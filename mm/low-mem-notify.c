/*
 * mm/low-mem-notify.c
 *
 * Sends low-memory notifications to processes via /dev/low-mem.
 *
 * Copyright (C) 2012 The Chromium OS Authors
 * This program is free software, released under the GPL.
 * Based on a proposal by Minchan Kim
 *
 * A process that polls /dev/low-mem is notified of a low-memory situation.
 * The intent is to allow the process to free some memory before the OOM killer
 * is invoked.
 *
 * A low-memory condition is estimated by subtracting anonymous memory
 * (i.e. process data segments), kernel memory, and a fixed amount of
 * file-backed memory from total memory.  This is just a heuristic, as in
 * general we don't know how much memory can be reclaimed before we try to
 * reclaim it, and that's too expensive or too late.
 *
 * This is tailored to Chromium OS, where a single program (the browser)
 * controls most of the memory, and (currently) no swap space is used.
 */


#include <linux/module.h>
#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/eventfd.h>
#include <linux/sort.h>
#include <linux/mutex.h>
#include <linux/file.h>
#include <linux/list.h>

#include <linux/low-mem-notify.h>
#ifdef CONFIG_SWAP
#include <linux/swap.h>
#endif

#undef DEBUG
#ifdef DEBUG
#define dprintk(msg, args...)       \
		printk("\r\n[%s:%d:%s] " msg, __FILE__, __LINE__, __func__, ## args)
#else
#define dprintk(msg, args...)
#endif

#define DEFAULT_WORKINGSET_SIZE		120
#define DEFAULT_RATIO			1

struct low_mem_threshold {
	struct eventfd_ctx *eventfd;
	unsigned long threshold;
};

struct low_mem_threshold_ary {
	int current_threshold;
	unsigned int size;
	struct low_mem_threshold entries[0];
};

struct low_mem_thresholds {
	/* Primary thresholds array */
	struct low_mem_threshold_ary *primary;
	/* Spare threshold array */
	struct low_mem_threshold_ary *spare;
};

#undef MAX_NAMELEN
#define MAX_NAMELEN	32
struct xreclaimable {
	char name[MAX_NAMELEN];	/* name */
	unsigned long pages;	/* pages */
	unsigned long max_pages;/* max pages */
	struct list_head list;	/* list */
};

//typedef struct xreclaimable xreclaimable_t;

/* protect arrays of thresholds */
struct mutex thresholds_lock;

/* thresholds for memory usage. RCU-protected */
struct low_mem_thresholds thresholds;

/* workingset pages */
atomic_long_t workingset_pages;

/* ratio */
atomic_t ratio;

/* extra raclaimable list */
static LIST_HEAD(xr_list);

/* total extra reclaimable */
atomic_long_t xreclaimable_pages;

/* zram swap */
atomic_t zramswap;

/* freeze flag */
atomic_t freeze;

static void low_mem_notify_threshold(int force);
#ifdef CONFIG_SYSFS
static int sysfs_add_xreclaimable(char *name);
static void sysfs_remove_xreclaimable(char *name);
static void sysfs_reset_xreclaimable(void);
static void sysfs_set_xreclaimable(const char *name, unsigned long size);
#endif
static unsigned long total_pages;

void low_mem_notify(void)
{
	if (atomic_read(&freeze))
		return;

	low_mem_notify_threshold(0);
}

static inline unsigned long _free_pages(void)
{
	unsigned long free = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
	unsigned long file = global_page_state(NR_FILE_PAGES) -
						global_page_state(NR_SHMEM);
#ifdef CONFIG_SWAP
	free += atomic_long_read(&nr_swap_pages);
	file -= total_swapcache_pages();
#endif
	return (free > file) ? free : file;
}

static inline unsigned long _usable_pages(void)
{
	unsigned long free = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
	unsigned long file = global_page_state(NR_FILE_PAGES)
						- global_page_state(NR_SHMEM);
	unsigned long usable;
#ifdef CONFIG_SWAP
	unsigned long swap = atomic_long_read(&nr_swap_pages);
	free += swap;
	free -= total_swapcache_pages();
	if (atomic_read(&zramswap))
		free -= (swap / 3);
#endif
	free += global_page_state(NR_SLAB_RECLAIMABLE);

	usable = free + file - atomic_long_read(&workingset_pages)
				+ atomic_long_read(&xreclaimable_pages);
	return ((long)usable > 0) ? usable : 0;
}

static void low_mem_notify_threshold(int force)
{
	struct low_mem_threshold_ary *t;
	unsigned long free;
	int i;

	rcu_read_lock();
	t = rcu_dereference(thresholds.primary);
	if (!t)
		goto unlock;

	free = _usable_pages(); /* _free_pages(); */

	i = t->current_threshold;

	if (force)
		eventfd_signal(t->entries[i].eventfd, 1);

	for (; i >= 0 && unlikely(t->entries[i].threshold > free); i--)
		eventfd_signal(t->entries[i].eventfd, 1);

	i++;

	for (; i < t->size && unlikely(t->entries[i].threshold <= free); i++)
		eventfd_signal(t->entries[i].eventfd, 1);

	t->current_threshold = i - 1;
unlock:
	rcu_read_unlock();
}

static int compare_thresholds(const void *a, const void *b)
{
	const struct low_mem_threshold *_a = a;
	const struct low_mem_threshold *_b = b;

	if (_a->threshold > _b->threshold)
		return 1;

	if (_a->threshold < _b->threshold)
		return -1;

	return 0;
}

static int low_mem_register_event(struct eventfd_ctx *eventfd,
				unsigned long threshold)
{
	struct low_mem_threshold_ary *new;
	unsigned long free;
	int i, size, ret = 0;

	mutex_lock(&thresholds_lock);

	free = _usable_pages(); /* _free_pages(); */

	if (thresholds.primary)
		low_mem_notify_threshold(0);

	size = thresholds.primary ? thresholds.primary->size + 1 : 1;

	new = kmalloc(sizeof(*new) + size * sizeof(struct low_mem_threshold),
			GFP_KERNEL);
	if (!new) {
		ret = -ENOMEM;
		goto unlock;
	}
	new->size = size;

	if (thresholds.primary) {
		memcpy(new->entries, thresholds.primary->entries, (size - 1) *
				sizeof(struct low_mem_threshold));
	}

	new->entries[size - 1].eventfd = eventfd;
	new->entries[size - 1].threshold = threshold;

	sort(new->entries, size, sizeof(struct low_mem_threshold),
			compare_thresholds, NULL);
	#ifdef DEBUG
	for (i = 0; i < size; i++)
		dprintk("[%d] threshold : %ld\n", i, new->entries[i].threshold);
	#endif

	new->current_threshold = -1;
	for (i = 0; i < size; i++) {
		if (new->entries[i].threshold < free)
			++new->current_threshold;
	}
	dprintk("new current threshold ==> %d\n", new->current_threshold);

	kfree(thresholds.spare);
	thresholds.spare = thresholds.primary;

	rcu_assign_pointer(thresholds.primary, new);

	synchronize_rcu();

unlock:
	mutex_unlock(&thresholds_lock);
	return ret;
}

static void low_mem_unregister_event(struct eventfd_ctx *eventfd)
{
	struct low_mem_threshold_ary *new;
	unsigned long free;
	int i, j, size;

	mutex_lock(&thresholds_lock);

	free = _usable_pages(); /* _free_pages(); */

	size = 0;
	for (i=0; i < thresholds.primary->size; i++) {
		if (thresholds.primary->entries[i].eventfd != eventfd)
			size++;
	}

	if (thresholds.primary->size == size)
		goto unlock;

	new = kmalloc(sizeof(*new) + size * sizeof(struct low_mem_threshold),
			GFP_KERNEL);
	if (!new) {
		goto unlock;
	}
	new->size = size;

	new->current_threshold = -1;
	for (i = 0, j = 0; i < thresholds.primary->size; i++) {
		if (thresholds.primary->entries[i].eventfd == eventfd)
			continue;

		new->entries[j] = thresholds.primary->entries[i];
		if (new->entries[j].threshold <= free)
			++new->current_threshold;

		j++;
	}

	#ifdef DEBUG
	for (i = 0; i < size; i++)
		dprintk("[%d] threshold : %ld\n", i, new->entries[i].threshold);
	#endif

	kfree(thresholds.spare);
	thresholds.spare = thresholds.primary;

	rcu_assign_pointer(thresholds.primary, new);

	synchronize_rcu();
unlock:
	mutex_unlock(&thresholds_lock);
}

static int check_duplicate_event(struct eventfd_ctx *eventfd)
{
	int i;
	mutex_lock(&thresholds_lock);
	for (i=0; i < thresholds.primary->size; i++) {
		if (thresholds.primary->entries[i].eventfd == eventfd) {
			dprintk("eventfd(%d) is duplicated !!\n", eventfd);
			mutex_unlock(&thresholds_lock);
			return 1;
		}
	}
	mutex_unlock(&thresholds_lock);
	return 0;
}

static int low_mem_reset_events(void)
{
	mutex_lock(&thresholds_lock);

	kfree(thresholds.primary);
	kfree(thresholds.spare);

	thresholds.primary = thresholds.spare = NULL;

	mutex_unlock(&thresholds_lock);

	return 0;
}

static void dump_xreclaimables(void)
{
#ifdef DEBUG
	struct xreclaimable *pos;
	rcu_read_lock();
	list_for_each_entry_rcu(pos, &xr_list, list) {
		printk("%s : %ld / %ld\n", pos->name,
				pos->pages, pos->max_pages);
	}
	rcu_read_unlock();
#endif
}

static bool check_xreclaimable(struct xreclaimable *xr)
{
	struct xreclaimable *pos;
	rcu_read_lock();
	list_for_each_entry(pos, &xr_list, list) {
		if (pos == xr) {
			rcu_read_unlock();
			return true;
		}
	}
	rcu_read_unlock();
	return false;
}

static struct xreclaimable * find_xreclaimable(char *name)
{
	struct xreclaimable *pos;
	rcu_read_lock();
	list_for_each_entry_rcu(pos, &xr_list, list) {
		if (strncmp(pos->name, name, MAX_NAMELEN) == 0) {
			rcu_read_unlock();
			return pos;
		}
	}
	rcu_read_unlock();
	return NULL;
}

static struct xreclaimable * add_xreclaimable(char *name)
{
	struct xreclaimable * xr;

	xr = (struct xreclaimable *)kzalloc(sizeof(struct xreclaimable), GFP_KERNEL);

	INIT_LIST_HEAD(&xr->list);
	strcpy(xr->name, name);
	xr->pages = xr->max_pages = 0;

	list_add_tail_rcu(&xr->list, &xr_list);

	dump_xreclaimables();
	return xr;
}

static void remove_xreclaimable(struct xreclaimable *xr)
{
	list_del_rcu(&xr->list);
	kfree(xr);

	dump_xreclaimables();
}

static void set_xreclaimable(struct xreclaimable *xr, unsigned long size)
{
	struct xreclaimable *pos;
	unsigned long total_pages = 0;
	unsigned long pages = size >> PAGE_SHIFT;
	int check = 0;

	rcu_read_lock();
	list_for_each_entry_rcu(pos, &xr_list, list) {
		if (pos == xr) {
			xr->pages = pages;
			if (pages > xr->max_pages)
				xr->max_pages = pages;
			check++;
		}
		total_pages += xr->pages;
	}
	rcu_read_unlock();

	if (!check)
		printk("%s is unknown.\n", xr->name);

	/* update total xreclaimable pages */
	atomic_long_set(&xreclaimable_pages, total_pages);
}

struct xreclaimable * low_mem_notify_add_xreclaimable(char *name)
{
	struct xreclaimable * xr;

	if (MAX_NAMELEN < strlen(name))
		name[MAX_NAMELEN - 1] = '\0';
	dprintk("name : \"%s\"\n", name);

	xr = find_xreclaimable(name);
	if (xr) {
		printk(KERN_ERR "low_mem_notify: duplicate name(%s)\n", name);
		return xr;
	}

	return add_xreclaimable(name);
}
EXPORT_SYMBOL_GPL(low_mem_notify_add_xreclaimable);

void low_mem_notify_remove_xreclaimable(struct xreclaimable *xr)
{
	if (check_xreclaimable(xr))
		remove_xreclaimable(xr);
#ifdef DEBUG
	else
		printk("wrong xr handle : %p\n", (void*)xr);
#endif
}
EXPORT_SYMBOL_GPL(low_mem_notify_remove_xreclaimable);

static struct xreclaimable *_xr_gpupool = NULL;
void low_mem_notify_set_xreclaimable(unsigned long size)
{
	if (!_xr_gpupool) {
		_xr_gpupool = add_xreclaimable("gpupool");
	}

	set_xreclaimable(_xr_gpupool, size);
}
EXPORT_SYMBOL_GPL(low_mem_notify_set_xreclaimable);

void low_mem_notify_set_xreclaimable_size(struct xreclaimable *xr,
						unsigned long size)
{
	if (check_xreclaimable(xr))
		set_xreclaimable(xr, size);
#ifdef DEBUG
	else
		printk("wrong xr handle : %p\n", (void*)xr);
#endif
}
EXPORT_SYMBOL_GPL(low_mem_notify_set_xreclaimable_size);

void low_mem_notify_set_freeze(unsigned long flag)
{
	atomic_set(&freeze, flag);
}
EXPORT_SYMBOL_GPL(low_mem_notify_set_freeze);

#ifdef CONFIG_SYSFS

#define LOW_MEM_ATTR_RO(_name)				      \
	static struct kobj_attribute low_mem_##_name##_attr = \
		__ATTR_RO(_name)

#ifndef __ATTR_WO
#define __ATTR_WO(_name) { \
	.attr	= { .name = __stringify(_name), .mode = S_IWUSR },	\
	.store	= _name##_store,					\
}
#endif

