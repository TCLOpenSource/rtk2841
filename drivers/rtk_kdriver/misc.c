#include <generated/autoconf.h>
#include <linux/init.h>
#include <linux/kernel.h>   /* MISC_DBG_PRINT() */
#include <linux/slab.h>     /* kmalloc() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/cdev.h>
#include <linux/module.h>
//#include <asm/system.h>       /* cli(), *_flags */
#include <asm/uaccess.h>        /* copy_*_user */
#include <asm/io.h>
#include <linux/sched.h>
#include <linux/signal.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/delay.h>
#include <rtk_kdriver/misc.h>
//#include <rbus/crt_reg.h>
#include <rbus/dc_sys_reg.h>
#include <rbus/stb_reg.h>
#include "rtd_types.h"
#include <linux/kthread.h>
#include <linux/interrupt.h>

#include <rbus/dc_sys_reg.h>
//#include <rbus/crt_reg.h>
//#include <rbus/ib_reg.h>
#include <rbus/vodma_reg.h>

#include <mach/rtk_log.h>
#include <linux/uaccess.h>

#ifdef CONFIG_RTK_KDRV_WATCHDOG
#include <rtk_kdriver/rtk_watchdog.h>
#endif
#define MISC_TAG "MISC"

#define MISC_DBG(fmt,args...) rtd_printk(KERN_DEBUG, MISC_TAG, fmt, ## args)
#define MISC_INFO(fmt,args...) rtd_printk(KERN_INFO, MISC_TAG, fmt, ## args)
#define MISC_ERR(fmt,args...) rtd_printk(KERN_ERR, MISC_TAG, fmt, ## args)
#define MISC_EMERG(fmt,args...) rtd_printk(KERN_EMERG, MISC_TAG, fmt, ## args)
//#define MISC_DBG_PRINT(s, args...) printk(s, ## args)
//#define MISC_DBG_PRINT(s, args...)

int misc_major      = 0;
int misc_minor      = 0;
#define REG_BUSH_OC_CONTROL 0xb8000438
#define REG_BUSH_OC_DONE 0xb8000438
#define REG_BUSH_SSC_CONTROL 0xb80003d0
#define REG_BUSH_NCODE_SSC 0xb80003d4
#define REG_BUSH_FCODE_SSC 0xb80003d4
#define REG_BUSH_GRAN_EST 0xb80003d0

#define REG_BUS_OC_CONTROL 0xb8000428
#define REG_BUS_OC_DONE 0xb8000428
#define REG_BUS_SSC_CONTROL 0xb80003c0
#define REG_BUS_NCODE_SSC 0xb80003c4
#define REG_BUS_FCODE_SSC 0xb80003c4
#define REG_BUS_GRAN_EST 0xb80003c0

#define REG_DDR_OC_CONTROL 0xb8008028
#define REG_DDR_OC_DONE 0xb8008028
#define REG_DDR_SSC_CONTROL 0xb800801c
#define REG_DDR_NCODE_SSC 0xb8008028
#define REG_DDR_FCODE_SSC 0xb8008024
#define REG_DDR_GRAN_EST 0xb8008020

#define REG_DDR2_OC_CONTROL 0xb8004028
#define REG_DDR2_OC_DONE 0xb8004028
#define REG_DDR2_SSC_CONTROL 0xb800401c
#define REG_DDR2_NCODE_SSC 0xb8004028
#define REG_DDR2_FCODE_SSC 0xb8004024
#define REG_DDR2_GRAN_EST 0xb8004020

#define REG_DISPLAY_OC_CONTROL 0xb80006a0
#define REG_DISPLAY_OC_DONE 0xb80006b4
#define REG_DISPLAY_SSC_CONTROL 0xb80006b0
#define REG_DISPLAY_NCODE_SSC 0xb80006ac
#define REG_DISPLAY_FCODE_SSC 0xb80006ac
#define REG_DISPLAY_GRAN_EST 0xb80006b0

#define DC_PHY_EFF_MEAS_CTRL_reg 0xB8008D80
#define DC_PHY_TMCTRL3_reg 0xB800880C
#define DC_PHY_READ_CMD_reg 0xB8008D84
#define DC_PHY_WRITE_CMD_reg 0xB8008D88

#define JTAG_CONTROL_REG 0xB810E004

#define PERIOD 30//60 //period 30 kHz
#define DOT_GRAN 4
#define RTD_LOG_CHECKING_REGISTER 0xb801a610
#define RTD_LOG_CHECK_REG 0x100

#define IB_CLIENTS_NUM 13
#define IB_CLIENTS_REG_ADDRESS_OFFSET 0x100
#define IB_TRAP_CASE_NUMBER 11
#define IB_ERR_STATUS_NUMBER 26

typedef enum DC_ID {
        DC_ID_1 = 0,
        DC_NUMBER,
} DC_ID;

typedef enum DC_SYS_ID {
        DC_SYS1 = 0,
        DC_SYS2 = 1,
        DC_SYS3 = 2,
        DC_SYS_NUMBER,
} DC_SYS_ID;

static struct class *misc_class;
static struct misc_dev *misc_drv_dev;                           /* allocated in misc_init_module */
extern void msleep(unsigned int msecs);
extern void dump_stacks (void);
static void rtk_ddr_debug_resume(void);

//extern unsigned int console_rtdlog_level;
//extern unsigned int console_rtdlog_module;
extern rtk_rtdlog_info_t console_rtdlog;

typedef struct DC_ERRCMD_REGS {
        unsigned int addcmd_hi[DC_NUMBER][DC_SYS_NUMBER];
        unsigned int addcmd_lo[DC_NUMBER][DC_SYS_NUMBER];
        unsigned int dc_int[DC_NUMBER][DC_SYS_NUMBER];
} DC_ERRCMD_REGS;

DC_ERRCMD_REGS dcsys_errcmd_regs;

static void  rtd_part_outl(unsigned int reg_addr, unsigned int endBit, unsigned int startBit, unsigned int value)
{
        unsigned int X, A, result;
        X = (1 << (endBit - startBit + 1)) - 1;
        A = rtd_inl(reg_addr);
        result = (A & (~(X << startBit))) | (value << startBit);
        MISC_INFO("[%s]origin=0x%x,startBit=%d, endBit=%d, value=0x%x\n", __FUNCTION__, A, startBit, endBit, value);
        MISC_INFO("[%s]reg=0x%x, value=0x%x\n", __FUNCTION__, reg_addr, result);
        rtd_outl(reg_addr, result);

}

#define MODULE_STR_SIZE    (8)
static bool StrToHex(unsigned char* pu8string, unsigned int u32Size, unsigned int* pu32Value)
{
        unsigned int u32Value = 0;
        unsigned int i;
        unsigned char u8Data[MODULE_STR_SIZE];
        bool bRet = true;

        if (u32Size > MODULE_STR_SIZE) {
                u32Size = MODULE_STR_SIZE;
        }
        for (i = 0; i < u32Size; i++) {
                //Covert 'A' to 'a'
                if ((pu8string[i] >= 'A') && (pu8string[i] <= 'F')) {
                        u8Data[i] = pu8string[i] - 'A' + 'a';
                } else {
                        u8Data[i] = pu8string[i];
                }
        }

        for (i = 0; i < u32Size; i++) {
                //printf("u8Data[%d]: %d.\n", i, u8Data[i]);
                if ((u8Data[i] >= '0') && (u8Data[i] <= '9')) {
                        u32Value *= 16;
                        u32Value += (u8Data[i] - '0');
                } else if ((u8Data[i] >= 'a') && (u8Data[i] <= 'f')) {
                        u32Value *= 16;
                        u32Value += (u8Data[i] + 10 - 'a');
                } else if (u8Data[i] != '\n') {
                        bRet = false;
                }
        }
        if (bRet) {
                *pu32Value = u32Value;
        }
        // MISC_INFO("[MISC][StrToHex]%d,leng=%s,%s, ===> %d\n", bRet,u32Size ,u8Data, *pu32Value  );

        return bRet;
}



static unsigned int DDR_period = PERIOD;
static RHAL_SYS_SPREAD_SPECTRUM_RATIO_T DDR_nRatio[RHAL_SYS_SPREAD_SPECTRUM_MODULE_MAX] = 
        {
                RHAL_SYS_SPREAD_SPECTRUM_OFF,
#ifdef SUPPORT_DCU2
                RHAL_SYS_SPREAD_SPECTRUM_OFF
#endif
         };

static unsigned int DDR1_freq_old = 0;
static unsigned int DDR1_N_CODE = 0;
static unsigned int DDR1_F_CODE = 0;
static unsigned int DDR1_freq_new = 0; 
#ifdef SUPPORT_DCU2
static unsigned int DDR2_freq_old = 0;
static unsigned int DDR2_N_CODE = 0;
static unsigned int DDR2_F_CODE = 0;
static unsigned int DDR2_freq_new = 0;
#endif
static unsigned int getSSCParameter(unsigned int inputFreq, unsigned int inRatio,
                                    unsigned int *Ncode_ssc,  unsigned int *Fcode_ssc, unsigned int *Gran_est)
{
        unsigned int M_target = 0;
        unsigned int target_F_Code = 0;
        unsigned int ssc_clock = 0;
        unsigned int step = 0;
        unsigned int ret_Ncode_ssc = 0;
        unsigned int ret_Fcode_ssc = 0;
        unsigned int ret_Gran_est = 0;
        unsigned int tempValue = 0;
        unsigned int tempValue3 = 0;
        unsigned int tempValue2 = 0;
        unsigned int temp_a = 0;
        unsigned int temp_b = 0;

        M_target = (inputFreq / 27) - 3;

        tempValue = ((100000 * inputFreq) / 27) % 100000;
        target_F_Code = (tempValue * 2048) / 100000;

        ret_Ncode_ssc = ((inputFreq * (10000 - inRatio)) / 27) / 10000 - 3;

        tempValue = ((inputFreq * (10000 - inRatio)) / 270) % 1000;
        ret_Fcode_ssc = (tempValue * 2048) / 1000;

        tempValue2 = (inputFreq * (10000 - inRatio / 2));
        tempValue = (((M_target - ret_Ncode_ssc) * 2048 + (target_F_Code - ret_Fcode_ssc)) / 2 / 2048) + (ret_Ncode_ssc + 3);
        temp_a = inputFreq * 10000;
        temp_b = inputFreq * (inRatio / 2);
        tempValue3 = (temp_a - temp_b);
        ssc_clock = tempValue3 / tempValue / 10;
        step = ssc_clock / DDR_period;

        tempValue2 = ((M_target - ret_Ncode_ssc) * 2048 + (target_F_Code - ret_Fcode_ssc));
        tempValue = (1000 * (tempValue2 * 2)) / step;
        tempValue2 = 1 << (15 - DOT_GRAN);
        ret_Gran_est = (tempValue * tempValue2) / 1000; //pow(2,15-DOT_GRAN);

        if(Ncode_ssc != NULL)
                *Ncode_ssc = ret_Ncode_ssc;
        if(Fcode_ssc != NULL)
                *Fcode_ssc = ret_Fcode_ssc;
        if(Gran_est != NULL)
                *Gran_est = ret_Gran_est;

        MISC_INFO("[%s] M_target=%d, target_F_Code=%d\n", __FUNCTION__, M_target, target_F_Code);
        MISC_INFO("[%s] ssc_clock=%d, step=%d\n", __FUNCTION__, ssc_clock, step);
        MISC_INFO("[%s] input(%d,%d),output(%d,,%d,,%d,)\n", __FUNCTION__, inputFreq, inRatio, ret_Ncode_ssc, ret_Fcode_ssc, ret_Gran_est);

        return 1;

}

