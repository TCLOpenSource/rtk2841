#ifndef _RTK_ECC_OTP_H_
#define _RTK_ECC_OTP_H_
#define ADC_DATA_OFST                               0x148
#define ADC_DATA_LEN                                92
#define ECC_ADC_START_BIT                           4000
#define ECC_ADC_UNIT_BIT_NUM                        12

#define DEVICE_UNIQUE_KEY_OFST                      0x1A4
#define DEVICE_UNIQUE_KEY_LEN                       16
#define ECC_DEVICE_UNIQUE_KEY_START_BIT             4012
#define ECC_DEVICE_UNIQUE_KEY_UNIT_BIT_NUM          9

#define RSA_DATA_OFST                               0x1B4
#define RSA_DATA_LEN                                32
#define ECC_RSA_START_BIT                           4021
#define ECC_RSA_UNIT_BIT_NUM                        10

#define RSA_REMK_DATA_OFST                          0x1D4
#define RSA_REMK_DATA_LEN                           32
#define ECC_RSA_REMK_START_BIT                      4031
#define ECC_RSA_REMK_UNIT_BIT_NUM                   10

extern int otp_ecc_util_get_adc(unsigned char *adc_buf, unsigned int len);
extern int otp_ecc_util_get_rsa(unsigned char *rsa_buf, unsigned int len);
extern int otp_ecc_util_get_rsa_remk(unsigned char *rsa_remk_buff,
                        unsigned int len);
extern int otp_ecc_util_get_device_unique_key(
                        unsigned char *device_unique_key_buff, unsigned int len);
#endif
