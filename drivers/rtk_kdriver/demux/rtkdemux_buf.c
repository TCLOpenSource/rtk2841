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
#include "rtkdemux_export.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_specialhandling.h"
#include <rtk_kdriver/rtk_vdec.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
    #include <linux/suspend.h>
#endif

void DEMUX_BUF_ResetRBHeader(DEMUX_BUF_T *pBufH, DEMUX_BUF_T *pBuf, RINGBUFFER_TYPE type, unsigned char reverse)
{
	RINGBUFFER_HEADER *pHeader = NULL;
	if (pBufH == NULL)
		return;
	pHeader = (RINGBUFFER_HEADER *)pBufH->virAddr;
	memset(pHeader, 0 , sizeof(RINGBUFFER_HEADER));
	if (pBuf == NULL)
		return;
	if (reverse) {
		pHeader->beginAddr    = DEMUX_reverseInteger(pBuf->phyAddr);
		pHeader->size         = DEMUX_reverseInteger(pBuf->size);
		pHeader->bufferID     = DEMUX_reverseInteger(type);
		pHeader->writePtr     = DEMUX_reverseInteger(pBuf->phyAddr);
		pHeader->numOfReadPtr = DEMUX_reverseInteger(1);
		pHeader->readPtr[0]   = DEMUX_reverseInteger(pBuf->phyAddr);
		pHeader->readPtr[1]   = DEMUX_reverseInteger(pBuf->phyAddr);
	} else {
		pHeader->beginAddr    = pBuf->phyAddr;
		pHeader->size         = pBuf->size;
		pHeader->bufferID     = type;
		pHeader->writePtr     = pBuf->phyAddr;
		pHeader->numOfReadPtr = 1;
		pHeader->readPtr[0]   = pBuf->phyAddr;
		pHeader->readPtr[1]   = pBuf->phyAddr;
	}
}

int DEMUX_BUF_AllocBuffer(DEMUX_BUF_T *pBuf, int size, int isCache, int useZone)
{
	isCache = demux_device->disableCache ? 0 : isCache ;
	pBuf->allocSize = size < 0x1000 ? 0x1000 : size ;
	pBuf->nonCachedaddr = 0;
	if (isCache)
		pBuf->cachedaddr = (UINT8 *)dvr_malloc_specific(pBuf->allocSize, useZone ? GFP_DCU1 : GFP_DCU2_FIRST);
	else {
		void* uncached;

		pBuf->cachedaddr = (UINT8 *)dvr_malloc_uncached_specific(
			pBuf->allocSize,
			useZone ? GFP_DCU1 : GFP_DCU2_FIRST,
			&uncached
		);

		pBuf->nonCachedaddr = (unsigned char *)uncached;
	}

	if (!(pBuf->cachedaddr)) {
		dmx_err("RTKDEMUX:  cannot allocate memory by using dvr_malloc_uncached_specific. size = %x\n", size) ;
		return -EFAULT ;
	} else {
		pBuf->phyAddr = dvr_to_phys(pBuf->cachedaddr) ;
		pBuf->virAddr = isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr ;
		pBuf->isCache = isCache ;
	}
	pBuf->size = size ;
	pBuf->fromPoll = 0 ;

#ifdef CONFIG_LG_SNAPSHOT_BOOT
	register_cma_forbidden_region(__phys_to_pfn(pBuf->phyAddr), size);
#endif
	dmx_mask_print(DEMUX_BUFFER_DEBUG, "useZone cachedAddr %lx, uncachedAddr %lx, phyAddr %x, allocSize %x\n",
		(unsigned long)(uintptr_t)pBuf->cachedaddr,	(unsigned long)(uintptr_t)pBuf->nonCachedaddr, pBuf->phyAddr, pBuf->allocSize);
	return 0 ;
}
int DEMUX_BUF_FreeBuffer(DEMUX_BUF_T *pBuf)
{
	if (pBuf->cachedaddr && !pBuf->fromPoll) {
		dvr_free(pBuf->cachedaddr) ;
		memset(pBuf, 0, sizeof(DEMUX_BUF_T));
	}
	return 0 ;
}

