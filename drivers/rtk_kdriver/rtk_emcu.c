#include <linux/init.h>
#include <linux/suspend.h>
#include <linux/errno.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <rbus/stb_reg.h>
#include <rbus/emcu_reg.h>
#include <rbus/irda_reg.h>
#include "../emcu/rtk_kdv_emcu.h"
#include <rtk_kdriver/rtk_emcu_export.h>
#include <linux/dma-mapping.h>
#include <asm/cacheflush.h>
#include <asm/system_misc.h>
#include <asm/suspend.h>
#include <tvscalercontrol/panel/panelapi.h>
#include <mach/platform.h>

#ifdef CONFIG_RTK_KDRV_IR
extern int ir_suspend_protocol(void);
#endif

#ifdef CONFIG_RTK_KDRV_CEC
extern int pm_rtd299x_cec_suspend(void);
#endif


extern platform_info_t platform_info;
extern int rtk_SetIOPinDirection(unsigned long long pininfo, unsigned int value);
extern int emcu_chk_event(void);

/* general reg setting */
#define REG_MAGIC_51                0xb8060110
#define REG_8051_TICK               0xb8060114
#define REG_SCPU_TICK               0xb8060118

/* 8051 magic event */
#define MAGIC_8051                  0x2379beef  /* 8051 is runing but counting RTC only. setting by 8051 only.*/
#define WAKE_8051                   0x9021affe  /* send message to 8051,let 8051 wakeup and handle standby status.. */
#define CHECK_8051                   0           /* set magic reg of 8051 to zero then check 8051 is runing. */

#define GET_MAGIC_PARM()            rtd_inl(REG_MAGIC_51)
#define SET_MAGIC_PARM(num)         rtd_outl(REG_MAGIC_51,num)

#define CHK_CEC(num)                (num>>loc_cec)&0xf

#define STM_NOEMAL      1
#define STM_WAKEUP      2

static void pm_load_st_gpio(void)
{
    unsigned long long value;
    char *buf, *token;
    buf = platform_info.pcb_st_enum_parameter;
    while(1)
    {
        token = strchr(buf,',');
        if (token){
            token = token + 1;
            value = simple_strtoull(token, 0, 0);
            rtk_SetIOPinDirection(value,0);
        }
        else
            break;

        buf = token;
    }
}

static void calculate_DDR_checksum(void)
{
    unsigned int *begin_ptr = phys_to_virt(0x02000000);
    unsigned int *end_ptr = phys_to_virt(0x16000000);
    const unsigned int length = 0x01000000/4;
    unsigned int total_checksume = 0;

    while(begin_ptr < end_ptr)
    {
        unsigned int i;
        unsigned int sumValue = 0;
        unsigned int *data_ptr = begin_ptr;

        for(i=0; i<length; i++)
        {
            sumValue+= *data_ptr;
            data_ptr++;
        }

        printk("DDR_checksum(%lx/%x)\n", (unsigned long int)begin_ptr, sumValue);
        total_checksume +=sumValue;
        begin_ptr+=length;

    }
    printk("DDR_checksum total (%x)\n", total_checksume);

    //check for ACPU ddr
    {
        unsigned int *data_ptr = phys_to_virt(0x01600000 );
        unsigned int *end_ptr = phys_to_virt(0x01a00000);
        unsigned int sumValue=0;
        while(data_ptr<end_ptr)
        {
            sumValue+=*data_ptr;
            data_ptr++;
        }
        printk("DDR_checksum A(%x)\n", sumValue);
    }

    //check for VCPU1 ddr
    {
        unsigned int *data_ptr = phys_to_virt(0x01a00000 );
        unsigned int *end_ptr = phys_to_virt(0x01e00000);
        unsigned int sumValue=0;
        while(data_ptr<end_ptr)
        {
            sumValue+=*data_ptr;
            data_ptr++;
        }
        printk("DDR_checksum V1(%x)\n", sumValue);
    }

    //check for VCPU2 ddr
    {
        unsigned int *data_ptr = phys_to_virt(0x01e00000 );
        unsigned int *end_ptr = phys_to_virt(0x01f00000);
        unsigned int sumValue=0;
        while(data_ptr<end_ptr)
        {
            sumValue+=*data_ptr;
            data_ptr++;
        }
        printk("DDR_checksum V2(%x)\n", sumValue);
    }
}

/** NOTICE,
 * wakup_8051 is modified as instead of timer shudown main area,
 * but wait for STANDBYWFIL2 for sure all SCPU activities idle.
 * An additional option will be set for emcu fw, to countdown this waiting.
 * - if timeout, SOC will reboot. (AC reboot)
 * - if option=0, means no reboot. (Keep platform for debugging.)
 **/
