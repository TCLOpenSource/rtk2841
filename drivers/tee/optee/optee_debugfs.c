#include <linux/kernel.h>
#include <linux/tee.h>
#include <linux/ioctl.h>
#include <linux/module.h>
#include <linux/tee_drv.h>
#include <linux/slab.h>
#include <linux/debugfs.h>

#define STATS_UUID \
		{ 0xd96a5b40, 0xe2c7, 0xb1af, \
		{ 0x87, 0x94, 0x10, 0x02, 0xa5, 0xd5, 0xc6, 0x1b } }

#define STATS_CMD_PAGER_STATS		0
#define STATS_CMD_ALLOC_STATS		1

#define TEE_NUM_PARAM 4
#define TEE_ALLOCATOR_DESC_LENGTH 32
#define TEE_TA_COUNT_MAX 10
#define TEEC_MEM_INPUT   0x00000001
#define TEEC_MEM_OUTPUT  0x00000002

static struct dentry *optee_debugfs_root = NULL;
static struct dentry *meminfo_dentry = NULL;
static struct dentry *tameminfo_dentry = NULL;

typedef struct {
    uint32_t uuid_tL;
    uint32_t stack_size;
    uint32_t code_size;
} ta_minfo;

struct malloc_stats {
    char desc[TEE_ALLOCATOR_DESC_LENGTH];
	uint32_t allocated;               /* Bytes currently allocated */
	uint32_t max_allocated;           /* Tracks max value of allocated */
    uint32_t size;                    /* Total size for this allocator */
	uint32_t num_alloc_fail;          /* Number of failed alloc requests */
	uint32_t biggest_alloc_fail;      /* Size of biggest failed alloc */
	uint32_t biggest_alloc_fail_used; /* Alloc bytes when above occurred */
    uint32_t cur_alloc_ta_count;
    uint32_t max_alloc_ta_count;
    ta_minfo ta_minfo_cur[TEE_TA_COUNT_MAX];
    ta_minfo ta_minfo_max[TEE_TA_COUNT_MAX];
};

struct teec_uuid {
	uint32_t timeLow;
	uint16_t timeMid;
	uint16_t timeHiAndVersion;
	uint8_t clockSeqAndNode[8];
};

struct optee_ta {
    struct tee_context *ctx;
    __u32 session;
};

static struct optee_ta meminfo_ta;

static int optee_meminfo_match(struct tee_ioctl_version_data *data, const void *vers)
{
	return 1;
}

/* 0: success, -N: failure (N: value) */
static int optee_meminfo_init(void)
{
    int ret = 0, rc = 0;
    struct teec_uuid uuid = STATS_UUID;
    struct tee_ioctl_open_session_arg arg;
    struct tee_ioctl_version_data vers = {
        .impl_id = TEE_IMPL_ID_OPTEE,
        .impl_caps = TEE_OPTEE_CAP_TZ,
        .gen_caps = TEE_GEN_CAP_GP,
    };

    memset(&meminfo_ta, 0, sizeof(meminfo_ta));
    meminfo_ta.ctx = tee_client_open_context(NULL, optee_meminfo_match, NULL, &vers);
    if(meminfo_ta.ctx == NULL) {
		pr_err("optee_meminfo: no ta context\n");
		ret = -EINVAL;
		goto err;
	}

    memset(&arg, 0, sizeof(arg));
    memcpy(&arg.uuid, &uuid, sizeof(struct teec_uuid));
    arg.clnt_login = TEE_IOCTL_LOGIN_PUBLIC;
    pr_debug("arg uuid %pUl \n", arg.uuid);

    rc = tee_client_open_session(meminfo_ta.ctx, &arg, NULL);
    if(rc){
        pr_err("optee_meminfo: open_session failed ret %x arg %x", rc, arg.ret);
		ret = -EINVAL;
        goto err;
    }
    if (arg.ret) {
 		ret = -EINVAL;
 		goto err;
 	}

    meminfo_ta.session = arg.session;

    pr_debug("open_session ok\n");
    return 0;

err:
 	if (meminfo_ta.session) {
 		tee_client_close_session(meminfo_ta.ctx, meminfo_ta.session);
        pr_err("optee_meminfo: open failed close session \n");
 		meminfo_ta.session = 0;
 	}
 	if (meminfo_ta.ctx) {
 		tee_client_close_context(meminfo_ta.ctx);
        pr_err("optee_meminfo: open failed close context\n");
 		meminfo_ta.ctx = NULL;
 	}
    pr_err("open_session fail\n");

    return ret;
}

