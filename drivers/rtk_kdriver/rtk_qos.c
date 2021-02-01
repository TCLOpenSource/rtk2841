#include <linux/syscalls.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/delay.h>
#include <mach/io.h>
#include <rtk_kdriver/rtk_qos_export.h>
#include "rbus/dc_phy_reg.h"

//#define ENABLE_DC2_SUPPORT

///////////////////////////////////////
//MC1 QoS
//MC1 CH0 - SCPU express lane
//MC1 CH1 - DC_SYS
//MC1 CH2 - DC_SYS2 Read
//MC1 CH3 - DC_SYS2 Write
//MC1 CH4 - DC_SYS3 Read
//MC1 CH5 - DC_SYS3 Write

///////////////////////////////////////
//MC2 QoS
//MC2 CH0 - SCPU express lane
//MC2 CH1 - DC_SYS
//MC2 CH2 - DC_SYS2 Read
//MC2 CH3 - DC_SYS2 Write
//MC1 CH4 - DC_SYS3 Read
//MC2 CH5 - DC_SYS3 Write

///////////////////////////////////////
// User Define
//#define MC_MEASURE_APPLY_SW_PATCH
//#define MC_MEASURE_PATCH_NUMERATOR 3
//#define MC_MEASURE_PATCH_DENOMINATOR 4

///////////////////////////////////////
// DBUS client id
// 30: KCPU
// 31: ACPU
// 32: ACPU2
// 33: VCPU
// 34: VCPU2
// F0: non-secure SCPU

unsigned char g_rtk_qos_force_setting = 0;
unsigned char g_rtk_qos_current_setting = 0;
unsigned int g_rtk_qos_parameter[66];

static int rtk_qos_save_mc_normal_setting(void)
{
	int idx = 0;
	int i = 0;

	// MC1
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_0_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_1_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_2_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_3_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_4_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_5_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_6_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_8_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_Qos_ctl_9_reg);

	for (i = 0;i < 24;i++)
	{
		g_rtk_qos_parameter[idx++] = rtd_inl(DC_PHY_ch0_ctl_0_reg + i*4);
	}

#ifdef ENABLE_DC2_SUPPORT
	//MC2
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_0_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_1_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_2_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_3_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_4_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_5_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_6_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_8_reg);
	g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_Qos_ctl_9_reg);

	for (i = 0;i < 24;i++)
	{
		g_rtk_qos_parameter[idx++] = rtd_inl(DC2_PHY_ch0_ctl_0_reg + i*4);
	}
#endif

	return 0;
}

static int rtk_qos_load_mc_normal_setting(void)
{
	int idx = 0;
	int i = 0;

    pr_debug("[QOS] NORMAL\n");

	// MC1
	rtd_outl(DC_PHY_Qos_ctl_0_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_1_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_2_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_3_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_4_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_5_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_6_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_8_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC_PHY_Qos_ctl_9_reg, g_rtk_qos_parameter[idx++]);

	for (i = 0;i < 24;i++)
	{
		rtd_outl(DC_PHY_ch0_ctl_0_reg + i*4, g_rtk_qos_parameter[idx++]);
	}

#ifdef ENABLE_DC2_SUPPORT
	//MC2
	rtd_outl(DC2_PHY_Qos_ctl_0_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_1_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_2_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_3_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_4_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_5_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_6_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_8_reg, g_rtk_qos_parameter[idx++]);
	rtd_outl(DC2_PHY_Qos_ctl_9_reg, g_rtk_qos_parameter[idx++]);

	for (i = 0;i < 24;i++)
	{
		rtd_outl(DC2_PHY_ch0_ctl_0_reg + i*4, g_rtk_qos_parameter[idx++]);
	}
#endif

	return 0;
}

