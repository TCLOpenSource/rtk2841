#include <linux/mpi.h>
#include <crypto/algapi.h>
#include <rtk_kdriver/mcp/rsa_lib.h>
/*
 * Hash algorithm OIDs plus ASN.1 DER wrappings [RFC4880 sec 5.2.2].
 */
static const u8 RSA_digest_info_MD5[] = {
        0x30, 0x20, 0x30, 0x0C, 0x06, 0x08,
        0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x02, 0x05, /* OID */
        0x05, 0x00, 0x04, 0x10
};

static const u8 RSA_digest_info_SHA1[] = {
        0x30, 0x21, 0x30, 0x09, 0x06, 0x05,
        0x2B, 0x0E, 0x03, 0x02, 0x1A,
        0x05, 0x00, 0x04, 0x14
};

static const u8 RSA_digest_info_RIPE_MD_160[] = {
        0x30, 0x21, 0x30, 0x09, 0x06, 0x05,
        0x2B, 0x24, 0x03, 0x02, 0x01,
        0x05, 0x00, 0x04, 0x14
};

static const u8 RSA_digest_info_SHA224[] = {
        0x30, 0x2d, 0x30, 0x0d, 0x06, 0x09,
        0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x04,
        0x05, 0x00, 0x04, 0x1C
};

static const u8 RSA_digest_info_SHA256[] = {
        0x30, 0x31, 0x30, 0x0d, 0x06, 0x09,
        0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01,
        0x05, 0x00, 0x04, 0x20
};

static const u8 RSA_digest_info_SHA384[] = {
        0x30, 0x41, 0x30, 0x0d, 0x06, 0x09,
        0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x02,
        0x05, 0x00, 0x04, 0x30
};

static const u8 RSA_digest_info_SHA512[] = {
        0x30, 0x51, 0x30, 0x0d, 0x06, 0x09,
        0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x03,
        0x05, 0x00, 0x04, 0x40
};

static const struct {
        const u8 *data;
        size_t size;
} RSA_ASN1_templates[HASH_ALGO_ID_LAST] = {
#define _(X) { RSA_digest_info_##X, sizeof(RSA_digest_info_##X) }
        [HASH_ALGO_ID_MD5]         = _(MD5),
        [HASH_ALGO_ID_SHA1]        = _(SHA1),
        [HASH_ALGO_ID_RIPE_MD_160] = _(RIPE_MD_160),
        [HASH_ALGO_ID_SHA256]      = _(SHA256),
        [HASH_ALGO_ID_SHA384]      = _(SHA384),
        [HASH_ALGO_ID_SHA512]      = _(SHA512),
        [HASH_ALGO_ID_SHA224]      = _(SHA224),
#undef _
};
void change_byte_array_endian(UINT8 *buffer, UINT32 len)
{
        int i = 0, j = 0;
        int loop = 0;
        loop = len / BYTES_PER_MPI_LIMB;
        for(i = 0; i < loop; i++)
                for(j = 0; j < BYTES_PER_MPI_LIMB / 2; j++) {
                        unsigned char tmp = buffer[BYTES_PER_MPI_LIMB * i + j];
                        buffer[BYTES_PER_MPI_LIMB * i + j] =
                                buffer[BYTES_PER_MPI_LIMB * i + BYTES_PER_MPI_LIMB - j - 1];
                        buffer[BYTES_PER_MPI_LIMB * i + BYTES_PER_MPI_LIMB - j - 1] = tmp;
                }
}

static int convert_mpi_to_char_array(MPI x, unsigned char *array, unsigned int len)
{
        int ret = -1;
        unsigned int x_size = 0;
        unsigned char *x_buf = NULL;
        if(x && array && len > 0) {
                x_buf = mpi_get_buffer(x, &x_size, NULL);
                if(!x_buf) {
                        ret = -ENOMEM;
                        goto exit;
                }
                if(len >= x_size)
                        memcpy(array + len - x_size, x_buf, x_size);
                else
                        memcpy(array, x_buf + x_size - len, len);
                kfree(x_buf);
                ret = 0;
        }
exit:
        return ret;
}

