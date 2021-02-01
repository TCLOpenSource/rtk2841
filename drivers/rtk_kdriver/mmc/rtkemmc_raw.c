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


#ifdef CONFIG_WEBOS
#define NEW_MMC_API_PATH
#ifdef NEW_MMC_API_PATH
#include "../../staging/webos/logger/ll_mmc.h"
#else
#include "../../staging/webos/mmcoops/mmcoops.h"
#endif
#endif
#ifdef CONFIG_REALTEK_OF
#include <linux/of_irq.h>
#include <linux/of_address.h>
#endif

#ifndef  CONFIG_WEBOS
#ifdef NEW_MMC_API_PATH
struct ll_mmc_ops {
   const char *name;
   s32 (*ll_mmc_init)(void);
   s32 (*ll_mmc_write)(u8 *buffer, u64 address, u32 size);
   s32 (*ll_mmc_read)(u8 *buffer, u64 address, u32 size);
};
void register_ll_mmc_ops(struct ll_mmc_ops *ops);
#else
struct mmcoops_ops {
	const char *name;
	s32 (*raw_mmc_init)(void);
	s32 (*raw_mmc_write)(u8 *buffer, u64 address, u32 size);
	s32 (*raw_mmc_read)(u8 *buffer, u64 address, u32 size);
};
void register_mmcoops_ops(struct mmcoops_ops *ops);
#endif
#endif
/************************************************************************
 *  Local Define
 ************************************************************************/
#define DRIVER_NAME "rtkemmc_raw"
#define BANNER      "Realtek eMMC RAW Driver"
#define VERSION "$Id: RTK_284X 2017-10-05 20:35 $"

/* #define EN_SHOW_DATA */
#define cr_maskl(reg,msk,sht,val)  \
		cr_writel((cr_readl(reg) & ~(msk<<sht))|(val<<sht), reg)

#define RAW_EMMC_VDD (MMC_VDD_30_31 | MMC_VDD_31_32 | MMC_VDD_32_33 | MMC_VDD_33_34 | MMC_VDD_165_195)
#define MMC_SECTOR_ADDR (1 << 30)

#define EMMC_DEBUG

#ifndef AUTO_SEND_STOP
	#define AUTO_SEND_STOP
#endif
/************************************************************************
 *  Local veriable
 ************************************************************************/
struct rtksd_host *rawport = NULL;
static unsigned int raw_rca;
struct scatterlist* raw_sg;
u32 rtk_emmc_raw_op;
/************************************************************************
 *  Local Function Protal Type
 ************************************************************************/
static int raw_chk_resource(void);

/************************************************************************
 *  External Function Protal Type
 ************************************************************************/
extern int export_em_sg_make_script(struct scatterlist *sg,
			 int dma_nents, struct sd_cmd_pkt *cmd_info);
extern int export_em_reinit_idmac_post(struct sd_cmd_pkt *cmd_info);
extern int export_em_reinit_idmac_pre(struct sd_cmd_pkt *cmd_info);

/************************************************************************
 *  Externall veriable
 ************************************************************************/
extern struct mmc_host *mmc_host_local;


/************************************************************************
 * Function Body
 ************************************************************************/
/************************************************************************
 *
 ************************************************************************/
static
void raw_em_read_rsp( unsigned int * rsp, unsigned int reg_count )
{
	if ( reg_count == 16 ){
		rsp[3] = cr_readl(EM_DWC_RESP0);
		rsp[2] = cr_readl(EM_DWC_RESP1);
		rsp[1] = cr_readl(EM_DWC_RESP2);
		rsp[0] = cr_readl(EM_DWC_RESP3);

	}else if ( reg_count == 2 ){
		/*
		When CIU sends auto-stop command,
		then response is saved in Response 0 register.
		Response for previous command sent by host is
		still preserved in Response 0 register.
		*/
		rsp[0] = cr_readl(EM_DWC_RESP0);
		rsp[1] = cr_readl(EM_DWC_RESP1);
	}else{
		rsp[0] = cr_readl(EM_DWC_RESP0);
	}
#if 0
	mmcraw("%s(%d)cnt=%u\n",__func__,__LINE__,reg_count);
	mmcraw("rsp[0]=0x%08x\n",rsp[0]);
	mmcraw("rsp[1]=0x%08x\n",rsp[1]);
	mmcraw("rsp[2]=0x%08x\n",rsp[2]);
	mmcraw("rsp[3]=0x%08x\n",rsp[3]);
#endif
}

/************************************************************************
 *
 ************************************************************************/
static
int raw_em_chk_rsp(u32 * rsp, u32 cmd_flag, struct sd_cmd_pkt *cmd_info)
{

	int ret_err = 0;
	u32 cmd_idx = 0;

	cmd_idx = SDMMC_CMD_INDX(cmd_flag);

	if(cmd_flag & SDMMC_CMD_RESP_LONG){
		raw_em_read_rsp(rsp, 16);
		/* only resp == 6 is possible have card status */

	}else{
		if(cmd_flag & SDMMC_CMD_SEND_STOP)
			raw_em_read_rsp(rsp, 2);
		else
			raw_em_read_rsp(rsp, 6);

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
				 &&(rsp[1] & RESP_ERR_BIT))
		{
					ret_err |= 1;
				}
			}
		}
	}
	if(ret_err){
		mmcraw("rsp error !!!!!!!!!!!!!!!!!!!!!!!!\n");
		mmcraw("rsp[0]=0x%08x\n",rsp[0]);
		if(cmd_flag & SDMMC_CMD_SEND_STOP){
			mmcraw("rsp[1]=0x%08x",rsp[1]);
		}
	}

	return ret_err;
}

