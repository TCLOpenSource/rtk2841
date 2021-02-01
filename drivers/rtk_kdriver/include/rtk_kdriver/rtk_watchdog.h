#ifndef __RTK_WATCHDOG_H__
#define __RTK_WATCHDOG_H__

#include <linux/watchdog.h>

typedef enum {
	DDR_SCAN_STATUS_SCPU = 0,
	DDR_SCAN_STATUS_ACPU1,
	DDR_SCAN_STATUS_ACPU2,
	DDR_SCAN_STATUS_VCPU1,
	DDR_SCAN_STATUS_VCPU2,
	DDR_SCAN_STATUS_KCPU,
	DDR_SCAN_STATUS_GPU,
	DDR_SCAN_STATUS_NUM,
} DDR_SCAN_STATUS_CPU_ENUM_T;

extern void DDR_scan_set_error(int cpu);

extern int rtk_watchdog_get_flag(void);
extern int watchdog_enable(unsigned char On);

struct wdog_dev {
        volatile int initialized;
        struct semaphore sem;     /* mutual exclusion semaphore     */
        struct cdev cdev;   /* Char device structure          */
};


#endif /* __RTK_WATCHDOG_H__ */
