//Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/interrupt.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/fs.h>
//#include <asm/io.h>
#include <asm/uaccess.h>

#include "rtk_vgip_isr.h"
#include <rbus/vgip_reg.h>
#include <rbus/sub_vgip_reg.h>
#include <rbus/dma_vgip_reg.h>
#include <rbus/h3ddma_reg.h>
#include <rbus/onms_reg.h>
#include <rbus/sys_reg_reg.h>
#include "memc_isr/Driver/reg_offset.h"
#include "memc_isr/Driver/KI7416_reg.h"
#include "vgip_isr/scalerVIP.h"
#include "vgip_isr/scalerVideo.h"
#include "vgip_isr/scalerDCC.h"
#include "vgip_isr/scalerDI.h"
#include "rbus/sb2_reg.h"
#include "rbus/tve_reg.h"
#include "rbus/tve_dma_reg.h"
#include "rbus/vodma_reg.h"

//#include "rbus/crt_sys_reg.h" /* henry @ mac5 161216 */
//#include "rbus/crt_reg.h"
//#include "rbus/pll_reg_reg.h"
//#include "rbus/ppoverlay_reg.h"
#include "tvscalercontrol/scaler/scalerstruct.h"
#include "tvscalercontrol/vip/scalerColor.h"
#include "tvscalercontrol/vip/vip_reg_def.h"
#include <tvscalercontrol/scalerdrv/scalerdrv.h>
#include <tvscalercontrol/i3ddma/i3ddma_drv.h>

#if 0 // Fix me in Mac5p -- Seamless conflict (Roger's code in a88e32d998a42405b2b10ddaa7be242d2a28765b is in if)
#include <tvscalercontrol/i3ddma/i3ddma.h>
#include <tvscalercontrol/vo/rtk_vo.h>
#endif
#include <mach/rtk_log.h>
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#include <rtk_kdriver/RPCDriver.h>

// for register dump
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

#ifdef CONFIG_I2RND_ENABLE
#include <rbus/vodma_reg.h>
#include <tvscalercontrol/scalerdrv/scaler_i2rnd.h>
#endif
#ifdef CONFIG_PST_ENABLE
#include <tvscalercontrol/scalerdrv/scaler_pst.h>
#endif

/* Function Prototype */
static int vgip_isr_suspend(struct platform_device *dev, pm_message_t state);
static int vgip_isr_resume(struct platform_device *dev);
static long vgip_isr_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);

extern int updateVODMASetting(unsigned int);
/* Variables */
static BOOL I2R_PVR_MAIN_flag = TRUE;
unsigned int main_repeat_mask_pre = 0;
extern unsigned char ini_ReadSrcDet;
static unsigned char Enter_Hist = TRUE;
static struct class *vgip_isr_class = NULL;
static struct cdev vgip_isr_cdev;
static struct platform_device *vgip_isr_platform_devs = NULL;
static struct platform_driver vgip_isr_platform_driver = {
#ifdef CONFIG_PM
	.suspend		= vgip_isr_suspend,
	.resume			= vgip_isr_resume,
#endif
	.driver = {
		.name		= "vgip_isr",
		.bus		= &platform_bus_type,
	},
};

static struct platform_driver online_isr_platform_driver;

struct file_operations vgip_isr_fops = {
	.owner                  = THIS_MODULE,
	.unlocked_ioctl         = vgip_isr_ioctl,
};

static int vgip_isr_suspend(struct platform_device *dev, pm_message_t state)
{
	printk(KERN_NOTICE "Before [VGIP_ISR] suspend\n");

	// disable VGIP interrupt
	vgip_vgip_chn1_ctrl_RBUS vgip_chn1_ctrl_reg;
	vgip_chn1_ctrl_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_chn1_ctrl_reg.ch1_vact_end_ie = 0;
	rtd_outl(VGIP_VGIP_CHN1_CTRL_reg, vgip_chn1_ctrl_reg.regValue);

	return 0;
}

static int vgip_isr_resume(struct platform_device *dev)
{
	printk(KERN_NOTICE "After [VGIP_ISR] resume\n");

        // disable route to VCPU
        rtd_outl(SYS_REG_INT_CTRL_VCPU_reg, BIT(SYS_REG_INT_CTRL_VCPU_dispi_int_vcpu_routing_en_shift));
        // enable route to SCPU
        rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, BIT(SYS_REG_INT_CTRL_SCPU_dispi_int_scpu_routing_en_shift) | BIT(SYS_REG_INT_CTRL_SCPU_write_data_shift));
        // enable VGIP interrupt
        rtd_maskl(VGIP_VGIP_CHN1_CTRL_reg,~(VGIP_VGIP_CHN1_CTRL_ch1_vact_end_ie_mask),VGIP_VGIP_CHN1_CTRL_ch1_vact_end_ie_mask);

	ini_ReadSrcDet=0;

	return 0;
}

static long vgip_isr_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	dummy_vgip_isr_struct dummy;
	int ret = 0;

	switch (cmd) {
	case VGIP_ISR_IOCT_DUMMY:
		ret = copy_from_user(&dummy, (void *)arg, sizeof(dummy));
		break;
	};

	return ret;
}

