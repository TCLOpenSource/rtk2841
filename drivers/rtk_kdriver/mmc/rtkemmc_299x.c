/*
 * Realtek MMC/SD/SDIO driver
 *
 * Authors:
 * Copyright (C) 2008-2009 Realtek Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/mbus.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include  <linux/dmapool.h>
#include <linux/scatterlist.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/mmc/host.h>
#include <asm/unaligned.h>

#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/semaphore.h>
#include <linux/mmc/card.h>
#include <linux/mmc/mmc.h>
#include <linux/mmc/sd.h>
#include <linux/workqueue.h>
#include <linux/completion.h>
#include <linux/time.h>
#include <rbus/mmc_reg.h>
#include <rbus/mmc_p_reg.h>
#include <rbus/misc_reg.h>
#include "rtksdio_299x.h"
#include "rtksd_ops.h"
#include <mach/platform.h>
#include <mach/pcbMgr.h>
#include <rbus/sb2_reg.h>

#ifdef CONFIG_REALTEK_OF
#include <linux/of_irq.h>
#include <linux/of_address.h>
#endif
/************************************************************************
 *  Local Define
 ************************************************************************/
#define DRIVER_NAME "rtkemmc_dw"
#define BANNER      "Realtek eMMC Driver"
#define VERSION "$Id: rtkemmc.c RTK_284X 2018-08-28 14:45 $"

#ifdef CONFIG_ARM64
    extern u32 gic_irq_find_mapping(u32 hwirq);
    #define IRQ_GET_KERNEL_IRQ_NUM(hwirq)            gic_irq_find_mapping(hwirq)
#else
    #define IRQ_GET_KERNEL_IRQ_NUM(hwirq)            (hwirq)
#endif

#ifndef CONFIG_MMC_RTKEMMC_HK_ATTR
#define CONFIG_MMC_RTKEMMC_HK_ATTR
#endif

#ifdef CONFIG_MMC_RTKEMMC_SHOUTDOWN_PROTECT
#if defined(CONFIG_REALTEK_PCBMGR) && defined(CONFIG_REALTEK_GPIO)
#define EMMC_SHOUTDOWN_PROTECT
/* note: AC detect pin is iso_gpio_36 on 296x*/
#else
#define EMMC_SHOUTDOWN_PROTECT_FAIL
#endif
#endif

#ifdef CONFIG_MMC_RTKEMMC_DDR
#define EN_EMMC_DDR50
#endif

#ifdef CONFIG_RTKEMMC_HS200
#define EN_EMMC_HS200
#endif

#ifdef CONFIG_RTKEMMC_HS400
#define EN_EMMC_HS400
#endif

/* #define EN_SHOW_DATA */
#define cr_maskl(reg,msk,sht,val)  \
        cr_writel((cr_readl(reg) & ~(msk<<sht))|(val<<sht), reg)

#define USE_FIXED_W_PHASE

/* rtk_emmc_bus_wid control flag*/
#define EMMC_OPEN_LOG   _BIT0
#define EMMC_DIS_4BITS  _BIT1
#define EMMC_DIS_8BITS  _BIT2
#define EMMC_DIS_HS200  _BIT3
#define EMMC_DIS_HS400  _BIT4

#define EMMC_EN_PARAM   _BIT16
#define EMMC_DIS_SSCG   _BIT17
#define EMMC_EN_IO_DRV  _BIT18
#define EMMC_EN_MMC_DRV _BIT19
#define EMMC_FIX_DSTUNE _BIT20
#define EMMC_SKIP_TUNE  _BIT21
#define EMMC_ALWAYS_CLK _BIT22
#define EMMC_BURST_BLK  _BIT23

#define EMMC_RW_REG     _BIT24
#define EMMC_RESTORE    _BIT25
#define EMMC_RCV_FLOW   _BIT26

#define IDMAC_INT_CLR       (SDMMC_IDMAC_INT_AI | SDMMC_IDMAC_INT_NI | \
                 SDMMC_IDMAC_INT_CES | SDMMC_IDMAC_INT_DU | \
                 SDMMC_IDMAC_INT_FBE | SDMMC_IDMAC_INT_RI | \
                 SDMMC_IDMAC_INT_TI)

#define USE_INT_MODE (SDMMC_CMD_DAT_EXP|SDMMC_CMD_START)

//#define SKIP_ODD_POINT

/* default phase */
#define DEFAULT_R_PHASE     0x0c
#define DEFAULT_C_PHASE     0x1f
#define DEFAULT_W_PHASE     0x1f

#define DEFAULT_C_PHASE_200 0x1b
#define DEFAULT_W_PHASE_200 0x1b
#define DEFAULT_W_PHASE_400 0x0f
#define DEFAULT_DSTUNE      8

/************************************************************************
 *  Local veriable
 ************************************************************************/
static int maxfreq = RTKSD_CLOCKRATE_MAX;
static int nodma;
struct mmc_host *mmc_host_local;
static u32 rtk_emmc_bus_wid = 0;
static u32 rtk_emmc_test_ctl =0;
static u32 rtk_emmc_bus_clock = 0;
static u32 rtk_emmc_log_state = 0;
static unsigned long rtk_emmc_err_cnt = 0;
extern u32 rtk_emmc_raw_op;

static const char *const dw_clk_tlb[23] = {
    "200Khz",
    "10Mhz",
    "15Mhz",
    "20Mhz",
    "25Mhz",
    "30Mhz",
    "40Mhz",
    "50Mhz",
    "60Mhz",
    "70Mhz",
    "80Mhz",
    "90Mhz",
    "100Mhz",
    "110Mhz",
    "120Mhz",
    "130Mhz",
    "140Mhz",
    "150Mhz",
    "160Mhz",
    "170Mhz",
    "180Mhz",
    "190Mhz",
    "200Mhz"
};

#ifdef CONFIG_RTKEMMC_COWORK_WITH_KCPU
// for pm
#define KCPU_EMMC_DEVICE_SUSPEND_DONE   0xED00ED00
extern unsigned int mmc_pm_sync_addr;
#endif
/************************************************************************
 *  Local Function Protal Type
 ************************************************************************/
static void dw_em_request(struct mmc_host *host, struct mmc_request *mrq);
static int dw_em_get_ro(struct mmc_host *mmc);
static void dw_em_set_ios(struct mmc_host *host, struct mmc_ios *ios);
static int dw_em_execute_tuning(struct mmc_host *mmc, u32 opcode);
static int mmc_send_data_cmd(struct mmc_host * mmc, u32 hc_cmd,
                 u32 cmd_arg, u32 blk_cnt, unsigned char *buffer);

static void set_cmd_info(struct rtksd_host *sdport,struct mmc_command * cmd,
             struct sd_cmd_pkt *cmd_info, u32 opcode, u32 arg,
             u32 rsp_para);

static int dw_em_stop_transmission(struct rtksd_host *sdport);
static u32 dw_em_get_cmd_timeout(struct sd_cmd_pkt *cmd_info);

static void dw_em_set_scrip_base(dma_addr_t scrip_base);
static void show_ext_csd(u8 *ext_csd);
static int rtkem_h2d(u32 value);
static void dw_em_crt_reset(struct rtksd_host *sdport,u32 sync);
static void dw_em_hw_reset(struct mmc_host *host);
static void dw_em_reset_host_IP(struct rtksd_host *sdport,u8 save_en);
static void dw_em_reset_host(struct rtksd_host *sdport,u8 save_en);
static int dw_em_reset_IP(void);
static void dw_em_set_div(struct rtksd_host *sdport,u32 em_div);
static void dw_em_IP_config(struct rtksd_host *sdport);
static int rtkem_clr_sta(struct rtksd_host *sdport);
static int dw_em_dis_sd_tune(struct rtksd_host *sdport);
//static int dw_em_auto_sd_tune(struct rtksd_host *sdport);
int dw_em_prepare_hs400_tuning(struct mmc_host *host, struct mmc_ios *ios);
int dw_em_drive_strength (struct mmc_card *card,
        unsigned int max_dtr, int host_drv,
        int card_drv, int *drv_type);
static void dw_em_set_ds_delay(struct rtksd_host *sdport, int ds_delay);
static int dw_em_ds_tuning(struct mmc_host *host, u32 ctl);
#ifdef  EN_SHOW_DATA
static void show_data(u8 *buf, unsigned int len);
#endif

static
const struct mmc_host_ops rtkemmc_ops = {
    .request        = dw_em_request,
    .get_ro         = dw_em_get_ro,
    .set_ios        = dw_em_set_ios,
    .execute_tuning     = dw_em_execute_tuning,
    .hw_reset       = dw_em_hw_reset,
    .prepare_hs400_tuning   = dw_em_prepare_hs400_tuning,
    .select_drive_strength  = dw_em_drive_strength,
};

/************************************************************************
 *  external Function Protal Type
 ************************************************************************/
extern s32 export_raw_dw_em_read(u8 *buffer, u64 address, u32 size);
extern s32 export_raw_dw_em_write(u8 *buffer, u64 address, u32 size);
extern s32 export_raw_dw_em_init(void);
extern int export_raw_emmc_partition_change(u32 part_num);

/************************************************************************
 * Function Body
 ************************************************************************/
/* #define RECOVER_FLOW_TEST */
#ifdef RECOVER_FLOW_TEST
void dw_em_signal_restore(void){

    if(rtk_emmc_test_ctl & EMMC_RESTORE){
    EM_ALERT("%s(%d)\n",__func__,__LINE__);
    /*
     * For recover flow test, add any restore seting here.
     */

    /* resture DS_turn*/
    cr_writel(0x47, 0xb801088C);
}
}
#endif

#if 0
void show_reg_all(struct rtksd_host *sdport){
    int i;
    u32 reg_adr;


    for(i=0;i<12;i++){
        reg_adr = (0xb8000700+(i*4));
        EM_ERR("0x%08x=0x%08x\n",reg_adr,cr_readl(reg_adr));
    }

    for(i=0;i<4;i++){
        reg_adr = (EM_PLUS_BASE+(i*4));
        EM_ERR("0x%08x=0x%08x\n",reg_adr,cr_readl(reg_adr));
    }
    for(i=0;i<25;i++){
        reg_adr = (EM_WARP_CTRL+(i*4));
        EM_ERR("0x%08x=0x%08x\n",reg_adr,cr_readl(reg_adr));
    }

    for(i=0;i<51;i++){
        reg_adr = (DWC_IP_BASE+(i*4));
        //DWC_IP_BASE
        EM_ERR("0x%08x=0x%08x\n",reg_adr,cr_readl(reg_adr));
        if((i*4)==0xa4){

            for(i=0;i<5;i++){
                reg_adr=(DWC_IP_BASE+(i*4))+0x100;
                EM_ERR("0x%08x=0x%08x\n",reg_adr,cr_readl(reg_adr));
            }
            break;
        }
    }

}
#endif

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_get_occupy(struct rtksd_host *sdport)
{
    unsigned int relock = 0;
    unsigned int loop = 0;
    unsigned long flags;

#ifdef CONFIG_MMC_HW_SEMAPHORE
    /* get HW semaphore */
    while(!(cr_readl(EMMC_HW_SEMAPHORE))
     && loop < 1000)
    {
        loop++;
        EM_WARNING("wait EMMC_HW_SEMAPHORE\n");
        msleep(1);
    }
    if(loop >= 1000)
        return -1;
    loop = 0;
#endif

RE_LOCK:
    spin_lock_irqsave(&sdport->lock,flags);

    if(cr_readl(EM_SCPU_SEL) & PS_SCPU_SEL){
        relock = 1;
    }else{
        cr_writel( PS_SCPU_SEL, EM_SCPU_SEL );
    }

    spin_unlock_irqrestore(&sdport->lock, flags);
    if(relock){
        loop ++;
        relock = 0;
        msleep(1);
        if(loop > 5){
            u32 reg1,reg2;
            reg1 = cr_readl(RTK_EM_DW_SRST);
            reg2 = cr_readl(RTK_EM_DW_CLKEN);
            if(!(reg1 & BIT(23)) || !(reg2 & BIT(23))){
                EM_WARNING("%s(%d)RST/CLK disable[%d] DW_SRST=0x%08x DW_CLKEN=0x%08x  <<<<<<<<<\n",
                __func__,__LINE__,loop,
                cr_readl(RTK_EM_DW_SRST),
                cr_readl(RTK_EM_DW_CLKEN));

                cr_writel((RSTN_EM_DW | 0x01UL),RTK_EM_DW_SRST);
                cr_writel((CLKEN_EM_DW | 0x01U),RTK_EM_DW_CLKEN);
            }
        }
        if(loop > 100){
            /* check CRT reg status here */
            EM_WARNING("%s(%d)waitting[%d] <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n",
                __func__,__LINE__,loop);
            if(loop > 1000){
#ifdef CONFIG_MMC_HW_SEMAPHORE
                /* release HW semahpore */
                rtd_outl(EMMC_HW_SEMAPHORE,    0);
#endif
                return -1;
            }
        }
        goto RE_LOCK;
    }

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_release_occupy(struct rtksd_host *sdport){

    /* release scpu */
    unsigned long flags;
    int err = 0;

    if(rtk_emmc_raw_op) {
        cr_writel(0 , EM_SCPU_SEL );    /* release SCPU */
        return 0;
    }

    spin_lock_irqsave(&sdport->lock,flags);

    if(cr_readl(EM_SCPU_SEL) & PS_SCPU_SEL){
        cr_writel(0 , EM_SCPU_SEL );    /* release SCPU */
    }else{
        err = 1;
    }
    spin_unlock_irqrestore(&sdport->lock, flags);

#ifdef CONFIG_MMC_HW_SEMAPHORE
    /* release HW semahpore */
    rtd_outl(EMMC_HW_SEMAPHORE,    0);
#endif

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_read_rsp( u32 * rsp, u32 reg_count )
{
    /* #define SHOW_RESP */

    if ( reg_count == 16 ){
        rsp[3] = cr_readl(EM_DWC_RESP0);
        rsp[2] = cr_readl(EM_DWC_RESP1);
        rsp[1] = cr_readl(EM_DWC_RESP2);
        rsp[0] = cr_readl(EM_DWC_RESP3);
#ifdef SHOW_RESP
        EM_ERR("rsp[0]=0x%08x\n", rsp[0]);
        EM_ERR("rsp[1]=0x%08x\n", rsp[1]);
        EM_ERR("rsp[2]=0x%08x\n", rsp[2]);
        EM_ERR("rsp[3]=0x%08x\n", rsp[3]);
#endif
    } else {
        rsp[0] = cr_readl(EM_DWC_RESP0);
#ifdef SHOW_RESP
        EM_ERR("rsp[0]=0x%08x\n", rsp[0]);
#endif
        /*
        When CIU sends auto-stop command,
        Response for previous command sent by host is
        still preserved in Response 1 register.
        So, record rsp[1] always.
        */
        if(reg_count == 2 ){
            rsp[1] = cr_readl(EM_DWC_RESP1);
#ifdef SHOW_RESP
            EM_ERR("rsp[1]=0x%08x\n", rsp[1]);
#endif
        }
    }
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_chk_rsp(u32 * rsp, u32 cmd_flag, struct sd_cmd_pkt * cmd_info)
{
    int ret_err = 0;
    u32 cmd_idx = 0;

    cmd_idx = SDMMC_CMD_INDX(cmd_flag);

    if(cmd_flag & SDMMC_CMD_RESP_LONG){
        dw_em_read_rsp(rsp, 16);
        /* only resp == 6 is possible have card status */

    }else{
        if(cmd_flag & SDMMC_CMD_SEND_STOP)
            dw_em_read_rsp(rsp, 2);
        else
            dw_em_read_rsp(rsp, 6);

        if((cmd_flag & SDMMC_CMD_RESP_CRC)){
            if( (cmd_idx != MMC_GO_IRQ_STATE)){
                /*
                 Only R1/R1b should check Card_Status.
                 It can't diff R1/R1b/R5/R6/R7.
                 but only CMD40 have definded, so check it here.
                */
                if(rsp[0] & RESP_ERR_BIT){
                    ret_err = 1;
                }
                if((cmd_flag & SDMMC_CMD_SEND_STOP)
                    && (rsp[1] & RESP_ERR_BIT)) {
                    ret_err |= 1;
                }
            }
        }
    }
    if(ret_err){
        /* response will be check by high-level, print information just for debug. */
        mmcinfo("rsp error !!!\n");
        mmcinfo("rsp[0]=0x%08x\n", rsp[0]);
        if(cmd_flag & SDMMC_CMD_SEND_STOP){
            mmcinfo("rsp[1]=0x%08x\n", rsp[1]);
        }
    }

    return ret_err;
}

/************************************************************************
 *   0x0 :  50ohm x1
 *   0x1 :  33ohm x1.5
 *   0x2 :  66ohm x0.75
 *   0x3 : 100ohm x0.5
 *   0x4 :  40ohm x1.2
 ************************************************************************/
int dw_em_drive_strength (struct mmc_card *card,
        unsigned int max_dtr, int host_drv,
        int card_drv, int *drv_type)
{
    int drv_stg;

    /* according to Scott's advice, use 1.2(0x4) */
    if(max_dtr > 52000000){
        if(card->cid.manfid == 0x90){
            /* for hynix */
            drv_stg = 0x1;
        }else
            drv_stg = 0x4;
    }else
        drv_stg = 0;

    EM_INFO("set drive strength to %d\n",drv_stg);
    return drv_stg;
}

/************************************************************************
 *
 ************************************************************************/
int dw_em_prepare_hs400_tuning(struct mmc_host *host, struct mmc_ios *ios)
{
    struct rtksd_host *sdport;

    sdport = mmc_priv(host);
    sdport->cur_ds_tune = DEFAULT_DSTUNE;

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_init_phase(struct rtksd_host *sdport, u32 w_phase,u32 r_phase,u32 c_phase)
{
    /* default Phase Setting */

    /*
     eMMC PLL Phase:
          setting on romcode\src\arch\reset\drivers\crt\crt.c +239

      0xb8000708[ 5: 0]==> clk vs data write phase
      0xb8000708[15:10]==> clk vs data read phase
      0xb800070c[15:10]==> clk vs cmd  write phase
    */
    mmcmsg3("w_phase=%u r_phase=%u\n",w_phase,r_phase);

    if(w_phase != 0xff){
        sdport->cur_w_phase = w_phase;
        cr_maskl(EMMC_PLLPHASE_CTRL,0x03fUL, 0 ,w_phase);
    }

    if(r_phase != 0xff){
        sdport->cur_r_phase = r_phase;
        cr_maskl(EMMC_PLLPHASE_CTRL,0x03fUL,10 ,r_phase);
    }

    if(c_phase != 0xff){
        sdport->cur_c_phase = c_phase;
        cr_maskl(EMMC_PLL_PHASE_INTERPOLATION,0x03fUL,10 ,c_phase);
    }

    mmcmsg3("PHASE_REG(0x%08x)=0x%08x\n",
        EMMC_PLLPHASE_CTRL, cr_readl(EMMC_PLLPHASE_CTRL));

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_set_PLL_SSC(struct rtksd_host *sdport,
    u32 ncode ,u32 fcode ,u32 rang)
{
    int ret;
    unsigned int loop;

    ret = -1;

    EM_INFO("%s: Going to enable SSC!!!\n",DRIVER_NAME);
    cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,0);       /* PLLEMMC_OC_EN = 0 */

    cr_maskl(EMMC_PLL_SSC3,0x0FFUL,16,ncode);   /* Ncode_ssc = veriable */
    cr_maskl(EMMC_PLL_SSC3,0x7FFUL, 0,fcode);   /* Fcode_ssc = veriable */
    cr_maskl(EMMC_PLL_SSC5,0x7UL,24,4);     /* dot_gran=4 */
    cr_maskl(EMMC_PLL_SSC5,0x7ffffUL,4,rang);   /* Gran_est=49166(30k) */

    cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,1);       /* PLLEMMC_OC_EN = 1 */

    loop = 200000;
    while(loop--){  /* polling PLLEMMC_Oc_done flag */
        if(cr_readl(EMMC_PLL_SSC6) & _BIT4){
            break;
        }
    }

    cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,0);   /* PLLEMMC_OC_EN = 0 */
    if(loop){
        cr_maskl(EMMC_PLL_SSC5,0x001UL,0 ,1);   /* En_ssc =1 */
        ret = 0;
    }else{
        EM_ERR("SSC enable fail!!!\n");
    }

    return ret;
}

/************************************************************************
 *
typedef struct  {
    u32                 ctl;
    u8                  ncode_t;
    u8                  sdiv2;
    u8                  r_phase;
    u8                  w_phase;
    u8                  icp;
    u8                  pi_isel;    <== RTK2831/2841 skip this item
    u8                  cs;
    u8                  cp;
    u8                  rs;
    u16                 ncode_ssc;
    u16                 fcode_ssc;
    u32                 range_ssc;
}mmc_param_t;
 ************************************************************************/
mmc_param_t mmc_defaul_tparam[16]= {
/*  ctl/ncode_t/sdiv2/r_pha/w_pha/icp/pi_isel/cs/cp/rs/ncode/fcode/ range              */
    { 1,     40,    0,   13, 0xff,  5,      3, 3, 0, 4, 0x27,0X48F,0x2E5C }, /* 193.5Mhz */
    { 0,     39,    0,   20, 0xff,  5,      3, 3, 0, 4,    0,    0,     0 }, /* 189Mhz  */
    { 0,     37,    0,   51, 0xff,  5,      3, 3, 0, 4,    0,    0,     0 }, /* 180Mhz   */
    { 0,     35,    0,   48, 0xff,  5,      3, 3, 0, 4,    0,    0,     0 }, /* 171Mhz   */
    { 0,     33,    0,   45, 0xff,  3,      3, 3, 0, 5,    0,    0,     0 }, /* 162Mhz   */
    { 0,     30,    0,   43, 0xff,  3,      3, 3, 0, 5,    0,    0,     0 }, /* 148.5Mhz */
    { 0,     28,    0,   41, 0xff,  3,      3, 3, 0, 4,    0,    0,     0 }, /* 139.5Mhz */
    { 0,     26,    0,   37, 0xff,  3,      3, 3, 0, 4,    0,    0,     0 }, /* 130.5Mhz */
    { 0,     24,    0,   34, 0xff,  3,      3, 3, 0, 4,    0,    0,     0 }, /* 121.5Mhz */
    { 0,     21,    0,   35, 0xff,  3,      3, 3, 0, 3,    0,    0,     0 }, /* 108Mhz   */
    { 0,     41,    1,   37, 0xff,  6,      3, 3, 1, 4,    0,    0,     0 }, /* 99Mhz    */
    { 0,     37,    1,   37, 0xff,  6,      3, 3, 1, 3,    0,    0,     0 }, /* 90Mhz    */
    { 0,     33,    1,   37, 0xff,  5,      3, 3, 1, 3,    0,    0,     0 }, /* 81Mhz    */
    { 0,     29,    1,   37, 0xff,  3,      3, 3, 1, 4,    0,    0,     0 }, /* 72Mhz    */
    { 0,     23,    1,   37, 0xff,  3,      3, 3, 1, 4,    0,    0,     0 }, /* 58.5Mhz  */
    { 0,     19,    1,   12, 0xff,  3,      3, 3, 1, 3,    0,    0,     0 }  /* 49.5Mhz include under */
};

/************************************************************************
 *
 * PLL Clock Formula:
 *
 *   PLLEMMC_NCODE_T = 0x1800_0720[23:16]
 *   PLLSN           = 0x1800_0700[10:8] <==1(currently)
 *   Note : max PLLSN is 4
 *   PLLSDIV2        = 0x1800_0700[17]   <==0(currently)
 *   Fout = 27 *( PLLEMMC_NCODE_T +3)/ (PLLSN+2)/( PLLSDIV2+1)/2
 *        = 27 *( PLLEMMC_NCODE_T +3)/ 6
 *   PLLEMMC_NCODE_T = (((6 * Fout )/27)-3)
 *
 * if PLLSN is 4
 *   PLLEMMC_NCODE_T = (((12 * Fout )/27)-3)
 *
 *                      PLLSN=  [1]    [4]
 * 200Mhz : 0x1800_0720[23:16] = 41     85
 * 190Mhz : 0x1800_0720[23:16] = 39 81
 * 180Mhz : 0x1800_0720[23:16] = 37 77
 * 170Mhz : 0x1800_0720[23:16] = 35 72
 * 160Mhz : 0x1800_0720[23:16] = 32 68
 * 150Mhz : 0x1800_0720[23:16] = 30 63
 * 140Mhz : 0x1800_0720[23:16] = 28 59
 * 130Mhz : 0x1800_0720[23:16] = 26 54
 * 120Mhz : 0x1800_0720[23:16] = 24 50
 * 110Mhz : 0x1800_0720[23:16] = 21 45
 * 100Mhz : 0x1800_0720[23:16] = 19 41
 *  90Mhz : 0x1800_0720[23:16] = 17 37
 *  80Mhz : 0x1800_0720[23:16] = 15 32
 *  70Mhz : 0x1800_0720[23:16] = 12 28
 *  60Mhz : 0x1800_0720[23:16] = 10 23
 *  50Mhz : 0x1800_0720[23:16] =  8 19
 *
 * ICP setting :
 * under 50Mhz =>                 => ICP=? => 0x18000700[16:12]=0x00
 * 50,60,70Mhz => VCO=100,120,140 => ICP=5 => 0x18000700[16:12]=0x01
 * 80,90,100,110, 120,130,140Mhz
 *             => VCO=160,180,200,220,240,260,280
 *                                => ICP=10 => 0x18000700[16:12]=0x03
 * 150,160,170,180,190,200Mhz
 *             => VCO=300,320,340,360,380,400
 *                                => ICP=20 => 0x18000700[16:12]=0x07
 *
 ************************************************************************/
static
int dw_em_set_PLL_clk(struct rtksd_host *sdport, u32 targ_clk,u32 clk_div,u32 init)
{
    //unsigned long flags;
    int err = 0;
    unsigned int pllemmc_ncode_t = 0;
    unsigned int loop = 20000;
    unsigned int icp = 0;
    unsigned int sdiv2 = 0;
    unsigned int sdiv2_old = 0;
    unsigned int r_phase = 0;
    unsigned int pll_sta = 0;
    unsigned int ncode_ssc = 0;
    unsigned int fcode_ssc = 0;
    unsigned int ssc_rang = 0;
    unsigned int cs,cp,rs;
    unsigned char idx;
    u32 config1;
    u32 config2;
    u32 config3;
    u32 config4;
    u32 config5;
    u32 config6;
    u32 config7;
    mmc_param_t *tmp_param_ptr;

#define SSC_EN _BIT0

    if (sdport->cur_PLL == targ_clk) {
        dw_em_set_div(sdport,clk_div);
        mmcmsg3(" skip\n");
        return 0;
    }

    if (targ_clk >= CLK_200Mhz){
        idx = 0;
    }else if (targ_clk >= CLK_190Mhz){
        idx = 1;
    }else if (targ_clk >= CLK_180Mhz){
        idx = 2;
    }else if (targ_clk >= CLK_170Mhz){
        idx = 3;
    }else if (targ_clk >= CLK_160Mhz){
        idx = 4;
    }else if (targ_clk >= CLK_150Mhz){
        idx = 5;
    }else if (targ_clk >= CLK_140Mhz){
        idx = 6;
    }else if (targ_clk >= CLK_130Mhz){
        idx = 7;
    }else if (targ_clk >= CLK_120Mhz){
        idx = 8;
    }else if (targ_clk >= CLK_110Mhz){
        idx = 9;
    }else if (targ_clk >= CLK_100Mhz){
        idx = 10;
    }else if (targ_clk >= CLK_90Mhz){
        idx = 11;
    }else if (targ_clk >= CLK_80Mhz){
        idx = 12;
    }else if (targ_clk >= CLK_70Mhz){
        idx = 13;
    }else if (targ_clk >= CLK_60Mhz){
        idx = 14;
    }else {
        idx = 15;
    }

    if(rtk_emmc_test_ctl & EMMC_EN_PARAM){
        EM_ALERT("%s(%d)Use Bootcode pre-setting parameter\n",__func__,__LINE__);
        tmp_param_ptr = sdport->mmc_boot_param;
    }else {
        tmp_param_ptr = mmc_defaul_tparam;
    }

    pllemmc_ncode_t = tmp_param_ptr[idx].ncode_t;
    sdiv2           = tmp_param_ptr[idx].sdiv2;
    r_phase         = tmp_param_ptr[idx].r_phase;
    icp             = tmp_param_ptr[idx].icp;
    cs              = tmp_param_ptr[idx].cs;
    cp              = tmp_param_ptr[idx].cp;
    rs              = tmp_param_ptr[idx].rs;

    ncode_ssc = tmp_param_ptr[idx].ncode_ssc;
    fcode_ssc = tmp_param_ptr[idx].fcode_ssc;
    ssc_rang  = tmp_param_ptr[idx].range_ssc;

    /* disable SSCG func by pre-setting of bootcode */
    if(rtk_emmc_test_ctl & EMMC_DIS_SSCG){
        pll_sta &= ~SSC_EN;
    }else{
        if(tmp_param_ptr[idx].ctl & MMC_EN_SSCG)
            pll_sta |= SSC_EN;
    }

    if(rtk_emmc_test_ctl & EMMC_EN_PARAM){
        EM_ALERT("%s(%d)idx%d==================================\n",__func__,__LINE__,idx);
        EM_ALERT("    pllemmc_ncode_t=%u(0x%x)\n",pllemmc_ncode_t,pllemmc_ncode_t);
        EM_ALERT("    r_phase=%u(0x%x)\n",r_phase,r_phase);
        EM_ALERT("    icp=%u(0x%x)\n",icp,icp);

        if(pll_sta & SSC_EN){
            EM_ALERT("SSCG enable !!!\n");
            EM_ALERT("    ncode_ssc=%u(0x%x)\n",ncode_ssc,ncode_ssc);
            EM_ALERT("    fcode_ssc=%u(0x%x)\n",fcode_ssc,fcode_ssc);
            EM_ALERT("    ssc_rang=%u(0x%x)\n",ssc_rang,ssc_rang);
        }
    }

    if(!init){
        /* backup IP status first */
        config1 = cr_readl(EM_DWC_PWREN);
        config2 = cr_readl(EM_DWC_CLKDIV);
        config3 = cr_readl(EM_DWC_CTYPE);
        config4 = cr_readl(EM_DWC_UHS_REG);
        config5 = cr_readl(EM_DWC_DBADDR);
        config6 = cr_readl(EM_DWC_EMMC_DDR_REG);
        config7 = cr_readl(EM_HALF_CYCLE_CAL_EN);
        dw_em_dis_sd_tune(sdport);
    }

    /* reset IP  */
    dw_em_reset_IP();
    udelay(10);

    /* gating digital clock */
    cr_writel(CLKEN_EM_DW,RTK_EM_DW_CLKEN);

    //spin_lock_irqsave(&sdport->lock, flags);

    if(clk_div){
        /*
         * if clk_div is true, meaning bus clock lower or equal 50Mhz,
         * use default phase
         */
        r_phase = DEFAULT_R_PHASE;
    }else{
        /* If clock get from PLL directly ,use new phase setting clock. */
        if(targ_clk == sdport->tud_r_clock){
            r_phase = sdport->tud_r_phase;
        }
    }

    /* w_phase[15:10];r_phase [5:0];c_phase [25:20]; */
    dw_em_init_phase(sdport,0xff,r_phase,0xff);

    if(init){
        cr_maskl(EMMC_PLL_SET,0x001UL,0 ,0);    /* PLLALLRSTB = 0 */
        cr_maskl(EMMC_PLL_SET,0x001UL,30 ,0);   /* PLL_EMMC_CKSSC_INV = 0 */
        cr_maskl(EMMC_PLL_SSC0,0x2FFUL,4 ,1);   /* PLLEMMC_OC_STEP_SET = 1 */
        cr_maskl(EMMC_PLL_CTRL,0x001UL,24 ,1);  /* PLLEMMC_FREEZE */
        cr_maskl(EMMC_PLL_CTRL,0x003UL,0 ,2);   /* , LDO power on, PLLEMMC power on, */

        cr_maskl(EMMC_PLL_SSC4,0x0FFUL,16,pllemmc_ncode_t); /* To setting PLLEMMC_NCODE_T */
        cr_maskl(EMMC_PLL_SSC5,0x001UL,0 ,0);   /* En_ssc =0; disable SSC */

        udelay(5);

        cr_maskl(EMMC_PLL_SET,0x007UL,8 ,1);    /* PLLSN = 1, */
        cr_maskl(EMMC_PLL_SET,0x001UL,29,cp);    /* CP */
        cr_maskl(EMMC_PLL_SET,0x003UL,27,cs);    /* CS */
        cr_maskl(EMMC_PLL_SET,0x007UL,24,rs);    /* RS */
        cr_maskl(EMMC_PLL_SET,0x01fUL,12,icp);  /* PLL Charger Pump Current IchDpll[16:12] */
        cr_maskl(EMMC_PLL_SET,0x001UL,17,sdiv2);    /* PLLSDIV2 = 0, 27x(19+3)/3/2=99MHz */
        udelay(5);

        cr_maskl(EMMC_PLL_SET,0x001UL,0 ,1);    /* PLLALLRSTB = 1 */
        cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,1);   /* PLLEMMC_OC_EN = 1 */
    }else{
        sdiv2_old = (cr_readl(EMMC_PLL_SET)>>17) & 0x1UL;
        cr_maskl(EMMC_PLL_CTRL,0x001UL,24 ,1);  /* PLLEMMC_FREEZE */
        cr_maskl(EMMC_PLL_SSC5,0x001UL,0 ,0);   /* En_ssc =0; disable SSC */
        cr_maskl(EMMC_PLL_SSC0,0x2FFUL,4 ,0x200);   /* PLLEMMC_OC_STEP_SET = 0x200 */
        cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,0);   /* PLLEMMC_OC_EN = 0 */
        cr_maskl(EMMC_PLL_SET,0x007UL,8 ,1);    /* PLLSN = 1, */
        cr_maskl(EMMC_PLL_SET,0x001UL,29,cp);    /* CP */
        cr_maskl(EMMC_PLL_SET,0x003UL,27,cs);    /* CS */
        cr_maskl(EMMC_PLL_SET,0x007UL,24,rs);    /* RS */
        cr_maskl(EMMC_PLL_SET,0x01fUL,12,icp);  /* PLL Charger Pump Current IchDpll[16:12] */
        if (sdiv2 > sdiv2_old) {
            /* high --> low */
            cr_maskl(EMMC_PLL_SET,0x001UL,17,sdiv2);    /* PLLSDIV2 = 0, 27x(19+3)/3/2=99MHz */
            cr_maskl(EMMC_PLL_SSC4,0x0FFUL,16,pllemmc_ncode_t); /* To setting PLLEMMC_NCODE_T */
        }else{
            /* low --> high */
            cr_maskl(EMMC_PLL_SSC4,0x0FFUL,16,pllemmc_ncode_t); /* To setting PLLEMMC_NCODE_T */
            cr_maskl(EMMC_PLL_SET,0x001UL,17,sdiv2);    /* PLLSDIV2 = 0, 27x(19+3)/3/2=99MHz */
        }
        cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,1);   /* PLLEMMC_OC_EN = 1 */
    }

    //spin_unlock_irqrestore(&sdport->lock, flags);

    while(--loop){  /* polling PLLEMMC_Oc_done flag */
        if(cr_readl(EMMC_PLL_SSC6) & _BIT4){
            break;
        }
        /* max waiting for 100ms = 20000*5us */
        udelay(5);
    }

    cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,0);   /* PLLEMMC_OC_EN = 0 */
    udelay(150);
    cr_maskl(EMMC_PLL_CTRL,0x001UL,24 ,0);  /* release PLLEMMC_FREEZE */

    if(!loop){
        err = -1;
        goto OUT;
    }

    /* To enable SSC, just care about PLL clock, no matter divider or else. */
    if(pll_sta & SSC_EN){
        dw_em_set_PLL_SSC(sdport, ncode_ssc, fcode_ssc ,ssc_rang);
    }

    sdport->cur_PLL = targ_clk;

