#ifndef _HDMI_VFE_CONFIG_H_
#define _HDMI_VFE_CONFIG_H_

#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <pcbMgr.h>

enum hdmi_arc_status
{
       NONE_ARC_PORT = -1,
       MULTI_ARC_PORT = -2,
       UNKNOW_ARC_PORT = -3,
};

/**********************************************************************************************
*
*	External Funtion Declarations
*
**********************************************************************************************/

int hdmi_vfe_get_rx_port_info(unsigned char port, HDMI_CHANNEL_T_PCB_INFO* p_info);
int hdmi_vfe_get_hdmi_port(unsigned char ch, unsigned char* p_port);
int hdmi_vfe_get_hdmi_channel(unsigned char port, unsigned char* p_ch);
char hdmi_vfe_get_arc_channel(void);

#endif // _HDMI_VFE_CONFIG_H_
