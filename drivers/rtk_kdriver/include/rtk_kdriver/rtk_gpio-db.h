#ifndef __RTK_GPIO_DB_H__
#define __RTK_GPIO_DB_H__

#include <linux/types.h>
#include <rtk_kdriver/rtk_gpio.h>

#define RTK_GPIO_ALL        7           // this is going to be removed


typedef enum _tagSORTTYPE {
    SORT_PIN = 0,
    SORT_PORT = 1,
} SORTTYPE;

#define GPIOTYPE    RTK_GPIO_GROUP


typedef enum _tagGPIODIRECTION {
    GPIO_INPUT  = 0,
    GPIO_OUTPUT = 1,
} GPIODIR;


typedef enum _tagGPIOPOTENTIAL {
    GPIO_PIN_LOW  = 0,
    GPIO_PIN_HIGH = 1,
} GPIOPOT;

typedef struct
{
    u32          Port;   // GPIO_PORT_RD_MODEL_OPTION_9
    u32          Usage;  // GPIO_ALLOW_WR / GPIO_ALLOW_RD  / GPIO_UNUSE
    u32          Type;   // GPIO Type: _MIS_GPIO / _ISO_GPIO
    u32          Number; // Port Number
    char            Name[64];
}GPIO_MAP_ENTRY;

typedef struct {
    int size;
    int count;
    int sort_type;
    GPIO_MAP_ENTRY **item;
}Array;  

typedef struct _GPIO_DESC {
    short gpionum;
    GPIOTYPE type;
    GPIODIR dir;
    GPIOPOT pot;
} gpio_desc;

typedef struct _GPIO_NAME {
    char  gpioname[64]; 
    short portnum;
    short gpionum;
    GPIOTYPE type;
} gpio_name;

typedef enum _tagGPIOACTION{
    GPIO_PIN_INPUT    = 0,
    GPIO_PIN_OUTPUT   = 1,
}GPIOACTION;


enum
{
    GPIO_ALLOW_WR   = 0 ,
    GPIO_ALLOW_RD   = 1 ,
    GPIO_UNUSE  = 2 ,
};

///////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////////

extern void  rtk_gpio_array_new(Array *array, int size);
extern void  rtk_gpio_array_add(Array *array, GPIO_MAP_ENTRY *item);
extern void  set_gpio_table(char *board_str);
extern int   rtk_gpio_info(Array *RTK_GPIO_DB,int pin_num, int type);
extern int   rtk_gpio_info_by_port(Array *RTK_GPIO_DB,int port_num);
extern int   rtk_gpio_port_info(Array *RTK_GPIO_DB,int port_num);
extern int   rtk_gpio_port(Array *RTK_GPIO_DB,int Index);
extern int   rtk_gpio_direction(Array *RTK_GPIO_DB,int Index);
extern int   rtk_gpio_pin_num(Array *RTK_GPIO_DB,int Index);
extern int   rtk_gpio_type(Array *RTK_GPIO_DB,int Index);
extern char* rtk_gpio_name(Array *RTK_GPIO_DB,int Index);
extern int   pin_compare(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2);
extern int   port_compare(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2);
extern void  rtk_gpio_sort(Array *RTK_GPIO_DB, int size, int (*comp)(GPIO_MAP_ENTRY *elem1, GPIO_MAP_ENTRY *elem2));
extern int   rtk_gpio_find(Array *RTK_GPIO_DB, int num, char *buf);
extern int   rtk_gpio_value(Array *RTK_GPIO_DB,int index);

#endif /*__RTK_GPIO_DB_H__ */