int DEMUX_BUF_AllocFromPoll(DEMUX_BUF_T *pBuf, int size, DEMUX_BUF_T *pSrcBuf, int isCache)
{
	/*  return DEMUX_BUF_AllocBuffer(pBuf, size, isCache, 0) ;*/

	pBuf->allocSize = (size + 0xf) & ~0xf ; /*size < 0x1000 ? 0x1000 : size ;*/

	if (pBuf->allocSize + demux_device->usedPollSize > pSrcBuf->allocSize) {
		dmx_err("RTKDEMUX: cannot allocate memory from pool, pool size = %x, used size = %x, alloc size = %x\n", pSrcBuf->allocSize, demux_device->usedPollSize, size) ;
		return -EFAULT ;
	}
	pBuf->phyAddr       = (dma_addr_t)((unsigned int)pSrcBuf->phyAddr + demux_device->usedPollSize) ;
	pBuf->cachedaddr    = pSrcBuf->cachedaddr    + demux_device->usedPollSize ;
	pBuf->nonCachedaddr = pSrcBuf->nonCachedaddr + demux_device->usedPollSize ;
	pBuf->virAddr       = isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr ;
	pBuf->isCache       = isCache ;
	pBuf->fromPoll = 1 ;
	pBuf->size       = size ;

	demux_device->usedPollSize += pBuf->allocSize ;
	dmx_mask_print(DEMUX_BUFFER_DEBUG, "Poll: cachedAddr %lx, uncachedAddr %lx, phyAddr %x, allocSize %x\n",
		(unsigned long)(uintptr_t)pBuf->cachedaddr,	(unsigned long)(uintptr_t)pBuf->nonCachedaddr,	pBuf->phyAddr, pBuf->allocSize);
	return 0 ;
}
//#########################################################################################################################################
/* state transition :
              Add PID (in IOCTL)              Remove PID (in IOCTL)                            UpdatePinInfo (in demux thread)
             ------------------->             ----------------------------------->             ------------------------------->
BUF_STAT_DONE                    BUF_STAT_NEW                                     BUF_STAT_FREE                                BUF_STAT_DONE
             <-------------------             <----------------------------------              <------------------------------
             UpdatePinInfo (in demux thread)   Add PID and buffer is not released yet           Remove PID (in IOCTL)
*/
#define WITH_SVP
#ifndef DEMUX_VIDEO_USE_PINGPONG_BUFFERS
int DEMUX_BUF_PrepareVideoBuffer(demux_channel *pCh, DEMUX_PES_DEST_T dest)
{
	int retryCnt = 0;
	int port;
	DEMUX_BUF_T *pBuf = 0;
	int64_t startTime = 0;

	if (dest == DEMUX_DEST_VDEC0) port = 0;
	else if (dest == DEMUX_DEST_VDEC1) port = 1;
	else return -1;

	pBuf = &pCh->bsVideoBuf[port];
	if (pBuf->phyAddr) {
		/*buffer is not released yet. reuse it.
		 * Only need to flush buffer(reset buffer header)
		*/
		pCh->vBufStatus[port] = BUF_STAT_NEW;
		return 0;
	}
#ifdef WITH_SVP
	startTime = CLOCK_GetPTS();
	/* In case fail to borrow SVP buffer, maybe GStreamer release it soon. 
	 * Therefore, retry at most 10 times.
	 */
	while (pBuf->phyAddr == 0 && retryCnt < 10)  {
		pBuf->phyAddr = rtkvdec_cobuffer_alloc(VDEC_SVP_BUF, port);
		retryCnt++;
	}
	dmx_crit("[%s %d]CH%d it takes %lld(ticks) to borrow SVP[%d] buffer(0x%x)\n", __func__, __LINE__, pCh->tunerHandle, CLOCK_GetPTS()-startTime, port, pBuf->phyAddr);
#endif
	if (pBuf->phyAddr == 0) {
		dmx_crit("[%s %d] notice : fail to borrow SVP buffer\n", __func__, __LINE__);
		startTime = CLOCK_GetPTS();
		if (DEMUX_BUF_AllocBuffer(pBuf, RTKVDEC_SVPMEM_SIZE, 1, 1) < 0) {
			dmx_crit("[%s %d]CH%d fatal error: fail to allocate video ES buffer\n", __func__, __LINE__, pCh->tunerHandle);
			BUG();
			return -1;
		}
		dmx_crit("[%s %d]CH%d it takes %lld(ticks) to alloc ES[%d] buffer(0x%x)\n", __func__, __LINE__, pCh->tunerHandle, CLOCK_GetPTS()-startTime, port, pBuf->phyAddr);
	} else {
		pBuf->size = RTKVDEC_SVPMEM_SIZE;
		pBuf->allocSize = 0; //it means memory is from SVP.
		pBuf->cachedaddr = dvr_remap_cached_memory(pBuf->phyAddr, pBuf->size, __builtin_return_address(0));
		pBuf->nonCachedaddr = 0;
		pBuf->isCache = 1;
		pBuf->virAddr = pBuf->cachedaddr;
		pBuf->fromPoll = 0;
	}
	if (pCh->bsVideoBufH[port].virAddr == NULL){
		if (DEMUX_BUF_AllocFromPoll(&pCh->bsVideoBufH[port], sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_crit("[%s %d]CH%d fatal error : fail to allocate bs buffer header\n", __func__, __LINE__, pCh->tunerHandle);
			DEMUX_BUF_ReturnVideoBuffer(pCh, port);
			return -1;
		}
	}
	DEMUX_BUF_ResetRBHeader(&pCh->bsVideoBufH[port], pBuf, RINGBUFFER_STREAM,  1);

	/* If we can borrow SVP buffer, inband buffer is, too. 
	 */
	pBuf = &pCh->ibVideoBuf[port];
#ifdef WITH_SVP
	if (pBuf->phyAddr == 0) {
		startTime = CLOCK_GetPTS();
		pBuf->phyAddr = rtkvdec_cobuffer_alloc(VDEC_INBAND_BUF, port);
		dmx_crit("[%s %d]CH%d it takes %lld(ticks) to borrow IB[%d] buffer(0x%x)\n", __func__, __LINE__, pCh->tunerHandle, CLOCK_GetPTS()-startTime, port, pBuf->phyAddr);
	}
#endif
	if (pBuf->phyAddr == 0) {
		dmx_crit("[%s %d]CH%d notice : fail to borrow inband buffer\n", __func__, __LINE__, pCh->tunerHandle);
		startTime = CLOCK_GetPTS();
		/* inband buffer is mapped to noncached area because we don't flush cache before update wp. */
		if (DEMUX_BUF_AllocBuffer(pBuf, RTKVDEC_IBBUF_SIZE, 0, 1) < 0) {
			dmx_crit("[%s %d]CH%d fatal error: fail to allocate video IB buffer\n", __func__, __LINE__, pCh->tunerHandle);
			BUG();
			return -1;
		}
		dmx_crit("[%s %d]CH%d it takes %lld(ticks) to alloc IB[%d] buffer(0x%x)\n", __func__, __LINE__, pCh->tunerHandle, CLOCK_GetPTS()-startTime, port, pBuf->phyAddr);
	} else {
		pBuf->size = RTKVDEC_IBBUF_SIZE;
		pBuf->allocSize = 0; //it means memory is from SVP.
		pBuf->cachedaddr = 0;
		pBuf->nonCachedaddr = dvr_remap_uncached_memory(pBuf->phyAddr, pBuf->size, __builtin_return_address(0));
		pBuf->isCache = 0;
		pBuf->virAddr = pBuf->nonCachedaddr;
		pBuf->fromPoll = 0;
	}
	if (pCh->ibVideoBufH[port].virAddr == NULL){
		if (DEMUX_BUF_AllocFromPoll(&pCh->ibVideoBufH[port], sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_crit("[%s %d]CH%d fatal error : fail to allocate ib buffer header\n", __func__, __LINE__, pCh->tunerHandle);
			DEMUX_BUF_ReturnVideoBuffer(pCh, port);
			return -1;
		}
	}
	DEMUX_BUF_ResetRBHeader(&pCh->ibVideoBufH[port], pBuf, RINGBUFFER_COMMAND, 1);

	pCh->vBufStatus[port] = BUF_STAT_NEW;
	return 0;
}

int DEMUX_BUF_ReturnVideoBuffer(demux_channel *pCh, int port)
{
	DEMUX_BUF_T *pBuf = 0;

	if (port < 0 || port >= 2)
		return -1;

	pBuf = &pCh->bsVideoBuf[port];
	if (pBuf->allocSize == 0) {
		dmx_crit("[%s %d]CH%d return SVP buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
		if (pBuf->phyAddr) {
			rtkvdec_cobuffer_free(VDEC_SVP_BUF, pBuf->phyAddr);
			dvr_unmap_memory(pBuf->isCache ? (void *)pBuf->cachedaddr : (void *)pBuf->nonCachedaddr, pBuf->size);
		}
	} else {
		dmx_crit("[%s %d]CH%d return ES buf = 0x%x, virAddr = %p\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr, pBuf->virAddr);
		if (pBuf->cachedaddr)
			dvr_free(pBuf->cachedaddr);
	}
	memset(pBuf, 0, sizeof(DEMUX_BUF_T));

	pBuf = &pCh->ibVideoBuf[port];
	if (pBuf->allocSize == 0) {
		dmx_crit("[%s %d]CH%d return IB buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
		if (pBuf->phyAddr) {
			rtkvdec_cobuffer_free(VDEC_INBAND_BUF, pBuf->phyAddr);
			dvr_unmap_memory(pBuf->isCache ? (void *)pBuf->cachedaddr : (void *)pBuf->nonCachedaddr, pBuf->size);
		}
	} else {
		dmx_crit("[%s %d]CH%d return IB buf = 0x%x, virAddr = %p\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr, pBuf->virAddr);
		if (pBuf->cachedaddr)
			dvr_free(pBuf->cachedaddr);
	}
	memset(pBuf, 0, sizeof(DEMUX_BUF_T));

	return 0;
}
/*
int DEMUX_BUF_AllocateVideoBuffer(demux_channel *pCh, int port)
{
	DEMUX_BUF_T *pBuf = 0;

	pBuf = &pCh->bsVideoBuf[port];
	pBuf->allocSize = pBuf->size = VDEC_SVP_BUF;
	pBuf->isCache = 1;
	pBuf->cachedaddr = (UINT8 *)dvr_malloc_specific(pBuf->allocSize, GFP_DCU1);
	if (pBuf->cachedaddr == 0) {
		dmx_crit("[%s %d] fatal error: fail to allocate video ES buffer\n", __func__, __LINE__);
		BUG();
		return -1;
	}
	pBuf->nonCachedaddr = pBuf->cachedaddr;
	pBuf->phyAddr = dvr_to_phys(pBuf->cachedaddr);
	pBuf->virAddr = isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr;
	pBuf->fromPoll = 0;
	dmx_crit("[%s %d]CH%d ES buf = 0x%x, vir = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr, pBuf->virAddr);

	//prepare inband buffer
	pBuf = &pCh->ibVideoBuf[port];
	pBuf->allocSize = pBuf->size = VDEC_INBAND_BUF;
	pBuf->isCache = 0;
	pBuf->cachedaddr = (UINT8 *)dvr_malloc_uncached_specific(pBuf->allocSize, GFP_DCU1, (void*)&pBuf->nonCachedaddr);
	if (pBuf->cachedaddr == 0) {
		dmx_crit("[%s %d] fatal error: fail to allocate video IB buffer\n", __func__, __LINE__);
		dvr_free(pCh->bsVideoBuf[port].virAddr);
		memset(&pCh->bsVideoBuf[port], 0, sizeof(DEMUX_BUF_T));
		BUG();
		return -1;
	}
	pBuf->phyAddr = dvr_to_phys(pBuf->cachedaddr);
	pBuf->virAddr = isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr;
	pBuf->fromPoll = 0;
	dmx_crit("[%s %d]CH%d IB buf = 0x%x, vir = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr, pBuf->virAddr);

	SET_FLAG(pCh->events, EVENT_SET_VIDEO_PIN_INFO);
	return 0;
}
*/
void DEMUX_BUF_UpdatePinInfo(demux_channel *pCh, char bVideoPin)
{
	int i, port;
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
	DEMUX_BUF_T *pBufBS, *pBufIB, *pBufBSH, *pBufIBH;

	for (i = VIDEO_PIN; i < NUMBER_OF_PINS; i++) {
		if ((bVideoPin && (i == AUDIO_PIN || i== AUDIO2_PIN))
		|| (!bVideoPin && (i == VIDEO_PIN || i == VIDEO2_PIN)))
			continue;

		if(i == VIDEO_PIN || i == VIDEO2_PIN) {
			port = (i != VIDEO_PIN);
			pBufBSH  = &pCh->bsVideoBufH[port];
			pBufIBH  = &pCh->ibVideoBufH[port];
			pBufBS   = &pCh->bsVideoBuf[port];
			pBufIB   = &pCh->ibVideoBuf[port];

		} else {
			continue;

		}

		pPinInfo   = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_BS];
		pPinIBInfo = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_IB];
		if (pCh->vBufStatus[port] == BUF_STAT_FREE) {
			DEMUX_BUF_ReturnVideoBuffer(pCh, port);
			memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));

			dmx_crit("[%s %d]reset CH%d pin = %d, port = %d\n", __func__, __LINE__, pCh->tunerHandle, i, port);
			pCh->vBufStatus[port] = BUF_STAT_DONE;
		} else if (pCh->vBufStatus[port] == BUF_STAT_NEW) {
			RINGBUFFER_HEADER* pHeader = 0;
			//don't reset inband buffer header
			DEMUX_BUF_ResetRBHeader(pBufBSH, pBufBS, RINGBUFFER_STREAM,  1);
			IOCTL_SetPinInfo(pPinIBInfo, (RINGBUFFER_HEADER *)pBufIBH->virAddr, pBufIB);
			IOCTL_SetPinInfo(pPinInfo, (RINGBUFFER_HEADER *)pBufBSH->virAddr, pBufBS);
			dmx_crit("[%s %d]set CH%d pin = %d\n", __func__, __LINE__, pCh->tunerHandle, i);

			pHeader = (RINGBUFFER_HEADER *)pBufIBH->virAddr;
			dmx_crit("[%s %d]IB rp=0x%lx, wp = 0x%lx, base = 0x%lx\n", __func__, __LINE__, pHeader->readPtr[0], pHeader->writePtr, pHeader->beginAddr);

			pCh->vBufStatus[port] = BUF_STAT_DONE;
		}

	}
}
#endif
//###########################################################AUDIO BUFFER#################################################
#ifdef DEMUX_AUDIO_USE_GLOBAL_BUFFER
bool isPinOwnTheBuffer(demux_channel * pCh, int pin, DEMUX_PIN_BUFFER_T * pBuffer)
{
	return ((pCh->tunerHandle == pBuffer->ownerChannel) &&(pin == pBuffer->ownerPin));
}

int demuxFreeAudioBuffer(DEMUX_PIN_BUFFER_T * pBuffer)
{
	//DO NOT RETURE AUDIO BUFFER , JUST RESET RING BUFFER EADER
	if (pBuffer == NULL)
	{
		dmx_err("[%s,%d], param error, \n", __func__, __LINE__);
		return -1;
	}
	//return bs buffer
#ifdef RETUN_AUDIO_BUFFER
	if (pBuffer->bsBufferH.virAddr)
	{
		DEMUX_BUF_ResetRBHeader(&pBuffer->bsBufferH,NULL, 0,0);
	}
	if (pBuffer->bsBuffer.phyAddr)
	{
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s %d]CH%d return audio ES buf = 0x%x, virAddr = %p\n", 
			__func__, __LINE__, pCh->tunerHandle, pBuffer->bsBuffer->phyAddr, pBuffer->bsBuffer->virAddr);
		DEMUX_BUF_FreeBuffer(&pBuffer->bsBuffer);
	}
	//retrun ib buffer
	if (pBuffer->ibBufferH.virAddr)
	{
		DEMUX_BUF_ResetRBHeader(&pBuffer->ibBufferH, NULL, 0,0);
	}
	if (pBuffer->ibBuffer.phyAddr)
	{
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s %d]CH%d return audio IB buf = 0x%x, virAddr = %p\n", 
			__func__, __LINE__, pCh->tunerHandle, pBuffer->ibBuffer->phyAddr, pBuffer->ibBuffer->virAddr);
		DEMUX_BUF_FreeBuffer(&pBuffer->ibBuffer);
	}
