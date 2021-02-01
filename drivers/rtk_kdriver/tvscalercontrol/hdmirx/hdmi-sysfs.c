#include <linux/syscalls.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <mach/io.h>
#include <rtk_kdriver/tvscalercontrol/hdmirx/hdmifun.h>
#include <rtk_kdriver/tvscalercontrol/hdmirx/hdmi_arc.h>
#include "hdmiPlatform.h"
#include "hdmiInternal.h"


//===========================================================================
// Func : hdmi_attr_show
//===========================================================================
static ssize_t hdmi_show_status(
    struct device*              dev,
    struct device_attribute*    attr,
    char*                       buf
    )
{
    int  n;
    int  count = PAGE_SIZE;
    char *ptr = buf;
    unsigned char port = newbase_hdmi_get_current_display_port();
    unsigned char vido_state = newbase_hdmi_get_video_state(port);
    unsigned char audio_state = newbase_hdmi_audio_get_current_status();
    HDMI_TIMING_T timing;

    /*----------------------------------------------------
    HDMI STATUS
    Port Status : Current = 1, HPD Status = 1/0/0/0
    TMDS Status : TMDS STS=0xf8, OUT=0x8, CTL=0x8
    VIDEO FSM   : Wait Sync (0)
    AUDIO FSM   : Wait Sync (0)
    HDCP  Status: Enabled
    ------------------------------------------------------*/

    n = scnprintf(ptr, count, "---------------- HDMI STATUS --------------\n");
    ptr+=n; count-=n;

    //---------------------------------------
    // Port Status
    //---------------------------------------
    n = scnprintf(ptr, count, "Port Status : Current=%d, 5V_DET=%d.%d.%d.%d\n",
        port,
        newbase_hdmi_get_5v_state(0),
        newbase_hdmi_get_5v_state(1),
        newbase_hdmi_get_5v_state(2),
        newbase_hdmi_get_5v_state(3));
    ptr+=n; count-=n;

    //---------------------------------------
    // PHY Status
    //---------------------------------------
    n = scnprintf(ptr, count, "PHY Status : clock=%u, clock_stable=%d\n",
            newbase_rxphy_get_clk(port),
            newbase_rxphy_is_clk_stable(port));
    ptr+=n; count-=n;

    //---------------------------------------
    // TMDS Status
    //---------------------------------------
    n = scnprintf(ptr, count, "TMDS Status : TMDS STS=0xf8, OUT=0x8, CTL=0x8\n");
    ptr+=n; count-=n;

#if 0
    //---------------------------------------
    // BIT Error
    //---------------------------------------            
    if ((rtd_inl(0xb800d060) & 0x1)==0)
        rtd_outl(0xb800d060,0x00010103); //enable    
        
    n = scnprintf(ptr, count, "Bit Error : (R/G/B)=%u/%u/%u, TERC4(R/G/B)=%u/%u/%u\n",                                                 
            rtd_inl(0xb800d064) & 0xFFFF,
            rtd_inl(0xb800d068) & 0xFFFF,
            rtd_inl(0xb800d06c) & 0xFFFF,
            rtd_inl(0xb800d074) & 0xFFFF,
            rtd_inl(0xb800d078) & 0xFFFF,
            rtd_inl(0xb800d07c) & 0xFFFF);
            
    ptr+=n; count-=n;
#endif

    //---------------------------------------
    // Video FSM
    //---------------------------------------
    n = scnprintf(ptr, count, "VIDEO Status : FSM = %s (%d), OutEn=%d\n",
                  _hdmi_video_fsm_str(vido_state), vido_state,
                  lib_hdmi_is_video_output(port));
    ptr+=n; count-=n;

    if (newbase_hdmi_get_timing(port, &timing))
        n = scnprintf(ptr, count, "VIDEO Timing : h_total=%d, v_total=%d, h_act=%d, v_act=%d, h_freq=%d, v_freq=%d.%d, interlace=%d, color_space=%d(%s), color_depth=%d(%s), pixel_repeat=%x\n",
                timing.h_total, timing.v_total,
                timing.h_act_len, timing.v_act_len,
                (timing.h_freq * 100), timing.v_freq/10, timing.v_freq%10,
                timing.is_interlace,
                timing.colorspace, _hdmi_color_space_str(timing.colorspace),
                timing.colordepth, _hdmi_color_depth_str(timing.colordepth),
                timing.pixel_repeat);
    else
        n = scnprintf(ptr, count, "VIDEO Timing : N/A\n");

    ptr+=n; count-=n;

    //---------------------------------------
    // Audio FSM
    //---------------------------------------
    n = scnprintf(ptr, count, "AUDIO Status : FSM = %s (%d)\n",
                  _hdmi_audio_fsm_str(audio_state), audio_state);
    ptr+=n; count-=n;

    //---------------------------------------
    // Cotrol
    //---------------------------------------
    n = scnprintf(ptr, count, "AVMute Status : %s\n", lib_hdmi_get_avmute(port) ? "On" : "Off");
    ptr+=n; count-=n;
    
    //---------------------------------------
    // HDCP Status
    //---------------------------------------
    n = scnprintf(ptr, count, "HDCP Status: HDCP 1.4=%s\n",
                  (lib_hdmi_hdcp14_is_onoff(port)) ? "On" : "Off" );

    ptr+=n; count-=n;

    return ptr - buf;
}


