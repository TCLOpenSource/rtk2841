/*
 *  Copyright (C) 2010 Realtek Semiconductors, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __RTKSDIO_H
#define __RTKSDIO_H

#ifdef CONFIG_RTK_KDRIVER_SUPPORT
#include <rtk_kdriver/rtk_crt.h>
#else
#include <mach/rtk_crt.h>
#endif
#include <mach/io.h>
#include "rtkemmc_dbg.h"
#include "rtksdio_dbg.h"

/* Bit DEfine */
#define _BIT0   (0x01UL<<0)
#define _BIT1   (0x01UL<<1 )
#define _BIT2   (0x01UL<<2 )
#define _BIT3   (0x01UL<<3 )
#define _BIT4   (0x01UL<<4 )
#define _BIT5   (0x01UL<<5 )
#define _BIT6   (0x01UL<<6 )
#define _BIT7   (0x01UL<<7 )
#define _BIT8   (0x01UL<<8 )
#define _BIT9   (0x01UL<<9 )
#define _BIT10  (0x01UL<<10)
#define _BIT11  (0x01UL<<11)
#define _BIT12  (0x01UL<<12)
#define _BIT13  (0x01UL<<13)
#define _BIT14  (0x01UL<<14)
#define _BIT15  (0x01UL<<15)
#define _BIT16  (0x01UL<<16)
#define _BIT17  (0x01UL<<17)
#define _BIT18  (0x01UL<<18)
#define _BIT19  (0x01UL<<19)
#define _BIT20  (0x01UL<<20)
#define _BIT21  (0x01UL<<21)
#define _BIT22  (0x01UL<<22)
#define _BIT23  (0x01UL<<23)
#define _BIT24  (0x01UL<<24)
#define _BIT25  (0x01UL<<25)
#define _BIT26  (0x01UL<<26)
#define _BIT27  (0x01UL<<27)
#define _BIT28  (0x01UL<<28)
#define _BIT29  (0x01UL<<29)
#define _BIT30  (0x01UL<<30)
#define _BIT31  (0x01UL<<31)

typedef void (*set_gpio_func_t)(u32 gpio_num,u8 ctl);


/* all error bit define at "Device Status". */
#define RESP_ERR_BIT    ( _BIT31|_BIT30|_BIT29|_BIT28|   \
              _BIT27|_BIT26|_BIT24|_BIT23|   \
              _BIT22|_BIT21|_BIT20|_BIT19|   \
              _BIT16|_BIT15|_BIT13|_BIT7  )

/* fatal error, if these bits alert the command should skip retry. not figure out yet. */
#define RESP_ERR_FATAL  ( _BIT31|_BIT30|_BIT29|_BIT28|   \
              _BIT27|_BIT26|_BIT24|_BIT23|   \
              _BIT22|_BIT21|_BIT20|_BIT19|   \
              _BIT16|_BIT15|_BIT13|_BIT7  )

/*
 * Clock rates
 */
#define RTKSD_CLOCKRATE_MAX         50000000
#define RTKSD_BASE_DIV_MAX          0x100

#define tmp_readl(offset)        (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(offset))

#define tmp_writel(val, offset)  (*(volatile unsigned int *)GET_MAPPED_RBUS_ADDR(offset) = val); \
                                  wmb()

static inline unsigned int cr_readl(__u32 __iomem  regs)
{
    dmb(sy);
    return tmp_readl(regs);
}

static inline void cr_writel(const unsigned int val, __u32 __iomem regs)
{
    dmb(sy);
    tmp_writel(val, regs);
}

static inline unsigned int scrt_readl(__u32 __iomem  regs)
{
    unsigned int regval;

    //hw_semaphore_try_lock();
    dmb(sy);
    regval = tmp_readl(regs);
    //hw_semaphore_unlock();
    return regval;
}

static inline void scrt_writel(const unsigned int val, __u32 __iomem regs)
{
    //hw_semaphore_try_lock();
    dmb(sy);
    tmp_writel(val, regs);
    //hw_semaphore_unlock();
}