/************************************************************************
 *
 ************************************************************************/
static
void raw_em_send_cmd(u32 cmd, u32 sd_arg)
{
	unsigned int cmd_status = 0;
	unsigned int loop = 0;

	cr_writel(sd_arg, EM_DWC_CMDARG);
	cr_writel(SDMMC_CMD_START | cmd, EM_DWC_CMD);

	loop = 1000; //wait 10ms
	while (loop --) {
		cmd_status = cr_readl(EM_DWC_CMD);
		if (!(cmd_status & SDMMC_CMD_START))
			return;
		udelay(10);
	}

	mmcraw("Timeout sending command (cmd %#x arg %#x status %#x)\n",
		   cmd, sd_arg, cmd_status);
}

/************************************************************************
 *
 ************************************************************************/
static
void raw_em_set_div(unsigned int em_div)
{
	unsigned int row_div;

	if(em_div)
		row_div = (em_div>>1);
	else
		row_div = 0;
	/* reset div every time change clock */

	/* disable clock */
	cr_writel(0, EM_DWC_CLKENA);
	cr_writel(0, EM_DWC_CLKSRC);

	/* inform CIU */
	raw_em_send_cmd(SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);

	/* set clock to desired speed */
	cr_writel(row_div, EM_DWC_CLKDIV);

	/* inform CIU */
	raw_em_send_cmd(SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);

	/* enable clock */
	cr_writel((_BIT16 | _BIT0), EM_DWC_CLKENA);

	/* inform CIU */
	raw_em_send_cmd(SDMMC_CMD_UPD_CLK | SDMMC_CMD_PRV_DAT_WAIT, 0);

	mmcraw("CLK divide=%d\n",(row_div<<1));
}

/************************************************************************
 *
 ************************************************************************/
static
void raw_em_clear_int_sta(unsigned int hold_int){

	if(hold_int){
		cr_writel( 0x0, EM_DWC_INTMASK );           //disable int.
		cr_writel( 0x0,EM_DWC_IDINTEN );
	}

	cr_writel( 0xffffffff, EM_DWC_RINTSTS );    //Clear all int result.
	cr_writel( 0xffffffff, EM_DWC_IDSTS);
}

/************************************************************************
 * IP configure
 ************************************************************************/
static
void raw_em_IP_config(void)
{
	unsigned int reginfo;

	cr_writel( _BIT0, EM_DWC_PWREN );           //enable power of device 0.
	cr_writel( 0x0, EM_DWC_INTMASK );           //disable int.
	cr_writel( 0xffffffff, EM_DWC_RINTSTS );    //Clear all int result.

	cr_writel( 0xffffff40,EM_DWC_TMOUT );               //set timeout of data and response as default.

	cr_writel((0x05UL<<SDMMC_MSIZE_SHT)        /* set DW_DMA_Multiple_Transaction_Size as 64(0x05) */
		 |(0x3fUL<<SDMMC_RX_WMARK_SHT)     /* RX_WMARK=0x3f */
		 |(0x40UL<<SDMMC_TX_WMARK_SHT) ,   /* TX_WMARK=0x40 */
				EM_DWC_FIFOTH );

	cr_writel( SDMMC_DE|SDMMC_FB,EM_DWC_BMOD );

	cr_writel( 0,EM_DWC_IDINTEN );

	/* enable write/read threshold as 512 bytes */
	cr_writel((0x0200 << 16) | _BIT2 | _BIT0, EM_DWC_CardThrCtl);

	reginfo = (SDMMC_CTRL_USE_IDMAC);   //use_internal_dmac

	cr_writel( reginfo,EM_DWC_CTRL );

}

/************************************************************************
 *
 ************************************************************************/
static
void raw_em_reset_card(void)
{
	/* card reset should be implement here. This reg is GPIO control only.  */
	cr_writel(~_BIT0,EM_DWC_RST_n);
	mdelay(1);
	cr_writel(_BIT0,EM_DWC_RST_n);

	/* Toggle 74 clock here :
	 *  The toggle clock will be send out before cmd0 by DW IP.
	 *  To reference unsigned int raw_em_prepare_command()
	 *  cmd0 set SDMMC_CMD_INIT bit.
	 */
}

/************************************************************************
 *
 ************************************************************************/
static
void raw_em_set_IO_driving(void)
{
	/* data pad driving */
	cr_writel( 0xaaaaaaaa, 0xb80008D8);
	cr_writel( 0xfbfbfbfb, 0xb80008DC);
	cr_writel( 0xfbfbfbfb, 0xb80008E0);

	cr_writel( 0x00000000, 0xb80008e8);
}


/************************************************************************
 *
 ************************************************************************/
