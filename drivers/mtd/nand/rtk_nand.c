/******************************************************************************
 * $Id: rtk_nand.c 337905 2010-10-18 01:32:27Z alexchang2131 $
 * drivers/mtd/nand/rtk_nand.c
 * Overview: Realtek NAND Flash Controller Driver
 * Copyright (c) 2008 Realtek Semiconductor Corp. All Rights Reserved.
 * Modification History:
 *    #000 2010-07-02 AlexChang   create file
 * Copyright (C) 2007-2013 Realtek Semiconductor Corporation
 *
 *******************************************************************************/
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/slab.h>
#include <linux/sysctl.h>
#include <linux/sched.h>
#include <linux/list.h>
#include <linux/pm.h>
#include <linux/module.h>

#include <rbus/nand_reg.h>
#include <mach/io.h>

#include <linux/mtd/rtk_nand.h>
#include <linux/bitops.h>
#include <mtd/mtd-abi.h>
#include <linux/jiffies.h>
#include <linux/delay.h>
#include <linux/time.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/string.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>

#include <linux/dma-mapping.h>
#include <linux/mtd/rtk_mtd_patch.h>
#include "../mtdcore.h"
#include <mach/platform.h>
#include "../../rtk_kdriver/include/rtk_kdriver/rtk_crt.h"//#include <mach/rtk_crt.h>
#include <linux/device.h>
#include "../../base/base.h"

#ifdef CONFIG_MTD_NAND_BBT_SHARE
#include "../../rtk_kdriver/include/rtk_kdriver/RPCDriver.h"//#include <mach/RPCDriver.h>
#endif

#define BANNER  "Realtek NAND Flash Driver"
#define VERSION  "$Id: rtk_nand.c RTK_299X_PLUS 2015-05-11 14:00 $"

#define RTK_NAND_INTERRUPT	(0)
#define MTDSIZE	(sizeof (struct mtd_info) + sizeof (struct nand_chip))
#define MAX_PARTITIONS	16
#define BOOTCODE	16*1024*1024	//16MB
#define FACT_PARAM_SIZE 4*1024*1024 //4MB for TV factory parameter use.
#define DRIVER_NAME "rtkNF"
#define NF_INIT	(0)
#define NF_READ_TRIGGER 	(1)
#define NF_WRITE_TRIGGER 	(2)
#define NF_ERASE_TRIGGER 	(3)
#define NF_POLL_STATUS 	(4)
#define NF_WAKE_UP	(5)

#define NF_AUTO_IRQ_MASK	(0x08)
#define NF_DMA_IRQ_MASK		(0x10)
#define NF_POLL_IRQ_MASK	(0x80)
#define NF_XFER_IRQ_MASK	(0x04)
#define NF_IRQ_MASK	(NF_XFER_IRQ_MASK|NF_AUTO_IRQ_MASK|NF_DMA_IRQ_MASK|NF_POLL_IRQ_MASK)

#define NF_RESET_IRQ	REG_WRITE_U32(REG_NAND_ISREN,(0xff<<1|0x00));\
						REG_WRITE_U32(REG_NAND_ISR,(0xff<<1|0x00))

//#define NF_RESET_IRQ	NULL

#define NF_ENABLE_IRQ(mask)	REG_WRITE_U32(REG_NAND_ISREN,(mask|0x01))


static int g_nfFlag = NF_INIT ;

#define CLR_REG_NAND_ISR REG_WRITE_U32(REG_NAND_ISR,(0xFF<<1))

#define ISR_EN_READ (0x10)
#define ISR_EN_WRITE (0x08)

static int g_enReadRetrial = 0;
static unsigned char regVal1=0;
static unsigned char regVal2=0;
static unsigned char regVal3=0;
static unsigned char regVal4=0;
static unsigned char nRun=0;
static unsigned char nInc=0;

int g_sw_WP_level = -1;
//#define MTD_NAND_RTK_NAND_TEST
#ifdef MTD_NAND_RTK_NAND_TEST
int test_erase_fail_remap = 0;
int test_write_fail_remap = 0;
int test_read_warning_remap = 0;
int test_read_fail_remap  = 0;
#endif

/*proc fs entry*/
static struct proc_dir_entry *rtk_nand_proc_entry;

static void rtk_xfer_GetParameter(void);
static void rtk_xfer_SetParameter(unsigned char val1,unsigned char val2,unsigned char val3,unsigned char val4);

//static void rtk_SetVal( char val1, char val2, char val3, char val4);
static void rtk_SetReadRetrialMode(unsigned int run);
static int rtk_read_ecc_page_reTrial (struct mtd_info *mtd, u16 chipnr, unsigned int page, u_char *data_buf, u_char *oob_buf);

extern int pcb_mgr_get_enum_info_byname(char *enum_name, unsigned long long *value);
//extern platform_info_t platform_info;

#if RTK_NAND_INTERRUPT
static wait_queue_head_t	g_irq_waitq;

//#define RTK_WAIT_EVENT wait_event_interruptible(g_host->irq_waitq,g_nfFlag==NF_WAKE_UP)
#define RTK_WAIT_EVENT wait_event_interruptible(g_irq_waitq,g_nfFlag==NF_WAKE_UP)

#define CHECK_IRQ(flag,reg,mask,value) ((g_nfFlag==flag)&&((REG_READ_U32(reg)&mask)==value))
#define CHECK_REG(reg,mask,value) (REG_READ_U32(reg)&mask==value)
//#define CLEAR_IRQ(reg,mask)	(REG_WRITE_U32(reg,(REG_READ_U32(reg)|mask)&0xfffffffe))
#define CLEAR_IRQ(reg,mask)	(REG_WRITE_U32(reg,mask))
#define NF_AUTO_TRIG_ISR	(0x08)
#define NF_DMA_ISR	(0x10)
#define NF_POLL_STATUS_ISR	(0x80)
#endif

#define RETRY_COUNT	(0x20)

//Add for GPIO Setting
#define BIT(x) (1 << (x))
#define SETBITS(x,y) ((x) |= (y))
#define CLEARBITS(x,y) ((x) &= (~(y)))
#define SETBIT(x,y) SETBITS((x), (BIT((y))))
#define CLEARBIT(x,y) CLEARBITS((x), (BIT((y))))
static unsigned int g_regGPIODirBase = 0;
static unsigned int g_regGPIOOutBase = 0;
static struct rtk_nand_host *g_host;

static unsigned int g_NFWP_no = 0;
//static unsigned int g_NFWP_index = 0;

static unsigned int g_NFWP_value_INV = 0;
static unsigned int g_NFWP_value_en = 0;
static unsigned int g_NFWP_value_dis = 0;
static unsigned int g_NFWP_value_init = 0;
static int g_NFWP_pinType = 0;


#define NF_GPIO_OUT	(1)
#define NF_GPIO_IN	(0)
//#define NF_WP_ENABLE	(0)
//#define NF_WP_DISABLE	(1)

unsigned int g_BootcodeSize = 0;
unsigned int g_Factory_param_size = 0;
unsigned int g_Secure_store_Start = 0;
unsigned int g_Secure_store_Size = 0;
unsigned int g_Factory_RO_Start = 0;
unsigned int g_Factory_RO_Size = 0;
unsigned int g_CP_Disable_area = 0;

unsigned char g_edo_mode_enable = 0;

static int g_WP_en = 0;
unsigned int g_NF_pageSize = 0;
unsigned char g_isRandomize = 0;

#define NF_OOB_SIZE 512

const char *ptypes[] = {"cmdlinepart", NULL};

/* nand driver low-level functions */
static int rtk_read_oob(struct mtd_info *mtd, u16 chipnr, int page, int len, u_char *buf);
static int rtk_read_ecc_page(struct mtd_info *mtd, u16 chipnr, unsigned int page,
			u_char *data, u_char *oob_buf);
static int rtk_write_oob(struct mtd_info *mtd, u16 chipnr, int page, int len, const u_char *buf);
static int rtk_write_ecc_page(struct mtd_info *mtd, u16 chipnr, unsigned int page,
			const u_char *data, const u_char *oob_buf, int isBBT);
static int rtk_erase_block(struct mtd_info *mtd, u16 chipnr, int page);
static void rtk_nand_edo_setting(void);


/* Global Variables */
struct mtd_info *rtk_mtd;

static int page_size, oob_size, ppb;
#ifdef CONFIG_MTD_NAND_IBT
//for whole nand flash
int I_KERNEL_RBA_PERCENT = 2;
//for whole nand flash
int RBA_PERCENT = 4;
//for bootcode area
int I_BOOTCODE_RBA_PERCENT = 10;
#else
//for whole nand flash
int RBA_PERCENT = 5;
#endif
static char is_NF_CP_Enable_read = 0;
static char is_NF_CP_Enable_write = 0;

static unsigned int u32CP_mode = 0;
static unsigned int cpSel = 0;
static unsigned int flash_protection_root_key_index = 0;

static char u8regKey0[4];
static char u8regKey1[4];
static char u8regKey2[4];
static char u8regKey3[4];
static unsigned int *regKey0;
static unsigned int *regKey1;
static unsigned int *regKey2;
static unsigned int *regKey3;

#ifdef CONFIG_MTD_NAND_CP_ENABLE
#define RTK_MTD_NAND_CP_ENABLE 1
#else
#define RTK_MTD_NAND_CP_ENABLE 0
#endif


DEFINE_SEMAPHORE (sem_NF_CARDREADER);
EXPORT_SYMBOL(sem_NF_CARDREADER);

#if RTK_ARD_ALGORITHM //Variable declartion
	#define TOTAL_BLK_NUM	8192
	const unsigned int g_RecBlkStart = 64;
	const unsigned int g_RecBlkEnd   = 7389;

	const unsigned int g_PorcWindowSize = 64;
	const unsigned int g_ReadCntThrshld = 0x200000;
	//const unsigned int g_ReadCntThrshld = 0x400000;

	const unsigned int g_MaxMinDist = 8192;
	const unsigned int g_DistInc = 1;

	const unsigned int g_WinTrigThrshld = 8192;
	static unsigned int g_WinTrigCnt = 0;

	static unsigned int g_RecArray[8192]={0};

	static unsigned int g_u32WinStart = 0;
	static unsigned int g_u32WinEnd = 0;

	int whichBlk= 0;
	int pagePerBlk = 0;

#endif
struct rtk_nand_host {
	struct mtd_info		mtd;
	struct nand_chip	nand;
	struct mtd_partition	*parts;
	struct device		*dev;

	void			*spare0;
	void			*main_area0;
	void			*main_area1;

	void __iomem		*base;
	void __iomem		*regs;
	int			status_request;
	struct clk		*clk;
	int			clk_act;
	int			irq;

	wait_queue_head_t	irq_waitq;

	uint8_t			*data_buf;
	unsigned int		buf_start;
	int			spare_len;
};

//-----------------------------random mode setting------------------------------
static unsigned char nf_is_random_mode(void)
{
	return REG_READ_U32(REG_RND_EN) & 0x1;
}

#if 0
static void nf_enable_random_mode(void)
{
	REG_WRITE_U32(REG_RND_EN,RND_RW_EN_rnd_rw_enable(0x1));
}

static void nf_disable_random_mode(void)
{
	REG_WRITE_U32(REG_RND_EN,RND_RW_EN_rnd_rw_enable(0x0));
}
#endif

static void nf_set_random_read(unsigned int pagesize,unsigned int spare_col)
{
	REG_WRITE_U32(REG_RND_CMD1, RND_CMD1_rnd_cmd1(0x5));
	REG_WRITE_U32(REG_RND_CMD2, RND_CMD2_rnd_cmd2(0xe0));
	REG_WRITE_U32(REG_RND_DATA_STR_COL_H, RND_DATA_STR_COL_H_data_col_msb(0));	// data start address MSB (always 0)
	REG_WRITE_U32(REG_RND_SPR_STR_COL_H, RND_SPR_STR_COL_H_spr_col_msb((spare_col+ pagesize) >> 8));	// spare start address MSB
	REG_WRITE_U32(REG_RND_SPR_STR_COL_L, REG_RND_SPR_STR_COL_L_spr_col_lsb((spare_col+ pagesize) & 0xff));	// spare start address LSB
}

static void nf_set_random_write(unsigned int pagesize,unsigned int spare_col)
{
	REG_WRITE_U32(REG_RND_CMD1, RND_CMD1_rnd_cmd1(0x85));
	REG_WRITE_U32(REG_RND_DATA_STR_COL_H, RND_DATA_STR_COL_H_data_col_msb(0));	// data start address MSB (always 0)
	REG_WRITE_U32(REG_RND_SPR_STR_COL_H, RND_SPR_STR_COL_H_spr_col_msb((spare_col+ pagesize) >> 8));	// spare start address MSB
	REG_WRITE_U32(REG_RND_SPR_STR_COL_L, REG_RND_SPR_STR_COL_L_spr_col_lsb((spare_col+ pagesize) & 0xff));	// spare start address LSB
}

//----------------------------------------------------------------------------
int getCPStatus(void)
{
	return is_NF_CP_Enable_read;
}
//----------------------------------------------------------------------------

void setCPfunc(int isEnable)
{
	if(isEnable)
		is_NF_CP_Enable_read = 1;
	else
		is_NF_CP_Enable_read = 0;
}


//----------------------------------------------------------------------------
void setAudioIOBit(int index, int value) {

	if (index > 3) return;
	rtd_maskl(0xb8000980, ~(1 << (index+ 12)), (value != 0) << (index+ 12));
}
//----------------------------------------------------------------------------

void setGPIOBit(unsigned int nGPIOBase, unsigned int nGPIOnum, unsigned int uBit)
{
	unsigned int whichReg = 0;
	unsigned int whichBit = 0;
	unsigned int temp;
	whichReg = nGPIOBase+4*(nGPIOnum/32);
	whichBit = nGPIOnum%32;

	temp = REG_READ_U32(whichReg);
	
	if(uBit)
		REG_WRITE_U32(whichReg,SETBIT(temp,whichBit));
	else
		REG_WRITE_U32(whichReg,CLEARBIT(temp,whichBit));
}
//----------------------------------------------------------------------------
unsigned int getGPIOBit(unsigned int nGPIOBase, unsigned int nGPIOnum)
{
	unsigned int whichReg = 0;
	unsigned int whichBit = 0;
	unsigned int ret=0;
	whichReg = nGPIOBase+4*(nGPIOnum/32);
	whichBit = nGPIOnum%32;
	ret = REG_READ_U32(whichReg);
	ret>>=whichBit;
	ret&=(0x1);
	return ret;
}
//----------------------------------------------------------------------------

unsigned int getGPIORegVal(unsigned int nGPIOBase, unsigned int nGPIOnum)
{
	unsigned int whichReg = 0;
	//unsigned int whichBit = 0;
	whichReg = nGPIOBase+4*(nGPIOnum/32);
	//printk("\tgetRegister 0x%x\n",whichReg);
	return REG_READ_U32(whichReg);
}

 //----------------------------------------------------------------------------

#if RTK_ARD_ALGORITHM //function declartion
//----------------------------------------------------------------------------
void RTK_ARD_DumpProcWin(int nStartBlk, int nSize)
{
	int i=0;
	unsigned int nSysStartBlk = g_RecBlkStart;
	for(i=0;i<nSize;i++)
	{
		if(nStartBlk<=g_RecBlkEnd)
		{
			printk("[%u] %u \n",nStartBlk,g_RecArray[nStartBlk]);
			nStartBlk++;
		}
		else
		{
			printk("[%u] %u \n",nSysStartBlk,g_RecArray[nSysStartBlk]);
			nSysStartBlk++;
		}
	}
}
//----------------------------------------------------------------------------
void slideProcWindowPtr()
{
	int tmp=0;
	g_u32WinStart = g_u32WinEnd;
	if(((g_u32WinEnd+g_PorcWindowSize-1)>g_RecBlkEnd))//reverse
	{
		tmp =  g_RecBlkEnd - g_u32WinEnd+1;
		g_u32WinEnd = g_RecBlkStart + (g_PorcWindowSize - tmp)-1;
	}
	else
	{
		g_u32WinEnd+=(g_PorcWindowSize-1);
	}
}
//----------------------------------------------------------------------------
void resetBlock(int nBlkNo)
{
	static unsigned int tmpCnt = 0;
//Reser block....TBD...
////////////////////////////
	tmpCnt++;

printk("\n");
printk("\t[AT]Reset block [%u] : %u\n",nBlkNo,g_RecArray[nBlkNo]);
printk("\t[AT]Total reset %u blocks\n",tmpCnt);
	g_RecArray[nBlkNo]=0;

}
//----------------------------------------------------------------------------
void travelProcWindow()//When WinTrigCnt > WinTrigThrshld
{
	int maxVal[2];
	int minVal[2];
	int i=0;
	int idx=g_u32WinStart;

	if(g_RecArray[g_u32WinEnd] > g_RecArray[g_u32WinStart])
	{
		minVal[0]=g_u32WinStart;
		minVal[1]=g_RecArray[g_u32WinStart];
		maxVal[0]=g_u32WinEnd;
		maxVal[1]=g_RecArray[g_u32WinEnd];
	}
	else
	{
		maxVal[0]=g_u32WinStart;
		maxVal[1]=g_RecArray[g_u32WinStart];
		minVal[0]=g_u32WinEnd;
		minVal[1]=g_RecArray[g_u32WinEnd];
	}

	printk("++++Before Travel++++\n");
	printk("minVal[%u] %u, maxVal[%u] %u\n",minVal[0],minVal[1],maxVal[0],maxVal[1]);
	RTK_ARD_DumpProcWin(g_u32WinStart,g_PorcWindowSize);
	for(i=0;i<g_PorcWindowSize;i++)
	{
		if(g_RecArray[idx]>=g_ReadCntThrshld)
			resetBlock(idx);
		if(idx<=g_RecBlkEnd)
		{
			if(g_RecArray[idx]<minVal[1])//Process minimun value
			{
				minVal[0]=idx;
				minVal[1]=g_RecArray[idx];
			}
			if(g_RecArray[idx]>maxVal[1])//Process maximun value
			{
				maxVal[0]=idx;
				maxVal[1]=g_RecArray[idx];
			}
			if(idx==g_RecBlkEnd)
				idx = g_RecBlkStart;
			else
				idx++;
		}

	}
	printk("----After Travel w/o Grouping ----\n");
	printk("minVal[%u] %u, maxVal[%u] %u\n",minVal[0],minVal[1],maxVal[0],maxVal[1]);

	//Grouping
	g_RecArray[minVal[0]] += g_DistInc;
	if((maxVal[1]-minVal[1]) < g_MaxMinDist)
	{
		g_RecArray[maxVal[0]] += g_MaxMinDist;
	}

	RTK_ARD_DumpProcWin(g_u32WinStart,g_PorcWindowSize);
	slideProcWindowPtr();
	g_WinTrigCnt = 0; //Reset windows trigger count
}
#endif
//----------------------------------------------------------------------------

