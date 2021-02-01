//Copyright (C) 2007-2013 Realtek Semiconductor Corporation.
#include <linux/interrupt.h>
#include <asm/io.h>
#include "rbus/sb2_reg.h"
#include "rbus/emcu_reg.h"
#include "rbus/pll27x_reg_reg.h"
#include "rbus/stb_reg.h"
#include <linux/sched.h>
//#include <linux/ptrace.h>
#include <asm-generic/irq_regs.h>
#include <linux/nmi.h>
#include <rtk_kdriver/RPCDriver.h>
#include <rtk_sb2_callback.h>
#include <rtk_dc_mt.h>
#include <linux/module.h>

#ifdef CONFIG_REALTEK_RPC_KCPU
static struct semaphore send_sb2_emergency_intr_sem[(RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR];
#else
static struct semaphore send_sb2_emergency_intr_sem[(RPC_NR_KERN_DEVS)/RPC_NR_PAIR];
#endif

#ifdef CONFIG_ARM64
#include <mach/io.h>
#include <asm/system_misc.h>
#define hook_fault_code hook_debug_fault_code
#endif
#define FRED_START "\033[1;31;40m"
#define FGREEN_START "\033[1;32;40m"
#define FYELLOW_START "\033[1;33;40m"
#define FBLUE_START "\033[1;34;40m"
#define FCOLOR_END "\033[0m"

#define SB2DBG_LOG 1
#if SB2DBG_LOG
#define DBG_DFT(format, ...) printk(format, ##__VA_ARGS__)
#define DBG_YELLOW(format, ...) printk ( FYELLOW_START format FCOLOR_END, ##__VA_ARGS__)
#else
#define DBG_DFT(format, ...)
#define DBG_YELLOW(format, ...)
#endif

#define SB2_BLOCK_SET_NUM 4

//operation label
#define OPERA_MONITOR   0
#define OPERA_CLEAR     1
#define OPERA_HACKON    2 // hack cmd to enable all CPUs' Interrupt status
#define OPERA_HACKOFF   3 // hack cmd to restore all CPUs' Interrupt status
#define OPERA_BLOCK     4
#define OPERA_NONBLOCK  5
#define OPERA_TRAP_TOGGLE  6
//cpu enable/disable label
#define CPU_TYPE_ALL    0
#define CPU_TYPE_ACPU   1
#define CPU_TYPE_VCPU   2
#define CPU_TYPE_SCPU   3
#define CPU_TYPE_VCPU2  4
#define CPU_TYPE_KCPU   5
#define CPU_TYPE_ACPU2  6
//rw label
#define RW_FLAG_RW      0
#define RW_FLAG_RO      1
#define RW_FLAG_WO      2
#define RW_FLAG_DFT     RW_FLAG_RW
//str label
#define STR_FLAG_YES    0
#define STR_FLAG_NO     1
#define STR_FLAG_DFT    STR_FLAG_YES
//option param offset
#define OPT_RW          0
#define OPT_STR         1
//debug register offset
#define STRREG_INV_INTEN_reg    0
#define STRREG_INV_INTSTAT_reg  1
#define STRREG_DEBUG_REG_reg    2
#define STRREG_DBG_INT_reg      3

#define SB2_ALIGN_SIZE  4
typedef struct sb2dbg_bitmask
{
        unsigned int bit_mask;
        unsigned int raw_val;
        unsigned int reg_addr;
} sb2dbg_bitmask;

typedef struct sb2_dbg_param
{
        int set_id; // which set to be use,range 1-8
        unsigned int cpu_flag[7]; // which cpu type to be set,0:all 1:a v:2 s:3 v2:4 k:5
        unsigned int start; // dbg start address,phy addr
        unsigned int end; // dbg end address,phy addr
        unsigned char operation; // the main operation of sb2 cmd,0:monitor 1:clear
        unsigned char rw;  // read & write monitor flag
        unsigned char str; // STR support flag
        unsigned int bit_mask; // bit mask param
} sb2_dbg_param;

typedef struct sb2dbg_status_store
{
        unsigned int start_addr;
        unsigned int end_addr;
        unsigned int ctrl;
} sb2dbg_status_store;

typedef struct sb2block_status_store
{
        unsigned int ctrl;
        unsigned int start_addr[SB2_BLOCK_SET_NUM];
        unsigned int end_addr[SB2_BLOCK_SET_NUM];
} sb2block_status_store;

static unsigned int sb2dbg_tmp_reg[4];
static sb2dbg_status_store sb2dbg_reg_status[16];
static sb2dbg_bitmask sb2dbg_mask_status[16];
static sb2block_status_store sb2block_reg_status;
static unsigned int dbg_flag = 0;
static unsigned int str_support_flag = 0;
static unsigned int sb2hack_intr_bit = 0;
static int sb2_dbg_kernel_trap_warning = 1;  // change default to 1
static sb2_timeout_info timeout_info;
static int sb2_set_id = 1;
struct atomic_notifier_head sb2_notifier_list;
struct atomic_notifier_head sb2_notifier_list_cat;      //show register moudles

static const t_sb2_timout_moudle module_sb2_info[] = {        
//1800_000  - 1800_ffff
        {0x18000000, 0x18000fff, "Main Top System"}, 
        {0x18001000, 0x180017ff, "vde"}, 
        {0x18001800, 0x18001fff, "rng"},
        {0x18002000, 0x18002fff, "Audio Engine(AE/ADE)"},
        {0x18003000, 0x18003fff, "DC2_SYS"}, 
        {0x18004000, 0x18004fff, "DC2_PHY"}, 
        {0x18005000, 0x18005fff, "VODMA"}, 
        {0x18006000, 0x18006fff, "AIO"},                 
        {0x18007000, 0x18007fff, "DC_SYS"}, 
                
        {0x18008000, 0x18008fff, "DC_PHY"}, 
        {0x18009000, 0x18009fff, "ME"},             
        {0x1800A000, 0x1800Afff, "HDMI"}, 
        {0x1800B000, 0x1800Bfff, "MD"}, 
        {0x1800c000, 0x1800cfff, "SE"}, 
        {0x1800D000, 0x1800Dfff, "HDMI"}, 
        {0x1800e000, 0x1800ffff, "VE"}, 

//1801_000  - 1801_ffff
        //{0x18010000, 0x180107ff, "nand flash"}, 
        {0x18010800, 0x18010bff, "emmc"}, 
        //{0x18010c00, 0x18010fff, "SD"}, 
		{0x18012000, 0x18012fff, "USBEX"}, 
		{0x18013000, 0x18013fff, "USB"}, 
		
        {0x18014000, 0x18014fff, "TP"}, 
        {0x18015000, 0x18015fff, "CP"}, 
        {0x18016000, 0x18016fff, "ETN"}, 
        {0x18017000, 0x18017fff, "DP"}, 
                
        {0x18018000, 0x18019fff, "Video Decorder"}, 
        {0x1801A000, 0x1801Afff, "SB2"}, 
        {0x1801B000, 0x1801Bfff, "MISC"}, 
        {0x1801C000, 0x1801Cfff, "System Bridge"},   
        {0x1801D000, 0x1801Efff, "ARM"}, 
        {0x1801F000, 0x1801Ffff, "Video Encoder"}, 

//1802_000  - 1802_ffff
        {0x18020000, 0x18025fff, "DISPIM"}, 
        {0x18026000, 0x18026fff, "LVDS"},
        {0x18027000, 0x18027FFF, "DISPIM"},                
        {0x18028000, 0x1802ffff, "DISPD"},             

//1803_000  - 1803_ffff
        {0x18030000, 0x18030fff, "VBI Slicer"}, 
        {0x18031000, 0x18031FFF, "OSD_COMP"},   //1200 ~ 1fff : reserved
                
        {0x18032000, 0x18032fff, "IF DEMOD(Digital)"},
        {0x18033000, 0x18033fff, "IF DEMOD(Analog)"},
        {0x18034000, 0x180343ff, "VP9"}, 
        {0x18035000, 0x18036FFF, "VE2"},      
        {0x18037000, 0x18037FFF, "VDE2"},     

        {0x18038000, 0x18038fff, "efuse"}, 
        {0x18039000, 0x18039FFF, "MISC"},   
        {0x1803A000, 0x1803AFFF, "Audio Engine(AE2/ADE2)"},   
        {0x1803B000, 0x1803CFFF, "HDMI"},
        {0x1803D000, 0x1803D7FF, "hdmitx"},
        {0x1803D800, 0x1803DFFF, "disp2tve"},
        {0x1803E000, 0x1800EFFF, "SE"},         
        {0x1803F000, 0x1803FFFF, "ib(inter bridge)"},

//1804_000  - 1804_ffff
        //reserved

//1805_000  - 1805_ffff
        {0x18050000, 0x18058FFF, "USB3.0 HOST"},
        {0x18059000, 0x18059FFF, "DRAM Control"},
        {0x1805A000, 0x1805AFFF, "USB Wrapper"},
        {0x1805B000, 0x1805BFFF, "ARM(secure)"},
        {0x1805C000, 0x1805CFFF, "ARM(non-secure)"},
        {0x1805D000, 0x1805DFFF, "MIPS"},
        /* E000-Efff  reserved*/
        {0x1805F000, 0x1805FFFF, "USB3.0 HOST"},

//1806_000  - 1806_ffff
        {0x18060000, 0x18060FFF, "Satndby"},
        {0x18061000, 0x18062FFF, "ST PERI"},
        /* 3000-3fff  reserved*/
        {0x18064000, 0x18067FFF, "DI_DMA"},
        /* 8000-Afff  reserved*/
        {0x1806B000, 0x1806BFFF, "DOLBY_V"},
        {0x1806C000, 0x1806CFFF, "certid"},
        {0x1806D000, 0x1806DFFF, "KT"},
        {0x1806E000, 0x1806EFFF, "RSA(CP)"},
        {0x1806F000, 0x1806FFFF, "SCE"},

//1807_000  - 1807_ffff
        {0x18070000, 0x18072FFF, "demod wrapper"},
        /* 1000-Ffff  reserved*/

//1808_000  - 1808_ffff
        {0x18080000, 0x1808FFFF, "GIC"},   

//1809_000  - 1809_ffff
        {0x18090000, 0x18098FFF, "USB_OTG"},  
        {0x18099000, 0x1809FFFF, "MEMC"},    

//180A_000  - 180A_ffff
        {0x180A0000, 0x180AFFFF, "CCI"},   

//180B_000  - 180B_ffff
        {0x180B0000, 0x180B07FF, "DC_PHY_SECU"}, 
        //{0x180B0800, 0x180B0FFF, "DC2_PHY_SECU"},                
        {0x180B1000, 0x180B1FFF, "PST"},    //IMD scaler
        {0x180B2000, 0x180B2FFF, "HDMI"},    
        {0x180B3000, 0x180B3FFF, "DC_PATGEN"},    
		{0x180B4000, 0x180B4FFF, "HDMIEX"},    
        /* 4000-Ffff  reserved*/

//
        {0x180C0000, 0x180FFFFF, "demod core"}, 

//
        {0x18100000, 0x1813FFFF, "gpu"}, 
//
        {0x18140000, 0x1814FFFF, "hdic_dtmb"},
};



extern void dump_stacks(void);

int sb2_buserr_handler(unsigned long addr, unsigned int fsr, struct pt_regs *regs);
irqreturn_t sb2_block_intr(int irq, void *dev_id);

irqreturn_t sb2_intr(int irq, void *dev_id)
{
        int value = 0;

        //System CPU issued an invalid address access
        value = rtd_inl(SB2_INV_INTSTAT_reg);
        if(!(value & BIT(1)))
                return IRQ_NONE;

        // do handling in exneral abort and just clear interrupt pending here
        rtd_outl(SB2_INV_INTSTAT_reg, BIT(1));

        return IRQ_HANDLED;
}

int setup_irq(unsigned int irq, struct irqaction *act);
void __init sb2_intr_setup(void)
{
        /* Request IRQ */
        if(request_irq(IRQ_DCSYS,
                       sb2_intr,
                       IRQF_SHARED,
                       "SB2",
                       sb2_intr))
        {
                printk(KERN_ERR "SB2: cannot register IRQ %d\n", IRQ_DCSYS);
                return ;
        }

        hook_fault_code(8, sb2_buserr_handler, SIGBUS, 0, "external abort on bus error");
        hook_fault_code(0x16, sb2_buserr_handler, SIGBUS, 0, "external async abort on bus error");

        // use the maximum timeout value. (all are 65535T)
        rtd_setbits(SB2_DEBUG_REG_reg, BIT(8) | BIT(7) | BIT(6) | BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0));

        //clear Sciva_int
        rtd_outl(SB2_INV_INTSTAT_reg, BIT(1));

        //Enable To_en, To_en1, To_end(disp-relative)
        rtd_outl(SB2_INV_INTEN_reg, BIT(8) | BIT(5) | BIT(4) |  BIT(0));
        rtd_outl(SB2_INV_INTEN_reg, BIT(1) ); ////SCPU should hook exception handler, instead of interrupt...

        //Enable EMCU rbus timeout, and TO cycle = 32768T (bit[7..5] = 0x6).
        /* NOTICE, EMCU TO cycles should be shorter than SB2,
         * otherwise SB2 could be disturbed by occurrence of both faked bus ACK.
         */
        //Enable EMCU rbus timeout
        rtd_setbits(0xb8060400, BIT(7) | BIT(6) | BIT(2));


        printk("@sb2_intr_setup:    enable sb2 interrupt [reserved rbus address]\n");
}

