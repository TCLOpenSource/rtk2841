#include <linux/module.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include<linux/slab.h>	
#include <linux/delay.h>
#include <linux/semaphore.h>
#include <linux/dma-direction.h>
#include <linux/dma-mapping.h>
//#include <rtk_kdriver/rtk_md.h>
#include <asm/cacheflush.h>
#include <mach/platform.h>
#include "../mtdcore.h"
#include "rtk_spinor.h"

//#define CONFIG_RTK_SPI_WP_HW

/************************************************************************
 *  Defines SFC registers
 ************************************************************************/
#define SPI_BASE_ADDR	0xb8200000	/* NOR flash start addess */
#define REG_SFC_BASE	 0xb801a800
#define SPI_REG_NUM     12

#define REG_SFC_OPCODE		(REG_SFC_BASE + 0x00)
#define REG_SFC_CTL			(REG_SFC_BASE + 0x04)
#define REG_SFC_SCK			(REG_SFC_BASE + 0x08)
#define REG_SFC_CE			(REG_SFC_BASE + 0x0c)
#define REG_SFC_WP			(REG_SFC_BASE + 0x10)
#define REG_SFC_POS_LATCH	(REG_SFC_BASE + 0x14)
#define REG_SFC_WAIT_WR		(REG_SFC_BASE + 0x18)
#define REG_SFC_EN_WR		(REG_SFC_BASE + 0x1c)
#define REG_SFC_FAST_RD		(REG_SFC_BASE + 0x20)
#define REG_SFC_SCK_TAP		(REG_SFC_BASE + 0x24)
#define REG_SF_32MB_EN		(REG_SFC_BASE + 0x28)
#define REG_SPI_NAND_0		(REG_SFC_BASE + 0x2c)
#define SB2_CTRL_REG                 0xb801A960

/* REG_SFC_OPCODE */
#define DUAL_QUAL_MODE_OFFSET 9
#define DUAL_QUAL_MODE_MASE 0xF
#define FAT_MODE_OFFSET (8)
#define CMD_MASK  0xff
#define NORMAL_MODE    ((0b0000&DUAL_QUAL_MODE_MASE)<<DUAL_QUAL_MODE_OFFSET)
#define DUAL_READ_MODE ((0b0001&DUAL_QUAL_MODE_MASE)<<DUAL_QUAL_MODE_OFFSET)
#define QUAD_READ_MODE ((0b0101&DUAL_QUAL_MODE_MASE)<<DUAL_QUAL_MODE_OFFSET)

#define CMD_READ_ID                 0x9f
#define CMD_READ_STATUS1            0x05
#define CMD_READ_STATUS2            0x35
#define CMD_READ_STATUS3            0x15
#define CMD_WRITE_ENABLE            0x06
#define CMD_WRITE_STATUS1           0X01
#define CMD_WRITE_STATUS2           0X31
#define CMD_WRITE_STATUS3           0X11
#define CMD_PAGE_PROGRAM            0x02
#define CMD_PAGE_PROGRAM_QUAD       0x32
#define CMD_READ_NORMAL             0x03
#define CMD_READ_NORMAL_FAST        0x0b
#define CMD_READ_DUAL_FAST          0x3b
#define CMD_READ_QUAD_FAST          0x6b
#define CMD_ERASE_BLOCK_64K         0xd8
#define CMD_ERASE_BLOCK_32K         0x52
#define CMD_ERASE_SECTOR_4K         0x20
#define CMD_ENABLE_RESET               0x66
#define CMD_RESET                             0x99

#define STATUS_QE_S9                (1<<0x01)

/* REG_SFC_CTL	*/
#define DATA_EN_OFFSET     (4)
#define ADDR_EN_OFFSET     (3)
#define DMY_CNT_OFFSET     (0)
#define DMY_CNT_MASK       (0x7)

/* REG_SFC_SCK */
#define MODE_OFFSET         8
#define FDIV_MASK           0xff
#define FDIV_OFFSET         0

/* REG_SFC_EN_WR */
#define WT_PROG_EN_OFFSET   (8)
#define WR_EN_OP_OFFSET     (0)
#define WR_EN_OP_MASK     (0xff)

/* REG_SFC_CE */
#define TDT_OFFSET          (16)
#define TDT_MASK           (0xffff)
#define PHCNT_OFFSET         (8)
#define PHCNT_MASK         (0xff)
#define PLCNT_OFFSET          0
#define PLCNT_MASK          (0xff)


/* REG_SFC_POS_LATCH */
#define POS_LATCH_OFFSET  0
#define POS_LATCH_FALL    0
#define POS_LATCH_RISE    1
#define DELAY_SEL_MASK    0x07

/* REG_SFC_WAIT_WR */
#define WT_PROG_DONE_OFFSET   (8)
#define RDSR_OP_OFFSET     (0)
#define RDSR_OP_MASK     (0Xff)

/* SPI STATUS REGISTER */
#define WIP_OFFSET 0
#define WEL_OFFSET 1
#define STATUS_WIP			0x01

/************************************************************************
 *  Defines Move Data Engine registers
 ************************************************************************/
#define REG_MD_FDMA_DDR_SADDR	(0xb800b088)
#define REG_MD_FDMA_FL_SADDR	(0xb800b08c)
#define REG_MD_FDMA_CTRL2		(0xb800b090)
#define REG_MD_FDMA_CTRL1		(0xb800b094)
#define REG_MD_SMQ_INT_STATUS	(0xb800b004)

/* REG_MD_FDMA_CTRL2 */
#define FORWART_MAPPINT_OFFSET   29
#define FDMA_SWAP_OFFSET         28
#define SWAP_VALUE                1
#define FDMA_MAX_XFER_OFFSET     26
#define SET_DMA_LEN               3
#define SET_DMA_LEN_512           2
#define FDMA_DIR_OFFSET          25
#define FLASH_2_DDR               0
#define DDR_2_FLASH               1
#define FDMA_LEN_MASK      0x1ffffff
#define FDMA_LEN_OFFSET           0

/* REG_MD_FDMA_CTRL1 */
#define WRITE_EN1_OFFSET 1
#define FDMA_GO_OFFSET 0

