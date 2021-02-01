/*
 * Block driver for media (i.e., flash cards)
 *
 * Copyright 2002 Hewlett-Packard Company
 * Copyright 2005-2008 Pierre Ossman
 *
 * Use consistent with the GNU GPL is permitted,
 * provided that this copyright notice is
 * preserved in its entirety in all copies and derived works.
 *
 * HEWLETT-PACKARD COMPANY MAKES NO WARRANTIES, EXPRESSED OR IMPLIED,
 * AS TO THE USEFULNESS OR CORRECTNESS OF THIS CODE OR ITS
 * FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 * Many thanks to Alessandro Rubini and Jonathan Corbet!
 *
 * Author:  Andrew Christian
 *          28 May 2002
 */
#include <linux/moduleparam.h>
#include <linux/module.h>
#include <linux/init.h>

#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/hdreg.h>
#include <linux/kdev_t.h>
#include <linux/blkdev.h>
#include <linux/mutex.h>
#include <linux/scatterlist.h>
#include <linux/string_helpers.h>
#include <linux/delay.h>
#include <linux/capability.h>
#include <linux/compat.h>
#include <linux/pm_runtime.h>

#include <linux/mmc/ioctl.h>
#include <linux/mmc/card.h>
#include <linux/mmc/host.h>
#include <linux/mmc/mmc.h>
#include <linux/mmc/sd.h>

#include <asm/uaccess.h>

#include "queue.h"

#ifdef CONFIG_RTKEMMC_COWORK_WITH_KCPU
#include <rtk_kdriver/RPCDriver.h>
#include <linux/pageremap.h>
#include <asm/cacheflush.h>

//extern int send_rpc_command(int opt, unsigned long command, unsigned long param1, unsigned long param2, unsigned long *retvalue);

#endif

MODULE_ALIAS("mmc:block");

#ifdef MODULE_PARAM_PREFIX
#undef MODULE_PARAM_PREFIX
#endif
#define MODULE_PARAM_PREFIX "mmcblk."

#define INAND_CMD38_ARG_EXT_CSD  113
#define INAND_CMD38_ARG_ERASE    0x00
#define INAND_CMD38_ARG_TRIM     0x01
#define INAND_CMD38_ARG_SECERASE 0x80
#define INAND_CMD38_ARG_SECTRIM1 0x81
#define INAND_CMD38_ARG_SECTRIM2 0x88
#define MMC_BLK_TIMEOUT_MS  (10 * 60 * 1000)        /* 10 minute timeout */
#define MMC_SANITIZE_REQ_TIMEOUT 240000
#define MMC_EXTRACT_INDEX_FROM_ARG(x) ((x & 0x00FF0000) >> 16)

#define mmc_req_rel_wr(req)	((req->cmd_flags & REQ_FUA) && \
				  (rq_data_dir(req) == WRITE))
#define PACKED_CMD_VER	0x01
#define PACKED_CMD_WR	0x02

#ifdef CONFIG_MMC_RTKEMMC_PLUS
#define RTK_IOCTL_OPTION
#endif

static DEFINE_MUTEX(block_mutex);

/*
 * The defaults come from config options but can be overriden by module
 * or bootarg options.
 */
static int perdev_minors = CONFIG_MMC_BLOCK_MINORS;

/*
 * We've only got one major, so number of mmcblk devices is
 * limited to (1 << 20) / number of minors per device.  It is also
 * currently limited by the size of the static bitmaps below.
 */
static int max_devices;

#define MAX_DEVICES 256

/* TODO: Replace these with struct ida */
static DECLARE_BITMAP(dev_use, MAX_DEVICES);
static DECLARE_BITMAP(name_use, MAX_DEVICES);

/*
 * There is one mmc_blk_data per slot.
 */
struct mmc_blk_data {
	spinlock_t	lock;
	struct gendisk	*disk;
	struct mmc_queue queue;
	struct list_head part;

	unsigned int	flags;
#define MMC_BLK_CMD23	(1 << 0)	/* Can do SET_BLOCK_COUNT for multiblock */
#define MMC_BLK_REL_WR	(1 << 1)	/* MMC Reliable write support */
#define MMC_BLK_PACKED_CMD	(1 << 2)	/* MMC packed command support */

	unsigned int	usage;
	unsigned int	read_only;
	unsigned int	part_type;
	unsigned int	name_idx;
	unsigned int	reset_done;
#define MMC_BLK_READ		BIT(0)
#define MMC_BLK_WRITE		BIT(1)
#define MMC_BLK_DISCARD		BIT(2)
#define MMC_BLK_SECDISCARD	BIT(3)
#ifdef CONFIG_MMC_RTKEMMC_PLUS
	unsigned int	reset_cnt;
#endif
	/*
	 * Only set in main mmc_blk_data associated
	 * with mmc_card with dev_set_drvdata, and keeps
	 * track of the current selected device partition.
	 */
	unsigned int	part_curr;
	struct device_attribute force_ro;
	struct device_attribute power_ro_lock;
	int	area_type;
};

static DEFINE_MUTEX(open_lock);

enum {
	MMC_PACKED_NR_IDX = -1,
	MMC_PACKED_NR_ZERO,
	MMC_PACKED_NR_SINGLE,
};

module_param(perdev_minors, int, 0444);
MODULE_PARM_DESC(perdev_minors, "Minors numbers to allocate per device");

static inline int mmc_blk_part_switch(struct mmc_card *card,
				      struct mmc_blk_data *md);
static int get_card_status(struct mmc_card *card, u32 *status, int retries);

static inline void mmc_blk_clear_packed(struct mmc_queue_req *mqrq)
{
	struct mmc_packed *packed = mqrq->packed;

	BUG_ON(!packed);

	mqrq->cmd_type = MMC_PACKED_NONE;
	packed->nr_entries = MMC_PACKED_NR_ZERO;
	packed->idx_failure = MMC_PACKED_NR_IDX;
	packed->retries = 0;
	packed->blocks = 0;
}

static struct mmc_blk_data *mmc_blk_get(struct gendisk *disk)
{
	struct mmc_blk_data *md;

	mutex_lock(&open_lock);
	md = disk->private_data;
	if (md && md->usage == 0)
		md = NULL;
	if (md)
		md->usage++;
	mutex_unlock(&open_lock);

	return md;
}

static inline int mmc_get_devidx(struct gendisk *disk)
{
	int devmaj = MAJOR(disk_devt(disk));
	int devidx = MINOR(disk_devt(disk)) / perdev_minors;

	if (!devmaj)
		devidx = disk->first_minor / perdev_minors;
	return devidx;
}

static void mmc_blk_put(struct mmc_blk_data *md)
{
	mutex_lock(&open_lock);
	md->usage--;
	if (md->usage == 0) {
		int devidx = mmc_get_devidx(md->disk);
		blk_cleanup_queue(md->queue.queue);

		__clear_bit(devidx, dev_use);

		put_disk(md->disk);
		kfree(md);
	}
	mutex_unlock(&open_lock);
}

static ssize_t power_ro_lock_show(struct device *dev,
		struct device_attribute *attr, char *buf)
{
	int ret;
	struct mmc_blk_data *md = mmc_blk_get(dev_to_disk(dev));
	struct mmc_card *card = md->queue.card;
	int locked = 0;

	if (card->ext_csd.boot_ro_lock & EXT_CSD_BOOT_WP_B_PERM_WP_EN)
		locked = 2;
	else if (card->ext_csd.boot_ro_lock & EXT_CSD_BOOT_WP_B_PWR_WP_EN)
		locked = 1;

	ret = snprintf(buf, PAGE_SIZE, "%d\n", locked);

	mmc_blk_put(md);

	return ret;
}

static ssize_t power_ro_lock_store(struct device *dev,
		struct device_attribute *attr, const char *buf, size_t count)
{
	int ret;
	struct mmc_blk_data *md, *part_md;
	struct mmc_card *card;
	unsigned long set;

	if (kstrtoul(buf, 0, &set))
		return -EINVAL;

	if (set != 1)
		return count;

	md = mmc_blk_get(dev_to_disk(dev));
	card = md->queue.card;

	mmc_get_card(card);

	ret = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL, EXT_CSD_BOOT_WP,
				card->ext_csd.boot_ro_lock |
				EXT_CSD_BOOT_WP_B_PWR_WP_EN,
				card->ext_csd.part_time);
	if (ret)
		pr_err("%s: Locking boot partition ro until next power on failed: %d\n", md->disk->disk_name, ret);
	else
		card->ext_csd.boot_ro_lock |= EXT_CSD_BOOT_WP_B_PWR_WP_EN;

	mmc_put_card(card);

	if (!ret) {
		pr_info("%s: Locking boot partition ro until next power on\n",
			md->disk->disk_name);
		set_disk_ro(md->disk, 1);

		list_for_each_entry(part_md, &md->part, part)
			if (part_md->area_type == MMC_BLK_DATA_AREA_BOOT) {
				pr_info("%s: Locking boot partition ro until next power on\n", part_md->disk->disk_name);
				set_disk_ro(part_md->disk, 1);
			}
	}

	mmc_blk_put(md);
	return count;
}

static ssize_t force_ro_show(struct device *dev, struct device_attribute *attr,
			     char *buf)
{
	int ret;
	struct mmc_blk_data *md = mmc_blk_get(dev_to_disk(dev));

	ret = snprintf(buf, PAGE_SIZE, "%d\n",
		       get_disk_ro(dev_to_disk(dev)) ^
		       md->read_only);
	mmc_blk_put(md);
	return ret;
}

static ssize_t force_ro_store(struct device *dev, struct device_attribute *attr,
			      const char *buf, size_t count)
{
	int ret;
	char *end;
	struct mmc_blk_data *md = mmc_blk_get(dev_to_disk(dev));
	unsigned long set = simple_strtoul(buf, &end, 0);
	if (end == buf) {
		ret = -EINVAL;
		goto out;
	}

	set_disk_ro(dev_to_disk(dev), set || md->read_only);
	ret = count;
out:
	mmc_blk_put(md);
	return ret;
}

static int mmc_blk_open(struct block_device *bdev, fmode_t mode)
{
	struct mmc_blk_data *md = mmc_blk_get(bdev->bd_disk);
	int ret = -ENXIO;

	mutex_lock(&block_mutex);
	if (md) {
		if (md->usage == 2)
			check_disk_change(bdev);
		ret = 0;

		if ((mode & FMODE_WRITE) && md->read_only) {
			mmc_blk_put(md);
			ret = -EROFS;
		}
	}
	mutex_unlock(&block_mutex);

	return ret;
}

static void mmc_blk_release(struct gendisk *disk, fmode_t mode)
{
	struct mmc_blk_data *md = disk->private_data;

	mutex_lock(&block_mutex);
	mmc_blk_put(md);
	mutex_unlock(&block_mutex);
}

static int
mmc_blk_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
	geo->cylinders = get_capacity(bdev->bd_disk) / (4 * 16);
	geo->heads = 4;
	geo->sectors = 16;
	return 0;
}

struct mmc_blk_ioc_data {
	struct mmc_ioc_cmd ic;
	unsigned char *buf;
	u64 buf_bytes;
};

static struct mmc_blk_ioc_data *mmc_blk_ioctl_copy_from_user(
	struct mmc_ioc_cmd __user *user)
{
	struct mmc_blk_ioc_data *idata;
	int err;

	idata = kzalloc(sizeof(*idata), GFP_KERNEL);
	if (!idata) {
		err = -ENOMEM;
		goto out;
	}

	if (copy_from_user(&idata->ic, user, sizeof(idata->ic))) {
		err = -EFAULT;
		goto idata_err;
	}

	idata->buf_bytes = (u64) idata->ic.blksz * idata->ic.blocks;
	if (idata->buf_bytes > MMC_IOC_MAX_BYTES) {
		err = -EOVERFLOW;
		goto idata_err;
	}

	if (!idata->buf_bytes)
		return idata;

	idata->buf = kzalloc(idata->buf_bytes, GFP_KERNEL);
	if (!idata->buf) {
		err = -ENOMEM;
		goto idata_err;
	}

	if (copy_from_user(idata->buf, (void __user *)(unsigned long)
					idata->ic.data_ptr, idata->buf_bytes)) {
		err = -EFAULT;
		goto copy_err;
	}

	return idata;

copy_err:
	kfree(idata->buf);
idata_err:
	kfree(idata);
out:
	return ERR_PTR(err);
}

static int mmc_blk_ioctl_copy_to_user(struct mmc_ioc_cmd __user *ic_ptr,
				      struct mmc_blk_ioc_data *idata)
{
	struct mmc_ioc_cmd *ic = &idata->ic;

	if (copy_to_user(&(ic_ptr->response), ic->response,
			 sizeof(ic->response)))
		return -EFAULT;

	if (!idata->ic.write_flag) {
		if (copy_to_user((void __user *)(unsigned long)ic->data_ptr,
				 idata->buf, idata->buf_bytes))
			return -EFAULT;
	}

	return 0;
}

static int ioctl_rpmb_card_status_poll(struct mmc_card *card, u32 *status,
				       u32 retries_max)
{
	int err;
	u32 retry_count = 0;

	if (!status || !retries_max)
		return -EINVAL;

	do {
		err = get_card_status(card, status, 5);
		if (err)
			break;

		if (!R1_STATUS(*status) &&
				(R1_CURRENT_STATE(*status) != R1_STATE_PRG))
			break; /* RPMB programming operation complete */

		/*
		 * Rechedule to give the MMC device a chance to continue
		 * processing the previous command without being polled too
		 * frequently.
		 */
		usleep_range(1000, 5000);
	} while (++retry_count < retries_max);

	if (retry_count == retries_max)
		err = -EPERM;

	return err;
}

static int ioctl_do_sanitize(struct mmc_card *card)
{
	int err;

	if (!mmc_can_sanitize(card)) {
			pr_warn("%s: %s - SANITIZE is not supported\n",
				mmc_hostname(card->host), __func__);
			err = -EOPNOTSUPP;
			goto out;
	}

	pr_debug("%s: %s - SANITIZE IN PROGRESS...\n",
		mmc_hostname(card->host), __func__);

	err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
					EXT_CSD_SANITIZE_START, 1,
					MMC_SANITIZE_REQ_TIMEOUT);

	if (err)
		pr_err("%s: %s - EXT_CSD_SANITIZE_START failed. err=%d\n",
		       mmc_hostname(card->host), __func__, err);

	pr_debug("%s: %s - SANITIZE COMPLETED\n", mmc_hostname(card->host),
					     __func__);
out:
	return err;
}

static int __mmc_blk_ioctl_cmd(struct mmc_card *card, struct mmc_blk_data *md,
			       struct mmc_blk_ioc_data *idata)
{
	struct mmc_command cmd = {0};
	struct mmc_data data = {0};
	struct mmc_request mrq = {NULL};
	struct scatterlist sg;
	int err;
	int is_rpmb = false;
	u32 status = 0;

	if (!card || !md || !idata)
		return -EINVAL;

	if (md->area_type & MMC_BLK_DATA_AREA_RPMB)
		is_rpmb = true;

	cmd.opcode = idata->ic.opcode;
	cmd.arg = idata->ic.arg;
	cmd.flags = idata->ic.flags;