void wakeup_8051(int flag)
{
    printk("@@!!!!!enter pm_wakeup_emcu\n");

    /* ================================================
     * refine enable EMCU core flow as DIC's recommend
     * CLKEN=1 > CLKEN=0 > RSTN=1 > CLKEN=1
     * ================================================*/

#ifdef CONFIG_CUSTOMER_TV030
    rtd_outl(REG_MAGIC_51, 0);
    rtd_outl(STB_ST_SRST1_reg, _BIT9);           // rst off
    rtd_outl(STB_ST_CLKEN1_reg, _BIT9 | _BIT0);  // clk enable
    rtd_outl(STB_ST_SRST1_reg, _BIT9 | _BIT0);   // rst on
#else
    if(rtd_inl(0xb8060110) == 0x9021aebe)
        rtd_outl(STB_ST_SRST1_reg, _BIT9);           // rst off
    rtd_outl(STB_ST_CLKEN1_reg, _BIT9 | _BIT0);  // clk enable
    rtd_outl(STB_ST_SRST1_reg, _BIT9 | _BIT0);   // rst on
#endif

    udelay(500);

    if(flag == SUSPEND_RAM){
        pr_alert("%s(%u)ecpu reset release done\n",__func__,__LINE__);
                    rtd_outl(REG_MAGIC_51, WAKE_8051);
        }
        else{
            rtd_outl(STB_ST_SRST1_reg, _BIT9 | _BIT0);
                    rtd_outl(REG_MAGIC_51, 0x9021affc);
            pr_alert("%s(%u)ecpu reset release done\n",__func__,__LINE__);
            while(1);
        }

    //go forwared to enter optee, where to do cpu_suspend.
    /* fixme, if not optee, SCPU core 0 should also do individual cpu shutdown flow, instead of while(1). */
#if !defined (CONFIG_OPTEE)
        while(1);
#endif
}


void rtkpm_get_param(void){
#ifdef CONFIG_RTK_KDRV_IR
    ir_suspend_protocol();
#endif
#ifdef CONFIG_RTK_KDRV_CEC
    if(CHK_CEC(GET_EVENT_MSG())) {
        printk("\n==>initial CEC suspend block.\n");
        pm_rtd299x_cec_suspend();
        rtd_outl(STB_ST_BUSCLK_reg, rtd_inl(STB_ST_BUSCLK_reg) |
                                (1 << STB_ST_BUSCLK_bus_clksel_shift)); /*let clock is 27Mhz*/
    }
#endif

}

#if defined (CONFIG_RTK_KDRV_EMCU_DCOFF_TIMEOUT)
static int emcu_dcoff_timeout = CONFIG_RTK_KDRV_EMCU_DCOFF_TIMEOUT;

void set_emcu_dcoff_timeout(void)
{
    rtd_outl(RTD_SHARE_MEM_BASE+(4*IDX_REG_DC_OFF_TIMEOUT), emcu_dcoff_timeout);
}

#else
#define set_emcu_dcoff_timeout() do {} while(0)
#endif //#if defined (RTK_KDRV_EMCU_DCOFF_TIMEOUT)


#ifdef CONFIG_RTK_KDRV_WATCHDOG
extern int watchdog_enable (unsigned char On);
#endif

// added by zhang_jie@rtk to pull the HotPlug pins low here manually
extern void newbase_hdmi_set_hpd(unsigned char nport, unsigned char high, unsigned char controllable);

extern char hdmi_suspend_set_hotplug_flag;
void Pull_Low_HPD(void)
{
	unsigned char port;
	printk("\n hotplug setting begins! \n");
	
	if(hdmi_suspend_set_hotplug_flag==1)
		return;
	for (port = 0; port < 3/* HDMI_RX_PORT_MAX_NUM */; port++)
		newbase_hdmi_set_hpd(port, 0, 1);  // Pull low the HotPlug here manually when DC off
		
	printk("\n hotplug setting ends! \n");
}

extern void lib_hdmi_power(unsigned char port, unsigned char enable);
// added by zhang_jie@rtk to close the HDMI IP power again here manually
void Disable_HDMI_Z0_Power(void)
{
		unsigned char port;
		printk("\n Z0 power setting begins! \n");

		//#define  DFE_HDMI_RX_PHY_P0P1_Z0POW_reg	0xB800DA20  // port0 and port1 share this register
		//#define  DFE_HDMI_RX_PHY_P2_Z0POW_reg	   0xB800DC20	// port2

		for (port = 0; port < 3/* HDMI_RX_PORT_MAX_NUM */; port++){
			lib_hdmi_power(port, 0);
		}
		printk("\n Z0 power setting ends! \n");		
}

