/******************************************************************************
*
*   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
*
*   @author baker.cheng@realtek.com
*
******************************************************************************/

#include <linux/export.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/pwm.h>
#include <linux/module.h>
#include <linux/stat.h>
#include <linux/types.h>

#include <mach/rtk_platform.h>
#include <mach/pcbMgr.h>

#include <linux/fs.h> /*file operators*/
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <uapi/asm/byteorder.h>

#include <rtk_kdriver/rtk_pwm-reg.h>
#include <rtk_kdriver/rtk_pwm_crt.h>
#include <rtk_kdriver/rtk_pwm_func.h>
#include <rtk_kdriver/rtk_pwm_local_dimming.h>
#include <rtk_kdriver/rtk_pwm_video.h>
#include <rtk_kdriver/rtk_pwm_attr.h>
#include <rtk_kdriver/rtk_pwm.h>
#include <rtk_kdriver/tvscalercontrol/panel/panelapi.h>


int dev_major;
int dev_minor;
struct cdev *dev_cdevp = NULL;
static struct device *pwm_device_st;


static struct platform_device *pst_rtk_pwm_platform_dev;
static struct class *_gstpwm_class;
RTK_PCB_ENUM _gPWMNamelist[MAX_PWM_COUNT]= {0};
static int _gPwmCount = 0;
static unsigned int s_rtk_pos_start = 0;

int rtk_pwm_open(struct inode *inode, struct file *filp)
{
#if PATCH_FOR_VDELAY
	/*for vcpu isr*/
	rtk_pwm_send_mem();
#endif
	return 0;
}

ssize_t rtk_pwm_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
	PWM_WARN("%s():\n", __FUNCTION__);
	return -EFAULT;
}
ssize_t rtk_pwm_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
	PWM_WARN("%s():\n", __FUNCTION__);
	return -EFAULT;
}

static
int rtk_pwm_set_param_ex(RTK_PWM_PARAM_EX_T* param)
{
    int ret = PWM_OK;

    pwm0_ctrl_RBUS pwm_ctrl_reg;
    pwm0_duty_set_RBUS pwm_duty_set_reg;
    pwm0_db_ctrl_RBUS dbReg;
    pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
    R_CHIP_T *pchip2 = NULL;

    pchip2 = rtk_pwm_chip_get_by_name(param->pcbname);
    if(pchip2 == NULL){
        ret = (-PWM_PCB_ENUM_ERROR);
        PWM_ERR("PWM %s chip get error!\n",param->pcbname);
        return ret;
    }

    /** Read Register status **/
    pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
    dbReg.regValue = rtd_inl(pchip2->rtk_db_reg);

    switch (param->id) {
        case PWM_PARAM_POLARITY:
            if((param->val != 0) && (param->val != 1)){
                PWM_ERR("SET %s  POLARITY INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_POLARITY_INVALID);
            }

            pchip2->rtk_polarity = param->val;
            rtk_pwm_ctrl_polarity(pchip2,&pwm_ctrl_reg);

            if( m_printk_ioctl_get() > 0 )
                PWM_ERR("SET %s POLARITY param_val:%ld\n",pchip2->nodename,param->val);

            break;

        case PWM_PARAM_FREQUENCY:
            if((param->val < 4) || (param->val > MAX_PWM_FREQ)){
                PWM_ERR("SET %s  FREQEUNCY INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_FREQEUNCY_INVALID);
            }

            pchip2->rtk_freq = param->val;
            rtk_pwm_timing_freq_set(pchip2,&pwm_timing_ctrl_reg);
            rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);

            rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
            rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);


            if( m_printk_ioctl_get() > 0 )
                PWM_ERR("SET %s FREQUENCY param_val:%ld\n",pchip2->nodename,param->val);

            break;

        case PWM_PARAM_DUTY:

            if(param->val < 0){
                PWM_ERR("SET %s  DUTY INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_DUTY_INVALID);
            }

            pchip2->rtk_duty = param->val;
            rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
            rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);

            if( m_printk_ioctl_get() > 0 )
                PWM_ERR("SET %s DUTY param_val:%ld\n",pchip2->nodename,param->val);

            break;

        case PWM_PARAM_VSYNC_RESET:
            if((param->val != 0) && (param->val != 1)){
                PWM_ERR("SET %s VSYNC INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_VSYNC_INVALID);
            }

            s_rtk_pos_start = pchip2->rtk_vsync = param->val;
            rtk_pwm_ctrl_vsync_enable(pchip2,&pwm_ctrl_reg);

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("SET %s VSYNC param_val:%ld\n",pchip2->nodename,param->val);
            break;

        case PWM_PARAM_OUTPUT:
            if((param->val != 0) && (param->val != 1)){
                PWM_ERR("SET %s OUTPUT INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_OUTPUT_INVALID);
            }

            pchip2->rtk_enable = param->val;
            rtk_pwm_ctrl_output_enable(pchip2,&pwm_ctrl_reg);
            if( m_printk_ioctl_get() > 0 )
                PWM_ERR("SET %s OUTPUT param_val:%ld\n",pchip2->nodename,param->val);
            break;
        case PWM_PARAM_TOTALCNT:
            if((param->val < 0) && (param->val > 360)){
                PWM_ERR("SET %s TOTALCNT INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_TOTALCNT_INVALID);
            }

            pchip2->rtk_totalcnt = param->val;
            rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
            rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);
            if( m_printk_ioctl_get() > 0 )
                PWM_ERR("SET %s TOTALCNT param_val:%ld\n",pchip2->nodename,param->val);
            break;
        case PWM_PARAM_VSYNC_DELAY:
            if((param->val < 0) || (param->val > pchip2->rtk_totalcnt)){
                PWM_ERR("SET %s  VSYNC_DELAY INVALID param_val:%ld\n",pchip2->nodename,param->val);
                return (-PWM_VSYNC_DELAY_INVALID);
            }
            pchip2->rtk_pos_start = param->val;
            get_v_delay(pchip2);
            /*vsync delay*/
            if(pchip2->rtk_pos_start > 0 && pchip2->rtk_vsync) {
                rtk_pwm_ctrl_vdelay_enable(pchip2,&pwm_ctrl_reg);
            }else{
                rtk_pwm_ctrl_vdelay_disable(pchip2,&pwm_ctrl_reg);
            }
            break;
        default:
            ret = (-PWM_PARAM_ID_INVALID);
    }

    if(ret == PWM_OK){
        /*set DB */
        rtk_pwm_db_enable(pchip2,&dbReg);
        rtk_pwm_db_update(pchip2,&dbReg);
        rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
        rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);

        videoPwmAction_Yes();
    }

    return ret;
}

int set_pwm_freq_totalcnt_vsyncdelay(char *pcbname,unsigned long rtk_freq_val,unsigned long rtk_totalcnt_val,unsigned long rtk_pos_start_val){

	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
	pwm0_duty_set_RBUS pwm_duty_set_reg;
	pwm0_ctrl_RBUS pwm_ctrl_reg;
	R_CHIP_T *pchip2 = NULL;

	pchip2 = rtk_pwm_chip_get_by_name(pcbname);

	    /** Read Register status **/
    	pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    	pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    	pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
	
	// PWM_PARAM_FREQUENCY:
	if((rtk_freq_val < 4) || (rtk_freq_val > MAX_PWM_FREQ)){
	    PWM_ERR("SET %s  FREQEUNCY INVALID param_val:%ld\n",pchip2->nodename,rtk_freq_val);
	    return -1;
	}

	if(pchip2->rtk_duty == 0)
		pchip2->rtk_duty = 256;
	
	pchip2->rtk_freq = rtk_freq_val;
	
	rtk_pwm_timing_freq_set(pchip2,&pwm_timing_ctrl_reg);
	rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);

	rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
	rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);

	
