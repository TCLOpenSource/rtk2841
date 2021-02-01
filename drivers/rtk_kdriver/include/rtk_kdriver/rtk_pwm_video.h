#ifndef __RTK_PWM_VIDEO_H__
#define __RTK_PWM_VIDEO_H__

#define PATCH_FOR_VDELAY 0

void videoPwmAction_No(void);
void videoPwmAction_Yes(void);
static int rtk_pwm_init_mem(void);
static int rtk_pwm_send_mem(void);
static void rtk_pwm_destroy_mem(void);


#endif
