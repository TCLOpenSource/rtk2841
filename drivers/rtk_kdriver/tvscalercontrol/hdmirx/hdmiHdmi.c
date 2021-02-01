/*=============================================================
 * Copyright (c)      Realtek Semiconductor Corporation, 2016
 *
 * All rights reserved.
 *
 *============================================================*/

/*======================= Description ============================
 *
 * file: 		hdmiHdmi.c
 *
 * author: 	Captain America, Steve Rogers
 * date:
 * version: 	3.0
 *
 *============================================================*/

/*========================Header Files============================*/


#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/module.h>
#include <linux/fs.h>		/* everything... */
#include <linux/cdev.h>
#include <linux/platform_device.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <linux/sched.h>
#include <linux/sched/rt.h>
#include <linux/kthread.h>
#include <linux/string.h>/*memset*/
#include <rtk_kdriver/RPCDriver.h>
#include <mach/rtk_platform.h>
#include "hdmi_common.h"
#include "hdmi_edid.h"

#if MHL_SUPPORT
#include "mhl_driver.h"
#endif


extern unsigned char board_hdmi_drv_port_mapping(unsigned char port);
extern unsigned char board_hdmi_drv_port_mapping_to_UI(unsigned char hw_port);



/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/
#define CLK_STABLE_CNT			8// 2  [WOSQRTK-8394 -Green transient appears - SONY S570/S470]
#define TMDS_CLOCK_TOLERANCE(port)	MAX(hdmi_rx[port].timing_t.tmds_clk_b>>7, 5)     // 6G tolerance should be larger
#define NO_INFO_MAX			6
#define HDCP_RESET_CNT			30     //The counter for keeping HDCP 1.4 or 2.2 in no signal state, if timeout, turn on both 1.4 & 2.2



#define	HDCP_10_DVI 	0x91
#define	HDCP_11_HDMI 	0x93

#define _AUDIO_128_TIMES        1
#define _AUDIO_256_TIMES        2




/**********************************************************************************************
*
*	Const Declarations
*
**********************************************************************************************/
const VIDEO_DPLL_RATIO_T dpll_ratio[] = {

	{ 	15, 15, 	1, 1	},	// 24 bits
	{ 	12, 15, 	4, 5	},	// 30 bits
	{ 	10, 15, 	2, 3	},	// 36 bits
	{ 	15, 30, 	1, 2	},	// 48 bits
};


HDMI_CONST VIDEO_DPLL_FIX_T video_pll_main_param[]=
{
	{30 ,0,0b010,0b100},
	{62,3,0b010,0b111},
	{30,1,0b010,0b100},
	{6,0,0b000,0b100},
	{14,3,0b001,0b101},
	{6,1,0b000,0b100},
	{6,2,0b000,0b100},
	{6,3,0b000,0b100},
	{6,4,0b000,0b100},
	{6,6,0b000,0b100},
};



HDMI_CONST VIDEO_DPLL_RANGE_T video_pll_others_param[]=
{
	{6 ,10,0b000,0b100},
	{11,18,0b000,0b111},
	{19,30,0b001,0b110},
	{31,48,0b010,0b110},
};


HDMI_CONST HDMI_AUDIO_PLL_COEFF_T audio_pll_coeff[] = {
	{ 32000, _AUDIO_256_TIMES, 0},
	{ 44100, _AUDIO_256_TIMES, 0},
	{ 48000, _AUDIO_256_TIMES, 0},
	{ 88200, _AUDIO_256_TIMES, 1},
	{ 96000, _AUDIO_256_TIMES, 1},
	{ 176400, _AUDIO_128_TIMES, 2},
	{ 192000, _AUDIO_128_TIMES, 3}
};

HDMI_CONST HDMI_AUDIO_PLL_PARAM_T hdmi_audiopll_param[] = {

	{ 2,   20,  2,  8,  1,  0x1D, 0xDC,  "32K"     },//0x1E, 0xB0
	//{ 2,   20,  2,  6,  1,  0xFE, 0x7A,  "44.1K"  },//0xFC, 0x68
	{ 2,   20,  2,  6,  1,  0xFC, 0x68,  "44.1K"  },//GIGABYTE GA-H55N-USB3, Geforce GTX560 Ti-ASUS
	{ 2,   22,  2,  6,  1,  0x07, 0x40,  "48K"     },
	{ 2,   20,  1,  6,  1,  0xFE, 0x7A,  "88.2K"  },
	{ 2,   22,  1,  6,  1,  0x07, 0x40,  "96K"     },
	{ 2,   20,  1,  6,  0,  0xFE, 0x7A,  "176.4K" },
	{ 2,   22,  1,  6,  0,  0x07, 0x40,  "192K"    }

};

HDMI_CONST unsigned int AUDIO_CHANNEL_STATUS[] = {
	44100,
	0,				   // 000 indicate standard no support
	48000,
	32000,
	22000,
	0,
	24000,
	0,
	88200,
	0,
	96000,
	0,
	176400,   // cloud modify trend bound cal wrong value use reg value
	0,
	192000,
	0,
};


const char *colormetry_name[]  = {

	"HDMI_COLORIMETRY_NOSPECIFIED",
	"HDMI_COLORIMETRY_601",
	"HDMI_COLORIMETRY_709",
	"HDMI_COLORIMETRY_XYYCC601",
	"HDMI_COLORIMETRY_XYYCC709",
	"HDMI_COLORIMETRY_SYCC601",
	"HDMI_COLORIMETRY_ADOBE_YCC601",
	"HDMI_COLORIMETRY_ADOBE_RGB",

};

const char *depth_name[] = {

	"HDMI_COLOR_DEPTH_8B",
	"HDMI_COLOR_DEPTH_10B",
	"HDMI_COLOR_DEPTH_12B",
	"HDMI_COLOR_DEPTH_16B",

};

const char* _hdmi_color_depth_str(unsigned char depth)
{
    return (depth < sizeof(depth_name)/sizeof(char*)) ? depth_name[depth] : "Unknown";
}

const char *colorspace_name[] = {
	"COLOR_RGB",
	"COLOR_YUV422",
	"COLOR_YUV444",
	"COLOR_YUV420",
	"COLOR_UNKNOW"
};

const char* _hdmi_color_space_str(unsigned char color_space)
{
    if (color_space >= sizeof(colorspace_name)/sizeof(char*))
        color_space =  sizeof(colorspace_name)/sizeof(char*)-1;  // force to unknow

    return colorspace_name[color_space];
}

const char *hdmi_3d_name[] = {
	"HDMI3D_FRAME_PACKING",
	"HDMI3D_FIELD_ALTERNATIVE",
	"HDMI3D_LINE_ALTERNATIVE",
	"HDMI3D_SIDE_BY_SIDE_FULL",
	"HDMI3D_L_DEPTH",

	"HDMI3D_L_DEPTH_GPX",
	"HDMI3D_TOP_AND_BOTTOM",
	"HDMI3D_RSV0",
	"HDMI3D_SIDE_BY_SIDE_HALF",
	"HDMI3D_LINE_BY_LINE",

	"HDMI3D_VERTICAL_STRIPE",
	"HDMI3D_CHECKER_BOARD",
	"HDMI3D_REALID",
	"HDMI3D_SENSIO",
	"HDMI3D_RSV1",

	"HDMI3D_2D_ONLY",
};





/**********************************************************************************************
*
*	Variables
*
**********************************************************************************************/
HDMI_PORT_INFO_T	hdmi_rx[HDMI_RX_PORT_MAX_NUM];
HDMI_CHANNEL_T		pcb_info[HDMI_RX_PORT_MAX_NUM];
HDCP_KEY_T		hdcpkey;
unsigned char		mhl_edid_table[256];
unsigned char 		current_port = 0;

//unsigned int 		hpd_low_ms = 100; //default value (+ resume already had 500ms low)
unsigned int 		hpd_low_ms = HPD_DEFAULT_LOW_MS; //default value (+ resume already had 500ms low)
unsigned int 		hpd_target_ch = 0xff;
//unsigned int 		hpd_low_is_running = 0;

#if 0 //STABLE_CHECK_OLD_PATCH
static unsigned int bNeedDebBeforeDisp = 0;
static unsigned int DispDebCnt = 0;
static unsigned int DispDebCondition = 0;
#endif

#if AUDIO_THREAD_MODIFY
unsigned char audio_thread_run[HDMI_RX_PORT_MAX_NUM] = {0};
#endif //#if AUDIO_THREAD_MODIFY

#if HDMI_TOGGLE_HPD_Z0_ENABLE
unsigned char hdmi_toggle_hpd_z0_flag[HDMI_RX_PORT_MAX_NUM] = {0};
HDMI_DC_ON_STATE_E hdmi_dc_on_delay_state[HDMI_RX_PORT_MAX_NUM] = {HDMI_DC_ON_NONE};
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

#if HDMI_STR_TOGGLE_HPD_ENABLE
HDMI_STR_HPD_TOGGLE_STATE_E hdmi_str_toggle_hpd_state[HDMI_RX_PORT_MAX_NUM] = {HDMI_STR_HPD_TOGGLE_NONE};
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE

#if HDMI_DISPLAY_DELAY_ENABLE
unsigned char hdmi_delay_display_enable[HDMI_RX_PORT_MAX_NUM] = {_DISABLE};
HDMI_DISPLAY_DELAY_STATE_STATE_E hdmi_delay_display_state[HDMI_RX_PORT_MAX_NUM] = {HDMI_DISPLAY_DELAY_NONE};
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

#if 1 //#if HDMI_DISPLAY_DELAY_ENABLE
HDMI_SPECIFIC_DEVICE_E hdmi_specific_device[HDMI_RX_PORT_MAX_NUM] = {HDMI_SPECIFIC_DEVICE_NONE};
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

#if HDCP_STATUS_CHECK_ENABLE
HDMI_HDCP_TOGGLE_STATUS_T	hdmi_hdcp_check_toggle_state[HDMI_RX_PORT_MAX_NUM] = {HDMI_HDCP_TOGGLE_NONE};
#endif //#if HDCP_STATUS_CHECK_ENABLE

unsigned char customer_hdcp1p4= false;
unsigned char customer_hdcp2p2= false;
extern unsigned char* h2p2table=NULL;
/**********************************************************************************************
*
*	Funtion Declarations
*
**********************************************************************************************/

void newbase_hdmi_edid_init(void);
void newbase_hdmi_hdcp_init(void);


void newbase_hdmi_fix_green_line(unsigned char nport);
void newbase_hdmi_set_scaler_info(HDMI_TIMING_T *timing);

void newbase_hdmi_hpd_delay_work_func(void);


unsigned char newbase_hdmi_update_vsi(unsigned char port);
unsigned char newbase_hdmi_update_avi(unsigned char nport);
unsigned char newbase_hdmi_update_spd(unsigned char port);
unsigned char newbase_hdmi_update_audiopkt(unsigned char port);
unsigned char newbase_hdmi_update_drm(unsigned char port);
unsigned char newbase_hdmi_update_rsv0_packet(unsigned char port, unsigned char len, unsigned char *buf);
unsigned char newbase_hdmi_update_rsv1_packet(unsigned char port, unsigned char len, unsigned char *buf);
unsigned char newbase_hdmi_update_rsv2_packet(unsigned char port, unsigned char len, unsigned char *buf);
unsigned char newbase_hdmi_update_rsv3_packet(unsigned char port, unsigned char len, unsigned char *buf);
unsigned char newbase_hdmi_check_spd_name(unsigned char port, unsigned char *vendor_name);
unsigned char newbase_hdmi_check_spd_prod(unsigned char port, unsigned char *prod_desc);
unsigned char newbase_hdmi_check_aksv(unsigned char port, unsigned char *aksv);

unsigned char newbase_hdmi_compatibility_check(unsigned char port);
unsigned char newbase_hdmi_check_avi_colorimetry_info(unsigned char port, unsigned char ucInit);
unsigned char newbase_hdmi_no_SPD_packetInfo(unsigned char nport);
//STABLE_CHECK_OLD_PATCH- unsigned char newbase_hdmi_check_deb_condition_beforeDisp(unsigned char nport, unsigned char ucInit);
unsigned char newbase_hdmi_check_hdcp_condition(unsigned char nport, unsigned char ucInit);

#if AUDIO_THREAD_MODIFY
unsigned char lib_hdmi_audio_get_thread_run(unsigned char nport);
void lib_hdmi_audio_set_thread_run(unsigned char nport, unsigned char uc_run);
#endif //#if AUDIO_THREAD_MODIFY





/**********************************************************************************************
*
*	Function Body
*
**********************************************************************************************/


HDMI_CHANNEL_T*  newbase_hdmi_get_pcbinfo(unsigned int port)
{
	return (port < HDMI_RX_PORT_MAX_NUM) ? &pcb_info[port] : NULL;
}

void newbase_hdmi_save_pcbinfo(unsigned char port, const HDMI_CHANNEL_T_PCB_INFO *pcb)
{
	HDMI_CHANNEL_T* p_ch = newbase_hdmi_get_pcbinfo(port);

	if (p_ch==NULL) {
		HDMI_EMG("%s failed, port %d doesn't exist\n", __FUNCTION__ , port);
		return ;
	}
	
	p_ch->phy_port     = pcb->phy_port;
	p_ch->ddc_selected = pcb->ddc_selected;	
	p_ch->edid_type    = pcb->edid_type;
	p_ch->hpd          = pcb->hpd;	
	p_ch->det_5v       = pcb->det_5v;	    
}

unsigned char newbase_hdmi_phy_port_status(unsigned char port)
{
	return (port < HDMI_RX_PORT_MAX_NUM) ? pcb_info[port].phy_port : HDMI_PHY_PORT_NOTUSED;
}

int newbase_hdmi_ddc_channel_status(unsigned char port)
{
	return (port < HDMI_RX_PORT_MAX_NUM) ? pcb_info[port].ddc_selected : -1;
}

void newbase_hdmi_save_edid(unsigned char port, const unsigned char *edid, const unsigned int len)
{
	HDMI_CHANNEL_T* p_ch = newbase_hdmi_get_pcbinfo(port);
	
	if (p_ch==NULL) {
		HDMI_EMG("%s failed, port %d doesn't exist\n", __FUNCTION__ , port);
		return ;
	}		
	
	memcpy(p_ch->edid_table, edid, len);
	
	p_ch->edid_initialized = 1;
	
	HDMI_EMG("Customer EDID:%02x,%02x,%02x,%02x,%02x,port=%d\n", 
	    p_ch->edid_table[0], p_ch->edid_table[1], 
	    p_ch->edid_table[2], p_ch->edid_table[128], 
	    p_ch->edid_table[255], port);
}


int newbase_hdmi_edid_initialized(unsigned char port)
{
	HDMI_CHANNEL_T* p_ch = newbase_hdmi_get_pcbinfo(port);
	
	if (p_ch==NULL) {
		HDMI_EMG("%s failed, port %d doesn't exist\n", __FUNCTION__ , port);
		return 0;
	}		
	
	return (p_ch->edid_initialized) ? 1 : 0;
}



void newbase_hdmi_init(void)
{
	unsigned char j;

	HDMI_PRINTF("%s\n", __func__);

	lib_hdmi_crt_on();
	lib_hdmiddc_crt_on();
	lib_hdmi_reg_init();

	for (j=0; j<HDMI_RX_PORT_MAX_NUM; j++)
	{
		unsigned int ddc_ch;
		
		if (newbase_hdmi_phy_port_status(j)==HDMI_PHY_PORT_NOTUSED)
			continue;

		newbase_hdmi_set_hpd(j, 0, INIT_HPD_OFF);
		lib_hdmi_power(j, 0);
		
		ddc_ch = newbase_hdmi_ddc_channel_status(j);
		if (ddc_ch < 0)
			continue;
		
		lib_hdmiddc_sda2gpio(ddc_ch);
		lib_hdmi_ddc_sel(j, ddc_ch);
		lib_hdmiddc_set_sda_delay(ddc_ch, 0x1); //K2L, one NB no audio, due to IIC issue. Q2879/3094/3222
		lib_hdmiddc_sda_dir_out(ddc_ch, 0x1);  //Q9305: first plug in, no tx_clk in due to IIC issue.
		lib_hdmiddc_gpio2sda(ddc_ch);

		newbase_hdmi_check_hdcp_condition(j, _TRUE);
	}

	newbase_hdmi_edid_init();
	newbase_hdmi_hdcp_init();

	newbase_hdmi_clear_table();
	lib_hdmi_phy_init();

#if MHL_SUPPORT
	CBUS_InitialPHYSettings();
	MHLInitialMACSettings();
	MHLTmdsInitial();
	CBUSLINKClk(0);
#endif

	newbase_hdmi_port_var_init_all();

	HDMI_SMPHR_DETECT_INIT();
	HDMI_SMPHR_INFOPKT_INIT();

	HDMI_ISR_THREAD(1);
	HDMI_INFOPKT_THREAD(1);
#if AUDIO_THREAD_MODIFY
	HDMI_AUDIO_THREAD(1);
#endif //#if AUDIO_THREAD_MODIFY
}

void newbase_hdmi_uninit(void)
{
	HDMI_WQ_HPD_DESTROY();

	HDMI_ISR_THREAD(0);
	HDMI_INFOPKT_THREAD(0);
#if AUDIO_THREAD_MODIFY
	HDMI_AUDIO_THREAD(0);
#endif //#if AUDIO_THREAD_MODIFY
}

void newbase_hdmi_init_source(unsigned char port)
{
	if (newbase_hdmi_phy_port_status(port) == HDMI_PHY_PORT_NOTUSED)
	{
		HDMI_EMG("This channel %d is Disable\n", port);
		return;
	}

	HDMI_PRINTF("%s[port%d]\n", __func__, port);

	lib_hdmi_crt_on();

	//newbase_hdmi_port_select(port);
	lib_hdmi_power(port, 1);
	lib_hdmi_tmds_init(port);
	lib_hdmi_mac_init(port);	//need to check: move to newbase_drvif_hdmi_Init, ok?

	newbase_hdmi_port_var_init(port);
	newbase_hdmi_audio_close(port);

	newbase_hdmi_set_hpd(port , 1, INITSRC_HPD_ON);
	// LG webos cannot set hpd high here.
	// LG webos will call write edid & hpd high by himself later.

	newbase_rxphy_init_struct(port);
	newbase_rxphy_isr_set(port, 1);

	lib_hdmi_misc_variable_initial(port);
}

void newbase_hdmi_release_source(unsigned char port)
{

	if (port >= HDMI_RX_PORT_MAX_NUM)  {
		HDMI_EMG("%s: err port=%d\n", __func__, port);
		return;
	}

#if MHL_SUPPORT
	if (MHL_CHANNEL == port) {
		mhl_release();
	}
#endif

	newbase_rxphy_isr_set(port, 0);
	lib_hdmi_power(port, 0);

	newbase_hdmi_disconnect_source(port);
	HDMI_WQ_HPD_CANCEL();
}

void newbase_hdmi_disconnect_source(unsigned char port)
{	// keep PHY_ISR in active, keep power on

	lib_hdmi_video_output(port, 0);  // blanking screen in step 1.
	newbase_hdmi_port_var_init(port);

	lib_hdmi_video_output(port, 0); //close again, avoid re-open in detect_mode
	newbase_hdmi_audio_close(port);

#ifdef HDMI_VIDEO_WD_ENABLE
	newbase_hdmi_watchdog_apply(_DISABLE, HDMI_WD_ALL_COND);
#endif //#ifdef HDMI_VIDEO_WD_ENABLE

}

void newbase_hdmi_port_select(unsigned char port)	// reset all mac functions
{
	lib_hdmi_mac_select_port(port);
	lib_hdmi_video_output(port, 0);
	newbase_hdmi_set_current_display_port(port);
}

void newbase_hdmi_port_var_init_all(void)
{
	unsigned char i;
	for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++)
	{
		newbase_hdmi_port_var_init(i);
	}
}

unsigned char first_time_detect=1;
void newbase_hdmi_port_var_init(unsigned char port)
{
	memset(&hdmi_rx[port], 0, sizeof(HDMI_PORT_INFO_T));

	SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
	SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);

	SET_H_INTERLACE(port, 0);
	SET_H_MODE(port, MODE_HDMI);
	SET_H_COLOR_DEPTH(port, HDMI_COLOR_DEPTH_8B);
	SET_H_COLOR_SPACE(port, COLOR_RGB);

	SET_H_3DFORMAT(port, HDMI3D_2D_ONLY);

	newbase_hdcp_init_timer(port);

	newbase_hdmi_audio_var_init(port);
	first_time_detect=1;
}


void newbase_hdmi_edid_init(void)
{
	unsigned char j;

	for (j=0; j<HDMI_RX_PORT_MAX_NUM; j++)
	{
		HDMI_CHANNEL_T* p_ch = newbase_hdmi_get_pcbinfo(j);

		if (p_ch == NULL || p_ch->phy_port == HDMI_PHY_PORT_NOTUSED)  
		{
			HDMI_EMG("%s: init port %d failed - port not used, skip it\n", __func__, j);
			continue;
		}
		
		HDMI_INFO("edid_init EDID:%02x,%02x,%02x,%02x,%02x,Port=%d\n",
			p_ch->edid_table[0], p_ch->edid_table[1], p_ch->edid_table[2],
			p_ch->edid_table[128], p_ch->edid_table[255], j);
			
		newbase_hdmi_write_edid(p_ch->ddc_selected, p_ch->edid_table, 256);

		if (p_ch->edid_type == HDMI_EDID_ONCHIP)
			newbase_hdmi_edid_enable(p_ch->ddc_selected, 1);
	}

#if MHL_SUPPORT
	newbase_hdmi_mhl_write_edid(mhl_edid_table, 256);
	newbase_hdmi_mhl_edid_enable(1);
#endif
}

void newbase_hdmi_hdcp_init(void)
{
	unsigned char j;

#if defined(CONFIG_RTK_KDRV_HDCP_KEY_FROM_OTP)
	unsigned char hdcp14_buf[325];
	if (get_hdcp_14_otp(hdcp14_buf, 325) == 0) {
		HDMI_PRINTF("[HDCP] HDCP1.4 OTP-KEY  OK\n");
		memcpy(hdcpkey.BKsv , hdcp14_buf,5);
		memcpy(hdcpkey.Key , hdcp14_buf+5, 320);
	} else {
		HDMI_EMG("[HDCP] NO HDCP1.4 OTP-KEY\n");
	        if(customer_hdcp1p4)
		{
			HDMI_EMG("[HDCP] Using Customer HDCP1.4 KEY\n");
		}
	}
#else
	HDMI_EMG("[HDCP] NO HDCP1.4 OTP-KEY (UNDEFINED)\n");
	if(customer_hdcp1p4)
	{
	        HDMI_EMG("[HDCP] Using Customer HDCP1.4 KEY\n");
	}
#endif // CONFIG_RTK_KDRV_HDCP_KEY_FROM_OTP

	for (j=0; j<HDMI_RX_PORT_MAX_NUM; j++)
	{
		if (newbase_hdmi_phy_port_status(j)==HDMI_PHY_PORT_NOTUSED)
			continue;	

		lib_hdmi_hdcp_init(j);
	}

	newbase_hdmi_write_hdcp14_key(hdcpkey.BKsv, hdcpkey.Key);

#if HDCP2_2
	for (j=0; j<HDMI_RX_PORT_MAX_NUM; j++) {
		if (newbase_hdmi_phy_port_status(j) == HDMI_PHY_PORT_NOTUSED)
			continue;
		#ifndef CONFIG_CUSTOMER_TV030
		lib_hdmi_hdcp22_init(j);
		#endif
	}
#endif
}



const char* _hdmi_video_fsm_str(unsigned int fsm)
{
    switch (fsm) {
    case MAIN_FSM_HDMI_WAIT_SYNC:       return "WAIT_SYNC";
    case MAIN_FSM_HDMI_SETUP_VEDIO_PLL: return "SETUP_VEDIO_PLL";
    case MAIN_FSM_HDMI_MEASURE:         return "MEASURE";		
    case MAIN_FSM_HDMI_DISPLAY_ON:      return "DISPLAY_ON";					
    case MAIN_FSM_HDMI_VIDEO_READY:     return "VIDEO_READY";			
    default:
    return "UNKNOW";	    
    }
}

const char* _hdmi_audio_fsm_str(unsigned int fsm)
{
    switch (fsm) {
    case AUDIO_FSM_AUDIO_START:          return "START";
    case AUDIO_FSM_FREQ_DETECT:          return "DETECT";
    case AUDIO_FSM_AUDIO_WAIT_TO_START:  return "WAIT TO START";
    case AUDIO_FSM_AUDIO_START_OUT:      return "START OUT";
    case AUDIO_FSM_AUDIO_WAIT_PLL_READY: return "WAIT PLL READY";
    case AUDIO_FSM_AUDIO_CHECK:          return "CHECK";
    default:                             return "UNKNOW";
    }
}


unsigned char newbase_hdmi_detect_mode(unsigned char port)
{
	if (port >= HDMI_RX_PORT_MAX_NUM) {
		return _MODE_NOSIGNAL;
	}

	if (hdmi_in(DEBUG_REG_ADDR) & DEBUG_28_BYPASS_DETECT) {
		return _MODE_NOSIGNAL;
	}

	if (GET_H_VIDEO_FSM(port) > MAIN_FSM_HDMI_SETUP_VEDIO_PLL) {
		if (newbase_hdmi_check_condition_change(port)) {
			SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
		}
	}

	switch (GET_H_VIDEO_FSM(port)) {
		case MAIN_FSM_HDMI_WAIT_SYNC:
			if (newbase_hdmi_wait_sync(port)) {
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_SETUP_VEDIO_PLL);
			} else {
				return _MODE_NOSIGNAL;
			}
		break;

		case MAIN_FSM_HDMI_SETUP_VEDIO_PLL:
			if (newbase_hdmi_setup_video_pll(port)) {
				//newbase_hdmi_check_deb_condition_beforeDisp(port, _TRUE);	////STABLE_CHECK_OLD_PATCH
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_MEASURE);
			} else {
				return _MODE_NOSIGNAL;
			}
		break;

		case MAIN_FSM_HDMI_MEASURE:
			if (newbase_hdmi_measure(port)) {
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_DISPLAY_ON);
			} else {
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
				return _MODE_DETECT;
			}
		break;

		case MAIN_FSM_HDMI_DISPLAY_ON:
			if (newbase_hdmi_display_on(port)) {

#ifdef AVMUTE_HDMI_REDETECT //willychou add for AVmute need display timing info
				if (lib_hdmi_get_avmute(port) && !lib_hdmi_get_bch_2bit_error(port)) {

					HDMI_PRINTF("[WARNING] AVMUTE...\n");
					//USER:willychou DATE:2016/08/30
					//to prevent [WOSQRTK-8372]APPLE TV BOX display AV mute timing 1920X 1084 P
					SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_SETUP_VEDIO_PLL);
					return _MODE_NOSIGNAL;
				}
#endif
				if (newbase_hdmi_check_condition_change(port)) {
					SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
					return _MODE_NOSIGNAL;
				}

				if (!newbase_hdmi_compatibility_check(port)) {
					SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_SETUP_VEDIO_PLL);
					return _MODE_DETECT;
				}

				lib_hdmi_char_err_rst(port, 0);
				HDMI_PRINTF("FSM_HDMI_DISPLAY_ON[%d] OK\n", port);
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_VIDEO_READY);
				return _MODE_SUCCESS;
			} else {
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
				return _MODE_DETECT;
			}
		break;

		case MAIN_FSM_HDMI_VIDEO_READY:
			if (newbase_hdmi_video_ready(port)) {
				// ...
				return _MODE_SUCCESS;
			} else {
				SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
				return _MODE_NOSIGNAL;
			}
		break;

		default:
		break;
	}

	return _MODE_NOSIGNAL;
}

unsigned char newbase_hdmi_check_condition_change(unsigned char port)
{
unsigned int phy_clk;

	if (!newbase_rxphy_is_clk_stable(port)) {
		return TRUE;
	}

	phy_clk = newbase_rxphy_get_clk(port);

	if (phy_clk < VALID_MIN_CLOCK) {
		HDMI_EMG("invalid clock\n");
		return TRUE;
	}

	if (HDMI_ABS(phy_clk, hdmi_rx[port].timing_t.tmds_clk_b) > TMDS_CLOCK_TOLERANCE(port)) {
		HDMI_EMG("clock change\n");
		return TRUE;
	}

	if (MODE_HDMI == GET_H_MODE(port)) {
		if (GET_H_COLOR_SPACE(port) != newbase_hdmi_get_colorspace_reg(port)) {
			HDMI_EMG("colorspace chg from %d to %d\n", GET_H_COLOR_SPACE(port), newbase_hdmi_get_colorspace_reg(port));
			return TRUE;
		}

		if (GET_H_COLOR_DEPTH(port) != lib_hdmi_get_color_depth(port)) {
			HDMI_EMG("color depth chage\n");
			return TRUE;
		}
	}

	if (GET_H_MODE(port) != newbase_hdmi_get_hdmi_mode_reg(port)) {
		HDMI_EMG("HDMI/DVI chg from %d to %d\n", GET_H_MODE(port), (!GET_H_MODE(port)));
		return TRUE;
	}

	return FALSE;
}

unsigned char newbase_hdmi_wait_sync(unsigned char port)
{
	unsigned int curr_clk;

#if MHL_SUPPORT
	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_31_BYPASS_CBUS) {
		newbase_mhl_cts_mode();
	} else {
		if (port == MHL_CHANNEL) {
			if (!newbase_mhl_detect_mode(port)) {
				return FALSE;
			}
		}
	}
#endif

#if HDMI_TOGGLE_HPD_Z0_ENABLE
	lib_hdmi_toggle_hpd_z0_check(port, _FALSE);
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	curr_clk = newbase_rxphy_get_clk(port);
	if ((curr_clk < VALID_MIN_CLOCK) ||
		(HDMI_ABS(hdmi_rx[port].timing_t.tmds_clk_b, curr_clk) > TMDS_CLOCK_TOLERANCE(port))) {
		// Set false if clock is invalid or changed
		hdmi_rx[port].timing_t.tmds_clk_b = curr_clk;
		hdmi_rx[port].timing_t.tmds_clk_stable_cnt = 0;
		if (hdmi_rx[port].timing_t.is_interlace) {
			lib_hdmi_clear_interlace_reg(port);
			hdmi_rx[port].timing_t.is_interlace = 0;
		}
		return FALSE;
	}

	if (hdmi_rx[port].timing_t.tmds_clk_stable_cnt < CLK_STABLE_CNT) {
		// Set false if clock is unstable
		hdmi_rx[port].timing_t.tmds_clk_stable_cnt++;
		return FALSE;
	}
	hdmi_rx[port].timing_t.tmds_clk_b = curr_clk;

	if (!newbase_rxphy_get_setphy_done(port)) {
		//HDMI_PRINTF("Wait for set_phy(p%d)\n", port);
		return FALSE;
	}

	newbase_hdmi_open_err_detect(port);
	lib_hdmi_set_repeat_auto(port);
	lib_hdmi_set_colorspace_auto(port);

	lib_hdmi_bch_error_clr(port);

	newbase_hdmi_audio_var_init(port);
	newbase_hdmi_reset_all_infoframe(port);
	lib_hdmi_audio_set_hbr_manual_mode(port, 0, 0);
	lib_hdmi_audio_clear_hdr_status(port);

#ifdef HDMI_AVI_INFO_COLORIMETRY_ENABLE
	newbase_hdmi_check_avi_colorimetry_info(port, _TRUE);
#endif //#ifdef HDMI_AVI_INFO_COLORIMETRY_ENABLE

	return TRUE;
}

unsigned char newbase_hdmi_setup_video_pll(unsigned char port)
{
	HDMI_PRINTF("FSM_HDMI_SETUP_VEDIO_PLL[%d]\n", port);

	newbase_hdmi_port_select(port);

#if MHL3_ENABLE
	lib_mhl3_set_detectmode(port, newbase_hdmi_get_is_mhl3(port));
	lib_mhl3_set_24_16bit(port, (newbase_hdmi_get_is_mhl3(port) && (mhl3_get_bits_per_pixel() == BPP_16)));
#endif

#ifdef HDMI_VIDEO_WD_ENABLE
	//Enable Video and Audio, to prevent Tx HDMI have no audio, the watch dog not work
	newbase_hdmi_watchdog_apply(_DISABLE, HDMI_WD_ALL_COND);
#endif //#ifdef HDMI_VIDEO_WD_ENABLE

	SET_H_COLOR_DEPTH(port, (HDMI_COLOR_DEPTH_T)lib_hdmi_get_color_depth(port));
	SET_H_MODE(port, (HDMI_DVI_MODE_T)newbase_hdmi_get_hdmi_mode_reg(port));
	SET_H_PIXEL_REPEAT(port, lib_hdmi_get_pixelrepeat(port));

	if (GET_H_MODE(port) == MODE_DVI) {
		lib_hdmi_set_repeat_manual(port, 0);
		lib_hdmi_set_colorspace_manual(port, 0);
	} else {
		lib_hdmi_set_repeat_auto(port);
		lib_hdmi_set_colorspace_auto(port);
	}

	SET_H_COLOR_SPACE(port, (HDMI_COLOR_SPACE_T)newbase_hdmi_get_colorspace_reg(port));
	SET_H_INTERLACE(port, lib_hdmi_get_is_interlace(port, HDMI_MS_DIRECT));
	lib_hdmi_clear_interlace_reg(port);

#if HDMI2p0
	//It had support YUV420
#else //#if HDMI2p0
	if(COLOR_YUV420 == hdmi_rx[port].timing_t.colorspace)
	{
		HDMI_INFO("Not Support YUV420 :%d\n", port);
		return FALSE;
	}
#endif //#if HDMI2p0

	if (!lib_hdmi_set_video_pll(port,
		hdmi_rx[port].timing_t.tmds_clk_b,
		hdmi_rx[port].timing_t.colordepth,
		hdmi_rx[port].timing_t.is_interlace,
		hdmi_rx[port].timing_t.colorspace==COLOR_YUV420,
		hdmi_rx[port].timing_t.is_mhl))
		return FALSE;

	return TRUE;
}

