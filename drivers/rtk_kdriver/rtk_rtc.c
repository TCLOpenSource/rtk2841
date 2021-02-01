/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2013 by Chien-An Lin <colin@realtek.com.tw>
 *
 * Time initialization.
 */
#include <linux/clockchips.h>
#include <mach/platform.h>
#include <linux/export.h>
#include <rbus/stb_reg.h>
#include <rbus/drtc_reg.h>
DEFINE_SPINLOCK(rtc_lock);

#include <linux/init.h>
#include <linux/kernel.h>       /* printk() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/slab.h>
#include <linux/time.h>
#include <asm/mach/time.h>
#include <rtk_kdriver/RPCDriver.h>
#include <linux/pageremap.h>
#include <asm/cacheflush.h>
#include <rtk_kdriver/rtk_otp_util.h>
#include <rtk_kdriver/rtk_sb2_callback.h>

#if (defined(CONFIG_OPTEE) && !defined(CONFIG_CUSTOMER_TV006))
#include <linux/arm-smccc.h>

struct optee_rpc_param {
	u32	a0;
	u32	a1;
	u32	a2;
	u32	a3;
	u32	a4;
	u32	a5;
	u32	a6;
	u32	a7;
};
extern int optee_rtc_set_info_send(struct optee_rpc_param *p_rtc_set_info);
#endif

/*define*/
#define RTC_OPS_REQ_MAGIC               0xCC525443      //'R'(52)'T'(54)'C'(43)
#define RTC_OPS_SET_MMSS                0xCC00
#define RTC_OPS_SET_ALARM_MMSS          0xCC01
#define RTC_OPS_SET_AIE_ENABLE          0xCC02
#define RTC_OPS_SET_AIE_DISABLE         0xCC03

#define RTD_SHARE_MEM_BASE      0xb8060500
#define RTC_WAKEUP_FLAG         BIT(30)

//use dummy register(0xB806010C) as rtc alarm sec register temporarily
#define DRTC_ALMSEC_reg         STB_WDOG_DATA4_reg
#define DRTC_ALMSEC_tag         0xCC000000

static int g_is_secure_rbus_rtk_rtc ;

/*struct define*/
typedef struct {
        unsigned int    magic_num;
        unsigned int    rtc_ops;
        unsigned int    sec;
        unsigned int    min;
        unsigned int    hour;
        unsigned int    day;
        char *          prv;
} rtc_req;

static int rtk_rtc_cowork_with_secure_os(unsigned int         rtc_ops,
                                    unsigned int     sec,
                                    unsigned int     min,
                                    unsigned int     hour,
                                    unsigned int     day)
{
#if (defined(CONFIG_OPTEE) && !defined(CONFIG_CUSTOMER_TV006))
        struct optee_rpc_param rtc_set_info; 

        rtc_set_info.a1 = RTC_OPS_REQ_MAGIC;
        rtc_set_info.a2 = rtc_ops;
        rtc_set_info.a3 = sec;
        rtc_set_info.a4 = min;
        rtc_set_info.a5 = hour;
        rtc_set_info.a6 = day;  
        pr_notice("[%s][%d]Send cmd to optee OS.[rtc_ops = 0x%x]\n", __func__, __LINE__, rtc_ops);
        return optee_rtc_set_info_send(&rtc_set_info);        
#else    
        unsigned long vir_addr = 0;
        unsigned long phy_addr = 0;
        unsigned long ret;
        int size = 0;
        rtc_req rtc_op;

        size = sizeof(rtc_req);
        memset((void *)&rtc_op, 0x00, size);

        // pack rtc info
        rtc_op.magic_num = RTC_OPS_REQ_MAGIC;
        rtc_op.rtc_ops = rtc_ops;
        rtc_op.sec = sec;
        rtc_op.min = min;
        rtc_op.hour = hour;
        rtc_op.day = day;

        // allocate buffer
        vir_addr = (unsigned long)dvr_malloc_specific(size, GFP_DCU1);
        if (!vir_addr) {
                pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
                return -1;
        }

        phy_addr = (unsigned long)dvr_to_phys((void*)vir_addr);
        if (!phy_addr) {
                pr_err("[%s %d]do dvr_to_phys fail\n", __func__, __LINE__);
                goto out;
        }

        // copy rtc info to buffer
        memcpy((void *)vir_addr, (void *)(&rtc_op), size);

        // do flush
        dmac_flush_range((void *)vir_addr, (void *)(vir_addr + size)) ;
        outer_flush_range((phys_addr_t)phy_addr, (phys_addr_t)phy_addr + size) ;

#ifdef CONFIG_RTK_KDRV_RPC
        // send rpc to kcpu
        if (send_rpc_command(RPC_KCPU, RPC_SCPU_RTC_OPS_REQ, phy_addr, 0, &ret) == RPC_OK) {
                pr_notice("[%s][%d]Send rpc to kcpu done![op-code = 0x%x]\n", __func__, __LINE__, rtc_op.rtc_ops);
        }else {
                pr_err("[%s][%d]Send rpc to kcpu fail![op-code = 0x%x]\n", __func__, __LINE__, rtc_op.rtc_ops);
                goto out;
        }
#else
	pr_err("[%s][%d]Send rpc to kcpu fail! CONFIG_RTK_KDRV_RPC is disabled! \n", __func__, __LINE__);
#endif
        if(ret != 0) {
                pr_err("[%s][%d]Send rpc to kcpu return fail![op-code = 0x%x]\n", __func__, __LINE__, rtc_op.rtc_ops);
                goto out;
        }

        // free buffer
        dvr_free((void *)vir_addr);
        return 0;

out:
        dvr_free((void *)vir_addr);
        return -1;
#endif
}

