#ifndef _DEMUX_BUF_H_
#define _DEMUX_BUF_H_

#define WAIT_TO_BE_DONE_TIMEOUT (5*HZ)	/* 5 sec */

void DEMUX_BUF_ResetRBHeader(DEMUX_BUF_T *pBufH, DEMUX_BUF_T *pBuf, RINGBUFFER_TYPE type, unsigned char reverse);
int DEMUX_BUF_AllocBuffer(DEMUX_BUF_T *pBuf, int size, int isCache, int useZone);
int DEMUX_BUF_FreeBuffer(DEMUX_BUF_T *pBuf);
int DEMUX_BUF_AllocFromPoll(DEMUX_BUF_T *pBuf, int size, DEMUX_BUF_T *pSrcBuf, int isCache);
void DEMUX_BUF_RestoreFromPoll(DEMUX_BUF_T *pBuf);
void DEMUX_BUF_ZeroOutBuffer(DEMUX_BUF_T *pBuf);

int DEMUX_BUF_SetupPSIBuffer(demux_channel *pCh, unsigned long phyAddr, int size);
int DEMUX_BUF_SetupRefClockBuf(demux_channel *pCh, unsigned long phyAddr, int size);
int DEMUX_BUF_ReturnRefClockBuffer(demux_channel *pCh);
int DEMUX_BUF_ReturnPSIBuffer(demux_channel *pCh);


int DEMUX_BUF_SetupDecBuffer(demux_channel *pCh, int pin, unsigned long bsPhyAddr, int bsSize, unsigned long ibPhyAddr, int ibSize);
int DEMUX_BUF_ReturnDecBuffer(demux_channel *pCh, int pin);
void DEMUX_BUF_UpdatePinInfo(demux_channel *pCh);

int DEMUX_BUF_PrepareSelfRefClockBuf(demux_channel *pCh);
int DEMUX_BUF_PrepareSelfDecBuf(demux_channel *pCh, int pin, int bsSize, int ibSize);

int DEMUX_PESBuffer_Alloc(DEMUX_PES_MAP_T *pMap, int size);
void DEMUX_PESBuffer_UpdateBuferStatus(demux_channel *pCh);
void DEMUX_PESBuffer_UpdateBuferStatus(demux_channel *pCh);

int DEMUX_BUF_APvrBuffer_Alloc(int size);
int DEMUX_BUF_GIFOBuffer_Alloc(DEMUX_CHANNEL_T ch, int size);


int DEMUX_BUF_AllocTPBuffer(demux_channel * pCh);
int DEMUX_BUF_FreeTPBuffer(demux_channel * pCh);
int DEMUX_BUF_ConfigTPBuffer(demux_channel * pCh);
int DEMUX_BUF_MTPBuffer_Create(demux_channel *pCh);
int DEMUX_BUF_MTPBuffer_Destroy(demux_channel *pC);
#endif
