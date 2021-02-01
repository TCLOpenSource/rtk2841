#include <rtk_kdriver/rtk_pwm.h>
#include <rtk_kdriver/rtk_pwm_func.h>
#include <rtk_kdriver/rtk_pwm_crt.h>
#include <rtk_kdriver/rtk_crt.h>	/*htotal, vtotoal, clk_sel */
#include <rbus/stb_reg.h>	
#include <rbus/sys_reg_reg.h>
/*---------------------------------------------------------------------
//Realtek Hardware related function
//The naming rule : starts with rtk_hw_setting_XX
//---------------------------------------------------------------------*/
static bool iso_pwm_on = true;
static bool misc_pwm_on = true;

void rtk_hw_setting_power_on(int type)
{
	/*type =0 : iso , type =1 misc */
	if (type == 0 && iso_pwm_on == false) {
		if (!(rtd_inl(STB_ST_CLKEN0_reg) &
			    BIT(STB_ST_CLKEN0_clken_pwm_shift))) {

			CRT_CLK_OnOff(PWM, CLK_ON, &type);
		}
		iso_pwm_on = true;

	} else if (type == 1 && misc_pwm_on == false) {
		if (!(rtd_inl(SYS_REG_SYS_CLKEN2_reg) &
		     BIT(SYS_REG_SYS_CLKEN2_clken_pwm_shift))) {

			CRT_CLK_OnOff(PWM, CLK_ON, &type);
		}
		misc_pwm_on = true;
	}
};

void rtk_hw_setting_power_off(int type)
{
	if (type == 0) {

		CRT_CLK_OnOff(PWM, CLK_OFF, &type);

		iso_pwm_on = false;
	} else if (type == 1) {

		CRT_CLK_OnOff(PWM, CLK_OFF, &type);

		misc_pwm_on = false;
	}
};
