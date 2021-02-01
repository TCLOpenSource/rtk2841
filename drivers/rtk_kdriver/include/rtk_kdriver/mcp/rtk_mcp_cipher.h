#ifndef __MCP_CIPHER_H__
#define __MCP_CIPHER_H__

#include <rtk_kdriver/rtk_mcp.h>

#define MAX_CIPHER_BLOCK_SIZE       	32
#define MAX_CIPHER_IV_SIZE          	32
#define MAX_CIPHER_KEY_SIZE         	32


typedef struct
{
    void*           	cipher;        
    void*           	cipher_data;        
    unsigned char   	buff_len;    
    unsigned char   	buff[MAX_CIPHER_BLOCK_SIZE];    
}MCP_CIPHER_CTX;


// flags B[] ................
#define MCP_CIPH_STREAM_CIPHER          	0x0
#define MCP_CIPH_ECB_MODE               	0x1
#define MCP_CIPH_CBC_MODE               	0x2
#define MCP_CIPH_CFB_MODE               	0x3
#define MCP_CIPH_OFB_MODE               	0x4
#define MCP_CIPH_CTR_MODE               	0x5
#define MCP_CIPH_MODE                   	0x7


typedef struct 
{    
    int block_size;
    int key_len;            /* Default value for variable length ciphers */
    int iv_len;
    int ctx_size;           /* how big ctx->cipher_data needs to be */        
    int (*init)(MCP_CIPHER_CTX* ctx, const unsigned char *key, const unsigned char *iv, int enc);
    int (*do_cipher)(MCP_CIPHER_CTX *ctx, unsigned char* in, unsigned long len, unsigned char* out);
    int (*peek_iv)(MCP_CIPHER_CTX* ctx, unsigned char* out);
    int (*cleanup)(MCP_CIPHER_CTX *ctx);
}MCP_CIPHER;


void MCP_CIPHER_CTX_init(MCP_CIPHER_CTX *a); 
int  MCP_CIPHER_CTX_cleanup(MCP_CIPHER_CTX *a);
int  MCP_CipherInit(MCP_CIPHER_CTX *ctx, const MCP_CIPHER *type, unsigned char *key, unsigned char *iv, int enc);                    
int  MCP_CipherUpdate(MCP_CIPHER_CTX *ctx, unsigned char* in, unsigned long len, unsigned char* out);
int  MCP_CipherPeekIV(MCP_CIPHER_CTX *ctx, unsigned char* out);
int  MCP_CipherFinal(MCP_CIPHER_CTX *ctx, unsigned char* out);         

int  MCP_CipherDataSimple(const MCP_CIPHER *type, unsigned char *key, unsigned char *iv, int enc, unsigned char* in, unsigned long len, unsigned char* out);    
#define MCP_EncryptDataSimple(type, key, iv, in, len, out)   MCP_CipherDataSimple(type, key, iv, 1, in, len, out)
#define MCP_DecryptDataSimple(type, key, iv, in, len, out)   MCP_CipherDataSimple(type, key, iv, 0, in, len, out)

// ciphers ...
extern MCP_CIPHER *MCP_des_ecb(void);
extern MCP_CIPHER *MCP_des_cbc(void);
extern MCP_CIPHER *MCP_tdes_ecb(void);
extern MCP_CIPHER *MCP_tdes_cbc(void);
extern MCP_CIPHER *MCP_aes_128_ecb(void);
extern MCP_CIPHER *MCP_aes_128_cbc(void);            
extern MCP_CIPHER *MCP_aes_128_ctr(void);
#ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA
extern MCP_CIPHER *MCP_cam_128_ecb(void);
extern MCP_CIPHER *MCP_cam_128_cbc(void);
extern MCP_CIPHER *MCP_cam_128_ctr(void);
#endif

                
#endif //__MCP_CIPHER_H__
