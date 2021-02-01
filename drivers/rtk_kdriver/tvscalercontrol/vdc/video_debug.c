#include <linux/kconfig.h>			/**< kconfig macro */
#include <linux/types.h>			/**< kernel types */
#include <linux/kernel.h>			/**< kerne header */
#include <linux/stringify.h>			/**< __stringify() macro */
#include <linux/bitops.h>			/**< bits operation */
#include <linux/hashtable.h>			/**< Kernel generic hash table */
#include <linux/kfifo.h>			/**< kfifo */
#include <linux/spinlock.h>			/**< spin lock */
#include <linux/list.h>				/**< hlist */
#include <linux/slab.h>				/**< kmem_cache_xxx */
#include <linux/jiffies.h>			/**< jiffies */
#include <linux/atomic.h>			/**< atomic */

#include <rbus/tv_sb1_ana_reg.h>
#include <rbus/vd_ifd_input_reg.h>
#ifdef CONFIG_ARCH_RTK287X
#include <rbus/vd_ifd_input_108_reg.h>
#endif
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/vdtop_reg.h>

#include <tvscalercontrol/vdc/video.h>
#include <tvscalercontrol/io/ioregdrv.h>

#define VIDEO_LOG "VDBG"
#include "video_log.h"
#include "video_debug.h"

/*----------------------------------------------------------------------------- 
 * Debug record interface
 *----------------------------------------------------------------------------*/
#define REG_REC_HASH_ORDER	5	/**< hash bit order */
#define REG_REC_LAYER_MAX	8	/**< max of record layer */

#define __REC_ATTR_RO (VIDEO_DEBUG_RECORD_ATTR_RO)
#define __REC_ATTR_WO (VIDEO_DEBUG_RECORD_ATTR_WO)
#define __REC_ATTR_RW (VIDEO_DEBUG_RECORD_ATTR_RW)

enum {
	VDC_DBG_BUSY = 0,
};

enum {
	VDC_DBG_REG_READ = 0,
	VDC_DBG_REG_WRITE,
};

/*----------------------------------------------------------------------------*/
struct reg_rec_cfg {
	unsigned int addr;
	int nlayer;
	int attr;
};

struct reg_rec_bkt_elm {
	unsigned int addr;
	unsigned int value;
	unsigned long jiffies;
};

struct reg_rec_bkt {
	unsigned int addr;
	int attr;
	struct hlist_node node;
	DECLARE_KFIFO_PTR(fifo, struct reg_rec_bkt_elm);
	spinlock_t fifo_lock;
};

struct reg_rec {
	DECLARE_HASHTABLE(hash, REG_REC_HASH_ORDER);
	spinlock_t hash_lock;
	atomic_t active_events;
};

struct video_debug {
	struct reg_rec rrec;
	unsigned long flags;
};

/*----------------------------------------------------------------------------*/
static struct video_debug g_video_debug;

/*----------------------------------------------------------------------------*/
static int reg_rec_init(struct reg_rec *rrec);
static void reg_rec_exit(struct reg_rec *rrec);
static int reg_rec_bkt_put_elm(struct reg_rec_bkt *rbkt, unsigned int value);
static int reg_rec_bkt_get_elm(struct reg_rec_bkt *rbkt,
			       struct reg_rec_bkt_elm *elm);
static int reg_rec_hash_put_elm(struct reg_rec *rrec, unsigned int addr,
				unsigned int value, int attr);
static int reg_rec_hash_get_elm(struct reg_rec *rrec,
				struct reg_rec_bkt_elm *elm, unsigned int addr);
static int reg_rec_hash_add_bkt(struct reg_rec *rrec, unsigned int addr,
				int nlayer, int attr);
static void reg_rec_hash_del_bkt(struct reg_rec *rrec, unsigned int addr);
static void reg_rec_hash_del_bkt_all(struct reg_rec *rrec);
static struct reg_rec_bkt *reg_rec_hash_find_bkt(struct reg_rec *rrec,
						 unsigned int addr);

/*----------------------------------------------------------------------------*/
/* point to video debug */
static inline struct video_debug *to_video_debug(void)
{
	return &g_video_debug;
}

/* point to the regoster record  */
static inline struct reg_rec *to_reg_rec(struct video_debug *pdebug)
{
	return pdebug ? &pdebug->rrec : NULL;
}

