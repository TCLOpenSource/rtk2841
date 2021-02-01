#ifndef __MCP_API_H__
#define __MCP_API_H__
extern struct class          *mcp_dev_class;
#define MCP_MAX_CW_ENTRY        128
#define MCP_MODE(x)                     (x & 0x1F)

#define MCP_ALGO_DES         	0x00
#define MCP_ALGO_3DES        	0x01
#define MCP_ALGO_RC4         	0x02
#define MCP_ALGO_MD5         	0x03
#define MCP_ALGO_SHA_1       	0x04
#define MCP_ALGO_AES         	0x05
#define MCP_ALGO_AES_G       	0x06
#define MCP_ALGO_AES_H       	0x07
#define MCP_ALGO_CMAC        	0x08
#define MCP_ALGO_CSA            0x09   
#define MCP_ALGO_MULTI2         0x0A   
#define MCP_ALGO_SHA256         0x0B
#define MCP_ALGO_CRC            0x0C    /* load vector with 0 */
#define MCP_ALGO_CRC_SHA256     0x0D    /* write back to DDR */
#define MCP_ALGO_AES_192        0x10
#define MCP_ALGO_AES_256        0x11
#define MCP_ALGO_CAM            0x1D
#define MCP_ALGO_CAM_192        0x1E
#define MCP_ALGO_CAM_256        0x1F

#define MCP_BCM(x)  ((x & 0x3) << 6)  
#define MCP_BCM_ECB          	0x0
#define MCP_BCM_CBC          	0x1
#define MCP_BCM_CTR          	0x2

#define MCP_ENC(x)     ((x & 0x1) << 5)        

#define MAX_CP_EN_DE_SEGMENT_SIZE 0x00FFFFF0  /*16Mbytes - 16bytes*/

typedef struct 
{
    unsigned int flags;
    unsigned int key[6];
    unsigned int iv[4];
    unsigned int data_in;      // data in : physical address
    unsigned int data_out;     // data out : physical address
    unsigned int length;       // data length
}mcp_desc;


#define FIRST_BLOCK                 0x80
#define LAST_BLOCK                  0x08
#define SINGLE_CLOCK               (FIRST_BLOCK | LAST_BLOCK)


/***************************************************************************
               ------------------- APIS ----------------
****************************************************************************/

#define FILE_HASHING_BUFFER_SIZE                (512 * 1024)

/********************************************************************************
 AES_H Hashing
 ********************************************************************************/
#define AES_H_FILE_HASHING_BUFFER_SIZE        FILE_HASHING_BUFFER_SIZE

int MCP_AES_H_HASH_INIT(mcp_desc* p_desc);
int MCP_AES_H_IV_UPDATE(mcp_desc* p_desc, unsigned char Hash[16]);
int MCP_AES_H_PADDING(unsigned char* p_buff, unsigned long buff_len, unsigned long data_len);
int MCP_AES_H_Hashing(mcp_desc* p_desc, unsigned char* p_in, unsigned long len, unsigned char* p_out);
int MCP_AES_H_DataHash(unsigned char* p_data, unsigned long data_len, unsigned char hash[16], unsigned long block_size, unsigned char first_block);


/********************************************************************************
 DES 
 ********************************************************************************/ 
