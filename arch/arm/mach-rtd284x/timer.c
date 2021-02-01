/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 * Time initialization.
 */

#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/clockchips.h>
#include <linux/clocksource.h>
#include <asm/io.h>
#include <asm/mach/time.h>
#include <linux/of.h>
#include <linux/sched_clock.h>
#include <mach/timex.h>
#include <mach/io.h>
#include <mach/irqs.h>
#include <rbus/timer_reg.h>

#ifdef CONFIG_ARM_ARCH_TIMER
#include <asm/arch_timer.h>

#define WRAP_A7_APB_TSG_EN0                                                          0xB805C800
#define WRAP_A7_APB_TSG_EN1                                                          0xB805C804
#endif

#ifdef CONFIG_REALTEK_SCHED_LOG
unsigned int sched_log_time_scale;
#endif // CONFIG_REALTEK_SCHED_LOG

extern int rtk_clocksource_init(void);

struct clock_event_device rtk_clock_event;
static u64 clock_offset = 0;

struct timer_reg sys_timer[MAX_HWTIMER_NUM] = {
{TIMER_TC0TVR_reg, TIMER_TC0CVR_reg, TIMER_TC0CR_reg, TIMER_TC0ICR_reg, TIMER_UMSK_ISR_tc0_int_shift},
{TIMER_TC1TVR_reg, TIMER_TC1CVR_reg, TIMER_TC1CR_reg, TIMER_TC1ICR_reg, TIMER_UMSK_ISR_tc1_int_shift},
{TIMER_TC2TVR_reg, TIMER_TC2CVR_reg, TIMER_TC2CR_reg, TIMER_TC2ICR_reg, TIMER_UMSK_ISR_tc2_int_shift},
{TIMER_TC3TVR_reg, TIMER_TC3CVR_reg, TIMER_TC3CR_reg, TIMER_TC3ICR_reg, TIMER_UMSK_ISR_tc3_int_shift},
{TIMER_TC4TVR_reg, TIMER_TC4CVR_reg, TIMER_TC4CR_reg, TIMER_TC4ICR_reg, TIMER_UMSK_ISR_tc4_int_shift},
{TIMER_TC5TVR_reg, TIMER_TC5CVR_reg, TIMER_TC5CR_reg, TIMER_TC5ICR_reg, TIMER_UMSK_ISR_tc5_int_shift},
{TIMER_TC6TVR_reg, TIMER_TC6CVR_reg, TIMER_TC6CR_reg, TIMER_TC6ICR_reg, TIMER_UMSK_ISR_tc6_int_shift},
{TIMER_TC7TVR_reg, TIMER_TC7CVR_reg, TIMER_TC7CR_reg, TIMER_TC7ICR_reg, TIMER_UMSK_ISR_tc7_int_shift},
};

static void clear_irq_reason(unsigned int id)
{
    unsigned int reg_tmp;
    reg_tmp = rtd_inl(TIMER_ISR_reg);
    reg_tmp |= (1<<id);
 //   rtd_outl(TIMER_ISR_reg,reg_tmp);
    rtd_outl(TIMER_ISR_reg, (1<<id));
}

static irqreturn_t rtk_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &rtk_clock_event;
	//rtd_setbits(ISR_reg, 1 << (sys_timer[SYSTEM_TIMER].isr_bit));
	clear_irq_reason(SYSTEM_TIMER);
	evt->event_handler(evt);
	return IRQ_HANDLED;
}

static struct irqaction rtk_timer_irq = {
    .dev_id     = (void *)sys_timer,
    .name       = "gp timer",
    .flags      = IRQF_TIMER | IRQF_SHARED,
    .handler    = rtk_timer_interrupt,
};

int create_timer(unsigned char id, unsigned int interval, unsigned char mode)
{
	//Disable Interrupt
	rtk_timer_control(id, HWT_INT_DISABLE);

	//Disable Timer
//	rtk_timer_control(id, HWT_STOP);

	//Set The Initial Value
	rtk_timer_set_value(id, 0);

	//Set The Target Value
	rtk_timer_set_target(id, interval);

	//Enable Timer Mode
	rtk_timer_set_mode(id, mode);

	//Enable Timer
//	rtk_timer_control(id, HWT_START);

	//Enable Interrupt
	rtk_timer_control(id, HWT_INT_ENABLE);

	return 0;
}

