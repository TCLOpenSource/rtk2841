/**
 * HDCPTX22.cpp
 *
 *
 *  Created on: 2014/8/11
 *  Revisioned on: 2014/9/19
 *  			   2014/9/23
 *                 2014/12/04
 *
 *      Author: Bruce Huang @ Realtek semiconductor crop.
 *
 *  Descriptions:
 *  	- A simple class to control HDCP 2.2 TX nego protocol (map HDCP to HDMI) .
 *  	- One may change SHA, RAS, AES service routine with hardware support.
 *  	- Repeater command set is supported in this engine.
 *  	- Pass all test items in HDCP CTS (for both receiver and repeater).
 *
 *  Items to be done:
 *  	- SRM check (revocation list)?
 *  	- decrypt real hdcp tx key, remove production key in source code
 *
 *  USER SPACE API:
 *  	- Provide API to enable/disable HDCP 22 by application.
 *
 *  HDMI scope:
 *  	- when Rx plug-in, Tx should read HDCP2Vsn (with retry for 2 seconds),
 *  	  however, after HDCP capability is got, a Tx does not need to start HDCP nego immediately.
 */
#define LOG_TAG "RTKHDCPTX22Core"

#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/HDCPTX22.h>
#include <tvscalercontrol/hdcp2_2/HDCPTX22_TestKey.h>

#include <tvscalercontrol/hdcp2_2/crypto.h>
#include <tvscalercontrol/hdcp2_2/bigdigits.h>
#include <tvscalercontrol/hdcp2_2/hmac.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_rcp_api.h>

/**
 * NOTICE:
 * If one wants to test with test vector,
 * one can enable "USE_TEST_VECTOR" and disable "GENERATE_REAL_RANDOM_VALUE"
 * variable "testkey_id" is to let user define load R1 or R2 vector.
 */

#define USE_TEST_VECTOR             0
#define DISABLE_STORED_KM_MSG       0
#define	GENERATE_REAL_RANDOM_VALUE  0

/**
 * If user wants to peek HDCP traffic, enable these flags
 */
#define	DUMP_OUT_DATA               0
#define	DUMP_IN_DATA                0
#define	DUMP_META_BUFFER            0

#define NUMS_PER_LINE 20
#define	LOG pr_debug
#define	IS_SUCCESS(x) (x==HDCP_ERR_SUCCESS)

#define MAX_REAUTH_RETRY_COUNT 5

#define IS_NEED_REAUTH(x)	 ( x == HDCP_ERR_READ_RECEIVERID_LIST_ERROR_NEED_REAUTH ||	\
			x == HDCP_ERR_RECEIVERID_LIST_MSG_SIZE_ERROR_NEED_REAUTH ||	\
			x == HDCP_ERR_V_COMPARE_ERROR_NEED_REAUTH ||	\
			x == HDCP_ERR_SEQ_NUM_V_ROLL_OVER_ERROR_NEED_REAUTH ||	\
			x == HDCP_ERR_DOWNSTREAM_EXCEED_ERROR_NEED_REAUTH ||	\
			x == HDCP_ERR_REPEATER_SEND_RECEIVERID_LIST_TIMEOUT_NEED_REAUTH || \
			x == HDCP_ERR_INCORRECT_SEQ_NUM_V_NEED_REAUTH )

#define IS_NEED_REAUTH_WITH_MAX_RETRY_COUNT(x)  ( x == HDCP_ERR_READ_CERT_TIMEOUT_NEED_REAUTH || \
			 x == HDCP_ERR_LLC_SIGNATURE_ERROR || \
			 x == HDCP_ERR_READ_H_PRIME_TIMEOUT_NEED_REAUTH || \
			 x == HDCP_ERR_H_COMPARE_ERROR || \
			 x == HDCP_ERR_READ_PAIRING_INFO_TIMEOUT_NEED_REAUTH || \
			 x == HDCP_ERR_LC_INIT_RETRY_COUNT_OVERFLOW || \
			 x == HDCP_ERR_L_COMPARE_ERROR || \
			 x == HDCP_ERR_WRITE_FAILED )

// Timeout value define (ms)
#define	AKE_INIT_TIMEOUT					100
#define CONTENT_STREAM_MANAGEMENT_TIMEOUT	100
#define	AKE_NO_STORED_KM_TIMEOUT			1000
#define	AKE_PAIRING_INFO_TIMEOUT			200
#define	LC_SEND_L_PRIME_TIMEOUT				20			// 7 ms timeout is applied in HDCP interface independant spec
#define REPEATER_SEND_RECEIVERID_TIMEOUT	2500		// 3 seconds (2.9 sec)
#define REPEATER_SEND_STREAM_READY_TIMEOUT  100

// Max retry count during locality check
#define LC_INIT_RETRY_COUNT					1024

#define DELAY_BEFORE_ENC_FRAME				200000		// should be 200ms according to spec

// load r1 or r2 vector if test key is applied.
static int testkey_id = KEY_R1;
HdcpTxParam hdcptx_parm;
INT8 msg_buf[MSG_BUF_SIZE];
extern void spu_print(unsigned char *message, int length);
//#define HDCP2DBGLOG(key, msg, len)  do{pr_debug(key);spu_print(msg, len);}while(0)

void HDCPTx22_init(void)
{
	LOG("[HDCP] Create HDCPTX22 for HDMI\n");
	hdcptx_parm.read_fun=NULL;
	hdcptx_parm.write_fun=NULL;
	hdcptx_parm.read_rx_status_fun=NULL;
	hdcptx_parm.check_read_fun=NULL;
	hdcptx_parm.store_rx_info_fun=NULL;
	hdcptx_parm.find_km_ekhkm_fun=NULL;
	hdcptx_parm.reauth_handler_fun=NULL;
	hdcptx_parm.auth_complete_fun=NULL;
	hdcptx_parm.check_revocation_fun=NULL;

	hdcptx_parm.mState=HDCP_STATE_IDLE;
	hdcptx_parm.mTxVersion=HDCP_TRANSMITTER_INFO_VERSION;

	hdcptx_parm.mPStreamIDType=NULL;
	hdcptx_parm.mk=0;
	hdcptx_parm.mStopHDCPNego=0;
	hdcptx_parm.mReauthRetryCount=0;

	//srand(time(NULL));
	init();
}

void HDCPTx22_deinit(void)
{
	LOG("Delete HDCPTX22 for HDMI\n");
	if(hdcptx_parm.mPStreamIDType!=NULL)
	{
		kfree(hdcptx_parm.mPStreamIDType);
		hdcptx_parm.mPStreamIDType=NULL;
	}
}

void init(void)
{
	if(hdcptx_parm.reauth_handler_fun!=NULL)
	{
		hdcptx_parm.reauth_handler_fun();
	}
	hdcptx_parm.mRepeater=0;
	hdcptx_parm.mRxVersion=0;

	hdcptx_parm.mProtocolDescriptor=0x0;
	hdcptx_parm.mLCInitRetryCount=0;
	hdcptx_parm.mSeqNumV=-1;	// -1 is the default value
	hdcptx_parm.mSeqNumM=0;
	
}

HDCP_ERR hdcp_safe_write(INT8 *buf, INT32 size, INT32 *rst)
{
	if(hdcptx_parm.write_fun!=NULL)
	{
		*rst = hdcptx_parm.write_fun(buf,size);
		if(*rst!=size)
			return HDCP_ERR_WRITE_FAILED;
		else
			return HDCP_ERR_SUCCESS;
	}
	else
	{
		return HDCP_ERR_NO_IO_FUN;
	}
}

HDCP_ERR hdcp_safe_read(INT8 *buf, INT32 size, INT32 *rst)
{
	if(hdcptx_parm.read_fun!=NULL)
	{
		*rst = hdcptx_parm.read_fun(buf,size);
		if(*rst!=size)
		{
			return HDCP_ERR_PAYLOAD_SIZE_ERROR;
		}
		return HDCP_ERR_SUCCESS;
	}
	else
	{
		return HDCP_ERR_NO_IO_FUN;
	}
}

HDCP_ERR hdcp_safe_read_with_timeout(INT8 *buf, INT32 size, INT32 *rst, INT32 ms, UINT32 *time_consume)
{
	HDCP_ERR err_code;
	if(hdcptx_parm.read_fun==NULL)
		return HDCP_ERR_NO_IO_FUN;
	else
	{
		struct timeval tv_start = {0, 0};
		struct timeval tv_end = {0, 0};
		int can_read=-1;
		// start down-count
		//gettimeofday(&tv_start, NULL);
		// wait can read until timeout
		do
		{
			// check can read or not
			can_read=hdcptx_parm.check_read_fun(size);
			// update time consumption
			//gettimeofday(&tv_end, NULL);
		}while(can_read<=0 && hdcp_get_duration(&tv_start,&tv_end)<ms);

		// Make time window checking more flexible, so disable this block,
		// but keeps the implementation for further debug reference.
#if 0
		if(hdcp_get_duration(&tv_start,&tv_end)>=ms)
		{
			*time_consume=hdcp_get_duration(&tv_start,&tv_end);
			*rst = -1;
			return HDCP_ERR_TIMEOUT;
		}
#endif

		if(can_read<=0)
		{
			*time_consume=hdcp_get_duration(&tv_start,&tv_end);
			*rst = -1;
			return HDCP_ERR_TIMEOUT; //return HDCP_ERR_IO_BROKEN;
		}
		
		err_code = hdcp_safe_read(buf,size,rst);
		//gettimeofday(&tv_end, NULL);
		*time_consume=hdcp_get_duration(&tv_start,&tv_end);
		return err_code;
	}
}

HDCP_RST hdcp_check_stored_km(void)
{
	INT32 rst;
#if(DISABLE_STORED_KM_MSG)
	// let HDCP always report no_stored_km
	return HDCP_FALSE;
#endif

	// if no function pointer is assigned, that means ap is not going to support ake_stored_km feature.
	// and engine will return false.
	LOG("[HDCP] check stored km of Rx\n");
	if(hdcptx_parm.find_km_ekhkm_fun==NULL)
		return HDCP_FALSE;

	rst = hdcptx_parm.find_km_ekhkm_fun(
			hdcptx_parm.mReceiverID,HDCP_RECEIVER_ID_SIZE,
			hdcptx_parm.mStoredKm,HDCP_KM_SIZE,
			hdcptx_parm.mStoredEkhKm,HDCP_EKH_KM_SIZE,
			hdcptx_parm.mStoredm,HDCP_M_SIZE);

	LOG("[HDCP] found km & ekhkm rst:%d\n",rst);

	if(rst>=0)
		return HDCP_TRUE;
	else
		return HDCP_FALSE;
}

void hdcp_generate_random_km(void)
{
#if(GENERATE_REAL_RANDOM_VALUE)
	generate_random_number(hdcptx_parm.mKm,HDCP_KM_SIZE,"km");
#else
	if(testkey_id==KEY_R1)
		memcpy(hdcptx_parm.mKm,km_r1,HDCP_KM_SIZE);
	else
	    memcpy(hdcptx_parm.mKm,km_r2,HDCP_KM_SIZE);
#endif
}

void hdcp_generate_random_rtx(void)
{
#if(GENERATE_REAL_RANDOM_VALUE)
	generate_random_number(hdcptx_parm.mRtx,HDCP_RTX_SIZE,"rtx");
#else
	if(testkey_id==KEY_R1)
		memcpy(hdcptx_parm.mRtx,rtx_r1,HDCP_RTX_SIZE);
	else
	    memcpy(hdcptx_parm.mRtx,rtx_r2,HDCP_RTX_SIZE);
#endif
}

void hdcp_generate_random_seed(void)
{
#if(GENERATE_REAL_RANDOM_VALUE)
	generate_random_number(hdcptx_parm.mSeed,HDCP_SEED_SIZE,"seed");
#else
	memcpy(hdcptx_parm.mSeed,seed,HDCP_SEED_SIZE);
#endif
}