int  get_SB2_DBG_START_register(int id)
{
        if(id < 8)
        {
                return (SB2_DBG_START_0_reg + id * 4);
        }
        else
        {
                return (SB2_DBG_START2_0_reg + (id - 8) * 4);
        }
}

int  get_SB2_DBG_END_register(int id)
{
        if(id < 8)
        {
                return (SB2_DBG_END_0_reg + id * 4);
        }
        else
        {
                return (SB2_DBG_END2_0_reg + (id - 8) * 4);
        }
}

int  get_SB2_DBG_CTRL_register(int id)
{
        if(id < 8)
        {
                return (SB2_DBG_CTRL_0_reg + id * 4);
        }
        else
        {
                return (SB2_DBG_CTRL3_0_reg + (id - 8) * 4);
        }
}

void string_cpy_coher(char * dst, char * src, int * pOff, int len)
{
        strcpy(&dst[*pOff], src);
        (*pOff) += len - 1; // drop last '\0'
}

void dump_help_info(void)
{
        pr_info("\nsb2 dbg cmd usage:\n");
        pr_info("1)set range: "FYELLOW_START"set{1-16} monitor {cpu_type1,cpu_type2,...} start_addr-end_addr [rw/r/w,str/nstr]\n"FCOLOR_END
                "\t usable cpu type:"FYELLOW_START"{acpu/vcpu/scpu/vcpu2/kcpu/acpu2}\n"FCOLOR_END
                "\t exp( full mode ): "FGREEN_START"echo \"set1 monitor scpu,acpu 18000000-18000010 rw,str\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END
                "\t exp(simple mode): "FGREEN_START"echo \"set1 monitor scpu,acpu 18000000-18000010 \">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END);
        pr_info("2)clear range: "FYELLOW_START"set{1-8} clear\n"FCOLOR_END
                "\t exp: "FGREEN_START"echo \"set1 clear\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END);
        pr_info("3)force enable/disalbe all cpus interrupt: "FYELLOW_START"set{1-8} hack_on/hack_off\n"FCOLOR_END
                "\t exp: "FGREEN_START"echo \"set1 hack_on\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END
                "\t exp: "FGREEN_START"echo \"set1 hack_off\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END);
        pr_info("4)block range(only block register write): "FYELLOW_START"set{1-4} block all start_addr-end_addr\n"FCOLOR_END
                "\t exp: "FGREEN_START"echo \"set1 block all 0x18000000-0x18001000\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END);
        pr_info("5)non-block range(register write): "FYELLOW_START"set{1-4} non-block \n"FCOLOR_END
                "\t exp: "FGREEN_START"echo \"set1 non-block\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END);
        pr_info("6)trap toggle: "FYELLOW_START"set{1-4} trap-toggle \n"FCOLOR_END
                "\t exp: "FGREEN_START"echo \"set1 trap-toggle\">/sys/realtek_boards/sb2_dbg\n"FCOLOR_END);
}
void dump_block_info(void)
{
        int i;
        unsigned int start_addr[SB2_BLOCK_SET_NUM] = {0};
        unsigned int end_addr[SB2_BLOCK_SET_NUM] = {0};
        unsigned int ctrl_val = rtd_inl(SB2_RBUS_INVA_ACC_CTRL_reg);
        unsigned int start_convert = 0;
        unsigned int end_convert = 0;

        start_addr[0] = rtd_inl(SB2_RBUS_INVA_ACC_SEC1_START_reg);
        end_addr[0] = rtd_inl(SB2_RBUS_INVA_ACC_SEC1_END_reg);
        start_addr[1] = rtd_inl(SB2_RBUS_INVA_ACC_SEC2_START_reg);
        end_addr[1] = rtd_inl(SB2_RBUS_INVA_ACC_SEC2_END_reg);
        start_addr[2] = rtd_inl(SB2_RBUS_INVA_ACC_SEC3_START_reg);
        end_addr[2] = rtd_inl(SB2_RBUS_INVA_ACC_SEC3_END_reg);
        start_addr[3] = rtd_inl(SB2_RBUS_INVA_ACC_SEC4_START_reg);
        end_addr[3] = rtd_inl(SB2_RBUS_INVA_ACC_SEC4_END_reg);

        printk("===sb2 block setting===\n");
        for(i = 0; i < SB2_BLOCK_SET_NUM; ++i)
        {
                start_convert = (start_addr[i] << 2) + 0x18000000;
                end_convert = (end_addr[i] << 2) + 0x18000000;
                pr_info("[%02d] [%08x - %08x] check %s\n", i + 1, start_convert, end_convert,
                        (ctrl_val & 1 << (i * 2)) ? "enable" : "disable");
        }
}

void dump_set_info(void)
{
        int i;
        char cpu_enables[128] = {0};
        int cpu_str_cnt = 0;
        //char* cpu_enable;
        char*read_write[] = {"R/W", "read", "write", "R/W"};
        char*data_instruction[] = {"data and instruction", "data", "instruction", "data and instruction"};
        char*str_support[] = {"non-STR", "STR"};
        unsigned int ctrl_reg;
        unsigned int start_reg;
        unsigned int end_reg;
        unsigned int ctrl_reg_value;
        unsigned int start_reg_value;
        unsigned int end_reg_value;

        pr_err("===sb2 dbg setting===\n");
        for (i = 0; i < 16; i++)
        {
                memset(cpu_enables, '\0', sizeof(cpu_enables));
                cpu_str_cnt = 0;
                ctrl_reg = get_SB2_DBG_CTRL_register(i);
                start_reg = get_SB2_DBG_START_register(i);
                end_reg = get_SB2_DBG_END_register(i);
                // DBG_YELLOW("%d: ctrl_reg(0x%x): 0x%x, start_reg(0x%x): 0x%x,  end_reg(0x%x): 0x%x\n",  i+1, ctrl_reg,rtd_inl(ctrl_reg), start_reg,rtd_inl(start_reg),end_reg,rtd_inl(end_reg));

                ctrl_reg_value =  rtd_inl(ctrl_reg);
                start_reg_value =  rtd_inl(start_reg);
                end_reg_value =  rtd_inl(end_reg);

                if ((ctrl_reg_value & BIT(12)) && (ctrl_reg_value & BIT(10)) && (ctrl_reg_value & BIT(8)) && (ctrl_reg_value & BIT(16)) && (ctrl_reg_value & BIT(14)) && (ctrl_reg_value & BIT(18)))
                {
                        string_cpy_coher(cpu_enables, "[all]", &cpu_str_cnt, sizeof("[all]"));
                }
                else
                {
                        if (ctrl_reg_value & BIT(12))
                        {
                                string_cpy_coher(cpu_enables, "[A]", &cpu_str_cnt, sizeof("[A]"));
                        }
                        if (ctrl_reg_value & BIT(10))
                        {
                                string_cpy_coher(cpu_enables, "[V]", &cpu_str_cnt, sizeof("[V]"));
                        }
                        if (ctrl_reg_value & BIT(8))
                        {
                                string_cpy_coher(cpu_enables, "[S]", &cpu_str_cnt, sizeof("[S]"));
                        }
                        if (ctrl_reg_value & BIT(14))
                        {
                                //string_cpy_coher(cpu_enables, "[V2]", &cpu_str_cnt, sizeof("[V2]"));

                        }
                        if (ctrl_reg_value & BIT(16))
                        {
                                string_cpy_coher(cpu_enables, "[K]", &cpu_str_cnt, sizeof("[K]"));
                        }

                        if (ctrl_reg_value & BIT(18))
                        {
                                //string_cpy_coher(cpu_enables, "[A2]", &cpu_str_cnt, sizeof("[A2]"));
                        }
                        if (cpu_str_cnt == 0)
                        {
                                string_cpy_coher(cpu_enables, "no cpu", &cpu_str_cnt, sizeof("no cpu"));
                        }
                }
                cpu_enables[sizeof(cpu_enables) - 1] = '\0';
                pr_err("[%02d] [%08x - %08x] %16s check enable,%8s,mask %08x,monitor %s (%s)\n", i + 1,
                       rtd_inl(get_SB2_DBG_START_register(i)),
                       rtd_inl(get_SB2_DBG_END_register(i)),
                       cpu_enables,
                       str_support[str_support_flag >> i & 0x1],
                       sb2dbg_mask_status[i].bit_mask,
                       data_instruction[ctrl_reg_value >> 2 & 0x3],
                       read_write[ctrl_reg_value >> 5 & 0x3]);
        }
        pr_err("===sb2 dbg setting===\n");
        pr_err("DBG_CTRL2:(0x%08x) = 0x%08x\n",SB2_DBG_CTRL2_reg,rtd_inl(SB2_DBG_CTRL2_reg));
        pr_err("DBG_INT:(0x%08x) = 0x%08x\n",SB2_DBG_INT_reg,rtd_inl(SB2_DBG_INT_reg));
     
}

void dump_sb2dbg_regval(void)
{
        int i;
        pr_err("%08x=%08x SB2_INV_INTEN\n", SB2_INV_INTEN_reg, rtd_inl(SB2_INV_INTEN_reg));
        pr_err("%08x=%08x SB2_INV_INTSTAT\n", SB2_INV_INTSTAT_reg, rtd_inl(SB2_INV_INTSTAT_reg));
        pr_err("%08x=%08x SB2_DEBUG_REG\n", SB2_DEBUG_REG_reg, rtd_inl(SB2_DEBUG_REG_reg));
        pr_err("%08x=%08x SB2_DBG_INT\n", SB2_DBG_INT_reg, rtd_inl(SB2_DBG_INT_reg));

        for (i = 0; i < 8; i++)
        {
                pr_err("------set%02d------\n", i + 1);
                pr_err("[set%02d]%08x=%08x SB2_DBG_START\n", i + 1, SB2_DBG_START_0_reg + i * 4, rtd_inl(SB2_DBG_START_0_reg + i * 4));
                pr_err("[set%02d]%08x=%08x SB2_DBG_END\n", i + 1, SB2_DBG_END_0_reg + i * 4, rtd_inl(SB2_DBG_END_0_reg + i * 4));
                pr_err("[set%02d]%08x=%08x SB2_DBG_CTRL\n", i + 1, SB2_DBG_CTRL_0_reg + i * 4, rtd_inl(SB2_DBG_CTRL_0_reg + i * 4));
        }
        for (i = 8; i < 16; i++)
        {
                pr_err("------set%02d------\n", i + 1);
                pr_err("[set%02d]%08x=%08x SB2_DBG_START2\n", i + 1, SB2_DBG_START2_0_reg + (i - 8) * 4, rtd_inl(SB2_DBG_START2_0_reg + (i - 8) * 4));
                pr_err("[set%02d]%08x=%08x SB2_DBG_END2\n", i + 1, SB2_DBG_END2_0_reg + (i - 8) * 4, rtd_inl(SB2_DBG_END_0_reg + (i - 8) * 4));
                pr_err("[set%02d]%08x=%08x SB2_DBG_CTRL3\n", i + 1, SB2_DBG_CTRL3_0_reg + (i - 8) * 4, rtd_inl(SB2_DBG_CTRL3_0_reg + (i - 8) * 4));
        }
}

void dump_sb2block_regval(void)
{
        int i;
        pr_err("%08x=%08x SB2_RBUS_INVA_ACC_CTRL\n", SB2_RBUS_INVA_ACC_CTRL_reg, rtd_inl(SB2_RBUS_INVA_ACC_CTRL_reg));
        pr_err("%08x=%08x SB2_BL_CPU\n", SB2_BL_CPU_reg, rtd_inl(SB2_BL_CPU_reg));
        pr_err("%08x=%08x SB2_INTSTAT_SCPU\n", SB2_INTSTAT_SCPU_reg, rtd_inl(SB2_INTSTAT_SCPU_reg));

        for (i = 0; i < 4; i++)
        {
                pr_err("------set%02d------\n", i + 1);
                pr_err("[set%02d]%08x=%08x SB2_BLOCK_START\n", i + 1, SB2_RBUS_INVA_ACC_SEC1_START_reg + i * 8, rtd_inl(SB2_DBG_START_0_reg + i * 8));
                pr_err("[set%02d]%08x=%08x SB2_BLOCK_END\n", i + 1, SB2_RBUS_INVA_ACC_SEC1_END_reg + i * 8, rtd_inl(SB2_DBG_END_0_reg + i * 8));
        }
}

void dump_sb2dbg_misc_info(void)
{
        pr_err("sb2_dbg_kernel_trap_warning toggle to %d\n", sb2_dbg_kernel_trap_warning);
}

void sb2_rbus_timeout_info(void)
{
        pr_err("\n Reset related settings 0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x\n",
               SYS_REG_SYS_SRST0_reg, rtd_inl(SYS_REG_SYS_SRST0_reg),
               SYS_REG_SYS_SRST1_reg, rtd_inl(SYS_REG_SYS_SRST1_reg),
               SYS_REG_SYS_SRST2_reg, rtd_inl(SYS_REG_SYS_SRST2_reg),
               SYS_REG_SYS_SRST3_reg, rtd_inl(SYS_REG_SYS_SRST3_reg));
        pr_err("\n Clock related settings 0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x\n",
               SYS_REG_SYS_CLKEN0_reg, rtd_inl(SYS_REG_SYS_CLKEN0_reg),
               SYS_REG_SYS_CLKEN1_reg, rtd_inl(SYS_REG_SYS_CLKEN1_reg),
               SYS_REG_SYS_CLKEN2_reg, rtd_inl(SYS_REG_SYS_CLKEN2_reg),
               SYS_REG_SYS_CLKEN3_reg, rtd_inl(SYS_REG_SYS_CLKEN3_reg));

        if (rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_pllreg_mask)
        {
                pr_err("\n PLL27X_REG. settings 0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x\n",
                       PLL27X_REG_SYS_PLL_27X1_reg, rtd_inl(PLL27X_REG_SYS_PLL_27X1_reg),
                       PLL27X_REG_SYS_PLL_27X2_reg, rtd_inl(PLL27X_REG_SYS_PLL_27X2_reg),
                       PLL27X_REG_SYS_PLL_27X3_reg, rtd_inl(PLL27X_REG_SYS_PLL_27X3_reg),
                       PLL27X_REG_SYS_PLL_27X4_reg, rtd_inl(PLL27X_REG_SYS_PLL_27X4_reg));
        }

        pr_err("\n Clock sel. settings  0x%08x:0x%08x\n",
               SYS_REG_SYS_CLKSEL_reg, rtd_inl(SYS_REG_SYS_CLKSEL_reg));

        pr_err("\n Uart clock related register dump  0x%08x:0x%08x 0x%08x:0x%08x 0x%08x:0x%08x \n\n",
               PLL27X_REG_SYS_PLL_AUD3_reg, rtd_inl(PLL27X_REG_SYS_PLL_AUD3_reg),
               STB_ST_CLKEN0_reg, rtd_inl(STB_ST_CLKEN0_reg),
               STB_ST_SRST0_reg, rtd_inl(STB_ST_SRST0_reg));

        return;
}
//get one moudle 
static int get_sb2_moudle_name(t_sb2_timout_moudle *module_info,  int moudle_num,unsigned long reg,char* str,int offset)
{ 
        int i=0;
        //int moudle_num = sizeof(module_sb2_info)/sizeof(t_sb2_timout_moudle);

        memset(str, 0, MODULE_NAME_LEN_MAX);
        for(i = offset;i < moudle_num; i++){
                if((reg>= module_info[i].addr_start) && (reg<= module_info[i].addr_end))
                {
                        //pr_err("(%s)[%lx-%lx]\n",module_info[i].name,module_info[i].addr_start, module_info[i].addr_end);
                        snprintf(str,MODULE_NAME_LEN_MAX,"%s",module_info[i].name);
                        offset = i+1;
                        return offset;
                }
        }
        return -1;
}

static int search_sb2_moudle_name(t_sb2_timout_moudle *module_info, unsigned long reg, char * str, int moudle_num, int buffsize)
{
        int i,pos = 0;
        int offset = 0;
        int found = 0;
        char sb2_moudle_name[MODULE_NAME_LEN_MAX] = {0};
        
        memset(str, 0, buffsize);
        for(i=0;i< moudle_num;i++){
                offset = get_sb2_moudle_name(module_info,moudle_num, reg, sb2_moudle_name, offset);
                if(offset == -1){
                        break;
                }

                if(pos<buffsize-1){
                        snprintf(str+pos, buffsize-pos, "[%s]", sb2_moudle_name);
                        pos = pos + strlen(sb2_moudle_name) + 2;
                }
                found = 1;      //get moudle

        }
        if(found == 0){         //no match moudle
                return -1;
        }

        return 0;

}

//get all mathc  moudle 
static int get_sb2_moudle_all(unsigned long reg,char* str,int buffsize)
{ 
        int moudle_num = sizeof(module_sb2_info)/sizeof(t_sb2_timout_moudle);
        //int moudle_simple_num = sizeof(module_sb2_info_simple)/sizeof(t_sb2_timout_moudle);

        if(search_sb2_moudle_name(module_sb2_info, reg, str, moudle_num, buffsize) == 0){
                return 0;
        }
        #if 0
        else if(search_sb2_moudle_name(module_sb2_info_simple, reg, str, moudle_simple_num, buffsize) == 0){
                return 1;
        }
        #endif        
        snprintf(str, buffsize, "[%s]", "Unknown");
        return -1;
}


unsigned long buserr_ignored_addr = _UNSET_;
extern int do_rbusto_fake_read(unsigned long addr, unsigned int fsr, struct pt_regs *regs);

static int sb2_buserr_ignore(unsigned long addr)
{
	if ((addr == (volatile unsigned long)buserr_ignored_addr) ||
	    (_ANY_ == (volatile unsigned long)buserr_ignored_addr))
		return 1;
	
	return 0;
}


int sb2_buserr_handler(unsigned long addr, unsigned int fsr, struct pt_regs *regs)
{
        int sb2_intstat = 0;
        int emcu_to_stat = 0;
        struct siginfo info;
        char sb2_moudle_name_all[64] = {0};

        //System CPU issued an invalid address access
        sb2_intstat = rtd_inl(SB2_INV_INTSTAT_reg);
        emcu_to_stat = rtd_inl(0xb8060400) & (0xf << 28);

        /* check sb2 timeout or emcu timeout */
        if(!(sb2_intstat & BIT(1)) && (emcu_to_stat == 0))
                return 1;

	/* check address that could be ignored. */
	if (sb2_buserr_ignore(addr)) {
		// ack timeout state 
		if (sb2_intstat & BIT(1))
		{
			rtd_outl(SB2_INV_INTSTAT_reg, BIT(1)); //write out clear
		}

		// return 0xdeaddead for read instruction
		if ((fsr & BIT(11)) == 0) { 
			if (do_rbusto_fake_read(addr, fsr, regs) != 0) 
				goto bus_err;
			else
				return 0;
		}

		// ignore OK, and go forward
		regs->ARM_pc += 4;
		return 0;
	}
	
bus_err:
        timeout_info.isTimeout = 1;
        timeout_info.timeout_reg = rtd_inl(SB2_INV_ADDR_reg);

        if(console_loglevel < 5)
        {
                console_loglevel = 5;
        }

        get_sb2_moudle_all(timeout_info.timeout_reg, sb2_moudle_name_all, sizeof(sb2_moudle_name_all));

        pr_err("\nYou have accessed an reserved register address :   \e[1;31m0x%x\e[0m \e[1;34m%s\e[0m\n\n", rtd_inl(SB2_INV_ADDR_reg), sb2_moudle_name_all);
        pr_err("\n Timeout status 0x%08x:0x%08x, 0xb8060400:0x%08x \n", SB2_INV_INTSTAT_reg, rtd_inl(SB2_INV_INTSTAT_reg), rtd_inl(0xb8060400));

        // ack timeout state and print debug info
        if (sb2_intstat & BIT(1))
        {
                rtd_outl(SB2_INV_INTSTAT_reg, BIT(1)); //write out clear
                sb2_rbus_timeout_info();
        }

        //force to trigger a kernel panic in kernel mode
        panic_on_oops = 1;


        if ((fsr & 0x1800) == 0x1800)   // imprecise write abort
        {
                addr = rtd_inl(SB2_INV_ADDR_reg) - 0x18000000 + RBUS_BASE_VIRT;
                ///regs->ARM_pc -= 8;
        }

        pr_alert("\n\nrbus timeout:  (0x%03x) at 0x%08lx \n",  fsr, addr);
        if ((fsr & 0x1800) == 0x1800)   // imprecise write abort
        {
                printk("This imprecise data abort is due to rbus write transaction timeout. \n");
                printk("Please add a dsb() immediately after each rbus 0x%08x write transaction, and test again. \n", addr);
                printk("When exception happening, DSB will stop and indicate which rbus write is invalid. \n\n\n");
        }

        atomic_notifier_call_chain(&sb2_notifier_list, 0, NULL);
        memset(&timeout_info, 0, sizeof(timeout_info));

        return 1;
}

irqreturn_t sb2_dbg_intr (int irq, void *dev_id)
{
        int value = 0;
        unsigned int dbg_addr = 0;
        void* v_addr = NULL;
        unsigned int v_addr_value = 0;
        unsigned int int_setting = 0;
        int data_instruction;
        int write_read;
        int loop_cnt = 0;
        int i;
        unsigned int trash_reg;
        unsigned int trash_val;
        unsigned int trash_mask_val;
        unsigned int cmp_val;
        unsigned char old_loglevel;

        //SCPU or ACPU,VCPU issued an invalid address access
        value = rtd_inl(SB2_DBG_INT_reg);
        //DBG_DFT("rtd_inl(SB2_DBG_INT_reg);: 0x%x", rtd_inl(SB2_DBG_INT_reg));
        if(!(value & BIT(10)))   //TODO:ALL CPU INTR BIT
        {
                return IRQ_NONE;
        }

        old_loglevel = console_loglevel;
        if(old_loglevel < 5)
        {
                console_loglevel = 5;
        }

        dbg_addr = rtd_inl(SB2_DBG_ADDR_2_reg);
        //check bit monitor start
        for(i = 0; i < 16; ++i)
        {
                if((sb2dbg_mask_status[i].bit_mask) && (dbg_addr == sb2dbg_mask_status[i].reg_addr))
                {
                        trash_reg = dbg_addr | 0xa0000000;
                        trash_val =  rtd_inl(trash_reg);
                        trash_mask_val = trash_val & (~sb2dbg_mask_status[i].bit_mask);
                        cmp_val = sb2dbg_mask_status[i].raw_val & (~sb2dbg_mask_status[i].bit_mask);

                        if(trash_mask_val == cmp_val)
                        {
                                rtd_outl(SB2_DBG_INT_reg, BIT(10));
                                DBG_YELLOW("bit mask continue minitor!\n");
                                return IRQ_HANDLED;
                        }
                        else
                        {
                                DBG_YELLOW("[Memory trash]SB2DBG bit minitor:val changed to 0x%08x@0x%08x,raw 0x%08x,mask 0x%08x\n",
                                           trash_val, dbg_addr, sb2dbg_mask_status[i].raw_val, sb2dbg_mask_status[i].bit_mask);
                        }
                }
        }
        //check bit monitor finish
        data_instruction = rtd_inl(SB2_DBG_ADDR1_reg)&BIT(2);
        write_read = rtd_inl(SB2_DBG_ADDR1_reg)&BIT(3);
        pr_err("\n[Memory trash](%s) SCPU have %s %s invalid.  SB2 reserved address is \e[1;31m0x%x\e[0m\n\n",
               __FUNCTION__, write_read ? "write" : "read", data_instruction ? "data" : "instruction",
               dbg_addr);

        pr_err("[Memory trash]dump_stacks\n");
        dump_stacks();//dump stack
        pr_err("\n\n\n\n\n");

        if((dbg_addr < 0x18000000) || (dbg_addr >= 0x19000000))
        {
                v_addr = ioremap(dbg_addr, 4);
                //DBG_DFT(" v_addr :  0x%x\n", v_addr);
                v_addr_value = rtd_inl((long unsigned int)v_addr);
                iounmap(v_addr);
        }
        else
        {
                v_addr = dbg_addr|0xa0000000;
                v_addr_value = rtd_inl((long unsigned int)v_addr);
        }

        for(loop_cnt = 0; loop_cnt < 2; ++loop_cnt)
        {
                pr_err("\n\n\n\nLoop dump info %d/%d\n", loop_cnt + 1, 3);
                pr_err("[Memory trash] grep value:"FYELLOW_START"0x%08x"FCOLOR_END"@"FRED_START"0x%08x"FCOLOR_END"\n", v_addr_value, dbg_addr);
                dump_set_info();
                dump_sb2dbg_regval();
                //sb2_rbus_timeout_info();
        }

        //clear the SB2 scpu dbg interrupt flag
        rtd_outl(SB2_DBG_INT_reg, BIT(10));
        pr_debug("SB2_DBG_INT_reg=%x\n", rtd_inl(SB2_DBG_INT_reg));
        if(sb2_dbg_kernel_trap_warning == 1)
        {

                panic("[Memory trash] SB2 dbg monitor detected ... \n");

        }
        console_loglevel = old_loglevel;
        return IRQ_HANDLED;
}

int find_free_dbg_register (void)
{
        int i;

        for (i = 0; i < 16; i++)
        {
                if( (dbg_flag >> i & 0x1) == 0)
                {
                        return i;
                }
        }
        return -1;
}

// cpu_id -->   0:all 1:a 2:v 3:s 4:v2 5:k 6:a2
// 1800_0000~1810_0000  rbus  0000_0000~1800_0000   dbus
int sb2_dbg_clear (sb2_dbg_param *pParam)
{
        int set_id = pParam->set_id;
        int id = set_id - 1;
        unsigned int str_id = pParam->str;

        unsigned int ctrl_reg;
        unsigned int sb2dbg_final_clear = BIT(17) | BIT(13) | BIT(11) | BIT(9) | BIT(7) | BIT(4);

        if(id < 0)
        {
                pr_err("sb2 dbg set failed, invalid argument - dbg set id is %d\n", set_id);
                return -1;
        }

        ctrl_reg = get_SB2_DBG_CTRL_register(id);

        rtd_outl(ctrl_reg, sb2dbg_final_clear);

        DBG_YELLOW("%d: reg(0x%x): 0x%x, sb2dbg_final_clear:0x%x\n",  id + 1, ctrl_reg, rtd_inl(ctrl_reg), sb2dbg_final_clear);
        dbg_flag = dbg_flag & (~(1 << id));
        if(str_id == STR_FLAG_YES)
        {
                str_support_flag = str_support_flag & (~(1 << id));
        }
        return 0;
}

// cpu_id -->   0:all 1:a 2:v 3:s 4:v2 5:k 6:a2
// 1800_0000~1810_0000  rbus  0000_0000~1800_0000   dbus
int sb2_dbg_monitor (sb2_dbg_param *pParam)
{

        unsigned int start = pParam->start;
        unsigned int end = pParam->end;
        unsigned int *cpu_id = pParam->cpu_flag;
        int set_id = pParam->set_id;
        unsigned int rw_id = pParam->rw;
        unsigned int str_id = pParam->str;
        int i = 0;
        //debug set 1 for scpu access invalid rbus register test:  0x1805_d000 ~ 0x1805_e000

        unsigned int start_reg;
        unsigned int end_reg;
        unsigned int ctrl_reg;
        unsigned int dbg_recnt = 0x3;

        unsigned int bitmoni_reg;

        // 0:all 1:a 2:v 3:s 4:v2 5:k 6:a2
        unsigned int cpu_set_bit[7] =
        {
                BIT(17) | BIT(16) | BIT(13) | BIT(12) | BIT(11) | BIT(10) | BIT(9) | BIT(8),
                BIT(13) | BIT(12),
                BIT(11) | BIT(10),
                BIT(9) | BIT(8),
                0,
                BIT(17) | BIT(16),
                0,
        };
        // 0:rw 1:r 2:w
        unsigned int rw_set_bit[3] =
        {
                BIT(7) | BIT(6) | BIT(5),
                BIT(7) | BIT(5),
                BIT(7) | BIT(6)
        };
        // 0:data&instruction 1:data 2:instruction
        unsigned int di_set_bit[3] =
        {
                BIT(4) | BIT(3) | BIT(2),
                BIT(4) | BIT(2),
                BIT(4) | BIT(3)
        };

        unsigned int cpu_final_set_bit = 0;
        unsigned int sb2dbg_final_set = 0;
        unsigned int sb2dbg_final_clear = BIT(17) | BIT(13) | BIT(11) | BIT(9) | BIT(7) | BIT(4);

#if 0
        int id = find_free_dbg_register();
#else
        int id = set_id - 1;
        if((id < 0) || (id > 15))
        {
                pr_err("sb2 dbg set failed, invalid argument - dbg set id is %d\n", set_id);
                return -1;
        }
#endif

        start_reg = get_SB2_DBG_START_register(id);
        end_reg = get_SB2_DBG_END_register(id);
        ctrl_reg = get_SB2_DBG_CTRL_register(id);


        rtd_outl(ctrl_reg, sb2dbg_final_clear); //clear dbg range first
        rtd_outl(start_reg, start);  //set dbg range
        rtd_outl(end_reg, end);
        //set cpu types
        for(i = 0; i < 7; ++i)
        {
                //DBG_YELLOW("i:%d cpu_set_bit[i]: %x\n", i, cpu_set_bit[i]);

                if(cpu_id[i])
                {
                        cpu_final_set_bit |= cpu_set_bit[i];
                        //DBG_YELLOW("i:%d cpu_final_set_bit: %x\n", i, cpu_final_set_bit);
                }
        }

        if(pParam->bit_mask)
        {
                if((start == end) && (rw_id == RW_FLAG_WO))
                {
                        bitmoni_reg = start | 0xa0000000;
                        sb2dbg_mask_status[id].reg_addr = start;
                        sb2dbg_mask_status[id].bit_mask = pParam->bit_mask;
                        sb2dbg_mask_status[id].raw_val = rtd_inl(bitmoni_reg);
                        DBG_YELLOW("sb2dbg_bit_mask[%d](1-16): %x,val: %x\n", id + 1, sb2dbg_mask_status[id].bit_mask, sb2dbg_mask_status[id].raw_val);
                }
                else
                {
                        pr_err("bit-mask set failed,expected:(start == end)&&(rw_id == RW_FLAG_WO)\n");
                        return -1;
                }
        }
        else
        {
                sb2dbg_mask_status[id].bit_mask = 0;
                sb2dbg_mask_status[id].raw_val = 0;
        }
        sb2dbg_final_set = cpu_final_set_bit | rw_set_bit[rw_id] | di_set_bit[0] | dbg_recnt;
        //DBG_YELLOW("sb2dbg_final_set: %x\n", sb2dbg_final_set);
        rtd_outl(ctrl_reg, sb2dbg_final_set);



        //DBG_YELLOW("%d: sb2dbg_final_set: 0x%x, start: 0x%x,  end:0x%x\n",  id+1, sb2dbg_final_set, start, end);

        //DBG_YELLOW("%d: ctrl_reg(0x%x): 0x%x, start_reg(0x%x): 0x%x,  end_reg(0x%x): 0x%x\n",  id+1, ctrl_reg,rtd_inl(ctrl_reg), start_reg,rtd_inl(start_reg),end_reg,rtd_inl(end_reg));

        dbg_flag = dbg_flag | (1 << id);
        if(str_id == STR_FLAG_YES)
        {
                str_support_flag = str_support_flag | (1 << id);
        }
        else
        {
                str_support_flag = str_support_flag & (~(1 << id));
        }
        sb2_set_id = (set_id%16) +1;
        return 0;
}



//c0108000 T _text IRQ_DCSYS IRQ_SECURE_SB2
extern char _text[], _stext[], _etext[];
void __init sb2_dbg_intr_setup (void)
{
        /* Request IRQ */
        if(request_irq(IRQ_DCSYS,
                       sb2_dbg_intr,
                       IRQF_SHARED,
                       "SB2_DBG",
                       sb2_dbg_intr))
        {
                printk(KERN_ERR "SB2 DBG: cannot register IRQ %d\n", IRQ_SECURE_SB2);
                return ;
        }

        //enable sb2 dbg interrupt
        rtd_outl(SB2_DBG_INT_reg, (BIT(7) | BIT(0)));

        printk("@sb2_dbg_intr_setup:    enable sb2 dbg interrupt [reserved rbus OR dbus address]\n");
}

void __init sb2_dbg_latch_setup (void)
{
        //only latches first illegal address
        //rtd_outl(SB2_DBG_CTRL2_reg, (BIT(5) | BIT(4) | BIT(3) | BIT(2) | BIT(1) | BIT(0)));

        //latche each illegal address
        rtd_outl(SB2_DBG_CTRL2_reg, 0);
}

//cat /sys/realtek_boards/sb2_dbg
void sb2_dbg_get (void)
{
        dump_help_info();
        dump_set_info();
        dump_block_info();
        dump_sb2dbg_misc_info();
}

//echo "10800000,10c97000,no_match_in_range,ALL" > /sys/realtek_boards/sb2_dbg
//echo "18061500,18061600,match_in_range,scpu" > /sys/realtek_boards/sb2_dbg
void dump_sb2_dbg_param(sb2_dbg_param * pParam)
{
        DBG_DFT("\ndump sb2 dbg setting cmd:\n");
        DBG_DFT("set_id:%d\n", pParam->set_id);
        DBG_DFT("option:%d (0:monitor 1:clear 2:hack_on 3:hack_off 4:block)\n", pParam->operation);
        DBG_DFT("cpu flag:(all:%d a:%d v:%d s:%d v2:%d k:%d a2:%d)\n",
                pParam->cpu_flag[0], pParam->cpu_flag[1], pParam->cpu_flag[2],
                pParam->cpu_flag[3], pParam->cpu_flag[4], pParam->cpu_flag[5], pParam->cpu_flag[6]);
        DBG_DFT("start addr:0x%08x\n", pParam->start);
        DBG_DFT("end addr:0x%08x\n", pParam->end);
        DBG_DFT("rw flag:%d(0:rw 1:r 2:w)\n", pParam->rw);
        DBG_DFT("str flag:%s\n", (pParam->str == STR_FLAG_YES) ? "Support STR" : "Not support STR");
}

int get_cputype_id(const char * cpu)
{
        int return_id = -1;
        if (strcmp(cpu, "all") == 0)
        {
                return_id = CPU_TYPE_ALL;
        }
        else if (strcmp(cpu, "acpu") == 0)
        {
                return_id = CPU_TYPE_ACPU;
        }
        else if (strcmp(cpu, "vcpu") == 0)
        {
                return_id = CPU_TYPE_VCPU;
        }
        else if (strcmp(cpu, "scpu") == 0)
        {
                return_id = CPU_TYPE_SCPU;
        }
        else if (strcmp(cpu, "vcpu2") == 0)
        {       
                pr_err("invalid cpu type - %s\n", cpu);
                return_id = -1;
        }
        else if (strcmp(cpu, "kcpu") == 0)
        {
                return_id = CPU_TYPE_KCPU;
        }
        else if (strcmp(cpu, "acpu2") == 0)
        {
                pr_err("invalid cpu type - %s\n", cpu);
                return_id = -1;
        }
        else
        {
                pr_err("invalid cpu type - %s\n", cpu);
                return -1;
        }

        return return_id;
}

int split_str(char * str, char split_flag, char out_str[][16], int max_cnt)
{
        int num = 0;
        int i;
        int start;
        int end;
        if((str == NULL) || (out_str == NULL))
        {
                return -1;
        }
        //get strings
        for(start = 0, end = 0; str[end] != '\0'; ++end)
        {
                if(str[end] == split_flag)
                {
                        if(start < end)   // if any char between start-end range;
                        {
                                for(i = 0; start < end; start++, i++)   // copy string
                                {
                                        out_str[num][i] = str[start];
                                }
                                start = end + 1; //ignore the split str;
                                num++;
                                if(num >= max_cnt)
                                {
                                        return num;
                                }
                        }
                        else
                        {
                                start = end + 1; //ignore the split str;
                        }
                }
        }
        //get last string
        if(start < end)   // if any char between start-end range;
        {
                for(i = 0; start < end; start++, i++)
                {
                        out_str[num][i] = str[start];
                }
                num++;
        }

        return num;
}

int parse_set_field(char * field_str, sb2_dbg_param * pParam)
{
        if((field_str == NULL) || (pParam == NULL))
        {
                pr_err("set_field is NULL\n");
                return -1;
        }

        if (sscanf(field_str, "set%d", &pParam->set_id) < 1)
        {
                pr_err("parse set_field fail!\n");
                return -1;
        }
        if((pParam->set_id <= 0) || (pParam->set_id > 16))
        {
                pr_err("unexpected set id,expected range[1-16]!\n");
                return -1;
        }

        return 0;
}

int parse_operation_field(char * field_str, sb2_dbg_param * pParam)
{
        if((field_str == NULL) || (pParam == NULL))
        {
                pr_err("operation_field is NULL\n");
                return -1;
        }

        if(strcmp(field_str, "monitor") == 0)
        {
                pParam->operation = OPERA_MONITOR;
        }
        else if(strcmp(field_str, "clear") == 0)
        {
                pParam->operation = OPERA_CLEAR;
        }
        else if(strcmp(field_str, "hack_on") == 0)
        {
                pParam->operation = OPERA_HACKON;
        }
        else if(strcmp(field_str, "hack_off") == 0)
        {
                pParam->operation = OPERA_HACKOFF;
        }
        else if(strcmp(field_str, "block") == 0)
        {
                pParam->operation = OPERA_BLOCK;
        }
        else if(strcmp(field_str, "non-block") == 0)
        {
                pParam->operation = OPERA_NONBLOCK;
        }
        else if(strcmp(field_str, "trap-toggle") == 0)
        {
                pParam->operation = OPERA_TRAP_TOGGLE;
        }
        else
        {
                pr_err("unexpected operation:%s!\n", field_str);
                return -1;
        }

        return 0;
}

int parse_cpu_field(char * field_str, sb2_dbg_param * pParam)
{
        char cpu_str[7][16] = {{0}};
        int cpu_num = 0;
        int cpu_id = 0;
        int i;

        memset(cpu_str, '\0', sizeof(cpu_str));

        if((field_str == NULL) || (pParam == NULL))
        {
                pr_err("cpu_field is NULL\n");
                return -1;
        }

        //only monitor need cpu_field
        if(pParam->operation != OPERA_MONITOR)   // non-monitor operation don't need this field.
        {
                return 0;
        }

        cpu_num = split_str(field_str, ',', cpu_str, 7);
        if((cpu_num <= 0) || (cpu_num > 7))   //no cpu or too many cpus
        {
                pr_err("unexpected cpu type num,expected between [1-7],actual:%d!\n", cpu_num);
                return -1;
        }
        for(i = 0; i < cpu_num; ++i)   //parse cpu id
        {
                cpu_str[i][15] = '\0';
                cpu_id = get_cputype_id(&cpu_str[i][0]);
                if(cpu_id != -1)
                {
                        pParam->cpu_flag[cpu_id] = 1;
                }
        }

        return 0;
}

int parse_range_field(char * field_str, sb2_dbg_param * pParam)
{
        char addr_str[2][16] = {{0}};

        memset(addr_str, '\0', sizeof(addr_str));

        //check input
        if((field_str == NULL) || (pParam == NULL))
        {
                pr_err("range_field is NULL\n");
                return -1;
        }

        if((pParam->operation != OPERA_MONITOR) && (pParam->operation != OPERA_BLOCK))   // non-monitor operation don't need this field.
        {
                return 0;
        }

        if(split_str(field_str, '-', addr_str, 2) != 2)
        {
                pr_err("unexpected addr param,excepted start_addr-end_addr!\n");
                return -1;
        }

        addr_str[0][15] = '\0';
        if(sscanf(&addr_str[0][0], "%x", &pParam->start) < 1)
        {
                pr_err("parse start range fail\n");
                return -1;
        }

        addr_str[1][15] = '\0';
        if(sscanf(&addr_str[1][0], "%x", &pParam->end) < 1)
        {
                pr_err("parse end range fail\n");
                return -1;
        }
        if((pParam->start) > (pParam->end))
        {
                pr_err("sb2 set fail, MT start range:0x%08x > end range:0x%08x\n",pParam->start,pParam->end);    
        }
        return 0;
}

int parse_rw_flag(char * flag_str, sb2_dbg_param * pParam)
{
        if(flag_str == NULL)
        {
                pParam->rw = RW_FLAG_DFT;//default value
                return 0;
        }

        if(strcmp(flag_str, "r") == 0)
        {
                pParam->rw = RW_FLAG_RO;
        }
        else if(strcmp(flag_str, "w") == 0)
        {
                pParam->rw = RW_FLAG_WO;
        }
        else if(strcmp(flag_str, "rw") == 0)
        {
                pParam->rw = RW_FLAG_RW;
        }
        else
        {
                pr_err("unexpected rw param!\n");
                return -1;
        }

        return 0;
}

int parse_str_flag(char * flag_str, sb2_dbg_param * pParam)
{
        if(flag_str == NULL)
        {
                pParam->str = STR_FLAG_DFT;//default value
                return 0;
        }

        if(strcmp(flag_str, "str") == 0)
        {
                pParam->str = STR_FLAG_YES;
        }
        else if(strcmp(flag_str, "nstr") == 0)
        {
                pParam->str = STR_FLAG_NO;
        }
        else
        {
                pr_err("unexpected str param!\n");
                return -1;
        }

        return 0;
}

int parse_opt_field(char * field_str, sb2_dbg_param * pParam)
{
        char opt_param[4][16] = {{0}};

        memset(opt_param, '\0', sizeof(opt_param));
        //check input
        if((field_str == NULL) || (pParam == NULL))
        {
                pr_err("opt_field is NULL\n");
                return -1;
        }
        if(field_str[0] == '\0')   //use default param
        {
                pParam->rw = RW_FLAG_DFT;
                pParam->str = STR_FLAG_DFT;
                return 0;
        }
        //split&parse flags
        if(split_str(field_str, ',', opt_param, 2) != 2)
        {
                pr_err("too less option param,expected:[rw,str]!\n");
                return -1;
        }
        //get read/write flag
        opt_param[OPT_RW][15] = '\0';
        if(parse_rw_flag(opt_param[OPT_RW], pParam))
        {
                pr_err("parse opt_field:rw_flag fail\n");
                return -1;
        }

        //get str flag
        opt_param[OPT_STR][15] = '\0';
        if(parse_str_flag(opt_param[OPT_STR], pParam))
        {
                pr_err("parse opt_field:str_flag fail\n");
                return -1;
        }

        return 0;
}

int parse_bit_field(char * field_str, sb2_dbg_param * pParam)
{
        if(pParam->operation != OPERA_MONITOR)   // non-monitor operation don't need this field.
        {
                return 0;
        }

        if(sscanf(field_str, "%x", &pParam->bit_mask) < 1)
        {
                pr_err("no bit mask value, use default value 0\n");
                pParam->bit_mask = 0;   //use default value
                //return -1;
        }

        return 0;
}

void opera_hackon(void)
{
        printk("Dbg intr bit now:0x%08x\n", rtd_inl(SB2_DBG_INT_reg));
        if(sb2hack_intr_bit == 0)   // check if not hack_on now...
        {
                sb2hack_intr_bit = rtd_inl(SB2_DBG_INT_reg);
                rtd_outl(SB2_DBG_INT_reg, BIT(19) | BIT(9) | BIT(8) | (BIT(7) | BIT(0)));
                printk("Hack ON Finish.Dbg Intr bit:0x%08x\n", rtd_inl(SB2_DBG_INT_reg));
        }
        else     // if hack_on already
        {
                printk("Hack operation is ON already.Do nothing for now.\n");
        }
}

void opera_hackoff(void)
{
        printk("Dbg intr bit now:0x%08x\n", rtd_inl(SB2_DBG_INT_reg));
        if(sb2hack_intr_bit != 0)   // check if not hack_off now...
        {
                printk("sb2hack_intr_bit:0x%08x\n", sb2hack_intr_bit);
                rtd_outl(SB2_DBG_INT_reg, (~sb2hack_intr_bit) & (~BIT(0)));
                printk("Hack OFF Finish.Dbg Intr bit:0x%08x\n", rtd_inl(SB2_DBG_INT_reg));
                sb2hack_intr_bit = 0;
        }
        else     // if hack_off already
        {
                printk("Hack operation is OFF already.Do nothing for now.\n");
        }
}

void opera_trap_toggle(void)
{
        if(sb2_dbg_kernel_trap_warning == 1)
        {
                sb2_dbg_kernel_trap_warning = 0;
        }
        else
        {
                sb2_dbg_kernel_trap_warning = 1;
        }

        printk("sb2_dbg_kernel_trap_warning toggle to %d\n", sb2_dbg_kernel_trap_warning);
}

int parse_cmdline(const char * buffer, sb2_dbg_param * pParam)
{
        char set_field[8] = {0};
        char operation_field[8] = {0};
        char cpu_field[48] = {0};
        char range_field[24] = {0};
        char opt_field[24] = {0};
        char bit_field[16] = {0};

        if((buffer == NULL) || (pParam == NULL))
        {
                pr_err("use NULL input param!\n");
                goto Fail;
        }

        DBG_DFT("sb2_dbg receive cmd:%s\n", buffer);
        //get options
        if (sscanf(buffer, "%s %s %s %s %s %s", set_field, operation_field, cpu_field, range_field, opt_field, bit_field) < 1)
        {
                pr_err("get cmdline fail!\n");
                goto Fail;
        }

        if(parse_set_field(set_field, pParam))
        {
                pr_err("parse set_field fail!\n");
                goto Fail;
        }

        if(parse_operation_field(operation_field, pParam))
        {
                pr_err("parse operation_field fail!\n");
                goto Fail;
        }

        if(parse_cpu_field(cpu_field, pParam))
        {
                pr_err("parse cpu_field fail!\n");
                goto Fail;
        }

        if(parse_range_field(range_field, pParam))
        {
                pr_err("parse range_field fail!\n");
                goto Fail;
        }

        if(parse_opt_field(opt_field, pParam))
        {
                pr_err("parse opt_field fail!\n");
                goto Fail;
        }

        if(parse_bit_field(bit_field, pParam))
        {
                pr_err("parse bit_field fail!\n");
                goto Fail;
        }

        return 0;

Fail:
        pr_err("[sb2 debug driver]parse param fail!\n");
        return -1;
}

int sb2_block_set_range(unsigned int id, unsigned int start, unsigned int end)
{
        unsigned int ctrl_val = rtd_inl(SB2_RBUS_INVA_ACC_CTRL_reg);

        id -= 1;
        //check id
        if(id >= 4)
                return -1;

        //check range: between 0x1800_0000-0x1840_0000 or 0xB800_0000_0xB840_0000
        if(((start >= 0x18000000) && (start <= 0x18400000)) || ((start >= 0xB8000000) && (start <= 0xB8400000)))
        {
                start = start >> 2;
        }
        else
        {
                pr_err("sb2 block, start address(0x%08x) error!\n", start);
                return -1;
        }
        if(((end >= 0x18000000) && (end <= 0x18400000)) || ((end >= 0xB8000000) && (end <= 0xB8400000)))
        {
                end = end >> 2;
        }
        else
        {
                pr_err("sb2 block, start address(0x%08x) error!\n", start);
                return -1;
        }

        switch(id)
        {
                case 0:
                        ctrl_val &= ~BIT(0);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC1_START_reg, start);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC1_END_reg, end);
                        ctrl_val |= BIT(0);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        break;
                case 1:
                        ctrl_val &= ~BIT(2);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC2_START_reg, start);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC2_END_reg, end);
                        ctrl_val |= BIT(2);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        break;
                case 2:
                        ctrl_val &= ~BIT(4);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC3_START_reg, start);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC3_END_reg, end);
                        ctrl_val |= BIT(4);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        break;
                case 3:
                        ctrl_val &= ~BIT(6);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC4_START_reg, start);
                        rtd_outl(SB2_RBUS_INVA_ACC_SEC4_END_reg, end);
                        ctrl_val |= BIT(6);
                        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
                        break;
                default:
                        break;
        }

        rtd_outl(SB2_INTEN_SCPU_reg, (BIT(1) | BIT(0)));
        return 0;
}

