/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for de-interlace IP control functions.
 *
 * @author	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	ip
 */

/**
 * @addtogroup ip
 * @{
 */

#ifndef _SCALER_IP_H
#define _SCALER_IP_H
/*======================== EXTERNAL DEPENDENCY ===============================*/
//#include <rtd_types.h>

/*======================== CONSTANTS =========================================*/

/*======================== MACROS ============================================*/

/*======================== TYPES =============================================*/

typedef enum
{
	IPTBL_COMMON = 0x00,	// Table of common
	IPTBL_AV,				// Table of AV
	IPTBL_SV,				// Table of SV
	IPTBL_TV				// Table of TV
}eIpTable;

typedef enum
{
	IPTYPE_NR = 0x00,	// IP type Noise-Reduction
	IPTYPE_DI = 0x01	// IP type De-Interlace
}eIpType;

typedef enum
{
	DITYPE_3A = 0x00,	// IP type Noise-Reduction
	DITYPE_5A = 0x01	// IP type De-Interlace
}eDIType;

// IP FIFO type
typedef enum
{
	IPFIFO_XC = 0x00,	// FIFO of False-Cross-Color
	IPFIFO_NR = 0x01,	// FIFO of Noise-Reduction
	IPFIFO_DI = 0x02	// FIFO of Deinterlacer-Motion
}eIpFifo;

/*======================== VARIABLES =========================================*/
//extern unsigned char tIP3DDeInterlaceSetting[];
/*======================== FUNCTIONS =========================================*/
/*============================================================================*/
/**
 * fw_scalerip_set_di
 * Set IP (video process) registers, includes its memory setting
 *
 * @param <info> { display-info struecture }
 * @return { none }
 *
 */
void ScalarIP_Enable(unsigned char value);
void fw_scalerip_set_di(void);
//void fw_scalerip_init(void); // hsliao 20081231, move to linux driver
void ScalerIP_SetTemporalNR(unsigned char display, unsigned char value);
void ScalerIP_SetMPEGNR(unsigned char display, unsigned char value);
void ScalerIP_SetDeinterlaceMode(unsigned char display, unsigned char mode);
void fw_scalerip_disable_ip(unsigned char display);
void set_di_doublebuf_write(unsigned char diflag,unsigned char _2d_flag);
unsigned char set_di_doublebuf_write_TV006(unsigned char diflag,unsigned char _2d_flag);

// [2D3D] VGIP2 through DI IP in 2D 3D conversion mode
//void fw_scalerip_set_di_for_2Dcvt3D(unsigned char diEnable, unsigned char rtnrEnable);
void fw_scalerip_disable_onlyip(UINT8 display);

void fw_scalerip_set_di_for_MaincvtSub(unsigned char diEnable, unsigned char rtnrEnable);

//Elsie 20140117
void fw_scalerip_set_DI_chroma_10bits(unsigned char isEnable);
unsigned char fw_scalerip_get_DI_chroma_10bits(void);
//void drvif_color_rtnr_progressive_check(unsigned char interlace_flag, unsigned char channel);
void fw_scalerip_set_di_gamemode_setting(unsigned char isEnable);
void fw_scalerip_set_di_gamemode(unsigned char isEnable);
unsigned char fw_scalerip_get_di_gamemode(void);
void check_di_buffer_mode(void);
void set_di_wait_frame_num(unsigned char num);//Set to need wait frame number
void wait_DI_ready(void);//wait DI buffer ready 
void sub_VGIP_sample_needDItiming(unsigned char bonoff);


#endif	// #define _SCALER_IP_H
/*======================== End of File =======================================*/

/**
  * @}
  */

