//Kernel Header file
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/fs.h>		/* everything... */
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <asm/uaccess.h>
#include <mach/irqs.h>
#include <rtk_kdriver/mcp/mcp.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <rtk_kdriver/io.h>

#include "scaler_hdcp2dev.h"
#include <tvscalercontrol/hdcp2_2/hdcp2_messages.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_interface.h>
#include <tvscalercontrol/hdcp2_2/crypto.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_rcp_api.h>
#include <tvscalercontrol/hdcp2_2/hmac.h>


#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdmirx/hdmi_reg.h>

//#include <rbus/hdmi_p0_reg.h>
//#include <mach-rtd289x/rbus/rbusInterruptReg.h>
#include <rtk_kdriver/rtk_hdcp_otp_util.h>
#include <tvscalercontrol/io/ioregdrv.h>

static struct semaphore HDCP2_Semaphore;

#define		BIT0		0x00000001
#define		BIT1		0x00000002
#define		BIT2		0x00000004
#define		BIT3		0x00000008
#define		BIT4		0x00000010
#define		BIT5		0x00000020
#define		BIT6		0x00000040
#define		BIT7		0x00000080
#define		BIT8		0x00000100
#define		BIT9		0x00000200
#define		BIT10		0x00000400

#define DBG_PRINT(s, args...) pr_debug(s, ## args)

static dev_t hdcp2_devno = 0;//vfe device number
static struct cdev hdcp2_cdev;

#define OK true
#define NOT_OK false
#define HDCP_1p4 0

int rtk_hal_hdcp2_WriteKeySet(unsigned char *pKeySet, unsigned char *dst_file_path, int keyLength)
{
#if 0
	int rc = NOT_OK;
	if(pKeySet == NULL || dst_file_path == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_WriteKeySet input paramter is error!\n");
		return NOT_OK;
	}
	if(keyLength != KEYSET_SIZE)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_WriteKeySet keylength is error!\n");
		return NOT_OK;
	}

	rc = hdcp2_save_encrypted_keyset(pKeySet, dst_file_path, keyLength);
	return rc;
#endif
#if 1
	int rc = NOT_OK;
	if(pKeySet == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_WriteKeySet input paramter is error!\n");
		return NOT_OK;
	}
	rc = hdcp2_save_keyset(pKeySet);
#endif
	hdcp2_save_keyset_file(pKeySet,dst_file_path,keyLength);

	return OK;
}

int rtk_hal_hdcp2_GetEncHdcp2Key(unsigned char *pEncKey, unsigned char *src_file_path, int *keyLen)
{
#if 0
	if(pEncKey == NULL || src_file_path == NULL || keyLen == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_GetEncHdcp2Key input paramter is error!\n");
		return NOT_OK;
	}

	read_binary_file(src_file_path, pEncKey, KEYSET_SIZE);
#endif
	return OK;
}

int rtk_hal_hdcp2_SetEncHdcp2Key(unsigned char *pEncKey)
{
#if 0
	if(pEncKey == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_GetEncHdcp2Key input paramter is error!\n");
		return NOT_OK;
	}

	write_binary_file(src_file_path, pEncKey, KEYSET_SIZE);
#endif
	return OK;


}

int rtk_hal_hdcp2_GetRootPublicKey(unsigned char *pRootPublicKey, unsigned char *src_file_path)
{
#if 0
	int rc = NOT_OK;

	if(pRootPublicKey == NULL || src_file_path == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_GetRootPublicKey input paramter is error!\n");
		return NOT_OK;
	}

	rc = hdcp2_load_encrypted_keyset(pRootPublicKey, src_file_path, DCP_LLC_KEY_SIZE+15);
	return rc;
#endif
	return OK;
}

int rtk_hal_hdcp2_GetCertInfo(unsigned char *pReceiverID, unsigned char *pPubKey, unsigned char *pRootSign)
{
	unsigned char certInfo[CERT_RX_SIZE] = {0x00};
	if(pReceiverID == NULL || pPubKey == NULL || pRootSign == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_GetCertInfo input paramter is error!\n");
		return NOT_OK;
	}

	hdcp2_Rx_GetCertRx(certInfo, CERT_RX_SIZE);
	memcpy(pReceiverID, certInfo, RECEIVER_ID_SIZE);
	memcpy(pPubKey, &certInfo[RECEIVER_ID_SIZE], KEY_PUBLIC_RX_SIZE);
	//memcpy(pReserved, &certInfo[RECEIVER_ID_SIZE+KEY_PUBLIC_RX_SIZE], RESERVED_SIZE);
	memcpy(pRootSign, &certInfo[RECEIVER_ID_SIZE+KEY_PUBLIC_RX_SIZE+RESERVED_SIZE], DCP_LLC_SIG_SIZE);
	return OK;


}

int rtk_hal_hdcp2_GetCertInfo2(unsigned char *pReceiverID, unsigned char *pPubKey, unsigned char *pReserved, unsigned char *pRootSign)
{
	unsigned char certInfo[CERT_RX_SIZE] = {0x00};
	if(pReceiverID == NULL || pPubKey == NULL || pRootSign == NULL || pReserved == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_GetCertInfo2 input paramter is error!\n");
		return NOT_OK;
	}

	hdcp2_Rx_GetCertRx(certInfo, CERT_RX_SIZE);
	memcpy(pReceiverID, certInfo, RECEIVER_ID_SIZE);
	memcpy(pPubKey, &certInfo[RECEIVER_ID_SIZE], KEY_PUBLIC_RX_SIZE);
	memcpy(pReserved, &certInfo[RECEIVER_ID_SIZE+KEY_PUBLIC_RX_SIZE], RESERVED_SIZE);
	memcpy(pRootSign, &certInfo[RECEIVER_ID_SIZE+KEY_PUBLIC_RX_SIZE+RESERVED_SIZE], DCP_LLC_SIG_SIZE);
	return OK;
}

int rtk_hal_hdcp2_Decrypt_RSAES_OAEP(unsigned char *pEKpubKm)
{
	unsigned char  Km[KM_SIZE] = {0x00};
	unsigned char  KPriv_tmp[KPRIVRX_SIZE] = {0x00};
       H2status rc;

	if(pEKpubKm == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Decrypt_RSAES_OAEP input paramter is error!\n");
		return NOT_OK;
	}

	spu_GetKPrivRx(KPriv_tmp);
	//HDCP2DBGLOG("KPriv_tmp: ", KPriv_tmp, KPRIVRX_SIZE);
	//HDCP2DBGLOG("pEKpubKm: ", pEKpubKm, EKPUBKM_SIZE);
    	rc = Decrypt_EKpubKm_kPrivRx(KPriv_tmp, Km, pEKpubKm);
	HDCP2DBGLOG("km: ", Km, KM_SIZE);
	spu_SetKM(Km);
	RTK_RCP_SET_CW_HDCP2(SRAM_KM_ENTRY , Km, KM_SIZE);
	return rc;
}

int rtk_hal_hdcp2_Kd_Key_Derivation(unsigned char *pRtx, unsigned char *pRrx, unsigned int version)
{
	int modeHDCP22 = 0;
	unsigned char rn[RN_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	unsigned char kd[KD_SIZE] = {0x00};
	//unsigned char km[KM_SIZE];

	if(pRtx == NULL || pRrx == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Kd_Key_Derivation input paramter is error!\n");
		return NOT_OK;
	}

	if(version !=0 && version != 1 && version != 2)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Kd_Key_Derivation input version is error!\n");
		return NOT_OK;
	}

	if(version ==2)
		modeHDCP22 = 1;
	else
		modeHDCP22 = 0;
#if 0 //for test
	spu_GetKM(km);
	HDCP2DBGLOG("km: ", km, KM_SIZE);
	HDCP2DBGLOG("pRtx: ", pRtx, RTX_SIZE);
	HDCP2DBGLOG("pRrx: ", pRrx, RRX_SIZE);
	pr_debug("version = %d\n", modeHDCP22);
#endif
	RCP_HDCP2_GenKd(SRAM_KM_ENTRY, pRtx, pRrx, rn, SRAM_KD_ENTRY,modeHDCP22);
	RTK_RCP_GET_CW_HDCP2(SRAM_KD_ENTRY , kd, KD_SIZE);
	spu_SetKD(kd);
	HDCP2DBGLOG("kD: ", kd, KD_SIZE);
	return OK;
}


