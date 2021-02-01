#ifndef __SCALER_HDCP2DEV_H__
#define __SCALER_HDCP2DEV_H__

/*-----------------------------------------------------------------------------
	Definition of struct for IO ctrl cmd(all parameters include in the same struct)
------------------------------------------------------------------------------*/


typedef struct
{
	unsigned char *pKeySet;
	unsigned char *dst_file_path;
	int keyLength;
}HDCP2_WRITE_KEYSET_PARA_T;

typedef struct
{
	unsigned char *pEncKey;
	unsigned char *src_file_path;
	int *keyLen;
}HDCP2_GET_ENCHDCP2KEY_PARA_T;

typedef struct
{
	unsigned char *pRootPublicKey;
	unsigned char *src_file_path;
}HDCP2_GET_ROOTPUBLICKEY_PARA_T;

typedef struct
{
	unsigned char *pReceiverID;
	unsigned char *pPubKey;
	unsigned char *pReserved;
	unsigned char *pRootSign;
}HDCP2_GET_CERTINFO_PARA_T;

typedef struct
{
	unsigned char *pRtx;
	unsigned char *pRrx;
	unsigned int version;
}HDCP2_KD_KEY_DERIVATION_PARA_T;

typedef struct
{
	unsigned char *pHPrime;
	unsigned char repeater;
	unsigned char *pRtx;
	unsigned char *deviceOptionInfo;
	unsigned int version;
}HDCP2_COMPUTE_H_PRIME_PARA_T;

typedef struct
{
	unsigned char *pLPrime;
	unsigned char *pRn;
	unsigned char *pRrx;
	unsigned int version;
}HDCP2_COMPUTE_L_PRIME_PARA_T;

typedef struct
{
	unsigned char *pEKH_KM;
	unsigned char *pM;
}HDCP2_ENCRYPT_KM_USING_KH_PARA_T;

typedef struct
{
	unsigned char *pEks;
	unsigned char *pRtx;
	unsigned char *pRrx;
	unsigned char *pRn;
	unsigned int version;
}HDCP2_DECRYPT_EKS_PARA_T;

typedef struct
{
	unsigned char *pMaskedDB;
	unsigned char *pDB;
	unsigned char *pDBMask;
}HDCP2_GENERATE_KM_PARA_T;

typedef struct
{
	unsigned char *pEks;
	unsigned char *pRrx;
	unsigned char *pRtx;
	unsigned char *pRn;
	unsigned int version;
}HDCP2_GENERATE_KS_PARA_T;

typedef struct
{
	unsigned char *pOutputBuf;
	unsigned char *pInputBuf;
	int length;;
	unsigned char *pCounter;
}HDCP2_DATA_DECRYPT_PARA_T;

typedef struct
{
	unsigned char *pOutputBuf;
	unsigned char *pInputBuf;
	unsigned int length;
}HDCP2_SHA_PARA_T;

typedef struct
{
	unsigned char *pOutputBuf;
	unsigned char *pInputBuf;
	unsigned int length;
	unsigned char *pKey;
	int keylength;
}HDCP2_HMAC_SHA256_PARA_T;

typedef struct
{
	unsigned char *pOutputBuf;
	unsigned char *pInputBuf;
	int length;
	unsigned char *pkey;
	int keyLength;
	unsigned char *pCounter;
}HDCP2_AES_CTR_PARA_T;

typedef struct
{
	unsigned char *pData;
	int *pLength;
}HDCP2_GET_PROTECTED_DECRYPTIONKEY_PARA_T;

typedef struct
{
	unsigned char *pData;
	int length;
}HDCP2_SET_PROTECTED_DECRYPTIONKEY_PARA_T;

typedef struct
{
	unsigned char *pData;
	int length;
	int *exsit;
}HDCP2_GET_OTPHDCP2KEY_PARA_T;

typedef struct
{
	unsigned char *pVPrime;
	unsigned char *pRxIdListsInfo;
	int infoLength;
}HDCP2_COMPUTE_V_PRIME_PARA_T;

typedef struct
{
	unsigned char *pMPrime;
	unsigned char *pStreamManageInfo;
	int infoLength;
}HDCP2_COMPUTE_M_PRIME_PARA_T;

typedef struct
{
	unsigned char *b14Status;
	unsigned char *b22Status;
}HDCP2_GET_HDCP_STATUS_PARA_T;

typedef struct
{
	unsigned int argc;
	unsigned char *lc128;
	unsigned char *km;
	unsigned char *ks;
}HDCP2_UseTestVector_PARA_T;

#define HDCP2_MAJOR 0   /* dynamic major by default */
#define HDCP2_NR_DEVS 1    /* se0 through se3 */


#define HDCP2_DEVICE_NUM										1
#define HDCP2_DEVICE_NAME										"hdcp2dev"

