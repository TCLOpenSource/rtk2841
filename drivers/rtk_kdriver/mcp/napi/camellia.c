#include <linux/kernel.h>
#include <linux/mm.h>
#include <rtk_kdriver/rtk_mcp.h>

#include "mcp/rtk_mcp_cipher.h"
#include "mcp/rtk_mcp_dbg.h"
#include "camellia.h"


/*------------------------------------------------------------------
 * Func : CAM_Init
 *
 * Desc : Initial MCP Digest
 *
 * Parm : ctx  : context of md ctx 
 *        key  : key
 *        iv   : initial vector
 *         
 * Retn : N/A
 *------------------------------------------------------------------*/
int CAM_Init(
    MCP_CIPHER_CTX*   		ctx,
    const unsigned char*    	key,
    const unsigned char*    	iv, 
    int                     	mode,
    int                     	enc
    )
{             
    CAM_CTX* p_cam = (CAM_CTX*) ctx->cipher_data;
        
    memset(p_cam, 0, sizeof(CAM_CTX));
    
    switch(mode) 
    {
    	case MCP_CIPH_ECB_MODE: 
    		p_cam->mode = MCP_BCM_ECB;
        	break;
        
    	case MCP_CIPH_CBC_MODE: 
    		p_cam->mode = MCP_BCM_CBC;
        	break;        
        
    	case MCP_CIPH_CTR_MODE:
    		p_cam->mode = MCP_BCM_CTR;
        	break;        
                
    	default:        
        	return -1;    
    }
    
    p_cam->enc = (enc) ? 1 : 0;
    p_cam->ecnt_ofst = 0;
        
    if ((unsigned long)key > MCP_MAX_CW_ENTRY) 
    {                    
    	p_cam->key = p_cam->buff[0];
        memcpy(p_cam->buff[0], key, 16);
    }
	else if((unsigned long)key <= MCP_MAX_CW_ENTRY)   
	{
		p_cam->key = key;
	} 
            
    if (iv) 
    {
    	p_cam->iv = p_cam->buff[1];
        memcpy(p_cam->buff[1], iv, 16);
    }   
    else
    {
    	p_cam->iv = p_cam->buff[1];
    }         

    return 0;
}



 /*------------------------------------------------------------------
 * Func : CAM_DoCipher
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
int CAM_DoCipher(
    MCP_CIPHER_CTX*   		ctx,
    unsigned char*          	in,           
    unsigned long           	len,
    unsigned char*          	out
    )
{       
    CAM_CTX* p_cam = (CAM_CTX*) ctx->cipher_data;
    unsigned char iv[16];
    
    len &= ~0xF;
        
    if (len)
    {        
        if (p_cam->enc)
       {
            MCP_CAM_Encryption(p_cam->mode, p_cam->key, p_cam->iv, in, out, len);
                                
            if (p_cam->mode==MCP_BCM_CBC)
                memcpy(p_cam->iv, out + len - 16, 16);      // save iv
        }
        else
        {
            memcpy(iv, p_cam->iv, 16);
         
            if (p_cam->mode==MCP_BCM_CBC)
                memcpy(p_cam->iv, in + len - 16, 16);      // save iv

            MCP_CAM_Decryption(p_cam->mode, p_cam->key, iv, in, out, len);
        }        
    }
        
    return len;
}



/*------------------------------------------------------------------
 * Func : CAM_Cleanup
 *
 * Desc : Finished MCP Digest and output the remain data
 *
 * Parm : ctx       : context of cipher ctx
 *         
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int CAM_Cleanup(
	MCP_CIPHER_CTX* 		ctx
	) 
{
    // do nothing
    return 0;
}


/*------------------------------------------------------------------
 * Func : CAM_PeekIV
 *
 * Desc : Get current IV 
 *
 * Parm : ctx       : context of cipher ctx
 *        out       : iv output 
 *         
 * Retn : size of iv
 *------------------------------------------------------------------*/
