#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/types.h>
#include <linux/bitops.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include "rtk_spi_nand.h"
#include "rtk_spi_nand_base.h"


#include <linux/platform_device.h>
#include <linux/device.h>
#include "../../base/base.h"


#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <mach/platform.h>
#include "../mtdcore.h"
#include <linux/slab.h>

#include <linux/mtd/rtk_mtd_patch.h>
#include <linux/mtd/flash_nand_profile.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/parser.h>
#include <mtd/mtd-abi.h>
#include <mach/io.h>
#include <asm/page.h>
#include <linux/semaphore.h>

DEBUG_SET_LEVEL(DEBUG_LEVEL_INFO);
#define NOT_ALIGNED(mtd, x) (x & (mtd->oobblock-1)) != 0

spi_nand_info_t *rtk_spi_nand_mtd;

unsigned int g_sn_BootcodeSize = 0;
unsigned int g_sn_Factory_param_size = 0;
static const char *ptypes[] = {"cmdlinepart", NULL};
static struct proc_dir_entry *rtk_spi_nand_proc_entry;
int rtk_sn_str_debug;
int rtk_sn_test_debug;
#ifdef CONFIG_MTD_TABLE_TEST
extern int set_erase_fail;
extern int set_write_fail;
extern int set_read_fail;
#endif



int __init rtk_spi_nand_probe(struct platform_device *pdev);
static void __exit rtk_spi_nand_exit(struct spi_nand_chip *this);
int spi_nand_suspend(struct platform_device *pdev, pm_message_t state);
int spi_nand_resume(struct platform_device *pdev);

extern int sn_get_free_block(struct mtd_info *mtd,int bad_log_block);
extern int sn_get_log2phy_block(struct mtd_info *mtd,int log_block);
extern int sn_get_log2phy_page(struct mtd_info *mtd,int log_page);
extern  int sn_init_table(struct mtd_info *mtd);
extern void sn_de_init_table(struct mtd_info *mtd);
extern int sn_init_bbt_table(struct mtd_info *mtd);
extern int sn_remap_erase_fail_block(struct mtd_info *mtd,int log_block,int bad_block);
extern int sn_remap_write_fail_page(struct mtd_info *mtd,int log_block,int fail_page,
	const u_char * page_content);
extern int sn_remap_read_fail_page(struct mtd_info *mtd,int log_block,int bad_block);

extern void sn_build_bootcode_log2phy_table(struct mtd_info *mtd);
static ssize_t rtk_sn_str_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
static ssize_t rtk_sn_str_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);
static ssize_t rtk_sn_test_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf);
static ssize_t rtk_sn_test_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count);

static struct kobj_attribute rtk_sn_str_attr = 
	__ATTR(sn_str, 0555, rtk_sn_str_show, rtk_sn_str_store);

static struct kobj_attribute rtk_sn_test_attr = 
	__ATTR(sn_test, 0555, rtk_sn_test_show, rtk_sn_test_store);

static struct platform_driver rtk_spi_nand_driver = {
    .driver = {
        .name    = "rtk_sn",
    },
    .probe         = rtk_spi_nand_probe,
    .remove        = __exit_p(rtk_spi_nand_exit),
#ifdef CONFIG_PM
    .suspend       = spi_nand_suspend,
    .resume        = spi_nand_resume,
#endif
};

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

char *rtk_sn_parse_token(const char *parsed_string, const char *token)
{
    const char *ptr = parsed_string;
    const char *start, *end, *value_start, *value_end;
    char *ret_str;

    while(1) {
        value_start = value_end = 0;
	      for(;*ptr == ' ' || *ptr == '\t'; ptr++) ;
        if(*ptr == '\0')	
            break;
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
int rtk_sn_getpackage(void)
{
    unsigned char *param = NULL;
	int package_216 = 1;
	param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"package_216");
	if(param)
        package_216 = simple_strtoul(param, (char**)&package_216, 10);
	return package_216;
}


unsigned char* rtk_sn_getBootType(void)
{
    unsigned char *param;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"boot_flash");
    return param;
}
//----------------------------------------------------------------------------
unsigned int rtk_sn_getBootcodeSize(void)
{
    unsigned char *param;
    unsigned int retBootcodeSize = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"bootcode_size");

    if(param)
        retBootcodeSize = simple_strtoul(param, (char**)&retBootcodeSize, 16);
    return retBootcodeSize;
}
//----------------------------------------------------------------------------
unsigned int rtk_sn_getSecurestoreStart(void)
{
    unsigned char *param;
    unsigned int retSecurestoreStart = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"ss_start");

    if(param)
        retSecurestoreStart = simple_strtoul(param, (char**)&retSecurestoreStart, 16);
    return retSecurestoreStart;
}

//----------------------------------------------------------------------------
unsigned int rtk_sn_getSecurestoreSize(void)
{
    unsigned char *param;
    unsigned int retSecurestoreSize = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"ss_size");

    if(param)
        retSecurestoreSize = simple_strtoul(param, (char**)&retSecurestoreSize, 16);
    return retSecurestoreSize;
}

//----------------------------------------------------------------------------
unsigned int rtk_sn_getFactParaSize(void)
{
    unsigned char *param;
    unsigned int retFactParaSize = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"factory_size");

    if(param)
        retFactParaSize = simple_strtoul(param, (char**)&retFactParaSize, 16);
    return retFactParaSize;
}

//----------------------------------------------------------------------------
unsigned int rtk_sn_getFactRoParaStart(void)
{
    unsigned char *param;
    unsigned int retFactRoParaStart = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"factory_ro_start");

    if(param)
        retFactRoParaStart = simple_strtoul(param, (char**)&retFactRoParaStart, 16);
    return retFactRoParaStart;
}

//----------------------------------------------------------------------------
unsigned int rtk_sn_getFactRoParaSize(void)
{
    unsigned char *param;
    unsigned int retFactRoParaSize = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"factory_ro_size");

    if(param)
        retFactRoParaSize = simple_strtoul(param, (char**)&retFactRoParaSize, 16);
    return retFactRoParaSize;
}

//----------------------------------------------------------------------------
unsigned int rtk_sn_getRBAPercent(void)
{
    unsigned char *param;
    unsigned int retRbaPercent = -1 ;
    param=(char *)rtk_sn_parse_token(platform_info.system_parameters,"rba_percent");

    if(param)
        retRbaPercent = simple_strtoul(param, (char**)&retRbaPercent, 16);
    return retRbaPercent;
}

// init global params
static void spi_nand_params_init(struct mtd_info *mtd)
{
    //param getting
    g_sn_BootcodeSize = rtk_sn_getBootcodeSize();
    if(g_sn_BootcodeSize == -1)
        g_sn_BootcodeSize = DEF_SYS_PARAM_BOOTCODE_SIZE;		//12M
  
    g_sn_Factory_param_size = rtk_sn_getFactParaSize();
    if(g_sn_Factory_param_size == -1)
        g_sn_Factory_param_size = DEF_SYS_PARAM_FACTORY_SIZE;	      //4M
    SN_INFO("%s g_sn_BootcodeSize 0x%x g_sn_Factory_param_size 0x%x\n",__FUNCTION__,g_sn_BootcodeSize,g_sn_Factory_param_size);
}

static void init_spi_nand_lock(struct mtd_info *mtd)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    this->state = FL_READY;
    init_waitqueue_head(&this->wq);
    spin_lock_init(&this->chip_lock);
}