static unsigned int getDDR1Frequency(void)//reference from bootcode:/common/cmd_dssinfo.c  pll_ddr_freq()
{
        unsigned int regValueForN = rtd_inl(REG_DDR_NCODE_SSC);
        unsigned int regValueForF = rtd_inl(REG_DDR_FCODE_SSC);
        unsigned int N_CODE, F_CODE, FOUT;
        N_CODE = (regValueForN & 0xFF00) >> 8;
        F_CODE = (regValueForF & 0x7FF0000) >> 16;

        FOUT = (unsigned int)(((27 * N_CODE + 27 * 3 + (27 * F_CODE) / 2048)));

        MISC_INFO("[%s] regvalueForN= 0x%x regvalueForF= 0x%x ==>N:%d, F=%d , out=%d\n", __FUNCTION__, regValueForN, regValueForF, N_CODE, F_CODE, FOUT);
        return FOUT;
}

static void setDDR1Frequency(unsigned int fin)//reference from bootcode:/common/cmd_dssinfo.c  pll_ddr_freq()
{
        unsigned int regValueForN = 0;
        unsigned int regValueForF = 0;
        
        unsigned int N_CODE = fin/27 - 3;
        unsigned int F_CODE = (fin%27 * 10000)/27*2048/10000 ;
        
        regValueForN = (N_CODE&0xFF) << 8;
        regValueForF = ((F_CODE & 0x7FF) <<16);
        rtd_maskl(REG_DDR_NCODE_SSC, 0xFFFF00FF, regValueForN);
        rtd_maskl(REG_DDR_FCODE_SSC, 0xF800FFFF, regValueForF);

        MISC_INFO("[%s] regvalueForN= 0x%x regvalueForF= 0x%x ==>N:%d, F=%d , in=%d\n", __FUNCTION__, regValueForN, regValueForF, N_CODE, F_CODE, fin);
        return;
}

#ifdef SUPPORT_DCU2
static unsigned int getDDR2Frequency(void)//reference from bootcode:/common/cmd_dssinfo.c  pll_ddr_freq()
{
        unsigned int regValueForN = rtd_inl(REG_DDR2_NCODE_SSC);
        unsigned int regValueForF = rtd_inl(REG_DDR2_FCODE_SSC);
        unsigned int N_CODE, F_CODE, FOUT;
        N_CODE = (regValueForN & 0xFF00) >> 8;
        F_CODE = (regValueForF & 0x7FF0000) >> 16;

        FOUT = (unsigned int)(((27 * N_CODE + 27 * 3 + (27 * F_CODE) / 2048)));

        MISC_INFO("[%s] regvalueForN= 0x%x regvalueForF= 0x%x ==>N:%d, F=%d , out=%d\n", __FUNCTION__, regValueForN, regValueForF, N_CODE, F_CODE, FOUT);
        return FOUT;
}

static void setDDR2Frequency(unsigned int fin)//reference from bootcode:/common/cmd_dssinfo.c  pll_ddr_freq()
{
        unsigned int regValueForN = 0;
        unsigned int regValueForF = 0;
        
        unsigned int N_CODE = fin/27 - 3;
        unsigned int F_CODE = (fin%27 * 10000)/27*2048/10000 ;
        
        regValueForN = (N_CODE&0xFF) << 8;
        regValueForF = ((F_CODE & 0x7FF) <<16);
        rtd_maskl(REG_DDR2_NCODE_SSC, 0xFFFF00FF, regValueForN);
        rtd_maskl(REG_DDR2_FCODE_SSC, 0xF800FFFF, regValueForF);

        MISC_INFO("[%s] regvalueForN= 0x%x regvalueForF= 0x%x ==>N:%d, F=%d , in=%d\n", __FUNCTION__, regValueForN, regValueForF, N_CODE, F_CODE, fin);
        return;
}

#endif
//-----------------------------------------------------
//
//
//-----------------------------------------------------
int RHAL_SYS_SetDDRSpreadSpectrum(RHAL_SYS_SPREAD_SPRECTRUM_MODULE_T module, RHAL_SYS_SPREAD_SPECTRUM_RATIO_T nRatio)
{
        unsigned int NCode_ssc = 0;
        unsigned int FCode_ssc = 0;
        unsigned int Gran_est = 0;
        unsigned int freq_MHz = 0;
        unsigned int waitBit = 0;
        int ret = -1;
        
        if(module == RHAL_SYS_SPREAD_SPECTRUM_MODULE_DDR)
       {
                if(DDR1_freq_old == 0)
                {
                        DDR1_N_CODE = (rtd_inl(REG_DDR_NCODE_SSC) & 0xFF00) >> 8; // save ddr freq N_CODE
                        DDR1_F_CODE = (rtd_inl(REG_DDR_FCODE_SSC) & 0x7FF0000) >> 16; // save ddr freq F_CODE
                        DDR1_freq_old = (unsigned int)(((27 * DDR1_N_CODE + 27 * 3 + (27 * DDR1_F_CODE) / 2048)));
                }
                
                if(nRatio == RHAL_SYS_SPREAD_SPECTRUM_OFF)
                {
                        rtd_maskl(REG_DDR_NCODE_SSC, 0xFFFF00FF, ((DDR1_N_CODE&0xFF) << 8));
                        rtd_maskl(REG_DDR_FCODE_SSC, 0xF800FFFF, ((DDR1_F_CODE & 0x7FF) <<16));
                        
                        rtd_part_outl(REG_DDR_SSC_CONTROL, 1, 1, 0x0);//En_ssc =0 
                        return 0;
                }
                else if(nRatio <= RHAL_SYS_SPREAD_SPECTRUM_RATIO_6_00){
                        rtd_maskl(REG_DDR_NCODE_SSC, 0xFFFF00FF, ((DDR1_N_CODE&0xFF) << 8));
                        rtd_maskl(REG_DDR_FCODE_SSC, 0xF800FFFF, ((DDR1_F_CODE & 0x7FF) <<16));
                        nRatio = nRatio* 25;
                }
                else if(nRatio <RHAL_SYS_SPREAD_SPECTRUM_RATIO_MAX)
                {
                        nRatio = (nRatio - RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_0_25 + 1)*25;
                        DDR1_freq_new = DDR1_freq_old*(nRatio +10000)/10000;
                        setDDR1Frequency(DDR1_freq_new);
                        nRatio = nRatio *2;
                }
                /******************************DCU1********************************/
                //Step 1. Get frequnecy
                freq_MHz = getDDR1Frequency();

                //Step 2. Get Ncode_ssc, Fcode_ssc and Gran
                getSSCParameter(freq_MHz, nRatio, &NCode_ssc, &FCode_ssc, &Gran_est);
                //Step 3. Write to register
                //Step 3.1 Disable ssc
                rtd_part_outl(REG_DDR_SSC_CONTROL, 3, 3, 0x1);//dpi_ssc_flag_init =1
                rtd_part_outl(REG_DDR_SSC_CONTROL, 1, 1, 0x0);//En_ssc =0
                //Step 3.2 Disable oc
                rtd_part_outl(REG_DDR_OC_CONTROL, 26, 26, 0);//oc_en =0
                //Step 3.3 Set Ncode_ssc, Fcode_ssc
                rtd_part_outl(REG_DDR_NCODE_SSC, 7, 0, NCode_ssc);//Ncode_ssc
                rtd_part_outl(REG_DDR_FCODE_SSC, 10, 0, FCode_ssc);//Fcode_ssc
                //Step 3.4 Set Gran_est
                rtd_part_outl(REG_DDR_GRAN_EST, 22, 20, DOT_GRAN);//Gran_set
                rtd_part_outl(REG_DDR_GRAN_EST, 18, 0, Gran_est);//Gran_set
                //Step 3.5 Enable oc
                rtd_part_outl(REG_DDR_OC_CONTROL, 26, 26, 1);//oc_en =1

                waitBit = rtd_inl(REG_DDR_OC_DONE);
                while((waitBit & 0x4000000) == 0) {
                        waitBit = rtd_inl(REG_DDR_OC_DONE); // polling for oc_done
                        printk("waiting.....DDR  =0x%x\n", waitBit);
                }
                //Step 3.6 Disable oc
                rtd_part_outl(REG_DDR_OC_CONTROL, 26, 26, 0);//oc_en =0
                //Step 3.7 Enable ssc
                rtd_part_outl(REG_DDR_SSC_CONTROL, 1, 1, 0x1);//En_ssc =1
                //Step 4.End
                ret = 0;
        }
#ifdef SUPPORT_DCU2
        else if(module == RHAL_SYS_SPREAD_SPECTRUM_MODULE_DDR2)
        {
                if(DDR2_freq_old == 0)
                {
                        DDR2_N_CODE = (rtd_inl(REG_DDR2_NCODE_SSC) & 0xFF00) >> 8; // save ddr freq N_CODE
                        DDR2_F_CODE = (rtd_inl(REG_DDR2_FCODE_SSC) & 0x7FF0000) >> 16; // save ddr freq F_CODE
                        DDR2_freq_old = (unsigned int)(((27 * DDR2_N_CODE + 27 * 3 + (27 * DDR2_F_CODE) / 2048)));
                }
                
                if(nRatio == RHAL_SYS_SPREAD_SPECTRUM_OFF)
                {
                        rtd_maskl(REG_DDR2_NCODE_SSC, 0xFFFF00FF, ((DDR2_N_CODE&0xFF) << 8));
                        rtd_maskl(REG_DDR2_FCODE_SSC, 0xF800FFFF, ((DDR2_F_CODE & 0x7FF) <<16));
                        rtd_part_outl(REG_DDR2_SSC_CONTROL, 1, 1, 0x0);//En_ssc =0 
                        return 0;
                }
                else if(nRatio <= RHAL_SYS_SPREAD_SPECTRUM_RATIO_6_00){
                        rtd_maskl(REG_DDR2_NCODE_SSC, 0xFFFF00FF, ((DDR2_N_CODE&0xFF) << 8));
                        rtd_maskl(REG_DDR2_FCODE_SSC, 0xF800FFFF, ((DDR2_F_CODE & 0x7FF) <<16));
                        nRatio = nRatio* 25;
                }
                else if(nRatio <RHAL_SYS_SPREAD_SPECTRUM_RATIO_MAX)
                {
                        nRatio = (nRatio - RHAL_SYS_SPREAD_SPECTRUM_RATIO_up_0_25 + 1)*25;
                        DDR2_freq_new = DDR2_freq_old*(nRatio +10000)/10000;
                        setDDR2Frequency(DDR2_freq_new);
                        nRatio = nRatio *2;
                }
                
                /******************************DCU2********************************/
                freq_MHz = getDDR2Frequency();
                //Step 2. Get Ncode_ssc, Fcode_ssc and Gran
                getSSCParameter(freq_MHz, nRatio, &NCode_ssc, &FCode_ssc, &Gran_est);
                //Step 3. Write to register
                //Step 3.1 Disable ssc
                rtd_part_outl(REG_DDR2_SSC_CONTROL, 3, 3, 0x1);////dpi_ssc_flag_init =1
                rtd_part_outl(REG_DDR2_SSC_CONTROL, 1, 1, 0x0);//////En_ssc =0
                //Step 3.2 Disable oc
                rtd_part_outl(REG_DDR2_OC_CONTROL, 26, 26, 0);//oc_en =0
                //Step 3.3 Set Ncode_ssc, Fcode_ssc
                rtd_part_outl(REG_DDR2_NCODE_SSC, 7, 0, NCode_ssc);//Ncode_ssc
                rtd_part_outl(REG_DDR2_FCODE_SSC, 10, 0, FCode_ssc);//Fcode_ssc
                //Step 3.4 Set Gran_est
                rtd_part_outl(REG_DDR2_GRAN_EST, 22, 20, DOT_GRAN);//Gran_set
                rtd_part_outl(REG_DDR2_GRAN_EST, 18, 0, Gran_est);//Gran_set
                //Step 3.5 Enable oc
                rtd_part_outl(REG_DDR2_OC_CONTROL, 26, 26, 1);//oc_en =1

                waitBit = 0;
                waitBit = rtd_inl(REG_DDR2_OC_DONE);
                while((waitBit & 0x4000000) == 0) {
                        waitBit = rtd_inl(REG_DDR2_OC_DONE); // polling for oc_done
                        printk("waiting.....DDR2  =0x%x\n", waitBit);
                }
                //Step 3.6 Disable oc
                rtd_part_outl(REG_DDR2_OC_CONTROL, 26, 26, 0);//oc_en =0
                //Step 3.7 Enable ssc
                rtd_part_outl(REG_DDR2_SSC_CONTROL, 1, 1, 0x1);//En_ssc =1
                //Step 4.End                
                ret = 0;
        }
#endif

        return ret;
}

