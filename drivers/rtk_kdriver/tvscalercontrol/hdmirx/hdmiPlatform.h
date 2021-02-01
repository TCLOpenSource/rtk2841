#ifndef __HDMI_PLATFOM_H
#define __HDMI_PLATFOM_H


/**************************************************************************************/
//
//  Peace means having a bigger stick than the other guy.
//
//
//    --  Tony Stark, Iron Man (2008)
//
//
/**************************************************************************************/



#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/types.h>
#include <tvscalercontrol/io/ioregdrv.h>
#include <mach/rtk_log.h>



#ifdef __cplusplus
extern "C" {
#endif



/**********************************************************************************************
*
*	Marco or Definitions
*
**********************************************************************************************/

//------------------------------------------
// Definitions of Bits
//------------------------------------------
#define _ZERO                       0x00
#define _BIT0                       0x01
#define _BIT1                       0x02
#define _BIT2                       0x04
#define _BIT3                       0x08
#define _BIT4                       0x10
#define _BIT5                       0x20
#define _BIT6                       0x40
#define _BIT7                       0x80
#define _BIT8                       0x0100
#define _BIT9                       0x0200
#define _BIT10                      0x0400
#define _BIT11                      0x0800
#define _BIT12                      0x1000
#define _BIT13                      0x2000
#define _BIT14                      0x4000
#define _BIT15                      0x8000
#define _BIT16                      0x10000
#define _BIT17                      0x20000
#define _BIT18                      0x40000
#define _BIT19                      0x80000
#define _BIT20                      0x100000
#define _BIT21                      0x200000
#define _BIT22                      0x400000
#define _BIT23                      0x800000
#define _BIT24                      0x1000000
#define _BIT25                      0x2000000
#define _BIT26                      0x4000000
#define _BIT27                      0x8000000
#define _BIT28                      0x10000000
#define _BIT29                      0x20000000
#define _BIT30                      0x40000000
#define _BIT31                      0x80000000


// #define __init
#define hdmi_in(addr)					IoReg_Read32(addr)
#define hdmi_out(addr, value)				IoReg_Write32(addr, value)
#define hdmi_mask(addr, andmask, ormask) 		IoReg_Mask32(addr, andmask, ormask)
#define hdmiport_out(addr, value)                   	IoReg_Write32(addr, value)
#define hdmiport_mask(addr, andmask, ormask)		IoReg_Mask32(addr, andmask, ormask)
#define hdmiport_in(addr)				IoReg_Read32(addr)


#define HDMI_RX_DBG_EN
#define TAG_NAME_HDMI "HDMI"










#define GET_MODE_CURR()			(Scaler_DispGetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_MODE_CURR))
#define GET_MODE_POLARITY()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_POLARITY))
#define GET_MODE_IVTOTAL()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IVLEN))
#define GET_MODE_IHTOTAL()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHLEN))
#define GET_MODE_IVHEIGHT()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IVHEIGHT))
#define GET_MODE_IHWIDTH()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHWID))
#define GET_MODE_IVSTA()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IVSTARTPOS))
#define GET_MODE_IHSTA()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHSTARTPOS))
#define GET_MODE_IVFREQ()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IVFREQ))
#define GET_MODE_IHFREQ()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHFREQ))
#define GET_MODE_IVCOUNT()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IVCOUNT))
#define GET_MODE_IHCOUNT()			(Scaler_ModeGet_Hdmi_ModeInfo(SLR_MODE_IHCOUNT))

#define SET_MODE_CURR(x)			(Scaler_DispSetInputInfoByDisp((SCALER_DISP_CHANNEL)Scaler_DispGetInputInfo(SLR_INPUT_DISPLAY), SLR_INPUT_MODE_CURR, (x)))
#define SET_MODE_POLARITY(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_POLARITY,  (x)))
#define SET_MODE_IVTOTAL(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IVLEN, (x)))
#define SET_MODE_IHTOTAL(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IHLEN, (x)))
#define SET_MODE_IVHEIGHT(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IVHEIGHT, (x)))
#define SET_MODE_IHWIDTH(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IHWID, (x)))
#define SET_MODE_IVSTA(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IVSTARTPOS,(x)))
#define SET_MODE_IHSTA(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IHSTARTPOS, (x)))
#define SET_MODE_IVFREQ(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IVFREQ, (x)))
#define SET_MODE_IHFREQ(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IHFREQ, (x)))
#define SET_MODE_IVCOUNT(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IVCOUNT, (x)))
#define SET_MODE_IHCOUNT(x)			(Scaler_ModeSet_Hdmi_ModeInfo(SLR_MODE_IHCOUNT, (x)))

#define SET_SCALER_POLARITY(x)			{}
#define SET_SCALER_IVTOTAL(x)			{}
#define SET_SCALER_IHTOTAL(x)			{}
#define SET_SCALER_IVHEIGHT(x)			{}
#define SET_SCALER_IVHEIGHT_PRE(x)		{}
#define SET_SCALER_IHWIDTH(x)			{}
#define SET_SCALER_IHWIDTH_PRE(x)		{}
#define SET_SCALER_IVSTA(x)			{}
#define SET_SCALER_IVSTA_PRE(x)		{}
#define SET_SCALER_IHSTA(x)			{}
#define SET_SCALER_IHSTA_PRE(x)		{}
#define SET_SCALER_IVFREQ(x)			{}
#define SET_SCALER_IHFREQ(x)			{}
#define SET_SCALER_IVCOUNT(x)			{}
#define SET_SCALER_IHCOUNT(x)			{}
#define SET_SCALER_ISINTERLACE(x)		{}
#define SET_SCALER_IS422(x)			{}
#define SET_SCALER_COLORSPACE(x)		{}
#define SET_SCALER_COLORDEPTH(x)		{}
#define SET_SCALER_COLORIMEYRY(x)		{}


#define SCALERDRV_WAIT_VS()			WaitFor_IVS1()

#define HDMI_ISR_THREAD(on)			HdmiISREnable(on)
#define HDMI_INFOPKT_THREAD(on)		newbase_hdmi_infoframe_thread(on)
#define HDMI_AUDIO_THREAD(on)			newbase_hdmi_audio_thread(on)
#define HDMI_SMPHR_DETECT_INIT()		lib_hdmi_semaphore_detect_init()
#define HDMI_SMPHR_DETECT_GET()		lib_hdmi_get_semaphore_detect()
#define HDMI_SMPHR_INFOPKT_INIT()		lib_hdmi_semaphore_infopkt_init()
#define HDMI_SMPHR_INFOPKT_GET()		lib_hdmi_get_semaphore_infopkt()



#define HDMI_WQ_HPD_CREATE(q_func)		drvif_Hdmi_CreateHPDDelayWorkQueue(q_func)
#define HDMI_WQ_HPD_START(delayms)		drvif_Hdmi_startHPDDelayWorkQueue(delayms)
#define HDMI_WQ_HPD_CANCEL()			drvif_Hdmi_CancelHPDDelayWorkQueue()
#define HDMI_WQ_HPD_DESTROY()			drvif_Hdmi_DestroyHPDDelayWorkQueue()










/**********************************************************************************************
*
*	External Funtion Declarations
*
**********************************************************************************************/


extern void _HDMI_DELAY(unsigned int ms);
extern void hdmi_delayus(unsigned int us);


extern void HdmiISRInit(void);
extern void HdmiISREnable(char nEnable);
extern void newbase_hdmi_infoframe_thread(unsigned char create);
extern void newbase_hdmi_audio_thread(unsigned char create);


extern void lib_hdmi_semaphore_detect_init(void);
extern struct semaphore* lib_hdmi_get_semaphore_detect(void);
extern void lib_hdmi_semaphore_infopkt_init(void);
extern struct semaphore* lib_hdmi_get_semaphore_infopkt(void);


extern struct semaphore* get_offline_semaphore(void);


extern void drvif_Hdmi_CreateHPDDelayWorkQueue(void *work_queue_func);
extern int drvif_Hdmi_startHPDDelayWorkQueue(unsigned int delayms);
extern void drvif_Hdmi_CancelHPDDelayWorkQueue(void);
extern void drvif_Hdmi_DestroyHPDDelayWorkQueue(void);


#ifdef __cplusplus
}
#endif
#endif