int rtk_pm_load_8051(int flag)
{
    printk("\n%s(%u)2013/07/09 11:30\n",__func__,__LINE__);
    local_irq_disable();

#ifdef CONFIG_RTK_KDRV_WATCHDOG
        printk("Suspend action...MUST disable watchdog\n");
        watchdog_enable(0);
#endif
    if(flag == SUSPEND_BOOTCODE)
    {
        printk("bootcode call suspend.\n");
    }else if((flag == SUSPEND_RAM )||
             (flag == SUSPEND_WAKEUP))
    {
        unsigned int pm_event_msg;
        unsigned int stm_value;

        pm_event_msg = GET_EVENT_MSG();

        if(flag == SUSPEND_WAKEUP){
            stm_value = STM_WAKEUP;
        }else{
            //for after add rtc_wakeup, stm area only used BIT_28 & BIT_29
            stm_value = (pm_event_msg>>loc_stm) &0x03;
            if(!stm_value)
                stm_value = STM_NOEMAL;
        }

        //for after add rtc_wakeup, stm area only used BIT_28 & BIT_29
        pm_event_msg = (pm_event_msg&0xcfffffff)|(stm_value<<loc_stm);
        SET_EVENT_MSG(pm_event_msg);
        printk("Suspend to RAM action...(0x%08x)\n",pm_event_msg);

    }else{
#ifdef CONFIG_RTK_KDRV_WATCHDOG
        /*Jira MAC5P-2215, disable watchdog when enter emcu_on mode*/
		Panel_TurnOff();
#endif
        printk("system call suspend.(disable watchdog)\n");
    }

    if(flag != SUSPEND_WAKEUP)
    {
        pm_load_st_gpio();
    }
    printk("load bin file from DDR\n");
#ifndef CONFIG_TV005
    rtkpm_get_param();
#endif

#ifdef CONFIG_CUSTOMER_TV030
	Pull_Low_HPD();
	Disable_HDMI_Z0_Power();
#endif

/* Calculate DDR checksum for make sure STR flow DDR data is not corrupt */
#if 1
    if((rtd_inl(STB_WDOG_DATA14_reg) == 0xfafefafe) && (flag == SUSPEND_RAM))
        calculate_DDR_checksum();
#endif

    set_emcu_dcoff_timeout();

#ifdef CONFIG_TV030_PLATFORM
extern int ir_protocol;
    unsigned int share_tmp = rtd_inl(RTD_SHARE_MEM_BASE);
    unsigned int share_ir_tmp = rtd_inl(RTD_SHARE_MEM_BASE+4*(0xe));
    unsigned int share_led_tmp = rtd_inl(RTD_SHARE_MEM_BASE+4*(0x1c));
    unsigned int share_irdaKey_tmp1 = rtd_inl(RTD_SHARE_MEM_BASE+4*(0xf));
    unsigned int share_irdaKey_tmp2 = rtd_inl(RTD_SHARE_MEM_BASE+4*(0x10));
	if(share_led_tmp == 0x0) 
	{
	    printk("NTS non-STR,led cannot work when factory reset\n");
		rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1c), 0x4c000001);
	}
#if 1	//nec ir
	if(share_ir_tmp != ir_protocol) {
        printk("share_ir_tmp != ir_protocol!!!!!\n");
        if(ir_protocol == 8){
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xd), 0x8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xe), 0xf2a0d5);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xf), 0xfef010);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x10), 0xf300cf);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x11), 0xf310ce);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x12), 0xf320cd);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x13), 0xf330cc);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x14), 0xf340cb);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x15), 0xf350ca);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x16), 0xf360c9);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x17), 0xf370c8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x18), 0xf380c7);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x19), 0xf390c6);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1a), 0x0);
        }
		else if(ir_protocol == 19){
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xd), 0x13);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xe), 0x2ad59966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xf), 0x31ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x10), 0x32ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x11), 0x33ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x12), 0x34ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x13), 0x35ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x14), 0x36ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x15), 0x37ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x16), 0x38ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x17), 0x39ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x18), 0x30ce9966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x19), 0xef109966);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1a), 0x0);
		}
    }
