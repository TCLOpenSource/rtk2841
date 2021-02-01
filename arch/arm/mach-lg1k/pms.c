#include <linux/kernel.h>

#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/lg1k/pms.h>
#include <linux/mutex.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/sched.h>

#define	PMS_POLL	0x0001		/* polling instead of interrupt */
#define PMS_DEBUG_COUT	0x0002		/* enable debug-print of PMS firmware */
#define PMS_DEBUG_FAKE	0x0004		/* enable fake mode */

#define PMS_CPUFREQ_FLAG	0x0400	/* default flag for cpufreq */
#define PMS_CPUVOLT_FLAG	0	/* default flag for cpuvolt */
#define PMS_HOTPLUG_FLAG	0	/* default flag for hotplug */

#define	PMS_TIMEOUT	100		/* msecs */

#define MAILBOX(m)	((m) << 5)
#define REG(r)		((r) << 2)

#define M2A_IRQ_CTRL	REG(0)		/* PMS to CPU IRQ control & status */
#define M2A_IRQ_MASK	REG(1)		/* PMS to CPU IRQ enable or mask */
#define A2M_IRQ_CTRL	REG(2)		/* CPU to PMS IRQ control & status */
#define A2M_IRQ_MASK	REG(3)		/* CPU to PMS IRQ enable or mask */

#define IPC_CMD_CPU_NOP	0xaa000000	/* request for no operation */
#define	IPC_CMD_CPU_FS	0xaa000001	/* request for scaling frequency */
#define IPC_CMD_CPU_VS	0xaa000002	/* request for scaling voltage */
#define	IPC_CMD_CPU_PM	0xaa000004	/* request for controling power */

#define IPC_CMD_CPU_RES	0xaa000100	/* response */

#define IPC_ERR_NONE	0xaa020000
#define IPC_ERR_AVS	0xaa020001
#define IPC_ERR_PLL	0xaa020002
#define IPC_ERR_PMIC	0xaa020004
#define IPC_ERR_PI	0xaa020008
#define IPC_ERR_PO	0xaa020010
#define IPC_ERR_WFI	0xaa020020
#define IPC_ERR_TS	0xaa020040

static void __iomem *pms_ipc_base;
static void __iomem *pms_irq_base;

static DEFINE_MUTEX(pms_mutex);

static void (*pms_mutex_lock_fn)(void);
static void (*pms_mutex_unlock_fn)(void);
static void (*pms_resume_fn)(void);

static inline void pms_mutex_lock(void)
{
	if (pms_mutex_lock_fn)
		pms_mutex_lock_fn();
}

static inline void pms_mutex_unlock(void)
{
	if (pms_mutex_unlock_fn)
		pms_mutex_unlock_fn();
}

/*
 * Peterson's algorithm (http://en.wikipedia.org/wiki/Peterson%27s_algorithm)
 * to implement the mutual exclusion between the CPU(P0) and the PMS(P1).
 */

static void lg1156_pms_mutex_lock(void)
{
	mutex_lock(&pms_mutex);

	writel_relaxed(0x01, pms_ipc_base + MAILBOX(6) + REG(0));
	writel_relaxed(0x01, pms_ipc_base + MAILBOX(6) + REG(2));
	while (readl_relaxed(pms_ipc_base + MAILBOX(6) + REG(1)) == 0x01 &&
	       readl_relaxed(pms_ipc_base + MAILBOX(6) + REG(2)) == 0x01) {
		/* busy wait */
	}
}

static void lg1156_pms_mutex_unlock(void)
{
	writel_relaxed(0x00, pms_ipc_base + MAILBOX(6) + REG(0));
	mutex_unlock(&pms_mutex);
}

static void lg1210_pms_mutex_lock(void)
{
	mutex_lock(&pms_mutex);
}

static void lg1210_pms_mutex_unlock(void)
{
	mutex_unlock(&pms_mutex);
}

static u32 _pms_key(void)
{
	static u16 key;
	/* should be called with pms_mutex locked */
	return 0xface0000 | key++;
}