int MCP_DES_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[7], unsigned char IV[8]);    
int MCP_DES_Decryption(unsigned char mode, unsigned char key[7], unsigned char iv[8], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_DES_Encryption(unsigned char mode, unsigned char key[7], unsigned char iv[8], unsigned char* p_in, unsigned char* p_out, unsigned long len);
#define MCP_DES_ECB_Decryption(key, p_in, p_out, len)       	MCP_DES_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_DES_ECB_Encryption(key, p_in, p_out, len)       	MCP_DES_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_DES_CBC_Decryption(key, iv, p_in, p_out, len)   	MCP_DES_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_DES_CBC_Encryption(key, iv, p_in, p_out, len)   	MCP_DES_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_DES_CTR_Decryption(key, iv, p_in, p_out, len)   	MCP_DES_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_DES_CTR_Encryption(key, iv, p_in, p_out, len)   	MCP_DES_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)


/********************************************************************************
 TDES 
 ********************************************************************************/ 
int MCP_TDES_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[21], unsigned char IV[8]);    
int MCP_TDES_Decryption(unsigned char mode, unsigned char key[21], unsigned char iv[8], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_TDES_Encryption(unsigned char mode, unsigned char key[21], unsigned char iv[8], unsigned char* p_in, unsigned char* p_out, unsigned long len);
#define MCP_TDES_ECB_Decryption(key, p_in, p_out, len)       	MCP_TDES_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_TDES_ECB_Encryption(key, p_in, p_out, len)       	MCP_TDES_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_TDES_CBC_Decryption(key, iv, p_in, p_out, len)   	MCP_TDES_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_TDES_CBC_Encryption(key, iv, p_in, p_out, len)   	MCP_TDES_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_TDES_CTR_Decryption(key, iv, p_in, p_out, len)   	MCP_TDES_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_TDES_CTR_Encryption(key, iv, p_in, p_out, len)   	MCP_TDES_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)


/********************************************************************************
 AES 
 ********************************************************************************/ 
int MCP_AES_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[16], unsigned char IV[16]);
int MCP_AES_Decryption(unsigned char mode, unsigned char key[16], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_AES_Encryption(unsigned char mode, unsigned char key[16], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_AES_PeekIV(unsigned char IV[16]);

#define MCP_AES_ECB_Decryption(key, p_in, p_out, len)       	MCP_AES_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_AES_ECB_Encryption(key, p_in, p_out, len)       	MCP_AES_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_AES_CBC_Decryption(key, iv, p_in, p_out, len)   	MCP_AES_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_AES_CBC_Encryption(key, iv, p_in, p_out, len)   	MCP_AES_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_AES_CTR_Decryption(key, iv, p_in, p_out, len)   	MCP_AES_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_AES_CTR_Encryption(key, iv, p_in, p_out, len)   	MCP_AES_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)

/********************************************************************************
 AES-192
 ********************************************************************************/
int MCP_AES_192_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[24], unsigned char IV[16], unsigned long key_buff_phy );
int MCP_AES_192_Decryption(unsigned char Mode, unsigned char Key[24], unsigned char IV[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_AES_192_Encryption(unsigned char mode, unsigned char key[24], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);

#define MCP_AES_192_ECB_Decryption(key, p_in, p_out, len)       MCP_AES_192_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_AES_192_ECB_Encryption(key, p_in, p_out, len)       MCP_AES_192_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_AES_192_CBC_Decryption(key, iv, p_in, p_out, len)   MCP_AES_192_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_AES_192_CBC_Encryption(key, iv, p_in, p_out, len)   MCP_AES_192_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_AES_192_CTR_Decryption(key, iv, p_in, p_out, len)   MCP_AES_192_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_AES_192_CTR_Encryption(key, iv, p_in, p_out, len)   MCP_AES_192_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)

/********************************************************************************
 AES-256
 ********************************************************************************/
int MCP_AES_256_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[32], unsigned char IV[16], unsigned long key_buff_phy );
int MCP_AES_256_Decryption(unsigned char Mode, unsigned char Key[32], unsigned char IV[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_AES_256_Encryption(unsigned char mode, unsigned char key[32], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);

#define MCP_AES_256_ECB_Decryption(key, p_in, p_out, len)       MCP_AES_256_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_AES_256_ECB_Encryption(key, p_in, p_out, len)       MCP_AES_256_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_AES_256_CBC_Decryption(key, iv, p_in, p_out, len)   MCP_AES_256_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_AES_256_CBC_Encryption(key, iv, p_in, p_out, len)   MCP_AES_256_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_AES_256_CTR_Decryption(key, iv, p_in, p_out, len)   MCP_AES_256_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_AES_256_CTR_Encryption(key, iv, p_in, p_out, len)   MCP_AES_256_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)

#ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA
/********************************************************************************
 Camellia
 ********************************************************************************/
int MCP_CAM_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[16], unsigned char IV[16]);
int MCP_CAM_Decryption(unsigned char mode, unsigned char key[16], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_CAM_Encryption(unsigned char mode, unsigned char key[16], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_CAM_PeekIV(unsigned char IV[16]);

#define MCP_CAM_ECB_Decryption(key, p_in, p_out, len)       MCP_CAM_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_CAM_ECB_Encryption(key, p_in, p_out, len)       MCP_CAM_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_CAM_CBC_Decryption(key, iv, p_in, p_out, len)   MCP_CAM_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_CAM_CBC_Encryption(key, iv, p_in, p_out, len)   MCP_CAM_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_CAM_CTR_Decryption(key, iv, p_in, p_out, len)   MCP_CAM_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_CAM_CTR_Encryption(key, iv, p_in, p_out, len)   MCP_CAM_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)

/********************************************************************************
 Camellia -192
 ********************************************************************************/
int MCP_CAM_192_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[24], unsigned char IV[16], unsigned long key_buff_phy );
int MCP_CAM_192_Decryption(unsigned char Mode, unsigned char Key[24], unsigned char IV[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_CAM_192_Encryption(unsigned char mode, unsigned char key[24], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);

#define MCP_CAM_192_ECB_Decryption(key, p_in, p_out, len)       MCP_CAM_192_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_CAM_192_ECB_Encryption(key, p_in, p_out, len)       MCP_CAM_192_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_CAM_192_CBC_Decryption(key, iv, p_in, p_out, len)   MCP_CAM_192_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_CAM_192_CBC_Encryption(key, iv, p_in, p_out, len)   MCP_CAM_192_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_CAM_192_CTR_Decryption(key, iv, p_in, p_out, len)   MCP_CAM_192_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_CAM_192_CTR_Encryption(key, iv, p_in, p_out, len)   MCP_CAM_192_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)

/********************************************************************************
 Camellia -256
 ********************************************************************************/
int MCP_CAM_256_DESC_INIT(mcp_desc* pDesc, unsigned char EnDe, unsigned char Mode, unsigned char Key[32], unsigned char IV[16], unsigned long key_buff_phy );
int MCP_CAM_256_Decryption(unsigned char Mode, unsigned char Key[32], unsigned char IV[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);
int MCP_CAM_256_Encryption(unsigned char mode, unsigned char key[32], unsigned char iv[16], unsigned char* p_in, unsigned char* p_out, unsigned long len);

#define MCP_CAM_256_ECB_Decryption(key, p_in, p_out, len)       MCP_CAM_256_Decryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_CAM_256_ECB_Encryption(key, p_in, p_out, len)       MCP_CAM_256_Encryption(MCP_BCM_ECB, key, NULL, p_in, p_out, len)
#define MCP_CAM_256_CBC_Decryption(key, iv, p_in, p_out, len)   MCP_CAM_256_Decryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_CAM_256_CBC_Encryption(key, iv, p_in, p_out, len)   MCP_CAM_256_Encryption(MCP_BCM_CBC, key, iv, p_in, p_out, len)
#define MCP_CAM_256_CTR_Decryption(key, iv, p_in, p_out, len)   MCP_CAM_256_Decryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#define MCP_CAM_256_CTR_Encryption(key, iv, p_in, p_out, len)   MCP_CAM_256_Encryption(MCP_BCM_CTR, key, iv, p_in, p_out, len)
#endif

/********************************************************************************
 SHA-1 Hashing
 ********************************************************************************/
#define SHA1_FILE_HASHING_BUFFER_SIZE        FILE_HASHING_BUFFER_SIZE
#define SHA1_DIGEST_SIZE                     20
#define SHA1_BLOCK_SIZE                      64
#define SHA1_ALIGNMENT_CHECK                 0x3F

int MCP_SHA1_HASH_INIT(mcp_desc* p_desc);
int MCP_SHA1_IV_UPDATE(mcp_desc* p_desc, unsigned char hash[SHA1_DIGEST_SIZE]);
int MCP_SHA1_PADDING(unsigned char* p_buff, unsigned long buff_len, unsigned long data_len);
int MCP_SHA1_Hashing(mcp_desc* p_desc, unsigned char* p_in, unsigned long len, unsigned char* p_out);
int MCP_SHA1_DataHash(unsigned char* p_data, unsigned long data_len, unsigned char hash[SHA1_DIGEST_SIZE], unsigned long block_size, unsigned char first_block);    

#ifdef CONFIG_RTK_KDRV_MCP_SHA256
/********************************************************************************
 SHA-256 Hashing
 ********************************************************************************/
#define SHA256_FILE_HASHING_BUFFER_SIZE        FILE_HASHING_BUFFER_SIZE
#define SHA256_DIGEST_SIZE                     32
#define SHA256_BLOCK_SIZE                      64
#define SHA256_ALIGNMENT_CHECK                 0x3F

int MCP_SHA256_HASH_INIT(mcp_desc* p_desc);
int MCP_SHA256_IV_UPDATE(mcp_desc* p_desc, unsigned char hash[SHA256_DIGEST_SIZE]);
int MCP_SHA256_PADDING(unsigned char* p_buff, unsigned long buff_len, unsigned long data_len);
int MCP_SHA256_Hashing(mcp_desc* p_desc, unsigned char* p_in, unsigned long len, unsigned char* p_out);
int MCP_SHA256_DataHash(unsigned char* p_data, unsigned long data_len, unsigned char hash[SHA256_DIGEST_SIZE], unsigned long block_size, unsigned char first_block);    
#endif    
        
/********************************************************************************
 misc
 ********************************************************************************/
#include "mcp/rtk_mcp_dbg.h"
void* mcp_malloc(unsigned long size);
void  mcp_free(void* addr, unsigned long size);
void  mcp_dump_mem(unsigned char* data, unsigned int len);
#define mcp_dump_data_with_text(data, len ,fmt, args...)\
        do {\
        	    mcp_debug(fmt, ## args);\
                mcp_dump_mem(data, len);\
        }while(0)

void do_mcp_throughput_calculate(mcp_desc* desc, dma_addr_t* data_in, dma_addr_t* data_out, unsigned long data_len, int ende, int bcm, char *str);
void mcp_dump_all_desc(char * buf);
/*********************APIs for internal call************************/
extern int __init mcp_core_init(struct device *dev_device);
extern void __exit mcp_core_uninit(void);
extern int mcp_pm_on(void);
extern int mcp_pm_off(void);
extern int mcp_do_command_user(mcp_desc __user * p_desc, int n_desc);
extern int mcp_do_command(mcp_desc* p_desc, int n_desc);

#endif  // __MCP_API_H__
