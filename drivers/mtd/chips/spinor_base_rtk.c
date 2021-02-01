#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/semaphore.h>
#include "rtk_spinor.h"
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/delay.h>
#include <asm/uaccess.h>

static spinlock_t lock;
extern struct mtd_info *rtk_spinor_mtd;

static int printf_turn = 0;
static ssize_t spi_print_show(struct kobject *kobj, struct kobj_attribute *attr,  char *buf)
{
        spinor_chip_t *this = (spinor_chip_t *)rtk_spinor_mtd->priv;
        char tmp_buf[512] = {0};

        memset(tmp_buf, 0, sizeof(tmp_buf));
        if(strcmp(attr->attr.name, "lock_status") == 0)
                this->get_lock_status(rtk_spinor_mtd, tmp_buf, 511);

        return snprintf(buf, 512, "%s\n", tmp_buf);
   
}
static ssize_t spi_print_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count)
{
        sscanf(buf, "%du", &printf_turn);
        
        return count;
}


static struct kobj_attribute spi_print_attribute = __ATTR(spi_print, 0444, spi_print_show, spi_print_store);
static struct kobj_attribute spi_lock_attribute = __ATTR(lock_status, 0444, spi_print_show, spi_print_store);


static struct attribute *attrs[] = {
    &spi_print_attribute.attr,
    &spi_lock_attribute.attr,
    NULL,   /* need to NULL terminate the list of attributes */
};

static struct attribute_group attr_group = {
    .attrs = attrs,
};
        
static struct kobject *rtk_spi_kobj;

void rtd_spi_nor_test(struct mtd_info *mtd);

static int spi_nor_match_chip(struct mtd_info *mtd_info, unsigned int chip_id)
{
	int i=0;
	spinor_chip_t *spinor_chip = mtd_info->priv;
	
   	for (i = 0; i < DEV_SIZE_S; i++)
  	 {
     	/* find the match flash brand */
      	if (chip_id != s_device[i].id)
         	continue;
        
        memcpy(spinor_chip->spinor_info, &s_device[i], sizeof(spinor_info_t));
   		//spinor_chip->spinor_info= &s_device[i];
      	break;
   	}

   	if (i == DEV_SIZE_S) 
    { 
      	printk("[SPINOR-INFO]Cannot find any match ID!!!\n");
        spinor_chip->spinor_info = NULL;
      	return -1;
   	}
	return 0;

}

static int spi_nor_read (struct mtd_info *mtd, loff_t from, size_t len, size_t * retlen, u_char * buf)
{
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    int ret = 0;
    size_t rlen = 0;
    size_t len_to_read = 0;
    size_t len_done_read = 0;
    
    if ( retlen )
		*retlen = 0;
    if(this == NULL)
        return -EINVAL;
    if(!buf)
        return -EINVAL;

    down(&this->spinor_sem);
//#if 1 
#ifndef CONFIG_MTD_RTK_SFC_READ_MD  
    len_to_read = len;
    this->read_bytes(mtd, from, len_to_read, &rlen, buf);
    len_done_read += rlen;
#else
    len_to_read = len;
    if(len_to_read < WRITE_BYTES_MASK) // if data len smaller than 16, not need md
    {
        this->read_bytes(mtd, from, len_to_read, &rlen, buf);
    }
    else
    {
        this->read_md(mtd, from, len_to_read, &rlen, buf);
    }
    len_done_read += rlen;
#endif
    if(len_done_read != len)
    {
        printk("Error, len_done_read:0x%x != len_verify:0x%x!\n", len_done_read, len);	
        return EAGAIN;
    }
    
    *retlen = len_done_read;
    
    up(&this->spinor_sem);
    return ret;
}

