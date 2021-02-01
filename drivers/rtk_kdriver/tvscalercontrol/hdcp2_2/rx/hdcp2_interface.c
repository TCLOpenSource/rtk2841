#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/bigdigits.h>
#include <tvscalercontrol/hdcp2_2/crypto.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_messages.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_interface.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_session.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_rcp_api.h>
#include <tvscalercontrol/hdcp2_2/hmac.h>
#include <tvscalercontrol/hdcp2_2/hdmi.h>
#include <rtk_kdriver/rtk_hdcp_otp_util.h>
H2_gKsvInfo gKsvInfo;

#ifdef TEST_HDCP2_2_RX_DRIVER
/**
 * Interface definition / prototypes
 */

#ifdef DEBUG_XTASK_INTERFACE
#define LOCALDBG ENABLE
#else
#define LOCALDBG DISABLE
#endif

#if defined(NEWBASE_FUNC)
unsigned char global_lc128[LC128_SIZE] = {0};
unsigned char global_certRx[CERT_RX_SIZE] = {0};
unsigned char global_kprivRx[KPRIVRX_SIZE] = {0};
unsigned char global_kh[KH_SIZE] = {0};
unsigned char global_km[HDMI_MAX_PORT_NUM][KM_SIZE] = {0};
unsigned char global_kd[HDMI_MAX_PORT_NUM][KD_SIZE] = {0};
unsigned char global_dkey2[HDMI_MAX_PORT_NUM][DKEY_SIZE] = {0};
unsigned char global_ksxorlc128[HDMI_MAX_PORT_NUM][KS_SIZE] = {0};
unsigned char global_riv[HDMI_MAX_PORT_NUM][RIV_SIZE] = {0};
unsigned char global_datadecrypto[HDMI_MAX_PORT_NUM][SESSIONKEY_SIZE] = {0};
#else
unsigned char global_certRx[CERT_RX_SIZE] = {0};
unsigned char global_kprivRx[KPRIVRX_SIZE] = {0};
#endif

//#define CONFIG_HDCP2_USE_DEFAULT_HDCP_KEY

#ifdef CONFIG_HDCP2_USE_DEFAULT_HDCP_KEY
const unsigned char CTS_key[]=
{
    0x00
};
#endif

/**
 * Secrets related to the session. Each new session
 * will reset these values.
 */
const unsigned char gcLc128[] = {
	0x93, 0xce, 0x5a, 0x56, 0xa0, 0xa1, 0xf4, 0xf7, 0x3c, 0x65, 0x8a, 0x1b,
	0xd2, 0xae, 0xf0, 0xf7
};


const unsigned char gcCert1[] = {
	0x74, 0x5b, 0xb8, 0xbd, 0x04, 0xbc, 0x83, 0xc7, 0x95, 0x78, 0xf9, 0x0c,
	0x91, 0x4b, 0x89, 0x38, 0x05, 0x5a, 0xa4, 0xac, 0x1f, 0xa8, 0x03, 0x93, 0x82, 0x79, 0x75, 0xaf,
	0x66, 0x22, 0xde, 0x43, 0x80, 0x8d, 0xcd, 0x5d, 0x90, 0xb8, 0x3c, 0xb3, 0xd8, 0x9e, 0xb0, 0x0d,
	0x09, 0x44, 0xf4, 0x3f, 0x5f, 0xab, 0xb9, 0xc4, 0xc9, 0x96, 0xef, 0x78, 0xb5, 0x8f, 0x69, 0x77,
	0xb4, 0x7d, 0x08, 0x14, 0x9c, 0x81, 0xa0, 0x8f, 0x04, 0x1f, 0xa0, 0x88, 0xe1, 0x20, 0xc7, 0x34,
	0x4a, 0x49, 0x35, 0x65, 0x99, 0xcf, 0x53, 0x19, 0xf0, 0xc6, 0x81, 0x76, 0x05, 0x5c, 0xb9, 0xde,
	0xdd, 0xab, 0x3d, 0xb0, 0x92, 0xa1, 0x23, 0x4f, 0x0c, 0x71, 0x30, 0x42, 0x78, 0xf6, 0x55, 0xae,
	0xbd, 0x36, 0x25, 0x8e, 0x25, 0x0d, 0x4e, 0x5e, 0x8e, 0x77, 0x6a, 0x60, 0xe3, 0xc1, 0xe9, 0xee,
	0xcd, 0x2b, 0x9e, 0x18, 0x63, 0x97, 0xd4, 0xe6, 0x75, 0x01, 0x00, 0x01, 0x00, 0x00, 0x1d, 0x0a,
	0x61, 0xea, 0xab, 0xf8, 0xa8, 0x2b, 0x02, 0x69, 0xa1, 0x34, 0xfd, 0x91, 0xac, 0x2b, 0xf2, 0x8f,
	0x34, 0x8b, 0xd4, 0x84, 0xfa, 0x62, 0xbc, 0x01, 0x4a, 0x4a, 0xa2, 0xb2, 0x14, 0xbf, 0xb5, 0xf4,
	0xdf, 0xac, 0x80, 0x93, 0x0d, 0x13, 0xec, 0x9c, 0xe5, 0xd8, 0x34, 0x70, 0x51, 0x9a, 0x66, 0x80,
	0xeb, 0xbe, 0xcc, 0x7e, 0x45, 0xf0, 0xe6, 0x39, 0x63, 0x84, 0xc9, 0xb9, 0x8e, 0x8c, 0xaf, 0x9c,
	0xa9, 0xd4, 0x0e, 0xeb, 0x9a, 0x57, 0x2a, 0x17, 0x41, 0xca, 0x97, 0xf3, 0x19, 0x96, 0xb5, 0x5d,
	0x0f, 0x30, 0xa3, 0x84, 0xe5, 0x73, 0xa2, 0xed, 0x05, 0x69, 0x7a, 0x22, 0xce, 0x84, 0x1f, 0x3e,
	0x39, 0x9e, 0x28, 0x76, 0xc9, 0xbc, 0x89, 0x5b, 0x70, 0xb1, 0x7b, 0xf4, 0xed, 0xb6, 0x74, 0x12,
	0xab, 0x48, 0x29, 0x64, 0xce, 0x6c, 0x60, 0x04, 0xeb, 0xa9, 0x7a, 0xa2, 0x15, 0xa6, 0x58, 0x9a,
	0xad, 0x32, 0xc7, 0x53, 0x39, 0xe5, 0xfe, 0xf0, 0x37, 0xa7, 0xa0, 0xc5, 0xff, 0xec, 0xd9, 0xb0,
	0x05, 0xbb, 0x25, 0x13, 0xa0, 0xa4, 0xc7, 0x0b, 0x2a, 0x5d, 0xc6, 0x8f, 0x51, 0x11, 0xcb, 0x36,
	0xed, 0x5c, 0x17, 0x7e, 0x22, 0x20, 0xc3, 0xeb, 0x40, 0x8c, 0x67, 0xbb, 0x1c, 0xd2, 0x47, 0xb0,
	0xe0, 0xbd, 0xe7, 0x4c, 0xcd, 0x5d, 0xd5, 0x23, 0x12, 0xf8, 0x3b, 0x1d, 0x91, 0x3b, 0xf3, 0xc7,
	0x60, 0xea, 0x90, 0x24, 0x48, 0xe5, 0x92, 0x21, 0x6c, 0xf6, 0xd9, 0x5e, 0x76, 0x8d, 0x2b, 0x86,
	0xa6, 0x7c, 0x16, 0xae, 0xa8, 0x36, 0x08, 0xa0, 0x37, 0x14, 0x1a, 0xd7, 0x03, 0xe1, 0x40, 0x31,
	0xca, 0x6c, 0x95, 0xe0, 0x10, 0xb0, 0x43, 0xcf, 0xb7, 0xe0, 0x30, 0x05, 0xb9, 0xac, 0xb7, 0x08,
	0x68, 0xcd, 0x7e, 0x11, 0x47, 0x2a, 0x03, 0x3b, 0xeb, 0x74, 0xc8, 0x19, 0x62, 0x8b, 0x2f, 0x11,
	0x91, 0xb6, 0x06, 0x4f, 0xe0, 0x2a, 0x44, 0x20, 0x43, 0x29, 0x13, 0x1f, 0xdd, 0xd0, 0x4a, 0x11,
	0x6c, 0x0e, 0x83, 0xbf, 0x22, 0x62, 0x3b, 0xeb, 0xec, 0xd7, 0x76, 0x28, 0xba, 0x64, 0x88, 0x42,
	0xc8, 0x73, 0xa7, 0x9e, 0x4a, 0x69, 0x3a, 0xb2, 0x0c, 0x4b, 0x3a, 0xd9, 0x50, 0xdb, 0x7c, 0x51,
	0xee, 0x15, 0xe0, 0x6b, 0x2c, 0x63, 0xa6, 0x91, 0x57, 0xdd, 0xbf, 0x17, 0x47, 0x23, 0xad, 0x15,
	0xcb, 0xb9, 0x91, 0x18, 0x0b, 0x51, 0x8f, 0xf9, 0x1c, 0x51, 0x67, 0xc1, 0x0b, 0x78, 0xf5, 0xd9,
	0x55, 0xdc, 0x48, 0xe4, 0xc0, 0x83, 0xa5, 0xdf, 0x75, 0xe2, 0xdc, 0x88, 0xd2, 0xc6, 0xdd, 0xdf,
	0x1f, 0x37, 0x90, 0x35, 0xf6, 0xfd, 0xda, 0xe0, 0x04, 0x32, 0x69, 0xc1, 0xaf, 0xd9, 0xf9, 0x11,
	0xc5, 0xaa, 0x74, 0x58, 0x32, 0x1c, 0x71, 0xaa, 0xa7, 0x14, 0xfb, 0x23, 0x17, 0x22,
};