//-------------
	// PWM_PARAM_TOTALCNT:
	if((rtk_totalcnt_val <= 0) || (rtk_totalcnt_val >= 360)){
	    PWM_ERR("SET %s TOTALCNT INVALID param_val:%ld\n",pchip2->nodename,rtk_totalcnt_val);
	    return -1;
	}

	pchip2->rtk_totalcnt = rtk_totalcnt_val;
	rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
	rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);
	
//-------------	
	// PWM_PARAM_VSYNC_DELAY:
	if((rtk_pos_start_val < 0) || (rtk_pos_start_val > pchip2->rtk_totalcnt)){
	    PWM_ERR("SET %s  VSYNC_DELAY INVALID param_val:%ld\n",pchip2->nodename,rtk_pos_start_val);
	    return -1;
	}
	pchip2->rtk_pos_start = rtk_pos_start_val;
	get_v_delay(pchip2);
	/*vsync delay*/
	if(pchip2->rtk_pos_start > 0 && pchip2->rtk_vsync) {
	    rtk_pwm_ctrl_vdelay_enable(pchip2,&pwm_ctrl_reg);
	}else{
	    rtk_pwm_ctrl_vdelay_disable(pchip2,&pwm_ctrl_reg);
	}
	
}

static
int rtk_pwm_get_param_ex(RTK_PWM_PARAM_EX_T* param)
{
    int ret = PWM_OK;
    unsigned short M = 0, N = 0;
    pwm0_ctrl_RBUS pwm_ctrl_reg;
    pwm0_duty_set_RBUS pwm_duty_set_reg;
    pwm0_db_ctrl_RBUS dbReg;
    pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
    R_CHIP_T *pchip2 = NULL;

    pchip2 = rtk_pwm_chip_get_by_name(param->pcbname);
    if(pchip2 == NULL){
        ret = (-PWM_PCB_ENUM_ERROR);
        PWM_ERR("PWM %s chip get error!\n",param->pcbname);
        return ret;
    }

    /** Read Register status **/
    pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
    dbReg.regValue = rtd_inl(pchip2->rtk_db_reg);

    switch (param->id) {
        case PWM_PARAM_POLARITY:
            param->val = pwm_ctrl_reg.pwm0l;

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET %s POLARITY param_val:%ld\n",pchip2->nodename,param->val);

            break;
        case PWM_PARAM_FREQUENCY:
            M = pwm_timing_ctrl_reg.pwm0_m;
            N = pwm_timing_ctrl_reg.pwm0_n;
            param->val = ((CONFIG_CPU_XTAL_FREQ / (1 << M)) / (N+1) / pchip2->rtk_duty_max);

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET %s FREQUENCY param_val:%ld\n",pchip2->nodename,param->val);

            break;

        case PWM_PARAM_DUTY:
            param->val = pchip2->rtk_duty = rtk_pwm_duty_get(pchip2,pwm_duty_set_reg.pwm0_dut,pwm_duty_set_reg.pwm0_totalcnt);

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET %s DUTY param_val:%ld\n",pchip2->nodename,param->val);

            break;

        case PWM_PARAM_VSYNC_RESET:
            param->val = pwm_ctrl_reg.pwm0_vs_rst_en;

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET %s VSYNC param_val:%ld\n",pchip2->nodename,param->val);

            break;
        case PWM_PARAM_OUTPUT:
            param->val = pwm_ctrl_reg.pwm0_en;

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET %s OUTPUT param_val:%ld\n",pchip2->nodename,param->val);

            break;
        case PWM_PARAM_TOTALCNT:
            param->val = pwm_duty_set_reg.pwm0_totalcnt;

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET %s TOTALCNT param_val:%ld\n",pchip2->nodename,param->val);

            break;
        default:
            ret = (-PWM_PARAM_ID_INVALID);
    }

    return ret;
}


static
int rtk_pwm_set_mode(RTK_PWM_MODE_INFO_T mode_param)
{
    int ret = PWM_OK;
    R_CHIP_T *pchip2 = rtk_pwm_chip_get_by_name(mode_param.pcbname);
    if(pchip2 == NULL){
        ret = (-PWM_PCB_ENUM_ERROR);
        PWM_ERR("PWM %s chip get error!\n",mode_param.pcbname);
        return ret;
    }

    if(mode_param.m_mode == GPIO_MODE){

        if(mode_param.m_val == 1){
            if(pchip2->rtk_polarity == 1)
                rtk_change_to_gpio_mode(pchip2,GPIO_PIN_LOW);
            else
                rtk_change_to_gpio_mode(pchip2,GPIO_PIN_HIGH);
        }
        else if(mode_param.m_val == 0){
            if(pchip2->rtk_polarity == 1)
                rtk_change_to_gpio_mode(pchip2,GPIO_PIN_HIGH);
            else
                rtk_change_to_gpio_mode(pchip2,GPIO_PIN_LOW);
        }
        else{
            PWM_ERR("SET %s  MODE VALUE INVALID mode_val:%d\n",pchip2->nodename,mode_param.m_val);
            return (-PWM_VALUE_INVALID);
        }
    }
    else if(mode_param.m_mode == PWM_MODE){
        rtk_change_to_pwm_mode(pchip2);
    }
    else {
        PWM_ERR("SET %s  MODE INVALID mode_val:%d\n",pchip2->nodename,mode_param.m_mode);
        return (-PWM_MODE_INVALID);
    }
    return ret;
}