#define LOW_MEM_ATTR_WO(_name)				      \
	static struct kobj_attribute low_mem_##_name##_attr = \
		__ATTR_WO(_name)

#define LOW_MEM_ATTR(_name)				      \
	static struct kobj_attribute low_mem_##_name##_attr = \
		__ATTR(_name, 0644, _name##_show, _name##_store)

static unsigned low_mem_margin_to_minfree(unsigned percent)
{
	return (percent * (total_pages)) / 100;
}

static ssize_t free_pages_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%ld\n", _free_pages());
}
LOW_MEM_ATTR_RO(free_pages);

static ssize_t usable_pages_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	return sprintf(buf, "%ld\n", _usable_pages());
}
LOW_MEM_ATTR_RO(usable_pages);

static ssize_t thresholds_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	struct low_mem_threshold_ary *t;
	ssize_t count = 0;
	int i;

	rcu_read_lock();
	t = rcu_dereference(thresholds.primary);
	if (!t)
		goto unlock;

	for (i = 0; i < t->size; i++) {
		if (i == t->current_threshold)
			count += sprintf(&buf[count], "*");
		count += sprintf(&buf[count], "%ld ", t->entries[i].threshold);
	}
	count += sprintf(&buf[count], "\n");

unlock:
	rcu_read_unlock();
	return count;
}
LOW_MEM_ATTR_RO(thresholds);

