#include "rtk_ddc_drv.h"
#include "rtk_ddc_common.h"
#include <rtk_kdriver/rtk_ddc_lib.h>

extern srtk_ddc_chip* rtk_ddc_lib_get_chip_by_port(unsigned char id);


/*-------------------------------------------------------
 * Func : rtk_ddc_lib_enable
 *
 * Desc : enable a ddc hw 
 *
 * Para : id       : DDC port id
 *        enable   : 0: disabled, others : enabled
 *
 * Retn : 0 : success, others : failed
 -------------------------------------------------------*/
int rtk_ddc_lib_enable(unsigned char id, unsigned char enable)
{
    int ret  = 0;
    srtk_ddc_chip *p_ddc = rtk_ddc_lib_get_chip_by_port(id);

    if (p_ddc==NULL)
    {
        RTK_DDC_ERR("%s there is no ddc %d\n",__func__ , id);
        return -1;
    }
    
    ret = rtk_ddc_drv_enable_external_dev_access(p_ddc, enable);
    if (ret)
        RTK_DDC_ERR("fail to enable ddc %d for external device access\n", id);
        
    return ret;
}




/*-------------------------------------------------------
 * Func : rtk_ddc_lib_sync_reset
 *
 * Desc : reset a specified ddc HW
 *
 * Para : id : DDC port id 
 *
 * Retn : 0 : success, others : failed
 -------------------------------------------------------*/
int rtk_ddc_lib_sync_reset(unsigned char id)
{
    srtk_ddc_chip *p_ddc = rtk_ddc_lib_get_chip_by_port(id);

    if (p_ddc == NULL)
    {
        RTK_DDC_ERR("%s there is no ddc %d\n", __func__ , id);
        return -1;
    }
    
    rtk_ddc_drv_reset(p_ddc);
    return 0;
}


/*-------------------------------------------------------
 * Func : rtk_ddc_lib_crt_on
 *
 * Desc : enable clock of ddc 
 *
 * Para : N/A
 *
 * Retn : N/A
 -------------------------------------------------------*/
void rtk_ddc_lib_crt_on(void)
{    
    rtk_ddc_drv_crt_on();
}



/*-------------------------------------------------------
 * Func : rtk_ddc_lib_set_sda_delay
 *
 * Desc : set delay time of ddc
 *
 * Para : id : DDC port id
 *        delay : delay time
 *
 * Retn : 0 : success, others : failed
 -------------------------------------------------------*/
int rtk_ddc_lib_set_sda_delay(unsigned char id, unsigned char delay)
{
    srtk_ddc_chip *p_ddc = rtk_ddc_lib_get_chip_by_port(id);
    
    if (p_ddc==NULL)
    {
        RTK_DDC_ERR("%s there is no ddc %d\n", __func__ , id);
        return -1;        
    }
    
    p_ddc->read_delay = delay;
    
    return rtk_ddc_drv_set_read_delay(p_ddc);
}



/*-------------------------------------------------------
 * Func : rtk_ddc_lib_set_write_debounce
 *
 * Desc : set write debounce of a ddc driver 
 *
 * Para : id : DDC port id
 *        clock : debounde time
 *
 * Retn : 0 : success, others : failed
 -------------------------------------------------------*/
int rtk_ddc_lib_set_write_debounce(
    unsigned char           id, 
    unsigned char           clock
    )
{
    srtk_ddc_chip *p_ddc = rtk_ddc_lib_get_chip_by_port(id);
  
    if(p_ddc == NULL)
    {
        RTK_DDC_ERR("%s there is no ddc %d\n", __func__ , id);
        return -1;
    }
    
    p_ddc->write_debounce = (int)clock;
    rtk_ddc_drv_set_write_debounce(p_ddc);
    return 0;
}




/*-------------------------------------------------------
 * Func : rtk_ddc_lib_write_edid
 *
 * Desc : write edid table to specified ddc
 *
 * Para : id       : DDC port id
 *        edid_tbl : edid table to be written
 *        len      : size of edid table
 *
 * Retn : 0 : success, others : failed
 -------------------------------------------------------*/
int rtk_ddc_lib_write_edid(
    unsigned char           id,
    unsigned char*          edid_tbl, 
    unsigned int            len
    )
{
    int ret  = 0;
    srtk_edid edid;
    srtk_ddc_chip *p_ddc = NULL;
    
    if (NULL == edid_tbl)
    {
        RTK_DDC_ERR("%s invalid parameters, when read edid by rtk ddc lib\n" , 
__func__ );
        return -EINVAL;
    }

    p_ddc = rtk_ddc_lib_get_chip_by_port(id);
    
    if (p_ddc == NULL)
    {
        RTK_DDC_ERR("%s there is no ddc %d\n", __func__ , id);
        return -ENXIO;
    }
    
    edid.len = len;
    
    memcpy(edid.content, edid_tbl, len);
    
    ret = rtk_ddc_drv_write(p_ddc, &edid);
    
    if(ret)
    {
        RTK_DDC_ERR("%s fail to write DDC %d edid\n", __func__ , id);
        return -1;        
    }        
    
    return ret;
}



/*-------------------------------------------------------
 * Func : rtk_ddc_lib_read_edid
 *
 * Desc : read edid table from specified ddc
 *
 * Para : id       : DDC port id
 *        edid_tbl : edid output buffer
 *        len      : size of edid buffer
 *
 * Retn : 0 : success, others : failed
 -------------------------------------------------------*/
int rtk_ddc_lib_read_edid(
    unsigned char           id,
    unsigned char*          edid_tbl, 
    unsigned int            len
    )
{
    int ret  = 0;
    srtk_edid edid;
    srtk_ddc_chip *p_ddc = NULL;
    
    if (NULL == edid_tbl)
    {
        RTK_DDC_ERR("%s invalid parameters, when read edid by rtk ddc lib\n" , __func__ );
        return -EINVAL;
    }

    p_ddc = rtk_ddc_lib_get_chip_by_port(id);
    
    if (p_ddc==NULL)
    {
        RTK_DDC_ERR("%s there is no ddc %d\n", __func__ , id);
        return -ENXIO;
    }

    edid.len = len;
    ret = rtk_ddc_drv_read(p_ddc, &edid);
    
    if (ret)
    {
        RTK_DDC_ERR("%s fail to read edid of ddc %d\n", __func__ , id);
        return ret;
    }

    memcpy(edid_tbl,edid.content,len);
    return 0;
}