#else
	if (pBuffer->bsBufferH.virAddr)
	{

		DEMUX_BUF_ResetRBHeader(&pBuffer->bsBufferH, &pBuffer->bsBuffer, RINGBUFFER_STREAM, 1);

	}
	if (pBuffer->ibBufferH.virAddr)
	{
		DEMUX_BUF_ResetRBHeader(&pBuffer->ibBufferH, &pBuffer->ibBuffer, RINGBUFFER_COMMAND,  1);

	}
#endif
	return 0;
}

int demuxPrepareAudioBuffer(DEMUX_PIN_BUFFER_T *pBuffer)
{
	if(pBuffer == NULL)
	{
		dmx_err("[%s,%d], param error!!\n", __func__, __LINE__);
		return -1;
	}

	if (pBuffer->bsBufferH.virAddr == 0)
	{
		if (DEMUX_BUF_AllocFromPoll(&pBuffer->bsBufferH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_err("[%s %d]out of memory: allocate audio bs buffer header fail\n", __func__, __LINE__);
			return -1;
		}
	}
	if (pBuffer->ibBufferH.virAddr == 0) {
		if (DEMUX_BUF_AllocFromPoll(&pBuffer->ibBufferH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_err("[%s %d] out of memory: allocate audio ib buffer header fail\n", __func__, __LINE__);
			return -1;
		}
	}
	if (pBuffer->bsBuffer.virAddr == 0 ||pBuffer->ibBuffer.virAddr == 0 )
	{
		if ((pBuffer->bsBuffer.virAddr == 0 && DEMUX_BUF_AllocBuffer(&pBuffer->bsBuffer, demux_device->sizeOfAudioBS, 1, 1) < 0) 
			|| (pBuffer->ibBuffer.virAddr == 0 && DEMUX_BUF_AllocBuffer(&pBuffer->ibBuffer, demux_device->sizeOfAudioIB, 0, 1) < 0)) {
			dmx_err("[%s %d]out of memory: allocate audio bs buffer\n", __func__, __LINE__);
			DEMUX_BUF_FreeBuffer(&pBuffer->bsBuffer);
			DEMUX_BUF_FreeBuffer(&pBuffer->ibBuffer);
			return -1;
		}
		//only when alloc buffer ,reset HEADER
		DEMUX_BUF_ResetRBHeader(&pBuffer->bsBufferH, &pBuffer->bsBuffer, RINGBUFFER_COMMAND, 1);
		DEMUX_BUF_ResetRBHeader(&pBuffer->ibBufferH, &pBuffer->ibBuffer, RINGBUFFER_STREAM,  1);
	}
	return 0;
}

bool demuxAudio_getFreeBuffer(DEMUX_PIN_BUFFER_T **ppbuffer)
{
	int i, tWaitFree = -1;;
	if (ppbuffer == NULL){
		return false;
	}

	for (i = 0; i<MAX_ADEC_NUM; i++)
	{
		if ((demux_device->audioBuffer[i].status == BUF_STAT_FREE) && (tWaitFree<0))
		{
			tWaitFree = i;
			continue;
		}
		//prepare the buffer
		//demuxAudio_prepareBufer(&demux_device->audioBuffer[i]);
		if (demux_device->audioBuffer[i].status == BUF_STAT_OFFLINE)
			break;
	}

	if (i == MAX_ADEC_NUM )
	{
		if ( tWaitFree>=0)
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s, %d]  no unUsedBuffer, try resuse Buffer:%d(ch:%d, pin:%d)\n",
				__func__, __LINE__,  tWaitFree,demux_device->audioBuffer[tWaitFree].ownerChannel,demux_device->audioBuffer[tWaitFree].ownerPin);
			demux_device->audioBuffer[tWaitFree].status 		= BUF_STAT_REUSED;
			i  = tWaitFree;
		}
		else
		{
			dmx_err("[%s,%d],  ERROR Not idle Buffer for audio \n", __func__, __LINE__);
			return false;
		}
	}
	else{
		//:p1
		demuxPrepareAudioBuffer(&demux_device->audioBuffer[i]);
		demux_device->audioBuffer[i].status 		= BUF_STAT_NEW;
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d]  alloc buffer success\n", __func__, __LINE__);
	}
	//demux_device->audioBuffer[tWaitFree].ownerChannel	= pCh->tunerHandle;
	//demux_devide->audioBuffer[tWaitFree].ownerPin		= pin;
	*ppbuffer = &demux_device->audioBuffer[i];
	dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] select AudioBuffer %d\n",__func__, __LINE__, demux_device->audioBuffer[i].bufferIndex);
	return true;
}
bool demxAudio_handleHoldBuffer(demux_channel *pCh, int pin)
{
	if (pCh==NULL && pin != AUDIO_PIN && pin != AUDIO2_PIN)
	{
		dmx_err("[%s,%d], param error, pin:%d\n", __func__, __LINE__, pin);
		return false;
	}
	if (pCh->pinInfo[pin].pBuffer == NULL )
	{
		dmx_err("[%s, %d], ch:%d, pin:%d, do not hold buffer \n", __func__, __LINE__, pCh->tunerHandle, pin)
		return false;
	}

	if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_OFFLINE)
	{

		dmx_err("[%s,%d] ch:%d, pin:%d buffer status wrong, OFFLINE BUT BEEN  REFERED\n",__func__, __LINE__, pCh->tunerHandle, pin);
		BUG();
		pCh->pinInfo[pin].pBuffer = NULL;
		if(demuxAudio_getFreeBuffer(&pCh->pinInfo[pin].pBuffer))
		{
			pCh->pinInfo[pin].pBuffer->ownerChannel = pCh->tunerHandle;
			pCh->pinInfo[pin].pBuffer->ownerPin = pin;
			return true;
		}
		else 
			return false;
	}
	if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_ONLINE ||pCh->pinInfo[pin].pBuffer->status == BUF_STAT_NEW){
		//check owner :should same
		if (isPinOwnTheBuffer(pCh,pin, pCh->pinInfo[pin].pBuffer))
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d, buffer status:%d  DO NOTHING\n",
				__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status);
			return true;
		}
		else{
			dmx_err("[%s,%d] ch:%d, pin:%d,ERROR buffer status:%d  OWNER: CH:%d, pin:%d \n",
				__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status, pCh->pinInfo[pin].pBuffer->ownerChannel, pCh->pinInfo[pin].pBuffer->ownerPin);
			BUG();
			return false;
		}
	}
	else if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_FREE)
	{
		//SAME OWNER
		//if (isPinOwnTheBuffer(pCh,pin, pCh->pinInfo[pin].pBuffer)){
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d, buffer status:%d  still hold buffer REUSE it \n",
				__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status);
			pCh->pinInfo[pin].pBuffer->status 		= BUF_STAT_NEW;
			pCh->pinInfo[pin].pBuffer->ownerChannel 	= pCh->tunerHandle;
			pCh->pinInfo[pin].pBuffer->ownerPin		= pin;
			return true;
		//}
		//else{//DIFF OWNER
		//	dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d,ERROR buffer status:%d  owner: ch%d, pin:%d\n",
		//		__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status, pCh->pinInfo[pin].pBuffer->ownerChannel, pCh->pinInfo[pin].pBuffer->ownerPin);
		//	BUG();
		//	return false;
		//}
	}
	else if(pCh->pinInfo[pin].pBuffer->status == BUF_STAT_REUSED)
	{
		if (isPinOwnTheBuffer(pCh,pin, pCh->pinInfo[pin].pBuffer))
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d, buffer status:%d  already got buffer with for previous release \n",
				__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status);
			return true;
		}
		else
		{
			//got new buffer
			if(demuxAudio_getFreeBuffer(&pCh->pinInfo[pin].pBuffer_reserved))
			{
				dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s, %d], ch:%d, pin:%d, request buffer success, still hold a buffer to relase\n",
					__func__, __LINE__, pCh->tunerHandle, pin);
				pCh->pinInfo[pin].pBuffer_reserved->ownerChannel = pCh->tunerHandle;
				pCh->pinInfo[pin].pBuffer_reserved->ownerPin = pin;
				pCh->pinInfo[pin].pBuffer->status 		= BUF_STAT_REUSED_II;
				return true;
			}
			else
			{
				dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s, %d], ch:%d, pin:%d, request buffer fail, \n",
					__func__, __LINE__, pCh->tunerHandle, pin);
				return false;
			}

		}
	}
	else if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_REUSED_II)
	{
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d, buffer status:%d  already got buffer with for previous release\n",
			__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status);
		return true;
	}

	dmx_err("[%s, %d], ch:%d,pin:%d, buffer status not recognize status:%d\n", 
		__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->status);
	return false;
}