	if (idata->buf_bytes) {
		data.sg = &sg;
		data.sg_len = 1;
		data.blksz = idata->ic.blksz;
		data.blocks = idata->ic.blocks;

		sg_init_one(data.sg, idata->buf, idata->buf_bytes);

		if (idata->ic.write_flag)
			data.flags = MMC_DATA_WRITE;
		else
			data.flags = MMC_DATA_READ;

		/* data.flags must already be set before doing this. */
		mmc_set_data_timeout(&data, card);

		/* Allow overriding the timeout_ns for empirical tuning. */
		if (idata->ic.data_timeout_ns)
			data.timeout_ns = idata->ic.data_timeout_ns;

		if ((cmd.flags & MMC_RSP_R1B) == MMC_RSP_R1B) {
			/*
			 * Pretend this is a data transfer and rely on the
			 * host driver to compute timeout.  When all host
			 * drivers support cmd.cmd_timeout for R1B, this
			 * can be changed to:
			 *
			 *     mrq.data = NULL;
			 *     cmd.cmd_timeout = idata->ic.cmd_timeout_ms;
			 */
			data.timeout_ns = idata->ic.cmd_timeout_ms * 1000000;
		}

		mrq.data = &data;
	}

	mrq.cmd = &cmd;

	err = mmc_blk_part_switch(card, md);
	if (err)
		return err;

	if (idata->ic.is_acmd) {
		err = mmc_app_cmd(card->host, card);
		if (err)
			return err;
	}

	if (is_rpmb) {
		err = mmc_set_blockcount(card, data.blocks,
			idata->ic.write_flag & (1 << 31));
		if (err)
			return err;
	}

	if ((MMC_EXTRACT_INDEX_FROM_ARG(cmd.arg) == EXT_CSD_SANITIZE_START) &&
	    (cmd.opcode == MMC_SWITCH)) {
		err = ioctl_do_sanitize(card);

		if (err)
			pr_err("%s: ioctl_do_sanitize() failed. err = %d",
			       __func__, err);

		return err;
	}

	mmc_wait_for_req(card->host, &mrq);

	if (cmd.error) {
		dev_err(mmc_dev(card->host), "%s: cmd error %d\n",
						__func__, cmd.error);
		return cmd.error;
	}
	if (data.error) {
		dev_err(mmc_dev(card->host), "%s: data error %d\n",
						__func__, data.error);
		return data.error;
	}

	/*
	 * According to the SD specs, some commands require a delay after
	 * issuing the command.
	 */
	if (idata->ic.postsleep_min_us)
		usleep_range(idata->ic.postsleep_min_us, idata->ic.postsleep_max_us);

	memcpy(&(idata->ic.response), cmd.resp, sizeof(cmd.resp));

	if (is_rpmb) {
		/*
		 * Ensure RPMB command has completed by polling CMD13
		 * "Send Status".
		 */
		err = ioctl_rpmb_card_status_poll(card, &status, 25);
		if (err)
			dev_err(mmc_dev(card->host),
					"%s: Card Status=0x%08X, error %d\n",
					__func__, status, err);
	}

	return err;
}

#ifdef RTK_IOCTL_OPTION
extern int export_mmc_poweroff_notify(struct mmc_card *card, unsigned int notify_type);
extern int export_mmc_can_poweroff_notify(const struct mmc_card *card);
extern int export_mmc_send_data_cmd(unsigned int hc_cmd,unsigned int cmd_arg,
                                    unsigned int blk_cnt,unsigned char * buffer );

#define RTK_FLAG_SHT (16) //The flags of struct mmc_command is from bit0 to bit10. Therefore, We use bit16 to bit31.
#define GET_RTK_IOCTL_FLAG(val) \
            ((val & 0xffff0000)>>RTK_FLAG_SHT)
#define GET_CMD_IOCTL_FLAG(val) \
            (val & 0x0000FFFF)

#define RTK_IOCTL_ERASE         (0x01)
#define RTK_IOCTL_OPEN          (0x02)
#define RTK_IOCTL_CLOSE         (0x03)
#define RTK_IOCTL_PON_SHORT     (0x04)
#define RTK_IOCTL_PON_LONG      (0x05)
#define RTK_IOCTL_SMART_REPORT  (0x06)
#define RTK_IOCTL_GET_CID       (0x07)
#define RTK_IOCTL_GET_CSD       (0x08)

static
int mmc_rtk_ioctl_open(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata )
{
	return 1;
}

static
int mmc_rtk_ioctl_close(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata )
{
	return 1;
}

static
int mmc_rtk_ioctl_power_off_notification(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata )
{
	struct mmc_blk_data *md;
	struct mmc_card *card;
	u32 *buf;
	u8 *emmc_buf = NULL;
	int err;

	err = -EPERM;
	md   = mmc_blk_get(bdev->bd_disk);
	card = md->queue.card;
	buf  = (unsigned int *)idata->buf;
	pr_info("%s(%d)PON type is %s\n",
		__func__,__LINE__,
		(buf[0]==EXT_CSD_POWER_OFF_SHORT)?
		"EXT_CSD_POWER_OFF_SHORT":
		((buf[0]==EXT_CSD_POWER_OFF_LONG)?
		"EXT_CSD_POWER_OFF_LONG":"Unknow PON Type"));

	if(card &&
		(buf[0] <= EXT_CSD_SLEEP_NOTIFICATION) &&
		(card->ext_csd.rev >= 6) )
    {
        if (export_mmc_can_poweroff_notify(card)){
            /* waitting to send poweroff_notify command */
            pr_info( "Card poweroff-notify-state is EXT_CSD_POWER_ON already.\n");
        }else{
            pr_info( "transfer Card poweroff-notify-state to EXT_CSD_POWER_ON.\n");
            emmc_buf = kmalloc(512, GFP_KERNEL);
            if(!emmc_buf){
                err = -ENOMEM;
                goto ERR_OUT;
            }else{
                memset(emmc_buf, 0, 512);
                //err = mmc_send_ext_csd(card, emmc_buf);
                err = mmc_get_ext_csd(card, &emmc_buf);
		
                if(err){
		            err = -EIO;
                    goto ERR_OUT;
		        }
#if 0
		        for(i=0; i<512; i++){
                    pr_err( "    [%03u]=%02x\n",i,*(emmc_buf+i));
                }
#endif
                if(emmc_buf[34] == EXT_CSD_POWER_ON){
                    card->ext_csd.power_off_notification = EXT_CSD_POWER_ON;

                }else{
                    err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
			                EXT_CSD_POWER_OFF_NOTIFICATION,
			                EXT_CSD_POWER_ON,
			                card->ext_csd.generic_cmd6_time);
	                if (err && err != -EBADMSG){
		                goto ERR_OUT;
	                }

            		/*
            		 * The err can be -EBADMSG or 0,
            		 * so check for success and update the flag
            		 */
            		if (!err){
            			card->ext_csd.power_off_notification = EXT_CSD_POWER_ON;
            		}
                }
            }
        }
        pr_info( "perform poweroff-notify.\n");
		err = export_mmc_poweroff_notify(card, buf[0]);
		if(err){
		    err = -EIO;
            goto ERR_OUT;
		}
    }
ERR_OUT:
    if(emmc_buf)
        kfree(emmc_buf);

    return err;
}
#if 0
void long_byte_swap(unsigned int *sor ,unsigned int len)
{
    unsigned int   i;
    unsigned int   tmp;
    unsigned char* btmp1;
    unsigned char* btmp2;

    btmp2 = (unsigned char* )&tmp;
    for(i=0;i<len;i++){
        sor += i;
        btmp1 = (unsigned char*)sor;
        btmp2[0] = btmp1[3];
        btmp2[1] = btmp1[2];
        btmp2[2] = btmp1[1];
        btmp2[3] = btmp1[0];
        *sor = tmp;
    }
}
#endif
static
int mmc_rtk_get_vender_smart(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata,
	unsigned char* life_info )
{
	struct mmc_blk_data *md;
	struct mmc_card *card;
	struct mmc_command cmd = {0};
	struct mmc_data data = {0};
	struct mmc_request mrq = {NULL};
	struct scatterlist sg;
	unsigned char *buf_t = NULL;
	unsigned char *buf   = NULL;
	int err = 0;
	int i;

/* #define SHOW_TEST_INFO */

	md   = mmc_blk_get(bdev->bd_disk);
    	card = md->queue.card;

    	buf_t = kmalloc(520, GFP_KERNEL);
	if(!buf_t){
	    err = -1;
		goto ERR_OUT;
	}
	buf = (unsigned char *)((unsigned int)buf_t & 0xFFFFFFF8);
	memset(buf,0x0,512);

	/* TSB vandor command about "Device Health command Format" */
	/* send cmd56 with "Device Health Command */
	pr_info("send Device Health Command\n");
	cmd.opcode  = MMC_GEN_CMD;
	cmd.arg     = 0x0;
	cmd.flags   = MMC_RSP_R1 | MMC_CMD_ADTC;
	cmd.data    = &data;
	cmd.mrq     = &mrq;

/*
    depend on FMMTL2-129_19nm e-MMC v4 41alpha_Device Health_121115.pdf
    Device Health Command Format
    0x000         1    Sub Command Number (0x05)
    0x001 ¡V 0x003 3    Dummy Data (0x00)
    0x004 ¡V 0x007 4    Defined Password for Device Health 19nm v4.41£\ (0x63-0x50-0x17-0x00)
    0x009 ¡V 0x1FF 504  Reserved
*/
	buf[0] = 0x05;
	buf[4] = 0x63;
	buf[5] = 0x50;
	buf[6] = 0x17;
	buf[7] = 0x00;

#ifdef SHOW_TEST_INFO
	pr_err("%s(%d)SHOW initial buff\n",__func__,__LINE__);
	for(i=0; i<(512/16);i++){
		pr_err("[%03i~%03i]=%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			(i*8),(i*8)+7,
			buf[(i*8)+ 0], buf[(i*8)+ 1], buf[(i*8)+ 2], buf[(i*8)+ 3],
			buf[(i*8)+ 4], buf[(i*8)+ 5], buf[(i*8)+ 6], buf[(i*8)+ 7],
			buf[(i*8)+ 8], buf[(i*8)+ 9], buf[(i*8)+10], buf[(i*8)+11],
			buf[(i*8)+12], buf[(i*8)+13], buf[(i*8)+14], buf[(i*8)+15]);
	}
	pr_err("\n");
#endif

	data.sg = &sg;
	data.sg_len = 1;
	data.blksz = 0x200;
	data.blocks = 1;

	sg_init_one(data.sg, buf, 512);
	data.flags = MMC_DATA_WRITE;
	mmc_set_data_timeout(&data, card);
	mrq.data = &data;
	mrq.cmd = &cmd;

	/* mmc_claim_host() have called before, do not call again ; */

	mmc_wait_for_req(card->host, &mrq);
	if (cmd.error) {
		pr_err("%s: cmd error %d\n",
			__func__, cmd.error);
		err = cmd.error;
		goto ERR_OUT;
	}

	if (data.error) {
		pr_err("%s: data error %d\n",
			__func__, data.error);
		err = data.error;
		goto ERR_OUT;
	}

	/* get Device Health Response Data */
	/*
	depend on FMMTL2-129_19nm e-MMC v4 41alpha_Device Health_121115.pdf
	Device Health Response Data Format
	0x000           1   Sub Command Number (0x05)
	0x001 ¡V 0x002   2   Reserved (0x00)
	0x003           1   Status
	                A0 : OK
	                E0 : NG
	0x004           1 Total Judgment for 19nm(preliminary)
	                0x01 : New device <10% useful life
	                0x02 : New device <20% useful life
	                0x03 : New device <30% useful life
	                0x04 : Light usage <40% useful life
	                0x05 : Light usage <50% useful life
	                0x06 : Light usage <60% useful life
	                0x07 : Heavy usage <70% useful life
	                0x08 : Heavy usage <80% useful life
	                0x09 : Near EOL <90% useful life
	                0x0A : Near EOL <100% useful life
	                0x0B : EOL >=100% useful life
	                0x0C : EOL
	0x005           1   Reserved
	0x006           1   Reserved
	0x007 ¡V 0x1FF   505 Reserved
	*/
	pr_info("get Device Health Response Data\n");

	memset(buf,0xa5,512);
	cmd.opcode  = MMC_GEN_CMD;
	cmd.arg     = 0x1;
	cmd.flags   = MMC_RSP_R1 | MMC_CMD_ADTC;

	data.sg = &sg;
	data.sg_len = 1;
	data.blksz = 0x200;
	data.blocks = 1;

	sg_init_one(data.sg, buf, 512);
	data.flags = MMC_DATA_READ;
	mmc_set_data_timeout(&data, card);
	mrq.data = &data;
	mrq.cmd  = &cmd;

	mmc_wait_for_req(card->host, &mrq);
	if (cmd.error) {
		pr_err("%s: cmd error %d\n",__func__, cmd.error);
		err = cmd.error;
		goto ERR_OUT;
	}

	if (data.error) {
		pr_err("%s: data error %d\n",__func__, data.error);
		err = data.error;
		goto ERR_OUT;
	}

#ifdef SHOW_TEST_INFO
	pr_err("%s(%d)SHOW buff\n",__func__,__LINE__);
	for(i=0; i<(512/16);i++){
		pr_err("[%03i~%03i]=%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			(i*8),(i*8)+7,
			buf[(i*8)+ 0], buf[(i*8)+ 1], buf[(i*8)+ 2], buf[(i*8)+ 3],
			buf[(i*8)+ 4], buf[(i*8)+ 5], buf[(i*8)+ 6], buf[(i*8)+ 7],
			buf[(i*8)+ 8], buf[(i*8)+ 9], buf[(i*8)+10], buf[(i*8)+11],
			buf[(i*8)+12], buf[(i*8)+13], buf[(i*8)+14], buf[(i*8)+15]);
	}
	pr_err("\n");
#endif
	for(i=0; i<512;i++){
		life_info[i] = buf[i];
	}

#ifdef SHOW_TEST_INFO
	pr_err("%s(%d)SHOW life_info\n",__func__,__LINE__);
	for(i=0; i<(512/16);i++){
		pr_err("[%03i~%03i]=%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
			(i*8),(i*8)+7,
			life_info[(i*8)+ 0], life_info[(i*8)+ 1], life_info[(i*8)+ 2], life_info[(i*8)+ 3],
			life_info[(i*8)+ 4], life_info[(i*8)+ 5], life_info[(i*8)+ 6], life_info[(i*8)+ 7],
			life_info[(i*8)+ 8], life_info[(i*8)+ 9], life_info[(i*8)+10], life_info[(i*8)+11],
			life_info[(i*8)+12], life_info[(i*8)+13], life_info[(i*8)+14], life_info[(i*8)+15]);
	}
	pr_err("\n");
#endif

ERR_OUT:

	if(buf_t)
		kfree(buf_t);

	return err;
}