static
void raw_em_reset_host(unsigned int save_en)
{
	unsigned int config1;
	unsigned int config2;
	unsigned int config3;
	unsigned int config4;
	unsigned int config5;
	unsigned int config6;

	if(save_en){
		/* store currently IP setting */
		config1 = cr_readl(EM_DWC_PWREN);
		config2 = cr_readl(EM_DWC_CLKDIV);
		config3 = cr_readl(EM_DWC_CTYPE);
		config4 = cr_readl(EM_DWC_UHS_REG);
		config5 = cr_readl(EM_DWC_DBADDR);
		config6 = cr_readl(EM_DWC_EMMC_DDR_REG);
	}

	/*
	  reset all eMMC module.
	  private_data that reserve for future is NULL
	 */
	/* 289x new func, One rbus clock finish */
	cr_writel(CLKEN_EM_DW,RTK_EM_DW_CLKEN);
	cr_writel(RSTN_EM_DW,RTK_EM_DW_SRST);
	udelay(5);
	cr_writel((RSTN_EM_DW | 0x01UL),RTK_EM_DW_SRST);
	cr_writel((CLKEN_EM_DW | 0x01U),RTK_EM_DW_CLKEN);

	/* set IO pad driving */
	raw_em_set_IO_driving();

	/* reset synopsys eMMC IP */
	raw_em_IP_config();

	if(save_en){
		/* restore previously IP setting */
		cr_writel(config1,EM_DWC_PWREN);
		raw_em_set_div((config2<<1));
		cr_writel(config3,EM_DWC_CTYPE);
		cr_writel(config4,EM_DWC_UHS_REG);
		cr_writel(config5,EM_DWC_DBADDR);
		cr_writel(config6,EM_DWC_EMMC_DDR_REG);
	}

}

/************************************************************************
 * //-------- PLLEMMC for EMMC (99MHz) -------------------------------------
 * rtd_part_outl(0xb8000700, 0, 0, 0x1);    // PLLALLRSTB = 1
 * rtd_part_outl(0xb8000704, 1, 0, 0x2);    // LDO power on, PLLEMMC power on
 * rtd_part_outl(0xb8000720, 23, 16, 0x13); // PLLEMMC_NCODE_T = 19
 * rtd_part_outl(0xb8000700, 10, 8, 0x1);   // PLLSN = 1,
 * rtd_part_outl(0xb8000700, 17, 17, 0);    // PLLSDIV2 = 0, 27x(19+3)/3/2=99MHz
 * rtd_part_outl(0xb8000710, 0, 0, 0x1);    // PLLEMMC_OC_EN = 1
 * rtd_inl(0xb8000728);                     // polling 0xb8000728[4]==1, PLLEMMC_Oc_done flag
 * rtd_part_outl(0xb8000710, 0, 0, 0);      // PLLEMMC_OC_EN = 1
 *
 * Clock Setting:
 * Target_Clock = 27MHz*( PLLEMMC_NCODE_T +3)/ (PLLSN+2)/( PLLSDIV2+1)/2
 *
 * PLLEMMC_NCODE_T = 0x1800_0720[23:16]
 * PLLSN           = 0x1800_0700[10:8] <==1(currently)
 * PLLSDIV2        = 0x1800_0700[17]   <==0(currently)
 *
 * Phase Setting:
 *   0x1800_0708[ 5: 0] <== Write Phase Setting
 *   0x1800_0708[15:10] <== Read  Phase Setting
 *
 *
 ************************************************************************/
#define DEFAULT_C_PHASE		0x0
#define DEFAULT_R_PHASE		0x0c
#define DEFAULT_W_PHASE		0x1d

int raw_em_set_base_clk(void)
{
	int err = 0;
	unsigned int loop = 200000;
	unsigned int reginfo;

	/* hold mmc IP clock; 289x skip this action */
	//cr_writel(CLKEN_EM_DW, RTK_EM_DW_CLKEN);

	/* Phase Setting */
	reginfo = cr_readl(0xb8000708) & ~((0x3fUL<<20)|(0x3fUL<<10)|(0x3fUL<<0));
	reginfo |= ((DEFAULT_C_PHASE<<20)|(DEFAULT_R_PHASE<<10)|(DEFAULT_W_PHASE<<0));
	cr_writel(reginfo,0xb8000708);


	/* Addording to discuss with Fekao, the base clock will b setting to 99Mhz */
	cr_maskl(EMMC_PLL_SET,0x001UL,30 ,0);	/* PLL_EMMC_CKSSC_INV = 0 */
	cr_maskl(EMMC_PLL_SSC0,0x2FFUL,4 ,0);	/* PLLEMMC_OC_STEP_SET = 0 */

	cr_maskl(EMMC_PLL_CTRL,0x003UL,0 ,2);	/* LDO power on, PLLEMMC power on */

	cr_maskl(EMMC_PLL_SSC4,0x0FFUL,16,41);	/* PLLEMMC_NCODE_T=41 and PLLSN=4 for 95MHz */
	cr_maskl(EMMC_PLL_SSC5,0x001UL,0 ,0);	/* En_ssc =0; disable SSC */

	udelay(5);

	cr_maskl(EMMC_PLL_SET,0x007UL,8 ,4);	/* PLLSN = 4, */
	cr_maskl(EMMC_PLL_SET,0x001UL,17,0);	/* PLLSDIV2 = 0, 27x(19+3)/3/2=99MHz */
	cr_maskl(EMMC_PLL_SET,0x01fUL,12,3);	/* PLL Charger Pump Current IchDpll[16:12], icp set to 3 on 100Mhz */
	udelay(5);

	cr_maskl(EMMC_PLL_SET,0x001UL,0 ,1);	/* PLLALLRSTB = 1 */
	cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,1);	/* PLLEMMC_OC_EN = 1 */

	while(loop--){              // polling 0xb8000728[4]==1, PLLEMMC_Oc_done flag
		if(cr_readl(EMMC_PLL_SSC6) & _BIT4){
			break;
		}
	}

	cr_maskl(EMMC_PLL_SSC0,0x001UL,0 ,0);	/* PLLEMMC_OC_EN = 0 */
	udelay(150);

	if(!loop){
		err = -1;
	}

	/* release mmc IP clock */
	//cr_writel((CLKEN_EM_DW | 0x1UL), RTK_EM_DW_CLKEN);

	return err;
}