static inline void reg_maskl(const unsigned int mask,
                const unsigned int val, __u32 __iomem regs)
{
    cr_writel((cr_readl(regs) & ~mask) | val,regs);
}

#define CLEAR_CR_CARD_STATUS(reg_addr)      \
do {                                \
    cr_writel(0xffffffff, reg_addr);    \
} while (0)

#define CLEAR_ALL_CR_CARD_STATUS(io_base)        \
do {                                \
    int i = 0;  \
    for(i=0; i<5; i++)  \
        CLEAR_CR_CARD_STATUS(io_base+20+ (i*4));  \
} while (0)

/*  ===== macros and funcitons for Realtek CR ===== */
/* for SD/MMC usage */
#define ON                      0
#define OFF                     1

#define GPIO_H      (0x1<<0)
#define GPIO_L      (0)
#define DIR_OUT     (0x1<<1)
#define DIR_IN      (0)
#define DIR_SKIP    (0x6<<1)
#define MUX_SKIP    (0x7<<1)
#define ISO_FLAG    (0x800UL)

/* MMC response type */
#define SD_R0                   (RESP_TYPE_NON|CRC7_CHK_DIS)
#define SD_R1                   (RESP_TYPE_6B)
#define SD_R1b                  (RESP_TYPE_6B)
#define SD_R2                   (RESP_TYPE_17B)
#define SD_R3                   (RESP_TYPE_6B|CRC7_CHK_DIS)
#define SD_R4                   (RESP_TYPE_6B)
#define SD_R5                   (RESP_TYPE_6B)
#define SD_R6                   (RESP_TYPE_6B)
#define SD_R7                   (RESP_TYPE_6B)
#define SD_R_NO                 (0xFF)

/* rtflags */
#define RTKCR_FCARD_DETECTED    (1<<0)      /* Card is detected */
#define RTKCR_FOPEN_LOG         (1<<1)      /* open command log */
#define RTKCR_USER_PARTITION    (1<<2)      /* card is working on normal partition */
#define RTKCR_IDENT_STATE       (1<<3)      /* card is identification mode */
#define RTKCR_FCARD_POWER       (1<<4)      /* Card is power on */
#define RTKCR_FHOST_POWER       (1<<5)      /* Host is power on */
#define RTKCR_TUNING_STATE      (1<<6)      /* Host is processing phase tuning */
#define RTKCR_RECOVER_STATE     (1<<7)      /* Host is processing recover flow */
#define RTKCR_FOPEN_INT         (1<<8)      /* open interrupt */
#define RTKCR_CMD23_ALERT       (1<<9)      /* Host is processing cmd23 flow */

#define MMC_EN_SSCG _BIT0

typedef struct  {
    u32                 ctl;
    u8                  ncode_t;
    u8                  sdiv2;
    u8                  r_phase;
    u8                  w_phase;
    u8                  icp;
    u8                  pi_isel;
    u8                  cs;
    u8                  cp;
    u8                  rs;
    u16                 ncode_ssc;
    u16                 fcode_ssc;
    u32                 range_ssc;
}mmc_param_t;


#define STATE_IDLE          0
#define STATE_SENDING_CMD   1
#define STATE_SENDING_DATA  2
#define STATE_DATA_BUSY     3
#define STATE_POST_POLLING  4
#define STATE_SENDING_STOP  5
#define STATE_DATA_ERROR    6
#define STATE_DATA_COMPLETE 7
#define STATE_WAIT_STOP     8
#define STATE_REQUEST_END   9

