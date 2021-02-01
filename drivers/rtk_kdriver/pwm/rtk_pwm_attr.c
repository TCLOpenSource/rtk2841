#include <linux/types.h>
#include <linux/platform_device.h>
#include <rtk_kdriver/rtk_pwm.h>
#include <rtk_kdriver/rtk_pwm_func.h>
#include <rtk_kdriver/rtk_pwm_video.h>

ssize_t rtk_pwm_show_param(struct device *dev, struct device_attribute *attr,
			   char *buf)
{
	int ret = 0;
	R_CHIP_T *pchip2 = NULL;
	if (dev->platform_data != NULL) {
		pchip2 = (R_CHIP_T *) dev->platform_data;
		if (pchip2->mapped == false) {
			PWM_WARN("[PWM]Warning! This PWM isn't initialize.\n");
			return 0;
		}
	}
	if (strncmp(attr->attr.name, "run", 3) == 0) {
		ret = sprintf(buf, "%d\n", pchip2->rtk_enable);
	} else if (strncmp(attr->attr.name, "duty", 4) == 0) {
		ret = sprintf(buf, "%d\n", pchip2->rtk_duty);
	} else if (strncmp(attr->attr.name, "vsync", 5) == 0) {
		ret = sprintf(buf, "%d\n", pchip2->rtk_vsync);
	} else if (strncmp(attr->attr.name, "freq", 4) == 0) {
		ret = sprintf(buf, "%d\n", pchip2->rtk_freq);
	} else if (strncmp(attr->attr.name, "polarity", 8) == 0) {
		ret = sprintf(buf, "%d\n", pchip2->rtk_polarity);
	} else if (strncmp(attr->attr.name, "pos", 3) == 0) {
		ret = sprintf(buf, "(%d, %08x)\n", pchip2->rtk_pos_start,pchip2->rtk_pos_start_clk);
	} else if (strncmp(attr->attr.name, "frdvp", 5) == 0) {
		ret = 0;
	} else if (strncmp(attr->attr.name, "adapt_freq", 10) == 0) {
		pchip2->rtk_adapt_freq =rtk_pwm_get_adapt_freq(pchip2);
		ret = sprintf(buf, "%d\n", pchip2->rtk_adapt_freq);
	} else if (strncmp(attr->attr.name, "disable_ioctl", strlen("disable_ioctl")) == 0) {
		ret = sprintf(buf, "%d\n", m_disable_ioctl_get());
	} else if (strncmp(attr->attr.name, "printk_ioctl", strlen("printk_ioctl")) == 0) {
		ret = sprintf(buf, "%d\n", m_printk_ioctl_get());
	} else if (strncmp(attr->attr.name, "ioctlCounter", strlen("ioctlCounter")) == 0) {
		ret = sprintf(buf, "%u\n", m_ioctl_counter_get());
	} else if (strncmp(attr->attr.name, "mPlus", strlen("mPlus")) == 0) {
		ret = sprintf(buf, "%d\n", pchip2->rtk_mPlus );
	} else if (strncmp(attr->attr.name, "mode", strlen("mode")) == 0) {
		ret = sprintf(buf, "%s\n", (pchip2->currentMode == PWM_MODE) ? "PWM_MODE":"GPIO_MODE");
	} else if (strncmp(attr->attr.name, "panel", strlen("panel")) == 0) {
		if( pwm_mode_get() == PWM_DRIVING_LED_CURRENT)
			ret = sprintf(buf, "%s\n", "LED_CURRENT" );
		else if( pwm_mode_get() == PWM_DRIVING_2CH_PHASE_SAME)
			ret = sprintf(buf, "%s\n", "2CH_PHASE_SAME" );
		else if( pwm_mode_get() == PWM_DRIVING_2CH_PHASE_DIFF)
			ret = sprintf(buf, "%s\n", "2CH_PHASE_DIFF" );
		else
			ret = sprintf(buf, "%s\n", "No this Panel type" );
	}else if (strncmp(attr->attr.name, "Mduty", strlen("Mduty")) == 0) {
		int i = 0;
		int mPlus_duty = 0;
		int pwm_duty = 0;
		int final_duty = 0;
		R_CHIP_T *pchip2 = NULL;
		
		for (i = 0; i < pin_index_get(); i++) {
			pchip2 = rtk_pwm_chip_get(i);
			rtd_inl(pchip2->reg->DUTY_SET);
			pwm_duty = pchip2->rtk_duty;
			mPlus_duty = rtd_inl(PWM_M_PLUS_VADDR) && (PWM_M_PLUS_MASK);
			//Duty formula Output duty (%)= ((PWM duty/256)*100%) * ((M+ duty /4096)*100%)
			final_duty = (((pwm_duty*100)/256) * ((mPlus_duty*100)/4096));
			ret = sprintf(buf,"PWM%d_duty: %d %d %d\n",i,pwm_duty,mPlus_duty,final_duty);
			//ret = sprintf(buf,"PWM%d_duty:%d M+_duty:%d Final_duty:%d%%\n",i,pwm_duty,mPlus_duty,final_duty);
		}
	}else if (strncmp(attr->attr.name, "status", strlen("status")) == 0) {
		pchip2->rtk_adapt_freq =rtk_pwm_get_adapt_freq(pchip2);
		
		ret = sprintf(buf, "[%s] en=%d, freq=%d Hz, duty=%d, polarity=%d, vsync_rst=%d, (pos=%d,%08x), adap_freq=%d, mPlus=%d\n", 
				pchip2->nodename,
				pchip2->rtk_enable, 
				pchip2->rtk_freq, 
				pchip2->rtk_duty,
				pchip2->rtk_polarity,
				pchip2->rtk_vsync,
				pchip2->rtk_pos_start,
				pchip2->rtk_pos_start_clk,
				pchip2->rtk_adapt_freq,
				pchip2->rtk_mPlus);
	}

	return ret;
}

