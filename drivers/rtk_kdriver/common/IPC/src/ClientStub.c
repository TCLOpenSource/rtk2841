#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <ClientStub.h>

#ifdef DEBUG_RPCCALL
#define DBGFN "/tmp/rpc.txt"

static inline void write_file(char *func, int line, char *cpu, char *proc)
{
	static int fd = -1;
	char buf[128];
	int len;

	if(fd == -1){
		printf("open %s for debugging...\n", DBGFN);
		fd = open(DBGFN, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0644);
	}

	if(fd == -1){
		perror("open file failed");
		return;
	}

	len = sprintf(buf, "%s:%s @%s:%d\n", cpu, proc, func, line);
	write(fd, buf, len);
}


/*
 *  Used to pack the RPC_STRUCT and parameter must send to server
 *  then write to the ring buffer
 */
int __client_call ( char *func, int line, char *procName, RPC_STRUCT * rpc, u_long procedureID, int sendMode, xdrproc_t xdr_args, caddr_t args_ptr, long args_size)
#else
int client_call ( RPC_STRUCT * rpc, u_long procedureID, int sendMode, xdrproc_t xdr_args, caddr_t args_ptr, long args_size)
#endif
{

    XDR xdrs;
    char * mem_ToShm;        // Memory start address for writing to Share-memory
    int size_ToShm = 0;      // size of memory for writing to Share-memory
    int cnt;                 // number of bytes writed to Share-memory

    // assign RPC_STRUCT's value
    rpc->procedureID = procedureID;

    /*
     * prepare continuous memory for sending to share-memory
     *    start  ---------------
     *           |  RPC_STRUCT |
     *           |-------------|
     *           | user's args |
     *           |-------------|
     */

    // prepare XDR's memory location of ARGS
    // because we need args_size after XDR
    // so we do this first.
    mem_ToShm = (char *)malloc(sizeof(RPC_STRUCT) + args_size);
    mem_ToShm += sizeof(RPC_STRUCT);


    xdrmem_create(&xdrs, (char *)mem_ToShm, args_size, XDR_ENCODE);
    if ((*xdr_args)(&xdrs, args_ptr) ==0) {
           printf("XDR error \n");
	   exit(1);
    }

    rpc->parameterSize = xdr_getpos(&xdrs);
    size_ToShm += rpc->parameterSize;

    mem_ToShm -= sizeof(RPC_STRUCT);




    // prepare XDR's memory location of RPC_STRUCT
    xdrmem_create(&xdrs, (char *)mem_ToShm, sizeof(RPC_STRUCT), XDR_ENCODE);
    if( xdr_RPC_STRUCT(&xdrs, rpc) == 0){
	    printf(" XDR_RPC_STRUCT error \n");
	    exit(1);
    }
    size_ToShm += xdr_getpos(&xdrs);

#ifdef DEBUG_RPCCALL
    write_file(func, line, (sendMode & SEND_AUDIO_CPU) ? "Audio" : "Video", procName);
    printf("================= %sRPC: %s(%lu) ===============\n", (sendMode & SEND_AUDIO_CPU) ? "Audio" : "Video", procName, procedureID);
#endif

    // Write to Ring Buffer
//    fflush(1);
    cnt = writeRingBuf(sendMode, (char *)mem_ToShm, size_ToShm);
    //printf("Client Write to ring buf %d bytes \n",cnt);
    RPCDEBUG("Client Write to ring buf %d bytes \n",cnt);
    free(mem_ToShm);


    // if writeRingBuf error,
    // return to the user send error,
    // we dont re-send it.
    if (cnt == size_ToShm) {
        return RPC_SUCCESS;
    }
    else {
	    printf("cnt: %d, size_ToShm: %d\n", cnt, size_ToShm);
        return RPC_ERROR;
    }

}



/*
 * according to the setting user apply
 * fill into the RPC_STRUCT
 */
RPC_STRUCT
prepareRPCCall(
    CLNT_STRUCT *clnt,
    int result)
{
    RPC_STRUCT rpc;

    // if NONBLOCK_MODE, Task ID must be 0
    if (clnt->sendMode & BLOCK_MODE)
        rpc.taskID = getTaskID();
    else
	rpc.taskID = 0;

    rpc.programID = clnt->programID;
    rpc.versionID = clnt->versionID;
    rpc.context = (int)result;
    rpc.parameterSize = 0;
    rpc.procedureID = 0;
#ifdef RTD_1195
    rpc.sysPID = clnt->sysPID;
#endif
    return rpc;
}


/*
 * The function apply to server proxy
 * used to send the reply back
 */
void
RTK_SendReply(
   u_long     req_taskID,
   int        req_context,
   char     * ReplyParameter,   // parameter's start address
   u_long     ParameterSize,    // parameter's size
   xdrproc_t  _xdr_result,
   int        opt)
{
    RPC_STRUCT rpc;
    XDR xdrs;
    char * mem_ToShm;       // mem start addr for writing to share memory
    int size_ToShm =0 ;     // total mem size for writing to share memory
    int cnt=0;

//    if (openStubRPC()) {
//        exit(1);
//    }

    // when reply, RPC's context must be the parameter addr we want to reply.

    rpc.programID = REPLYID;
    rpc.versionID = REPLYID;
    rpc.procedureID = 0;
    rpc.context = req_context;  // fill in req's para addr
    rpc.taskID = 0;
#ifdef RTD_1195
    rpc.sysPID = 0;
#endif

    ////////////////////////////////////////////////////////
    //               _______________
    //               |  RPC_STRUCT  |
    //               ----------------
    //               | req's TaskID |   <- use to wake up request func
    //               ----------------
    //               |  Reply para. |
    //               ----------------
    mem_ToShm = malloc(sizeof(RPC_STRUCT) + sizeof(u_long)+ ParameterSize);

    mem_ToShm += sizeof(RPC_STRUCT);

     // TaskID
    xdrmem_create(&xdrs, mem_ToShm, sizeof(u_long), XDR_ENCODE);
    if(!xdr_u_long(&xdrs, &req_taskID)){
    	printf("get xdr_u_long error...\n");
    	return;
    }

    size_ToShm += sizeof(u_long);
    mem_ToShm += size_ToShm;

     // Reply Parameter
    xdrmem_create(&xdrs, mem_ToShm, ParameterSize, XDR_ENCODE);
    (*_xdr_result)(&xdrs, ReplyParameter);


    size_ToShm += xdr_getpos(&xdrs);
    rpc.parameterSize = size_ToShm;


    mem_ToShm -= (sizeof(u_long) + sizeof(RPC_STRUCT));

     // RPC_STRUCT
    xdrmem_create(&xdrs, mem_ToShm, sizeof(RPC_STRUCT), XDR_ENCODE);
    xdr_RPC_STRUCT(&xdrs, &rpc);

    size_ToShm += xdr_getpos(&xdrs);

    cnt = writeRingBuf(opt, (char *)mem_ToShm, size_ToShm);
    free(mem_ToShm);


//    closeStubRPC();
}

