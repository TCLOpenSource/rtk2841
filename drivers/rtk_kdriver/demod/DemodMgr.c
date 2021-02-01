#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/poll.h>
#include <asm/cacheflush.h>
#include <linux/proc_fs.h>

#include "comm.h"
#include "tuner.h"
#include "demod.h"
#include "demod_rtk_all.h"
#include "demod_rtk_common.h"

#include "DemodMgr.h"
#include "demod_debug.h"

#define RTKDEMOD_MAJOR  0
#define DRV_NAME "rtkdemod"

PS_RTK_DEMOD_DATA pDemod_globe;

struct semaphore rtkdemod_Semaphore;/* This Semaphore is for rtkdemo control*/

unsigned char isDemodConstructors = 0;

unsigned char isUseDDemod = 0;
unsigned char demod_suspend_done = 0;   // TRUE: suspend complete / FALSE: resume complete

/* parameters for debug */
struct proc_dir_entry * demod_proc_dir = NULL;
struct proc_dir_entry * demod_proc_entry = NULL;

#ifdef CONFIG_PM
static int rtk_demod_suspend(struct device *dev)
{
	DEMOD_MGR_CALLER("realtek_demod rtk_demod_suspend begin\n");
	if (isDemodConstructors == 1 && isUseDDemod == 1)
		pDemod_globe->m_pDemod->Suspend(pDemod_globe->m_pDemod);
	DEMOD_MGR_CALLER("realtek_demod rtk_demod_suspend end\n");
	demod_suspend_done = 1;
	return 0;
}

extern struct device* get_i2c_device_ptr_demod_use(void);

static int rtk_demod_resume(struct device *dev)
{

	DEMOD_MGR_CALLER("realtek_demod rtk_demod_resume begin\n");

	if (isDemodConstructors == 1 && isUseDDemod == 1) {
		// IOCTL_RTK_DEMOD_INIT
		//DEMOD_MGR_CALLER("realtek_demod rtk_demod_resume step 01 Init\n");
		pDemod_globe->m_pDemod->Init(pDemod_globe->m_pDemod);

               /*    
		// IOCTL_RTK_DEMOD_SETTVPARA
		//DEMOD_MGR_DBG("realtek_demod rtk_demod_resume step 02 SETTVPARA\n");
		pDemod_globe->m_pTuner->TunerParam.id = pDemod_globe->set_tv_para.id;
		pDemod_globe->m_pTuner->TunerParam.std = pDemod_globe->set_tv_para.std;
		pDemod_globe->m_pTuner->TunerParam.step_freq = pDemod_globe->set_tv_para.step_freq;
		pDemod_globe->m_pTuner->TunerParam.if_freq = pDemod_globe->set_tv_para.if_freq;
		pDemod_globe->m_pTuner->TunerParam.if_inversion = pDemod_globe->set_tv_para.if_inversion;
		pDemod_globe->m_pTuner->TunerParam.if_agc_pola = pDemod_globe->set_tv_para.if_agc_pola;
		pDemod_globe->m_pTuner->TunerParam.min_freq = pDemod_globe->set_tv_para.min_freq;
		pDemod_globe->m_pTuner->TunerParam.max_freq = pDemod_globe->set_tv_para.max_freq;
		pDemod_globe->m_pTuner->TunerParam.lowband_midband_limit_freq = pDemod_globe->set_tv_para.lowband_midband_limit_freq;
		pDemod_globe->m_pTuner->TunerParam.midband_highband_limit_freq = pDemod_globe->set_tv_para.midband_highband_limit_freq;
               */

		// IOCTL_RTK_DEMOD_SETTVMODE
		//DEMOD_MGR_DBG("realtek_demod rtk_demod_resume step 03 SetTvMode=%d\n", pDemod_globe->set_tv_mode_data.mode);
		pDemod_globe->m_pDemod->SetTvMode(pDemod_globe->m_pDemod, (TV_SYSTEM_TYPE)(pDemod_globe->set_tv_mode_data.mode));

/*
		// IOCTL_RTK_DEMOD_SETTVPARA
		//DEMOD_MGR_DBG("realtek_demod rtk_demod_resume step 04 SETTVPARA\n");
		pDemod_globe->m_pTuner->TunerParam.id = pDemod_globe->set_tv_para.id;
		pDemod_globe->m_pTuner->TunerParam.std = pDemod_globe->set_tv_para.std;
		pDemod_globe->m_pTuner->TunerParam.step_freq = pDemod_globe->set_tv_para.step_freq;
		pDemod_globe->m_pTuner->TunerParam.if_freq = pDemod_globe->set_tv_para.if_freq;
		pDemod_globe->m_pTuner->TunerParam.if_inversion = pDemod_globe->set_tv_para.if_inversion;
		pDemod_globe->m_pTuner->TunerParam.if_agc_pola = pDemod_globe->set_tv_para.if_agc_pola;
		pDemod_globe->m_pTuner->TunerParam.min_freq = pDemod_globe->set_tv_para.min_freq;
		pDemod_globe->m_pTuner->TunerParam.max_freq = pDemod_globe->set_tv_para.max_freq;
		pDemod_globe->m_pTuner->TunerParam.lowband_midband_limit_freq = pDemod_globe->set_tv_para.lowband_midband_limit_freq;
		pDemod_globe->m_pTuner->TunerParam.midband_highband_limit_freq = pDemod_globe->set_tv_para.midband_highband_limit_freq;
*/

		// IOCTL_RTK_DEMOD_SETTVSYSEX
		//DEMOD_MGR_DBG("realtek_demod rtk_demod_resume step 05 SetTVSysEx\n");
		//pDemod_globe->m_pDemod->SetTVSysEx(pDemod_globe->m_pDemod, pDemod_globe->set_tv_sys_ex_data.sys, NULL);

		// IOCTL_RTK_DEMOD_ACQUIRESIGNAL
		//DEMOD_MGR_DBG("realtek_demod rtk_demod_resume step 06 AcquireSignal 0\n");
		//pDemod_globe->m_pDemod->AcquireSignal(pDemod_globe->m_pDemod, 0);
		//DEMOD_MGR_DBG("realtek_demod rtk_demod_resume step 06 AcquireSignal 1\n");
		//pDemod_globe->m_pDemod->AcquireSignal(pDemod_globe->m_pDemod, 1);
	} else {
		DEMOD_MGR_INFO("realtek_demod last is ATV, ddmod no need init");
	}

	DEMOD_MGR_CALLER("realtek_demod rtk_demod_resume end\n");
	demod_suspend_done = 0;
	return 0;
}

