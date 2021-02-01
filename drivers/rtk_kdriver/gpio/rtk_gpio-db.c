#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <mach/platform.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rtk_kdriver/rtk_gpio-db.h>
#include <rtk_kdriver/rtk_gpio-dev.h>
#include <rtk_gpio-debug.h>

#include <linux/string.h>

MODULE_LICENSE("GPL");

int pin_compare(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2);
int port_compare(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2);

void rtk_gpio_array_new(Array *array, int size)
{
    int i = 0;
    array->count = 0;
    array->size = size;
    array->item = (GPIO_MAP_ENTRY**)kmalloc(array->size*sizeof(GPIO_MAP_ENTRY*),GFP_KERNEL);

    for( i = 0; i< array->size ; ++i)
        array->item[i] = (GPIO_MAP_ENTRY*)kzalloc(sizeof(GPIO_MAP_ENTRY),GFP_KERNEL);
}

void rtk_gpio_array_add(Array *array, GPIO_MAP_ENTRY *item)
{
    if (array->count < array->size)
        *array->item[array->count++] = *item;
}


void set_gpio_table(char *board_str)
{
}


//Find information with pin number
int rtk_gpio_info(Array *RTK_GPIO_DB,int pin_num,int type)
{
    int i = 0;
    for(i = 0; i < RTK_GPIO_DB->count ; ++i)
    {
        if (RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE)
            continue;

        if (type == RTK_GPIO_ALL)
        {
            if (RTK_GPIO_DB->item[i]->Number == pin_num)            
                return i;            
        }
        else
        {
            if (RTK_GPIO_DB->item[i]->Type == type && 
                RTK_GPIO_DB->item[i]->Number == pin_num)
                return i;            
        }
    }

    return (-1);
}

int rtk_gpio_info_by_port(Array *RTK_GPIO_DB,int port_num)
{
    int i = 0;
    
    for(i = 0; i < RTK_GPIO_DB->count ; ++i)
    {
        if( RTK_GPIO_DB->item[i]->Usage == GPIO_UNUSE)
            continue;
        
        if( RTK_GPIO_DB->item[i]->Port == port_num)        
            return i;        
    }
    
    return (-1);
}

int rtk_gpio_port(Array *RTK_GPIO_DB,int Index)
{
    if ( Index < 0 || Index > RTK_GPIO_DB->count)
    {
        RTK_GPIO_WARNING("%s GPIO Table Index invalid\n", "rtk_gpio_port");
        return 0;
    }

    return RTK_GPIO_DB->item[Index]->Port;            
}


int rtk_gpio_type(Array *RTK_GPIO_DB,int Index)
{
    if (Index < 0 || Index > RTK_GPIO_DB->count)
    {
        RTK_GPIO_WARNING("%s GPIO Table Index invalid\n", "rtk_gpio_type");
        return 0;
    }
    return RTK_GPIO_DB->item[Index]->Type;    
}


int rtk_gpio_direction(Array *RTK_GPIO_DB, int Index)
{
    if (Index < 0 || Index > RTK_GPIO_DB->count)
    {
        RTK_GPIO_WARNING("%s GPIO Table Index invalid\n","rtk_gpio_direction");
        return 0;
    }
    
    return RTK_GPIO_DB->item[Index]->Usage;
}

int rtk_gpio_pin_num(Array *RTK_GPIO_DB,int Index)
{
    if (Index < 0 || Index > RTK_GPIO_DB->count)
    {
        RTK_GPIO_WARNING("%s GPIO Table Index invalid\n","rtk_gpio_pin_num");
        return 0;
    }
    
    return RTK_GPIO_DB->item[Index]->Number;
}


char* rtk_gpio_name(Array *RTK_GPIO_DB,int Index)
{
    if (Index < 0 || Index > RTK_GPIO_DB->count)
    {
        RTK_GPIO_WARNING("%s GPIO Table Index invalid\n","rtk_gpio_name");
        return 0;
    }
    return RTK_GPIO_DB->item[Index]->Name;
}


void gpio_swap(Array *array,  int i, int j)
{
    GPIO_MAP_ENTRY *temp;
    temp = array->item[i];
    array->item[i] = array->item[j];
    array->item[j] = temp;
}