static
int rtk_pwm_get_mode(RTK_PWM_MODE_INFO_T* mode_param)
{
    int ret = PWM_OK;
    R_CHIP_T *pchip2 = rtk_pwm_chip_get_by_name(mode_param->pcbname);
    if(pchip2 == NULL){
        ret = (-PWM_PCB_ENUM_ERROR);
        PWM_ERR("PWM %s chip get error!\n",mode_param->pcbname);
        return ret;
    }

    mode_param->m_mode = pchip2->currentMode;

    if(mode_param->m_mode == GPIO_MODE)
        mode_param->m_val = rtk_pwm_gpio_value(pchip2);
    else  if(mode_param->m_mode == PWM_MODE){
        mode_param->m_val = 0;
    }
    else {
        PWM_ERR("SET %s  MODE INVALID mode_val:%d\n",pchip2->nodename,mode_param->m_mode);
        return (-PWM_MODE_INVALID);
    }
    return ret;
}


static
int rtk_pwm_set_all_param_ex(RTK_PWM_INFO_EX_T* param_all)
{
    int ret = PWM_OK;

    pwm0_ctrl_RBUS pwm_ctrl_reg;
    pwm0_duty_set_RBUS pwm_duty_set_reg;
    pwm0_db_ctrl_RBUS dbReg;
    pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
    R_CHIP_T *pchip2 = NULL;

    pchip2 = rtk_pwm_chip_get_by_name(param_all->pcbname);
    if(pchip2 == NULL){
        ret = (-PWM_PCB_ENUM_ERROR);
        PWM_ERR("PWM %s chip get error!\n",param_all->pcbname);
        return ret;
    }

    /** Read Register status **/
    pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
    dbReg.regValue = rtd_inl(pchip2->rtk_db_reg);

    //Set Polarity
    if((param_all->m_polarity != 0) && (param_all->m_polarity != 1)){
        PWM_ERR("SET %s  POLARITY INVALID param_val:%ld\n",pchip2->nodename,param_all->m_polarity);
        return (-PWM_POLARITY_INVALID);
    }
    pchip2->rtk_polarity = param_all->m_polarity;
    rtk_pwm_ctrl_polarity(pchip2,&pwm_ctrl_reg);

    //Set Frequency
    if((param_all->m_freq < 4) || (param_all->m_freq > MAX_PWM_FREQ)){
        PWM_ERR("SET %s FREQEUNCY INVALID param_val:%ld\n",pchip2->nodename,param_all->m_freq);
        return (-PWM_FREQEUNCY_INVALID);
    }
    pchip2->rtk_freq = param_all->m_freq;
    rtk_pwm_timing_freq_set(pchip2,&pwm_timing_ctrl_reg);

    //Set Duty
    if((param_all->m_duty < 0) || (param_all->m_duty > pchip2->rtk_duty_max)){
        PWM_ERR("SET %s  DUTY INVALID param_val:%ld\n",pchip2->nodename,param_all->m_duty);
        return (-PWM_DUTY_INVALID);
    }
    pchip2->rtk_duty = param_all->m_duty;
    rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);

    //Set Vsync
    if((param_all->m_vsync != 0) && (param_all->m_vsync != 1)){
        PWM_ERR("SET %s  VSYNC INVALID param_val:%ld\n",pchip2->nodename,param_all->m_vsync);
        return (-PWM_VSYNC_INVALID);
    }
    pchip2->rtk_vsync = param_all->m_vsync;

    //Set Output
    if((param_all->m_run != 0) && (param_all->m_run != 1)){
        PWM_ERR("SET %s  OUTPUT INVALID param_val:%ld\n",pchip2->nodename,param_all->m_run);
        return (-PWM_OUTPUT_INVALID);
    }
    pchip2->rtk_enable = param_all->m_run;
    rtk_pwm_ctrl_output_enable(pchip2,&pwm_ctrl_reg);

    if(ret == PWM_OK){
        rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);
        rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);
        rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);
        /*set DB */
        rtk_pwm_db_enable(pchip2,&dbReg);
        rtk_pwm_db_update(pchip2,&dbReg);
        rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
        rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);

        if( m_printk_ioctl_get() > 0 ){
            PWM_ERR("SET %s POLARITY m_polarity:%ld\n",pchip2->nodename,param_all->m_polarity);
            PWM_ERR("SET %s FREQUENCY m_freq:%ld\n",pchip2->nodename,param_all->m_freq);
            PWM_ERR("SET %s DUTY m_duty:%ld\n",pchip2->nodename,param_all->m_duty);
            PWM_ERR("SET %s VSYNC m_vsync:%ld\n",pchip2->nodename,param_all->m_vsync);
            PWM_ERR("SET %s OUTPUT m_run:%ld\n",pchip2->nodename,param_all->m_run);
        }

        videoPwmAction_Yes();
    }

    return ret;
}

