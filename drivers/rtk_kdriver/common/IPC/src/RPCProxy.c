#include <stdio.h>
#include <RPCProxy.h>
//#include <Logger/rtd_log.h>

int pli_setThreadName(char *str);


#define NUM_HANDLER_THREADS 3

struct THREAD_STRUCT *g_pStruct_a = NULL;
struct THREAD_STRUCT *g_pStruct_v = NULL;
struct THREAD_STRUCT *g_pStruct_v2 = NULL;
#ifdef ENABLE_KCPU_COMMON
struct THREAD_STRUCT *g_pStruct_k = NULL;
#endif
int g_RPCThreadRunning = 0;
pthread_t g_p_threads_a[NUM_HANDLER_THREADS];
pthread_t g_p_threads_v[NUM_HANDLER_THREADS];
pthread_t g_p_threads_v2[NUM_HANDLER_THREADS];
#ifdef ENABLE_KCPU_COMMON
pthread_t g_p_threads_k[NUM_HANDLER_THREADS];
#endif

/*
 * Dispatch Function
 * compare the REG Linking-List's value
 * according to programID and versionID, dispatch to different handler
 */
void DispatchRPCRequest(struct REG_STRUCT * reg, char * buf, int opt, pthread_mutex_t *pMutex){

    RPC_STRUCT rpc;
    XDR xdrs;

    xdrmem_create(&xdrs, buf, sizeof(RPC_STRUCT), XDR_DECODE);
    xdr_RPC_STRUCT(&xdrs, &rpc);

    // according to the programID and versionID,
    // dispatch to the corresponding function
    for ( ; reg != NULL ; reg = reg->next) {
        if ((rpc.programID == reg->programID) &&
            (rpc.versionID == reg->versionID)) {
	        (*(reg->func))(&rpc, opt, pMutex);
	        break;
        }
    }

}

/*
 *  The entry of Server Proxy
 *  responsible for reading from INTERRUPT & POLL ring-buffer
 *  then call dispatch
 */
void RPCProxy_loop(struct THREAD_STRUCT * pData){

    char * buf = malloc(sizeof(RPC_STRUCT));
    int cnt;
    struct sched_param param;

    if (pData->flag == SEND_AUDIO_CPU) {
        pli_setThreadName("RPC_thread_A");
    }
    else if(pData->flag == SEND_VIDEO_CPU2) {
        pli_setThreadName("RPC_thread_V2");
    }
#ifdef ENABLE_KCPU_COMMON
    else if(pData->flag == SEND_SECURE_CPU) {
        pli_setThreadName("RPC_thread_K");
    }
#endif
    else {
        pli_setThreadName("RPC_thread_V");
    }
    // boost its priority
    param.sched_priority = 1;
    if (sched_setscheduler(0, SCHED_FIFO, &param) != 0)
        perror("error in sched_setscheduler");

    while (g_RPCThreadRunning) {

        pthread_mutex_lock(pData->pMutex);

		while (g_RPCThreadRunning) {
			// check poll ring buffer later...
			if ((cnt = readRingBuf(USE_POLL_BUF | pData->flag, (char *)buf, sizeof(RPC_STRUCT))) > 0) {
				RPCDEBUG("read from poll ring buffer %d bytes\n", cnt);

				DispatchRPCRequest(pData->pReg, buf, USE_POLL_BUF | pData->flag, pData->pMutex);
				break;
			}

			// check INTR ring buffer first
			if ((cnt = readRingBuf(USE_INTR_BUF | BLOCK_MODE | pData->flag, (char *)buf, sizeof(RPC_STRUCT))) > 0) {
				//printf("read from intr ring buffer %d bytes\n", cnt);
				RPCDEBUG("read from intr ring buffer %d bytes\n", cnt);

				DispatchRPCRequest(pData->pReg, buf, USE_INTR_BUF | BLOCK_MODE | pData->flag, pData->pMutex);
				break;
			}
			RPCDEBUG("***waiting timeout...\n");
		}

    }

    if (buf)
        free(buf);

    pthread_mutex_unlock(pData->pMutex);
    pthread_exit(NULL);

    //closeRPC();
}

#if __BIONIC__ == 1
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP {0}
#endif // __BIONIC__ == 1

#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
#if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
int g_RPCProxyInitDone = 0;
#endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK

int initRPCProxy(struct REG_STRUCT *reg) {

    int i=0;
    static pthread_mutex_t request_mutex_a = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
    static pthread_mutex_t request_mutex_v = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
    static pthread_mutex_t request_mutex_v2 = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
#ifdef ENABLE_KCPU_COMMON
    static pthread_mutex_t request_mutex_k = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
#endif

    g_pStruct_a = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_a)
        exit(1);
    g_pStruct_v = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_v)
        exit(1);
    g_pStruct_v2 = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_v2)
        exit(1);
#ifdef ENABLE_KCPU_COMMON
    g_pStruct_k = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_k)
        exit(1);
#endif

    if (openRPC())
        exit(1);

    if (openStubRPC())
        exit(1);

#ifdef RPC_PROGRAM_REGISTER
    struct REG_STRUCT *rnode;
    for (rnode = reg ; rnode != NULL ; rnode = rnode->next) {
    	if(registerRPC(rnode->programID)){
    		exit(1);
        }
    }
#endif

    g_RPCThreadRunning = 1;

    g_pStruct_a->pReg = reg;
    g_pStruct_a->pMutex = &request_mutex_a;
    g_pStruct_a->flag = SEND_AUDIO_CPU;
    for (i=0; i<NUM_HANDLER_THREADS; i++)
        pthread_create(&g_p_threads_a[i], NULL, (void *)RPCProxy_loop, g_pStruct_a);

    g_pStruct_v->pReg = reg;
    g_pStruct_v->pMutex = &request_mutex_v;
    g_pStruct_v->flag = SEND_VIDEO_CPU;
    for (i=0; i<NUM_HANDLER_THREADS; i++)
        pthread_create(&g_p_threads_v[i], NULL, (void *)RPCProxy_loop, g_pStruct_v);

    g_pStruct_v2->pReg = reg;
    g_pStruct_v2->pMutex = &request_mutex_v2;
    g_pStruct_v2->flag = SEND_VIDEO_CPU2;
    for (i=0; i<NUM_HANDLER_THREADS; i++)
        pthread_create(&g_p_threads_v2[i], NULL, (void *)RPCProxy_loop, g_pStruct_v2);

#ifdef ENABLE_KCPU_COMMON
    g_pStruct_k->pReg = reg;
    g_pStruct_k->pMutex = &request_mutex_k;
    g_pStruct_k->flag = SEND_SECURE_CPU;
    for (i=0; i<NUM_HANDLER_THREADS; i++)
        pthread_create(&g_p_threads_k[i], NULL, (void *)RPCProxy_loop, g_pStruct_k);
#endif

#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
#if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    g_RPCProxyInitDone = 1;
#endif

#if 1 == BUILD_FOR_MACARTHUR3
#pragma message ( "BUILD_FOR_MACARTHUR3 is #define'd to 1 in RPCProxy.c" )
#else
#pragma message ( "BUILD_FOR_MACARTHUR3 is #define'd to 0 in RPCProxy.c" )
#endif
#if 1 == BUILD_FOR_KCPU_COMMON
#pragma message ( "BUILD_FOR_KCPU_COMMON is #define'd to 1 in RPCProxy.c" )
#else
#pragma message ( "BUILD_FOR_KCPU_COMMON is #define'd to 0 in RPCProxy.c" )
#endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
    return 1;
}

int DeInitRPCProxyEx(unsigned char wait_thread_exit) {
    int i;
	stopRPC();
    g_RPCThreadRunning = 0;
	if (wait_thread_exit){
	    for (i = 0; i<NUM_HANDLER_THREADS;i++)
	        pthread_join(g_p_threads_a[i], 0);
	    for (i = 0; i<NUM_HANDLER_THREADS;i++)
	        pthread_join(g_p_threads_v[i], 0);
	    for (i = 0; i<NUM_HANDLER_THREADS;i++)
	        pthread_join(g_p_threads_v2[i], 0);
#ifdef ENABLE_KCPU_COMMON
	    for (i = 0; i<NUM_HANDLER_THREADS;i++)
	        pthread_join(g_p_threads_k[i], 0);
#endif
	}

    if (g_pStruct_a && g_pStruct_a->pReg)
        ipc_unregister(g_pStruct_a->pReg);

    if (g_pStruct_a)
        free(g_pStruct_a);
    if (g_pStruct_v)
        free(g_pStruct_v);
    if (g_pStruct_v2)
        free(g_pStruct_v2);
#ifdef ENABLE_KCPU_COMMON
    if (g_pStruct_k)
        free(g_pStruct_k);
#endif

#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
#if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    g_RPCProxyInitDone = 0;
#endif
#endif

    return 1;
}
int DeInitRPCProxy()
{
	return DeInitRPCProxyEx(1);
}