/*
	parse_token can parse a string and extract the value of designated token.
		parsed_string: The string to be parsed.
		token: the name of the token
		return value: If return value is NULL, it means that the token is not found.
			If return value is "non zero", it means that the token is found, and return value will be a string that contains the value of that token.
			If the token doesn't have a value, return value will be a string that contains empty string ("\0").
			If return value is "non zero", "BE SURE" TO free it after you donot need it.

		Exp:
			char *value=parse_token("A1 A2=222 A3=\"333 333\"", "A0");
				=> value=NULL
			char *value=parse_token("A1 A2=222 A3=\"333 333\"", "A1");
				=> value points to a string of "\0"
			char *value=parse_token("A1 A2=222 A3=\"333 333\"", "A2");
				=> value points to a string of "222"
			char *value=parse_token("A1 A2=222 A3=\"333 333\"", "A3");
				=> value points to a string of "333 333"
*/
 char *rtkNF_parse_token(const char *parsed_string, const char *token)
{
	const char *ptr = parsed_string;
	const char *start, *end, *value_start, *value_end;
	char *ret_str;

	while(1) {
		value_start = value_end = 0;
		for(;*ptr == ' ' || *ptr == '\t'; ptr++)	;
		if(*ptr == '\0')	break;
		start = ptr;
		for(;*ptr != ' ' && *ptr != '\t' && *ptr != '=' && *ptr != '\0'; ptr++) ;
		end = ptr;
		if(*ptr == '=') {
			ptr++;
			if(*ptr == '"') {
				ptr++;
				value_start = ptr;
				for(; *ptr != '"' && *ptr != '\0'; ptr++)	;
				if(*ptr != '"' || (*(ptr+1) != '\0' && *(ptr+1) != ' ' && *(ptr+1) != '\t')) {
					printk("system_parameters error! Check your parameters.");
					break;
				}
			} else {
				value_start = ptr;
				for(;*ptr != ' ' && *ptr != '\t' && *ptr != '\0' && *ptr != '"'; ptr++) ;
				if(*ptr == '"') {
					printk("system_parameters error! Check your parameters.");
					break;
				}
			}
			value_end = ptr;
		}

		if(!strncmp(token, start, end-start)) {
			if(value_start) {
				ret_str = kmalloc(value_end-value_start+1, GFP_KERNEL);
				if(ret_str)
				{
					strncpy(ret_str, value_start, value_end-value_start);
					ret_str[value_end-value_start] = '\0';
				}
				return ret_str;
			} else {
				if(ret_str)
				{
					ret_str = kmalloc(1, GFP_KERNEL);
					strcpy(ret_str, "");
				}
				return ret_str;
			}
		}
	}

	return (char*)NULL;
}

//----------------------------------------------------------------------------
unsigned int rtkNF_getWPSettingval(void)
{
    unsigned char *param;
    unsigned int retWPval = 0 ;
	
    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"WP_PIN_EN");

    if(param)
		retWPval = simple_strtoul(param, (char**)&retWPval, 16);
	else
		retWPval = 0;
    return retWPval;
}
//----------------------------------------------------------------------------
unsigned char* rtkNF_getBootType(void)
{
    unsigned char *param;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"boot_flash");

     return param;
}
//----------------------------------------------------------------------------
unsigned int rtkNF_getBootcodeSize(void)
{
    unsigned char *param;
    unsigned int retBootcodeSize = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"bootcode_size");

    if(param)
		retBootcodeSize = simple_strtoul(param, (char**)&retBootcodeSize, 16);
    return retBootcodeSize;
}
//----------------------------------------------------------------------------
unsigned int rtkNF_getSecurestoreStart(void)
{
    unsigned char *param;
    unsigned int retSecurestoreStart = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"ss_start");

    if(param)
		retSecurestoreStart = simple_strtoul(param, (char**)&retSecurestoreStart, 16);
    return retSecurestoreStart;
}

//----------------------------------------------------------------------------
unsigned int rtkNF_getSecurestoreSize(void)
{
    unsigned char *param;
    unsigned int retSecurestoreSize = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"ss_size");

    if(param)
		retSecurestoreSize = simple_strtoul(param, (char**)&retSecurestoreSize, 16);
    return retSecurestoreSize;
}

//----------------------------------------------------------------------------
unsigned int rtkNF_getFactParaSize(void)
{
    unsigned char *param;
    unsigned int retFactParaSize = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"factory_size");

    if(param)
		retFactParaSize = simple_strtoul(param, (char**)&retFactParaSize, 16);
    return retFactParaSize;
}

//----------------------------------------------------------------------------
unsigned int rtkNF_getFactRoParaStart(void)
{
    unsigned char *param;
    unsigned int retFactRoParaStart = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"factory_ro_start");

    if(param)
		retFactRoParaStart = simple_strtoul(param, (char**)&retFactRoParaStart, 16);
    return retFactRoParaStart;
}


//----------------------------------------------------------------------------
unsigned int rtkNF_getFactRoParaSize(void)
{
    unsigned char *param;
    unsigned int retFactRoParaSize = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"factory_ro_size");

    if(param)
		retFactRoParaSize = simple_strtoul(param, (char**)&retFactRoParaSize, 16);
    return retFactRoParaSize;
}


//----------------------------------------------------------------------------
unsigned int rtkNF_getRBAPercent(void)
{
    unsigned char *param;
    unsigned int retRbaPercent = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"rba_percent");

    if(param)
		retRbaPercent = simple_strtoul(param, (char**)&retRbaPercent, 16);
    return retRbaPercent;
}

//----------------------------------------------------------------------------
unsigned int rtkNF_getSW_WP_level(void)
{
    unsigned char *param;
    unsigned int retSWwplevel = -1 ;

    param=(char *)rtkNF_parse_token(platform_info.system_parameters,"sw_wp");

    if(param)
		retSWwplevel = simple_strtoul(param, (char**)&retSWwplevel, 16);
    return retSWwplevel;
}

//----------------------------------------------------------------------------

void WAIT_DONE(unsigned int addr, unsigned int mask, unsigned int value)
{
	while ( (REG_READ_U32(addr) & mask) != value )
	{
		asm("nop");
	}
}

//----------------------------------------------------------------------------
#ifdef CONFIG_MTD_NAND_BBT_SHARE
static struct workqueue_struct* nand_wq;
static void _nand_rpc_work(struct work_struct *work)
{
	NF_MSG_INFO("enter _nand_rpc_work!\n");
	if(rtk_mtd)
		rtk_mtd->_reload_bbt(rtk_mtd);
	else
		NF_MSG_INFO("rtk_mtd is NULL!\n");
}

DECLARE_WORK(nand_rpc_work, _nand_rpc_work);
#define NAND_WAKEUP_WORK()  queue_work(nand_wq, &nand_rpc_work)

unsigned long rtk_nand_rpc_handler(unsigned long param1,unsigned long param2)
{
	NF_MSG_INFO("enter rtk_nand_rpc_handler!\n");
	NAND_WAKEUP_WORK();

	return 0;
}
#endif

//----------------------------------------------------------------------------

static void rtk_nand_resumeReg(void)
{
	unsigned int temp_reg = 0;
	struct NF_CLK_INFO nf_clk;

	//set clk info
	nf_clk.nf_clksel = 0x1;
	nf_clk.clk_is_on = 0;
	nf_clk.clk_set_or_get = NF_CLK_SET;
	
	
	REG_WRITE_U32( 0xb801032c,0x01);	//Enable NAND/CardReader arbitrator

	//change NF freq divider (need to disabled NF clock when change divider) 
	CRT_CLK_OnOff(NAND, CLK_ON, &nf_clk);

	if(is_jupiter_cpu()||is_macarthur_cpu())
		REG_WRITE_U32( REG_SPR_DDR_CTL,0x7<<26);
	else
		REG_WRITE_U32(REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1) | NF_SPR_DDR_CTL_spare_ddr_ena(1) | NF_SPR_DDR_CTL_per_2k_spr_ena(1)| NF_SPR_DDR_CTL_spare_dram_sa(0)); //set spare2ddr func. 4=>0.5k spe2ddr_ena at A000F000

	REG_WRITE_U32( REG_PD,~(0x1 << 0) );
	REG_WRITE_U32( REG_ND_CMD,CMD_RESET );

	if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
		REG_WRITE_U32( REG_ND_CTL,(0x80 | 0x00));
	else
		REG_WRITE_U32( REG_ND_CTL,(NF_ND_CTL_xfer(0x01) | NF_ND_CTL_tran_mode(0)) );

	WAIT_DONE(REG_ND_CTL,0x80,0);
	WAIT_DONE(REG_ND_CTL,0x40,0x40);

	REG_WRITE_U32( REG_TIME_PARA1,NF_TIME_PARA1_T1(0x1));
	REG_WRITE_U32( REG_TIME_PARA2,NF_TIME_PARA2_T2(0x1));
	REG_WRITE_U32( REG_TIME_PARA3,NF_TIME_PARA3_T3(0x1));

	if(!is_jupiter_cpu()||!is_saturn_cpu()||!is_darwin_cpu()||!is_macarthur_cpu()||!is_nike_cpu()||!is_macarthur2_cpu()||!is_magellan_cpu()||!is_296x_cpu()||!is_sirius_cpu())
		REG_WRITE_U32( REG_DELAY_CTL,NF_DELAY_CTL_T_WHR_ADL(0x09) );

	//reinit edo setting
	rtk_nand_edo_setting();
	
	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));
	
}
//----------------------------------------------------------------------------

/*
 * RTK NAND suspend:
 */
static void rtk_nand_suspend (struct mtd_info *mtd)
{
	unsigned int retryCnt = RETRY_COUNT;
	
	padlock(PAD_NAND);   // lock nand・s pad

	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry --> 0x%x \n",__FUNCTION__,retryCnt);
		if(retryCnt<=0)
		{
			printk("%s : Retry fail [0x%x]\n",__FUNCTION__,retryCnt);
			
			padunlock(PAD_NAND);   // unlock nand・s pad
			
			return -ERESTARTSYS;
		}
		retryCnt--;
	}
	
	printk("[%s]Enter..\n",__FUNCTION__);
	if(g_enReadRetrial)
	{
		rtk_xfer_SetParameter(regVal1,regVal2,regVal3,regVal4);
	}
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
	printk("[%s]Exit..\n",__FUNCTION__);

	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad
	

}
//----------------------------------------------------------------------------
static void rtk_nand_resume (struct mtd_info *mtd)
{
	unsigned int retryCnt = RETRY_COUNT;
	
	padlock(PAD_NAND);   // lock nand・s pad

	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry --> 0x%x \n",__FUNCTION__,retryCnt);
		if(retryCnt<=0)
		{
			printk("%s : Retry fail [0x%x]\n",__FUNCTION__,retryCnt);
			
			padunlock(PAD_NAND);   // unlock nand・s pad
			
			return -ERESTARTSYS;
		}
		retryCnt--;
	}
	
	printk("[%s]Enter...\n",__FUNCTION__);

	if(g_enReadRetrial)
	{
		if((regVal1==0)&&(regVal2==0)&&(regVal3==0)&&(regVal4==0))
			rtk_xfer_GetParameter();
	}
	rtk_nand_resumeReg();
	printk("[%s]Exit..\n",__FUNCTION__);

	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad
	
}
//----------------------------------------------------------------------------
static void rtk_read_oob_from_SRAM(struct mtd_info *mtd, __u8 *r_oobbuf)
{
	unsigned int reg_oob, reg_num;
	int i;
	unsigned int sram_base_addr; 
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	
	if(is_macarthur2_cpu()||is_296x_cpu()||is_sirius_cpu())
		sram_base_addr = REG_NF_BASE_ADDR + 0x400;
	else
		sram_base_addr = REG_NF_BASE_ADDR;
	//printk("mtd->ecctype 0x%x\n",mtd->ecctype);
//	if ( mtd->ecctype == MTD_ECC_NONE )
	if ( mtd->ecctype == MTD_ECC_NONE ||(mtd->ecctype!=MTD_ECC_RTK_HW))
	{
		reg_num = sram_base_addr;
		reg_oob = REG_READ_U32(reg_num);
		r_oobbuf[0] = reg_oob & 0xff;
		r_oobbuf[1] = (reg_oob >> 8) & 0xff;
		r_oobbuf[2] = (reg_oob >> 16) & 0xff;
		r_oobbuf[3] = (reg_oob >> 24) & 0xff;

		reg_num = sram_base_addr+4;
		reg_oob = REG_READ_U32(reg_num);
		r_oobbuf[4] = reg_oob & 0xff;

		reg_num = sram_base_addr+16;
		reg_oob = REG_READ_U32(reg_num);
		r_oobbuf[5] = reg_oob & 0xff;
		r_oobbuf[6] = (reg_oob >> 8) & 0xff;
		r_oobbuf[7] = (reg_oob >> 16) & 0xff;
		r_oobbuf[8] = (reg_oob >> 24) & 0xff;

		reg_num = sram_base_addr+16*2;
		reg_oob = REG_READ_U32(reg_num);
		r_oobbuf[9] = reg_oob & 0xff;
		r_oobbuf[10] = (reg_oob >> 8) & 0xff;
		r_oobbuf[11] = (reg_oob >> 16) & 0xff;
		r_oobbuf[12] = (reg_oob >> 24) & 0xff;

		reg_num = sram_base_addr+16*3;
		reg_oob = REG_READ_U32(reg_num);
		r_oobbuf[13] = reg_oob & 0xff;
		r_oobbuf[14] = (reg_oob >> 8) & 0xff;
		r_oobbuf[15] = (reg_oob >> 16) & 0xff;
		r_oobbuf[16] = (reg_oob >> 24) & 0xff;

	}
	else
	{
		//just support 6/12bit-ecc dump, Not support 24/40bit-ecc dump
		unsigned int increment = 0, len = 0, cnt = 0, sram_oob_size=0;
		unsigned int count_temp=0, j =0;
		//sanity check
		if((this->ecc_select == 0x18)||(this->ecc_select == 0x28)){
			printk("Not support 24/40bit-ecc dump!!!\n");
			return;
		}
		
		// ecc-bit select
		switch (this->ecc_select) {
			case 0x0c:			// 26B/512B (6B for software)
				increment = 0x20;
				len = 26;
				cnt = mtd->oobblock/512;
				break;
			case 0x0:			// 16B/512B (6B for software)
			default:
				increment = 0x10;
				len = 16;
				cnt = mtd->oobblock/512;
				break;
		}

		if(is_296x_cpu())
			sram_oob_size = 256;
		else{
			sram_oob_size = 64;
		}
		
		for (i = 0,count_temp =0; (i < sram_oob_size) && (count_temp<cnt); i += increment,count_temp++) {
			for(j =0 ; j<len; j++){
				reg_num = sram_base_addr + j +i;
				r_oobbuf[i+j] = REG_READ_U8(reg_num);
			}
		}
	}
}

static void rtk_nand_read_id(struct mtd_info *mtd, u_char id[6])
{
	int id_chain;
	padlock(PAD_NAND);   // lock nand・s pad
	
#if 1
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0x06) );
	REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(0x01));

	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(0x0));
	REG_WRITE_U32(REG_PP_CTL0,NF_PP_CTL0_pp_enable(0x01));
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));

	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_READ_ID));
#ifdef XFER_MODE
	REG_WRITE_U32(REG_ND_CTL,NF_ND_CTL_xfer(0x01));
	WAIT_DONE(REG_ND_CTL,0x80,0);
#endif
	REG_WRITE_U32(REG_ND_PA0,NF_ND_PA0_page_addr0(0));
	REG_WRITE_U32(REG_ND_PA2,NF_ND_PA2_addr_mode(0x07));

#ifdef XFER_MODE

	REG_WRITE_U32(REG_ND_CTL,NF_ND_CTL_xfer(1)|NF_ND_CTL_tran_mode(1));
	WAIT_DONE(REG_ND_CTL,0x80,0);
#else
    REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(1)| NF_AUTO_TRIG_auto_case(1));
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
#endif
	REG_WRITE_U32(REG_ND_CTL,NF_ND_CTL_xfer(1)|NF_ND_CTL_tran_mode(4));
	WAIT_DONE(REG_ND_CTL,0x80,0);

	REG_WRITE_U32(REG_PP_CTL0,NF_PP_CTL0_pp_reset(1));

	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_map_sel(1)|NF_SRAM_CTL_access_en(1)|NF_SRAM_CTL_mem_region(0));
	
	id_chain = REG_READ_U32(REG_SRAM_BASE);
	
	id[0] = id_chain & 0xff;
	id[1] = (id_chain >> 8) & 0xff;
	id[2] = (id_chain >> 16) & 0xff;
	id[3] = (id_chain >> 24) & 0xff;
	if(id_chain==0xDA94D7AD)
	{
		printk("Detect H27UBG8T2B and enable read-retrial mode...\n");
		g_enReadRetrial = 1;
		g_isRandomize = 1;
		printk("Enable Read-retrial mode...\n");
		printk("Enable Randomized mechanism\n");
	}

	id_chain = REG_READ_U32(REG_SRAM_BASE+4);
	
	id[4] = id_chain & 0xff;
	id[5] = (id_chain >> 8) & 0xff;

	REG_WRITE_U32(REG_SRAM_CTL,0x0);	//# no omitted
#else
if(!rtk_tmp)
	id_chain=0xDA94D7AD;
else
	id_chain=0x20202020;

	id[0] = id_chain & 0xff;
	id[1] = (id_chain >> 8) & 0xff;
	id[2] = (id_chain >> 16) & 0xff;
	id[3] = (id_chain >> 24) & 0xff;


	if(id_chain==0xDA94D7AD)
	{
		printk("Detect H27UBG8T2B and enable read-retrial mode...\n");
		g_enReadRetrial = 1;
		id[4] = 0x74;
		id[5] = 0xc3;
	}

else
{
	id[4] = 0x20;
	id[5] = 0x20;

}
#endif
	padunlock(PAD_NAND);   // unlock nand・s pad
}
//----------------------------------------------------------------------------
static void reverse_to_Tags(char *r_oobbuf, int eccBits)
{
	int k,j;

	if(is_jupiter_cpu())
	{
		for ( k=0; k<4; k++ )
			r_oobbuf[5+k] = r_oobbuf[8+k];

		memcpy(&r_oobbuf[9],&r_oobbuf[16],4);//add by alexchang for improve nand read 0225-2010
		memcpy(&r_oobbuf[13],&r_oobbuf[24],4);//add by alexchang for improve nand read 0225-2010
	}else{
		if((eccBits==0)||(eccBits==0xc))
		{
			for ( k=0; k<4; k++ )
				r_oobbuf[5+k] = r_oobbuf[8+k];

			memcpy(&r_oobbuf[9],&r_oobbuf[16],4);//add by alexchang for improve nand read 0225-2010
			memcpy(&r_oobbuf[13],&r_oobbuf[24],4);//add by alexchang for improve nand read 0225-2010
		}else if((eccBits==0x18)||(eccBits==0x28))
		{
			for(k=0,j=1;k<28;k+=4,j++)
				memcpy(&r_oobbuf[1+k],&r_oobbuf[8*j],4);
		}
	}
}

//----------------------------------------------------------------------------
static int rtk_Process_Buf(unsigned char* oob_buf)
{
	int j=0,k=0;
	unsigned int reg_oob, reg_num;

	REG_WRITE_U32(REG_READ_BY_PP,0x00);
	REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x04);

	for ( j=0; j < 12; j++)
	{
		reg_num = REG_NF_BASE_ADDR + j*4;
		reg_oob = REG_READ_U32(reg_num);
		oob_buf[j*4+0] = reg_oob & 0xff;
		oob_buf[j*4+1] = (reg_oob >> 8) & 0xff;
		if(j==11)
			break;
		oob_buf[j*4+2] = (reg_oob >> 16) & 0xff;
		oob_buf[j*4+3] = (reg_oob >> 24) & 0xff;
	}

	for ( j=16,k=0; j < 28; j++,k++)
	{
		reg_num = REG_NF_BASE_ADDR + j*4;
		reg_oob = REG_READ_U32(reg_num);
		oob_buf[46+k*4+0] = reg_oob & 0xff;
		oob_buf[46+k*4+1] = (reg_oob >> 8) & 0xff;
		if(j==27)
			break;
		oob_buf[46+k*4+2] = (reg_oob >> 16) & 0xff;
		oob_buf[46+k*4+3] = (reg_oob >> 24) & 0xff;
	}

	REG_WRITE_U32(REG_SRAM_CTL, 0x00);
	REG_WRITE_U32(REG_READ_BY_PP,0x80);
	return 0;
}
//----------------------------------------------------------------------------

static int rtk_read_regTrigger(int isCPdisable,int page_size,int triggerMode)
{
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_DMA_IRQ_MASK);
	g_nfFlag = NF_READ_TRIGGER;
#endif
	if(is_NF_CP_Enable_read&&(!isCPdisable))
	{
		REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
		REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
		REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
		REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

		REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
		REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
		REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
	}
	else
		REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(triggerMode));

#if RTK_NAND_INTERRUPT
	RTK_WAIT_EVENT;
