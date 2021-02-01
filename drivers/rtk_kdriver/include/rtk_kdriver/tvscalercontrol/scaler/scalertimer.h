#ifndef __SCALER_TIMER_H__
#define __SCALER_TIMER_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>

/*===================================  Types ================================*/
/*================================== Variables ==============================*/
/*================================ Definitions ==============================*/
typedef unsigned char (*SLRTIMER_CALLBACK)(unsigned int , void*);

typedef enum _SLRTIMER_ID{
	SLRTIMER_PIPMP	= 1,
	SLRTIMER_VDC,
	SLRTIMER_MODESTATE_NOSIG,
	SLRTIMER_MODESTATE_NOSUPPORT,
	SLRTIMER_MODESTATE_NOCABLE,
	SLRTIMER_MAGICPICTURE,
	SLRTIMER_IFD_SW_DETECT,
	SLRTIMER_IFD_LOGGER,
	SLRTIMER_OPC_EVENT,
	SLRTIMER_COOCAA_HELPER_SLIDER,
	SLRTIMER_VGA_XTAL_ADJ,
	SLRTIMER_WEG_EVENT,
	SLRTIMER_DISABLE_OSD,
	SLRTIMER_AUTO_VIP_EVENT,
	SLRTIMER_AUTO_VIP_BRIGHTNESS_BOOST,
	SLRTIMER_AUTO_VIEW_EVENT,
	SLRTIMER_SELF_AWB_PEAK,//leochen
#if defined(TV032_1)||defined (TV014_1)||(defined TV014_2)
	SLRTIMER_RESTORE_MUTE_RELEASE,	//zhang_dc 2012.06.28 add.
#endif
#ifdef CONFIG_SOURCE_AUTO_SWITCH
	SLRTIMER_SOURCE_AUTO_SWITCH,
#endif
	SLRTIMER_LIGHT_SENSOR_DET,
	SLRTIMER_TEMPERATURE_DET,
#if defined (PQ_005_STYLE)
	SLRTIMER_Dynamic_CM_EVENT,//yuan 20130225
	SLRTIMER_Dynamic_CM_CRICKET_EVENT,//yuan 20130225  P2300::Cricket mode
#endif


	SLRTIMER_ID_MAX,
} SLRTIMER_ID;
/*================================== Function ===============================*/
/*============================================================================*/
/**
 * ScalerTimer_Initial
 * Initial scaler timer
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void ScalerTimer_Initial(void);

/*============================================================================*/
/**
 * ScalerTimer_DeInitial
 * DeInitial scaler timer
 *
 * @param <void>		{ void }
 * @return 			{ TRUE/FALSE }
 *
 */
unsigned char ScalerTimer_DeInitial(void);

/*============================================================================*/
/**
 * ScalerTimer_ActiveTimerEvent
 * Add new function into timer event
 *
 * @param <timerId>	{ timer ID }
 * @param <msTime>	{ timer count, the base is 1ms }
 * @param <Event>	{ function pointer to callback }
 * @return 			{ void }
 *
 */
void ScalerTimer_ActiveTimerEvent(SLRTIMER_ID timerId, unsigned int msTime, SLRTIMER_CALLBACK Event);

/**
 * ScalerTimer_ReactiveTimerEvent
 * Renew or add timer event
 *
 * @param <timerId>	{ timer ID }
 * @param <msTime>	{ timer count, the base is 1ms }
 * @param <Event>	{ function pointer to callback }
 * @return 			{ void }
 *
 */
void ScalerTimer_ReactiveTimerEvent(SLRTIMER_ID timerId, unsigned int msTime, SLRTIMER_CALLBACK Event);

/*============================================================================*/
/**
 * ScalerTimer_CancelTimerEvent
 * Cancel a timer event
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void ScalerTimer_CancelTimerEvent(SLRTIMER_ID timerId);

/*============================================================================*/
/**
 * ScalerTimer_CancelAllTimerEvent
 * Cancel all timer event in internal table
 *
 * @param <void>		{ void }
 * @return 			{ void }
 *
 */
void ScalerTimer_CancelAllTimerEvent(void);

#ifdef __cplusplus
}
#endif

#endif // __SCALER_TIMER_H__


