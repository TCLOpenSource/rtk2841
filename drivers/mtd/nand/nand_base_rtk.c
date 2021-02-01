/******************************************************************************
 * $Id: nand_base_rtk.c 317223 2010-06-01 07:38:49Z alexchang2131 $
 * drivers/mtd/nand/nand_base_rtk.c
 * Overview: Realtek MTD NAND Driver 
 * Copyright (c) 2008 Realtek Semiconductor Corp. All Rights Reserved.
 * Modification History:
 *    #000 2008-06-10 Ken-Yu   create file
 *    #001 2008-09-10 Ken-Yu   add BBT and BB management
 *    #002 2008-09-28 Ken-Yu   change r/w from single to multiple pages
 *    #003 2008-10-09 Ken-Yu   support single nand with multiple dies
 *    #004 2008-10-23 Ken-Yu   support multiple nands
 * Copyright (C) 2007-2013 Realtek Semiconductor Corporation
 *******************************************************************************/
#include <linux/delay.h>
#include <linux/errno.h>
#include <linux/sched.h>
#include <linux/types.h>
#include <linux/mtd/mtd.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/bitops.h>
#include <linux/parser.h>
// Ken-Yu 
#include <mtd/mtd-abi.h>
#include <linux/mtd/rtk_nand.h>

#include <mach/io.h>
#include <rbus/nand_reg.h>

#include <asm/page.h>
#include <linux/jiffies.h>

#include <linux/mtd/rtk_mtd_patch.h>
#include <linux/mtd/flash_nand_profile.h>
#include <linux/semaphore.h>
#include <linux/module.h>
#include "../../rtk_kdriver/include/rtk_kdriver/rtk_crt.h" //#include <mach/rtk_crt.h>

#ifdef CONFIG_MTD_NAND_BBT_SHARE
#include "../../rtk_kdriver/include/rtk_kdriver/RPCDriver.h" //#include <mach/RPCDriver.h>
#endif


#ifdef CONFIG_NAND_MULTI_READ_FOR_CARDREADER
	#define NAND_POWEROFF_CARDREADER_WITH_MULTI_READ	(1)//add for fixing card reader share pin bug. alexchang 0831-2010
#else
	#define NAND_POWEROFF_CARDREADER_WITH_MULTI_READ	(0)//add for fixing card reader share pin bug. alexchang 0831-2010
#endif

#ifdef CONFIG_NAND_READ_SKIP_UPDATE_BBT
	#define NAND_READ_SKIP_UPDATE_BBT		(1)//add for fixing card reader share pin bug. alexchang 0901-2010
#else
	#define NAND_READ_SKIP_UPDATE_BBT		(0)//add for fixing card reader share pin bug. alexchang 0901-2010
#endif

static DEFINE_SEMAPHORE (sem_rd);
static DEFINE_SEMAPHORE (sem_wte);
static DEFINE_SEMAPHORE (sem_bbt);

static unsigned char g_isSysSecure = 0;
extern unsigned char g_isRandomize;
extern unsigned int g_BootcodeSize;
extern  unsigned int g_Factory_param_size;
#define READ_RETRY_COUNT	3
#define Nand_Block_Isbad_Slow_Version 0
#define MTD_SEM_RETRY_COUNT	(0x40)
#define NOTALIGNED(mtd, x) (x & (mtd->oobblock-1)) != 0
#define NAND_CP_RW_DISABLE (0xFFFFFFFF)
unsigned int g_eccSelect =0xFF;

extern unsigned int g_Secure_store_Start;
extern unsigned int g_Secure_store_Size;
unsigned int gp_access_range = 0;

//for writing profile
static const device_type_t *ptr_device;
#ifdef CONFIG_MTD_NAND_RBT
extern int init_table(struct mtd_info *mtd);
extern int rtk_nand_reload_bbt(struct mtd_info *mtd);
extern int get_phyblock(struct mtd_info *mtd,int logblock);
extern int erase_remap_block(struct mtd_info *mtd,int logblock,int bad_block);
extern int remap_write_block_content(struct mtd_info *mtd,int log_block,int page,const u_char * page_content);
extern int remap_read_block_content(struct mtd_info *mtd,int log_block,int page);
#endif

#ifdef CONFIG_MTD_NAND_IBT
unsigned int IBT_LEN=0;
#endif

#define check_end(mtd, addr, len)					\
do {									\
	if (mtd->size == 0) 						\
		return -ENODEV;						\
	else								\
	if ((addr + len) > mtd->size) {					\
		printk (				\
			"%s: attempt access past end of device\n",	\
			__FUNCTION__);					\
		return -EINVAL;						\
	}								\
} while(0)

#define check_page_align(mtd, addr)					\
do {									\
	if (addr & (mtd->oobblock - 1)) {				\
		printk (				\
			"%s: attempt access non-page-aligned data\n",	\
			__FUNCTION__);					\
		printk (				\
			"%s: mtd->oobblock = 0x%x\n",			\
			__FUNCTION__,mtd->oobblock);			\
		return -EINVAL;						\
	}								\
} while (0)

#define check_block_align(mtd, addr)					\
do {									\
	if (addr & (mtd->erasesize - 1)) {				\
		printk (				\
			"%s: attempt access non-block-aligned data\n",	\
			__FUNCTION__);					\
		return -EINVAL;						\
	}								\
} while (0)

#define check_len_align(mtd,len)					\
do {									\
	if (len & (512 - 1)) {          	 			\
		printk (				\
               	      "%s: attempt access non-512bytes-aligned mem\n",	\
			__FUNCTION__);					\
		return -EINVAL;						\
	}								\
} while (0)

extern char *rtkNF_parse_token(const char *parsed_string, const char *token);
extern unsigned int rtkNF_getBootcodeSize(void);
extern unsigned int rtkNF_getFactParaSize(void);
unsigned int g_mtd_BootcodeSize = 0;
extern int g_sw_WP_level;
extern int g_disNFWP;
#if NAND_POWEROFF_CARDREADER_WITH_MULTI_READ
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
static char *NF_parse_token(const char *parsed_string, const char *token)
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
				strncpy(ret_str, value_start, value_end-value_start);
				ret_str[value_end-value_start] = '\0';
				return ret_str;
			} else {
				ret_str = kmalloc(1, GFP_KERNEL);
				strcpy(ret_str, "");
				return ret_str;
			}
		}
	}

	return (char*)NULL;
}
#endif

#if NAND_POWEROFF_CARDREADER_WITH_MULTI_READ
u32 NF_rtk_power_gpio=0;
u32 NF_rtk_power_bits=0;
void NF_rtkcr_card_power(u8 status)
{
    void __iomem *mmio = (void __iomem *) NF_rtk_power_gpio;
    if(status==0){ //power on
        printk("Card Power on\n");
        writel(readl(mmio) & ~(1<<NF_rtk_power_bits),mmio);
    }else{          //power off
        printk("Card Power off\n");
        writel(readl(mmio) | (1<<NF_rtk_power_bits),mmio);
    }
}
void NF_rtkcr_chk_param(u32 *pparam, u32 len, u8 *ptr)
{
    unsigned int value,i;
    for(i=0;i<len;i++){
        value = ptr[i] - '0';
        if((value >= 0) && (value <=9))
        {
            *pparam+=value<<(4*(len-1-i));
            continue;
        }
        value = ptr[i] - 'a';
        if((value >= 0) && (value <=5))
        {
            value+=10;
            *pparam+=value<<(4*(len-1-i));
            continue;
        }
        value = ptr[i] - 'A';
        if((value >= 0) && (value <=5))
        {
            value+=10;
            *pparam+=value<<(4*(len-1-i));
            continue;
        }
    }
}
int NF_rtkcr_get_gpio(void)
{
    unsigned char *cr_param;
    void __iomem *mmio;
    cr_param=(char *)NF_parse_token(platform_info.system_parameters,"cr_pw");
    if(cr_param){
        NF_rtkcr_chk_param(&NF_rtk_power_gpio,4,cr_param);
        NF_rtkcr_chk_param(&NF_rtk_power_bits,2,cr_param+5);

        mmio = (void __iomem *) (NF_rtk_power_gpio+0xb8010000);
        writel(readl(mmio) | (1<<NF_rtk_power_bits),mmio); //enable GPIO output

        if((NF_rtk_power_gpio & 0xf00) ==0x100){
            NF_rtk_power_gpio+=0xb8010010;
        }else if((NF_rtk_power_gpio & 0xf00) ==0xd00){
            NF_rtk_power_gpio+=0xb8010004;
        }else{
            printk(KERN_ERR "wrong GPIO of card's power.\n");
            return -1;
        }
        printk("power_gpio = 0x%x\n",NF_rtk_power_gpio);
        printk("power_bits = %d\n",NF_rtk_power_bits);
        return 0;
    }
    printk(KERN_ERR "Can't find GPIO of card's power.\n");
    return -1;

}

#endif
/* Realtek supports nand chip types */
/* Micorn */
#define MT29F2G08AAD	0x2CDA8095	//SLC, 256 MB, 1 dies
#define MT29F2G08ABAE	0x2CDA9095  //SLC, 256MB, 1 dies
#define MT29F1G08ABADA  0x2CF18095  //SLC, 128MB, 1 dies
#define MT29F4G08ABADA  0x2CDC9095  //SLC, 512MB, 1 dies
//#define MT29F32G08CBACA  0x2C68044A  //MLC, 4GB, 1 dies
#define MT29F64G08CBAAA  0x2C88044B //MLC, 8GB, 1dies
#define MT29F8G08ABABA   0x2C380026  //Micron 1GB   (SLC single die)
#define MT29F4G08ABAEAH4 0x2CDC90A6  //Micron 4Gb   (SLC single die)
#define MT29F8G08ABACA	  0x2CD390A6	//Micron 8GB   (SLC single die)


/* STMicorn */
#define NAND01GW3B2B	0x20F1801D	//SLC, 128 MB, 1 dies
#define NAND01GW3B2C	0x20F1001D	//SLC, 128 MB, 1 dies, son of NAND01GW3B2B
#define NAND02GW3B2D	0x20DA1095	//SLC, 256 MB, 1 dies
#define NAND04GW3B2B	0x20DC8095	//SLC, 512 MB, 1 dies
#define NAND04GW3B2D	0x20DC1095	//SLC, 512 MB, 1 dies
#define NAND04GW3C2B	0x20DC14A5	//MLC, 512 MB, 1 dies
#define NAND08GW3C2B	0x20D314A5	//MLC, 1GB, 1 dies

/* Hynix Nand */
#define HY27UF081G2A	0xADF1801D	//SLC, 128 MB, 1 dies
#define HY27UF081G2B	0xADF1801D	//SLC, 128 MB, 1 dies

#define HY27UF082G2A	0xADDA801D	//SLC, 256 MB, 1 dies
#define HY27UF082G2B	0xADDA1095	//SLC, 256 MB, 1 dies
#define HY27UF084G2B	0xADDC1095	//SLC, 512 MB, 1 dies
#define HY27UF084G2M	0xADDC8095	//SLC, 512 MB, 1 dies
	/* HY27UT084G2M speed is slower, we have to decrease T1, T2 and T3 */
#define HY27UT084G2M	0xADDC8425	//MLC, 512 MB, 1 dies, BB check at last page, SLOW nand
#define HY27UT084G2A	0xADDC14A5	//MLC, 512 MB, 1 dies
#define H27U4G8T2B		0xADDC14A5	//MLC, 512 MB, 1 dies
#define HY27UT088G2A	0xADD314A5	//MLC, 1GB, 1 dies, BB check at last page
#define HY27UG088G5M	0xADDC8095	//SLC, 1GB, 2 dies
#define HY27UG088G5B	0xADDC1095	//SLC, 1GB, 2 dies
#define H27U8G8T2B		0xADD314B6	//MLC, 1GB, 1 dies, 4K page
#define H27UAG8T2A		0xADD59425	//MLC, 2GB, 1 dies, 4K page
#define H27UAG8T2B		0xADD5949A	//MLC, 2GB, 1 dies, 8K page
#define H27U2G8F2C		0xADDA9095	//SLC, 256 MB, 1 dies, 2K page
#define H27U4G8F2D      0xADDC9095  //SLC, 512MB, 1dies, 2K page
#define H27U1G8F2B      0xADF1001D	//SLC, 128MB, 1dies, 2K page
#define H27UBG8T2A		0xADD7949A	//MLC, 4GB, 1 dies, 8K page
#define H27UBG8T2B		0xADD794DA	//MLC, 4GB, 1 dies, 8K page
#define H27U4G8F2ETR	0xADDC9095	//SLC, 512MB, 1dies, 2K page


 

/* Samsung Nand */
#define K9F1G08U0B	0xECF10095	//SLC, 128 MB, 1 dies
#define K9F1G08U0D	0xECF10015	//SLC, 128 MB, 1 dies
#define K9F2G08U0B	0xECDA1095	//SLC, 256 MB, 1 dies
#define K9G4G08U0A	0xECDC1425	//MLC, 512 MB, 1 dies, BB check at last page
#define K9G4G08U0B	0xECDC14A5	//MLC, 512 MB, 1 dies, BB check at last page
#define K9F4G08U0B	0xECDC1095	//SLC, 512 MB, 1 dies
#define K9G8G08U0A	0xECD314A5	//MLC, 1GB, 1 dies, BB check at last page
#define K9G8G08U0M	0xECD31425	//MLC, 1GB, 1 dies, BB check at last page
#define K9K8G08U0A	0xECD35195	//SLC, 1GB, 1 dies
#define K9F8G08U0M	0xECD301A6	//SLC, 1GB, 1 dies, 4K page
#define K9K8G08U0D	0xECD31195  //SLC, 1GB, 1 dies

/* Toshiba */
#define TC58NVG0S3C	0x98F19095	//128 MB, 1 dies
#define TC58NVG0S3E	0x98D19015	//128 MB, 1 dies
#define TC58NVG1S3C	0x98DA9095	//256 MB, 1 dies
#define TC58NVG1S3E	0x98DA9015	//256 MB, 1 dies
#define TC58NVG2S3E	0x98DC9015	//512 MB, 1 dies
#define TC58NVG5D2F	0x98D79432	//MLC, 4GB, 1 dies, 8K page
#define TC58NVG4D2E 0x98D59432  //MLC, 2GB, 1 dies, 8K page
#define TC58NVG2S0F 0x98DC9026  //SLC,512MB 1 dies,4K page
#define TC58NVG2S0FTA00	0x98D39026	// Toshiba 4Gb  (SLC single die)
#define TC58NVG5D2H 0x98D79432 
#define TC58BVG0S3H     0x98F18015	//SLC, 1GB, 1 dies
#define TC58BVG1S3H     0x98DA9015	//SLC, 2GB, 1 dies
#define TC58NVG0S3H     0x98F18015	//SLC, 1GB, 1 dies
#define TC58NVG1S3H     0x98DA9015	//SLC, 2GB, 1 dies
#define TC58DVG02D5		0x98f10015  //SLC,128MB 1 dies 
#define TH58NVG2S3HTA00 0x98DC9115		//SLC,512MB 2 dies

/* Macronix/MXIC */
#define MX30LF1G08AM 0xC2F1801D // 128 MB, 1 dies
#define MX30LF1208AA 0xC2F0801D // 64MB, 1 dies
#define MX30LF1G18AC        0xC2F18095      //MIX  1Gb
#define MX30LF2G18AC        0xC2DA9095      //MIX 2Gb
#define MX30LF4G18AC        0xC2DC9095      //MIX 4Gb
#define MX60LF8G18AC        0xC2D3D195      //MIX 8Gb

/* ESMT */
#define F59L1G81A  0x92F18095
#define F59L4G81A	0xC8DC9095
#define F59L1G81A2Y	0xC8D18095 
#define F59L2G81A	0xC8DA9095


/*MIRA*/
//#define PSU2GA30AT 0X7F7F7F7F      
#define PSU2GA30BT    0xC8DA9095
#define PSU4GA30AT    0xC8DC9095

/*Spansion*/
#define S34ML01G1	        0x01F1001D
#define S34ML02G1	        0x01DA9095
#define S34ML04G1	        0x01DC9095  
#define S34ML01G2     		0x01F1801D
#define S34ML02G2	        0x01DA9095 
#define S34ML04G2	        0x01DC9095 


/*Zentel*/
#define A5U2GA31BTS	        0xC8DA9095
/*winbond*/
#define W29N01HV  				0xEFF10095         //winbond 1Gb
#define W29N02GV  				0xEFDA9095         //winbond 2Gb
#define W29N04GV  				0xEFDC9095        //winbond 4Gb
#define W29N08GV  				0xEFD39195        //winbond 8Gb

/*GD*/
#define GD9FU1G8F2A       0xC8F1801D       //GD  1Gb  

