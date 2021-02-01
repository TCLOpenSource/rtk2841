#ifndef _RPCAPI_H
#define _RPCAPI_H

#define NONBLOCK_MODE	0x00
#define	BLOCK_MODE		0x01
#define USE_POLL_BUF	0x00
#define USE_INTR_BUF	0x02
#define SEND_VIDEO_CPU	0x00
#define SEND_AUDIO_CPU	0x04
#define SEND_VIDEO_CPU2	0x08
#ifdef ENABLE_KCPU_COMMON
#define SEND_SECURE_CPU	0x10
#define SEND_SYSTEM_CPU 0x10
#endif

#ifdef __cplusplus
extern "C" {
#endif

int			openRPC();
int			closeRPC();

void		setTimeout(int msec);

int			readRingBuf(int opt, char *buf, int size);

void		ackTask(int taskid);

#define RPC_PROGRAM_REGISTER

#ifdef RPC_PROGRAM_REGISTER
#include <sys/ioctl.h>
#define RPC_IOC_MAGIC  'k'
#define RPC_IOCTHANDLER _IO(RPC_IOC_MAGIC, 3)
#define RPC_IOSTOP      _IO(RPC_IOC_MAGIC, 4)
int			registerRPC(unsigned long programID);
int			stopRPC();
#endif

#ifdef __cplusplus
}
#endif
#endif