int CAM_PeekIV(
	MCP_CIPHER_CTX* 		ctx, 
	unsigned char* 			out
	) 
{
    CAM_CTX* p_cam = (CAM_CTX*) ctx->cipher_data;
    int ret = 0;
    
    switch(p_cam->mode)
    {
    	case MCP_BCM_CBC: 
    	case MCP_BCM_CTR: 
        	memcpy(out, p_cam->iv, 16);      // output iv
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
 * Func : CAM_128_ECB_Init
 *
 * Desc : Initial CAM 128 ECB Cipher
 *
 * Parm : ctx  : context of md ctx 
 *        key  : key
 *        iv   : initial vector
 *         
 * Retn : N/A
 *------------------------------------------------------------------*/
int CAM_128_ECB_Init(
    MCP_CIPHER_CTX* 		ctx, 
    const unsigned char*    	key, 
    const unsigned char*    	iv, 
    int                     	enc
    )
{               
    return CAM_Init(ctx, key, NULL, MCP_CIPH_ECB_MODE, enc);
}


static const MCP_CIPHER cam_128_ecb =
{
    .block_size	= 16,      
    .iv_len     	= 0,    
    .ctx_size   	= sizeof(CAM_CTX),
    .init       	= CAM_128_ECB_Init,
    .do_cipher  	= CAM_DoCipher,
    .peek_iv    	= CAM_PeekIV,
    .cleanup    	= CAM_Cleanup,
};



MCP_CIPHER *MCP_cam_128_ecb(void)
{
    return (MCP_CIPHER*)&cam_128_ecb;
}


/***************************************************************************
     CBC mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : CAM_128_CBC_Init
 *
 * Desc : Initial CAM 128 CBC Cipher
 *
 * Parm : ctx  : context of md ctx 
 *        key  : key
 *        iv   : initial vector
 *         
 * Retn : N/A
 *------------------------------------------------------------------*/
int CAM_128_CBC_Init(
    MCP_CIPHER_CTX*     	ctx,
    const unsigned char*    	key,        
    const unsigned char*    	iv,        
    int                     	enc
    )
{               
    return CAM_Init(ctx, key, iv, MCP_CIPH_CBC_MODE, enc);
}


static const MCP_CIPHER cam_128_cbc =
{    
    .block_size 	= 16,      
    .iv_len     	= 16,    
    .ctx_size   	= sizeof(CAM_CTX),
    .init       	= CAM_128_CBC_Init,
    .do_cipher  	= CAM_DoCipher,
    .peek_iv    	= CAM_PeekIV,
    .cleanup    	= CAM_Cleanup,
};


MCP_CIPHER *MCP_cam_128_cbc(void)
{
    return (MCP_CIPHER*)&cam_128_cbc;
}



/***************************************************************************
     CTR mode
****************************************************************************/


/*------------------------------------------------------------------
 * Func : CAM_128_CTR_Init
 *
 * Desc : Initial CAM 128 CTR Cipher
 *
 * Parm : ctx  : context of md ctx 
 *        key  : key
 *        iv   : initial vector
 *         
 * Retn : N/A
 *------------------------------------------------------------------*/
int CAM_128_CTR_Init(
    MCP_CIPHER_CTX*     	ctx,
    const unsigned char*    	key,        
    const unsigned char*    	iv,        
    int                     	enc
    )
{
    return CAM_Init(ctx, key, iv, MCP_CIPH_CTR_MODE, enc);
}


static void xor_array(unsigned char* in1, unsigned char* in2, unsigned char* out, unsigned char len)
{
    int i;
    for (i=0; i<len; i++)
        out[i] = in1[i] ^ in2[i];
}


 /*------------------------------------------------------------------
 * Func : CAM_CTR_DoCipher
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
int CAM_128_CTR_DoCipher(
    MCP_CIPHER_CTX*       	ctx,
    unsigned char*          	in,           
    unsigned long           	len,
    unsigned char*          	out
    )
{       
    CAM_CTX* p_cam = (CAM_CTX*) ctx->cipher_data;
    unsigned int remain = 0;
    int ret = len;        
    
    // process previous non termianted short block (if any...)
    if (p_cam->ecnt_ofst)
    {        
        remain = 16 - p_cam->ecnt_ofst;
        
        if (remain > len)
            remain = len;
        
        xor_array(in, &p_cam->ecnt[p_cam->ecnt_ofst], out, remain);
                
        p_cam->ecnt_ofst += remain;
        p_cam->ecnt_ofst &= 0xF;
        in  += remain;
        len -= remain;           
        out += remain;                
    }
    
    remain = len & 0xF;
    len   -= remain;
    
    // process complete blocks...    
    if (len)
    {        
        MCP_CAM_Encryption(p_cam->mode, p_cam->key, p_cam->iv, in, out, len);
        in  += len;
        out += len;
        MCP_AES_PeekIV(p_cam->iv);      // update iv
        p_cam->ecnt_ofst = 0;
    }
    
    // process short block...
    if (remain)
    {
        memset(p_cam->ecnt, 0, 16);
        memcpy(p_cam->ecnt, in, remain);
        MCP_CAM_Encryption(p_cam->mode, p_cam->key, p_cam->iv, p_cam->ecnt, p_cam->ecnt, 16);
        memcpy(out, p_cam->ecnt, remain);   // output remain bytes
        MCP_AES_PeekIV(p_cam->iv);          // update iv
        p_cam->ecnt_ofst = remain;
    }
        
    return ret;
}



static const MCP_CIPHER cam_128_ctr =
{    
    .block_size 	= 1,        // CTR mode has no block alignment requirements...
    .iv_len     	= 16,    
    .ctx_size   	= sizeof(CAM_CTX),
    .init       	= CAM_128_CTR_Init,
    .do_cipher  	= CAM_128_CTR_DoCipher,
    .peek_iv    	= CAM_PeekIV,
    .cleanup    	= CAM_Cleanup,
};


MCP_CIPHER *MCP_cam_128_ctr(void)
{
    return (MCP_CIPHER*) &cam_128_ctr;
}
