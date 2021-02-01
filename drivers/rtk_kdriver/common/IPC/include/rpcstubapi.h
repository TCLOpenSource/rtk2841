#ifndef _RPCSTUBAPI_H
#define _RPCSTUBAPI_H

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

int			openStubRPC();
int			closeStubRPC();

long		getTaskID();

int			writeRingBuf(int opt, char *buf, int size);

#if defined(USE_TIMED_WAITREPLY)
void        __timedwaitReply(const char *func_name);
#else
void        waitReply();
#endif

#ifdef __cplusplus
}
#endif

#if defined(USE_TIMED_WAITREPLY)
#define waitReply()   __timedwaitReply(__FUNCTION__)
#endif

#ifdef IS_SCPU
#undef RPC_EMERG
#define RPC_EMERG(fmt, args...)       logger_kmsg("[libk]-wrpc:" fmt, ## args)
void logger_kmsg(char * fmt, ...);
#define Q9527_DEBUG() \
{ \
    if (rpc->procedureID == 47 || rpc->procedureID == 48) \
        RPC_EMERG("%s:pid = %d, procedureID = %d\n", __FUNCTION__,(int)gettid(), (int)rpc->procedureID); \
}
#else
#define RPC_EMERG(fmt, args...)      do {}while(0)
#define Q9527_DEBUG()                do {}while(0)
#endif

#ifdef __BIONIC__
#undef RPC_EMERG
#include <cutils/log.h>
#define RPC_EMERG ALOGE
#endif

#endif

