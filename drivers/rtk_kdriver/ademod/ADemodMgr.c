#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/poll.h>


//#include "ademodcore/comm.h"
#include "tuner.h"
#include "ademod.h"
#include "demod_rtk_atv.h"

#include "ADemodMgr.h"

#define RTKADEMOD_MAJOR  0
#define DRV_NAME "rtkademod"

PS_RTK_ADEMOD_DATA pADemod_globe;

extern struct semaphore rtkdemod_Semaphore;/* This Semaphore is for rtkdemo control*/

static unsigned char isConstructors = 0;
static unsigned char isSTR = 0;
extern unsigned char isUseDDemod; 

unsigned char Scaler_AVD_GetAvdSource(void);

// From source.h
enum _SRC_TYPE {
	_SRC_TV = 0x01,
	_SRC_VO,
	_SRC_CVBS,
	_SRC_SV,
	_SRC_COMPONENT,
	_SRC_SCART,
	_SRC_SCART_RGB,
	_SRC_HDMI,
	_SRC_DVI,
	_SRC_VGA,
	_SRC_YPBPR,
	_SRC_PVR,
	_SRC_VIDEO8,
	_SRC_USB,
	_SRC_WIFI,
	_SRC_DISPLAYPORT,
	_SRC_OSD,

#ifdef CONFIG_INPUT_SOURCE_IPG
	_SRC_IPG,
#endif

	_SRC_MAX,	// don't change this order
};


#ifdef CONFIG_PM
static int rtk_ademod_suspend(struct device *dev)
{
	ADEMOD_MGR_CALLER("realtek_ademod rtk_ademod_suspend begin\n");
	ADEMOD_MGR_INFO("DemodSeclect: %d\n", isUseDDemod);
	ADEMOD_MGR_CALLER("realtek_ademod rtk_ademod_suspend end\n");
	isSTR = 0;
	return 0;
}

static int rtk_ademod_resume(struct device *dev)
{
	ADEMOD_MGR_CALLER("realtek_ademod rtk_ademod_resume begin\n");

	if (isConstructors == 1 && isUseDDemod == 0) {
		// IOCTL_RTK_ADEMOD_SETTVPARA
		pADemod_globe->m_pTuner->TunerParam.id = pADemod_globe->set_tv_para.id;
		pADemod_globe->m_pTuner->TunerParam.std = pADemod_globe->set_tv_para.std;
		pADemod_globe->m_pTuner->TunerParam.step_freq = pADemod_globe->set_tv_para.step_freq;
		pADemod_globe->m_pTuner->TunerParam.if_freq = pADemod_globe->set_tv_para.if_freq;
		pADemod_globe->m_pTuner->TunerParam.if_inversion = pADemod_globe->set_tv_para.if_inversion;
		pADemod_globe->m_pTuner->TunerParam.if_agc_pola = pADemod_globe->set_tv_para.if_agc_pola;
		pADemod_globe->m_pTuner->TunerParam.min_freq = pADemod_globe->set_tv_para.min_freq;
		pADemod_globe->m_pTuner->TunerParam.max_freq = pADemod_globe->set_tv_para.max_freq;
		pADemod_globe->m_pTuner->TunerParam.lowband_midband_limit_freq = pADemod_globe->set_tv_para.lowband_midband_limit_freq;
		pADemod_globe->m_pTuner->TunerParam.midband_highband_limit_freq = pADemod_globe->set_tv_para.midband_highband_limit_freq;

		// IOCTL_RTK_ADEMOD_INIT
		pADemod_globe->m_pADemod->Init(pADemod_globe->m_pADemod);
	} else {
		if (isConstructors == 1) {
			ADEMOD_MGR_INFO("realtek_ademod last is DTV, admod no need init");
		} else {
			ADEMOD_MGR_INFO("realtek_ademod No Use, admod no need init");
		}
	}
	ADEMOD_MGR_CALLER("realtek_ademod rtk_ademod_resume end\n");
	isSTR = 1;
	return 0;
}

static int rtk_ademod_suspend_std(struct device *dev)
{
	ADEMOD_MGR_CALLER(KERN_NOTICE "realtek_ademod rtk_ademod_suspend\n");
	return 0;
}

static int rtk_ademod_resume_std(struct device *dev)
{
	ADEMOD_MGR_CALLER(KERN_NOTICE "realtek_ademod rtk_ademod_resume\n");
	return 0;
}
#endif

