#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>

#include "mcp/rtk_mcp_cipher.h"
#include "mcp/rtk_mcp_dbg.h"
#include "aes.h"

/*------------------------------------------------------------------
 * Func : AES_Init
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_Init(
    MCP_CIPHER_CTX*   		ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	mode,
    int                     	enc
    )
{
    AES_CTX* p_aes = (AES_CTX*) ctx->cipher_data;

    memset(p_aes, 0, sizeof(AES_CTX));

    switch(mode)
    {
    	case MCP_CIPH_ECB_MODE:
        	p_aes->mode = MCP_BCM_ECB;
        	break;

    	case MCP_CIPH_CBC_MODE:
        	p_aes->mode = MCP_BCM_CBC;
        	break;

    	case MCP_CIPH_CTR_MODE:
        	p_aes->mode = MCP_BCM_CTR;
        	break;

    	default:
        	return -1;
    }

    p_aes->enc = (enc) ? 1 : 0;
    p_aes->ecnt_ofst = 0;

    if ((unsigned long)key > MCP_MAX_CW_ENTRY)
    {
        p_aes->key = p_aes->buff[0];
        memcpy(p_aes->buff[0], key, 16);
    }
    else if((unsigned long)key <= MCP_MAX_CW_ENTRY)
    {
        p_aes->key = (unsigned char*)key;
    }


    if (iv)
    {
        p_aes->iv = p_aes->buff[1];
        memcpy(p_aes->buff[1], iv, 16);
    }
    else
    {
        p_aes->iv = p_aes->buff[1];
    }

    return 0;
}



 /*------------------------------------------------------------------
 * Func : AES_DoCipher
 *
 * Desc : Do Cipher
 *
 * Parm : ctx       : context of cipher
 *        in        : input data buffer
 *        len       : size of input data buffer
 *        out       : output data buffer
 *
 * Retn : output data length
 *------------------------------------------------------------------*/
int AES_DoCipher(
    MCP_CIPHER_CTX*   		ctx,
    unsigned char*          	in,
    unsigned long           	len,
    unsigned char*          	out
    )
{
    AES_CTX* p_aes = (AES_CTX*) ctx->cipher_data;
    unsigned char iv[16];

    len &= ~0xF;

    if (len)
    {
        if (p_aes->enc)
        {
            MCP_AES_Encryption(p_aes->mode, p_aes->key, p_aes->iv, in, out, len);

            if (p_aes->mode==MCP_BCM_CBC)
                memcpy(p_aes->iv, out + len - 16, 16);      // save iv
        }
        else
        {
            memcpy(iv, p_aes->iv, 16);

            if (p_aes->mode==MCP_BCM_CBC)
                memcpy(p_aes->iv, in + len - 16, 16);      // save iv

            MCP_AES_Decryption(p_aes->mode, p_aes->key, iv, in, out, len);
        }
    }

    return len;
}



/*------------------------------------------------------------------
 * Func : AES_Cleanup
 *
 * Desc : Finished MCP Digest and output the remain data
 *
 * Parm : ctx       : context of cipher ctx
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int AES_Cleanup(
	MCP_CIPHER_CTX* 		ctx
	)
{
    // do nothing
    return 0;
}



/*------------------------------------------------------------------
 * Func : AES_PeekIV
 *
 * Desc : Get current IV
 *
 * Parm : ctx       : context of cipher ctx
 *        out       : iv output
 *
 * Retn : size of iv
 *------------------------------------------------------------------*/
int AES_PeekIV(
	MCP_CIPHER_CTX* 		ctx,
	unsigned char* 			out
	)
{
    AES_CTX* p_aes = (AES_CTX*) ctx->cipher_data;
    int ret = 0;

    switch(p_aes->mode)
    {
    	case MCP_BCM_CBC:
    	case MCP_BCM_CTR:
        	memcpy(out, p_aes->iv, 16);      // output iv
        	ret = 16;
        	break;
		default:
			break;
    }

    return ret;
}


/***************************************************************************
     ECB mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : AES_128_ECB_Init
 *
 * Desc : Initial AES 128 ECB Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_128_ECB_Init(
    MCP_CIPHER_CTX* 		ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return AES_Init(ctx, key, NULL, MCP_CIPH_ECB_MODE, enc);
}


static const MCP_CIPHER aes_128_ecb =
{
    .block_size	= 16,
    .iv_len     	= 0,
    .ctx_size   	= sizeof(AES_CTX),
    .init       	= AES_128_ECB_Init,
    .do_cipher  	= AES_DoCipher,
    .peek_iv    	= AES_PeekIV,
    .cleanup    	= AES_Cleanup,
};



MCP_CIPHER *MCP_aes_128_ecb(void)
{
    return (MCP_CIPHER*)&aes_128_ecb;
}


/***************************************************************************
     CBC mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : AES_128_CBC_Init
 *
 * Desc : Initial AES 128 CBC Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_128_CBC_Init(
    MCP_CIPHER_CTX*     	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return AES_Init(ctx, key, iv, MCP_CIPH_CBC_MODE, enc);
}


static const MCP_CIPHER aes_128_cbc =
{
    .block_size 	= 16,
    .iv_len     	= 16,
    .ctx_size   	= sizeof(AES_CTX),
    .init       	= AES_128_CBC_Init,
    .do_cipher  	= AES_DoCipher,
    .peek_iv    	= AES_PeekIV,
    .cleanup    	= AES_Cleanup,
};


MCP_CIPHER *MCP_aes_128_cbc(void)
{
    return (MCP_CIPHER*)&aes_128_cbc;
}



/***************************************************************************
     CTR mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : AES_128_CTR_Init
 *
 * Desc : Initial AES 128 CTR Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int AES_128_CTR_Init(
    MCP_CIPHER_CTX*     	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return AES_Init(ctx, key, iv, MCP_CIPH_CTR_MODE, enc);
}


static void xor_array(unsigned char* in1, unsigned char* in2, unsigned char* out, unsigned char len)
{
    int i;
    for (i=0; i<len; i++)
        out[i] = in1[i] ^ in2[i];
}


 /*------------------------------------------------------------------
 * Func : AES_CTR_DoCipher
 *
 * Desc : Do Cipher
 *
 * Parm : ctx       : context of cipher
 *        in        : input data buffer
 *        len       : size of input data buffer
 *        out       : output data buffer
 *
 * Retn : output data length
 *------------------------------------------------------------------*/
