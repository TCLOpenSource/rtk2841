#ifndef __RSA_LIB_H__
#define __RSA_LIB_H__
#include <linux/mpi.h>
#include <linux/mutex.h>
#include <mach/rtk_log.h>

typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef enum _RSA_INPUT_TYPE
{
	RSA_INPUT_TYPE_CHAR_ARRAY_LITTLE_ENDIAN,
	RSA_INPUT_TYPE_HEX_STRING,
	RSA_INPUT_TYPE_CHAR_ARRAY_BIG_ENDIAN,
}RSA_INPUT_TYPE;

typedef enum hash_algo_id {
        HASH_ALGO_ID_MD4,
        HASH_ALGO_ID_MD5,
        HASH_ALGO_ID_SHA1,
        HASH_ALGO_ID_RIPE_MD_160,
        HASH_ALGO_ID_SHA256,
        HASH_ALGO_ID_SHA384,
        HASH_ALGO_ID_SHA512,
        HASH_ALGO_ID_SHA224,
        HASH_ALGO_ID_LAST
} HASH_ALGO_ID;
typedef enum _RSA_PADDING_MODE {
        RSA_PKCS1_PADDING = 0,
        /*RSA_SSLV23_PADDING = 1,
        RSA_NO_PADDING = 2,
        RSA_PKCS1_OAEP_PADDING = 3,
        RSA_X931_PADDING = 4,*/
} RSA_PADDING_MODE;
typedef enum _RSA_KEY_TYPE {
        RSA_KEY_N,
        RSA_KEY_E,
        RSA_KEY_D,
} RSA_KEY_TYPE;

typedef struct _RSA_T RSA_T;
struct _RSA_T {
        struct mutex mutex;
        RSA_PADDING_MODE padding_mode;
        HASH_ALGO_ID hash_algo;
        MPI n;
        MPI e;
        MPI d;
        void (*rsa_set_hash_algo)(RSA_T *rsa, HASH_ALGO_ID hash_algo);
        void (*rsa_set_padding_mode)(RSA_T *rsa,
                                     RSA_PADDING_MODE padding_mode);
        int (*rsa_set_key)(RSA_T *rsa, RSA_KEY_TYPE key_type,
                           UINT8 *key, UINT32 len);
        /*int (*rsa_public_decrypt)(RSA_T *rsa, UINT8 *in,
                                                UINT8 *out, UINT32 len);*/
        int (*rsa_verfiy)(RSA_T *rsa,  UINT8 *digest,
                          UINT32 digest_size, UINT8 *sigbuf, UINT32 siglen);
        int (*rsa_set_rsa_verify_callback)(RSA_T *rsa,
                int (*rsa_verify_callback)(UINT8 *digest, UINT32 digest_size, UINT8 *dec_sigbuf, UINT32 dec_sigbuf_size));
        int (*rsa_verify_callback)(UINT8 *digest, UINT32 digest_size,
                                   UINT8 *dec_sigbuf, UINT32 dec_sigbuf_size);
};

extern void rsa_init(RSA_T *rsa) ;
extern void rsa_clean(RSA_T *rsa) ;


#define RSA_DBG(fmt, args...)               rtd_printk(KERN_DEBUG, "RSA","[DBG] " fmt, ## args)
#define RSA_INFO(fmt, args...)              rtd_printk(  KERN_INFO , "RSA",  "[Info] " fmt, ## args)
#define RSA_WARNING(fmt, args...)       rtd_printk( KERN_WARNING , "RSA", "[Warn] " fmt, ## args)
#define RSA_ERR(fmt, args...)       rtd_printk( KERN_ERR , "RSA", "[Err] " fmt, ## args)


#endif