static int ademod_major = RTKADEMOD_MAJOR;
static int ademod_minor;

module_param(ademod_major, int, S_IRUGO);
module_param(ademod_minor, int, S_IRUGO);

static struct dev_pm_ops const rtk_ademod_plat_pm_ops = {
	.suspend     = rtk_ademod_suspend,
	.resume      = rtk_ademod_resume,
	.freeze      = rtk_ademod_suspend_std,
	.thaw        = rtk_ademod_resume_std,
	.poweroff    = rtk_ademod_suspend_std,
	.restore     = rtk_ademod_resume_std,
};

static const char drv_name[] = DRV_NAME;

static struct class *rtk_ademod_class;
static struct platform_device *rtk_ademod_platform_devs;
static struct platform_driver  rtk_ademod_device_driver
	= {
	.driver = {
		.name       = (char *)drv_name,
		.bus        = &platform_bus_type,
#ifdef CONFIG_PM
		.pm 	  = &rtk_ademod_plat_pm_ops,
#endif
	},
};

static int rtk_ademod_open(struct inode *inode, struct file *filp)
{
	ADEMOD_MGR_CALLER("func %s, line %d, NOT implemented!!, fp %x\n", __func__, __LINE__, (unsigned int)filp);
	return 0;
}

static int rtk_ademod_release(struct inode *inode, struct file *filp)
{
	ADEMOD_MGR_CALLER("func %s, line %d\n", __func__, __LINE__);

	if (filp == pADemod_globe->fpInit) {
		if (down_interruptible(&pADemod_globe->sem))
			return -ERESTARTSYS;


		up(&pADemod_globe->sem);
	}

	return 0;
}

long rtk_ademod_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret = -ENOTTY;

	RTK_ADEMOD_CONSTRUCTORS ademod_init_data;
	RTK_ADEMOD_SETTVSYSEX *p_set_tv_sys_ex_data;
	//RTK_ADEMOD_SETIF set_if_data;
	RTK_ADEMOD_SETMODE set_mode_data;
	//RTK_ADEMOD_SET_TS_MODE set_ts_mode_data;
	RTK_ADEMOD_SET_TVMODE set_tv_mode_data;
	RTK_ADEMOD_SET_ACQ_SIG set_acq_sig_data;
	RTK_ADEMOD_GET_LOCK get_lock_data;
	RTK_ADEMOD_SET_TVPARA set_tv_para;
	RTK_ADEMOD_GET_QUALITY get_quality;
	RTK_ADEMOD_GET_CARRIEROFFSET get_carrier_offset;

	TV_SIG_QUAL quality_temp;

	//initialize
	set_acq_sig_data.lock = 0;
	set_acq_sig_data.WaitSignalLock = 1;
    get_quality.id = 0;

	if (down_interruptible(&pADemod_globe->sem))
		return -ERESTARTSYS;
	
	down(&rtkdemod_Semaphore);
	switch (cmd) {
	case IOCTL_RTK_ADEMOD_CONSTRUCTORS:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_CONSTRUCTORS\n");
			if (copy_from_user((void *)&ademod_init_data, (const void __user *)arg, sizeof(RTK_ADEMOD_CONSTRUCTORS))) {
				ret = -EFAULT;
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: IOCTL_RTK_ADEMOD_CONSTRUCTORS failed !!!!!!!!!!!!!!!\n", __LINE__);
			} else {
				//ADEMOD_MGR_DBG("realtek_ademod ademod_init_data.m_addr = %d(0x%x)\n", ademod_init_data.m_addr, ademod_init_data.m_addr);
				//ADEMOD_MGR_DBG("realtek_ademod ademod_init_data.m_output_freq = %d(0x%x)\n", ademod_init_data.m_output_freq, ademod_init_data.m_output_freq);
				//ADEMOD_MGR_DBG("realtek_ademod ademod_init_data.m_output_mode = %d(0x%x)\n", ademod_init_data.m_output_mode, ademod_init_data.m_output_mode);

				memcpy(&pADemod_globe->ademod_init_data, &ademod_init_data, sizeof(RTK_ADEMOD_CONSTRUCTORS));
				pADemod_globe->m_pTuner = kmalloc(sizeof(TUNER), GFP_KERNEL);
				Tuner_Constructors(pADemod_globe->m_pTuner);
				pADemod_globe->m_pADemod = kmalloc(sizeof(ADEMOD), GFP_KERNEL);
				REALTEK_ATV_Constructors(pADemod_globe->m_pADemod);
				pADemod_globe->m_pADemod->AttachTuner(pADemod_globe->m_pADemod, pADemod_globe->m_pTuner);
				ret = 0;
				pADemod_globe->fpInit = filp;
				isConstructors = 1;
			}
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_CONSTRUCTORS ,No need to do something in CVBS Mode\n");
			ret = 0;
		}
		break;

	case IOCTL_RTK_ADEMOD_INIT:
		ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_INIT\n");
		pADemod_globe->m_pADemod->Init(pADemod_globe->m_pADemod);
		ret = 0;
		isSTR = 0;
		break;