OUT:
    /* crt sync reset */
    dw_em_crt_reset(sdport,1);

    /* reset IP  */
    dw_em_reset_IP();
    udelay(10);

    /*config IP */
    dw_em_IP_config(sdport);

    if(!init){
        /* restore previously IP setting */
        dw_em_set_div(sdport,clk_div);
        cr_writel(config3,EM_DWC_CTYPE);
        cr_writel(config4,EM_DWC_UHS_REG);
        cr_writel(config5,EM_DWC_DBADDR);
        cr_writel(config6,EM_DWC_EMMC_DDR_REG);
        if(config7 & _BIT0){
            dw_em_set_ds_delay(sdport, sdport->cur_ds_tune);
        }
    }

    return err;

}

/************************************************************************
 *
 ************************************************************************/
#define SDMMC_CMD_VOLT_SWITCH   BIT(28)
static
void dw_em_wait_while_busy(struct rtksd_host *sdport, u32 cmd_flags)
{
    unsigned long timeout = jiffies + msecs_to_jiffies(500);

    /*
     * Databook says that before issuing a new data transfer command
     * we need to check to see if the card is busy.  Data transfer commands
     * all have SDMMC_CMD_PRV_DAT_WAIT set, so we'll key off that.
     *
     * ...also allow sending for SDMMC_CMD_VOLT_SWITCH where busy is
     * expected.
     */
    if ((cmd_flags & SDMMC_CMD_PRV_DAT_WAIT) &&
        !(cmd_flags & SDMMC_CMD_VOLT_SWITCH)) {
        while (cr_readl(EM_DWC_STATUS) & SDMMC_DAT0_BUSY) {
            if (time_after(jiffies, timeout)) {
                /* Command will fail; we'll pass error then */
                EM_ALERT("Busy; trying anyway\n");
                break;
            }
            udelay(10);
        }
    }
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_send_cmd(struct rtksd_host *sdport, u32 cmd, u32 sd_arg)
{
    unsigned long timeout = jiffies + msecs_to_jiffies(500);
    unsigned int cmd_status = 0;

    cr_writel(sd_arg, EM_DWC_CMDARG);
    wmb();
    dw_em_wait_while_busy(sdport, cmd);
    cr_writel(SDMMC_CMD_START | cmd, EM_DWC_CMD);

    while (time_before(jiffies, timeout)) {
        cmd_status = cr_readl(EM_DWC_CMD);
        if (!(cmd_status & SDMMC_CMD_START))
            return;
    }

    EM_ERR("Timeout sending command (cmd %#x arg %#x status %#x)\n",
           cmd, sd_arg, cmd_status);
}

/************************************************************************
 *  Notice: em_div must be even value.
 ************************************************************************/
static
void dw_em_set_div(struct rtksd_host *sdport,u32 em_div)
{
    u32 row_div;

    if(em_div)
        row_div = (em_div>>1);
    else
        row_div = 0;

    /* reset div every time change clock */

    /* disable clock */
    cr_writel(0, EM_DWC_CLKENA);
    cr_writel(0, EM_DWC_CLKSRC);

    /* inform CIU */
    dw_em_send_cmd(sdport, SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);

    /* set clock to desired speed */
    cr_writel(row_div, EM_DWC_CLKDIV);

    /* inform CIU */
    dw_em_send_cmd(sdport, SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);

    /* enable clock */
    if(rtk_emmc_test_ctl & EMMC_ALWAYS_CLK){
        EM_ALERT("%s(%d)Use Bootcode pre-setting parameter. clock always on.\n",
            __func__,__LINE__);
        cr_writel(_BIT0, EM_DWC_CLKENA);
    }else{
        /* only low power if no SDIO */
        cr_writel((_BIT16 | _BIT0), EM_DWC_CLKENA);
    }
    /* inform CIU */
    dw_em_send_cmd(sdport, SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);

    sdport->cur_div = em_div;

    mmcmsg2("CLK divide %u\n",(row_div<<1));
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_set_clk(struct rtksd_host *sdport,u32 em_clock)
{
    u32 base_clk = 0;
    u32 clk_div = 0;
    u32 seted_clk = 0;
    u32 idx = 0;
    u32 quirk_num = 0;

    quirk_num = sdport->mid;

    if(em_clock > CLK_200Mhz){
        EM_NOTICE("emmc: unknow clock target %u, force to 25Mhz\n",
               em_clock);
        em_clock = CLK_25Mhz;
    }

    if(em_clock <=CLK_400Khz ){
        /* select 200KHz */
        idx = 0;
        seted_clk = CLK_200Khz;
        base_clk = CLK_50Mhz;
        clk_div = 250;
    }else if(em_clock < CLK_15Mhz){
        /* 10Mhz */
        idx = 1;
        seted_clk = CLK_10Mhz;
        base_clk = CLK_60Mhz;
        clk_div = 6;
    }else if(em_clock < CLK_20Mhz){
        /* 15Mhz */
        idx = 2;
        seted_clk = CLK_15Mhz;
        base_clk = CLK_60Mhz;
        clk_div = 4;
    }else if(em_clock < CLK_25Mhz){
        /* 20Mhz */
        idx = 3;
        seted_clk = CLK_20Mhz;
        base_clk = CLK_80Mhz;
        clk_div = 4;
    } else if (em_clock < CLK_30Mhz) {
        /* 25Mhz */
        idx = 4;
        seted_clk = CLK_25Mhz;
        base_clk = CLK_50Mhz;
        clk_div = 2;
    } else if (em_clock < CLK_40Mhz) {
        /* 30Mhz */
        idx = 5;
        seted_clk = CLK_30Mhz;
        base_clk = CLK_60Mhz;
        clk_div = 2;
    } else if (em_clock < CLK_50Mhz) {
        /* 40Mhz */
        idx = 6;
        seted_clk = CLK_40Mhz;
        base_clk = CLK_80Mhz;
        clk_div = 2;
    } else if (em_clock < CLK_60Mhz) {
        /* 50Mhz */
        idx = 7;
        seted_clk = CLK_50Mhz;
        base_clk = CLK_50Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_70Mhz) {
        /* 60Mhz */
        idx = 8;
        seted_clk = CLK_60Mhz;
        base_clk = CLK_60Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_80Mhz) {
        /* 70Mhz */
        idx = 9;
        seted_clk = CLK_70Mhz;
        base_clk = CLK_70Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_90Mhz) {
        /* 80Mhz */
        idx = 10;
        seted_clk = CLK_80Mhz;
        base_clk = CLK_80Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_100Mhz) {
        /* 90Mhz */
        idx = 11;
        seted_clk = CLK_90Mhz;
        base_clk = CLK_90Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_110Mhz) {
        /* 100Mhz */
        idx = 12;
        seted_clk = CLK_100Mhz;
        base_clk  = CLK_100Mhz;
        clk_div   = 0;
    } else if (em_clock < CLK_120Mhz) {
        /* 110Mhz */
        idx = 13;
        seted_clk = CLK_110Mhz;
        base_clk = CLK_110Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_130Mhz) {
        /* 120Mhz */
        idx = 14;
        seted_clk = CLK_120Mhz;
        base_clk  = CLK_120Mhz;
        clk_div   = 0;
    } else if (em_clock < CLK_140Mhz) {
        /* 130Mhz */
        idx = 15;
        seted_clk = CLK_130Mhz;
        base_clk = CLK_130Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_150Mhz) {
        /* 140Mhz */
        idx = 16;
        seted_clk = CLK_140Mhz;
        base_clk  = CLK_140Mhz;
        clk_div   = 0;
    } else if (em_clock < CLK_160Mhz) {
        /* 150Mhz */
        idx = 17;
        seted_clk = CLK_150Mhz;
        base_clk = CLK_150Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_170Mhz) {
        /* 160Mhz */
        idx = 18;
        seted_clk = CLK_160Mhz;
        base_clk  = CLK_160Mhz;
        clk_div   = 0;
    } else if (em_clock < CLK_180Mhz) {
        /* 170Mhz */
        idx = 19;
        seted_clk = CLK_170Mhz;
        base_clk = CLK_170Mhz;
        clk_div = 0;
    } else if (em_clock < CLK_190Mhz) {
        /* 180Mhz */
        idx = 20;
        seted_clk = CLK_180Mhz;
        base_clk  = CLK_180Mhz;
        clk_div   = 0;
    } else if (em_clock < CLK_200Mhz) {
        /* 190Mhz */
        idx = 21;
        seted_clk = CLK_190Mhz;
        base_clk = CLK_190Mhz;
        clk_div = 0;
    }else{
        /*
        mid 0x11 ==> Toshiba
        mid 0x13 ==> Micron
        mid 0x15 ==> Samsung
        mid 0x90 ==> Hynix
         */
        idx = 22;
        seted_clk = CLK_200Mhz;
        base_clk  = CLK_200Mhz;
        clk_div   = 0;
        EM_NOTICE("%s: MID(0x%x) eMMC detected\n",
            DRIVER_NAME,quirk_num);
    }

    if(sdport->cur_clock == seted_clk){

        /* do nothing */
    }else{
        dw_em_set_PLL_clk(sdport,base_clk,clk_div,0);
        sdport->cur_clock = seted_clk;
        EM_NOTICE("%s: clk change to %s(%u) [0x%x=0x%08x]\n",
            DRIVER_NAME, dw_clk_tlb[idx], idx,
            EMMC_PLLPHASE_CTRL,cr_readl(EMMC_PLLPHASE_CTRL));
    }

}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_clear_int_sta(u32 hold_int)
{
    if(hold_int)
        cr_writel(0x0, EM_DWC_INTMASK); /* disable int. */

    cr_writel(0xffffffff, EM_DWC_RINTSTS);  /* Clear all int result. */
}

/************************************************************************
 *
 ************************************************************************/
#if 0
static
void dw_em_enable_int_sta(unsigned int_event)
{
    cr_writel(int_event, EM_DWC_INTMASK);

    /* enable global int. */
    cr_writel(cr_readl(EM_DWC_CTRL) | SDMMC_CTRL_INT_ENABLE, EM_DWC_CTRL);
}
#endif

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_clear_int_sta_IDMA(u32 hold_int)
{
    if(hold_int)
        cr_writel(0x0, EM_DWC_IDINTEN);
    /* Clear all int result. */
    cr_writel(0xffffffff, EM_DWC_IDSTS);
}

/************************************************************************
 *
 ************************************************************************/
#if 0
static
void dw_em_enable_int_sta_IDMA(unsigned int_event)
{

    cr_writel(int_event, EM_DWC_IDINTEN);

    /* enable global int. */
    cr_writel(cr_readl(EM_DWC_CTRL) | SDMMC_CTRL_INT_ENABLE, EM_DWC_CTRL);
}
#endif

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_clear_int_wrap(unsigned int hold_int)
{
    if(hold_int)
        cr_writel(0x07, EM_INT_MASK);

    cr_writel(0x07,EM_INT_STATUS);
}

/************************************************************************
 *
 ************************************************************************/
#if 0
static
void dw_em_enable_int_wrap(unsigned int_event)
{
    /* Note : It's not like normal.
     * Zero enable here.
     * To reference spec if doubt.
     */
    cr_writel(~(int_event), EM_INT_MASK);
}
#endif

/************************************************************************
 * IP configure
 ************************************************************************/
static
void dw_em_IP_config(struct rtksd_host *sdport)
{
    u32 reginfo = 0;

    cr_writel(_BIT0, EM_DWC_PWREN); /* enable power of device 0. */

    /* int mask setting */
    cr_writel(reginfo, EM_DWC_INTMASK);
    cr_writel(0xffffffff, EM_DWC_RINTSTS);  /* Clear all int result. */

    /* disable IDMAC int */
    cr_writel(0, EM_DWC_IDINTEN);

    cr_writel(0xffffff40, EM_DWC_TMOUT);    /* set timeout of data and response as default. */

    cr_writel( (0x05UL<<SDMMC_MSIZE_SHT)        /* set DW_DMA_Multiple_Transaction_Size as 64(0x05) */
              |(0x3fUL<<SDMMC_RX_WMARK_SHT)     /* RX_WMARK=0x3f */
              |(0x40UL<<SDMMC_TX_WMARK_SHT) ,   /* TX_WMARK=0x40 */
                EM_DWC_FIFOTH );

    /* enable write/read threshold as 512 bytes */
    cr_writel((0x0200 << 16) | _BIT2 | _BIT0, EM_DWC_CardThrCtl);

    cr_writel( reginfo,EM_DWC_CTRL );
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_set_scrip_base(dma_addr_t scrip_base)
{
    /* set Descriptor List Base Address Register */
    cr_writel( scrip_base,EM_DWC_DBADDR );
}

/************************************************************************
 * depend on
 * JESD84-B51-1.pdf chapter 6.15.9 H/W Reset Operation
 * tRSTW : RST_n pulse width; min 1[us]
 ************************************************************************/
static
void dw_em_reset_card(struct rtksd_host *sdport)
{

    /* card reset should be implement here. This reg is GPIO control only.  */
    cr_writel(~_BIT0,EM_DWC_RST_n);
    udelay(10);
    cr_writel(_BIT0,EM_DWC_RST_n);

    /* Toggle 74 clock here :
     *  The toggle clock will be send out before cmd0 by DW IP.
     *  To reference u32 dw_em_prepare_command()
     *  cmd0 set SDMMC_CMD_INIT bit.
     */
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_reset_IP(void)
{
    int ret;
    u32 loop;

    /*
    * To reset controller/FIFO/DMA.
    * This reset is not to effect warper of RTK.
    */
    cr_writel(cr_readl(EM_DWC_CTRL)|(0x07), EM_DWC_CTRL);

    ret = -1;
    loop = 1000;
    while(loop--){
        if((cr_readl(EM_DWC_CTRL)&(0x07)) == 0){
            ret = 0;
            break;
        }
        udelay(1);
    }

    if(ret){
        EM_WARNING("%s: IP reset fail!!!\n",DRIVER_NAME);
    }
    return ret;
}

/************************************************************************

 ************************************************************************/
static
void dw_em_reset_host_IP(struct rtksd_host *sdport,u8 save_en)
{
    unsigned long flags;
    u32 config1;
    u32 config2;
    u32 config3;
    u32 config4;
    u32 config5;
    u32 config6;
    mmcmsg3("\n");

    spin_lock_irqsave(&sdport->lock,flags);
    mmcmsg3("\n");
    if(save_en){
        /* store currently IP setting */
        config1 = cr_readl(EM_DWC_PWREN);
        config2 = cr_readl(EM_DWC_CLKDIV);
        config3 = cr_readl(EM_DWC_CTYPE);
        config4 = cr_readl(EM_DWC_UHS_REG);
        config5 = cr_readl(EM_DWC_DBADDR);
        config6 = cr_readl(EM_DWC_EMMC_DDR_REG);
    }

    /* reset synopsys eMMC IP */
    spin_unlock_irqrestore(&sdport->lock, flags);
    if(dw_em_reset_IP()){
        /* reset all eMMC module. */
        EM_ERR("%s: IP reset fail, reset Host all!!!\n",DRIVER_NAME);
        dw_em_crt_reset(sdport,0);
    }
    spin_lock_irqsave(&sdport->lock,flags);

    udelay(10);

    dw_em_IP_config(sdport);

    if(save_en){
        /* restore previously IP setting */
        cr_writel(config1,EM_DWC_PWREN);
        spin_unlock_irqrestore(&sdport->lock, flags);
        dw_em_set_div(sdport,(config2<<1));
        spin_lock_irqsave(&sdport->lock,flags);
        cr_writel(config3,EM_DWC_CTYPE);
        cr_writel(config4,EM_DWC_UHS_REG);
        cr_writel(config5,EM_DWC_DBADDR);
        cr_writel(config6,EM_DWC_EMMC_DDR_REG);
    }

    sdport->rtflags |= RTKCR_FHOST_POWER;
    sdport->reset_event = 0;

    spin_unlock_irqrestore(&sdport->lock, flags);
    mmcmsg3("\n");
}

/************************************************************************
 eMMC Pad driving/duty cycle:
    Pad driving set to 0.75,duty cycle shift 0ns

    rtd_part_outl(0xb80008a0,31,26,0x12);   //rst driving strength
    rtd_part_outl(0xb80008a0,25,23,0x0);    //rst duty cycle
    rtd_part_outl(0xb80008a0,22 ,17,0x12);  //clk driving strength
    rtd_part_outl(0xb80008a0,16,14,0x0);    //clk duty cycle
    rtd_part_outl(0xb80008a0,13,8,0x12);    //cmd driving strength
    rtd_part_outl(0xb80008a0,7,5,0x0);  //cmd duty cycle

    rtd_part_outl(0xb80008a4,31,26,0x12);   //dummy driving strength
    rtd_part_outl(0xb80008a4,25,23,0x0);    //dummy duty cycle
    rtd_part_outl(0xb80008a4,22 ,17,0x12);  //ds driving strength
    rtd_part_outl(0xb80008a4,16,14,0x0);    //ds duty cycle
    rtd_part_outl(0xb80008a4,13,8,0x12);    //d5 driving strength
    rtd_part_outl(0xb80008a4,7,5,0x0);  //d5 duty cycle

    rtd_part_outl(0xb80008a8,31,26,0x12);   //d3 driving strength
    rtd_part_outl(0xb80008a8,25,23,0x0);    //d3 duty cycle
    rtd_part_outl(0xb80008a8,22 ,17,0x12);  //d4 driving strength
    rtd_part_outl(0xb80008a8,16,14,0x0);    //d4 duty cycle
    rtd_part_outl(0xb80008a8,13,8,0x12);    //d0 driving strength
    rtd_part_outl(0xb80008a8,7,5,0x0);  //d0 duty cycle

    rtd_part_outl(0xb80008ac,31,26,0x12);   //d1 driving strength
    rtd_part_outl(0xb80008ac,25,23,0x0);    //d1 duty cycle
    rtd_part_outl(0xb80008ac,22 ,17,0x12);  //d2 driving strength
    rtd_part_outl(0xb80008ac,16,14,0x0);    //d2 duty cycle
    rtd_part_outl(0xb80008ac,13,8,0x12);    //d7 driving strength
    rtd_part_outl(0xb80008ac,7,5,0x0);  //d7 duty cycle

    rtd_part_outl(0xb80008b0,31,26,0x12);   //d6 driving strength
    rtd_part_outl(0xb80008b0,25,23,0x0);    //d6 duty cycle

 ************************************************************************/
/*
 Pad driving strength 0x1b = X1.25;
 with device driving:HS200/HS400 : 0x4(x1.2)
 */
#define IO_PAD_8A0_HS400 ((0x1BUL<<26)|(0x1BUL<<17)|(0x1BUL<<8))
#define IO_PAD_8A4_HS400 ((0x1BUL<<26)|(0x1BUL<<17)|(0x1BUL<<8))
#define IO_PAD_8A8_HS400 ((0x1BUL<<26)|(0x1BUL<<17)|(0x1BUL<<8))
#define IO_PAD_8AC_HS400 ((0x1BUL<<26)|(0x1BUL<<17)|(0x1BUL<<8))
#define IO_PAD_8B0_HS400 ((0x1BUL<<26))

#define IO_PAD_8A0_HS200 IO_PAD_8A0_HS400
#define IO_PAD_8A4_HS200 IO_PAD_8A4_HS400
#define IO_PAD_8A8_HS200 IO_PAD_8A8_HS400
#define IO_PAD_8AC_HS200 IO_PAD_8AC_HS400
#define IO_PAD_8B0_HS200 IO_PAD_8B0_HS400

/*
 Pad driving strength 0x0 = X0.5;
 with device driving:HS50 : 0x0(x1)
 */
#define IO_PAD_8A0_HS50 ((0x0UL<<26)|(0x0UL<<17)|(0x0UL<<8))
#define IO_PAD_8A4_HS50 ((0x0UL<<26)|(0x0UL<<17)|(0x0UL<<8))
#define IO_PAD_8A8_HS50 ((0x0UL<<26)|(0x0UL<<17)|(0x0UL<<8))
#define IO_PAD_8AC_HS50 ((0x0UL<<26)|(0x0UL<<17)|(0x0UL<<8))
#define IO_PAD_8B0_HS50 ((0x0UL<<26))

void dw_em_set_IO_driving(struct rtksd_host *sdport, unsigned int type_sel)
{
    //u32 mid = sdport->mid;
    u32 io_pad_setting1;
    u32 io_pad_setting2;
    u32 io_pad_setting3;
    u32 io_pad_setting4;
    u32 io_pad_setting5;
    u32 w_phase;
    u32 c_phase;

    /*
     Pad config:
     set emmc pull up/pull down/slew rate/smt trigger
    */
    cr_writel(0x11100000,0xb8000870);   //rst,clk,cmd,
    cr_writel(0x11111111,0xb8000878);   //dummy,ds,d5,d3,d4,d0,d1,d2,
    cr_writel(0x11000000,0xb800087c);   //d7,d6

    if(type_sel == DRIVING_HS400){
        w_phase = DEFAULT_W_PHASE_400;
        c_phase = DEFAULT_C_PHASE_200;
        while(rtk_emmc_test_ctl & EMMC_EN_IO_DRV){
            u32 *io_drv_ptr;

            EM_ALERT("%s(%d)Use Bootcode pre-setting parameter\n",__func__,__LINE__);

            if(sdport->mmc_io_drv == NULL){
                EM_ALERT("%s(%d)sdport->mmc_io_drv = NULL, use default setting\n",__func__,__LINE__);
                break;
            }

            io_drv_ptr = sdport->mmc_io_drv;

            cr_writel( io_drv_ptr[0], 0xb8000874);
            cr_writel( io_drv_ptr[1], 0xb8000880);
            cr_writel( io_drv_ptr[2], 0xb8000884);
            cr_writel( io_drv_ptr[3], 0xb8000888);
            cr_writel( io_drv_ptr[4], 0xb800088c);

            dw_em_init_phase(sdport,w_phase,0xff,c_phase);

            EM_ALERT("0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n",
                0xb8000874,cr_readl(0xb8000874),
                0xb8000880,cr_readl(0xb8000880),
                0xb8000884,cr_readl(0xb8000884),
                0xb8000888,cr_readl(0xb8000888),
                0xb800088c,cr_readl(0xb800088c));
            return;
        }

        io_pad_setting1 = IO_PAD_8A0_HS400;
        io_pad_setting2 = IO_PAD_8A0_HS400;
        io_pad_setting3 = IO_PAD_8A0_HS400;
        io_pad_setting4 = IO_PAD_8A0_HS400;
        io_pad_setting5 = IO_PAD_8A0_HS400;

    }else if(type_sel == DRIVING_HS200){
        w_phase = DEFAULT_W_PHASE_200;
        c_phase = DEFAULT_C_PHASE_200;
        io_pad_setting1 = IO_PAD_8A0_HS200;
        io_pad_setting2 = IO_PAD_8A0_HS200;
        io_pad_setting3 = IO_PAD_8A0_HS200;
        io_pad_setting4 = IO_PAD_8A0_HS200;
        io_pad_setting5 = IO_PAD_8A0_HS200;
    }else{
        w_phase = DEFAULT_W_PHASE;
        c_phase = DEFAULT_C_PHASE;
        io_pad_setting1 = IO_PAD_8A0_HS50;
        io_pad_setting2 = IO_PAD_8A0_HS50;
        io_pad_setting3 = IO_PAD_8A0_HS50;
        io_pad_setting4 = IO_PAD_8A0_HS50;
        io_pad_setting5 = IO_PAD_8A0_HS50;
    }

    /*
     eMMC Pad driving/duty cycle:
    */
    cr_writel(io_pad_setting1,0xb8000874);  //rst/clk/cmd
    cr_writel(io_pad_setting2,0xb8000880);  //dummy/ds/d5
    cr_writel(io_pad_setting3,0xb8000884);  //d3/d4/d0
    cr_writel(io_pad_setting4,0xb8000888);  //d1/d2/d7
    cr_writel(io_pad_setting5,0xb800088c);  //d6

    dw_em_init_phase(sdport,w_phase,0xff,c_phase);

}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_crt_reset(struct rtksd_host *sdport,u32 sync)
{
    /*
      reset all eMMC module.
     */
    if(sync){
        /* crt sync reset */
        cr_writel(RSTN_EM_DW,RTK_EM_DW_SRST);
        cr_writel((CLKEN_EM_DW | 0x01U),RTK_EM_DW_CLKEN);
        udelay(10);
        cr_writel(CLKEN_EM_DW,RTK_EM_DW_CLKEN);
    }else{
        cr_writel(CLKEN_EM_DW,RTK_EM_DW_CLKEN);
        cr_writel(RSTN_EM_DW,RTK_EM_DW_SRST);
        udelay(5);
    }

    cr_writel((RSTN_EM_DW | 0x01UL),RTK_EM_DW_SRST);
    cr_writel((CLKEN_EM_DW | 0x01U),RTK_EM_DW_CLKEN);
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_reset_host(struct rtksd_host *sdport,u8 save_en)
{
    unsigned long flags;
    u32 config1;
    u32 config2;
    u32 config3;
    u32 config4;
    u32 config5;
    u32 config6;
    u32 config7;

    mmcmsg3("\n");
    spin_lock_irqsave(&sdport->lock,flags);
    if(save_en){
        mmcmsg3("\n");
        /* store currently IP setting */
        config1 = cr_readl(EM_DWC_PWREN);
        config2 = cr_readl(EM_DWC_CLKDIV);
        config3 = cr_readl(EM_DWC_CTYPE);
        config4 = cr_readl(EM_DWC_UHS_REG);
        config5 = cr_readl(EM_DWC_DBADDR);
        config6 = cr_readl(EM_DWC_EMMC_DDR_REG);
        config7 = cr_readl(EM_HALF_CYCLE_CAL_EN);
        dw_em_dis_sd_tune(sdport);
    }

    /*
      reset all eMMC module.
     */
    dw_em_crt_reset(sdport,0);

    /* reset synopsys eMMC IP */
    dw_em_IP_config(sdport);

    if(save_en){
        /* restore previously IP setting */
        cr_writel(config1,EM_DWC_PWREN);
        spin_unlock_irqrestore(&sdport->lock, flags);
        dw_em_set_div(sdport,(config2<<1));
        spin_lock_irqsave(&sdport->lock,flags);
        cr_writel(config3,EM_DWC_CTYPE);
        cr_writel(config4,EM_DWC_UHS_REG);
        cr_writel(config5,EM_DWC_DBADDR);
        cr_writel(config6,EM_DWC_EMMC_DDR_REG);
        if(config7 & _BIT0){
            dw_em_set_ds_delay(sdport, sdport->cur_ds_tune);
        }
    }

    sdport->rtflags |= RTKCR_FHOST_POWER;
    sdport->reset_event = 0;

    spin_unlock_irqrestore(&sdport->lock, flags);
}

/************************************************************************
 *
 ************************************************************************/
#if 0
static
u32 dw_em_chk_card_busy(void)
{
    if(cr_readl( EM_DWC_STATUS ) & SDMMC_DAT0_BUSY)
        return 1;
    else
        return 0;

}
#endif

/************************************************************************
 * usage: force sdport->cur_ds_tune = 0 to make sure 1st tune on ds-tune.
 ************************************************************************/
#if 0
static
int dw_em_auto_sd_tune(struct rtksd_host *sdport)
{
    u32 ds_tune;
    u32 dis_auto_tune = 0;

    if(rtk_emmc_test_ctl & EMMC_FIX_DSTUNE){
        EM_ALERT("%s(%d)Use Bootcode pre-setting parameter\n",__func__,__LINE__);
        dis_auto_tune = 1;
    }
    ds_tune = sdport->cur_ds_tune;
    mmcmsg4("%s(%d)ds_tune = 0x%08x \n",__func__,__LINE__,ds_tune);

    /*
     enable DS-tune
     Enable of half-cycle calibration
     */
    cr_maskl(EM_HALF_CYCLE_CAL_EN,1,18 ,0);     /* fw_mode is trigged by rising */
    udelay(5);
    cr_maskl(EM_DS_TUNE_CTRL,0x1f,15 ,ds_tune);     /* fill result read from  0xb8010890 */

#if 0
    /* skip direct settting, use ds_tune offset to tuning */
    if(dis_auto_tune){
        cr_maskl(EM_HALF_CYCLE_CAL_EN,0x1f,3 ,ds_tune);
        cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1 ,3);
        cr_maskl(EM_DS_TUNE_CTRL,1,20 ,1);
        cr_maskl(EM_HALF_CYCLE_CAL_EN,1,0 ,1);
    }else
#endif
    {
        /* pre-setting fine-tune value *** */

        if(dis_auto_tune){
            unsigned int tmp_dstune;
            tmp_dstune = sdport->mmc_dstune;

            if(tmp_dstune & 0x80){
                /* half_cycle_res_mod = 1 */
                EM_ALERT("%s(%d)---\n",__func__,__LINE__);
                cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1 ,1);
            }else{
                /* half_cycle_res_mod = 2 */
                EM_ALERT("%s(%d)+++\n",__func__,__LINE__);
                cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1 ,2);
            }
            tmp_dstune &= 0x1fUL;
            cr_maskl(EM_HALF_CYCLE_CAL_EN,0x1f,3 ,tmp_dstune);
            EM_ALERT("%s(%d)force offset ds_tune = %d\n",__func__,__LINE__,tmp_dstune);
        }else{
#if 0
            /* half_cycle_res_mod = 2; "1=>minus";"2=>plus" */
            if(sdport->mid == 0x15){
                /* set half_cycle_res_thr = -2 for Samsung*/
                cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1 ,1);
                cr_maskl(EM_HALF_CYCLE_CAL_EN,0x1f,3 ,2);
            }else{
                /* set half_cycle_res_thr = +3 */
                cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1 ,2);
                cr_maskl(EM_HALF_CYCLE_CAL_EN,0x1f,3 ,3);
            }
#endif
            cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1 ,3);
            cr_maskl(EM_HALF_CYCLE_CAL_EN,0x1f,3 ,sdport->cur_ds_tune);

        }

        /* enable auto ds tune */
        cr_maskl(EM_DS_TUNE_CTRL,1,20 ,1);  /* bypass SW mode */
        cr_maskl(EM_HALF_CYCLE_CAL_EN,1,18 ,1); /*enable half cycle calibrate mode*/
        cr_maskl(EM_HALF_CYCLE_CAL_EN,1,0 ,1);
    }

    udelay(5);
    cr_maskl(EM_HALF_CYCLE_CAL_EN,1,18 ,0); /* fw_mode is trigged by rising */

    mmcmsg4("0x%08x=0x%08x 0x%08x=0x%08x\n",
        (unsigned int)EM_HALF_CYCLE_CAL_EN,(unsigned int)cr_readl(EM_HALF_CYCLE_CAL_EN),
        (unsigned int)EM_HALF_CYCLE_CAL_RESULT,(unsigned int)cr_readl(EM_HALF_CYCLE_CAL_RESULT));

    return 0;
}
#endif

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_dis_sd_tune(struct rtksd_host *sdport)
{
    u32 reginfo;

    reginfo = cr_readl(EM_HALF_CYCLE_CAL_EN);

    if(reginfo & _BIT0){
        mmcmsg4("record ds-tune value");
        /* record ds-tune value */
        sdport->cur_ds_tune = cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f;

        cr_maskl(EM_HALF_CYCLE_CAL_EN,1,0 ,0);  /* disable DS-tune */

        mmcmsg4("%s(%d)ds_tune=0x%08x\n",
            __func__,__LINE__,sdport->cur_ds_tune);
        mmcmsg4("0x%08x=0x%08x 0x%08x=0x%08x\n",
            (unsigned int)EM_HALF_CYCLE_CAL_EN,(unsigned int)cr_readl(EM_HALF_CYCLE_CAL_EN),
            (unsigned int)EM_HALF_CYCLE_CAL_RESULT,(unsigned int)cr_readl(EM_HALF_CYCLE_CAL_RESULT));
    }else{
        mmcmsg4("skip\n");
    }

    return 0;
}