static int rtk_qos_load_mc_decoder_setting(void)
{
    pr_debug("[QOS] DECODER\n");

	// MC1
	rtd_outl(DC_PHY_Qos_ctl_0_reg, 0x00000443);
	rtd_outl(DC_PHY_Qos_ctl_6_reg, 0x00180610);

	rtd_outl(DC_PHY_ch0_ctl_3_reg, 0x60210071);
	rtd_outl(DC_PHY_ch1_ctl_0_reg, 0x0984080e);
	rtd_outl(DC_PHY_ch1_ctl_1_reg, 0x70007f00);
	rtd_outl(DC_PHY_ch1_ctl_2_reg, 0x0800608f);
	rtd_outl(DC_PHY_ch1_ctl_3_reg, 0x80210071);

	rtd_outl(DC_PHY_ch2_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC_PHY_ch2_ctl_3_reg, 0x51015071);
	rtd_outl(DC_PHY_ch3_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC_PHY_ch3_ctl_3_reg, 0x51013071);
	rtd_maskl(DC_PHY_ch4_ctl_2_reg, 0xFFFFFFF0, 0x4);
	rtd_maskl(DC_PHY_ch5_ctl_2_reg, 0xFFFFFFF0, 0x4);

#ifdef ENABLE_DC2_SUPPORT
	// MC2
	rtd_outl(DC2_PHY_Qos_ctl_0_reg, 0x00000243);
	rtd_outl(DC2_PHY_Qos_ctl_6_reg, 0x00180610);

	rtd_outl(DC2_PHY_ch0_ctl_3_reg, 0x60210071);
	rtd_outl(DC2_PHY_ch1_ctl_0_reg, 0x0984080e);
	rtd_outl(DC2_PHY_ch1_ctl_1_reg, 0x70007f00);
	rtd_outl(DC2_PHY_ch1_ctl_2_reg, 0x0800608f);
	rtd_outl(DC2_PHY_ch1_ctl_3_reg, 0x80210071);

	rtd_outl(DC2_PHY_ch2_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC2_PHY_ch2_ctl_3_reg, 0x51015071);
	rtd_outl(DC2_PHY_ch3_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC2_PHY_ch3_ctl_3_reg, 0x51013071);
	rtd_maskl(DC2_PHY_ch4_ctl_2_reg, 0xFFFFFFF0, 0x4);
	rtd_maskl(DC2_PHY_ch5_ctl_2_reg, 0xFFFFFFF0, 0x4);
#endif

	return 0;
}

static int rtk_qos_load_mc_hdmi_4k_setting(void)
{
    pr_debug("[QOS] HDMI 4K\n");

	// MC1
	rtd_outl(DC_PHY_ch2_ctl_1_reg, 0x60007f00);
	rtd_outl(DC_PHY_ch2_ctl_3_reg, 0x83015071);

	rtd_outl(DC_PHY_ch3_ctl_1_reg, 0x60007500);
	rtd_outl(DC_PHY_ch3_ctl_2_reg, 0x1f409688);
	rtd_outl(DC_PHY_ch3_ctl_3_reg, 0x83013071);

	rtd_outl(DC_PHY_ch4_ctl_3_reg, 0x8300a011);
	rtd_outl(DC_PHY_ch5_ctl_3_reg, 0x53010011);

#ifdef ENABLE_DC2_SUPPORT
	// MC2
	rtd_outl(DC2_PHY_ch2_ctl_1_reg, 0x60007f00);
	rtd_outl(DC2_PHY_ch2_ctl_3_reg, 0x83015071);

	rtd_outl(DC2_PHY_ch3_ctl_1_reg, 0x60007500);
	rtd_outl(DC2_PHY_ch3_ctl_2_reg, 0x1f409688);
	rtd_outl(DC2_PHY_ch3_ctl_3_reg, 0x83013071);

	rtd_outl(DC2_PHY_ch4_ctl_3_reg, 0x8300a011);
	rtd_outl(DC2_PHY_ch5_ctl_3_reg, 0x53010011);
#endif

	return 0;
}

