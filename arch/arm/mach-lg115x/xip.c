#include <linux/kernel.h>

#include <linux/init.h>
#include <linux/memblock.h>

#include "xip.h"

unsigned long appxip_start __initdata = 0;
unsigned long appxip_size __initdata = 0;

static unsigned long fontxip_start __initdata = 0;
static unsigned long fontxip_size __initdata = 0;

static int __init appxip_early(char *p)
{
	unsigned long start, size;
	char *endp;

	start = memparse(p, &endp);
	if (*endp == ',') {
		size = memparse(endp + 1, NULL);

		appxip_start = start;
		appxip_size = size;
	}
	return 0;
}
early_param("appxip", appxip_early);

static int __init fontxip_early(char *p)
{
	unsigned long start, size;
	char *endp;

	start = memparse(p, &endp);
	if (*endp == ',') {
		size = memparse(endp + 1, NULL);

		fontxip_start = start;
		fontxip_size = size;
	}
	return 0;
}
early_param("fontxip", fontxip_early);

void __init lg115x_reserve_xip(void)
{
	if (appxip_size &&
		memblock_is_region_reserved(appxip_start, appxip_size)) {
		pr_err("APPXIP: 0x%08lx+0x%08lx overlaps in-use memory region - disabling \n",
			   appxip_start, appxip_size);
		appxip_start = appxip_size = 0;
	}
	else if (!IS_ALIGNED(appxip_start, SECTION_SIZE)) {
		pr_err("APPXIP: 0x%08lx+0x%08lx appxip_start should be 1MB aligned - disabling \n",
			   appxip_start, appxip_size);
		appxip_start = appxip_size = 0;
	}

	if (appxip_size) {
		appxip_size = ALIGN(appxip_size, SECTION_SIZE);		
		memblock_reserve(appxip_start, appxip_size);
		memblock_free(appxip_start, appxip_size);
		memblock_remove(appxip_start, appxip_size);
	}

	if (fontxip_size &&
		memblock_is_region_reserved(fontxip_start, fontxip_size)) {
		pr_err("FONTXIP: 0x%08lx+0x%08lx overlaps in-use memory region - disabling \n",
			   fontxip_start, fontxip_size);
		fontxip_start = fontxip_size = 0;
	}
	else if (!IS_ALIGNED(fontxip_start, SECTION_SIZE)) {
		pr_err("FONTXIP: 0x%08lx+0x%08lx fontxip_start should be 1MB aligned - disabling \n",
			   fontxip_start, fontxip_size);
		fontxip_start = fontxip_size = 0;
	}

	if (fontxip_size) {
		fontxip_size = ALIGN(fontxip_size, SECTION_SIZE);
		memblock_reserve(fontxip_start, fontxip_size);
		memblock_free(fontxip_start, fontxip_size);
		memblock_remove(fontxip_start, fontxip_size);	
	}
}