/* is video decoder is busy */
static inline bool vdc_dbg_is_busy(struct video_debug *pdebug)
{
	return pdebug \
		? (pdebug->flags & BIT_MASK(VDC_DBG_BUSY) ? true : false) \
		: false;
}

/* is address valid ? */
static inline bool is_reg_addr_valid(unsigned int addr)
{
	return (bool)((0xb8000000 & addr) == 0xb8000000);
}

/* is attribute valid ? */
static inline bool is_reg_attr_valid(unsigned int attr)
{
	return (bool)((attr >= __REC_ATTR_RO) && (attr <= __REC_ATTR_RW));
}

/* is debug valid ? */
static inline bool is_video_debug_valid(struct video_debug *pdebug)
{
	return ((!IS_ERR_OR_NULL(pdebug) && vdc_dbg_is_busy(pdebug)) \
		? true : false);
}

/* is debug register record valid ? */
static inline bool is_reg_rec_valid(struct reg_rec *rrec)
{
	return (!IS_ERR_OR_NULL(rrec) ? true : false);
}

/* increase active events */
static inline int reg_rec_inc_active_events(struct reg_rec *rrec)
{
	if (!is_reg_rec_valid(rrec))
		return 0;

	return atomic_inc_return(&rrec->active_events);
}

/* decreass active events */
static inline int reg_rec_dec_active_events(struct reg_rec *rrec)
{
	if (!is_reg_rec_valid(rrec))
		return 0;

	return atomic_add_unless(&rrec->active_events, -1, 0);
}

/* read active events */
static inline int reg_rec_read_active_events(struct reg_rec *rrec)
{
	if (!is_reg_rec_valid(rrec))
		return 0;

	return atomic_read(&rrec->active_events);
}

/* is debug register record hash bucket valid ? */
static inline bool is_reg_rec_bkt_valid(struct reg_rec_bkt *bkt)
{
	return ((!IS_ERR_OR_NULL(bkt) && kfifo_initialized(&bkt->fifo)) \
		? true : false);
}

/* is debug register record element is valid ? */
static inline bool is_reg_rec_bkt_elm_valid(struct reg_rec_bkt_elm *elm)
{
	return (!IS_ERR_OR_NULL(elm) ? true : false);
}

/* print out record */
static inline void reg_rec_bkt_elm_show(struct reg_rec_bkt_elm *elm)
{
	if (is_reg_rec_bkt_elm_valid(elm)) {
		video_logk("jfs %08lx:\t%08x: %08x, bit %*pb\r\n", elm->jiffies,
			   elm->addr, elm->value, 32, &elm->value);
	}
	return;
}

/*----------------------------------------------------------------------------*/
/**
 * Initailize reigster record
 * 
 * @param rrec Point to register record
 * 
 * @return int Return the error code.
 */
int reg_rec_init(struct reg_rec *rrec)
{
	video_logf();

	if (!is_reg_rec_valid(rrec)) {
		video_loge("invalid rrec\n");
		return -EINVAL;
	}

	hash_init(rrec->hash);
	spin_lock_init(&rrec->hash_lock);
	atomic_set(&rrec->active_events, 0);

	return 0;
}

/**
 * Exit register record
 * 
 * @param rrec Point to register record
 */
void reg_rec_exit(struct reg_rec *rrec)
{
	video_logf();

	if (is_reg_rec_valid(rrec))
		reg_rec_hash_del_bkt_all(rrec);
}

/**
 * Put register record element to the bucket
 * 
 * @param rbkt Pointer to the registsr record bucket
 * @param value The register value
 * 
 * @return int It returns 0 if the fifo was full. Otherwise it 
 *         returns the number processed elements.
 */
int reg_rec_bkt_put_elm(struct reg_rec_bkt *rbkt, unsigned int value)
{
	int ret = 0;
	struct reg_rec_bkt_elm elm;
	unsigned long flags;

	video_logf();

	if (!is_reg_rec_bkt_valid(rbkt)) {
		video_loge("invalid rbkt\n");
		return 0;
	}

	/* lock for hash */
	spin_lock_irqsave(&rbkt->fifo_lock, flags);

	if (!kfifo_avail(&rbkt->fifo))
		ret = kfifo_get(&rbkt->fifo, &elm);

	elm.addr = rbkt->addr;
	elm.value = value;
	elm.jiffies = jiffies;

	ret = kfifo_put(&rbkt->fifo, elm);

	/* unlock for hash */
	spin_unlock_irqrestore(&rbkt->fifo_lock, flags);

	return ret;
}