unsigned char hex_to_dec(unsigned char hex)
{
        if(hex >= '0' && hex <= '9')
                return hex - '0';
        else if(hex >= 'a' && hex <= 'f')
                return hex - 'a' + 0xa;
        else if(hex >= 'A' && hex <= 'F')
                return hex - 'A' + 0xa;
        return 0;
}

void dump_mem_buffer(char *name, unsigned char *octet_str, unsigned int len)
{
        int i = 0;
        printk("****************dump_mem_buffer[%s]*******************\n", name);
        for(i = 0; i < len; i++) {
                   printk("%02x", octet_str[i]);
        }
        printk("\n**************************************************\n");
}

void dump_mpi_value(char *name, MPI x, unsigned int len)
{
        int res = 0;
        unsigned char *buffer = NULL;
        if(x == NULL || len == 0)
                return;
        buffer = kzalloc(len, GFP_ATOMIC);
        if(!buffer)
                return;
        res = convert_mpi_to_char_array(x, buffer, len);
        if(res == 0)
                dump_mem_buffer(name, buffer, len);
        kfree(buffer);
}


/*
*Function:Convert a dec array to a mpi.This dec array should be Little indian 
*and msb int first.
*Note: the ret value should be free by caller.
*/
MPI get_mpi_from_char_array(unsigned char *buffer, unsigned int len, UINT8 convert)
{
        MPI res = NULL;
        int space = 0;
        int total = len;
        unsigned char *tmp_buffer = NULL;
        if(len == 0)
                return res;
        space = len % BYTES_PER_MPI_LIMB;
        if(space)
                total = len + BYTES_PER_MPI_LIMB - space;
        
        tmp_buffer = kzalloc(total, GFP_KERNEL);
        if(!tmp_buffer)
                return res;
        if(space)
                memcpy(tmp_buffer + BYTES_PER_MPI_LIMB - space, buffer, len);
        else
                memcpy(tmp_buffer, buffer, len);
        if(convert)
                change_byte_array_endian(tmp_buffer, total);
        res = mpi_read_raw_data(tmp_buffer, total);
        kfree(tmp_buffer);
        return res;
        
}

static int rsa_decrypt(MPI n, MPI e, MPI s, MPI *_m)
{
        int ret = -1;
        MPI m;
        if (mpi_cmp_ui(s, 0) < 0) {
                RSA_DBG(" = -EBADMSG [s < 0]");
                return -EBADMSG;
        }
        if (mpi_cmp(s, n) >= 0) {
                RSA_DBG(" = -EBADMSG [s >= n]");
                return -EBADMSG;
        }
        m = mpi_alloc(0);
        if (!m)
                return -ENOMEM;

        /* (2) m = s^e mod n */
        ret = mpi_powm(m, s, e, n);
        if (ret < 0) {
                mpi_free(m);
                return ret;
        }

        *_m = m;
        return 0;
}

static UINT8* rsa_mpi_to_char_array(MPI x, unsigned int len)
{
        unsigned int x_size = 0;
        unsigned char *x_buf = NULL;
        UINT8 *tmp_buffer = NULL;
        if(x && len) {
                tmp_buffer = kzalloc(len, GFP_KERNEL);
                if(!tmp_buffer)
                        goto exit;
                x_buf = mpi_get_buffer(x, &x_size, NULL);
                if(!x_buf) 
                        goto exit;
                if(len >= x_size)
                        memcpy(tmp_buffer + len - x_size, x_buf, x_size);
                else
                        memcpy(tmp_buffer, x_buf + x_size - len, len);
                kfree(x_buf);
                return tmp_buffer;
        }
exit:
        if(tmp_buffer)
                kfree(tmp_buffer);
        if(x_buf)
                kfree(x_buf);                       
        return NULL;
}