//#define debug_ISR
#define BIT(x)               (1 <<x)

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
extern void dolby_trigger_timer6(void);
#endif
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
irqreturn_t OnlineMeasureISR(int irq, void *dev_id)
{
	extern void triggle_onms_handler(unsigned char display);
	unsigned char online1_flag = 0, online2_flag = 0;
#ifdef CONFIG_FORCE_RUN_I3DDMA
    unsigned char online3_flag = 0;
#endif
	vgip_int_ctl_RBUS int_ctl_reg;
	onms_onms1_status_RBUS onms_onms1_status_reg;
	onms_onms1_interrupt_en_RBUS onms_onms1_interrupt_en_reg;
	onms_onms2_status_RBUS onms_onms2_status_reg;
	onms_onms2_interrupt_en_RBUS onms_onms2_interrupt_en_reg;
#ifdef CONFIG_FORCE_RUN_I3DDMA
	onms_onms3_status_RBUS onms_onms3_status_reg;
	onms_onms3_interrupt_en_RBUS onms_onms3_interrupt_en_reg;
#endif
	int_ctl_reg.regValue = scaler_rtd_inl( VGIP_INT_CTL_reg );
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if ( int_ctl_reg.onms1_int_ie == 0 && int_ctl_reg.onms2_int_ie == 0 && int_ctl_reg.onms3_int_ie == 0)	// _BIT6
		return IRQ_NONE;
#else
	if ( int_ctl_reg.onms1_int_ie == 0 && int_ctl_reg.onms2_int_ie == 0)	// _BIT6
		return IRQ_NONE;
#endif
	onms_onms1_status_reg.regValue = scaler_rtd_inl(ONMS_onms1_status_reg);
	onms_onms1_interrupt_en_reg.regValue = scaler_rtd_inl(ONMS_onms1_interrupt_en_reg);
	if((onms_onms1_status_reg.regValue & onms_onms1_interrupt_en_reg.regValue)>0)
		online1_flag = 1;
	else
		online1_flag = 0;
	onms_onms2_status_reg.regValue = scaler_rtd_inl(ONMS_onms2_status_reg);
	onms_onms2_interrupt_en_reg.regValue = scaler_rtd_inl(ONMS_onms2_interrupt_en_reg);
	if((onms_onms2_status_reg.regValue & onms_onms2_interrupt_en_reg.regValue)>0)
		online2_flag = 1;
	else
		online2_flag = 0;

#ifdef CONFIG_FORCE_RUN_I3DDMA
	onms_onms3_status_reg.regValue = scaler_rtd_inl(ONMS_onms3_status_reg);
	onms_onms3_interrupt_en_reg.regValue = scaler_rtd_inl(ONMS_onms3_interrupt_en_reg);
	if((onms_onms3_status_reg.regValue & onms_onms3_interrupt_en_reg.regValue)>0)
		online3_flag = 1;
	else
		online3_flag = 0;
#endif

#ifdef CONFIG_FORCE_RUN_I3DDMA
	if(online1_flag || online2_flag || online3_flag)
#else
	if(online1_flag || online2_flag)
#endif
	{//process online measure interrupt
		if (online1_flag) {
			//step 1 clean onlinemeasure interrupt pending
			//scaler_rtd_outl(ONMS_onms1_status_reg, onms_onms1_status_reg.regValue);
			//step 2 disable onlinemeasure interrupt
			scaler_rtd_outl(ONMS_onms1_interrupt_en_reg, 0);
			int_ctl_reg.onms1_int_ie = 0;
			scaler_rtd_outl(VGIP_INT_CTL_reg, int_ctl_reg.regValue);
			//Syep3 pass RPC to Notify kernel scaler code to process signel not stable issue
			//FIX ME

		}

#ifdef CONFIG_FORCE_RUN_I3DDMA
		if (online3_flag) {
			//step 1 clean onlinemeasure interrupt pending
			//scaler_rtd_outl(ONMS_onms1_status_reg, onms_onms1_status_reg.regValue);
			//step 2 disable onlinemeasure interrupt
			scaler_rtd_outl(ONMS_onms3_interrupt_en_reg, 0);
			int_ctl_reg.onms3_int_ie = 0;
			scaler_rtd_outl(VGIP_INT_CTL_reg, int_ctl_reg.regValue);
			//Syep3 pass RPC to Notify kernel scaler code to process signel not stable issue
			triggle_onms_handler(SLR_MAIN_DISPLAY);
		}
		if(online3_flag || online1_flag)
		{
			triggle_onms_handler(SLR_MAIN_DISPLAY);//main online error
		}
#else
		if(online1_flag)
		{
			triggle_onms_handler(SLR_MAIN_DISPLAY);//main online error
		}
#endif
		if (online2_flag) {
			//step 1 clean onlinemeasure interrupt pending
			//scaler_rtd_outl(ONMS_onms2_status_reg, onms_onms2_status_reg.regValue);
			//step 2 disable onlinemeasure interrupt
			scaler_rtd_outl(ONMS_onms2_interrupt_en_reg, 0);
			int_ctl_reg.onms2_int_ie = 0;
			scaler_rtd_outl(VGIP_INT_CTL_reg, int_ctl_reg.regValue);
			//Syep3 pass RPC to Notify kernel scaler code to process signel not stable issue
			//FIX ME
			triggle_onms_handler(SLR_SUB_DISPLAY);//sub online error
		}
		return IRQ_HANDLED;
	}else{
		return IRQ_NONE;
	}
}
#endif


#ifdef APVR_ISR_DEBUG
int idma_get_field_mode_sub(void)
{

    return SUB_VGIP_VGIP_CHN2_STATUS_get_ch2_field_pol(rtd_inl(SUB_VGIP_VGIP_CHN2_STATUS_reg)) ? 0:1;//1: 0;
}
#endif
extern HDR_MODE get_HDMI_HDR_mode(void);
extern unsigned short Scaler_DispGetInputInfoByDisp(unsigned char channel, SLR_INPUT_INFO infoList);
extern void dynamic_change_hdr_setting(unsigned char hdr_enable);
extern unsigned char Scaler_I2rnd_get_enable(void);

