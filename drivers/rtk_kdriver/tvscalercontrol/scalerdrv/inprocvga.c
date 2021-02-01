/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2005
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * The file is a declaration and definition header file
 *
 * @author 	$Author:  $
 * @date 	$Date:  $
 * @version 	$Revision:  $
 * @ingroup
 */

 /**
 * @addtogroup
 * @{
 */
//RBUS Header file
#include <rbus/dds_pll_reg.h>
#include <rbus/abl_reg.h>
#include <rbus/adc_reg.h>
#include <scalercommon/scalerCommon.h>

//Tvscalercontrol Header file
#include "tvscalercontrol/io/ioregdrv.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/scalerdrv/inprocvga.h"
#include "tvscalercontrol/scalerdrv/mode.h"
#include "tvscalercontrol/scalerdrv/syncproc.h"
#include "tvscalercontrol/adcsource/vga.h"


// Definitions of ADC Fine Tune Delay (Value == 0 ~ 7)
//--------------------------------------------------
#define _ADC_FINE_TUNE_DELAY_RED        (0) //_C_ADC_FINE_TUNE_DELAY_RED//0
#define _ADC_FINE_TUNE_DELAY_GREEN    (0)// _C_ADC_FINE_TUNE_DELAY_GREEN//0
#define _ADC_FINE_TUNE_DELAY_BLUE       (0)//_C_ADC_FINE_TUNE_DELAY_BLUE//0

/**
 * inprocvga_adcsetup
 * Startup settings for VGA
 * calculate pixelclock and set the ADC port
 * @param <none>
 * @return {none}
*/
static void inprocvga_adcsetup(void)
{
#if 0//Fix error by Will
	unsigned short pixelclock;
	adc_dcrestore_ctrl_RBUS adc_dcrestore_ctrl_reg;
	//adc_ctl_RBUS adc_ctl_reg;	davidneedtocheckthis spec change in mag ADC_CTL -> ADC_CTL_RESERVE
	pll_phase_interpolation_RBUS pll_phase_interpolation_reg;
	pll_div_ctrl_RBUS pll_div_ctrl_reg;

    	// Calculate pixel clock rate (round to MHz)
    	pixelclock  = (((unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_H_FREQ) * (unsigned int)Scaler_DispGetInputInfo(SLR_INPUT_H_LEN)) * 2 / (1000 * 10));
    	pixelclock  = (pixelclock >> 1) + (pixelclock & 0x01);

    	// ADC differential mode and Set ADC bandwidth to reduce high frequency noise
    	adc_dcrestore_ctrl_reg.regValue = IoReg_Read32(ADC_ADC_DCRESTORE_CTRL_VADDR);
    if(pixelclock < 38)
		adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_75M;
	else if(pixelclock < 68)
		adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_150M;
	else if(pixelclock < 160)
		adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_300M;
	else
		adc_dcrestore_ctrl_reg.adc_ctl_rgb_3_0 = ADC_BW_400M;
	IoReg_Write32(ADC_ADC_DCRESTORE_CTRL_VADDR, adc_dcrestore_ctrl_reg.regValue);

	if(VGA_SP_PATH == SYNC_PROCESSOR1)
	{
		// Phase interpolation control load modified.   Marvin 0812
		pll_phase_interpolation_reg.regValue = IoReg_Read32(DDS_PLL_PLL_PHASE_INTERPOLATION_VADDR);

		if(pixelclock < 25)//25M HZ
			pll_phase_interpolation_reg.pllsphrl = 1;//sirus VCO interpolation
		else
			pll_phase_interpolation_reg.pllsphrl = 2;//sirus VCO interpolation

		IoReg_Write32(DDS_PLL_PLL_PHASE_INTERPOLATION_VADDR, pll_phase_interpolation_reg.regValue);

		// HSYNC positive/negtive tracking
		pll_div_ctrl_reg.regValue = IoReg_Read32(DDS_PLL_PLL_DIV_CTRL_VADDR);
		pll_div_ctrl_reg.tracking_inv = 0;
		IoReg_Write32(DDS_PLL_PLL_DIV_CTRL_VADDR, pll_div_ctrl_reg.regValue);
	}
#endif
}

/**
 * This API is used to setup scaler related common setting for VGA
 *
 * @param [input] :
 * @param [output] :
 * @return The result it setup.
 * @retval _SUCCESS If setup ok.
 * @retval _FAIL If setup fail.
 *
 */
unsigned char drvif_inprocvga_setup(void)
{
	//frank@0507 move from modestate.c
	//drvif_mode_enableonlinemeasure();
	inprocvga_adcsetup();
	//Scaler_DispSetStatus((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY),SLR_DISP_422,FALSE);
	return TRUE;
}

/**
 * This API is used to init scaler setting for VGA
 *
 * @param [input] :
 * @param [output] :
 * @return None
 *
 */
void drvif_inprocvga_init(void)
{
	//[Code Sync][AlanLi][0980403][1]
	//VGA support composite sync
	//VGADetecSyncTypeMode = 5;//<Stanley k(0623> Force default setting to seperate sync type.
	//[Code Sync][AlanLi][0980403][1][end]

	// CSW+ 0961105 Add APLL setting for YPbPr auto color
	IoReg_Write32(ABL_ABL_CTRL_reg, 0x00000000);
	IoReg_Write32(ABL_ABL_WINDOW_reg, 0x00000000);
}

/**
*
* @}
*/
