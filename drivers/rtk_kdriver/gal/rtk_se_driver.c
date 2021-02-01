/******************************************************************************
*
*   Copyright(c) 2016 Realtek Semiconductor Corp. All rights reserved.
*
*   @author baker.cheng@realtek.com
*
******************************************************************************/
#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h> /*kmalloc*/
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>/*copy_from_user*/
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>/*DMA*/
#include <linux/sched.h>/*common*/
#include <linux/ioctl.h>
#include <linux/platform_device.h>
#include <linux/pageremap.h>
#include <mach/platform.h>
#include <mach/irqs.h>
#include <linux/of_irq.h>
#if defined(CONFIG_ARM64)
#include <mach/io.h>
#endif
#include <rtk_crt.h>
#include <gal/rtk_se.h>
#include <gal/rtk_se_export.h>
#include <gal/rtk_se_reg.h>

#include "osd_dump_agent.h"

#define PW_SAVING  0

#if PW_SAVING
#include <linux/kthread.h>
#endif

/******************declare callback func******************/
#if defined(CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER)
#include <rtk_dc_mt.h>
static void se_debug_info(void);
DCMT_DEBUG_INFO_DECLARE(se_mdscpu,se_debug_info);

static void se_debug_info(void)
{
#if defined(CONFIG_ARM64)
	volatile unsigned long cmd_addr;
#else
	volatile unsigned int cmd_addr;
#endif
	int cnt = 0;

	if(isDcmtTrap("SE2_Q0") || isDcmtTrap("SE2_Q1") || isDcmtTrap("SE2")) {
		printk(KERN_ERR"\tb800c000=%08x\n",
			rtd_inl(SEOFFSET(SeCmdBase[0])));
		printk(KERN_ERR"\tb800c004=%08x\n",
			rtd_inl(SEOFFSET(SeCmdBase[1])));
		printk(KERN_ERR"\tb800c010=%08x\n",
			rtd_inl(SEOFFSET(SeCmdLimit[0])));
		printk(KERN_ERR"\tb800c014=%08x\n",
			rtd_inl(SEOFFSET(SeCmdLimit[1])));
		printk(KERN_ERR"\tb800c020=%08x\n",
			rtd_inl(SEOFFSET(SeCmdReadPtr[0])));
		printk(KERN_ERR"\tb800c024=%08x\n",
			rtd_inl(SEOFFSET(SeCmdReadPtr[1])));
		printk(KERN_ERR"\tb800c030=%08x\n",
			rtd_inl(SEOFFSET(SeCmdWritePtr[0])));
		printk(KERN_ERR"\tb800c034=%08x\n",
			rtd_inl(SEOFFSET(SeCmdWritePtr[1])));
		printk(KERN_ERR"\tb800c0d0=%08x\n",
			rtd_inl(SEOFFSET(SeDmaInfo1[0].SeRegBaseAddress[0])));
		printk(KERN_ERR"\tb800c0d4=%08x\n",
			rtd_inl(SEOFFSET(SeDmaInfo1[0].SeRegBaseAddress[1])));

		if(rtd_inl(SEOFFSET(SeCmdReadPtr[0])) &&
		    rtd_inl(SEOFFSET(SeCmdBase[0]))) {
			if(rtd_inl(SEOFFSET(SeCmdReadPtr[0])) ==
				rtd_inl(SEOFFSET(SeCmdBase[0]))) {

#if defined(CONFIG_ARM64)
				cmd_addr = (volatile unsigned long)phys_to_virt(rtd_inl(SEOFFSET(SeCmdLimit[0])));
#else
				cmd_addr = (volatile unsigned int)phys_to_virt(rtd_inl(SEOFFSET(SeCmdLimit[0])));
#endif
			}else{

#if defined(CONFIG_ARM64)
				cmd_addr = (volatile unsigned long)phys_to_virt(rtd_inl(SEOFFSET(SeCmdReadPtr[0])));
#else
				cmd_addr = (volatile unsigned int)phys_to_virt(rtd_inl(SEOFFSET(SeCmdReadPtr[0])));
#endif
			}
			printk(KERN_ERR"\t");
			for(cnt=0;cnt<32;cnt++) {
#if defined(CONFIG_ARM64)
				printk(KERN_ERR"%lx ",*((volatile unsigned long*)(cmd_addr)-cnt));
#else
				printk(KERN_ERR"%08x ",*((volatile unsigned int*)(cmd_addr)-cnt));

#endif
			}
		}
		printk(KERN_ERR"\n");


	}else{
		/*do nothing, shall we need printk ?*/
		printk(KERN_ERR"NOT SE module.\n");
		return;
	}
	/*get dcmt trap information (include trash_addr,module_id,rw_type)
	dcmt_trap_info trap_info;
	get_dcmt_trap_info(&trap_info);
	*/
        return;
}
#endif

static int lord_kspace_p = 0;
static int lord_uspace_p = 0;
static int lord_uspace_pp = 0;
static int lord_uspace_t = 0;
#if SE_SE20 || SE_OLD
static uint32_t se_s_index8_mem_phy = 0;
static uint32_t* se_s_index8_mem_vir = 0;
#endif

#if defined(SE_RECOVERY_VCPU)
static uint32_t se_v_base = 0;
static uint32_t se_v_limit = 0;
static uint32_t se_v_rptr = 0;
static uint32_t se_v_wptr = 0;
static uint32_t se_v_qpri = 0;
static uint32_t se_v_int = 0;
static uint32_t se_v_taskid = 0;
static uint32_t se_v_ctl = 0;

#if SE_SE20_EXT
#define SE_CONV_COEF_NUM 7
#define SE_SCAL_VAL_NUM 6
#define SE_SCAL_COEFH_NUM 64 /*32,32*/
#define SE_SCAL_COEFV_NUM 32 /*16,16*/

#define SE_SCAL_COEFHV_NUM (SE_SCAL_COEFH_NUM+SE_SCAL_COEFV_NUM)
#define SE_SCAL_COEFHV20_NUM (64)
static uint32_t se_v_conv_coef[SE_CONV_COEF_NUM];
static uint32_t se_v_scal_val[SE_SCAL_VAL_NUM];
static uint32_t se_v_scal_coef_hv[SE_SCAL_COEFHV_NUM];
static uint32_t se_v_scal_coef_hv20[SE_SCAL_COEFHV20_NUM];
#endif

#if SE_OLD || SE_SE20
#define SE_CONV_COEF_NUM 8
#define SE_SCAL_VAL_NUM 3
#define SE_SCAL_COEFH_NUM 64 /*32,32*/
#define SE_SCAL_COEFV_NUM 32 /*16,16*/
static uint32_t se_v_conv_coef[SE_CONV_COEF_NUM];
static uint32_t se_v_scal_val[SE_SCAL_VAL_NUM];
static uint32_t se_v_scal_coef_h[SE_SCAL_COEFH_NUM];
static uint32_t se_v_scal_coef_v[SE_SCAL_COEFV_NUM];
#endif
#endif
static int rtk_se_fmt(SE_FMT_ST *pInfo);