/************************************************************************
 *
 ************************************************************************/
static
unsigned int raw_em_chk_card_busy(void)
{
	if(cr_readl( EM_DWC_STATUS ) & SDMMC_DAT0_BUSY)
		return 1;
	else
		return 0;

}

/************************************************************************
 *
 ************************************************************************/
static
unsigned int raw_em_set_bits(unsigned int bus_width)
{
	unsigned int reginfo = 0;

	if(bus_width & BUS_WIDTH_8){
		mmcraw("8 bits mode\n");
		reginfo = _BIT16;
	}else if(bus_width & BUS_WIDTH_4){
		mmcraw("4 bits mode\n");
		reginfo = _BIT0;
	}else{
		mmcraw("1 bits mode\n");
		reginfo = 0;
	}

	cr_writel( reginfo,EM_DWC_CTYPE);
	return 0;
}

/************************************************************************
 *
 ************************************************************************/
static
unsigned int raw_em_prepare_command(struct sd_cmd_pkt * cmd_info)
{
	u32 cmd_idx  = 0;
	u32 cmd_flag = 0;
	u32 rsp_typ  = 0;
	u32 cmd_typ  = 0;

	cmd_idx = (u32)cmd_info->cmd->opcode;
	rsp_typ = (u32)cmd_info->rsp_para;
	cmd_typ = (u32)cmd_info->flags;

	/*
	mmcraw("cmd_idx=0x%08x rsp_typ=0x%08x cmd_typ=0x%08x\n",
	        cmd_idx,rsp_typ,cmd_typ);
	*/

	cmd_flag = cmd_idx;

	if (cmd_idx == MMC_STOP_TRANSMISSION)
		cmd_flag |= SDMMC_CMD_STOP;

	if (cmd_idx != MMC_SEND_STATUS)
		cmd_flag |= SDMMC_CMD_PRV_DAT_WAIT;

	/* before idle cmd, send 80 clk plus first */
	if(cmd_idx == MMC_GO_IDLE_STATE)
		cmd_flag |= SDMMC_CMD_INIT;

	/* check resp type */
	if(rsp_typ & MMC_RSP_PRESENT){

		cmd_flag |= (SDMMC_CMD_RESP_EXP);
		if(rsp_typ & MMC_RSP_CRC)
			cmd_flag |= (SDMMC_CMD_RESP_CRC);

		if(rsp_typ & MMC_RSP_136)
			cmd_flag |= (SDMMC_CMD_RESP_LONG);

	}

	/* check cmd type ADTC? */
	if(cmd_typ )
	{
		cmd_flag |= SDMMC_CMD_DAT_EXP;

		/* check data write/read */
		if(cmd_typ == MMC_DATA_WRITE)
			cmd_flag |= SDMMC_CMD_DAT_EXP | SDMMC_CMD_DAT_WR;

	}

#ifdef AUTO_SEND_STOP
	/* auto send stop cmd */
	if((cmd_idx == MMC_READ_MULTIPLE_BLOCK)
	  |(cmd_idx == MMC_WRITE_MULTIPLE_BLOCK))
	{
		cmd_flag |= SDMMC_CMD_SEND_STOP;
	}
#endif

	cmd_flag |= SDMMC_CMD_USE_HREG;

	/* mmcraw("cmd_flag=0x%08x\n", cmd_flag); */

	return cmd_flag;
}

/************************************************************************
 *
 ************************************************************************/
static
int raw_em_TriggerXferCmd(unsigned int cmd_flag, struct sd_cmd_pkt *cmd_info)
{
	int ret_err;
	unsigned int    cmd_idx;
	unsigned int    loops;
	unsigned int    sd_int_stat_row = 0;

	unsigned int    sd_status;
	unsigned int    wr_bit = 0;

	cmd_idx = SDMMC_CMD_INDX(cmd_flag);

	cr_writel(cr_readl(EM_INT_STATUS)|(_BIT1|_BIT2),
					  EM_INT_STATUS);
	if(cmd_flag & _BIT10)
		wr_bit = _BIT1;
	else
		wr_bit = _BIT2;

	/* disable and clear int */
	raw_em_clear_int_sta(1);

	cr_writel(cmd_flag|SDMMC_CMD_START, EM_DWC_CMD);

	udelay(1);

	ret_err = -19; /*  TIMEOUT ( defined in include/mmc.h ) */
	loops = 50000; /* cmd_info->timeout; */
	while( loops ){
		sd_int_stat_row = cr_readl(EM_DWC_RINTSTS);

		if(cmd_flag & SDMMC_CMD_DAT_EXP)
		{
			if(sd_int_stat_row & SDMMC_INT_DATA_OVER){
				if(cr_readl(EM_INT_STATUS) & wr_bit){
					/*
					 wait DDR busy
					  0: dma done
					  1: dma busy
					*/
					cr_writel(cr_readl(EM_INT_STATUS)|(_BIT1|_BIT2),
							EM_INT_STATUS);
				}else{
					ret_err = 0;
					break;
				}
			}
		}
		else
		{
			if(sd_int_stat_row & SDMMC_INT_CMD_DONE){
				ret_err = 0;
				break;
			}
		}

		udelay(100);
		loops--;
	}

	sd_status = cr_readl(EM_DWC_STATUS);
	cr_writel(sd_int_stat_row,EM_DWC_RINTSTS); /* clear int status */

	if( ret_err ) {
		mmcraw("Cmd Timeout!!!\n");
	}else{
		if((sd_int_stat_row & SDMMC_INT_ERROR)) {
			if( (cmd_idx == MMC_SEND_OP_COND)
			 && (sd_int_stat_row & SDMMC_INT_RESP_ERR))
			{
					/* cmd1 skip response error */
			}
			else{
				ret_err = -17;
				mmcraw("EM_DWC_RINTSTS error bit alert!!!\n");
			}
		}
	}

	if( ret_err ) {
		mmcraw("EM_DWC_RINTSTS=%08x\n", sd_int_stat_row);
		mmcraw("EM_DWC_STATUS =%08x\n", sd_status);
		/* raw_em_reset_host(1); */
	}

	return ret_err;
}