void sb2_block_clear_range(unsigned int id)
{
        unsigned int ctrl_val = rtd_inl(SB2_RBUS_INVA_ACC_CTRL_reg);

        id -= 1;
        //check id
        if(id >= 4)
                return;

        switch(id)
        {
                case 0:
                        ctrl_val &= ~BIT(0);
                        break;
                case 1:
                        ctrl_val &= ~BIT(2);
                        break;
                case 2:
                        ctrl_val &= ~BIT(4);
                        break;
                case 3:
                        ctrl_val &= ~BIT(6);
                        break;
                default:
                        break;
        }
        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, ctrl_val);
}

/***************************RBUS BLOCKING FUNCTION*****************************/
/*total 4 set
**ctrl : SB2_RBUS_INVA_ACC_CTRL_reg
**start/end 4 set
       SB2_RBUS_INVA_ACC_SEC1_START_reg
       SB2_RBUS_INVA_ACC_SEC1_END_reg
**block cpu
       SB2_BL_CPU_reg
**intr enable
       SB2_INTEN_SCPU_reg
**intr inform scpu
       SB2_INTSTAT_SCPU_reg
*/

irqreturn_t sb2_block_intr(int irq, void *dev_id)
{
        int value = 0;
        unsigned char block_cpu = 0;
        unsigned int block_addr = 0;

        char* str_cpu[16] =
        {
                "kcpu",
                "acpu",
                "acpu2",
                "vcpu",
                "vcpu2",
                "scpu",
                "uart",
                "8051",
                "HIF",
                "demod",
                "rbusdma",
                "none",
                "unknown",
                "unknown",
                "unknown",
                "unknown"
        };

        //System CPU blocking intr status
        value = rtd_inl(SB2_INTSTAT_SCPU_reg);
        if(!(value & BIT(1)))
        {
                return IRQ_NONE;
        }

        //get block cpu id & addr
        value = rtd_inl(SB2_BL_CPU_reg);
        block_cpu = (value >> 24) & 0x0f;
        block_addr = value & 0x0fffff;

        //clear intr bit
        printk("[Memory Trash] sb2 block cpu:%d(%s), addr:block_addr(20bit):0x%08x\n", block_cpu, str_cpu[block_cpu], block_addr);
        rtd_outl(SB2_INTSTAT_SCPU_reg, (BIT(1) | BIT(0)));

        dump_stacks();//dump stack first
        dump_sb2block_regval();
        sb2_rbus_timeout_info();

        panic("[Memory trash] SB2 dbg block detected ... \n");

        return IRQ_HANDLED;
}