static
int mmc_rtk_ioctl_smart(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata )
{
	struct mmc_blk_data *md = NULL;
	struct mmc_card *card = NULL;
	u8 *buf;
	u8 ctl = 0;
	int err;

#define MAGIC_ALERT 	(0x01<<0)
#define MMC50_ALERT	(0x01<<1)

	err = -EPERM;
	md   = mmc_blk_get(bdev->bd_disk);
	card = md->queue.card;
	buf  = (u8 *)idata->buf;

/*
    For version 5.0, you can fill the data just like the below.
    (HAL_MMC_Get_SMART_Report(buff, len))
    45 4D 43 35 : E M C 5 <- magic for EMMC 5.0 smart report
    XX : DEVICE_LIFE_TIME_EST_TYP_A [268] <- for MLC
    YY : DEVICE_LIFE_TIME_EST_TYP_B [269] <- for SLC
    ZZ : PRE_EOL_INFO [267]
    000000000: 45 4D 43 35 XX YY ZZ 00 00 00 00 00 00 00 00 00 ........
*/

	pr_info( "\n"
		"buf[0~3]=0x%02x 0x%02x 0x%02x 0x%02x\n",
		buf[0],buf[1],buf[2],buf[3]);
	pr_info( "buf[7~4]=0x%02x 0x%02x 0x%02x 0x%02x\n",
		buf[7],buf[6],buf[5],buf[4]);
	pr_info( "buf[11~8]=0x%02x 0x%02x 0x%02x 0x%02x\n",
		buf[11],buf[10],buf[9],buf[8]);
	if((buf[0] == 0x45)
	&& (buf[1] == 0x48)
	&& (buf[2] == 0x52)
	&& (buf[3] == 0x49))
	{
		ctl |= MAGIC_ALERT;

	}

	if(card){
		if (card->ext_csd.rev >= 7) {
			pr_info("eMMC5.x device.\n");
			pr_info("get ext_cse [267][268][269] for smart info.\n");
			buf[0] = 0x45;
			buf[1] = 0x4D;
			buf[2] = 0x43;
			buf[3] = 0x35;
			buf[4] = card->ext_csd.raw_life_time_est_a;
			buf[5] = card->ext_csd.raw_life_time_est_b;
			buf[6] = card->ext_csd.raw_pre_eol_info;

			if(ctl & MAGIC_ALERT){
				pr_info("get vendor life info.\n");

				pr_info("MMC_NAME=%s\n",mmc_card_name(card));
				if((strcmp(mmc_card_name(card),"008G92") == 0)
				|| (strcmp(mmc_card_name(card),"004GE0") == 0))
				{
					pr_info("device hit\n");
					err = mmc_rtk_get_vender_smart(bdev,idata,(buf+512));
				}else{
					/* if device version not match, return zero. */
					pr_err("MMC_NAME=%s\n",mmc_card_name(card));
					pr_err("device not hit\n");
					err = 0;
				}
			}

			if(!err){
				if (copy_to_user((void __user *)(unsigned long) (idata->ic.data_ptr),
					idata->buf, 1024))
				{
					err = -EFAULT;

				}
			}

		}else{	/* eMMC 4.5 (under eMMC5.0)*/
			pr_info("This is not eMMC5.x device.\n");
			pr_info("get vendor life info.\n");

			pr_info("MMC_NAME=%s\n",mmc_card_name(card));
			if(strcmp(mmc_card_name(card),"008G92") == 0){
				pr_err("device hit\n");
				err = mmc_rtk_get_vender_smart(bdev,idata,(buf+512));
			}else{
				/* if device version not match, return zero. */
				pr_err("MMC_NAME=%s\n",mmc_card_name(card));
				pr_err("device not hit\n");
			}

			if(!err){
				if (copy_to_user((void __user *)(unsigned long) (idata->ic.data_ptr),
					idata->buf, 1024))
				{
					err = -EFAULT;
				}
			}
		}

	}
	return err;
}

#define IOCTL_GET_CID	1
#define IOCTL_GET_CSD	2
#define IOCTL_GET_ECSD	3

static
int mmc_rtk_ioctl_CXD(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata,
	int reg_type )
{
	struct mmc_blk_data *md;
	struct mmc_card *card;
	int err = -EBADMSG;

	md = mmc_blk_get(bdev->bd_disk);
	card = md->queue.card;

	if(card){
		u8 *pcid;

		if(reg_type == IOCTL_GET_CID)
			pcid = (u8 *)card->raw_cid;
		else if(reg_type == IOCTL_GET_CSD)
			pcid = (u8 *)card->raw_csd;
		else{
			WARN_ON(1);
			err = -EFAULT;
			goto ERR_OUT;
		}

		pr_info("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x \n",
			pcid[3] ,pcid[2] ,pcid[1] ,pcid[0],
			pcid[7] ,pcid[6] ,pcid[5] ,pcid[4],
			pcid[11],pcid[10],pcid[9] ,pcid[8],
			pcid[15],pcid[14],pcid[13],pcid[12]);
		
		//memcpy(idata->buf,card->raw_cid,16);
		memcpy(idata->buf,pcid,16);

		/*
		 long_byte_swap((unsigned int*)idata->buf,4);
		*/
		if (copy_to_user((void __user *)(unsigned long) idata->ic.data_ptr,
			idata->buf, 16))
		{
			err = -EFAULT;
		}else{
			err = 0;
		}
	}
ERR_OUT:
	return err;
}


static
int mmc_rtk_ioctl_cmd(
	struct block_device * bdev,
	struct mmc_blk_ioc_data *idata )
{
	struct mmc_blk_data *md;
	struct mmc_card *card;

	u32 rtk_flags;
	u32 cmd_flags;
	u32 *buf;
	int err = 0;

	md = mmc_blk_get(bdev->bd_disk);
	card = md->queue.card;

	rtk_flags = GET_RTK_IOCTL_FLAG(idata->ic.flags);    //((idata->ic.flags)& 0xffff0000)>>RTK_FLAG_SHT;
	cmd_flags = GET_CMD_IOCTL_FLAG(idata->ic.flags);    //idata->ic.flags & (0x0000FFFF);

	buf = (unsigned int *)idata->buf;

	switch(rtk_flags){
	case RTK_IOCTL_OPEN:
		pr_info("RTK_IOCTL_OPEN\n");
		mmc_rtk_ioctl_open(bdev,idata);
		break;
	case RTK_IOCTL_CLOSE:
		pr_info("RTK_IOCTL_CLOSE\n");
		mmc_rtk_ioctl_close(bdev,idata);
		break;
	case RTK_IOCTL_ERASE:
		pr_info("RTK_IOCTL_ERASE\n");
		err = mmc_erase(card, buf[0], buf[1], MMC_TRIM_ARG);
		break;
	case RTK_IOCTL_PON_SHORT:
		pr_info("RTK_IOCTL_PON_SHORT\n");
		buf[0] = EXT_CSD_POWER_OFF_SHORT;
		mmc_rtk_ioctl_power_off_notification(bdev,idata);
		break;
	case RTK_IOCTL_PON_LONG:
		pr_info("RTK_IOCTL_PON_LONG\n");
		buf[0] = EXT_CSD_POWER_OFF_LONG;
		mmc_rtk_ioctl_power_off_notification(bdev,idata);
		break;
	case RTK_IOCTL_SMART_REPORT:
		pr_info("RTK_IOCTL_SMART_REPORT\n");
		mmc_rtk_ioctl_smart(bdev,idata);
		break;
	case RTK_IOCTL_GET_CID:
		pr_info("RTK_IOCTL_GET_CID\n");
		mmc_rtk_ioctl_CXD(bdev,idata,IOCTL_GET_CID);
		break;
	case RTK_IOCTL_GET_CSD:
		pr_info("RTK_IOCTL_GET_CSD\n");
		mmc_rtk_ioctl_CXD(bdev,idata,IOCTL_GET_CSD);
		break;
	default:
		pr_info("vendor cmd%d no support!\n",rtk_flags);
		break;
	}

	return err;
}
#endif  //?#ifdef RTK_IOCTL_OPTION

static int mmc_blk_ioctl_cmd(struct block_device *bdev,
			     struct mmc_ioc_cmd __user *ic_ptr)
{
	struct mmc_blk_ioc_data *idata;
	struct mmc_blk_data *md;
	struct mmc_card *card;
	int err = 0, ioc_err = 0;
#ifdef RTK_IOCTL_OPTION
	unsigned int rtk_flags;
#endif	

	/*
	 * The caller must have CAP_SYS_RAWIO, and must be calling this on the
	 * whole block device, not on a partition.  This prevents overspray
	 * between sibling partitions.
	 */
	if ((!capable(CAP_SYS_RAWIO)) || (bdev != bdev->bd_contains))
		return -EPERM;

	idata = mmc_blk_ioctl_copy_from_user(ic_ptr);
	if (IS_ERR(idata))
		return PTR_ERR(idata);

	md = mmc_blk_get(bdev->bd_disk);
	if (!md) {
		err = -EINVAL;
		goto cmd_err;
	}

	card = md->queue.card;
	if (IS_ERR(card)) {
		err = PTR_ERR(card);
		goto cmd_done;
	}
	
#ifdef RTK_IOCTL_OPTION
	rtk_flags = GET_RTK_IOCTL_FLAG(idata->ic.flags);

	if(rtk_flags){
		pr_info("RTK vendor IOCTL cmd!!\n");

		/* call RTK ioctl HERE */
		mmc_get_card(card);
		err = mmc_rtk_ioctl_cmd(bdev,idata);
		mmc_put_card(card);
		
		ioc_err = 0;
		goto cmd_done;
	}
#endif	

	mmc_get_card(card);

	ioc_err = __mmc_blk_ioctl_cmd(card, md, idata);

	mmc_put_card(card);

	err = mmc_blk_ioctl_copy_to_user(ic_ptr, idata);

cmd_done:
	mmc_blk_put(md);
cmd_err:
	kfree(idata->buf);
	kfree(idata);
	return ioc_err ? ioc_err : err;
}

static int mmc_blk_ioctl_multi_cmd(struct block_device *bdev,
				   struct mmc_ioc_multi_cmd __user *user)
{
	struct mmc_blk_ioc_data **idata = NULL;
	struct mmc_ioc_cmd __user *cmds = user->cmds;
	struct mmc_card *card;
	struct mmc_blk_data *md;
	int i, err = 0, ioc_err = 0;
	__u64 num_of_cmds;

	/*
	 * The caller must have CAP_SYS_RAWIO, and must be calling this on the
	 * whole block device, not on a partition.  This prevents overspray
	 * between sibling partitions.
	 */
	if ((!capable(CAP_SYS_RAWIO)) || (bdev != bdev->bd_contains))
		return -EPERM;

	if (copy_from_user(&num_of_cmds, &user->num_of_cmds,
			   sizeof(num_of_cmds)))
		return -EFAULT;

	if (num_of_cmds > MMC_IOC_MAX_CMDS)
		return -EINVAL;

	idata = kcalloc(num_of_cmds, sizeof(*idata), GFP_KERNEL);
	if (!idata)
		return -ENOMEM;

	for (i = 0; i < num_of_cmds; i++) {
		idata[i] = mmc_blk_ioctl_copy_from_user(&cmds[i]);
		if (IS_ERR(idata[i])) {
			err = PTR_ERR(idata[i]);
			num_of_cmds = i;
			goto cmd_err;
		}
	}

	md = mmc_blk_get(bdev->bd_disk);
	if (!md)
		goto cmd_err;

	card = md->queue.card;
	if (IS_ERR(card)) {
		err = PTR_ERR(card);
		goto cmd_done;
	}

	mmc_get_card(card);

	for (i = 0; i < num_of_cmds && !ioc_err; i++)
		ioc_err = __mmc_blk_ioctl_cmd(card, md, idata[i]);

	mmc_put_card(card);

	/* copy to user if data and response */
	for (i = 0; i < num_of_cmds && !err; i++)
		err = mmc_blk_ioctl_copy_to_user(&cmds[i], idata[i]);

cmd_done:
	mmc_blk_put(md);
cmd_err:
	for (i = 0; i < num_of_cmds; i++) {
		kfree(idata[i]->buf);
		kfree(idata[i]);
	}
	kfree(idata);
	return ioc_err ? ioc_err : err;
}

struct mmc_ext_ioctl_header{
	unsigned int header;				// 0..3
	unsigned int cmd_count;				// 4..7
	unsigned int chk_sum;				// 8..11
	unsigned int reserved;				// 12..15
} __attribute__((packed));

struct mmc_ext_ioctl_subcommand{
	unsigned char type;					// 0
	unsigned char mmc_opcode;			// 1
	unsigned char mmc_flags;			// 2
	unsigned char data_rw;				// 3		0:no data, 1:read, 2:write
	unsigned int  mmc_arg;				// 4..7
	unsigned int  timeout_ms;			// 8..11
	unsigned int  data_size;			// 12..15
	unsigned int  buff;					// 16..19
	unsigned char reserved[8];			// 20..28
	unsigned int  chksum;				// 29..31
} __attribute__((packed));

struct mmc_ext_ioctl{
	struct mmc_ext_ioctl_header header;				// 0..15
	struct mmc_ext_ioctl_subcommand subcmd[15];		// 16..495
	unsigned char reserved[16];						// 496..511
} __attribute__((packed));