int buf_even_addr = 0;
int buf_odd_addr = 0;
#define TVE_VFLIP_SIZE_OFFSET 720*575*2
irqreturn_t vgip_isr(int irq, void *dev_id)
{

#ifdef debug_ISR

static unsigned int time_cnt1=0;
unsigned int reg_value = 0;
reg_value = rtd_inl(0xb802e4f8);
if((reg_value & BIT(30))){
	time_cnt1++;
}

int time0, time1, time2;
static int exe_cnt=0, exe_cnt_2=0;
static int time0s_set=0, time1s_set=0, time2s_set;
static int time0s_start=0, time1s_start=0, time2s_start=0;
static int time0s_end=0, time1s_end=0, time2s_end=0;
static int time0s_cnt=0, time1s_cnt=0, time2s_cnt=0;
int line_cnt, line_info;

exe_cnt++;

#endif

#ifdef APVR_ISR_DEBUG
static unsigned int apvr_cur_time = 0;
static unsigned int apvr_pre_time = 0;
static int apvr_cur_field = -1;
static int apvr_pre_field = -1;
#endif


#if 0


	unsigned int status;

	status = rtd_inl(0xb8022214);

	if (!(status & BIT(25)) && !(status & BIT(24)))
		return IRQ_NONE;

	if (status & BIT(24)) {
		rtd_setbits(0xb8022214, BIT(24));
	}

	if (status & BIT(25)) {
		rtd_setbits(0xb8022214, BIT(25));
	}

#else
	// Handle Flag
	unsigned char handle_ch1_sta_flag = 0;
	unsigned char handle_ch1_end_flag = 0;
	unsigned char handle_ch2_sta_flag = 0;
	unsigned char handle_ch2_end_flag = 0;
	unsigned char handle_dma_ch3_sta_flag = 0;
	unsigned char handle_dma_ch3_end_flag = 0;
	UINT8 handle_h3ddma_Cap_last_wr_flag = 0;
	unsigned char handle_h3ddma_Cap2_last_wr_flag = 0;
	static unsigned int non_vact_start_cnt = 0, non_vact_end_cnt = 0;
#ifdef CONFIG_I2RND_ENABLE
	vodma_vodma_i2rnd_m_flag_RBUS vo_i2rnd_m_flag;
#endif
	_system_setting_info* system_info_structure_table = NULL;
	system_info_structure_table = scaler_GetShare_Memory_system_setting_info_Struct();

	/*==main channel==*/
	vgip_int_ctl_RBUS int_ctl_reg;
	vgip_vgip_chn1_ctrl_RBUS vgip_chn1_ctrl_reg;
	vgip_vgip_chn1_status_RBUS vgip_chn1_status_reg;
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_chn1_ctrl_reg;
	dma_vgip_dma_vgip_status_RBUS dma_vgip_chn1_status_reg;
	h3ddma_interrupt_enable_RBUS h3ddma_interrupt_enable_reg;
	h3ddma_cap_status_RBUS h3ddma_cap_status_reg;
	histogram_ich1_hist_status_RBUS ich1_hist_status;

	/*==sub channel==*/
	#if 1
	sub_vgip_vgip_chn2_ctrl_RBUS vgip_chn2_ctrl_reg;
	sub_vgip_vgip_chn2_status_RBUS vgip_chn2_status_reg;
	#endif

	vgip_chn1_ctrl_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_CTRL_reg);
	vgip_chn1_status_reg.regValue = rtd_inl(VGIP_VGIP_CHN1_STATUS_reg);
	// check IDMA VGIP interrupt pending
	dma_vgip_chn1_ctrl_reg.regValue = scaler_rtd_inl(DMA_VGIP_DMA_VGIP_CTRL_reg);
	dma_vgip_chn1_status_reg.regValue = scaler_rtd_inl(DMA_VGIP_DMA_VGIP_STATUS_reg);
	h3ddma_interrupt_enable_reg.regValue = scaler_rtd_inl(H3DDMA_Interrupt_Enable_reg);
	h3ddma_cap_status_reg.regValue = scaler_rtd_inl(H3DDMA_Cap_Status_reg);
	ich1_hist_status.regValue = rtd_inl(HISTOGRAM_ICH1_Hist_Status_reg);

	int_ctl_reg.regValue = rtd_inl( VGIP_INT_CTL_reg );
	if ( int_ctl_reg.vgip_int_ie == 0 ){	// _BIT3
		//return IRQ_NONE;//can not return, because other ip will cause interrupt
	}

	/********main channel*******/
	if (vgip_chn1_ctrl_reg.ch1_vact_start_ie &&  vgip_chn1_status_reg.ch1_vact_start && int_ctl_reg.vgip_int_ie){	// _BIT24
		ich1_hist_status.ch1_his_his_irq = 1;
		handle_ch1_sta_flag = 1;
	}

	if (vgip_chn1_ctrl_reg.ch1_vact_end_ie && vgip_chn1_status_reg.ch1_vact_end && int_ctl_reg.vgip_int_ie){	// _BIT25
		handle_ch1_end_flag = 1;
	}

	if (dma_vgip_chn1_ctrl_reg.dma_vact_start_ie && dma_vgip_chn1_status_reg.dma_vact_start && int_ctl_reg.vgip_int_ie) {	// _BIT24
		handle_dma_ch3_sta_flag = 1;
	}

	if (dma_vgip_chn1_ctrl_reg.dma_vact_end_ie && dma_vgip_chn1_status_reg.dma_vact_end && int_ctl_reg.vgip_int_ie) {		// _BIT25
		handle_dma_ch3_end_flag = 1;
	}

	if(h3ddma_interrupt_enable_reg.cap_last_wrt_ie && h3ddma_cap_status_reg.cap_last_wr_flag)
		handle_h3ddma_Cap_last_wr_flag = 1;

	if(h3ddma_interrupt_enable_reg.cap2_last_wrt_ie && h3ddma_cap_status_reg.cap2_last_wr_flag)
		handle_h3ddma_Cap2_last_wr_flag = 1;

	/*********sub channel*******/
	#if 1
	// check channel 2 interrupt pending
	vgip_chn2_ctrl_reg.regValue = scaler_rtd_inl( SUB_VGIP_VGIP_CHN2_CTRL_reg );
	if (vgip_chn2_ctrl_reg.ch2_vact_start_ie || vgip_chn2_ctrl_reg.ch2_vact_end_ie) { //_BIT24 _BIT25 enable channel2 VActiveStainterrupt or VActiveEndinterrupt
		//channel 2 interrupt
		vgip_chn2_status_reg.regValue = scaler_rtd_inl( SUB_VGIP_VGIP_CHN2_STATUS_reg );

		if (vgip_chn2_ctrl_reg.ch2_vact_start_ie && vgip_chn2_status_reg.ch2_vact_start && int_ctl_reg.vgip_int_ie)	//	_BIT24
			handle_ch2_sta_flag = 1;

		if (vgip_chn2_ctrl_reg.ch2_vact_end_ie && vgip_chn2_status_reg.ch2_vact_end && int_ctl_reg.vgip_int_ie)		//	_BIT25
			handle_ch2_end_flag = 1;
	}
	#endif

	if(handle_ch1_end_flag)
		updateVODMASetting(0);

	if((!(vgip_chn1_ctrl_reg.ch1_vact_end_ie && vgip_chn1_status_reg.ch1_vact_end )) &&
		(handle_ch1_sta_flag || handle_ch1_end_flag || handle_ch2_sta_flag || handle_ch2_end_flag || handle_dma_ch3_sta_flag || handle_dma_ch3_end_flag))
	{
		rtd_outl(HISTOGRAM_ICH1_Hist_Status_reg, ich1_hist_status.regValue);
	}