/************************************************************************
 *
 ************************************************************************/
static
int dw_em_set_DDR400(struct rtksd_host *sdport, u32 ddr_mode)
{
    u32 reginfo;
    u32 ddr_targ;
    unsigned long flags;

    mmcmsg3("ddr_mode=0x%08x\n",ddr_mode);
    /* non-DDR mode, SW 1.8V */
    cr_writel(_BIT0, EM_DWC_UHS_REG);

    reginfo = cr_readl(EM_DWC_EMMC_DDR_REG);
    mmcmsg3("0x%08x = 0x%08x\n",(u32)EM_DWC_EMMC_DDR_REG,reginfo);

    spin_lock_irqsave(&sdport->lock, flags);

    if (ddr_mode) {
        ddr_targ = _BIT31;
    } else {
        ddr_targ = 0;
    }

    if ((reginfo & (_BIT31)) != ddr_targ) {
        reginfo = 0;

        if (ddr_targ) {
            reginfo |= ddr_targ;
            EM_NOTICE("HS400 enable\n");
        } else {
            EM_NOTICE("HS400 disable\n");
        }
        EM_NOTICE("set phase 0x%x=0x%08x\n",EMMC_PLLPHASE_CTRL,cr_readl(EMMC_PLLPHASE_CTRL));
        cr_writel(reginfo, EM_DWC_EMMC_DDR_REG);
    }else{
        /* nothing to do */
        mmcmsg3("skip\n");
    }

    spin_unlock_irqrestore(&sdport->lock, flags);

    return 0;

}


/************************************************************************
 *  if reset IP, this reg should be recoard and restore
 ************************************************************************/
static
int dw_em_set_DDR(struct rtksd_host *sdport, u32 ddr_mode)
{
    u32 reginfo;
    u32 ddr_targ;
    unsigned long flags;

    /*
     * If DDR400 enable last time, disable it.
     */
    cr_writel(0, EM_DWC_EMMC_DDR_REG);

    reginfo = cr_readl(EM_DWC_UHS_REG);
    spin_lock_irqsave(&sdport->lock, flags);

    if (ddr_mode) {
        ddr_targ = (_BIT16 | _BIT0);
    } else {
        ddr_targ = 0;
    }

    if ((reginfo & (_BIT16|_BIT0)) == ddr_targ) {
        /* do nothing */
    } else {
        reginfo &= ~(_BIT16 | _BIT0);

        if (ddr_targ) {
            reginfo |= ddr_targ;
            EM_INFO("DDR enable\n");
        } else {
            EM_INFO("DDR disable\n");
        }
        cr_writel(reginfo, EM_DWC_UHS_REG);
    }

    spin_unlock_irqrestore(&sdport->lock, flags);

    return 0;

}

/************************************************************************
 * if reset IP, this reg should be recoard and restore
 ************************************************************************/
static
int dw_em_set_bits(struct rtksd_host *sdport, u32 bus_width)
{
    u32 reginfo = 0;
    u32 bit_targ;

    unsigned long flags;

    reginfo = cr_readl(EM_DWC_CTYPE);

    spin_lock_irqsave(&sdport->lock, flags);

    if (bus_width == MMC_BUS_WIDTH_8) {
        if (reginfo & _BIT16) {
            goto skip_out;
        } else {
            EM_NOTICE("%s: 8 bits mode\n",DRIVER_NAME);
            bit_targ = _BIT16;
            sdport->cur_width = 8;
        }
    } else if (bus_width == MMC_BUS_WIDTH_4) {
        if (reginfo & _BIT0) {
            goto skip_out;
        }else{
            EM_NOTICE("%s: 4 bits mode\n",DRIVER_NAME);
            bit_targ = _BIT0;
            sdport->cur_width = 4;
        }
    }else{
        if (reginfo & (_BIT16 | _BIT0)) {
            EM_NOTICE("%s: 1 bits mode\n",DRIVER_NAME);
            bit_targ = 0;
            sdport->cur_width = 1;
        } else {
            goto skip_out;
        }
    }
    reginfo &= ~(_BIT16 | _BIT0);
    reginfo |= bit_targ;

    cr_writel( reginfo,EM_DWC_CTYPE);

skip_out:

    spin_unlock_irqrestore(&sdport->lock, flags);
    return 0;

}

/************************************************************************
 * reference .\linux-3.10.0\drivers\mmc\host\dw_mmc.c
 * static u32 dw_mci_prepare_command(struct mmc_host *mmc, struct mmc_command *cmd)
 ************************************************************************/
#define AUTO_SEND_STOP
static
u32 dw_em_prepare_command(struct sd_cmd_pkt * cmd_info)
{
    struct mmc_command *cmd = cmd_info->cmd;
    u32 cmd_idx  = 0;
    u32 cmd_flag = 0;
    u32 rsp_typ  = 0;
    u32 cmd_typ  = 0;
    u32 wrt_typ  = 0;

    if(cmd == NULL)
        BUG_ON(1);

    cmd_idx = (u32)(cmd->opcode);
    rsp_typ = (u32)mmc_resp_type(cmd);
    cmd_typ = (u32)mmc_cmd_type(cmd);

    if(cmd->data)
        wrt_typ = (u32)cmd->data->flags;

    cmd_flag = cmd_idx;

    if (cmd_idx == MMC_STOP_TRANSMISSION)
        cmd_flag |= SDMMC_CMD_STOP;
    else{
        cmd_flag |= SDMMC_CMD_PRV_DAT_WAIT;
    }

    /* before idle cmd, send 80 clk plus first */
    if(cmd_idx == MMC_GO_IDLE_STATE)
        cmd_flag |= SDMMC_CMD_INIT;

    /* check resp type */
    if(rsp_typ & MMC_RSP_PRESENT){

        cmd_flag |= (SDMMC_CMD_RESP_EXP);

        if(rsp_typ & MMC_RSP_136)
            cmd_flag |= (SDMMC_CMD_RESP_LONG);

    }

    /*
       Cmd13 skip resp CRC check.
       reference JESD84-B50-1.pdf; 6.6.2 High-speed modes selection
       Because hard to judge what time is proper disable CRC time,
       Skip all time here
     */
    if( (rsp_typ & MMC_RSP_CRC)
     && (cmd_idx != MMC_SEND_STATUS) )
    {
        cmd_flag |= (SDMMC_CMD_RESP_CRC);
    }

    /* check cmd type ADTC? */
    if (cmd_typ == MMC_CMD_ADTC) {
        cmd_flag |= SDMMC_CMD_DAT_EXP;

        /* check data write/read */
        if(wrt_typ == MMC_DATA_WRITE)
            cmd_flag |= SDMMC_CMD_DAT_WR;
    }
#ifdef AUTO_SEND_STOP
    /* auto send stop cmd */
    if((cmd_idx == MMC_READ_MULTIPLE_BLOCK)
    || (cmd_idx == MMC_WRITE_MULTIPLE_BLOCK)) {
        cmd_flag |= SDMMC_CMD_SEND_STOP;
    }
#endif

    cmd_flag |= SDMMC_CMD_USE_HREG;
    cmd_info->cmd_flag = cmd_flag;

    return cmd_flag;
}

/************************************************************************
 * Note : If relative interrupt are disable,
          these value of regiter will be zero.
 ************************************************************************/
void show_int_sta(const char *c_func,
        const int c_line,
        struct rtksd_host *sdport,
        u32 ctl)
{
#ifdef MMC_DEBUG
#define READ_FROM_REG _BIT0
    u32 int_status;
    u32 sd_trans;
    u32 sd_status;
    u32 wrap_sta;

    if(ctl & READ_FROM_REG){
        int_status  = cr_readl(EM_DWC_RINTSTS);
        sd_trans    = cr_readl(EM_DWC_IDSTS);
        sd_status   = cr_readl(EM_DWC_STATUS);
        wrap_sta    = cr_readl(EM_INT_STATUS);
    }else{
        int_status  = sdport->int_status;
        sd_trans    = sdport->sd_trans;
        sd_status   = sdport->sd_status;
        wrap_sta    = sdport->wrap_sta;

    }
    EM_ERR( "%s(%d){\n"
        "    EM_DWC_RINTSTS = 0x%08x EM_DWC_IDSTS   = 0x%08x\n"
        "    EM_DWC_STATUS  = 0x%08x EM_INT_STATUS  = 0x%08x\n"
        "}\n",
        c_func,c_line,
        int_status,sd_trans,
        sd_status,wrap_sta);
#endif
}

/************************************************************************
 *
 ************************************************************************/
/* #define EN_CAL_XFER_TIME */
#define IDMAC_NORMAL_INT    (SDMMC_IDMAC_INT_NI|SDMMC_IDMAC_INT_RI|SDMMC_IDMAC_INT_TI)
#define IDMAC_INT_ERR       (SDMMC_IDMAC_INT_AI|SDMMC_IDMAC_INT_CES| \
                             SDMMC_IDMAC_INT_DU|SDMMC_IDMAC_INT_FBE)

#define RECORD_STATE_LEN 10
static unsigned int sta_2nd[RECORD_STATE_LEN];
static unsigned int sta_1st[RECORD_STATE_LEN];

static
int dw_em_show_record_sta(unsigned int* buf_1st,unsigned int* buf_2nd);

static
int dw_em_record_sta(
    unsigned int sta0,unsigned int sta1,
    unsigned int sta2,unsigned int sta3,
    unsigned int sta4,unsigned int sta5,
    unsigned int sta6,unsigned int sta7,
    unsigned int sta8,unsigned int sta9)
{
/*
    cmd_idx,
    cmd_arg,
    cmd_flag,
    sdport->int_status = cr_readl(EM_DWC_RINTSTS);
    sdport->sd_status  = cr_readl(EM_DWC_STATUS);
    sdport->sd_trans   = cr_readl(EM_DWC_IDSTS);
    sdport->wrap_sta   = cr_readl(EM_INT_STATUS);
    cr_readl(EM_DWC_BYTCNT),
    timeend
*/
    int i;
    for(i=0;i<RECORD_STATE_LEN;i++){
        sta_2nd[i] = sta_1st[i];
    }

    sta_1st[0]= sta0;
    sta_1st[1]= sta1;
    sta_1st[2]= sta2;
    sta_1st[3]= sta3;
    sta_1st[4]= sta4;
    sta_1st[5]= sta5;
    sta_1st[6]= sta6;
    sta_1st[7]= sta7;
    sta_1st[8]= sta8;
    sta_1st[9]= sta9;

    return 0;
}

static
int dw_em_show_record_sta(unsigned int* buf_1st,unsigned int* buf_2nd)
{
    EM_ALERT("last 2nd:\n"
        "        sta[0]=0x%08x sta[1]=0x%08x sta[2]=0x%08x sta[3]=0x%08x\n"
            "        sta[4]=0x%08x sta[5]=0x%08x sta[6]=0x%08x sta[7]=0x%08x\n"
            "        sta[8]=0x%08x sta[9]=0x%08x\n",
            buf_2nd[0],buf_2nd[1],buf_2nd[2],buf_2nd[3],
            buf_2nd[4],buf_2nd[5],buf_2nd[6],buf_2nd[7],
            buf_2nd[8],buf_2nd[9]);

    EM_ALERT("last 1st:\n"
        "        sta[0]=0x%08x sta[1]=0x%08x sta[2]=0x%08x sta[3]=0x%08x\n"
            "        sta[4]=0x%08x sta[5]=0x%08x sta[6]=0x%08x sta[7]=0x%08x\n"
            "        sta[8]=0x%08x sta[9]=0x%08x\n",
            buf_1st[0],buf_1st[1],buf_1st[2],buf_1st[3],
            buf_1st[4],buf_1st[5],buf_1st[6],buf_1st[7],
            buf_2nd[8],buf_2nd[9]);

    return 0;
}

static
int rtkem_debug_info(struct sd_cmd_pkt * cmd_info)
{
#if 0
    u32 *des_base;
    u32 i;

    EM_ALERT("\n****** BUS Status Info ******\n");

    EM_ALERT("======DC_SYS FIFO Status======\n"
         "    0x%08x=0x%08x 0x%08x=0x%08x\n",
            (u32)0xb8007064,(u32)cr_readl(0xb8007064),
            (u32)0xb8003064,(u32)cr_readl(0xb8003064));
    EM_ALERT("======IB FIFO Status======\n"
         "    0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n"
         "    0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n"
         "    0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n"
         "    0x%08x=0x%08x 0x%08x=0x%08x\n",
            (u32)0xb803F0F0,(u32)cr_readl(0xb803F0F0),
            (u32)0xb803F1F0,(u32)cr_readl(0xb803F1F0),
            (u32)0xb803F2F0,(u32)cr_readl(0xb803F2F0),
            (u32)0xb803F3F0,(u32)cr_readl(0xb803F3F0),
            (u32)0xb803F4F0,(u32)cr_readl(0xb803F4F0),
            (u32)0xb803F5F0,(u32)cr_readl(0xb803F5F0),
            (u32)0xb803F6F0,(u32)cr_readl(0xb803F6F0),
            (u32)0xb803F7F0,(u32)cr_readl(0xb803F7F0),
            (u32)0xb803F8F0,(u32)cr_readl(0xb803F8F0),
            (u32)0xb803F9F0,(u32)cr_readl(0xb803F9F0),
            (u32)0xb803FAF0,(u32)cr_readl(0xb803FAF0),
            (u32)0xb803FBF0,(u32)cr_readl(0xb803FBF0),
            (u32)0xb803FCF0,(u32)cr_readl(0xb803FCF0),
            (u32)0xb803FCF0,(u32)cr_readl(0xb803FCF0));
    EM_ALERT("\n****** WRAPPER setting ******\n"
         "    0x%08x=0x%08x 0x%08x=0x%08x\n",
            (u32)0xb8007008,(u32)cr_readl(0xb8007008),
            (u32)0xb80070c8,(u32)cr_readl(0xb80070c8));
    EM_ALERT("======eMMC descripter======\n");
    des_base = cmd_info->sdport->scrip_buf;
    for(i=0;i<10;i++){
        EM_ALERT("{Line%02u}[des0]=0x%08x [des1]==0x%08x [des2]==0x%08x [des3]==0x%08x\n",
            i,des_base[(i*4)+0],des_base[(i*4)+1],des_base[(i*4)+2],des_base[(i*4)+3]);
    }

    EM_ALERT("\n&&&&&& BUS Status Info &&&&&&\n");
#endif
    return 0;
}

/************************************************************************
 *
 ************************************************************************/
#define GET_DBUS_SMA(value) ((value>>16)&0x07)
#define GET_AHB_SMA(value)  (value & 0x7FFF)
static
int dw_em_TriggerXferCmd(u32 cmd_flag,struct sd_cmd_pkt * cmd_info)
{
    struct rtksd_host *sdport = cmd_info->sdport;
    int ret_err = 0;
    u32 cmd_idx = 0;
    u32 int_mode = 0;
    u32 reginfo = 0;
    unsigned long timeend = 0;
    unsigned long flags;
    u32 cmd_arg = 0;
    u32 warp_sta1 = 0;

#ifdef EN_CAL_XFER_TIME
    struct timeval tt1;
    struct timeval tt2;
#endif

    DECLARE_COMPLETION(rtk_wait);
    sdport->task_state = 0;
    if(sdport->tmout){
        timeend = sdport->tmout;
        sdport->tmout = 0;
    }else{
        WARN_ON(1);
        timeend = msecs_to_jiffies(100);
    }

    sdport->int_status  = 0;
    sdport->sd_trans    = 0;
    sdport->sd_status   = 0;
    sdport->wrap_sta    = 0;

    spin_lock_irqsave(&sdport->lock,flags);

    /* Here, we use cmd_flag to get information for flow sync reason.  */
    cmd_idx = SDMMC_CMD_INDX(cmd_flag);
    cmd_arg = (u32)(cmd_info->cmd->arg);

    /* Start IDMAC running */
    cr_writel(1, EM_DWC_PLDMND);

    /* disable and clear int */
    dw_em_clear_int_sta(1);
    dw_em_clear_int_sta_IDMA(1);
    dw_em_clear_int_wrap(1);

    if((cmd_flag & USE_INT_MODE) == USE_INT_MODE)
        int_mode = 1;

    sdport->int_waiting = &rtk_wait;
    if(int_mode){
        u32 int_reg = 0;

/* #define EN_IDMA_INT*/
#ifdef EN_IDMA_INT
        u32 dwc_reg = 0;
#endif
        /* setting interrupt mask */
        int_reg = 0xffff;
        if (cmd_flag & SDMMC_CMD_DAT_EXP){
            int_reg &= ~(SDMMC_INT_RXDR | SDMMC_INT_TXDR | SDMMC_INT_ACD);

            /* do not check SDMMC_INT_CMD_DONE and SDMMC_INT_DATA_OVER */
            int_reg &= ~(SDMMC_INT_CMD_DONE|SDMMC_INT_DATA_OVER);
#ifdef EN_IDMA_INT


            /* setting IDMA interrupt mask */
            dwc_reg = IDMAC_NORMAL_INT;
            cr_writel(dwc_reg, EM_DWC_IDINTEN);
#endif

            /*enable wrap int */
            cr_writel(0x00, EM_INT_MASK);

        }else{
            /* do nothing here */
        }
        cr_writel(int_reg, EM_DWC_INTMASK);

        /* enable global interrupt */
        reginfo =  (cr_readl(EM_DWC_CTRL)|SDMMC_CTRL_INT_ENABLE);
        cr_writel(reginfo, EM_DWC_CTRL);

    } else {
        sdport->task_state = STATE_SENDING_DATA;
        tasklet_schedule(&sdport->polling_tasklet);
    }

    if(cmd_arg==0x03a50101 ){
        /* if sanitize operation, waitting until finish. */
    }else{
        if(sdport->rtflags & RTKCR_TUNING_STATE){
            timeend = msecs_to_jiffies(10);
        }
        mod_timer(&sdport->timer, (jiffies + timeend) );
    }

#ifdef EN_CAL_XFER_TIME
    do_gettimeofday(&tt1);
#endif
    smp_wmb();

#if 0
    if(cr_readl(EM_DWC_RINTSTS)){
        EM_ERR("cmd_idx=%02d cmd_flag=0x%08x\n",
               cmd_idx,cmd_flag);

        EM_ERR("0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x \n",
               (u32)EM_DWC_RINTSTS,cr_readl(EM_DWC_RINTSTS),
               (u32)EM_DWC_IDSTS,cr_readl(EM_DWC_IDSTS),
               (u32)EM_DWC_STATUS,cr_readl(EM_DWC_STATUS),
               (u32)EM_INT_STATUS,cr_readl(EM_INT_STATUS));
    }
#endif
    cr_writel(cmd_flag | SDMMC_CMD_START, EM_DWC_CMD);

    spin_unlock_irqrestore(&sdport->lock, flags);

    wait_for_completion(&rtk_wait);

    if (!(sdport->int_status & SDMMC_INT_ERROR)
     && !(sdport->sd_trans & IDMAC_INT_ERR))
    {
        u32 fsm = (sdport->sd_trans & (0xf<<13))>>13;
        if(fsm){
            mmcmsg2("FSM not idel(%u)",fsm);
        }
    }

    ret_err = cmd_info->cmd->error;

#ifdef EN_CAL_XFER_TIME
    do_gettimeofday(&tt2);
#endif

    if( ret_err) {
        rtk_emmc_err_cnt++;
        if((sdport->rtflags & RTKCR_TUNING_STATE) ) {
#if 0
            /* skip log display while tuning flow  */
            EM_ERR( "%s: Tuning State{mid=0x%x}\n"
                "    cmd_idx=%d RINTSTS=0x%08x\n",
                DRIVER_NAME, sdport->mid,
                cmd_idx, sdport->int_status);
#endif
        } else {
            warp_sta1 = cr_readl(EM_WARP_STATUS1);
            if(rtk_emmc_test_ctl & EMMC_RCV_FLOW){
                dw_em_show_record_sta(sta_1st,sta_2nd);
            }
                if (cmd_flag & SDMMC_CMD_DAT_EXP)
                    sdport->rtflags |= RTKCR_RECOVER_STATE;

            EM_ERR( "%s: Recover State{mid=0x%x}\n"
                "    cmd_idx=%d cmd_arg=0x%08x cmd_flag=0x%08x loops=0x%x\n"
                "        RINTSTS=0x%08x  STATUS=0x%08x\n"
                "        IDSTS=0x%08x(0x%08x)%s\n"
                "        INT_STATUS=0x%08x  EM_DWC_BYTCNT=0x%08x\n"
                "        WARP_STATUS0=0x%08x  WARP_STATUS1=0x%08x\n",
                DRIVER_NAME, sdport->mid,
                cmd_idx, cmd_arg, cmd_flag, cmd_info->timeout,
                sdport->int_status,sdport->sd_status,
                sdport->sd_trans,cr_readl(EM_DWC_STATUS),
                (sdport->sd_trans & (0x1f << 13))?"[DMAC not Idle!!!]":"",
                sdport->wrap_sta,cr_readl(EM_DWC_BYTCNT),
                cr_readl(EM_WARP_STATUS0),warp_sta1);
            mmcmsg3("0x%08x=0x%08x 0x%08x=0x%08x\n",
                (u32)EM_HALF_CYCLE_CAL_EN,(u32)cr_readl(EM_HALF_CYCLE_CAL_EN),
                (u32)EM_HALF_CYCLE_CAL_RESULT,(u32)cr_readl(EM_HALF_CYCLE_CAL_RESULT));

            rtkem_debug_info(cmd_info);

#ifdef EN_CAL_XFER_TIME

            if(tt1.tv_usec > tt2.tv_usec){
                tt2.tv_usec+=1000000;
            }
            EM_ERR( "MMCT %ld.%lds\n",
                (tt2.tv_sec-tt1.tv_sec),
                (tt2.tv_usec-tt1.tv_usec));
#endif
        }

        if((cmd_flag & SDMMC_CMD_DAT_EXP)
         &&((GET_DBUS_SMA(warp_sta1)!=1) || (GET_AHB_SMA(warp_sta1)!=1)))
        {
            /* if wrap state machine not idle, reset wrap */
            dw_em_reset_host(sdport,1);
        }else{
            dw_em_reset_host_IP(sdport,1);
        }
#ifdef RECOVER_FLOW_TEST
        dw_em_signal_restore();
#endif

    }else{
        if ((sdport->rtflags & RTKCR_RECOVER_STATE)
         && (cmd_flag & SDMMC_CMD_DAT_EXP))
        {
            sdport->rtflags &= ~RTKCR_RECOVER_STATE;
            EM_ALERT("recover success!\n");
        }
    }
    dw_em_record_sta(cmd_idx,cmd_arg,cmd_flag,sdport->int_status,
            sdport->sd_status,sdport->sd_trans,
            sdport->wrap_sta,cr_readl(EM_DWC_BYTCNT),
            (u32)timeend,0);
#ifdef EN_CAL_XFER_TIME
    if(sdport->rtflags & RTKCR_FOPEN_LOG){
        if(tt1.tv_usec > tt2.tv_usec){
            tt2.tv_usec+=1000000;
        }
        EM_ALERT("old time: %ld.%06ldus\n",tt1.tv_sec,tt1.tv_usec);
        EM_ALERT("cur time: %ld.%06ldus\n",tt2.tv_sec,tt2.tv_usec);
        EM_ALERT( "MMCT %ld.%06lds (C=%d)[B=%d]%s\n",
            (tt2.tv_sec-tt1.tv_sec),
            (tt2.tv_usec-tt1.tv_usec),
            cmd_idx,
            cmd_info->block_count, (ret_err) ? "fail!" : "");
    }
#endif

    return ret_err;
}

/************************************************************************
 *
 ************************************************************************/
