/* Kernel Header file */
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/semaphore.h>

/* RBUS Header file*/
#include <rbus/adc_reg.h>

/* Tvscalercontrol Header file */
#include <tvscalercontrol/io/ioregdrv.h>
#include <tvscalercontrol/scalerdrv/power.h>
#include <tvscalercontrol/scalerdrv/syncproc.h>


/*===================================  Types ================================*/
static struct semaphore Adc_Power_Semaphore;
static struct semaphore Avd_Power_Semaphore;

/*================================== Function ================================*/

void drvif_adc_power_control(ADC_POWER_CONTROL_TYPE type)
{
	static unsigned char need_all_power_flag = false; //This is for scart need all power
	adc_adc_power_RBUS adc_adc_power_reg;
	pr_debug("\r\n####func:%s powertype:%d####\r\n", __FUNCTION__, type);
	adc_adc_power_reg.regValue = IoReg_Read32(ADC_ADC_POWER_reg);
	switch (type) {
	case ADC_POWER_YPP_ONLY_DETECT_CONTROL:
		if (need_all_power_flag) {
			pr_debug("\r\n####func:%s line:%d need all power####\r\n", __FUNCTION__, __LINE__);
			break;
		}
		adc_adc_power_reg.adc_power_7 = 1;
		adc_adc_power_reg.adc_power_6 = 1;
#if (YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY0)
		adc_adc_power_reg.adc_power_5 = 1;
		adc_adc_power_reg.adc_power_4 = 1; /* 2014 LG driver based */
#else /*if (YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY1) */
		adc_adc_power_reg.adc_power_5 = 0;
		adc_adc_power_reg.adc_power_4 = 1;
#endif
		adc_adc_power_reg.adc_power_3 = 1;
		adc_adc_power_reg.adc_power_2 = 0; /* Red Channel ADC Power Off brandon save power for LG detect */
		adc_adc_power_reg.adc_power_1 = 1; /* Green Channel ADC Power Off */
		adc_adc_power_reg.adc_power_0 = 0; /* Blue Channel ADC Power Off */
	break;

	case ADC_POWER_VGA_ONLY_DETECT_CONTROL:
		//adc_adc_power_reg.regValue = IoReg_Read32(ADC_ADC_POWER_VADDR);
		adc_adc_power_reg.adc_power_7 = 1;
		adc_adc_power_reg.adc_power_6 = 1;
		adc_adc_power_reg.adc_power_5 = 1;
		adc_adc_power_reg.adc_power_4 = 1;
		adc_adc_power_reg.adc_power_3 = 1;
		adc_adc_power_reg.adc_power_2 = 1;
		adc_adc_power_reg.adc_power_1 = 1;
		adc_adc_power_reg.adc_power_0 = 1;
		break;

	case ADC_POWER_YPP_SCALER_CONTROL:
		if (need_all_power_flag) {
			pr_debug("\r\n####func:%s line:%d need all power####\r\n", __FUNCTION__, __LINE__);
			break;
		}
		adc_adc_power_reg.adc_power_7 = 1;
		adc_adc_power_reg.adc_power_6 = 1;
#if (YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY0)
		adc_adc_power_reg.adc_power_5 = 1;
		adc_adc_power_reg.adc_power_4 = 1;
#else /*if (YPBPR_SOY_PATH_SELECT == SP_VHS_SOURCE_SOY1) */
		adc_adc_power_reg.adc_power_5 = 0;
		adc_adc_power_reg.adc_power_4 = 1;
#endif
		adc_adc_power_reg.adc_power_3 = 1;
		adc_adc_power_reg.adc_power_2 = 1; /* Red Channel ADC Power On */
		adc_adc_power_reg.adc_power_1 = 1; /* Green Channel ADC Power On */
		adc_adc_power_reg.adc_power_0 = 1; /* Blue Channel ADC Power On */
	break;

	case ADC_POWER_VDC_ENABLE_CONTROL:
		if (need_all_power_flag) {
			pr_debug("\r\n####func:%s line:%d need all power####\r\n", __FUNCTION__, __LINE__);
			break;
		}
		adc_adc_power_reg.adc_power_3 = 1;
		adc_adc_power_reg.adc_power_6 = 1;
	break;

	case ADC_POWER_ADC_DISABLE_VDC_ALIVE_CONTROL:
		if (need_all_power_flag) {
			pr_debug("\r\n####func:%s line:%d need all power####\r\n", __FUNCTION__, __LINE__);
			break;
		}
		adc_adc_power_reg.adc_power_0 = 0;
		adc_adc_power_reg.adc_power_1 = 0;
		adc_adc_power_reg.adc_power_2 = 0;
		adc_adc_power_reg.adc_power_3 = 1;
		adc_adc_power_reg.adc_power_4 = 0;
		adc_adc_power_reg.adc_power_5 = 0;
		adc_adc_power_reg.adc_power_6 = 1;
		adc_adc_power_reg.adc_power_7 = 0;
	break;

	case ADC_POWER_ALL_ENABLE_CONTROL:
		adc_adc_power_reg.adc_power_3 = 1;	/* can't disable!!! */
		adc_adc_power_reg.adc_power_0 = 1;
		adc_adc_power_reg.adc_power_1 = 1;
		adc_adc_power_reg.adc_power_2 = 1;
		adc_adc_power_reg.adc_power_4 = 1;
		adc_adc_power_reg.adc_power_5 = 1;
		adc_adc_power_reg.adc_power_6 = 1;
		adc_adc_power_reg.adc_power_7 = 1;
		need_all_power_flag = TRUE;
	break;

	case ADC_POWER_ALL_DISABLE_CONTROL:
		adc_adc_power_reg.adc_power_3 = 1;	/* can't disable!!! */
		adc_adc_power_reg.adc_power_0 = 0;
		adc_adc_power_reg.adc_power_1 = 0;
		adc_adc_power_reg.adc_power_2 = 0;
		adc_adc_power_reg.adc_power_4 = 0;
		adc_adc_power_reg.adc_power_5 = 0;
		adc_adc_power_reg.adc_power_6 = 0;
		adc_adc_power_reg.adc_power_7 = 0;
		need_all_power_flag = FALSE;
	break;

	case ADC_POWER_VDC_DISABLE_ADC_ALIVE_CONTROL:
		need_all_power_flag = FALSE;
	break;

	default:
	break;

	}
	IoReg_Write32(ADC_ADC_POWER_reg, adc_adc_power_reg.regValue);
}

void adc_power_semaphore_init(void)
{
	sema_init(&Adc_Power_Semaphore, 1);
}

struct semaphore* get_adc_power_semaphore(void)
{
	return &Adc_Power_Semaphore;
}




void avd_power_semaphore_init(void)
{
	sema_init(&Avd_Power_Semaphore, 1);
}

struct semaphore* get_avd_power_semaphore(void)
{
	return &Avd_Power_Semaphore;
}

/*======================== End of File =======================================*/
/**
*
* @}
*/