static int rsa_i2osp(MPI x, size_t xLen, u8 **pX)
{
	unsigned X_size, x_size;
	int X_sign;
	u8 *X;

	/* Make sure the string is the right length.  The number should begin
	 * with { 0x00, 0x01, ... } so we have to account for 15 leading zero
	 * bits not being reported by MPI.
	 */
	x_size = mpi_get_nbits(x);
	RSA_DBG("size(x)=%u xLen*8=%zu\n", x_size, xLen * 8);
	if (x_size != xLen * 8 - 15)
		return -ERANGE;

	X = mpi_get_buffer(x, &X_size, &X_sign);
	if (!X)
		return -ENOMEM;
	if (X_sign < 0) {
		kfree(X);
		return -EBADMSG;
	}
	if (X_size != xLen - 1) {
		kfree(X);
		return -EBADMSG;
	}

	*pX = X;
	return 0;
}

static int default_rsa_verify(const u8 *H, const u8 *EM, size_t k, size_t hash_size,
		      const u8 *asn1_template, size_t asn1_size)
{
	unsigned PS_end, T_offset, i;
	if (k < 2 + 1 + asn1_size + hash_size)
		return -EBADMSG;
	/* Decode the EMSA-PKCS1-v1_5 */
	if (EM[1] != 0x01) {
		RSA_DBG(" = -EBADMSG [EM[1] == %02u]", EM[1]);
		return -EBADMSG;
	}

	T_offset = k - (asn1_size + hash_size);
	PS_end = T_offset - 1;
	if (EM[PS_end] != 0x00) {
		RSA_DBG(" = -EBADMSG [EM[T-1] == %02u]", EM[PS_end]);
		return -EBADMSG;
	}

	for (i = 2; i < PS_end; i++) {
		if (EM[i] != 0xff) {
			RSA_DBG(" = -EBADMSG [EM[PS%x] == %02u]", i - 2, EM[i]);
			return -EBADMSG;
		}
	}

	if (crypto_memneq(asn1_template, EM + T_offset, asn1_size) != 0) {
		RSA_DBG(" = -EBADMSG [EM[T] ASN.1 mismatch]");
		return -EBADMSG;
	}

	if (crypto_memneq(H, EM + T_offset + asn1_size, hash_size) != 0) {
		RSA_DBG(" = -EKEYREJECTED [EM[T] hash mismatch]");
		return -EKEYREJECTED;
	}
	return 0;
}

/*
 * Perform the verification step [RFC3447 sec 8.2.2].
 */
int rsa_verify_signature(RSA_T *rsa, MPI sig, UINT32 sig_size, UINT8 *digest, UINT8 *digest_len)
{
        size_t tsize;
        int ret;
        /* Variables as per RFC3447 sec 8.2.2 */
        const u8 *H = digest;
        MPI m = NULL;
        size_t k;
        unsigned char *tmp_buffer = NULL;
        if (!RSA_ASN1_templates[rsa->hash_algo].data && !rsa->rsa_verify_callback)
                return -ENOTSUPP;
        /* (1) Check the signature size against the public key modulus size */
        k = mpi_get_nbits(rsa->n);
        tsize = mpi_get_nbits(sig);

        /* According to RFC 4880 sec 3.2, length of MPI is computed starting
         * from most significant bit.  So the RFC 3447 sec 8.2.2 size check
         * must be relaxed to conform with shorter signatures - so we fail here
         * only if signature length is longer than modulus size.
         */
        /*printk("step 1: k=%zu size(S)=%zu\n", k, tsize);*/
        if (k < tsize) {
                ret = -EBADMSG;
                goto error;
        }
        /* Round up and convert to octets */
        k = (k + 7) / 8;

        /* (2b) Apply the RSAVP1 verification primitive to the public key */
        ret = rsa_decrypt(rsa->n, rsa->e, sig, &m);
        if (ret < 0)
                goto error;
        tmp_buffer = rsa_mpi_to_char_array(m, sig_size);
        if(!tmp_buffer) {
                ret = -ENOMEM;
                goto error;
        }

        if(rsa->rsa_verify_callback) {
                ret = rsa->rsa_verify_callback(digest, digest_len, tmp_buffer, sig_size);
        } else
                ret = default_rsa_verify(H, tmp_buffer, sig_size, digest_len,
                                 RSA_ASN1_templates[rsa->hash_algo].data,
                                 RSA_ASN1_templates[rsa->hash_algo].size);
error:
        if(tmp_buffer)
                kfree(tmp_buffer);
        mpi_free(m);
        return ret;
}