ssize_t rtk_pwm_store_param(struct device *dev, struct device_attribute *attr,
			    const char *buf, size_t count)
{
	int val = 0;
	R_CHIP_T *pchip2 = NULL;
	pwm0_ctrl_RBUS pwm_ctrl_reg;
	pwm0_duty_set_RBUS pwm_duty_set_reg;
	pwm0_db_ctrl_RBUS dbReg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;

	if (dev->platform_data != NULL) {
		pchip2 = (R_CHIP_T *) dev->platform_data;
		if (pchip2->mapped == false)
			return 0;
	}

	sscanf(buf, "%d\n", &val);

	if (strncmp(attr->attr.name, "disable_ioctl", strlen("disable_ioctl")) == 0) {

		if (val == 0 || val == 1)
			m_disable_ioctl_set(val);
		else
			PWM_WARN("PWM disable Fail!\n");

	}else if (strncmp(attr->attr.name, "printk_ioctl", strlen("printk_ioctl")) == 0) {

		if (val == 0 || val == 1)
			m_printk_ioctl_set(val);
		else
			PWM_WARN("PWM printk ioctrl Fail!\n");

	}else if (strncmp(attr->attr.name, "ioctlCounter", strlen("ioctlCounter")) == 0) {

		m_ioctl_counter_set(val);
		PWM_WARN("set ioctlCounter to %u \n" , m_ioctl_counter_get() );

	}else if (strncmp(attr->attr.name, "run", 3) == 0) {

		if (val == 0 || val == 1)
			pchip2->rtk_enable = val;
		else
			PWM_WARN("PWM run Fail!\n");

	} else if (strncmp(attr->attr.name, "duty", 4) == 0) {

		if (val <= 0)
			val = 0;
		else if (val >= pchip2->rtk_duty_max)
			val = pchip2->rtk_duty_max;

		pchip2->rtk_duty = val;

	} else if (strncmp(attr->attr.name, "vsync", 5) == 0) {

		if (val == 0 || val == 1)
			pchip2->rtk_vsync = val;
		else
			PWM_WARN("PWM Write vsync Fail!\n");

	} else if (strncmp(attr->attr.name, "freq", 4) == 0) {

		/*if (val <= 4)
			val = 4;
		else if (val >= MAX_PWM_FREQ)
			val = MAX_PWM_FREQ;*/

		pchip2->rtk_freq = val;

	} else if (strncmp(attr->attr.name, "polarity", 8) == 0) {

		if (val == 0 || val == 1)
			pchip2->rtk_polarity = val;
		else
			PWM_WARN("PWM Write polarity Fail!\n");

	} else if (strncmp(attr->attr.name, "adapt_freq", 10) == 0) {

		pchip2->rtk_adapt_freq =rtk_pwm_get_adapt_freq(pchip2);

	} else if (strncmp(attr->attr.name, "pos", 3) == 0) {

		if (val >=0 && val <=255) {
			pchip2->rtk_pos_start = val;
			get_v_delay(pchip2);
		}else{
			PWM_WARN("PWM Write pos Fail!\n");
		}

	} else if (strncmp(attr->attr.name, "mPlus", 5) == 0) {

		if (val == 0 || val == 1)
			pchip2->rtk_mPlus = val;
		else
			PWM_WARN("PWM change mPlus Fail!\n");

	} else if (strncmp(attr->attr.name, "mode", 4) == 0) {

		if (val == PWM_MODE || val == GPIO_MODE)
			pchip2->currentMode = val;
		else
			PWM_WARN("PWM change mode Fail!\n");
	} else if (strncmp(attr->attr.name, "apply", 5) == 0) {
		if (val == 1) {

			/*set timing ctrl , freq */
			rtk_pwm_timing_freq_set(pchip2,&pwm_timing_ctrl_reg);

			/*set duty */
			rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);

			/*set CTRL */
			rtk_pwm_ctrl_reg_read(pchip2,&pwm_ctrl_reg);
			rtk_pwm_ctrl_polarity(pchip2,&pwm_ctrl_reg);
			rtk_pwm_ctrl_output_enable(pchip2,&pwm_ctrl_reg);
			rtk_pwm_ctrl_vsync_enable(pchip2,&pwm_ctrl_reg);
			rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
			
			/*vsync delay*/
			if(pchip2->rtk_pos_start > 0 && pchip2->rtk_vsync) {
				rtk_pwm_ctrl_vdelay_enable(pchip2,&pwm_ctrl_reg);
			}else{
				rtk_pwm_ctrl_vdelay_disable(pchip2,&pwm_ctrl_reg);
			}
			
			rtk_pwm_db_enable(pchip2,&dbReg);


			rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);
			rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);
			rtk_pwm_db_update(pchip2,&dbReg);
			rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);

			if(pchip2->currentMode == GPIO_MODE){
				if(pchip2->rtk_duty == pchip2->rtk_duty_max)
					rtk_change_to_gpio_mode(pchip2,GPIO_PIN_HIGH);
				else if(pchip2->rtk_duty == 0)
					rtk_change_to_gpio_mode(pchip2,GPIO_PIN_LOW);
			}else if(pchip2->currentMode == PWM_MODE){
				rtk_change_to_pwm_mode(pchip2);
			}

			videoPwmAction_Yes();

		}
	}

	return count;
}



