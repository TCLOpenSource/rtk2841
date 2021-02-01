#ifndef __RTK_DISEQC_H__
#define __RTK_DISEQC_H__

#include <mach/rtk_log.h>

#undef  TAG_NAME
#define TAG_NAME  "DISEQC"

#define SUCCESS 0
#define FAIL    (-1)
/// Function return status
enum FUNC_RETURN_STATUS {
        FUNC_SUCCESS,                       ///<   Execute function successfully.
        FUNC_ERROR,                         ///<   Execute function unsuccessfully.
};

typedef enum {
        DISEQC_PULSE_MODE,
        DISEQC_ENVELOP_MODE,
        DISEQC_ENVELOP_NONE,
} ENVELOP_MODE;

typedef enum {
        DISEQC_OFF,
        DISEQC_ON,
        DISEQC_ON_OFF_NONE,
} DISEQC_ON_OFF;

typedef enum {
        TONE_MODE_A,
        TONE_MODE_B,
        TONE_MODE_MAX,
}TONE_MODE;

typedef struct sDiseqc_Func{
	struct device *device_this;
	int mode;
	int diseqc_dev_major;
	int diseqc_dev_minor;
	int (* SetContinue22kOnOff)(unsigned int Diseqc22kOnOff);
	int (* SetDiseqcCmd)(unsigned int DataLength,unsigned char *Data);
	int (* SetUnModToneBurst)(void);
	int (* SetModToneBurst)(void);
	int (* SetToneBurst)(TONE_MODE mode);
}Diseqc_Func;

int RTK_SetEnvelopMode(unsigned int Env_en);
int RTK_SetContinue22kOnOff(unsigned int Diseqc22kOnOff);
int RTK_SetDiseqcCmd(unsigned int DataLength,unsigned char *Data);
int RTK_SetUnModToneBurst(void);
int RTK_SetModToneBurst(void);
int RTK_SetToneBurst(TONE_MODE mode);

int diseqc_set_envelop_mode(unsigned int envelop_mode);
int diseqc_set_continue_22k_on_off(unsigned int diseqc_22k_on_off);
int diseqc_set_diseqc_cmd(unsigned int data_len,unsigned char *data);
int diseqc_set_unmod_tone_burst(void);
int diseqc_set_mod_tone_burst(void);
int diseqc_set_tone_burst(TONE_MODE mode);


#ifdef __cplusplus
extern "C"{
#endif

#define DISEQC_DBG(fmt, args...)	rtd_printk(KERN_DEBUG, TAG_NAME , "[DEBUG]" fmt, ##args);
#define DISEQC_INFO(fmt, args...)	rtd_printk(KERN_INFO, TAG_NAME , "[INFO]" fmt, ##args);
#define DISEQC_WARN(fmt, args...)	rtd_printk(KERN_WARNING, TAG_NAME , "[WARN]" fmt, ##args);
#define DISEQC_ERROR(fmt, args...)	rtd_printk(KERN_ERR , TAG_NAME , "[Error]" fmt, ## args)


#ifdef __cplusplus
}
#endif

#endif