void hdcp_generate_random_rn(void)
{
#if(GENERATE_REAL_RANDOM_VALUE)
	generate_random_number(hdcptx_parm.mRn,HDCP_RN_SIZE,"rn");
#else
	if(testkey_id==KEY_R1)
		memcpy(hdcptx_parm.mRn,rn_r1,HDCP_RN_SIZE);
	else
	    memcpy(hdcptx_parm.mRn,rn_r2,HDCP_RN_SIZE);
#endif
}

void hdcp_generate_random_ks(void)
{
#if(GENERATE_REAL_RANDOM_VALUE)
	generate_random_number(hdcptx_parm.mKs,HDCP_KS_SIZE,"ks");
#else
	memcpy(hdcptx_parm.mKs,ks,HDCP_KS_SIZE);
#endif
}

void hdcp_generate_random_riv(void)
{
#if(GENERATE_REAL_RANDOM_VALUE)
	generate_random_number(hdcptx_parm.mRIV,HDCP_RIV_SIZE,"riv");
#else
	if(testkey_id==KEY_R1)
		memcpy(hdcptx_parm.mRIV,riv_r1,HDCP_RIV_SIZE);
	else
	    memcpy(hdcptx_parm.mRIV,riv_r2,HDCP_RIV_SIZE);
#endif
}

void hdcp_compute_h(void)
{
	INT32 duration;
	//LOG(("[HDCP] %s\n",__func__));

	// do some benchmark about time consumption
	struct timeval tv_start = {0, 0};
	struct timeval tv_end = {0, 0};

	//gettimeofday(&tv_start, NULL);

	// prepare KD, (kd = dkey0 || dkey1)
	hdcp_compute_kd();

	// here should use service function hdcp_compute_h_hdmi to get h value
	hdcp_compute_h_hdmi();
	//gettimeofday(&tv_end, NULL);

	duration = hdcp_get_duration(&tv_start,&tv_end);
	LOG("[HDCP] Use %d ms to compute H\n",duration);

#if(DUMP_META_BUFFER)
	// dump result H
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"H");
	dump_buffer((INT8*)hdcptx_parm.mH,HDCP_H_SIZE,msg_buf);
#endif
HDCP2DBGLOG("Hprime:", hdcptx_parm.mH, HDCP_H_SIZE);
}

void hdcp_compute_h_hdmi(void)
{
	H2status rc;
	// prepare src = Rtx || RxCaps || TxCaps
	UINT8 pSrc[HDCP_RTX_SIZE+HDCP_RXTX_CAPS_SIZE+HDCP_RXTX_CAPS_SIZE]={0};
	INT32 offset=0;
    // Rtx
	memcpy(pSrc,hdcptx_parm.mRtx,HDCP_RTX_SIZE);
	offset=offset+HDCP_RTX_SIZE;
    // RxCaps
    memcpy(pSrc+offset,hdcptx_parm.ake_send_cert_msg.RxCaps,HDCP_RXTX_CAPS_SIZE);
	offset=offset+HDCP_RXTX_CAPS_SIZE;
    // TxCaps
    memcpy(pSrc+offset,hdcptx_parm.ake_init_msg.TxCaps,HDCP_RXTX_CAPS_SIZE);
	// H = HMAC-SHA256(pSrc,Kd);
	 rc = hmacsha256(
			hdcptx_parm.mKD,
			HDCP_KD_SIZE,
			pSrc,
			(HDCP_RTX_SIZE+HDCP_RXTX_CAPS_SIZE+HDCP_RXTX_CAPS_SIZE),
			hdcptx_parm.mH);
}

void hdcp_compute_l_no_precomputation(void)
{
	H2status rc;
	//LOG("[HDCP] %s\n",__func__);
	// clear mL
	
	UINT8 kd_xor_rrx[HDCP_KD_SIZE]={0};	// serves as key
	UINT8 rrx_work_buf[HDCP_KD_SIZE]={0};
	memset(hdcptx_parm.mL,0x0,HDCP_L_SIZE);
	// prepare rrx_work_buf
	memcpy(rrx_work_buf+(HDCP_KD_SIZE-HDCP_RRX_SIZE),hdcptx_parm.mRrx,HDCP_RRX_SIZE);

	// do Kd XOR rrx
	crypt_xor(hdcptx_parm.mKD,rrx_work_buf,kd_xor_rrx,HDCP_KD_SIZE);

	// do HMAC-SHA256(rn, Kd XOR rrx)
	rc = hmacsha256(kd_xor_rrx,HDCP_KD_SIZE,hdcptx_parm.mRn,HDCP_RN_SIZE,hdcptx_parm.mL);

#if(DUMP_META_BUFFER)
	// dump data
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"L:");
	dump_buffer((INT8*)hdcptx_parm.mL,HDCP_L_SIZE,msg_buf);
#endif
HDCP2DBGLOG("Lprime: ", hdcptx_parm.mL, HDCP_L_SIZE);
}

void hdcp_compute_kd(void)
{
	LOG("[HDCP] compute kd\n");
	hdcp_compute_dkey(0);
	hdcp_compute_dkey(1);
	// Kd = dkey0 || dkey1
	memset(hdcptx_parm.mKD,0x0,HDCP_KD_SIZE);
	memcpy(hdcptx_parm.mKD,hdcptx_parm.mDKey0,HDCP_DKEY_SIZE);
	memcpy(hdcptx_parm.mKD+HDCP_DKEY_SIZE,hdcptx_parm.mDKey1,HDCP_DKEY_SIZE);

#if(DUMP_META_BUFFER)
	// dump date
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"KD");
	dump_buffer((INT8*)hdcptx_parm.mKD,HDCP_KD_SIZE,msg_buf);
#endif
HDCP2DBGLOG("kd: ", hdcptx_parm.mKD, HDCP_KD_SIZE);
}

void hdcp_compute_dkey(INT8 i)
{
	
#if 0
	static UINT8 pSrc[] = {
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

	UINT8 ctr_in[HDCP_CTR_SIZE]={0};
	UINT8 ctr_out[HDCP_CTR_SIZE]={0};
	UINT8 iv[HDCP_IV_SIZE]={0};			// serve as AES IV

	UINT8 rn_xor_buf[HDCP_KM_SIZE]={0};
	UINT8 km_xor_rn[HDCP_KM_SIZE]={0};	// serve as AES key

	UINT8 aes_out[HDCP_DKEY_SIZE]={0};		// AES output
	UINT8 dkey_buf[HDCP_DKEY_SIZE]={0};

	INT32 offset=0;
	// compute IV:
	// IV = rtx || (rrx XOR ctr)

	// - set counter to ctr_in buffer, i = 0,1 or 2
	ctr_in[HDCP_CTR_SIZE-1]=i;

	// calculate (rrx XOR ctr)
	crypt_xor(mRrx,ctr_in,ctr_out,HDCP_CTR_SIZE);

	// prepare iv IV = rtx || ctr_out
	offset=0;
	memcpy(iv+offset,mRtx,HDCP_RTX_SIZE);
	offset=offset+HDCP_RTX_SIZE;
	memcpy(iv+offset,ctr_out,HDCP_CTR_SIZE);

	// prepare rn which going to XOR with km
	if(i==2)
	{
		// only calculating dkey2 needs a random value rn
		// rn XOR with least-significant 64-bits of km
		memcpy(rn_xor_buf+(HDCP_KM_SIZE-HDCP_RN_SIZE),mRn,HDCP_RN_SIZE);
	}

	// prepare km XOR rn
	crypt_xor(mKm,rn_xor_buf,km_xor_rn,HDCP_KM_SIZE);

	// use (km XOR rn) & IV to calculate dkeyi
	// AES-CTR is applied
	//H2status rc = crypto_aesCtr128(pSrc,sizeof(pSrc),km_xor_rn,iv,aes_out);//zhaodong_yin
	    // Generate Kd                                                                                                                       
 
	// copied from Rx implementation, do known why, but just use it
	// compute dkey = pDst XOR pSrc
	crypt_xor(aes_out,pSrc,dkey_buf,HDCP_DKEY_SIZE);
#endif
UINT8 rn_xor_buf[HDCP_KM_SIZE]={0};
UINT8 dkey_buf[HDCP_DKEY_SIZE]={0};
UINT8 kd_buf[HDCP_KD_SIZE]={0};
LOG("[HDCP] hdcp_compute_dkey %d\n",i);

spu_SetKM(hdcptx_parm.mKm);
if(i == 2)
{
	spu_SetDKey2(dkey_buf);
	RCP_HDCP2_GenDKey(SRAM_KM_ENTRY, hdcptx_parm.mRtx,hdcptx_parm.mRrx, hdcptx_parm.mRn, 2, SRAM_DK2_ENTRY,1);
	spu_GetDKey2(dkey_buf);
}
else if(i == 1)
{
	RCP_HDCP2_GenDKey(SRAM_KM_ENTRY, hdcptx_parm.mRtx,hdcptx_parm.mRrx, rn_xor_buf, 1, SRAM_KD_ENTRY+2,1);
	spu_GetKD(kd_buf);
	memcpy(dkey_buf, kd_buf+HDCP_DKEY_SIZE, HDCP_DKEY_SIZE);
}
else if(i == 0)
{
	spu_SetKD(kd_buf);
	RCP_HDCP2_GenDKey(SRAM_KM_ENTRY, hdcptx_parm.mRtx,hdcptx_parm.mRrx, rn_xor_buf, 0, SRAM_KD_ENTRY,1);
	spu_GetKD(kd_buf);
	memcpy(dkey_buf, kd_buf, HDCP_DKEY_SIZE);
}

#if(DUMP_META_BUFFER)
	// dump result
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"dkey %d",i);
	dump_buffer((INT8*)dkey_buf,HDCP_DKEY_SIZE,msg_buf);
#endif
pr_debug("dkey%d", i);
HDCP2DBGLOG(": ", (UINT8*)dkey_buf, HDCP_DKEY_SIZE);
	// then copy dkey_buf to mapped mDKey
	if(i==0)
		memcpy(hdcptx_parm.mDKey0,dkey_buf,HDCP_DKEY_SIZE);
	else if(i==1)
		memcpy(hdcptx_parm.mDKey1,dkey_buf,HDCP_DKEY_SIZE);
	else if(i==2)
		memcpy(hdcptx_parm.mDKey2,dkey_buf,HDCP_DKEY_SIZE);
	// job done
}