static int rtk_qos_load_mc_user_a_setting(void)
{
	pr_debug("[QOS] User A\n");

	// MC1
	rtd_outl(DC_PHY_Qos_ctl_0_reg, 0x00000401);
	rtd_outl(DC_PHY_Qos_ctl_8_reg, 0x08ff0076);
	rtd_outl(DC_PHY_ch0_ctl_0_reg, 0x0984080e);
	rtd_outl(DC_PHY_ch0_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC_PHY_ch0_ctl_2_reg, 0x0100108f);
	rtd_outl(DC_PHY_ch0_ctl_3_reg, 0x60010071);
	rtd_outl(DC_PHY_ch1_ctl_0_reg, 0x09840806);
	rtd_outl(DC_PHY_ch1_ctl_1_reg, 0x00006000);
	rtd_outl(DC_PHY_ch1_ctl_2_reg, 0x80018084);
	rtd_outl(DC_PHY_ch1_ctl_3_reg, 0x41010021);
	rtd_outl(DC_PHY_ch2_ctl_0_reg, 0x09840806);
	rtd_outl(DC_PHY_ch2_ctl_1_reg, 0x40005f00);
	rtd_outl(DC_PHY_ch2_ctl_2_reg, 0x12c18088);
	rtd_outl(DC_PHY_ch2_ctl_3_reg, 0x53015021);
	rtd_outl(DC_PHY_ch3_ctl_0_reg, 0x09840806);
	rtd_outl(DC_PHY_ch3_ctl_1_reg, 0x30005000);
	rtd_outl(DC_PHY_ch3_ctl_2_reg, 0x80018088);
	rtd_outl(DC_PHY_ch3_ctl_3_reg, 0x53013021);
	rtd_outl(DC_PHY_ch4_ctl_0_reg, 0x0984080e);
	rtd_outl(DC_PHY_ch4_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC_PHY_ch4_ctl_2_reg, 0x0300208f);
	rtd_outl(DC_PHY_ch4_ctl_3_reg, 0x60110071);
	rtd_outl(DC_PHY_ch5_ctl_0_reg, 0x0984080e);
	rtd_outl(DC_PHY_ch5_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC_PHY_ch5_ctl_2_reg, 0x0300208f);
	rtd_outl(DC_PHY_ch5_ctl_3_reg, 0x60110071);
	
#ifdef ENABLE_DC2_SUPPORT
	// MC2
	rtd_outl(DC2_PHY_Qos_ctl_0_reg, 0x00000001);
	rtd_outl(DC2_PHY_Qos_ctl_8_reg, 0x08ff0076);
	rtd_outl(DC2_PHY_ch0_ctl_0_reg, 0x0984080e);
	rtd_outl(DC2_PHY_ch0_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC2_PHY_ch0_ctl_2_reg, 0x0100108f);
	rtd_outl(DC2_PHY_ch0_ctl_3_reg, 0x60010071);
	rtd_outl(DC2_PHY_ch1_ctl_0_reg, 0x09840806);
	rtd_outl(DC2_PHY_ch1_ctl_1_reg, 0x00006000);
	rtd_outl(DC2_PHY_ch1_ctl_2_reg, 0x80018084);
	rtd_outl(DC2_PHY_ch1_ctl_3_reg, 0x41010021);
	rtd_outl(DC2_PHY_ch2_ctl_0_reg, 0x09840806);
	rtd_outl(DC2_PHY_ch2_ctl_1_reg, 0x40005f00);
	rtd_outl(DC2_PHY_ch2_ctl_2_reg, 0x12c18088);
	rtd_outl(DC2_PHY_ch2_ctl_3_reg, 0x53015021);
	rtd_outl(DC2_PHY_ch3_ctl_0_reg, 0x09840806);
	rtd_outl(DC2_PHY_ch3_ctl_1_reg, 0x30005000);
	rtd_outl(DC2_PHY_ch3_ctl_2_reg, 0x80018088);
	rtd_outl(DC2_PHY_ch3_ctl_3_reg, 0x53013021);
	rtd_outl(DC2_PHY_ch4_ctl_0_reg, 0x0984080e);
	rtd_outl(DC2_PHY_ch4_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC2_PHY_ch4_ctl_2_reg, 0x0300208f);
	rtd_outl(DC2_PHY_ch4_ctl_3_reg, 0x60110071);
	rtd_outl(DC2_PHY_ch5_ctl_0_reg, 0x0984080e);
	rtd_outl(DC2_PHY_ch5_ctl_1_reg, 0xff00ff00);
	rtd_outl(DC2_PHY_ch5_ctl_2_reg, 0x0300208f);
	rtd_outl(DC2_PHY_ch5_ctl_3_reg, 0x60110071);
#endif

	return 0;
}