bool demuxAudio_updatePinStatus(demux_channel *pCh, int pin)
{
	bool ret = false;
	DEMUX_BUF_PIN_T *pPinInfo=NULL, *pPinIBInfo=NULL;
	if (pCh == NULL || ((pin !=AUDIO_PIN) &&(pin != AUDIO2_PIN)))
	{
		dmx_err("[%s, %d] param wrong pch:%p, pin:%d \n", __func__, __LINE__, pCh, pin);
		return false;
	}
	if (pCh->pinInfo[pin].pBuffer == NULL)
	{
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG, "[%s, %d] ch:%d, pin:%d, there is not buffer in this pin \n", __func__, __LINE__, pCh->tunerHandle, pin);
		return true;
	}
	if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_NEW)
	{//:P8
		if (isPinOwnTheBuffer(pCh,pin, pCh->pinInfo[pin].pBuffer))
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, buffer[%d] online \n",
				__func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex);

			IOCTL_SetPinInfo(&pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB], (RINGBUFFER_HEADER *)pCh->pinInfo[pin].pBuffer->ibBufferH.virAddr, &pCh->pinInfo[pin].pBuffer->ibBuffer);
			IOCTL_SetPinInfo(&pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS], (RINGBUFFER_HEADER *)pCh->pinInfo[pin].pBuffer->bsBufferH.virAddr, &pCh->pinInfo[pin].pBuffer->bsBuffer);
			pCh->pinInfo[pin].pBuffer->status = BUF_STAT_ONLINE;
			ret = true;
		}
		else{
			dmx_err("[%s,%d], ch:%d, pin:%d, buffer[%d]status not sync,bufferOwer(ch:%d,pin:%d)\n",
				 __func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex, pCh->pinInfo[pin].pBuffer->ownerChannel,pCh->pinInfo[pin].pBuffer->ownerPin);
			BUG();
			ret = false;
		}
	}
	else if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_FREE)
	{
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, buffer[%d] (ch:%d, pin:%d)OFFLINE \n", 
			__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->bufferIndex, pCh->pinInfo[pin].pBuffer->ownerChannel, pCh->pinInfo[pin].pBuffer->ownerPin);
		pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
		pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
		memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
		memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
		//need to return buffer 
		demuxFreeAudioBuffer(pCh->pinInfo[pin].pBuffer)	;
		//no need to return buffer.
		//TODO
		pCh->pinInfo[pin].pBuffer->status = BUF_STAT_OFFLINE;
		pCh->pinInfo[pin].pBuffer = NULL;
		ret = true;
		
	}
	else if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_REUSED)
	{//:P5
		if (!isPinOwnTheBuffer(pCh, pin, pCh->pinInfo[pin].pBuffer))
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, release reused buffer[%d] \n",
				__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->bufferIndex);
			pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
			pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
			memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			pCh->pinInfo[pin].pBuffer->status = BUF_STAT_NEW;
			pCh->pinInfo[pin].pBuffer = NULL;
			ret = true;
		}
		else
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, wait buffer [%d] release \n", 
				__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer->bufferIndex);
			ret = false;
		}
	}
	else if (pCh->pinInfo[pin].pBuffer->status == BUF_STAT_REUSED_II)
	{
		if (!isPinOwnTheBuffer(pCh, pin, pCh->pinInfo[pin].pBuffer))
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, release reusedII buffer %d \n", 
				__func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex);
			pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
			pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
			memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			pCh->pinInfo[pin].pBuffer->status = BUF_STAT_NEW;
			pCh->pinInfo[pin].pBuffer = NULL;
			//reserver buffer
			if (pCh->pinInfo[pin].pBuffer_reserved){
				dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, handle reserved buffer [%d]\n", 
					__func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex);
				pCh->pinInfo[pin].pBuffer = pCh->pinInfo[pin].pBuffer_reserved;
				pCh->pinInfo[pin].pBuffer_reserved = NULL;
				if (isPinOwnTheBuffer(pCh, pin, pCh->pinInfo[pin].pBuffer))
				{
					if (demuxAudio_updatePinStatus(pCh, pin))
						ret = true;
					else
						ret = false;
				}
				else{
					dmx_err("[%s,%d] ch:%d, pin :%d,  reusedII buffer %d , owner ERROR (CH:%d, pin:%d)\n", 
						__func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex, pCh->pinInfo[pin].pBuffer->ownerChannel,pCh->pinInfo[pin].pBuffer->ownerPin);
					BUG();
					ret = false;
				}
			}
			else{
				dmx_err("[%s,%d] ch:%d, pin :%d, reusedII pin, miss reserved buffer \n",__func__, __LINE__, pCh->tunerHandle, pin );
				BUG();
				ret=false;
			}
		}
		else
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d,  reserved buffer [%d] wiat release\n", 
					__func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex);
			ret = false;
		}
	}
	else{
		dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin :%d, bufer[%d], status:%d, no nothing\n", 
			__func__, __LINE__, pCh->tunerHandle, pin,pCh->pinInfo[pin].pBuffer->bufferIndex, pCh->pinInfo[pin].pBuffer->status);
		ret = true;
	}
	return ret;
}