/*
 * Open and close
 */

int misc_open(
        struct inode*           inode,
        struct file*            filp
)
{
        struct misc_dev *pdev; /* device information */

        pdev = container_of(inode->i_cdev, struct misc_dev, cdev);
        filp->private_data = pdev; /* for other methods */

        MISC_DBG("misc open\n");
        return 0;
}

int misc_release(
        struct inode*           inode,
        struct file*            filp
)
{
        filp->private_data = NULL;

        MISC_DBG("misc release\n");
        return 0;
}

#ifdef CONFIG_R8168
static struct task_struct *thread_wol, *thread_wolether;
static int wol_polling(void *arg);
static int wolether_polling(void *arg);
extern struct platform_device *network_devs;
extern int rtl8168_suspend(struct platform_device *dev, pm_message_t state);
extern int rtl8168_resume(struct platform_device *dev);

static int wol_polling(void *arg)
{
        pm_message_t pmstate;

        rtl8168_suspend(network_devs, pmstate);
        MISC_INFO("ether driver suspend for WOL\n");
        // Reset WOL Pin to high for the falling edge trigger of the ext. micom
        rtd_outl(0xb8061108, (rtd_inl(0xb8061108) | (1 << 6)));
        // Clear WOL Flag
        rtd_outl(0xb80160b0, 0xf0031e00);  //0xf0031e00
        rtd_outl(0xb806050c, 0xbeef7777);
        while(!kthread_should_stop()) {
                msleep(300);
                rtd_outl(0xb80160b0, 0x70030000);  //0xf0031e00
                MISC_INFO("%08x\n", rtd_inl(0xb80160b0));   // check 0x1e00(default)  -->WOL 0x9e00
                MISC_INFO("%08x\n", rtd_inl(0xb8061108));
                if ( (rtd_inl(0xb80160b0) & 0xffff) == 0x9e00)
                        break;
                if ( rtd_inl(0xb806050c) == 0xbeef9999)
                        break;
        }
        MISC_INFO("WOL!! wol_polling thread break\n");
        if ( rtd_inl(0xb806050c) != 0xbeef9999) {
                MISC_INFO("Set WOL Pin to low for the falling edge trigger of the ext. micom!\n");
                MISC_INFO("%08x\n", rtd_inl(0xb8061100));
                MISC_INFO("%08x\n", rtd_inl(0xb8061108));
                // Set WOL Pin to low for the falling edge trigger of the ext. micom
                rtd_outl(0xb8061108, (rtd_inl(0xb8061108) & ~(1 << 6)));
                MISC_INFO("%08x\n", rtd_inl(0xb8061108));
        }
        // Resume
        rtl8168_resume(network_devs);
        MISC_INFO("ether driver resume for WOL\n");
        rtd_outl(0xb806050c, 0x0);
        MISC_INFO("stop wol_polling thread!\n");
        kthread_stop(thread_wol);

        return 0;
}

