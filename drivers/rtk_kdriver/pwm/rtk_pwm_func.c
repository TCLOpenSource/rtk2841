#include <linux/pwm.h>
#include <linux/platform_device.h>
#include <mach/pcbMgr.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/ppoverlay_reg.h>

#include <rtk_kdriver/rtk_pwm_crt.h>
#include <rtk_kdriver/rtk_pwm_func.h>
#include <rtk_kdriver/rtk_pwm.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-db.h>
#include <rtk_kdriver/pcbMgr.h>

#define DISABLE_DB 1

static int pwm_mode=0;
static int _gBacklightPwmPin = -1;
static int _gpwmindex = 0;
static R_CHIP_T _gstrchip[MAX_PWM_NODE];
static int m_printk_ioctl=0;
static int m_disable_ioctl=0;
static unsigned int m_ioctl_counter = 0;
static unsigned long iso_pwm_usage = 0;
static unsigned long misc_pwm_usage = 0;

int rtk_pwm_pcb_mgr_get(const char *pcbname,int ricindex)
{
	int ret = 0;
	ret = pcb_mgr_get_enum_info_byname((char *)pcbname,
					 &_gstrchip[ricindex].ullPcbMgrValue);
	return ret;
}

int rtk_pwm_pcb_mgr_get_value(RTK_PCB_ENUM *pcbinfo,int ricindex)
{
	int ret = 0;
	pcbinfo->value = _gstrchip[ricindex].ullPcbMgrValue;
	return ret;
}

int rtk_pwm_chip_index_get(int ricindex)
{
	return _gstrchip[ricindex].index;
}

unsigned long long rtk_pwm_chip_PcbMgrValue_get(int ricindex)
{
	return _gstrchip[ricindex].ullPcbMgrValue;
}

const rtk_pwm_reg_map* rtk_pwm_chip_reg_get(int ricindex)
{
	return _gstrchip[ricindex].reg;
}

const char* rtk_pwm_chip_pcbname_get(int ricindex)
{
	return _gstrchip[ricindex].pcbname;
}


void rtk_pwm_chip_device_set(struct platform_device *pdev)
{
	_gstrchip[pin_index_get()].pst_rtk_pwm_dev =pwm_get(&pdev->dev, pdev->name);
	//return _gstrchip[ricindex].pwm_device_st;
}

void pwm_mode_set(int mode)
{
	pwm_mode = mode;
}

int pwm_mode_get(void)
{
	return pwm_mode;
}

int rtk_pwm_backlight_pin_set(int ricindex)
{
	_gBacklightPwmPin = ricindex;
	return _gBacklightPwmPin;
}

int rtk_pwm_backlight_pin_get(void)
{
	return _gBacklightPwmPin;
}

void pin_index_count(void)
{
	_gpwmindex++;
}

int pin_index_get(void)
{
	return _gpwmindex;
}

void m_printk_ioctl_set(int en_printk)
{
	m_printk_ioctl = en_printk;
}

int m_printk_ioctl_get(void)
{
	return m_printk_ioctl;
}

void m_disable_ioctl_set(int disable)
{
	m_disable_ioctl = disable;
}

int m_disable_ioctl_get(void)
{
	return m_disable_ioctl;
}

void m_ioctl_counter_count(void)
{
	m_ioctl_counter++;
}

void m_ioctl_counter_set(unsigned int counter)
{
	m_ioctl_counter = counter;
}

unsigned int m_ioctl_counter_get(void)
{
	return m_ioctl_counter;
}

R_CHIP_T* rtk_pwm_chip_get_by_index(int m_index,int m_type)
{
	int i = 0;
	R_CHIP_T *pchip2 = NULL;
	int pwm_type = 0;

	for (i = 0; i < MAX_PWM_NODE; i++) {
		pchip2 = &_gstrchip[i];
		if(GET_PIN_TYPE(pchip2->ullPcbMgrValue) == PCB_PIN_TYPE_PWM)
			pwm_type = PWM_MISC;
		else if (GET_PIN_TYPE(pchip2->ullPcbMgrValue) == PCB_PIN_TYPE_ISO_PWM)
			pwm_type = PWM_ISO;

		if(pchip2->index == m_index && pwm_type == m_type)
			return &_gstrchip[i];
	}
	return NULL;
}

