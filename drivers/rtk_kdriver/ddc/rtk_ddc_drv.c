#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/delay.h>
#include <asm/io.h>
#include <rbus/iso_misc_ddc1_reg.h>
#include <rbus/iso_misc_ddc2_reg.h>
#include <rbus/iso_misc_ddc3_reg.h>
#include <rbus/misc_ddc_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/stb_reg.h>
#include "rtk_ddc_drv.h"
#include "rtk_ddc_dev.h"
#include "rtk_ddc_sysfs.h"
#include "rtk_ddc_common.h"
#include <rtk_kdriver/tvscalercontrol/hdmirx/hdmifun.h>


//DDC REG OFFSET
#define REG_EDID_CTL_OFFSET             0x0c
#define REG_DDC_SIR_OFFSET              0x20
#define REG_DDC_SAP_OFFSET              0x24
#define REG_DDC_SCR_OFFSET              0x2C
//STB REG OFFSET
#define REG_STB_SRST1_OFFSET            0x24
#define REG_STB_CLKEN1_OFFSET           0x34
//CRT RST REG OFFSET
#define REG_CRT_SYS_RST_RST0_OFFSET     0x00
#define REG_CRT_SYS_RST_RST1_OFFSET     0x04
#define REG_CRT_SYS_RST_RST3_OFFSET     0x0C
#define REG_CRT_SYS_RST_CLKEN0_OFFSET   0x10
#define REG_CRT_SYS_RST_CLKEN1_OFFSET   0x14
#define REG_CRT_SYS_RST_CLKEN3_OFFSET   0x1C

#define CONFIG_DDC_TOOL_DEBUG_MODE      1

int g_rtk_ddc_dbg = 1;

int rtk_ddc_drv_edid_content_is_valid(int content_len, const unsigned char* content)
{    
    if(NULL==content)
    {
        RTK_DDC_ERR("check edid content failed, content should not be NULL\n");
        return 0;
    }
    
    if ((128 != content_len) && (256 != content_len))
    {
        RTK_DDC_ERR("check edid content failed, content len should be ether 128 or 256\n");
        return 0;
    }        
    
    return 1;
}

static int rtk_ddc_drv_check_srtk_edid(srtk_edid* pedid)
{
    if(NULL == pedid)
    {
        RTK_DDC_ERR("input parameter is invalid in check srtk_edid\n");
        return -EINVAL;
    }
    if(pedid->len > ARRAY_SIZE(pedid->content)
            || (128 != pedid->len && 256 != pedid->len))
        return 0;
    return 1;
}

int rtk_ddc_drv_enable_external_dev_access(srtk_ddc_chip* pchip,int enable)
{
    if(NULL == pchip)
    {
        RTK_DDC_ERR("input parameter is invalid in read edid\n");
        return -EINVAL;
    }
    rtd_maskl((unsigned int)pchip->base+REG_EDID_CTL_OFFSET,~ISO_MISC_DDC1_EDID_CR_edid_en_mask, ISO_MISC_DDC1_EDID_CR_edid_en((enable!=0)));
    return 0;
}

int rtk_ddc_drv_crt_on(void)
{    
    rtd_outl(STB_ST_SRST1_reg, (STB_ST_SRST1_write_data_mask|STB_ST_SRST1_rstn_ddc1_mask|STB_ST_SRST1_rstn_ddc2_mask|STB_ST_SRST1_rstn_ddc3_mask|STB_ST_SRST1_rstn_ddc4_mask));
    rtd_outl(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_write_data_mask|STB_ST_CLKEN1_clken_ddc1_mask|STB_ST_CLKEN1_clken_ddc2_mask|STB_ST_CLKEN1_clken_ddc3_mask|STB_ST_CLKEN1_clken_ddc4_mask));

    rtd_outl(STB_ST_SRST1_reg, (STB_ST_SRST1_write_data_mask|STB_ST_SRST1_rstn_ddc_mask));
    rtd_outl(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_write_data_mask|STB_ST_CLKEN1_clken_ddc_mask));

#if MHL_SUPPORT
    rtd_outl(STB_ST_SRST1_reg, (STB_ST_SRST1_write_data_mask|STB_ST_SRST1_rstn_cbus_mask));
    rtd_outl(STB_ST_CLKEN1_reg, (STB_ST_CLKEN1_write_data_mask|STB_ST_CLKEN1_clken_cbus_mask));

    rtd_outl(SYS_REG_SYS_SRST3_reg, SYS_REG_SYS_SRST3_write_data_mask|SYS_REG_SYS_SRST3_rstn_ddc_mask);
    rtd_outl(SYS_REG_SYS_CLKEN3_reg, SYS_REG_SYS_CLKEN3_write_data_mask|SYS_REG_SYS_CLKEN3_clken_ddc_mask);