static DEVICE_ATTR(run,          S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(duty,         S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(vsync,        S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(freq,         S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(polarity,     S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(adapt_freq,   S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(apply,        S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(pos,          S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(disable_ioctl,S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(status,       S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);	    
static DEVICE_ATTR(printk_ioctl, S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(ioctlCounter, S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(mPlus,        S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(panel,        S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(Mduty,        S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);
static DEVICE_ATTR(mode,         S_IWUSR|S_IWGRP|S_IRUGO, rtk_pwm_show_param, rtk_pwm_store_param);

void rtk_pwm_create_attr(struct device *device)
{
	device_create_file(device,&dev_attr_run);
	device_create_file(device,&dev_attr_duty);
	device_create_file(device,&dev_attr_freq);
	device_create_file(device,&dev_attr_Mduty);
	device_create_file(device,&dev_attr_vsync);
	device_create_file(device,&dev_attr_polarity);
	device_create_file(device,&dev_attr_adapt_freq);
	device_create_file(device,&dev_attr_pos);
	device_create_file(device,&dev_attr_apply);
	device_create_file(device,&dev_attr_disable_ioctl);
	device_create_file(device,&dev_attr_status);
	device_create_file(device,&dev_attr_printk_ioctl);
	device_create_file(device,&dev_attr_ioctlCounter);
	device_create_file(device,&dev_attr_mPlus);
	device_create_file(device,&dev_attr_panel);
	device_create_file(device,&dev_attr_mode);
}

void rtk_pwm_remove_attr(struct device *device)
{
	device_remove_file(device, &dev_attr_run);
	device_remove_file(device, &dev_attr_duty);
	device_remove_file(device, &dev_attr_freq);
	device_remove_file(device, &dev_attr_Mduty);
	device_remove_file(device, &dev_attr_vsync);
	device_remove_file(device, &dev_attr_polarity);
	device_remove_file(device, &dev_attr_adapt_freq);
	device_remove_file(device, &dev_attr_pos);
	device_remove_file(device, &dev_attr_apply);
	device_remove_file(device, &dev_attr_disable_ioctl);
	device_remove_file(device, &dev_attr_status);
	device_remove_file(device, &dev_attr_printk_ioctl);
	device_remove_file(device, &dev_attr_ioctlCounter);
	device_remove_file(device, &dev_attr_mPlus);
	device_remove_file(device, &dev_attr_panel);
	device_remove_file(device, &dev_attr_mode);
}
