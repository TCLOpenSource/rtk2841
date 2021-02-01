#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_session.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_messages.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_interface.h>
#include <tvscalercontrol/hdcp2_2/crypto.h>

#ifdef TEST_HDCP2_2_RX_DRIVER

#ifdef DEBUG_H2_SESSION
#define LOCALDBG ENABLE
#else
#define LOCALDBG DISABLE
#endif
static h2State gState = H2_STATE_INIT;
static enum {
	PAIRING_INIT, PAIRING_SEND_HPRIME, PAIRING_SEND_PAIRING_INFO
} gPairingState = PAIRING_INIT;
static H2bool gbNoStoredEkm;

/**
 * Functions to process incoming messages
 */

/**
 * Return code:
 * <0 = error
 *  0 = success
 *  1 = success, outgoing message available in *message.
 *
 *  Error codes:
 *  -1 = generic error
 *  -2 = Not enough room in *message for the outgoing message.
 *  -3 = Message received, but gState is not correct for this message.
 *  -4 = Decryption failed.
 */

#define STATUS_ERROR_DECRYPTION_FAILED -4
#define STATUS_ERROR_BAD_STATE -3
#define STATUS_ERROR_OUTGOING_MSG_TOO_LARGE -2
#define STATUS_OK 0

/**
 * A message is waiting to be sent as a reply
 */
#define STATUS_OK_PENDING_MSG 1

/**
 * On Process AKE Init:
 * Set state to B1 ( Received AKE_INIT )
 * Copy RTX
 * Send AKE_SendCert message
 *
 * Any time AKE Init is received, the state machine is reset, so it
 * can be called from any state.
 *
 */
static int processAkeInit(unsigned char *message, unsigned int length)
{
	int rc = -1;

   /**
    * These two are static to keep them off the stack.
    */
	static H2_AKEInitPayLoad payload;
	static H2_AKESendCertPayLoad sendPayload;
	do {
      /** Zero out session values */
		hdcp2_Rx_reset();
      /** Unpack AKE Init message */
		if (NULL == message) {
			rc = -1;
			break;
		}
		if (h2MsgAkeInitUnpack(message, length, &payload) != 0) {
			H2DBGLOG((LOCALDBG, "Error unpacking message!\r\n"));
			rc = -1;
			break;
		}

      /** Copy RTX value */
		hdcp2_Rx_Setrtx(payload.rTx);

#ifndef HDCP2_2_WIFI
		hdcp2_Rx_SetTxcaps(message + 1 + RTX_SIZE);

#endif	/*  */
#if 0
      /** Make sure there's room for the outgoing message */
		if (length < MAX_PACKED_MSG_SIZE) {
			H2DBGLOG((LOCALDBG, "No room for outgoing AKE Send Cert message!\r\n"));
			rc = STATUS_ERROR_OUTGOING_MSG_TOO_LARGE;
			break;
		}
#endif
#ifdef HDCP2_2_WIFI
      /** HDCP2 -> HDCP1 repeater */
		sendPayload.repeater = HDCP_REPEATER;
		H2DBGLOG((LOCALDBG, "Setting repeater bit to %d.\n", sendPayload.repeater));

      /** Copy Cert RX into the outgoing message */
		hdcp2_Rx_GetCertRx(sendPayload.Cert_rx, sizeof(sendPayload.Cert_rx));

      /** Pack the message for transmission */
		if (0 != h2MsgAkeSendCertPack(message, &length, &sendPayload)) {
			H2DBGLOG((LOCALDBG, "Error packing AKE_SEND_CERT\r\n"));
			rc = -1;
			break;
		}

#else
		hdcp2_Rx_GetCertRx(sendPayload.Cert_rx, sizeof(sendPayload.Cert_rx));
		hdcp2_Rx_GenrRx();
		hdcp2_Rx_GetrRx(sendPayload.rrx, sizeof(sendPayload.rrx));
		hdcp2_Rx_GenRxcaps();
		hdcp2_Rx_GetRxcaps(sendPayload.rxcaps, sizeof(sendPayload.rxcaps));

		 h2MsgAkeSendCertPack( message, &length, &sendPayload);
#if 0
		if (0 != h2MsgAkeSendCertPack(message, &length, &sendPayload)) {
			H2DBGLOG((LOCALDBG, "Error packing AKE_SEND_CERT\r\n"));
			rc = -1;
			break;
		}

#endif
#if 0				/*for test*/
		printk("testcertrx:\n");
		spu_print(sendPayload.Cert_rx, sizeof(sendPayload.Cert_rx));
		printk("testrrx:\n");
		spu_print(sendPayload.rrx, sizeof(sendPayload.rrx));
		printk("testrxcaps:\n");
		spu_print(sendPayload.rxcaps, sizeof(sendPayload.rxcaps));

#endif
#endif

      /** Signal that a message is waiting */
		rc = STATUS_OK_PENDING_MSG;

      /** Everything went okay, so update state */
		gState = H2_STATE_B1_AKE_INIT;
	} while (0);
	return rc;
}