#endif
    return 0;
}

int rtk_ddc_drv_is_enable(srtk_ddc_chip* pchip)
{
    int enable = 0;
    if(NULL == pchip)
    {
        RTK_DDC_ERR("input parameter is invalid in is_enable\n");
        return -EINVAL;
    }
    enable = (rtd_inl((long unsigned int)(pchip->standby_base+REG_STB_SRST1_OFFSET)) & pchip->reset_mask) > 0?1:0;
    if(enable)
    {
        enable = (rtd_inl((long unsigned int)(pchip->standby_base+REG_STB_CLKEN1_OFFSET)) & pchip->clock_enable_mask) > 0?1:0;
        if(enable && DDC_MHL == pchip->ddc_type)
        {
            enable = (rtd_inl((unsigned int)pchip->reset_base + REG_CRT_SYS_RST_RST3_OFFSET) & SYS_REG_SYS_SRST3_rstn_ddc_mask)>0?1:0;
            if(enable)
            {
                enable = (rtd_inl((unsigned int)pchip->reset_base + REG_CRT_SYS_RST_CLKEN3_OFFSET) & SYS_REG_SYS_CLKEN3_clken_ddc_mask)>0?1:0;
            }
        }
    }

    return enable;
}

int rtk_ddc_drv_set_enable(srtk_ddc_chip* pchip, int enable)
{
    if(NULL == pchip)
    {
        RTK_DDC_ERR("input parameter is invalid in set enable\n");
        return -EINVAL;
    }

    if(enable)
    {
        if(DDC_MHL == pchip->ddc_type)
        {
            // enable cbus's reset & clock
            rtd_outl((unsigned int)pchip->reset_base + REG_CRT_SYS_RST_RST3_OFFSET,   SYS_REG_SYS_CLKEN3_write_data_mask|SYS_REG_SYS_SRST3_rstn_ddc_mask);
            rtd_outl((unsigned int)pchip->reset_base + REG_CRT_SYS_RST_CLKEN3_OFFSET, SYS_REG_SYS_SRST3_write_data_mask |SYS_REG_SYS_CLKEN3_clken_ddc_mask);
        }
        rtd_outl((unsigned int)pchip->standby_base + REG_STB_SRST1_OFFSET,  STB_ST_SRST1_write_data_mask| pchip->reset_mask);
        rtd_outl((unsigned int)pchip->standby_base + REG_STB_CLKEN1_OFFSET, STB_ST_CLKEN1_write_data_mask| pchip->clock_enable_mask);
        
        // restore delay & debounce setting of DDC
        rtk_ddc_drv_set_read_delay(pchip);
        rtk_ddc_drv_set_write_debounce(pchip);
    }
    else
    {        
        if(DDC_MHL == pchip->ddc_type)
        {
            // if enable cbus, it cause system crash.
            rtd_outl((unsigned int)pchip->reset_base + REG_CRT_SYS_RST_CLKEN3_OFFSET, SYS_REG_SYS_CLKEN3_clken_ddc_mask);
            rtd_outl((unsigned int)pchip->reset_base + REG_CRT_SYS_RST_RST3_OFFSET,   SYS_REG_SYS_SRST3_rstn_ddc_mask);
        }
        else
        {
            rtd_outl((unsigned long)pchip->standby_base + REG_STB_SRST1_OFFSET,  pchip->reset_mask);
            rtd_outl((unsigned long)pchip->standby_base + REG_STB_CLKEN1_OFFSET, pchip->clock_enable_mask);
        }
    }
    return 0;
}

int rtk_ddc_drv_set_read_delay(srtk_ddc_chip* pchip)
{
    if(NULL == pchip || pchip->read_delay < 0 || pchip->read_delay > 7)
    {
        RTK_DDC_ERR("input parameter is invalid in delay of read\n");
        return -EINVAL;
    }
    rtd_maskl((unsigned int)pchip->base+REG_DDC_SCR_OFFSET, ~ISO_MISC_DDC1_DDC_SCR_dataoutputdelay_sel_mask, ISO_MISC_DDC1_DDC_SCR_dataoutputdelay_sel(pchip->read_delay));
    return 0;
}

int rtk_ddc_drv_set_write_debounce(srtk_ddc_chip* pchip)
{
    if(NULL == pchip || pchip->write_debounce < 0 || pchip->write_debounce > 3)
    {
        RTK_DDC_ERR("input parameter is invalid in debounce of write\n");
        return -EINVAL;
    }
    rtd_maskl((unsigned int)pchip->base,~ISO_MISC_DDC1_I2C_CR_debounce_mode_mask,ISO_MISC_DDC1_I2C_CR_debounce_mode(pchip->write_debounce));
    return 0;
}

