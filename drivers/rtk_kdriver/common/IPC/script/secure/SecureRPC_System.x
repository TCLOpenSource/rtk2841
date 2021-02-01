.insert <RPCBaseDS.h>
.insert <SecureRPCBaseDS.h>

struct RPC_sstore_rpc_cmd_t {
	unsigned int ulCmd;
	unsigned int algo;
	u_long keyType;
	u_long pkey;
	u_long keyLen;
	u_long pIV;
	u_long IVLen;
	u_long pDataIn;
	u_long dataInLen;
	u_long pDataOut;
	u_long dataOutLen;
	u_long pHmacKey;
};

struct RPC_tee_rpc_cmd_t{
	RPC_RtkDrmCode			func_code;
	unsigned long			pSharedMem;
	unsigned long			sharedMemSize;
};

struct RPC_tee_manager_cmd_t{
	char procName[256];
};


struct RPC_tee_manager_time_t
{
    long      tv_sec;
    long      tv_usec;
};


struct RPC_tee_manager_key_t{
	char esnkey[2048];
	long esnkeyLen;
	char playReadyKey[51200];
	long playReadyKeyLen;
};

struct RPC_tee_manager_memInfo_t
{
	long pPhysicalMem;
	long size;
	long procName[256];
};

struct RPC_tee_protection_cmd_t{
	u_long type;
	u_long arg;
	u_long start_addr;
	u_long end_addr;
	u_long reserve[3];
	char name[32];
};

struct SECURE_RPC_DTVAPI_SS
{
	long type ; /* type defined in Include/rpc_Types.h of system source branch */
	long size ;
	long data[5] ;
};

struct SECURE_RPC_DTVAPI_S
{
	long type ;
	long size ;
	long data[10] ;
};

struct SECURE_RPC_DTVAPI_M
{
	long type ;
	long size ;
	long data[30] ;
};

struct SECURE_RPC_DTVAPI_MM
{
	long type ;
	long size ;
	long data[80] ;
};

struct SECURE_RPC_DTVAPI_L
{
	long type ;
	long size ;
	long data[320] ;
};

struct SECURE_RPC_DTVAPI_LL
{
	long type ;
	long size ;
	long data[400] ;
};


struct RPCRES_SS {
	HRESULT result;
	long size ;
	long data[5];
};

struct RPCRES_S {
	HRESULT result;
	long size ;
	long data[10];
};

struct RPCRES_M {
	HRESULT result;
	long size ;
	long data[30];
};

struct RPCRES_MM {
	HRESULT result;
	long size ;
	long data[80];
};

struct RPCRES_L {
	HRESULT result;
	long size ;
	long data[320];
};


/**
 * This script describes SECURE_SYSTEM APIs which system software could invoke/(be invoked) by RPC mechanism.
 * There are several groups of APIs in the SECURE_SYSTEM APIs.
 * One group is APIs that are common to all filters,
 * Others are specific APIs for dedicated application, such as filters, DtvApp, and etc.
 */

#define SECURE_RPC_COMMON_FUNC_BASE               0
#define SECURE_RPC_FILTER_FUNC_BASE            1000
#define SECURE_RPC_APP_FUNC_BASE               3000
#define SECURE_RPC_APP_TEEMANAGER_BASE         4000