#else
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
#endif
	if(is_NF_CP_Enable_read&&(!isCPdisable))//Clear register
	{
		REG_WRITE_U32(REG_CP_NF_SET,0);
	}
	return 0;
}


//----------------------------------------------------------------------------
static int rtk_read_ecc_page_withLargeECC (struct mtd_info *mtd, u16 chipnr, unsigned int page, u_char *data_buf, u_char *oob_buf)
{

	struct nand_chip *this = NULL;
	int rc = 0;
	int dram_sa, dma_len, spare_dram_sa;
	int blank_all_one = 0;
	int page_len;
	int r_unit = 2048;
	int i=0,cnt=0;
//	unsigned int reg_oob, reg_num;
	unsigned char *ptr_oob;
	unsigned int  *ptr_data;

	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int index = 0;
	uint8_t	auto_trigger_mode = 2;
	uint8_t	addr_mode = 1;

	ptr_oob = kmalloc(128,GFP_KERNEL);
	ptr_data = kmalloc(2048,GFP_KERNEL);
//printk("ptr_oob 0x%x\n",ptr_oob);
//printk("ptr_data 0x%x\n",ptr_data);

	this = (struct nand_chip *) mtd->priv;
	page_size = mtd->oobblock;
	oob_size = mtd->oobsize;
	ppb = mtd->erasesize/mtd->oobblock;
	cnt = page_size/r_unit;
	
	if(page_size%r_unit)
	{
		printk("[%s]ERROR page_size not alignment...\n",__FUNCTION__);
		return -1;
	}

	page_size = 2048;

	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	REG_WRITE_U32(REG_BLANK_CHK,NF_BLANK_CHK_blank_ena(1) );
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0));

	if((this->ecc_select == 0x18)||(this->ecc_select == 0x28))
	{
		page_len = page_size >> 10;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(4));
	}
	else
	{
		page_len = page_size >> 9;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(2));
	}
	REG_WRITE_U32(REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));

	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(1));
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));
	REG_WRITE_U32(REG_PP_CTL0,0);

 	if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
 		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
	else if( this->ecc_select == 0x18) //setting for 24bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));

	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_READ_C1));
	REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_READ_C2));
	REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_READ_C3));

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page));
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8));
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16));
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7));
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));
	REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));

	dma_len = page_size >> 9;
	REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

	dram_sa = (((unsigned int)virt_to_phys(data_buf)) >> 3);
	REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));

	if (ptr_oob){
		spare_dram_sa = (((unsigned int)virt_to_phys(ptr_oob)) >> 3);
	}else{
		spare_dram_sa = (((unsigned int)virt_to_phys(this->g_oobbuf)) >> 3);
	}
	if(is_jupiter_cpu()||is_macarthur_cpu())
		REG_WRITE_U32( REG_SPR_DDR_CTL,(0x7<<26) | (spare_dram_sa&0x3ffffff));
	else
		REG_WRITE_U32( REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));
	rtk_read_regTrigger(mtd->isCPdisable_R, page_size,auto_trigger_mode);

	rtk_Process_Buf(oob_buf);
	for(;i<cnt-1;i++)
	{
		data_buf+=2048;
		oob_buf+=92;

		dram_sa = (((unsigned int)virt_to_phys(data_buf)) >> 3);
		
		if (ptr_oob){
			spare_dram_sa = (((unsigned int)virt_to_phys(ptr_oob)) >> 3);
		}else{
			spare_dram_sa = (((unsigned int)virt_to_phys(this->g_oobbuf)) >> 3);
		}
		if(is_jupiter_cpu()||is_macarthur_cpu())
			REG_WRITE_U32( REG_SPR_DDR_CTL,(0x7<<26) | (spare_dram_sa&0x3ffffff));
		else
			REG_WRITE_U32( REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));
		REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));
		rtk_read_regTrigger(mtd->isCPdisable_R, page_size,0x04);
		rtk_Process_Buf(oob_buf);
	}

	if(ptr_oob)
	{
		kfree(ptr_oob);
		ptr_oob=NULL;
	}
	if(ptr_data)
	{
		kfree(ptr_data);
		ptr_data=NULL;
	}

	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	index = page & (32-1);
	blank_all_one = (REG_READ_U32(REG_BLANK_CHK)>>1) & 0x01;

	mtd->nEccMaxValue = REG_MAX_ECC_NUM_max_ecc_num(REG_READ_U32(REG_MAX_ECC_NUM));
	if (blank_all_one)
	{
		if(this->erase_page_flag)
			this->erase_page_flag[chip_section+section] =  (1<< index);
	}

	if (REG_READ_U32(REG_ND_ECC) & 0x0C){
		if(!this->erase_page_flag)
		{
			if (REG_READ_U32(REG_ND_ECC) & 0x08){
				if ( chipnr == 0 && (page < (g_BootcodeSize/page_size)) )
				{
					return 0;
				}
				else
				{
					return -1;
				}
			}
		}
		else
		{
			if (this->erase_page_flag[chip_section+section] & (1<< index) ){
				;
			}else
			{
				if (REG_READ_U32(REG_ND_ECC) & 0x08){
					if ( chipnr == 0 && (page < (g_BootcodeSize/page_size)) )
					{
						return 0;
					}
					else
					{
						return -1;
					}
				}
			}
		}
	}
#if RTK_ARD_ALGORITHM
	g_WinTrigCnt++;
	whichBlk = page / ppb;
	g_RecArray[whichBlk]++;
	if(g_WinTrigCnt > g_WinTrigThrshld)
		travelProcWindow();
#endif
	mtd->isCPdisable_R = 0;
	return rc;
}

//----------------------------------------------------------------------------
//Add read retrial mechanism
//static int nRun,regVal1,regVal2,regVal3,regVal4,nInc;
static void rtk_xfer_SetParameter(unsigned char val1,unsigned char val2,unsigned char val3,unsigned char val4)
{
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	CLR_REG_NAND_ISR;
	g_nfFlag = NF_INIT;
#endif

	//rtk_xfer_GetParameter();
	REG_WRITE_U32(REG_DATA_TL0, 0x1);				//Set data transfer count[7:0]
	REG_WRITE_U32(REG_DATA_TL1, NF_DATA_TL1_access_mode(1) | NF_DATA_TL1_sram_path(0) | NF_DATA_TL1_length1(0x0));				//Set data transfer count[13:8], SRAM path and access mode

	//Transfer command
	REG_WRITE_U32(REG_ND_CMD, 0x36);				//Set CMD1
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x0));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Transfer Reg#1 address
	REG_WRITE_U32(REG_ND_PA0, 0xa7);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_PA2, NF_ND_PA2_addr_mode(0x7) | NF_ND_PA2_page_addr2(0x0));				//Set address mode & PA[20:16]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Reset PP
	REG_WRITE_U32(REG_READ_BY_PP, NF_READ_BY_PP_read_by_pp(0));	//Data read to DRAM from NAND through PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0x1) | NF_PP_CTL0_pp_enable(0x0));				//Set PP starting address[9:8], PP reset and PP enable

	//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_map_sel(1)|NF_SRAM_CTL_access_en(0x1) | NF_SRAM_CTL_mem_region(0x0));	//Enable direct access SRAM
	REG_WRITE_U32(REG_ND_PA0, val1);				//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_access_en(0x0));	//Disable direct access SRAM
	//Set PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0) | NF_PP_CTL0_pp_enable(1));				//Set PP starting address[9:8], PP reset and PP enable
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0));				//Set PP starting address[9:8]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x3));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done
	//Transfer Reg#2 address
	REG_WRITE_U32(REG_ND_PA0, 0xad);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Reset PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0x1) | NF_PP_CTL0_pp_enable(0x0));				//Set PP starting address[9:8], PP reset and PP enable
	//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_map_sel(1)|NF_SRAM_CTL_access_en(0x1) | NF_SRAM_CTL_mem_region(0x0));	//Enable direct access SRAM
	REG_WRITE_U32(REG_ND_PA0, val2);				//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_access_en(0x0));	//Disable direct access SRAM
	//Set PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0) | NF_PP_CTL0_pp_enable(1));				//Set PP starting address[9:8], PP reset and PP enable
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0));				//Set PP starting address[9:8]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x3));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Transfer Reg#3 address
	REG_WRITE_U32(REG_ND_PA0, 0xae);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Reset PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0x1) | NF_PP_CTL0_pp_enable(0x0));				//Set PP starting address[9:8], PP reset and PP enable
	//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_map_sel(1)|NF_SRAM_CTL_access_en(0x1) | NF_SRAM_CTL_mem_region(0x0));	//Enable direct access SRAM
	REG_WRITE_U32(REG_ND_PA0, val3);				//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_access_en(0x0));	//Disable direct access SRAM
	//Set PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0) | NF_PP_CTL0_pp_enable(1));				//Set PP starting address[9:8], PP reset and PP enable
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0));				//Set PP starting address[9:8]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x3));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Transfer Reg#4 address
	REG_WRITE_U32(REG_ND_PA0, 0xaf);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Reset PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0x1) | NF_PP_CTL0_pp_enable(0x0));				//Set PP starting address[9:8], PP reset and PP enable
	//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_map_sel(1)|NF_SRAM_CTL_access_en(0x1) | NF_SRAM_CTL_mem_region(0x0));	//Enable direct access SRAM
	REG_WRITE_U32(REG_ND_PA0, val4);				//Set data
	REG_WRITE_U32(REG_SRAM_CTL,NF_SRAM_CTL_access_en(0x0));	//Disable direct access SRAM
	//Set PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0) | NF_PP_CTL0_pp_enable(1));				//Set PP starting address[9:8], PP reset and PP enable
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0));				//Set PP starting address[9:8]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x3));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Transfer command
	REG_WRITE_U32(REG_ND_CMD, 0x16);				//Set CMD1
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x0));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done
	//printk("Set and Get value...\n");
	//rtk_xfer_GetParameter();
	//	printk("[%s]%d,%d,%d,%d\n",__FUNCTION__,val1,val2,val3,val4);
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	CLR_REG_NAND_ISR;
	g_nfFlag = NF_INIT;
#endif

}
//----------------------------------------------------------------------------
static void rtk_xfer_GetParameter()
{
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	CLR_REG_NAND_ISR;
	g_nfFlag = NF_INIT;
#endif

#if 1 //Get parameter from DRAM

	regVal1=(REG_READ_U32(0xb8007660)>>24)&0x000000ff ;
	regVal2=(REG_READ_U32(0xb8007660)>>16)&0x000000ff ;
	regVal3=(REG_READ_U32(0xb8007660)>>8)&0x000000ff ;
	regVal4=REG_READ_U32(0xb8007660)&0x000000ff ;

#else

	REG_WRITE_U32(REG_DATA_TL0, 0x1);				//Set data transfer count[7:0]
	REG_WRITE_U32(REG_DATA_TL1, NF_DATA_TL1_access_mode(1) | NF_DATA_TL1_sram_path(0) | NF_DATA_TL1_length1(0x0));				//Set data transfer count[13:8], SRAM path and access mode

	//Set PP
	REG_WRITE_U32(REG_READ_BY_PP, NF_READ_BY_PP_read_by_pp(0));	//Data read to DRAM from NAND through PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0) | NF_PP_CTL0_pp_enable(1));				//Set PP starting address[9:8], PP reset and PP enable
	REG_WRITE_U32(REG_PP_CTL1, 0x0);				//Set PP starting assdress[7:0]
	//Set table sram
	//REG_WRITE_U32(NF_TABLE_CTL_reg, NF_TABLE_CTL_table_start_addr(0x0) | NF_TABLE_CTL_table_enable(0));				//Set table SRAM starting assdress ( 0 ~ A) and enable table SRAM

	//Transfer command
	REG_WRITE_U32(REG_ND_CMD, 0x37);				//Set CMD1
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x0));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done
//test hang

	//Transfer Reg#1 address
	REG_WRITE_U32(REG_ND_PA0, 0xa7);
	REG_WRITE_U32(REG_ND_PA2, NF_ND_PA2_addr_mode(0x7) | NF_ND_PA2_page_addr2(0x0));	//Set reg#1
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done
//test ok
	//Get data
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x2));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80,0x00);					//Wait xfer done
	REG_WRITE_U32((unsigned long)&regVal1, REG_READ_U32(REG_ND_DAT));
//test err


	//Transfer Reg#2 address
	REG_WRITE_U32(REG_ND_PA0, 0xad);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Get data
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x2));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done
	REG_WRITE_U32((unsigned long)&regVal2, REG_READ_U32(REG_ND_DAT));

	//Transfer Reg#3 address
	REG_WRITE_U32(REG_ND_PA0, 0xae);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Get data
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x2));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80,0x00);					//Wait xfer done
	REG_WRITE_U32((unsigned long)&regVal3, REG_READ_U32(REG_ND_DAT));


	//Transfer Reg#4 address
	REG_WRITE_U32(REG_ND_PA0, 0xaf);				//Set PA[7:0]
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x1));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done

	//Get data
	REG_WRITE_U32(REG_ND_CTL, NF_ND_CTL_xfer(1) | NF_ND_CTL_ecc_enable(0) | NF_ND_CTL_tran_mode(0x2));				//Enable Xfer, eanble ECC and set transfer mode
	WAIT_DONE(REG_ND_CTL, 0x80, 0x00);					//Wait xfer done
	REG_WRITE_U32((unsigned long)&regVal4, REG_READ_U32(REG_ND_DAT));

	//Reset PP
	REG_WRITE_U32(REG_PP_CTL0, NF_PP_CTL0_pp_start_addr(0x0) | NF_PP_CTL0_pp_reset(0x1) | NF_PP_CTL0_pp_enable(0x0)); 			//Set PP starting address[9:8], PP reset and PP enable
	#endif

	//	printk("[%s]%d,%d,%d,%d\n",__FUNCTION__,regVal1,regVal2,regVal3,regVal4);
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	CLR_REG_NAND_ISR;
	g_nfFlag = NF_INIT;
#endif

}
//----------------------------------------------------------------------------
#if 0
static void rtk_SetVal( char val1, char val2, char val3, char val4)
{
	rtk_xfer_GetParameter();
	regVal1+=val1;
	regVal2+=val2;
	regVal3+=val3;
	regVal4+=val4;
	rtk_xfer_SetParameter(regVal1,regVal2,regVal3,regVal4);
}
#endif
//----------------------------------------------------------------------------
static void rtk_SetReadRetrialMode(unsigned int run)
{

	if((regVal1==0)&&(regVal2==0)&&(regVal3==0)&&(regVal4==0))
		rtk_xfer_GetParameter();
	run%=7;

	if(run!=nRun)
		printk("\n\n$$run %d,[Run %d]\n",run,nRun);
	switch(run)
	{

	#if 1
		case 1:
			//rtk_SetVal(0x00,0x06,0x0A,0x06);
			rtk_xfer_SetParameter(regVal1,regVal2+0x06,regVal3+0x0A,regVal4+0x06);

		break;

		case 2:
			//rtk_SetVal(0xff,-0x03,-0x07,-0x08);
			rtk_xfer_SetParameter(0x00,regVal2-0x03,regVal3-0x07,regVal4-0x08);

		break;

		case 3:
			//rtk_SetVal(0xff,-0x06,-0x0D,-0x0F);
			rtk_xfer_SetParameter(0x00,regVal2-0x06,regVal3-0x0D,regVal4-0x0F);

		break;

		case 4:
			//rtk_SetVal(0xff,-0x09,-0x14,-0x17);
			rtk_xfer_SetParameter(0x00,regVal2-0x09,regVal3-0x14,regVal4-0x17);
		break;

		case 5:
			//rtk_SetVal(0xff,0xff,-0x1A,-0x1E);
			rtk_xfer_SetParameter(0x00,0x00,regVal3-0x1A,regVal4-0x1E);

		break;

		case 6:

			//rtk_SetVal(0xff,0xff,-0x20,-0x25);
			rtk_xfer_SetParameter(0x00,0x00,regVal3-0x20,regVal4-0x25);

		break;
#endif
		default:
			//rtk_xfer_SetParameter(regVal1,regVal2,regVal3,regVal4);
		break;
	}
}
//----------------------------------------------------------------------------
static int rtk_read_ecc_page_reTrial (struct mtd_info *mtd, u16 chipnr, unsigned int page, u_char *data_buf, u_char *oob_buf)
{

	struct nand_chip *this = NULL;
	int rc = 0;
	int dram_sa, dma_len, spare_dram_sa;
	int blank_all_one = 0;
	int page_len;

	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int index = 0;
	uint8_t	auto_trigger_mode = 2;
	uint8_t	addr_mode = 1;
	//printk("[%s]scramble 0x%x\n",__FUNCTION__,mtd->isScramble);
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_DMA_IRQ_MASK);
	g_nfFlag = NF_READ_TRIGGER;
#endif
	nInc=0;
	while(nInc<7)
	{
		rtk_SetReadRetrialMode(nInc+nRun);

		this = (struct nand_chip *) mtd->priv;
		page_size = mtd->oobblock;
		oob_size = mtd->oobsize;
		ppb = mtd->erasesize/mtd->oobblock;
		this->ecc_err_flag = 0;

		if ( chipnr == 0 && page < (g_CP_Disable_area/page_size))
		{
			mtd->isCPdisable_R = 1;
			mtd->isScramble=MTD_SCRAMBLE_DISABLE;
		}
		else
			mtd->isScramble=1;

		if((mtd->ecctype==MTD_ECC_RTK_HW)&&(this->ecc_select==0x18||this->ecc_select==0x28))
		{
			if(!oob_buf)
			{
				rc = rtk_read_ecc_page_withLargeECC(mtd,chipnr,page,data_buf,this->g_oobbuf);
			}
			else
				rc = rtk_read_ecc_page_withLargeECC(mtd,chipnr,page,data_buf,oob_buf);
			if(rc==0)
			{
				nRun+=nInc;
				nRun%=7;
				return rc;
			}
			else
			{
				nInc++;
				rc=-1;
				continue;
			}
		}

		if(g_edo_mode_enable)
			REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
		else
			REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
		//REG_WRITE_U32(0x01,0xb801032c);	//Enable NAND/CardReader arbitrator add by alexchang 0303-2010
		REG_WRITE_U32(REG_BLANK_CHK,NF_BLANK_CHK_blank_ena(1) );
		REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0));

		if((this->ecc_select == 0x18)||(this->ecc_select == 0x28))
		{
			page_len = page_size >> 10;
			REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(4));
		}
		else
		{
			page_len = page_size >> 9;
			REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(2));
		}
		REG_WRITE_U32(REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));

		REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(1));
		REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));
		REG_WRITE_U32(REG_PP_CTL0,0);

		if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
			REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
		else if( this->ecc_select == 0x18) //setting for 24bits ecc.
			REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
		else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
			REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
		else
			REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));

		REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_READ_C1));
		REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_READ_C2));
		REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_READ_C3));

		REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page));
		REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8));
		REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16));
		REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7));
		REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
		REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));
		REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));

		dma_len = page_size >> 9;
		REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

		dram_sa = (((unsigned int)virt_to_phys(data_buf)) >> 3);

		REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));

		if (oob_buf){
			spare_dram_sa = (((unsigned int)virt_to_phys(oob_buf)) >> 3);
		}else{
			spare_dram_sa = (((unsigned int)virt_to_phys(this->g_oobbuf)) >> 3);
		}
		if(is_jupiter_cpu()||is_macarthur_cpu())
			REG_WRITE_U32( REG_SPR_DDR_CTL,(0x7<<26) | (spare_dram_sa&0x3ffffff));
		else
			REG_WRITE_U32( REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));


#if RTK_NAND_INTERRUPT
		NF_RESET_IRQ;
		NF_ENABLE_IRQ(NF_DMA_IRQ_MASK);
		g_nfFlag = NF_READ_TRIGGER;