static int spi_nand_get_device(struct mtd_info *mtd, int new_state)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    DECLARE_WAITQUEUE(wait, current);

    /*Grab the lock and see if the device is available*/
    while (1) {
        spin_lock(&this->chip_lock);
        if (this->state == FL_READY) {
            this->state = new_state;
            spin_unlock(&this->chip_lock);
            break;
        }
        
        if (new_state == FL_PM_SUSPENDED) {
            spin_unlock(&this->chip_lock);
            return (this->state == FL_PM_SUSPENDED)?0 : -EAGAIN;
        }
        
        set_current_state(TASK_UNINTERRUPTIBLE);
        add_wait_queue(&this->wq, &wait);
        spin_unlock(&this->chip_lock);
        schedule();
        remove_wait_queue(&this->wq, &wait);
    }
    return 0;
}

static void spi_nand_release_device(struct mtd_info *mtd)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    /* Release the chip */
    spin_lock(&this->chip_lock);
    this->state = FL_READY;
    wake_up(&this->wq);
    spin_unlock(&this->chip_lock);
}

int spi_nand_erase(struct mtd_info *mtd, struct erase_info *instr)
{
    int ret = 0, erase_block_start = 0,erase_block_num = 0,block_id = 0,phy_block= 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    instr->fail_addr  = 0xffffffff;
    instr->state      = MTD_ERASING;
    erase_block_start = (int)((instr->addr)>>this->block_shift);
    erase_block_num   = (int)((instr->len + this->block_size - 1)>>this->block_shift);
	SN_DEBUG("%s log block %d erase_block_start %d erase_block_num %d \n",
		__FUNCTION__,(erase_block_start + block_id),erase_block_start,erase_block_num);
    spi_nand_get_device(mtd, FL_ERASING);
    
    while(block_id < erase_block_num)
    {
        phy_block = sn_get_log2phy_block(mtd,(erase_block_start + block_id));
        if(phy_block > this->total_block_num)
        {
            SN_ERR("%s log block %d get remap failed\n",__FUNCTION__, (erase_block_start + block_id));
            ret = -1;
            break;
        }
        SN_DEBUG("%s log block %d phy block %d \n",__FUNCTION__,(erase_block_start + block_id),phy_block);
        if(this->erase_block(mtd, phy_block) != 0)
        {
            if((ret = sn_remap_erase_fail_block(mtd,(erase_block_start + block_id),
				 phy_block)) != 0){
                break;
            }
        }
        if(ret == 0)
        {
            block_id++; 
        }
    }
    instr->state = MTD_ERASE_DONE;
    spi_nand_release_device(mtd);
    return ret;       
}

int spi_nand_write_ecc (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen,
			const u_char * buf, const u_char *oob_buf,struct nand_oobinfo *oobsel)
{
    int ret = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    unsigned int page_start = 0, page_num = 0, page_id = 0,page_offset=0;
    unsigned int phy_page = 0, phy_block = 0,log_block = 0;

    if ((to + len) > mtd->size) 
    {
        SN_ERR ("%s: Attempt write beyond end of device\n",__FUNCTION__);
        *retlen = 0;
        return -EINVAL;
    }
	
    if (NOT_ALIGNED(mtd, to)||NOT_ALIGNED(mtd, len)) 
    {
        SN_ERR ("%s: Attempt to write not page aligned data\n",__FUNCTION__);
        return -EINVAL;
    }
	if(*retlen)
		*retlen = 0;
	  
    page_start = (int)(to>>this->page_shift);
    page_num   = (int)(len>>this->page_shift);
    
    while(page_id < page_num)
    {
        /*get physical page*/
        log_block   = (page_start + page_id)/this->block_per_page;
        page_offset = (page_start + page_id)%this->block_per_page;
        phy_block   =  sn_get_log2phy_block(mtd,log_block);
        if(phy_block > this->total_block_num)
        {
            SN_ERR("%s log block %d get remap failed\n",__FUNCTION__, log_block);
            ret = -1;
            break;
        }
        phy_page  =  phy_block*this->block_per_page + page_offset; 
       	SN_DEBUG("%s logical page_start %d page_num %d page_offset %d phy_page %d\n",
			__FUNCTION__,page_start,page_num, page_offset,phy_page);

        /*write to spi nand*/
        if(this->write_ecc_page(mtd, phy_page, buf,oob_buf) != 0)
        {
            /*using remap block*/
            if((ret = sn_remap_write_fail_page(mtd,log_block,phy_page,buf))!= 0)
            {
                break;
            }       
        }
   
        if(oob_buf != NULL)
        {
            oob_buf += this->oob_size;
        }
        buf += this->page_size;
        *retlen = *retlen + this->page_size;
        page_id++;	     
    }  
    return ret;
}

static int spi_nand_write (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
    int ret = 0;
    spi_nand_get_device(mtd, FL_WRITING);
    ret = spi_nand_write_ecc (mtd, to, len, retlen, buf, NULL,NULL);
    spi_nand_release_device(mtd);
    return ret;
}

static int spi_nand_write_oob (struct mtd_info *mtd, loff_t to, struct mtd_oob_ops *ops)//for 2.6.34 YAFFS-->mtd
{
    int ret = 0;
    spi_nand_get_device(mtd, FL_WRITING);
    ret =  spi_nand_write_ecc (mtd,to, ops->len, &ops->retlen,ops->datbuf, ops->oobbuf,NULL);
    spi_nand_release_device(mtd);
    return ret;
}
static int spi_nand_read_ecc (struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, u_char *buf, u_char *oob_buf, struct nand_oobinfo *oobsel)
{
    int ret = 0,retry_count = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    unsigned int page_start = 0, page_num = 0, page_id = 0,page_offset=0;
    unsigned int phy_page = 0, phy_block = 0,log_block = 0;
    if ((from + len) > mtd->size) 
    {
        SN_ERR ("%s: Attempt len %d from %lu read beyond end of device\n", __FUNCTION__,len,from);
        *retlen = 0;
        return -EINVAL;
    }

    if (NOT_ALIGNED (mtd, from) || NOT_ALIGNED(mtd, len)) 
    {
        SN_ERR ("%s: Attempt to read not page aligned data\n",__FUNCTION__);
        *retlen = 0;
        return -EINVAL;
    }
	if(*retlen)
		*retlen = 0;
	  
    page_start = (int)(from >> this->page_shift); 
    page_num   = (int)(len >> this->page_shift); 
    
    while(page_id < page_num)
    {
        /*get physical page*/
        log_block   = (page_start + page_id)/this->block_per_page;
        page_offset = (page_start + page_id)%this->block_per_page;
        phy_block   =  sn_get_log2phy_block(mtd,log_block);
        if(phy_block > this->total_block_num)
        {
            SN_ERR("%s %d log block %d phy block %d get remap failed!\n",
					__FUNCTION__, __LINE__,log_block,phy_block);
            ret = -1;
            break;
        }
        phy_page  =  phy_block*this->block_per_page+ page_offset; 
        SN_DEBUG("%s logical page_start %d page_num %d page_offset %d phy_page %d\n",
			__FUNCTION__,page_start,page_num, page_offset,phy_page);
    	  
        for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++)
        {
            if((ret = this->read_ecc_page (mtd, phy_page,buf,oob_buf))== 0)
            {
            	if(retry_count != 0){
					SN_INFO("%s OK retry count %d page_start %d page_num %d phy_page %d \n",
						__FUNCTION__,retry_count,page_start,page_num,phy_page);
				}
                break;
            } 
            SN_INFO("%s retry_count %d page_start %d page_num %d  phy_page %d \n",
					__FUNCTION__,retry_count,page_start,page_num,phy_page);
        }
		if(ret != 0){
          	sn_remap_read_fail_page(mtd,log_block,phy_page);
        }
        if(ret == 0)
        {
        	if(oob_buf != NULL)
        	{
            	oob_buf += this->oob_size;
        	}
        	buf += this->page_size;
        	*retlen = *retlen + this->page_size;
        	page_id++; 
		}else{
            SN_ERR("[%s]log_block %d,phy_page %d error: data_len %d != len %d\n",
				__FUNCTION__,log_block,phy_page,*retlen , len);
    	    break;
        } 
    }   
    return ret;
}