static int mmc_blk_ioctl_cmd_extended(struct block_device *bdev,	unsigned int user_cmd, unsigned long user_arg)
{
	struct mmc_blk_data *md;
	struct mmc_card *card;
	struct mmc_command cmd = {0};
	struct mmc_data data = {0};
	struct mmc_request mrq = {0};
	struct scatterlist sg;
	struct mmc_ext_ioctl *cmd_buff = NULL;
	unsigned char *data_buff = NULL;
	unsigned int data_size = 0;
	unsigned int rca;
	unsigned int cid[4];
	unsigned int chksum = 0;
	unsigned int cmd13timeout = 0;
	unsigned int cmd13current = 0;

	int err = 0;
	int i;

	#define EXTIOCTL_SIG 0x84B

	if ((_IOC_TYPE(user_cmd) != MMC_BLOCK_MAJOR) ||
		(_IOC_SIZE(user_cmd) != EXTIOCTL_SIG))
		return -EINVAL;

	if (_IOC_NR(user_cmd) != 'L')
		return -EINVAL;

#define EMMC_LG_SUB_NORMAL				0
#define EMMC_LG_SUB_GET_CID				1

#define EMMC_NO_DATA	0
#define EMMC_DATA_READ	1
#define EMMC_DATA_WRITE	2

#define EMMC_CMD13_TIMESLOT				20

	md = mmc_blk_get(bdev->bd_disk);
	if (!md)	{
		err = -EINVAL;
		mmc_blk_put(md);
		return err;
	}

	card = md->queue.card;
	if (IS_ERR(card))	{
		err = PTR_ERR(card);
		mmc_blk_put(md);
		return err;
	}

	cid[0] = card->raw_cid[0];
	cid[1] = card->raw_cid[1];
	cid[2] = card->raw_cid[2];
	cid[3] = card->raw_cid[3];

	rca = card->rca;

	mmc_claim_host(card->host);

	cmd_buff = NULL;
	cmd_buff = kzalloc(sizeof(struct mmc_ext_ioctl), GFP_KERNEL);
	if (!cmd_buff) {
		mmc_release_host(card->host);
		mmc_blk_put(md);

		err = -ENOMEM;
		return err;
	}

	if (copy_from_user((void *)cmd_buff, (void __user *)user_arg, 0x200)) {
		mmc_release_host(card->host);
		mmc_blk_put(md);

		err = -ENOMEM;
		return err;
	}

	if ((cmd_buff->header.cmd_count + cmd_buff->header.header)
		!= cmd_buff->header.chk_sum) {
		pr_err("EMMC >> EXT IOCTL CMD HEADER chksum ERROR\n");

		mmc_release_host(card->host);
		mmc_blk_put(md);

		err = -ENOMEM;
		return err;
	}

	for (i = 0; i < cmd_buff->header.cmd_count;) {
		chksum = cmd_buff->subcmd[i].type;
		chksum ^= cmd_buff->subcmd[i].mmc_opcode;
		chksum ^= cmd_buff->subcmd[i].mmc_flags;
		chksum ^= cmd_buff->subcmd[i].data_rw;
		chksum ^= cmd_buff->subcmd[i].mmc_arg;
		chksum ^= cmd_buff->subcmd[i].timeout_ms;
		chksum ^= cmd_buff->subcmd[i].data_size;
		chksum ^= cmd_buff->subcmd[i].buff;

		if (chksum != cmd_buff->subcmd[i].chksum) {
			pr_err("EMMC >> EXT IOCTL SUB CMD chksum ERROR\n");

			err = -ENOMEM;
			break;
		}

		if (cmd_buff->subcmd[i].type == EMMC_LG_SUB_GET_CID) {
			if (copy_to_user(
				(void __user *)(cmd_buff->subcmd[i].buff),
				(void *)(&cid[0]), 4 * sizeof(u32))) {
				err = -EFAULT;
				break;
			}

			i++;
			continue;
		}

		cmd.opcode = cmd_buff->subcmd[i].mmc_opcode;
		if (cmd_buff->subcmd[i].mmc_opcode == MMC_SEND_STATUS) {
			cmd.arg = rca << 16;

			if (cmd13timeout == 0) {
				cmd13current = 0;
				if (cmd_buff->subcmd[i].timeout_ms == 0) {
					cmd13timeout = 1000 / EMMC_CMD13_TIMESLOT;
				} else {
					cmd13timeout =
						cmd_buff->subcmd[i].timeout_ms /
						EMMC_CMD13_TIMESLOT;
				}
				cmd13timeout++;
			}
		} else {
			cmd.arg = cmd_buff->subcmd[i].mmc_arg;
			cmd13timeout = 0;
			cmd13current = 0;
		}
		cmd.flags = cmd_buff->subcmd[i].mmc_flags;
		cmd.busy_timeout = 0;
		data_size = cmd_buff->subcmd[i].data_size;

		if (cmd_buff->subcmd[i].data_rw > 0) {
			if (data_buff == NULL) {
				data_buff = kzalloc(data_size, GFP_KERNEL);
				if (!data_buff) {
					err = -ENOMEM;
					data_buff = NULL;
					break;
				}
			}

			data.sg = &sg;
			data.sg_len = 1;
			data.blksz = 512;
			data.blocks = data_size / 512;

			sg_init_one(data.sg, data_buff, data_size);

			if (cmd_buff->subcmd[i].data_rw == EMMC_DATA_READ)
				data.flags = MMC_DATA_READ;
			else
				data.flags = MMC_DATA_WRITE;
			mrq.data = &data;
		} else {
			mrq.data = NULL;
			cmd.data = NULL;
		}

		mrq.cmd = &cmd;

		/* write the data into the buffer */
		if (cmd_buff->subcmd[i].data_rw == EMMC_DATA_WRITE) {
			if (copy_from_user(data_buff,
				(void __user *)(cmd_buff->subcmd[i].buff),
				0x200)) {
				err = -EFAULT;
				break;
			}
		}

		mmc_wait_for_req(card->host, &mrq);

		if (cmd.error) {
			dev_err(mmc_dev(card->host), "%s: cmd error %d\n",
				__func__, cmd.error);
			err = cmd.error;
			break;
		}

		if (cmd_buff->subcmd[i].mmc_opcode == MMC_SEND_STATUS) {
			if ((cmd.resp[0] & 0xF00) != 0x900) {
				if (cmd13current > cmd13timeout) {
					err = -EFAULT;
					break;
				}

				cmd13current++;
				msleep(EMMC_CMD13_TIMESLOT);

				continue;
			} else {
				cmd13current = 0;
				cmd13timeout = 0;
			}
		}

		if (data.error) {
			dev_err(mmc_dev(card->host), "%s: data error %d\n",
				__func__, data.error);
			err = data.error;
			break;
		}

		if (cmd_buff->subcmd[i].data_rw == EMMC_DATA_READ) {
			if (copy_to_user(
				(void __user *)(cmd_buff->subcmd[i].buff),
				data_buff, data_size)) {
				err = -EFAULT;
				break;
			}
		}

		if (data_buff) {
			kfree(data_buff);
			data_buff = NULL;
	 	}

		i++;
	}

	mmc_release_host(card->host);
	mmc_blk_put(md);

	if(cmd_buff)
		kfree(cmd_buff);

	if(data_buff)
		kfree(data_buff);

	return err;
}


#ifdef CONFIG_RTKEMMC_COWORK_WITH_KCPU
#define FW_VERSION_INFO_MAGIC		0xFEDCBA00

/* version info*/
typedef struct tps_fw_version_info_t
{
    unsigned int kernel_version;
    unsigned int audio_version;
    unsigned int video_version;
    unsigned int audio2_version;
    unsigned int video2_version;
    unsigned int kcpu_version;
    unsigned int bootloader_version;
} tps_fw_version_info;


typedef struct  {
	unsigned int			header;
	unsigned int			ops_type;
#define RPC_OPS_GET_FW_VERINFO			0x0
#define RPC_OPS_UPDATE_FW_VERINFO		0x1	
	tps_fw_version_info	fw_verinfo;
}ctl_ver_info;

static int mmc_fw_version_info_parse(struct fw_verinfo __user *ic_ptr)
{
	unsigned long vir_addr;
	unsigned long phy_addr;
	unsigned long size = 0;
	unsigned long ret = 0;

	struct fw_verinfo verinfo;
	ctl_ver_info ctl_verinfo;

	if (copy_from_user(&verinfo, (void __user *)ic_ptr, sizeof(struct fw_verinfo))) {
		pr_err("copy user data to kernel fail!\n");
		return -1;
	}

	ctl_verinfo.header = FW_VERSION_INFO_MAGIC;
	if(verinfo.ops_type == OPS_GET_FW_VERINFO){
		ctl_verinfo.ops_type = RPC_OPS_GET_FW_VERINFO;
		memset(&(ctl_verinfo.fw_verinfo), 0x00, sizeof(tps_fw_version_info));
	}else{
		ctl_verinfo.ops_type = RPC_OPS_UPDATE_FW_VERINFO;
		//memcpy(&(ctl_verinfo.fw_verinfo), verinfo.ptr, sizeof(tps_fw_version_info));
		if (copy_from_user(&(ctl_verinfo.fw_verinfo), (void __user *)(verinfo.ptr), sizeof(tps_fw_version_info))) {
			pr_err("copy user data to kernel fail![%s][%d]\n", __func__,__LINE__);
			return -1;
		}
	}

	size = sizeof(ctl_ver_info);
	
	// allocate buffer
	vir_addr = (unsigned long)dvr_malloc_specific(size, GFP_DCU1);
	phy_addr = (unsigned long)dvr_to_phys((void*)vir_addr);
	if (!phy_addr) {
		pr_err("[%s %d]alloc memory fail\n", __func__, __LINE__);
		return -1;
	}

	memcpy((void *)vir_addr, (void *)&ctl_verinfo, sizeof(ctl_verinfo));

	// do flush
	dmac_flush_range((void *)vir_addr, (void *)(vir_addr + size)) ;
	outer_flush_range((phys_addr_t)phy_addr, (phys_addr_t)phy_addr + size) ;
//*
	// send rpc to kcpu
	if (send_rpc_command(RPC_KCPU, RPC_SCPU_FW_VERSION_REQ, phy_addr, 0, &ret) == RPC_OK){
		pr_notice("[%s][%d]Send rpc to kcpu that get fw version done!\n",__func__,__LINE__);
	}else{
		pr_err("[%s][%d]Send rpc to kcpu fail!\n",__func__,__LINE__);
		goto fail;
	}
//*/
	if(ret != 0){
		pr_err("[%s][%d]kcpu handle rpc to fail!\n",__func__,__LINE__);
		goto fail;
	}

	if(verinfo.ops_type == OPS_GET_FW_VERINFO){
		// process fw version info data
		//copy_to_user((void __user *)ic_ptr->ptr, (void *)vir_addr, sizeof(tps_fw_version_info));
		copy_to_user((void __user *)(verinfo.ptr), (void *)vir_addr, sizeof(tps_fw_version_info));
	}

	// free
	dvr_free((void *)vir_addr);
	return 0;

fail:
	if(vir_addr!= NULL)
		dvr_free((void *)vir_addr);

	return -1;
}
#endif

static int mmc_blk_ioctl(struct block_device *bdev, fmode_t mode,
	unsigned int cmd, unsigned long arg)
{
	switch (cmd) {
	case MMC_IOC_CMD:
		return mmc_blk_ioctl_cmd(bdev,
				(struct mmc_ioc_cmd __user *)arg);
	case MMC_IOC_MULTI_CMD:
		return mmc_blk_ioctl_multi_cmd(bdev,
				(struct mmc_ioc_multi_cmd __user *)arg);
#ifdef CONFIG_RTKEMMC_COWORK_WITH_KCPU	
	case MMC_IOC_FW_VERINFO_OPS_CMD:
		return mmc_fw_version_info_parse((struct fw_verinfo __user *)arg);
#endif
	default:
		return  mmc_blk_ioctl_cmd_extended(bdev, cmd, arg);
	}
}

#ifdef CONFIG_COMPAT
static int mmc_blk_compat_ioctl(struct block_device *bdev, fmode_t mode,
	unsigned int cmd, unsigned long arg)
{
	return mmc_blk_ioctl(bdev, mode, cmd, (unsigned long) compat_ptr(arg));
}
#endif

static const struct block_device_operations mmc_bdops = {
	.open			= mmc_blk_open,
	.release		= mmc_blk_release,
	.getgeo			= mmc_blk_getgeo,
	.owner			= THIS_MODULE,
	.ioctl			= mmc_blk_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl		= mmc_blk_compat_ioctl,
#endif
};

static inline int mmc_blk_part_switch(struct mmc_card *card,
				      struct mmc_blk_data *md)
{
	int ret;
	struct mmc_blk_data *main_md = dev_get_drvdata(&card->dev);

	if (main_md->part_curr == md->part_type)
		return 0;

	if (mmc_card_mmc(card)) {
		u8 part_config = card->ext_csd.part_config;

		part_config &= ~EXT_CSD_PART_CONFIG_ACC_MASK;
		part_config |= md->part_type;

		/*
		 * Workaround for samsung eMMC (manfid:0x15)
		 * rpmb access problem
		 */
		if (card->cid.manfid == 0x15)
			udelay(100);

		ret = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
				 EXT_CSD_PART_CONFIG, part_config,
				 card->ext_csd.part_time*10);
		if (ret)
			return ret;

		card->ext_csd.part_config = part_config;
	}

	main_md->part_curr = md->part_type;
	return 0;
}

static u32 mmc_sd_num_wr_blocks(struct mmc_card *card)
{
	int err;
	u32 result;
	__be32 *blocks;

	struct mmc_request mrq = {NULL};
	struct mmc_command cmd = {0};
	struct mmc_data data = {0};

	struct scatterlist sg;

	cmd.opcode = MMC_APP_CMD;
	cmd.arg = card->rca << 16;
	cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_AC;

	err = mmc_wait_for_cmd(card->host, &cmd, 0);
	if (err)
		return (u32)-1;
	if (!mmc_host_is_spi(card->host) && !(cmd.resp[0] & R1_APP_CMD))
		return (u32)-1;

	memset(&cmd, 0, sizeof(struct mmc_command));

	cmd.opcode = SD_APP_SEND_NUM_WR_BLKS;
	cmd.arg = 0;
	cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;

	data.blksz = 4;
	data.blocks = 1;
	data.flags = MMC_DATA_READ;
	data.sg = &sg;
	data.sg_len = 1;
	mmc_set_data_timeout(&data, card);

	mrq.cmd = &cmd;
	mrq.data = &data;

	blocks = kmalloc(4, GFP_KERNEL);
	if (!blocks)
		return (u32)-1;

	sg_init_one(&sg, blocks, 4);

	mmc_wait_for_req(card->host, &mrq);

	result = ntohl(*blocks);
	kfree(blocks);

	if (cmd.error || data.error)
		result = (u32)-1;

	return result;
}

static int get_card_status(struct mmc_card *card, u32 *status, int retries)
{
	struct mmc_command cmd = {0};
	int err;

	cmd.opcode = MMC_SEND_STATUS;
	if (!mmc_host_is_spi(card->host))
		cmd.arg = card->rca << 16;
	cmd.flags = MMC_RSP_SPI_R2 | MMC_RSP_R1 | MMC_CMD_AC;
	err = mmc_wait_for_cmd(card->host, &cmd, retries);
	if (err == 0)
		*status = cmd.resp[0];
	return err;
}

static int card_busy_detect(struct mmc_card *card, unsigned int timeout_ms,
		bool hw_busy_detect, struct request *req, int *gen_err)
{
	unsigned long timeout = jiffies + msecs_to_jiffies(timeout_ms);
	int err = 0;
	u32 status;

	do {
		err = get_card_status(card, &status, 5);
		if (err) {
			pr_err("%s: error %d requesting status\n",
			       req->rq_disk->disk_name, err);
			return err;
		}

		if (status & R1_ERROR) {
			pr_err("%s: %s: error sending status cmd, status %#x\n",
				req->rq_disk->disk_name, __func__, status);
			*gen_err = 1;
		}

		/* We may rely on the host hw to handle busy detection.*/
		if ((card->host->caps & MMC_CAP_WAIT_WHILE_BUSY) &&
			hw_busy_detect)
			break;

		/*
		 * Timeout if the device never becomes ready for data and never
		 * leaves the program state.
		 */
		if (time_after(jiffies, timeout)) {
			pr_err("%s: Card stuck in programming state! %s %s\n",
				mmc_hostname(card->host),
				req->rq_disk->disk_name, __func__);
			return -ETIMEDOUT;
		}

		/*
		 * Some cards mishandle the status bits,
		 * so make sure to check both the busy
		 * indication and the card state.
		 */
	} while (!(status & R1_READY_FOR_DATA) ||
		 (R1_CURRENT_STATE(status) == R1_STATE_PRG));

	return err;
}

static int send_stop(struct mmc_card *card, unsigned int timeout_ms,
		struct request *req, int *gen_err, u32 *stop_status)
{
	struct mmc_host *host = card->host;
	struct mmc_command cmd = {0};
	int err;
	bool use_r1b_resp = rq_data_dir(req) == WRITE;

	/*
	 * Normally we use R1B responses for WRITE, but in cases where the host
	 * has specified a max_busy_timeout we need to validate it. A failure
	 * means we need to prevent the host from doing hw busy detection, which
	 * is done by converting to a R1 response instead.
	 */
	if (host->max_busy_timeout && (timeout_ms > host->max_busy_timeout))
		use_r1b_resp = false;

	cmd.opcode = MMC_STOP_TRANSMISSION;
	if (use_r1b_resp) {
		cmd.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;
		cmd.busy_timeout = timeout_ms;
	} else {
		cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_AC;
	}

	err = mmc_wait_for_cmd(host, &cmd, 5);
	if (err)
		return err;

	*stop_status = cmd.resp[0];

	/* No need to check card status in case of READ. */
	if (rq_data_dir(req) == READ)
		return 0;

	if (!mmc_host_is_spi(host) &&
		(*stop_status & R1_ERROR)) {
		pr_err("%s: %s: general error sending stop command, resp %#x\n",
			req->rq_disk->disk_name, __func__, *stop_status);
		*gen_err = 1;
	}

	return card_busy_detect(card, timeout_ms, use_r1b_resp, req, gen_err);
}

#define ERR_NOMEDIUM	3
#define ERR_RETRY	2
#define ERR_ABORT	1
#define ERR_CONTINUE	0