#endif
		//printk("Retry[%s]Ran 0x%x, scr 0x%x, flag 0x%x\n",__FUNCTION__,g_isRandomize,mtd->isScramble,mtd->isCPdisable_R);
		//printk("R blk:%u, page:%u\n",page/ppb,page%ppb);

		if((g_isRandomize&&(!mtd->isCPdisable_R))||(mtd->isScramble!=MTD_SCRAMBLE_DISABLE))
		{
			//printk("Ran 0x%x\n",g_isRandomize);
			//printk("isCPdisable_R 0x%x\n",mtd->isCPdisable_R);
			//printk("isScramble 0x%x\n",mtd->isScramble);
	                //printk("page 0x%x\n",page);
			//printk("@");
			if(u32CP_mode==0)//CBC initial key setting.
			{
				REG_WRITE_U32( REG_CP_NF_INI_KEY,page);
			}
			REG_WRITE_U32(REG_CP_NF_KEY,0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),0x12345678);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
			
			dma_map_single(NULL, data_buf, page_size,  DMA_FROM_DEVICE);
			
			if ( oob_buf )
				dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);
			else
				dma_map_single(NULL, this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);
				
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{

			if(is_NF_CP_Enable_read&&(!mtd->isCPdisable_R))
			{
				//printk("X");
				REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
				REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
				REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
				REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

				REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
				REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
				
				dma_map_single(NULL, data_buf, page_size,  DMA_FROM_DEVICE);
				
				if ( oob_buf )
					dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);
				else
					dma_map_single(NULL, this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);
				
				REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
			}
			else
			{//printk("/");
				
				dma_map_single(NULL, data_buf, page_size,  DMA_FROM_DEVICE);
				
				if ( oob_buf )
					dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);
				else
					dma_map_single(NULL, this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);
				
				REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
			}
		}

		REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(auto_trigger_mode));

#if RTK_NAND_INTERRUPT
		RTK_WAIT_EVENT;
#else
		WAIT_DONE(REG_AUTO_TRIG,0x80,0);
		WAIT_DONE(REG_DMA_CTL3,0x01,0);
		
		WAIT_DONE(REG_ND_CTL,0x40,0x40);		
#endif

	dma_unmap_single(NULL, virt_to_phys(data_buf), page_size, DMA_FROM_DEVICE);
	if ( oob_buf )
		dma_unmap_single(NULL, virt_to_phys(oob_buf), oob_size, DMA_FROM_DEVICE);
	else
		dma_unmap_single(NULL, virt_to_phys( this->g_oobbuf), oob_size,  DMA_FROM_DEVICE);

		if((is_NF_CP_Enable_read&&(!mtd->isCPdisable_R))||g_isRandomize)//Clear register
		{
			REG_WRITE_U32(REG_CP_NF_SET,0);
		}

		if(oob_buf)
		{
			if(this->ecc_select==0x18||this->ecc_select==0x28)
				reverse_to_Tags(oob_buf,this->ecc_select);
			else
			{
				REG_WRITE_U32(REG_READ_BY_PP,0x00);
				if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_sirius_cpu())
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x02);
				else
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x04);
				rtk_read_oob_from_SRAM(mtd, oob_buf);
				REG_WRITE_U32(REG_SRAM_CTL, 0x00);
				REG_WRITE_U32(REG_READ_BY_PP,0x80);
			}
		}

		chip_section = (chipnr * this->page_num) >> 5;
		section = page >> 5;
		index = page & (32-1);
		blank_all_one = (REG_READ_U32(REG_BLANK_CHK)>>1) & 0x01;


		// add by alexchang 01-28-2011
		mtd->nEccMaxValue = REG_MAX_ECC_NUM_max_ecc_num(REG_READ_U32(REG_MAX_ECC_NUM));
		if (blank_all_one)
		{
			if(this->erase_page_flag)
				this->erase_page_flag[chip_section+section] =  (1<< index);
			else{
				nRun+=nInc;
				nRun%=7;
				return 0;				
			}
		}

		if (REG_READ_U32(REG_ND_ECC) & 0x0C){
			if(!this->erase_page_flag)
			{
				if (REG_READ_U32(REG_ND_ECC) & 0x08){
					if ( chipnr == 0 && page < g_BootcodeSize/page_size )
					{
						nRun+=nInc;
						nRun%=7;
						return 0;
					}
					else
					{
						//printk("0[%s]nInc %d,nRun %d\n",__FUNCTION__,nInc,nRun);
						nInc++;
						rc=-1;
						printk("!!!Read Fail page NO. 0x%x\n",page);
						continue;
					}
				}
			}
			else
			{
				if (this->erase_page_flag[chip_section+section] & (1<< index) ){
					nRun+=nInc;
					nRun%=7;
					return 0;

				}else
				{
					if (REG_READ_U32(REG_ND_ECC) & 0x08){
						if ( chipnr == 0 && page < g_BootcodeSize/page_size )
						{
							nRun+=nInc;
							nRun%=7;
							return 0;
						}
						else
						{
							//printk("1[%s]nInc %d,nRun %d\n",__FUNCTION__,nInc,nRun);
							nInc++;
							rc=-1;
							printk("!!!Read Fail page NO. 0x%x\n",page);
							continue;
						}
					}
				}
			}
			if(REG_READ_U32(REG_ND_ECC) & 0x04){
				if((REG_READ_U32(REG_MAX_ECC_NUM) & 0x3F) > this->ecc_safe_value){
					printk("[%s][%d]blk %d, page %d ecc error warning,ecc_num = 0x%x\n",__FUNCTION__,__LINE__,page/ppb,page%ppb,REG_READ_U32(REG_RSECC_NUM));
					this->ecc_err_flag = 1;
				}
			}			
		}

#if RTK_ARD_ALGORITHM
		whichBlk = page / ppb;
		g_RecArray[whichBlk]++;
		if(g_WinTrigCnt > g_WinTrigThrshld)
			travelProcWindow();
#endif
		mtd->isCPdisable_R = 0;
		rc=0;
		break;

	}
	//printk("return rc %d\n",rc);
	nRun+=nInc;
	nRun%=7;

	return rc;
}


//----------------------------------------------------------------------------


static int rtk_erase_block(struct mtd_info *mtd, u16 chipnr, int page)
{
	struct nand_chip *this = NULL;
	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int retryCnt = RETRY_COUNT;
	page_size = mtd->oobblock;
	oob_size = mtd->oobsize;
	ppb = mtd->erasesize/mtd->oobblock;
	
	//printk("erasesize 0x%x,oobblock 0x%x\n",mtd->erasesize,mtd->oobblock);
	//printk("AT[%s]:show chipnr %d\n",__FUNCTION__,chipnr);
	
	padlock(PAD_NAND);   // lock nand・s pad
#ifdef MTD_NAND_RTK_NAND_TEST
	if(test_erase_fail_remap != 0){
		printk("%s: page %d  block %d enter erase remap test mode!!\n", 
			__FUNCTION__, page,page/ppb);
		test_erase_fail_remap = 0;
		return -1;
	}
    printk("%s enter page %d   block %d  \n", __FUNCTION__,page,page/ppb);
#endif
	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,page);
		if(retryCnt<=0)
		{
			printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,page);
			
			padunlock(PAD_NAND);   // unlock nand・s pad
			
			return -ERESTARTSYS;
		}
		retryCnt--;
	}
	this = (struct nand_chip *) mtd->priv;
	//printk("AT[%s]:page %d, ppb %d, mtd->erasesize %u, mtd->oobblock %u\n",__FUNCTION__,page,ppb,mtd->erasesize,mtd->oobblock);
	if ( page & (ppb-1) ){
		printk("%s: page %d is not block alignment !!\n", __FUNCTION__, page);
		up (&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -1;
	}

	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Disable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_dis);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_dis);//Set Value
				break;
			}
		REG_WRITE_U32( REG_CMD3,NF_CMD3_cmd3(CMD_BLK_ERASE_C3));
		REG_WRITE_U32( REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(0x07)|NF_POLL_FSTS_trig_poll(1));
		WAIT_DONE(REG_POLL_FSTS,0x1,0);
		}
	}

#if RTK_NAND_INTERRUPT
	g_nfFlag = NF_ERASE_TRIGGER;
	NF_RESET_IRQ;
#endif

	//REG_WRITE_U32(0x01,0xb801032c);	//Enable NAND/CardReader arbitrator add by alexchang 0303-2010
	
	REG_WRITE_U32( REG_ND_CMD,NF_ND_CMD_cmd(CMD_BLK_ERASE_C1) );
	REG_WRITE_U32( REG_CMD2,NF_CMD2_cmd2(CMD_BLK_ERASE_C2) );
	REG_WRITE_U32( REG_CMD3,NF_CMD3_cmd3(CMD_BLK_ERASE_C3) );

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page) );
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8) );
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(0x04)|NF_ND_PA2_page_addr2(page>>16) );
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>> 21)&0x7) );
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));

	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(1)|NF_AUTO_TRIG_auto_case(2) );
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);

#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_POLL_IRQ_MASK);
	g_nfFlag = NF_ERASE_TRIGGER;
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	RTK_WAIT_EVENT;
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_IRQ_MASK);
#else
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	WAIT_DONE(REG_POLL_FSTS,0x01,0x0);
	WAIT_DONE(REG_ND_CTL,0x40,0x40);//add by alexchang 0416-2010
#endif

	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_en);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_en);//Set Value
				break;
			}

		}
	}

	if ( REG_READ_U32(REG_ND_DAT) & 0x01 ){
		up (&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		printk("[%s] erasure is not completed at block %d\n", __FUNCTION__, page/ppb);
		if ( chipnr == 0 && page >= 0 && page < g_BootcodeSize/page_size )
			return 0;
		else
			return -1;
	}

	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	if(this->erase_page_flag)
		memset ( (__u32 *)(this->erase_page_flag)+ chip_section + section, 0xff, ppb>>3);
	//printk("[AT]Erase block : %u  \n\n\n",page/ppb);
	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad
#if RTK_ARD_ALGORITHM
	g_RecArray[page/ppb]=0;
	//	printk("[AT]Erase block : %u  \n",page/ppb);
#endif
	return 0;
}
//----------------------------------------------------------------------------
unsigned char *malloc_aligned(size_t size,int alignment)
{
	unsigned char *ptr = kmalloc(size + alignment-1,GFP_KERNEL);
	if (!ptr) return NULL;
	ptr = (unsigned char *)(((unsigned int)(ptr) + alignment-1) & ~alignment);
	return ptr;
}
//----------------------------------------------------------------------------

static int rtk_read_oob (struct mtd_info *mtd, u16 chipnr, int page, int len, u_char *oob_buf)
{
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int rc = 0;
	int dram_sa, dma_len, spare_dram_sa;
	int blank_all_one=0;
	int page_len;
	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int index = 0;
	unsigned int retryCnt = RETRY_COUNT;
	uint8_t auto_trigger_mode = 2;
	uint8_t addr_mode = 1;
	page_size = mtd->oobblock;
	oob_size = mtd->oobsize;
	ppb = mtd->erasesize/mtd->oobblock;
	this->ecc_err_flag = 0;
	padlock(PAD_NAND);   // lock nand・s pad

	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,page);
		if(retryCnt<=0)
		{
			printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,page);
			padunlock(PAD_NAND);   // unlock nand・s pad
			return -ERESTARTSYS;
		}
		retryCnt--;
	}

	//------------------------set random mode-------------------
	if (nf_is_random_mode()){
		nf_set_random_read(mtd->oobblock, 0);
	}
	
	if(g_enReadRetrial)
	{
		if(!oob_buf)
		{
			rc = rtk_read_ecc_page_reTrial(mtd,chipnr,page,this->g_databuf,this->g_oobbuf);
		}
		else
			rc = rtk_read_ecc_page_reTrial(mtd,chipnr,page,this->g_databuf,oob_buf);
		up(&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return rc;
	}

	if ( len>oob_size || !oob_buf ){
		printk("[%s] error: len>oob_size OR oob_buf is NULL\n", __FUNCTION__);
		up (&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -1;
	}
	
	if ( chipnr == 0 && page >= 0 && page < g_CP_Disable_area/page_size )
		mtd->isCPdisable_R = 1;

	dma_map_single(NULL,this->g_databuf, page_size,  DMA_FROM_DEVICE);
	if ( oob_buf )
		dma_map_single(NULL,oob_buf, oob_size,  DMA_FROM_DEVICE);

	if((mtd->ecctype==MTD_ECC_RTK_HW)&&(this->ecc_select==0x18||this->ecc_select==0x28))
	{
		rc = rtk_read_ecc_page_withLargeECC(mtd,chipnr,page,this->g_databuf,oob_buf);
		up(&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return rc;
	}
	
	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	REG_WRITE_U32(REG_BLANK_CHK,NF_BLANK_CHK_blank_ena(1));
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0)); //REG:0x100
	if((this->ecc_select == 0x18)||(this->ecc_select==0x28))
	{
		page_len = page_size >> 10;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(4));
	}
	else
	{
		page_len = page_size >> 9;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(2));
	}
	REG_WRITE_U32(REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));

	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(1));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL0,0);//add by alexchang 0208-2010

 	if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
 		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
	else if( this->ecc_select == 0x18) //setting for 24bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));

	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_READ_C1));
	REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_READ_C2));
	REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_READ_C3));

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page) );
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8) );
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16) );
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7) );
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));

	//Set ECC
	REG_WRITE_U32(REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(1));//add by alexchang0223-2010

	//Set DMA
	dram_sa = (((unsigned int)virt_to_phys(this->g_databuf)) >> 3);
	REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));

	dma_len = page_size >> 9;
	REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

	spare_dram_sa = (((unsigned int)virt_to_phys(oob_buf)) >> 3);
	if(is_jupiter_cpu())
		REG_WRITE_U32(REG_SPR_DDR_CTL,(0x07<<26)|(spare_dram_sa&0x3ffffff));
	else
		REG_WRITE_U32( REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));

#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_DMA_IRQ_MASK);
	g_nfFlag = NF_READ_TRIGGER;
#endif
	if(g_isRandomize&&(!mtd->isCPdisable_R))
	{
		if(u32CP_mode==0)//CBC initial key setting.
		{
			REG_WRITE_U32( REG_CP_NF_INI_KEY,page);
		}
		REG_WRITE_U32(REG_CP_NF_KEY,0x12345678);
		REG_WRITE_U32((REG_CP_NF_KEY+0x4),0x12345678);
		REG_WRITE_U32((REG_CP_NF_KEY+0x8),0x12345678);
		REG_WRITE_U32((REG_CP_NF_KEY+0xc),0x12345678);

		REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
		REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
		
		dma_map_single(NULL, this->g_databuf, page_size,  DMA_FROM_DEVICE);
		if ( oob_buf )
			dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);

		REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));

	}
	else
	{
		if(is_NF_CP_Enable_read&&(!mtd->isCPdisable_R))
		{
			REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
			
			dma_map_single(NULL, this->g_databuf, page_size,  DMA_FROM_DEVICE);
			if ( oob_buf )
				dma_map_single(NULL,oob_buf, oob_size,  DMA_FROM_DEVICE);

			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{
			dma_map_single(NULL,this->g_databuf, page_size,  DMA_FROM_DEVICE);
			if ( oob_buf )
				dma_map_single(NULL,oob_buf, oob_size,  DMA_FROM_DEVICE);

			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_ddr_wr(1)|NF_DMA_CTL3_dma_xfer(1));
		}
	}
	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(auto_trigger_mode));
	//WAIT_DONE(REG_AUTO_TRIG,0x80,0);

#if RTK_NAND_INTERRUPT
	RTK_WAIT_EVENT;
#else
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
	
	WAIT_DONE(REG_ND_CTL,0x40,0x40);	
#endif

	dma_unmap_single(NULL, virt_to_phys(this->g_databuf), page_size, DMA_FROM_DEVICE);
	if ( oob_buf )
		dma_unmap_single(NULL, virt_to_phys(oob_buf), oob_size, DMA_FROM_DEVICE);

	if((is_NF_CP_Enable_read&&(!mtd->isCPdisable_R))||g_isRandomize)//Clear register
	{
		REG_WRITE_U32(REG_CP_NF_SET,0);
	}

	if(oob_buf)
	{
		if(this->ecc_select==0x18||this->ecc_select==0xc||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
			reverse_to_Tags(oob_buf,this->ecc_select);
		else
		{
			if( ! is_jupiter_cpu() )
			{
				REG_WRITE_U32(REG_READ_BY_PP,0x00);
				
				if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_sirius_cpu())
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x02);
				else
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x04);

				rtk_read_oob_from_SRAM(mtd, oob_buf);
				REG_WRITE_U32(REG_SRAM_CTL, 0x00);
				REG_WRITE_U32(REG_READ_BY_PP,0x80);
			}
			if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
				reverse_to_Tags(oob_buf,this->ecc_select);
		}
#if 0
			if( ! is_jupiter_cpu() )
			{
				REG_WRITE_U32(REG_READ_BY_PP,0x00);

				if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_sirius_cpu())
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x02);
				else
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x04);

				rtk_read_oob_from_SRAM(mtd, oob_buf);
				REG_WRITE_U32(REG_SRAM_CTL, 0x00);
				REG_WRITE_U32(REG_READ_BY_PP,0x80);
			}
#endif
	}