int rtk_hal_hdcp2_Compute_H_Prime(unsigned char *pHPrime, unsigned char repeater, unsigned char *pRtx, unsigned char *deviceOptionInfo, unsigned int version)
{
	unsigned char  Kd[KD_SIZE] = {0x00};
	unsigned char  txcaps[TXCAPS_SIZE] = {0x00};
	unsigned char  rxcaps[RXCAPS_SIZE] = {0x00};
	H2status rc;

	if(pHPrime == NULL || pRtx == NULL || deviceOptionInfo == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_H_Prime input paramter is error!\n");
		return NOT_OK;
	}

	if(version !=0 && version != 1 && version != 2)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_H_Prime input version is error!\n");
		return NOT_OK;
	}

	if(repeater !=0 && repeater != 1)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_H_Prime input repeater is error!\n");
		return NOT_OK;
	}

	spu_GetKD(Kd);

	hdcp2_Rx_Setdevinfo(deviceOptionInfo);
	memcpy(rxcaps, deviceOptionInfo, RXCAPS_SIZE);
	memcpy(txcaps, deviceOptionInfo+RXCAPS_SIZE, TXCAPS_SIZE);
#if 0 //for test
	HDCP2DBGLOG("kd: ", Kd, KD_SIZE);
	HDCP2DBGLOG("pRtx: ", pRtx, RTX_SIZE);
	HDCP2DBGLOG("txcaps: ", txcaps, TXCAPS_SIZE);
	HDCP2DBGLOG("rxcaps: ", rxcaps, RXCAPS_SIZE);
#endif
	if(version == 2)
		rc = Compute_Hprime_22_widi(Kd, pRtx, txcaps, rxcaps, repeater, pHPrime);
	else
		rc = Compute_Hprime_Rx(Kd, pRtx, repeater, pHPrime);

	return rc;
}

int rtk_hal_hdcp2_Compute_L_Prime(unsigned char *pLPrime, unsigned char *pRn, unsigned char *pRrx, unsigned int version)
{
	unsigned char  Kd[KD_SIZE] = {0x00};
	H2status rc;

	if(pLPrime == NULL || pRrx == NULL || pRn == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_L_Prime input paramter is error!\n");
		return NOT_OK;
	}

	if(version !=0 && version != 1 && version != 2)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_L_Prime input version is error!\n");
		return NOT_OK;
	}
	spu_GetKD(Kd);
#if 0 //for test
	HDCP2DBGLOG("kd: ", Kd, KD_SIZE);
	HDCP2DBGLOG("pRrx: ", pRrx, RRX_SIZE);
	HDCP2DBGLOG("pRn: ", pRn, RN_SIZE);
#endif
	rc = Compute_Lprime_Rx_widi(Kd, pRrx, pRn, pLPrime);
	return rc;
}

int rtk_hal_hdcp2_Compute_Kh(void)
{
	unsigned char  KPriv_tmp[KPRIVRX_SIZE] = {0x00};
	unsigned char  Kh[KH_SIZE] = {0x00};
	H2status rc;

	spu_GetKPrivRx(KPriv_tmp);
	rc = Compute_Kh (KPriv_tmp, KPRIVRX_SIZE, Kh);

	HDCP2DBGLOG("kh: ", Kh, KH_SIZE);
	return rc;
}

int rtk_hal_hdcp2_Encrypt_Km_using_Kh(unsigned char *pEKh_Km, unsigned char *pM)
{
	H2status rc;

	if(pEKh_Km == NULL || pM == NULL )
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Encrypt_Km_using_Kh input paramter is error!\n");
		return NOT_OK;
	}

	rc = hdcp2_Rx_Compute_EKhKm(pM, pEKh_Km);
	return rc;
}

int rtk_hal_hdcp2_Decrypt_Km_using_Kh(unsigned char *pM, unsigned char *pEkh_Km)
{
	H2status rc;
	unsigned char km[KM_SIZE] = {0x00};

	if(pEkh_Km == NULL || pM == NULL )
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Decrypt_Km_using_Kh input paramter is error!\n");
		return NOT_OK;
	}

	rc = hdcp2_Rx_ParseEKhKm(pEkh_Km,  pM);

	spu_GetKM(km);
	HDCP2DBGLOG("kM: ", km, KH_SIZE);
	return rc;
}

int rtk_hal_hdcp2_Decrypt_EKs(unsigned char *pEKs, unsigned char *pRtx, unsigned char *pRrx, unsigned char *pRn, unsigned int version)
{
	H2status rc;
	int modeHDCP22 = 0;
	unsigned char ks[KS_SIZE] = {0x00};

	if(pEKs == NULL || pRtx == NULL || pRrx == NULL || pRn == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Decrypt_EKs input paramter is error!\n");
		return NOT_OK;
	}

	if(version !=0 && version != 1 && version != 2)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Decrypt_EKs input version is error!\n");
		return NOT_OK;
	}
	if(version ==2)
		modeHDCP22 = 1;
	else
		modeHDCP22 = 0;

	rc = hdcp2_Rx_Compute_EdKeyKs(pRtx, pRrx, pRn, pEKs, modeHDCP22);

	hdcp2_Rx_GetKs(ks, KS_SIZE);
	HDCP2DBGLOG("ks: ", ks, KS_SIZE);
	return rc;
}

int rtk_hal_hdcp2_XOR_Ks_with_LC128(void)
{
	unsigned char KsxorLc128[16] = {0x00};
	down(&HDCP2_Semaphore);

	 hdcp2_GenKsXorLc128();
	 spu_GetKsXorLc128(KsxorLc128);
	 HDCP2DBGLOG("KsxorLc128: ", KsxorLc128, 16);

	 up(&HDCP2_Semaphore);
	return OK;
}

int rtk_hal_hdcp2_Generate_Km(unsigned char *pMaskedDB, unsigned char *pDB, unsigned char *pDBMask)
{
	if(pMaskedDB == NULL || pDB == NULL || pDBMask == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Generate_Km input paramter is error!\n");
		return NOT_OK;
	}
	memset(pMaskedDB, 0, DB_SIZE+4);
	crypt_xor(pDB, pDBMask, pMaskedDB, DB_SIZE);
	return OK;
}

int rtk_hal_hdcp2_Generate_Ks(unsigned char *pEks, unsigned char *pRrx, unsigned char *pRtx, unsigned char *pRn, unsigned int version)
{
	H2status rc;
	int modeHDCP22;

	if(pEks == NULL || pRrx == NULL || pRtx == NULL|| pRn == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Generate_Ks input paramter is error!\n");
		return NOT_OK;
	}

	if(version !=0 && version != 1 && version != 2)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Generate_Ks input version is error!\n");
		return NOT_OK;
	}

	if(version ==2)
		modeHDCP22 = 1;
	else
		modeHDCP22 = 0;
#if 0//for test
	HDCP2DBGLOG("pRrx: ", pRrx, RRX_SIZE);
	HDCP2DBGLOG("pRtx: ", pRtx, RTX_SIZE);
	HDCP2DBGLOG("pRn: ", pRn, RN_SIZE);
#endif
	rc = hdcp2_Verify_EdkeyKs(pEks, pRrx, pRtx, pRn, modeHDCP22);
	return rc;
}

int rtk_hal_hdcp2_Data_Decrypt(unsigned char *pOutputBuf, unsigned char *pInputBuf, int length, unsigned char *pCounter)
{
	unsigned char KsxorLc128[16] = {0x00};
	unsigned char DataCrypto[16] = {0x00};
	down(&HDCP2_Semaphore);

	if(pOutputBuf == NULL || pInputBuf == NULL || pCounter == NULL || length == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Data_Decrypt input paramter is error!\n");
		return NOT_OK;
	}

	spu_GetKsXorLc128(KsxorLc128);
	RTK_RCP_AES_CTR_Decryption(KsxorLc128, pCounter, pInputBuf, pOutputBuf, length);
	if(length % 16)
	{
		RCP_HDCP2_DataDecrypt(SRAM_KS_XOR_LC128_ENTRY,  SRAM_DATA_DECRYPT_ENTRY, KsxorLc128, pCounter);
		RTK_RCP_GET_CW_HDCP2(SRAM_DATA_DECRYPT_ENTRY , DataCrypto, SRAM_DATA_DECRYPT_SIZE);
		spu_SetDateDecrypto(DataCrypto);
		crypt_xor(pInputBuf + length-length % 16 , DataCrypto, pOutputBuf+ length-length % 16, length%16);
	}

	/*HDCP2DBGLOG("pOutputBuf: ", pOutputBuf, length);*/

	up(&HDCP2_Semaphore);
	return OK;
}