void dw_em_crt_muxpad(struct rtksd_host *sdport)
{
    /* 296x do not need. Its dedicate pin */
    return;
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_SendCmd(struct sd_cmd_pkt *cmd_info)
{
    struct rtksd_host *sdport   = cmd_info->sdport;
    struct mmc_command *cmd     = cmd_info->cmd;
    u32 cmd_idx                 = (u32)(cmd->opcode);
    u32 cmd_arg = (u32) (cmd->arg);
    u32 *rsp                    = cmd->resp;
    u32 cmd_flag = 0;
    unsigned long flags;

    int ret_err = 0;
    int rsp_err = 0;

    if(rsp == NULL) {
        BUG_ON(1);
    }

    if(dw_em_get_occupy(sdport)){
        return cmd_info->cmd->error = -EIO;
    }

    dw_em_get_cmd_timeout(cmd_info);
    cmd_flag = dw_em_prepare_command(cmd_info);

    if(cmd_idx == 23)
        sdport->rtflags |= RTKCR_CMD23_ALERT;

    if( (sdport->rtflags & RTKCR_FOPEN_LOG)
     || (sdport->rtflags & RTKCR_RECOVER_STATE))
    {
        EM_ALERT("cmd_idx=%02d cmd_arg=0x%08x cmd_flag=0x%08x retries=%u\n",
               cmd_idx, cmd_arg, cmd_flag, cmd->retries);
        EM_ALERT("        ds_tune=%u\n",
            (cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f));
    }

    if( sdport->log_state == 1 )
    {
        if (cmd_idx == 35)
            EM_WARNING("[EMMC ERASE]: start addr: 0x%x\n", cmd_arg);
        else if (cmd_idx == 36)
            EM_WARNING("[EMMC ERASE]: end addr: 0x%x\n", cmd_arg);
        else if (cmd_idx == 6)
        {
            if ((cmd_arg & 0xffffff00) == 0x3200100)
                EM_WARNING("[EMMC FLUSH]: 0x%x\n", cmd_arg);
        }
    }

    if( (cmd_idx == 6)
     && (rtk_emmc_test_ctl & EMMC_EN_MMC_DRV) ){
        u32 tmp_mmc_drv = sdport->mmc_drv;
        u32 chg_alert = 0;

        if((cmd_arg & 0xffff0fff) == 0x03b90301 ){
            /* HS400 mode */
            tmp_mmc_drv = (tmp_mmc_drv & 0x00ff0000)>>16;
            if(tmp_mmc_drv <= 4)
                chg_alert = 1;
        }else if((cmd_arg & 0xffff0fff) == 0x03b90201 ){
            /* HS200 mode */
            tmp_mmc_drv = (tmp_mmc_drv & 0x0000ff00)>>8;
            if(tmp_mmc_drv <= 4)
                chg_alert = 1;
        }
        if(chg_alert){
            EM_NOTICE("%s(%d)Use Bootcode pre-setting parameter\n",
                __func__,__LINE__);
            EM_NOTICE("%s(%d)arg=0x%08x mmc_drv=0x%08x\n",
                __func__,__LINE__,cmd_arg,tmp_mmc_drv);
            cmd_arg &= 0xffff0fff;
            cmd_arg |= (tmp_mmc_drv<<12);
            EM_NOTICE("%s(%d)arg=0x%08x mmc_drv=0x%08x\n",
                __func__,__LINE__,cmd_arg,tmp_mmc_drv);
        }
    }

    spin_lock_irqsave(&sdport->lock,flags);

    cr_writel(cmd_arg,  EM_DWC_CMDARG);
    cr_writel(0,        EM_DWC_BLKSIZ);
    cr_writel(0,        EM_DWC_BYTCNT);

    spin_unlock_irqrestore(&sdport->lock, flags);

    ret_err = dw_em_TriggerXferCmd(cmd_flag,cmd_info);

    rsp_err = dw_em_chk_rsp(rsp, cmd_flag, cmd_info);

    dw_em_release_occupy(sdport);
    if(rsp_err){
#ifdef SHOW_RESPONSE
        EM_INFO("response error alert. check it!!!\n");
#endif
    }

    if( ret_err ){
        EM_INFO( "%s: %s fail\n", DRIVER_NAME, __func__);
    } else {
        /* TO get manufacturer ID here */
        if(cmd_idx == MMC_ALL_SEND_CID ){
            sdport->mid = ((rsp[0]>>24) & 0xffU);
        }
    }

    return ret_err;
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_Stream_Cmd(struct sd_cmd_pkt * cmd_info)
{
    struct rtksd_host *sdport = cmd_info->sdport;
    struct mmc_command *cmd    = cmd_info->cmd;
    u32  cmd_idx        = (u32)(cmd->opcode);
    u32  cmd_arg        = (u32)(cmd->arg);
    u32 *rsp            = cmd->resp;
    u32  byte_count     = (u32)(cmd_info->byte_count);
    u32  total_byte_cnt = (u32)(cmd_info->total_byte_cnt);
    u32  cmd_flag       = 0;
    unsigned long flags;

    int ret_err = 0;
    int rsp_err = 0;

    if(rsp == NULL) {
        BUG_ON(1);
    }

    dw_em_get_cmd_timeout(cmd_info);

    cmd_flag = dw_em_prepare_command(cmd_info);

    if(sdport->rtflags & RTKCR_CMD23_ALERT){
        sdport->rtflags &= ~RTKCR_CMD23_ALERT;
        cmd_flag &= ~SDMMC_CMD_SEND_STOP;
    }

    if( (sdport->rtflags & RTKCR_FOPEN_LOG)
     || (sdport->rtflags & RTKCR_RECOVER_STATE))
    {
        EM_ALERT("cmd_idx=%02d cmd_arg=0x%08x cmd_flag=0x%08x retries=%u\n"
            "            blk_siz=0x%08x total_byte_cnt=0x%08x\n",
            cmd_idx, cmd_arg, cmd_flag, cmd->retries,
            (u32) byte_count, (u32) total_byte_cnt);
        EM_ALERT("        ds_tune=%u\n",
            (cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f));
    }

    if( (sdport->log_state == 1)
     && ( (cmd_idx == 18) || (cmd_idx == 25)
       || (cmd_idx == 17) || (cmd_idx == 24) ) )
    {
        EM_WARNING("[EMMC %s]: addr: 0x%x; size: 0x%x; {cmd%u}\n",
            ((cmd_idx == 18) || (cmd_idx == 17))? " Read" : "Write",
            cmd_arg, total_byte_cnt,cmd_idx);
    }

    spin_lock_irqsave(&sdport->lock,flags);

    cr_writel(cmd_arg,          EM_DWC_CMDARG);
    cr_writel(byte_count,       EM_DWC_BLKSIZ);
    cr_writel(total_byte_cnt,   EM_DWC_BYTCNT);

    spin_unlock_irqrestore(&sdport->lock, flags);

    ret_err = dw_em_TriggerXferCmd(cmd_flag,cmd_info);

    rsp_err = dw_em_chk_rsp(rsp, cmd_flag, cmd_info);

    if(rsp_err){
#ifdef SHOW_RESPONSE
        if(!(sdport->rtflags & RTKCR_TUNING_STATE))
            EM_INFO("response error alert. check it!!!\n");
#endif
    }

    if( ret_err ){
        if(!(sdport->rtflags & RTKCR_TUNING_STATE))
            EM_INFO( "%s: %s fail\n", DRIVER_NAME, __func__);
    } else {
        /* do nothing now */
    }

    return ret_err;

}

/************************************************************************
 *
 ************************************************************************/
static
void rtk_op_complete(struct rtksd_host *sdport)
{

    if (sdport->int_waiting) {
        struct completion *waiting = sdport->int_waiting;
        sdport->int_waiting = NULL;
        complete(waiting);
    }
}

/************************************************************************
 *
 ************************************************************************/
static
void rtkem_hold_card(struct rtksd_host *sdport)
{
    /* 296x_plus eMMC pin are dedicate.
       It can't hold pin. */
    return;
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_bus_speed_down(struct rtksd_host *sdport)
{
    u32 tmp_clk;
    if(sdport->cur_clock > CLK_100Mhz){
        tmp_clk = (sdport->cur_clock) - CLK_20Mhz;
    } else if (sdport->cur_clock > CLK_50Mhz) {
        tmp_clk = CLK_50Mhz;
    } else {
        tmp_clk = sdport->cur_clock - CLK_10Mhz;
    }
    sdport->ops->set_clk(sdport,tmp_clk);
}

/************************************************************************
 *
 ************************************************************************/
static
u32 dw_em_get_cmd_timeout(struct sd_cmd_pkt *cmd_info)
{
    struct rtksd_host *sdport   = cmd_info->sdport;
    struct mmc_command* cmd     = cmd_info->cmd;
    u16 block_count             = cmd_info->block_count;
    u32 tmout = 0;

    if(cmd_info->cmd->data){
        tmout = msecs_to_jiffies(500);
        if (block_count > 0x100) {
            tmout = tmout + msecs_to_jiffies(block_count>>2);
        }
    }else{
        if (mmc_resp_type(cmd) & MMC_RSP_BUSY) {
            /*
             if response type is R1b,
             Host should wait long time for card busy.
             */
            tmout = msecs_to_jiffies((cmd->busy_timeout > 1000 )? cmd->busy_timeout:1000);
        } else {
            tmout = msecs_to_jiffies(80);
        }
    }

    cmd_info->timeout = sdport->tmout = tmout;
    return 0;
}

/************************************************************************
 *  Reference:  linux-3.10.0\drivers\mmc\host\dw_mmc.c
 *              static void dw_mci_translate_sglist(struct dw_mci *host, struct mmc_data *data,
 *  The byte_ctl is used to judege if data small then 1bolck(512 bytes).
 *  if so, It will set end flag at first loop.
 ************************************************************************/
#define SG_1ST_FLAG (0x01UL<<0)
#define SG_END_FLAG (0x01UL<<1)
#define SG_BYT_FLAG (0x01UL<<2)
#define SHOW_SCRIPT_DATA        0
u32 *dw_em_build_script(u32 *des_base,
    dma_addr_t  dma_addr,
    u32 blk_cnt, u32 *scrip_cnt, u32 ctl,
    struct sd_cmd_pkt *cmd_info)
{
    u32 *des_base2;
    dma_addr_t dma_addr2;
    dma_addr_t scrip_buf_phy;
    u32  blk_cnt2;
    u32  remain_blk_cnt;
    u32 tmp_val;
    *scrip_cnt       = 0;

    des_base2       = des_base;
    dma_addr2       = dma_addr;
    remain_blk_cnt  = blk_cnt;

    scrip_buf_phy = cmd_info->sdport->scrip_buf_phy;

    mmcmsg1("des_base2=0x%p dma_addr2=0x%08x remain_blk_cnt=0x%08x\n",
            des_base2,dma_addr2,remain_blk_cnt);

    while(remain_blk_cnt){

#if SHOW_SCRIPT_DATA
        mmcmsg1("des_base2=0x%08x", (u32)des_base2);
#endif
        /* setting des0; transfer parameter  */

        /*
                 To enable IDMAC interrupt:
         reference to Spec 3.2.3Descriptors.
         Table 3-3 Bits in IDMAC DES0 Element (32-bit Address Configuration)
         meantion about DES0 bit1
         */
        tmp_val = IDMAC_DES0_OWN | IDMAC_DES0_DIC | IDMAC_DES0_CH;
        if(ctl & SG_1ST_FLAG){
            if(remain_blk_cnt == blk_cnt)
                tmp_val |= IDMAC_DES0_FD;
            }

        if(ctl & SG_END_FLAG){
            if(remain_blk_cnt <= EMMC_MAX_SCRIPT_BLK){
                tmp_val |= IDMAC_DES0_LD;
                tmp_val &= ~IDMAC_DES0_DIC;
            }
        }

        des_base2[0] = tmp_val;

        /* setting des1; buffer size in byte */
        if(remain_blk_cnt > EMMC_MAX_SCRIPT_BLK){
            blk_cnt2 = EMMC_MAX_SCRIPT_BLK;
        }else{
            blk_cnt2 = remain_blk_cnt;
        }
        des_base2[1] = (blk_cnt2<<9);

        /* setting des2; Physical address to DMA to/from */
        des_base2[2] = (dma_addr2);

        /* setting des3; next descrpter entry */
        des_base2[3] = scrip_buf_phy+(((cmd_info->scrip_cnt)+(*scrip_cnt)+1)*16);

        if(ctl & SG_BYT_FLAG){
            des_base2[0] |= IDMAC_DES0_LD;
            des_base2[1]  = blk_cnt;
            remain_blk_cnt = 0;
#if SHOW_SCRIPT_DATA
            /*
              the value of des_base[x] and des_base2[x] is different.
              because point des_base2 is increase 4 per loop
            */
            mmcmsg1("des0=0x%08x\n", des_base2[0]);
            mmcmsg1("des1=0x%08x\n", des_base2[1]);
            mmcmsg1("des2=0x%08x\n", des_base2[2]);
            mmcmsg1("des3=0x%08x\n", des_base2[3]);
#endif
        }else{
#if SHOW_SCRIPT_DATA
            /*
              the value of des_base[x] and des_base2[x] is different.
              because point des_base2 is increase 4 per loop
              If want to see value of des_base2[x], It must be here,
              because  des_base2 will be increased later.
            */
            mmcmsg1("des0=0x%08x\n", des_base2[0]);
            mmcmsg1("des1=0x%08x\n", des_base2[1]);
            mmcmsg1("des2=0x%08x\n", des_base2[2]);
            mmcmsg1("des3=0x%08x\n", des_base2[3]);
#endif
            dma_addr2 = dma_addr2+(blk_cnt2<<9);
            remain_blk_cnt -= blk_cnt2;
            des_base2 += 4;
        }
        *scrip_cnt += 1;
    }

    mmcmsg1("scrip_cnt=%u des_base2=0x%p\n", *scrip_cnt, des_base2);

    return des_base2;
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_sg_make_script(struct scatterlist *sg,
             int dma_nents, struct sd_cmd_pkt *cmd_info)
{
    int err = 0;
    u32 i;
    u32 *des_base;
    dma_addr_t dma_addr;
    u32 dma_leng;
    u32 blk_cnt;
    u32 byt_cnt;
    u32 scrip_ctl = 0;
    u32 scrip_cnt = 0;
    u32 total_byte_cnt = 0;

        mmcmsg1("sg=0x%p dma_nents=%d\n",sg,dma_nents);
    cmd_info->scrip_cnt      = 0;
    cmd_info->block_count    = 0;
    cmd_info->total_byte_cnt = 0;
    des_base = cmd_info->sdport->scrip_buf;
    for(i=0; i<dma_nents; i++,sg++){
        scrip_ctl = 0;
        dma_leng = sg_dma_len(sg);
        dma_addr = sg_dma_address(sg);
        mmcmsg1("dma_addr:0x%x; dma_leng:0x%x dma_nents_cnt=%d\n",
            dma_addr, dma_leng, i);

        blk_cnt = (dma_leng>>9);
        byt_cnt = (dma_leng&0x1FF);

        if(byt_cnt){
            if((blk_cnt) || (dma_nents!=1) ){
                WARN(1,
                     "data cont not aligment to 512. dma_leng=%d\n",
                    dma_leng);
                total_byte_cnt = 0;
                err = -1;
                break;
            }
            /*
             * Notice:
             *   The byte mode have never test.
             *   It occur at certain register reading.
             *   Like ACMD51(SEND_CSR) at SD card.
             */
            cmd_info->byte_count = byt_cnt;
            blk_cnt = 1;
            scrip_ctl |= SG_BYT_FLAG;
        }else{
            cmd_info->byte_count = 0x200;
        }
        if(i==0)
            scrip_ctl |= SG_1ST_FLAG;
        if((i+1)==dma_nents)
            scrip_ctl |= SG_END_FLAG;

        if(scrip_ctl & SG_BYT_FLAG)
            des_base =
                dw_em_build_script(des_base, dma_addr, byt_cnt,
                           &scrip_cnt, scrip_ctl,cmd_info);
        else
            des_base =
                dw_em_build_script(des_base, dma_addr, blk_cnt,
                           &scrip_cnt, scrip_ctl,cmd_info);

        cmd_info->scrip_cnt      += scrip_cnt;
        cmd_info->block_count    += blk_cnt;
        cmd_info->total_byte_cnt += dma_leng;
        mmcmsg1("scrip_cnt=%u blk_cnt=0x%08x total_byte_cnt=0x%08x\n",
                cmd_info->scrip_cnt, cmd_info->block_count,
                cmd_info->total_byte_cnt);
    }

    if(cmd_info->scrip_cnt > 256){
        EM_ERR("\ncmd_info->scrip_cnt: %d\n", cmd_info->scrip_cnt);
        EM_ERR("\ncmd_info->block_count: %d\n", cmd_info->block_count);
        EM_ERR("\ncmd_info->total_byte_cnt: %d\n", cmd_info->total_byte_cnt);
        EM_ERR("\ndma_nents: %d\n", dma_nents);
    }

    return err;
}

int export_em_sg_make_script(struct scatterlist *sg,
             int dma_nents, struct sd_cmd_pkt *cmd_info)
{
    return dw_em_sg_make_script(sg,dma_nents,cmd_info);
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_reinit_idmac_pre(struct sd_cmd_pkt *cmd_info)
{
    unsigned int ctrl = 0;

    cr_writel(SDMMC_SWR,EM_DWC_BMOD);

    ctrl = 0;

    cr_writel(IDMAC_INT_CLR,EM_DWC_IDSTS);
    cr_writel(ctrl, EM_DWC_IDINTEN);

    dw_em_set_scrip_base(cmd_info->sdport->scrip_buf_phy);

    /* Select IDMAC interface */
    ctrl = cr_readl(EM_DWC_CTRL);
    ctrl |= SDMMC_CTRL_USE_IDMAC;
    cr_writel(ctrl, EM_DWC_CTRL);
    wmb();

    /* Enable the IDMAC */
    ctrl = cr_readl(EM_DWC_BMOD);
    ctrl |= SDMMC_IDMAC_ENABLE;
    cr_writel(ctrl, EM_DWC_BMOD);
    wmb();

    /* Start it running */
    cr_writel(1, EM_DWC_PLDMND);
    wmb();

    return 0;
}


int export_em_reinit_idmac_pre(struct sd_cmd_pkt *cmd_info)
{
    return dw_em_reinit_idmac_pre(cmd_info);
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_reinit_idmac_post(struct sd_cmd_pkt *cmd_info)
{
    u32 temp;

    /* Disable and reset the IDMAC interface */
    temp = cr_readl(EM_DWC_CTRL);
    temp &= ~SDMMC_CTRL_USE_IDMAC;
    temp |= SDMMC_CTRL_DMA_RESET;
    cr_writel(temp, EM_DWC_CTRL);
    wmb();

    /* Stop the IDMAC running */
    temp = cr_readl(EM_DWC_BMOD);
    temp &= ~(SDMMC_IDMAC_ENABLE | SDMMC_IDMAC_FB);
    cr_writel(temp, EM_DWC_BMOD);
    wmb();

    return 0;
}

int export_em_reinit_idmac_post(struct sd_cmd_pkt *cmd_info){
    return dw_em_reinit_idmac_post(cmd_info);
}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_Stream(struct sd_cmd_pkt *cmd_info)
{
    int err=0;
    struct mmc_host *host;
    struct rtksd_host *sdport;
    struct scatterlist *sg;
    u32 dir = 0;
    int dma_nents = 0;

    host   = cmd_info->sdport->mmc;
    sdport = cmd_info->sdport;

    if(sdport->scrip_buf == NULL){
       /*
        * Scripter base is setting when srcipter buffer alloced.
        * check where is dw_em_set_scrip_base().
        */
        BUG_ON(1);
        return cmd_info->cmd->error = -ENOMEM;
    }

    if(cmd_info->data->flags & MMC_DATA_READ){
        dir = DMA_FROM_DEVICE;
    }else{
        dir = DMA_TO_DEVICE;
    }
    cmd_info->data->bytes_xfered=0;
    dma_nents = dma_map_sg( mmc_dev(host), cmd_info->data->sg,
            cmd_info->data->sg_len,  dir);
    sg = cmd_info->data->sg;

    if((dma_nents < 0) || (dma_nents > host->max_segs) ){
        WARN(1, "Unexpected scatter&gather case. dma_nents=%d\n",
                dma_nents);
        err = -ENOMEM;
        cmd_info->cmd->error = err;
        goto umap_err_out;
    }

    if(dw_em_get_occupy(sdport)){
        return cmd_info->cmd->error = -EIO;
    }

#define RE_INITIAL_IDMAC
#ifdef  RE_INITIAL_IDMAC
                /* Software reset of DMA */
    dw_em_reinit_idmac_pre(cmd_info);
#endif

    if(dw_em_sg_make_script(sg,dma_nents,cmd_info)){
        err = -ENOMEM;
        cmd_info->cmd->error = err;
        dw_em_release_occupy(sdport);
        goto umap_err_out;
    }

    if((cmd_info->scrip_cnt)>EMMC_MAX_SCRIPT_LINE ){
        WARN(1, "scrip length more then %d(%d)\n",
                EMMC_MAX_SCRIPT_LINE,cmd_info->scrip_cnt);
        err = -ENOMEM;
        cmd_info->cmd->error = err;
        dw_em_release_occupy(sdport);
        goto umap_err_out;
    }
    err = dw_em_Stream_Cmd(cmd_info);

#ifdef  RE_INITIAL_IDMAC
    dw_em_reinit_idmac_post(cmd_info);
#endif
    dw_em_release_occupy(sdport);
    if(err == 0){
        if(host->card){

            if( !(cmd_info->cmd_flag & SDMMC_CMD_SEND_STOP)
             && ( (cmd_info->cmd->opcode == 18)
               || (cmd_info->cmd->opcode == 25) ) )
            {
                if(dw_em_stop_transmission(sdport)){
                    /* if stop cmd error, set stop cmd error code, and skip bytes_xfered caculation */
                    err = -ETIMEDOUT;
                    cmd_info->stop->error = err;
                    goto umap_err_out;
                }
            }
        }
        cmd_info->data->bytes_xfered = cmd_info->total_byte_cnt;
        cmd_info->data->error = 0;
    }else{
        cmd_info->data->bytes_xfered = 0;
    }

umap_err_out:
    dma_unmap_sg( mmc_dev(host), cmd_info->data->sg,
            cmd_info->data->sg_len,  dir);

    return err;
}

/************************************************************************
 *
 ************************************************************************/
/* #define CHECK_CRC_ENABLE */
#if defined(CHECK_CRC_ENABLE)
void show_CRC_value(void)
{
    int i;
#define CRC_REG_BASE 0xb8010854
    for(i=0;i<2;i++){
        EM_ALERT("0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n",
            CRC_REG_BASE+(i*16)+0,  cr_readl(CRC_REG_BASE+(i*16)+0),
            CRC_REG_BASE+(i*16)+4,  cr_readl(CRC_REG_BASE+(i*16)+4),
            CRC_REG_BASE+(i*16)+8,  cr_readl(CRC_REG_BASE+(i*16)+8),
            CRC_REG_BASE+(i*16)+12, cr_readl(CRC_REG_BASE+(i*16)+12));
    }
}
#else
#define show_CRC_value()
#endif

/************************************************************************
 *
 ************************************************************************/
static
void rtkem_polling_tasklet(unsigned long param)
{
    u32 cmd_flag;
    struct rtksd_host *sdport;
    struct mmc_command *cmd;
    struct sd_cmd_pkt * cmd_info;
    u32  state;
    u32  prev_state = 0;
    unsigned int    wrap_sta0 = 0;
    bool err_flag = false;

    sdport = (struct rtksd_host *)param;
    spin_lock(&sdport->lock);

    state = sdport->task_state;

    /*
     * Note:
     *  At STATE_CMD_DONE state,
     *  the struct sd_cmd_pkt have been released.
     */
    cmd_info = sdport->cmd_info;
    if(cmd_info == NULL)
        WARN_ON(1);

    cmd = cmd_info->cmd;
    cmd_flag = cmd_info->cmd_flag;

    do {
        prev_state = state;

        switch (state) {
        case STATE_IDLE:
            break;

        case STATE_SENDING_DATA:
            sdport->int_status  = cr_readl(EM_DWC_RINTSTS);
            sdport->sd_trans    = cr_readl(EM_DWC_IDSTS);
            sdport->sd_status   = cr_readl(EM_DWC_STATUS);
            sdport->wrap_sta    = cr_readl(EM_INT_STATUS);
            wrap_sta0           = cr_readl(EM_WARP_STATUS0);

            if((sdport->int_status & SDMMC_INT_ERROR)) {
#define DW_EM_TIMEOUT   (SDMMC_INT_HTO|SDMMC_INT_DTO|SDMMC_INT_RTO)
#define DW_EM_RCRC_ERR  (SDMMC_INT_DCRC|SDMMC_INT_RCRC|SDMMC_INT_RESP_ERR)
#define DW_EM_RESP_ERR  (SDMMC_INT_RCRC|SDMMC_INT_RESP_ERR)

                if(sdport->int_status & DW_EM_RESP_ERR){
                    cmd_info->cmd->error = -EILSEQ;
                }else{
                    cmd_info->cmd->error = -ETIMEDOUT;
                }
                err_flag = true;
            }

            if(cmd_flag & SDMMC_CMD_DAT_EXP){
                if (sdport->sd_trans & IDMAC_INT_ERR) {
                    if(!err_flag){
                        err_flag = true;
                        cmd_info->cmd->error = -ETIMEDOUT;
                    }
                    cmd_info->data->error = -ETIMEDOUT;
                }

                if (sdport->int_status & SDMMC_INT_DATA_OVER) {
                    if(err_flag){
                        state = STATE_DATA_ERROR;
                        break;
                    }

                    if (cmd_flag & SDMMC_CMD_DAT_WR)
                    {
                        /* At write case, waitting card busy */
                        if(!(sdport->sd_status & SDMMC_DAT0_BUSY)){
                            if( !(sdport->sd_trans & (0x1f << 13))
                             && !(wrap_sta0 & _BIT1))
                            {
                                state = STATE_POST_POLLING;
                                break;
                            }else{
                                mmcinfo("wait FSM!!![0x%08x]\n",sdport->sd_trans);
                                show_int_sta(__func__,__LINE__,sdport,1);

                            }
                        }else{
                            mmcinfo("wait for card busy!!!\n");
                            show_int_sta(__func__,__LINE__,sdport,1);
                        }

                    }else{
                        if(sdport->wrap_sta & PS_DMA_WR_DONE_S){
                            /* At read case, waitting inner DDR done.
                               Read action is writting data to DDR.
                               that is why to use PS_DMA_WR_DONE_S */
                            if( !(sdport->sd_trans & (0x1f << 13))
                             && !(wrap_sta0 & _BIT0)
                             && !(wrap_sta0 & _BIT1) )
                            {
                                state = STATE_POST_POLLING;
                                break;
                            }else{
                                mmcinfo("wait FSM!!![0x%08x]\n",sdport->sd_trans);
                                show_int_sta(__func__,__LINE__,sdport,1);
                            }
                        }else{
                            mmcinfo("wait for DDR busy!!!(0x%08x)\n",sdport->wrap_sta);
                            show_int_sta(__func__,__LINE__,sdport,1);
                        }
                    }
                }
            } else {
                if (sdport->int_status & SDMMC_INT_CMD_DONE) {
                    if(err_flag){
                        state = STATE_DATA_ERROR;
                        break;
                    }
                    if (mmc_resp_type(cmd) & MMC_RSP_BUSY)
                    {
                        if(!(sdport->sd_status & SDMMC_DAT0_BUSY)){
                            state = STATE_POST_POLLING;
                            break;
                        }else{
                            mmcinfo("wait for card busy!!! [cmd%u]\n",
                                SDMMC_CMD_INDX(cmd_flag));
                        }
                    }else{
                    state = STATE_POST_POLLING;
                    break;
                }

                }
            }
            sdport->task_state = prev_state = state;
            tasklet_schedule(&sdport->polling_tasklet);
            break;
        case STATE_POST_POLLING:
            if(cr_readl(EM_DWC_CMD) & _BIT31){
                sdport->task_state = prev_state = state;
                tasklet_schedule(&sdport->polling_tasklet);
            }else{
                if((cmd_flag & SDMMC_CMD_DAT_EXP)
                && (cr_readl(EM_DWC_IDSTS) & (0x1f << 13))){
                    mmcmsg4("wait FSM!!![0x%08x]\n",sdport->sd_trans);
                    sdport->task_state = prev_state = state;
                    tasklet_schedule(&sdport->polling_tasklet);
                }else{
                    show_CRC_value();
                    cmd_info->cmd->error = 0;
                    state = STATE_DATA_COMPLETE;
                }
            }
            break;
        case STATE_DATA_ERROR:
            state = STATE_DATA_COMPLETE;
            break;
        case STATE_DATA_COMPLETE:
            prev_state = state = STATE_IDLE;
            del_timer(&sdport->timer);
#if 0
            /* disable and clear int */
            dw_em_clear_int_sta(1);
            dw_em_clear_int_sta_IDMA(1);
            dw_em_clear_int_wrap(1);
#endif
            rtk_op_complete(sdport);
            break;
        }
    } while (state != prev_state);

    sdport->task_state = state;
    spin_unlock(&sdport->lock);

}

/************************************************************************
 *
 ************************************************************************/
static
void rtkcr_req_end_tasklet(unsigned long param)
{
    struct rtksd_host *sdport;
    struct mmc_request* mrq;
    unsigned long flags;

    sdport = (struct rtksd_host *)param;
    spin_lock_irqsave(&sdport->lock,flags);

    mrq = sdport->mrq;
    sdport->mrq = NULL;

    spin_unlock_irqrestore(&sdport->lock, flags);
    mmc_request_done(sdport->mmc, mrq);
}

/************************************************************************
 *
 ************************************************************************/
static
void rtksd_send_command(struct rtksd_host *sdport, struct mmc_command *cmd)
{
    struct sd_cmd_pkt *cmd_info = NULL;

    if ( !sdport || !cmd ){
        EM_ERR( "%s: sdport or cmd is null\n", DRIVER_NAME);
        return ;
    }

    cmd_info = sdport->cmd_info;
    cmd_info->cmd    = sdport->mrq->cmd;
    cmd_info->stop   = sdport->mrq->stop;
    cmd_info->sdport = sdport;

    if (cmd->data){
        cmd_info->data = cmd->data;
        dw_em_Stream(cmd_info);

    }else{
        dw_em_SendCmd(cmd_info);
    }

    /* This is for mmc_fast_rw function. */
    if(cmd->opcode == MMC_SWITCH){
         if((cmd->arg & 0xffff00ff) == 0x03b30001) {
            if((cmd->arg & 0x0000ff00)==0){
                sdport->rtflags |= RTKCR_USER_PARTITION;
            }else{
                sdport->rtflags &= ~RTKCR_USER_PARTITION;
            }
         }
    }

    tasklet_schedule(&sdport->req_end_tasklet);
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_request(struct mmc_host *host, struct mmc_request *mrq)
{
    struct rtksd_host *sdport = NULL;
    struct mmc_command *cmd = NULL;
    struct sd_cmd_pkt *cmd_info = NULL;
    unsigned long flags;

    sdport = mmc_priv(host);
    BUG_ON(sdport->mrq != NULL);

    /*
     * The flag "rtk_emmc_raw_op" is for store log while kernel panic.
     * When this flag alert, skip all request come from system.
     */
    while(rtk_emmc_raw_op){
        EM_ERR("wait RAW func finish!!!!!!!!!!!!!!!!!!!\n");
        msleep(10);
    }

    /*
    Beware: only struct mmc_command malloc by rtk_self should be assigned to sdport->cmd.
    It's to identify which assigend by.
    */
    cmd_info = kmalloc(sizeof(struct sd_cmd_pkt), GFP_KERNEL);
    spin_lock_irqsave(&sdport->lock,flags);
    sdport->mrq = mrq;

    if(!cmd_info ){
        EM_ERR("request cmd_info memory fail\n");
        mrq->cmd->error = -ENOMEM;
        mrq->cmd->retries = 0;
        goto done;
    }
    memset(cmd_info, 0, sizeof(struct sd_cmd_pkt));

    cmd = mrq->cmd;
    cmd->error = -EINPROGRESS;
    if (cmd->data){
        cmd->data->error = -EINPROGRESS;
    }
    sdport->cmd_info = cmd_info;
    sdport->cmd = cmd;

    if (!(sdport->rtflags & RTKCR_FCARD_DETECTED)){
        cmd->error = -ENOMEDIUM;
        cmd->retries = 0;
        goto done;
    }

    if ( sdport && cmd ){
        spin_unlock_irqrestore(&sdport->lock, flags);
        rtksd_send_command(sdport, cmd);
    }else{
done:
        tasklet_schedule(&sdport->req_end_tasklet);
        spin_unlock_irqrestore(&sdport->lock, flags);

    }
    if(cmd_info)
        kfree(cmd_info);
}

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_hw_reset(struct mmc_host *host)
{
    struct rtksd_host *sdport;
    sdport = mmc_priv(host);

    if(dw_em_get_occupy(sdport)){
        return;
    }

    rtkem_clr_sta(sdport);
    sdport->ops->reset_card(sdport);
    sdport->ops->reset_host(sdport,1);

    dw_em_release_occupy(sdport);
}

/************************************************************************
 *
 ************************************************************************/
#define HS_52_DDR   (0x01)
#define HS_200_DDR  (0x01<<16)

static
void dw_em_set_ios(struct mmc_host *host, struct mmc_ios *ios)
{
    struct rtksd_host *sdport;
    u32 tmp_clock = 0;
    u32 tmp_bits = 0;
    u32 ctrl_DDR = 0;
    u32 driving = 0;

    sdport = mmc_priv(host);
    mmcmsg2("bus_mode  = %u\n",ios->bus_mode);
    mmcmsg2("clock     = %u\n",ios->clock);
    mmcmsg2("timing    = %u\n",ios->timing);
    mmcmsg2("bus_width = %u\n", ios->bus_width);

    sdport->ops->set_DDR = dw_em_set_DDR;

    driving = DRIVING_COMMON;

    if(dw_em_get_occupy(sdport)){
        return;
    }

    if (ios->bus_mode == MMC_BUSMODE_PUSHPULL){
        if (ios->bus_width == MMC_BUS_WIDTH_8){
            tmp_bits = MMC_BUS_WIDTH_8;
        }else if (ios->bus_width == MMC_BUS_WIDTH_4){
            tmp_bits = MMC_BUS_WIDTH_4;
        }else{
            tmp_bits = MMC_BUS_WIDTH_1;
        }

        tmp_clock = ios->clock;

        if (ios->timing == MMC_TIMING_MMC_HS400) {
            dw_em_set_ds_delay(sdport, sdport->cur_ds_tune);
            ctrl_DDR = (HS_52_DDR|HS_200_DDR);
            if (tmp_clock > CLK_200Mhz) {
                tmp_clock = CLK_200Mhz;
            }
            sdport->ops->set_DDR = dw_em_set_DDR400;
            driving = DRIVING_HS400;
        } else if (ios->timing == MMC_TIMING_MMC_HS200) {
            ctrl_DDR = 0;
            if (tmp_clock > CLK_200Mhz) {
                tmp_clock = CLK_200Mhz;
            }
            driving = DRIVING_HS200;
        } else if (ios->timing == MMC_TIMING_UHS_DDR50) {
            dw_em_dis_sd_tune(sdport);
            ctrl_DDR = HS_52_DDR;
            if(tmp_clock > CLK_50Mhz){
                tmp_clock = CLK_50Mhz;
            }
        } else if ((ios->timing == MMC_TIMING_SD_HS) ||
            (ios->timing == MMC_TIMING_MMC_HS)) {
            dw_em_dis_sd_tune(sdport);
            ctrl_DDR = 0;
            if(tmp_clock > CLK_50Mhz){
                tmp_clock = CLK_50Mhz;
            }
        } else {
            dw_em_dis_sd_tune(sdport);
            ctrl_DDR = 0;
            if(tmp_clock>CLK_25Mhz){
                tmp_clock = CLK_25Mhz;
            }
        }

    } else {
        /* MMC_BUSMODE_OPENDRAIN */
        tmp_clock = CLK_200Khz;
        tmp_bits = MMC_BUS_WIDTH_1;
        ctrl_DDR = 0;

    }

    sdport->ops->set_IO_driving(sdport,driving);
    sdport->ops->set_DDR(sdport, ctrl_DDR);
    sdport->ops->set_bits(sdport, tmp_bits);
    sdport->ops->set_clk(sdport,tmp_clock);

    /* eMMC Power control */
    switch (ios->power_mode) {
    case MMC_POWER_UP:
        cr_writel(_BIT0, EM_DWC_PWREN);
        break;
    case MMC_POWER_OFF:
        /* Power down slot */
        /* record ds_tune for STR flow */
        sdport->cur_ds_tune = cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f;
        cr_writel(0, EM_DWC_PWREN);
        break;
    default:
        break;
    }

    dw_em_release_occupy(sdport);

}

/************************************************************************
 *
 ************************************************************************/
static
void rtkem_chk_card_insert(struct rtksd_host *sdport)
{
    struct mmc_host *host=sdport->mmc;

    /* setting HW  */

    /* enable PLL of eMMC */
    dw_em_set_PLL_clk(sdport,CLK_50Mhz,0,1);

    /* set emmc pin mux */
    if(sdport->ops->set_crt_muxpad)
        sdport->ops->set_crt_muxpad(sdport);

    sdport->ops->reset_host(sdport,0);
    sdport->ops->set_IO_driving(sdport,DRIVING_COMMON);
    sdport->ops->set_clk(sdport,CLK_200Khz);
    dw_em_init_phase(sdport,DEFAULT_W_PHASE,DEFAULT_R_PHASE,DEFAULT_C_PHASE); /* w_phase;r_phase */
    sdport->ops->set_bits(sdport, MMC_BUS_WIDTH_1);
    /* move reset card to dw_em_hw_reset() to support re-initial flow. */

    host->card_type_pre = CR_EM;    /* default flow is sd */
    host->ops = &rtkemmc_ops;
    sdport->rtflags |= RTKCR_FCARD_DETECTED;
    //sdport->ins_event |= EVENT_SKIP_DSTUNING;
}

/************************************************************************
 *
 ************************************************************************/
static
void rtksd_timeout_timer(unsigned long data)
{
    struct rtksd_host *sdport = NULL;
    struct mmc_command *cmd = NULL;

    u32 int_status = 0;
    u32 int_status_m = 0;
    u32 sd_trans = 0;
    u32 sd_status = 0;
    u32 wrap_sta = 0;
    unsigned long flags;
    sdport = (struct rtksd_host *)data;
    cmd = sdport->cmd;

    spin_lock_irqsave(&sdport->lock,flags);

    if(sdport->int_waiting){

        int_status   = cr_readl(EM_DWC_RINTSTS);
        int_status_m = cr_readl(EM_DWC_MINTSTS);
        sd_trans     = cr_readl(EM_DWC_IDSTS);
        sd_status    = cr_readl(EM_DWC_STATUS);
        wrap_sta     = cr_readl(EM_INT_STATUS);
        /* disable and clear int */
        dw_em_clear_int_sta(1);
        dw_em_clear_int_sta_IDMA(1);
        dw_em_clear_int_wrap(1);

        sdport->int_status  = (int_status & 0xffff) | (int_status_m<<16);
        sdport->sd_trans    = sd_trans;
        sdport->sd_status   = sd_status;
        sdport->wrap_sta    = wrap_sta;
    }else{
        WARN_ON(1);
    }

    cmd->error =  -ETIMEDOUT;
    if(cmd->data){
        cmd->data->error = -ETIMEDOUT;
    }
    sdport->task_state = STATE_DATA_ERROR;
    tasklet_schedule(&sdport->polling_tasklet);
    spin_unlock_irqrestore(&sdport->lock, flags);

    if((!(sdport->rtflags & RTKCR_TUNING_STATE))
     ||(sdport->rtflags & RTKCR_FOPEN_LOG))
        EM_INFO( "%s:  card access time out!\n",DRIVER_NAME);

}

/************************************************************************
 *
 ************************************************************************/
#ifdef EMMC_SHOUTDOWN_PROTECT
static
void rtksd_gpio_isr(VENUS_GPIO_ID gid, unsigned char assert, void *dev)
{
    struct rtksd_host *sdport = dev;
    u32 reg_tmp;
    u32 bit_tmp;
    u32 reginfo;
    u32 invert;
    unsigned char assert_tmp;

    reginfo = (u32)GET_PIN_TYPE(sdport->gpio_isr_info);
    bit_tmp = (u32)GET_PIN_INDEX(sdport->gpio_isr_info);
    invert  = (u32)GET_GPIO_INVERT(sdport->gpio_isr_info);

    reg_tmp = ((bit_tmp & 0xffffffe0)>>5)<<2;
    bit_tmp = (bit_tmp & 0x1fUL);

    switch(reginfo){
        case PCB_PIN_TYPE_GPIO:
            reg_tmp += MIS_GPDATI_BASE;
            break;
        case PCB_PIN_TYPE_ISO_GPIO:
            reg_tmp += ISO_GPDATI_BASE;
            break;
        default:
        EM_INFO( "PIN group not match\n");
            WARN_ON(1);
            return;
    }

    reginfo = cr_readl(reg_tmp);

    assert_tmp =
        (unsigned char)((reginfo & (0x01UL << bit_tmp)) >> bit_tmp);

    /* In here, need to make sure the level of GPIO if high or low. */
    if(invert)
        invert = 0;
    else
        invert = (0x01UL <<bit_tmp);

    if ((reginfo & (0x01UL << bit_tmp)) == invert) {

        local_irq_disable();
        preempt_disable();

        /* disable Watchdog 0xB801B6F0 */
        /* regval = cr_readl(0xB801B6F0) & ~0xFF; */
        /* cr_writel(regval | 0xa5, 0xB801B6F0); */

        rtkem_hold_card(sdport);

        EM_NOTICE( "%s(%u)eMMC have locked on!!!\n",
            __func__,__LINE__);

        /* cr_writel(0x04000000, 0xb801B6FC); // set 2.4 sec */
        /* cr_writel(cr_readl(0xb801B6F0) & ~0xFF, 0xb801B6F0); // enable Watchdog */
        while(1);
    }
}
#endif

/************************************************************************
 *
 ************************************************************************/
static
void dw_em_chk_shoutdown_protect(struct rtksd_host *sdport)
{
#ifdef EMMC_SHOUTDOWN_PROTECT
    /* note: AC detect pin is iso_gpio_36 on 296x*/
    u64 rtk_tmp_gpio;

    /* #define FAKE_AC_DET_PIN */
#ifdef FAKE_AC_DET_PIN
    /* for reference POWER_EN  0x101010c04 */
    if(pcb_mgr_get_enum_info_byname("POWER_EN", &rtk_tmp_gpio)==0)
#else
    if(pcb_mgr_get_enum_info_byname("PIN_AC_DETECT", &rtk_tmp_gpio)==0)
#endif
    {
        u32 gpio_group;
        u32 rtk_gpio_num;
        set_gpio_func_t gpio_func;

        EM_NOTICE("PIN_AC_DETECT got.(0x%x)\n", (u32) rtk_tmp_gpio);

        gpio_group      = GET_PIN_TYPE(rtk_tmp_gpio);
        rtk_gpio_num    = GET_PIN_INDEX(rtk_tmp_gpio);

#ifdef FAKE_AC_DET_PIN
        EM_ERR("gpio_group = %x\n", gpio_group);
        EM_ERR("rtk_gpio_num = %x\n", rtk_gpio_num);

        /* Has 296x board AC detect pin? */
        rtk_tmp_gpio    = 0x0015303;
        gpio_group      = GET_PIN_TYPE(rtk_tmp_gpio);
        rtk_gpio_num    = GET_PIN_INDEX(rtk_tmp_gpio);
        EM_ERR("\nfor test change PIN_AC_DETECT to 0x%08llx.\n",
               rtk_tmp_gpio);
        EM_ERR("gpio_group = %x\n", gpio_group);
        EM_ERR("rtk_gpio_num = %x\n", rtk_gpio_num);
#endif
        sdport->gpio_isr_info = (u32)rtk_tmp_gpio;

        switch(gpio_group){
        case PCB_PIN_TYPE_GPIO:
            EM_INFO("PIN type is PCB_PIN_TYPE_GPIO\n");
            if (rtk_gpio_num > MAX_MIS_GPIO_CNT) {
                EM_INFO
                    ("Error Pin define,Skip AC_DET function\n");
                goto AC_DET_OUT;
            }
            gpio_group = MIS_GPIO;
            gpio_func = rtkcr_set_mis_gpio;
            break;
        case PCB_PIN_TYPE_ISO_GPIO:
            EM_INFO("PIN type is PCB_PIN_TYPE_ISO_GPIO\n");
            if(iso_gpio_mux_tbl[rtk_gpio_num][0] == 0xff ||
                rtk_gpio_num > MAX_ISO_GPIO_CNT) {
                EM_INFO
                    ("Error Pin define,Skip AC_DET function\n");
                goto AC_DET_OUT;
            }
            gpio_group = ISO_GPIO;
            gpio_func = rtkcr_set_iso_gpio;
            break;
        default:
            EM_INFO("PIN group not match\n");
            goto AC_DET_OUT;

        }

        EM_INFO("PIN_AC_DETECT is %s_GPIO %u.\n",
                    gpio_group==ISO_GPIO? "ISO":"MIS",rtk_gpio_num);

        gpio_func(rtk_gpio_num,DIR_IN|GPIO_L);
        venus_gpio_set_debounce(venus_gpio_id(gpio_group, rtk_gpio_num), VENUS_GPIO_DEBOUNCE_10ms);
        venus_gpio_set_dir(venus_gpio_id(gpio_group, rtk_gpio_num), 0);
        venus_gpio_clear_isr(venus_gpio_id(gpio_group, rtk_gpio_num));
        if (venus_gpio_request_irq
            (venus_gpio_id(gpio_group, rtk_gpio_num), rtksd_gpio_isr,
             DRIVER_NAME, sdport)) {
            EM_INFO("%s: request gpio isr fail\n", DRIVER_NAME);
            goto AC_DET_OUT;
        }
        venus_gpio_set_irq_enable(venus_gpio_id
                      (gpio_group, rtk_gpio_num), 1);

    }

AC_DET_OUT:
    return;

#else //? #ifdef EMMC_SHOUTDOWN_PROTECT
    EM_NOTICE( "%s: EMMC_SHOUTDOWN_PROTECT not define\n",
            DRIVER_NAME);

#ifdef EMMC_SHOUTDOWN_PROTECT_FAIL
    EM_NOTICE("%s: Lost config CONFIG_REALTEK_PCBMGR or CONFIG_REALTEK_GPIO, Please check! \n",
            DRIVER_NAME);
#endif

#endif  //? #ifdef EMMC_SHOUTDOWN_PROTECT
}

/************************************************************************
 *
 ************************************************************************/
static
irqreturn_t dw_em_irq(int irq, void *dev)
{
    struct rtksd_host *sdport = dev;

    int irq_handled = 0;

    u32 int_status = 0;
    u32 int_status_m = 0;
    u32 sd_trans = 0;
    u32 sd_status = 0;
    u32 wrap_sta = 0;

    if(sdport->reset_event){
        EM_ERR("%s: sd clock off at reset process, no interrupt service\n",
                DRIVER_NAME);

/* #define SHOW_CRT_CLK_INFO*/
#ifdef SHOW_CRT_CLK_INFO
        {
        u32 reginfo = 0;

        reginfo = scrt_readl(RTK_EM_DW_CLKEN);
        EM_ERR("%s: RTK_EM_CLKEN=0x%08x\n",
                DRIVER_NAME,reginfo);
        }
#endif
    }else{
        int_status   = cr_readl(EM_DWC_RINTSTS);
        int_status_m = cr_readl(EM_DWC_MINTSTS);
        sd_trans     = cr_readl(EM_DWC_IDSTS);
        sd_status    = cr_readl(EM_DWC_STATUS);
        wrap_sta     = cr_readl(EM_INT_STATUS);
    }

    spin_lock(&sdport->lock);

    if(int_status_m & cr_readl(EM_DWC_INTMASK)){
        //cr_writel(~int_status,EM_DWC_INTMASK);
        cr_writel(int_status,EM_DWC_RINTSTS);
        irq_handled |= _BIT0;
    }

    if(sd_trans & cr_readl(EM_DWC_IDINTEN)){
        //cr_writel(~sd_trans,EM_DWC_IDINTEN);
        cr_writel(sd_trans,EM_DWC_IDSTS);
        irq_handled |= _BIT1;
    }

    if(wrap_sta & ~(cr_readl(EM_INT_MASK))){
        //cr_writel(wrap_sta,EM_INT_MASK);
        cr_writel(wrap_sta,EM_INT_STATUS);
        irq_handled |= _BIT2;
    }

    if(irq_handled){
        /* disable and clear int */
        //dw_em_clear_int_sta(1);
        //dw_em_clear_int_sta_IDMA(1);
        //dw_em_clear_int_wrap(1);

        sdport->int_status  = (int_status & 0xffff) | (int_status_m<<16);
        sdport->sd_trans    = sd_trans;
        sdport->sd_status   = sd_status;
        sdport->wrap_sta    = wrap_sta;

        if(sdport->int_waiting){

            sdport->task_state = STATE_POST_POLLING;
            tasklet_schedule(&sdport->polling_tasklet);
        }else{
            EM_ERR("\n"
                "%s: No int_waiting!!!(0x%02x)\n"
                "   INT_STATUS=0x%08x RINTSTS=0x%08x\n"
                "   IDSTS=0x%08x STATUS=0x%08x\n",
                DRIVER_NAME,irq_handled,
                wrap_sta,int_status,sd_trans,sd_status);
/*
                wrap_sta     = cr_readl(EM_INT_STATUS);
                int_status   = cr_readl(EM_DWC_RINTSTS);
                int_status_m = cr_readl(EM_DWC_MINTSTS);
                sd_trans     = cr_readl(EM_DWC_IDSTS);
                sd_status    = cr_readl(EM_DWC_STATUS);
*/

        }
    }

    spin_unlock(&sdport->lock);

    if(irq_handled)
        return IRQ_HANDLED;
    else
        return IRQ_NONE;

}

/************************************************************************
 * check read only func
 ************************************************************************/
static
int dw_em_get_ro(struct mmc_host *mmc)
{
#if 0
    struct rtksd_host *sdport = mmc_priv(mmc);
    struct mmc_card *card = mmc->card;
#endif

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
int rtksd_switch_user_partition(struct mmc_card *card)
{
    struct mmc_command *cmd;
    struct sd_cmd_pkt *cmd_info;
    struct rtksd_host *sdport;
    int err = 0;

    sdport = mmc_priv(card->host);

    cmd = kmalloc(sizeof(struct mmc_command), GFP_KERNEL);
    cmd_info = kmalloc(sizeof(struct sd_cmd_pkt), GFP_KERNEL);
    sdport->cmd = cmd;

    memset(cmd, 0, sizeof(struct mmc_command));
    memset(cmd_info, 0, sizeof(struct sd_cmd_pkt));

    set_cmd_info(sdport,cmd,cmd_info,
             MMC_SWITCH, 0x03b30001, (MMC_CMD_AC | MMC_RSP_R1B));
    err = dw_em_SendCmd(cmd_info);

    kfree(cmd);
    kfree(cmd_info);
    if(err){
        EM_WARNING( "%s: MMC_SWITCH fail\n", DRIVER_NAME);
    }
    return err;

}

/************************************************************************
 *
 ************************************************************************/
#ifdef CONFIG_MMC_RTKEMMC_HK_ATTR

#define NORMAL_PART 0
#define BOOT1_PART  1
#define BOOT2_PART  2
#define GP1_PART    3
#define GP2_PART    4
#define GP3_PART    5
#define GP4_PART    6

#if 0
static int rtksd_switch_partition(struct rtksd_host *sdport,u8 acc_part)
{
    struct mmc_command *cmd;
    struct sd_cmd_pkt *cmd_info;
    int err;

    cmd = kmalloc(sizeof(struct mmc_command), GFP_KERNEL);
    cmd_info = kmalloc(sizeof(struct sd_cmd_pkt), GFP_KERNEL);
    sdport->cmd = cmd;

    memset(cmd, 0, sizeof(struct mmc_command));
    memset(cmd_info, 0, sizeof(struct sd_cmd_pkt));

    /* set_cmd_info() */
    cmd->opcode         = MMC_SWITCH;
    cmd->arg            = 0x03b30001 | (acc_part << 8);
    cmd->flags          = (MMC_CMD_AC | MMC_RSP_R1B);
    cmd_info->cmd       = cmd;
    cmd_info->sdport    = sdport;
    sdport->cmd_info    = cmd_info;

    err = dw_em_SendCmd(cmd_info);

    kfree(cmd);
    kfree(cmd_info);

    if(err){
        EM_WARNING( "%s: MMC_SWITCH fail\n", DRIVER_NAME);
    }
    return err;

}
#endif

/************************************************************************
 *
 ************************************************************************/
static int rtksd_switch(struct mmc_card *card,
            u8 acc_mod, u8 index, u8 value, u8 cmd_set)
{
    struct mmc_command *cmd;
    struct sd_cmd_pkt *cmd_info;
    struct rtksd_host *sdport;
    u32 arg = 0;
    int err = 0;

    sdport = mmc_priv(card->host);

    cmd = kmalloc(sizeof(struct mmc_command), GFP_KERNEL);
    cmd_info = kmalloc(sizeof(struct sd_cmd_pkt), GFP_KERNEL);
    sdport->cmd = cmd;

    memset(cmd, 0, sizeof(struct mmc_command));
    memset(cmd_info, 0, sizeof(struct sd_cmd_pkt));

    arg = (acc_mod << 24) | (index << 16) | (value << 8) | (cmd_set);

    EM_INFO("arg=0x%08x\n", arg);
    set_cmd_info(sdport,cmd,cmd_info,
             MMC_SWITCH, arg, (MMC_CMD_AC | MMC_RSP_R1B));

    err = dw_em_SendCmd(cmd_info);

    kfree(cmd);
    kfree(cmd_info);

    if(err){
        EM_WARNING( "%s: MMC_SWITCH fail\n", DRIVER_NAME);
    }
    return err;

}
#endif

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_stop_transmission(struct rtksd_host *sdport)
{
    struct mmc_command *cmd;
    struct sd_cmd_pkt *cmd_info;
    int err = 0;

    cmd = kmalloc(sizeof(struct mmc_command), GFP_KERNEL);
    cmd_info = kmalloc(sizeof(struct sd_cmd_pkt), GFP_KERNEL);
    sdport->cmd = cmd;

    memset(cmd, 0, sizeof(struct mmc_command));
    memset(cmd_info, 0, sizeof(struct sd_cmd_pkt));
    /*
        cmd12 : R1 for read
                R1b for write
    */

    set_cmd_info(sdport,cmd,cmd_info,
             MMC_STOP_TRANSMISSION, 0x00, (MMC_RSP_R1B | MMC_CMD_AC));
    err = dw_em_SendCmd(cmd_info);

    kfree(cmd);
    kfree(cmd_info);

    if(err){
        EM_WARNING( "%s: MMC_STOP_TRANSMISSION fail\n",
            DRIVER_NAME);
    }
    return err;

}

/************************************************************************
 *
 ************************************************************************/
static
void set_cmd_info(struct rtksd_host *sdport,struct mmc_command * cmd,
          struct sd_cmd_pkt *cmd_info, u32 opcode, u32 arg,
          u32 rsp_para)
{
    memset(cmd, 0, sizeof(struct mmc_command));
    memset(cmd_info, 0, sizeof(struct sd_cmd_pkt));

    cmd->opcode         = opcode;
    cmd->arg            = arg;
    cmd->flags          = rsp_para;
    cmd_info->cmd       = cmd;
    cmd_info->sdport    = sdport;
    sdport->cmd_info    = cmd_info;

}

/************************************************************************
 * For reference
 *
 * 4Bits Pattern
 * [000]=ff [001]=0f [002]=ff [003]=00 [004]=ff [005]=cc [006]=c3 [007]=cc
 * [008]=c3 [009]=3c [010]=cc [011]=ff [012]=fe [013]=ff [014]=fe [015]=ef
 * [016]=ff [017]=df [018]=ff [019]=dd [020]=ff [021]=fb [022]=ff [023]=fb
 * [024]=bf [025]=ff [026]=7f [027]=ff [028]=77 [029]=f7 [030]=bd [031]=ef
 * [032]=ff [033]=f0 [034]=ff [035]=f0 [036]=0f [037]=fc [038]=cc [039]=3c
 * [040]=cc [041]=33 [042]=cc [043]=cf [044]=ff [045]=ef [046]=ff [047]=ee
 * [048]=ff [049]=fd [050]=ff [051]=fd [052]=df [053]=ff [054]=bf [055]=ff
 * [056]=bb [057]=ff [058]=f7 [059]=ff [060]=f7 [061]=7f [062]=7b [063]=de
 *
 * =======================================================================
 * 8Bits Pattern
 * [000]=ff [001]=ff [002]=00 [003]=ff [004]=ff [005]=ff [006]=00 [007]=00
 * [008]=ff [009]=ff [010]=cc [011]=cc [012]=cc [013]=33 [014]=cc [015]=cc
 * [016]=cc [017]=33 [018]=33 [019]=cc [020]=cc [021]=cc [022]=ff [023]=ff
 * [024]=ff [025]=ee [026]=ff [027]=ff [028]=ff [029]=ee [030]=ee [031]=ff
 * [032]=ff [033]=ff [034]=dd [035]=ff [036]=ff [037]=ff [038]=dd [039]=dd
 * [040]=ff [041]=ff [042]=ff [043]=bb [044]=ff [045]=ff [046]=ff [047]=bb
 * [048]=bb [049]=ff [050]=ff [051]=ff [052]=77 [053]=ff [054]=ff [055]=ff
 * [056]=77 [057]=77 [058]=ff [059]=77 [060]=bb [061]=dd [062]=ee [063]=ff
 * [064]=ff [065]=ff [066]=ff [067]=00 [068]=ff [069]=ff [070]=ff [071]=00
 * [072]=00 [073]=ff [074]=ff [075]=cc [076]=cc [077]=cc [078]=33 [079]=cc
 * [080]=cc [081]=cc [082]=33 [083]=33 [084]=cc [085]=cc [086]=cc [087]=ff
 * [088]=ff [089]=ff [090]=ee [091]=ff [092]=ff [093]=ff [094]=ee [095]=ee
 * [096]=ff [097]=ff [098]=ff [099]=dd [100]=ff [101]=ff [102]=ff [103]=dd
 * [104]=dd [105]=ff [106]=ff [107]=ff [108]=bb [109]=ff [110]=ff [111]=ff
 * [112]=bb [113]=bb [114]=ff [115]=ff [116]=ff [117]=77 [118]=ff [119]=ff
 * [120]=ff [121]=77 [122]=77 [123]=ff [124]=77 [125]=bb [126]=dd [127]=ee
 *
 ************************************************************************/
#define TUNING_BLK_CNT      1
#define TUNING_WRITE_FLAG   _BIT31
#define TUNING_SKIP_FLAG    _BIT30
#define TUNING_HS400        _BIT29
#define TUNING_DIR_UP       _BIT28
#define TUNING_SKIP_ALL     _BIT27
#define TUNING_BLK_SHT      6
#define TUNING_CMD_MASK     (0x3fUL)            /* bit0~bit5 */
#define TUNING_BLK_MASK     (0xfUL << TUNING_BLK_SHT)   /* bit6~bit9 */
#define TUNING_TPHASE_SHT   6
#define TUNING_TPHASE_MASK  (0x3fUL << TUNING_TPHASE_SHT)   /* bit6~bit11 */
#define GET_TUNING_CMD(opcode)  (opcode & TUNING_CMD_MASK)
#define GET_TUNING_BLK(opcode)  ((opcode & TUNING_BLK_MASK) >> TUNING_BLK_SHT)
#define GET_TPHASE(opcode)  ((opcode & TUNING_TPHASE_MASK) >> TUNING_TPHASE_SHT)
#define TUNING_BLK_ADR      0x80 /* At write case, this address should be careful to erase data on eMMC */

/* #define CHECK_PATTERN_SELF */
#ifdef CHECK_PATTERN_SELF
/*
keep these struct and function for debug if needed
*/
static const unsigned char pattern_blk[64] = {
    0xff, 0x0f, 0xff, 0x00, 0xff, 0xcc, 0xc3, 0xcc,
    0xc3, 0x3c, 0xcc, 0xff, 0xfe, 0xff, 0xfe, 0xef,
    0xff, 0xdf, 0xff, 0xdd, 0xff, 0xfb, 0xff, 0xfb,
    0xbf, 0xff, 0x7f, 0xff, 0x77, 0xf7, 0xbd, 0xef,
    0xff, 0xf0, 0xff, 0xf0, 0x0f, 0xfc, 0xcc, 0x3c,
    0xcc, 0x33, 0xcc, 0xcf, 0xff, 0xef, 0xff, 0xee,
    0xff, 0xfd, 0xff, 0xfd, 0xdf, 0xff, 0xbf, 0xff,
    0xbb, 0xff, 0xf7, 0xff, 0xf7, 0x7f, 0x7b, 0xde,

};

/************************************************************************
 *
 ************************************************************************/
static int dw_em_chk_pattern(struct rtksd_host *sdport,u8 *data)
{
    int i;
    int err = 0;

    if(sdport->cur_width == 8)
    {
        unsigned char nb1 = 0;
        unsigned char nb2 = 0;

        mmcmsg2("%dbits pattern check\n",sdport->cur_width);
        for(i=0; i<64; i++){
            nb1 = (pattern_blk[i] & 0xf0) >> 4;
            nb1 = (nb1<<4)|nb1;
            nb2 = (pattern_blk[i] & 0xf);
            nb2 = (nb2<<4)|nb2;

            if((data[i*2] != nb1) || (data[(i*2)+1] != nb2)){
                mmcmsg2("nb1=0x%x nb2=0x%x \n",nb1,nb2);
                mmcmsg2("data[%x]=0x%x data[%x]=0x%x \n",
                    i,data[i*2],i+1,data[(i*2)+1]);
                err = -1;
                break;
            }
        }

    } else {
        mmcmsg2("%dbits pattern check\n",sdport->cur_width);
        for(i=0; i<64; i++){
            if(data[i] != pattern_blk[i]){
                mmcmsg2("data[%x]=0x%x pattern_blk[%x]=0x%x \n",
                    i,data[i],i,pattern_blk[i]);
                err = -1;
                break;
            }
        }
    }

    return err;
}

#endif

/************************************************************************
 *
 ************************************************************************/
static void rtkem_show_tuning_result(struct rtksd_host *sdport, u8* p,char* reason)
{
    EM_INFO("%s\n"
    "        {00-31}[%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d% d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d]\n"
    "        {32-63}[%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d% d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d]\n",
        reason,
        p[ 0],p[ 1],p[ 2],p[ 3],p[ 4],p[ 5],p[ 6],p[ 7],
        p[ 8],p[ 9],p[10],p[11],p[12],p[13],p[14],p[15],
        p[16],p[17],p[18],p[19],p[20],p[21],p[22],p[23],
        p[24],p[25],p[26],p[27],p[28],p[29],p[30],p[31],
        p[32],p[33],p[34],p[35],p[36],p[37],p[38],p[39],
        p[40],p[41],p[42],p[43],p[44],p[45],p[46],p[47],
        p[48],p[49],p[50],p[51],p[52],p[53],p[54],p[55],
        p[56],p[57],p[58],p[59],p[60],p[61],p[62],p[63]);
}

static void rtkem_show_ds_tune_result(struct rtksd_host *sdport, u8* p,char* reason)
{
    EM_INFO("%s\n"
    "        {00-31}[%d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d% d%d%d%d %d%d%d%d %d%d%d%d %d%d%d%d]\n",
        reason,
        p[ 0],p[ 1],p[ 2],p[ 3],p[ 4],p[ 5],p[ 6],p[ 7],
        p[ 8],p[ 9],p[10],p[11],p[12],p[13],p[14],p[15],
        p[16],p[17],p[18],p[19],p[20],p[21],p[22],p[23],
        p[24],p[25],p[26],p[27],p[28],p[29],p[30],p[31]);
}
/************************************************************************
 *
 * We found at some phase, 61 currently, will access fail always,
 * for max vaild continuousily phase range, skip the odd point
 * if final phase hit odd point, shift it.
 *
 ************************************************************************/
#define ODD_POINT   (61)
#define ODD_POINT_LVL   (6)
#define ODD_POINT_THR   (4)
#define ODD_POINT_THR_L (ODD_POINT-ODD_POINT_THR)
#define ODD_POINT_THR_H (ODD_POINT+ODD_POINT_THR)

static int rtkem_chk_odd_point(struct rtksd_host *sdport, u8* p)
{
#ifdef SKIP_ODD_POINT
    int i;
    int last_p = 0;
    int odd_cnt = 0;
    int odd_min = 0;
    int bp = 0;
    EM_INFO("check Odd point, phase %d\n",ODD_POINT);

    do{
        for (i=0; i<MAX_TUNING_STEP; i++) {
            last_p = i+1;
            if(last_p >= MAX_TUNING_STEP)
                last_p -= MAX_TUNING_STEP;
            if(p[i] == 1 && p[last_p] == 0 )
                odd_cnt += 1;
        }

        if(odd_cnt == 1){
            /* only one break area, skip odd point check */
            break;
        }

        EM_INFO("ODD_POINT_THR_L=%d ODD_POINT_THR_H=%d\n",
            ODD_POINT_THR_L,ODD_POINT_THR_H);

        odd_cnt = 0;
        odd_min = 0;
        last_p = (ODD_POINT_THR_L-1);
        for (i = ODD_POINT_THR_L; i< (ODD_POINT_THR_L+(ODD_POINT_LVL*2)); i++) {
            bp = i;
            if(bp >= MAX_TUNING_STEP)
                bp -= 64;

            if(p[bp] == 0 && p[last_p] == 1 )
                odd_min = bp;
            if((odd_min) && (p[bp] == 0))
                odd_cnt+=1;

            last_p = bp;
            //EM_INFO("i=%d bp=%d odd_min=%d odd_cnt=%d\n",
            //  i,bp,odd_min,odd_cnt);
        }
        EM_INFO("odd_min=%d odd_cnt=%d\n",odd_min,odd_cnt);

        if(odd_cnt && (odd_cnt<ODD_POINT_LVL)){
            EM_INFO("Match Odd point judgement\n");
            /* if fail point samll then 6, skip it */
            for (i = odd_min; i < (odd_min+odd_cnt); i++) {
                bp = i;
                if(bp >= MAX_TUNING_STEP)
                    bp -= 64;
                p[bp] = 1;
                //EM_INFO("i=%d bp=%d odd_min=%d odd_cnt=%d\n",
                //  i,bp,odd_min,odd_cnt);
                EM_INFO("Skip phase %d\n",bp);
            }
        }
    }while(0);

    return 0;
#else
    return 0;
#endif
}

/************************************************************************
 *
 ************************************************************************/
static int dw_em_simple_tuning(struct mmc_host *mmc, u32 ctl)
{
    struct rtksd_host *sdport;
    int i, j;
    u32 tmp_phase = 0;
    u32 cur_phase = 0;
    u32 phase_sht = 0;
    u32 phase_mask = 0;
    u32 min_p = 0;
    u32 max_p = 0;
    u32 phase_diff = 0;
    u32 tune_cmd = 0;
    u8 w_flag = 0;
    u8 p[64] = {0};
    int cmd_error = 0;
    int err = 0;

    sdport = mmc_priv(mmc);
    mmcmsg3( "cur bus width %d\n", sdport->cur_width );

    tune_cmd = GET_TUNING_CMD(ctl);

    if(ctl & TUNING_WRITE_FLAG)
        w_flag = 1;

    if(w_flag) {
        phase_sht = PHASE_W_SHT;
        phase_mask = PHASE_W_MASK;
    } else {
        phase_sht = PHASE_R_SHT;
        phase_mask = PHASE_R_MASK;
    }

    /* tuining start */
    mmcmsg3("PHASE_REG(0x%08x)=0x%08x\n",
        EMMC_PLLPHASE_CTRL, cr_readl(EMMC_PLLPHASE_CTRL));
    cur_phase = (cr_readl(EMMC_PLLPHASE_CTRL)>>phase_sht) & phase_mask;
    mmcmsg3("initial %s phase=%u(0x%x)\n",(w_flag)?"write":"read",cur_phase, cur_phase);
#define SCAN_LOW_TO_HIGH
#ifdef  SCAN_LOW_TO_HIGH
    for (i=0; i < MAX_TUNING_STEP; i++) {
#else
    i = MAX_TUNING_STEP;
    while(i--){
#endif
        tmp_phase = i;
        mmcmsg3( "tmp %s phase is %u(0x%x)\n",(w_flag)?"write":"read",tmp_phase,tmp_phase);

        if(!(ctl & TUNING_SKIP_FLAG))
            cr_maskl(EMMC_PLLPHASE_CTRL,phase_mask,phase_sht ,tmp_phase);

        sdport->rtflags |= RTKCR_TUNING_STATE;

        if(w_flag)
            mdelay(2);

        err = mmc_send_tuning(mmc, tune_cmd, &cmd_error);

        sdport->rtflags &= ~RTKCR_TUNING_STATE;

        if(cmd_error)
            mmcmsg3("tuning cmd fail!(phase %d)\n",i);

        if (!err){
            p[i] = true;
        }
    }

    if(!(ctl & TUNING_SKIP_FLAG)){
        rtkem_show_tuning_result(sdport,p,"tuning result: ");
        rtkem_chk_odd_point(sdport,p);
    }

    /*rtkem_show_tuning_result(sdport,p,"odd fix result: ");*/

    /* find longest good phase circumference */
    for (i=0; i<MAX_TUNING_STEP; i++) {
        int circum = 0;

        for (j=i; j < i+MAX_TUNING_STEP; j++) {
            int convert_j =  (j >= MAX_TUNING_STEP)?
                (j-MAX_TUNING_STEP) : j;
            if (p[convert_j])
                circum++;
            else
                break;
        }

        if (circum > phase_diff) {
            phase_diff = circum;
            min_p = i;
        }
    }

    if (phase_diff < 8) {
        err = -EIO;
        EM_NOTICE("good range too small,roll back to original phase %d(0x%x)\n",
            cur_phase,cur_phase);

        tmp_phase = cur_phase;
        cr_maskl(EMMC_PLLPHASE_CTRL,phase_mask,phase_sht ,tmp_phase);
    }else{
        err = 0;

        if (ctl & TUNING_SKIP_FLAG) {
            EM_NOTICE("skip tuning!!!,keep original phase %d(0x%x)\n",
                cur_phase,cur_phase);

            /* keep sdport->cur_w_phase;cur_w_ph400;cur_r_phase same */
            //tmp_phase = cur_phase;
            //cr_maskl(EMMC_PLLPHASE_CTRL,phase_mask,phase_sht ,tmp_phase);
        }else{
            //u32 ds_tune_tmp;
            max_p = min_p + phase_diff;
            if(max_p >= MAX_TUNING_STEP)
                max_p -= MAX_TUNING_STEP;

            tmp_phase = min_p + phase_diff/2;

#ifdef SKIP_ODD_POINT
            if((tmp_phase >= ODD_POINT_THR_L) && (tmp_phase <= ODD_POINT_THR_H)){
                EM_NOTICE("Odd point range hit!!! phase %d\n",tmp_phase);
                if(tmp_phase > ODD_POINT)
                    tmp_phase = ODD_POINT+4;
                else
                    tmp_phase = ODD_POINT-4;

            }
#endif
            if(tmp_phase >= MAX_TUNING_STEP)
                tmp_phase -= MAX_TUNING_STEP;


            cr_maskl(EMMC_PLLPHASE_CTRL,phase_mask,phase_sht ,tmp_phase);
            //ds_tune_tmp = cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f;

            EM_NOTICE("%s: max_p=%u min_p=%u diff=%u\n",
                DRIVER_NAME,max_p,min_p,phase_diff);
            EM_NOTICE("============================================\n");
            EM_NOTICE("%s: final PHASE(%s) is %u; 0x%08x = 0x%08x\n",
                DRIVER_NAME,(w_flag)?"W":"R",tmp_phase,
                EMMC_PLLPHASE_CTRL,cr_readl(EMMC_PLLPHASE_CTRL));
            //EM_NOTICE("ds_tune=%u(show only)\n",ds_tune_tmp);
            EM_NOTICE("============================================\n");

            if(w_flag){
                sdport->cur_w_phase = tmp_phase;
                sdport->cur_w_ph400 = min_p + phase_diff/4;
                if(sdport->cur_w_ph400 >= MAX_TUNING_STEP)
                    sdport->cur_w_ph400 -= MAX_TUNING_STEP;
                mmcmsg3("cur_w_phase = 0x%08x\n",sdport->cur_w_phase);
                mmcmsg3("cur_w_ph400 = 0x%08x\n",sdport->cur_w_ph400);
            } else {
                sdport->cur_r_phase = tmp_phase;

                sdport->tud_r_phase = sdport->cur_r_phase;
                sdport->tud_r_clock = sdport->cur_clock;

                sdport->pre_r_phase = sdport->tud_r_phase;
                //sdport->pre_ds_tune = ds_tune_tmp;

                mmcmsg3("%s(%d) ==>\n"
                    "        tud_r_phase =0x%08x tud_r_clock=%d\n"
                    "        pre_r_phase=0x%08x pre_ds_tune=0x%08x",
                    __func__,__LINE__,
                    sdport->tud_r_phase,sdport->tud_r_clock,
                    sdport->pre_r_phase,sdport->pre_ds_tune);
            }
        }
    }

    return err;
}
/************************************************************************
 *
 ************************************************************************/
static void dw_em_set_ds_delay(struct rtksd_host *sdport, int ds_delay)
{
    unsigned int tmp_dstune;
    unsigned int tmp_dsmode;
    unsigned int init_ds;

    init_ds = sdport->cur_ds_tune;
    if(rtk_emmc_test_ctl & EMMC_FIX_DSTUNE){
        EM_ALERT("%s(%d)Use Bootcode pre-setting parameter\n",
            __func__,__LINE__);

        tmp_dsmode = 3;  //((sdport->mmc_dstune) & 0xffff0000) >> 16;
        tmp_dstune = sdport->mmc_dstune & 0xff;
        if(tmp_dsmode == 3){
            /* becauce ds_value is abslute value at mode 3. fix initial ds_value */
            init_ds = tmp_dstune;
        }

        EM_ALERT("%s(%d)mode%d %s %d\n",
                __func__,__LINE__,
                tmp_dsmode,
                (tmp_dsmode==1)?"---":
                (tmp_dsmode==2)?"+++":
                (tmp_dsmode==3)?"fix delay":"",
                tmp_dstune);

    }else{
        tmp_dsmode = 3;
        tmp_dstune = ds_delay;
    }

    cr_maskl(EM_HALF_CYCLE_CAL_EN, 1, 18,0);
    udelay(5);
    cr_maskl(EM_DS_TUNE_CTRL, 0x1f, 15, init_ds);
    cr_maskl(EM_HALF_CYCLE_CAL_EN,3,1,tmp_dsmode);
    cr_maskl(EM_HALF_CYCLE_CAL_EN,0x1f,3,tmp_dstune);
    cr_maskl(EM_DS_TUNE_CTRL,1,20 ,1);
    cr_maskl(EM_HALF_CYCLE_CAL_EN,1,18 ,1);
    cr_maskl(EM_HALF_CYCLE_CAL_EN,1,0 ,1);
    udelay(5);
    cr_maskl(EM_HALF_CYCLE_CAL_EN,1,18 ,0);
#if 0
    EM_ALERT("%s(%d)cur_ds_tune:%d\n" ,
        __func__, __LINE__,sdport->cur_ds_tune);
    EM_ALERT("0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n",
        0xb801088c,(u32)cr_readl(0xb801088c),
        0xb8010890,(u32)cr_readl(0xb8010890),
        0xb8010850,(u32)cr_readl(0xb8010850),
        0xb8000708,(u32)cr_readl(0xb8000708),
        0xb800070C,(u32)cr_readl(0xb800070C));
#endif
}

/************************************************************************
 *
 ************************************************************************/
static int dw_em_ds_tuning(struct mmc_host *mmc, u32 ctl)
{
    struct rtksd_host *sdport = mmc_priv(mmc);
    u16 i=0, j=0;
    int err=0;
    u16 max_range = 0;
    u16 min_ds = 0;
    u16 ds_middle = 0;
    u8 result[MAX_DS_TUNE] = {0};
    int cmd_error = 0;

    if(ctl & TUNING_SKIP_FLAG){
        EM_ALERT("%s(%d)cur_ds_tune:%d\n" ,
            __func__, __LINE__,sdport->cur_ds_tune);
        EM_ALERT("0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n",
            0xb801088c,(u32)cr_readl(0xb801088c),
            0xb8010890,(u32)cr_readl(0xb8010890),
            0xb8010850,(u32)cr_readl(0xb8010850),
            0xb8000708,(u32)cr_readl(0xb8000708),
            0xb800070C,(u32)cr_readl(0xb800070C));
        return 0;
    }

    for (i=0; i < MAX_DS_TUNE; i++) {
        dw_em_set_ds_delay(sdport, i);
        sdport->rtflags |= RTKCR_TUNING_STATE;
        err = mmc_send_tuning(mmc, MMC_READ_SINGLE_BLOCK, &cmd_error);
        sdport->rtflags &= ~RTKCR_TUNING_STATE;

        if (!err)
            result[i] = 1;
    }
    rtkem_show_ds_tune_result(sdport,result,"DS tuning result: ");

    for (i=0; i < MAX_DS_TUNE; i++) {
        int circum = 0;

        for (j=i; j < i+MAX_DS_TUNE; j++) {
            int convert_j =  (j >= MAX_DS_TUNE)?
                (j-MAX_DS_TUNE) : j;
            if (result[convert_j])
                circum++;
            else
                break;
        }

        if (circum > max_range) {
            max_range = circum;
            min_ds = i;
        }
    }

    ds_middle = (min_ds + (max_range)/2)-1;

    if (max_range < 3) {
        EM_ERR("ds capable range %d is small\n", max_range);
        dw_em_set_ds_delay(sdport, sdport->cur_ds_tune);
        goto ERR;
    } else {
       dw_em_set_ds_delay(sdport, ds_middle);
       sdport->pre_ds_tune = sdport->cur_ds_tune = ds_middle;
       EM_ERR("set ds %d\n", ds_middle);
    }

    return 0;
ERR:
    return -1;
}

/************************************************************************
 *
 ************************************************************************/
static int dw_em_execute_tuning(struct mmc_host *mmc, u32 opcode)
{
    struct rtksd_host *sdport;
    int err = 0;
    u32 tune_ctl = 0;
    u32 pre_ctl = 0;

    sdport = mmc_priv(mmc);

    if(sdport->ins_event & EVENT_SKIP_PHASETUNE)
    {
        /* if STR operation, skip tuning */
        EM_NOTICE("%s(%d) skip tuning flow!!!\n",__func__,__LINE__);
        /* if tuning prior at resume case, skip tuning  */
        pre_ctl |= TUNING_SKIP_ALL;
        sdport->cur_r_phase = sdport->pre_r_phase;
        sdport->ins_event &= ~EVENT_SKIP_PHASETUNE;
    }

    if(rtk_emmc_test_ctl & EMMC_SKIP_TUNE){
        EM_ALERT("%s(%d)Use Bootcode pre-setting parameter. Skip tuning\n",
            __func__,__LINE__);
        pre_ctl |= TUNING_SKIP_FLAG;
    }

    if( (opcode == 21)
     || (opcode == 18) )
    {
        /*
         opcode 21 is HS200 tuning state
         opcode 18 is HS400 tuning state
         */

        /* enable DS-tune has moved to prepare_hs400_tuning() */
        tune_ctl = pre_ctl;

        if ((opcode == 18) &&
            ((rtk_emmc_test_ctl & EMMC_FIX_DSTUNE) ||
            (sdport->ins_event & EVENT_SKIP_DSTUNING)))
        {
            /* skip ds tuning if fix dstune */
            EM_NOTICE("skip ds tuning flow!!!{dss=%d;dsh=%d}[A]\n",
                    sdport->cur_ds_tune,cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f);
            sdport->pre_ds_tune = sdport->cur_ds_tune;
            tune_ctl |= TUNING_SKIP_FLAG;
            sdport->ins_event &= ~EVENT_SKIP_DSTUNING;
            err = 0;
            goto ERR_OUT;
        }

        if(tune_ctl & TUNING_SKIP_ALL){
            if(opcode == 18){
                //dw_em_set_ds_delay(sdport, sdport->cur_ds_tune);
                EM_NOTICE("skip ds tuning flow!!!{dss=%d;dsh=%d}[B]\n",
                    sdport->cur_ds_tune,cr_readl(EM_HALF_CYCLE_CAL_RESULT) & 0x1f);
                sdport->pre_ds_tune = sdport->cur_ds_tune;

            }else{
                /* w_phase;r_phase */
                dw_em_init_phase(sdport,0xff,(u32)sdport->cur_r_phase,0xff);
                EM_INFO("%s(%d)restore r_phase=%d\n",
                        __func__,__LINE__,sdport->cur_r_phase);
            }
            err = 0;
            goto ERR_OUT;
        }

        /* read tuning first at HS200 */
        if(opcode == 18){
            tune_ctl |= 17;
            err = dw_em_ds_tuning(mmc, tune_ctl);
        }else{
            tune_ctl |= 21;
            err = dw_em_simple_tuning(mmc, tune_ctl);
        }

        if(err){
            goto ERR_OUT;
        }

#ifndef USE_FIXED_W_PHASE

        /* write tuning  */
        tune_ctl = pre_ctl;
        tune_ctl |= TUNING_WRITE_FLAG;
        if(opcode == 18){
            tune_ctl |= TUNING_HS400;
            tune_ctl |= 25; // tuning cmd
            /* block R/W teset use 2 block for stability */
            tune_ctl |= (2UL << TUNING_BLK_SHT);
        }else{
            /* cmd21 only 1 block */
            tune_ctl |= 21; // tuning cmd
            tune_ctl |= (1UL << TUNING_BLK_SHT);
            err = dw_em_simple_tuning(mmc, tune_ctl);
        }

        if(err){
            goto ERR_OUT;
        }
#endif

    }else{
        err = -1;
    }
ERR_OUT:
    return err;

}

/************************************************************************
 *
 ************************************************************************/
static int mmc_send_data_cmd(struct mmc_host *mmc, u32 hc_cmd,
                 u32 cmd_arg, u32 blk_cnt, unsigned char *buffer)
{
    int err = 0;
    struct rtksd_host *sdport;
    unsigned long flags;

    if(mmc == NULL)
        mmc = mmc_host_local;

    sdport = mmc_priv(mmc);

    if(!(sdport->rtflags & RTKCR_TUNING_STATE)){
        EM_NOTICE( "cmd=%u, arg=0x%08x, size=0x%08x, buf=0x%p\n",
            hc_cmd,cmd_arg,blk_cnt,buffer);
    }

    if(mmc){
        struct mmc_card *card = mmc->card;
        struct mmc_request mrq = {0};
        struct mmc_command cmd = {0};
        struct mmc_data data   = {0};
        struct scatterlist sg;

        sdport = mmc_priv(mmc);
        mmc_claim_host(mmc);
        spin_lock_irqsave(&sdport->lock,flags);

        cmd.opcode = hc_cmd;
        cmd.arg = cmd_arg;
        cmd.flags = MMC_RSP_R1 | MMC_CMD_ADTC;

        if (blk_cnt) {
            data.sg = &sg;
            data.sg_len = 1;

            if(hc_cmd == 21){
                if(sdport->cur_width == 8){
                    /* 8bits 128bytes */
                    data.blksz = 128;
                }else if(sdport->cur_width ==4){
                    /* 4bits 64bytes */
                    data.blksz = 64;
                }else{
                    mmcmsg2( "not supported parameter");
                    spin_unlock_irqrestore(&sdport->lock, flags);
                    mmc_release_host(mmc);
                    goto ERR_OUT;
                }

            }else{
                data.blksz = 512;
            }
            data.blocks = blk_cnt;

            sg_init_one(data.sg, buffer, (blk_cnt * (data.blksz)));

            if( hc_cmd == MMC_WRITE_MULTIPLE_BLOCK ||
                hc_cmd == MMC_WRITE_BLOCK) {
                data.flags = MMC_DATA_WRITE;
            } else if (hc_cmd == MMC_SEND_EXT_CSD ||
                hc_cmd == MMC_READ_MULTIPLE_BLOCK ||
                hc_cmd == MMC_READ_SINGLE_BLOCK ||
                hc_cmd == MMC_SEND_TUNING_BLOCK_HS200) {
                data.flags = MMC_DATA_READ;
            }else{
                EM_ERR( "not supported command");
                spin_unlock_irqrestore(&sdport->lock, flags);
                mmc_release_host(mmc);
                goto ERR_OUT;
            }

            if(card){
                mmc_set_data_timeout(&data, card);
            }
        }

        data.mrq = &mrq;
        cmd.mrq = &mrq;
        cmd.data = &data;

        if(sdport->rtflags & RTKCR_TUNING_STATE)
            cmd.retries = 0;
        else
            cmd.retries = 3;

CMD_RETRY:
        mrq.data = &data;
        mrq.cmd = &cmd;

        if(sdport->mrq){
            sdport->mrq = NULL;
        }

        cmd.error = 0;
        data.error = 0;

        spin_unlock_irqrestore(&sdport->lock, flags);
        mmc_wait_for_req(mmc, &mrq);
        spin_lock_irqsave(&sdport->lock,flags);

        err = cmd.error;

        if(err && cmd.retries ){
            mmcmsg2( "%s(%u)last retry %d counter.\n",
                __func__,__LINE__,cmd.retries);
            cmd.retries--;
            goto CMD_RETRY;
        }
        spin_unlock_irqrestore(&sdport->lock, flags);
        mmc_release_host(mmc);

    }else{
        err = -ENODEV;
    }

ERR_OUT:
    if(err)
        mmcmsg2( "err=%d\n", err);
    return err;
}

/************************************************************************
 *
 ************************************************************************/
int export_mmc_send_data_cmd(u32 hc_cmd,
                 u32 cmd_arg, u32 blk_cnt, unsigned char *buffer)
{
    return mmc_send_data_cmd(NULL,hc_cmd,cmd_arg,blk_cnt,buffer);
}
EXPORT_SYMBOL(export_mmc_send_data_cmd);

#ifdef CONFIG_MMC_RTKEMMC_HK_ATTR
/************************************************************************
 *
 ************************************************************************/
static
void show_ext_csd(u8 *ext_csd)
{
    int i;
    for (i = 0; i < 512; i += 8) {
        EM_NOTICE(
               "[%03u]=%02x [%03u]=%02x [%03u]=%02x [%03u]=%02x "
               "[%03u]=%02x [%03u]=%02x [%03u]=%02x [%03u]=%02x\n",
               i, *(ext_csd + i), i + 1, *(ext_csd + i + 1), i + 2,
               *(ext_csd + i + 2), i + 3, *(ext_csd + i + 3), i + 4,
               *(ext_csd + i + 4), i + 5, *(ext_csd + i + 5), i + 6,
               *(ext_csd + i + 6), i + 7, *(ext_csd + i + 7));
    }
    EM_NOTICE( "\n");
}

/************************************************************************
 *
 ************************************************************************/
#ifdef  EN_SHOW_DATA
static
void show_data(u8 *buf, unsigned int len)
{
    int i;
    for (i = 0; i < len; i += 8) {
        EM_NOTICE(
               "[%03u]=%02x [%03u]=%02x [%03u]=%02x [%03u]=%02x "
               "[%03u]=%02x [%03u]=%02x [%03u]=%02x [%03u]=%02x\n",
               i, *(buf + i), i + 1, *(buf + i + 1), i + 2,
               *(buf + i + 2), i + 3, *(buf + i + 3), i + 4,
               *(buf + i + 4), i + 5, *(buf + i + 5), i + 6,
               *(buf + i + 6), i + 7, *(buf + i + 7));
    }
    EM_NOTICE( "\n");
}
#endif

/************************************************************************
 *
 ************************************************************************/
#define PF2_SHOW_EXT_CSD 0x01UL
#define PF2_FULL_PARAM   0x02UL
#define PF2_SET_EXT_CSD  0x04UL

/************************************************************************
 *
 ************************************************************************/
static void hk_set_wr_rel(struct device *dev,
              size_t p_count, unsigned char *cr_param)
{
    u8 *emmc_buf;
    u8 acc_mod;
    u8 index;
    u8 value;
    u8 i;
    u8 idx_lop;
    u8 cmd_set;
    u32 param1;
    u32 param2;
    u32 param3;
    u32 buf_size;
    struct mmc_host *host;
    struct mmc_card *card = NULL;

    EM_NOTICE( "%s(%u)2013/08/15 17:30\n", __func__, __LINE__);

    if( p_count != 38){
        EM_NOTICE( "Command format:\n"
               "    echo set_wr_rel=param1,param2,param3 > emmc_hacking;\n"
               "        param1[7:0] is value in byte you want to set.\n"
               "        param2 :\n"
               "            [bit0] TO show all ext_csd.\n"
               "            [bit1] Send CMD6. if this bit is set.\n"
               "                   param1 change to 32 bits parameter of argument of AMD6.\n"
               "        param3 must be 2379beef to make sure you want to do this.\n"
               "ex:\n"
               "    echo set_wr_rel=00000001,00000000,2379beef > emmc_hacking;\n"
               "        param1=0x00000001 enable user data area write reliability\n"
               "        param2=0x00020000 do not show all ext_csd.\n"
               "        param3=2379beef make sure that want to do this.\n"
               "\n"
               "    echo set_wr_rel=03a71f01,00000002,2379beef > emmc_hacking;\n"
               "        param1=0x03a71f01 set ext_cse[0xa7], value=0x1f, cmd_set=1\n"
               "        param2=0x00000002 send CMD6. param1 is argument in 32 bits.\n"
               "        param3=2379beef make sure that want to do this.\n" );
        goto ERR_OUT;
    }

    host = dev_get_drvdata(dev);
    if(host)
        card = host->card;

    /* KWarning: checked ok by alexkh@realtek.com */
    if(card == NULL){
        EM_NOTICE( "card is not exist.\n");
        goto ERR_OUT;
    }

    rtkcr_chk_param(&param1,8,cr_param);
    rtkcr_chk_param(&param2,8,cr_param+9);
    rtkcr_chk_param(&param3,8,cr_param+18);

    EM_NOTICE( "param1=0x%x\n", param1);
    EM_NOTICE( "param2=0x%x\n", param2);
    EM_NOTICE( "param3=0x%x\n", param3);

    if(param2 & PF2_FULL_PARAM){
        EM_NOTICE( "Send CMD6 alert\n");
        acc_mod = (u8)((param1>>24)&0xff);
        index   = (u8)((param1>>16)&0xff);
        value   = (u8)((param1>> 8)&0xff);
        cmd_set = (u8)(param1&0xff);
    }else{
        EM_NOTICE( "Enable Write Reliability\n");
        acc_mod = MMC_SWITCH_MODE_WRITE_BYTE;
        index   = EXT_CSD_WR_REL_SET;
        value   = (u8)param1;
        cmd_set = 1;
    }

    EM_NOTICE( "acc_mod=0x%x; index=%u; value=0x%x; cmd_set=0x%x\n",
            acc_mod,index,value,cmd_set);

    buf_size = 512;
    emmc_buf = kmalloc(buf_size, GFP_KERNEL);
    if(!emmc_buf){
        EM_NOTICE( "emmc_buf is NULL\n");
        goto ERR_OUT;
    }

    memset(emmc_buf, 0, 512);
    mmc_send_data_cmd(NULL, MMC_SEND_EXT_CSD, 0, 1, emmc_buf);

    EM_NOTICE( "[EXT_CSD] :\n");
    if(param2){
        if(param2 & PF2_SHOW_EXT_CSD)
            show_ext_csd(emmc_buf);
        if(param2 & PF2_FULL_PARAM){
            if( index==249 || index==242 ||
                index==212 || index==136 )
                idx_lop = 4;
            else if( index==157 || index==140)
                idx_lop = 3;
            else if( index==143)
                idx_lop = 12;
            else
                idx_lop = 1;

            for(i=0; i<idx_lop; i++)
                EM_NOTICE( "    [%03u]=%02x\n", index + i,
                       *(emmc_buf + index + i));
        }

    }else{
        EM_NOTICE( "    [%03u]=%02x [%03u]=%02x\n",
               166, *(emmc_buf + 166), 167, *(emmc_buf + 167));
    }

    if(index == EXT_CSD_WR_REL_SET){
        if((*(emmc_buf+EXT_CSD_WR_REL_PARAM) & 0x05) == 0x05 ){
            if(*(emmc_buf+EXT_CSD_PARTITION_SETTING_COMPLETED) & 0x01){
                EM_NOTICE( "This chip PARTITION configuration have completed\n");
                EM_NOTICE( "  ENH_SATRT_ADDR = 0x%08x\n",
                       (*(emmc_buf + EXT_CSD_ENH_START_ADDR + 3)
                    << 24) | (*(emmc_buf +
                            EXT_CSD_ENH_START_ADDR +
                            2) << 16) | (*(emmc_buf +
                                   EXT_CSD_ENH_START_ADDR
                                   +
                                   1) << 8) |
                          (*(emmc_buf+EXT_CSD_ENH_START_ADDR)));
                EM_NOTICE( "  ENH_SIZE_MULT  = 0x%06x\n",
                       (*(emmc_buf + EXT_CSD_ENH_SIZE_MULT + 2)
                    << 16) | (*(emmc_buf +
                            EXT_CSD_ENH_SIZE_MULT +
                            1) << 8) | (*(emmc_buf +
                                  EXT_CSD_ENH_SIZE_MULT)));
                EM_NOTICE( "  PARTITION_ATTRIBUTE  = 0x%06x\n",
                       (*
                    (emmc_buf +
                     EXT_CSD_PARTITION_ATTRIBUTE)));
                EM_NOTICE( "  WR_REL_SET  = 0x%x\n",
                        (*(emmc_buf+EXT_CSD_WR_REL_SET)));
                goto FINISH_OUT;
            }

        }else{
            EM_NOTICE( "Device not support setting write reliability\n");
            EM_NOTICE( "  WR_REL_PARAM = 0x%x\n",
                      *(emmc_buf+EXT_CSD_WR_REL_PARAM));
            goto FINISH_OUT;
        }
    }

    if(param3 == 0x2379beef)
        rtksd_switch(card,acc_mod,index,value,cmd_set);
    else{
        EM_NOTICE( "param3 != 0x2379beef skip command.\n");
        goto FINISH_OUT;
    }

    memset(emmc_buf, 0, 512);
    mmc_send_data_cmd(NULL, MMC_SEND_EXT_CSD, 0, 1, emmc_buf);

    EM_NOTICE( "{F} [EXT_CSD] :\n");
    if(param2){
        if(param2 & PF2_SHOW_EXT_CSD)
            show_ext_csd(emmc_buf);
        if(param2 & PF2_FULL_PARAM){
            if( index==249 || index==242 ||
                index==212 || index==136 )
                idx_lop = 4;
            else if( index==157 || index==140)
                idx_lop = 3;
            else if( index==143)
                idx_lop = 12;
            else
                idx_lop = 1;

            for(i=0; i<idx_lop; i++)
                EM_NOTICE( "    [%03u]=%02x\n", index + i,
                       *(emmc_buf + index + i));
        }
    }else{
        EM_NOTICE( "    [%03u]=%02x [%03u]=%02x\n",
               166, *(emmc_buf + 166), 167, *(emmc_buf + 167));
    }

FINISH_OUT:
    kfree(emmc_buf);

ERR_OUT:
    return;

}

/************************************************************************
 *
 ************************************************************************/
static void hk_red_ext_csd(struct device *dev, size_t p_count,
                           unsigned char *cr_param)
{
    u8 *emmc_buf;
    u32 param1;     /* target emmc address */
    u32 param2;     /* block number */
    u32 param3;     /* 1: write; 0: read */
    u32 buf_size ;
    struct mmc_host *host;
    struct mmc_card *card = NULL;

    EM_NOTICE( "%s(%u)2013/08/15 17:30\n", __func__, __LINE__);
    host = dev_get_drvdata(dev);
    if(host)
        card = host->card;

    /* KWarning: checked ok by alexkh@realtek.com */
    if(card == NULL){
        EM_INFO( "card is not exist.\n");
        goto ERR_OUT;
    }

    rtkcr_chk_param(&param1,8,cr_param);
    rtkcr_chk_param(&param2,8,cr_param+9);
    rtkcr_chk_param(&param3,8,cr_param+18);

    EM_NOTICE( "param1=0x%x\n", param1);  /* enh_start_addr */
    EM_NOTICE( "param2=0x%x\n", param2);  /* enh_block_cnt */
    EM_NOTICE( "param3=0x%x\n", param3);

    buf_size = 512;
    emmc_buf = kmalloc(buf_size, GFP_KERNEL);
    if(!emmc_buf){
        EM_NOTICE( "emmc_buf is NULL\n");
        goto ERR_OUT;
    }
    EM_NOTICE( "emmc_buf=0x%p\n", emmc_buf);

    memset(emmc_buf, 0, 512);
    mmc_send_data_cmd(NULL, MMC_SEND_EXT_CSD, 0, 1, emmc_buf);

    EM_NOTICE( "[EXT_CSD] :\n");

    if(param1 && !(param2 & PF2_SHOW_EXT_CSD)){
        u8 i;
        u8 item_cnt = 0;
        u8 item_cnt_old = 0;
        for(i=0;i<4;i++){
            /* every byte of param1 denote one extcsd address, parser here.
             * if the field is zero, use lasted address add one
             */
            item_cnt = param1>>(i*8);
            if(!item_cnt)
                item_cnt = (item_cnt_old+1);
            EM_NOTICE( "    [%03u]=%02x\n", item_cnt,
                   *(emmc_buf + item_cnt));
            item_cnt_old = item_cnt;
        }
        EM_NOTICE( "\n");
    }else{
        show_ext_csd(emmc_buf);
    }
    kfree(emmc_buf);

ERR_OUT:
    return;
}

/************************************************************************
 *
 ************************************************************************/
static void hk_set_enh_user_area(struct device *dev,
                 size_t p_count, unsigned char *cr_param)
{
    u8 *emmc_buf;
    u32 param1;
    u32 param2;
    u32 param3;
    u32 buf_size ;
    struct mmc_host *host;
    struct mmc_card *card = NULL;

    EM_NOTICE( "%s(%u)2013/08/15 17:30\n", __func__, __LINE__);
    host = dev_get_drvdata(dev);
    if(host)
        card = host->card;

    /* KWarning: checked ok by alexkh@realtek.com */
    if(card == NULL){
        EM_NOTICE( "card is not exist.\n");
        goto ERR_OUT;
    }
    rtkcr_chk_param(&param1,8,cr_param);
    rtkcr_chk_param(&param2,8,cr_param+9);
    rtkcr_chk_param(&param3,8,cr_param+18);

    EM_NOTICE( "param1=0x%x\n", param1);  /* enh_start_addr */
    EM_NOTICE( "param2=0x%x\n", param2);  /* enh_block_cnt */
    EM_NOTICE( "param3=0x%x\n", param3);

    buf_size = 512;
    emmc_buf = kmalloc(buf_size, GFP_KERNEL);
    if(!emmc_buf){
        EM_NOTICE( "emmc_buf is NULL\n");
        goto ERR_OUT;
    }
    EM_NOTICE( "emmc_buf=0x%p\n", emmc_buf);

    memset(emmc_buf, 0, 512);
    mmc_send_data_cmd(NULL, MMC_SEND_EXT_CSD, 0, 1, emmc_buf);

    EM_NOTICE( "[EXT_CSD] :\n");
    if((*(emmc_buf+EXT_CSD_PARTITION_SUPPORT) &0x03) == 0x03){
        u32 i;
        u32 max_enh_size_mult;
        u32 enh_size_base_blk;
        u32 sec_cnt;
        u8 hc_wp_grp_size;
        u8 hc_erase_grp_size;

        hc_wp_grp_size = *(emmc_buf+EXT_CSD_HC_WP_GRP_SIZE);
        hc_erase_grp_size = *(emmc_buf+EXT_CSD_HC_ERASE_GRP_SIZE);

        sec_cnt = (*(emmc_buf+EXT_CSD_SEC_CNT+3)<<24) |
                  (*(emmc_buf+EXT_CSD_SEC_CNT+2)<<16) |
                  (*(emmc_buf+EXT_CSD_SEC_CNT+1)<<8) |
                  (*(emmc_buf+EXT_CSD_SEC_CNT));

        max_enh_size_mult =
            (*(emmc_buf + EXT_CSD_MAX_ENH_SIZE_MULT + 2) << 16) |
                            (*(emmc_buf+EXT_CSD_MAX_ENH_SIZE_MULT+1)<<8) |
                            (*(emmc_buf+EXT_CSD_MAX_ENH_SIZE_MULT));

        enh_size_base_blk = ((u32)hc_wp_grp_size)*((u32)hc_erase_grp_size) * 1024;

        EM_NOTICE( "  ERASE_GROUP_DEF = 0x%x\n",
                *(emmc_buf+EXT_CSD_ERASE_GROUP_DEF));
        EM_NOTICE( "  HC_WP_GRP_SIZE = 0x%x\n", hc_wp_grp_size);
        EM_NOTICE( "  HC_ERASE_GRP_SIZE = 0x%x\n",
               hc_erase_grp_size);
        EM_NOTICE( "  SEC_CNT = 0x%x\n", sec_cnt);
        EM_NOTICE( "  MAX_ENH_SIZE_MULT = 0x%x\n",
               max_enh_size_mult);
        EM_NOTICE( "Enhanced User Data Area base=\n"
               "            %u kBytes(0x%x block)\n",
                (enh_size_base_blk>>1),enh_size_base_blk);
        EM_NOTICE( "Enhanced User Data Area x Size=\n"
               "            ENH_SIZE_MULT x HC_WP_GRP_SIZE x\n"
               "            HC_ERASE_GRP_SIZE x 512 kBytes\n");

        if(*(emmc_buf+EXT_CSD_PARTITION_SETTING_COMPLETED) & 0x01){
            EM_NOTICE( "This chip PARTITION configuration have completed\n");
            EM_NOTICE( "  ENH_SATRT_ADDR = 0x%08x\n",
                   (*(emmc_buf + EXT_CSD_ENH_START_ADDR + 3) << 24)
                   | (*(emmc_buf + EXT_CSD_ENH_START_ADDR + 2) <<
                  16) | (*(emmc_buf + EXT_CSD_ENH_START_ADDR +
                       1) << 8) | (*(emmc_buf +
                             EXT_CSD_ENH_START_ADDR)));
            EM_NOTICE( "  ENH_SIZE_MULT  = 0x%06x\n",
                      (*(emmc_buf+EXT_CSD_ENH_SIZE_MULT+2)<<16) |
                      (*(emmc_buf+EXT_CSD_ENH_SIZE_MULT+1)<<8) |
                      (*(emmc_buf+EXT_CSD_ENH_SIZE_MULT)));
            EM_NOTICE( "  PARTITION_ATTRIBUTE  = 0x%06x\n",
                    (*(emmc_buf+EXT_CSD_PARTITION_ATTRIBUTE)));

            goto FINISH_OUT;
        }

        if(param2 > enh_size_base_blk){
            i = param2 % enh_size_base_blk;
            param2 = (param2/enh_size_base_blk);
            if(i)
                param2 += 1;
        }else{
            param2 = 1;
        }
        if(param2 > max_enh_size_mult)
            param2 = max_enh_size_mult;

        EM_NOTICE( "ENH_SATRT_ADDR = 0x%08x\n", param1);
        EM_NOTICE( "ENH_SIZE_MULT  = 0x%06x\n", param2);

        if(p_count == 38 && (param3 == 0x2379beef)){
            u32 part_switch_time;
            /* doing set enhance user data param to ext_csd */
            /* setting ENH_SATRT_ADDR */
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_START_ADDR,
                     (u8) (param1 & 0xff), 1);
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_START_ADDR + 1,
                     (u8) ((param1 >> 8) & 0xff), 1);
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_START_ADDR + 2,
                     (u8) ((param1 >> 16) & 0xff), 1);
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_START_ADDR + 3,
                     (u8) ((param1 >> 24) & 0xff), 1);
            /* setting ENH_SIZE_MULT */
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_SIZE_MULT,
                     (u8) (param2 & 0xff), 1);
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_SIZE_MULT + 1,
                     (u8) ((param2 >> 8) & 0xff), 1);
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                     EXT_CSD_ENH_SIZE_MULT + 2,
                     (u8) ((param2 >> 16) & 0xff), 1);
            /* settig user data area to enhance mode */
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                         EXT_CSD_PARTITION_ATTRIBUTE,0x01,1);
            /* setting partition configuration complete */
            rtksd_switch(card,MMC_SWITCH_MODE_WRITE_BYTE,
                         EXT_CSD_PARTITION_SETTING_COMPLETED,0x01,1);

            part_switch_time =
                *(emmc_buf + EXT_CSD_PART_SWITCH_TIME);
            EM_NOTICE( "Partition Switch Time is %u0ms.\n",
                   part_switch_time);
            mdelay(10*(part_switch_time+10));
        }else{
            EM_NOTICE( "Command format:\n"
                   "    echo set_ehuser=param1,param2,param3 > emmc_hacking;\n"
                   "        param1 is enhance user data area start address in block(8 hex).\n"
                   "        param2 is enhance user data area size in block(8 hex).\n"
                   "        param3 must be 2379beef to make sure you want to do this.\n"
                   "ex:\n"
                   "    echo set_ehuser=00000000,00020000,2379beef > emmc_hacking;\n"
                   "        param1=0x00000000 EUDA start address is 0.\n"
                   "        param2=0x00020000 EUDA size is 0x2000.\n"
                   "        param3=2379beef make sure that want to do this.\n" );
        }

    }else{
        EM_NOTICE( "device do not support enhance uaer data area.\n");
    }
FINISH_OUT:
    kfree(emmc_buf);

ERR_OUT:
    return;
}

/************************************************************************
 *
 ************************************************************************/
static void hk_rw_reg(struct device *dev,
        size_t p_count, unsigned char *cr_param)
{
    u32 param1;
    u32 param2;
    u32 param3;

    EM_NOTICE( "%s(%u)2015/10/19 16:25\n", __func__, __LINE__);

    rtkcr_chk_param(&param1,8,cr_param);
    rtkcr_chk_param(&param2,8,cr_param+9);
    rtkcr_chk_param(&param3,8,cr_param+18);

    if(p_count == 34){
        if(param1 == 0x2379beef){
            /* write reg */
            EM_NOTICE("REG[0x%08x] = 0x%08x(before)\n",param2,cr_readl(param2));
            cr_writel(param3, param2);
            EM_NOTICE("REG[0x%08x] = 0x%08x\n",param2,cr_readl(param2));
        }else if(param3 == 0x2379beef){
            /* read reg */
            EM_NOTICE("REG[0x%08x] = 0x%08x\n",param2,cr_readl(param2));
        }
    }else{
#if 0       /* Just for remind, do not to display user guide */
        EM_NOTICE( "Command format:\n"
               "    echo rw_reg=param1,param2,param3 > emmc_hacking;\n"
               "        param1: if 0xffffffff is write; if 0x00000000 is read.\n"
               "        param2: register address.\n"
               "        param3: if write case, it's writed value, or nothing.\n"
               "  ex:\n"
               "   write case:"
               "    echo rw_reg=2379beef,b8010900,12345678 > emmc_hacking;\n"
               "   read case:"
               "    echo rw_reg=00000000,b8010900,2379beef > emmc_hacking;\n" );
#endif
    }

    return;
}

#endif

/* ========================================================
 * blk_addr    : eMMC read/write target address, block base.
 * data_size   : tarnsfer data size, block base.
 * buffer      : DMA address
 * rw_mode     : fast read or fast write
 ========================================================== */
#define FAST_READ   0x1278
#define FAST_WRITE  0x3478
extern int export_get_card_status(struct mmc_card *card, u32 *status, int retries);
static int mmc_fast_rw( u32 blk_addr,
               u32 data_size, unsigned char *buffer, u32 rw_mode)
{
    int err = 0;
    struct mmc_host * mmc = mmc_host_local;

    if(mmc){
        struct rtksd_host *sdport;
        struct mmc_card *card;
        struct mmc_request mrq = {0};
        struct mmc_command cmd = {0};
        struct mmc_data data   = {0};
        struct scatterlist sg;

        sdport = mmc_priv(mmc);
        mmc_claim_host(mmc);
        card = mmc->card;

        if((sdport->rtflags & RTKCR_USER_PARTITION)==0){
            int try_loop = 3;
            do{
                err = 0;
                /* Switch to ser partition */
                err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
                        EXT_CSD_PART_CONFIG, 0,
                        card->ext_csd.part_time);
            }while(try_loop-- && err );
            if(err){
                mmc_release_host(mmc);
                goto ERR_OUT;
            } else
                sdport->rtflags |= RTKCR_USER_PARTITION;
        }

        if(data_size>1){

            if(rw_mode == FAST_WRITE)
                cmd.opcode = MMC_WRITE_MULTIPLE_BLOCK;
            else
                cmd.opcode = MMC_READ_MULTIPLE_BLOCK;

        }else{

            if(rw_mode == FAST_WRITE)
                cmd.opcode = MMC_WRITE_BLOCK;
            else
                cmd.opcode = MMC_READ_SINGLE_BLOCK;
        }

        cmd.arg = blk_addr;
        cmd.flags = MMC_RSP_R1 | MMC_CMD_ADTC;

        if (data_size) {    /* date info setting */
            data.sg = &sg;
            data.sg_len = 1;
            data.blksz = 512;
            data.blocks = data_size;

            sg_init_one(data.sg, buffer, (data_size<<9));

            if(rw_mode == FAST_WRITE)
                data.flags = MMC_DATA_WRITE;
            else
                data.flags = MMC_DATA_READ;

            mmc_set_data_timeout(&data, card);
        }

        data.mrq = &mrq;
        cmd.mrq = &mrq;
        cmd.data = &data;
        cmd.retries =5;

CMD_RETRY:
        mrq.data = &data;
        mrq.cmd = &cmd;

        if(sdport->mrq){
            sdport->mrq = NULL;
        }
        cmd.error = 0;
        data.error = 0;
        mmc_wait_for_req(mmc, &mrq);
        err = cmd.error;
        if(err && cmd.retries){
            EM_INFO("%s(%u)last retry %d counter.\n",
                    __func__,__LINE__,cmd.retries);
            cmd.retries--;
            goto CMD_RETRY;
        }
        mmc_release_host(mmc);
    }else{
        err = -ENODEV;
    }

ERR_OUT:
    if(err)
        EM_INFO("err=%d\n", err);
    return err;
}