//oobReadCnt++;
//printk("\t oob read cnt %u\n",oobReadCnt);
	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	index = page & (32-1);
	blank_all_one = (REG_READ_U32(REG_BLANK_CHK)>>1) & 0x01;
	if (blank_all_one)
	{
		if(this->erase_page_flag)
			this->erase_page_flag[chip_section+section] =  (1<< index);
		else{
			up (&sem_NF_CARDREADER);
			padunlock(PAD_NAND);   // unlock nand・s pad	
			return 0;	// return OK if all data bit is 1 (page is not written yet)
		}
	}

	if (REG_READ_U32(REG_ND_ECC) & 0x0C){
		if(!this->erase_page_flag)
		{
			if (REG_READ_U32(REG_ND_ECC) & 0x08){
				if ( chipnr == 0 && page >= 0 && page < g_BootcodeSize/page_size )
				{
					up (&sem_NF_CARDREADER);
					padunlock(PAD_NAND);   // unlock nand・s pad
					return 0;
				}
				else
				{
					up (&sem_NF_CARDREADER);
					padunlock(PAD_NAND);   // unlock nand・s pad
					printk("[%s]blk %d, page %d fail\n",__FUNCTION__,page/ppb,page%ppb);
					return -1;
				}
			}
		}
		else
		{
			if (this->erase_page_flag[chip_section+section] & (1<< index) ){
				up (&sem_NF_CARDREADER);
				padunlock(PAD_NAND);   // unlock nand・s pad
				return 0;	// return OK if all data bit is 1 (page is not written yet)
			}
			else{
				if (REG_READ_U32(REG_ND_ECC) & 0x08){
					if ( chipnr == 0 && page >= 0 && page < g_BootcodeSize/page_size )
					{
						up (&sem_NF_CARDREADER);
						padunlock(PAD_NAND);   // unlock nand・s pad
						return 0;
					}
					else
					{
						up (&sem_NF_CARDREADER);
						printk("[%s]blk %d, page %d fail\n",__FUNCTION__,page/ppb,page%ppb);
						padunlock(PAD_NAND);   // unlock nand・s pad
						return -1;
					}
				}
			}
		}

		if(REG_READ_U32(REG_ND_ECC) & 0x04){
			if((REG_READ_U32(REG_MAX_ECC_NUM) & 0x3F) > this->ecc_safe_value){
				printk("[%s][%d]blk %d, page %d ecc error warning,ecc_num = 0x%x\n",__FUNCTION__,__LINE__,page/ppb,page%ppb,REG_READ_U32(REG_RSECC_NUM));
				this->ecc_err_flag = 1;
			}
		}
	}
	
	mtd->isCPdisable_R = 0;
	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad
	return rc;
}
//----------------------------------------------------------------------------
static int rtk_read_ecc_page (struct mtd_info *mtd, u16 chipnr, unsigned int page, u_char *data_buf, u_char *oob_buf)
{
//static unsigned int eccReadCnt = 0;
	struct nand_chip *this = NULL;
	int rc = 0;
	int dram_sa, dma_len, spare_dram_sa;
	int blank_all_one = 0;
	int page_len;

	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int index = 0;
	unsigned int retryCnt = RETRY_COUNT;
	uint8_t	auto_trigger_mode = 2;
	uint8_t	addr_mode = 1;
	unsigned int dma_addr_databuf, dma_addr_oobbuf;	
	
	this = (struct nand_chip *) mtd->priv;

	
	page_size = mtd->oobblock;
	oob_size = mtd->oobsize;
	ppb = mtd->erasesize/mtd->oobblock;
	this->ecc_err_flag = 0;
	//printk("[%s]scramble 0x%x\n",__FUNCTION__,mtd->isScramble);
	padlock(PAD_NAND);   // lock nand・s pad
#ifdef MTD_NAND_RTK_NAND_TEST
	if(test_read_fail_remap == 1){
		test_read_fail_remap = 0;
		printk("%s enter page %d read fail ecc error case \n", __FUNCTION__,page);
		return -1;
	}
	//if((page%this->ppb == 0)||(page == 131071)){
		// printk("%s enter page %d  block %d erase_page_flag %d\n", __FUNCTION__,page,page/this->ppb,this->erase_page_flag);
	//}
#endif
	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,page);
		if(retryCnt<=0)
		{
			printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,page);
			padunlock(PAD_NAND);   // unlock nand・s pad
			return -ERESTARTSYS;
		}
		retryCnt--;
	}

        if(((uint32_t)data_buf&0x7)!=0)
        {
                printk("[%s]data_buf must 8 byte alignmemt!!\n",__FUNCTION__);
                BUG();
        }
	if ( chipnr == 0 && page < (g_CP_Disable_area/page_size ))
	{
                mtd->isCPdisable_R = 1;
                mtd->isScramble=MTD_SCRAMBLE_DISABLE;
	}

	//------------------------set random mode-------------------
	if (nf_is_random_mode()){
		nf_set_random_read(mtd->oobblock, 0);
	}

	if(g_enReadRetrial)
	{
		if(!oob_buf)
		{
			rc = rtk_read_ecc_page_reTrial(mtd,chipnr,page,data_buf,this->g_oobbuf);
		}
		else
			rc = rtk_read_ecc_page_reTrial(mtd,chipnr,page,data_buf,oob_buf);
		up(&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return rc;
	}

	//if ( chipnr == 0 && page >= 0 && page < g_BootcodeSize/page_size )
	//	mtd->isCPdisable_R = 1;

	if ( chipnr == 0 && page < g_CP_Disable_area/page_size)
		mtd->isCPdisable_R = 1;

	dma_addr_databuf = dma_map_single(NULL, data_buf, page_size,  DMA_FROM_DEVICE);
	if ( oob_buf )
		dma_addr_oobbuf = dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);
	else
		dma_addr_oobbuf = dma_map_single(NULL, this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);

	if((mtd->ecctype==MTD_ECC_RTK_HW)&&(this->ecc_select==0x18||this->ecc_select==0x28))
	{
		if(!oob_buf)
		{
			rc = rtk_read_ecc_page_withLargeECC(mtd,chipnr,page,data_buf,this->g_oobbuf);
		}
		else
			rc = rtk_read_ecc_page_withLargeECC(mtd,chipnr,page,data_buf,oob_buf);
		up(&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return rc;
	}

	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	//REG_WRITE_U32(0x01,0xb801032c);	//Enable NAND/CardReader arbitrator add by alexchang 0303-2010
	REG_WRITE_U32(REG_BLANK_CHK,NF_BLANK_CHK_blank_ena(1) );
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0));

	if((this->ecc_select == 0x18)||(this->ecc_select==0x28))
	{
		page_len = page_size >> 10;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(4));
	}
	else
	{
		page_len = page_size >> 9;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_access_mode(1)|NF_DATA_TL1_length1(2));
	}
	REG_WRITE_U32(REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));

	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(1));
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));
	REG_WRITE_U32(REG_PP_CTL0,0);

 	if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
 		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
	else if( this->ecc_select == 0x18) //setting for 24bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));

	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_READ_C1));
	REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_READ_C2));
	REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_READ_C3));

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page));
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8));
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16));
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7));
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));
	REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));

	dma_len = page_size >> 9;
	REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

	dram_sa = (((unsigned int)virt_to_phys(data_buf)) >> 3);
	REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));

	if (oob_buf){
		spare_dram_sa = (((unsigned int)virt_to_phys(oob_buf)) >> 3);
	}else{
		spare_dram_sa = (((unsigned int)virt_to_phys(this->g_oobbuf)) >> 3);
	}
	if(is_jupiter_cpu())
		REG_WRITE_U32( REG_SPR_DDR_CTL,(0x7<<26) | (spare_dram_sa&0x3ffffff));
	else
		REG_WRITE_U32( REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));

#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_DMA_IRQ_MASK);
	g_nfFlag = NF_READ_TRIGGER;
#endif
	//printk("[%s]Ran 0x%x, scr 0x%x, flag 0x%x\n",__FUNCTION__,g_isRandomize,mtd->isScramble,mtd->isCPdisable_R);
	if(g_isRandomize&&(!mtd->isCPdisable_R))
	{

		if(u32CP_mode==0)//CBC initial key setting.
		{
			REG_WRITE_U32( REG_CP_NF_INI_KEY,page);
		}
		REG_WRITE_U32(REG_CP_NF_KEY,0x12345678);
		REG_WRITE_U32((REG_CP_NF_KEY+0x4),0x12345678);
		REG_WRITE_U32((REG_CP_NF_KEY+0x8),0x12345678);
		REG_WRITE_U32((REG_CP_NF_KEY+0xc),0x12345678);

		REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
		REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));

		dma_addr_databuf = dma_map_single(NULL, data_buf, page_size,  DMA_FROM_DEVICE);
		if ( oob_buf )
			dma_addr_oobbuf = dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);
		else
			dma_addr_oobbuf = dma_map_single(NULL, this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);

		REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
	}
	else
	{
		if(is_NF_CP_Enable_read&&(!mtd->isCPdisable_R))
		{
			REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));

			dma_addr_databuf = dma_map_single(NULL, data_buf, page_size,  DMA_FROM_DEVICE);
			if ( oob_buf )
				dma_addr_oobbuf = dma_map_single(NULL, oob_buf, oob_size,  DMA_FROM_DEVICE);
			else
				dma_addr_oobbuf = dma_map_single(NULL, this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{

			dma_addr_databuf = dma_map_single(NULL,data_buf, page_size,  DMA_FROM_DEVICE);
			if ( oob_buf )
				dma_addr_oobbuf = dma_map_single(NULL,oob_buf, oob_size,  DMA_FROM_DEVICE);
			else
				dma_addr_oobbuf = dma_map_single(NULL,this->g_oobbuf, oob_size,  DMA_FROM_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0x1)|NF_DMA_CTL3_dma_xfer(0x1));
		}
	}

	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(auto_trigger_mode));

#if RTK_NAND_INTERRUPT
	RTK_WAIT_EVENT;
#else
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
	
	WAIT_DONE(REG_ND_CTL,0x40,0x40);	
#endif

	dma_unmap_single(NULL, dma_addr_databuf, page_size,  DMA_FROM_DEVICE);
	outer_flush_range(dma_addr_databuf, (dma_addr_databuf + page_size));
	if ( oob_buf ){
		dma_unmap_single(NULL, dma_addr_oobbuf, oob_size,  DMA_FROM_DEVICE);
		outer_flush_range(dma_addr_oobbuf, (dma_addr_oobbuf + oob_size));			
	}else{
		dma_unmap_single(NULL, dma_addr_oobbuf, oob_size,  DMA_FROM_DEVICE);
		outer_flush_range(dma_addr_oobbuf, (dma_addr_oobbuf + oob_size));	
	}

	if((is_NF_CP_Enable_read&&(!mtd->isCPdisable_R))||g_isRandomize)//Clear register
	{
		REG_WRITE_U32(REG_CP_NF_SET,0);
	}

	if(oob_buf)
	{
		if(this->ecc_select==0x18||this->ecc_select==0x0c||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
		{
			if(mtd->ecctype!=MTD_ECC_RTK_HW)
				reverse_to_Tags(oob_buf,this->ecc_select);
			else
			{
				REG_WRITE_U32(REG_READ_BY_PP,0x00);

				if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_sirius_cpu())
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x02);
				else
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x04);

				rtk_read_oob_from_SRAM(mtd, oob_buf);
				REG_WRITE_U32(REG_SRAM_CTL, 0x00);
				REG_WRITE_U32(REG_READ_BY_PP,0x80);
			}
		}
		else
		{
			if( ! is_jupiter_cpu() )
			{
				REG_WRITE_U32(REG_READ_BY_PP,0x00);

				if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_sirius_cpu())
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x02);
				else
					REG_WRITE_U32(REG_SRAM_CTL, 0x30 | 0x04);

				rtk_read_oob_from_SRAM(mtd, oob_buf);
				REG_WRITE_U32(REG_SRAM_CTL, 0x00);
				REG_WRITE_U32(REG_READ_BY_PP,0x80);
			}
			if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
				reverse_to_Tags(oob_buf,this->ecc_select);

		}

	}

	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	index = page & (32-1);
	blank_all_one = (REG_READ_U32(REG_BLANK_CHK)>>1) & 0x01;

	// add by alexchang 01-28-2011
	mtd->nEccMaxValue = REG_MAX_ECC_NUM_max_ecc_num(REG_READ_U32(REG_MAX_ECC_NUM));
	if (blank_all_one)
	{
		if(this->erase_page_flag)
			this->erase_page_flag[chip_section+section] =  (1<< index);
		else{
			up (&sem_NF_CARDREADER);
			padunlock(PAD_NAND);   // unlock nand・s pad
			return 0;	// return OK if all data bit is 1 (page is not written yet)
		}
	}

	if (REG_READ_U32(REG_ND_ECC) & 0x0C){
		if(!this->erase_page_flag)
		{
			if (REG_READ_U32(REG_ND_ECC) & 0x08){
				if ( chipnr == 0 && page < g_BootcodeSize/page_size )
				{
					up (&sem_NF_CARDREADER);
					padunlock(PAD_NAND);   // unlock nand・s pad
					return 0;
				}
				else
				{
					up (&sem_NF_CARDREADER);
					padunlock(PAD_NAND);   // unlock nand・s pad
					printk("[%s][%d]blk %d, page %d \n",__FUNCTION__,__LINE__,page/ppb,page%ppb);
					return -1;
				}
			}
		}
		else
		{
			if (this->erase_page_flag[chip_section+section] & (1<< index) ){
				up (&sem_NF_CARDREADER);
				padunlock(PAD_NAND);   // unlock nand・s pad
				return 0;	// return OK if all data bit is 1 (page is not written yet)
			}else
			{
				if (REG_READ_U32(REG_ND_ECC) & 0x08){
					if ( chipnr == 0 && page < g_BootcodeSize/page_size )
					{
						up (&sem_NF_CARDREADER);
						padunlock(PAD_NAND);   // unlock nand・s pad
						return 0;
					}
					else
					{
						up (&sem_NF_CARDREADER);
						padunlock(PAD_NAND);   // unlock nand・s pad
						printk("[%s][%d]blk %d, page %d \n",__FUNCTION__,__LINE__,page/ppb,page%ppb);
						return -1;
					}
				}
			}
		}
		if(REG_READ_U32(REG_ND_ECC) & 0x04){
			if((REG_READ_U32(REG_MAX_ECC_NUM) & 0x3F) > this->ecc_safe_value){
				printk("[%s][%d]blk %d, page %d ecc error warning,ecc_num = 0x%x\n",__FUNCTION__,__LINE__,page/ppb,page%ppb,REG_READ_U32(REG_RSECC_NUM));
				this->ecc_err_flag = 1;
			}
		}
	}

#if RTK_ARD_ALGORITHM
	g_WinTrigCnt++;
//	printk("mtd->erasesize %u  mtd->oobblock %u\n",mtd->erasesize,mtd->oobblock);
//	printk("ppb %u \n",ppb);
	whichBlk = page / ppb;
	g_RecArray[whichBlk]++;
	if(g_WinTrigCnt > g_WinTrigThrshld)
		travelProcWindow();
#endif

	mtd->isCPdisable_R = 0;
	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad
	//printk("R blk:%u, page:%u\n",page/ppb,page%ppb);
#ifdef MTD_NAND_RTK_NAND_TEST
	if(test_read_warning_remap != 0){
		printk("%s: enter test_read_warning_remap page %d block %d test mode!!\n", __FUNCTION__, page,page/this->ppb);
		this->ecc_err_flag = 1;
		test_read_warning_remap = 0;
	}
#endif
	return rc;
}
//----------------------------------------------------------------------------
static int rtk_write_oob(struct mtd_info *mtd, u16 chipnr, int page, int len, const u_char *oob_buf)
{
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int rc = 0;
	uint8_t	auto_trigger_mode = 1;
	uint8_t	addr_mode = 1;
	unsigned int page_len, dram_sa, dma_len, spare_dram_sa;
	unsigned char oob_1stB;
	unsigned int chip_section = 0;
	unsigned int section =0;
	unsigned int index =0;
	unsigned int retryCnt = RETRY_COUNT;
	if (this->erase_page_flag)
		this->erase_page_flag[chip_section+section] &= ~(1 << index);
	memset(this->g_databuf, 0xff, page_size);

	page_size = mtd->oobblock;
	oob_size = mtd->oobsize;
	ppb = mtd->erasesize/mtd->oobblock;
	padlock(PAD_NAND);   // lock nand・s pad

	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,page);
			if(retryCnt<=0)
			{
				printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,page);
				padunlock(PAD_NAND);   // unlock nand・s pad
				return -ERESTARTSYS;
			}
			retryCnt--;
	}
#if 0 //def MTD_NAND_RTK_NAND_TEST
	if ( chipnr == 0 && page >= 0 && page < (g_BootcodeSize+g_Secure_store_Size)/page_size ){
		printk("[%s] You have no permission to write this page %d\n", __FUNCTION__, page);
		up (&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -2;
	}
#endif

	if ( len>oob_size || !oob_buf ){
		printk("[%s] error: len>oob_size OR oob_buf is NULL\n", __FUNCTION__);
		up (&sem_NF_CARDREADER);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -1;
	}

	//----------------set random mode --------------------
	if (nf_is_random_mode()){
		nf_set_random_write(mtd->oobblock,0);
	}

	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_dis);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_dis);//Set Value
				break;
			}
            REG_WRITE_U32( REG_CMD3,NF_CMD3_cmd3(CMD_BLK_ERASE_C3));
            REG_WRITE_U32( REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(0x07)|NF_POLL_FSTS_trig_poll(1));
            WAIT_DONE(REG_POLL_FSTS,0x1,0);
		}
	}
	
	dma_map_single(NULL,this->g_databuf, page_size, DMA_TO_DEVICE);
	if ( oob_buf ) 
		dma_map_single(NULL,oob_buf, oob_size, DMA_TO_DEVICE);

	if ( page == ppb || page == ppb+1|| page == ppb*2 || page == ppb*2+1 )
		oob_1stB = BBT_TAG;
	else if(( page>=(g_BootcodeSize+g_Secure_store_Size)/page_size )&&(page<(g_BootcodeSize+g_Secure_store_Size+g_Factory_param_size+g_Factory_RO_Size)/page_size))
		oob_1stB = TAG_FACTORY_PARAM;
	else
		oob_1stB = 0xFF;
//end of alexchang 0208-2010
	//REG_WRITE_U32(0x01,0xb801032c);	//Enable NAND/CardReader arbitrator add by alexchang 0303-2010
	REG_WRITE_U32(REG_SRAM_CTL,0x00);//add by alexchang 0208-2010
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0));
 	if((this->ecc_select == 0x18)||((this->ecc_select == 0x28)))
	{
		page_len = page_size >> 10;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_length1(4));
	}
	else
	{
		page_len = page_size >> 9;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_length1(2));
	}

	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL0,0);//add by alexchang 0208-2010

	REG_WRITE_U32( REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));
	
 	if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
 		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
	else if( this->ecc_select == 0x18) //setting for 24bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	
 	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_WRITE_C1));
	REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_WRITE_C2));
	REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_WRITE_C3));

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page));
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8));
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16));
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7));
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));

	dma_len = page_size >> 9;
	REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

	dram_sa = (((unsigned int)virt_to_phys(this->g_databuf)) >> 3);
	REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));

	spare_dram_sa = (((unsigned int)virt_to_phys(oob_buf)) >> 3);

	if(is_jupiter_cpu())
		REG_WRITE_U32( REG_SPR_DDR_CTL,(0x7<<26) | (spare_dram_sa&0x3ffffff));
	else
		REG_WRITE_U32( REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));
#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_AUTO_IRQ_MASK);
	g_nfFlag = NF_WRITE_TRIGGER;
#endif
	if(g_isRandomize&&(!mtd->isCPdisable_W))
	{
		if(mtd->isScramble!=MTD_SCRAMBLE_DISABLE)
		{
			//printk("&");
			if(u32CP_mode==0)//CBC initial key setting.
			{
				REG_WRITE_U32( REG_CP_NF_INI_KEY,page);
			}
			REG_WRITE_U32(REG_CP_NF_KEY,0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),0x12345678);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
			//add by alexchang 0208-2010
			
			dma_map_single(NULL,this->g_databuf, page_size, DMA_TO_DEVICE);
			if ( oob_buf )
			dma_map_single(NULL, oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{
			//printk("%");
			dma_map_single(NULL,this->g_databuf, page_size, DMA_TO_DEVICE);
			if ( oob_buf )
			dma_map_single(NULL,oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
	}
	else
	{
		if(is_NF_CP_Enable_write&&(!mtd->isCPdisable_W))
		{//printk("#");
			REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
			//add by alexchang 0208-2010
			dma_map_single(NULL,this->g_databuf, page_size, DMA_TO_DEVICE);
			if ( oob_buf )
				dma_map_single(NULL,oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{//printk("@");
			//add by alexchang 0208-2010

			dma_map_single(NULL,this->g_databuf, page_size, DMA_TO_DEVICE);
			if ( oob_buf )
				dma_map_single(NULL,oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
	}
	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(auto_trigger_mode));

#if RTK_NAND_INTERRUPT
	RTK_WAIT_EVENT;
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_POLL_IRQ_MASK);
	g_nfFlag = NF_WRITE_TRIGGER;
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	RTK_WAIT_EVENT;
#else
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	WAIT_DONE(REG_POLL_FSTS,0x01,0x0);
	WAIT_DONE(REG_ND_CTL,0x40,0x40);//add by alexchang 0416-2010
#endif

	dma_unmap_single(NULL, virt_to_phys(this->g_databuf), page_size, DMA_TO_DEVICE);
	if ( oob_buf )
		dma_unmap_single(NULL, virt_to_phys(oob_buf), oob_size, DMA_TO_DEVICE);

	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_en);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_en);//Set Value
				break;
			}
		}
	}

	if((is_NF_CP_Enable_write&&(!mtd->isCPdisable_W))||g_isRandomize)//Clear register
	{
		REG_WRITE_U32(REG_CP_NF_SET,0);
	}

	if ( REG_READ_U32(REG_ND_DAT) & 0x01 ){
		up (&sem_NF_CARDREADER);
		printk("[%s] write oob is not completed at page %d\n", __FUNCTION__, page);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -1;
	}

	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	index = page & (32-1);
	if (this->erase_page_flag)
		this->erase_page_flag[chip_section+section] &= ~(1 << index);
	mtd->isCPdisable_W = 0;
	//printk("[AT]WO block : %u ,page : %d  \n",page/ppb,page%ppb);
	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad

	return rc;
}

//----------------------------------------------------------------------------

//char bbbbb[4096];

