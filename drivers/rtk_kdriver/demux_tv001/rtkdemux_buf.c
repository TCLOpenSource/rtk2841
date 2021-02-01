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
#include "rtkdemux_ioctl_ex.h"
#include <rtk_kdriver/rtk_vdec.h>
#ifdef CONFIG_LG_SNAPSHOT_BOOT
    #include <linux/suspend.h>
#endif

#ifdef USE_STATIC_RESERVED_BUF
#include <mach/rtk_platform.h>
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
	pBuf->fromVBM = 0;
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

int DEMUX_BUF_SetupRefClockBuf(demux_channel *pCh, unsigned long phyAddr, int size)
{
	DEMUX_BUF_T *pBuf;

	/* set up reference clock */
	if (phyAddr == 0 || size == 0)
		return -1;

	if (pCh->bUseSelfBuf) {
		dmx_crit("[%s %d] ERROR: buffer owner is KERNEL\n", __func__, __LINE__);
		return -1;
	}
	pBuf = &pCh->refClockBuffer;
	if (pBuf->virAddr) {
		if (pCh->state == DEMUX_STATE_STOP)
			dvr_unmap_memory(pBuf->virAddr, pBuf->size);
		else
			BUG();
	}

	pBuf->size = size;
	pBuf->allocSize = 0; /* it means memory is from user space. */
	pBuf->phyAddr = phyAddr;
	pBuf->nonCachedaddr = dvr_remap_uncached_memory(pBuf->phyAddr, pBuf->size, __builtin_return_address(0));
	pBuf->cachedaddr = 0;
	pBuf->isCache = 0;
	pBuf->fromPoll = 0;
	pBuf->virAddr = pBuf->nonCachedaddr;

	if (pCh->isInit)
		IOCTLEX_ResetRefClock(pCh);

	return 1;
}
int DEMUX_BUF_SetupPSIBuffer(demux_channel *pCh, unsigned long phyAddr, int size)
{
	DEMUX_BUF_T *pBuf;
	RINGBUFFER_HEADER *pBufHeader;

	/* set up PSI buffer */
	if (phyAddr == 0 || size == 0)
		return -1;


	pBuf = &pCh->psiBufferH;
	if (pBuf->virAddr) {
		if (pCh->state == DEMUX_STATE_STOP)
			DEMUX_BUF_ReturnPSIBuffer(pCh);
		else
			BUG();
	}
	/* setup buffer header */
	pBuf->size = size;
	pBuf->allocSize = 0; /* it means memory is from user space. */
	pBuf->phyAddr = phyAddr;
	pBuf->cachedaddr = 0;
	pBuf->nonCachedaddr = dvr_remap_uncached_memory(pBuf->phyAddr, pBuf->size, __builtin_return_address(0));
	pBuf->isCache = 0;
	pBuf->fromPoll = 0;
	pBuf->virAddr = pBuf->nonCachedaddr;
	dmx_crit("[%s %d]CH%d setup PSI buf header = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
	pBufHeader = (RINGBUFFER_HEADER *)pBuf->virAddr;

	/* setup psi buffer */
	pBuf = &pCh->psiBuffer;
	pBuf->size = pBufHeader->size;
	pBuf->allocSize = 0; /* it means memory is from user space. */
	pBuf->phyAddr = pBufHeader->beginAddr;
	pBuf->cachedaddr = dvr_remap_cached_memory(pBuf->phyAddr, pBuf->size, __builtin_return_address(0));
	pBuf->nonCachedaddr = 0;
	pBuf->isCache = 1;
	pBuf->fromPoll = 0;
	pBuf->virAddr = pBuf->cachedaddr;

	dmx_crit("[%s %d]CH%d setup psi buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
	return 0;
}
int DEMUX_BUF_ReturnRefClockBuffer(demux_channel *pCh)
{
	DEMUX_BUF_T *pBuf;
	pBuf = &pCh->refClockBuffer;

	dmx_notice("[%s %d]CH%d return reference clock = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
	if (pBuf->phyAddr && !pCh->bUseSelfBuf) {
		dvr_unmap_memory(pBuf->isCache ? (void *)pBuf->cachedaddr : (void *)pBuf->nonCachedaddr, pBuf->size);
		DEMUX_BUF_ZeroOutBuffer(pBuf);
	}

	return 1;
}
int DEMUX_BUF_ReturnPSIBuffer(demux_channel *pCh)
{
	DEMUX_BUF_T *pBuf;
	pBuf = &pCh->psiBuffer;

	dmx_crit("[%s %d]CH%d return PSI buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
	if (pBuf->phyAddr) {
		dvr_unmap_memory(pBuf->isCache ? (void *)pBuf->cachedaddr : (void *)pBuf->nonCachedaddr, pBuf->size);
		DEMUX_BUF_ZeroOutBuffer(pBuf);
	}

	pBuf = &pCh->psiBufferH;
	dmx_crit("[%s %d]CH%d return PSI buf Header = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBuf->phyAddr);
	if (pBuf->phyAddr) {
		dvr_unmap_memory(pBuf->isCache ? (void *)pBuf->cachedaddr : (void *)pBuf->nonCachedaddr, pBuf->size);
		DEMUX_BUF_ZeroOutBuffer(pBuf);
	}

	return 1;
}

int DEMUX_BUF_SetupDecBuffer(demux_channel *pCh, int pin, unsigned long bsPhyAddr, int bsSize, unsigned long ibPhyAddr, int ibSize)
{
	RINGBUFFER_HEADER *pBufHeader = 0;
	DEMUX_BUF_T *pBufBS, *pBufIB, *pBufBSH, *pBufIBH;

	if (bsPhyAddr == 0 || bsSize == 0) {
		dmx_crit("[%s %d] bsPhyAddr is %ld, bsSize = %d\n", __func__, __LINE__, bsPhyAddr, bsSize);
		return -1;
	}
	if (pin >= NUMBER_OF_PINS)
		return -1;
	pBufBSH = &pCh->bsDecBufH[pin];
	pBufBS = &pCh->bsDecBuf[pin];
	pBufIBH = &pCh->ibDecBufH[pin];
	pBufIB = &pCh->ibDecBuf[pin];

	if (pBufBSH->virAddr && pCh->pinInfo[pin].bufStatus == BUF_STAT_FREE) {
		if (pCh->state == DEMUX_STATE_STOP)
			DEMUX_BUF_ReturnDecBuffer(pCh, pin);
		else if (wait_event_timeout(pCh->bufStatusWQ, (pCh->pinInfo[pin].bufStatus == BUF_STAT_DONE), WAIT_TO_BE_DONE_TIMEOUT) == 0) {
			/* timeout occurs and condition is false */
			dmx_crit("[%s %d] timeout to free buffer. bufStatus = %d\n", __func__, __LINE__, pCh->pinInfo[pin].bufStatus);
			return -1;
		}
	}

	/* setup bs buffer header */
	pBufBSH->size = bsSize;
	pBufBSH->allocSize = 0; /* it means memory is from user space. */
	pBufBSH->phyAddr = bsPhyAddr;
	pBufBSH->cachedaddr = 0;
	pBufBSH->nonCachedaddr = dvr_remap_uncached_memory(pBufBSH->phyAddr, pBufBSH->size, __builtin_return_address(0));
	pBufBSH->isCache = 0;
	pBufBSH->fromPoll = 0;
	pBufBSH->virAddr = pBufBSH->nonCachedaddr;
	pBufHeader = (RINGBUFFER_HEADER *)pBufBSH->virAddr;
	dmx_crit("[%s %d]CH%d setup pin(%d) BS buf header = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufBSH->phyAddr);


	/* setup bs buffer */
	pBufBS->size = DEMUX_reverseInteger(pBufHeader->size);
	pBufBS->allocSize = 0; /* it means memory is from user space. */
	pBufBS->phyAddr = DEMUX_reverseInteger(pBufHeader->beginAddr);
	pBufBS->cachedaddr = dvr_remap_cached_memory(pBufBS->phyAddr, pBufBS->size, __builtin_return_address(0));
	pBufBS->nonCachedaddr = 0;
	pBufBS->isCache = 1;
	pBufBS->fromPoll = 0;
	pBufBS->virAddr = pBufBS->cachedaddr;
	dmx_crit("[%s %d]CH%d setup pin(%d) BS buf = 0x%x, size = %d\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufBS->phyAddr, pBufBS->size);
	DEMUX_BUF_ResetRBHeader(pBufBSH, pBufBS, RINGBUFFER_STREAM,  1);

	if (ibPhyAddr && ibSize) {
		/* setup ib buffer header */
		pBufIBH->size = ibSize;
		pBufIBH->allocSize = 0; /* it means memory is from user space. */
		pBufIBH->phyAddr = ibPhyAddr;
		pBufIBH->cachedaddr = 0;
		pBufIBH->nonCachedaddr = dvr_remap_uncached_memory(pBufIBH->phyAddr, pBufIBH->size, __builtin_return_address(0));
		pBufIBH->isCache = 0;
		pBufIBH->fromPoll = 0;
		pBufIBH->virAddr = pBufIBH->nonCachedaddr;
		pBufHeader = (RINGBUFFER_HEADER *)pBufIBH->virAddr;
		dmx_crit("[%s %d]CH%d setup pin(%d) IB buf header = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufIBH->phyAddr);


		/* setup ib buffer */
		pBufIB->size = DEMUX_reverseInteger(pBufHeader->size);
		pBufIB->allocSize = 0; /* it means memory is from user space. */
		pBufIB->phyAddr = DEMUX_reverseInteger(pBufHeader->beginAddr);
		pBufIB->nonCachedaddr = dvr_remap_uncached_memory(pBufIB->phyAddr, pBufIB->size, __builtin_return_address(0));
		pBufIB->cachedaddr = 0;
		pBufIB->isCache = 0;
		pBufIB->fromPoll = 0;
		pBufIB->virAddr = pBufIB->nonCachedaddr;
		dmx_crit("[%s %d]CH%d setup pin(%d) IB buf = 0x%x, size = %d\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufIB->phyAddr, pBufIB->size);

		DEMUX_BUF_ResetRBHeader(pBufIBH, pBufIB, RINGBUFFER_COMMAND, 1);
	}

	pCh->pinInfo[pin].bufStatus = BUF_STAT_NEW;
	if (pCh->state == DEMUX_STATE_STOP) /* demux thread is not running */
		DEMUX_BUF_UpdatePinInfo(pCh);
	else {
		mutex_lock(&pCh->mutex);
		SET_FLAG(pCh->events, EVENT_SET_PIN_INFO);
		mutex_unlock(&pCh->mutex);
	}
	return 0;
}

int DEMUX_BUF_ReturnDecBuffer(demux_channel *pCh, int pin)
{
	DEMUX_BUF_T *pBufBS, *pBufIB, *pBufBSH, *pBufIBH;

	if (pin >= NUMBER_OF_PINS)
		return -1;

	pBufBSH = &pCh->bsDecBufH[pin];
	pBufBS = &pCh->bsDecBuf[pin];
	pBufIBH = &pCh->ibDecBufH[pin];
	pBufIB = &pCh->ibDecBuf[pin];
	/* unmap bs buffer */

	if (pBufBS->phyAddr) {
		dmx_crit("[%s %d]CH%d return pin %d BS buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufBS->phyAddr);
		if (pCh->bUseSelfBuf) {
			if (pBufBS->allocSize == 0) {
				dmx_crit("[%s %d]CH%d return SVP buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pBufBS->phyAddr);
				if (pBufBS->phyAddr) {
					rtkvdec_cobuffer_free(VDEC_SVP_BUF, pBufBS->phyAddr);
					dvr_unmap_memory(pBufBS->isCache ? (void *)pBufBS->cachedaddr : (void *)pBufBS->nonCachedaddr, pBufBS->size);
				}
			}
			else
				dvr_free(pBufBS->cachedaddr);
		}
		else {
			dvr_unmap_memory(pBufBS->isCache ? (void *)pBufBS->cachedaddr : (void *)pBufBS->nonCachedaddr, pBufBS->size);
		}
		DEMUX_BUF_ZeroOutBuffer(pBufBS);
	}

	/* unmap bs buffer header */
	if (pBufBSH->phyAddr && !pCh->bUseSelfBuf) {
		dmx_crit("[%s %d]CH%d return pin %d BS buf header = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufBSH->phyAddr);
		dvr_unmap_memory(pBufBSH->isCache ? (void *)pBufBSH->cachedaddr : (void *)pBufBSH->nonCachedaddr, pBufBSH->size);
		DEMUX_BUF_ZeroOutBuffer(pBufBSH);
	}

	/* unmap ib buffer */
	if (pBufIB->phyAddr) {
		dmx_crit("[%s %d]CH%d return pin %d IB buf = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufIB->phyAddr);
		if (pCh->bUseSelfBuf)
			dvr_free(pBufIB->cachedaddr);
		else
			dvr_unmap_memory(pBufIB->isCache ? (void *)pBufIB->cachedaddr : (void *)pBufIB->nonCachedaddr, pBufIB->size);
		DEMUX_BUF_ZeroOutBuffer(pBufIB);
	}

	/* unmap ib buffer header */

	if (pBufIBH->phyAddr && !pCh->bUseSelfBuf) {
		dmx_crit("[%s %d]CH%d return pin %d IB buf header = 0x%x\n", __func__, __LINE__, pCh->tunerHandle, pin, pBufIBH->phyAddr);
		dvr_unmap_memory(pBufIBH->isCache ? (void *)pBufIBH->cachedaddr : (void *)pBufIBH->nonCachedaddr, pBufIBH->size);
		DEMUX_BUF_ZeroOutBuffer(pBufIBH);
	}

	return 0;
}

void DEMUX_BUF_UpdatePinInfo(demux_channel *pCh)
{
	int i, port = 0;
	DEMUX_BUF_PIN_T *pPinInfo, *pPinIBInfo;
	DEMUX_BUF_T *pBufBS, *pBufIB, *pBufBSH, *pBufIBH;

	for (i = VIDEO_PIN; i < NUMBER_OF_PINS; i++) {

		pBufBSH = &pCh->bsDecBufH[i];
		pBufBS = &pCh->bsDecBuf[i];
		pBufIBH = &pCh->ibDecBufH[i];
		pBufIB = &pCh->ibDecBuf[i];

		pPinInfo   = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_BS];
		pPinIBInfo = &pCh->pinInfo[i].bufInfo[DEMUX_STREAM_TYPE_IB];
		if (pCh->pinInfo[i].bufStatus == BUF_STAT_FREE) {
			DEMUX_BUF_ReturnDecBuffer(pCh, i);
			memset(pPinIBInfo, 0, sizeof(DEMUX_BUF_PIN_T));
			memset(pPinInfo, 0, sizeof(DEMUX_BUF_PIN_T));

			dmx_notice("[%s %d]reset CH%d pin = %d, port = %d\n", __func__, __LINE__, pCh->tunerHandle, i, port);
			pCh->pinInfo[i].bufStatus = BUF_STAT_DONE;
		} else if (pCh->pinInfo[i].bufStatus == BUF_STAT_NEW) {
			RINGBUFFER_HEADER *pHeader = 0;

			IOCTL_SetPinInfo(pPinIBInfo, (RINGBUFFER_HEADER *)pBufIBH->virAddr, pBufIB);
			IOCTL_SetPinInfo(pPinInfo, (RINGBUFFER_HEADER *)pBufBSH->virAddr, pBufBS);
			dmx_notice("[%s %d]set CH%d pin = %d\n", __func__, __LINE__, pCh->tunerHandle, i);

			pHeader = (RINGBUFFER_HEADER *)pBufBSH->virAddr;
			dmx_notice("[%s %d]BS rp=0x%lx, wp = 0x%lx, base = 0x%lx\n", __func__, __LINE__, (unsigned long)pHeader->readPtr[0], (unsigned long)pHeader->writePtr, (unsigned long)pHeader->beginAddr);

			pCh->pinInfo[i].bufStatus = BUF_STAT_DONE;
		}

	}
	wake_up(&pCh->bufStatusWQ);
}
int DEMUX_BUF_PrepareSelfRefClockBuf(demux_channel *pCh)
{
	DEMUX_BUF_T *pBuf = &pCh->refClockBuffer;

	if (pBuf->virAddrFromPoll)
		DEMUX_BUF_RestoreFromPoll(pBuf);
	else if (DEMUX_BUF_AllocFromPoll(pBuf, DEMUX_REFCLK_BUFF_SIZE, &demux_device->bufPoll, 0) < 0) {
		dmx_crit("[%s %d] fail allocate reference clock\n", __func__, __LINE__);
		return -1;
	}

	if (pCh->isInit)
		IOCTLEX_ResetRefClock(pCh);

	return 0;
}

#define WITH_SVP

int DEMUX_BUF_PrepareSelfDecBuf(demux_channel *pCh, int pin, int bsSize, int ibSize)
{
	DEMUX_BUF_T *pBufBS, *pBufIB;
	DEMUX_BUF_T *pBufBSH, *pBufIBH;

	pBufBS = &pCh->bsDecBuf[pin];
	pBufIB = &pCh->ibDecBuf[pin];
	pBufBSH = &pCh->bsDecBufH[pin];
	pBufIBH = &pCh->ibDecBufH[pin];

	/* cannot check buffer header because buffer header can be reused */
	if (pBufBS->phyAddr)
		return 0;

	if (pBufBSH->virAddr == 0) {
		if (pBufBSH->virAddrFromPoll)
			DEMUX_BUF_RestoreFromPoll(pBufBSH);
		else if (DEMUX_BUF_AllocFromPoll(pBufBSH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
			dmx_crit("[%s %d]CH%d out of memory: allocate buffer header fail\n", __func__, __LINE__, pCh->tunerHandle);
			return -1;
		}
	}

	if(pBufBS->virAddr == 0) {
#ifdef WITH_SVP
        int64_t startTime = 0;
        int retryCnt = 0;
        int port = -1;

		if(pin==VIDEO_PIN || pin==VIDEO2_PIN) {
			if (pin == VIDEO_PIN) 
				port = 0;
			else if (pin == VIDEO2_PIN)
				port = 1;

			startTime = CLOCK_GetPTS();
			/* In case fail to borrow SVP buffer, maybe GStreamer release it soon. 
		         * Therefore, retry at most 10 times.
			 */
			while (pBufBS->phyAddr == 0 && retryCnt < 10)  {
				pBufBS->phyAddr = rtkvdec_cobuffer_alloc(VDEC_SVP_BUF, port);
				retryCnt++;
			}
			dmx_crit("[%s %d]CH%d it takes %lld(ticks) to borrow SVP[%d] buffer(0x%x)\n", __func__, __LINE__, pCh->tunerHandle, CLOCK_GetPTS()-startTime, port, pBufBS->phyAddr);
		}
#endif
		if (pBufBS->phyAddr == 0) {
			if (DEMUX_BUF_AllocBuffer(pBufBS, bsSize, 1, 1) < 0) {
				dmx_crit("[%s %d]CH%d out of memory: allocate bs buffer fail. bsSize = %d\n", __func__, __LINE__, pCh->tunerHandle, bsSize);
				return -1;
			}
		}
		else
		{
			pBufBS->size = bsSize;
			pBufBS->allocSize = 0; //it means memory is from SVP.
			pBufBS->cachedaddr = dvr_remap_cached_memory(pBufBS->phyAddr, pBufBS->size, __builtin_return_address(0));
			pBufBS->nonCachedaddr = 0;
			pBufBS->isCache = 1;
			pBufBS->virAddr = pBufBS->cachedaddr;
			pBufBS->fromPoll = 0;
		}
	}

	DEMUX_BUF_ResetRBHeader(pBufBSH, pBufBS, RINGBUFFER_STREAM,  1);

	if (ibSize > 0) {
		if (pBufIBH->virAddr == 0) {
			if (pBufIBH->virAddrFromPoll)
				DEMUX_BUF_RestoreFromPoll(pBufIBH);
			else if (DEMUX_BUF_AllocFromPoll(pBufIBH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
				dmx_crit("[%s %d]CH%d out of memory: allocate buffer header fail\n", __func__, __LINE__, pCh->tunerHandle);
				return -1;
			}
		}
		if (pBufIB->virAddr == 0 && DEMUX_BUF_AllocBuffer(pBufIB, ibSize, 0, 1) < 0) {
			dmx_crit("[%s %d]CH%d out of memory: allocate ib buffer fail. ibSize = %d\n", __func__, __LINE__, pCh->tunerHandle, ibSize);
			DEMUX_BUF_FreeBuffer(pBufBS);
			return -1;
		}
		DEMUX_BUF_ResetRBHeader(pBufIBH, pBufIB, RINGBUFFER_COMMAND, 1);
	}

	pCh->pinInfo[pin].bufStatus = BUF_STAT_NEW;
	if (pCh->state == DEMUX_STATE_STOP) /* demux thread is not running */
		DEMUX_BUF_UpdatePinInfo(pCh);
	else {
		mutex_lock(&pCh->mutex);
		SET_FLAG(pCh->events, EVENT_SET_PIN_INFO);
		mutex_unlock(&pCh->mutex);
	}

	return 0;
}
void DEMUX_BUF_RestoreFromPoll(DEMUX_BUF_T *pBuf)
{
	pBuf->phyAddr = pBuf->phyAddrFromPoll;
	pBuf->virAddr = pBuf->virAddrFromPoll;
	pBuf->cachedaddr = 0;
	pBuf->nonCachedaddr = pBuf->virAddr;
	pBuf->isCache = 0;
	pBuf->fromPoll = 1;
	pBuf->size = sizeof(RINGBUFFER_HEADER);
	pBuf->allocSize = (pBuf->size + 0xf) & ~0xf ; /*size < 0x1000 ? 0x1000 : size ;*/
}
void DEMUX_BUF_ZeroOutBuffer(DEMUX_BUF_T *pBuf)
{
	//cannot reset virAddrFromPoll/phyAddrFromPoll
	pBuf->phyAddr       = 0;
	pBuf->cachedaddr    = 0;
	pBuf->nonCachedaddr = 0;
	pBuf->virAddr       = 0;
	pBuf->isCache       = 0;
	pBuf->fromPoll      = 0;
	pBuf->size          = 0;
}
//########################################################## PES BUFFER ##################################################

int DEMUX_PESBuffer_Alloc(DEMUX_PES_MAP_T *pMap, int size)
{
	RINGBUFFER_HEADER *pRBH = NULL;
	size = size & (~0xFFF);    /* align to 4K */

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
	if (DEMUX_BUF_AllocBuffer(&(pMap->pesFilterBuffer), size, 1, 0) < 0){
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
	pRBH->size         = size;
	pRBH->writePtr     = pRBH->beginAddr;
	pRBH->numOfReadPtr = 1;
	pRBH->readPtr[0]   = pRBH->beginAddr;

	pMap->pWrPtr        = (u32 *)&pRBH->writePtr;
	pMap->pRdPtr        = (u32 *)&pRBH->readPtr[0];
	pMap->pBufferLower  = (unsigned char *)pRBH->beginAddr;
	pMap->pBufferUpper  = (unsigned char *)(pMap->pBufferLower + size);
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
				dmx_mask_print(DEMUX_PES_DEBUG,"updatebufferstatus reset pes buffer :ch:%d, pesid:%d, phyAddr:%lx \n", pCh->tunerHandle, index, (unsigned long)pRBH->beginAddr);
			}
			pMap->bufferStatus = BUFFER_ONLINE;
		}
	}
}
int DEMUX_BUF_APvrBuffer_Alloc(int size)
{
	if (size <= 0)
		return -1;

	if (demux_device->APvrTsBuf.allocSize == 0) {
		if (DEMUX_BUF_AllocBuffer(&demux_device->APvrTsBuf, size, 1, 0) < 0) {
			dmx_crit("[%s %d] fail to allocate Apvr TS buffer\n",
				__func__, __LINE__);
			return -1;
		}
	}

	return 0;
}
int DEMUX_BUF_GIFOBuffer_Alloc(DEMUX_CHANNEL_T ch, int size)
{
	demux_channel *pCh;

	dmx_function_call();
	DEMUX_CHECK_CH(ch);

	if (size <= 0)
		return -1;

	pCh = &demux_device->pChArray[ch];
	if (pCh->GIFOBuf.allocSize == 0) {
		if (DEMUX_BUF_AllocBuffer(&pCh->GIFOBuf, size, 1, 0) < 0) {
			dmx_err("[%s %d] fail to allocate GIFO buffer\n",
				__func__, __LINE__);
			return -1;
		}
	}

	return 0;
}

int DEMUX_BUF_AllocTPBuffer(demux_channel * pCh)
{
	DEMUX_BUF_T *pBuf = &pCh->tpBuffer;
	unsigned int phyAddr = 0;
	if (pCh  == NULL){
		dmx_err("%s_%d: invalid param\n!!!!!", __func__, __LINE__);
		goto ALLOCATE_FAIL;
	}
	if (pCh->bIsSDT) {
		if (DEMUX_BUF_AllocBuffer(&pCh->tpBuffer, SDT_CH_BUFF_SIZE, 0, 0) < 0)
		{
			dmx_err("%s_%d: ch:%d DEMUX_BUF_AllocBuffer\n!!!!!", __func__, __LINE__,pCh->tunerHandle );
			goto ALLOCATE_FAIL;
		}
		goto ALLOCATE_SUCCESS;
	}
	if(TP_TP2 == pCh->tunerHandle){
		if (DEMUX_BUF_AllocBuffer(&pCh->tpBuffer, DEMUX_TP2_BUFF_SIZE, 0, 0) < 0)
		{
			dmx_err("%s_%d: ch:%d DEMUX_BUF_AllocBuffer\n!!!!!", __func__, __LINE__,pCh->tunerHandle );
			goto ALLOCATE_FAIL;
		}
		goto ALLOCATE_SUCCESS;
	}

#ifdef USE_STATIC_RESERVED_BUF
	{
		unsigned int totalSize = 0;
		unsigned int startPhyAddr = 0;
		totalSize = carvedout_buf_query(CARVEDOUT_TP, (void**)&startPhyAddr);
		dmx_info("startPhyAddr:0x%x chNum:%d totalSize:%d size:%d\n",startPhyAddr,pCh->tunerHandle,totalSize,DEMUX_TP_BUFF_SIZE);
		if (totalSize > 0) {
			phyAddr = startPhyAddr + pCh->tunerHandle * DEMUX_TP_BUFF_SIZE;
			if ((phyAddr+DEMUX_TP_BUFF_SIZE) <= (startPhyAddr + totalSize)) {
				dmx_info("Using Reserved Buffer phyAddr: 0x%x\n",phyAddr);
				pBuf->phyAddr = phyAddr;
				pBuf->allocSize = DEMUX_TP_BUFF_SIZE < 0x1000 ? 0x1000 : DEMUX_TP_BUFF_SIZE ;
				pBuf->cachedaddr = dvr_remap_cached_memory(pBuf->phyAddr, pBuf->allocSize, __builtin_return_address(0));
				pBuf->nonCachedaddr = dvr_remap_uncached_memory(pBuf->phyAddr, pBuf->allocSize, __builtin_return_address(0));
				pBuf->isCache = 0;
				pBuf->virAddr = pBuf->isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr ;
				pBuf->size = DEMUX_TP_BUFF_SIZE ;
				pBuf->fromPoll = 0 ;
				pBuf->fromVBM = 0;
	
				dmx_notice("[%s]TP[%d] cachedAddr 0x%lx, uncachedAddr 0x%lx, phyAddr 0x%x, allocSize 0x%x\n",
					__func__, pCh->tunerHandle, (unsigned long)(uintptr_t)pBuf->cachedaddr,
					(unsigned long)(uintptr_t)pBuf->nonCachedaddr,	pBuf->phyAddr, pBuf->allocSize);
				goto ALLOCATE_SUCCESS;
			} else {
				dmx_warn("%s_%d: ch:%d carvedout TP buffer allocate FAIL \n!!!!!", __func__, __LINE__,pCh->tunerHandle );

			}
		} else {
			dmx_warn("%s_%d: ch:%d carvedout TP buffer allocate FAIL \n!!!!!", __func__, __LINE__,pCh->tunerHandle );

		}
	}

#endif
#ifdef TP_BUFFER_FROM_VBM
	{
		DEMUX_BUF_T rpcBuf;
		if( DEMUX_BUF_AllocBuffer(&rpcBuf, sizeof(VIDEO_RPC_VBM_BORROWMEMCHUNK), 0, 1) == 0 && rpcBuf.virAddr) {
			unsigned long result;
			int send_rpc_ret = 0;
			VIDEO_RPC_VBM_BORROWMEMCHUNK* cmd = (VIDEO_RPC_VBM_BORROWMEMCHUNK*)rpcBuf.virAddr;
			memset((void *)cmd, 0, sizeof(VIDEO_RPC_VBM_BORROWMEMCHUNK));
			cmd->memChunkAddr = 0;
			cmd->memChunkSize = 0;
			cmd->reqSize = DEMUX_reverseInteger(DEMUX_TP_BUFF_SIZE);
			send_rpc_ret = send_rpc_command(RPC_VIDEO, VIDEO_RPC_ToAgent_BorrowVBMMemChunk, rpcBuf.phyAddr, rpcBuf.size, &result);
			if (send_rpc_ret == RPC_OK) {
				phyAddr = DEMUX_reverseInteger(cmd->memChunkAddr);
				totalSize = DEMUX_reverseInteger(cmd->memChunkSize);
				pBuf->phyAddr = phyAddr;
				pBuf->allocSize = totalSize;;
				pBuf->cachedaddr = dvr_remap_cached_memory(phyAddr, totalSize, __builtin_return_address(0));
				pBuf->nonCachedaddr = dvr_remap_uncached_memory(phyAddr, totalSize, __builtin_return_address(0));
				pBuf->isCache = 0;
				pBuf->virAddr = pBuf->isCache ? pBuf->cachedaddr : pBuf->nonCachedaddr;
				pBuf->size = DEMUX_TP_BUFF_SIZE ;
				pBuf->fromPoll = 0;
				pBuf->fromVBM = 1;
	
				DEMUX_BUF_FreeBuffer(&rpcBuf);
				dmx_info("[%s %d]CH[%d] borrow from VBM: addr 0x%x, cached %p, nonCached %p, size %d\n",
					__func__, __LINE__, chNum, phyAddr, pBuf->cachedaddr, pBuf->nonCachedaddr, totalSize);
				goto ALLOCATE_SUCCESS;
			} else {
				DEMUX_BUF_FreeBuffer(&rpcBuf);
				dmx_err("%s_%d: ch:%d VBM TP buffer allocate FAIL \n!!!!!", __func__, __LINE__,pCh->tunerHandle );
				goto ALLOCATE_FAIL;
			}
		} else {
			dmx_err("%s_%d: ch:%d VBM TP buffer allocate FAIL \n!!!!!", __func__, __LINE__,pCh->tunerHandle );
			goto ALLOCATE_FAIL;

		}
	}

#endif
	{
		if (DEMUX_BUF_AllocBuffer(pBuf, DEMUX_TP_BUFF_SIZE, 0, 0) < 0)
		{
			dmx_err("%s_%d: ch:%d DEMUX_BUF_AllocBuffer\n!!!!!", __func__, __LINE__,pCh->tunerHandle );
			goto ALLOCATE_FAIL;
		}
	}

ALLOCATE_SUCCESS:

	pCh->phyAddrOffset = (long)pCh->tpBuffer.phyAddr - (long)pCh->tpBuffer.virAddr;
	// tp header init
	if (pCh->tpBufferH.virAddrFromPoll) {
		DEMUX_BUF_RestoreFromPoll(&pCh->tpBufferH);
	} else {
		if (DEMUX_BUF_AllocFromPoll(&pCh->tpBufferH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0)
		{
			dmx_err("%s_%d: ch:%d DEMUX_BUF_AllocFromPoll tpBufferH FAIL\n!!!!!", __func__, __LINE__,pCh->tunerHandle );
			goto ALLOCATE_FAIL;
		}
	}
	return 0;
ALLOCATE_FAIL:
	return -1;

}

int DEMUX_BUF_FreeTPBuffer(demux_channel * pCh)
{
	DEMUX_BUF_T *pBuf = &pCh->tpBuffer;
	unsigned int tp_buf_start = 0;
	unsigned int tp_buf_size  = 0;
	if (pCh  == NULL){
		dmx_err("%s_%d: invalid param\n!!!!!", __func__, __LINE__);
		goto FREE_FAIL;
	}
#ifdef USE_STATIC_RESERVED_BUF
	tp_buf_size = carvedout_buf_query(CARVEDOUT_TP, (void**)&tp_buf_start);
	if (pBuf->phyAddr >= tp_buf_start && (pBuf->phyAddr+pBuf->allocSize) <= (tp_buf_start + tp_buf_size)) {
		dvr_unmap_memory((void *)pBuf->cachedaddr, pBuf->allocSize);
		dvr_unmap_memory((void *)pBuf->nonCachedaddr, pBuf->allocSize);
		dmx_info("[%s %d] CH[%d] return carved-out buffer\n", __func__, __LINE__, pCh->tunerHandle);
		memset(pBuf, 0, sizeof(DEMUX_BUF_T));
		goto FREE_OK;
	}
#endif
#ifdef TP_BUFFER_FROM_VBM
	if (pBuf->fromVBM) {
		DEMUX_BUF_T rpcBuf;
		if( DEMUX_BUF_AllocBuffer(&rpcBuf, sizeof(VIDEO_RPC_VBM_RETURNMEMCHUNK), 0, 1) == 0 && rpcBuf.virAddr) {
			unsigned long result;
			VIDEO_RPC_VBM_RETURNMEMCHUNK* cmd = (VIDEO_RPC_VBM_RETURNMEMCHUNK*)rpcBuf.virAddr;
			memset((void *)cmd, 0, sizeof(VIDEO_RPC_VBM_RETURNMEMCHUNK));
			cmd->memChunkAddr = DEMUX_reverseInteger(pBuf->phyAddr);
			cmd->memChunkSize = DEMUX_reverseInteger(pBuf->allocSize);
			send_rpc_command(RPC_VIDEO, VIDEO_RPC_ToAgent_ReturnVBMMemChunk, rpcBuf.phyAddr, rpcBuf.size, &result);
			dvr_unmap_memory((void *)pBuf->cachedaddr, pBuf->allocSize);
			dvr_unmap_memory((void *)pBuf->nonCachedaddr, pBuf->allocSize);
			dmx_info("[%s %d] CH[%d] return VBM buffer\n",  __func__, __LINE__, pCh->tunerHandle);
			DEMUX_BUF_FreeBuffer(&rpcBuf);
			goto FREE_OK;
		} else {
			dmx_err("%s_%d: ch:%dFAIL DEMUX_BUF_FreeTPBuffer \n!!!!", __func__, __LINE__, pCh->tunerHandle);
			goto FREE_FAIL;
		}
	}
#endif
	DEMUX_BUF_FreeBuffer(pBuf);

FREE_OK:
	if (pCh->tpBufferH.fromPoll == 1) {
		if (pCh->tpBufferH.phyAddrFromPoll == 0 && pCh->tpBufferH.phyAddr) {
			pCh->tpBufferH.phyAddrFromPoll = pCh->tpBufferH.phyAddr;
			pCh->tpBufferH.virAddrFromPoll = pCh->tpBufferH.virAddr;
		}
	}
	DEMUX_BUF_ZeroOutBuffer(&pCh->tpBufferH);
	return 0;

FREE_FAIL:
	return -1;
}
int DEMUX_BUF_ConfigTPBuffer(demux_channel * pCh)
{
	SINT32 tpAlignment, tpBufAlignment, mtpAlignment;
	TPK_TP_STATUS_T tpStatus;
	int tpBufSize, tpDataSize;
	UINT8 mtp_id;
	int32_t ret = -1;
	if (pCh ==  NULL)
	{
		dmx_err("%s_%d: invalid param!!!!\n", __func__, __LINE__);
		return -1;
	}

	if (RHAL_GetTpStatus(pCh->tunerHandle, &tpStatus) != TPK_SUCCESS){
		dmx_err("%s_%d: RHAL_GetTpStatus FAIL !!!!\n", __func__, __LINE__);
		return -1;
	}

	mtp_id = DEMUX_GET_MTP_ID(pCh->tunerHandle);

	tpAlignment    = tpStatus.tp_param.prefix_en ? 192 : 188;
	pCh->tsPacketSize  = tpAlignment;
	mtpAlignment   = 1024*((tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192 : 188);
	if (pCh->bIsSDT)
		tpBufAlignment = tpAlignment;
	else
		tpBufAlignment = tpAlignment* 1024*2;
	ret = RHAL_GetTPBufferStatus(pCh->tunerHandle, &tpBufSize, &tpDataSize) ;
	if ((ret != TPK_SUCCESS)  && (ret != TPK_NOT_INIT)) {
		dmx_err("[%s %d] FAIL RHAL_GetTPBufferStatus!!!!! \n", __func__, __LINE__);
		return -1;
	}
	/* buffer is packet-aligned. */
	if (((pCh->tpBuffer.size % tpBufAlignment) == 0) && (tpBufSize == pCh->tpBuffer.size)) {
		if (tpStatus.tp_src != MTP){
			dmx_crit("[%s %d] FAIL RHAL_GetTPBufferStatus!!!!! \n", __func__, __LINE__);
			return 0;
		}

	}
	/* if tp starts streaming already, stop it. */
	if (tpStatus.tp_stream_status == TP_STREAM_START)
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_STOP);
	
	
	if ((pCh->tpBuffer.size % tpBufAlignment) || (pCh->tpBuffer.size != tpBufSize)) {
		RINGBUFFER_HEADER *pHeader    = (RINGBUFFER_HEADER *)pCh->tpBufferH.virAddr;
		DEMUX_BUF_T       *pBuf       = &pCh->tpBuffer;

		pBuf->size = pBuf->size - (pBuf->size % tpBufAlignment);
		RHAL_SetTPRingBuffer(pCh->tunerHandle, (UINT8 *)pBuf->phyAddr, (UINT8 *)pBuf->nonCachedaddr, pBuf->size);

		tpBufSize = 0;
		tpDataSize = 0;
		if (RHAL_GetTPBufferStatus(pCh->tunerHandle, &tpBufSize, &tpDataSize) == TPK_SUCCESS && tpBufSize != pBuf->size) {
			dmx_crit("[%s %d] buf size not matched: tpBufSize = %d, org = %d\n", __func__, __LINE__, tpBufSize,  pBuf->size);
			pBuf->size = tpBufSize;
		}

		//pHeader->size             = pBuf->size;
		//pHeader->beginAddr        = pBuf->phyAddr;
		//pHeader->writePtr         = pBuf->phyAddr;
		//pHeader->readPtr[0]       = pBuf->phyAddr;
		//pHeader->readPtr[1]       = pBuf->phyAddr;

		DEMUX_BUF_ResetRBHeader(&pCh->tpBufferH, &pCh->tpBuffer, RINGBUFFER_STREAM, 0);
		dmx_info("[%s %d] TP readPtr[0] = 0x%lx, readPtr[1] = 0x%lx, writePtr = 0x%lx\n",
			__func__, __LINE__, (unsigned long)pHeader->readPtr[0], (unsigned long)pHeader->readPtr[1], (unsigned long)pHeader->writePtr);
		if (RHAL_DumpTPRingBuffer(pCh->tunerHandle, pCh->bStartRec, (UINT8 *)&pHeader->readPtr[0], (UINT8 *)&pHeader->writePtr) != TPK_SUCCESS)
			return -1;


	}
	else{
		dmx_err("%s_%d: TPBuffer config DO NOTHING : size:%d, bufferAligment:%d\n", __func__, __LINE__, pCh->tpBuffer.size, tpBufAlignment);
	}

	if (tpStatus.tp_src == MTP && pCh->mtpBuffer.allocSize > 0) {
		if ( pCh->mtpUploadUnitSize){
			if ((pCh->mtpUploadUnitSize) %((tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192 : 188) != 0 ){
				dmx_err("%s_%d: ch:%d, uploadUnitSize(%d) is not sync with timeStamp(%d)\n",
					__func__, __LINE__, pCh->tunerHandle, pCh->mtpUploadUnitSize,((tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192 : 188));
				return -1;
			}
			mtpAlignment   = pCh->mtpUploadUnitSize;
		}
		pCh->mtpBuffer.size = pCh->mtpBuffer.size - (pCh->mtpBuffer.size % (mtpAlignment)) - mtpAlignment; /*reserve one 192k to handle wrap-around*/
		RHAL_SetMTPBuffer(mtp_id, (UINT8 *)pCh->mtpBuffer.phyAddr, (UINT8 *)pCh->mtpBuffer.virAddr, pCh->mtpBuffer.size);
		dmx_crit("[%s %d] mtpBuffer(phyAddr:0x%x, virAddr:%p,Size: %d), timeStamp:%d, uploadUnitSize:%d \n",
			__func__, __LINE__, pCh->mtpBuffer.phyAddr, pCh->mtpBuffer.virAddr, pCh->mtpBuffer.size, ((tpStatus.tp_param.ts_in_tsp_len == byte_192) ? 192 : 188) ,mtpAlignment);
	}
	/* re-start tp if necessary */
	if (tpStatus.tp_stream_status == TP_STREAM_START)
		RHAL_TPStreamControl(pCh->tunerHandle, TP_STREAM_START);

	return 0;
}

/************************************************************************************************
	buffer: MTP BUFFER
	allocate mtp buffer, mtp may share buffer with tp,  need reconfig tp buffer

	NEED demux_lock
***********************************************************************************************/

int  DEMUX_BUF_MTPBuffer_Create(demux_channel *pCh)
{

	DEMUX_BUF_T *pTpBuf = NULL;
	if (pCh == NULL)
	{
		dmx_err	("%s_%d: invalid param !!!!!!!!!\n", __func__, __LINE__);
		return -1;
	}
	if (pCh->mtpBuffer.allocSize != 0) 
		return 0;

	pTpBuf = &pCh->tpBuffer;
#ifdef SHARE_TPBUFFER_WITH_MTPBUFFER
	if (pTpBuf->allocSize == 0)
	{
		dmx_err("%s_%d: tp buffer still not allocate yet!!!\n", __func__, __LINE__);
		return -1;
	}
	
	//reduce tp size
	pTpBuf->size = DEMUX_TP_BUFF_SIZE - MTP_BUFFER_SIZE;
	// config mtp buffer
	pCh->mtpBuffer.phyAddr = pTpBuf->phyAddr + pTpBuf->size;
	pCh->mtpBuffer.allocSize = MTP_BUFFER_SIZE;
	pCh->mtpBuffer.cachedaddr = pTpBuf->cachedaddr + pTpBuf->size;
	pCh->mtpBuffer.nonCachedaddr = pTpBuf->nonCachedaddr + pTpBuf->size;
	pCh->mtpBuffer.isCache = 0;
	pCh->mtpBuffer.virAddr = pTpBuf->virAddr + pTpBuf->size;
	pCh->mtpBuffer.size = MTP_BUFFER_SIZE;
	pCh->mtpBuffer.fromPoll = 0 ;
	dmx_crit("%s_%d: MTP share TP buffer: tp (phy:%x, vir:%p, size:%d/%d), mtp (phy:%x, vir:%p, size:%d/%d)\n",
		__func__, __LINE__, pTpBuf->phyAddr, pTpBuf->virAddr, pTpBuf->size, pTpBuf->allocSize,
		pCh->mtpBuffer.phyAddr, pCh->mtpBuffer.virAddr, pCh->mtpBuffer.size, pCh->mtpBuffer.allocSize);
	DEMUX_BUF_ResetRBHeader(&pCh->tpBufferH, &pCh->tpBuffer, RINGBUFFER_STREAM, 0);
	
#else
	if (DEMUX_BUF_AllocBuffer(&pCh->mtpBuffer, MTP_BUFFER_SIZE, 1, 0) < 0) {
		dmx_crit("[%s %d] fail to allocate MTP buffer\n", __func__, __LINE__);
		return -1;
	}
#endif
	return 0;
}

int DEMUX_BUF_MTPBuffer_Destroy(demux_channel *pCh)
{
	DEMUX_BUF_T *pTpBuf = &pCh->tpBuffer;
	if (pCh == NULL)
	{
		dmx_err	("%s_%d: invalid param !!!!!!!!!\n", __func__, __LINE__);
		return -1;
	}
#ifdef SHARE_TPBUFFER_WITH_MTPBUFFER
	pTpBuf = &pCh->tpBuffer;
	if (pCh->mtpBuffer.allocSize == 0) 
		return 0;

	pTpBuf->size = DEMUX_TP_BUFF_SIZE;

	memset(&pCh->mtpBuffer, 0 , sizeof(DEMUX_BUF_T));
	DEMUX_BUF_ConfigTPBuffer(pCh);
	dmx_crit("%s_%d: MTP share TP buffer: tp (phy:%x, vir:%p, size:%d/%d), mtp (phy:%x, vir:%p, size:%d/%d)\n",
		__func__, __LINE__, pTpBuf->phyAddr, pTpBuf->virAddr, pTpBuf->size, pTpBuf->allocSize,
		pCh->mtpBuffer.phyAddr, pCh->mtpBuffer.virAddr, pCh->mtpBuffer.size, pCh->mtpBuffer.allocSize);
	
	
#else
	
	DEMUX_BUF_FreeBuffer(&pCh->mtpBuffer);
#endif
	return 0;
}