#ifdef CONFIG_I2RND_ENABLE
	vodma_vodma_i2rnd_st_RBUS vodma_i2rnd_st_reg;

	if(handle_ch1_sta_flag==1 || handle_ch1_end_flag==1){
		if(Scaler_I2rnd_get_enable()==1){
			vodma_i2rnd_st_reg.regValue= rtd_inl(VODMA_vodma_i2rnd_st_reg);
			if(vodma_i2rnd_st_reg.i2rnd_st == 0x3){
				I2R_PVR_MAIN_flag = 1;
			}else{
				I2R_PVR_MAIN_flag = 0;
			}
		}else{
			I2R_PVR_MAIN_flag = 1;
		}
	}
#else
	I2R_PVR_MAIN_flag = 1;
#endif

#ifdef CONFIG_HDR_SDR_SEAMLESS
extern HDR_SDR_SEAMLESS_PQ_STRUCT HDR_SDR_SEAMLESS_PQ;
if (handle_ch1_end_flag == 1&&HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_PQModeInfo]==1&&HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_BLACK_LEVEL]==1){
	if(get_HDMI_HDR_mode() == HDR_HDR10_HDMI)
	{
#if 1 // Fix me in Mac5p -- Seamless conflict (Roger's code in a88e32d998a42405b2b10ddaa7be242d2a28765b is in else)
//		down(&HDR_Setting_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			dynamic_change_hdr_setting(TRUE);
//		up(&HDR_Setting_Semaphore);
	}else{
//		down(&HDR_Setting_Semaphore);
		if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE)
			dynamic_change_hdr_setting(FALSE);
//		up(&HDR_Setting_Semaphore);
	}
	HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_PQModeInfo]=0;
	HDR_SDR_SEAMLESS_PQ.HDR_SDR_SEAMLESS_PQ_SET[HDR_SDR_SEAMLESS_PQ_HAL_BLACK_LEVEL]=0;
}
#else // Fix me in Mac5p
		i3ddma_change_sharememory = (i3ddma_change_info *)Scaler_GetShareMemVirAddr(SCALERIOC_I3DDMA_FORMAT_CHANGE_SHAREMEMORY_FLAG);
		if(get_i3ddma_change_format_flag() && (i3ddma_change_sharememory->change_flag == 0))
		{
			spin_lock(get_i3ddma_change_spinlock());//lock i3ddma change spinlock
			set_i3ddma_change_format_flag(FALSE);
			cur_hdmi_hdr_mode = get_HDMI_HDR_mode();
			spin_unlock(get_i3ddma_change_spinlock());//unlock i3ddma change  spinlock
			if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
            {
    			target_output_color = get_target_i3ddma_color_format();
    			i3ddma_change_sharememory->target_color = Scaler_ChangeUINT32Endian(target_output_color);
    			i3ddma_change_sharememory->change_flag = Scaler_ChangeUINT32Endian(1);
    			I3ddma_format_changed_seamless(get_backup_hdmi_info(), target_output_color);
    			need_change_vgip_pq = TRUE;//need to update pq and vtop 422 to 444
            }
		}
	}
	if(handle_ch1_sta_flag && need_change_vgip_pq)
	{
		need_change_vgip_pq = FALSE;
		set_change_vgip_pq = TRUE;
	}
	if(handle_ch1_end_flag && set_change_vgip_pq)
	{
		set_change_vgip_pq = FALSE;
        if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_HDMI)
		    dynamic_change_hdr_setting((cur_hdmi_hdr_mode == HDR_HDR10_HDMI)? TRUE : FALSE, target_output_color);
	}
    if(handle_ch1_end_flag &&(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE))
    {
        if(get_vdec_seamless_change_flag())
        {
			spin_lock(get_vdec_seamless_change_spinlock());//lock vdec semaless change spinlock
			set_vdec_seamless_change_flag(FALSE);
			spin_unlock(get_vdec_seamless_change_spinlock());//unlock vdec semaless change  spinlock
            if(Get_DisplayMode_Src(SLR_MAIN_DISPLAY) == VSC_INPUTSRC_VDEC)
            {//run hdr change
                dynamic_change_hdr_setting((get_OTT_HDR_mode() == HDR_HDR10_VDEC)? TRUE : FALSE, I3DDMA_COLOR_YUV422);
            }
        }
    }
#endif
#endif