#if 0
	case IOCTL_RTK_ADEMOD_SETIF:
		if (copy_from_user((void *)&set_if_data, (const void __user *)arg, sizeof(RTK_ADEMOD_SETIF))) {
			ret = -EFAULT;
			ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_SETIF failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pADemod_globe->m_pADemod->SetIF(pADemod_globe->m_pADemod, (IF_PARAM*) &set_if_data);
			ret = 0;
		}
		break;
#endif
	case IOCTL_RTK_ADEMOD_SETTVMODE:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_SETTVMODE\n");
			isUseDDemod = 0 ;
			if (copy_from_user((void *)&set_tv_mode_data, (const void __user *)arg, sizeof(RTK_ADEMOD_SET_TVMODE))) {
				ret = -EFAULT;
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_SETTVMODE failed !!!!!!!!!!!!!!!\n", __LINE__);
			} else {
				//ADEMOD_MGR_DBG("realtek_ademod set_tv_mode_data.mode = %d(0x%x)\n", set_tv_mode_data.mode, set_tv_mode_data.mode);

				memcpy(&pADemod_globe->set_tv_mode_data, &set_tv_mode_data, sizeof(RTK_ADEMOD_SET_TVMODE));
				pADemod_globe->m_pADemod->SetTvMode(pADemod_globe->m_pADemod, (TV_SYSTEM_TYPE)set_tv_mode_data.mode);
				ret = 0;
			}
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_SETTVMODE ,No need to do something in CVBS Mode\n");
			ret = 0;
		}
		break;

	case IOCTL_RTK_ADEMOD_SETTVSYSEX:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_SETTVSYSEX\n");
			isUseDDemod = 0 ;

			p_set_tv_sys_ex_data = kmalloc(sizeof(RTK_ADEMOD_SETTVSYSEX), GFP_KERNEL);

			if (p_set_tv_sys_ex_data != NULL) {
				if (copy_from_user((void *)p_set_tv_sys_ex_data, (const void __user *)arg, sizeof(RTK_ADEMOD_SETTVSYSEX))) {
					ret = -EFAULT;
					//ADEMOD_MGR_DBG("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_SETTVSYSEX failed !!!!!!!!!!!!!!!\n", __LINE__);
				} else {
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_sys_ex_data.sys = %d(0x%x)\n", set_tv_sys_ex_data.sys, set_tv_sys_ex_data.sys);

					memcpy(&pADemod_globe->set_tv_sys_ex_data, p_set_tv_sys_ex_data, sizeof(RTK_ADEMOD_SETTVSYSEX));
					pADemod_globe->m_pADemod->SetTVSysEx(pADemod_globe->m_pADemod, p_set_tv_sys_ex_data->sys, &p_set_tv_sys_ex_data->sig_info);
					ret = 0;
				}
				kfree(p_set_tv_sys_ex_data);
			}
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_SETTVSYSEX ,No need to do something in CVBS Mode\n");
			ret = 0;
		}
		break;

	case IOCTL_RTK_ADEMOD_ACQUIRESIGNAL:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_ACQUIRESIGNAL\n");
			if (copy_from_user((void *)&set_acq_sig_data, (const void __user *)arg, sizeof(RTK_ADEMOD_SET_ACQ_SIG))) {
				ret = -EFAULT;
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_ACQUIRESIGNAL failed !!!!!!!!!!!!!!!\n", __LINE__);
			} else {
				//ADEMOD_MGR_DBG("realtek_ademod set_acq_sig_data.WaitSignalLock = %d(0x%x)\n", set_acq_sig_data.WaitSignalLock, set_acq_sig_data.WaitSignalLock);

				memcpy(&pADemod_globe->set_acq_sig_data, &set_acq_sig_data, sizeof(RTK_ADEMOD_SET_ACQ_SIG));
				set_acq_sig_data.lock = pADemod_globe->m_pADemod->AcquireSignal(pADemod_globe->m_pADemod, set_acq_sig_data.WaitSignalLock);
				if (copy_to_user((void __user *)arg, &set_acq_sig_data, sizeof(RTK_ADEMOD_SET_ACQ_SIG)))
					ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_ACQUIRESIGNAL failed !!!!!!!!!!!!!!!\n", __LINE__);
				ret = 0;
			}
		} else {
			memcpy(&pADemod_globe->set_acq_sig_data, &set_acq_sig_data, sizeof(RTK_ADEMOD_SET_ACQ_SIG));
			set_acq_sig_data.lock = TUNER_CTRL_OK;
			if (copy_to_user((void __user *)arg, &set_acq_sig_data, sizeof(RTK_ADEMOD_SET_ACQ_SIG)))
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_ACQUIRESIGNAL failed !!!!!!!!!!!!!!!\n", __LINE__);
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_ACQUIRESIGNAL ,No need to do something in CVBS Mode\n");
			ret = 0;
		}
		break;

	case IOCTL_RTK_ADEMOD_UNINIT:
		//ADEMOD_MGR_CALLER("[realtek_ademod] IOCTL_RTK_ADEMOD_UNINIT\n");
		ret = 0;
		break;

	case IOCTL_RTK_ADEMOD_DESTRUCTORS:
		//ADEMOD_MGR_CALLER("[realtek_ademod] IOCTL_RTK_ADEMOD_DESTRUCTORS\n");
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_DESTRUCTORS\n");
			pADemod_globe->m_pADemod->Destory(pADemod_globe->m_pADemod);
			kfree(pADemod_globe->m_pADemod);
			pADemod_globe->m_pTuner->Destory(pADemod_globe->m_pTuner);
			kfree(pADemod_globe->m_pTuner);
			isConstructors = 0;
			ret = 0;
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_DESTRUCTORS ,No need to do something in CVBS Mode\n");
			ret = 0;
		}
		break;