typedef struct {
	unsigned char p[64];
	unsigned char q[64];
	unsigned char dP[64];
	unsigned char dQ[64];
	unsigned char qInv[64];
} kpriv_t;

/* R1 Private Key*/
const kpriv_t gcKpriv1 = {
	    /*p[] =*/
	{
		0xdc, 0x1a, 0x02, 0xb8, 0x36, 0xed, 0x3a, 0xe8, 0x74, 0x74, 0xcd,
		0x72, 0x28, 0x4a, 0xee, 0x31, 0x90, 0xe4, 0xd0, 0x6a, 0xf9, 0xf6,
		0xf8, 0xd3, 0x50, 0x29, 0xc2, 0x84, 0x97, 0x98, 0x10, 0x5d, 0xea,
		0x7b, 0x88, 0xfd, 0x36, 0xc5, 0x04, 0x99, 0xad, 0xab, 0x27, 0x0a,
		0x5a, 0x2a, 0xf9, 0x18, 0x7b, 0x7d, 0xb0, 0xc3, 0xcb, 0xe3, 0x5a,
		0xc2, 0x9a, 0x10, 0xf7, 0xc9, 0x9a, 0x18, 0x3e, 0xb5
	},
	    /*q[] = */
	{
		0xdb, 0x42, 0xe9, 0x42, 0xe3, 0x2a, 0x78, 0xc9, 0x6f, 0x2b, 0x7b,
		0x74, 0xd6, 0x9b, 0xae, 0xb9, 0x3d, 0xf4, 0xe7, 0x35, 0x90, 0x1c,
		0xc4, 0x5a, 0xb4, 0x22, 0x8c, 0x3c, 0x08, 0x9b, 0xa5, 0x29, 0x64,
		0x57, 0x29, 0xb2, 0xc4, 0x80, 0xf9, 0xee, 0xc6, 0x94, 0x30, 0x3e,
		0xd2, 0x33, 0x9f, 0xbb, 0x6a, 0x43, 0x03, 0x89, 0x14, 0x9b, 0x8f,
		0x20, 0xb8, 0x60, 0x1f, 0x7f, 0x30, 0x3b, 0x20, 0xc1
	 },
	    /*dP[] = */
	{
		0x73, 0xd1, 0xa4, 0x18, 0xb7, 0x9e, 0x81, 0xdf, 0x0c, 0x58, 0xe2,
		0x3a, 0xee, 0x04, 0xef, 0xee, 0x59, 0x26, 0x6e, 0x9d, 0xbc, 0x47,
		0x3f, 0x8c, 0x42, 0xa4, 0x96, 0xdd, 0x1a, 0xc0, 0x43, 0xec, 0x87,
		0x94, 0xd5, 0xf3, 0x18, 0xbc, 0xf7, 0xbc, 0xbe, 0x6c, 0x4f, 0xb0,
		0xdc, 0xdd, 0xbc, 0x12, 0x2b, 0xf9, 0x69, 0xe8, 0xbe, 0x03, 0x37,
		0x21, 0x2b, 0xdd, 0x3d, 0xe6, 0x72, 0x15, 0xcb, 0xf9
	 },
	    /*dQ[] = */
	{
		0x09, 0x1d, 0xe6, 0x1f, 0x0e, 0xdd, 0x04, 0x3a, 0xb3, 0xf1, 0xa5,
		0xe7, 0x7c, 0xc8, 0xea, 0x61, 0xef, 0x6e, 0x90, 0x72, 0x8c, 0xb4,
		0x75, 0x81, 0xa3, 0xfd, 0xcf, 0xc0, 0xeb, 0x46, 0xb5, 0x7e, 0x5c,
		0x1a, 0xb7, 0xb4, 0x24, 0x31, 0x8c, 0xb2, 0xdd, 0xf4, 0xe9, 0x70,
		0xa3, 0x42, 0xdc, 0x40, 0x69, 0xb1, 0xb1, 0xa2, 0xf0, 0x85, 0x6b,
		0x55, 0x1b, 0xf5, 0x7b, 0x39, 0xc9, 0xa2, 0x9b, 0xc1
	},
	    /*qInv[] =*/
	{
		0x89, 0x58, 0xa5, 0xa3, 0x63, 0xd9, 0xa9, 0xee, 0x0e, 0x7e, 0xa1,
		0xc0, 0x56, 0x2d, 0x59, 0xfc, 0xf8, 0x66, 0x1c, 0x26, 0x48, 0x21,
		0x9d, 0xe0, 0x61, 0xe4, 0xa8, 0x06, 0x97, 0x64, 0xc7, 0x01, 0x77,
		0x47, 0x11, 0x8e, 0xa2, 0x81, 0xd2, 0x00, 0xdd, 0x5a, 0x1b, 0x8f,
		0x7a, 0x1b, 0x2c, 0x68, 0x56, 0x39, 0xcf, 0xcd, 0xd3, 0x6a, 0xff,
		0x73, 0x81, 0x1d, 0x91, 0x3d, 0x48, 0xb4, 0x43, 0x4c
	},
};

const unsigned char gcLc128_test_hdcp22[] = {
	0x93, 0xce, 0x5a, 0x56, 0xa0, 0xa1, 0xf4, 0xf7, 0x3c, 0x65, 0x8a, 0x1b, 0xd2, 0xae, 0xf0, 0xf7
};