/************************************************************************

************************************************************************/
static
int raw_em_SendCmd( unsigned char  cmd_idx,
		   unsigned int   cmd_arg,
		   unsigned int   rsp_type,
		   unsigned int * rsp)
{
	int ret_err;
	unsigned int cmd_flag;
	struct sd_cmd_pkt cmd_info;
	struct mmc_command cmd;

	cmd_info.cmd = &cmd;
	cmd.arg      = cmd_arg;
	cmd.opcode   = cmd_idx;

	cmd_info.rsp_para  = rsp_type;
	cmd_info.flags =0;
	cmd_info.timeout = 500;

	cmd_flag = raw_em_prepare_command(&cmd_info);

#ifdef EMMC_DEBUG
	mmcraw("cmd_idx=%02u cmd_arg=0x%08x cmd_flag=0x%08x\n",
			cmd_idx,cmd_arg,cmd_flag);
#endif

	cr_writel(cmd_arg,EM_DWC_CMDARG); // cmd argument 0x28

	ret_err = raw_em_TriggerXferCmd(cmd_flag, &cmd_info);

	ret_err |= raw_em_chk_rsp(rsp, cmd_flag,&cmd_info);

	return ret_err;
}

/************************************************************************
 *
 ************************************************************************/
static
int raw_em_Stream_Cmd(struct sd_cmd_pkt * cmd_info)
{
	int ret_err = 0;
	int rsp_err = 0;
	u32 dir = 0;
	int dma_nents = 0;
	unsigned int cmd_flag;
	//unsigned int cmd_idx        = cmd_info->cmd->opcode;
	unsigned int cmd_arg	= cmd_info->cmd->arg;
	unsigned int *rsp	= cmd_info->cmd->resp;
	unsigned int byte_cnt	= cmd_info->byte_count;
	unsigned int blk_cnt	= cmd_info->block_count;

	cmd_info->timeout = 2500;

	if(cmd_info->flags == MMC_DATA_READ){ //cmd_info->data->flags & MMC_DATA_READ){
		dir = DMA_FROM_DEVICE;
	}else if(cmd_info->flags == MMC_DATA_WRITE){
		dir = DMA_TO_DEVICE;
	}else{
		WARN_ON(1);
		return -1;
	}

	dma_nents = dma_map_sg( mmc_dev(mmc_host_local), raw_sg,1,dir);

	export_em_reinit_idmac_pre(cmd_info);
	export_em_sg_make_script(raw_sg,dma_nents,cmd_info);

	cmd_flag = raw_em_prepare_command(cmd_info);

#ifdef EMMC_DEBUG
	mmcraw("cmd_idx=%02u cmd_arg=0x%08x cmd_flag=0x%08x\n"
		"       byte_cnt=0x%08x blk_cnt=0x%08x\n",
			cmd_info->cmd->opcode,cmd_arg,cmd_flag,byte_cnt,blk_cnt);
#endif

	cr_writel(cmd_arg,          EM_DWC_CMDARG);
	cr_writel(byte_cnt,         EM_DWC_BLKSIZ);
	cr_writel(byte_cnt*blk_cnt, EM_DWC_BYTCNT);

	ret_err = raw_em_TriggerXferCmd(cmd_flag, cmd_info);
	rsp_err |= raw_em_chk_rsp(rsp, cmd_flag, cmd_info);

	dma_unmap_sg( mmc_dev(mmc_host_local), raw_sg,1,  dir);
	export_em_reinit_idmac_post(cmd_info);

	return ret_err;

}


/************************************************************************
 *
 ************************************************************************/
static
int raw_em_Stream(
	unsigned int    cmd_idx,
	unsigned int    cmd_arg,
	unsigned int    rsp_type,
	unsigned int    blk_cnt,
	unsigned int    xfer_flag,
	unsigned char   *data_buffer )
{
	struct scatterlist sg;
	struct sd_cmd_pkt cmd_info;
	struct mmc_command cmd;
	int err = -1;

	cmd_info.sdport = rawport;
	cmd_info.cmd = &cmd;
	cmd.arg      = cmd_arg;
	cmd.opcode = cmd_idx;

	cmd_info.rsp_para    = rsp_type;
	cmd_info.byte_count  = 0x200;
	cmd_info.block_count = blk_cnt;
	cmd_info.flags   = xfer_flag;

	sg_init_one(&sg, data_buffer, (blk_cnt*0x200));
	raw_sg = &sg;

	err = raw_em_Stream_Cmd(&cmd_info );

	if(err){
		mmcraw("stream cmd fail\n");;
	}

	raw_sg = NULL;

	return err;

}