static ssize_t level_show(struct kobject *kobj,
				  struct kobj_attribute *attr, char *buf)
{
	struct low_mem_threshold_ary *t;
	ssize_t count = 0;

	rcu_read_lock();
	t = rcu_dereference(thresholds.primary);
	if (!t)
		goto unlock;

	count = sprintf(buf, "%u\n", t->current_threshold);
unlock:
	rcu_read_unlock();
	return count;
}
LOW_MEM_ATTR_RO(level);

static ssize_t event_ctrl_show(struct kobject *kobj,
				  struct kobj_attribute *attr, char *buf)
{
	struct low_mem_threshold_ary *t;
	ssize_t count = 0;

	rcu_read_lock();
	t = rcu_dereference(thresholds.primary);
	if (!t)
		goto unlock;

	count = sprintf(buf, "%u\n", t->size);

unlock:
	rcu_read_unlock();
	return count;
}

static ssize_t event_ctrl_store(struct kobject *kobj,
                                        struct kobj_attribute *attr,
					const char *buf, size_t count)
{
	struct eventfd_ctx *eventfd = NULL;
	struct file *efile = NULL;
	int err, ret = 0;
	long input;
	unsigned int efd;
	unsigned long threshold;
	char *buffer, *endp;

	if(total_pages == 0)
		total_pages = totalram_pages + total_swap_pages;

	/* <event_fd> <threshold> */
	efd = simple_strtoul(buf, &endp, 10);
	if (*endp != ' ')
		return -EINVAL;
	buffer = endp + 1;

	err = kstrtol(buffer, 10, &input);
	if (err)
		return -EINVAL;

	efile = eventfd_fget(efd);
	if (IS_ERR(efile)) {
		ret = PTR_ERR(efile);
		goto fail;
	}

	eventfd = eventfd_ctx_fileget(efile);
	if (IS_ERR(eventfd)) {
		ret = PTR_ERR(eventfd);
		goto fail;
	}

	dprintk("input = %ld, efd = %d\n", input, efd);
	if ((input < 0) && check_duplicate_event(eventfd)) {
		low_mem_unregister_event(eventfd);
		ret = count;
		goto out;
	}

	if (atomic_read(&ratio))
		threshold = low_mem_margin_to_minfree(input);
	else
		threshold = (input < 0) ? total_pages : input;

	ret = low_mem_register_event(eventfd, threshold);
	if (ret)
		goto fail;

	fput(efile);

	return count;

fail:

	if(eventfd && !IS_ERR(eventfd))
		eventfd_ctx_put(eventfd);
out:
	if (!IS_ERR_OR_NULL(efile))
		fput(efile);

	return ret;
}
LOW_MEM_ATTR(event_ctrl);