static int spi_nor_write_cpu (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    int ret = 0;
    size_t wlen = 0;
    size_t len_to_write = 0;
    size_t len_done_write = 0;
    
    if((this == NULL) || (buf ==NULL))
        return -EINVAL;

    if (retlen)
		*retlen = 0;
    
    down(&this->spinor_sem);

    SFC_MSG_DEBUG("%s_%d   spi:%llx len:%x \n", __FUNCTION__, __LINE__, to, len);

    // 1st pass: write data which smaller than a single page (256 bytes) to make destination address within 256-bytes alignment
    if((len > 0) && (((to + MD_PP_DATA_SIZE - 1) & (~(MD_PP_DATA_SIZE - 1))) - to) > 0)
    {
       len_to_write = ((to + MD_PP_DATA_SIZE - 1) & (~(MD_PP_DATA_SIZE - 1))) - to;
       if(len_to_write > len)
	        len_to_write = len;

       SFC_MSG_DEBUG("write 1st pass use cpu\n");
       ret = this->write_bytes(mtd, to, len_to_write, &wlen, buf);
       SFC_MSG_DEBUG("ret %d\n", ret);
       if(ret < 0)
       {
           goto to_error;
       }

       to += wlen;
       buf += wlen;
       len -= wlen;
       len_done_write += wlen;
    }

    // 2rd pass: write data in page unit (256 bytes)
     while(len >= MD_PP_DATA_SIZE) 
     {
        SFC_MSG_DEBUG("write 2rd pass use md\n");
		len_to_write = MD_PP_DATA_SIZE;
	    ret = this->write_bytes(mtd, to, len_to_write, &wlen, buf);
        SFC_MSG_DEBUG("ret %d\n", ret);
        if(ret < 0)
        {
            goto to_error;
        }
	    to += wlen;
        buf += wlen;
        len -= wlen;
        len_done_write += wlen;
	}

    // 3th pass: write data which smaller than a single page (256 bytes)
    if(len > 0) 
    {
       len_to_write = len;
       SFC_MSG_DEBUG("write 3st pass use cpu\n");
       ret = this->write_bytes(mtd, to, len_to_write, &wlen, buf);
       SFC_MSG_DEBUG("ret %d\n", ret);
       if(ret < 0)
       {
           goto to_error;
       }

       to += wlen;
       buf += wlen;
       len -= wlen;
       len_done_write += wlen;
    }

    *retlen = len_done_write; 
 
 #if 0   // verify_after_write
 do_verify:
    ret = this->verify_after_write(mtd, to_verify, len_verify, buf_verify);
    if(ret < 0)
    {   SFC_MSG_ERR("spi nor verify fail after write\n");
        //printk(KERN_ERR "spi nor verify fail after write\n");
        return -EAGAIN;
    }
 #endif

 to_error:
    up(&this->spinor_sem);
    return ret;
}