/**
 * Process Ake No Stored Ekm message.
 *
 * This message is only valid in state B1.
 */
static int processAkeNoStoredEkm(unsigned char *message, unsigned int length)
{
	int rc = -1;
	H2status stat = H2_OK;
   unsigned char send_msg[H_SIZE + 1];

   /**
    * These two are static to keep them off the stack.
    */
	static H2_AKENoStoredEkmPayLoad payload;
   static H2_AKESendHprimePayLoad sendPayload;
	do {
		gbNoStoredEkm = 1;	/* Send Pairing info */

      /** Check state! */
#if 0
		if (gState != H2_STATE_B1_AKE_INIT) {
			rc = STATUS_ERROR_BAD_STATE;
			gState = H2_STATE_INIT;	/* Reset state on error */
			H2DBGLOG((LOCALDBG, "AKENOSTOREDEKM: BAD STATE\r\n"));
			break;
		}

#endif
      /** Unpack AKE No Stored Ekm message */
		 if (h2MsgAkeNoStoredEkmUnpack(message, length, &payload) != 0) {
			H2DBGLOG((LOCALDBG, "Error unpacking message!\r\n"));
			rc = -1;
			break;
		}

      /** Copy EKPubKm value */
		stat = hdcp2_Rx_SetEKpubKm(payload.EKpub_Km);
		if (stat != H2_OK) {
			H2DBGLOG((LOCALDBG, "Decryption of EKpubKm failed!\r\n"));
			rc = STATUS_ERROR_DECRYPTION_FAILED;
						     /** No pending message. Timeout will notify TX of an error */
			break;
		}

#if 0
      /** Generate RRX */
		hdcp2_GenrRx();

      /** Send rRx */
		hdcp2_GetrRx(sendPayload.rrx, sizeof(sendPayload.rrx));
		h2MsgAkeSendRrxPack(message, &length, &sendPayload);

      /** Set pairing state */
		gPairingState = PAIRING_SEND_HPRIME;

#endif
	hdcp2_Rx_GethPrime(sendPayload.Hprime, sizeof(sendPayload.Hprime));
	  h2MsgAkeSendHprimePack( send_msg, &length, &sendPayload );
		rc = STATUS_OK_PENDING_MSG;

      /** No state change */
	} while (0);
	return rc;
}

/**
 * Process Ake Stored Ekm message.
 *
 * This message is only valid in state B1.
 */