void __init sb2_block_intr_setup(void)
{
        /* Request IRQ */
        if(request_irq(IRQ_DCSYS,
                       sb2_block_intr,
                       IRQF_SHARED,
                       "SB2_BLOCK",
                       sb2_block_intr))
        {
                printk(KERN_ERR "SB2: cannot register IRQ %d\n", IRQ_DCSYS);
                return ;
        }

        //enable sb2 block interrupt
        rtd_outl(SB2_INTEN_SCPU_reg, (BIT(1) | BIT(0)));

        printk("@sb2_block_intr_setup:    enable sb2 block interrupt\n");
}

int sb2_dbg_block (sb2_dbg_param *pParam)
{
        return sb2_block_set_range(pParam->set_id, pParam->start, pParam->end);
}

void sb2_dbg_nonblock (sb2_dbg_param *pParam)
{
        sb2_block_clear_range(pParam->set_id);
}

#define isnumber(c)      (c>=0x30 && c<=0x39)
#define isalphabet(c)    (c>=0x41 && c<=0x5A) || (c>=0x61 && c<=0x7A)
#define isalnum(c)       (isnumber(c) || isalphabet(c))
static char* __find_next_str(char* str)
{
    char* end = str + strlen(str);

    while(str < end) {
        if (isalnum(*str)) // is alphabet or number
            return str;
        str++;
    }

    return NULL;
}

