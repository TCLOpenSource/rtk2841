#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_buff.h"
#include "mcp/rtk_mcp_dgst.h"

#include "sha1.h"


void SHA1_CTX_Init(SHA1_CTX* ctx)
{
    static const unsigned char SHA1InitHash[20] = {
        0x67, 0x45, 0x23, 0x01, 0xEF, 0xCD, 0xAB, 0x89,
        0x98, 0xBA, 0xDC, 0xFE, 0x10, 0x32, 0x54, 0x76,
        0xC3, 0xD2, 0xE1, 0xF0
    };

    memcpy(ctx->hash, SHA1InitHash, 20);     // Init Hash value
    ctx->byte_count = 0;
    mcpb_purge(ctx->tmp);
}



/*------------------------------------------------------------------
 * Func : SHA1_DigestInit
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA1_DigestInit(MCP_MD_CTX* ctx)
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;

    if (p_sha1)
    {
        p_sha1->tmp = alloc_mcpb(64);              // alloc a buffer that used to restore short block
        if (!p_sha1->tmp)
            return -1;

        SHA1_CTX_Init(p_sha1);
        return 0;
    }

    return -1;
}




/*------------------------------------------------------------------
 * Func : SHA1_DigestUpdate
 *
 * Desc : Update SHA1 Digest
 *
 * Parm : ctx     : context of md ctx
 *        pData   :
 *        DataLen : Data Length
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA1_DigestUpdate(
    MCP_MD_CTX*             ctx,
    MCP_BUFF*               mcpb
    )
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;
    mcp_desc desc;

    MCP_SHA1_HASH_INIT(&desc);

    MCP_SHA1_IV_UPDATE(&desc, p_sha1->hash);    // Setup the initial value of SHA1 Hash Value

    //-----------------------------------------------
    // short block handling
    //-----------------------------------------------
    if (p_sha1->tmp->len)
    {
        mcpb_push(mcpb, p_sha1->tmp->len);
        memcpy(mcpb->data, p_sha1->tmp->data, p_sha1->tmp->len);
        mcpb_purge(p_sha1->tmp);                                     // clean data buffer
    }

    if (mcpb->len > 64)
    {
        //mcp_dump_data_with_text(mcpb->data, mcpb->len, "data to proc ...");

        MCP_SHA1_Hashing(&desc, mcpb->data, mcpb->len & ~0x3F, p_sha1->hash);   // compute new hash value
        p_sha1->byte_count += mcpb->len & ~0x3F;
        mcpb_pull(mcpb, mcpb->len & ~0x3F);
    }

    //-----------------------------------------------
    // short block handling - backup imcomplete data block
    //-----------------------------------------------
    if (mcpb->len)
    {
        memcpy(p_sha1->tmp->data, mcpb->data ,mcpb->len);
        mcpb_put(p_sha1->tmp, mcpb->len);
    }

    return 0;
}



/*------------------------------------------------------------------
 * Func : SHA1_DigestFinal
 *
 * Desc : Finished SHA1 Digest
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA1_DigestFinal(
    MCP_MD_CTX*             ctx,
    unsigned char*          pHash
    )
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;
    int pad_sz;
    mcp_desc desc;

    MCP_SHA1_HASH_INIT(&desc);

    MCP_SHA1_IV_UPDATE(&desc, p_sha1->hash);    // Setup the initial value of SHA1 Hash Value

    pad_sz = MCP_SHA1_PADDING(p_sha1->tmp->tail, mcpb_tailroom(p_sha1->tmp), p_sha1->byte_count + p_sha1->tmp->len);           // byte count = proccessed byte count + unproced byte count

    //mcp_dump_data_with_text(p_sha1->tmp->tail, pad_sz, "padding data ...");

    mcpb_put(p_sha1->tmp, pad_sz);

    MCP_SHA1_Hashing(&desc, p_sha1->tmp->data, p_sha1->tmp->len, p_sha1->hash);     // compute new hash value

    memcpy(pHash, p_sha1->hash, 20);

    //---------------------- reset ctx -------------------

    SHA1_CTX_Init(p_sha1);

    return 0;
}




/*------------------------------------------------------------------
 * Func : SHA1_DigestPeek
 *
 * Desc : Peek current Hash value
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA1_DigestPeek(
    MCP_MD_CTX*             ctx,
    unsigned char*          pHash
    )
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;
    memcpy(pHash, p_sha1->hash, 20);
    return 0;
}




/*------------------------------------------------------------------
 * Func : SHA1_DigestCleanup
 *
 * Desc : Clean up SHA1 context
 *
 * Parm : ctx  : context of md ctx
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int SHA1_DigestCleanup(MCP_MD_CTX* ctx)
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;
    free_mcpb(p_sha1->tmp);
    memset(p_sha1, 0, sizeof(SHA1_CTX));
    return 0;
}


static const MCP_MD sha1_md =
{
    .type       = MCP_MD_SHA1,
    .digest_sz  = 20,
    .block_size = 64,
    .ctx_size   = sizeof(SHA1_CTX),
    .init       = SHA1_DigestInit,
    .update     = SHA1_DigestUpdate,
    .final      = SHA1_DigestFinal,
    .peek       = SHA1_DigestPeek,
    .cleanup    = SHA1_DigestCleanup,
};


MCP_MD *MCP_sha1(void)
{
    return (MCP_MD*) &sha1_md;
}



///////////////////////////////////////////////////////////////////////////////////
// for MARS SHA_1 generation
///////////////////////////////////////////////////////////////////////////////////



/*------------------------------------------------------------------
 * Func : MARS_SHA1_DigestUpdate
 *
 * Desc : Update SHA1 Digest
 *
 * Parm : ctx     : context of md ctx
 *        pData   :
 *        DataLen : Data Length
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MARS_SHA1_DigestUpdate(
    MCP_MD_CTX*             ctx,
    MCP_BUFF*               mcpb
    )
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;
    mcp_desc desc;
    int pad_sz;

    MCP_SHA1_HASH_INIT(&desc);

    // padding header ... (for hash value propagation)
    if (p_sha1->byte_count)
        memcpy(mcpb_push(mcpb, 20), p_sha1->hash, 20);

    // padding tail...
    pad_sz = MCP_SHA1_PADDING(mcpb->tail, mcpb_tailroom(mcpb), mcpb->len);

    mcpb_put(mcpb, pad_sz);

    // compute hash data ...
    //mcp_dump_data_with_text(mcpb->data, mcpb->len, "data to proc ...");

    MCP_SHA1_Hashing(&desc, mcpb->data, mcpb->len, p_sha1->hash);   // compute new hash value

    //mcp_dump_data_with_text(p_sha1->hash, 20, "data to proc ...");

    p_sha1->byte_count += mcpb->len;

    return 0;
}




/*------------------------------------------------------------------
 * Func : MARS_SHA1_DigestFinal
 *
 * Desc : Finished SHA1 Digest
 *
 * Parm : ctx      : context of md ctx
 *        pHash    : Hash value output
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MARS_SHA1_DigestFinal(
    MCP_MD_CTX*             ctx,
    unsigned char*          pHash
    )
{
    SHA1_CTX* p_sha1 = (SHA1_CTX*) ctx->md_data;
    memcpy(pHash, p_sha1->hash, 20);

    //---
    SHA1_CTX_Init(p_sha1);
    return 0;
}


static const MCP_MD Mars_sha1_md =
{
    .type       = MCP_MD_SHA1,
    .digest_sz  = 20,
    .block_size = 64,
    .ctx_size   = sizeof(SHA1_CTX),
    .init       = SHA1_DigestInit,
    .update     = MARS_SHA1_DigestUpdate,
    .final      = MARS_SHA1_DigestFinal,
    .peek       = SHA1_DigestPeek,
    .cleanup    = SHA1_DigestCleanup,
};



MCP_MD *MCP_mars_sha1(void)
{
    return (MCP_MD*) &Mars_sha1_md;
}



#if 0       // for test only

/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/



static void SHA1_HashTest(void)
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

        MCP_DigestInit(&ctx, MCP_mars_sha1());

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
static int __init mcp_sha1_module_init(void)
{
    SHA1_HashTest();

    return 0;
}


module_init(mcp_sha1_module_init);

#endif
