#ifndef _MHL_DRIVER_H_
#define _MHL_DRIVER_H_

#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <pcbMgr.h>

/**
 * unsigned char get_is_support_mhl_circuit(void)
 * @param [IN] none
 * @return 1 : mhl circuit; o : not mhl circuit
 *
 * it detect mhl signal
*/
int get_is_support_mhl_circuit(void);
/**
 * unsigned char get_mhl_signal(void)
 * @param [IN] none
 * @return 1 : mhl signal; o : not mhl signal
 *
 * it detect mhl signal
*/
int get_mhl_signal(void);

/**
 * void set_hdmi_mhl_sel(unsigned char high_low)
 * @param [IN] high_low, set high/low
 * @return none
 *
 * it set hdmi/mhl selection
*/
void set_hdmi_mhl_sel(unsigned char high_low);

unsigned char get_hdmirx_hotplug(unsigned char port);

/**
 * void set_hdmirx_hotplug(unsigned char port, unsigned char high_low)
 * @param [IN] port, hdmi port
 * @param [IN] high_low, set high/low
 * @return none
 *
 * it set hdmi hot plug
*/
void set_hdmirx_hotplug(unsigned char port, unsigned char high_low);


/**
 * int get_hdmi_rx_mhl_channel()
 *
 * @return mhl channel if define ofMHLCHANNEL  in bootcode
 *
 * it get hdmi port info id
*/
int get_hdmi_rx_mhl_channel(void);


#endif // _MHL_DRIVER_H_
