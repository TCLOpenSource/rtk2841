//Kernel Header file
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
//#include <mach/io.h>

//RBUS Header file
//#include <rbus/rbusScaledownReg.h>
//#include <rbus/rbusDiReg.h>
//#include <rbus/scaler/rbusPpOverlayReg.h>
#include <rbus/ppoverlay_reg.h>
#include <rbus/vgip_reg.h>
//#include <rbus/scaler/rbusCRTReg.h>
//#include <rbus/crt_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rbus/offms_reg.h>
#include <rbus/mdomain_cap_reg.h>
#include <rbus/mdomain_disp_reg.h>

#include <scalercommon/scalerCommon.h>


//Tvscalercontrol Header file
#include "tvscalercontrol/io/ioregdrv.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/scaler/source.h"
#include "tvscalercontrol/scalerdrv/adjust.h"
#include "tvscalercontrol/scalerdrv/scalerdrv.h"
#include <tvscalercontrol/panel/panelapi.h>
#include <mach/rtk_log.h>

#define TAG_NAME_VBE "VBE"

// register dump
#include <tvscalercontrol/io/ioregdrv.h>
#undef rtd_outl
#define rtd_outl(x, y)     								IoReg_Write32(x,y)
#undef rtd_inl
#define rtd_inl(x)     									IoReg_Read32(x)
#undef rtd_maskl
#define rtd_maskl(x, y, z)     							IoReg_Mask32(x,y,z)
#undef rtd_setbits
#define rtd_setbits(offset, Mask) rtd_outl(offset, (rtd_inl(offset) | Mask))
#undef rtd_clearbits
#define rtd_clearbits(offset, Mask) rtd_outl(offset, ((rtd_inl(offset) & ~(Mask))))

/**
* Description  : Sync processor measure start
* Input Value  : None
* Output Value : None
*/
void drv_adjust_syncprocessormeasurestart(void)
{
	offms_sp_ms3stus_RBUS offms_sp_ms3stus_reg;
	offms_sp_ms3ctrl_RBUS offms_sp_ms3ctrl_reg;
	//write clear
	offms_sp_ms3stus_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Stus_reg);
	offms_sp_ms3stus_reg.off_vs_per_to_long = 1;
	offms_sp_ms3stus_reg.off_vs_per_to = 1;
	offms_sp_ms3stus_reg.off_vs_high_to = 1;
	offms_sp_ms3stus_reg.off_vs_per_of = 1;
	offms_sp_ms3stus_reg.off_vs_over_range = 1;
	offms_sp_ms3stus_reg.off_vs_pol_chg = 1;
	offms_sp_ms3stus_reg.off_hs_per_of = 1;
	offms_sp_ms3stus_reg.off_hs_over_range = 1;
	offms_sp_ms3stus_reg.off_hs_pol_chg = 1;
	IoReg_Write32(OFFMS_SP_MS3Stus_reg, offms_sp_ms3stus_reg.regValue);

	//measure once
	offms_sp_ms3ctrl_reg.regValue = IoReg_Read32(OFFMS_SP_MS3Ctrl_reg);
	offms_sp_ms3ctrl_reg.off_online_en = _DISABLE;
	offms_sp_ms3ctrl_reg.off_start_ms = _ENABLE;
	IoReg_Write32(OFFMS_SP_MS3Ctrl_reg, offms_sp_ms3ctrl_reg.regValue);

}



/**
* Description  : Calculate the suitable IVS to DVS delay
* Input Value  : Scaling setting
* Output Value : IV to DV delay lines
*/


#define FrameSync_Patch 1

unsigned char  drv_adjust_measureivs2dvsdelay(void)
{
	return 0;
}


void drvif_clear_ivs2dvsdelay(void)
{
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5;
	ppoverlay_fs_iv_dv_fine_tuning2_RBUS tuning2_reg;

	#if 1  //if osd will be filcker, open
	//WaitFor_DEN_STOP();//Fix error by Will
	#endif

	//reset iv2dvs pixel delay
	tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
	tuning2_reg.iv2dv_pixel = 0;
	tuning2_reg.iv2dv_pixel2 = 0;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, tuning2_reg.regValue);

	//set iv2dvs  line delay= 1
	fs_iv_dv_fine_tuning5.regValue = 0;
	fs_iv_dv_fine_tuning5.iv2dv_line = 0;

	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5.regValue);

}