unsigned char newbase_hdmi_measure(unsigned char port)
{
	HDMI_PRINTF("FSM_HDMI_MEASURE[12.01][%d]\n", port);

	lib_hdmi_meas_select_port(port);
	lib_hdmi_video_output(port, 1);
	lib_hdmi_crc_check(port);

#if MHL_SUPPORT
	if ((port == MHL_CHANNEL) && DETECT_MHL2_IN && newbase_hdmi_get_is_mhl(port)) {
		if (!lib_hdmi_is_rgb_status_ready(port)) {
			hdmi_rx[port].meas_retry_cnt++;
			if (hdmi_rx[port].meas_retry_cnt > MHL_DATA_TIMEOUT) {
				newbase_rxphy_reset_setphy_proc(port);
			}
			HDMI_PRINTF("[MHL] Waiting for RGB Data=%d\n", hdmi_rx[port].meas_retry_cnt);
			return FALSE;
		}
	}
#endif

	if (!newbase_hdmims_measure_video(&hdmi_rx[port].timing_t)) {
		hdmi_rx[port].meas_retry_cnt++;
		if (hdmi_rx[port].meas_retry_cnt > MEAS_RETRY_LIMIT) {
			newbase_rxphy_reset_setphy_proc(port);

#if HDMI2p0
			//USER:LewisLee DATE:2016/11/22
			//to prevent Tx unstable, pixel clock unstable, but large than VALID_MIN_CLOCK
			//it will let toggle function NG
			//pixel clock stable + measure NG
			newbase_hdmi2p0_inc_scdc_toggle(port);
#endif

#if HDMI_STR_TOGGLE_HPD_ENABLE
			if(HDMI_STR_HPD_TOGGLE_READY == lib_hdmi_get_str_toggle_hpd_state(port))
			{
				newbase_hdmi_set_hpd(port , 0, INIT_HPD_OFF);
				msleep(HDMI_STR_TOGGLE_HPD_MS);
				HDMI_EMG("STR on HPD Toggle\n");
				newbase_hdmi_set_hpd(port , 1, INIT_HPD_OFF);
				lib_hdmi_set_str_toggle_hpd_state(port, HDMI_STR_HPD_TOGGLE_NONE);
			}
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE
		}
		return FALSE;
	}

	newbase_hdmi_check_crc_0(port);

	return TRUE;
}

unsigned char newbase_hdmi_display_on(unsigned char port)
{
	//HDMI_PRINTF("FSM_HDMI_DISPLAY_ON[%d]\n", port);

	SET_MODE_IHCOUNT(hdmi_rx[port].timing_t.h_total);
	SET_MODE_IVCOUNT(hdmi_rx[port].timing_t.v_total);
	SET_MODE_IHFREQ(hdmi_rx[port].timing_t.h_freq);
	SET_MODE_IVFREQ(hdmi_rx[port].timing_t.v_freq);

	hdmi_rx[port].timing_t.modetable_index = Hdmi_Search_Mode(&hdmi_rx[port].timing_t.mode_id);

	if (GET_H_COLOR_SPACE(port) != newbase_hdmi_get_colorspace_reg(port)) {
		HDMI_EMG("D-CS chg from %d to %d\n", GET_H_COLOR_SPACE(port), newbase_hdmi_get_colorspace_reg(port));
		return FALSE;
	}
	if (GET_H_COLOR_DEPTH(port) != lib_hdmi_get_color_depth(port)) {
		HDMI_EMG("D-CD chg from %d to %d\n", GET_H_COLOR_DEPTH(port), lib_hdmi_get_color_depth(port));
		return FALSE;
	}
	if (GET_H_PIXEL_REPEAT(port) != lib_hdmi_get_pixelrepeat(port)) {
		HDMI_EMG("D-PR chg from %d to %d\n", GET_H_PIXEL_REPEAT(port), lib_hdmi_get_pixelrepeat(port));
		return FALSE;
	}
	if (GET_H_INTERLACE(port) != lib_hdmi_get_is_interlace(port, HDMI_MS_DIRECT)) {
		HDMI_EMG("D-IP chg from %d to %d\n", GET_H_INTERLACE(port), (!GET_H_INTERLACE(port)));
		return FALSE;
	}

	newbase_hdmi_set_scaler_info(&hdmi_rx[port].timing_t);

	newbase_hdmi_fix_green_line(port);

#if HDR10_MD_INFO_CHECK
#ifdef CONFIG_FORCE_RUN_I3DDMA
	if (newbase_hdmi_is_dispsrc(SLR_MAIN_DISPLAY))
#endif
		newbase_hdmi_dv_hdr_enable(_ENABLE);//Minchay@20160607-a add dolby version hdr
#endif

#ifdef HDMI_VIDEO_WD_ENABLE
	newbase_hdmi_watchdog_apply(_ENABLE, (HDMI_WD_VIDEO_COND | HDMI_WD_AUDIO_COND));
#endif

#if defined(PROJECT_TVSERVER)
#if MHL3_ENABLE
	if (newbase_hdmi_get_is_mhl(port) && newbase_hdmi_get_is_mhl3(port)) {
		set_MHL_flag(1);
	} else {
		set_MHL_flag(0);
	}
#endif
#endif
	if (GET_H_MODE(port)) {
#if AUDIO_THREAD_MODIFY
		lib_hdmi_audio_set_thread_run(port, _TRUE);
#else //#if AUDIO_THREAD_MODIFY
		HDMI_AUDIO_THREAD(TRUE); //need current_port is correct
#endif //#if AUDIO_THREAD_MODIFY

		SET_H_VIDEO_FORMAT(port, (HDMI_HVF_E)newbase_hdmi_get_video_format_reg(port));
		SET_H_3DFORMAT(port, (HDMI_3D_T)newbase_hdmi_get_3d_structure_reg(port));
	}

	HDMI_PRINTF("bHDMIColorSpace = %s\n", GET_H_COLOR_SPACE(port) < (sizeof(colorspace_name)/4)  ? colorspace_name[GET_H_COLOR_SPACE(port)] : "UNDEFINED");
	HDMI_PRINTF("IsInterlaced = %d\n", GET_H_INTERLACE(port));
	HDMI_PRINTF("bIsHDMIDVI = %d\n", GET_H_MODE(port));
	HDMI_PRINTF("PixelRepeat = %d\n", GET_H_PIXEL_REPEAT(port));
	HDMI_PRINTF("ColorDepth = %s\n", GET_H_COLOR_DEPTH(port) < (sizeof(depth_name)/4)  ? depth_name[GET_H_COLOR_DEPTH(port)] : "UNDEFINED");
	HDMI_PRINTF("ColorMetry = %s\n", newbase_hdmi_get_colorimetry(port) < (sizeof(colormetry_name)/4)  ? colormetry_name[newbase_hdmi_get_colorimetry(port)]: "UNDEFINED");
	HDMI_PRINTF("3D Format  = %s\n", GET_H_3DFORMAT(port) < (sizeof(hdmi_3d_name)/4) ? hdmi_3d_name[GET_H_3DFORMAT(port)] : "UNDEFINED");

	return TRUE;
}

unsigned char newbase_hdmi_video_ready(unsigned char port)
{
#ifdef AVMUTE_HDMI_REDETECT //willychou add for AVmute need display timing info
	//USER:LewisLee DATE:2016/08/14
	//to prevent picture have short time garbage before display
	if (lib_hdmi_get_avmute(port) && !lib_hdmi_get_bch_2bit_error(port)) {
		HDMI_PRINTF("[WARNING] AVMUTE 2...\n");
		SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
		return FALSE;
	}
#endif

	return TRUE;
}


void newbase_hdmi_set_info(unsigned char port){
	newbase_hdmi_set_scaler_info(&hdmi_rx[port].timing_t);
}


unsigned char newbase_hdmi_check_mode(void)
{

unsigned char port = current_port;
	if (hdmi_in(DEBUG_REG_ADDR) & DEBUG_27_BYPASS_CHECK) {
		return TRUE;
	}

	if (hdmi_in(DEBUG_REG_ADDR) & DEBUG_19_DUMP_REG) {
		lib_hdmi_dbg_reg_dump(port);
	}

#ifdef AVMUTE_HDMI_REDETECT //willychou add for AVmute need display timing info
	// KTASKWBS-5703
	// Send Avmute( once or 150ms )but no timing change when  KT STB play HDR video play again
	if (lib_hdmi_get_avmute(port) && (lib_hdmi_is_wdm_enable(port) || !lib_hdmi_get_bch_2bit_error(port))) {
		lib_hdmi_video_output(port, 0);
		lib_hdmi_audio_output(port, 0);
		HDMI_EMG("check_mode: [WARNING] AVMUTE 3...\n");
		//SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);
		return FALSE;
	}
#endif


	if (GET_H_VIDEO_FSM(port) != MAIN_FSM_HDMI_VIDEO_READY) {
		HDMI_EMG("check_mode: changed_1(p=%d)\n", port);
		return FALSE;
	}

	if (newbase_hdmi_check_condition_change(port)) {
		lib_hdmi_video_output(port, 0);
		lib_hdmi_audio_output(port, 0);
		HDMI_EMG("check_mode: changed_2(p=%d)\n", port);
		return FALSE;
	}

	if (GET_H_INTERLACE(port) != newbase_hdmi_get_interlace_conti_mode(port)) {
		HDMI_EMG("check_mode: interlace chg from %d to %d\n", GET_H_INTERLACE(port), (!GET_H_INTERLACE(port)));
		return FALSE;
	}

#if MHL_SUPPORT
	if (GET_MHL_ON(port)) {
		UserMHLMscCHECK_MODE();
	} else
#endif
	{
#if BITERR_PATCH
		if (!(hdmi_in(DEBUG_REG_ADDR) & DEBUG_25_BITERR_DET)) {
			if (hdmi_rx[port].timing_t.tmds_clk_b > 2900) {	// > 3G
				if (newbase_hdmi_char_err_detection(port)) {
					if (newbase_hdmi_is_long_cable(port)) {
						newbase_hdmi_dfe_recovery_6g_long_cable(port);
					}
				}
			} else if (hdmi_rx[port].timing_t.tmds_clk_b > 1042) {	// > 1.1G
				if (newbase_hdmi_bit_err_detection(port)) {
				//	newbase_hdmi_dfe_recovery_mi_speed(port);
				}
			} else if (hdmi_rx[port].timing_t.tmds_clk_b > 430) {  // > 450M ~ 1.1G
				if (newbase_hdmi_bit_err_detection(port)) {
					newbase_hdmi_dfe_recovery_midband_long_cable(port);
				}
			}
	}
#endif
	}

#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT // [DolbyVision] Dolby Vision CRC check
#if defined(PROJECT_TVSERVER)  // sync code from TvServer, not ensure the function in KXL is correct or not
    if(!newbase_hdmi_dv_hdr_md_info_check()){
        printf("checkmode: [DV] fail\n");
        return FALSE;
    }
#endif
#endif

#if HDR10_MD_INFO_CHECK
	//Minchay@20160607-a add hdr10 md check
	if (!newbase_hdmi_hdr10_md_info_check()) {
		HDMI_PRINTF("checkmode: [HDR10] fail\n");
		return FALSE;
	}
#endif

#if HDCP_STATUS_CHECK_ENABLE
	if(_FALSE == lib_hdmi_hdcp_status_check(port, _FALSE))
		return FALSE;
#endif //#if HDCP_STATUS_CHECK_ENABLE

	return TRUE;
}

void newbase_hdmi_reset_video_state(unsigned char port)
{
	SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_WAIT_SYNC);

	SET_H_INTERLACE(port, 0);
	SET_H_MODE(port, MODE_HDMI);
	SET_H_COLOR_DEPTH(port, HDMI_COLOR_DEPTH_8B);
	SET_H_COLOR_SPACE(port, COLOR_RGB);

	SET_H_3DFORMAT(port, HDMI3D_2D_ONLY);
}

unsigned char newbase_hdmi_get_video_state(unsigned char port)
{
	return GET_H_VIDEO_FSM(port);
}

void newbase_hdmi_reset_meas_counter(unsigned char port)
{
	hdmi_rx[port].meas_retry_cnt = 0;
}

void newbase_hdmi_check_crc_0(unsigned char port)
{
	if (lib_hdmi_read_crc(port)) {
		return;
	}

	HDMI_EMG("CRC=00000000000, cs=%d\n", GET_H_COLOR_SPACE(port));

	if (GET_H_COLOR_SPACE(port) == COLOR_YUV420) {
//		hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_29_BYPASS_PHY_ISR, DEBUG_29_BYPASS_PHY_ISR);
//		while (lib_hdmi_read_crc(port) == 0) {
//			msleep(10);
//		}
//		hdmi_mask(DEBUG_REG_ADDR, ~DEBUG_29_BYPASS_PHY_ISR, 0);

		lib_hdmi_420_en(port, 0);
		msleep(20);
		lib_hdmi_420_en(port, 1);
	}
}

void newbase_hdcp_init_timer(unsigned char port)
{
#if HDCP2_2 && HDCP22_PATCH_DEFAULT_EN
	hdmi_rx[port].hdcp_init_period = HDCP_RESET_CNT;
#endif
}

void newbase_hdcp_handler(unsigned char port)
{
	unsigned char aksv_rcv = lib_hdcp14_check_aksv_reg(port);
	//unsigned char tx_rd_bksv = lib_hdcp14_check_bksv_reg(port);

	if (aksv_rcv) { //Tx write Aksv
		lib_hdmi_hdcp14_enable(port, 1);
#if HDCP2_2
		lib_hdmi_hdcp22_enable(port, 0);
#endif

		if (aksv_rcv) {
			lib_hdcp14_clear_aksv_reg(port);
		}

		newbase_hdcp_init_timer(port);
		hdmi_rx[port].hdcp_authing = HDCP14;
		hdmi_rx[port].tx_aksv[0] = lib_hdmi_hdcp_port_read(port, 0x10);
		hdmi_rx[port].tx_aksv[1] = lib_hdmi_hdcp_port_read(port, 0x11);
		hdmi_rx[port].tx_aksv[2] = lib_hdmi_hdcp_port_read(port, 0x12);
		hdmi_rx[port].tx_aksv[3] = lib_hdmi_hdcp_port_read(port, 0x13);
		hdmi_rx[port].tx_aksv[4] = lib_hdmi_hdcp_port_read(port, 0x14);

		HDMI_PRINTF("\n[HDCP] AKSV Flag = %x, %x ,%x ,%x, %x\n", hdmi_rx[port].tx_aksv[0], hdmi_rx[port].tx_aksv[1], hdmi_rx[port].tx_aksv[2], hdmi_rx[port].tx_aksv[3], hdmi_rx[port].tx_aksv[4]);
//		HDMI_PRINTF("\nHDMI An = %x  %x %x  %x  %x %x %x  %x\n",
//			lib_hdmi_hdcp_port_read(port, 0x18),
//			lib_hdmi_hdcp_port_read(port, 0x19),
//			lib_hdmi_hdcp_port_read(port, 0x1a),
//			lib_hdmi_hdcp_port_read(port, 0x1b),
//			lib_hdmi_hdcp_port_read(port, 0x1c),
//			lib_hdmi_hdcp_port_read(port, 0x1d),
//			lib_hdmi_hdcp_port_read(port, 0x1e),
//			lib_hdmi_hdcp_port_read(port, 0x1f));
	}

#if HDCP2_2 && HDCP22_PATCH_DEFAULT_EN
// No HDCP1.4 and No clock for a while, then reset to HDCP2.2
	if (newbase_rxphy_get_clk(port) < VALID_MIN_CLOCK) {

		if (hdmi_rx[port].hdcp_init_period) {
			hdmi_rx[port].hdcp_init_period--;
		} else {

			if (!lib_hdmi_hdcp22_is_onoff(port) || !lib_hdmi_hdcp14_is_onoff(port)) {
				lib_hdmi_hdcp22_enable(port, 0); // First, connect MSHG-800/HDCP2.2, then plug out cable to QD882, HDCP CTS fail.
				lib_hdmi_hdcp14_enable(port, 1);
				lib_hdmi_hdcp22_enable(port, 1);
				hdmi_rx[port].hdcp_authing = NO_HDCP;
				lib_hdmi_hdcp_port_write(port, 0xC4, 0x0);   //[WOSQRTK-9185]SKbox transient garbage
				HDMI_PRINTF("[HDCP] reset to ALL TURN ON\n");
			}
		}
	}
#endif
#if HDCP2_2
	if (lib_hdmi_hdcp22_get_auth_done(port)) {
		hdmi_rx[port].hdcp_authing = HDCP22;
	}
#endif

}

unsigned char newbase_hdcp_get_auth_mode(unsigned char port)
{
	return hdmi_rx[port].hdcp_authing;
}


#if HDMI2p0
void newbase_hdmi2p0_check_tmds_config(unsigned char port)
{
	unsigned char cfg, hail_hydra;

#if MHL_SUPPORT
	if (newbase_hdmi_get_is_mhl(port)) {
		hdmi_rx[port].scramble_flag = 0;
		hdmi_rx[port].clock40x_flag = 0;
		return;
	}
#endif

	cfg = lib_hdmi2p0_get_tmds_config(port);

	hail_hydra = (hdmi_rx[port].scramble_flag|hdmi_rx[port].clock40x_flag);

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_26_FORCE_6G) {
		hdmi_rx[port].scramble_flag = 1;
		hdmi_rx[port].clock40x_flag = 1;
	} else {
		if (hdmi_rx[port].hdmi2p0_tmds_toggle_flag > 10) {
			hdmi_rx[port].scramble_flag = ((cfg&_BIT0) != 0);
			hdmi_rx[port].clock40x_flag = ((cfg&_BIT1) != 0);
		} else if (hdmi_rx[port].hdmi2p0_tmds_toggle_flag > 2) {
			hdmi_rx[port].scramble_flag = ((cfg&_BIT0) == 0);
			hdmi_rx[port].clock40x_flag = ((cfg&_BIT1) == 0);
			//HDMI_PRINTF("HDMI2.0 swap\n");
		} else {
			hdmi_rx[port].scramble_flag = ((cfg&_BIT0) != 0);
			hdmi_rx[port].clock40x_flag = ((cfg&_BIT1) != 0);
		}
	}

	if (!hail_hydra && (hdmi_rx[port].scramble_flag||hdmi_rx[port].clock40x_flag)) {
		HDMI_PRINTF("HDMI2.0 SCDC: got it(p%d)\n", port);
	}

}

unsigned char newbase_hdmi2p0_get_scramble_flag(unsigned char port)
{
	return hdmi_rx[port].scramble_flag;
}

unsigned char newbase_hdmi2p0_get_clock40x_flag(unsigned char port)
{
	return hdmi_rx[port].clock40x_flag;
}

void newbase_hdmi2p0_detect_config(unsigned char port)
{
#if 0// MHL_SUPPORT
	if (GET_MHL_ON(port) && GET_MHL_VER3(port)) {
		hdmi_rx[port].scramble_flag = 0; //return;
	}
#endif

	lib_hdmi2p0_scramble_enable(port, hdmi_rx[port].scramble_flag);

}

void newbase_hdmi2p0_reset_scdc_toggle(unsigned char port)
{
	hdmi_rx[port].hdmi2p0_tmds_toggle_flag = 0;
}

void newbase_hdmi2p0_inc_scdc_toggle(unsigned char port)
{
	if(hdmi_rx[port].hdmi2p0_tmds_toggle_flag >= 0xfe)
		hdmi_rx[port].hdmi2p0_tmds_toggle_flag = 0;
	else
		hdmi_rx[port].hdmi2p0_tmds_toggle_flag++;
}


#endif



void newbase_hdmi_set_current_display_port(unsigned char port)
{
	current_port = port;
}

unsigned char newbase_hdmi_get_current_display_port(void)
{
	return current_port;
}



unsigned char newbase_hdmi_get_timing(unsigned char port, HDMI_TIMING_T *ptiming)
{
	down(HDMI_SMPHR_DETECT_GET());

	if (GET_H_VIDEO_FSM(port) == MAIN_FSM_HDMI_VIDEO_READY) {
		memcpy(ptiming, &hdmi_rx[port].timing_t, sizeof(HDMI_TIMING_T));
		up(HDMI_SMPHR_DETECT_GET());
		return TRUE;
	} else {
		memset(ptiming, 0, sizeof(HDMI_TIMING_T));
		up(HDMI_SMPHR_DETECT_GET());
		return FALSE;
	}

	return FALSE;
}

unsigned char newbase_hdmi_get_hvstart(unsigned char port, HDMI_TIMING_T *ptiming, unsigned char vsc_ch)
{
	if (GET_H_VIDEO_FSM(port) == MAIN_FSM_HDMI_VIDEO_READY) {
		lib_hdmims_get_hvstart(ptiming, vsc_ch);
		return TRUE;
	} else {
		ptiming->h_act_sta = 0;
		ptiming->v_act_sta = 0;
		return FALSE;
	}

}

unsigned char newbase_hdmi_get_interlace_conti_mode(unsigned char nport)
{
unsigned char is_intc= 0;

	if (hdmi_rx[nport].vs_cnt > 3) {
		is_intc = lib_hdmi_get_is_interlace(nport, HDMI_MS_DIRECT);
		lib_hdmi_clear_interlace_reg(nport);
		hdmi_rx[nport].vs_cnt = 0;
		return is_intc;
	} else {
		lib_hdmi_vsync_checked(nport);
		hdmi_rx[nport].vs_cnt++;
		return hdmi_rx[nport].timing_t.is_interlace;
	}

}

unsigned char newbase_hdmi_get_is_interlace(unsigned char port)
{
	return GET_H_INTERLACE(port);
}

unsigned char newbase_hdmi_get_hdmi_mode_reg(unsigned char port)
{
#if HDMI2p0
	if (newbase_hdmi2p0_get_clock40x_flag(port) || newbase_hdmi2p0_get_scramble_flag(port)) {
		return TRUE;
	}
#endif

#if MHL_SUPPORT
	if (GET_MHL_ON(port)) {
		return TRUE;
	}
#endif

	return lib_hdmi_is_hdmi_mode(port);

}

unsigned char newbase_hdmi_get_hdmi_mode(unsigned char port)
{
	return GET_H_MODE(port);
}

unsigned char newbase_hdmi_get_colordepth(unsigned char port)
{
	return GET_H_COLOR_DEPTH(port);
}

unsigned char newbase_hdmi_get_colorspace_reg(unsigned char port)
{
	if (!newbase_hdmi_get_hdmi_mode_reg(port)) {
		return COLOR_RGB;
	}

	return lib_hdmi_get_colorspace(port);
}

unsigned char newbase_hdmi_get_colorspace(unsigned char port)
{
	if (GET_H_COLOR_SPACE(port) == COLOR_YUV420) {  //follow K2L
		return COLOR_YUV444;
	} else {
		return GET_H_COLOR_SPACE(port);
	}
}

unsigned char newbase_hdmi_get_video_format_reg(unsigned char port)
{
	if (hdmi_rx[port].vsi_t.Length == 0) {	//no vsinfo
		return HVF_NO;
	}

	return lib_hdmi_get_video_format(port);
}

unsigned char newbase_hdmi_get_video_format(unsigned char port)
{
	return GET_H_VIDEO_FORMAT(port);
}

unsigned char newbase_hdmi_get_3d_structure_reg(unsigned char port)
{
	if (hdmi_rx[port].vsi_t.Length == 0) {	//no vsinfo
		return HDMI3D_2D_ONLY;
	}

	if (lib_hdmi_get_video_format(port) != HVF_3D) {
		return HDMI3D_2D_ONLY;
	} else {
		return lib_hdmi_get_3d_structure(port);
	}
}


unsigned char newbase_hdmi_get_3d_structure(unsigned char port)
{
	if (hdmi_rx[port].vsi_t.Length == 0)	{	//no vsinfo
		return HDMI3D_2D_ONLY;
	}
	return GET_H_3DFORMAT(port);
}

unsigned char newbase_hdmi_get_colorimetry(unsigned char port)
{
	if (hdmi_rx[port].avi_t.len == 0) return 0;

	return (hdmi_rx[port].avi_t.C == 3)?
		(hdmi_rx[port].avi_t.EC+HDMI_COLORIMETRY_XYYCC601):hdmi_rx[port].avi_t.C;
}

unsigned char newbase_hdmi_get_color_range(unsigned char port)
{
	if (hdmi_rx[port].avi_t.len == 0) return 0;

	if (hdmi_rx[port].avi_t.Y == 0) {	// RGB
		return hdmi_rx[port].avi_t.Q;
	} else if (hdmi_rx[port].avi_t.Y == 1 || hdmi_rx[port].avi_t.Y == 2 || hdmi_rx[port].avi_t.Y == 3) {	// YUV
		return (hdmi_rx[port].avi_t.YQ<3)?(hdmi_rx[port].avi_t.YQ+1):MODE_RAG_DEFAULT;
	} else {
		return MODE_RAG_DEFAULT;
	}
}

unsigned char newbase_hdmi_get_audio_coding_type(unsigned char *code_type)
{
	unsigned char port = newbase_hdmi_get_current_display_port();
	if (hdmi_rx[port].audiopkt_t.len == 0) return 0;

	*code_type = hdmi_rx[port].audiopkt_t.CT;
	if (hdmi_rx[port].audiopkt_t.CT == 0) {
		*code_type = lib_hdmi_audio_get_channel_status15_0(port, 0xFF00, 8);
	}

	return 1;
}

unsigned int newbase_hdmi_get_tmds_clockx10(unsigned char port)
{
	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_MEASURE)
		return 0;
	return (lib_hdmi_get_clock(port)*270)>>8;
}



#if MHL_SUPPORT

void newbase_hdmi_set_is_mhl(unsigned char port, unsigned char is_mhl)
{
	SET_MHL_ON(port, is_mhl);
}

unsigned char newbase_hdmi_get_is_mhl(unsigned char port)
{
	return GET_MHL_ON(port);
}

void newbase_hdmi_set_is_mhl_ppmode(unsigned char port, unsigned char is_mhl_pp)
{
	SET_MHL_PP_MODE(port, is_mhl_pp);
}

unsigned char newbase_hdmi_get_is_mhl_ppmode(unsigned char port)
{
	return GET_MHL_PP_MODE(port);
}

void newbase_hdmi_set_is_mhl3(unsigned char port, unsigned char is_mhl3)
{
	SET_MHL_VER3(port, is_mhl3);
}

unsigned char newbase_hdmi_get_is_mhl3(unsigned char port)
{
	//return mhl_is_ver3x();
	return GET_MHL_VER3(port);
}
#endif


void newbase_hdmi_fix_green_line(unsigned char nport) //k3l need to check
{
	if (GET_H_COLOR_SPACE(nport) == COLOR_RGB) {
		lib_hdmi_tmds_out_ctrl(nport, 1, 0, 0, 0);
	} else {
		lib_hdmi_tmds_out_ctrl(nport, 0, 0x8000, 0x1000, 0x8000);
	}
}


void newbase_hdmi_set_scaler_info(HDMI_TIMING_T *timing)
{
	SET_MODE_IVSTA(timing->v_act_sta);
	SET_MODE_IHSTA(timing->h_act_sta);
	SET_MODE_IVHEIGHT(timing->v_act_len);      // Get Input VSYNC Period Measurement Result ;match resolution(cause measure result will lose one line)
	SET_MODE_IHWIDTH(timing->h_act_len);  // Input HSYNC High Period Measurement Result; match resolution(cause measure result will lose one line)
	SET_MODE_IVTOTAL(timing->v_total);
	SET_MODE_IHTOTAL(timing->h_total);
	SET_MODE_IHCOUNT(timing->h_total);
	SET_MODE_IVCOUNT(timing->v_total);
	SET_MODE_IVFREQ(timing->v_freq);
	SET_MODE_IHFREQ(timing->h_freq);
	SET_SCALER_POLARITY(timing->polarity);
	SET_SCALER_IVTOTAL(timing->v_total);
	SET_SCALER_IHTOTAL(timing->h_total);
	SET_SCALER_IVHEIGHT(timing->v_act_len);
	SET_SCALER_IVHEIGHT_PRE(timing->v_act_len);
	SET_SCALER_IHWIDTH(timing->h_act_len);
	SET_SCALER_IHWIDTH_PRE(timing->h_act_len);
	SET_SCALER_IVSTA(timing->v_act_sta);
	SET_SCALER_IVSTA_PRE(timing->v_act_sta);
	SET_SCALER_IHSTA(timing->h_act_sta);
	SET_SCALER_IHSTA_PRE(timing->h_act_sta);
	SET_SCALER_IVFREQ(timing->v_freq);
	SET_SCALER_IHFREQ(timing->h_freq);
	SET_SCALER_IVCOUNT(timing->v_total);
	SET_SCALER_IHCOUNT(timing->h_total);
	SET_SCALER_ISINTERLACE((timing->is_interlace) == 1);
	SET_SCALER_IS422(timing->colorspace == COLOR_YUV422);

	SET_SCALER_COLORSPACE(timing->colorspace);
	SET_SCALER_COLORDEPTH(timing->colordepth);
	SET_SCALER_COLORIMEYRY(timing->colorimetry);
}





void newbase_hdmi_audio_var_init(unsigned char nport)
{
	hdmi_rx[nport].audio_t.coding_type= 0;
	hdmi_rx[nport].audio_t.sr_mismatch_cnt = 0;
	hdmi_rx[nport].audio_t.track_mode_tgl = 0;
}

unsigned char newbase_hdmi_audio_is_pll_ready(unsigned char nport)
{
	unsigned char timeout;

	for (timeout = 0; timeout < 5; timeout++) {
		lib_hdmi_audio_clear_phase_error(nport);
		msleep(20);
		if (!(lib_hdmi_audio_is_pll_unlock(nport)||lib_hdmi_audio_is_fifo_overflow(nport)||lib_hdmi_audio_is_fifo_underflow(nport)))
			return TRUE;
		lib_hdmi_audio_wclr_pll_unlock(nport);
		lib_hdmi_audio_wclr_fifo_overflow(nport);
		lib_hdmi_audio_wclr_fifo_underflow(nport);
	}

	HDMI_EMG("[ERR] FIFO Unstable = %x\n", hdmi_in(HDMI_HDMI_SR_reg));
	return FALSE;

}

