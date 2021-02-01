#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/string.h>
#include <rtk_kdriver/rtk_otp_util.h>
#include <rtk_kdriver/rtk_mcp.h>
#include <rtk_kdriver/rtk_hdcp_otp_util.h>
#include <rtk_kdriver/rtk_ecc_otp.h>

#define HDCP_Private_Key_Offset	645//bit:5160~7719
#define HDCP_BKSB_Key_Offset 640//bit:5120~ 5159
#define HDCP_Private_Key_Len 320
#define HDCP_BKSB_Key_Len	5
#define HDCP_14_Len	325

#define HDCP22_len	878
#define HDCP22_1_878_offset 1024 // bit:8192~15215
#define HDCP22_RECEIVE_ID_offset	1902 // bit:15216~15255
#define HDCP22_RECEIVE_ID_len	5
#define HDCP22_SHA1_len	842

static unsigned int ini_key[4] = {0, 0, 0, 0};
static unsigned int h_key[4] = {0x39dfc22d, 0xd0210342, 0x233ff1ce, 0x959d0274};

#define SHA1_SUM_POS	-0x20
#define SHA1_SUM_LEN	20

/*
 * 32-bit integer manipulation macros (big endian)
 */
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i) {				\
	(n) = ( (unsigned long) (b)[(i)    ] << 24 )	\
	    | ( (unsigned long) (b)[(i) + 1] << 16 )	\
	    | ( (unsigned long) (b)[(i) + 2] <<  8 )	\
	    | ( (unsigned long) (b)[(i) + 3]       );	\
}
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i) {				\
	(b)[(i)    ] = (unsigned char) ( (n) >> 24 );	\
	(b)[(i) + 1] = (unsigned char) ( (n) >> 16 );	\
	(b)[(i) + 2] = (unsigned char) ( (n) >>  8 );	\
	(b)[(i) + 3] = (unsigned char) ( (n)       );	\
}
#endif

/**
 * \brief	   SHA-1 context structure
 */
typedef struct
{
    unsigned long total[2];	/*!< number of bytes processed	*/
    unsigned long state[5];	/*!< intermediate digest state	*/
    unsigned char buffer[64];	/*!< data block being processed */
}
sha1_context;

/*
 * SHA-1 context setup
 */
void sha1_starts (sha1_context * ctx)
{
	ctx->total[0] = 0;
	ctx->total[1] = 0;

	ctx->state[0] = 0x67452301;
	ctx->state[1] = 0xEFCDAB89;
	ctx->state[2] = 0x98BADCFE;
	ctx->state[3] = 0x10325476;
	ctx->state[4] = 0xC3D2E1F0;
}

static void sha1_process (sha1_context * ctx, unsigned char data[64])
{
	unsigned long temp, W[16], A, B, C, D, E;

	GET_UINT32_BE (W[0], data, 0);
	GET_UINT32_BE (W[1], data, 4);
	GET_UINT32_BE (W[2], data, 8);
	GET_UINT32_BE (W[3], data, 12);
	GET_UINT32_BE (W[4], data, 16);
	GET_UINT32_BE (W[5], data, 20);
	GET_UINT32_BE (W[6], data, 24);
	GET_UINT32_BE (W[7], data, 28);
	GET_UINT32_BE (W[8], data, 32);
	GET_UINT32_BE (W[9], data, 36);
	GET_UINT32_BE (W[10], data, 40);
	GET_UINT32_BE (W[11], data, 44);
	GET_UINT32_BE (W[12], data, 48);
	GET_UINT32_BE (W[13], data, 52);
	GET_UINT32_BE (W[14], data, 56);
	GET_UINT32_BE (W[15], data, 60);

#define S(x,n)	((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))

#define R(t) (						\
	temp = W[(t -  3) & 0x0F] ^ W[(t - 8) & 0x0F] ^	\
	       W[(t - 14) & 0x0F] ^ W[ t      & 0x0F],	\
	( W[t & 0x0F] = S(temp,1) )			\
)

#define P(a,b,c,d,e,x)	{				\
	e += S(a,5) + F(b,c,d) + K + x; b = S(b,30);	\
}

	A = ctx->state[0];
	B = ctx->state[1];
	C = ctx->state[2];
	D = ctx->state[3];
	E = ctx->state[4];

