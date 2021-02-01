
#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_buff.h"
#include "mcp/rtk_mcp_dgst.h"

#include "sha256.h"



void SHA256_CTX_Init(SHA256_CTX* ctx)
{
    static const unsigned char SHA256InitHash[SHA256_DIGEST_SIZE] = {
        0x6a, 0x09, 0xe6, 0x67, 0xbb, 0x67, 0xae, 0x85,
        0x3c, 0x6e, 0xf3, 0x72, 0xa5, 0x4f, 0xf5, 0x3a,
        0x51, 0x0e, 0x52, 0x7f, 0x9b, 0x05, 0x68, 0x8c,
        0x1f, 0x83, 0xd9, 0xab, 0x5b, 0xe0, 0xcd, 0x19,
    };

    memcpy(ctx->hash, SHA256InitHash, SHA256_DIGEST_SIZE);     // Init Hash value
    ctx->byte_count = 0;
    mcpb_purge(ctx->tmp);
}



/*------------------------------------------------------------------
 * Func : SHA256_DigestInit
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA256_DigestInit(MCP_MD_CTX* ctx)
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;

    if (p_SHA256)
    {
        p_SHA256->tmp = alloc_mcpb(64);              // alloc a buffer that used to restore short block
        if (!p_SHA256->tmp)
            return -1;

        SHA256_CTX_Init(p_SHA256);
        return 0;
    }

    return -1;
}




/*------------------------------------------------------------------
 * Func : SHA256_DigestUpdate
 *
 * Desc : Update SHA256 Digest
 *
 * Parm : ctx     : context of md ctx
 *        pData   :
 *        DataLen : Data Length
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA256_DigestUpdate(
    MCP_MD_CTX*             ctx,
    MCP_BUFF*               mcpb
    )
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;
    mcp_desc desc;

    MCP_SHA256_HASH_INIT(&desc);

    MCP_SHA256_IV_UPDATE(&desc, p_SHA256->hash);    // Setup the initial value of SHA256 Hash Value

    //-----------------------------------------------
    // short block handling
    //-----------------------------------------------
    if (p_SHA256->tmp->len)
    {
        mcpb_push(mcpb, p_SHA256->tmp->len);
        memcpy((void *)mcpb->data, (void*)p_SHA256->tmp->data, p_SHA256->tmp->len);
        mcpb_purge(p_SHA256->tmp);                                     // clean data buffer
    }

    if (mcpb->len > 64)
    {
        //mcp_dump_data_with_text(mcpb->data, mcpb->len, "data to proc ...");

        MCP_SHA256_Hashing(&desc, mcpb->data, mcpb->len & ~0x3F, p_SHA256->hash);   // compute new hash value
        p_SHA256->byte_count += mcpb->len & ~0x3F;
        mcpb_pull(mcpb, mcpb->len & ~0x3F);
    }

    //-----------------------------------------------
    // short block handling - backup imcomplete data block
    //-----------------------------------------------
    if (mcpb->len)
    {
        memcpy((void *)p_SHA256->tmp->data, (void *)mcpb->data ,mcpb->len);
        mcpb_put(p_SHA256->tmp, mcpb->len);
    }

    return 0;
}



/*------------------------------------------------------------------
 * Func : SHA256_DigestFinal
 *
 * Desc : Finished SHA256 Digest
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA256_DigestFinal(
    MCP_MD_CTX*             ctx,
    unsigned char*          pHash
    )
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;
    int pad_sz;
    mcp_desc desc;

    MCP_SHA256_HASH_INIT(&desc);

    MCP_SHA256_IV_UPDATE(&desc, p_SHA256->hash);    // Setup the initial value of SHA256 Hash Value

    pad_sz = MCP_SHA256_PADDING(p_SHA256->tmp->tail, mcpb_tailroom(p_SHA256->tmp), p_SHA256->byte_count + p_SHA256->tmp->len);           // byte count = proccessed byte count + unproced byte count

    //mcp_dump_data_with_text(p_SHA256->tmp->tail, pad_sz, "padding data ...");

    mcpb_put(p_SHA256->tmp, pad_sz);

    MCP_SHA256_Hashing(&desc, p_SHA256->tmp->data, p_SHA256->tmp->len, p_SHA256->hash);     // compute new hash value

    memcpy(pHash, p_SHA256->hash, SHA256_DIGEST_SIZE);

    //---------------------- reset ctx -------------------

    SHA256_CTX_Init(p_SHA256);

    return 0;
}




/*------------------------------------------------------------------
 * Func : SHA256_DigestPeek
 *
 * Desc : Peek current Hash value
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA256_DigestPeek(
    MCP_MD_CTX*             ctx,
    unsigned char*          pHash
    )
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;
    memcpy(pHash, p_SHA256->hash, SHA256_DIGEST_SIZE);
    return 0;
}




/*------------------------------------------------------------------
 * Func : SHA256_DigestCleanup
 *
 * Desc : Clean up SHA256 context
 *
 * Parm : ctx  : context of md ctx
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA256_DigestCleanup(MCP_MD_CTX* ctx)
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;
    free_mcpb(p_SHA256->tmp);
    memset(p_SHA256, 0, sizeof(SHA256_CTX));
    return 0;
}


static const MCP_MD SHA256_md =
{
    .type       = MCP_MD_SHA256,
    .digest_sz  = SHA256_DIGEST_SIZE,
    .block_size = 64,
    .ctx_size   = sizeof(SHA256_CTX),
    .init       = SHA256_DigestInit,
    .update     = SHA256_DigestUpdate,
    .final      = SHA256_DigestFinal,
    .peek       = SHA256_DigestPeek,
    .cleanup    = SHA256_DigestCleanup,
};


MCP_MD *MCP_sha256(void)
{
    return (MCP_MD*) &SHA256_md;
}



///////////////////////////////////////////////////////////////////////////////////
// for MARS SHA256 generation
///////////////////////////////////////////////////////////////////////////////////



/*------------------------------------------------------------------
 * Func : MARS_SHA256_DigestUpdate
 *
 * Desc : Update SHA256 Digest
 *
 * Parm : ctx     : context of md ctx
 *        pData   :
 *        DataLen : Data Length
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MARS_SHA256_DigestUpdate(
    MCP_MD_CTX*             ctx,
    MCP_BUFF*               mcpb
    )
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;
    mcp_desc desc;
    int pad_sz;

    MCP_SHA256_HASH_INIT(&desc);

    // padding header ... (for hash value propagation)
    if (p_SHA256->byte_count)
        memcpy(mcpb_push(mcpb, SHA256_DIGEST_SIZE), p_SHA256->hash, SHA256_DIGEST_SIZE);

    // padding tail...
    pad_sz = MCP_SHA256_PADDING(mcpb->tail, mcpb_tailroom(mcpb), mcpb->len);

    mcpb_put(mcpb, pad_sz);

    // compute hash data ...
    //mcp_dump_data_with_text(mcpb->data, mcpb->len, "data to proc ...");

    MCP_SHA256_Hashing(&desc, mcpb->data, mcpb->len, p_SHA256->hash);   // compute new hash value

    //mcp_dump_data_with_text(p_SHA256->hash, SHA256_DIGEST_SIZE, "data to proc ...");

    p_SHA256->byte_count += mcpb->len;

    return 0;
}




/*------------------------------------------------------------------
 * Func : MARS_SHA256_DigestFinal
 *
 * Desc : Finished SHA256 Digest
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MARS_SHA256_DigestFinal(
    MCP_MD_CTX*             ctx,
    unsigned char*          pHash
    )
{
    SHA256_CTX* p_SHA256 = (SHA256_CTX*) ctx->md_data;
    memcpy(pHash, p_SHA256->hash, SHA256_DIGEST_SIZE);

    //---
    SHA256_CTX_Init(p_SHA256);
    return 0;
}


static const MCP_MD Mars_SHA256_md =
{
    .type       = MCP_MD_SHA256,
    .digest_sz  = SHA256_DIGEST_SIZE,
    .block_size = 64,
    .ctx_size   = sizeof(SHA256_CTX),
    .init       = SHA256_DigestInit,
    .update     = MARS_SHA256_DigestUpdate,
    .final      = MARS_SHA256_DigestFinal,
    .peek       = SHA256_DigestPeek,
    .cleanup    = SHA256_DigestCleanup,
};



MCP_MD *MCP_mars_sha256(void)
{
    return (MCP_MD*) &Mars_SHA256_md;
}



#if 0        // for test only

/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/



static void SHA256_HashTest(void)
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

        MCP_DigestInit(&ctx, MCP_mars_sha256());

        MCP_DigestUpdate(&ctx, pBuff);

        MCP_DigestFinal(&ctx, Hash, &HashLen);            // read out hash value

        MCP_MD_CTX_cleanup(&ctx);

        mcp_dump_data_with_text(Hash, HashLen, "[MCP] SAH1 hash value : ");
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
static int __init mcp_SHA256_module_init(void)
{
    SHA256_HashTest();

    return 0;
}


module_init(mcp_SHA256_module_init);

#endif