R_CHIP_T* rtk_pwm_chip_get_by_name(char* pcbname)
{
	int i = 0;
	R_CHIP_T *pchip2 = NULL;
	for (i = 0; i < MAX_PWM_NODE; i++) {
		pchip2 = &_gstrchip[i];

		if(strcmp(pchip2->pcbname,pcbname) == 0){
			//PWM_ERR("===> %s name match\n",pchip2->pcbname);
			return &_gstrchip[i];
		}
	}
	return NULL;
}

R_CHIP_T* rtk_pwm_chip_get(int m_index)
{
	return &_gstrchip[m_index];
}

/*************************************************************************
*** workaround for PWM support full HIGH and full low: change pwm to gpio.
*************************************************************************/
extern void rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value);

int rtk_pwm_gpio_value(R_CHIP_T *pchip2)
{
	return rtk_gpio_output_get(pchip2->gid);
}

void rtk_change_to_gpio_mode(R_CHIP_T *pchip2, GPIOPOT outputValue)
{
	if(INVALID_GPIO_GID == pchip2->gid || 0 == pchip2->pin_mux_info.addr){
		PWM_ERR("Probably pwm init get pinmux info error by pcbenum!\n");
		PWM_ERR("Change to gpio failed: addr:%ld pwmvalue:%d;Gid:%d;L:%d\n",
				pchip2->pin_mux_info.addr,
				pchip2->pin_mux_info.pwmValue,
				pchip2->gid, __LINE__);
		return;
	}

	if(PWM_MODE == pchip2->currentMode){
		pchip2->currentMode = GPIO_MODE;
		rtd_part_outl(pchip2->pin_mux_info.addr,
				pchip2->pin_mux_info.mask_h,
				pchip2->pin_mux_info.mask_l,
				pchip2->pin_mux_info.gpioValue);
	}
	rtk_gpio_output(pchip2->gid, outputValue);
	rtk_gpio_set_dir(pchip2->gid, 1);
}

void rtk_change_to_pwm_mode(R_CHIP_T *pchip2)
{
	if(0 == pchip2->pin_mux_info.addr){
		PWM_ERR("Probably pwm init get pinmux info error by pcbenum!\n");
		PWM_ERR("Change to pwm failed: addr:%ld pwmvalue:%d;Gid:%d;L:%d\n",
				pchip2->pin_mux_info.addr,
				pchip2->pin_mux_info.pwmValue,
				pchip2->gid, __LINE__);
		return;
	}

	if(GPIO_MODE == pchip2->currentMode){
		pchip2->currentMode = PWM_MODE;
		rtd_part_outl(pchip2->pin_mux_info.addr,
				pchip2->pin_mux_info.mask_h,
				pchip2->pin_mux_info.mask_l,
				pchip2->pin_mux_info.pwmValue);
	}
}

int rtk_pwm_backlight_set_duty( int duty )
{
	R_CHIP_T *pchip2 = NULL;
	pwm0_db_ctrl_RBUS dbReg;
	pwm0_duty_set_RBUS pwm_duty_set_reg;
	pwm0_ctrl_RBUS pwm_ctrl_reg;

	pr_debug(KERN_NOTICE "%s():\n", __FUNCTION__);

	if( duty > 255 || duty < 0) {
		PWM_ERR("backlight duty %d error!\n",duty );
		return -1;;
	}

	/*get pin index of backlight pwm*/
	if( rtk_pwm_backlight_pin_get() != (-1) ){
		pchip2 = &_gstrchip[rtk_pwm_backlight_pin_get()];
	}else{
		PWM_WARN("backlight pwm source is missed\n");
	}

#if PATCH_FOR_VDELAY
	*(_gp_pwm_mem_virt+3) = 0x0;

	rtk_pwm_ctrl_reg_read(pchip2,&pwm_ctrl_reg);
	rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
	rtk_pwm_db_enable(pchip2,&dbReg);

	rtk_pwm_db_update(pchip2,&dbReg);
	rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);//Write after dbReg because DB wr
#endif

	/*set duty */
	pchip2->rtk_duty = duty;
	rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
	rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);

	if( m_printk_ioctl > 0 ){

		PWM_WARN("%s set pwm[%d], duty=%d freq=%d lock=%d (pos=%d,%08x) adp = %d  adap_freq=%d mPlus=%d\n",
				__func__ ,
				pchip2->index,
				pchip2->rtk_duty,
				pchip2->rtk_freq,
				pchip2->rtk_vsync,
				pchip2->rtk_pos_start,
                pchip2->rtk_pos_start_clk,
                pchip2->rtk_adpt_en,
                pchip2->rtk_adapt_freq,
                pchip2->rtk_mPlus);
	}

	return 0;
}
EXPORT_SYMBOL(rtk_pwm_backlight_set_duty);