static int processAkeStoredEkm(unsigned char *message, unsigned int length)
{
	int rc = -1;
   unsigned char send_msg[H_SIZE + 1];
	static H2_AKEStoredEkmPayLoad payload;
   static H2_AKESendHprimePayLoad sendPayload;

	do {

#if 0
      /** Check state! */
		if (gState != H2_STATE_B1_AKE_INIT) {
			rc = STATUS_ERROR_BAD_STATE;
			H2DBGLOG((ENABLE, "Error: StoredEkm: Bad state\r\n"));
			gState = H2_STATE_INIT;	/* Reset state on error */
			break;
		}
		gbNoStoredEkm = 0;	/* Don't send pairing info */

#endif
      /** Unpack AKE Stored Ekm message */
		 if (h2MsgAkeStoredEKmUnpack(message, length, &payload) != 0) {
			H2DBGLOG((ENABLE, "Error unpacking message!\r\n"));
			rc = -1;
			break;
		}

      /** Copy EKhKm / m value */
		hdcp2_Rx_SetEKhKm(payload.EKh_Km, payload.m);

#if 0
      /** Make sure there's room for the outgoing message */
		if (length < AKE_MSG_SEND_RRX_SIZE) {
			H2DBGLOG((ENABLE, "No room for outgoing AKE Send RRX message!\r\n"));
			rc = STATUS_ERROR_OUTGOING_MSG_TOO_LARGE;
			break;
		}
#endif
#if 0
      /** Generate rRx */
		hdcp2_GenrRx();
		hdcp2_GetrRx(sendPayload.rrx, sizeof(sendPayload.rrx));

      /** Pack the message for transmission */
		    if (0 != h2MsgAkeSendRrxPack(message, &length, &sendPayload)) {
			rc = -1;
			H2DBGLOG((ENABLE, "Failed to PACK message!\r\n"));
			break;
		}

      /** Set pairing state */
		gPairingState = PAIRING_SEND_HPRIME;

#endif
	hdcp2_Rx_GethPrime(sendPayload.Hprime, sizeof(sendPayload.Hprime));
	h2MsgAkeSendHprimePack( send_msg, &length, &sendPayload );
      /** Signal that a message is waiting */
		rc = STATUS_OK_PENDING_MSG;

      /** No state change */
	} while (0);
	return rc;
}

static int processLcInit(unsigned char *message, unsigned int length)
{
	int rc = -1;
   unsigned char send_msg[L_SIZE + 1];
   /**
    * These two are static to keep them off the stack.
    */
	static H2_LCInitPayLoad payload;
	static H2_LCSendLprimePayLoad sendPayload;
	do {

      /** Check state! */
      /** TBD: If LC Init is received in B2 (for retries), continue */
#if 0
		if ((gState != H2_STATE_B1_AKE_INIT) && (gState != H2_STATE_B2_LC_INIT)) {
			H2DBGLOG((LOCALDBG, "Error: LcInit: Bad state %d (should be %d)\r\n",
				gState, H2_STATE_B1_AKE_INIT));
			rc = STATUS_ERROR_BAD_STATE;
			gState = H2_STATE_INIT;	/* Reset state on error */
			break;
		}

#endif

      /** Unpack Lc Init message */
		if (h2MsgLcInitUnpack(message, length, &payload) != 0) {
			H2DBGLOG((LOCALDBG, "Error unpacking message!\r\n"));
			rc = -1;
			break;
		}

      /** Copy rn value */
		hdcp2_Rx_Setrn(payload.rn);

#if 0
      /** Make sure there's room for the outgoing message */
		if (length < AKE_MSG_SEND_LPRIME_SIZE) {
			H2DBGLOG((LOCALDBG, "No room for outgoing SKE Send Lprime message!\r\n"));
			rc = STATUS_ERROR_OUTGOING_MSG_TOO_LARGE;
			break;
		}
#endif
      /** Copy Lprime into the outgoing message */
		hdcp2_Rx_GetlPrime(sendPayload.Lprime, sizeof(sendPayload.Lprime));
      h2MsgLcSendLprimePack( send_msg, &length, &sendPayload );
#if 0
      /** Pack the message for transmission */
		    if (0 != h2MsgLcSendLprimePack(message, &length, &sendPayload)) {
			H2DBGLOG((LOCALDBG, "Error packing Lprime\r\n"));
			rc = -1;
			break;
		}

#endif
      /** Signal that a message is waiting */
		rc = STATUS_OK_PENDING_MSG;

      /** State is B2 */
		gState = H2_STATE_B2_LC_INIT;
	} while (0);
	return rc;
}