int rtk_rtc_secure_rbus_bit_state(void)
{
	return g_is_secure_rbus_rtk_rtc;
}

void rtk_rtc_dump_set_time(void)
{
    int min,hour,sec,day;
    int value = 0;

    pr_info("\n\n***********dump rtc device time************************");
    min = rtd_inl(DRTC_RTCMIN_reg);
    hour = rtd_inl(DRTC_RTCHR_reg);
    sec = rtd_inl(DRTC_RTCSEC_reg);
    day = rtd_inl(DRTC_RTCDATE1_reg);
    day += rtd_inl(DRTC_RTCDATE2_reg) << 8;    
    pr_info("RTC_time:[day: %d] %02d:%02d:%02d\n",day,hour,min,(sec/2));

    min = rtd_inl(DRTC_ALMMIN_reg);
    hour = rtd_inl(DRTC_ALMHR_reg);
    day = rtd_inl(DRTC_ALMDATE1_reg);
    day += rtd_inl(DRTC_ALMDATE2_reg) << 8;    
    sec = (rtd_inl(DRTC_ALMSEC_reg) & 0x00ffffff);
    pr_info("ALARM_time:[day: %d] %02d:%02d:%02d\n",day,hour,min,(sec/2));

    value = rtd_inl(DRTC_RTCCR_reg);
    pr_info("interrupt status:(0x%08x) = 0x%08x \n", DRTC_RTCCR_reg, value);
    pr_info("alarm_sec status:(0x%08x) = 0x%08x \n", DRTC_ALMSEC_reg, rtd_inl(DRTC_ALMSEC_reg));
    pr_info("rtc enable status:(0x%08x) = 0x%08x \n", DRTC_RTCEN_reg, rtd_inl(DRTC_RTCEN_reg));

    pr_info("************dump rtc device time end***********************\n");

}

void rtk_rtc_sb2_timeout_debug_info(void) {
        sb2_timeout_info rtc_timeout_info; 
        unsigned int otp_secure_rbus_type_buf = 0;
        //check trash module
        if(!isSb2Timeout("ST PERI")) { 
                return;
        }
        
        //get sb2 timeout information 
        get_sb2_timeout_info(&rtc_timeout_info);  

        //trash address not match DRTC register range
        if((rtc_timeout_info.timeout_reg < 0x18061900) || (rtc_timeout_info.timeout_reg > 0x18061930))
        {
            return ;
        }

        pr_err("Access DRTC register timeout,Trash address:0x%lx \n",rtc_timeout_info.timeout_reg);
#ifdef CONFIG_RTK_KDRV_OTP
        //secure_rbus_bit   0x18038040 [11:8]  X011: enable(Security Rbus)
        otp_read_bits(0x40, 11, 8, &otp_secure_rbus_type_buf);
#endif
        //printf debug info
        pr_err("Secure_rbus_bit value = %d\n",otp_secure_rbus_type_buf);
        pr_err("DRTC clk: (0x%08x) = 0x%08x \n",STB_ST_CLKEN2_reg,rtd_inl(STB_ST_CLKEN2_reg));

        return;
}