void getHVTotal(int *htotal, int *vtotal)
{
	ppoverlay_dh_total_last_line_length_RBUS dhReg;
	ppoverlay_dv_total_RBUS dvReg;

	dhReg.regValue = rtd_inl(PPOVERLAY_DH_TOTAL_LAST_LINE_LENGTH_VADDR);
	*htotal = dhReg.dh_total;

	dvReg.regValue = rtd_inl(PPOVERLAY_DV_TOTAL_VADDR);
	*vtotal = dvReg.dv_total;

	if (*htotal == 0) {
		PWM_ERR("Get 0 htotal, use 1 instead of 0\n");
		*htotal = 0x897;
	}

	if (*vtotal == 0) {
		PWM_ERR("Get 0 vtotal, use 0x464 instead of 0\n");
		*vtotal = 0x464;
	}

};


void get_v_delay(R_CHIP_T *pchip2)
{
	unsigned int phase_us=(1000000000/pchip2->rtk_adapt_freq)*
		pchip2->rtk_adapt_freq/pchip2->rtk_freq;

	pchip2->rtk_pos_start_clk = pchip2->rtk_pos_start*phase_us/pchip2->rtk_totalcnt / CONFIG_CPU_XTAL_NS;

	if(pchip2->rtk_pos_start_clk >=0x1fffff ||
		    pchip2->rtk_pos_start_clk <0) {

		PWM_ERR("PWM vsync overflow!\n");
		PWM_ERR("adapt_fre = %d, freq = %d, pos = %d, phase_us = %d\n",
			pchip2->rtk_adapt_freq, pchip2->rtk_freq,
			pchip2->rtk_pos_start, phase_us);

		pchip2->rtk_pos_start_clk= 1;
	}

};

/*porting from Ben:scalerDisplay.cpp
*/
void getDClk(int *dclk)
{
	pll27x_reg_sys_pll_disp1_RBUS pll_disp1_reg;
	pll27x_reg_pll_ssc0_RBUS  pll_ssc0_reg;
	pll27x_reg_sys_pll_disp3_RBUS pll_disp3_reg;
	sys_reg_sys_dispclksel_RBUS disp_clk_reg;
	unsigned int Mcode = 0, Ncode = 0, Fcode = 0, Odiv = 0 ;
	unsigned int temp = 0;

	pll_disp1_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_DISP1_reg);
	pll_ssc0_reg.regValue = rtd_inl(PLL27X_REG_PLL_SSC0_reg);
	pll_disp3_reg.regValue = rtd_inl(PLL27X_REG_SYS_PLL_DISP3_reg);
	disp_clk_reg.regValue = rtd_inl(SYS_REG_SYS_DISPCLKSEL_reg);

	Mcode = pll_disp1_reg.dpll_m;
	Ncode = pll_disp1_reg.dpll_n;
	Fcode = pll_ssc0_reg.fcode_t_ssc;

	Odiv = (0x1 << pll_disp3_reg.dpll_o);
	temp = 2700 * (Mcode + 3 + (Fcode/2048)) / ((Ncode + 2)*Odiv);

	//temp = temp/(0x1 << disp_clk_reg.dispd_osd_div);  // fixed me, no this member in header file
	*dclk = (temp * 10000);

}

int rtk_get_pwm_duty_base_change(int duty,int duty_max,int totalcnt)
{
    int base_duty = 0;
    base_duty =  DIV_ROUND_CLOSEST(duty*(totalcnt+1),(duty_max));
    return base_duty;
}

