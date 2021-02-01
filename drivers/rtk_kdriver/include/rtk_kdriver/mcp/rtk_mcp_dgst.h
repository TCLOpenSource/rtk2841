#ifndef __MCP_DGST_H__
#define __MCP_DGST_H__

#include "rtk_mcp_buff.h"


#define MCP_BUFF            		mcp_buff
#define MCP_MAX_DIGEST_SIZE 	64

typedef enum {
    MCP_MD_AES_H,
    MCP_MD_MARS_AES_H,
    MCP_MD_SHA1,
    MCP_MD_MARS_SHA1,    
#ifdef CONFIG_RTK_KDRV_MCP_SHA256
    MCP_MD_SHA256,
    MCP_MD_MARS_SHA256
#endif    
}MCP_MD_TYPES;


typedef struct 
{
    void* digest;
    void* md_data;
    void* private_data;     /* kevin added to contain special data */
}MCP_MD_CTX;


typedef struct 
{
    int type;   			/* type id*/
    int digest_sz;    	/* digest size */
    int block_size;  	/* the block size for each operation */
    int ctx_size;      	/* how big does the ctx->md_data need to be */    
    int (*init)(MCP_MD_CTX* ctx);  /* initial md conext */          
    int (*update)(MCP_MD_CTX *ctx, MCP_BUFF* mcpb);
    int (*final)(MCP_MD_CTX *ctx, unsigned char* pHash);    
    int (*peek)(MCP_MD_CTX *ctx, unsigned char* pHash);    
    int (*cleanup)(MCP_MD_CTX *ctx);
    
}MCP_MD;


void MCP_MD_CTX_init(MCP_MD_CTX *ctx);
int  MCP_MD_CTX_cleanup(MCP_MD_CTX *ctx);
int  MCP_DigestInit(MCP_MD_CTX* ctx, const MCP_MD* type);
int  MCP_DigestUpdate(MCP_MD_CTX* ctx, MCP_BUFF* mcpb);
int  MCP_DigestFinal(MCP_MD_CTX* ctx,unsigned char* pHash,unsigned int* pHashLen);
int  MCP_DigestPeek(MCP_MD_CTX* ctx,unsigned char* pHash,unsigned int* pHashLen);


extern MCP_MD* MCP_aes_h(void);
extern MCP_MD* MCP_mars_aes_h(void);
extern MCP_MD* MCP_mars_aes_h_with_aes_enc(void);
extern MCP_MD* MCP_sha1(void);
extern MCP_MD* MCP_mars_sha1(void);
#ifdef CONFIG_RTK_KDRV_MCP_SHA256
extern MCP_MD* MCP_sha256(void);
extern MCP_MD* MCP_mars_sha256(void);
#endif

#endif // __MCP_DGST_H__
