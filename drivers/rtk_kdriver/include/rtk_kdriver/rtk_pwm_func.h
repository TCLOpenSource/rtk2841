#ifndef __RTK_PWM_FUNC_H__
#define __RTK_PWM_FUNC_H__

#include <rtk_kdriver/rtk_pwm.h>
#include <rtk_kdriver/rtk_pwm-reg.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-db.h>

#define ABS(x, y)    ((x) > (y) ? ((x)-(y)) : ((y)-(x)))
#define MAX_PWM_NODE  6
#define PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_VADDR  PPOVERLAY_DH_Total_Last_Line_Length_reg
#define PPOVERLAY_DV_TOTAL_VADDR                   PPOVERLAY_DV_total_reg

typedef struct RTK_CHIP_T {
	int index;
	bool mapped;
	unsigned long long ullPcbMgrValue;
	struct pwm_chip *chip;
	char nodename[16];
	char pcbname[32];
	const rtk_pwm_reg_map *reg;	/*hw phy address */
	struct device *pwm_device_st;	/* PWM-I-x or PWM-M-x */
	struct pwm_device *pst_rtk_pwm_dev;	/* get from linux pwm_get */
	int rtk_duty_max;
	int rtk_totalcnt;
	int rtk_freq;
	int lg_freq48n;
	int lg_freq50n;
	int lg_freq60n;
	int vt;			/*v-total */
	int ht;			/*h-total */
	int dclk;		/*dclk */
	int rtk_adapt_freq;
	unsigned int rtk_db_reg;
	int rtk_vsync;
	int rtk_enable;
	int rtk_duty;
	int rtk_polarity;
	int rtk_pos_start;
	unsigned int rtk_pos_start_clk;
	int rtk_adpt_en;
	int rtk_mPlus;      /*M+ enable*/
	rtk_pwm_pin_reg    pin_mux_info;
	RTK_GPIO_ID        gid;
	PIN_MODE_T         currentMode;
} R_CHIP_T;

int rtk_pwm_pcb_mgr_get(char const *pcbname,int ricindex);
int rtk_pwm_pcb_mgr_get_value(RTK_PCB_ENUM *pcbinfo,int ricindex);
int rtk_pwm_chip_index_get(int ricindex);
unsigned long long rtk_pwm_chip_PcbMgrValue_get(int ricindex);
const rtk_pwm_reg_map * rtk_pwm_chip_reg_get(int ricindex);
const char* rtk_pwm_chip_pcbname_get(int ricindex);

void rtk_pwm_chip_device_set(struct platform_device *pdev);

void pwm_mode_set(int mode);
int pwm_mode_get(void);
void pin_index_count(void);
int pin_index_get(void);
int rtk_pwm_backlight_pin_set(int ricindex);
int rtk_pwm_backlight_pin_get(void);
void m_printk_ioctl_set(int en_printk);
int m_printk_ioctl_get(void);
void m_disable_ioctl_set(int disable);
int m_disable_ioctl_get(void);
void m_ioctl_counter_count(void);
void m_ioctl_counter_set(unsigned int counter);
unsigned int m_ioctl_counter_get(void);

R_CHIP_T* rtk_pwm_chip_get(int m_index);
R_CHIP_T* rtk_pwm_chip_get_by_index(int m_index,int m_type);
R_CHIP_T* rtk_pwm_chip_get_by_name(char* pcbname);

int rtk_pwm_backlight_enable(int enable);
int rtk_pwm_backlight_set_duty( int duty );


void getHVTotal(int *htotal, int *vtotal);
void get_v_delay(R_CHIP_T *pchip2);
void getDClk(int *dclk);
void rtk_hw_get_divider(int pwm_freq_hz, int duty_max, int *totalcnt,
			       unsigned short *M_best, unsigned short *N_best);
int rtk_get_pwm_duty_base_change(int duty,int duty_max,int totalcnt);
int rtk_pwm_set_freq(int inumber, int ifreq, int ifold,bool bEnableDB);
int rtk_pwm_get_freq(R_CHIP_T *pchip2,unsigned short M, unsigned short N);
int rtk_pwm_get_adapt_freq(R_CHIP_T *pchip2);

void rtk_pwm_timing_update(R_CHIP_T *pchip2,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg);
void rtk_pwm_duty_update(R_CHIP_T *pchip2,pwm0_duty_set_RBUS* pwm_duty_set_reg);
void rtk_pwm_ctrl_update(R_CHIP_T *pchip2,pwm0_ctrl_RBUS* pwm_ctrl_reg);
void rtk_pwm_db_update(R_CHIP_T *pchip2,pwm0_db_ctrl_RBUS* dbReg);

void rtk_pwm_user_setting(R_CHIP_T *pchip2,RTK_PWM_INFO_T *stpwminfo);

int rtk_pwm_hw_type_init(R_CHIP_T *pwmPin);
void rtk_pwm_hw_pin_init(R_CHIP_T *pwmPin, int ricindex);

void rtk_pwm_totalcnt_init(R_CHIP_T *pchip2,int rtk_totalcnt);
void rtk_pwm_duty_probe_init(int duty, int duty_max, int *totalcnt,rtk_pwm_reg_map *regtable,pwm0_duty_set_RBUS* pwm_duty_set_reg);
void rtk_pwm_ctrl_probe_init(int pwm_mode,int invert,R_CHIP_T *pchip2,rtk_pwm_reg_map *regtable,pwm0_ctrl_RBUS* pwm_ctrl_reg);
void rtk_pwm_timing_probe_init(int pwm_freq_hz, int duty_max,int *totalcnt,rtk_pwm_reg_map *regtable,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg);
void rtk_pwm_timing_freq_set(R_CHIP_T *pchip2,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg);
void rtk_pwm_timing_freq_reg_read(R_CHIP_T *pchip2,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg);

unsigned long rtk_pwm_duty_get(R_CHIP_T *pchip2,int duty_max, int totalcnt);
void rtk_pwm_duty_set(R_CHIP_T *pchip2,pwm0_duty_set_RBUS* pwm_duty_set_reg);
void rtk_pwm_duty_reg_read(R_CHIP_T *pchip2,pwm0_duty_set_RBUS* pwm_duty_set_reg);

void rtk_pwm_ctrl_reg_read(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_ctrl_vdelay_enable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_ctrl_vdelay_disable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_ctrl_polarity(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_ctrl_output_enable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_ctrl_vsync_enable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_ctrl_db_wr(pwm0_ctrl_RBUS *pwm_ctrl_reg);
void rtk_pwm_db_enable(R_CHIP_T *pchip2,pwm0_db_ctrl_RBUS* dbReg);

/** PWM GPIO mode **/
int rtk_pwm_gpio_value(R_CHIP_T *pchip2);
void rtk_change_to_gpio_mode(R_CHIP_T *pchip2, GPIOPOT outputValue);
void rtk_change_to_pwm_mode(R_CHIP_T *pchip2);
#endif