HDCP_ERR hdcp_read_msg(void)
{
	HDCP_ERR err_code=HDCP_ERR_UNDEFINED;
	INT32 offset;
	switch(hdcptx_parm.mState){
	case HDCP_STATE_SEND_AKE_INIT:
		{
			// 1. read AKE_Send_Cert
			//UINT32 time_consumed_send_cert=0;
			LOG("\033[0;33;33m[HDCP][<] read_send_cert\033[m\n");
			err_code=HDCP_ERR_SUCCESS;//read_ake_send_cert(AKE_INIT_TIMEOUT,&time_consumed_send_cert);
			if(testkey_id==KEY_R1)
				memcpy((UINT8*)(&hdcptx_parm.ake_send_cert_msg), gR1_Ake_send_cert, sizeof(AKE_Send_Cert_Msg));
			else
	   			 memcpy((UINT8*)(&hdcptx_parm.ake_send_cert_msg), gR2_Ake_send_cert, sizeof(AKE_Send_Cert_Msg));
			
			// LOG("Read AKE_Send_Cert use:%d ms\n",time_consumed_send_cert);

			if(IS_SUCCESS(err_code))
			{
				// check message ID
				if(hdcptx_parm.ake_send_cert_msg.id!=AKE_SEND_CERT)
					return HDCP_ERR_MSG_ID_ERROR;

				// in HDCP 2.2 HDMI spec, ake_send_cert payload contains following data
				// - certrx
				offset=0;
				// receiverID
				memcpy(hdcptx_parm.mReceiverID,hdcptx_parm.ake_send_cert_msg.cert_rx+offset,HDCP_RECEIVER_ID_SIZE);

				offset=offset+HDCP_RECEIVER_ID_SIZE;
				// receiver public key
				memcpy(hdcptx_parm.mReceiverPublicKey,hdcptx_parm.ake_send_cert_msg.cert_rx+offset,HDCP_RECEIVER_PUBLIC_KEY_SIZE);

				// protocol descriptor - should always be 0x0 in HDMI spec
				offset=offset+HDCP_RECEIVER_PUBLIC_KEY_SIZE;
				hdcptx_parm.mProtocolDescriptor=(hdcptx_parm.ake_send_cert_msg.cert_rx[offset]>>4 & 0xf);

				offset=offset+2;
				// LLC signature
				memcpy(hdcptx_parm.mLLCSignature,hdcptx_parm.ake_send_cert_msg.cert_rx+offset,HDCP_RECEIVER_LLC_SIGNATURE_SIZE);
				LOG("[HDCP] Analysis RxCert.\n");

#if(DUMP_META_BUFFER)
				// dump data
				memset(msg_buf,0x0,MSG_BUF_SIZE);
				snprintf(msg_buf,MSG_BUF_SIZE,"ReceiverID:");
				dump_buffer((INT8*)hdcptx_parm.mReceiverID,HDCP_RECEIVER_ID_SIZE,msg_buf);

				memset(msg_buf,0x0,MSG_BUF_SIZE);
				snprintf(msg_buf,MSG_BUF_SIZE,"ReceiverPublicKey (kpubrx):");
				dump_buffer((INT8*)hdcptx_parm.mReceiverPublicKey,HDCP_RECEIVER_PUBLIC_KEY_SIZE,msg_buf);

				memset(msg_buf,0x0,MSG_BUF_SIZE);
				snprintf(msg_buf,MSG_BUF_SIZE,"ReceiverLLC:");
				dump_buffer((INT8*)mLLCSignature,HDCP_RECEIVER_LLC_SIGNATURE_SIZE,msg_buf);
#endif
				HDCP2DBGLOG("ReceiverID: ", (UINT8*)hdcptx_parm.mReceiverID, HDCP_RECEIVER_ID_SIZE);
				HDCP2DBGLOG("ReceiverPublicKey (kpubrx): ", (UINT8*)hdcptx_parm.mReceiverPublicKey, HDCP_RECEIVER_PUBLIC_KEY_SIZE);
				HDCP2DBGLOG("ReceiverLLC: ", (UINT8*)hdcptx_parm.mLLCSignature, HDCP_RECEIVER_LLC_SIGNATURE_SIZE);

				// TODO check revocation list


				// verify LLC signature
				if(check_LLC_signature()!=HDCP_TRUE)
				{
					return HDCP_ERR_LLC_SIGNATURE_ERROR;
				}

				// - rrx
				memcpy(hdcptx_parm.mRrx,hdcptx_parm.ake_send_cert_msg.rrx,HDCP_RRX_SIZE);

#if(DUMP_META_BUFFER)
				// dump data
				memset(msg_buf,0x0,MSG_BUF_SIZE);
				snprintf(msg_buf,MSG_BUF_SIZE,"Rrx:");
				dump_buffer((INT8*)hdcptx_parm.mRrx,HDCP_RRX_SIZE,msg_buf);
#endif
				HDCP2DBGLOG("Rrx: ", (UINT8*)hdcptx_parm.mRrx, HDCP_RRX_SIZE);
				// - RxCaps
				hdcptx_parm.mRxVersion = hdcptx_parm.ake_send_cert_msg.RxCaps[0];
				hdcptx_parm.mRepeater = hdcptx_parm.ake_send_cert_msg.RxCaps[2];

                LOG("RxCap: %.2x %.2x %.2x",
                		hdcptx_parm.ake_send_cert_msg.RxCaps[0],
                		hdcptx_parm.ake_send_cert_msg.RxCaps[1],
                		hdcptx_parm.ake_send_cert_msg.RxCaps[2]);

				if(hdcp_check_stored_km()==HDCP_TRUE)
				{
					hdcptx_parm.mState = HDCP_STATE_SEND_STORED_KM;
				}
				else
				{
					hdcptx_parm.mState = HDCP_STATE_SEND_NO_STORED_KM;
				}
			}
		}
		break;
	case HDCP_STATE_SEND_STORED_KM:
	case HDCP_STATE_SEND_NO_STORED_KM:
		{
			UINT32 time_consumed_h_prime=0;
			UINT32 time_consumed_pairing_info;
			LOG("\033[0;33;33m[HDCP][<] read_send_h_prime\033[m\n");
			err_code = HDCP_ERR_SUCCESS;//read_ake_send_h_prime(AKE_NO_STORED_KM_TIMEOUT,&time_consumed_h_prime);
			if(testkey_id==KEY_R1)
				memcpy((UINT8*)(&hdcptx_parm.ake_send_h_prime_msg), gR1_AKE_Send_H_Prime, sizeof(AKE_Send_H_Prime_Msg));
			else
	   			 memcpy((UINT8*)(&hdcptx_parm.ake_send_h_prime_msg), gR2_AKE_Send_H_Prime, sizeof(AKE_Send_H_Prime_Msg));
			
			if(IS_SUCCESS(err_code))
			{
				// check message ID
				if(hdcptx_parm.ake_send_h_prime_msg.id!=AKE_SEND_H_PRIME)
					return HDCP_ERR_MSG_ID_ERROR;

				LOG("[HDCP] Read Hprime ok, start checking H' correctness.\n");
				hdcp_compute_h();
				if(memcmp(hdcptx_parm.mH,hdcptx_parm.ake_send_h_prime_msg.h_prime,HDCP_H_SIZE)!=0)
				{
					LOG("[HDCP] H compare failed\n");
					err_code=HDCP_ERR_H_COMPARE_ERROR;
				}
				else
				{
					if(hdcptx_parm.mState==HDCP_STATE_SEND_NO_STORED_KM)
					{
						LOG("[HDCP] H compare success, read Pairing_Info in no_stored_km case\n");
						// next continue read AKE_Send_Pairing_Info.
						time_consumed_pairing_info=0;
						LOG("\033[0;33;33m[HDCP][<] read_send_pairing_info\033[m\n");
						err_code= HDCP_ERR_SUCCESS;//read_ake_send_pairing_info(AKE_PAIRING_INFO_TIMEOUT,&time_consumed_pairing_info);
						if(testkey_id==KEY_R1)
							memcpy((UINT8*)(&hdcptx_parm.ake_send_pairing_info_msg), gR1_AKE_Send_pairing_info, sizeof(hdcptx_parm.ake_send_pairing_info_msg));
						else
	   						memcpy((UINT8*)(&hdcptx_parm.ake_send_pairing_info_msg), gR2_AKE_Send_pairing_info, sizeof(hdcptx_parm.ake_send_pairing_info_msg));
						
						LOG("[HDCP] Read Pairing Info use %d ms\n",time_consumed_pairing_info);
						if(IS_SUCCESS(err_code))
						{
							// check message id
							if(hdcptx_parm.ake_send_pairing_info_msg.id!=AKE_SEND_PAIRING_INFO)
								return HDCP_ERR_MSG_ID_ERROR;

							memcpy(hdcptx_parm.mEKhKm,hdcptx_parm.ake_send_pairing_info_msg.e_kh_km,HDCP_EKH_KM_SIZE);
							// save pairing info to internal storage
							hdcp_save_pairing_info();

							// every thing is correct, then switch to next state
							//LOG("change state to LC_INIT\n");
							hdcptx_parm.mState=HDCP_STATE_SEND_LC_INIT;
						}
					}
					else
					{
						LOG("[HDCP] H compare success, switch to LC_Init in stored_km case\n");
						hdcptx_parm.mState=HDCP_STATE_SEND_LC_INIT;
					}
				}
			}
			else
			{
				LOG("Read Hprime error rst=%d. time used=%d.\n",err_code,time_consumed_h_prime);
			}
		}
		break;
	case HDCP_STATE_SEND_LC_INIT:
	case HDCP_STATE_RESEND_LC_INIT:
		{
			// Locality check without pre-computation support, read LC_Send_L_prime in 20 ms
			UINT32 time_consumed=0;
			LOG("\033[0;33;33m[HDCP][<] read_send_l_prime\033[m\n");
			err_code = HDCP_ERR_SUCCESS;//read_lc_send_l_prime_no_precompute(LC_SEND_L_PRIME_TIMEOUT,&time_consumed);
			if(testkey_id==KEY_R1)
				memcpy((UINT8*)(&hdcptx_parm.lc_send_l_prime_no_precompute_msg), gR1_LC_SEND_L_PRIME, sizeof(hdcptx_parm.lc_send_l_prime_no_precompute_msg));
			else
	   			 memcpy((UINT8*)(&hdcptx_parm.lc_send_l_prime_no_precompute_msg), gR2_LC_SEND_L_PRIME, sizeof(hdcptx_parm.lc_send_l_prime_no_precompute_msg));
			
			LOG("[HDCP] read l_prime use %d ms err_code= %s\n",time_consumed,hdcp_err_str[err_code]);
			if(IS_SUCCESS(err_code))
			{
				// check message id
				if(hdcptx_parm.lc_send_l_prime_no_precompute_msg.id!=LC_SEND_L_PRIME)
					return HDCP_ERR_MSG_ID_ERROR;

				// compute L and check correctness
				hdcp_compute_l_no_precomputation();
				// compare with L'
				if(memcmp(hdcptx_parm.mL,hdcptx_parm.lc_send_l_prime_no_precompute_msg.l_prime,HDCP_L_SIZE)!=0)
				{
					LOG("[HDCP] Locality check error, L prime check error\n");
					err_code=HDCP_ERR_L_COMPARE_ERROR;
				}
				else
				{
					LOG("[HDCP] Locality check pass, change state to Send_SKE\n");
					hdcptx_parm.mState=HDCP_STATE_SEND_SKE;
				}
			}
			else
			{
			#if 0
				if(err_code==HDCP_ERR_TIMEOUT)
				{
					hdcptx_parm.mLCInitRetryCount++;
					if(hdcptx_parm.mLCInitRetryCount<LC_INIT_RETRY_COUNT)
					{
						LOG("\033[0;33;33m[HDCP] read L prime timeout retry count: %d\033[m\n",hdcptx_parm.mLCInitRetryCount);
						hdcptx_parm.mState=HDCP_STATE_RESEND_LC_INIT;
						err_code = HDCP_ERR_RESEND_LC_INIT;
					}
					else
					{
						LOG("[HDCP] read L prime timeout retry count overflow\n");
						err_code = HDCP_ERR_LC_INIT_RETRY_COUNT_OVERFLOW;
					}
				}
				else
			#endif
				{
					LOG("[HDCP] read L prime fatal error err_code=%s\n",hdcp_err_str[err_code]);
				}
			}
		}
		break;
	case HDCP_STATE_SEND_SKE:
		{
			// if code can reach here, means a connected sink is a REPEATER.
			// wait READY message in RxStatus for 3 seconds
			UINT32 time_consumed=0;
			LOG("\033[0;33;33m[HDCP][<] read_Repeater_Auth_ReceiverId_list\033[m\n");
			err_code = read_repeater_auth_receiverId_list(
					REPEATER_SEND_RECEIVERID_TIMEOUT,
					&time_consumed);
		}
		break;
	default:
		break;
	}

	LOG("[HDCP] %s rst=%s \n",__func__,hdcp_err_str[err_code]);

	return err_code;
}