inline void InitSeReg(void)
{
	rtd_outl(SEOFFSET(SeCtrl), 0x5);
	rtd_outl(SEOFFSET(SeCmdBase), (uint32_t) se_devices->CmdBase);
	rtd_outl(SEOFFSET(SeCmdLimit), (uint32_t) se_devices->CmdLimit);
	rtd_outl(SEOFFSET(SeCmdReadPtr), (uint32_t) se_devices->CmdReadPtr);
	rtd_outl(SEOFFSET(SeCmdWritePtr), (uint32_t) se_devices->CmdWritePtr);
	rtd_outl(SEOFFSET(SeInstCntL), 0x0);
	rtd_outl(SEOFFSET(SeInstCntH), 0x0);
	se_devices->u64InstCnt = 0;
	se_devices->u64IssuedInstCnt = 0;
	if(se_devices->CmdReadPtr != se_devices->CmdWritePtr) {
		rtd_outl(SEOFFSET(SeCtrl), 0x7);
	}
	/*set FBDC dummy register*/
	/*rtd_outl(SEOFFSET(SeSctch), BIT(5) | BIT(8));*/


#if SE_SE20 || SE_OLD
	if(se_s_index8_mem_phy) {
#if SE_SE20
		rtd_outl(SEOFFSET(SeDmaInfo2[5]), se_s_index8_mem_phy );
#endif
#if SE_OLD
		rtd_outl(SEOFFSET(SeDmaInfo1[0].SeRegBaseAddress[3]), se_s_index8_mem_phy);
#endif
	}
#endif
}

#if defined(SE_RECOVERY_VCPU)
#if SE_SE20_EXT
inline void InitSeVReg(void)
{
	if(se_v_base)
		rtd_outl(SEOFFSET(SeCmdBase[1]), se_v_base);
	if(se_v_limit)
		rtd_outl(SEOFFSET(SeCmdLimit[1]), se_v_limit);
	if(se_v_rptr)
		rtd_outl(SEOFFSET(SeCmdReadPtr[1]), se_v_rptr);
	if(se_v_wptr)
		rtd_outl(SEOFFSET(SeCmdWritePtr[1]), se_v_wptr);
	if(se_v_qpri)
		rtd_outl(SEOFFSET(SeQueuePriority), se_v_qpri);
	if(se_v_int)
		rtd_outl(SEOFFSET(SeIntSel), se_v_int);
	if(se_v_taskid)
		rtd_outl(SEOFFSET(Se20DmaInfo.Se20BaddrSet[15].Se20Baddr[1]),se_v_taskid);
	if(se_v_ctl)
		rtd_outl(SEOFFSET(SeCtrl[1]), se_v_ctl);

	if(se_v_base) {
		/*conv coef, 1d4,1e4,1f4,204,214,224,234*/
		unsigned int cnt=0;
		for(cnt=0;cnt<SE_CONV_COEF_NUM;cnt++) {
			rtd_outl(SEOFFSET(SeConvScaling[1]) +0x10*cnt, se_v_conv_coef[cnt]);
		}
		/*scal coef val, 2f4,304,314, 324, 334,344*/
		for(cnt=0;cnt<SE_SCAL_VAL_NUM;cnt++) {
			rtd_outl(SEOFFSET(SeStchSet[0])+0x4+0x10*cnt, se_v_scal_val[cnt]);
		}
		/*scal h,v coef 500, 580, 600, 640*/
		for(cnt=0;cnt<SE_SCAL_COEFHV_NUM;cnt++) {
			rtd_outl((SEOFFSET(SeCoefInfo[1])  +0x4*cnt), se_v_scal_coef_hv[cnt]);
		}
		/*68,88*/
		for(cnt=0;cnt<SE_SCAL_COEFHV20_NUM;cnt++) {
			rtd_outl((SEOFFSET(Se20CoefInfo[0])+0x4 +0x10*cnt), se_v_scal_coef_hv20[cnt]);
		}
	}

}
#else
inline void InitSeVReg(void)
{
	if(se_v_base)
		rtd_outl(SEOFFSET(SeCmdBase[1]), se_v_base);
	if(se_v_limit)
		rtd_outl(SEOFFSET(SeCmdLimit[1]), se_v_limit);
	if(se_v_rptr)
		rtd_outl(SEOFFSET(SeCmdReadPtr[1]), se_v_rptr);
	if(se_v_wptr)
		rtd_outl(SEOFFSET(SeCmdWritePtr[1]), se_v_wptr);
	if(se_v_qpri)
		rtd_outl(SEOFFSET(SeQueuePriority), se_v_qpri);
	if(se_v_int)
		rtd_outl(SEOFFSET(SeIntSel), se_v_int);
#if SE_SE20
	if(se_v_taskid)
		rtd_outl(SEOFFSET(SeDmaInfo2[5])+0x4,se_v_taskid);
#else
	if(se_v_taskid)
		rtd_outl(SEOFFSET(SeDmaInfo1[1].SeRegBaseAddress[3]),se_v_taskid);
#endif
	if(se_v_ctl)
		rtd_outl(SEOFFSET(SeCtrl[1]), se_v_ctl);

	if(se_v_base) {
		/*coef, 1e4,1f4,204,214,224,234,244,254,*/
		unsigned int cnt=0;
		for(cnt=0;cnt<SE_CONV_COEF_NUM;cnt++) {
			rtd_outl(SEOFFSET(SeConvScaling[1]) +0x10*cnt, se_v_conv_coef[cnt]);
		}

		/*scal coef val, 2c4,2d4,2e4*/
		for(cnt=0;cnt<SE_SCAL_VAL_NUM;cnt++) {
			rtd_outl(SEOFFSET(SeStretch[1]) + 0x10*cnt, se_v_scal_val[cnt]);
		}

		/*scal coef, 480,500*/
		for(cnt=0;cnt<SE_SCAL_COEFH_NUM;cnt++) {
			rtd_outl((0xb800c480 +0x4*cnt), se_v_scal_coef_h[cnt]);
		}

		/*scal coef, 580,5c0*/
		for(cnt=0;cnt<SE_SCAL_COEFV_NUM;cnt++) {
			rtd_outl((0xb800c580 +0x4*cnt), se_v_scal_coef_v[cnt]);
		}
	}
}
#endif
#endif
inline void StoreSeReg(void)
{
	se_devices->CmdReadPtr = rtd_inl(SEOFFSET(SeCmdReadPtr));
	se_devices->CmdWritePtr = rtd_inl(SEOFFSET(SeCmdWritePtr));

#if SE_SE20 || SE_OLD
	if(se_s_index8_mem_phy) {
#if SE_SE20
		se_s_index8_mem_phy = rtd_inl(SEOFFSET(SeDmaInfo2[5]));
#endif
#if SE_OLD
		se_s_index8_mem_phy = rtd_inl(SEOFFSET(SeDmaInfo1[0].SeRegBaseAddress[3]));
#endif
	}
#endif
}
#if defined(SE_RECOVERY_VCPU)
#if SE_SE20_EXT
inline void StoreSeVReg(void)
{
	unsigned int cnt=0;
	se_v_base = rtd_inl(SEOFFSET(SeCmdBase[1]));
	se_v_limit = rtd_inl(SEOFFSET(SeCmdLimit[1]));
	se_v_rptr = rtd_inl(SEOFFSET(SeCmdReadPtr[1]));
	se_v_wptr = rtd_inl(SEOFFSET(SeCmdWritePtr[1]));
	se_v_qpri = rtd_inl(SEOFFSET(SeQueuePriority));
	se_v_int = rtd_inl(SEOFFSET(SeIntSel));
	se_v_taskid = rtd_inl(SEOFFSET(Se20DmaInfo.Se20BaddrSet[15].Se20Baddr[1]));
	se_v_ctl = rtd_inl(SEOFFSET(SeCtrl[1]));

	/*conv coef, 1d4,1e4,1f4,204,214,224,234*/
	for(cnt=0;cnt<SE_CONV_COEF_NUM;cnt++) {
		se_v_conv_coef[cnt] =
		    rtd_inl(SEOFFSET(SeConvScaling[1]) +0x10*cnt);
	}
	/*scal coef val, 2f4,304,314, 324, 334,344*/
	for(cnt=0;cnt<SE_SCAL_VAL_NUM;cnt++) {
		se_v_scal_val[cnt] = rtd_inl(SEOFFSET(SeStchSet[0])+0x4+0x10*cnt);
	}

	/*scal h,v coef 500, 580, 600, 640*/
	for(cnt=0;cnt<SE_SCAL_COEFHV_NUM;cnt++) {
		se_v_scal_coef_hv[cnt] =
		    rtd_inl(SEOFFSET(SeCoefInfo[1]) +0x4*cnt);
	}

	/*68,88*/
	for(cnt=0;cnt<SE_SCAL_COEFHV20_NUM;cnt++) {
		se_v_scal_coef_hv20[cnt] =
		    rtd_inl(SEOFFSET(Se20CoefInfo[0])+0x4+0x10*cnt);
	}

}
#else
inline void StoreSeVReg(void)
{
	unsigned int cnt=0;
	se_v_base = rtd_inl(SEOFFSET(SeCmdBase[1]));
	se_v_limit = rtd_inl(SEOFFSET(SeCmdLimit[1]));
	se_v_rptr = rtd_inl(SEOFFSET(SeCmdReadPtr[1]));
	se_v_wptr = rtd_inl(SEOFFSET(SeCmdWritePtr[1]));
	se_v_qpri = rtd_inl(SEOFFSET(SeQueuePriority));
	se_v_int = rtd_inl(SEOFFSET(SeIntSel));
#if SE_SE20
	se_v_taskid = rtd_inl(SEOFFSET(SeDmaInfo2[5])+0x4);
#else
	se_v_taskid = rtd_inl(SEOFFSET(SeDmaInfo1[1].SeRegBaseAddress[3]));
#endif
	se_v_ctl = rtd_inl(SEOFFSET(SeCtrl[1]));

	/*conv coef, 1e4,1f4,204,214,224,234,244,254,*/
	for(cnt=0;cnt<SE_CONV_COEF_NUM;cnt++) {
		se_v_conv_coef[cnt] = rtd_inl(0xb800c1e4 +0x10*cnt);
	}
	/*scal coef val, 2c4,2d4,2e4*/
	for(cnt=0;cnt<SE_SCAL_VAL_NUM;cnt++) {
		se_v_scal_val[cnt] = rtd_inl(0xb800c2c4 +0x10*cnt);
	}

	/*scal coef, 480,500*/
	for(cnt=0;cnt<SE_SCAL_COEFH_NUM;cnt++) {
		se_v_scal_coef_h[cnt] = rtd_inl(0xb800c480 +0x4*cnt);
	}

	/*scal coef, 580,5c0*/
	for(cnt=0;cnt<SE_SCAL_COEFV_NUM;cnt++) {
		se_v_scal_coef_v[cnt] = rtd_inl(0xb800c580 +0x4*cnt);
	}
}
#endif
#endif

