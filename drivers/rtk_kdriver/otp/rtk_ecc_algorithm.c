#include <linux/string.h>
#include <rtk_kdriver/rtk_otp_util.h>
#include "rtk_ecc_algorithm.h"

#define BITS_PER_INT 32
#define BYTES_PER_INT 4
/* Only for 1024bits data
/* This function encode 1024bits data to 12bis ECC
/* intput parameter:
/*              char* orig_data : data bits (1024bits)
/*
/* output paramter:
/*      unsigned int* ecc_data bits (12bits)
/*
/* return value: 0 success, non-zero if failure.
*/
int EnHammingCode1024(char* orig_data, unsigned int* ecc_data)
{
    //int cnt;
    unsigned int paritybit_idx;
    unsigned int codebit_idx;
    unsigned int databit_idx;
    unsigned int paritybit_pattern;
    unsigned int tmpCheckbit;
    unsigned int lCnt, val, lBitOff;

    if(orig_data == NULL) {
        ECC_FUNC_WARNING("[Error] Empty data ponter!\n");
        return -1;
    }

    if(ecc_data == NULL) {
        ECC_FUNC_WARNING("[Error] Empty ecc data ponter!\n");
        return -2;
    }

    *ecc_data = 0;
    paritybit_idx = 0;
    while(paritybit_idx < THE_NUM_CHECK_1024_BITS) {
        // compare bit by code word
        codebit_idx = 0;
        databit_idx = 0;
        paritybit_pattern = 1;
        tmpCheckbit = 0;
        while(codebit_idx < (THE_NUM_CHECK_1024_BITS + THE_NUM_DATA_1024_BITS)) {
            if(codebit_idx != (paritybit_pattern - 1)) {
                if(((codebit_idx + 1) >> paritybit_idx) & 0x01)  {
                    tmpCheckbit ^= ((*(orig_data + ((databit_idx & 0xfffffff8) >> 3)) >> (databit_idx & 0x7)) & 0x01);
                }

                databit_idx++;
            } else {
                paritybit_pattern = paritybit_pattern << 1;
            }
            codebit_idx++;
        }
        *ecc_data |= ((tmpCheckbit & 0x01) << paritybit_idx);
        paritybit_idx++;
    }

    ECC_FUNC_DBG("ecc = %08x\n", *ecc_data);

    // Calculate the bits number in orig data & ECC data
    val = 0;
    for(lCnt = 0; lCnt < (THE_NUM_DATA_1024_BITS / 8); lCnt++)
        for(lBitOff = 0; lBitOff < 8; lBitOff++)
            if(*(orig_data + lCnt) & (1 << lBitOff))
                val++;

    for(lCnt = 0; lCnt < THE_NUM_CHECK_1024_BITS; lCnt++)
        if(*ecc_data & (1 << lCnt))
            val++;
    *ecc_data |= ((val & 0x01) << THE_NUM_CHECK_1024_BITS);

    return 0;
}