#define HDCP_REPEATER 0
static int processSkeSendEks(unsigned char *message, unsigned int length)
{
	int rc = -1;
	static H2_SKESendEksPayLoad payload;
   /*static H2_RepeaterAuthSendRxIdList_PayLoad sendPayload = {0};
   static H2uint8 ksvs[RECEIVERID_SIZE*MAX_DEVICECOUNT];
   static unsigned int outgoingLength = 0;*/

	do {
      /** Check state! */
#if 0
		if (gState != H2_STATE_B2_LC_INIT) {
			H2DBGLOG((LOCALDBG, "SkeSendEks: Bad State\r\n"));
			rc = STATUS_ERROR_BAD_STATE;
			gState = H2_STATE_INIT;	/* Reset state on error */
			break;
		}

      /** Check for size of outgoing message */
		if (0 != h2MsgRepeaterAuthSendReceiverIdListPack(NULL, &outgoingLength, &sendPayload, ksvs)) {
			H2DBGLOG((LOCALDBG, "Error determing length of RX ID Message\r\n"));
			rc = -1;
			break;
		}
		if (length < outgoingLength) {
			H2DBGLOG((LOCALDBG, "No room for outgoing RX ID list message!\r\n"));
			rc = STATUS_ERROR_OUTGOING_MSG_TOO_LARGE;
			break;
		}

      /** Unpack Ske Send Eks message */
#endif
		if (h2MsgSkeSendEksUnpack(message, length, &payload) != 0) {
			H2DBGLOG((LOCALDBG, "Error unpacking message!\r\n"));
			rc = -1;
			break;
		}

      /** Transition to state B3 */
		gState = H2_STATE_B3_SKE_SEND_EKS;

      /** Copy EdKeyKs value */
		hdcp2_Rx_SetEdKeyKs(payload.Edkey_Ks);

      /** Copy riv */
		hdcp2_Rx_SetRiv(payload.riv);

		    /*
		     * Don't send KSV if we're not a repeater.
		     */
#if (HDCP_REPEATER == 1)
      H2uint8 DeviceCount;
      H2uint8 Depth;
      H2uint8 DepthExceeded;
      H2uint8 DevicesExceeded;

      hdcp2_Rx_GetKsvInfo( &DeviceCount, &Depth, &DevicesExceeded, &DepthExceeded, ksvs );

      H2DBGLOG((LOCALDBG, "DeviceCount: %d DepthExceeded: %d DevicesExceeded: %d\n",
         DeviceCount, DepthExceeded, DevicesExceeded ));

      if ( DeviceCount || DepthExceeded || DevicesExceeded )
      {

         hdcp2_Rx_GetKsvInfo( &sendPayload.deviceCount, &sendPayload.depth,
               &sendPayload.maxDevsExceeded, &sendPayload.maxCascadeExceeded ,
               (H2uint8 *)ksvs );

         /** Copy Vprime into the outgoing message */
         hdcp2_Rx_GetvPrime( sendPayload.VPrime, sizeof( sendPayload.VPrime ) );

         if ( 0 != h2MsgRepeaterAuthSendReceiverIdListPack( message, &length, &sendPayload, ksvs ))
         {
            H2DBGLOG(( LOCALDBG, "Error packing Rx Id list\r\n"));
            rc = -1;
            break;
         }


         /** Success, Send KSVs */
         rc = STATUS_OK_PENDING_MSG;
      }
      else
      {
         /**
          * Per INTEL call on August 10th, 2010, do not send message if
          * no KSVs are available
          */
         rc = STATUS_OK;
      }
#endif
      /** State is B4 */
		gState = H2_STATE_B4_AUTHENTICATED;
	} while (0);
	return rc;
}

h2State h2StateGet(void)
{
	return gState;
}

