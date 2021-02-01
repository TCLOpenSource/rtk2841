#ifndef __RTK_RCP_H__
#define __RTK_RCP_H__

#define MAX_CW_ENTRY 128
#define KEY_OTP NULL
#define KEY_CW(key_entry)  ((unsigned char *)((key_entry) + 1))


int RTK_RCP_DES_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[7],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_DES_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_DES_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_DES_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_DES_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_DES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[7],
    unsigned char           IV[8],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_DES_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_DES_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_DES_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_DES_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_TDES_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[21],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_TDES_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_TDES_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_TDES_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_TDES_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_TDES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[21],
    unsigned char           IV[8],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_TDES_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_TDES_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_TDES_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_TDES_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_CTR_Cipher_ex(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen,
    unsigned char           word_align  /*It seems stranged, from old api*/
);



int RTK_RCP_AES_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_CTR_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_CTR_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_CTR_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_CTR_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_WIDEVINE_AES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV_In[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_WIDEVINE_AES_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_WIDEVINE_AES_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_WIDEVINE_AES_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_WIDEVINE_AES_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_192_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_192_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_192_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_192_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_192_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_192_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_192_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_192_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_192_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_192_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_192_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_192_CTR_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_192_CTR_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_192_CTR_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_192_CTR_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_256_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_256_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_256_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_256_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_256_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_256_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_256_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_256_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_256_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_256_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_AES_256_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_AES_256_CTR_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_256_CTR_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_AES_256_CTR_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_AES_256_CTR_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)


int RTK_RCP_CAM_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_CTR_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_CTR_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_CTR_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_CTR_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_192_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_192_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_192_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_192_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_192_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_192_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_192_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_192_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_192_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_192_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_192_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_192_CTR_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_192_CTR_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_192_CTR_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_192_CTR_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_256_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_256_ECB_Encryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_256_ECB_Cipher(1, Key, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_256_ECB_Decryption(Key, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_256_ECB_Cipher(0, Key, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_256_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_256_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_256_CBC_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_256_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_256_CBC_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_CAM_256_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
);

#define RTK_RCP_CAM_256_CTR_Encryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_256_CTR_Cipher(1, Key, IV, pDataIn, pDataOut, DataLen)
#define RTK_RCP_CAM_256_CTR_Decryption(Key, IV, pDataIn, pDataOut, DataLen)       RTK_RCP_CAM_256_CTR_Cipher(0, Key, IV, pDataIn, pDataOut, DataLen)

int RTK_RCP_SET_CW(unsigned int id, unsigned char* pCW, unsigned int len);
int RTK_RCP_GET_CW(unsigned int id, unsigned char* pCW, unsigned int len);

int RTK_RCP_CW_XOR(int CwIn1, int CwIn2, int CwOut);

static inline void xor_array(unsigned char* in1, unsigned char* in2, unsigned char* out, unsigned long len)
{
    int i = 0;
    for (i=0; i<len; i++)
        out[i] = in1[i]^in2[i];
}


#endif