#define HDCP2_IOC_MAGIC										'h'
#define HDCP2_IOC_WRITE_KEYSET								_IOW(HDCP2_IOC_MAGIC, 1, HDCP2_WRITE_KEYSET_PARA_T)
#define HDCP2_IOC_GET_ENCHDCP2KEY							_IOR(HDCP2_IOC_MAGIC, 2,  HDCP2_GET_ENCHDCP2KEY_PARA_T)
#define HDCP2_IOC_SET_ENCHDCP2KEY							_IOW(HDCP2_IOC_MAGIC, 3, unsigned char *)
#define HDCP2_IOC_GET_ROOTPUBLICKEY							_IOR(HDCP2_IOC_MAGIC, 4, HDCP2_GET_ROOTPUBLICKEY_PARA_T)
#define HDCP2_IOC_GET_CERTINFO								_IOR(HDCP2_IOC_MAGIC, 5, HDCP2_GET_CERTINFO_PARA_T)
#define HDCP2_IOC_GET_CERTINFO2								_IOR(HDCP2_IOC_MAGIC, 6, HDCP2_GET_CERTINFO_PARA_T)
#define HDCP2_IOC_DECRYPT_RSAES_OAEP							_IOW(HDCP2_IOC_MAGIC, 7, unsigned char *)
#define HDCP2_IOC_KD_KEY_DERIVATION							_IOR(HDCP2_IOC_MAGIC, 8, HDCP2_KD_KEY_DERIVATION_PARA_T)
#define HDCP2_IOC_COMPUTE_H_PRIME							_IOW(HDCP2_IOC_MAGIC, 9, HDCP2_COMPUTE_H_PRIME_PARA_T)
#define HDCP2_IOC_COMPUTE_L_PRIME							_IOR(HDCP2_IOC_MAGIC, 10, HDCP2_COMPUTE_L_PRIME_PARA_T)
#define HDCP2_IOC_COMPUTE_KH									_IO(HDCP2_IOC_MAGIC, 11)
#define HDCP2_IOC_ENCRYPT_KM_USING_KH						_IOW(HDCP2_IOC_MAGIC, 12, HDCP2_ENCRYPT_KM_USING_KH_PARA_T)
#define HDCP2_IOC_DECRYPT_KM_USING_KH						_IOW(HDCP2_IOC_MAGIC, 13, HDCP2_ENCRYPT_KM_USING_KH_PARA_T)
#define HDCP2_IOC_DECRYPT_EKS									_IOW(HDCP2_IOC_MAGIC, 14, HDCP2_DECRYPT_EKS_PARA_T)
#define HDCP2_IOC_XOR_KS_WITH_LC128							_IO(HDCP2_IOC_MAGIC, 15)
#define HDCP2_IOC_GENERATE_KM									_IOW(HDCP2_IOC_MAGIC, 16, HDCP2_GENERATE_KM_PARA_T)
#define HDCP2_IOC_GENERATE_KS									_IOW(HDCP2_IOC_MAGIC, 17, HDCP2_GENERATE_KS_PARA_T)
#define HDCP2_IOC_DATA_DECRYPT								_IOW(HDCP2_IOC_MAGIC, 18, HDCP2_DATA_DECRYPT_PARA_T)
#define HDCP2_IOC_SHA1											_IOR(HDCP2_IOC_MAGIC, 19, HDCP2_SHA_PARA_T)
#define HDCP2_IOC_SHA256										_IOW(HDCP2_IOC_MAGIC, 20, HDCP2_SHA_PARA_T)
#define HDCP2_IOC_HMAC_SHA256									_IOW(HDCP2_IOC_MAGIC, 21, HDCP2_HMAC_SHA256_PARA_T)
#define HDCP2_IOC_AES_CTR										_IOW(HDCP2_IOC_MAGIC, 22, HDCP2_AES_CTR_PARA_T)
#define HDCP2_IOC_SELECT_STOREDKM							_IOW(HDCP2_IOC_MAGIC, 23, int)
#define HDCP2_IOC_WRITE_STOREDKM								_IOW(HDCP2_IOC_MAGIC, 24, int)
#define HDCP2_IOC_DATA_ENCRYPT								_IOW(HDCP2_IOC_MAGIC, 25, HDCP2_DATA_DECRYPT_PARA_T)
#define HDCP2_IOC_GET_PROTECTED_DECRYPTIONKEY				_IOR(HDCP2_IOC_MAGIC, 26, HDCP2_GET_PROTECTED_DECRYPTIONKEY_PARA_T)
#define HDCP2_IOC_SET_PROTECTED_DECRYPTIONKEY				_IOW(HDCP2_IOC_MAGIC, 27, HDCP2_SET_PROTECTED_DECRYPTIONKEY_PARA_T)
#define HDCP2_IOC_HDCP_INIT									_IO(HDCP2_IOC_MAGIC, 28)
#define HDCP2_IOC_GET_OTPHDCP2KEY						_IOW(HDCP2_IOC_MAGIC, 29, HDCP2_GET_OTPHDCP2KEY_PARA_T)
#define HDCP2_IOC_COMPUTE_V_PRIME							_IOW(HDCP2_IOC_MAGIC, 30, HDCP2_COMPUTE_V_PRIME_PARA_T)
#define HDCP2_IOC_COMPUTE_M_PRIME							_IOR(HDCP2_IOC_MAGIC, 31, HDCP2_COMPUTE_M_PRIME_PARA_T)
#define HDCP2_IOC_GET_HDCP_STATUS							_IOR(HDCP2_IOC_MAGIC, 32, HDCP2_GET_HDCP_STATUS_PARA_T)
#define HDCP2_IOC_UseTestVector							_IOW(HDCP2_IOC_MAGIC, 33, HDCP2_UseTestVector_PARA_T)

#define HDCP2_IOC_MAXNR							33

#endif

