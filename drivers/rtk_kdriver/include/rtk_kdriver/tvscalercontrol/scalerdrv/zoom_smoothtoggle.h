#ifndef ZOOM_SMOOTHTOGGLE_H_
#define ZOOM_SMOOTHTOGGLE_H_

#include <scalercommon/scalerCommon.h>
///#include "tvscalercontrol/scaler/scalerlib.h"

typedef struct _SMOOTH_TOGGLE_SZIE{
	unsigned int	nWidth;
	unsigned int	nLength;
} SMOOTH_TOGGLE_SIZE;

typedef struct _SMOOTH_TOGGLE_INFO {
	unsigned int IMD_SMOOTH_H_ACT_WID_PRE;
	unsigned int IMD_SMOOTH_V_ACT_LEN_PRE;
	unsigned int IMD_SMOOTH_H_ACT_STA_PRE;
	unsigned int IMD_SMOOTH_V_ACT_STA_PRE;
	unsigned int IMD_SMOOTH_H_ACT_WID;
	unsigned int IMD_SMOOTH_H_ACT_STA;
	unsigned int IMD_SMOOTH_V_ACT_LEN;
	unsigned int IMD_SMOOTH_V_ACT_STA;
	unsigned int IMD_SMOOTH_CapWid;			///! capture window width
	unsigned int IMD_SMOOTH_CapLen;			///! capture window length
	unsigned int IMD_SMOOTH_DI_WID;
	unsigned int IMD_SMOOTH_DI_LEN;	
	unsigned int IMD_SMOOTH_MEM_ACT_HSTA;	// the active start x-pixle of FIFO output in M-domain
	unsigned int IMD_SMOOTH_MEM_ACT_VSTA;	// the active start y-pixle of FIFO output in M-domain
	unsigned int IMD_SMOOTH_MEM_ACT_WID;    // the active width of FIFO output in M-domain
	unsigned int IMD_SMOOTH_MEM_ACT_LEN;	// the active length of FIFO output in M-domain
	unsigned int IMD_SMOOTH_DispWid;			// display window width
	unsigned int IMD_SMOOTH_DispLen;			// display window length
	unsigned int IMD_SMOOTH_H_TOTAL;
	unsigned int IMD_SMOOTH_V_TOTAL;
	unsigned int IMD_SMOOTH_FRAMESYNC;
	unsigned char IMD_SMOOTH_H_SCALE_DOWN;
	unsigned char IMD_SMOOTH_V_SCALE_DOWN;
	unsigned char IMD_SMOOTH_H_SCALE_UP;
	unsigned char IMD_SMOOTH_V_SCALE_UP;
	unsigned char IMD_SMOOTH_DISP_RTNR;
	unsigned char IMD_SMOOTH_V_UZD_BUFFER_MODE;
	unsigned char IMD_SMOOTH_DISP_422;
	unsigned char IMD_SMOOTH_DISP_422CAP;
	unsigned char IMD_SMOOTH_DI_CUT_4_LINES;
	unsigned char IMD_SMOOTH_DISP_THRIP;
	unsigned char IMD_SMOOTH_MODE_CURR;
	unsigned char IMD_SMOOTH_DISP_10BIT;//rika
	unsigned char IMD_SMOOTH_DISP_INTERLACE;
	unsigned int IMD_SMOOTH_H_FREQ;
	unsigned int IMD_SMOOTH_V_FREQ;
	unsigned char IMD_SMOOTH_VFLIP;
	unsigned char IMD_SMOOTH_INPUT_AFD;
	unsigned char IMD_SMOOTH_DISP_MA3A;
	unsigned char IMD_SMOOTH_DISP_VFLIP3;
#ifdef CONFIG_SDNR_CROP
	unsigned int IMD_SMOOTH_SDNRH_ACT_WID_PRE;
	unsigned int IMD_SMOOTH_SDNRV_ACT_LEN_PRE;
	unsigned int IMD_SMOOTH_SDNRH_ACT_STA_PRE;
	unsigned int IMD_SMOOTH_SDNRV_ACT_STA_PRE;
	unsigned int IMD_SMOOTH_SDNRH_ACT_WID;
	unsigned int IMD_SMOOTH_SDNRH_ACT_STA;
	unsigned int IMD_SMOOTH_SDNRV_ACT_LEN;
	unsigned int IMD_SMOOTH_SDNRV_ACT_STA;
#endif
} SMOOTH_TOGGLE_INFO;


int zoom_imd_smooth_toggle_config(unsigned int  un32_windowId,
    unsigned int  un32_hposition, unsigned int  un32_vposition,
    unsigned int  un32_hsize, unsigned int  un32_vsize,unsigned char zoomfunc);

void zoom_imd_smooth_toggle_vo_enable(unsigned char enable, unsigned char display);
void zoom_imd_smooth_toggle_vo_init(unsigned char display);

int zoom_imd_smooth_toggle_proc(unsigned char rcflag,unsigned char rdflag, unsigned char display);

///int zoom_imd_smooth_toggle_testproc(void);//rika test


enum zoom_smooth_toggle_handle_state {
	ZOOM_STATE_NONE = 0,
	ZOOM_STATE_DONOW=1,
	ZOOM_STATE_WAIT_APPLY_OK = 2,//to do in modestate.cpp
	//ZOOM_STATE_DONE=3,//already done this time, and reset to NONE in modestate.cpp

};

enum zoom_smooth_toggle_state{
	//added by rika 20140611 for return value of zoom_imd_smooth_toggle_proc
	ZOOM_STATE_OK=0,
	ZOOM_STATE_FAIL=1,
	ZOOM_STATE_SAMEREGION=2,
};