int rtk_timer_set_mode(unsigned char id, unsigned char mode)
{
	switch(mode) {
		case COUNTER:
			rtd_clearbits(sys_timer[id].cr, TIMERINFO_TIMER_MODE);
			break;
		case TIMER:
			rtd_setbits(sys_timer[id].cr, TIMERINFO_TIMER_MODE);
			break;
		default:
			return 1;
	}
	return 0;
}

int rtk_timer_get_value(unsigned char id)
{
    if (id >= MAX_HWTIMER_NUM)
        return 0;

    // get the current timer's value
    return rtd_inl(sys_timer[id].cvr);
}

int rtk_timer_set_value(unsigned char id, unsigned int value)
{
    if (id >= MAX_HWTIMER_NUM)
        return 1;

    // set the timer's initial value
    rtd_outl(sys_timer[id].cvr, value);
    return 0;
}

int rtk_timer_set_target(unsigned char id, unsigned int value)
{
    if (id >= MAX_HWTIMER_NUM)
        return 1;

    // set the timer's initial value
    rtd_outl(sys_timer[id].tvr, value);
    return 0;
}

int rtk_timer_control(unsigned char id, unsigned int cmd)
{
    if (id > MAX_HWTIMER_NUM)
        return 1;

    switch(cmd) {
        case HWT_INT_CLEAR:
            //rtd_setbits(UMSK_ISR_reg, 1 << (sys_timer[id].isr_bit));
            clear_irq_reason(id);
            break;
        case HWT_START:
            rtd_setbits(sys_timer[id].cr, TIMERINFO_TIMER_ENABLE);
            // Clear Interrupt Pending (must after enable)
            //rtd_setbits(ISR_reg, 1 << (sys_timer[id].isr_bit));
            clear_irq_reason(id);
            break;
        case HWT_STOP:
            rtd_clearbits( sys_timer[id].cr, TIMERINFO_TIMER_ENABLE);
            break;
        case HWT_PAUSE:
            rtd_setbits(sys_timer[id].cr, TIMERINFO_TIMER_PAUSE);
            break;
        case HWT_RESUME:
            rtd_clearbits(sys_timer[id].cr, TIMERINFO_TIMER_PAUSE);
            break;
        case HWT_INT_ENABLE:
            rtd_setbits(sys_timer[id].icr, TIMERINFO_INTERRUPT_ENABLE);
            break;
        case HWT_INT_DISABLE:
            rtd_clearbits(sys_timer[id].icr, TIMERINFO_INTERRUPT_ENABLE);
            break;
        default:
            return 1;
    }
    return 0;
}

#if 0 // before 4.2
static void cevt_set_mode(enum clock_event_mode mode,
                        struct clock_event_device *clk)
{
    switch (mode) {
    case CLOCK_EVT_MODE_PERIODIC:
        create_timer(SYSTEM_TIMER, TIMERINFO_BASE_CLOCK/HZ, TIMER);
        break;

    case CLOCK_EVT_MODE_ONESHOT:
        /* period set, and timer enabled in 'next_event' hook */
        create_timer(SYSTEM_TIMER, TIMERINFO_BASE_CLOCK/HZ, COUNTER);
        break;

    case CLOCK_EVT_MODE_RESUME:
	pr_info("ready to resume clock event device...\n");
	break;

    case CLOCK_EVT_MODE_SHUTDOWN:
	rtk_timer_control(SYSTEM_TIMER, HWT_INT_DISABLE);
//	rtk_timer_control(SYSTEM_TIMER, HWT_STOP);
	break;

    case CLOCK_EVT_MODE_UNUSED:
    default: break;
    }
}
#else
static int cevt_set_state_periodic(struct clock_event_device *clk)
{
	create_timer(SYSTEM_TIMER, TIMERINFO_BASE_CLOCK/HZ, TIMER);

	return 0;
}
static int cevt_set_state_oneshot(struct clock_event_device *clk)
{
	create_timer(SYSTEM_TIMER, TIMERINFO_BASE_CLOCK/HZ, COUNTER);

	return 0;
}
static int cevt_set_state_oneshot_stopped(struct clock_event_device *clk)
{
	rtk_timer_control(SYSTEM_TIMER, HWT_STOP);

	return 0;
}
static int cevt_set_state_shutdown(struct clock_event_device *clk)
{
	rtk_timer_control(SYSTEM_TIMER, HWT_INT_DISABLE);

	return 0;
}
static int cevt_tick_resume(struct clock_event_device *clk)
{
	pr_info("ready to resume clock event device...\n");

	return 0;
}
#endif