static int mmc_blk_cmd_error(struct request *req, const char *name, int error,
	bool status_valid, u32 status)
{
	switch (error) {
	case -EILSEQ:
		/* response crc error, retry the r/w cmd */
		pr_err("%s: %s sending %s command, card status %#x\n",
			req->rq_disk->disk_name, "response CRC error",
			name, status);
		return ERR_RETRY;

	case -ETIMEDOUT:
		pr_err("%s: %s sending %s command, card status %#x\n",
			req->rq_disk->disk_name, "timed out", name, status);
#ifdef CONFIG_MMC_RTKEMMC_PLUS
		/* If the status of pervious cmd is success , retry the r/w cmd */
		if (status_valid)
			return ERR_RETRY;
#else
		/* If the status cmd initially failed, retry the r/w cmd */
		if (!status_valid)
			return ERR_RETRY;
#endif
		/*
		 * If it was a r/w cmd crc error, or illegal command
		 * (eg, issued in wrong state) then retry - we should
		 * have corrected the state problem above.
		 */
		if (status & (R1_COM_CRC_ERROR | R1_ILLEGAL_COMMAND))
			return ERR_RETRY;

		/* Otherwise abort the command */
		return ERR_ABORT;

	default:
		/* We don't understand the error code the driver gave us */
		pr_err("%s: unknown error %d sending read/write command, card status %#x\n",
		       req->rq_disk->disk_name, error, status);
		return ERR_ABORT;
	}
}

/*
 * Initial r/w and stop cmd error recovery.
 * We don't know whether the card received the r/w cmd or not, so try to
 * restore things back to a sane state.  Essentially, we do this as follows:
 * - Obtain card status.  If the first attempt to obtain card status fails,
 *   the status word will reflect the failed status cmd, not the failed
 *   r/w cmd.  If we fail to obtain card status, it suggests we can no
 *   longer communicate with the card.
 * - Check the card state.  If the card received the cmd but there was a
 *   transient problem with the response, it might still be in a data transfer
 *   mode.  Try to send it a stop command.  If this fails, we can't recover.
 * - If the r/w cmd failed due to a response CRC error, it was probably
 *   transient, so retry the cmd.
 * - If the r/w cmd timed out, but we didn't get the r/w cmd status, retry.
 * - If the r/w cmd timed out, and the r/w cmd failed due to CRC error or
 *   illegal cmd, retry.
 * Otherwise we don't understand what happened, so abort.
 */
static int mmc_blk_cmd_recovery(struct mmc_card *card, struct request *req,
	struct mmc_blk_request *brq, int *ecc_err, int *gen_err)
{
	bool prev_cmd_status_valid = true;
	u32 status, stop_status = 0;
	int err, retry;

	if (mmc_card_removed(card))
		return ERR_NOMEDIUM;

	/*
	 * Try to get card status which indicates both the card state
	 * and why there was no response.  If the first attempt fails,
	 * we can't be sure the returned status is for the r/w command.
	 */
	for (retry = 2; retry >= 0; retry--) {
		err = get_card_status(card, &status, 0);
		if (!err)
			break;

		/* Re-tune if needed */
		mmc_retune_recheck(card->host);

		prev_cmd_status_valid = false;
		pr_err("%s: error %d sending status command, %sing\n",
		       req->rq_disk->disk_name, err, retry ? "retry" : "abort");
	}

	/* We couldn't get a response from the card.  Give up. */
	if (err) {
		/* Check if the card is removed */
		if (mmc_detect_card_removed(card->host))
			return ERR_NOMEDIUM;
#ifdef CONFIG_MMC_RTKEMMC_PLUS
		/* retry 5 times anyway */
		return ERR_RETRY;
#else
		return ERR_ABORT;
#endif
	}

	/* Flag ECC errors */
	if ((status & R1_CARD_ECC_FAILED) ||
	    (brq->stop.resp[0] & R1_CARD_ECC_FAILED) ||
	    (brq->cmd.resp[0] & R1_CARD_ECC_FAILED))
		*ecc_err = 1;

	/* Flag General errors */
	if (!mmc_host_is_spi(card->host) && rq_data_dir(req) != READ)
		if ((status & R1_ERROR) ||
			(brq->stop.resp[0] & R1_ERROR)) {
			pr_err("%s: %s: general error sending stop or status command, stop cmd response %#x, card status %#x\n",
			       req->rq_disk->disk_name, __func__,
			       brq->stop.resp[0], status);
			*gen_err = 1;
		}

	/*
	 * Check the current card state.  If it is in some data transfer
	 * mode, tell it to stop (and hopefully transition back to TRAN.)
	 */
	if (R1_CURRENT_STATE(status) == R1_STATE_DATA ||
	    R1_CURRENT_STATE(status) == R1_STATE_RCV) {
		err = send_stop(card,
			DIV_ROUND_UP(brq->data.timeout_ns, 1000000),
			req, gen_err, &stop_status);
		if (err) {
			pr_err("%s: error %d sending stop command\n",
			       req->rq_disk->disk_name, err);
			/*
			 * If the stop cmd also timed out, the card is probably
			 * not present, so abort. Other errors are bad news too.
			 */
			return ERR_ABORT;
		}

		if (stop_status & R1_CARD_ECC_FAILED)
			*ecc_err = 1;
	}

	/* Check for set block count errors */
	if (brq->sbc.error)
		return mmc_blk_cmd_error(req, "SET_BLOCK_COUNT", brq->sbc.error,
				prev_cmd_status_valid, status);

	/* Check for r/w command errors */
	if (brq->cmd.error)
		return mmc_blk_cmd_error(req, "r/w cmd", brq->cmd.error,
				prev_cmd_status_valid, status);

	/* Data errors */
	if (!brq->stop.error)
		return ERR_CONTINUE;

	/* Now for stop errors.  These aren't fatal to the transfer. */
	pr_info("%s: error %d sending stop command, original cmd response %#x, card status %#x\n",
	       req->rq_disk->disk_name, brq->stop.error,
	       brq->cmd.resp[0], status);

	/*
	 * Subsitute in our own stop status as this will give the error
	 * state which happened during the execution of the r/w command.
	 */
	if (stop_status) {
		brq->stop.resp[0] = stop_status;
		brq->stop.error = 0;
	}
	return ERR_CONTINUE;
}

static int mmc_blk_reset(struct mmc_blk_data *md, struct mmc_host *host,
			 int type)
{
	int err;
#ifdef CONFIG_MMC_RTKEMMC_PLUS
	if (md->reset_done & type){
		if(host->card->type == MMC_TYPE_MMC){
			md->reset_cnt++;
			pr_alert("%s: reset anyway; reset_cnt=%d\n",
				mmc_hostname(host),md->reset_cnt);
			if(md->reset_cnt>2){
				/* down mode */
				if(host->caps2 & MMC_CAP2_HS400_1_8V){
					md->reset_cnt = 0;
					pr_alert("%s: Disable HS400 mode\n",mmc_hostname(host));
					host->caps2 &= ~MMC_CAP2_HS400_1_8V;
				}else if (host->caps2 & MMC_CAP2_HS200_1_8V_SDR){
					md->reset_cnt = 0;
					pr_alert("%s: Disable HS200 mode\n",mmc_hostname(host));
					host->caps2 &= ~MMC_CAP2_HS200_1_8V_SDR;
				}
			}
		}else{
			return -EEXIST;
		}
	}
#else
	if (md->reset_done & type)
		return -EEXIST;
#endif
	md->reset_done |= type;
	err = mmc_hw_reset(host);
	/* Ensure we switch back to the correct partition */
	if (err != -EOPNOTSUPP) {
		struct mmc_blk_data *main_md =
			dev_get_drvdata(&host->card->dev);
		int part_err;

		main_md->part_curr = main_md->part_type;
		part_err = mmc_blk_part_switch(host->card, md);
		if (part_err) {
			/*
			 * We have failed to get back into the correct
			 * partition, so we need to abort the whole request.
			 */
			return -ENODEV;
		}
	}
	return err;
}

static inline void mmc_blk_reset_success(struct mmc_blk_data *md, int type)
{
	md->reset_done &= ~type;
#ifdef CONFIG_MMC_RTKEMMC_PLUS
	md->reset_cnt = 0;
#endif
}

int mmc_access_rpmb(struct mmc_queue *mq)
{
	struct mmc_blk_data *md = mq->data;
	/*
	 * If this is a RPMB partition access, return ture
	 */
	if (md && md->part_type == EXT_CSD_PART_CONFIG_ACC_RPMB)
		return true;

	return false;
}

static int mmc_blk_issue_discard_rq(struct mmc_queue *mq, struct request *req)
{
	struct mmc_blk_data *md = mq->data;
	struct mmc_card *card = md->queue.card;
	unsigned int from, nr, arg;
	int err = 0, type = MMC_BLK_DISCARD;

	if (!mmc_can_erase(card)) {
		err = -EOPNOTSUPP;
		goto out;
	}

	from = blk_rq_pos(req);
	nr = blk_rq_sectors(req);

	if (mmc_can_discard(card))
		arg = MMC_DISCARD_ARG;
	else if (mmc_can_trim(card))
		arg = MMC_TRIM_ARG;
	else
		arg = MMC_ERASE_ARG;
retry:
	if (card->quirks & MMC_QUIRK_INAND_CMD38) {
		err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
				 INAND_CMD38_ARG_EXT_CSD,
				 arg == MMC_TRIM_ARG ?
				 INAND_CMD38_ARG_TRIM :
				 INAND_CMD38_ARG_ERASE,
				 0);
		if (err)
			goto out;
	}
	err = mmc_erase(card, from, nr, arg);
out:
	if (err == -EIO && !mmc_blk_reset(md, card->host, type))
		goto retry;
	if (!err)
		mmc_blk_reset_success(md, type);
	blk_end_request(req, err, blk_rq_bytes(req));

	return err ? 0 : 1;
}

static int mmc_blk_issue_secdiscard_rq(struct mmc_queue *mq,
				       struct request *req)
{
	struct mmc_blk_data *md = mq->data;
	struct mmc_card *card = md->queue.card;
	unsigned int from, nr, arg;
	int err = 0, type = MMC_BLK_SECDISCARD;

	if (!(mmc_can_secure_erase_trim(card))) {
		err = -EOPNOTSUPP;
		goto out;
	}

	from = blk_rq_pos(req);
	nr = blk_rq_sectors(req);

	if (mmc_can_trim(card) && !mmc_erase_group_aligned(card, from, nr))
		arg = MMC_SECURE_TRIM1_ARG;
	else
		arg = MMC_SECURE_ERASE_ARG;

retry:
	if (card->quirks & MMC_QUIRK_INAND_CMD38) {
		err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
				 INAND_CMD38_ARG_EXT_CSD,
				 arg == MMC_SECURE_TRIM1_ARG ?
				 INAND_CMD38_ARG_SECTRIM1 :
				 INAND_CMD38_ARG_SECERASE,
				 0);
		if (err)
			goto out_retry;
	}

	err = mmc_erase(card, from, nr, arg);
	if (err == -EIO)
		goto out_retry;
	if (err)
		goto out;

	if (arg == MMC_SECURE_TRIM1_ARG) {
		if (card->quirks & MMC_QUIRK_INAND_CMD38) {
			err = mmc_switch(card, EXT_CSD_CMD_SET_NORMAL,
					 INAND_CMD38_ARG_EXT_CSD,
					 INAND_CMD38_ARG_SECTRIM2,
					 0);
			if (err)
				goto out_retry;
		}

		err = mmc_erase(card, from, nr, MMC_SECURE_TRIM2_ARG);
		if (err == -EIO)
			goto out_retry;
		if (err)
			goto out;
	}

out_retry:
	if (err && !mmc_blk_reset(md, card->host, type))
		goto retry;
	if (!err)
		mmc_blk_reset_success(md, type);
out:
	blk_end_request(req, err, blk_rq_bytes(req));

	return err ? 0 : 1;
}

static int mmc_blk_issue_flush(struct mmc_queue *mq, struct request *req)
{
	struct mmc_blk_data *md = mq->data;
	struct mmc_card *card = md->queue.card;
	int ret = 0;

	ret = mmc_flush_cache(card);
	if (ret)
		ret = -EIO;

	blk_end_request_all(req, ret);

	return ret ? 0 : 1;
}

/*
 * Reformat current write as a reliable write, supporting
 * both legacy and the enhanced reliable write MMC cards.
 * In each transfer we'll handle only as much as a single
 * reliable write can handle, thus finish the request in
 * partial completions.
 */
static inline void mmc_apply_rel_rw(struct mmc_blk_request *brq,
				    struct mmc_card *card,
				    struct request *req)
{
	if (!(card->ext_csd.rel_param & EXT_CSD_WR_REL_PARAM_EN)) {
		/* Legacy mode imposes restrictions on transfers. */
		if (!IS_ALIGNED(brq->cmd.arg, card->ext_csd.rel_sectors))
			brq->data.blocks = 1;

		if (brq->data.blocks > card->ext_csd.rel_sectors)
			brq->data.blocks = card->ext_csd.rel_sectors;
		else if (brq->data.blocks < card->ext_csd.rel_sectors)
			brq->data.blocks = 1;
	}
}

#define CMD_ERRORS							\
	(R1_OUT_OF_RANGE |	/* Command argument out of range */	\
	 R1_ADDRESS_ERROR |	/* Misaligned address */		\
	 R1_BLOCK_LEN_ERROR |	/* Transferred block length incorrect */\
	 R1_WP_VIOLATION |	/* Tried to write to protected block */	\
	 R1_CC_ERROR |		/* Card controller error */		\
	 R1_ERROR)		/* General/unknown error */

static int mmc_blk_err_check(struct mmc_card *card,
			     struct mmc_async_req *areq)
{
	struct mmc_queue_req *mq_mrq = container_of(areq, struct mmc_queue_req,
						    mmc_active);
	struct mmc_blk_request *brq = &mq_mrq->brq;
	struct request *req = mq_mrq->req;
	int need_retune = card->host->need_retune;
	int ecc_err = 0, gen_err = 0;

	/*
	 * sbc.error indicates a problem with the set block count
	 * command.  No data will have been transferred.
	 *
	 * cmd.error indicates a problem with the r/w command.  No
	 * data will have been transferred.
	 *
	 * stop.error indicates a problem with the stop command.  Data
	 * may have been transferred, or may still be transferring.
	 */
	if (brq->sbc.error || brq->cmd.error || brq->stop.error ||
	    brq->data.error) {
		switch (mmc_blk_cmd_recovery(card, req, brq, &ecc_err, &gen_err)) {
		case ERR_RETRY:
			return MMC_BLK_RETRY;
		case ERR_ABORT:
			return MMC_BLK_ABORT;
		case ERR_NOMEDIUM:
			return MMC_BLK_NOMEDIUM;
		case ERR_CONTINUE:
			break;
		}
	}

	/*
	 * Check for errors relating to the execution of the
	 * initial command - such as address errors.  No data
	 * has been transferred.
	 */
	if (brq->cmd.resp[0] & CMD_ERRORS) {
		pr_err("%s: r/w command failed, status = %#x\n",
		       req->rq_disk->disk_name, brq->cmd.resp[0]);
		return MMC_BLK_ABORT;
	}

	/*
	 * Everything else is either success, or a data error of some
	 * kind.  If it was a write, we may have transitioned to
	 * program mode, which we have to wait for it to complete.
	 */
	if (!mmc_host_is_spi(card->host) && rq_data_dir(req) != READ) {
		int err;

		/* Check stop command response */
		if (brq->stop.resp[0] & R1_ERROR) {
			pr_err("%s: %s: general error sending stop command, stop cmd response %#x\n",
			       req->rq_disk->disk_name, __func__,
			       brq->stop.resp[0]);
			gen_err = 1;
		}

		err = card_busy_detect(card, MMC_BLK_TIMEOUT_MS, false, req,
					&gen_err);
		if (err)
			return MMC_BLK_CMD_ERR;
	}