static int get_arguments(char* str, int argc, char** argv)
{
    int ret = 0;
    char* sep;

    while ((str = __find_next_str(str)) && ret < argc) {
        argv[ret++] = str;
        //DC_MT_INFO("arg[%d]='%s'\n", ret, str);
        sep = strchr(str, ','); // devided by

        if (sep == NULL)
            break;

        *sep = '\0'; // changed to null terminated
        //DC_MT_INFO("**** arg[%d]='%s'\n", ret, str);
        str = sep + 1;

    }

    return ret;
}
static void print_reg_match_info(unsigned long  reg)
{        
        char sb2_moudle_name_all[64] = {0};
        
        get_sb2_moudle_all(reg, sb2_moudle_name_all, sizeof(sb2_moudle_name_all));
        pr_err("register(%lx) matched moudles: %s\n", reg, sb2_moudle_name_all);
}

static void print_moudle_match_info(char * str)
{        
        //char sb2_moudle_name_all[64] = {0};
        int moudle_num = sizeof(module_sb2_info)/sizeof(t_sb2_timout_moudle);
        int i,num=1;
        
        for(i=0; i<moudle_num; i++){
                //if(strncpy(str, module_sb2_info[i].name, strlen(str)) == 0){
                if(strcmp(str, module_sb2_info[i].name) == 0){
                        pr_err("moudle(%s) matched reg[%d]: [0x%lx-0x%x]\n", str,num, module_sb2_info[i].addr_start, module_sb2_info[i].addr_end);
                        num++;
                }
        }
}