static
int rtk_pwm_get_all_param_ex(RTK_PWM_INFO_EX_T* param_all)
{
    int ret = PWM_OK;

    unsigned short M = 0, N = 0;
    pwm0_ctrl_RBUS pwm_ctrl_reg;
    pwm0_duty_set_RBUS pwm_duty_set_reg;
    pwm0_db_ctrl_RBUS dbReg;
    pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
    R_CHIP_T *pchip2 = NULL;

    pchip2 = rtk_pwm_chip_get_by_name(param_all->pcbname);
    if(pchip2 == NULL){
        ret = (-PWM_PCB_ENUM_ERROR);
        PWM_ERR("PWM %s chip get error!\n",param_all->pcbname);
        return ret;
    }

    /** Read Register status **/
    pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
    dbReg.regValue = rtd_inl(pchip2->rtk_db_reg);

    //Get Polarity
    param_all->m_polarity = pwm_ctrl_reg.pwm0l;
    //Get Frequency
    M = pwm_timing_ctrl_reg.pwm0_m;
    N = pwm_timing_ctrl_reg.pwm0_n;
    param_all->m_freq = ((CONFIG_CPU_XTAL_FREQ / (1 << M)) / (N+1) / pchip2->rtk_duty_max);

    //Get Duty
    param_all->m_duty = pchip2->rtk_duty = rtk_pwm_duty_get(pchip2,pwm_duty_set_reg.pwm0_dut,pwm_duty_set_reg.pwm0_totalcnt);
    //Get Vsync
    param_all->m_vsync = pwm_ctrl_reg.pwm0_vs_rst_en;
    //Get Output
    param_all->m_run = pwm_ctrl_reg.pwm0_en;

    if( m_printk_ioctl_get() > 0 ){
        PWM_WARN("GET %s POLARITY m_polarity:%ld\n",pchip2->nodename,param_all->m_polarity);
        PWM_WARN("GET %s FREQUENCY m_freq:%ld\n",pchip2->nodename,param_all->m_freq);
        PWM_WARN("GET %s DUTY m_duty:%ld\n",pchip2->nodename,param_all->m_duty);
        PWM_WARN("GET %s VSYNC m_vsync:%ld\n",pchip2->nodename,param_all->m_vsync);
        PWM_WARN("GET %s OUTPUT m_run:%ld\n",pchip2->nodename,param_all->m_run);
    }

    return ret;
}
int rtk_pwm_set_param(RTK_PWM_PARAM_T* param)
{
    int ret = PWM_SUCCESS;
    int pwm_index = PWM_IDX(param->m_index);
    int pwm_type = PWM_TYPE(param->m_index);
    pwm0_ctrl_RBUS pwm_ctrl_reg;
    pwm0_duty_set_RBUS pwm_duty_set_reg;
    pwm0_db_ctrl_RBUS dbReg;
    pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
    R_CHIP_T *pchip2 = rtk_pwm_chip_get_by_index(pwm_index,pwm_type);
    if(pchip2 == NULL){
        ret = -EFAULT;
        PWM_ERR("PWM index-%d chip get error!\n",pwm_index);
        return ret;
    }

    /** Read Register status **/
    pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
    dbReg.regValue = rtd_inl(pchip2->rtk_db_reg);

    switch (param->id) {
        case PWM_PARAM_POLARITY:
            pchip2->rtk_polarity = param->val;
            rtk_pwm_ctrl_polarity(pchip2,&pwm_ctrl_reg);
            rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);
            rtk_pwm_ctrl_db_wr(&pwm_ctrl_reg);
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("SET PWM-%s-%d POLARITY param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_FREQUENCY:
            pchip2->rtk_freq = param->val;
            rtk_pwm_timing_freq_set(pchip2,&pwm_timing_ctrl_reg);
            rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);

            rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
            rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);

            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("SET PWM-%s-%d FREQUENCY param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_DUTY:
            pchip2->rtk_duty = param->val;
            rtk_pwm_duty_set(pchip2,&pwm_duty_set_reg);
            rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("SET PWM-%s-%d DUTY param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_VSYNC_RESET:
            pchip2->rtk_vsync = param->val;
            rtk_pwm_ctrl_vsync_enable(pchip2,&pwm_ctrl_reg);
            rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("SET PWM-%s-%d VSYNC param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_OUTPUT:
            pchip2->rtk_enable = param->val;
            rtk_pwm_ctrl_output_enable(pchip2,&pwm_ctrl_reg);
            rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("SET PWM-%s-%d OUTPUT param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        default:
            ret = PWM_FAIL;
    }

    if(ret == PWM_SUCCESS){
        /*set DB */
        rtk_pwm_db_enable(pchip2,&dbReg);
        rtk_pwm_db_update(pchip2,&dbReg);
        rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);

        videoPwmAction_Yes();
    }

    return ret;
}

static
int rtk_pwm_get_param(RTK_PWM_PARAM_T* param)
{
    int ret = PWM_SUCCESS;
    int pwm_type = PWM_TYPE(param->m_index);
    int pwm_index = PWM_IDX(param->m_index);
    unsigned short M = 0, N = 0;
    pwm0_ctrl_RBUS pwm_ctrl_reg;
    pwm0_duty_set_RBUS pwm_duty_set_reg;
    pwm0_db_ctrl_RBUS dbReg;
    pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
    R_CHIP_T *pchip2 = rtk_pwm_chip_get_by_index(pwm_index,pwm_type);
    if(pchip2 == NULL){
        ret = -EFAULT;
        PWM_ERR("PWM index-%d chip get error!\n",pwm_index);
        return ret;
    }

    /** Read Register status **/
    pwm_ctrl_reg.regValue = rtd_inl(pchip2->reg->CTRL);
    pwm_timing_ctrl_reg.regValue = rtd_inl(pchip2->reg->TIMING_CTRL);
    pwm_duty_set_reg.regValue = rtd_inl(pchip2->reg->DUTY_SET);
    dbReg.regValue = rtd_inl(pchip2->rtk_db_reg);

    switch (param->id) {
        case PWM_PARAM_POLARITY:
            param->val = pchip2->rtk_polarity = pwm_ctrl_reg.pwm0l;
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET PWM-%s-%d POLARITY param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_FREQUENCY:
            M = pwm_timing_ctrl_reg.pwm0_m;
            N = pwm_timing_ctrl_reg.pwm0_n;
            param->val = pchip2->rtk_freq = rtk_pwm_get_freq(pchip2,M,N);
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET PWM-%s-%d FREQUENCY param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_DUTY:
            param->val = pchip2->rtk_duty = rtk_pwm_duty_get(pchip2,pwm_duty_set_reg.pwm0_dut,pwm_duty_set_reg.pwm0_totalcnt);
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET PWM-%s-%d DUTY param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_VSYNC_RESET:
            param->val = pchip2->rtk_vsync = pwm_ctrl_reg.pwm0_vs_rst_en;
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET PWM-%s-%d VSYNC param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        case PWM_PARAM_OUTPUT:
            param->val = pchip2->rtk_enable = pwm_ctrl_reg.pwm0_en;
            if( m_printk_ioctl_get() > 0 )
                PWM_WARN("GET PWM-%s-%d OUTPUT param_val:%ld\n",(pwm_type == PWM_MISC)?"MISC":"ISO",pwm_index,param->val);
            break;
        default:
            ret = PWM_FAIL;
    }

    return ret;
}

long rtk_pwm_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int retval = 0;
	RTK_PWM_INFO_T stpwminfo;
	R_CHIP_T *pchip2 = NULL;
	RTK_PWM_PARAM_T param;
	RTK_PWM_PARAM_EX_T param_ex;
	RTK_PWM_INFO_EX_T  param_all;
	RTK_PWM_MODE_INFO_T mode_info;
	pwm0_ctrl_RBUS pwm_ctrl_reg;
	pwm0_duty_set_RBUS pwm_duty_set_reg;
	pwm0_db_ctrl_RBUS dbReg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;

	if(m_disable_ioctl_get())
		return retval;

	m_ioctl_counter_count();

	switch (cmd) {
	case PWM_MODE_SET:
		if (copy_from_user(&mode_info, (RTK_PWM_MODE_INFO_T __user *) arg, sizeof(mode_info)))
			return -EFAULT;

		retval = rtk_pwm_set_mode(mode_info);
		if(retval < 0){
			PWM_ERR("pwm set mode_info failed \n");
			return retval;
		}
		break;
	case PWM_MODE_GET:
		if (copy_from_user(&mode_info, (RTK_PWM_MODE_INFO_T __user *) arg, sizeof(mode_info)))
			return -EFAULT;

		retval = rtk_pwm_get_mode(&mode_info);
		if (retval < 0){
			PWM_ERR("pwm get mode_info failed \n");
			return retval;
		}
		return copy_to_user((RTK_PWM_MODE_INFO_T __user *) arg, &mode_info,sizeof(mode_info));
		break;
	case PWM_PARAM_SET_EX:
		if (copy_from_user(&param_ex, (RTK_PWM_PARAM_EX_T __user *) arg, sizeof(param_ex)))
			return -EFAULT;

		retval = rtk_pwm_set_param_ex(&param_ex);
		if(retval < 0){
			PWM_ERR("pwm set param_ex failed \n");
			return retval;
		}
		break;
	case PWM_PARAM_GET_EX:
		if (copy_from_user(&param_ex, (RTK_PWM_PARAM_EX_T __user *) arg, sizeof(param_ex)))
			return -EFAULT;

		retval = rtk_pwm_get_param_ex(&param_ex);
		if (retval < 0){
			PWM_ERR("pwm get param_ex failed \n");
			return retval;
		}
		return copy_to_user((RTK_PWM_PARAM_EX_T __user *) arg, &param_ex,sizeof(param_ex));
		break;
	case PWM_IOCR_SET_EX:
		if (copy_from_user(&param_all, (RTK_PWM_INFO_EX_T __user *) arg, sizeof(param_all)))
			return -EFAULT;

		retval = rtk_pwm_set_all_param_ex(&param_all);
		if(retval < 0){
			PWM_ERR("pwm set param_all failed \n");
			return retval;
		}
		break;
	case PWM_IOCR_GET_EX:
		if (copy_from_user(&param_all, (RTK_PWM_INFO_EX_T __user *) arg, sizeof(param_all)))
			return -EFAULT;

		retval = rtk_pwm_get_all_param_ex(&param_all);
		if (retval < 0){
			PWM_ERR("pwm get param_all failed \n");
			return retval;
		}
		return copy_to_user((RTK_PWM_INFO_EX_T __user *) arg, &param_all,sizeof(param_all));
		break;
	case PWM_PARAM_SET:
		if (copy_from_user(&param, (RTK_PWM_PARAM_T __user *) arg, sizeof(param)))
			return -EFAULT;

		if(rtk_pwm_set_param(&param) == PWM_FAIL)
		{
			PWM_ERR("pwm set param failed \n");
			return -EFAULT;
		}

		break;

	case PWM_PARAM_GET:
		if (copy_from_user(&param, (RTK_PWM_PARAM_T __user *) arg, sizeof(param)))
			return -EFAULT;

		if (rtk_pwm_get_param(&param) < 0)
		{
			PWM_ERR("pwm get param failed \n");
			return -EFAULT;
		}

		return copy_to_user((RTK_PWM_PARAM_T __user *) arg, &param,sizeof(param));
		break;

	case PWM_IOCR_SET:
	{
		if (copy_from_user
		    ((void *)&stpwminfo, (const void __user *)arg,
		     sizeof(struct RTK_PWM_INFO))) {
			retval = -EFAULT;
			PWM_ERR("PWM_IOCR_ fail!\n");
			break;
		}
		if(stpwminfo.m_index >= pin_index_get()) {
			retval = -EFAULT;
			PWM_ERR("PWM index-%d error!\n",stpwminfo.m_index);
			break;
		}

		pchip2 = rtk_pwm_chip_get(stpwminfo.m_index);

		pchip2->rtk_adapt_freq = rtk_pwm_get_adapt_freq(pchip2);
		rtk_pwm_user_setting(pchip2,&stpwminfo);

		get_v_delay(pchip2);
		
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

		/*set DB */
		rtk_pwm_db_enable(pchip2,&dbReg);

		rtk_pwm_timing_update(pchip2,&pwm_timing_ctrl_reg);
		rtk_pwm_duty_update(pchip2,&pwm_duty_set_reg);
		rtk_pwm_db_update(pchip2,&dbReg);
		rtk_pwm_ctrl_update(pchip2,&pwm_ctrl_reg);
		
		videoPwmAction_Yes();

		if( m_printk_ioctl_get() > 0 ){
			PWM_WARN("%s set pwm[%d], duty=%d freq=%d lock=%d (pos=%d,%08x) adp = %d  adap_freq=%d mPlus=%d\n",
				__func__ ,
				stpwminfo.m_index,
				pchip2->rtk_duty,
				pchip2->rtk_freq,
				pchip2->rtk_vsync,
				pchip2->rtk_pos_start,
                pchip2->rtk_pos_start_clk,
				pchip2->rtk_adpt_en,
				pchip2->rtk_adapt_freq,
                pchip2->rtk_mPlus);

		}

		break;
	}
	default:
		retval = -ENOTTY;
	}

	return retval;
}

