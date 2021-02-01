#ifndef __RTK_GPIO_DEV_H__
#define __RTK_GPIO_DEV_H__

#include <linux/kfifo.h>


#define UINT32 unsigned int
#define SINT32 signed int
typedef struct {
	unsigned int minor;
	wait_queue_head_t wq __attribute__ ((__aligned__(4)));
	struct kfifo fifo;
} RTK_GPIO_DEV_DATA;

#define FIFO_DEPTH      256

typedef struct {
    char  pin_name[32];
    unsigned char val ;
} RTK_GPIO_VAL_T ;

typedef struct {
    char  pin_name[32];
    unsigned char dir;
} RTK_GPIO_DIR_T ;

typedef struct {
    char  pin_name[32];
    unsigned char  irq_en;
    unsigned char  debounce;
    unsigned char  edge_type;
} RTK_GPIO_IRQ_SET_T ;

typedef struct {
    char  pin_name[32];
    unsigned char irq_en;
} RTK_GPIO_IRQ_EN_T ;

typedef struct {
    char  pin_name[32];
    unsigned char trigger_type;
    unsigned char irq_flag;
} RTK_GPIO_IRQ_FLAG_T ;

typedef struct {
    RTK_GPIO_PCBINFO_T  pinInfo[32];
    unsigned char count;
} RTK_GPIO_GET_ALL_GPIO_PIN_T ;

/* IOCTL Command Definitions */
#define RTK_GPIO_IOC_MAGIC			'r'

#define RTK_GPIO_SET_VAL                _IOW(RTK_GPIO_IOC_MAGIC, 0, RTK_GPIO_VAL_T)
#define RTK_GPIO_GET_VAL                _IOR(RTK_GPIO_IOC_MAGIC, 1, RTK_GPIO_VAL_T)
#define RTK_GPIO_SET_DIR                _IOW(RTK_GPIO_IOC_MAGIC, 2, RTK_GPIO_DIR_T)
#define RTK_GPIO_GET_DIR                _IOR(RTK_GPIO_IOC_MAGIC, 3, RTK_GPIO_DIR_T)
#define RTK_GPIO_SET_IRQ                _IOW(RTK_GPIO_IOC_MAGIC, 4, RTK_GPIO_IRQ_SET_T)
#define RTK_GPIO_SET_IRQ_EN             _IOW(RTK_GPIO_IOC_MAGIC, 5, RTK_GPIO_IRQ_EN_T)
#define RTK_GPIO_GET_IRQ_FLAG           _IOR(RTK_GPIO_IOC_MAGIC, 6, RTK_GPIO_IRQ_FLAG_T)
#define RTK_GPIO_GET_ALL_GPIO_PIN       _IOR(RTK_GPIO_IOC_MAGIC, 7, RTK_GPIO_GET_ALL_GPIO_PIN_T)


#define RTK_GPIO_IOC_MAXNR  8


#define CHIP_ID_REG		(0xB8060000)



#endif /* __RTK_GPIO_DEV_H__ */