static int rtk_write_ecc_page (struct mtd_info *mtd, u16 chipnr, unsigned int page,
			const u_char *data_buf, const  u_char *oob_buf, int isBBT)
{
	unsigned int ppb = mtd->erasesize/mtd->oobblock;
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int rc = 0;
	uint8_t	auto_trigger_mode = 1;
	uint8_t	addr_mode = 1;
	unsigned int i=0;

	unsigned int page_len, dram_sa, dma_len, spare_dram_sa;
	unsigned char oob_1stB;

	unsigned char nf_oob_buf[oob_size];
	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int index = 0;
	unsigned int retryCnt = RETRY_COUNT;
	padlock(PAD_NAND);   // lock nand・s pad
#ifdef MTD_NAND_RTK_NAND_TEST
	if(test_write_fail_remap != 0){
		printk("%s: page %d block %d enter write remap test mode!!\n", __FUNCTION__, page,page/this->ppb);
		test_write_fail_remap = 0;
		return -1;
	}
#endif

	//printk("00[%s]Ran 0x%x, scr 0x%x, flag 0x%x\n",__FUNCTION__,g_isRandomize,mtd->isScramble,mtd->isCPdisable_W);
	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,page);
			if(retryCnt<=0)
			{
				printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,page);
				padunlock(PAD_NAND);   // unlock nand・s pad
				return -ERESTARTSYS;
			}
			retryCnt--;
	}
        if(((uint32_t)data_buf&0x7)!=0)
        {
                printk("[%s]data_buf must 8 byte alignmemt!!\n",__FUNCTION__);
                BUG();
        }
        if(((uint32_t)oob_buf&0x7)!=0)
        {
                printk("[%s]oob_buf must 8 byte alignmemt!!\n",__FUNCTION__);
                BUG();
        }
		
	dma_map_single(NULL,data_buf, page_size, DMA_TO_DEVICE);

	if ( chipnr == 0 && page < g_BootcodeSize/page_size ){
		if ( page<3*ppb ){
			printk("[%s] Updating BBT %d page=%d\n", __FUNCTION__, page/ppb, page%ppb);
		}
		else
		{
			printk("[%s] You have no permission to write page %d\n", __FUNCTION__, page);
			up (&sem_NF_CARDREADER);
			padunlock(PAD_NAND);   // unlock nand・s pad
			return -2;
		}
		mtd->isCPdisable_W = 1;
	}
	if ( chipnr == 0 && page >= g_BootcodeSize/page_size){
		if(page<(g_CP_Disable_area/page_size))
		{
			  mtd->isCPdisable_W = 1;
		}
	}

	//----------------set random mode --------------------
	if (nf_is_random_mode()){
		nf_set_random_write(mtd->oobblock,0);
	}

	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_dis);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_dis);//Set Value
				break;
			}
			REG_WRITE_U32( REG_CMD3,NF_CMD3_cmd3(CMD_BLK_ERASE_C3));
			REG_WRITE_U32( REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(0x07)|NF_POLL_FSTS_trig_poll(1));
			WAIT_DONE(REG_POLL_FSTS,0x1,0);
		}
	}

	if ( page == ppb || page == ppb+1|| page == ppb*2 || page == ppb*2+1 )
		oob_1stB = BBT_TAG;
	else if(( page>=(g_BootcodeSize+g_Secure_store_Size)/page_size )&&(page<(g_BootcodeSize+g_Secure_store_Size+g_Factory_param_size+g_Factory_RO_Size)/page_size))
		oob_1stB = TAG_FACTORY_PARAM;
	else
		oob_1stB = 0xFF;

	//REG_WRITE_U32(0xb801032c,0x01);	//Enable NAND/CardReader arbitrator add by alexchang 0303-2010

	if ( oob_buf )	{
		int i,j;
		//memset(nf_oob_buf,0xff,oob_size);
		nf_oob_buf[0] = oob_1stB;

		if((this->ecc_select == 0x18)||(this->ecc_select == 0x28))
		{
			for(i=1,j=0; i<8; i++)
			{
				nf_oob_buf[8*i] = oob_buf[j];
				nf_oob_buf[8*i+1] = oob_buf[j+1];
				nf_oob_buf[8*i+2] = oob_buf[j+2];
				nf_oob_buf[8*i+3] = oob_buf[j+3];
				j+=4;
			}
		}
		else
		{
			for(i=0; i<4; i++)
				nf_oob_buf[1+i] = oob_buf[i];
			if( is_jupiter_cpu() )
			{
				for(i=1,j=4; i<4; i++)
				{
					nf_oob_buf[8*i] = oob_buf[j];
					nf_oob_buf[8*i+1] = oob_buf[j+1];
					nf_oob_buf[8*i+2] = oob_buf[j+2];
					nf_oob_buf[8*i+3] = oob_buf[j+3];
					j+=4;
				}
			}
			else
			{
				for(i=2,j=4; i<8; i+=2)
				{
					nf_oob_buf[4*i] = oob_buf[j];
					nf_oob_buf[4*i+1] = oob_buf[j+1];
					nf_oob_buf[4*i+2] = oob_buf[j+2];
					nf_oob_buf[4*i+3] = oob_buf[j+3];
					j+=4;
				}
			}
		}
	}else
		nf_oob_buf[0] = oob_1stB;

	dma_map_single(NULL,nf_oob_buf, oob_size, DMA_TO_DEVICE);

	REG_WRITE_U32(REG_SRAM_CTL,0x00);//add by alexchang 0208-2010
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0));
 	if((this->ecc_select == 0x18)||(this->ecc_select == 0x28))
	{
		page_len = page_size >> 10;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_length1(4));
	}
	else
	{
		page_len = page_size >> 9;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_length1(2));
	}

	REG_WRITE_U32( REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));
	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL0,0);//add by alexchang 0208-2010

 	if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
 		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
	else if( this->ecc_select == 0x18) //setting for 24bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	
 	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_WRITE_C1));
	REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_WRITE_C2));
	REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_WRITE_C3));

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page));
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8));
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16));
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7));
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));
	REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));

	dma_len = page_size >> 9;
	REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

	dram_sa = (((unsigned int)virt_to_phys(data_buf)) >> 3);
	REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));

	if (oob_buf){
		spare_dram_sa = (((unsigned int)virt_to_phys(nf_oob_buf)) >> 3);
	}else{
		spare_dram_sa = (((unsigned int)virt_to_phys(this->g_oobbuf)) >> 3);
	}
	if(is_jupiter_cpu())
		REG_WRITE_U32(REG_SPR_DDR_CTL, (0x7<<26) | (spare_dram_sa&0x3ffffff));
	else
		REG_WRITE_U32(REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));

#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_AUTO_IRQ_MASK);
	g_nfFlag = NF_WRITE_TRIGGER;
#endif
	//printk("11[%s]Ran 0x%x, scr 0x%x, flag 0x%x\n",__FUNCTION__,g_isRandomize,mtd->isScramble,mtd->isCPdisable_W);

	if(g_isRandomize&&(!mtd->isCPdisable_W))
	{
//		if(mtd->isScramble!=MTD_SCRAMBLE_DISABLE)
//		{
			//printk("$");
			if(u32CP_mode==0)//CBC initial key setting.
			{
					REG_WRITE_U32( REG_CP_NF_INI_KEY,page);
			}
			REG_WRITE_U32(REG_CP_NF_KEY,0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),0x12345678);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));

			dma_map_single(NULL, data_buf, page_size, DMA_TO_DEVICE);
			dma_map_single(NULL, nf_oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
//		}
//		else
//		{//printk("=");
//			dma_map_single(NULL, data_buf, page_size, DMA_TO_DEVICE);
//			dma_map_single(NULL, nf_oob_buf, oob_size, DMA_TO_DEVICE);
//			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
//		}
	}
	else
	{
		if(is_NF_CP_Enable_write&&(!mtd->isCPdisable_W))
		{//printk("+");
			REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
			
			dma_map_single(NULL,data_buf, page_size, DMA_TO_DEVICE);
			dma_map_single(NULL,nf_oob_buf, oob_size, DMA_TO_DEVICE);
		
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{//printk("-");

			dma_map_single(NULL, data_buf, page_size, DMA_TO_DEVICE);
			dma_map_single(NULL, nf_oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
	}
	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(auto_trigger_mode));


#if RTK_NAND_INTERRUPT
	RTK_WAIT_EVENT;
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_POLL_IRQ_MASK);
	g_nfFlag = NF_WRITE_TRIGGER;
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	RTK_WAIT_EVENT;
#else
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	WAIT_DONE(REG_POLL_FSTS,0x01,0x0);
	WAIT_DONE(REG_ND_CTL,0x40,0x40);//add by alexchang 0416-2010
#endif

	dma_unmap_single(NULL, virt_to_phys(data_buf), page_size, DMA_TO_DEVICE);
	dma_unmap_single(NULL, virt_to_phys(nf_oob_buf), oob_size, DMA_TO_DEVICE);

	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_en);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_en);//Set Value
				break;
			}
		}
	}

	if((is_NF_CP_Enable_write&&(!mtd->isCPdisable_W))||g_isRandomize)//Clear register
	{
		REG_WRITE_U32(REG_CP_NF_SET,0);
	}

	if ( REG_READ_U32(REG_ND_DAT) & 0x01 ){
		up (&sem_NF_CARDREADER);
		printk("[%s] write is not completed at page %d\n", __FUNCTION__, page);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -1;
	}

	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	index = page & (32-1);

	if (this->erase_page_flag)
		this->erase_page_flag[chip_section+section] &= ~(1 << index);
	mtd->isCPdisable_W = 0;
	//printk("[AT]W block : %u , page: %u \n",page/ppb,page%ppb);
	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad
#if 0
	char *ppptr = (unsigned long)bbbbb-(unsigned long)bbbbb%8+8;
	rtk_read_ecc_page (mtd, chipnr, page, ppptr, oob_buf);
	if(memcmp(ppptr,data_buf, 2048))
		{
			int i, count=0;
			for(i=0;i<2048;i++)
		 		if(ppptr[i] != data_buf[i])
				 count++;
				printk("Data compare error! %d %x %x %x %p\n", count, ppptr[0],
				ppptr[1], ppptr[2], ppptr); //BUG();
				}
	else
		printk("write check OK!\n");
#endif

	return rc;
}

//-------------------------------------------------------------------------
//for write bootcode area
static int rtk_write_bootcode_area (struct mtd_info *mtd, u16 chipnr, unsigned int page,
			const u_char *data_buf, const  u_char *oob_buf, unsigned int spare_value)
{
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int rc = 0;
	uint8_t	auto_trigger_mode = 1;
	uint8_t	addr_mode = 1;
	unsigned int page_len, dram_sa, dma_len, spare_dram_sa;
	unsigned char nf_oob_buf[oob_size];
	unsigned int chip_section = 0;
	unsigned int section = 0;
	unsigned int index = 0;
	unsigned int retryCnt = RETRY_COUNT;
	unsigned char temp;
	unsigned char increment = 8;    // 6B for software (8B spacing)
	unsigned char count = 0, i=0;
	padlock(PAD_NAND);   // lock nand・s pad

	//printk("00[%s]Ran 0x%x, scr 0x%x, flag 0x%x\n",__FUNCTION__,g_isRandomize,mtd->isScramble,mtd->isCPdisable_W);
	while (down_interruptible (&sem_NF_CARDREADER)) {
		printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,page);
			if(retryCnt<=0)
			{
				printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,page);
				padunlock(PAD_NAND);   // unlock nand・s pad
				return -ERESTARTSYS;
			}
			retryCnt--;
	}
        if(((uint32_t)data_buf&0x7)!=0)
        {
                printk("[%s]data_buf must 8 byte alignmemt!!\n",__FUNCTION__);
                BUG();
        }
        if(((uint32_t)oob_buf&0x7)!=0)
        {
                printk("[%s]oob_buf must 8 byte alignmemt!!\n",__FUNCTION__);
                BUG();
        }

	if ( chipnr == 0 && page<(g_CP_Disable_area/page_size)){
		mtd->isCPdisable_W = 1;
	}
	
	dma_map_single(NULL,data_buf, page_size, DMA_TO_DEVICE);

	//----------------set random mode --------------------
	if (nf_is_random_mode()){
		nf_set_random_write(mtd->oobblock,0);
	}

	if(g_edo_mode_enable)
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(1));
	else
		REG_WRITE_U32(REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0));
	
	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_dis);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_dis);//Set Value
				break;
			}
            REG_WRITE_U32( REG_CMD3,NF_CMD3_cmd3(CMD_BLK_ERASE_C3));
            REG_WRITE_U32( REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(0x07)|NF_POLL_FSTS_trig_poll(1));
            WAIT_DONE(REG_POLL_FSTS,0x1,0);
		}
	}

	if((this->ecc_select == 0x18)||(this->ecc_select == 0x28)){
		increment = 8;		// 4B for software
		count =  page_size >> 10;
	}else{
		increment = 8;		// 6B for software (8B spacing)
		count =  page_size >> 9;
	}
	
	//init nf_oob_buf
	memset(nf_oob_buf, 0xff, oob_size);
	temp = (unsigned char)((spare_value>>0)&0xff);
	if(temp == 0xff){
		//for kcpu secure store case
		//do nothing

	}else{
		for(i=0; i<count; i++){
			nf_oob_buf[0 + i*increment] = (unsigned char)((spare_value>>0)&0xff);
			nf_oob_buf[1 + i*increment] = (unsigned char)((spare_value>>8)&0xff);
			nf_oob_buf[2 + i*increment] = (unsigned char)((spare_value>>16)&0xff);
			nf_oob_buf[3 + i*increment] = (unsigned char)((spare_value>>24)&0xff);
		}
	}

	dma_map_single(NULL,nf_oob_buf, oob_size, DMA_TO_DEVICE);

	REG_WRITE_U32(REG_SRAM_CTL,0x00);//add by alexchang 0208-2010
	
	REG_WRITE_U32(REG_DATA_TL0,NF_DATA_TL0_length0(0));
 	if((this->ecc_select == 0x18)||(this->ecc_select == 0x28))
	{
		page_len = page_size >> 10;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_length1(4));
	}
	else
	{
		page_len = page_size >> 9;
		REG_WRITE_U32(REG_DATA_TL1,NF_DATA_TL1_length1(2));
	}

	REG_WRITE_U32( REG_PAGE_LEN,NF_PAGE_LEN_page_len(page_len));
	REG_WRITE_U32(REG_READ_BY_PP,NF_READ_BY_PP_read_by_pp(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL1,NF_PP_CTL1_pp_start_addr(0));//add by alexchang 0208-2010
	REG_WRITE_U32(REG_PP_CTL0,0);//add by alexchang 0208-2010

 	if ( this->ecc_select == 0xc)	//setting for 12bits ecc.
 		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(1));
	else if( this->ecc_select == 0x18) //setting for 24bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(1)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else if(this->ecc_select == 0x28)	//setting for 40bits ecc.
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(1)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	else
		REG_WRITE_U32(REG_ECC_SEL,NF_ECC_SEL_ecc_bch_40b_ena(0)|NF_ECC_SEL_ecc_bch_24b_ena(0)|NF_ECC_SEL_ecc_bch_12b_ena(0));
	
 	REG_WRITE_U32(REG_ND_CMD,NF_ND_CMD_cmd(CMD_PG_WRITE_C1));
	REG_WRITE_U32(REG_CMD2,NF_CMD2_cmd2(CMD_PG_WRITE_C2));
	REG_WRITE_U32(REG_CMD3,NF_CMD3_cmd3(CMD_PG_WRITE_C3));

	REG_WRITE_U32( REG_ND_PA0,NF_ND_PA0_page_addr0(page));
	REG_WRITE_U32( REG_ND_PA1,NF_ND_PA1_page_addr1(page>>8));
	REG_WRITE_U32( REG_ND_PA2,NF_ND_PA2_addr_mode(addr_mode)|NF_ND_PA2_page_addr2(page>>16));
	REG_WRITE_U32( REG_ND_PA3,NF_ND_PA3_page_addr3((page>>21)&0x7));
	REG_WRITE_U32(REG_ND_CA0,NF_ND_CA0_col_addr0(0));
	REG_WRITE_U32(REG_ND_CA1,NF_ND_CA1_col_addr1(0));
	REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));

	dma_len = page_size >> 9;
	REG_WRITE_U32(REG_DMA_CTL2,NF_DMA_CTL2_dma_len(dma_len));

	dram_sa = (((unsigned int)virt_to_phys(data_buf)) >> 3);
	REG_WRITE_U32(REG_DMA_CTL1,NF_DMA_CTL1_dram_sa(dram_sa));
	
	spare_dram_sa = (((unsigned int)virt_to_phys(nf_oob_buf)) >> 3);
	
	if(is_jupiter_cpu())
		REG_WRITE_U32(REG_SPR_DDR_CTL, (0x7<<26) | (spare_dram_sa&0x3ffffff));
	else
		REG_WRITE_U32(REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1)|NF_SPR_DDR_CTL_spare_ddr_ena(1)|NF_SPR_DDR_CTL_per_2k_spr_ena(1)|NF_SPR_DDR_CTL_spare_dram_sa(spare_dram_sa));
	

#if RTK_NAND_INTERRUPT
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_AUTO_IRQ_MASK);
	g_nfFlag = NF_WRITE_TRIGGER;
#endif
	//printk("11[%s]Ran 0x%x, scr 0x%x, flag 0x%x\n",__FUNCTION__,g_isRandomize,mtd->isScramble,mtd->isCPdisable_W);

	if(g_isRandomize&&(!mtd->isCPdisable_W))
	{
//		if(mtd->isScramble!=MTD_SCRAMBLE_DISABLE)
//		{
			//printk("$");
			if(u32CP_mode==0)//CBC initial key setting.
			{
					REG_WRITE_U32( REG_CP_NF_INI_KEY,page);
			}
			REG_WRITE_U32(REG_CP_NF_KEY,0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),0x12345678);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),0x12345678);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));
			
			dma_map_single(NULL, data_buf, page_size, DMA_TO_DEVICE);
			dma_map_single(NULL, nf_oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
//		}
//		else
//		{//printk("=");
//			dma_map_single(NULL, data_buf, page_size, DMA_TO_DEVICE);
//			dma_map_single(NULL, nf_oob_buf, oob_size, DMA_TO_DEVICE);
//			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
//		}
	}
	else
	{
		if(is_NF_CP_Enable_write&&(!mtd->isCPdisable_W))
		{//printk("+");
			REG_WRITE_U32(REG_CP_NF_KEY,*regKey0);
			REG_WRITE_U32((REG_CP_NF_KEY+0x4),*regKey1);
			REG_WRITE_U32((REG_CP_NF_KEY+0x8),*regKey2);
			REG_WRITE_U32((REG_CP_NF_KEY+0xc),*regKey3);

			REG_WRITE_U32(REG_CP_NF_SET,u32CP_mode|cpSel);
			REG_WRITE_U32(REG_CP_LEN,NF_CP_LEN_cp_length(page_size));

			dma_map_single(NULL,data_buf, page_size, DMA_TO_DEVICE);
			dma_map_single(NULL,nf_oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0x1)|NF_DMA_CTL3_cp_first(0x1)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
		else
		{//printk("-");

			dma_map_single(NULL, data_buf, page_size, DMA_TO_DEVICE);
			dma_map_single(NULL, nf_oob_buf, oob_size, DMA_TO_DEVICE);
			
			REG_WRITE_U32(REG_DMA_CTL3,NF_DMA_CTL3_cp_enable(0)|NF_DMA_CTL3_cp_first(0)|NF_DMA_CTL3_ddr_wr(0)|NF_DMA_CTL3_dma_xfer(0x1));
		}
	}
	REG_WRITE_U32( REG_AUTO_TRIG,NF_AUTO_TRIG_auto_trig(1)|NF_AUTO_TRIG_spec_auto_case(0)| NF_AUTO_TRIG_auto_case(auto_trigger_mode));


#if RTK_NAND_INTERRUPT
	RTK_WAIT_EVENT;
	NF_RESET_IRQ;
	NF_ENABLE_IRQ(NF_POLL_IRQ_MASK);
	g_nfFlag = NF_WRITE_TRIGGER;
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	RTK_WAIT_EVENT;
#else
	WAIT_DONE(REG_AUTO_TRIG,0x80,0);
	WAIT_DONE(REG_DMA_CTL3,0x01,0);
	REG_WRITE_U32(REG_POLL_FSTS,NF_POLL_FSTS_bit_sel(6)|NF_POLL_FSTS_trig_poll(1) );
	WAIT_DONE(REG_POLL_FSTS,0x01,0x0);
	WAIT_DONE(REG_ND_CTL,0x40,0x40);//add by alexchang 0416-2010
#endif

	dma_unmap_single(NULL, virt_to_phys(data_buf), page_size, DMA_TO_DEVICE);
	dma_unmap_single(NULL, virt_to_phys(nf_oob_buf), oob_size, DMA_TO_DEVICE);

	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())//Enable NF_WP pin (Write Protect Pin)
	{
		if(g_WP_en)
		{
			switch(g_NFWP_pinType)
			{
				case PCB_PIN_TYPE_AUDIO:
					setAudioIOBit(g_NFWP_no, g_NFWP_value_en);
				break;
				case PCB_PIN_TYPE_GPIO:
				default:
					setGPIOBit(g_regGPIODirBase,g_NFWP_no,NF_GPIO_OUT);//Set Driection
					setGPIOBit(g_regGPIOOutBase,g_NFWP_no,g_NFWP_value_en);//Set Value
				break;
			}
		}
	}

	if((is_NF_CP_Enable_write&&(!mtd->isCPdisable_W))||g_isRandomize)//Clear register
	{
		REG_WRITE_U32(REG_CP_NF_SET,0);
	}


	if ( REG_READ_U32(REG_ND_DAT) & 0x01 ){
		up (&sem_NF_CARDREADER);
		printk("[%s] write is not completed at page %d\n", __FUNCTION__, page);
		padunlock(PAD_NAND);   // unlock nand・s pad
		return -1;
	}
			
	chip_section = (chipnr * this->page_num) >> 5;
	section = page >> 5;
	index = page & (32-1);

	if (this->erase_page_flag)
		this->erase_page_flag[chip_section+section] &= ~(1 << index);
	mtd->isCPdisable_W = 0;
	//printk("[AT]W block : %u , page: %u \n",page/ppb,page%ppb);
	up (&sem_NF_CARDREADER);
	padunlock(PAD_NAND);   // unlock nand・s pad

	return rc;
}