#ifdef TVE_FUNCTION_ENABLE
	if(handle_dma_ch3_end_flag && scaler_scart_out_isr_get_enable())
	{
		if(h3ddma_cap_status_reg.cap_field)
		{
			if(h3ddma_cap_status_reg.cap_block_sel == 0)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg);
				}
			}
			else if(h3ddma_cap_status_reg.cap_block_sel==1)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg);
				}

			}
			else if(h3ddma_cap_status_reg.cap_block_sel==2)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg);
				}

			}
			else if(h3ddma_cap_status_reg.cap_block_sel==3)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg);
				}

			}
		}
		else
		{
			if(h3ddma_cap_status_reg.cap_block_sel == 0)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg);
				}
			}
			else if(h3ddma_cap_status_reg.cap_block_sel==1)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L4_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg);
				}

			}
			else if(h3ddma_cap_status_reg.cap_block_sel==2)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L1_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg);
				}

			}
			else if(h3ddma_cap_status_reg.cap_block_sel==3)
			{
				if(scaler_get_tve_vflip_enable())
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg)+TVE_VFLIP_SIZE_OFFSET;
				}
				else
				{
					buf_even_addr = scaler_rtd_inl(H3DDMA_Cap_L2_Start_reg);
					buf_odd_addr = scaler_rtd_inl(H3DDMA_Cap_L3_Start_reg);
				}

			}
		}
		
		{
			if(TVE_syncgen_status_i_get_i_field(scaler_rtd_inl(TVE_syncgen_status_i_reg)) == 0)
			{
				//pr_emerg("Enter even field![%d,%d,%x]\n",h3ddma_cap_status_reg.cap_field,h3ddma_cap_status_reg.cap_block_sel,buf_odd_addr);
				scaler_rtd_maskl(TVE_intpos_i_reg, ~(TVE_intpos_i_write_en2_mask|TVE_intpos_i_int_vpos_mask), TVE_intpos_i_write_en2(1) | TVE_intpos_i_int_vpos(625/2+2));
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT0_reg, buf_odd_addr/8+0x5a);	  //  dma addr  //和3d dma差了8倍
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT1_reg, buf_odd_addr/8+0x5a);	  //  dma addr
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT2_reg, buf_odd_addr/8+0x5a);	  //  dma addr
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT3_reg, buf_odd_addr/8+0x5a);	  
			}
			else
			{
				//pr_emerg("Enter odd  field![%d,%d,%x]\n",h3ddma_cap_status_reg.cap_field,h3ddma_cap_status_reg.cap_block_sel,buf_even_addr);
				scaler_rtd_maskl(TVE_intpos_i_reg, ~(TVE_intpos_i_write_en2_mask|TVE_intpos_i_int_vpos_mask), TVE_intpos_i_write_en2(1) | TVE_intpos_i_int_vpos(2));
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT0_reg, buf_even_addr/8);	  //  dma addr  //和3d dma差了8倍
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT1_reg, buf_even_addr/8);	  //  dma addr
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT2_reg, buf_even_addr/8);	  //  dma addr
				scaler_rtd_outl(TVE_DMA_TVEVDDMA_SATRT3_reg, buf_even_addr/8);	  
			}

		}
	}
#endif

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT  //DolbyHDR_fix_me!!
#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	if(get_HDMI_HDR_mode() == HDR_DOLBY_HDMI){
#if 1
        if((HDR_DolbyVision_Get_CurHdmiMode() > DOLBY_HDMI_OFF) && handle_ch1_end_flag){
			// send RPC to Linux kernel -- HDMI mode data end for B05 setting apply
			HDR_DOLBY_VISION_HDMI_Send_Write_Index_RPC();
		}

		// only check md_parser data end interrupt when md_parser enabled
		if(((HDR_DolbyVision_Get_CurHdmiMode() > DOLBY_HDMI_OFF) && handle_h3ddma_Cap2_last_wr_flag)
			|| ((HDR_DolbyVision_Get_CurHdmiMode() == DOLBY_HDMI_OFF) && handle_dma_ch3_end_flag))
		{
			HDR_DolbyVision_HDMI_handler();
		}/*else if((HDR_DolbyVision_Get_CurHdmiMode() > DOLBY_HDMI_OFF) && handle_ch1_end_flag){
			// send RPC to Linux kernel -- HDMI mode data end for B05 setting apply
			HDR_DOLBY_VISION_HDMI_Send_Write_Index_RPC();
		}*/
#endif
	}else if((get_OTT_HDR_mode() == HDR_DOLBY_COMPOSER) && (get_HDMI_HDR_mode() == HDR_MODE_DISABLE)){
		//Normal mode data end for B05 setting apply
		if(handle_ch1_end_flag){
			dolby_trigger_timer6();//trigger to apply finish
		}
	}
#endif
#endif

#ifdef CONFIG_I2RND_ENABLE
	if(handle_ch1_sta_flag && main_repeat_mask_pre){
		//reset repeat mask
		vodma_i2rnd_st_reg.regValue= rtd_inl(VODMA_vodma_i2rnd_st_reg);
		if(vodma_i2rnd_st_reg.i2rnd_st == 0x3){
			vo_i2rnd_m_flag.regValue = IoReg_Read32(VODMA_vodma_i2rnd_m_flag_reg);
			if(main_repeat_mask_pre == 1)
			{
				vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en = 1;
				IoReg_Write32(VODMA_vodma_i2rnd_m_flag_reg, vo_i2rnd_m_flag.regValue);
				main_repeat_mask_pre =0;
			}
			else
			{
				main_repeat_mask_pre --;
			}
		}
	}

	//Eric@0809 Set i2rnd & pst write point
	if(get_i2rnd_pst_write_pnt_counter()){
		if(handle_ch1_sta_flag){
			vodma_i2rnd_st_reg.regValue= IoReg_Read32(VODMA_vodma_i2rnd_st_reg);
			vo_i2rnd_m_flag.regValue = IoReg_Read32(VODMA_vodma_i2rnd_m_flag_reg);
			//main path
			if(vodma_i2rnd_st_reg.i2rnd_st == 0x3){
				//check main repeat mask
				if((vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en == 1)||(main_repeat_mask_pre && (vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en == 0))){

					main_repeat_mask_pre = main_repeat_mask_pre + get_i2rnd_pst_write_pnt_counter();
					vo_i2rnd_m_flag.i2rnd_hw_mask_repeat_frame_m_en = 0;
					IoReg_Write32(VODMA_vodma_i2rnd_m_flag_reg, vo_i2rnd_m_flag.regValue);
				}
			}
			if (Scaler_I2rnd_get_enable()) {
				Scaler_i2rnd_set_write_point();
			}
		#ifdef CONFIG_PST_ENABLE
			if (Scaler_main_md_pst_get_enable()) {
				Scaler_pst_set_write_point(_MAIN_MD);
			}
		#endif
			set_i2rnd_pst_write_pnt_counter(0);
		}
	}
