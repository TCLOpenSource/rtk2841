#include <linux/kernel.h>

#include <linux/dma-mapping.h>
#include <linux/list.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/spinlock.h>

#include "zacc.h"

int zacc_ready(void)
{
	return zacc_decoder_ready() && zacc_encoder_ready();
}
EXPORT_SYMBOL(zacc_ready);

struct zacc_dev *__zacc_device(struct list_head *list, spinlock_t *lock)
{
	struct zacc_dev *zdev;
	unsigned long flags;

	if (list_empty(list))
		return NULL;

	spin_lock_irqsave(lock, flags);

	zdev = list_first_entry(list, struct zacc_dev, list);
	if (!list_is_singular(list))
		list_rotate_left(list);

	spin_unlock_irqrestore(lock, flags);

	return zdev;
}

struct zacc_desc *zacc_get_desc(struct zacc_dev *zdev)
{
	struct zacc_desc *desc = NULL;
	unsigned long flags;

	do {
		spin_lock_irqsave(&zdev->lock, flags);

		if (zdev->used < zdev->size) {
			desc = &zdev->desc[zdev->head];
			zdev->head = (zdev->head + 1) % zdev->size;
			zdev->used++;
		}

		spin_unlock_irqrestore(&zdev->lock, flags);
	} while (!desc);

	return desc;
}

void zacc_put_desc(struct zacc_dev *zdev, struct zacc_desc *desc)
{
	unsigned long flags;
	bool done = false;

	do {
		spin_lock_irqsave(&zdev->lock, flags);

		if (desc - zdev->desc == zdev->tail) {
			zdev->tail = (zdev->tail + 1) % zdev->size;
			zdev->used--;

			done = true;
		}

		spin_unlock_irqrestore(&zdev->lock, flags);
	} while (!done);
}

static int zacc_alloc_desc(struct zacc_dev *zdev)
{
	struct device *dev = &zdev->pdev->dev;
	size_t sz = sizeof(struct zacc_desc) * zdev->size;
	zdev->desc = dma_alloc_coherent(dev, sz, &zdev->desc_pa, GFP_DMA32);
	return zdev->desc ? 0 : -ENOMEM;
}

static void zacc_free_desc(struct zacc_dev *zdev)
{
	struct device *dev = &zdev->pdev->dev;
	size_t sz = sizeof(struct zacc_desc) * zdev->size;
	dma_free_coherent(dev, sz, zdev->desc, zdev->desc_pa);
}

static void zacc_init(struct zacc_dev *zdev)
{
	int i;

	zdev->head = 0;
	zdev->tail = 0;
	zdev->used = 0;

	memset(zdev->desc, 0, sizeof(struct zacc_desc) * zdev->size);
	for (i = 0; i < zdev->size; i++)
		zdev->desc[i].own = 1;
	zdev->desc[zdev->size - 1].wrap = 1;
	wmb();

	/* mask all interrupts */
	writel_relaxed(0xffff, zdev->base + ZACC_IM);
	/* select ADMA */
	writel_relaxed(0x0000, zdev->base + ZACC_DC);
	/* set address for ADMA descriptors */
	writel_relaxed((u32)zdev->desc_pa, zdev->base + ZACC_ADB);
	/* update ADMA descriptor */
	writel_relaxed(0x0001, zdev->base + ZACC_ADC);
	/* set polling interval */
	writel_relaxed(0x0001, zdev->base + ZACC_ADPI);
	/* update polling interval */
	writel_relaxed(0x0001, zdev->base + ZACC_ADPIC);
	/* enable ADMA */
	writel_relaxed(0x0001, zdev->base + ZACC_AC);
	/* enable core */
	writel_relaxed(0x0001, zdev->base + ZACC_CC);
}

static void zacc_stop(struct zacc_dev *zdev)
{
	/* disable ADMA */
	writel_relaxed(0x0000, zdev->base + ZACC_AC);
}

struct zacc_dev *__zacc_probe(struct platform_device *pdev)
{
	struct zacc_dev *zdev;
	struct resource *res;
	struct device_node *np = pdev->dev.of_node;

	zdev = devm_kzalloc(&pdev->dev, sizeof(struct zacc_dev), GFP_KERNEL);
	if (!zdev)
		return NULL;

	platform_set_drvdata(pdev, zdev);
	zdev->pdev = pdev;

	INIT_LIST_HEAD(&zdev->list);
	spin_lock_init(&zdev->lock);

	zdev->size = ZACC_QUEUE_SIZE;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return NULL;

	zdev->base = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(zdev->base))
		return NULL;

	of_property_read_u32_index(np, "alignments", 0, &zdev->ddam);
	of_property_read_u32_index(np, "alignments", 1, &zdev->sdam);

	zdev->ddam = zdev->ddam ? ~zdev->ddam : ~PAGE_MASK;
	zdev->sdam = zdev->sdam ? ~zdev->sdam : ~PAGE_MASK;

	if (zacc_alloc_desc(zdev) < 0)
		return NULL;

	zacc_init(zdev);

	return zdev;
}

void __zacc_remove(struct platform_device *pdev)
{
	struct zacc_dev *zdev = platform_get_drvdata(pdev);
	zacc_stop(zdev);
	zacc_free_desc(zdev);
}

int zacc_suspend(struct device *dev)
{
	struct zacc_dev *zdev = dev_get_drvdata(dev);
	zacc_stop(zdev);
	return 0;
}

int zacc_resume(struct device *dev)
{
	struct zacc_dev *zdev = dev_get_drvdata(dev);
	zacc_init(zdev);
	return 0;
}

SIMPLE_DEV_PM_OPS(zacc_pm_ops, zacc_suspend, zacc_resume);