static int is_moudle_reg_match(char * str, unsigned long  reg)
{
        int i = 0;
        int moudle_num = sizeof(module_sb2_info)/sizeof(t_sb2_timout_moudle);
        
        for(i = 0;i < moudle_num; i++){
                if((reg >= module_sb2_info[i].addr_start) && (reg <= module_sb2_info[i].addr_end))
                {
                        //pr_warning("moudel_name=%s\n",module_sb2_info[i].name);

                        if(strcmp(module_sb2_info[i].name, str)==0){
                                //pr_warning("match moudel_name=%s\n",module_sb2_info[i].name);
                                return 0;
                        }        
                }
        }  
        return -1;//means match fail
        
}
static int callback_cmd_error(char * str)
{
        pr_err("####CALLBACK ERROR!!!####\n");
        pr_err("%s\n", str);
        return -2;
}
static int callback_cat_list(char* str)
{
        if(strncmp(str,"show_func", strlen("show_func"))==0){
                pr_err("----------SB2_TIMEOUT REGISTERED MOUDLES------------\n");
                atomic_notifier_call_chain(&sb2_notifier_list_cat, 0, NULL);
                pr_err("----------SB2_TIMEOUT SHOW MOUDLUES END-------------\n");
                return 0;
        }else{              
                return -1;
        }
}
//echo "callback SB2,1801a6f4"> /sys/realtek_boards/sb2_dbg
//echo "callback show_func"> /sys/realtek_boards/sb2_dbg
//return: -1:fail not callback cmd, 0:success, other: fail but is callback cmd
static int parse_sb2_callback_cmd(const char * buffer)
{
        int ret = 0;
        char* argv[2];
        char* cmd = NULL;
        int argc =0; 

        if(strncmp(buffer, "callback", strlen("callback")) != 0){       
                return -1;
        }
        cmd = __find_next_str((char*)buffer + strlen("callback"));
        if(cmd == NULL){
                return callback_cmd_error("Lack param");

        }
        argc = get_arguments((char*)cmd, 2, argv);

        if(callback_cat_list(argv[0]) == 0){    //command : cat
                return 0;
        }
        if(argc < 2){   //command less 2
                return callback_cmd_error("Lack param");    
        }

        memset(&timeout_info,0,sizeof(timeout_info));//clear timeout info
        timeout_info.isTimeout = 1;
        if (sscanf(argv[1], "%lx", &timeout_info.timeout_reg) != 1) {
                ret = callback_cmd_error("set callback parameter failed, parse reg address failed\n");
                goto RET;
        }
        
        if(is_moudle_reg_match(argv[0], timeout_info.timeout_reg) == -1){ //moudle name not match register
                pr_err("####CALLBACK ERROR!!!####\n");
                pr_err("%s and %lx not match\n",argv[0], timeout_info.timeout_reg);
                print_reg_match_info(timeout_info.timeout_reg);
                print_moudle_match_info(argv[0]);
                ret = -3;
                goto RET;
        }

        atomic_notifier_call_chain(&sb2_notifier_list, 0, NULL);
RET:
        memset(&timeout_info,0,sizeof(timeout_info));//clear timeout info
        return ret;
}