void  rtk_gpio_sort_recursive(Array *array, int start, int end, int (*comp)(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2))
{
    if(start >= end)
        return;

    int mid = end;
    int left = start;
    int right = end - 1;

    while(left < right) 
    {
        //  check right side
        while(comp(array->item[mid], array->item[left]) && left < right){
            //printf("Left:%d Port1:%d Port2:%d\n",left,array->item[mid]->Port,array->item[left]->Port);
            left++;
        }

        // check left side
        while (comp(array->item[right], array->item[mid]) && left < right){
            //printf("right:%d Port1:%d Port2:%d\n",right,array->item[mid]->Port,array->item[left]->Port);
            right--;
        }
        gpio_swap(array , left, right);
    }
    
    //exchangePin( &gpioMap[left], &gpioMap[j]);
    if (comp(array->item[left], array->item[end]))
        gpio_swap(array,left, end);
    else
        left++;

    rtk_gpio_sort_recursive(array, start, left-1, comp);   // check left side
    rtk_gpio_sort_recursive(array, left+1, end, comp);  // check right side
}


void rtk_gpio_sort(Array *RTK_GPIO_DB, int size, int (*comp)(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2))
{
    //printf("Test_sort==> comp:%x\n",comp);
     rtk_gpio_sort_recursive(RTK_GPIO_DB,0,size-1,comp);
}

int pin_compare(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2)
{
    if (elem1->Number < elem2->Number)
        return 1;
    else if ( elem1->Number > elem2->Number)
        return 0;
    else if (elem1->Number == elem2->Number && (elem1->Usage != GPIO_UNUSE) && (elem2->Usage == GPIO_UNUSE))
        return 0;
    else
        return 1;
}


int port_compare(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2)
{
    if (elem1->Port < elem2->Port)
        return 1;
    else
        return 0;
}

int rtk_gpio_value(Array *RTK_GPIO_DB,int index)
{
    int retval = 0;
    RTK_GPIO_ID gid;
    gid = rtk_gpio_id( (RTK_GPIO_GROUP) RTK_GPIO_DB->item[index]->Type,
                           RTK_GPIO_DB->item[index]->Number);

    if (RTK_GPIO_DB->item[index]->Usage == GPIO_ALLOW_WR)
        retval = rtk_gpio_output_get(gid);
    else if(RTK_GPIO_DB->item[index]->Usage == GPIO_ALLOW_RD)
        retval = rtk_gpio_input(gid);

    return retval;
}

int rtk_gpio_port_info(Array *RTK_GPIO_DB,int port_num)
{
    int min = 0;
    int mid = 0;
    int max = RTK_GPIO_DB->count-1 ;

    while(max >= min)
    {   
        // binary search to compare portIndex and get error pin name
        mid=(min+max)/2 ;
        
        if (port_num == RTK_GPIO_DB->item[mid]->Port )
        {
            if (RTK_GPIO_DB->item[mid]->Usage == GPIO_ALLOW_WR || 
                RTK_GPIO_DB->item[mid]->Usage == GPIO_ALLOW_RD )            
                return mid;
            
            RTK_GPIO_WARNING(" port_num=%d is not valid , port name=%s \n" ,
                    port_num , RTK_GPIO_DB->item[mid]->Name);
            return -1;             
        }
        else if( port_num >= RTK_GPIO_DB->item[mid]->Port )
        {
                max = mid-1 ; // comapre left
        }
        else
        {
                min = mid+1 ; // shift right
        }
    }
    RTK_GPIO_WARNING(" port_num=%d is not valid , port name=%s \n" ,
                        port_num , RTK_GPIO_DB->item[mid]->Name);
    return -1;
}


