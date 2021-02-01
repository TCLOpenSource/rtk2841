#ifndef __RSA_API_H__
#define __RSA_API_H__
#include <rtk_kdriver/mcp/rsa_lib.h>
#include <rtk_kdriver/mcp/rsa_util.h>

extern RSA_T *  RSA_new(void);
extern void  RSA_free(RSA_T *rsa);
extern void RSA_set_hash_algo(RSA_T *rsa, HASH_ALGO_ID hash_algo);
extern void RSA_set_padding_mode(RSA_T *rsa,
					RSA_PADDING_MODE padding_mode);
extern int RSA_set_key(RSA_T *rsa, RSA_KEY_TYPE key_type,
					RSA_INPUT_TYPE key_input_type, UINT8 *key, UINT32 len);
extern int RSA_verfiy(RSA_T *rsa,  UINT8 *digest,
			UINT32 digest_size, UINT8 *sigbuf, UINT32 siglen);
extern void RSA_set_verify_callback(RSA_T *rsa,
                int (*rsa_verify_callback)(UINT8 *digest, UINT32 digest_size, UINT8 *dec_sigbuf, UINT32 dec_sigbuf_size));
#endif