static ssize_t reset_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	/* reset thresholds */
	low_mem_reset_events();

	return count;
}
LOW_MEM_ATTR_WO(reset);

static ssize_t workingset_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	size_t count;
	count = sprintf(buf, "%ld\n", atomic_long_read(&workingset_pages));
	return count;
}

static ssize_t workingset_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	unsigned long size = memparse(buf, NULL);
	if (!size)
		return -EINVAL;

	atomic_long_set(&workingset_pages, size >> PAGE_SHIFT);

	return count;
}
LOW_MEM_ATTR(workingset);

static ssize_t xreclaimable_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	struct xreclaimable *xr;
	size_t count = 0;

	rcu_read_lock();
	list_for_each_entry_rcu(xr, &xr_list, list) {
		count += sprintf(&buf[count], "%s : %ld k/ %ld k\n", xr->name,
				xr->pages<<2, xr->max_pages<<2);
	}
	rcu_read_unlock();

	return count;
}
#if 1
static ssize_t xreclaimable_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	/* for backward compatibility */
	unsigned long size = memparse(buf, NULL);
	if (!size)
		return -EINVAL;
	low_mem_notify_set_xreclaimable(size);
	return count;
}
LOW_MEM_ATTR(xreclaimable);
#else
LOW_MEM_ATTR_RO(xreclaimable);
#endif
static ssize_t xreclaimable_ctrl_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	int argc;
	char **argv, *tmp;
	unsigned long size = 0;

	tmp = strstrip((char*)buf);
	argv = argv_split(GFP_KERNEL, tmp, &argc);

	dprintk("argc = %d, argv = \"%s\"\n", argc, tmp);

	if (argc == 1 && strcmp(argv[0], "reset") == 0) {
		sysfs_reset_xreclaimable();
		goto out;
	}

	if (strcmp(argv[0], "add") == 0)
		sysfs_add_xreclaimable(argv[1]);
	else if (strcmp(argv[0], "rm") == 0)
		sysfs_remove_xreclaimable(argv[1]);
	else if (argc > 2 && strcmp(argv[0], "set") == 0) {
		size = memparse(argv[2], NULL);
		if (!size) {
			argv_free(argv);
			return -EINVAL;
		}
		sysfs_set_xreclaimable(argv[1], size);
	}
	else
		printk("xreclaimable : wrong commands(%s)\n", buf);

