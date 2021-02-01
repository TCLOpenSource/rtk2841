#include <linux/kernel.h>
#include <linux/module.h>
#include <crypto/public_key.h>
#include <rtk_kdriver/mcp/rsa_lib.h>
#include <rtk_kdriver/mcp/rsa_util.h>
static int rsa_set_hash_algo(RSA_T *rsa, HASH_ALGO_ID hash_algo)
{
        if(hash_algo >= HASH_ALGO_ID_MD4
            && hash_algo < HASH_ALGO_ID_LAST) {
                mutex_lock(&rsa->mutex);
                rsa->hash_algo = hash_algo;
                mutex_unlock(&rsa->mutex);
                return 0;
        }
        return -1;
}
static int rsa_set_padding_mode(RSA_T *rsa,
                                RSA_PADDING_MODE padding_mode)
{
        if(padding_mode == RSA_PKCS1_PADDING) {
                mutex_lock(&rsa->mutex);
                rsa->padding_mode = padding_mode;
                mutex_unlock(&rsa->mutex);
                return 0;
        }
        return -1;
}

static int rsa_set_rsa_verify_callback(RSA_T *rsa,
                int (*rsa_verify_callback)(UINT8 *digest, UINT32 digest_size, UINT8 *dec_sigbuf, UINT32 dec_sigbuf_size))
{
        mutex_lock(&rsa->mutex);
        rsa->rsa_verify_callback = rsa_verify_callback;
        mutex_unlock(&rsa->mutex);
        return 0;
}

static int rsa_set_key(RSA_T *rsa, RSA_KEY_TYPE key_type,
                       UINT8 *key, UINT32 len)
{
        int ret = -EINVAL;
        MPI tmp = NULL;
        MPI prev = NULL;
        if(key && len)
                tmp = mpi_read_raw_data(key, len);
        if(tmp) {
                ret = 0;
                mutex_lock(&rsa->mutex);
                if(key_type == RSA_KEY_N) {
                        prev = rsa->n;
                        rsa->n = tmp;
                        tmp = NULL;
                        /*dump_mpi_value("RSA_KEY_N:", rsa->n, 256);*/
                } else if(key_type == RSA_KEY_E) {
                        prev = rsa->e;
                        rsa->e = tmp;
                        tmp = NULL;
                        /*dump_mpi_value("RSA_KEY_E:", rsa->e, 4);*/
                } else if(key_type == RSA_KEY_D) {
                        prev = rsa->d;
                        rsa->d = tmp;
                        tmp = NULL;
                } else {
                        ret = -EINVAL;
                }
                mutex_unlock(&rsa->mutex);
        }
        if(tmp != NULL)
                mpi_free(tmp);
        if(prev != NULL)
                mpi_free(prev);
        return ret;
}

/*
 * Perform the verification step [RFC3447 sec 8.2.2].
 */

static int rsa_verfiy(RSA_T *rsa,  UINT8 *digest, UINT32 digest_size,
                                        UINT8 *sigbuf, UINT32 siglen)
{
        int ret = -1;
        MPI sig = NULL;
        if(sigbuf && siglen)
                sig = mpi_read_raw_data(sigbuf, siglen);
        if(sig == NULL)
                return -1;
        /*dump_mpi_value("Signature:", sig, 256);*/
        /* Variables as per RFC3447 sec 8.2.2 */
        mutex_lock(&rsa->mutex);
        if(rsa->n == NULL || rsa->e == NULL) {
                ret = -EINVAL;
                mutex_unlock(&rsa->mutex);
                if(sig != NULL)
                        mpi_free(sig);
                return ret;
        }
        ret = rsa_verify_signature(rsa, sig, siglen, digest, digest_size);
        mutex_unlock(&rsa->mutex);
        if(sig != NULL)
                mpi_free(sig);
        return ret;
}

void rsa_init(RSA_T *rsa)
{
        if(rsa) {
                mutex_init(&rsa->mutex);
                rsa->hash_algo = HASH_ALGO_SHA256;
                rsa->padding_mode = RSA_PKCS1_PADDING;
                rsa->rsa_set_hash_algo = rsa_set_hash_algo;
                rsa->rsa_set_padding_mode = rsa_set_padding_mode;
                rsa->rsa_set_key = rsa_set_key;
                rsa->rsa_verfiy = rsa_verfiy;
                rsa->rsa_set_rsa_verify_callback = rsa_set_rsa_verify_callback;
                rsa->rsa_verify_callback = NULL;
        }
}

void rsa_clean(RSA_T *rsa)
{
        if(rsa) {
                if(rsa->d) {
                        mpi_free(rsa->d);
                        rsa->d = NULL;
                }
                if(rsa->e) {
                        mpi_free(rsa->e);
                        rsa->e = NULL;
                }
                if(rsa->n) {
                        mpi_free(rsa->n);
                        rsa->n = NULL;
                }
                memset(rsa, 0, sizeof(RSA_T));
        }
}