HDCP_ERR hdcp_send_msg(void)
{
	HDCP_ERR err_code=HDCP_ERR_UNDEFINED;
	switch(hdcptx_parm.mState)
	{
	case HDCP_STATE_SEND_AKE_INIT:
		LOG("\033[0;33;33m[HDCP][>] AKE_Init\033[m\n");
		err_code = send_ake_init();
		break;
	case HDCP_STATE_SEND_NO_STORED_KM:
		LOG("\033[0;33;33m[HDCP][>] AKE_No_Stored_km\033[m\n");
		err_code = send_ake_nostored_km();
		break;
	case HDCP_STATE_SEND_STORED_KM:
		LOG("\033[0;33;33m[HDCP][>] AKE_Stored_km\033[m\n");
		err_code = send_ake_stored_km();
		break;
	case HDCP_STATE_SEND_LC_INIT:
	case HDCP_STATE_RESEND_LC_INIT:
		LOG("\033[0;33;33m[HDCP][>] (resend) LC_Init retry count %d\033[m\n",hdcptx_parm.mLCInitRetryCount);
		err_code = send_lc_init();
		break;
	case HDCP_STATE_SEND_SKE:
		LOG("\033[0;33;33m[HDCP][>] Send_SKE\033[m\n");
		err_code = send_ske();
		break;
	case HDCP_STATE_REPEATER_AUTH_SEND_ACK:
		LOG("\033[0;33;33m[HDCP][>] RepeaterAuth Send Ack\033[m\n");
		err_code = send_repeaterAuth_Ack();
		break;
	default:
		break;
	}
	return err_code;
}

void dump_buffer(INT8 *buf, INT32 size, INT8 *description)
{
	

    INT8 line_buf[NUMS_PER_LINE*4];
    INT8 tmp[NUMS_PER_LINE*4];
    INT8 digits[10];
    int i;
    LOG("\n%s length:%d\n",description,size);
    memset(line_buf,0x0,NUMS_PER_LINE*4);
	for(i=0;i<size;i++)
	{
	    memset(digits,0x0,10);
	    sprintf(digits,"%.2x",(buf[i] & 0xff));

        // append
        memcpy(tmp,line_buf,NUMS_PER_LINE*4);
        sprintf(line_buf,"%s %s",tmp,digits);

		if((i+1)%NUMS_PER_LINE==0)
		{
			LOG("\033[0;32;32m%s\033[m",line_buf);
            memset(line_buf,0x0,NUMS_PER_LINE*4);
            memset(tmp,0x0,NUMS_PER_LINE*4);
		}
	}

    // dump rest of the data
    LOG("\033[0;32;32m%s\033[m",line_buf);
}

void compare_buffers(INT8 *buf1, INT8 *buf2, INT32 size, INT8 *description)
{
	int i;
	LOG("[HDCP] Compare %s %d bytes\n",description,size);
	for(i=0;i<size;i++)
	{
		if(buf1[i]!=buf2[i])
		{
			LOG("\033[0;31;31m[HDCP] buffer compare error.\033[m\n");
			return;
		}
	}
	LOG("\033[0;32;32m[HDCP] data is correct.\033[m\n");
}

UINT32 hdcp_get_duration(struct timeval *start, struct timeval* end)
{
	UINT32 duration=(end->tv_sec - start->tv_sec)*1000000 + (end->tv_usec - start->tv_usec);
	// convert microsecond to millisecond.
	duration=duration/1000;
	return duration;
}

HDCP_ERR send_ake_init(void)
{
	//INT32 write_size=0;
	// prepare ake_init payload
	memset(&hdcptx_parm.ake_init_msg,0x0,sizeof(AKE_Init_Msg));
	hdcptx_parm.ake_init_msg.id=AKE_INIT;
	hdcp_generate_random_rtx();
	memcpy(hdcptx_parm.ake_init_msg.rtx,hdcptx_parm.mRtx,HDCP_RTX_SIZE);

	hdcptx_parm.ake_init_msg.TxCaps[0]=HDCP_TRANSMITTER_INFO_VERSION;
	hdcptx_parm.ake_init_msg.TxCaps[1]=0x0;
	hdcptx_parm.ake_init_msg.TxCaps[2]=0x0;

#if(DUMP_OUT_DATA)
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"[>] send AKE_Init");
	dump_buffer((INT8*)(&hdcptx_parm.ake_init_msg),sizeof(AKE_Init_Msg),msg_buf);
#endif

	
	HDCP2DBGLOG("AKE_INIT: ", (UINT8*)(&hdcptx_parm.ake_init_msg), sizeof(AKE_Init_Msg));
	return HDCP_ERR_SUCCESS;//hdcp_safe_write((INT8*)(&ake_init_msg),sizeof(AKE_Init_Msg),&write_size);
}

HDCP_ERR send_lc_init(void)
{
	//INT32 write_size=0;
	HDCP_ERR err_code;
	// generate 64-bits random rn
	hdcp_generate_random_rn();
	// send LC_Init message
	memset((INT8*)(&hdcptx_parm.lc_init_msg),0x0,sizeof(Lc_Init_Msg));
	hdcptx_parm.lc_init_msg.id=LC_INIT;
	memcpy(hdcptx_parm.lc_init_msg.rn,hdcptx_parm.mRn,HDCP_RN_SIZE);

#if(DUMP_OUT_DATA)
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"[>] send LC_Init");
	dump_buffer((INT8*)(&hdcptx_parm.lc_init_msg),sizeof(Lc_Init_Msg),msg_buf);
#endif
	HDCP2DBGLOG("LC_Init: ", (UINT8*)(&hdcptx_parm.lc_init_msg), sizeof(Lc_Init_Msg));
	
	err_code = HDCP_ERR_SUCCESS;//hdcp_safe_write((INT8*)(&lc_init_msg),sizeof(Lc_Init_Msg),&write_size);
	return err_code;
}

HDCP_ERR send_ake_stored_km(void)
{
	//INT32 write_size=0;
	HDCP_ERR err_code;
	memset(&hdcptx_parm.ake_stored_km_msg,0x0,sizeof(AKE_Stored_km_Msg));
	hdcptx_parm.ake_stored_km_msg.id=AKE_STORED_KM;
	memcpy(hdcptx_parm.ake_stored_km_msg.m,hdcptx_parm.mStoredm,HDCP_KM_SIZE);
	memcpy(hdcptx_parm.ake_stored_km_msg.e_kh_km,hdcptx_parm.mStoredEkhKm,HDCP_EKH_KM_SIZE);
	
	err_code = HDCP_ERR_SUCCESS;//hdcp_safe_write((INT8*)(&ake_stored_km_msg),sizeof(AKE_Stored_km_Msg),&write_size);

	if(IS_SUCCESS(err_code))
	{
		// copy stored km to km
		memcpy(hdcptx_parm.mKm,hdcptx_parm.mStoredKm,HDCP_KM_SIZE);
	}

#if(DUMP_OUT_DATA)
    memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"[>] send ake_stored_km");
	dump_buffer((INT8*)(&hdcptx_parm.ake_stored_km_msg),sizeof(AKE_Stored_km_Msg),msg_buf);
#endif
	HDCP2DBGLOG("AKE_Send_stored_km: ", (UINT8*)(&hdcptx_parm.ake_stored_km_msg), sizeof(hdcptx_parm.ake_stored_km_msg));
	return err_code;
}

HDCP_ERR send_ake_nostored_km(void)
{
	// refer to PKCS#1 2.1 page 19
	// size: 32 bytes
	static const UINT8 sha256NullHash[SHA256_DIGEST_HDCP2_SIZE] = {
			0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14,
			0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24,
			0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
			0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55 };
	INT32 offset = 0; 
	int i;
	INT32 ps_len;
	INT32 db_size;
	UINT8* pDB ;
	UINT8* pdbMask;
	UINT8* pMaskedDB;
	UINT8 seedMask[HDCP_SEED_SIZE]={0};
	UINT8 EM[(1024/8)]={0};
	DIGIT_T m[(1024/32)]={0};
	DIGIT_T c[(1024/32)]={0};
	// prepare e and n, convert from octet string to digits
	DIGIT_T n[(1024/32)]={0};
	DIGIT_T e[(1024/32)]={0};
	INT32 rst=0;    
	HDCP_ERR err_code;
	UINT8 ekpubkm[(1024/8)]={0};
	UINT8 maskedSeed[HDCP_SEED_SIZE]={0};
	// generate a random 128-bits km
	hdcp_generate_random_km();

#if(DUMP_META_BUFFER)
	// dump km
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"km:");
	dump_buffer((INT8*)hdcptx_parm.mKm,HDCP_KM_SIZE,msg_buf);
#endif
	HDCP2DBGLOG("KM: ", (UINT8*)hdcptx_parm.mKm, HDCP_KM_SIZE);
	LOG("[HDCP] encrypt EkhKm.\n");

	// Refer to Spec PKCS #1 v2.1 section 7.1.1 RSAES-OAEP-Encrypt
	// *** Start encrypt km *** //
	// PS = octet string consisting of k - mLen - 2hLen -2 zero octets.
	// PS length would be 46 if SHA-256 is applied
	ps_len = 1024/8 - HDCP_KM_SIZE - 2*(SHA256_DIGEST_HDCP2_SIZE) - 2;
	//LOG("PS length=%d\n",ps_len);

	// generate DB = lHash || PS || 0x01 || km.
	// DB length = k - hLen - 1; (128 - 32 - 1) = 95
	db_size=SHA256_DIGEST_HDCP2_SIZE+ps_len+1+HDCP_KM_SIZE;
	pDB = (UINT8*)kcalloc(db_size, sizeof(unsigned char), GFP_KERNEL);
	offset=0;

	memcpy(pDB+offset,sha256NullHash,SHA256_DIGEST_HDCP2_SIZE);
	offset=offset+SHA256_DIGEST_HDCP2_SIZE;
	for(i=0;i<ps_len;i++)
	{
		pDB[offset]=0x0;
		offset++;
	}
	pDB[offset]=0x1;
	offset=offset+1;
	memcpy(pDB+offset,hdcptx_parm.mKm,HDCP_KM_SIZE);

#if(DUMP_META_BUFFER)
	// dump DB while developing
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"DB raw:");
	dump_buffer((INT8*)pDB,db_size,msg_buf);
#endif

	// generate random seed
	hdcp_generate_random_seed();

#if(DUMP_META_BUFFER)
	// dump random seed
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"seed:");
	dump_buffer((INT8*)hdcptx_parm.mSeed,HDCP_SEED_SIZE,msg_buf);
#endif

	pdbMask = (UINT8*)kcalloc(db_size, sizeof(unsigned char), GFP_KERNEL);
	// dbMask = MGF(seed, k-hLen-1);
	MGF1_SHA256(pdbMask,db_size,hdcptx_parm.mSeed,HDCP_SEED_SIZE);
	// maskedDB = DB xor dbMask
	pMaskedDB=(UINT8*)kcalloc(db_size, sizeof(unsigned char), GFP_KERNEL);
	crypt_xor(pDB,pdbMask,pMaskedDB,db_size);

	// seedMask = MGF(maskedDB,hLen)
	
	MGF1_SHA256(seedMask,HDCP_SEED_SIZE,pMaskedDB,db_size);

	// maskedSeed = seed xor seedMask
	
	crypt_xor(hdcptx_parm.mSeed,seedMask,maskedSeed,HDCP_SEED_SIZE);

	// EM = 0x0 || maskedSeed || maskedDB
	// EM length = k
	
	offset=0;

	offset=offset+1;
	memcpy(EM+offset,maskedSeed,HDCP_SEED_SIZE);
	offset=offset+HDCP_SEED_SIZE;
	memcpy(EM+offset,pMaskedDB,db_size);

#if(DUMP_META_BUFFER)
	// dump EM while developing
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"EM raw:");
	dump_buffer((INT8*)EM,(1024/8),msg_buf);