/* RTK Nand Chip ID list */
static device_type_t nand_device[] = 
{
 {"MT29F2G08AAD", MT29F2G08AAD, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"MT29F2G08ABAE", MT29F2G08ABAE, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff,0x01, 0x01, 0x01, 0x00, 4}, 	
 {"MT29F1G08ABADA", MT29F1G08ABADA, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff,0x01, 0x01, 0x01, 0x00, 4},	 
 {"MT29F4G08ABADA", MT29F4G08ABADA, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x56, 0xff, 0xff,0x01, 0x01, 0x01, 0x00, 4},	  	
 //{"MT29F32G08CBACA", MT29F32G08CBACA, 0x100000000, 0x100000000, 4096, 256*4096, 224, 1, 0, 0xff, 0xff, 0x18,0x00, 0x00, 0x00, 0x18, 20},	
 {"MT29F64G08CBAAA", MT29F64G08CBAAA, 0x200000000, 0x200000000, 8192, 256*8192, 448, 1, 0, 0xff, 0xff, 0x18,0x01, 0x01, 0x01, 0x18, 20},	  	
 {"MT29F8G08ABABA", MT29F8G08ABABA, 0x40000000, 0x40000000, 4096, 128*4096, 224, 1, 0, 0x85, 0xff, 0xff,0x01, 0x01, 0x01, 0x00, 4}, 	 
 {"MT29F4G08ABAEAH4", MT29F4G08ABAEAH4, 0x20000000, 0x20000000, 4096, 64*4096, 224, 1, 0, 0x54, 0xff, 0xff,0x01, 0x01, 0x01, 0x0c, 8},
 {"MT29F8G08ABACA", MT29F8G08ABACA, 0x40000000, 0x40000000, 4096, 64*4096, 224, 1, 0, 0x64, 0xff, 0xff,0x01, 0x01, 0x01, 0x0c, 8},

 {"NAND01GW3B2B", NAND01GW3B2B, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"NAND01GW3B2C", NAND01GW3B2C, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"NAND02GW3B2D", NAND02GW3B2D, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0x44, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"NAND04GW3B2B", NAND04GW3B2B, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x20, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"NAND04GW3B2D", NAND04GW3B2D, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"NAND04GW3C2B", NAND04GW3C2B, 0x20000000, 0x20000000, 2048, 128*2048, 64, 1, 1, 0x24, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"NAND08GW3C2B", NAND08GW3C2B, 0x40000000, 0x40000000, 2048, 128*2048, 64, 1, 1, 0x34, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UF081G2A", HY27UF081G2A, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UF081G2B", HY27UF081G2B, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UF082G2A", HY27UF082G2A, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0x00, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UF082G2B", HY27UF082G2B, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0x44, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UF084G2B", HY27UF084G2B, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UT084G2A", HY27UT084G2A, 0x20000000, 0x20000000, 2048, 128*2048, 64, 1, 1, 0x24, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"H27U4G8T2B", H27U4G8T2B, 0x20000000, 0x20000000, 2048, 128*2048, 64, 1, 1, 0x24, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UT088G2A", HY27UT088G2A, 0x40000000, 0x40000000, 2048, 128*2048, 64, 1, 1, 0x34, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UF084G2M", HY27UF084G2M, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UT084G2M", HY27UT084G2M, 0x20000000, 0x20000000, 2048, 128*2048, 64, 1, 1, 0xff, 0xff, 0xff, 0x04, 0x04, 0x04, 0x00, 4},
 {"HY27UG088G5M", HY27UG088G5M, 0x40000000, 0x20000000, 2048, 64*2048, 64, 2, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"HY27UG088G5B", HY27UG088G5B, 0x40000000, 0x20000000, 2048, 64*2048, 64, 2, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"H27U8G8T2B", H27U8G8T2B, 0x40000000, 0x40000000, 4096, 128*4096, 128, 1, 1, 0x34, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"H27UAG8T2A", H27UAG8T2A, 0x80000000, 0x80000000, 4096, 128*4096, 224, 1, 1, 0x44, 0x41, 0x18, 0x01, 0x01, 0x01, 0x0c, 8},
 {"H27UAG8T2B", H27UAG8T2B, 0x80000000, 0x80000000, 8192, 256*8192, 448, 1, 1, 0x74, 0x42, 0x18, 0x01, 0x01, 0x01, 0x18, 20},
 {"H27U2G8F2C", H27U2G8F2C, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 1, 0x44, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4}, 	 
 {"H27U4G8F2D", H27U4G8F2D, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 1, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},  	
 {"H27U1G8F2B", H27U1G8F2B, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},  	
 {"H27UBG8T2A", H27UBG8T2A, 0x100000000, 0x100000000, 8192, 256*8192, 448, 1, 1, 0x74, 0x42, 0x18, 0x01, 0x01, 0x01, 0x18, 20},
 {"H27UBG8T2B", H27UBG8T2B, 0x100000000, 0x100000000, 8192, 256*8192, 448, 1, 1, 0x74, 0xc3, 0x18, 0x01, 0x01, 0x01, 0x18, 20}, 	
 {"H27U4G8F2ETR", H27U4G8F2ETR, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 1, 0x56, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4}, 	

 {"K9F1G08U0B", K9F1G08U0B, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0x40, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9F1G08U0D", K9F1G08U0D, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0x40, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9F2G08U0B", K9F2G08U0B, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0x44, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9G4G08U0A", K9G4G08U0A, 0x20000000, 0x20000000, 2048, 128*2048, 64, 1, 1, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9G4G08U0B", K9G4G08U0B, 0x20000000, 0x20000000, 2048, 128*2048, 64, 1, 1, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9F4G08U0B", K9F4G08U0B, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9G8G08U0A", K9G8G08U0A, 0x40000000, 0x40000000, 2048, 128*2048, 64, 1, 1, 0x64, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9G8G08U0M", K9G8G08U0M, 0x40000000, 0x40000000, 2048, 128*2048, 64, 1, 1, 0x64, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9K8G08U0A", K9K8G08U0A, 0x40000000, 0x40000000, 2048, 64*2048, 64, 1, 0, 0x58, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9F8G08U0M", K9F8G08U0M, 0x40000000, 0x40000000, 4096, 64*4096, 128, 1, 0, 0x64, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"K9K8G08U0D", K9K8G08U0D, 0x40000000, 0x40000000, 2048, 64*2048, 64, 1, 0, 0x58, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4}, 	
 {"TC58NVG0S3C", TC58NVG0S3C, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"TC58NVG0S3E", TC58NVG0S3E, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0x76, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"TC58NVG1S3C", TC58NVG1S3C, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"TC58NVG2S3E", TC58NVG2S3E, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x76, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"TC58NVG5D2F", TC58NVG5D2F, 0x100000000, 0x100000000, 8192, 128*8192, 448, 1, 1, 0x76, 0x55, 0x18, 0x01, 0x01, 0x01, 0x18, 20},
 {"TC58NVG4D2E", TC58NVG4D2E, 0x80000000, 0x80000000, 8192, 128*8192, 448, 1, 1, 0x76, 0x55, 0x18, 0x01, 0x01, 0x01, 0x18, 20},
 {"TC58NVG2S0F", TC58NVG2S0F, 0x20000000, 0x20000000, 4096, 64*4096, 128, 1, 0, 0x76, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"TC58NVG2S0FTA00", TC58NVG2S0F, 0x20000000, 0x20000000, 4096, 64*4096, 128, 1, 0, 0x76, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
  	
 {"TC58NVG5D2H", TC58NVG5D2H, 0x20000000, 0x20000000, 8192, 128*8192, 80, 1, 0, 0x76, 0x56, 0x18, 0x01, 0x01, 0x01, 0x18, 20},
 {"TC58BVG0S3H", TC58BVG0S3H, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xF2, 0x16, 0xff, 0x01, 0x01, 0x01, 0x0c, 8},
 {"TC58BVG1S3H", TC58BVG1S3H, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0xF6, 0x16, 0xff, 0x01, 0x01, 0x01, 0x0c, 8},
 {"TC58NVG0S3H", TC58NVG0S3H, 0x8000000, 0x8000000, 2048, 64*2048, 128, 1, 0, 0x72, 0x16, 0xff, 0x01, 0x01, 0x01, 0x0c, 8},
 {"TC58NVG1S3H", TC58NVG1S3H, 0x10000000, 0x10000000, 2048, 64*2048, 128, 1, 0, 0x76, 0x16, 0xff, 0x01, 0x01, 0x01, 0x0c, 8},
 {"TC58NVG1S3E", TC58NVG1S3E, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0x76, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"TC58DVG02D5", TC58DVG02D5, 0x8000000, 0x8000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	
 {"TH58NVG2S3HTA00", TH58NVG2S3HTA00, 0x20000000, 0x20000000, 2048, 64*2048, 128, 1, 0, 0x76, 0xff, 0xff, 0x01, 0x01, 0x01, 0x0c, 8},	
  
 {"MX30LF1G08AM", MX30LF1G08AM, 0x8000000, 0x8000000, 2048,  64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"MX30LF1208AA", MX30LF1208AA, 0x4000000, 0x4000000, 2048,  64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	 
 {"MX30LF1G18AC", MX30LF1G18AC, 0x8000000, 0x8000000, 2048,  64*2048, 64, 1, 0, 0x02, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00,  4},	  
 {"MX30LF2G18AC", MX30LF2G18AC, 0x10000000, 0x10000000, 2048,  64*2048, 64, 1, 0, 0x06, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	 
 {"MX30LF4G18AC", MX30LF4G18AC, 0x20000000, 0x20000000, 2048,  64*2048, 64, 1, 0, 0x56, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},     
 {"MX60LF8G18AC", MX60LF8G18AC, 0x40000000, 0x40000000,2048,  64*2048, 64, 1, 0, 0x5A, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4}, 
 
 {"F59L1G81A", F59L1G81A, 0x8000000, 0x8000000, 2048,  64*2048, 64, 1, 0, 0x40, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"F59L4G81A", F59L4G81A, 0x20000000, 0x20000000, 2048, 64*2048, 64, 1, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"F59L1G81A2Y", F59L1G81A2Y, 0x8000000, 0x8000000, 2048,  64*2048, 64, 1, 0, 0x40, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	  
 {"F59L2G81A", F59L2G81A, 0x10000000, 0x10000000, 2048,  64*2048, 64, 1, 0, 0x44, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
  	
// {"PSU2GA30AT", PSU2GA30AT, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0xC8, 0xDA, 0xff, 0x00, 0x00, 0x00, 0x00, 4},    
 {"S34ML01G1",S34ML01G1, 0x8000000,  0x8000000,  2048,  64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"S34ML02G1",S34ML02G1, 0x10000000, 0x10000000, 2048,  64*2048, 64, 1, 0, 0x44, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"S34ML04G1",S34ML04G1, 0x20000000, 0x20000000, 2048,  64*2048, 64, 1, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},                
 {"S34ML01G2",S34ML01G2, 0x8000000,  0x8000000,  2048,  64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 4},
 {"S34ML02G2",S34ML02G2, 0x10000000, 0x10000000, 2048,  64*2048, 128, 1, 0, 0x46, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},
 {"S34ML04G2",S34ML04G2, 0x20000000, 0x20000000, 2048,  64*2048, 128, 1, 0, 0x56, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 4},
 {"A5U2GA31BTS", A5U2GA31BTS, 0x10000000, 0x10000000, 2048, 64*2048, 64, 1, 0, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 4},     	
 
 {"W29N01HV", W29N01HV, 0x8000000, 0x8000000, 2048,  64*2048, 64, 1, 0, 0x00, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	  
 {"W29N02GV", W29N02GV, 0x10000000, 0x10000000, 2048,  64*2048, 64, 1, 0, 0x04, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	
 {"W29N04GV", W29N04GV, 0x20000000, 0x20000000, 2048,  64*2048, 64, 1, 0, 0x54, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},   
 {"W29N08GV", W29N08GV, 0x40000000, 0x40000000, 2048,  64*2048, 64, 1, 0, 0x58, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4}, 
 
 {"GD9FU1G8F2A",GD9FU1G8F2A, 0x8000000, 0x8000000, 2048,  64*2048, 64, 1, 0, 0x42, 0xff, 0xff, 0x01, 0x01, 0x01, 0x00, 4},	  
 {NULL, }
};

/* NAND low-level MTD interface functions */
static int nand_read (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf);
static int nand_read_ecc (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *buf, 
			u_char *oob_buf, struct nand_oobinfo *oobsel);
static int nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf);
static int nand_write_ecc (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char * buf, 
			const u_char *oob_buf, struct nand_oobinfo *oobsel);
static int nand_erase (struct mtd_info *mtd, struct erase_info *instr);
static void nand_sync (struct mtd_info *mtd);
static int nand_suspend (struct mtd_info *mtd);
static void nand_resume (struct mtd_info *mtd);
static int nand_read_oob (struct mtd_info *mtd, loff_t from, struct mtd_oob_ops *ops);
static int nand_read_oob_ext (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, u_char *oob_buf);
	
static int nand_write_oob (struct mtd_info *mtd, loff_t to, struct mtd_oob_ops *ops);

/* YAFFS2 */

static int nand_block_isbad (struct mtd_info *mtd, loff_t ofs);
static int nand_block_markbad (struct mtd_info *mtd, loff_t ofs);
static int rtk_badblock_remap(struct mtd_info *mtd, u16 chipnr, unsigned int page);
/////////////////////////////////////////
int rtk_update_bbt (struct mtd_info *mtd, __u8 *data_buf, __u8 *oob_buf, BB_t *bbt);

#ifdef NAND_FLASH_DEBUG
static int TEST_ERASE_ALL(struct mtd_info *mtd, int page, int bc);
static int TEST_READ_WRITE(struct mtd_info *mtd, int page);
#endif



/* Global Variables */
int RBA=0;
static int oob_size, ppb, isLastPage;
static int page_size = 0;

#if 0		//rtk_mtd_patch
extern platform_info_t platform_info;
char *mp_erase_nand;
int mp_erase_flag = 0;
char *mp_time_para;
int mp_time_para_value = 0;
char *nf_clock;
int nf_clock_value = 0;
char *mcp;
#endif

//===========================================================================
static void NF_CKSEL(char *PartNum, unsigned int value)
{
	struct NF_CLK_INFO nf_clk;

	//set clk info
	nf_clk.nf_clksel = value;
	nf_clk.clk_is_on = 0;
	nf_clk.clk_set_or_get = NF_CLK_SET;	//set clksel

	//change NF freq divider (need to disabled NF clock when change divider) 
	CRT_CLK_OnOff(NAND, CLK_ON, &nf_clk);

	printk("[%s] %s is set to nf clock: 0x%x\n", __FUNCTION__, PartNum, value);
}
//------------------------------------------------------------------------------------------------

static int  check_BBT(struct mtd_info *mtd, unsigned int blk)
{
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int i;
	//int BBs=0;

	printk("[%s]..\n", __FUNCTION__);
	for ( i=0; i<RBA; i++)
	{
		if ( this->bbt[i].bad_block == blk )
		{
			printk("blk 0x%x exist\n",blk);
			return -1;	
		}
	}

	return 0;
}

//------------------------------------------------------------------------------------------------
static int  check_SW_WP(struct mtd_info *mtd)
{
	if(!(mtd->flags & MTD_WRITEABLE))
		return -1;
	if(!(mtd->flags & MTD_SWP_WRITEABLE))
		return -1;
	else
		return 0;
}

//------------------------------------------------------------------------------------------------
static void dump_BBT(struct mtd_info *mtd)
{
	
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int i;
	int BBs=0;
	printk("[%s] Nand BBT Content\n", __FUNCTION__);
	for ( i=0; i<RBA; i++){
		if ( i==0 && this->bbt[i].BB_die == BB_DIE_INIT && this->bbt[i].bad_block == BB_INIT ){
			printk("Congratulation!! No BBs in this Nand.\n");
			break;
		}
		if ( this->bbt[i].bad_block != BB_INIT ){
			printk("[%d] (%d, %u, %d, %u)\n", i, this->bbt[i].BB_die, this->bbt[i].bad_block, 
				this->bbt[i].RB_die, this->bbt[i].remap_block);
			BBs++;
		}
	}
	this->BBs = BBs;
}

#if 0
static void reverse_to_Yaffs2Tags(__u8 *r_oobbuf)
{
	int k;
	int cpBits=0;
	if(page_size==2048)
		cpBits=16;
	else
		cpBits=32;
	for ( k=0; k<cpBits; k++ ){
//	for ( k=0; k<oob_size; k++ ){
		r_oobbuf[k]  = r_oobbuf[1+k];
	}
}
#endif

int rtk_block_isbad(struct mtd_info *mtd, u16 chipnr, loff_t ofs)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	unsigned int page, block, page_offset;
	unsigned char block_status_p1;
#if Nand_Block_Isbad_Slow_Version
	unsigned char block_status_p2;
#endif

	unsigned char buf[oob_size] __attribute__((__aligned__(4)));

	this->active_chip=chipnr=0;		
	page = ((int) ofs) >> this->page_shift;
	page_offset = page & (ppb-1);
	block = page/ppb;
	if ( isLastPage ){
		page = block*ppb + (ppb-1);	
		if ( this->read_oob (mtd, chipnr, page, oob_size, buf) ){
			printk ("%s: read_oob page=%d failed\n", __FUNCTION__, page);
			return 1;
		}
		block_status_p1 = buf[0];
#if Nand_Block_Isbad_Slow_Version
		page = block*ppb + (ppb-2);	
		if ( this->read_oob (mtd, chipnr, page, oob_size, buf) ){
			printk ("%s: read_oob page=%d failed\n", __FUNCTION__, page);
			return 1;
		}
		block_status_p2 = buf[0];
		debug_nand("[1]block_status_p1=0x%x, block_status_p2=0x%x\n", block_status_p1, block_status_p2);
#endif		
	}else{	
		if ( this->read_oob (mtd, chipnr, page, oob_size, buf) ){
			printk ("%s: read_oob page=%d failed\n", __FUNCTION__, page);
			return 1;
		}
		block_status_p1 = buf[0];
#if Nand_Block_Isbad_Slow_Version
		if ( this->read_oob (mtd, chipnr, page+1, oob_size, buf) ){
			printk ("%s: read_oob page+1=%d failed\n", __FUNCTION__, page+1);
			return 1;
		}
		block_status_p2 = buf[0];
		debug_nand("[2]block_status_p1=0x%x, block_status_p2=0x%x\n", block_status_p1, block_status_p2);
#endif
	}

	if(block < (g_BootcodeSize/mtd->erasesize)){
		if (( block_status_p1 != 0xff)&&( block_status_p1 != 0x23)&&( block_status_p1 != 0x79)&&( block_status_p1 != 0x80) \
			&&( block_status_p1 != 0xd0)&&( block_status_p1 != 0xbb)&&( block_status_p1 != 0x11)&&( block_status_p1 != 0x51) \
			&&( block_status_p1 != 0x78)&&( block_status_p1 != 0x50)&&( block_status_p1 != 0x22)&&( block_status_p1 != 0x7a)){
			printk ("WARNING: Die %d: block=%d is bad, block_status_p1=0x%x\n", chipnr, block, block_status_p1);
			return -1;
		}
	}else{
#if Nand_Block_Isbad_Slow_Version
		if ( (block_status_p1 != 0xff) && (block_status_p2 != 0xff) ){
#else
		if ( block_status_p1 != 0xff){
#endif		
			printk ("WARNING: Die %d: block=%d is bad, block_status_p1=0x%x\n", chipnr, block, block_status_p1);
			return -1;
		}

	}
	return 0;
}


static int nand_block_isbad (struct mtd_info *mtd, loff_t ofs)
{
	return 0;
}

void mark_as_badblock(struct mtd_info *rtk_mtd,int block_id)
{	
	struct nand_chip *this = (struct nand_chip *)rtk_mtd->priv; 
	memset(this->g_oobbuf, 0xff, oob_size); 
	this->g_oobbuf[0] = 0x00;	
	if (isLastPage ){		
		this->write_oob(rtk_mtd, 0, block_id*ppb+ppb-1, oob_size, this->g_oobbuf);		
		this->write_oob(rtk_mtd, 0, block_id*ppb+ppb-2, oob_size, this->g_oobbuf);	
	}else{		
		this->write_oob(rtk_mtd, 0, block_id*ppb,	oob_size, this->g_oobbuf);		
		this->write_oob(rtk_mtd, 0, block_id*ppb+1, oob_size, this->g_oobbuf);	
	}
}


#ifndef CONFIG_MTD_NAND_RBT
static int nand_block_markbad (struct mtd_info *mtd, loff_t ofs)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	

	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	unsigned int page, block, page_offset;
	int i;
	int rc = 0;
	unsigned char buf[oob_size] __attribute__((__aligned__(4)));
	int chipnr, chipnr_remap;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	
	page = ((int) ofs) >> this->page_shift;
	this->active_chip = chipnr = chipnr_remap = (int)(ofs >> this->chip_shift);
	page_offset = page & (ppb-1);
	block = page/ppb;

	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);

	while (down_interruptible (&sem_bbt)) {
		printk("%s : Retry\n",__FUNCTION__);
		if(retryCnt<=0)
		{
			printk("%s : BBT Retry fail!\n",__FUNCTION__);
			return -ERESTARTSYS;
		}
		retryCnt--;
	}
#ifdef CONFIG_MTD_NAND_IBT
	//search ibt
	if(this->use_ibt){
		if(((this->ibt[block].src_block ==	SRC_INIT)&&(this->ibt[block].dst_block ==  DST_INIT)) ||(this->ibt[block].dst_block== block)){
			#ifdef _DEBUG_IBT
			printk(" [%s][block no = 0x%x]ibt  ...\n",__FUNCTION__,block);
			#endif
		}else if(this->ibt[block].dst_block != block){
			block = this->ibt[block].dst_block;
			#ifdef _DEBUG_IBT
			printk(" [%s][block no = 0x%x]ibt search...\n", __FUNCTION__,block);
			#endif
		}
	}
#endif
	
	for ( i=0; i<RBA; i++){
		if ( this->bbt[i].bad_block != BB_INIT ){
			if ( chipnr == this->bbt[i].BB_die && block == this->bbt[i].bad_block ){
				block = this->bbt[i].remap_block;
				if ( this->bbt[i].BB_die != this->bbt[i].RB_die ){
					this->active_chip = chipnr_remap = this->bbt[i].RB_die;
					this->select_chip(mtd, chipnr_remap);
				}					
			}
		}else
			break;
	}
	up (&sem_bbt);
	
	page = block*ppb + page_offset;
				
	buf[0]=0x00;
	rc = this->write_oob (mtd, this->active_chip, page, oob_size, buf);
	if (rc) {
			DEBUG (MTD_DEBUG_LEVEL0, "%s: write_oob failed\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif	
			return -1;
	}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	

	return 0;
}
#else
static int nand_block_markbad (struct mtd_info *mtd, loff_t ofs)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif
	struct nand_chip *this = mtd->priv;
	unsigned int page = 0,block = 0, page_offset = 0,retryCnt = 0;
	int rc = 0, chipnr = 0,chipnr_remap = 0,bad_block = 0;

	page = ((int) ofs) >> this->page_shift;
	this->active_chip = chipnr = chipnr_remap = (int)(ofs >> this->chip_shift);
	page_offset = page & (this->ppb-1);
	block = page/this->ppb;

	this->active_chip=chipnr=chipnr_remap=0;
	this->select_chip(mtd, chipnr);

	printk("INIT(block0x%x)....", block);
	while (down_interruptible (&sem_bbt)) {
		printk("%s : Retry\n",__FUNCTION__);
		if(retryCnt<=0){
			printk("%s : BBT Retry fail!\n",__FUNCTION__);
			rc = -ERESTARTSYS;
			goto end;
		}
		retryCnt--;
	}
	/*get phy block*/
	bad_block = get_phyblock(mtd,block);
	up (&sem_bbt); 
	printk("( bad block0x%x)....\n", block);
	mark_as_badblock(mtd, bad_block);
	
end:
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	
	return rc;
}

#endif

#ifndef CONFIG_MTD_NAND_RBT
//----------------------------------------------------------------------------------------------------
//add by alexchang 0928-2010

//----------------------------------------------------------------------------------------------------

static int nand_read_oob_ext (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, 
			u_char *oob_buf)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	

	struct nand_chip *this = mtd->priv;
	unsigned int page, realpage;
	int oob_len = 0, thislen;
	int rc=0;
	int old_page, page_offset, block;
	int chipnr, chipnr_remap;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	int i;
	int retry_count;

	if ((from + len) > mtd->size) {
		printk ("nand_read_oob: Attempt read beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -EINVAL;
	}


	if (NOTALIGNED (mtd, from)) {
		printk (KERN_NOTICE "nand_read_oob: Attempt to read not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -EINVAL;
	}

	realpage = (int)(from >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(from >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	block = page/ppb;
	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);

	
	if ( retlen ) 
		*retlen = 0;
	thislen = oob_size;

	while (oob_len < len) {
		if (thislen > (len - oob_len)) 
			thislen = (len - oob_len);

		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				return -ERESTARTSYS;
			}
			retryCnt--;
		}
#ifdef CONFIG_MTD_NAND_IBT
		//search ibt
		if(this->use_ibt){
			if(((this->ibt[block].src_block ==	SRC_INIT)&&(this->ibt[block].dst_block ==  DST_INIT)) ||(this->ibt[block].dst_block== block)){
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt  ...\n",__FUNCTION__,block);
				#endif
			}else if(this->ibt[block].dst_block != block){
				block = this->ibt[block].dst_block;
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt search...\n", __FUNCTION__,block);
				#endif
			}
		}
#endif
		for ( i=0; i<RBA; i++){
			if ( this->bbt[i].bad_block != BB_INIT ){
				if ( this->active_chip == this->bbt[i].BB_die && block == this->bbt[i].bad_block ){
					block = this->bbt[i].remap_block;
					if ( this->bbt[i].BB_die != this->bbt[i].RB_die ){
						this->active_chip = chipnr_remap = this->bbt[i].RB_die;
						this->select_chip(mtd, chipnr_remap);
					}					
				}
			}else
				break;
		}
		up (&sem_bbt);
		page = block*ppb + page_offset;
		for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++){
			rc = this->read_oob (mtd, this->active_chip, page, thislen, &oob_buf[oob_len]);
			if(rc >= 0)
				break;			
		}
		if (rc < 0) {
			if (rc == -1){
				printk ("%s: read_oob: Un-correctable HW ECC\n", __FUNCTION__);
				if(check_BBT(mtd,page/ppb)==0)
				{
				while (down_interruptible (&sem_bbt)) {
					printk("%s : Retry\n",__FUNCTION__);
					if(retryCnt<=0)
					{
						printk("%s : BBT Retry fail!\n",__FUNCTION__);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
				for( i=0; i<RBA; i++){
					if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
						if ( chipnr != chipnr_remap)	//remap block is bad
							this->bbt[i].BB_die = chipnr_remap;
						else
							this->bbt[i].BB_die = chipnr;
						this->bbt[i].bad_block = page/ppb;
						break;
					}
				}
				up (&sem_bbt);
				dump_BBT(mtd);
				
				if ( rtk_update_bbt (mtd, this->g_databuf, this->g_oobbuf, this->bbt) ){
					printk("[%s] rtk_update_bbt() fails\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif	
					return -1;
					}
				}
				
				this->g_oobbuf[0] = 0x00;
				if ( isLastPage ){
					this->erase_block (mtd, this->active_chip, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-1, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-2, oob_size, this->g_oobbuf);
				}else{
					this->erase_block (mtd, this->active_chip, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+1, oob_size, this->g_oobbuf);
				}
				printk("rtk_read_oob: Un-correctable HW ECC Error at page=%d\n", page);				
			}else{
				printk ("%s: rtk_read_oob: semphore failed\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif	
				return -1;
			}
		}

		if(this->ecc_err_flag){
			rtk_badblock_remap(mtd,this->active_chip,page);
		}
		
		oob_len += thislen;

		old_page++;
		page_offset = old_page & (ppb-1);
		if ( oob_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}

	if ( retlen ){
		if ( oob_len == len )
			*retlen = oob_len;
		else{
			printk("[%s] error: oob_len %d != len %d\n", __FUNCTION__, oob_len, len);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif	
			return -1;
		}	
	}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	
	return 0;
}
#else
static int nand_read_oob_ext (struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen, 
			u_char *oob_buf)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	

	struct nand_chip *this = mtd->priv;
	unsigned int page, realpage;
	int rc=0,oob_len = 0, thislen = 0,old_page =0,retry_count = 0;
	int page_offset = 0, block = 0,i =0,chipnr=0, chipnr_remap=0,phy_block = 0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;

	if ((from + len) > mtd->size) {
		printk ("nand_read_oob: Attempt read beyond end of device\n");
		*retlen = 0;
		rc = -EINVAL;
		goto end;
	}

	if (NOTALIGNED (mtd, from)) {
		printk (KERN_NOTICE "nand_read_oob: Attempt to read not page aligned data\n");
		rc = -EINVAL;
		goto end;
	}

	realpage = (int)(from >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(from >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (this->ppb-1);
	block = page/this->ppb;
	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);

	
	if ( retlen ) 
		*retlen = 0;
	thislen = this->oob_size;

	while (oob_len < len) {
		if (thislen > (len - oob_len)) 
			thislen = (len - oob_len);

		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0){
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				rc = -ERESTARTSYS;
				goto end;
			}
			retryCnt--;
		}
		/*get phy block*/
		phy_block = get_phyblock(mtd,block);
		up (&sem_bbt);
		page = phy_block*this->ppb + page_offset;
		for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++){
			rc = this->read_oob (mtd, this->active_chip, page, thislen, &oob_buf[oob_len]);
			if(rc >= 0)
				break;			
		}
		if (rc < 0) {
			if (rc == -1){
				printk("rtk_read_oob: Un-correctable HW ECC Error at page=%d\n", page); 	
				break;		
			}else{
				printk ("%s: rtk_read_oob: semphore failed\n", __FUNCTION__);
				break;
			}
		}
				
		oob_len += thislen;
		old_page++;
		page_offset = old_page & (this->ppb-1);
		if ( oob_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/this->ppb;
	}

	if ( retlen ){
		if ( oob_len == len )
			*retlen = oob_len;
		else{
			printk("[%s] error: oob_len %d != len %d\n", __FUNCTION__, oob_len, len);
			rc =  -1;
		}	
	}
end:
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	
	return rc;
}

#endif

static int nand_read (struct mtd_info *mtd, loff_t from, size_t len, size_t * retlen, u_char * buf)
{
	int rc=0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	if(g_isSysSecure||g_isRandomize)
  {
			  while (down_interruptible (&sem_rd)) {
				printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,(unsigned int)from);
				if(retryCnt<=0)
				{
					printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,(unsigned int)from);
					return -ERESTARTSYS;
				}
				retryCnt--;
			}
        if(g_isRandomize)
			mtd->isCPdisable_R = 0;
		if(g_isSysSecure)
		{
			if(*retlen == NAND_CP_RW_DISABLE)
				mtd->isCPdisable_R = 1;
			else
				mtd->isCPdisable_R = 0;
		}
//		if(g_isRandomize)
//		{
//			//mtd->isScramble= 1;
//			mtd->isCPdisable_R = 0;
//		}
	}
	//printk("[%s]scramble 0x%x\n",__FUNCTION__,mtd->isScramble);

	//printk("[%s] mtd->oobblock =%u\n", __FUNCTION__, mtd->oobblock);
	rc = nand_read_ecc (mtd, from, len, retlen, buf, NULL, NULL);
	if(g_isSysSecure||g_isRandomize)
        {
		//printk("[%s] done \n",__FUNCTION__);
		//mtd->isScramble= 0;
		up (&sem_rd);
	}

	return rc;
}                          

static int nand_read_oob (struct mtd_info *mtd, loff_t from, struct mtd_oob_ops *ops)
{
	int rc = 0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;

	if(g_isSysSecure||g_isRandomize)
	{
        while (down_interruptible (&sem_rd)) {
				printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,(unsigned int)from);
				if(retryCnt<=0)
				{
					printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,(unsigned int)from);
					return -ERESTARTSYS;
				}
				retryCnt--;
			}
        if(g_isRandomize)
        {
			//mtd->isScramble = 1;
			mtd->isCPdisable_R = 0;
        }
		else
			mtd->isCPdisable_R = 1;//Add by alexchang for disable yaffs cp read. 0614-2011
		
	}

	mtd->oobinfo.useecc = ops->mode;
	//printk("[%s]scramble 0x%x\n",__FUNCTION__,mtd->isScramble);
	if(ops->len==ops->ooblen)// read oob 
		 rc = nand_read_oob_ext(mtd, from, ops->len, &ops->retlen,ops->oobbuf);
	else
	{
		
		 rc = nand_read_ecc(mtd, from, ops->len, &ops->retlen,ops->datbuf, ops->oobbuf, NULL);
	}
	
	if(g_isSysSecure||g_isRandomize)
        {
//		printk("[%s] done \n",__FUNCTION__);
		//mtd->isScramble= 0;

		up (&sem_rd);
	}

	return rc;
}   

#ifndef CONFIG_MTD_NAND_RBT
static int nand_read_ecc (struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, u_char *buf, u_char *oob_buf, struct nand_oobinfo *oobsel)
{
	//printk("[%s] mtd->oobblock =0x%x,len =0x%x, from 0x%x\n", __FUNCTION__, mtd->oobblock,len,from);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this = mtd->priv;
	unsigned long long  page, realpage,page_ppb;
	int data_len, oob_len;
	int rc;
	unsigned int old_page, page_offset, block;
	int chipnr, chipnr_remap;
	int i;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	int tmp_isCPdisable_R = mtd->isCPdisable_R;
	int retry_count;

	if ((from + len) > mtd->size) {
		printk ("nand_read_ecc: Attempt read beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}
	//printk("[%s] NOTALIGNED (mtd, from) 0x%x, NOTALIGNED(mtd, len)0x%x\n",__FUNCTION__,NOTALIGNED (mtd, from),NOTALIGNED(mtd, len));

	if (NOTALIGNED (mtd, from) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_read_ecc: Attempt to read not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}

	realpage = (int)(from >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(from >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	//block = page/ppb;
	page_ppb = page;
	do_div(page_ppb,ppb);
	block = (unsigned int)page_ppb;
	//printk("\t\tReady to READ blk:%u, page:%u, len:%u, page_size:%d, oob_size:%d\n",page/ppb,page%ppb,len,page_size,oob_size);

	this->active_chip=chipnr=chipnr_remap=0;		

	if(oobsel)
	{	
		if (oobsel->useecc==MTD_ECC_RTK_HW )
		{
			mtd->ecctype = MTD_ECC_RTK_HW;
		}	
		else
			mtd->ecctype = MTD_ECC_NONE;
	}	
	else
		mtd->ecctype = mtd->oobinfo.useecc;
	
	this->select_chip(mtd, chipnr);
	
	if ( retlen )
		*retlen = 0;
	
	data_len = oob_len = 0;

	while (data_len < len) {
		
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				return -ERESTARTSYS;
			}
			retryCnt--;
		}

#ifdef CONFIG_MTD_NAND_IBT
		//search ibt
		if(this->use_ibt){
			if(((this->ibt[block].src_block ==	SRC_INIT)&&(this->ibt[block].dst_block ==  DST_INIT)) ||(this->ibt[block].dst_block== block)){
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt  ...\n",__FUNCTION__,block);
				#endif
			}else if(this->ibt[block].dst_block != block){
				block = this->ibt[block].dst_block;
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt search...\n", __FUNCTION__,block);
				#endif
			}
		}
#endif

		for ( i=0; i<RBA; i++){
			if ( this->bbt[i].bad_block != BB_INIT ){
				if ( this->active_chip == this->bbt[i].BB_die && block == this->bbt[i].bad_block ){
					block = this->bbt[i].remap_block;
					if ( this->bbt[i].BB_die != this->bbt[i].RB_die ){
						this->active_chip = chipnr_remap = this->bbt[i].RB_die;
						this->select_chip(mtd, chipnr_remap);
					}
				}
			}else
				break;
		}
        	up (&sem_bbt);

		page = block*ppb + page_offset;  
		
		//printk("\t\tConfirm to READ blk:%u, page:%u\n",block,page_offset);
		mtd->isCPdisable_R =tmp_isCPdisable_R;
		for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++){
			rc = this->read_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len]);
			if(rc >= 0)
				break;			
		}
		if (rc < 0) {
			#if	NAND_POWEROFF_CARDREADER_WITH_MULTI_READ
			printk("[%s]Try again..\n",__FUNCTION__);
			NF_rtkcr_card_power(1);//power off card reader.
			rc = this->read_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len]);
			if(rc<0)
			{
			#if NAND_READ_SKIP_UPDATE_BBT
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif			
				return -1;
			#endif
			}
			#endif
			if (rc == -1){
				printk ("%s: read_ecc_page: Un-correctable HW ECC\n", __FUNCTION__);
				
				//update BBT
				#ifdef CONFIG_MTD_NAND_IBT
				if(this->use_ibt)
					page_ppb = block;
				#endif
				
				if(check_BBT(mtd,page_ppb)==0)
				{
				while (down_interruptible (&sem_bbt)) {
					printk("%s : Retry\n",__FUNCTION__);
					if(retryCnt<=0)
					{
						printk("%s : BBT Retry fail!\n",__FUNCTION__);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
				for( i=0; i<RBA; i++){
					if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
						if ( chipnr != chipnr_remap)	//remap block is bad
							this->bbt[i].BB_die = chipnr_remap;
						else
							this->bbt[i].BB_die = chipnr;
						this->bbt[i].bad_block = page_ppb;
						break;
					}
				}
				up (&sem_bbt);
				dump_BBT(mtd);
				
				if ( rtk_update_bbt (mtd, this->g_databuf, this->g_oobbuf, this->bbt) ){
					printk("[%s] rtk_update_bbt() fails\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
					}
				}
				
				this->g_oobbuf[0] = 0x00;
				block = page_ppb;
				if ( isLastPage){
					this->erase_block (mtd, this->active_chip, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-1, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-2, oob_size, this->g_oobbuf);
				}else{
					this->erase_block (mtd, this->active_chip, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+1, oob_size, this->g_oobbuf);
				}
				printk("rtk_read_ecc_page: Un-correctable HW ECC Error at page=0x%llx\n", page);
			}else{
				printk ("%s: read_ecc_page:  semphore failed\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
			}
		}
		
		if(this->ecc_err_flag){
			rtk_badblock_remap(mtd,this->active_chip,page);
		}		
		
		data_len += page_size;

		if(oob_buf)
			oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}

	if ( retlen ){
		if ( data_len == len )
			*retlen = data_len;
		else{
				printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif	
				return -1;
		}	
	}

#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif

	return 0;
}

#else
static int nand_read_ecc (struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, u_char *buf, u_char *oob_buf, struct nand_oobinfo *oobsel)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this = mtd->priv;
	unsigned long long	page = 0, realpage = 0,page_ppb = 0;
	int data_len = 0, oob_len = 0,rc = 0,retry_count = 0;
	int i = 0, chipnr = 0, chipnr_remap = 0,tmp_isCPdisable_R = mtd->isCPdisable_R;
	unsigned int old_page = 0, page_offset = 0, block = 0,phy_block = 0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;


	if ((from + len) > mtd->size) {
		printk ("nand_read_ecc: Attempt read beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}
	//printk("[%s] NOTALIGNED (mtd, from) 0x%x, NOTALIGNED(mtd, len)0x%x\n",__FUNCTION__,NOTALIGNED (mtd, from),NOTALIGNED(mtd, len));

	if (NOTALIGNED (mtd, from) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_read_ecc: Attempt to read not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}

	realpage = (int)(from >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(from >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (this->ppb-1);
	//block = page/ppb;
	page_ppb = page;
	do_div(page_ppb,this->ppb);
	block = (unsigned int)page_ppb;
	//printk("Ready to READ blk:%u, page:%u, len:%u\n",page/ppb,page%ppb,len);

	this->active_chip=chipnr=chipnr_remap=0;		

	if(oobsel)
	{	
		if(oobsel->useecc==MTD_ECC_RTK_HW ){
			mtd->ecctype = MTD_ECC_RTK_HW;
		}else{
			mtd->ecctype = MTD_ECC_NONE;
		}
	}else{
		mtd->ecctype = mtd->oobinfo.useecc;
	}
	
	this->select_chip(mtd, chipnr);
	
	if (retlen)
		*retlen = 0;
	
	while (data_len < len) {
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				rc = -ERESTARTSYS;
				goto end;
			}
			retryCnt--;
		}
		
		/*get phy block*/
		phy_block = get_phyblock(mtd,block);
		up (&sem_bbt);
		page = phy_block*this->ppb + page_offset;
		
		//printk("%s len 0x%x data_len 0x%x READ blk:%u, page_offset %d page:%u\n",
		//	__FUNCTION__,len,data_len,block,page_offset,page);
		mtd->isCPdisable_R =tmp_isCPdisable_R;
		for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++){
			rc = this->read_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len]);
			if(rc >= 0)
				break;			
		}
		if (rc < 0) {
			#if NAND_POWEROFF_CARDREADER_WITH_MULTI_READ
			printk("[%s]Try again..\n",__FUNCTION__);
			NF_rtkcr_card_power(1);//power off card reader.
			rc = this->read_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len]);
			if(rc<0){
			#if NAND_READ_SKIP_UPDATE_BBT
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif			
				return -1;
			#endif
			}
			#endif
			if (rc == -1){
				printk ("%s: read_ecc_page: Un-correctable HW ECC page %d \n", __FUNCTION__,page);
                goto end;
			}
		}
		
		if(this->ecc_err_flag){
			printk ("%s: Enter page %u phy_block %d log block %d \n", __FUNCTION__,page,phy_block,block);
			while (down_interruptible (&sem_bbt)) {
				printk("%s : Retry\n",__FUNCTION__);
				if(retryCnt<=0)
				{
					printk("%s : BBT Retry fail!\n",__FUNCTION__);
					rc = -ERESTARTSYS;
					goto end;
				}
				retryCnt--;
			}
			remap_read_block_content(mtd,block, page);
			up (&sem_bbt);
		}		
		
		data_len += page_size;
		if(oob_buf)
			oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
		//printk("%s data_len 0x%x len 0x%x \n",__FUNCTION__,data_len,len);
	}

	if ( retlen ){
		if ( data_len == len )
			*retlen = data_len;
		else{
			printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
            rc = -1; 
		}	
	}

end:
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif

	return rc;
}