unsigned char newbase_hdmi_audio_set_pll(unsigned char nport, unsigned int freq, unsigned char ucACR_N,HDMI_AUDIO_TRACK_MODE track_mode)
{

	//u_int8_t coeff = 0;
	u_int8_t i;

	int timeout = 10;
	u_int32_t tmp1;
	u_int32_t I_Code=0,S=0;
	unsigned int clk;

	//HDMI_LOG( "HDMI_HDMI_AVMCR_reg = %x\n", hdmiport_in(HDMI_HDMI_AVMCR_reg));

	for (i=0; i < 7; i++) {
		if (audio_pll_coeff[i].freq == freq)  {
			//coeff = audio_pll_coeff[i].coeff;
			/*rate = audio_pll_coeff[i].rate;*/
			goto PLL_SETTING;
		}
	}
	HDMI_EMG( "Unsupport audio freq = %d\n", freq);
	return FALSE;

PLL_SETTING:

	clk = hdmi_rx[nport].timing_t.tmds_clk_b;

	/*						//adams mask 20120612,for STB LT5K no sound
		if (ACR_N == 0) {
			HDMI_PRINTF( "ACR_N = 0\n");
			return FALSE;
		}
	*/
	/*(2)audio output enable = auto mode*/
	hdmiport_mask(HDMI_HDMI_AFCR_reg,~_BIT6,_BIT6);
	/*(3)Disable trend and boundary tracking*/
	hdmiport_mask(HDMI_HDMI_WDCR0_reg,~HDMI_HDMI_WDCR0_bt_track_en_mask,0x0);//<2>Disable trend and boundary tracking
	hdmiport_mask(HDMI_HDMI_PSCR_reg, ~(_BIT3 |_BIT2),0x00);//<1>Disable trend and boundary tracking
	hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);//Update Double Buffer
	/*(4)FSM back to Pre-mode*/
	hdmiport_mask(HDMI_HDMI_AVMCR_reg , ~_BIT5,0x00);
	/*(5)Disable N/CTS tracking*/
	hdmiport_mask(HDMI_AUDIO_CTS_UP_BOUND_reg,~_BIT20,0x0);		//CTS has glitch not to tracking disable
	hdmiport_mask(HDMI_AUDIO_N_UP_BOUND_reg,~_BIT20,0x0);			//N has glitch not to tracking disable
	hdmiport_mask(HDMI_HDMI_PSCR_reg , ~_BIT4,0x00);
	hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);//Update Double Buffer
	/*(6)Disable SDM*/
	hdmiport_mask(HDMI_HDMI_AAPNR_reg, ~_BIT1,0x0);
	/*(7)Disable PLL*/
	//hdmiport_mask(HDMI_APLLCR1_reg,  ~( _BIT2 | _BIT0| _BIT13| _BIT12| _BIT11), (_BIT2 | _BIT0)); // Disable PLL
	// cloud modify magellan remove bit 16 ~bit10  , need check
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg, ~HDMI_HDMI_APLLCR1_dpll_rstb_mask, 0x0);
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg,  ~( HDMI_HDMI_APLLCR1_dpll_freeze_mask|HDMI_HDMI_APLLCR1_dpll_vcorstb_mask|HDMI_HDMI_APLLCR1_dpll_pow_mask), (HDMI_HDMI_APLLCR1_dpll_freeze_mask )); // Disable PLL //20140922
	/*(8)resetS &S1 code to avoid dead lock*/
	hdmiport_mask(HDMI_HDMI_CMCR_reg,  ~( _BIT6|_BIT5), 0x0); // PLL output clk sel from crystal
	hdmi_out(HDMI_HDMI_SCAPR_reg,0x00);	//S1 & S2 code clear to 0 , to avoid dead lock
	hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);//Update Double Buffer
    	udelay(10);
	hdmiport_mask(HDMI_HDMI_CMCR_reg,  ~( _BIT6|_BIT5), (_BIT6)); // PLL output clk sel from VCO
	//hdmi_out(HDMI_HDMI_CMCR_reg,  0x50);	//Enable Double Buffer
	hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);//Update Double Buffer
	/*(9)D code*/
	hdmi_out(HDMI_HDMI_DCAPR0_reg, (hdmi_audiopll_param[i].D_HighByte << 8) | hdmi_audiopll_param[i].D_LowByte);
	hdmiport_mask(HDMI_HDMI_CMCR_reg,~(HDMI_HDMI_CMCR_dbdcb_mask),HDMI_HDMI_CMCR_dbdcb(1));				//Enable Double Buffer for K/M/S/D/O

	/*(10)Initial PLL*/
	if (hdmi_audiopll_param[i].N < 2) {
		hdmiport_mask(HDMI_HDMI_APLLCR0_reg, ~(HDMI_HDMI_APLLCR0_dpll_m_mask |HDMI_HDMI_APLLCR0_dpll_o_mask | HDMI_HDMI_APLLCR0_dpll_bpsin_mask | HDMI_HDMI_APLLCR0_dpll_n_mask),
			HDMI_HDMI_APLLCR0_dpll_m(hdmi_audiopll_param[i].M - 2) | HDMI_HDMI_APLLCR0_dpll_o(hdmi_audiopll_param[i].O) | HDMI_HDMI_APLLCR0_dpll_bpsin(1) |	HDMI_HDMI_APLLCR0_dpll_n(0));		//set audio PLL N code
	} else {
		hdmiport_mask(HDMI_HDMI_APLLCR0_reg, ~(HDMI_HDMI_APLLCR0_dpll_m_mask |HDMI_HDMI_APLLCR0_dpll_o_mask |HDMI_HDMI_APLLCR0_dpll_bpsin_mask | HDMI_HDMI_APLLCR0_dpll_n_mask),
		              HDMI_HDMI_APLLCR0_dpll_m(hdmi_audiopll_param[i].M - 2) | HDMI_HDMI_APLLCR0_dpll_o(hdmi_audiopll_param[i].O) |
		              HDMI_HDMI_APLLCR0_dpll_bpsin(0) |	HDMI_HDMI_APLLCR0_dpll_n(hdmi_audiopll_param[i].N-2));		//set audio PLL N code
	}

	hdmiport_mask(HDMI_HDMI_CMCR_reg,~(HDMI_HDMI_CMCR_dbdcb_mask),HDMI_HDMI_CMCR_dbdcb(1));				//Enable Double Buffer for K/M/S/D/O
	hdmi_out(HDMI_HDMI_SCAPR_reg,  (hdmi_audiopll_param[i].S1) ? ((hdmi_audiopll_param[i].S / 2) | 0x80) : (hdmi_audiopll_param[i].S / 2));
	hdmi_out(HDMI_PRESET_S_CODE1_reg, 0xf800);		//S1 code
	hdmiport_mask(HDMI_HDMI_APLLCR0_reg,~(_BIT2|_BIT1|_BIT0), _BIT0);		//set Icp 4u
	hdmiport_mask(HDMI_HDMI_APLLCR0_reg,~(_BIT5|_BIT4|_BIT3),(_BIT5| _BIT3) );	//set RS=26k
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg,~(HDMI_APLLCR1_dpll_CS_MASK),(HDMI_APLLCR1_dpll_CS_35P) );			//set CS=35pf
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg,~(_BIT22|_BIT21),_BIT21 );			//set CP=15pf

	//hdmiport_mask(HDMI_APLLCR1_reg,~(_BIT3 | _BIT1 |_BIT0), (_BIT3 | _BIT1));//Enable PLL
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg,~(HDMI_HDMI_APLLCR1_dpll_stoppsw_mask|HDMI_HDMI_APLLCR1_dpll_pow_mask), (HDMI_HDMI_APLLCR1_dpll_pow_mask|HDMI_HDMI_APLLCR1_dpll_stoppsw_mask));//Enable PLL //20140922
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg,~(HDMI_HDMI_APLLCR1_dpll_vcorstb_mask), (HDMI_HDMI_APLLCR1_dpll_vcorstb_mask));//RST //20140922
	//PLL Calibration
	//hdmiport_mask(HDMI_APLLCR1_reg,  ~(_BIT15|_BIT16), _BIT16); // Set VCO default    //cloud mark for magellan 2013 0110
	//msleep(1);
	// hdmiport_mask(HDMI_APLLCR1_reg, ~_BIT11, _BIT11);         // Reg DPLL_CMPEN       //cloud mark for magellan 2013 0110
	// msleep(1);
	// hdmiport_mask(HDMI_APLLCR1_reg, ~_BIT12, _BIT12);         // Reg DPLL_CALLCH      //cloud mark for magellan 2013 0110
	// msleep(1);
	// hdmiport_mask(HDMI_APLLCR1_reg, ~_BIT13, _BIT13);         // Reg DPLL_CALSW      //cloud mark for magellan 2013 0110
	HDMI_PRINTF(" m = %x\n o = %x\n s = %x\n ", hdmi_audiopll_param[i].M, hdmi_audiopll_param[i].O, hdmi_audiopll_param[i].S);
	//Wait PLL Stable
    	udelay(1);
	//PLL un-freeze
	//hdmiport_mask(HDMI_APLLCR1_reg,~_BIT2, 0x0); //DPLL normal->clk really output to fifo for read
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg, ~HDMI_HDMI_APLLCR1_dpll_rstb_mask, HDMI_HDMI_APLLCR1_dpll_rstb_mask);
	udelay(40);	//wait PLL stable
	hdmiport_mask(HDMI_HDMI_APLLCR1_reg,~HDMI_HDMI_APLLCR1_dpll_freeze_mask,0x0);
	/*(11)Enable SDM*/
	//hdmiport_mask(HDMI_AAPNR_reg, ~_BIT1,_BIT1);
	hdmiport_mask(HDMI_HDMI_AAPNR_reg, ~HDMI_HDMI_AAPNR_esdm_mask,HDMI_HDMI_AAPNR_esdm_mask);
	udelay(1);

	if(track_mode == HDMI_AUDIO_N_CTS_TREND_BOUND) {
		HDMI_PRINTF("\n *****N/CTS Trend& Boundary Tracking*****\n");
		/*(12)Enable N/CTS tracking*/
		/*Modify N/CTS tracking parameter  USER:kistlin DATE:2011/08/04*/
		//for phase error count source Fpec = Fdds = Fvco/4
		//PEpec x Tpec = delta(Tvco)xNxSxPLLO = Tvco(1/8)(D[15:0]/2^16)xNxSxPLLO
		//D[15:0] = PEpec x Tpec /[Tvco(1/8)(1//2^16)xNxSxPLLO]
		//and D[15:0] = PEpec x (1/8)Icode
		//Icode calculate I code =2^24/(N*S*PLLO)

		//for phase error count source = fvco/4,fdds
		//Icode calculate I code =2*2048*2^10/(N*S*PLLO)-->x2 才夠力 20110701 kist
		if (hdmi_audiopll_param[i].S1)
			S = hdmi_audiopll_param[i].S*2;
		else
			S = hdmi_audiopll_param[i].S;
		HDMI_PRINTF("S = %d , ACR_N=%d , 	hdmi_audiopll_param[i].O = %d\n",S, ucACR_N, hdmi_audiopll_param[i].O );
		if (ucACR_N) {
			I_Code =16*1024*1024/(ucACR_N*S*(hdmi_audiopll_param[i].O<<1));
		} else
			I_Code = 0x02;

		//calculate 4*N*(1/128fa) or 4*CTS*Tv, 4x for delay (msleep(1) 約為300us)
		tmp1 = 4*ucACR_N*1000/(128*freq);
		if (tmp1 < 5)
			tmp1 = tmp1;//CTS*Tv < tmp1/4 > 2* CTS*Tv,  CTS*Tv(0.67ms~3.3ms)
		else if (tmp1 < 9)
			tmp1 = tmp1+2;
		else
			tmp1 = tmp1+3;

		//HDMI_PRINTF( "I Code = %d\n",I_Code);
		//HDMI_PRINTF( "tmp1 = %d\n",tmp1);

		hdmi_out(HDMI_HDMI_ICPSNCR0_reg,I_Code);     //Set I code of Ncts[15:8]
		hdmi_out(HDMI_HDMI_PCPSNCR0_reg,0x0000);	//Set P code of Ncts [15:8]
		//	hdmiport_mask(HDMI_NPECR_reg,~_BIT30,_BIT30);	//N_CTS tracking re-enable toggle function enable
		hdmiport_mask(HDMI_HDMI_NPECR_reg,~HDMI_HDMI_NPECR_ncts_re_enable_off_en_mask,HDMI_HDMI_NPECR_ncts_re_enable_off_en_mask);
		hdmi_out(HDMI_HDMI_PSCR_reg,0x92);	//Enable N_CTS tracking & set FIFO depth
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);	//Update Double Buffer
#if 0
		if (tmp1 > 9) {
			msleep(tmp1-9);// msleep 要小於10 才行,所以做兩次,因為兩個的單位不大一樣
			msleep(9);
		} else
			msleep(tmp1);
#endif
		hdmi_out(HDMI_HDMI_PETR_reg,0x1e);//phase error threshold
		for (timeout = 0; timeout < 25; timeout++) {
			hdmiport_mask(HDMI_HDMI_SR_reg,~_BIT3,_BIT3);
			hdmi_out(HDMI_HDMI_NCPER_reg,0xff);
			msleep(20);
			if ((hdmi_in(HDMI_HDMI_SR_reg) & (_BIT3)) == 0)
				break;
		}

		if (timeout == 25) {
			HDMI_EMG( "PLL 1st check not lock = %x\n",hdmi_in(HDMI_HDMI_NCPER_reg));
		} else {
			HDMI_PRINTF( "PLL 1st check lock count = %d\n",timeout);
		}


		//hdmiport_mask(HDMI_PSCR_reg,~_BIT4,0);	//disable N_CTS tracking
		hdmiport_mask(HDMI_HDMI_PSCR_reg,~HDMI_HDMI_PSCR_etcn_mask,0);
		//hdmiport_mask(HDMI_CMCR_reg,~_BIT4 , _BIT4);	//Update Double Buffer
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~HDMI_HDMI_CMCR_dbdcb_mask , HDMI_HDMI_CMCR_dbdcb_mask);	//Update Double Buffer
		//hdmiport_mask(HDMI_NPECR_reg,~_BIT30,0);	//N_CTS tracking re-enable toggle function disable
		hdmiport_mask(HDMI_HDMI_NPECR_reg,~HDMI_HDMI_NPECR_ncts_re_enable_off_en_mask,0);
		//hdmi_out(HDMI_ICPSNCR0_reg,0x0002);     //Set I code of Ncts[15:8]
		hdmi_out(HDMI_HDMI_ICPSNCR0_reg,(HDMI_HDMI_ICPSNCR0_ich(0) | HDMI_HDMI_ICPSNCR0_icl(0x02)));     //Set I code of Ncts[15:8]
		//hdmi_out(HDMI_PCPSNCR0_reg,0x2000);	//Set P code of Ncts [15:8]
		hdmi_out(HDMI_HDMI_PCPSNCR0_reg,(HDMI_HDMI_PCPSNCR0_pch(0x20) | HDMI_HDMI_PCPSNCR0_pcl(0x0)));	//Set P code of Ncts [15:8]
		//hdmiport_mask(HDMI_PSCR_reg,~_BIT4,_BIT4);	//enable N_CTS tracking
		hdmiport_mask(HDMI_HDMI_PSCR_reg,~HDMI_HDMI_PSCR_etcn_mask,HDMI_HDMI_PSCR_etcn_mask);
		//hdmiport_mask(HDMI_CMCR_reg,~_BIT4 , _BIT4);	//Update Double Buffer
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~HDMI_HDMI_CMCR_dbdcb_mask,HDMI_HDMI_CMCR_dbdcb_mask);
		//N&CTS boundary set
		//hdmiport_mask(AUDIO_CTS_UP_BOUND_reg,~0xfffff,0x6ddd0);		//CTS up boundary set 450000
		//hdmiport_mask(HDMI_AUDIO_CTS_UP_BOUND_reg,~(HDMI_AUDIO_CTS_UP_BOUND_cts_up_bound_mask),HDMI_AUDIO_CTS_UP_BOUND_cts_up_bound(450000));		//CTS up boundary set 450000
		//hdmiport_mask(HDMI_AUDIO_CTS_LOW_BOUND_reg,~0xfffff,0x4e20);		//CTS low boundary set 20000
		lib_hdmi_audio_cts_bound(nport, clk);
		//hdmiport_mask(HDMI_AUDIO_N_UP_BOUND_reg,~0xfffff,0x13880);		//N up boundary set 80000
		//hdmiport_mask(HDMI_AUDIO_N_LOW_BOUND_reg,~0xfffff,0x7d0);		//N low boundary set 2000

		lib_hdmi_audio_n_bound(nport, freq);
		hdmiport_mask(HDMI_AUDIO_CTS_UP_BOUND_reg,~_BIT20,_BIT20);		//CTS has glitch not to tracking enable
		hdmiport_mask(HDMI_AUDIO_N_UP_BOUND_reg,~_BIT20,_BIT20);			//N has glitch not to tracking enable

		/*(13)Wait PLL lock by N&CTS tracking*/
		hdmi_out(HDMI_HDMI_PETR_reg,0x1e);//phase error threshold
		for (timeout = 0; timeout < 25; timeout++) {
			hdmiport_mask(HDMI_HDMI_SR_reg,~_BIT3,_BIT3);
			hdmi_out(HDMI_HDMI_NCPER_reg,0xff);
			msleep(20);
			if ((hdmi_in(HDMI_HDMI_SR_reg) & (_BIT3)) == 0)
				break;
		}

		if (timeout == 25) {
			HDMI_EMG( "PLL not lock = %x\n",hdmi_in(HDMI_HDMI_NCPER_reg));
		} else {
			HDMI_PRINTF( "PLL lock count = %d\n",timeout);
		}

		/*(14)FSM Initial*/
		//hdmiport_out(HDMI_HDMI_FBR_VADDR,0x77);//Target FIFO depth = 14 ,Boundary address distance = 7
		hdmi_out(HDMI_HDMI_FBR_reg,0x74);
		//hdmiport_out(HDMI_HDMI_FTR_VADDR,0x03);//target times for summation of one trend to decide the trend
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,~_BIT6,_BIT6);//FSM entry Pre-mode (AOC=1)
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,~_BIT5,_BIT5);//FSM entry next step (AOMC=1)
		//msleep(1);//wait fifo to target fifo level   cloud modify timing
              	udelay(1);
		/*(15)Enable trend and boundary tracking*/
		hdmi_out(HDMI_HDMI_ICTPSR0_reg,0x0005);      	//Set I code  of trend [15:8]
		hdmi_out(HDMI_HDMI_PCTPSR0_reg,0x02FF);	//Set P code of trend [15:8]
		hdmi_out(HDMI_HDMI_ICBPSR0_reg,0x0005);      //Set I code of bnd [15:8]
		hdmi_out(HDMI_HDMI_PCBPSR0_reg,0x02FF);	//Set P code of bnd [15:8]
		hdmi_out(HDMI_HDMI_STBPR_reg,0x01);		//Set Boundary Tracking Update Response Time
		hdmiport_mask(HDMI_HDMI_PSCR_reg , ~(_BIT3|_BIT2), (_BIT3|_BIT2));//<1>Enable trend and boundary tracking
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);//Update Double Buffer
		msleep(20);
		hdmiport_mask(HDMI_HDMI_WDCR0_reg,~HDMI_HDMI_WDCR0_bt_track_en_mask,HDMI_HDMI_WDCR0_bt_track_en_mask);//<2>Enable trend and boundary tracking
	} else if(track_mode == HDMI_AUDIO_TREND_BOUND) {
		HDMI_PRINTF("\n ***** TREND_BOUND Tracking*****\n");
		/*(14)FSM Initial*/
		//hdmiport_out(HDMI_HDMI_FBR_VADDR,0x77);//Target FIFO depth = 14 ,Boundary address distance = 7
		hdmi_out(HDMI_HDMI_FBR_reg,0x74);
		//hdmiport_out(HDMI_HDMI_FTR_VADDR,0x03);//target times for summation of one trend to decide the trend
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,~_BIT6,_BIT6);//FSM entry Pre-mode (AOC=1)
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,~_BIT5,_BIT5);//FSM entry next step (AOMC=1)
		udelay(1);//wait fifo to target fifo level

		/*(15)Enable trend and boundary tracking*/
		hdmi_out(HDMI_HDMI_ICTPSR0_reg,0x0005);      	//Set I code  of trend [15:8]
		hdmi_out(HDMI_HDMI_PCTPSR0_reg,0x02FF);	//Set P code of trend [15:8]
		//hdmi_out(HDMI_HDMI_PCTPSR0_reg,0x2000);
		hdmi_out(HDMI_HDMI_ICBPSR0_reg,0x0001);      //Set I code of bnd [15:8]
		//hdmi_out(HDMI_HDMI_PCBPSR0_reg,0x02FF);	//Set P code of bnd [15:8]
		hdmi_out(HDMI_HDMI_PCBPSR0_reg,0x2000);	//Set P code of bnd [15:8]
		hdmi_out(HDMI_HDMI_STBPR_reg,0x01);		//Set Boundary Tracking Update Response Time
		hdmi_out(HDMI_HDMI_PSCR_reg,  (HDMI_HDMI_PSCR_fdint(4)|HDMI_HDMI_PSCR_etcn(0)|HDMI_HDMI_PSCR_etfd(1)|HDMI_HDMI_PSCR_etfbc(1)|HDMI_HDMI_PSCR_pecs(2)));// FIFO depth tracking
		hdmiport_mask(HDMI_HDMI_PSCR_reg , ~(_BIT3|_BIT2), (_BIT3|_BIT2));//<1>Enable trend and boundary tracking
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);//Update Double Buffer
		msleep(20);
		hdmiport_mask(HDMI_HDMI_WDCR0_reg,~HDMI_HDMI_WDCR0_bt_track_en_mask,HDMI_HDMI_WDCR0_bt_track_en_mask);//<2>Enable trend and boundary tracking

	} else { //  H/W N/CTS Tracking
		HDMI_PRINTF("\n ***** N/CTS Tracking*****\n");
		/*(12)Enable N/CTS tracking*/
		if (hdmi_audiopll_param[i].S1)
			S = hdmi_audiopll_param[i].S*2;
		else
			S = hdmi_audiopll_param[i].S;
		HDMI_PRINTF("S = %d , ACR_N=%d , 	hdmi_audiopll_param[i].O = %d\n",S, ucACR_N, hdmi_audiopll_param[i].O );
		if (ucACR_N) {
			I_Code =16*1024*1024/(ucACR_N*S*(hdmi_audiopll_param[i].O<<1));
		} else
			I_Code = 0x02;

		//calculate 4*N*(1/128fa) or 4*CTS*Tv, 4x for delay (msleep(1) 約為300us)
		tmp1 = 4*ucACR_N*1000/(128*freq);
		if (tmp1 < 5)
			tmp1 = tmp1;//CTS*Tv < tmp1/4 > 2* CTS*Tv,  CTS*Tv(0.67ms~3.3ms)
		else if (tmp1 < 9)
			tmp1 = tmp1+2;
		else
			tmp1 = tmp1+3;

		//HDMI_PRINTF( "I Code = %d\n",I_Code);
		//HDMI_PRINTF( "tmp1 = %d\n",tmp1);

		hdmi_out(HDMI_HDMI_ICPSNCR0_reg,I_Code);     //Set I code of Ncts[15:8]
		hdmi_out(HDMI_HDMI_PCPSNCR0_reg,0x0000);	//Set P code of Ncts [15:8]
		//hdmiport_mask(HDMI_NPECR_reg,~_BIT30,_BIT30);	//N_CTS tracking re-enable toggle function enable
		hdmiport_mask(HDMI_HDMI_NPECR_reg,~HDMI_HDMI_NPECR_ncts_re_enable_off_en_mask,HDMI_HDMI_NPECR_ncts_re_enable_off_en_mask);
		hdmi_out(HDMI_HDMI_PSCR_reg,0x92);	//Enable N_CTS tracking & set FIFO depth
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);	//Update Double Buffer
#if 0
		if (tmp1 > 9) {
			msleep(tmp1-9);// msleep 要小於10 才行,所以做兩次,因為兩個的單位不大一樣
			msleep(9);
		} else
			msleep(tmp1);
#endif
		hdmi_out(HDMI_HDMI_PETR_reg,0x1e);//phase error threshold
		for (timeout = 0; timeout < 25; timeout++) {
			hdmiport_mask(HDMI_HDMI_SR_reg,~_BIT3,_BIT3);
			hdmi_out(HDMI_HDMI_NCPER_reg,0xff);
			msleep(20);
			if ((hdmi_in(HDMI_HDMI_SR_reg) & (_BIT3)) == 0)
				break;
		}

		if (timeout == 25) {
			HDMI_EMG( "PLL 1st check not lock = %x\n",hdmi_in(HDMI_HDMI_NCPER_reg));
		} else {
			HDMI_PRINTF( "PLL 1st check lock count = %d\n",timeout);
		}


		hdmiport_mask(HDMI_HDMI_PSCR_reg,~_BIT4,0);	//disable N_CTS tracking
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);	//Update Double Buffer
		//hdmiport_mask(HDMI_NPECR_reg,~_BIT30,0);	//N_CTS tracking re-enable toggle function disable
		hdmiport_mask(HDMI_HDMI_NPECR_reg,~HDMI_HDMI_NPECR_ncts_re_enable_off_en_mask,0);//N_CTS tracking re-enable toggle function disable
		hdmi_out(HDMI_HDMI_ICPSNCR0_reg,0x0002);     //Set I code of Ncts[15:8]
		hdmi_out(HDMI_HDMI_PCPSNCR0_reg,0x2000);	//Set P code of Ncts [15:8]
		hdmiport_mask(HDMI_HDMI_PSCR_reg,~_BIT4,_BIT4);	//enable N_CTS tracking
		hdmiport_mask(HDMI_HDMI_CMCR_reg,~_BIT4 , _BIT4);	//Update Double Buffer

		//N&CTS boundary set
		//hdmiport_mask(HDMI_AUDIO_CTS_UP_BOUND_reg,~0xfffff,0x6ddd0);		//CTS up boundary set 450000
		//hdmiport_mask(HDMI_AUDIO_CTS_LOW_BOUND_reg,~0xfffff,0x4e20);		//CTS low boundary set 20000
		lib_hdmi_audio_cts_bound(nport, clk);
		//hdmiport_mask(HDMI_AUDIO_N_UP_BOUND_reg,~0xfffff,0x13880);		//N up boundary set 80000
		//hdmiport_mask(HDMI_AUDIO_N_LOW_BOUND_reg,~0xfffff,0x7d0);		//N low boundary set 2000
		lib_hdmi_audio_n_bound(nport, freq);
		hdmiport_mask(HDMI_AUDIO_CTS_UP_BOUND_reg,~_BIT20,_BIT20);		//CTS has glitch not to tracking enable
		hdmiport_mask(HDMI_AUDIO_N_UP_BOUND_reg,~_BIT20,_BIT20);			//N has glitch not to tracking enable

		/*(13)Wait PLL lock by N&CTS tracking*/
		hdmi_out(HDMI_HDMI_PETR_reg,0x1e);//phase error threshold
		for (timeout = 0; timeout < 25; timeout++) {
			hdmiport_mask(HDMI_HDMI_SR_reg,~_BIT3,_BIT3);
			hdmi_out(HDMI_HDMI_NCPER_reg,0xff);
			msleep(20);
			if ((hdmi_in(HDMI_HDMI_SR_reg) & (_BIT3)) == 0)
				break;
		}

		if (timeout == 25) {
			HDMI_EMG( "PLL not lock = %x\n",hdmi_in(HDMI_HDMI_NCPER_reg));
		} else {
			HDMI_PRINTF( "PLL lock count = %d\n",timeout);
		}

		/*(14)FSM Initial*/
		hdmi_out(HDMI_HDMI_FBR_reg,0x77);//Target FIFO depth = 14 ,Boundary address distance = 7
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,~_BIT6,_BIT6);//FSM entry Pre-mode (AOC=1)
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,~_BIT5,_BIT5);//FSM entry next step (AOMC=1)
		udelay(1);//wait fifo to target fifo level
	}
#if 0
	hdmiport_out(HDMI_HDMI_PTRSV1_reg, 0x01);		// Wait for ACR : Packet Type = 0x01
	for (i=0; i<100; i++) {
		hdmiport_out(HDMI_HDMI_NCPER_reg,0xff);
		if ((hdmi_in(HDMI_HDMI_SR_reg) & (_BIT2|_BIT1))!=0)
			hdmi_mask(HDMI_HDMI_SR_reg,~(_BIT2|_BIT1),(_BIT2|_BIT1));
		HdmiGetStruct(&isr_info);
		b = isr_info.b;
		msleep(20);

		HDMI_PRINTF( "Sum C  = %x  %x \n",hdmiport_in(HDMI_HDMI_DPCR4_VADDR),hdmiport_in(HDMI_HDMI_DPCR5_VADDR));
		//if ((hdmiport_in(HDMI_HDMI_DPCR4_VADDR)&0xff)!=0x7)
		{
			//cts = Hdmi_PacketSRAMRead(113)<<16;
			//cts = cts|Hdmi_PacketSRAMRead(114)<<8;
			//cts = cts|Hdmi_PacketSRAMRead(115);
			//n = Hdmi_PacketSRAMRead(116)<<16;
			//n = n|Hdmi_PacketSRAMRead(117)<<8;
			//n = n|Hdmi_PacketSRAMRead(118);
			//HDMI_PRINTF( "CTS = %d  N = %d  \n",cts,n);
			HDMI_PRINTF( "FIFO depth  =%x  %x\n",hdmiport_in(HDMI_HDMI_FDDR_VADDR),hdmiport_in(HDMI_HDMI_FDDF_VADDR));
			HDMI_PRINTF( "b=%d Phase err = %x\n",b,hdmiport_in(HDMI_HDMI_NCPER_reg));
			HDMI_PRINTF("FIFO Check  = %x\n", hdmi_in(HDMI_HDMI_SR_reg));
		}
	}

#endif


#if 0
	/*(16)Wait FIFO stable*/
	for (timeout = 0; timeout < 5; timeout++) {
		hdmi_out(HDMI_HDMI_NCPER_reg,0xff);
		msleep(20);
		if ((hdmi_in(HDMI_HDMI_SR_reg) & (_BIT3|_BIT2|_BIT1))==0)
			break;
		hdmiport_mask(HDMI_HDMI_SR_reg,~(_BIT3|_BIT2|_BIT1),(_BIT3|_BIT2|_BIT1));
	}

	if (timeout == 5)
		HDMI_PRINTF( "FIFO Unstable  = %x \n",hdmi_in(HDMI_HDMI_SR_reg));
	else
		HDMI_PRINTF( "FIFO timeout count = %d\n",timeout);

	HDMI_PRINTF( "HDMI_HDMI_AVMCR_reg = %x\n", hdmi_in(HDMI_HDMI_AVMCR_reg));
#endif
	return TRUE;

}

unsigned int newbase_hdmi_audio_freq_correction(unsigned int freq)
{
	/*
		TO-DO : use ABS function
	*/
	const unsigned int b_ratio = 1000;

	freq *= 10;
	if((freq >= (31700*b_ratio/100)) && (freq <= (32300*b_ratio/100)))
		freq = 32000;
	else if((freq >= (43500*b_ratio/100)) && (freq <= (44600*b_ratio/100)))
		freq = 44100;
	else if((freq >= 47500*b_ratio/100) && (freq <= (48500*b_ratio/100)))
		freq = 48000;
	else if((freq >= (87700*b_ratio/100)) && (freq <= (88700*b_ratio/100)))
		freq = 88200;
	else if((freq >= (95500*b_ratio/100)) && (freq <= (96500*b_ratio/100)))
		freq = 96000;
	else if((freq >= (175400*b_ratio/100)) && (freq <= (177400*b_ratio/100)))
		freq = 176400;
	else if((freq >= (191000*b_ratio/100)) && (freq <= (193000*b_ratio/100)))
		freq = 192000;
	else
		freq = 0;


	return freq;
}

void newbase_hdmi_audio_get_freq(unsigned char nport, HDMI_AUDIO_FREQ_T *freq, HDMI_AUDIO_TRACK_MODE *track_mode)
{

	unsigned long cts, n , b;
	unsigned char count=0;

	freq->ACR_freq = 0;
	freq->AudioInfo_freq = 0;
	freq->SPDIF_freq = 0;
	freq->ACR_N = 0;

	/*
		Set trigger to get CTS&N and LPCM Channel Status Info
	*/

	//Start Pop up N_CTS value
	lib_hdmi_audio_pop_n_cts(nport);

	// Clear Info Frame update indicator
	lib_hdmi_audio_clear_fs(nport);

	if (!newbase_hdmi_audio_wait_acr(nport))
	{
		HDMI_PRINTF("No N/CTS packet\n");
	}

	for (count = 0; count < 15; count++)
	{
		if (lib_hdmi_audio_pop_n_cts_done(nport) && lib_hdmi_audio_fs_from_cs(nport))
			break;

		msleep(10);
	}
	if (count >=15)
	{
		HDMI_EMG("[ERR] POP UP TIME OUT\n");
	}
	HDMI_PRINTF("POP UP TIME %d\n",count);


	if (lib_hdmi_audio_fs_from_cs(nport)) // debug options: bit0 or bit1
	{
		freq->SPDIF_freq = AUDIO_CHANNEL_STATUS[lib_hdmi_audio_get_freq_from_cs(nport)];
	}

	HDMI_PRINTF("*************** SPDIF freq=%ld\n", freq->SPDIF_freq);


	/*
			Get Audio Frequency from CTS&N
	*/
	cts = lib_hdmi_audio_get_cts(nport);
	n = lib_hdmi_audio_get_n(nport);
	b = hdmi_rx[nport].timing_t.tmds_clk_b;
	freq->ACR_N = n;

#if MHL_SUPPORT
	if (newbase_hdmi_get_is_mhl_ppmode(nport) && newbase_hdmi_get_is_mhl(nport)) {
		b <<= 1;
	}
#endif
	HDMI_PRINTF("(cts=%ld)(n=%ld)(b=%ld)\n",cts, n, b);

	if (cts == 0 || n == 0 || b == 0)  return;

	freq->ACR_freq = ((((270000 * b)/256)/128) * n) / (cts);
	freq->ACR_freq *= 100;
	freq->ACR_freq = newbase_hdmi_audio_freq_correction(freq->ACR_freq);

#if MHL_SUPPORT
	if (GET_MHL_ON(nport) && GET_MHL_VER3(nport))
	{
		*track_mode = HDMI_AUDIO_TREND_BOUND;
	}
	else
#endif
	{
		*track_mode = HDMI_AUDIO_N_CTS_TREND_BOUND;
	}

}

unsigned char newbase_hdmi_audio_detect(void)
{
	#define MATCH_THRD	15
	unsigned char i, result = FALSE;
	HDMI_AUDIO_FREQ_T t, t2;
	HDMI_AUDIO_TRACK_MODE track_mode;
	unsigned char port = current_port;

#if AUDIO_THREAD_MODIFY
	if(_FALSE == lib_hdmi_audio_get_thread_run(port))
		return FALSE;
#endif //#if AUDIO_THREAD_MODIFY

	if (((GET_H_VIDEO_FSM(port) != MAIN_FSM_HDMI_DISPLAY_ON) && (GET_H_VIDEO_FSM(port) != MAIN_FSM_HDMI_VIDEO_READY)) ||
		(lib_hdmi_get_avmute(port) && !lib_hdmi_get_bch_2bit_error(port)) ||
		(hdmi_rx[port].timing_t.tmds_clk_b < VALID_MIN_CLOCK))
	{
		lib_hdmi_audio_output(port, 0);
		SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
		return FALSE;
	}

	switch (GET_H_AUDIO_FSM(port))
	{
	case AUDIO_FSM_AUDIO_START:
		//HDMI_PRINTF("AUDIO_FSM_AUDIO_START\n");

		for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++)
		{
			SET_H_AUDIO_FSM(i, AUDIO_FSM_AUDIO_START);
			lib_hdmi_audio_init(i);
		}

		lib_hdmi_audio_set_hbr_manual_mode(port, 0, 0);
		hdmi_rx[port].audio_t.sr_mismatch_cnt = 0;


#if AUDIO_HBR_DETECT
		if (!newbase_hdmi_audio_wait_2_samples(port)) {
			break;
		}
#else
		if (!newbase_hdmi_audio_wait_sample(port)) {
			//HDMI_PRINTF("No audio sample(p%d)\n", port);
			break; //need to wait for audio sample packet
		}
#endif

		SET_H_AUDIO_FSM(port, AUDIO_FSM_FREQ_DETECT);

		break;
	case AUDIO_FSM_FREQ_DETECT:
		HDMI_PRINTF("AUDIO_FSM_FREQ_DETECT[%d]\n", port);

//  Ack from China (20170323)
//  Change timing(w/ HDCP), flick happen before going to next timing
//  => AVMUTE => WD on, so blanking => audio stop & re-detect & disable WD => WD off, so display on => repeat....,
//
//
//#ifdef HDMI_VIDEO_WD_ENABLE
//		newbase_hdmi_watchdog_apply(_DISABLE, HDMI_WD_AUDIO_COND);
//#endif //#ifdef HDMI_VIDEO_WD_ENABLE

		hdmi_rx[port].audio_t.coding_type = lib_hdmi_audio_is_nonpcm(port);

		newbase_hdmi_audio_get_freq(port, &t, &track_mode);
		newbase_hdmi_audio_get_freq(port, &t2, &track_mode);
		HDMI_PRINTF("Hdmi_GetAudioFreq t=%ld\n", t.ACR_freq);
		HDMI_PRINTF("Hdmi_GetAudioFreq t2=%ld\n", t2.ACR_freq);

		if ((t.ACR_freq != 0) && (t.ACR_freq==t2.ACR_freq))
		{
			if (HDMI_ABS(t.ACR_freq, t.SPDIF_freq) > (t.ACR_freq/20)) {  // WOSQRTK-4508 // treat as noise if SR in (CS&info) arenot match > 5%
				HDMI_EMG("[HDMI] Freq in N/CTS and CS are not match!!(cnt=%d)\n", hdmi_rx[port].audio_t.sr_mismatch_cnt);
				if (hdmi_rx[port].audio_t.sr_mismatch_cnt < MATCH_THRD) {
					hdmi_rx[port].audio_t.sr_mismatch_cnt++;
					//SET_HDMI_AUDIO_FSM(AUDIO_FSM_AUDIO_START);
					break;
				} else {
					hdmi_rx[port].audio_t.sr_mismatch_cnt = 0;
				}
			}

			if (hdmi_rx[port].audio_t.track_mode_tgl == 1) {
				hdmi_rx[port].audio_t.track_mode_tgl = 0;
				if (newbase_hdmi_audio_set_pll(port, t.ACR_freq, t.ACR_N, track_mode))
				{
					SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_WAIT_PLL_READY);
					break;
				}
			} else {
				hdmi_rx[port].audio_t.track_mode_tgl = 1;
				if (newbase_hdmi_audio_set_pll(port, t.ACR_freq, t.ACR_N, HDMI_AUDIO_TREND_BOUND))
				{
					SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_WAIT_PLL_READY);
					break;
				}
			}
		}
		else
		{
		 	if ((t.ACR_freq == 0)||(t2.ACR_freq == 0)) { //cts = 0,use t.SPDIF_freq and force to trend_boundary tracking
				if (newbase_hdmi_audio_set_pll(port, t.SPDIF_freq, t.ACR_N, HDMI_AUDIO_TREND_BOUND))
				{
					if (t.SPDIF_freq == t2.SPDIF_freq) {
						SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_WAIT_PLL_READY);
						break;
					}
				}
			}
		}
		break;
	case AUDIO_FSM_AUDIO_WAIT_PLL_READY:
		HDMI_PRINTF("AUDIO_FSM_AUDIO_WAIT_PLL_READY\n");

		if (!newbase_hdmi_audio_is_pll_ready(port))
		{
			SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
			return FALSE;
		}

		SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START_OUT);
		break;
	case AUDIO_FSM_AUDIO_START_OUT:
		HDMI_PRINTF("AUDIO_FSM_AUDIO_START_OUT[%d]\n", port);

		lib_hdmi_audio_generate(port);
		lib_hdmi_audio_output(port, 1);

#ifdef HDMI_VIDEO_WD_ENABLE
		newbase_hdmi_watchdog_apply(_ENABLE, HDMI_WD_AUDIO_COND);
#endif //#ifdef HDMI_VIDEO_WD_ENABLE

		SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_CHECK);
		result = TRUE;
		break;
	case AUDIO_FSM_AUDIO_CHECK:

			hdmi_rx[port].audio_t.track_mode_tgl = 0;

			if (!newbase_hdmi_audio_is_pll_ready(port))
			{
				lib_hdmi_audio_output(port, 0);
				SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
			}

			if (!lib_hdmi_audio_is_output(port))
			{
				lib_hdmi_audio_output(port, 0);
				SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
				//HDMI_PRINTF("Audio Output Disable cause by AVMCR output disable:%x\n",hdmi_in(HDMI_HDMI_AVMCR_reg));
			}

			if (hdmi_rx[port].audio_t.coding_type != lib_hdmi_audio_is_nonpcm(port))
			{
				lib_hdmi_audio_output(port, 0);
				SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
				HDMI_PRINTF("Audio Type change=%d\n", lib_hdmi_audio_is_nonpcm(port));
			}
		break;
	default:
		SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
		break;
	}

	return result;
}