void rtk_rtc_alarm_aie_enable(int state)
{
        unsigned long flags;

        if(g_is_secure_rbus_rtk_rtc == 1) {
                if(state) {
                        rtk_rtc_cowork_with_secure_os(RTC_OPS_SET_AIE_ENABLE, 0, 0, 0, 0);
                } else {
                        rtk_rtc_cowork_with_secure_os(RTC_OPS_SET_AIE_DISABLE, 0, 0, 0, 0);
                }
        } else {
                spin_lock_irqsave(&rtc_lock, flags);
                if(state) {
                        rtd_setbits(DRTC_RTCCR_reg, DRTC_RTCCR_alarminte_mask);
                } else {
                        rtd_clearbits(DRTC_RTCCR_reg, DRTC_RTCCR_rtc_alarm_int_status_mask);
                        rtd_clearbits(DRTC_RTCCR_reg, DRTC_RTCCR_alarminte_mask);
                }
                spin_unlock_irqrestore(&rtc_lock, flags);
        }

#if !defined(CONFIG_CUSTOMER_TV006)
        if(state){
            //inform 8051 do rtc_wakeup
            rtd_setbits(RTD_SHARE_MEM_BASE,RTC_WAKEUP_FLAG);
        }
#endif        

}

int rtk_rtc_alarm_aie_state(void)
{
        int ret;

        if(rtd_inl(DRTC_RTCCR_reg) & DRTC_RTCCR_alarminte_mask)
                ret = 1;
        else
                ret = 0;

        return ret;
}


void rtk_read_persistent_clock(struct timespec64 *ts)
{
        int day, hour, min, sec;
        unsigned long flags;

        spin_lock_irqsave(&rtc_lock, flags);

        sec = rtd_inl(DRTC_RTCSEC_reg) >> 1;    // One unit represents half second
        min = rtd_inl(DRTC_RTCMIN_reg);
        hour = rtd_inl(DRTC_RTCHR_reg);
        day = rtd_inl(DRTC_RTCDATE1_reg);
        day += rtd_inl(DRTC_RTCDATE2_reg) << 8;

        spin_unlock_irqrestore(&rtc_lock, flags);
        ts->tv_sec = ((day * 24 + hour) * 60 + min) * 60 + sec + mktime(platform_info.rtc_base_date_year, 1, 1, 0, 0, 0);
        ts->tv_nsec = 0;
}

int rtk_rtc_mips_set_mmss(unsigned long nowtime)
{
        unsigned long flags;
        int day, hour, min, sec, hms;
        unsigned long off_sec, base_sec = mktime(platform_info.rtc_base_date_year, 1, 1, 0, 0, 0);

        off_sec = nowtime - base_sec;
        if(base_sec > nowtime) {
                pr_err("RTC set time error! The time cannot be set to the date before year %d.\n", platform_info.rtc_base_date_year);
                return -EINVAL;
        }

        day = off_sec / (24 * 60 * 60);
        hms = off_sec % (24 * 60 * 60);
        hour = hms / 3600;
        min = (hms % 3600) / 60;
        sec = ((hms % 3600) % 60) * 2;  // One unit represents half second.

        if(day > 16383) {
                pr_err("RTC day field overflow. I am so surprised that the Realtek product has been used for more than 40 years. Is it still workable? Hahaha...\n");
                return -EINVAL;
        }

        if(g_is_secure_rbus_rtk_rtc == 1) {
                if(rtk_rtc_cowork_with_secure_os(RTC_OPS_SET_MMSS, sec, min, hour, day) < 0) {
                        pr_err("RTC SET MMSS fail, Cowork with Secure OS!\n");
                        spin_unlock(&rtc_lock);
                        return -EPIPE;
                }
        } else {
                /* irq are locally disabled here, but I still like to use spin_lock_irqsave */
                spin_lock_irqsave(&rtc_lock, flags);
                rtd_outl(DRTC_RTCSEC_reg, sec);
                rtd_outl(DRTC_RTCMIN_reg, min);
                rtd_outl(DRTC_RTCHR_reg, hour);
                rtd_outl(DRTC_RTCDATE1_reg, day & 0x00ff);
                rtd_outl(DRTC_RTCDATE2_reg, (day & 0x3f00) >> 8);
                spin_unlock_irqrestore(&rtc_lock, flags);
        }
        pr_notice("[%s][%d]RTC set time success\n", __func__, __LINE__);

        return 0;
}