	/* if general error occurs, retry the write operation. */
	if (gen_err) {
		pr_warn("%s: retrying write for general error\n",
				req->rq_disk->disk_name);
		return MMC_BLK_RETRY;
	}

	if (brq->data.error) {
		if (need_retune && !brq->retune_retry_done) {
			pr_info("%s: retrying because a re-tune was needed\n",
				req->rq_disk->disk_name);
			brq->retune_retry_done = 1;
			return MMC_BLK_RETRY;
		}
		pr_err("%s: error %d transferring data, sector %u, nr %u, cmd response %#x, card status %#x\n",
		       req->rq_disk->disk_name, brq->data.error,
		       (unsigned)blk_rq_pos(req),
		       (unsigned)blk_rq_sectors(req),
		       brq->cmd.resp[0], brq->stop.resp[0]);

		if (rq_data_dir(req) == READ) {
			if (ecc_err)
				return MMC_BLK_ECC_ERR;
			return MMC_BLK_DATA_ERR;
		} else {
			return MMC_BLK_CMD_ERR;
		}
	}

	if (!brq->data.bytes_xfered)
		return MMC_BLK_RETRY;

	if (mmc_packed_cmd(mq_mrq->cmd_type)) {
		if (unlikely(brq->data.blocks << 9 != brq->data.bytes_xfered))
			return MMC_BLK_PARTIAL;
		else
			return MMC_BLK_SUCCESS;
	}

	if (blk_rq_bytes(req) != brq->data.bytes_xfered)
		return MMC_BLK_PARTIAL;

	return MMC_BLK_SUCCESS;
}

static int mmc_blk_packed_err_check(struct mmc_card *card,
				    struct mmc_async_req *areq)
{
	struct mmc_queue_req *mq_rq = container_of(areq, struct mmc_queue_req,
			mmc_active);
	struct request *req = mq_rq->req;
	struct mmc_packed *packed = mq_rq->packed;
	int err, check, status;
	u8 *ext_csd;

	BUG_ON(!packed);

	packed->retries--;
	check = mmc_blk_err_check(card, areq);
	err = get_card_status(card, &status, 0);
	if (err) {
		pr_err("%s: error %d sending status command\n",
		       req->rq_disk->disk_name, err);
		return MMC_BLK_ABORT;
	}

	if (status & R1_EXCEPTION_EVENT) {
		err = mmc_get_ext_csd(card, &ext_csd);
		if (err) {
			pr_err("%s: error %d sending ext_csd\n",
			       req->rq_disk->disk_name, err);
			return MMC_BLK_ABORT;
		}

		if ((ext_csd[EXT_CSD_EXP_EVENTS_STATUS] &
		     EXT_CSD_PACKED_FAILURE) &&
		    (ext_csd[EXT_CSD_PACKED_CMD_STATUS] &
		     EXT_CSD_PACKED_GENERIC_ERROR)) {
			if (ext_csd[EXT_CSD_PACKED_CMD_STATUS] &
			    EXT_CSD_PACKED_INDEXED_ERROR) {
				packed->idx_failure =
				  ext_csd[EXT_CSD_PACKED_FAILURE_INDEX] - 1;
				check = MMC_BLK_PARTIAL;
			}
			pr_err("%s: packed cmd failed, nr %u, sectors %u, "
			       "failure index: %d\n",
			       req->rq_disk->disk_name, packed->nr_entries,
			       packed->blocks, packed->idx_failure);
		}
		kfree(ext_csd);
	}

	return check;
}

static void mmc_blk_rw_rq_prep(struct mmc_queue_req *mqrq,
			       struct mmc_card *card,
			       int disable_multi,
			       struct mmc_queue *mq)
{
	u32 readcmd, writecmd;
	struct mmc_blk_request *brq = &mqrq->brq;
	struct request *req = mqrq->req;
	struct mmc_blk_data *md = mq->data;
	bool do_data_tag;

	/*
	 * Reliable writes are used to implement Forced Unit Access and
	 * are supported only on MMCs.
	 */
	bool do_rel_wr = (req->cmd_flags & REQ_FUA) &&
		(rq_data_dir(req) == WRITE) &&
		(md->flags & MMC_BLK_REL_WR);

	memset(brq, 0, sizeof(struct mmc_blk_request));
	brq->mrq.cmd = &brq->cmd;
	brq->mrq.data = &brq->data;

	brq->cmd.arg = blk_rq_pos(req);
	if (!mmc_card_blockaddr(card))
		brq->cmd.arg <<= 9;
	brq->cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;
	brq->data.blksz = 512;
	brq->stop.opcode = MMC_STOP_TRANSMISSION;
	brq->stop.arg = 0;
	brq->data.blocks = blk_rq_sectors(req);

	/*
	 * The block layer doesn't support all sector count
	 * restrictions, so we need to be prepared for too big
	 * requests.
	 */
	if (brq->data.blocks > card->host->max_blk_count)
		brq->data.blocks = card->host->max_blk_count;

	if (brq->data.blocks > 1) {
		/*
		 * After a read error, we redo the request one sector
		 * at a time in order to accurately determine which
		 * sectors can be read successfully.
		 */
		if (disable_multi)
			brq->data.blocks = 1;

		/*
		 * Some controllers have HW issues while operating
		 * in multiple I/O mode
		 */
		if (card->host->ops->multi_io_quirk)
			brq->data.blocks = card->host->ops->multi_io_quirk(card,
						(rq_data_dir(req) == READ) ?
						MMC_DATA_READ : MMC_DATA_WRITE,
						brq->data.blocks);
	}

	if (brq->data.blocks > 1 || do_rel_wr) {
		/* SPI multiblock writes terminate using a special
		 * token, not a STOP_TRANSMISSION request.
		 */
		if (!mmc_host_is_spi(card->host) ||
		    rq_data_dir(req) == READ)
			brq->mrq.stop = &brq->stop;
		readcmd = MMC_READ_MULTIPLE_BLOCK;
		writecmd = MMC_WRITE_MULTIPLE_BLOCK;
	} else {
		brq->mrq.stop = NULL;
		readcmd = MMC_READ_SINGLE_BLOCK;
		writecmd = MMC_WRITE_BLOCK;
	}
	if (rq_data_dir(req) == READ) {
		brq->cmd.opcode = readcmd;
		brq->data.flags |= MMC_DATA_READ;
		if (brq->mrq.stop)
			brq->stop.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 |
					MMC_CMD_AC;
	} else {
		brq->cmd.opcode = writecmd;
		brq->data.flags |= MMC_DATA_WRITE;
		if (brq->mrq.stop)
			brq->stop.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B |
					MMC_CMD_AC;
	}

	if (do_rel_wr)
		mmc_apply_rel_rw(brq, card, req);

	/*
	 * Data tag is used only during writing meta data to speed
	 * up write and any subsequent read of this meta data
	 */
	do_data_tag = (card->ext_csd.data_tag_unit_size) &&
		(req->cmd_flags & REQ_META) &&
		(rq_data_dir(req) == WRITE) &&
		((brq->data.blocks * brq->data.blksz) >=
		 card->ext_csd.data_tag_unit_size);

	/*
	 * Pre-defined multi-block transfers are preferable to
	 * open ended-ones (and necessary for reliable writes).
	 * However, it is not sufficient to just send CMD23,
	 * and avoid the final CMD12, as on an error condition
	 * CMD12 (stop) needs to be sent anyway. This, coupled
	 * with Auto-CMD23 enhancements provided by some
	 * hosts, means that the complexity of dealing
	 * with this is best left to the host. If CMD23 is
	 * supported by card and host, we'll fill sbc in and let
	 * the host deal with handling it correctly. This means
	 * that for hosts that don't expose MMC_CAP_CMD23, no
	 * change of behavior will be observed.
	 *
	 * N.B: Some MMC cards experience perf degradation.
	 * We'll avoid using CMD23-bounded multiblock writes for
	 * these, while retaining features like reliable writes.
	 */
	if ((md->flags & MMC_BLK_CMD23) && mmc_op_multi(brq->cmd.opcode) &&
	    (do_rel_wr || !(card->quirks & MMC_QUIRK_BLK_NO_CMD23) ||
	     do_data_tag)) {
		brq->sbc.opcode = MMC_SET_BLOCK_COUNT;
		brq->sbc.arg = brq->data.blocks |
			(do_rel_wr ? (1 << 31) : 0) |
			(do_data_tag ? (1 << 29) : 0);
		brq->sbc.flags = MMC_RSP_R1 | MMC_CMD_AC;
		brq->mrq.sbc = &brq->sbc;
	}

	mmc_set_data_timeout(&brq->data, card);

	brq->data.sg = mqrq->sg;
	brq->data.sg_len = mmc_queue_map_sg(mq, mqrq);

	/*
	 * Adjust the sg list so it is the same size as the
	 * request.
	 */
	if (brq->data.blocks != blk_rq_sectors(req)) {
		int i, data_size = brq->data.blocks << 9;
		struct scatterlist *sg;

		for_each_sg(brq->data.sg, sg, brq->data.sg_len, i) {
			data_size -= sg->length;
			if (data_size <= 0) {
				sg->length += data_size;
				i++;
				break;
			}
		}
		brq->data.sg_len = i;
	}

	mqrq->mmc_active.mrq = &brq->mrq;
	mqrq->mmc_active.err_check = mmc_blk_err_check;

	mmc_queue_bounce_pre(mqrq);
}

static inline u8 mmc_calc_packed_hdr_segs(struct request_queue *q,
					  struct mmc_card *card)
{
	unsigned int hdr_sz = mmc_large_sector(card) ? 4096 : 512;
	unsigned int max_seg_sz = queue_max_segment_size(q);
	unsigned int len, nr_segs = 0;

	do {
		len = min(hdr_sz, max_seg_sz);
		hdr_sz -= len;
		nr_segs++;
	} while (hdr_sz);

	return nr_segs;
}

static u8 mmc_blk_prep_packed_list(struct mmc_queue *mq, struct request *req)
{
	struct request_queue *q = mq->queue;
	struct mmc_card *card = mq->card;
	struct request *cur = req, *next = NULL;
	struct mmc_blk_data *md = mq->data;
	struct mmc_queue_req *mqrq = mq->mqrq_cur;
	bool en_rel_wr = card->ext_csd.rel_param & EXT_CSD_WR_REL_PARAM_EN;
	unsigned int req_sectors = 0, phys_segments = 0;
	unsigned int max_blk_count, max_phys_segs;
	bool put_back = true;
	u8 max_packed_rw = 0;
	u8 reqs = 0;

	if (!(md->flags & MMC_BLK_PACKED_CMD))
		goto no_packed;

	if ((rq_data_dir(cur) == WRITE) &&
	    mmc_host_packed_wr(card->host))
		max_packed_rw = card->ext_csd.max_packed_writes;

	if (max_packed_rw == 0)
		goto no_packed;

	if (mmc_req_rel_wr(cur) &&
	    (md->flags & MMC_BLK_REL_WR) && !en_rel_wr)
		goto no_packed;

	if (mmc_large_sector(card) &&
	    !IS_ALIGNED(blk_rq_sectors(cur), 8))
		goto no_packed;

	mmc_blk_clear_packed(mqrq);

	max_blk_count = min(card->host->max_blk_count,
			    card->host->max_req_size >> 9);
	if (unlikely(max_blk_count > 0xffff))
		max_blk_count = 0xffff;

	max_phys_segs = queue_max_segments(q);
	req_sectors += blk_rq_sectors(cur);
	phys_segments += cur->nr_phys_segments;

	if (rq_data_dir(cur) == WRITE) {
		req_sectors += mmc_large_sector(card) ? 8 : 1;
		phys_segments += mmc_calc_packed_hdr_segs(q, card);
	}

	do {
		if (reqs >= max_packed_rw - 1) {
			put_back = false;
			break;
		}

		spin_lock_irq(q->queue_lock);
		next = blk_fetch_request(q);
		spin_unlock_irq(q->queue_lock);
		if (!next) {
			put_back = false;
			break;
		}

		if (mmc_large_sector(card) &&
		    !IS_ALIGNED(blk_rq_sectors(next), 8))
			break;

		if (next->cmd_flags & REQ_DISCARD ||
		    next->cmd_flags & REQ_FLUSH)
			break;

		if (rq_data_dir(cur) != rq_data_dir(next))
			break;

		if (mmc_req_rel_wr(next) &&
		    (md->flags & MMC_BLK_REL_WR) && !en_rel_wr)
			break;

		req_sectors += blk_rq_sectors(next);
		if (req_sectors > max_blk_count)
			break;

		phys_segments +=  next->nr_phys_segments;
		if (phys_segments > max_phys_segs)
			break;

		list_add_tail(&next->queuelist, &mqrq->packed->list);
		cur = next;
		reqs++;
	} while (1);

	if (put_back) {
		spin_lock_irq(q->queue_lock);
		blk_requeue_request(q, next);
		spin_unlock_irq(q->queue_lock);
	}

	if (reqs > 0) {
		list_add(&req->queuelist, &mqrq->packed->list);
		mqrq->packed->nr_entries = ++reqs;
		mqrq->packed->retries = reqs;
		return reqs;
	}

no_packed:
	mqrq->cmd_type = MMC_PACKED_NONE;
	return 0;
}

static void mmc_blk_packed_hdr_wrq_prep(struct mmc_queue_req *mqrq,
					struct mmc_card *card,
					struct mmc_queue *mq)
{
	struct mmc_blk_request *brq = &mqrq->brq;
	struct request *req = mqrq->req;
	struct request *prq;
	struct mmc_blk_data *md = mq->data;
	struct mmc_packed *packed = mqrq->packed;
	bool do_rel_wr, do_data_tag;
	u32 *packed_cmd_hdr;
	u8 hdr_blocks;
	u8 i = 1;

	BUG_ON(!packed);

	mqrq->cmd_type = MMC_PACKED_WRITE;
	packed->blocks = 0;
	packed->idx_failure = MMC_PACKED_NR_IDX;

	packed_cmd_hdr = packed->cmd_hdr;
	memset(packed_cmd_hdr, 0, sizeof(packed->cmd_hdr));
	packed_cmd_hdr[0] = (packed->nr_entries << 16) |
		(PACKED_CMD_WR << 8) | PACKED_CMD_VER;
	hdr_blocks = mmc_large_sector(card) ? 8 : 1;

	/*
	 * Argument for each entry of packed group
	 */
	list_for_each_entry(prq, &packed->list, queuelist) {
		do_rel_wr = mmc_req_rel_wr(prq) && (md->flags & MMC_BLK_REL_WR);
		do_data_tag = (card->ext_csd.data_tag_unit_size) &&
			(prq->cmd_flags & REQ_META) &&
			(rq_data_dir(prq) == WRITE) &&
			((brq->data.blocks * brq->data.blksz) >=
			 card->ext_csd.data_tag_unit_size);
		/* Argument of CMD23 */
		packed_cmd_hdr[(i * 2)] =
			(do_rel_wr ? MMC_CMD23_ARG_REL_WR : 0) |
			(do_data_tag ? MMC_CMD23_ARG_TAG_REQ : 0) |
			blk_rq_sectors(prq);
		/* Argument of CMD18 or CMD25 */
		packed_cmd_hdr[((i * 2)) + 1] =
			mmc_card_blockaddr(card) ?
			blk_rq_pos(prq) : blk_rq_pos(prq) << 9;
		packed->blocks += blk_rq_sectors(prq);
		i++;
	}