#ifdef CONFIG_COMPAT
long rtk_pwm_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	return rtk_pwm_ioctl(filp, cmd, (unsigned long)arg);
}
#endif

int rtk_pwm_release(struct inode *inode, struct file *filp)
{
	//printk("%s():\n", __FUNCTION__);
	return 0;

}


static struct file_operations rtk_pwm_fops = {
	.owner = THIS_MODULE,
	.read = rtk_pwm_read,
	.write = rtk_pwm_write,
	.unlocked_ioctl = rtk_pwm_ioctl,
#ifdef CONFIG_ARM64
#ifdef CONFIG_COMPAT
	.compat_ioctl = rtk_pwm_compat_ioctl,
#endif
#endif
	.release = rtk_pwm_release,
	.open = rtk_pwm_open,
};


static void rtk_hw_setting_pwm_probe(int ricindex,const rtk_pwm_reg_map *regtable,
				     PCB_PIN_TYPE_T pintype, int index,
				     int pwm_freq_hz, int duty_max, int duty,
				     int invert, int memindex)
{

	pwm0_ctrl_RBUS pwm_ctrl_reg;
	pwm0_timing_ctrl_RBUS pwm_timing_ctrl_reg;
	pwm0_duty_set_RBUS pwm_duty_set_reg;
	pwm0_db_ctrl_RBUS dbReg;
	int rtk_totalcnt = 0;
	R_CHIP_T *pchip2;
	char *pcbname;
	pchip2 = rtk_pwm_chip_get(ricindex);

	pcbname = rtk_pwm_chip_pcbname_get(ricindex);
	if(strcmp(pcbname,"PIN_DIM_OUT") == 0){	
		duty = 256;
		RTK_PWM_P("[PWM] pcbname=%s,duty=%d \n",pcbname,duty);
	}
	
	RTK_PWM_P
	    ("[PWM] int index 0x%x, int pwm_freq_hz 0x%x, \n \
	     int duty_max 0x%x, int duty 0x%x, int invert 0x%x\n",
	     index, pwm_freq_hz, duty_max, duty, invert);
	

	rtk_pwm_timing_probe_init(pwm_freq_hz,duty_max, &rtk_totalcnt,regtable,&pwm_timing_ctrl_reg);
	rtk_pwm_totalcnt_init(pchip2,rtk_totalcnt);
	rtk_pwm_duty_probe_init(duty,duty_max,&rtk_totalcnt,regtable,&pwm_duty_set_reg);

	rtk_pwm_db_enable(pchip2,&dbReg);
	rtk_pwm_db_update(pchip2,&dbReg);
	rtk_pwm_ctrl_probe_init(pwm_mode_get(),invert,pchip2,regtable,&pwm_ctrl_reg);

	videoPwmAction_Yes();
}