enum zoom_vo_smooth_state{


	ZOOM_VOSTATE_OK=0,
	ZOOM_VOSTATE_FAIL=1,
	ZOOM_VOSTATE_START=98,
	ZOOM_VOSTATE_NONE=99,
};


enum zoom_function{
	//added by rika 20140611 for return value of zoom_imd_smooth_toggle_proc
	ZOOM_CROP=0,
	ZOOM_DISP=1,

};
//---vo related

enum VO_SCALER_AR_MODE {
	VO_SCALER_AR_ORIGINAL = 0,
	VO_SCALER_AR_1080I_BBY_ZOOM = 0 + 1,
	VO_SCALER_AR_1080I_BBY_CINEMA = 0 + 2,
	VO_SCALER_AR_AUTO_AFD = 0 + 3,
	VO_SCALER_AR_PERSON = 0 + 4,
	VO_SCALER_AR_CAPTION = 0 + 5,
	VO_SCALER_AR_MOVIE = 0 + 6,
	VO_SCALER_AR_ZOOM = 0 + 7,
	VO_SCALER_AR_ZOOM2 = 0 + 8,
	VO_SCALER_AR_ZOOM3 = 0 + 9,
	VO_SCALER_AR_CUSTOMER = 0 + 10,
};
typedef enum VO_SCALER_AR_MODE VO_SCALER_AR_MODE;


enum zoom_double_buffer_apply_ip{
	ZOOM_VGIP=0,
	ZOOM_DI = 0 + 1,
	ZOOM_DI_HSD = 0 + 2,
	ZOOM_UZD = 0 + 3,
	ZOOM_M_CAP = 0 + 4,
	ZOOM_M_DISP = 0 + 5,
	ZOOM_UZU = 0 + 6,
	ZOOM_DTG = 0 + 7,
	ZOOM_DPLL = 0 + 8,
	ZOOM_RGB2YUV= 0 + 9,
};
typedef enum zoom_double_buffer_apply_ip zoom_double_buffer_apply_ip;



//---ddk variable signal lock

#define SIGNAL_STATUS_UNKNOW			0x00
#define SIGNAL_STATUS_LOCK				0x01
#define SIGNAL_STATUS_UNLOCK			0x02
#define SIGNAL_STATUS_FORMAT_CHANGED    0x04
#define SIGNAL_STATUS_UNSTABLE			0x08


//end of ddk variable signal lock

void smooth_toggle_set_enable(unsigned char enable);
void smooth_toggle_set_finish(unsigned char enable);
void zoom_smooth_toggle_set_thlock(unsigned char enable);
unsigned char zoom_smooth_toggle_get_thlock(void);

unsigned char smooth_toggle_get_datamode_enable(void);
void imd_smooth_wait_to_apply_sucessfully(void);
unsigned char zoom_smooth_toggle_get_finish(void);
void zoom_smooth_toggle_set_finish(unsigned char enable);
void zoom_update_info_from_vo(void);
stVGIP_ADJUSTMENT_INFO get_zoom_vgip_adjust_data(unsigned char display);
unsigned char get_zoom_vgip_adjust_enable(void);
void set_zoom_vgip_adjust_enable(unsigned char enable);
void zoom_smooth_toggle_state_info_rpc
(unsigned char display,   unsigned int  crop_hpos, unsigned int  crop_vpos,
    unsigned int  crop_hsize, unsigned int  crop_vsize,
    unsigned int  disp_hpos, unsigned int   disp_vpos,
    unsigned int  disp_hsize, unsigned int  disp_vsize    );
void vo_zoom_go_smooth_toggle_set(unsigned char enable,unsigned char display);
void imd_smooth_enable_main_double_buffer(unsigned char bEnable);
void imd_smooth_enable_sub_double_buffer(unsigned char bEnable);
unsigned int imd_smooth_memory_cal_vflip_block_addr(unsigned int address, unsigned int linesize , unsigned int linenum);
void imd_smooth_MemSetDisplayVFLIPAddr(unsigned char display, unsigned int Addr1, unsigned int Addr2, unsigned int Addr3);
void imd_smooth_MemSetDisplayAddr(unsigned char display, unsigned int Addr1, unsigned int Addr2);
void imd_smooth_memory_set_main_3D_setting(unsigned int LineStep);
void zoom_photo_smooth_toggle_proc(unsigned char display,StructDisplayInfo * vo_disp);
unsigned char Scaler_Set_VOsmoothenable(unsigned char display);
unsigned char scaler_smoothtoggle_info_samecheck(unsigned char display);

void scalerVIP_smoothtoggle_init(unsigned char display, unsigned short the_width, unsigned short the_height,unsigned short Cap_width, unsigned short Cap_height, unsigned short MEM_ACT_WID, unsigned short MEM_ACT_LEN);
void scalerVIP_smoothtoggle_film_reset(void);
void imd_smooth_toggle_check_pre_double_buffer(unsigned char display);
void imd_smooth_main_double_buffer_apply(zoom_double_buffer_apply_ip apply_ip);
void imd_smooth_main_double_buffer_all_apply(void);
void imd_smooth_sub_double_buffer_all_apply(void);
void zoom_imd_smooth_check_di_buffer_mode(void);
void zoom_record_input_output_pre_size(unsigned char display,StructSrcRect inputsize,StructSrcRect outputsize);
void zoom_smoothtoggle_only_shift_xy(unsigned char display);
StructSrcRect drvif_cal_SDNR_size(unsigned char display, StructSrcRect input, StructSrcRect output);
void run_smoothtoggle_for_ip_change(unsigned char display);
void zoom_update_scaler_info_from_vo_smooth_toggle(unsigned char display);
#endif
