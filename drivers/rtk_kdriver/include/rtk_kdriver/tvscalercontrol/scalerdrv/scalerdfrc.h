/*==========================================================================
  * Copyright (c)      Realtek Semiconductor Corporation, 2006
  * All rights reserved.
  * ========================================================================*/

/*================= File Description =======================================*/
/**
 * @file
 * 	This file is for scaler clock related functions.
 *
 * @author 	$Author$
 * @date		$Date$
 * @version	$Revision$
 * @ingroup	clock
 */

/**
 * @addtogroup clock
 * @{
 */

#ifndef _SCALER_DFRC_H_
#define _SCALER_DFRC_H_

typedef enum  _COMPRESSION_MODE
{
       COMPRESSION_MODE_8_BITS = 0x8,
       COMPRESSION_MODE_12_BITS = 0xc,
       COMPRESSION_MODE_UNKNOW

}COMPRESSION_MODE;

typedef enum  _PIXEL_ENCODING
{
       PIXEL_ENCODE_444 = 0x0,
       PIXEL_ENCODE_422

}PIXEL_ENCODING;

typedef enum  _COLOR_DEPTH
{
       COLOR_DEPTH_6BITS = 0x0,
       COLOR_DEPTH_8BITS,
       COLOR_DEPTH_10BITS,
       COLOR_DEPTH_RESERVED,

}COLOR_DEPTH;

typedef enum  _D3DTG_MODE
{
	D3DTG_FRC_1X = 0,
	D3DTG_FRC_2X,
	D3DTG_FRC_4X,
	D3DTG_FRC_5X,
	D3DTG_FRC_8X,

}D3DTG_MODE;

typedef struct _SCALER_DFRC_PARAM
{
	unsigned char pixel_encoding;	//input Pixel encoding , 0 => 4:4:4 , 1 => 4:2:2
	unsigned char bit_sel; //Color depth select, 0 => 6 bits, 1 => 8 bits, 2 => 10 bits, 3 => Reserved
	COMPRESSION_MODE compression_bits;
						/*For example:  444, 10bit mode,  30 to 8 bit , compression*/
						/* pixel_encoding = 0, bit_sel = 2, compression_bits = 8*/
	//unsigned char	sfg_segment_num;
	unsigned char	pixel_mode;
	unsigned int dfrc_act_width;
	unsigned int dfrc_act_len;
	unsigned char sr_mode;	//(0:SR_H2_V2), (1:SR_H1_V2),(2:SR_H2_V1),(3:SR_BYPASS)
	unsigned char d3dtg_mode;
						/*Decide how many vsync will be add by d3dtg, 0: FRC 1x (1->1) bypass vsync , 1; FRC 2x (1->2) add 1 vsync ,
                                           2: FRC 4x (1->4) add 3 vsync, 3: FRC 5x (1->5) add 4 vsync, 4: FRC 8x (1->8) add 7 vsync*/
	unsigned char dfrc_enable;

}SCALER_DFRC_PARAM;


void drvif_scaler_set_dfrc(void);
void drvif_scaler_set_3ddtg(void);
void drvif_scaler_dfrc_init(SCALER_DFRC_PARAM* param);

void scaler_set_3ddtg(UINT8 bEnable);
void scaler_set_dfrc(void);
void scaler_load_dfrc_test_script();


#endif // #ifndef _SCALER_H_
/*======================== End of File =======================================*/
/**
*
* @}
*/