/**
 * Get record element from the bucket
 * 
 * @param rbkt Pointer to the record bucket
 * @param elm Pointer to the record element
 * 
 * @return int It returns 0 if the fifo was empty. Otherwise it 
 *         returns the number processed elements.
 */
int reg_rec_bkt_get_elm(struct reg_rec_bkt *rbkt, struct reg_rec_bkt_elm *elm)
{
	int ret = 0;
	unsigned long flags;

	video_logf();

	if (!is_reg_rec_bkt_valid(rbkt)) {
		video_loge("invalid rbkt\n");
		return 0;
	}

	if (!is_reg_rec_bkt_elm_valid(elm)) {
		video_loge("invalid elm\n");
		return 0;
	}

	/* lock for hash */
	spin_lock_irqsave(&rbkt->fifo_lock, flags);

	ret = kfifo_get(&rbkt->fifo, elm);

	/* unlock for hash */
	spin_unlock_irqrestore(&rbkt->fifo_lock, flags);

	return ret;
}

/**
 * Put register record element to the hash
 * 
 * @param rrec Pointer to the registsr record
 * @param addr The register address 
 * @param value The register value 
 * @param attr Operation read/write attribute
 * 
 * @return int It returns 0 if the fifo was full. Otherwise it 
 *         returns the number processed elements.
 */
int reg_rec_hash_put_elm(struct reg_rec *rrec, unsigned int addr,
			 unsigned int value, int attr)
{
	struct reg_rec_bkt *rbkt = NULL;

	video_logf();

	if (!is_reg_rec_valid(rrec)) {
		video_loge("invalid rrec\n");
		return 0;
	}

	rbkt = reg_rec_hash_find_bkt(rrec, addr);
	if (!is_reg_rec_bkt_valid(rbkt)) {
		video_loge("invalid rbkt\n");
		return -EIO;
	}

	if ((rbkt->attr != __REC_ATTR_RW) && (rbkt->attr != attr)) {
		video_loge("attr %d vs %d is not matched\n", rbkt->attr,
			   attr);
		return -EIO;
	}

	return reg_rec_bkt_put_elm(rbkt, value);
}

/**
 * Get record element by addr
 * 
 * @param rrec Pointer to the record
 * @param elm Pointer to the record element
 * @param addr The address
 * 
 * @return int It returns 0 if the fifo was empty. Otherwise it 
 *         returns the number processed elements.
 */
int reg_rec_hash_get_elm(struct reg_rec *rrec, struct reg_rec_bkt_elm *elm, 
			 unsigned int addr)
{
	int ret = 0;
	struct reg_rec_bkt *rbkt = NULL;

	video_logf();

	if (!is_reg_rec_valid(rrec)) {
		video_loge("invalid rrec\n");
		return 0;
	}

	rbkt = reg_rec_hash_find_bkt(rrec, addr);
	if (is_reg_rec_bkt_valid(rbkt))
		ret = reg_rec_bkt_get_elm(rbkt, elm);

	return ret;
}

/**
 * Add register record bucket to the register record hash
 * 
 * @param rrec Point to the register record
 * @param addr The register record address
 * @param nlayer The number of register record layer 
 * @param attr The register read/write attribute 
 * 
 * @return int Retrun error code
 */