/* Only for 1024bits*/
int DeHammingCode1024(char* ptTrasmit_data, unsigned int ecc_data)
{
    ECC_CHECK_RESULT_TYPE ret = ECC_CHECK_RESULT_SUCC;
    unsigned int syn;
    unsigned int paritybit_pattern;
    unsigned int databit_idx;
    unsigned int codebit_idx;
    unsigned int get_bit_num_idx;

    // Compute syndrome
    syn = 0;
    paritybit_pattern = 0;
    get_bit_num_idx = 0;
    databit_idx = 0;
    for (codebit_idx = 0; codebit_idx < (THE_NUM_CHECK_1024_BITS + THE_NUM_DATA_1024_BITS); codebit_idx++) {
        if(codebit_idx != paritybit_pattern) {
            if(*(ptTrasmit_data + ((databit_idx & 0xfffffff8) >> 3)) & (1 << (databit_idx & 0x07))) {
                syn ^= (codebit_idx + 1);
                get_bit_num_idx++;
            }
            databit_idx++;
        } else {
            if(ecc_data & (paritybit_pattern + 1)) {
                syn ^= (codebit_idx + 1);
                get_bit_num_idx++;
            }

            paritybit_pattern = ((paritybit_pattern + 1) << 1) - 1;
        }
    }

    // Correct error if needed
    if(syn <= (THE_NUM_CHECK_1024_BITS + THE_NUM_DATA_1024_BITS)) {
        if (syn) {
            paritybit_pattern = 1;
            for(codebit_idx = 0; codebit_idx < THE_NUM_CHECK_1024_BITS; codebit_idx++) {
                if(syn  <=      paritybit_pattern)
                    break;
                paritybit_pattern = paritybit_pattern << 1;
            }

            if((get_bit_num_idx & 0x01) != ((ecc_data >> THE_NUM_CHECK_1024_BITS) & 0x01)) {
                if(paritybit_pattern == syn)
                    ecc_data ^= paritybit_pattern;
                else {
                    *(ptTrasmit_data + (((syn - codebit_idx - 1) & 0xfffffff8) >> 3)) ^= (1 << ((syn - codebit_idx - 1) & 0x07));
                    ret = ECC_CHECK_RESULT_FAIL_DATA_BUT_FIXED;
                }
                ECC_FUNC_WARNING("[Info] repaired ok\n");
            } else {
                ECC_FUNC_WARNING("[Error] unrepaired\n");
                ret = ECC_CHECK_RESULT_FAIL_BUT_NOT_FIXED;
            }
        } else {
            ECC_FUNC_WARNING("[Info] No error for data\n");
            ret = ECC_CHECK_RESULT_SUCC;
        }
    } else {
        ECC_FUNC_WARNING("[Error] Get Error syndrome\n");
        ret = ECC_CHECK_RESULT_FAIL_BUT_NOT_FIXED;
    }

    return ret;
}


/*
*Function:get the ecc check bits len
*Input:the check character data array len
*Ret:1-32 is valid
*
*/
static unsigned int get_ecc_check_bits_len(unsigned int char_array_len)
{
    int ecc_check_bits_len = 0;
    for(ecc_check_bits_len = 0; ecc_check_bits_len <= INTEGER_BITS_SIZE; ecc_check_bits_len++) {
        if(((1 << ecc_check_bits_len) - ecc_check_bits_len) >= (CHAR_BITS_SIZE * char_array_len + 1))
            break;
    }
    if(ecc_check_bits_len > INTEGER_BITS_SIZE)
        ecc_check_bits_len = 0;
    return ecc_check_bits_len;
}


/*
/* This function encode any bits data to specialbits ECC
/* intput parameter:
/*              orig_data : data bits
/*              orig_data_len:
/* output paramter:
/*      unsigned int* ecc_data bits (12bits)
/*
/* return value: 0 success, non-zero if failure.
*/
int EnHammingCode(unsigned char* orig_data, unsigned int orig_data_len,
                  unsigned int* ecc_data, unsigned int *ecc_data_bits_len)
{
    //int cnt;
    unsigned int paritybit_idx;
    unsigned int codebit_idx;
    unsigned int databit_idx;
    unsigned int paritybit_pattern;
    unsigned int tmpCheckbit;
    unsigned int lCnt, val, lBitOff;

    if(orig_data == NULL ||
       orig_data_len == 0) {
        ECC_FUNC_WARNING("[Error] Empty data ponter!\n");
        return -1;
    }

    if(ecc_data == NULL
       || ecc_data_bits_len == NULL) {
        ECC_FUNC_WARNING("[Error] Empty ecc data ponter!\n");
        return -1;
    }
    *ecc_data_bits_len = get_ecc_check_bits_len(orig_data_len);
    if(*ecc_data_bits_len == 0) {
        ECC_FUNC_WARNING("[Error] Can't get valid Ecc check bits len\n");
        return -1;
    }

    *ecc_data = 0;
    paritybit_idx = 0;
    while(paritybit_idx < *ecc_data_bits_len) {
        // compare bit by code word
        codebit_idx = 0;
        databit_idx = 0;
        paritybit_pattern = 1;
        tmpCheckbit = 0;
        while(codebit_idx < (*ecc_data_bits_len + orig_data_len * CHAR_BITS_SIZE)) {
            if(codebit_idx != (paritybit_pattern - 1)) {
                if(((codebit_idx + 1) >> paritybit_idx) & 0x01)  {
                    tmpCheckbit ^= ((*(orig_data + ((databit_idx & 0xfffffff8) >> 3)) >> (databit_idx & 0x7)) & 0x01);
                }

                databit_idx++;
            } else {
                paritybit_pattern = paritybit_pattern << 1;
            }
            codebit_idx++;
        }
        *ecc_data |= ((tmpCheckbit & 0x01) << paritybit_idx);
        paritybit_idx++;
    }

    ECC_FUNC_DBG("ecc = %08x\n", *ecc_data);

    // Calculate the bits number in orig data & ECC data
    val = 0;
    for(lCnt = 0; lCnt < orig_data_len; lCnt++)
        for(lBitOff = 0; lBitOff < 8; lBitOff++)
            if(*(orig_data + lCnt) & (1 << lBitOff))
                val++;

    for(lCnt = 0; lCnt < *ecc_data_bits_len; lCnt++)
        if(*ecc_data & (1 << lCnt))
            val++;
    ECC_FUNC_DBG("val = %08x\n", val);
    *ecc_data |= ((val & 0x01) << (*ecc_data_bits_len));
    /*Need to contain the whole Ecc check bits ,Even it
    *don't belong to the hamming code check bits range.
    */
    *ecc_data_bits_len = *ecc_data_bits_len + 1;
    return 0;
}