#endif
    if(share_tmp == 0x10110000 || (((share_tmp&0x1FFF0000)==0x10110000) && share_irdaKey_tmp1==0 && share_irdaKey_tmp2==0)) {
	pr_alert("\n%s(%u)DC off, share memory may not set correctly by ap!!!\n",__func__,__LINE__);
        printk("pm_wake_ DC share memory may not set correctly by ap, using DC off default. warning!!!!!\n");
#if 1 // original AP default value
        rtd_outl(RTD_SHARE_MEM_BASE             ,0x2c0001);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1), 0x16000a);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x2), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x3), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x4), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x5), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x6), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x7), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x8), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x9), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xa), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xb), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xc), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xd), 0x8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xe), 0xf2a0d5);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xf), 0xfef010);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x10), 0xf300cf);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x11), 0xf310ce);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x12), 0xf320cd);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x13), 0xf330cc);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x14), 0xf340cb);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x15), 0xf350ca);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x16), 0xf360c9);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x17), 0xf370c8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x18), 0xf380c7);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x19), 0xf390c6);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1a), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1b), 0x3);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1c), 0x80000000);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1d), 0x400600);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1e), 0x400804);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1f), 0x0);
#endif
    }

    if(share_tmp == 0x10000000) {
	pr_alert("\n%s(%u)STR off, share memory may not set correctly by ap!!!\n",__func__,__LINE__);
        printk("pm_wake_ STR share memory may not set correctly by ap, using STR off default. warning!!!!!\n");
#if 1 // original AP default value
        rtd_outl(RTD_SHARE_MEM_BASE		, 0x101c0011);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1), 0x16000a);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x2), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x3), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x4), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x5), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x6), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x7), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x8), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x9), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xa), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xb), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xc), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xd), 0x8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xe), 0xf2a0d5);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xf), 0xfef010);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x10), 0xf300cf);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x11), 0xf310ce);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x12), 0xf320cd);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x13), 0xf330cc);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x14), 0xf340cb);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x15), 0xf350ca);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x16), 0xf360c9);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x17), 0xf370c8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x18), 0xf380c7);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x19), 0xf390c6);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1a), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1b), 0x3);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1c), 0x80000000);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1d), 0x400600);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1e), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1f), 0x0);
#else
        rtd_outl(RTD_SHARE_MEM_BASE		, 0x111c2011);   // 10sec wakeup
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1), 0x16000a);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x2), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x3), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x4), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x5), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x6), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x7), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x8), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x9), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xa), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xb), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xc), 0xa);	   // 10sec wakeup
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xd), 0x8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xe), 0xf2a0d5);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0xf), 0xfef010);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x10), 0xf300cf);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x11), 0xf310ce);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x12), 0xf320cd);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x13), 0xf330cc);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x14), 0xf340cb);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x15), 0xf350ca);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x16), 0xf360c9);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x17), 0xf370c8);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x18), 0xf380c7);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x19), 0xf390c6);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1a), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1b), 0x3);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1c), 0x80000000);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1d), 0x400600);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1e), 0x0);
        rtd_outl(RTD_SHARE_MEM_BASE+4*(0x1f), 0x0);
#endif
    }
#endif

    if(emcu_chk_event())
        BUG_ON(1);
    else
    wakeup_8051(flag);

    return 0;
}

extern int rtk_emcu_smem_set_ir(char *ibuf);
static int rtk_pm_load_8051_code(char *s)
{
    printk("\n%s(%u)2018/03/28 16:40\n",__func__,__LINE__);

    if((strlen(s) < 1) || rtk_emcu_smem_set_ir(s+1)){
        pr_alert("\n%s(%u)There are no IR key setting!!!\n",__func__,__LINE__);
        //BUG_ON(1);
    }

    #ifndef CONFIG_TV005
    rtk_pm_load_8051(0);
    #endif
    return 0;
}

static int rtk_pm_act_8051_code(char *s){
    printk("\n%s(%u)2013/04/08 11:50\n",__func__,__LINE__);
    #ifdef CONFIG_TV005
    // init IrDA
    rtd_outl(ISO_IRDA_IR_PSR_VADDR ,0x5a13133b);
    rtd_outl(ISO_IRDA_IR_PER_VADDR ,0x1162d);
    rtd_outl(ISO_IRDA_IR_SF_VADDR, 0xff00021b);
    rtd_outl(ISO_IRDA_IR_DPIR_VADDR ,0x1f4);
    rtd_outl(ISO_IRDA_IR_CR_VADDR ,0x5df);
    // load 8051
    rtk_pm_load_8051(0);
    #endif
    return 0;
}

__setup("POWERDOWN",rtk_pm_load_8051_code);
__setup("ac_on",    rtk_pm_act_8051_code);

/* end of file */