/* REG_MD_SMQ_INT_STATUS */
#define FDMA_DONE_INIT_STATUS_OFFSET 4

/************************************************************************
 *  Define misc
 ************************************************************************/
#define SFC_DELAY 100
#define SFC_DELAY_TW 5000           // write status register cycle time
#define SN_SYNC	                __asm__ __volatile__ ("DSB;")
#define SUSPEND_TIMEOUT    25000
#define ERASE_DATA_TIMEOUT 25000 // 2500ms
#define WRITE_DATA_TIMEOUT 100   // 5ms
#define SET_FEATURE_TIMEOUT 1000   // 50ms

#define SFC_WP_MASK_BIT2_TO_BIT7 0xfc
#define SFC_WP_MASK_BIT6         0x40
#define SFC_WP_MASK_BIT2         0x04
/************************************************************************
 ************************************************************************
 ************************************************************************/
static const char *ptypes[] = {"cmdlinepart", NULL};

/* Global Variables */
struct mtd_info *rtk_spinor_mtd;

DEFINE_SEMAPHORE(sem_SFC_NOR);

struct semaphore sem_SFC_NOR;

static int sfc_init(spinor_chip_t *spinor_chip);
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
 char *rtk_sfc_parse_token(const char *parsed_string, const char *token)
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
//**************************************************************************
unsigned char* rtk_sfc_getBootType(void)
{
    unsigned char *param;

    param=(char *)rtk_sfc_parse_token(platform_info.system_parameters,"boot_flash");

    return param;
}
//**************************************************************************
int rtk_sfc_get_package_216(void)
{
        unsigned char *param = NULL;
        int package_216 = 1;

        param=(char *)rtk_sfc_parse_token(platform_info.system_parameters, "package_216");
        if(param)
                package_216 = simple_strtoul(param, (char**)&package_216, 10);

        return package_216;
}
//**************************************************************************
static int sfc_check_pin_mux(void)
{
        volatile unsigned int regval1;
        volatile unsigned int regval2;

        regval1 = rtd_inl(0xb8000868);
        regval2 = rtd_inl(0xb800086c);
        if(((regval1 & 0xf0f0f0f0) != 0x20202020) || ((regval2&0xf0f00000) != 0x20200000))
        {
                
                SFC_MSG_ERR("the spi pin mux error: 0xb8000868: %x 0xb800086c:%x!!\n", regval1, regval2);
            
        }

        // pinmux 
        rtd_outl(0xb8000868, 0x20202020);
        rtd_outl(0xb800086c, 0x20200000);
        return 0;
}

//**************************************************************************
static int rtk_sfc_init_condition_check(void)
{
        unsigned char *ptr;
        int ret = 0;
        
        ptr = rtk_sfc_getBootType();
        if(ptr == NULL)
        {
                printk("[Warning]Can't get boot type!spi nor flash driver init exit....\n");
	   ret = -1;
                goto error;
        }
        else
        {
	    if(memcmp(ptr, "spi", 3) != 0){
		printk("Boottype %s!spi nor flash driver init exit....\n",ptr);
		ret = -1;
                           goto error;
                }
        }
        
        if(sfc_check_pin_mux() == -1)
        {
                ret = -1;
                goto error;
        }
        
        printk("Boottype %s!spi nor flash driver init continue....\n",ptr);

error:
        return ret;
}

void sfc_debug(void)
{
    printk("\n%x: %x\n", REG_SFC_OPCODE, rtd_inl(REG_SFC_OPCODE));
    printk("%x: %x\n", REG_SFC_CTL,    rtd_inl(REG_SFC_CTL));
    printk("%x: %x\n", REG_SFC_SCK,    rtd_inl(REG_SFC_SCK));
    printk("%x: %x\n", REG_SFC_CE,     rtd_inl(REG_SFC_CE));
    printk("%x: %x\n", REG_SFC_WP,     rtd_inl(REG_SFC_WP));
    printk("%x: %x\n", REG_SFC_POS_LATCH, rtd_inl(REG_SFC_POS_LATCH));
    printk("%x: %x\n", REG_SFC_WAIT_WR, rtd_inl(REG_SFC_WAIT_WR));
    printk("%x: %x\n", REG_SFC_EN_WR,   rtd_inl(REG_SFC_EN_WR));
    printk("%x: %x\n", REG_SFC_FAST_RD	,   rtd_inl(REG_SFC_FAST_RD));
    printk("%x: %x\n", REG_SFC_SCK_TAP,   rtd_inl(REG_SFC_SCK_TAP));
    printk("%x: %x\n", REG_SF_32MB_EN	,   rtd_inl(REG_SF_32MB_EN));
    printk("%x: %x\n", REG_SPI_NAND_0,   rtd_inl(REG_SPI_NAND_0));

    return;
}

static unsigned int swap_endian(unsigned int input)
{
	unsigned int output;

	output = (input & 0xff000000)>>24|
			 (input & 0x00ff0000)>>8|
			 (input & 0x0000ff00)<<8|
			 (input & 0x000000ff)<<24;

	return output;
}

static void sfc_enable_write(void)
{
    unsigned char tmp;
	rtd_outl(REG_SFC_OPCODE, CMD_WRITE_ENABLE);
	rtd_outl(REG_SFC_CTL, 0x00);  // data_en=0 addr_en=0 dmy=0	
	SN_SYNC;
	udelay(SFC_DELAY); 	
	tmp = rtd_inb(SPI_BASE_ADDR);
    return;
}
static void sfc_get_feature(unsigned char rdsr, unsigned char *data)
{
    SN_SYNC;
    rtd_outl(REG_SFC_OPCODE, rdsr & CMD_MASK);
    rtd_outl(REG_SFC_CTL, 1<<DATA_EN_OFFSET);
    SN_SYNC;

    udelay(SFC_DELAY); 
    *data = rtd_inb(SPI_BASE_ADDR);
    SN_SYNC;
    return;
}

