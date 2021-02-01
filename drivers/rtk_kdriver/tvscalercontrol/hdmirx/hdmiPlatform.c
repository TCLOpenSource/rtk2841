/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmiPlatform.c
 *
 * author: 	Hawkeye, Clint Barton
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/
#include <linux/kthread.h> //kthread_create()?Bkthread_run()
#include <linux/err.h> //IS_ERR()?BPTR_ERR()
#include <linux/delay.h>
#include <linux/time.h>
#include <linux/workqueue.h>
#include "hdmi_common.h"
#include "hdmi_vfe_config.h"



/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/




/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/





/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
struct semaphore smphr_timing_detect;
struct semaphore smphr_infopkt;

static struct workqueue_struct *hpdwq = NULL;
static struct delayed_work hpd_delay_work;






/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/







/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/

void lib_hdmi_semaphore_detect_init(void)
{
	sema_init(&smphr_timing_detect, 1);
}

struct semaphore* lib_hdmi_get_semaphore_detect(void)
{
	return &smphr_timing_detect;
}


void lib_hdmi_semaphore_infopkt_init(void)
{
	sema_init(&smphr_infopkt, 1);
}

struct semaphore* lib_hdmi_get_semaphore_infopkt(void)
{
	return &smphr_infopkt;
}


#define HDMI_PHY_AT_USERLAND			1
#if defined(CONFIG_USERSPACE_HDMI_PHY) || (HDMI_PHY_AT_USERLAND==1)

#define ENABLE_THREAD_TASK

static bool hdmiPhyEnable = false;
static bool audio_thread_flag = false;
static bool infoframe_flag = false;

#ifdef ENABLE_THREAD_TASK
	static struct task_struct *hdmi_task;
	static int hdmiPhyThread(void* arg);
#else
	static struct sigaction old_act;

void hdmPhy_singal(int data) {
//	printf("*");
	rtd_hdmiPhy_ISR();
}
#endif




static struct task_struct *audio_task;
static struct task_struct *infoframe_task;



static int hdmi_audio_thread(void* arg);
static int hdmi_infoframe_thread(void* arg);





#ifdef ENABLE_THREAD_TASK
void xDestroyHdmiPhyThread(void)
{
	int ret;
	if (hdmiPhyEnable == true) {

        HDMI_PRINTF("%s\n" , __func__ );

		ret = kthread_stop(hdmi_task);
		hdmiPhyEnable = false;

		if (!ret)
			pr_debug("%s hdmi thread stopped\n" , __func__ );
		else
			HDMI_PRINTF("%s thread stop error , ret = %d \n" , __func__ ,ret );
	}
}

bool xCreateHdmiPhyThread(void)
{
	int err;
	bool ret = false;

	if (hdmiPhyEnable == true)
			return false;

	HDMI_PRINTF("%s\n" , __func__ );

	hdmi_task = kthread_create(hdmiPhyThread, NULL, "hdmi_task");

	if (IS_ERR(hdmi_task))
	{
		err = PTR_ERR(hdmi_task);
		hdmi_task = NULL;
		hdmiPhyEnable = false;
		pr_err("%s , Unable to start kernel thread (err_id = %d)./n", __func__,err);
		return ret ;
	}

	hdmiPhyEnable = true;
	wake_up_process(hdmi_task);

	ret = true;

	HDMI_PRINTF("%s sucess \n" , __func__ );

	return ret;

}

static int hdmiPhyThread(void* arg)
{
	while (!kthread_should_stop() && hdmiPhyEnable == true) {
		newbase_rxphy_isr();
		msleep(10); // sleep 10 ms
	}

	return 0;
}

#endif