/* R1 Cert*/
const unsigned char gcCert1_test_hdcp22[] = {
	0x8b, 0xa4, 0x47, 0x42, 0xfb, 0xe4, 0x68, 0x63, 0x8a, 0xda, 0x97, 0x2d,
	0xde, 0x9a, 0x8d, 0x1c, 0xb1, 0x65, 0x4b, 0x85, 0x8d, 0xe5, 0x46, 0xd6, 0xdb, 0x95, 0xa5, 0xf6, 0x66, 0x74,
	0xea, 0x81, 0x0b, 0x9a, 0x58, 0x58, 0x66, 0x26, 0x86, 0xa6, 0xb4, 0x56, 0x2b, 0x29, 0x43, 0xe5, 0xbb, 0x81,
	0x74, 0x86, 0xa7, 0xb7, 0x16, 0x2f, 0x07, 0xec, 0xd1, 0xb5, 0xf9, 0xae, 0x4f, 0x98, 0x89, 0xa9, 0x91, 0x7d,
	0x58, 0x5b, 0x8d, 0x20, 0xd5, 0xc5, 0x08, 0x40, 0x3b, 0x86, 0xaf, 0xf4, 0xd6, 0xb9, 0x20, 0x95, 0xe8, 0x90,
	0x3b, 0x8f, 0x9f, 0x36, 0x5b, 0x46, 0xb6, 0xd4, 0x1e, 0xf5, 0x05, 0x88, 0x80, 0x14, 0xe7, 0x2c, 0x77, 0x5d,
	0x6e, 0x54, 0xe9, 0x65, 0x81, 0x5a, 0x68, 0x92, 0xa5, 0xd6, 0x40, 0x78, 0x11, 0x97, 0x65, 0xd7, 0x64, 0x36,
	0x5e, 0x8d, 0x2a, 0x87, 0xa8, 0xeb, 0x7d, 0x06, 0x2c, 0x10, 0xf8, 0x0a, 0x7d, 0x01, 0x00, 0x01, 0x10, 0x00,
	0x06, 0x40, 0x99, 0x8f, 0x5a, 0x54, 0x71, 0x23, 0xa7, 0x6a, 0x64, 0x3f, 0xbd, 0xdd, 0x52, 0xb2, 0x79, 0x6f,
	0x88, 0x26, 0x94, 0x9e, 0xaf, 0xa4, 0xde, 0x7d, 0x8d, 0x88, 0x10, 0xc8, 0xf6, 0x56, 0xf0, 0x8f, 0x46, 0x28,
	0x48, 0x55, 0x51, 0xc5, 0xaf, 0xa1, 0xa9, 0x9d, 0xac, 0x9f, 0xb1, 0x26, 0x4b, 0xeb, 0x39, 0xad, 0x88, 0x46,
	0xaf, 0xbc, 0x61, 0xa8, 0x7b, 0xf9, 0x7b, 0x3e, 0xe4, 0x95, 0xd9, 0xa8, 0x79, 0x48, 0x51, 0x00, 0xbe, 0xa4,
	0xb6, 0x96, 0x7f, 0x3d, 0xfd, 0x76, 0xa6, 0xb7, 0xbb, 0xb9, 0x77, 0xdc, 0x54, 0xfb, 0x52, 0x9c, 0x79, 0x8f,
	0xed, 0xd4, 0xb1, 0xbc, 0x0f, 0x7e, 0xb1, 0x7e, 0x70, 0x6d, 0xfc, 0xb9, 0x7e, 0x66, 0x9a, 0x86, 0x23, 0x3a,
	0x98, 0x5e, 0x32, 0x8d, 0x75, 0x18, 0x54, 0x64, 0x36, 0xdd, 0x92, 0x01, 0x39, 0x90, 0xb9, 0xe3, 0xaf, 0x6f,
	0x98, 0xa5, 0xc0, 0x80, 0xc6, 0x2f, 0xa1, 0x02, 0xad, 0x8d, 0xf4, 0xd6, 0x66, 0x7b, 0x45, 0xe5, 0x74, 0x18,
	0xb1, 0x27, 0x24, 0x01, 0x1e, 0xea, 0xd8, 0xf3, 0x79, 0x92, 0xe9, 0x03, 0xf5, 0x57, 0x8d, 0x65, 0x2a, 0x8d,
	0x1b, 0xf0, 0xda, 0x58, 0x3f, 0x58, 0xa0, 0xf4, 0xb4, 0xbe, 0xcb, 0x21, 0x66, 0xe9, 0x21, 0x7c, 0x76, 0xf3,
	0xc1, 0x7e, 0x2e, 0x7c, 0x3d, 0x61, 0x20, 0x1d, 0xc5, 0xc0, 0x71, 0x28, 0x2e, 0xb7, 0x0f, 0x1f, 0x7a, 0xc1,
	0xd3, 0x6a, 0x1e, 0xa3, 0x54, 0x34, 0x8e, 0x0d, 0xd7, 0x96, 0x93, 0x78, 0x50, 0xc1, 0xee, 0x27, 0x72, 0x3a,
	0xbd, 0x57, 0x22, 0xf0, 0xd7, 0x6d, 0x9d, 0x65, 0xc4, 0x07, 0x9c, 0x82, 0xa6, 0xd4, 0xf7, 0x6b, 0x9a, 0xe9,
	0xc0, 0x6c, 0x4a, 0x4f, 0x6f, 0xbe, 0x8e, 0x01, 0x37, 0x50, 0x3a, 0x66, 0xd9, 0xe9, 0xd9, 0xf9, 0x06, 0x9e,
	0x00, 0xa9, 0x84, 0xa0, 0x18, 0xb3, 0x44, 0x21, 0x24, 0xa3, 0x6c, 0xcd, 0xb7, 0x0f, 0x31, 0x2a, 0xe8, 0x15,
	0xb6, 0x93, 0x6f, 0xb9, 0x86, 0xe5, 0x28, 0x01, 0x1a, 0x5e, 0x10, 0x3f, 0x1f, 0x4d, 0x35, 0xa2, 0x8d, 0xb8,
	0x54, 0x26, 0x68, 0x3a, 0xcd, 0xcb, 0x5f, 0xfa, 0x37, 0x4a, 0x60, 0x10, 0xb1, 0x0a, 0xfe, 0xba, 0x9b, 0x96,
	0x5d, 0x7e, 0x99, 0xcf, 0x01, 0x98, 0x65, 0x87, 0xad, 0x40, 0xd5, 0x82, 0x1d, 0x61, 0x54, 0xa2, 0xd3, 0x16,
	0x3e, 0xf7, 0xe3, 0x05, 0x89, 0x8d, 0x8a, 0x50, 0x87, 0x47, 0xbe, 0x29, 0x18, 0x01, 0xb7, 0xc3, 0xdd, 0x43,
	0x23, 0x7a, 0xcd, 0x85, 0x1d, 0x4e, 0xa9, 0xc0, 0x1a, 0xa4, 0x77, 0xab, 0xe7, 0x31, 0x9a, 0x33, 0x1b, 0x7a,
	0x86, 0xe1, 0xe5, 0xca, 0x0c, 0x43, 0x1a, 0xfa, 0xec, 0x4c, 0x05, 0xc6, 0xd1, 0x43, 0x12, 0xf9, 0x4d, 0x3e,
	0xf7, 0xd6, 0x05, 0x9c, 0x1c, 0xdd,
};

/*R1 Private Key*/
const kpriv_t gcKpriv1_test_hdcp22 = {
	    /*p[] =*/
	{
		0xf5, 0xf6, 0xfa, 0x44, 0xa2, 0x16, 0x2f, 0xa7, 0x1f, 0x7f, 0x16,
		0x05, 0x99, 0x26, 0xc4, 0x1b, 0x80, 0x7f, 0xfa, 0x52, 0x4e, 0x3e,
		0xaa, 0x3d, 0x1e, 0xb0, 0xf1, 0x9a, 0xc6, 0x3d, 0x8f, 0x57, 0x2b,
		0x9e, 0xcd, 0xe8, 0x03, 0xd6, 0xf3, 0x91, 0x75, 0xe2, 0x19, 0x44,
		0x9e, 0x11, 0x58, 0x5f, 0xd6, 0x88, 0x7c, 0xc4, 0xc1, 0x5b, 0x45,
		0x9b, 0x84, 0xcf, 0x72, 0x1d, 0x35, 0xbf, 0x24, 0xd5
	 },
	    /*q[] = */
	{
		0xed, 0xba, 0x08, 0xbf, 0x42, 0x2c, 0x0e, 0xfa, 0x3a, 0xc4, 0xd2,
		0xc7, 0x01, 0x51, 0x25, 0xae, 0xb0, 0xa1, 0xcc, 0xdb, 0x67, 0x9b,
		0xaa, 0x50, 0xf0, 0x80, 0xac, 0x4b, 0x9f, 0x5c, 0xba, 0x1e, 0xf4,
		0x7f, 0xa9, 0xb3, 0x21, 0x8b, 0x62, 0x2c, 0x36, 0xda, 0xcd, 0xa7,
		0x4d, 0xa4, 0xd6, 0x44, 0xed, 0xb1, 0x34, 0xe7, 0x69, 0x10, 0x77,
		0x5a, 0x6a, 0xff, 0xf5, 0x63, 0x8a, 0x2c, 0x43, 0x09
	 },
	    /*dP[] = */
	{
		0x61, 0x5a, 0xc4, 0x6c, 0x6e, 0x0b, 0x82, 0x09, 0x10, 0x3a, 0x69,
		0x29, 0x06, 0x19, 0x85, 0xfd, 0xac, 0xba, 0xfb, 0x05, 0xa0, 0xda,
		0xc4, 0xdf, 0x34, 0x4a, 0xad, 0x16, 0xa9, 0xe8, 0xab, 0xd7, 0xc0,
		0xf8, 0x36, 0x5f, 0xe3, 0x45, 0x2d, 0x5b, 0x21, 0xe1, 0xc0, 0x46,
		0x9c, 0x9a, 0x18, 0xf4, 0xb6, 0x21, 0x87, 0xe1, 0x08, 0xf7, 0x6b,
		0x71, 0xc6, 0xfb, 0xa5, 0x1b, 0x52, 0xae, 0xb9, 0x91
	 },
	    /*dQ[] = */
	{
		0x5a, 0x83, 0x7f, 0xbb, 0x1a, 0xbd, 0xdd, 0xc2, 0x06, 0xc8, 0x54,
		0x1c, 0xb3, 0x72, 0xab, 0x2f, 0x55, 0x4f, 0x75, 0xc9, 0x80, 0x2c,
		0x73, 0xef, 0xb7, 0x72, 0xb6, 0xa7, 0x60, 0x79, 0x14, 0xe0, 0x9e,
		0x65, 0x51, 0x3e, 0xc4, 0x21, 0xe6, 0xf2, 0x40, 0xbc, 0x94, 0x9b,
		0x03, 0xe4, 0x24, 0x35, 0x40, 0x6f, 0x3d, 0x5e, 0x72, 0xd1, 0x73,
		0x30, 0x39, 0x17, 0x55, 0xde, 0x5d, 0x88, 0xb6, 0xc9
	 },
	    /*qInv[] =*/
	{
		0xbc, 0x91, 0x2a, 0x93, 0x6a, 0x8d, 0x24, 0x3c, 0xd5, 0x7d, 0x12,
		0x3b, 0xa3, 0x71, 0xc7, 0x3a, 0xf0, 0x64, 0x72, 0x50, 0x7e, 0x18,
		0x71, 0xe1, 0xb4, 0x3b, 0x1e, 0xfc, 0x38, 0xca, 0xe6, 0x8c, 0x16,
		0x51, 0x97, 0xd6, 0x3f, 0x04, 0xee, 0x23, 0x8b, 0x45, 0x0c, 0x4b,
		0x98, 0x36, 0x18, 0x27, 0x29, 0x1b, 0x4d, 0x73, 0x7e, 0xe8, 0xb0,
		0x1a, 0xc7, 0xfb, 0x5c, 0xea, 0x78, 0xd0, 0x6e, 0x97
	 },
};

