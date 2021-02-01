#ifndef _DEMUX_IOCTL_EX_H_
#define _DEMUX_IOCTL_EX_H_

void IOCTLEX_ResetRefClock(demux_channel *pCh);

int IOCTLEX_PESDestToPin(DEMUX_PES_DEST_T dest);
int IOCTLEX_InitChannelImpl(int chIndex);
int IOCTLEX_UninitChannelImpl(demux_channel *pCh);

int IOCTLEX_StopDemux(DEMUX_CHANNEL_T *pInfo);
int IOCTLEX_StartDemux(DEMUX_CHANNEL_T *pInfo);
int IOCTLEX_SetBuffer(DEMUX_BUF_INFO_T *pInfo);
int IOCTLEX_ReleaseBuffer(DEMUX_BUF_INFO_T *pInfo);

long IOCTLEX_Handle(struct file *filp, unsigned int cmd, unsigned long arg);
#endif