#endif

	// free allocated buffers
	kfree(pDB);
	kfree(pdbMask);
	kfree(pMaskedDB);

	// m = OS2IP(EM)
	
	mpConvFromOctets(m, (1024/32), EM, (1024/8));

	// c = RSAEP((n,e),m)
	// where (n,e) is the RSA public key
	// refer to PKCS #1 v2.1 section 5.1.1
	// c = m^e mod n
	
	mpConvFromOctets(n,(1024/32),hdcptx_parm.mReceiverPublicKey,(1024/8));
	mpConvFromOctets(e,(1024/32),hdcptx_parm.mReceiverPublicKey+(1024/8),3);
	mpModExp(c,m,e,n,(1024/32));

	// convert c into octet string
	
	mpConvToOctets(c,(1024/32),ekpubkm,(1024/8));

#if(DUMP_META_BUFFER)
	// dump result while developing
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"ekpubkm:");
	dump_buffer((INT8*)ekpubkm,(1024/8),msg_buf);
#endif
	HDCP2DBGLOG("ekpubkm: ", (UINT8*)ekpubkm, sizeof(ekpubkm));
#if(USE_TEST_VECTOR)
	// compare with test vector
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"check ekpubkm:");
	if(testkey_id==KEY_R1)
		compare_buffers((INT8*)ekpubkm,(INT8*)ekpubkm_r1,HDCP_EKPUB_KM_SIZE,msg_buf);
	else
	    compare_buffers((INT8*)ekpubkm,(INT8*)ekpubkm_r2,HDCP_EKPUB_KM_SIZE,msg_buf);
#endif

	// pack outgoing data and send to rx
	hdcptx_parm.ake_no_stored_km_msg.id=AKE_NO_STORED_KM;
	memcpy(hdcptx_parm.ake_no_stored_km_msg.e_kpub_km,ekpubkm,HDCP_EKPUB_KM_SIZE);

	 rst=0;    
	 err_code = HDCP_ERR_SUCCESS;//hdcp_safe_write((INT8*)(&ake_no_stored_km_msg),sizeof(AKE_No_Stored_km_Msg),&rst);

#if(DUMP_OUT_DATA)
    memset(msg_buf,0x0,MSG_BUF_SIZE);
    snprintf(msg_buf,MSG_BUF_SIZE,"[>] send AKE_Send_no_stored_km");
    dump_buffer((INT8*)(&hdcptx_parm.ake_no_stored_km_msg),sizeof(AKE_No_Stored_km_Msg),msg_buf);
#endif
	HDCP2DBGLOG("AKE_Send_no_stored_km: ", (UINT8*)(&hdcptx_parm.ake_no_stored_km_msg), sizeof(AKE_No_Stored_km_Msg));
	return err_code;
}

HDCP_ERR send_ske(void)
{
	int i;
	UINT8 dkey2_xor_rrx[HDCP_DKEY_SIZE]={0};
	UINT8 rrx_work_buf[HDCP_DKEY_SIZE]={0};
	//INT32 write_size=0;
	HDCP_ERR err_code;
	hdcp_generate_random_ks();

#if(DUMP_OUT_DATA)	
	memset(msg_buf,0x0,MSG_BUF_SIZE);
    snprintf(msg_buf,MSG_BUF_SIZE,"ks [1]");
    dump_buffer((INT8*)mKs,HDCP_KS_SIZE,msg_buf);
#endif

	hdcp_generate_random_riv();
	hdcp_compute_dkey(2);

	// EKS = ks XOR ( dkey2 [least-significant 64-bits] XOR rrx)
	

	memcpy(rrx_work_buf+(HDCP_DKEY_SIZE-HDCP_RRX_SIZE),hdcptx_parm.mRrx,HDCP_RRX_SIZE);
	crypt_xor(hdcptx_parm.mDKey2,rrx_work_buf,dkey2_xor_rrx,HDCP_DKEY_SIZE);

	memset(hdcptx_parm.mEKS,0x0,HDCP_EKS_SIZE);
	crypt_xor(hdcptx_parm.mKs,dkey2_xor_rrx,hdcptx_parm.mEKS,HDCP_EKS_SIZE);

#if(DUMP_META_BUFFER)
	// dump buffer
	memset(msg_buf,0x0,MSG_BUF_SIZE);
	snprintf(msg_buf,MSG_BUF_SIZE,"eks");
	dump_buffer((INT8*)hdcptx_parm.mEKS,HDCP_EKS_SIZE,msg_buf);
#endif

	memset((INT8*)(&hdcptx_parm.ske_send_eks_msg),0x0,sizeof(SKE_Send_Eks_Msg));
	hdcptx_parm.ske_send_eks_msg.id=SKE_SEND_EKS;
	memcpy(hdcptx_parm.ske_send_eks_msg.edkey_ks,hdcptx_parm.mEKS,HDCP_EKS_SIZE);
	memcpy(hdcptx_parm.ske_send_eks_msg.r_iv,hdcptx_parm.mRIV,HDCP_RIV_SIZE);

#if(DUMP_OUT_DATA)
		memset(msg_buf,0x0,MSG_BUF_SIZE);
		snprintf(msg_buf,MSG_BUF_SIZE,"[>] send AKE_Send_SKE");
		dump_buffer((INT8*)(&hdcptx_parm.ske_send_eks_msg),sizeof(SKE_Send_Eks_Msg),msg_buf);
#endif
HDCP2DBGLOG("SKE_send_eks_msg: ", (UINT8*)(&hdcptx_parm.ske_send_eks_msg), sizeof(hdcptx_parm.ske_send_eks_msg));

	 err_code = HDCP_ERR_SUCCESS;//hdcp_safe_write(
			//(INT8*)(&ske_send_eks_msg),
			//sizeof(SKE_Send_Eks_Msg),
			//&write_size);

	if(IS_SUCCESS(err_code))
	{
		// if sink is a receiver, nego is finished here!
		if(hdcptx_parm.mRepeater==0)
			err_code=HDCP_ERR_NEGO_COMPLETE;

		// at this time, notify upper level to start HDCP encryption, refer to spec page 28, State A3.
		if(hdcptx_parm.auth_complete_fun!=NULL)
		{
		
#if(DUMP_OUT_DATA)	
		    memset(msg_buf,0x0,MSG_BUF_SIZE);
        	snprintf(msg_buf,MSG_BUF_SIZE,"ks [2]");
        	dump_buffer((INT8*)mKs,HDCP_KS_SIZE,msg_buf);
#endif

			UINT8 ksXORLc128Temp[HDCP_KS_SIZE]={0};

			// use different Lc128 (test key v.s production key)
#if(USE_TEST_VECTOR)
            LOG("[HDCP] use test lc128\n");
			crypt_xor(hdcptx_parm.mKs,gcLc128_22,ksXORLc128Temp,HDCP_KS_SIZE);
#else
            LOG("[HDCP] use production lc128 []\n");
			crypt_xor(hdcptx_parm.mKs,gcLc128_22_Production,ksXORLc128Temp,HDCP_KS_SIZE);
#endif

#if(DUMP_OUT_DATA)	
            memset(msg_buf,0x0,MSG_BUF_SIZE);
        	snprintf(msg_buf,MSG_BUF_SIZE,"ks_xor_1c128 [before swap]");
        	dump_buffer((INT8*)ksXORLc128Temp,HDCP_KS_SIZE,msg_buf);
#endif

			// prepare riv & ks_XOR_LC128 for cipher engine, need byte swap.
			memset(hdcptx_parm.mRIVCipher,0x0,HDCP_RIV_SIZE);
			memset(hdcptx_parm.mKsXORLc128,0x0,HDCP_KS_SIZE);

			// convert riv
			for(i=0;i<HDCP_RIV_SIZE;i++)
			{
				hdcptx_parm.mRIVCipher[i]=hdcptx_parm.mRIV[HDCP_RIV_SIZE-1-i];
			}
			// convert ksXORLc128
			for(i=0;i<HDCP_KS_SIZE;i++)
			{
				hdcptx_parm.mKsXORLc128[i]=ksXORLc128Temp[HDCP_KS_SIZE-1-i];
			}
            //usleep(DELAY_BEFORE_ENC_FRAME);
			hdcptx_parm.auth_complete_fun(hdcptx_parm.mRIVCipher,HDCP_RIV_SIZE,hdcptx_parm.mKsXORLc128,HDCP_KS_SIZE);
		}
	}
	return err_code;
}

HDCP_ERR send_repeaterAuth_Ack(void)
{
	HDCP_ERR err_code;
	INT32 write_rst=0;
	memset(&hdcptx_parm.repeaterAuth_send_ack_msg,0x0,sizeof(RepeaterAuth_Send_Ack_Msg));
	hdcptx_parm.repeaterAuth_send_ack_msg.id=REPEATER_AUTH_SEND_ACK;
	memcpy(hdcptx_parm.repeaterAuth_send_ack_msg.v,hdcptx_parm.mV+HDCP_V_SIZE,HDCP_V_SIZE);
	LOG("[HDCP] send V (last significant 128 bits) back to Rx\n");

#if(DUMP_OUT_DATA)
		memset(msg_buf,0x0,MSG_BUF_SIZE);
		snprintf(msg_buf,MSG_BUF_SIZE,"[>] send RepeaterAuth_Ack");
		dump_buffer((INT8*)(&hdcptx_parm.repeaterAuth_send_ack_msg),sizeof(RepeaterAuth_Send_Ack_Msg),msg_buf);
#endif

	
	 err_code = hdcp_safe_write(
			(INT8 *)&hdcptx_parm.repeaterAuth_send_ack_msg,
			sizeof(RepeaterAuth_Send_Ack_Msg),
			&write_rst);

	// nego is completed when receiver list is received.
	if(IS_SUCCESS(err_code))
		err_code = HDCP_ERR_NEGO_COMPLETE_WITH_REPEATER;

	return err_code;
}

HDCP_ERR send_repeater_auth_content_stream_manage(void)
{
	INT32 write_rst=0;
	HDCP_ERR err_code;
	UINT8 *out;
	LOG("[HDCP] send RepeaterAuth Content Stream Manage Message.\n");
	memset(&hdcptx_parm.repeaterAuth_stream_manage_msg_h,0x0,sizeof(RepeaterAuth_Stream_Manage_Msg_Heading));
	// id
	hdcptx_parm.repeaterAuth_stream_manage_msg_h.id=REPEATER_AUTH_STREAM_MANAGE;

	hdcptx_parm.mSeqNumMBuf[0]=(UINT8)((hdcptx_parm.mSeqNumM>>16)&0xff);
	hdcptx_parm.mSeqNumMBuf[1]=(UINT8)((hdcptx_parm.mSeqNumM>> 8)&0xff);
	hdcptx_parm.mSeqNumMBuf[2]=(UINT8)((hdcptx_parm.mSeqNumM>> 0)&0xff);

	memcpy(hdcptx_parm.repeaterAuth_stream_manage_msg_h.seq_sum_m,hdcptx_parm.mSeqNumMBuf,HDCP_SEQ_NUM_M_SIZE);

	// k
	hdcptx_parm.mk = 0x1;
	hdcptx_parm.repeaterAuth_stream_manage_msg_h.k[0]=(hdcptx_parm.mk>>8)&0xff;
	hdcptx_parm.repeaterAuth_stream_manage_msg_h.k[1]=(hdcptx_parm.mk>>0)&0xff;

	// prepare payload
	if(hdcptx_parm.mPStreamIDType!=NULL)
	{
		kfree(hdcptx_parm.mPStreamIDType);
		hdcptx_parm.mPStreamIDType=NULL;
	}

	hdcptx_parm.mPStreamIDType = (UINT8 *)kcalloc(2*hdcptx_parm.mk, sizeof(unsigned char), GFP_KERNEL);

	hdcptx_parm.mPStreamIDType[0]=0x0;	// stream id should always be 0
	hdcptx_parm.mPStreamIDType[1]=0x1;	// type 0x1, refer to test vector now.

	// create output data
	out=(UINT8 *)kcalloc(sizeof(RepeaterAuth_Stream_Manage_Msg_Heading)+(2*hdcptx_parm.mk), sizeof(unsigned char), GFP_KERNEL);

	memcpy(out,&hdcptx_parm.repeaterAuth_stream_manage_msg_h,sizeof(RepeaterAuth_Stream_Manage_Msg_Heading));
	memcpy(out+sizeof(RepeaterAuth_Stream_Manage_Msg_Heading),hdcptx_parm.mPStreamIDType,(2*hdcptx_parm.mk));

	err_code=hdcp_safe_write((INT8 *)out,
			sizeof(RepeaterAuth_Stream_Manage_Msg_Heading)+(2*hdcptx_parm.mk),
			&write_rst);

	kfree(out);
	hdcptx_parm.mSeqNumM++;
	// special block...[used during early development, disable it anyway]
#if 0
	{
		// verify M', compute M first
		memset(mM,0x0,HDCP_M_PRIME_SIZE);
		UINT8 *input = (UINT8 *)malloc(2*mk+HDCP_SEQ_NUM_M_SIZE);

		memcpy(input,mPStreamIDType,(2*mk));
		memcpy(input+(2*mk),mSeqNumMBuf,HDCP_SEQ_NUM_M_SIZE);

		// prepare key - SHA256(kd)
		H2Sha256Ctx_t c;
		UINT8 key[SHA256_DIGEST_SIZE];

		memset(key, 0x00, SHA256_DIGEST_SIZE);

		crypto_sha256Init(&c);
		crypto_sha256Update(&c, mKD, HDCP_KD_SIZE);
		crypto_sha256Final(&c, key);

		hmacsha256(key,SHA256_DIGEST_SIZE,input,(2*mk+HDCP_SEQ_NUM_M_SIZE),mM);
		free(input);
	}
#endif
	return err_code;
}