int reg_rec_hash_add_bkt(struct reg_rec *rrec, unsigned int addr, int nlayer,
			 int attr)
{
	int ret = 0;
	struct reg_rec_bkt *rbkt = NULL;
	unsigned long flags;

	video_logf();

	if (!is_reg_rec_valid(rrec)) {
		video_loge("invalid rrec\n");
		return -EINVAL;
	}

	if (nlayer < 0 || nlayer > REG_REC_LAYER_MAX)
		nlayer = REG_REC_LAYER_MAX;

	rbkt = reg_rec_hash_find_bkt(rrec, addr);
	if (!IS_ERR_OR_NULL(rbkt)) {
		video_logi("rbkt addr %08x attr %d -> %d already exist\n", addr,
			   rbkt->attr, attr);
		/* update read/write attribute */
		rbkt->attr = attr;
		return 0;
	}

	rbkt = (struct reg_rec_bkt *)kzalloc(sizeof(struct reg_rec_bkt),
					     GFP_KERNEL);
	if (IS_ERR_OR_NULL(rbkt)) {
		video_loge("no memory for reg_rec_bkt\n");
		return -ENOMEM;
	}

	ret = kfifo_alloc(&rbkt->fifo, nlayer, GFP_KERNEL);
	if (ret < 0) {
		video_loge("no memory for reg_rec_bkt.fifo\n");
		goto out_free_rbkt;
	}

	rbkt->addr = addr;
	spin_lock_init(&rbkt->fifo_lock);
	INIT_HLIST_NODE(&rbkt->node);

	/* lock for hash */
	spin_lock_irqsave(&rrec->hash_lock, flags);

	hash_add(rrec->hash, &rbkt->node, addr);

	/* unlock for hash */
	spin_unlock_irqrestore(&rrec->hash_lock, flags);

	return 0;

out_free_rbkt:
	kfree(rbkt);

	return ret;
}

/**
 * Delete register record bucket to the register record hash
 * 
 * @param rrec Point to the register record
 * @param addr The register record address
 */
void reg_rec_hash_del_bkt(struct reg_rec *rrec, unsigned int addr)
{
	struct reg_rec_bkt *rbkt = NULL;
	unsigned long flags;

	video_logf();

	if (is_reg_rec_valid(rrec)) {
		rbkt = reg_rec_hash_find_bkt(rrec, addr);
		if (is_reg_rec_bkt_valid(rbkt)) {
			/* lock for hash */
			spin_lock_irqsave(&rrec->hash_lock, flags);

			if (hash_hashed(&rbkt->node))
				hash_del(&rbkt->node);

			/* unlock for hash */
			spin_unlock_irqrestore(&rrec->hash_lock, flags);

			kfifo_free(&rbkt->fifo);
			kfree(rbkt);
			rbkt = NULL;
		}
	}
}

/**
 * Delete all register record buckets
 * 
 * @param rrec Point to the register record
 */
void reg_rec_hash_del_bkt_all(struct reg_rec *rrec)
{
	struct reg_rec_bkt *rbkt = NULL;
	struct hlist_node *next = NULL;
	int i = 0;
	unsigned long flags;

	video_logf();

	if (is_reg_rec_valid(rrec)) {
		hash_for_each_safe(rrec->hash, i, next, rbkt, node) {
			if (is_reg_rec_bkt_valid(rbkt)) {
				/* lock for hash */
				spin_lock_irqsave(&rrec->hash_lock, flags);

				if (hash_hashed(&rbkt->node))
					hash_del(&rbkt->node);

				/* unlock for hash */
				spin_unlock_irqrestore(&rrec->hash_lock, flags);

				kfifo_free(&rbkt->fifo);
				kfree(rbkt);
				rbkt = NULL;
			}
		}
	}
}

/**
 * Find the register record backut by address
 * 
 * @param rrec Point to the register record
 * @param addr The register record address
 * 
 * @return struct reg_rec_bkt* Point to the registser record 
 *         bucket
 */
struct reg_rec_bkt *reg_rec_hash_find_bkt(struct reg_rec *rrec, unsigned int addr)
{
	struct reg_rec_bkt *rbkt = NULL;
	unsigned long flags;

	video_logf();

	if (is_reg_rec_valid(rrec)) {
		/* lock for hash */
		spin_lock_irqsave(&rrec->hash_lock, flags);

		hash_for_each_possible(rrec->hash, rbkt, node, addr) {
			if (rbkt && rbkt->addr == addr) {
				video_logi("rbkt %pK addr %08x\n", rbkt, addr);
				break;
			}
		}

		/* unlock for hash */
		spin_unlock_irqrestore(&rrec->hash_lock, flags);
	}

	return rbkt;
}

/**
 * Register record address and layer
 * 
 * @param addr The register address to be recorded
 * @param nlayer The number of layer of the records. If nlayer <
 *               0, use the max of layers. If nlayer > max of
 *               layers, set to the max of layers.
 * @param attr The read/write attribute. 
 *             VIDEO_DEBUG_RECORD_ATTR_RO,
 *             VIDEO_DEBUG_RECORD_ATTR_WO or
 *             VIDEO_DEBUG_RECORD_ATTR_RW.
 * @return int Return the error code
 */