void newbase_hdmi_audio_close(unsigned char port)
{
	lib_hdmi_audio_output(port, 0);
#if AUDIO_THREAD_MODIFY
	lib_hdmi_audio_set_thread_run(port, _FALSE);
#else //#if AUDIO_THREAD_MODIFY
	HDMI_AUDIO_THREAD(FALSE);
#endif //#if AUDIO_THREAD_MODIFY
	SET_H_AUDIO_FSM(port, AUDIO_FSM_AUDIO_START);
}

void newbase_hdmi_audio_reset_status(void)
{
	unsigned char i;
	for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++)
		SET_H_AUDIO_FSM(i, AUDIO_FSM_AUDIO_START);
}

unsigned char newbase_hdmi_audio_get_current_status(void)
{
	return GET_H_AUDIO_FSM(current_port);
}


unsigned char newbase_hdmi_audio_wait_acr(unsigned char port)
{	//Audio Clock Regeneration (N/CTS)
	unsigned char i, bch_err;

	lib_hdmi_set_rsv_packet_type(port, 0, 0x01);
	lib_hdmi_clear_rsv_packet0_status(port);

	for (i=0; i<5; i++) {
		if (newbase_hdmi_update_rsv0_packet(port, 1, &bch_err)) {
			return (bch_err == 0);
		}
		msleep(10);
	}

	return FALSE;
}

unsigned char newbase_hdmi_audio_wait_sample(unsigned char port)
{	//Audio Sample (L-PCM and IEC 61937 compressed formats)
	unsigned char i, buf[2];

	lib_hdmi_set_rsv_packet_type(port, 0, 0x02);
	lib_hdmi_clear_rsv_packet0_status(port);

	for (i=0; i<5; i++) {
		if (newbase_hdmi_update_rsv0_packet(port, 2, buf)) {
			lib_hdmi_audio_set_hbr_manual_mode(port, 1, 0);
			return TRUE;
		}
		msleep(10);
	}

	return FALSE;
}


unsigned char newbase_hdmi_audio_wait_2_samples(unsigned char port)
{	// Audio Sample (02) (L-PCM and IEC 61937 compressed formats)
	//HBR sample (09)
	unsigned char i, buf[9];

	// is packet_02 in reserved_0 ??
	lib_hdmi_set_rsv_packet_type(port, 0, 0x02);
	lib_hdmi_clear_rsv_packet0_status(port);

	// is packet_09 in reserved_1 ??
	lib_hdmi_set_rsv_packet_type(port, 1, 0x09);
	lib_hdmi_clear_rsv_packet1_status(port);

	for (i=0; i<5; i++) {
		if (newbase_hdmi_update_rsv1_packet(port, 9, buf) || lib_hdmi_audio_get_hbr_mode(port)) {
			lib_hdmi_audio_set_hbr_manual_mode(port, 1, 1);
			HDMI_PRINTF("Got HBR packet(p%d)\n", port);
			return TRUE;
		}
		msleep(10);
	}

	if (newbase_hdmi_update_rsv0_packet(port, 2, buf)) {
		lib_hdmi_audio_set_hbr_manual_mode(port, 1, 0);  //follow up Merlin-1 setting, review this later
		return TRUE;
	}

	return FALSE;
}



/*
unsigned char newbase_hdmi_reg_table(HDMI_TABLE_TYPE index, void *ptr,unsigned char port)
{

	if ( !ptr )
		return FALSE;

	//HDMI_PRINTF("%s %d %x\n", __func__, index, (unsigned int) ptr);
	switch ( index )
	{
		case HDMI_HDCP_KEY_TABLE:
                                          HDCP_KEY_T* hdcp_ptr =  (HDCP_KEY_T*)ptr;
                                         	memcpy(hdcpkey.BKsv, hdcp_ptr->BKsv, 5) ;
                                          memcpy(hdcpkey.Key, hdcp_ptr->Key, 320) ;
			break;
		case HDMI_CHANNEL:
			HDMI_CHANNEL_T* hdmi_ch_ptr = (HDMI_CHANNEL_T*)ptr;
			pcb_info[port].phy_port = hdmi_ch_ptr->phy_port;
			pcb_info[port].ddc_selected = hdmi_ch_ptr->ddc_selected;
			break;

#if MHL_SUPPORT
		case CBUS_TABLE:
		//cbus = (CBUS_CHANNEL_T*) ptr;

		break;
#endif

		default:

			return FALSE;
	}
	return TRUE;
}
*/




void newbase_hdmi_read_aksv(unsigned char port, unsigned char *pAKSV)
{
	unsigned char i;
	for (i=0; i<5; i++) {
		pAKSV[i] = hdmi_rx[port].tx_aksv[i];
	}
}

void newbase_hdmi_read_hdcp14_key(unsigned char *bksv, unsigned char *hdcp_key)
{
	lib_hdmi_read_hdcpkey(0, bksv, hdcp_key);
}

void newbase_hdmi_write_hdcp14_key(unsigned char *bksv, unsigned char *hdcp_key)
{
	unsigned char i;
	for (i=0; i<HDMI_RX_PORT_MAX_NUM; i++) {
		lib_hdmi_write_hdcpkey(i, bksv, hdcp_key);
	}
}


void newbase_hdmi_read_edid(unsigned char port, unsigned char *edid, unsigned int len)
{
	if (port >= HDMI_RX_PORT_MAX_NUM) {
		HDMI_EMG("%s: err port=%d\n", __func__, port);
		return;
	}
	lib_hdmiddc_read(port, edid, len);
}

void newbase_hdmi_write_edid(unsigned char port, unsigned char *edid, unsigned int len)
{
	if (port >= HDMI_RX_PORT_MAX_NUM) {
		HDMI_EMG("%s: err port=%d\n", __func__, port);
		return;
	}
	
	//newbase_hdmi_dump_hdmi_edid(edid + 128);	// for debug
	
	lib_hdmiddc_write(port, edid, len);
}

void newbase_hdmi_edid_enable(unsigned char port, unsigned char enable)
{
	if (port >= HDMI_RX_PORT_MAX_NUM) {
		HDMI_EMG("%s: err port=%d\n", __func__, port);
		return;
	}
	lib_hdmiddc_enable(port, enable);
}


#if MHL_SUPPORT
void newbase_hdmi_mhl_write_edid(unsigned char *edid, unsigned int len)
{
	lib_hdmiddc_mhl_write(edid, len);
}

void newbase_hdmi_mhl_edid_enable(unsigned char enable)
{
	lib_hdmiddc_mhl_enable(enable);
}
#endif








void newbase_hdmi_control_pull_up_1k(void)
{
	if (newbase_hdmi_get_5v_state(MHL_CHANNEL) && !DETECT_MHL2_IN ) {
		lib_hdmi_control_pull_up_1k(1);	// normal, internal pull up 1K for hdmi
	} else {
		lib_hdmi_control_pull_up_1k(0); //bypass
	}
}


unsigned char newbase_hdmi_get_5v_state(unsigned char port)
{
	HDMI_CHANNEL_T* p_info = newbase_hdmi_get_pcbinfo(port);
    
	if (p_info==NULL)
		return 0;
    
	rtk_gpio_set_dir(p_info->det_5v, 0);

	return rtk_gpio_input(p_info->det_5v);		
}

void newbase_hdmi_set_hpd(unsigned char nport, unsigned char high, unsigned char controllable)
{        
	HDMI_CHANNEL_T* p_info = newbase_hdmi_get_pcbinfo(nport);
    
	if (p_info==NULL)
		return;

	if (!controllable)
		return;

	if (high) 
	{
#if HDMI2p0
		hdmiport_mask(HDMI_SCDC_CR_reg, ~HDMI_SCDC_CR_scdc_reset_mask, 0);
#endif

#if MHL_SUPPORT
		if (nport == MHL_CHANNEL) 
		{
			if (MHL_CIRCUIT)  //HDMI/MHL combo
			{
				hdmiport_mask(CBUS_PMM_CBUS_PHY_3_reg,~(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask),0);  //set input
				HDMI_EMG("HOTPLUG[%d]=HIGH\n", nport);
				return;
			}
		}
#endif // #if MHL_SUPPORT

		HDMI_EMG("HOTPLUG[%d]=HIGH\n", nport);

	} 
	else 
	{
#if HDMI2p0
		hdmiport_mask(HDMI_SCDC_CR_reg, ~HDMI_SCDC_CR_scdc_reset_mask, HDMI_SCDC_CR_scdc_reset_mask);
#endif

#if MHL_SUPPORT
		if (nport == MHL_CHANNEL) 
		{
			if (MHL_CIRCUIT)  //HDMI/MHL combo
			{			
				if (!DETECT_MHL2_IN)
				{				                        
					hdmiport_mask(CBUS_PMM_CBUS_PHY_3_reg,~(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask|CBUS_PMM_CBUS_PHY_3_cbus_i_rx_mask),(CBUS_PMM_CBUS_PHY_3_cbus_e_rx_mask)); //set output
					HDMI_EMG("HOTPLUG[%d]=LOW\n", nport);
					return;
				}
			}
		}
#endif //#if MHL_SUPPORT

		HDMI_EMG("HOTPLUG[%d]=LOW\n", nport);
	}
		
	rtk_gpio_output(p_info->hpd, (high) ? 0 : 1);   
	rtk_gpio_set_dir(p_info->hpd, 1);
}

void newbase_hdmi_hpd_delay_work_init(void)
{
	hpd_target_ch = 0xff;
	HDMI_WQ_HPD_DESTROY();
	HDMI_WQ_HPD_CREATE(&newbase_hdmi_hpd_delay_work_func);
	if (0 == HDMI_WQ_HPD_START(hpd_low_ms)) {
		//hpd_low_is_running = 1;
	}

	hpd_low_ms = HPD_DEFAULT_LOW_MS;
}

void newbase_hdmi_hpd_delay_work_func(void)
{
	int nPortCnt = 0;

	//hpd_low_is_running = 0;

	//do what you want to do after 'hpd_delayms' delay
	if (hpd_target_ch == 0xff) { // for all channel
		for (nPortCnt=0; nPortCnt<HDMI_RX_PORT_MAX_NUM; nPortCnt++) {
			newbase_hdmi_set_hpd(nPortCnt, 1, INIT_HPD_OFF); //HPD pull high
		}
	} else {
		//for certain channel
	}
	HDMI_PRINTF("%s is actived(%x)\n", __func__, hpd_target_ch);
}

void newbase_hdmi_check_connection_state(unsigned char port)
{
	unsigned char conn_st = newbase_hdmi_get_5v_state(port);

	if (conn_st != hdmi_rx[port].cable_conn) {
		if (conn_st) {
			lib_hdmi_char_err_rst(port, 1);  //reset CED until measure done
		}
		else
		{
			int ddc_ch;

#if HDMI2p0
			lib_hdmi2p0_reset_scdc(port);
			lib_hdmi2p0_scramble_enable(port, 0);	// First, connect MSHG-800/4K60(#474), then plug out cable to QD882, HDCP CTS will check Bstatus.
#endif
			lib_hdmi_clear_avmute(port);
			lib_hdmi_hdcp_port_write(port, 0xC4, 0x0);   //[WOSQRTK-9185]SKbox transient garbage

			//---------------------------------------------                            
			// ddc sync_reset, patch for poor design
			//---------------------------------------------
			ddc_ch = newbase_hdmi_ddc_channel_status(port);

			if (ddc_ch >=0)
			{
				lib_hdmiddc_sync_reset(ddc_ch);
				lib_hdmiddc_set_sda_delay(ddc_ch, 0x1); //K2L, one NB no audio, due to IIC issue. Q2879/3094/3222
				lib_hdmiddc_enable(ddc_ch, 1);
			}
						
			//---------------------------------------------
			// reset hdcp 
			//---------------------------------------------
//#if HDCP2_2
//			newbase_hdmi_hdcp2_clear_status(port);
//#endif

#if HDMI_TOGGLE_HPD_Z0_ENABLE
			lib_hdmi_set_toggle_hpd_z0_flag(port, _FALSE);
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

			lib_hdmi_misc_variable_initial(port);
		}
	}

	hdmi_rx[port].cable_conn = conn_st;
}


unsigned char newbase_hdmi_get_avmute(unsigned char port)
{
	//USER:willychou DATE:2017/08/22
	//sink CTS test - AVMute test need display timing info

	if (GET_H_VIDEO_FSM(port) == MAIN_FSM_HDMI_VIDEO_READY) {
		if (lib_hdmi_get_avmute(port) && !lib_hdmi_get_bch_2bit_error(port)) {
			HDMI_PRINTF("This is AVMUTE\n");
			return TRUE;
		}
	}

	return FALSE;
}


void newbase_hdmi_save_customer_hdcp1p4(unsigned char* hdcp_1p4, unsigned int len )
{
	if(hdcp_1p4)//save Customer hdcp1p4 to hdcpkey
	{
		memcpy(hdcpkey.BKsv , hdcp_1p4, 5);
		memcpy(hdcpkey.Key, hdcp_1p4+5, 320);

		HDMI_EMG("Customer HDCP1p4:%d,%d,%d,%d,%d,len=%d\n",
			hdcpkey.Key[0], hdcpkey.Key[1],
			hdcpkey.Key[2], hdcpkey.Key[3], hdcpkey.Key[4],len);

		customer_hdcp1p4=TRUE;
	}
	else
		customer_hdcp1p4=FALSE;

}
void newbase_hdmi_save_customer_hdcp2p2(unsigned char* hdcp_2p2, unsigned int len )
{
	h2p2table = kmalloc(len, GFP_KERNEL);//kernal space
	if(h2p2table)
	{
		memcpy(h2p2table, hdcp_2p2, len);
		HDMI_EMG("Customer HDCP2p2:%d,%d,%d,%d,%d,len=%d\n",h2p2table[0],h2p2table[1],h2p2table[2],h2p2table[3],h2p2table[4],len);
		customer_hdcp2p2=TRUE;
	}
	else
		customer_hdcp2p2=FALSE;
}

unsigned char newbase_hdmi_get_customer_hdcp1p4(void)
{
	return customer_hdcp1p4;
}
unsigned char newbase_hdmi_get_customer_hdcp2p2(void)
{
	return customer_hdcp2p2;
}
unsigned char* newbase_hdmi_get_customer_hdcp2p2_table(void)
{
	return h2p2table;
}
void newbase_hdmi_clear_table(void)
{
	if (h2p2table)
		kfree(h2p2table);
	customer_hdcp1p4 = FALSE;
	customer_hdcp2p2= FALSE;
}

void newbase_hdmi_save_mhl_edid(const unsigned char *edid, const unsigned int len)
{
	memcpy(mhl_edid_table, edid, len);
}

void newbase_hdmi_save_hdcp(const HDCP_KEY_T *key)
{
	memcpy(&hdcpkey, key, sizeof(HDCP_KEY_T));
}



void newbase_hdmi_reset_all_infoframe(unsigned char port)
{
	memset(&hdmi_rx[port].vsi_t, 0, sizeof(HDMI_VSI_T));
	hdmi_rx[port].no_vsi_cnt = 0;
	lib_hdmi_clear_fvs_received_status(port);
	lib_hdmi_clear_vs_received_status(port);

	memset(&hdmi_rx[port].avi_t, 0, sizeof(HDMI_AVI_T));
	hdmi_rx[port].no_avi_cnt = 0;
	lib_hdmi_clear_avi_received_status(port);

	memset(&hdmi_rx[port].spd_t, 0, sizeof(HDMI_SPD_T));
	hdmi_rx[port].no_spd_cnt = 0;
	lib_hdmi_clear_spd_received_status(port);

	memset(&hdmi_rx[port].audiopkt_t, 0, sizeof(HDMI_AUDIO_T));
	hdmi_rx[port].no_audiopkt_cnt = 0;
	lib_hdmi_clear_audiopkt_received_status(port);

	memset(&hdmi_rx[port].drm_t, 0, sizeof(HDMI_DRM_T));
	hdmi_rx[port].no_drm_cnt = 0;
	lib_hdmi_clear_drm_received_status(port);

}

void newbase_hdmi_update_infoframe(unsigned char port)
{
unsigned char is_drm_here = hdmi_rx[port].drm_t.type_code;
unsigned char is_avi_here = hdmi_rx[port].avi_t.type_code;
unsigned char is_spd_here = hdmi_rx[port].spd_t.type_code;
unsigned char is_audio_here = hdmi_rx[port].audiopkt_t.type_code;
unsigned char is_vsi_here = hdmi_rx[port].vsi_t.VSIF_Version;  // vsi has 2 version-type //861-G


	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_MEASURE || GET_H_MODE(port) != MODE_HDMI) {
		return;
	}

	if (newbase_hdmi_update_drm(port)) {
		hdmi_rx[port].no_drm_cnt = 0;
	} else {
		if (++hdmi_rx[port].no_drm_cnt > NO_INFO_MAX) {
			memset(&hdmi_rx[port].drm_t, 0, sizeof(HDMI_DRM_T));
			hdmi_rx[port].no_drm_cnt = 0;
		}
	}

	if (newbase_hdmi_update_avi(port)) {
		hdmi_rx[port].no_avi_cnt = 0;
	} else {
		if (++hdmi_rx[port].no_avi_cnt > NO_INFO_MAX) {
			memset(&hdmi_rx[port].avi_t, 0, sizeof(HDMI_AVI_T));
			hdmi_rx[port].no_avi_cnt = 0;
		}
	}

	if (newbase_hdmi_update_vsi(port)) {
		hdmi_rx[port].no_vsi_cnt = 0;
	} else {
		if (++hdmi_rx[port].no_vsi_cnt > NO_INFO_MAX) {
			memset(&hdmi_rx[port].vsi_t, 0, sizeof(HDMI_VSI_T));
			hdmi_rx[port].no_vsi_cnt = 0;
		}
	}

	if (newbase_hdmi_update_spd(port)) {
		hdmi_rx[port].no_spd_cnt = 0;
	} else {
		if (++hdmi_rx[port].no_spd_cnt > NO_INFO_MAX) {
			memset(&hdmi_rx[port].spd_t, 0, sizeof(HDMI_SPD_T));
			hdmi_rx[port].no_spd_cnt = 0;
		}
	}

	if (newbase_hdmi_update_audiopkt(port)) {
		hdmi_rx[port].no_audiopkt_cnt = 0;
	} else {
		if (++hdmi_rx[port].no_audiopkt_cnt > NO_INFO_MAX) {
			memset(&hdmi_rx[port].audiopkt_t, 0, sizeof(HDMI_AUDIO_T));
			hdmi_rx[port].no_audiopkt_cnt = 0;
		}
	}

	if (is_drm_here != hdmi_rx[port].drm_t.type_code) {
		HDMI_PRINTF("DRM INFO=%d\n", hdmi_rx[port].drm_t.type_code);
	}
	if (is_avi_here != hdmi_rx[port].avi_t.type_code) {
		HDMI_PRINTF("AVI INFO=%d\n", hdmi_rx[port].avi_t.type_code);
	}
	if (is_spd_here != hdmi_rx[port].spd_t.type_code) {
		HDMI_PRINTF("SPD INFO=%d\n", hdmi_rx[port].spd_t.type_code);
	}
	if (is_audio_here != hdmi_rx[port].audiopkt_t.type_code) {
		HDMI_PRINTF("AUD INFO=%d\n", hdmi_rx[port].audiopkt_t.type_code);
	}
	if (is_vsi_here != hdmi_rx[port].vsi_t.VSIF_Version) {
		HDMI_PRINTF("VSI INFO=%d (%x,%x,%x)\n", hdmi_rx[port].vsi_t.VSIF_Version, hdmi_rx[port].vsi_t.Reg_ID[0], hdmi_rx[port].vsi_t.Reg_ID[1], hdmi_rx[port].vsi_t.Reg_ID[2]);
		// 0xd8, 0x5d, 0xc4 is hdmi2.0 FVSPS	                    (QD980 Forum VS)
		// 0x03, 0x0c, 0x00 is hdmi1.4 VSPS or Dolby         (QD980 LLC VS)
		// QD980 has a bug, it needs to toggle & apply twice then send correct info.
	}

}

unsigned char newbase_hdmi_get_hdmi_mode_infoframe(unsigned char port)
{
	if(GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_DISPLAY_ON)
		return 0;

	if(MODE_HDMI == GET_H_MODE(port))
		return 1;

	return 0;
}

unsigned char newbase_hdmi_get_vs_infoframe(unsigned char port, HDMI_VSI_T *p_vsi_t)
{
	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_MEASURE || GET_H_MODE(port) != MODE_HDMI) {
		return 0;
	}

	if (hdmi_rx[port].vsi_t.VSIF_TypeCode == 0) {
		return 0;
	}

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_23_FORCE_NO_INFOPKT) {
		return 0;
	}

	memcpy(p_vsi_t, &hdmi_rx[port].vsi_t, sizeof(HDMI_VSI_T));
	return 1;
}

unsigned char newbase_hdmi_get_avi_infoframe(unsigned char port, HDMI_AVI_T *p_avi_t)
{
	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_MEASURE || GET_H_MODE(port) != MODE_HDMI) {
		return 0;
	}

	if (hdmi_rx[port].avi_t.type_code == 0) {
		return 0;
	}

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_23_FORCE_NO_INFOPKT) {
		return 0;
	}

	memcpy(p_avi_t, &hdmi_rx[port].avi_t, sizeof(HDMI_AVI_T));
	return 1;
}

unsigned char newbase_hdmi_get_spd_infoframe(unsigned char port, HDMI_SPD_T *p_spd_t)
{
	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_MEASURE || GET_H_MODE(port) != MODE_HDMI) {
		return 0;
	}

	if (hdmi_rx[port].spd_t.type_code == 0) {
		return 0;
	}

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_23_FORCE_NO_INFOPKT) {
		return 0;
	}

	memcpy(p_spd_t, &hdmi_rx[port].spd_t, sizeof(HDMI_SPD_T));
	return 1;
}

unsigned char newbase_hdmi_get_audio_infoframe(unsigned char port, HDMI_AUDIO_T *p_audio_t)
{
	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_MEASURE || GET_H_MODE(port) != MODE_HDMI) {
		return 0;
	}

	if (hdmi_rx[port].audiopkt_t.type_code == 0) {
		return 0;
	}

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_23_FORCE_NO_INFOPKT) {
		return 0;
	}

	memcpy(p_audio_t, &hdmi_rx[port].audiopkt_t, sizeof(HDMI_AUDIO_T));
	return 1;
}

unsigned char newbase_hdmi_get_drm_infoframe(unsigned char port, HDMI_DRM_T *p_drm_t)
{
	if (GET_H_VIDEO_FSM(port) < MAIN_FSM_HDMI_VIDEO_READY || GET_H_MODE(port) != MODE_HDMI) {
		return 0;
	}

	if (hdmi_rx[port].drm_t.type_code == 0) {
		return 0;
	}

	if (hdmi_in(DEBUG_REG_ADDR)&DEBUG_22_FORCE_NO_DRMPKT) {
		return 0;
	}

	memcpy(p_drm_t, &hdmi_rx[port].drm_t, sizeof(HDMI_DRM_T));
	return 1;
}


unsigned char newbase_hdmi_update_vsi(unsigned char port)
{

#if 0
#define VSI_PKT_LEN	31
	unsigned char sta_pos, len, pkt_buf[VSI_PKT_LEN]={0};

#if HDMI2p0
	if (lib_hdmi_is_fvs_received(port)) {
		lib_hdmi_clear_fvs_received_status(port);
		sta_pos = 253;
		len = 11;
	} else
#endif
	if (lib_hdmi_is_vs_received(port)) {
		lib_hdmi_clear_vs_received_status(port);
		sta_pos = 203;
		len = 18;
	} else {
		return FALSE;
	}


	lib_hdmi_read_packet_sram(port, sta_pos, len, pkt_buf);
	pkt_buf[2] = pkt_buf[1];	//len
	pkt_buf[1] = pkt_buf[0];	//version
	pkt_buf[0] = 0x81;

	memcpy(&hdmi_rx[port].vsi_t, pkt_buf, len); //use len for memcpy because copy size will be 11 or 18
	return TRUE;
#else

#define VSI_MAX_PKT_LEN (18 + 12) // setting 30 if change for application
#define VSI_PKT_LEN	18
	unsigned char sta_pos,len,pkt_buf[VSI_MAX_PKT_LEN]={0};
	unsigned char len1=0;

#if HDMI2p0
	if (lib_hdmi_is_fvs_received(port)) {
		lib_hdmi_clear_fvs_received_status(port);
		sta_pos = 253;
		len = 11;
	} else
#endif

	if (lib_hdmi_is_vs_received(port)) {
		lib_hdmi_clear_vs_received_status(port);
		sta_pos = 203;
		len = 18;
	} else {
		return FALSE;
	}


	lib_hdmi_read_packet_sram(port, sta_pos, len, pkt_buf);
	pkt_buf[2] = pkt_buf[1];	//len
	pkt_buf[1] = pkt_buf[0];	//version
	pkt_buf[0] = 0x81;

	if (sta_pos == 203) {
		len1 = pkt_buf[2] + 3;
		if ((len1 > VSI_PKT_LEN) && (len1 <= VSI_MAX_PKT_LEN)) {
			lib_hdmi_read_packet_sram(port, 323,  len1 - VSI_PKT_LEN  ,  pkt_buf + VSI_PKT_LEN);
			len = len1;
		}
	}

	memcpy(&hdmi_rx[port].vsi_t, pkt_buf, len); //use len for memcpy because copy size will be 11 or 18
	return TRUE;


#endif

}

unsigned char newbase_hdmi_update_avi(unsigned char port)
{

#if 0
#define AVI_PKT_LEN	16
	unsigned char pkt_buf[AVI_PKT_LEN]={0};

	if (!lib_hdmi_is_avi_received(port)) {
		return FALSE;
	}

	lib_hdmi_clear_avi_received_status(port);

	lib_hdmi_read_packet_sram(port, 1, AVI_PKT_LEN, pkt_buf);
	pkt_buf[2] = pkt_buf[1];	//len
	pkt_buf[1] = pkt_buf[0];	//version
	pkt_buf[0] = 0x82;

	memcpy(&hdmi_rx[port].avi_t, pkt_buf, sizeof(HDMI_AVI_T));

	return TRUE;

#else

	#define AVI_MAX_PKT_LEN (16 + 14) //change for application
	#define AVI_PKT_LEN	16
	unsigned char pkt_buf[AVI_MAX_PKT_LEN]={0};
	unsigned char len = 0;

	if (!lib_hdmi_is_avi_received(port)) {
		return FALSE;
	}

	lib_hdmi_clear_avi_received_status(port);

	lib_hdmi_read_packet_sram(port, 1, AVI_PKT_LEN, pkt_buf);
	pkt_buf[2] = pkt_buf[1];	//len
	pkt_buf[1] = pkt_buf[0];	//version
	pkt_buf[0] = 0x82;

	len = pkt_buf[2] + 3;
	if ((len > AVI_PKT_LEN)&& (len <= AVI_MAX_PKT_LEN)) {
		lib_hdmi_read_packet_sram(port, 335,   len - AVI_PKT_LEN  ,  pkt_buf + AVI_PKT_LEN);
	}

	memcpy(&hdmi_rx[port].avi_t, pkt_buf, sizeof(HDMI_AVI_T));

	return TRUE;

#endif

}

unsigned char newbase_hdmi_update_spd(unsigned char port)
{
#define SPD_PKT_LEN	28
	unsigned char pkt_buf[SPD_PKT_LEN]={0};

	if (!lib_hdmi_is_spd_received(port)) {
		return FALSE;
	}

	lib_hdmi_clear_spd_received_status(port);

	lib_hdmi_read_packet_sram(port, 295, SPD_PKT_LEN, pkt_buf);
	pkt_buf[2] = pkt_buf[1];	//len
	pkt_buf[1] = pkt_buf[0];	//version
	pkt_buf[0] = 0x83;

	memcpy(&hdmi_rx[port].spd_t, pkt_buf, sizeof(HDMI_SPD_T));
	return TRUE;
}

unsigned char newbase_hdmi_update_audiopkt(unsigned char port)
{
#define AUDIO_PKT_LEN	13
	unsigned char pkt_buf[AUDIO_PKT_LEN]={0};

	if (!lib_hdmi_is_audiopkt_received(port)) {
		return FALSE;
	}

	lib_hdmi_clear_audiopkt_received_status(port);

	lib_hdmi_read_packet_sram(port, 18, AUDIO_PKT_LEN, pkt_buf);
	pkt_buf[2] = pkt_buf[1];	//len
	pkt_buf[1] = pkt_buf[0];	//version
	pkt_buf[0] = 0x84;

	memcpy(&hdmi_rx[port].audiopkt_t, pkt_buf, AUDIO_PKT_LEN);
	return TRUE;

}

unsigned char newbase_hdmi_update_drm(unsigned char port)
{
#define DRM_PKT_LEN	29
	unsigned char pkt_buf[DRM_PKT_LEN]={0};

	if (!lib_hdmi_is_drm_received(port)) {
		return FALSE;
	}

	lib_hdmi_clear_drm_received_status(port);

	lib_hdmi_read_packet_sram(port, 265, DRM_PKT_LEN, pkt_buf);

	((unsigned char*)(&hdmi_rx[port].drm_t))[2] = pkt_buf[1]; // len
	((unsigned char*)(&hdmi_rx[port].drm_t))[1] = pkt_buf[0]; // version
	((unsigned char*)(&hdmi_rx[port].drm_t))[0] = 0x87; // Info Frame Type

	hdmi_rx[port].drm_t.eEOTFtype       = pkt_buf[3];
	hdmi_rx[port].drm_t.eMeta_Desc     = pkt_buf[4];
	hdmi_rx[port].drm_t.display_primaries_x0 = pkt_buf[5]|(pkt_buf[6]<<8);
	hdmi_rx[port].drm_t.display_primaries_y0 = pkt_buf[7]|(pkt_buf[8]<<8);
	hdmi_rx[port].drm_t.display_primaries_x1 = pkt_buf[9]|(pkt_buf[10]<<8);
	hdmi_rx[port].drm_t.display_primaries_y1 = pkt_buf[11]|(pkt_buf[12]<<8);
	hdmi_rx[port].drm_t.display_primaries_x2 = pkt_buf[13]|(pkt_buf[14]<<8);
	hdmi_rx[port].drm_t.display_primaries_y2 = pkt_buf[15]|(pkt_buf[16]<<8);
	hdmi_rx[port].drm_t.white_point_x = pkt_buf[17]|(pkt_buf[18]<<8);
	hdmi_rx[port].drm_t.white_point_y = pkt_buf[19]|(pkt_buf[20]<<8);
	hdmi_rx[port].drm_t.max_display_mastering_luminance = pkt_buf[21]|(pkt_buf[22]<<8);
	hdmi_rx[port].drm_t.min_display_mastering_luminance = pkt_buf[23]|(pkt_buf[24]<<8);
	hdmi_rx[port].drm_t.maximum_content_light_level = pkt_buf[25]|(pkt_buf[26]<<8);
	hdmi_rx[port].drm_t.maximum_frame_average_light_level = pkt_buf[27]|(pkt_buf[28]<<8);

	return TRUE;
}


unsigned char newbase_hdmi_update_rsv0_packet(unsigned char port, unsigned char len, unsigned char *buf)
{
	if (!lib_hdmi_is_rsv_packet0_received(port)) {
		return FALSE;
	}

	lib_hdmi_read_packet_sram(port, 78, len, buf);
	return TRUE;
}

unsigned char newbase_hdmi_update_rsv1_packet(unsigned char port, unsigned char len, unsigned char *buf)
{
	if (!lib_hdmi_is_rsv_packet1_received(port)) {
		return FALSE;
	}

	lib_hdmi_read_packet_sram(port, 109, len, buf);
	return TRUE;
}

unsigned char newbase_hdmi_update_rsv2_packet(unsigned char port, unsigned char len, unsigned char *buf)
{
	if (!lib_hdmi_is_rsv_packet2_received(port)) {
		return FALSE;
	}

	lib_hdmi_read_packet_sram(port, 140, len, buf);
	return TRUE;
}

unsigned char newbase_hdmi_update_rsv3_packet(unsigned char port, unsigned char len, unsigned char *buf)
{
	if (!lib_hdmi_is_rsv_packet3_received(port)) {
		return FALSE;
	}

	lib_hdmi_read_packet_sram(port, 171, len, buf);
	return TRUE;
}


unsigned char newbase_hdmi_check_spd_name(unsigned char port, unsigned char *vendor_name)
{
	unsigned char i;

	if (hdmi_rx[port].spd_t.type_code == 0)
		return 0;

#if 0
	HDMI_PRINTF("VendorName [%x, %x, %x, %x, %x, %x, %x, %x]\n",
		hdmi_rx[port].spd_t.VendorName[0], hdmi_rx[port].spd_t.VendorName[1],
		hdmi_rx[port].spd_t.VendorName[2], hdmi_rx[port].spd_t.VendorName[3],
		hdmi_rx[port].spd_t.VendorName[4], hdmi_rx[port].spd_t.VendorName[5],
		hdmi_rx[port].spd_t.VendorName[6], hdmi_rx[port].spd_t.VendorName[7]);
#endif

	for (i=0; i<8; i++) {
		if (hdmi_rx[port].spd_t.VendorName[i] != vendor_name[i]) {
			return 0;
		}
	}

	return 1;
}

unsigned char newbase_hdmi_check_spd_prod(unsigned char port, unsigned char *prod_desc)
{
	unsigned char i;

	if (hdmi_rx[port].spd_t.type_code == 0)
		return 0;

#if 0
	HDMI_PRINTF("ProductDesc [%x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x]\n",
		hdmi_rx[port].spd_t.ProductDesc[0], hdmi_rx[port].spd_t.ProductDesc[1],
		hdmi_rx[port].spd_t.ProductDesc[2], hdmi_rx[port].spd_t.ProductDesc[3],
		hdmi_rx[port].spd_t.ProductDesc[4], hdmi_rx[port].spd_t.ProductDesc[5],
		hdmi_rx[port].spd_t.ProductDesc[6], hdmi_rx[port].spd_t.ProductDesc[7],
		hdmi_rx[port].spd_t.ProductDesc[8], hdmi_rx[port].spd_t.ProductDesc[9],
		hdmi_rx[port].spd_t.ProductDesc[10], hdmi_rx[port].spd_t.ProductDesc[11],
		hdmi_rx[port].spd_t.ProductDesc[12], hdmi_rx[port].spd_t.ProductDesc[13],
		hdmi_rx[port].spd_t.ProductDesc[14], hdmi_rx[port].spd_t.ProductDesc[15]);
#endif

	for (i=0; i<16; i++) {
		if (hdmi_rx[port].spd_t.ProductDesc[i] != prod_desc[i]) {
			return 0;
		}
	}

	return 1;
}