/**
 * Attached KSVs
 */
 static struct {
	unsigned char rtx[RTX_SIZE];
	unsigned char rn[RN_SIZE];
	unsigned char rRx[RRX_SIZE];
	unsigned char m[M_SIZE];
	unsigned char hPrime[H_SIZE];
	unsigned char txcaps[TXCAPS_SIZE];
	unsigned char rxcaps[RXCAPS_SIZE];
	unsigned char ks[KS_SIZE];
} SessionSecrets_Rx[HDMI_MAX_PORT_NUM];

static struct {
	unsigned char rx_version;
	unsigned short rx_capability_mask;
	unsigned char tx_version;
	unsigned short tx_capability_mask;
}HDCP2_DEVICE_INFO;
/**
 * @func spu_printBytes
 * @scope Static
 *
 * NOTE: This function does not do anything if LOCALDBG is set to DISABLE.
 *
 * @param H2uint8 *bytes - Data to print
 * @param H2uint32 len - How many bytes to print
 * @return void
 */
#ifdef DEBUG_XTASK_INTERFACE
static void spu_printBytes(const H2uint8 *bytes, H2uint32 len)
{
	unsigned int ii;
	for (ii = 0; ii < len; ii++) {
		pr_debug("%02x ", bytes[ii]);
		if (ii % 16 == 15) {
			pr_debug("\r\n");
		}
	}
	pr_debug("\r\n");
}

#define spu_printBytes_with_text(x, y, fmt, args...)    do {pr_debug(fmt, ## args); spu_printBytes(x, y); } while (0)

#else
#define spu_printBytes(x, y)
#define spu_printBytes_with_text(x, y, args...)
#endif
int read_binary_file(const char *path, unsigned char *buff, unsigned int len)
{
	struct file *file = NULL;
	int ret;
	file = filp_open(path, O_RDONLY, 0444);
	if (IS_ERR(file)) {
		pr_debug("create file error\n");
		return -1;
	}
	ret = kernel_read(file, 0, buff, len);
	filp_close(file, 0);
	return ret;
}

int write_binary_file(const char *path, unsigned char *buff, unsigned int len)
{
	struct file *file = NULL;
	mm_segment_t fs;
	loff_t pos;

	file = filp_open(path, O_RDWR | O_CREAT, 0444);
	if (IS_ERR(file)) {
		pr_debug("create file error\n");
		return -1;
	}
	fs = get_fs();
	set_fs(KERNEL_DS);
	pos = 0;
	vfs_write(file, buff, len, &pos);
	filp_close(file, 0);
	set_fs(fs);
	return 0;
}

H2status hdcp2_load_from_flash(void);

/**
 * Zero out session secrets, called from CID_INIT
 */
H2status hdcp2_Rx_init(void)
{
	hdcp2_load_from_flash();
	int i;
	for(i = 0; i < HDMI_MAX_PORT_NUM; i++)
		memset((char *)&SessionSecrets_Rx[i], 0, sizeof(SessionSecrets_Rx[i]));
	memset((char *)&gKsvInfo, 0, sizeof(gKsvInfo));

	    /* Disable the HDMI police */
	hdmi_policeEnable(FALSE);
	return H2_OK;
}

/**
 * Zero out session secrets
 */
H2status hdcp2_Rx_reset(void)
{
	int i;
	for(i = 0; i < HDMI_MAX_PORT_NUM; i++)
		memset((char *)&SessionSecrets_Rx[i], 0, sizeof(SessionSecrets_Rx[i]));

	    /* Disable the HDMI police */
	hdmi_policeEnable(FALSE);
	return H2_OK;
}

#ifdef HDCP2_2_WIFI
H2status hdcp2_Rx_SetRepeater_wifi(char repeater)
{
	unsigned int nport = get_current_hdmi_port();
	if (repeater & REPEATER_MASK)
		SessionSecrets_Rx[nport].repeater = 1;
	else
		SessionSecrets_Rx[nport].repeater = 0;
	pr_debug("repeater:%x\n", repeater);
	return H2_OK;
}

int hdcp2_Rx_IsRepeater(void)
{
	unsigned int nport = get_current_hdmi_port();
	if (SessionSecrets_Rx[nport].repeater)
		return TRUE;
	else
		return FALSE;
}

BOOL hdcp2_Rx_IsProDesp(void)
{
	if (*(CertKey.Reserved) & 0xf)
		return TRUE;
	else
		return FALSE;
}

#endif

/**
 * Generate the Pseudo-Random 64 bit value rRx.
 *
 * Results are stored in SessionSecrets.rRx.
 *
 */
H2status hdcp2_Rx_GenrRx(void)
{
	unsigned int nport = get_current_hdmi_port();

#if 1
	H2uint32 rRx[2];
	rRx[0] = crypto_random32();
	rRx[1] = crypto_random32();

#else
	unsigned char rRx[] = {
		0xe1, 0x7a, 0xb0, 0xfd, 0x0f, 0x54, 0x40, 0x52
	};
#endif

	memcpy(SessionSecrets_Rx[nport].rRx, rRx, RRX_SIZE);
	return H2_OK;
}

/**
 * Copy RTX to Session Secrets.
 */
H2status hdcp2_Rx_Setrtx(const H2uint8 *rtx)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(SessionSecrets_Rx[nport].rtx, rtx, RRX_SIZE);
	return H2_OK;
}

H2status hdcp2_Rx_SetTxcaps(unsigned char *message)
{
	if (message == NULL)
		return H2_ERROR;
	unsigned int nport = get_current_hdmi_port();
	memcpy(SessionSecrets_Rx[nport].txcaps, message, TXCAPS_SIZE);
		return H2_OK;
}

H2status hdcp2_Rx_GetTxcaps(H2uint8 *txcaps, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(txcaps, SessionSecrets_Rx[nport].txcaps, TXCAPS_SIZE);
	return H2_OK;
}

H2status hdcp2_Rx_GenRxcaps(void)
{
	unsigned rxcaps[3];
	rxcaps[2] = 0;
	rxcaps[2] |= 0;
	rxcaps[1] = 0;
	rxcaps[0] = 2;
	unsigned int nport = get_current_hdmi_port();
	memcpy(SessionSecrets_Rx[nport].rxcaps, rxcaps, RXCAPS_SIZE);
	return H2_OK;
}

H2status hdcp2_Rx_GetRxcaps(H2uint8 *rxcaps, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(rxcaps, SessionSecrets_Rx[nport].rxcaps, RXCAPS_SIZE);
	return H2_OK;
}

/**
 * Copy Rn to Session Secrets.
 */
H2status hdcp2_Rx_Setrn(const H2uint8 *rn)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(SessionSecrets_Rx[nport].rn, rn, RN_SIZE);
	return H2_OK;
}

