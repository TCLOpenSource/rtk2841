/*****************************************************************************
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
#include "rtkdemux_ioctl_ex.h"
#include "rtkdemux_buf.h"
#include "rtkdemux_MW.h"
#include "rtkdemux_specialhandling.h"
#include <rtk_kdriver/RPCDriver.h>   /* register_kernel_rpc, send_rpc_command */
#include <rtk_kdriver/scalercommon/scalerCommon.h>
#include <rtk_kdriver/rpc/VideoRPC_System.h>
#include <rtk_kdriver/rpc/VideoRPC_System_data.h>

#include <tp/tp_drv_global.h>


#define DEMUX_CHECK_PID(x)  \
{\
	if (x > 0x1fff) { \
		dmx_warn("func %s, line %d, Error(pid : 0x%x)!!\n", __func__, __LINE__, x); \
		return -ENOTTY; \
	} \
}

static bool _bcase_print_key_info = false;



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
	int i;

	if (demux_device->pChArray) {
		for (i = 0; i < demux_device->chNum; i++) {
			IOCTLEX_UninitChannelImpl(&demux_device->pChArray[i]);
		}

		DEMUX_BUF_FreeBuffer(&demux_device->APvrTsBuf);
		DEMUX_BUF_FreeBuffer(&demux_device->secFilterBuffer);
		DEMUX_BUF_FreeBuffer(&demux_device->bufPoll);
		mutex_destroy(&demux_device->mutex);
		kfree(demux_device->pChArray);
		demux_device->pChArray = NULL;
	}
	if (demux_device->pChUsage) {
		for (i = 0; i < demux_device->chNum; i++) {
			if (demux_device->pChUsage[i].pOwner)
				kfree(demux_device->pChUsage[i].pOwner);
		}
		kfree(demux_device->pChUsage);
		demux_device->pChUsage = 0;
	}
}


void IOCTL_SetPinInfo(DEMUX_BUF_PIN_T *pPinInfo, RINGBUFFER_HEADER *pRBH, DEMUX_BUF_T *pBuf)
{
	if (pRBH == 0 || pBuf == 0)
		return;

	pPinInfo->pWrPtr		= (u32 *)&pRBH->writePtr;
	pPinInfo->pRdPtr		= (u32 *)&pRBH->readPtr[0];
	pPinInfo->pBufferLower  = (unsigned char *)DEMUX_reverseInteger(pRBH->beginAddr);
	pPinInfo->pBufferUpper  = pPinInfo->pBufferLower + DEMUX_reverseInteger(pRBH->size);
	pPinInfo->phyAddrOffset = (long) pBuf->phyAddr - (long) pBuf->virAddr;
	pPinInfo->pRBH		  =  pRBH;
}


static void IOCTL_CheckAvSync(demux_channel *pCh)
{
	mutex_lock(&pCh->mutex);
	if (pCh->tp_src == MTP) {
		DEMUX_ResetAVSync(pCh, pCh->pbAvsyncMode);
	} else if (pCh->avSyncMode != NAV_AVSYNC_PCR_MASTER && pCh->tp_src != MTP) {
		pCh->avSyncMode = NAV_AVSYNC_PCR_MASTER;
		REFCLK_SetMasterShip(DEMUX_GetReferenceClock(pCh), pCh->avSyncMode);
		REFCLK_SetTimeout(DEMUX_GetReferenceClock(pCh), 3*DEMUX_CLOCKS_PER_SEC);
	}

	mutex_unlock(&pCh->mutex);
}

