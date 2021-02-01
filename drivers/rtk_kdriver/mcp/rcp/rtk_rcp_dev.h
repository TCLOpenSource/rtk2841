#ifndef __RTK_RCP_DEV_H__
#define __RTK_RCP_DEV_H__

#define RCP_DEV_NAME        "rcp_core"

#define RCP_MODE(x)             ((x) & 0x1F)

#define RCP_ALGO_AES                        0x0
#define RCP_ALGO_TDES                      0x1
#define RCP_ALGO_DES                        0x2
#define RCP_ALGO_SHA_256                0x3
#define RCP_ALGO_AES_192                0x4
#define RCP_ALGO_AES_256                0x7
#define RCP_ALGO_CAM                       0x8
#define RCP_ALGO_CAM_192                0x9
#define RCP_ALGO_CAM_256                0xa
#define RCP_ALGO_CW_LOGIC             0xF
#define RCP_ALGO_CW_OPSEL             0x10



#define RCP_ENDE(x)                           (((x) >> 5) & 0x1)
#define RCP_ENC                                 1
#define RCP_DEC                                 0

#define RCP_CW_OPSEL(x)                  (((x) >> 5) & 0x1)
#define GET_CW                          0x1
#define SET_CW                           0x0


#define RCP_BCM(x)                            (((x) >> 6) & 0x3)
#define RCP_BCM_ECB                         0x0
#define RCP_BCM_CBC                         0x1
#define RCP_BCM_CTR                         0x2

#define RCP_CW_LOGIC(x)                 (((x) >> 6) & 0x3)
#define RCP_CW_LOGIC_AND                0x0
#define RCP_CW_LOGIC_OR                 0x1
#define RCP_CW_LOGIC_XOR                0x2

#define RCP_KEY_FROM(x)                 (((x) >> 20) & 0x3)
#define RCP_KEY_FROM_OTP                0x0
#define RCP_KEY_FROM_CW                 0x1
#define RCP_KEY_FROM_DDR                0x2

#define RCP_IV_FROM(x)                 (((x) >> 22) & 0x3)
#define RCP_IV_FROM_OTP                0x0
#define RCP_IV_FROM_CW                 0x1
#define RCP_IV_FROM_DDR                0x2

#define RCP_IV_POST_CRYPT(x)                 (((x) >> 24) & 0x1)
#define RCP_IV_NO_UPDATE                0x0
#define RCP_IV_NEED_UPDATE                 0x1

/*Only for AES Ctr algorithm*/
#define RCP_CHECK_ADDR_ALIGN(x)         (((x) >> 25) & 0x1)
#define RCP_NO_CHECK_ADDR_ALIGN                0
#define RCP_NEED_CHECK_ADDR_ALIGN              1


#define RCP_IOCTL_DO_COMMAND     0x70000a00


typedef struct {
    unsigned char *key;
    unsigned char *iv;
    unsigned int flags;
    unsigned int    len;
    unsigned char *data_in;
    unsigned char *data_out;
    unsigned int out_len;
    unsigned char addr_align; /*the old AES CTR cipher need this, I don't know why.*/
} RCP_DESC;

typedef struct {
    unsigned char key[32];
    unsigned char iv[32];
    unsigned int flags;
    unsigned int    len;
    unsigned char *data_in;
    unsigned char *data_out;
    unsigned int out_len;
} RCP_DESC_USER;



extern __init int rtk_rcp_dev_init(void);
extern  __exit void rtk_rcp_dev_exit(void);
#endif