#if 1
static int wolether_polling(void *arg)
{
        pm_message_t pmstate;

        while(!kthread_should_stop()) {
                msleep(300);
                if ( rtd_inl(0xb8060110) == 0x9021affe )
                        break;
                if ( rtd_inl(0xb8060110) == 0xbeef8888 )
                        break;
        }
        if ( rtd_inl(0xb8060110) == 0xbeef8888 ) {
                MISC_INFO("wolether_polling thread break(magic:%08x)\n", rtd_inl(0xb8060110));
                MISC_INFO("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
#if 0
                /* Reset Geth IP */
                MISC_INFO("Reset Geth IP!!\n");
                rtd_outl(0xb8016037, rtd_inl(0xb8016037) | 0x10); // BIT4
                MISC_INFO("checking rtd_inl(0xb8016037)=%08x \n", rtd_inl(0xb8016037));
                mdelay(50);
                // enable WOL IP setting for MAC
                MISC_INFO("enable WOL IP setting for MAC!!!\n");
                rtd_outl(0xb8016050, 0x1dcfc010);
                MISC_INFO("rtd_inl(0xb8016050)=%08x\n", rtd_inl(0xb8016050));
                mdelay(50);
                //rtd_outl(0xb80160d0, 0xb2000021);
                rtd_outl(0xb80160d0, 0x22000021); // fix auto wakeup issue
                MISC_INFO("rtd_inl(0xb80160d0)=%08x\n", rtd_inl(0xb80160d0));
                mdelay(50);
                rtd_outl(0xb8016050, 0x1dcf0010);
                MISC_INFO("rtd_inl(0xb8016050)=%08x\n", rtd_inl(0xb8016050));
                mdelay(50);
                // 0x18016c10[0] = 0x1 (default =0) before enable emcu clock
                // gmac clock select  0: gmac/emcu2 use bus clock 1: gmac/emcu2 use GPHY125MHz clock
                rtd_outl(0xb8016c10, (rtd_inl(0xb8016c10) & 0xfffffffe) | 0x1);
                mdelay(50);
                rtd_inl(0xb8016c10); // for asynchronous access
#endif
                //rtl8168_suspend(network_devs, pmstate);
                //MISC_INFO("ether driver suspend for WOL\n");
                rtd_outl(0xb8060110, 0xbeef6666);
        }
        MISC_INFO("stop wolether_polling thread!\n");
        kthread_stop(thread_wolether);

        return 0;
}
#endif
#endif
/*
 * The QSM Off implementation: tunning OSC & enable OSC
 */
void MISC_OSC_Clk_init(void)
{
    //   rtd_outl(0x0044, rtd_inl(0x0044)|_BIT11); //emb osc clock enable
    rtd_outl(0xb8060044, _BIT11 | _BIT0);

    //   rtd_outl(0x0044, rtd_inl(0x0044)&~_BIT11); //emb osc clock disable
    rtd_outl(0xb8060044, _BIT11);

    //   rtd_outl(0x0034, rtd_inl(0x0034)&~_BIT12); //hold osc reset
    rtd_outl(0xb8060034, _BIT12);

    //   rtd_outl(0x0034, rtd_inl(0x0034)|_BIT12); //release osc reset
    rtd_outl(0xb8060034, _BIT12 | _BIT0);

    //delayms(0x1); //delay at least > 150us
    udelay(200);
    //   rtd_outl(0x0044, rtd_inl(0x0044)|_BIT11); //emb osc clock enable
    rtd_outl(0xb8060044, _BIT11 | _BIT0);
}

void MISC_OSC_tracking(void)
{
    rtd_outl(0xb8060058, rtd_inl(0xb8060058)|_BIT1);// select external 27Mhz
    //rtd_setBits(0x0058, _BIT1);

    rtd_outl(0xb80600d0, rtd_inl(0xb80600d0)&~_BIT1);// auto mode
    //rtd_clearBits(0x00d0, _BIT1);

    rtd_outl(0xb80600d0, rtd_inl(0xb80600d0)|_BIT3);// osc_track_lock_en
    //rtd_setBits(0x00d0, _BIT3);

    rtd_outl(0xb80600d0, rtd_inl(0xb80600d0)|_BIT2);// osc_calibratable_en
    //rtd_setBits(0x00d0, _BIT2);

    rtd_outl(0xb80600d0, rtd_inl(0xb80600d0)|_BIT0);// Osc tracking enable
    //rtd_setBits(0x00d0, _BIT0);

    //    while(!(rtd_inl(0xb80600d4) & _BIT3));//polling for osc_track_lock_status=1
    while(!(rtd_inl(0xb80600d4) & _BIT3));//polling for osc_track_lock_status=1

    rtd_outl(0xb80600d0, rtd_inl(0xb80600d0)&~_BIT0);// Osc tracking disable
    //rtd_clearBits(0x00d0, _BIT0);

    rtd_outl(0xb8060058, rtd_inl(0xb8060058)&~_BIT1);// select ring_osc
    //rtd_clearBits(0x0058, _BIT1);
}

/*
 * The ioctl() implementation
 */

long misc_ioctl(
        struct file             *filp,
        unsigned int            cmd,
        unsigned long           arg)
{
        struct misc_dev *pdev = filp->private_data;
        int retval = 0;
        unsigned int i;

        if (down_interruptible(&pdev->sem))
                return -ERESTARTSYS;

        switch(cmd) {
                case MISC_WAKEUP_ECPU: {
                       MISC_INFO( "Wake-up ECPU...\n");
                       MISC_INFO("289x rtd_inl(0xb8060110)=%08x\n", rtd_inl(0xb8060110));
                       if(rtd_inl(0xb8060110) == 0x9021aebe) {  // sync system timer between A/V CPU
                           rtd_outl(0xb8060110, 0);
                           rtd_outl(STB_ST_SRST1_reg, BIT(9));
														}
                       rtd_outl(STB_ST_CLKEN1_reg, BIT(9) | BIT(0));       // clk enable
                       udelay(500);
                       rtd_outl(STB_ST_SRST1_reg, BIT(9) | BIT(0));
						                }
                break;

                case MISC_SET_WOL_ENABLE: {
                        int nEnable = arg;
			pm_message_t pmstate;

#ifdef CONFIG_R8168
                        
                        if(nEnable) {
                                // stop wol_polling thread and resume ether driver in case of Warm standby mode is on
                                if ( rtd_inl(0xb806050c) == 0xbeef7777 ) {
                                MISC_INFO( "Enter WOL flow in Warm standby mode...\n");
                                rtd_outl(0xb80160b0, 0x70030000);  //0xf0031e00
                                        // set WOL flag disabled for emcu
                                        MISC_INFO("set WOL flag disabled for emcu\n");
                                        rtd_outl(0xb8060500, (rtd_inl(0xb8060500) & 0xfeffffff));
                                        // stop wol_polling thread and resume ether driver in case of Warm standby mode is on
                                        rtd_outl(0xb806050c, 0xbeef9999);
                                        while ( rtd_inl(0xb806050c) == 0xbeef9999 ) {
                                                MISC_INFO( "stop wol_polling thread waiting! %x\n", rtd_inl(0xb806050c));
                                                msleep(300);
                                        }
						         } 
						         else {
                                         if(rtd_inl(0xb8060110) ==0x9021affa) {
		                                  MISC_INFO( "Enter twice WOL flow...\n");
										  break;
								       }
								  MISC_INFO( "Enable WOL...\n");
								  rtd_outl(0xb80160b0, 0x70030000);  //0xf0031e00	                                    MISC_INFO( "Enter WOL flow...\n");
	                                MISC_INFO( "Enter WOL flow...\n");
                                        MISC_INFO( "%s: WOL:%08x\n", __FUNCTION__, rtd_inl(0xb80160b0));   // check 0x1e00(default)  -->WOL 0x9e00
                                        MISC_INFO( "warm standby wol_polling thread does not exist!\n");
                                }
#if 1
#if 0
                                /* Reset Geth IP */
                                MISC_INFO("Reset Geth IP!!\n");
                                rtd_outl(0xb8016037, 0x10); // BIT4
                                MISC_INFO("checking rtd_inl(0xb8016037)=%08x \n", rtd_inl(0xb8016037));
                                mdelay(50);
                                // enable WOL IP setting for PHY
#if 0
                                MISC_INFO("enable WOL IP setting for PHY!!!\n");
                                rtd_outl(0xb8016060, 0x841f0bc4);       // Goto to Page bc4
                                MISC_INFO("rtd_inl(0xb8016060)=%08x\n", rtd_inl(0xb8016060));
                                rtd_outl(0xb8016060, 0x84150203);       // set internal LDO turn on
                                MISC_INFO("rtd_inl(0xb8016060)=%08x\n", rtd_inl(0xb8016060));
                                udelay(500);
#endif
                                // enable WOL IP setting for MAC
                                MISC_INFO("enable WOL IP setting for MAC!!!\n");
                                rtd_outl(0xb8016050, 0x1dcfc010);
                                MISC_INFO("rtd_inl(0xb8016050)=%08x\n", rtd_inl(0xb8016050));
                                mdelay(50);
                                //rtd_outl(0xb80160d0, 0xb2000021);
                                rtd_outl(0xb80160d0, 0x22000021); // fix auto wakeup issue
                                MISC_INFO("rtd_inl(0xb80160d0)=%08x\n", rtd_inl(0xb80160d0));
                                mdelay(50);
                                rtd_outl(0xb8016050, 0x1dcf0010);
                                MISC_INFO("rtd_inl(0xb8016050)=%08x\n", rtd_inl(0xb8016050));
                                mdelay(50);
#endif
                                MISC_INFO("289x  rtd_inl(0xb8060110)=%08x\n", rtd_inl(0xb8060110));

                                if((rtd_inl(0xb8060110) == 0x9021aebe) || (rtd_inl(0xb8060110) == 0x9021affc)) {
                                        rtd_outl(STB_ST_SRST1_reg, BIT(9));
                                }
                                // clear STR flag for emcu
                                //rtd_outl(0xb8060110, 0x00000000);
                                // clear share memory for emcu
#define RTD_SHARE_MEM_LEN       32
#define RTD_SHARE_MEM_BASE      0xb8060500
                                MISC_INFO("clear share memory in %s...\n", __FUNCTION__);
                                for(i = 0; i < RTD_SHARE_MEM_LEN; i++)
                                        rtd_outl(RTD_SHARE_MEM_BASE + (4 * i), 0);
                                // set WOL flag enabled for emcu
                                MISC_INFO("set WOL flag enabled for emcu\n");
                                rtd_outl(0xb8060500, (rtd_inl(0xb8060500) & 0xfeffffff) | 0x01000000);
                                // 0x18016c10[0] = 0x1 (default =0) before enable emcu clock
                                // gmac clock select  0: gmac/emcu2 use bus clock 1: gmac/emcu2 use GPHY125MHz clock
                                rtd_outl(0xb8016c10, (rtd_inl(0xb8016c10) & 0xfffffffe) | 0x1);
                                mdelay(50);
                                rtd_inl(0xb8016c10); // for asynchronous access
                                // run a thread for WOL polling
                                thread_wolether = kthread_run(wolether_polling, NULL, "wolether_polling");
                                if(IS_ERR(thread_wolether)) {
                                        MISC_INFO("create wolether_polling thread failed\n");
                                        retval = -EFAULT;
                                        break;
																				 }
				MISC_INFO("create wolether_polling thread successfully\n");

				MISC_INFO("ether driver suspend for WOL before\n");
				pm_message_t pmstate;
				rtl8168_suspend(network_devs, pmstate);
				MISC_INFO("ether driver suspend for WOL done\n");
#else
                                // clear STR flag for emcu
                                //rtd_outl(0xb8060110, 0x00000000);
                                // clear share memory for emcu
#define RTD_SHARE_MEM_LEN       32
#define RTD_SHARE_MEM_BASE      0xb8060500
                                MISC_INFO("clear share memory in %s...\n", __FUNCTION__);
                                for(i = 0; i < RTD_SHARE_MEM_LEN; i++)
                                        rtd_outl(RTD_SHARE_MEM_BASE + (4 * i), 0);
                                // set WOL flag enabled for emcu
                                MISC_INFO("set WOL flag enabled for emcu\n");
                                rtd_outl(0xb8060500, (rtd_inl(0xb8060500) & 0xfeffffff) | 0x01000000);
                                // run a thread for WOL polling
                                //thread_wolether = kthread_run(wolether_polling, NULL, "wolether_polling");
                                //if(IS_ERR(thread_wolether)) {
                                //        MISC_INFO("create wolether_polling thread failed\n");
                                //        retval = -EFAULT;
                                //        break;
 																				//}
                                //MISC_INFO("create wolether_polling thread successfully\n");
#endif
                                // enable emcu clock
                             MISC_INFO( "Wake-up ECPU...\n");
                             MISC_INFO("289x  rtd_inl(0xb8060110)=%08x\n", rtd_inl(0xb8060110));
                             rtd_outl(0xb8060110, 0x9021affa);
                             rtd_outl(STB_ST_CLKEN1_reg, BIT(9) | BIT(0));  // clk enable for emcu
                             udelay(500);
                             rtd_outl(STB_ST_SRST1_reg, BIT(9) | BIT(0));        // release reset for emcu
                        } else {
                                MISC_INFO( "Disable WOL...\n");
                                // clear STR flag for emcu
                                rtd_outl(0xb8060110, 0x00000000);
																				rtd_outl(STB_ST_SRST1_reg, _BIT9);//reset 8051
                                // clear share memory for emcu
                                MISC_INFO("clear share memory in %s...\n", __FUNCTION__);
                                for(i = 0; i < RTD_SHARE_MEM_LEN; i++)
                                        rtd_outl(RTD_SHARE_MEM_BASE + (4 * i), 0);
                                // set WOL flag disabled for emcu
                                MISC_INFO("set WOL flag disabled for emcu\n");
                                rtd_outl(0xb8060500, (rtd_inl(0xb8060500) & 0xfeffffff));
                                // disable emcu clock
                                //rtd_outl(STB_ST_CLKEN1_reg, rtd_inl(STB_ST_CLKEN1_reg) & ~BIT(9));    // clk disable for emcu
                                //udelay(500);
                                //rtd_outl(STB_ST_SRST1_reg, rtd_inl(STB_ST_SRST1_reg) & ~BIT(9));  // hold reset for emcu
                        }
#endif
                }
                break;
                case MISC_GET_WOL_ENABLE: {
                        int nEnable;

                        if((rtd_inl(0xb8060500) & 0x01000000) != 0)
                                nEnable = true;
                        else
                                nEnable = false;

                        if(copy_to_user((void __user *)arg, (void *)&nEnable, sizeof(int))) {
                                retval = -EFAULT;
                                break;
                        }
                }
                break;
#ifdef CONFIG_RTK_KDRV_RTICE
                case MISC_SET_DEBUG_LOCK: {

                        int nLock = arg;
                        extern  UINT8 g_ByPassRTICECmd;

                        if(nLock) {
                                //pin switch to uart2
                                //according to KTASKWBS-2863, always enable log.
                                //rtd_maskl(0xb806020C, 0xFF0FFFFF, 0x00600000);//06: uart2_rXdi_src0,<I> 0x1800_020C[23:20]
                                //  rtd_maskl(0xb806020C, 0x0FFFFFFF, 0x60000000);//06: uart2_tXdo,<O> 0x1800_020C[31:28]

                                //disable JTAG debug
                                rtd_maskl(JTAG_CONTROL_REG, 0xFFFFFFEF, 0x00000010);//ejtag_gpu_bist    set 1 to mux out gpu mbist ejtag port

                                //disable connect RTICE
                                g_ByPassRTICECmd = 1;
                        } else {
                                //enable JTAG debug
                                //pin switch to uart1
                                //according to KTASKWBS-2863, always enable log.
                                //rtd_maskl(0xb806020C, 0xFF0FFFFF, 0x00900000);//09: uart0_rXdi_src0,<I> 0x1806_020C[23:20]
                                //  rtd_maskl(0xb806020C, 0x0FFFFFFF, 0x90000000);//09: uart0_tXdo,<O> 0x1806_020C[31:28]

                                //enable JTAG debug
                                rtd_maskl(JTAG_CONTROL_REG, 0xFFFFFFEF, 0x00000000);//ejtag_gpu_bist

                                //enbale connect RTICE
                                g_ByPassRTICECmd = 0;

                        }
                }
                break;
#endif
                case MISC_SET_DDR_SSC_PARAM: 
                {
                        DDR_SSC_PARA para;
                        int nRet = 0;
                        if(copy_from_user((void *)&para, (const void __user *)arg, sizeof(DDR_SSC_PARA))) {
                                retval = -EFAULT;
                                break;
                        }

                        switch (para.cmd) 
                        {
                                case RHAL_SYS_CMD_SET_SPREAD_SPRECTRUM:
                                        DDR_nRatio[para.module] = para.ratio;
                                        nRet = RHAL_SYS_SetDDRSpreadSpectrum(para.module, DDR_nRatio[para.module]);
                                        break;
                                       
                                case RHAL_SYS_CMD_GET_SPREAD_SPRECTRUM:
                                        para.ratio = DDR_nRatio[para.module];
                                        break;

                                case RHAL_SYS_CMD_SET_DDR_PERIOD:
                                         if(para.period == RHAL_SYS_DDR_PERIOD_30K)
                                                DDR_period = 30;
                                        else if(para.period == RHAL_SYS_DDR_PERIOD_33K)
                                                 DDR_period = 33;
                                        else if(para.period == RHAL_SYS_DDR_PERIOD_60K)
                                                DDR_period = 60;
                                        else if(para.period == RHAL_SYS_DDR_PERIOD_66K)
                                                DDR_period = 66;
                                        else
                                        {
                                                nRet = -1;
                                                break;                                                
                                         }
                                         nRet = RHAL_SYS_SetDDRSpreadSpectrum(para.module, DDR_nRatio[para.module]);      
                                         break;
                                        
                                case RHAL_SYS_CMD_GET_DDR_PERIOD:
                                        if(DDR_period == 30)
                                                para.period = RHAL_SYS_DDR_PERIOD_30K;
                                        else if(DDR_period == 33)
                                                 para.period = RHAL_SYS_DDR_PERIOD_33K;
                                        else if(DDR_period == 60)
                                                para.period = RHAL_SYS_DDR_PERIOD_60K;
                                        else if(DDR_period == 66)
                                                para.period = RHAL_SYS_DDR_PERIOD_66K;
                                        else
                                                nRet = -1;
                                        break;

                                 case RHAL_SYS_CMD_GET_SUPPORT_MODULE:
                                        if(para.module == RHAL_SYS_SPREAD_SPECTRUM_MODULE_DDR)
                                                para.module_support = 1;
#ifdef SUPPORT_DCU2
                                        else if(para.module == RHAL_SYS_SPREAD_SPECTRUM_MODULE_DDR2)
                                                para.module_support = 1;
#endif
                                        else
                                                para.module_support = 0;
                                        break;
                                        
                                 default:
                                        nRet = -1;
                                        break;
                        }

                        if(nRet != 0) {
                                retval = -EFAULT;
                                break;
                        }
                        if(copy_to_user((void __user *)arg, (void *)&para, sizeof(DDR_SSC_PARA))) {
                                retval = -EFAULT;
                                break;
                        }
                        break;
                }
               

                case MISC_SET_RTDLOG: {
                        rtk_rtdlog_info_t rtd_log = {0};
                        if(copy_from_user((void *)&rtd_log, (const void __user *)arg, sizeof(rtk_rtdlog_info_t))) {
                                MISC_INFO("[RTDLOG_LEVEL] copy_from_user fail...\n");
                                retval = -EFAULT;
                                break;
                        }
                        console_rtdlog.rtdlog_level = rtd_log.rtdlog_level;
                        console_rtdlog.rtdlog_module = rtd_log.rtdlog_module;
                        console_rtdlog.rtdlog_option = rtd_log.rtdlog_option;
                }
                break;
                case MISC_GET_RTDLOG: {

                        if((unsigned int)rtd_inl(RTD_LOG_CHECKING_REGISTER) == 0xdeadbeef) {
                                /*using unused register 0xb801a610 to check whether to using assert
                                when rtd log fatal
                                */
                                console_rtdlog.rtdlog_option = (console_rtdlog.rtdlog_option | RTD_LOG_CHECK_REG);
                                //MISC_INFO("test the Reg : 0x%x, the option value:%x \n",rtd_inl(RTD_LOG_CHECKING_REGISTER), console_rtdlog.rtdlog_option );
                        }

                        if(copy_to_user((void __user *)arg, (void *)&console_rtdlog, sizeof(rtk_rtdlog_info_t))) {
                                MISC_INFO("[RTDLOG_LEVEL] copy_to_user fail...\n");
                                retval = -EFAULT;
                                break;
                        }
                }
                break;

                /*case MISC_SET_RTDLOG_MODULE:
                {
                    unsigned int log_module = 0;
                    if(copy_from_user((void *)&log_module, (const void __user *)arg, sizeof(unsigned int)))
                    {
                        MISC_INFO("[RTDLOG_MODULE] copy_from_user fail...\n");
                        retval = -EFAULT;
                        break;
                    }
                    console_rtdlog_module = log_module;
                }
                break;

                case MISC_GET_RTDLOG_MODULE:
                {
                    if(copy_to_user((void __user *)arg, (void *)&console_rtdlog_module, sizeof(unsigned int)))
                    {
                        MISC_INFO("[RTDLOG_MODULE] copy_to_user fail...\n");
                        retval = -EFAULT;
                        break;
                    }
                }
                break;*/
#ifdef CONFIG_R8168
                case MISC_SET_WARM_WOL_ENABLE: {
                        int nEnable = arg;

                        if(nEnable) {
                                MISC_INFO( "Enable Warm Standby WOL...\n");
                                // clear STR flag for emcu
                                //rtd_outl(0xb8060110, 0x00000000);
                                // clear share memory for emcu
#define RTD_SHARE_MEM_LEN       32
#define RTD_SHARE_MEM_BASE      0xb8060500
                                MISC_INFO("clear share memory in %s...\n", __FUNCTION__);
                                for(i = 0; i < RTD_SHARE_MEM_LEN; i++)
                                        rtd_outl(RTD_SHARE_MEM_BASE + (4 * i), 0);
                                // set WOL flag enabled for emcu
                                MISC_INFO("set WOL flag enabled for emcu\n");
                                rtd_outl(0xb8060500, (rtd_inl(0xb8060500) & 0xfeffffff) | 0x01000000);
                                // run a thread for WOL polling
                                thread_wol = kthread_run(wol_polling, NULL, "wol_polling");
                                if(IS_ERR(thread_wol)) {
                                        MISC_INFO("create wol_polling thread failed\n");
                                        retval = -EFAULT;
                                        break;
                                }
                                MISC_INFO("create wol_polling thread successfully\n");
                                // 0x18016c10[0] = 0x1 (default =0) before enable emcu clock
                                // gmac clock select  0: gmac/emcu2 use bus clock 1: gmac/emcu2 use GPHY125MHz clock
                                //rtd_outl(0xb8016c10, (rtd_inl(0xb8016c10) & 0xfffffffe) | 0x1);
                                // enable emcu clock
                                //MISC_INFO( "Wake-up ECPU...\n");
                                //rtd_outl(STB_ST_CLKEN1_reg, rtd_inl(STB_ST_CLKEN1_reg) | BIT(9)); // clk enable for emcu
                                //udelay(500);
                                //rtd_outl(STB_ST_SRST1_reg, rtd_inl(STB_ST_SRST1_reg) | BIT(9));       // release reset for emcu
                        } else {
                                MISC_INFO( "Disable WOL...\n");
                                // clear STR flag for emcu
                                //rtd_outl(0xb8060110, 0x00000000);
                                // clear share memory for emcu
                                MISC_INFO("clear share memory in %s...\n", __FUNCTION__);
                                for(i = 0; i < RTD_SHARE_MEM_LEN; i++)
                                        rtd_outl(RTD_SHARE_MEM_BASE + (4 * i), 0);
                                // set WOL flag disabled for emcu
                                MISC_INFO("set WOL flag disabled for emcu\n");
                                rtd_outl(0xb8060500, (rtd_inl(0xb8060500) & 0xfeffffff));
                                // stop a thread for WOL polling
                                rtd_outl(0xb80160b0, 0x70030000);  //0xf0031e00
                                if ( (thread_wol != NULL) && ((rtd_inl(0xb80160b0) & 0xffff) != 0x9e00) ) {
                                        // Resume
                                        rtl8168_resume(network_devs);
                                        MISC_INFO( "ether driver resume for WOL\n");
                                        kthread_stop(thread_wol);
                                        MISC_INFO( "stop wol_polling thread!\n");
                                } else {
                                        MISC_INFO( "%s: WOL:%08x\n", __FUNCTION__, rtd_inl(0xb80160b0));   // check 0x1e00(default)  -->WOL 0x9e00
                                        MISC_INFO( "wol_polling thread does not exist!\n");
                                }
                                // disable emcu clock
                                //rtd_outl(STB_ST_CLKEN1_reg, rtd_inl(STB_ST_CLKEN1_reg) & ~BIT(9));    // clk disable for emcu
                                //udelay(500);
                                //rtd_outl(STB_ST_SRST1_reg, rtd_inl(STB_ST_SRST1_reg) & ~BIT(9));  // hold reset for emcu
                        }
                }
                break;
#endif
                case MISC_GET_WARM_WOL_ENABLE: {
                        int nEnable;

                        if((rtd_inl(0xb8060500) & 0x01000000) != 0)
                                nEnable = true;
                        else
                                nEnable = false;

                        if(copy_to_user((void __user *)arg, (void *)&nEnable, sizeof(int))) {
                                retval = -EFAULT;
                                break;
                        }
                }
                break;
                case MISC_QSM_OFF: {
                       MISC_INFO( "QSM OFF Wake-Up Internal Micom...\n");
#if 0
                       /* disable LVR function */
                       rtd_outl(STB_SC_LV_RST_reg, (rtd_inl(STB_SC_LV_RST_reg) & 0xffffdfff));
                       MISC_INFO("289x rtd_inl(0xb8060004)=%08x\n", rtd_inl(STB_SC_LV_RST_reg));
                       MISC_OSC_Clk_init();
                       MISC_INFO("289x OSC Clk init ok\n");
                       /* tunning OSC & enable OSC */
                        MISC_OSC_tracking();
#endif                 
                       if( rtd_inl(0xb8060110) != 0x9021affa) {   
                           rtd_outl(STB_ST_SRST1_reg, BIT(9));
                           rtd_outl(0xb8060110, 0x9021affc);
                           rtd_outl(STB_ST_CLKEN1_reg, BIT(9) | BIT(0));  // clk enable for emcu
                           udelay(500);
                           rtd_outl(STB_ST_SRST1_reg, BIT(9) | BIT(0));        // release reset for emcu
                           udelay(500);
                           MISC_INFO("289x OSC Clk tracking ok, rtd_inl(0xb8060110)=%08x\n", rtd_inl(0xb8060110));
                        }
                } 
                break;
#ifdef CONFIG_RTK_KDRV_WATCHDOG
                case MISC_SET_WATCHDOG_ENABLE: {
                        int On = arg;
                        watchdog_enable(On);
                }
                break;
#endif

                case MISC_UART_PINMUX_SWITCH:
                {
                        UART_PINMUX_ENABLE_T   param;

                        if(copy_from_user((void *)&param, (const void __user *)arg, sizeof(UART_PINMUX_ENABLE_T )))
                        {
                                retval = -EFAULT;
                                break;
                        }
                        switch(param)
                        {
                                case UART0_PINMUX_ENABLE:
                                        rtd_maskl(0xB8060200, 0x0f0fffff, 0x60600000);
                                        break;
                                case UART1_PINMUX_ENABLE:
                                        rtd_maskl(0xB8060200, 0x0f0fffff, 0x80800000);
                                        rtd_maskl(0xB80008E0, 0xfcffffff, 0x00000000);
                                        break;
                                case UART0_UART1_PINMUX_DISABLE:
                                        rtd_maskl(0xB8060200, 0x0f0fffff, 0xf0f00000);
                                        break;
                                default:
                                        MISC_ERR(KERN_ERR "misc ioctl MISC_UART_PINMUX_SWITCH not supported\n");
                                        retval = -EFAULT;
                                        break;
                        }
                        break;
                }

                case MISC_UART_GET_UART0_ENABLE:
                {
                        unsigned int tmp_val = rtd_inl(0xB8060200);

                        if( (tmp_val & 0xf0f00000) == 0x60600000)
                        {
                                tmp_val = 1;

                        }
                        else
                        {
                                tmp_val = 0;
                        }

                        if(copy_to_user((void __user *)arg, (const void *)&tmp_val, sizeof(unsigned int)))
                        {
                                retval = -EFAULT;
                                goto out;
                        }

                        break;
                }

                case MISC_UART_GET_UART1_ENABLE:
                {
                        unsigned int tmp_val = rtd_inl(0xB8060200);

                        if( (tmp_val & 0xf0f00000) == 0x80800000)
                        {
                                tmp_val = 1;

                        }
                        else
                        {
                                tmp_val = 0;
                        }

                        if(copy_to_user((void __user *)arg, (const void *)&tmp_val, sizeof(unsigned int)))
                        {
                                retval = -EFAULT;
                                goto out;
                        }

                        break;
                }

                default:  /* redundant, as cmd was checked against MAXNR */
                        MISC_ERR("misc ioctl not supported\n");
                        retval = -EFAULT;
                        goto out;
        }
out:
        up(&pdev->sem);
        return retval;
}

/*
Add for rtd_logger to change log module and level
*/

ssize_t misc_read(struct file * filp, char __user * buf, size_t count,
                  loff_t * f_pos)
{
        //using KERN_EMERG to get information at any time
        MISC_EMERG(" ==========Read information==========\n" );
        MISC_EMERG(" LOGGER Module=0x%x\n", console_rtdlog.rtdlog_module );
        MISC_EMERG(" LOGGER level=%d\n", console_rtdlog.rtdlog_level);
        MISC_EMERG(" LOGGER option=0x%x\n", console_rtdlog.rtdlog_option);
        MISC_EMERG(" ========Read information End=========\n" );
        return 0;
}

ssize_t misc_write(struct file * filp, const char __user * buf, size_t count,
                   loff_t * f_pos)
{
        ssize_t retval = -ENOMEM;

        if (count <= 256) {
                uint8_t data[256] = {0};
                if (copy_from_user(data, buf, count)) {
                        retval = -EFAULT;
                        goto out;
                }
                MISC_ERR("[misc_write]Get string =%s\n", data);
                char cmd[20];
                char value[MODULE_STR_SIZE] = {'\n'};
                unsigned int convertValue = 0;

                //sscanf (data,"%s %u",cmd,&convertValue);
                sscanf (data, "%s %s", cmd, value);
                //count  value str size
                char str_length = 0;
                int i = 0;
                for (i = 0; i < MODULE_STR_SIZE; i++) {
                        if ((value[i] >= 'A') && (value[i] <= 'F')) {
                                str_length++;
                        } else if((value[i] >= 'a') && (value[i] <= 'f')) {
                                str_length++;
                        } else if((value[i] >= '0') && (value[i] <= '9')) {
                                str_length++;
                        }
                }

                if(StrToHex(value, str_length, &convertValue) == true) {
                        // MISC_ERR("[misc_write]value  %s convert=0x%x\n",value,convertValue);
                        if(strcmp(cmd, "logmodule") == 0) {
                                // MISC_ERR("[misc_write]convert=%s, 0x%x\n",cmd,convertValue);
                                // console_rtdlog_module = convertValue;
                                console_rtdlog.rtdlog_module = convertValue;
                        } else if(strcmp(cmd, "loglevel") == 0) {
                                //MISC_ERR("[misc_write]convert=%s, 0x%x\n",cmd,convertValue);
                                //console_rtdlog_level = convertValue;
                                console_rtdlog.rtdlog_level = convertValue;
                        } else if(strcmp(cmd, "logoption") == 0) {
                                //MISC_ERR("[misc_write]convert=%s, 0x%x\n",cmd,convertValue);
                                //console_rtdlog_level = convertValue;
                                console_rtdlog.rtdlog_option = convertValue;
                        } else {
                                MISC_ERR("[misc_write]NO USING COMMAND\n");
                        }
                }
        }

        retval = count;

out:
        return retval;
}

static void dump_vo_regs(void)
{
        /*dump VO realted register for checking*/
        rtd_setbits(VODMA_VODMA_V1CHROMA_FMT_reg, BIT(12));
        MISC_INFO("Dump VODMA Setting(1) 0xB8005030(%x), 0xb80050DC(%x),0xb8005000(%x)\n",
                  rtd_inl(VODMA_VODMA_V1CHROMA_FMT_reg),
                  rtd_inl(VODMA_VODMA_dma_option_reg), rtd_inl(VODMA_VODMA_V1_DCFG_reg));

        rtd_clearbits(VODMA_VODMA_V1CHROMA_FMT_reg, BIT(12));
        MISC_INFO("Dump VODMA Setting(0) 0xB8005030(%x), 0xb80050DC(%x),0xb8005000(%x)\n",
                  rtd_inl(VODMA_VODMA_V1CHROMA_FMT_reg),
                  rtd_inl(VODMA_VODMA_dma_option_reg), rtd_inl(VODMA_VODMA_V1_DCFG_reg));

        MISC_INFO("Dump 0xB8005100(%x), 0xB8005104(%x),0xB800500C(%x), 0xB800511C(%x)\n",
                  rtd_inl(0xB8005100), rtd_inl(0xB8005104), rtd_inl(0xB800500C), rtd_inl(0xB800511C));

        MISC_INFO("Dump 0xB8005120(%x), 0xB8005134(%x), 0xB8005144(%x), 0xB8005018(%x)\n",
                  rtd_inl(0xB8005120), rtd_inl(0xB8005134), rtd_inl(0xB8005144), rtd_inl(0xB8005018));

        MISC_INFO("Dump 0xB800501c(%x), 0xB8005020(%x), 0xB8005024(%x), 0xB80050E4(%x)\n",
                  rtd_inl(0xB800501c), rtd_inl(0xB8005020), rtd_inl(0xB8005024), rtd_inl(0xB80050E4));
}

static char* dc_sys_id_str [16][16] = {
        {"TVSB2_DIW",    "TVSB1_VD",      "SB1_CP",       "SB2_KCPU",   "SB3_AEE",    "VE","TVSB3_PST",                  "GPU","TVSB5_DEMOD","NULL","SE2_Q0",  "TVSB4_ODW",               "NULL", "NULL","NULL","NULL"},
        {"TVSB2_DIR",    "TVSB1_AUDIO1",   "SB1_USB_EX",       "SB2_ACPU2",  "SB3_ADE",    "VE","TVSB3_NULL",     "GPU","TVSB5_DBGDMA",  "NULL","SE2_Q1",  "TVSB4_ODR",            "NULL", "NULL","NULL","NULL"},
        {"TVSB2_M_CAP",  "TVSB1_AUDIO2","SB1_USB",      "SB2_ACPU",   "SB3_ME",     "VE","TVSB3_NULL",             "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_DC2H",               "NULL", "NULL","NULL","NULL"},
        {"TVSB2_M_DISP", "TVSB1_VBI",     "SB1_NULL",    "SB2_VCPU2",  "SB3_MD_KCPU","VE","TVSB3_NULL",         "GPU","TVSB5_NULL",  "NULL","SE2_NULL","TVSB4_SUBT",               "NULL","NULL","NULL","NULL"},
        {"TVSB2_S_CAP",  "TVSB1_TVE_VD",  "SB1_TP2",      "SB2_VCPU",   "SB3_VE",     "VE","TVSB3_NULL",            "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_OSD1",                "NULL","NULL","NULL","NULL"},
        {"TVSB2_S_DISP", "TVSB1_TVE_VBI", "SB1_ETN",      "SB2_UART",   "SB3_VDE",    "VE","TVSB3_NULL",           "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_OSD2",               "NULL","NULL","NULL","NULL"},
        {"TVSB2_VO1_Y",  "TVSB1_NULL",    "SB1_TP_KC",    "SB2_HOST_IF","SB3_NULL",    "VE","TVSB3_NULL",        "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_OSD3",               "NULL","NULL","NULL","NULL"},
        {"TVSB2_VO1_C",  "TVSB1_NULL",    "SB1_EMMC_KC",  "SB2_NULL",   "SB3_NULL",   "VE","TVSB3_NULL",        "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_NULL",                "NULL","NULL","NULL","NULL"},
        {"TVSB2_VO2_Y",  "TVSB1_NULL",    "SB1_NULL",     "SB2_NULL",   "SB3_NULL",   "VE","TVSB3_NULL",           "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_NULL",                "NULL","NULL","NULL","NULL"},
        {"TVSB2_VO2_C",  "TVSB1_NULL",    "SB1_NULL",     "SB2_NULL",   "SB3_NULL",   "VE","TVSB3_NULL",           "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_NULL",                "NULL","NULL","NULL","NULL"},
        {"TVSB2_I3DDMA", "TVSB1_NULL",    "SB1_CP_NKC",   "SB2_NULL",   "SB3_UART2",  "VE","TVSB3_NULL",        "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_NULL",               "NULL","NULL","NULL","NULL"},
        {"TVSB2_DE_XC_W","TVSB1_NULL",    "SB1_NULL",   "SB2_NULL",   "SB3_MD_SCPU","VE","TVSB3_NULL",        "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_DMATO3DLUTR",  "NULL","NULL","NULL","NULL"},
        {"TVSB2_DE_XC_R","TVSB1_NULL",    "SB1_TP2_NKC",  "SB2_NULL",   "SB3_MD_VCPU","VE","TVSB3_NULL",     "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_NULL",               "NULL","NULL","NULL","NULL"},
        {"TVSB2_SNR_R",  "TVSB1_NULL",    "SB1_TP_NKC",   "SB2_NULL",   "SB3_NULL",   "VE","TVSB3_NULL",          "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_NULL",               "NULL","NULL","NULL","NULL"},
        {"TVSB2_NULL",   "TVSB1_NULL",    "SB1_EMMC_NKC", "SB2_NULL",   "SB3_NULL",   "VE","TVSB3_NULL",        "GPU","TVSB5_NULL", "NULL","SE2_NULL","TVSB4_OSD_FBDC",        "NULL","NULL","NULL","NULL"},
        {"TVSB2",            "TVSB1",             "SB1",                 "SB2",            "SB3",           "VE", "TVSB3",                "GPU","TVSB5",          "NULL","SE2",     "TVSB4",                                "NULL","NULL","NULL","NULL"}
};

void dump_addcmd_status (unsigned int addcmd0, unsigned int addcmd1)
{
        unsigned int module_id = (addcmd0 >> 15) & 0xFF;
        MISC_INFO("access type: %s\n", (addcmd1 & BIT(1)) ? "write" : "read");
        MISC_INFO("module_ID is 0x%x(%s)\n", module_id,dc_sys_id_str[module_id&0xF][(module_id>>4)&0xF]);
        MISC_INFO("Sequence starting address is : 0x%x (unit: byte).  (0x%x Unit : 8-Byte )\n", ( (addcmd1 & 0x7FFFFFFF) >> 2) << 3, (addcmd1 & 0x7FFFFFFF)>>2);
        MISC_INFO("Sequence burst length ( Unit : 8-Byte ) is : %d\n", (addcmd1 >> 31) + ((addcmd0 & 0x7F)<<1));
}

static void dump_dc_errcmd(int dc_id, int sys_id, char * msg)
{
        int i;
        unsigned int add_hi_reg = (dcsys_errcmd_regs.addcmd_hi[dc_id][sys_id]);
        unsigned int add_lo_reg = (dcsys_errcmd_regs.addcmd_lo[dc_id][sys_id]);
        unsigned int dc_int_reg = (dcsys_errcmd_regs.dc_int[dc_id][sys_id]);
        unsigned int addcmd[2];
        unsigned int trap_case;
        unsigned int mask = BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15);
        char* errcmd_str[8] = {
                "seq_sa_odd",
                "seq_bl_zero",
                "seq_bl_odd",
                "blk_8x2_on_64",
                "blk_size_exceed",
                "blk_err",
                "blk_h_zero",
                "blk_w_zero",
        };

        if (rtd_inl(add_hi_reg) & BIT(31)) {
                trap_case = (rtd_inl(add_hi_reg) & 0x7F800000) >> 23;
                addcmd[0] = (rtd_inl(add_hi_reg) & 0x007FFFFF);
                addcmd[1] = rtd_inl(add_lo_reg);

                MISC_INFO("%s\n", msg);

                MISC_INFO("dump regs\n add_hi_reg 0x%08x = 0x%08x\n add_lo_reg 0x%08x = 0x%08x\n dc_int_reg 0x%08x = 0x%08x\n",
                        add_hi_reg, rtd_inl(add_hi_reg),
                        add_lo_reg, rtd_inl(add_lo_reg),
                        dc_int_reg, rtd_inl(dc_int_reg));
                MISC_INFO("DC error command detected: trap case %08x, addcmd %08x-%08x\n", trap_case, addcmd[0], addcmd[1]);
                for(i = 0; i < 8; ++i) {
                        if(trap_case & (1 << i)) {
                                MISC_INFO("trap case : %d (%s)\n", i, errcmd_str[i]);
                        }
                }
                dump_addcmd_status(addcmd[0], addcmd[1]);
                rtd_outl(dc_int_reg, mask);  //write 0 to clear the pending
        }
}