int rtk_ddc_drv_reset(srtk_ddc_chip* pchip)
{
    int ret = 0;
    if(NULL == pchip)
    {
        RTK_DDC_ERR("input parameter is invalid in reset\n");
        return -EINVAL;
    }
    rtk_ddc_drv_set_enable(pchip, 0);
    rtk_ddc_drv_set_enable(pchip, 1);
    return ret;
}

int rtk_ddc_drv_read(srtk_ddc_chip* pchip, srtk_edid* pedid)
{
    int ret = 0;
    int i   = 0;
    if(NULL == pchip || NULL == pedid || 0 == rtk_ddc_drv_check_srtk_edid(pedid))
    {
        RTK_DDC_ERR("input parameter is invalid in read edid\n");
        return -EINVAL;
    }
    ret = mutex_lock_interruptible(&pchip->rw_edid_mutex);
    {
        rtd_outl((unsigned int)pchip->base + REG_DDC_SIR_OFFSET, 0x0);
        for(i=0;i < pedid->len;i++)
        {
            pedid->content[i] = rtd_inl((long unsigned int)(pchip->base+REG_DDC_SAP_OFFSET));
        }
    }
    mutex_unlock(&pchip->rw_edid_mutex);
    return 0;
}

int rtk_ddc_drv_write(srtk_ddc_chip* pchip, srtk_edid* pedid)
{
    int i   = 0;
    int ret = 0;
    int channel_enble   = 0;

    if(NULL == pchip || NULL == pedid
            || 0 == rtk_ddc_drv_edid_content_is_valid(pedid->len,pedid->content))
    {
        RTK_DDC_ERR("input parameter is invalid in read edid\n");
        return -EINVAL;
    }

    ret = rtk_ddc_drv_set_enable(pchip,1);
    if(0!=ret)
    {
        RTK_DDC_ERR("fail to enable ddc(0x%08x), can not write edid.\n",(unsigned int)pchip->base);
        return ret;
    }
	
    channel_enble = ISO_MISC_DDC1_EDID_CR_get_edid_en(rtd_inl((unsigned int)pchip->base+REG_EDID_CTL_OFFSET));
    if(0 != rtk_ddc_drv_enable_external_dev_access(pchip, 0))
        RTK_DDC_ERR("id%d fail to switch to internal access\n",pchip->id);

    msleep(20); //this is for rbus timeout when ac cycle
    ret = mutex_lock_interruptible(&pchip->rw_edid_mutex);
    {
        rtd_outl((unsigned int)pchip->base+REG_DDC_SIR_OFFSET,0);
        for(i=0;i<pedid->len;i++)
            rtd_outl((unsigned int)pchip->base+REG_DDC_SAP_OFFSET,pedid->content[i]);
    }
    mutex_unlock(&pchip->rw_edid_mutex);

    if(0 != rtk_ddc_drv_enable_external_dev_access(pchip,channel_enble))
        RTK_DDC_ERR("id%d fail to switch to access right\n",pchip->id);

    return ret;
}