void rtk_rtc_read_alarm_persistent_clock(struct timespec64 *ts)
{
        int day, hour, min;
        unsigned long flags;

        if(rtk_rtc_alarm_aie_state()) {
                spin_lock_irqsave(&rtc_lock, flags);
                min = rtd_inl(DRTC_ALMMIN_reg);
                hour = rtd_inl(DRTC_ALMHR_reg);
                day = rtd_inl(DRTC_ALMDATE1_reg);
                day += rtd_inl(DRTC_ALMDATE2_reg) << 8;
                spin_unlock_irqrestore(&rtc_lock, flags);
        } else {
                min = 0;
                hour = 0;
                day = 0;
        }
        ts->tv_sec = ((day * 24 + hour) * 60 + min) * 60 + mktime(platform_info.rtc_base_date_year, 1, 1, 0, 0, 0);
        ts->tv_nsec = 0;
}

int rtk_rtc_set_alarm_mmss(unsigned long nowtime)
{
        unsigned long flags;
        int day, hour, min, hms, sec;
        unsigned long off_sec, base_sec = mktime(platform_info.rtc_base_date_year, 1, 1, 0, 0, 0);

        off_sec = nowtime - base_sec + 60;
        if(base_sec > nowtime) {
                pr_err("RTC alarm set time error! The time cannot be set to the date before year %d.\n", platform_info.rtc_base_date_year);
                return -EINVAL;
        }

        day = off_sec / (24 * 60 * 60);
        hms = off_sec % (24 * 60 * 60);
        hour = hms / 3600;
        min = (hms % 3600) / 60;
        sec = ((hms % 3600) % 60) * 2;  // One unit represents half second.

        if(day > 16383) {
                pr_err("RTC alarm day field overflow.\n");
                return -EINVAL;
        }

        rtd_outl(DRTC_ALMSEC_reg, sec | DRTC_ALMSEC_tag);
        if(g_is_secure_rbus_rtk_rtc == 1) {
                if(rtk_rtc_cowork_with_secure_os(RTC_OPS_SET_ALARM_MMSS, 0, min, hour, day) < 0) {
                        pr_err("RTC SET ALARM MMSS fail, Cowork with Secure OS!\n");
                        spin_unlock(&rtc_lock);
                        return -EPIPE;
                }
        } else {
                /* irq are locally disabled here, but I still like to use spin_lock_irqsave */
                spin_lock_irqsave(&rtc_lock, flags);
                rtd_outl(DRTC_ALMMIN_reg, min);
                rtd_outl(DRTC_ALMHR_reg, hour);
                rtd_outl(DRTC_ALMDATE1_reg, day & 0x00ff);
                rtd_outl(DRTC_ALMDATE2_reg, (day & 0x3f00) >> 8);
                spin_unlock_irqrestore(&rtc_lock, flags);
        }
        rtk_rtc_dump_set_time();
        return 0;
}