static void dump_dc_errcmd_reg(int dc_id, int sys_id, char * msg)
{
        unsigned int add_hi_reg = (dcsys_errcmd_regs.addcmd_hi[dc_id][sys_id]);
        unsigned int add_lo_reg = (dcsys_errcmd_regs.addcmd_lo[dc_id][sys_id]);
        unsigned int dc_int_reg = (dcsys_errcmd_regs.dc_int[dc_id][sys_id]);

        MISC_INFO("%s\n", msg);
        MISC_INFO("add_hi_reg(0x%08x),val:0x%08x\n",add_hi_reg,rtd_inl(add_hi_reg));
        MISC_INFO("add_lo_reg(0x%08x),val:0x%08x\n",add_lo_reg,rtd_inl(add_lo_reg));
        MISC_INFO("dc_int_reg(0x%08x),val:0x%08x\n",dc_int_reg,rtd_inl(dc_int_reg));
}

static void dump_dc_errcmd_all(void)
{
        dump_dc_errcmd_reg(DC_ID_1, DC_SYS1, "DC1 SYS1 ERRCMD REG");
        dump_dc_errcmd_reg(DC_ID_1, DC_SYS2, "DC1 SYS2 ERRCMD REG");
        dump_dc_errcmd_reg(DC_ID_1, DC_SYS3, "DC1 SYS3 ERRCMD REG");
        dump_dc_errcmd(DC_ID_1, DC_SYS1, "DC1 SYS1 ERRCMD");
        dump_dc_errcmd(DC_ID_1, DC_SYS2, "DC1 SYS2 ERRCMD");
        dump_dc_errcmd(DC_ID_1, DC_SYS3, "DC1 SYS3 ERRCMD");
}