void rtk_hw_get_divider(int pwm_freq_hz, int duty_max, int *totalcnt,
			       unsigned short *M_best, unsigned short *N_best)
{
	int i , j= 0;
	unsigned long ftmp = 0, error = 0, error_best = 0;
	unsigned short N = 0;
	//unsigned short TotalCnt_best = 0;
	unsigned long pwmFreqHz = 0;
	
	if (pwm_freq_hz == 3) {
		*M_best = 0x3;
		*N_best = 0xfff;
		*totalcnt = duty_max;
	} 
	else if(pwm_freq_hz > 3 && pwm_freq_hz <= 1000){// For freq = 3~1000Hz,total cnt fixed 255
		pwmFreqHz = pwm_freq_hz;
		ftmp = (duty_max + 1) * pwm_freq_hz + 1;
		error_best = ftmp;
		for (i = 0; i <= M_MAX; i++) {

			N = (CONFIG_CPU_XTAL_FREQ / (1 << i)) / ftmp;

			if (N <= 0)
				N = 1;

			if (N > 0x1000)
				continue;

			error = ABS((CONFIG_CPU_XTAL_FREQ / (1 << i)) / N, ftmp);

			if (error < error_best) {
				error_best = error;
				*N_best = (unsigned short)N;
				*M_best = i;
			}
		}
		*totalcnt = duty_max;
	}
	else { // For freq > 1000Hz, totalcnt is variable
		pwmFreqHz = pwm_freq_hz;
		error_best = pwmFreqHz  + 1;
		for (j=duty_max; j<4097; j++) // Start duty_max=255 to find solution
		{
			for (i=0; i<=3; i++)
			{
				N = (CONFIG_CPU_XTAL_FREQ / (( 1 << i)*j*pwmFreqHz));

				if (N == 0)
					N=1;

				if (N > 0x1000)
					continue;

				//result = source_clock / (( 1 << i)*j*N)-pwmFreqHz;
				error = ABS(CONFIG_CPU_XTAL_FREQ / (( 1 << i)*j*N),pwmFreqHz);

				if(error == 0)
				{
					error_best = error;
					*N_best = N-1;
					*M_best = i;
					*totalcnt = j-1;
					break;
				}

				if (error < error_best)
				{
					error_best = error;
					*N_best = N-1;
					*M_best = i;
					*totalcnt = j-1;
				}
			}
			if (error == 0)
			{
				break;
			}
		}
	}
}


int rtk_pwm_set_freq(int inumber, int ifreq, int ifold,bool bEnableDB)
{
	R_CHIP_T *pchip2 = NULL;
	int iFreqTemp = 0;
	pwm0_db_ctrl_RBUS dbReg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
	pwm0_ctrl_RBUS pwm_ctrl_reg;

	pr_warn("%s()\n", __FUNCTION__);

	if(inumber >= _gpwmindex) {
		PWM_ERR("PWM index-%d error!\n",
			inumber);
		return -1;;
	}
	if(ifreq > 1000 || ifreq <=0) {
		PWM_ERR( "PWM freq %d error!\n",
			ifreq);
		return -1;;
	}
	if(ifold > 20 || ifold <=0) {
		PWM_ERR( "PWM freq %d ,%d-fold error!\n",
			ifreq, ifold);
		return -1;;
	}

	pchip2 = rtk_pwm_chip_get(inumber);
	pchip2->rtk_adapt_freq = rtk_pwm_get_adapt_freq(pchip2);


#if 1
	if(pchip2->rtk_adpt_en !=0)
	{

		iFreqTemp = pchip2->rtk_freq;

		if(ifreq%HZ_48 == 0) {
			iFreqTemp = pchip2->lg_freq48n;
		}else if(ifreq % HZ_50 == 0) {
			iFreqTemp = pchip2->lg_freq50n;
		}else if(ifreq % HZ_60 == 0) {
			iFreqTemp = pchip2->lg_freq60n;
		}else {
			iFreqTemp = ifreq*ifold;
		}
       // printk(KERN_EMERG"\033[1;31m  [sttest]%s,%s ,%d ,%d \n\033[m",__FILE__,__FUNCTION__ ,iFreqTemp,ifreq);

		if((iFreqTemp > 1000)&& iFreqTemp <= 0)
		{
			PWM_ERR("PWM[%d] illegal freq=%d fold=%d\n",inumber, ifreq, ifold);
			return -1;
		}
		pchip2->rtk_freq = iFreqTemp;
	}

#else

	pchip2->rtk_freq = ifreq*ifold;

#endif

	/*set timing ctrl , freq */
	rtk_pwm_timing_freq_set(pchip2,&pwm_timing_ctrl_reg);
	rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);


	/*set DB */
	rtk_pwm_ctrl_reg_read(pchip2,&pwm_ctrl_reg);
	rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
	rtk_pwm_db_enable(pchip2,&dbReg);

	dbReg.DB_RD_SEL =0;
	if (bEnableDB == false)
	{
		dbReg.pwm_global_delay_en = 1;
		//dbReg.DB_RD_SEL = 1;
	}
	rtk_pwm_db_update(pchip2,&dbReg);
	rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);//Write after dbReg because DB wr

	/*set DB */
	rtk_pwm_ctrl_reg_read(pchip2,&pwm_ctrl_reg);
	rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
	rtk_pwm_db_enable(pchip2,&dbReg);

	dbReg.DB_RD_SEL =0;
	if (bEnableDB == false)
	{
		dbReg.pwm_global_delay_en = 0;
		//dbReg.DB_RD_SEL = 0;
	}
	rtk_pwm_db_update(pchip2,&dbReg);
	rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);//Write after dbReg because DB wr

	if( m_printk_ioctl > 0 ){
	//	PWM_WARN("set pwm[%d], freq=%d adpt=%d \n",inumber, pchip2->rtk_freq, pchip2->rtk_adapt_freq);
		PWM_WARN("%s set pwm[%d], duty=%d freq=%d lock=%d (pos=%d,%08x) adp = %d  adap_freq=%d mPlus=%d\n",
				__func__ ,
				inumber,
				pchip2->rtk_duty,
				pchip2->rtk_freq,
				pchip2->rtk_vsync,
				pchip2->rtk_pos_start,
                pchip2->rtk_pos_start_clk,
                pchip2->rtk_adpt_en,
                pchip2->rtk_adapt_freq,
                pchip2->rtk_mPlus);
	}

	return 0;
}
EXPORT_SYMBOL(rtk_pwm_set_freq);