#endif

#if 0 //debug : bypass
	// Check if handled IRQ
	if (handle_ch1_sta_flag || handle_ch1_end_flag)
		scaler_rtd_outl(VGIP_VGIP_CHN1_STATUS_reg, vgip_chn1_status_reg.regValue);	//write clear status

	if (handle_dma_ch3_sta_flag || handle_dma_ch3_end_flag)
		scaler_rtd_outl(DMA_VGIP_DMA_VGIP_STATUS_reg, dma_vgip_chn1_status_reg.regValue);	//write clear status

	#if 1// sub channel
		if(handle_ch2_sta_flag || handle_ch2_end_flag)
			scaler_rtd_outl(SUB_VGIP_VGIP_CHN2_STATUS_reg, vgip_chn2_status_reg.regValue);	//write clear status
	#endif

	if(handle_ch1_sta_flag
		 || handle_ch2_sta_flag
		 || handle_ch2_end_flag
		 || handle_dma_ch3_sta_flag
		 || handle_dma_ch3_end_flag){
		return IRQ_HANDLED;
	}else{
		return IRQ_NONE;
	}
#endif



#ifdef debug_ISR
	if((reg_value & BIT(27))){

		time0s_cnt++;

		line_info = rtd_inl(0xb8022234);
		line_cnt = ((line_info & 0x00FFF000)>>12);

		time0 = rtd_inl(0xB801B6A8);
		if(time0s_set==0) {
			time0s_start = time0;
			time0s_set=1;
			time0s_cnt=0;
		}
		time0s_end = rtd_inl(0xB801B6A8);

		if((time0s_end-time0s_start)>=90000) {
			printk("[VCPU]VGIP isr runs %d times=%d\n\n",time0s_cnt, (time0s_end-time0s_start));
			printk("[VCPU]VGIP isr line = %d\n\n", line_cnt);
			printk("[VCPU]VGIP time_cnt1 = %d\n\n", time_cnt1);
			printk("[VCPU]VGIP sta_flag = %d,end_flag=%d \n\n", handle_ch1_sta_flag, handle_ch1_end_flag);
			printk("[VCPU]VGIP start_ie = %d,vact_start=%d \n\n", vgip_chn1_ctrl_reg.ch1_vact_start_ie, vgip_chn1_status_reg.ch1_vact_start);
			printk("[VCPU]VGIP end_ie = %d,vact_end=%d \n\n", vgip_chn1_ctrl_reg.ch1_vact_end_ie, vgip_chn1_status_reg.ch1_vact_end);
			time0s_set = 0;
		}

	}
#endif

	//===============================
	// Handle Channel 1 VactStart Interrupt
	//===============================
	if ( handle_ch1_sta_flag){

#ifdef debug_ISR

if((reg_value & BIT(29))){

	exe_cnt++;
	time1s_cnt++;

	line_info = rtd_inl(0xb8022234);
	line_cnt = ((line_info & 0x00FFF000)>>12);

	time1 = rtd_inl(0xB801B6A8);
	if(time1s_set==0) {
		time1s_start = time1;
		time1s_set=1;
		time1s_cnt=0;
	}
	time1s_end = rtd_inl(0xB801B6A8);

	if(exe_cnt%120==0) {
		printk("[VCPU][sta]VGIP isr line = %d\n\n", line_cnt);
		exe_cnt = 0;
	}

	if((time1s_end-time1s_start)>=90000) {
		printk("[VCPU][sta]VGIP isr runs %d times=%d\n\n",time1s_cnt, (time1s_end-time1s_start));
		printk("[VCPU][sta]VGIP isr line = %d\n\n", line_cnt);
		printk("[VCPU][sta]VGIP time_cnt1 = %d\n\n", time_cnt1);
		time1s_set = 0;
	}

}

#else

	if(I2R_PVR_MAIN_flag){
		/*==Film mode check==*/
		if (Scaler_Get_InputSrcInit() == NULL || Scaler_DispGetInfoPtr() ==NULL ){ // wait init
			; // do nothing
		} else {
			if(Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE){ //in active area
				if ( fwif_color_GetAutoMAFlag() && Scaler_DispGetStatus(SLR_MAIN_DISPLAY, SLR_DISP_INTERLACE)) { // Enable auto_ma and interlace input
					scalerVIP_film_FWmode_film_reset();
					#if 0
						unsigned char isrc = Scaler_InputSrcGetType(SLR_MAIN_DISPLAY);
						if (isrc == _SRC_VO || isrc == _SRC_USB || isrc == _SRC_WIFI) {

							extern FILM_FW_ShareMem_ISR *g_Share_Memory_FILM_FW;
							extern unsigned char GMV_status_for_Filim;

							if (g_Share_Memory_FILM_FW) {
								if(GMV_status_for_Filim == 0){
									g_Share_Memory_FILM_FW->st_DI_STATUS_VPAN = scalerVIP_DI_MiddleWare_GetStatus(STATUS_VPAN);
								} else {
									g_Share_Memory_FILM_FW->st_DI_STATUS_VPAN = 1;
								}
								g_Share_Memory_FILM_FW->flag_Trigger = 0x1;
							}
						}
					#else
						scalerVIP_film_FWmode();  // FW film
					#endif
				}
			}
		}
	}
#endif
		if(handle_ch1_sta_flag){
			vgip_chn1_status_reg.ch1_vact_start = 1;	//write clear status
		}

	}// end if handle_ch1_sta_flag

	//===============================
	// Handle Channel 1 VactEndInterrupt
	//===============================