H2status hdcp2_Rx_GetRn(H2uint8 *rn, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(rn, SessionSecrets_Rx[nport].rn, RN_SIZE);
	return H2_OK;
}

/**
 * Set initialization vector RIV.
 */
H2status hdcp2_Rx_SetRiv(const H2uint8 *riv)
{
	spu_SetRiv(riv);
	RTK_RCP_SET_CW_HDCP2(SRAM_RIV_ENTRY , riv, RIV_SIZE);
	return H2_OK;
}

/**
 * Receive EKpubKm from userspace and process it.
 *
 * Results are stored in SessionSecrets.
 * @todo Support 'repeater'=1.
 *
 */
H2status hdcp2_Rx_SetEKpubKm(const H2uint8 *EKpubKm)
{
	H2uint8 Km_tmp[MASTERKEY_SIZE];
	H2uint8 Kd_tmp[KD_SIZE];
	H2uint8 KPriv_tmp[KPRIVRX_SIZE];
	H2status rc;
	H2uint8 rtx[RTX_SIZE];
	H2uint8 rrx[RRX_SIZE];
	H2uint8 rn[RN_SIZE] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	unsigned char rxcaps[RXCAPS_SIZE];
	unsigned char txcaps[TXCAPS_SIZE];
	unsigned int nport = get_current_hdmi_port();
	    /* Decrypt Km */
	spu_GetKPrivRx(KPriv_tmp);
	rc = Decrypt_EKpubKm_kPrivRx(KPriv_tmp, Km_tmp, EKpubKm);
	if (rc != H2_OK) {
		H2DBGLOG((LOCALDBG, "Error decrypting master key!\r\n"));
		goto end_proc;
	}
	spu_SetKM(Km_tmp);
	RTK_RCP_SET_CW_HDCP2(SRAM_KM_ENTRY , Km_tmp, KM_SIZE);

	//printk("TEST km:\n");
	//spu_print(Km_tmp, KM_SIZE);
	hdcp2_Rx_GetrTx(rtx, RTX_SIZE);
	hdcp2_Rx_GetrRx(rrx, RRX_SIZE);

    /** Generate Kd = dKey0 || dKey1 */
	    /*RCP_HDCP2_GenKd(SRAM_KM_ENTRY, SessionSecrets.rtx, SessionSecrets.rn, SRAM_KD_ENTRY);*/
	RCP_HDCP2_GenKd(SRAM_KM_ENTRY, rtx, rrx, rn, SRAM_KD_ENTRY, 1);
	//printk("Test KD\n");
	RTK_RCP_GET_CW_HDCP2(SRAM_KD_ENTRY , Kd_tmp, KD_SIZE);
	spu_SetKD(Kd_tmp);
	//spu_print(Kd_tmp, KD_SIZE);
	hdcp2_Rx_GetRxcaps(rxcaps, RXCAPS_SIZE);
	hdcp2_Rx_GetTxcaps(txcaps, TXCAPS_SIZE);

    /** Compute HPrime from Kd, RTX, and Repeater */
	    /*Compute_Hprime_Rx(Kd_tmp, rtx, 1, SessionSecrets_Rx.hPrime);*/
	Compute_Hprime_22(Kd_tmp, rtx, txcaps, rxcaps, SessionSecrets_Rx[nport].hPrime);
	//printk("Test hPrime\n");
	//spu_print(SessionSecrets_Rx.hPrime, H_SIZE);
end_proc:
	memset(Kd_tmp, 0, sizeof(Kd_tmp));
	memset(Km_tmp, 0, sizeof(Km_tmp));
	memset(KPriv_tmp, 0, sizeof(KPriv_tmp));
	return rc;
}


/**
 * Set EKhKm and m. m should be stored after EKhKm.
 */
H2status hdcp2_Rx_SetEKhKm(H2uint8 *EKhKm, H2uint8 *m)
{
	H2uint8 Kh_temp[H_SIZE];
	H2uint8 Km_temp[MASTERKEY_SIZE];
	H2uint8 Kd_temp[KD_SIZE];
	H2uint8 rtx[RTX_SIZE];
	H2uint8 rrx[RRX_SIZE];
	H2uint8 rn[RN_SIZE] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	unsigned char rxcaps[RXCAPS_SIZE];
	unsigned char txcaps[TXCAPS_SIZE];
	unsigned int nport = get_current_hdmi_port();

	memcpy(SessionSecrets_Rx[nport].m, m, M_SIZE);
	spu_GetKH(Kh_temp);

    /** Compute Km */
	RTK_RCP_AES_CTR_Decryption(Kh_temp, SessionSecrets_Rx[nport].m, EKhKm, Km_temp, EKHKM_SIZE);
	spu_SetKM(Km_temp);
	RTK_RCP_SET_CW_HDCP2(SRAM_KM_ENTRY , Km_temp, KM_SIZE);
	//printk("TEST km:\n");
	//spu_print(Km_temp, 16);

    /** Compute Kd */
	    /*RCP_HDCP2_GenKd(SRAM_KM_ENTRY, SessionSecrets.rtx, SessionSecrets.rn, SRAM_KD_ENTRY);
	     RCP_HDCP2_GenKd(SRAM_KM_ENTRY, rtx, rrx, rn, SRAM_KD_ENTRY,0);*/
	hdcp2_Rx_GetrTx(rtx, RTX_SIZE);
	hdcp2_Rx_GetrRx(rrx, RRX_SIZE);
	RCP_HDCP2_GenKd(SRAM_KM_ENTRY, rtx, rrx, rn, SRAM_KD_ENTRY, 1);
	RTK_RCP_GET_CW_HDCP2(SRAM_KD_ENTRY , Kd_temp, KD_SIZE);
	spu_SetKD(Kd_temp);
	//printk("Test KD\n");
	//spu_print(Kd_temp, KD_SIZE);

    /** Compute HPrime */
	    /*Compute_Hprime_Rx(Kd_temp, SessionSecrets.rtx, HDCP_REPEATER, SessionSecrets.hPrime);*/
	hdcp2_Rx_GetRxcaps(rxcaps, RXCAPS_SIZE);
	hdcp2_Rx_GetTxcaps(txcaps, TXCAPS_SIZE);

	    /*Compute_Hprime_Rx(Kd_temp, rtx, 1, SessionSecrets_Rx.hPrime);*/
	Compute_Hprime_22(Kd_temp, rtx, txcaps, rxcaps, SessionSecrets_Rx[nport].hPrime);
	//printk("Test1 hPrime\n");
	//spu_print(SessionSecrets_Rx.hPrime, H_SIZE);
	memset(Kh_temp, 0, sizeof(Kh_temp));
	memset(Km_temp, 0, sizeof(Km_temp));
	memset(Kd_temp, 0, sizeof(Kd_temp));
	return H2_OK;
}

H2status hdcp2_Rx_ParseEKhKm(H2uint8 *EKhKm, H2uint8 *m)
{
	H2uint8 Kh[KH_SIZE];
	H2uint8 Km[MASTERKEY_SIZE];
	spu_GetKH(Kh);

#if 0
	HDCP2DBGLOG("Kh: ", Kh, KH_SIZE);
	HDCP2DBGLOG("m: ", m, M_SIZE);
	HDCP2DBGLOG("EKhKm: ", EKhKm, EKHKM_SIZE);

#endif
    /** Compute Km */
	RTK_RCP_AES_CTR_Decryption(Kh, m, EKhKm, Km, EKHKM_SIZE);
	spu_SetKM(Km);
	RTK_RCP_SET_CW_HDCP2(SRAM_KM_ENTRY , Km, KM_SIZE);
	return H2_OK;
}

H2status hdcp2_Rx_SetKs(const H2uint8 *ks)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(SessionSecrets_Rx[nport].ks, ks, sizeof(SessionSecrets_Rx[nport].ks));
	return H2_OK;
}

H2status hdcp2_Rx_GetKs(H2uint8 *ks, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(ks, SessionSecrets_Rx[nport].ks, sizeof(SessionSecrets_Rx[nport].ks));
	return H2_OK;
}

/**
 * Process EdKeyKs message. Compute sessionKey based on
 * EdKeyKs and dKey2
 */
