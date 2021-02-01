#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_cipher.h"
#include "mcp/rtk_mcp_dbg.h"
#include "tdes.h"




/*------------------------------------------------------------------
 * Func : TDES_Init
 *
 * Desc : Initial TDES Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int TDES_Init(
    MCP_CIPHER_CTX*       	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	mode,
    int                     	enc
    )
{
    TDES_CTX* p_tdes = (TDES_CTX*) ctx->cipher_data;

    memset(p_tdes, 0, sizeof(TDES_CTX));

    switch(mode)
    {
    	case MCP_CIPH_ECB_MODE:
        	p_tdes->mode = MCP_BCM_ECB;
        	break;

    	case MCP_CIPH_CBC_MODE:
        	p_tdes->mode = MCP_BCM_CBC;
        	break;

    	default:
        	return -1;
    }

    p_tdes->enc = (enc) ? 1 : 0;

    if ((unsigned long)key > MCP_MAX_CW_ENTRY)
    {
        p_tdes->key = p_tdes->buff[0];
        memcpy(p_tdes->buff[0], key, 21);
    }
    else if((unsigned long)key <= MCP_MAX_CW_ENTRY)
    {
        p_tdes->key = (unsigned char*)key;
    }

    if (iv)
    {
        p_tdes->iv = p_tdes->buff[1];
        memcpy(p_tdes->buff[1], iv, 8);
    }
    else
    {
        p_tdes->iv = p_tdes->buff[1];
    }

    return 0;
}



 /*------------------------------------------------------------------
 * Func : TDES_DoCipher
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
int TDES_DoCipher(
    MCP_CIPHER_CTX*    		ctx,
    unsigned char*          	in,
    unsigned long          	len,
    unsigned char*          	out
    )
{
    TDES_CTX* p_tdes = (TDES_CTX*)ctx->cipher_data;
    unsigned char iv[8];

    len &= ~0x7;

    if (len)
    {
        if (p_tdes->enc)
        {
            MCP_TDES_Encryption(p_tdes->mode, p_tdes->key, p_tdes->iv, in, out, len);

            if (p_tdes->mode==MCP_BCM_CBC)
                memcpy(p_tdes->iv, out + len - 8, 8);      // save iv
        }
        else
        {
            memcpy(iv, p_tdes->iv, 8);

            if (p_tdes->mode==MCP_BCM_CBC)
                memcpy(p_tdes->iv, in + len - 8, 8);         // save iv

            MCP_TDES_Decryption(p_tdes->mode, p_tdes->key, iv, in, out, len);
        }
    }

    return len;
}



/*------------------------------------------------------------------
 * Func : TDES_Cleanup
 *
 * Desc : Finished TDES Cipher and output the remain data
 *
 * Parm : ctx       : context of cipher ctx
 *        out       : digest output
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int TDES_Cleanup(
	MCP_CIPHER_CTX* 		ctx
	)
{
    // do nothing
    return 0;
}



/*------------------------------------------------------------------
 * Func : TDES_PeekIV
 *
 * Desc : Get current IV
 *
 * Parm : ctx       : context of cipher ctx
 *        out       : iv output
 *
 * Retn : size of iv
 *------------------------------------------------------------------*/
int TDES_PeekIV(
	MCP_CIPHER_CTX* 		ctx,
	unsigned char* 			out
	)
{
    TDES_CTX* p_tdes = (TDES_CTX*)ctx->cipher_data;
    int ret = 0;

    switch(p_tdes->mode)
    {
    	case MCP_BCM_CBC:
        	memcpy(out, p_tdes->iv, 8);      // output iv
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
 * Func : TDES_ECB_Init
 *
 * Desc : Initial TDES ECB Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int TDES_ECB_Init(
    MCP_CIPHER_CTX*        	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return TDES_Init(ctx, key, NULL, MCP_CIPH_ECB_MODE, enc);
}


static const MCP_CIPHER tdes_ecb =
{
    .block_size 	= 8,
    .iv_len     	= 0,
    .ctx_size   	= sizeof(TDES_CTX),
    .init       	= TDES_ECB_Init,
    .do_cipher  	= TDES_DoCipher,
    .peek_iv    	= TDES_PeekIV,
    .cleanup    	= TDES_Cleanup,
};



MCP_CIPHER *MCP_tdes_ecb(void)
{
    return (MCP_CIPHER*)&tdes_ecb;
}


/***************************************************************************
     CBC mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : TDES_CBC_Init
 *
 * Desc : Initial TDES CBC Cipher
 *
 * Parm : ctx  : context of md ctx
 *        key  : key
 *        iv   : initial vector
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
int TDES_CBC_Init(
    MCP_CIPHER_CTX*       	ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv,
    int                     	enc
    )
{
    return TDES_Init(ctx, key, iv, MCP_CIPH_CBC_MODE, enc);
}


static const MCP_CIPHER tdes_cbc =
{
    .block_size 	= 8,
    .iv_len     	= 8,
    .ctx_size   	= sizeof(TDES_CTX),
    .init       	= TDES_CBC_Init,
    .do_cipher 	        = TDES_DoCipher,
    .peek_iv    	= TDES_PeekIV,
    .cleanup    	= TDES_Cleanup,
};


MCP_CIPHER *MCP_tdes_cbc(void)
{
    return (MCP_CIPHER*)&tdes_cbc;
}

