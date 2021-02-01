#ifndef __RTK_LG_BOARD_H__
#define __RTK_LG_BOARD_H__

#ifdef CONFIG_REALTEK_PCBMGR
#include <mach/pcbMgr.h>
#endif


/*** LG K3L/K3Lp hw pcb LSADC configuartion pins  for country definition
*    using kernel booting parameters , extern bcas_info_t bcas = on/off
*    Bit0 level = Japan PCB.          enable smart card driver , disable pcmcia driver
*    Bit0 level = NON-Japan PCB.  enable pcmcia driver , disable    smart card driver
*
***/
enum{
	LG_COUNTRY_TW_COL_ATSC_US =  0 ,
	LG_COUNTRY_EU_ATSC_BR  = 1,
	LG_COUNTRY_CN_HK_ATSC_KR_SMC_JP = 2,
	LG_COUNTRY_AJJA_ATSC_CI  = 3,
};

 int getLgK2L_PcbCountry(void);
 int isPcbWithPcmcia(void);
 int isPcbWithSmc(void);

#endif /*__RTK_LG_BOARD_H__ */