static int lg1156_pms_request(u32 key, u32 flag)
{
	unsigned long timeout = PMS_TIMEOUT * NSEC_PER_MSEC;
	unsigned long long start;
	u32 reg;
	int err = 0;

	/* clear possible unhandled pending interrupts */
	writel_relaxed(0x00, pms_irq_base + M2A_IRQ_CTRL);
	/* wake PMS to handle the request */
	writel_relaxed(0x01, pms_irq_base + A2M_IRQ_CTRL);

	start = sched_clock();

	/* busy-wait for PMS completion */
	while (!(readl_relaxed(pms_irq_base + M2A_IRQ_CTRL) & 0x01)) {
		if (sched_clock() - start > timeout) {
			pr_err("%s: request timed-out\n", __func__);
			err = -ETIME;
			goto quit;
		}
	}

	/* check response code */
	reg = readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(0));
	if (reg != IPC_CMD_CPU_RES) {
		pr_err("%s: CMD: %#x (expected: %#x)\n", __func__, reg,
		       IPC_CMD_CPU_RES);
		err = -EINVAL;
		goto quit;
	}
	/* check transaction key */
	reg = readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(7));
	if (reg != key) {
		pr_err("%s: KEY: %#x (expected: %#x)\n", __func__, reg, key);
		err = -EINVAL;
		goto quit;
	}
	/* check error code */
	reg = readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(6));
	if (reg != IPC_ERR_NONE) {
		pr_err("%s: ERR: %#x (expected: %#x)\n", __func__, reg,
		       IPC_ERR_NONE);
		err = -EFAULT;
		goto quit;
	}
quit:
	return err;
}

static int lg1210_pms_request(u32 key, u32 flag)
{
	unsigned long timeout = PMS_TIMEOUT * NSEC_PER_MSEC;
	unsigned long long start;
	u32 v[2];
	int err = 0;

	/* wake PMS to handle the request */
	writel_relaxed(0x01, pms_irq_base);

	start = sched_clock();

	/* busy-wait for PMS completion */
	while (1) {
		v[0] = readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(0));
		v[1] = readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(7));

		if (v[0] == IPC_CMD_CPU_RES && v[1] == key)
			break;

		if (sched_clock() - start > timeout) {
			pr_err("%s: request timed-out\n", __func__);
			err = -ETIME;
			goto quit;
		}
	}
quit:
	return err;
}

/*
 * CPU frequency scaling
 */

static inline int _lg1156_pms_get_cpufreq(int cpu)
{
	return readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(1));
}

static int lg1156_pms_get_cpufreq(int cpu)
{
	int kHz;

	pms_mutex_lock();
	kHz = _lg1156_pms_get_cpufreq(cpu);
	pms_mutex_unlock();

	return kHz;
}

static int lg1156_pms_set_cpufreq(int cpu, int kHz)
{
	u32 flag = PMS_CPUFREQ_FLAG;
	u32 key;
	int err = 0;

	pms_mutex_lock();

	if (_lg1156_pms_get_cpufreq(cpu) == kHz)
		goto quit;

	/* describe the request */
	writel_relaxed(IPC_CMD_CPU_FS, pms_ipc_base + MAILBOX(0) + REG(0));
	writel_relaxed(kHz,            pms_ipc_base + MAILBOX(0) + REG(1));
	writel_relaxed(flag,           pms_ipc_base + MAILBOX(0) + REG(5));
	writel_relaxed(key = _pms_key(), pms_ipc_base + MAILBOX(0) + REG(7));

	/* request and wait for response */
	err = lg1156_pms_request(key, flag);
quit:
	return err;
}

static int lg1210_pms_set_cpufreq(int cpu, int kHz)
{
	u32 flag = PMS_CPUFREQ_FLAG;
	u32 key;
	int err = 0;

	pms_mutex_lock();

	if (_lg1156_pms_get_cpufreq(cpu) == kHz)
		goto quit;

	/* describe the request */
	writel_relaxed(IPC_CMD_CPU_FS, pms_ipc_base + MAILBOX(0) + REG(0));
	writel_relaxed(kHz,            pms_ipc_base + MAILBOX(0) + REG(1));
	writel_relaxed(flag,           pms_ipc_base + MAILBOX(0) + REG(5));
	writel_relaxed(key = _pms_key(), pms_ipc_base + MAILBOX(0) + REG(7));

	/* request and wait for response */
	err = lg1210_pms_request(key, flag);
quit:
	pms_mutex_unlock();
	return err;
}

/*
 * CPU voltage scaling
 */

static inline int _lg1156_pms_get_cpuvolt(int cpu)
{
	return readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(2));
}

static int lg1156_pms_get_cpuvolt(int cpu)
{
	int uV;

	pms_mutex_lock();
	uV = _lg1156_pms_get_cpuvolt(cpu);
	pms_mutex_unlock();

	return uV;
}

