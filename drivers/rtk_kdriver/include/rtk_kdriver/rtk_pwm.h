#ifndef __RTK_PWM_CONFIG_RTD284x_H__
#define __RTK_PWM_CONFIG_RTD284x_H__

#include <mach/rtk_log.h>
static unsigned int ld_time_tick=0;

#define PWM_ID(type, id)    (((type  & 0x7)<< 5) | (id & 0x1F))
#define PWM_TYPE(id)        ((id >> 5) & 0x7)
#define PWM_IDX(id)         (id & 0x1F)
#define MAX_PWM_COUNT 10
#define PCB_ENUM_NAME_LEN_MAX	64

#define PWM_OK                0
#define PWM_PCB_ENUM_ERROR    1
#define PWM_DUTY_INVALID      2
#define PWM_FREQEUNCY_INVALID 3
#define PWM_POLARITY_INVALID  4
#define PWM_VSYNC_INVALID     5
#define PWM_OUTPUT_INVALID    6
#define PWM_NULL_POINTER      7
#define PWM_INIT_FAILED       8
#define PWM_PARAM_ID_INVALID  9
#define PWM_MODE_INVALID      10
#define PWM_VALUE_INVALID     11
#define PWM_VSYNC_DELAY_INVALID 12
#define PWM_TOTALCNT_INVALID  13

typedef struct linux_pcb_pwm_enum_t {
	char name[PCB_ENUM_NAME_LEN_MAX];
	unsigned long long value;
}RTK_PCB_ENUM;

typedef enum{
	PWM_DRIVING_LED_CURRENT     = 0,    /* PWM1(global dimming )+ PWM2(led current) */
	PWM_DRIVING_2CH_PHASE_SAME  = 1,    /* PWM1(global dimming) + PWM2(global dimming) : same phase */
	PWM_DRIVING_2CH_PHASE_DIFF  = 2,    /* PWM1(global dimming) + PWM2(global dimming) : diffrent phase */
	PWM_DRIVING_MODE_MAX        = 3
}PWM_DRIVING_MODE_T;

typedef enum{
	PWM_MODE   = 0,
	GPIO_MODE  = 1,
}PIN_MODE_T;

typedef enum {
	PWM_MISC = 0,
	PWM_ISO = 1,
} PWM_TYPE;

typedef enum {
	CRT_PWM_ISO = 0,
	CRT_PWM_MISC = 1,
} CRT_PWM_TYPE;

typedef enum {
	PWM_PARAM_POLARITY = 0,
	PWM_PARAM_FREQUENCY = 1,
	PWM_PARAM_DUTY = 2,
	PWM_PARAM_VSYNC_RESET = 3,
	PWM_PARAM_OUTPUT = 4,
	PWM_PARAM_TOTALCNT = 5,
	PWM_PARAM_VSYNC_DELAY = 6,
} PWM_PARAMETER_ID;

typedef enum {
	PWM_SUCCESS = 0,
	PWM_FAIL = -1,
} PWM_RET;

typedef struct {
	int m_index;            /* pwm index */
#ifdef CONFIG_COMPAT
	unsigned int id;       /* parameter id*/
	unsigned int val;      /* parameter val*/
#else
	unsigned long id;       /* parameter id*/
	unsigned long val;      /* parameter val*/
#endif
} RTK_PWM_PARAM_T;

typedef struct {
#ifdef CONFIG_COMPAT
   unsigned int id;       /* parameter id*/
   unsigned int val;      /* parameter val*/
#else
	unsigned long id;       /* parameter id*/
	unsigned long val;      /* parameter val*/
#endif
	char pcbname[64];
} RTK_PWM_PARAM_EX_T;

typedef struct {
	unsigned int m_polarity;
	unsigned int m_run;
	unsigned int m_duty;
	unsigned int m_freq;
	unsigned int m_vsync;
	char pcbname[64];
} RTK_PWM_INFO_EX_T;

typedef struct {
	unsigned int m_val;
	unsigned int m_mode;
	char pcbname[64];
} RTK_PWM_MODE_INFO_T;

typedef struct RTK_PWM_INFO {
	int m_index;
	int m_run;
	int m_duty;
	int m_freq;
	int m_adpt_en;
	int m_freq48n;
	int m_freq50n;
	int m_freq60n;
	int m_vsync;
	int m_pos;
} RTK_PWM_INFO_T;