struct rtksd_host {
    struct mmc_host     *mmc;           /* MMC structure */
    struct mmc_command  *cmd;
    u32                 rtflags;        /* Driver states */
    u32                 log_state;        /* log_func state */
    u8                  ins_event;
    u8                  cmd_opcode;

#define EVENT_NON           0x00
#define EVENT_INSER         0x01
#define EVENT_REMOV         0x02
#define EVENT_USER          0x10
#define EVENT_SKIP_PHASETUNE (0x10)
#define EVENT_SKIP_DSTUNING  (0x20)
    u32                 cur_clock;
    u32                 cur_width;
    u32                 cur_PLL;
    u32                 cur_div;
    u8                  cur_w_phase;
    u8                  cur_w_ph400;
    u8                  cur_r_phase;
    u8                  cur_c_phase;
    u8                  tud_r_phase;
    u32                 tud_r_clock;
    u32                 cur_ds_tune;

    u8                  pre_r_phase;
    u32                 pre_ds_tune;
    void *              cur_host_status;
    u32                 mid;

    u8                  reset_event;
    struct mmc_request  *mrq;            /* Current request */
    u8                  wp;
    struct rtk_host_ops *ops;
    struct semaphore    sem;
    struct semaphore    sem_op_end;

    void __iomem        *base;
    u32 base_io;
    spinlock_t          lock;
    unsigned int        ns_per_clk;
    struct workqueue_struct *cr_workqueue;
    struct delayed_work cr_work;
    struct tasklet_struct req_end_tasklet;
    struct tasklet_struct polling_tasklet;
    struct sd_cmd_pkt   *cmd_info;
    struct sd_cmd_pkt   *stop_info;
    struct timer_list   timer;
    struct timer_list   plug_timer;
    struct completion   *int_waiting;
    struct device       *dev;
    struct resource     *res;
    int                 irq;
    u8                  *tmp_buf;
    dma_addr_t          tmp_buf_phy_addr;
    struct  dma_pool    *scrip_pool;
    u32                 *scrip_buf;
    dma_addr_t          scrip_buf_phy;

#ifdef MONI_MEM_TRASH
    u8                  *cmp_buf;
    dma_addr_t          phy_addr;
#endif

    u8                  pinmux_type;
    u32                 test_count;
    u32                 int_status;
    u32                 int_status_old;
    u32                 sd_status;
    u32                 sd_status2;
    u32                 sd_trans;
    u32                 wrap_sta;
    u32                 gpio_isr_info;
    u32                 task_state;
    u32                 tmout;

    /* for bootcode pre setting parameter *** */
    mmc_param_t *mmc_boot_param;
    u32 *mmc_io_drv;
    u32 mmc_drv;
    u32 mmc_dstune;
    u32 mmc_burst_blk;
    /* for bootcode pre setting parameter &&& */

    unsigned long       timeend;
};

struct rtk_host_ops {
    irqreturn_t (*func_irq)(int irq, void *dev);
    int (*re_init_proc)(struct mmc_card *card);
    int (*card_det)(struct rtksd_host *sdport);
    void (*card_power)(struct rtksd_host *sdport,u8 status);
    void (*chk_card_insert)(struct rtksd_host *rtkhost);
    void (*set_crt_muxpad)(struct rtksd_host *rtkhost);
    void (*set_clk)(struct rtksd_host *rtkhost,u32 mmc_clk);
    void (*reset_card)(struct rtksd_host *rtkhost);
    void (*reset_host)(struct rtksd_host *rtkhost,u8 save_en);
    void (*set_IO_driving)(struct rtksd_host *rtkhost,u32 type_sel);
    void (*bus_speed_down)(struct rtksd_host *sdport);
    u32 (*get_cmdcode)(u32 opcode );
    u32 (*get_r1_type)(u32 opcode );
    u32 (*chk_cmdcode)(struct mmc_command* cmd);
    u32 (*chk_r1_type)(struct mmc_command* cmd);
    void (*hold_card)(struct rtksd_host *sdport);
    int (*set_bits)(struct rtksd_host *sdport,u32 bus_wid);
    int (*set_DDR)(struct rtksd_host *sdport,u32 ddr_mode);
};

struct ms_cmd_pkt {
    struct rtksd_host   *sdport;
    struct ms_command   *mscmd;
    struct mmc_data     *data;