int h2MessagePoll(unsigned char *message, unsigned int length)
{
	int rc = 0;
	unsigned char send_msg[EKHKM_SIZE+1];
	H2DBGLOG((LOCALDBG, "POLL: State is %d\n", gPairingState));
	gPairingState = PAIRING_SEND_PAIRING_INFO;
	switch (gPairingState) {
	case PAIRING_INIT:
		break;
	case PAIRING_SEND_HPRIME:
	{
		static H2_AKESendHprimePayLoad sendPayload;
	    /** Make sure there's room for the outgoing message */
		if (length < AKE_MSG_SEND_HPRIME_SIZE) {
			H2DBGLOG((LOCALDBG, "No room for outgoing AKE Send Hprime message!\r\n"));
			rc = STATUS_ERROR_OUTGOING_MSG_TOO_LARGE;
			break;
		}

	    /** Copy Hprime into the outgoing message */
		hdcp2_Rx_GethPrime(sendPayload.Hprime, sizeof(sendPayload.Hprime));

	    /** Pack the message for transmission */
		 if (0 != h2MsgAkeSendHprimePack(message, &length, &sendPayload)) {
			H2DBGLOG((LOCALDBG, "AKE Send Hprime pack failed!\r\n"));
			rc = -1;
			break;
		}

	    /** Signal that a message is waiting */
		rc = STATUS_OK_PENDING_MSG;
		gPairingState = (gbNoStoredEkm ? PAIRING_SEND_PAIRING_INFO : PAIRING_INIT);
		H2DBGLOG((LOCALDBG, "Newstate: %d\r\n", gPairingState));
	}
		break;
	case PAIRING_SEND_PAIRING_INFO:
	{
		static H2_AKESendPairingInfoPayLoad sendPayload;
		H2DBGLOG((LOCALDBG, "Getting Pairing Info\r\n"));
		hdcp2_Rx_GetEKhKm(sendPayload.Ekh_Km, sizeof(sendPayload.Ekh_Km));
	//	printk("TEST Ekh_km:\n");
	//	spu_print(sendPayload.Ekh_Km, sizeof(sendPayload.Ekh_Km));

		h2MsgAkeSendPairingInfoPack( send_msg, &length, &sendPayload );

#if 0
		if (0 != h2MsgAkeSendPairingInfoPack(message, &length, &sendPayload)) {
			H2DBGLOG((LOCALDBG, "Packing Pairing Info failed\r\n"));
			rc = -1;
		} else {
			H2DBGLOG((LOCALDBG, "Pairing Info packed\r\n"));
			rc = STATUS_OK_PENDING_MSG;
			gPairingState = PAIRING_INIT;
		}

#endif
	}
		break;
	default:
		H2DBGLOG((LOCALDBG, "POLL: UNKNOWN STATE %d\r\n", gPairingState));
		gPairingState = PAIRING_INIT;
		break;
	}
	return rc;
}

void h2Init(void)
{
	    /* TODO: crypto_init() in userspace, ??? in xtask */
	gState = H2_STATE_INIT;
	return;
}

int h2MessageParse(unsigned char *message, unsigned int length)
{
	int rc = 0;
	unsigned char msgId;
	do {
		if (NULL == message) {
			break;
		}
		msgId = *message;
		H2DBGLOG((LOCALDBG, "Got msg %d\n", msgId));
		switch (msgId) {
	/**
	* TX -> RX messages
	*/
		case AKE_INIT:
			rc = processAkeInit(message, length);
			break;
		case AKE_NO_STORED_EKM:
			rc = processAkeNoStoredEkm(message, length);

	/** Start pairing process */
			 gPairingState = PAIRING_SEND_HPRIME;
			break;
		case AKE_STORED_EKM:
			rc = processAkeStoredEkm(message, length);
			gPairingState = PAIRING_SEND_HPRIME;
			break;
		case LC_INIT:
			rc = processLcInit(message, length);
			break;
		case SKE_SEND_EKS:
			rc = processSkeSendEks(message, length);
			break;

	/**
	* RX -> TX messages. We should not receive these!
	*/
		case AKE_SEND_CERT:
		case AKE_SEND_RRX:
		case AKE_SEND_H_PRIME:
		case AKE_SEND_PAIRING_INFO:
		case LC_SEND_L_PRIME:
		case REP_AUTH_SEND_RXID_LIST:
			H2DBGLOG((LOCALDBG, "Received a message that should go to TX, not to RX!\n"));

			    /* TODO: Error handling? */
			rc = -1;
			break;
		default:
			H2DBGLOG((LOCALDBG, "Received unknown message\n"));
			rc = -2;
			break;
		}
	} while (0);
	return rc;
}

#endif