HDCP_ERR read_ake_send_cert(UINT32 time_out, UINT32 *time_consumed)
{
	INT32 read_size=0;
	HDCP_ERR err_code;
	memset(&hdcptx_parm.ake_send_cert_msg,0x0,sizeof(AKE_Send_Cert_Msg));
	err_code = hdcp_safe_read_with_timeout(
			(INT8*)(&hdcptx_parm.ake_send_cert_msg),
			sizeof(AKE_Send_Cert_Msg),
			&read_size,
			time_out,
			time_consumed);
#if(DUMP_IN_DATA)
		memset(msg_buf,0x0,MSG_BUF_SIZE);
		snprintf(msg_buf,MSG_BUF_SIZE,"[<] Read AKE_Send_Cert");
		dump_buffer((INT8*)(&hdcptx_parm.ake_send_cert_msg),sizeof(AKE_Send_Cert_Msg),msg_buf);
#endif
        // 1A-08
        if(err_code == HDCP_ERR_TIMEOUT)
            err_code = HDCP_ERR_READ_CERT_TIMEOUT_NEED_REAUTH;

		return err_code;
}

HDCP_ERR read_ake_send_h_prime(UINT32 time_out, UINT32 *time_consumed)
{
	INT32 read_size=0;
	HDCP_ERR err_code;
	memset((INT8*)(&hdcptx_parm.ake_send_h_prime_msg),0x0,sizeof(AKE_Send_H_Prime_Msg));
	err_code = hdcp_safe_read_with_timeout(
			(INT8*)(&hdcptx_parm.ake_send_h_prime_msg),
			sizeof(AKE_Send_H_Prime_Msg),
			&read_size,
			time_out,
			time_consumed);
#if(DUMP_IN_DATA)
		memset(msg_buf,0x0,MSG_BUF_SIZE);
		snprintf(msg_buf,MSG_BUF_SIZE,"[<] Read AKE_Send_H_prime:");
		dump_buffer((INT8*)(&hdcptx_parm.ake_send_h_prime_msg),sizeof(AKE_Send_H_Prime_Msg),msg_buf);
#endif
    // 1A-11
    if(err_code == HDCP_ERR_TIMEOUT)
        err_code = HDCP_ERR_READ_H_PRIME_TIMEOUT_NEED_REAUTH;
	return err_code;
}

HDCP_ERR read_ake_send_pairing_info(UINT32 time_out, UINT32 *time_consumed)
{
	INT32 read_size=0;
	HDCP_ERR err_code;
	memset((INT8*)(&hdcptx_parm.ake_send_pairing_info_msg),0x0,sizeof(AKE_Send_Pairing_Info_Msg));
	err_code = hdcp_safe_read_with_timeout(
			(INT8*)(&hdcptx_parm.ake_send_pairing_info_msg),
			sizeof(AKE_Send_Pairing_Info_Msg),
			&read_size,
			time_out,
			time_consumed);

#if(DUMP_IN_DATA)
		memset(msg_buf,0x0,MSG_BUF_SIZE);
		snprintf(msg_buf,MSG_BUF_SIZE,"[<] Read AKE_Send_PairingInfo");
		dump_buffer((INT8*)(&hdcptx_parm.ake_send_pairing_info_msg),sizeof(AKE_Send_Pairing_Info_Msg),msg_buf);
#endif
    // 1A-12
    if(err_code == HDCP_ERR_TIMEOUT)
        err_code = HDCP_ERR_READ_PAIRING_INFO_TIMEOUT_NEED_REAUTH;
	return err_code;
}

HDCP_ERR read_lc_send_l_prime_no_precompute(UINT32 time_out, UINT32 *time_consumed)
{
	INT32 read_size=0;
	HDCP_ERR err_code;
	memset((INT8*)(&hdcptx_parm.lc_send_l_prime_no_precompute_msg),0x0,sizeof(Lc_Send_L_Prime_No_Precompute_Msg));
	err_code = hdcp_safe_read_with_timeout(
			(INT8*)(&hdcptx_parm.lc_send_l_prime_no_precompute_msg),
			sizeof(Lc_Send_L_Prime_No_Precompute_Msg),
			&read_size,
			time_out,
			time_consumed);

#if(DUMP_IN_DATA)
		memset(msg_buf,0x0,MSG_BUF_SIZE);
		snprintf(msg_buf,MSG_BUF_SIZE,"[<] Read AKE_Send_L_Prime");
		dump_buffer((INT8*)(&hdcptx_parm.lc_send_l_prime_no_precompute_msg),sizeof(Lc_Send_L_Prime_No_Precompute_Msg),msg_buf);
#endif
	return err_code;
}

HDCP_ERR read_repeater_auth_receiverId_list(UINT32 time_out, UINT32 *time_consumed)
{
	//LOG("[HDCP] %s\n",__func__);
	

	struct timeval tv_start = {0, 0};
	struct timeval tv_end = {0, 0};
	INT8 reauth=0;
	INT8 ready=0;
	INT8 ready_record=0;
	INT32 msg_size=0;
	HDCP_RST rx_rst ;
	INT32 time_used;
	UINT8 *buf;
	INT32 read_rst;
	HDCP_ERR err_code;
	
	if(hdcptx_parm.read_rx_status_fun==NULL)
		return HDCP_ERR_READ_RXSTATUS_ERROR;
	//gettimeofday(&tv_start, NULL);
	// polling rx status READY bit,
	// Spec page:29, Transition A6:A7, goes to next state if READY bit is set.
	rx_rst = hdcptx_parm.read_rx_status_fun(&reauth,&ready,&msg_size);
	while(rx_rst!=HDCP_TRUE || ready_record==0 || msg_size==0)
	{
		rx_rst = hdcptx_parm.read_rx_status_fun(&reauth,&ready,&msg_size);
		// save ready bit to temp
		if(rx_rst==HDCP_TRUE && ready_record==0 && ready==1)
		{
			LOG("[HDCP] got ready bit, save to record.");
			ready_record=ready;
		}

		//gettimeofday(&tv_end, NULL);
		time_used = hdcp_get_duration(&tv_start,&tv_end);

		// break condition, 3 second time window.
		if(time_used>time_out)
		{
			*time_consumed = time_used;
			LOG("[HDCP] Read receiverId list timeout.\n");
			return HDCP_ERR_REPEATER_SEND_RECEIVERID_LIST_TIMEOUT_NEED_REAUTH;
		}
		//usleep(10000);
	}
	LOG("[HDCP] RxInfo -> reauth: %d ready: %d message_size: %d\n",reauth,ready,msg_size);
	if(ready_record>0 && reauth==0 && msg_size>0)
	{
		// receiver ID list is ready
		buf=(UINT8*)kcalloc(msg_size, sizeof(unsigned char), GFP_KERNEL);
		read_rst=0;
		err_code = hdcp_safe_read((INT8 *)buf,msg_size,&read_rst);
		if(IS_SUCCESS(err_code))
		{
#if(DUMP_IN_DATA)
			memset(msg_buf,0x0,MSG_BUF_SIZE);
			snprintf(msg_buf,MSG_BUF_SIZE,"[<] Read RepeaterAuth_Send_ReceiverID_List");
			dump_buffer((INT8*)buf,msg_size,msg_buf);
#endif
			// process message
			err_code = hdcp_process_receiverId_list(buf,msg_size);
		}
		kfree(buf);
		return err_code;
	}
	else
	{
		// indicate that rx does not provide correct RxStatus value.
		return HDCP_ERR_READ_RECEIVERID_LIST_ERROR_NEED_REAUTH;
	}
}

HDCP_ERR read_repeater_auth_content_stream_ready(UINT32 time_out, UINT32 *time_consumed)
{
	
	UINT32 time_used=0;
	INT32 read_rst=0;
	HDCP_ERR err_code;
	H2Sha256Ctx_t c;
	UINT8 key[SHA256_DIGEST_HDCP2_SIZE];
	UINT8 *input;
	memset(&hdcptx_parm.repeaterAuth_stream_ready_msg,0x0,sizeof(RepeaterAuth_Stream_Ready_Msg));
	 err_code = hdcp_safe_read_with_timeout(
			(INT8 *)(&hdcptx_parm.repeaterAuth_stream_ready_msg),
			sizeof(RepeaterAuth_Stream_Ready_Msg),
			&read_rst,
			CONTENT_STREAM_MANAGEMENT_TIMEOUT,
			&time_used);
	// timeout convert
    if(err_code == HDCP_ERR_TIMEOUT)
    {
        err_code = HDCP_ERR_READ_STREAM_READY_TIMEOUT_NEED_REAUTH;
    }
    
	// process message
	if(IS_SUCCESS(err_code))
	{
		// verify M', compute M first
		memset(hdcptx_parm.mM,0x0,HDCP_M_PRIME_SIZE);
		input = (UINT8 *)kcalloc(2*hdcptx_parm.mk+HDCP_SEQ_NUM_M_SIZE, sizeof(unsigned char), GFP_KERNEL);

		memcpy(input,hdcptx_parm.mPStreamIDType,(2*hdcptx_parm.mk));
		memcpy(input+(2*hdcptx_parm.mk),hdcptx_parm.mSeqNumMBuf,HDCP_SEQ_NUM_M_SIZE);

		// prepare key - SHA256(kd)
		

		memset(key, 0x00, SHA256_DIGEST_HDCP2_SIZE);

		crypto_sha256Init(&c);
		crypto_sha256Update(&c, hdcptx_parm.mKD, HDCP_KD_SIZE);
		crypto_sha256Final(&c, key);

		hmacsha256(key,SHA256_DIGEST_HDCP2_SIZE,input,(2*hdcptx_parm.mk+HDCP_SEQ_NUM_M_SIZE),hdcptx_parm.mM);
		kfree(input);

        // compare M and M'
        if(memcmp(hdcptx_parm.mM,hdcptx_parm.repeaterAuth_stream_ready_msg.m_prime,HDCP_M_PRIME_SIZE)!=0)
        {
        	LOG("[HDCP] M compare error.\n");
            err_code = HDCP_ERR_M_COMPARE_ERROR;
        }
        else
        {
        	LOG("[HDCP] M compare ok.\n");
        }
	}
	return err_code;
}

