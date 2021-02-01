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
#include "rtkdemux_deliver.h"
#include "rtkdemux_export.h"
#include "rtkdemux_debug.h"

int DELIVER_PSI(demux_channel *pCh, unsigned char *pTSP)
{
	DEMUX_BUF_T *pBuf;
	RINGBUFFER_HEADER *pBufHeader;
	int freeSize;
	unsigned char *pDst;

	pBuf = &pCh->psiBufferH;
	pBufHeader = (RINGBUFFER_HEADER *)pBuf->virAddr;
	if (pBufHeader == 0)
		return -1;

	freeSize = BS_DISTANCE2(pBufHeader->writePtr, pBufHeader->readPtr[0], pBufHeader->size) - 1;
	if (freeSize < 188) {
		dmx_crit("[%s %d] PSI buffer full\n", __func__, __LINE__);
		return -1;
	}
	pDst = pBufHeader->writePtr + pCh->psiBuffer.cachedaddr - pCh->psiBuffer.phyAddr;
	memcpy(pDst, pTSP+4, 188);
	DEMUX_flushMemory(pDst, (unsigned char *)pBufHeader->writePtr, 188) ;

	if ((pDst+188) >= (pCh->psiBuffer.cachedaddr + pCh->psiBuffer.size))
		pBufHeader->writePtr = pCh->psiBuffer.phyAddr;
	else
		pBufHeader->writePtr += 188;
	return 0;
}