/************************************************************************

************************************************************************/
static
int raw_em_wait_status( unsigned char state )
{
	unsigned int rsp_buffer[4];
	unsigned int counter;
	int ret_err = 0;

	counter = 500;

	while(counter--)
	{
		ret_err = raw_em_SendCmd(MMC_SEND_STATUS,
					raw_rca << RCA_SHIFTER,
					MMC_RSP_R1,
					rsp_buffer);

		if(ret_err){
			break;
		}else{
			unsigned char cur_state = R1_CURRENT_STATE(rsp_buffer[0]);
			ret_err = -1;
			if(cur_state == state){
				if(rsp_buffer[0] & R1_READY_FOR_DATA){
					ret_err = 0;
					break;
				}
			}
		}
		mdelay(1);
	}

	return ret_err;
}


/************************************************************************
 *
 ************************************************************************/
#ifndef  AUTO_SEND_STOP
static
int raw_em_send_stop(void)
{
	unsigned int rsp_buffer[4];
	int ret_err = 0;

	ret_err = raw_em_SendCmd(MMC_STOP_TRANSMISSION,
				0,  /* if HPI have not set, RCA is unnecessary. */
				MMC_RSP_R1B,
				rsp_buffer);

	return ret_err;
}
#endif

/************************************************************************
 *
 ************************************************************************/
static
int raw_em_send_csd(struct rtksd_host *rawport){
	int err;
	unsigned int raw_csd[4];

	/* Read CSD ==> CMD9 */
	err = 0;
	err = raw_em_SendCmd( MMC_SEND_CSD,
			raw_rca << RCA_SHIFTER,
			MMC_RSP_R2,
			raw_csd);

	mmcraw("raw_csd[0]=0x%x", raw_csd[0]);
	mmcraw("raw_csd[1]=0x%x", raw_csd[1]);
	mmcraw("raw_csd[2]=0x%x", raw_csd[2]);
	mmcraw("raw_csd[3]=0x%x", raw_csd[3]);

	return err;

}

/************************************************************************
 *
 ************************************************************************/
int raw_em_rw_loop(u8 *buffer, u64 address, u32 size,u32 dir)
{
	u32 tar_addr;
	u32 blk_cont;
	u32 tmp_tar_addr;
	u8* tmp_buf_addr;
	u32 tmp_blk_cont;
	u32 res_blk_cont;
	u32 cmd_idx;

	int err = 0;

	mmcraw("%s(%d)\n",__func__,__LINE__);

	mmcraw("buffer=0x%p; address=0x%llx; size=0x%x\n",
			buffer,address,size);


	if (!IS_ALIGNED(address, 512)){
		mmcraw("%s(%d)address not align 512!\n",__func__,__LINE__);
		return -1;
	}

	if (!IS_ALIGNED(size, 512)){
		mmcraw("%s(%d)size not align 512!\n",__func__,__LINE__);
		return -1;
	}

	/* always sector address device */
	tar_addr = (u32)(address>>9);

	blk_cont = size>>9;

	if(size & 0x1ff)
		blk_cont+=1;

	tmp_tar_addr = tar_addr;
	res_blk_cont = blk_cont;
	tmp_buf_addr = buffer;

	mmcraw("tmp_tar_addr=0x%x tar_addr=0x%x\n",tmp_tar_addr,tar_addr);
	mmcraw("res_blk_cont=0x%x blk_cont=0x%x\n",res_blk_cont,blk_cont);
	mmcraw("tmp_buf_addr=0x%p array_ptr=0x%p\n",tmp_buf_addr,buffer);

#define EMMC_MAX_XFER_BLK 600
	while(res_blk_cont){

		if(res_blk_cont > EMMC_MAX_XFER_BLK)
			tmp_blk_cont = EMMC_MAX_XFER_BLK;
		else
			tmp_blk_cont = res_blk_cont;

		mmcraw("tmp_blk_cont=%d\n",tmp_blk_cont);

		if(dir == MMC_DATA_WRITE)
			cmd_idx = 24;
		else
			cmd_idx = 17;

		if(tmp_blk_cont > 1)
			cmd_idx += 1;

		err = raw_em_Stream( cmd_idx,
				tmp_tar_addr,
				MMC_RSP_R1,
				tmp_blk_cont,
				dir,
				tmp_buf_addr);
		if(err){
			mmcraw("%s(%d)cmd err\n",__func__,__LINE__);
			break;
		}

#ifndef  AUTO_SEND_STOP
		if(tmp_blk_cont > 1)
			raw_em_send_stop();
#endif

		tmp_tar_addr += tmp_blk_cont;
		res_blk_cont -= tmp_blk_cont;
		tmp_buf_addr += (tmp_blk_cont<<9);

		mmcraw("tmp_tar_addr=%d\n",tmp_tar_addr);
		mmcraw("res_blk_cont=%d\n",res_blk_cont);
		mmcraw("tmp_buf_addr=%p\n",tmp_buf_addr);

		if(dir == MMC_DATA_WRITE)
			raw_em_wait_status(STATE_TRAN);
	}

	if(err){
		mmcraw("%s(%d)cmd err\n",__func__,__LINE__);
		err = -1;
	}

	return err;

}

/************************************************************************
 *
 ************************************************************************/
static s32 raw_dw_em_write(u8 *buffer, u64 address, u32 size)
{
	int err = 0;

	if(raw_chk_resource())
		return -1;

	rtk_emmc_raw_op = 1;
	while(cr_readl(EM_SCPU_SEL) & PS_SCPU_SEL){
		//EM_ALERT("%s(%d)wait previously cmd finish\n",__func__,__LINE__);
		udelay(10);
	}
	cr_writel( PS_SCPU_SEL, EM_SCPU_SEL );

	err = raw_em_rw_loop(buffer,address,size,MMC_DATA_WRITE);

	cr_writel( 0, EM_SCPU_SEL );
	rtk_emmc_raw_op = 0;

	return err;
}