void HdmiISREnable(char nEnable)
{
#ifndef ENABLE_THREAD_TASK
	struct sigaction act;
	struct itimerval value;
#endif

		if (nEnable) {
#ifndef ENABLE_THREAD_TASK
		    if (hdmiPhyEnable == false) {
//		    	rtd_hdmiRx_cmd(IOCTRL_HDMI_PHY_START, NULL);
		    	act.sa_handler= hdmPhy_singal;
		    	act.sa_flags=0;
		    	sigemptyset(&act.sa_mask);
		    	sigaction(SIGALRM,&act, &old_act);

		    	value.it_value.tv_sec=0;
		    	value.it_value.tv_usec=10000;
		    	value.it_interval=value.it_value;
		    	setitimer(ITIMER_REAL,&value,NULL);
		    	hdmiPhyEnable = true;
			}
#else
			xCreateHdmiPhyThread();
#endif
		} else {
#ifndef ENABLE_THREAD_TASK
			if (hdmiPhyEnable == true) {
//				rtd_hdmiRx_cmd(IOCTRL_HDMI_PHY_STOP, NULL);
				value.it_value.tv_sec=0;
			    value.it_value.tv_usec=0;
			    value.it_interval=value.it_value;
			    setitimer(ITIMER_REAL,&value,NULL);
			    hdmiPhyEnable == false;
			   // sigaction(SIGALRM,&old_act, NULL);
			}
#else
			xDestroyHdmiPhyThread();
#endif
		}

}

void HdmiISRInit(void) {
       // pthread_create(&thread_id_hdmiPhy, NULL, hdmiPhyThread, (void *)NULL);
}

void HdmiISRClose(void) {
		HdmiISREnable(0);
}


void xDestroyHdmiAudioThread(void)
{
	int ret;

	if (audio_thread_flag == true) {


		HDMI_PRINTF("%s\n" , __func__ );

		ret = kthread_stop(audio_task);
		audio_thread_flag = false;

		if (!ret)
			HDMI_PRINTF("%s hdmi audio thread stopped\n" , __func__ );
		else
			HDMI_EMG("%s hdmi audio thread stopped error, ret = %d \n" , __func__ , ret  );
	}

}

bool xCreateHdmiAudioThread(void)
{
	int err;
	bool ret = false;

	if (audio_thread_flag == true)
		return true;

	HDMI_PRINTF("%s\n" , __func__ );

	audio_task = kthread_create(hdmi_audio_thread, NULL, "audio_task");

	if (IS_ERR(audio_task))
	{
		err = PTR_ERR(audio_task);
		audio_task = NULL;

		audio_thread_flag = false;
		pr_err("%s , Unable to start kernel thread (err_id = %d)./n", __func__,err);
		return ret ;
	}

	audio_thread_flag = true;

	newbase_hdmi_audio_reset_status();

	wake_up_process(audio_task);
	ret = true;

	HDMI_PRINTF("%s success \n" , __func__ );

	return ret;
}

static int hdmi_audio_thread(void* arg)
{
	while (!kthread_should_stop() && audio_thread_flag == true) {

		newbase_hdmi_audio_detect();

		msleep(10); // sleep 10 ms
	}

	return 0;
}



void xDestroyHdmiInfoFrameThread(void)
{
	int ret;

	if (infoframe_flag) {

		ret = kthread_stop(infoframe_task);
		infoframe_flag = false;

		if (!ret)
			pr_debug("%s hdmi thread stopped\n" , __func__ );
		else
			HDMI_PRINTF("%s error , ret = %d \n" , __func__ , ret );
	}
}

bool xCreateHdmiInfoFrameThread(void)
{
	int err;
	bool ret = false;

	if (infoframe_flag)
		return false;

	HDMI_PRINTF("%s\n" , __func__ );

	infoframe_task = kthread_create(hdmi_infoframe_thread, NULL, "infoframe_task");

	if (IS_ERR(infoframe_task))
	{
		err = PTR_ERR(infoframe_task);
		infoframe_task = NULL;

		infoframe_flag = false;
		pr_err("%s , Unable to start kernel thread (err_id = %d)./n", __func__,err);
		return ret ;
	}

	infoframe_flag = true;

	wake_up_process(infoframe_task);
	ret = true;

	HDMI_PRINTF("%s success \n" , __func__ );

	return ret;

}

static int hdmi_infoframe_thread(void* arg)
{
	int i;

	while (!kthread_should_stop() && infoframe_flag) {

		for( i = 0 ; i < HDMI_RX_PORT_MAX_NUM; ++i )		
			newbase_hdmi_update_infoframe(i);		

		msleep(40);        
	}

	return 0;
}