int AES_128_CTR_DoCipher(
    MCP_CIPHER_CTX*       	ctx,
    unsigned char*          	in,
    unsigned long           	len,
    unsigned char*          	out
    )
{
    AES_CTX* p_aes = (AES_CTX*) ctx->cipher_data;
    unsigned int remain = 0;
    int ret = len;

    // process previous non termianted short block (if any...)
    if (p_aes->ecnt_ofst)
    {
        remain = 16 - p_aes->ecnt_ofst;

        if (remain > len)
            remain = len;

        xor_array(in, &p_aes->ecnt[p_aes->ecnt_ofst], out, remain);

        p_aes->ecnt_ofst += remain;
        p_aes->ecnt_ofst &= 0xF;
        in  += remain;
        len -= remain;
        out += remain;
    }

    remain = len & 0xF;
    len   -= remain;

    // process complete blocks...
    if (len)
    {
        MCP_AES_Encryption(p_aes->mode, p_aes->key, p_aes->iv, in, out, len);
        in  += len;
        out += len;
        MCP_AES_PeekIV(p_aes->iv);      // update iv
        p_aes->ecnt_ofst = 0;
    }

    // process short block...
    if (remain)
    {
        memset(p_aes->ecnt, 0, 16);
        memcpy(p_aes->ecnt, in, remain);
        MCP_AES_Encryption(p_aes->mode, p_aes->key, p_aes->iv, p_aes->ecnt, p_aes->ecnt, 16);
        memcpy(out, p_aes->ecnt, remain);   // output remain bytes
        MCP_AES_PeekIV(p_aes->iv);          // update iv
        p_aes->ecnt_ofst = remain;
    }

    return ret;
}



static const MCP_CIPHER aes_128_ctr =
{
    .block_size 	= 1,        // CTR mode has no block alignment requirements...
    .iv_len     	= 16,
    .ctx_size   	= sizeof(AES_CTX),
    .init       	= AES_128_CTR_Init,
    .do_cipher  	= AES_128_CTR_DoCipher,
    .peek_iv    	= AES_PeekIV,
    .cleanup    	= AES_Cleanup,
};


MCP_CIPHER *MCP_aes_128_ctr(void)
{
    return (MCP_CIPHER*) &aes_128_ctr;
}



/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/

#if 0

#define TEST_DATA_BUFFER_SIZE     (128 + 8)

static void AES_CipherTest(void)
{
    MCP_CIPHER* cipher = MCP_aes_128_ctr();
    MCP_CIPHER_CTX  ctx;

    unsigned char key[16] =  {
        0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
        0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11
    };

    unsigned char iv[16] =  {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    unsigned char* buff = kmalloc(TEST_DATA_BUFFER_SIZE, GFP_KERNEL);
    unsigned char* in  = buff;
    unsigned char* out = buff;
    int step = 8;
    int outl = 0;
    int i;
    int len;

    memset(buff, 0x33, TEST_DATA_BUFFER_SIZE);

    mcp_dump_data_with_text(buff, TEST_DATA_BUFFER_SIZE, "Source Data : ");

    ////////////////////////////////////////////////////////////////////

    MCP_CIPHER_CTX_init(&ctx);

    MCP_CipherInit(&ctx, cipher, key, iv, 1);

    for (i=0; i < TEST_DATA_BUFFER_SIZE; i+= step)
    {
        len = TEST_DATA_BUFFER_SIZE-i;
        outl += MCP_CipherUpdate(&ctx, &in[i], (len>=step) ? step : len, &out[outl]);
    }

    outl += MCP_CipherFinal(&ctx, &out[outl]);

    MCP_CIPHER_CTX_cleanup(&ctx);

    mcp_dump_data_with_text(out, outl, "Encrypted Data : ");

    ////////////////////////////////////////////////////////////////////

    MCP_CIPHER_CTX_init(&ctx);

    MCP_CipherInit(&ctx, cipher, key, iv, 0);

    outl = 0;

    for (i=0; i < TEST_DATA_BUFFER_SIZE; i+= step)
    {
        len =TEST_DATA_BUFFER_SIZE -i;
        outl += MCP_CipherUpdate(&ctx, &in[i], (len>=step) ? step : len, &out[outl]);
    }

    outl += MCP_CipherFinal(&ctx, &out[outl]);

    MCP_CIPHER_CTX_cleanup(&ctx);

    mcp_dump_data_with_text(out, outl, "Decrypted Data : ");

    ////////////////////////////////////////////////////////////////////
    kfree(buff);
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
static int __init mcp_aes_module_init(void)
{
    AES_CipherTest();
    return 0;
}


module_init(mcp_aes_module_init);

#endif