static int lg1156_pms_set_cpuvolt(int cpu, int uV)
{
	u32 flag = PMS_CPUVOLT_FLAG;
	u32 key;
	int err = 0;

	pms_mutex_lock();

	if (_lg1156_pms_get_cpuvolt(cpu) == uV)
		goto quit;

	/* describe the request */
	writel_relaxed(IPC_CMD_CPU_VS, pms_ipc_base + MAILBOX(0) + REG(0));
	writel_relaxed(uV,             pms_ipc_base + MAILBOX(0) + REG(2));
	writel_relaxed(flag,           pms_ipc_base + MAILBOX(0) + REG(5));
	writel_relaxed(key = _pms_key(), pms_ipc_base + MAILBOX(0) + REG(7));

	/* request and wait for response */
	err = lg1156_pms_request(key, flag);
quit:
	return err;
}

static int lg1210_pms_set_cpuvolt(int cpu, int uV)
{
	u32 flag = PMS_CPUVOLT_FLAG;
	u32 key;
	int err = 0;
	pms_mutex_lock();

	if (_lg1156_pms_get_cpuvolt(cpu) == uV)
		goto quit;

	/* describe the request */
	writel_relaxed(IPC_CMD_CPU_VS, pms_ipc_base + MAILBOX(0) + REG(0));
	writel_relaxed(uV,             pms_ipc_base + MAILBOX(0) + REG(2));
	writel_relaxed(flag,           pms_ipc_base + MAILBOX(0) + REG(5));
	writel_relaxed(key = _pms_key(), pms_ipc_base + MAILBOX(0) + REG(7));

	/* request and wait for response */
	err = lg1210_pms_request(key, flag);
quit:
	pms_mutex_unlock();
	return err;
}

/*
 * secondary CPU power gating
 */

#define BITMAP_CLRBIT(bitmap,bit)	((bitmap) & ~(1 << (bit)))
#define BITMAP_GETBIT(bitmap,bit)	(((bitmap) >> (bit)) & 1)
#define BITMAP_SETBIT(bitmap,bit)	((bitmap) | (1 << (bit)))

static inline u32 lg1156_pms_get_hotplug_bitmap(void)
{
	return readl_relaxed(pms_ipc_base + MAILBOX(1) + REG(3));
}

static inline int _lg1156_pms_get_hotplug(int cpu)
{
	return BITMAP_GETBIT(lg1156_pms_get_hotplug_bitmap(), cpu);
}

static int lg1156_pms_get_hotplug(int cpu)
{
	int on;

	pms_mutex_lock();
	on = _lg1156_pms_get_hotplug(cpu);
	pms_mutex_unlock();

	return on;
}

static int lg1156_pms_set_hotplug(int cpu, int on)
{
	u32 flag = PMS_HOTPLUG_FLAG;
	u32 bitmap;
	u32 key;
	int err = 0;

	if (cpu == 0)
		return on ? 0 : -EINVAL;

	pms_mutex_lock();

	if (_lg1156_pms_get_hotplug(cpu) == on)
		goto quit;

	bitmap = on ? BITMAP_SETBIT(lg1156_pms_get_hotplug_bitmap(), cpu) :
	              BITMAP_CLRBIT(lg1156_pms_get_hotplug_bitmap(), cpu);

	/* force PMS to check STANDBYWFI signal before powering off CPU */
	if (!on)
		flag |= 0x0040;

	/* describe the request */
	writel_relaxed(IPC_CMD_CPU_PM, pms_ipc_base + MAILBOX(0) + REG(0));
	writel_relaxed(bitmap,         pms_ipc_base + MAILBOX(0) + REG(3));
	writel_relaxed(flag,           pms_ipc_base + MAILBOX(0) + REG(5));
	writel_relaxed(key = _pms_key(), pms_ipc_base + MAILBOX(0) + REG(7));

	/* request and wait for response */
	err = lg1156_pms_request(key, flag);
quit:
	return err;
}

static int lg1210_pms_set_hotplug(int cpu, int on)
{
	u32 flag = PMS_HOTPLUG_FLAG;
	u32 bitmap;
	u32 key;
	int err = 0;

	if (cpu == 0)
		return on ? 0 : -EINVAL;

	pms_mutex_lock();

	if (_lg1156_pms_get_hotplug(cpu) == on)
		goto quit;

	bitmap = on ? BITMAP_SETBIT(lg1156_pms_get_hotplug_bitmap(), cpu) :
	              BITMAP_CLRBIT(lg1156_pms_get_hotplug_bitmap(), cpu);

	/* H15 PMS requires changed mask in upper 16-bit */
	bitmap &= 0xffff;
	bitmap |= (0x01 << cpu) << 16;

	/* force PMS to print debug information */
	flag |= 0x0002;

	/* force PMS to check STANDBYWFI signal before powering off CPU */
	if (!on)
		flag |= 0x0040;

	/* describe the request */
	writel_relaxed(IPC_CMD_CPU_PM, pms_ipc_base + MAILBOX(0) + REG(0));
	writel_relaxed(bitmap,         pms_ipc_base + MAILBOX(0) + REG(3));
	writel_relaxed(flag,           pms_ipc_base + MAILBOX(0) + REG(5));
	writel_relaxed(key = _pms_key(), pms_ipc_base + MAILBOX(0) + REG(7));

	/* request and wait for response */
	err = lg1210_pms_request(key, flag);
quit:
	pms_mutex_unlock();
	return err;
}