void newbase_hdmi_infoframe_thread(unsigned char create)
{
	if (create) {
		xCreateHdmiInfoFrameThread();
	} else {
		xDestroyHdmiInfoFrameThread();
	}
}

void newbase_hdmi_audio_thread(unsigned char create)
{
	if (create) {
		xCreateHdmiAudioThread();
	} else {
		xDestroyHdmiAudioThread();
	}
}



#else
int hdmi_fd = -1;

void HdmiISREnable(char nEnable) {

		if (hdmi_fd < 0) return ;

		if (nEnable)
			ioctl(hdmi_fd, IOCTRL_HDMI_PHY_START);
		else
			ioctl(hdmi_fd, IOCTRL_HDMI_PHY_STOP);

}
void HdmiISRInit(void) {

	hdmi_fd = open("/dev/hdmiRx", O_RDWR);
	if (hdmi_fd < 0) {
		hdmi_fd = -1;
		pr_debug("hdmi isr init fail\n");
		return;
	}

}

void HdmiISRClose(void) {

		if (hdmi_fd < 0) return ;
		HdmiISREnable(0);
		close(hdmi_fd);

}

void HdmiGetStruct(HDMIRX_IOCTL_STRUCT_T* ptr) {

		if (hdmi_fd < 0) return ;
		ioctl(hdmi_fd, IOCTRL_HDMI_GET_STRUCT, ptr);


}

void HdmiAudioPLLSampleStart(void) {
		if (hdmi_fd < 0) return ;
		ioctl(hdmi_fd, IOCTRL_HDMI_AUDIO_PLL_SAMPLE_START, 0);

}

void HdmiAudioPLLSampleStop(void) {
		if (hdmi_fd < 0) return ;
		ioctl(hdmi_fd, IOCTRL_HDMI_AUDIO_PLL_SAMPLE_STOP, 0);

}

void HdmiAudioPLLSampleDump(void) {
		if (hdmi_fd < 0) return ;
		ioctl(hdmi_fd, IOCTRL_HDMI_AUDIO_PLL_SAMPLE_DUMP, 0);
}

void HdmiSetAPStatus(HDMIRX_APSTATUS_T apstatus) {
		if (hdmi_fd < 0) return ;
		ioctl(hdmi_fd, IOCTRL_HDMI_SET_APSTATUS, apstatus);

}

void Hdmi_SetTimer10ms(unsigned short value) {
	if (hdmi_fd < 0) return ;
	ioctl(hdmi_fd, IOCTRL_HDMI_SET_TIMER, (void *) &value);


}
unsigned short Hdmi_GetTimer10ms(void) {
	unsigned short value;
	if (hdmi_fd < 0) return 0;
	ioctl(hdmi_fd, IOCTRL_HDMI_GET_TIMER, (void *) &value);
	return value;
}

#endif



void drvif_Hdmi_CreateHPDDelayWorkQueue(void *work_queue_func)
{
	if (NULL == hpdwq) {
		hpdwq = create_workqueue("HPD workqueue");
		if (NULL == hpdwq) {
			HDMI_EMG("ERROR: Create HPD workqueue failed!\n");
		} else {
			HDMI_EMG("Create HPD workqueue successful!\n");
			INIT_DELAYED_WORK(&hpd_delay_work, (void *)work_queue_func);
		}
	}
}

int drvif_Hdmi_startHPDDelayWorkQueue(unsigned int delayms)
{
	int ret = -1;
	if (hpdwq) {
		ret = queue_delayed_work(hpdwq, &hpd_delay_work, msecs_to_jiffies(delayms));
	}
	return ret;
}

void drvif_Hdmi_CancelHPDDelayWorkQueue(void)
{
	if (hpdwq) {
		cancel_delayed_work(&hpd_delay_work);
		flush_workqueue(hpdwq);
	}
}

void drvif_Hdmi_DestroyHPDDelayWorkQueue(void)
{
	if (hpdwq) {
		cancel_delayed_work(&hpd_delay_work);
		flush_workqueue(hpdwq);
		destroy_workqueue(hpdwq);
		hpdwq = NULL;
	}
}
//20151206 andy modify for HPD low delayed work
//================================