static int spi_nand_read (struct mtd_info *mtd, loff_t from, size_t len, size_t * retlen, u_char * buf)
{
    int ret=0;
    unsigned int rd_len = 0, tmp_len = 0;
    tmp_len = rd_len = len;
    spi_nand_get_device(mtd, FL_READING);
    // align read length to page boundary
    if (rd_len & (mtd->oobblock - 1))
    {
        rd_len = (rd_len / mtd->oobblock + 1) * mtd->oobblock;
    }

    len = rd_len;
    ret = spi_nand_read_ecc(mtd, from, len, retlen, buf, NULL,NULL);

    if(*retlen == len)
        *retlen=tmp_len;
        
    spi_nand_release_device(mtd);
		
    return ret;
}

static int spi_nand_read_oob (struct mtd_info *mtd, loff_t from, struct mtd_oob_ops *ops)
{
    int ret = 0;
    spi_nand_get_device(mtd, FL_READING);
    mtd->oobinfo.useecc = ops->mode;
    ret = spi_nand_read_ecc(mtd, from, ops->len, &ops->retlen,ops->datbuf, ops->oobbuf,NULL);
    spi_nand_release_device(mtd);
    return ret;
}

int read_page_content(struct mtd_info *mtd,unsigned int page_no,u8 * buf,
 unsigned int page_num, unsigned int magic_num)
{
    int ret = 0, page_id = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    for(page_id = 0; page_id < page_num; page_id++)
    {
        if((ret = this->read_ecc_page(mtd,(page_no+page_id), this->g_databuf, this->g_oobbuf)) == 0)
        {
            if(IGR_TAG != magic_num)
            {
                if(this->g_oobbuf[this->magic_tag_offset] != magic_num)
                {
                    ret = -1;
                    SN_ERR("%s read page %d tag 0x%x\n",__FUNCTION__,(page_no+page_id),this->g_oobbuf[0]); 
                    break;
                }
            }
            memcpy(buf+page_id*this->page_size, this->g_databuf, this->page_size);
        }
        else
        {
            ret = -1;
            SN_ERR("%s read page %d error\n",__FUNCTION__,(page_no+page_id));
            break;
        }
    }
    return ret;
}

int write_block_content(struct mtd_info *mtd,unsigned int page_no,u8 * buf,
 unsigned int page_num, unsigned int magic_num)
{
    int ret = 0, page_id = 0, block_addr = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    u_char *oob_buf = NULL;
    block_addr = page_no/this->block_per_page;
    memset(this->g_oobbuf,0xFF,this->oob_size);
    
    if(IGR_TAG != magic_num)
    {
        this->g_oobbuf[this->magic_tag_offset]= magic_num;
        oob_buf = this->g_oobbuf;
    }
    
    /*earse block*/
    if((ret = this->erase_block(mtd,block_addr)) == 0)
    {  
        /*write content*/
        for(page_id = 0; page_id < page_num; page_id++)
        {
            if((ret = this->write_ecc_page(mtd,(page_no+page_id),buf, oob_buf)) == 0)
            {
                buf += this->page_size;
            }else{
                ret = -1;
                SN_ERR("%s write page %d error\n",__FUNCTION__,(page_no+page_id));
                break;
            }
        }
    }
    return ret;
}

int is_good_block(struct mtd_info *mtd,unsigned int phy_block)
{
    int ret = 0,page_addr = 0,loop = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    unsigned char block_status_p1 = 0;
    page_addr = phy_block*this->block_per_page;
    if((ret = this->read_oob(mtd, page_addr, this->g_oobbuf,this->oob_size))!=0)
    {
        SN_ERR("%s: read_oob page=%d failed\n", __FUNCTION__, page_addr);
    }
    else
    {
        block_status_p1 = this->g_oobbuf[this->bad_tag_offset];
        if(phy_block < this->bootcode_end_phy_block)
        {
            block_status_p1 = this->g_oobbuf[this->magic_tag_offset];
            for(loop = 0; loop< SPECIAL_SPI_BLOCK_TAG_N; loop++)
            {
                if(block_status_p1 == Special_SPI_BlockTag[loop])
                {
                    break;
                }
            }
            if(loop >= SPECIAL_SPI_BLOCK_TAG_N)
            {
                SN_ERR("Bootcode/Secure-store/Factory area: block tag error!!! block_status_p1 = [0x%x], block_no = [0x%x]\n",block_status_p1,phy_block);
                ret = 1;		//error block tag, bad block
            }else{
                   //check special block
                if(phy_block == 0x0)
                {
                    if (( block_status_p1 != BLOCK_CLEAN)&&(block_status_p1 != BLOCK_OTHER_DATA))
                    {
                        SN_ERR("Profile area: block tag error!!! block_status_p1 = [0x%x], block_no = [0x%x]\n",block_status_p1,phy_block);
                        ret = 1;			//error block tag, bad block
                    }
                }else if(phy_block < IBT_SCAN_START_BLOCK){
					if((block_status_p1 != BLOCK_BBT)&&(block_status_p1 != BLOCK_IBT)
						&&(block_status_p1 != BLOCK_CLEAN)){
						SN_ERR("IBT-BBT area: block tag error!!! block_status_p1 = [0x%x], "
							"block_no = [0x%x]\n",block_status_p1,phy_block);
                        ret = 1;		//error block tag, bad block
					}
				}
            }
        }else{
			if((block_status_p1 == 0xff)||(block_status_p1 == BLOCK_FACTORY_SETTING))
			{
				 ret = 0;
			}
			else
			{
				SN_ERR("block tag error!!! block_status_p1 = [%x], block_no = [0x%x]\n",block_status_p1,phy_block);
				ret = 1;		//error block tag, bad block
			}

        }
    }   
    return ret;
}

int spi_nand_block_is_bad(struct mtd_info *mtd,loff_t ofs)
{
    int ret = 0;
    return ret;
}

static int spi_nand_block_status(struct mtd_info *mtd,  loff_t ofs)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv; 
    unsigned int page_addr = 0;
    unsigned char block_status_p1 = 0;
	
    page_addr = ((int) ofs) >> this->page_shift;
    memset(this->g_oobbuf, 0xff, this->oob_size);
    if(this->read_oob(mtd, page_addr, this->g_oobbuf,this->oob_size)!=0)
    {
        SN_ERR ("%s: read_oob page=%d failed\n", __FUNCTION__, page_addr);
    }
    else
    {
        block_status_p1 = this->g_oobbuf[this->magic_tag_offset];
    } 
    return block_status_p1;
}

int spi_nand_erase_bootcode_area (struct mtd_info *mtd, struct erase_info *instr)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
    rtk_sn_spin_lock();