#endif

#ifndef CONFIG_MTD_NAND_RBT
//panic_nand_write without oobbuf.
static int panic_nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, 
			const u_char * buf)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	

	struct nand_chip *this = mtd->priv;
	unsigned int page, realpage;
	int data_len, oob_len;
	int rc;
	int i, old_page, page_offset, block;
	int chipnr, chipnr_remap, err_chipnr = 0, err_chipnr_remap = 1;
	int backup_offset;
	int block_remap=0x12345678;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	int tmp_isCPdisable_W = mtd->isCPdisable_W;
	
	if ((to + len) > mtd->size) {
		printk ("nand_write_ecc: Attempt write beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -EINVAL;
	}
	if (NOTALIGNED (mtd, to) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_write_ecc: Attempt to write not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -EINVAL;
	}

	realpage = (int)(to >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(to >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	block = page/ppb;

	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);
	
	if ( retlen )
		*retlen = 0;
	
	data_len = oob_len = 0;

	while ( data_len < len) {
		
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				return -ERESTARTSYS;
			}
			retryCnt--;
		}
		
#ifdef CONFIG_MTD_NAND_IBT
		//search ibt
		if(this->use_ibt){
			if(((this->ibt[block].src_block ==	SRC_INIT)&&(this->ibt[block].dst_block ==  DST_INIT)) ||(this->ibt[block].dst_block== block)){
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt  ...\n",__FUNCTION__,block);
				#endif
			}else if(this->ibt[block].dst_block != block){
				block = this->ibt[block].dst_block;
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt search...\n", __FUNCTION__,block);
				#endif
			}
		}
#endif
		for ( i=0; i<RBA; i++){
			if ( this->bbt[i].bad_block != BB_INIT ){
				if ( this->active_chip == this->bbt[i].BB_die && block == this->bbt[i].bad_block ){
					block = this->bbt[i].remap_block;
					if ( this->bbt[i].BB_die != this->bbt[i].RB_die ){
						this->active_chip = chipnr_remap = this->bbt[i].RB_die;
						this->select_chip(mtd, chipnr_remap);
					}
				}
			}else
				break;
		}
		up (&sem_bbt);

		page = block*ppb + page_offset;
		//printk("Confirm to write blk:%u, page:%u\n",page/ppb,page%ppb);
		mtd->isCPdisable_W= tmp_isCPdisable_W;
		rc = this->write_ecc_page (mtd, this->active_chip, page, &buf[data_len], NULL, 0);
		if (rc < 0) {
			if ( rc == -1){
				//printk ("%s: write_ecc_page:  write blk:%u, page:%u failed\n", __FUNCTION__,page/ppb,page%ppb);

			if(check_BBT(mtd,page/ppb)==0)
			{
				while (down_interruptible (&sem_bbt)) {
					printk("%s : Retry\n",__FUNCTION__);
					if(retryCnt<=0)
					{
						printk("%s : BBT Retry fail!\n",__FUNCTION__);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
				/* update BBT */
				for( i=0; i<RBA; i++){
					if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
						if ( chipnr != chipnr_remap)	//remap block is bad
							err_chipnr = chipnr_remap;
						else
							err_chipnr = chipnr;
						this->bbt[i].BB_die = err_chipnr;
						this->bbt[i].bad_block = page/ppb;
						err_chipnr_remap = this->bbt[i].RB_die;
						block_remap = this->bbt[i].remap_block;
						break;
					}
				}
				up (&sem_bbt);
				if ( block_remap == 0x12345678 ){
					printk("[%s] RBA do not have free remap block\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif	

					return -1;
				}
			}
			
				dump_BBT(mtd);
			
				if ( rtk_update_bbt (mtd, this->g_databuf, this->g_oobbuf, this->bbt) ){
					printk("[%s] rtk_update_bbt() fails\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif	
					return -1;
				}

				backup_offset = page&(ppb-1);
				this->select_chip(mtd, err_chipnr_remap);
				this->erase_block (mtd, err_chipnr_remap, block_remap*ppb);
			
				if ( err_chipnr != err_chipnr_remap ){
					this->active_chip = err_chipnr;
					this->select_chip(mtd, err_chipnr);
				}

				this->g_oobbuf[0] = 0x00;
				block = page/ppb;
				if ( isLastPage ){
					this->erase_block (mtd, err_chipnr, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-1, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-2, oob_size, this->g_oobbuf);
				}else{
					this->erase_block (mtd, err_chipnr, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb, oob_size, this->g_oobbuf);	
					this->write_oob(mtd, this->active_chip, block*ppb+1, oob_size, this->g_oobbuf);
				}
			}else{
				printk ("%s: write_ecc_page:  rc=%d\n", __FUNCTION__, rc);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif	
				return -1;
			}	
		}
		data_len += page_size;
		oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}

	if ( retlen ){
		
		if ( data_len == len )
			*retlen = data_len;
		else{
			printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif	
			return -1;
		}	
	}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
	return 0;
}

#else
static int panic_nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, 
			const u_char * buf)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	

	struct nand_chip *this = mtd->priv;
	unsigned int page = 0, realpage = 0,retryCnt = MTD_SEM_RETRY_COUNT;
	int data_len = 0, oob_len = 0;
	int rc = 0,i= 0, old_page= 0, page_offset= 0, block = 0,phy_block = 0;
	int chipnr= 0, chipnr_remap= 0, err_chipnr = 0;
	int tmp_isCPdisable_W = mtd->isCPdisable_W;
	
	if ((to + len) > mtd->size) {
		printk ("nand_write_ecc: Attempt write beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -EINVAL;
	}
	if (NOTALIGNED (mtd, to) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_write_ecc: Attempt to write not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -EINVAL;
	}

	realpage = (int)(to >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(to >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	block = page/ppb;

	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);
	
	if ( retlen )
		*retlen = 0;
	
	data_len = oob_len = 0;

	while ( data_len < len) {
		
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				rc = -ERESTARTSYS;
				goto end;
			}
			retryCnt--;
		}
		/*get phy block*/
		phy_block = get_phyblock(mtd,block);
		up (&sem_bbt);

		page = phy_block*ppb + page_offset;
		//printk("Confirm to write blk:%u, page:%u\n",page/ppb,page%ppb);
		mtd->isCPdisable_W= tmp_isCPdisable_W;
		rc = this->write_ecc_page (mtd, this->active_chip, page, &buf[data_len], NULL, 0);
		if (rc < 0) {
			while (down_interruptible (&sem_bbt)) {
				printk("%s : Retry\n",__FUNCTION__);
				if(retryCnt<=0){
					printk("%s : BBT Retry fail!\n",__FUNCTION__);
					rc = -ERESTARTSYS;
					goto end;
				}
				retryCnt--;
			}
			if((rc = remap_write_block_content(mtd,block,page,buf)) < 0){
				up (&sem_bbt);
				rc = -1;
				goto end;
			}
			up (&sem_bbt);
		}
		data_len += page_size;
		oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}

	if ( retlen ){
		if ( data_len == len )
			*retlen = data_len;
		else{
			printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
			rc = -1;
		}	
	}
	
end:
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
	return rc;
}