H2status hdcp2_Rx_SetEdKeyKs(H2uint8 *EdKeyKs)
{
	#if defined(NEWBASE_FUNC)
	unsigned char nport = get_current_hdmi_port();
	#endif

	unsigned char dkey2[16];
	H2uint8 rtx[RTX_SIZE];
	H2uint8 rrx[RRX_SIZE];
	H2uint8 rn[RN_SIZE];
	unsigned char ks[16];
	hdcp2_Rx_GetrTx(rtx, RTX_SIZE);
	hdcp2_Rx_GetrRx(rrx, RRX_SIZE);
	hdcp2_Rx_GetRn(rn, RN_SIZE);

    /** Compute dKey2 */
	RCP_HDCP2_GenDKey(SRAM_KM_ENTRY, rtx, rrx, rn, 2, SRAM_DK2_ENTRY, 1);

	    /*RCP_HDCP2_GenKd(SRAM_KM_ENTRY, rtx, rrx, rn, SRAM_KD_ENTRY,0);*/
	RTK_RCP_GET_CW_HDCP2(SRAM_DK2_ENTRY , dkey2, DKEY_SIZE);
	spu_SetDKey2(dkey2);
//	printk("TEST dkey2:\n");
//	spu_print(dkey2, 16);

#if 0
	unsigned char rrx_temp[16];
	unsigned char temp[16];
	memset(rrx_temp, 0, sizeof(rrx_temp));
	memcpy(rrx_temp + DKEY_SIZE - RRX_SIZE, rrx, RRX_SIZE);
	crypt_xor(EdKeyKs, dkey2, temp, DKEY_SIZE);
	crypt_xor(temp, rrx_temp, ks, DKEY_SIZE);

#endif

    /** Compute Session Key */
	RCP_HDCP2_GenKs(SRAM_DK2_ENTRY, EdKeyKs, rrx, SRAM_KS_XOR_LC128_ENTRY);
	RTK_RCP_GET_CW_HDCP2(SRAM_KS_XOR_LC128_ENTRY , ks, SRAM_KS_XOR_LC128_SIZE);
	spu_SetKsXorLc128(ks);
	hdcp2_Rx_SetKs(ks);
//	printk("TEST ks:\n");
//	spu_print(ks, 16);

	#if ENABLE_DDC_WRITE
	#if defined(NEWBASE_FUNC)
	lib_ks_setting(nport, ks);
	#else
	drvif_KS_Setting(ks);
	#endif
	#endif
    /** Compute AES Key */
	unsigned char lc128[LC128_SIZE];
	spu_GetLc128(lc128);
	RTK_RCP_SET_CW_HDCP2(SRAM_LC128_ENTRY ,  lc128, LC128_SIZE);
	RCP_HDCP2_GenKsXorLc128(SRAM_LC128_ENTRY, SRAM_KS_XOR_LC128_ENTRY, SRAM_KS_XOR_LC128_ENTRY);

	    /*
	     * Enable the HDMI police
	     */
	hdmi_policeEnable(TRUE);
	return H2_OK;
}

H2status hdcp2_Rx_Compute_EdKeyKs(H2uint8 *rtx, H2uint8 *rrx, H2uint8 *rn, H2uint8 *EdKeyKs, int modeHDCP22)
{
	unsigned char dkey2[DKEY_SIZE];
	unsigned char ks[KS_SIZE];
	RCP_HDCP2_GenDKey(SRAM_KM_ENTRY, rtx, rrx, rn, 2, SRAM_DK2_ENTRY, modeHDCP22);
	RTK_RCP_GET_CW_HDCP2(SRAM_DK2_ENTRY , dkey2, DKEY_SIZE);
	spu_SetDKey2(dkey2);

	/** Compute Session Key */
	RCP_HDCP2_GenKs(SRAM_DK2_ENTRY, EdKeyKs, rrx, SRAM_KS_XOR_LC128_ENTRY);
	RTK_RCP_GET_CW_HDCP2(SRAM_KS_XOR_LC128_ENTRY , ks, SRAM_KS_XOR_LC128_SIZE);
	spu_SetKsXorLc128(ks);
	hdcp2_Rx_SetKs(ks);
	return H2_OK;
}

H2status hdcp2_Rx_GetrTx(H2uint8 *pOut, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(pOut, SessionSecrets_Rx[nport].rtx, RTX_SIZE);
	return H2_OK;
}

/**
 * Fetch the generated rRx value to send to the TX.
 *
 */
H2status hdcp2_Rx_GetrRx(H2uint8 *pOut, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(pOut, SessionSecrets_Rx[nport].rRx, sizeof(SessionSecrets_Rx[nport].rRx));
	return H2_OK;
}

/**
 * Read the public key certificate from Serialization Secrets.
 */
H2status hdcp2_Rx_GetCertRx(H2uint8 *pOut, H2uint32 ulSize)
{
	spu_GetCertRx(pOut);
	return H2_OK;
}

/**
 * Get the computed EKhKm value to be sent to the TX
 */
H2status hdcp2_Rx_GetEKhKm(H2uint8 *pOut, H2uint32 ulSize)
{
	unsigned char kh[KH_SIZE];
	unsigned char km[16];
	unsigned char m[16];
	unsigned int nport = get_current_hdmi_port();
	memset(m, 0, 16);
	memcpy(m, SessionSecrets_Rx[nport].rtx, 8);
	memcpy(m + 8, SessionSecrets_Rx[nport].rRx, 8);
	spu_GetKH(kh);
	spu_GetKM(km);

	    /*RCP_HDCP2_EkhKm(SRAM_KH_ENTRY, SRAM_KM_ENTRY, SessionSecrets.rtx, pOut);   */
	RTK_RCP_AES_CTR_Decryption(kh, m, km, pOut, 16);
	return H2_OK;
}

H2status hdcp2_Rx_Compute_EKhKm(H2uint8 *m, H2uint8 *Ekhkm)
{
	unsigned char kh[KH_SIZE];
	unsigned char km[KM_SIZE];
	spu_GetKH(kh);
	spu_GetKM(km);

	    /*RCP_HDCP2_EkhKm(SRAM_KH_ENTRY, SRAM_KM_ENTRY, SessionSecrets.rtx, pOut);    */
	RTK_RCP_AES_CTR_Decryption(kh, m, km, Ekhkm, 16);
	return H2_OK;
}

/**
 * Get HPrime.
 */
H2status hdcp2_Rx_GethPrime(H2uint8 *pOut, H2uint32 ulSize)
{
	unsigned int nport = get_current_hdmi_port();
	memcpy(pOut, &SessionSecrets_Rx[nport].hPrime, sizeof(SessionSecrets_Rx[nport].hPrime));
	return H2_OK;
}

/**
 * Get L prime.
 */
H2status hdcp2_Rx_GetlPrime(H2uint8 *pOut, H2uint32 ulSize)
{
	H2uint8 Kd_tmp[KD_SIZE];
	H2uint8 rrx[RRX_SIZE];
	H2uint8 rn[RN_SIZE];

	spu_GetKD(Kd_tmp);
	hdcp2_Rx_GetrRx(rrx, RRX_SIZE);
	hdcp2_Rx_GetRn(rn, RN_SIZE);
	Compute_Lprime_Rx(Kd_tmp, rrx, rn, pOut);
	memset(Kd_tmp, 0, sizeof(Kd_tmp));
	//printk("Test  Lprime:\n");
	//spu_print(pOut, L_SIZE);
	return H2_OK;
}

/**
 * The KSVs message contains:
 * Device Count - 1 byte
 * Depth ( 1 byte )
 * Max Devs Exceeded ( 1 byte )
 * Max Cascade Exceeded ( 1 byte )
 * if ( Max Devs Exceeded == 0 && MaxCascadeExceeded == 0 )
 * KSVs ( 5 bytes each )
 */
H2status hdcp2_Rx_SetKsvs(unsigned char *pMsg, unsigned int len)
{
	memset(&gKsvInfo, 0, sizeof(gKsvInfo));
	gKsvInfo.DeviceCount = *pMsg;
	if (gKsvInfo.DeviceCount == 0)
		goto end_proc;
	gKsvInfo.Depth = *(pMsg + 1) + 1;
	gKsvInfo.DevicesExceeded = *(pMsg + 2);
	gKsvInfo.DepthExceeded = *(pMsg + 3);
	H2DBGLOG((LOCALDBG, "KSVINFO: %u devices, %u depth, %u dev exceed, %u depth exceed\r\n",
		gKsvInfo.DeviceCount, gKsvInfo.Depth,
		gKsvInfo.DevicesExceeded, gKsvInfo.DepthExceeded));
	if ((gKsvInfo.DeviceCount < MAX_DEVICECOUNT) && (gKsvInfo.DevicesExceeded == 0) && (gKsvInfo.DepthExceeded == 0)) {
		H2DBGLOG((LOCALDBG, "KSVINFO: Copying %u bytes\r\n", 5 * gKsvInfo.DeviceCount));
		memcpy(gKsvInfo.Ksvs, pMsg + 4, 5 * gKsvInfo.DeviceCount);
	} else
		gKsvInfo.DevicesExceeded = 1;
end_proc:
	return H2_OK;
}