    unsigned char       *dma_buffer;    //data transfer address
    u16                 cmdcode;        //rtk ms operation code
    u16                 trans_bytes;    //register transfer bytes
    u16                 block_count;    //data block transfer count
};

struct sd_cmd_pkt {
    struct mmc_host     *mmc;       /* MMC structure */
    struct rtksd_host   *sdport;
    struct mmc_command  *sbc;    /* cmd->opcode; cmd->arg; cmd->resp; cmd->data */
    struct mmc_command  *cmd;
    struct mmc_command  *stop;
    struct mmc_data     *data;
    unsigned char       *dma_buffer;
    u16                 byte_count;
    u16                 block_count;
    u32                 total_byte_cnt;
    u32                 scrip_cnt;
    u32                 cmd_flag;
    u32                 cmdcode;
    u32                 flags;
    u8                  rsp_para;
    u8                  rsp_len;
    u32                 timeout;
};

/* *** Realtek CRT register *** */
#define EMMC_HW_SEMAPHORE       (0xB801A628)

#define RTK_SD_CLKSEL           SYS_REG_SYS_CLKSEL_reg
#define RTK_EM_DW_SRST          SYS_REG_SYS_SRST2_reg
#define RTK_EM_DW_CLKEN         SYS_REG_SYS_CLKEN2_reg
#define RTK_SD_SRST             SYS_REG_SYS_SRST3_reg
#define RTK_SD_CLKEN            SYS_REG_SYS_CLKEN3_reg

#define RSTN_EM_DW              (0x01UL<<23)
#define CLKEN_EM_DW             (0x01UL<<23)
#define RSTN_SD                 (0x01UL<<16)
#define CLKEN_SD                (0x01UL<<16)

#define CR_BASE_ADDR            0xb8010C00
#define EM_BASE_ADDR            0xb8010800

/* PLL and Phase relation */
#define EMMC_PLL_SET            0xb8000700
#define EMMC_PLL_CTRL           0xb8000704
#define EMMC_PLLPHASE_CTRL      0xb8000708
#define EMMC_PLL_PHASE_INTERPOLATION    0xb800070C
#define EMMC_PLL_SSC0           0xb8000710
#define EMMC_PLL_SSC1           0xb8000714
#define EMMC_PLL_SSC2           0xb8000718
#define EMMC_PLL_SSC3           0xb800071C
#define EMMC_PLL_SSC4           0xb8000720
#define EMMC_PLL_SSC5           0xb8000724
#define EMMC_PLL_SSC6           0xb8000728

#define MAX_TUNING_STEP         64
#define MAX_DS_TUNE             (32)
#define PHASE_W_SHT             0
#define PHASE_W_MASK            0x03fUL
#define PHASE_R_SHT             10
#define PHASE_R_MASK            0x03fUL
/* *** Realtek CRT register &&& */

#define DRIVING_COMMON  0
#define DRIVING_HS200   1
#define DRIVING_HS400   2

/* CRT_SYS_CLKSEL setting bit *** */
#define EMMC_SOURCECLKSEL_SHT       (27)
#define MASK_EMMC_SOURCECLKSEL      (0x03UL<<EMMC_SOURCECLKSEL_SHT)
#define RBUS_27MHZ_202M             (0x00UL<<EMMC_SOURCECLKSEL_SHT)
#define PLL2X_295M                  (0x01UL<<EMMC_SOURCECLKSEL_SHT)
#define PLLGPU2_HALF                (0x10UL<<EMMC_SOURCECLKSEL_SHT)

#define EMMC_CLKSEL_SHT             (12)
#define SD_CLKSEL_SHT               (20)

#define EMMC_CLKSEL_MASK            (0x07UL<<EMMC_CLKSEL_SHT)
#define SD_CLKSEL_MASK              (0x07UL<<SD_CLKSEL_SHT)
#define EMMC_CLOCK_SPEED_GAP        (CARD_SWITCHCLOCK_25MHZ<<EMMC_CLKSEL_SHT)
#define SD_CLOCK_SPEED_GAP          (CARD_SWITCHCLOCK_25MHZ<<SD_CLKSEL_SHT)

