#ifndef  _RPC_STRUCT_H_
#define  _RPC_STRUCT_H_


#include <xdr/types.h>
#include <xdr/xdr.h>


#ifdef __cplusplus
extern "C" {
#endif

#ifdef RPC_DEBUG
 #define RPCDEBUG(fmt, args...) printf(fmt, ## args)
#else
 #define RPCDEBUG(fmt, args...)  /*empty macro */
#endif

#define REPLYID 99   // for registering the Reply_Handler

#define NONBLOCK_MODE	0x00
#define	BLOCK_MODE		0x01
#define USE_POLL_BUF	0x00
#define USE_INTR_BUF	0x02
#define SEND_VIDEO_CPU	0x00
#define SEND_AUDIO_CPU	0x04
#define SEND_VIDEO_CPU2	0x08
#ifdef ENABLE_KCPU_COMMON
#define SEND_SYSTEM_CPU 0x10
#define SEND_SECURE_CPU 0x10
#endif

#define RTD_1195

/*
 * The data structure for user assign the sending mode
 * the sendMode defined in rpcapi.h
 */
typedef struct CLNT_STRUCT CLNT_STRUCT;

struct CLNT_STRUCT {
    int sendMode;  // (NONBLOCK_MODE, BLOCK_MODE) | (USE_POLL_BUF, USE_INTR_BUF)
    long programID;  // The program ID defined in IDL file
    long versionID;  // The version ID defined in IDL file
#ifdef RTD_1195
	long sysPID;        // the callee's task ID
#endif
};



/*
 * The packet header of RPC
 */
typedef struct RPC_STRUCT RPC_STRUCT;

struct RPC_STRUCT {
    u_long programID;      // program ID defined in IDL file
    u_long versionID;      // version ID defined in IDL file
    u_long procedureID;    // function ID defined in IDL file

    u_long taskID;         // the caller's task ID, assign 0 if NONBLOCK_MODE
#ifdef RTD_1195
    u_long sysPID;         // the callee's task ID
#endif
    u_long parameterSize;  // packet's body size
    u_int context;         // return address of reply value
};



bool_t                 xdr_RPC_STRUCT(XDR *, RPC_STRUCT *);

CLNT_STRUCT            prepareCLNT(int opt, long programID, long versionID);
#ifdef RTD_1195
CLNT_STRUCT            prepareCLNT2(int opt, long programID, long versionID, long sysPID);
#endif

#ifdef __cplusplus
}
#endif

#define SendReply RTK_SendReply

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

