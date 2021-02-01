#include <linux/string.h>
#include <linux/slab.h>
#include "rtkdemux.h"
#include "rtkdemux_debug.h"
#include "rtkdemux_chmgr.h"

int CHMGR_TryAcquireChannel(DEMUX_CH_ACQUIRE_PRIORITY priority);
int CHMGR_DumpChannelUsage(void);

int CHMGR_DumpChannelUsage(void)
{
	int i;
	if (demux_device->pChUsage == 0)
		return -1;

	dmx_notice("channel usage:\n");
	for (i = 0; i < demux_device->chNum; i++) {
		const DEMUX_CH_USAGE_T *pChUsage = demux_device->pChUsage + i;

		dmx_notice("ch[%d]: bUsed = %d, owner = %s\n", i, pChUsage->bUsed, pChUsage->pOwner ? pChUsage->pOwner : "null");
	}
	return 0;
}
int CHMGR_AcquireChannel(DEMUX_CH_ACQUIRE_T* pInfo)
{
	int chIndex = -1;
	if (pInfo == 0 || demux_device->pChUsage == 0)
		return -1;

	chIndex = CHMGR_TryAcquireChannel(pInfo->priority);
	if (chIndex == -1) {
		dmx_crit("[%s %d] acquire ch fail. owner = %s\n", __func__, __LINE__, pInfo->owner);
		CHMGR_DumpChannelUsage();
		return -1;
	}

	demux_device->pChUsage[chIndex].bUsed = true;
	demux_device->pChUsage[chIndex].pOwner = strlen(pInfo->owner) > 0 ? kstrdup(pInfo->owner, GFP_KERNEL) : 0;
	pInfo->chIndex = chIndex;
	dmx_notice("[%s %d] acquire ch = %d. owner = %s\n", __func__, __LINE__, chIndex, pInfo->owner);
	CHMGR_DumpChannelUsage();
	return 0;
}
int CHMGR_TryAcquireChannel(DEMUX_CH_ACQUIRE_PRIORITY priority)
{
	int i;
	int sdtCh = -1;
	int pvrCh = -1;
	int liveCh = -1;
	if (demux_device->pChUsage == 0)
		return -1;

	for (i = 0; i < demux_device->chNum; i++) {
		if (demux_device->pChUsage[i].bUsed)
			continue;
		if (sdtCh == -1 && demux_device->pChArray[i].bIsSDT)
			sdtCh = i;
		else if(pvrCh == -1 && i >= 0 && i <= 1)
			pvrCh = i;
		else if(liveCh == -1)
			liveCh = i;
	}

	if (priority == DEMUX_CH_PVR_ONLY)
		return pvrCh;
	if (priority == DEMUX_CH_PVR_FIRST) {
		if (pvrCh != -1)    return pvrCh;
		return liveCh;
	}
	if (priority == DEMUX_CH_SDT_ONLY)
		return sdtCh;
	if (priority == DEMUX_CH_SDT_FIRST) {
		if (sdtCh != -1)    return sdtCh;
		if (liveCh != -1)    return liveCh;
		return pvrCh;
	}
	if (priority == DEMUX_CH_LIVE_ONLY)
		return liveCh;
	if (priority == DEMUX_CH_LIVE_FIRST) {
		if (liveCh != -1)    return liveCh;
		return pvrCh;
	}
	return -1;
}
int CHMGR_ReleaseChannel(int chIndex)
{
	if (demux_device->pChUsage == 0 || chIndex >= demux_device->chNum || chIndex < 0)
		return -1;

	dmx_notice("[%s %d] release ch = %d.\n", __func__, __LINE__, chIndex);
	demux_device->pChUsage[chIndex].bUsed = false;
	if (demux_device->pChUsage[chIndex].pOwner) {
		kfree(demux_device->pChUsage[chIndex].pOwner);
		demux_device->pChUsage[chIndex].pOwner = 0;
	}
	CHMGR_DumpChannelUsage();
	return 0;
}