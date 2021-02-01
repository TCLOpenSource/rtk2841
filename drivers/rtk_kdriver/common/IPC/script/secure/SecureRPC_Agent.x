.insert <RPCBaseDS.h>
.insert <SecureRPCBaseDS.h>

/*---------------------------------------------------------------------------*/
/*    APIs on VP Agent Side                          */
/*                                                                           */
/*---------------------------------------------------------------------------*/

struct RPC_tee_rpc_result_t{
	RPC_RtkDrmCode			func_code;
	unsigned long			result;
	unsigned long			pSharedMem;
	unsigned long			sharedMemSize;
};

struct SECURE_RPC_TOSYSTEM_GET_SETUP_PARAM
{
    long type ;     /* type defined in Include/rpc_Types.h of system source branch */
    long      reserved0;
    long      reserved1 ;
};

struct SECURE_RPC_TOSYSTEM_SET_PARAM
{
    long type ;
    long data[5] ;
};


struct RPCRES_K_S {
	HRESULT result;
	long size ;
	long data[10];
};

struct SECURE_RPC_TOSYSTEM_SEND_RW
{
    long type ;
    long size ;
    long data[16] ;
};

struct SECURE_RPC_TOSYSTEM_TVSERVER_CTRL
{
    long type ;
    long size ;
    char cmd[100] ;
};

struct SECURE_RPC_TOSYSTEM_OSD_MSG
{
    long type ;
    long size ;
    long data[200] ;
};

program SECURE_AGENT {
  version VERSION {
  	HRESULT		SECURE_RPC_ToSystem_PlayReady_Result(RPC_tee_rpc_result_t)       = 2;
  RPCRES_LONG SECURE_RPC_ToSystem_GetSetupParameter(SECURE_RPC_TOSYSTEM_GET_SETUP_PARAM) = 4;
  HRESULT     SECURE_RPC_ToSystem_SetParameter     (SECURE_RPC_TOSYSTEM_SET_PARAM)       = 6;
  RPCRES_K_S  SECURE_RPC_ToSystem_SendReadCommand  (SECURE_RPC_TOSYSTEM_SEND_RW) = 8;
  HRESULT     SECURE_RPC_ToSystem_SendWriteCommand (SECURE_RPC_TOSYSTEM_SEND_RW) = 10;
  HRESULT     SECURE_RPC_ToSystem_TvServerControl (SECURE_RPC_TOSYSTEM_TVSERVER_CTRL) = 12;
  HRESULT     SECURE_RPC_ToSystem_OsdMsg (SECURE_RPC_TOSYSTEM_OSD_MSG) = 14;
  RPCRES_K_S  SECURE_RPC_ToSystem_GetData(SECURE_RPC_TOSYSTEM_SET_PARAM) = 16;
  }=0;
}=502;