int rtk_pwm_get_adapt_freq(R_CHIP_T *pchip2)
{
	getHVTotal(&(pchip2->ht), &(pchip2->vt));
	getDClk(&(pchip2->dclk));
	return (pchip2->dclk/pchip2->ht/pchip2->vt);
}

int rtk_pwm_get_freq(R_CHIP_T *pchip2,unsigned short M, unsigned short N)
{
	int freq = 0;
	freq = CONFIG_CPU_XTAL_FREQ/(1 << M)/(N+1)/pchip2->rtk_duty_max;
	return freq;
}

void rtk_pwm_timing_update(R_CHIP_T *pchip2,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg)
{
	rtd_outl(pchip2->reg->TIMING_CTRL,pwm_timing_ctrl_reg->regValue);
}

void rtk_pwm_duty_update(R_CHIP_T *pchip2,pwm0_duty_set_RBUS* pwm_duty_set_reg)
{
	rtd_outl(pchip2->reg->DUTY_SET, pwm_duty_set_reg->regValue);
}

void rtk_pwm_ctrl_update(R_CHIP_T *pchip2,pwm0_ctrl_RBUS* pwm_ctrl_reg)
{
	rtd_outl(pchip2->reg->CTRL, pwm_ctrl_reg->regValue);//Write after dbReg because DB wr
}

void rtk_pwm_db_update(R_CHIP_T *pchip2,pwm0_db_ctrl_RBUS* dbReg)
{
	rtd_outl(pchip2->rtk_db_reg, dbReg->regValue);
}

void rtk_pwm_totalcnt_init(R_CHIP_T *pchip2,int rtk_totalcnt)
{
	pchip2->rtk_totalcnt = rtk_totalcnt;
}

void rtk_pwm_duty_probe_init(int duty, int duty_max, int *totalcnt, rtk_pwm_reg_map *regtable,pwm0_duty_set_RBUS* pwm_duty_set_reg)
{
	pwm_duty_set_reg->regValue = rtd_inl(regtable->DUTY_SET);
	pwm_duty_set_reg->pwm0_totalcnt = (*totalcnt);
	pwm_duty_set_reg->pwm0_dut = rtk_get_pwm_duty_base_change(duty,duty_max,*totalcnt);
	rtd_outl(regtable->DUTY_SET,pwm_duty_set_reg->regValue);
}

