#include <linux/string.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <rtk_kdriver/rtk_ecc_otp.h>
#include <rtk_kdriver/rtk_otp_util.h>
#include "rtk_ecc_algorithm.h"

int otp_ecc_util_get_adc(unsigned char *adc_buff, unsigned int len)
{
    int ret = 0;
    char *output = NULL;
    if(adc_buff == NULL || len < ADC_DATA_LEN)
        return -1;
    ret = otp_ecc_util_get_data_region(ADC_DATA_OFST, ADC_DATA_LEN,
                                       ECC_ADC_START_BIT, ECC_ADC_UNIT_BIT_NUM, 1, &output);
    if(ret == 0) {
        memcpy(adc_buff, output, ADC_DATA_LEN);
        FREE(output);
    }
    return ret;
}

int otp_ecc_util_get_rsa (unsigned char *rsa_buff, unsigned int len)
{
    int ret = 0;
    char *output =  NULL;
    if(rsa_buff == NULL || len < RSA_DATA_LEN)
        return -1;
    ret = otp_ecc_util_get_data_region(RSA_DATA_OFST, RSA_DATA_LEN,
                                       ECC_RSA_START_BIT, ECC_RSA_UNIT_BIT_NUM, 1, &output);
    if(ret == 0) {
        memcpy(rsa_buff, output, RSA_DATA_LEN);
        FREE(output);
    }
    return ret;
}

int otp_ecc_util_get_rsa_remk(
    unsigned char *rsa_remk_buff, unsigned int len)
{
    int ret = 0;
    char *output =  NULL;
    if(rsa_remk_buff == NULL || len < RSA_REMK_DATA_LEN)
        return -1;
    ret = otp_ecc_util_get_data_region(RSA_REMK_DATA_OFST, RSA_REMK_DATA_LEN,
                                       ECC_RSA_REMK_START_BIT, ECC_RSA_REMK_UNIT_BIT_NUM, 1, &output);
    if(ret == 0) {
        memcpy(rsa_remk_buff, output, RSA_REMK_DATA_LEN);
        FREE(output);
    }
    return ret;
}

int otp_ecc_util_get_device_unique_key(
    unsigned char *device_unique_key_buff, unsigned int len)
{
    int ret = 0;
    char *output =  NULL;
    if(device_unique_key_buff == NULL || len < DEVICE_UNIQUE_KEY_LEN)
        return -1;
    ret = otp_ecc_util_get_data_region(DEVICE_UNIQUE_KEY_OFST, DEVICE_UNIQUE_KEY_LEN,
                                       ECC_DEVICE_UNIQUE_KEY_START_BIT, ECC_DEVICE_UNIQUE_KEY_UNIT_BIT_NUM, 1, &output);
    if(ret == 0) {
        memcpy(device_unique_key_buff, output, DEVICE_UNIQUE_KEY_LEN);
        FREE(output);
    }
    return ret;
}