HDCP_ERR hdcp_process_receiverId_list(UINT8 *buf, INT32 size)
{
	int i;
	int compute_msg_size = 1+HDCP_RXINFO_SIZE;
	INT32 seqNumV;
	INT32 receiverIDSize;
	INT32 input_size;
	UINT8 *input;
	UINT8 *pt;
	H2status rc;
	//LOG("[HDCP] %s\n",__func__);
	memset(&hdcptx_parm.repeaterAuth_send_receiverId_msg_h,0x0,sizeof(RepeaterAuth_Send_ReceiverID_List_Msg_Heading));
	memset(&hdcptx_parm.repeaterAuth_send_receiverId_msg_p,0x0,sizeof(RepeaterAuth_Send_ReceiverID_List_Msg_Payload));

	// set RepeaterAuth_Send_ReceiverID_List (Header part)
	memcpy(&hdcptx_parm.repeaterAuth_send_receiverId_msg_h,buf,sizeof(RepeaterAuth_Send_ReceiverID_List_Msg_Heading));
	// check message ID
	if(hdcptx_parm.repeaterAuth_send_receiverId_msg_h.id != REPEATER_AUTH_SEND_RECEIVERID_LIST)
		return HDCP_ERR_MSG_ID_ERROR;

	// analysis RxInfo
	memcpy(hdcptx_parm.mRxInfo,hdcptx_parm.repeaterAuth_send_receiverId_msg_h.rxInfo,HDCP_RXINFO_SIZE);
	// NOTE: mRepeaterRxInfo (including ReceiverId List) would be cleared every time when RepeaterAuth_Send_ReceiverId_List is received.
	memset(&hdcptx_parm.mRepeaterRxInfo,0x0,sizeof(RepeaterRxInfo));
	hdcptx_parm.mRepeaterRxInfo.depth=(hdcptx_parm.mRxInfo[0]>>1)&0x7;
	hdcptx_parm.mRepeaterRxInfo.device_count=((hdcptx_parm.mRxInfo[0]&0x1)<<4)|((hdcptx_parm.mRxInfo[1]>>4)&0xff);
	hdcptx_parm.mRepeaterRxInfo.max_devs_exceeded=(hdcptx_parm.mRxInfo[1]>>3)&0x1;
	hdcptx_parm.mRepeaterRxInfo.max_cascade_exceeded=(hdcptx_parm.mRxInfo[1]>>2)&0x1;
	hdcptx_parm.mRepeaterRxInfo.hdcp2_0_repeater_downstream=(hdcptx_parm.mRxInfo[1]>>1)&0x1;
	hdcptx_parm.mRepeaterRxInfo.hdcp1_device_downstream=(hdcptx_parm.mRxInfo[1]>>0)&0x1;

	// check if msg_size match RxInfo:
	
	// if max cascade or max devices exceeded, notify Tx to reauth HDCP nego.
	if(hdcptx_parm.mRepeaterRxInfo.max_cascade_exceeded!=1 &&hdcptx_parm.mRepeaterRxInfo.max_devs_exceeded!=1)
	{
		compute_msg_size=compute_msg_size+HDCP_SEQ_NUM_V_SIZE+HDCP_V_SIZE;
		compute_msg_size=compute_msg_size+(hdcptx_parm.mRepeaterRxInfo.device_count*HDCP_RECEIVER_ID_SIZE);
	}
	else
	{
		return HDCP_ERR_DOWNSTREAM_EXCEED_ERROR_NEED_REAUTH;
	}

	LOG("[HDCP] check msg size= %d size= %d\n",compute_msg_size,size);
	if(compute_msg_size!=size)
	{
		return HDCP_ERR_RECEIVERID_LIST_MSG_SIZE_ERROR_NEED_REAUTH;
	}

	// set RepeaterAuth_Send_ReceiverID_List (Payload part)
	memcpy(&hdcptx_parm.repeaterAuth_send_receiverId_msg_p,
			buf+(sizeof(RepeaterAuth_Send_ReceiverID_List_Msg_Heading)),
			sizeof(RepeaterAuth_Send_ReceiverID_List_Msg_Payload));

	// check seq_num_v over-roll case (big-endian conversion, not sure.)
	seqNumV = hdcptx_parm.repeaterAuth_send_receiverId_msg_p.seq_num_V[0]<<16 |
					hdcptx_parm.repeaterAuth_send_receiverId_msg_p.seq_num_V[1]<< 8 |
					hdcptx_parm.repeaterAuth_send_receiverId_msg_p.seq_num_V[2];

	LOG("\033[0;31;31m[HDCP] seq_num_v: %d mSeqNumV: %d\033[m\n",seqNumV,hdcptx_parm.mSeqNumV);

    // 1B-06, seq_num_v should be 0 after a new AKE_Init is sent
    if(hdcptx_parm.mSeqNumV==-1)
    {
        if(seqNumV!=0)
            return HDCP_ERR_INCORRECT_SEQ_NUM_V_NEED_REAUTH;
    }
    else if(seqNumV<hdcptx_parm.mSeqNumV)
	{
		LOG("[HDCP] seq_num_v roll-over, reauth entire HDCP.\n");
		return HDCP_ERR_SEQ_NUM_V_ROLL_OVER_ERROR_NEED_REAUTH;
	}

	// save seq_num_v
	hdcptx_parm.mSeqNumV=seqNumV;

	// Compute V = HMAC-SHA256(ReceiverID list || RxInfo || seq_num_v, kd);
	// prepare input buffer to calculate V
	LOG("[HDCP] compute V\n");
	 receiverIDSize=hdcptx_parm.mRepeaterRxInfo.device_count*HDCP_RECEIVER_ID_SIZE;
	 input_size=receiverIDSize+HDCP_RXINFO_SIZE+HDCP_SEQ_NUM_V_SIZE;
	 input=(UINT8 *)kcalloc(input_size, sizeof(unsigned char), GFP_KERNEL);
	 pt=input;

	memcpy(pt, buf+(1+HDCP_RXINFO_SIZE+HDCP_SEQ_NUM_V_SIZE+HDCP_V_SIZE),receiverIDSize);
	pt=pt+receiverIDSize;
	memcpy(pt,hdcptx_parm.mRxInfo,HDCP_RXINFO_SIZE);
	pt=pt+HDCP_RXINFO_SIZE;
	memcpy(pt,hdcptx_parm.repeaterAuth_send_receiverId_msg_p.seq_num_V,HDCP_SEQ_NUM_V_SIZE);

	memset(hdcptx_parm.mV,0x0,HDCP_V_OUT_SIZE);
	rc = hmacsha256(
				hdcptx_parm.mKD,
				HDCP_KD_SIZE,
				input,
				input_size,
				hdcptx_parm.mV);

	// free allocated buffer.
	kfree(input);
	// compare with V' provided by Repeater side.
	memcpy(hdcptx_parm.mVPrime,hdcptx_parm.repeaterAuth_send_receiverId_msg_p.v_prime,HDCP_V_SIZE);
	if(memcmp(hdcptx_parm.mV,hdcptx_parm.mVPrime,HDCP_V_SIZE)!=0)
		return HDCP_ERR_V_COMPARE_ERROR_NEED_REAUTH;

	LOG("[HDCP] check V correctness OK\n");
	// save Receivers' ID list to mRepeaterRxInfo.
	pt=buf+(1+HDCP_RXINFO_SIZE+HDCP_SEQ_NUM_V_SIZE+HDCP_V_SIZE);
	for(i=0;i<hdcptx_parm.mRepeaterRxInfo.device_count;i++)
	{
		memcpy(hdcptx_parm.mRepeaterRxInfo.downStreamReceivers[i].receiverId,pt,HDCP_RECEIVER_ID_SIZE);
		pt=pt+HDCP_RECEIVER_ID_SIZE;
	}
	// switch to next state.
	hdcptx_parm.mState = HDCP_STATE_REPEATER_AUTH_SEND_ACK;
	return HDCP_ERR_SUCCESS;
}

HDCP_ERR start_hdcp_nego(void)
{
	LOG("[HDCP] %s\n",__func__);
	// start send first command AKE_Init
	hdcptx_parm.mState=HDCP_STATE_SEND_AKE_INIT;
	hdcptx_parm.mErrCode = HDCP_ERR_UNDEFINED;
	while(1)
	{
hdcp_send:
        if(hdcptx_parm.mStopHDCPNego==1)
            break;
            
		// do send message
		hdcptx_parm.mErrCode = hdcp_send_msg();

		if( hdcptx_parm.mErrCode!=HDCP_ERR_SUCCESS &&
			hdcptx_parm.mErrCode!=HDCP_ERR_NEGO_COMPLETE &&
			hdcptx_parm.mErrCode!=HDCP_ERR_NEGO_COMPLETE_WITH_REPEATER)
		{
			LOG("[HDCP] Error in send msg, err_code: \033[0;31;31m%s\033[m\n",hdcp_err_str[hdcptx_parm.mErrCode]);
		}

        // COMMENT: should we do this in a separated thread? or in rx polling loop?
		// Note that a tx device could decide when to send content stream management command.
		// in this implementation, it sends only once.

		// handle RepeaterAuth_Content_Stream_Management message
		// cost at least 500ms, should be okay.
		if(hdcptx_parm.mErrCode==HDCP_ERR_NEGO_COMPLETE_WITH_REPEATER)
		{
			int repeaterContentStreamRetry = 5;
send_content_stream_manage:
			// try to deliver Content Stream Management message
			LOG("\033[0;33;33m[HDCP][>] Send_Repeater_Auth_Content_Stream_Manage\033[m\n");
			hdcptx_parm.mErrCode = send_repeater_auth_content_stream_manage();

			if(IS_SUCCESS(hdcptx_parm.mErrCode))
			{
				// read ack message
				UINT32 time_used=0;
				LOG("\033[0;33;33m[HDCP][<] read_Repeater_Auth_Content_Stream_Ready\033[m\n");
				hdcptx_parm.mErrCode = read_repeater_auth_content_stream_ready(
                    REPEATER_SEND_STREAM_READY_TIMEOUT,
                    &time_used);

				if(!IS_SUCCESS(hdcptx_parm.mErrCode))
				{
					repeaterContentStreamRetry--;
					if(repeaterContentStreamRetry>0)
					{
						goto send_content_stream_manage;
					}
				}
				else
				{
					// if success, enter polling mode...
					hdcptx_parm.mErrCode = HDCP_ERR_NEGO_COMPLETE_WITH_REPEATER;
				}
			}
			else
			{
				// write failed
				repeaterContentStreamRetry--;
				if(repeaterContentStreamRetry>0)
				{
					goto send_content_stream_manage;
				}
			}
		}

		// Refer to spec State A5. no matter a connected sink is a Receiver or a Repeater,
		// a HDCP Transmitter should always polling RxStatus less than every one second
		// after State A5.
		if(hdcptx_parm.mErrCode==HDCP_ERR_NEGO_COMPLETE || hdcptx_parm.mErrCode == HDCP_ERR_NEGO_COMPLETE_WITH_REPEATER)
		{
			hdcptx_parm.mState=HDCP_STATE_POLLING_RXSTATUS;
			//LOG("HDCP 2.2 nego complete rst= \033[0;32;32m %s \033[m, state= \033[0;32;32m %s \033[m\n",hdcp_err_str[hdcptx_parm.mErrCode],hdcp_state_str[hdcptx_parm.mState]);
			// enter a endless loop, caller could set mKeepPollingRxStatus to 0 to exit polling loop
			hdcptx_parm.mKeepPollingRxStatus=1;
			polling_rx_status();
			if(hdcptx_parm.mState==HDCP_STATE_SEND_AKE_INIT)
		    {
				// reauth-req occurred, or verify ReceiverId list fail.
				LOG("[HDCP] break RxStatus polling loop by get Repeater reauth-req.\n");
				hdcptx_parm.mErrCode = HDCP_ERR_UNDEFINED;
				goto hdcp_send;
			}
			else if(hdcptx_parm.mState==HDCP_STATE_REPEATER_AUTH_SEND_ACK)
			{
				// READY & Verify ReceiverId list ok
				LOG("[HDCP] break RxStatus polling loop by get Repeater READY bit.\n");
				hdcptx_parm.mErrCode = HDCP_ERR_UNDEFINED;
				goto hdcp_send;
			}
			else
			{
				LOG("[HDCP] break RxStatus polling loop by outside event or other internal error.\n");
			}
			break;
		}

		// do read message if everythis is okay
		if(IS_SUCCESS(hdcptx_parm.mErrCode))
		{
			hdcptx_parm.mErrCode = hdcp_read_msg();
		}

		// error with max retry count.
        if(IS_NEED_REAUTH_WITH_MAX_RETRY_COUNT(hdcptx_parm.mErrCode))
        {
            hdcptx_parm.mReauthRetryCount++;
            if(hdcptx_parm.mReauthRetryCount<MAX_REAUTH_RETRY_COUNT)
            {
                LOG("[HDCP] re-auth internally, err_code: \033[0;35;35m %s \033[m retry count: %d\n",
                		hdcp_err_str[hdcptx_parm.mErrCode],
                		hdcptx_parm.mReauthRetryCount);

    			hdcptx_parm.mState = HDCP_STATE_SEND_AKE_INIT;
    			hdcptx_parm.mErrCode = HDCP_ERR_UNDEFINED;
    			init();
    			goto hdcp_send;
            }
            else
            {
                break;
            }
        }

		// check err_code and re-auth HDCP
		if(IS_NEED_REAUTH(hdcptx_parm.mErrCode))
		{
            init();
            LOG("[HDCP] re-auth internally, err_code: \033[0;35;35m %s \033[m\n",hdcp_err_str[hdcptx_parm.mErrCode]);

			hdcptx_parm.mState = HDCP_STATE_SEND_AKE_INIT;
			hdcptx_parm.mErrCode = HDCP_ERR_UNDEFINED;
			
			goto hdcp_send;
		}

		// not success, not LC retry, not catch by the re-auth block above.
		if(hdcptx_parm.mErrCode!=HDCP_ERR_SUCCESS && hdcptx_parm.mErrCode!=HDCP_ERR_RESEND_LC_INIT)
		{
			LOG("[HDCP] Error in read msg, err_code: \033[0;31;31m %s \033[m\n",hdcp_err_str[hdcptx_parm.mErrCode]);
			break;
		}
	}

	LOG("[HDCP] stop hdcp nego loop, err_code: \033[0;31;31m %s \033[m\n",hdcp_err_str[hdcptx_parm.mErrCode]);
	return hdcptx_parm.mErrCode;
}
// TODO
HDCP_RST check_smr(void)
{
	return HDCP_TRUE;
}