static void optee_meminfo_deinit(void)
{
 	if (meminfo_ta.session) {
 		tee_client_close_session(meminfo_ta.ctx, meminfo_ta.session);
		meminfo_ta.session = 0;
	}

 	if (meminfo_ta.ctx) {
 		tee_client_close_context(meminfo_ta.ctx);
 		meminfo_ta.ctx = NULL;
 	}
}

/* 0: success, -N: failure (N: value) */
static int optee_meminfo_dump(struct malloc_stats *kernel_stats, struct malloc_stats *user_stats)
{
    int ret = 0, rc = 0;
    struct tee_ioctl_invoke_arg arg;
    struct tee_param *param = NULL;
    struct tee_shm *shm_buffer;
    int shm_len = 0;
	phys_addr_t shm_pa = 0;
	void *shm_va = 0;

    pr_debug("get from optee\n");

    if(meminfo_ta.ctx == NULL) {
		pr_err("optee_meminfo: no ta context\n");
		ret = -EINVAL;
		goto out;
	}

    param = kcalloc(TEE_NUM_PARAM, sizeof(struct tee_param), GFP_KERNEL);

    memset(&arg, 0, sizeof(arg));
    arg.func = STATS_CMD_ALLOC_STATS;
    arg.session = meminfo_ta.session;
    arg.num_params = TEE_NUM_PARAM;

	// alloc share memory
    shm_len = sizeof(struct malloc_stats);
    shm_buffer = tee_shm_alloc(meminfo_ta.ctx, shm_len, TEE_SHM_MAPPED);
    if (shm_buffer == NULL) {
        pr_err("optee_meminfo: no shm_buffer\n");
		ret = -ENOMEM;
		goto out;
	}

	// get share memory virtual addr for data accessing
    shm_va = tee_shm_get_va(shm_buffer, 0);
 	if (shm_va == NULL) {
		ret = -ENOMEM;
 		goto out;
	}

	// get share memory physial addr for tee param
	rc = tee_shm_get_pa(shm_buffer, 0, &shm_pa);
	if (rc) {
		ret = -ENOMEM;
		goto out;
	}

	pr_debug("shm_buffer=%p, shm_len=%d, va=%p, pa=%x\n", (void *)shm_buffer, shm_len, shm_va, shm_pa);

	if(user_stats){
		/**
		*  optee user ta meminfo
		*/
		memset(param, 0, sizeof(struct tee_param) * TEE_NUM_PARAM);
		param[0].attr = TEE_IOCTL_PARAM_ATTR_TYPE_VALUE_INPUT;
		param[0].u.value.a = 3; // user ta pool
		param[0].u.value.b = 0;
		param[1].attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_OUTPUT;
		param[1].u.memref.shm = shm_buffer;
		param[1].u.memref.size = shm_len;
		param[2].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;
		param[3].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;

		rc = tee_client_invoke_func(meminfo_ta.ctx, &arg, param);

		if (rc || arg.ret) {
			pr_err("optee_meminfo: invoke failed ret %x arg.ret %x\n", rc, arg.ret);
			ret = -EINVAL;
			goto out;
		}

        memcpy(user_stats, (struct malloc_stats *)shm_va, sizeof(struct malloc_stats));

	}

	if(kernel_stats){
		/**
		*  optee kernel heap info
		*/
		memset(param, 0, sizeof(struct tee_param) * TEE_NUM_PARAM);
		param[0].attr = TEE_IOCTL_PARAM_ATTR_TYPE_VALUE_INPUT;
		param[0].u.value.a = 1; // kernel pool
		param[0].u.value.b = 0;
		param[1].attr = TEE_IOCTL_PARAM_ATTR_TYPE_MEMREF_OUTPUT;
		param[1].u.memref.shm = shm_buffer;
		param[1].u.memref.size = shm_len;
		param[2].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;
		param[3].attr = TEE_IOCTL_PARAM_ATTR_TYPE_NONE;

		rc = tee_client_invoke_func(meminfo_ta.ctx, &arg, param);
		if (rc || arg.ret) {
			pr_err("optee_meminfo: invoke failed ret %x arg.ret %x\n", rc, arg.ret);
			ret = -EINVAL;
			goto out;
		}

		memcpy(kernel_stats, (struct malloc_stats *)shm_va, sizeof(struct malloc_stats));

	}

out:
	if (param)
		kfree(param);

	if (shm_buffer)
		tee_shm_free(shm_buffer);

	if (ret)
		return ret;
	else
		return 0;
}