/************************************************************************
 *
 ************************************************************************/
#define MAX_XFER_BLK      0x400
static int mmc_fast_rw_loop(u32 blk_addr,
                u32 data_size, unsigned char *buffer, u32 rw_mode)
{
    int err = 0;

    u32 tmp_addr   = blk_addr;
    u32 tmp_size   = data_size;
    u32 org_size   = data_size;
    unsigned char * tmp_buf = buffer;
    u32 max_xfer_blk;
    do{
        /* max 1M bytes read/write per transfer */

        max_xfer_blk = MAX_XFER_BLK;

        if(data_size > max_xfer_blk){
            tmp_size = max_xfer_blk;
        }else{
            tmp_size = data_size;
        }

        err = mmc_fast_rw(tmp_addr,tmp_size,tmp_buf,rw_mode);

        if(err)
            break;

        if(data_size > max_xfer_blk){
            tmp_addr    += max_xfer_blk;
            data_size   -= max_xfer_blk;
            tmp_buf     += (max_xfer_blk<<9);
        }else{
            data_size = 0;
        }

    }while(data_size);

    if(err == 0)
         return org_size-data_size;
    else
        return err;
}

/************************************************************************
 *
 ************************************************************************/
int mmc_fast_read(u32 blk_addr, u32 data_size, unsigned char *buffer)
{
    int err = 0;
    err = mmc_fast_rw_loop(blk_addr,data_size,buffer,FAST_READ);
    return err;
}