#endif
static int nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
	int rc = 0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	if(g_isSysSecure||g_isRandomize)
        {
				while (down_interruptible (&sem_wte)) {
					printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,(unsigned int)to);
					if(retryCnt<=0)
					{
						printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,(unsigned int)to);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
		
		
		if(g_isRandomize)
		{
			//mtd->isScramble = 1;
			mtd->isCPdisable_W = 0;
		}
		else
			mtd->isCPdisable_W = 1;//Add by alexchang for disable yaffs cp read. 0614-2011
		//printk("[%s]Set mtd->isCPdisable_W --> 0 ",__FUNCTION__);
		//printk("[%s]Scrabmle flag 0x%x\n",__FUNCTION__,mtd->isScramble);
	}
	else
		mtd->isCPdisable_W = 1;
	rc = (nand_write_ecc (mtd, to, len, retlen, buf, NULL, NULL));

	if(g_isSysSecure||g_isRandomize)
        {
		//printk("[%s] done\n",__FUNCTION__);
		//mtd->isScramble= 0;
		up (&sem_wte);
	}	
	return rc;
}

static int nand_write_oob (struct mtd_info *mtd, loff_t to, struct mtd_oob_ops *ops)//for 2.6.34 YAFFS-->mtd
{
	int rc = 0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	if(g_isSysSecure||g_isRandomize)
        {
				while (down_interruptible (&sem_wte)) {
					printk("%s : Retry [Address: 0x%x]\n",__FUNCTION__,(unsigned int)to);
					if(retryCnt<=0)
					{
						printk("%s : Retry fail [ADDR 0x%x]\n",__FUNCTION__,(unsigned int)to);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
		if(g_isRandomize)
		{
			//mtd->isScramble = 1;
			mtd->isCPdisable_W = 0;
		}
		else
			mtd->isCPdisable_W = 1;//Add by alexchang for disable yaffs cp read. 0614-2011
		//printk("[%s]Set mtd->isCPdisable_W --> 1 ",__FUNCTION__);
		//printk("[%s]Scrabmle flag 0x%x\n",__FUNCTION__,mtd->isScramble);
	}
	rc =  nand_write_ecc (mtd, to, ops->len, &ops->retlen,ops->datbuf, ops->oobbuf, NULL);
	if(g_isSysSecure||g_isRandomize)
        {
		//	mtd->isScramble= 0;
		//printk("[%s] done\n",__FUNCTION__);
		up (&sem_wte);
	}
	return rc;
}                          

#ifndef CONFIG_MTD_NAND_RBT
static int nand_write_ecc (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, 
			const u_char * buf, const u_char *oob_buf, struct nand_oobinfo *oobsel)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this = mtd->priv;
	unsigned long long page, realpage,page_ppb;
	int data_len, oob_len;
	int rc;
	unsigned int i, old_page, page_offset, block;
	int chipnr, chipnr_remap, err_chipnr = 0, err_chipnr_remap = 1;
	int backup_offset;
	int block_remap=0x12345678;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	int tmp_isCPdisable_W = mtd->isCPdisable_W;
	
	if ((to + len) > mtd->size) {
		printk ("nand_write_ecc: Attempt write beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}

	if (NOTALIGNED (mtd, to) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_write_ecc: Attempt to write not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}

	realpage = (unsigned long long)(to >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(to >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	//block = page/ppb;
	page_ppb = page;
	do_div(page_ppb,ppb);
	block = (unsigned int)page_ppb;

	if(g_sw_WP_level > 0)
	{
		if(!g_disNFWP)
		{
			if(check_SW_WP(mtd)==-1)
			{
				if(page >= (g_BootcodeSize+g_Factory_param_size)/page_size+ppb) 				
				{
					printk("[%s]Permission denied!!!\n",__FUNCTION__);
					g_disNFWP=0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
				}
			}
		}
	}
	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);
	
	if ( retlen )
		*retlen = 0;
	
	data_len = oob_len = 0;

	while ( data_len < len) {
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				return -ERESTARTSYS;
			}
			retryCnt--;
		}
		
#ifdef CONFIG_MTD_NAND_IBT
		//search ibt
		if(this->use_ibt){
			if(((this->ibt[block].src_block ==	SRC_INIT)&&(this->ibt[block].dst_block ==  DST_INIT)) ||(this->ibt[block].dst_block== block)){
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt  ...\n",__FUNCTION__,block);
				#endif
			}else if(this->ibt[block].dst_block != block){
				block = this->ibt[block].dst_block;
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt search...\n", __FUNCTION__,block);
				#endif
			}
		}
#endif
		for ( i=0; i<RBA; i++){
			if ( this->bbt[i].bad_block != BB_INIT ){
				if ( this->active_chip == this->bbt[i].BB_die && block == this->bbt[i].bad_block ){
					block = this->bbt[i].remap_block;
					if ( this->bbt[i].BB_die != this->bbt[i].RB_die ){
						this->active_chip = chipnr_remap = this->bbt[i].RB_die;
						this->select_chip(mtd, chipnr_remap);
					}
				}
			}else
				break;
		}
		up (&sem_bbt);

		page = block*ppb + page_offset;

		mtd->isCPdisable_W= tmp_isCPdisable_W;
		if(oob_buf)
			rc = this->write_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len], 0);
		else
			rc = this->write_ecc_page (mtd, this->active_chip, page, &buf[data_len], NULL, 0);
				
		if (rc < 0) {
			if ( rc == -1){

			#ifdef CONFIG_MTD_NAND_IBT
			if(this->use_ibt)
				page_ppb = block;
			#endif
			
			if(check_BBT(mtd,page_ppb)==0)
			{
				while (down_interruptible (&sem_bbt)) {
					printk("%s : Retry\n",__FUNCTION__);
					if(retryCnt<=0)
					{
						printk("%s : BBT Retry fail!\n",__FUNCTION__);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
				/* update BBT */
				for( i=0; i<RBA; i++){
					if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
						if ( chipnr != chipnr_remap)	//remap block is bad
							err_chipnr = chipnr_remap;
						else
							err_chipnr = chipnr;
						this->bbt[i].BB_die = err_chipnr;
						this->bbt[i].bad_block = page_ppb;
						err_chipnr_remap = this->bbt[i].RB_die;
						block_remap = this->bbt[i].remap_block;
						break;
					}
				}
				up (&sem_bbt);
				if ( block_remap == 0x12345678 ){
					printk("[%s] RBA do not have free remap block\n", __FUNCTION__);
					if(g_sw_WP_level > 0)
					{
						if(g_disNFWP)
								g_disNFWP=0;
					}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif						
					return -1;
				}
			}
			
				dump_BBT(mtd);
			
				if ( rtk_update_bbt (mtd, this->g_databuf, this->g_oobbuf, this->bbt) ){
					printk("[%s] rtk_update_bbt() fails\n", __FUNCTION__);
					if(g_sw_WP_level > 0)
					{
						if(g_disNFWP)
								g_disNFWP=0;
					}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif								
					return -1;
				}

				backup_offset = page&(ppb-1);
				this->select_chip(mtd, err_chipnr_remap);
				this->erase_block (mtd, err_chipnr_remap, block_remap*ppb);
#if 0
				printk("[%s] Start to Backup old_page from %d to %d\n", __FUNCTION__, block*ppb, block*ppb+backup_offset-1);

				for ( i=0; i<backup_offset; i++){
					if ( err_chipnr != err_chipnr_remap ){
						this->active_chip = err_chipnr;
						this->select_chip(mtd, err_chipnr);
					}
					this->read_ecc_page(mtd, this->active_chip, (page/ppb)*ppb+i, this->g_databuf, this->g_oobbuf);
					if ( this->g_oobbuf )
						reverse_to_Yaffs2Tags(this->g_oobbuf);
					if ( err_chipnr != err_chipnr_remap ){
						this->active_chip = err_chipnr_remap;
						this->select_chip(mtd, err_chipnr_remap);
					}
					this->write_ecc_page(mtd, this->active_chip, block_remap*ppb+i, this->g_databuf, this->g_oobbuf, 0);
				}
				this->write_ecc_page (mtd, this->active_chip, block_remap*ppb+backup_offset, &buf[data_len], &oob_buf[oob_len], 0);
				printk("[%s] write failure page = %d to %d\n", __FUNCTION__, page, block_remap*ppb+backup_offset);
#endif			
				if ( err_chipnr != err_chipnr_remap ){
					this->active_chip = err_chipnr;
					this->select_chip(mtd, err_chipnr);
				}

				this->g_oobbuf[0] = 0x00;
				block = page_ppb;
				if ( isLastPage ){
					this->erase_block (mtd, err_chipnr, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-1, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-2, oob_size, this->g_oobbuf);
				}else{
					this->erase_block (mtd, err_chipnr, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb, oob_size, this->g_oobbuf);	
					this->write_oob(mtd, this->active_chip, block*ppb+1, oob_size, this->g_oobbuf);
				}
			}else{
				printk ("%s: write_ecc_page:  rc=%d\n", __FUNCTION__, rc);
				if(g_sw_WP_level > 0)
				{
					if(g_disNFWP)
							g_disNFWP=0;
				}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
			}	
		}
		//else
			//printk("Confirm to write blk:%u, page:%u Succeed!!\n",page/ppb,page%ppb);
		data_len += page_size;
		oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}
	if(g_sw_WP_level > 0)
	{
		if(g_disNFWP)
				g_disNFWP=0;
	}

	if ( retlen ){
		
		if ( data_len == len )
			*retlen = data_len;
		else{
			printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif			
			return -1;
		}	
	}

#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	
	return 0;
}
#else
static int nand_write_ecc (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen,
			const u_char * buf, const u_char *oob_buf, struct nand_oobinfo *oobsel)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this = mtd->priv;
	unsigned long long page = 0, realpage = 0,page_ppb = 0;
	int rc = 0,data_len = 0, oob_len  = 0,chipnr = 0,chipnr_remap = 0,tmp_isCPdisable_W = mtd->isCPdisable_W;
	unsigned int i = 0, old_page = 0, page_offset = 0,block = 0,phy_block = 0,retryCnt = MTD_SEM_RETRY_COUNT;;

	if ((to + len) > mtd->size) {
		printk ("nand_write_ecc: Attempt write beyond end of device\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}
	
	if (NOTALIGNED (mtd, to) || NOTALIGNED(mtd, len)) {
		printk ("nand_write_ecc: Attempt to write not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}
	
	realpage = (unsigned long long)(to >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(to >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (this->ppb-1);
	//block = page/ppb;
	page_ppb = page;
	do_div(page_ppb,this->ppb);
	block = (unsigned int)page_ppb;

	if(g_sw_WP_level > 0)
	{
		if(!g_disNFWP)
		{
			if(check_SW_WP(mtd)==-1)
			{
				if(page >= (g_BootcodeSize+g_Factory_param_size)/page_size+ppb) 				
				{
					printk("[%s]Permission denied!!!\n",__FUNCTION__);
					g_disNFWP=0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
				}
			}
		}
	}
	this->active_chip=chipnr=chipnr_remap=0;
	this->select_chip(mtd, chipnr);

	if ( retlen )
		*retlen = 0;

	while ( data_len < len) {
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0){
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				rc = -ERESTARTSYS;
				goto end;
			}
			retryCnt--;
		}
		
		/*get phy block*/
		phy_block = get_phyblock(mtd,block);
		up (&sem_bbt);
		mtd->isCPdisable_W= tmp_isCPdisable_W;
		page = phy_block*ppb + page_offset;
		//printk("%s len 0x%x data_len 0x%x READ blk:%u, page_offset %d page:%u\n",
		//	__FUNCTION__,len,data_len,block,page_offset,page);

		if(oob_buf)
			rc = this->write_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len], 0);
		else
			rc = this->write_ecc_page (mtd, this->active_chip, page, &buf[data_len], NULL, 0);

		if (rc < 0) {
			while (down_interruptible (&sem_bbt)) {
				printk("%s : Retry\n",__FUNCTION__);
				if(retryCnt<=0){
					printk("%s : BBT Retry fail!\n",__FUNCTION__);
					rc = -ERESTARTSYS;
					goto end;
				}
				retryCnt--;
			}
			if((rc = remap_write_block_content(mtd,block,page,buf)) < 0){
				up (&sem_bbt);
				rc = -1;
				goto end;
			}
			up (&sem_bbt);
		}
		data_len += this->page_size;
		oob_len  += this->oob_size;

		old_page++;
		page_offset = old_page & (this->ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/this->ppb;
	}
	
	if ( retlen ){
		if ( data_len == len){
			*retlen = data_len;
		}else{
			printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len); 		
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif			
			rc = -1;
		}	
	}
	
	
end:
	if(g_sw_WP_level > 0){
		if(g_disNFWP)
				g_disNFWP=0;
	}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	
	return rc;
}

#endif

//------------------------------write / read / erase for bootcode--------------------------------------------------
static unsigned int rtk_access_range_get(loff_t to, size_t len)
{
	unsigned int access_range = 0;

	//access bootcode-area
	if((to+ len)<g_BootcodeSize)
		access_range = g_BootcodeSize;

	//access kcpu secure-store area
	if((to>=g_Secure_store_Start)&&((to +len)<(g_Secure_store_Start + g_Secure_store_Size)))
		access_range = g_Secure_store_Start + g_Secure_store_Size;

	printk("access_range = 0x%x \n", access_range);
	return access_range;

}
//write bootcode area, no bbt&ibt
static int nand_write_bootcode_area (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, 
			const u_char * buf, const u_char *oob_buf, unsigned char block_tag)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
	rtk_spin_lock();
#endif	
	struct nand_chip *this = mtd->priv;
	unsigned int page, realpage;
	int data_len, oob_len;
	int rc;
	int i, old_page, page_offset, block;
	int chipnr, chipnr_remap, err_chipnr = 0;
	unsigned int page_counter=0;
	unsigned int spare_value;

	if(block_tag == 0xff){
		//for kcpu secure store case
		if((to < g_Secure_store_Start) ||((to +len)>=(g_Secure_store_Start + g_Secure_store_Size))){
			printk ("nand_write_bootcode_area: Attempt write beyond end of kcpu secure-store area\n");
			*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif
			return -EINVAL;
		}
	}else{
		if ((to + len) > g_BootcodeSize) {
			printk ("nand_write_bootcode_area: Attempt write beyond end of bootcode area\n");
			*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif
			return -EINVAL;
		}
	}

	if (NOTALIGNED (mtd, to) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_write_bootcode_area: Attempt to write not page aligned data\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		return -EINVAL;
	}

	gp_access_range = rtk_access_range_get(to, len);
	if(gp_access_range == 0){
		printk("[%s][%d]get access range fail!\n",__FUNCTION__,__LINE__);
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE				
		rtk_spin_unlock();
#endif	
		return -1;
	}

	realpage = (int)(to >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(to >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	block = page/ppb;

	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);
	
	if ( retlen )
		*retlen = 0;
	
	data_len = oob_len = 0;

	while ( data_len < len) {
		//check bad block
		{
			loff_t ofs;
			i = block;
			while(1){
				ofs= i*mtd->erasesize;
				if(ofs >=gp_access_range){
					printk("Access address overflow!!!\n");
					*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif
					return -1;
				}
				if(rtk_block_isbad(mtd,chipnr,ofs)==0x0){
					block = i;
					old_page = block*ppb + page_offset;
					break;
				}else{
					i++;
				}
			}
		}

		page = block*ppb + page_offset;
		spare_value =  (block_tag & 0x0000ffff) | ((page_counter & 0xffff) << 16);
		rc = this->write_bootcode_area(mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len], spare_value);
		
		if (rc < 0) {
			//erase & mark bad block
			this->g_oobbuf[0] = 0x00;
			//block = page_ppb;
			if ( isLastPage ){
				this->erase_block (mtd, err_chipnr, block*ppb);
				this->write_oob(mtd, this->active_chip, block*ppb+ppb-1, oob_size, this->g_oobbuf);
				this->write_oob(mtd, this->active_chip, block*ppb+ppb-2, oob_size, this->g_oobbuf);
			}else{
				this->erase_block (mtd, err_chipnr, block*ppb);
				this->write_oob(mtd, this->active_chip, block*ppb, oob_size, this->g_oobbuf);	
				this->write_oob(mtd, this->active_chip, block*ppb+1, oob_size, this->g_oobbuf);
			}

#if 0
			//write next block
			data_len = data_len - page%ppb*page_size;
			oob_len = oob_len -  page%ppb*oob_size;

			
			old_page = old_page -page%ppb + ppb;
			page_offset = old_page & (ppb-1);
			if ( data_len<len && !(old_page & this->pagemask)) {
				old_page &= this->pagemask;
				chipnr++;
				this->active_chip = chipnr;
				this->select_chip(mtd, chipnr);
			}
			block = old_page/ppb;
			
			continue;
#else
			printk ("%s: Write fail!:  rc=%d\n", __FUNCTION__, rc);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif
			return -1;
#endif
		}
		
		data_len += page_size;
		oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
		page_counter++;
	}

	if ( retlen ){
		if ( data_len == len )
			*retlen = data_len;
		else{
			printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif
			return -1;
		}	
	}
	
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif

	return block;

}

int nand_erase_bootcode_area (struct mtd_info *mtd, struct erase_info *instr)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
	rtk_spin_lock();
#endif	
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	u_int32_t addr = instr->addr;
	u_int32_t len = instr->len;
	int page, chipnr;
	int old_page, block;
	int elen = 0;
	int rc = 0;
	int realpage, chipnr_remap;
	int i;

	 instr->fail_addr = 0xffffffff;

	 if ((addr + len) >= (g_Secure_store_Start + g_Secure_store_Size)) {
		printk ("nand_erase_bootcode_area: Attempt erase beyond end of bootcode area\n");
		instr->state = MTD_ERASE_FAILED;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		return -EINVAL;
	}

	if (addr & (mtd->erasesize - 1)) {
		printk ("%s: attempt access non-block-aligned data\n",__FUNCTION__);
		instr->state = MTD_ERASE_FAILED;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		return -EINVAL;
	}

	gp_access_range = rtk_access_range_get(addr, len);
	if(gp_access_range == 0){
		printk("[%s][%d]get access range fail!\n",__FUNCTION__,__LINE__);
		instr->state = MTD_ERASE_FAILED;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE				
		rtk_spin_unlock();
#endif	
		return -1;
	}

	realpage = ((int) addr) >> this->page_shift;
	this->active_chip = chipnr = chipnr_remap = ((int) addr) >> this->chip_shift;
	old_page = page = realpage & this->pagemask;
	block = page/ppb;

	this->active_chip=chipnr=chipnr_remap=0;	
	this->select_chip(mtd, chipnr);
	
	instr->state = MTD_ERASING;
	while (elen < len) {
		{
			loff_t ofs;
			i = block;
			while(1){
				ofs= i*mtd->erasesize;
				if(ofs >=gp_access_range){
					printk("Access address overflow!!!\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif
					return -1;
				}
				if(rtk_block_isbad(mtd,chipnr,ofs)==0x0){
					block = i;
					old_page = block*ppb;
					break;
				}else{
					i++;
				}
			}
		}
		
		page = block*ppb;
		rc = this->erase_block (mtd, this->active_chip, page);
			
		if (rc) {
			printk ("%s: block erase failed at page address=0x%08x\n", __FUNCTION__, addr);
			instr->fail_addr = (page << this->page_shift);	
			
			this->g_oobbuf[0] = 0x00;
			if ( isLastPage ){
				this->write_oob(mtd, chipnr, page+ppb-1, oob_size, this->g_oobbuf);
				this->write_oob(mtd, chipnr, page+ppb-2, oob_size, this->g_oobbuf);
			}else{
				this->write_oob(mtd, chipnr, page, oob_size, this->g_oobbuf);
				this->write_oob(mtd, chipnr, page+1, oob_size, this->g_oobbuf);
			}

			printk ("%s: ERASE fail! rc=%d\n", __FUNCTION__, rc);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif
			return -1;
		}
		
		if ( chipnr != chipnr_remap )
			this->select_chip(mtd, chipnr);
			
		elen += mtd->erasesize;

		old_page += ppb;
		
		if ( elen<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}

		block = old_page/ppb;
	}
	instr->state = MTD_ERASE_DONE;

#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif
	return rc;
}

static int nand_read_bootcode_area (struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, u_char *buf, u_char *oob_buf)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	
	struct nand_chip *this = mtd->priv;
	unsigned long long  page, realpage,page_ppb;
	int data_len, oob_len;
	int rc;
	unsigned int old_page, page_offset, block;
	int chipnr, chipnr_remap;
	int i;
	int retry_count;

	if ((from + len) >mtd->size) {
		printk ("nand_read_bootcode_area: Attempt read beyond chip-size\n");
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}

	if (NOTALIGNED (mtd, from) || NOTALIGNED(mtd, len)) {
		printk (KERN_NOTICE "nand_read_bootcode_area: Attempt to read not page aligned data\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		return -EINVAL;
	}

	gp_access_range = rtk_access_range_get(from, len);
	if(gp_access_range == 0){
		printk("[%s][%d]get access range fail!\n",__FUNCTION__,__LINE__);
		*retlen = 0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE				
		rtk_spin_unlock();
#endif	
		return -1;
	}

	realpage = (int)(from >> this->page_shift);
	this->active_chip = chipnr = chipnr_remap = (int)(from >> this->chip_shift);
	old_page = page = realpage & this->pagemask;
	page_offset = page & (ppb-1);
	//block = page/ppb;
	page_ppb = page;
	do_div(page_ppb,ppb);
	block = (unsigned int)page_ppb;

	this->active_chip=chipnr=chipnr_remap=0;		
	//CMYu, 20091030
	mtd->ecctype = mtd->oobinfo.useecc;
	
	this->select_chip(mtd, chipnr);
	
	if ( retlen )
		*retlen = 0;
	
	data_len = oob_len = 0;

	while (data_len < len) {
		{
			loff_t ofs;
			i = block;
			while(1){
				ofs= i*mtd->erasesize;
				if(ofs >=gp_access_range){
					printk("Access address overflow!!!\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif
					return -1;
				}
				if(rtk_block_isbad(mtd,chipnr,ofs)==0x0){
					block = i;
					old_page = block*ppb + page_offset;
					break;
				}else{
					i++;
				}
			}
		}

		page = block*ppb + page_offset;  
		for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++){
			rc = this->read_ecc_page (mtd, this->active_chip, page, &buf[data_len], &oob_buf[oob_len]);
			if(rc >= 0)
				break;				
		}
		if (rc < 0) {
			if (rc == -1){
				//printk ("%s: read_ecc_page: Un-correctable HW ECC\n", __FUNCTION__);
				this->g_oobbuf[0] = 0x00;
				if ( isLastPage){
					this->erase_block (mtd, this->active_chip, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-1, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+ppb-2, oob_size, this->g_oobbuf);
				}else{
					this->erase_block (mtd, this->active_chip, block*ppb);
					this->write_oob(mtd, this->active_chip, block*ppb, oob_size, this->g_oobbuf);
					this->write_oob(mtd, this->active_chip, block*ppb+1, oob_size, this->g_oobbuf);
				}
				printk("nand_read_bootcode_area: Un-correctable HW ECC Error at page=0x%llx\n", page);
				
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
				
			}else{
				printk ("%s: read fail---> semphore failed\n", __FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
			}
		}

		data_len += page_size;

		if(oob_buf)//add by alexchang 0524-2010
			oob_len += oob_size;
		
		old_page++;
		page_offset = old_page & (ppb-1);
		if ( data_len<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}

	if ( retlen ){
		if ( data_len == len )
			*retlen = data_len;
		else{
				printk("[%s] error: data_len %d != len %d\n", __FUNCTION__, data_len, len);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif
				return -1;
		}	
	}

#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif
	return 0;
}

//for build profile
static unsigned int accumulate_byte_value(const void *buf, unsigned int length)
{
	unsigned int i, res;
	unsigned char *ptr = (unsigned char *)buf;

	if ((buf == NULL) || (length == 0))
		return 0;

	for (i = res = 0; i < length; i++)
		res += ptr[i];

	return res;
}

unsigned int swap_endian(unsigned int input)
{
	unsigned int output;

	output = (input & 0xff000000)>>24|
			 (input & 0x00ff0000)>>8|
			 (input & 0x0000ff00)<<8|
			 (input & 0x000000ff)<<24;

	return output;
}

// return 0 ----> profile not exist
//return 1 ----> profile exist
static int nand_profile_exist(struct mtd_info *mtd, unsigned char block_tag)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	int rc=0;
	unsigned int checksum;
	t_nand_profile *profile;
	int chipnr =0;
	
	//check block state & data
	memset(this->g_databuf, 0xff , mtd->oobblock);
	memset(this->g_oobbuf, 0xff , mtd->oobsize);
	rc = this->read_ecc_page (mtd, chipnr, 0, this->g_databuf, this->g_oobbuf);
	if (rc < 0) {
		printk("read profile error\n");	
		return 0;
	}

	//check block-tag
	if (this->g_oobbuf[0] != block_tag) {
		printk("[%x] profile not exist\n", this->g_oobbuf[0]);
		return 0;
	}

	// check profile identifier
	profile = (t_nand_profile *)this->g_databuf;

	rc = memcmp(profile->identifier, NAND_PROFILE_IDENTIFIER, 
		strlen(NAND_PROFILE_IDENTIFIER));
	if (rc) {
		printk("wrong identify\n");
		return 0;
	}
	
	//check checksum
	checksum = accumulate_byte_value(profile, 128);
	if (checksum != *((unsigned int *)profile->checksum)) {
		printk("profile checksum not match (%x <> %x)\n", 
			checksum, *((unsigned int *)profile->checksum));
		return 0;
	}
	
	//success return 
	return 1;
}


static int build_nand_profile(struct mtd_info *mtd, t_nand_profile *profile)
{
	unsigned int tmp, checksum;
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	unsigned int tmp_id;
	unsigned int blocks_per_flash = ((unsigned int)ptr_device->size)/ptr_device->BlockSize;

	if (profile == NULL) {
		return -1;
	}

	// build NAND profile
	memcpy(profile->identifier, NAND_PROFILE_IDENTIFIER, sizeof(NAND_PROFILE_IDENTIFIER));
	profile->revision = 0x2;

	//ptr_device
	tmp_id = swap_endian(ptr_device->id);
	for (tmp = 0; tmp < 4; tmp++)
		profile->manufacturer_id[tmp] = (tmp_id >> (tmp * 8)) & 0xff;

	if(ptr_device->CycleID5th != 0xff){
		profile->manufacturer_id[4] = ptr_device->CycleID5th;
	}
	if(ptr_device->CycleID6th != 0xff){
		profile->manufacturer_id[5] = ptr_device->CycleID6th;
	}

	if (strlen(ptr_device->name) < (sizeof(profile->flash_name) - 1))
		tmp = strlen(ptr_device->name);
	else
		tmp = sizeof(profile->flash_name) - 1;
	memcpy(profile->flash_name, (char *)(ptr_device->name), tmp);

	profile->number_of_bbt = 2;
	profile->bbt_start_block = 0x1;
	profile->bbt_end_block = 0x2;
	profile->number_of_rsv_block = (blocks_per_flash * this->RBA_PERCENT)/ 100;
	profile->rsv_start_block = blocks_per_flash - profile->number_of_rsv_block;
	profile->rsv_end_block = blocks_per_flash - 1;
	profile->data_per_page = ptr_device->PageSize;

	switch (ptr_device->eccSelect) {
		case 0x00:
			tmp = 16 * (ptr_device->PageSize / 512);
			break;
		case 0x0c:
			tmp = 26 * (ptr_device->PageSize / 512);
			break;
/*
		case ECC_24BIT:
			tmp = 46 * (device->PageSize / 1024);
			break;
*/
		default:	// unknown type
			return -1;
	}
	profile->oob_per_page = tmp;
	profile->page_per_block = this->ppb;
	profile->block_per_die = blocks_per_flash;
	
	switch (ptr_device->eccSelect){
		case 0x00:
			//6bit ecc
			profile->ecc_bit = ECC_6BIT;
			break;
		case 0x0c:
			//12bit ecc
			profile->ecc_bit = ECC_12BIT;
			break;

		default:
			return -1;

	}

	profile->param_t1 = ptr_device->T1;
	profile->param_t2 = ptr_device->T2;
	profile->param_t3 = ptr_device->T3;
	
	//set default value 0x1
	profile->address_mode = 0x1;

	checksum = accumulate_byte_value(profile, 128);
	//modify by angus, magellan doesn't endian invert
	for (tmp = 0; tmp < 4; tmp++)
		profile->checksum[tmp] = (checksum >> (tmp * 8)) & 0xff;
	//*(unsigned int *)profile->checksum = checksum;

	return 0;
}


static int nand_write_profile (struct mtd_info *mtd)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
	rtk_spin_lock();
#endif	
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	t_nand_profile *profile;
	int chipnr =0;
	unsigned int spare_value, page_counter=0;
	unsigned char block_tag=0xd0;
	int rc = 0;

	if(nand_profile_exist(mtd, block_tag)){
		printk("Profile exist!\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
		rtk_spin_unlock();
#endif	
		return 0;
	}

	profile = (t_nand_profile *)kmalloc(sizeof(t_nand_profile), GFP_KERNEL);
	if(profile == NULL){
		printk("%s: Error, no enough memory for profile\n",__FUNCTION__);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif	
		return -1;
	}else{
		//set init value
		memset(profile, 0, sizeof(t_nand_profile));
	}
		

	rc = build_nand_profile(mtd, profile);
	if(rc<0){
		printk("Build nand profile fail!\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif		
		kfree(profile);
		return -1;
	}
	
	//erase block0
	rc = this->erase_block(mtd, chipnr, 0);
	if(rc<0){
		printk("Erase block0 fail!\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		kfree(profile);
		return -1;
	}

	//reset buffer
	memset(this->g_databuf, 0xff , mtd->oobblock);
	memset(this->g_oobbuf, 0xff , mtd->oobsize);
	//set buffer value
	memcpy(this->g_databuf, profile, sizeof(t_nand_profile));
	this->g_oobbuf[0] = block_tag;
	//set spare_value
	spare_value =  (block_tag & 0x0000ffff) | ((page_counter & 0xffff) << 16);
	rc = this->write_bootcode_area(mtd, chipnr, 0, this->g_databuf, this->g_oobbuf, spare_value);
	if(rc<0){
		printk("Write profile fail!\n");
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
		rtk_spin_unlock();
#endif
		kfree(profile);
		return -1;
	}
	
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif
	kfree(profile);
	return 0;
}

//-----------------------------end : access bootcode area interface-------------------------------------
static int nand_erase (struct mtd_info *mtd, struct erase_info *instr)
{
	
	return nand_erase_nand (mtd, instr, 0);
}

#ifndef CONFIG_MTD_NAND_RBT
int nand_erase_nand (struct mtd_info *mtd, struct erase_info *instr, int allowbbt)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
	rtk_spin_lock();
#endif	
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	u_int32_t addr = instr->addr;
	u_int32_t len = instr->len;
	int page, chipnr;
	int old_page, block;
	int elen = 0;
	int rc = 0;
	int i=0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;
	int realpage, chipnr_remap, block_remap=0x12345678;

	check_end (mtd, addr, len);
	check_block_align (mtd, addr);

	 instr->fail_addr = 0xffffffff;

	realpage = ((int) addr) >> this->page_shift;
	this->active_chip = chipnr = chipnr_remap = ((int) addr) >> this->chip_shift;
	old_page = page = realpage & this->pagemask;
	block = page/ppb;
	if(g_sw_WP_level > 0)
	{
		if(!g_disNFWP)
		{
			if(check_SW_WP(mtd)==-1)
			{
				if(page >= (g_BootcodeSize+g_Factory_param_size)/page_size+ppb) 				
				{
					printk("[%s]Permission denied!!!\n",__FUNCTION__);
					g_disNFWP=0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
				}
			}
		}
	}
	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);
	
	instr->state = MTD_ERASING;
	while (elen < len) {
		//printk("Ready to Erase blk %u\n",page/ppb);
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				return -ERESTARTSYS;
			}
			retryCnt--;
		}
		//block_remap=0x12345678;
#ifdef CONFIG_MTD_NAND_IBT
		//search ibt
		if(this->use_ibt){
			if(((this->ibt[block].src_block ==  SRC_INIT)&&(this->ibt[block].dst_block ==  DST_INIT)) ||(this->ibt[block].dst_block== block)){
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt  ...\n",__FUNCTION__,block);
				#endif
			}else if(this->ibt[block].dst_block != block){
				block = this->ibt[block].dst_block;
				#ifdef _DEBUG_IBT
				printk(" [%s][block no = 0x%x]ibt search...\n", __FUNCTION__,block);
				#endif
			}
		}
#endif

		for ( i=0; i<RBA; i++){
			if ( this->bbt[i].bad_block != BB_INIT ){
				if ( this->active_chip == this->bbt[i].BB_die && block == this->bbt[i].bad_block ){
					block = this->bbt[i].remap_block;
					if ( this->bbt[i].BB_die != this->bbt[i].RB_die ){
						this->active_chip = chipnr_remap = this->bbt[i].RB_die;
						this->select_chip(mtd, chipnr_remap);
					}
				}
			}else
				break;
		}
		up (&sem_bbt);
		page = block*ppb;
		//printk("confirm to Erase blk %u\n",page/ppb);
		rc = this->erase_block (mtd, this->active_chip, page);
			
		if (rc) {
			printk ("%s: block erase failed at page address=0x%08x\n", __FUNCTION__, addr);
			instr->fail_addr = (page << this->page_shift);	
			if(check_BBT(mtd,page/ppb)==0)
			{
				while (down_interruptible (&sem_bbt)) {
					printk("%s : Retry\n",__FUNCTION__);
					if(retryCnt<=0)
					{
						printk("%s : BBT Retry fail!\n",__FUNCTION__);
						return -ERESTARTSYS;
					}
					retryCnt--;
				}
				//block_remap=0x12345678;
				for( i=0; i<RBA; i++){
					if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT)
						{
							if ( chipnr != chipnr_remap)
								this->bbt[i].BB_die = chipnr_remap;
							else
								this->bbt[i].BB_die = chipnr;
						this->bbt[i].bad_block = page/ppb;
						block_remap = this->bbt[i].remap_block;
						break;
					}
				}
				up (&sem_bbt);
				if ( block_remap == 0x12345678 ){
					printk("[%s] RBA do not have free remap block[%d]\n", __FUNCTION__,RBA);
					if(g_sw_WP_level > 0)
					{
						if(g_disNFWP)
								g_disNFWP=0;
					}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
				}
			}

			dump_BBT(mtd);

			if ( rtk_update_bbt (mtd, this->g_databuf, this->g_oobbuf, this->bbt) ){
				printk("[%s] rtk_update_bbt() fails\n", __FUNCTION__);
				if(g_sw_WP_level > 0)
				{
					if(g_disNFWP)
							g_disNFWP=0;
				}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
			}
			
			this->g_oobbuf[0] = 0x00;
			if ( isLastPage ){
				this->write_oob(mtd, chipnr, page+ppb-1, oob_size, this->g_oobbuf);
				this->write_oob(mtd, chipnr, page+ppb-2, oob_size, this->g_oobbuf);
			}else{
				this->write_oob(mtd, chipnr, page, oob_size, this->g_oobbuf);
				this->write_oob(mtd, chipnr, page+1, oob_size, this->g_oobbuf);
			}
		
			rc = this->erase_block(mtd, chipnr_remap, block_remap*ppb);
		}
		//else
			//printk("confirm to Erase blk %u  succeed!!\n",page/ppb);
		
		if ( chipnr != chipnr_remap )
			this->select_chip(mtd, chipnr);
			
		elen += mtd->erasesize;

		old_page += ppb;
		
		if ( elen<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}

		block = old_page/ppb;
	}
	instr->state = MTD_ERASE_DONE;
	if(g_sw_WP_level > 0)
	{
		if(g_disNFWP)
				g_disNFWP=0;
	}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif
	return rc;
}