int rtk_qos_set_mode(RTK_QOS_MODE_T qos_mode)
{
	if(g_rtk_qos_force_setting){
        pr_debug("[QOS] FORCE SETTING, IGNORE mode[%d]\n", qos_mode);
		return 0;
    }

	g_rtk_qos_current_setting = qos_mode;

	switch(qos_mode){
		case RTK_QOS_BOOT_MODE:
		case RTK_QOS_NORMAL_MODE:
			rtk_qos_load_mc_normal_setting();
			break;

		case RTK_QOS_DECODER_MODE:
			rtk_qos_load_mc_decoder_setting();
			break;

		case RTK_QOS_HDMI_4K_MODE:
			rtk_qos_load_mc_hdmi_4k_setting();
			break;

		case RTK_QOS_USER_A_MODE:
			rtk_qos_load_mc_user_a_setting();
			break;

		default:
			break;
	}

	return 0;
}

int rtk_qos_suspend(void)
{
	rtk_qos_load_mc_normal_setting();
	return 0;
}

int rtk_qos_resume(void)
{
	rtk_qos_save_mc_normal_setting();
	g_rtk_qos_force_setting = 0;
	return 0;
}

ssize_t rtk_qos_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	if(g_rtk_qos_force_setting == 0)
	{
		return sprintf(buf, "current is default setting mode(%d)\n", g_rtk_qos_current_setting);
	}
	else
	{
		if(g_rtk_qos_force_setting == RTK_QOS_NORMAL_MODE)
			return sprintf(buf, "current is force normal mode\n");
		else if(g_rtk_qos_force_setting == RTK_QOS_DECODER_MODE)
			return sprintf(buf, "current is force decode 1 mode\n");
		else if(g_rtk_qos_force_setting == RTK_QOS_HDMI_4K_MODE)
			return sprintf(buf, "current is force hdmi 1 mode\n");
		else if(g_rtk_qos_force_setting == RTK_QOS_USER_A_MODE)
			return sprintf(buf, "current is force user a mode\n");
	}

	return 0;
}

int rtk_qos_reset_all(void)
{
	g_rtk_qos_force_setting = 0;
	g_rtk_qos_current_setting = 0;
	rtk_qos_load_mc_normal_setting();
	return 0;
}

int rtk_qos_set_force_mode(unsigned char mode)
{
	g_rtk_qos_force_setting = mode;

	switch(mode) {
		case RTK_QOS_NORMAL_MODE:
			rtk_qos_load_mc_normal_setting();
			break;
		case RTK_QOS_DECODER_MODE:
			rtk_qos_load_mc_decoder_setting();
			break;
		case RTK_QOS_HDMI_4K_MODE:
			rtk_qos_load_mc_hdmi_4k_setting();
			break;
		case RTK_QOS_USER_A_MODE:
			rtk_qos_load_mc_user_a_setting();
			break;
		default:
			break;
	}

	return 0;
}