EXPORT_SYMBOL(mmc_fast_read);

/************************************************************************
 *
 ************************************************************************/
int mmc_fast_write(u32 blk_addr, u32 data_size, unsigned char *buffer)
{
    int err = 0;
    if(blk_addr<0x20000){
        EM_INFO("target small then save area.\n");
        err = -1;
    }
    err = mmc_fast_rw_loop(blk_addr,data_size,buffer,FAST_WRITE);
    return err;
}

EXPORT_SYMBOL(mmc_fast_write);

/************************************************************************
 *
 ************************************************************************/
void test_raw_emmc_partition_change(u32 mode)
{
    EM_ALERT( "%s(%d)\n",__func__,__LINE__);
    if(export_raw_emmc_partition_change(mode)){
        EM_ALERT( "%s(%d)change partition%u fail\n",
            __func__,__LINE__,mode);
    }
}

/************************************************************************
 *
 ************************************************************************/
void test_raw_emmc_read(u64 blk_addr, u32 blk_cnt)
{
    u8 *emmc_buf = NULL;
    int err;

    EM_ALERT( "%s(%d)\n",__func__,__LINE__);

    emmc_buf = kmalloc(blk_cnt*512, GFP_KERNEL);
    if(!emmc_buf){
        EM_ALERT( "%s(%d)malloc buffer fail!!!\n",__func__,__LINE__);
    }else{
        err = export_raw_dw_em_read(emmc_buf, (u64)(blk_addr*512),(blk_cnt*512));

        if(err){
            EM_ALERT( "%s(%d) fail!!!\n",__func__,__LINE__);
        }
        kfree(emmc_buf);
    }
}