/* for any bits len*/
ECC_CHECK_RESULT_TYPE DeHammingCode(unsigned char* ptTrasmit_data, unsigned int ptTrasmit_data_len,
                                    unsigned int *p_ecc_data, unsigned int *p_ecc_check_error_bit_index)
{
    ECC_CHECK_RESULT_TYPE ret = ECC_CHECK_RESULT_SUCC;
    unsigned int syn;
    unsigned int paritybit_pattern;
    unsigned int databit_idx;
    unsigned int codebit_idx;
    unsigned int get_bit_num_idx;
    unsigned int ecc_data_bits_len;
    if(ptTrasmit_data == NULL || ptTrasmit_data_len == 0
       || p_ecc_data == NULL || p_ecc_check_error_bit_index == NULL) {
        ECC_FUNC_WARNING("[Error] Can't get valid Ecc check bits len\n");
        ret = ECC_CHECK_RESULT_IMPROPER_PARAM;
        return ret;
    }
    ecc_data_bits_len = get_ecc_check_bits_len(ptTrasmit_data_len);
    if(ecc_data_bits_len == 0) {
        ECC_FUNC_WARNING("[Error] Can't get valid Ecc check bits len\n");
        ret = ECC_CHECK_RESULT_IMPROPER_PARAM;
        return ret;
    }
    ECC_FUNC_DBG("ecc_data = %d\n", *p_ecc_data);
    // Compute syndrome
    syn = 0;
    paritybit_pattern = 0;
    get_bit_num_idx = 0;
    databit_idx = 0;
    for (codebit_idx = 0; codebit_idx < (ecc_data_bits_len + CHAR_BITS_SIZE * ptTrasmit_data_len); codebit_idx++) {
        if(codebit_idx != paritybit_pattern) {
            if(*(ptTrasmit_data + ((databit_idx & 0xfffffff8) >> 3)) & (1 << (databit_idx & 0x07))) {
                syn ^= (codebit_idx + 1);
                get_bit_num_idx++;
            }
            databit_idx++;
        } else {
            if(*p_ecc_data & (paritybit_pattern + 1)) {
                syn ^= (codebit_idx + 1);
                get_bit_num_idx++;
            }

            paritybit_pattern = ((paritybit_pattern + 1) << 1) - 1;
        }
    }
    ECC_FUNC_DBG("syndrome = %d\n", syn);

    // Correct error if needed
    if(syn <= (ecc_data_bits_len + CHAR_BITS_SIZE * ptTrasmit_data_len)) {
        if (syn) {
            paritybit_pattern = 1;
            for(codebit_idx = 0; codebit_idx < ecc_data_bits_len; codebit_idx++) {
                if(syn  <=      paritybit_pattern)
                    break;
                paritybit_pattern = paritybit_pattern << 1;
            }

            if((get_bit_num_idx & 0x01) != ((*p_ecc_data >> ecc_data_bits_len) & 0x01)) {
                if(paritybit_pattern == syn) {
                    *p_ecc_data ^= paritybit_pattern;
                    *p_ecc_check_error_bit_index = codebit_idx;
                    ret = ECC_CHECK_RESULT_FAIL_ECC_BUT_FIXED;

                } else {
                    *(ptTrasmit_data + (((syn - codebit_idx - 1) & 0xfffffff8) >> 3)) ^= (1 << ((syn - codebit_idx - 1) & 0x07));
                    *p_ecc_check_error_bit_index = (syn - codebit_idx - 1);
                    ret = ECC_CHECK_RESULT_FAIL_DATA_BUT_FIXED;
                }
                ECC_FUNC_WARNING("[Info] repaired ok\n");
            } else {
                ECC_FUNC_WARNING("[Error] unrepaired\n");
                ret = ECC_CHECK_RESULT_FAIL_BUT_NOT_FIXED;
            }
        } else {
            ECC_FUNC_WARNING("[Info] No error for data\n");
            ret = ECC_CHECK_RESULT_SUCC;
        }
    } else {
        ECC_FUNC_WARNING("[Error] Get Error syndrome\n");
        ret = ECC_CHECK_RESULT_FAIL_BUT_NOT_FIXED;
    }
    return ret;
}