#else
int nand_erase_nand (struct mtd_info *mtd, struct erase_info *instr, int allowbbt)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE 	
	rtk_spin_lock();
#endif	
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	u_int32_t addr = instr->addr;
	u_int32_t len = instr->len;
	int page = 0, chipnr = 0,old_page = 0, block = 0,elen = 0;
	int rc = 0,i=0,realpage = 0, chipnr_remap = 0,phy_block = 0;
	unsigned int retryCnt = MTD_SEM_RETRY_COUNT;

	check_end (mtd, addr, len);
	check_block_align (mtd, addr);

	instr->fail_addr = 0xffffffff;

	realpage = ((int) addr) >> this->page_shift;
	this->active_chip = chipnr = chipnr_remap = ((int) addr) >> this->chip_shift;
	old_page = page = realpage & this->pagemask;
	block = page/ppb;
	if(g_sw_WP_level > 0)
	{
		if(!g_disNFWP)
		{
			if(check_SW_WP(mtd)==-1)
			{
				if(page >= (g_BootcodeSize+g_Factory_param_size)/page_size+ppb) 				
				{
					printk("[%s]Permission denied!!!\n",__FUNCTION__);
					g_disNFWP=0;
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
				}
			}
		}
	}
	this->active_chip=chipnr=chipnr_remap=0;		
	this->select_chip(mtd, chipnr);
	
	instr->state = MTD_ERASING;
	while (elen < len) {
		//printk("Ready to Erase blk %u\n",page/ppb);
		while (down_interruptible (&sem_bbt)) {
			printk("%s : Retry\n",__FUNCTION__);
			if(retryCnt<=0)
			{
				printk("%s : BBT Retry fail!\n",__FUNCTION__);
				rc = -ERESTARTSYS;
				goto end;
			}
			retryCnt--;
		}
		/*get phy block*/
		phy_block = get_phyblock(mtd,block);
		up (&sem_bbt);
		
		page = phy_block*this->ppb ;
		//printk("confirm to Erase blk %u\n",page/ppb);
		if((rc = this->erase_block (mtd, this->active_chip, page))!= 0){
			while (down_interruptible (&sem_bbt)) {
				printk("%s : Retry\n",__FUNCTION__);
				if(retryCnt<=0){
					printk("%s : BBT Retry fail!\n",__FUNCTION__);
					rc = -ERESTARTSYS;
					goto end;
				}
				retryCnt--;
			}
			if((rc = erase_remap_block(mtd,block,phy_block))!= 0){
				up (&sem_bbt);
				goto end;
			}
			up (&sem_bbt);
		}

		elen += mtd->erasesize;
		old_page += ppb;
		
		if ( elen<len && !(old_page & this->pagemask)) {
			old_page &= this->pagemask;
			chipnr++;
			this->active_chip = chipnr;
			this->select_chip(mtd, chipnr);
		}
		block = old_page/ppb;
	}
	instr->state = MTD_ERASE_DONE;