#define EMMC_CLOCK_450_SPEED_GAP    (CARD_SWITCHCLOCK_450_25MHZ<<EMMC_CLKSEL_SHT)
#define SD_CLOCK_450_SPEED_GAP      (CARD_SWITCHCLOCK_450_25MHZ<<SD_CLKSEL_SHT)


#define CARD_SWITCHCLOCK_75MHZ  (0x00UL)
#define CARD_SWITCHCLOCK_50MHZ  (0x01UL)
#define CARD_SWITCHCLOCK_37MHZ  (0x02UL)
#define CARD_SWITCHCLOCK_30MHZ  (0x03UL)
#define CARD_SWITCHCLOCK_25MHZ  (0x04UL)
#define CARD_SWITCHCLOCK_18MHZ  (0x05UL)
#define CARD_SWITCHCLOCK_15MHZ  (0x06UL)

#define LOWEST_CLOCK    CARD_SWITCHCLOCK_15MHZ

#define CLK_200Khz      200000
#define CLK_400Khz      400000

#define CLK_10Mhz       10000000
#define CLK_15Mhz       15000000
#define CLK_20Mhz       20000000
#define CLK_25Mhz       25000000
#define CLK_30Mhz       30000000
#define CLK_40Mhz       40000000
#define CLK_50Mhz       50000000
#define CLK_60Mhz       60000000
#define CLK_70Mhz       70000000
#define CLK_80Mhz       80000000
#define CLK_90Mhz       90000000

#define CLK_100Mhz      100000000
#define CLK_110Mhz      110000000
#define CLK_120Mhz      120000000
#define CLK_130Mhz      130000000
#define CLK_140Mhz      140000000
#define CLK_150Mhz      150000000
#define CLK_160Mhz      160000000
#define CLK_170Mhz      170000000
#define CLK_180Mhz      180000000
#define CLK_190Mhz      190000000
#define CLK_200Mhz      200000000

#define RTK_CLK_STEP    7

static const
u32 rtk_clock_tbl[RTK_CLK_STEP] = {
    75000000,
    50000000,
    37000000,
    30000000,
    25000000,
    18000000,
    15000000
};

#define RTK_DIV_CLK_128  (rtk_clock_tbl[RTK_CLK_STEP-1]>>7) //clock divide with 128
#define RTK_DIV_CLK_256  (rtk_clock_tbl[RTK_CLK_STEP-1]>>8) //clock divide with 256

#define RCA_SHIFTER         16

#define BYTE_CNT            0x200
#define RTK_NORMAL_SPEED    0x00
#define RTK_HIGH_SPEED      0x01
#define RTK_1_BITS          0x00
#define RTK_4_BITS          0x10
#define RTK_BITS_MASK       0x30
#define RTK_SPEED_MASK      0x01
#define RTK_PHASE_MASK      0x06

/* send status event */
#define STATE_IDLE          0
#define STATE_READY         1
#define STATE_IDENT         2
#define STATE_STBY          3
#define STATE_TRAN          4
#define STATE_DATA          5
#define STATE_RCV           6
#define STATE_PRG           7
#define STATE_DIS           8

#define LVL_HI             0x01
#define LVL_LO             0x00

#define rtkcr_get_int_sta(io_base,status_addr) \
            *(u32 *)status_addr = cr_readl(io_base+CR_INT_STATUS)

#define rtkcr_get_sd_sta(io_base,status_addr) \
            *(u32 *)status_addr = cr_readl(io_base+SD_STATUS)

#define rtkcr_get_sd_sta2(io_base,status_addr) \
            *(u32 *)status_addr = cr_readl(io_base+SD_STATUS2)

#define rtkcr_get_sd_trans(io_base,status_addr) \
            *(u32 *)status_addr = cr_readl(io_base+SD_TRANSFER)

