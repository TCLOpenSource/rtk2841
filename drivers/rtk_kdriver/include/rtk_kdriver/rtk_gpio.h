#ifndef __RTK_GPIO_H__
#define __RTK_GPIO_H__
#include <mach/rtk_log.h>
#include <rtk_gpio-debug.h>

#include <mach/pcbMgr.h>

//////////////////////////////////////////////////////////////////////////////////////////////
// Chipset informations
//////////////////////////////////////////////////////////////////////////////////////////////
#define MIS_GPIO_CNT                    191
#define ISO_GPIO_CNT                    60
#define GPI_MIS_CNT                     0
#define GPI_ISO_CNT                     2
#define GPO_MIS_CNT                     0
#define GPO_ISO_CNT                     0
#define RTK_SUPPORT_ISO_GPI

#define MAX_PCB_GPIO_COUNT 64

#define GPIO_SUCCESS                 0
#define GPIO_FAIL                   -1
#define GPIO_PIN_UNDEFINED          -2
#define GPIO_TYPE_WRONG             -3

//////////////////////////////////////////////////////////////////////////////////////////////
// Data Structures
//////////////////////////////////////////////////////////////////////////////////////////////
#define RTK_GPIO_ID         unsigned int

typedef struct
{
    char name[32];
    char trigger_type;
    char irq_flag;
    void *dev_id;
    void    (*handler) (RTK_GPIO_ID id, unsigned char assert, void *data);   /* assert call back */
} RTK_GPIO_IRQ;

typedef enum
{
    ISO_GPIO = 0,
    MIS_GPIO,
    ISO_GPI,
    ISO_GPO,
    MIS_GPI,
    MIS_GPO,
} RTK_GPIO_GROUP;

typedef enum
{
    RTK_GPIO_DEBOUNCE_37ns = 0,
    RTK_GPIO_DEBOUNCE_1us,
    RTK_GPIO_DEBOUNCE_10us,
    RTK_GPIO_DEBOUNCE_100us,
    RTK_GPIO_DEBOUNCE_1ms,
    RTK_GPIO_DEBOUNCE_10ms,
    RTK_GPIO_DEBOUNCE_20ms,
    RTK_GPIO_DEBOUNCE_30ms,
} RTK_GPIO_DEBOUNCE;

typedef enum
{
    GPIO_LOW_ACTIVE      = 0,
    GPIO_HIGH_ACTIVE     = 1,
} RTK_GPIO_POLARITY;

typedef enum
{
    GPIO_RISING_EDGE     = 0,
    GPIO_FALLING_EDGE    = 1,
    GPIO_BOTH_EDGE       = 2,
} RTK_GPIO_TRIGGER;

typedef enum
{
    GPIO_ASSERT_INTERRUPT       = 0,
    GPIO_DISASSERT_INTERRUPT    = 1,
    GPIO_BOTH_INTERRUPT         = 2,
} RTK_GPIO_GLOBAL_INTSEL;

typedef struct
{
    unsigned int direction;
    unsigned int outputValue;
} RTK_GPIO_CONFIG;

typedef struct {
    char pin_name[32];
    unsigned char valid;
    unsigned char pin_type;
    unsigned char pin_index;
    unsigned char input_type;
    unsigned char invert;
    unsigned char init_value;
    unsigned int  gid;
    unsigned char gpio_type;
} RTK_GPIO_PCBINFO_T;


typedef struct {
    RTK_GPIO_PCBINFO_T pcblist[MAX_PCB_GPIO_COUNT];
    int pcbcnt;
} RTK_GPIO_PCB_T;

//////////////////////////////////////////////////////////////////////////////////////////////
// APIs
//////////////////////////////////////////////////////////////////////////////////////////////

#define rtk_gpio_id(group, idx)     (((group & 0x7) << 8) | (idx & 0xFF))
#define gpio_group(id)              ((id >> 8) & 0x7)
#define gpio_idx(id)                (id & 0xFF)

static inline char* gpio_type(int group)
{
    switch(group)
    {
    case ISO_GPIO:  return "ISO_GPIO";
    case MIS_GPIO:  return "MIS_GPIO";
    case ISO_GPI:   return "GPI_ISO";
    case ISO_GPO:   return "GPO_ISO";
    case MIS_GPI:   return "GPI_MIS";
    case MIS_GPO:   return "GPO_MIS";
    default:        return "unknow_GPIO";
    }
}

int rtk_gpio_set_dir(RTK_GPIO_ID gid, unsigned char out);

int rtk_gpio_get_dir(RTK_GPIO_ID gid);

int rtk_gpio_set_debounce(RTK_GPIO_ID gid, unsigned char val);

int rtk_gpio_input(RTK_GPIO_ID gid);

int rtk_gpio_output(RTK_GPIO_ID gid, unsigned char val);

int rtk_gpio_output_get(RTK_GPIO_ID gid );

int rtk_gpio_set_irq_polarity(RTK_GPIO_ID gid, unsigned char positive);

int rtk_gpio_set_irq_trigger_type(RTK_GPIO_ID gid, RTK_GPIO_TRIGGER type);

int rtk_gpio_set_irq_enable(RTK_GPIO_ID gid, unsigned char on);

int rtk_gpio_request_irq(RTK_GPIO_ID gid, void (*handler) (RTK_GPIO_ID gid, unsigned char assert, void *dev_id), char *name, void *dev_id);

void rtk_gpio_free_irq(RTK_GPIO_ID gid, void *dev_id);

int rtk_gpio_clear_isr(RTK_GPIO_ID gid);

int rtk_gpio_chk_irq_enable(RTK_GPIO_ID gid);

void rtk_gpio_lg_hal_int_isr(RTK_GPIO_ID gid, unsigned char assert, void* dev_id);

int rtk_gpio_get_irq_flag( RTK_GPIO_ID gid, unsigned char positive );

void rtk_gpio_rtk_int_isr(RTK_GPIO_ID gid, unsigned char assert, void* dev_id);

int rtk_gpio_get_irq_flag_ex( RTK_GPIO_ID gid, unsigned char trigger_type );

void rtk_gpio_init_pcb_pin(void);

int rtk_gpio_get_pcb_info(char* pinName,RTK_GPIO_PCBINFO_T*pInfo);

RTK_GPIO_ID rtk_gpio_get_gid_by_pintype(PCB_PIN_TYPE_T pin_type, unsigned char pin_index);

void rtk_gpio_syncInfo_toDB(void);

void rtk_gpio_get_all_pinInfo(RTK_GPIO_PCBINFO_T* pinInfolist,int *count);

#endif /*__RTK_GPIO_H__ */
