#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include "mcp/rtk_mcp_dgst.h"


/*------------------------------------------------------------------
 * Func : MCP_MD_CTX_init
 *
 * Desc : init MCP MD context
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void MCP_MD_CTX_init(
	MCP_MD_CTX 		*ctx
	)
{
    memset(ctx, 0, sizeof(MCP_MD_CTX));
}



/*------------------------------------------------------------------
 * Func : MCP_MD_CTX_cleanup
 *
 * Desc : clean up context
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MCP_MD_CTX_cleanup(
	MCP_MD_CTX 		*ctx
	)
{
    if (ctx && ctx->md_data)
    {
        if (ctx->digest)
            ((MCP_MD*)ctx->digest)->cleanup(ctx);   // do clean up

        kfree(ctx->md_data);        // free data
    }

    return 0;
}



/*------------------------------------------------------------------
 * Func : MCP_DigestInit
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *        type : tpye of md engine
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MCP_DigestInit(
	MCP_MD_CTX* 		ctx,
	const MCP_MD* 	type
	)
{
    ctx->digest = (MCP_MD*) type;
    ctx->md_data = kmalloc(type->ctx_size, GFP_KERNEL);
    return type->init(ctx);
}



/*------------------------------------------------------------------
 * Func : MCP_DigestUpdate
 *
 * Desc : Update MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *        mcpb : data to be proc
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MCP_DigestUpdate(
    MCP_MD_CTX*       	ctx,
    MCP_BUFF*           	mcpb
    )
{
    return (ctx && ctx->digest) ? ((MCP_MD*)ctx->digest)->update(ctx, mcpb) : -1;
}




/*------------------------------------------------------------------
 * Func : MCP_DigestFinal
 *
 * Desc : Finished MCP Digest and output the hash value
 *
 * Parm : ctx       : context of md ctx
 *        pHash     : digest output
 *        pHashLen  : size of digest
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MCP_DigestFinal(
    MCP_MD_CTX*         	ctx,
    unsigned char*       	pHash,
    unsigned int*         	pHashLen
    )
{
    if ( ctx != NULL && ctx->digest != NULL )
    {
        *pHashLen = ((MCP_MD*)ctx->digest)->digest_sz;
        return (ctx && ctx->digest) ? ((MCP_MD*)ctx->digest)->final(ctx, pHash) : -1;
    }
    else
    {
        printk("[MCP][MCP_DigestFinal] Err, bad parameter, null pointer of ctx or ctx->digest\n");
        return -1;
    }
}




/*------------------------------------------------------------------
 * Func : MCP_DigestPeek
 *
 * Desc : Read out the hash value
 *
 * Parm : ctx       : context of md ctx
 *        pHash     : digest output
 *        pHashLen  : size of digest
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MCP_DigestPeek(
    MCP_MD_CTX*         	ctx,
    unsigned char*      	pHash,
    unsigned int*       	pHashLen
    )
{
    if ( ctx != NULL && ctx->digest != NULL )
    {
        *pHashLen = ((MCP_MD*)ctx->digest)->digest_sz;
        return (ctx && ctx->digest) ? ((MCP_MD*)ctx->digest)->peek(ctx, pHash) : -1;
    }
    else
    {
        printk("[MCP][MCP_DigestFinal] Err, bad parameter, null pointer of ctx or ctx->digest\n");
        return -1;
    }
}



/*------------------------------------------------------------------
 * Func : MCP_get_digestbyname
 *
 * Desc : get MCP_MD by name
 *
 * Parm : name : name of the algorithm
 *
 * Retn : handle of MCP MD
 *------------------------------------------------------------------*/
MCP_MD* MCP_get_digestbyname(
	const char* 		name
	)
{
    if (strcmp(name,"aes_h")==0)
        return MCP_aes_h();

    if (strcmp(name,"mars_aes_h")==0)
        return MCP_mars_aes_h();

    return NULL;
}