static int rtk_ddc_drv_allocate(struct platform_device* pdev,srtk_ddc_chip** ppchip)
{
    int ret = 0;
    struct resource *resource   = NULL;
    srtk_ddc_platform_data *platform_data = (srtk_ddc_platform_data *)pdev->dev.platform_data;
    if(RTK_DDC_MAX_NUM < pdev->id)
    {
        RTK_DDC_ERR("rtk ddc platform index is too large, it should be less than %d\n",RTK_DDC_MAX_NUM);
        return -EINVAL;
    }

    *ppchip = kzalloc(sizeof(**ppchip),GFP_KERNEL);
    if(NULL == (*ppchip))
    {
        RTK_DDC_ERR("fail to allocate rtk ddc chip\n");
        return -ENOMEM;
    }
    (*ppchip)->ddc_type = platform_data->ddc_type;
    (*ppchip)->write_debounce   = platform_data->write_debounce;
    (*ppchip)->read_delay       = platform_data->read_delay;
    (*ppchip)->clock_enable_mask= platform_data->clock_enable_mask;
    (*ppchip)->reset_mask       = platform_data->reset_mask;
    (*ppchip)->dev      = &pdev->dev;
    (*ppchip)->id       = pdev->id;
    mutex_init(&(*ppchip)->rw_edid_mutex);
    snprintf((*ppchip)->name,sizeof((*ppchip)->name),"%s.%d",pdev->name,(*ppchip)->id);

    //(*ppchip)->resource = platform_get_resource(pdev,IORESOURCE_MEM,0);
    (*ppchip)->resource = platform_get_resource_byname(pdev,IORESOURCE_MEM,RTK_RESOURCE_NAME_DDC);
    resource = (*ppchip)->resource;
    if(NULL == resource)
    {
        RTK_DDC_ERR("fail to get chip[%d] DDC resource\n",(*ppchip)->id);
        return -ENOENT;
    }

    // there is no ioremap function
    (*ppchip)->base    = resource->start;
    (*ppchip)->standby_resource = platform_get_resource_byname(pdev,IORESOURCE_MEM,RTK_RESOURCE_NAME_STB);
    resource = (*ppchip)->standby_resource;
    if(NULL == resource)
    {
        RTK_DDC_ERR("fail to get chip[%d] DDC resource\n",(*ppchip)->id);
        return -ENOENT;
    }
    // there is no ioremap function
    (*ppchip)->standby_base    = resource->start;

    (*ppchip)->reset_resource = platform_get_resource_byname(pdev,IORESOURCE_MEM,RTK_RESOURCE_NAME_SYS_RST);
    resource = (*ppchip)->reset_resource;

    if(NULL == resource)
    {
        RTK_DDC_ERR("fail to get chip[%d] DDC resource\n",(*ppchip)->id);
        return -ENOENT;
    }
    // there is no ioremap function
    (*ppchip)->reset_base    = resource->start;

    return ret;
}

static void rtk_ddc_drv_destroy(srtk_ddc_chip* pchip)
{
    if(NULL != pchip)
    {
        kfree(pchip);
        pchip = NULL;
    }
}

////////////////////////////////////////////////////////////////////////

typedef struct srtk_ddc_lib
{
    int             chip_num;
    srtk_ddc_chip*  chips[RTK_DDC_MAX_NUM];
}srtk_ddc_lib;

static srtk_ddc_lib *prtk_ddc_lib = NULL;


int rtk_ddc_lib_register(srtk_ddc_chip *pchip)
{
    int ret = 0;

    if(NULL == pchip || RTK_DDC_MAX_NUM <= pchip->id)
    {
        RTK_DDC_ERR("%s invalid parameters, when register rtk ddc lib\n" , __func__ );
        return -EINVAL;
    }
    prtk_ddc_lib->chips[pchip->id] = pchip;
    prtk_ddc_lib->chip_num++;
    return ret;
}

int rtk_ddc_lib_unregister(srtk_ddc_chip *pchip)
{
    if(NULL == pchip || RTK_DDC_MAX_NUM <= pchip->id)
    {
        RTK_DDC_ERR("%s invalid parameters, when unregister rtk ddc lib\n" , __func__ );
        return -EINVAL;
    }
    prtk_ddc_lib->chips[pchip->id] = NULL;
    return 0;
}

int rtk_ddc_lib_init(int numDev)
{
    int i = 0;
    if(RTK_DDC_MAX_NUM < numDev)
    {
        RTK_DDC_ERR("%s there are too many rtd ddc platform driver, it should less than %d\n", __func__ ,RTK_DDC_MAX_NUM);
        return -EINVAL;
    }
    prtk_ddc_lib = kzalloc(sizeof(*prtk_ddc_lib),GFP_KERNEL);
    if(!prtk_ddc_lib)
    {
        RTK_DDC_ERR("%s fail to allocate memory for rtk_ddc_lib, when register rtk ddc lib\n" , __func__ );
        return -ENOMEM;
    }

    prtk_ddc_lib->chip_num = 0;
    for(i=0;i<ARRAY_SIZE(prtk_ddc_lib->chips);i++)
    {
        prtk_ddc_lib->chips[i]   = NULL;
    }
    return 0;
}

int rtk_ddc_lib_remove(void)
{
    int i   = 0;
    if(prtk_ddc_lib)
    {
        for(i=0;i<ARRAY_SIZE(prtk_ddc_lib->chips);i++)
        {
            prtk_ddc_lib->chips[i]    = NULL;
        }
        prtk_ddc_lib->chip_num = 0;
        kfree(prtk_ddc_lib);
        prtk_ddc_lib = NULL;
    }
    return 0;
}



/*-------------------------------------------------------
 * Func : rtk_ddc_lib_get_chip_by_port
 *
 * Desc : get handle of ddc 
 *
 * Para : id : DDC port id
 *
 * Retn : NULL : failed
 *        others : handle of DDC
 -------------------------------------------------------*/
