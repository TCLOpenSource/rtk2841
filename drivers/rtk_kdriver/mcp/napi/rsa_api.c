#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <rtk_kdriver/mcp/rsa_api.h>

RSA_T *  RSA_new(void)
{
        RSA_T *rsa = (RSA_T *)kzalloc(sizeof(RSA_T), GFP_KERNEL);
        if(rsa)
                rsa_init(rsa);
        return rsa;
}

void  RSA_free(RSA_T *rsa)
{
        if(rsa) {
                rsa_clean(rsa);
                kfree(rsa);
        }
}

int RSA_set_key(RSA_T *rsa, RSA_KEY_TYPE key_type,
                RSA_INPUT_TYPE key_input_type, UINT8 *key, UINT32 len)
{
        int ret = 0;
        unsigned char *tmp_buffer = NULL;
        int total = 0;
        if(!rsa || !key || !len)
                return -EINVAL;
        if(key_input_type == RSA_INPUT_TYPE_CHAR_ARRAY_LITTLE_ENDIAN) {
                int space = 0;
                total = len;
                space = len % BYTES_PER_MPI_LIMB;
                if(space)
                        total = len + BYTES_PER_MPI_LIMB - space;

                tmp_buffer = kzalloc(total, GFP_KERNEL);
                if(!tmp_buffer)
                        return -ENOMEM;
                if(space)
                        memcpy(tmp_buffer + BYTES_PER_MPI_LIMB - space, key, len);
                else
                        memcpy(tmp_buffer, key, len);
                change_byte_array_endian(tmp_buffer, total);
        } else if(key_input_type == RSA_INPUT_TYPE_HEX_STRING) {
                int i = 0;
                if(len < 2)
                        return -EINVAL;
                total = len / 2;
                tmp_buffer = kzalloc(total, GFP_KERNEL);
                if(!tmp_buffer)
                        return -ENOMEM;
                for(i = 0; i < total; i++)
                        tmp_buffer[i] = (hex_to_dec(key[2 * i]) << 4) | 
                                                        hex_to_dec(key[2 * i + 1]);
        } else if(key_input_type == RSA_INPUT_TYPE_CHAR_ARRAY_BIG_ENDIAN) {
                total = len ;
                tmp_buffer = key;
        } else {
                return -EINVAL;
        }
        ret = rsa->rsa_set_key(rsa, key_type, tmp_buffer, total);
        if(key_input_type == RSA_INPUT_TYPE_CHAR_ARRAY_LITTLE_ENDIAN
            || key_input_type == RSA_INPUT_TYPE_HEX_STRING)
                kfree(tmp_buffer);
        return ret;
}

void RSA_set_hash_algo(RSA_T *rsa, HASH_ALGO_ID hash_algo)
{
        if(rsa)
                rsa->rsa_set_hash_algo(rsa, hash_algo);
}

void RSA_set_padding_mode(RSA_T *rsa,
                          RSA_PADDING_MODE padding_mode)
{
        if(rsa)
                rsa->rsa_set_padding_mode(rsa, padding_mode);
}

void RSA_set_verify_callback(RSA_T *rsa,
                int (*rsa_verify_callback)(UINT8 *digest, UINT32 digest_size, UINT8 *dec_sigbuf, UINT32 dec_sigbuf_size))
{
        if(rsa)
                rsa->rsa_set_rsa_verify_callback(rsa, rsa_verify_callback);
}


int RSA_verfiy(RSA_T *rsa,  UINT8 *digest,
               UINT32 digest_size, UINT8 *sigbuf, UINT32 siglen)
{
        if(rsa && digest && digest_size && sigbuf && siglen)
                return rsa->rsa_verfiy(rsa, digest, digest_size, sigbuf, siglen);
        return -EINVAL;
}

#if 0
/************************only for test*********************************/

static unsigned char * convert_hex_to_octet_array
                (unsigned char *octet_str, unsigned char *hex_str, unsigned int hex_str_len)
{
        int i = 0;
        int j = 0;
        for(i = 0; i < hex_str_len / 2; i++) {
                   octet_str[i] =  (hex_to_dec(hex_str[2 * i]) << 4) | 
                                                        hex_to_dec(hex_str[2 * i + 1]);
        }
        return octet_str;
        
}

static int verify_callback(UINT8 *digest, UINT32 digest_size, UINT8 *dec_sigbuf, UINT32 dec_sigbuf_size)
{
        dump_mem_buffer("digest", digest, digest_size);
        dump_mem_buffer("dec_sigbuf", dec_sigbuf, dec_sigbuf_size);
        return 0;
}

static int __init rsa_module_test(void)
{
        unsigned char output[256] = {0};              
        int ret;
        char signature_str[] = 
        "4770653416bb3a0bc936748b87df62f7db6f5a11937e71abc7ac4c419ed3971dde2f9e198680b0e004528d9290e028efc3a7750a3846ac27be2b6e4ca23e70a1850262743a5880699f112ad20340359095dbfe096d3c43f90af1467972bfea5ae30d29341ecae263e1be2b22c007e68269f00e18bf595f4ea106bea102d24f4d6b4ae1834195f82250e4b47b5b10b450da8df3f952f4d220e002f3b9df94d19172702d4f19f071fade3c282fdb291f846a95d9e677580bc462b63657d22692eb7edddf1f72283785e6a873c3db838fb68298840cd7e19ded1ec0e0e860c42dbf1a53715a291c1128421461a8f6e3ad71e478003db618421576b35bdc72f3acea";
         char rsa_key_str[] = 
        "f122bb19ebf350ed424e339a27b5017cb36eafc6f13cf95cccba7251b3d881f88163f9dcf9337401a61c98d623bc08d0327ea1b16e49838c8d9234961500d10b4edb245381182d06dc70ae56bfb363fcc7855a8b85e63152493bcc263ee8428230b4da1e3e1799c669a5df5f01f0c4dd82706055ad500389fd8573bbecd267ffe592144bb1c4499fac14065f1a1dd09de051de456dafe18e1c64495888d3d380a279cc1a0bf610993b08b497882c476925a31a335d859e5ef0ba131ea7090f3d7c548ebaa01b9a9ac19c25d69974645521852c2c49920c6477e9e9c19220f7f4ae3d9c8903b834e89f13b85bf71d83dee805caeadf86f9a5533e0a9915026ff3";
        unsigned char hash_value[] = "3636363636363636363636363636363636363636363636363636363636363636";
        unsigned int exp = 65537;
        /*expect:0001ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff003031300d0609608648016503040201050004203636363636363636363636363636363636363636363636363636363636363636*/
        printk("====================RSATest_start================================\n");
        RSA_T * rsa = RSA_new();
        RSA_set_key(rsa, RSA_KEY_N, RSA_INPUT_TYPE_HEX_STRING,
                                                        rsa_key_str, sizeof(rsa_key_str));
        
        RSA_set_key(rsa, RSA_KEY_E, RSA_INPUT_TYPE_CHAR_ARRAY_LITTLE_ENDIAN,
                                                        &exp, sizeof(int));
        
        //RSA_set_verify_callback(rsa, verify_callback);
        ret = RSA_verfiy(rsa, 
                convert_hex_array_to_octet_array(hash_value, hash_value, 64), 32, 
                convert_hex_array_to_octet_array(signature_str, signature_str, 512), 
                        256);
        RSA_free(rsa);
        printk("RSA verfiy %s\n", (ret == 0) ? "sucess" : "fail");
        printk("====================RSATest_end================================\n");
}

module_init(rsa_module_test);
#endif