static void dump_dcsys_debug_status(void)
{
        unsigned int val;
        val = rtd_inl(DC_SYS_DC_debug_status_reg);
        MISC_INFO("DC1 debug status is %08x: \n", val);
        if (val & BIT(25)) {
                MISC_INFO("DC1 BIT 25:  exsram write data fifo underflow\n");
        }
        if (val & BIT(24)) {
                MISC_INFO("DC1 BIT 24:  exsram write data fifo overflow\n");
        }
        if (val & BIT(23)) {
                MISC_INFO("DC1 BIT 23:  DC_SYS3 write cmd fifo underflow\n");
        }
        if (val & BIT(22)) {
                MISC_INFO("DC1 BIT 22:  DC_SYS2 write cmd fifo underflow\n");
        }
        if (val & BIT(21)) {
                MISC_INFO("DC1 BIT 21:  DC_SYS write cmd fifo underflow\n");
        }
        if (val & BIT(20)) {
                MISC_INFO("DC1 BIT 20:  DC_SYS3 read cmd fifo underflow\n");
        }
        if (val & BIT(19)) {
                MISC_INFO("DC1 BIT 19:  DC_SYS2 read cmd fifo underflow\n");
        }
        if (val & BIT(18)) {
                MISC_INFO("DC1 BIT 18:  DC_SYS read cmd fifo underflow\n");
        }
        if (val & BIT(17)) {
                MISC_INFO("DC1 BIT 17:  DC_SYS3 write cmd fifo overflow\n");
        }
        if (val & BIT(16)) {
                MISC_INFO("DC1 BIT 16:  DC_SYS2 write cmd fifo overflow\n");
        }
        if (val & BIT(15)) {
                MISC_INFO("DC1 BIT 15:  DC_SYS write cmd fifo overflow\n");
        }
        if (val & BIT(14)) {
                MISC_INFO("DC1 BIT 14:  DC_SYS3 read cmd fifo overflow\n");
        }
        if (val & BIT(13)) {
                MISC_INFO("DC1 BIT 13:  DC_SYS2 read cmd fifo overflow\n");
        }
        if (val & BIT(12)) {
                MISC_INFO("DC1 BIT 12:  DC_SYS read cmd fifo overflow\n");
        }
        if (val & BIT(11)) {
                MISC_INFO("DC1 BIT 11:  DC_SYS3 write data fifo underflow\n");
        }
        if (val & BIT(10)) {
                MISC_INFO("DC1 BIT 10:  DC_SYS2 write data fifo underflow\n");
        }
        if (val & BIT(9)) {
                MISC_INFO("DC1 BIT 9:  DC_SYS write data fifo underflow\n");
        }
        if (val & BIT(8)) {
                MISC_INFO("DC1 BIT 8:  DC_SYS3 read data fifo underflow\n");
        }
        if (val & BIT(7)) {
                MISC_INFO("DC1 BIT 7:  DC_SYS2 read data fifo underflow\n");
        }
        if (val & BIT(6)) {
                MISC_INFO("DC1 BIT 6:  DC_SYS read data fifo underflow\n");
        }
        if (val & BIT(5)) {
                MISC_INFO("DC1 BIT 5:  DC_SYS3 write data fifo overflow\n");
        }
        if (val & BIT(4)) {
                MISC_INFO("DC1 BIT 4:  DC_SYS2 write data fifo overflow\n");
        }
        if (val & BIT(3)) {
                MISC_INFO("DC1 BIT 3:  DC_SYS write data fifo overflow\n");
        }
        if (val & BIT(2)) {
                MISC_INFO("DC1 BIT 2:  DC_SYS3 read data fifo overflow\n");
        }
        if (val & BIT(1)) {
                MISC_INFO("DC1 BIT 1:  DC_SYS2 read data fifo overflow\n");
        }
        if (val & BIT(0)) {
                MISC_INFO("DC1 BIT 0:  DC_SYS read data fifo overflow\n");
        }

}