int IOCTL_InitModule ()
{
	int i, j, size;
	int ret = 0;

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

	demux_device->pChUsage = kmalloc(sizeof(DEMUX_CH_USAGE_T)*demux_device->chNum, GFP_KERNEL);
	if (demux_device->pChUsage)
		memset(demux_device->pChUsage, 0, sizeof(DEMUX_CH_USAGE_T)*demux_device->chNum);

	mutex_init(&demux_device->mutex);

	/* allocate buffer pool for ringbuffer header and refclock */
	i = (sizeof(RINGBUFFER_HEADER) + 0xf) & ~0xf;
	j = (pInfo->sizeOfRefClock     + 0xf) & ~0xf;

	size = i *  demux_device->chNum*(1 /*tp*/+ 1 /*rec*/ + ((demux_device->numberOfVD + demux_device->numberOfAD) << 1)/*bs+ib*/)
		+ i * 2 /*tp(0 and 1) info */
		+ i * 2 /*tp(0 and 1) */ * 5 /* SUBTITLE, TELTEXT, ISDB_CC, ISDB_CC_SUPERIMPOSE, PSI*/
		+ j * demux_device->chNum /* reference clock */
		+ i*(MAX_SECTION_FILTER_NUM+MAX_PID_FILTER_CB_NUM)*demux_device->chNum/*section and PES ringbuffer header*/;

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

/*
	for (i = 0; i < demux_device->chNum; i++) {
		IOCTLEX_InitChannelImpl(i);
	}
*/
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
		if (!pCh->isInit)
			continue;

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
					pRBH->size         = pPes->pBufferUpper - pPes->pBufferLower;
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
#if defined(DEMUX_AUDIO_USE_PINGPONG_BUFFERS)
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
	pCh->tmpPinInfo[pin].pinInfoStatus = PININFO_FREE;
	SET_FLAG(pCh->events, EVENT_SET_AUDIO_PIN_INFO);
	dmx_crit("[%s %d]CH%d pin = %d\n", __func__, __LINE__, pInfo->ch, pin);
	mutex_unlock(&pCh->mutex);

	return 0;
}
#endif
int IOCTL_GetBufferInfo(DEMUX_BUF_INFO_T *pInfo)
{
	demux_channel *pCh;
	DEMUX_BUF_T   *pIBH, *pBSH = NULL;
	int pin;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d]\n", __func__, __LINE__);
	pCh = &demux_device->pChArray[pInfo->ch];

	switch (pInfo->dest) {
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
	case DEMUX_DEST_STC0:
	case DEMUX_DEST_STC1:
		if (pCh->bUseSelfBuf && pCh->refClockBuffer.phyAddr == 0)
			DEMUX_BUF_PrepareSelfRefClockBuf(pCh);

		pInfo->refClockPhyAddr    = pCh->refClockBuffer.phyAddr;
		pInfo->refClockHeaderSize = pCh->refClockBuffer.allocSize;
		return 0;
	default:
		break;
	}

	pin = IOCTLEX_PESDestToPin(pInfo->dest);
	switch (pin) {
	case AUDIO_PIN:
	case AUDIO2_PIN:
	{
		if (pCh->bUseSelfBuf)
			DEMUX_BUF_PrepareSelfDecBuf(pCh, pin, demux_device->sizeOfAudioBS, demux_device->sizeOfAudioIB);

		if (pCh->bsDecBuf[pin].phyAddr)
			pBSH = &pCh->bsDecBufH[pin], pIBH = &pCh->ibDecBufH[pin];

		break;
	}
	case VIDEO_PIN:
	case VIDEO2_PIN:
	{
		if (pCh->bUseSelfBuf)
			DEMUX_BUF_PrepareSelfDecBuf(pCh, pin, demux_device->sizeOfVideoBS, demux_device->sizeOfVideoIB);

		if (pCh->bsDecBuf[pin].phyAddr)
			pBSH = &pCh->bsDecBufH[pin], pIBH = &pCh->ibDecBufH[pin];

		break;
	}
	case SUBTITLE_PIN:
	case TELETEXT_PIN:
	case ISDB_CC_PIN:
	case ISDB_CC_SUPERIMPOSE_PIN:
	{
		if (pCh->bUseSelfBuf)
			DEMUX_BUF_PrepareSelfDecBuf(pCh, pin, (pin == SUBTITLE_PIN) ? 128*1024 : 256*1024, (pin == SUBTITLE_PIN) ? 64*1024 : 0);

		if (pCh->bsDecBuf[pin].phyAddr)
			pBSH = &pCh->bsDecBufH[pin], pIBH = &pCh->ibDecBufH[pin];

		break;
	}
	default:
		break;
	}


	if (pBSH) {
		if (pCh->bUseSelfBuf && pCh->refClockBuffer.phyAddr == 0)
			DEMUX_BUF_PrepareSelfRefClockBuf(pCh);

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
	case DEMUX_DEST_SUBTITLE: pin = SUBTITLE_PIN; break;
	case DEMUX_DEST_TELETEXT: pin = TELETEXT_PIN; break;
	case DEMUX_DEST_ISDB_CC: pin = ISDB_CC_PIN; break;
	case DEMUX_DEST_ISDB_CC_SUPERIMPOSE: pin = ISDB_CC_SUPERIMPOSE_PIN; break;
	default : return;
	}
	if (bRemoved) {
		demux_device->pinMap[pin].chIndex = demux_device->chNum ;
			if (pin == AUDIO_PIN)
				RESET_FLAG(pCh->events, EVENT_SET_AUDIO_FORMAT);
			if (pin == AUDIO2_PIN)
				RESET_FLAG(pCh->events, EVENT_SET_AUDIO2_FORMAT);
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
	DEMUX_PCRSYNC_T *pPcrProcesser;
	pCh = &demux_device->pChArray[pInfo->ch];
	pPcrProcesser = &pCh->pcrProcesser;

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
				dmx_notice("[dtv] (CH%d)RemovePID: pid=%d(0x%x),type=%d,dest=%d\n", pCh->tunerHandle, currentFilter->pid, currentFilter->pid, pInfo->pidType, pInfo->dest);


				IOCTL_UpdatePinMap(pCh, currentFilter->pesDest, true);

				currentFilter->refCnt--;
				if( 0 == currentFilter->refCnt ) {
					currentFilter->pid = -1;
				} else {
					currentFilter->pesDest = DEMUX_DEST_TSO;
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

	if (pInfo->pid == filterRemoveIndicator) { /* only clear PID by setting pInfo->pid to 0x1fff */
		const int target = GetTargetIdxFromType(pInfo->pidType, pInfo->dest);
		pCh->pidFilterCount = IOCTL_RemoveInvalidPIDFilters(pCh->pidFilterList, pCh->pidFilterCount);

		if (0 <= target) {
			pCh->activeTarget[target].bNewTarget = false;
			pCh->activeTarget[target].pid        = -1;

			if (target == DEMUX_TARGET_AUDIO) {
				pCh->audio_newformat_info.Audio.audioPid = -1;
				pCh->audio_newformat_info.Audio.IsSendNewFormat = false;
				PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, false);
			} else if (target == DEMUX_TARGET_AUDIO_2ND) {
				pCh->audio_newformat_info.Audio_2ND.audioPid = -1;
				pCh->audio_newformat_info.Audio_2ND.IsSendNewFormat = false;
			} else if (target == DEMUX_TARGET_VIDEO){
				PCRSYNC_FlushVideoPidOrDest(pPcrProcesser, false);
			}
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

			/*Multiple audio track case*/
			if (target == DEMUX_TARGET_AUDIO)
				PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, true);
			else if (target == DEMUX_TARGET_VIDEO)
				PCRSYNC_FlushVideoPidOrDest(pPcrProcesser, true);
		}

		if (target == DEMUX_TARGET_AUDIO_2ND)
			memset(&pCh->adInfo, 0, sizeof(pCh->adInfo));

		if (target == DEMUX_TARGET_AUDIO)
			pCh->audio_newformat_info.Audio.audioPid = newFilter->pid;
		else if (target == DEMUX_TARGET_AUDIO_2ND)
			pCh->audio_newformat_info.Audio_2ND.audioPid = newFilter->pid;

		// We need to reset 1. RCD in REFCLK 2. RCD in PCRSYNC variable 3. GPTSTimeout = 3s in ResetAVSync
		// Otherwise, we might get previous rcd when we change to Radio channel and audio fw uses wrong rcd to update their MPTS
		/*if (pCh->tp_src != MTP && (target == DEMUX_TARGET_AUDIO || target == DEMUX_TARGET_AUDIO_2ND)) {
			// check acivative video pid exist or not
                        if (pCh->activeTarget[DEMUX_TARGET_VIDEO].pid == -1 && pCh->activeTarget[DEMUX_TARGET_VIDEO_2ND].pid == -1) {
                                REFCLK_Reset(DEMUX_GetReferenceClock(pCh), pCh->avSyncMode, pCh->videoFreeRunThreshold);
                                PCRSYNC_Reset(&pCh->pcrProcesser, DEMUX_GetReferenceClock(pCh), pCh->tunerHandle, pCh->pPcrRecoveryManager);
                                DEMUX_ResetAVSync(pCh, pCh->avSyncMode);
                        }
                }
		*/


		// We need to reset 1. RCD in REFCLK 2. RCD in PCRSYNC variable
		// Otherwise, we might get previous rcd when we change to Radio channel and audio fw uses wrong rcd to update their MPTS
		if (pCh->tp_src != MTP && (target == DEMUX_TARGET_AUDIO || target == DEMUX_TARGET_AUDIO_2ND)) {
			// check acivative video pid exist or not
                        if (pCh->activeTarget[DEMUX_TARGET_VIDEO].pid == -1 && pCh->activeTarget[DEMUX_TARGET_VIDEO_2ND].pid == -1) {
                                REFCLK_Reset(DEMUX_GetReferenceClock(pCh), pCh->avSyncMode, pCh->videoFreeRunThreshold);
                                PCRSYNC_Reset(&pCh->pcrProcesser, DEMUX_GetReferenceClock(pCh), pCh->tunerHandle, pCh->pPcrRecoveryManager);
                        }
                }


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
		pCh->pidFilterCount++;
	} else {
		//update dest
		dmx_notice("[dtv] (CH%d)AddPID update_dest: pid=%d(0x%x),type=%d,dest=%d->%d\n", pCh->tunerHandle, pInfo->pid, pInfo->pid, pInfo->pidType, pCh->pidFilterList[i].pesDest, pInfo->dest);

		pCh->pidFilterList[i].pesDest = pInfo->dest;
		pCh->pidFilterList[i].refCnt  += 1;
		IOCTL_UpdatePinMap(pCh, pInfo->dest, false);

		if (pInfo->pidType == DEMUX_PID_AUDIO) {
			if (pInfo->dest == DEMUX_DEST_ADEC0) {
				pCh->audio_newformat_info.Audio.audioPid = pInfo->pid;
				PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, true);
			} else if (pInfo->dest == DEMUX_DEST_ADEC1) {
				pCh->audio_newformat_info.Audio_2ND.audioPid = pInfo->pid;
				PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, true);
			} else if (pInfo->dest == DEMUX_DEST_TSO) {
				if (pInfo->pid == pCh->audio_newformat_info.Audio.audioPid) {
					pCh->audio_newformat_info.Audio.audioPid = -1;
					pCh->audio_newformat_info.Audio.IsSendNewFormat = false;
				} else if (pInfo->pid == pCh->audio_newformat_info.Audio_2ND.audioPid) {
					pCh->audio_newformat_info.Audio_2ND.audioPid = -1;
					pCh->audio_newformat_info.Audio_2ND.IsSendNewFormat = false;
				}
			}
		}
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
	pCh->bUpdateDemuxTarget = true;

	return 0;
}
int IOCTL_SetPID(DEMUX_SET_PID_T *pInfo)
{
	demux_channel *pCh;
	int i;
	dmx_notice("func %s, line %d, ch %d, pid 0x%x, pidType %d, dest %d\n", __func__, __LINE__, pInfo->ch, pInfo->pid, pInfo->pidType, pInfo->dest);
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	mutex_lock(&pCh->mutex);
	IOCTL_SetPIDImpl(pInfo);
	/* debug print */
	for (i = 0 ; i < pCh->pidFilterCount ; i++) {
		dmx_mask_print(DEMUX_NOMAL_DEBUG,"[dtv] (CH%d)pidFilterList[%d]:pid=%d,type=%d,dest=%d\n",
			pCh->tunerHandle, i, pCh->pidFilterList[i].pid, pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest);
	}
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
			pSec->pWrPtr        = (u32 *)&pRBH->writePtr;
			pSec->pRdPtr        = (u32 *)&pRBH->readPtr[0];
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
	int i, ret = -1, newSize;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	DEMUX_CHECK_PID(pInfo->pid);
	pCh = &demux_device->pChArray[pInfo->ch];
	newSize = pInfo->size;
	if (pInfo->pidType == DEMUX_PID_VIDEO) {
		if (pInfo->size > DEMUX_VD_BS_SIZE)
			newSize = DEMUX_VD_BS_SIZE;
	} else if (pInfo->pidType == DEMUX_PID_AUDIO) {
		if (pInfo->size > DEMUX_AD_BS_SIZE)
			newSize = DEMUX_AD_BS_SIZE;
	} else if (pInfo->size > PES_FILTER_RING_BUFFER_SIZE)
		newSize = PES_FILTER_RING_BUFFER_SIZE;

	if (newSize != pInfo->size) {
		dmx_warn("[IOCTL_AddPESFilter %d] buffer size (%d) is larger than allowed (%d). resize it\n", __LINE__, pInfo->size, newSize);
		pInfo->size = newSize;
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


	if (ret >= 0){
		pPes = &pCh->pesMap[ret];
		if (pPes->bufferStatus == BUFFER_OFFLINE){
			if (DEMUX_PESBuffer_Alloc(pPes, pInfo->size) < 0){
				dmx_err("%s-%d : alloc pes buffer for pid:%x, fail\n", __func__, __LINE__, pInfo->pid);
				pCh->pesMap[ret].occupied = 0;
				pCh->pidFilterListCB[ret].used       = 0;
				pCh->activePESTarget[ret].bNewTarget = true;
				pCh->activePESTarget[ret].pid        = -1;
				pCh->activePESTarget[ret].isTemi     = false;
				ret = -1;
			}
   			dmx_mask_print(DEMUX_PES_DEBUG,"Allocate pesBuffer: ch:%d, pesId:%d, virAddr:%p, phyAddr:%x, limit:%p\n", pInfo->ch, ret, pPes->virAddr, pPes->phyAddr, pPes->pBufferUpper);
		}
		else if (pPes->bufferStatus == BUFFER_FREE){
			pPes->bufferStatus = BUFFER_NEW;
			dmx_mask_print(DEMUX_PES_DEBUG,"reuse unfree buffer : ch:%d, pesId:%d, virAddr:%p, phyAddr:%x, limit:%p\n", pInfo->ch, ret, pPes->virAddr, pPes->phyAddr, pPes->pBufferUpper);
		}
		else
		{
			dmx_err(" %s-%d : PES Filter status not sync !\n", __func__, __LINE__);
			ret = -1;
		}
	}

	if (ret >= 0) {
		RINGBUFFER_HEADER *pRBH = NULL;
		//alloc memory
		pPes = &pCh->pesMap[ret];
		pRBH = (RINGBUFFER_HEADER *)pPes->rbHeader.virAddr;


		pRBH->reserve2 = DEMUX_PESBUFFER_OP_PENDING_FOR_INIT;
		pInfo->baseAddr      = pRBH->beginAddr;
		pInfo->baseAllocSize = pRBH->size ;

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
	pCh->activePESTarget[pInfo->pesfIndex].isTemi     = false;
	pCh->pesMap[pInfo->pesfIndex].bufferStatus = BUFFER_FREE;

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
	DEMUX_PCRSYNC_T *pPcrProcesser;
	bool bVideo = false, bAudio = false, bPCR = false, bPES = false, bSec = false, bRecordA = false, bRecordB = false, bPVR = false, bTSO = false, bSubtitle =false, bTT = false;
	int i;

	dmx_function_call();
	dmx_notice("%s_%d,ch:%d, scope:%d\n", __func__, __LINE__, pInfo->ch, pInfo->scope);
	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	pPcrProcesser = &pCh->pcrProcesser;
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
		bSubtitle = true;
		bTT		  = true;
	default:
		break;
	}

	if(bVideo == true ) {
		PCRSYNC_FlushVideoPidOrDest(pPcrProcesser, false);
	}

	if(  bVideo || bAudio || bPCR || bRecordA || bRecordB || bTSO ) {
		for (i = 0; i < pCh->pidFilterCount; i++) {
			if( ( bVideo   && (DEMUX_PID_VIDEO	   == pCh->pidFilterList[i].pidType) ) ||
				( bAudio   && (DEMUX_PID_AUDIO	   == pCh->pidFilterList[i].pidType) ) ||
				( bPCR	   && (DEMUX_PID_PCR	   == pCh->pidFilterList[i].pidType) ) ||
				( bSubtitle&& (DEMUX_PID_SUBTITLE  == pCh->pidFilterList[i].pidType) ) ||
				( bTT	   && (DEMUX_PID_TELETEXT  == pCh->pidFilterList[i].pidType) ) ||
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
		if (bAudio) {
			pCh->audio_newformat_info.Audio.audioPid = -1;
			pCh->audio_newformat_info.Audio.IsSendNewFormat = false;
			pCh->audio_newformat_info.Audio_2ND.audioPid = -1;
			pCh->audio_newformat_info.Audio_2ND.IsSendNewFormat = false;
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
				pCh->pesMap[i].bufferStatus = BUFFER_FREE;

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
	//if (pInfo->scope == DEMUX_CLEAN_ALL)
	//		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
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
int IOCTL_GetPIDFilterIndex(DEMUX_SET_PID_T *pInfo)
{
	demux_channel *pCh;
	int i, ret = -1;
	dmx_function_call();
	mutex_lock(&demux_device->mutex);
	for (i = 0; i < demux_device->tpInfo.descrambler_num; i++) {
		if (!demux_device->cwInfo[i].used) {
			demux_device->cwInfo[i].used   = 1;
			demux_device->cwInfo[i].pid    = pInfo->pid;
			demux_device->cwInfo[i].ch     = pInfo->ch;
			ret = i;
			break;
		}
	}
	mutex_unlock(&demux_device->mutex);

	if (pInfo->pid != 0xffff && ret >= 0) {
		DEMUX_CHECK_CH(pInfo->ch);
		pCh = &demux_device->pChArray[pInfo->ch];

		mutex_lock(&pCh->mutex);
		for (i = 0; i < pCh->pidFilterCount; i++) {
			if (pCh->pidFilterList[i].pid == pInfo->pid /*&& pCh->pidFilterList[i].pidType == pInfo->pidType && pCh->pidFilterList[i].pesDest == pInfo->dest*/) {
				pCh->pidFilterList[i].cwIndex = ret;
				pCh->pidFilterList[i].enDescramble = 1;
				SET_FLAG(pCh->events, EVENT_UPDATE_TS_LIST);
				pCh->bUpdateDemuxTarget = true;
			}
		}
		mutex_unlock(&pCh->mutex);
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
	SET_FLAG(pCh->status, STATUS_FLUSH_MTP);

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
		if (DEMUX_BUF_MTPBuffer_Create(pCh) < 0) {
			dmx_crit("[%s %d] fail to allocate MTP buffer\n", __func__, __LINE__);
			return -1;
		}
		DEMUX_BUF_ConfigTPBuffer(pCh);
	}
	pInfo->bufPhyAddr = pCh->mtpBuffer.phyAddr;
	pInfo->bufSize = pCh->mtpBuffer.allocSize;
	pInfo->size = pCh->mtpBuffer.size;
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
	DEMUX_BUF_MTPBuffer_Destroy(pCh);
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
	//Using MTP buffer need to wait until PID filter was set and TP start streaming
	if (pCh->startStreaming == 0) {
		pInfo->contiguousWritableSize = 0;
		pInfo->writableSize = 0;
		return 0;
	}

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
	if (tpStatus.tp_param.prefix_en == false)
		return 0;
	else
		tpStatus.tp_param.prefix_en = false;
#else
	if (tpStatus.tp_param.prefix_en == pInfo->bEnable)
		return 0;
	else
		tpStatus.tp_param.prefix_en = pInfo->bEnable;
#endif
	if (DEMUX_checkFilterCount(pCh) > 0) {
		dmx_err("Set TimeStamp Fail. Dtv is running now\n");
		return -1;
	}

	if (pCh->tp_src == MTP) {
	#ifdef DEMUX_REC_HACK_TIMESTAMP
		tpStatus.tp_param.prefix_en = false; /* timestamp is useless during PVR playback ?! */
		tpStatus.tp_param.frc_en = false;
		tpStatus.tp_param.ts_in_tsp_len = byte_192;
	#else
		/* tpStatus.tp_param.prefix_en = false; */ /* timestamp is useless during PVR playback ?! */
		tpStatus.tp_param.frc_en = pInfo->bEnable;
		tpStatus.tp_param.ts_in_tsp_len = (pInfo->bEnable) ? byte_192 : byte_188;
		tpStatus.tp_param.keep = (pInfo->bEnable)? 1:0;
	#endif
		if (pCh->mtpUploadUnitSize){
			if ((pCh->mtpUploadUnitSize) %((pInfo->bEnable == byte_192) ? 192 : 188) != 0 ){
				dmx_mask_print(DEMUX_NOMAL_DEBUG|DEMUX_NOTICE_PRINT,"%s_%d: ch:%d, uploadUnitSize(%d) is not sync with timeStamp(%d) use Default uploadUnitSize\n",
					__func__, __LINE__, pCh->tunerHandle, pCh->mtpUploadUnitSize,((pInfo->bEnable == byte_192) ? 192 : 188));
				pCh->mtpUploadUnitSize = 1024*((pInfo->bEnable == byte_192) ? 192 : 188);
			}
		}
		else{
			pCh->mtpUploadUnitSize = 1024*((pInfo->bEnable == byte_192) ? 192 : 188);
		}
	}

	if (tpStatus.tp_stream_status == TP_STREAM_START)
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);

	if (RHAL_SetTPMode(pCh->tunerHandle, tpStatus.tp_param) != TPK_SUCCESS) {
		if (tpStatus.tp_stream_status == TP_STREAM_START) {
			RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
		}
		return -1;
	}
	DEMUX_BUF_ConfigTPBuffer(pCh);

	if (tpStatus.tp_stream_status == TP_STREAM_START)
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);
	return 0;
}


int IOCTL_SetUploadUnitSize(DEMUX_UPLOADUNITSIZE_SETTING_T *pInfo)
{
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;
	//UINT32 unitsize_for_compatible = 0;

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];

	if (pCh->tp_src != MTP) {
		dmx_err("%s_%d: ch:%d, not MTP, FAIL to set unloadUnitSize \n",__func__, __LINE__, pCh->tunerHandle)
		return -1;
	}

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS){
		dmx_err("%s_%d: fail to get tp(%d) status \n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}

	// this is for backward compatiable, after ap code commit , this should removed, and replace unitsize_for_compatible with pInfo->uploadUnitSize
	//begin
	//unitsize_for_compatible = ((pInfo->uploadUnitSize >1024)?pInfo->uploadUnitSize: pInfo->uploadUnitSize*1024);
	//end

	if (pCh->mtpUploadUnitSize !=0 &&(pCh->mtpUploadUnitSize== pInfo->uploadUnitSize)){
		dmx_mask_print(DEMUX_NOMAL_DEBUG|DEMUX_NOTICE_PRINT,"%s_%d: ch:%d, setUploadunitsize: %d \n",
			__func__, __LINE__, pCh->tunerHandle, pInfo->uploadUnitSize);
		return 0;
	}

	if (DEMUX_checkFilterCount(pCh) > 0) {
		dmx_err("Set UploadUnitSize Fail. Dtv is running now\n");
		return -1;
	}

	if ((pInfo->uploadUnitSize) % ((tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192: 188) != 0){
		dmx_err("%s_%d: ch:%d, uploadUnitSize(%d) is not sync with timeStamp(%d)\n",
			__func__, __LINE__, pCh->tunerHandle,  pInfo->uploadUnitSize,((tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192 : 188));
		return -1;
	}

	if ((pInfo->uploadUnitSize) % (1024) != 0){
		dmx_err("%s_%d: ch:%d, uploadUnitSize(%d)  NOT_SYNC to 1024\n",
			__func__, __LINE__, pCh->tunerHandle,  pInfo->uploadUnitSize);
		return -1;
	}

	pCh->mtpUploadUnitSize = pInfo->uploadUnitSize;

	dmx_mask_print(DEMUX_NOMAL_DEBUG|DEMUX_NOTICE_PRINT,"%s_%d: ch:%d, setUploadunitsize: %d \n",
		__func__, __LINE__, pCh->tunerHandle, pInfo->uploadUnitSize);


	if (tpStatus.tp_stream_status == TP_STREAM_START){
		if (RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP) != TPK_SUCCESS){
			dmx_err("%s_%d: fail to stop TP(%d) \n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
	}

	if (DEMUX_BUF_ConfigTPBuffer(pCh) <0){
		dmx_err("%s_%d: ch:(%d) fail to DEMUX_BUF_ConfigTPBuffer\n", __func__, __LINE__, pCh->tunerHandle);
		return -1;
	}

	if (tpStatus.tp_stream_status == TP_STREAM_START){
		if (RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START)!= TPK_SUCCESS){
			dmx_err("%s_%d: fail to start TP(%d) \n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
	}
	return  0;
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
		if (DEMUX_BUF_MTPBuffer_Create(pCh) < 0)
			return -1;

	}
	DEMUX_BUF_ConfigTPBuffer(pCh);
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
			status = pInfo->dest == DEMUX_DEST_ADEC0 ? STATUS_FLUSH_AUDIO  :
				pInfo->dest == DEMUX_DEST_ADEC1 ? STATUS_FLUSH_AUDIO2 :
				pInfo->dest == DEMUX_DEST_VDEC0 ? STATUS_FLUSH_VIDEO  :
				pInfo->dest == DEMUX_DEST_VDEC1 ? STATUS_FLUSH_VIDEO2 : STATUS_FLUSH_SUBTITLE;
			if (status == STATUS_FLUSH_VIDEO || status == STATUS_FLUSH_VIDEO2) {
				pCh->videoDecodeMode[status == STATUS_FLUSH_VIDEO ? 0 : 1] = pInfo->data[1];
				rtkdemux_dbg_dump_ts_flush_enable(pInfo->ch);
			}
			SET_FLAG(pCh->status, status);
			break;
		}
	case DEMUX_PRIVATEINFO_AUDIO_FORMAT:
		{
			dmx_notice("(%s-%d): DEMUX_PRIVATEINFO_AUDIO_FORMAT: dest:%d \n", __FILE__, __LINE__, pInfo->dest);
			if (pInfo->dest == DEMUX_DEST_ADEC0) {
				SET_FLAG(pCh->events, EVENT_SET_AUDIO_FORMAT);
				pCh->audioFormat = pInfo->data[1];
				memset(pCh->audioPrivateInfo, 0, sizeof(pCh->audioPrivateInfo));
				memcpy(pCh->audioPrivateInfo, &pInfo->data[2], sizeof(ULONG)*8);
			} else {
				SET_FLAG(pCh->events, EVENT_SET_AUDIO2_FORMAT);
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
	if (HAS_FLAG(pCh->status, STATUS_FLUSH_MTP)) {
		RESET_FLAG(pCh->status, STATUS_FLUSH_MTP);
	}
	RESET_FLAG(pCh->status, STATUS_APVR_PLAYBACK_START);
	mutex_unlock(&pCh->mutex);

	/*Allocate mtp buffer first, before start MTP streaming*/
	if (pInfo->bStartStreaming) {
		if (pCh->mtpBuffer.allocSize == 0) {
			if (DEMUX_BUF_MTPBuffer_Create(pCh) < 0) {
				dmx_crit("[%s %d] fail to allocate MTP buffer\n", __func__, __LINE__);
				return -1;
			}
			DEMUX_BUF_ConfigTPBuffer(pCh);
		}
	} else if (pCh->startStreaming) {
		//Stop TP streaming when MTP bStartStreaming=false
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
		pCh->startStreaming = 0;
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
	DEMUX_BUF_T   *pBS = NULL;

	dmx_function_call();
	if(pInfo->ch >= demux_device->chNum)
		return -1;

	pCh = &demux_device->pChArray[pInfo->ch];


	switch (pInfo->bufferType) {
		case DEMUX_BUFFER_TYPE_SECTION:             pBS = &demux_device->secFilterBuffer; break;
		case DEMUX_BUFFER_TYPE_REFCLOCK:
			if(pCh->isInit == 0)
				break;
			pBS = &pCh->refClockBuffer; break;
		case DEMUX_BUFFER_TYPE_BUFFERHEADERPOOL:    pBS = &demux_device->bufPoll; break;
		case DEMUX_BUFFER_TYPE_APVR:
		{
			if (DEMUX_BUF_APvrBuffer_Alloc(pInfo->size) == 0)
				pBS = &demux_device->APvrTsBuf;
			break;
		}
		case DEMUX_BUFFER_TYPE_GIFO:
		{
			if(pCh->isInit == 0)
				break;
			if (DEMUX_BUF_GIFOBuffer_Alloc(pInfo->ch, pInfo->size) == 0)
				pBS = &pCh->GIFOBuf;
			break;
		}
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
int IOCTL_EnableDescrambler(DEMUX_ENABLE_DESCRAMBLER_T *pInfo)
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
	if (pCh->pidFilterCount == 0) {
		dmx_notice("BCAS_ClearPid : ch:%d,  DEMUX_PRIVATEINFO_FLUSHTP \n", pInfo->ch);
		dmx_notice("(%s-%d): DEMUX_PRIVATEINFO_FLUSHTP -ch:%d filteramask: %x \n", __FILE__, __LINE__,pInfo->ch,DEMUX_checkFilterCount(pCh));
		SET_FLAG(pCh->status, STATUS_FLUSH_TP);
	}
	mutex_unlock(&pCh->mutex);
	return 0;
}
int IOCTL_SwitchDescrambler(DEMUX_SWITCH_DESCRAMBLER_T *pInfo)
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
		DEMUX_SET_PID_T pidFilter;
		pidFilter.ch  = pInfo->ch;
		pidFilter.pid = 0xffff;
		pCh->CIKeySel = IOCTL_GetPIDFilterIndex(&pidFilter);
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
	DEMUX_PCRSYNC_T *pPcrProcesser;
	int i, j, activeTarget;
	DEMUX_PES_DEST_T orgDest = DEMUX_DEST_NONE;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	if (pInfo->count > DEMUX_MAX_NUM_TO_SET)
		return -1;

	pCh = &demux_device->pChArray[pInfo->ch];
	pPcrProcesser = &pCh->pcrProcesser;
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
				IOCTL_UpdatePinMap(pCh, target->dest, false);

				if (target->pidType == DEMUX_PID_AUDIO) {
					if (target->dest == DEMUX_DEST_ADEC0) {
						PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, true);
						pCh->audio_newformat_info.Audio.audioPid = pInfo->pidlist[j].pid;
					} else if (target->dest == DEMUX_DEST_ADEC1) {
						pCh->audio_newformat_info.Audio_2ND.audioPid = pInfo->pidlist[j].pid;
					} else if (target->dest == DEMUX_DEST_TSO) {
						if (target->pid == pCh->audio_newformat_info.Audio.audioPid) {
							PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, false);
							pCh->audio_newformat_info.Audio.audioPid = -1;
							pCh->audio_newformat_info.Audio.IsSendNewFormat = false;
						} else if (target->pid == pCh->audio_newformat_info.Audio_2ND.audioPid) {
							pCh->audio_newformat_info.Audio_2ND.audioPid = -1;
							pCh->audio_newformat_info.Audio_2ND.IsSendNewFormat = false;
						}
					}
				}

				if (target->pidType == DEMUX_PID_VIDEO) {
					if (target->dest == DEMUX_DEST_VDEC0) {
						PCRSYNC_FlushVideoPidOrDest(pPcrProcesser, true);
					} else {
						PCRSYNC_FlushVideoPidOrDest(pPcrProcesser, false);
					}
				}

				activeTarget = GetTargetIdxFromType(entry->pidType, entry->pesDest);
				if (activeTarget >= 0 && pCh->activeTarget[activeTarget].pid != entry->pid) {
					pCh->activeTarget[activeTarget].bNewTarget = true;
					pCh->activeTarget[activeTarget].pid        = entry->pid;

					if (activeTarget == DEMUX_TARGET_AUDIO)
						PCRSYNC_FlushAudioPidOrDest(pPcrProcesser, true);
					else if (activeTarget == DEMUX_TARGET_VIDEO)
						PCRSYNC_FlushVideoPidOrDest(pPcrProcesser, true);
				}

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
	int i;
	dmx_function_call();
	DEMUX_CHECK_CH(pInfo->ch);
	if (pInfo->count > DEMUX_MAX_NUM_TO_SET)
		return -1;
	pCh = &demux_device->pChArray[pInfo->ch];

	mutex_lock(&pCh->mutex);
	for(i = 0; i < pInfo->count; i++) {
		IOCTL_SetPIDImpl(&(pInfo->pidlist[i]));
	}
	/* debug print */
	for (i = 0 ; i < pCh->pidFilterCount ; i++) {
		dmx_crit("[IOCTL_SetPIDs][dtv] (CH%d)pidFilterList[%d]:pid=%d,type=%d,dest=%d\n",
			pCh->tunerHandle, i, pCh->pidFilterList[i].pid, pCh->pidFilterList[i].pidType, pCh->pidFilterList[i].pesDest);
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

	pCh->pvrSpeed = pInfo->speed;
	if (pInfo->speed == 0) {
		mutex_unlock(&pCh->mutex);
		return 0;
	}

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

	if (pInfo->speed != 256) {
		if (pCh->avSyncMode != NAV_AVSYNC_VIDEO_ONLY)
		{
			/* According to KTASKWBS-275, only normal speed have audio */
			DEMUX_ResetAVSync(pCh, NAV_AVSYNC_VIDEO_ONLY);
		}
		/*cannot enable frame rate control for trick play because video should decode frame ASAP*/
		mutex_unlock(&pCh->mutex);
		PVR_EnableTPRateControl(pCh, false);

		return 0;
	} else {
		if (pCh->avSyncMode == pCh->pbAvsyncMode) {
			mutex_unlock(&pCh->mutex);
			return 0;
		}
		DEMUX_ResetAVSync(pCh, pCh->pbAvsyncMode);
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
 	1.  stream control
 	2.  set tp param
 	3.  SetTPInputConfig
			1) set port
			2) set source
			3) set tpo
	4.	alloc buffer for mtp
	5.  free all filter
 */
int IOCTL_SetTPInputConfig(DEMUX_TP_SOURCE_CONFIG_T *pInfo)
{
	int tp_id = 0;
	demux_channel *pCh;
	TPK_TP_STATUS_T tpStatus;
	DEMUX_TP_STREAM_CONTROL_T streamCtrl;
	DEMUX_FREE_DESCRAMBLE_INDEX_T data;
	TPK_TP_SOURCE_T tp_src;
	static DEMUX_TP_SOURCE_CONFIG_T ori_info[MAX_TP_COUNT];

	DEMUX_CHECK_CH(pInfo->ch);
	pCh = &demux_device->pChArray[pInfo->ch];
	tp_id = pCh->tunerHandle;

	dmx_notice("0. ch:%d portType:%d inputType:%d casType:%d  %s, line %d\n", pInfo->ch, pInfo->portType, pInfo->inputType, pInfo->casType, __func__, __LINE__);

	if (pInfo->inputType == TPK_INPUT_ENABLE || pInfo->inputType == TPK_INPUT_DISABLE)
	{
		streamCtrl.ch	=	tp_id;
		if (pInfo->inputType == TPK_INPUT_ENABLE)
			streamCtrl.ctrl	= TP_STREAM_START;
		else
			streamCtrl.ctrl	= TP_STREAM_STOP;
		IOCTL_SetTPStreamControl(&streamCtrl);
		return 0;
	}

	if (RHAL_GetTpStatus(tp_id, &tpStatus) != TPK_SUCCESS)
		return TPK_FAIL;

#if 0
	if(tpStatus.tp_stream_status == TP_STREAM_START)
	{
		streamCtrl.ch = tp_id;
		streamCtrl.ctrl = TP_STREAM_STOP ;
		IOCTL_SetTPStreamControl(&streamCtrl);
	}
#endif

	tpStatus.tp_param.serial                	= 0 ;
	tpStatus.tp_param.sync_byte             	= 0x47 ;
	tpStatus.tp_param.ts_in_tsp_len         	= byte_188 ;
	tpStatus.tp_param.clr_tsp_scrmbl_bit    	= 0x1 ;
	tpStatus.tp_param.pid_filter_en         	= 0x1 ;

	if (pInfo->inputType == TPK_INPUT_SERIAL)
	{
		tpStatus.tp_param.serial            = 1 ;
		dmx_notice( "[%s %d] - Set TP%d to Serial mode!\n", __func__, __LINE__, tp_id);
	}
	else if (pInfo->inputType == TPK_INPUT_PARALLEL)
	{
		tpStatus.tp_param.serial            = 0 ;
		dmx_notice("[%s %d] - Set TP%d to Parallel mode!\n", __func__, __LINE__, tp_id) ;
	}
	// TODO: add two-bits mode

	if (pInfo->portType == TPK_PORT_FROM_MEM)
	{
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
		tpStatus.tp_param.keep = 0;
		tpStatus.tp_param.casType = (pInfo->casType == TPK_WITH_CAS) ? TPK_WITH_CAS : TPK_WITHOUT_CAS;
	}

	if (RHAL_SetTPMode(tp_id, tpStatus.tp_param) != TPK_SUCCESS)
	{
		dmx_crit("[%s %d] - RHAL_SetTPMode fail!\n",  __func__, __LINE__);
		return -1;
	}
	/*  3.  SetTPInputConfig
			3.1 set port - remove this part in merlin2
			3.2 set source
			3.3 set tpo
	*/

	/* dmx_mask_print(DEMUX_NOMAL_DEBUG," 3.  SetTPInputConfig  %s, line %d\n", __func__, __LINE__);*/
	tp_src = RHAL_GetTPSource(pInfo->portType);

	/* 3.2 set source */
	if (RHAL_SetTPSource(tp_id,tp_src,pInfo->casType) != TPK_SUCCESS)
	{
		dmx_crit("[%s %d] - RHAL_SetTPSource fail!\n",  __func__, __LINE__);
		return TPK_FAIL;
	}
	pCh->tp_src = tp_src;

	if(tp_src == MTP) {
		dmx_notice("\033[1;36m [%s %d] tp_id =%d\033[m\n", __func__ , __LINE__ , tp_id );
		pCh->mtpUploadUnitSize = 0;
		IOCTL_StopPCRRecovery((DEMUX_CHANNEL_T *)&tp_id);
	}

	/* 3) set tpo */
	if(pInfo->casType==TPK_WITH_CAS)
	{
		TPK_TPOUT_REMUX_PARAM_T remux_param ;
		TPK_TPOUT_SOURCE_T tpout_src;
 		tpout_src = TPK_IN_DEMOD_TO_TPOUT;
		remux_param.output_sync_byte = 0x47;
		remux_param.tpp_id = 0;/*default use tpp0 */

		if(tp_src == MTP)
			remux_param.tpp_src = MTP ;
		else if(tp_src != TS_UNMAPPING)
			remux_param.tpp_src = Internal_Demod ;

		if (RHAL_TPOUTSetDataSource(0, tpout_src,&remux_param) != TPK_SUCCESS)
		{
			dmx_crit("[%s %d] - RHAL_TPOUTSetDataSource fail!\n",  __func__, __LINE__);
			return TPK_FAIL;
		}
	}

	/*  4.  alloc buffer for mtp    */
	if (pInfo->portType == TPK_PORT_FROM_MEM && pCh->mtpBuffer.allocSize == 0) {
		dmx_notice(" alloc buffer for mtp  %s, line %d\n", __func__, __LINE__);
		if (DEMUX_BUF_MTPBuffer_Create(pCh) < 0)
			return -1;
	}
	DEMUX_BUF_ConfigTPBuffer(pCh);
	IOCTL_CheckAvSync(pCh);

	/*  5.  free all filter    */

	data.ch = pCh->tunerHandle;

	if (pInfo->casType == TPK_WITH_CAS &&
		ori_info[pInfo->ch].inputType == pInfo->inputType &&
		ori_info[pInfo->ch].portType  == pInfo->portType  &&
		ori_info[pInfo->ch].casType   != pInfo->casType) {
		; // do not free filter
	}
	else {
		IOCTL_FreeAllPIDFilterIndex(&data);
	}

	/* feed back  tp status*/
#if 0
	if(tpStatus.tp_stream_status == TP_STREAM_START)
	{
		streamCtrl.ch = tp_id;
		streamCtrl.ctrl = TP_STREAM_START ;
		IOCTL_SetTPStreamControl(&streamCtrl);
	}
#endif

	/* record info */
	ori_info[pInfo->ch].ch        = pInfo->ch;
	ori_info[pInfo->ch].inputType = pInfo->inputType;
	ori_info[pInfo->ch].portType  = pInfo->portType;
	ori_info[pInfo->ch].casType   = pInfo->casType;

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
			pFilterList ->filterList[pFilterList ->size].gpb_size 		= ((RINGBUFFER_HEADER *)pCh->pesMap[j].rbHeader.virAddr)->size;
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
bool IOCTL_CheckRingBufferData(struct file * filp)
{
#define BS_DISTANCE_TO_READ(start, end, base, limit) \
((end) + ((end) >= (start) ? 0 : limit - base) - (start))
	int iChannel, iItem;
	for (iChannel =0; iChannel < demux_device->chNum; iChannel++)
	{
		if (!((int)filp->private_data & (1 << iChannel)))
			continue;
		for ( iItem = 0; iItem < MAX_SECTION_FILTER_NUM; iItem++)
		{
			DEMUX_SEC_LIST_T *pSecItem = &(demux_device->pChArray[iChannel].secListCB[iItem]);
			if (pSecItem->used) {
				RINGBUFFER_HEADER *pRBH = (RINGBUFFER_HEADER *)(pSecItem->rbHeader.virAddr);
				if (pRBH && BS_DISTANCE_TO_READ(pRBH->readPtr[1], *(pSecItem->pWrPtr), pSecItem->pBufferLower, pSecItem->pBufferUpper) > 4)
					return true;
			}
		}
		for ( iItem = 0; iItem < MAX_PID_FILTER_CB_NUM; iItem++)
		{
			DEMUX_PES_MAP_T *pPesMap = &(demux_device->pChArray[iChannel].pesMap[iItem]);
			if (demux_device->pChArray[iChannel].pidFilterListCB[iItem].used) {
				RINGBUFFER_HEADER *pRBH = (RINGBUFFER_HEADER *)(pPesMap->rbHeader.virAddr);
				if (pRBH && (pRBH->reserve2 == DEMUX_PESBUFFER_OP_INITIALIZED))
					if(BS_DISTANCE_TO_READ(pRBH->readPtr[1], *(pPesMap->pWrPtr), pPesMap->pBufferLower, pPesMap->pBufferUpper) > 4)
						return true;
			}
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
	if (pInfoH->virAddr == 0 && pInfoH->virAddrFromPoll) { // Check whether it can be restored form poll or not
		DEMUX_BUF_RestoreFromPoll(pInfoH);
		DEMUX_BUF_ResetRBHeader(pInfoH, &pCh->tpInfoBuffer, RINGBUFFER_STREAM, 0);
	}
	else if (pInfoH->virAddr == 0) {
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