#define F(x,y,z) (z ^ (x & (y ^ z)))
#define K 0x5A827999

	P (A, B, C, D, E, W[0]);
	P (E, A, B, C, D, W[1]);
	P (D, E, A, B, C, W[2]);
	P (C, D, E, A, B, W[3]);
	P (B, C, D, E, A, W[4]);
	P (A, B, C, D, E, W[5]);
	P (E, A, B, C, D, W[6]);
	P (D, E, A, B, C, W[7]);
	P (C, D, E, A, B, W[8]);
	P (B, C, D, E, A, W[9]);
	P (A, B, C, D, E, W[10]);
	P (E, A, B, C, D, W[11]);
	P (D, E, A, B, C, W[12]);
	P (C, D, E, A, B, W[13]);
	P (B, C, D, E, A, W[14]);
	P (A, B, C, D, E, W[15]);
	P (E, A, B, C, D, R (16));
	P (D, E, A, B, C, R (17));
	P (C, D, E, A, B, R (18));
	P (B, C, D, E, A, R (19));

#undef K
#undef F

#define F(x,y,z) (x ^ y ^ z)
#define K 0x6ED9EBA1

	P (A, B, C, D, E, R (20));
	P (E, A, B, C, D, R (21));
	P (D, E, A, B, C, R (22));
	P (C, D, E, A, B, R (23));
	P (B, C, D, E, A, R (24));
	P (A, B, C, D, E, R (25));
	P (E, A, B, C, D, R (26));
	P (D, E, A, B, C, R (27));
	P (C, D, E, A, B, R (28));
	P (B, C, D, E, A, R (29));
	P (A, B, C, D, E, R (30));
	P (E, A, B, C, D, R (31));
	P (D, E, A, B, C, R (32));
	P (C, D, E, A, B, R (33));
	P (B, C, D, E, A, R (34));
	P (A, B, C, D, E, R (35));
	P (E, A, B, C, D, R (36));
	P (D, E, A, B, C, R (37));
	P (C, D, E, A, B, R (38));
	P (B, C, D, E, A, R (39));

#undef K
#undef F

#define F(x,y,z) ((x & y) | (z & (x | y)))
#define K 0x8F1BBCDC

	P (A, B, C, D, E, R (40));
	P (E, A, B, C, D, R (41));
	P (D, E, A, B, C, R (42));
	P (C, D, E, A, B, R (43));
	P (B, C, D, E, A, R (44));
	P (A, B, C, D, E, R (45));
	P (E, A, B, C, D, R (46));
	P (D, E, A, B, C, R (47));
	P (C, D, E, A, B, R (48));
	P (B, C, D, E, A, R (49));
	P (A, B, C, D, E, R (50));
	P (E, A, B, C, D, R (51));
	P (D, E, A, B, C, R (52));
	P (C, D, E, A, B, R (53));
	P (B, C, D, E, A, R (54));
	P (A, B, C, D, E, R (55));
	P (E, A, B, C, D, R (56));
	P (D, E, A, B, C, R (57));
	P (C, D, E, A, B, R (58));
	P (B, C, D, E, A, R (59));

#undef K
#undef F

#define F(x,y,z) (x ^ y ^ z)
#define K 0xCA62C1D6

	P (A, B, C, D, E, R (60));
	P (E, A, B, C, D, R (61));
	P (D, E, A, B, C, R (62));
	P (C, D, E, A, B, R (63));
	P (B, C, D, E, A, R (64));
	P (A, B, C, D, E, R (65));
	P (E, A, B, C, D, R (66));
	P (D, E, A, B, C, R (67));
	P (C, D, E, A, B, R (68));
	P (B, C, D, E, A, R (69));
	P (A, B, C, D, E, R (70));
	P (E, A, B, C, D, R (71));
	P (D, E, A, B, C, R (72));
	P (C, D, E, A, B, R (73));
	P (B, C, D, E, A, R (74));
	P (A, B, C, D, E, R (75));
	P (E, A, B, C, D, R (76));
	P (D, E, A, B, C, R (77));
	P (C, D, E, A, B, R (78));
	P (B, C, D, E, A, R (79));