#ifndef debug_ISR
	if(I2R_PVR_MAIN_flag && (handle_ch1_sta_flag || handle_ch1_end_flag || handle_ch2_sta_flag || handle_ch2_end_flag || handle_dma_ch3_sta_flag || handle_dma_ch3_end_flag)){
		if((scalerVIP_Get_PT_NO()!=0)&&(!vgip_chn1_ctrl_reg.ch1_vact_end_ie)) {
			scalerVIP_Set_Parameter_forLGM2(0); // reset value
		}
	}
#endif


	if ( handle_ch1_end_flag) {
#ifdef debug_ISR

if((reg_value & BIT(30))){

	exe_cnt_2++;
	time2s_cnt++;

	line_info = rtd_inl(0xb8022234);
	line_cnt = ((line_info & 0x00FFF000)>>12);

	time2 = rtd_inl(0xB801B6A8);
	if(time2s_set==0) {
		time2s_start = time1;
		time2s_set=1;
		time2s_cnt=0;
	}
	time2s_end = rtd_inl(0xB801B6A8);

	if(exe_cnt_2%120==0) {
		printk("[VCPU][end]VGIP isr line = %d\n\n", line_cnt);
		exe_cnt_2 = 0;
	}

	if((time2s_end-time2s_start)>=90000) {
		printk("[VCPU][end]VGIP isr runs %d times=%d\n\n",time2s_cnt, (time2s_end-time2s_start));
		printk("[VCPU][end]VGIP isr line = %d\n\n", line_cnt);
		printk("[VCPU][end]VGIP time_cnt1 = %d\n\n", time_cnt1);
		time2s_set = 0;
	}

}

#else
	if(I2R_PVR_MAIN_flag){
		scalerVIP_color_colorspacergb2yuvtransfer(_CHANNEL1, NULL);

		if ( Scaler_DispGetInfoPtr() != NULL && Scaler_DispGetInputInfoByDisp(SLR_MAIN_DISPLAY, SLR_INPUT_STATE) == _MODE_STATE_ACTIVE ){

			if(Enter_Hist){

				scalerVIP_colorHistISR(_CHANNEL1);  // Erin

				if(fwif_color_GetAutoMAFlag()) {

					scalerVIP_colorMaAutoISR(_CHANNEL1); //Thur 20070920

					extern unsigned char g_IsNot4KVO;
					if( g_IsNot4KVO && Scaler_Get3DEnable() && scalerVIP_check_vdc_hw_pwr() && AVD_Clock_Flag_detection()) {
						scalerVideo_adaptive3DAdjust();
						/*
						if(Scaler_InputSrcGetMainChFrom() ==_SRC_FROM_VDC) {//VDC source enter DI => refer to external accumulation
							scalerVideo_adaptive3DAdjust();//wjchen 1225, for costomer2 new adaptive 3d threshold
						} else { //"NOT" VDC source enter DI => refer to vdc internal accumulation
							scalerVideo_adaptive3DAdjust();//wjchen 1225, for costomer2 new adaptive 3d threshold
						}
						*/
					}
				}

			}
		}
	}

#endif
		if(handle_ch1_end_flag)
			vgip_chn1_status_reg.ch1_vact_end = 1;	//write clear status

	}

#ifdef CONFIG_FRAMERATE_DEBUG_IN_VGIPISR
	vbe_disp_debug_framerate_change_msg();
#endif

	//===============================
	// clear DMA VGIP interrupt status
	//===============================
	if(handle_dma_ch3_sta_flag)
		dma_vgip_chn1_status_reg.dma_vact_start = 1;

	if(handle_dma_ch3_end_flag)
		dma_vgip_chn1_status_reg.dma_vact_end = 1;

	if(handle_h3ddma_Cap_last_wr_flag)
		h3ddma_cap_status_reg.cap_last_wr_flag = 1;

	if(handle_h3ddma_Cap2_last_wr_flag)
		h3ddma_cap_status_reg.cap2_last_wr_flag = 1;


/*********sub channel************/
	#if 1//sub channel
	//===============================
	// Handle Channel 1 VactStart Interrupt
	//===============================
		if ( handle_ch2_sta_flag ){
			#if 0
			#ifdef APVR_ISR_DEBUG
			apvr_cur_time=rtd_inl(0xB801B690)/90;
			apvr_cur_field = idma_get_field_mode_sub();
			if((apvr_cur_field == apvr_pre_field) || ((apvr_cur_time-apvr_pre_time) > 30))
			{
				pr_emerg("@@@@@apvr sub vgip isr same cur_field:%d, pre_field:%d, timeintval:%d@@@@@\n", apvr_cur_field,apvr_pre_field,apvr_cur_time-apvr_pre_time);
			}
			apvr_pre_time = apvr_cur_time;
			apvr_pre_field= apvr_cur_field;
			#endif
			// enable a2tov enable
			rtd_outl(REG_SB2_CPU_INT_EN, _BIT28|_BIT0);
			// enable a2tov status
			rtd_outl(REG_SB2_CPU_INT, _BIT28|_BIT0);
			#endif
			vgip_chn2_status_reg.ch2_vact_start = 1;

		}// end if handle_ch2_sta_flag

	//===============================
	// Handle Channel 2 VactEnd Interrupt
	//===============================
		if ( handle_ch2_end_flag ){

			vgip_chn2_status_reg.ch2_vact_end = 1;
		}// end if handle_ch2_end_flag
	#endif

	// Check if handled IRQ
	if (handle_ch1_sta_flag || handle_ch1_end_flag)
		scaler_rtd_outl(VGIP_VGIP_CHN1_STATUS_reg, vgip_chn1_status_reg.regValue);	//write clear status

	if (handle_dma_ch3_sta_flag || handle_dma_ch3_end_flag)
		scaler_rtd_outl(DMA_VGIP_DMA_VGIP_STATUS_reg, dma_vgip_chn1_status_reg.regValue);	//write clear status

	if(handle_h3ddma_Cap_last_wr_flag|| handle_h3ddma_Cap2_last_wr_flag)
		scaler_rtd_outl(H3DDMA_Cap_Status_reg, h3ddma_cap_status_reg.regValue);

	#if 1// sub channel
	if(handle_ch2_sta_flag || handle_ch2_end_flag)
		scaler_rtd_outl(SUB_VGIP_VGIP_CHN2_STATUS_reg, vgip_chn2_status_reg.regValue);	//write clear status
	#endif