static int sfc_set_feature(unsigned char wrsr, unsigned char data)
{
    unsigned char tmp;
    int ret = 0, retry = 0;
    
    sfc_enable_write();
    
    rtd_outl(REG_SFC_OPCODE, wrsr & CMD_MASK); 
	rtd_outl(REG_SFC_CTL, 1<<DATA_EN_OFFSET);
	SN_SYNC;
	udelay(SFC_DELAY); 
	rtd_outb(SPI_BASE_ADDR, data);
    
    do {
        udelay(SFC_DELAY);
        sfc_get_feature(CMD_READ_STATUS1, &tmp);
    } while ((tmp & STATUS_WIP)&&(++retry < SET_FEATURE_TIMEOUT));

    if (retry == SET_FEATURE_TIMEOUT) 
    {
        printk("%s wait timet out  0x%x\n",__FUNCTION__, tmp);
        ret = -1;
    }

    //sfc_get_feature(CMD_READ_STATUS1, &tmp);
    //if(tmp != data)
    //{
    //    printk("%s 0x%x != 0x%x\n", __FUNCTION__, tmp, data);
    //    return -1;
   // }

    return ret;
    //return;
}

static int sfc_set_feature_16bit(unsigned char wrsr, unsigned short data)
{
    unsigned char tmp;
    int ret = 0, retry = 0;
    
    sfc_enable_write();
	rtd_outl(REG_SFC_OPCODE, wrsr & CMD_MASK); 
	rtd_outl(REG_SFC_CTL, 1<<DATA_EN_OFFSET);
	asm("DSB");
	udelay(SFC_DELAY); 
	rtd_outw(SPI_BASE_ADDR, data);

    do {
        udelay(SFC_DELAY);
        sfc_get_feature(CMD_READ_STATUS1, &tmp);
    } while ((tmp & STATUS_WIP)&&(++retry < SET_FEATURE_TIMEOUT));

    if (retry == SET_FEATURE_TIMEOUT) 
    {
        printk("%s wait timet out  0x%x\n",__FUNCTION__, tmp);
        ret = -1;
    }
    return ret;
}

static int sfc_wait_erase_done(void)
{
    int ret = 0, retry = 0;
    unsigned char data = 0;
    
    do {
        udelay(SFC_DELAY);
        sfc_get_feature(CMD_READ_STATUS1, &data);
    } while ((data & STATUS_WIP)&&(++retry < ERASE_DATA_TIMEOUT));

    if (retry == ERASE_DATA_TIMEOUT) 
    {
        printk("%s wait timet out  0x%x\n",__FUNCTION__, data);
        ret = -1;
    }
    return ret;
}

static int sfc_wait_write_done(void)
{
    int ret = 0, retry = 0;
    unsigned char data = 0;
    
    do {
        udelay(SFC_DELAY);
        sfc_get_feature(CMD_READ_STATUS1, &data);
    } while ((data & STATUS_WIP)&&(++retry < WRITE_DATA_TIMEOUT));

    if (retry == WRITE_DATA_TIMEOUT) 
    {
        printk("%s wait timet out  0x%x\n",__FUNCTION__, data);
        ret = -1;
    }
    return ret;
}

static int sfc_wait_set_feature_done(void)
{
    int ret = 0, retry = 0;
    unsigned char data = 0;
    
    do {
        udelay(SFC_DELAY);
        sfc_get_feature(CMD_READ_STATUS1, &data);
    } while ((data & STATUS_WIP)&&(++retry < SET_FEATURE_TIMEOUT));

    if (retry == SET_FEATURE_TIMEOUT) 
    {
        printk("%s wait timet out  0x%x\n",__FUNCTION__, data);
        ret = -1;
    }
    printk("***11retry %d\n", retry);
    return ret;
}

// return 1 : quad enable  return 0: quad disable 
static int sfc_check_quad(spinor_info_t *spinor_info)
{
    unsigned char data = 0;

    sfc_get_feature(spinor_info->cmd_quad_rdsr, &data);
    if(data & spinor_info->cmd_quad_bit)
       return 1;
    else
       return 0;
}

static int sfc_enable_quad(spinor_info_t *spinor_info)
{
    unsigned char data = 0;
    unsigned char tmp = 0;
    unsigned short data_16bit = 0xffff;
    int ret = 0;

    if(spinor_info->id == WINBOND_W32Q64_64Mbit)
    {
        sfc_get_feature(CMD_READ_STATUS1, &data);
        data_16bit = data;
        sfc_get_feature(spinor_info->cmd_quad_rdsr, &data);
        data = data | spinor_info->cmd_quad_bit;
        data_16bit = ((data << 8) | data_16bit);  
        ret = sfc_set_feature_16bit(spinor_info->cmd_quad_wrsr, data_16bit);
        if(ret < 0)
        {
            return ret;
        }
        sfc_get_feature(spinor_info->cmd_quad_rdsr, &tmp);
        SFC_MSG_DEBUG("%s tmp:0x%x data:0x%x\n", __FUNCTION__, tmp, data);
        if(tmp != data)
        {
            SFC_MSG_DEBUG("%s 0x%x != 0x%x\n", __FUNCTION__, tmp, data);
            return -1;
        }
    }
    else
    {
        sfc_get_feature(spinor_info->cmd_quad_rdsr, &data);
        data = data | spinor_info->cmd_quad_bit;
        ret = sfc_set_feature(spinor_info->cmd_quad_wrsr, data);
        if(ret < 0)
        {
            return ret;
        }
        sfc_get_feature(spinor_info->cmd_quad_rdsr, &tmp);
        SFC_MSG_DEBUG("%s tmp:0x%x data:0x%x\n", __FUNCTION__, tmp, data);
        if(tmp != data)
        {
            SFC_MSG_DEBUG("%s 0x%x != 0x%x\n", __FUNCTION__, tmp, data);
            return -1;
        }
    }
    return ret;
}

static int sfc_disable_quad(spinor_info_t *spinor_info)
{
    unsigned char data = 0;
    int ret = 0;
    
    sfc_get_feature(spinor_info->cmd_quad_rdsr, &data);
    data = data & (~spinor_info->cmd_quad_bit);
    ret = sfc_set_feature(spinor_info->cmd_quad_wrsr, data);

    return ret;
}


