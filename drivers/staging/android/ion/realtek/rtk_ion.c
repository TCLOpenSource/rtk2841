/*
 * drivers/gpu/realtek/realtek_ion.c
 *
 * Copyright (C) 2011 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/module.h>

#include "../ion.h"
#include "../ion_priv.h"

struct ion_device *rtk_ion_device;
int num_heaps;
struct ion_heap **rtk_ion_heaps;

#define RT_ION_CMD_QUERY_PHY  (1)




long realtek_ion_custom_ioctl(struct ion_client *client, unsigned int cmd,
			      unsigned long arg);


extern struct ion_handle *ion_handle_get_by_id(struct ion_client *client,	int id);

long realtek_ion_custom_ioctl(struct ion_client *client, unsigned int cmd,
			      unsigned long arg)
{
	size_t leng ;
	int err = EFAULT;
		
	switch(cmd)
	{
		case RT_ION_CMD_QUERY_PHY:
		{
			struct ion_handle *handle;
			int len;			

			struct RT_ION_QUERY_PHY_data* data;

			data = (struct RT_ION_QUERY_PHY_data *)arg;

				handle = ion_import_dma_buf(client, data->handle_id);
			
				if ( IS_ERR(handle) ) {
					printk(KERN_ERR " rtIon ion_import_dma_buf fail client:%p id:0x%x  err:%d\n", client, data->handle_id, PTR_ERR(handle) );
					return PTR_ERR(handle);
				}

				err = ion_phys(client, handle, &(data->phy_addr), &(data->leng) );

				if( unlikely(err) ) {
					ion_free( client , handle );
					printk(KERN_ERR " rtIon ion_phys fail client:%p id:0x%x  err:%d\n", client, data->handle_id, PTR_ERR(handle) );
					return err;
				}
				
				ion_free( client , handle );
			
			//printk(KERN_ERR " rtIon got 0x%x 0x%x  0x%x\n", handle, data->phy_addr, data->leng );
			

		}

			return 0;
			
		break;		

		default:
			printk(KERN_ERR " invalud rt custom ion ioctl:%d 0x%x\n", cmd, arg);
	}
	
	return err;
}

EXPORT_SYMBOL(realtek_ion_custom_ioctl);

int realtek_ion_probe(struct platform_device *pdev)
{
	struct ion_platform_data *pdata = pdev->dev.platform_data;
	int err;
	int i;

	num_heaps = pdata->nr;

	rtk_ion_heaps = kzalloc(sizeof(struct ion_heap *) * pdata->nr, GFP_KERNEL);

	rtk_ion_device = ion_device_create(realtek_ion_custom_ioctl);
	if (IS_ERR_OR_NULL(rtk_ion_device)) {
		kfree(rtk_ion_heaps);
		return PTR_ERR(rtk_ion_device);
	}

	/* create the rtk_ion_heaps as specified in the board file */
	for (i = 0; i < num_heaps; i++) {
		struct ion_platform_heap *heap_data = &pdata->heaps[i];

		rtk_ion_heaps[i] = ion_heap_create(heap_data);
		if (IS_ERR_OR_NULL(rtk_ion_heaps[i])) {
			err = PTR_ERR(rtk_ion_heaps[i]);
			printk(KERN_ERR " rtk ion heap %s create fail %d\n", heap_data->name, err);
			goto err;
		}
		ion_device_add_heap(rtk_ion_device, rtk_ion_heaps[i]);
	}
	platform_set_drvdata(pdev, rtk_ion_device);
	return 0;
err:
	ion_device_destroy(rtk_ion_device);
	for (i = 0; i < num_heaps; i++) {
		if (!IS_ERR_OR_NULL(rtk_ion_heaps[i]))
			ion_heap_destroy(rtk_ion_heaps[i]);
	}
	kfree(rtk_ion_heaps);
	return err;
}

int realtek_ion_remove(struct platform_device *pdev)
{
	struct ion_device *rtk_ion_device = platform_get_drvdata(pdev);
	int i;

	ion_device_destroy(rtk_ion_device);
	for (i = 0; i < num_heaps; i++)
		if (!IS_ERR_OR_NULL(rtk_ion_heaps[i]))
			ion_heap_destroy(rtk_ion_heaps[i]);
	kfree(rtk_ion_heaps);
	return 0;
}

static struct platform_driver ion_driver = {
	.probe = realtek_ion_probe,
	.remove = realtek_ion_remove,
	.driver = { .name = "ion-realtek" }
};


#define CONST_GAL_MEM_ADDR_START (0x10000000)
#define CONST_GAL_MEM_SIZE (128*1024*1024)

#ifdef CONFIG_CUSTOMER_TV006

int GAL_MEM_ADDR_START = CONST_GAL_MEM_ADDR_START;
int GAL_MEM_SIZE = CONST_GAL_MEM_SIZE;
#else
int GAL_MEM_ADDR_START;
int GAL_MEM_SIZE;
#endif


//284x android 
//#ifdef CONFIG_CUSTOMER_TV006

static struct ion_platform_data rtk_data = {
	.nr = 4,
	.heaps = (struct ion_platform_heap [])
	{
		{
                .type = ION_HEAP_TYPE_SYSTEM_CONTIG,
                .name = "system_contig",
                .id = ION_HEAP_TYPE_SYSTEM_CONTIG,
            },
            {
                .type = ION_HEAP_TYPE_SYSTEM,
                .name = "system",
                .id = ION_HEAP_TYPE_SYSTEM,
            },
            {
                .type = ION_HEAP_TYPE_DMA,
                .name = "ion_cma",
                .id = ION_HEAP_TYPE_DMA,
            },
            {
                .type = ION_HEAP_TYPE_CUSTOM,
                .name = "ion_dvr",
                .id = ION_HEAP_TYPE_CUSTOM,
            }
	}
};
//#endif

static int __init ion_init(void)
{
	platform_device_register_resndata(NULL, "ion-realtek", -1, NULL, 0, &rtk_data, sizeof(rtk_data));
	return platform_driver_register(&ion_driver);
}

static void __exit ion_exit(void)
{
	platform_driver_unregister(&ion_driver);
}

module_init(ion_init);
module_exit(ion_exit);