s32 export_raw_dw_em_write(u8 *buffer, u64 address, u32 size)
{
	EM_ALERT("%s(%d)\n",__func__,__LINE__);
	return raw_dw_em_write(buffer,address,size);
}

/************************************************************************
 *
 ************************************************************************/
static s32 raw_dw_em_read(u8 *buffer, u64 address, u32 size)
{
	int err = 0;

	if(raw_chk_resource())
		return -1;

	rtk_emmc_raw_op = 1;
	while(cr_readl(EM_SCPU_SEL) & PS_SCPU_SEL){
		//EM_ALERT("%s(%d)wait previously cmd finish\n",__func__,__LINE__);
		udelay(10);
	}
	cr_writel( PS_SCPU_SEL, EM_SCPU_SEL );

	err = raw_em_rw_loop(buffer,address,size,MMC_DATA_READ);

	cr_writel( 0, EM_SCPU_SEL );
	rtk_emmc_raw_op = 0;

	return err;
}

s32 export_raw_dw_em_read(u8 *buffer, u64 address, u32 size)
{
	EM_ALERT("%s(%d)\n",__func__,__LINE__);
	return raw_dw_em_read(buffer,address,size);
}

/************************************************************************
 *
 ************************************************************************/
static s32 raw_dw_em_init(void)
{
	int err;
	int rty_cnt;
	u32 timeend;
	u32 resp[4];
	unsigned int raw_cid[4];

	mmcraw("raw dw eMMC initial 2016/06/14 15:40\n");
	mmcraw("(build at %s %s )\n",__DATE__,__TIME__);
	mmcraw("(RTK284x plateform)\n");

	if(raw_chk_resource())
		return -1;

	rtk_emmc_raw_op = 1;
	while(cr_readl(EM_SCPU_SEL) & PS_SCPU_SEL){
		//EM_ALERT("%s(%d)wait previously cmd finish\n",__func__,__LINE__);
		udelay(10);
	}
	cr_writel( PS_SCPU_SEL, EM_SCPU_SEL );

	raw_em_set_base_clk();

	rty_cnt = 0;

	/* reset host IP */
	raw_em_reset_host(0);

	//clock of realchip (99MHz/500)~= 200Khz
	raw_em_set_div(500);

	raw_em_set_bits(BUS_WIDTH_1);

	rty_cnt = 5;
CMD0_RETRY:
	/* CMD0 */
	/* setting reset pin, then send 80 clock brfore cmd0 */
	raw_em_reset_card();
	raw_em_SendCmd(MMC_GO_IDLE_STATE, 0, MMC_RSP_NONE,resp);

	if(raw_em_chk_card_busy()){
		if(rty_cnt){
			rty_cnt--;
			udelay(100);
			goto CMD0_RETRY;
		}
		err = -1;
		goto err_out;
	}

	/* Idle state ==> CMD1 */
	mmcraw("cmd1\n");
	err = 0;
	timeend = 100;
	while (timeend--){

		mdelay(10);
		err = raw_em_SendCmd(MMC_SEND_OP_COND,
				RAW_EMMC_VDD|MMC_SECTOR_ADDR,
				MMC_RSP_R3,
				resp);

		if(err ){
			printk("cmd err !!!\n");
			err = -1;
			break;
		}

		if((resp[0] == 0xffffffff)){
			printk("resp error (0x%08x)\n",resp[0]);
			resp[0] = 0;
		}

		if (resp[0] & MMC_CARD_BUSY){
			if( resp[0] & MMC_SECTOR_ADDR ) {
				printk("sector addressing card\n");
			}else{
				printk("byte addressing card\n");
			}
			break;
		}

	}

	if( (timeend == 0) || err ) {
		err = -1;
		goto err_out;
	}

	/* CMD2 */
	mmcraw("cmd2\n");
	udelay(100);
	err = 0;
	err = raw_em_SendCmd(MMC_ALL_SEND_CID,
				0x00000000,
				MMC_RSP_R2,
				raw_cid);
	if(err)
		goto err_out;

	/* Indentification state ==> CMD3 */
	mmcraw("cmd3\n");
	udelay(100);
	err = 0;
	err = raw_em_SendCmd(MMC_SET_RELATIVE_ADDR,
				raw_rca << RCA_SHIFTER,
				MMC_RSP_R1,
				resp);
	if(err)
		goto err_out;


	/* Send CSD  ==> CMD9 */
	udelay(100);
	err = raw_em_send_csd(rawport);
	if(err)
		goto err_out;

	/* Standy-by state ==> CMD7 */
	mmcraw("cmd7\n");
	udelay(100);
	err = 0;
	err = raw_em_SendCmd(MMC_SELECT_CARD,
			raw_rca << RCA_SHIFTER,
			MMC_RSP_R1B,
			resp);

	if(err){
		mmcraw("cmd7 error\n");
		goto err_out;
	}

	if(resp[0] & R1_READY_FOR_DATA){
		udelay(100);
	}else{
		mdelay(3);
	}

	/* speed up to 25Mhz (100MHz/4)=25Mhz */
	raw_em_set_div(4);

	/* change to 4bits width ==> CMD6 */
	mmcraw("cmd6\n");
	mmcraw("change to 4bits\n");
	if(1){
		u32 arg;
		u32 bus_width_type;
		udelay(100);
		err = 0;
		bus_width_type = EXT_CSD_BUS_WIDTH_4;

		arg = (MMC_SWITCH_MODE_WRITE_BYTE << 24)|
			  (EXT_CSD_BUS_WIDTH          << 16)|
			  (bus_width_type             << 8)|
			  EXT_CSD_CMD_SET_NORMAL;

		err = raw_em_SendCmd(MMC_SWITCH,
				arg,
				MMC_RSP_R1B,
				resp);
		if(err)
			goto err_out;

		/* To wait status change complete */
		err = 0;
		timeend = 100;
		do {
			udelay(1000);
			err = raw_em_SendCmd(MMC_SEND_STATUS,
					raw_rca << RCA_SHIFTER,
					MMC_RSP_R1,
					resp);

			if(err)
				goto err_out;

			timeend--;

		}while((R1_CURRENT_STATE(resp[0]) == STATE_PRG) && timeend);

		if(err) {
			goto err_out;
		}

		if ((resp[0] & R1_SWITCH_ERROR) ||
			(timeend==0) )
		{
			err = -1;
			goto err_out;
		}else{
			raw_em_set_bits(bus_width_type);

			if(bus_width_type == EXT_CSD_BUS_WIDTH_8)
				mmcraw("MMC 8-bits mode\n");
			else if(bus_width_type == EXT_CSD_BUS_WIDTH_4)
				mmcraw("MMC 4-bits mode\n");
			else
				mmcraw("unsupport bus type\n");

		}
	}

err_out:
	if(err){
		mmcraw("re initial fail!!\n");
		err = -1;
	}else{
		mmcraw("re initial finish\n");
	}

	rtk_emmc_raw_op = 0;
	cr_writel( 0, EM_SCPU_SEL );

	return err;
}