static void switch_read_mode(spinor_info_t *spinor_info)
{
    switch(spinor_info->read_mode)
    {
        case eMODE_READ_NORMAL:
            rtd_outl(REG_SFC_OPCODE, (CMD_READ_NORMAL&CMD_MASK) | NORMAL_MODE); //switch flash to read mode
	        rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET)|(1<<ADDR_EN_OFFSET));    //data_en=1 addr_en=1 dmy_en=0
            break;
        case eMODE_READ_NORMAL_FAST:
            rtd_outl(REG_SFC_OPCODE, (CMD_READ_NORMAL_FAST&CMD_MASK) | NORMAL_MODE); //switch flash to read mode
	        rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET)|(1<<ADDR_EN_OFFSET) | ((1&DMY_CNT_MASK)<<DMY_CNT_OFFSET)); //data_en=1 addr_en=1 dmy_en=1
            break;
        case eMODE_READ_DUAL_FAST:
            rtd_outl(REG_SFC_OPCODE, (CMD_READ_DUAL_FAST&CMD_MASK) | DUAL_READ_MODE ); //switch flash to read mode
	        rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET)|(1<<ADDR_EN_OFFSET) | ((1&DMY_CNT_MASK)<<DMY_CNT_OFFSET)); //data_en=1 addr_en=1 dmy_en=1
            break;
        case eMODE_READ_QUAD_FAST:
            rtd_outl(REG_SFC_OPCODE, (CMD_READ_QUAD_FAST&CMD_MASK) | QUAD_READ_MODE); //switch flash to read mode
	        rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET)|(1<<ADDR_EN_OFFSET) | ((1&DMY_CNT_MASK)<<DMY_CNT_OFFSET)); //data_en=1 addr_en=1 dmy_en=1
            break;
        default:
            rtd_outl(REG_SFC_OPCODE, (CMD_READ_NORMAL&CMD_MASK) | NORMAL_MODE); //switch flash to read mode
	        rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET)|(1<<ADDR_EN_OFFSET));    //data_en=1 addr_en=1 dmy_en=0
            break;
    }
    
	asm("DSB");
}

static void switch_write_mode(spinor_info_t *spinor_info)
{
    if(spinor_info->write_mode == eMODE_WRITE_NORMAL)
    {
        //if(spinor_info->read_mode == eMODE_READ_QUAD_FAST)
       // {
       //     SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
       //     sfc_disable_quad();
       // }
        //issue write command
	    rtd_outl(REG_SFC_OPCODE, CMD_PAGE_PROGRAM & CMD_MASK);
	    rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET | 1<<ADDR_EN_OFFSET)); // data_en=1 addr_en=1 dmy_en=0
        asm("DSB");   
    }
    else if(spinor_info->write_mode == eMODE_WRITE_QUAD_FAST)
    {
        SFC_MSG_ERR("the spi dirver not surport write quad mode\n");
        //SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
        //sfc_enable_quad();
        //SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
        //rtd_outl(REG_SFC_OPCODE, (CMD_PAGE_PROGRAM_QUAD&CMD_MASK) | QUAD_READ_MODE); //switch flash to read mode
	    //rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET)|(1<<ADDR_EN_OFFSET) | ((1&DMY_CNT_MASK)<<DMY_CNT_OFFSET)); //data_en=1 addr_en=1 dmy_en=1
        //SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
        
    }
}

static void switch_erase_mode(spinor_info_t *spinor_info)
{
    SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
    asm("DSB");

    //if(spinor_info->read_mode == eMODE_READ_QUAD_FAST)
    //{
    //    sfc_disable_quad(spinor_info);
    //}

    return;
}
inline size_t sfc_memcpy(unsigned int dst, unsigned int src, size_t len) 
{
    size_t i;
    for (i=0; i<len; i++)
    {
        rtd_outb(((dst) + i) , rtd_inb((src) + i));
    }

    return len;
}

static void sfc_read_bytes(struct mtd_info* mtd, loff_t from, size_t len, size_t *retlen, u_char *buf)
{
    spinor_chip_t* spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
        
    switch_read_mode(spinor_info);
  
    *retlen = sfc_memcpy((unsigned int)buf, (SPI_BASE_ADDR+ (unsigned int)from), len);
    
    return;
}

extern void smd_checkComplete(void);
static void sfc_read_md(struct mtd_info* mtd, loff_t from, size_t len, size_t *retlen, const u_char  *buf)
{
    spinor_chip_t *spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
        
    switch_read_mode(spinor_info);
    smd_checkComplete();
    
    // set DDR and flash addr
    rtd_outl(REG_MD_FDMA_DDR_SADDR, (unsigned int)virt_to_phys(buf));
    rtd_outl(REG_MD_FDMA_FL_SADDR, (unsigned int)from);
    rtd_outl(REG_MD_FDMA_CTRL2, (1 << FORWART_MAPPINT_OFFSET) | (SET_DMA_LEN_512 << FDMA_MAX_XFER_OFFSET) | ((len&FDMA_LEN_MASK)<<FDMA_LEN_OFFSET) | (FLASH_2_DDR<<FDMA_DIR_OFFSET)); // forward map, no_swap, DMA LEN, FLASH to DDR               

    dmac_flush_range(buf, buf+len);
	outer_flush_range(virt_to_phys(buf), virt_to_phys(buf+len));

    SN_SYNC;
    rtd_outl(REG_MD_FDMA_CTRL1, (1<<WRITE_EN1_OFFSET) | (1<<FDMA_GO_OFFSET));

    while(rtd_inl(REG_MD_FDMA_CTRL1) & (1<<FDMA_GO_OFFSET)); // wait for MD done its operation 
	rtd_outl(REG_MD_SMQ_INT_STATUS, (1 << FDMA_DONE_INIT_STATUS_OFFSET));  // clear flash done bit

    *retlen = len;
    
    return;
}


static int sfc_write_bytes(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char  *buf) 
{
    int ret = 0;
    spinor_chip_t *spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);

    SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
    switch_write_mode(spinor_info);
    SFC_MSG_DEBUG("%s_%d\n", __FUNCTION__, __LINE__);
    *retlen = sfc_memcpy((SPI_BASE_ADDR+ (unsigned int)to), (unsigned int)buf, len);
    //mdelay(3);
    ret = sfc_wait_write_done();
    return ret;
}

