#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/dma-mapping.h>
#include <linux/highmem.h>
#include <linux/list.h>
#include <linux/mm.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>
#include <linux/zacc.h>

#include "zacc.h"

static LIST_HEAD(zacc_enc_list);
static spinlock_t zacc_enc_lock;

int zacc_encoder_ready(void)
{
	return !list_empty(&zacc_enc_list);
}

static struct zacc_dev *zacc_encoder(void)
{
	return __zacc_device(&zacc_enc_list, &zacc_enc_lock);
}

ssize_t zacc_encode(void *dst, void const *src)
{
	struct zacc_dev *zdev;
	struct zacc_desc *desc;
	struct device *dev;
	struct page *dst_pg, *src_pg;
	dma_addr_t dst_pa, src_pa;
	int err;

	if (!dst || !src)
		return -EINVAL;

	zdev = zacc_encoder();
	if (!zdev)
		return -ENODEV;
	dev = &zdev->pdev->dev;

	if ((unsigned long)dst & zdev->ddam)
		return -EINVAL;
	if ((unsigned long)src & zdev->sdam)
		return -EINVAL;

	desc = zacc_get_desc(zdev);

	dst_pg = virt_to_page(dst);
	src_pg = kmap_atomic_to_page((void *)src);

	dst_pa = dma_map_page(dev, dst_pg, 0, PAGE_SIZE, DMA_FROM_DEVICE);
	src_pa = dma_map_page(dev, src_pg, 0, PAGE_SIZE, DMA_TO_DEVICE);

	desc->src_addr = (u32)src_pa >> 4;
	desc->dst_addr = (u32)dst_pa;
	desc->unc_size = PAGE_SIZE;
	desc->bid_size = PAGE_SIZE;
	desc->ready = 1;
	wmb();
	desc->own = 0;
	wmb();

	writel_relaxed(0x02, zdev->base + ZACC_AS);

	while (!desc->own)
		rmb();

	dma_unmap_page(dev, dst_pa, PAGE_SIZE, DMA_FROM_DEVICE);
	dma_unmap_page(dev, src_pa, PAGE_SIZE, DMA_TO_DEVICE);

	err = desc->abnt ? -EIO : desc->bid_size;
	rmb();

	zacc_put_desc(zdev, desc);

	return err;
}
EXPORT_SYMBOL(zacc_encode);

static int zacc_probe(struct platform_device *pdev)
{
	struct zacc_dev *zdev;
	unsigned long flags;

	zdev = __zacc_probe(pdev);
	if (!zdev)
		return -ENODEV;

	spin_lock_irqsave(&zacc_enc_lock, flags);
	list_add_tail(&zdev->list, &zacc_enc_list);
	spin_unlock_irqrestore(&zacc_enc_lock, flags);

	pr_info("zacc_enc: %s initialized\n", pdev->name);

	return 0;
}

static int zacc_remove(struct platform_device *pdev)
{
	struct zacc_dev *zdev = platform_get_drvdata(pdev);
	unsigned long flags;

	spin_lock_irqsave(&zacc_enc_lock, flags);
	list_del(&zdev->list);
	spin_unlock_irqrestore(&zacc_enc_lock, flags);

	__zacc_remove(pdev);

	return 0;
}

#ifdef CONFIG_OF

static struct of_device_id const zacc_of_match[] = {
	{ .compatible = "lge,lg1k-zacc-enc", },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, zacc_of_match);

#endif	/* CONFIG_OF */

static struct platform_driver zacc_enc_drv = {
	.probe	= zacc_probe,
	.remove	= zacc_remove,
	.driver	= {
		.name	= "zacc-enc",
		.owner	= THIS_MODULE,
		.pm	= &zacc_pm_ops,
		.of_match_table	= of_match_ptr(zacc_of_match),
	},
};
module_platform_driver(zacc_enc_drv);

MODULE_AUTHOR("Jongsung Kim <neidhard.kim@lge.com>");
MODULE_DESCRIPTION("LG1K ZACC HW compressor support");
MODULE_LICENSE("GPL");
