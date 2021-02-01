
/*=============================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2009
  * All rights reserved.
  * ============================================ */

/*================= File Description ================= */
/**
 * @file
 * 	This file is for the main function and some initial functions.
 *
 * @author 	$Author: Jennifer $
 * @date 	$Date: 2009/11/19 03:26 $
 * @version 	$Revision: 0.1 $
 * @ingroup 	vdc
 */

/**
 * @addtogroup vdc
 * @{
 */
 /*
#include <rtd_types.h>
#include <Application/AppClass/MediaControl/Types/RtMediaTypes.h>//yy
*/
#include <linux/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AUDIO_HW_MAX_CMD_LENGTH 256

void drvif_module_audio_factory_debug_get_dma_prefix(char* prefix);	// Clayton

void xDumpAudioRawData(unsigned int Length); // Clayton

uint32_t drvif_module_audio_factory_TestDMA_Enable(unsigned int Length);	// Clayton

uint8_t drvif_module_get_audio_factory_TestDMA_mode_select(void);


/*======================== Type Defines =======================*/
typedef enum {
	DMA_ADC_SIF_DATA = 0,
	DMA_BTSC_BB_DATA = 1,
	DMA_A2_MAIN_DATA = 2,
	DMA_A2_SUB_DATA = 3,
	DMA_A2_PILOT_DATA = 4,
	DMA_NICAM_DEMOD_DATA = 5,
	DMA_IFD_SIF_DATA = 6 
}AUDIO_TEST_DMA_MODE_SEL;

typedef enum {
	AUDIO_HW_DBG_CMD_DUMP_SIF = 0,
	AUDIO_HW_DBG_CMD_NUMBER
} AUDIO_HW_DBG_CMD_INDEX_T;

void drvif_module_audio_factory_TestDMA_mode_select(AUDIO_TEST_DMA_MODE_SEL value); // Clayton
int audio_hw_dbg_EXECUTE(const int cmd_index, char **cmd_pointer);

#ifdef __cplusplus
}
#endif