static int cevt_set_next_event(unsigned long evt,
                        struct clock_event_device *unused)
{
    unsigned int cnt;
    int res;

    rtd_outl(sys_timer[SYSTEM_TIMER].icr, 0x80000000);
    cnt = rtd_inl(sys_timer[SYSTEM_TIMER].cvr);
    cnt += evt;
    rtd_outl(sys_timer[SYSTEM_TIMER].tvr, cnt);

    res = ((int)(rtd_inl(sys_timer[SYSTEM_TIMER].cvr) - cnt) > 0) ? -ETIME : 0;

    return res;
}

void cevt_suspend(struct clock_event_device *evt)
{
}

void cevt_resume(struct clock_event_device *evt)
{
    // ensure the timer is off before we do the next step...
    rtk_timer_control(SYSTEM_TIMER, HWT_INT_DISABLE);
//  rtk_timer_control(SYSTEM_TIMER, HWT_STOP);
}

//Chuck TODO
#if (0)
static unsigned int __init estimate_cpu_frequency(void)
{
   unsigned int value_m, value_n, value_o;
   unsigned int freq, tmp;

   // use CRT register to estimate cpu frequency
   if ((rtd_inl(SYS_PLL_SCPU2_reg) & SYS_PLL_SCPU2_pllscpu_oeb_mask) == 0) {
      tmp = rtd_inl(SYS_PLL_SCPU1_reg);
      value_m = ((tmp & SYS_PLL_SCPU1_pllscpu_m_mask) >> SYS_PLL_SCPU1_pllscpu_m_shift);
      value_n = ((tmp & SYS_PLL_SCPU1_pllscpu_n_mask) >> SYS_PLL_SCPU1_pllscpu_n_shift);
      value_o = ((tmp & SYS_PLL_SCPU1_pllscpu_o_mask) >> SYS_PLL_SCPU1_pllscpu_o_shift);
      freq = 27 * (value_m+2) / (value_n+1) / (value_o+1);
   }
   else {
      freq = 27;
   }

   return freq;
}
#endif

static u64 rtk_read_sched_clock(void)
{
        return rtd_inl(sys_timer[SYSTEM_TIMER].cvr) + clock_offset;
}

static cycle_t rtk_hpt_read(struct clocksource *cs)
{
        return rtd_inl(sys_timer[SYSTEM_TIMER].cvr);
}

#ifdef CONFIG_ARM_ARCH_TIMER

unsigned int u32_CNTCVLW, u32_CNTCVUP;

void suspend_cs_timestamp(void)
{
#ifndef CONFIG_OPTEE
	rtd_outl(WRAP_A7_APB_TSG_EN0, 0x8);
	u32_CNTCVLW = rtd_inl(WRAP_A7_APB_TSG_EN1);
	rtd_outl(WRAP_A7_APB_TSG_EN0, 0xc);
	u32_CNTCVUP = rtd_inl(WRAP_A7_APB_TSG_EN1);
#endif
}

static void resume_cs_timestamp(void)
{

#ifndef CONFIG_OPTEE
	rtd_outl(WRAP_A7_APB_TSG_EN0, 0);
	rtd_outl(WRAP_A7_APB_TSG_EN1, 0);

	rtd_outl(WRAP_A7_APB_TSG_EN0, 0x8);
	rtd_outl(WRAP_A7_APB_TSG_EN1, u32_CNTCVLW);

	rtd_outl(WRAP_A7_APB_TSG_EN0, 0xc);
	rtd_outl(WRAP_A7_APB_TSG_EN1, u32_CNTCVUP);

	// configure coresight CNTCR
	rtd_outl(WRAP_A7_APB_TSG_EN0, 0);
	rtd_outl(WRAP_A7_APB_TSG_EN1, 1);

	// configure coresight CNTFID0
	rtd_outl(WRAP_A7_APB_TSG_EN0, 0x20);
	rtd_outl(WRAP_A7_APB_TSG_EN1, 0x019bfcc0);
#endif
}
#endif

static void rtk_hpt_suspend(struct clocksource *cs)
{
	clock_offset = rtk_read_sched_clock();
	rtk_timer_control(SYSTEM_TIMER, HWT_STOP);
#ifdef CONFIG_ARM_ARCH_TIMER
	suspend_cs_timestamp();
#endif
}

