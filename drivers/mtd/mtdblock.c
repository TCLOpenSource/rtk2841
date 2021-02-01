/*
 * Direct MTD block device access
 *
 * Copyright © 1999-2010 David Woodhouse <dwmw2@infradead.org>
 * Copyright © 2000-2003 Nicolas Pitre <nico@fluxnic.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/vmalloc.h>

#include <linux/mtd/mtd.h>
#include <linux/mtd/blktrans.h>
#include <linux/mutex.h>
#include <linux/major.h>
//---------------------------------------------------
#define ERASE_NAND 1
//#define MTD_NAND_SECT_SIZE 4096
#define NAND_CP_RW_DISABLE (0xFFFFFFFF)

unsigned int *ptrMtdCacheAddr = NULL;
//---------------------------------------------------


struct mtdblk_dev {
	struct mtd_blktrans_dev mbd;
	int count;
	struct mutex cache_mutex;
	unsigned char *cache_data;
	unsigned long cache_offset;
	unsigned int cache_size;
	enum { STATE_EMPTY, STATE_CLEAN, STATE_DIRTY } cache_state;
};

static DEFINE_MUTEX(mtdblks_lock);

/*
 * Cache stuff...
 *
 * Since typical flash erasable sectors are much larger than what Linux's
 * buffer cache can handle, we must implement read-modify-write on flash
 * sectors for each block write requests.  To avoid over-erasing flash sectors
 * and to speed things up, we locally cache a whole flash sector while it is
 * being written to until a different sector is required.
 */

static void erase_callback(struct erase_info *done)
{
	wait_queue_head_t *wait_q = (wait_queue_head_t *)done->priv;
	wake_up(wait_q);
}
//----------------------------------------------
static void erase_callbackExt(struct erase_info *done)
{
 return;
}
//----------------------------------------------

