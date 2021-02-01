/**
 **
 */

#ifndef _RTK_LNBGPIO_REG_H_
#define _RTK_LNBGPIO_REG_H_

//#include "rbus/rbusTypes.h"


typedef struct _RTK_LNBGPIO {

	bool mapped;

	int index;
	int pinNumber;


	char nodename[16];

//	const rtk_lsdac_reg_map *reg;	/*hw phy address */

	struct device *lnbgpio_device_st;	/* PWM-I-x or PWM-M-x */

//	unsigned long long ullPcbMgrValue;

	int logical_0_high;
	int logical_0_low;
	int logical_1_high;
	int logical_1_low;

	unsigned char lnbgpioByte[8];

	int lnbLength ;


} t_RTK_LNBGPIO;


#endif