#if 0
	case IOCTL_RTK_ADEMOD_SETTSMODE:
		if (copy_from_user((void *)&set_ts_mode_data, (const void __user *)arg, sizeof(RTK_ADEMOD_SET_TS_MODE))) {
			ret = -EFAULT;
			ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_SETTSMODE failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			pADemod_globe->m_pADemod->SetTSMode(pADemod_globe->m_pADemod, (TS_PARAM*)&set_ts_mode_data);
			ret = 0;
		}
		break;
#endif
	case IOCTL_RTK_ADEMOD_GETLOCK:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_GETLOCK\n");
			pADemod_globe->m_pADemod->GetLockStatus(pADemod_globe->m_pADemod, &(get_lock_data.lock));
			ret = 0;
			if (copy_to_user((void __user *)arg, &get_lock_data, sizeof(RTK_ADEMOD_GET_LOCK)))
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETLOCK failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_GETLOCK ,No need to do something in CVBS Mode\n");
			get_lock_data.lock = TUNER_CTRL_OK;
			if (copy_to_user((void __user *)arg, &get_lock_data, sizeof(RTK_ADEMOD_GET_LOCK)))
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETLOCK failed !!!!!!!!!!!!!!!\n", __LINE__);
			ret = 0;
		}
		break;

#if 0
	case IOCTL_RTK_ADEMOD_AUTO_TUNE:
		if (isConstructors)
			pADemod_globe->m_pADemod->AutoTune(pADemod_globe->m_pADemod);
		else {
			DEMOD_MGR_INFO("[realtek_demod] IOCTL_RTK_ADEMOD_AUTO_TUNE isConstructors = 0\n");
		}
		ret = 0;
		break;