/************************************************************************
 *
 ************************************************************************/
void test_raw_emmc_write(u64 blk_addr, u32 blk_cnt)
{
    u8 *emmc_buf = NULL;
    int err;

    EM_ALERT( "%s(%d)\n",__func__,__LINE__);

    emmc_buf = kmalloc(blk_cnt*512, GFP_KERNEL);
    if(!emmc_buf){
        EM_ALERT( "%s(%d)malloc buffer fail!!!\n",__func__,__LINE__);
    }else{
        err = export_raw_dw_em_write(emmc_buf, (u64)(blk_addr*512),(blk_cnt*512));

        if(err){
            EM_ALERT( "%s(%d) fail!!!\n",__func__,__LINE__);
        }
        kfree(emmc_buf);
    }
}

/************************************************************************
 *
 ************************************************************************/
#define MMC_PATTERN_1 0x00ff00ff
#define MMC_PATTERN_2 0x55aa55aa
#define MMC_PATTERN_3 0xff00ff00
#define MMC_PATTERN_4 0xaa55aa55

static void mmc_fill_pattern(char *mmc_buf,int blk_cnt)
{
    int i;
    uint *ptr;

    /*
     change to 4 bytes, it's convenient to arrange pattern.
     Four types pattern to test.
     */
     ptr = (uint*)mmc_buf;
RE_FILL:
    blk_cnt -= 1;

    for(i=0;i< 128;i++){
        if(i<32)
            ptr[i] = MMC_PATTERN_1;
        else if(i<64)
            ptr[i] = MMC_PATTERN_2;
        else if(i<96)
            ptr[i] = MMC_PATTERN_3;
        else if(i<128)
            ptr[i] = MMC_PATTERN_4;
    }
    if(blk_cnt){
        ptr += 128;
        goto RE_FILL;
    }

}

/************************************************************************
 *
 ************************************************************************/
static int mmc_chk_pattern(char *mmc_buf,int blk_cnt)
{
    int i;
    int ret;
    uint *ptr;

    /*
     change to 4 bytes, it's convenient to arrange pattern.
     Four types pattern to test.
     */
    ret = 0;
    ptr = (uint*)mmc_buf;

NEXT_BLK_CHK:
    blk_cnt -= 1;
    for(i=0;i< 128;i++){
        if(i<32){
            if(ptr[i] != MMC_PATTERN_1){
                ret = -1;
                break;
            }
        }
        else if(i<64){
            if(ptr[i] != MMC_PATTERN_2){
                ret = -1;
                break;
            }
        }
        else if(i<96){
            if(ptr[i] != MMC_PATTERN_3){
                ret = -1;
                break;
            }
        }
        else if(i<128){
            if(ptr[i] != MMC_PATTERN_4){
                ret = -1;
                break;
            }
        }
    }

    if(blk_cnt && !ret){
        ptr += 128;
        goto NEXT_BLK_CHK;
    }

    return ret;
}

/************************************************************************
 *
 ************************************************************************/
static void mmc_show_blk(char *mmc_buf,int blk_cnt)
{
#ifdef DEBUG_PATTERN_EN

    int i;
    uint *ptr;

    ptr = (uint*)mmc_buf;

NEXT_BLK:
    blk_cnt -= 1;
    for(i=0;i<16;i++){
        printf("0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
               ptr[(i*8)+0],ptr[(i*8)+1],ptr[(i*8)+2],ptr[(i*8)+3],
               ptr[(i*8)+4],ptr[(i*8)+5],ptr[(i*8)+6],ptr[(i*8)+7]);
    }

    if(blk_cnt){
        ptr += 128;
        goto NEXT_BLK;
    }
#endif
}

/************************************************************************
 *
 ************************************************************************/
void test_raw_emmc_compare(u64 blk_addr, u32 blk_cnt)
{
    u8 *emmc_buf = NULL;
    int err;

    EM_ALERT( "%s(%d)\n",__func__,__LINE__);

    emmc_buf = kmalloc(blk_cnt*512, GFP_KERNEL);
    if(!emmc_buf){
        EM_ALERT( "%s(%d)malloc buffer fail!!!\n",__func__,__LINE__);
    }else{
        memset(emmc_buf, 0, blk_cnt*0x200);
        mmc_fill_pattern(emmc_buf,blk_cnt);
        mmc_show_blk(emmc_buf,blk_cnt);
        err = export_raw_dw_em_write(emmc_buf, (u64)(blk_addr*512),(blk_cnt*512));

        if(err){
            EM_ALERT( "%s(%d) fail!!!\n",__func__,__LINE__);
            goto ERR_OUT;
        }

        memset(emmc_buf, 0, blk_cnt*0x200);
        mmc_show_blk(emmc_buf,blk_cnt);
        err = export_raw_dw_em_read(emmc_buf, (u64)(blk_addr*512),(blk_cnt*512));
        if(err){
            EM_ALERT( "%s(%d) fail!!!\n",__func__,__LINE__);
            goto ERR_OUT;
        }

        mmc_show_blk(emmc_buf,blk_cnt);
        err = mmc_chk_pattern(emmc_buf,blk_cnt);
        if (err){
            EM_ALERT( "%s(%d) compare fail\n",__func__,__LINE__);
        }

ERR_OUT:
        kfree(emmc_buf);
    }
}

/************************************************************************
 * Command Sample
 * //No use
 * echo raw_func=00000000,b800084c,00001000 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //change to user partition
 * echo raw_func=00000001,00000000,00001000 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //change to boot part 1
 * echo raw_func=00000001,00000001,00001000 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //change to boot part 2
 * echo raw_func=00000001,00000002,00001000 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //read from 0x1234 total 0x100blk
 * echo raw_func=00000002,00001234,00000100 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //write to 0x740000 total 0x100blk
 * echo raw_func=00000003,00740000,00000100 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //emmc init
 * echo raw_func=00000004,b800084c,00001000 > /sys/devices/platform/18010800.emmc/emmc_hacking
 * //emmc W/R compare use raw func. write to 0x740000 total 0x10blk then read back and compare.
 * echo raw_func=00000005,00740000,00000010 > /sys/devices/platform/18010800.emmc/emmc_hacking
 *
 ************************************************************************/
static void hk_raw_func(struct device *dev, size_t p_count,
            unsigned char *cr_param)
{
    u32 param1;     /* 1:change partition; 2:raw_read; 3:raw_write */
    u32 param2;     /* partition number or start blk address for read/write */
    u32 param3;     /* block size of read/write  */

    EM_ALERT( "%s(%u)2016/05/04 16:05\n", __func__, __LINE__);

    rtkcr_chk_param(&param1,8,cr_param);
    rtkcr_chk_param(&param2,8,cr_param+9);
    rtkcr_chk_param(&param3,8,cr_param+18);

    EM_NOTICE( "param1=0x%x\n", param1);
    EM_NOTICE( "param2=0x%x\n", param2);
    EM_NOTICE( "param3=0x%x\n", param3);

    switch(param1){
        case 1: //raw_partition
            test_raw_emmc_partition_change(param2);
            break;
        case 2: //raw_read
            test_raw_emmc_read((u64)param2, param3);
            break;
        case 3: //raw_write
            test_raw_emmc_write((u64)param2, param3);
            break;
        case 4: //raw_init
            export_raw_dw_em_init();
            break;
        case 5: //W/R compare
            test_raw_emmc_compare((u64)param2, param3);
            break;
        default:
            EM_ALERT( "No support\n");
            return;
    }
    return;
}

/************************************************************************
 * mmc device attribute
 ************************************************************************/

/************************************************************************
 *
 ************************************************************************/
#define TEST_BLK_SIZE 10
static ssize_t
cr_fast_RW_dev_show(struct device *dev, struct device_attribute *attr,
        char *buf)
{
    struct mmc_host * host = dev_get_drvdata(dev);

    EM_INFO("%s(%u)\n", __func__, __LINE__);

    if(host && host->card){
        rtksd_switch_user_partition(host->card);
    }
    return sprintf(buf, "send SWITCH command\n");
}

static ssize_t
cr_fast_RW_dev_store(struct device *dev,
                     struct device_attribute *attr,
             const char *buf, size_t count)
{

    unsigned char *cr_param = NULL;

    EM_INFO("%s(%u)\n", __func__, __LINE__);
    EM_INFO("%s\n", buf);
    EM_INFO("count=%d\n", count);

    cr_param=(char *)rtkcr_parse_token(buf,"cr_param");

    if(cr_param){
        u8 *emmc_buf;
        u32 param1; /* target emmc address */
        u32 param2; /* block number */
        u32 param3; /* 1: write; 0: read */

        rtkcr_chk_param(&param1,8,cr_param);
        rtkcr_chk_param(&param2,8,cr_param+9);
        rtkcr_chk_param(&param3,8,cr_param+18);
        EM_INFO("param1=0x%x param2=0x%x param3=0x%x\n",
                param1,param2,param3);

        emmc_buf = kmalloc(512*param2, GFP_KERNEL);
        if(!emmc_buf){
            EM_INFO("emmc_buf is NULL\n");
            goto ERR_OUT;
        }

        EM_INFO("emmc_buf=0x%p\n", emmc_buf);

        if(param3 == 1){
            mmc_fast_write(param1, param2, emmc_buf );
        }else{
            mmc_fast_read(param1, param2, emmc_buf );
        }
        kfree(emmc_buf);
    }else{
        EM_INFO("have no parameter searched.\n");
    }

ERR_OUT:
    /*
    return value must be equare or big then "count"
    to finish this attribute
    */
    if(cr_param)
        kfree(cr_param);
    return count;
}

DEVICE_ATTR(cr_fast_RW, S_IRUGO | S_IWUSR,
            cr_fast_RW_dev_show,cr_fast_RW_dev_store);

/************************************************************************
 *
 ************************************************************************/
static ssize_t
em_open_log_dev_show(struct device *dev, struct device_attribute *attr,
        char *buf)
{
    struct mmc_host * host = dev_get_drvdata(dev);
    struct rtksd_host *sdport = mmc_priv(host);


    if(sdport->rtflags & RTKCR_FOPEN_LOG){
        sdport->rtflags &= ~RTKCR_FOPEN_LOG;
    }else{
        sdport->rtflags |=  RTKCR_FOPEN_LOG;
    }

    return sprintf(buf, "%s log %s\n",
            DRIVER_NAME,
            (sdport->rtflags & RTKCR_FOPEN_LOG)?"open":"close");
}

static ssize_t
em_open_log_dev_store(struct device *dev,
                     struct device_attribute *attr,
              const char *buf, size_t count)
{
    EM_INFO("%s(%u)No thing to do.\n", __func__, __LINE__);

    return count;
}

DEVICE_ATTR(em_open_log, S_IRUGO | S_IWUSR,
              em_open_log_dev_show,em_open_log_dev_store);

/************************************************************************
 *
 ************************************************************************/
#ifdef CONFIG_MMC_RTKEMMC_HK_ATTR
static ssize_t
emmc_hacking_dev_show(struct device *dev, struct device_attribute *attr,
        char *buf)
{
    EM_INFO( "%s(%u)2013/08/12 10:55\n", __func__, __LINE__);

    EM_INFO( "Supported hacking below:\n");
    EM_INFO( "    set_wr_rel  : enable write reliability.\n");
    EM_INFO( "    red_ext_csd : show ext_csd.\n");
    EM_INFO( "    set_ehuser  : enable enhance user date area.\n");

    return sprintf(buf, "emmc_hacking_dev_show\n");
}

static ssize_t
emmc_hacking_dev_store(struct device *dev,
                     struct device_attribute *attr,
               const char *buf, size_t count)
{
    unsigned char *cr_param = NULL;

    EM_INFO( "%s(%u)2013/08/15 17:30\n", __func__, __LINE__);
    EM_INFO( "count=%d\n", count);

    cr_param=(char *)rtkcr_parse_token(buf,"set_wr_rel");
    if(cr_param){
        hk_set_wr_rel(dev,count,cr_param);
        kfree(cr_param);
        goto FINISH_OUT;
    }

    cr_param=(char *)rtkcr_parse_token(buf,"red_ext_csd");
    if(cr_param){
        hk_red_ext_csd(dev,count,cr_param);
        kfree(cr_param);
        goto FINISH_OUT;
    }

    cr_param=(char *)rtkcr_parse_token(buf,"set_ehuser");
    if(cr_param){
        hk_set_enh_user_area(dev,count,cr_param);
        kfree(cr_param);
        goto FINISH_OUT;
    }

    cr_param=(char *)rtkcr_parse_token(buf,"rw_reg");
    if(cr_param){
        hk_rw_reg(dev,count,cr_param);
        kfree(cr_param);
        goto FINISH_OUT;
    }

    cr_param=(char *)rtkcr_parse_token(buf,"raw_func");
    if(cr_param){
        hk_raw_func(dev,count,cr_param);
        kfree(cr_param);
        goto FINISH_OUT;
    }

    EM_INFO("have no match command!!\n");

FINISH_OUT:
    /*
    return value must be equare or big then "count"
    to finish this attribute
    */
    return count;
}

DEVICE_ATTR(emmc_hacking, S_IRUGO | S_IWUSR,
            emmc_hacking_dev_show,emmc_hacking_dev_store);

#endif

/************************************************************************
 *
 ************************************************************************/
static ssize_t
emmc_errcnt_dev_show(struct device *dev, struct device_attribute *attr,
        char *buf)
{

    return sprintf(buf, "%s: eMMC have had %lu error since boot\n",
        DRIVER_NAME, rtk_emmc_err_cnt);
}

static ssize_t
emmc_errcnt_dev_store(struct device *dev,
                     struct device_attribute *attr,
              const char *buf, size_t count)
{
    EM_INFO("%s(%u)No thing to do.\n", __func__, __LINE__);

    return count;
}

DEVICE_ATTR(emmc_errcnt, S_IRUGO | S_IWUSR,
            emmc_errcnt_dev_show, emmc_errcnt_dev_store);

static ssize_t
phase_tune_dev_show(struct device *dev, struct device_attribute *attr,
        char *buf)
{
    unsigned int phase_ctrl_val = rtd_inl(EMMC_PLLPHASE_CTRL);
    unsigned int w_phase = (phase_ctrl_val >> PHASE_W_SHT) & PHASE_W_MASK;
    unsigned int r_phase = (phase_ctrl_val >> PHASE_R_SHT) & PHASE_R_MASK;

    return sprintf(buf, "%s: current w_phase = %u, r_phase = %u EMMC_PLL_PHASE_CTRL = 0x%08x\n",
        DRIVER_NAME, w_phase, r_phase, phase_ctrl_val);
}

static ssize_t
phase_tune_dev_store(struct device *dev, struct device_attribute *attr,
              const char *buf, size_t count)
{
    unsigned int phase_ctrl_val = rtd_inl(EMMC_PLLPHASE_CTRL);
    int w_phase = (phase_ctrl_val >> PHASE_W_SHT) & PHASE_W_MASK;
    int r_phase = (phase_ctrl_val >> PHASE_R_SHT) & PHASE_R_MASK;
    char *input = kmalloc(sizeof(buf), GFP_KERNEL);
    char *opt = NULL;

    strcpy(input, buf);

    while ((opt= strsep(&input, " ")) != NULL) {
        if (!*opt)
            continue;

        if (!strncmp(opt, "w_phase=", 8)) {
            if(kstrtol(opt + 8, 10, (unsigned long*)&w_phase))
            	w_phase = 0;
        }

        if (!strncmp(opt, "r_phase=", 8)) {
            if(kstrtol(opt + 8, 10, (unsigned long*)&r_phase))
            	r_phase = 0;
        }
    }

    if (w_phase >= MAX_TUNING_STEP)
        w_phase = MAX_TUNING_STEP - 1;
    if (r_phase >= MAX_TUNING_STEP)
        r_phase = MAX_TUNING_STEP - 1;

    cr_maskl(EMMC_PLLPHASE_CTRL, PHASE_W_MASK, PHASE_W_SHT ,w_phase);
    cr_maskl(EMMC_PLLPHASE_CTRL, PHASE_R_MASK, PHASE_R_SHT, r_phase);

    return count;
}

DEVICE_ATTR(phase_tune, S_IRUGO | S_IWUSR,
            phase_tune_dev_show, phase_tune_dev_store);