out:
	argv_free(argv);
	return count;
}
LOW_MEM_ATTR_WO(xreclaimable_ctrl);

static ssize_t ratio_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	size_t count;
	count = sprintf(buf, "%d\n", atomic_read(&ratio));
	return count;
}

static ssize_t ratio_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	unsigned long t;
	char *tmp;
	int ret;

	tmp = strstrip((char*)buf);
	if (strlen(tmp) == 0)
		return 0;

	ret = kstrtoul(tmp, 10, &t);
	if (ret)
		return -EINVAL;

	atomic_set(&ratio, (t > 0) ? 1 : 0);

	return count;
}
LOW_MEM_ATTR(ratio);

static ssize_t zramswap_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	size_t count;
	count = sprintf(buf, "%d\n", atomic_read(&zramswap));
	return count;
}

static ssize_t zramswap_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	unsigned long t;
	char *tmp;
	int ret;

	tmp = strstrip((char*)buf);
	if (strlen(tmp) == 0)
		return 0;

	ret = kstrtoul(tmp, 10, &t);
	if (ret)
		return -EINVAL;

	atomic_set(&zramswap, (t > 0) ? 1 : 0);

	return count;
}
LOW_MEM_ATTR(zramswap);

static ssize_t force_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	if (atomic_read(&freeze))
		return count;

	low_mem_notify_threshold(1);
	return count;
}
LOW_MEM_ATTR_WO(force);