unsigned char newbase_hdmi_check_aksv(unsigned char port, unsigned char *aksv)
{
	unsigned char i;

#if 0
	HDMI_PRINTF("AKSV [%x, %x, %x, %x, %x]\n",
	hdmi_rx[port].tx_aksv[0], hdmi_rx[port].tx_aksv[1],
	hdmi_rx[port].tx_aksv[2], hdmi_rx[port].tx_aksv[3],
	hdmi_rx[port].tx_aksv[4]);
#endif

	for (i = 0; i < 5; i++) {
		if (hdmi_rx[port].tx_aksv[i] != aksv[i]) {
			return 0;
		}
	}

	return 1;
}






unsigned char newbase_hdmi_compatibility_check(unsigned char port)
{
	HDMI_POOR_DEV_T btv_stb = {{0x42, 0x72, 0x6f, 0x61, 0x64, 0x63, 0x6f, 0x6d},
				{0x53, 0x54, 0x42, 0x20, 0x52, 0x65, 0x66, 0x73, 0x77, 0x20, 0x44, 0x65, 0x73, 0x69, 0x67, 0x6e}};

#if HDMI_TOGGLE_HPD_Z0_ENABLE
	// [STB-14] KT UHD STB (IC1000)
	HDMI_POOR_DEV_T kt_stb_IC1000 = {{0x4b, 0x61, 0x6f, 0x6e, 0x00, 0x63, 0x6f, 0x6d},
				{0x49, 0x43, 0x31, 0x30, 0x30, 0x30, 0x00, 0x63, 0x65, 0x20, 0x42, 0x6f, 0x61, 0x72, 0x64, 0x00}};

	lib_hdmi_set_toggle_hpd_z0_flag(port, _FALSE);
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE
#if HDMI_STR_TOGGLE_HPD_ENABLE
	// [STB-20] IC1100 - KT olleh GiGA UHD tv STB
	HDMI_POOR_DEV_T kt_stb_IC1100 = {{0x4b, 0x61, 0x6f, 0x6e, 0x00, 0x63, 0x6f, 0x6d},
				{0x49, 0x43, 0x31, 0x31, 0x30, 0x30, 0x00, 0x63, 0x65, 0x20, 0x42, 0x6f, 0x61, 0x72, 0x64, 0x00}};

	lib_hdmi_set_str_toggle_hpd_state(port, HDMI_STR_HPD_TOGGLE_NONE);
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE

#if HDMI_DISPLAY_DELAY_ENABLE
	// [HOME-05] LHB755 - LG
	HDMI_POOR_DEV_T LHB755 = {{0x4d, 0x54, 0x4b, 0x00, 0x00, 0x00, 0x00, 0x00},
				{0x42, 0x44, 0x20, 0x50, 0x4c, 0x41, 0x59, 0x45, 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

//	unsigned char LHB755_NG_aksv[5] = {0};

//	lib_hdmi_set_delay_display_enable(port, _DISABLE); //move to lib_hdmi_misc_variable_initial(), to prevent Tx SPD and AKSV unstable

	// Roku Ultra 4640R
	HDMI_POOR_DEV_T Roku_Ultra_4640R = {{0x4d, 0x00, 0x74, 0x00, 0x72, 0x00, 0x20, 0x00},
				{0x48, 0x00, 0x4d, 0x00, 0x20, 0x00, 0x78, 0x00, 0x44, 0x00, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00}};
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

//	lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_NONE); //move to lib_hdmi_misc_variable_initial(), to prevent Tx SPD and AKSV unstable

	hpd_low_ms = HPD_DEFAULT_LOW_MS;

	if (newbase_hdmi_check_spd_name(port, btv_stb.spd_vn_name) && newbase_hdmi_check_spd_prod(port, btv_stb.psd_pd_desc)) {
		//[WOSQRTK-9185]SKbox transient garbage
		HDMI_EMG("This is SKBOX!!!!!!!\n");
		lib_hdmi_hdcp_port_write(port, 0xC4, 0x8);
		lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_SK_STB);
		if((first_time_detect==1)&&(hdmi_rx[port].timing_t.h_act_len==1920)&&(hdmi_rx[port].timing_t.v_act_len==1080)&&(ABS(hdmi_rx[port].timing_t.v_freq,500)<10))
		{	
			HDMI_EMG(" lzqmsg==>reset hpd");
			SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_SETUP_VEDIO_PLL);
			first_time_detect=0;
			newbase_hdmi_set_hpd(port, 0,1);//pull low HPD for specify ports
			newbase_hdmi_hpd_delay_work_init();
			return 0;
		}
	}
#if HDMI_TOGGLE_HPD_Z0_ENABLE
	else if (newbase_hdmi_check_spd_name(port, kt_stb_IC1000.spd_vn_name) && newbase_hdmi_check_spd_prod(port, kt_stb_IC1000.psd_pd_desc)) {
		//[WOSQRTK-9185]SKbox transient garbage
		HDMI_EMG("This is KT STB IC1000 !!!!!!!\n");
		lib_hdmi_set_toggle_hpd_z0_flag(port, _TRUE);
		lib_hdmi_dc_on_delay_check(port, _TRUE);
		lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_KT_STB_IC1000);
	}
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE
#if HDMI_STR_TOGGLE_HPD_ENABLE
	else if (newbase_hdmi_check_spd_name(port, kt_stb_IC1100.spd_vn_name) && newbase_hdmi_check_spd_prod(port, kt_stb_IC1100.psd_pd_desc)) {
		//[WOSQRTK-10334] KT STB and TV STR off/on, can not display
		HDMI_EMG("This is KT STB IC1100 !!!!!!!\n");
		lib_hdmi_set_str_toggle_hpd_state(port, HDMI_STR_HPD_TOGGLE_ENTER);
		lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_KT_STB_IC1100);
	}
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE
#if HDMI_DISPLAY_DELAY_ENABLE
	else if (newbase_hdmi_check_spd_name(port, LHB755.spd_vn_name) && newbase_hdmi_check_spd_prod(port, LHB755.psd_pd_desc)) {
		//[WOSQRTK-10006] [HOME-05] LHB755 - LG, change timing flicker
		HDMI_EMG("This is DVD LHB755 !!!!!!!\n");
		lib_hdmi_set_delay_display_enable(port, _ENABLE);
		lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_LHB_755);

		if(HDMI_DISPLAY_DELAY_NONE == lib_hdmi_get_delay_display_state(port))
		{
			lib_hdmi_set_delay_display_state(port, HDMI_DISPLAY_DELAY_INIT);
			lib_hdmi_delay_check_before_display(port, _TRUE);
		}
	}
#if HDCP2_2
	else if (newbase_hdmi_check_spd_name(port, Roku_Ultra_4640R.spd_vn_name) && newbase_hdmi_check_spd_prod(port, Roku_Ultra_4640R.psd_pd_desc)) {
		//[WOSQRTK-10397] [WOSQRTK-10396] [WOSQRTK-10389] [WOSQRTK-10385] Roku Ultra 4640R
		if(_ENABLE == lib_hdmi_hdcp22_is_onoff(port))
		{
			HDMI_EMG("This is Roku Ultra 4640R !!!!!!!\n");
	//		lib_hdmi_set_delay_display_enable(port, _ENABLE);
	//		lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_ROKU_ULTRA_4640R);

			if(HDMI_DISPLAY_DELAY_NONE == lib_hdmi_get_delay_display_state(port))
			{
	//			lib_hdmi_set_delay_display_state(port, HDMI_DISPLAY_DELAY_INIT);
	//			lib_hdmi_delay_check_before_display(port, _TRUE);
			}
		}
		else// if(_DISABLE == lib_hdmi_hdcp22_is_onoff(port))
		{
			HDMI_EMG("This is Roku Ultra 4640R-Not HDCP22\n");
		}

	//	lib_hdmi_hdcp_status_check(port, _TRUE);
	//	hpd_low_ms = HPD_ROKU_ULTRA_4640R_LOW_MS;
	}
#endif //#if HDCP2_2
#endif //#if HDMI_DISPLAY_DELAY_ENABLE
	else {
		// init variable
	}

#ifdef HDMI_AVI_INFO_COLORIMETRY_ENABLE
	if(_FALSE == newbase_hdmi_check_avi_colorimetry_info(port, _FALSE)) {
//					SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_MEASURE);
		SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_SETUP_VEDIO_PLL);
		return FALSE;
	}
#endif //#ifdef HDMI_AVI_INFO_COLORIMETRY_ENABLE

#ifdef HDMI_CHECK_HDCP_ENABLE
	if(_FALSE == newbase_hdmi_check_hdcp_condition(port, _FALSE)) {
//					SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_MEASURE);
		SET_H_VIDEO_FSM(port, MAIN_FSM_HDMI_SETUP_VEDIO_PLL);
		return FALSE;
	}
#endif //#ifdef HDMI_CHECK_HDCP_ENABLE

	//newbase_hdmi_check_deb_condition_beforeDisp(port, _FALSE);	////STABLE_CHECK_OLD_PATCH
	first_time_detect=1;
	return TRUE;

}



//USER:Lewislee DATE:2016/08/26
//to fix blu-ray player, NS-BRDVD short time unstable
unsigned char newbase_hdmi_check_stable_before_display(void)
{
	unsigned char port = current_port;

#if 0 //STABLE_CHECK_OLD_PATCH
	if (bNeedDebBeforeDisp == 1)
	{
		if( DispDebCnt > 0 ) {
			HDMI_PRINTF("------>debouncing =%d, %d\n", bNeedDebBeforeDisp,  DispDebCnt);
			DispDebCnt--;
			return FALSE;
		}
	}
	bNeedDebBeforeDisp = 0;
	DispDebCondition = 0;
#endif

#if HDMI_DISPLAY_DELAY_ENABLE
	if(_FALSE == lib_hdmi_delay_check_before_display(port, _FALSE))
	{
		if(_TRUE == lib_hdmi_delay_display_action(port))
		{
			//need to debounce, skip now
//			return _FALSE;
		}
	}

	lib_hdmi_set_delay_display_enable(port, _DISABLE);
	lib_hdmi_set_delay_display_state(port, HDMI_DISPLAY_DELAY_NONE);
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

	if (hdmi_in(DEBUG_REG_ADDR) & DEBUG_27_BYPASS_CHECK)
	{
		return TRUE;
	}

	if (GET_H_VIDEO_FSM(port) != MAIN_FSM_HDMI_VIDEO_READY)
	{
		HDMI_EMG("B-check_mode_changed_1(p=%d)\n", port);
		return FALSE;
	}

#if HDMI_TOGGLE_HPD_Z0_ENABLE
	if(_FALSE == lib_hdmi_dc_on_delay_check(port, _FALSE))
		return FALSE;
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	if (newbase_hdmi_check_condition_change(port))
	{
		lib_hdmi_video_output(port, 0);
		lib_hdmi_audio_output(port, 0);
		HDMI_EMG("B-check_mode_changed_2(p=%d)\n", port);
		return FALSE;
	}

	if (GET_H_INTERLACE(port) != newbase_hdmi_get_interlace_conti_mode(port))
	{
		HDMI_EMG("B-interlace chg from %d to %d\n", GET_H_INTERLACE(port), (!GET_H_INTERLACE(port)));
		return FALSE;
	}

	 if (GET_H_PIXEL_REPEAT(port) != lib_hdmi_get_pixelrepeat(port)) {
	  HDMI_EMG("B-PR chg from %d to %d\n", GET_H_PIXEL_REPEAT(port), lib_hdmi_get_pixelrepeat(port));
	  return FALSE;
	 }
#if HDR10_MD_INFO_CHECK
	//Minchay@20160607-a add hdr10 md check
	if (!newbase_hdmi_hdr10_md_info_check())
	{
		HDMI_PRINTF("B-[HDR10] check mode fail\n");
		return FALSE;
	}
#endif //#if HDR10_MD_INFO_CHECK

	return TRUE;
}

//USER:LewisLee Date:2016/09/29
//to prevent HDR mode or other case
//HDMI Watchdog turn on.
//But VSC foreground source is not HDMI, it maybe make picture abnormal
unsigned char newbase_hdmi_watchdog_apply(unsigned char Enable, unsigned char Condition)
{
#ifdef HDMI_VIDEO_WD_ENABLE
	UINT8 nport;
	UINT8 ucEnable_WatchDog = _FALSE;
	static UINT8 ucWatchDog_Mask = 0x00;
	#ifdef CONFIG_FORCE_RUN_I3DDMA
	dma_vgip_dma_vgip_ctrl_RBUS dma_vgip_dma_vgip_ctrl_reg;
	#endif
#ifndef CONFIG_FORCE_RUN_I3DDMA
	vgip_vgip_chn1_ctrl_RBUS vgip_vgip_chn1_ctrl_reg;
	#ifdef CONFIG_DUAL_CHANNEL
	sub_vgip_vgip_chn2_ctrl_RBUS sub_vgip_vgip_chn2_ctrl_reg;
	#endif //#ifdef CONFIG_DUAL_CHANNEL
#endif
	nport = newbase_hdmi_get_current_display_port();


	if(_ENABLE == Enable)
	{
		ucWatchDog_Mask = ucWatchDog_Mask | Condition;
	}
	else// if(_DISABLE == Enable)
	{
		ucWatchDog_Mask = ucWatchDog_Mask & (~Condition);
	}

	if(HDMI_WD_ALL_COND == (ucWatchDog_Mask & (HDMI_WD_VIDEO_COND | HDMI_WD_AUDIO_COND | HDMI_WD_VSC_COND)))
		ucEnable_WatchDog = _TRUE;
	else// if(HDMI_WD_ALL_COND != (ucWatchDog_Mask & (HDMI_WD_VIDEO_COND | HDMI_WD_AUDIO_COND | HDMI_WD_VSC_COND)))
		ucEnable_WatchDog = _FALSE;

	if(MODE_DVI == GET_H_MODE(nport))
	{
		ucEnable_WatchDog = _DISABLE;
	}

//	HDMI_INFO("drvif_Hdmi_WatchDog_Apply, Enable=%x, Condition=%x, nport=%x, ucWatchDog_Mask=%x, ucEnable_WatchDog=%x\n",
//		Enable, Condition, nport, ucWatchDog_Mask, ucEnable_WatchDog);

#ifdef CONFIG_FORCE_RUN_I3DDMA
	if (newbase_hdmi_is_dispsrc(SLR_MAIN_DISPLAY))
	{
		dma_vgip_dma_vgip_ctrl_reg.regValue = hdmi_in(DMA_VGIP_DMA_VGIP_CTRL_reg);

		if(0 == dma_vgip_dma_vgip_ctrl_reg.dma_in_sel)
		{
//			HDMI_PRINTF("DMA Channel Is HDMI\n");
		}
		else// if(0 != dma_vgip_dma_vgip_ctrl_reg.dma_in_sel)
		{
			ucEnable_WatchDog = _DISABLE;
//			HDMI_PRINTF("DMA Channel Not HDMI a\n");
		}
	}
	else
	{
		ucEnable_WatchDog = _DISABLE;
//		HDMI_PRINTF("DMA Channel Not HDMI b\n");
	}
#else //#ifdef CONFIG_FORCE_RUN_I3DDMA
	if (newbase_hdmi_is_dispsrc(SLR_MAIN_DISPLAY))
	{
		vgip_vgip_chn1_ctrl_reg.regValue = hdmi_in(VGIP_VGIP_CHN1_CTRL_reg);

		if(0 == vgip_vgip_chn1_ctrl_reg.ch1_in_sel)
		{
//			HDMI_PRINTF("Main Channel Is HDMI\n");
		}
		else
		{
			ucEnable_WatchDog = _DISABLE;
		}
	}
#ifdef CONFIG_DUAL_CHANNEL
	if (newbase_hdmi_is_dispsrc(SLR_SUB_DISPLAY))
	{
		sub_vgip_vgip_chn2_ctrl_reg.regValue = hdmi_in(SUB_VGIP_VGIP_CHN2_CTRL_reg);

		if(0 == sub_vgip_vgip_chn2_ctrl_reg.ch2_in_sel)
		{
//			HDMI_PRINTF("Sub Channel Is HDMI\n");
		}
		else
		{
			ucEnable_WatchDog = _DISABLE;
		}
	}
#endif //#ifdef CONFIG_DUAL_CHANNEL

#if (!defined(__QC_VERIFY_COMMON_H__))
	else
	{
		ucEnable_WatchDog = _DISABLE;
	}
#endif

#endif //#ifdef CONFIG_FORCE_RUN_I3DDMA
/*
	if(GET_H_AUDIO_FSM(nport) < AUDIO_FSM_AUDIO_CHECK)
	{
		ucEnable_WatchDog = _DISABLE;
	}
*/

	if(_ENABLE == ucEnable_WatchDog)
	{
		lib_hdmi_wdm_enable(nport, 1);
		lib_hdmi_auto_avmute_enable(nport, 1);
		//hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~(HDMI_HDMI_WDCR0_wdm_mask | HDMI_HDMI_WDCR0_asmfe_mask),
		//	HDMI_HDMI_WDCR0_wdm(1) | HDMI_HDMI_WDCR0_asmfe(1));
	}
	else// if(_DISABLE == ucEnable_WatchDog)
	{
		lib_hdmi_wdm_enable(nport, 0);
		lib_hdmi_auto_avmute_enable(nport, 0);
		//hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~(HDMI_HDMI_WDCR0_wdm_mask | HDMI_HDMI_WDCR0_asmfe_mask),
		//	HDMI_HDMI_WDCR0_wdm(0) | HDMI_HDMI_WDCR0_asmfe(0));
	}
#endif //#ifdef HDMI_VIDEO_WD_ENABLE

	return _FALSE;
}

//USER:LewisLee Date:2016/09/30
//to fix colorimetry NG case
unsigned char newbase_hdmi_check_avi_colorimetry_info(unsigned char port, unsigned char ucInit)
{
#ifdef HDMI_AVI_INFO_COLORIMETRY_ENABLE
	static unsigned char avi_debounce[HDMI_RX_PORT_MAX_NUM];

	if(_TRUE == ucInit)
	{
		avi_debounce[port] = HDMI_AVI_INFO_COLORIMETRY_DEBOUNCE_CNT;
		return _TRUE;
	}

	if (port >= HDMI_RX_PORT_MAX_NUM)
	{
		return _TRUE;
	}

	if (MODE_DVI == GET_H_MODE(port))
	{
		return _TRUE;
	}

	// 160ms/times
	if(2 == hdmi_rx[port].avi_t.type_code)
	{
		if(0 == hdmi_rx[port].avi_t.len)
		{
			//for other case
		}
		else// if(0 != hdmi_rx[port].avi_t.len)
		{
			if((0 == hdmi_rx[port].avi_t.EC) && (0 == hdmi_rx[port].avi_t.C))
			{
				if(avi_debounce[port])
				{
					//Just for 2 depth = LG Bluray BP-550 + Speaker YAMAHA YSP-5600
					//special case, wait more time
					if((0x59 == hdmi_rx[port].spd_t.VendorName[0]) && (0x61 == hdmi_rx[port].spd_t.VendorName[1])
						&& (0x6d == hdmi_rx[port].spd_t.VendorName[2]) && (0x61 == hdmi_rx[port].spd_t.VendorName[3])
						&& (0x68 == hdmi_rx[port].spd_t.VendorName[4]) && (0x61 == hdmi_rx[port].spd_t.VendorName[5])
						&& (0x00 == hdmi_rx[port].spd_t.VendorName[6]) && (0x00 == hdmi_rx[port].spd_t.VendorName[7]))
					{
						avi_debounce[port]--;
						HDMI_EMG("EC /C avi_debounce1=%x\n", avi_debounce[port]);
						return _FALSE;
					}
#if 0
					HDMI_PRINTF("VendorName [%x, %x, %x, %x, %x, %x, %x, %x]\n", hdmi_rx[port].spd_t.VendorName[0],
						hdmi_rx[port].spd_t.VendorName[1], hdmi_rx[port].spd_t.VendorName[2],
						hdmi_rx[port].spd_t.VendorName[3], hdmi_rx[port].spd_t.VendorName[4],
						hdmi_rx[port].spd_t.VendorName[5], hdmi_rx[port].spd_t.VendorName[6],
						hdmi_rx[port].spd_t.VendorName[7]);

					HDMI_EMG("EC /C avi_debounce1 exit\n");
#endif //#if 0
				}
			}
		}
	}
#endif //#ifdef HDMI_AVI_INFO_COLORIMETRY_ENABLE

	return _TRUE;
}

//==========================================

unsigned char newbase_hdmi_no_SPD_packetInfo(unsigned char nport)
{
	if( (0 == hdmi_rx[nport].spd_t.VendorName[0]) && (0 == hdmi_rx[nport].spd_t.VendorName[1])
		&& (0 == hdmi_rx[nport].spd_t.VendorName[2]) && (0 == hdmi_rx[nport].spd_t.VendorName[3])
		&& (0 == hdmi_rx[nport].spd_t.VendorName[4]) && (0 == hdmi_rx[nport].spd_t.VendorName[5])
		&& (0 == hdmi_rx[nport].spd_t.VendorName[6]) && (0 == hdmi_rx[nport].spd_t.VendorName[7]))
	{
		if((0 == hdmi_rx[nport].spd_t.ProductDesc[0]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[1])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[2]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[3])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[4]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[5])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[6]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[7])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[8]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[9])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[10]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[11])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[12]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[13])
			&& (0 == hdmi_rx[nport].spd_t.ProductDesc[14]) && (0 == hdmi_rx[nport].spd_t.ProductDesc[15]))
		{
			return _TRUE;
		}
	}
	return _FALSE;
}

//==========================================

#if 0  //STABLE_CHECK_OLD_PATCH
unsigned char newbase_hdmi_check_deb_condition_beforeDisp(unsigned char nport, unsigned char ucInit)
{
//#ifdef HDMI_CHECK_HDCP_ENABLE

	unsigned int cur_v_act_len = hdmi_rx[nport].timing_t.v_act_len;
	unsigned int cur_h_act_len = hdmi_rx[nport].timing_t.h_act_len;

	if(_TRUE == ucInit)
	{
		if(bNeedDebBeforeDisp == 0 ) {
			DispDebCnt = 0;
		}
		return _TRUE;
	}

	if (nport >= HDMI_PORT_TOTAL_NUM)
	{
		return _TRUE;
	}

	if( ((cur_h_act_len==1280 && cur_v_act_len == 720) ||(cur_h_act_len==1360 && cur_v_act_len == 768)
		||(cur_h_act_len==1920 && cur_v_act_len == 540) ||(cur_h_act_len == 3840 && cur_v_act_len == 2160))
#if HDCP2_2
		&& ( (_ENABLE == lib_hdmi_hdcp14_is_onoff(nport)) && (_ENABLE ==lib_hdmi_hdcp22_is_onoff(nport)) )
#else
		&& (_ENABLE == lib_hdmi_hdcp14_is_onoff(nport))
#endif
		&& (_TRUE == newbase_hdmi_no_SPD_packetInfo(nport)) )
	{
		HDMI_PRINTF("...............checking h/v= (%d, %d) [%d-%d], c=%d, vic=%d\n", cur_h_act_len, cur_v_act_len, bNeedDebBeforeDisp, DispDebCondition, DispDebCnt, hdmi_rx[nport].avi_t.VIC);

		//deb start point: condition1
		if( (cur_h_act_len==1360 && cur_v_act_len == 768) && (bNeedDebBeforeDisp == 0) && (hdmi_rx[nport].avi_t.VIC == 0))
		{
			bNeedDebBeforeDisp = 1;
			DispDebCnt = DISP_DEB_CNT_APPLETV;
			DispDebCondition = 1;

			HDMI_PRINTF("**************************** disp deb start1!!\n");
		}

		//deb again: condition2 =1360x768->1280x720
		if((cur_h_act_len==1280 && cur_v_act_len == 720) && (DispDebCondition==1))
		{
			DispDebCnt = DISP_DEB_CNT_APPLETV;
			DispDebCondition = 2;

			HDMI_PRINTF("**************************** disp deb start2!!\n");
		}

		//LewisLee DATE:2016/12/22
		//WOSQRTK-10354, PC40000
		// 3840x2160 timing, HDMI cable plug in/out will flicker
		if( (cur_h_act_len == 3840 && cur_v_act_len == 2160) && (bNeedDebBeforeDisp == 0) && (hdmi_rx[nport].avi_t.VIC == 0))
		{
			bNeedDebBeforeDisp = 1;
			DispDebCnt = DISP_DEB_CNT_PC40000;
			DispDebCondition = 3;

			HDMI_PRINTF("**************************** disp deb start3!!\n");
		}
	}
	else {

		DispDebCondition = 0;
		DispDebCnt = 0;
		bNeedDebBeforeDisp = 0;
	}
//#endif //#ifdef HDMI_CHECK_HDCP_ENABLE

	return _TRUE;
}
#endif

//==========================================

//USER:LewisLee Date:2016/10/08
//Fix TV power on, PS 4 flocker
//No HDCP => stable clock => display => HDCP => flicker => display
unsigned char newbase_hdmi_check_hdcp_condition(unsigned char nport, unsigned char ucInit)
{
#ifdef HDMI_CHECK_HDCP_ENABLE
	hdmi_p0_port0_hdcp_flag1_RBUS hdmi_p0_port0_hdcp_flag1_reg;
	static unsigned char HDCP_debounce[HDMI_RX_PORT_MAX_NUM];

	if(_TRUE == ucInit)
	{
		HDCP_debounce[nport] = HDMI_HDCP_DEBOUNCE_CNT;
		return _TRUE;
	}

	if (nport >= HDMI_RX_PORT_MAX_NUM)
	{
		return _TRUE;
	}

	if (MODE_DVI == GET_H_MODE(nport))
	{
		return _TRUE;
	}

	if(0 == HDCP_debounce[nport])
		return _TRUE;

#if 0
	HDMI_PRINTF("VendorName [%x, %x, %x, %x, %x, %x, %x, %x]\n", hdmi_rx[nport].spd_t.VendorName[0],
		hdmi_rx[nport].spd_t.VendorName[1], hdmi_rx[nport].spd_t.VendorName[2],
		hdmi_rx[nport].spd_t.VendorName[3], hdmi_rx[nport].spd_t.VendorName[4],
		hdmi_rx[nport].spd_t.VendorName[5], hdmi_rx[nport].spd_t.VendorName[6],
		hdmi_rx[nport].spd_t.VendorName[7]);

	HDMI_PRINTF("ProductDesc [%x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x, %x]\n",
		hdmi_rx[nport].spd_t.ProductDesc[0], hdmi_rx[nport].spd_t.ProductDesc[1],
		hdmi_rx[nport].spd_t.ProductDesc[2], hdmi_rx[nport].spd_t.ProductDesc[3],
		hdmi_rx[nport].spd_t.ProductDesc[4], hdmi_rx[nport].spd_t.ProductDesc[5],
		hdmi_rx[nport].spd_t.ProductDesc[6], hdmi_rx[nport].spd_t.ProductDesc[7],
		hdmi_rx[nport].spd_t.ProductDesc[8], hdmi_rx[nport].spd_t.ProductDesc[9],
		hdmi_rx[nport].spd_t.ProductDesc[10], hdmi_rx[nport].spd_t.ProductDesc[11],
		hdmi_rx[nport].spd_t.ProductDesc[12], hdmi_rx[nport].spd_t.ProductDesc[13],
		hdmi_rx[nport].spd_t.ProductDesc[14], hdmi_rx[nport].spd_t.ProductDesc[15] );
#endif //#if 0

	// 160ms/times
	// VendorName = SCEI
	if((0x53 == hdmi_rx[nport].spd_t.VendorName[0]) && (0x43 == hdmi_rx[nport].spd_t.VendorName[1])
		&& (0x45 == hdmi_rx[nport].spd_t.VendorName[2]) && (0x49 == hdmi_rx[nport].spd_t.VendorName[3])
		&& (0x00 == hdmi_rx[nport].spd_t.VendorName[4]) && (0x00 == hdmi_rx[nport].spd_t.VendorName[5])
		&& (0x00 == hdmi_rx[nport].spd_t.VendorName[6]) && (0x00 == hdmi_rx[nport].spd_t.VendorName[7]))
	{
		// ProductDesc = PS4
		if((0x50 == hdmi_rx[nport].spd_t.ProductDesc[0]) && (0x53 == hdmi_rx[nport].spd_t.ProductDesc[1])
			&& (0x34 == hdmi_rx[nport].spd_t.ProductDesc[2]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[3])
			&& (0x00 == hdmi_rx[nport].spd_t.ProductDesc[4]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[5])
			&& (0x00 == hdmi_rx[nport].spd_t.ProductDesc[6]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[7])
			&& (0x00 == hdmi_rx[nport].spd_t.ProductDesc[8]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[9])
			&& (0x00 == hdmi_rx[nport].spd_t.ProductDesc[10]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[11])
			&& (0x00 == hdmi_rx[nport].spd_t.ProductDesc[12]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[13])
			&& (0x00 == hdmi_rx[nport].spd_t.ProductDesc[14]) && (0x00 == hdmi_rx[nport].spd_t.ProductDesc[15]))
			{
				hdmi_p0_port0_hdcp_flag1_reg.regValue = hdmi_in(HDMI_HDCP_FLAG1_reg);

				if((0 == hdmi_p0_port0_hdcp_flag1_reg.wr_aksv_flag) && (0 == hdmi_p0_port0_hdcp_flag1_reg.rd_ri_flag))
				{
					//Need check HDCP 1.4 or 2.2
					HDCP_debounce[nport]--;

					HDMI_EMG("[HDCP] HDCP_debounce=%x\n", HDCP_debounce[nport]);
					if(_ENABLE == lib_hdmi_hdcp14_is_onoff(nport))
						return _FALSE;
				}
			}
	}

	HDCP_debounce[nport] = 0; // need check it can clear in here or not

//	HDMI_EMG("[HDCP] HDCP_debounce exit\n");
#endif //#ifdef HDMI_CHECK_HDCP_ENABLE

	return _TRUE;
}

unsigned char newbase_hdmi_is_dispsrc(unsigned char disp)
{
	if(VSC_INPUTSRC_HDMI == Get_DisplayMode_Src(disp))
		return TRUE;
	else
		return FALSE;
}


/*********************************************************************************
*
*	HDR
*
*********************************************************************************/



//Minchay@20160607-a-s add hdr10 and dolby version hdr
void newbase_hdmi_dv_hdr_enable(unsigned char detectEn)
{
#ifdef CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT
unsigned char port = newbase_hdmi_get_current_display_port();

#ifdef CONFIG_FORCE_RUN_I3DDMA
	if (!newbase_hdmi_is_dispsrc(SLR_MAIN_DISPLAY))
		return;
#endif
	if (detectEn == _ENABLE)
	{//enable
		if (newbase_hdmi_get_colorspace(port) == COLOR_RGB)
		{
			HDMI_PRINTF("[DolbyVision test COLOR_RGB] HDMI Auto Detet enable...\n");
			Scaler_HDR_DolbyVision_Hdmi_SetDetectEnable(_ENABLE, _DISABLE);
		}
	}
	else
	{//disable
		Scaler_HDR_DolbyVision_Hdmi_SetDetectEnable(_DISABLE, _DISABLE);
	}
#endif
}



void newbase_hdmi_hdr10_enable(unsigned char detectEn)
{

#ifdef CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT
	HDMI_PRINTF("[HDR10] HDMI Auto Detet En:%d...\n",detectEn);
	if(detectEn == _ENABLE)
    {//enable
		Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
	}
	else
	{//disable
	    Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_OFF);
	}
#endif
}

unsigned char newbase_hdmi_hdr10_md_info_check(void)
{
#if  defined(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT)
	unsigned int result=0;
	static unsigned int hdrCrcErrCnt=0, hdrCrcRdyCnt=0;

	if(Scaler_HDR10_Hdmi_Get_Detect_Status() != SLR_HDR10_HDMI_DETECT_OFF){ // check HDMI CRC result when DolbyVision check enabled
		unsigned char bChanged=0;
		result = drvif_hdmi_is_drm_info_ready();
		if(result && (Scaler_HDR10_Hdmi_Get_Detect_Status() == SLR_HDR10_HDMI_DETECT_ON))
		{
			if(++hdrCrcRdyCnt > DV_CRC_RDY_THRESH){
				Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_FOUND_MD);
				bChanged = TRUE;
				hdrCrcRdyCnt = 0;
			}
			pr_debug(KERN_NOTICE "[HDR10] rdyCnt=%d\n", hdrCrcRdyCnt);
		}
		else if(!result /*&& (++hdrCrcErrCnt > DV_CRC_ERR_THRESH)*/ && (Scaler_HDR10_Hdmi_Get_Detect_Status() >= SLR_HDR10_HDMI_DETECT_FOUND_MD))
		{
			Scaler_HDR10_Hdmi_Set_Detect_Status(SLR_HDR10_HDMI_DETECT_ON);
			bChanged = TRUE;
		}

		if(result)
			hdrCrcErrCnt = 0;
		else
			hdrCrcRdyCnt = 0;

		if(bChanged){
			pr_debug(KERN_NOTICE "[HDR10] check=%d\n", result);
			return FALSE;
		}
	}
#endif

    return TRUE;
}


void newbase_hdmi_hdr_disable(void)
{

#ifdef CONFIG_FORCE_RUN_I3DDMA
       if (newbase_hdmi_is_dispsrc(SLR_MAIN_DISPLAY))
#endif

       newbase_hdmi_dv_hdr_enable(_DISABLE);
    newbase_hdmi_hdr10_enable(_DISABLE);
}
//Minchay@20160607-a-e add hdr10 and dolby version hdr


/*********************************************************************************
*
*	hdmi_lib.c
*
*********************************************************************************/


void lib_hdmi_crt_on(void)
{

	hdmi_out(SYS_REG_SYS_SRST0_reg, (SYS_REG_SYS_SRST0_rstn_hdmi_common_mask|
		SYS_REG_SYS_SRST0_rstn_hdmi_pre2_mask| SYS_REG_SYS_SRST0_rstn_hdmi_pre1_mask|
		SYS_REG_SYS_SRST0_rstn_hdmi_pre0_mask|SYS_REG_SYS_SRST0_write_data_mask));
	hdmi_out(SYS_REG_SYS_SRST1_reg, (SYS_REG_SYS_SRST1_rstn_hdmi_mask|SYS_REG_SYS_SRST1_write_data_mask));

	hdmi_out(SYS_REG_SYS_CLKEN0_reg, (SYS_REG_SYS_CLKEN0_clken_hdmi_common_mask|
		SYS_REG_SYS_CLKEN0_clken_hdmi_pre2_mask|SYS_REG_SYS_CLKEN0_clken_hdmi_pre1_mask|
		SYS_REG_SYS_CLKEN0_clken_hdmi_pre0_mask|SYS_REG_SYS_CLKEN0_write_data_mask));
	hdmi_out(SYS_REG_SYS_CLKEN1_reg, (SYS_REG_SYS_CLKEN1_clken_hdmi_mask|SYS_REG_SYS_CLKEN1_write_data_mask));

	hdmi_out(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_rstn_ddc_mask | SYS_REG_SYS_SRST3_write_data_mask);
	hdmi_out(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_clken_ddc_mask | SYS_REG_SYS_CLKEN3_write_data_mask);

	hdmi_out(STB_ST_SRST1_reg, (STB_ST_SRST1_rstn_osc_mask |STB_ST_SRST1_rstn_ddc_mask |STB_ST_SRST1_write_data_mask));
	hdmi_out(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_clken_osc_mask |STB_ST_CLKEN1_clken_ddc_mask |STB_ST_CLKEN1_write_data_mask));