end:
	if(g_sw_WP_level > 0)
	{
		if(g_disNFWP)
				g_disNFWP=0;
	}
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif
	return rc;
}

#endif

static void nand_sync (struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	this->state = FL_READY;
}


static int nand_suspend (struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	this->suspend(mtd);
	return 0;
}


static void nand_resume (struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	this->resume(mtd);
}


static void nand_select_chip(struct mtd_info *mtd, int chip)
{
	switch(chip) {
		case -1:
			REG_WRITE_U32(REG_PD,0xff);
			break;			
		case 0:
		case 1:
		case 2:
		case 3:
			REG_WRITE_U32(REG_PD, ~(1 << chip));
			break;
		default:
			REG_WRITE_U32(REG_PD, ~(1 << 0));
	}
}

#ifndef CONFIG_MTD_NAND_RBT
#ifndef CONFIG_MTD_NAND_IBT
static int scan_last_die_BB(struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	__u32 start_page = 0;
	__u32 addr;
	int block_num = this->block_num;
	int block_size = 1 << this->phys_erase_shift;
	int table_index=0;
	int remap_block[RBA];
	int remap_count = 0;
	int i, j;
	int numchips = this->numchips;
	int chip_size = this->chipsize;
	int rc = 0;
	__u8 *block_status = NULL;
	g_mtd_BootcodeSize = rtkNF_getBootcodeSize();
	if(g_mtd_BootcodeSize == -1)
	{
		if(is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
			g_mtd_BootcodeSize = 0x1400000;		
		else
			g_mtd_BootcodeSize = 12*1024*1024;
	}
	if ( numchips>1 ){
		start_page = 0x00000000;
	}else{
		//start_page = 0x01000000;
		start_page = g_mtd_BootcodeSize + g_Secure_store_Size;
	}		
	
	this->active_chip = numchips-1;
	this->select_chip(mtd, numchips-1);
	
	block_status = kmalloc( block_num, GFP_KERNEL );	
	if ( !block_status ){
		printk("%s: Error, no enough memory for block_status\n",__FUNCTION__);
		rc = -ENOMEM;
		goto EXIT;
	}
	memset ( (__u32 *)block_status, 0, block_num );
	for( addr=start_page; addr<chip_size; addr+=block_size ){
		if ( rtk_block_isbad(mtd, numchips-1, addr) ){
			int bb = addr >> this->phys_erase_shift;
			block_status[bb] = 0xff;
		}
	}

	for ( i=0; i<RBA; i++){
		if ( block_status[(block_num-1)-i] == 0x00){
			remap_block[remap_count] = (block_num-1)-i;
			remap_count++;
		}
	}

	if (remap_count<RBA+1){
		for (j=remap_count+1; j<RBA+1; j++)
			remap_block[j-1] = RB_INIT;
	}

	for ( i=0; i<(block_num-RBA); i++){
		if (block_status[i] == 0xff){
			this->bbt[table_index].bad_block = i;
			this->bbt[table_index].BB_die = numchips-1;
			this->bbt[table_index].remap_block = remap_block[table_index];
			this->bbt[table_index].RB_die = numchips-1;
			table_index++;
		}
	}

	for( i=table_index; table_index<RBA; table_index++){
		this->bbt[table_index].bad_block = BB_INIT;
		this->bbt[table_index].BB_die = BB_DIE_INIT;
		this->bbt[table_index].remap_block = remap_block[table_index];
		this->bbt[table_index].RB_die = numchips-1;
	}
	
	kfree(block_status);

	RTK_FLUSH_CACHE((unsigned long) this->bbt, sizeof(BB_t)*RBA);
	
EXIT:
	if (rc){
		if (block_status)
			kfree(block_status);	
	}
				
	return 0;
}


static int scan_other_die_BB(struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	__u32 start_page;
	__u32 addr;
	int block_size = 1 << this->phys_erase_shift;
	int j, k;
	int numchips = this->numchips;
	int chip_size = this->chipsize;

	g_mtd_BootcodeSize = rtkNF_getBootcodeSize();
	if(g_mtd_BootcodeSize == -1)
	{
		if(is_magellan_cpu()||is_296x_cpu()||is_sirius_cpu())
			g_mtd_BootcodeSize = 0x1400000;		//20M
		else
			g_mtd_BootcodeSize = 12*1024*1024;
	}
	for( k=0; k<numchips-1; k++ ){
		this->active_chip = k;
		this->select_chip(mtd, k);
		if( k==0 ){
			start_page = g_mtd_BootcodeSize + g_Secure_store_Size;
		}else{
			start_page = 0x00000000;
		}
		
		for( addr=start_page; addr<chip_size; addr+=block_size ){
			if ( rtk_block_isbad(mtd, k, addr) ){
				for( j=0; j<RBA; j++){
					if ( this->bbt[j].bad_block == BB_INIT && this->bbt[j].remap_block != RB_INIT){
						this->bbt[j].bad_block = addr >> this->phys_erase_shift;
						this->bbt[j].BB_die = k;
						this->bbt[j].RB_die = numchips-1;
						break;
					}
				}
			}
		}
	}
	
	RTK_FLUSH_CACHE((unsigned long) this->bbt, sizeof(BB_t)*RBA);
	
	return 0;
}

static int rtk_create_bbt(struct mtd_info *mtd, int page)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	
	int rc = 0;
	u8 *temp_BBT = 0;
	u8 mem_page_num, page_counter=0;
	if(page==ppb)
		printk("[%s] nand driver creates B1 !!\n", __FUNCTION__);
	else if(page==(ppb<<1))
		printk("[%s] nand driver creates B2 !!\n", __FUNCTION__);
	
	if ( scan_last_die_BB(mtd) ){
		printk("[%s] scan_last_die_BB() error !!\n", __FUNCTION__);
		return -1; 
	}
 
	if ( this->numchips >1 ){	
		if ( scan_other_die_BB(mtd) ){
			printk("[%s] scan_last_die() error !!\n", __FUNCTION__);
			return -1;
		}
	}

	mem_page_num = (sizeof(BB_t)*RBA + page_size-1 )/page_size;
	temp_BBT = kmalloc( mem_page_num*page_size, GFP_KERNEL );
	if ( !temp_BBT ){
		printk("%s: Error, no enough memory for temp_BBT\n",__FUNCTION__);
		return -ENOMEM;
	}
	memset( temp_BBT, 0xff, mem_page_num*page_size);
			
	this->select_chip(mtd, 0);
	
	if ( this->erase_block(mtd, 0, page) ){
		printk("[%s]erase block %d failure !!\n", __FUNCTION__, page/ppb);
		rc =  -1;
		goto EXIT;
	}
		
	this->g_oobbuf[0] = BBT_TAG;

	memcpy( temp_BBT, this->bbt, sizeof(BB_t)*RBA );
	while( mem_page_num>0 ){
		if ( this->write_ecc_page(mtd, 0, page+page_counter, temp_BBT+page_counter*page_size, 
			this->g_oobbuf, 1) ){
				printk("[%s] write BBT B%d page %d failure!!\n", __FUNCTION__, 
					page ==0?0:1, page+page_counter);
				rc =  -1;
				goto EXIT;
		}
		page_counter++;
		mem_page_num--;		
	}

EXIT:
	if (temp_BBT)
		kfree(temp_BBT);
		
	return rc;		
}
#endif

int rtk_update_bbt (struct mtd_info *mtd, __u8 *data_buf, __u8 *oob_buf, BB_t *bbt)
{
	int rc = 0;
	struct nand_chip *this = mtd->priv;
	unsigned char active_chip = this->active_chip;
	u8 *temp_BBT = 0;
#ifdef CONFIG_MTD_NAND_BBT_SHARE	
	unsigned long ret = 0;
#endif
	
	oob_buf[0] = BBT_TAG;

	this->select_chip(mtd, 0);	
		
	if ( sizeof(BB_t)*RBA <= page_size){
		memcpy( data_buf, bbt, sizeof(BB_t)*RBA );
	}else{
		temp_BBT = kmalloc( 2*page_size, GFP_KERNEL );
		if ( !(temp_BBT) ){
			printk("%s: Error, no enough memory for temp_BBT\n",__FUNCTION__);
			return -ENOMEM;
		}
		memset(temp_BBT, 0xff, 2*page_size);
		memcpy(temp_BBT, bbt, sizeof(BB_t)*RBA );
		memcpy(data_buf, temp_BBT, page_size);
	}
		
	if ( this->erase_block(mtd, 0, ppb) ){
		printk("[%s]error: erase block 1 failure\n", __FUNCTION__);
	}

	if ( this->write_ecc_page(mtd, 0, ppb, data_buf, oob_buf, 1) ){
		printk("[%s]update BBT B1 page 0 failure\n", __FUNCTION__);
	}else{
		if ( sizeof(BB_t)*RBA > page_size){
			memset(data_buf, 0xff, page_size);
			memcpy( data_buf, temp_BBT+page_size, sizeof(BB_t)*RBA - page_size );
			if ( this->write_ecc_page(mtd, 0, ppb+1, data_buf, oob_buf, 1) ){
				printk("[%s]update BBT B1 page 1 failure\n", __FUNCTION__);
			}
			memcpy(data_buf, temp_BBT, page_size);//add by alexchang 0906-2010
		}	
	}
	//-----------------------------------------------------------------------
	if ( this->erase_block(mtd, 0, ppb<<1) ){
		printk("[%s]error: erase block 1 failure\n", __FUNCTION__);
		return -1;
	}

	if ( this->write_ecc_page(mtd, 0, ppb<<1, data_buf, oob_buf, 1) ){
		printk("[%s]update BBT B2 failure\n", __FUNCTION__);
		return -1;
	}else{
		if ( sizeof(BB_t)*RBA > page_size){
			memset(data_buf, 0xff, page_size);
			memcpy( data_buf, temp_BBT+page_size, sizeof(BB_t)*RBA - page_size );
			if ( this->write_ecc_page(mtd, 0, 2*ppb+1, data_buf, oob_buf, 1) ){
				printk("[%s]error: erase block 2 failure\n", __FUNCTION__);
				return -1;
			}
		}		
	}
	
	this->select_chip(mtd, active_chip);

	if (temp_BBT)
		kfree(temp_BBT);
	
#ifdef CONFIG_MTD_NAND_BBT_SHARE
	if(send_krpc(RPC_KCPU,KRPC_NON_BLOCK_MODE,0,RPC_SCPU_NAND_BBT_UPDATE, 0, 0, &ret) == RPC_OK) {
		printk("%s:send RPC_SCPU_NAND_BBT_UPDATE successfully %ld\n",__func__,ret);
	}
	else{
		printk("%s:send RPC_SCPU_NAND_BBT_UPDATE fail %ld\n",__func__,ret);
	}
	if(ret)
		printk("%s:rpc update kcpu bbt failed!\n",__func__);		
#endif		

	return rc;
}

static int rtk_badblock_remap(struct mtd_info *mtd, u16 chipnr, unsigned int page)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	unsigned char *data_buf = NULL;
	unsigned int page_align;
	unsigned int block = 0,remap_block = 0;
	int data_len;
	int i;
	int ret = 0,rc = 0;
	int chipnr_remap = 0;
	int flag_temp = 0;

	if((data_buf = kmalloc( mtd->erasesize, GFP_KERNEL )) == NULL){
		printk("%s:%d:malloc buf failed!\n",__func__,__LINE__);
		ret = -1;
		goto end;
	}

	memset(data_buf,0xff,mtd->erasesize);

	//32bit sys
	block = page/ppb;
	page_align = block*ppb;

	this->active_chip = chipnr;
	this->select_chip(mtd, chipnr);

	data_len = 0;
	//1.read original block data
	while(data_len < mtd->erasesize){
		rc = this->read_ecc_page (mtd, this->active_chip, page_align, &data_buf[data_len], NULL);
		if(rc < 0){
			printk("%s:%d:read page %d failed!\n",__func__,__LINE__,page_align);
			ret = -1;
			goto end;
		}
		data_len += page_size;
		page_align ++;
	}

	//2.get remap block
	if(check_BBT(mtd,block)==0){
		for( i=0; i<RBA; i++){
			if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
				remap_block = this->bbt[i].remap_block;
				chipnr_remap = this->bbt[i].RB_die;
				this->bbt[i].BB_die = chipnr;
				this->bbt[i].bad_block = block;
				break;
			}
		}

		if(i >= RBA){
			printk("[%s] RBA do not have free remap block[%d]\n", __FUNCTION__,RBA);
			ret = -1;
			goto end;			
		}
	}
	else{
		printk("%s:%d:block %d has remaped!\n",__func__,__LINE__,block);
		ret = -1;
		goto end;
	}

	rc = 1;
	while(rc){

		//3. erase remap block
		if(chipnr_remap != chipnr){
			this->active_chip = chipnr_remap;
			this->select_chip(mtd, chipnr_remap);
		}
		printk("%s:%d:confirm to Erase blk %u\n",__func__,__LINE__,remap_block);
		rc = this->erase_block (mtd, this->active_chip, remap_block*ppb);
		if(rc){
			printk ("%s: block erase failed at page address=0x%08x\n", __FUNCTION__, remap_block*ppb);
			if(check_BBT(mtd,remap_block)==0)
			{

				for( i=0; i<RBA; i++){
					if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
							if ( chipnr != chipnr_remap)
								this->bbt[i].BB_die = chipnr_remap;
							else
								this->bbt[i].BB_die = chipnr;
							this->bbt[i].bad_block = block = remap_block;
							remap_block = this->bbt[i].remap_block;
							chipnr_remap = this->bbt[i].RB_die;
							break;
					}
				}				

				if ( i >= RBA ){
					printk("[%s] RBA do not have free remap block[%d]\n", __FUNCTION__,RBA);
					ret = -1;
					goto end;
				}
				
				this->g_oobbuf[0] = 0x00;
				if ( isLastPage ){
					this->write_oob(mtd, this->active_chip, block*ppb + ppb - 1, oob_size, this->g_oobbuf);
					this->write_oob(mtd, chipnr, block*ppb + ppb - 2, oob_size, this->g_oobbuf);
				}else{
					this->write_oob(mtd, chipnr, block*ppb, oob_size, this->g_oobbuf);
					this->write_oob(mtd, chipnr, block*ppb+1, oob_size, this->g_oobbuf);
				}		
				
				continue;
			}	
			else{
				printk("%s:%d:block %d has remaped!\n",__func__,__LINE__,block);
				ret = -1;
				goto end;				
			}			
		}

		//4. write remap block
		data_len = 0;
		memset(this->g_oobbuf,0xFF,mtd->oobsize);
		page_align = remap_block*ppb;
		while(data_len < mtd->erasesize){
			rc = this->write_ecc_page (mtd, this->active_chip, page_align, &data_buf[data_len], this->g_oobbuf, 0);
			if(rc < 0){
				if(rc == -1){
					printk ("%s: write_ecc_page:  write blk:%u, page:%u failed\n", __FUNCTION__,page_align/ppb,page_align%ppb);
					if(check_BBT(mtd,remap_block)==0){
						for( i=0; i<RBA; i++){
							if ( this->bbt[i].bad_block == BB_INIT && this->bbt[i].remap_block != RB_INIT){
									if ( chipnr != chipnr_remap)
										this->bbt[i].BB_die = chipnr_remap;
									else
										this->bbt[i].BB_die = chipnr;
									this->bbt[i].bad_block = block = remap_block;
									remap_block = this->bbt[i].remap_block;
									chipnr_remap = this->bbt[i].RB_die;
									break;
							}
						}				

						if ( i >= RBA ){
							printk("[%s] RBA do not have free remap block[%d]\n", __FUNCTION__,RBA);
							ret = -1;
							goto end;
						}
						
						this->erase_block (mtd, this->active_chip, block*ppb);	
				
						this->g_oobbuf[0] = 0x00;
						if ( isLastPage ){
							this->write_oob(mtd, this->active_chip, block*ppb + ppb - 1, oob_size, this->g_oobbuf);
							this->write_oob(mtd, chipnr, block*ppb + ppb - 2, oob_size, this->g_oobbuf);
						}else{
							this->write_oob(mtd, chipnr, block*ppb, oob_size, this->g_oobbuf);
							this->write_oob(mtd, chipnr, block*ppb+1, oob_size, this->g_oobbuf);
						}		
						
						//continue;		
						flag_temp = 1;
						break;
					}
					else{
						printk("%s:%d:block %d has remaped!\n",__func__,__LINE__,block);
						ret = -1;
						goto end;				
					}
				}
				else{
					printk ("%s: write_ecc_page:  rc=%d\n", __FUNCTION__, rc);
					ret = -1;
					goto end;					
				}
			}
			data_len += page_size;
			page_align ++;			
		}
		
		if(flag_temp){
			flag_temp = 0;
			continue;
		}
		
		rc = 0;
	}

	dump_BBT(mtd);
	
	//5. write bbt
	if ( rtk_update_bbt (mtd, this->g_databuf, this->g_oobbuf, this->bbt) ){
		printk("[%s] rtk_update_bbt() fails\n", __FUNCTION__);
		ret = -1;
		goto end;
	}
	