inline void UpdateInstCount(struct se_dev *dev)
{
	uint64_t u64InstCnt;
	u64InstCnt = (uint64_t)rtd_inl(SEOFFSET(SeInstCntL));
	u64InstCnt += ((uint64_t)rtd_inl((SEOFFSET(SeInstCntH))) << 32);
	dev->u64InstCnt = u64InstCnt;
}


static bool se_pm_func_clk_status = true; //1=clk on, 0=clk off

#if PW_SAVING
static void se_pm_func_clk_on(void) {
	/*this function must be inside se cmd lock*/
	//add clk or static variable  to check?
	rtk_se_power(1);
	InitSeReg();
#if defined(SE_RECOVERY_VCPU)
	InitSeVReg();
#endif
}
#endif

#if PW_SAVING
/*#define SE_PM_PRINT(s, args...) printk(s, ## args)*/
#define SE_PM_PRINT(s, args...)
static bool se_pm_func_clk_ctl = false; //1=pm func on, 0= pm func off
static void se_pm_func_clk_on(void);

static void set_se_pm_func_clk_ctl_status(bool en) {
	if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
		SE_PM_PRINT(KERN_ERR "[SE]GET Command Queue FAIL@%s \n.", __func__);
		return;
	}
	se_pm_func_clk_ctl = en;
	/*before disable this, clk shuld be up*/
	if(se_pm_func_clk_status == false && se_pm_func_clk_ctl == false) {
		se_pm_func_clk_on();
		SE_PM_PRINT(KERN_ERR "[SE]set clk on@%s \n.", __func__);
	}

	up(&sem_cmdqueue);
	return;
}



static int se_pm_func(void*) {

	msleep(70000);
	while(1) {
		msleep(500);

		if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
			printk(KERN_ERR "[SE]GET Command Queue FAIL@%s \n.", __func__);
			continue;
		}
		if(se_pm_func_clk_ctl == false) {
			/*don't clk off*/
			up(&sem_cmdqueue);
			SE_PM_PRINT(KERN_ERR"[SE]@%s - clk ctl off skip\n", __func__);
			continue;
		}
		if(se_pm_func_clk_status == false) {
			/*clk is off now*/
			up(&sem_cmdqueue);
			/*need more delay? msleep(1000);*/
			SE_PM_PRINT(KERN_ERR"[SE]@%s - clk off skip\n", __func__);
			continue;
		}

		if ((rtd_inl(SEOFFSET(SeIdle)) & 0x1) &&
			!(rtd_inl(SEOFFSET(SeCtrl)) & 0x2) &&
			(rtd_inl(SEOFFSET(SeCmdReadPtr)) ==
			 rtd_inl(SEOFFSET(SeCmdWritePtr)))) {
			up(&sem_cmdqueue);
		}else{
			SE_PM_PRINT(KERN_ERR"[SE]@%s - scpu busy skip\n", __func__);
			continue;
		}

#if defined(SE_RECOVERY_VCPU)
		if ((rtd_inl(SEOFFSET(SeIdle[1])) & 0x1) &&
			!(rtd_inl(SEOFFSET(SeCtrl[1])) & 0x2) &&
			(rtd_inl(SEOFFSET(SeCmdReadPtr[1])) ==
			rtd_inl(SEOFFSET( SeCmdWritePtr[1])))) {
			up(&sem_cmdqueue);
		}else {
			SE_PM_PRINT(KERN_ERR"[SE]@%s - vcpu busy skip\n", __func__);
			continue;

		}
		StoreSeVReg();
#endif
		StoreSeReg();
		rtk_se_power(0);
		up(&sem_cmdqueue);
		SE_PM_PRINT(KERN_ERR "[SE]set clk off@%s \n", __func__);
	}
	return 0;
};
#endif

/* This function services keyboard interrupts. It reads the relevant
 * information from the keyboard and then scheduales the bottom half
 * to run when the kernel considers it safe.
 *
 *
*/
irqreturn_t rtk_se_irq_handler(int irq, void *dev_id)
{
	if ((rtd_inl(SEOFFSET(SeInte)) & 0x8) &&
		(rtd_inl(SEOFFSET(SeInts)) & 0x8)) {
		rtd_outl(SEOFFSET(SeInts), (uint32_t)0x8);
		rtd_outl(SEOFFSET(SeInte), (uint32_t) 0x8);
		if ((rtd_inl(SEOFFSET(SeCtrl)) & 0x2) &&
			((rtd_inl(SEOFFSET(SeIdle)) & 0x1) == 0))
			dev_info(se_device_st, "se is not idle\n");
		up(&sem_checkfinish);
		return IRQ_HANDLED;
	}
	dev_info(se_device_st, "se IRQ_NONE\n");
	return IRQ_NONE;
}