static int read_ecc_bits(unsigned int ecc_bit_offset, unsigned int bits_num, unsigned int *ecc_value)
{
    int ret = -1;
    unsigned int reg_offset = (ecc_bit_offset / BITS_PER_INT) * 4;
    unsigned int reg_bit_offset = ecc_bit_offset % BITS_PER_INT;
    if(ecc_value == NULL || bits_num > 32)
        return ret;

    if((reg_bit_offset + bits_num) <= BITS_PER_INT) {
        ret = otp_read_bits(reg_offset, reg_bit_offset + bits_num - 1,
                            reg_bit_offset, ecc_value);
    } else {
        unsigned int tmp = 0;
        ret = otp_read_bits(reg_offset, BITS_PER_INT - 1, reg_bit_offset, &tmp);
        if(ret == 0) {
            ret = otp_read_bits(reg_offset + BYTES_PER_INT, bits_num +
                                reg_bit_offset - BITS_PER_INT - 1, 0, ecc_value);
            if(ret == 0)
                *ecc_value = (*ecc_value << (BITS_PER_INT - reg_bit_offset)) | tmp;
        }
    }
    return ret;
}

int do_ecc_check_util(ECC_CHECK_REGION *check_region)
{
    int ret = 0;
    int loops = 0;
    int i = 0;
    unsigned char *check_unit_data = NULL;
    unsigned int check_unit_data_len = 0;
    unsigned int check_ecc_offset = 0;
    unsigned int error_bit_index = 0;
    unsigned char *buffer = NULL;
    if(check_region == NULL || check_region->data == NULL ||
       check_region->len == 0 || check_region->ecc_unit_bit_num == 0)
        return -1;
    check_unit_data_len = (1 << (check_region->ecc_unit_bit_num - 2)) / 8;
    ECC_FUNC_DBG("%s, %d, check_unit_data_len == %d\n", check_unit_data_len);
    if(check_region->len % check_unit_data_len) {
        buffer = (unsigned char *)MALLOC(check_unit_data_len);
        if(!buffer)
            return -1;
    }
    loops = ((check_region->len - 1) / check_unit_data_len) + 1;
    for(i = 0; i < loops; i++) {
        unsigned int ecc_val = 0;
        check_ecc_offset = check_region->ecc_start_bit + check_region->ecc_unit_bit_num * i;
        if(i < (loops - 1)) {
            check_unit_data = check_region->data + check_unit_data_len * i;
        } else {
            if((check_region->len % check_unit_data_len) == 0) {
                check_unit_data = check_region->data + check_unit_data_len * i;
            } else {
                check_unit_data = buffer;
                memset(check_unit_data, 0, check_unit_data_len);
                memcpy(check_unit_data, check_region->data + check_unit_data_len * i,
                       check_region->len % check_unit_data_len);
            }
        }
        if(read_ecc_bits(check_ecc_offset, check_region->ecc_unit_bit_num, &ecc_val) != 0) {
            ECC_FUNC_WARNING("read ecc bits failed ,ecc offset= %08x\n", check_ecc_offset);
            ret = -1;
            break;
        }
        if((ecc_val == 0) && (check_region->flags & ECC_CHECK_INGORE_ECC_NOT_BURN))
            continue;

        ret = DeHammingCode(check_unit_data, check_unit_data_len, &ecc_val, &error_bit_index);
        if((ret == ECC_CHECK_RESULT_IMPROPER_PARAM) ||
           (ret == ECC_CHECK_RESULT_FAIL_BUT_NOT_FIXED)) {
            break;
        }
        ret = ECC_CHECK_RESULT_SUCC;
    }
    if(buffer)
        FREE(buffer);
    return ret;
}