s32 export_raw_dw_em_init(void)
{
	int err = 0;
	EM_ALERT("%s(%d)\n",__func__,__LINE__);

	err= raw_dw_em_init();
	return err;
}

/************************************************************************
 * #define EMMC_USER_AREA          0
 * #define EMMC_BOOT_PARTITION1    1
 * #define EMMC_BOOT_PARAITION2    2
 ************************************************************************/
static int raw_emmc_partition_change(u32 part_num)
{
	u32 resp[4];
	int err = -1;

	if(raw_chk_resource())
		return -1;

	rtk_emmc_raw_op = 1;
#if 0
	err = raw_em_SendCmd(MMC_SEND_STATUS,
					raw_rca << RCA_SHIFTER,
					MMC_RSP_R1,
					resp);
#endif

	err = raw_em_SendCmd(MMC_SWITCH,
		MMC_SWITCH_MODE_WRITE_BYTE<<24 |
		EXT_CSD_PART_CONFIG<<16 |
		part_num<<8 |
		EXT_CSD_CMD_SET_NORMAL,
		(MMC_CMD_AC | MMC_RSP_R1B),
		resp);

	if(err){
		EM_WARNING( "%s: MMC_SWITCH fail\n", DRIVER_NAME);
	}

	rtk_emmc_raw_op = 0;

	return err;
}

int export_raw_emmc_partition_change(u32 part_num){
	return raw_emmc_partition_change(part_num);
}

/************************************************************************
 *

 	int err = 0;
	struct rtksd_host *sdport;
	unsigned long flags;

	if(mmc == NULL)
		mmc = mmc_host_local;

	sdport = mmc_priv(mmc);


 ************************************************************************/
static
int raw_chk_resource(void)
{
	int err = 0;
	if(!rawport){
		if(mmc_host_local){
			rawport = mmc_priv(mmc_host_local);
		}else{
			err = -1;
			EM_ALERT("no mmc_host_local exist\n");
		}
	}

	return err;
}

/************************************************************************
 *  Before mmcoops.c and mmcoops.h merge finished,
 ************************************************************************/
#ifndef  CONFIG_WEBOS

static struct mmcoops_ops *mmcoops;
void register_mmcoops_ops(struct mmcoops_ops *ops)
{
	if (mmcoops)
		pr_warn("Overriding previously set MMCOOPS ops\n");

	mmcoops = ops;
}

#endif

#ifdef NEW_MMC_API_PATH
struct ll_mmc_ops rtk_mmcoops_ops = {
	.name			= DRIVER_NAME,
	.ll_mmc_init		= raw_dw_em_init,
	.ll_mmc_write		= raw_dw_em_write,
	.ll_mmc_read		= raw_dw_em_read,
};

static int __init lg1k_ll_mmc_init(void)
{
	EM_INFO(DRIVER_NAME ": Register MMC driver for oops/panic\n");

	register_ll_mmc_ops(&rtk_mmcoops_ops);

	rawport = NULL;
	raw_rca = 1;
	rtk_emmc_raw_op = 0;

	return 0;
}
early_initcall(lg1k_ll_mmc_init);
#else
struct mmcoops_ops rtk_mmcoops_ops = {
	.name			= DRIVER_NAME,
	.raw_mmc_init		= raw_dw_em_init,
	.raw_mmc_write		= raw_dw_em_write,
	.raw_mmc_read		= raw_dw_em_read,
};

static int __init lg1k_mmcoops_init(void)
{
	EM_INFO(DRIVER_NAME ": Register MMC driver for oops/panic\n");

	register_mmcoops_ops(&rtk_mmcoops_ops);

	rawport = NULL;
	raw_rca = 1;
	rtk_emmc_raw_op = 0;

	return 0;
}
early_initcall(lg1k_mmcoops_init);
#endif