static void dump_mc_error_status(unsigned int reg, char * msg)
{
        unsigned int val;
        MISC_INFO("[%s]reg val:0x%08x\n", msg, reg);
        if(reg & BIT(30)) {
                MISC_INFO("[%s] ASYNC FIFO for wdata from DC_SYS overflows\n", msg);
        }
        if(reg & BIT(29)) {
                MISC_INFO("[%s] ASYNC FIFO for command from DC_SYS overflows\n", msg);
        }
        if(reg & BIT(27)) {
                MISC_INFO("[%s] Tag with wdata ack from MC mismatch with the expected qfifo cmd tag from DC_SYS\n", msg);
        }
        if(reg & BIT(26)) {
                MISC_INFO("[%s] Tag with rdata valid from MC mismatch with the expected qfifo cmd tag from DC_SYS\n", msg);
        }
        if(reg & BIT(25)) {
                MISC_INFO("[%s] Burst length of write command from DC_SYS mismatch with the one from MC\n", msg);
        }
        if(reg & BIT(24)) {
                MISC_INFO("[%s] Burst length of read command from DC_SYS mismatch with the one from MC\n", msg);
        }

        val = reg & 0x3F0;
        val = val >> 4;
        MISC_INFO("[%s] The maximum number of read command ever reached in MC_FIFO is 0x%08x\n", msg, val);

        val = reg & 0x7;
        MISC_INFO("[%s] The bank number of the maximum number of write command ever reached in MC_FIFO is 0x%08x\n", msg, val);
}

static void dump_mc_error_status_all(void)
{
        unsigned int mc1_fifo_dbg_cmd0_val = rtd_inl(0xB8008930);
        unsigned int mc1_fifo_dbg_cmd1_val = rtd_inl(0xB8008934);
        unsigned int mc1_fifo_dbg_cmd2_val = rtd_inl(0xB8008938);
        unsigned int mc1_fifo_dbg_cmd3_val = rtd_inl(0xB800893C);

        dump_mc_error_status(mc1_fifo_dbg_cmd0_val, "MC1 SCPU");
        dump_mc_error_status(mc1_fifo_dbg_cmd1_val, "MC1 DCSYS1");
        dump_mc_error_status(mc1_fifo_dbg_cmd2_val, "MC1 DCSYS2");
        dump_mc_error_status(mc1_fifo_dbg_cmd3_val, "MC1 DCSYS3");
}

int is_dcsys_errcmd(void)
{
        int i, j;
        for(i = 0; i < DC_NUMBER; ++i) {
                for(j = 0; j < DC_SYS_NUMBER; ++j) {
                        if(rtd_inl(dcsys_errcmd_regs.addcmd_hi[i][j]) & BIT(31)) {
                                return 1;
                        }
                }
        }

        return 0;
}

void dump_128bit_bridge_error_status(unsigned int val, char * msg)
{
        unsigned int tmp;
        char * Error_zero_length_id_str[16] = {
                "none error",
                "De-Interlace(W)",
                "De-Interlace(R)",
                "Main Capture(W)",
                "Main Display(R)",
                "Sub Capture (W)",
                "Sub Display (R)",
                "VO1_Y (R)",
                "VO1_C (C)",
                "VO2_Y (R)",
                "VO2_C (R)",
                "I3DDMA (W)",
                "DE_XC(W)",
                "DE_XC(R)",
                "SNR(R)",
                "UNKNOWN"
        };

        MISC_INFO("[%s]reg val:0x%08x\n", msg, val);

        char * Error_req_id[16] = {
                "none error",
                "De-Interlace(W)",
                "De-Interlace(R)",
                "Main Capture(W)",
                "Main Display(R)",
                "Sub Capture (W)",
                "Sub Display (R)",
                "VO1_Y (R)",
                "VO1_C (R)",
                "VO2_Y (R)",
                "VO2_C (R)",
                "I3DDMA (W)",
                "DE_XC(W)",
                "DE_XC(R)",
                "SNR(R)",
                "UNKNOWN"
        };

        if(val & 0xF000) {
                tmp = (val & 0xF000) >> 12;
                MISC_INFO("%s - Error_zero_length : %s\n", msg, Error_zero_length_id_str[tmp]);
        }

        if(val & BIT(9)) {
                MISC_INFO("%s - Error_read_full\n", msg);
        }

        if(val & BIT(8)) {
                MISC_INFO("%s - Error_write_full\n", msg);
        }

        if(val & 0xF) {
                tmp = val & 0xF;
                MISC_INFO("%s - Error_req : %s\n", msg, Error_req_id[tmp]);
        }
}