int rtk_se_open(struct inode *inode, struct file *filp)
{
	struct se_dev *dev;
	int queue = iminor(inode);
	dev_info(se_device_st,
		 " **********    se open: queue = %d   **********\n", queue);
	dev = container_of(inode->i_cdev, struct se_dev, cdev);
	filp->private_data = dev;
	/* now trim to 0 the length of the device if open was write-only */
	if(down_timeout(&dev->sem, HZ/2)) {
		printk(KERN_ERR "[SE]%s-%d dev sem timeout!\n",
			__func__,__LINE__ );
		return -ERESTARTSYS;
	}
	dev_info(se_device_st,
		 " **********    se open: initialized = %d  **********\n",
		 dev->initialized);
	if (dev->initialized) {
		dev->initialized++;
		up(&dev->sem);
		return 0;
	}

	dev->initialized++;
	dev->queue = queue;

	up(&dev->sem);
	return 0;
}
int rtk_se_release(struct inode *inode, struct file *filp)
{
	/* struct se_dev *dev = filp->private_data;  for other methods */
	struct se_dev *dev = se_devices;
	/* int queue = dev->queue; */
	if(down_timeout(&dev->sem, HZ/2)) {
		printk(KERN_ERR "[SE]%s-%d dev sem timeout!\n",
			__func__,__LINE__ );
		return -ERESTARTSYS;
	}
	dev->initialized--;
	dev_info(se_device_st, "\nse release, count = %d\n", dev->initialized);

	if (dev->initialized > 0) {
		up(&dev->sem);
		return 0;
	}
	up(&dev->sem);
#if SE_SE20 || SE_OLD
	se_free_mem();
#endif

	return 0;
}
ssize_t rtk_se_read(struct file * filp, char __user * buf, size_t count,
		loff_t * f_pos)
{
	printk(KERN_ERR "[SE]%sunsupported\n", __func__);
	return -EFAULT;
}
ssize_t rtk_se_write(struct file * filp, const char __user * buf, size_t count,
		 loff_t * f_pos)
{
	printk(KERN_ERR "[SE]%sunsupported\n", __func__);
	return -EFAULT;
}

/*
 * The "extended" operations -- only seek
 */

loff_t rtk_se_llseek(struct file * filp, loff_t off, int whence)
{
	printk(KERN_ERR "[SE]%sunsupported\n", __func__);
	return -EINVAL;
}


long rtk_se_ioctl(struct file *filp, uint32_t cmd, unsigned long arg)
{
	/* struct se_dev *dev = filp->private_data; */
	/*struct se_dev *dev = se_devices;*/
	int retval = 0;

	switch (cmd) {
	case SE_IOC_CMD_LOCK:
	{
		SE_LOCK_INFO_T stpidinfo;
		memset(&stpidinfo, 0, sizeof(SE_LOCK_INFO_T));
		if (copy_from_user
		    ((void *)&stpidinfo, (const void __user *)arg,
		     sizeof(struct SE_LOCK_INFO))) {
			retval = -EFAULT;
			dev_info(se_device_st,
				 "SE_IOC_CMD_LOCK get pid  failed!\n");
			//goto out;
		}
		if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
			printk(KERN_ERR "[SE]GET Command Queue FAIL \n.");
			printk(KERN_ERR \
			"[SE]Blocking:K_pid = %d, u_pid = %d, u_ppid = %d,",\
			lord_kspace_p,lord_uspace_p,lord_uspace_pp);
			printk(KERN_ERR "u_tid = %d\n", lord_uspace_t);
			printk(KERN_ERR \
			"[SE]Looser  :K_pid = %d, u_pid = %d, u_ppid = %d,",\
			current->pid,stpidinfo.m_pid,stpidinfo.m_ppid);
			printk(KERN_ERR "u_tid = %d\n", stpidinfo.m_tid);
			retval = -EINTR;
			goto out;
		}
#if PW_SAVING
		if(se_pm_func_clk_status == false) {
			se_pm_func_clk_on();
			SE_PM_PRINT(KERN_ERR "[SE]set clk on@%s \n", __func__);
		}
#endif

		lord_kspace_p = current->pid;
		lord_uspace_p = stpidinfo.m_pid;
		lord_uspace_pp = stpidinfo.m_ppid;
		lord_uspace_t = stpidinfo.m_tid;
		//StoreSeReg();
#if 0
		//rtk_se_checkFinish();
		rtd_outl(0xb800cdc0, 0);
		rtd_outl(0xb800ce20, 0xffff0000);
#endif
		break;
	}
	case SE_IOC_CMD_UNLOCK:
		lord_kspace_p = 0;
		lord_uspace_p = 0;
		lord_uspace_pp = 0;
		lord_uspace_t = 0;
#if 0
		//rtk_se_checkFinish();
		rtd_outl(0xb800cdc0, 0);
		rtd_outl(0xb800ce20, 0xffff0000);
#endif
		up(&sem_cmdqueue);
		break;
	case SE_IOC_HW_RESET:
	{
		/*set FBDC dummy register, for video pwm, we set 0 first*/
		/*rtd_outl(SEOFFSET(SeSctch), 0); */

#if defined(SE_RECOVERY_VCPU)
		StoreSeVReg();
#endif
		rtk_se_power(1);
		printk(KERN_ERR "[SE] HW-RESET entry !!!\n");
		InitSeReg();
#if defined(SE_RECOVERY_VCPU)
		InitSeVReg();
#endif
		break;
	}
	case SE_IOC_WAIT_FOR_COMPLETE:
	{
#if PW_SAVING
		if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
			printk(KERN_ERR "[SE]GET Command Queue FAIL@%s SE_IOC_WAIT_FOR_COMPLETE \n.", __func__);
			break;
		}

		if(se_pm_func_clk_status == false) {
			up(&sem_cmdqueue);
			SE_PM_PRINT(KERN_ERR"[SE]@%s-SE_IOC_WAIT_FOR_COMPLETE, clk off skip\n", __func__);
			break;
		}
		SE_PM_PRINT(KERN_ERR"[SE]@%s-SE_IOC_WAIT_FOR_COMPLETE, clk on...\n", __func__);
#endif
		rtk_se_checkFinish();
#if defined(SE_RECOVERY_VCPU)
		rtk_se_checkFinishV();
#endif
#if PW_SAVING
		up(&sem_cmdqueue);
#endif
		break;
	}
#if PW_SAVING
	case SE_IOC_PM_CTRL:
	{
		bool data;
		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(bool))) {
			retval = -EFAULT;
			//printk(KERN_ERR"[SE]SE_IOC_PM_CTRL get value  failed!\n");
			/*disable pm func if anything gets wrong*/
			set_se_pm_func_clk_ctl_status(false);
		}else{
			printk(KERN_ERR"[SE]SE_IOC_PM_CTRL get value is %d\n",data);
			set_se_pm_func_clk_ctl_status(data);
		}
		break;
	}