int parse_sb2_show_last_set(const char * buffer)
{
        char cpu_enables[128] = {0};
        int cpu_str_cnt = 0;
        //char* cpu_enable;
        char*read_write[] = {"R/W", "read", "write", "R/W"};
        char*data_instruction[] = {"data and instruction", "data", "instruction", "data and instruction"};
        char*str_support[] = {"non-STR", "STR"};
        unsigned int ctrl_reg;
        unsigned int start_reg;
        unsigned int end_reg;
        unsigned int ctrl_reg_value;
        unsigned int start_reg_value;
        unsigned int end_reg_value;
        unsigned int last_set_id = ((sb2_set_id-1)?(sb2_set_id-1):16) ;
        int i;
        
        if(strncmp(buffer, "show_set", strlen("show_set")) != 0)
        {
                return -1;
        }
        pr_err("===sb2 dbg setting===\n");
        for (i = 0; i < 16; i++)
        {
                memset(cpu_enables, '\0', sizeof(cpu_enables));
                cpu_str_cnt = 0;
                ctrl_reg = get_SB2_DBG_CTRL_register(i);
                start_reg = get_SB2_DBG_START_register(i);
                end_reg = get_SB2_DBG_END_register(i);
                // DBG_YELLOW("%d: ctrl_reg(0x%x): 0x%x, start_reg(0x%x): 0x%x,  end_reg(0x%x): 0x%x\n",  i+1, ctrl_reg,rtd_inl(ctrl_reg), start_reg,rtd_inl(start_reg),end_reg,rtd_inl(end_reg));

                ctrl_reg_value =  rtd_inl(ctrl_reg);
                start_reg_value =  rtd_inl(start_reg);
                end_reg_value =  rtd_inl(end_reg);

                if ((ctrl_reg_value & BIT(12)) && (ctrl_reg_value & BIT(10)) && (ctrl_reg_value & BIT(8)) && (ctrl_reg_value & BIT(16)) && (ctrl_reg_value & BIT(14)) && (ctrl_reg_value & BIT(18)))
                {
                        string_cpy_coher(cpu_enables, "[all]", &cpu_str_cnt, sizeof("[all]"));
                }
                else
                {
                        if (ctrl_reg_value & BIT(12))
                        {
                                string_cpy_coher(cpu_enables, "[A]", &cpu_str_cnt, sizeof("[A]"));
                        }
                        if (ctrl_reg_value & BIT(10))
                        {
                                string_cpy_coher(cpu_enables, "[V]", &cpu_str_cnt, sizeof("[V]"));
                        }
                        if (ctrl_reg_value & BIT(8))
                        {
                                string_cpy_coher(cpu_enables, "[S]", &cpu_str_cnt, sizeof("[S]"));
                        }
                        if (ctrl_reg_value & BIT(14))
                        {
                                string_cpy_coher(cpu_enables, "[V2]", &cpu_str_cnt, sizeof("[V2]"));

                        }
                        if (ctrl_reg_value & BIT(16))
                        {
                                string_cpy_coher(cpu_enables, "[K]", &cpu_str_cnt, sizeof("[K]"));
                        }

                        if (ctrl_reg_value & BIT(18))
                        {
                                string_cpy_coher(cpu_enables, "[A2]", &cpu_str_cnt, sizeof("[A2]"));
                        }
                        if (cpu_str_cnt == 0)
                        {
                                string_cpy_coher(cpu_enables, "no cpu", &cpu_str_cnt, sizeof("no cpu"));
                        }
                }
                cpu_enables[sizeof(cpu_enables) - 1] = '\0';
                if((i+1) == last_set_id){
                        pr_err("\e[1;33m[%02d] [%08x - %08x] %16s check enable,%8s,mask %08x,monitor %s (%s)\e[0m\n", i + 1,

                               rtd_inl(get_SB2_DBG_START_register(i)),
                               rtd_inl(get_SB2_DBG_END_register(i)),
                               cpu_enables,
                               str_support[str_support_flag >> i & 0x1],
                               sb2dbg_mask_status[i].bit_mask,
                               data_instruction[ctrl_reg_value >> 2 & 0x3],
                               read_write[ctrl_reg_value >> 5 & 0x3]);
                }else{
                        pr_err("[%02d] [%08x - %08x] %16s check enable,%8s,mask %08x,monitor %s (%s)\n", i + 1,
                               rtd_inl(get_SB2_DBG_START_register(i)),
                               rtd_inl(get_SB2_DBG_END_register(i)),
                               cpu_enables,
                               str_support[str_support_flag >> i & 0x1],
                               sb2dbg_mask_status[i].bit_mask,
                               data_instruction[ctrl_reg_value >> 2 & 0x3],
                               read_write[ctrl_reg_value >> 5 & 0x3]);

                }
        }
                
        return 0;

}

//------------------------format----------------------------
// echo "set_id monitor cpu_type1,cpu_type2,... start_addr-end_addr r/w/rw,str/nstr"  > /sys/realtek_boards/sb2_dbg
// echo "set_id clear"  > /sys/realtek_boards/sb2_dbg
// echo "set_id hack_on/hack_off"  > /sys/realtek_boards/sb2_dbg       (don't care about set_id value actually.)
//----------------------format end--------------------------
//echo "set7 monitor acpu,scpu 18061500-18061600 rw,str" > /sys/realtek_boards/sb2_dbg
void sb2_dbg_set (const char *buffer)
{
        sb2_dbg_param param;

        if(parse_sb2_callback_cmd(buffer) != -1){        //parse callback cmd ok
                return;
        }
		
        if(parse_sb2_show_last_set(buffer) != -1)
        {
                return;
        }
        memset(&param, 0, sizeof(param));
        if(parse_cmdline(buffer, &param) == 0)
        {
                dump_sb2_dbg_param(&param);
                if(param.operation == OPERA_MONITOR)
                {
                        // set dbg range
                        if(sb2_dbg_monitor(&param))
                        {
                                pr_err("sb2_dbg_set fail!\n");
                                goto Fail;
                        }
                }
                else if(param.operation == OPERA_CLEAR)
                {
                        // clear dbg range
                        if(sb2_dbg_clear(&param))
                        {
                                pr_err("sb2_dbg_clear fail!\n");
                                goto Fail;
                        }
                }
                else if(param.operation == OPERA_HACKON)
                {
                        opera_hackon();
                }
                else if(param.operation == OPERA_HACKOFF)
                {
                        opera_hackoff();
                }
                else if(param.operation == OPERA_BLOCK)
                {
                        if(sb2_dbg_block(&param))
                        {
                                pr_err("sb2_dbg_block fail!\n");
                                goto Fail;
                        }
                }
                else if(param.operation == OPERA_NONBLOCK)
                {
                        sb2_dbg_nonblock(&param);
                }
                else if(param.operation == OPERA_TRAP_TOGGLE)
                {
                        opera_trap_toggle();
                }
                else
                {
                        goto Fail;
                }
        }
        else
        {
                goto Fail;
        }

        /*
            if(set_sb2_dbg_arange(start,end,cpu_id,set_id)==0)
            {
                printk("sb2 dbg set OK\n");
                return;
            }
        */
        return ;

Fail:
        pr_err("sb2 dbg set fail\n");
        return ;
}

#define MONITOR_DCMT_ENABLE 0x1   //dcmt bit0
#define MONITOR_SB2_ENABLE 0x2   //sb2 bit1
#define MONITOR_ARM_WRAPER_ENABLE 0x4   //arm_wraper bit2

#ifdef CONFIG_REALTEK_ARM_WRAPPER
extern int get_arm_wraper_set_id(void);
#endif

//buf: [rbus_start  rbus_size  config_status  sb2_set_id  arm_set_id] 
void hw_monitor_get_status(char * buf, int bufsize)
{
        int config_status = 0;
        int arm_wraper_set_id =0;

        #ifdef CONFIG_RTK_KDRV_DC_MEMORY_TRASH_DETCTER
                config_status = config_status |MONITOR_DCMT_ENABLE;
        #endif

        #ifdef  CONFIG_RTK_KDRV_SB2
                config_status= config_status |MONITOR_SB2_ENABLE;
        #endif

        #ifdef CONFIG_REALTEK_ARM_WRAPPER
                config_status = config_status |MONITOR_ARM_WRAPER_ENABLE;
                arm_wraper_set_id = get_arm_wraper_set_id();
        #endif

        snprintf(buf, bufsize, "%lx %lx %d %d %d ", RBUS_BASE_PHYS, RBUS_BASE_SIZE, config_status, sb2_set_id, arm_wraper_set_id);// one more ' '
}

void sb2_emergency_intr_clear(void)
{
    // Disable the interrupt from system to audio & video
	rtd_outl(SB2_NMI_CPU_INT_EN_reg, (SB2_NMI_CPU_INT_EN_int_sa_en_mask ));
	rtd_outl(SB2_NMI_CPU_INT_EN_reg, (SB2_NMI_CPU_INT_EN_int_sv_en_mask ));
#ifdef CONFIG_REALTEK_RPC_KCPU
	rtd_outl(SB2_NMI_CPU_INT_EN_reg, (SB2_NMI_CPU_INT_EN_int_sk_en_mask ));
#endif
}

void sb2_emergency_intr_enable(void)
{
    // Enable the interrupt from system to audio & video
	rtd_outl(SB2_NMI_CPU_INT_EN_reg, (SB2_NMI_CPU_INT_EN_int_sa_en_mask | SB2_NMI_CPU_INT_EN_write_data_mask));
	rtd_outl(SB2_NMI_CPU_INT_EN_reg, (SB2_NMI_CPU_INT_EN_int_sv_en_mask | SB2_NMI_CPU_INT_EN_write_data_mask));
#ifdef CONFIG_REALTEK_RPC_KCPU
	rtd_outl(SB2_NMI_CPU_INT_EN_reg, (SB2_NMI_CPU_INT_EN_int_sk_en_mask | SB2_NMI_CPU_INT_EN_write_data_mask));
#endif
}

void sb2_emergency_intr_setup(void)
{
	int i;
#ifdef CONFIG_REALTEK_RPC_KCPU
	for (i = 0; i < (RPC_NR_KERN_DEVS+RPC_NR_KERN_KCPU_DEVS)/RPC_NR_PAIR; i++)
#else
	for (i = 0; i < RPC_NR_KERN_DEVS/RPC_NR_PAIR; i++)
#endif
	{
		sema_init(&send_sb2_emergency_intr_sem[i], 1);
	}

	sb2_emergency_intr_enable();
}

int sb2_emergency_intr_wait_done(unsigned int maskbit)
{
	unsigned int timeout =  jiffies + HZ*SB2_EMERGENCY_INT_TIMEOUT;
	int done = 0;

	while(time_before(jiffies, timeout))
	{
		if((rtd_inl(SB2_NMI_CPU_INT_reg) & maskbit) == 0x0) //done
		{
			done = 1;
			break;
		}
	}
	return done;
}
void sb2_emergency_intr_send(unsigned int opt,unsigned int command, unsigned int parameter)
{

	unsigned int enableMask;
	unsigned int *share_buf;

	if( opt == RPC_AUDIO)
	{
		enableMask = SB2_NMI_CPU_INT_int_sa_mask;
	}
	else if( opt == RPC_VIDEO)
	{
		enableMask = SB2_NMI_CPU_INT_int_sv_mask;
	}
#ifdef CONFIG_REALTEK_RPC_KCPU
	else if( opt == RPC_KCPU)
	{
		enableMask = SB2_NMI_CPU_INT_int_sk_mask;
	}
#endif
	else
	{
		 pr_err("Not support type(%d) @ %s\n", opt, __FUNCTION__);
		 return;
	}

	down(&send_sb2_emergency_intr_sem[opt]);
	share_buf = (unsigned int *)phys_to_virt(SB2_EMERGENCY_INT_BUFF_ADDR+ opt * SB2_EMERGENCY_INT_BUFF_COMMAND_SIZE);
	share_buf[0] = command;
	share_buf[1] = parameter;
	rtd_outl(SB2_NMI_CPU_INT_reg, (enableMask | SB2_NMI_CPU_INT_write_data_mask));

	if(!sb2_emergency_intr_wait_done(enableMask))
	{
		 pr_err("Send emergency interrupt to (%d) but no ack. Com(%d),Parameter(%d ) @%s\n",
		 	opt, command, parameter, __FUNCTION__);

		 //clear interrupt
		 rtd_outl(SB2_NMI_CPU_INT_reg, (enableMask ));
	}
	up(&send_sb2_emergency_intr_sem[opt]);
}
void sb2_emergency_intr_send_all(void)
{
	pr_err("Issue  sb2_emergency_intr_send_all\n");
	rtd_outl(SB2_NMI_CPU_INT_reg, (SB2_NMI_CPU_INT_int_sa_mask | SB2_NMI_CPU_INT_write_data_mask));
	rtd_outl(SB2_NMI_CPU_INT_reg, (SB2_NMI_CPU_INT_int_sv_mask | SB2_NMI_CPU_INT_write_data_mask));
	rtd_outl(SB2_NMI_CPU_INT_reg, (SB2_NMI_CPU_INT_int_sk_mask | SB2_NMI_CPU_INT_write_data_mask));
}
void restore_sb2dbg_init_setting(void)
{
        // use the maximum timeout value
        rtd_setbits(SB2_DEBUG_REG_reg, sb2dbg_tmp_reg[STRREG_DEBUG_REG_reg]);
        //clear Sciva_int
        //rtd_outl(SB2_INV_INTSTAT_reg, sb2dbg_tmp_reg[STRREG_INV_INTSTAT_reg] | BIT(0));
        //Enable scivairq_en, To_en, To_en1
        rtd_outl(SB2_INV_INTEN_reg, sb2dbg_tmp_reg[STRREG_INV_INTEN_reg] | BIT(0));
        rtd_outl(SB2_INV_INTEN_reg, BIT(1) ); //avoid bootcode to enable SCPU int.
        //enable sb2 dbg interrupt
        rtd_outl(SB2_DBG_INT_reg, sb2dbg_tmp_reg[STRREG_DBG_INT_reg] | BIT(0));
}