int rtk_hal_hdcp2_SHA1(unsigned char * pOutputBuf, unsigned char *pInputBuf, int length)
{
	H2status rc;

	if(pOutputBuf == NULL || pInputBuf == NULL || length == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_SHA1 input paramter is error!\n");
		return NOT_OK;
	}

	rc = Sha1(pInputBuf, length, pOutputBuf);
	return rc;
}

int rtk_hal_hdcp2_SHA256(unsigned char * pOutputBuf, unsigned char *pInputBuf, int length)
{
	H2status rc;

	if(pOutputBuf == NULL || pInputBuf == NULL || length == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_HMAC_SHA256 input paramter is error!\n");
		return NOT_OK;
	}

	rc = Sha256(pInputBuf, length, pOutputBuf);
	return rc;
}

int rtk_hal_hdcp2_HMAC_SHA256(unsigned char * pOutputBuf, unsigned char *pInputBuf, int length, unsigned char *pKey, int keylength)
{
	H2status rc;

	if(pOutputBuf == NULL || pInputBuf == NULL || pKey == NULL || length == 0 || keylength == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_HMAC_SHA256 input paramter is error!\n");
		return NOT_OK;
	}

#if 0//for test
	HDCP2DBGLOG("pKey: ", pKey, keylength);
	HDCP2DBGLOG("pInputBuf: ", pInputBuf, length);
#endif
	rc = hmacsha256( pKey, keylength, pInputBuf, length, pOutputBuf);
	return rc;
}

int rtk_hal_hdcp2_AES_CTR(unsigned char *pOutputBuf, unsigned char *pInputBuf, int length, unsigned char *pkey, int keyLength, unsigned char *pCounter)
{
	if(pOutputBuf == NULL || pInputBuf == NULL || pkey == NULL || pCounter == NULL || length == 0 || keyLength == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_AES_CTR input paramter is error!\n");
		return NOT_OK;
	}
	RTK_RCP_AES_CTR_Decryption(pkey, pCounter, pInputBuf, pOutputBuf, length);
	return OK;
}

int rtk_hal_hdcp2_Select_StoredKm(int index)
{
	unsigned char km[KM_SIZE] = {0x00};
	if(index < 0 || index > 4)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Select_StoredKm index is error!\n");
		return NOT_OK;
	}
	switch(index)
	{
		case 0:
			/*spu_GetKm0(km);*/
			break;
		case 1:
			/*spu_GetKm1(km);*/
			break;
		case 2:
			/*spu_GetKm2(km);*/
			break;
		case 3:
			/*spu_GetKm3(km);*/
			break;
		case 4:
			/*spu_GetKm4(km);*/
			break;
		default:
			break;
	}

	spu_SetKM(km);
	pr_debug("index = %d\n", index);
	HDCP2DBGLOG("KM: ", km, KM_SIZE);
	return OK;
}

int rtk_hal_hdcp2_Write_StoredKm(int index)
{
	unsigned char km[KM_SIZE] = {0x00};
	if(index < 0 || index > 4)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Write_StoredKm index is error!\n");
		return NOT_OK;
	}
	spu_GetKM(km);
	switch(index)
	{
		case 0:
			/*spu_SetKm0(km);*/
			break;
		case 1:
			/*spu_SetKm1(km);*/
			break;
		case 2:
			/*spu_SetKm2(km);*/
			break;
		case 3:
			/*spu_SetKm3(km);*/
			break;
		case 4:
			/*spu_SetKm4(km);*/
			break;
		default:
			break;
	}
	pr_debug("index = %d\n", index);
	HDCP2DBGLOG("KM: ", km, KM_SIZE);
	return OK;
}

int rtk_hal_hdcp2_Data_Encrypt(unsigned char *pOutputBuf, unsigned char *pInputBuf, int length, unsigned char *pCounter)
{
	unsigned char KsxorLc128[16] = {0x00};
	if(pOutputBuf == NULL || pInputBuf == NULL || pCounter == NULL || length == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Data_Encrypt input paramter is error!\n");
		return NOT_OK;
	}

	spu_GetKsXorLc128(KsxorLc128);
	RTK_RCP_AES_CTR_Decryption(KsxorLc128, pCounter, pInputBuf, pOutputBuf, length);
	return OK;
}

int rtk_hal_hdcp2_GetProtectedDecryptionKey(unsigned char *pData, int *pLength)
{
	down(&HDCP2_Semaphore);

	if(pData == NULL || pLength == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_GetProtectedDecryptionKey input paramter is error!\n");
		return NOT_OK;
	}
	hdcp2_Rx_GetKs(pData, KS_SIZE);
	spu_GetLc128(pData+KS_SIZE);

	up(&HDCP2_Semaphore);
	return OK;
}

int rtk_hal_hdcp2_SetProtectedDecryptionKey(unsigned char *pData, int length)
{
	unsigned char KsxorLc128[16] = {0x00};
	down(&HDCP2_Semaphore);

	if(pData == NULL || length == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_SetProtectedDecryptionKey input paramter is error!\n");
		return NOT_OK;
	}
	hdcp2_Rx_SetKs(pData);
	spu_SetLc128(pData+KS_SIZE);

	 hdcp2_GenKsXorLc128();
	 spu_GetKsXorLc128(KsxorLc128);
	 HDCP2DBGLOG("KsxorLc128: ", KsxorLc128, 16);

	 up(&HDCP2_Semaphore);
	return OK;
}

int rtk_hal_hdcp_Init(void)
{
	//hdcp2_load_from_flash();
	return OK;
}

int rtk_hal_hdcp2_Compute_V_Prime(unsigned char *pVPrime, unsigned char *pRxIdListsInfo,  int infoLength)
{
	unsigned char kd_temp[KD_SIZE] = {0x00};
	H2status rc;
	if(pVPrime == NULL || pRxIdListsInfo == NULL || infoLength == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_V_Prime input paramter is error!\n");
		return NOT_OK;
	}

	spu_GetKD(kd_temp);
	rc = hmacsha256(kd_temp, KD_SIZE, pRxIdListsInfo, infoLength, pVPrime);
	return rc; 
}

int rtk_hal_hdcp2_Compute_M_Prime(unsigned char *pMPrime, unsigned char *pStreamManageInfo, int infoLength)
{
	unsigned char kd_temp[KD_SIZE] = {0x00};
	unsigned char kd_sha256[KD_SIZE] = {0x00};
	H2status rc;
	if(pMPrime == NULL || pStreamManageInfo == NULL || infoLength == 0)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_Compute_M_Prime input paramter is error!\n");
		return NOT_OK;
	}
	spu_GetKD(kd_temp);
	Sha256(kd_temp, KD_SIZE, kd_sha256);
	rc = hmacsha256(kd_sha256, KD_SIZE, pStreamManageInfo, infoLength, pMPrime);
	return rc;
}

int rtk_hal_hdcp2_UseTestVector(unsigned int argc, HDCP2_UseTestVector_PARA_T *vector)
{
	if(argc == 0)
	{
		unsigned char temp_lc128[16] = {0};
		unsigned char temp_km[16] = {0};
		unsigned char temp_ks[16] = {0};
		spu_SetLc128(temp_lc128);
		spu_SetKM(temp_km);
		hdcp2_Rx_SetKs(temp_ks);
		return OK;
	}
	else if(argc == 3)
	{
		if(vector)
		{
			spu_SetLc128(vector->lc128);
			spu_SetKM(vector->km);
			hdcp2_Rx_SetKs(vector->ks);
		}
		return OK;
	}
	else
	{
		return NOT_OK;
	}
}

int rtk_hal_hdcp2_get_hdcp_status(unsigned char *b14Status, unsigned char *b22Status)
{
	hdmi_p0_port0_hdcp_flag1_RBUS hdcp_flag1_reg; 
	unsigned int nport = get_current_hdmi_port();
	unsigned char hdcp22_auth_flag;
	if(b14Status == NULL || b22Status == NULL)
	{
		pr_debug("hdcp2:rtk_hal_hdcp2_get_hdcp_status input paramter is error!\n");
		return NOT_OK;
	}
	hdcp_flag1_reg.regValue = IoReg_Read32(HDMI_P0_PORT0_HDCP_FLAG1_reg);
	*b14Status = hdcp_flag1_reg.adne_flag;
	hdcp22_auth_flag=(HDMI_HDCP_2p2_SR0_get_state(IoReg_Read32(HDMI_HDCP_2p2_SR0_reg))==0x010)?1:0;
	*b22Status = hdcp22_auth_flag;
	return OK;
}