static int rtk_demod_suspend_std(struct device *dev)
{
	DEMOD_MGR_CALLER(KERN_NOTICE "rtk_demod_suspend\n");
	if (isDemodConstructors == 1 && isUseDDemod == 1)
		pDemod_globe->m_pDemod->Suspend(pDemod_globe->m_pDemod);
	demod_suspend_done = 1;
	return 0;
}

static int rtk_demod_resume_std(struct device *dev)
{
	DEMOD_MGR_CALLER(KERN_NOTICE "rtk_demod_resume\n");
	demod_suspend_done = 0;
	return 0;
}
#endif

static int demod_major = RTKDEMOD_MAJOR;
static int demod_minor;

module_param(demod_major, int, S_IRUGO);
module_param(demod_minor, int, S_IRUGO);

static struct dev_pm_ops const rtk_demod_plat_pm_ops = {
	.suspend     = rtk_demod_suspend,
	.resume      = rtk_demod_resume,
	.freeze      = rtk_demod_suspend_std,
	.thaw        = rtk_demod_resume_std,
	.poweroff    = rtk_demod_suspend_std,
	.restore     = rtk_demod_resume_std,
};

static const char drv_name[] = DRV_NAME;

static struct class *rtk_demod_class;
static struct platform_device *rtk_demod_platform_devs;
static struct platform_driver  rtk_demod_device_driver
	= {
	.driver = {
		.name       = (char *)drv_name,
		.bus        = &platform_bus_type,
#ifdef CONFIG_PM
		.pm 	  = &rtk_demod_plat_pm_ops,
#endif
	},
};

struct device* get_rtkdemod_device_ptr(void)
{
	return &(rtk_demod_platform_devs->dev);
}

static int rtk_demod_open(struct inode *inode, struct file *filp)
{
	DEMOD_MGR_CALLER("func %s, line %d, NOT implemented!!, fp %x\n", __func__, __LINE__, (unsigned int)filp);
	return 0;
}

static int rtk_demod_release(struct inode *inode, struct file *filp)
{
	DEMOD_MGR_CALLER("func %s, line %d\n", __func__, __LINE__);

	if (filp == pDemod_globe->fpInit) {
		if (down_interruptible(&pDemod_globe->sem))
			return -ERESTARTSYS;


		up(&pDemod_globe->sem);
	}

	return 0;
}