int rtk_qos_mc_measure(unsigned int client_id, unsigned int loop_cnt)
{
#define RTK_QOS_MC_MEASURE_1 0
#define RTK_QOS_MC_MEASURE_2 1
#define MC_BURST_LENGTH 16 /* 128 bits/8 = 16 bytes*/
#define MC_RECORD_NUMBER 8
#define MC_FRAME_RATE_SOURCE_CLK 27000000

	unsigned int i = 0, j = 0;
	unsigned int max_r_cnt[2] = {0};
	unsigned int max_w_cnt[2] = {0};
	unsigned int r_cnt[2] = {0};
	unsigned int w_cnt[2] = {0};
	unsigned int r_valid[2] = {0};
	unsigned int w_valid[2] = {0};
	unsigned int r_prev_cnt[2] = {0xFFFFFFFF, 0xFFFFFFFF};
	unsigned int w_prev_cnt[2] = {0xFFFFFFFF, 0xFFFFFFFF};
#ifdef MC_MEASURE_APPLY_SW_PATCH
	unsigned int tmp_cnt = 0;
	unsigned int tmp_threshold = 0;
#endif
	unsigned int timeout_cnt = 0;
	unsigned int ddomain_frame_rate = 0;

	ddomain_frame_rate = MC_FRAME_RATE_SOURCE_CLK / rtd_inl(0xb80282ec);

#ifdef ENABLE_DC2_SUPPORT
	pr_err("Client[%x] avg of 8 vsync record [MC1_R/MC1_W/MC2_R/MC2_W] (loop_cnt=%d, frame rate=%d)\n", client_id, loop_cnt, ddomain_frame_rate);
#else
	pr_err("Client[%x] avg of 8 vsync record [MC1_R/MC1_W] (loop_cnt=%d, frame rate=%d)\n", client_id, loop_cnt, ddomain_frame_rate);
#endif

	for (i = 0;i < loop_cnt;i++)
	{
		rtd_outl(DC_PHY_CLIENT_MEAS_0_reg, 0x1); // MC1 record enable
#ifdef ENABLE_DC2_SUPPORT
		rtd_outl(DC2_PHY_CLIENT_MEAS_0_reg, 0x1); // MC2 record enable
#endif
		while(1){
			if (rtd_inl(DC_PHY_CLIENT_MEAS_0_reg) == 0x0) // wait record done
			{
#ifdef ENABLE_DC2_SUPPORT
				if (rtd_inl(DC2_PHY_CLIENT_MEAS_0_reg) == 0x0)
#endif
				{
					timeout_cnt = 0;
					break;
				}
			}

			msleep(10);
			timeout_cnt++;
			if (timeout_cnt > 0x8000000){
				pr_err("[ERROR] Wait mc measure dont bit timeout\n");
				return 0;
			}
		}

		r_cnt[RTK_QOS_MC_MEASURE_1] = 0;
		w_cnt[RTK_QOS_MC_MEASURE_1] = 0;
#ifdef ENABLE_DC2_SUPPORT
		r_cnt[RTK_QOS_MC_MEASURE_2] = 0;
		w_cnt[RTK_QOS_MC_MEASURE_2] = 0;
#endif

		r_prev_cnt[RTK_QOS_MC_MEASURE_1] = 0xFFFFFFFF;
		w_prev_cnt[RTK_QOS_MC_MEASURE_1] = 0xFFFFFFFF;
#ifdef ENABLE_DC2_SUPPORT
		r_prev_cnt[RTK_QOS_MC_MEASURE_2] = 0xFFFFFFFF;
		w_prev_cnt[RTK_QOS_MC_MEASURE_2] = 0xFFFFFFFF;
#endif

		r_valid[RTK_QOS_MC_MEASURE_1] = 0;
		w_valid[RTK_QOS_MC_MEASURE_1] = 0;
#ifdef ENABLE_DC2_SUPPORT
		r_valid[RTK_QOS_MC_MEASURE_2] = 0;
		w_valid[RTK_QOS_MC_MEASURE_2] = 0;
#endif

		// sum of 8 record
		for (j = 0;j < MC_RECORD_NUMBER;j++)
		{
#ifdef MC_MEASURE_APPLY_SW_PATCH
			rtd_outl(DC_PHY_CLIENT_MEAS_1_reg, ((j & 0x7) << 8) | client_id); // record << 8 | client_id

			tmp_cnt = rtd_inl(DC_PHY_CLIENT_MEAS_2_reg); // meas_read_cnt

			if (j == 0) // first record is always safe
				tmp_threshold = 0;
			else // compute the threshold
				tmp_threshold = (r_prev_cnt[RTK_QOS_MC_MEASURE_1] * MC_MEASURE_PATCH_NUMERATOR) / MC_MEASURE_PATCH_DENOMINATOR;

			if ((tmp_threshold == 0) || (tmp_cnt <= (r_prev_cnt[RTK_QOS_MC_MEASURE_1] + tmp_threshold)))
			{
				r_cnt[RTK_QOS_MC_MEASURE_1] += tmp_cnt;
				r_valid[RTK_QOS_MC_MEASURE_1]++;
				r_prev_cnt[RTK_QOS_MC_MEASURE_1] = tmp_cnt;
			}

			tmp_cnt = rtd_inl(DC_PHY_CLIENT_MEAS_3_reg); // meas_write_cnt

			if (j == 0) // first record is always safe
				tmp_threshold = 0;
			else // compute the threshold
				tmp_threshold = (w_prev_cnt[RTK_QOS_MC_MEASURE_1] * MC_MEASURE_PATCH_NUMERATOR) / MC_MEASURE_PATCH_DENOMINATOR;

			if ((tmp_threshold == 0) || (tmp_cnt <= (w_prev_cnt[RTK_QOS_MC_MEASURE_1] + tmp_threshold)))
			{
				w_cnt[RTK_QOS_MC_MEASURE_1] += tmp_cnt;
				w_valid[RTK_QOS_MC_MEASURE_1]++;
				w_prev_cnt[RTK_QOS_MC_MEASURE_1] = tmp_cnt;
			}
#else
			rtd_outl(DC_PHY_CLIENT_MEAS_1_reg, ((j & 0x7) << 8) | client_id); // record << 8 | client_id

			r_cnt[RTK_QOS_MC_MEASURE_1] += rtd_inl(DC_PHY_CLIENT_MEAS_2_reg); // meas_read_cnt
			r_valid[RTK_QOS_MC_MEASURE_1]++;

			w_cnt[RTK_QOS_MC_MEASURE_1] += rtd_inl(DC_PHY_CLIENT_MEAS_3_reg); // meas_write_cnt
			w_valid[RTK_QOS_MC_MEASURE_1]++;
#endif

#ifdef ENABLE_DC2_SUPPORT
#ifdef MC_MEASURE_APPLY_SW_PATCH
			rtd_outl(DC2_PHY_CLIENT_MEAS_1, ((j & 0x7) << 8) | client_id); // record << 8 | client_id

			tmp_cnt = rtd_inl(DC2_PHY_CLIENT_MEAS_2); // meas_read_cnt

			if (j == 0) // first record is always safe
				tmp_threshold = 0;
			else // compute the threshold
				tmp_threshold = (r_prev_cnt[RTK_QOS_MC_MEASURE_2] * MC_MEASURE_PATCH_NUMERATOR) / MC_MEASURE_PATCH_DENOMINATOR;

			if ((tmp_threshold == 0) || (tmp_cnt <= (r_prev_cnt[RTK_QOS_MC_MEASURE_2] + tmp_threshold)))
			{
				r_cnt[RTK_QOS_MC_MEASURE_2] += tmp_cnt;
				r_valid[RTK_QOS_MC_MEASURE_2]++;
				r_prev_cnt[RTK_QOS_MC_MEASURE_2] = tmp_cnt;
			}

			tmp_cnt = rtd_inl(DC2_PHY_CLIENT_MEAS_3); // meas_write_cnt

			if (j == 0) // first record is always safe
				tmp_threshold = 0;
			else // compute the threshold
				tmp_threshold = (w_prev_cnt[RTK_QOS_MC_MEASURE_2] * MC_MEASURE_PATCH_NUMERATOR) / MC_MEASURE_PATCH_DENOMINATOR;

			if (tmp_cnt <= w_prev_cnt[RTK_QOS_MC_MEASURE_2])
			{
				w_cnt[RTK_QOS_MC_MEASURE_2] += tmp_cnt;
				w_valid[RTK_QOS_MC_MEASURE_2]++;
				w_prev_cnt[RTK_QOS_MC_MEASURE_2] = tmp_cnt;
			}
		
#else
			rtd_outl(DC2_PHY_CLIENT_MEAS_1, ((j & 0x7) << 8) | client_id); // record << 8 | client_id

			r_cnt[RTK_QOS_MC_MEASURE_2] += rtd_inl(DC2_PHY_CLIENT_MEAS_2); // meas_read_cnt
			r_valid[RTK_QOS_MC_MEASURE_2]++;

			w_cnt[RTK_QOS_MC_MEASURE_2] += rtd_inl(DC2_PHY_CLIENT_MEAS_3); // meas_write_cnt
			w_valid[RTK_QOS_MC_MEASURE_2]++;
#endif
#endif
		}

		// compute the real count
		if (r_valid[RTK_QOS_MC_MEASURE_1] != 0)
			r_cnt[RTK_QOS_MC_MEASURE_1] /= r_valid[RTK_QOS_MC_MEASURE_1];

		if (w_valid[RTK_QOS_MC_MEASURE_1] != 0)
			w_cnt[RTK_QOS_MC_MEASURE_1] /= w_valid[RTK_QOS_MC_MEASURE_1];
#ifdef ENABLE_DC2_SUPPORT
		if (r_valid[RTK_QOS_MC_MEASURE_2] != 0)
			r_cnt[RTK_QOS_MC_MEASURE_2] /= r_valid[RTK_QOS_MC_MEASURE_2];

		if (w_valid[RTK_QOS_MC_MEASURE_2] != 0)
			w_cnt[RTK_QOS_MC_MEASURE_2] /= w_valid[RTK_QOS_MC_MEASURE_2];
#endif
		// save the max value
		if (r_cnt[RTK_QOS_MC_MEASURE_1] > max_r_cnt[RTK_QOS_MC_MEASURE_1])
			max_r_cnt[RTK_QOS_MC_MEASURE_1] = r_cnt[RTK_QOS_MC_MEASURE_1];

		if (w_cnt[RTK_QOS_MC_MEASURE_1] > max_w_cnt[RTK_QOS_MC_MEASURE_1])
			max_w_cnt[RTK_QOS_MC_MEASURE_1] = w_cnt[RTK_QOS_MC_MEASURE_1];
#ifdef ENABLE_DC2_SUPPORT
		if (r_cnt[RTK_QOS_MC_MEASURE_2] > max_r_cnt[RTK_QOS_MC_MEASURE_2])
			max_r_cnt[RTK_QOS_MC_MEASURE_2] = r_cnt[RTK_QOS_MC_MEASURE_2];

		if (w_cnt[RTK_QOS_MC_MEASURE_2] > max_w_cnt[RTK_QOS_MC_MEASURE_2])
			max_w_cnt[RTK_QOS_MC_MEASURE_2] = w_cnt[RTK_QOS_MC_MEASURE_2];
#endif
		pr_err("Client[%x][%5d] => [MC1] %6d %6d => ",
			client_id,
			i,
			r_cnt[RTK_QOS_MC_MEASURE_1],
			w_cnt[RTK_QOS_MC_MEASURE_1]
		);

		pr_err("%4d MB/s %4d MB/s\n",
			r_cnt[RTK_QOS_MC_MEASURE_1]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000,
			w_cnt[RTK_QOS_MC_MEASURE_1]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000
		);

#ifdef ENABLE_DC2_SUPPORT
		pr_err("Client[%x][%5d] => [MC2] %6d %6d => ",
			client_id,
			i,
			r_cnt[RTK_QOS_MC_MEASURE_2],
			w_cnt[RTK_QOS_MC_MEASURE_2]
		);

		pr_err("%4d MB/s %4d MB/s\n",
			r_cnt[RTK_QOS_MC_MEASURE_2]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000,
			w_cnt[RTK_QOS_MC_MEASURE_2]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000
		);

#endif
	}

	pr_err("[Client:%x][MC1 Max] === r:%4d MB/s w:%4d MB/s ===\n",
		client_id,
		max_r_cnt[RTK_QOS_MC_MEASURE_1]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000,
		max_w_cnt[RTK_QOS_MC_MEASURE_1]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000
	);

#ifdef ENABLE_DC2_SUPPORT
	pr_err("[Client:%x][MC2 Max] === r:%4d MB/s w:%4d MB/s ===\n",
		client_id,
		max_r_cnt[RTK_QOS_MC_MEASURE_2]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000,
		max_w_cnt[RTK_QOS_MC_MEASURE_2]*MC_BURST_LENGTH*ddomain_frame_rate/1000/1000
	);
#endif

	return 0;
}