	memset(brq, 0, sizeof(struct mmc_blk_request));
	brq->mrq.cmd = &brq->cmd;
	brq->mrq.data = &brq->data;
	brq->mrq.sbc = &brq->sbc;
	brq->mrq.stop = &brq->stop;

	brq->sbc.opcode = MMC_SET_BLOCK_COUNT;
	brq->sbc.arg = MMC_CMD23_ARG_PACKED | (packed->blocks + hdr_blocks);
	brq->sbc.flags = MMC_RSP_R1 | MMC_CMD_AC;

	brq->cmd.opcode = MMC_WRITE_MULTIPLE_BLOCK;
	brq->cmd.arg = blk_rq_pos(req);
	if (!mmc_card_blockaddr(card))
		brq->cmd.arg <<= 9;
	brq->cmd.flags = MMC_RSP_SPI_R1 | MMC_RSP_R1 | MMC_CMD_ADTC;

	brq->data.blksz = 512;
	brq->data.blocks = packed->blocks + hdr_blocks;
	brq->data.flags |= MMC_DATA_WRITE;

	brq->stop.opcode = MMC_STOP_TRANSMISSION;
	brq->stop.arg = 0;
	brq->stop.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;

	mmc_set_data_timeout(&brq->data, card);

	brq->data.sg = mqrq->sg;
	brq->data.sg_len = mmc_queue_map_sg(mq, mqrq);

	mqrq->mmc_active.mrq = &brq->mrq;
	mqrq->mmc_active.err_check = mmc_blk_packed_err_check;

	mmc_queue_bounce_pre(mqrq);
}

static int mmc_blk_cmd_err(struct mmc_blk_data *md, struct mmc_card *card,
			   struct mmc_blk_request *brq, struct request *req,
			   int ret)
{
	struct mmc_queue_req *mq_rq;
	mq_rq = container_of(brq, struct mmc_queue_req, brq);

	/*
	 * If this is an SD card and we're writing, we can first
	 * mark the known good sectors as ok.
	 *
	 * If the card is not SD, we can still ok written sectors
	 * as reported by the controller (which might be less than
	 * the real number of written sectors, but never more).
	 */
	if (mmc_card_sd(card)) {
		u32 blocks;

		blocks = mmc_sd_num_wr_blocks(card);
		if (blocks != (u32)-1) {
			ret = blk_end_request(req, 0, blocks << 9);
		}
	} else {
		if (!mmc_packed_cmd(mq_rq->cmd_type))
			ret = blk_end_request(req, 0, brq->data.bytes_xfered);
	}
	return ret;
}

static int mmc_blk_end_packed_req(struct mmc_queue_req *mq_rq)
{
	struct request *prq;
	struct mmc_packed *packed = mq_rq->packed;
	int idx = packed->idx_failure, i = 0;
	int ret = 0;

	BUG_ON(!packed);

	while (!list_empty(&packed->list)) {
		prq = list_entry_rq(packed->list.next);
		if (idx == i) {
			/* retry from error index */
			packed->nr_entries -= idx;
			mq_rq->req = prq;
			ret = 1;

			if (packed->nr_entries == MMC_PACKED_NR_SINGLE) {
				list_del_init(&prq->queuelist);
				mmc_blk_clear_packed(mq_rq);
			}
			return ret;
		}
		list_del_init(&prq->queuelist);
		blk_end_request(prq, 0, blk_rq_bytes(prq));
		i++;
	}

	mmc_blk_clear_packed(mq_rq);
	return ret;
}

static void mmc_blk_abort_packed_req(struct mmc_queue_req *mq_rq)
{
	struct request *prq;
	struct mmc_packed *packed = mq_rq->packed;

	BUG_ON(!packed);

	while (!list_empty(&packed->list)) {
		prq = list_entry_rq(packed->list.next);
		list_del_init(&prq->queuelist);
		blk_end_request(prq, -EIO, blk_rq_bytes(prq));
	}

	mmc_blk_clear_packed(mq_rq);
}

static void mmc_blk_revert_packed_req(struct mmc_queue *mq,
				      struct mmc_queue_req *mq_rq)
{
	struct request *prq;
	struct request_queue *q = mq->queue;
	struct mmc_packed *packed = mq_rq->packed;

	BUG_ON(!packed);

	while (!list_empty(&packed->list)) {
		prq = list_entry_rq(packed->list.prev);
		if (prq->queuelist.prev != &packed->list) {
			list_del_init(&prq->queuelist);
			spin_lock_irq(q->queue_lock);
			blk_requeue_request(mq->queue, prq);
			spin_unlock_irq(q->queue_lock);
		} else {
			list_del_init(&prq->queuelist);
		}
	}

	mmc_blk_clear_packed(mq_rq);
}

static int mmc_blk_issue_rw_rq(struct mmc_queue *mq, struct request *rqc)
{
	struct mmc_blk_data *md = mq->data;
	struct mmc_card *card = md->queue.card;
	struct mmc_blk_request *brq = &mq->mqrq_cur->brq;
	int ret = 1, disable_multi = 0, retry = 0, type, retune_retry_done = 0;
	enum mmc_blk_status status;
	struct mmc_queue_req *mq_rq;
	struct request *req = rqc;
	struct mmc_async_req *areq;
	const u8 packed_nr = 2;
	u8 reqs = 0;

	if (!rqc && !mq->mqrq_prev->req)
		return 0;

	if (rqc)
		reqs = mmc_blk_prep_packed_list(mq, rqc);

	do {
		if (rqc) {
			/*
			 * When 4KB native sector is enabled, only 8 blocks
			 * multiple read or write is allowed
			 */
			if ((brq->data.blocks & 0x07) &&
			    (card->ext_csd.data_sector_size == 4096)) {
				pr_err("%s: Transfer size is not 4KB sector size aligned\n",
					req->rq_disk->disk_name);
				mq_rq = mq->mqrq_cur;
				goto cmd_abort;
			}

			if (reqs >= packed_nr)
				mmc_blk_packed_hdr_wrq_prep(mq->mqrq_cur,
							    card, mq);
			else
				mmc_blk_rw_rq_prep(mq->mqrq_cur, card, 0, mq);
			areq = &mq->mqrq_cur->mmc_active;
		} else
			areq = NULL;
		areq = mmc_start_req(card->host, areq, (int *) &status);
		if (!areq) {
			if (status == MMC_BLK_NEW_REQUEST)
				mq->flags |= MMC_QUEUE_NEW_REQUEST;
			return 0;
		}

		mq_rq = container_of(areq, struct mmc_queue_req, mmc_active);
		brq = &mq_rq->brq;
		req = mq_rq->req;
		type = rq_data_dir(req) == READ ? MMC_BLK_READ : MMC_BLK_WRITE;
		mmc_queue_bounce_post(mq_rq);

		switch (status) {
		case MMC_BLK_SUCCESS:
		case MMC_BLK_PARTIAL:
			/*
			 * A block was successfully transferred.
			 */
			mmc_blk_reset_success(md, type);

			if (mmc_packed_cmd(mq_rq->cmd_type)) {
				ret = mmc_blk_end_packed_req(mq_rq);
				break;
			} else {
				ret = blk_end_request(req, 0,
						brq->data.bytes_xfered);
			}

			/*
			 * If the blk_end_request function returns non-zero even
			 * though all data has been transferred and no errors
			 * were returned by the host controller, it's a bug.
			 */
			if (status == MMC_BLK_SUCCESS && ret) {
				pr_err("%s BUG rq_tot %d d_xfer %d\n",
				       __func__, blk_rq_bytes(req),
				       brq->data.bytes_xfered);
				rqc = NULL;
				goto cmd_abort;
			}
			break;
		case MMC_BLK_CMD_ERR:
			ret = mmc_blk_cmd_err(md, card, brq, req, ret);
			if (mmc_blk_reset(md, card->host, type))
				goto cmd_abort;
			if (!ret)
				goto start_new_req;
			break;
		case MMC_BLK_RETRY:
			retune_retry_done = brq->retune_retry_done;
			if (retry++ < 5)
				break;
			/* Fall through */
		case MMC_BLK_ABORT:
			if (!mmc_blk_reset(md, card->host, type))
				break;
			goto cmd_abort;
		case MMC_BLK_DATA_ERR: {
			int err;

			err = mmc_blk_reset(md, card->host, type);
			if (!err)
				break;
			if (err == -ENODEV ||
				mmc_packed_cmd(mq_rq->cmd_type))
				goto cmd_abort;
			/* Fall through */
		}
		case MMC_BLK_ECC_ERR:
			if (brq->data.blocks > 1) {
				/* Redo read one sector at a time */
				pr_warn("%s: retrying using single block read\n",
					req->rq_disk->disk_name);
				disable_multi = 1;
				break;
			}
			/*
			 * After an error, we redo I/O one sector at a
			 * time, so we only reach here after trying to
			 * read a single sector.
			 */
			ret = blk_end_request(req, -EIO,
						brq->data.blksz);
			if (!ret)
				goto start_new_req;
			break;
		case MMC_BLK_NOMEDIUM:
			goto cmd_abort;
		default:
			pr_err("%s: Unhandled return value (%d)",
					req->rq_disk->disk_name, status);
			goto cmd_abort;
		}

		if (ret) {
			if (mmc_packed_cmd(mq_rq->cmd_type)) {
				if (!mq_rq->packed->retries)
					goto cmd_abort;
				mmc_blk_packed_hdr_wrq_prep(mq_rq, card, mq);
				mmc_start_req(card->host,
					      &mq_rq->mmc_active, NULL);
			} else {

				/*
				 * In case of a incomplete request
				 * prepare it again and resend.
				 */
				mmc_blk_rw_rq_prep(mq_rq, card,
						disable_multi, mq);
				mmc_start_req(card->host,
						&mq_rq->mmc_active, NULL);
			}
			mq_rq->brq.retune_retry_done = retune_retry_done;
		}
	} while (ret);

	return 1;

 cmd_abort:
	if (mmc_packed_cmd(mq_rq->cmd_type)) {
		mmc_blk_abort_packed_req(mq_rq);
	} else {
		if (mmc_card_removed(card))
			req->cmd_flags |= REQ_QUIET;
		while (ret)
			ret = blk_end_request(req, -EIO,
					blk_rq_cur_bytes(req));
	}

 start_new_req:
	if (rqc) {
		if (mmc_card_removed(card)) {
			rqc->cmd_flags |= REQ_QUIET;
			blk_end_request_all(rqc, -EIO);
		} else {
			/*
			 * If current request is packed, it needs to put back.
			 */
			if (mmc_packed_cmd(mq->mqrq_cur->cmd_type))
				mmc_blk_revert_packed_req(mq, mq->mqrq_cur);

			mmc_blk_rw_rq_prep(mq->mqrq_cur, card, 0, mq);
			mmc_start_req(card->host,
				      &mq->mqrq_cur->mmc_active, NULL);
		}
	}

	return 0;
}

static int mmc_blk_issue_rq(struct mmc_queue *mq, struct request *req)
{
	int ret;
	struct mmc_blk_data *md = mq->data;
	struct mmc_card *card = md->queue.card;
	struct mmc_host *host = card->host;
	unsigned long flags;
	unsigned int cmd_flags = req ? req->cmd_flags : 0;

	if (req && !mq->mqrq_prev->req)
		/* claim host only for the first request */
		mmc_get_card(card);

	ret = mmc_blk_part_switch(card, md);
	if (ret) {
		if (req) {
			blk_end_request_all(req, -EIO);
		}
		ret = 0;
		goto out;
	}

	mq->flags &= ~MMC_QUEUE_NEW_REQUEST;
	if (cmd_flags & REQ_DISCARD) {
		/* complete ongoing async transfer before issuing discard */
		if (card->host->areq)
			mmc_blk_issue_rw_rq(mq, NULL);
		if (req->cmd_flags & REQ_SECURE)
			ret = mmc_blk_issue_secdiscard_rq(mq, req);
		else
			ret = mmc_blk_issue_discard_rq(mq, req);
	} else if (cmd_flags & REQ_FLUSH) {
		/* complete ongoing async transfer before issuing flush */
		if (card->host->areq)
			mmc_blk_issue_rw_rq(mq, NULL);
		ret = mmc_blk_issue_flush(mq, req);
	} else {
		if (!req && host->areq) {
			spin_lock_irqsave(&host->context_info.lock, flags);
			host->context_info.is_waiting_last_req = true;
			spin_unlock_irqrestore(&host->context_info.lock, flags);
		}
		ret = mmc_blk_issue_rw_rq(mq, req);
	}

out:
	if ((!req && !(mq->flags & MMC_QUEUE_NEW_REQUEST)) ||
	     (cmd_flags & MMC_REQ_SPECIAL_MASK))
		/*
		 * Release host when there are no more requests
		 * and after special request(discard, flush) is done.
		 * In case sepecial request, there is no reentry to
		 * the 'mmc_blk_issue_rq' with 'mqrq_prev->req'.
		 */
		mmc_put_card(card);
	return ret;
}

static inline int mmc_blk_readonly(struct mmc_card *card)
{
	return mmc_card_readonly(card) ||
	       !(card->csd.cmdclass & CCC_BLOCK_WRITE);
}

