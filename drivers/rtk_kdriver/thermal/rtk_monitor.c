/* rtk hw monitor
 *
 * Created by: davidwang@realtek.com
 * Copyright: (C) 2015 Realtek Semiconductor Corp.
 *
 *
 */

#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/mutex.h>
#include <linux/time.h>
#include <linux/kobject.h>
#include <linux/delay.h>
#include <linux/err.h> /* IS_ERR() PTR_ERR() */
#include <asm/io.h>    /* rtd_inl() rtd_outl() ... */
#if (defined CONFIG_RTK_KDRIVER) || (defined CONFIG_RTK_KDRIVER_SUPPORT)
#include <rtk_kdriver/rtk_thermal_sensor.h>
#include <rtk_kdriver/rtk_gpio.h>
#else
#include <mach/rtk_thermal_sensor.h>
#include <mach/rtk_gpio.h>
#endif
#include <linux/freezer.h>
#include <rbus/stb_reg.h>
#include <tvscalercontrol/scaler_vbedev.h>
#include <rbus/vby1_reg.h>
#include <rbus/pinmux_lvdsphy_reg.h>
static DEFINE_MUTEX(rtk_monitor_activation_lock);
static DEFINE_MUTEX(rtk_monitor_delay_lock);
static unsigned int rtk_monitor_active = 0;
static unsigned int rtk_monitor_delay = 1000; // ms
#ifdef VBE_DISP_TCON_SELF_CHECK
unsigned int monitor_rgb_rolling = 0;
#include "tvscalercontrol/io/ioregdrv.h"
#include <rbus/mdomain_disp_reg.h>
#endif

//#define CONFIG_RTK_ZQ_ENABLE
static struct task_struct *rtk_monitor_task;

static unsigned long pre_jiffies;

unsigned int test_mode = 0, ZQ_Config = 0;

unsigned int counter = 0;
unsigned int hwsetting_result[6];
unsigned int DC1_R480_max = 0, DC1_R480_min = 100;
unsigned int DC2_R480_max = 0, DC2_R480_min = 100;
unsigned int DC1_SET_max[8], DC1_SET_min[8];
unsigned int DC2_SET_max[8], DC2_SET_min[8];
unsigned int DC1_R480[32], DC2_R480[32];
unsigned int DC1_PMOS_SET0[16], DC1_PMOS_SET1[16], DC1_PMOS_SET2[16], DC1_PMOS_SET3[16];
unsigned int DC1_NMOS_SET0[16], DC1_NMOS_SET1[16], DC1_NMOS_SET2[16], DC1_NMOS_SET3[16];
unsigned int DC2_PMOS_SET0[16], DC2_PMOS_SET1[16], DC2_PMOS_SET2[16], DC2_PMOS_SET3[16];
unsigned int DC2_NMOS_SET0[16], DC2_NMOS_SET1[16], DC2_NMOS_SET2[16], DC2_NMOS_SET3[16];
unsigned int DC1_R480_err_msg[2], DC2_R480_err_msg[2];
unsigned int DC1_R480_Total[32], DC2_R480_Total[32];
unsigned int DC1_PMOS_SET0_Total[16], DC1_PMOS_SET1_Total[16], DC1_PMOS_SET2_Total[16], DC1_PMOS_SET3_Total[16];
unsigned int DC1_NMOS_SET0_Total[16], DC1_NMOS_SET1_Total[16], DC1_NMOS_SET2_Total[16], DC1_NMOS_SET3_Total[16];
unsigned int DC2_PMOS_SET0_Total[16], DC2_PMOS_SET1_Total[16], DC2_PMOS_SET2_Total[16], DC2_PMOS_SET3_Total[16];
unsigned int DC2_NMOS_SET0_Total[16], DC2_NMOS_SET1_Total[16], DC2_NMOS_SET2_Total[16], DC2_NMOS_SET3_Total[16];

#define DC1_OCDP_SET0 0xb8008374
#define DC1_OCDN_SET0 0xb8008378
#define DC1_OCDP_SET1 0xb800825C
#define DC1_OCDN_SET1 0xb8008260
#define DC1_PAD_RZCTRL_STATUS 0xb8008388
#define DC1_PAD_BUS_0 0xb80082FC
#define DC1_PAD_BUS_1 0xb8008300
#define DC1_PAD_CTRL_PROG 0xb800821C
#define DC1_PAD_CTRL_ZPROG 0xb8008598
#define DC1_PAD_ZCTRL_STATUS 0xb8008220
#define DC1_READ_CTRL_2 0xb800852C

#define DC2_OCDP_SET0 0xb8004374
#define DC2_OCDN_SET0 0xb8004378
#define DC2_OCDP_SET1 0xb800425C
#define DC2_OCDN_SET1 0xb8004260
#define DC2_PAD_RZCTRL_STATUS 0xb8004388
#define DC2_PAD_BUS_0 0xb80042FC
#define DC2_PAD_BUS_1 0xb8004300
#define DC2_PAD_CTRL_PROG 0xb800421C
#define DC2_PAD_CTRL_ZPROG 0xb8004598
#define DC2_PAD_ZCTRL_STATUS 0xb8004220
#define DC2_READ_CTRL_2 0xb800452C

//dummy reg. from 0xb80083D4, 83D8, 43CC~43D8
#define ZQFW_CTRL1 0xb80083D4
#define ZQFW_CTRL2 0xb80083D8
#define ZQFW_SET_REG 0xb80043CC //43CC,43D0,43D4,43D8

static void Array_init(unsigned int Array[], unsigned int element, unsigned int value)
{
    unsigned int i;

    for(i = 0; i < element; i++)
        Array[i] = value;
}

static void Get_Ori_ZQ_Phase(unsigned int flag)
{
    unsigned int Reg[6] = {DC1_OCDP_SET0, DC1_OCDN_SET0, DC2_OCDP_SET0, DC2_OCDN_SET0, DC1_PAD_RZCTRL_STATUS, DC2_PAD_RZCTRL_STATUS};
    unsigned int i;

    if(flag == 0) {
        Array_init(hwsetting_result, 6, 0);
        for(i = 0; i < 6; i++) {
            if(i < 4)
                hwsetting_result[i] = rtd_inl(Reg[i]);
            else
                hwsetting_result[i] = (rtd_inl(Reg[i]) & 0x3E) >> 1; //[5:1]
        }
    } else if(flag == 1) {
        for(i = 0; i < 6; i++)
            pr_debug("[ZqHwsetting]0x%08x=0x%x", Reg[i], hwsetting_result[i]);
    }
}

