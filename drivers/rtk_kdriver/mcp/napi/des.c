#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_cipher.h"
#include "mcp/rtk_mcp_dbg.h"
#include "des.h"




/*------------------------------------------------------------------
 * Func : DES_Init
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int DES_Init(
    MCP_CIPHER_CTX*      	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	mode,
    int                     	enc
    )
{
    DES_CTX* p_des = (DES_CTX*) ctx->cipher_data;

    memset(p_des, 0, sizeof(DES_CTX));

    switch(mode)
    {
    	case MCP_CIPH_ECB_MODE:
        	p_des->mode = MCP_BCM_ECB;
        	break;

    	case MCP_CIPH_CBC_MODE:
        	p_des->mode = MCP_BCM_CBC;
        	break;

    	default:
        	return -1;
    }

    p_des->enc = (enc) ? 1 : 0;

    if ((unsigned long)key > MCP_MAX_CW_ENTRY)
    {
        p_des->key = p_des->buff[0];
        memcpy(p_des->buff[0], key, 7);
    }
	else if((unsigned long)key <= MCP_MAX_CW_ENTRY)
	{
		p_des->key = key;
	}

    if (iv)
    {
        p_des->iv = p_des->buff[1];
        memcpy(p_des->buff[1], iv, 8);
    }
    else
    {
        p_des->iv = p_des->buff[1];
    }

    return 0;
}



 /*------------------------------------------------------------------
 * Func : DES_DoCipher
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
int DES_DoCipher(
    MCP_CIPHER_CTX*     	ctx,
    unsigned char*          	in,
    unsigned long           	len,
    unsigned char*         	out
    )
{
    DES_CTX* p_des = (DES_CTX*)ctx->cipher_data;
    unsigned char iv[8];

    len &= ~0x7;

    if (len)
    {
        if (p_des->enc)
        {
            MCP_DES_Encryption(p_des->mode, p_des->key, p_des->iv, in, out, len);

            if (p_des->mode==MCP_BCM_CBC)
                memcpy(p_des->iv, out + len - 8, 8);      // save iv
        }
        else
        {
            memcpy(iv, p_des->iv, 8);

            if (p_des->mode==MCP_BCM_CBC)
                memcpy(p_des->iv, in + len - 8, 8);         // save iv

            MCP_DES_Decryption(p_des->mode, p_des->key, iv, in, out, len);
        }
    }

    return len;
}



/*------------------------------------------------------------------
 * Func : DES_Cleanup
 *
 * Desc : Finished MCP Digest and output the remain data
 *
 * Parm : ctx       : context of cipher ctx
 *        out       : digest output
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int DES_Cleanup(
	MCP_CIPHER_CTX* 		ctx
	)
{
    // do nothing
    return 0;
}



/*------------------------------------------------------------------
 * Func : DES_PeekIV
 *
 * Desc : Get current IV
 *
 * Parm : ctx       : context of cipher ctx
 *        out       : iv output
 *
 * Retn : size of iv
 *------------------------------------------------------------------*/
int DES_PeekIV(
	MCP_CIPHER_CTX* 		ctx,
	unsigned char* 			out)
{
    DES_CTX* p_des = (DES_CTX*)ctx->cipher_data;
    int ret = 0;

    switch(p_des->mode)
    {
    	case MCP_BCM_CBC:
        	memcpy(out, p_des->iv, 8);      // output iv
        	ret = 8;
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
 * Func : DES_ECB_Init
 *
 * Desc : Initial AES 128 ECB Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int DES_ECB_Init(
    MCP_CIPHER_CTX*      	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return DES_Init(ctx, key, NULL, MCP_CIPH_ECB_MODE, enc);
}


static const MCP_CIPHER des_ecb =
{
    .block_size 	= 8,
    .iv_len     	= 0,
    .ctx_size   	= sizeof(DES_CTX),
    .init       	= DES_ECB_Init,
    .do_cipher  	= DES_DoCipher,
    .peek_iv    	= DES_PeekIV,
    .cleanup    	= DES_Cleanup,
};



MCP_CIPHER *MCP_des_ecb(void)
{
    return (MCP_CIPHER*)&des_ecb;
}


/***************************************************************************
     CBC mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : DES_CBC_Init
 *
 * Desc : Initial AES 128 CBC Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int DES_CBC_Init(
    MCP_CIPHER_CTX*      	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return DES_Init(ctx, key, iv, MCP_CIPH_CBC_MODE, enc);
}


static const MCP_CIPHER des_cbc =
{
    .block_size 	= 8,
    .iv_len     	= 8,
    .ctx_size   	= sizeof(DES_CTX),
    .init       	= DES_CBC_Init,
    .do_cipher  	= DES_DoCipher,
    .peek_iv    	= DES_PeekIV,
    .cleanup    	= DES_Cleanup,
};


MCP_CIPHER *MCP_des_cbc(void)
{
    return (MCP_CIPHER*)&des_cbc;
}