static ssize_t freeze_show(struct kobject *kobj,
				struct kobj_attribute *attr, char *buf)
{
	size_t count;
	count = sprintf(buf, "%d\n", atomic_read(&freeze));
	return count;
}

static ssize_t freeze_store(struct kobject *kobj,
				struct kobj_attribute *attr,
				const char *buf, size_t count)
{
	unsigned long t;
	char *tmp;
	int ret;

	tmp = strstrip((char*)buf);
	if (strlen(tmp) == 0)
		return 0;

	ret = kstrtoul(tmp, 10, &t);
	if (ret)
		return -EINVAL;

	low_mem_notify_set_freeze((t > 0) ? 1 : 0);
	return count;
}
LOW_MEM_ATTR(freeze);

static ssize_t usable_stat_show(struct kobject *kobj,
				  struct kobj_attribute *attr, char *buf)
{
	unsigned long free = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
	unsigned long file = global_page_state(NR_FILE_PAGES)
						- global_page_state(NR_SHMEM);
	unsigned long slab_reclaimable = global_page_state(NR_SLAB_RECLAIMABLE);
	unsigned long xreclaimable = atomic_long_read(&xreclaimable_pages);
	unsigned long workingset = atomic_long_read(&workingset_pages);
	unsigned long usable;
	ssize_t count = 0;
#ifdef CONFIG_SWAP
	unsigned long swap = atomic_long_read(&nr_swap_pages);
	unsigned long swapcache = total_swapcache_pages();
	unsigned long zramuse = 0;

	if (atomic_read(&zramswap))
		zramuse = (swap / 3);
#else
	unsigned long swap = 0;
	unsigned long swapcache = 0;
	unsigned long zramuse = 0;
#endif

	usable = free + swap - zramuse + file - swapcache + slab_reclaimable + xreclaimable - workingset;

	count  = sprintf(&buf[count], "usable pages :         %8lu\n", usable);
	count += sprintf(&buf[count], "(+) free :             %8lu\n", free);
	count += sprintf(&buf[count], "(+) swap :             %8lu\n", swap);
	count += sprintf(&buf[count], "(-) zramuse :          %8lu\n", zramuse);
	count += sprintf(&buf[count], "(+) file :             %8lu\n", file);
	count += sprintf(&buf[count], "(-) swapcache :        %8lu\n", swapcache);
	count += sprintf(&buf[count], "(+) slab_reclaimable : %8lu\n", slab_reclaimable);
	count += sprintf(&buf[count], "(+) xreclaimable :     %8lu\n", xreclaimable);
	count += sprintf(&buf[count], "(+) workingset :       %8lu\n", workingset);
	count += sprintf(&buf[count], "thresholds : ");
	count += thresholds_show(kobj, attr, &buf[count]);
	count += sprintf(&buf[count], "xreclaimable : ");
	count += xreclaimable_show(kobj, attr, &buf[count]);
	count += sprintf(&buf[count], "\n");

	return count;
}
LOW_MEM_ATTR_RO(usable_stat);