int rtk_pwm_hw_type_init(R_CHIP_T *pwmPin)
{
	unsigned long pwm_id;
	pwm_id = GET_PIN_INDEX(pwmPin->ullPcbMgrValue);
	if (GET_PIN_TYPE(pwmPin->ullPcbMgrValue) == PCB_PIN_TYPE_ISO_PWM) {

		if ((iso_pwm_usage &  (1<<pwm_id)))
			return -1;

		iso_pwm_usage |= 1<<pwm_id;

		rtk_hw_setting_power_on(CRT_PWM_ISO);

		snprintf(pwmPin->nodename, 16, "pwm-I-%d",
			 GET_PIN_INDEX(pwmPin->ullPcbMgrValue));

		pwmPin->reg =
			pwm_iso_phy[GET_PIN_INDEX(pwmPin->ullPcbMgrValue)].p_reg_map;

		pwmPin->rtk_db_reg = ISO_MIS_PWM_DB_CTRL_VADDR;

	} else if (GET_PIN_TYPE(pwmPin->ullPcbMgrValue) ==  PCB_PIN_TYPE_PWM) {

		if ((misc_pwm_usage &  (1<<pwm_id)))
			return -1;

		misc_pwm_usage |= 1<<pwm_id;

		rtk_hw_setting_power_on(CRT_PWM_MISC);

		snprintf(pwmPin->nodename, 16, "pwm-M-%d",
				 GET_PIN_INDEX(pwmPin->ullPcbMgrValue));

		pwmPin->reg =pwm_mis_phy[GET_PIN_INDEX(pwmPin->ullPcbMgrValue)].p_reg_map;

		pwmPin->rtk_db_reg = MIS_PWM_DB_CTRL_VADDR;
	} else {
		pwmPin->index = (-1);
		return -1;
	}

	pwmPin->index = GET_PIN_INDEX(pwmPin->ullPcbMgrValue);
	return 0;
}

void rtk_pwm_hw_pin_init(R_CHIP_T *pwmPin, int ricindex)
{
	unsigned short N = 0, M = 0;
	pwm0_ctrl_RBUS pwm_ctrl_reg;
	pwm0_duty_set_RBUS pwm_duty_set_reg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;

	pwmPin->index =GET_PIN_INDEX(pwmPin->ullPcbMgrValue);//ricindex;

	pwmPin->mapped = true;
	rtk_pwm_duty_reg_read(pwmPin,&pwm_duty_set_reg);
	rtk_pwm_timing_freq_reg_read(pwmPin,&pwm_timing_ctrl_reg);
	M = pwm_timing_ctrl_reg.pwm0_m;
	N = pwm_timing_ctrl_reg.pwm0_n;
	pwmPin->rtk_duty_max = GET_PWM_DUTY_MAX(pwmPin->ullPcbMgrValue);;
	pwmPin->rtk_totalcnt = pwm_duty_set_reg.pwm0_totalcnt;
	pwmPin->rtk_freq = rtk_pwm_get_freq(pwmPin,M,N);
	pwmPin->lg_freq48n = 96;
	pwmPin->lg_freq50n = 100;
	pwmPin->lg_freq60n = 120;
	pwmPin->rtk_duty = pwm_duty_set_reg.pwm0_dut;
/*
	pwmPin->rtk_duty_max = GET_PWM_DUTY_MAX(pwmPin->ullPcbMgrValue);
	pwmPin->rtk_freq = GET_PWM_FREQ(pwmPin->ullPcbMgrValue);
	pwmPin->lg_freq48n = 96;
	pwmPin->lg_freq50n = 100;
	pwmPin->lg_freq60n = 120;
	pwmPin->rtk_duty = GET_PWM_INIT_DUTY(pwmPin->ullPcbMgrValue);
*/
	rtk_pwm_ctrl_reg_read(pwmPin,&pwm_ctrl_reg);

	pwmPin->rtk_vsync = pwm_ctrl_reg.pwm0_vs_rst_en;
	pwmPin->rtk_enable = pwm_ctrl_reg.pwm0_en;
	pwmPin->rtk_polarity = pwm_ctrl_reg.pwm0l;
	pwmPin->rtk_mPlus = 0;//MAC5 no M+ flag

	pwmPin->rtk_adapt_freq =rtk_pwm_get_adapt_freq(pwmPin);

	if( pwmPin->rtk_vsync == 1 ){
		pwmPin->rtk_pos_start = pwm_ctrl_reg.pwm0_vs_delay_thr;
		pwmPin->rtk_pos_start_clk = pwm_ctrl_reg.pwm0_vs_delay_thr;
	}else{
		pwmPin->rtk_pos_start = 0;
		pwmPin->rtk_pos_start_clk = 1;
	}

	pwmPin->rtk_adpt_en = 0;

}

