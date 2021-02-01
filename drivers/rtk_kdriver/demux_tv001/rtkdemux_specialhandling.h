#ifndef __RTKDEMUX_SPECIALHANDLING_H__
#define __RTKDEMUX_SPECIALHANDLING_H__

#include "rtkdemux.h"

void BufferFullDroppingReset(demux_channel *pCh, int pinIndex, int isAllPin);
void CheckStartCondition(demux_channel *pCh, int pinIndex);
void CheckStopCondition(demux_channel *pCh, int pinIndex, long writableSize, long ringBufferSize);
bool IsDropping(demux_channel *pCh, int pinIndex);
bool GetTotalDroppingPin(void);
void DroppingResetReset(demux_channel *pCh);


#endif /* __RTKDEMUX_SPECIALHANDLING_H__ */

