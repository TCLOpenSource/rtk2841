/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for power related functions.
 *
 * @author 	$Author$
 * @date	$Date$
 * @version	$Revision$
 * @ingroup	power
 */


#ifndef _POWER_H_
#define _POWER_H_

typedef enum {
	ADC_POWER_YPP_ONLY_DETECT_CONTROL = 0,
	ADC_POWER_VGA_ONLY_DETECT_CONTROL = 1,
	ADC_POWER_YPP_SCALER_CONTROL = 2,
	ADC_POWER_VGA_SCALER_CONTROL = 3,
	ADC_POWER_VDC_ENABLE_CONTROL = 4,
	ADC_POWER_ADC_DISABLE_VDC_ALIVE_CONTROL = 5,
	ADC_POWER_VDC_DISABLE_ADC_ALIVE_CONTROL = 6,
	ADC_POWER_ALL_ENABLE_CONTROL = 7,
	ADC_POWER_ALL_DISABLE_CONTROL = 8,
} ADC_POWER_CONTROL_TYPE;

/*================================== Function ================================*/
/*============================================================================*/
void drvif_adc_power_control(ADC_POWER_CONTROL_TYPE type);
void adc_power_semaphore_init(void);
struct semaphore* get_adc_power_semaphore(void);

void avd_power_semaphore_init(void);
struct semaphore* get_avd_power_semaphore(void);



/*============================================================================*/


#endif // #ifndef  _POWER_H_
/*======================== End of File =======================================*/