#endif	
    spi_nand_get_device(mtd, FL_ERASING);
    int ret = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    u_int32_t addr = instr->addr, len = instr->len;
    int block_id = 0, block_start = 0,block_num = 0,phy_block = 0;
    instr->fail_addr = 0xffffffff;
    instr->state = MTD_ERASE_FAILED;

    if (addr & (mtd->erasesize - 1)) 
    {
        SN_ERR ("%s: attempt access non-block-aligned data\n",__FUNCTION__);
        ret = -EINVAL;
        goto exit;
    }

    block_start  = (int)(addr>>this->block_shift);
    block_num    = (int)(len>>this->block_shift);
    SN_DEBUG("[%s][%d]block_start %d block_num %d!\n",__FUNCTION__,__LINE__,
		block_start,block_num);
    if((block_start + block_num) > this->kernel_start_phy_block)
    {
        SN_ERR("[%s][%d]get access range fail!\n",__FUNCTION__,__LINE__);
        ret = -EINVAL;
        goto exit;
    }

    instr->state = MTD_ERASING;
    while(block_id < block_num)
    {
        phy_block = sn_get_log2phy_block(mtd,(block_start + block_id)); 
        SN_DEBUG("[%s][%d]log_block %d phy_block %d!\n",__FUNCTION__,__LINE__,
           block_start,phy_block);
        if(phy_block > this->kernel_start_phy_block)
        {
            SN_ERR("[%s][%d]get access range block %d fail!\n",__FUNCTION__,__LINE__,phy_block);
            ret = - 1;
            goto exit;
        }
        if(this->erase_block(mtd, phy_block) != 0)
        {
            SN_ERR("[%s][%d]erase phy_block %d error!\n",__FUNCTION__,__LINE__,phy_block);
            this->g_oobbuf[this->bad_tag_offset] = BAD_TAG;
            this->write_oob(mtd, phy_block*this->block_per_page,this->g_oobbuf,this->oob_size);
            sn_build_bootcode_log2phy_table(mtd);
        }
        else
        {
             block_id++; 
        }
    }
    instr->state = MTD_ERASE_DONE;

exit:
    spi_nand_release_device(mtd);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
    rtk_sn_spin_unlock();
#endif
    return ret;
}

static int spi_nand_write_bootcode_area (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, 
			const u_char * buf, const u_char *oob_buf, unsigned char block_tag)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
    rtk_sn_spin_lock();
#endif	
    spi_nand_get_device(mtd, FL_WRITING);
    int ret = 0;
    unsigned int page_start = 0, page_num = 0, page_id = 0,page_offset=0,phy_page = 0;
    unsigned int log_block = 0,phy_block = 0, page_counter = 0, spare_value = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	u_char * tmp_oob_buf =  NULL;
    if ((to + len) > mtd->size) 
    {
        SN_ERR ("%s: Attempt write beyond end of device 0x%x \n",__FUNCTION__,mtd->size);
        *retlen = 0;
        ret = -EINVAL;
        goto exit;
    }
	
    if (NOT_ALIGNED(mtd, to)||NOT_ALIGNED(mtd, len)) 
    {
        SN_ERR ("%s: Attempt to write not page aligned data\n",__FUNCTION__);
		*retlen = 0;
		ret =  -EINVAL;
        goto exit;
    }
	  
    page_start = (int)(to>>this->page_shift);
    page_num   = (int)(len>>this->page_shift);
    SN_DEBUG("[%s][%d] page_start %d page_num %d kernel_start_phy_block %d!\n",__FUNCTION__,__LINE__,
		page_start,page_num,this->kernel_start_phy_block);
    if(((page_start + page_num)/this->block_per_page)> this->kernel_start_phy_block)
    {
        SN_ERR("[%s][%d]get access range fail!\n",__FUNCTION__,__LINE__);
		*retlen = 0;
		ret = -EINVAL;
        goto exit;
    }

	if ( retlen )
		*retlen = 0;
	
    log_block   = (page_start + page_id)/this->block_per_page;
    SN_DEBUG("[%s][%d]log_block %d page_num %d!\n",__FUNCTION__,__LINE__,
		log_block,page_num);
    while(page_id < page_num)
    {
        log_block   = (page_start + page_id)/this->block_per_page;
        page_offset = (page_start + page_id)&(this->block_per_page - 1);
        spare_value =  (block_tag&0x0000ffff)|((page_counter&0xffff) << 16);
		phy_block   =  sn_get_log2phy_block(mtd,log_block);
        if(phy_block > this->kernel_start_phy_block)
        {
            SN_ERR("%s log block %d get remap failed\n",__FUNCTION__, log_block);
            ret = -1;
            break;
        }
        phy_page    =  phy_block*this->block_per_page + page_offset; 
        SN_DEBUG("[%s][%d]phy_block %d phy_page %d spare_value 0x%x!\n",__FUNCTION__,__LINE__,
			phy_block,phy_page,spare_value);
        if(oob_buf != NULL)
        {
            tmp_oob_buf = this->g_oobbuf;
            memcpy(tmp_oob_buf,(u_char *)oob_buf,this->oob_size);
            memcpy(&(tmp_oob_buf[this->magic_tag_offset]),(char*)&spare_value,sizeof(int)); 
        }

        /*write to spi nand*/
        if(this->write_ecc_page(mtd, phy_page, buf,tmp_oob_buf) != 0)
        {
            /*mark bad block, update log2phy table*/
            this->g_oobbuf[this->bad_tag_offset] = BAD_TAG;
            this->write_oob(mtd, phy_block*this->block_per_page,this->g_oobbuf,this->oob_size);
            sn_build_bootcode_log2phy_table(mtd); 
        }
        else
        {
            if(oob_buf != NULL)
            {
                oob_buf += this->oob_size;
            }
            buf += this->page_size;
			*retlen = *retlen + this->page_size;
            page_id++; 
            page_counter++;
			if(page_id < page_num)
			{
				phy_page++;
			}
			phy_block   = phy_page/this->block_per_page;
        }
    } 

	if(ret == 0)
	{
		ret = log_block;   //return write last block
	}
 
exit:
    spi_nand_release_device(mtd);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
    rtk_sn_spin_unlock();
#endif
    return ret;
}

static int spi_nand_read_bootcode_area (struct mtd_info *mtd, loff_t from, size_t len,
			size_t *retlen, u_char *buf, u_char *oob_buf)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
    rtk_sn_spin_lock();
#endif	
    spi_nand_get_device(mtd, FL_READING);
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int ret  = 0,page_id = 0,page_start = 0,page_num =0,phy_page = 0,page_offset = 0;
    int log_block = 0,phy_block,retry_count = 0;
    if (NOT_ALIGNED (mtd, from) || NOT_ALIGNED(mtd, len))
    {
        SN_ERR (KERN_NOTICE "%s: Attempt to read not page aligned data\n",__FUNCTION__);
        ret = -EINVAL;
        goto exit;
    }
	
    page_start = (int)(from>>this->page_shift);///this->page_size;
    page_num   = (int)(len>>this->page_shift);///this->page_size;
    SN_DEBUG("[%s][%d] page_start %d page_num %d kernel_start_phy_block %d!\n",__FUNCTION__,__LINE__,
		page_start,page_num,this->kernel_start_phy_block);
    if(((page_start + page_num)/this->block_per_page)> this->kernel_start_phy_block)
    {
        SN_ERR("[%s][%d]get access range fail!\n",__FUNCTION__,__LINE__);
        ret = -EINVAL;
        goto exit;
    }

	if ( retlen )
		*retlen = 0;


    while(page_id < page_num)
    {
        /*get physical page*/
        log_block   = (page_start + page_id)/this->block_per_page;
        page_offset = (page_start + page_id)&(this->block_per_page - 1);//%this->block_per_page;
        phy_block   =  sn_get_log2phy_block(mtd,log_block);
        SN_DEBUG("[%s][%d]log_block %d phy_block %d page_num %d!\n",__FUNCTION__,__LINE__,
			log_block,phy_block,page_num);
        if(phy_block > this->kernel_start_phy_block)
        {
            SN_ERR("%s log block %d get remap failed\n",__FUNCTION__, log_block);
            ret = -1;
            break;
        }
        phy_page  =  phy_block*this->block_per_page+ page_offset; 
        SN_DEBUG("[%s][%d]phy_block %d phy_page %d!\n",__FUNCTION__,__LINE__,
            phy_block,phy_page);
        for(retry_count = 0;retry_count < READ_RETRY_COUNT;retry_count++)
        {
            if((ret = this->read_ecc_page(mtd, phy_page,buf,oob_buf))== 0)
            {
                break;
            } 
        }
        if(ret == 0)
        {
            if(oob_buf != NULL)
            {
                oob_buf += this->oob_size;
            }
            buf += this->page_size;
            *retlen = *retlen + this->page_size;
            page_id++;
        }
        else
        {
            SN_ERR("[%s]error: data_len %d != len %d\n", __FUNCTION__, *retlen , len);
            break;
        } 
    }