void rtk_pwm_ctrl_probe_init(int pwm_mode,int invert,R_CHIP_T *pchip2,rtk_pwm_reg_map *regtable,pwm0_ctrl_RBUS* pwm_ctrl_reg)
{
	pwm_ctrl_reg->regValue = rtd_inl(regtable->CTRL);
	pwm_ctrl_reg->pwm0l = (invert != 0);
	pwm_ctrl_reg->pwm0_ck = 1;
	pwm_ctrl_reg->pwm0_vs_rst_en = pchip2->rtk_vsync;
	pwm_ctrl_reg->pwm0_en = 1;
	pwm_ctrl_reg->pwm0_dut_8b = 0;
	pwm_ctrl_reg->pwm0_w_db_wr = 1;//From dbReg

	if(pwm_mode ==PWM_DRIVING_2CH_PHASE_DIFF){
		pwm_ctrl_reg->pwm0_vs_delay_thr = 1;
		pwm_ctrl_reg->pwm0_vs_delay_en = 1;
	}else{
		pwm_ctrl_reg->pwm0_vs_delay_thr = 1;
		pwm_ctrl_reg->pwm0_vs_delay_en = 0;
	}

	pwm_ctrl_reg->pwm0_vs_rst_en = pchip2->rtk_vsync;
	rtd_outl(regtable->CTRL, pwm_ctrl_reg->regValue);//Write after dbReg because DB wr
}

void rtk_pwm_timing_probe_init(int pwm_freq_hz, int duty_max,int *totalcnt,rtk_pwm_reg_map *regtable,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg)
{
	unsigned short N_best = 0, M_best = 0;
	rtk_hw_get_divider(pwm_freq_hz, duty_max, totalcnt,&M_best, &N_best);

	pwm_timing_ctrl_reg->regValue = rtd_inl(regtable->TIMING_CTRL);
	pwm_timing_ctrl_reg->pwm0_cnt_mode = 1;
	pwm_timing_ctrl_reg->pwm0_ck_sel = 0;
	pwm_timing_ctrl_reg->pwm0_m = M_best;
	pwm_timing_ctrl_reg->pwm0_n = N_best;
	rtd_outl(regtable->TIMING_CTRL,pwm_timing_ctrl_reg->regValue);
}

void rtk_pwm_timing_freq_reg_read(R_CHIP_T *pchip2,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg)
{
	pwm_timing_ctrl_reg->regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
}

void rtk_pwm_timing_freq_set(R_CHIP_T *pchip2,pwm0_timing_ctrl_RBUS* pwm_timing_ctrl_reg)
{
	unsigned short M = 0, N = 0;
	rtk_hw_get_divider(pchip2->rtk_freq,pchip2->rtk_duty_max,&pchip2->rtk_totalcnt, &M, &N);

	pwm_timing_ctrl_reg->regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
	pwm_timing_ctrl_reg->pwm0_m = M;
	pwm_timing_ctrl_reg->pwm0_n = N;
}

void rtk_pwm_user_setting(R_CHIP_T *pchip2,RTK_PWM_INFO_T *stpwminfo)
{
	pchip2->rtk_enable = stpwminfo->m_run;
	pchip2->rtk_duty = stpwminfo->m_duty;
	pchip2->rtk_vsync = stpwminfo->m_vsync?1:0;
	pchip2->rtk_adpt_en= stpwminfo->m_adpt_en;
	pchip2->rtk_pos_start = stpwminfo->m_pos;

	if(stpwminfo->m_adpt_en) {
			if(pchip2->rtk_adapt_freq == HZ_48) {
				pchip2->rtk_freq = stpwminfo->m_freq48n;
				pchip2->lg_freq48n = stpwminfo->m_freq48n;
			}else if(pchip2->rtk_adapt_freq == HZ_50) {
				pchip2->rtk_freq = stpwminfo->m_freq50n;
				pchip2->lg_freq50n = stpwminfo->m_freq50n;
			}else if(pchip2->rtk_adapt_freq == HZ_60) {
				pchip2->rtk_freq = stpwminfo->m_freq60n;
				pchip2->lg_freq60n = stpwminfo->m_freq60n;
			}else if(((pchip2->rtk_adapt_freq >= 51)&&(pchip2->rtk_adapt_freq <= 59) )
			||((pchip2->rtk_adapt_freq >= 45)&&(pchip2->rtk_adapt_freq <= 47))){

				pchip2->rtk_freq = pchip2->rtk_adapt_freq*2;
				pchip2->lg_freq60n = stpwminfo->m_freq60n;

				PWM_WARN("PWM[%d]  special freq=%d \n",
					stpwminfo->m_index,
					pchip2->rtk_adapt_freq);

			}else {
				PWM_ERR("PWM[%d] illegal freq=%d \n",
					stpwminfo->m_index,
					pchip2->rtk_adapt_freq);

				pchip2->rtk_freq = stpwminfo->m_freq60n;
			}
		}else{
			pchip2->rtk_freq = stpwminfo->m_freq;
		}
}