int rtk_rtc_ip_init(void)
{
        int ret = 0;
        unsigned int otp_secure_rbus_type_buf = 0;
        
#ifdef CONFIG_RTK_KDRV_OTP
        //secure_rbus_bit   0x18038040 [11:8]  X011: enable(Security Rbus)
        ret = otp_read_bits(0x40, 11, 8, &otp_secure_rbus_type_buf);
#else
        pr_err("[%s][%d]Read OTP fail! CONFIG_RTK_KDRV_OTP is disabled! \n", __func__, __LINE__);

#endif
        if(otp_secure_rbus_type_buf == 3) {
                g_is_secure_rbus_rtk_rtc = 1;
        }

        if(g_is_secure_rbus_rtk_rtc == 0) {
                if (!STB_ST_CLKEN2_get_clken_rtc(rtd_inl(STB_ST_CLKEN2_reg))) {
                        // enable DRTC clock
                        rtd_outl(STB_ST_CLKEN2_reg, STB_ST_CLKEN2_clken_rtc(1) | STB_ST_CLKEN2_get_write_data(0));
                        rtd_outl(STB_ST_SRST2_reg, STB_ST_SRST2_rstn_rtc(1) | STB_ST_SRST2_get_write_data(0));
                        rtd_outl(STB_ST_SRST2_reg, STB_ST_SRST2_rstn_rtc(1) | STB_ST_SRST2_get_write_data(1));
                        rtd_outl(STB_ST_CLKEN2_reg, STB_ST_CLKEN2_clken_rtc(1) | STB_ST_CLKEN2_get_write_data(1));


                        // reset time info
                        rtd_outl(DRTC_RTCSEC_reg, 0x0); // sec
                        rtd_outl(DRTC_RTCMIN_reg, 0x0); // min
                        rtd_outl(DRTC_RTCHR_reg, 0x0); // hour
                        rtd_outl(DRTC_RTCDATE1_reg, 0x0); // date LSB
                        rtd_outl(DRTC_RTCDATE2_reg, 0x0); // date MSB

                        // enable RTC
                        rtd_maskl(DRTC_RTCEN_reg, 0xff, 0x5A);
                }
        }

        if((platform_info.rtc_base_date_year > 2005) || (platform_info.rtc_base_date_year < 1985)) {
            //pr_notice(" Base year of RTC error. Reset to year 2005.\n");
            platform_info.rtc_base_date_year = 2005;
        }
        return 0;
}

int rtk_rtc_early_init(void)
{
	rtk_rtc_ip_init();

	if(g_is_secure_rbus_rtk_rtc == 0){
		register_persistent_clock(NULL, (clock_access_fn)rtk_read_persistent_clock); //used to sync rtc time to system time
	}
	else{
#ifdef CONFIG_REALTEK_SECURE	 	
		register_persistent_clock(NULL, (clock_access_fn)rtk_read_persistent_clock); 
#endif
	}

	return 0;
}

#if 0
static unsigned int __init estimate_cpu_frequency(void)
{
//      unsigned int value_m, value_n, value_o;
        unsigned int value_n, value_f;
        unsigned int freq, tmp;

        // use CRT register to estimate cpu frequency
        if ((rtd_inl(SYS_PLL_SCPU2_reg) & SYS_PLL_SCPU2_pllscpu_oeb_mask) == 0) {
                tmp = rtd_inl(SYS_PLL_SCPU1_reg);
                // PLL Frequency = 27 * (NCODE + 3 + FCODE / 2048);
//              value_m = ((tmp & SYS_PLL_SCPU1_pllscpu_m_mask) >> SYS_PLL_SCPU1_pllscpu_m_shift);
                value_n = ((tmp & SYS_PLL_SCPU2_pllscpu_ncode_mask) >> SYS_PLL_SCPU2_pllscpu_ncode_shift);
                value_f = ((tmp & SYS_PLL_SCPU2_pllscpu_fcode_mask) >> SYS_PLL_SCPU2_pllscpu_fcode_shift);
//              value_o = ((tmp & SYS_PLL_SCPU1_pllscpu_o_mask) >> SYS_PLL_SCPU1_pllscpu_o_shift);
//              freq = 27 * (value_m+2) / (value_n+1) / (value_o+1);
                freq = 27 * (value_n + 3 + value_f / 2048);
        } else {
                freq = 27;
        }

        return freq;
}
#endif

//disable rtc alarm & clear rtc alarm interrupt pending bit.
static int __init rtk_alarm_init(void)
{
	rtk_rtc_alarm_aie_enable(0);  
	return 0;
}

late_initcall(rtk_alarm_init);

EXPORT_SYMBOL(rtk_rtc_ip_init);
EXPORT_SYMBOL(rtk_read_persistent_clock);
EXPORT_SYMBOL(rtk_rtc_mips_set_mmss);
EXPORT_SYMBOL(rtk_rtc_read_alarm_persistent_clock);
EXPORT_SYMBOL(rtk_rtc_set_alarm_mmss);
EXPORT_SYMBOL(rtk_rtc_alarm_aie_enable);
EXPORT_SYMBOL(rtk_rtc_alarm_aie_state);

