#ifndef __RTK_QOS_CONTROL_H__
#define __RTK_QOS_CONTROL_H__

typedef enum {
	RTK_QOS_BOOT_MODE,
	RTK_QOS_NORMAL_MODE,
	RTK_QOS_DECODER_MODE,
	RTK_QOS_HDMI_4K_MODE, // current for HDMI 4K 50,60Hz
	RTK_QOS_USER_A_MODE,
	RTK_QOS_MODE_NUM
} RTK_QOS_MODE_T;

extern int rtk_qos_set_mode(RTK_QOS_MODE_T qos_mode);
extern int rtk_qos_suspend(void);
extern int rtk_qos_resume(void);
#endif /* __RTK_QOS_CONTROL_H__ */
