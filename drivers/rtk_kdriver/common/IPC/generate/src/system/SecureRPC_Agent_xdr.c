/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <SecureRPC_Agent.h>
#include <RPCBaseDS.h>
#include <SecureRPCBaseDS.h>

bool_t
xdr_RPC_tee_rpc_result_t (XDR *xdrs, RPC_tee_rpc_result_t *objp)
{
	 if (!xdr_RPC_RtkDrmCode (xdrs, &objp->func_code))
		 return FALSE;
	 if (!xdr_u_long (xdrs, &objp->result))
		 return FALSE;
	 if (!xdr_u_long (xdrs, &objp->pSharedMem))
		 return FALSE;
	 if (!xdr_u_long (xdrs, &objp->sharedMemSize))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SECURE_RPC_TOSYSTEM_GET_SETUP_PARAM (XDR *xdrs, SECURE_RPC_TOSYSTEM_GET_SETUP_PARAM *objp)
{
	 if (!xdr_long (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->reserved0))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->reserved1))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SECURE_RPC_TOSYSTEM_SET_PARAM (XDR *xdrs, SECURE_RPC_TOSYSTEM_SET_PARAM *objp)
{
	 if (!xdr_long (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->data, 5,
		sizeof (long), (xdrproc_t) xdr_long))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_RPCRES_K_S (XDR *xdrs, RPCRES_K_S *objp)
{
	 if (!xdr_HRESULT (xdrs, &objp->result))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->data, 10,
		sizeof (long), (xdrproc_t) xdr_long))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SECURE_RPC_TOSYSTEM_SEND_RW (XDR *xdrs, SECURE_RPC_TOSYSTEM_SEND_RW *objp)
{
	 if (!xdr_long (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->data, 16,
		sizeof (long), (xdrproc_t) xdr_long))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SECURE_RPC_TOSYSTEM_TVSERVER_CTRL (XDR *xdrs, SECURE_RPC_TOSYSTEM_TVSERVER_CTRL *objp)
{
	 if (!xdr_long (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->cmd, 100,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_SECURE_RPC_TOSYSTEM_OSD_MSG (XDR *xdrs, SECURE_RPC_TOSYSTEM_OSD_MSG *objp)
{
	 if (!xdr_long (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_long (xdrs, &objp->size))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->data, 200,
		sizeof (long), (xdrproc_t) xdr_long))
		 return FALSE;
	return TRUE;
}