static int spi_nor_write_md (struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen, const u_char *buf)
{
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    int ret = 0;
    size_t wlen = 0;
    size_t len_to_write = 0;
    size_t len_done_write = 0;
    
    if((this == NULL) || (buf ==NULL))
        return -EINVAL;

    if (retlen)
		*retlen = 0;
    
    down(&this->spinor_sem);

    SFC_MSG_DEBUG("%s_%d   spi:%llx len:%x \n", __FUNCTION__, __LINE__, to, len);

#if 0
    if(to < (this->spinor_info->size - 0x10000 - 0xA0000))  // 64K 640K
    {
        printk("write addr beyond the limit\n");
        //while(1);
    }
#endif

    if(((unsigned int)buf < 0xc0000000))
    {
        SFC_MSG_DEBUG("write only use cpu\n");
        len_to_write = len;
        ret = spi_nor_write_cpu(mtd, to, len_to_write, &wlen, buf);
        // ret = this->write_bytes(mtd, to, len_to_write, &wlen, buf);
        SFC_MSG_DEBUG("ret %d\n", ret);
        if(ret < 0)
        {
            goto to_error;
        }
        len_done_write += wlen;
    }
    else
    {
        // 1st pass: write data which smaller than a single page (256 bytes) to make destination address within 256-bytes alignment
        if((len > 0) && (((to + MD_PP_DATA_SIZE - 1) & (~(MD_PP_DATA_SIZE - 1))) - to) > 0)
        {
           len_to_write = ((to + MD_PP_DATA_SIZE - 1) & (~(MD_PP_DATA_SIZE - 1))) - to;
           if(len_to_write > len)
			    len_to_write = len;

            if(len_to_write < WRITE_BYTES_MASK) // if data len smaller than 16, not need md
            {
                SFC_MSG_DEBUG("write 1st pass use cpu\n");
                ret = this->write_bytes(mtd, to, len_to_write, &wlen, buf);
                SFC_MSG_DEBUG("ret %d\n", ret);
                if(ret < 0)
                {
                    goto to_error;
                }
            }
            else
            {
                SFC_MSG_DEBUG("write 1st pass use md\n");
                ret = this->write_md(mtd, to, len_to_write, &wlen, buf);
                SFC_MSG_DEBUG("ret %d\n", ret);
                if(ret < 0)
                {
                    goto to_error;
                }
            }
            to += wlen;
            buf += wlen;
            len -= wlen;
            len_done_write += wlen;
        }

        // 2rd pass: write data in page unit (256 bytes)
	    while(len >= MD_PP_DATA_SIZE) 
        {
            SFC_MSG_DEBUG("write 2rd pass use md\n");
		    len_to_write = MD_PP_DATA_SIZE;
	        ret = this->write_md(mtd, to, len_to_write, &wlen, buf);
            SFC_MSG_DEBUG("ret %d\n", ret);
            if(ret < 0)
            {
                goto to_error;
            }
		    to += wlen;
            buf += wlen;
            len -= wlen;
            len_done_write += wlen;
        }

        // 3th pass: write data which smaller than a single page (256 bytes)
        if(len > 0) 
        {
            len_to_write = len;
            if(len_to_write < WRITE_BYTES_MASK) // if data len smaller than 16, not need md
            {
                SFC_MSG_DEBUG("write 3st pass use cpu\n");
                ret = this->write_bytes(mtd, to, len_to_write, &wlen, buf);
                SFC_MSG_DEBUG("ret %d\n", ret);
                if(ret < 0)
                {
                    goto to_error;
                }
            }
            else
            {
                SFC_MSG_DEBUG("write 3th pass use md\n");
                ret = this->write_md(mtd, to, len_to_write, &wlen, buf);
                SFC_MSG_DEBUG("ret %d\n", ret);
                if(ret < 0)
                {
                    goto to_error;
                }
            }
            to += wlen;
            buf += wlen;
            len -= wlen;
            len_done_write += wlen;
        }

        *retlen = len_done_write; 
    }


    *retlen = len_done_write; 
 
 #if 0   // verify_after_write
 do_verify:
    ret = this->verify_after_write(mtd, to_verify, len_verify, buf_verify);
    if(ret < 0)
    {   SFC_MSG_ERR("spi nor verify fail after write\n");
        //printk(KERN_ERR "spi nor verify fail after write\n");
        return -EAGAIN;
    }
 #endif

 to_error:
    up(&this->spinor_sem);
    return ret;
}

static int spi_nor_erase (struct mtd_info *mtd, struct erase_info *instr)
{
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    int ret = 0;
    
    if(this == NULL)
        return -EINVAL;

    down(&this->spinor_sem);
    ret = this->erase_flash(mtd, instr->addr, instr->len);
    if(ret < 0)
    {
        instr->state = MTD_ERASE_FAILED;
        return ret;
    }

    // callback for jffs2 bug
    instr->state = MTD_ERASE_DONE;
  //  mtd_erase_callback(instr);
    
    up(&this->spinor_sem);
    return ret; 
}

int spi_nor_suspend(struct mtd_info *mtd)
{
    int ret = 0;
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    down(&this->spinor_sem);
            ret = this->suspend(mtd);
    up(&this->spinor_sem);
    return ret;
}