int DEMUX_BUF_RequestAudioBuffer(demux_channel *pCh, int pin)
{//this function should already hold channel mutex.

	if (pCh==NULL && pin != AUDIO_PIN && pin != AUDIO2_PIN)
	{
		dmx_err("[%s,%d], param error, pin:%d\n", __func__, __LINE__, pin);
		return -1;
	}

	mutex_lock(&demux_device->mutex);
	if (pCh->pinInfo[pin].pBuffer != NULL )//HOLD BUFFER
	{
		if (demxAudio_handleHoldBuffer(pCh, pin))
		{
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d, request buffer success \n",__func__, __LINE__, pCh->tunerHandle, pin);
			goto SUCCESS;
		}
		else
		{
			dmx_err("[%s,%d] ch:%d, pin:%d, request buffer fail \n",__func__, __LINE__, pCh->tunerHandle, pin);
			goto FAIL;
		}
	}
	else
	{
		if (demuxAudio_getFreeBuffer(&pCh->pinInfo[pin].pBuffer))
		{
			pCh->pinInfo[pin].pBuffer->ownerChannel = pCh->tunerHandle;
			pCh->pinInfo[pin].pBuffer->ownerPin = pin;
			dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s,%d] ch:%d, pin:%d, request buffer success \n",__func__, __LINE__, pCh->tunerHandle, pin);
			goto SUCCESS;
		}
		else
		{
			dmx_err("[%s,%d] ch:%d, pin:%d, request buffer fail \n",__func__, __LINE__, pCh->tunerHandle, pin);
			goto FAIL;

		}
	}

