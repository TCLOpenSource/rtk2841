#ifndef RTKDEMUX_PVRONLY_H
#define RTKDEMUX_PVRONLY_H

#include "rtkdemux.h"
#include "rtkdemux_common.h"
#include "rtkdemux_debug.h"

void PVR_CheckPvrAudioStable(demux_channel *pCh, int64_t pts);
void PVR_PvrStartToPlay(demux_channel *pCh);
void PVR_EnableTPRateControl(demux_channel *pCh, bool bEnable);
void PVR_DetectAudioOnlyFile(demux_channel *pCh);
void PVR_CheckPTSDiff(demux_channel *pCh);

#endif /*RTKDEMUX_PVRONLY_H*/