void drvif_set_frc_ivs2dvsdelay_line(UINT16 iv2dv_line1, UINT16 iv2dv_line2, UINT8 ucDelayField)
{
	ppoverlay_fs_iv_dv_fine_tuning5_RBUS fs_iv_dv_fine_tuning5_reg;
	//fs_iv_dv_fine_tuning1_RBUS fs_iv_dv_fine_tuning1_reg;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"drvif_set_frc_ivs2dvsdelay_line, iv2dv_line1 : %x, iv2dv_line2 : %x\n", iv2dv_line1, iv2dv_line2);

	while(ucDelayField > 0)
	{
		ucDelayField--;
		//WaitFor_DEN_STOP();//Fix error by Will
	}

	fs_iv_dv_fine_tuning5_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg);
	fs_iv_dv_fine_tuning5_reg.iv2dv_line_2 = iv2dv_line2;
	fs_iv_dv_fine_tuning5_reg.iv2dv_line = iv2dv_line1;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning5_reg, fs_iv_dv_fine_tuning5_reg.regValue);
}

void drvif_set_frc_ivs2dvsdelay_pixel(UINT16 iv2dv_pixel1, UINT16 iv2dv_pixel2, UINT8 ucDelayField)
{
	ppoverlay_fs_iv_dv_fine_tuning2_RBUS fs_iv_dv_fine_tuning2_reg;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"drvif_set_frc_ivs2dvsdelay_pixel, iv2dv_pixel1 : %x, iv2dv_pixel2 : %x\n", iv2dv_pixel1, iv2dv_pixel2);

	while(ucDelayField > 0)
	{
		ucDelayField--;
		//WaitFor_DEN_STOP();//Fix error by Will
	}

	fs_iv_dv_fine_tuning2_reg.regValue = IoReg_Read32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg);
	fs_iv_dv_fine_tuning2_reg.iv2dv_pixel = iv2dv_pixel1;
	fs_iv_dv_fine_tuning2_reg.iv2dv_pixel2 = iv2dv_pixel2;
	IoReg_Write32(PPOVERLAY_FS_IV_DV_Fine_Tuning2_reg, fs_iv_dv_fine_tuning2_reg.regValue);
}


/**
 * Description  : Adjust spread spectrum range
 * Input Value  : Spread spectrum range
 * Output Value : None
 */
