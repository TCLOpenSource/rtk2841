#include <stdio.h>
#include <RPCProxy.h>

int pli_setThreadName(char *str);


#define NUM_HANDLER_THREADS 3

struct THREAD_STRUCT *g_pStruct_a = NULL;
struct THREAD_STRUCT *g_pStruct_v = NULL;
struct THREAD_STRUCT *g_pStruct_v2 = NULL;
struct THREAD_STRUCT *g_pStruct_s = NULL;
int g_RPCThreadRunning = 0;
pthread_t g_p_threads_a[NUM_HANDLER_THREADS];
pthread_t g_p_threads_v[NUM_HANDLER_THREADS];
pthread_t g_p_threads_v2[NUM_HANDLER_THREADS];
pthread_t g_p_threads_s[NUM_HANDLER_THREADS];
    
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
    
    if (pData->flag == SEND_SYSTEM_CPU)
        pli_setThreadName("RPC_thread_S");
    else if (pData->flag == SEND_AUDIO_CPU)
        pli_setThreadName("RPC_thread_A");
    else if (pData->flag == SEND_VIDEO_CPU2)
        pli_setThreadName("RPC_thread_V2");
    else
        pli_setThreadName("RPC_thread_V");

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

int initRPCProxy(struct REG_STRUCT *reg) {

    int i=0;
    static pthread_mutex_t request_mutex_a = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
    static pthread_mutex_t request_mutex_v = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
    static pthread_mutex_t request_mutex_v2 = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
    static pthread_mutex_t request_mutex_s = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

    g_pStruct_a = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_a)
        exit(1);
    g_pStruct_v = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_v)
        exit(1);
    g_pStruct_v2 = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_v2)
        exit(1);
    g_pStruct_s = (THREAD_STRUCT *)malloc(sizeof(THREAD_STRUCT));
    if (!g_pStruct_s)
        exit(1);

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

    g_pStruct_s->pReg = reg;
    g_pStruct_s->pMutex = &request_mutex_s;
    g_pStruct_s->flag = SEND_SYSTEM_CPU;
    for (i=0; i<NUM_HANDLER_THREADS; i++)
        pthread_create(&g_p_threads_s[i], NULL, (void *)RPCProxy_loop, g_pStruct_s);

    return 1;
}


int DeInitRPCProxy() {    
    int i;

    g_RPCThreadRunning = 0;

    for (i = 0; i<NUM_HANDLER_THREADS;i++)
        pthread_join(g_p_threads_a[i], 0);
    for (i = 0; i<NUM_HANDLER_THREADS;i++)
        pthread_join(g_p_threads_v[i], 0);    
    for (i = 0; i<NUM_HANDLER_THREADS;i++)
        pthread_join(g_p_threads_v2[i], 0);    
    for (i = 0; i<NUM_HANDLER_THREADS;i++)
        pthread_join(g_p_threads_s[i], 0);    
    
    if (g_pStruct_a && g_pStruct_a->pReg)
        ipc_unregister(g_pStruct_a->pReg);

    if (g_pStruct_a)
        free(g_pStruct_a);

    if (g_pStruct_v)
        free(g_pStruct_v);

    if (g_pStruct_v2)
        free(g_pStruct_v2);

    if (g_pStruct_s)
        free(g_pStruct_s);

    closeRPC();
    closeStubRPC();

    return 1;    
}