extern int rtk_pwm_backlight_enable(int enable);
extern int rtk_pwm_backlight_set_duty( int duty );
void rtk_pwm_chip_PcbMgrValue_set(int ricindex, unsigned long long value);
int rtk_pwm_set_freq(int inumber, int ifreq, int ifold,bool bEnableDB);
int rtk_pwm_set_scaler_source( int ifreq, int ifold,bool bEnableDB);
void rtk_pwm_enable_vsync(int enable);

#define PWM_IOC_MAGIC  'p'
#define PWM_IOCR_SET _IOR(PWM_IOC_MAGIC,  0, RTK_PWM_INFO_T)
#define PWM_BACKLIGHT_DUTY _IOW(PWM_IOC_MAGIC,  1, int)
#define PWM_PARAM_SET _IOW(PWM_IOC_MAGIC,  2, RTK_PWM_PARAM_T)
#define PWM_PARAM_GET _IOR(PWM_IOC_MAGIC,  3, RTK_PWM_PARAM_T)

#define PWM_IOCR_SET_EX _IOW(PWM_IOC_MAGIC,  4, RTK_PWM_INFO_EX_T)
#define PWM_IOCR_GET_EX _IOR(PWM_IOC_MAGIC,  5, RTK_PWM_INFO_EX_T)
#define PWM_PARAM_SET_EX _IOW(PWM_IOC_MAGIC,  6, RTK_PWM_PARAM_EX_T)
#define PWM_PARAM_GET_EX _IOR(PWM_IOC_MAGIC,  7, RTK_PWM_PARAM_EX_T)
#define PWM_MODE_SET _IOW(PWM_IOC_MAGIC,  10, RTK_PWM_MODE_INFO_T)
#define PWM_MODE_GET _IOR(PWM_IOC_MAGIC,  11, RTK_PWM_MODE_INFO_T)

#undef RTK_PWM_DEBUG
#define RTK_PWM_DEBUG
#ifdef RTK_PWM_DEBUG
#define RTK_PWM_P(fmt, args...)		printk(fmt, ## args)
#else
#define RTK_PWM_P(fmt, args...)
#endif

#define N_MAX  4096
#define M_MAX  3
#define CONFIG_CPU_XTAL_FREQ 27000000
#define CONFIG_CPU_XTAL_NS   (37)    /*1/27000000*/

#define MAX_PWM_FREQ (105600)

#define HZ_48 48
#define HZ_50 50
#define HZ_60 60

#define GET_PWM_PINMUX_GPIO_NUM(x)        ((unsigned int)  (((x)) & 0x1FF))
#define GET_PWM_PINMUX_GPIO_INIT_VALUE(x) ((unsigned int)  (((x) >> 9) & 0x1))
#define GET_PWM_PINMUX_GPIO_PINTYPE(x)    ((unsigned int)  (((x) >> 10) & 0xF))
#define GET_PWM_PINMUX_GPIOVALUE(x)       ((unsigned char) (((x) >> 14) & 0xF))
#define GET_PWM_PINMUX_PWMVALUE(x)        ((unsigned char) (((x) >> 18) & 0xF))
#define GET_PWM_PINMUX_REG_ENDBIT(x)      ((unsigned char) (((x) >> 22) & 0x1F))
#define GET_PWM_PINMUX_REG_STARTBIT(x)    ((unsigned char) (((x) >> 27) & 0x1F))
#define GET_PWM_PINMUX_ADDR(x)            ((unsigned int)  (((x) >> 32) & 0xFFFFFFFF))
#define INVALID_GPIO_GID   0xFFFF
#define MAX_PWM_DUTY  255
#define MIN_PWM_DUTY  0
struct rtk_pwm_pin_reg_t {
    unsigned long  addr;
    unsigned char  mask_h;
    unsigned char  mask_l;
    unsigned char  pwmValue;
    unsigned char  gpioValue;
};
typedef struct rtk_pwm_pin_reg_t rtk_pwm_pin_reg;

//int rtk_pwm_backlight_set_duty( int duty );


#define PWM_DEBUG(fmt, args...)	rtd_printk(KERN_DEBUG, "PWM" , fmt, ## args)
#define PWM_INFO(fmt, args...)	rtd_printk(KERN_INFO, "PWM" , fmt, ## args)
#define PWM_WARN(fmt, args...)	rtd_printk(KERN_WARNING, "PWM" , fmt, ## args)
#define PWM_ERR(fmt, args...)	rtd_printk(KERN_ERR  , "PWM" , fmt, ## args)

#endif
