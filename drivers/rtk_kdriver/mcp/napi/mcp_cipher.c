#include <linux/kernel.h>
#include <linux/slab.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_cipher.h"




/*------------------------------------------------------------------
 * Func : MCP_CIPHER_CTX_init
 *
 * Desc : init MCP MD context
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void MCP_CIPHER_CTX_init(
	MCP_CIPHER_CTX 		*ctx
	)
{
    memset(ctx, 0, sizeof(MCP_CIPHER_CTX));
}



/*------------------------------------------------------------------
 * Func : MCP_CIPHER_CTX_cleanup
 *
 * Desc : clean up context
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int MCP_CIPHER_CTX_cleanup(
	MCP_CIPHER_CTX 		*ctx
	)
{
    if (ctx && ctx->cipher_data)
    {
        if (ctx->cipher)
            ((MCP_CIPHER*)ctx->cipher)->cleanup(ctx);

        kfree(ctx->cipher_data);        // free cipher data

        memset(ctx, 0, sizeof(MCP_CIPHER_CTX));
    }

    return 0;
}



/*------------------------------------------------------------------
 * Func : MCP_CipherInit
 *
 * Desc : Initial MCP Cipher
 *
 * Parm : ctx  : context of md ctx
 *        type : tpye of md engine
 *        key  : key of cipher
 *        iv   : initial vector
 *        enc  : 1 : encryption, 0 decryption
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_CipherInit(
    MCP_CIPHER_CTX*  		ctx,
    const MCP_CIPHER*		type,
    unsigned char*          	key,
    unsigned char*          	iv,
    int                     	enc
    )
{
    ctx->cipher      = (void*) type;
    ctx->cipher_data = kmalloc(type->ctx_size, GFP_KERNEL);
    ctx->buff_len    = 0;
    return type->init(ctx, key, iv, enc);
}



/*------------------------------------------------------------------
 * Func : MCP_CipherUpdate
 *
 * Desc : Update MCP Cipher
 *
 * Parm : ctx  : context of md ctx
 *        in   : input data buffer
 *        len  : length of input data buffer
 *        out  : output data buffer
 *
 * Retn : < 0 : failed , ohers: output data length
 *------------------------------------------------------------------*/
int MCP_CipherUpdate(
    MCP_CIPHER_CTX* 		ctx,
    unsigned char*          	in,
    unsigned long           	len,
    unsigned char*          	out
    )
{
    MCP_CIPHER* cipher = (MCP_CIPHER*) ctx->cipher;
    int outl = 0;
    int ret;

    if (ctx->buff_len)
    {
        if (ctx->buff_len + len < cipher->block_size )
        {
            memcpy(&ctx->buff[ctx->buff_len], in, len);
            ctx->buff_len += len;
            return 0;
        }
        else
        {
            ret =  cipher->block_size - ctx->buff_len;
            memcpy(&ctx->buff[ctx->buff_len], in, ret);
            in  += ret;
            len -= ret;

            if ((ret = cipher->do_cipher(ctx, ctx->buff,  cipher->block_size, out))<0)
                return ret;

            ctx->buff_len = 0;

            out += ret;
            outl+= ret;
        }
    }

    if (len)
    {
        if ((ret = cipher->do_cipher(ctx, in, len, out)) < 0)
            return ret;

        in   += ret;
        len  -= ret;
        outl += ret;

        if (len)             // backup short block
        {
            memcpy(ctx->buff, in, len);
            ctx->buff_len = len;
        }
    }

    return outl;
}



/*------------------------------------------------------------------
 * Func : MCP_CipherFinal
 *
 * Desc : Finished MCP Digest and output the remain data
 *
 * Parm : ctx       : context of md ctx
 *        out       : cipher test output
 *
 * Retn : size of remain data
 *------------------------------------------------------------------*/
int MCP_CipherFinal(
    MCP_CIPHER_CTX* 		ctx,
    unsigned char*         	out
    )
{
    int len = ctx->buff_len;

    if (len)
    {
        ctx->buff_len = 0;
        memcpy(out, ctx->buff, len);
    }

    return len;
}



/*------------------------------------------------------------------
 * Func : MCP_CipherPeekIV
 *
 * Desc : Get curent iv of the MCP cipher
 *
 * Parm : ctx      : context of md ctx
 *        iv       : cipher test output
 *
 * Retn : size of iv
 *------------------------------------------------------------------*/
int MCP_CipherPeekIV(
    MCP_CIPHER_CTX* 		ctx,
    unsigned char*          	out
    )
{
    MCP_CIPHER* cipher = (MCP_CIPHER*) ctx->cipher;
    return cipher->peek_iv(ctx, out);
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
MCP_CIPHER* MCP_get_cipherbyname(
	const char* 		name
	)
{
    if (strcmp(name,"aes_128_ecb")==0)
        return MCP_aes_128_ecb();

    if (strcmp(name,"aes_128_cbc")==0)
        return MCP_aes_128_cbc();

    if (strcmp(name,"aes_128_ctr")==0)
        return MCP_aes_128_ctr();
   
#ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA
    if (strcmp(name,"camellia_128_ecb")==0)
        return MCP_cam_128_ecb();

    if (strcmp(name,"camellia_128_cbc")==0)
        return MCP_cam_128_cbc();

    if (strcmp(name,"camellia_128_ctr")==0)
        return MCP_cam_128_ctr();
#endif
 
    if (strcmp(name,"des_ecb")==0)
        return MCP_des_ecb();

    if (strcmp(name,"des_cbc")==0)
        return MCP_des_cbc();

    if (strcmp(name,"tdes_ecb")==0)
        return MCP_tdes_ecb();

    if (strcmp(name,"tdes_cbc")==0)
        return MCP_tdes_cbc();

    return NULL;
}



/*------------------------------------------------------------------
 * Func : MCP_CipherDataSimple
 *
 * Desc : do one shot data cipher
 *
 * Parm : cipher : type of MCP cipher
 *        key    : key of cipher
 *        iv     : iv of cipher
 *        enc    : enc / dec
 *        in     : input data
 *        len    : input data len
 *        out    : output data len
 *
 * Retn : number of bytes output
 *------------------------------------------------------------------*/
int MCP_CipherDataSimple(
    const MCP_CIPHER* 		cipher,
    unsigned char*          	key,
    unsigned char*          	iv,
    int                     	enc,
    unsigned char*          	in,
    unsigned long           	len,
    unsigned char*          	out
    )
{
    MCP_CIPHER_CTX ctx;
    int ret = 0;

    MCP_CIPHER_CTX_init(&ctx);

    MCP_CipherInit(&ctx, cipher, key, iv, enc);

    ret =  MCP_CipherUpdate(&ctx, in, len, out);

    ret += MCP_CipherFinal(&ctx, &out[ret]);

    MCP_CIPHER_CTX_cleanup(&ctx);

    return ret;
}