//----------------------------------------------------------------------------
static int rtk_nand_profile (void)
{
	int maxchips = 4;
	char *ptype;
	int pnum = 0;
	struct mtd_partition *mtd_parts;
	struct nand_chip *this = (struct nand_chip *)rtk_mtd->priv;
	int retRba=0;


#if 0
#ifdef CONFIG_MTD_NAND_RTK_RBA_PERCENT
	this->RBA_PERCENT = CONFIG_MTD_NAND_RTK_RBA_PERCENT;
	printk("[Customize]RBA percentage: %d%\n",this->RBA_PERCENT);

#else
	this->RBA_PERCENT = RBA_PERCENT;
	printk("[Default]RBA percentage: %d'%'\n",this->RBA_PERCENT);
#endif
#else
	retRba = rtkNF_getRBAPercent();
	if(retRba == -1)
	{
		rtk_mtd->u32RBApercentage = this->RBA_PERCENT = RBA_PERCENT;
		NF_MSG_INFO("[**Default**]RBA percentage: %d%%\n",this->RBA_PERCENT);
	}
	else
	{
		rtk_mtd->u32RBApercentage = this->RBA_PERCENT = retRba;
		NF_MSG_INFO("[**Customize**]RBA percentage: %d%%\n",this->RBA_PERCENT);
	}
#endif

	g_sw_WP_level = rtkNF_getSW_WP_level();
	if(g_sw_WP_level == -1)
		NF_MSG_INFO("Disable software write protect!\n");
	else
		NF_MSG_INFO("Enable software write protect!\n");

	if (rtk_nand_scan (rtk_mtd, maxchips) < 0 || rtk_mtd->size == 0){
		NF_MSG_ERR("%s: Error, cannot do nand_scan(on-board)\n", __FUNCTION__);
		return -ENODEV;
	}
	if ( !(rtk_mtd->oobblock&(0x200-1)) )
		REG_WRITE_U32( REG_PAGE_LEN,rtk_mtd->oobblock >> 9);
	else{
		NF_MSG_ERR("Error: pagesize is not 512B Multiple");
		return -1;
	}

#ifdef CONFIG_MTD_CMDLINE_PARTS
	ptype = (char *)ptypes[0];
	pnum = parse_mtd_partitions (rtk_mtd, ptypes, &mtd_parts, 0);
#endif
	if (pnum <= 0) {
		NF_MSG_INFO("RTK: using the whole nand as a partitoin\n");
		if(add_mtd_device(rtk_mtd)) {
			NF_MSG_ERR("RTK: Failed to register new nand device\n");
			return -EAGAIN;
		}
	}else{
		NF_MSG_INFO("RTK: using dynamic nand partition\n");
		if (add_mtd_partitions (rtk_mtd, mtd_parts, pnum)) {
			NF_MSG_ERR("%s: Error, cannot add %s device\n",
					__FUNCTION__, rtk_mtd->name);
			rtk_mtd->size = 0;
			return -EAGAIN;
		}
	}
	return 0;
}

/*********************proc fs relative function************************/
int rtk_nand_proc_read(char *buf, void *private_ptr)
{
	struct nand_chip *this = (struct nand_chip *) rtk_mtd->priv;
	int wlen = 0;
	
//	wlen += sprintf(buf+wlen, "Nand-Driver built:" __DATE__ " " __TIME__ "\n\n");
	
	wlen += sprintf(buf+wlen,"nand_name:%s\n", rtk_mtd->PartNum);
	wlen += sprintf(buf+wlen,"nand_size:%llu\n", (uint64_t)this->device_size);
	wlen += sprintf(buf+wlen,"chip_size:%llu\n", (uint64_t)this->chipsize);
	wlen += sprintf(buf+wlen,"block_size:%u\n", rtk_mtd->erasesize);
	wlen += sprintf(buf+wlen,"page_size:%u\n", rtk_mtd->oobblock);
	wlen += sprintf(buf+wlen,"oob_size:%u\n", rtk_mtd->oobsize);
	wlen += sprintf(buf+wlen,"ppb:%u\n", rtk_mtd->erasesize/rtk_mtd->oobblock);
	wlen += sprintf(buf+wlen,"RBA:%u\n", this->RBA);
	wlen += sprintf(buf+wlen,"BBs:%u\n", this->BBs);
	
	return wlen;
}

static int rtk_nand_proc_show(struct seq_file *m, void *v)
{
	char buffer[1024];
	int len;

	len = rtk_nand_proc_read(buffer, NULL);
	seq_puts(m, buffer);
	return 0;
}

static int rtk_nand_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, rtk_nand_proc_show, NULL);
}

static struct file_operations rtk_nand_procfs_ops = {
	.owner = THIS_MODULE,
	.open  = rtk_nand_proc_open,
	.read  = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};

static int rtk_nand_procfs_init(void)
{
	/* Install the proc_fs entries */
	rtk_nand_proc_entry = proc_create("nandinfo",
				    S_IRUGO | S_IFREG,
				    NULL,
				    &rtk_nand_procfs_ops);

	if (rtk_nand_proc_entry) {
		return 0;
	} else {
		return -ENOMEM;
	}
}

/*********************display version************************/
static void display_version (void)
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
	
	NF_MSG_INFO(BANNER " Rev:%s (%s %s)\n", revision, date, time);
//	NF_MSG_INFO("Realtek_NF: build at %s %s\n", __DATE__, __TIME__);
}

//----------------------------------------------------------------------------
#if 0//!RTK_CP_DISABLE
static int rtk_set_CP_KEY(struct CP_key_info *cp_keyInfo)
{
	#if 0
	REG_WRITE_U32(cp_keyInfo->CP_INI_KEY_0,CP_NF_INI_KEY_0_reg);
	REG_WRITE_U32(cp_keyInfo->CP_INI_KEY_1,CP_NF_INI_KEY_1_reg);
	REG_WRITE_U32(cp_keyInfo->CP_INI_KEY_2,CP_NF_INI_KEY_2_reg);
	REG_WRITE_U32(cp_keyInfo->CP_INI_KEY_3,CP_NF_INI_KEY_3_reg);
	REG_WRITE_U32(cp_keyInfo->CP_KEY_0,CP_NF_KEY_0_reg);
	REG_WRITE_U32(cp_keyInfo->CP_KEY_1,CP_NF_KEY_1_reg);
	REG_WRITE_U32(cp_keyInfo->CP_KEY_2,CP_NF_KEY_2_reg);
	REG_WRITE_U32(cp_keyInfo->CP_KEY_3,CP_NF_KEY_3_reg);
	#endif
	return 0;
}
#endif
#if 1
void endian_swap(unsigned int* x)
{
	*x = (*x>>24) |((*x<<8) & 0x00FF0000) |((*x>>8) & 0x0000FF00) |(*x<<24);
}
#endif
//----------------------------------------------------------------------------

#if RTK_NAND_INTERRUPT

static struct platform_driver rtkNF_device = {
    .driver     = {
        .name   = DRIVER_NAME,
        .owner  = THIS_MODULE,
    },
    .remove     = __exit_p(rtk_nand_exit),
    //.suspend    = rtk_nand_suspend,
    //.resume     = rtk_nand_resume,
    .suspend    = NULL,
    .resume     = NULL,
};
static irqreturn_t rtknf_irq(int irq, void *dev)
{
	//printk("++++f:%d,0x%x\n",g_nfFlag,REG_READ_U32(REG_NAND_ISR));
	//Read isr handler
	//printk("&g_irq_waitq 0x%x\n",&g_irq_waitq);
	if(CHECK_IRQ(NF_READ_TRIGGER,REG_NAND_ISR,NF_DMA_ISR,NF_DMA_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_DMA_ISR);
		g_nfFlag=NF_WAKE_UP;
		//wake_up_interruptible(&g_host->irq_waitq);
		wake_up_interruptible(&g_irq_waitq);

		return IRQ_HANDLED;
	}
	else if(CHECK_IRQ(NF_READ_TRIGGER,REG_NAND_ISR,NF_AUTO_TRIG_ISR,NF_AUTO_TRIG_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_AUTO_TRIG_ISR);
		return IRQ_HANDLED;
	}

	//Write isr handler
	if(CHECK_IRQ(NF_WRITE_TRIGGER,REG_NAND_ISR,NF_AUTO_TRIG_ISR,NF_AUTO_TRIG_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_AUTO_TRIG_ISR);
		g_nfFlag=NF_WAKE_UP;
		//wake_up_interruptible(&g_host->irq_waitq);
		wake_up_interruptible(&g_irq_waitq);
		return IRQ_HANDLED;
	}
	if(CHECK_IRQ(NF_WRITE_TRIGGER,REG_NAND_ISR,NF_POLL_STATUS_ISR,NF_POLL_STATUS_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_POLL_STATUS_ISR);
		g_nfFlag=NF_WAKE_UP;
		//wake_up_interruptible(&g_host->irq_waitq);
		wake_up_interruptible(&g_irq_waitq);
		return IRQ_HANDLED;
	}
	else if(CHECK_IRQ(NF_WRITE_TRIGGER,REG_NAND_ISR,NF_DMA_ISR,NF_DMA_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_DMA_ISR);
		return IRQ_HANDLED;
	}

	//Erase isr handler
	if(CHECK_IRQ(NF_ERASE_TRIGGER,REG_NAND_ISR,NF_POLL_STATUS_ISR,NF_POLL_STATUS_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_POLL_STATUS_ISR);
		g_nfFlag=NF_WAKE_UP;
		//wake_up_interruptible(&g_host->irq_waitq);
		wake_up_interruptible(&g_irq_waitq);
		return IRQ_HANDLED;
	}
	else if(CHECK_IRQ(NF_ERASE_TRIGGER,REG_NAND_ISR,NF_AUTO_TRIG_ISR,NF_AUTO_TRIG_ISR))
	{
		CLEAR_IRQ(REG_NAND_ISR,NF_AUTO_TRIG_ISR);
		return IRQ_HANDLED;
	}

	if((REG_READ_U32(REG_NAND_ISR)&NF_IRQ_MASK))
	{
		if((g_nfFlag==NF_ERASE_TRIGGER)||(g_nfFlag==NF_READ_TRIGGER)||(g_nfFlag==NF_READ_TRIGGER)||(g_nfFlag=NF_WAKE_UP))
		{
			//printk("+++++f:%d,0x%x\n",g_nfFlag,REG_READ_U32(REG_NAND_ISR));
			CLR_REG_NAND_ISR;
			return IRQ_HANDLED;
		}
	}
	//printk("xxxxxf:%d,0x%x\n",g_nfFlag,REG_READ_U32(REG_NAND_ISR));
	 return IRQ_NONE;
}

//----------------------------------------------------------------------------
static int __init rtkNF_probe(struct platform_device *pdev)
{
	struct resource *r;
	int nf_irq,ret;
	/* Allocate memory for MTD device structure and private data */
	g_host = kzalloc(sizeof(struct rtk_nand_host), GFP_KERNEL);
	if (!g_host)
		return -ENOMEM;

	r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	//init_waitqueue_head(&g_host->irq_waitq);
	init_waitqueue_head(&g_irq_waitq);

	nf_irq = platform_get_irq(pdev, 0);
	ret = request_irq(nf_irq, rtknf_irq, IRQF_SHARED, DRIVER_NAME, g_host);   //rtkcr_interrupt
	if (ret)
	{
		printk(KERN_ERR "%s: cannot assign irq %d\n", DRIVER_NAME, nf_irq);
		return -1;
	}
	return 0;

}
#endif

//edo-mode enable/disable judge
static void rtk_nand_edo_setting(void)
{
	unsigned int  t2 = 0,t3 = 0;
	unsigned int nd_clk = 0;

	unsigned int sys_clk = 0;
	unsigned int div_num = 0;
	unsigned int  rate = 0;

	struct NF_CLK_INFO nf_clk;

	//set clk info
	nf_clk.nf_clksel = 0;
	nf_clk.clk_is_on = 0;
	nf_clk.clk_set_or_get = NF_CLK_GET;

	t2 = REG_READ_U32(REG_TIME_PARA2) & 0xff;
	t3 = REG_READ_U32(REG_TIME_PARA3) & 0xff;

	sys_clk = 295;	//295MHz
	CRT_CLK_OnOff(NAND, CLK_ON, &nf_clk);
	nd_clk = nf_clk.nf_clksel;
	div_num = nd_clk+3;

	rate =  sys_clk/(div_num*((t2+1) +(t3+1)));

	if(rate >= 33){
		NF_MSG_INFO("Clk = %dMhz, Enable edo mode!\n", rate);
		g_edo_mode_enable = 1;
	}else{
		NF_MSG_INFO("Clk = %dMhz, Disable edo mode!\n", rate);
		g_edo_mode_enable = 0;
	}
		
	return ;
}

//cpsel--->0:register, 1:CW, 2:E-Fuse
//cpmode--->//0 for CBC mode, 0x200 for ECB mode
static int rtk_nand_cp_setting(unsigned int cpsel, unsigned int cpmode, unsigned int keyindex)
{ 
	//sanity check
	if((cpsel >= 3)||(cpmode >=2)){
		NF_MSG_INFO("NFCP parameters setting error!\n");
		goto cp_null;
	}
	
	//when cpsel select CW, must setting keyindex
	if((cpsel == 1) && (keyindex == 0) ){
		NF_MSG_INFO("NFCP parameters setting error!\n");
		goto cp_null;
	}
		
	cpSel = cpsel << 0;
	u32CP_mode = cpmode << 9;
	flash_protection_root_key_index = keyindex << 2;

	//when cpsel select register, get regkey
	if(!cpSel ){
		memcpy(&u8regKey0,&platform_info.AES_IMG_KEY[0],4);
		memcpy(&u8regKey1,&platform_info.AES_IMG_KEY[4],4);
		memcpy(&u8regKey2,&platform_info.AES_IMG_KEY[8],4);
		memcpy(&u8regKey3,&platform_info.AES_IMG_KEY[12],4);
		regKey0 = (unsigned int*)&u8regKey0;
		regKey1 = (unsigned int*)&u8regKey1;
		regKey2 = (unsigned int*)&u8regKey2;
		regKey3 = (unsigned int*)&u8regKey3;
		endian_swap(regKey0);
		endian_swap(regKey1);
		endian_swap(regKey2);
		endian_swap(regKey3);
	}
		
	is_NF_CP_Enable_read = 1;
	is_NF_CP_Enable_write = 1;

	NF_MSG_INFO("Enable NFCP...");

	if(cpSel == 0)
		printk("register...");
	else if(cpsel == 1)
		printk("CW...");
	else if(cpsel == 2)
		printk("E-Fuse...");
	else
		printk("Unknown...");
	
	if(u32CP_mode == 0)
		printk("CBC.\n");
	else if(u32CP_mode == 0x200)
		printk("ECB.\n");
	else
		printk("Unknown.\n");

	return 0;
	
cp_null:
	NF_MSG_INFO("Disable NFCP...\n");
	is_NF_CP_Enable_write = is_NF_CP_Enable_read = 0;
	return -1;

}

static int rtk_nand_wp_setting(unsigned int gpio_dir_base, unsigned int gpio_out_base)
{
	unsigned long long pin_WP_info;

	g_regGPIODirBase = gpio_dir_base;
	g_regGPIOOutBase = gpio_out_base;
	
#if  defined(CONFIG_REALTEK_PCBMGR)
	if(pcb_mgr_get_enum_info_byname("PIN_FLASH_WP",&pin_WP_info)!=0)
	{
		g_WP_en = 0;
		NF_MSG_INFO("PIN_FLASH_WP is not defined\n");
	}else{
		NF_MSG_INFO("PIN_FLASH_WP defined value 0x%llx\n",pin_WP_info);
	
		g_NFWP_no = ((unsigned char) ((pin_WP_info >> 8) & 0xFF));
		g_NFWP_value_INV = ((unsigned char) ((pin_WP_info >> 24) & 0xFF));
		g_NFWP_pinType = GET_PIN_TYPE(pin_WP_info);
		g_NFWP_value_init = ((unsigned char) ((pin_WP_info >> 32) & 0xFF)); //0 enable WP;1 disable WP
		if(g_NFWP_value_init)
		{
			NF_MSG_INFO("PIN_FLASH_WP default disable,g_NFWP_value_init = %d\n",g_NFWP_value_init);
			g_WP_en = 0;
		}else{
			NF_MSG_INFO("PIN_FLASH_WP default enable,g_NFWP_value_init = %d\n",g_NFWP_value_init);
			g_WP_en = 1;				
		}
				
		if(is_darwin_cpu())
		{
			if(g_NFWP_value_INV==0){
				g_NFWP_value_en = 1;
				g_NFWP_value_dis = 0;
			}else{
				g_NFWP_value_en = 0;
				g_NFWP_value_dis = 1;
			}
		}else{
			if(g_NFWP_value_INV==0)
			{
				g_NFWP_value_en = 0;
				g_NFWP_value_dis = 1;
			}else{
				g_NFWP_value_en = 1;
				g_NFWP_value_dis = 0;
			}
		}
	}
#else
	NF_MSG_INFO("Force disable FLASH_WP!!\n");
	g_WP_en=0;
#endif

	NF_MSG_INFO("g_regGPIODirBase = 0x%x\n",g_regGPIODirBase);
	NF_MSG_INFO("g_regGPIOOutBase = 0x%x\n",g_regGPIOOutBase);
	NF_MSG_INFO("g_NFWP_no = %d\n",g_NFWP_no);
	NF_MSG_INFO("g_NFWP_value_en = %d\n",g_NFWP_value_en);
	NF_MSG_INFO("g_NFWP_value_dis = %d\n",g_NFWP_value_dis);
	NF_MSG_INFO("g_NFWP_pinType = %d\n",g_NFWP_pinType);

	return 0;

}