static DEVICE_ATTR(status, 0444, hdmi_show_status, NULL);


//===========================================================================
// Func : hdmi_ddc_show
//===========================================================================

static ssize_t hdmi_attr_show_debug_ctrl(
    struct device*              dev,
    struct device_attribute*    attr,
    char*                       buf
    )
{
    int  n;
    int  count = PAGE_SIZE;
    char *ptr = buf;    
        
    if (strcmp(attr->attr.name, "debug_ctrl")==0)
    {         
        //---------------------------------------------------
        // bypass detect 
        //---------------------------------------------------
        n = scnprintf(ptr, count, "bypass_detect=%d\n", 
            (hdmi_in(DEBUG_REG_ADDR) & DEBUG_28_BYPASS_DETECT) ? 1 : 0);                  
        ptr+=n; count-=n;
        
        //---------------------------------------------------
        // bypass check 
        //---------------------------------------------------
        n = scnprintf(ptr, count, "bypass_check=%d\n", 
            (hdmi_in(DEBUG_REG_ADDR) & DEBUG_27_BYPASS_CHECK) ? 1 : 0);                  
        ptr+=n; count-=n;
        
        //---------------------------------------------------
        // force_6g
        //---------------------------------------------------
        n = scnprintf(ptr, count, "force_6g=%d\n", 
            (hdmi_in(DEBUG_REG_ADDR) & DEBUG_26_FORCE_6G) ? 1 : 0);                  
        ptr+=n; count-=n;
        
        //---------------------------------------------------
        // bit_err_det
        //---------------------------------------------------
        n = scnprintf(ptr, count, "bit_err_det=%d\n", 
            (hdmi_in(DEBUG_REG_ADDR) & DEBUG_25_BITERR_DET) ? 1 : 0);                  
        ptr+=n; count-=n;    
           
        //---------------------------------------------------
        // force no info pack
        //---------------------------------------------------
        n = scnprintf(ptr, count, "force_no_info_pack=%d\n", 
            (hdmi_in(DEBUG_REG_ADDR) & DEBUG_23_FORCE_NO_INFOPKT) ? 1 : 0);                  
        ptr+=n; count-=n;
        
        //---------------------------------------------------
        // dump_reg
        //---------------------------------------------------
        n = scnprintf(ptr, count, "dump_reg=%d\n", 
            (hdmi_in(DEBUG_REG_ADDR) & DEBUG_19_DUMP_REG) ? 1 : 0);                  
        ptr+=n; count-=n;
    }
    else if (strcmp(attr->attr.name, "arc_ctrl")==0)
    {    
        // ARC Channel
        n = scnprintf(ptr, count, "arc_spdif_channel=%d\n", hdmi_arc_get_spdif_channel());
        ptr+=n; count-=n;

        // ARC status
        n = scnprintf(ptr, count, "arc_spdif_out_en=%d\n", hdmi_arc_get_status());
        ptr+=n; count-=n;          
    }

    return ptr - buf;
}


static ssize_t hdmi_attr_store_debug_ctrl(struct device *dev,
                   struct device_attribute *attr,
                   const char *buf, size_t count)
{        
    int val;

    if (strcmp(attr->attr.name, "debug_ctrl")==0)
    {        
        if (sscanf(buf, "bypass_detect=%d", &val)==1)
        {
            if (val)
                hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) | DEBUG_28_BYPASS_DETECT);
            else                
		        hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) & ~DEBUG_28_BYPASS_DETECT);
        }
        else if (sscanf(buf, "bypass_check=%d", &val)==1)
        {
            if (val)
                hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) | DEBUG_27_BYPASS_CHECK);
            else                
		        hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) & ~DEBUG_27_BYPASS_CHECK);
        }
        else if (sscanf(buf, "force_6g=%d", &val)==1)
        {
            if (val)
                hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) | DEBUG_26_FORCE_6G);
            else                
		        hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) & ~DEBUG_26_FORCE_6G);
        } 
        else if (sscanf(buf, "bit_err_det=%d", &val)==1)
        {
            if (val)
                hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) | DEBUG_25_BITERR_DET);
            else                
		        hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) & ~DEBUG_25_BITERR_DET);
        }
        else if (sscanf(buf, "force_no_info_pack=%d", &val)==1)
        {
            if (val)
                hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) | DEBUG_23_FORCE_NO_INFOPKT);
            else                
		        hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) & ~DEBUG_23_FORCE_NO_INFOPKT);
        }
        else if (sscanf(buf, "dump_reg=%d", &val)==1)
        {
            if (val)
                hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) | DEBUG_19_DUMP_REG);
            else                
		        hdmi_out(DEBUG_REG_ADDR, hdmi_in(DEBUG_REG_ADDR) & ~DEBUG_19_DUMP_REG);
        }  
        else
        {            
            return -1;        
        }           
    }
    else if (strcmp(attr->attr.name, "arc_ctrl")==0)
    {    
        if (sscanf(buf, "arc_spdif_out_en=%d", &val)==1)        
            hdmi_arc_enable((val) ? 1 : 0);                                                
    }               
    else
    {
        return -1;
    }

    return count;
}

