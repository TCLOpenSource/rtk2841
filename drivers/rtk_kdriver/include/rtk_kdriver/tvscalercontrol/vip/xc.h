/**
 * @file
 * 	This file is for color related functions.
 *
 * @author 	$Author$
 * @date 	$Date$
 * @version $Revision$
 */

/**
 * @addtogroup color
 * @{
 */

#ifndef _XC_H
#define _XC_H
/*============================ Module dependency  ===========================*/
/*#include "rtd_types.h"*/

/*===================================  Types ================================*/


typedef struct {

	unsigned char cp_temporal_xc_en;
	unsigned char cp_temporalenable;
	unsigned char cp_temporalthly;

} DRV_di_TNR_XC_CTRL;

typedef struct {

	unsigned char tnrxc_mkii_en;
	unsigned char tnrxc_mkii_thc1;
	unsigned char tnrxc_mkii_thc2;
	unsigned char tnrxc_mkii_thy;

} DRV_di_TNR_XC_MKII;

typedef struct {

	DRV_di_TNR_XC_CTRL di_TNR_XC_CTRL;
	DRV_di_TNR_XC_MKII di_TNR_XC_MKII;
} DRV_di_TNR_XC_table;




/*================================== Variables ==============================*/
/*================================ Definitions ==============================*/

/*================================== Function ===============================*/
/*============================================================================*/
/*
*set XC to initial state
*@param <Level> {Level control}
*/

/*============================================================================*/
/*
*set XC threshold for 3 level
*0:xc turn off		1:low	2:medium(default)		3:high
*@param <Level> {Level control}
*/


void drvif_color_auto_bal_init(unsigned char display, unsigned char flag_interlace);


void drvif_color_di_set_TNRXC_Ctrl(DRV_di_TNR_XC_CTRL *ptr);
void drvif_color_di_set_TNRXC_Mk2(DRV_di_TNR_XC_MKII *ptr);

/*======================== End of File =======================================*/

#endif