static int rtk_qos_mode_parsing(const char *buf)
{
	char *mode;
	unsigned int client_id;
	unsigned int loop_cnt;
	int ret = -1; // error

	if(buf==NULL) {
		pr_notice("rtk_qos_mode_parsing param buf is null\n");
		return -1;
	}

	mode = strstr(buf, "@");

	if (buf != NULL)
	{
		if (strncmp(buf, "meas", 4) == 0)
		{
			if (mode != NULL)
			{
				sscanf(mode+1, "%x", &client_id);
				mode = strstr(mode+1, ",");
				if (mode != NULL)
				{
					sscanf(mode+1, "%d", &loop_cnt);
					rtk_qos_mc_measure(client_id, loop_cnt);
				}
				else
				{
					rtk_qos_mc_measure(client_id, 100);
				}
			}
			ret = 0x80; // measure
		}
		else if (strncmp(buf, "reset", 5) == 0)
		{
			return 0; // reset 
		}
		else if (strncmp(buf, "set", 3) == 0)
		{
			if (mode != NULL)
			{
				mode++;
				if (strncmp(mode, "normal", 6) == 0)
				{
					return RTK_QOS_NORMAL_MODE; // normal mode
				}
				else if (strncmp(mode, "decode_1", 8) == 0)
				{
					return RTK_QOS_DECODER_MODE; // decode mode
				}
				else if (strncmp(mode, "hdmi_1", 6) == 0)
				{
					return RTK_QOS_HDMI_4K_MODE; // hdmi_4k mode
				}
				else if (strncmp(mode, "user_a", 6) == 0)
				{
					return RTK_QOS_USER_A_MODE; // user_a mode
				}
			}
			else
			{
				ret = -1; // error
			}
		}
		else
		{
			ret = -1; // error
		}
	}

	if (ret == -1)
	{
		pr_err("[ERROR] This is a wrong command!\nPlease input [set|reset|meas]@[normal|decode_1|hdmi_1|user_a...],[...]\n");
	}

	return ret;
}

ssize_t rtk_qos_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
	int ret, mode=0;

	mode = rtk_qos_mode_parsing(buf);

	switch (mode) {
		case -1: // error
		case 0x80: // measure
			// do nothing here
			break;
		case 0: // reset
			ret = rtk_qos_reset_all();
			break;
		default: // other QoS mode
			ret = rtk_qos_set_force_mode(mode);
			break;
	}

	return count;
}

static int __init rtk_qos_init(void)
{
	//int ret;

	rtk_qos_save_mc_normal_setting(); // save initial bandwidth setting.

	return 0;
}

late_initcall(rtk_qos_init);
EXPORT_SYMBOL(rtk_qos_set_mode);