#if MHL_SUPPORT
	hdmi_out(STB_ST_SRST1_reg, (STB_ST_SRST1_rstn_cbus_mask | STB_ST_SRST1_write_data_mask));
	hdmi_out(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_clken_cbus_mask | STB_ST_CLKEN1_write_data_mask));
#endif

#if 0
	hdmi_out(SYS_REG_SYS_SRST1_reg, (SYS_REG_SYS_SRST1_write_data_mask|SYS_REG_SYS_SRST1_rstn_apll_adc_mask));
	hdmi_out(SYS_REG_SYS_CLKEN1_reg, (SYS_REG_SYS_CLKEN1_write_data_mask|SYS_REG_SYS_CLKEN1_clken_apll_adc_mask));
	hdmi_mask(DDS_PLL_PLL_CTRL_reg, ~DDS_PLL_PLL_CTRL_apllldopow_mask, DDS_PLL_PLL_CTRL_apllldopow_mask); /*bit0 needed ?*/
#endif

	hdmi_out(SYS_REG_SYS_SRST1_reg, (SYS_REG_SYS_SRST1_rstn_offms_mask | SYS_REG_SYS_SRST1_write_data_mask));
	hdmi_out(SYS_REG_SYS_CLKEN1_reg, (SYS_REG_SYS_CLKEN1_clken_offms_mask | SYS_REG_SYS_CLKEN1_write_data_mask));

#if MHL_SUPPORT
	hdmi_out(SYS_REG_SYS_SRST1_reg, (SYS_REG_SYS_SRST1_rstn_cbus_mask | SYS_REG_SYS_SRST1_write_data_mask));
	hdmi_out(SYS_REG_SYS_CLKEN1_reg, (SYS_REG_SYS_CLKEN1_clken_cbus_mask | SYS_REG_SYS_CLKEN1_write_data_mask));
#endif

	hdmi_out(SYS_REG_SYS_SRST2_reg, (SYS_REG_SYS_SRST2_rstn_dispm_cap_mask|SYS_REG_SYS_SRST2_rstn_dispm_disp_mask|SYS_REG_SYS_SRST2_write_data_mask));
	hdmi_out(SYS_REG_SYS_CLKEN2_reg, (SYS_REG_SYS_CLKEN2_clken_dispm_cap_mask|SYS_REG_SYS_CLKEN2_clken_dispm_disp_mask|SYS_REG_SYS_CLKEN2_write_data_mask));

}

void lib_hdmi_power(unsigned char nport, unsigned char enable)
{

	if (enable) {
		hdmiport_mask(HDMI_TMDS_OUTCTL_reg, ~(HDMI_TMDS_OUTCTL_tbcoe_mask|HDMI_TMDS_OUTCTL_tgcoe_mask|HDMI_TMDS_OUTCTL_trcoe_mask|HDMI_TMDS_OUTCTL_ocke_mask),
			(HDMI_TMDS_OUTCTL_tbcoe(1)|HDMI_TMDS_OUTCTL_tgcoe(1)|HDMI_TMDS_OUTCTL_trcoe(1)|HDMI_TMDS_OUTCTL_ocke(1)));		//enable PLL TMDS, RGB clock output

		lib_hdmi_z0_set(nport, LN_ALL, 1);
	} else {

		hdmiport_mask(HDMI_TMDS_OUTCTL_reg,~(HDMI_TMDS_OUTCTL_tbcoe_mask | HDMI_TMDS_OUTCTL_tgcoe_mask | HDMI_TMDS_OUTCTL_trcoe_mask | HDMI_TMDS_OUTCTL_ocke_mask)
		              ,(HDMI_TMDS_OUTCTL_tbcoe(0) | HDMI_TMDS_OUTCTL_tgcoe(0) | HDMI_TMDS_OUTCTL_trcoe(0) | HDMI_TMDS_OUTCTL_ocke(0)));		//disable PLL TMDS, RGB clock output

		lib_hdmi_z0_set(nport, LN_ALL, 0);
	}

}

void lib_hdmi_tmds_init(unsigned char nport)
{
	lib_hdmi_mac_select_port(nport);

#if MHL_SUPPORT
	hdmiport_mask(HDMI_MHL_HDMI_MAC_CTRL_reg,~(HDMI_MHL_HDMI_MAC_CTRL_pp_mode_output_mask|HDMI_MHL_HDMI_MAC_CTRL_packet_mhl_en_mask|HDMI_MHL_HDMI_MAC_CTRL_xor_pixel_sel_mask|HDMI_MHL_HDMI_MAC_CTRL_ch_dec_pp_mode_en_mask),0);
#endif //#if MHL_SUPPORT

	hdmiport_mask(HDMI_TMDS_PWDCTL_reg,~(HDMI_TMDS_PWDCTL_ebip_mask|HDMI_TMDS_PWDCTL_egip_mask|HDMI_TMDS_PWDCTL_erip_mask|HDMI_TMDS_PWDCTL_ecc_mask),(HDMI_TMDS_PWDCTL_ebip_mask|HDMI_TMDS_PWDCTL_egip_mask|HDMI_TMDS_PWDCTL_erip_mask|HDMI_TMDS_PWDCTL_ecc_mask));				//enable TMDS input

	hdmiport_mask(HDMI_HDMI_VCR_reg,~HDMI_HDMI_VCR_iclk_sel_mask,HDMI_HDMI_VCR_iclk_sel(0));
	hdmiport_mask(HDMI_TMDS_CPS_reg,~HDMI_TMDS_CPS_clkv_meas_sel_mask,HDMI_TMDS_CPS_clkv_meas_sel(3));		//measure input clock source sel

	//hdmiport_mask(HDMI_TMDS_DPC_SET0_reg,~HDMI_TMDS_DPC_SET0_dpc_bypass_dis_mask,HDMI_TMDS_DPC_SET0_dpc_en(1));					// video function block enable

}

void lib_hdmi_mac_init(unsigned char nport)
{

	lib_hdmi_mac_select_port(nport);

	hdmiport_out(HDMI_P0_PORT0_POWER_SAVING_reg, 0x00); // disable pattern gen clock

	if (nport < 2) {
	hdmiport_mask(HDMI_PHY_FIFO_CR1_reg,
		~((HDMI_PHY_FIFO_CR1_port0_bclk_inv_mask|HDMI_PHY_FIFO_CR1_port0_gclk_inv_mask|HDMI_PHY_FIFO_CR1_port0_rclk_inv_mask)<<(nport*3)),
		(HDMI_PHY_FIFO_CR1_port0_bclk_inv_mask|HDMI_PHY_FIFO_CR1_port0_gclk_inv_mask|HDMI_PHY_FIFO_CR1_port0_rclk_inv_mask)<<(nport*3));
	}
	else {
		hdmiport_mask(HDMI_EX_P2_EX_PHY_FIFO_CR1_reg,
			~(HDMI_EX_P2_EX_PHY_FIFO_CR1_port2_rclk_inv_mask|HDMI_EX_P2_EX_PHY_FIFO_CR1_port2_gclk_inv_mask|HDMI_EX_P2_EX_PHY_FIFO_CR1_port2_bclk_inv_mask),
			(HDMI_EX_P2_EX_PHY_FIFO_CR1_port2_rclk_inv_mask|HDMI_EX_P2_EX_PHY_FIFO_CR1_port2_gclk_inv_mask|HDMI_EX_P2_EX_PHY_FIFO_CR1_port2_bclk_inv_mask));
	}

	lib_hdmi_mac_afifo_enable(nport);

	// 20161018: SL8800 HDCP CTS1.4, contiune test without disconnect tmds_clock.
	hdmiport_out(HDMI_HDMI_SCR_reg , 0x163);//DVI/HDMI condition(A,B) select  /* hdcp cts1.4 : Bstatus (MSB): 0x00*/
	hdmiport_mask(HDMI_HDMI_AFCR_reg, ~(HDMI_HDMI_AFCR_audio_test_enable_mask|0x07), 0x06);//Enable Audio FIFO
	hdmiport_out(HDMI_HDMI_AVMCR_reg , 0x48);//enable video & audio output
	hdmiport_out(HDMI_HDMI_WDCR0_reg , 0x00);  //disable watch dog


#if HDMI2p0   // for hdmi 2.0 spec use
	hdmiport_mask(HDMI_SCDC_CR_reg,(~HDMI_SCDC_CR_scdc_en_mask),HDMI_SCDC_CR_scdc_en_mask);
	//hdmiport_mask(HDMI_SCDC_PCR_reg, (~HDMI_SCDC_PCR_i2c_free_num_mask), HDMI_SCDC_PCR_i2c_free_num(0x0a));
	hdmiport_mask(HDMI_HDMI_2p0_CR_reg,~(HDMI_HDMI_2p0_CR_hdmi_2p0_en_mask),HDMI_HDMI_2p0_CR_hdmi_2p0_en_mask);
	lib_hdmi_scdc_write(nport, 0x01, 0x01); // HDMI2.0/10.4.1.2/Sink Devices compliant with this version of the specification shall set Sink Version = 1.
#endif

	hdmiport_mask(HDMI_HDCP_PCR_reg,
	              ~(HDMI_HDCP_PCR_km_clk_sel_mask|HDMI_HDCP_PCR_hdcp_vs_sel_mask),
	              (HDMI_HDCP_PCR_km_clk_sel_mask|HDMI_HDCP_PCR_hdcp_vs_sel_mask));

	hdmiport_mask(HDMI_HDMI_VCR_reg, ~(HDMI_HDMI_VCR_prdsam_mask|HDMI_HDMI_VCR_csam_mask),  HDMI_HDMI_VCR_prdsam(1)|HDMI_HDMI_VCR_csam(1));

#if 0 //LG_Color_Space_flow
	HDMI_Color_space_initial();
#endif

	hdmiport_out(HDMI_HDMI_MAGCR0_reg, 0xE000/*0x14*/);

	hdmiport_out(HDMI_HDMI_INTCR_reg, 0);
	hdmiport_mask(HDMI_HDMI_VCR_reg, ~(HDMI_HDMI_VCR_eoi_mask) , 0);  // not inverse EVEN/ODD

	hdmiport_mask(HDMI_HDMI_PAMICR_reg, ~HDMI_HDMI_PAMICR_icpvsb_mask, 0x00);//Disable packet variation Watch Dog
	//hdmiport_mask(HDMI_HDMI_AOCR_reg,(~0x0ff),0xFF);	//Enable SPDIF/I2S Output

	hdmiport_mask(HDMI_TMDS_ERRC_reg, ~HDMI_TMDS_ERRC_nl_mask, HDMI_TMDS_ERRC_nl(3));
	hdmiport_mask(HDMI_HDMI_BCHCR_reg , ~(HDMI_HDMI_BCHCR_pe_mask|HDMI_HDMI_BCHCR_bche_mask|HDMI_HDMI_BCHCR_enrwe_mask|HDMI_HDMI_BCHCR_spcss_mask),(HDMI_HDMI_BCHCR_pe_mask|HDMI_HDMI_BCHCR_bche_mask|HDMI_HDMI_BCHCR_enrwe_mask|HDMI_HDMI_BCHCR_spcss_mask));	// Enable BCH Function
	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~0xFFDF9E, 0x00); // Clear Audio Watch Dog and Set X: 15

	lib_hdmi_char_err_rst(nport, 1);  //reset CED until measure done

#if HDCP2_2 && HDCP22_PATCH_DEFAULT_EN
	lib_hdmi_hdcp22_enable(nport, 1);
	lib_hdmi_hdcp14_enable(nport, 1);
#else
	lib_hdmi_hdcp14_enable(nport, 1);
	#if HDCP2_2
	lib_hdmi_hdcp22_enable(nport, 0);
	#endif
#endif

	lib_hdmi_mac_release(nport); // QC: when ac on, need this for hdcp auth, otherwise no clock in MSHG-800

}



void lib_hdmi_hdcp_init(unsigned char nport)
{
	// Disable HDCP and clear HDCP address
	//hdmi_out(HDMI_HDCP_CR_reg, (HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_dkapde_mask));
	hdmi_mask(HDMI_HDCP_CR_reg, ~(HDMI_HDCP_CR_hdcp_clk_switch_auto_mask), HDMI_HDCP_CR_hdcp_clk_switch_auto_mask);
	hdmi_mask(HDMI_HDCP_PCR_reg, ~(HDMI_HDCP_PCR_km_clk_sel_mask|HDMI_HDCP_PCR_enc_tog_mask), 0);

#if 1 /*defined (ENABLE_HDMI_1_1_SUPPORT)*/ /* must set in hdcp cts1.4 */
	lib_hdmi_hdcp_port_write(nport, 0x40, HDCP_11_HDMI);				//set OESS for DVI
#else
	Hdmi_HdcpPortWrite(0x40,HDCP_10_DVI);				//set OESS for DVI
#endif

#if HDCP2_2
	//hdmi_mask(HDMI_HDCP_2p2_CR_reg,~HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask, HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask);
	#ifndef CONFIG_CUSTOMER_TV030
	lib_hdmi_hdcp_port_write(nport, 0x50,0x04);//support hdcp2.2
	#endif
	//HDMI_PRINTF("\n HDCP2.p vision = %x\n",Hdmi_HdcpPortRead(0x50));
#endif


#if 0
	hdmi_mask(HDMI_HDCP_PCR_reg, ~HDMI_HDCP_PCR_apai_mask, 0);
	hdmi_out(HDMI_HDCP_AP_reg, 0x00);

	for (i = 0; i < 640; i++) {
		hdmi_out(HDMI_HDCP_AP_reg, 0x43 + (i<<8));
		hdmi_out(HDMI_HDCP_DP_reg, 0x00);
	}

	hdmi_out(HDMI_HDCP_AP_reg, 0x00);
	hdmi_mask(HDMI_HDCP_PCR_reg, ~HDMI_HDCP_PCR_apai_mask, HDMI_HDCP_PCR_apai_mask);
#endif

	hdmi_mask(HDMI_HDCP_CR_reg, ~(HDMI_HDCP_CR_namfe_mask), (HDMI_HDCP_CR_namfe_mask)); //for New_AC_Mode Enable,fix simplay bug

}


void lib_hdmi_write_hdcpkey(unsigned char nport, unsigned char *bksv, unsigned char *hdcp_key)
{
	unsigned int i;

	// Disable HDCP and clear HDCP address
	hdmi_mask(HDMI_HDCP_CR_reg,
		~(HDMI_HDCP_CR_hdcp_en_mask|HDMI_HDCP_CR_dkapde_mask|HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_ivspm_mask|
		HDMI_HDCP_CR_invvs_mask|HDMI_HDCP_CR_ivsp_mask|HDMI_HDCP_CR_rpt_mask|HDMI_HDCP_CR_namfe_mask) , HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_dkapde_mask);

	lib_hdmi_hdcp_port_write_conti(nport, 0x00, bksv, 5);	//set KSV 40 bits

	/*Write device private key*/
	for(i=0; i<320; i++) {
#ifdef CONFIG_HDCP_KEY_PRINT
		if (i% 8 == 0) HDMI_PRINTF("\n");
		HDMI_PRINTF("%x ", hdcp_key[i]);
#endif //#ifdef CONFIG_HDCP_KEY_PRINT

		hdmi_out(HDMI_HDCP_DKAP_reg, hdcp_key[i]);
	}

#ifdef CONFIG_HDCP_KEY_PRINT
	HDMI_PRINTF("\n =================================================== =");
	hdmi_mask(HDMI_HDCP_CR_reg,
	~(HDMI_HDCP_CR_hdcp_en_mask|HDMI_HDCP_CR_dkapde_mask|HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_ivspm_mask|
	HDMI_HDCP_CR_invvs_mask|HDMI_HDCP_CR_ivsp_mask|HDMI_HDCP_CR_rpt_mask|HDMI_HDCP_CR_namfe_mask)
	,HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_dkapde_mask);
	HDMI_PRINTF("\n i=%d  HDMI BKSV Flag = %x, %x ,%x ,%x, %x \n",
	       i ,
	       lib_hdmi_hdcp_port_read(nport, 0x00),
	       lib_hdmi_hdcp_port_read(nport, 0x01),
	       lib_hdmi_hdcp_port_read(nport, 0x02),
	       lib_hdmi_hdcp_port_read(nport, 0x03),
	       lib_hdmi_hdcp_port_read(nport, 0x04));
	HDMI_PRINTF("HDCP key 320 byte read ");
	for(i=0; i<320; i++) {
		if (i% 16 == 0) HDMI_PRINTF("\n");
		HDMI_PRINTF("%x ", hdmi_in(HDMI_HDCP_DKAP_reg));
	}

#endif //#ifdef CONFIG_HDCP_KEY_PRINT

	hdmi_mask(HDMI_HDCP_CR_reg,
	 ~(HDMI_HDCP_CR_hdcp_en_mask|HDMI_HDCP_CR_dkapde_mask|HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_ivspm_mask|
	HDMI_HDCP_CR_invvs_mask|HDMI_HDCP_CR_ivsp_mask|HDMI_HDCP_CR_rpt_mask|HDMI_HDCP_CR_namfe_mask), 0x00);

	hdmi_mask(HDMI_HDCP_CR_reg, ~(HDMI_HDCP_CR_namfe_mask), (HDMI_HDCP_CR_namfe_mask)); //for New_AC_Mode Enable,fix simplay bug

}

void lib_hdmi_read_hdcpkey(unsigned char nport, unsigned char *bksv, unsigned char *hdcp_key)
{
	unsigned int i;
	unsigned char reg_bak;

	reg_bak = hdmi_in(HDMI_HDCP_CR_reg);
	// Disable HDCP and clear HDCP address
	hdmi_mask(HDMI_HDCP_CR_reg,
	 ~(HDMI_HDCP_CR_hdcp_en_mask|HDMI_HDCP_CR_dkapde_mask|HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_ivspm_mask|
	HDMI_HDCP_CR_invvs_mask|HDMI_HDCP_CR_ivsp_mask|HDMI_HDCP_CR_rpt_mask|HDMI_HDCP_CR_namfe_mask), 0x00);

	hdmi_mask(HDMI_HDCP_CR_reg,
	~(HDMI_HDCP_CR_hdcp_en_mask|HDMI_HDCP_CR_dkapde_mask|HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_ivspm_mask|
	HDMI_HDCP_CR_invvs_mask|HDMI_HDCP_CR_ivsp_mask|HDMI_HDCP_CR_rpt_mask|HDMI_HDCP_CR_namfe_mask)
	,HDMI_HDCP_CR_maddf_mask|HDMI_HDCP_CR_dkapde_mask);


	for (i=0; i<5; i++) {
		bksv[i] = lib_hdmi_hdcp_port_read(nport, i);

	}
	bksv[5] = bksv[6] = bksv[7] = 0;


	for(i=0; i<320; i++) {
		hdcp_key[i] = hdmi_in(HDMI_HDCP_DKAP_reg);
	}

#if defined(CONFIG_HDCP_KEY_PRINT)
	HDMI_PRINTF("\nHDCP BKSV Flag = %x, %x ,%x ,%x, %x \n",
	            bksv[0],
	            bksv[1],
	            bksv[2],
	            bksv[3],
	            bksv[4]);
	HDMI_PRINTF("HDCP key 320 byte read=\n");
	for(i=0; i<320; i++) {
		if (i% 16 == 0) HDMI_PRINTF("\n");
		HDMI_PRINTF("%x ",  hdcp_key[i]);
	}
#endif //#ifdef CONFIG_HDCP_KEY_PRINT

	hdmi_out(HDMI_HDCP_CR_reg, reg_bak);

}


void lib_hdmi_hdcp14_enable(unsigned char nport, unsigned char on)
{
	if (on) {
		hdmiport_mask(HDMI_HDCP_CR_reg, ~HDMI_HDCP_CR_hdcp_en_mask, HDMI_HDCP_CR_hdcp_en_mask);
	} else {
		hdmiport_mask(HDMI_HDCP_CR_reg, ~HDMI_HDCP_CR_hdcp_en_mask, 0);
	}
}

unsigned char lib_hdmi_hdcp14_is_onoff(unsigned char nport)
{
	return HDMI_HDCP_CR_get_hdcp_en(hdmi_in(HDMI_HDCP_CR_reg));
}

#if HDMI_STR_HPD_SPEED_UP_ENABLE
unsigned char lib_hdmi_cec_is_enabled(void)
{
#ifdef CONFIG_RTK_KDRV_CEC
	return (CEC_CEC_CR0_get_cec_mode(hdmi_in(CEC_CEC_CR0_reg))==1?1:0);
#else
	return 0;
#endif
    
}
#endif

unsigned char lib_hdcp14_check_aksv_reg(unsigned char nport)
{
	return HDMI_HDCP_FLAG1_get_wr_aksv_flag(hdmi_in(HDMI_HDCP_FLAG1_reg));
}

void lib_hdcp14_clear_aksv_reg(unsigned char nport)
{
	hdmi_out(HDMI_HDCP_FLAG1_reg, HDMI_HDCP_FLAG1_wr_aksv_flag_mask);
}

unsigned char lib_hdcp14_check_bksv_reg(unsigned char nport)
{
	return HDMI_HDCP_FLAG1_get_rd_bksv_flag(hdmi_in(HDMI_HDCP_FLAG1_reg));
}

void lib_hdcp14_clear_bksv_reg(unsigned char nport)
{
	hdmi_out(HDMI_HDCP_FLAG1_reg, HDMI_HDCP_FLAG1_rd_bksv_flag_mask);
}

void lib_hdmi_hdcp_port_write_conti(unsigned char nport, unsigned char addr, const unsigned char* value, unsigned char num)
{
	unsigned char bit0_tmp;
	bit0_tmp = HDMI_HDCP_PCR_get_apai(hdmi_in(HDMI_HDCP_PCR_reg));
	hdmi_mask(HDMI_HDCP_PCR_reg, ~HDMI_HDCP_PCR_apai_mask, 0);
	hdmi_out(HDMI_HDCP_AP_reg, addr);

	while(num--)
		hdmi_out(HDMI_HDCP_DP_reg, *(value++));

	hdmi_mask(HDMI_HDCP_PCR_reg, ~HDMI_HDCP_PCR_apai_mask, HDMI_HDCP_PCR_apai(bit0_tmp));
}

void lib_hdmi_hdcp_port_write(unsigned char nport, unsigned char addr ,unsigned char value)
{
	hdmi_out(HDMI_HDCP_AP_reg, addr);
	hdmi_out(HDMI_HDCP_DP_reg, value);
}

unsigned char lib_hdmi_hdcp_port_read(unsigned char nport, unsigned char addr)
{
	hdmi_out(HDMI_HDCP_AP_reg, addr);
	return hdmi_in(HDMI_HDCP_DP_reg);
}



#if HDCP2_2
void lib_hdmi_hdcp22_enable(unsigned char nport, unsigned char enable)
{
	if (enable) {
		hdmiport_mask(HDMI_HDCP_2p2_CR_reg, ~HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask, HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask);
#if HDCP22_PATCH_DEFAULT_EN
		lib_hdmi_hdcp_port_write(nport, 0x50,0x04);
#endif
	} else {
		hdmiport_mask(HDMI_HDCP_2p2_CR_reg, ~HDMI_HDCP_2p2_CR_hdcp_2p2_en_mask, 0);
	}
}

unsigned char lib_hdmi_hdcp22_is_onoff(unsigned char nport)
{
	return HDMI_HDCP_2p2_CR_get_hdcp_2p2_en(hdmi_in(HDMI_HDCP_2p2_CR_reg));
}

unsigned char lib_hdmi_hdcp22_get_auth_done(unsigned char nport)
{
	return (HDMI_HDCP_2p2_SR0_get_state(hdmi_in(HDMI_HDCP_2p2_SR0_reg))==0x010);
}
#endif





void lib_hdmi_ddc_sel(unsigned char nport, unsigned char ddc_ch)
{
	unsigned int val;
	val = hdmi_in(HDMI_HDMI_VCR_reg) & (~(HDMI_HDMI_VCR_int_pro_chg_flag_mask|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask|HDMI_HDMI_VCR_hdcp_ddc_chsel_mask));
	hdmiport_out(HDMI_HDMI_VCR_reg, val|HDMI_HDMI_VCR_hdcp_ddc_chsel(ddc_ch));
}

void lib_hdmi_mac_select_port(unsigned char nport)
{	// reset all mac
	hdmi_out(SYS_REG_SYS_CLKEN0_reg, (SYS_REG_SYS_CLKEN0_clken_hdmi_common_mask));

	hdmi_out(SYS_REG_SYS_SRST0_reg, (SYS_REG_SYS_SRST0_rstn_hdmi_common_mask));
	//udelay(1);
	hdmi_out(SYS_REG_SYS_SRST0_reg, (SYS_REG_SYS_SRST0_rstn_hdmi_common_mask|
		SYS_REG_SYS_SRST0_write_data_mask));

	hdmi_mask(HDMI_P0_PORT0_PORT_SWITCH_reg,
		~(HDMI_PORT_SWITCH_port_sel_mask),
		(HDMI_PORT_SWITCH_port_sel(nport)));

	hdmi_out(SYS_REG_SYS_CLKEN0_reg, (SYS_REG_SYS_CLKEN0_clken_hdmi_common_mask|
		SYS_REG_SYS_CLKEN0_write_data_mask));
}

void lib_hdmi_meas_select_port(unsigned char nport)
{
	hdmiport_mask(HDMI_P0_PORT0_PORT_SWITCH_reg,
		~(HDMI_PORT_SWITCH_offms_port_sel_mask),
		(HDMI_PORT_SWITCH_offms_port_sel(nport)));
}

unsigned char lib_hdmi_is_rgb_status_ready(unsigned char nport)
{
	return ((hdmi_in(HDMI_TMDS_CTRL_reg) & (HDMI_TMDS_CTRL_bcd_mask|HDMI_TMDS_CTRL_gcd_mask|HDMI_TMDS_CTRL_rcd_mask))
		== (HDMI_TMDS_CTRL_bcd_mask|HDMI_TMDS_CTRL_gcd_mask|HDMI_TMDS_CTRL_rcd_mask));
}

void lib_hdmi_clear_rgb_status(unsigned char nport)
{
	hdmi_out(HDMI_TMDS_CTRL_reg, (HDMI_TMDS_CTRL_bcd_mask|HDMI_TMDS_CTRL_gcd_mask|HDMI_TMDS_CTRL_rcd_mask));
}

unsigned char lib_hdmi_vsync_checked(unsigned char nport)
{
	unsigned char i;
	hdmiport_out(HDMI_TMDS_CTRL_reg, HDMI_TMDS_CTRL_yo_mask);
	for (i=0; i<15; i++) {
		if (HDMI_TMDS_CTRL_get_yo(hdmi_in(HDMI_TMDS_CTRL_reg))) {
			return TRUE;
		}
		msleep(5);
	}
	//hdmiport_out(HDMI_TMDS_CTRL_reg, HDMI_TMDS_CTRL_yo_mask);
	HDMI_PRINTF("[WARNING] Vsync cannot seen?\n");
	return FALSE;
}

unsigned char lib_hdmi_get_color_depth(unsigned char nport)
{
	unsigned char cd;
	cd = HDMI_TMDS_DPC0_dpc_cd(hdmi_in(HDMI_TMDS_DPC0_reg));
	if (cd > 3) {
		return (cd-4);
	} else {
		return 0;
	}
}

void lib_hdmi_clear_interlace_reg(unsigned char nport)
{
	unsigned int val;

	val = hdmi_in(HDMI_HDMI_VCR_reg) & (~(HDMI_HDMI_VCR_int_pro_chg_flag_mask|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask));
	hdmiport_out(HDMI_HDMI_VCR_reg, (val|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask));

	hdmiport_out(HDMI_TMDS_CTRL_reg, HDMI_TMDS_CTRL_yo_mask); //reset vsync
}

unsigned char lib_hdmi_get_is_interlace(unsigned char nport, HDMI_MS_T ms_mode)
{
	unsigned char i;

	if (ms_mode == HDMI_MS_ONESHOT) {
		lib_hdmi_clear_interlace_reg(nport);
		for (i=0; i<4; i++)	{
			lib_hdmi_vsync_checked(nport);
		}
	}

	if (HDMI_HDMI_VCR_get_se(hdmi_in(HDMI_HDMI_VCR_reg))) {
		lib_hdmi_clear_interlace_reg(nport);
		return 0;
	} else {
		return HDMI_HDMI_VCR_get_eot(hdmi_in(HDMI_HDMI_VCR_reg));
	}
}

void lib_hdmi_set_repeat_manual(unsigned char nport, unsigned char rep_value)
{
	unsigned int val;
	val = hdmi_in(HDMI_HDMI_VCR_reg) & (~(HDMI_HDMI_VCR_int_pro_chg_flag_mask|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask|HDMI_HDMI_VCR_prdsam_mask));
	hdmiport_out(HDMI_HDMI_VCR_reg, val);

	val &= ~HDMI_HDMI_VCR_dsc_mask;
	hdmiport_out(HDMI_HDMI_VCR_reg, val|HDMI_HDMI_VCR_dsc(rep_value));
}

void lib_hdmi_set_repeat_auto(unsigned char nport)
{
	unsigned int val;
	val = hdmi_in(HDMI_HDMI_VCR_reg) & (~(HDMI_HDMI_VCR_int_pro_chg_flag_mask|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask));
	hdmiport_out(HDMI_HDMI_VCR_reg, val|HDMI_HDMI_VCR_prdsam_mask);
}

unsigned char lib_hdmi_get_pixelrepeat(unsigned char nport)
{
	if (HDMI_HDMI_VCR_get_prdsam(hdmi_in(HDMI_HDMI_VCR_reg))) {
		return HDMI_HDMI_VCR_get_dsc_r(hdmi_in(HDMI_HDMI_VCR_reg));
	} else {
		return HDMI_HDMI_VCR_get_dsc(hdmi_in(HDMI_HDMI_VCR_reg));
	}
}

void lib_hdmi_set_colorspace_manual(unsigned char nport, unsigned char color_space)
{
	unsigned int val;
	val = hdmi_in(HDMI_HDMI_VCR_reg) & (~(HDMI_HDMI_VCR_int_pro_chg_flag_mask|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask|HDMI_HDMI_VCR_csam_mask));
	hdmiport_out(HDMI_HDMI_VCR_reg, val);

	msleep(20);

	val &= ~HDMI_HDMI_VCR_csc_mask;
	hdmiport_out(HDMI_HDMI_VCR_reg, val|HDMI_HDMI_VCR_csc(color_space));
}

void lib_hdmi_set_colorspace_auto(unsigned char nport)
{
	unsigned int val;
	val = hdmi_in(HDMI_HDMI_VCR_reg) & (~(HDMI_HDMI_VCR_int_pro_chg_flag_mask|HDMI_HDMI_VCR_eot_mask|HDMI_HDMI_VCR_se_mask));
	hdmiport_out(HDMI_HDMI_VCR_reg, val|HDMI_HDMI_VCR_csam_mask);
}

unsigned char lib_hdmi_get_colorspace(unsigned char nport)
{
	if (HDMI_HDMI_VCR_get_csam(hdmi_in(HDMI_HDMI_VCR_reg))) { //auto
		return HDMI_HDMI_VCR_get_csc_r(hdmi_in(HDMI_HDMI_VCR_reg));
	} else {
		return HDMI_HDMI_VCR_get_csc(hdmi_in(HDMI_HDMI_VCR_reg));
	}
}

unsigned char lib_hdmi_is_hdmi_mode(unsigned char nport)
{
	if (HDMI_HDMI_SCR_get_mode(hdmi_in(HDMI_HDMI_SCR_reg))) {
		return HDMI_HDMI_SCR_get_msmode(hdmi_in(HDMI_HDMI_SCR_reg));
	}


	if (HDMI_HDMI_SR_get_mode(hdmi_in(HDMI_HDMI_SR_reg))) {
		return MODE_HDMI;
	} else {
		return MODE_DVI;
	}
}

unsigned char lib_hdmi_get_video_format(unsigned char nport)
{
	return HDMI_HDMI_VIDEO_FORMAT_get_hvf(hdmi_in(HDMI_HDMI_VIDEO_FORMAT_reg));
}

unsigned char lib_hdmi_get_3d_structure(unsigned char nport)
{
	return HDMI_HDMI_3D_FORMAT_get_hdmi_3d_structure(hdmi_in(HDMI_HDMI_3D_FORMAT_reg));
}

unsigned char lib_hdmi_get_3d_extdata(unsigned char nport)
{
	/*

	3D Ext Data
	Horizontal sub-sampling
	0000:Odd/Left picture, Odd/Right picture
	0001:Odd/Left picture, Even/Right picture
	0010:Even/Left picture, Odd/Right picture
	0011:Even/Left picture, Even/Right picture
	Quincunx matrix
	0100:Odd/Left picture, Odd/Right picture
	0101:Odd/Left picture, Even/Right picture
	0110:Even/Left picture, Odd/Right picture
	0111:Even/Left picture, Even/Right picture
	1000~1111:Reserved

	*/
	return HDMI_HDMI_3D_FORMAT_get_hdmi_3d_ext_data(hdmi_in(HDMI_HDMI_3D_FORMAT_reg));
}

unsigned char lib_hdmi_get_vsi_vic(unsigned char nport)
{
	/*
	HDMI_VIC
	0x01:4Kx2K@30Hz
	0x02:4Kx2K@25Hz
	0x03:4Kx2K@24Hz
	0x04:4Kx2K@24Hz(SMPTE)
	Others:reserved
	*/

	return HDMI_HDMI_VIDEO_FORMAT_get_hdmi_vic(hdmi_in(HDMI_HDMI_VIDEO_FORMAT_reg));
}