static struct lg1k_pms_ops const lg1156_pms_ops = {
	.get_cpufreq	= lg1156_pms_get_cpufreq,
	.set_cpufreq	= lg1156_pms_set_cpufreq,
	.get_cpuvolt	= lg1156_pms_get_cpuvolt,
	.set_cpuvolt	= lg1156_pms_set_cpuvolt,
	.get_hotplug	= lg1156_pms_get_hotplug,
	.set_hotplug	= lg1156_pms_set_hotplug,
};

static struct lg1k_pms_ops const lg1210_pms_ops = {
	.get_cpufreq	= lg1156_pms_get_cpufreq,
	.set_cpufreq	= lg1210_pms_set_cpufreq,
	.get_cpuvolt	= lg1156_pms_get_cpuvolt,
	.set_cpuvolt	= lg1210_pms_set_cpuvolt,
	.get_hotplug	= lg1156_pms_get_hotplug,
	.set_hotplug	= lg1210_pms_set_hotplug,
};

static void lg1156_pms_init_hw(void)
{
	int reg;

	/* clear IPC region for messages and mutex */
	for (reg = 0; reg < 8; reg++) {
		writel_relaxed(0x00, pms_ipc_base + MAILBOX(0) + REG(reg));
		writel_relaxed(0x00, pms_ipc_base + MAILBOX(2) + REG(reg));
		writel_relaxed(0x00, pms_ipc_base + MAILBOX(6) + REG(reg));
	}

	/* clear all interrupts */
	writel_relaxed(0x00, pms_irq_base + M2A_IRQ_CTRL);
	/* disable all interrupts */
	writel_relaxed(0x00, pms_irq_base + M2A_IRQ_MASK);
}

static void __init lg1156_pms_init(struct device_node *dn)
{
	pms_ipc_base = of_iomap(dn, 0);
	if (!pms_ipc_base) {
		pr_err("could not find address for PMS-IPC\n");
		return;
	}

	pms_irq_base = of_iomap(dn, 1);
	if (!pms_irq_base) {
		pr_err("could not find address for PMS-IRQ\n");
		return;
	}

	lg1156_pms_init_hw();

	lg1k_pms_set_ops(&lg1156_pms_ops);
	pms_mutex_lock_fn = lg1156_pms_mutex_lock;
	pms_mutex_unlock_fn = lg1156_pms_mutex_unlock;
	pms_resume_fn = lg1156_pms_init_hw;
}

static void lg1210_pms_init_hw(void)
{
	writel_relaxed(0x0f, pms_ipc_base + MAILBOX(1) + REG(3));
}

static void __init lg1210_pms_init(struct device_node *dn)
{
	pms_ipc_base = of_iomap(dn, 0);
	if (!pms_ipc_base) {
		pr_err("could not find address for PMS-IPC\n");
		return;
	}

	pms_irq_base = of_iomap(dn, 1);
	if (!pms_irq_base) {
		pr_err("could not find address for PMS-IRQ\n");
		return;
	}

	lg1210_pms_init_hw();

	lg1k_pms_set_ops(&lg1210_pms_ops);
	pms_mutex_lock_fn = lg1210_pms_mutex_lock;
	pms_mutex_unlock_fn = lg1210_pms_mutex_unlock;
	pms_resume_fn = lg1210_pms_init_hw;
}

static struct of_device_id const pms_init_data[] __initdata = {
	{ .compatible = "lge,lg1156-pms", .data = lg1156_pms_init, },
	{ .compatible = "lge,lg1210-pms", .data = lg1210_pms_init, },
	{ /* sentinel */ },
};

void __init lg115x_init_pms(void)
{
	struct device_node *dn;
	struct of_device_id const *match;
	void (*pms_init_fn)(struct device_node *);

	for_each_matching_node_and_match(dn, pms_init_data, &match) {
		pms_init_fn = match->data;
		pms_init_fn(dn);
		break;
	}
}

void lg115x_pms_resume(void)
{
	extern int in_suspend;
	if (pms_resume_fn && !in_suspend)
		pms_resume_fn();
}