static DEVICE_ATTR(debug_ctrl, 0644, hdmi_attr_show_debug_ctrl, hdmi_attr_store_debug_ctrl);
static DEVICE_ATTR(arc_ctrl,  0644, hdmi_attr_show_debug_ctrl, hdmi_attr_store_debug_ctrl);


//===========================================================================
// Func : hdmi_ddc_show
//===========================================================================
static ssize_t hdmi_edid_status_show(
    struct device*              dev,
    struct device_attribute*    attr,
    char*                       buf
    )
{
    int port = 0;
    if (sscanf(attr->attr.name, "edid_%d", &port)!=1 || port >= HDMI_RX_PORT_MAX_NUM || port <0)
        return -EINVAL;

    newbase_hdmi_read_edid(port, buf, 256);
    return 256;
}


static ssize_t hdmi_edid_status_store(
    struct device*              dev,
    struct device_attribute*    attr,
    const char*                 buf, 
    size_t                      count
    )
{
    int port = 0;
    
    if (buf == NULL ||
        sscanf(attr->attr.name, "edid_%d", &port)!=1 || 
        port >= HDMI_RX_PORT_MAX_NUM || 
        port <0)
        return -EINVAL;

    newbase_hdmi_write_edid(port, (char*) buf, (count > 256) ? 256 : count);
    newbase_hdmi_save_edid(port, (char*) buf, (count > 256) ? 256 : count);  // store edid on specified edid port
    return count;
}

static DEVICE_ATTR(edid_0, 0644, hdmi_edid_status_show, hdmi_edid_status_store);
static DEVICE_ATTR(edid_1, 0644, hdmi_edid_status_show, hdmi_edid_status_store);
static DEVICE_ATTR(edid_2, 0644, hdmi_edid_status_show, hdmi_edid_status_store);



//////////////////////////////////////////////////////////////////////////////
// File Operations
//////////////////////////////////////////////////////////////////////////////

int hdmi_open(struct inode *inode, struct file *file)
{
    return 0;
}

int hdmi_release(struct inode *inode, struct file *file)
{
    return 0;
}



//////////////////////////////////////////////////////////////////////////////
// Module Init / Exit
//////////////////////////////////////////////////////////////////////////////

static struct file_operations hdmi_fops =
{
    .owner      = THIS_MODULE,
    .open       = hdmi_open,
    .release    = hdmi_release,
};

static struct miscdevice hdmi_miscdev =
{
    MISC_DYNAMIC_MINOR,
    "rtk_hdmi",
    &hdmi_fops
};

int __init hdmi_module_init(void)
{
    if (misc_register(&hdmi_miscdev))
    {
        pr_warning("hdmi_module_init failed - register misc device failed\n");
        return -ENODEV;
    }

    device_create_file(hdmi_miscdev.this_device, &dev_attr_status);
    device_create_file(hdmi_miscdev.this_device, &dev_attr_edid_0);
    device_create_file(hdmi_miscdev.this_device, &dev_attr_edid_1);
    device_create_file(hdmi_miscdev.this_device, &dev_attr_edid_2);
    device_create_file(hdmi_miscdev.this_device, &dev_attr_debug_ctrl);    
    device_create_file(hdmi_miscdev.this_device, &dev_attr_arc_ctrl);    

    return 0;
}

static void __exit hdmi_module_exit(void)
{
    device_remove_file(hdmi_miscdev.this_device, &dev_attr_status);
    device_remove_file(hdmi_miscdev.this_device, &dev_attr_edid_0);
    device_remove_file(hdmi_miscdev.this_device, &dev_attr_edid_1);
    device_remove_file(hdmi_miscdev.this_device, &dev_attr_edid_2);
    device_remove_file(hdmi_miscdev.this_device, &dev_attr_debug_ctrl);    
    device_remove_file(hdmi_miscdev.this_device, &dev_attr_arc_ctrl);
    misc_deregister(&hdmi_miscdev);
}

module_init(hdmi_module_init);
module_exit(hdmi_module_exit);
MODULE_LICENSE("GPL");
