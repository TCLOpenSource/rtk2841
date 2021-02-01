#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <linux/sched.h>
#include <asm/memory.h>
#include "rtk_kdriver/mcp/rtk_mcp_aux.h"
#include "mcp/rtk_mcp_dbg.h"


int mcp_is_pli_address(unsigned int addr)
{
    return pli_to_kernel(addr) ? 1 : 0;
}


unsigned long pli_to_kernel(unsigned int addr)
{
    struct vm_area_struct* vm_area = find_vma(current->mm, (unsigned long) addr);
    unsigned long pfn;
    unsigned long virt_addr;

    if (vm_area == NULL || follow_pfn(vm_area, (unsigned long) addr, &pfn))
        return 0;

    virt_addr = __phys_to_virt(__pfn_to_phys(pfn)) + (((unsigned long)addr) % PAGE_SIZE);

    mcp_debug("addr=%08lx, pfn=%08lx, kernel addr=%08lx\n", (unsigned long)addr, pfn, virt_addr);
    return virt_addr;
}