exit:
    spi_nand_release_device(mtd);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
    rtk_sn_spin_unlock();
#endif
    return ret;
}

static unsigned int accumulate_byte_value(const void *buf, unsigned int length)
{
    unsigned int i = 0, res =0;
    unsigned char *ptr = (unsigned char *)buf;

    for (i = res = 0; i < length; i++)
        res += ptr[i];

    return res;
}

static int spi_nand_profile_exist(struct mtd_info *mtd, unsigned char block_tag)
{
    int ret = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    unsigned int checksum = 0;
    t_spi_nand_profile *profile = NULL;

    //check block state & data
    memset(this->g_databuf, 0xff, mtd->oobblock);
    memset(this->g_oobbuf, 0xff, mtd->oobsize);
    if((ret = this->read_ecc_page (mtd, 0,this->g_databuf,this->g_oobbuf))== 0)
    {
        //check block-tag
        if (this->g_oobbuf[this->bad_tag_offset] != block_tag) {
            SN_ERR("%s [%x] profile not exist\n",__FUNCTION__,this->g_oobbuf[0]);
		    ret = -1;
        }
        else{
            profile = (t_spi_nand_profile *)this->g_databuf;
            if((ret = memcmp(profile->identifier, SPI_NAND_PROFILE_IDENTIFIER, strlen(SPI_NAND_PROFILE_IDENTIFIER)))!=0)
            {
                SN_ERR("%s wrong identify\n",__FUNCTION__);
            }
            else{
                //check checksum
                checksum = accumulate_byte_value(profile, SPI_NAND_PROFILE_CHECKSUM_SIZE);
                if (checksum != *((unsigned int *)profile->checksum)) 
                {
                    SN_ERR("profile checksum not match (%x <> %x)\n", 
                    checksum, *((unsigned int *)profile->checksum));
                    ret = -1;
                }
				else
                {
                    SN_INFO("%s profile exit!\n",__FUNCTION__);	
                }
            }
        }
    }else{
        SN_ERR("%s read profile error\n",__FUNCTION__);	
    }
    return ret;
}

extern void dump_byte(char *buf, int buf_size);
static int build_spi_nand_profile(struct mtd_info *mtd, t_spi_nand_profile *profile)
{
    int ret = 0;
    unsigned int tmp = 0, checksum = 0,tmp_id = 0,loop = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
	unsigned int * swap_buf = (unsigned int *)profile;

    if (profile == NULL) {
        return -1;
    }

	SN_INFO("%s profile size %d\n",__FUNCTION__,sizeof(t_spi_nand_profile));
    // build SPI NAND profile
    memcpy(profile->identifier, SPI_NAND_PROFILE_IDENTIFIER, sizeof(SPI_NAND_PROFILE_IDENTIFIER));
    profile->revision = 0x2;

    //ptr_device
    tmp_id = swap_endian(this->id);
    for (tmp = 0; tmp < 4; tmp++)
        profile->manufacturer_id[tmp] = (tmp_id >> (tmp * 8)) & 0xff;

    if (strlen(mtd->name) < (sizeof(profile->flash_name) - 1))
        tmp = strlen(mtd->name);
    else
        tmp = sizeof(profile->flash_name) - 1;
    memcpy(profile->flash_name, (char *)(mtd->name), tmp);

	profile->data_per_page		 = this->page_size;
	profile->oob_per_page		 = this->oob_size;
	profile->page_per_block 	 = this->block_per_page;
	profile->block_per_die		 = this->total_block_num;
	profile->bb_tag_offset       = this->bad_tag_offset+this->page_size;
	profile->special_tag_offset  = this->magic_tag_offset+this->page_size;
	profile->initial_bb_pos 	 = this->bad_tag_offset;
	profile->ra_block_mask		 = 0x3FF;
	profile->number_of_bbt		 = 2;
	profile->bbt_start_block	 = 0x1;
	profile->bbt_end_block		 = 0x2;
	profile->number_of_rsv_block = this->total_block_num * this->RBA_PERCENT/ 100;
	profile->rsv_start_block	 = this->total_block_num - profile->number_of_rsv_block;
	profile->rsv_end_block		 = this->total_block_num - 1;
	profile->number_of_ibt		 = 2;
	profile->ibt_start_block	 = 0x3;
	profile->ibt_end_block		 = 0x4;

    if(rtk_sn_getpackage() == 0)////128 pin not have wp and hold pin
    {
        if(this->support_cache_mode >= CACHE_4X)
        {
            profile->support_cache_mode = CACHE_2X;
        }
        else{
            profile->support_cache_mode = this->support_cache_mode;
	    }
    }else{
    	profile->support_cache_mode = this->support_cache_mode;
    }
	
	profile->cache_bit_offset    = this->cache_bit_offset;
	
    checksum = accumulate_byte_value(profile, SPI_NAND_PROFILE_CHECKSUM_SIZE);
	*(unsigned int *)profile->checksum = checksum;
	/*for merlin3 --> becasue swap profile content ,romcode spi_nand driver use swap mode*/
	for(loop = 0; loop < sizeof(t_spi_nand_profile)/4; loop++)
	{
		tmp = swap_endian(swap_buf[loop]);
		swap_buf[loop] = tmp;
	}
    return ret;
}

static int spi_nand_write_profile (struct mtd_info *mtd)
{
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE		
    rtk_sn_spin_lock();
#endif	
    spi_nand_get_device(mtd, FL_WRITING);
    int ret = 0;
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    t_spi_nand_profile *profile = NULL;
    unsigned int spare_value = 0, page_counter=0;
    unsigned char block_tag  = BLOCK_OTHER_DATA;

    if(spi_nand_profile_exist(mtd, block_tag) == 0){
        SN_INFO("%s Profile exist!\n",__FUNCTION__);
        goto exit;
    }

    profile = (t_spi_nand_profile *)kmalloc(sizeof(t_spi_nand_profile), GFP_KERNEL);
    if(profile == NULL){
        SN_ERR("%s: Error, no enough memory for profile\n",__FUNCTION__);
        ret = -1;
        goto exit;
    }else{
        //set init value
        memset(profile, 0, sizeof(t_spi_nand_profile));
    }
		
    ret = build_spi_nand_profile(mtd, profile);
    if(ret<0){
        SN_ERR("%s Build nand profile fail!\n",__FUNCTION__);	
        goto exit;
    }
	
    //erase block0
    ret = this->erase_block(mtd, 0);
    if(ret<0){
        SN_ERR("%s Erase block0 fail!\n",__FUNCTION__);
        goto exit;
    }

    //reset buffer
    memset(this->g_databuf, 0xff , mtd->oobblock);
    memset(this->g_oobbuf, 0xff , mtd->oobsize);
    //set buffer value
    memcpy(this->g_databuf, profile, sizeof(t_spi_nand_profile));
    this->g_oobbuf[this->magic_tag_offset] = block_tag;
    //set spare_value
    spare_value =  (block_tag & 0x0000ffff) | ((page_counter & 0xffff) << 16);
    ret = this->write_ecc_page (mtd, 0, this->g_databuf,this->g_oobbuf);

exit:
    spi_nand_release_device(mtd);
#ifdef CONFIG_MTD_NAND_RTK_HW_SEMAPHORE
    rtk_sn_spin_unlock();
#endif
    if(profile != NULL)
    {
        kfree(profile);
    }
    return ret;
}