static int optee_meminfo_show(struct seq_file *m, void *v)
{
	struct malloc_stats kernel_stats;
	struct malloc_stats user_stats;
	struct malloc_stats *stat_buffer;
	struct tee_shm_pool_stats pool_stats;
	if (optee_meminfo_init()){
		pr_err("optee_meminfo_init fail");
		return 0;
	}
	if (optee_meminfo_dump(&kernel_stats, &user_stats)){
		pr_err("optee_meminfo_dump fail");
		return 0;
	}

	if(tee_shm_pool_get_stats(meminfo_ta.ctx, &pool_stats)){
		pr_err("No tee_shm_pool_stat\n");
		return 0;
	}

	optee_meminfo_deinit();

	/**
	 *  optee kernel heap info
	 */
	stat_buffer = &kernel_stats;

	seq_printf(m,
		"========= OPTEE Kernel Heap ==========\n"
		"allocated:                    %8d\n"
		"max_allocated:                %8d\n"
		"total_size:                   %8d\n"
		"free:                         %8d\n"
		"num_alloc_fail:               %8d\n"
		"biggest_alloc_fail:           %8d\n"
		"biggest_alloc_fail_used:      %8d\n"
		,
		//stat_buffer->desc,
		(int)stat_buffer->allocated,
		stat_buffer->max_allocated,
		stat_buffer->size,
		stat_buffer->size - stat_buffer->allocated,
		stat_buffer->num_alloc_fail,
		stat_buffer->biggest_alloc_fail,
		stat_buffer->biggest_alloc_fail_used
	);


	/**
	 *  optee user ta meminfo
	 */
	stat_buffer = &user_stats;

	seq_printf(m,
		"========= OPTEE TA RAM Secure ========\n"
		"allocated:                    %8d\n"
		"max_allocated:                %8d\n"
		"total_size:                   %8d\n"
		"free:                         %8d\n"
		,
		(int)stat_buffer->allocated,
		stat_buffer->max_allocated,
		stat_buffer->size,
		stat_buffer->size - stat_buffer->allocated
	);
	/**
	*  optee shared memory (OPTEE SHM MEM) info
	*/
	seq_printf(m,
		"========= OPTEE Shared Memory ========\n"
		"-major pool for user      (unit %4dB)\n"
		" major total_size             %8d\n"
		" major allocated              %8d\n"
		" major max_allocated          %8d\n"
		" major free                   %8d\n"
		"-private pool for kernel  (unit %4dB)\n"
		" private total_size           %8d\n"
		" private allocated            %8d\n"
		" private max_allocated        %8d\n"
		" private free                 %8d\n"
		,
		pool_stats.dmabuf_mgr_aligned_unit,
		pool_stats.dmabuf_mgr_total,
		pool_stats.dmabuf_mgr_allocated,
		pool_stats.dmabuf_mgr_max_allocated,
		pool_stats.dmabuf_mgr_total - pool_stats.dmabuf_mgr_allocated,
		pool_stats.private_mgr_aligned_unit,
		pool_stats.private_mgr_total,
		pool_stats.private_mgr_allocated,
		pool_stats.private_mgr_max_allocated,
		pool_stats.private_mgr_total - pool_stats.private_mgr_allocated
	);

	return 0;
}