int pcb_mgr_get_enum_info_represent_byapp(RTK_PCB_ENUM *pcbenumPtr)
{
    int i;
    int index = 0;
    PCB_PIN_TYPE_T     pin_type;

    struct linux_pcb_pwm_enum_t  *linux_pcb_enum_ptr = (struct linux_pcb_pwm_enum_t* )pcbenumPtr;

    if(linux_pcb_enum_ptr == NULL){
        return -1;
    }

    for(i = 0; i < PCB_ENUM_MAX; i++){
        if(memcmp(pcb_enum_all[i].name, "PIN", 3) == 0){
            pin_type = GET_PIN_TYPE(pcb_enum_all[i].value);
            //PWM_WARN("pin type :%d, pin pcb_enum_all[i].name:%s\n", pin_type, pcb_enum_all[i].name);
            if(PCB_PIN_TYPE_PWM == pin_type  || PCB_PIN_TYPE_ISO_PWM == pin_type){
                strcpy(linux_pcb_enum_ptr[index].name,pcb_enum_all[i].name);
                linux_pcb_enum_ptr[index].value = pcb_enum_all[i].value;
                index ++;
            }
        }
    }

    return index;
}

static int rtk_hw_setting_pwm_init(RTK_PCB_ENUM *pcbinfo, int ricindex)
{
	int ret = 0;
	R_CHIP_T *pwmPin=NULL;
	char *pcbname = pcbinfo->name;
	char     pcbNameWithPinmux[128];
	unsigned long long ullPcbPinMuxValue = 0;

	ret = rtk_pwm_pcb_mgr_get(pcbname,ricindex);
	
	if( ret != 0)
		return -1;

	rtk_pwm_pcb_mgr_get_value(pcbinfo,ricindex);

	if( strcmp(pcbname , "PIN_BL_ADJ") == 0 ||
		strcmp(pcbname , "PIN_PWM_DIM1") == 0){
		rtk_pwm_backlight_pin_set(ricindex);
	}

	pwmPin = rtk_pwm_chip_get(ricindex);
	strcpy(pwmPin->pcbname,pcbname);

	/** workaround for full high & full low support **/
	(void)snprintf(pcbNameWithPinmux, sizeof(pcbNameWithPinmux), "%s%s", pcbname, "_GPIO_INFO");
	ret = pcb_mgr_get_enum_info_byname(pcbNameWithPinmux, &ullPcbPinMuxValue);
	if(0 != ret){
		PWM_ERR("Get pcbenum error.enum name:%s\n", pcbNameWithPinmux);
		pwmPin->gid = INVALID_GPIO_GID;
	}
	else{
		pwmPin->pin_mux_info.addr      = GET_PWM_PINMUX_ADDR(ullPcbPinMuxValue);
		pwmPin->pin_mux_info.mask_h    = GET_PWM_PINMUX_REG_ENDBIT(ullPcbPinMuxValue);
		pwmPin->pin_mux_info.mask_l    = GET_PWM_PINMUX_REG_STARTBIT(ullPcbPinMuxValue);
		pwmPin->pin_mux_info.pwmValue  = GET_PWM_PINMUX_PWMVALUE(ullPcbPinMuxValue);
		pwmPin->pin_mux_info.gpioValue = GET_PWM_PINMUX_GPIOVALUE(ullPcbPinMuxValue);
		pwmPin->gid = rtk_gpio_get_gid_by_pintype(GET_PWM_PINMUX_GPIO_PINTYPE(ullPcbPinMuxValue),
												GET_PWM_PINMUX_GPIO_NUM(ullPcbPinMuxValue));
	}
	pwmPin->currentMode = PWM_MODE;

	if(rtk_pwm_hw_type_init(pwmPin) < 0)
		return (-1);

#ifdef CONFIG_RTK_KDRV_PWM_INIT_ENABLE
	rtk_hw_setting_pwm_probe(ricindex,
		rtk_pwm_chip_reg_get(ricindex),
		GET_PIN_TYPE(pcbinfo->value),
		GET_PIN_INDEX(pcbinfo->value),
		GET_PWM_FREQ(pcbinfo->value),
		GET_PWM_DUTY_MAX(pcbinfo->value),
		GET_PWM_INIT_DUTY(pcbinfo->value),
		GET_PWM_INVERT(pcbinfo->value),
		rtk_pwm_chip_index_get(ricindex));
#endif
	pwmPin->pwm_device_st = device_create(_gstpwm_class, NULL, MKDEV(0, 0), NULL,
				  pwmPin->nodename);

	rtk_pwm_create_attr(pwmPin->pwm_device_st);

	pwmPin->pwm_device_st->platform_data = (void *)pwmPin;

	rtk_pwm_hw_pin_init(pwmPin,ricindex);
	
	PWM_WARN("[%s] Get %s ,Create Node[%d] %s\n \
		device id = %d, VT=%d, HT=%d, clk=%d, adapt_freq=%d,\n\
		freq = %d, max_duty=%d, duty=%d, vsync = %d, \n \
		enable = %d, polarity = %d, pos_delay = %08x , \n \
		mPlus = %08x\n",
		__func__, pcbname, ricindex,
		pwmPin->nodename,
		pwmPin->pwm_device_st->id,
		pwmPin->vt,
		pwmPin->ht,
		pwmPin->dclk,
		pwmPin->rtk_adapt_freq,
		pwmPin->rtk_freq,
		pwmPin->rtk_duty_max,
		pwmPin->rtk_duty,
		pwmPin->rtk_vsync,
		pwmPin->rtk_enable,
		pwmPin->rtk_polarity,
		pwmPin->rtk_pos_start_clk,
		pwmPin->rtk_mPlus );

	return 0;

}



