
/**************************************************************************************/
//
// I know I'm asking a lot. But the price of freedom is high.
// It always has been. And it's a price I'm willing to pay.
// And if I'm the only one, then so be it. But I'm willing to bet I'm not.
//
//	- Steve Rogers, Captain America II (2014)
//
/**************************************************************************************/






#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/semaphore.h>
#include <rtk_kdriver/rtk_semaphore.h>

#include <mach/io.h>
#include <mach/rtk_log.h>

#include <rbus/rbus_types.h>
#include <rbus/timer_reg.h>
#include <rbus/pll27x_reg_reg.h>  //audio clock for cbus

#include <rbus/mhl_p0_reg.h>
#include <rbus/mhl_p1_reg.h>
#include <rbus/mhl_p2_reg.h>

#include <rbus/cbus_pmm_reg.h>
#include <rbus/cbus_reg.h>

#include <rbus/sub_vgip_reg.h>
#include <rbus/vgip_reg.h>

#include <rbus/sys_reg_reg.h>
#include <rbus/dds_pll_reg.h>
#include <rbus/stb_reg.h>

//hdmiMs
#include <rbus/smartfit_reg.h>
#include <rbus/offms_reg.h>
#include <rbus/onms_reg.h>

//hdmi_ddc
#include <rbus/iso_misc_ddc1_reg.h>
#include <rbus/iso_misc_ddc2_reg.h>
#include <rbus/iso_misc_ddc3_reg.h>

#include <rbus/misc_ddc_reg.h>


#include <rtk_kdriver/rtk_crt.h>




#include <tvscalercontrol/hdmirx/hdmifun.h>
#include <tvscalercontrol/hdmirx/hdmi_reg.h>


#include "MHL_CDF.h"
#include <tvscalercontrol/hdmirx/mhl_cbus.h>

#include <rbus/ecbus_rx_dphy_reg.h>
#include <rbus/ecbus_rx_reg.h>
#include <rbus/efuse_reg.h>



// hdmiHdmi
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scaler/state.h>
#include <tvscalercontrol/scalerdrv/mode.h>
#include <rtk_kdriver/rtk_hdcp_otp_util.h>
#include <rbus/cec_reg.h>
#include "hdmi_debug.h"
#include "hdmiPlatform.h"
#include "hdmiInternal.h"


//hdmiMs.c
#if HDMI_MEASURE_I3DDMA_SMART_FIT
#include <tvscalercontrol/scalerdrv/scalerdrv.h> //CONFIG_FORCE_RUN_I3DDMA
#include <rbus/dma_vgip_reg.h>
#endif //#if HDMI_MEASURE_I3DDMA_SMART_FIT

//hdmiFun.c
#if defined(CONFIG_ENABLE_DOLBY_VISION_HDMI_AUTO_DETECT)|| defined(CONFIG_ENABLE_HDR10_HDMI_AUTO_DETECT)
#include <tvscalercontrol/scalerdrv/scaler_hdr_ctrl.h>
#endif