static int optee_tameminfo_show(struct seq_file *m, void *v)
{
	struct malloc_stats user_stats;
	struct malloc_stats *stat_buffer;
    int idx = 0;
	if (optee_meminfo_init())
		return 0;
    /* only show user ta info */
	if (optee_meminfo_dump(NULL, &user_stats))
		return 0;
	optee_meminfo_deinit();

	/**
	 *  optee user ta meminfo
	 */
	stat_buffer = &user_stats;
    seq_printf(m,
		"========= OPTEE TA RAM Secure ========\n"
		"allocated:                    %8d\n"
		"max_allocated:                %8d\n"
		"total_size:                   %8d\n"
		"free:                         %8d\n"
		"the number of cur ta:         %8d\n"
		"the number of max ta:         %8d\n"
        ,
		(int)stat_buffer->allocated,
		stat_buffer->max_allocated,
        stat_buffer->size,
        stat_buffer->size - stat_buffer->allocated,
        stat_buffer->cur_alloc_ta_count,
        stat_buffer->max_alloc_ta_count
		);
    if(stat_buffer->cur_alloc_ta_count > 0)
        for(idx = 0; idx < stat_buffer->cur_alloc_ta_count ; idx ++)
            seq_printf(m,
                "|-cur_TA idx:                 %8d\n"
                "| cur_TA uuid_time_low:       %08x\n"
                "| cur_TA stack_size:          %8d\n"
                "|-cur_TA code_size:           %8d\n"
                ,
                idx + 1,
                stat_buffer->ta_minfo_cur[idx].uuid_tL,
                stat_buffer->ta_minfo_cur[idx].stack_size,
                stat_buffer->ta_minfo_cur[idx].code_size
                );
    if(stat_buffer->max_alloc_ta_count > 0)
        for(idx = 0; idx < stat_buffer->max_alloc_ta_count ; idx ++)
            seq_printf(m,
                "|-max_TA idx:                 %8d\n"
                "| max_TA uuid_time_low        %08x\n"
                "| max_TA stack_size:          %8d\n"
                "|-max_TA code_size:           %8d\n"
                ,
                idx + 1,
                stat_buffer->ta_minfo_max[idx].uuid_tL,
                stat_buffer->ta_minfo_max[idx].stack_size,
                stat_buffer->ta_minfo_max[idx].code_size
                );

	return 0;
}
static int optee_meminfo_open(struct inode *inode, struct file *file)
{
	return single_open(file, optee_meminfo_show, NULL);
}
static int optee_tameminfo_open(struct inode *inode, struct file *file)
{
	return single_open(file, optee_tameminfo_show, NULL);
}
static const struct file_operations optee_meminfo_fops = {
	.open           = optee_meminfo_open,
	.read           = seq_read,
	.llseek         = seq_lseek,
	.release        = single_release,
};

static const struct file_operations optee_tameminfo_fops = {
	.open           = optee_tameminfo_open,
	.read           = seq_read,
	.llseek         = seq_lseek,
	.release        = single_release,
};
/**
 *  debugfs creation
 */
static void optee_debugfs_file_add(void)
{
	char *name;

	if (!optee_debugfs_root) {
		pr_warn("tee: debugfs: no root dir, not creating file dir\n");
		return;
	}

	// -- template begin
	name = "meminfo";
	meminfo_dentry = debugfs_create_file(name, S_IRUGO, optee_debugfs_root, NULL, &optee_meminfo_fops);
	if (!meminfo_dentry)
		pr_warn("tee: debugfs file entry <%s> creation failed\n", name);
	// -- template end

    // -- template begin
	name = "tameminfo";
	tameminfo_dentry = debugfs_create_file(name, S_IRUGO, optee_debugfs_root, NULL, &optee_tameminfo_fops);
	if (!meminfo_dentry)
		pr_warn("tee:ta debugfs file entry <%s> creation failed\n", name);
	// -- template end
}

static void optee_debugfs_file_del(void)
{
	if (meminfo_dentry) {
		debugfs_remove_recursive(meminfo_dentry);
		meminfo_dentry = NULL;
	}

	if (tameminfo_dentry) {
		debugfs_remove_recursive(tameminfo_dentry);
		tameminfo_dentry = NULL;
	}
}

void optee_debugfs_init(char *name)
{
	if (!debugfs_initialized()) {
		pr_warn("tee: debugfs not available, dir <%s> not created\n", name);
		return;
	}

	optee_debugfs_root = debugfs_create_dir(name, NULL);
	if (!optee_debugfs_root) {
		pr_warn("tee: debugfs dir <%s> creation failed\n", name);
		return;
	}

	optee_debugfs_file_add();
}

void optee_debugfs_exit(void)
{
	optee_debugfs_file_del();
	debugfs_remove_recursive(optee_debugfs_root);
	optee_debugfs_root = NULL;
}