#define HDCP2_TMP_BUFFER_SIZE       (128 * 1024)

int hdcp2_open(struct inode *inode, struct file *filp) {
#ifdef CONFIG_RTK_KDRV_MCP
	filp->private_data = mcp_malloc(HDCP2_TMP_BUFFER_SIZE);
#endif
    	if (filp->private_data==NULL)
        		return -ENOMEM;

	return 0;
}

ssize_t  hdcp2_read(struct file *filep, char *buffer, size_t count, loff_t *offp)
{
	return 0;

}

ssize_t hdcp2_write(struct file *filep, const char *buffer, size_t count, loff_t *offp)
{
	return 0;
}

int hdcp2_release(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_RTK_KDRV_MCP
	if (filp->private_data)
        	mcp_free(filp->private_data, HDCP2_TMP_BUFFER_SIZE);
#endif
	return 0;
}

#define HDCP2_KEY_LEN_MAX 1024
long hdcp2_ioctl(struct file *file, unsigned int cmd,  unsigned long arg)
{
    	unsigned char* hdcp_buff = (unsigned char*) file->private_data;
	int retval = 0;
	pr_debug("HDCP2: hdcp2_ioctl, %x;;agr:%x\n", cmd,*((unsigned int *)arg));

	if (_IOC_TYPE(cmd) != HDCP2_IOC_MAGIC || _IOC_NR(cmd) > HDCP2_IOC_MAXNR) return -ENOTTY ;

	switch (cmd)
	{
		case HDCP2_IOC_WRITE_KEYSET:
		{
			HDCP2_WRITE_KEYSET_PARA_T write_keyset;
			if(copy_from_user((void *)&write_keyset, (const void __user *)arg, sizeof(HDCP2_WRITE_KEYSET_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_WRITE_KEYSET copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_keyset[HDCP2_KEY_LEN_MAX];
				if(copy_from_user((void *)temp_keyset, (const void __user *)write_keyset.pKeySet, 878))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_keyset copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				rtk_hal_hdcp2_WriteKeySet(temp_keyset, write_keyset.dst_file_path, write_keyset.keyLength);
			}
			break;
		}
		case HDCP2_IOC_GET_ENCHDCP2KEY:
		{
			HDCP2_GET_ENCHDCP2KEY_PARA_T enchdcp2_key;
			if(copy_from_user((void *)&enchdcp2_key, (const void __user *)arg, sizeof(HDCP2_GET_ENCHDCP2KEY_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GET_ENCHDCP2KEY copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtk_hal_hdcp2_GetEncHdcp2Key(enchdcp2_key.pEncKey, enchdcp2_key.src_file_path, enchdcp2_key.keyLen);

			}
			break;
		}
		case HDCP2_IOC_SET_ENCHDCP2KEY:
		{
			unsigned char *enchdcp2_key;
			if(copy_from_user((void *)&enchdcp2_key, (const void __user *)arg, sizeof(unsigned char *)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SET_ENCHDCP2KEY copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SET_ENCHDCP2KEY copy_from_user failed!!!!!!!!!!!!!!!\n");
				rtk_hal_hdcp2_SetEncHdcp2Key(enchdcp2_key);

			}
			break;
		}
		case HDCP2_IOC_GET_ROOTPUBLICKEY:
		{
			HDCP2_GET_ROOTPUBLICKEY_PARA_T rootpublic_key;
			if(copy_from_user((void *)&rootpublic_key, (const void __user *)arg, sizeof(HDCP2_GET_ROOTPUBLICKEY_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GET_ROOTPUBLICKEY copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtk_hal_hdcp2_GetRootPublicKey(rootpublic_key.pRootPublicKey, rootpublic_key.src_file_path);
			}
			break;
		}
		case HDCP2_IOC_GET_CERTINFO:
		{
			HDCP2_GET_CERTINFO_PARA_T certinfo;
			if(copy_from_user((void *)&certinfo, (const void __user *)arg, sizeof(HDCP2_GET_CERTINFO_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GET_CERTINFO copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_receiveID[RECEIVER_ID_SIZE] = {0x00};
				unsigned char temp_pubkey[KEY_PUBLIC_RX_SIZE] = {0x00};
				unsigned char temp_rootsign[DCP_LLC_SIG_SIZE] = {0x00};
				rtk_hal_hdcp2_GetCertInfo(temp_receiveID, temp_pubkey, temp_rootsign);

				if(copy_to_user((void __user *)certinfo.pReceiverID, (void *) temp_receiveID, RECEIVER_ID_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_receiveID copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				if(copy_to_user((void __user *)certinfo.pPubKey, (void *) temp_pubkey, KEY_PUBLIC_RX_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_pubkey copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				if(copy_to_user((void __user *)certinfo.pRootSign, (void *) temp_rootsign, DCP_LLC_SIG_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_rootsign copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}

			}
			break;
		}
		case HDCP2_IOC_GET_CERTINFO2:
		{
			HDCP2_GET_CERTINFO_PARA_T certinfo2;
			if(copy_from_user((void *)&certinfo2, (const void __user *)arg, sizeof(HDCP2_GET_CERTINFO_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GET_CERTINFO2 copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_receiveID[RECEIVER_ID_SIZE] = {0x00};
				unsigned char temp_pubkey[KEY_PUBLIC_RX_SIZE] = {0x00};
				unsigned char temp_reserved[RESERVED_SIZE] = {0x00};
				unsigned char temp_rootsign[DCP_LLC_SIG_SIZE] = {0x00};
				rtk_hal_hdcp2_GetCertInfo2(temp_receiveID, temp_pubkey, temp_reserved, temp_rootsign);

				if(copy_to_user((void __user *)certinfo2.pReceiverID, (void *) temp_receiveID, RECEIVER_ID_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_receiveID copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				if(copy_to_user((void __user *)certinfo2.pPubKey, (void *) temp_pubkey, KEY_PUBLIC_RX_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_pubkey copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				if(copy_to_user((void __user *)certinfo2.pReserved, (void *) temp_reserved, RESERVED_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_reserved copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				if(copy_to_user((void __user *)certinfo2.pRootSign, (void *) temp_rootsign, DCP_LLC_SIG_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_rootsign copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}

			}
			break;
		}
		case HDCP2_IOC_DECRYPT_RSAES_OAEP:
		{
			unsigned char pEKpubKm[EKPUBKM_SIZE] = {0x00};
			if(copy_from_user((void *)pEKpubKm, (const void __user *)arg, EKPUBKM_SIZE))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DECRYPT_RSAES_OAEP copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				if(rtk_hal_hdcp2_Decrypt_RSAES_OAEP(pEKpubKm) == H2_ERROR)
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DECRYPT_RSAES_OAEP pEkpubkm error!!!\n");
				}
			}
			break;
		}
		case HDCP2_IOC_KD_KEY_DERIVATION:
		{
			HDCP2_KD_KEY_DERIVATION_PARA_T kd_key_derivation;
			if(copy_from_user((void *)&kd_key_derivation, (const void __user *)arg, sizeof(HDCP2_KD_KEY_DERIVATION_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_KD_KEY_DERIVATION copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_rtx[RTX_SIZE] = {0x00};
				unsigned char temp_rrx[RRX_SIZE] = {0x00};
				if(copy_from_user((void *)temp_rtx, (const void __user *)kd_key_derivation.pRtx, RTX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rtx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rrx, (const void __user *)kd_key_derivation.pRrx, RRX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rrx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				rtk_hal_hdcp2_Kd_Key_Derivation(temp_rtx, temp_rrx, kd_key_derivation.version);
			}
			break;
		}
		case HDCP2_IOC_COMPUTE_H_PRIME:
		{
			HDCP2_COMPUTE_H_PRIME_PARA_T compute_h_prime;
			if(copy_from_user((void *)&compute_h_prime, (const void __user *)arg, sizeof(HDCP2_COMPUTE_H_PRIME_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_COMPUTE_H_PRIME copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_hprime[H_SIZE] = {0x00};
				unsigned char temp_rtx[RTX_SIZE] = {0x00};
				unsigned char temp_deviceOptionInfo[RXCAPS_SIZE + TXCAPS_SIZE] = {0x00};

				if(copy_from_user((void *)temp_rtx, (const void __user *)compute_h_prime.pRtx, RTX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rtx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_deviceOptionInfo, (const void __user *)compute_h_prime.deviceOptionInfo, RXCAPS_SIZE + TXCAPS_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_deviceOptionInfo copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Compute_H_Prime(temp_hprime, compute_h_prime.repeater, temp_rtx, temp_deviceOptionInfo, compute_h_prime.version);

				if(copy_to_user((void __user *)compute_h_prime.pHPrime, (void *) temp_hprime, H_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_hprime copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_COMPUTE_L_PRIME:
		{
			HDCP2_COMPUTE_L_PRIME_PARA_T compute_l_prime;
			if(copy_from_user((void *)&compute_l_prime, (const void __user *)arg, sizeof(HDCP2_COMPUTE_L_PRIME_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_COMPUTE_L_PRIME copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_lprime[L_SIZE] = {0x00};
				unsigned char temp_rn[RN_SIZE] = {0x00};
				unsigned char temp_rrx[RRX_SIZE] = {0x00};

				if(copy_from_user((void *)temp_rn, (const void __user *)compute_l_prime.pRn, RN_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rn copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rrx, (const void __user *)compute_l_prime.pRrx, RRX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rrx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Compute_L_Prime(temp_lprime, temp_rn, temp_rrx,  compute_l_prime.version);

				if(copy_to_user((void __user *)compute_l_prime.pLPrime, (void *) temp_lprime, L_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_lprime copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_COMPUTE_KH:
		{
			rtk_hal_hdcp2_Compute_Kh();
			break;
		}
		case HDCP2_IOC_ENCRYPT_KM_USING_KH:
		{
			HDCP2_ENCRYPT_KM_USING_KH_PARA_T encrypt_km;
			if(copy_from_user((void *)&encrypt_km, (const void __user *)arg, sizeof(HDCP2_ENCRYPT_KM_USING_KH_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_ENCRYPT_KM_USING_KH copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_ekhkm[EKHKM_SIZE] = {0x00};
				unsigned char temp_m[M_SIZE] = {0x00};

				if(copy_from_user((void *)temp_m, (const void __user *)encrypt_km.pM, M_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_m copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Encrypt_Km_using_Kh(temp_ekhkm, temp_m);

				if(copy_to_user((void __user *)encrypt_km.pEKH_KM, (void *) temp_ekhkm, EKHKM_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_ekhkm copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_DECRYPT_KM_USING_KH:
		{
			HDCP2_ENCRYPT_KM_USING_KH_PARA_T decrypt_km;
			if(copy_from_user((void *)&decrypt_km, (const void __user *)arg, sizeof(HDCP2_ENCRYPT_KM_USING_KH_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DECRYPT_KM_USING_KH copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_ekhkm[EKHKM_SIZE] = {0x00};
				unsigned char temp_m[M_SIZE] = {0x00};

				if(copy_from_user((void *)temp_ekhkm, (const void __user *)decrypt_km.pEKH_KM, EKHKM_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_ekhkm copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_m, (const void __user *)decrypt_km.pM, M_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_m copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Decrypt_Km_using_Kh(temp_m, temp_ekhkm);
			}
			break;
		}
		case HDCP2_IOC_DECRYPT_EKS:
		{
			HDCP2_DECRYPT_EKS_PARA_T decrypt_eks;
			if(copy_from_user((void *)&decrypt_eks, (const void __user *)arg, sizeof(HDCP2_DECRYPT_EKS_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DECRYPT_EKS copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_eks[EDKEYKS_SIZE] = {0x00};
				unsigned char temp_rtx[RTX_SIZE] = {0x00};
				unsigned char temp_rrx[RRX_SIZE] = {0x00};
				unsigned char temp_rn[RN_SIZE] = {0x00};

				if(copy_from_user((void *)temp_eks, (const void __user *)decrypt_eks.pEks, EDKEYKS_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_eks copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rtx, (const void __user *)decrypt_eks.pRtx, RTX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rtx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rrx, (const void __user *)decrypt_eks.pRrx, RRX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rrx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rn, (const void __user *)decrypt_eks.pRn, RN_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rn copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Decrypt_EKs(temp_eks, temp_rtx, temp_rrx, temp_rn, decrypt_eks.version);
			}
			break;
		}
		case HDCP2_IOC_XOR_KS_WITH_LC128:
		{
			rtk_hal_hdcp2_XOR_Ks_with_LC128();
			break;
		}
		case HDCP2_IOC_GENERATE_KM:
		{
			HDCP2_GENERATE_KM_PARA_T Gen_km;
			if(copy_from_user((void *)&Gen_km, (const void __user *)arg, sizeof(HDCP2_GENERATE_KM_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GENERATE_KM copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_maskedDB[DB_SIZE+4] = {0x00};
				unsigned char temp_db[DB_SIZE] = {0x00};
				unsigned char temp_dbmask[DB_SIZE] = {0x00};

				if(copy_from_user((void *)temp_db, (const void __user *)Gen_km.pDB, DB_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_db copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_dbmask, (const void __user *)Gen_km.pDBMask, DB_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_dbmask copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Generate_Km(temp_maskedDB, temp_db, temp_dbmask);

				if(copy_to_user((void __user *)Gen_km.pMaskedDB, (void *) temp_maskedDB, DB_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_maskedDB copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_GENERATE_KS:
		{
			HDCP2_GENERATE_KS_PARA_T Gen_ks;
			if(copy_from_user((void *)&Gen_ks, (const void __user *)arg, sizeof(HDCP2_GENERATE_KS_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GENERATE_KS copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_eks[EDKEYKS_SIZE] = {0x00};
				unsigned char temp_rtx[RTX_SIZE] = {0x00};
				unsigned char temp_rrx[RRX_SIZE] = {0x00};
				unsigned char temp_rn[RN_SIZE] = {0x00};

				if(copy_from_user((void *)temp_rtx, (const void __user *)Gen_ks.pRtx, RTX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rtx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rrx, (const void __user *)Gen_ks.pRrx, RRX_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rrx copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)temp_rn, (const void __user *)Gen_ks.pRn, RN_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_rn copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				rtk_hal_hdcp2_Generate_Ks(temp_eks, temp_rrx, temp_rtx, temp_rn, Gen_ks.version);

				if(copy_to_user((void __user *)Gen_ks.pEks, (void *) temp_eks, EDKEYKS_SIZE))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_eks copy_to_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_DATA_DECRYPT:
		{
			HDCP2_DATA_DECRYPT_PARA_T data;
			if(copy_from_user((void *)&data, (const void __user *)arg, sizeof(HDCP2_DATA_DECRYPT_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DATA_DECRYPT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_counter[16] = {0x00};
				if(copy_from_user((void *)temp_counter, (const void __user *)data.pCounter, 16))
		        	{
		            			retval = -EFAULT;
		            			DBG_PRINT("scaler hdcp2 ioctl code=temp_counter copy_from_user failed!!!!!!!!!!!!!!!\n");
		            			break;
		        	}

				if (hdcp_buff==NULL || data.length < 512)
                			{
						unsigned char hdcp_outputbuf[512] = {0x00};
						unsigned char hdcp_inputbuf[512] = {0x00};
						if(copy_from_user((void *)hdcp_inputbuf, (const void __user *)data.pInputBuf, data.length))
		        			{
		            				retval = -EFAULT;
		            				DBG_PRINT("scaler hdcp2 ioctl code=hdcp_inputbuf copy_from_user failed!!!!!!!!!!!!!!!\n");
		            				break;
		        			}

                    				rtk_hal_hdcp2_Data_Decrypt(hdcp_outputbuf, hdcp_inputbuf, data.length, temp_counter);

						if(copy_to_user((void __user *)data.pOutputBuf, (void *) hdcp_outputbuf, data.length))
    			        		{
    			           			retval = -EFAULT;
				            		DBG_PRINT("scaler hdcp2 ioctl code=hdcp_outputbuf copy_from_user failed!!!!!!!!!!!!!!!\n");
				            		break;
    			        		}
                			}
                			else
                			{
    			    		while(data.length)
    			    		{
    			        			unsigned char KsxorLc128[16] = {0x00};
    			        			unsigned int len = (data.length >= HDCP2_TMP_BUFFER_SIZE) ?  HDCP2_TMP_BUFFER_SIZE : data.length;
                        					spu_GetKsXorLc128(KsxorLc128);

                        					if(copy_from_user((void *)hdcp_buff, (const void __user *)data.pInputBuf, len))
    			        			{
    			            				retval = -EFAULT;
				            			DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DATA_DECRYPT copy_from_user failed!!!!!!!!!!!!!!!\n");
				            			break;
    			        			}
#ifdef CONFIG_RTK_KDRV_MCP
    			        			MCP_AES_CTR_Decryption(KsxorLc128, temp_counter, hdcp_buff, hdcp_buff, (len + 15) & (~0xF));

                        				MCP_AES_PeekIV(temp_counter);  // peek iv
#endif

    			        			if(copy_to_user((void __user *)data.pOutputBuf, (void *) hdcp_buff, len))
    			        			{
    			           				retval = -EFAULT;
				            			DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DATA_DECRYPT copy_from_user failed!!!!!!!!!!!!!!!\n");
				            			break;
    			        			}

    			        			data.pInputBuf += len;
    			        			data.pOutputBuf += len;
    			        			data.length -= len;
    			    		}
    				}
			}
			break;
		}
		case HDCP2_IOC_SHA1:
		{
			HDCP2_SHA_PARA_T sha1;
			if(copy_from_user((void *)&sha1, (const void __user *)arg, sizeof(HDCP2_SHA_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SHA1 copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char *in_ptr = kmalloc(sha1.length, GFP_KERNEL);
				unsigned char *out_ptr = kmalloc(20, GFP_KERNEL);
				if((in_ptr == NULL) ||(out_ptr == NULL))
				{
					if(in_ptr != NULL) {
						kfree(in_ptr);
						in_ptr = NULL;
					}
					if(out_ptr != NULL) {
						kfree(out_ptr);
						out_ptr = NULL;
					}
					DBG_PRINT("in_ptr/out_ptr kmalloc failed!!!!!!!!!!!!!!!\n");
					retval = -EFAULT;
					break;
				}

				if(copy_from_user((void *)in_ptr, (const void __user *)sha1.pInputBuf, sha1.length))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_SHA1(out_ptr, in_ptr, sha1.length);

				if(copy_to_user((void __user *)sha1.pOutputBuf, (void *)out_ptr, 20))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=out_ptr copy_to_user failed!!!!!!!!!!!!!!!\n");
            				//break;
        			}

				kfree(in_ptr);
				kfree(out_ptr);
				in_ptr = NULL;
				out_ptr = NULL;
			}
			break;
		}
		case HDCP2_IOC_SHA256:
		{
			HDCP2_SHA_PARA_T sha256;
			if(copy_from_user((void *)&sha256, (const void __user *)arg, sizeof(HDCP2_SHA_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SHA256 copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char *in_ptr = kmalloc(sha256.length, GFP_KERNEL);
				unsigned char *out_ptr = kmalloc(32, GFP_KERNEL);
				if((in_ptr == NULL) ||(out_ptr == NULL))
				{
					if(in_ptr != NULL) {
						kfree(in_ptr);
						in_ptr = NULL;
					}
					if(out_ptr != NULL) {
						kfree(out_ptr);
						out_ptr = NULL;
					}
					DBG_PRINT("in_ptr/out_ptr kmalloc failed!!!!!!!!!!!!!!!\n");
					retval = -EFAULT;
					break;
				}

				if(copy_from_user((void *)in_ptr, (const void __user *) sha256.pInputBuf, sha256.length))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_SHA256(out_ptr, in_ptr, sha256.length);

				if(copy_to_user((void __user *)sha256.pOutputBuf, (void *)out_ptr, 32))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=out_ptr copy_to_user failed!!!!!!!!!!!!!!!\n");
            				//break;
        			}

				kfree(in_ptr);
				kfree(out_ptr);
				in_ptr = NULL;
				out_ptr = NULL;
			}
			break;
		}
		case HDCP2_IOC_HMAC_SHA256:
		{
			HDCP2_HMAC_SHA256_PARA_T hmac_sha256;
			if(copy_from_user((void *)&hmac_sha256, (const void __user *)arg, sizeof(HDCP2_HMAC_SHA256_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_HMAC_SHA256 copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char *in_ptr = kmalloc(hmac_sha256.length, GFP_KERNEL);
				unsigned char *out_ptr = kmalloc(32, GFP_KERNEL);
				unsigned char *key_ptr = kmalloc(hmac_sha256.keylength, GFP_KERNEL);
				if((in_ptr == NULL) ||(out_ptr == NULL) || (key_ptr == NULL))
				{
					if(in_ptr != NULL) {
						kfree(in_ptr);
						in_ptr = NULL;
					}
					if(out_ptr != NULL) {
						kfree(out_ptr);
						out_ptr = NULL;
					}
					if(key_ptr != NULL) {
						kfree(key_ptr);
						key_ptr = NULL;
					}
					DBG_PRINT("in_ptr/out_ptr/key_ptr kmalloc failed!!!!!!!!!!!!!!!\n");
					retval = -EFAULT;
					break;
				}

				if(copy_from_user((void *)in_ptr, (const void __user *) hmac_sha256.pInputBuf, hmac_sha256.length))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)key_ptr, (const void __user *) hmac_sha256.pKey, hmac_sha256.keylength))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_HMAC_SHA256(out_ptr, in_ptr, hmac_sha256.length, key_ptr, hmac_sha256.keylength);

				if(copy_to_user((void __user *)hmac_sha256.pOutputBuf, (void *)out_ptr, 32))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=out_ptr copy_to_user failed!!!!!!!!!!!!!!!\n");
            				//break;
        			}

				kfree(in_ptr);
				kfree(out_ptr);
				kfree(key_ptr);
				in_ptr = NULL;
				out_ptr = NULL;
				key_ptr = NULL;
			}
			break;
		}
		case HDCP2_IOC_AES_CTR:
		{
			HDCP2_AES_CTR_PARA_T aes_ctr;
			if(copy_from_user((void *)&aes_ctr, (const void __user *)arg, sizeof(HDCP2_AES_CTR_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_AES_CTR_PARA_T copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char *in_ptr = kmalloc(aes_ctr.length, GFP_KERNEL);
				unsigned char *out_ptr = kmalloc(aes_ctr.length, GFP_KERNEL);
				unsigned char *key_ptr = kmalloc(aes_ctr.keyLength, GFP_KERNEL);
				unsigned char counter[16];
				if((in_ptr == NULL) ||(out_ptr == NULL) || (key_ptr == NULL))
				{
					if(in_ptr != NULL) {
						kfree(in_ptr);
						in_ptr = NULL;
					}
					if(out_ptr != NULL) {
						kfree(out_ptr);
						out_ptr = NULL;
					}
					if(key_ptr != NULL) {
						kfree(key_ptr);
						key_ptr = NULL;
					}
					DBG_PRINT("in_ptr/out_ptr/key_ptr kmalloc failed!!!!!!!!!!!!!!!\n");
					retval = -EFAULT;
					break;
				}

				if(copy_from_user((void *)in_ptr, (const void __user *) aes_ctr.pInputBuf, aes_ctr.length))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)key_ptr, (const void __user *)aes_ctr.pkey, aes_ctr.keyLength))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)counter, (const void __user *)aes_ctr.pCounter, 16))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_AES_CTR(out_ptr, in_ptr, aes_ctr.length, key_ptr, aes_ctr.keyLength, counter);

				if(copy_to_user((void __user *)aes_ctr.pOutputBuf, (void *)out_ptr, aes_ctr.length))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=out_ptr copy_to_user failed!!!!!!!!!!!!!!!\n");
            				//break;
        			}

				kfree(in_ptr);
				kfree(out_ptr);
				kfree(key_ptr);
				in_ptr = NULL;
				out_ptr = NULL;
				key_ptr = NULL;
			}
			break;
		}
		case HDCP2_IOC_SELECT_STOREDKM:
		{
			int index;
			if(copy_from_user((void *)&index, (const void __user *)arg, sizeof(int)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SELECT_STOREDKM copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtk_hal_hdcp2_Select_StoredKm(index);
			}
			break;
		}
		case HDCP2_IOC_WRITE_STOREDKM:
		{
			int index;
			if(copy_from_user((void *)&index, (const void __user *)arg, sizeof(int)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_WRITE_STOREDKM copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtk_hal_hdcp2_Write_StoredKm(index);
			}
			break;
		}
		case HDCP2_IOC_DATA_ENCRYPT:
		{
			HDCP2_DATA_DECRYPT_PARA_T data;
			if(copy_from_user((void *)&data, (const void __user *)arg, sizeof(HDCP2_DATA_DECRYPT_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_DATA_ENCRYPT copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				rtk_hal_hdcp2_Data_Encrypt(data.pOutputBuf, data.pInputBuf, data.length, data.pCounter);
			}
			break;
		}
		case HDCP2_IOC_GET_PROTECTED_DECRYPTIONKEY:
		{
			HDCP2_GET_PROTECTED_DECRYPTIONKEY_PARA_T get_prokey;
			if(copy_from_user((void *)&get_prokey, (const void __user *)arg, sizeof(HDCP2_GET_PROTECTED_DECRYPTIONKEY_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_GET_PROTECTED_DECRYPTIONKEY copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_data[32];
				rtk_hal_hdcp2_GetProtectedDecryptionKey(temp_data, get_prokey.pLength);
				if(copy_to_user((void __user *)get_prokey.pData, (void *) temp_data, 32))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_data copy_from_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_SET_PROTECTED_DECRYPTIONKEY:
		{
			HDCP2_SET_PROTECTED_DECRYPTIONKEY_PARA_T set_prokey;
			if(copy_from_user((void *)&set_prokey, (const void __user *)arg, sizeof(HDCP2_SET_PROTECTED_DECRYPTIONKEY_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SET_PROTECTED_DECRYPTIONKEY copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_data[32];
				if(copy_from_user((void *)temp_data, (const void __user *)set_prokey.pData, set_prokey.length))
        			{
            				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_data copy_from_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				rtk_hal_hdcp2_SetProtectedDecryptionKey(temp_data, set_prokey.length);
			}
			break;
		}
		case HDCP2_IOC_HDCP_INIT:
		{
			rtk_hal_hdcp_Init();
			break;
		}
		case HDCP2_IOC_GET_OTPHDCP2KEY:
		{
			HDCP2_GET_OTPHDCP2KEY_PARA_T HDCP2_OTP_KEY;
			if(copy_from_user((void *)&HDCP2_OTP_KEY, (const void __user *)arg, sizeof(HDCP2_GET_OTPHDCP2KEY_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_SET_PROTECTED_DECRYPTIONKEY copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_data[1024] = {0};
				int temp_exsit = 0;
#ifdef CONFIG_RTK_KDRV_HDCP_KEY_FROM_OTP
				if(get_hdcp_22_otp(temp_data, HDCP2_OTP_KEY.length) == 0)
					temp_exsit = 1;
				else
					temp_exsit = 0;
#endif
				if(copy_to_user((void __user *)HDCP2_OTP_KEY.pData, (void *) temp_data, HDCP2_OTP_KEY.length))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_data copy_from_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
				if(copy_to_user((void __user *)HDCP2_OTP_KEY.exsit, (void *) &temp_exsit, sizeof(int)))
        			{
           				retval = -EFAULT;
            				DBG_PRINT("scaler hdcp2 ioctl code=temp_data copy_from_user failed!!!!!!!!!!!!!!!\n");
            				break;
        			}
			}
			break;
		}
		case HDCP2_IOC_COMPUTE_V_PRIME:
		{
			HDCP2_COMPUTE_V_PRIME_PARA_T compute_v_prime;
			if(copy_from_user((void *)&compute_v_prime, (const void __user *)arg, sizeof(HDCP2_COMPUTE_V_PRIME_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_COMPUTE_V_PRIME_PARA_T copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_vprime[VPRIME_SIZE] = {0x00};
				unsigned char temp_listinfo[LIST_SIZE] = {0x00};

				if(copy_from_user((void *)temp_listinfo, (const void __user *)compute_v_prime.pRxIdListsInfo, compute_v_prime.infoLength))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_listinfo copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Compute_V_Prime(temp_vprime, temp_listinfo, compute_v_prime.infoLength);

				if(copy_to_user((void __user *)compute_v_prime.pVPrime, (void *) temp_vprime, VPRIME_SIZE))
    			{
       				retval = -EFAULT;
        			DBG_PRINT("scaler hdcp2 ioctl code=temp_vprime copy_from_user failed!!!!!!!!!!!!!!!\n");
        			break;
    			}

			}
			break;
		}
		case HDCP2_IOC_COMPUTE_M_PRIME:
		{
			HDCP2_COMPUTE_M_PRIME_PARA_T compute_m_prime;
			if(copy_from_user((void *)&compute_m_prime, (const void __user *)arg, sizeof(HDCP2_COMPUTE_M_PRIME_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_COMPUTE_M_PRIME_PARA_T copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char temp_mprime[MPRIME_SIZE] = {0x00};
				unsigned char temp_streaminfo[STREAM_SIZE] = {0x00};

				if(copy_from_user((void *)temp_streaminfo, (const void __user *)compute_m_prime.pStreamManageInfo, compute_m_prime.infoLength))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=temp_streaminfo copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				rtk_hal_hdcp2_Compute_M_Prime(temp_mprime, temp_streaminfo, compute_m_prime.infoLength);

				if(copy_to_user((void __user *)compute_m_prime.pMPrime, (void *) temp_mprime, MPRIME_SIZE))
    			{
       				retval = -EFAULT;
        			DBG_PRINT("scaler hdcp2 ioctl code=temp_mprime copy_from_user failed!!!!!!!!!!!!!!!\n");
        			break;
    			}

			}
			break;
		}
		case HDCP2_IOC_GET_HDCP_STATUS:
		{
			HDCP2_GET_HDCP_STATUS_PARA_T GET_HDCP_STATUS;
			if(copy_from_user((void *)&GET_HDCP_STATUS, (const void __user *)arg, sizeof(HDCP2_GET_HDCP_STATUS_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_GET_HDCP_STATUS_PARA_T copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else
			{
				unsigned char b14status = 0;
				unsigned char b22status = 0;
				rtk_hal_hdcp2_get_hdcp_status(&b14status, &b22status);

				if(copy_to_user((void __user *)GET_HDCP_STATUS.b14Status, (void *) &b14status, sizeof(unsigned char)))
				{
	   				retval = -EFAULT;
	    			DBG_PRINT("scaler hdcp2 ioctl code=b14status copy_from_user failed!!!!!!!!!!!!!!!\n");
	    			break;
				}

				if(copy_to_user((void __user *)GET_HDCP_STATUS.b22Status, (void *) &b22status, sizeof(unsigned char)))
				{
	   				retval = -EFAULT;
	    			DBG_PRINT("scaler hdcp2 ioctl code=b22status copy_from_user failed!!!!!!!!!!!!!!!\n");
	    			break;
				}
			}
			break;
		}
		case HDCP2_IOC_UseTestVector:
		{
			HDCP2_UseTestVector_PARA_T usetestvector;
			HDCP2_UseTestVector_PARA_T test_vector;
			if(copy_from_user((void *)&usetestvector, (const void __user *)arg, sizeof(HDCP2_UseTestVector_PARA_T)))
			{
				retval = -EFAULT;
				DBG_PRINT("scaler hdcp2 ioctl code=HDCP2_IOC_UseTestVector copy_from_user failed!!!!!!!!!!!!!!!\n");
			}
			else if(usetestvector.argc == 0)
			{
				rtk_hal_hdcp2_UseTestVector(0, NULL);
			}
			else
			{
				unsigned char *lc128 = kmalloc(LC128_SIZE, GFP_KERNEL);
				unsigned char *km = kmalloc(KM_SIZE, GFP_KERNEL);
				unsigned char *ks = kmalloc(KS_SIZE, GFP_KERNEL);
				if((lc128 == NULL) ||(km == NULL) || (ks == NULL))
				{
					if(lc128 != NULL) {
						kfree(lc128);
						lc128 = NULL;
					}
					if(km != NULL) {
						kfree(km);
						km = NULL;
					}
					if(ks != NULL) {
						kfree(ks);
						ks = NULL;
					}
					DBG_PRINT("lc128/km/ks kmalloc failed!!!!!!!!!!!!!!!\n");
					retval = -EFAULT;
					break;
				}

				if(copy_from_user((void *)lc128, (const void __user *) usetestvector.lc128, LC128_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)km, (const void __user *)usetestvector.km, KM_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}
				if(copy_from_user((void *)ks, (const void __user *)usetestvector.ks, KS_SIZE))
				{
					retval = -EFAULT;
					DBG_PRINT("scaler hdcp2 ioctl code=in_ptr copy_from_user failed!!!!!!!!!!!!!!!\n");
				}

				test_vector.argc = usetestvector.argc;
				test_vector.lc128 = lc128;
				test_vector.km = km;
				test_vector.ks = ks;
				rtk_hal_hdcp2_UseTestVector(usetestvector.argc, &test_vector);


				kfree(lc128);
				kfree(km);
				kfree(ks);
				lc128 = NULL;
				km = NULL;
				ks = NULL;
			}
			break;
		}

		default:
			pr_debug("Scaler hdcp2 disp: ioctl code = %d is invalid!!!!!!!!!!!!!!!1\n", cmd);
			break ;
		}
	return retval;


}

#ifdef CONFIG_PM

HDCP2_PM_PARAMTER HDCP2_PM_PARAMTER_DATA;
static int hdcp2_suspend (struct device *p_dev)
{
	int result = 0;
	result = hdcp2_copy_paramter(&HDCP2_PM_PARAMTER_DATA);
	return result;
}

static int hdcp2_resume (struct device *p_dev)
{
	int result = 0;
	result = hdcp2_recover_paramter(&HDCP2_PM_PARAMTER_DATA);
	return result;
}

#endif


#ifdef CONFIG_PM

static const struct dev_pm_ops hdcp2_pm_ops =
{
	.suspend    = hdcp2_suspend,
	.resume     = hdcp2_resume,
#ifdef CONFIG_HIBERNATION
	.freeze     = hdcp2_suspend,
	.thaw       = hdcp2_resume,
	.poweroff   = hdcp2_suspend,
	.restore    = hdcp2_resume,
#endif
};
#endif // CONFIG_PM

struct file_operations hdcp2_fops= {
	.owner =    THIS_MODULE,
	.open  =    hdcp2_open,
	.release =  hdcp2_release,
	.read  =    hdcp2_read,
	.write = 	hdcp2_write,
	.unlocked_ioctl =    hdcp2_ioctl,
};

int hdcp2_major   = HDCP2_MAJOR;
int hdcp2_minor   = 0 ;
int hdcp2_nr_devs = HDCP2_NR_DEVS;

module_param(hdcp2_major, int, S_IRUGO);
module_param(hdcp2_minor, int, S_IRUGO);
module_param(hdcp2_nr_devs, int, S_IRUGO);


static struct class *hdcp2_class = NULL;
static struct platform_device *hdcp2_platform_devs = NULL;
static struct platform_driver hdcp2_device_driver = {
    .driver = {
        .name       = HDCP2_DEVICE_NAME,
        .bus        = &platform_bus_type,
#ifdef CONFIG_PM
	.pm           = &hdcp2_pm_ops,
#endif
    },
} ;

static struct miscdevice HDCP2_miscdev =
{
	MISC_DYNAMIC_MINOR,
	"HDCP2",
	&hdcp2_fops
};

static char *hdcp2_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

int hdmi_port = 0;

void set_current_hdmi_port(int port)
{
	if(port < 0 || port > 3)
	{
		pr_err("port is error[%d]\n",port);
		return;
	}
	hdmi_port = port;
}

int get_current_hdmi_port(void)
{
	return hdmi_port;
}

irqreturn_t HDCP_irq_handler(int irq, void *dev_id)
{
	unsigned char nport;
	unsigned long regValue[HDMI_MAX_PORT_NUM] = {0x00};
	unsigned char handler_flag = 0;

	for(nport=0; nport<HDMI_MAX_PORT_NUM; nport++)
	{
		regValue[nport] = rtd_inl(HDMI_HDCP_2p2_SR0_reg);
#if (HDCP2_SEND_PAIRINGINFO_BY_IRQ_RD)
		if (regValue[nport] & (HDMI_HDCP_2p2_SR0_irq_wr_msg_done_mask|HDMI_HDCP_2p2_SR0_irq_rd_msg_done_mask))
#else
		if(regValue[nport] & HDMI_HDCP_2p2_SR0_irq_wr_msg_done_mask)
#endif
		{
			rtd_maskl(HDMI_HDMI_INTCR_reg,~(HDMI_HDMI_INTCR_pending_mask),(HDMI_HDMI_INTCR_pending_mask));
			set_current_hdmi_port(nport);
			newbase_msg_hander(nport);
			handler_flag ++;
		}
	}

	if(handler_flag > 0)
		return IRQ_HANDLED;
	else
		return IRQ_NONE;

}

int hdcp2_init_module(void)
{
	int result;
  	int devno;
	dev_t dev = 0;
	rtd_outl(SYS_REG_INT_CTRL_MEMC_reg, (SYS_REG_INT_CTRL_MEMC_hdmi_irq_scpu_routing_en_mask|SYS_REG_INT_CTRL_MEMC_write_data_mask));
	
	pr_debug("\n\n\n\n *****************  hdcp2 init module  *********************\n\n\n\n");

	if (request_irq(IRQ_HDMI, HDCP_irq_handler, IRQF_SHARED, "HDCP2", HDCP_irq_handler))
	{
		pr_debug(" \n [linux]HDCP2: cannot register IRQ %d \n", IRQ_HDMI);
      	 	return -EIO;	/* FAil ! */
	}
	pr_debug("[linux]HDCP2: register sucess!!! IRQ %d\n", IRQ_HDMI);

	 if (misc_register(&HDCP2_miscdev))
      		 return -1;

	//return 0;	/* succeed ! */

	if (hdcp2_major) {
		dev = MKDEV(hdcp2_major, hdcp2_minor);
		result = register_chrdev_region(dev, hdcp2_nr_devs, HDCP2_DEVICE_NAME);
	} else {
		result = alloc_chrdev_region(&dev, hdcp2_minor, hdcp2_nr_devs,HDCP2_DEVICE_NAME);
		hdcp2_major = MAJOR(dev);
	}
	if (result < 0) {
		DBG_PRINT(KERN_WARNING "hdcp2: can't get major %d\n", hdcp2_major);
		return result;
	}

	pr_debug("hdcp2 init module major number = %d\n", hdcp2_major);

	hdcp2_class = class_create(THIS_MODULE,HDCP2_DEVICE_NAME);

	if (IS_ERR(hdcp2_class))
	{
		pr_debug("scalehdcp2: can not create class...\n");
		result = PTR_ERR(hdcp2_class);
		goto fail_class_create;
	}

	hdcp2_class->devnode = hdcp2_devnode;

	hdcp2_platform_devs = platform_device_register_simple(HDCP2_DEVICE_NAME, -1, NULL, 0);

    	if((result=platform_driver_register(&hdcp2_device_driver)) != 0){
		pr_debug("scalehdcp2: can not register platform driver...\n");
		result = -ENOMEM;
		goto fail_platform_driver_register;
    	}

    	devno = MKDEV(hdcp2_major, hdcp2_minor);
    	cdev_init(&hdcp2_cdev, &hdcp2_fops);
    	hdcp2_cdev.owner = THIS_MODULE;
   	hdcp2_cdev.ops = &hdcp2_fops;
	result = cdev_add (&hdcp2_cdev, devno, 1);
	if (result<0)
	{
		pr_debug("scalehdcp2: can not add character device...\n");
		goto fail_cdev_init;
	}
    	device_create(hdcp2_class, NULL, MKDEV(hdcp2_major, 0), NULL, HDCP2_DEVICE_NAME);

    	sema_init(&HDCP2_Semaphore, 1);
    	return 0;	//success

fail_cdev_init:
	platform_driver_unregister(&hdcp2_device_driver);
fail_platform_driver_register:
	platform_device_unregister(hdcp2_platform_devs);
	hdcp2_platform_devs = NULL;
	class_destroy(hdcp2_class);
fail_class_create:
	hdcp2_class = NULL;
	unregister_chrdev_region(hdcp2_devno, 1);
	return result;
}



void __exit hdcp2_cleanup_module(void)
{
	dev_t devno = MKDEV(hdcp2_major, hdcp2_minor);
	DBG_PRINT("rtice clean module hdcp2_major = %d\n", hdcp2_major);
  	device_destroy(hdcp2_class, MKDEV(hdcp2_major, 0));
  	class_destroy(hdcp2_class);
	hdcp2_class = NULL;
	cdev_del(&hdcp2_cdev);
   	/* device driver removal */
	if(hdcp2_platform_devs) {
		platform_device_unregister(hdcp2_platform_devs);
		hdcp2_platform_devs = NULL;
	}
  	platform_driver_unregister(&hdcp2_device_driver);
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, hdcp2_nr_devs);
}

module_init(hdcp2_init_module) ;
module_exit(hdcp2_cleanup_module) ;
