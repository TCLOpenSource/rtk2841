/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <VideoRPC_Agent.h>
#include <rt/misc/ClientStub.h>

#include <RPCBaseDS.h>
#include <VideoRPCBaseDS.h>

void * AllocateMem(int c, void *s);

#define INT8U unsigned char
INT8U ReleaseMem(void *msg);

HRESULT *
VIDEO_RPC_ENC_ToSystem_EndOfStream_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ENC_ToSystem_EndOfStream, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_EndOfStream_0(VIDEO_RPC_ENDOFSTREAM *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_ENDOFSTREAM );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_EndOfStream, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_ENDOFSTREAM, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_Deliver_GenInfo_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_Deliver_GenInfo, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_Deliver_FrameInfo_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_Deliver_FrameInfo, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg_0(VIDEO_RPC_DEC_JPEG_INFO *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_DEC_JPEG_INFO );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_JPEG_ToSystem_EndOfDecSeg, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_DEC_JPEG_INFO, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_Deliver_WSSInfo_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_Deliver_WSSInfo, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_Deliver_PauseInfo_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_Deliver_PauseInfo, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_DEC_ToSystem_FatalError_0(VIDEO_RPC_DEC_ERROR_INFO *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_DEC_ERROR_INFO );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_DEC_ToSystem_FatalError, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_DEC_ERROR_INFO, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_ScaleModeSCART_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_ScaleModeSCART, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo_0(VIDEO_RPC_ENC_AUTOPAUSE *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_ENC_AUTOPAUSE );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_Deliver_AutoPauseInfo, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_ENC_AUTOPAUSE, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_VideoHaltDone_0(long *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(long );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_VideoHaltDone, clnt->sendMode,
		(xdrproc_t) xdr_long, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_SendScalerMsg_0(VIDEO_RPC_SCALER_MESSAGE *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_SCALER_MESSAGE );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_SendScalerMsg, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_SCALER_MESSAGE, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_DecoderMessage_0(VIDEO_RPC_DEC_MESSAGE *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_DEC_MESSAGE );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_DecoderMessage, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_DEC_MESSAGE, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_VoutMessage_0(VIDEO_RPC_VOUT_MESSAGE *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_VOUT_MESSAGE );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_VoutMessage, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_VOUT_MESSAGE, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo_0(VIDEO_RPC_DEC_FRAME_INFO *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_DEC_FRAME_INFO );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_DEC_ToSystem_Deliver_FrameInfo, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_DEC_FRAME_INFO, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo_0(VIDEO_RPC_DEC_PIC_INFO *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_DEC_PIC_INFO );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_DEC_ToSystem_Deliver_PicInfo, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_DEC_PIC_INFO, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo_0(VIDEO_RPC_DEC_MEDIA_INFO *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_DEC_MEDIA_INFO );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_DEC_ToSystem_Deliver_MediaInfo, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_DEC_MEDIA_INFO, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}

HRESULT *
VIDEO_RPC_ToSystem_KernelRPC_0(VIDEO_RPC_TO_KERNEL_PARAMETER *argp, CLNT_STRUCT *clnt)
{
#if defined(ENABLE_RPC_PROXY_INIT_CHECK)
  #if 1 == BUILD_FOR_MACARTHUR3
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 1" )
  #else
  #pragma message( "BUILD_FOR_MACARTHUR3 is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_KCPU_COMMON
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 1" )
  #else
  #pragma message("BUILD_FOR_KCPU_COMMON is #define'd to 0" )
  #endif
  #if 1 == BUILD_FOR_MACARTHUR3 && 0 == BUILD_FOR_KCPU_COMMON
    //THIS IS COMPILED FOR SCPU
    extern int g_RPCProxyInitDone;
    if (0 == g_RPCProxyInitDone)
    {
        //while (1)
        //{
        //    printf ("g_RPCProxyInitDone not init to 1\n");
        //    sleep (1);
        //}
        initRPCProxy();
    }
  #endif
#endif //ENABLE_RPC_PROXY_INIT_CHECK
	RPC_STRUCT rpc;
	HRESULT * result = NULL ;
	long args_size = sizeof(VIDEO_RPC_TO_KERNEL_PARAMETER );
	unsigned char pool;


	// if NONBLOCK_MODE, dont need to alloc memory
	if (clnt->sendMode & BLOCK_MODE) {
		result = (HRESULT *) AllocateMem(sizeof(HRESULT ), &pool);
	}


	// prepare the RPC call structure
	// including programID, versionID, TaskID...
	rpc = prepareRPCCall(clnt, (int)result);


	if (client_call (&rpc, VIDEO_RPC_ToSystem_KernelRPC, clnt->sendMode,
		(xdrproc_t) xdr_VIDEO_RPC_TO_KERNEL_PARAMETER, (caddr_t) argp, args_size)
		!= RPC_SUCCESS) {
		if(result)
			ReleaseMem(result);
		return (HRESULT *)-1;
	}


	//for blocking use
	if (clnt->sendMode & BLOCK_MODE) {
		XDR xdrs;

		waitReply();
		xdrmem_create(&xdrs, (char *)result, sizeof(HRESULT), XDR_DECODE);
		 if(!xdr_HRESULT(&xdrs, result))
			 return (HRESULT *)-1;
		return result;
	}

	return 0;

}