/*---------------------------------------------------------------------
//---------------------------------------------------------------------*/

static int rtk_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	PWM_INFO("[%s] id = %d\n", __func__, chip->npwm);

	return 0;
}

static void rtk_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	PWM_INFO("[%s] id = %d\n", __func__, chip->npwm);
	return;
}

static int rtk_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
			  int duty_ns, int period_ns)
{

	PWM_INFO(
		"[%s] id=%d ,duty_ns= %d, period_ns=%d\n",__func__, chip->npwm,
	       duty_ns, period_ns);

	return 0;
}

static struct pwm_ops rtk_pwm_ops = {
	.enable = rtk_pwm_enable,
	.disable = rtk_pwm_disable,
	.config = rtk_pwm_config,
	.owner = THIS_MODULE,
};

static int rtk_pwm_probe(struct platform_device *pdev)
{
	struct pwm_chip *pstrchip;
	unsigned int id = pdev->id;

	PWM_WARN("[%s]Initialize PWM-%d, name = %s\n",__func__, id, pdev->name);

	pstrchip =
	    devm_kzalloc(&pdev->dev, sizeof(struct pwm_chip), GFP_KERNEL);
	if (pstrchip == NULL) {
		dev_err(&pdev->dev, "[%s] failed to allocate pwm_device\n",
			__func__);
		return -ENOMEM;
	}

	pstrchip->dev = &pdev->dev;
	pstrchip->ops = &rtk_pwm_ops;
	pstrchip->base = 1;
	pstrchip->npwm = 1;

	PWM_WARN("[%s]%d dev name = %s, id = %d\n", __func__, __LINE__,
	       pdev->dev.init_name, id);

	pwmchip_add(pstrchip);

	platform_set_drvdata(pdev, pstrchip);

	rtk_pwm_chip_device_set(pdev);
	
	return 0;
}

static int rtk_pwm_remove(struct platform_device *pdev)
{
	rtk_hw_setting_power_off(CRT_PWM_MISC);
	return 0;
}



#ifdef CONFIG_PM
static int rtk_pwm_suspend(struct device *dev)
{
	PWM_WARN("suspend\n");

	rtk_hw_setting_power_off(CRT_PWM_MISC);

	videoPwmAction_No();

	return 0;
}

static int rtk_pwm_resume(struct device *dev)
{
	int ricindex=0;
	PWM_WARN("resume\n");
	unsigned long long ullPcbMgrValue;
	const rtk_pwm_reg_map *reg;
	
	rtk_hw_setting_power_on(CRT_PWM_ISO);
	rtk_hw_setting_power_on(CRT_PWM_MISC);

    /*pwm init, I'm not sure that Is AP will set pwm after resume or not? */

	videoPwmAction_No();

#if 1
	for (ricindex = 0; ricindex < pin_index_get(); ricindex++) {
		ullPcbMgrValue = rtk_pwm_chip_PcbMgrValue_get(ricindex);
		reg = rtk_pwm_chip_reg_get(ricindex);

		rtk_hw_setting_pwm_probe(ricindex, reg,
					 GET_PIN_TYPE(ullPcbMgrValue),
					 GET_PIN_INDEX(ullPcbMgrValue),
					 GET_PWM_FREQ(ullPcbMgrValue),
					 GET_PWM_DUTY_MAX(ullPcbMgrValue),
#ifdef CONFIG_CUSTOMER_TV006
					0,   /* control by webos */
#else
					GET_PWM_INIT_DUTY(ullPcbMgrValue),
#endif
					 GET_PWM_INVERT(ullPcbMgrValue),
					 rtk_pwm_chip_index_get(ricindex));
	}
#endif
	rtk_local_dimming_enable();
	return 0;
}

#ifdef CONFIG_HIBERNATION
static int rtk_pwm_suspend_std(struct device *dev)
{
	PWM_WARN("rtk_pwm_suspend_std\n");

	videoPwmAction_No();

	return 0;
}
static int rtk_pwm_resume_std(struct device *dev)
{
	PWM_WARN("rtk_pwm_resume_std\n");
	return 0;
}

#endif

static const struct dev_pm_ops rtk_pwm_pm_ops = {

	.suspend = rtk_pwm_suspend,
	.resume = rtk_pwm_resume,

#ifdef CONFIG_HIBERNATION
	.freeze     = rtk_pwm_suspend_std,
	.thaw       = rtk_pwm_resume_std,
#endif
};


#endif

static const struct of_device_id rtk_pwm_devices[] = {
	{.compatible = "rtk-pwm",},
	{},
};

MODULE_DEVICE_TABLE(of, rtk_pwm_devices);