void restore_sb2dbg_status(void)
{
        int i;
        unsigned int start_addr = 0;
        unsigned int end_addr = 0;
        unsigned int ctrl = 0;
        unsigned int start_reg = 0;
        unsigned int end_reg = 0;
        unsigned int ctrl_reg = 0;
        unsigned int rw_write_bit = BIT(7);
        unsigned int di_write_bit = BIT(4);
        unsigned int dbg_recnt = 0x3;
        unsigned int sb2dbg_cpu_write = BIT(17) | BIT(13) | BIT(11) | BIT(9);
        unsigned int sb2dbg_final_set = 0;
        unsigned int sb2dbg_final_clear = BIT(17) | BIT(13) | BIT(11) | BIT(9) | BIT(7) | BIT(4);

        restore_sb2dbg_init_setting();

        for (i = 0; i < 16; i++)
        {
                if(str_support_flag & (0x1 << i))
                {
                        start_addr = sb2dbg_reg_status[i].start_addr;
                        end_addr = sb2dbg_reg_status[i].end_addr;
                        ctrl = sb2dbg_reg_status[i].ctrl;

                        start_reg = get_SB2_DBG_START_register(i);
                        end_reg = get_SB2_DBG_END_register(i);
                        ctrl_reg = get_SB2_DBG_CTRL_register(i);

                        sb2dbg_final_set = sb2dbg_cpu_write | rw_write_bit | di_write_bit | ctrl | dbg_recnt;

                        rtd_outl(ctrl_reg, sb2dbg_final_clear);
                        rtd_outl(start_reg, start_addr);
                        rtd_outl(end_reg, end_addr);
                        rtd_outl(ctrl_reg, sb2dbg_final_set);
                }
                else //if not support str,clear bit-monitor
                {
                        sb2dbg_mask_status[i].raw_val = 0;
                        sb2dbg_mask_status[i].bit_mask = 0;
                        sb2dbg_mask_status[i].reg_addr = 0;
                }
        }

	sb2_emergency_intr_enable();
}

void restore_sb2block_status(void)
{
        int i;
        rtd_outl(SB2_INTEN_SCPU_reg, (BIT(1) | BIT(0)));

        for(i = 0; i < SB2_BLOCK_SET_NUM; ++i)
        {
                rtd_outl(SB2_RBUS_INVA_ACC_SEC1_START_reg + i * 8, sb2block_reg_status.start_addr[i]);
                rtd_outl(SB2_RBUS_INVA_ACC_SEC1_END_reg + i * 8, sb2block_reg_status.end_addr[i]);
        }
        rtd_outl(SB2_RBUS_INVA_ACC_CTRL_reg, sb2block_reg_status.ctrl);
}

void store_sb2dbg_status(void)
{
        int i;

        memset(sb2dbg_tmp_reg, 0, sizeof(sb2dbg_tmp_reg));
        memset(sb2dbg_reg_status, 0, sizeof(sb2dbg_reg_status));

        sb2dbg_tmp_reg[STRREG_INV_INTEN_reg] = rtd_inl(SB2_INV_INTEN_reg);
        //sb2dbg_tmp_reg[STRREG_INV_INTSTAT_reg] = rtd_inl(SB2_INV_INTSTAT_reg);
        sb2dbg_tmp_reg[STRREG_DEBUG_REG_reg] = rtd_inl(SB2_DEBUG_REG_reg);
        sb2dbg_tmp_reg[STRREG_DBG_INT_reg] = rtd_inl(SB2_DBG_INT_reg);

        for (i = 0; i < 16; i++)
        {
                if(str_support_flag & (0x1 << i))   //if reg[i] has already been setting
                {
                        sb2dbg_reg_status[i].start_addr = rtd_inl(get_SB2_DBG_START_register(i));
                        sb2dbg_reg_status[i].end_addr = rtd_inl(get_SB2_DBG_END_register(i));
                        sb2dbg_reg_status[i].ctrl = rtd_inl(get_SB2_DBG_CTRL_register(i));
                }
        }

	sb2_emergency_intr_clear();
}

void store_sb2block_status(void)
{
        int i;
        memset(&sb2block_reg_status, 0, sizeof(sb2block_reg_status));
        sb2block_reg_status.ctrl = rtd_inl(SB2_RBUS_INVA_ACC_CTRL_reg);
        for(i = 0; i < SB2_BLOCK_SET_NUM; ++i)
        {
                sb2block_reg_status.start_addr[i] = rtd_inl(SB2_RBUS_INVA_ACC_SEC1_START_reg + i * 8);
                sb2block_reg_status.end_addr[i] = rtd_inl(SB2_RBUS_INVA_ACC_SEC1_END_reg + i * 8);
        }
}

void __init monitor_scpu_text_phy(void)
{
        unsigned int phy_kernel_start = 0x104000;
#ifdef CONFIG_ARM64
        unsigned int phy_kernel_end = (unsigned int)((unsigned long)_etext - PAGE_OFFSET);
#else
        unsigned int phy_kernel_end = (unsigned int)(_etext - CONFIG_PAGE_OFFSET);
#endif
        sb2_dbg_param param;
        memset(&param, 0, sizeof(param));

        param.set_id = 6;
        param.cpu_flag[CPU_TYPE_ALL] = 1;
        param.start = phy_kernel_start;
        param.end = phy_kernel_end;
        param.operation = OPERA_MONITOR;
        param.rw = RW_FLAG_WO;
        param.str = STR_FLAG_YES;

        // set dbg range
        if(sb2_dbg_monitor(&param))
                pr_err("sb2_dbg_set fail!\n");
}

void __init monitor_kcpu_text_phy(void)
{
        sb2_dbg_param param;
        memset(&param, 0, sizeof(param));

        param.set_id = 7;
        param.cpu_flag[CPU_TYPE_ALL] = 0;
        param.cpu_flag[CPU_TYPE_ACPU] = 1;
        param.cpu_flag[CPU_TYPE_VCPU] = 1;
        param.cpu_flag[CPU_TYPE_SCPU] = 1;
        param.cpu_flag[CPU_TYPE_VCPU2] = 0;
        param.cpu_flag[CPU_TYPE_KCPU] = 0;
        param.cpu_flag[CPU_TYPE_ACPU2] = 0;
        param.start = 0x18408000;
        param.end = 0x18545000-SB2_ALIGN_SIZE;
        param.operation = OPERA_MONITOR;
        param.rw = RW_FLAG_WO;
        param.str = STR_FLAG_YES;

        // set dbg range
        if(sb2_dbg_monitor(&param))
        {
                pr_err("sb2_dbg_set fail!\n");
        }
}

void __init monitor_overrun_phy(void)
{
        sb2_dbg_param param;
        memset(&param, 0, sizeof(param));

        param.set_id = 8;
        param.cpu_flag[CPU_TYPE_ALL] = 0;
        param.cpu_flag[CPU_TYPE_ACPU] = 0;
        param.cpu_flag[CPU_TYPE_VCPU] = 1;
        param.cpu_flag[CPU_TYPE_SCPU] = 0;
        param.cpu_flag[CPU_TYPE_KCPU] = 1;


        param.start = 0x20000000;
        param.end = 0xffffffff;
        param.operation = OPERA_MONITOR;
        param.rw = RW_FLAG_RW;
        param.str = STR_FLAG_YES;

        // set dbg range
        if(sb2_dbg_monitor(&param))
        {
                pr_err("sb2_dbg_set fail!\n");
        }
}

void rtk_sb2_setup(void)
{
        sb2_intr_setup();
        sb2_dbg_latch_setup();
        sb2_dbg_intr_setup();
        sb2_block_intr_setup();
        monitor_scpu_text_phy();
#ifdef CONFIG_REALTEK_SECURE
        monitor_kcpu_text_phy();
#endif
        monitor_overrun_phy();
        //monitor_dc_phy();
        //monitor_dc2_phy();

	 sb2_emergency_intr_setup();
}
EXPORT_SYMBOL(rtk_sb2_setup);
int get_sb2_timeout_info(sb2_timeout_info *info)
{
        if(timeout_info.isTimeout)
        {
                memcpy(info,&timeout_info,sizeof(timeout_info));
        }
        else
        {
                memset(info,0,sizeof(sb2_timeout_info));
        }

        return 0;
}
EXPORT_SYMBOL(get_sb2_timeout_info);

int isSb2Timeout(char * module_name)
{
        if(!timeout_info.isTimeout){
                return 0;
        }
        if(is_moudle_reg_match(module_name, timeout_info.timeout_reg) == 0){    //match
                return 1;
        }
        return 0;
}
EXPORT_SYMBOL(isSb2Timeout);


static void sb2_dump_in_dcmt(void)
{
        if(isDcmtTrap("CPUS"))
        {
                pr_err("dump sb2 reg info:\n");
                dump_sb2dbg_regval();
        }
}

DCMT_DEBUG_INFO_DECLARE(sb2_dump,sb2_dump_in_dcmt);

static int __init sb2_extra_module_init(void)
{
        DCMT_DEBUG_INFO_REGISTER(sb2_dump,sb2_dump_in_dcmt);
}

static void __exit sb2_extra_module_exit(void)
{
        DCMT_DEBUG_INFO_UNREGISTER(sb2_dump,sb2_dump_in_dcmt);
}

module_init(sb2_extra_module_init);
module_exit(sb2_extra_module_exit);

#if 0
void __init monitor_dc_phy(void)
{
        sb2_dbg_param dc_param;
        memset(&dc_param, 0, sizeof(dc_param));

        dc_param.set_id = 6;
        dc_param.cpu_flag[CPU_TYPE_ALL] = 1;
        dc_param.start = 0x18008000;
        dc_param.end = 0x18008ffc;
        dc_param.operation = OPERA_MONITOR;
        dc_param.rw = RW_FLAG_WO;
        dc_param.str = STR_FLAG_YES;

        // set dbg range
        if(sb2_dbg_monitor(&dc_param))
        {
                pr_err("sb2_dbg_set fail!\n");
        }
}

void __init monitor_dc2_phy(void)
{
        sb2_dbg_param dc2_param;
        memset(&dc2_param, 0, sizeof(dc2_param));

        dc2_param.set_id = 7;
        dc2_param.cpu_flag[CPU_TYPE_ALL] = 1;
        dc2_param.start = 0x18004000;
        dc2_param.end = 0x18004ffc;
        dc2_param.operation = OPERA_MONITOR;
        dc2_param.rw = RW_FLAG_WO;
        dc2_param.str = STR_FLAG_YES;

        // set dbg range
        if(sb2_dbg_monitor(&dc2_param))
        {
                pr_err("sb2_dbg_set fail!\n");
        }
}

#endif

