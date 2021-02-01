#include "ifd_new.h"
//#include <mach/rtk_crt.h>
//#include <rbus/sb2_reg.h>

void drv_ifd_analog_preset(void)
{
	//merge to common.c : AtvDemodInitialization
	drv_ifd_dac_default();
	return;
}

void drv_ifd_adc_clock_init_162M(void)
{
	//move to common.c : DemodPllSetting
	return;
}

void drv_ifd_pll_default(void)
{
	//move to common.c : DemodPllDefault
	return;
}

void drv_ifd_adc_default(void)
{
	//move to common.c : DemodAdcDefault
	return;
}

void drv_ifd_dac_default(void)
{
	//paste from script
	//register default
	rtd_outl(0xb8033000, 0x00022002);
	rtd_outl(0xb8033004, 0x00000000);
	rtd_outl(0xb8033008, 0x20000313);
	rtd_outl(0xb8033024, 0x00000000);

	rtd_maskl(0xb8033000, 0xeeeffff, 0x11100000);//Enable
	return;
}

void drv_ifd_power_on(bool enable)
{
	//move to common.c : AtvDemodPowerControl
	return;
}

void drv_ifd_adc_power_on(bool enable)
{
	//need implement
	return;
}

bool drv_ifd_adc_power_check(void)
{
	//need implement
	return _TRUE;
}

void drv_ifd_set_adcinput_swing(IFD_ADC_SHAGAIN setting1, IFD_ADC_FULLSCALE setting2)
{
#if 0 // Carol //
	tv_sb1_ana_ifadc_ctrl3_RBUS ifadc_ctrl2_rbus_data;

	ifadc_ctrl2_rbus_data.regValue = rtd_inl(TV_SB1_ANA_IFADC_CTRL3_reg);
	ifadc_ctrl2_rbus_data.reg_adc2x_vref_sel = setting2;
	rtd_outl(TV_SB1_ANA_IFADC_CTRL3_reg, ifadc_ctrl2_rbus_data.regValue);
#endif
}

void drv_ifd_adc_input_sel(IFD_ADC_INPUT_SEL input_source)
{
#if 0 // Carol //
	tv_sb1_ana_ifadc_ctrl3_RBUS ain_sel_rbus_data;

	ain_sel_rbus_data.regValue = rtd_inl(TV_SB1_ANA_IFADC_CTRL3_reg);
	ain_sel_rbus_data.reg_adc2x_insel = input_source;
	rtd_outl(TV_SB1_ANA_IFADC_CTRL3_reg, ain_sel_rbus_data.regValue);
#endif
}

void drv_ifd_adc_clock(IFD_CLK_RATE adc_clock)
{
	// adc clock fix at 162M
	return;
}

void drv_ifd_adc_clock_source_set(IFD_IFADC_MUX value)
{
	pll27x_reg_sys_pll_27x4_RBUS adc_clock_source_rbus_data;

	adc_clock_source_rbus_data.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);
	adc_clock_source_rbus_data.pll_ck_ifadc_mux = value;
	rtd_outl(PLL27X_REG_SYS_PLL_27X4_reg, adc_clock_source_rbus_data.regValue);
}

bool drv_ifd_adc_clock_source_get_info(void)
{
	pll27x_reg_sys_pll_27x4_RBUS adc_clock_source_rbus_data;

	adc_clock_source_rbus_data.regValue = rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg);
	return adc_clock_source_rbus_data.pll_ck_ifadc_mux;
}

void drv_ifd_adc_pga_gain_fix(bool enable, IFD_ADC_PGAFIX_CTRL fix_pga_gain)
{
	#if 0 // Carol //
	tv_sb1_ana_ifadc_ctrl2_RBUS ifdadc_ctrl1_rbus_data;

	ifdadc_ctrl1_rbus_data.regValue = rtd_inl(TV_SB1_ANA_IFADC_CTRL2_reg);
	ifdadc_ctrl1_rbus_data.reg_adc2x_fixgain = fix_pga_gain;
	rtd_outl(TV_SB1_ANA_IFADC_CTRL2_reg, ifdadc_ctrl1_rbus_data.regValue);
	#endif
}

#ifdef ENABLE_PWR_IP_CLOSE_SIRIUS
void drv_ifd_dac_openfordtv(bool enable)
{
#if 0
	VDAC_TV_CTRL2_RBUS VDAC_TV_CTRL2_reg;
	VDAC_TV_CTRL2_reg.regValue = IoReg_Read32(IFD_ANALOG_VDAC_TV_CTRL2_VADDR);
	if (enable) {
		VDAC_TV_CTRL2_reg.reg_vdac_vdac_en_tv = 1;
	} else {
		VDAC_TV_CTRL2_reg.reg_vdac_vdac_en_tv = 0;
	}
	IoReg_Write32(_VDAC_TV_CTRL2_VADDR, VDAC_TV_CTRL2_reg.regValue);
#endif
}
#endif