/****************************************************************************
 * using MD to write data from DDR to FLASH which size is within a single page
 * pass-in address must be aligned on 4-bytes, and 
 * length must be multiples of 4-bytes
 *****************************************************************************/
static void sfc_write_md(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf) 
{
    spinor_chip_t *spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
    int ret = 0;
    
    switch_write_mode(spinor_info);
    
    // set DDR and flash addr
    rtd_outl(REG_MD_FDMA_DDR_SADDR, (unsigned int)virt_to_phys(buf));
    rtd_outl(REG_MD_FDMA_FL_SADDR, (unsigned int)to);
    rtd_outl(REG_MD_FDMA_CTRL2, (1 << FORWART_MAPPINT_OFFSET) | (SET_DMA_LEN_512<< FDMA_MAX_XFER_OFFSET) | ((len&FDMA_LEN_MASK)<<FDMA_LEN_OFFSET) | (DDR_2_FLASH<<FDMA_DIR_OFFSET)); // forward map, swap, DMA LEN, FLASH to DDR

    dmac_flush_range(buf, buf+len);
	outer_flush_range(virt_to_phys(buf), virt_to_phys(buf+len));
    
    SN_SYNC;
    rtd_outl(REG_MD_FDMA_CTRL1, (1<<WRITE_EN1_OFFSET) | (1<<FDMA_GO_OFFSET));

    while(rtd_inl(REG_MD_FDMA_CTRL1) & (1<<FDMA_GO_OFFSET)); // wait for MD done its operation 
	rtd_outl(REG_MD_SMQ_INT_STATUS, (1 << FDMA_DONE_INIT_STATUS_OFFSET));  // clear flash done bit

    SN_SYNC;
    *retlen = len;
    //mdelay(3);
    ret = sfc_wait_write_done();
    return;
}

static int sfc_verify_after_write(struct mtd_info* mtd, const u_char * to_verify, size_t len_verify, const u_char *buf_verify)
{
    spinor_chip_t *spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
    size_t i = 0;
    to_verify += SPI_BASE_ADDR;
    
	switch_read_mode(spinor_info);
    mdelay(10);
	//printk("\nverify1: (0x%x, 0x%x, 0x%x)\n", (unsigned int)to_verify, (unsigned int)buf_verify, len_verify);
	do {
		if (*to_verify != *buf_verify) {
			SFC_MSG_DEBUG("0x%08x -> 0x%02x,  0x%08x -> 0x%02x\n", (unsigned int)to_verify, *to_verify, (unsigned int)buf_verify, *buf_verify);
			return -1;
	    }
	to_verify++;
	buf_verify++;
	asm("DSB");
	} while (++i < len_verify);

    return 0;
}

static int sfc_erase_flash(struct mtd_info* mtd, loff_t from, size_t len)
{
    spinor_chip_t *spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
    loff_t erase_addr = SPI_BASE_ADDR + from;
    size_t erase_size = len;
    unsigned int cmd_erase = 0;
    unsigned char tmp;
    size_t size = 0;
    int ret = 0;
    
   if(spinor_info->min_erase_size == 0)
    {
        printk("the spi nor min_erase_size is not init\n");
        return -1;
    }
     
	if(len%spinor_info->min_erase_size != 0)
	{
		printk("the erase size is not align\n");
        return -1;
	}

    if((erase_addr & (spinor_info->min_erase_size-1)) != 0)
	{
		printk("the erase addr is not align\n");
             return -1;
	}

    switch_erase_mode(spinor_info);
    
 	while(erase_size > 0)
	{
	    //sfc_enable_write();
	    //printk("/");
		
        if ((erase_size >= ERASE_SZIE_64K) && (((unsigned int)erase_addr&(ERASE_SZIE_64K-1)) == 0) && (spinor_info->erase_capacity & ERASE_64K)) {
		    //printk("(64k)");
            cmd_erase = CMD_ERASE_BLOCK_64K;
            size = ERASE_SZIE_64K;
        }
        else if ((erase_size >= ERASE_SZIE_32K) && (((unsigned int)erase_addr&(ERASE_SZIE_32K -1)) == 0) && (spinor_info->erase_capacity & ERASE_32K)) {
		    //printk("(32k)");
            cmd_erase = CMD_ERASE_BLOCK_32K;
            size = ERASE_SZIE_32K;
        }
        else if ((erase_size >= ERASE_SZIE_4K) && (((unsigned int)erase_addr&(ERASE_SZIE_4K-1)) == 0) && (spinor_info->erase_capacity & ERASE_4K)) {
		    //printk("(4k)");
            cmd_erase = CMD_ERASE_SECTOR_4K;
            size = ERASE_SZIE_4K;
        }

        if(cmd_erase)
        {
            rtd_outl(REG_SFC_OPCODE, cmd_erase&CMD_MASK);
            rtd_outl(REG_SFC_CTL, 0x08);
            rtd_outl(REG_SFC_CTL, (1<<ADDR_EN_OFFSET)); // data_en=0 addr_en=1 dmy_en=0
            SN_SYNC;
            tmp = rtd_inb(erase_addr);
            udelay(SFC_DELAY);
            cmd_erase = 0;
        }
        else
        {
            printk("the erase size is not aligned,please use rtk_spi_nor_get_align()\n");
            return -1;
        }

        ret = sfc_wait_erase_done();
        if(ret < 0)
        {
            return -1;
        }
        /* read status registers until write operation completed*/
        //do
       // {
       //     rtd_outl(REG_SFC_OPCODE, CMD_READ_STATUS1&CMD_MASK);
        //    rtd_outl(REG_SFC_CTL, 1<<DATA_EN_OFFSET); // data_en = 1, addr_en=0 , dmy_en=0	 		
        //    SN_SYNC;
        //} while((tmp = rtd_inb(SPI_BASE_ADDR))&STATUS_WIP);

        size = (erase_size > size)? size : erase_size ;
        erase_size -= size;
        erase_addr += size;
	}

    return 0;
}