SUCCESS:
	mutex_unlock(&demux_device->mutex);
	return 0;
FAIL:
	mutex_unlock(&demux_device->mutex);
	return -1;

}
int DEMUX_BUF_ReleaseAudioBuffer(demux_channel *pCh, int pin)
{
	DEMUX_PIN_BUFFER_T *pBuffer=NULL;
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
	pPinInfo   = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_BS];
	pPinIBInfo = &pCh->pinInfo[pin].bufInfo[DEMUX_STREAM_TYPE_IB];
	if (pCh==NULL && pin != AUDIO_PIN && pin != AUDIO2_PIN)
	{
		dmx_err("[%s,%d], param error, pin:%d\n", __func__, __LINE__, pin);
		return -1;
	}
	mutex_lock(&demux_device->mutex);
	pBuffer = pCh->pinInfo[pin].pBuffer;
	if (pBuffer != NULL)
	{
		
		if(pBuffer->status == BUF_STAT_ONLINE ){
			dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, release  buffer status:%d, \n",
				__func__, __LINE__, pCh->tunerHandle, pin, pBuffer->status);
			pBuffer->status = BUF_STAT_FREE;
		}
		else if (pBuffer->status == BUF_STAT_NEW)
		{
			//check use owner
			dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, release unused buffer status:%d, \n",
				__func__, __LINE__, pCh->tunerHandle, pin, pBuffer->status);
			memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			demuxFreeAudioBuffer(pCh->pinInfo[pin].pBuffer)	;
			pCh->pinInfo[pin].pBuffer->status = BUF_STAT_OFFLINE;
			pCh->pinInfo[pin].pBuffer = NULL;
		}
		else if (pBuffer->status == BUF_STAT_REUSED )
		{
			if (isPinOwnTheBuffer(pCh,pin, pBuffer))
			{
				dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, status:%d, undo reuse \n",
					__func__, __LINE__, pCh->tunerHandle, pin, pBuffer->status);
				memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
				memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
				pCh->pinInfo[pin].pBuffer->ownerChannel = -1;
				pCh->pinInfo[pin].pBuffer->ownerPin = -1;
				pCh->pinInfo[pin].pBuffer->status = BUF_STAT_FREE;
				pCh->pinInfo[pin].pBuffer = NULL;
			}
			else
			{
				dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, status:%d, wait for release , do nothing\n",
					__func__, __LINE__, pCh->tunerHandle, pin, pBuffer->status);
			}
		}
		else if (pBuffer->status == BUF_STAT_REUSED_II)
		{

			if (isPinOwnTheBuffer(pCh,pin, pBuffer))
			{
				dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, status:%d, undo reuse \n",
					__func__, __LINE__, pCh->tunerHandle, pin, pBuffer->status);
				memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
				memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
				pCh->pinInfo[pin].pBuffer->ownerChannel = -1;
				pCh->pinInfo[pin].pBuffer->ownerPin = -1;
				pCh->pinInfo[pin].pBuffer->status = BUF_STAT_FREE;
				pCh->pinInfo[pin].pBuffer = NULL;
			}
			else
			{
				if (isPinOwnTheBuffer(pCh, pin, pCh->pinInfo[pin].pBuffer_reserved))
				{
					if (pCh->pinInfo[pin].pBuffer_reserved->status == BUF_STAT_NEW)
					{
						dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d,reserved buffer Free status:%d,  \n",
							__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer_reserved->status);
						memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
						memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
						demuxFreeAudioBuffer(pCh->pinInfo[pin].pBuffer_reserved)	;
						pCh->pinInfo[pin].pBuffer_reserved->status = BUF_STAT_OFFLINE;
						pCh->pinInfo[pin].pBuffer_reserved = NULL;
					}
					else if (pCh->pinInfo[pin].pBuffer_reserved->status == BUF_STAT_REUSED ||pCh->pinInfo[pin].pBuffer_reserved->status == BUF_STAT_REUSED_II)
					{
						dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, reserved buffer status:%d, undo reuse \n",
							__func__, __LINE__, pCh->tunerHandle, pin, pBuffer->status);
						memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
						memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));
						pCh->pinInfo[pin].pBuffer_reserved->ownerChannel = -1;
						pCh->pinInfo[pin].pBuffer_reserved->ownerPin = -1;
						pCh->pinInfo[pin].pBuffer_reserved->status = BUF_STAT_FREE;
						pCh->pinInfo[pin].pBuffer_reserved = NULL;
					}
				}
				else{
					dmx_mask_print(DEMUX_BUFFER_DEBUG|DEMUX_NOTICE_PRINT,"[%s, %d] ch:%d, pin:%d, reused_II pin, reserved buffer status not sync owner:ch:%d, pin:%d\n",
						__func__, __LINE__, pCh->tunerHandle, pin, pCh->pinInfo[pin].pBuffer_reserved->ownerChannel,pCh->pinInfo[pin].pBuffer_reserved->ownerPin);
					BUG();
					mutex_unlock(&demux_device->mutex);
					return -1;
				}
			}
		}
		

	}
	mutex_unlock(&demux_device->mutex);
	return 0;
}