end:
	if(data_buf != NULL)
		kfree(data_buf);
	
	return ret;
}

static int rtk_nand_reload_bbt(struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	int rc = 0;
	__u8 isbbt_b1, isbbt_b2;
	u8 *temp_BBT=0;
	u8 mem_page_num, page_counter=0;
	unsigned int i=0;

	RTK_FLUSH_CACHE((unsigned long) this->bbt, sizeof(BB_t)*RBA);
	mem_page_num = (sizeof(BB_t)*RBA + page_size-1 )/page_size;
	temp_BBT = kmalloc( mem_page_num*page_size, GFP_KERNEL );
	if ( !temp_BBT ){
		printk("%s: Error, no enough memory for temp_BBT\n",__FUNCTION__);
		return -ENOMEM;
	}
	
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_lock();
#endif	

	memset( temp_BBT, 0xff, mem_page_num*page_size);
	rc = this->read_ecc_page(mtd, 0, ppb, this->g_databuf, this->g_oobbuf);
	
	isbbt_b1 = this->g_oobbuf[0];
	printk("[%s][%d]this->g_oobbuf[0] = %x\n",__FUNCTION__,__LINE__, this->g_oobbuf[0]);
	if ( !rc ){
		if ( isbbt_b1 == BBT_TAG ){
			printk("[%s] have created bbt B1, just loads it !!\n", __FUNCTION__);
			memcpy( temp_BBT, this->g_databuf, page_size );
			page_counter++;
			mem_page_num--;

			while( mem_page_num>0 ){
				if ( this->read_ecc_page(mtd, 0, ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
					printk("[%s] load bbt B1 error!!\n", __FUNCTION__);
					kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif					
					return -1;
				}
				memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;
			}
			memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
		}
		else{
			printk("[%s] read BBT B1 tags fails, try to load BBT B2\n", __FUNCTION__);
			rc = this->read_ecc_page(mtd, 0, ppb<<1, this->g_databuf, this->g_oobbuf);
			isbbt_b2 = this->g_oobbuf[0];	
			printk("[%s][%d]this->g_oobbuf[0] = %x\n",__FUNCTION__,__LINE__, this->g_oobbuf[0]);
			if ( !rc ){
				if ( isbbt_b2 == BBT_TAG ){
					printk("[%s] have created bbt B2, just loads it !!\n", __FUNCTION__);
					memcpy( temp_BBT, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;

					while( mem_page_num>0 ){
						if ( this->read_ecc_page(mtd, 0, 2*ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
							printk("[%s] load bbt B2 error!!\n", __FUNCTION__);
							kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
							rtk_spin_unlock();
#endif							
							return -1;
						}
						memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
						page_counter++;
						mem_page_num--;
					}
					memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
				}else{
					printk("[%s] read BBT B2 tags fails\n", __FUNCTION__);
					//rtk_create_bbt(mtd, ppb);
					//rtk_create_bbt(mtd, ppb<<1);
					kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
					rtk_spin_unlock();
#endif						
					return -1;
				}
			}else{
				printk("[%s] read BBT B2 with HW ECC fails\n", __FUNCTION__);
				//rtk_create_bbt(mtd, ppb);
				kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
			}
		}
	}else{
		printk("[%s] read BBT B1 with HW ECC error, try to load BBT B2\n", __FUNCTION__);
		rc = this->read_ecc_page(mtd, 0, ppb<<1, this->g_databuf, this->g_oobbuf);
		isbbt_b2 = this->g_oobbuf[0];	
		if ( !rc ){
			if ( isbbt_b2 == BBT_TAG ){
				printk("[%s] have created bbt B1, just loads it !!\n", __FUNCTION__);
				memcpy( temp_BBT, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;

				while( mem_page_num>0 ){
					if ( this->read_ecc_page(mtd, 0, 2*ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
						printk("[%s] load bbt B2 error!!\n", __FUNCTION__);
						kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
						rtk_spin_unlock();
#endif						
						return -1;
					}
					memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;
				}
				memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
			}else{
				printk("[%s] read BBT B2 tags fails\n", __FUNCTION__);
				//rtk_create_bbt(mtd, ppb<<1);
				kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
				rtk_spin_unlock();
#endif				
				return -1;
			}
		}else{
			printk("[%s] read BBT B1 and B2 with HW ECC fails\n", __FUNCTION__);
			kfree(temp_BBT);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
			rtk_spin_unlock();
#endif				
			return -1;
		}
	}

	dump_BBT(mtd);

	if (temp_BBT)
		kfree(temp_BBT);
	
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
	rtk_spin_unlock();
#endif	

	return rc;
}

#ifdef CONFIG_MTD_NAND_IBT
static int rtk_nand_scan_bbt(struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	int rc = 0;
	__u8 isbbt_b1, isbbt_b2;
	u8 *temp_BBT=0;
	u8 mem_page_num, page_counter=0;

	RTK_FLUSH_CACHE((unsigned long) this->bbt, sizeof(BB_t)*RBA);
	mem_page_num = (sizeof(BB_t)*RBA + page_size-1 )/page_size;
	temp_BBT = kmalloc( mem_page_num*page_size, GFP_KERNEL );
	if ( !temp_BBT ){
		NF_MSG_ERR("%s: No enough memory for temp_BBT\n",__FUNCTION__);
		return -ENOMEM;
	}
	memset( temp_BBT, 0xff, mem_page_num*page_size);

	rc = this->read_ecc_page(mtd, 0, ppb, this->g_databuf, this->g_oobbuf);
	
	isbbt_b1 = this->g_oobbuf[0];
	if ( !rc ){
		if ( isbbt_b1 == BBT_TAG ){
			NF_MSG_INFO("BBT exist!Load it......\n");
			memcpy( temp_BBT, this->g_databuf, page_size );
			page_counter++;
			mem_page_num--;

			while( mem_page_num>0 ){
				if ( this->read_ecc_page(mtd, 0, ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
					NF_MSG_ERR("%s: Load BBT fail......\n", __FUNCTION__);
					kfree(temp_BBT);
					return -1;
				}
				memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;
			}
			memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
		}
		else{
			NF_MSG_WARN("Read BBT tags fail, try to load BBT back-up......\n");
			rc = this->read_ecc_page(mtd, 0, ppb<<1, this->g_databuf, this->g_oobbuf);
			isbbt_b2 = this->g_oobbuf[0];
			if ( !rc ){
				if ( isbbt_b2 == BBT_TAG ){
					NF_MSG_INFO("BBT back-up exist! load it......\n");
					memcpy( temp_BBT, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;

					while( mem_page_num>0 ){
						if ( this->read_ecc_page(mtd, 0, 2*ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
							NF_MSG_ERR("%s: Load BBT back-up error!!\n", __FUNCTION__);
							kfree(temp_BBT);
							return -1;
						}
						memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
						page_counter++;
						mem_page_num--;
					}
					memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
				}else{
					NF_MSG_ERR("%s: Read BBT back-up tag fail......\n", __FUNCTION__);
					//rtk_create_bbt(mtd, ppb);
					//rtk_create_bbt(mtd, ppb<<1);
					kfree(temp_BBT);
					return -1;
				}
			}else{
				NF_MSG_ERR("Read BBT Back-up with HW ECC fails\n");
				//rtk_create_bbt(mtd, ppb);
				kfree(temp_BBT);
				return -1;
			}
		}
	}else{
		NF_MSG_WARN("Read BBT tags with HW ECC error, try to load BBT back-up......\n");
		rc = this->read_ecc_page(mtd, 0, ppb<<1, this->g_databuf, this->g_oobbuf);
		isbbt_b2 = this->g_oobbuf[0];	
		if ( !rc ){
			if ( isbbt_b2 == BBT_TAG ){
				NF_MSG_INFO("BBT back-up exist! load it......\n");
				memcpy( temp_BBT, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;

				while( mem_page_num>0 ){
					if ( this->read_ecc_page(mtd, 0, 2*ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
						NF_MSG_ERR("%s: Load BBT back-up fail......\n", __FUNCTION__);
						kfree(temp_BBT);
						return -1;
					}
					memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;
				}
				memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
			}else{
				NF_MSG_ERR("%s: Read BBT back-up tag fail......\n", __FUNCTION__);
				//rtk_create_bbt(mtd, ppb<<1);
				kfree(temp_BBT);
				return -1;
			}
		}else{
			NF_MSG_ERR("%s: Read BBT & BBT back-up with HW ECC fail......\n", __FUNCTION__);
			kfree(temp_BBT);
			return -1;
		}
	}

	dump_BBT(mtd);

	if (temp_BBT)
		kfree(temp_BBT);
	
	return rc;
}

//search ibt&bbt
static int rtk_nand_scan_ibt_bbt(struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	int rc = 0;
	unsigned int ibt_page_no,ibt_bak_page_no;
	__u8 isibt, isibt_bak;
	u8 *temp_IBT=0;
	u8 mem_page_num, page_counter=0;
	
	ibt_page_no = IBT_BLOCK_ADDR*ppb;
	ibt_bak_page_no = IBT_BAK_BLOCK_ADDR*ppb;

	RTK_FLUSH_CACHE((unsigned long) this->ibt, sizeof(IB_t)*IBT_LEN);
	
	mem_page_num = (sizeof(IB_t)*IBT_LEN + page_size-1 )/page_size;
	temp_IBT = kmalloc( mem_page_num*page_size, GFP_KERNEL );
	if ( !temp_IBT ){
		NF_MSG_ERR("%s: No enough memory for temp_IBT\n",__FUNCTION__);
		return -ENOMEM;
	}
	memset( temp_IBT, 0xff, mem_page_num*page_size);

	rc = this->read_ecc_page(mtd, 0, ibt_page_no, this->g_databuf, this->g_oobbuf);
	
	isibt = this->g_oobbuf[0];
	if ( !rc ){
		if ( isibt == IBT_TAG ){
			NF_MSG_INFO("IBT exist!Load it......\r\n");
			memcpy( temp_IBT, this->g_databuf, page_size );
			page_counter++;
			mem_page_num--;

			while( mem_page_num>0 ){
				if ( this->read_ecc_page(mtd, 0, ibt_page_no+page_counter, this->g_databuf, this->g_oobbuf) ){
					NF_MSG_ERR("%s: Load IBT fail!!!\n", __FUNCTION__);
					kfree(temp_IBT);
					return -1;
				}
				memcpy( temp_IBT+page_counter*page_size, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;
			}
			memcpy( this->ibt, temp_IBT, sizeof(IB_t)*IBT_LEN);
			
			goto success;
			
		}else{
			NF_MSG_WARN("Read IBT tags fails, try to load IBT back-up......\n");
			rc = this->read_ecc_page(mtd, 0, ibt_bak_page_no, this->g_databuf, this->g_oobbuf);
			isibt_bak = this->g_oobbuf[0];
			if(!rc){
				if ( isibt_bak == IBT_TAG ){
					NF_MSG_INFO("IBT back-up exist!Loads it......\r\n");
					memcpy( temp_IBT, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;

					while( mem_page_num>0 ){
						if ( this->read_ecc_page(mtd, 0, ibt_bak_page_no+page_counter, this->g_databuf, this->g_oobbuf) ){
							NF_MSG_ERR("%s: Load IBT back-up fail!!!\n", __FUNCTION__);
							kfree(temp_IBT);
							return -1;
						}
						memcpy( temp_IBT+page_counter*page_size, this->g_databuf, page_size );
						page_counter++;
						mem_page_num--;
					}
					memcpy( this->bbt, temp_IBT, sizeof(IB_t)*IBT_LEN );

					goto success;
					
				}else{
					NF_MSG_ERR("%s: Read IBT & IBT back-up tags fails......\n", __FUNCTION__);
					goto fail;
				}

			}else{
				NF_MSG_ERR("%s: Read IBT back-up with HW ECC fails......\n", __FUNCTION__);	
				goto fail;
			}
				
		
		}
		
	}else{
		NF_MSG_WARN("Read IBT with HW ECC error, try to load IBT back-up......\n", __FUNCTION__);
		rc = this->read_ecc_page(mtd, 0, ibt_bak_page_no, this->g_databuf, this->g_oobbuf);
		isibt_bak = this->g_oobbuf[0];
		
		if ( !rc ){
			if ( isibt_bak == IBT_TAG ){
				NF_MSG_INFO("IBT back-up exist!Loads it ......\r\n");
				memcpy( temp_IBT, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;

				while( mem_page_num>0 ){
					if ( this->read_ecc_page(mtd, 0, ibt_bak_page_no+page_counter, this->g_databuf, this->g_oobbuf) ){
						NF_MSG_ERR("%s: load IBT back-up fail......\n", __FUNCTION__);
						kfree(temp_IBT);
						return -1;
					}
					memcpy( temp_IBT+page_counter*page_size, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;
				}
				memcpy( this->bbt, temp_IBT, sizeof(IB_t)*IBT_LEN );
				goto success;
				
			}else{
				NF_MSG_ERR("%s: Read IBT back-up tags fails...... \n", __FUNCTION__);
				goto fail;
				
			}
		}else{
			NF_MSG_ERR("%s: read IBT and IBT back-up with HW ECC fails......\n", __FUNCTION__);
			goto fail;
		}

	}

	//dump_BBT(mtd);

	if (temp_IBT)
		kfree(temp_IBT);

	return rc;

success:
	this->use_ibt = 1;
	if (temp_IBT)
		kfree(temp_IBT);
	//scan & load bbt
	rc = this->scan_bbt (mtd);
	return rc;

fail:
	this->use_ibt = 0;
	if (temp_IBT)
		kfree(temp_IBT);
	//try read bbt
	rc = this->scan_bbt (mtd);
	return rc;
}

#else

static int rtk_nand_scan_bbt(struct mtd_info *mtd)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	int rc = 0;
	__u8 isbbt_b1, isbbt_b2;
	u8 *temp_BBT=0;
	u8 mem_page_num, page_counter=0;
	unsigned int i=0;

	RTK_FLUSH_CACHE((unsigned long) this->bbt, sizeof(BB_t)*RBA);
	mem_page_num = (sizeof(BB_t)*RBA + page_size-1 )/page_size;
	temp_BBT = kmalloc( mem_page_num*page_size, GFP_KERNEL );
	if ( !temp_BBT ){
		printk("%s: Error, no enough memory for temp_BBT\n",__FUNCTION__);
		return -ENOMEM;
	}
	memset( temp_BBT, 0xff, mem_page_num*page_size);

	rc = this->read_ecc_page(mtd, 0, ppb, this->g_databuf, this->g_oobbuf);
	
	isbbt_b1 = this->g_oobbuf[0];
	printk("[%s][%d]this->g_oobbuf[0] = %x\n",__FUNCTION__,__LINE__, this->g_oobbuf[0]);
	if ( !rc ){
		if ( isbbt_b1 == BBT_TAG ){
			printk("[%s] have created bbt B1, just loads it !!\n", __FUNCTION__);
			memcpy( temp_BBT, this->g_databuf, page_size );
			page_counter++;
			mem_page_num--;

			while( mem_page_num>0 ){
				if ( this->read_ecc_page(mtd, 0, ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
					printk("[%s] load bbt B1 error!!\n", __FUNCTION__);
					kfree(temp_BBT);
					return -1;
				}
				memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;
			}
			memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
		}
		else{
			printk("[%s] read BBT B1 tags fails, try to load BBT B2\n", __FUNCTION__);
			rc = this->read_ecc_page(mtd, 0, ppb<<1, this->g_databuf, this->g_oobbuf);
			isbbt_b2 = this->g_oobbuf[0];	
			printk("[%s][%d]this->g_oobbuf[0] = %x\n",__FUNCTION__,__LINE__, this->g_oobbuf[0]);
			if ( !rc ){
				if ( isbbt_b2 == BBT_TAG ){
					printk("[%s] have created bbt B2, just loads it !!\n", __FUNCTION__);
					memcpy( temp_BBT, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;

					while( mem_page_num>0 ){
						if ( this->read_ecc_page(mtd, 0, 2*ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
							printk("[%s] load bbt B2 error!!\n", __FUNCTION__);
							kfree(temp_BBT);
							return -1;
						}
						memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
						page_counter++;
						mem_page_num--;
					}
					memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
				}else{
					printk("[%s] read BBT B2 tags fails, nand driver will creat BBT B1 and B2\n", __FUNCTION__);
					rtk_create_bbt(mtd, ppb);
					rtk_create_bbt(mtd, ppb<<1);
				}
			}else{
				printk("[%s] read BBT B2 with HW ECC fails, nand driver will creat BBT B1\n", __FUNCTION__);
				rtk_create_bbt(mtd, ppb);
			}
		}
	}else{
		printk("[%s] read BBT B1 with HW ECC error, try to load BBT B2\n", __FUNCTION__);
		rc = this->read_ecc_page(mtd, 0, ppb<<1, this->g_databuf, this->g_oobbuf);
		isbbt_b2 = this->g_oobbuf[0];	
		if ( !rc ){
			if ( isbbt_b2 == BBT_TAG ){
				printk("[%s] have created bbt B1, just loads it !!\n", __FUNCTION__);
				memcpy( temp_BBT, this->g_databuf, page_size );
				page_counter++;
				mem_page_num--;

				while( mem_page_num>0 ){
					if ( this->read_ecc_page(mtd, 0, 2*ppb+page_counter, this->g_databuf, this->g_oobbuf) ){
						printk("[%s] load bbt B2 error!!\n", __FUNCTION__);
						kfree(temp_BBT);
						return -1;
					}
					memcpy( temp_BBT+page_counter*page_size, this->g_databuf, page_size );
					page_counter++;
					mem_page_num--;
				}
				memcpy( this->bbt, temp_BBT, sizeof(BB_t)*RBA );
			}else{
				printk("[%s] read BBT B2 tags fails, nand driver will creat BBT B2\n", __FUNCTION__);
				rtk_create_bbt(mtd, ppb<<1);
			}
		}else{
			printk("[%s] read BBT B1 and B2 with HW ECC fails\n", __FUNCTION__);
			kfree(temp_BBT);
			return -1;
		}
	}

	dump_BBT(mtd);

	if (temp_BBT)
		kfree(temp_BBT);
	
	return rc;
}
#endif
#endif

int rtk_nand_scan(struct mtd_info *mtd, int maxchips)
{
	struct nand_chip *this = (struct nand_chip *)mtd->priv;
	unsigned char id[6];
	unsigned int device_size=0;
	unsigned int i;
	unsigned int nand_type_id ;
	int rtk_lookup_table_flag=0;
	unsigned char maker_code;	
	unsigned char device_code; 
	unsigned char B5th;
	unsigned char B6th;
	unsigned int block_size;
	unsigned int num_chips = 1;
	uint64_t chip_size=0;
	unsigned int num_chips_probe = 1;
	uint64_t result = 0;
	uint64_t div_res = 0;
	unsigned int flag_size, mempage_order;
	
	if ( !this->select_chip )
		this->select_chip = nand_select_chip;
	if ( !this->scan_bbt )
#ifdef CONFIG_MTD_NAND_RBT
		this->scan_bbt = init_table;
#else
		this->scan_bbt = rtk_nand_scan_bbt;
#endif

	this->active_chip = 0;
	this->select_chip(mtd, 0);

	mtd->name = "rtk_nand";

#if NAND_POWEROFF_CARDREADER_WITH_MULTI_READ
	NF_rtkcr_get_gpio();
	NF_MSG_INFO("(V)NAND_POWEROFF_CARDREADER_WITH_MULTI_READ\n");
#else
	NF_MSG_INFO("(X)NAND_POWEROFF_CARDREADER_WITH_MULTI_READ\n");
#endif

#if NAND_READ_SKIP_UPDATE_BBT
	NF_MSG_INFO("(V)NAND_READ_SKIP_UPDATE_BBT\n");
#else
	NF_MSG_INFO("(X)NAND_READ_SKIP_UPDATE_BBT\n");
#endif

	while (1) {
		this->read_id(mtd, id);

		this->maker_code = maker_code = id[0];
		this->device_code = device_code = id[1];
		nand_type_id = maker_code<<24 | device_code<<16 | id[2]<<8 | id[3];
		B5th = id[4];
		B6th = id[5];

		NF_MSG_INFO("READ ID:0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",id[0],id[1],id[2],id[3],id[4],id[5]);		

		for (i=1;  i<maxchips; i++) {
			this->select_chip(mtd, i);
			this->read_id(mtd, id);
			if ( maker_code !=  id[0] ||device_code != id[1] )
				break;
		}
		
		num_chips_probe = i;
		NF_MSG_INFO("NAND Flash Controller detects %d dies\n", num_chips_probe);
		
		for (i = 0; nand_device[i].name; i++){
			
			if ( nand_device[i].id==nand_type_id && 
				((nand_device[i].CycleID5th==0xff)?1:(nand_device[i].CycleID5th==B5th))&&
				((nand_device[i].CycleID6th==0xff)?1:(nand_device[i].CycleID6th==B6th))){
				
				REG_WRITE_U32( REG_TIME_PARA1,nand_device[i].T1);
				REG_WRITE_U32( REG_TIME_PARA2,nand_device[i].T2);
				REG_WRITE_U32( REG_TIME_PARA3,nand_device[i].T3);
				
				this->ecc_safe_value = nand_device[i].ecc_safe_value;
				
				if (nand_device[i].size == num_chips_probe * nand_device[i].chipsize){
					if ( num_chips_probe == nand_device[i].num_chips ){
						NF_MSG_INFO("One %s chip has %d die(s) on board\n", nand_device[i].name, nand_device[i].num_chips);
						
						mtd->PartNum = nand_device[i].name;
						device_size = nand_device[i].size;
						chip_size = nand_device[i].chipsize;
						page_size = nand_device[i].PageSize;
						block_size = nand_device[i].BlockSize;
						oob_size = nand_device[i].OobSize;
						num_chips = nand_device[i].num_chips;
						isLastPage = nand_device[i].isLastPage;
						rtk_lookup_table_flag = 1;
						
						NF_MSG_INFO("nand part=%s, id=%x, device_size=%llu, chip_size=%llu, num_chips=%d, page_size=%d, isLastPage=%d\n", 
							nand_device[i].name, nand_device[i].id, nand_device[i].size, nand_device[i].chipsize, 
							nand_device[i].num_chips, nand_device[i].PageSize,nand_device[i].isLastPage);
						NF_MSG_INFO("eccBits=%d, ecc_safe_value = 0x%d \n", nand_device[i].eccSelect, this->ecc_safe_value);
						break;
					}				
				}else{
					if ( !strcmp(nand_device[i].name, "HY27UF084G2M" ) )
						continue;
					else{	
						NF_MSG_INFO("We have %d the same %s chips on board\n", num_chips_probe/nand_device[i].num_chips, nand_device[i].name);
						
						mtd->PartNum = nand_device[i].name;
						device_size = nand_device[i].size;
						chip_size = nand_device[i].chipsize;	
						page_size = nand_device[i].PageSize;
						block_size = nand_device[i].BlockSize;
						oob_size = nand_device[i].OobSize;
						num_chips = nand_device[i].num_chips;
						isLastPage = nand_device[i].isLastPage;
						rtk_lookup_table_flag = 1;
						
						NF_MSG_INFO("nand part=%s, id=%x, device_size=%llu, chip_size=%llu, num_chips=%d, isLastPage=%d\n", 
							nand_device[i].name, nand_device[i].id, nand_device[i].size, nand_device[i].chipsize, nand_device[i].num_chips, nand_device[i].isLastPage);
						NF_MSG_INFO("eccBits=%d, ecc_safe_value = 0x%d \n", nand_device[i].eccSelect, this->ecc_safe_value);
						break;
					}
				}
			}
		}

		if ( !rtk_lookup_table_flag ){
			NF_MSG_ERR("Lookup Table do not have this nand flash !!\n");
			NF_MSG_ERR("%s: Manufacture ID=0x%02x, Chip ID=0x%02x, "
					"3thID=0x%02x, 4thID=0x%02x, 5thID=0x%02x, 6thID=0x%02x\n",
					mtd->name, id[0], id[1], id[2], id[3], id[4], id[5]);
			return -1;
		}
		
		this->page_shift = generic_ffs(page_size)-1; 
		this->phys_erase_shift = generic_ffs(block_size)-1;
		
		this->oob_shift = generic_ffs(oob_size)-1;
		ppb = this->ppb = block_size >> this->page_shift;
		
		if (chip_size){
			this->block_num = chip_size >> this->phys_erase_shift;
			this->page_num = chip_size >> this->page_shift;
			this->chipsize = chip_size;
			this->device_size = device_size;
			this->chip_shift =  generic_ffs(this->chipsize )-1;
		}

		this->pagemask = (this->chipsize >> this->page_shift) - 1;
	
		mtd->oobsize = this->oob_size = oob_size;

		mtd->writesize = mtd->oobblock = page_size;//add by alexchang 0923-2010
		//mtd->subpagesize = page_size;
		mtd->erasesize = block_size;
#ifdef CONFIG_MTD_NAND_RBT
		this->block_size = block_size;
		this->page_size = page_size;	
#endif
		this->ecc_select = nand_device[i].eccSelect;//add by alexchang 0617-2011.
		g_eccSelect = this->ecc_select;

		this->eccmode = MTD_ECC_RTK_HW;

		if((this->ecc_select==0x0)||(this->ecc_select==0xc))
			mtd->eccsize = 512;
		else
			mtd->eccsize = 1024;

		ptr_device = &nand_device[i];
		break;
	}

	this->select_chip(mtd, 0);
			
	if (num_chips != num_chips_probe)
		this->numchips = num_chips_probe;
	else
		this->numchips = num_chips;
	div_res = mtd->size = this->numchips * this->chipsize;
#ifdef CONFIG_MTD_NAND_RBT
	this->bootcode_size = g_BootcodeSize;
	this->secstore_start = g_BootcodeSize;
	this->secstore_size = g_Secure_store_Size;
#endif

#ifndef CONFIG_MTD_NAND_RBT
	do_div(div_res,block_size);
	result = div_res;
	result*=this->RBA_PERCENT;
	do_div(result,100);
	RBA = this->RBA = result;

	if(mtd->u32RBApercentage)
		mtd->u32RBApercentage = this->RBA_PERCENT;
	
	NF_MSG_INFO("RBAPercentage %d%%  , RBA = 0x%x \n",mtd->u32RBApercentage, RBA);
	this->bbt = kmalloc( sizeof(BB_t)*RBA, GFP_KERNEL );

	if ( !this->bbt ){
		NF_MSG_ERR("%s: No enough memory for BBT\n",__FUNCTION__);
		return -1;
	}
	memset(this->bbt, 0,  sizeof(BB_t)*RBA); 

#ifdef CONFIG_MTD_NAND_IBT
	//ibt
	IBT_LEN = this->block_num;
	this->ibt = kmalloc( sizeof(IB_t)*IBT_LEN, GFP_KERNEL );
	if ( !this->ibt ){
		NF_MSG_ERR("%s: No enough memory for IBT\n",__FUNCTION__);
		return -1;
	}
	memset(this->ibt, 0,  sizeof(IB_t)*IBT_LEN);
#endif
#endif

	this->g_databuf = kmalloc( page_size, GFP_KERNEL );
	if ( !this->g_databuf ){
		NF_MSG_ERR("%s: No enough memory for g_databuf\n",__FUNCTION__);
		return -ENOMEM;
	}
	memset(this->g_databuf, 0xff, page_size);

	this->g_oobbuf = kmalloc( oob_size, GFP_KERNEL );
	if ( !this->g_oobbuf ){
		NF_MSG_ERR("%s: No enough memory for g_oobbuf\n",__FUNCTION__);
		return -ENOMEM;
	}
	memset(this->g_oobbuf, 0xff, oob_size);

	flag_size =  (this->numchips * this->page_num) >> 3;
	mempage_order = get_order(flag_size);
	
//	if(mempage_order<13)
	{
		this->erase_page_flag = (void *)__get_free_pages(GFP_KERNEL, mempage_order);	
		if ( !this->erase_page_flag ){
			NF_MSG_ERR("%s: No enough memory for erase_page_flag\n",__FUNCTION__);
			return -ENOMEM;
		}
		memset ( (__u32 *)this->erase_page_flag, 0, flag_size);
	}

	mtd->type				= MTD_NANDFLASH;
	mtd->flags			= MTD_CAP_NANDFLASH;
	mtd->ecctype		= MTD_ECC_NONE;
	mtd->_erase			= nand_erase;
	mtd->_point			= NULL;
	mtd->_unpoint		= NULL;
	mtd->_read				= nand_read;
	mtd->_write			= nand_write;
	mtd->_read_ecc		= nand_read_ecc;
	mtd->_write_ecc		= nand_write_ecc;
	mtd->_read_oob		= nand_read_oob;
	mtd->_write_oob	= 	nand_write_oob;
	//for access bootcode area
	mtd->_erase_bootcode_area = nand_erase_bootcode_area;
	mtd->_write_bootcode_area = nand_write_bootcode_area;
	mtd->_read_bootcode_area = nand_read_bootcode_area;
	mtd->_write_profile = nand_write_profile;
	mtd->_readv			= NULL;
	mtd->_writev			= NULL;
	mtd->_readv_ecc	= NULL;
	mtd->_writev_ecc	= NULL; 
	mtd->_sync			= nand_sync;
	mtd->_lock				= NULL;
	mtd->_unlock			= NULL;
	mtd->_suspend		= nand_suspend;
	mtd->_resume		= nand_resume;
	mtd->owner			= THIS_MODULE;

	mtd->_block_isbad			= nand_block_isbad;
	mtd->_block_markbad	= nand_block_markbad;
	mtd->_panic_write = panic_nand_write;
#ifdef CONFIG_MTD_NAND_RBT
	mtd->_reload_bbt = rtk_nand_reload_bbt;
#else
	mtd->_reload_bbt = rtk_nand_scan_bbt;
#endif
	
	mtd->owner = THIS_MODULE;
#if 0
	/* =========================== for MP usage =======================*/
	mp_time_para = (char *) NF_parse_token(platform_info.system_parameters, "mp_time_para");
	if ( mp_time_para && strlen(mp_time_para) )
		mp_time_para_value = simple_strtoul(mp_time_para, &mp_time_para, 10);

	if ( mp_time_para_value ){
		/* reset the optimal speed */
		REG_WRITE_U32( REG_TIME_PARA1,mp_time_para_value);
		REG_WRITE_U32( REG_TIME_PARA2,mp_time_para_value);
		REG_WRITE_U32( REG_TIME_PARA3,mp_time_para_value);
	}

	/* get nf_clock from /sys/realtek_boards/system_parameters */
	nf_clock = (char *) NF_parse_token(platform_info.system_parameters, "nf_clock");
	if ( nf_clock && strlen(nf_clock) )
		nf_clock_value = simple_strtoul(nf_clock, &nf_clock, 10);

	if ( nf_clock_value )
		NF_CKSEL(mtd->PartNum, nf_clock_value);

	/* get mp_erase_nand from /sys/realtek_boards/system_parameters */
	mp_erase_nand = (char *) NF_parse_token(platform_info.system_parameters, "mp_erase_nand");
	//printk("mp_erase_nand=%s\n", mp_erase_nand);
	if ( mp_erase_nand && strlen(mp_erase_nand) )
		mp_erase_flag = simple_strtoul(mp_erase_nand, &mp_erase_nand, 10);
	//printk("mp_erase_flag=%d\n", mp_erase_flag);
	
	if ( mp_erase_flag ){
		int start_pos = 0;
		int start_page = (start_pos/mtd->erasesize)*ppb;

		unsigned long long block_num = mtd->size - start_pos;

		do_div(block_num,mtd->erasesize); 
		//int block_num = (mtd->size - start_pos)/mtd->erasesize;
		//printk("start_page=%d, block_num=%d\n", start_page, block_num);
		printk("Starting erasure all contents of nand for MP.\n");
		TEST_ERASE_ALL(mtd, start_page, block_num);
		this->select_chip(mtd, 0);
		return 0;
	}

	/* CMYu, 20090720, get mcp from /sys/realtek_boards/system_parameters */
	mcp = (char *) NF_parse_token(platform_info.system_parameters, "mcp");
	//printk("mcp=%s\n", mcp);
	if (mcp){
		if ( strstr(mcp, "ecb") )
			this->mcp = MCP_AES_ECB;
		else if ( strstr(mcp, "cbc") ) 
			this->mcp = MCP_AES_CBC;
		else if ( strstr(mcp, "ctr") )
			this->mcp = MCP_AES_CTR;
		else
			this->mcp = MCP_NONE;			
	}
#endif	
	//for MCP test
	//this->mcp = MCP_AES_ECB;
	//printk("[%s] this->mcp=%d\n", __FUNCTION__, this->mcp);
			
	/* =========== WE Over spec: Underclocking lists: ========== */
	switch(nand_type_id){
		case HY27UT084G2M:	//WE: 40 ns
			//NF_CKSEL(mtd->PartNum, 0x04);	//43.2 MHz
			break;
		case HY27UF081G2A:	//WE: 15 ns
		case HY27UF082G2A:
		case K9G4G08U0A:
		case K9G8G08U0M:
		case TC58NVG0S3C:
		case TC58NVG1S3C:
		case HY27UT084G2A:
			NF_CKSEL(mtd->PartNum, 0x03);	//54 MHz
			break;
		default:
			;
	}	

	//setting edo mode
	this->edo_setting();
	
#ifdef NAND_FLASH_DEBUG
	//for debug nand flash write/read/erase function
	TEST_ERASE_ALL(mtd, 0, 1);
	TEST_READ_WRITE(mtd, 0);
#endif
#ifndef CONFIG_MTD_NAND_RBT
#ifdef CONFIG_MTD_NAND_IBT
	return rtk_nand_scan_ibt_bbt(mtd);
#else
	return this->scan_bbt (mtd);
#endif
#else
	return init_table(mtd);
#endif
	
}

#ifdef NAND_FLASH_DEBUG
static int TEST_ERASE_ALL(struct mtd_info *mtd, int page, int bc)
{
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	int i;
	int chip_block_num = this->block_num;
	int start_block = page/ppb;
	int block_in_die; 
	int rc = 0;
	int chipnr =0, block;
	
	if ( page & (ppb-1) ){
		page = (page/ppb)*ppb;
	}

	for ( i=0; i<bc; i++){
		block_in_die = start_block + i;
		chipnr = block_in_die/chip_block_num;

		this->active_chip=chipnr=0;		
		block = block_in_die%chip_block_num;
		this->select_chip(mtd, block_in_die/chip_block_num);
		rc = this->erase_block(mtd, chipnr, block*ppb);
		if ( rc<0 ){
			this->g_oobbuf[0] = 0x00;
			if ( isLastPage ){
				this->write_oob(mtd, chipnr, block*ppb+ppb-1, oob_size, this->g_oobbuf);
				this->write_oob(mtd, chipnr, block*ppb+ppb-2, oob_size, this->g_oobbuf);
			}else{
				this->write_oob(mtd, chipnr, block*ppb, oob_size, this->g_oobbuf);
				this->write_oob(mtd, chipnr, block*ppb+1, oob_size, this->g_oobbuf);
			}
		}
	}

	return 0;
}

static int TEST_READ_WRITE(struct mtd_info *mtd, int page)
{
	struct nand_chip *this = (struct nand_chip *) mtd->priv;
	unsigned int chipnr=0;
	unsigned int i=0;
	
	memset(this->g_databuf, 0x00 , mtd->oobblock);
	this->g_databuf[0] = 0x11;
	this->g_databuf[1] = 0x22;
	this->g_databuf[2] = 0x33;
	this->g_databuf[3] = 0x44;
	this->g_databuf[4] = 0x55;
	
	memset(this->g_oobbuf, 0xff , 64);
	this->g_oobbuf[0] = 0xff;
	this->g_oobbuf[1] = 0x55;
	this->g_oobbuf[2] = 0x11;
	this->g_oobbuf[3] = 0x22;
	this->g_oobbuf[4] = 0x33;

	this->write_ecc_page(mtd, chipnr, page, this->g_databuf, this->g_oobbuf, 1);

	//redifine g_databuf value
	memset(this->g_databuf, 0xff , mtd->oobblock);
	memset(this->g_oobbuf, 0x00 , 64);

	this->read_ecc_page(mtd, chipnr, page, this->g_databuf, this->g_oobbuf);
	printk("\n-------------------------------------------------------read write test starting-------------------------------\n");
	for(i = 0; i< 2048; i++){
		if((i%16)==0)
			printk("\n");
		
		printk("0x%x\t", this->g_databuf[i]);
	}

	printk("\n\noob data:\n");
	for(i = 0; i < 64; i++){
		if((i%16)==0)
			printk("\n");
		
		printk("0x%x\t", this->g_oobbuf[i]);

	}
	printk("\n-------------------------------------------------------read write test ending--------------------------------\n");

	return 0;

}
#endif