// init global params
static void rtk_nand_params_init(void)
{
	g_BootcodeSize = rtkNF_getBootcodeSize();
	if(g_BootcodeSize == -1)
	{
		if(is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
			g_BootcodeSize = 0x1400000; 	//20M
		else
			g_BootcodeSize = 12*1024*1024;
	}
	
	g_Factory_param_size = rtkNF_getFactParaSize();
	if(g_Factory_param_size == -1)
		g_Factory_param_size = 0x800000;		//8M
	
	g_Secure_store_Start = rtkNF_getSecurestoreStart();
	if(g_Secure_store_Start == -1)
		g_Secure_store_Start = 0x1400000;	//20M
	
	g_Secure_store_Size = rtkNF_getSecurestoreSize();
	if(g_Secure_store_Size == -1)
		g_Secure_store_Size = 0x2100000;	//33M
	
	g_Factory_RO_Start = rtkNF_getFactRoParaStart();
	if(g_Factory_RO_Start == -1)
		g_Factory_RO_Start = 0x3D00000;  
			
	g_Factory_RO_Size = rtkNF_getFactRoParaSize();
	if(g_Factory_RO_Size == -1)
		g_Factory_RO_Size = 0x200000;		//2M
			
	g_CP_Disable_area =  g_BootcodeSize+g_Secure_store_Size+g_Factory_param_size+g_Factory_RO_Size;

	NF_MSG_INFO("Bootcode Area [0x%x ~ 0x%x]\n",0,g_BootcodeSize);
	NF_MSG_INFO("Secure-Store Area [0x%x ~ 0x%x]\n",g_BootcodeSize,(g_BootcodeSize+g_Secure_store_Size));
	NF_MSG_INFO("Factory Area [0x%x ~ 0x%x]\n",(g_BootcodeSize+g_Secure_store_Size),(g_BootcodeSize+g_Secure_store_Size+g_Factory_param_size));
	NF_MSG_INFO("Factory_ro Area [0x%x ~ 0x%x]\n",g_Factory_RO_Start,g_Factory_RO_Start+g_Factory_RO_Size);
	
}

static void rtk_nand_ctrler_init(void)
{
	unsigned int temp_reg = 0;

	struct NF_CLK_INFO nf_clk;

	//set clk info
	nf_clk.nf_clksel = 0x1;
	nf_clk.clk_is_on = 0;
	nf_clk.clk_set_or_get = NF_CLK_SET;

	//change NF freq divider (need to disabled NF clock when change divider) 
	CRT_CLK_OnOff(NAND, CLK_ON, &nf_clk);

	//enable spare DMA to DDR
	if ( is_jupiter_cpu()||is_macarthur_cpu())
		REG_WRITE_U32( REG_SPR_DDR_CTL,0x7<<26);
	else
		REG_WRITE_U32(REG_SPR_DDR_CTL,NF_SPR_DDR_CTL_cr_nf_hw_pinmux_ena(1) | NF_SPR_DDR_CTL_spare_ddr_ena(1) | NF_SPR_DDR_CTL_per_2k_spr_ena(1)| NF_SPR_DDR_CTL_spare_dram_sa(0)); //set spare2ddr func. 4=>0.5k spe2ddr_ena at A000F000

	//reset nand flash
	REG_WRITE_U32( REG_PD,~(0x1 << 0) );
	REG_WRITE_U32( REG_ND_CMD,CMD_RESET );

	if(is_jupiter_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
		REG_WRITE_U32( REG_ND_CTL,(0x80 | 0x00));
	else
		REG_WRITE_U32( REG_ND_CTL,(NF_ND_CTL_xfer(0x01) | NF_ND_CTL_tran_mode(0)) );

	WAIT_DONE(REG_ND_CTL,0x80,0);
	WAIT_DONE(REG_ND_CTL,0x40,0x40);

	//setting low timing for read id
	//REG_WRITE_U32( REG_MULTI_CHNL_MODE,0x00);
	REG_WRITE_U32( REG_TIME_PARA1,NF_TIME_PARA1_T1(0x2));
	REG_WRITE_U32( REG_TIME_PARA2,NF_TIME_PARA2_T2(0x2));
	REG_WRITE_U32( REG_TIME_PARA3,NF_TIME_PARA3_T3(0x2));

	if(!is_jupiter_cpu()||!is_saturn_cpu()||!is_darwin_cpu()||!is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
		REG_WRITE_U32( REG_DELAY_CTL,NF_DELAY_CTL_T_WHR_ADL(0x09) );

	REG_WRITE_U32( REG_MULTI_CHNL_MODE,NF_MULTI_CHNL_MODE_edo(0x00));
	REG_WRITE_U32( REG_ECC_STOP,NF_ECC_STOP_ecc_n_stop(0x01));

	//init colnum address
	REG_WRITE_U32( REG_ND_CA0,0);
	REG_WRITE_U32( REG_ND_CA1,0);

}

static int rtk_nand_boot_type_getting(void)
{
	unsigned char *ptr;
	
 	ptr = rtkNF_getBootType();

	if(ptr == NULL){
		NF_MSG_INFO("[Warning]Can't get boot type!Nand flash driver init continue....\n");
		return 0;
	}else{
		if(memcmp(ptr,"nand",strlen(ptr))!=0){
			NF_MSG_INFO("Boottype %s!Nand flash driver init exit....\n",ptr);
			return -1;
		}else{
			NF_MSG_INFO("Boottype %s!Nand flash driver init continue....\n",ptr);
		}
	}

	return 0;
}

static int rtk_nand_init_condition_check(void)
{
	struct NF_CLK_INFO nf_clk;

	//get clk info
	nf_clk.nf_clksel = 0;
	nf_clk.clk_is_on = 0;
	nf_clk.clk_set_or_get = NF_CLK_GET;	//get nf_clksel
	
	//step1: boot type check
	if(rtk_nand_boot_type_getting()!=0){
		NF_MSG_ERR("Boottype is not nand. Installing fails.\n");
		return -1;
	}
	
	//step2: clock enable check
	CRT_CLK_OnOff(NAND, CLK_ON, &nf_clk);
	if(nf_clk.clk_is_on == 0){
		NF_MSG_ERR("Nand Flash Clock is NOT Open. Installing fails.\n");
		return -1;
	}

	//step3: nand info print
	display_version();

	if(nf_is_random_mode())
		NF_MSG_INFO("Access Mode: Random access mode!\n");
	else
		NF_MSG_INFO("Access Mode: Sequential access mode!\n");
	
#ifdef CONFIG_MTD_NAND_IBT
	NF_MSG_INFO("Enable IBT mechanism of NAND driver.\n");
#endif

	return 0;
}

static void rtk_nand_access_mechanism_init(void)
{
#if RTK_NAND_INTERRUPT
	if(is_darwin_cpu()||is_macarthur_cpu()||is_nike_cpu()||is_macarthur2_cpu()||is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
	{
		NF_MSG_INFO("Enable INT for nand flash driver...\n");
		REG_WRITE_U32(0xb801a640,(REG_READ_U32(0xb801a640)|0x8));//Enable INT of NAND flash
	}
	NF_MSG_INFO("Enable interrupt mechanism of NAND driver.\n");
	platform_driver_probe(&rtkNF_device, rtkNF_probe);
	REG_WRITE_U32(REG_NAND_ISREN,(NF_IRQ_MASK|0x01));
#else
	NF_MSG_INFO("Enable polling mechanism of NAND driver.\n");
#endif
}


//----------------------------------------------------------------------------
#if 0
static int __init rtk_nand_init (void)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this=NULL;
	int rc = 0;

	NF_MSG_INFO("Nand flash init starting....\n");

	if(rtk_nand_init_condition_check() != 0){
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		return -1;
	}

	//polling or interrupt mechanism
	rtk_nand_access_mechanism_init();	

	//init global params
	rtk_nand_params_init();
	
	//setting wp
	rtk_nand_wp_setting(REG_GPIO_DIR_BASE, REG_GPIO_OUT_BASE);

	//setting on-the-fly
	if((is_sirius_cpu()||is_296x_cpu())&&(RTK_MTD_NAND_CP_ENABLE || platform_info.secure_boot)){
		//setting CW/CBC
		rtk_nand_cp_setting(1,0,124);
	}

#if	RTK_ARD_ALGORITHM
 	g_u32WinStart = g_RecBlkStart;
 	g_u32WinEnd = g_u32WinStart+g_PorcWindowSize-1;
	g_WinTrigCnt = 0;
	//printk("Start ARD Algorithm Test : ");
	//printk("\n");
#endif

	//init nand ctrler
	rtk_nand_ctrler_init();
	
	rtk_mtd = kmalloc (MTDSIZE, GFP_KERNEL);
	if ( !rtk_mtd ){
		NF_MSG_ERR("%s: Error, no enough memory for rtk_mtd\n",__FUNCTION__);
		rc = -ENOMEM;
		goto EXIT;
	}
	memset ( (char *)rtk_mtd, 0, MTDSIZE);
	rtk_mtd->priv = this = (struct nand_chip *)(rtk_mtd+1);

	this->read_id		= rtk_nand_read_id;
	this->read_ecc_page 	= rtk_read_ecc_page;
	this->read_oob 		= rtk_read_oob;
	this->write_ecc_page	= rtk_write_ecc_page;
	this->write_oob		= rtk_write_oob;
	this->write_bootcode_area = rtk_write_bootcode_area;

	this->erase_block 	= rtk_erase_block;
	this->suspend		= rtk_nand_suspend;
	this->resume		= rtk_nand_resume;
	this->sync		= NULL;
	this->edo_setting = rtk_nand_edo_setting;
	
	if( rtk_nand_profile() < 0 ){
		rc = -1;
		goto EXIT;
	}

	if(g_isRandomize)
	{
		NF_MSG_INFO("[%s]Randomized enabled \n ",__FUNCTION__);
		cpSel = 0;//0:register, 1:CW, 2:E-Fuse
        	u32CP_mode = 0x0;//0 for CBC mode, 0x200 for ECB mode
	}



	g_NF_pageSize = page_size = rtk_mtd->oobblock;
	oob_size = rtk_mtd->oobsize;
	ppb = (rtk_mtd->erasesize)/(rtk_mtd->oobblock);

#ifdef CONFIG_MTD_NAND_BBT_SHARE
	nand_wq = create_singlethread_workqueue("nand_rpc");
  	if(register_kernel_rpc(RPC_KCPU_NAND_BBT_UPDATE, rtk_nand_rpc_handler) == 1)
    		NF_MSG_WARN("Register rtk_nand_rpc_handler failed!\n");
	else
		NF_MSG_INFO("Register rtk_nand_rpc_handler success!\n");
#endif

	if(rtk_nand_procfs_init()<0)
		NF_MSG_WARN("Register procfs nandinfo file failed!\n");
	
EXIT:
	if (rc < 0) {
		if (rtk_mtd){
			del_mtd_partitions (rtk_mtd);
			if (this->g_databuf)
				kfree(this->g_databuf);
			if(this->g_oobbuf)
				kfree(this->g_oobbuf);
			if (this->erase_page_flag){
				unsigned int flag_size =  (this->numchips * this->page_num) >> 3;
				unsigned int mempage_order = get_order(flag_size);
				free_pages((unsigned long)this->erase_page_flag, mempage_order);
			}
			kfree(rtk_mtd);
		}
		//remove_proc_entry("nandinfo", NULL);
		NF_MSG_ERR("Realtek Nand Flash Driver install fail!\n");
	}else
		NF_MSG_INFO("Realtek Nand Flash Driver is successfully installing.\n");
		
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif		

	return rc;
}
#else
static int __init rtknand_probe(struct platform_device *pdev);

static struct platform_driver rtknand_driver = {
	.driver = {
		.name	 = "rtk_nand",
	},
	.probe		   = rtknand_probe,
	.remove 	   = __exit_p(rtk_nand_exit),
#ifdef CONFIG_PM
	.suspend	   = rtk_nand_suspend,
	.resume 	   = rtk_nand_resume,
#endif
};
#ifdef MTD_NAND_RTK_NAND_TEST
static ssize_t rtk_nand_str_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "test_erase_fail_remap:%u test_write_fail_remap:%u test_read_warning_remap:%u test_read_fail_remap:%u\n", 
		test_erase_fail_remap,test_write_fail_remap,test_read_warning_remap,test_read_fail_remap );
}
extern void dump_bbt(struct mtd_info *mtd);
extern void dump_rbt(struct mtd_info *mtd);

static ssize_t rtk_nand_str_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{	
	switch (buf[0]) {
	case '0':
		printk("do nothing \n");
		
		break;
	case '1':
		test_erase_fail_remap = 1;
		printk("%s set 1 to test_erase_fail_remap %d \n",__FUNCTION__,test_erase_fail_remap);
		break;
	case '2':
		test_write_fail_remap = 1;
		printk("%s set 1 to test_write_fail_remap %d \n",__FUNCTION__,test_write_fail_remap);
		break;
	case '3':
		test_read_warning_remap = 1;
		printk("%s set 1 to test_read_warning_remap %d \n",__FUNCTION__,test_read_warning_remap);
		break;
	case '4':
		test_read_fail_remap = 1;
		printk("%s set 1 to test_read_fail_remap %d \n",__FUNCTION__,test_read_fail_remap);
		break;
#ifdef CONFIG_MTD_NAND_RBT
	case '5':
		printk("%s dump bbt \n",__FUNCTION__);
		dump_bbt(rtk_mtd);
		break;
	case '6':
		printk("%s dump rbt \n",__FUNCTION__);
		dump_rbt(rtk_mtd);
		break;
#endif
	default:
		break;
	}
	return count;
}
static struct kobj_attribute rtk_nand_test_attr = 
	__ATTR(nand_test, 0755, rtk_nand_str_show, rtk_nand_str_store);

static int rtk_spi_nand_sysfs_init(void)
{
	int ret = 0;
	struct kobject *kobj = NULL;

	/* Install the proc_fs entries */
	if((kobj = kobject_create_and_add("nand_test",&(rtknand_driver.driver.p->kobj)))!= NULL){
		ret = sysfs_create_file(kobj,&rtk_nand_test_attr.attr);
	}
	return ret;
}
#endif
static int __init rtknand_probe(struct platform_device *pdev)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this=NULL;
	int rc = 0;

	printk("*********Nand flash init starting....\n");

	if(rtk_nand_init_condition_check() != 0){
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		return -1;
	}

#ifdef CONFIG_ARM64
	if (!pdev->dev.dma_mask)
		pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
	if (!pdev->dev.coherent_dma_mask)
		pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
#endif


	//polling or interrupt mechanism
	//rtk_nand_access_mechanism_init();	

	//init global params
	rtk_nand_params_init();
	
	//setting wp
	rtk_nand_wp_setting(REG_GPIO_DIR_BASE, REG_GPIO_OUT_BASE);

	//setting on-the-fly
	if((is_sirius_cpu()||is_296x_cpu())&&(RTK_MTD_NAND_CP_ENABLE || platform_info.secure_boot)){
		//setting CW/CBC
		rtk_nand_cp_setting(1,0,124);
	}

#if	RTK_ARD_ALGORITHM
 	g_u32WinStart = g_RecBlkStart;
 	g_u32WinEnd = g_u32WinStart+g_PorcWindowSize-1;
	g_WinTrigCnt = 0;
	//printk("Start ARD Algorithm Test : ");
	//printk("\n");
#endif

	//init nand ctrler
	rtk_nand_ctrler_init();
	
	rtk_mtd = kmalloc (MTDSIZE, GFP_KERNEL);
	if ( !rtk_mtd ){
		NF_MSG_ERR("%s: Error, no enough memory for rtk_mtd\n",__FUNCTION__);
		rc = -ENOMEM;
		goto EXIT;
	}
	memset ( (char *)rtk_mtd, 0, MTDSIZE);
	rtk_mtd->priv = this = (struct nand_chip *)(rtk_mtd+1);

	this->read_id		= rtk_nand_read_id;
	this->read_ecc_page 	= rtk_read_ecc_page;
	this->read_oob 		= rtk_read_oob;
	this->write_ecc_page	= rtk_write_ecc_page;
	this->write_oob		= rtk_write_oob;
	this->write_bootcode_area = rtk_write_bootcode_area;

	this->erase_block 	= rtk_erase_block;
	this->suspend		= rtk_nand_suspend;
	this->resume		= rtk_nand_resume;
	this->sync		= NULL;
	this->edo_setting = rtk_nand_edo_setting;
	
	if( rtk_nand_profile() < 0 ){
		rc = -1;
		goto EXIT;
	}

	if(g_isRandomize)
	{
		NF_MSG_INFO("[%s]Randomized enabled \n ",__FUNCTION__);
		cpSel = 0;//0:register, 1:CW, 2:E-Fuse
        	u32CP_mode = 0x0;//0 for CBC mode, 0x200 for ECB mode
	}



	g_NF_pageSize = page_size = rtk_mtd->oobblock;
	oob_size = rtk_mtd->oobsize;
	ppb = (rtk_mtd->erasesize)/(rtk_mtd->oobblock);

#ifdef CONFIG_MTD_NAND_BBT_SHARE
	nand_wq = create_singlethread_workqueue("nand_rpc");
  	if(register_kernel_rpc(RPC_KCPU_NAND_BBT_UPDATE, rtk_nand_rpc_handler) == 1)
    		NF_MSG_WARN("Register rtk_nand_rpc_handler failed!\n");
	else
		NF_MSG_INFO("Register rtk_nand_rpc_handler success!\n");
#endif

	if(rtk_nand_procfs_init()<0)
		NF_MSG_WARN("Register procfs nandinfo file failed!\n");
#ifdef MTD_NAND_RTK_NAND_TEST
	rtk_spi_nand_sysfs_init();
#endif
EXIT:
	if (rc < 0) {
		if (rtk_mtd){
			del_mtd_partitions (rtk_mtd);
			if (this->g_databuf)
				kfree(this->g_databuf);
			if(this->g_oobbuf)
				kfree(this->g_oobbuf);
			if (this->erase_page_flag){
				unsigned int flag_size =  (this->numchips * this->page_num) >> 3;
				unsigned int mempage_order = get_order(flag_size);
				free_pages((unsigned long)this->erase_page_flag, mempage_order);
			}
			kfree(rtk_mtd);
		}
		//remove_proc_entry("nandinfo", NULL);
		NF_MSG_ERR("Realtek Nand Flash Driver install fail!\n");
	}else
		NF_MSG_INFO("Realtek Nand Flash Driver is successfully installing.\n");
		
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif		

	return rc;
    
}

static int __init rtk_nand_init (void)
{
    int rc = 0;
	rc = platform_driver_probe(&rtknand_driver, rtknand_probe);

	if (rc < 0){
		printk( "Realtek Nand Controller Driver installation fails.\n\n");

	}else{
		printk( "Realtek Nand Controller Driver is successfully installing.\n\n");
	}
    return rc;
}


#endif
//----------------------------------------------------------------------------
void __exit rtk_nand_exit (void)
{
	struct nand_chip *this = NULL;
	free_irq(g_host->irq, g_host);

	if (rtk_mtd){
		del_mtd_partitions (rtk_mtd);
		this = (struct nand_chip *)rtk_mtd->priv;
		if (this->g_databuf)
			kfree(this->g_databuf);
		if(this->g_oobbuf)
			kfree(this->g_oobbuf);
		if (this->erase_page_flag){
			unsigned int flag_size =  (this->numchips * this->page_num) >> 3;
			unsigned int mempage_order = get_order(flag_size);
			free_pages((unsigned long)this->erase_page_flag, mempage_order);
		}
		kfree(rtk_mtd);

	}
	remove_proc_entry("nandinfo", NULL);
}
//----------------------------------------------------------------------------
module_init(rtk_nand_init);
module_exit(rtk_nand_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("AlexChang <alexchang2131@realtek.com>");
MODULE_DESCRIPTION("Realtek NAND Flash Controller Driver");
