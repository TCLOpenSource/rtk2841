#include <linux/string.h>
#include "rtkdemux_rec.h"

extern int DEMUX_AllocBuffer(DEMUX_BUF_T *pBuf, int size, int isCache, int useZone);
extern int DEMUX_AllocFromPoll(DEMUX_BUF_T *pBuf, int size, DEMUX_BUF_T *pSrcBuf, int isCache);
extern int DEMUX_FreeBuffer(DEMUX_BUF_T *pBuf);

unsigned char DEMUX_REC_RequestWriteSpace(demux_channel *pCh, unsigned long *pWP, int *pWritableSize)
{
#ifndef DEMUX_REC_FROM_TP_BUF
	RINGBUFFER_HEADER *pHeader;
	int writableSize;
	if (pCh->recBufferH.virAddr == 0)
		return 0;

	pHeader = (RINGBUFFER_HEADER *)pCh->recBufferH.virAddr;
	writableSize = pHeader->readPtr[0] - pHeader->writePtr - 1;
	if (writableSize < 0)
		writableSize += pHeader->size;

	*pWritableSize = writableSize;
	*pWP = pHeader->writePtr;
#endif
	return 1;
}
void DEMUX_REC_WriteToRecBuf(demux_channel *pCh, unsigned char *pSrcData, int dataSize)
{
#ifndef DEMUX_REC_FROM_TP_BUF
	RINGBUFFER_HEADER *pHeader = (RINGBUFFER_HEADER *)pCh->recBufferH.virAddr;
	unsigned long upper;
	unsigned long wp;
	int writableSize = dataSize;
	int recSize;
	if (DEMUX_REC_RequestWriteSpace(pCh, &wp, &writableSize) == 0)
		return;

	if (writableSize <= 0)
		return;

	if (writableSize < dataSize) {
		dmx_crit("[%s %d] rec buffer full. dataSize = %d, writableSize = %d\n", __func__, __LINE__, dataSize, writableSize);
		return;
	}

	recSize = (writableSize > dataSize) ? dataSize : writableSize;
	upper = pHeader->beginAddr + pHeader->size;

#ifdef DEMUX_REC_HACK_TIMESTAMP
	unsigned char *mywp = (unsigned char *)(wp + pCh->recBufVirAddrOffset);

	RHAL_TP_TimeStampPadding(pSrcData, recSize, &mywp, writableSize, 0, pHeader->beginAddr + pCh->recBufVirAddrOffset, upper + pCh->recBufVirAddrOffset);
	wp = mywp - pCh->recBufVirAddrOffset;

#else
	if ((wp + recSize) > upper) {
		int len = upper - wp;
		memcpy((void *)(wp+pCh->recBufVirAddrOffset), pSrcData, len);
		memcpy((void *)(pHeader->beginAddr+pCh->recBufVirAddrOffset), pSrcData+len, recSize-len);
		wp = pHeader->beginAddr + recSize - len;
	} else {
		memcpy((void *)(wp+pCh->recBufVirAddrOffset), pSrcData, recSize);
		wp += recSize;
	}

	if (wp >= upper)
		wp -= pHeader->size;
#endif
	pHeader->writePtr = wp;
#endif
}
unsigned char DEMUX_REC_AllocateRecBuf(demux_channel *pCh)
{
#ifndef DEMUX_REC_FROM_TP_BUF
	if (pCh->recBufferH.virAddr)
		return 1;

	if (DEMUX_AllocFromPoll(&pCh->recBufferH, sizeof(RINGBUFFER_HEADER), &demux_device->bufPoll, 0) < 0) {
		if (DEMUX_AllocBuffer(&pCh->recBufferH, sizeof(RINGBUFFER_HEADER), 0, 0) < 0)
			return 0;
	}
	#ifdef DEMUX_REC_HACK_TIMESTAMP
	int allocSize = /*12288*600;*/ 96*1024*170; /* for HEVC, about 16M. for asynchronous frame indexing, the size should be 96*1024*2 aligned */
	#else
	int allocSize = (pCh->tsPacketSize == 192) ? 96*1024*172 : 188*1024*40;
	#endif
	if (DEMUX_AllocBuffer(&pCh->recBuffer, allocSize, 0, 0) < 0) {
		DEMUX_FreeBuffer(&pCh->recBufferH);
		return 0;
	}
	pCh->recBufVirAddrOffset = (long)pCh->recBuffer.virAddr - (long)pCh->recBuffer.phyAddr;

	RINGBUFFER_HEADER *pHeader = (RINGBUFFER_HEADER *)pCh->recBufferH.virAddr;
	memset(pHeader, 0, sizeof(RINGBUFFER_HEADER));

	pHeader->beginAddr    = pCh->recBuffer.phyAddr;
	pHeader->size         = pCh->recBuffer.size;
	pHeader->bufferID     = RINGBUFFER_STREAM;
	pHeader->writePtr     = pCh->recBuffer.phyAddr;
	pHeader->numOfReadPtr = 1;
	pHeader->readPtr[0]   = pCh->recBuffer.phyAddr;
	pHeader->readPtr[1]   = pCh->recBuffer.phyAddr;
#endif
	return 1;
}
