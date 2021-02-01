#include <mach/pcbMgr.h>
#include <mach/rtk_log.h>
#include <mach/io.h>
#include <tvscalercontrol/hdmirx/hdmi_arc.h>
#include "hdmi_arc-priv.h"
#include "hdmi_debug.h"

static int g_arc_spdif_ch = 1;
#define ARC_SPDIF_INFO()  ((g_arc_spdif_ch >= RTK_SPDIF_COUNT) ? NULL : &g_spdif_cfg[g_arc_spdif_ch])


/*------------------------------------------------
 * Func  : Init HDMI ARC
 *
 * Desc  : Init HDMI ARC HW
 *
 * Param : N/A
 *
 * Retn  : 0 : successed, others : failed
 *-----------------------------------------------*/
int hdmi_arc_init(void)
{            
    unsigned int arc_state = ARC_DEFAULT_DONT_CARE;
    
#ifdef CONFIG_REALTEK_PCBMGR
    unsigned long long val = 0;    
    
    if (pcb_mgr_get_enum_info_byname("ARC_CFG", &val)==0)
    {                
        g_arc_spdif_ch = ARC_CFG_ARC_SPDIF_CHANNEL(val);
        arc_state = ARC_CFG_ARC_DEFAULT_STATE(val);                 
    }
    
#endif
    
    HDMI_EMG("ARC CFG: arc spdif channel=%d, defaul state = %d\n", 
            g_arc_spdif_ch, arc_state);
    
    if (g_arc_spdif_ch >= RTK_SPDIF_COUNT) 
    {
        HDMI_EMG("hdmi_arc_init failed, invalid ARC SPDIF channel - %d\n", g_arc_spdif_ch);
        BUG();
        return -1;
    }       
    
    switch(arc_state)
    {
    case ARC_DEFAULT_OFF:   return hdmi_arc_enable(0);        
    case ARC_DEFAULT_ON:    return hdmi_arc_enable(1);                
    case ARC_DEFAULT_DONT_CARE:             
        // do nothing, keep origional setting
        break;
    default:
        HDMI_EMG("hdmi_arc_init failed, invalid state - %d\n", arc_state);
        BUG();
        return -1;
    }
    
    return 0;
}



/*------------------------------------------------
 * Func  : hdmi_arc_enable
 *
 * Desc  : enable / disable ARC output
 *
 * Param : enable : enable/disable ARC out
 *            0 : disable
 *            others : enable
 *
 * Retn  : 0 : successed, others : failed
 *-----------------------------------------------*/
int hdmi_arc_enable(unsigned char en)
{            
    RTK_SPDIF_INFO* p_this = ARC_SPDIF_INFO();    
    unsigned int val;
    
    if (p_this==NULL) 
    {
        HDMI_EMG("hdmi_arc_enable failed, unable to get SPDIF info\n");
        return -1;
    }
        
    // set pinmux        
    val = rtd_inl(p_this->pad_mux_reg) & ~(p_this->pad_mux_mask);
    if (en)    
    {        
        val |= (p_this->pad_mux_val_spdif & p_this->pad_mux_mask);            // zap to spdif
    }
    else    
    {                        
        rtk_gpio_output(p_this->gid,  0);    // set gpio to output low
        rtk_gpio_set_dir(p_this->gid, 1);    // set gpio to output state
        
        val |= (p_this->pad_mux_val_gpio & p_this->pad_mux_mask);             // zap to gpio                
    }
            
    rtd_outl(p_this->pad_mux_reg, val);
        
    return 0;
}


/*------------------------------------------------
 * Func  : hdmi_arc_get_status
 *
 * Desc  : qurey arc status
 *
 * Param : N/A
 *
 * Retn  : 0 : disabled, 1 : enabled
 *-----------------------------------------------*/
int hdmi_arc_get_status(void)
{   
    RTK_SPDIF_INFO* p_this = ARC_SPDIF_INFO();    
    unsigned int val;
    
    if (p_this==NULL)
    {        
        HDMI_EMG("hdmi_is_arc_enable failed, unable to get SPDIF info\n");
        return 0;
    }
            
    val = rtd_inl(p_this->pad_mux_reg) & p_this->pad_mux_mask;
        
    return (val==p_this->pad_mux_val_spdif) ? 1 : 0;    
}



/*------------------------------------------------
 * Func  : hdmi_arc_get_spdif_channel
 *
 * Desc  : qurey arc spdif channel 
 *
 * Param : N/A
 *
 * Retn  : spdif channel
 *-----------------------------------------------*/
int hdmi_arc_get_spdif_channel(void)
{               
    return g_arc_spdif_ch;    
}