static long rtk_demod_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret = -ENOTTY;

	//unsigned char m_addr_temp;
	//unsigned char *char_potint;

	TV_SIG_QUAL quality_temp;

	if (down_interruptible(&pDemod_globe->sem))
		return -ERESTARTSYS;

	down(&rtkdemod_Semaphore);
	switch (cmd) {
	case IOCTL_RTK_DEMOD_CONSTRUCTORS:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_CONSTRUCTORS\n");
		if (copy_from_user((void *)&pDemod_globe->demod_init_data, (const void __user *)arg, sizeof(RTK_DEMOD_CONSTRUCTORS))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: IOCTL_RTK_DEMOD_CONSTRUCTORS failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod demod_init_data.m_addr = %d(0x%x)\n", pDemod_globe->demod_init_data.m_addr, pDemod_globe->demod_init_data.m_addr);
			//DEMOD_MGR_DBG("realtek_demod demod_init_data.m_output_mode = %d(0x%x)\n", pDemod_globe->demod_init_data.m_output_mode, pDemod_globe->demod_init_data.m_output_mode);
			//DEMOD_MGR_DBG("realtek_demod demod_init_data.m_output_freq = %d(0x%x)\n", pDemod_globe->demod_init_data.m_output_freq, pDemod_globe->demod_init_data.m_output_freq);

			pDemod_globe->m_comm = kmalloc(sizeof(COMM), GFP_KERNEL);
			Comm_Constructors(pDemod_globe->m_comm, 0);
			pDemod_globe->m_pTuner = kmalloc(sizeof(TUNER), GFP_KERNEL);
			Tuner_Constructors(pDemod_globe->m_pTuner);
			pDemod_globe->m_pDemod = kmalloc(sizeof(DEMOD), GFP_KERNEL);
			REALTEK_ALL_Constructors(pDemod_globe->m_pDemod, pDemod_globe->demod_init_data.m_addr, pDemod_globe->demod_init_data.m_output_mode, pDemod_globe->demod_init_data.m_output_freq, pDemod_globe->m_comm);
			pDemod_globe->m_pDemod->AttachTuner(pDemod_globe->m_pDemod, pDemod_globe->m_pTuner);
			ret = 0;
			pDemod_globe->fpInit = filp;
			isDemodConstructors = 1;
		}
		break;

	case IOCTL_RTK_DEMOD_INIT:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_INIT\n");
		pDemod_globe->m_pDemod->Init(pDemod_globe->m_pDemod);
		ret = 0;
		break;


	case IOCTL_RTK_DEMOD_SETIF:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETIF\n");

		if (copy_from_user((void *)&pDemod_globe->set_if_data, (const void __user *)arg, sizeof(RTK_DEMOD_SETIF))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETIF failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_if_data.freq = %d\n", pDemod_globe->set_if_data.freq);
			//DEMOD_MGR_DBG("realtek_demod set_if_data.inversion = %d\n", pDemod_globe->set_if_data.inversion);
			//DEMOD_MGR_DBG("realtek_demod set_if_data.agc_pola = %d\n", pDemod_globe->set_if_data.agc_pola);

			pDemod_globe->m_pDemod->SetIF(pDemod_globe->m_pDemod, (IF_PARAM*) &pDemod_globe->set_if_data);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETTVMODE:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETTVMODE\n");
		isUseDDemod = 1;

		if (copy_from_user((void *)&pDemod_globe->set_tv_mode_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_TVMODE))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETTVMODE failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_tv_mode_data.mode = %d(0x%x)\n", pDemod_globe->set_tv_mode_data.mode, pDemod_globe->set_tv_mode_data.mode);

			pDemod_globe->m_pDemod->SetTvMode(pDemod_globe->m_pDemod, (TV_SYSTEM_TYPE)pDemod_globe->set_tv_mode_data.mode);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETTVSYS:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETTVSYS\n");
		isUseDDemod = 1;

		if (copy_from_user((void *)&pDemod_globe->set_tv_sys_ex_data, (const void __user *)arg, sizeof(RTK_DEMOD_SETTVSYSEX))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETTVSYSEX failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_tv_sys_ex_data.sys = %d\n", pDemod_globe->set_tv_sys_ex_data.sys);

			pDemod_globe->m_pDemod->SetTVSysEx(pDemod_globe->m_pDemod, pDemod_globe->set_tv_sys_ex_data.sys, NULL);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETTVSYSEX:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETTVSYSEX\n");
		isUseDDemod = 1;
		if (copy_from_user((void *)&pDemod_globe->set_tv_sys_ex_data, (const void __user *)arg, sizeof(RTK_DEMOD_SETTVSYSEX))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETTVSYSEX failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_tv_sys_ex_data.sys = %d\n", pDemod_globe->set_tv_sys_ex_data.sys);

			pDemod_globe->m_pDemod->SetTVSysEx(pDemod_globe->m_pDemod, pDemod_globe->set_tv_sys_ex_data.sys, &pDemod_globe->set_tv_sys_ex_data.pSigInfo);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_ACQUIRESIGNAL:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_ACQUIRESIGNAL\n");
		if (copy_from_user((void *)&pDemod_globe->set_acq_sig_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_ACQ_SIG))) {
			//ret = -EFAULT;
			ret = 0;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_ACQUIRESIGNAL failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_acq_sig_data.WaitSignalLock = %d\n", pDemod_globe->set_acq_sig_data.WaitSignalLock);

			pDemod_globe->set_acq_sig_data.return_value = pDemod_globe->m_pDemod->AcquireSignal(pDemod_globe->m_pDemod, pDemod_globe->set_acq_sig_data.WaitSignalLock);
			if (copy_to_user((void __user *)arg, &pDemod_globe->set_acq_sig_data, sizeof(RTK_DEMOD_SET_ACQ_SIG)))
				ret = 0;
			else
				ret = -EFAULT;
		}
		break;

	case IOCTL_RTK_DEMOD_UNINIT:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_UNINIT\n");
		ret = 0;
		break;

	case IOCTL_RTK_DEMOD_DESTRUCTORS:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_DESTRUCTORS\n");

		REALTEK_ALL_Destructors(pDemod_globe->m_pDemod);
		kfree(pDemod_globe->m_pDemod);
		pDemod_globe->m_pTuner->Destory(pDemod_globe->m_pTuner);
		kfree(pDemod_globe->m_pTuner);
		pDemod_globe->m_comm->Destory(pDemod_globe->m_comm);
		kfree(pDemod_globe->m_comm);
		isDemodConstructors = 0;
		ret = 0;
		break;

	case IOCTL_RTK_DEMOD_SETTSMODE:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETTSMODE\n");

		if (copy_from_user((void *)&pDemod_globe->set_ts_mode_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_TS_MODE))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETTSMODE failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.mode = %d\n", pDemod_globe->set_ts_mode_data.mode);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.data_order = %d\n", pDemod_globe->set_ts_mode_data.data_order);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.datapin = %d\n", pDemod_globe->set_ts_mode_data.datapin);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.err_pol = %d\n", pDemod_globe->set_ts_mode_data.err_pol);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.sync_pol = %d\n", pDemod_globe->set_ts_mode_data.sync_pol);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.val_pol = %d\n", pDemod_globe->set_ts_mode_data.val_pol);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.clk_pol = %d\n", pDemod_globe->set_ts_mode_data.clk_pol);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.internal_demod_input = %d\n", pDemod_globe->set_ts_mode_data.internal_demod_input);
			//DEMOD_MGR_DBG("realtek_demod set_ts_mode_data.strength_mode = %d\n", pDemod_globe->set_ts_mode_data.strength_mode);

			pDemod_globe->m_pDemod->SetTSMode(pDemod_globe->m_pDemod, (TS_PARAM*)&pDemod_globe->set_ts_mode_data);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_GETLOCK:
		pDemod_globe->m_pDemod->GetLockStatus(pDemod_globe->m_pDemod, &(pDemod_globe->get_lock_data.lock));
		ret = 0;

		if (copy_to_user((void __user *)arg, &pDemod_globe->get_lock_data, sizeof(RTK_DEMOD_GET_LOCK)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_GETLOCK\n");
		break;


	case IOCTL_RTK_DEMOD_GETCROFFSET:
		pDemod_globe->m_pDemod->GetCarrierOffset(pDemod_globe->m_pDemod, &(pDemod_globe->get_croffset_data.Offset));
		ret = 0;
		if (copy_to_user((void __user *)arg, &pDemod_globe->get_croffset_data, sizeof(RTK_DEMOD_GET_CROFFSET)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_GETCROFFSET\n");
		break;

	case IOCTL_RTK_DEMOD_GETCHANNELINFO:
		pDemod_globe->m_pDemod->GetChannelInfo(pDemod_globe->m_pDemod, &(pDemod_globe->get_channelinfo_data.Standard), &(pDemod_globe->get_channelinfo_data.Modulation), &(pDemod_globe->get_channelinfo_data.CodeRate), &(pDemod_globe->get_channelinfo_data.PilotOnOff), &(pDemod_globe->get_channelinfo_data.Inverse));
		ret = 0;
		if (copy_to_user((void __user *)arg, &pDemod_globe->get_channelinfo_data, sizeof(RTK_DEMOD_GET_CHANNELINFO)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_GETCHANNELINFO\n");
		break;

	case IOCTL_RTK_DEMOD_AUTO_TUNE:
		pDemod_globe->m_pDemod->AutoTune(pDemod_globe->m_pDemod);
		ret = 0;
		break;

	case IOCTL_RTK_DEMOD_SETMODE:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETMODE\n");

		if (copy_from_user((void *)&pDemod_globe->set_mode_data, (const void __user *)arg, sizeof(RTK_DEMOD_SETMODE))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETMODE failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_mode_data.mode = %d\n", pDemod_globe->set_mode_data.mode);

			pDemod_globe->m_pDemod->SetMode(pDemod_globe->m_pDemod, (TV_OP_MODE)pDemod_globe->set_mode_data.mode);
			ret = 0;
		}

		break;
	case IOCTL_RTK_DEMOD_SETTVPARA:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETTVPARA\n");

		if (copy_from_user((void *)&pDemod_globe->set_tv_para, (const void __user *)arg, sizeof(RTK_DEMOD_SET_TVPARA))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETTVPARA failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.id = %d\n", pDemod_globe->set_tv_para.id);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.std = %d\n", pDemod_globe->set_tv_para.std);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.step_freq = %d\n", pDemod_globe->set_tv_para.step_freq);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.if_freq = %d\n", pDemod_globe->set_tv_para.if_freq);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.if_inversion = %d\n", pDemod_globe->set_tv_para.if_inversion);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.if_agc_pola = %d\n", pDemod_globe->set_tv_para.if_agc_pola);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.min_freq= %d\n", pDemod_globe->set_tv_para.min_freq);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.max_freq = %d\n", pDemod_globe->set_tv_para.max_freq);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.lowband_midband_limit_freq = %d\n", pDemod_globe->set_tv_para.lowband_midband_limit_freq);
			//DEMOD_MGR_DBG("realtek_demod set_tv_para.midband_highband_limit_freq = %d\n", pDemod_globe->set_tv_para.midband_highband_limit_freq);

			pDemod_globe->m_pTuner->TunerParam.id = pDemod_globe->set_tv_para.id;
			pDemod_globe->m_pTuner->TunerParam.std = pDemod_globe->set_tv_para.std;
			pDemod_globe->m_pTuner->TunerParam.step_freq = pDemod_globe->set_tv_para.step_freq;
			pDemod_globe->m_pTuner->TunerParam.if_freq = pDemod_globe->set_tv_para.if_freq;
			pDemod_globe->m_pTuner->TunerParam.if_inversion = pDemod_globe->set_tv_para.if_inversion;
			pDemod_globe->m_pTuner->TunerParam.if_agc_pola = pDemod_globe->set_tv_para.if_agc_pola;
			pDemod_globe->m_pTuner->TunerParam.min_freq = pDemod_globe->set_tv_para.min_freq;
			pDemod_globe->m_pTuner->TunerParam.max_freq = pDemod_globe->set_tv_para.max_freq;
			pDemod_globe->m_pTuner->TunerParam.lowband_midband_limit_freq = pDemod_globe->set_tv_para.lowband_midband_limit_freq;
			pDemod_globe->m_pTuner->TunerParam.midband_highband_limit_freq = pDemod_globe->set_tv_para.midband_highband_limit_freq;
			ret = 0;
		}

		break;
	case IOCTL_RTK_DEMOD_GETQUALITY:
		if (copy_from_user((void *)&pDemod_globe->get_quality, (const void __user *)arg, sizeof(RTK_DEMOD_GET_QUALITY))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_GETQUALITY failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {

            quality_temp.rflevel= pDemod_globe->get_quality.pQuality.rflevel;
            //DEMOD_MGR_EMERG_FORCE("\033[1;32;31m""[KEN]quality_temp.rflevel = %d\n""\033[m", quality_temp.rflevel);
        
			pDemod_globe->m_pDemod->GetSignalQuality(pDemod_globe->m_pDemod, (ENUM_TV_QUAL)(pDemod_globe->get_quality.id), (TV_SIG_QUAL*)&quality_temp);

			switch (pDemod_globe->get_quality.id) {
			case TV_QUAL_NOSIG :
				pDemod_globe->get_quality.pQuality.nosig = quality_temp.nosig;
				break;

			case TV_QUAL_INNERLOCK :
				pDemod_globe->get_quality.pQuality.inner = quality_temp.inner;
				break;

			case TV_QUAL_SNR :
				pDemod_globe->get_quality.pQuality.snr = quality_temp.snr;

				break;
			case TV_QUAL_BEC :
			case TV_QUAL_BER : {
				if (pDemod_globe->get_quality.id == TV_QUAL_BER)
					pDemod_globe->get_quality.pQuality.ber = quality_temp.ber;
				if (pDemod_globe->get_quality.id  == TV_QUAL_BEC) {
					pDemod_globe->get_quality.pQuality.layer_ber.ber_num = quality_temp.layer_ber.ber_num;
					pDemod_globe->get_quality.pQuality.layer_ber.ber_den = quality_temp.layer_ber.ber_den;
				}

				break;
			}
			case TV_QUAL_PEC :
			case TV_QUAL_PER :
			case TV_QUAL_UCBLOCKS : {
				if (pDemod_globe->get_quality.id == TV_QUAL_PER)
					pDemod_globe->get_quality.pQuality.per = quality_temp.per;
				else if (pDemod_globe->get_quality.id == TV_QUAL_UCBLOCKS)
					pDemod_globe->get_quality.pQuality.layer_per.per_num = quality_temp.ucblocks;
				else if (pDemod_globe->get_quality.id == TV_QUAL_PEC) {
					pDemod_globe->get_quality.pQuality.layer_per.per_num = quality_temp.layer_per.per_num;
					pDemod_globe->get_quality.pQuality.layer_per.per_den = quality_temp.layer_per.per_den;
				}

				break;
			}

			case TV_QUAL_SIGNAL_STRENGTH:

               
				pDemod_globe->get_quality.pQuality.strength = quality_temp.strength;
				break;

			case TV_QUAL_SIGNAL_QUALITY:
				pDemod_globe->get_quality.pQuality.quality = quality_temp.quality;
				break;

			case TV_QUAL_AGC:
				pDemod_globe->get_quality.pQuality.agc = quality_temp.agc;
				break;
			case TV_QUAL_DEMODFWVERSION:
				pDemod_globe->get_quality.pQuality.DemodFwVersion = quality_temp.DemodFwVersion;
				break;

			case TV_QUAL_CUSTOMER_LG:
				pDemod_globe->get_quality.pQuality.strength = quality_temp.strength;
				pDemod_globe->get_quality.pQuality.quality = quality_temp.quality;
				pDemod_globe->get_quality.pQuality.layer_per.per_num = quality_temp.layer_per.per_num;
				pDemod_globe->get_quality.pQuality.layer_per.per_den = quality_temp.layer_per.per_den;
				pDemod_globe->get_quality.pQuality.layer_ber.ber_num = quality_temp.layer_ber.ber_num;
				pDemod_globe->get_quality.pQuality.layer_ber.ber_den = quality_temp.layer_ber.ber_den;
				pDemod_globe->get_quality.pQuality.agc = quality_temp.agc;
				pDemod_globe->get_quality.pQuality.snr = quality_temp.snr;
				break;

			default:
				ret = TUNER_CTRL_FAIL;
			}

			if (copy_to_user((void __user *)arg, &pDemod_globe->get_quality, sizeof(RTK_DEMOD_GET_QUALITY)))
				DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_GETQUALITY\n");
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_GET_DEMOD_INFO:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_GET_DEMOD_INFO\n");
		pDemod_globe->m_pDemod->GetDemodInfo(pDemod_globe->m_pDemod, (TV_DEMOD_INFO*)&pDemod_globe->get_demod_info_data);
		if (copy_to_user((void __user *)arg, &pDemod_globe->get_demod_info_data, sizeof(RTK_DEMOD_GET_DEMOD_INFO)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_GET_DEMOD_INFO\n");
		ret = 0;
		break;

	case IOCTL_RTK_DEMOD_GET_DEBUG_INFO:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_GET_DEBUG_INFO\n");
		if (copy_from_user((void *)&pDemod_globe->get_debug_info_data, (const void __user *)arg, sizeof(RTK_DEMOD_GET_DEBUG_INFO))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_GET_DEBUG_INFO failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->DebugInfo(pDemod_globe->m_pDemod, pDemod_globe->get_debug_info_data.debug_mode);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_GET_SIGNAL_INFO:
		pDemod_globe->m_pDemod->GetSignalInfo(pDemod_globe->m_pDemod, (TV_SIG_INFO*)&pDemod_globe->get_signal_info_data);
		if (copy_to_user((void __user *)arg, &pDemod_globe->get_signal_info_data, sizeof(RTK_DEMOD_GET_SIGNAL_INFO)))
			DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_GET_SIGNAL_INFO\n");
		ret = 0;
		break;
	case IOCTL_RTK_DEMOD_CHANGET2PLP:

		if (copy_from_user((void *)&pDemod_globe->get_signal_info_data, (const void __user *)arg, sizeof(RTK_DEMOD_GET_SIGNAL_INFO))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: IOCTL_RTK_DEMOD_CHANGET2PLP failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//DEMOD_MGR_DBG("realtek_demod set_tv_sys_ex_data.sys = %d\n", pDemod_globe->set_tv_sys_ex_data.sys);

			pDemod_globe->m_pDemod->ChangeT2PLP(pDemod_globe->m_pDemod, (TV_SIG_INFO*)&pDemod_globe->get_signal_info_data);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_GETT2PLPINFO:
		pDemod_globe->m_pDemod->GetT2PLPInfo(pDemod_globe->m_pDemod, (TV_SIG_INFO*)&pDemod_globe->get_signal_info_data);

		if (copy_to_user((void __user *)arg, &pDemod_globe->get_signal_info_data, sizeof(RTK_DEMOD_GET_SIGNAL_INFO)))
			DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_GETT2PLPINFO\n");
		ret = 0;
		break;

	case IOCTL_RTK_DEMOD_INSPECT_SIGNAL:
		pDemod_globe->m_pDemod->InspectSignal(pDemod_globe->m_pDemod);
		ret = 0;
		break;


	case IOCTL_RTK_DEMOD_SETDISEQC_22K:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETDISEQC_22K\n");
		if (copy_from_user((void *)&pDemod_globe->set_diseqc_22k_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_DISEQC_22K))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETDISEQC_22K failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->SetDiseqcContinue22kOnOff(pDemod_globe->m_pDemod, pDemod_globe->set_diseqc_22k_data.onoff);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETDISEQC_CMD:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETDISEQC_CMD\n");
		if (copy_from_user((void *)&pDemod_globe->set_diseqc_cmd_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_DISEQC_CMD))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETDISEQC_CMD failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->SetDiseqcCmd(pDemod_globe->m_pDemod, pDemod_globe->set_diseqc_cmd_data.length, pDemod_globe->set_diseqc_cmd_data.data);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETDISEQC_BURST:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_SETDISEQC_BURST\n");
		if (copy_from_user((void *)&pDemod_globe->set_diseqc_toneburst_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_DISEQC_TONEBURST))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETDISEQC_BURST failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->SetDiseqcToneBurst(pDemod_globe->m_pDemod, pDemod_globe->set_diseqc_toneburst_data.mode);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_GETREGCMD:
		if (copy_from_user((void *)&pDemod_globe->get_reg_data, (const void __user *)arg, sizeof(RTK_DEMOD_GET_REG_DATA))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_GETREGCMD failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->GetRegCmd(pDemod_globe->m_pDemod, pDemod_globe->get_reg_data.RegAddr, &(pDemod_globe->get_reg_data.RegValue));
			if (copy_to_user((void __user *)arg, &pDemod_globe->get_reg_data, sizeof(RTK_DEMOD_GET_REG_DATA)))
				DEMOD_MGR_DBG("[realtek_demod] IOCTL_RTK_DEMOD_GETGEGCMD\n");
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETREGCMD:
		if (copy_from_user((void *)&pDemod_globe->set_reg_data, (const void __user *)arg, sizeof(RTK_DEMOD_SET_REG_DATA))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETREGCMD failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->SetRegCmd(pDemod_globe->m_pDemod, pDemod_globe->set_reg_data.RegAddr, pDemod_globe->set_reg_data.RegValue);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_SETTUNER_INPUT_MODE:
		if (copy_from_user((void *)&pDemod_globe->set_tuner_input, (const void __user *)arg, sizeof(RTK_DEMOD_SET_TUNER_INPUT))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_SETTUNER_INPUT_MODE failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->SetTunerInputMode(pDemod_globe->m_pDemod, pDemod_globe->set_tuner_input.Mode);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_INIT:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_INIT\n");
		if (copy_from_user((void *)&pDemod_globe->blindscan_init_data, (const void __user *)arg, sizeof(RTK_DEMOD_BLINDSCAN_INIT))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_BLINDSCAN_INIT failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pDemod_globe->m_pDemod->BlindScan_Init(pDemod_globe->m_pDemod, pDemod_globe->blindscan_init_data.StartFreqMhz, pDemod_globe->blindscan_init_data.EndFreqMhz);
			ret = 0;
		}
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_NEXTFREQ:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_NEXTFREQ\n");
		pDemod_globe->m_pDemod->BlindScan_NextFreq(pDemod_globe->m_pDemod, &(pDemod_globe->blindscan_nextfreq_data.bBlindScanEnd));
		ret = 0;
		if (copy_to_user((void __user *)arg, &pDemod_globe->blindscan_nextfreq_data, sizeof(RTK_DEMOD_BLINDSCAN_NEXTFREQ)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_NEXTFREQ\n");
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_GETTUNERFREQ:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_GETTUNERFREQ\n");
		pDemod_globe->m_pDemod->BlindScan_GetTunerFreq(pDemod_globe->m_pDemod, &(pDemod_globe->blindscan_get_tunerfreq_data.TunerCenterFreqMhz), &(pDemod_globe->blindscan_get_tunerfreq_data.TunerCutOffFreqKhz));
		ret = 0;
		if (copy_to_user((void __user *)arg, &pDemod_globe->blindscan_get_tunerfreq_data, sizeof(RTK_DEMOD_BLINDSCAN_GET_TUNERFREQ)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_GETTUNERFREQ\n");
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_END:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_END\n");
		pDemod_globe->m_pDemod->BlindScan_End(pDemod_globe->m_pDemod);
		ret = 0;
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_GETFOUNDTP:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_GETFOUNDTP\n");
		pDemod_globe->m_pDemod->BlindScan_GetFoundTP(pDemod_globe->m_pDemod, &(pDemod_globe->blindscan_get_foundtp_data.FreqMhz), &(pDemod_globe->blindscan_get_foundtp_data.SymbolRateKhz));
		ret = 0;
		if (copy_to_user((void __user *)arg, &pDemod_globe->blindscan_get_foundtp_data, sizeof(RTK_DEMOD_BLINDSCAN_GET_FOUNDTP)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_GETFOUNDTP\n");
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_GETSTATUS:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_GETSTATUS\n");
		pDemod_globe->m_pDemod->BlindScan_GetStatus(pDemod_globe->m_pDemod, &(pDemod_globe->blindscan_get_status_data.Status), &(pDemod_globe->blindscan_get_status_data.bBlindScanLock));
		ret = 0;
		if (copy_to_user((void __user *)arg, &pDemod_globe->blindscan_get_status_data, sizeof(RTK_DEMOD_BLINDSCAN_GET_STATUS)))
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_GETSTATUS\n");
		break;

	case IOCTL_RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL:
		//DEMOD_MGR_CALLER("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL\n");
		if (copy_from_user((void *)&pDemod_globe->blindscan_acquire_signal_data, (const void __user *)arg, sizeof(RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL))) {
			ret = -EFAULT;
			DEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			//memcpy(&pDemod_globe->blindscan_acquire_signal_data, &blindscan_acquire_signal_data, sizeof(RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL));
			pDemod_globe->m_pDemod->BlindScan_AcquireSignal(pDemod_globe->m_pDemod, &(pDemod_globe->blindscan_acquire_signal_data.SymbolRate), &(pDemod_globe->blindscan_acquire_signal_data.Fcfo), &(pDemod_globe->blindscan_acquire_signal_data.bTpLock));
			ret = 0;
			if (copy_to_user((void __user *)arg, &pDemod_globe->blindscan_acquire_signal_data, sizeof(RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL)))
				DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_DEMOD_BLINDSCAN_ACQUIRE_SIGNAL\n");
		}
		break;

	default:
		DEMOD_MGR_WARNING("RTKDEMOD[%d]: unknown ioctl(0x%08x)\n", __LINE__, cmd);
		break;
	}
	up(&rtkdemod_Semaphore);
	up(&pDemod_globe->sem);
	return ret;
}

unsigned int rtk_demod_poll(struct file *filp, poll_table *wait)
{
	if (pDemod_globe->filter_flag > 0) {
		pDemod_globe->filter_flag = 0;
		return POLLIN | POLLRDNORM;
	} else {
		return 0;
	}
}

struct file_operations demod_fops = {
	.owner              = THIS_MODULE,
	.unlocked_ioctl     = rtk_demod_ioctl,
	.open               = rtk_demod_open,
	.release            = rtk_demod_release,
	.poll               = rtk_demod_poll,
};

static char *rtk_demod_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

static void rtk_demod_exit(void)
{

	dev_t dev = MKDEV(demod_major, demod_minor);

	if (rtk_demod_platform_devs == NULL)
		BUG();

	device_destroy(rtk_demod_class, dev);
	cdev_del(&pDemod_globe->cdev);
	platform_driver_unregister(&rtk_demod_device_driver);
	platform_device_unregister(rtk_demod_platform_devs);
	kfree(pDemod_globe);
	rtk_demod_platform_devs = NULL;
	class_destroy(rtk_demod_class);
	rtk_demod_class = NULL;
	unregister_chrdev_region(dev, 1);
}

static const struct file_operations demod_proc_fops =
{
	.owner = THIS_MODULE,
	.write  = demod_proc_write,
	.read  = demod_proc_read,
};

static int __init rtk_demod_init(void)
{
	int result;
	dev_t dev = 0;

	/*	DEMOD_MGR_CALLER("\n\n\n\n *****************	  demod init module  %s*********************\n\n\n\n", __TIME__); // fix compile error */
	DEMOD_MGR_CALLER("\n\n\n\n *****************	  demod init module  *********************\n\n\n\n");

	if (demod_major) {
		dev = MKDEV(RTKDEMOD_MAJOR, 0);
		result = register_chrdev_region(dev, 1, DRV_NAME);
	} else {
		result = alloc_chrdev_region(&dev, demod_minor, 1, DRV_NAME);
		demod_major = MAJOR(dev);
	}

	if (result < 0) {
		DEMOD_MGR_WARNING("demod: can not get chrdev region...\n");
		return result;
	}

	rtk_demod_class = class_create(THIS_MODULE, DRV_NAME);
	if (IS_ERR(rtk_demod_class)) {
		DEMOD_MGR_WARNING("demod: can not create class...\n");
		result = PTR_ERR(rtk_demod_class);
		goto fail_class_create;
	}

	rtk_demod_class->devnode = rtk_demod_devnode;
	pDemod_globe = kmalloc(sizeof(SRTK_DEMOD_DATA), GFP_KERNEL);
	if (!pDemod_globe) {
		rtk_demod_exit();
		return -ENOMEM;
	}

	rtk_demod_platform_devs = platform_device_register_simple(DRV_NAME, -1, NULL, 0);
	if (platform_driver_register(&rtk_demod_device_driver) != 0) {
		DEMOD_MGR_WARNING("demod: can not register platform driver...\n");
		result = -EINVAL;
		goto fail_platform_driver_register;
	}

	memset(pDemod_globe, 0, sizeof(SRTK_DEMOD_DATA));
	cdev_init(&pDemod_globe->cdev, &demod_fops);
	pDemod_globe->cdev.owner = THIS_MODULE;
	pDemod_globe->cdev.ops   = &demod_fops;
	if (cdev_add(&pDemod_globe->cdev, dev, 1) < 0) {
		DEMOD_MGR_WARNING("demod: can not add character device...\n");
		goto fail_cdev_init;
	}

	device_create(rtk_demod_class, NULL, dev, NULL, DRV_NAME);
	sema_init	(&rtkdemod_Semaphore, 1);
	sema_init(&pDemod_globe->sem, 1);

	/* [[KTASKWBS-1065] Make demod resume run at asynchronous for parallel resume time*/
	device_enable_async_suspend(get_rtkdemod_device_ptr());

#ifdef CONFIG_PROC_FS
	/* add proc entry */
	if((demod_proc_dir == NULL) && (demod_proc_entry == NULL))
	{
		demod_proc_dir = proc_mkdir(DEMOD_PROC_DIR , NULL);

		if (demod_proc_dir == NULL)
		{
			DEMOD_MGR_WARNING("create rhal_tp dir proc entry (%s) failed\n", DEMOD_PROC_DIR);
		}
		else
		{
			demod_proc_entry = proc_create(DEMOD_PROC_ENTRY, 0666, demod_proc_dir, &demod_proc_fops);
			if(demod_proc_entry == NULL)
			{
				DEMOD_MGR_WARNING("failed to get proc entry for %s/%s \n", DEMOD_PROC_DIR, DEMOD_PROC_ENTRY);
			}
		}
	}
#else
	DEMOD_MGR_WARNING("This module requests the kernel to support procfs,need set CONFIG_PROC_FS configure Y\n");
#endif

	return 0;

fail_cdev_init:
	platform_driver_unregister(&rtk_demod_device_driver);
fail_platform_driver_register:
	platform_device_unregister(rtk_demod_platform_devs);
	rtk_demod_platform_devs = NULL;
	class_destroy(rtk_demod_class);
fail_class_create:
	rtk_demod_class = NULL;
	unregister_chrdev_region(dev, 1);
	return result;
}

int rtk_demod_get_debugbuf(unsigned int *buf_addr, unsigned int *buf_size)
{
	int ret = -ENOTTY;
	unsigned int buf_addr_get = 0, buf_size_get = 0, buf_type = 0;

	if (pDemod_globe->m_pDemod != NULL) {

#ifdef CONFIG_PROC_FS
		proc_remove(demod_proc_entry);
		demod_proc_entry = NULL;

		proc_remove(demod_proc_dir);
		demod_proc_dir = NULL;
#endif

		pDemod_globe->m_pDemod->GetDebugLogBuf(pDemod_globe->m_pDemod, &buf_addr_get, &buf_size_get);
		buf_type = (buf_addr_get & 0xC0000000) >> 30;
		buf_addr_get = (buf_addr_get & 0x3FFFFFFF) + DEMOD_MEM_START_PHYS;
		if (((buf_addr_get < DEMOD_MEM_START_PHYS) || (buf_addr_get > DEMOD_MEM_END_PHYS)) && (buf_type == 1)) {
			*buf_addr = 0;
			*buf_size = 0;//uncorrect, so clear
		} else {
			*buf_addr = phys_to_virt(buf_addr_get);
			*buf_size = buf_size_get;
		}
		ret = 0;
		printk("demod debugbuf, type=%d, addr=0x%x, size=0x%x\n", buf_type, *buf_addr, *buf_size);
	}

	return ret;
}

module_init(rtk_demod_init);
module_exit(rtk_demod_exit);

MODULE_LICENSE("GPL");