int rtk_spi_nand_proc_read(char *buf, void *private_ptr)
{	
    int wlen = 0;
    struct spi_nand_chip *this  = (struct spi_nand_chip *)rtk_spi_nand_mtd->priv;	
    wlen += sprintf(buf+wlen,"spi_nand_name:%s\n", rtk_spi_nand_mtd->name);	
    wlen += sprintf(buf+wlen,"spi_nand_id:0x%x\n", this->id);	
    wlen += sprintf(buf+wlen,"spi_nand_size:%llu\n", (uint64_t)this->device_size);	
    wlen += sprintf(buf+wlen,"block_size:%u\n", this->block_size);	
    wlen += sprintf(buf+wlen,"page_size:%u\n", this->page_size);	
    wlen += sprintf(buf+wlen,"oob_size:%u\n", this->oob_size);	
    wlen += sprintf(buf+wlen,"ppb:%u\n",   this->block_per_page);
    wlen += sprintf(buf+wlen,"RBA:%u\n", this->RBA);	
    wlen += sprintf(buf+wlen,"BBs:%u\n", this->bbt_len);	
    return wlen;
}

static int rtk_spi_nand_proc_show(struct seq_file *m, void *v)
{
    char buffer[1024] = {0};
    rtk_spi_nand_proc_read(buffer, NULL);
    seq_puts(m, buffer);
    return 0;
}

static int rtk_spi_nand_proc_open(struct inode *inode, struct file *file)
{
    return single_open(file, rtk_spi_nand_proc_show, NULL);
}

static struct file_operations rtk_spi_nand_procfs_ops = {
	.owner = THIS_MODULE,
	.open  = rtk_spi_nand_proc_open,
	.read  = seq_read,
	.llseek  = seq_lseek,
	.release = single_release,
};

static int rtk_spi_nand_procfs_init(void)
{
    int ret = 0;
    /* Install the proc_fs entries */
    rtk_spi_nand_proc_entry = proc_create("spi_nand",
				    S_IRUGO | S_IFREG,
				    NULL,
				    &rtk_spi_nand_procfs_ops);

    if (!rtk_spi_nand_proc_entry) {
		    ret = -ENOMEM;
    }
    return ret;
}

static ssize_t rtk_sn_str_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%u\n", rtk_sn_str_debug);
}

extern int rtk_spi_nand_scan(struct mtd_info *mtd);
extern void rtk_machine_restart(char, const char *);
static ssize_t rtk_sn_str_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{	
	switch (buf[0]) {
	case '0':
        rtk_sn_str_debug = 0;
        printk("%s set 0 to rtk_sn_str_debug %d \n",__FUNCTION__,rtk_sn_str_debug);
        break;
	case '1':
        rtk_sn_str_debug = 1;
        printk("%s set 1 to rtk_sn_str_debug %d \n",__FUNCTION__,rtk_sn_str_debug);
        break;
	case '2':
		SN_DEBUG("%s reboot now**********\n",__FUNCTION__);
		rtk_machine_restart(0,"restart");
		break;
	default:
        SN_INFO("%s use default  rtk_sn_str_debug %d \n",__FUNCTION__,rtk_sn_str_debug);
        break;
    }
	return count;
}

static ssize_t rtk_sn_test_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "%u\n", rtk_sn_test_debug);
}

static ssize_t rtk_sn_test_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{	
#ifdef CONFIG_MTD_TABLE_TEST

	switch (buf[0]) {
	case '1':
		set_erase_fail = 1;
		rtk_sn_test_debug = 0;
        SN_INFO("%s set 1 to set_erase_fail %d \n",__FUNCTION__,rtk_sn_test_debug);
        break;
	case '2':
        set_write_fail = 1;
		rtk_sn_test_debug = 1;
        SN_INFO("%s set 1 to set_write_fail %d \n",__FUNCTION__,rtk_sn_test_debug);
        break;
	case '3':
	case '4':
		set_read_fail = 1;
		rtk_sn_test_debug = 2;
		SN_INFO("%s set 1 to set_read_fail %d \n",__FUNCTION__,rtk_sn_test_debug);
		break;
	default:
        SN_INFO("%s use default  rtk_sn_str_debug %d \n",__FUNCTION__,rtk_sn_test_debug);
        break;
    }
#endif
	return count;
}


static int rtk_spi_nand_sysfs_init(void)
{
	int ret = 0;
	struct kobject *kobj = NULL;

	/* Install the proc_fs entries */
	if((kobj = kobject_create_and_add("str",&(rtk_spi_nand_driver.driver.p->kobj)))!= NULL){
        if((ret = sysfs_create_file(kobj,&rtk_sn_str_attr.attr)) < 0){
			return ret;
		}
	}

	/* Install the proc_fs entries */
	if((kobj = kobject_create_and_add("test",&(rtk_spi_nand_driver.driver.p->kobj)))!= NULL){
        ret = sysfs_create_file(kobj,&rtk_sn_test_attr.attr);
	}
	return ret;
}


void spi_nand_function_init(struct mtd_info *mtd)
{
    struct spi_nand_chip *this   = (struct spi_nand_chip *)mtd->priv;
    this->read_id                = rtk_spi_nand_read_id;
    this->read_ecc_page          = rtk_spi_read_ecc_page;
    this->read_oob               = rtk_spi_read_oob;
    this->write_ecc_page         = rtk_spi_write_ecc_page;
    this->write_oob              = rtk_spi_write_oob;
    this->erase_block            = rtk_spi_erase_block;
    this->is_good_block          = is_good_block;
    this->suspend                = NULL;
    this->resume                 = NULL;
    this->sync                   = NULL;   
    mtd->type                    = MTD_NANDFLASH;
    mtd->flags                   = MTD_CAP_NANDFLASH;
    mtd->ecctype                 = MTD_ECC_NONE;
    mtd->_erase                  = spi_nand_erase;
    mtd->_read                   = spi_nand_read;
    mtd->_write                  = spi_nand_write;
    mtd->_read_ecc               = spi_nand_read_ecc;
    mtd->_write_ecc              = spi_nand_write_ecc;
    mtd->_read_oob               = spi_nand_read_oob;
    mtd->_write_oob              = spi_nand_write_oob;
    mtd->_erase_bootcode_area    = spi_nand_erase_bootcode_area;
    mtd->_write_bootcode_area    = spi_nand_write_bootcode_area;
    mtd->_read_bootcode_area     = spi_nand_read_bootcode_area;
    mtd->_write_profile          = spi_nand_write_profile;
    mtd->_block_isbad            = spi_nand_block_is_bad;
    mtd->_reload_bbt             = sn_init_bbt_table;
    mtd->_suspend                = spi_nand_suspend;
    mtd->_resume                 = spi_nand_resume;
    mtd->_point                  = NULL;
    mtd->_unpoint                = NULL;
    mtd->_sync                   = NULL;
    mtd->_lock                   = NULL;
    mtd->_unlock                 = NULL;
    mtd->_block_markbad          = NULL;
}