int rtk_gpio_find(Array *RTK_GPIO_DB,int pin_num,char *buf)
{
    int ret = 0;
    int len = 0;
    int retval = 0;
    RTK_GPIO_ID gid;
    SINT32 min = 0 ;
    SINT32 max = (RTK_GPIO_DB->count)-1;
    SINT32 mid = 0 ;
    SINT32 shift = 0;
    SINT32 pin_pos = 0;
    
    while(max >= min)
    {
        // binary search to compare portIndex and get error pin name
        mid=(min+max)/2;

        if(pin_num == RTK_GPIO_DB->item[mid]->Number)
        {
            retval = rtk_gpio_value(RTK_GPIO_DB,mid);
            
            ret = sprintf(buf,"%s%-5dID:%-5dName:%-16s%-5s%-8sValue:%-5d\n",\
                                        gpio_type(RTK_GPIO_DB->item[mid]->Type),\
                                        RTK_GPIO_DB->item[mid]->Number,\
                                        RTK_GPIO_DB->item[mid]->Port,\
                                        RTK_GPIO_DB->item[mid]->Name+strlen("GPIO_PORT_WR_"),\
                                        (RTK_GPIO_DB->item[mid]->Usage) ? "[IN]":"[OUT]",\
                                        "[V]",\
                                        retval);

            buf    += ret;
            len    += ret;
            shift = mid;
            
            while(pin_num == RTK_GPIO_DB->item[shift-1]->Number)
            {
                //ret = sprintf(buf,"PinNum:%d Name:%s max:%d min:%d\n",RTK_GPIO_DB->item[shift-1]->Number,RTK_GPIO_DB->item[shift-1]->Name,max,min);
                retval = rtk_gpio_value(RTK_GPIO_DB,shift-1);
                
                ret = sprintf(buf,"%s%-5dID:%-5dName:%-16s%-5s%-8sValue:%-5d\n",
                        gpio_type(RTK_GPIO_DB->item[shift-1]->Type),
                        RTK_GPIO_DB->item[shift-1]->Number,
                        RTK_GPIO_DB->item[shift-1]->Port,
                        RTK_GPIO_DB->item[shift-1]->Name+strlen("GPIO_PORT_WR_"),
                        (RTK_GPIO_DB->item[shift-1]->Usage) ? "[IN]":"[OUT]",
                        "[V]",
                        retval);
                        
                buf    += ret;
                len    += ret;
                shift--;
            }
            
            shift = mid;
            
            while(pin_num == RTK_GPIO_DB->item[shift+1]->Number)
            {            
                retval = rtk_gpio_value(RTK_GPIO_DB,shift+1);
                
                ret    = sprintf(buf,"%s%-5dID:%-5dName:%-16s%-5s%-8sValue:%-5d\n",
                            gpio_type(RTK_GPIO_DB->item[shift+1]->Type),
                            RTK_GPIO_DB->item[shift+1]->Number,
                            RTK_GPIO_DB->item[shift+1]->Port,
                            RTK_GPIO_DB->item[shift+1]->Name+strlen("GPIO_PORT_WR_"),
                            (RTK_GPIO_DB->item[shift+1]->Usage) ? "[IN]":"[OUT]",
                            "[V]",
                            retval);
                        
                buf += ret;
                len += ret;
                shift++;
            }
            break;
        }
        else if (pin_num <= RTK_GPIO_DB->item[mid]->Number)
        {            
            min = mid+1;
        }
        else
        {            
            max = mid-1;
        }
    }
    
    if (ret ==0)
        ret = sprintf(buf,"GPIO num:%d not found\n",pin_num);

    return ret;
}


EXPORT_SYMBOL(set_gpio_table);
EXPORT_SYMBOL(rtk_gpio_array_new);
EXPORT_SYMBOL(rtk_gpio_array_add);
EXPORT_SYMBOL(rtk_gpio_info);
EXPORT_SYMBOL(rtk_gpio_port_info);
EXPORT_SYMBOL(rtk_gpio_info_by_port);
EXPORT_SYMBOL(rtk_gpio_port);
EXPORT_SYMBOL(rtk_gpio_direction);
EXPORT_SYMBOL(rtk_gpio_pin_num);
EXPORT_SYMBOL(rtk_gpio_type);
EXPORT_SYMBOL(rtk_gpio_name);
EXPORT_SYMBOL(pin_compare);
EXPORT_SYMBOL(port_compare);
EXPORT_SYMBOL(rtk_gpio_sort);
EXPORT_SYMBOL(rtk_gpio_find);