srtk_ddc_chip* rtk_ddc_lib_get_chip_by_port(unsigned char id)
{
    int i;
        
    for (i=0;i<ARRAY_SIZE(prtk_ddc_lib->chips);i++)
    {
        if (prtk_ddc_lib->chips[i] && prtk_ddc_lib->chips[i]->id == id)
            return prtk_ddc_lib->chips[i];
    }
    
    return NULL;
}

////////////////////////////////////////////////////////////////////////

static int rtk_ddc_platform_driver_probe(struct platform_device* pdev)
{
    int ret             = 0;
    srtk_ddc_chip* pchip = NULL;

    ret = rtk_ddc_drv_allocate(pdev,&pchip);
    if(ret)
    {
        RTK_DDC_ERR("fail to allocate rtk ddc chip\n");
        goto fail_allocate_ddc_drv;
    }
    platform_set_drvdata(pdev,pchip);

    rtk_ddc_drv_set_enable(pchip,1);
    rtk_ddc_drv_set_read_delay(pchip);
    rtk_ddc_drv_set_write_debounce(pchip);
    rtk_ddc_drv_enable_external_dev_access(pchip,1);

    ret = rtk_ddc_sysfs_create(pchip);
    if(ret)
        goto fail_create_ddc_sysfs;

    ret = rtk_ddc_lib_register(pchip);
    if(ret)
        goto  fail_register_ddc_lib;

    return ret;

fail_register_ddc_lib:
    rtk_ddc_sysfs_destroy(pchip);
fail_create_ddc_sysfs:
    platform_set_drvdata(pdev,NULL);
fail_allocate_ddc_drv:
    rtk_ddc_drv_destroy(pchip);
    return ret;
}

static int rtk_ddc_platform_driver_remove(struct platform_device* pdev)
{
    srtk_ddc_chip *pchip = platform_get_drvdata(pdev);
    rtk_ddc_sysfs_destroy(pchip);
    rtk_ddc_lib_unregister(pchip);
    platform_set_drvdata(pdev,NULL);
    rtk_ddc_drv_destroy(pchip);
    return 0;
}

static int rtk_ddc_platform_driver_suspend(struct platform_device *pdev, pm_message_t state){
    return 0;
}

static int rtk_ddc_platform_driver_resume(struct platform_device *pdev){
    return 0;
}

static struct platform_driver rtk_ddc_platform_driver =
{
    .probe      = rtk_ddc_platform_driver_probe,
    .remove     = rtk_ddc_platform_driver_remove,
    .suspend    = rtk_ddc_platform_driver_suspend,
    .resume     = rtk_ddc_platform_driver_resume,
    .driver     =
    {
        .name = RTK_DDC_NAME,
    },
};

static int rtk_ddc_platform_driver_exit(void)
{
    platform_driver_unregister(&rtk_ddc_platform_driver);
    rtk_ddc_lib_remove();
    return 0;
}


static int rtk_ddc_platform_driver_init(int numDev)
{
    int ret     = 0;
    ret = rtk_ddc_lib_init(numDev);
    if(ret)
    {
        RTK_DDC_ERR("init rtk ddc lib failed.\n");
        goto fail_init_ddc_lib;
    }

    ret = platform_driver_register(&rtk_ddc_platform_driver);
    if(ret)
    {
        RTK_DDC_ERR("platform_driver_register failed.\n");
        goto fail_register_ddc_platform_drv;
    }
    return ret;

fail_register_ddc_platform_drv:
fail_init_ddc_lib:
    rtk_ddc_lib_remove();
    return ret;
}

static int rtk_ddc_init(void)
{
    int ret     = 0;
    int numDev  = 0;
    if((ret = rtk_ddc_platform_device_init(&numDev)))
    {
        RTK_DDC_ERR("fail to init rtk ddc platform device!!\n");
        return ret;
    }

    if((ret = rtk_ddc_platform_driver_init(numDev)))
    {
        RTK_DDC_ERR("fail to init rtk ddc platform driver!!\n");
        goto fail_init_ddc_platform_drv;
    }

    return ret;
    
fail_init_ddc_platform_drv:
    rtk_ddc_platform_device_exit();
    return ret;
}

static void rtk_ddc_exit(void)
{
    rtk_ddc_platform_driver_exit();
    rtk_ddc_platform_device_exit();
}

module_init(rtk_ddc_init);
module_exit(rtk_ddc_exit);

MODULE_DESCRIPTION("Realtek DDC");
MODULE_AUTHOR("Roger Kan <roger.kan@realtek.com>");
MODULE_LICENSE("GPL");