static ssize_t
em_chk_mode_dev_show(struct device *dev, struct device_attribute *attr,
            char *buf)
{
    struct mmc_host * host = dev_get_drvdata(dev);
    struct mmc_card *card = NULL;
    int type;
    struct rtksd_host *sdport = NULL;
    u32 tmp1,tmp2;

    static const char *const card_type_tbl[5] = {
        "MMC ",
        "SD ",
        "SDIO ",
        "SD_COMBO ",
        "Unknow "
    };

    if(host && host->card){
        sdport = mmc_priv(host);
        card = host->card;
        type = card->type;
        if(type >3)
            type = 4;

        EM_ALERT("%s: new %s%s%s%s card(%dHz)[%dbit] at address %04x\n",
            mmc_hostname(host),
            mmc_card_uhs(host->card) ? "ultra high speed " :
            (mmc_card_hs(host->card) ? "high speed " : ""),
            mmc_card_hs400(host->card) ? "HS400 " :
            (mmc_card_hs200(host->card) ? "HS200 " : ""),
            mmc_card_ddr52(host->card) ? "DDR " : "",
            card_type_tbl[type],
            sdport->cur_clock,
            sdport->cur_width,
            host->card->rca);

    }

    EM_ALERT("MMC PLL:\n"
            "   0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n"
            "   0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n"
            "   0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x 0x%08x=0x%08x\n",
            0xb8000700,(u32)cr_readl(0xb8000700),0xb8000704,(u32)cr_readl(0xb8000704),
            0xb8000708,(u32)cr_readl(0xb8000708),0xb800070c,(u32)cr_readl(0xb800070c),
            0xb8000710,(u32)cr_readl(0xb8000710),0xb8000714,(u32)cr_readl(0xb8000714),
            0xb8000718,(u32)cr_readl(0xb8000718),0xb800071c,(u32)cr_readl(0xb800071c),
            0xb8000720,(u32)cr_readl(0xb8000720),0xb8000724,(u32)cr_readl(0xb8000724),
            0xb8000728,(u32)cr_readl(0xb8000728),0xb800072c,(u32)cr_readl(0xb800072c));

    tmp1 = (u32)cr_readl(0xb8000700);
    tmp2 = (u32)cr_readl(0xb8000720);
    EM_ALERT("CP=0x%x CS=0x%x RS=0x%x\n",((tmp1>>29)&0x01),((tmp1>>27)&0x03),((tmp1>>24)&0x7));
    EM_ALERT("DIV2=0x%x PLLSSI=0x%x PLLSN=0x%x\n",((tmp1>>17)&0x01),((tmp1>>12)&0x1f),((tmp1>>8)&0x7));
    EM_ALERT("NCODE_T=0x%x FCODE_T=0x%x\n",((tmp2>>16)&0xff),((tmp2>>0)&0x7ff));

    return sprintf(buf, "%s\n",__func__);
}

static ssize_t
em_chk_mode_dev_store(struct device *dev,
            struct device_attribute *attr,
            const char *buf, size_t count)
{
    EM_ALERT("%s(%u)\n", __func__, __LINE__);
    EM_ALERT("%s\n", buf);
    EM_ALERT("count=%d\n", count);

    /*
    return value must be equare or big then "count"
    to finish this attribute
    */
    return count;
}

DEVICE_ATTR(em_chk_mode, S_IRUGO | S_IWUSR,
        em_chk_mode_dev_show,em_chk_mode_dev_store);


/************************************************************************
 *
 ************************************************************************/
static
int rtkemmc_boot_type_getting(void)
{
    int err = 0;
    unsigned char *cr_param = NULL;

    cr_param =
        (char *)rtkcr_parse_token(platform_info.system_parameters,
                      "boot_flash");

    if(cr_param == NULL){
        EM_INFO
            ("[Warning]Can't get boot type!eMMC driver init continue....\n");
    }else{
        if(memcmp(cr_param,"emmc",strlen(cr_param))!=0){
            EM_INFO("Boottype %s!eMMC flash driver init exit....\n",
                   cr_param);
            err = -1;
        }else{
            EM_INFO("Boottype %s!eMMC driver init continue....\n",
                   cr_param);
        }
    }

    if(cr_param)
        kfree(cr_param);

    return err;

}

/************************************************************************
 *
 ************************************************************************/

static void rtkemmc_parse_pad_drv(struct rtksd_host * rtk_priv, char *drv_str)
{
    char *tmp;
    char *tmp_drv_str = drv_str;
    unsigned int driving = 0;
    int i=0;

    if (!rtk_priv)
        return;

    rtk_priv->mmc_io_drv = kmalloc(sizeof(u32)*5, GFP_KERNEL); // 5 param at most
    if (rtk_priv->mmc_io_drv == NULL) {
        EM_ALERT("No mem can be allocated\n");
        return;
    }

    for (i=0; i<5; i++)
        rtk_priv->mmc_io_drv[i] =  (IO_PAD_8A0_HS400);

    for (i=0; i<5; i++) {
        tmp = strsep(&tmp_drv_str, ",");
        //if (tmp == NULL || tmp == "\0")
		if (tmp == NULL)
            continue;
        if (!kstrtol(tmp, 16, (unsigned long*)&driving))
            rtk_priv->mmc_io_drv[i] = driving;
    }

    EM_NOTICE("\n");
    for (i=0; i<5; i++)
        EM_NOTICE("mmc_io_drv[%d] = 0x%08x, ", i, rtk_priv->mmc_io_drv[i]);
    EM_NOTICE("\n");
}

static int rtkemmc_parse_mmc_param(struct rtksd_host *sdport)
{
    char *opt = NULL;
    char *platform_mmc_param = NULL;

    unsigned int dstune = 0;
    unsigned int card_drv = 0;
    unsigned int burst_blk = 0;
    char *str_tmp;

    if (platform_info.mmc_param == NULL) {
        EM_INFO("=== NO MMC PARAMETER in bootloader===\n");
        return 0;
    }

    if (!sdport) {
        EM_ERR("%s rtkemmc initial error\n", __FUNCTION__);
        return -1;
    }

    EM_NOTICE("=== mmc_param is %s ===\n", platform_info.mmc_param);
    platform_mmc_param = platform_info.mmc_param;

    while ((opt= strsep(&platform_mmc_param, " ")) != NULL) {
        if (!*opt)
            continue;

        if (!strncmp(opt, "emmc_open_log", 13)) {
            sdport->rtflags |= RTKCR_FOPEN_LOG;
        }
        else if (!strncmp(opt, "emmc_width=", 11)) {
            if (kstrtol(opt + 11, 10, (unsigned long*)&rtk_emmc_bus_wid))
                rtk_emmc_bus_wid = 0;
            else {
                printk("width %d ", rtk_emmc_bus_wid);
            }

            switch (rtk_emmc_bus_wid)
            {
                case 1:
                    sdport->mmc->caps &= ~MMC_CAP_8_BIT_DATA;
                    sdport->mmc->caps &= ~MMC_CAP_4_BIT_DATA;
                    break;
                case 4:
                    sdport->mmc->caps &= ~MMC_CAP_8_BIT_DATA;
                    sdport->mmc->caps |= MMC_CAP_4_BIT_DATA;
                    break;
                default:
                    sdport->mmc->caps |= MMC_CAP_8_BIT_DATA;
                    sdport->mmc->caps |= MMC_CAP_4_BIT_DATA;
            }
        }
        else if (!strncmp(opt, "emmc_clock=", 11)) {
            if (kstrtol(opt + 11, 10, (unsigned long*)&rtk_emmc_bus_clock))
                rtk_emmc_bus_clock = 0;
            else {
                EM_NOTICE("emmc_clock %d ", rtk_emmc_bus_clock);
                // check clock > 200MHz?
                if (rtk_emmc_bus_clock > 200000000)
                    rtk_emmc_bus_clock = 200000000;

                sdport->mmc->f_max = rtk_emmc_bus_clock;
            }
        }
        else if (!strncmp(opt, "dstune=", 7)) {
            if (kstrtol(opt + 7, 10, (unsigned long*)&dstune))
                dstune = 0;
            else {
                sdport->mmc_dstune = dstune;
                EM_NOTICE("dstune %d\n", dstune);
                rtk_emmc_test_ctl |= EMMC_FIX_DSTUNE;
            }
        }
        else if (!strncmp(opt, "pad_drv=", 8)) {
            str_tmp = strsep(&opt, "=");
            EM_NOTICE("\ndebug {str_tmp %s} {opt %s} \n", str_tmp, opt);
            rtkemmc_parse_pad_drv(sdport, opt);
            rtk_emmc_test_ctl |= EMMC_EN_IO_DRV;
        }
        else if (!strncmp(opt, "card_drv=", 9)) {
            if (kstrtol(opt + 9, 10, (unsigned long*)&card_drv))
                card_drv = 0;
            else {
                sdport->mmc_drv = card_drv;
                EM_NOTICE("card_drv 0x%x ", sdport->mmc_drv);
                // check card_drv 0x0 ~ 0x4
                if (sdport->mmc_drv > 0x4 ||
                    sdport->mmc_drv < 0x0 )
                    sdport->mmc_drv = 0x0; // default card driving
                rtk_emmc_test_ctl |= EMMC_EN_MMC_DRV;
            }
        }
        else if (!strncmp(opt, "burst_blk=", 10)) {
            if (kstrtol(opt + 10, 10, (unsigned long*)&burst_blk))
                burst_blk = 0;
            else {
                EM_NOTICE("burst_blk %d", burst_blk);
                sdport->mmc->max_blk_count = burst_blk;
            }
        }
        else if (!strncmp(opt, "emmc_dis_sscg", 13)) {
            rtk_emmc_test_ctl |= EMMC_DIS_SSCG;
        }
        else if (!strncmp(opt, "emmc_always_clk", 15)) {
            rtk_emmc_test_ctl |= EMMC_ALWAYS_CLK;
        }
        else if (!strncmp(opt, "emmc_en_hs50", 13)){
            sdport->mmc->caps2 &= ~(MMC_CAP2_HS200_1_8V_SDR
                    | MMC_CAP2_HS400_1_8V);
            EM_ALERT("bootcode select HS50 mode\n");
        }
        else if (!strncmp(opt, "emmc_en_hs200", 13)){
            sdport->mmc->caps2 &= ~(MMC_CAP2_HS200_1_8V_SDR
                    | MMC_CAP2_HS400_1_8V);
            sdport->mmc->caps2 |= MMC_CAP2_HS200_1_8V_SDR;
            EM_ALERT("bootcode select HS200 mode\n");
        }
        else if (!strncmp(opt, "emmc_en_hs400", 13)) {
            sdport->mmc->caps2 &= ~(MMC_CAP2_HS200_1_8V_SDR
                    | MMC_CAP2_HS400_1_8V);
            sdport->mmc->caps2 |= (MMC_CAP2_HS200_1_8V_SDR
                        | MMC_CAP2_HS400_1_8V);
            EM_ALERT("bootcode select HS400 mode\n");
        }
        else if (!strncmp(opt, "emmc_skip_tune", 14)) {
            rtk_emmc_test_ctl |= EMMC_SKIP_TUNE;
        }
        else if (!strncmp(opt, "emmclog=", 8)) {
            /*
            For customer request, valid value from 0~15(0xf).
            1. without emmclog or emmclog=0, disable message function.
            2. emmclog=1, enable message for this request.
            3. emmclog=other_value , for future request.
             */
            if (kstrtol(opt + 8, 10, (unsigned long*)&rtk_emmc_log_state))
                rtk_emmc_log_state = 0;
            else {
                sdport->log_state = rtk_emmc_log_state;
                EM_ERR("log_state is %u\n",sdport->log_state);
            }
        }
    }

    EM_NOTICE("\n");
    return 0;
}

static
struct rtk_host_ops emmc_ops = {
    .func_irq       = NULL,
    .re_init_proc   = NULL,
    .card_det       = NULL,
    .card_power     = NULL,
    .chk_card_insert= rtkem_chk_card_insert,
    .set_crt_muxpad = NULL,
    .set_clk        = dw_em_set_clk,
    .set_bits       = dw_em_set_bits,
    .set_DDR        = dw_em_set_DDR,
    .reset_card     = dw_em_reset_card,
    .reset_host     = dw_em_reset_host,
    .set_IO_driving = dw_em_set_IO_driving,
    .bus_speed_down = dw_em_bus_speed_down,
    .get_cmdcode    = NULL,
    .get_r1_type    = NULL,
    .chk_cmdcode    = NULL,
    .chk_r1_type    = NULL,
    .hold_card      = rtkem_hold_card,
};

/************************************************************************
 *
 ************************************************************************/
static
int __init rtkemmc_probe(struct platform_device *pdev)
{
    struct mmc_host *mmc = NULL;
    struct rtksd_host *sdport = NULL;
    struct resource *r;
    int ret, irq;
    int att_err;

    /* check if emmc BOOT */
    if(rtkemmc_boot_type_getting()){
        EM_NOTICE("%s: It's not eMMC boot type!\n", DRIVER_NAME);
        return -ENXIO;
    }
    att_err = device_create_file(&pdev->dev, &dev_attr_cr_fast_RW);
    att_err = device_create_file(&pdev->dev, &dev_attr_em_open_log);
    att_err = device_create_file(&pdev->dev, &dev_attr_em_chk_mode);
    att_err = device_create_file(&pdev->dev, &dev_attr_emmc_errcnt);
    att_err = device_create_file(&pdev->dev, &dev_attr_phase_tune);
#ifdef CONFIG_MMC_RTKEMMC_HK_ATTR
    att_err = device_create_file(&pdev->dev, &dev_attr_emmc_hacking);
#endif

#ifdef CONFIG_REALTEK_OF
    {
        u32 of_irq = 0;
        struct resource of_reg_res;

        of_irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
        //irq = (int)of_irq;
        irq = IRQ_GET_KERNEL_IRQ_NUM(50); //for initial only
        EM_INFO("%s: IRQ %u\n", pdev->dev.of_node->name, irq);

        if (of_address_to_resource(pdev->dev.of_node, 0, &of_reg_res)) {
            return -ENXIO;
        }
        r = request_mem_region(of_reg_res.start, resource_size(&of_reg_res),
                       pdev->dev.of_node->name);
        if (!r) {
            return -ENXIO;
        }
    }
#else
    r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
    irq = platform_get_irq(pdev, 0);
    EM_INFO("%s: IRQ %u\n", DRIVER_NAME, irq);

    if (!r || irq < 0){
        return -ENXIO;
    }
    r = request_mem_region(r->start, ((r->end) - (r->start) + 1),
                   DRIVER_NAME);
    if (!r){
        return -EBUSY;
    }
#endif

    mmc = mmc_alloc_host(sizeof(struct rtksd_host), &pdev->dev);

    if (!mmc) {
        ret = -ENOMEM;
        goto out;
    }

    mmc_host_local = mmc;

    sdport = mmc_priv(mmc);
    memset(sdport, 0, sizeof(struct rtksd_host));

    sdport->mmc = mmc;
    sdport->dev = &pdev->dev;
    sdport->res = r;
    sdport->ops = &emmc_ops;

    /* Right now device-tree probed devices don't get dma_mask set.
         * we check here
         */
    if (!pdev->dev.dma_mask)
        pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
        if (!pdev->dev.coherent_dma_mask)
        pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);

    mmc->ocr_avail = MMC_VDD_30_31 | MMC_VDD_31_32
        | MMC_VDD_32_33 | MMC_VDD_33_34 | MMC_VDD_165_195;

    mmc->caps = MMC_CAP_ERASE
          | MMC_CAP_HW_RESET
          | MMC_CAP_4_BIT_DATA
          | MMC_CAP_8_BIT_DATA
          | MMC_CAP_SD_HIGHSPEED
          | MMC_CAP_MMC_HIGHSPEED | MMC_CAP_NONREMOVABLE
          | MMC_CAP_CMD23

            ;
	mmc->caps2 = 0
#ifdef EN_EMMC_HS200
		| MMC_CAP2_HS200_1_8V_SDR
#endif

#ifdef EN_EMMC_HS400
		| MMC_CAP2_HS400_1_8V
#endif
	;
#if defined(CONFIG_RTKEMMC_HS200) || defined(CONFIG_RTKEMMC_HS400)
    /* use config setting */
        mmc->f_max = (CONFIG_RTKEMMC_HS200_CLOCK*1000000);
#else
    mmc->f_max = CLK_50Mhz;    /* RTK max bus clk is 50Mhz */
#endif
    /* check mmc parameter from bootcode  */
    ret = rtkemmc_parse_mmc_param(sdport);
    if (ret) {
        EM_ERR("parse mmc parameter fail\n");
    }
    mmc->f_min = CLK_200Khz;        /* follow lowest clock 100KHz according spec, but we set to 200KHz*/

    mmc->max_segs       = 128;
    mmc->max_blk_size   = 512;

    if(rtk_emmc_test_ctl & EMMC_BURST_BLK){
        mmc->max_blk_count  = sdport->mmc_burst_blk;
        EM_WARNING("%s(%d)Use Bootcode pre-setting parameter\n",__func__,__LINE__);
        EM_WARNING("    max_blk_count=0x%x\n",mmc->max_blk_count);
    }else{
        //mmc->max_blk_count  = (EMMC_MAX_SCRIPT_LINE * EMMC_MAX_SCRIPT_BLK);
        mmc->max_blk_count  = 1024;
    }
    mmc->max_seg_size   = mmc->max_blk_size * mmc->max_blk_count;
    mmc->max_req_size   = mmc->max_blk_size * mmc->max_blk_count;

    spin_lock_init(&sdport->lock);
    tasklet_init(&sdport->req_end_tasklet, rtkcr_req_end_tasklet,
                (unsigned long)sdport);
    tasklet_init(&sdport->polling_tasklet, rtkem_polling_tasklet,
                (unsigned long)sdport);

    sdport->base = ioremap(r->start, 0x000003F0);

//#define ALEXKH_TEST
#ifdef ALEXKH_TEST
    {
        sdport->rtflags |= RTKCR_FOPEN_LOG;
    }
#endif

    if (!sdport->base) {
        ret = -ENOMEM;
        goto out;
    }

    ret = request_irq(irq, dw_em_irq, IRQF_SHARED, DRIVER_NAME, sdport);
    if (ret) {
        EM_ERR( "%s: cannot assign irq %d\n", DRIVER_NAME, irq);
        goto out;
    } else{
        sdport->irq = irq;
    }


    dw_em_chk_shoutdown_protect(sdport);

    setup_timer(&sdport->timer, rtksd_timeout_timer, (unsigned long)sdport);

    rtkem_clr_sta(sdport);
    sdport->ops->chk_card_insert(sdport);

    /*
     * The scripter are 16 bytes per line,
     * So we need Scripter POOL size is 4096(EMMC_MAX_SCRIPT_LINE*16)
     */
    sdport->scrip_pool = dma_pool_create(DRIVER_NAME, sdport->dev,
                         (EMMC_SCRIPT_BUF_SIZE), 16384,
                         16384);
    if(!(sdport->scrip_pool)){
        EM_INFO( "%s: request Scripter Pool faill!\n",
               DRIVER_NAME);
        ret = -ENOMEM;
        goto out;
    }

    sdport->scrip_buf = dma_pool_alloc(sdport->scrip_pool,GFP_KERNEL ,
                     &sdport->scrip_buf_phy);
    if(!(sdport->scrip_buf)){
        EM_INFO( "%s: request Scripter Buffer fail!\n",
               DRIVER_NAME);
        dma_pool_destroy(sdport->scrip_pool);
        ret = -ENOMEM;
        goto out;
    }
    dw_em_set_scrip_base(sdport->scrip_buf_phy);

    platform_set_drvdata(pdev, mmc);

    ret = mmc_add_host(mmc);
    if (ret){
        goto out;
    }

#ifdef CONFIG_CUSTOMER_TV006
    device_enable_async_suspend(&pdev->dev);
#endif

    EM_NOTICE( "%s: %s driver initialized\n",
               mmc_hostname(mmc), DRIVER_NAME);

    return 0;

out:
    if (sdport) {
        if (sdport->irq)
            free_irq(sdport->irq, sdport);

        if (sdport->base)
            iounmap(sdport->base);

    }
    if (r)
        release_resource(r);
    if (mmc)
        mmc_free_host(mmc);

    return ret;
}

/************************************************************************
 *
 ************************************************************************/
static
int __exit rtkem_remove(struct platform_device *pdev)
{
    struct mmc_host *mmc = platform_get_drvdata(pdev);

    device_remove_file(&pdev->dev, &dev_attr_cr_fast_RW);
    device_remove_file(&pdev->dev, &dev_attr_em_open_log);
    device_remove_file(&pdev->dev, &dev_attr_em_chk_mode);
    device_remove_file(&pdev->dev, &dev_attr_emmc_errcnt);
    device_remove_file(&pdev->dev, &dev_attr_phase_tune);
#ifdef CONFIG_MMC_RTKEMMC_HK_ATTR
    device_remove_file(&pdev->dev, &dev_attr_emmc_hacking);
#endif

    if (mmc) {
        struct rtksd_host *sdport = mmc_priv(mmc);

        flush_scheduled_work();
        tasklet_kill(&sdport->polling_tasklet);
        tasklet_kill(&sdport->req_end_tasklet);
        mmc_remove_host(mmc);
        if(!mmc){
            EM_NOTICE("eMMC host have removed.\n");
            mmc_host_local = NULL;
        }

        if(sdport->scrip_buf)
            dma_pool_free(sdport->scrip_pool, sdport->scrip_buf,
                         sdport->scrip_buf_phy);
        if(sdport->scrip_pool)
            dma_pool_destroy(sdport->scrip_pool);

        free_irq(sdport->irq, sdport);

        del_timer_sync(&sdport->timer);
        iounmap(sdport->base);

        release_resource(sdport->res);
        mmc_free_host(mmc);
    }
    platform_set_drvdata(pdev, NULL);
    return 0;
}

#ifdef CONFIG_PM
/************************************************************************
 *
 ************************************************************************/
static
int rtkem_suspend(struct platform_device *dev, pm_message_t state)
{
    struct mmc_host *mmc = platform_get_drvdata(dev);
    int ret = 0;

    EM_NOTICE( "%s: Prepare to suspend...\n", DRIVER_NAME);

#ifdef CONFIG_RTKEMMC_COWORK_WITH_KCPU
#ifndef CONFIG_RTK_KDRV_OPENBSD
    if(mmc_pm_sync_addr != 0){
        int log_flag = 0;
        pr_notice("wait kcpu emmc suspend ,share memory(0x%x)=0x%x...\n", \
            mmc_pm_sync_addr,*((volatile unsigned int *)mmc_pm_sync_addr));
        // polling kcpu emmc suspend done
        while(*((volatile unsigned int *)mmc_pm_sync_addr) != KCPU_EMMC_DEVICE_SUSPEND_DONE){
            if (log_flag == 0){
                pr_notice("wait kcpu emmc suspend done ...\n");
                log_flag++;
            }else{
                udelay(10);
            }
        }
        // clear share memory
        *((volatile unsigned int *)mmc_pm_sync_addr) = 0x0;
        pr_notice("kcpu emmc suspend ...done\n");
    }
#endif
#endif

    if (mmc){
        struct rtksd_host *sdport = mmc_priv(mmc);

        flush_scheduled_work();

        tasklet_kill(&sdport->polling_tasklet);
        tasklet_kill(&sdport->req_end_tasklet);
        /* should turn of plug timer */
        del_timer_sync(&sdport->timer);

        sdport->rtflags &= ~RTKCR_FCARD_DETECTED;

        EM_NOTICE( "%s: record:  r_phase=%d ds_tune=%d\n",
            DRIVER_NAME,sdport->pre_r_phase ,sdport->pre_ds_tune);

    }

    /* reset eMMC flow */
    EM_NOTICE( "%s: Holding eMMC reset pin...\n", DRIVER_NAME);
    if (mmc){
        struct rtksd_host *sdport = mmc_priv(mmc);
        rtkem_hold_card(sdport);
    }
    return ret;
}

/************************************************************************
 *
 ************************************************************************/
static
int rtkem_clr_sta(struct rtksd_host *sdport)
{
    sdport->cur_clock   = 0;
    sdport->cur_width   = 0;
    sdport->cur_PLL     = 0;
    sdport->cur_div     = 0;
    sdport->cur_w_phase = 0;
    sdport->cur_w_ph400 = 0;
    sdport->cur_r_phase = 0xff;
    sdport->cur_ds_tune = 0;

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
int rtkem_resume(struct platform_device *dev)
{
    struct mmc_host *mmc = platform_get_drvdata(dev);
    unsigned long flags;
    int ret = 0;

    EM_NOTICE( "%s: wake up to resume...\n", DRIVER_NAME);

    if (mmc){
        struct rtksd_host *sdport = mmc_priv(mmc);

        tasklet_init(&sdport->req_end_tasklet, rtkcr_req_end_tasklet,
                (unsigned long)sdport);
        tasklet_init(&sdport->polling_tasklet, rtkem_polling_tasklet,
                (unsigned long)sdport);

        rtkem_clr_sta(sdport);
        sdport->cur_ds_tune = sdport->pre_ds_tune;
        dw_em_crt_reset(sdport,0);

        /* enable PLL of eMMC */
        dw_em_set_PLL_clk(sdport,CLK_50Mhz,0,1);
        dw_em_init_phase(sdport,DEFAULT_W_PHASE,DEFAULT_R_PHASE,DEFAULT_C_PHASE); /* w_phase;r_phase */
        sdport->rtflags |= RTKCR_FCARD_DETECTED;

        dw_em_set_scrip_base(sdport->scrip_buf_phy);

        spin_lock_irqsave(&sdport->lock, flags);
        sdport->ins_event = EVENT_SKIP_PHASETUNE | EVENT_SKIP_DSTUNING;
        spin_unlock_irqrestore(&sdport->lock, flags);

        EM_NOTICE( "%s: read back:  r_phase=%d ds_tune=%d\n",
            DRIVER_NAME,sdport->cur_r_phase ,sdport->cur_ds_tune);

    }

    EM_NOTICE("%s: resume finish\n",DRIVER_NAME);
    return ret;
}
#else
#define rtkem_suspend   NULL
#define rtkem_resume    NULL
#endif

#ifdef CONFIG_REALTEK_OF
static const struct of_device_id of_rtkemmc_ids[] = {
    { .compatible = "realtek,rtk-emmc" },
    {}
};

MODULE_DEVICE_TABLE(of, of_rtkemmc_ids);
#endif
static
struct platform_driver rtkemmc_driver = {
    .driver     = {
        .name   = DRIVER_NAME,
        .owner  = THIS_MODULE,
#ifdef CONFIG_REALTEK_OF
        .of_match_table = of_rtkemmc_ids,
#endif
    },
    .remove     = __exit_p(rtkem_remove),
    .suspend    = rtkem_suspend,
    .resume     = rtkem_resume,

};

/************************************************************************
 *
 ************************************************************************/
static
void rtkcr_display_version (void)
{
    const __u8 *revision;
    const __u8 *date;
    const __u8 *time;
    char *running = (__u8 *)VERSION;

    strsep(&running, " ");
    strsep(&running, " ");
    revision = strsep(&running, " ");
    date = strsep(&running, " ");
    time = strsep(&running, " ");
    EM_NOTICE(BANNER " Rev:%s (%s %s)\n", revision, date, time);
// fix compile error because kernel enable option "-Werror=date-time"
//  EM_NOTICE("%s: build at %s %s\n", DRIVER_NAME, __DATE__, __TIME__);

#ifdef CONFIG_MMC_BLOCK_BOUNCE
    EM_NOTICE("%s: CONFIG_MMC_BLOCK_BOUNCE enable\n", DRIVER_NAME);
#endif

}

/************************************************************************
 *
 ************************************************************************/
static
int dw_em_set_bus_width(char *buf)
{
    /*
    get eMMC bus width setting by bootcode parameter, like below
    bootargs=console=ttyS0,115200 earlyprintk emmc_bus=8
    the keyword is "emmc_bus"
    example:
        emmc_bus=8
    */

    rtkcr_chk_param(&rtk_emmc_bus_wid,8,buf+1);
    EM_NOTICE("************************************************\n");
    EM_NOTICE("%s:Bootcode setting bus func is 0x%x\n",
                DRIVER_NAME,rtk_emmc_bus_wid);

    /* Pre-enable eMMC log of Kernel */
    if(rtk_emmc_bus_wid & EMMC_OPEN_LOG){
        EM_NOTICE("    enable eMMC log.\n");
    }
    /* disable 4bit mode */
    if(rtk_emmc_bus_wid & EMMC_DIS_4BITS){
        EM_NOTICE("    disable 4bit mode.\n");
    }
    /* disable 8bit mode */
    if(rtk_emmc_bus_wid & EMMC_DIS_8BITS){
        EM_NOTICE("    disable 8bit mode.\n");
    }
    /* disable HS200 */
    if(rtk_emmc_bus_wid & EMMC_DIS_HS200){
        EM_NOTICE("    disable HS200 mode.\n");
    }
    /* disable HS400 */
    if(rtk_emmc_bus_wid & EMMC_DIS_HS400){
        EM_NOTICE("    disable HS400 mode.\n");
    }

    return 0;
}

/************************************************************************
 *
 ************************************************************************/
static int rtkem_h2d(u32 value){
    int i,j;
    u32 pow;
    u32 tmp1,tmp2;
    u32 mask,sht;

    tmp2 = 0;
    pow  = 0;

    for(i=0;i<8;i++){
        sht = (i*4);
        mask = (0xfUL<<sht);
        tmp1 = (value & mask) >> sht;
        if(tmp1>9){
            return -1;
        }

        for(j=0;j<(i+1);j++){
            if(j==0)
                pow = 1;
            else
                pow = pow*10;
        }

        tmp1 = tmp1 * pow;
        tmp2 += tmp1;
        }

    return tmp2;
    }

/************************************************************************
 *
 ************************************************************************/
static int dw_em_set_bus_clock(char *buf)
{
    u32 tmp2;

    /*
    To get eMMC clock setting by bootcode parameter, like below
    bootargs=console=ttyS0,115200 earlyprintk emmc_clock=200
    The keyword is "emmc_colck"
    The getted parameter is hex, It's will be translated to Oct.
    example:
        emmc_clock=200 <==200Mhz
    */
    EM_NOTICE("************************************************\n");
    rtkcr_chk_param(&rtk_emmc_bus_clock,3,buf+1);

    tmp2 = rtkem_h2d(rtk_emmc_bus_clock);

    if((tmp2 > 200) | (tmp2 < 10)){
        rtk_emmc_bus_clock = 0;
        EM_NOTICE("parameter not support!\n");
    }else{
        rtk_emmc_bus_clock = tmp2;
    }

    EM_NOTICE("%s:Bootcode setting bus clock is %dMhz\n",
        DRIVER_NAME,rtk_emmc_bus_clock);
    return 0;
}


static int dw_em_log_func(char *buf)
{
    /*
     For customer request, valid value from 0~15(0xf).
      1. without emmclog or emmclog=0, disable message function.
      2. emmclog=1, enable message for this request.
      3. emmclog=other_value , for future request.
     */
    rtkcr_chk_param(&rtk_emmc_log_state,1,buf+1);
    EM_NOTICE("************************************************\n");
    EM_NOTICE("%s:Bootcode setting emmc_log func is %u\n",
                DRIVER_NAME,rtk_emmc_log_state);
    return 0;
}

static
int __init rtkemmc_init(void)
{
    int rc = 0;

    rtkcr_display_version();

#ifdef CONFIG_ANDROID
    EM_NOTICE( "%s: Android timming setting\n", DRIVER_NAME);
#endif

    rc = platform_driver_probe(&rtkemmc_driver, rtkemmc_probe);

    if (rc < 0){
        EM_NOTICE( "Realtek EMMC Controller Driver installation fails.\n\n");
        return -ENODEV;
    }else{
        EM_NOTICE( "Realtek EMMC Controller Driver is successfully installing.\n\n");
        return 0;
    }
}

static
void __exit rtkemmc_exit(void)
{
    platform_driver_unregister(&rtkemmc_driver);
}

/* allow emmc driver initialization earlier */
#ifdef CONFIG_RTKEMMC_COWORK_WITH_KCPU
/* if rpc driver initial early than mmc driver, we will cancel this modify*/
module_init(rtkemmc_init);
#else
fs_initcall(rtkemmc_init);          //5
#endif
module_exit(rtkemmc_exit);

/* maximum card clock frequency (default 50MHz) */
module_param(maxfreq, int, 0);

/* force PIO transfers all the time */
module_param(nodma, int, 0);

MODULE_AUTHOR("Elbereth");
MODULE_DESCRIPTION("Realtek EMMC Host Controller driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:rtkemmc");

__setup("emmc_bus",dw_em_set_bus_width);
__setup("emmc_clock",dw_em_set_bus_clock);
__setup("emmc_log",dw_em_log_func);