static int spi_nand_mtd_partition_init(struct mtd_info *mtd)
{
    int ret = 0, pnum = 0;
    char *ptype = NULL;
    struct mtd_partition *mtd_parts;
#ifdef CONFIG_MTD_CMDLINE_PARTS
    ptype = (char *)ptypes[0];
    pnum = parse_mtd_partitions(mtd, ptypes, &mtd_parts, 0);
#endif
    if (pnum <= 0) 
    {
        SN_INFO(KERN_NOTICE "[SN-INFO]Using the whole spi nand as a partitoin\n");
        if(add_mtd_device(mtd)) 
        {
            SN_ERR(KERN_WARNING "RTK: Failed to register new nand device\n");
            ret = -EAGAIN;
        }
    }else{
        printk(KERN_NOTICE "[SN-INFO] Using dynamic nand partition\n");
        if (add_mtd_partitions (mtd, mtd_parts, pnum)) 
        {
            SN_ERR("%s: Error, cannot add %s device\n",__FUNCTION__, mtd->name);
            mtd->size = 0;
            ret = -EAGAIN;
        }
    }
    return ret;
}

void printf_spi_nand_info(struct mtd_info *mtd)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    printk("---------------spi nandflash %s id 0x%x infomation--------------\n",mtd->PartNum,this->id);
    printk("block_size 0x%x block_shift: %lu\n", this->block_size,(unsigned long)this->block_shift);
    printk("page_size 0x%x page_shift: %lu\n", this->page_size,(unsigned long)this->page_shift);
    printk("oob_size %d oob_shift: 0x%x\n",this->oob_size, this->oob_shift);
    printk("total block num %d page num: %d\n",this->total_block_num, this->total_page_num);
    printk("block per page %d pagemask: %lu\n",this->block_per_page, (unsigned long)this->pagemask);   
    printk("bad block offset %d magic offset %d \n",this->bad_tag_offset,this->magic_tag_offset);
    printk("support cache mode %d (0:normal 1:dual 2:quad 3:quad_IO)\n", this->support_cache_mode);
}

int rtk_spi_nand_scan(struct mtd_info *mtd)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    unsigned int i = 0,spi_nand_type_id = 0;
    int rtk_lookup_table_flag =0;
    mtd->name = "rtk_sn";
    SN_INFO("[%s] \n", mtd->name);

    /*get spi nand id*/  
    this->read_id(mtd, &spi_nand_type_id);
    SN_INFO("READ ID:0x%x ********************\n",spi_nand_type_id);
 
    for (i = 0; spi_nand_device[i].name; i++)
    {
        if (spi_nand_device[i].id== spi_nand_type_id)
        {
            mtd->PartNum           = spi_nand_device[i].name;
            this->id               = spi_nand_type_id;
            this->device_size      = spi_nand_device[i].size;
            this->block_size       = spi_nand_device[i].blockSize;
            this->page_size        = spi_nand_device[i].pageSize;
            this->oob_size         = spi_nand_device[i].oobSize;
            this->bad_tag_offset   = spi_nand_device[i].bad_tag_offset - spi_nand_device[i].pageSize;
            this->magic_tag_offset = spi_nand_device[i].magic_tag_offset-spi_nand_device[i].pageSize;
            if(rtk_sn_getpackage() == 0)////128 pin not have wp and hold pin
            {
                if(spi_nand_device[i].support_cache_mode >= CACHE_4X)
                {
                    this->support_cache_mode = CACHE_2X;
                }
            }
            else{
                this->support_cache_mode = spi_nand_device[i].support_cache_mode;
            }
            this->cache_bit_offset   = spi_nand_device[i].cache_bit_offset;
            rtk_lookup_table_flag    = 1;
            SN_INFO("nand part=%s, id=%x, device_size=%lu page_size=%d\n",
            spi_nand_device[i].name, spi_nand_device[i].id, (unsigned long)spi_nand_device[i].size, spi_nand_device[i].pageSize);
            break;
        }   	
    }

    if ( !rtk_lookup_table_flag )
    {
        SN_ERR("Warning: Lookup Table do not have this spi nand!!\n");
        return -1;
    }
        
    this->block_shift      = generic_ffs(this->block_size)-1;
    this->page_shift       = generic_ffs(this->page_size )-1;
    this->oob_shift        = generic_ffs(this->oob_size)-1;
    this->total_block_num  = this->device_size>>this->block_shift;
    this->total_page_num   = this->device_size>>this->page_shift;
    this->block_per_page   = this->block_size/this->page_size;
    this->pagemask         = (this->device_size >> this->page_shift) - 1;
   
    mtd->size              = this->device_size;
    mtd->oobsize           = this->oob_size;
    mtd->writesize         = this->page_size;
    mtd->oobblock          = mtd->writesize;
    mtd->erasesize         = this->block_size;
    mtd->eccsize           = 512;
  
    this->g_databuf = kmalloc( this->page_size, GFP_KERNEL );
    if ( !this->g_databuf )
    {
        SN_ERR("%s: Error, no enough memory for g_databuf\n",__FUNCTION__);
        return -ENOMEM;
    }
    memset(this->g_databuf, 0xff, this->page_size);
    this->g_oobbuf = kmalloc(this->oob_size, GFP_KERNEL );
    if ( !this->g_oobbuf )
    {
        SN_ERR("%s: Error, no enough memory for g_oobbuf\n",__FUNCTION__);
        return -ENOMEM;
    }
    memset(this->g_oobbuf, 0xff, this->oob_size);
    this->sn_reg_arry = NULL; //for spi_nand str
    printf_spi_nand_info(mtd);
    return 0;
}

int spi_nand_mtd_init (struct mtd_info *mtd)
{
    int ret = 0; 
    set_spi_nand_pin_mux();
    sfc_reset();
	
    if (rtk_spi_nand_scan (mtd) < 0 || mtd->size == 0)
    {
        SN_ERR("%s: Error, cannot do nand_scan(on-board)\n", __FUNCTION__);
        ret = -ENODEV;
    }
    else
    {
        sfc_unlock_flash();
        sfc_set_cachemode(mtd);
        init_spi_nand_lock(mtd);
        if((ret = sn_init_table(mtd)) == 0)
        {
            /*spi_nand mtd partition add*/
            ret = spi_nand_mtd_partition_init(rtk_spi_nand_mtd);
        }  
    }
    return ret;
}


int spi_nand_suspend(struct platform_device *pdev, pm_message_t state)
{
    int ret = 0;
    if(rtk_spi_nand_mtd != NULL){
       SN_INFO("%s enter supend mode !\n",__FUNCTION__);
        if((ret = spi_nand_get_device(rtk_spi_nand_mtd, FL_PM_SUSPENDED)) == 0){
            if(rtk_sn_str_debug == 1){
                dump_sn_reg(1);
            }
            suspend_sn_register(rtk_spi_nand_mtd);
        }else{
            SN_ERR("%s error status !\n",__FUNCTION__);
        }	
    }
    return ret;
}