static void rtk_hpt_resume(struct clocksource *cs)
{
	rtk_timer_control(SYSTEM_TIMER, HWT_START);
#ifdef CONFIG_ARM_ARCH_TIMER
	resume_cs_timestamp();
#endif
}

static struct clocksource clocksource_rtk = {
        .name           = "RTK_CSRC",
        .read           = rtk_hpt_read,
        .mask           = CLOCKSOURCE_MASK(32),
        .flags          = CLOCK_SOURCE_IS_CONTINUOUS,
        .suspend        = rtk_hpt_suspend,
        .resume         = rtk_hpt_resume,
};

int rtk_clocksource_init(void)
{
        /* Calculate a somewhat reasonable rating value */
        clocksource_rtk.rating = 200 + TIMERINFO_BASE_CLOCK / 10000000;
#if 0 // before 3.15
        setup_sched_clock(rtk_read_sched_clock, 32, TIMERINFO_BASE_CLOCK);
#else
		sched_clock_register(rtk_read_sched_clock, 32, TIMERINFO_BASE_CLOCK);
#endif
        clocksource_register_hz(&clocksource_rtk, TIMERINFO_BASE_CLOCK);

        rtk_timer_control(SYSTEM_TIMER, HWT_START);

        return 0;
}

void rtk_timer_init(void)
{
    struct clock_event_device *evt = &rtk_clock_event;
    unsigned int est_freq_hw_timer = 0;
#ifdef CONFIG_ARM_ARCH_TIMER
//    int ppi[4]= {29, 0, 0, 0};
#if defined (CONFIG_OPTEE) && defined (CONFIG_ARCH_RTK284X)
    int ppi[4]= {29, 30, 26, 26}; //workaround for mac5p
#else
    int ppi[4]= {29, 30, 0, 26};
#endif
#endif

    //Chuck TODO
    //est_freq = estimate_cpu_frequency();
    est_freq_hw_timer = 27;

    //printk("Estimated  CPU  frequency: %d MHz\n", est_freq);
    //printk("Estimated Timer frequency: %d MHz\n", est_freq_hw_timer);

#ifdef CONFIG_REALTEK_SCHED_LOG
//  sched_log_time_scale = est_freq;
    sched_log_time_scale = est_freq_hw_timer;
#endif // CONFIG_REALTEK_SCHED_LOG

    memset(evt, 0, sizeof(struct clock_event_device));
#ifndef CONFIG_REALTEK_SECURE_OS
    evt->irq            = IRQ_TIMER;
#else
    evt->irq            = IRQ_AUDIO_DMA;
#endif
    evt->name           = "system timer";
    evt->features       = CLOCK_EVT_FEAT_ONESHOT;
    evt->rating         = HZ; // 350
#if 0 // before 4.2
    evt->set_mode       = cevt_set_mode;
#else
	evt->set_state_periodic = cevt_set_state_periodic;
	evt->set_state_oneshot = cevt_set_state_oneshot;
	evt->set_state_oneshot_stopped = cevt_set_state_oneshot_stopped;
	evt->set_state_shutdown = cevt_set_state_shutdown;
	evt->tick_resume = cevt_tick_resume;
#endif
    evt->set_next_event = cevt_set_next_event;
    evt->shift          = 32;
    evt->mult           = div_sc(TIMERINFO_BASE_CLOCK, NSEC_PER_SEC, evt->shift);
    evt->max_delta_ns   = clockevent_delta2ns(0x7fffffff, evt);
    evt->min_delta_ns   = clockevent_delta2ns(0x300, evt);
    evt->cpumask        = cpumask_of(0); // cpu_all_mask
    evt->suspend        = cevt_suspend;
    evt->resume         = cevt_resume;

    setup_irq(evt->irq, &rtk_timer_irq);
    rtk_clocksource_init();
    clockevents_register_device(evt);

#ifdef CONFIG_ARM_ARCH_TIMER
    // configure coresight CNTCR
#ifndef CONFIG_OPTEE
    rtd_outl(WRAP_A7_APB_TSG_EN0, 0);
    rtd_outl(WRAP_A7_APB_TSG_EN1, 1);

    // configure coresight CNTFID0
    rtd_outl(WRAP_A7_APB_TSG_EN0, 0x20);
    rtd_outl(WRAP_A7_APB_TSG_EN1, 0x019bfcc0);
#endif

#ifdef CONFIG_ATAGS
    arch_timer_dev_register(TIMER_CLOCK, ppi);
#endif
#endif
}

