#ifndef __RTK_LSADC_H__
#define __RTK_LSADC_H__

//#include "rbus/rbusTypes.h"
//#include "rtk_lsadc_reg.h"


#include <mach/rtk_log.h>
#ifdef CONFIG_REALTEK_PCBMGR
#include <mach/pcbMgr.h>
#endif

#define MAX_LSADC_COUNT  8
#define MAX_LSADC_THRESHOLD  0xff;
#define MAX_LSADC_PCBINFO_COUNT    20


#define LSADC_INIT_MASK_NONE   0
#define LSADC_INIT_MASK_BIT_0  1 << 0
#define LSADC_INIT_MASK_BIT_1  1 << 1
#define LSADC_INIT_MASK_BIT_2  1 << 2
#define LSADC_INIT_MASK_BIT_3  1 << 3
#define LSADC_INIT_MASK_BIT_4  1 << 4
#define LSADC_INIT_MASK_BIT_5  1 << 5
#define LSADC_INIT_MASK_BIT_6  1 << 6
#define LSADC_INIT_MASK_BIT_7  1 << 7
#define LSADC_INIT_MASK_BIT_8  1 << 8
#define LSADC_INIT_MASK_BIT_9  1 << 9

enum LSADC_INIT_MASK_BIT {
        LSADC_INIT_NONE = LSADC_INIT_MASK_NONE,
        LSADC_INIT_0  = LSADC_INIT_MASK_BIT_0,
        LSADC_INIT_1  = LSADC_INIT_MASK_BIT_1,
        LSADC_INIT_2  = LSADC_INIT_MASK_BIT_2,
        LSADC_INIT_3  = LSADC_INIT_MASK_BIT_3,
        LSADC_INIT_4  = LSADC_INIT_MASK_BIT_4,
        LSADC_INIT_5  = LSADC_INIT_MASK_BIT_5,
        LSADC_INIT_6  = LSADC_INIT_MASK_BIT_6,
        LSADC_INIT_7  = LSADC_INIT_MASK_BIT_7,
        LSADC_INIT_8  = LSADC_INIT_MASK_BIT_8,
        LSADC_INIT_9  = LSADC_INIT_MASK_BIT_9,
};

#define SET_LSADC_INIT_MASK(value)   \
lsadc_init_status_mask = lsadc_init_status_mask | value;\


typedef enum{
    VOLTAGE_MODE = 0,
    CURRENT_MODE = 1,
}LSADC_MODE;

typedef struct _lsadc_pcb_info {
    unsigned char pinName[64];
    unsigned long long ullPcbMgrValue;
    unsigned int index;
}LSADC_PCBINFO;

typedef struct _RTK_LSADC_INFO 
{
    int pinNumber;
    int pad_active;
    int pad_thred;
    int pad_sw;
    int pad_ctrl;
    int adc_val ;

} RTK_LSADC_INFO;

void LSADC_ClockEnable(unsigned char On);
int get_lsadc_init_status(unsigned int index);

int rtk_lsadc_defualt_enable(int index, LSADC_MODE lsadc_mode);

int rtk_lsadc_get_adcValue(unsigned int index, unsigned char* value);
int rtk_lsadc_get_threshold(unsigned int index, unsigned char* threshold);
int rtk_lsadc_get_activeStatus(unsigned int index, unsigned char* activeStatus);
int rtk_lsadc_get_padSwitch(unsigned int index, unsigned char* padSwitch);
int rtk_lsadc_get_voltageMode(unsigned int index, unsigned char* voltageMode);

int rtk_lsadc_set_threshold(unsigned int index, unsigned char threshold);
int rtk_lsadc_set_active(unsigned int index, unsigned char activeStatus);
int rtk_lsadc_set_padSwitch(unsigned int index, unsigned char padSwitch);
int rtk_lsadc_set_voltageMode(unsigned int index, unsigned char voltageMode);

int rtk_lsadc_get_lsadc_config(RTK_LSADC_INFO  *lsadc_info);
int rtk_lsadc_set_lsadc_config(RTK_LSADC_INFO  *lsadc_info);
int rtk_lsadc_dump_mainLsadcCtrl(void);
int rtk_lsadc_dump_mainAnalogCtrl(void);

#define LSADC_DEBUG(fmt, args...) \
{ \
        if (log_onoff)  \
        {   \
                rtd_printk(KERN_EMERG, "LSADC", fmt, ## args); \
        }   \
}

#define LSADC_INFO(fmt, args...)	rtd_printk(KERN_INFO , "LSADC" , "[Info]" fmt, ## args)
#define LSADC_WARN(fmt, args...)	rtd_printk(KERN_WARNING , "LSADC" , "[Warn]" fmt, ## args)
#define LSADC_ERROR(fmt, args...)	rtd_printk(KERN_ERR , "LSADC" , "[Error]" fmt, ## args)


#endif