static void Kernal_ZqCalibration(unsigned int OCD_flag)
{
    unsigned int tmp_val = 0, print_flag = 10;
    unsigned int total_SET = 4; //SET0~3
    unsigned int i, loop;
    unsigned int R480_test_loop = 5, OCD_test_loop = 5;
    unsigned int R480_max_loop, ZQ_max_loop;
    unsigned int PMOS_SET[4], NMOS_SET[4];
    unsigned int R480, PMOS[4], NMOS[4];
    unsigned int loop_delay, para_delay;

    rtd_maskl(ZQFW_CTRL1, 0xffffefff, 0x1000); //[12]=1 zq fw start

    if((test_mode & 0x2) == 0x2) { //[1]Main Enable
        Array_init(PMOS_SET, 4, 0);
        Array_init(NMOS_SET, 4, 0);
        Array_init(PMOS, 4, 0);
        Array_init(NMOS, 4, 0);
        R480 = 0;

        loop_delay = ((rtd_inl(ZQFW_CTRL2) & 0xf00) >> 8) * 100; //[11:8]
        para_delay = ((rtd_inl(ZQFW_CTRL2) & 0xf000) >> 12) * 100; //[15:12]

        if((test_mode & 0x1) == 0x1) { //[0]:debug msg1
            // ZQ Calibration
            for(i = 0; i < total_SET; i++) {
                tmp_val = ZQFW_SET_REG + i * 4;
                pr_debug ("[ZqCalDebugInfo]: value(0x%08x): 0x%08x \n", tmp_val, rtd_inl(tmp_val));
            }
        }

        if((ZQ_Config & 0x2) == 0x2) //[1]=1,R480 one time calibration
            R480_max_loop = 1;
        else
            R480_max_loop = R480_test_loop;
        if((ZQ_Config & 0x4) == 0x4) //[2]=1,SET0~3 one time calibration
            ZQ_max_loop = 1;
        else
            ZQ_max_loop = OCD_test_loop;


        //**DCU1 R480 Cal.**//
        if((test_mode & 0x4) == 0x4) { // [2]DCU1 R480 CAl. Enable
            for(loop = 0; loop < R480_max_loop; loop++) { //scan loop
                rtd_maskl(DC1_PAD_BUS_1, 0xFFFFFFBF, 0x00000000);   //zq pad[6] 0:on/1:off
                rtd_maskl(DC1_PAD_BUS_0, 0xEFFFFFFF, 0x10000000);   //vref_sel[28]=1 (1:from DDR Gen., 2: from sys bandgap)
                rtd_maskl(DC1_PAD_CTRL_PROG, 0xFFFEFFFF, 0x00010000); // [16]=1,R480 calibration enable
                //while((rtd_inl(DC1_PAD_RZCTRL_STATUS)&0x1) == 0x0); // [0] R480 calibration done
                usleep_range(10, 20);
                if((test_mode & 0x10) == 0x10) { // [4]:R480 msg
                    if((rtd_inl(DC1_PAD_RZCTRL_STATUS) & 0x1) != 0x1)
                        pr_debug ("[ZqCalDebugInfo]: R480 cal. failed(DCU1)!\n");
                    pr_debug ("[ZqCalDebugInfo]: value(0x%08x): 0x%08x ", DC1_PAD_RZCTRL_STATUS, rtd_inl(DC1_PAD_RZCTRL_STATUS));
                    pr_debug (" [5:1]:rzq_480code(DCU1)    \n");
                }
                rtd_maskl(DC1_PAD_CTRL_PROG, 0xFFFEFFFF, 0x00000000); // [16]=0,R480 calibration Disable

                //**calibration result**//
                tmp_val = (rtd_inl(DC1_PAD_RZCTRL_STATUS) & 0x3E) >> 1; //[5:1]
                R480 += tmp_val;
                if((ZQ_Config & 0x20000) == 0x20000) //[17]=1,record all scan results
                    DC1_R480_Total[tmp_val]++;
                if((test_mode & 0x10) == 0x10) // [4]:R480 msg
                    pr_debug("[ZqDebug]: %d)DC1_R480=%d\n", loop + 1, tmp_val);
                if((tmp_val < 0) || (tmp_val > 31)) {
                    DC1_R480_err_msg[0] += 1; //err counter
                    DC1_R480_err_msg[1] = tmp_val;
                    if((test_mode & 0x10) == 0x10) // [4]:R480 msg
                        pr_info("[ZqErrorMsg] ERROR!!DC1_R480=%d\n", tmp_val);
                }
                if(tmp_val > DC1_R480_max) {
                    DC1_R480_max = tmp_val;
                    pr_debug("[ZqCompare]: DC1_R480_max=%d\n", DC1_R480_max);
                }
                if(tmp_val < DC1_R480_min) {
                    DC1_R480_min = tmp_val;
                    pr_debug("[ZqCompare]: DC1_R480_min=%d\n", DC1_R480_min);
                }
            }//scan loop(s)

            if(R480_max_loop == R480_test_loop) { //multi-round of R480 calibration
                if((R480_test_loop - (R480 % R480_test_loop)) > (R480 % R480_test_loop))
                    R480 = R480 / R480_test_loop;
                else
                    R480 = 1 + (R480 / R480_test_loop);
            }

            if((ZQ_Config & 0x10000) == 0x10000) //[16]=1,record average result
                DC1_R480[R480]++;
            if((test_mode & 0x10) == 0x10) // [4]:R480 msg
                pr_debug("[ZqAverage]: DC1_R480=%d\n", R480);

            //**phase set**//
            rtd_maskl(DC1_PAD_RZCTRL_STATUS, 0xffffffC1, R480 << 1); //DC1 R480[5:1]
        }//end of [2]DCU1 R480 CAl. Enable


        //**DCU1 ZQ Calibration for SET0~3**//
        rtd_maskl(DC1_PAD_CTRL_PROG, 0xF7FFFFFF, 0x00000000);   // [27]=0,Disable Update Immediately
        rtd_maskl(DC1_PAD_CTRL_PROG, 0xFFFBFFFF, 0x00000000);   // [18]=0,Disable Update during Refresh

        for(i = 0; i < total_SET; i++) { //SET0~3
            tmp_val = rtd_inl(ZQFW_SET_REG + i * 4); //SET_i

            if((tmp_val & 0x40000000) == 0x40000000) { //if [30]=1 DC1 zq cal. SET_i is enable
                for(loop = 0; loop < ZQ_max_loop; loop++) { //scan loop
                    rtd_maskl(DC1_PAD_CTRL_PROG, 0x8FFFFFFF, ((0x1 * i) << 28)); // Enable auto update OCD / ODT set0~set7 [30:28]=0x1*i
                    rtd_maskl(DC1_PAD_CTRL_ZPROG, 0xF8000000, tmp_val); //[31:30]:DCU2/DCU1 zq cal. enable bits; [29:0]=tmp_val
                    rtd_maskl(DC1_PAD_CTRL_PROG, 0xFEFFFFFF, 0x01000000); // [24]=1,Calibration Start
                    //while((rtd_inl(DC1_PAD_ZCTRL_STATUS)&0x80000000) == 0x0); //wait[31]=1,wait calibration done
                    usleep_range(10, 20);
                    if((test_mode & 0x1) == 0x1) { // [0]:debug msg
                        if((rtd_inl(DC1_PAD_ZCTRL_STATUS) & 0x80000000) != 0x80000000)
                            pr_debug ("[ZqCalDebugInfo]: zq cal. failed(DCU1)!\n");
                        pr_debug ("[ZqCalDebugInfo]: value(0x%08x,0x%08x): 0x%08x, 0x%08x", DC1_PAD_CTRL_ZPROG, DC1_PAD_ZCTRL_STATUS, rtd_inl(DC1_PAD_CTRL_ZPROG), rtd_inl(DC1_PAD_ZCTRL_STATUS));
                        pr_debug (" [31:0]:zctrl_status(DCU1 SET%d)  \n", i);
                    }
                    rtd_maskl(DC1_PAD_CTRL_PROG, 0xFEFFFFFF, 0x00000000);    // [24]=0,Disable Calibration

                    //**calibration result**//
                    //DC1 PMOS OCD SET0~3[3:0][7:4][11:8][15:12], NMOS SET0~3
                    PMOS[i] = (rtd_inl(DC1_OCDP_SET0) >> (i * 4)) & 0xf;
                    PMOS_SET[i] += PMOS[i];
                    if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
                        pr_debug("[ZqDebug]: %d)DC1_PMOS_SET%d=%d\n", loop + 1, i, PMOS[i]);
                    if(PMOS[i] > DC1_SET_max[i]) {
                        DC1_SET_max[i] = PMOS[i];
                        pr_debug("[ZqCompare]: DC1_PMOS_SET%d_max=%d\n", i, DC1_SET_max[i]);
                    }
                    if(PMOS[i] < DC1_SET_min[i]) {
                        DC1_SET_min[i] = PMOS[i];
                        pr_debug("[ZqCompare]: DC1_PMOS_SET%d_min=%d\n", i, DC1_SET_min[i]);
                    }
                    //DC1 NMOS OCD SET0~3, NMOS SET0~3
                    NMOS[i] = (rtd_inl(DC1_OCDN_SET0) >> (i * 4)) & 0xf;
                    NMOS_SET[i] += NMOS[i];
                    if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
                        pr_debug("[ZqDebug]: %d)DC1_NMOS_SET%d=%d\n", loop + 1, i, NMOS[i]);
                    if(NMOS[i] > DC1_SET_max[i + 4]) {
                        DC1_SET_max[i + 4] = NMOS[i];
                        pr_debug("[ZqCompare]: DC1_NMOS_SET%d_max=%d\n", i, DC1_SET_max[i + 4]);
                    }
                    if(NMOS[i] < DC1_SET_min[i + 4]) {
                        DC1_SET_min[i + 4] = NMOS[i];
                        pr_debug("[ZqCompare]: DC1_NMOS_SET%d_min=%d\n", i, DC1_SET_min[i + 4]);
                    }

                    if((ZQ_Config & 0x20000) == 0x20000) { //[17]=1,record all scan results
                        if(i == 0) {
                            DC1_PMOS_SET0_Total[PMOS[i]]++;
                            DC1_NMOS_SET0_Total[NMOS[i]]++;
                        } else if(i == 1) {
                            DC1_PMOS_SET1_Total[PMOS[i]]++;
                            DC1_NMOS_SET1_Total[NMOS[i]]++;
                        } else if(i == 2) {
                            DC1_PMOS_SET2_Total[PMOS[i]]++;
                            DC1_NMOS_SET2_Total[NMOS[i]]++;
                        } else if(i == 3) {
                            DC1_PMOS_SET3_Total[PMOS[i]]++;
                            DC1_NMOS_SET3_Total[NMOS[i]]++;
                        }
                    }
                }//scan loop(s)

                if(ZQ_max_loop == OCD_test_loop) { //multi-round of ZQ SET0~3 calibration
                    if((OCD_test_loop - (PMOS_SET[i] % OCD_test_loop)) > (PMOS_SET[i] % OCD_test_loop))
                        PMOS_SET[i] = PMOS_SET[i] / OCD_test_loop;
                    else
                        PMOS_SET[i] = 1 + (PMOS_SET[i] / OCD_test_loop);

                    if((OCD_test_loop - (NMOS_SET[i] % OCD_test_loop)) > (NMOS_SET[i] % OCD_test_loop))
                        NMOS_SET[i] = NMOS_SET[i] / OCD_test_loop;
                    else
                        NMOS_SET[i] = 1 + (NMOS_SET[i] / OCD_test_loop);
                }//[2]=1, five rounds of ZQ SET0~3 calibration

                if((ZQ_Config & 0x10000) == 0x10000) { //[16]=1,record average result
                    if(i == 0) {
                        DC1_PMOS_SET0[PMOS_SET[i]]++;
                        DC1_NMOS_SET0[NMOS_SET[i]]++;
                    } else if(i == 1) {
                        DC1_PMOS_SET1[PMOS_SET[i]]++;
                        DC1_NMOS_SET1[NMOS_SET[i]]++;
                    } else if(i == 2) {
                        DC1_PMOS_SET2[PMOS_SET[i]]++;
                        DC1_NMOS_SET2[NMOS_SET[i]]++;
                    } else if(i == 3) {
                        DC1_PMOS_SET3[PMOS_SET[i]]++;
                        DC1_NMOS_SET3[NMOS_SET[i]]++;
                    }
                }
                if((test_mode & 0x20) == 0x20) { // [5]:ZQ msg
                    pr_debug("[ZqAverage]: DC1_PMOS_SET%d=%d\n", i, PMOS_SET[i]);
                    pr_debug("[ZqAverage]: DC1_NMOS_SET%d=%d\n", i, NMOS_SET[i]);
                }

                //**phase set**//
                rtd_maskl(DC1_OCDP_SET0, ~(0xf << (i * 4)), PMOS_SET[i] << (i * 4)); //DC1 PMOS OCD SET0[3:0][7:4][11:8][15:12]
                rtd_maskl(DC1_OCDN_SET0, ~(0xf << (i * 4)), NMOS_SET[i] << (i * 4)); //DC1 NMOS OCD SET0[3:0]

            }//if zq cal. SET_i is enable
        }//SET0~3

        if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
            pr_debug ("[ZqCalDebugInfo]: value(0x%08x,0x%08x): 0x%08x, 0x%08x", DC1_OCDP_SET0, DC1_OCDN_SET0, rtd_inl(DC1_OCDP_SET0), rtd_inl(DC1_OCDN_SET0));

        rtd_maskl(DC1_PAD_CTRL_PROG, 0xFFFBFFFF, 0x00040000);   // [18]=1,Enable Update during Refresh
        if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
            pr_debug ("[ZqCalDebugInfo]: value(0x%08x,0x%08x): 0x%08x, 0x%08x", DC1_OCDP_SET1, DC1_OCDN_SET1, rtd_inl(DC1_OCDP_SET1), rtd_inl(DC1_OCDN_SET1));


        //DC2
        Array_init(PMOS_SET, 4, 0);
        Array_init(NMOS_SET, 4, 0);
        Array_init(PMOS, 4, 0);
        Array_init(NMOS, 4, 0);
        R480 = 0;

        //**DCU2 R480 Cal.**//
        if((test_mode & 0x8) == 0x8) { // [3] DCU2 R480 CAl. Enable
            for(loop = 0; loop < R480_max_loop; loop++) { //scan loop
                rtd_maskl(DC2_PAD_BUS_1, 0xFFFFFFBF, 0x00000000);   //zq pad[6] 0:on/1:off
                rtd_maskl(DC2_PAD_BUS_0, 0xEFFFFFFF, 0x10000000);   //vref_sel[28]=1 (1:from DDR Gen., 2: from sys bandgap)
                rtd_maskl(DC2_PAD_CTRL_PROG, 0xFFFEFFFF, 0x00010000); // [16]=1,R480 calibration enable
                //while((rtd_inl(DC2_PAD_RZCTRL_STATUS)&0x1) == 0x0); // [0] R480 calibration done
                usleep_range(10, 20);
                if((test_mode & 0x10) == 0x10) { // [4]:R480 msg
                    if((rtd_inl(DC2_PAD_RZCTRL_STATUS) & 0x1) != 0x1)
                        pr_debug ("[ZqCalDebugInfo]: R480 cal. failed(DCU2)!\n");
                    pr_debug ("[ZqCalDebugInfo]: value(0x%08x): 0x%08x ", DC2_PAD_RZCTRL_STATUS, rtd_inl(DC2_PAD_RZCTRL_STATUS));
                    pr_debug (" [5:1]:rzq_480code(DCU2)    \n");
                }
                rtd_maskl(DC2_PAD_CTRL_PROG, 0xFFFEFFFF, 0x00000000); // [16]=0,R480 calibration Disable

                //**calibration result**//
                tmp_val = (rtd_inl(DC2_PAD_RZCTRL_STATUS) & 0x3E) >> 1; //[5:1]
                R480 += tmp_val;
                if((ZQ_Config & 0x20000) == 0x20000) //[17]=1,record all scan results
                    DC2_R480_Total[tmp_val]++;
                if((test_mode & 0x10) == 0x10) // [4]:R480 msg
                    pr_debug("[ZqDebug]: %d)DC2_R480=%d\n", loop + 1, tmp_val);
                if((tmp_val < 0) || (tmp_val > 31)) {
                    DC2_R480_err_msg[0] += 1; //err counter
                    DC2_R480_err_msg[1] = tmp_val;
                    if((test_mode & 0x10) == 0x10) // [4]:R480 msg
                        pr_info("[ZqErrorMsg] ERROR!!DC2_R480=%d\n", tmp_val);
                }
                if(tmp_val > DC2_R480_max) {
                    DC2_R480_max = tmp_val;
                    pr_debug("[ZqCompare]: DC2_R480_max=%d\n", DC2_R480_max);
                }
                if(tmp_val < DC2_R480_min) {
                    DC2_R480_min = tmp_val;
                    pr_debug("[ZqCompare]: DC2_R480_min=%d\n", DC2_R480_min);
                }
            }//scan loop(s)

            if(R480_max_loop == R480_test_loop) { //[1]=1, five rounds of R480 calibration
                if((R480_test_loop - (R480 % R480_test_loop)) > (R480 % R480_test_loop))
                    R480 = R480 / R480_test_loop;
                else
                    R480 = 1 + (R480 / R480_test_loop);
            }

            if((ZQ_Config & 0x10000) == 0x10000) //[16]=1,record average result
                DC2_R480[R480]++;
            if((test_mode & 0x10) == 0x10) // [4]:R480 msg
                pr_debug("[ZqAverage]: DC2_R480=%d\n", R480);

            //**phase set**//
            rtd_maskl(DC2_PAD_RZCTRL_STATUS, 0xffffffC1, R480 << 1); //DC2 R480[5:1]
        }//end of [2]DCU2 R480 CAl. Enable

        //**DCU2 ZQ Calibration for SET0~3**//
        rtd_maskl(DC2_PAD_CTRL_PROG, 0xF7FFFFFF, 0x00000000);   // [27]=0,Disable Update Immediately
        rtd_maskl(DC2_PAD_CTRL_PROG, 0xFFFBFFFF, 0x00000000);   // [18]=0,Disable Update during Refresh

        for(i = 0; i < total_SET; i++) { //SET0~3
            tmp_val = rtd_inl(ZQFW_SET_REG + i * 4); //SET_i

            if((tmp_val & 0x80000000) == 0x80000000) { //if [31]=1 DC2 zq cal. SET_i is enable
                for(loop = 0; loop < ZQ_max_loop; loop++) { //scan loop
                    rtd_maskl(DC2_PAD_CTRL_PROG, 0x8FFFFFFF, ((0x1 * i) << 28)); // Enable auto update OCD / ODT set0~set7 [30:28]=0x1*i
                    rtd_maskl(DC2_PAD_CTRL_ZPROG, 0xF8000000, tmp_val); //[31:30]:DCU2/DCU1 zq cal. enable bits; [29:0]=tmp_val
                    rtd_maskl(DC2_PAD_CTRL_PROG, 0xFEFFFFFF, 0x01000000); // [24]=1,Calibration Start
                    //while((rtd_inl(DC2_PAD_ZCTRL_STATUS)&0x80000000) == 0x0); //wait[31]=1,wait calibration done
                    usleep_range(10, 20);
                    if((test_mode & 0x1) == 0x1) { // [0]:debug msg
                        if((rtd_inl(DC2_PAD_ZCTRL_STATUS) & 0x80000000) != 0x80000000)
                            pr_debug ("[ZqCalDebugInfo]: zq cal. failed(DCU2)!\n");
                        pr_debug ("[ZqCalDebugInfo]: value(0x%08x,0x%08x): 0x%08x, 0x%08x", DC2_PAD_CTRL_ZPROG, DC2_PAD_ZCTRL_STATUS, rtd_inl(DC2_PAD_CTRL_ZPROG), rtd_inl(DC2_PAD_ZCTRL_STATUS));
                        pr_debug (" [31:0]:zctrl_status(DCU2 SET%d)  \n", i);
                    }
                    rtd_maskl(DC2_PAD_CTRL_PROG, 0xFEFFFFFF, 0x00000000);    // [24]=0,Disable Calibration

                    //**calibration result**//
                    //DC2 PMOS OCD SET0~3[3:0][7:4][11:8][15:12], NMOS SET0~3
                    PMOS[i] = (rtd_inl(DC2_OCDP_SET0) >> (i * 4)) & 0xf;
                    PMOS_SET[i] += PMOS[i];
                    if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
                        pr_debug("[ZqDebug]: %d)DC2_PMOS_SET%d=%d\n", loop + 1, i, PMOS[i]);
                    if(PMOS[i] > DC2_SET_max[i]) {
                        DC2_SET_max[i] = PMOS[i];
                        pr_debug("[ZqCompare]: DC2_PMOS_SET%d_max=%d\n", i, DC2_SET_max[i]);
                    }
                    if(PMOS[i] < DC2_SET_min[i]) {
                        DC2_SET_min[i] = PMOS[i];
                        pr_debug("[ZqCompare]: DC2_PMOS_SET%d_min=%d\n", i, DC2_SET_min[i]);
                    }
                    //DC2 NMOS OCD SET0~3, NMOS SET0~3
                    NMOS[i] = (rtd_inl(DC2_OCDN_SET0) >> (i * 4)) & 0xf;
                    NMOS_SET[i] += NMOS[i];
                    if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
                        pr_debug("[ZqDebug]: %d)DC2_NMOS_SET%d=%d\n", loop + 1, i, NMOS[i]);
                    if(NMOS[i] > DC2_SET_max[i + 4]) {
                        DC2_SET_max[i + 4] = NMOS[i];
                        pr_debug("[ZqCompare]: DC2_NMOS_SET%d_max=%d\n", i, DC2_SET_max[i + 4]);
                    }
                    if(NMOS[i] < DC2_SET_min[i + 4]) {
                        DC2_SET_min[i + 4] = NMOS[i];
                        pr_debug("[ZqCompare]: DC2_NMOS_SET%d_min=%d\n", i, DC2_SET_min[i + 4]);
                    }

                    if((ZQ_Config & 0x20000) == 0x20000) { //[17]=1,record all scan results
                        if(i == 0) {
                            DC2_PMOS_SET0_Total[PMOS[i]]++;
                            DC2_NMOS_SET0_Total[NMOS[i]]++;
                        } else if(i == 1) {
                            DC2_PMOS_SET1_Total[PMOS[i]]++;
                            DC2_NMOS_SET1_Total[NMOS[i]]++;
                        } else if(i == 2) {
                            DC2_PMOS_SET2_Total[PMOS[i]]++;
                            DC2_NMOS_SET2_Total[NMOS[i]]++;
                        } else if(i == 3) {
                            DC2_PMOS_SET3_Total[PMOS[i]]++;
                            DC2_NMOS_SET3_Total[NMOS[i]]++;
                        }
                    }
                }//scan loop(s)

                if(ZQ_max_loop == OCD_test_loop) { //[2]=1, five rounds of ZQ SET0~3 calibration
                    if((OCD_test_loop - (PMOS_SET[i] % OCD_test_loop)) > (PMOS_SET[i] % OCD_test_loop))
                        PMOS_SET[i] = PMOS_SET[i] / OCD_test_loop;
                    else
                        PMOS_SET[i] = 1 + (PMOS_SET[i] / OCD_test_loop);

                    if((OCD_test_loop - (NMOS_SET[i] % OCD_test_loop)) > (NMOS_SET[i] % OCD_test_loop))
                        NMOS_SET[i] = NMOS_SET[i] / OCD_test_loop;
                    else
                        NMOS_SET[i] = 1 + (NMOS_SET[i] / OCD_test_loop);
                }//[2]=1, multi-rounds of ZQ SET0~3 calibration

                if((ZQ_Config & 0x10000) == 0x10000) { //[16]=1,record average result
                    if(i == 0) {
                        DC2_PMOS_SET0[PMOS_SET[i]]++;
                        DC2_NMOS_SET0[NMOS_SET[i]]++;
                    } else if(i == 1) {
                        DC2_PMOS_SET1[PMOS_SET[i]]++;
                        DC2_NMOS_SET1[NMOS_SET[i]]++;
                    } else if(i == 2) {
                        DC2_PMOS_SET2[PMOS_SET[i]]++;
                        DC2_NMOS_SET2[NMOS_SET[i]]++;
                    } else if(i == 3) {
                        DC2_PMOS_SET3[PMOS_SET[i]]++;
                        DC2_NMOS_SET3[NMOS_SET[i]]++;
                    }
                }
                if((test_mode & 0x20) == 0x20) { // [5]:ZQ msg
                    pr_debug("[ZqAverage]: DC2_PMOS_SET%d=%d\n", i, PMOS_SET[i]);
                    pr_debug("[ZqAverage]: DC2_NMOS_SET%d=%d\n", i, NMOS_SET[i]);
                }

                //**phase set**//
                rtd_maskl(DC2_OCDP_SET0, ~(0xf << (i * 4)), PMOS_SET[i] << (i * 4)); //DC2 PMOS OCD SET0[3:0][7:4][11:8][15:12]
                rtd_maskl(DC2_OCDN_SET0, ~(0xf << (i * 4)), NMOS_SET[i] << (i * 4)); //DC2 NMOS OCD SET0[3:0]

            }//if zq cal. SET_i is enable
        }//SET0~3

        if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
            pr_debug ("[ZqCalDebugInfo]: value(0x%08x,0x%08x): 0x%08x, 0x%08x", DC2_OCDP_SET0, DC2_OCDN_SET0, rtd_inl(DC2_OCDP_SET0), rtd_inl(DC2_OCDN_SET0));

        rtd_maskl(DC2_PAD_CTRL_PROG, 0xFFFBFFFF, 0x00040000);   // [18]=1,Enable Update during Refresh
        if((test_mode & 0x20) == 0x20) // [5]:ZQ msg
            pr_debug ("[ZqCalDebugInfo]: value(0x%08x,0x%08x): 0x%08x, 0x%08x", DC2_OCDP_SET1, DC2_OCDN_SET1, rtd_inl(DC2_OCDP_SET1), rtd_inl(0xb8004560));

        //log print
        if((ZQ_Config & 0x18) != 0) //[4:3]log
            counter++;
        if(counter == print_flag) {
            //DC1
            if((DC1_R480_err_msg[0] > 0) && ((test_mode & 0x10) == 0x10)) //[4]:R480 msg
                pr_debug("[ZqErrorMsg] DC1_R480 error cnt=%d, last value=%d\n", DC1_R480_err_msg[0], DC1_R480_err_msg[1]);
            if((DC2_R480_err_msg[0] > 0) && ((test_mode & 0x10) == 0x10)) //[4]:R480 msg
                pr_debug("[ZqErrorMsg] DC2_R480 error cnt=%d, last value=%d\n", DC2_R480_err_msg[0], DC2_R480_err_msg[1]);

            if((ZQ_Config & 0x8) == 0x8) { //[3]=1,averaged calibration results
                pr_debug("\n[ZqSummary]: DC1_R480\n");
                for(i = 0; i < 32; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_R480[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_PMOS_SET0\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET0[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_NMOS_SET0\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET0[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_PMOS_SET1\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET1[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_NMOS_SET1\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET1[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_PMOS_SET2\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET2[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_NMOS_SET2\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET2[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_PMOS_SET3\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET3[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC1_NMOS_SET3\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET3[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                //DC2
                pr_debug("\n[ZqSummary]: DC2_R480\n");
                for(i = 0; i < 32; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_R480[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_PMOS_SET0\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET0[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_NMOS_SET0\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET0[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_PMOS_SET1\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET1[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_NMOS_SET1\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET1[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_PMOS_SET2\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET2[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_NMOS_SET2\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET2[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_PMOS_SET3\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET3[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqSummary]: DC2_NMOS_SET3\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET3[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);
            } //averaged result

            //Total count result, DC1
            if((ZQ_Config & 0x10) == 0x10) { //[4]=1,record all scan results
                pr_debug("\n[ZqTotalCnt]: DC1_R480_Total\n");
                for(i = 0; i < 32; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_R480_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_PMOS_SET0_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET0_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_NMOS_SET0_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET0_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_PMOS_SET1_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET1_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_NMOS_SET1_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET1_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_PMOS_SET2_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET2_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_NMOS_SET2_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET2_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_PMOS_SET3_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_PMOS_SET3_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC1_NMOS_SET3_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC1_NMOS_SET3_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                //DC2
                pr_debug("\n[ZqTotalCnt]: DC2_R480_Total\n");
                for(i = 0; i < 32; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_R480_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_PMOS_SET0_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET0_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_NMOS_SET0_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET0_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_PMOS_SET1_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET1_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_NMOS_SET1_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET1_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_PMOS_SET2_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET2_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_NMOS_SET2_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET2_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_PMOS_SET3_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_PMOS_SET3_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                pr_debug("\n[ZqTotalCnt]: DC2_NMOS_SET3_Total\n");
                for(i = 0; i < 16; i++) {
                    if(loop_delay > 0)
                        usleep_range(loop_delay, loop_delay + 10);
                    pr_debug("%d,%d;\n", i, DC2_NMOS_SET3_Total[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);
            } //edn of record all scan results

            if((ZQ_Config & 0x20) == 0x20) { //[5]=1, max and min for each set
                for(i = 0; i < total_SET; i++) { //SET0~3
                    pr_debug("[ZqCompare]: DC1_PMOS_SET%d_max=%d\n", i, DC1_SET_max[i]);
                    pr_debug("[ZqCompare]: DC1_PMOS_SET%d_min=%d\n", i, DC1_SET_min[i]);
                }
                if(para_delay > 0)
                    usleep_range(para_delay, para_delay + 10);

                for(i = 0; i < total_SET; i++) { //SET0~3
                    pr_debug("[ZqCompare]: DC2_PMOS_SET%d_max=%d\n", i, DC2_SET_max[i]);
                    pr_debug("[ZqCompare]: DC2_PMOS_SET%d_min=%d\n", i, DC2_SET_min[i]);
                }
            }

            counter = 0;

        }// print result
    } //end of Main enable

    rtd_maskl(ZQFW_CTRL1, 0xffffdfff, 0x2000); //[13]=1 zq fw finish
}

static int Trim_mode_Enable(int Trim_mode_flag)
{
    int i;

    //Trim mode enable
    for(i = 0; i < 4; i++) { //SET0~3
        rtd_maskl(DC1_READ_CTRL_2 + 4 * i, 0xFFBFFFFF, 0x00400000); // [22]Trim mode enable=1
        rtd_maskl(DC1_READ_CTRL_2 + 4 * i, 0xFF7FFFFF, 0x00800000); // [23]load in
        rtd_maskl(DC2_READ_CTRL_2 + 4 * i, 0xFFBFFFFF, 0x00400000); // Trim mode enable=1
        rtd_maskl(DC2_READ_CTRL_2 + 4 * i, 0xFF7FFFFF, 0x00800000); // load in
    }
    Trim_mode_flag = 1;
    if((test_mode & 0x1) == 0x1) //[0]:debug msg1
        pr_debug ("[ZqDebug]: Trim mode enabled.\n");

    return Trim_mode_flag;
}

static int Trim_mode_Disable(int Trim_mode_flag)
{
    int i;

    //Trim mode disable
    for(i = 0; i < 4; i++) {
        rtd_maskl(DC1_READ_CTRL_2 + 4 * i, 0xFF7FFFFF, 0x00000000); // [23]load disable
        rtd_maskl(DC1_READ_CTRL_2 + 4 * i, 0xFFBFFFFF, 0x00000000); // [22]Trim mode disable=0
        rtd_maskl(DC2_READ_CTRL_2 + 4 * i, 0xFF7FFFFF, 0x00000000); // load disable
        rtd_maskl(DC2_READ_CTRL_2 + 4 * i, 0xFFBFFFFF, 0x00000000); // Trim mode disable=0
    }
    Trim_mode_flag = 0;
    if((test_mode & 0x1) == 0x1) //[0]:debug msg1
        pr_debug ("[ZqDebug]: Trim mode disabled.\n");

    return Trim_mode_flag;
}

static int rtk_monitor_thread(void *arg)
{
    struct sched_param param = { .sched_priority = 1 };
//  unsigned int diff;

    int reg_value;
    int monitor_value = 0;
    int monitor_tmp = 0;
    int monitor_diff, flag = 0;
    int Trim_mode_flag = 100, onetime_flag = 0;
    unsigned int OCD_flag = 0;
    unsigned int trim_mode_on = 115, trim_mode_off = 105;

    //rtk_gpio_set_dir(rtk_gpio_id(MIS_GPIO, 59), 0);

    sched_setscheduler_nocheck(current, SCHED_FIFO, &param);

    pre_jiffies = jiffies; // initial

#ifdef CONFIG_RTK_ZQ_ENABLE
    rtd_maskl(ZQFW_CTRL1, 0xfffff0ff, 0x100); //[11:8]zq fw version 1
    counter = 0;
    ZQ_Config = rtd_inl(ZQFW_CTRL2);
    Array_init(DC1_R480_err_msg, 2, 0);
    Array_init(DC2_R480_err_msg, 2, 0);
    Array_init(DC1_SET_max, 8, 0);
    Array_init(DC1_SET_min, 8, 100);
    Array_init(DC2_SET_max, 8, 0);
    Array_init(DC2_SET_min, 8, 100);

    Array_init(DC1_R480, 32, 0);
    Array_init(DC2_R480, 32, 0);
    Array_init(DC1_PMOS_SET0, 16, 0);
    Array_init(DC1_PMOS_SET1, 16, 0);
    Array_init(DC1_PMOS_SET2, 16, 0);
    Array_init(DC1_PMOS_SET3, 16, 0);
    Array_init(DC1_NMOS_SET0, 16, 0);
    Array_init(DC1_NMOS_SET1, 16, 0);
    Array_init(DC1_NMOS_SET2, 16, 0);
    Array_init(DC1_NMOS_SET3, 16, 0);
    Array_init(DC2_PMOS_SET0, 16, 0);
    Array_init(DC2_PMOS_SET1, 16, 0);
    Array_init(DC2_PMOS_SET2, 16, 0);
    Array_init(DC2_PMOS_SET3, 16, 0);
    Array_init(DC2_NMOS_SET0, 16, 0);
    Array_init(DC2_NMOS_SET1, 16, 0);
    Array_init(DC2_NMOS_SET2, 16, 0);
    Array_init(DC2_NMOS_SET3, 16, 0);

    Array_init(DC1_R480_Total, 32, 0);
    Array_init(DC2_R480_Total, 32, 0);
    Array_init(DC1_PMOS_SET0_Total, 16, 0);
    Array_init(DC1_PMOS_SET1_Total, 16, 0);
    Array_init(DC1_PMOS_SET2_Total, 16, 0);
    Array_init(DC1_PMOS_SET3_Total, 16, 0);
    Array_init(DC1_NMOS_SET0_Total, 16, 0);
    Array_init(DC1_NMOS_SET1_Total, 16, 0);
    Array_init(DC1_NMOS_SET2_Total, 16, 0);
    Array_init(DC1_NMOS_SET3_Total, 16, 0);
    Array_init(DC2_PMOS_SET0_Total, 16, 0);
    Array_init(DC2_PMOS_SET1_Total, 16, 0);
    Array_init(DC2_PMOS_SET2_Total, 16, 0);
    Array_init(DC2_PMOS_SET3_Total, 16, 0);
    Array_init(DC2_NMOS_SET0_Total, 16, 0);
    Array_init(DC2_NMOS_SET1_Total, 16, 0);
    Array_init(DC2_NMOS_SET2_Total, 16, 0);
    Array_init(DC2_NMOS_SET3_Total, 16, 0);

    Get_Ori_ZQ_Phase(0); //get original phase
#endif

    do {
        set_freezable();
#if 0 //test
        diff = jiffies_to_msecs(jiffies - pre_jiffies);
        pre_jiffies = jiffies;

        pr_info("diff=%d\n", diff);
#endif

        reg_value = rtk_get_thermal_reg();
        monitor_value = reg_value & 0x7FFFF;
        if((monitor_value & 0x40000) == 0x40000) { //if [18]=1,negative temperature
            monitor_value = monitor_value - 1;
            monitor_value = (~monitor_value) & 0x0003FFFF;
            monitor_value = -monitor_value;
        }
        monitor_value = (1000 * monitor_value) / 1024;
        /*adding the highest temperatue value*/
        if((monitor_value % 1000) < 0)
            pr_debug("[Rtk Monitor] =%3d.%03d Highest:%d reg:%x\n", monitor_value / 1000, -(monitor_value % 1000), (rtd_inl(0xb8060134) & 0x00FF0000) >> 16, reg_value);
        else
            pr_debug("[Rtk Monitor] =%3d.%03d Highest:%d reg:%x\n", monitor_value / 1000, monitor_value % 1000, (rtd_inl(0xb8060134) & 0x00FF0000) >> 16, reg_value);
	if(monitor_value/1000 > 125)
		pr_crit("[Rtk Monitor]:%d reg:%x\n",monitor_value/1000,reg_value);

        {
            int previous_value = (rtd_inl(STB_WDOG_DATA14_reg) & (0x00ff0000)) >> 16;
            int val = monitor_value / 1000;
            if((val > 0) && (val < 255)) {
                //keep the highest temperature value
                if(val > previous_value)
                    rtd_maskl(STB_WDOG_DATA14_reg, 0xFF00FFFF, (val) << 16);
            } else { //invalid value
                rtd_maskl(STB_WDOG_DATA14_reg, 0xFF00FFFF, (0xff) << 16);
            }
        }

#ifdef CONFIG_RTK_ZQ_ENABLE
        OCD_flag = 0;
        test_mode = rtd_inl(ZQFW_CTRL1); //[7]:auto OCD; [6]:ZQ per sec; [5]:ZQ msg; [4]:R480 msg; [3:2]:DCU2/DCU1 R480 Cal Enable; [1]:Main Enable; [0]:debug msg
        ZQ_Config = rtd_inl(ZQFW_CTRL2);

        if((ZQ_Config & 0x40) == 0x40) //[6]=1
            Get_Ori_ZQ_Phase(1); //log print

        if((test_mode & 0x00000080) == 0x00000080) { //[7]=1, Auto OCD enable
            if((monitor_value / 1000) <= 60)
                OCD_flag = 1;
        }

        if((ZQ_Config & 0x80) == 0x0) { //[7]=0, Trim mode controller
            if((monitor_value / 1000) > trim_mode_on) {
                if(Trim_mode_flag != 0)
                    Trim_mode_flag = Trim_mode_Disable(Trim_mode_flag);
            } else if((monitor_value / 1000) < trim_mode_off) {
                if(Trim_mode_flag != 1)
                    Trim_mode_flag = Trim_mode_Enable(Trim_mode_flag);
            }
        }

        if(((ZQ_Config & 0x1) == 0x1) && (onetime_flag == 0)) { //[0]=1,one time calibration
            Kernal_ZqCalibration(OCD_flag);
            onetime_flag = 1;
        } else {
            if((test_mode & 0x00000040) == 0x00000000) { //[6]=0 update by monitor_diff > 10 or <-10
                if(flag == 0)
                    monitor_tmp = monitor_value;
                monitor_diff = (monitor_tmp - monitor_value) / 1000;
                if((flag == 0) || (monitor_diff > 10) || (monitor_diff < -10)) {
                    Kernal_ZqCalibration(OCD_flag); //DDR zq cal.
                    monitor_tmp = monitor_value;
                    flag = 1;
                }
            } else //[6]=1, update zq by second
                Kernal_ZqCalibration(OCD_flag);
        }
#endif
#ifdef CONFIG_FIXED_ME_443
#ifdef VBE_DISP_TCON_SELF_CHECK
        if((!(IoReg_Read32(MDOMAIN_DISP_dispm_comp_decomp_dbg_mux_reg)&_BIT31)) && (monitor_rgb_rolling == 0)) {
            vbe_disp_always_check_tcon();//every 1second to check
        }
#endif
#endif
        msleep(rtk_monitor_delay);

    } while (!kthread_should_stop());

    return 0;
}

static struct task_struct * rtk_monitor_thread_create(void)
{
    struct task_struct *task = NULL;
    int err;

    task = kthread_create(rtk_monitor_thread, NULL, "rtk_monitor_thread");
    if (IS_ERR(task)) {
        err = PTR_ERR(task);
        pr_err("%s failed (%d)\n", __func__, err);
        task = NULL;
        return task;
    }

    wake_up_process(task);
    return task;
}

static int rtk_monitor_enable(void)
{
    int ret = 0;

    mutex_lock(&rtk_monitor_activation_lock);

    if (rtk_monitor_active) {
        mutex_unlock(&rtk_monitor_activation_lock);
        return 0;
    }

    rtk_monitor_task = rtk_monitor_thread_create();

    if (rtk_monitor_task == NULL) {
        ret = -1;
        goto out;
    }

    rtk_monitor_active = 1;

out:
    mutex_unlock(&rtk_monitor_activation_lock);

    if (rtk_monitor_task != NULL)
        pr_info("rtk monitor thread created\n");
    else
        pr_err("rtk monitor thread NOT created\n");

    return ret;
}

static void rtk_monitor_disable(void)
{
    mutex_lock(&rtk_monitor_activation_lock);

    if (!rtk_monitor_active)
        goto out;

    kthread_stop(rtk_monitor_task);

    rtk_monitor_active = 0;

out:
    mutex_unlock(&rtk_monitor_activation_lock);
}

ssize_t rtk_monitor_active_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%u\n", rtk_monitor_active);
}

ssize_t rtk_monitor_active_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    int ret;

    switch (buf[0]) {
        case '0':
            rtk_monitor_disable();
            ret = 0;
            break;
        case '1':
            ret = rtk_monitor_enable();
            break;
        default:
            ret = -EINVAL;
    }

    return (ret >= 0) ? count : ret;
}

ssize_t rtk_monitor_delay_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%u\n", rtk_monitor_delay);
}

ssize_t rtk_monitor_delay_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
    int ret;

    mutex_lock(&rtk_monitor_delay_lock);
    ret = sscanf(buf, "%u", &rtk_monitor_delay);
    if (ret != 1) {
        mutex_unlock(&rtk_monitor_delay_lock);
        return -EINVAL;
    }

//out:
    mutex_unlock(&rtk_monitor_delay_lock);
    return count;
}

#if 0 // move to sysfs.c
static struct kobj_attribute rtk_monitor_active_attr =
    __ATTR(active, 0644, rtk_monitor_active_show, rtk_monitor_active_store);

static struct kobj_attribute rtk_monitor_delay_attr =
    __ATTR(delay, 0644, rtk_monitor_delay_show, rtk_monitor_delay_store);

//static struct attribute *rtk_monitor_attrs[] = {
//  &rtk_monitor_active_attr.attr,
//  &rtk_monitor_delay_attr.attr,
//  NULL,
//};

//static struct attribute_group rtk_monitor_attr_group = {
//  .attrs = rtk_monitor_attrs,
//};

static struct kobject *rtk_monitor_kobj;
extern struct kobject *realtek_boards_kobj;

static int __init rtk_monitor_sysfs_init(void)
{
    int ret;

//  rtk_monitor_kobj = kobject_create_and_add("rtk_monitor", kernel_kobj);
//  if (!rtk_monitor_kobj)
//      return -ENOMEM;
//  ret = sysfs_create_group(rtk_monitor_kobj, &rtk_monitor_attr_group);
//  if (ret)
//      kobject_put(rtk_monitor_kobj);

    if (!realtek_boards_kobj)
        return -ENOMEM;

    rtk_monitor_kobj = kobject_create();
    ret = kobject_set_name(rtk_monitor_kobj, "rtk_monitor");
    if (ret)
        goto out;
    ret = kobject_add(rtk_monitor_kobj, realtek_boards_kobj, "rtk_monitor");
    if (ret)
        goto out;

    ret = sysfs_create_file(rtk_monitor_kobj, &rtk_monitor_active_attr.attr);
    ret |= sysfs_create_file(rtk_monitor_kobj, &rtk_monitor_delay_attr.attr);
    if (ret)
        kobject_put(rtk_monitor_kobj);

out:
    return ret;
}
#endif

static int __init rtk_monitor_init(void)
{
    int ret;

    init_rtk_thermal_sensor();

    ret = rtk_monitor_enable();
    if (ret)
        return ret;

#if 0 // move to sysfs.c
    ret = rtk_monitor_sysfs_init();
    if (ret)
        pr_err("%s: unable to create sysfs entry\n", __func__);
#endif

    return 0;
}

late_initcall(rtk_monitor_init);