#endif

	if(handle_ch1_sta_flag
		|| handle_ch1_end_flag
		 || handle_ch2_sta_flag
		 || handle_ch2_end_flag
		 || handle_dma_ch3_sta_flag
		 || handle_dma_ch3_end_flag
		 || handle_h3ddma_Cap_last_wr_flag
		 || handle_h3ddma_Cap2_last_wr_flag){
		return IRQ_HANDLED;
	}else{
		return IRQ_NONE;
	}

}

static int __init vgip_isr_init_irq(void)
{
	/* Request IRQ */
	if(request_irq(IRQ_IMDOMAIN,
                   vgip_isr,
                   IRQF_SHARED,
                   "VGIP ISR",
                   (void *)vgip_isr_platform_devs))
	{
		pr_err("vgip_isr: cannot register IRQ %d\n", IRQ_IMDOMAIN);
		return -ENXIO;
	}

#ifdef CONFIG_RTK_KDEV_VGIP_INTERRUPT
	if(request_irq(IRQ_IMDOMAIN,
                   OnlineMeasureISR,
                   IRQF_SHARED,
                   "OnlineMeasure ISR",
                   (void *)"ONMS_ISR"))
	{
		pr_err("online_isr_platform_driver_isr: cannot register IRQ %d\n", IRQ_IMDOMAIN);
		return -ENXIO;
	}
#endif

	// disable route to VCPU
	rtd_outl(SYS_REG_INT_CTRL_VCPU_reg,
	            SYS_REG_INT_CTRL_VCPU_dispi_int_vcpu_routing_en_mask);

	// enable route to SCPU
	rtd_outl(SYS_REG_INT_CTRL_SCPU_reg,
	            SYS_REG_INT_CTRL_SCPU_dispi_int_scpu_routing_en_mask |
	            SYS_REG_INT_CTRL_SCPU_write_data_mask);

	// enable VGIP interrupt
	rtd_setbits(0xb8022210, BIT(25));

	pr_info("vgip_isr: register IRQ %d\n", IRQ_IMDOMAIN);

	return 0;
}

static char *vgip_isr_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

static int vgip_isr_init_module(void)
{

#if 0
	int result;
	dev_t dev = MKDEV(VGIP_ISR_MAJOR, 0);

	printk(KERN_NOTICE "vgip_isr: vgip_isr driver for Realtek Media Processors(2016/04/28)\n");

	result = register_chrdev_region(dev, 1, "vgip_isr");
	if (result < 0) {
		printk("vgip_isr: can not get chrdev region...\n");
		return result;
	}
#if 0 //. remove for osd
	vgip_isr_class = class_create(THIS_MODULE, "vgip_isr");
	if (IS_ERR(vgip_isr_class)) {
		printk("vgip_isr: can not create class...\n");
		result = PTR_ERR(vgip_isr_class);
		goto fail_class_create;
	}
#endif

	vgip_isr_class->devnode = vgip_isr_devnode;

	vgip_isr_platform_devs = platform_device_register_simple("vgip_isr", -1, NULL, 0);
	if (platform_driver_register(&vgip_isr_device_driver) != 0) {
		printk("vgip_isr: can not register platform driver...\n");
		result = -EINVAL;
		goto fail_platform_driver_register;
	}

	result = vgip_isr_init_irq();
	if (result < 0) {
		pr_err("vgip_isr: can not register irq...\n");
		return result;
	}

	cdev_init(&vgip_isr_cdev, &vgip_isr_fops);
	vgip_isr_cdev.owner = THIS_MODULE;
	vgip_isr_cdev.ops = &vgip_isr_fops;
	result = cdev_add(&vgip_isr_cdev, dev, 1);
	if (result < 0) {
		printk("vgip_isr: can not add character device...\n");
		goto fail_cdev_init;
	}
	device_create(vgip_isr_class, NULL, dev, NULL, "vgip_isr");

	return 0;

fail_cdev_init:
	platform_driver_unregister(&vgip_isr_device_driver);
fail_platform_driver_register:
	platform_device_unregister(vgip_isr_platform_devs);
	vgip_isr_platform_devs = NULL;
	class_destroy(vgip_isr_class);
fail_class_create:
	vgip_isr_class = NULL;
	unregister_chrdev_region(dev, 1);
	return result;

#else
	int result;
	vgip_isr_platform_devs = platform_device_register_simple("vgip_isr", -1, NULL, 0);
	if (platform_driver_register(&vgip_isr_platform_driver) != 0) {
                printk("vgip_isr: can not register platform driver...\n");
                result = -EINVAL;
                return result;
        }
	result = vgip_isr_init_irq();
	if (result < 0) {
		pr_err("vgip_isr: can not register irq...\n");
		return result;
	}

	return 0;
#endif

}

void vgip_isr_exit_module(void)
{
	free_irq(IRQ_IMDOMAIN, (void *)vgip_isr);
}

module_init(vgip_isr_init_module);
module_exit(vgip_isr_exit_module);