unsigned char lib_hdmi_set_video_pll(unsigned char nport, unsigned int b_clk, unsigned char cd, unsigned char is_interlace, unsigned char is_420, unsigned char is_mhl)
{


//  Fin =   Fxtal * b / 256
//  Target vco = ( Fin * m / n )     , TagretVco_HB = 500 ,  TagretVco_LB=250
//  Fin * m / n / 2^o / 2 * s = pixel clock = Fin * [24/30, 24/36, 24/48] ,  [10bits, 12bits,16bits]


//FVCO = Fin * m / n
//Fin = TMDS clock = pixel clock * SN/SM   --> pixel clock = Fin * SM / SN
//pixel clock = FVCO / 2^o / 2*s
//Fin * SM / SN = FVCO / 2^o / 2*s
//FVCO = Fin *  2^o * 2*s * SM/SN
//FVCO = Fin * 2^o * s * [24/30 * 2, 24/36 * 2, 24/48 * 2] --> Fin * 2^o * s * [8/5,4/3,1]
//  250 <  ( Fin * m / n )  < 500  -->  250 <   Fin * 2^o * s * [ 8/5 , 4/3, 1 ]   < 500



	unsigned char enable_2x = 0;
	unsigned int large_ratio, Smean,Stest, m, n, o , fvco;
	unsigned long pixel_clockx1024;
	unsigned int bpsin, fpfd1024;
	unsigned int i,j,tabsize;
	unsigned char dpll_rs, dpll_ip;


	hdmiport_mask(HDMI_YUV420_CR_reg, ~(HDMI_YUV420_CR_en_mask), 0);
	udelay(1);
	hdmiport_mask(HDMI_TMDS_DPC_SET0_reg, ~(HDMI_TMDS_DPC_SET0_dpc_en_mask), 0);
	udelay(1);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_pow_mask|HDMI_HDMI_VPLLCR1_dpll_vcorstb_mask|HDMI_HDMI_VPLLCR1_dpll_stoppsw_mask), 0);// Disable PLL
	udelay(1);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_rstb_mask), 0);
	udelay(1);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_freeze_mask), HDMI_HDMI_VPLLCR1_dpll_freeze_mask);



#define FVCO_MIN	250
#define FVCO_MAX	500

	//tmds clock = b * 27 / 256
	//tmds clock = pixel clock * SN/SM --> b* 27 / 256 = pixel clock * SN/SM
	//pixel clock = b * 27 * M / (SN * 256)
	//pixel clock * 1024 = b * 27 * M * 1024 / (N * 256)


	pixel_clockx1024 =((unsigned long)b_clk * 27 * dpll_ratio[cd].SM * 1024) / (dpll_ratio[cd].SN * 256);
	HDMI_PRINTF("pixel_clock = %ld\n", pixel_clockx1024);
	if (pixel_clockx1024 == 0) {
		HDMI_EMG("[ERR] pixel_clockx1024 is zero=%d,%d\n", b_clk, cd);
		return FALSE;
	}

	enable_2x = is_interlace;

	if ((pixel_clockx1024 < (160 * 1024) && enable_2x == 0) || (is_420)) {
		enable_2x = 1;		// if pixel_clock is under 160MHz then enable 2X clock maybe for DI
	}


	// interlace must 2 x   , MHL not
#if MHL_SUPPORT
	if (enable_2x && (!is_mhl))
#else
	if (enable_2x)
#endif
	{
		large_ratio = 2;
		hdmiport_mask(HDMI_TMDS_CPS_reg, ~HDMI_TMDS_CPS_pll_div2_en_mask, HDMI_TMDS_CPS_pll_div2_en(1));
	}
	else
	{
		large_ratio = 1;
		hdmiport_mask(HDMI_TMDS_CPS_reg, ~HDMI_TMDS_CPS_pll_div2_en_mask, HDMI_TMDS_CPS_pll_div2_en(0));
	}

#if MHL_SUPPORT
	if  ((cd || enable_2x) && (!is_mhl))
#else
	if  (cd || enable_2x)
#endif
	{
		hdmiport_mask(HDMI_TMDS_DPC_SET0_reg, ~HDMI_TMDS_DPC_SET0_dpc_bypass_dis_mask,HDMI_TMDS_DPC_SET0_dpc_bypass_dis(1));
	}
	else
	{
		hdmiport_mask(HDMI_TMDS_DPC_SET0_reg, ~HDMI_TMDS_DPC_SET0_dpc_bypass_dis_mask, HDMI_TMDS_DPC_SET0_dpc_bypass_dis(0));
	}

	if (large_ratio != 1) {
		pixel_clockx1024 <<= 1;
	}



// s = smean
// FVCO_MIN * 1024 / 2^o / 2s <= pixel_clock1024
// (pixel_clock1024 * 2^o) * 2s >= FVCO_MIN * 1024
// (pixel_clock1024 * 2) * 2s >= FVCO_MIN * 1024
//ex: s = 0 , 2s = Stest = 1 (no div)
//ex: s = 1 , 2s = Stest = 2 (div 2)


	o = 1;
	Smean = 0;
	Stest = 1;
	while(pixel_clockx1024 <= (200*1024)) {
		if (Smean == 0) Stest = 1;
		else Stest = Smean * 2;
		// 2---> 2^o
		if (((pixel_clockx1024*2)*Stest)>= (FVCO_MIN*1024))
			break;
		Smean ++;
	};

	if (pixel_clockx1024 > (200*1024)) { // >200MHz
		o = 0;
		Smean = 0;
	}
	/*else if (pixel_clockx1024 > (100*1024)){//100MHz ~200MHz
		o = 1;
		Smean = 0;
	}
	else if (pixel_clockx1024 > (50*1024)){//50MHz ~100MHz
		o = 1;
		Smean = 1;
	}
	else if (pixel_clockx1024 > (25*1024)){//25MHz ~50MHz
		o = 1;
		Smean = 2;
	}
	else {//13.5MHz~25MHz
		o = 1;
		Smean = 4;
	}*/

	//HDMI_PRINTF( "Smean =  %d\n", Smean);

	//if (Smean == 0) Stest = 1;
	//else Stest = Smean * 2;




////FVCO = Fin * m / n
//Fin = TMDS clock = pixel clock * SN/SM   --> pixel clock = Fin * SM / SN
//pixel clock = FVCO / 2^o / 2*s *  (1/large_ratio)
//Fin * SM / SN = FVCO / 2^o / 2*s * (1/large_ratio)
//FVCO = Fin *  2^o * 2*s * SM/SN * large_ratio
//Fin * m / n = Fin * 2^o * 2*s * SM/SN * large_ratio
//m/n = 2^o * 2*s * SM/SN * large_ratio
//when n determined, m = SM * (2*s) * n * large_ratio * 2^o / SN
//m = (SM * (2*s) * n * large_ratio ) << o / SN



	n = 0;
	do {
		n += dpll_ratio[cd].RatioN;
		m =((dpll_ratio[cd].RatioM * Stest * n * large_ratio)<<o) / dpll_ratio[cd].RatioN;
		//HDMI_PRINTF( "%d %d\n", m, n);
	} while(n < 2);

	//M code must >= 6
	while(m < 8)
	{
		n += dpll_ratio[cd].RatioN;
		m =((dpll_ratio[cd].RatioM * Stest * n * large_ratio)<<o) / dpll_ratio[cd].RatioN;
	}


	fvco = (b_clk * 27 * m) / (256 * n);


//mag2 PLL bug  m min must > 1 , or PLL will crash

	while (m<3) {
		n <<= 1;
		m <<= 1;
	}
	if (n > 9) {
		HDMI_EMG("[ERR] m=%d, n=%d > 9\n", m, n);
	}

	//HDMI_PRINTF("***************TMDS=%d\n", b_clk);
	//HDMI_PRINTF("***************cd=%d\n",cd);
	//HDMI_PRINTF("***************m=%d\n",m);
	//HDMI_PRINTF("***************n=%d\n",n);
	//HDMI_PRINTF("***************o=%d\n",o);
	//HDMI_PRINTF("***************s=%d\n",Smean);
	//HDMI_PRINTF("***************fraction1=%d\n",fraction1);
	//HDMI_PRINTF("***************fraction2=%d\n",fraction2);
	//HDMI_PRINTF("***************pixel_clockx1024=%ld\n",pixel_clockx1024);
	//HDMI_PRINTF("***************fvco=%d MHz\n",fvco);
	//HDMI_PRINTF("***************larget=%d\n",large_ratio);
	HDMI_PRINTF("fvco=%d MHz\n",fvco);



#if 0

	//	Icp x (N/M) x (27M/Fin) = 0.95uA
//	Icp x (N/M) x (27M/(27Mx1024/b) = 0.95
//	Icp x (N/M) x (b/1024) = 0.95
//	Icp x (N/M) x (b/1024) x 100 = 95
//	Icp = (Mx1024x95)/(Nxbx100)
	unsigned int fraction1, fraction2;

	fraction1 = ((unsigned long)m *95 *4 *b_clk /(n *256 *100)) ;    // 2bit fractional part
	fraction2 = 0x00;
	//HDMI_PRINTF("***************fraction1=%d\n",fraction1);

	if (fraction1 >=10)
		fraction1 -= 10;

	if(fraction1 >= 40) {      // 2bit fractional part
		fraction1 -= 40;
		fraction2 |= 0x04;
	}

	if(fraction1 >= 20) {      // 2bit fractional part
		fraction1 -= 20;
		fraction2 |= 0x02;
	}

	if(fraction1 >= 10) {      // 2bit fractional part
		fraction1 -= 10;
		fraction2 |= 0x01;
	}
	//HDMI_PRINTF("***************fraction2=%d\n",fraction2);
	//fraction2 |= 0x18;

#else

	tabsize = sizeof(video_pll_main_param)/sizeof(VIDEO_DPLL_FIX_T);

	//search main table
	for (i = 0; i < tabsize ; ++i) {
		if (((m - 2) == video_pll_main_param[i].dpll_M) && ((n - 2) == video_pll_main_param[i].dpll_N)) {
			dpll_ip = video_pll_main_param[i].dpll_IP;
			dpll_rs = video_pll_main_param[i].dpll_RS;
			break;
		}

	}

        // search other table,  if not fiind in main table
	if (i >= tabsize) {

	//fpfd = fin/(DPLL_BPSIN + (1-DPLL_BPSIN) * (DPLL_N+2))
	bpsin = HDMI_HDMI_VPLLCR0_get_dpll_bpsin(hdmi_in(HDMI_HDMI_VPLLCR0_reg));

	fpfd1024 = (b_clk * 27 * 1024 / 256) / (bpsin + ((1-bpsin) * n));

	//(13.5 - 0.3) * 1024 = 13516  ,  (40+0.3) * 1024 = 41267  (margin +- 0.3M)
	if ((fpfd1024 < 13516) || (fpfd1024 > 41267)) {  //margin +- 0.3M
		HDMI_EMG("[WARNING] fpfd is not correct range %d \n", fpfd1024);
	}


		for (j = 0 ; j < 4 ; ++j) {
			if (((m - 2) >= video_pll_others_param[j].min_M ) && ((m - 2) <= video_pll_others_param[j].max_M)) {
				dpll_ip = video_pll_others_param[j].dpll_IP;
				dpll_rs = video_pll_others_param[j].dpll_RS;
			break;
		}
	}

		if (j == 4) {
		dpll_ip =  2;
		dpll_rs = 3;
			HDMI_EMG("[ERROR] video pll table not find\n");
		}
	}


	//HDMI_PRINTF("***************ip=%d\n",dpll_ip);
	//HDMI_PRINTF("***************rs=%d\n",dpll_rs);

#endif


	hdmi_out(HDMI_HDMI_VPLLCR0_reg, HDMI_HDMI_VPLLCR0_dpll_m(m-2)|HDMI_HDMI_VPLLCR0_dpll_o(o)|HDMI_HDMI_VPLLCR0_dpll_n(n-2)|HDMI_HDMI_VPLLCR0_dpll_rs(dpll_rs)|HDMI_HDMI_VPLLCR0_dpll_ip(dpll_ip));	//set video PLL parameter
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_cp_mask | HDMI_HDMI_VPLLCR1_dpll_cs_mask), HDMI_HDMI_VPLLCR1_dpll_cp(1) | HDMI_HDMI_VPLLCR1_dpll_cs(3));
	hdmi_out(HDMI_MN_SCLKG_DIVS_reg,Smean);		//set video PLL output divider
	hdmiport_mask(HDMI_MN_SCLKG_CTRL_reg, ~HDMI_MN_SCLKG_CTRL_sclkg_dbuf_mask, HDMI_MN_SCLKG_CTRL_sclkg_dbuf_mask);		//video PLL double buffer load
	udelay(1);

	//video PLL power enable
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_ldo_pow_mask), HDMI_HDMI_VPLLCR1_dpll_ldo_pow_mask);
	udelay(1);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_pow_mask|HDMI_HDMI_VPLLCR1_dpll_stoppsw_mask), HDMI_HDMI_VPLLCR1_dpll_pow_mask|HDMI_HDMI_VPLLCR1_dpll_stoppsw_mask); //20140922
	udelay(1);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_vcorstb_mask), (HDMI_HDMI_VPLLCR1_dpll_vcorstb_mask));
	udelay(1);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_rstb_mask), HDMI_HDMI_VPLLCR1_dpll_rstb_mask);
	udelay(40);
	hdmiport_mask(HDMI_HDMI_VPLLCR1_reg, ~(HDMI_HDMI_VPLLCR1_dpll_freeze_mask), 0);

	lib_hdmi_video_output(nport, 1);  // pll clock need to enable ouput before pll_pow and 420_en on. //follow 20170125 huang kuan-chia's mail

	udelay(1);
	hdmiport_mask(HDMI_TMDS_DPC_SET0_reg,~(HDMI_TMDS_DPC_SET0_dpc_en_mask), HDMI_TMDS_DPC_SET0_dpc_en_mask);
	udelay(1);
	hdmiport_mask(HDMI_YUV420_CR_reg, ~(HDMI_YUV420_CR_en_mask), HDMI_YUV420_CR_en(is_420));

	return TRUE;
}

void lib_hdmi_video_output(unsigned char nport, unsigned char on)
{
	if (on)
		hdmiport_mask(HDMI_HDMI_AVMCR_reg, ~HDMI_HDMI_AVMCR_ve_mask, HDMI_HDMI_AVMCR_ve_mask);
	else
		hdmiport_mask(HDMI_HDMI_AVMCR_reg, ~HDMI_HDMI_AVMCR_ve_mask, 0);
}

unsigned char lib_hdmi_is_video_output(unsigned char nport)
{
	return HDMI_HDMI_AVMCR_get_ve(hdmi_in(HDMI_HDMI_AVMCR_reg));
}

void lib_hdmi_clear_avmute(unsigned char nport)
{
	hdmiport_mask(HDMI_HDMI_AVMCR_reg, ~(HDMI_HDMI_AVMCR_avmute_flag_mask), HDMI_HDMI_AVMCR_avmute_flag_mask);
	hdmiport_mask(HDMI_HDMI_AVMCR_reg, ~(HDMI_HDMI_AVMCR_avmute_flag_mask), 0);
}

unsigned char lib_hdmi_get_avmute(unsigned char nport)
{
	return HDMI_HDMI_SR_get_avmute(hdmi_in(HDMI_HDMI_SR_reg));
}

unsigned char lib_hdmi_get_bch_1bit_error(unsigned char nport)
{
	return HDMI_HDMI_BCHCR_get_bches(hdmi_in(HDMI_HDMI_BCHCR_reg));
}

unsigned char lib_hdmi_get_bch_2bit_error(unsigned char nport)
{
	return HDMI_HDMI_BCHCR_get_bches2(hdmi_in(HDMI_HDMI_BCHCR_reg));
}

void lib_hdmi_bch_error_clr(unsigned char nport)
{
	hdmiport_mask(HDMI_HDMI_BCHCR_reg , ~(HDMI_HDMI_BCHCR_bches_mask|HDMI_HDMI_BCHCR_bches2_mask), (HDMI_HDMI_BCHCR_bches_mask|HDMI_HDMI_BCHCR_bches2_mask));
}

void lib_hdmi_wdm_enable(unsigned char nport, unsigned char enable)
{
	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~HDMI_HDMI_WDCR0_wdm_mask, HDMI_HDMI_WDCR0_wdm(enable));
}

unsigned char lib_hdmi_is_wdm_enable(unsigned char nport)
{
	return HDMI_HDMI_WDCR0_get_wdm(hdmi_in(HDMI_HDMI_WDCR0_reg));
}

void lib_hdmi_auto_avmute_enable(unsigned char nport, unsigned char enable)
{
	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~HDMI_HDMI_WDCR0_asmfe_mask, HDMI_HDMI_WDCR0_asmfe(enable));
}

unsigned char lib_hdmi_is_auto_avmute_enable(unsigned char nport)
{
	return HDMI_HDMI_WDCR0_get_asmfe(hdmi_in(HDMI_HDMI_WDCR0_reg));
}

void lib_hdmi_tmds_out_ctrl(unsigned char nport, unsigned char bypass, unsigned int r, unsigned int g, unsigned int b)
{
	hdmiport_mask(HDMI_TMDS_OUT_CTRL_reg, ~(HDMI_TMDS_OUT_CTRL_tmds_bypass_mask), HDMI_TMDS_OUT_CTRL_tmds_bypass(bypass));
	hdmi_out(HDMI_TMDS_ROUT_reg, r);
	hdmi_out(HDMI_TMDS_GOUT_reg, g);
	hdmi_out(HDMI_TMDS_BOUT_reg, b);
}


void lib_hdmi_mac_afifo_enable(unsigned char nport)
{
	hdmiport_mask(HDMI_PHY_FIFO_CR0_reg,
		~((HDMI_PHY_FIFO_CR0_port0_b_afifo_en_mask|HDMI_PHY_FIFO_CR0_port0_b_flush_mask|
		HDMI_PHY_FIFO_CR0_port0_g_afifo_en_mask|HDMI_PHY_FIFO_CR0_port0_g_flush_mask|
		HDMI_PHY_FIFO_CR0_port0_r_afifo_en_mask|HDMI_PHY_FIFO_CR0_port0_r_flush_mask)<<(nport*7)),
		((HDMI_PHY_FIFO_CR0_port0_b_afifo_en_mask|HDMI_PHY_FIFO_CR0_port0_b_flush_mask|
		HDMI_PHY_FIFO_CR0_port0_g_afifo_en_mask|HDMI_PHY_FIFO_CR0_port0_g_flush_mask|
		HDMI_PHY_FIFO_CR0_port0_r_afifo_en_mask|HDMI_PHY_FIFO_CR0_port0_r_flush_mask)<<(nport*7)));

	hdmiport_mask(HDMI_EX_P2_EX_PHY_FIFO_CR0_reg,
		~(HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_r_flush_mask|HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_r_afifo_en_mask|
		    HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_g_flush_mask|HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_g_afifo_en_mask|
		    HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_b_flush_mask|HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_b_afifo_en_mask),
		    HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_r_flush_mask|HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_r_afifo_en_mask|
		    HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_g_flush_mask|HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_g_afifo_en_mask|
		    HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_b_flush_mask|HDMI_EX_P2_EX_PHY_FIFO_CR0_port2_b_afifo_en_mask);
}

void lib_hdmi_420_en(unsigned char nport, unsigned char en)
{
	hdmiport_mask(HDMI_YUV420_CR_reg, ~HDMI_YUV420_CR_en_mask, HDMI_YUV420_CR_get_en(en));
}

void lib_hdmi_crc_check(unsigned char nport)
{
	hdmi_out(HDMI_TMDS_CRCC_reg,
		HDMI_TMDS_CRCC_crc_r_en_mask|HDMI_TMDS_CRCC_crc_g_en_mask|HDMI_TMDS_CRCC_crc_b_en_mask|
		HDMI_TMDS_CRCC_crc_nonstable_mask|HDMI_TMDS_CRCC_crcc_mask);
}

unsigned int lib_hdmi_read_crc(unsigned char nport)
{
	return hdmi_in(HDMI_TMDS_CRCO0_reg);
}





unsigned char lib_hdmi_get_mhl_5v(void)
{
	return 0;
}

void lib_hdmi_control_pull_up_1k(unsigned char up1k)
{
#if MHL_SUPPORT
	hdmiport_mask(CBUS_PMM_CBUS_PHY_3_reg, ~(CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel_mask), CBUS_PMM_CBUS_PHY_3_hdmi_mhl_sel(up1k));
	//hdmiport_mask(CBUS_PMM_CBUS_PHY_3_reg, ~(CBUS_PMM_CBUS_PHY_3_hpd_r1k_bypass_mask), CBUS_PMM_CBUS_PHY_3_hpd_r1k_bypass(!up1k));
#endif //#if MHL_SUPPORT
}











#if HDMI2p0

unsigned char lib_hdmi_scdc_read(unsigned char nport, unsigned char addr)
{
	hdmi_out(HDMI_SCDC_AP_reg, addr);
	return hdmi_in(HDMI_SCDC_DP_reg);
}

void lib_hdmi_scdc_write(unsigned char nport, unsigned char addr,unsigned char value)
{
	hdmi_out(HDMI_SCDC_AP_reg, addr);
	hdmi_out(HDMI_SCDC_DP_reg, value);
}

unsigned char lib_hdmi2p0_get_tmds_config(unsigned char nport)
{
	return lib_hdmi_scdc_read(nport, 0x20);
}

void lib_hdmi2p0_reset_scdc(unsigned char nport)
{
	hdmiport_mask(HDMI_SCDC_CR_reg, ~HDMI_SCDC_CR_scdc_reset_mask, HDMI_SCDC_CR_scdc_reset_mask);
	hdmiport_mask(HDMI_SCDC_CR_reg, ~HDMI_SCDC_CR_scdc_reset_mask, 0);
	HDMI_PRINTF("HDMI2.0 SCDC: clear(p%d)\n", nport);
}

void lib_hdmi2p0_scdc_update_flag(unsigned char nport) //HDMI2.0 spec: 10.4.1.3
{
	if (((lib_hdmi_scdc_read(nport, 0x10)&_BIT2) == _BIT2)) {
		lib_hdmi_scdc_write(nport, 0x10, 0x00);
		lib_hdmi_scdc_write(nport, 0x10, 0x04);
	}
}

void lib_hdmi2p0_scramble_enable(unsigned char nport, unsigned char on_off)
{
#if defined(RDC_SINGLE_LANE)
	hdmiport_mask(HDMI_HDMI_SCR_reg, ~(HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask), (HDMI_HDMI_SCR_mode_mask));
	return;
#endif
	if (on_off) {
		//HDMI_PRINTF("HDMI2.0 Scramble Enable\n");
		//For RGB bug
		hdmiport_mask(HDMI_HDMI_SCR_reg,~(HDMI_HDMI_SCR_dvi_reset_ds_cm_en_mask),0);
                            //force scramble mode 20151014 LG QD 804 no scramble bug
		hdmiport_mask(HDMI_SCR_CR_reg, ~(HDMI_SCR_CR_scr_en_fw_mask|HDMI_SCR_CR_scr_auto_mask), HDMI_SCR_CR_scr_en_fw_mask);
		//for 6G audio bug setting
		//20150819
		hdmiport_mask(HDMI_HDMI_SCR_reg,~(HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask),(HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask));
	} else {
		//HDMI_PRINTF("HDMI2.0 Scramble disable\n");
		hdmiport_mask(HDMI_HDMI_SCR_reg,~(HDMI_HDMI_SCR_dvi_reset_ds_cm_en_mask),HDMI_HDMI_SCR_dvi_reset_ds_cm_en_mask);
		//for 6G audio bug setting
		  //force scramble mode 20151014 LG QD 804 no scramble bug
		hdmiport_mask(HDMI_SCR_CR_reg, ~(HDMI_SCR_CR_scr_en_fw_mask|HDMI_SCR_CR_scr_auto_mask), 0);
		//for 6G audio bug setting
		//20150819
		hdmiport_mask(HDMI_HDMI_SCR_reg,~(HDMI_HDMI_SCR_mode_mask|HDMI_HDMI_SCR_msmode_mask),0);
		//For 340M>TMDS
	}
}

#endif




void lib_hdmi_read_packet_sram(unsigned char nport, unsigned int start_addr, unsigned char len, unsigned char *pbuf)
{
	unsigned char i;
	down(HDMI_SMPHR_INFOPKT_GET());
	hdmi_out(HDMI_HDMI_PSAP_reg, start_addr);
	for (i=0; i<len; i++) {
		hdmi_out(HDMI_HDMI_PSAP_reg, start_addr+i);
		pbuf[i] = hdmi_in(HDMI_HDMI_PSDP_reg);
	}
	up(HDMI_SMPHR_INFOPKT_GET());
}

unsigned char lib_hdmi_is_fvs_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_fvsps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_fvs_received_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_fvsps_mask);
}

unsigned char lib_hdmi_is_vs_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_vsps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_vs_received_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_vsps_mask);
}

unsigned char lib_hdmi_is_avi_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_avips(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_avi_received_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_avips_mask);
}

unsigned char lib_hdmi_is_spd_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_spdps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_spd_received_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_spdps_mask);
}

unsigned char lib_hdmi_is_audiopkt_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_aps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_audiopkt_received_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_aps_mask);
}

unsigned char lib_hdmi_is_drm_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_drmps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_drm_received_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_drmps_mask);
}


void lib_hdmi_set_rsv_packet_type(unsigned char nport, unsigned char index, unsigned char pkt_type)
{
	hdmiport_mask(HDMI_HDMI_PTRSV1_reg, ~(HDMI_HDMI_PTRSV1_pt0_mask<<(index<<3)), pkt_type<<(index<<3));
}

unsigned char lib_hdmi_is_rsv_packet0_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_rsv0ps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_rsv_packet0_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_rsv0ps_mask);
}

unsigned char lib_hdmi_is_rsv_packet1_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_rsv1ps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_rsv_packet1_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_rsv1ps_mask);
}


unsigned char lib_hdmi_is_rsv_packet2_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_rsv2ps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_rsv_packet2_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_rsv2ps_mask);
}

unsigned char lib_hdmi_is_rsv_packet3_received(unsigned char nport)
{
	return HDMI_HDMI_GPVS_get_rsv3ps(hdmi_in(HDMI_HDMI_GPVS_reg));
}

void lib_hdmi_clear_rsv_packet3_status(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_GPVS_reg, HDMI_HDMI_GPVS_rsv3ps_mask);
}



void lib_hdmi_audio_init(unsigned char nport)
{
	// clear Overflow,Underflow,phase_non_lock, auto load double buffter
	hdmiport_out(HDMI_HDMI_DBCR_reg, 0x00);
	/*Disable audio watch dog*/
	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~HDMI_HDMI_WDCR0_awdck_mask, 0x00);	//disable  tmds clock audio watch dog
	hdmiport_mask(HDMI_HDMI_WDCR0_reg,
		~(HDMI_HDMI_WDCR0_awdfu_mask|HDMI_HDMI_WDCR0_awdfo_mask|HDMI_HDMI_WDCR0_awdap_mask|HDMI_HDMI_WDCR0_awdct_mask),
		0x00);

	lib_hdmi_audio_output(nport, 0);

	/*Disable FIFO trend tracking*/
	hdmiport_out(HDMI_HDMI_PSCR_reg, 0xE2);
	/*Update Double Buffer*/
	hdmiport_out(HDMI_HDMI_CMCR_reg, 0x50);   //K code =2

//  Ack from China (20170323)
//  Change timing(w/ HDCP), flick happen before going to next timing
//  => AVMUTE => WD on, so blanking => audio stop & re-detect & disable WD => WD off, so display on => repeat....,
//
//
//	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~(HDMI_HDMI_WDCR0_wdm_mask|HDMI_HDMI_WDCR0_asmfe_mask),
//				HDMI_HDMI_WDCR0_wdm(0)|HDMI_HDMI_WDCR0_asmfe(0));

}

unsigned char lib_hdmi_audio_is_nonpcm(unsigned char nport)
{
	return HDMI_HDMI_SR_get_spdiftype(hdmi_in(HDMI_HDMI_SR_reg));
}

void lib_hdmi_audio_pop_n_cts(unsigned char nport)
{
	hdmiport_mask(HDMI_HDMI_ACRCR_reg, ~(HDMI_HDMI_ACRCR_pucnr_mask|HDMI_HDMI_ACRCR_pucsr_mask), (HDMI_HDMI_ACRCR_pucnr_mask|HDMI_HDMI_ACRCR_pucsr_mask));
}

unsigned char lib_hdmi_audio_pop_n_cts_done(unsigned char nport)
{
	return ((hdmiport_in(HDMI_HDMI_ACRCR_reg) & (HDMI_HDMI_ACRCR_pucnr_mask|HDMI_HDMI_ACRCR_pucsr_mask))==0);
}

unsigned int lib_hdmi_audio_get_n(unsigned char nport)
{
	return HDMI_HDMI_ACRSR1_get_n(hdmi_in(HDMI_HDMI_ACRSR1_reg));
}

unsigned int lib_hdmi_audio_get_cts(unsigned char nport)
{
	return HDMI_HDMI_ACRSR0_get_cts(hdmi_in(HDMI_HDMI_ACRSR0_reg));
}


void lib_hdmi_audio_clear_fs(unsigned char nport)
{
	hdmiport_out(HDMI_HDMI_ASR0_reg, (HDMI_HDMI_ASR0_fsre_mask|HDMI_HDMI_ASR0_fsif_mask|HDMI_HDMI_ASR0_fscs_mask));
}

unsigned char lib_hdmi_audio_fs_from_cs(unsigned char nport)
{
	return (HDMI_HDMI_ASR0_fscs(hdmiport_in(HDMI_HDMI_ASR0_reg)));
}

unsigned char lib_hdmi_audio_get_freq_from_cs(unsigned char nport)
{
	return HDMI_HDMI_ASR1_get_fbcs(hdmiport_in(HDMI_HDMI_ASR1_reg));
}

void lib_hdmi_audio_cts_bound(unsigned char nport, unsigned int clk)
{
	unsigned long cts_up, cts_low;

	if (clk > 5600) { //6G timing
		cts_up = 0xfffff ;//990000;
		cts_low = 445500 *7/8 ;
	} else if (clk > 2750) { //   3G timing
		cts_up = 421875 * 9/8 ; //990000;
		cts_low = 222750 *7/8 ;
	} else if (clk > 1380) { //148M
		cts_up = 421875 * 9/8  ;//990000;
		cts_low = 140625 *7/8 ;
	} else if (clk > 660) {
		cts_up = 234375 * 9/8  ;//990000;
		cts_low = 74250 *7/8 ;
	} else {
		cts_up = 60060 * 9/8  ;//990000;
		cts_low = 25200 *7/8 ;
	}

	hdmiport_mask(HDMI_AUDIO_CTS_UP_BOUND_reg,~(HDMI_AUDIO_CTS_UP_BOUND_cts_up_bound_mask),HDMI_AUDIO_CTS_UP_BOUND_cts_up_bound(cts_up));
	hdmiport_mask(HDMI_AUDIO_CTS_LOW_BOUND_reg,~HDMI_AUDIO_CTS_LOW_BOUND_cts_low_bound_mask,HDMI_AUDIO_CTS_LOW_BOUND_cts_low_bound(cts_low));		//CTS low boundary set 20000
}

void lib_hdmi_audio_n_bound(unsigned char nport, unsigned int freq)
{
	int N_up, N_low;

	if (freq>190000) { //192k
		N_up = 46592 *9/8 ;//;
		N_low = 20480 *7/8 ;
	} else if (freq >170000) { //   176.4
		N_up = 71344 * 9/8 ; //990000;
		N_low = 17836 *7/8 ;
	} else if (freq >80000) { //   96 k 88.2k
		N_up = 35672 * 9/8  ;//990000;
		N_low = 8918 *7/8 ;
	} else { //32k  44.1k  48k
		N_up = 17836 * 9/8  ;//990000;
		N_low = 3072 *7/8 ;
	}

	hdmiport_mask(HDMI_AUDIO_N_UP_BOUND_reg,~(HDMI_AUDIO_N_UP_BOUND_n_up_bound_mask),HDMI_AUDIO_N_UP_BOUND_n_up_bound(N_up));
	hdmiport_mask(HDMI_AUDIO_N_LOW_BOUND_reg,~HDMI_AUDIO_N_LOW_BOUND_n_low_bound_mask,HDMI_AUDIO_N_LOW_BOUND_n_low_bound(N_low));		//CTS low boundary set 20000
	HDMI_PRINTF("freq = %d Audio_N_Bound H = %d , L =%d\n", freq, N_up, N_low);
}


unsigned char lib_hdmi_audio_is_pll_unlock(unsigned char nport)
{
	return HDMI_HDMI_SR_get_pllsts(hdmi_in(HDMI_HDMI_SR_reg));
}

void lib_hdmi_audio_wclr_pll_unlock(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_SR_reg, HDMI_HDMI_SR_pllsts_mask);
}

unsigned char lib_hdmi_audio_is_fifo_overflow(unsigned char nport)
{
	return HDMI_HDMI_SR_get_afifoof(hdmi_in(HDMI_HDMI_SR_reg));
}

void lib_hdmi_audio_wclr_fifo_overflow(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_SR_reg, HDMI_HDMI_SR_afifoof_mask);
}

unsigned char lib_hdmi_audio_is_fifo_underflow(unsigned char nport)
{
	return HDMI_HDMI_SR_get_afifouf(hdmi_in(HDMI_HDMI_SR_reg));
}

void lib_hdmi_audio_wclr_fifo_underflow(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_SR_reg, HDMI_HDMI_SR_afifouf_mask);
}

void lib_hdmi_audio_clear_phase_error(unsigned char nport)
{
	hdmi_out(HDMI_HDMI_NCPER_reg,0xff);
}


void lib_hdmi_audio_generate(unsigned char nport)
{
	unsigned char i;
	unsigned int d_code;

	hdmiport_mask(HDMI_HDMI_DBCR_reg , 0xF0, 0x0F);

	d_code = hdmi_in(HDMI_HDMI_APLLCR3_reg);

	for (i=0; i<5; i++) {
		if (d_code == hdmiport_in(HDMI_HDMI_APLLCR3_reg)) break;
	}

	hdmiport_out(HDMI_HDMI_DCAPR0_reg, d_code);	//pre-set D code

	hdmiport_out(HDMI_HDMI_PSCR_reg, 0xE2);		//pre-disable N/CTS tracking & FIFO depth

	//Enable audio Overflow & Underflow watch dog but not Audio type wdg
	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~(_BIT1|_BIT2|_BIT3|_BIT4), (_BIT1|_BIT2|_BIT3|_BIT4));
	hdmiport_mask(HDMI_HDMI_WDCR0_reg, ~_BIT15, _BIT15);//Enable audio tmds clock  watch dog
}

unsigned char lib_hdmi_audio_is_output(unsigned char nport)
{
	return HDMI_HDMI_AVMCR_get_aomc(hdmi_in(HDMI_HDMI_AVMCR_reg));
}