static struct mmc_blk_data *mmc_blk_alloc_req(struct mmc_card *card,
					      struct device *parent,
					      sector_t size,
					      bool default_ro,
					      const char *subname,
					      int area_type)
{
	struct mmc_blk_data *md;
	int devidx, ret;

	devidx = find_first_zero_bit(dev_use, max_devices);
	if (devidx >= max_devices)
		return ERR_PTR(-ENOSPC);
	__set_bit(devidx, dev_use);

	md = kzalloc(sizeof(struct mmc_blk_data), GFP_KERNEL);
	if (!md) {
		ret = -ENOMEM;
		goto out;
	}

	/*
	 * !subname implies we are creating main mmc_blk_data that will be
	 * associated with mmc_card with dev_set_drvdata. Due to device
	 * partitions, devidx will not coincide with a per-physical card
	 * index anymore so we keep track of a name index.
	 */
	if (!subname) {
		md->name_idx = find_first_zero_bit(name_use, max_devices);
		__set_bit(md->name_idx, name_use);
	} else
		md->name_idx = ((struct mmc_blk_data *)
				dev_to_disk(parent)->private_data)->name_idx;

	md->area_type = area_type;

	/*
	 * Set the read-only status based on the supported commands
	 * and the write protect switch.
	 */
	md->read_only = mmc_blk_readonly(card);

	md->disk = alloc_disk(perdev_minors);
	if (md->disk == NULL) {
		ret = -ENOMEM;
		goto err_kfree;
	}

	spin_lock_init(&md->lock);
	INIT_LIST_HEAD(&md->part);
	md->usage = 1;

	ret = mmc_init_queue(&md->queue, card, &md->lock, subname);
	if (ret)
		goto err_putdisk;

	md->queue.issue_fn = mmc_blk_issue_rq;
	md->queue.data = md;

	md->disk->major	= MMC_BLOCK_MAJOR;
	md->disk->first_minor = devidx * perdev_minors;
	md->disk->fops = &mmc_bdops;
	md->disk->private_data = md;
	md->disk->queue = md->queue.queue;
	md->disk->driverfs_dev = parent;
	set_disk_ro(md->disk, md->read_only || default_ro);
	if (area_type & (MMC_BLK_DATA_AREA_RPMB | MMC_BLK_DATA_AREA_BOOT))
		md->disk->flags |= GENHD_FL_NO_PART_SCAN;

	/*
	 * As discussed on lkml, GENHD_FL_REMOVABLE should:
	 *
	 * - be set for removable media with permanent block devices
	 * - be unset for removable block devices with permanent media
	 *
	 * Since MMC block devices clearly fall under the second
	 * case, we do not set GENHD_FL_REMOVABLE.  Userspace
	 * should use the block device creation/destruction hotplug
	 * messages to tell when the card is present.
	 */

	snprintf(md->disk->disk_name, sizeof(md->disk->disk_name),
		 "mmcblk%u%s", md->name_idx, subname ? subname : "");

	if (mmc_card_mmc(card))
		blk_queue_logical_block_size(md->queue.queue,
					     card->ext_csd.data_sector_size);
	else
		blk_queue_logical_block_size(md->queue.queue, 512);

	set_capacity(md->disk, size);

	if (mmc_host_cmd23(card->host)) {
		if (mmc_card_mmc(card) ||
		    (mmc_card_sd(card) &&
		     card->scr.cmds & SD_SCR_CMD23_SUPPORT))
			md->flags |= MMC_BLK_CMD23;
	}

	if (mmc_card_mmc(card) &&
	    md->flags & MMC_BLK_CMD23 &&
	    ((card->ext_csd.rel_param & EXT_CSD_WR_REL_PARAM_EN) ||
	     card->ext_csd.rel_sectors)) {
		md->flags |= MMC_BLK_REL_WR;
		blk_queue_flush(md->queue.queue, REQ_FLUSH | REQ_FUA);
	}

	if (mmc_card_mmc(card) &&
	    (area_type == MMC_BLK_DATA_AREA_MAIN) &&
	    (md->flags & MMC_BLK_CMD23) &&
	    card->ext_csd.packed_event_en) {
		if (!mmc_packed_init(&md->queue, card))
			md->flags |= MMC_BLK_PACKED_CMD;
	}

	return md;

 err_putdisk:
	put_disk(md->disk);
 err_kfree:
	kfree(md);
 out:
	return ERR_PTR(ret);
}

static struct mmc_blk_data *mmc_blk_alloc(struct mmc_card *card)
{
	sector_t size;

	if (!mmc_card_sd(card) && mmc_card_blockaddr(card)) {
		/*
		 * The EXT_CSD sector count is in number or 512 byte
		 * sectors.
		 */
		size = card->ext_csd.sectors;
	} else {
		/*
		 * The CSD capacity field is in units of read_blkbits.
		 * set_capacity takes units of 512 bytes.
		 */
		size = (typeof(sector_t))card->csd.capacity
			<< (card->csd.read_blkbits - 9);
	}

	return mmc_blk_alloc_req(card, &card->dev, size, false, NULL,
					MMC_BLK_DATA_AREA_MAIN);
}

static int mmc_blk_alloc_part(struct mmc_card *card,
			      struct mmc_blk_data *md,
			      unsigned int part_type,
			      sector_t size,
			      bool default_ro,
			      const char *subname,
			      int area_type)
{
	char cap_str[10];
	struct mmc_blk_data *part_md;

	part_md = mmc_blk_alloc_req(card, disk_to_dev(md->disk), size, default_ro,
				    subname, area_type);
	if (IS_ERR(part_md))
		return PTR_ERR(part_md);
	part_md->part_type = part_type;
	list_add(&part_md->part, &md->part);

	string_get_size((u64)get_capacity(part_md->disk), 512, STRING_UNITS_2,
			cap_str, sizeof(cap_str));
	pr_info("%s: %s %s partition %u %s\n",
	       part_md->disk->disk_name, mmc_card_id(card),
	       mmc_card_name(card), part_md->part_type, cap_str);
	return 0;
}

/* MMC Physical partitions consist of two boot partitions and
 * up to four general purpose partitions.
 * For each partition enabled in EXT_CSD a block device will be allocatedi
 * to provide access to the partition.
 */

static int mmc_blk_alloc_parts(struct mmc_card *card, struct mmc_blk_data *md)
{
	int idx, ret = 0;

	if (!mmc_card_mmc(card))
		return 0;

	for (idx = 0; idx < card->nr_parts; idx++) {
		if (card->part[idx].size) {
			ret = mmc_blk_alloc_part(card, md,
				card->part[idx].part_cfg,
				card->part[idx].size >> 9,
				card->part[idx].force_ro,
				card->part[idx].name,
				card->part[idx].area_type);
			if (ret)
				return ret;
		}
	}

	return ret;
}

static void mmc_blk_remove_req(struct mmc_blk_data *md)
{
	struct mmc_card *card;

	if (md) {
		/*
		 * Flush remaining requests and free queues. It
		 * is freeing the queue that stops new requests
		 * from being accepted.
		 */
		card = md->queue.card;
		mmc_cleanup_queue(&md->queue);
		if (md->flags & MMC_BLK_PACKED_CMD)
			mmc_packed_clean(&md->queue);
		if (md->disk->flags & GENHD_FL_UP) {
			device_remove_file(disk_to_dev(md->disk), &md->force_ro);
			if ((md->area_type & MMC_BLK_DATA_AREA_BOOT) &&
					card->ext_csd.boot_ro_lockable)
				device_remove_file(disk_to_dev(md->disk),
					&md->power_ro_lock);

			del_gendisk(md->disk);
		}
		mmc_blk_put(md);
	}
}

static void mmc_blk_remove_parts(struct mmc_card *card,
				 struct mmc_blk_data *md)
{
	struct list_head *pos, *q;
	struct mmc_blk_data *part_md;

	__clear_bit(md->name_idx, name_use);
	list_for_each_safe(pos, q, &md->part) {
		part_md = list_entry(pos, struct mmc_blk_data, part);
		list_del(pos);
		mmc_blk_remove_req(part_md);
	}
}

static int mmc_add_disk(struct mmc_blk_data *md)
{
	int ret;
	struct mmc_card *card = md->queue.card;

	add_disk(md->disk);
	md->force_ro.show = force_ro_show;
	md->force_ro.store = force_ro_store;
	sysfs_attr_init(&md->force_ro.attr);
	md->force_ro.attr.name = "force_ro";
	md->force_ro.attr.mode = S_IRUGO | S_IWUSR;
	ret = device_create_file(disk_to_dev(md->disk), &md->force_ro);
	if (ret)
		goto force_ro_fail;

	if ((md->area_type & MMC_BLK_DATA_AREA_BOOT) &&
	     card->ext_csd.boot_ro_lockable) {
		umode_t mode;

		if (card->ext_csd.boot_ro_lock & EXT_CSD_BOOT_WP_B_PWR_WP_DIS)
			mode = S_IRUGO;
		else
			mode = S_IRUGO | S_IWUSR;

		md->power_ro_lock.show = power_ro_lock_show;
		md->power_ro_lock.store = power_ro_lock_store;
		sysfs_attr_init(&md->power_ro_lock.attr);
		md->power_ro_lock.attr.mode = mode;
		md->power_ro_lock.attr.name =
					"ro_lock_until_next_power_on";
		ret = device_create_file(disk_to_dev(md->disk),
				&md->power_ro_lock);
		if (ret)
			goto power_ro_lock_fail;
	}
	return ret;

power_ro_lock_fail:
	device_remove_file(disk_to_dev(md->disk), &md->force_ro);
force_ro_fail:
	del_gendisk(md->disk);

	return ret;
}

#define CID_MANFID_SANDISK	0x2
#define CID_MANFID_TOSHIBA	0x11
#define CID_MANFID_MICRON	0x13
#define CID_MANFID_SAMSUNG	0x15
#define CID_MANFID_KINGSTON	0x70

static const struct mmc_fixup blk_fixups[] =
{
	MMC_FIXUP("SEM02G", CID_MANFID_SANDISK, 0x100, add_quirk,
		  MMC_QUIRK_INAND_CMD38),
	MMC_FIXUP("SEM04G", CID_MANFID_SANDISK, 0x100, add_quirk,
		  MMC_QUIRK_INAND_CMD38),
	MMC_FIXUP("SEM08G", CID_MANFID_SANDISK, 0x100, add_quirk,
		  MMC_QUIRK_INAND_CMD38),
	MMC_FIXUP("SEM16G", CID_MANFID_SANDISK, 0x100, add_quirk,
		  MMC_QUIRK_INAND_CMD38),
	MMC_FIXUP("SEM32G", CID_MANFID_SANDISK, 0x100, add_quirk,
		  MMC_QUIRK_INAND_CMD38),

	/*
	 * Some MMC cards experience performance degradation with CMD23
	 * instead of CMD12-bounded multiblock transfers. For now we'll
	 * black list what's bad...
	 * - Certain Toshiba cards.
	 *
	 * N.B. This doesn't affect SD cards.
	 */
	MMC_FIXUP("SDMB-32", CID_MANFID_SANDISK, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_BLK_NO_CMD23),
	MMC_FIXUP("SDM032", CID_MANFID_SANDISK, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_BLK_NO_CMD23),
	MMC_FIXUP("MMC08G", CID_MANFID_TOSHIBA, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_BLK_NO_CMD23),
	MMC_FIXUP("MMC16G", CID_MANFID_TOSHIBA, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_BLK_NO_CMD23),
	MMC_FIXUP("MMC32G", CID_MANFID_TOSHIBA, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_BLK_NO_CMD23),

	/*
	 * Some Micron MMC cards needs longer data read timeout than
	 * indicated in CSD.
	 */
	MMC_FIXUP(CID_NAME_ANY, CID_MANFID_MICRON, 0x200, add_quirk_mmc,
		  MMC_QUIRK_LONG_READ_TIME),

	/*
	 * On these Samsung MoviNAND parts, performing secure erase or
	 * secure trim can result in unrecoverable corruption due to a
	 * firmware bug.
	 */
	MMC_FIXUP("M8G2FA", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("MAG4FA", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("MBG8FA", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("MCGAFA", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("VAL00M", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("VYL00M", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("KYL00M", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),
	MMC_FIXUP("VZL00M", CID_MANFID_SAMSUNG, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_SEC_ERASE_TRIM_BROKEN),

	/*
	 *  On Some Kingston eMMCs, performing trim can result in
	 *  unrecoverable data conrruption occasionally due to a firmware bug.
	 */
	MMC_FIXUP("V10008", CID_MANFID_KINGSTON, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_TRIM_BROKEN),
	MMC_FIXUP("V10016", CID_MANFID_KINGSTON, CID_OEMID_ANY, add_quirk_mmc,
		  MMC_QUIRK_TRIM_BROKEN),

	END_FIXUP
};

static int mmc_blk_probe(struct mmc_card *card)
{
	struct mmc_blk_data *md, *part_md;
	char cap_str[10];

	/*
	 * Check that the card supports the command class(es) we need.
	 */
	if (!(card->csd.cmdclass & CCC_BLOCK_READ))
		return -ENODEV;

	mmc_fixup_device(card, blk_fixups);

	md = mmc_blk_alloc(card);
	if (IS_ERR(md))
		return PTR_ERR(md);

	string_get_size((u64)get_capacity(md->disk), 512, STRING_UNITS_2,
			cap_str, sizeof(cap_str));
	pr_info("%s: %s %s %s %s\n",
		md->disk->disk_name, mmc_card_id(card), mmc_card_name(card),
		cap_str, md->read_only ? "(ro)" : "");

	if (mmc_blk_alloc_parts(card, md))
		goto out;

	dev_set_drvdata(&card->dev, md);

	if (mmc_add_disk(md))
		goto out;

	list_for_each_entry(part_md, &md->part, part) {
		if (mmc_add_disk(part_md))
			goto out;
	}

	pm_runtime_set_autosuspend_delay(&card->dev, 3000);
	pm_runtime_use_autosuspend(&card->dev);

	/*
	 * Don't enable runtime PM for SD-combo cards here. Leave that
	 * decision to be taken during the SDIO init sequence instead.
	 */
	if (card->type != MMC_TYPE_SD_COMBO) {
		pm_runtime_set_active(&card->dev);
		pm_runtime_enable(&card->dev);
	}

	return 0;

 out:
	mmc_blk_remove_parts(card, md);
	mmc_blk_remove_req(md);
	return 0;
}

static void mmc_blk_remove(struct mmc_card *card)
{
	struct mmc_blk_data *md = dev_get_drvdata(&card->dev);

	mmc_blk_remove_parts(card, md);
	pm_runtime_get_sync(&card->dev);
	mmc_claim_host(card->host);
	mmc_blk_part_switch(card, md);
	mmc_release_host(card->host);
	if (card->type != MMC_TYPE_SD_COMBO)
		pm_runtime_disable(&card->dev);
	pm_runtime_put_noidle(&card->dev);
	mmc_blk_remove_req(md);
	dev_set_drvdata(&card->dev, NULL);
}

static int _mmc_blk_suspend(struct mmc_card *card)
{
	struct mmc_blk_data *part_md;
	struct mmc_blk_data *md = dev_get_drvdata(&card->dev);

	if (md) {
		mmc_queue_suspend(&md->queue);
		list_for_each_entry(part_md, &md->part, part) {
			mmc_queue_suspend(&part_md->queue);
		}
	}
	return 0;
}

static void mmc_blk_shutdown(struct mmc_card *card)
{
	_mmc_blk_suspend(card);
}

#ifdef CONFIG_PM_SLEEP
static int mmc_blk_suspend(struct device *dev)
{
	struct mmc_card *card = mmc_dev_to_card(dev);

	return _mmc_blk_suspend(card);
}

static int mmc_blk_resume(struct device *dev)
{
	struct mmc_blk_data *part_md;
	struct mmc_blk_data *md = dev_get_drvdata(dev);

	if (md) {
		/*
		 * Resume involves the card going into idle state,
		 * so current partition is always the main one.
		 */
		md->part_curr = md->part_type;
		mmc_queue_resume(&md->queue);
		list_for_each_entry(part_md, &md->part, part) {
			mmc_queue_resume(&part_md->queue);
		}
	}
	return 0;
}
#endif

static SIMPLE_DEV_PM_OPS(mmc_blk_pm_ops, mmc_blk_suspend, mmc_blk_resume);

static struct mmc_driver mmc_driver = {
	.drv		= {
		.name	= "mmcblk",
		.pm	= &mmc_blk_pm_ops,
	},
	.probe		= mmc_blk_probe,
	.remove		= mmc_blk_remove,
	.shutdown	= mmc_blk_shutdown,
};

static int __init mmc_blk_init(void)
{
	int res;

	if (perdev_minors != CONFIG_MMC_BLOCK_MINORS)
		pr_info("mmcblk: using %d minors per device\n", perdev_minors);

	max_devices = min(MAX_DEVICES, (1 << MINORBITS) / perdev_minors);

	res = register_blkdev(MMC_BLOCK_MAJOR, "mmc");
	if (res)
		goto out;

	res = mmc_register_driver(&mmc_driver);
	if (res)
		goto out2;

	return 0;
 out2:
	unregister_blkdev(MMC_BLOCK_MAJOR, "mmc");
 out:
	return res;
}

static void __exit mmc_blk_exit(void)
{
	mmc_unregister_driver(&mmc_driver);
	unregister_blkdev(MMC_BLOCK_MAJOR, "mmc");
}

module_init(mmc_blk_init);
module_exit(mmc_blk_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Multimedia Card (MMC) block device driver");