static int check_data_burn(unsigned char *data, unsigned int len)
{
    int ret = -1;
    int i = 0;
    if(data == NULL || len == 0)
        return ret;
    for(i = 0; i < len; i++) {
        if(data[i] != 0) {
            ret = 0;
            break;
        }
    }
    return ret;
}

int do_get_data_region_with_ecc_check(
    ECC_INPUT_DATA_PARAM *params, unsigned char **output)
{
    int ret = -1;
    unsigned char *buffer = NULL;
    ECC_CHECK_REGION check_region;
    if(params == NULL || params->data_len == 0 ||
       params->ecc_unit_bit_num == 0 || output == NULL)
        return ret;
    memset(&check_region, 0, sizeof(check_region));
    buffer = (unsigned char *)MALLOC(params->data_len);
    if(buffer == NULL)
        return ret;
    memset(buffer, 0, params->data_len);
    if(otp_read_region_byte(params->data_ofst, buffer, params->data_len) != 0) {
        ECC_FUNC_WARNING("Read data failed, ofst = %08x, len == %d\n",
                         params->data_ofst, params->data_len);
        goto error;
    }
    if(check_data_burn(buffer, params->data_len) != 0) {
        ECC_FUNC_WARNING("Data not burn, ofst = %08x, len == %d\n",
                         params->data_ofst, params->data_len);
        goto error;
    }
    check_region.data = buffer;
    check_region.len = params->data_len;
    check_region.ecc_start_bit = params->ecc_start_bit;
    check_region.ecc_unit_bit_num = params->ecc_unit_bit_num;
    check_region.flags = params->flags;
    if(do_ecc_check_util(&check_region) != ECC_CHECK_RESULT_SUCC) {
        ECC_FUNC_WARNING("Data check failed, ofst = %08x, len == \n", params->data_ofst, params->data_len);
        goto error;
    }
    *output = buffer;
    return 0;
error:
    if(buffer)
        FREE(buffer);
    return ret;
}


int otp_ecc_util_get_data_region(unsigned int data_ofst, unsigned int data_len,
                                 unsigned int ecc_start_bit,
                                 unsigned int ecc_unit_bit_num,
                                 unsigned int ignore_ecc_not_burn,
                                 unsigned int **output)
{
    ECC_INPUT_DATA_PARAM param;
    if(!output)
        return -1;
    memset(&param, 0, sizeof(param));
    param.data_ofst = data_ofst;
    param.data_len = data_len;
    param.ecc_start_bit = ecc_start_bit;
    param.ecc_unit_bit_num = ecc_unit_bit_num;
    if(ignore_ecc_not_burn)
        param.flags = ECC_CHECK_INGORE_ECC_NOT_BURN;
    return do_get_data_region_with_ecc_check(&param, output);
}