unsigned long rtk_pwm_duty_get(R_CHIP_T *pchip2,int duty, int totalcnt)
{
	return (duty)*(pchip2->rtk_duty_max) / totalcnt;
}

void rtk_pwm_duty_reg_read(R_CHIP_T *pchip2,pwm0_duty_set_RBUS* pwm_duty_set_reg)
{
	pwm_duty_set_reg->regValue = rtd_inl(pchip2->reg->DUTY_SET);
}

void rtk_pwm_duty_set(R_CHIP_T *pchip2,pwm0_duty_set_RBUS* pwm_duty_set_reg)
{
	pwm_duty_set_reg->regValue = rtd_inl(pchip2->reg->DUTY_SET);
	pwm_duty_set_reg->pwm0_dut = rtk_get_pwm_duty_base_change(pchip2->rtk_duty,pchip2->rtk_duty_max,pchip2->rtk_totalcnt);
	pwm_duty_set_reg->pwm0_totalcnt = pchip2->rtk_totalcnt;
}

void rtk_pwm_ctrl_reg_read(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	pwm_ctrl_reg->regValue = rtd_inl(pchip2->reg->CTRL);
}

void rtk_pwm_ctrl_vdelay_enable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	//pwm_ctrl_reg->regValue = rtd_inl(pchip2->reg->CTRL);
	pwm_ctrl_reg->pwm0_vs_delay_thr = pchip2->rtk_pos_start_clk;
	pwm_ctrl_reg->pwm0_vs_delay_en = 1;
}
void rtk_pwm_ctrl_vdelay_disable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	pwm_ctrl_reg->pwm0_vs_delay_thr = 0;
	pwm_ctrl_reg->pwm0_vs_delay_en = 0;
}

void rtk_pwm_ctrl_polarity(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	pwm_ctrl_reg->pwm0l = pchip2->rtk_polarity;
}

void rtk_pwm_ctrl_output_enable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	pwm_ctrl_reg->pwm0_en = pchip2->rtk_enable;
}

void rtk_pwm_ctrl_vsync_enable(R_CHIP_T *pchip2,pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	pwm_ctrl_reg->pwm0_vs_rst_en = pchip2->rtk_vsync;
}

void rtk_pwm_ctrl_db_wr(pwm0_ctrl_RBUS *pwm_ctrl_reg)
{
	#ifdef DISABLE_DB
		pwm_ctrl_reg->pwm0_w_db_wr = 0;//pchip2->rtk_vsync;   // please check this bit , too strange
	#else
		pwm_ctrl_reg->pwm0_w_db_wr = 1;//pchip2->rtk_vsync;   // please check this bit , too strange
	#endif
}

void rtk_pwm_db_enable(R_CHIP_T *pchip2,pwm0_db_ctrl_RBUS* dbReg)
{
	/*set DB *///Double buffer always enable
	dbReg->regValue = rtd_inl(pchip2->rtk_db_reg);
#ifdef DISABLE_DB
	dbReg->pwm_w_db_mode = 0;
	dbReg->pwm_w_db_en = 0;
#else
	dbReg->pwm_w_db_mode = 1;
	dbReg->pwm_w_db_en = 1;
#endif
}



int rtk_pwm_backlight_enable(int enable)
{
	int gpioLevel = 0;
	unsigned long long param = 0 ;


	if( enable < 0 )
	{
		gpioLevel = 0;
		PWM_WARN("%s enable = %d , too strange \n", __func__, enable );
	}
	else if( enable > 1 )
	{
		gpioLevel = 1;
	}
	else
	{
		gpioLevel = enable ;
	}


	if (pcb_mgr_get_enum_info_byname("PIN_BL_ON_OFF", &param) != 0)
	{
		PWM_WARN("%s PIN_BL_ON_OFF is not existed , please check pcb parameters = 0x%X \n", __func__, param);
		return (-1);
	}

	PWM_WARN("%s PIN_BL_ON_OFF = 0x%X gpio_type = %d gpio_num=%d\n", __func__, GET_PIN_TYPE(param) , GET_PIN_INDEX(param) );

	if ( rtk_SetIOPin(param, gpioLevel) != 0 )
	{
		PWM_WARN("%s output operation fail!\n", __func__ );
		return (-1);
	}

	if ( rtk_SetIOPinDirection(param, 1) != 0 )
	{
		PWM_WARN("%s direction operation fail!\n", __func__ );
		return (-1);
	}

	return 0;
}
EXPORT_SYMBOL(rtk_pwm_backlight_enable);