static DIGIT_T s[3072/32]={0};	// k = length
static DIGIT_T n[(3072/32)]={0};
static DIGIT_T e[(3072/32)]={0};
static DIGIT_T m[(3072/32)]={0};
static UINT8 EM_prime[(3072/8)]={0};
HDCP_RST check_LLC_signature(void)
{
	int i;
	// follow RSASSA-PKCS-v1_5-Verify
	
	UINT8 t_heading[]={0x30, 0x31, 0x30, 0x0d, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01,
							0x65, 0x03, 0x04, 0x02, 0x01, 0x05, 0x00, 0x04, 0x20};
	INT32 ps_length = ((3072/8)-3-sizeof(t_heading)-32);	// t_heading length:19
	UINT8 *pt;
	H2Sha256Ctx_t c;
	UINT8 in[HDCP_LLC_SIGNATURE_M_SIZE]={0};
	UINT8 out[SHA256_DIGEST_HDCP2_SIZE];
	
	// s = OS2IP(S), S is signature to be verified.
	mpConvFromOctets(s,(3072/32),hdcptx_parm.mLLCSignature,HDCP_RECEIVER_LLC_SIGNATURE_SIZE);
	// m = RSAVP1((n,e),s) -> m = s^e mod n
	
    
    // - prepare n and e [test v.s production]
#if 1//(USE_TEST_VECTOR)
   	mpConvFromOctets(n,(3072/32),tx_modulus_n_test,HDCP_TX_MODULUS_N_SIZE);
	mpConvFromOctets(e,(3072/32),tx_public_exponent_e_test,HDCP_TX_PUBLIC_EXPONENT_E_SIZE);
#else
	mpConvFromOctets(n,(3072/32),tx_modulus_n_production,HDCP_TX_MODULUS_N_SIZE);
	mpConvFromOctets(e,(3072/32),tx_public_exponent_e_production,HDCP_TX_PUBLIC_EXPONENT_E_SIZE);
#endif
	mpModExp(m,s,e,n,(3072/32));
	// EM' = I2OSP(m,k)
	mpConvToOctets(m,(3072/32),EM_prime,(3072/8));

	// check EM_prime (octets string) heading characters
	// EM' = 0x00 || 0x01 || PS || 0x00 || T
	if(EM_prime[0]!=0x00 || EM_prime[1]!=0x01)
	{
		LOG("EM' heading character error %.2x %.2x\n",EM_prime[0]&0xff,EM_prime[1]&0xff);
		return HDCP_FALSE;
	}
	pt=&EM_prime[2];
	// check ps
	for(i=0;i<ps_length;i++)
	{
		if(*pt!=0xff)
		{
			LOG("PS error\n");
			return HDCP_FALSE;
		}
		pt++;
	}
	// check 0x0
	if(*pt!=0x0)
	{
		LOG("0x0 error\n");
		return HDCP_FALSE;
	}
	pt++;

	// compare T heading, SHA-256 pattern
	for(i=0;i<sizeof(t_heading);i++)
	{
		if(*pt!=t_heading[i])
		{
			LOG("T heading error\n");
			return HDCP_FALSE;
		}
		pt++;
	}
	// compare public cert and other fields.
	memset(out, 0x00, SHA256_DIGEST_HDCP2_SIZE);
	memcpy(in,hdcptx_parm.ake_send_cert_msg.cert_rx,HDCP_LLC_SIGNATURE_M_SIZE);

	crypto_sha256Init(&c);
	crypto_sha256Update(&c, in, 138);
	crypto_sha256Final(&c, out);

	for(i=0;i<SHA256_DIGEST_HDCP2_SIZE;i++)
	{
		if(*pt!=out[i])
		{
			LOG("M error\n");
			return HDCP_FALSE;
		}
		pt++;
	}

	return HDCP_TRUE;
}

void generate_random_number(UINT8 *dst, INT32 size, const char *msg)
{
	int i;
	INT32 size_int = size/4;
	INT32 *tmp;
	if(size % 4 != 0)
	{
		LOG("WARNING - generate random number size not word aligned\n");
	}

	
	tmp = (INT32 *)kcalloc(size_int*4, sizeof(unsigned char), GFP_KERNEL);
	for(i=0;i<size_int;i++)
	{
		tmp[i]=crypto_random32();
	}
	memcpy(dst,tmp,size_int*4);

	kfree(tmp);
}

void hdcp_save_pairing_info(void)
{
	// NOTE: according to spec HDCP 2.2 page 18.
	// if Rx version is 2.0 or 2.1, Tx must not store pairing info of the receiver.
	if(hdcptx_parm.mRxVersion==2)
	{
		if(hdcptx_parm.store_rx_info_fun!=NULL)
		{
			// generate m
			UINT8 m[HDCP_M_SIZE]={0};
			memcpy(m,hdcptx_parm.mRtx,HDCP_RTX_SIZE);
			memcpy(m+HDCP_RTX_SIZE,hdcptx_parm.mRrx,HDCP_RRX_SIZE);

			hdcptx_parm.store_rx_info_fun(
					hdcptx_parm.mReceiverID,HDCP_RECEIVER_ID_SIZE,
					hdcptx_parm.mKm,HDCP_KM_SIZE,
					hdcptx_parm.mEKhKm,HDCP_EKH_KM_SIZE,
					m,HDCP_M_SIZE);
		}
	}
}

void stop_hdcp_polling_rx_status(void)
{
	hdcptx_parm.mKeepPollingRxStatus=0;
}

void  stop_hdcp_nego(void)
{
    hdcptx_parm.mStopHDCPNego=1;
}

void polling_rx_status(void)
{
	INT8 ready;
	INT8 reauth;
	INT32 msg_size;
	HDCP_RST rst;
	LOG("[HDCP] start polling RxStatus.\n");
	// HDCP engine can not work correctly without rx_status read function
	if(hdcptx_parm.read_rx_status_fun==NULL)
		return;

	while(hdcptx_parm.mKeepPollingRxStatus>0)
	{
	    LOG("[HDCP] polling rx status\n");
		rst = hdcptx_parm.read_rx_status_fun(&reauth,&ready,&msg_size);
		// analysis read, reauth-req, and msg_size.
		if(rst==HDCP_TRUE)
		{
			// process READY bit
			if(ready==1)
			{
				// for safety, check msg_size and re-ask again.
				// polling msg_size
				INT32 retry_count=0;
				while(msg_size==0 && retry_count<50)
				{
					INT8 tempReauth;
					INT8 tempReady;
					rst = hdcptx_parm.read_rx_status_fun(&tempReauth,&tempReady,&msg_size);
					//usleep(10000);	// sleep 0.01 sec
					retry_count++;
				}

				LOG("[HDCP] receive READY bit and read msg_size:%d retry_count:%d\n",msg_size,retry_count);

				// only process READY if msg_size > 0
				if(msg_size>0)
				{
					// receiver ID list is ready
					UINT8 *buf=(UINT8*)kcalloc(msg_size, sizeof(unsigned char), GFP_KERNEL);
					INT32 read_rst=0;
					hdcptx_parm.mErrCode = hdcp_safe_read((INT8 *)buf,msg_size,&read_rst);
					if(IS_SUCCESS(hdcptx_parm.mErrCode))
					{
#if(DUMP_IN_DATA)
						memset(msg_buf,0x0,MSG_BUF_SIZE);
						snprintf(msg_buf,MSG_BUF_SIZE,"[<] Read RepeaterAuth_Send_ReceiverID_List");
						dump_buffer((INT8*)buf,msg_size,msg_buf);
#endif
						// process message
						hdcptx_parm.mErrCode = hdcp_process_receiverId_list(buf,msg_size);
					}
					kfree(buf);
				}
				else
				{
					hdcptx_parm.mErrCode=HDCP_ERR_READ_RECEIVERID_LIST_ERROR_NEED_REAUTH;
				}

				LOG("[HDCP] polling RxStatus, process READY bit mErrCode: %s\n",hdcp_err_str[hdcptx_parm.mErrCode]);
				//LOG("[HDCP] polling RxStatus, process READY bit mState  : %s\n",hdcp_state_str[hdcptx_parm.mState]);

				if(IS_NEED_REAUTH(hdcptx_parm.mErrCode))
				{
					// change state back to AKE_Init again
					hdcptx_parm.mState=HDCP_STATE_SEND_AKE_INIT;
					// reset HDCP control variables
					init();
					// left polling loop
					hdcptx_parm.mKeepPollingRxStatus=-1;
				}
				break;
			}
			// process REAUTH-REQ bit
			else if(reauth==1)
			{
				// change state back to AKE_Init again
				hdcptx_parm.mState=HDCP_STATE_SEND_AKE_INIT;
				// reset HDCP control variables
				init();
				// left polling loop
				hdcptx_parm.mKeepPollingRxStatus=-1;

				break;
			}
		}
		//usleep(500000); // sleep 0.5 sec
	}
	//LOG("\033[0;31;31m[HDCP] leave RxStatus Polling routine, mState=%s\033[m\n",hdcp_state_str[hdcptx_parm.mState]);
}
