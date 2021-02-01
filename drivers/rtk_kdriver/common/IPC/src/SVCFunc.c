#include <xdr/xdr.h>
#include <xdr/types.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
#include <RPCProxy.h>
#include <SVCFunc.h>


/*
 * read the IPC packet's body,
 * after XDR transformation, store the parameter
 */
int
rpc_getargs(
    RPC_STRUCT      * rpc,
    xdrproc_t         _xdr_argument,
    caddr_t           argument,
    int               opt)
{
    XDR xdrs;
    char * buf;

    // according to the parameter size recording in RPC_STRUCT
    // read the packet's body from ring buffer.
    buf = malloc(rpc->parameterSize);
    if (readRingBuf(opt, (char*)buf, rpc->parameterSize) != rpc->parameterSize){
	    printf("read ring buffer error \n");
	    free(buf);
	    return 0;
    }


    xdrmem_create(&xdrs, buf, rpc->parameterSize, XDR_DECODE);

    // return the XDR transformation's result,
    // if success, must free the xdrs
    if ((*_xdr_argument)( &xdrs, argument)) {
        xdrs.x_op = XDR_FREE;
        (*_xdr_argument)( &xdrs, argument);
    	free(buf); // modified by jacky
        return 1;
    }
    else {
    	free(buf); // modified by jacky
        return 0;
    }


}



/*
 * Registered Reply Handler,
 * only use in BLOCK_MODE,
 * responsible for wake up the client task, and copy the result parameter
 */
void
Reply_Handler(
    RPC_STRUCT   * rpc,
    int            opt,
    pthread_mutex_t *pMutex)
{
    XDR xdrs;
    char * buf;
    u_long result_taskID;

    buf = malloc(rpc->parameterSize);

    if (readRingBuf(opt, (char*)buf, rpc->parameterSize) != rpc->parameterSize){
	    printf("read Ring Buffer error \n");
	    free(buf);
	    return ;
    }

    pthread_mutex_unlock(pMutex);

    // decode the taskID.
    xdrmem_create(&xdrs, buf, sizeof(u_long), XDR_DECODE);
    if(!xdr_u_long(&xdrs, &result_taskID)){
    	printf("xdr_u_long false...\n");
    	return;
    }

    buf += sizeof(u_long);

    // copy the result parameter and wake up the task by taskID.
    memcpy((char *)rpc->context, buf, (rpc->parameterSize-sizeof(u_long)));
    buf -= sizeof(u_long); //modified by ycyang
    free(buf); // modified by jacky

    ackTask(result_taskID);
}



/*
 * assign register values into the REG linking list
 * ( programID,
 *   versionID,
 *   dispatch function pointer)
 */
struct REG_STRUCT * ipc_register(
    struct REG_STRUCT * reg,
    u_long       programID,
    u_long       versionID,
    void        (*func)(struct RPC_STRUCT *, int, pthread_mutex_t *))
{

    if (reg == NULL) {
        reg = (struct REG_STRUCT *)malloc(sizeof(struct REG_STRUCT));
	 if (reg == NULL) {
	       printf("(register error! alloc memory fail\n");
       	return 0;
	 }
        reg->programID = programID;
        reg->versionID = versionID;
        reg->func = func;
        reg->next = NULL;
    }
    else if ((reg->programID == programID) && (reg->versionID == versionID)) {
        printf("(register error! program and version has been registered \n");
        return 0;
    }
    else{
        reg->next = ipc_register(reg->next, programID, versionID, func);
    }
    return reg;

}

int ipc_unregister(struct REG_STRUCT * reg) {
    int i, j, ptr[10];
    struct REG_STRUCT * tmp = reg;

    for (j=0; j<10; j++)
        ptr[j] = 0;

    i=0;

    while (tmp->next) {
        ptr[i] = (int)tmp;
        i++;
        tmp = tmp->next;
    }

    free(tmp);
    for (j=(i-1); j>=0; j--)
        free((void*)ptr[j]);

    return 1;
}

/*
 * The function used to register Reply_Handler
 * the program ID and version ID are assignd as "REPLYID"
 */

struct REG_STRUCT * ReplyHandler_register( struct REG_STRUCT * reg)
{
    reg = (struct REG_STRUCT *)
	          ipc_register(reg, REPLYID, REPLYID, Reply_Handler);
    return reg;
}


