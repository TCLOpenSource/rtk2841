#ifndef __FELIBCUSTOM_H__
#define __FELIBCUSTOM_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <libs/frontend/felibAPI.h>

//*************************************************************
// ENUM
//*************************************************************
typedef enum _FEIF_DEV_TYPE {		//follow the fe_type_t in frontend.h
	FEIF_DEV_TERR_FRONTEND = 0x0,
	FEIF_DEV_SATE_FRONTEND,
	FEIF_DEV_CABLE_FRONTEND,
	FEIF_DEV_ANALOG_FRONTEND,
	FEIF_DEV_SMART_ANTENNA,
	FEIF_DEV_ANALOG_AUDIO_DC,
	FEIF_DEV_ANALOG_VIDEO_DC,
	FEIF_DEV_TYPE_MAX
} FEIF_DEV_TYPE;

//*************************************************************
// STRUCT
//*************************************************************
typedef struct _FEIF_CALLBACK
{
	unsigned char (*Open)(FEIF_DEV_TYPE);
	unsigned char (*Close)(FEIF_DEV_TYPE);
	int (*ProcessCmd)(FEIF_DEV_TYPE, unsigned int, void *);
	unsigned char isRegister;
} FEIF_CALLBACK;


/**
 * Set Custom Tuner to RTK Demod.
 * This API must be used after Fe_OpenDevHandler(FE_TVSRC_TYPE type).
 *
 * @param type: the selected source input and customTuner function.
 * @return value: -1 for error, 0 for success
 */
int Fe_RTDemodSetCustomTuner(FE_TVSRC_TYPE type, int (*customTuner)(unsigned long), unsigned long bandDividerLow, unsigned long bandDividerHigh, unsigned char stepSizeRatioTen);

/**
 * Register Custom Frontend Device (Demod and Tuner).
 * This API must be used after Fe_Init(void) and before Fe_OpenDevHandler(FE_TVSRC_TYPE type).
 *
 * @param type: the selected source input and FeDev functions.
 * @return value: FALSE for error, TRUE for success
 */
unsigned char Fe_RegisterCustomFeDev(FE_TVSRC_TYPE type, FEIF_CALLBACK dev);

/**
 * Register Custom Frontend Device (Demod and Tuner).
 * This API must be used before Fe_DeInit(void) and after Fe_CloseDevHandler(FE_TVSRC_TYPE type).
 *
 * @param type: the selected source input.
 * @return value: FALSE for error, TRUE for success
 */
unsigned char Fe_UnregisterCustomFeDev(FE_TVSRC_TYPE type);


#ifdef __cplusplus
}
#endif

#endif	//__FELIBCUSTOM_H__