int moudle_video_debug_register_record(unsigned int addr, int nlayer, int attr)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);

	video_logf();

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return -EIO;
	}

	if (!is_reg_attr_valid(attr)) {
		video_loge("invalid attr %d\n", attr);
		return -EINVAL;
	}

	return reg_rec_hash_add_bkt(rrec, addr, nlayer, attr);
}

/**
 * Unregister record address
 * 
 * @param addr The register address to be un-recorded
 */
void moudle_video_debug_unregister_record(unsigned int addr)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);

	video_logf();

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return;
	}

	reg_rec_hash_del_bkt_all(rrec);
}

/**
 * Read and record value by address
 * 
 * @param addr The register address
 * 
 * @return int Return register value.
 */
unsigned int module_video_debug_record_read(unsigned int addr)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);
	unsigned int value = 0xdeaddead;
	int ret = 0;

	video_logf();

	value = IoReg_Read32(addr);

	if (!is_reg_addr_valid(addr)) {
		video_loge("invalid addr %08x val %08x\n", addr, value);
		ret = -EINVAL;
		goto out;
	}

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		ret = -EIO;
		goto out;
	}

	if (reg_rec_read_active_events(rrec) <= 0) {
		video_loge("deactive record\n");
		ret = -EIO;
		goto out;
	}

	ret = reg_rec_hash_put_elm(rrec, addr, value, __REC_ATTR_RO);
	if (ret <= 0) {
		video_loge("put elm fail %d addr %08x value %08x\n", ret,
			   addr, value);
		goto out;
	}

out:
	return value;
}

/**
 * Write and record value by address
 * 
 * @param addr The register address
 * @param value Value to be written
 * 
 * @return int Return error code
 */
int module_video_debug_record_write(unsigned int addr, unsigned int value)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);
	int ret = 0;

	video_logf();

	IoReg_Write32(addr, value);

	if (!is_reg_addr_valid(addr)) {
		video_loge("invalid addr %08x val %08x\n", addr, value);
		ret = -EINVAL;
		goto out;
	}

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		ret = -EIO;
		goto out;
	}

	if (reg_rec_read_active_events(rrec) <= 0) {
		video_loge("deactive record\n");
		ret = -EIO;
		goto out;
	}

	ret = reg_rec_hash_put_elm(rrec, addr, value, __REC_ATTR_WO);
	if (ret <= 0) {
		video_loge("failed to put record %d addr %08x value %08x\n",
			   ret, addr, value);
		goto out;
	}

out:
	return ret;
}

/**
 * Show the record values by address
 * 
 * @param addr The record address
 * 
 * @return int Return errro code
 */
int module_video_debug_record_show(unsigned int addr)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);
	struct reg_rec_bkt_elm elm;
	bool is_show = false;
	int ret = 0;

	video_logf();

	if (!is_reg_addr_valid(addr)) {
		video_loge("invalid addr %08x\n", addr);
		return -EINVAL;
	}

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return -EIO;
	}

	do {
		ret = reg_rec_hash_get_elm(rrec, &elm, addr);
		if (ret <= 0) {
			video_logk("------------[ end here ]------------\r\n");
			break;
		}

		if (!is_show) {
			video_logk("------------[ cut here ]------------\r\n");
			is_show = true;
		}

		reg_rec_bkt_elm_show(&elm);
	} while (1);

	return is_show ? 0 : -EIO;
}

/**
 * Clear record values by address
 * 
 * @param addr The register address
 * 
 * @return int Return error code
 */
int module_video_debug_record_clear(unsigned int addr)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);
	struct reg_rec_bkt_elm elm;
	bool is_clear = false;
	int ret = 0;

	video_logf();

	if (!is_reg_addr_valid(addr)) {
		video_loge("invalid addr %08x\n", addr);
		return -EINVAL;
	}

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return -EIO;
	}

	do {
		ret = reg_rec_hash_get_elm(rrec, &elm, addr);
		if (ret <= 0)
			break;

		if (!is_clear)
			is_clear = true;
	} while (1);

	return is_clear ? 0 : -EIO;
}