static struct platform_driver rtk_pwm_driver = {
	.driver = {
			.name = "rtk-pwm",
			.owner = THIS_MODULE,
			.of_match_table = of_match_ptr(rtk_pwm_devices),

			#ifdef CONFIG_PM
			.pm	= &rtk_pwm_pm_ops,
			#endif
		},
	.probe = rtk_pwm_probe,
	.remove = rtk_pwm_remove,
};

static int register_pwm_cdev(void) {

	dev_t dev;
	int ret;

	ret = alloc_chrdev_region(&dev, 0, 1, "pwm");
	if (ret) {
		PWM_ERR("can't alloc chrdev\n");
		return ret;
	}

	dev_major = MAJOR(dev);
	dev_minor = MINOR(dev);

	dev_cdevp = kzalloc(sizeof(struct cdev), GFP_KERNEL);
	if (dev_cdevp == NULL) {
		PWM_ERR( "kzalloc failed\n");
		goto failed;
	}

	cdev_init(dev_cdevp, &rtk_pwm_fops);
	dev_cdevp->owner = THIS_MODULE;
	dev_cdevp->ops = &rtk_pwm_fops;
	ret = cdev_add(dev_cdevp, MKDEV(dev_major, dev_minor), 1);
	if (ret < 0) {
		PWM_WARN("add chr dev failed\n");
		goto failed;
	}

	pwm_device_st = device_create(_gstpwm_class, NULL, MKDEV(dev_major, dev_minor), NULL, "pwm0");
	PWM_WARN("register chrdev(%d,%d) success.\n", dev_major, dev_minor);
	return 0;

failed:
	if(dev_cdevp) {
		kfree(dev_cdevp);
		dev_cdevp = NULL;
	}
	return 0;

}



static int __init rtk_pwm_mode_init(char *cmdline)
{
	static char *mode;
	mode = cmdline;
	if(cmdline == NULL){
		PWM_WARN("%s no set pwm mode\n",__func__);
	}else{
	    simple_strtoul(mode, &mode, 10);		   
		if(pwm_mode_get() == PWM_DRIVING_LED_CURRENT)
	        PWM_WARN("%s  pwm_mode:%s\n",__func__,"LED_CURRENT");
		else if(pwm_mode_get() == PWM_DRIVING_2CH_PHASE_SAME)
			PWM_WARN("%s  pwm_mode:%s\n",__func__,"2CH_PHASE_SAME");
		else if(pwm_mode_get() == PWM_DRIVING_2CH_PHASE_DIFF)
            PWM_WARN("%s  pwm_mode:%s\n",__func__,"2CH_PHASE_DIFF");
	}
	return 0;
}
early_param("pwm_mode", rtk_pwm_mode_init);

static int __init rtk_pwm_driver_init(void)
{
	int ret = 0;
	int i;

	_gPwmCount = pcb_mgr_get_enum_info_represent_byapp(_gPWMNamelist);
	if(_gPwmCount == 0)
		return -1;


	ret = platform_driver_register(&rtk_pwm_driver);
	if (ret != 0)
		goto REGISTER_ERROR;

	_gstpwm_class = class_create(THIS_MODULE, "rtk-pwm");
	if (_gstpwm_class == NULL)
		goto REGISTER_ERROR;

	/*use global index....don't care re-entry safety. */
	for(i = 0; i < _gPwmCount && i < MAX_PWM_COUNT; i++){
		ret = rtk_hw_setting_pwm_init(&_gPWMNamelist[i], pin_index_get());
		if (ret == 0) {
			pin_index_count();
		}
	}

	pst_rtk_pwm_platform_dev =
		platform_device_register_simple("rtk-pwm", -1, NULL, 0);

	if (pst_rtk_pwm_platform_dev == NULL) {
		platform_driver_unregister(&rtk_pwm_driver);
		goto REGISTER_ERROR;
	}

	register_pwm_cdev();

#if PATCH_FOR_VDELAY
	/*for vcpu isr*/
	rtk_pwm_init_mem();

	rtk_pwm_send_mem();
#endif

	return 0;

REGISTER_ERROR:
	class_destroy(_gstpwm_class);
	device_destroy(_gstpwm_class, MKDEV(0, 0));

	PWM_ERR("[%s] ======================================\n",
			__func__);
	PWM_ERR( "[%s] PWM Register Error!\n", __func__);
	PWM_ERR( "[%s] ======================================\n",
		     	__func__);
	return -1;
}

module_init(rtk_pwm_driver_init);

static void __exit rtk_pwm_driver_exit(void)
{
	int i;
	struct device *pwm_device_st = NULL;

#if PATCH_FOR_VDELAY
	rtk_pwm_destroy_mem();
#endif

	for (i = 0; i < pin_index_get(); i++) {
		rtk_pwm_remove_attr(pwm_device_st);
	}

	device_destroy(_gstpwm_class, MKDEV(0, 0));

	class_destroy(_gstpwm_class);

	platform_driver_unregister(&rtk_pwm_driver);

	platform_device_unregister(pst_rtk_pwm_platform_dev);

}

module_exit(rtk_pwm_driver_exit);
#if 0
int rtk_pwm_set_scaler_source( int ifreq, int ifold,bool bEnableDB)
{
	int i = 0;
	for (i = 0; i < pin_index_get(); i++) {
		if( 0 != rtk_pwm_set_freq(i, ifreq,ifold,bEnableDB))
			return -1;
	}
	return 0;
}
#endif

int rtk_pwm_set_scaler_source( int ifreq, int ifold,bool bEnableDB)
{
       if(s_rtk_pos_start){
               ifold = 1;
       }
       else // Vsync align disable => motion clairy off
       {
               ifold = 1;
		 ifreq = Get_PANEL_BACKLIGHT_PWM_FREQ();	   
       }
	int i = 0;
	for (i = 0; i < pin_index_get(); i++) {
		if( 0 != rtk_pwm_set_freq(i, ifreq,ifold,bEnableDB))
			return -1;
	}
	
	set_pwm_freq_totalcnt_vsyncdelay("PIN_DIM_OUT",(ifreq*ifold),255,s_rtk_pos_start);
	return 0;
}


EXPORT_SYMBOL(rtk_pwm_set_scaler_source);


MODULE_AUTHOR("baker.cheng <baker.cheng@realtek.com>");
MODULE_DESCRIPTION("Realtek Pulse Width Modulation Driver");
MODULE_ALIAS("platform:rtk-pwm");
MODULE_LICENSE("GPL");
