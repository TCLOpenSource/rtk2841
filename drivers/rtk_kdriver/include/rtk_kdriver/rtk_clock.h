#ifndef __ARCH_ARM_RTK_CLOCK_H
#define __ARCH_ARM_RTK_CLOCK_H

#include <linux/cpufreq.h>
#include <linux/kref.h>
#include <linux/list.h>
#include <linux/platform_device.h>

#if (defined CONFIG_ARCH_RTK289X) //K3L

#if (defined CONFIG_CUSTOMER_TV001)
#define SCPU_FREQ_STEP0  700000
#define SCPU_FREQ_STEP1  850000
#define SCPU_FREQ_STEP2  1000000
#define SCPU_FREQ_STEP3  1150000
#define SCPU_VID1        33
#define SCPU_VID0        34
#define VID_GPIO_GROUP   ISO_GPIO
#elif (defined CONFIG_CUSTOMER_TV030)
#define SCPU_FREQ_STEP0  700000
#define SCPU_FREQ_STEP1  850000
#define SCPU_FREQ_STEP2  1000000
#define SCPU_FREQ_STEP3  1150000
#define SCPU_VID1        33
#define SCPU_VID0        34
#define VID_GPIO_GROUP   ISO_GPIO
#elif (defined CONFIG_CUSTOMER_TV006)
#define SCPU_FREQ_STEP0  700000
#define SCPU_FREQ_STEP1  850000
#define SCPU_FREQ_STEP2  1000000
#define SCPU_FREQ_STEP3  1050000
#define SCPU_FREQ_STEP4  1150000
#define SCPU_VID1        42
#define SCPU_VID0        40
#define VID_GPIO_GROUP   MIS_GPIO
#endif

#elif (defined CONFIG_ARCH_RTK284X) //S4
//IO is same 
#define SCPU_VID1        27
#define SCPU_VID0        27
//#define VID_GPIO_GROUP   MIS_GPIO
#define VID_GPIO_GROUP   ISO_GPIO
//Frequency maybe different
#if (defined CONFIG_CUSTOMER_TV006)
#define SCPU_FREQ_STEP0  700000
#define SCPU_FREQ_STEP1  800000
#define SCPU_FREQ_STEP2  900000
#define SCPU_FREQ_STEP3  1000000
#define SCPU_FREQ_STEP4  1100000
#else 
#define SCPU_FREQ_STEP0  700000
#define SCPU_FREQ_STEP1  800000
#define SCPU_FREQ_STEP2  850000
#define SCPU_FREQ_STEP3  900000
#ifdef CONFIG_ANDROID
#ifdef CONFIG_REALTEK_VOLTAGE_CTRL
#define SCPU_FREQ_STEP4  1500000
#else
#ifdef CONFIG_CUSTOMER_TV030
#define SCPU_FREQ_STEP4  900000
#else
#define SCPU_FREQ_STEP4  1100000
#endif
#endif
#else
#ifdef CONFIG_CUSTOMER_TV030
#define SCPU_FREQ_STEP4  900000
#else
#define SCPU_FREQ_STEP4  1100000
#endif
#endif
#endif

#endif
extern void (*cpu_wait) (void);

struct clk;

struct clk_ops {
	void (*init) (struct clk *clk);
	void (*enable) (struct clk *clk);
	void (*disable) (struct clk *clk);
	void (*recalc) (struct clk *clk);
	int (*set_rate) (struct clk *clk, unsigned long rate, int algo_id);
	long (*round_rate) (struct clk *clk, unsigned long rate);
};

struct clk {
	struct list_head node;
	const char *name;
	int id;
	struct module *owner;

	struct clk *parent;
	struct clk_ops *ops;

	struct kref kref;

	unsigned long rate;
	unsigned long flags;
};

#define CLK_ALWAYS_ENABLED	(1 << 0)
#define CLK_RATE_PROPAGATES	(1 << 1)

/* Should be defined by processor-specific code */
void arch_init_clk_ops(struct clk_ops **, int type);

int clk_init(void);

int __clk_enable(struct clk *);
void __clk_disable(struct clk *);

void clk_recalc_rate(struct clk *);

int clk_register(struct clk *);
void clk_unregister(struct clk *);

struct clk *__rtk_clk_get(struct device *dev, const char *id);
unsigned long __rtk_clk_get_rate(struct clk *clk);
int __rtk_clk_set_rate(struct clk *clk, unsigned long rate);
int __rtk_clk_set_rate_ex(struct clk *clk, unsigned long rate, int algo_id);
//long __rtk_clk_round_rate(struct clk *clk, unsigned long rate);

int __rtk_init_cpufreq_table(struct cpufreq_frequency_table **table);
void __rtk_free_cpufreq_table(struct cpufreq_frequency_table **table);
void rtk_set_voltage(int freq);
unsigned int rtk_get_boot_freq(void);
#endif				/* __ASM_MIPS_CLOCK_H */