int DEMUX_BUF_UpdateChannelAudioPinStatus(demux_channel *pCh)
{
	int pin = 0;
	int ret = 0;

	if (pCh == NULL){
		dmx_err("[%s,%d], param ERROR\n", __func__, __LINE__);
		return -1;
	}
	mutex_lock(&demux_device->mutex);
	for (pin = VIDEO_PIN; pin < NUMBER_OF_PINS; pin++)
	{
		if(pin == AUDIO_PIN || pin== AUDIO2_PIN)
		{
			if (pCh->pinInfo[pin].pBuffer)
			{
				if (!demuxAudio_updatePinStatus(pCh, pin)){
					dmx_mask_print(DEMUX_NOTICE_PRINT|DEMUX_BUFFER_DEBUG,"[%s, %d] ch:%d, pin:%d, unfinish jobs \n", __func__, __LINE__, pCh->tunerHandle, pin);
					ret = -1;
				}

			}
				
		}
	}
	mutex_unlock(&demux_device->mutex);
	return ret;
}

void DEMUX_BUF_InitAudioBuffer()
{
	int i = 0;
	for (i=0; i<demux_device->numberOfAD; i++)
	{
		memset(&(demux_device->audioBuffer[i]), 0, sizeof(DEMUX_PIN_BUFFER_T));
		demux_device->audioBuffer[i].ownerPin=-1;
		demux_device->audioBuffer[i].ownerChannel = -1;
		demux_device->audioBuffer[i].status = BUF_STAT_OFFLINE;
		demux_device->audioBuffer[i].bufferIndex = i;
	}
}
#endif //DEMUX_AUDIO_USE_GLOBAL_BUFFER