int module_video_debug_record_start(void)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return 0;
	}

	return reg_rec_inc_active_events(rrec);
}

int module_video_debug_record_stop(void)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return 0;
	}

	return reg_rec_dec_active_events(rrec);
}

bool module_video_debug_record_active(void)
{
	struct video_debug *pdebug = to_video_debug();
	struct reg_rec *rrec = to_reg_rec(pdebug);

	if (!is_video_debug_valid(pdebug)) {
		video_loge("invalid video debug\n");
		return false;
	}

	return (bool)(reg_rec_read_active_events(rrec) > 0);
}

/*----------------------------------------------------------------------------- 
 * Debug module init/exit functions
 *----------------------------------------------------------------------------*/
#ifdef VIDEO_DEBUG_ENABLE_RECROD
static struct reg_rec_cfg def_reg_rec_tbl[] = {
	{VDTOP_VIDEO_STATUS_REG1_reg, 8, __REC_ATTR_RO}, 
	{VDTOP_VIDEO_STATUS_REG2_reg, 8, __REC_ATTR_RO},
	{VDTOP_VIDEO_STATUS_REG3_reg, 8, __REC_ATTR_RO},
};
#endif /* VIDEO_DEBUG_ENABLE_RECROD */

/*----------------------------------------------------------------------------*/
#ifdef VIDEO_DEBUG_ENABLE_RECROD
static inline void module_video_debug_exit_reg_rec(struct video_debug *pdebug)
{
	struct reg_rec *rrec = to_reg_rec(pdebug);
	int i = 0;

	video_logf();

	for (i = 0; i < ARRAY_SIZE(def_reg_rec_tbl); ++i)
		moudle_video_debug_unregister_record(def_reg_rec_tbl[i].addr);

	reg_rec_exit(rrec);
}

static inline int module_video_debug_init_reg_rec(struct video_debug *pdebug)
{
	struct reg_rec *rrec = to_reg_rec(pdebug);
	int ret = 0;
	int i = 0;

	video_logf();

	ret = reg_rec_init(rrec);
	if (ret < 0) {
		video_loge("reg_rec_init() fails\n");
		return -EIO;
	}

	for (i = 0; i < ARRAY_SIZE(def_reg_rec_tbl); ++i) {
		ret = moudle_video_debug_register_record(
			def_reg_rec_tbl[i].addr,
			def_reg_rec_tbl[i].nlayer,
			def_reg_rec_tbl[i].attr);
		if (ret < 0) {
			video_loge("register record %08x:%d:%d fails\n",
				   def_reg_rec_tbl[i].addr,
				   def_reg_rec_tbl[i].nlayer,
				   def_reg_rec_tbl[i].attr);
			debug_exit_reg_rec(pdebug);
			return -EIO;
		}
	}

	return 0;
}
#else
#define module_video_debug_exit_reg_rec(pdebug) ((void)0)
#define module_video_debug_init_reg_rec(pdebug) (0)
#endif /* VIDEO_DEBUG_ENABLE_RECROD */

/**
 * Initialize the video decoder debug system.
 * 
 * @return int Retrun the error code
 */
int module_video_debug_init(void)
{
	int ret = 0;
	struct video_debug *pdebug = to_video_debug();

	video_logf();

	if (IS_ERR_OR_NULL(pdebug)) {
		video_loge("null pdebug\n");
		return -EINVAL;
	}

	if (test_and_set_bit_lock(VDC_DBG_BUSY, &pdebug->flags)) {
		video_loge("already busy for debug\n");
		return -EBUSY;
	}

	ret = module_video_debug_init_reg_rec(pdebug);
	if (ret < 0) {
		video_loge("failed to init reg record\n");
		goto clear_flags_busy;
	}

	return 0;

clear_flags_busy:
	clear_bit_unlock(VDC_DBG_BUSY, &pdebug->flags);

	return ret;
}

/**
 * Exit the video decoder debug system.
 * 
 * @param d Point to video decoder debug system.
 */
void module_video_debug_exit(void)
{
	struct video_debug *pdebug = to_video_debug();

	video_logf();

	if (!is_video_debug_valid(pdebug))
		return;

	module_video_debug_exit_reg_rec(pdebug);

	clear_bit_unlock(VDC_DBG_BUSY, &pdebug->flags);
}