#define rtkcr_clr_int_dec_sta(io_base) \
            cr_writel( cr_readl(io_base+CR_INT_STATUS)| \
                       (RTKCR_INT_DEC_STA) , \
                       io_base+CR_INT_STATUS)

#define rtkcr_clr_int_card_sta(io_base) \
            cr_writel( cr_readl(io_base+CR_INT_STATUS)| \
                       (RTKCR_INT_CARD_STA) , \
                       io_base+CR_INT_STATUS)

#define rtkcr_clr_int_sta(io_base) \
            cr_writel( cr_readl(io_base+CR_INT_STATUS)| \
                       (RTKCR_INT_ALL_STA) , \
                       io_base+CR_INT_STATUS)

#define rtkcr_hold_int_dec(io_base)    \
            cr_writel( cr_readl(io_base+CR_INT_MASK) &  \
                       ~(RTKCR_INT_DEC_MASK), \
                       io_base+CR_INT_MASK)

#define rtkcr_hold_int_card(io_base)    \
            cr_writel( cr_readl(io_base+CR_INT_MASK) &  \
                       ~(RTKCR_INT_CARD_MASK), \
                       io_base+CR_INT_MASK)

#define rtkcr_hold_int_all(io_base)    \
            cr_writel( cr_readl(io_base+CR_INT_MASK) &  \
                       ~(RTKCR_INT_ALL_MASK), \
                       io_base+CR_INT_MASK)

#define rtkcr_en_int_dec(io_base)  \
            cr_writel( cr_readl(io_base+CR_INT_MASK) |  \
                       (RTKCR_INT_DEC_MASK), \
                       io_base+CR_INT_MASK)

#define rtkcr_en_int_card(io_base)  \
            cr_writel( cr_readl(io_base+CR_INT_MASK) |  \
                       (RTKCR_INT_CARD_MASK), \
                       io_base+CR_INT_MASK)

#define  rtkcr_mdelay(x)  \
            set_current_state(TASK_INTERRUPTIBLE); \
            schedule_timeout(msecs_to_jiffies(x))

#define INT_BLOCK_R_GAP 0x200
#define INT_BLOCK_W_GAP 5

static const char *const state_tlb[9] = {
    "STATE_IDLE",
    "STATE_READY",
    "STATE_IDENT",
    "STATE_STBY",
    "STATE_TRAN",
    "STATE_DATA",
    "STATE_RCV",
    "STATE_PRG",
    "STATE_DIS"
};

static const char *const bit_tlb[4] = {
    "1bit",
    "4bits",
    "8bits",
    "unknow"
};

static const char *const clk_tlb[7] = {
    "75MHz",
    "50MHz",
    "37MHz",
    "30MHz",
    "25MHz",
    "18MHz",
    "15MHz"
};

/* data read cmd */
static const u8 const opcode_r_type[16] = {
    0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0
};

/* data write cmd */
static const u8 const opcode_w_type[16] = {
    1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0
};

/* data xfer cmd */
static const u8 const opcode_d_type[16] = {
    1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0
};

static const char *const cmdcode_tlb[16] = {
    "N_W",      /* 0 */
    "AW3",      /* 1 */
    "AW4",      /* 2 */
    "UNK",      /* 3 */
    "UNK",      /* 4 */
    "AR3",      /* 5 */
    "AR4",      /* 6 */
    "UNK",      /* 7 */
    "SGR",      /* 8 */
    "AW1",      /* 9 */
    "AW2",      /* 10 */
    "UNK",      /* 11 */
    "N_R",      /* 12 */
    "AR1",      /* 13 */
    "AR2",      /* 14 */
    "UNK",      /* 15 */
};

#define CARD_STA_ERR_MASK ((1<<31)|(1<<30)|(1<<29)|(1<<28)|(1<<27)|(1<<26)|(1<<24)|(1<<23)|(1<<22)|(1<<21)|(1<<20)|(1<<19)|(1<<18)|(1<<17)|(1<<16)|(1<<15)|(1<<13)|(1<<7))

