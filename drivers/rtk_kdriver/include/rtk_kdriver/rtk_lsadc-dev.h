#ifndef __RTK_LSADC_DEV_H__
#define __RTK_LSADC_DEV_H__

#include <linux/kfifo.h>

typedef struct {
    unsigned char pin_name[32];
    RTK_LSADC_INFO info;
} RTK_LSADC_PCBINFO_T;

typedef struct {
    RTK_LSADC_PCBINFO_T  pcbInfo[20];
    int count;
} RTK_ALL_LSADC_PIN_T ;

typedef struct {
    char  pin_name[32];
    unsigned char val ;
} RTK_LSADC_VAL_T ;

#define RTK_LSADC_IOC_MAGIC            'o'
#define RTK_LSADC_GET_ADCVAL           _IOR(RTK_LSADC_IOC_MAGIC, 0, RTK_LSADC_VAL_T)
#define RTK_LSADC_SET_ACTIVE           _IOW(RTK_LSADC_IOC_MAGIC, 1, RTK_LSADC_VAL_T)
#define RTK_LSADC_SET_TRESHOLD         _IOR(RTK_LSADC_IOC_MAGIC, 2, RTK_LSADC_VAL_T)
#define RTK_LSADC_SET_SW               _IOW(RTK_LSADC_IOC_MAGIC, 3, RTK_LSADC_VAL_T)
#define RTK_LSADC_SET_MODE             _IOR(RTK_LSADC_IOC_MAGIC, 4, RTK_LSADC_VAL_T)
#define RTK_LSADC_GET_ACTIVE           _IOW(RTK_LSADC_IOC_MAGIC, 5, RTK_LSADC_VAL_T)
#define RTK_LSADC_GET_THRESHOLD        _IOW(RTK_LSADC_IOC_MAGIC, 6, RTK_LSADC_VAL_T)
#define RTK_LSADC_GET_SW               _IOR(RTK_LSADC_IOC_MAGIC, 7, RTK_LSADC_VAL_T)
#define RTK_LSADC_GET_MODE             _IOR(RTK_LSADC_IOC_MAGIC, 8, RTK_LSADC_VAL_T)
#define RTK_LSADC_DUMP                 _IOR(RTK_LSADC_IOC_MAGIC, 9, RTK_LSADC_VAL_T)

#endif