/**
 * Compute and return vPrime.
 */
H2status hdcp2_Rx_GetvPrime(H2uint8 *pOut, H2uint32 ulSize)
{
	H2status rc = H2_ERROR;
	static H2uint8 vPrimeBuff[5 * MAX_DEVICECOUNT + 4];
	H2uint8 Kd_tmp[KD_SIZE];

	memcpy(vPrimeBuff, gKsvInfo.Ksvs, gKsvInfo.DeviceCount * 5);
	vPrimeBuff[gKsvInfo.DeviceCount * 5] = gKsvInfo.Depth;
	vPrimeBuff[gKsvInfo.DeviceCount * 5 + 1] = gKsvInfo.DeviceCount;
	vPrimeBuff[gKsvInfo.DeviceCount * 5 + 2] = gKsvInfo.DevicesExceeded;
	vPrimeBuff[gKsvInfo.DeviceCount * 5 + 3] = gKsvInfo.DepthExceeded;
	spu_GetKD(Kd_tmp);
	rc = hmacsha256(Kd_tmp, KD_SIZE, vPrimeBuff, gKsvInfo.DeviceCount * 5 + 4, pOut);

	memset(Kd_tmp, 0, sizeof(Kd_tmp));
	return rc;
}

H2status hdcp2_Rx_GetKsvInfo(H2uint8 *Devices, H2uint8 *Depth, H2uint8 *DevicesExceeded, H2uint8 *DepthExceeded, H2uint8 *pKSVs)
{
	unsigned char Buff[5 * MAX_DEVICECOUNT + 16];
	int ret = read_binary_file("/tmp/ksv_list.bin", Buff, sizeof(Buff));
	H2DBGLOG((LOCALDBG, "ReadKSVData=%d\n", ret));
	if (ret < 6) {
		gKsvInfo.DeviceCount = 0;
		gKsvInfo.Depth = 0;
		gKsvInfo.DevicesExceeded = 0;
		gKsvInfo.DepthExceeded = 0;
		memset(gKsvInfo.Ksvs, 0, sizeof(gKsvInfo.Ksvs));
	} else {
		gKsvInfo.DeviceCount = ret / 5;
		gKsvInfo.Depth = Buff[0] + 1;
		gKsvInfo.DevicesExceeded = (gKsvInfo.DeviceCount > H2_MAX_DEVICECOUNT) ? 1 : 0;
		gKsvInfo.DepthExceeded = (gKsvInfo.Depth > 4) ? 1 : 0;
		memcpy(gKsvInfo.Ksvs, &Buff[1], gKsvInfo.DeviceCount * 5);
	}
	if (Devices) {
		H2DBGLOG((LOCALDBG, "Device Count: %u\r\n", gKsvInfo.DeviceCount));
		*Devices = gKsvInfo.DeviceCount;
	}
	if (Depth) {
		H2DBGLOG((LOCALDBG, "Depth: %u\r\n", gKsvInfo.Depth));
		*Depth = gKsvInfo.Depth;
	}
	if (DevicesExceeded) {
		H2DBGLOG((LOCALDBG, "Devices Exceeded: %u\r\n", gKsvInfo.DevicesExceeded));
		*DevicesExceeded = gKsvInfo.DevicesExceeded;
	}
	if (DepthExceeded) {
		H2DBGLOG((LOCALDBG, "Depth Exceeded: %u\r\n", gKsvInfo.DepthExceeded));
		*DepthExceeded = gKsvInfo.DepthExceeded;
	}
	if (pKSVs && !gKsvInfo.DevicesExceeded && !gKsvInfo.DepthExceeded) {
		H2DBGLOG((LOCALDBG, "Copying %u KSVs\r\n", gKsvInfo.DeviceCount));
		memcpy(pKSVs, gKsvInfo.Ksvs, gKsvInfo.DeviceCount * 5);
	}
	return H2_OK;
}

/**
 * Set Ks^lc128. (for decryptor test only...)
 */
H2status hdcp2_Rx_SetKsXorLc128(const H2uint8 *AESKey)
{
	spu_SetKsXorLc128(AESKey);
	return H2_OK;
}

/**
 * Copy Rn to Session Secrets.
 */
H2status hdcp2_Rx_decrypt(H2uint8 InputCtr[12], H2uint8 *pData, H2uint32 Len)
{
	unsigned char IV[16];
	spu_GetRiv(IV);
	IV[4] ^= InputCtr[0];
	IV[5] ^= InputCtr[1];
	IV[6] ^= InputCtr[2];
	IV[7] ^= InputCtr[3];
	memcpy(&IV[8], &InputCtr[4], 8);
	RTK_RCP_AES_CTR_Decryption(KEY_CW(SRAM_KS_XOR_LC128_ENTRY), IV, pData, pData, Len);
	memcpy(&InputCtr[4], &IV[8], 8);
	return H2_OK;
}

H2status hdcp2_save_encrypted_keyset(unsigned char *pKeySet, unsigned char *dst_file_path, int keyLength)
{
	unsigned char *output_tmpBuff = NULL;
	unsigned char iv[16];
	unsigned int key[4];
	H2status rc;
	output_tmpBuff = kcalloc(1024, sizeof(unsigned char), GFP_KERNEL);
	if (output_tmpBuff == NULL) {
		return H2_ERROR;
	}
	memset(output_tmpBuff, 0, 1024);
	if (pKeySet == NULL || dst_file_path == NULL)
		return H2_ERROR;
	spu_SetLc128(pKeySet);
	spu_SetCertRx(&pKeySet[16]);
	spu_SetKPrivRx(&pKeySet[16 + 522]);
	key[0] = HDCP2X_AES_KEY_0;
	key[1] = HDCP2X_AES_KEY_1;
	key[2] = HDCP2X_AES_KEY_2;
	key[3] = HDCP2X_AES_KEY_3;
	memset(iv, 0, sizeof(iv));
	RTK_RCP_AES_CBC_Encryption((unsigned char *)key, (unsigned char *)iv, pKeySet, output_tmpBuff, keyLength);

	 rc = write_binary_file(dst_file_path, output_tmpBuff, keyLength);
	if (output_tmpBuff) {
		kfree(output_tmpBuff);
		output_tmpBuff = NULL;
	}
	return rc;
}

H2status hdcp2_load_encrypted_keyset(unsigned char *pKeySet, unsigned char *src_file_path, int keyLength)
{
	unsigned char *tmpBuff = NULL;
	unsigned char iv[16];
	unsigned int key[4];
	tmpBuff = kcalloc(1024, sizeof(unsigned char), GFP_KERNEL);
	if (tmpBuff == NULL) {
		return H2_ERROR;
	}
	memset(tmpBuff, 0, 1024);
	if (pKeySet == NULL || src_file_path == NULL)
		return H2_ERROR;
	key[0] = HDCP2X_AES_KEY_0;
	key[1] = HDCP2X_AES_KEY_1;
	key[2] = HDCP2X_AES_KEY_2;
	key[3] = HDCP2X_AES_KEY_3;
	memset(iv, 0, sizeof(iv));
	read_binary_file(src_file_path, tmpBuff, keyLength);

	RTK_RCP_AES_CBC_Decryption((unsigned char *)key, (unsigned char *)iv, tmpBuff, pKeySet, keyLength);
	if (tmpBuff) {
		kfree(tmpBuff);
		tmpBuff = NULL;
	}
	return H2_OK;
}

H2status hdcp2_save_keyset_file(unsigned char *pKeySet, unsigned char *dst_file_path, int keyLength)
{
	H2status rc;
	if(dst_file_path == NULL || keyLength == 0)
	{
		pr_emerg("rhal don't save keyset to file\n");
		return H2_OK;
	}
	rc = write_binary_file(dst_file_path, pKeySet, keyLength);
	
	return rc;
}

H2status hdcp2_load_keyset_file(unsigned char *pKeySet, unsigned char *src_file_path, int keyLength)
{
	if(src_file_path == NULL || keyLength == 0)
	{
		pr_emerg("rhal don't load keyset from file\n");
		return H2_OK;
	}
	read_binary_file(src_file_path, pKeySet, keyLength);

	return H2_OK;
}

