#include <RPCstruct.h>

/*
 * XDR type of struct RPC_STRUCT
 */
bool_t
xdr_RPC_STRUCT (XDR *xdrs, RPC_STRUCT *objp)
{
    if (!xdr_u_long (xdrs, &objp->programID))
        return FALSE;
    if (!xdr_u_long (xdrs, &objp->versionID))
        return FALSE;
    if (!xdr_u_long (xdrs, &objp->procedureID))
        return FALSE;
    if (!xdr_u_long (xdrs, &objp->taskID))
        return FALSE;
#ifdef RTD_1195
    if (!xdr_u_long (xdrs, &objp->sysPID))
        return FALSE;
#endif
    if (!xdr_u_long (xdrs, &objp->parameterSize))
        return FALSE;
    if (!xdr_u_int (xdrs, &objp->context))
        return FALSE;

    return TRUE;
};



/*
 * assign user's setting value into the CLNT_STRUCT
 */
CLNT_STRUCT
prepareCLNT (int opt, long programID, long versionID) {

    CLNT_STRUCT clnt;

    clnt.sendMode = opt;

    clnt.programID = programID;
    clnt.versionID = versionID;
#ifdef RTD_1195
if ((opt & SEND_AUDIO_CPU) ||(opt & SEND_VIDEO_CPU2) )
	clnt.sysPID = (int)getpid();
#ifdef ENABLE_KCPU_COMMON
else if(opt & SEND_SECURE_CPU)
	clnt.sysPID = 0xffffffff;
#endif
else
	clnt.sysPID = (int)getpid();
#endif

    return clnt;
}

#ifdef RTD_1195
CLNT_STRUCT
prepareCLNT2 (int opt, long programID, long versionID, long sysPID) {

    CLNT_STRUCT clnt;

    clnt.sendMode = opt;

    clnt.programID = programID;
    clnt.versionID = versionID;
    clnt.sysPID = sysPID;

    return clnt;
}
#endif