static ssize_t usable_raw_show(struct kobject *kobj,
				  struct kobj_attribute *attr, char *buf)
{
	unsigned long free = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
	unsigned long file = global_page_state(NR_FILE_PAGES)
						- global_page_state(NR_SHMEM);
	unsigned long slab_reclaimable = global_page_state(NR_SLAB_RECLAIMABLE);
	unsigned long workingset = atomic_long_read(&workingset_pages);
	unsigned long xreclaimable = atomic_long_read(&xreclaimable_pages);
	unsigned long usable;
#ifdef CONFIG_SWAP
	unsigned long swap = atomic_long_read(&nr_swap_pages);
	unsigned long swapcache = total_swapcache_pages();
	unsigned long zramuse = 0;
	if (atomic_read(&zramswap))
		zramuse = (swap / 3);
#else
	unsigned long swap = 0;
	unsigned long swapcache = 0;
	unsigned long zramuse = 0;
#endif

	usable = free + swap - zramuse + file - swapcache + slab_reclaimable + xreclaimable - workingset;
	return sprintf(buf, "%ld %ld %ld %ld %ld %ld %ld %ld %ld\n",
			usable, free, swap, zramuse, file, swapcache, slab_reclaimable, xreclaimable, workingset);
}
LOW_MEM_ATTR_RO(usable_raw);

static struct attribute *low_mem_attrs[] = {
	&low_mem_free_pages_attr.attr,
	&low_mem_usable_pages_attr.attr,
	&low_mem_level_attr.attr,
	&low_mem_thresholds_attr.attr,
	&low_mem_event_ctrl_attr.attr,
	&low_mem_reset_attr.attr,
	&low_mem_workingset_attr.attr,
	&low_mem_xreclaimable_attr.attr,
	&low_mem_xreclaimable_ctrl_attr.attr,
	&low_mem_ratio_attr.attr,
	&low_mem_zramswap_attr.attr,
	&low_mem_force_attr.attr,
	&low_mem_freeze_attr.attr,
	&low_mem_usable_stat_attr.attr,
	&low_mem_usable_raw_attr.attr,
	NULL,
};

static struct attribute_group low_mem_attr_group = {
	.attrs = low_mem_attrs,
	.name = "low_mem_notify",
};

static int sysfs_add_xreclaimable(char *name)
{
	struct xreclaimable *xr;

	xr = low_mem_notify_add_xreclaimable(name);
	if (xr)
		printk("low_mem_notify : %s registered\n", xr->name);
	else
		printk(KERN_ERR "low_mem_notify: register failed(%s)\n", xr->name);

	return (xr) ? 0 : (-1);
}

static void sysfs_remove_xreclaimable(char *name)
{
	struct xreclaimable *xr = find_xreclaimable(name);
	if (xr) {
		printk("low_mem_notify : %s removed\n", xr->name);
		list_del(&xr->list);
		kfree(xr);
	}
}

static void sysfs_reset_xreclaimable(void)
{
	struct xreclaimable *pos, *n;

	list_for_each_entry_safe(pos, n, &xr_list, list) {
		list_del_rcu(&pos->list);
		kfree(pos);
	}

	atomic_long_set(&xreclaimable_pages, 0);

	printk("low_mem_notify : reset done.\n");
}

static void sysfs_set_xreclaimable(const char *name, unsigned long size)
{
	struct xreclaimable *xr = find_xreclaimable(name);
	if (xr)
		set_xreclaimable(xr, size);
}

static int __init low_mem_init(void)
{
	int err = sysfs_create_group(mm_kobj, &low_mem_attr_group);
	if (err)
		printk(KERN_ERR "low_mem: register sysfs failed\n");

	atomic_set(&ratio, DEFAULT_RATIO);
	atomic_set(&zramswap, 0);
	atomic_long_set(&workingset_pages, (DEFAULT_WORKINGSET_SIZE * 1024 * 1024) >> PAGE_SHIFT);
	atomic_set(&freeze, 0);

	memset(&thresholds, 0, sizeof(struct low_mem_thresholds));
	mutex_init(&thresholds_lock);

	atomic_long_set(&xreclaimable_pages, 0);

	return err;
}
module_init(low_mem_init)

#endif