/* Only ADTC type cmd use */
static const unsigned char rtk_sd_cmdcode[60][2] = {
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 0~3 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_NORMALREAD ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 4~7 */
    {SD_NORMALREAD ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_AUTOREAD1  ,SD_R1 }, /* 8~11 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_NORMALREAD ,SD_R1 }, {SD_NORMALREAD ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 12~15 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_AUTOREAD2  ,SD_R1 }, {SD_AUTOREAD1  ,SD_R1 }, {SD_NORMALWRITE,SD_R1 }, /* 16~19 */
    {SD_AUTOWRITE1 ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_NORMALREAD ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 20~23 */
    {SD_AUTOWRITE2 ,SD_R1 }, {SD_AUTOWRITE1 ,SD_R1 }, {SD_NORMALWRITE,SD_R1 }, {SD_NORMALWRITE,SD_R1 }, /* 24~27 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_NORMALREAD ,SD_R1 }, {SD_NORMALREAD ,SD_R1 }, /* 28~31 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 32~35 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 36~39 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_NORMALREAD ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 40~43 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 44~47 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_NORMALREAD ,SD_R1 }, /* 48~51 */
    {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, /* 52~55 */
    {SD_AUTOREAD2  ,SD_R1 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }, {SD_CMD_UNKNOW ,SD_R0 }  /* 56~59 */
};

#define CLK_PIN_IDX 0
#define CMD_PIN_IDX 1
#define RST_PIN_IDX 2           // for eMMC
#define WP_PIN_IDX  RST_PIN_IDX //for CARD-Reader
#define CD_PIN_IDX  3
#define D0_PIN_IDX  4
#define D1_PIN_IDX  5
#define D2_PIN_IDX  6
#define D3_PIN_IDX  7
#define D4_PIN_IDX  8
#define D5_PIN_IDX  9
#define D6_PIN_IDX  10
#define D7_PIN_IDX  11

/* GPIO setting */

/* xxx_DesignSpec_MISC_GPIO.doc */
#define MIS_PINMUX_BASE     (0xb8000800)
#define MIS_GPDIR_BASE      (0xb801BD00)
#define MIS_GPDATO_BASE     (0xb801BD18)
#define MIS_GPDATI_BASE     (0xb801BD30)
#define MIS_GPIE_BASE       (0xb801BD48)

/* xxx_DesignSpec_ISO_MISC_GPIO.doc */
#define ISO_PINMUX_BASE     (0xb8060200)
#define ISO_GPDIR_BASE      (0xb8061100)
#define ISO_GPDATO_BASE     (0xb8061108)
#define ISO_GPDATI_BASE     (0xb8061110)
#define ISO_GPIE_BASE       (0xb8061118)


#define ISO_GPIO_UNKNOW     (0xff)
#define MIS_GPIO_UNKNOW     (0xff)
#define MAX_ISO_GPIO_CNT    (30)
#define MAX_MIS_GPIO_CNT    (93)

/*
Pin mux info :
    xxxx_pinmux_main.doc
    xxxx_pinmux_pmm.doc

GPIO info :
    xxxx_DesignSpec_MISC_GPIO.doc
    xxxx_DesignSpec_ISO_MISC_GPIO.doc
*/
/* max iso_gpio is 30 */
static const u8 iso_gpio_mux_tbl[MAX_ISO_GPIO_CNT+1][2] ={
    {0x00, 28}, {0x00, 20}, {0x00, 12}, {0x00, 4},  /*  0: 3 */
    {0x04, 28}, {0x04, 20}, {0x04, 12}, {0x04, 4},  /*  4: 7 */
    {0x08, 28}, {0x08, 20}, {0x08, 12}, {0x08, 4},  /*  8:11 */
    {0x0C, 28}, {0x0C, 20}, {0x0C, 12}, {0x0C, 4},  /* 12:15 */
    {0x10, 28}, {0x10, 20}, {0x10, 12}, {0x10, 4},  /* 16:19 */
    {0x14, 28}, {0x14, 20}, {0x14, 12}, {0x14, 4},  /* 20:23 */
    {0x18, 28}, {0x18, 20}, {0x18, 12}, {0x18, 4},  /* 24:27 */
    {0x1C, 28}, {0x1C, 20}, {0x1C, 12}              /* 28:30 */
};

/* max mis_gpio is 93 */
static const u8 mis_gpio_mux_tbl[][2] ={
    {0x00, 28}, {0x00, 20}, {0x00, 12}, {0x00, 4},  /*  0:  3 */
    {0x04, 28}, {0x04, 20}, {0x04, 12}, {0x04, 4},  /*  4:  7 */
    {0x08, 28}, {0x08, 20}, {0x08, 12}, {0x08, 4},  /*  8: 11 */
    {0x0C, 28}, {0x0C, 20}, {0x0C, 12}, {0x0C, 4},  /* 12: 15 */
    {0x10, 28}, {0x10, 20}, {0x10, 12}, {0x10, 4},  /* 16: 19 */
    {0x14, 28}, {0x14, 20}, {0x14, 12}, {0x14, 4},  /* 20: 23 */
    {0x18, 28}, {0x18, 20}, {0x18, 12}, {0x18, 4},  /* 24: 27 */
    {0x1C, 28}, {0x1C, 20}, {0x1C, 12}, {0x1C, 4},  /* 28: 31 */
    {0x20, 28}, {0x20, 20}, {0x20, 12}, {0x20, 4},  /* 32: 35 */
    {0x24, 28}, {0x24, 20}, {0x24, 12}, {0x24, 4},  /* 36: 39 */
    {0x28, 28}, {0x28, 20}, {0x28, 12}, {0x28, 4},  /* 40: 43 */
    {0x2C, 28}, {0x2C, 20}, {0x2C, 12}, {0x2C, 4},  /* 44: 47 */
    {0x30, 28}, {0x30, 20}, {0x30, 12}, {0x30, 4},  /* 48: 51 */
    {0x34, 28}, {0x34, 20}, {0x34, 12}, {0x34, 4},  /* 52: 55 */
    {0x38, 28}, {0x38, 20}, {0x38, 12}, {0x38, 4},  /* 56: 59 */
    {0x3C, 28}, {0x3C, 20}, {0x3C, 12}, {0x3C, 4},  /* 60: 63 */
    {0x40, 28}, {0x40, 20}, {0x40, 12}, {0x40, 4},  /* 64: 67 */
    {0x44, 28}, {0x44, 20}, {0x44, 12}, {0x44, 4},  /* 68: 71 */
    {0x48, 28}, {0x48, 20}, {0x48, 12}, {0x48, 4},  /* 72: 75 */
    {0x4C, 28}, {0x4C, 20}, {0x4C, 12}, {0x4C, 4},  /* 76: 79 */
    {0x50, 28}, {0x50, 20}, {0x50, 12}, {0x50, 4},  /* 80: 83 */
    {0x54, 28}, {0x54, 20}, {0x54, 12}, {0x54, 4},  /* 84: 87 */
    {0x58, 28}, {0x58, 20}, {0x58, 12}, {0x58, 4},  /* 88: 91 */
    {0x5C, 28}, {0x5C, 20},                         /* 92: 93 */
};

#define I_MUX(pin) (iso_gpio_mux_tbl[pin][0]+ISO_PINMUX_BASE)
#define I_SHT(pin) (iso_gpio_mux_tbl[pin][1])
#define M_MUX(pin) (mis_gpio_mux_tbl[pin][0]+MIS_PINMUX_BASE)
#define M_SHT(pin) (mis_gpio_mux_tbl[pin][1])
#define GPIO_CHK_ISO(pin)   ((pin &  ISO_FLAG)?1:0)
#define GPIO_GET_NUM(pin)   (pin & ~ISO_FLAG)

#define PIN_MUX_SEL_SD      (0x0UL)

/* remove from c file &&& */

#endif