H2status hdcp2_save_keyset(unsigned char *pKeySet)
{
	spu_SetLc128(pKeySet);
	spu_SetCertRx(&pKeySet[16]);
	spu_SetKPrivRx(&pKeySet[16 + 522]);

	return H2_OK;
}

//USER : zhaodong_yin DATE : 2016/04/07
//to fix HDCP 2.2 handshake error
H2status Compute_Kh_hdmi(const H2uint8 *Kpriv_rx, int Kprivrx_len)
{
	H2status rc = H2_ERROR;

	H2Sha256Ctx_t c;
	unsigned char tmp[128];
	unsigned char kh[KH_SIZE];

	do {
		H2DBGLOG((LOCALDBG, "HDCP-Sink(Rx): Compute_Kh\n"));

		if (Kpriv_rx == NULL) {
			H2DBGLOG((WARN, "ERROR! Compute_Kh: Invalid Input parameters"));
			break;
		}

		crypto_sha256Init(&c);
		crypto_sha256Update(&c, Kpriv_rx, KPRIVRX_SIZE);
		crypto_sha256Final(&c, tmp);
		memcpy(kh, &tmp[16], KH_SIZE);
		spu_SetKH(kh);
		rc = H2_OK;
	} while (0);

	return rc;
}

#define HDCP22_len	878
H2status hdcp2_load_from_flash()
{
	unsigned char hdcp22_buf[HDCP22_len];
#ifdef CONFIG_RTK_KDRV_HDCP_KEY_FROM_OTP
	if(get_hdcp_22_otp(hdcp22_buf,HDCP22_len) == 0)
	{
		pr_notice("hdcp22 get key form otp...............\n");
		spu_SetLc128(hdcp22_buf);
		spu_SetCertRx(&hdcp22_buf[16]);
		spu_SetKPrivRx(&hdcp22_buf[16+522]);
		Compute_Kh_hdmi(&hdcp22_buf[16+522], KPRIVRX_SIZE);
	}
	else
#endif
	{
//		pr_notice("hdcp22 get key form otp error, warning!!!\n");
//		return H2_ERROR;
#ifdef CONFIG_HDCP2_USE_DEFAULT_HDCP_KEY //use internal hdcp2.2 key
	   	// save data in SRAM....
	   	spu_SetLc128(&CTS_key[4]);
	    	//spu_printBytes_with_text(&tmp[16], 522, "hdcp2_load_from_flash : CertRx :");
	    	spu_SetCertRx(&CTS_key[40]);
	    	pr_notice("Device ID = %x %x %x %x  %x \n ",CTS_key[40],CTS_key[41],CTS_key[42],CTS_key[43],CTS_key[44]);
	    	spu_SetKPrivRx(&CTS_key[40+522]);
                Compute_Kh_hdmi(&CTS_key[40+522],KPRIVRX_SIZE);
#else
		pr_emerg("hdcp2 default key can't use!\n");
#endif
	}
	return H2_OK;

}

H2status hdcp2_load_from_file(unsigned char *pKeySet, unsigned char *src_file_path, int keyLength)
{
	hdcp2_load_encrypted_keyset(pKeySet, src_file_path, keyLength);

	    /* save data in SRAM....  */
	spu_SetLc128(pKeySet);
	spu_SetCertRx(&pKeySet[16]);
	spu_SetKPrivRx(&pKeySet[16 + 522]);
	return H2_OK;
}
H2status hdcp2_load_from_ap(unsigned char* hdcp22_buf)
{
	    /* save data in SRAM....  */
	spu_SetLc128(&hdcp22_buf[4]);
	spu_SetCertRx(&hdcp22_buf[40]);
	pr_notice("hdcp2_load_from_AP Device ID = %x %x %x %x  %x \n ",hdcp22_buf[40],hdcp22_buf[41],hdcp22_buf[42],hdcp22_buf[43],hdcp22_buf[44]);
	spu_SetKPrivRx(&hdcp22_buf[40+522]);
	Compute_Kh_hdmi(&hdcp22_buf[40+522],KPRIVRX_SIZE);
	return H2_OK;
}
H2status hdcp2_Verify_EdkeyKs(unsigned char *pEks, unsigned char *rrx, unsigned char *rtx, unsigned char *rn, int modeHDCP22)
{
	unsigned char Dkey2[DKEY_SIZE];
	unsigned char ks[KS_SIZE];
	unsigned char temp[DKEY_SIZE];
	unsigned char rrx_temp[DKEY_SIZE];
	hdcp2_Rx_GetKs(ks, KS_SIZE);
	if (rn == NULL || rtx == NULL || rrx == NULL)
		return H2_ERROR;
	RCP_HDCP2_GenDKey(SRAM_KM_ENTRY, rtx, rrx, rn, 2, SRAM_DK2_ENTRY, modeHDCP22);
	spu_GetDKey2(Dkey2);

	memset(rrx_temp, 0, sizeof(rrx_temp));
	memcpy(rrx_temp + DKEY_SIZE - RRX_SIZE, rrx, RRX_SIZE);
	crypt_xor(rrx_temp, Dkey2, temp, DKEY_SIZE);
	crypt_xor(temp, ks, pEks, DKEY_SIZE);

	return H2_OK;
}

H2status hdcp2_GenKsXorLc128()
{
	unsigned char lc[LC128_SIZE];
	unsigned char ks[KS_SIZE];
	unsigned char ksxorLc[16];
	spu_GetLc128(lc);
	hdcp2_Rx_GetKs(ks, KS_SIZE);
	xor_array(lc, ks, ksxorLc, 16);
	spu_SetKsXorLc128(ksxorLc);
	return H2_OK;
}

H2status hdcp2_Rx_Setdevinfo(unsigned char *deviceOptionInfo)
{
	if(deviceOptionInfo == NULL)
		return H2_ERROR;
	HDCP2_DEVICE_INFO.rx_version = deviceOptionInfo[0];
	HDCP2_DEVICE_INFO.rx_capability_mask = deviceOptionInfo[1] << 8 | deviceOptionInfo[2];
	HDCP2_DEVICE_INFO.tx_version = deviceOptionInfo[3];
	HDCP2_DEVICE_INFO.tx_capability_mask = deviceOptionInfo[4] << 8 | deviceOptionInfo[5];
	return H2_OK;
}

unsigned char hdcp2_get_txversion(void)
{
	return HDCP2_DEVICE_INFO.tx_version;
}

unsigned char hdcp2_get_precompute(void)
{
	unsigned char tx_precompute = HDCP2_DEVICE_INFO.tx_capability_mask & 0x1;
	unsigned char rx_precompute = HDCP2_DEVICE_INFO.rx_capability_mask & 0x1;
	return tx_precompute & rx_precompute;
}

H2status hdcp2_copy_paramter(HDCP2_PM_PARAMTER *hdcp2_data)
{
	if (hdcp2_data == NULL)
		return H2_ERROR;
	//memcpy((unsigned char *)hdcp2_data, (unsigned char *)(&SessionSecrets_Rx), sizeof(SessionSecrets_Rx));
	spu_GetLc128(hdcp2_data->lc128);
	spu_GetCertRx(hdcp2_data->certRx);
	spu_GetKPrivRx(hdcp2_data->kPrivRx);
	spu_GetKH(hdcp2_data->kh);
	spu_GetKM(hdcp2_data->km);
	spu_GetKD(hdcp2_data->kd);
	spu_GetDKey2(hdcp2_data->dkey2);
	spu_GetKsXorLc128(hdcp2_data->ksXorLc128);
	spu_GetRiv(hdcp2_data->riv);
	return H2_OK;
}

H2status hdcp2_recover_paramter(HDCP2_PM_PARAMTER *hdcp2_data)
{
	if (hdcp2_data == NULL)
		return H2_ERROR;
	//memcpy((unsigned char *)(&SessionSecrets_Rx), (unsigned char *)hdcp2_data, sizeof(SessionSecrets_Rx));
	spu_SetLc128(hdcp2_data->lc128);
	spu_SetCertRx(hdcp2_data->certRx);
	spu_SetKPrivRx(hdcp2_data->kPrivRx);
	spu_SetKH(hdcp2_data->kh);
	spu_SetKM(hdcp2_data->km);
	spu_SetKD(hdcp2_data->kd);
	spu_SetDKey2(hdcp2_data->dkey2);
	spu_SetKsXorLc128(hdcp2_data->ksXorLc128);
	spu_SetRiv(hdcp2_data->riv);
	return H2_OK;
}

void hdcp2_get_lc128(unsigned char *p_lc128)
{
	spu_GetLc128(p_lc128);
}

#endif