#endif
	case SE_IOC_FMT:
	{
		SE_FMT_ST data;
		if (copy_from_user((void *)&data, (const void __user *)arg, sizeof(SE_FMT_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]SE_IOC_FMT get value fail!\n");
		}else {
			retval = rtk_se_fmt(&data);
			rtk_se_checkFinish();
		}

		break;
	}

	case SE_IOC_SETPALTE:
	{
		KADP_SE_PALE_ST pale;
		//pale = kmalloc(sizeof(KADP_SE_PALE_ST), GFP_KERNEL);
		//if (pale == NULL)
		//	return -EFAULT ;

		if (copy_from_user((void *)&pale, (const void __user *)arg,
			    sizeof(KADP_SE_PALE_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]setpalette get value fail!\n");
		}else {
			lord_kspace_p = current->pid;
			lord_uspace_p = pale.pinfo.m_pid;
			lord_uspace_pp = pale.pinfo.m_ppid;
			lord_uspace_t = pale.pinfo.m_tid;
			if(KGAL_SetSurfacePalette((KGAL_PALETTE_SURFACE_INFO_T*)&pale) != true){
				retval = -EFAULT;
			}
		}
		//kfree(pale);
		break;
	}
	case SE_IOC_BLIT:
	{
		KADP_SE_BLIT_ST bst;
		if (copy_from_user((void *)&bst, (const void __user *)arg,
			    sizeof(KADP_SE_BLIT_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]blit get value fail!\n");
		}else {

			lord_kspace_p = current->pid;
			lord_uspace_p = bst.pinfo.m_pid;
			lord_uspace_pp = bst.pinfo.m_ppid;
			lord_uspace_t = bst.pinfo.m_tid;
			if(KGAL_Blit(&bst.tSrcSurface, &bst.tSrcRect,
				&bst.tDstSurface, bst.dx, bst.dy,
				&bst.tBlitFlags, &bst.tBlitSettings) != true) {
				retval = -EFAULT;
			}
		}
		break;
	}
	case SE_IOC_STCHBLIT:
	{
		KADP_SE_STCHBLIT_ST bst;
		if (copy_from_user((void *)&bst, (const void __user *)arg,
			    sizeof(KADP_SE_STCHBLIT_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]stchblit get value fail!\n");
		}else {
			lord_kspace_p = current->pid;
			lord_uspace_p = bst.pinfo.m_pid;
			lord_uspace_pp = bst.pinfo.m_ppid;
			lord_uspace_t = bst.pinfo.m_tid;
			if(KGAL_StretchBlit(&bst.tSrcSurface, &bst.tSrcRect,
				&bst.tDstSurface, &bst.tDstRect, &bst.tBlitFlags,
				&bst.tBlitSettings) != true) {
				retval = -EFAULT;
			}
		}
		break;
	}
	case SE_IOC_FILLRECT:
	{
		KADP_SE_DRAW_ST bst;
		if (copy_from_user((void *)&bst, (const void __user *)arg,
			    sizeof(KADP_SE_DRAW_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]fillrect get value fail!\n");
		}else {
			lord_kspace_p = current->pid;
			lord_uspace_p = bst.pinfo.m_pid;
			lord_uspace_pp = bst.pinfo.m_ppid;
			lord_uspace_t = bst.pinfo.m_tid;

			if(KGAL_FillRectangle(&bst.tDstSurface, &bst.tDstRect,
				bst.color, &bst.tDrawFlags,
				&bst.tDrawSettings) != true){
				retval = -EFAULT;
			}
		}
		break;
	}
	case SE_IOC_DRAWRECT:
	{
		KADP_SE_DRAW_ST bst;
		if (copy_from_user((void *)&bst, (const void __user *)arg,
			    sizeof(KADP_SE_DRAW_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]fillrect get value fail!\n");
		}else {
			lord_kspace_p = current->pid;
			lord_uspace_p = bst.pinfo.m_pid;
			lord_uspace_pp = bst.pinfo.m_ppid;
			lord_uspace_t = bst.pinfo.m_tid;

			if(KGAL_DrawRectangle(&bst.tDstSurface, &bst.tDstRect,
				bst.color, &bst.tDrawFlags,
				&bst.tDrawSettings) != true){
				retval = -EFAULT;
			}
		}
		break;
	}
	case SE_IOC_DRAWLINE:
	{
		KADP_SE_DRAW_ST bst;

		if (copy_from_user((void *)&bst, (const void __user *)arg,
			    sizeof(KADP_SE_DRAW_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]fillrect get value fail!\n");
		}else {
			lord_kspace_p = current->pid;
			lord_uspace_p = bst.pinfo.m_pid;
			lord_uspace_pp = bst.pinfo.m_ppid;
			lord_uspace_t = bst.pinfo.m_tid;
			if(KGAL_DrawLine(&bst.tDstSurface, &bst.tDstLine,
				bst.color, &bst.tDrawFlags,
				&bst.tDrawSettings) != true){
				retval = -EFAULT;
			}
		}
		break;
	}
	case SE_IOC_FMTCONV:
	{
		KADP_SE_BLIT_ST bst;

		if (copy_from_user((void *)&bst, (const void __user *)arg,
			    sizeof(KADP_SE_BLIT_ST))) {
			retval = -EFAULT;
			printk(KERN_ERR"[SE]blit get value fail!\n");
		}else {
			lord_kspace_p = current->pid;
			lord_uspace_p = bst.pinfo.m_pid;
			lord_uspace_pp = bst.pinfo.m_ppid;
			lord_uspace_t = bst.pinfo.m_tid;
			if(KGAL_FormatConv(&bst.tSrcSurface, &bst.tSrcRect,
				&bst.tDstSurface, bst.dx, bst.dy,
				&bst.tBlitFlags, &bst.tBlitSettings) != true) {
				retval = -EFAULT;
			}
		}
		break;
	}
	case SE_IOC_WAITFINH:
	{
		UpdateInstCount(se_devices);
		if ((rtd_inl(SEOFFSET(SeIdle)) & 0x1) &&
			!(rtd_inl(SEOFFSET(SeCtrl)) & 0x2) &&
			(rtd_inl(SEOFFSET(SeCmdReadPtr)) ==
			 rtd_inl(SEOFFSET(SeCmdWritePtr)))) {
			UpdateInstCount(se_devices);
			se_devices->u64IssuedInstCnt = se_devices->u64InstCnt;
			retval = 1;
		}
		break;
	}
	default:
	{
		retval = -ENOTTY;
		goto out;
	}
	}
out:
	return retval;
}


int rtk_se_mmap(struct file *filp, struct vm_area_struct *vma)
{
	/* struct se_dev *dev = filp->private_data; */
	struct se_dev *dev = se_devices;
	unsigned long offset = vma->vm_pgoff;

	if(down_timeout(&dev->sem, HZ/2)) {
		printk(KERN_ERR "[SE]%s-%d dev sem timeout!\n",
			__func__,__LINE__ );
		return -ERESTARTSYS;
	}
	if (offset > (~0UL >> PAGE_SHIFT)) {
		dev_info(se_device_st, "%s, %d: offset = %ld\n", __FILE__,
			 __LINE__, offset);
		up(&dev->sem);
		return -EINVAL;
	}

	offset = offset << PAGE_SHIFT;
	//vma->vm_flags |= VM_IO | VM_RESERVED;
	vma->vm_flags |= (VM_IO | VM_LOCKED | (VM_DONTEXPAND | VM_DONTDUMP));
	if (offset == 0) {
		offset = (unsigned long)__pa(dev);
	} else if (offset == 0x10140000) {
		offset = (unsigned long)noncacheBufferPhy;
		vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
	} else if (offset == 0x1800C000) {
#if defined(CONFIG_ARM64)
		vma->vm_page_prot = pgprot_device(vma->vm_page_prot);
#else
		vma->vm_page_prot = pgprot_rtk_device(vma->vm_page_prot);
#endif
	} else {
		dev_info(se_device_st, "%s, %d: offset = %ld\n", __FILE__,
			 __LINE__, offset);
		up(&dev->sem);
		return -EINVAL;
	}

	if (io_remap_pfn_range
	    (vma, vma->vm_start, offset >> PAGE_SHIFT,
	     vma->vm_end - vma->vm_start, vma->vm_page_prot)) {
		up(&dev->sem);
		return -EAGAIN;
	}

	up(&dev->sem);
	return 0;
}

#ifdef CONFIG_PM
static int rtk_se_suspend(struct platform_device *dev, pm_message_t state)
{
#if PW_SAVING
	if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
		printk(KERN_ERR "[SE]GET Command Queue FAIL@%s \n.", __func__);
		return 0;
	}

	if(se_pm_func_clk_status == false){
		up(&sem_cmdqueue);
		printk(KERN_NOTICE "[RTK-SE]power is down, skip waiting idle bit\n");
		return 0;
	}
#endif

	rtk_se_checkFinish();
#if defined(SE_RECOVERY_VCPU)
	rtk_se_checkFinishV();
#endif
	printk(KERN_NOTICE "[RTK-SE]suspend, wait idle bit..finish.\n");
	se_devices->ignore_interrupt = 1;

	StoreSeReg();
#if defined(SE_RECOVERY_VCPU)
	StoreSeVReg();
#endif
	rtk_se_power(0);

#if PW_SAVING
	up(&sem_cmdqueue);
#endif
	return 0;
}

static int rtk_se_resume(struct platform_device *dev)
{
	printk(KERN_NOTICE "[RTK-SE]resume\n");
#if PW_SAVING
	if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
		printk(KERN_ERR "[SE]GET Command Queue FAIL@%s \n.", __func__);
		return 0;
	}
#endif
	rtk_se_power(1);

	InitSeReg();
#if defined(SE_RECOVERY_VCPU)
	InitSeVReg();
#endif
	se_devices->ignore_interrupt = 0;

#if PW_SAVING
	up(&sem_cmdqueue);
#endif
	return 0;
}

#endif
static struct platform_driver se_device_driver = {
#ifdef CONFIG_PM
	.suspend = rtk_se_suspend,
	.resume = rtk_se_resume,
#endif
	.driver = {
		   .name = "SE",
		   .bus = &platform_bus_type,

	},
};

static struct file_operations se_fops = {
	.owner = THIS_MODULE,
	.llseek = rtk_se_llseek,
	.read = rtk_se_read,
	.write = rtk_se_write,
	.unlocked_ioctl = rtk_se_ioctl,
	.open = rtk_se_open,
	.release = rtk_se_release,
	.mmap = rtk_se_mmap,
};

/*
 * The cleanup function is used to handle initialization failures as well.
 * Thefore, it must be careful to work correctly even if some of the items
 * have not been initialized
 */
static void se_cleanup_module(void)
{
	dev_t devno = MKDEV(se_major, se_minor);
	dev_info(se_device_st, "se clean module se_major = %d\n", se_major);

	if (noncacheBuffer) {
		dma_free_coherent(se_device_st, SE_COMMAND_ENTRIES,
			noncacheBuffer, noncacheBufferPhy);
	}

	free_irq(IRQ_SE, (void *)se_devices);
	unregister_chrdev_region(devno, se_nr_devs);
	if (se_devices) {
		cdev_del(&se_devices->cdev);
		device_destroy(se_class, devno);
		kfree(se_devices);
	}

	if (se_platform_devs)
		platform_device_unregister(se_platform_devs);

	platform_driver_unregister(&se_device_driver);
	if (se_class)
		class_destroy(se_class);

	//rtk_se_power(0);
	dev_info(se_device_st, "[SE] clean module success.\n");

	return;
};

/*
 * Set up the char_dev structure for this device.
 */
static void se_setup_cdev(struct se_dev *dev, int index)
{
	int err, devno = MKDEV(se_major, se_minor + index);
	cdev_init(&dev->cdev, &se_fops);
	dev->cdev.owner = THIS_MODULE;
	dev->cdev.ops = &se_fops;
	err = cdev_add(&dev->cdev, devno, 1);
	if (err)
		printk(KERN_NOTICE "Error %d adding se%d", err, index);
	se_device_st =
	    device_create(se_class, NULL, MKDEV(se_major, index), NULL, "se%d",
			  index);
}

#if defined(CONFIG_ARM64)
static char *se_devnode(struct device *dev, umode_t * mode) {
#else
static char *se_devnode(struct device *dev, mode_t * mode) {
#endif
	return NULL;
}

static int __init se_init_module(void)
{
	int result;
	uint32_t dwPhysicalAddress = 0;
	dev_t dev = 0;

#if PW_SAVING
	struct task_struct *se_pm_thread;
#endif
	printk(KERN_NOTICE
	       "\n[SE]%s,TIMEOUT=%d(%d), \n", __func__, SE_CMD_TIMEOUT, HZ);
	if (se_major) {
		dev = MKDEV(se_major, se_minor);
		result = register_chrdev_region(dev, se_nr_devs, "se");
	} else {
		result = alloc_chrdev_region(&dev, se_minor, se_nr_devs, "se");
		se_major = MAJOR(dev);
	}
	if (result < 0) {
		printk(KERN_WARNING "se: can't get major %d\n", se_major);
		return result;
	}
	printk(KERN_NOTICE "se init module major number = %d\n", se_major);
	se_class = class_create(THIS_MODULE, "se");
	if (IS_ERR(se_class))
		return PTR_ERR(se_class);
	se_class->devnode = se_devnode;

	se_platform_devs = platform_device_register_simple("SE", -1, NULL, 0);

	if (platform_driver_register(&se_device_driver) != 0) {
		platform_device_unregister(se_platform_devs);
		se_platform_devs = NULL;
		goto fail;
	}

	/*
	 * allocate the devices -- we can't have them static, as the number
	 * can be specified at load time
	 */
	se_devices =
		(struct se_dev *)kmalloc(se_nr_devs * sizeof(struct se_dev),
		GFP_KERNEL);
	noncacheBuffer =
		dma_alloc_coherent(se_device_st, SE_COMMAND_ENTRIES,
		&noncacheBufferPhy, GFP_KERNEL);
	printk(KERN_NOTICE
	       "B:SE_INIT...se_devices = %p(%08x), buffer(noncache) = %p(%08x)\n",
	       se_devices, (unsigned int)virt_to_phys(se_devices), noncacheBuffer,
	       (unsigned int)noncacheBufferPhy);
	if (!se_devices) {
		result = -ENOMEM;
		goto fail;
	}
	memset(se_devices, 0, sizeof(struct se_dev));

	sema_init(&se_devices->sem, 1);
	se_setup_cdev(se_devices, 0);
	sema_init(&sem_checkfinish, 1);
	sema_init(&sem_cmdqueue, 1);
	down(&sem_checkfinish);

	/* At this point call the init function for any friend device */
	dev = MKDEV(se_major, se_minor + se_nr_devs);

	se_devices->size = SE_COMMAND_ENTRIES;

	/* se_devices[0].CmdBuf = kmalloc(se_devices[0].size, GFP_KERNEL); */
	dwPhysicalAddress = noncacheBufferPhy;
	se_devices->CmdBase = (uint32_t) dwPhysicalAddress;
	se_devices->CmdWritePtr = se_devices->CmdBase;
	se_devices->CmdReadPtr = se_devices->CmdBase;

	se_devices->CmdLimit =
	    (uint32_t) (dwPhysicalAddress + se_devices->size);

#if defined(SE_RECOVERY_VCPU)
	if(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & BIT(SYS_REG_SYS_CLKEN1_clken_se_shift)) {
		StoreSeVReg();
	}
#endif
	rtk_se_power(1);
	InitSeReg();
#if defined(SE_RECOVERY_VCPU)
	InitSeVReg();
#endif

	StoreSeReg();
#if defined(SE_RECOVERY_VCPU)
	StoreSeVReg();
#endif

	if (request_irq
	    (IRQ_SE, rtk_se_irq_handler, IRQF_SHARED, "se", (void *)se_devices))
		dev_info(se_device_st, "se: can't get assigned irq%i\n",
			 IRQ_SE);

#if PW_SAVING
	se_pm_thread = kthread_create(se_pm_func, NULL, "SE_POWER_GUARD");
	if(se_pm_thread){
		printk(KERN_ERR"[SE] %s , run pm thread..\n", __func__);
		wake_up_process(se_pm_thread);
	}
#endif

#if defined(CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER)
DCMT_DEBUG_INFO_REGISTER(se_mdscpu,se_debug_info);
#endif

	return 0;

fail:
	se_cleanup_module();
	/*rtk_se_power(0);*/
	return result;
}

void rtk_se_power(int state)
{
	if(state ==1) {
		/*in some project, video enable se for logo animation.
		 we can't reset clk.*/
		if(!SYS_REG_SYS_CLKEN1_get_clken_se(rtd_inl(SYS_REG_SYS_CLKEN1_reg))) {
			CRT_CLK_OnOff(SE, CLK_ON, 0);
		}
		se_pm_func_clk_status = true;
	}else {
		CRT_CLK_OnOff(SE, CLK_OFF, 0);
		se_pm_func_clk_status = false;
	}
}

void WriteCmd(struct se_dev *dev, uint8_t* pbyCommandBuffer,
		int32_t lCommandLength) {
	uint32_t dwDataCounter = 0;
	uint32_t wrptr = 0, rdptr = 0;
	uint32_t u32Alignment = 0;

	if(down_timeout(&sem_cmdqueue, HZ/2)) {
		printk(KERN_ERR"[SE]Command Quard Interrupt\n.");
		return;
	}
	if (lCommandLength % 4 != 0) {
		u32Alignment = 4 - (lCommandLength % 4);
		se_devices->u64IssuedInstCnt += u32Alignment;
	}
	wrptr = dev->CmdWritePtr - dev->CmdBase;
	while (1) {
		rdptr = (uint32_t)rtd_inl(SEOFFSET(SeCmdReadPtr))-dev->CmdBase;
		if (rdptr <= wrptr)
			rdptr += dev->size;
		if ((wrptr + lCommandLength + u32Alignment) < rdptr)
			break;
	}

	for (dwDataCounter = 0; dwDataCounter < (uint32_t) lCommandLength;
	     dwDataCounter += sizeof(uint32_t)) {
		*(uint32_t *) (phys_to_virt(dev->CmdBase + wrptr)) =
		    *(uint32_t *) (pbyCommandBuffer + dwDataCounter);
		wrptr += sizeof(uint32_t);

		if (wrptr >= dev->size)
			wrptr = 0;
	}
	for (dwDataCounter = 0; dwDataCounter < u32Alignment;
	     dwDataCounter += sizeof(uint32_t)) {
		*(uint32_t *) (phys_to_virt(dev->CmdBase + wrptr)) = 0xf;
		wrptr += sizeof(uint32_t);
		if (wrptr >= dev->size)
			wrptr = 0;
	}
#if !defined(CONFIG_ARM64)
	dsb();
#endif
	dev->CmdWritePtr = (uint32_t) wrptr + dev->CmdBase;
	rtd_outl(SEOFFSET(SeCmdWritePtr), (uint32_t) dev->CmdWritePtr);
	rtd_outl(SEOFFSET(SeCtrl), 0x7);
	UpdateInstCount(dev);
	up(&sem_cmdqueue);
}

static int rtk_se_fmt(SE_FMT_ST *pInfo){
#if SE_SE20
	SECMD_EXT_FMT_CONV_SIM se_ext_conv;
	if(pInfo->width <=32 || pInfo->height <=0 ||pInfo->sAddr==0
		|| pInfo->dAddr==0 || pInfo->width%16 !=0) {
		printk(KERN_ERR"[SE] data error,saddr=%08x, daddr=%08x, w=%d, h=%d \n",
			pInfo->sAddr, pInfo->dAddr,
			pInfo->width <=32, pInfo->height);
		return -1;
	}

	memset((void *)&se_ext_conv, 0, sizeof(SECMD_EXT_FMT_CONV_SIM));
	se_ext_conv.WordReg1.OpCode = 0x1;
	se_ext_conv.WordReg1.RegisterAddress = 0x60;
	se_ext_conv.WordReg1_1.RegisterValue = 0x0075C057;

	se_ext_conv.WordAddr0.OpCode = 0x1;
	se_ext_conv.WordAddr0.RegisterAddress = 0xD0;
	se_ext_conv.WordAddr0_1.RegisterValue = pInfo->sAddr;

	se_ext_conv.WordPitch0.OpCode = 0x1;
	se_ext_conv.WordPitch0.RegisterAddress = 0xE0;
	se_ext_conv.WordPitch0_1.RegisterValue = pInfo->width*2;

	se_ext_conv.WordAddr1.OpCode = 0x1;
	se_ext_conv.WordAddr1.RegisterAddress = 0xD4;
	se_ext_conv.WordAddr1_1.RegisterValue = pInfo->dAddr;

	se_ext_conv.WordPitch1.OpCode = 0x1;
	se_ext_conv.WordPitch1.RegisterAddress = 0xE4;
	se_ext_conv.WordPitch1_1.RegisterValue = pInfo->width;

	se_ext_conv.WordAddr2.OpCode = 0x1;
	se_ext_conv.WordAddr2.RegisterAddress = 0xD8;
	se_ext_conv.WordAddr2_1.RegisterValue = pInfo->dAddr + pInfo->width*pInfo->height;

	se_ext_conv.WordPitch2.OpCode = 0x1;
	se_ext_conv.WordPitch2.RegisterAddress = 0xE8;
	se_ext_conv.WordPitch2_1.RegisterValue = pInfo->width;

	se_ext_conv.Word1.opcode = 0xb;
	se_ext_conv.Word1.rslt_fmt = pInfo->dFmt;

	se_ext_conv.Word1.rslt_swp_chr = pInfo->dSwap;
	se_ext_conv.Word1.src_swp_chr = pInfo->sSwap;
	se_ext_conv.Word1.two_dc_mode = 1;
	se_ext_conv.Word3.rslt_addr_index = 0x1;
	se_ext_conv.Word3.rslt_chr1_addr_index = 0x2;
	se_ext_conv.Word3.rslt_chr2_addr_index = 0x2;

	se_ext_conv.Word4.src1_inpt_w = pInfo->width;
	se_ext_conv.Word4.src1_inpt_h = pInfo->height;
	se_ext_conv.Word4.src1_fmt = pInfo->sFmt;
	se_ext_conv.Word6.src1_addr_index = 0;

	WriteCmd(se_devices, (uint8_t *)&se_ext_conv, sizeof(SECMD_EXT_FMT_CONV_SIM));
	return 0;
#else
	return -1;
#endif
}

int rtk_se_cpy(osd_dmem_info* pinfo) {
	SECMD_EXT_FMT_CONV_SIM se_ext_conv;

	if(pinfo == NULL || pinfo->dst_phyaddr == 0 || pinfo->src_phyaddr == 0 ||
		pinfo->w == 0 || pinfo->h == 0 || pinfo->pitch == 0 ||
		pinfo->w >3840 || pinfo->h > 3840 || pinfo->pitch > 3840*4)
		return -1;

	memset((void *)&se_ext_conv, 0, sizeof(SECMD_EXT_FMT_CONV_SIM));
	/*printk(KERN_ERR"%s src=%08x(%d) to %08x(%d)\n",__func__, pinfo->src_phyaddr, pinfo->pitch, pinfo->dst_phyaddr, pinfo->w );*/
	se_ext_conv.WordReg1.OpCode = 0x1;
	se_ext_conv.WordReg1.RegisterAddress = 0x60;
	se_ext_conv.WordReg1_1.RegisterValue = 0x00754057;

	se_ext_conv.WordAddr0.OpCode = 0x1;
	se_ext_conv.WordAddr0.RegisterAddress = 0xD0;
	se_ext_conv.WordAddr0_1.RegisterValue = pinfo->src_phyaddr;

	se_ext_conv.WordPitch0.OpCode = 0x1;
	se_ext_conv.WordPitch0.RegisterAddress = 0xE0;
	se_ext_conv.WordPitch0_1.RegisterValue = pinfo->pitch;

	se_ext_conv.WordAddr1.OpCode = 0x1;
	se_ext_conv.WordAddr1.RegisterAddress = 0xD4;
	se_ext_conv.WordAddr1_1.RegisterValue = pinfo->dst_phyaddr;
	se_ext_conv.WordPitch1.OpCode = 0x1;
	se_ext_conv.WordPitch1.RegisterAddress = 0xE4;
	se_ext_conv.WordPitch1_1.RegisterValue = pinfo->w*4;

	//dummy
	se_ext_conv.WordAddr2.OpCode = 0x1;
	se_ext_conv.WordAddr2.RegisterAddress = 0xD8;
	se_ext_conv.WordAddr2_1.RegisterValue = pinfo->dst_phyaddr;

	se_ext_conv.WordPitch2.OpCode = 0x1;
	se_ext_conv.WordPitch2.RegisterAddress = 0xE8;
	se_ext_conv.WordPitch2_1.RegisterValue = 0xf;

	se_ext_conv.WordAddr3.OpCode = 0x1;
	se_ext_conv.WordAddr3.RegisterAddress = 0xD8;
	se_ext_conv.WordAddr3_1.RegisterValue = pinfo->dst_phyaddr;

	se_ext_conv.WordPitch3.OpCode = 0x1;
	se_ext_conv.WordPitch3.RegisterAddress = 0xE8;
	se_ext_conv.WordPitch3_1.RegisterValue = 0xf;

	se_ext_conv.Word1.two_dc_mode = 1;
	se_ext_conv.Word1.opcode = 0xb;
	se_ext_conv.Word1.rslt_fmt =0xc;// 0x9;
	se_ext_conv.Word3.rslt_addr_index = 0x1;

	se_ext_conv.Word4.src1_inpt_w = pinfo->w;
	se_ext_conv.Word4.src1_inpt_h = pinfo->h;

	se_ext_conv.Word4.src1_fmt = 0xc;//0x9;

	se_ext_conv.Word5.src1_inpt_x=pinfo->x;
	se_ext_conv.Word5.src1_inpt_y=pinfo->y;

	se_ext_conv.Word6.src1_addr_index = 0;
	WriteCmd(se_devices, (uint8_t *)&se_ext_conv, sizeof(SECMD_EXT_FMT_CONV_SIM));
	//rtk_se_checkFinish();

	return 0;
}
EXPORT_SYMBOL(rtk_se_cpy);

bool rtk_se_checkFinish(void)
{
	bool ret = false;
	int delayAtomic = 1;
	int delaycounter = 0;

	while (!ret) {
		UpdateInstCount(se_devices);
		if ((rtd_inl(SEOFFSET(SeIdle)) & 0x1) &&
			!(rtd_inl(SEOFFSET(SeCtrl)) & 0x2) &&
			(rtd_inl(SEOFFSET(SeCmdReadPtr)) ==
			 rtd_inl(SEOFFSET(SeCmdWritePtr)))) {
			UpdateInstCount(se_devices);
			se_devices->u64IssuedInstCnt = se_devices->u64InstCnt;
			ret = true;
			break;
		}
		msleep(delayAtomic);
		if(delaycounter++ >5) {
			printk(KERN_ERR "[SE-S]checkfinihs too long!, break!");
			ret = false;
			break;
		}
	}

	return ret;
};
EXPORT_SYMBOL(rtk_se_checkFinish);

#if defined(SE_RECOVERY_VCPU)
bool rtk_se_checkFinishV(void)
{
	bool ret = false;
	int delayAtomic = 1;
	int delaycounter = 0;

	while (!ret) {
		if ((rtd_inl(SEOFFSET(SeIdle[1])) & 0x1) &&
			!(rtd_inl(SEOFFSET(SeCtrl[1])) & 0x2) &&
			(rtd_inl(SEOFFSET(SeCmdReadPtr[1])) ==
			rtd_inl(SEOFFSET( SeCmdWritePtr[1])))) {
			ret = true;
			break;
		}
		msleep(delayAtomic);
		if(delaycounter++ >5) {
			printk(KERN_ERR "[SE-V]checkfinihs too long!, break!");
			ret = false;
			break;
		}
	}


	return ret;
};
#endif

#if SE_SE20 || SE_OLD
unsigned int se_get_mem(void){
	if(se_s_index8_mem_phy)
		return se_s_index8_mem_phy;
	se_s_index8_mem_vir = (unsigned int*)dvr_malloc_specific(LUT8_WIDTH*LUT8_HEIGHT*4, GFP_DCU2_FIRST);
	if(se_s_index8_mem_vir == NULL)
		return 0;
	se_s_index8_mem_phy = (uint32_t)dvr_to_phys(se_s_index8_mem_vir);

	/*save phyaddr value to se BADDR register*/
	if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
		printk(KERN_ERR"[SE]%s-%d timeout \n.",__func__,__LINE__);
		//dvr_free((void*)se_s_index8_mem_vir);
		//se_s_index8_mem_phy = 0;
	}
#if SE_SE20
	rtd_outl(SEOFFSET(SeDmaInfo2[5]), se_s_index8_mem_phy );
#endif
#if SE_OLD
	rtd_outl(SEOFFSET(SeDmaInfo1[0].SeRegBaseAddress[3]), se_s_index8_mem_phy);
#endif
	up(&sem_cmdqueue);

	printk(KERN_ERR"[SE]%s-%d malloc memory size=%08x, addr=%08x \n.",__func__,__LINE__, LUT8_WIDTH*LUT8_HEIGHT*4, se_s_index8_mem_phy);
	return se_s_index8_mem_phy;
}

void se_free_mem(void){
	if(se_s_index8_mem_phy) {
		printk(KERN_ERR"[SE]%s-%d free memory size=%08x, addr=%08x \n.",__func__,__LINE__, LUT8_WIDTH*LUT8_HEIGHT*4, se_s_index8_mem_phy);
		if(down_timeout(&sem_cmdqueue, SE_CMD_TIMEOUT)) {
			printk(KERN_ERR"[SE]%s-%d timeout \n.",__func__,__LINE__);
		}
		dvr_free((void*)se_s_index8_mem_vir);
		se_s_index8_mem_vir = 0;
		se_s_index8_mem_phy = 0;
#if SE_SE20
		rtd_outl(SEOFFSET(SeDmaInfo2[5]), se_s_index8_mem_phy );
#endif
#if SE_OLD
		rtd_outl(SEOFFSET(SeDmaInfo1[0].SeRegBaseAddress[3]), se_s_index8_mem_phy);
#endif
		up(&sem_cmdqueue);
	}
}
#endif

module_init(se_init_module);
module_exit(se_cleanup_module);

MODULE_AUTHOR("baker.cheng <baker.cheng@realtek.com>");
MODULE_DESCRIPTION("Realtek 2D Graphic Driver");
MODULE_ALIAS("dev:se0");
MODULE_LICENSE("GPL");
