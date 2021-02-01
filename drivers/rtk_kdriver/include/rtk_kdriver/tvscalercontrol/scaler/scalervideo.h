#ifndef __SCALER_VIDEO_H__
#define __SCALER_VIDEO_H__

#ifdef __cplusplus
extern "C" {
#endif


/*================ Module dependency  =============== */

/*==================== Definitions ================= */
typedef enum _VD_27M_OVERSAMPLING_MODE{
	VD_27M_OFF=0x0000,
	VD_27M_HSD960_DI5A=0x0001,
	VD_27M_HSD1440_DI3A=0x0002,
} VD_27M_OVERSAMPLING_MODE;


/*==================== Variables ================= */


/*==================== Functions ================== */
/**
  fw_video_checkmode
   Check mode whether changed or not
 Check video decoder's input signal stable.
 This function will query the video decoder's status register.
 If the signal is stable return _SUCCESS, else return _FAIL.

   @param <src>        { Select signal to show }
   @return <unsigned char>    { return 1 if mode is changed, otherwise 0 }
   @return <unsigned char>    { return _SUCCESS if mode is stable,
                                  return _FAIL if mode changed }
*/
unsigned char fw_video_checkmode(unsigned char ucInputSrc);

/**
   fw_video_detectmode
   Find mode what belong to which standard(NTSC/PAL...)

   @param <void>       { void }
   @return <unsigned char>    { ucAV_Mode }

 		BIT 0~1
 		 : 1 60 Hz
 		 : 2 50 Hz
 		BIT 4~7
 		 : 00 PAL B,G,H,I
 		 : 10 NTSC M
 		 : 20 SECAM
 		 : 30 NTSC44
 		 : 40 PAL M
 		 : 50 PAL N
 		 : 60 PAL 60

   @set <ADC_CLOCK>    ??
           <IPH_ACT_STA>   ??
           <IPH_ACT_WID>   ??
           <IPV_ACT_STA>   ??
           <IPV_ACT_LEN>   ??
*/
#if defined(CONFIG_ENABLE_SPEED_UP_CH_SWITCH)	
// oliver+, 2012_06_26
unsigned char fw_video_detectmode2(unsigned char mode);
#endif
unsigned char fw_video_detectmode(void);

unsigned char fw_video_color_std_stable_check(unsigned char ucCurColorStd, unsigned char ucResetCounter);
void fw_video_set_27mhz_mode(VD_27M_OVERSAMPLING_MODE mode);
VD_27M_OVERSAMPLING_MODE fw_video_get_27mhz_mode(SCALER_DISP_CHANNEL Display);
VD_27M_OVERSAMPLING_MODE fw_video_check_enter_27mhz_mode_condition(SCALER_DISP_CHANNEL Display);

unsigned char fw_video_detectmode_noScaler(unsigned char mode);

#ifdef __cplusplus
}
#endif

#endif // __SCALER_VIDEO_H__

