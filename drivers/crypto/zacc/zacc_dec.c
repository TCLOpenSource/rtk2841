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

static LIST_HEAD(zacc_dec_list);
static spinlock_t zacc_dec_lock;

int zacc_decoder_ready(void)
{
	return !list_empty(&zacc_dec_list);
}

static struct zacc_dev *zacc_decoder(void)
{
	return __zacc_device(&zacc_dec_list, &zacc_dec_lock);
}

ssize_t zacc_decode(void *dst, void const *src, size_t size)
{
	struct zacc_dev *zdev;
	struct zacc_desc *desc;
	struct device *dev;
	struct page *dst_pg;
	dma_addr_t dst_pa, src_pa;
	int err;

	if (!dst || !src)
		return -EINVAL;

	zdev = zacc_decoder();
	if (!zdev)
		return -ENODEV;
	dev = &zdev->pdev->dev;

	if ((unsigned long)dst & zdev->ddam)
		return -EINVAL;

	desc = zacc_get_desc(zdev);

	dst_pg = kmap_atomic_to_page(dst);
	/*
	 * allow unaligned source data -- use pre-allocated page-aligned
	 * buffer instead for unaligned source data
	 */
	if ((unsigned long)src & zdev->sdam) {
		struct page *spab = zdev->spab[desc - zdev->desc];
		memcpy(page_address(spab), src, size);
		src = page_address(spab);
	}

	dst_pa = dma_map_page(dev, dst_pg, 0, PAGE_SIZE, DMA_FROM_DEVICE);
	src_pa = dma_map_single(dev, (void *)src, size, DMA_TO_DEVICE);

	desc->src_addr = (u32)src_pa >> 4;
	desc->dst_addr = (u32)dst_pa;
	desc->unc_size = PAGE_SIZE;
	desc->bid_size = size;
	desc->ready = 1;
	wmb();
	desc->own = 0;
	wmb();

	writel_relaxed(0x02, zdev->base + ZACC_AS);

	while (!desc->own)
		rmb();

	dma_unmap_page(dev, dst_pa, PAGE_SIZE, DMA_FROM_DEVICE);
	dma_unmap_single(dev, src_pa, size, DMA_TO_DEVICE);

	err = desc->abnt ? -EIO : desc->bid_size;
	rmb();

	zacc_put_desc(zdev, desc);

	return err;
}
EXPORT_SYMBOL(zacc_decode);

static int zacc_probe(struct platform_device *pdev)
{
	struct zacc_dev *zdev;
	unsigned long flags;
	int i;

	zdev = __zacc_probe(pdev);
	if (!zdev)
		return -ENODEV;

	for (i = 0; i < ZACC_QUEUE_SIZE; i++) {
		zdev->spab[i] = alloc_page(GFP_KERNEL);
		if (!zdev->spab[i])
			goto __free_page__;
	}

	spin_lock_irqsave(&zacc_dec_lock, flags);
	list_add_tail(&zdev->list, &zacc_dec_list);
	spin_unlock_irqrestore(&zacc_dec_lock, flags);

	pr_info("zacc_dec: %s initialized\n", pdev->name);

	return 0;

__free_page__:
	for (i = 0; i < ZACC_QUEUE_SIZE; i++) {
		if (zdev->spab[i])
			__free_page(zdev->spab[i]);
	}

	return -ENOMEM;
}

static int zacc_remove(struct platform_device *pdev)
{
	struct zacc_dev *zdev = platform_get_drvdata(pdev);
	unsigned long flags;
	int i;

	spin_lock_irqsave(&zacc_dec_lock, flags);
	list_del(&zdev->list);
	spin_unlock_irqrestore(&zacc_dec_lock, flags);

	for (i = 0; i < ZACC_QUEUE_SIZE; i++)
		__free_page(zdev->spab[i]);

	__zacc_remove(pdev);

	return 0;
}

#ifdef CONFIG_OF

static struct of_device_id const zacc_of_match[] = {
	{ .compatible = "lge,lg1k-zacc-dec", },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, zacc_of_match);

#endif	/* CONFIG_OF */

static struct platform_driver zacc_dec_drv = {
	.probe	= zacc_probe,
	.remove	= zacc_remove,
	.driver	= {
		.name	= "zacc-dec",
		.owner	= THIS_MODULE,
		.pm	= &zacc_pm_ops,
		.of_match_table	= of_match_ptr(zacc_of_match),
	},
};
module_platform_driver(zacc_dec_drv);

MODULE_AUTHOR("Jongsung Kim <neidhard.kim@lge.com>");
MODULE_DESCRIPTION("LG1K ZACC HW decompressor support");
MODULE_LICENSE("GPL");
