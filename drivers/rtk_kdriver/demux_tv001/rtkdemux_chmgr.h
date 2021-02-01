#ifndef _DEMUX_CHANNEL_MANAGER_H_
#define _DEMUX_CHANNEL_MANAGER_H_

int CHMGR_AcquireChannel(DEMUX_CH_ACQUIRE_T* pInfo);
int CHMGR_ReleaseChannel(int chIndex);

#endif