void dump_128bit_bridge_error_status_all(void)
{
        unsigned int sb2_dcu1_error_status = rtd_inl(0xB801C4FC);
        unsigned int sb3_dcu1_error_status = rtd_inl(0xB801C5FC);
        unsigned int sb4_dcu1_error_status = rtd_inl(0xB801C6FC);
        unsigned int sb5_dcu1_error_status = rtd_inl(0xB801C7FC);

        dump_128bit_bridge_error_status(sb2_dcu1_error_status, "128bit_sb2_error");
        dump_128bit_bridge_error_status(sb3_dcu1_error_status, "128bit_sb3_error");
        dump_128bit_bridge_error_status(sb4_dcu1_error_status, "128bit_sb4_error");
        dump_128bit_bridge_error_status(sb5_dcu1_error_status, "128bit_sb5_error");
}

void dump_64bit_bridge_error_status(unsigned int val, char * msg)
{
        unsigned int tmp;

        MISC_INFO("[%s]reg val:0x%08x\n", msg, val);

        if(val & BIT(30)) {
                MISC_INFO("%s : err_bl_zero\n", msg);
        }

        if(val & BIT(29)) {
                MISC_INFO("%s : err_blk_wxh_odd\n", msg);
        }

        tmp = val & 0x0F000000;
        tmp = tmp >> 24;
        MISC_INFO("%s : max_wcmd_in_fifo is %d\n", msg, tmp);

        tmp = val & 0x00F00000;
        tmp = tmp >> 20;
        MISC_INFO("%s : max_rcmd_in_fifo is %d\n", msg, tmp);

        tmp = val & 0x000FC000;
        tmp = tmp >> 14;
        MISC_INFO("%s : max_wait_wdone is %d\n", msg, tmp);

        tmp = val & 0x00003F80;
        tmp = tmp >> 7;
        MISC_INFO("%s : max_wdata_in_fifo is %d\n", msg, tmp);

        tmp = val & 0x0000007F;
        MISC_INFO("%s : max_rdata_in_fifo is %d\n", msg, tmp);
}

void dump_64bit_bridge_error_status_all(void)
{
        unsigned int dc_64_err_status_aio_status = rtd_inl(0xB8007F10);
        unsigned int dc_64_err_status_sb1_status = rtd_inl(0xB8007F14);
        unsigned int dc_64_err_status_sb3_status = rtd_inl(0xB8007F18);

        dump_64bit_bridge_error_status(dc_64_err_status_aio_status, "dc_64_err_status_aio");
        dump_64bit_bridge_error_status(dc_64_err_status_sb1_status, "dc_64_err_status_sb1");
        dump_64bit_bridge_error_status(dc_64_err_status_sb3_status, "dc_64_err_status_sb3");
}

irqreturn_t misc_isr (int irq, void *dev_id)
{
        if(!is_dcsys_errcmd())
                return IRQ_NONE;

        //dump_vo_regs();
        MISC_INFO("MISC ISR Dump Stacks!!!!\n");

        dump_stacks();

        dump_dc_errcmd_all();

        dump_dcsys_debug_status();

        dump_mc_error_status_all();

        dump_128bit_bridge_error_status_all();

        dump_64bit_bridge_error_status_all();

        panic("%s detected error!",__FUNCTION__);

        return IRQ_HANDLED;
}

//                          Add for new device PM driver.
#ifdef CONFIG_PM
static int misc_pm_suspend(
        struct device           *dev
)
{
        return 0;
}

static int misc_pm_resume(
        struct device           *dev
)
{
        MISC_INFO("misc resume\n");

        /* enable error commands detection of DCSYS1 and DCSYS2 */
        rtd_outl(DC_SYS_DC_int_enable_reg, BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(0));
        rtd_outl(DC_SYS_DC_int_enable_SYS2_reg, BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(0));
        rtd_outl(DC_SYS_DC_int_enable_SYS3_reg, BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(0));
        rtd_outl(DC_SYS_DC_EC_CTRL_reg, BIT(3) | BIT(2) | BIT(1) | BIT(0));

        rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, BIT(11) | BIT(0));   //enable global interrupt

		rtk_ddr_debug_resume();
        return 0;
}

static struct platform_device *misc_platform_devs;

static struct platform_driver misc_device_driver = {
        .suspend    = misc_pm_suspend,
        .resume     = misc_pm_resume,
        .driver = {
                .name       = "sys-misc",
                .bus        = &platform_bus_type,
        } ,
} ;
#endif // CONFIG_PM

struct file_operations misc_fops = {
        .owner              = THIS_MODULE,
        .unlocked_ioctl     = misc_ioctl,
        .open               = misc_open,
        .release            = misc_release,
        .read           = misc_read,
        .write = misc_write,
};

/*
 * Finally, the module stuff
 */

/*
 * The cleanup function is used to handle initialization failures as well.
 * Thefore, it must be careful to work correctly even if some of the items
 * have not been initialized
 */
void misc_cleanup_module(void)
{
        dev_t dev = MKDEV(misc_major, misc_minor);

        MISC_INFO( "misc clean module\n");

        /* Get rid of our char dev entries */
        if (misc_drv_dev) {
                device_destroy(misc_class, dev);
                cdev_del(&misc_drv_dev->cdev);
                kfree(misc_drv_dev);
#ifdef CONFIG_PM
                platform_device_unregister(misc_platform_devs);
#endif
        }

        unregister_chrdev_region(dev, 1);
}

static void init_dc_errcmd_regs(void)
{
        dcsys_errcmd_regs.addcmd_hi[0][0] = DC_SYS_DC_EC_ADDCMD_HI_reg;
        dcsys_errcmd_regs.addcmd_hi[0][1] = DC_SYS_DC_EC_ADDCMD_HI_SYS2_reg;
        dcsys_errcmd_regs.addcmd_hi[0][2] = DC_SYS_DC_EC_ADDCMD_HI_SYS3_reg;

        dcsys_errcmd_regs.addcmd_lo[0][0] = DC_SYS_DC_EC_ADDCMD_LO_reg;
        dcsys_errcmd_regs.addcmd_lo[0][1] = DC_SYS_DC_EC_ADDCMD_LO_SYS2_reg;
        dcsys_errcmd_regs.addcmd_lo[0][2] = DC_SYS_DC_EC_ADDCMD_LO_SYS3_reg;

        dcsys_errcmd_regs.dc_int[0][0] = DC_SYS_DC_int_status_reg;
        dcsys_errcmd_regs.dc_int[0][1] = DC_SYS_DC_int_status_SYS2_reg;
        dcsys_errcmd_regs.dc_int[0][2] = DC_SYS_DC_int_status_SYS3_reg;
}

int misc_init_module(void)
{
        int result;
        dev_t dev = 0;

        /*
         * Get a range of minor numbers to work with, asking for a dynamic
         * major unless directed otherwise at load time.
         */

        MISC_INFO( " ***************** misc init module ********************* \n");
        if (misc_major) {
                dev = MKDEV(misc_major, misc_minor);
                result = register_chrdev_region(dev, 1, "sys-misc");
        } else {
                result = alloc_chrdev_region(&dev, misc_minor, 1, "sys-misc");
                misc_major = MAJOR(dev);
        }
        if (result < 0) {
                MISC_ERR("misc: can't get major %d\n", misc_major);
                return result;
        }

        MISC_INFO( "misc init module major number = %d\n", misc_major);

        misc_class = class_create(THIS_MODULE, "sys-misc");
        if (IS_ERR(misc_class))
                return PTR_ERR(misc_class);

        device_create(misc_class, NULL, dev, NULL, "sys-misc");

        /*
         * allocate the devices
         */
        misc_drv_dev = kmalloc(sizeof(struct misc_dev), GFP_KERNEL);
        if (!misc_drv_dev) {
                device_destroy(misc_class, dev);
                result = -ENOMEM;
                goto fail;  /* Make this more graceful */
        }
        memset(misc_drv_dev, 0, sizeof(struct misc_dev));

        //initialize device structure
        sema_init(&misc_drv_dev->sem, 1);
        cdev_init(&misc_drv_dev->cdev, &misc_fops);
        misc_drv_dev->cdev.owner = THIS_MODULE;
        misc_drv_dev->cdev.ops = &misc_fops;
        result = cdev_add(&misc_drv_dev->cdev, dev, 1);
        /* Fail gracefully if need be */
        if (result) {
                device_destroy(misc_class, dev);
                kfree(misc_drv_dev);
                MISC_ERR("Error %d adding cdev misc", result);
                goto fail;
        }

#ifdef CONFIG_PM
        misc_platform_devs = platform_device_register_simple("sys-misc", -1, NULL, 0);

        if(platform_driver_register(&misc_device_driver) != 0) {
                device_destroy(misc_class, dev);
                cdev_del(&misc_drv_dev->cdev);
                kfree(misc_drv_dev);
                misc_platform_devs = NULL;
                goto fail;  /* Make this more graceful */
        }
#endif  //CONFIG_PM

        /* Request IRQ */
        if(request_irq(IRQ_DCSYS,
                       misc_isr,
                       IRQF_SHARED,
                       "DC error command detection",
                       misc_isr)) {
                MISC_ERR("MISC: cannot register IRQ %d\n", IRQ_DCSYS);
                return ;
        }

        /* enable error commands detection of DCSYS1 and DCSYS2 */
        rtd_outl(DC_SYS_DC_int_enable_reg, BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(0));
        rtd_outl(DC_SYS_DC_int_enable_SYS2_reg, BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(0));
        rtd_outl(DC_SYS_DC_int_enable_SYS3_reg, BIT(22) | BIT(21) | BIT(20) | BIT(19) | BIT(18) | BIT(17) | BIT(16) | BIT(15) | BIT(0));
        rtd_outl(DC_SYS_DC_EC_CTRL_reg, BIT(3) | BIT(2) | BIT(1) | BIT(0));

        rtd_outl(SYS_REG_INT_CTRL_SCPU_reg, BIT(11) | BIT(0));    //enable global interrupt

        init_dc_errcmd_regs();

        return 0; /* succeed */

fail:
        return result;
}

module_init(misc_init_module);
module_exit(misc_cleanup_module);

#include <mach/rtk_platform.h> 
#define DDR_DEBUG_RAM_DUMMY_ADDR	0xb8008EB0 // Dora gave
#define DDR_DEBUG_RAM_INVALID		0xbeef2379

unsigned int ddr_debug_ram_addr = 0;

static void rtk_ddr_debug_fill_dummy(unsigned int addr)
{
	rtd_outl(DDR_DEBUG_RAM_DUMMY_ADDR, addr);
}

static void rtk_ddr_debug_init_dummy(void)
{
	unsigned long addr = 0 ;
	unsigned long size = 0 ;

	size = carvedout_buf_query(CARVEDOUT_K_OS, (void **)&addr);

	if (size > 0) {
		// Use addr and size here
		ddr_debug_ram_addr = addr;
		rtk_ddr_debug_fill_dummy(ddr_debug_ram_addr);
	} else {
		rtk_ddr_debug_fill_dummy(DDR_DEBUG_RAM_INVALID);
		pr_err("No Security OS memory is reserved\n");
	}
}

static void rtk_ddr_debug_resume(void)
{
	rtk_ddr_debug_fill_dummy(ddr_debug_ram_addr);
}

static int __init rtk_ddr_debug_init(void)
{
	rtk_ddr_debug_init_dummy();

	return 0;
}
late_initcall(rtk_ddr_debug_init);
