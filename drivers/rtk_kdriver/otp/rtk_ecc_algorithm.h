#ifndef _RTK_ECC_ALGORITHM_H_
#define _RTK_ECC_ALGORITHM_H_
#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include <mach/rtk_log.h>
#define MALLOC(x)     kmalloc(x, GFP_KERNEL)
#define FREE(x)          kfree(x)

#define INTEGER_BITS_SIZE       32
#define CHAR_BITS_SIZE  8

#define THE_NUM_CHECK_1024_BITS 11
#define THE_NUM_DATA_1024_BITS  1024
#define THE_NUM_DATA_1024_BYTES  128

typedef enum {
    ECC_CHECK_RESULT_FAIL_BUT_NOT_FIXED = -4,
    ECC_CHECK_RESULT_FAIL_ECC_BUT_FIXED = -3,
    ECC_CHECK_RESULT_FAIL_DATA_BUT_FIXED = -2,
    ECC_CHECK_RESULT_IMPROPER_PARAM = -1,
    ECC_CHECK_RESULT_SUCC = 0,
} ECC_CHECK_RESULT_TYPE;

typedef enum _ECC_CHECK_FLAG {
    ECC_CHECK_INGORE_ECC_NOT_BURN = (1 << 0),
} ECC_CHECK_FLAG;

typedef struct _ECC_CHECK_REGION {
    unsigned char *data;
    unsigned int len;
    unsigned int ecc_start_bit;
    unsigned int ecc_unit_bit_num;
    ECC_CHECK_FLAG flags;
} ECC_CHECK_REGION;

typedef struct _ECC_INPUT_DATA_PARAM {
    unsigned int data_ofst;
    unsigned int data_len;
    unsigned int ecc_start_bit;
    unsigned int ecc_unit_bit_num;
    ECC_CHECK_FLAG flags;
} ECC_INPUT_DATA_PARAM;


extern int EnHammingCode1024(char* orig_data, unsigned int* ecc_data);
extern int DeHammingCode1024(char* ptTrasmit_data, unsigned int ecc_data);
extern int EnHammingCode(unsigned char* orig_data, unsigned int orig_data_len,
                         unsigned int* ecc_data, unsigned int *ecc_data_bits_len);
ECC_CHECK_RESULT_TYPE DeHammingCode(unsigned char* ptTrasmit_data,
                                    unsigned int ptTrasmit_data_len, unsigned int *p_ecc_data,
                                    unsigned int *p_ecc_check_error_bit_index);
extern int do_ecc_check_util(ECC_CHECK_REGION *check_region);
extern int do_get_data_region_with_ecc_check(
    ECC_INPUT_DATA_PARAM *params, unsigned char **output);
extern int otp_ecc_util_get_data_region(unsigned int data_ofst,
                                        unsigned int data_len, unsigned int ecc_start_bit,
                                        unsigned int ecc_unit_bit_num, unsigned int ignore_ecc_not_burn,
                                        unsigned int **output);

/*#define ECC_FUNC_DBG_EN*/
#ifdef ECC_FUNC_DBG_EN
#define ECC_FUNC_DBG(fmt, args...)     rtd_printk(KERN_DEBUG, "OTP_ECC", "[DBG] " fmt, ##args)
#else
#define ECC_FUNC_DBG(fmt, args...)
#endif
#define ECC_FUNC_WARNING(fmt, args...)        rtd_printk( KERN_WARNING , "OTP_ECC", "[Warn] " fmt, ##args)

#endif