#undef K
#undef F

	ctx->state[0] += A;
	ctx->state[1] += B;
	ctx->state[2] += C;
	ctx->state[3] += D;
	ctx->state[4] += E;
}

/*
 * SHA-1 process buffer
 */
void sha1_update (sha1_context * ctx, unsigned char *input, int ilen)
{
	int fill;
	unsigned long left;

	if (ilen <= 0)
		return;

	left = ctx->total[0] & 0x3F;
	fill = 64 - left;

	ctx->total[0] += ilen;
	ctx->total[0] &= 0xFFFFFFFF;

	if (ctx->total[0] < (unsigned long) ilen)
		ctx->total[1]++;

	if (left && ilen >= fill) {
		memcpy ((void *) (ctx->buffer + left), (void *) input, fill);
		sha1_process (ctx, ctx->buffer);
		input += fill;
		ilen -= fill;
		left = 0;
	}

	while (ilen >= 64) {
		sha1_process (ctx, input);
		input += 64;
		ilen -= 64;
	}

	if (ilen > 0) {
		memcpy ((void *) (ctx->buffer + left), (void *) input, ilen);
	}
}

static const unsigned char sha1_padding[64] = {
	0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*
 * SHA-1 final digest
 */
void sha1_finish (sha1_context * ctx, unsigned char output[20])
{
	unsigned long last, padn;
	unsigned long high, low;
	unsigned char msglen[8];

	high = (ctx->total[0] >> 29)
		| (ctx->total[1] << 3);
	low = (ctx->total[0] << 3);

	PUT_UINT32_BE (high, msglen, 0);
	PUT_UINT32_BE (low, msglen, 4);

	last = ctx->total[0] & 0x3F;
	padn = (last < 56) ? (56 - last) : (120 - last);

	sha1_update (ctx, (unsigned char *) sha1_padding, padn);
	sha1_update (ctx, msglen, 8);

	PUT_UINT32_BE (ctx->state[0], output, 0);
	PUT_UINT32_BE (ctx->state[1], output, 4);
	PUT_UINT32_BE (ctx->state[2], output, 8);
	PUT_UINT32_BE (ctx->state[3], output, 12);
	PUT_UINT32_BE (ctx->state[4], output, 16);
}

/*
 * Output = SHA-1( input buffer )
 */
void sha1_csum (unsigned char *input, int ilen, unsigned char output[20])
{
	sha1_context ctx;

	sha1_starts (&ctx);
	sha1_update (&ctx, input, ilen);
	sha1_finish (&ctx, output);
}

void hdcp_otp_hexdump(const void *buf, unsigned int length)
{
	unsigned int i;
	unsigned char *ptr = (unsigned char *)buf;

	if ((buf == NULL) || (length == 0))
	{
		printk("NULL\n");
		return;
	}

	printk("===> %s(0x%x, 0x%x):\n", __FUNCTION__, (unsigned int)buf, length);
	for (i = 0; i < length; i++)
	{
		printk("%02X ", ptr[i]);

		if ((i & 0xf) == 0xf)
		{
			printk("\n");
		}
	}
	printk("\n");
}

int get_hdcp_14_otp(unsigned char *buf,unsigned int len)
{
	unsigned char hdcp_buf[HDCP_14_Len];
	unsigned char hdcp_cmp_buf[HDCP_14_Len];

	if(len < HDCP_14_Len){
		hdcp_otp_err("len error; len = %d ,HDCP_14_Len = %d\n",len,HDCP_14_Len);
		return -1;
	}
	memset((unsigned char *)hdcp_buf,0x00,HDCP_14_Len);
	memset((unsigned char *)hdcp_cmp_buf,0x00,HDCP_14_Len);

	if(otp_ecc_util_get_hdcp_1_4(hdcp_buf, HDCP_14_Len, 1)) //read KSV + encrypted part
	{
		hdcp_otp_err("read otp fail!\n");
		return -1;	
	}

	if(memcmp((void *)hdcp_cmp_buf,(void *)hdcp_buf,HDCP_14_Len) == 0){
		hdcp_otp_err("hdcp1.4 in otp not burn!\n");
		return -1;
	}	

	memcpy(buf,hdcp_buf,HDCP_14_Len);
	
#ifdef HDCP_OTP_DEBUG
	hdcp_otp_hexdump(buf,HDCP_14_Len);
#endif

	return 0;
}

int get_hdcp_22_otp(unsigned char *buf,unsigned int len)
{
	unsigned char hdcp_buf[HDCP22_len];
	unsigned char hdcp_cmp_buf[HDCP22_len];
	unsigned char hdcp_sha1_buf[HDCP22_SHA1_len + 64];
	unsigned char receive_id_buf[HDCP22_RECEIVE_ID_len];
	unsigned char sha1_buf[SHA1_DIGEST_SIZE];

	unsigned char *ptr = hdcp_buf;
	unsigned int read_len = 0;
	
	if(len < (HDCP22_len - 20)){
		hdcp_otp_err("len error; len = %d ,HDCP22_len = %d\n",len,HDCP22_len);
		return -1;
	}

	read_len = (len > HDCP22_len) ? HDCP22_len : len;

	memset((void *)hdcp_buf,0,HDCP22_len);
	memset((void *)hdcp_cmp_buf,0,HDCP22_len);
	memset((void *)hdcp_sha1_buf,0,HDCP22_SHA1_len + 64);
	memset((void *)sha1_buf,0,SHA1_DIGEST_SIZE);
	
	if(otp_ecc_util_get_hdcp_2_2(ptr, HDCP22_len, 0) < 0)//only read encrypted part
	{
		hdcp_otp_err("read otp fail!\n");
		return -1;
	}

	if(memcmp((void *)hdcp_buf,(void *)hdcp_cmp_buf,HDCP22_len) == 0){
		hdcp_otp_err("hdcp2.2 in otp not burn!\n");
		return -1;
	}

#ifdef HDCP_OTP_DEBUG
	printk("hdcp2.2 int OTP:\n");
	hdcp_otp_hexdump(hdcp_buf,HDCP22_len);
#endif

	if(MCP_AES_CBC_Decryption(h_key,ini_key,hdcp_buf,hdcp_buf,HDCP22_len)<0){
		hdcp_otp_err("decrpyt hdcp2.2 fail!\n");
		return -1;
	}
	memcpy(hdcp_cmp_buf,hdcp_buf,HDCP22_len);
#ifdef HDCP_OTP_DEBUG
		printk("hdcp2.2 decode:\n");
		hdcp_otp_hexdump(hdcp_cmp_buf,HDCP22_len);
#endif
	memcpy(hdcp_sha1_buf,&hdcp_cmp_buf[16],HDCP22_SHA1_len);

#ifdef HDCP_OTP_DEBUG
			printk("hdcp_sha1_buf:\n");
			hdcp_otp_hexdump(hdcp_sha1_buf,HDCP22_SHA1_len);
#endif
	sha1_csum(hdcp_sha1_buf,HDCP22_SHA1_len,sha1_buf);
#ifdef HDCP_OTP_DEBUG
				printk("sha1_buf:\n");
				hdcp_otp_hexdump(sha1_buf,SHA1_DIGEST_SIZE);
#endif

	if(memcmp((void *)&hdcp_cmp_buf[HDCP22_len - 20],(void *)sha1_buf,SHA1_DIGEST_SIZE) !=0){
		hdcp_otp_err("check hdcp2.2 sha1 fail!\n");
		return -1;
	}


	memcpy(buf,hdcp_cmp_buf,read_len);

#ifdef HDCP_OTP_DEBUG
	hdcp_otp_hexdump(buf,read_len);
#endif

	return 0;
}

#ifdef HDCP_OTP_DEBUG
int hdcp_otp_test(void) 
{
	unsigned char hdcp22[HDCP22_len];
	unsigned char hdcp14[HDCP_14_Len];
	printk("\n\n\n\n *****************  hdcp otp test module  *********************\n\n\n\n");

	get_hdcp_14_otp(hdcp14,HDCP_14_Len);
	get_hdcp_22_otp(hdcp22,HDCP22_len);
}

module_init(hdcp_otp_test) ;
#endif