int spi_nand_resume(struct platform_device *pdev)
{
    int ret =  0;
    if(rtk_spi_nand_mtd != NULL){
        struct spi_nand_chip *this = (struct spi_nand_chip *)rtk_spi_nand_mtd->priv; 
        if (this->state == FL_PM_SUSPENDED){
            if(rtk_sn_str_debug == 1){
                dump_sn_reg(1);
            }
            resume_sn_register(rtk_spi_nand_mtd);
            set_spi_nand_pin_mux();
            sfc_reset();
	     sfc_unlock_flash();
            sfc_set_cachemode(rtk_spi_nand_mtd);
            spi_nand_release_device(rtk_spi_nand_mtd);
        }else{		
            SN_INFO("resume() called for the chip which is not in suspended state\n");
        }
    }
    return ret;
}


extern void dump_byte(char *buf, int buf_size);
extern int sfc_read_page_to_cache_b(const unsigned int block_addr,const unsigned int page_addr);
extern void sfc_read_cache_to_mem_cpu(unsigned int block_addr,UINT8 *dst,
	unsigned int offset,unsigned int len);
static void dump_by_cpu(struct mtd_info *mtd,ulong page_addr)
{
    unsigned int block_addr = 0;
    struct spi_nand_chip *this=(struct spi_nand_chip *)mtd->priv;
    char *buf = (char *)kmalloc(sizeof(char)*this->page_size,GFP_KERNEL);
    printk("%s  page_addr %d size %lu \n",
			 __FUNCTION__,page_addr,this->page_size);
    if(buf != NULL)
    {
        /*read to cache*/
        block_addr = page_addr/this->block_per_page;
        if( sfc_read_page_to_cache_b(block_addr,page_addr) == 0)
        {
            /*read cache to memeroy*/
            sfc_read_cache_to_mem_cpu(block_addr,buf,0,this->page_size);
            dump_byte(buf,this->page_size);
        }
        else
        {
            printk("%s  read error page_addr %lu size %lu \n",
			 __FUNCTION__,page_addr,this->page_size);
        }

        kfree(buf);
    }
}


static void table_wp_test(struct mtd_info *mtd,int block_addr)
{
    struct spi_nand_chip *this = (struct spi_nand_chip *)mtd->priv;
    int wp_times = 0,page_id = 0,cout = 10;
    size_t retlen = 0;
    uint64_t addr = block_addr*this->block_size;
    struct erase_info instr = {0}; 
    u_char *block_content     =  (u_char *)kmalloc(1<<this->block_shift, GFP_KERNEL );
    u_char *bak_block_content =  (u_char *)kmalloc(1<<this->block_shift, GFP_KERNEL );
	instr.mtd  = mtd;
	instr.addr = 100*this->block_size;
	instr.len  = this->block_size;
    if((block_content != NULL)&&(bak_block_content != NULL))
    {
        mtd->_read(mtd,addr,this->block_size,&retlen,block_content);
        dump_byte(block_content,512);
        //dump_by_cpu(mtd,64);
        while(cout>0)
        {
            if(mtd->_erase(mtd,&instr) != 0)
            {
                printk("%s erase failed time %d \n",__FUNCTION__,wp_times);
                break;
            }
            if(mtd->_write(mtd,100*this->block_size,this->block_size,&retlen,block_content)!= 0)
            {
                printk("[%s]block %d write_times %d writeblock error !!\n", __FUNCTION__,block_addr,wp_times);
                break;
            }
			  
            if(mtd->_read(mtd,100*this->block_size,this->block_size,&retlen,bak_block_content)!=0)
			{
                printk("[%s]block %d write_times %d readblock error !!\n", __FUNCTION__,block_addr,wp_times);
                break;
            }
					  
            if(memcmp(block_content,bak_block_content,1<<this->block_shift) == 0)
            {
                printk("[%s]block %d write_times %d compare OK !!\n", __FUNCTION__,block_addr,wp_times);
            }
            else
            {
                printk("[%s]block %d write_times %d compare error !!\n", __FUNCTION__,block_addr,wp_times);
                break;
            }
            wp_times++;
			//cout--;
        }
        kfree(block_content);
        kfree(bak_block_content);
    }
}

int __init rtk_spi_nand_probe(struct platform_device *pdev)
{
    int ret = 0;
    struct spi_nand_chip *this = NULL;
    SN_INFO("\n\n%s SPI_NAND FLASH driver init.......\n",__FUNCTION__);
    rtk_spi_nand_mtd = kmalloc(MTDSIZE, GFP_KERNEL);	
    if (!rtk_spi_nand_mtd)
    {
        SN_ERR("%s: Error, no enough memory for rtk_mtd\n",__FUNCTION__);
        ret = -ENOMEM;
        goto EXIT;
    }
    else{
        memset ( (char *)rtk_spi_nand_mtd, 0, MTDSIZE);
        rtk_spi_nand_mtd->priv = this = (struct spi_nand_chip *)(rtk_spi_nand_mtd+1);
    }

#ifdef CONFIG_ARM64
    if (!pdev->dev.dma_mask)
        pdev->dev.dma_mask = &pdev->dev.coherent_dma_mask;
    if (!pdev->dev.coherent_dma_mask)
        pdev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
#endif
    
    /*spi_nand params init*/
    spi_nand_params_init(rtk_spi_nand_mtd);
        
    /*spi_nand function init*/
    spi_nand_function_init(rtk_spi_nand_mtd);

    /*spi_nand mtd informtion init*/
    ret = spi_nand_mtd_init(rtk_spi_nand_mtd);
  
    /*create spi_nand proc fs entry*/
    rtk_spi_nand_procfs_init();

	rtk_spi_nand_sysfs_init();

    //table_wp_test(rtk_spi_nand_mtd,8);

EXIT:
    if(ret < 0)
    {
        rtk_spi_nand_exit(this);
    }
    return ret;
}

static int rtk_spi_nand_boot_type_getting(void)
{
	int ret = 0;
	unsigned char *ptr;
	
 	ptr = rtk_sn_getBootType();

	if(ptr == NULL){
		SN_ERR("[Warning]Can't get boot type!Spi-Nand flash driver init continue....\n");
		
	}else{
		if(memcmp(ptr,"spi_nand",strlen("spi_nand"))!=0){
			SN_ERR("Boottype %s!Spi-Nand flash driver init exit....\n",ptr);
			ret = -1;
		}else{
			SN_INFO("Boottype %s!Spi-Nand flash driver init continue....\n",ptr);
		}
	}

	return ret;
}

static int __init rtk_spi_nand_init (void)
{
    int ret = 0;

	//boot type check
	if((ret = rtk_spi_nand_boot_type_getting())!=0)
	{
		SN_ERR("Boottype is not spi-nand. Installing fails.\n");
	}
	else
	{
	
    	ret = platform_driver_probe(&rtk_spi_nand_driver, rtk_spi_nand_probe);
    	if (ret < 0)
    	{
        	SN_ERR( "Realtek SPI Nand Controller Driver installation fails.\n\n");
    	}
    	else{
        	SN_INFO( "*******5233333**Realtek SPI Nand Controller Driver is successfully installing.\n\n");
    	}
	}
    return ret;
}

static void __exit rtk_spi_nand_exit(struct spi_nand_chip *this)
{
    if(rtk_spi_nand_mtd != NULL)
    {
        if(this->g_databuf != NULL)
        {
            kfree(this->g_databuf);
        }
            
        if(this->g_oobbuf != NULL)
        {
            kfree(this->g_oobbuf);
        }
            
        del_mtd_partitions (rtk_spi_nand_mtd);
        sn_de_init_table(rtk_spi_nand_mtd);
        kfree(rtk_spi_nand_mtd);
    }
    remove_proc_entry("spi_nand_info", NULL);
}

module_init(rtk_spi_nand_init);
module_exit(rtk_spi_nand_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("MTD chip driver for Realtek SPI NAND Flash Controller");