void drv_adjust_spreadspectrumrange(unsigned char ucSpreadRange)
{
	UINT16 dclk_ss_reg_table[16]={0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75};

	pll27x_reg_sys_dclkss_RBUS dclkss_reg;
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_pll_ssc0_RBUS pll_ssc0_reg;
	pll27x_reg_pll_ssc3_RBUS pll_ssc3_reg;
	pll27x_reg_pll_ssc4_RBUS pll_ssc4_reg;
	pll27x_reg_pll_ssc5_RBUS pll_ssc5_reg;
	UINT32 m_code, f_code, n_code, n_code_ssc, f_code_ssc;
	UINT32 temp, temp_ssc;
	UINT32 dot_gran=4, gran_est;
	UINT32 dpll_clk, dpll_clk_ssc, ssc_clk, step;
	UINT32 ss_freq = 30*1000; //30K
	UINT32 cnt=0;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n dclk_ss_reg_table[%d] = %d \n", ucSpreadRange, dclk_ss_reg_table[ucSpreadRange]);


	pll_disp1_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_ssc0_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC0_reg);
	pll_ssc3_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC3_reg);
	pll_ssc4_reg.regValue = IoReg_Read32(PLL27X_REG_PLL_SSC4_reg);

	if(ucSpreadRange == 0){
		pll_ssc4_reg.en_ssc = 0;
		IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);
		return;
	}

	m_code = pll_disp1_reg.dpll_m;
	n_code = pll_disp1_reg.dpll_n;
	f_code = pll_ssc0_reg.fcode_t_ssc;

	temp = ((m_code+3)*10000+ ((f_code*10000)/2048));
	temp_ssc = (temp*(1000-dclk_ss_reg_table[ucSpreadRange]))/1000;
	n_code_ssc = temp_ssc/10000-3;
	f_code_ssc = ((temp_ssc%10000)*2048)/10000;

	pll_ssc3_reg.ncode_ssc = n_code_ssc;
	pll_ssc3_reg.fcode_ssc = f_code_ssc;
	pll_ssc0_reg.oc_en = 0;
	pll_ssc0_reg.oc_step_set = 0x200;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);
	IoReg_Write32(PLL27X_REG_PLL_SSC3_reg, pll_ssc3_reg.regValue);

	//printf("\n temp:%d, temp_ssc:%d, n_code_ssc:%d, f_code_ssc:%d\n", temp, temp_ssc, n_code_ssc, f_code_ssc);

	temp= 0;
	dpll_clk = (((m_code+3)*1000000 + (f_code*1000000)/2048)*27) / (n_code+2);
	dpll_clk_ssc = (dpll_clk/1000*((1000 - dclk_ss_reg_table[ucSpreadRange]/2)));
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n dpll_clk:%d, dpll_clk_ssc:%d \n", dpll_clk, dpll_clk_ssc);
	temp = (10000*((m_code-n_code_ssc)*2048+f_code-f_code_ssc)/2/2048 + (n_code_ssc+3)*10000);
	ssc_clk = dpll_clk_ssc /temp;
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n temp:%d, ssc_clk:%d \n", temp, dpll_clk_ssc/temp);
	step =  ssc_clk*10000 / ss_freq;
	if(f_code>=f_code_ssc)
		gran_est = (((m_code-n_code_ssc)*2048+f_code-f_code_ssc)*2*(1<<(15-dot_gran))) /step;
	else
		gran_est = (((m_code-1-n_code_ssc)*2048+ (2048+f_code)-f_code_ssc)*2*(1<<(15-dot_gran))) /step;

	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"m_code:%d, n_code:%d, f_code:%d, n_code_ssc:%d, f_code_ssc:%d\n", m_code , n_code, f_code, n_code_ssc, f_code_ssc);
	rtd_printk(KERN_DEBUG, TAG_NAME_VBE,"\n step:%d, gran_est:%d\n", step , gran_est);

	pll_ssc4_reg.dot_gran = dot_gran;
	pll_ssc4_reg.gran_auto_rst = 1;
	pll_ssc4_reg.gran_est = gran_est;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);

	pll_ssc0_reg.oc_en = 1;
	IoReg_Write32(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	cnt=10;
	do{
		pll_ssc5_reg.regValue = rtd_inl(PLL27X_REG_PLL_SSC5_reg);
		msleep(10);
	}while((pll_ssc5_reg.oc_done != 1) && (cnt--));

	pll_ssc0_reg.oc_en = 0;
	rtd_outl(PLL27X_REG_PLL_SSC0_reg, pll_ssc0_reg.regValue);

	pll_ssc4_reg.en_ssc = 1;
	IoReg_Write32(PLL27X_REG_PLL_SSC4_reg, pll_ssc4_reg.regValue);

	dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_reg);
	dclkss_reg.dclk_ss_load = _ENABLE;
	dclkss_reg.dclk_ss_en = _ENABLE;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_reg, dclkss_reg.regValue);

}

unsigned char drv_read_spreadspectrumrange(void)
{
	unsigned int data=0;
#if 0 //-> weihao, not find in CRT,	will fix by Ben in future.
	crt_sys_dclkss_RBUS sys_dclkss_reg;

	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	data = sys_dclkss_reg.dclk_ss_rag;
#endif
	return (unsigned char)data;
}
/**
 * Description  : Adjust spread spectrum FMDIV
 * Input Value  : Spread spectrum FMDIV value
 * Output Value : None
 */
void drvif_adjust_spreadspectrumrange_FMDIV(UINT8 ucValue)
{
#if 0 //-> weihao, not find in CRT,	will fix by Ben in future.
	//DCLK Spreading FMDIV (33K or 66K)
	crt_sys_dclkss_RBUS sys_dclkss_reg;

	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	//sys_dclkss_reg.dclk_ss_fmdiv = ucValue & _BIT0;;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, sys_dclkss_reg.regValue);

	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	sys_dclkss_reg.dclk_ss_load = _ENABLE;
	sys_dclkss_reg.dclk_ss_en = _ENABLE;
	sys_dclkss_reg.dclk_ss_rag = 8;
	IoReg_Write32(PLL27X_REG_SYS_DCLKSS_VADDR, sys_dclkss_reg.regValue);
#endif
}

UINT8 drvif_read_spreadspectrumrange_FMDIV(void)
{
	UINT8 data=0;
#if 0 //-> weihao, not find in CRT,	will fix by Ben in future.
	crt_sys_dclkss_RBUS sys_dclkss_reg;

	sys_dclkss_reg.regValue = IoReg_Read32(PLL27X_REG_SYS_DCLKSS_VADDR);
	//data = sys_dclkss_reg.dclk_ss_fmdiv;
#endif
	return (UINT8)data;
}

