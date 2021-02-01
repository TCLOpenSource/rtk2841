#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/init.h>
#include <linux/ioport.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/ioctl.h>
#include <linux/signal.h>
#include <linux/interrupt.h>
#include <linux/jiffies.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/freezer.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/gpio/driver.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-dev.h>
#include <rtk_kdriver/rtk_gpio-db.h>
#include <rtk_kdriver/rtk_gpio-attr.h>
#include <rtk_gpio-debug.h>
#include <mach/platform.h>

extern int bShowStrMessage;
extern Array RTK_GPIO_DB;

static RTK_GPIO_SETTING  rtk_gpio_setting =
{
    .gpio_type = MIS_GPIO,
    .gpio_num = 0,
};


int rtk_gpio_usb_dump(Array *RTK_GPIO_DB, char *buf)
{
    int i=0;
    int ret = 0;
    int retval = 0;
    int total = 0;
    
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    ret  = sprintf(buf,"%s","        USB GPIO DUMP                       \n");
    buf += ret;            
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
             
    for (i = 0; i< RTK_GPIO_DB->count ; ++i)
    {
        retval = rtk_gpio_value(RTK_GPIO_DB,i);

        if(strstr(RTK_GPIO_DB->item[i]->Name,"USB")!=NULL)
        {
            ret = sprintf(buf,"%s%-7dID:%-7dName:%-20s%-7s%-7sValue:%-7d\n",\
                                gpio_type(RTK_GPIO_DB->item[i]->Type),\
                                 RTK_GPIO_DB->item[i]->Number,\
                                 RTK_GPIO_DB->item[i]->Port,\
                                 RTK_GPIO_DB->item[i]->Name+strlen("GPIO_PORT_WR_"),\
                                (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",\
                                (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? "[X]":"[V]",\
                                (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? (-1):retval);
            buf    += ret;
            total++;
        }
    }
    
    ret = sprintf(buf,"Total:%d\n",total);
    buf    += ret;
    return ret;
}


int rtk_gpio_audio_dump(Array *RTK_GPIO_DB, char *buf)
{
    int i=0;
    int ret = 0;
    int retval = 0;
    int total = 0;
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    ret  = sprintf(buf,"%s","        AUDIO GPIO DUMP                       \n");
    buf += ret;
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    
    for (i = 0; i< RTK_GPIO_DB->count ; ++i)
    {
        retval = rtk_gpio_value(RTK_GPIO_DB,i);

        if (strstr(RTK_GPIO_DB->item[i]->Name,"AUDIO")!=NULL || 
            strstr(RTK_GPIO_DB->item[i]->Name,"AMP")!=NULL)
        {
            ret = sprintf(buf,"%s%-7dID:%-7dName:%-20s%-7s%-7sValue:%-7d\n",\
                    gpio_type(RTK_GPIO_DB->item[i]->Type),\
                     RTK_GPIO_DB->item[i]->Number,\
                     RTK_GPIO_DB->item[i]->Port,\
                     RTK_GPIO_DB->item[i]->Name+strlen("GPIO_PORT_WR_"),\
                    (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",\
                    (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? "[X]":"[V]",\
                    (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? (-1):retval);
            buf    += ret;
            total++;
        }
    }
    
    ret  = sprintf(buf,"Total:%d\n",total);
    buf += ret;
    return ret;
}



int rtk_gpio_misc_dump(Array *RTK_GPIO_DB, char *buf)
{
    int i=0;
    int ret = 0;
    int retval = 0;
    int total = 0;
    
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    ret  = sprintf(buf,"%s","        MISC GPIO DUMP                       \n");
    buf += ret;
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    
    for (i = 0; i< RTK_GPIO_DB->count ; ++i)
    {
        if (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE ||
            RTK_GPIO_DB->item[i]->Type == ISO_GPIO ||
            RTK_GPIO_DB->item[i]->Type == ISO_GPI ||
            RTK_GPIO_DB->item[i]->Type == ISO_GPO)
            continue;

        retval = rtk_gpio_value(RTK_GPIO_DB,i);

        ret = sprintf(buf,"%s%-7dID:%-7dName:%-20s%-7s%-7sValue:%-7d\n",\
                        gpio_type(RTK_GPIO_DB->item[i]->Type),\
                         RTK_GPIO_DB->item[i]->Number,\
                         RTK_GPIO_DB->item[i]->Port,\
                         RTK_GPIO_DB->item[i]->Name+strlen("GPIO_PORT_WR_"),\
                        (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",\
                        (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? "[X]":"[V]",\
                        (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? (-1):retval);
        buf    += ret;
        total++;
    }
    
    ret = sprintf(buf,"Total:%d\n",total);
    buf    += ret;
    return ret;
}


int rtk_gpio_iso_dump(Array *RTK_GPIO_DB, char *buf)
{
    int i=0;
    int ret = 0;
    int retval = 0;
    int total = 0;
    
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    ret  = sprintf(buf,"%s","        ISO GPIO DUMP                       \n");
    buf += ret;
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    
    for (i = 0; i< RTK_GPIO_DB->count ; ++i)
    {
        if (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE ||
            RTK_GPIO_DB->item[i]->Type == MIS_GPIO ||
            RTK_GPIO_DB->item[i]->Type == MIS_GPI ||
            RTK_GPIO_DB->item[i]->Type == MIS_GPO )
            continue;

        retval = rtk_gpio_value(RTK_GPIO_DB,i);

        ret = sprintf(buf,"%s%-7dID:%-7dName:%-20s%-7s%-7sValue:%-7d\n",\
                        gpio_type(RTK_GPIO_DB->item[i]->Type),\
                         RTK_GPIO_DB->item[i]->Number,\
                         RTK_GPIO_DB->item[i]->Port,\
                         RTK_GPIO_DB->item[i]->Name+strlen("GPIO_PORT_WR_"),\
                        (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",\
                        (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? "[X]":"[V]",\
                        (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? (-1):retval);
        buf += ret;
        total++;
    }
    
    ret = sprintf(buf,"Total:%d\n",total);
    buf    += ret;
    return ret;
}

int rtk_gpio_input_dump(Array *RTK_GPIO_DB, char *buf)
{
    int i=0;
    int ret = 0;
    int retval = 0;
    int total = 0;
    
    ret = sprintf(buf,"%s","********************************************\n");
    buf+= ret;
    ret = sprintf(buf,"%s","        INPUT GPIO DUMP                       \n");
    buf+= ret;
    ret = sprintf(buf,"%s","********************************************\n");
    buf+= ret;
    
    for (i = 0; i< RTK_GPIO_DB->count ; ++i)
    {
        if (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE || 
            RTK_GPIO_DB->item[i]->Usage == GPIO_ALLOW_WR)
            continue;
    
        retval = rtk_gpio_value(RTK_GPIO_DB,i);
    
        ret = sprintf(buf,"%s%-7dID:%-7dName:%-20s%-7s%-7sValue:%-7d\n",\
                        gpio_type(RTK_GPIO_DB->item[i]->Type),\
                         RTK_GPIO_DB->item[i]->Number,\
                         RTK_GPIO_DB->item[i]->Port,\
                         RTK_GPIO_DB->item[i]->Name+strlen("GPIO_PORT_WR_"),\
                        (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",\
                        (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? "[X]":"[V]",\
                        (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? (-1):retval);
        buf    += ret;
        total++;
    }
    ret  = sprintf(buf,"Total:%d\n",total);
    buf += ret;
    return ret;
}



int rtk_gpio_output_dump(Array *RTK_GPIO_DB, char *buf)
{
    int i=0;
    int ret = 0;
    int retval = 0;
    int total = 0;
    
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    ret  = sprintf(buf,"%s","        OUTPUT GPIO DUMP                    \n");
    buf += ret;
    ret  = sprintf(buf,"%s","********************************************\n");
    buf += ret;
    
    for (i = 0; i< RTK_GPIO_DB->count ; ++i)
    {
        if (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE || 
            RTK_GPIO_DB->item[i]->Usage == GPIO_ALLOW_RD)
            continue;
        
        retval = rtk_gpio_value(RTK_GPIO_DB,i);
        
        ret = sprintf(buf,"%s%-7dID:%-7dName:%-20s%-7s%-7sValue:%-7d\n",\
                    gpio_type(RTK_GPIO_DB->item[i]->Type),\
                     RTK_GPIO_DB->item[i]->Number,\
                     RTK_GPIO_DB->item[i]->Port,\
                     RTK_GPIO_DB->item[i]->Name+strlen("GPIO_PORT_WR_"),\
                    (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",\
                    (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? "[X]":"[V]",\
                    (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE) ? (-1):retval);
        buf += ret;
        total++;
    }
    ret  = sprintf(buf,"Total:%d\n",total);
    buf += ret;
    return ret;
}


int rtk_gpio_dump(Array *RTK_GPIO_DB, const char *cmd, char *buf)
{
    int i = 0;
    int ret = 0;
    int unused = 0;
    int retval = 0;
    int total = 0;

    if (strncmp(cmd, "name", 4) == 0)
    {
        ret  = sprintf(buf,"%s","==Used GPIO ==\n");
        buf += ret;
        
        for (i = 0; i< RTK_GPIO_DB->count ; ++i)
        {
            if(RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE)
                continue;
        
            ret  = sprintf(buf,"%s\n",RTK_GPIO_DB->item[i]->Name);
            buf += ret;
            total++;        
        }
    }
    else
    {

        for (i = 0; i< RTK_GPIO_DB->count ; ++i)
        {
            if(RTK_GPIO_DB->item[i]->Number == 0 && RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE)
            {
                if(strncmp(cmd, "alive", 5) == 0)
                    continue;

                unused = 1;
            }
            else
                unused = 0;

            retval = rtk_gpio_value(RTK_GPIO_DB,i);

            ret = sprintf(buf,"%s%-5dPort:%-5dName:%-16s%-5sStatus:%-8sValue:%-5d\n",
                            gpio_type(RTK_GPIO_DB->item[i]->Type),
                            RTK_GPIO_DB->item[i]->Number,
                            RTK_GPIO_DB->item[i]->Port,
                            RTK_GPIO_DB->item[i]->Name+13,
                            (RTK_GPIO_DB->item[i]->Usage) ? "[IN]":"[OUT]",
                            (unused) ? "invalid":"alive",
                            (unused) ? (-1) :retval);
            buf    += ret;            
            total++;
        }
    }
    
    ret  = sprintf(buf,"Total:%d\n",total);
    buf += ret;
    return ret;
}


ssize_t rtk_gpio_show_param(struct device *dev,
                            struct device_attribute *attr, char *buf)
{
    int ret = -1;
    char buf_info[4096] ={0};
    
    if (strncmp(attr->attr.name, "type", 4) == 0) 
    {
        ret = sprintf(buf, "%d\n", rtk_gpio_setting.gpio_type);    
    }
    else if (strncmp(attr->attr.name, "status", 6) == 0)
    {        
        ret = sprintf(buf, "%d\n", rtk_gpio_setting.gpio_num);    
    }
    else if (strncmp(attr->attr.name, "usb", 3) == 0) 
    {
        ret = rtk_gpio_usb_dump(&RTK_GPIO_DB,buf_info);
        return sprintf(buf, "%s\n", buf_info);    
    }
    else if (strncmp(attr->attr.name, "audio", 5) == 0) 
    {
        ret = rtk_gpio_audio_dump(&RTK_GPIO_DB,buf_info);    
        return sprintf(buf, "%s\n", buf_info);
    }
    else if (strncmp(attr->attr.name, "misc", 4) == 0) 
    {
        ret = rtk_gpio_misc_dump(&RTK_GPIO_DB,buf_info);  
        return sprintf(buf, "%s\n", buf_info);    
    }
    else if (strncmp(attr->attr.name, "iso", 3) == 0) 
    {
        ret = rtk_gpio_iso_dump(&RTK_GPIO_DB,buf_info);    
        return sprintf(buf, "%s\n", buf_info);
    
    }
    else if (strncmp(attr->attr.name, "input", 5) == 0) 
    {
        ret = rtk_gpio_input_dump(&RTK_GPIO_DB,buf_info);    
        return sprintf(buf, "%s\n", buf_info);    
    }
    else if (strncmp(attr->attr.name, "output", 6) == 0) 
    {
        ret = rtk_gpio_output_dump(&RTK_GPIO_DB,buf_info);    
        return sprintf(buf, "%s\n", buf_info);    
    }
    else if (strncmp(attr->attr.name, "dump", 4) == 0) 
    {
        int i;        
        
        for (i=0;i<RTK_GPIO_DB.count; ++i)
        {
            if (RTK_GPIO_DB.item[i]->Usage == GPIO_UNUSE)
            {
                RTK_GPIO_WARNING("%sPort:%-5dName:%-16s\n",
                                    "GPIO_UNUSE",
                                    RTK_GPIO_DB.item[i]->Port,
                                    RTK_GPIO_DB.item[i]->Name);
            }
            else
            {
                RTK_GPIO_WARNING("%s%-5dPort:%-5dName:%-16s\n",
                                gpio_type(RTK_GPIO_DB.item[i]->Type),
                                    RTK_GPIO_DB.item[i]->Number,
                                RTK_GPIO_DB.item[i]->Port,
                RTK_GPIO_DB.item[i]->Name);
            }
        }  
        return 0;    
    }
    else if (strncmp(attr->attr.name, "alive", 5) == 0) 
    {
        ret = rtk_gpio_dump(&RTK_GPIO_DB,"alive", buf_info);
        return sprintf(buf, "%s\n", buf_info);    
    }
    else if (strncmp(attr->attr.name, "name", 4) == 0) 
    {
        ret = rtk_gpio_dump(&RTK_GPIO_DB,"name",buf_info);    
        return sprintf(buf, "%s\n", buf_info);    
    }
    else  if (strncmp(attr->attr.name, "gpio", 6) == 0) 
    {
        if(rtk_gpio_setting.gpio_num > 0)
        {
            rtk_gpio_sort(&RTK_GPIO_DB,RTK_GPIO_DB.count,pin_compare);
            RTK_GPIO_DB.sort_type = SORT_PIN;
            rtk_gpio_find(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,buf_info);
            return sprintf(buf, "%s\n", buf_info);
        }
    }        
    return ret;
}

ssize_t rtk_gpio_store_param(struct device *dev,
                           struct device_attribute *attr,
                           const char *buf, size_t count)
{
    unsigned long val=0;
    int table_index = 0;
    int retval = 0;
    char cmd[6];
    char type[4];
    RTK_GPIO_ID gid;

    if (strncmp(attr->attr.name, "status", 6) == 0) 
    {
        sscanf(buf, "%d\n", &val);
        rtk_gpio_sort(&RTK_GPIO_DB,RTK_GPIO_DB.count,pin_compare);
        RTK_GPIO_DB.sort_type = SORT_PIN;
        rtk_gpio_setting.gpio_num = val;

        if (rtk_gpio_setting.gpio_type == MIS_GPIO)
        {
            RTK_GPIO_WARNING("MIS_GPIO\n");
            table_index = rtk_gpio_info(&RTK_GPIO_DB,val, MIS_GPIO);
        }
        else if (rtk_gpio_setting.gpio_type == ISO_GPIO)
        {
            RTK_GPIO_WARNING("ISO_GPIO\n");
            table_index = rtk_gpio_info(&RTK_GPIO_DB,val, ISO_GPIO);
        }
        else if (rtk_gpio_setting.gpio_type == RTK_GPIO_ALL)
        {
            RTK_GPIO_WARNING("RTK_GPIO_ALL\n");
            table_index = rtk_gpio_info(&RTK_GPIO_DB,val, RTK_GPIO_ALL);
        }

        if (table_index == (-1))
        {
            if (rtk_gpio_setting.gpio_type == MIS_GPIO || 
                rtk_gpio_setting.gpio_type == ISO_GPIO)
            {
                RTK_GPIO_WARNING("GPIO Type not match\n");
                table_index = rtk_gpio_info(&RTK_GPIO_DB,val,RTK_GPIO_ALL);
            }

            if (table_index != (-1))
            {
                if(rtk_gpio_direction(&RTK_GPIO_DB,table_index) == 0 ){
                    RTK_GPIO_WARNING("[GPIO][Direction: GPIO_ALLOW_WR]\n");
                }else if(rtk_gpio_direction(&RTK_GPIO_DB,table_index) == 1 ){
                    RTK_GPIO_WARNING("[GPIO][Direction: GPIO_ALLOW_RD]\n");
                }else if(rtk_gpio_direction(&RTK_GPIO_DB,table_index) == 2 ){
                    RTK_GPIO_WARNING("[GPIO][Direction: GPIO_UNUSE]\n");
                    return (-1);
                }
                
                RTK_GPIO_WARNING("[GPIO][Port Num: %d]\n", rtk_gpio_port(&RTK_GPIO_DB,table_index));
                RTK_GPIO_WARNING("[GPIO][Type: %s]\n",gpio_type(rtk_gpio_type(&RTK_GPIO_DB,table_index)));
                RTK_GPIO_WARNING("[GPIO][Pin_Num: %d]\n", rtk_gpio_pin_num(&RTK_GPIO_DB,table_index));
                RTK_GPIO_WARNING("[GPIO][Name: %s]\n", rtk_gpio_name(&RTK_GPIO_DB,table_index));
            }
            else
            {
                RTK_GPIO_WARNING("[GPIO] GPIO Num:%d is invalid\n",val);
            }
        }
        else
        {
            if(rtk_gpio_direction(&RTK_GPIO_DB,table_index) == 0 ){
                RTK_GPIO_WARNING("[GPIO][Direction: GPIO_ALLOW_WR]\n");
            }else if(rtk_gpio_direction(&RTK_GPIO_DB,table_index) == 1 ){
                RTK_GPIO_WARNING("[GPIO][Direction: GPIO_ALLOW_RD]\n");
            }else if(rtk_gpio_direction(&RTK_GPIO_DB,table_index) == 2 )
            {
                RTK_GPIO_WARNING("[GPIO][Direction: GPIO_UNUSE]\n");
                return (-1);
            }

            RTK_GPIO_WARNING("[GPIO][Port Num: %d]\n", rtk_gpio_port(&RTK_GPIO_DB,table_index));
            RTK_GPIO_WARNING("[GPIO][Type: %s]\n",gpio_type(rtk_gpio_type(&RTK_GPIO_DB,table_index)));
            RTK_GPIO_WARNING("[GPIO][Pin_Num: %d]\n", rtk_gpio_pin_num(&RTK_GPIO_DB,table_index));
            RTK_GPIO_WARNING("[GPIO][Name: %s]\n", rtk_gpio_name(&RTK_GPIO_DB,table_index));
        }
    }
    else  if (strncmp(attr->attr.name, "type", 4) == 0) 
    {
        rtk_gpio_sort(&RTK_GPIO_DB,RTK_GPIO_DB.count,pin_compare);
        RTK_GPIO_DB.sort_type = SORT_PIN;
        sscanf(buf,"%s",cmd);

        if(strncmp(cmd, "set", 3) == 0)
        {
            sscanf(buf,"%s%s%d%d",cmd,type,&rtk_gpio_setting.gpio_num,&val);
            if(strncmp(type, "mis", 3) == 0)
            {
                RTK_GPIO_WARNING("MIS_GPIO\n");
                rtk_gpio_setting.gpio_type = MIS_GPIO;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,MIS_GPIO);
            }
            else if(strncmp(type, "iso", 3) == 0)
            {
                RTK_GPIO_WARNING("ISO_GPIO\n");
                rtk_gpio_setting.gpio_type = ISO_GPIO;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,ISO_GPIO);
            }
            else if(strncmp(type, "go", 2) == 0)
            {
                RTK_GPIO_WARNING("MIS_GPO\n");
                rtk_gpio_setting.gpio_type = MIS_GPO;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,MIS_GPO);
            }
            else
            {
                RTK_GPIO_WARNING("[GPIO] Type Command is invalid\n");
                RTK_GPIO_WARNING("[GPIO] Type Format: <misc/iso>\n");
                RTK_GPIO_WARNING("[GPIO] Command Format: echo <set/get> <mis/iso> <num> <value>\n");
                return count;
            }

            if(table_index == (-1))
            {
                RTK_GPIO_WARNING("[GPIO] DB no this pin num:%d. Please check again\n",rtk_gpio_setting.gpio_num);
                return count;
            }
            else
            {
                if(val == GPIO_PIN_LOW || val == GPIO_PIN_HIGH)
                {
                    if(rtk_gpio_setting.gpio_type == MIS_GPO)
                    {
                        ;//Dont need set direction
                    }
                    else
                    {
                        gid = rtk_gpio_id((RTK_GPIO_GROUP) rtk_gpio_type(&RTK_GPIO_DB,table_index),
                                          rtk_gpio_pin_num(&RTK_GPIO_DB,table_index));
                                          
                        retval =  rtk_gpio_set_dir(gid, ((unsigned char)rtk_gpio_direction(&RTK_GPIO_DB,table_index)== GPIO_ALLOW_WR)?GPIO_OUTPUT:GPIO_INPUT);
                            
                        if (retval!=0)
                        {
                            RTK_GPIO_WARNING("[GPIO] Setting Direction fault!!\n");
                            return count;
                        }
                    }

                    retval =  rtk_gpio_output(gid, (unsigned char)val);
                    
                    if (retval !=0)
                    {
                        RTK_GPIO_WARNING("[GPIO] Setting Port number fault!!\n");
                        return count;
                    }

                    RTK_GPIO_WARNING("[GPIO][Port Num: %d]\n", rtk_gpio_port(&RTK_GPIO_DB,table_index));
                    RTK_GPIO_WARNING("[GPIO][Type: %s]\n",gpio_type(rtk_gpio_type(&RTK_GPIO_DB,table_index)));
                    RTK_GPIO_WARNING("[GPIO][Pin_Num: %d]\n", rtk_gpio_pin_num(&RTK_GPIO_DB,table_index));
                    RTK_GPIO_WARNING("[GPIO][Name: %s]\n", rtk_gpio_name(&RTK_GPIO_DB,table_index));
                    RTK_GPIO_WARNING("[GPIO][Direction:%d]\n",(rtk_gpio_direction(&RTK_GPIO_DB,table_index)== GPIO_ALLOW_WR?GPIO_OUTPUT:GPIO_INPUT));
                    RTK_GPIO_WARNING("[GPIO][Value: %d]\n", val);
                }
                else
                {
                    RTK_GPIO_WARNING("[GPIO] value is invalid\n");
                    RTK_GPIO_WARNING("[GPIO] VAlue Format: <1/0>\n");
                    RTK_GPIO_WARNING("[GPIO] Command Format: echo <set/get> <mis/iso> <num> <value>\n");
                    return count;
                }
            }
        }
        else if(strncmp(cmd, "get", 3) == 0)
        {
            sscanf(buf,"%s%s%d",cmd,type,&rtk_gpio_setting.gpio_num);
            RTK_GPIO_WARNING("[GPIO Type]:%s\n",type);
            RTK_GPIO_WARNING("[GPIO Pin number]:%d\n",rtk_gpio_setting.gpio_num);
            
            if (strncmp(type, "mis", 3) == 0)
            {
                RTK_GPIO_WARNING("MIS_GPIO\n");
                rtk_gpio_setting.gpio_type = MIS_GPIO;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,MIS_GPIO);
            }
            else if(strncmp(type, "iso", 3) == 0)
            {
                RTK_GPIO_WARNING("ISO_GPIO\n");
                rtk_gpio_setting.gpio_type = ISO_GPIO;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,ISO_GPIO);
            }
            else if(strncmp(type, "gi", 2) == 0)
            {
                RTK_GPIO_WARNING("ISO_GPI\n");
                rtk_gpio_setting.gpio_type = ISO_GPI;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,ISO_GPI);
            }
            else if(strncmp(type, "go", 2) == 0)
            {
                RTK_GPIO_WARNING("MIS_GPO\n");
                rtk_gpio_setting.gpio_type = MIS_GPO;
                table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,MIS_GPO);
            }
            else
            {
                RTK_GPIO_WARNING("[GPIO] Type Command is invalid\n");
                RTK_GPIO_WARNING("[GPIO] Type Format: <misc/iso>\n");
                RTK_GPIO_WARNING("[GPIO] Command Format: echo <set/get> <mis/iso> <num> <value>\n");
                return count;
            }

            if(table_index == (-1))
            {
                RTK_GPIO_WARNING("[GPIO] DB no this pin num:%d. Please check again\n",rtk_gpio_setting.gpio_num);
                return count;
            }
            else
            {
                gid = rtk_gpio_id( (RTK_GPIO_GROUP) rtk_gpio_type(&RTK_GPIO_DB,table_index),
                                                    rtk_gpio_pin_num(&RTK_GPIO_DB,table_index));
                
                if (rtk_gpio_direction(&RTK_GPIO_DB,table_index) == GPIO_ALLOW_WR)
                    retval = rtk_gpio_output_get(gid);
                else if (rtk_gpio_direction(&RTK_GPIO_DB,table_index) == GPIO_ALLOW_RD)
                    retval = rtk_gpio_input(gid);
                
                if (retval == (-EFAULT) )
                {
                    RTK_GPIO_WARNING("[GPIO] Setting Port number fault!!\n");
                    return count;
                }
                
                RTK_GPIO_WARNING("[GPIO][Port Num: %d]\n", rtk_gpio_port(&RTK_GPIO_DB,table_index));
                RTK_GPIO_WARNING("[GPIO][Type: %s]\n",gpio_type(rtk_gpio_type(&RTK_GPIO_DB,table_index)));
                RTK_GPIO_WARNING("[GPIO][Pin_Num: %d]\n", rtk_gpio_pin_num(&RTK_GPIO_DB,table_index));
                RTK_GPIO_WARNING("[GPIO][Name: %s]\n", rtk_gpio_name(&RTK_GPIO_DB,table_index));
                RTK_GPIO_WARNING("[GPIO][Read Value: %d]\n", retval);
            }
        }
        else if(strncmp(cmd, "enmsg", 5) == 0)
        {
            sscanf(buf,"%s%d",cmd,&bShowStrMessage);
            if(bShowStrMessage == Enable_MSG){
                RTK_GPIO_WARNING("[GPIO] Show STR Message Enable\n");
            }else{
                RTK_GPIO_WARNING("[GPIO] Show STR Message Disable\n");
            }
        }
        else if(strncmp(cmd, "test", 4) == 0)
        {
            printk("==> Test\n");
            sscanf(buf,"%s%d",cmd,&rtk_gpio_setting.gpio_num);
            table_index = rtk_gpio_info(&RTK_GPIO_DB,rtk_gpio_setting.gpio_num,MIS_GPIO);
            printk("==>table_index:%d\n",table_index);
            printk("==>RTK_GPIO_DB Name:%s\n",rtk_gpio_name(&RTK_GPIO_DB,table_index/*RTK_GPIO_DB.item[table_index]->Name*/));
        }
        else
        {
            RTK_GPIO_WARNING("GPIO Command is invalid\n");
            RTK_GPIO_WARNING("GPIO Command Format: echo <set/get> <mis/iso> <num> <value>\n");
        }
    }
    else  if (strncmp(attr->attr.name, "gpio", 6) == 0) 
    {
        sscanf(buf, "%d\n", &val);
        rtk_gpio_setting.gpio_num = val;
    }
    return count;
}


DEVICE_ATTR(status, S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(type,   S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(dump,   S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(alive,  S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(name,   S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(usb,    S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(audio,  S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(gpio,   S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(misc,   S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(iso,    S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(input,  S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);
DEVICE_ATTR(output, S_IWUSR | S_IWGRP | S_IRUGO, rtk_gpio_show_param, rtk_gpio_store_param);


int rtk_gpio_create_attr(struct device *device)
{
    device_create_file(device, &dev_attr_status);
    device_create_file(device, &dev_attr_type);
    device_create_file(device, &dev_attr_dump);
    device_create_file(device, &dev_attr_alive);
    device_create_file(device, &dev_attr_name);
    device_create_file(device, &dev_attr_usb);
    device_create_file(device, &dev_attr_audio);
    device_create_file(device, &dev_attr_gpio);
    device_create_file(device, &dev_attr_misc);
    device_create_file(device, &dev_attr_iso);
    device_create_file(device, &dev_attr_input);
    device_create_file(device, &dev_attr_output);
    return 0;
}

void rtk_gpio_remove_attr(struct device *device)
{
    device_remove_file(device, &dev_attr_status);
    device_remove_file(device, &dev_attr_type);
    device_remove_file(device, &dev_attr_dump);
    device_remove_file(device, &dev_attr_alive);
    device_remove_file(device, &dev_attr_name);
    device_remove_file(device, &dev_attr_usb);
    device_remove_file(device, &dev_attr_audio);
    device_remove_file(device, &dev_attr_gpio);
    device_remove_file(device, &dev_attr_misc);
    device_remove_file(device, &dev_attr_iso);
    device_remove_file(device, &dev_attr_input);
    device_remove_file(device, &dev_attr_output);
}

