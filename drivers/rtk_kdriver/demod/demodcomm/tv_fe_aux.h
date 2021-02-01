/***************************************************************************************************
  File        : tv_fe_types.h
  Description : type definitions for TV Frontend Control
  Author      : Kevin Wang (kevin_wang@realtek.com.tw)
****************************************************************************************************
    Update List :
---------------------------------------------------------------------------------------------------- 
    1.0b    |   20080721    | Modify SEC_FILTER_PARAM - Add Complete & pContext fof Section Data Delivery
---------------------------------------------------------------------------------------------------- 
    2.0     |   20080804    | Modify Return Value of Section Complete callback
            |               |     return sec_data
***************************************************************************************************/

#include "rtk_tv_fe_types.h"
 
#ifndef __TV_FE_AUX_H__
#define __TV_FE_AUX_H__

#ifdef __cplusplus
extern "C" {
#endif 

unsigned char Snr2Str(unsigned long Snr);
unsigned char Ber2Quality(unsigned long ber);
const char* tv_sys_name(TV_SYSTEM sys);
const char* lnb_mode_str(LNB_MODE mode);
const char* tuner_mode_str(TV_OP_MODE mode);

int check_tv_ctrl_attribute(const char* name);
int read_tv_ctrl_attribute(const char* name, char* command, int len);
void clear_tv_ctrl_attribute(const char* name);

/////////////////////////////////////// DISEQC Command ////////////////////////////////////////////
#ifdef DISEQC_SUPPORT_EN
extern const char* diseqc_tone_mode_str(DISEQC_TONE_MODE mode);
#endif

#ifdef __cplusplus
}
#endif

#endif  //__TV_FE_AUX_H__
