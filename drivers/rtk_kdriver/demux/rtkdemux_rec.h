#ifndef RTKDEMUX_RECORD_H
#define RTKDEMUX_RECORD_H

#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include "rtkdemux.h"

unsigned char DEMUX_REC_RequestWriteSpace(demux_channel *pCh, unsigned long *pWP, int *pWritableSize);
void DEMUX_REC_WriteToRecBuf(demux_channel *pCh, unsigned char *pSrcData, int dataSize);
unsigned char DEMUX_REC_AllocateRecBuf(demux_channel *pCh);

#endif /*RTKDEMUX_RECORD_H*/