static int erase_write (struct mtd_info *mtd, unsigned long pos,
			int len, const char *buf)
{
	struct erase_info erase;
	DECLARE_WAITQUEUE(wait, current);
	wait_queue_head_t wait_q;
	size_t retlen = 0;
	int ret;
	size_t retTmp=0;

	/*
	 * First, let's erase the flash block.
	 */
	if (mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH || mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") ){	//Nand flash
			erase.mtd = mtd;
			erase.addr = (pos/mtd->erasesize)*mtd->erasesize;
			if(!len)
				len = mtd->erasesize; 
			if(mtd->type==MTD_NORFLASH||mtd->type==MTD_DATAFLASH)
				erase.callback = erase_callbackExt;
			erase.len = len;
			//ret = MTD_ERASE(mtd, &erase);
			ret = mtd_erase(mtd, &erase);
			if (ret) {
				printk (KERN_WARNING "MTD_NAND_WITHOUT_WAIT_QUEUE: mtdblock:erase nand of region [0x%lx, 0x%x] "
						     "on \"%s\" failed\n", pos, len, mtd->name);
				return ret;
			}
	}else{		//Nor flash
	init_waitqueue_head(&wait_q);
	erase.mtd = mtd;
	erase.callback = erase_callback;
//	erase.addr = pos;
	erase.addr = (pos/mtd->erasesize)*mtd->erasesize;
	erase.len = len;
	erase.priv = (u_long)&wait_q;

	set_current_state(TASK_INTERRUPTIBLE);
	add_wait_queue(&wait_q, &wait);

	//ret = MTD_ERASE(mtd, &erase);
	ret = mtd_erase(mtd, &erase);
		
	if (ret) {
		set_current_state(TASK_RUNNING);
		remove_wait_queue(&wait_q, &wait);
		printk (KERN_WARNING "mtdblock: erase of region [0x%lx, 0x%x] "
				     "on \"%s\" failed\n",
			pos, len, mtd->name);
		return ret;
	}

	schedule();  /* Wait for erase to finish. */
	remove_wait_queue(&wait_q, &wait);
	}
#if 0
	init_waitqueue_head(&wait_q);
	erase.mtd = mtd;
	erase.callback = erase_callback;
	erase.addr = pos;
	erase.len = len;
	erase.priv = (u_long)&wait_q;

	set_current_state(TASK_INTERRUPTIBLE);
	add_wait_queue(&wait_q, &wait);

	ret = mtd_erase(mtd, &erase);
	if (ret) {
		set_current_state(TASK_RUNNING);
		remove_wait_queue(&wait_q, &wait);
		printk (KERN_WARNING "mtdblock: erase of region [0x%lx, 0x%x] "
				     "on \"%s\" failed\n",
			pos, len, mtd->name);
		return ret;
	}

	schedule();  /* Wait for erase to finish. */
	remove_wait_queue(&wait_q, &wait);
#endif
	/*
	 * Next, write the data to flash.
	 */
	 if ( mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
	 {
		int nCnt=len/mtd->oobblock;
		int idx = 0;

		pos = (pos/mtd->erasesize)*mtd->erasesize;
		retlen = 0;
		for(idx=0;idx<nCnt;idx++)
		{
			//ret = MTD_WRITE(mtd, pos+idx*mtd->oobblock, mtd->oobblock, &retTmp, (unsigned char*)mtd->ptr_u32CacheAddr[idx]);
			ret = mtd_write(mtd, pos+idx*mtd->oobblock, mtd->oobblock, &retTmp, (unsigned char*)mtd->ptr_u32CacheAddr[idx]);
			retlen+=retTmp;

		}
	 }
	 else
	 { 
		//ret = MTD_WRITE (mtd, pos, len, &retlen, buf);
		ret = mtd_write(mtd, pos, len, &retlen, buf);
	 }

	if (ret)
		return ret;
	if (retlen != len)
		return -EIO;
	return 0;
}


static int write_cached_data (struct mtdblk_dev *mtdblk)
{
	struct mtd_info *mtd = mtdblk->mbd.mtd;
	int ret;

	if (mtdblk->cache_state != STATE_DIRTY)
		return 0;

	pr_debug("mtdblock: writing cached data for \"%s\" "
			"at 0x%lx, size 0x%x\n", mtd->name,
			mtdblk->cache_offset, mtdblk->cache_size);

	ret = erase_write (mtd, mtdblk->cache_offset,
			   mtdblk->cache_size, mtdblk->cache_data);
	if (ret)
		return ret;

	/*
	 * Here we could arguably set the cache state to STATE_CLEAN.
	 * However this could lead to inconsistency since we will not
	 * be notified if this content is altered on the flash by other
	 * means.  Let's declare it empty and leave buffering tasks to
	 * the buffer cache instead.
	 */
	mtdblk->cache_state = STATE_EMPTY;
	return 0;
}


static int do_cached_write (struct mtdblk_dev *mtdblk, unsigned long pos,
			    int len, const char *buf)
{
	struct mtd_info *mtd = mtdblk->mbd.mtd;
	unsigned int sect_size = mtdblk->cache_size;
	size_t retlen;
	size_t retLenTmp =0 ;
	int ret=0;

	pr_debug("mtdblock: write on \"%s\" at 0x%lx, size 0x%x\n",
		mtd->name, pos, len);

	if (!sect_size)
		return mtd_write(mtd, pos, len, &retlen, buf);

	while (len > 0) {
		unsigned long sect_start = (pos/sect_size)*sect_size;
		unsigned int offset = pos - sect_start;
		unsigned int size = sect_size - offset;
		if( size > len )
			size = len;

		if (size == sect_size) {
			/*
			 * We are covering a whole sector.  Thus there is no
			 * need to bother with the cache while it may still be
			 * useful for other partial writes.
			 */
			ret = erase_write (mtd, pos, size, buf);
			if (ret)
				return ret;
		} else {
			/* Partial sector: need to use the cache */

			if (mtdblk->cache_state == STATE_DIRTY &&
			    mtdblk->cache_offset != sect_start) {
				ret = write_cached_data(mtdblk);
				if (ret)
					return ret;
			}
#if 0
			if (mtdblk->cache_state == STATE_EMPTY ||
			    mtdblk->cache_offset != sect_start) {
				/* fill the cache with the current sector */
				mtdblk->cache_state = STATE_EMPTY;
				ret = mtd_read(mtd, sect_start, sect_size,
					       &retlen, mtdblk->cache_data);
				if (ret)
					return ret;
				if (retlen != sect_size)
					return -EIO;

				mtdblk->cache_offset = sect_start;
				mtdblk->cache_size = sect_size;
				mtdblk->cache_state = STATE_CLEAN;
			}
#else
			if (mtdblk->cache_state == STATE_EMPTY ||
			    mtdblk->cache_offset != sect_start) {
				/* fill the cache with the current sector */
				mtdblk->cache_state = STATE_EMPTY;
					if ( mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
					{
						int nCnt=sect_size/mtd->oobblock;
						int idx = 0;
						retlen = 0;
						for(idx=0;idx<nCnt;idx++)
						{
							if((strcmp("/",mtd->name)==0)|| (strcmp("/usr/local/Resource",mtd->name)==0))
							{
								mtd->isCPdisable_R = 0;
								retLenTmp=0;
							}
							else
							{
								retLenTmp=NAND_CP_RW_DISABLE;
							}
							ret = mtd_read(mtd, sect_start+idx*mtd->oobblock, mtd->oobblock, &retLenTmp, (unsigned char*)mtd->ptr_u32CacheAddr[idx]);
							retlen+=retLenTmp;
						}
					}
					else
						ret = mtd_read(mtd, sect_start, sect_size, &retlen, mtdblk->cache_data);

				if (ret)
					return ret;
				if (retlen != sect_size)
					return -EIO;

				mtdblk->cache_offset = sect_start;
				mtdblk->cache_size = sect_size;
				mtdblk->cache_state = STATE_CLEAN;

			}
#endif
			/* write data to our local cache */
#if 0
			memcpy (mtdblk->cache_data + offset, buf, size);
			mtdblk->cache_state = STATE_DIRTY;
#else
			if ( mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
			{
					int nStartAddrIdx = offset/mtd->oobblock;
					int nCnt=size/mtd->oobblock;
					int i=0;
					if(mtd->oobblock>=0x2000)
					{
						if(pos%mtd->oobblock)
						{
							memcpy ( (unsigned char*)mtd->ptr_u32CacheAddr[nStartAddrIdx]+4096,buf, 4096);
							
						}
						else
						{
							memcpy ( (unsigned char*)mtd->ptr_u32CacheAddr[nStartAddrIdx],buf, 4096);	
						}
					}
					else
					{
					
						for(i=0;i<nCnt;i++)
						{
						  memcpy ( (char*)mtd->ptr_u32CacheAddr[nStartAddrIdx],buf+mtd->oobblock*i, mtd->oobblock);	
						  nStartAddrIdx++;
						}
					}
			}
			else
			{
				memcpy (mtdblk->cache_data + offset, buf, size);
				}
			mtdblk->cache_state = STATE_DIRTY;
#endif
		}

		buf += size;
		pos += size;
		len -= size;
	}

	return 0;
}


static int do_cached_read (struct mtdblk_dev *mtdblk, unsigned long pos,
			   int len, char *buf)
{
	struct mtd_info *mtd = mtdblk->mbd.mtd;
	unsigned int sect_size = mtdblk->cache_size;
	size_t retlen=0;
	int ret;
       //struct mtd_oob_ops op;

	pr_debug("mtdblock: read on \"%s\" at 0x%lx, size 0x%x\n",
			mtd->name, pos, len);

#if 0
	if (!sect_size)
		return mtd_read(mtd, pos, len, &retlen, buf);
#else
	if (!sect_size)
	{
		//if(strcmddp("/",mtd->name)==0)
		if((strcmp("/",mtd->name)==0)|| (strcmp("/usr/local/Resource",mtd->name)==0))
			return mtd_read(mtd, pos, len, &retlen, buf);
		else
		{
			#if 0
			op.len = len;
			op.retlen = retlen;
			op.datbuf = buf;
			op.oobbuf = NULL;
			return mtd->read_oob(mtd, pos,&op);
			#else
			retlen = NAND_CP_RW_DISABLE;
			return mtd_read(mtd, pos, len, &retlen, buf);
			#endif
		}
	}
#endif

	while (len > 0) {
		unsigned long sect_start = (pos/sect_size)*sect_size;
		unsigned int offset = pos - sect_start;
		unsigned int size = sect_size - offset;
		if (size > len)
			size = len;

		/*
		 * Check if the requested data is already cached
		 * Read the requested amount of data from our internal cache if it
		 * contains what we want, otherwise we read the data directly
		 * from flash.
		 */
		if (mtdblk->cache_state != STATE_EMPTY &&
		    mtdblk->cache_offset == sect_start) {
		    	if ( mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
			{
				int nStartAddrIdx = offset/mtd->oobblock;
				int nCnt=size/mtd->oobblock;
				int i=0;
				for(i=0;i<nCnt;i++)
				{
				  memcpy ( buf+mtd->oobblock*i,(char*)mtd->ptr_u32CacheAddr[nStartAddrIdx] ,mtd->oobblock);	
				  nStartAddrIdx++;
				}
			}
			else
			  memcpy (buf, mtdblk->cache_data + offset, size);
		} else {

			#if 0
				//ret = mtd->read(mtd, pos, size, &retlen, buf);
				ret = mtd_read(mtd, pos, size, &retlen, buf);
			#else
			//if(strcmp("/",mtd->name)==0)
			if((strcmp("/",mtd->name)==0)|| (strcmp("/usr/local/Resource",mtd->name)==0))
				ret = mtd_read(mtd, pos, size, &retlen, buf);
			else
			{
				#if 0
				op.len = size;
				op.retlen = retlen;
				op.datbuf = buf;
				op.oobbuf = NULL;
				ret =  mtd->read_oob(mtd, pos,&op);
				#else
				retlen = NAND_CP_RW_DISABLE;
			        ret = mtd_read(mtd, pos, size, &retlen, buf);
				#endif
			}
		    #endif
			if (ret)
				return ret;
			if (retlen != size)
				return -EIO;
		}

		buf += size;
		pos += size;
		len -= size;
	}

	return 0;
}

static int mtdblock_readsect(struct mtd_blktrans_dev *dev,
			      unsigned long block, char *buf)
{
	struct mtdblk_dev *mtdblk = container_of(dev, struct mtdblk_dev, mbd);
	struct mtd_info *mtd = mtdblk->mbd.mtd;

	if(!mtd->oobblock)
		mtd->oobblock = 512;
	if (mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH|| mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
		//return do_cached_read(mtdblk, block<<9, MTD_NAND_SECT_SIZE, buf);	
		return do_cached_read(mtdblk, block<<9, mtd->oobblock, buf);
	else
		return do_cached_read(mtdblk, block<<9, 512, buf);
}

static int mtdblock_writesect(struct mtd_blktrans_dev *dev,
			      unsigned long block, char *buf)
{
	struct mtdblk_dev *mtdblk = container_of(dev, struct mtdblk_dev, mbd);
	struct mtd_info *mtd = mtdblk->mbd.mtd;

	int i = 0;
	int addrSlots = 0;

	if(!mtd->oobblock)
		mtd->oobblock = 512;

	addrSlots = mtd->erasesize/mtd->oobblock;
	
	if (unlikely(!mtdblk->cache_data && mtdblk->cache_size)) {
#if 1
		if ( mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
		{
			mtd->ptr_u32CacheAddr=kmalloc(addrSlots*sizeof(int), GFP_KERNEL);
			if(!mtd->ptr_u32CacheAddr)
			{
				printk("[%s]mtdblk->mtd->ptr_u32CacheAddr allocate FAIL!\n",__FUNCTION__);
				return -EINTR;
			}
			for(i=0;i<addrSlots;i++)
			{
				mtd->ptr_u32CacheAddr[i]=(int)kmalloc(mtd->oobblock, GFP_KERNEL);
				if(!mtd->ptr_u32CacheAddr[i])
					return -EINTR;
			}
			mtdblk->cache_data  = (unsigned char*)mtd->ptr_u32CacheAddr;
		}
		else
		{
			mtdblk->cache_data = vmalloc(mtd->erasesize);
			if (!mtdblk->cache_data)
			return -EINTR;
		}
#else
		mtdblk->cache_data = vmalloc(mtdblk->mbd.mtd->erasesize);
		if (!mtdblk->cache_data)
			return -EINTR;
#endif
		/* -EINTR is not really correct, but it is the best match
		 * documented in man 2 write for all cases.  We could also
		 * return -EAGAIN sometimes, but why bother?
		 */
	}

	if ( mtd->type==MTD_DATAFLASH ||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
	{
		if(mtd->oobblock>0x1000)
		{
			unsigned int len=0;
			len=mtd->oobblock;
			len/=(mtd->oobblock/0x1000);
			return do_cached_write(mtdblk, block<<9, len, buf);
		}

		else
			return do_cached_write(mtdblk, block<<9, mtd->oobblock, buf);
	}
	else
		return do_cached_write(mtdblk, block<<9, 512, buf);
	
}

static int mtdblock_open(struct mtd_blktrans_dev *mbd)
{
	struct mtdblk_dev *mtdblk = container_of(mbd, struct mtdblk_dev, mbd);
	struct mtd_info *mtd = mbd->mtd;

	pr_debug("mtdblock_open\n");

	if(!mtd->oobblock)
		mtd->oobblock = 512;
	if (mtdblk->count) {
		mtdblk->count++;
		return 0;
	}

	/* OK, it's not open. Create cache info for it */
	mtdblk->count = 1;
	mutex_init(&mtdblk->cache_mutex);
	mtdblk->cache_state = STATE_EMPTY;
	if (!(mbd->mtd->flags & MTD_NO_ERASE) && mbd->mtd->erasesize) {
		mtdblk->cache_size = mbd->mtd->erasesize;
		mtdblk->cache_data = NULL;
	}
	if ( mtd->type==MTD_DATAFLASH||mtd->type==MTD_NORFLASH||mtd->type == MTD_NANDFLASH || strstr(mtd->name, "nand") )
	{
		if(!mtdblk->cache_size)
		{
			printk("[%s]No cache for NAND device!\n",__FUNCTION__);
			return -ENOMEM;
		}
		mtdblk->cache_data = NULL;
	}

	pr_debug("ok\n");

	return 0;
}

static void mtdblock_release(struct mtd_blktrans_dev *mbd)
{
	struct mtdblk_dev *mtdblk = container_of(mbd, struct mtdblk_dev, mbd);
	int i=0;
	
	pr_debug("mtdblock_release\n");

	mutex_lock(&mtdblks_lock);

	mutex_lock(&mtdblk->cache_mutex);
	
	if(mtdblk)
		write_cached_data(mtdblk);
	mutex_unlock(&mtdblk->cache_mutex);

	if (!--mtdblk->count) {
		/*
		 * It was the last usage. Free the cache, but only sync if
		 * opened for writing.
		 */
		if (mbd->file_mode & FMODE_WRITE)
			mtd_sync(mbd->mtd);

		//vfree(mtdblk->cache_data);
		if(mbd->mtd->ptr_u32CacheAddr)
		{
			for(i=0;i<mbd->mtd->erasesize/mbd->mtd->oobblock;i++)
				{
					if(mbd->mtd->ptr_u32CacheAddr[i])
					{
						kfree((unsigned int*)mbd->mtd->ptr_u32CacheAddr[i]);
						mbd->mtd->ptr_u32CacheAddr[i] = 0;
					}
				}
			if(mbd->mtd->ptr_u32CacheAddr)
			{
				kfree((unsigned int*)mbd->mtd->ptr_u32CacheAddr);
				mbd->mtd->ptr_u32CacheAddr = NULL;
			}
			mtdblk->cache_data=NULL;
		}
		if(mtdblk->cache_data)
			vfree(mtdblk->cache_data);
#if 0
		if(mtdblk)
			kfree(mtdblk);
#endif
	}

	mutex_unlock(&mtdblks_lock);

	pr_debug("ok\n");

	//return 0;
}

static int mtdblock_flush(struct mtd_blktrans_dev *dev)
{
	struct mtdblk_dev *mtdblk = container_of(dev, struct mtdblk_dev, mbd);

	mutex_lock(&mtdblk->cache_mutex);
	write_cached_data(mtdblk);
	mutex_unlock(&mtdblk->cache_mutex);
	mtd_sync(dev->mtd);
	return 0;
}

static void mtdblock_add_mtd(struct mtd_blktrans_ops *tr, struct mtd_info *mtd)
{
	struct mtdblk_dev *dev = kzalloc(sizeof(*dev), GFP_KERNEL);

	if (!dev)
		return;

	dev->mbd.mtd = mtd;
	dev->mbd.devnum = mtd->index;

	dev->mbd.size = mtd->size >> 9;
	dev->mbd.blksize = 512;			//
	dev->mbd.tr = tr;

	if (!(mtd->flags & MTD_WRITEABLE))
		dev->mbd.readonly = 1;

	if (add_mtd_blktrans_dev(&dev->mbd))
		kfree(dev);
}

static void mtdblock_remove_dev(struct mtd_blktrans_dev *dev)
{
	del_mtd_blktrans_dev(dev);
}

static struct mtd_blktrans_ops mtdblock_tr = {
	.name		= "mtdblock",
	.major		= MTD_BLOCK_MAJOR,
	.part_bits	= 0,
	.blksize 	= 512,
	.open		= mtdblock_open,
	.flush		= mtdblock_flush,
	.release	= mtdblock_release,
	.readsect	= mtdblock_readsect,
	.writesect	= mtdblock_writesect,
	.add_mtd	= mtdblock_add_mtd,
	.remove_dev	= mtdblock_remove_dev,
	.owner		= THIS_MODULE,
};

static int __init init_mtdblock(void)
{
	return register_mtd_blktrans(&mtdblock_tr);
}

static void __exit cleanup_mtdblock(void)
{
	deregister_mtd_blktrans(&mtdblock_tr);
}

module_init(init_mtdblock);
module_exit(cleanup_mtdblock);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nicolas Pitre <nico@fluxnic.net> et al.");
MODULE_DESCRIPTION("Caching read/erase/writeback block device emulation access to MTD devices");