#endif
	case IOCTL_RTK_ADEMOD_SETMODE:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_SETMODE\n");
			if (copy_from_user((void *)&set_mode_data, (const void __user *)arg, sizeof(RTK_ADEMOD_SETMODE))) {
				ret = -EFAULT;
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_SETMODE failed !!!!!!!!!!!!!!!\n", __LINE__);
			} else {
				//ADEMOD_MGR_DBG("realtek_ademod set_mode_data.mode = %d(0x%x)\n", set_mode_data.mode, set_mode_data.mode);

				memcpy(&pADemod_globe->set_mode_data, &set_mode_data, sizeof(RTK_ADEMOD_SETMODE));
				pADemod_globe->m_pADemod->SetMode(pADemod_globe->m_pADemod, (TV_OP_MODE)set_mode_data.mode);
				ret = 0;
			}
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_SETMODE ,No need to do something in CVBS Mode\n");
			ret = 0;
		}

		break;
	case IOCTL_RTK_ADEMOD_SETTVPARA:
		//if( _SRC_CVBS != Scaler_AVD_GetAvdSource() )
		if (1) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_SETTVPARA\n");
			if (isConstructors==0) {
				ADEMOD_MGR_WARNING("[ADemod][IOCTL][SETTVPARA] Constructor Not Yet\n");
				ret = 0;
			} else {
				if (copy_from_user((void *)&set_tv_para, (const void __user *)arg, sizeof(RTK_ADEMOD_SET_TVPARA))) {
					ret = -EFAULT;
					ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_SETTVPARA failed !!!!!!!!!!!!!!!\n", __LINE__);
				} else {
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.id = %d(0x%x)\n", set_tv_para.id, set_tv_para.id);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.std = %d(0x%x)\n", set_tv_para.std, set_tv_para.std);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.step_freq = %d(0x%x)\n", set_tv_para.step_freq, set_tv_para.step_freq);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.if_freq = %d(0x%x)\n", set_tv_para.if_freq, set_tv_para.if_freq);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.if_inversion = %d(0x%x)\n", set_tv_para.if_inversion, set_tv_para.if_inversion);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.if_agc_pola = %d(0x%x)\n", set_tv_para.if_agc_pola, set_tv_para.if_agc_pola);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.min_freq = %d(0x%x)\n", set_tv_para.min_freq, set_tv_para.min_freq);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.max_freq = %d(0x%x)\n", set_tv_para.max_freq, set_tv_para.max_freq);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.lowband_midband_limit_freq = %d(0x%x)\n", set_tv_para.lowband_midband_limit_freq, set_tv_para.lowband_midband_limit_freq);
					//ADEMOD_MGR_DBG("realtek_ademod set_tv_para.midband_highband_limit_freq = %d(0x%x)\n", set_tv_para.midband_highband_limit_freq, set_tv_para.midband_highband_limit_freq);

					memcpy(&pADemod_globe->set_tv_para, &set_tv_para, sizeof(RTK_ADEMOD_SET_TVPARA));

					pADemod_globe->m_pTuner->TunerParam.id = set_tv_para.id;
					pADemod_globe->m_pTuner->TunerParam.std = set_tv_para.std;
					pADemod_globe->m_pTuner->TunerParam.step_freq = set_tv_para.step_freq;
					pADemod_globe->m_pTuner->TunerParam.if_freq = set_tv_para.if_freq;
					pADemod_globe->m_pTuner->TunerParam.if_inversion = set_tv_para.if_inversion;
					pADemod_globe->m_pTuner->TunerParam.if_agc_pola = set_tv_para.if_agc_pola;
					pADemod_globe->m_pTuner->TunerParam.min_freq = set_tv_para.min_freq;
					pADemod_globe->m_pTuner->TunerParam.max_freq = set_tv_para.max_freq;
					pADemod_globe->m_pTuner->TunerParam.lowband_midband_limit_freq = set_tv_para.lowband_midband_limit_freq;
					pADemod_globe->m_pTuner->TunerParam.midband_highband_limit_freq = set_tv_para.midband_highband_limit_freq;
					ret = 0;
				}
			}
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_SETTVPARA ,No need to do something in CVBS Mode\n");
			ret = 0;
		}

		break;

	case IOCTL_RTK_ADEMOD_GETQUALITY:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_GETQUALITY\n");
			if (copy_from_user((void *)&get_quality, (const void __user *)arg, sizeof(RTK_ADEMOD_GET_QUALITY))) {
				ret = -EFAULT;
				ADEMOD_MGR_WARNING("RTKDEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETQUALITY failed !!!!!!!!!!!!!!!\n", __LINE__);
			} else {
				ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_GETQUALITY\n");
				pADemod_globe->m_pADemod->GetSignalQuality(pADemod_globe->m_pADemod, (ENUM_TV_QUAL)(get_quality.id), (TV_SIG_QUAL*)&quality_temp);
				switch (get_quality.id) {
				case TV_QUAL_NOSIG :
					get_quality.pQuality.nosig = quality_temp.nosig;
					break;

				case TV_QUAL_INNERLOCK :
					get_quality.pQuality.inner = quality_temp.inner;
					break;

				case TV_QUAL_SNR :
					get_quality.pQuality.snr = quality_temp.snr;

					break;
				case TV_QUAL_BEC :
				case TV_QUAL_BER : {
					if (get_quality.id == TV_QUAL_BER)
						get_quality.pQuality.ber = quality_temp.ber;
					if (get_quality.id  == TV_QUAL_BEC) {
						get_quality.pQuality.layer_ber.ber_num = quality_temp.layer_ber.ber_num;
						get_quality.pQuality.layer_ber.ber_den = quality_temp.layer_ber.ber_den;
					}

					break;
				}
				case TV_QUAL_PEC :
				case TV_QUAL_PER :
				case TV_QUAL_UCBLOCKS : {
					if (get_quality.id == TV_QUAL_PER)
						get_quality.pQuality.per = quality_temp.per;
					else if (get_quality.id == TV_QUAL_UCBLOCKS)
						get_quality.pQuality.layer_per.per_num = quality_temp.ucblocks;
					else if (get_quality.id == TV_QUAL_PEC) {
						get_quality.pQuality.layer_per.per_num = quality_temp.layer_per.per_num;
						get_quality.pQuality.layer_per.per_den = quality_temp.layer_per.per_den;
					}

					break;
				}

				case TV_QUAL_SIGNAL_STRENGTH:
					get_quality.pQuality.strength = quality_temp.strength;
					break;

				case TV_QUAL_SIGNAL_QUALITY:
					get_quality.pQuality.quality = quality_temp.quality;
					break;

				case TV_QUAL_AGC: {
					get_quality.pQuality.agc = quality_temp.agc;
				}
				break;

				default:
					ret = TUNER_CTRL_FAIL;
				}

				if (copy_to_user((void __user *)arg, &get_quality, sizeof(RTK_ADEMOD_GET_QUALITY)))
					ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETQUALITY failed !!!!!!!!!!!!!!!\n", __LINE__);
				ret = 0;
			}
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_GETQUALITY ,No need to do something in CVBS Mode\n");
			if (copy_to_user((void __user *)arg, &get_quality, sizeof(RTK_ADEMOD_GET_QUALITY)))
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETQUALITY failed !!!!!!!!!!!!!!!\n", __LINE__);
			ret = 0;
		}
		break;

	case IOCTL_RTK_ADEMOD_GETCARRIEROFFSET:
		if (_SRC_CVBS != Scaler_AVD_GetAvdSource()) {
			ADEMOD_MGR_CALLER("IOCTL_RTK_ADEMOD_GETCARRIEROFFSET\n");
			pADemod_globe->m_pADemod->GetCarrierOffset(pADemod_globe->m_pADemod, &(get_carrier_offset.pOffset));
			ret = 0;
			if (copy_to_user((void __user *)arg, &get_carrier_offset, sizeof(RTK_ADEMOD_GET_CARRIEROFFSET)))
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETCARRIEROFFSET failed !!!!!!!!!!!!!!!\n", __LINE__);
		} else {
			ADEMOD_MGR_INFO("IOCTL_RTK_ADEMOD_GETCARRIEROFFSET ,No need to do something in CVBS Mode\n");
			get_carrier_offset.pOffset = 0;
			if (copy_to_user((void __user *)arg, &get_carrier_offset, sizeof(RTK_ADEMOD_GET_CARRIEROFFSET)))
				ADEMOD_MGR_WARNING("RTKADEMOD[%d]: ioctl IOCTL_RTK_ADEMOD_GETCARRIEROFFSET failed !!!!!!!!!!!!!!!\n", __LINE__);
			ret = 0;
		}
		break;

	default:
		ADEMOD_MGR_WARNING("RTKADEMOD[%d]: unknown ioctl(0x%08x)\n", __LINE__, cmd);
		break;
	}
	up(&rtkdemod_Semaphore);
	up(&pADemod_globe->sem);
	return ret;
}