program SECURE_SYSTEM {
  version VERSION {

/**
 *  \defgroup common The common APIs
 *  Common APIs which all filter should support to.
 *
 *  \author right
 *  @{
 */

 /*!
 ************************************************************************
 * \brief
 *    These functions are used to control DTV/FrontEnd/Tunder of DTV flow
 *
 ************************************************************************
 */

  HRESULT SECURE_RPC_ToAgent_PlayReady               (RPC_tee_rpc_cmd_t)      = SECURE_RPC_APP_TEEMANAGER_BASE + 1 ;
  long	    SECURE_RPC_ToAgent_GetTeeManagerPid      (long)                     = SECURE_RPC_APP_TEEMANAGER_BASE + 2 ;
  long	    SECURE_RPC_ToAgent_ForkProcessByName     (RPC_tee_manager_cmd_t)    = SECURE_RPC_APP_TEEMANAGER_BASE + 3 ;
  HRESULT   SECURE_RPC_ToAgent_DeleteProcessByName   (RPC_tee_manager_cmd_t)    = SECURE_RPC_APP_TEEMANAGER_BASE + 4 ;
  HRESULT   SECURE_RPC_ToAgent_SetSystemTime         (RPC_tee_manager_time_t)   = SECURE_RPC_APP_TEEMANAGER_BASE + 5 ;
  HRESULT   SECURE_RPC_ToAgent_PrepareKStoreEnv      (RPC_tee_manager_key_t)    = SECURE_RPC_APP_TEEMANAGER_BASE + 6 ;
  HRESULT   SECURE_RPC_ToAgent_DeleteMemoryInKcup    (RPC_tee_manager_memInfo_t)= SECURE_RPC_APP_TEEMANAGER_BASE + 7 ;
  long      SECURE_RPC_ToAgent_AllocateMemoryInKcup  (RPC_tee_manager_memInfo_t)= SECURE_RPC_APP_TEEMANAGER_BASE + 8 ;
  long      SECURE_RPC_ToAgent_SetTeeProtection      (RPC_tee_protection_cmd_t) = SECURE_RPC_APP_TEEMANAGER_BASE + 9 ;

  HRESULT SECURE_RPC_ToAgent_DtvApi_SS               (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 15 ;
  HRESULT SECURE_RPC_ToAgent_Sstore_Cypto               (RPC_sstore_rpc_cmd_t)      = SECURE_RPC_COMMON_FUNC_BASE + 16 ;
  HRESULT SECURE_RPC_ToAgent_DtvApi_S                (SECURE_RPC_DTVAPI_S  x) = SECURE_RPC_COMMON_FUNC_BASE + 20 ;
  HRESULT SECURE_RPC_ToAgent_DtvApi_M                (SECURE_RPC_DTVAPI_M  x) = SECURE_RPC_COMMON_FUNC_BASE + 25 ;
  HRESULT SECURE_RPC_ToAgent_DtvApi_MM               (SECURE_RPC_DTVAPI_MM x) = SECURE_RPC_COMMON_FUNC_BASE + 30 ;
  HRESULT SECURE_RPC_ToAgent_DtvApi_L                (SECURE_RPC_DTVAPI_L  x) = SECURE_RPC_COMMON_FUNC_BASE + 35 ;
  RPCRES_LONG SECURE_RPC_ToAgent_DtvApiWithRes       (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 40 ;
  RPCRES_LONG SECURE_RPC_ToAgent_DtvApiWithRes_rl_S  (SECURE_RPC_DTVAPI_S  x) = SECURE_RPC_COMMON_FUNC_BASE + 45 ;
  RPCRES_LONG SECURE_RPC_ToAgent_DtvApiWithRes_rl_M  (SECURE_RPC_DTVAPI_M  x) = SECURE_RPC_COMMON_FUNC_BASE + 50 ;
  RPCRES_LONG SECURE_RPC_ToAgent_DtvApiWithRes_rl_MM (SECURE_RPC_DTVAPI_MM x) = SECURE_RPC_COMMON_FUNC_BASE + 55 ;
  RPCRES_LONG SECURE_RPC_ToAgent_DtvApiWithRes_rl_L  (SECURE_RPC_DTVAPI_L  x) = SECURE_RPC_COMMON_FUNC_BASE + 60 ;
  RPCRES_LONG SECURE_RPC_ToAgent_DtvApiWithRes_rl_LL (SECURE_RPC_DTVAPI_LL x) = SECURE_RPC_COMMON_FUNC_BASE + 65 ;
  RPCRES_SS   SECURE_RPC_ToAgent_DtvApiWithRes_rss   (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 70 ;
  RPCRES_SS   SECURE_RPC_ToAgent_DtvApiWithRes_rss_S (SECURE_RPC_DTVAPI_S  x) = SECURE_RPC_COMMON_FUNC_BASE + 75 ;
  RPCRES_SS   SECURE_RPC_ToAgent_DtvApiWithRes_rss_M (SECURE_RPC_DTVAPI_M  x) = SECURE_RPC_COMMON_FUNC_BASE + 80 ;
  RPCRES_SS   SECURE_RPC_ToAgent_DtvApiWithRes_rss_MM(SECURE_RPC_DTVAPI_MM x) = SECURE_RPC_COMMON_FUNC_BASE + 85 ;
  RPCRES_SS   SECURE_RPC_ToAgent_DtvApiWithRes_rss_L (SECURE_RPC_DTVAPI_L  x) = SECURE_RPC_COMMON_FUNC_BASE + 90 ;
  RPCRES_S    SECURE_RPC_ToAgent_DtvApiWithRes_S     (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 95 ;
  RPCRES_M    SECURE_RPC_ToAgent_DtvApiWithRes_M     (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 100 ;
  RPCRES_MM    SECURE_RPC_ToAgent_DtvApiWithRes_MM   (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 105 ;
  RPCRES_L    SECURE_RPC_ToAgent_DtvApiWithRes_L     (SECURE_RPC_DTVAPI_SS x) = SECURE_RPC_COMMON_FUNC_BASE + 110 ;
  RPCRES_L    SECURE_RPC_ToAgent_DtvApiWithRes_L_L   (SECURE_RPC_DTVAPI_L  x) = SECURE_RPC_COMMON_FUNC_BASE + 115 ;
  int  SECURE_RPC_ToAgent_SecureKeyBox       (RPC_tee_rpc_cmd_t)  = SECURE_RPC_COMMON_FUNC_BASE + 120 ;
  } = 0;
} = 501;