static int sfc_suspend(struct mtd_info* mtd)
{
    int ret = 0, retry = 0;
    unsigned char data = 0;
    int i = 0;
    spinor_chip_t* spinor_chip = mtd->priv;  

     printk("[spi flash] %s\n", __FUNCTION__);
    // wait FDMA DONE
    while(rtd_inl(REG_MD_FDMA_CTRL1) & (1<<FDMA_GO_OFFSET)); // wait for MD done its operation 

    // wait WIP
    do {
        udelay(SFC_DELAY);
        sfc_get_feature(CMD_READ_STATUS1, &data);
    } while ((data & STATUS_WIP)&&(++retry < SUSPEND_TIMEOUT));

    if (retry == SUSPEND_TIMEOUT) 
    {
        printk("spi flash suspend fail: %s wait timet out  0x%x\n",__FUNCTION__, data);
        ret = -1;
    }

     if(spinor_chip->spi_reg_array == NULL)
     {
                spinor_chip->spi_reg_array = (void *)kmalloc(SPI_REG_NUM * sizeof(int), GFP_KERNEL);
        }

     if(spinor_chip->spi_reg_array == NULL)
     {
                printk("spi flash suspend fail\n");
                return -1;
     }
                
     for(i = 0; i<SPI_REG_NUM; i++)
     {
                spinor_chip->spi_reg_array[i] = rtd_inl(REG_SFC_BASE + i*sizeof(int));
     }

    return ret;

}

static int sfc_resume(struct mtd_info* mtd)
{
    int ret = 0;
    spinor_chip_t* spinor_chip = mtd->priv;  
    int i = 0;

    printk("[spi flash] %s\n", __FUNCTION__);
    if(spinor_chip->spi_reg_array != NULL)
    {
        ret = sfc_init(spinor_chip);
        if(ret < 0){
           printk("spi flash resume fail %s_%d\n", __FUNCTION__, __LINE__);     
        }

         for(i = 0; i<SPI_REG_NUM; i++)
        {
                rtd_outl(REG_SFC_BASE + i*sizeof(int), spinor_chip->spi_reg_array[i]);
        }
    }
    else
    {
         printk("spi flash resume fail:%s_%d\n", __FUNCTION__, __LINE__);  
         ret = -1;
    }
    return ret;

}

static int sfc_lock(spinor_info_t *spinor_info)
{
	unsigned char status1 = 0xFF, status2 = 0xFF, status3 = 0xFF;
    unsigned short status_16bit = 0xffff;
    
    switch(spinor_info->id)
    {
        case GD25Q128C_128Mbit:
        case WINBOND_W25Q128FV_128Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);

            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7) != 0x0c) \
                || ((status2 & SFC_WP_MASK_BIT6) != SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7)) | 0x0c;
                status2 = status2 | SFC_WP_MASK_BIT6;
                if((-1==sfc_set_feature(CMD_WRITE_STATUS1, status1)) \
                    || (-1 == sfc_set_feature(CMD_WRITE_STATUS2, status2)))
                {
                    SFC_MSG_ERR("sfc_lock fail\n");
                    return -1;
                }
                SFC_MSG_INFO("new wp status: 0x%x 0x%x\n", status1, status2);
            }
            break;

         case GD25Q64C_64Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);

            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7) != 0x10) \
                || ((status2 & SFC_WP_MASK_BIT6) != SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7)) | 0x10;
                status2 = status2 | SFC_WP_MASK_BIT6;
                if((-1 == sfc_set_feature(CMD_WRITE_STATUS1, status1)) \
                    || (-1 == sfc_set_feature(CMD_WRITE_STATUS2, status2)))
                {
                    SFC_MSG_ERR("sfc_lock fail\n");
                    return -1;
                }      
                SFC_MSG_INFO("new wp status: 0x%x 0x%x\n", status1, status2);
            }
            break;

         case WINBOND_W32Q64_64Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x\n", status1, status2);
            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7) != 0x10) \
                || ((status2 & SFC_WP_MASK_BIT6) != SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7)) | 0x10;
                status2 = status2 | SFC_WP_MASK_BIT6;
                status_16bit = ((status2 << 8) |status1);
                if(-1 == sfc_set_feature_16bit(CMD_WRITE_STATUS1, status_16bit))
                {
                    SFC_MSG_ERR("sfc_lock fail\n");
                    return -1;
                }
                SFC_MSG_INFO("new wp status: 0x%x 0x%x\n", status1, status2);
            }
            break;
         
        default:
            break;
    }

    return 0;
}

static int sfc_unlock(struct mtd_info* mtd)
{
    spinor_chip_t* spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
        
    unsigned char status1 = 0xFF, status2 = 0xFF, status3 = 0xFF;
    unsigned short status_16bit = 0xffff;

    switch(spinor_info->id)
    {
        case GD25Q128C_128Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7)) \
                || (status2 & SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7));
                status2 = status2 & (~SFC_WP_MASK_BIT6);
                sfc_set_feature(CMD_WRITE_STATUS1, status1);
                sfc_set_feature(CMD_WRITE_STATUS2, status2);
                SFC_MSG_INFO("new wp status: 0x%x 0x%x\n", status1, status2);
            }
            break;

        case GD25Q64C_64Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7)) \
                || (status2 & SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7));
                status2 = status2 & (~SFC_WP_MASK_BIT6);
                sfc_set_feature(CMD_WRITE_STATUS1, status1);
                sfc_set_feature(CMD_WRITE_STATUS2, status2);
                SFC_MSG_INFO("new wp status: 0x%x 0x%x\n", status1, status2);
            }
            break;

        case WINBOND_W32Q64_64Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x\n", status1, status2);
            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7)) \
                || (status2 & SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7));
                status2 = status2 & (~SFC_WP_MASK_BIT6);
                status_16bit = ((status2 << 8) |status1);
                sfc_set_feature_16bit(CMD_WRITE_STATUS1, status_16bit);
                SFC_MSG_INFO("new wp status: 0x%x 0x%x\n", status1, status2);
            }
            break; 

         case WINBOND_W25Q128FV_128Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            if(((status1 & SFC_WP_MASK_BIT2_TO_BIT7)) \
                || (status2 & SFC_WP_MASK_BIT6))
            {
                status1 = (status1 & (~SFC_WP_MASK_BIT2_TO_BIT7));
                status2 = status2 & (~SFC_WP_MASK_BIT6);
                sfc_set_feature(CMD_WRITE_STATUS1, status1);
                sfc_set_feature(CMD_WRITE_STATUS2, status2);
                SFC_MSG_INFO("new wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            }
            break;
            
        default:
            break;
    }

    return 0;
}