unsigned int rtk_ademod_poll(struct file *filp, poll_table *wait)
{
	if (pADemod_globe->filter_flag > 0) {
		pADemod_globe->filter_flag = 0;
		return POLLIN | POLLRDNORM;
	} else {
		return 0;
	}
}

struct file_operations ademod_fops = {
	.owner              = THIS_MODULE,
	.unlocked_ioctl     = rtk_ademod_ioctl,
	.open               = rtk_ademod_open,
	.release            = rtk_ademod_release,
	.poll               = rtk_ademod_poll,
};

static char *rtk_ademod_devnode(struct device *dev, mode_t *mode)
{
	return NULL;
}

static void __exit rtk_ademod_exit(void)
{

	dev_t dev = MKDEV(ademod_major, ademod_minor);

	if (rtk_ademod_platform_devs == NULL)
		BUG();

	device_destroy(rtk_ademod_class, dev);
	cdev_del(&pADemod_globe->cdev);
	platform_driver_unregister(&rtk_ademod_device_driver);
	platform_device_unregister(rtk_ademod_platform_devs);
	kfree(pADemod_globe);
	rtk_ademod_platform_devs = NULL;
	class_destroy(rtk_ademod_class);
	rtk_ademod_class = NULL;
	unregister_chrdev_region(dev, 1);
}

