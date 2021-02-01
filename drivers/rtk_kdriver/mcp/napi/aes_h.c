#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_dgst.h"

#include "aes_h.h"



void AES_H_CTX_Init(
	AES_H_CTX* 		ctx
	)
{
    static const unsigned char AES_H_InitHash[] = {
        0x2D, 0xC2, 0xDF, 0x39, 0x42, 0x03, 0x21, 0xD0,
        0xCE, 0xF1, 0xFE, 0x23, 0x74, 0x02, 0x9D, 0x95,
    };

    memcpy(ctx->hash, AES_H_InitHash, 16);     // Init Hash value
    ctx->byte_count = 0;
    mcpb_purge(ctx->tmp);
}



/*------------------------------------------------------------------
 * Func : AES_H_DigestInit
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_H_DigestInit(
	MCP_MD_CTX* 		ctx
	)
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;

    if (p_aesh)
    {
        p_aesh->tmp = alloc_mcpb(16);

        if (!p_aesh->tmp)
            return -1;

        AES_H_CTX_Init(p_aesh);
        return 0;
    }

    return -1;
}




/*------------------------------------------------------------------
 * Func : AES_H_DigestUpdate
 *
 * Desc : Update AES_H Digest
 *
 * Parm : ctx     : context of md ctx
 *        pData   :
 *        DataLen : Data Length
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_H_DigestUpdate(
    MCP_MD_CTX*       	ctx,
    MCP_BUFF*            	mcpb
    )
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;

    mcp_desc desc;

    MCP_AES_H_HASH_INIT(&desc);

    MCP_AES_H_IV_UPDATE(&desc, p_aesh->hash);    // Setup the initial value of AES_H Hash Value

    //-----------------------------------------------
    // short block handling
    //-----------------------------------------------
    if (p_aesh->tmp->len)
    {
        mcpb_push(mcpb, p_aesh->tmp->len);
        memcpy(mcpb->data, p_aesh->tmp->data, p_aesh->tmp->len);
        mcpb_purge(p_aesh->tmp);                                     // clean data buffer
    }

    if (mcpb->len > 16)
    {
        MCP_AES_H_Hashing(&desc, mcpb->data, mcpb->len & ~0xF, p_aesh->hash);   // compute new hash value
        p_aesh->byte_count += mcpb->len & ~0xF;
        mcpb_pull(mcpb, mcpb->len & ~0xF);
    }

    //-----------------------------------------------
    // short block handling - backup imcomplete data block
    //-----------------------------------------------
    if (mcpb->len)
    {
        memcpy(p_aesh->tmp->data, mcpb->data ,mcpb->len);
        mcpb_put(p_aesh->tmp, mcpb->len);
    }

    return 0;
}



/*------------------------------------------------------------------
 * Func : AES_H_DigestFinal
 *
 * Desc : Finished AES_H Digest
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_H_DigestFinal(
    MCP_MD_CTX*        	ctx,
    unsigned char*       	pHash
    )
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;

    int pad_sz;

    mcp_desc desc;

    MCP_AES_H_HASH_INIT(&desc);

    MCP_AES_H_IV_UPDATE(&desc, p_aesh->hash);    // Setup the initial value of AES_H Hash Value

    pad_sz = MCP_AES_H_PADDING(p_aesh->tmp->tail, mcpb_tailroom(p_aesh->tmp), p_aesh->byte_count + p_aesh->tmp->len);

    mcpb_put(p_aesh->tmp, pad_sz);              // byte count = proccessed byte count + unproced byte count

    MCP_AES_H_Hashing(&desc, p_aesh->tmp->data, p_aesh->tmp->len, p_aesh->hash);     // compute new hash value

    memcpy(pHash, p_aesh->hash, 16);

    //---------------------- reset ctx -------------------

    AES_H_CTX_Init(p_aesh);

    return 0;
}




/*------------------------------------------------------------------
 * Func : AES_H_DigestPeek
 *
 * Desc : Peek current Hash value
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_H_DigestPeek(
    MCP_MD_CTX*         	ctx,
    unsigned char*      	pHash
    )
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;
    memcpy(pHash, p_aesh->hash, 16);
    return 0;
}




/*------------------------------------------------------------------
 * Func : AES_H_DigestCleanup
 *
 * Desc : Clean up AES_H context
 *
 * Parm : ctx  : context of md ctx
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_H_DigestCleanup(
	MCP_MD_CTX* 		ctx
	)
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;
    free_mcpb(p_aesh->tmp);
    memset(p_aesh, 0, sizeof(AES_H_CTX));
    return 0;
}


static const MCP_MD aes_h_md =
{
    .type       	= MCP_MD_AES_H,
    .digest_sz  	= 16,
    .block_size 	= 16,
    .ctx_size   	= sizeof(AES_H_CTX),
    .init       	= AES_H_DigestInit,
    .update     	= AES_H_DigestUpdate,
    .final      	= AES_H_DigestFinal,
    .peek       	= AES_H_DigestPeek,
    .cleanup    	= AES_H_DigestCleanup,
};


MCP_MD *MCP_aes_h(void)
{
    return (MCP_MD*)&aes_h_md;
}




///////////////////////////////////////////////////////////////////////////////////
// for MARS AES_H generation
//
//  1) auto hardware padding at end of block, no software padding
//  2) input data has no aligment issue because of (1)
//
///////////////////////////////////////////////////////////////////////////////////



/*------------------------------------------------------------------
 * Func : MARS_AES_H_DigestUpdate
 *
 * Desc : Update AES_H Digest
 *
 * Parm : ctx     : context of md ctx
 *        pData   :
 *        DataLen : Data Length
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MARS_AES_H_DigestUpdate(
    MCP_MD_CTX*         	ctx,
    MCP_BUFF*            	mcpb
    )
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;

    mcp_desc desc;

    MCP_AES_H_HASH_INIT(&desc);

    MCP_AES_H_IV_UPDATE(&desc, p_aesh->hash);

    MCP_AES_H_Hashing(&desc, mcpb->data, mcpb->len, p_aesh->hash);

    mcpb_pull(mcpb, mcpb->len);

    return 0;
}




/*------------------------------------------------------------------
 * Func : MARS_AES_H_DigestFinal
 *
 * Desc : Finished MARS AES_H Digest
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MARS_AES_H_DigestFinal(
    MCP_MD_CTX*         	ctx,
    unsigned char*       	pHash
    )
{
    AES_H_CTX* p_aesh = (AES_H_CTX*) ctx->md_data;
    memcpy(pHash, p_aesh->hash, 16);

    AES_H_CTX_Init(p_aesh);
    return 0;
}


static const MCP_MD Mars_aes_h_md =
{
    .type       	= MCP_MD_AES_H,
    .digest_sz  	= 16,
    .block_size 	= 16,
    .ctx_size   	= sizeof(AES_H_CTX),
    .init       	= AES_H_DigestInit,
    .update     	= MARS_AES_H_DigestUpdate,
    .final      	= MARS_AES_H_DigestFinal,
    .peek       	= AES_H_DigestPeek,
    .cleanup    	= AES_H_DigestCleanup,
};



MCP_MD *MCP_mars_aes_h(void)
{
    return (MCP_MD*)&Mars_aes_h_md;
}





/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/

#if 0

static void AES_H_HashTest(void)
{
    MCP_MD_CTX    ctx;
    MCP_BUFF*     pBuff;
    unsigned char Hash[MCP_MAX_DIGEST_SIZE];
    unsigned int  HashLen;

    pBuff = alloc_mcpb(256);

    if (pBuff)
    {
        // setup data
        memset(pBuff->data, 0x33, 256);
        mcpb_put(pBuff, 256);

        // start
        MCP_MD_CTX_init(&ctx);

        MCP_DigestInit(&ctx, MCP_mars_aes_h());

        MCP_DigestUpdate(&ctx, pBuff);

        MCP_DigestFinal(&ctx, Hash, &HashLen);            // read out hash value

        MCP_MD_CTX_cleanup(&ctx);

        mcp_dump_data_with_text(Hash, HashLen, "AES_H hash value : ");
    }

    free_mcpb(pBuff);
}



/*------------------------------------------------------------------
 * Func : mcp_aesh_module_init
 *
 * Desc : mcp module init function
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static int __init mcp_aesh_module_init(void)
{
    AES_H_HashTest();
    return 0;
}


module_init(mcp_aesh_module_init);

#endif