//########################################################## PES BUFFER ##################################################
#ifdef DEMUX_PES_BUFFER_DYNAMIC_ALLOC
int DEMUX_PESBuffer_Alloc(DEMUX_PES_MAP_T *pMap)
{
	RINGBUFFER_HEADER *pRBH = NULL;
	if (pMap == NULL){
		dmx_err("%s-%d : invalid param \n", __func__, __LINE__);
		return -1;
	}

	if (((pMap->phyAddr) != 0) || (pMap->pesFilterBuffer.phyAddr != 0))
	{
		dmx_err("%s-%d : pes buffer is already allocated \n", __func__, __LINE__);
		return -1;
	}
	if (pMap->rbHeader.virAddr == NULL){
		if (DEMUX_BUF_AllocFromPoll(&pMap->rbHeader, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0){
			dmx_err("%s_%d, pes allocate header fail!\n", __func__, __LINE__);
			return -1;
		}
	}
	if (DEMUX_BUF_AllocBuffer(&(pMap->pesFilterBuffer), PES_FILTER_RING_BUFFER_SIZE, 1, 0) < 0){
		dmx_err("%s-%d : pes Buffer Allocate fail!\n", __func__, __LINE__);
		return -1;
	}

	pRBH = (RINGBUFFER_HEADER *)pMap->rbHeader.virAddr;
	if (pRBH == NULL){
		dmx_err("%s-%d : pes header buffer not be allocate !\n", __func__, __LINE__);
		DEMUX_BUF_FreeBuffer(&(pMap->pesFilterBuffer));
		return -1;
	}

	pMap->virAddr = pMap->pesFilterBuffer.virAddr;
	pMap->phyAddr = (unsigned int)pMap->pesFilterBuffer.phyAddr;

	pRBH->beginAddr    = (unsigned long)pMap->phyAddr;
	pRBH->size         = PES_FILTER_RING_BUFFER_SIZE;
	pRBH->writePtr     = pRBH->beginAddr;
	pRBH->numOfReadPtr = 1;
	pRBH->readPtr[0]   = pRBH->beginAddr;

	pMap->pWrPtr        = &pRBH->writePtr;
	pMap->pRdPtr        = &pRBH->readPtr[0];
	pMap->pBufferLower  = (unsigned char *)pRBH->beginAddr;
	pMap->pBufferUpper  = (unsigned char *)(pMap->pBufferLower + PES_FILTER_RING_BUFFER_SIZE);
	pMap->phyAddrOffset = (long) pMap->phyAddr - (long) pMap->virAddr;

	pMap->bufferStatus = BUFFER_NEW;
	return 0;


}
int DEMUX_PESBuffer_Free(DEMUX_PES_MAP_T *pMap)
{
	if (pMap == NULL){
		dmx_err("%s-%d : invalid param \n", __func__, __LINE__);
		return -1;
	}
	if (((pMap->phyAddr) == 0) || (pMap->pesFilterBuffer.phyAddr == 0))
	{
		dmx_err("%s-%d : pes buffer is not allocated \n", __func__, __LINE__);
		return 0;
	}

	if (DEMUX_BUF_FreeBuffer(&(pMap->pesFilterBuffer))<0)
	{
		dmx_err("FAIL!!!!: fail to free pes buffer\n");
		return -1;
	}

	pMap->virAddr = NULL;
	pMap->phyAddr = 0;

	return 0;

}
void DEMUX_PESBuffer_UpdateBuferStatus(demux_channel *pCh)
{
	int index  = 0;
	if (pCh == NULL){
		dmx_err("%s-%d : invalid param \n", __func__, __LINE__);
		return ;
	}
	for (index =0; index < MAX_PID_FILTER_CB_NUM; index++){
		DEMUX_PES_MAP_T *pMap = &pCh->pesMap[index];
		if (pMap->bufferStatus == BUFFER_FREE){
			dmx_mask_print(DEMUX_PES_DEBUG,"updatebufferstatus  free pes buffer : ch: %d, pesId:%d \n", pCh->tunerHandle, index);
			if (DEMUX_PESBuffer_Free(pMap) < 0){
				dmx_err(DGB_COLOR_RED"FAIL!!!!: fail to free pes buffer : ch:%d, pesid:%d\n"DGB_COLOR_NONE, pCh->tunerHandle, index);
			}
			else
				pMap->bufferStatus = BUFFER_OFFLINE;
		}

		if (pMap->bufferStatus == BUFFER_NEW){
			RINGBUFFER_HEADER *pRBH = (RINGBUFFER_HEADER *)pMap->rbHeader.virAddr;
			if (pRBH->reserve2 == DEMUX_PESBUFFER_OP_PENDING_FOR_INIT){//this bit set by hal,to notify kernel do init
				pRBH->writePtr     = pRBH->beginAddr;
				pRBH->numOfReadPtr = 1;
				pRBH->readPtr[0]   = pRBH->beginAddr;
				pRBH->readPtr[1]   = pRBH->beginAddr;

				pMap->unitSize = 0 ;
				pMap->size = 0 ;
				pMap->curWr = (unsigned char *)(uintptr_t)pRBH->beginAddr;

				pRBH->reserve2 = DEMUX_PESBUFFER_OP_INITIALIZED;
				dmx_mask_print(DEMUX_PES_DEBUG,"updatebufferstatus reset pes buffer :ch:%d, pesid:%d, phyAddr:%lx \n", pCh->tunerHandle, index, pRBH->beginAddr);
			}
			pMap->bufferStatus = BUFFER_ONLINE;
		}
	}
}
#endif //DEMUX_PES_BUFFER_DYNAMIC_ALLOC