void spi_nor_resume(struct mtd_info *mtd)
{
    int ret = 0;
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    down(&this->spinor_sem);
    ret = this->resume(mtd);
    up(&this->spinor_sem);
    
    return;
}
static int spi_nor_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
    spinor_chip_t *this = (spinor_chip_t *)mtd->priv;
    this->unlock_flash(mtd);

    return 0;
}
int sfc_probe(struct mtd_info *mtd_info)
{
    spinor_chip_t *this = (spinor_chip_t *)mtd_info->priv;
    unsigned int id = 0;

    this->read_id(&id);
    if(spi_nor_match_chip(mtd_info, id)== 0)
    {
    	printk("[SFC-INFO]SPI nor flash match success!!!\n");
		printk("[SFC-INFO]SPI nor flash id = 0x%x\n",this->spinor_info->id);
	}
	else
    {
		printk("[SFC-INFO]SPI nor flash match failure!!!\n");
		return -1;
	}

    mtd_info->type = MTD_DATAFLASH;
    mtd_info->flags = MTD_WRITEABLE;
    mtd_info->ecctype = MTD_ECC_NONE;
    mtd_info->owner	= THIS_MODULE;
    mtd_info->name = "rtk_nor";
    mtd_info->size = this->spinor_info->size;
    mtd_info->erasesize = this->spinor_info->min_erase_size;
    mtd_info->writesize = 0x100;
    mtd_info->_erase = spi_nor_erase;
    mtd_info->_point		= NULL;
	mtd_info->_unpoint		= NULL;
    mtd_info->_read = spi_nor_read;
	mtd_info->numeraseregions = 0;	// uni-erasesize
	mtd_info->oobsize = 0;
    mtd_info->_suspend = spi_nor_suspend;
    mtd_info->_resume = spi_nor_resume;
	
//#if 1    
#ifndef CONFIG_MTD_RTK_SFC_WRITE_MD
    mtd_info->_write = spi_nor_write_cpu;
#else
    mtd_info->_write = spi_nor_write_md;
#endif

    mtd_info->_unlock = spi_nor_unlock;
    sema_init(&this->spinor_sem, 1);
    spin_lock_init(&lock);

  //  rtd_spi_nor_test(mtd_info);

    int retval;
    rtk_spi_kobj = kobject_create_and_add("rtk_spi", NULL);
    if (!rtk_spi_kobj)
         return -ENOMEM;

    retval = sysfs_create_group(rtk_spi_kobj, &attr_group);
  //  if (retval)
  //      kobject_put(rtk_spi_kobj);

    return 0;
}

#define SPI_TEST_ADDR  0x00ff0000
void rtd_spi_nor_test(struct mtd_info *mtd)
{
    unsigned char read_buf[1024] = {0xff};
    unsigned char read_buf2[32] = {0xff};
    unsigned char write_buf[1024] = {0};
    unsigned char *buf = 0xdf1d9840 ;
    struct erase_info instr;
    int i;
    int len = 0;
    
  
    mtd->_read(mtd, SPI_TEST_ADDR, 0x8, &len, read_buf);
    for(i=0; i<16; i++)
	{
		if(i%16 == 0)
			printk("\n");
		printk("0x%x\t", read_buf[i]);
	}

    printk("\nerase...\n");
    instr.addr = SPI_TEST_ADDR;
    instr.len = 0x1000;
    instr.callback = NULL;
    mtd->_erase(mtd, &instr);
     printk("\nread after erase\n");
    mtd->_read(mtd, SPI_TEST_ADDR, 0x8, &len, read_buf);

    for(i=0; i<16; i++)
	{
		if(i%16 == 0)
			printk("\n");
		printk("0x%x\t", read_buf[i]);
	}

    write_buf[0] = 0x99;
	write_buf[1] = 0x11;
	write_buf[2] = 0x11;
	write_buf[3] = 0x33;
	write_buf[4] = 0x44;
	write_buf[5] = 0x55;
	write_buf[6] = 0x99;
	write_buf[7] = 0x33;
	write_buf[8] = 0x22;
	write_buf[9] = 0x11;
	write_buf[10] = 0xbb;
    printk("\nread after write\n");
    mtd->_write(mtd, SPI_TEST_ADDR, 0x8, &len, write_buf);
    mtd->_read(mtd, SPI_TEST_ADDR, 0x8, &len, read_buf);

    for(i=0; i<16; i++)
	{
		if(i%16 == 0)
			printk("\n");
		printk("0x%x\t", read_buf[i]);
	}
}