void lib_hdmi_audio_output(unsigned char nport, unsigned char on)
{
	if (on) {
		hdmiport_mask(HDMI_HDMI_AVMCR_reg,
			~(HDMI_HDMI_AVMCR_aoc_mask|HDMI_HDMI_AVMCR_aomc_mask),
			(HDMI_HDMI_AVMCR_aoc_mask|HDMI_HDMI_AVMCR_aomc_mask));
		hdmiport_mask(HDMI_HDMI_AOCR_reg,
			~(HDMI_HDMI_AOCR_spdifo1_mask|HDMI_HDMI_AOCR_spdifo2_mask|
			HDMI_HDMI_AOCR_spdifo3_mask|HDMI_HDMI_AOCR_spdifo4_mask|
			HDMI_HDMI_AOCR_i2so1_mask|HDMI_HDMI_AOCR_i2so2_mask|
			HDMI_HDMI_AOCR_i2so3_mask|HDMI_HDMI_AOCR_i2so4_mask),
			(HDMI_HDMI_AOCR_spdifo1_mask|HDMI_HDMI_AOCR_spdifo2_mask|
			HDMI_HDMI_AOCR_spdifo3_mask|HDMI_HDMI_AOCR_spdifo4_mask|
			HDMI_HDMI_AOCR_i2so1_mask|HDMI_HDMI_AOCR_i2so2_mask|
			HDMI_HDMI_AOCR_i2so3_mask|HDMI_HDMI_AOCR_i2so4_mask));
	} else {
		hdmiport_mask(HDMI_HDMI_AOCR_reg,
			~(HDMI_HDMI_AOCR_spdifo1_mask|HDMI_HDMI_AOCR_spdifo2_mask|
			HDMI_HDMI_AOCR_spdifo3_mask|HDMI_HDMI_AOCR_spdifo4_mask|
			HDMI_HDMI_AOCR_i2so1_mask|HDMI_HDMI_AOCR_i2so2_mask|
			HDMI_HDMI_AOCR_i2so3_mask|HDMI_HDMI_AOCR_i2so4_mask),
			0);

		hdmiport_mask(HDMI_HDMI_AVMCR_reg, ~(HDMI_HDMI_AVMCR_aoc_mask|HDMI_HDMI_AVMCR_aomc_mask), HDMI_HDMI_AVMCR_aoc_mask);
		//hdmiport_out(HDMI_HDMI_CMCR_reg,0x50);   //K code =2
	}
}

void lib_hdmi_audio_set_hbr_manual_mode(unsigned char nport, unsigned char manu, unsigned char mode_fw)
{
	hdmiport_mask(HDMI_High_Bit_Rate_Audio_Packet_reg,
		~(HDMI_High_Bit_Rate_Audio_Packet_hbr_audio_mode_manual_mask|
		HDMI_High_Bit_Rate_Audio_Packet_hbr_audio_mode_fw_mask),
		HDMI_High_Bit_Rate_Audio_Packet_hbr_audio_mode_manual(manu)|
		HDMI_High_Bit_Rate_Audio_Packet_hbr_audio_mode_fw(mode_fw));
}

void lib_hdmi_audio_clear_hdr_status(unsigned char nport)
{
	hdmiport_mask(HDMI_High_Bit_Rate_Audio_Packet_reg,
		~HDMI_High_Bit_Rate_Audio_Packet_hbr_audio_mode_mask,
		HDMI_High_Bit_Rate_Audio_Packet_hbr_audio_mode_mask);
}

unsigned char lib_hdmi_audio_get_hbr_mode(unsigned char nport)
{
	return HDMI_High_Bit_Rate_Audio_Packet_get_hbr_audio_mode(hdmi_in(HDMI_High_Bit_Rate_Audio_Packet_reg));
}

unsigned char lib_hdmi_audio_get_channel_status15_0(unsigned char nport, unsigned int bitmask, unsigned int bitshift)
{
	hdmi_out(HDMI_HDMI_ACRCR_reg, HDMI_HDMI_ACRCR_pucsr_mask);
	msleep(80);
	return ((bitmask&(hdmi_in(HDMI_HDMI_ACS0_reg)))>>bitshift);
}

unsigned char lib_hdmi_audio_get_channel_status39_16(unsigned char nport, unsigned int bitmask, unsigned int bitshift)
{
	hdmi_out(HDMI_HDMI_ACRCR_reg, HDMI_HDMI_ACRCR_pucsr_mask);
	msleep(80);
	return ((bitmask&(hdmi_in(HDMI_HDMI_ACS1_reg)))>>bitshift);
}

unsigned char lib_hdmi_audio_get_thread_run(unsigned char nport)
{
#if AUDIO_THREAD_MODIFY
	return audio_thread_run[nport];
#endif //#if AUDIO_THREAD_MODIFY

	return _TRUE;
}

void lib_hdmi_audio_set_thread_run(unsigned char nport, unsigned char uc_run)
{
#if AUDIO_THREAD_MODIFY
//	HDMI_PRINTF("lib_hdmi_audio_set_thread_run[%d]=%d\n", nport, uc_run);
	audio_thread_run[nport] = uc_run;
#endif //#if AUDIO_THREAD_MODIFY
}

void lib_hdmi_set_toggle_hpd_z0_flag(unsigned char nport, unsigned char uc_flag)
{
#if HDMI_TOGGLE_HPD_Z0_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_toggle_hpd_z0_flag[%d]=%d\n", nport, uc_flag);
	hdmi_toggle_hpd_z0_flag[nport] = uc_flag;
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE
}

unsigned char lib_hdmi_get_toggle_hpd_z0_flag(unsigned char nport)
{
#if HDMI_TOGGLE_HPD_Z0_ENABLE
	return hdmi_toggle_hpd_z0_flag[nport];
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	return _FALSE;
}

unsigned char lib_hdmi_toggle_hpd_z0_check(unsigned char nport, unsigned char ucInit)
{
#if HDMI_TOGGLE_HPD_Z0_ENABLE
	static unsigned int start_time = 0;
	static unsigned int current_time = 0;

	if(_FALSE == lib_hdmi_get_toggle_hpd_z0_flag(nport))
		return _TRUE;

	if(_TRUE == ucInit)
	{
		// need to think, if start time almost overflow
		start_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;
		current_time = start_time;
		HDMI_EMG("lib_hdmi_toggle_hpd_z0_check nport=%x, start=%d\n", nport, start_time);
		return _TRUE;
	}

	current_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;

	if(current_time >= start_time)
	{
		if(current_time - start_time >= HDMI_START_TOGGLE_HPD_Z0_MS)
		{
			newbase_hdmi_set_hpd(nport , 0, INIT_HPD_OFF);
			lib_hdmi_z0_set(nport, LN_ALL, 0);
			msleep(HDMI_TOGGLE_HPD_Z0_MS);
			lib_hdmi_z0_set(nport, LN_ALL, 1);
			newbase_hdmi_set_hpd(nport , 1, INIT_HPD_OFF);
			HDMI_EMG("lib_hdmi_toggle_hpd_z0_check nport=%x, time=%d\n", nport, current_time);
			lib_hdmi_set_dc_on_delay_state(nport, HDMI_DC_ON_ENABLE_DELAY);
			lib_hdmi_set_toggle_hpd_z0_flag(nport, _FALSE);
		}
	}
	else// if(current_time <= start_time)
	{
		HDMI_EMG("lib_hdmi_toggle_hpd_z0_check over, start_time=%d, current_time=%d\n", start_time, current_time);
		lib_hdmi_set_toggle_hpd_z0_flag(nport, _FALSE);
	}
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	return _TRUE;
}

void lib_hdmi_set_dc_on_delay_state(unsigned char nport, HDMI_DC_ON_STATE_E state)
{
#if HDMI_TOGGLE_HPD_Z0_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_dc_on_delay_state[%d]=%d\n", nport, state);
	hdmi_dc_on_delay_state[nport] = state;
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE
}

HDMI_DC_ON_STATE_E lib_hdmi_get_dc_on_delay_state(unsigned char nport)
{
#if HDMI_TOGGLE_HPD_Z0_ENABLE
	return hdmi_dc_on_delay_state[nport];
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	return HDMI_DC_ON_NONE;
}

unsigned char lib_hdmi_dc_on_delay_check(unsigned char nport, unsigned char ucInit)
{
#if HDMI_TOGGLE_HPD_Z0_ENABLE
	static unsigned int start_time = 0;
	static unsigned int current_time = 0;

	if(_FALSE == lib_hdmi_get_toggle_hpd_z0_flag(nport))
		return _TRUE;

	if(_TRUE == ucInit)
	{
		if(HDMI_DC_ON_ENABLE_DELAY != lib_hdmi_get_dc_on_delay_state(nport))
			return _TRUE;

		lib_hdmi_set_dc_on_delay_state(nport, HDMI_DC_ON_START_TIME);
		// need to think, if start time almost overflow
		start_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;
		current_time = start_time;
		HDMI_EMG("lib_hdmi_dc_on_delay_check nport=%x, start=%d\n", nport, start_time);
		return _TRUE;
	}

	if(HDMI_DC_ON_START_TIME != lib_hdmi_get_dc_on_delay_state(nport))
		return _TRUE;

	current_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;

	if(current_time >= start_time)
	{
		if(current_time - start_time >= HDMI_DC_ON_DELAY_MS)
		{
			HDMI_EMG("lib_hdmi_dc_on_delay_check nport=%x, time=%d\n", nport, current_time);
			lib_hdmi_set_dc_on_delay_state(nport, HDMI_DC_ON_FINISH);
			return _TRUE;
		}
	}
	else// if(current_time <= start_time)
	{
		HDMI_EMG("lib_hdmi_dc_on_delay_check over, start_time=%d, current_time=%d\n", start_time, current_time);
		lib_hdmi_set_dc_on_delay_state(nport, HDMI_DC_ON_NONE);
		return _TRUE;
	}

	return _FALSE;
#endif //#if HDMI_TOGGLE_HPD_Z0_ENABLE

	return _TRUE;
}

void lib_hdmi_set_str_toggle_hpd_state(unsigned char nport, HDMI_STR_HPD_TOGGLE_STATE_E state)
{
#if HDMI_STR_TOGGLE_HPD_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_str_toggle_hpd_state[%d]=%d\n", nport, state);
	hdmi_str_toggle_hpd_state[nport] = state;
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE
}

HDMI_STR_HPD_TOGGLE_STATE_E lib_hdmi_get_str_toggle_hpd_state(unsigned char nport)
{
#if HDMI_STR_TOGGLE_HPD_ENABLE
	return hdmi_str_toggle_hpd_state[nport];
#endif //#if HDMI_STR_TOGGLE_HPD_ENABLE

	return HDMI_STR_HPD_TOGGLE_NONE;
}

void lib_hdmi_set_delay_display_enable(unsigned char nport, unsigned char ucEnable)
{
#if HDMI_DISPLAY_DELAY_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_delay_display_enable[%d]=%d\n", nport, ucEnable);
	hdmi_delay_display_enable[nport] = ucEnable;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE
}

unsigned char lib_hdmi_get_delay_display_enable(unsigned char nport)
{
#if HDMI_DISPLAY_DELAY_ENABLE
	return hdmi_delay_display_enable[nport];
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

	return _DISABLE;
}

void lib_hdmi_set_delay_display_state(unsigned char nport, HDMI_DISPLAY_DELAY_STATE_STATE_E state)
{
#if HDMI_DISPLAY_DELAY_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_delay_display_state[%d]=%d\n", nport, state);
	hdmi_delay_display_state[nport] = state;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE
}

HDMI_DISPLAY_DELAY_STATE_STATE_E lib_hdmi_get_delay_display_state(unsigned char nport)
{
#if HDMI_DISPLAY_DELAY_ENABLE
	return hdmi_delay_display_state[nport];
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

	return HDMI_DISPLAY_DELAY_NONE;
}

unsigned char lib_hdmi_delay_check_before_display(unsigned char nport, unsigned char ucInit)
{
#if HDMI_DISPLAY_DELAY_ENABLE
	static unsigned int start_time = 0;
	static unsigned int current_time = 0;
	unsigned int Delay_Time = 0;

	if(_DISABLE == lib_hdmi_get_delay_display_enable(nport))
		return _TRUE;

	if(_TRUE == ucInit)
	{
		if(HDMI_DISPLAY_DELAY_INIT == lib_hdmi_get_delay_display_state(nport))
		{
			lib_hdmi_set_delay_display_state(nport, HDMI_DISPLAY_DELAY_START);
			// need to think, if start time almost overflow
			start_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;
			current_time = start_time;
			HDMI_EMG("lib_hdmi_delay_check_before_display nport=%x, start=%d\n", nport, start_time);
		}
		return _TRUE;
	}

	if(HDMI_DISPLAY_DELAY_START != lib_hdmi_get_delay_display_state(nport))
		return _TRUE;

	Delay_Time = lib_hdmi_get_delay_display_time(nport);
	current_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;

	if(current_time >= start_time)
	{
		if(current_time - start_time >= Delay_Time)
		{
			HDMI_EMG("lib_hdmi_delay_check_before_display nport=%x, time=%d\n", nport, current_time);
			lib_hdmi_set_delay_display_state(nport, HDMI_DISPLAY_DELAY_FINISH);
			return _TRUE;
		}
	}
	else// if(current_time <= start_time)
	{
		HDMI_EMG("lib_hdmi_delay_check_before_display over, start_time=%d, current_time=%d\n", start_time, current_time);
		lib_hdmi_set_delay_display_state(nport, HDMI_DISPLAY_DELAY_FINISH);
		return _TRUE;
	}

	return _FALSE;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

	return _TRUE;
}

unsigned int lib_hdmi_get_delay_display_time(unsigned char nport)
{
	unsigned int DelayTime = 0; //ms

	switch(lib_hdmi_get_specific_device(nport))
	{
		case HDMI_SPECIFIC_DEVICE_LHB_755:
			DelayTime = HDMI_DISPLAY_DELAY_LHB_755_MS;
		break;

		case HDMI_SPECIFIC_DEVICE_ROKU_ULTRA_4640R:
			DelayTime = HDMI_DISPLAY_DELAY_ROKU_ULTRA_4640R_MS;
		break;

//		case HDMI_SPECIFIC_DEVICE_NONE:
		default:
			//other device, all 0
			DelayTime = 0;
		break;
	}

	return DelayTime;
}

//USER:LewisLee DATE:2016/12/27
//select delay by debounce or delay function
//don't delay too long
unsigned char lib_hdmi_delay_display_action(unsigned char nport)
{
#if HDMI_DISPLAY_DELAY_ENABLE
	unsigned char Need_Debounce = _FALSE;

	switch(lib_hdmi_get_specific_device(nport))
	{
		case HDMI_SPECIFIC_DEVICE_LHB_755:
			msleep(HDMI_DISPLAY_DELAY_LHB_755_MS_2); //OK
			Need_Debounce = _FALSE;
			HDMI_EMG("LHB_755 delay\n");
		break;

		case HDMI_SPECIFIC_DEVICE_ROKU_ULTRA_4640R:
			msleep(HDMI_DISPLAY_DELAY_ROKU_ULTRA_4640R_MS); //OK
			Need_Debounce = _FALSE;
			HDMI_EMG("Roku Ultra 4640R\n");
		break;

//		case HDMI_SPECIFIC_DEVICE_NONE:
		default:
			//other device, all 0
			Need_Debounce = _FALSE;
		break;
	}

	return Need_Debounce;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

	return _FALSE;
}

void lib_hdmi_set_specific_device(unsigned char nport, HDMI_SPECIFIC_DEVICE_E device)
{
#if 1 //#if HDMI_DISPLAY_DELAY_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_specific_device[%d]=%d\n", nport, device);
	hdmi_specific_device[nport] = device;
#endif //#if HDMI_DISPLAY_DELAY_ENABLE
}

HDMI_SPECIFIC_DEVICE_E lib_hdmi_get_specific_device(unsigned char nport)
{
#if 1 //#if HDMI_DISPLAY_DELAY_ENABLE
	return hdmi_specific_device[nport];
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

	return HDMI_SPECIFIC_DEVICE_NONE;
}

void lib_hdmi_misc_variable_initial(unsigned char port)
{
	lib_hdmi_set_specific_device(port, HDMI_SPECIFIC_DEVICE_NONE);

#if HDMI_DISPLAY_DELAY_ENABLE
	lib_hdmi_set_delay_display_enable(port, _DISABLE);
	lib_hdmi_set_delay_display_state(port, HDMI_DISPLAY_DELAY_NONE);
#endif //#if HDMI_DISPLAY_DELAY_ENABLE

#if HDCP_STATUS_CHECK_ENABLE
	lib_hdmi_set_hdcp_check_toggle_state(port, HDMI_HDCP_TOGGLE_NONE);
#endif //#if HDCP_STATUS_CHECK_ENABLE
}

void lib_hdmi_set_hdcp_check_toggle_state(unsigned char nport, HDMI_HDCP_TOGGLE_STATUS_T status)
{
#if HDCP_STATUS_CHECK_ENABLE
//	HDMI_PRINTF("lib_hdmi_set_delay_display_enable[%d]=%d\n", nport, ucEnable);
	hdmi_hdcp_check_toggle_state[nport] = status;
#endif //#if HDCP_STATUS_CHECK_ENABLE
}

HDMI_HDCP_TOGGLE_STATUS_T lib_hdmi_get_hdcp_check_toggle_state(unsigned char nport)
{
#if HDCP_STATUS_CHECK_ENABLE
	return hdmi_hdcp_check_toggle_state[nport];
#endif //#if HDCP_STATUS_CHECK_ENABLE

	return HDMI_HDCP_TOGGLE_NONE;
}

unsigned char lib_hdmi_hdcp_status_check(unsigned char nport, unsigned char IsInit)
{
#if HDCP2_2
#if HDCP_STATUS_CHECK_ENABLE
	static unsigned int start_time = 0;
	static unsigned int current_time = 0;

	if(_TRUE == IsInit)
	{
		// need to think, if start time almost overflow
		start_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;
		current_time = start_time;
		lib_hdmi_set_hdcp_check_toggle_state(nport, HDMI_HDCP_TOGGLE_ENABLE);
		HDMI_EMG("[HDCP] lib_hdmi_hdcp_status_check nport=%x, start=%d\n", nport, start_time);

		//Write clear ADNE_FLAG
		hdmi_out(HDMI_HDCP_FLAG1_reg, _BIT7);
		return _TRUE;
	}

	if(lib_hdmi_get_hdcp_check_toggle_state(nport) != HDMI_HDCP_TOGGLE_ENABLE)
		return _TRUE;

	if(_ENABLE == lib_hdmi_hdcp22_is_onoff(nport))
	{
		if(HDMI_HDCP_2p2_SR0_get_state(hdmi_in(HDMI_HDCP_2p2_SR0_reg)) >= HDMI_HDCP_2P2_AUTHENTICATED)
				return _TRUE;
		}
	else if(_ENABLE == lib_hdmi_hdcp14_is_onoff(nport))
		{
		if(1 == HDMI_HDCP_FLAG1_get_adne_flag(hdmi_in(HDMI_HDCP_FLAG1_reg)))
			return _TRUE;
		}
	else
	{
		return _TRUE;
	}


	current_time = hdmi_in(TIMER_SCPU_CLK90K_LO_reg)/90;

	if(current_time >= start_time)
	{
		if(current_time - start_time >= HDCP_STATUS_CHECK_TOGGLE_MS)
		{
			HDMI_EMG("[HDCP] lib_hdmi_hdcp_status_check nport=%x, time=%d\n", nport, current_time);
			lib_hdmi_hdcp_toggle_action(nport);
			return _FALSE;
		}
	}
	else// if(current_time <= start_time)
	{
		HDMI_EMG("[HDCP] lib_hdmi_hdcp_status_check over, start_time=%d, current_time=%d\n", start_time, current_time);
		lib_hdmi_set_hdcp_check_toggle_state(nport, HDMI_HDCP_TOGGLE_EXIT);
		return _TRUE;
	}
#endif //#if HDCP_STATUS_CHECK_ENABLE
#endif //#if HDCP2_2

	return _TRUE;
}

//USER:LewisLee DATE:2017/01/04
//In different device, use different solution
unsigned char lib_hdmi_hdcp_toggle_action(unsigned char nport)
{
#if HDCP_STATUS_CHECK_ENABLE
	switch(lib_hdmi_get_specific_device(nport))
	{
		case HDMI_SPECIFIC_DEVICE_ROKU_ULTRA_4640R:
#if 1
			newbase_hdmi_set_hpd(nport , 0, INIT_HPD_OFF);
			msleep(HDCP_STATUS_CHECK_ROKU_ULTRA_4640R_HPD_MS);
			newbase_hdmi_set_hpd(nport , 1, INIT_HPD_OFF);
#else //#if 1
			newbase_hdmi_set_hpd(nport , 0, INIT_HPD_OFF);
			if (0 == HDMI_WQ_HPD_START(HDCP_STATUS_CHECK_ROKU_ULTRA_4640R_HPD_MS)) {
				HDMI_EMG("Roku Ultra 4640R toggle HPD\n");
			}
#endif //#if 1
		break;

//		case HDMI_SPECIFIC_DEVICE_NONE:
		default:

		break;
	}

	return _TRUE;
#endif //#if HDCP_STATUS_CHECK_ENABLE

	return _TRUE;
}

void lib_hdmi_audio_pv_wd_enable(unsigned char nport, unsigned char on_off)
{

	if (on_off) {
		hdmiport_mask(HDMI_HDMI_AWDSR_reg, ~(HDMI_HDMI_AWDSR_awdpvsb_mask), 0xFF);

	} else {
		hdmiport_mask(HDMI_HDMI_AWDSR_reg, ~(HDMI_HDMI_AWDSR_awdpvsb_mask), 0x00);
	}
}

void lib_hdmi_video_pv_wd_enable(unsigned char nport, unsigned char on_off)
{

	if (on_off) {
		hdmiport_mask(HDMI_HDMI_VWDSR_reg, ~(HDMI_HDMI_VWDSR_vwdpvsb_mask), 0xFF);

	} else {
		hdmiport_mask(HDMI_HDMI_VWDSR_reg, ~(HDMI_HDMI_VWDSR_vwdpvsb_mask), 0x00);
	}
}

void lib_hdmi_pv_irq_enable(unsigned char nport, unsigned char on_off)
{

	if (on_off) {
		hdmiport_mask(HDMI_HDMI_PAMICR_reg, ~(HDMI_HDMI_PAMICR_icpvsb_mask), 0xFF);

	} else {
		hdmiport_mask(HDMI_HDMI_PAMICR_reg, ~(HDMI_HDMI_PAMICR_icpvsb_mask), 0x00);
	}
}


void lib_hdmi_packet_contnet_clear(unsigned nport, unsigned char pkt_type)
{
	switch (pkt_type)
	{

		case ACKG:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_ackg_clr_mask), HDMI_HDMI_PCMC_ackg_clr_mask);
			break;
		case SPD_INFO:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_spd_info_clr_mask), HDMI_HDMI_PCMC_spd_info_clr_mask);
			break;
		case DRM_INFO:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_drm_info_clr_mask), HDMI_HDMI_PCMC_drm_info_clr_mask);
			break;
		case FVS:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_fvs_info_clr_mask), HDMI_HDMI_PCMC_fvs_info_clr_mask);
			break;
		case GM:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_gm_clr_mask), HDMI_HDMI_PCMC_gm_clr_mask);
			break;
		case VS_INFO:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_vs_info_clr_mask), HDMI_HDMI_PCMC_vs_info_clr_mask);
			break;
		case MPEG_INFO:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_mpeg_info_clr_mask), HDMI_HDMI_PCMC_mpeg_info_clr_mask);
			break;
		case ISRC2:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_isrc2_clr_mask), HDMI_HDMI_PCMC_isrc2_clr_mask);
			break;
		case ISRC1:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_isrc1_clr_mask), HDMI_HDMI_PCMC_isrc1_clr_mask);
			break;
		case ACP:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_acp_clr_mask), HDMI_HDMI_PCMC_acp_clr_mask);
			break;
		case AUDIO_INFO:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_audio_info_clr_mask), HDMI_HDMI_PCMC_audio_info_clr_mask);
			break;
		case AVI_INFO:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(HDMI_HDMI_PCMC_avi_info_clr_mask), HDMI_HDMI_PCMC_avi_info_clr_mask);
			break;
		case ALL_PKT:
			hdmiport_mask(HDMI_HDMI_PCMC_reg, ~(0xFFF), 0xFFF);
			break;
	}

	hdmiport_mask(HDMI_HDMI_PCMC_reg,~(0xFFF), 0x0);

}

// only port0
void lib_hdmi_enable_hdr_dolby_meta_info_check(unsigned char on_off)
{
	if (on_off) {
			hdmiport_mask(HDMI_MDD_CR_reg, ~(HDMI_MDD_CR_no_md_check_mask | HDMI_MDD_CR_metadata_version_check_mask | HDMI_MDD_CR_metadata_type_check_mask),
		    (HDMI_MDD_CR_no_md_check_mask | HDMI_MDD_CR_metadata_version_check_mask | HDMI_MDD_CR_metadata_type_check_mask));
	} else {
			hdmiport_mask(HDMI_MDD_CR_reg, ~(HDMI_MDD_CR_no_md_check_mask | HDMI_MDD_CR_metadata_version_check_mask | HDMI_MDD_CR_metadata_type_check_mask), 0x0);
	}
}

void lib_hdmi_enable_hdr_dolby_md_detect(unsigned char on_off)
{
	if (on_off) {
		hdmiport_mask(HDMI_MDD_CR_reg, ~(HDMI_MDD_CR_en_mask), HDMI_MDD_CR_en_mask);

	} else {
		hdmiport_mask(HDMI_MDD_CR_reg, ~(HDMI_MDD_CR_en_mask), 0x0);
	}

}


unsigned char lib_hdmi_hdr_dolby_detect_res_change(void)
{

	if (hdmiport_in(HDMI_MDD_SR_reg) & _BIT1) {
		hdmiport_out(HDMI_MDD_SR_reg, HDMI_MDD_SR_det_result_chg_mask);
		return 1;
	}
	else {
		return 0;
	}

}

unsigned char lib_hdmi_hdr_dolby_res_det(void)
{
	return HDMI_MDD_SR_get_det_result(hdmiport_in(HDMI_MDD_SR_reg));

}

unsigned char lib_hdmi_hdr_dolby_frame_crc_det(void)
{

	return HDMI_MDD_SR_get_frame_crc_result(hdmiport_in(HDMI_MDD_SR_reg));

}




void lib_hdmi_dbg_reg_dump(unsigned char nport)
{

	#define AUDIO_REG_DBG 1
	#define VIDEO_REG_DBG 1
	#define HDCP_REG_DBG 1
	#define MHL_REG_DBG 1

	HDMI_EMG("===================Port%d Dump Reg Start===================\n",nport);
#if AUDIO_REG_DBG
	HDMI_EMG("###################Audio Part Begin###################\n");
	HDMI_EMG("SR=%x AFCR=%x \n",hdmiport_in(HDMI_HDMI_SR_reg),hdmiport_in(HDMI_HDMI_AFCR_reg));
	HDMI_EMG("ASR0=%x ASR1=%x \n",hdmiport_in(HDMI_HDMI_ASR0_reg),hdmiport_in(HDMI_HDMI_ASR1_reg));
	HDMI_EMG("APLLCR0=%x APLLCR1=%x APLLCR2=%x APLLCR3=%x\n",hdmiport_in(HDMI_HDMI_APLLCR0_reg),hdmiport_in(HDMI_HDMI_APLLCR1_reg),hdmiport_in(HDMI_HDMI_APLLCR2_reg),hdmiport_in(HDMI_HDMI_APLLCR3_reg));
	HDMI_EMG("ACRCR= %x ACRSR0=%x ACRSR1=%x \n",hdmiport_in(HDMI_HDMI_ACRCR_reg),hdmiport_in(HDMI_HDMI_ACRSR0_reg),hdmiport_in(HDMI_HDMI_ACRSR1_reg));
	HDMI_EMG("CTS_UP_BOUND=%x  CTS_LOW_BOUND=%x \n",hdmiport_in(HDMI_AUDIO_CTS_UP_BOUND_reg),hdmiport_in(HDMI_AUDIO_CTS_LOW_BOUND_reg));
	HDMI_EMG("N_UP_BOUND=%x  N_LOW_BOUND=%x \n",hdmiport_in(HDMI_AUDIO_N_UP_BOUND_reg),hdmiport_in(HDMI_AUDIO_N_LOW_BOUND_reg));
	HDMI_EMG("INTCR=%x SR_CHG=%x AOCR=%x  \n",hdmiport_in(HDMI_HDMI_INTCR_reg),hdmiport_in(HDMI_Audio_Sample_Rate_Change_IRQ_reg),hdmiport_in(HDMI_HDMI_AOCR_reg));
	HDMI_EMG("###################Audio Part End###################\n");
#endif

#if VIDEO_REG_DBG

	HDMI_EMG("###################TMDS Channel Status Begin###################\n");
	HDMI_EMG("TMDS_CTRL=%x TMDS_OUTCTL=%x \n",hdmiport_in(HDMI_TMDS_CTRL_reg),hdmiport_in(HDMI_TMDS_OUTCTL_reg));
	HDMI_EMG("###################TMDS Channel Status End###################\n");


	HDMI_EMG("###################Deep Color Status Begin###################\n");
	HDMI_EMG("DPC_SET2=%x DPC_SET3=%x \n",hdmiport_in(HDMI_TMDS_DPC_SET2_reg),hdmiport_in(HDMI_TMDS_DPC_SET3_reg));
	HDMI_EMG("###################Deep Color Status End###################\n");


	HDMI_EMG("###################Data Enable Error Status Begin###################\n");
	HDMI_EMG("DET_STS=%x \n",hdmiport_in(HDMI_TMDS_DET_STS_reg));
	HDMI_EMG("###################Data Enable Error Status End###################\n");

	HDMI_EMG("###################Video Data Error Detect Begin###################\n");
	HDMI_EMG("BIT_ERR_B=%x BIT_ERR_G=%x BIT_ERR_R=%x \n",hdmiport_in(HDMI_VIDEO_BIT_ERR_STATUS_B_reg),hdmiport_in(HDMI_VIDEO_BIT_ERR_STATUS_G_reg), hdmiport_in(HDMI_VIDEO_BIT_ERR_STATUS_R_reg));
	HDMI_EMG("TREC4_ERR_B=%x TREC4_ERR_G=%x TREC4_ERR_R=%x \n",hdmiport_in(HDMI_TERC4_ERR_STATUS_B_reg),hdmiport_in(HDMI_TERC4_ERR_STATUS_G_reg), hdmiport_in(HDMI_TERC4_ERR_STATUS_R_reg));
	HDMI_EMG("BCH_ERR=%x \n",hdmiport_in(HDMI_HDMI_BCHCR_reg));
	HDMI_EMG("###################Video Data Error Detect End###################\n");


	HDMI_EMG("################### Video Control Register Begin###################\n");
	HDMI_EMG("VCR=%x \n",hdmiport_in(HDMI_HDMI_VCR_reg));
	HDMI_EMG("###################Video Control Register End###################\n");

	HDMI_EMG("###################Guard Band Error Status Begin###################\n");
	HDMI_EMG("BCSR=%x \n",hdmiport_in(HDMI_HDMI_BCSR_reg));
	HDMI_EMG("###################Guard Band Error Status End###################\n");


	HDMI_EMG("###################PRBS Status Begin###################\n");
	HDMI_EMG("PRBS_R=%x PRBS_G=%x PRBS_B=%x\n",hdmiport_in(HDMI_PRBS_R_CTRL_reg),hdmiport_in(HDMI_PRBS_G_CTRL_reg),hdmiport_in(HDMI_PRBS_B_CTRL_reg));
	HDMI_EMG("###################PRBS Status End###################\n");


	HDMI_EMG("###################Asynchronous Fifo Status Begin###################\n");
	HDMI_EMG("FIFO_SR0=%x FIFO_SR1=%x\n",hdmiport_in(HDMI_PHY_FIFO_SR0_reg),hdmiport_in(HDMI_PHY_FIFO_SR1_reg));
	HDMI_EMG("CHSR=%x\n",hdmiport_in(HDMI_CH_SR_reg));
	HDMI_EMG("###################PHY Asynchronous Fifo Status End###################\n");


	HDMI_EMG("###################Asynchronous Fifo Status Begin###################\n");
	HDMI_EMG("FIFO_SR0=%x FIFO_SR1=%x\n",hdmiport_in(HDMI_PHY_FIFO_SR0_reg),hdmiport_in(HDMI_PHY_FIFO_SR1_reg));
	HDMI_EMG("CHSR=%x\n",hdmiport_in(HDMI_CH_SR_reg));
	HDMI_EMG("###################PHY Asynchronous Fifo Status End###################\n");

#if HDMI2p0
	HDMI_EMG("###################Scramble Status Begin###################\n");
	HDMI_EMG("SCR_CR=%x\n",hdmiport_in(HDMI_SCR_CR_reg));
	HDMI_EMG("###################Scramble Status End###################\n");


	HDMI_EMG("###################CED Status Begin###################\n");
	HDMI_EMG("CER_SR0=%x CER_SR1=%x CER_SR2=%x\n",hdmiport_in(HDMI_CERSR0_reg), hdmiport_in(HDMI_CERSR1_reg), hdmiport_in(HDMI_CERSR2_reg));
	HDMI_EMG("CER_SR3=%x CER_SR4=%x\n",hdmiport_in(HDMI_CERSR3_reg), hdmiport_in(HDMI_CERSR4_reg));
	HDMI_EMG("###################CED Statuss End###################\n");


	HDMI_EMG("###################YUV420 FIFO Status Begin###################\n");
	HDMI_EMG("YUV420_CR=%x\n",hdmiport_in(HDMI_YUV420_CR_reg));
	HDMI_EMG("###################YUV420 FIFO Status End###################\n");


	HDMI_EMG("###################PMM CLK Status Begin###################\n");
	HDMI_EMG("CLK_DET_SR=%x\n",hdmiport_in(HDMI_ACDRCLKDETSR_reg));
	HDMI_EMG("###################PMM CLK Status End###################\n");
#endif

#endif


#if HDCP_REG_DBG
	HDMI_EMG("###################HDCP Status Begin###################\n");
	HDMI_EMG("PCR=%x\n",hdmiport_in(HDMI_HDCP_PCR_reg));  //check ENC
	HDMI_EMG("HDCP_FLAG1=%x\n",hdmiport_in(HDMI_HDCP_FLAG1_reg));
	HDMI_EMG("HDCP2P2_SR0=%x\n",hdmiport_in(HDMI_HDCP_2p2_SR0_reg));
	HDMI_EMG("###################HDCP Status End###################\n");
#endif

#if MHL_SUPPORT
#if MHL_REG_DBG
	HDMI_EMG("###################MHL Status Begin###################\n");
	HDMI_EMG("LEADING_GB_CMP=%x\n",hdmiport_in(HDMI_HDMI_leading_GB_cmp_ctrl_reg));
	HDMI_EMG("AUDIO_CTS_UP=%x AUDIO_CTS_LOW=%x\n",hdmiport_in(HDMI_AUDIO_CTS_UP_BOUND_reg), hdmiport_in(HDMI_AUDIO_CTS_LOW_BOUND_reg));
	HDMI_EMG("AUDIO_N_UP=%x AUDIO_N_LOW=%x\n",hdmiport_in(HDMI_AUDIO_N_UP_BOUND_reg), hdmiport_in(HDMI_AUDIO_N_LOW_BOUND_reg));

	if (nport == 0) {
		HDMI_EMG("P0_MHL_STATUS=%x\n",hdmiport_in(MHL_P0_PORT0_MHL_STATUS_reg));
	}
	else if (nport == 1) {
		HDMI_EMG("P1_MHL_STATUS=%x\n",hdmiport_in(MHL_P1_PORT1_MHL_STATUS_reg));
	}
	else {
		HDMI_EMG("P2_MHL_STATUS=%x\n",hdmiport_in(MHL_P2_PORT2_MHL_STATUS_reg));
	}
	HDMI_EMG("###################MHL Status End###################\n");
#endif
#endif

	HDMI_EMG("===================Port%d Dump Reg End===================\n",nport);

}