static int __init rtk_ademod_init(void)
{
	int result;
	dev_t dev = 0;

	ADEMOD_MGR_CALLER("\n\n\n\n *****************	  ademod init module  *********************\n\n\n\n");

	if (ademod_major) {
		dev = MKDEV(RTKADEMOD_MAJOR, 0);
		result = register_chrdev_region(dev, 1, DRV_NAME);
	} else {
		result = alloc_chrdev_region(&dev, ademod_minor, 1, DRV_NAME);
		ademod_major = MAJOR(dev);
	}

	if (result < 0) {
		ADEMOD_MGR_WARNING("ademod: can not get chrdev region...\n");
		return result;
	}

	rtk_ademod_class = class_create(THIS_MODULE, DRV_NAME);
	if (IS_ERR(rtk_ademod_class)) {
		ADEMOD_MGR_WARNING("ademod: can not create class...\n");
		result = PTR_ERR(rtk_ademod_class);
		goto fail_class_create;
	}

	rtk_ademod_class->devnode = rtk_ademod_devnode;
	pADemod_globe = kmalloc(sizeof(SRTK_ADEMOD_DATA), GFP_KERNEL);
	if (!pADemod_globe) {
		rtk_ademod_exit();
		return -ENOMEM;
	}

	rtk_ademod_platform_devs = platform_device_register_simple(DRV_NAME, -1, NULL, 0);
	if (platform_driver_register(&rtk_ademod_device_driver) != 0) {
		ADEMOD_MGR_WARNING("ademod: can not register platform driver...\n");
		result = -EINVAL;
		goto fail_platform_driver_register;
	}

	memset(pADemod_globe, 0, sizeof(SRTK_ADEMOD_DATA));
	cdev_init(&pADemod_globe->cdev, &ademod_fops);
	pADemod_globe->cdev.owner = THIS_MODULE;
	pADemod_globe->cdev.ops   = &ademod_fops;
	if (cdev_add(&pADemod_globe->cdev, dev, 1) < 0) {
		ADEMOD_MGR_WARNING("ademod: can not add character device...\n");
		goto fail_cdev_init;
	}

	device_create(rtk_ademod_class, NULL, dev, NULL, DRV_NAME);
	sema_init	(&rtkdemod_Semaphore, 1);
	sema_init(&pADemod_globe->sem, 1);

	return 0;

fail_cdev_init:
	platform_driver_unregister(&rtk_ademod_device_driver);
fail_platform_driver_register:
	platform_device_unregister(rtk_ademod_platform_devs);
	rtk_ademod_platform_devs = NULL;
	class_destroy(rtk_ademod_class);
fail_class_create:
	rtk_ademod_class = NULL;
	unregister_chrdev_region(dev, 1);
	return result;
}

module_init(rtk_ademod_init);
module_exit(rtk_ademod_exit);

MODULE_LICENSE("GPL");
