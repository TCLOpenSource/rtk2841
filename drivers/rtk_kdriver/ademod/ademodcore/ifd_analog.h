
#ifndef _IFD_SIRIUS_H_
#define _IFD_SIRIUS_H_

#ifdef __cplusplus
extern "C" {
#endif

//#include <unistd.h>			// 'close()'
//#include <fcntl.h>			// 'open()'
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>


//remove on sirius
typedef enum  {
	IFD_ADC_SHAGAIN_0P6X = 0,
	IFD_ADC_SHAGAIN_0P86X = 1,
	IFD_ADC_SHAGAIN_1P0X = 2,
	IFD_ADC_SHAGAIN_1P2X = 3,
} IFD_ADC_SHAGAIN;

typedef enum  {
	IFD_ADC_PGAFIX_CTRL_FROM_DIGITAL = 0,
	IFD_ADC_PGAFIX_CTRL_N1DB = 1,
	IFD_ADC_PGAFIX_CTRL_N2DB = 2,
	IFD_ADC_PGAFIX_CTRL_N3DB = 3,
	IFD_ADC_PGAFIX_CTRL_N4DB,
	IFD_ADC_PGAFIX_CTRL_N5DB,
	IFD_ADC_PGAFIX_CTRL_N6DB,
	IFD_ADC_PGAFIX_CTRL_N7DB,
	IFD_ADC_PGAFIX_CTRL_2_5DB,
} IFD_ADC_PGAFIX_CTRL;

typedef enum  {
	IFD_ADC_FULLSCALE_1P23V = 0,
	IFD_ADC_FULLSCALE_1P30V = 1,
	IFD_ADC_FULLSCALE_1P40V = 2,
	IFD_ADC_FULLSCALE_1P48V = 3,
} IFD_ADC_FULLSCALE;


typedef enum  {
	IFD_ADC_INPUT_SEL_IFPGA = 0,
	IFD_ADC_INPUT_SEL_BYPASS,
} IFD_ADC_INPUT_SEL;

typedef enum  {
	IFD_DIG_DEMOD = 0,
	IFD_ANA_DEMOD,
} IFD_IFADC_MUX;

typedef enum  {
	IFD_CLK_RATE_108M = 0  ,
	IFD_CLK_RATE_54M,
	//IFD_CLK_RATE_24P576M,
	IFD_CLK_RATE_135M,
	IFD_CLK_RATE_162M,
} IFD_CLK_RATE;

typedef enum  {
	IFD_DAC_TV_SRC_SEL_VD = 0,
	IFD_DAC_TV_SRC_SEL_ADC = 3,
	IFD_DAC_TV_SRC_SEL_IFD_DEBUG = 4,
	IFD_DAC_TV_SRC_SEL_LSADC = 5,
	IFD_DAC_TV_SRC_SEL_TV_TVE = 6,
	IFD_DAC_TV_SRC_SEL_BOX_TVE = 7,
} IFD_DAC_TV_SRC_SEL;


void drv_ifd_analog_preset(void);
void drv_ifd_adc_clock_init_162M(void);
void drv_ifd_adc_default(void);
void drv_ifd_dac_default(void);
void drv_ifd_power_on(bool enable);
void drv_ifd_adc_power_on(bool enable);
bool drv_ifd_adc_power_check(void);
void drv_ifd_set_adcinput_swing(IFD_ADC_SHAGAIN setting1, IFD_ADC_FULLSCALE setting2);
void drv_ifd_adc_input_sel(IFD_ADC_INPUT_SEL input_source);
void drv_ifd_adc_clock(IFD_CLK_RATE adc_clock);
void drv_ifd_adc_clock_source_set(IFD_IFADC_MUX value);
bool drv_ifd_adc_clock_source_get_info(void);
void drv_ifd_adc_pga_gain_fix(bool enable, IFD_ADC_PGAFIX_CTRL fix_pga_gain);
void drv_ifd_pll_default(void);

#ifdef ENABLE_PWR_IP_CLOSE_SIRIUS
void drv_ifd_dac_openfordtv(bool enable);
#endif

#ifdef __cplusplus
}
#endif

#endif

