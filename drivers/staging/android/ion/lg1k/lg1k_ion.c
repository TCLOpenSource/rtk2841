/*
 * drivers/staging/ion/lg1k/lg1k_ion.c
 *
 * Description : ION Driver
 *
 */

#include <linux/err.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include "../ion.h"
#include "../ion_priv.h"

struct ion_device *idev;
struct ion_mapper *lg1k_user_mapper;
int num_heaps;
struct ion_heap **heaps;

static int lg1k_ion_probe(struct platform_device *pdev)
{
	struct ion_platform_data *pdata = pdev->dev.platform_data;
	int err;
	int i;

	num_heaps = pdata->nr;

	heaps = kzalloc(sizeof(struct ion_heap *) * pdata->nr, GFP_KERNEL);

	idev = ion_device_create(NULL);
	if (IS_ERR_OR_NULL(idev)) {
		kfree(heaps);
		return PTR_ERR(idev);
	}

	/* create the heaps as specified in the board file */
	for (i = 0; i < num_heaps; i++) {
		struct ion_platform_heap *heap_data = &pdata->heaps[i];

		heaps[i] = ion_heap_create(heap_data);
		if (IS_ERR_OR_NULL(heaps[i])) {
			err = PTR_ERR(heaps[i]);
			goto err;
		}
		ion_device_add_heap(idev, heaps[i]);
	}

	platform_set_drvdata(pdev, idev);

	dev_info(&pdev->dev, "registered ion driver\n");
	return 0;
err:
	for (i = 0; i < num_heaps; i++) {
		if (heaps[i])
			ion_heap_destroy(heaps[i]);
	}
	kfree(heaps);
	return err;
}

static int lg1k_ion_remove(struct platform_device *pdev)
{
	struct ion_device *idev = platform_get_drvdata(pdev);
	int i;

	ion_device_destroy(idev);
	for (i = 0; i < num_heaps; i++)
		ion_heap_destroy(heaps[i]);
	kfree(heaps);

	dev_info(&pdev->dev, "removed ion driver\n");
	return 0;
}

struct ion_client *lg1k_ion_client_create(unsigned int heap_mask,
					const char *name)
{
	return ion_client_create(idev, name);
}
EXPORT_SYMBOL(lg1k_ion_client_create);

static struct platform_driver ion_driver = {
	.probe = lg1k_ion_probe,
	.remove = lg1k_ion_remove,
	.driver = { .name = "ion-lg1k" }
};

module_platform_driver(ion_driver);