static int sfc_get_lock_status(struct mtd_info* mtd, char *buf, unsigned int max_size)
{
    spinor_chip_t* spinor_chip = mtd->priv;
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
        
    unsigned char status1 = 0xFF, status2 = 0xFF, status3 = 0xFF;
    unsigned short status_16bit = 0xffff;
    
    switch(spinor_info->id)
    {
        case GD25Q128C_128Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
          //  SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            snprintf(buf, max_size,"old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            break;

        case GD25Q64C_64Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            snprintf(buf, max_size,"old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            break;

        case WINBOND_W32Q64_64Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            snprintf(buf, max_size, "old wp status: 0x%x 0x%x\n", status1, status2);
            break; 

         case WINBOND_W25Q128FV_128Mbit:
            sfc_get_feature(CMD_READ_STATUS1, &status1);
            sfc_get_feature(CMD_READ_STATUS2, &status2);
            sfc_get_feature(CMD_READ_STATUS3, &status3);
            //SFC_MSG_INFO("old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            snprintf(buf, max_size, "old wp status: 0x%x 0x%x 0x%x\n", status1, status2, status3);
            break;
            
        default:
            break;
    }

    return 0;
}

static void sfc_read_id(unsigned int* id)
{
//#if defined(Config_Target_Board_MERLIN2)
        printk("%s_%d:rtd_inl(SB2_CTRL_REG): %x\n", __FUNCTION__, __LINE__, rtd_inl(SB2_CTRL_REG));
        rtd_outl(SB2_CTRL_REG, rtd_inl(SB2_CTRL_REG) & 0xfffffffe); // release spi flash
//#endif

   rtd_outl(REG_SFC_OPCODE, CMD_READ_ID & CMD_MASK);
   rtd_outl(REG_SFC_CTL, (1<<DATA_EN_OFFSET) | (0<<ADDR_EN_OFFSET) | (0&DMY_CNT_MASK));	/* dataen = 1, adren = 0, dmycnt = 0 */
   SN_SYNC;
   udelay(SFC_DELAY);
   *id = rtd_inl(SPI_BASE_ADDR);
   SN_SYNC;
   *id = swap_endian(*id);
   (*id)= (*id)>>8;
   return;
}

static int sfc_reset(void)
{
         unsigned char tmp;
         int ret = 0, retry = 0;
         
         rtd_outl(REG_SFC_OPCODE, CMD_ENABLE_RESET&CMD_MASK);
         rtd_outl(REG_SFC_CTL, 0x00);
         SN_SYNC;
         udelay(SFC_DELAY);
         tmp = rtd_inb(SPI_BASE_ADDR);
         udelay(SFC_DELAY);

         rtd_outl(REG_SFC_OPCODE, CMD_RESET&CMD_MASK);
         rtd_outl(REG_SFC_CTL, 0x00);
         SN_SYNC;
         udelay(SFC_DELAY);
         tmp = rtd_inb(SPI_BASE_ADDR);
         udelay(SFC_DELAY);  

        do {
                udelay(SFC_DELAY);
                sfc_get_feature(CMD_READ_STATUS1, &tmp);
        } while ((tmp & STATUS_WIP)&&(++retry < SET_FEATURE_TIMEOUT));

       if (retry == SET_FEATURE_TIMEOUT) 
        {
                printk("%s reset spi fail 0x%x\n",__FUNCTION__, tmp);
        }

       return ret;
}

static int sfc_init(spinor_chip_t *spinor_chip)
{
    spinor_info_t* spinor_info = (spinor_info_t*)(spinor_chip->spinor_info);
    int ret = 0;

   //  sfc_reset();    
   // rtd_outl(REG_SFC_SCK, ((0x09&FDIV_MASK) << FDIV_OFFSET));  // SCK  500M/10 = 50M
   // rtd_outl(REG_SFC_CE, ((0x001c&TDT_MASK)<< TDT_OFFSET) | ((0x07&PHCNT_MASK)<<PHCNT_OFFSET) | ((0x07&PLCNT_MASK)<<PLCNT_OFFSET)); // tdt:1C  thcnt:7 plcnt:7
    //rtd_outl(REG_SFC_POS_LATCH, POS_LATCH_FALL<< POS_LATCH_OFFSET); // set by hwsetting

    // auto
    rtd_outl(REG_SFC_EN_WR, (1<<WT_PROG_EN_OFFSET) | (CMD_WRITE_ENABLE & WR_EN_OP_MASK));
    rtd_outl(REG_SFC_WAIT_WR, (1<<WT_PROG_DONE_OFFSET) | (CMD_READ_STATUS1 & RDSR_OP_MASK));

        printk("%s_%d\n", __FUNCTION__, __LINE__);
  //  if(!rtk_sfc_get_package_216()) // //  why QUAD is not ok
  //  {
        printk("%s_%d\n", __FUNCTION__, __LINE__);
        if(spinor_info->read_mode == eMODE_READ_QUAD_FAST)
            spinor_info->read_mode = eMODE_READ_DUAL_FAST;

        if(spinor_info->write_mode == eMODE_WRITE_QUAD_FAST)
            spinor_info->write_mode = eMODE_WRITE_NORMAL;
 //   }

    switch(spinor_info->read_mode)
    {
        case eMODE_READ_NORMAL:
            printk("support eMODE_READ_NORMAL\n");
            break;
        case eMODE_READ_NORMAL_FAST:
            printk("support eMODE_READ_NORMAL_FAST\n");
            break;
        case eMODE_READ_DUAL_FAST:
            printk("support eMODE_READ_DUAL_FAST\n");
            break;
        case eMODE_READ_QUAD_FAST:
            printk("support eMODE_READ_QUAD_FAST\n");
            break;
        default:
            printk("please set spi read mode\n");
            break;
    }
 
    
    if(spinor_info->read_mode == eMODE_READ_QUAD_FAST || spinor_info->write_mode == eMODE_WRITE_QUAD_FAST)
    {
        if((spinor_info->cmd_quad_rdsr == EMPTY_VALUE) ||(spinor_info->cmd_quad_wrsr == EMPTY_VALUE) || (spinor_info->cmd_quad_bit == EMPTY_VALUE))
        {
            printk("quad mode set error, please check s_device[]\n");
            return -1;
        }
      
        if(sfc_check_quad(spinor_info) == 0)
        {
            SFC_MSG_INFO("enabel quad mode\n");
            ret = sfc_enable_quad(spinor_info);
            if(ret == -1)
            {
                SFC_MSG_ERR("enabel quad mode fail\n");
                return ret;
            }
        }
        else
        {
            SFC_MSG_INFO("enabel quad mode\n");
        }
    }
    
#ifdef CONFIG_RTK_SPI_WP_HW
     if(sfc_check_quad(spinor_info) == 1)
     {
         SFC_MSG_ERR("the WP_HW is conflict with quad mode, only chose the one\n"); 
         return -1;
     }
#endif

//#ifdef CONFIG_RTK_SPI_WP_SOFT
   //  sfc_lock(spinor_info);
    
//#endif

    return ret;
}

static int rtk_sfc_mtd_partition_init(struct mtd_info *mtd)
{
    char *ptype;
    int pnum = 0;
	struct mtd_partition *mtd_parts;

#ifdef CONFIG_MTD_CMDLINE_PARTS
	ptype = (char *)ptypes[0];
	pnum = parse_mtd_partitions(mtd, ptypes, &mtd_parts, 0);	
#endif
	if (pnum <= 0) {
		printk(KERN_NOTICE "[sfc-INFO]Using the whole spi nor as a partitoin\n");
		if(add_mtd_device(mtd)) {
			printk(KERN_WARNING "RTK: Failed to register new spi nor device\n");
			return -EAGAIN;
		}
	}else{
		printk(KERN_NOTICE "[SN-INFO] Using dynamic spi nor partition\n");
		if (add_mtd_partitions (mtd, mtd_parts, pnum)) {
			printk("%s: Error, cannot add %s device\n",
					__FUNCTION__, mtd->name);
			mtd->size = 0;
			return -EAGAIN;
		}
	}

	return 0;

}
static int __init rtk_spi_nor_init(void)
{
    spinor_chip_t *this = NULL;
    int ret = 0;
    printk("\n\n**********SFC init module.......\n");

    if(rtk_sfc_init_condition_check() != 0)
    {
        return -1;
    }
    
#ifdef CONFIG_MTD_RTK_SFC_WRITE_MD
    printk("[SFC-INFO:] SFC_WRITE_MD support\n");
#endif

#ifdef CONFIG_MTD_RTK_SFC_READ_MD
    printk("[SFC-INFO:] SFC_READ_MD support\n");
#endif

    //allocate memory for mtd struction
    rtk_spinor_mtd = kmalloc (MTDSIZE, GFP_KERNEL);
    if ( !rtk_spinor_mtd ){
        printk("%s: Error, no enough memory for rtk_mtd\n",__FUNCTION__);
        ret = -ENOMEM;
	 goto EXIT;
    }
    else
    {
        memset ( (char *)rtk_spinor_mtd, 0, MTDSIZE);
        rtk_spinor_mtd->priv = this = (spinor_chip_t *)(rtk_spinor_mtd+1);
    }

    this->read_id = sfc_read_id; 
    this->read_bytes = sfc_read_bytes;
    this->erase_flash = sfc_erase_flash;
    this->write_bytes = sfc_write_bytes;
    this->read_md = sfc_read_md;
    this->write_md = sfc_write_md;
    this->switch_read_mode = switch_read_mode;
    this->verify_after_write = sfc_verify_after_write;
    this->unlock_flash = sfc_unlock;
    this->suspend      = sfc_suspend;
    this->resume      = sfc_resume;
    this->spinor_info =  kmalloc(sizeof(spinor_info_t), GFP_KERNEL);
    this->get_lock_status = sfc_get_lock_status;
    
    if(sfc_probe(rtk_spinor_mtd) != 0)
    {
        ret = -ENODEV;
        goto EXIT;
    }

     ret = sfc_init(this);
     if(ret < 0){
		ret = -EAGAIN;
		goto EXIT;
	}

   //  sfc_unlock(rtk_spinor_mtd);    
  //  extern void rtd_spi_nor_test(struct mtd_info *mtd);
  //  rtd_spi_nor_test(rtk_spinor_mtd);
  
    //init mtd partition info
    ret = rtk_sfc_mtd_partition_init(rtk_spinor_mtd);
    if(ret < 0){
		ret = -EAGAIN;
		goto EXIT;
	}
    
EXIT:
    if(ret < 0)
    {
        kfree(this->spinor_info);
        if(rtk_spinor_mtd)
        {
            del_mtd_partitions (rtk_spinor_mtd);
            kfree(rtk_spinor_mtd);
            rtk_spinor_mtd = NULL;
        }
    }
	return ret;
	
}

static void __exit rtk_spi_nor_exit(void)
{
	spinor_chip_t *this = NULL;

     if(rtk_spinor_mtd)
     {
        del_mtd_partitions (rtk_spinor_mtd);
        kfree(rtk_spinor_mtd);
        rtk_spinor_mtd = NULL;
     }
	printk("[SFC-INFO]rtk_spi_nor_exit!!!\n");	
}

module_init(rtk_spi_nor_init);

module_exit(rtk_spi_nor_exit);

MODULE_LICENSE("GPL");

MODULE_AUTHOR("xun_yang <xun_yang@apowertec.com>");

MODULE_DESCRIPTION("MTD chip driver for Realtek Serial Nor Flash Controller");
