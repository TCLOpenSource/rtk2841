/******************************************************************************
*
*   Copyright(c) 2016 Realtek Semiconductor Corp. All rights reserved.
*
*   @author realtek.com
*
******************************************************************************/
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>
#include <linux/sched.h>
#include <linux/ioctl.h>
#include <linux/of.h>
#include <mach/io.h>
#include <mach/irqs.h>
#include <rbus/md_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rtk_kdriver/md/rtk_md_debug.h>
#include <rtk_kdriver/md/rtk_md_dev.h>
#include <rtk_kdriver/md/rtk_md_platform.h>
#include <rtk_kdriver/md/rtk_md.h>
#include <rtk_kdriver/md/rtk_md_reg.h>

extern struct md_dev *md_drv_dev;
extern unsigned int md_test_loops;
/*******************************The MD driver test cases for driver porting*******************************************/
#ifdef CONFIG_RTK_KDRV_MD_TEST
static void md_memcpy_test(uint8_t *srcBuf, uint8_t *dstBuf, struct md_dev     *pdev, int length)
{
    uint32_t src_phys_addr = dma_map_single(pdev->md_device, (void *)srcBuf, length, DMA_BIDIRECTIONAL);
    uint32_t dst_phys_addr = dma_map_single(pdev->md_device, (void *)dstBuf, length, DMA_BIDIRECTIONAL);
    PDEBUG("[MD] virtual address: %08x, %08x\n", (uint32_t)srcBuf, (uint32_t)dstBuf);
    PDEBUG("[MD] physical address: %08x, %08x\n", (uint32_t)src_phys_addr, (uint32_t)dst_phys_addr);

    uint64_t handle = smd_memcpy(dst_phys_addr, src_phys_addr, length);

    smd_checkComplete();

    PDEBUG("[MD]u64InstCnt = %lld, u64IssuedInstCnt = %lld\n", pdev->u64InstCnt, pdev->u64IssuedInstCnt);
    dma_unmap_single(pdev->md_device, src_phys_addr, length, DMA_BIDIRECTIONAL);
    dma_unmap_single(pdev->md_device, dst_phys_addr, length, DMA_BIDIRECTIONAL);

    if(memcmp((void*)srcBuf, (void*)dstBuf, length) == 0) {
        PDEBUG("[MD] memcpy ok\n");
    } else {
        PDEERR("[MD] memcpy fail\n");
        PDEIFO("%d,%d,%d,%d", srcBuf[0], srcBuf[1], srcBuf[2], srcBuf[3]);
        PDEIFO("%d,%d,%d,%d\n", dstBuf[0], dstBuf[1], dstBuf[2], dstBuf[3]);
    }
}

void md_unit_test(int length)
{
    uint8_t *srcBuf = kmalloc(length, GFP_KERNEL);
    uint8_t *dstBuf = kmalloc(length, GFP_KERNEL);

    if((srcBuf != NULL) && (dstBuf != NULL)) {
        memset(srcBuf, 0xa0, length);
        memset(dstBuf, 0xb0, length);
        md_memcpy_test(srcBuf, dstBuf, md_drv_dev, length);
    }
    kfree(srcBuf);
    kfree(dstBuf);
}

void md_fill_test(void)
{
    int i = 0;
    int length = 16;
    uint8_t *dstBuf = kmalloc(length, GFP_KERNEL);
    memset(dstBuf, 0x0, length);

    uint32_t dst_phys_addr = dma_map_single(md_drv_dev->md_device, (void *)dstBuf, length, DMA_BIDIRECTIONAL);

    smd_fill(dst_phys_addr, length, 0xaa);

    dma_unmap_single(md_drv_dev->md_device, dst_phys_addr, length, DMA_BIDIRECTIONAL);
    printk("md_fill_test:");
    for(i = 0; i < length; i++)
        printk("%02x ", dstBuf[i]);
    printk("\n");
    kfree(dstBuf);
}

void md_test_all(int length)
{
    int i = 0;
    int count = 0;
    uint32_t dstAry[10];
    uint8_t *dstBuf;
    uint8_t *srcBuf = kmalloc(length, GFP_KERNEL);
    if(srcBuf != NULL) {
        for (i = 0; i < 10; i++) {
            dstBuf = kmalloc(length, GFP_KERNEL);
            dstAry[i] = (uint32_t)dstBuf;
        }

        while(count < md_test_loops) {
            for(i = 0; i < 10; i++) {
                memset((void *)dstAry[i], count, length);
                md_memcpy_test(srcBuf, (uint8_t *)dstAry[i], md_drv_dev, length);
            }
            count++;
            udelay(100);
        }

        kfree(srcBuf);
        for(i = 0; i < 10; i++) {
            kfree((void*)dstAry[i]);
        }
    }
}


int multi_vs_signal(unsigned int length, unsigned int number)
{
    int i = 0;
    uint32_t dstAry[number];
    uint8_t *srcBuf = kmalloc(length, GFP_KERNEL);

    /* nable timer 90k */
    rtd_outl(0xb801b688, 0x1);

    /* malloc dst address and set dst val */
    if(srcBuf != NULL) {
        memset((void *)srcBuf, 0xff, length);
        for (i = 0; i < number; i++) {
            dstAry[i] = (uint32_t) kmalloc(length, GFP_KERNEL);
            memset((void *)dstAry[i], 0x33, length);
            //printk("daddress dstAry[i]=0x%x\n", dstAry[i]);
        }
    } else {
        printk("The srcBuf = NULL, please set a vir address to srcBuf\n");
        return -1;
    }

    /* Enable MD_MULTI_REQ Test */
    if (down_interruptible(&md_drv_dev->sem))
        return -1;

    rtk_md_enable_mult_reg(1);    //enable Multi-req

    up(&md_drv_dev->sem);

    printk(KERN_ALERT "Multi-req Enable (0x%08x)\n", (unsigned int)rtd_inl(MD_MULTI_REQ_reg));
    md_memcpy_multi_desc(srcBuf, dstAry, md_drv_dev, length, number);
    udelay(50);

    /* Disable MD_MULTI_REQ Test */
    if (down_interruptible(&md_drv_dev->sem))
        return -1;
    rtk_md_enable_mult_reg(0);    //disable Multi-req
    up(&md_drv_dev->sem);

    for (i = 0; i < number; i++)
        memset((void *)dstAry[i], 0x33, length);
    //printk("daddress dstAry[90]=0x%x 0x%x, dstAry[91]=0x%x 0x%x\n", ((uint8_t *)dstAry[90])[0], ((uint8_t *)dstAry[90])[1], ((uint8_t *)dstAry[91])[0], ((uint8_t *)dstAry[91])[1]);

    printk(KERN_ALERT "Multi-req Disable (0x%08x)\n", (unsigned int)rtd_inl(MD_MULTI_REQ_reg));
    md_memcpy_multi_desc(srcBuf, dstAry, md_drv_dev, length, number);
    udelay(50);

    kfree(srcBuf);
    for(i = 0; i < number; i++) {
        kfree((void*)dstAry[i]);
    }
    return 0;
}

/*******************************The MD driver test cases for some other function*******************************************/

#define MD_VECTOR                       (0)

static void md_memcpy_seq(
    uint32_t        addrdst,
    uint32_t        addrsrc,
    int32_t         len,
    int32_t         op,
    int32_t         movebyte,
    int32_t         datamode,
    int32_t         dir)
{
    uint32_t len_tmp = MD_SEQ_LEN_LIMIT;
    uint32_t dwcmdword[4] = {0};
    int32_t wret = 0;
    dwcmdword[0] = (datamode | movebyte | (op ? MD_CONST : 0) | (dir ? BIT(7) : 0));
    do {
        len_tmp = (len > MD_SEQ_LEN_LIMIT) ? MD_SEQ_LEN_LIMIT : len;

        dwcmdword[1] = addrdst;
        dwcmdword[2] = addrsrc;
        dwcmdword[3] = (len_tmp & MD_SEQ_LEN_LIMIT_MASK);

        wret = md_do_cmds((uint8_t *)dwcmdword, sizeof(dwcmdword));
        if(wret != MD_SUCCESS) {
            printk("[MD]%s fail(%d).\n", __func__, wret);
            break;
        }
        len -= len_tmp;
        addrdst += len_tmp;
        addrsrc += len_tmp;
    } while(len);

    smd_checkComplete();

}

static void md_memcpy_blk(
    uint32_t        h_blk,
    uint32_t        w_blk,
    uint32_t        x_blk,
    uint32_t        y_blk,
    uint32_t        dcu_index,
    int32_t         seq_addr,
    uint32_t        len,
    int32_t         movebyte,
    int32_t         datamode)
{
    uint32_t len_tmp = MD_SEQ_LEN_LIMIT;
    uint32_t dwcmdword[4] = {0};
    int32_t wret = 0;
    do {
        len_tmp = (len > MD_SEQ_LEN_LIMIT) ? MD_SEQ_LEN_LIMIT : len;
        dwcmdword[0] = (h_blk << 21 | w_blk << 6 | datamode | movebyte);

        dwcmdword[1] = (y_blk << 20 | x_blk << 6);
        dwcmdword[2] = seq_addr;
        if(datamode == MD_BS)
            dwcmdword[3] = (dcu_index << 20);
        else
            dwcmdword[3] = ((len_tmp & MD_SEQ_LEN_LIMIT_MASK) | dcu_index << 20);

        wret = md_do_cmds((uint8_t *)dwcmdword, sizeof(dwcmdword));
        if(wret != MD_SUCCESS) {
            printk("[MD]%s fail(%d).\n", __func__, wret);
            break;
        }
        len -= len_tmp;
        seq_addr += len_tmp;
        /*need addrdst*/
    } while(len);


    smd_checkComplete();

}

static void md_memcpy_pitch(
    uint32_t        addrdst,
    uint32_t        dstpitch,
    uint32_t        addrsrc,
    uint32_t        srcpitch,
    uint32_t        hlen,
    uint32_t        wlen,
    int32_t         movebyte)
{
    uint32_t dwcmdword[4] = {0};
    int32_t wret = 0;
    dwcmdword[0] = (MD_SS_PITCH | movebyte | dstpitch << 6 | srcpitch << 19);

    dwcmdword[1] = addrdst;
    dwcmdword[2] = addrsrc;
    dwcmdword[3] = (hlen << 21 | wlen << 7);;

    wret = md_do_cmds((uint8_t *)dwcmdword, sizeof(dwcmdword));
    if(wret != MD_SUCCESS) {
        printk("[MD]%s fail(%d).\n", __func__, wret);
    }

    smd_checkComplete();

}

/*copy from rtk_vo.c*/

#define DC_SYS_DC_SYS_MISC_reg                                  0xB8007004
#define DC_SYS_DC_SYS_MISC_get_page_size(data)                  ((0x00030000&(data))>>16)
#define IBU_SEQ_REGION_reg                                  0xb805c084
#define IBU_SEQ_BOUND_2_reg                                     0xb805c068
#define DC_SYS_DC_SYS_MISC_dram_4g_used_src(data)               ((0x08000000&(data))>>27)
#define DC2_SYS_DC_SYS_MISC_reg                                 0xB8003004
#define DC2_SYS_DC_SYS_MISC_dram_2g_used_src(data)              ((0x02000000&(data))>>25)
#define IBU_SEQ_REGION_get_region_2_mode(data)                  ((0x00007000&(data))>>12)
#define IBU_SEQ_REGION_get_region_3_mode(data)                  ((0x00000070&(data))>>4)
#define MODE_DC1       0x0
#define MODE_DC2       0x1

#define DC_SYS_DC_PICT_SET_pict_width_scale(data)                                    (0x007E0000&((data)<<17))

#define DC_SYS_DC_PICT_SET_pict_init_page(data)                                      (0x0001FFFF&((data)<<0))

#define DC_SYS_DC_PICT_SET_OFFSET_pict_set_num(data)                                 (0xFF000000&((data)<<24))

#define DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(data)                            (0x000003FF&((data)<<0))

#define DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(data)                            (0x000FFC00&((data)<<10))

#define DC_SYS_DC_PICT_SET_reg                                                       0xB8007000

#define DC_SYS_DC_PICT_SET_OFFSET_reg                                                0xB8007020

#define DC2_SYS_DC_PICT_SET_reg                                                       0xB8003000

#define DC2_SYS_DC_PICT_SET_OFFSET_reg                                                0xB8003020

void md_DCU_Set(uint32_t index, uint32_t st_addr, uint32_t width, uint32_t offset_x, uint32_t offset_y)
{
    uint32_t dc_misc;
    uint32_t dc_pict_set;
    uint32_t dc_pict_set_offset;
    uint32_t page_size;
    uint32_t width_scale;
    uint32_t page_shift;
    uint32_t init_page;
    uint32_t init_page1, init_page2;
    uint32_t page_offset;
    bool DCUSizeDiff;

    width_scale = (width + 255) / 256;

    /* dcu page size config */
    dc_misc = rtd_inl(DC_SYS_DC_SYS_MISC_reg);
    page_size = DC_SYS_DC_SYS_MISC_get_page_size(dc_misc);
    page_shift = 11 + page_size;
    init_page = st_addr >> page_shift;
    init_page1 = init_page;
    init_page2 = init_page;
    page_offset = (rtd_inl(IBU_SEQ_BOUND_2_reg) >> page_shift);
    DCUSizeDiff = (DC_SYS_DC_SYS_MISC_dram_4g_used_src(rtd_inl(DC_SYS_DC_SYS_MISC_reg)) &&
                   DC2_SYS_DC_SYS_MISC_dram_2g_used_src(rtd_inl(DC2_SYS_DC_SYS_MISC_reg))); /* different dcu size*/

    /* ib  enable */
    if (IBU_SEQ_REGION_get_region_2_mode(rtd_inl(IBU_SEQ_REGION_reg)) > MODE_DC2 &&
        IBU_SEQ_REGION_get_region_3_mode(rtd_inl(IBU_SEQ_REGION_reg)) > MODE_DC2 &&
        (init_page >= page_offset)) {
        if ((width_scale & 1))
            printk("width_scale not even: %d\n", width_scale);
        if ((init_page & 1)) {
            printk("init_page not even: %d\n", init_page);
            init_page += 1;
        }
        if ((offset_x & 1)) {
            printk("offset_x not even: %d\n", offset_x);
            offset_x &= ~1;
        }

        init_page1 = init_page;
        init_page2 = init_page;
        if (DCUSizeDiff) {
            init_page1 = (init_page - page_offset);
            init_page2 = (init_page - page_offset);
        }

        width_scale = ((width + 511) / 512) << 1;

        width_scale >>= 1;
        init_page1 >>= 1;
        init_page2 >>= 1;
        offset_x >>= 1;

        if (DCUSizeDiff)
            init_page1 += page_offset;
    }

    dc_pict_set = DC_SYS_DC_PICT_SET_pict_width_scale(width_scale) |
                  DC_SYS_DC_PICT_SET_pict_init_page(init_page1);
    rtd_outl(DC_SYS_DC_PICT_SET_reg, dc_pict_set);

    dc_pict_set_offset = DC_SYS_DC_PICT_SET_OFFSET_pict_set_num(index) |
                         DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(offset_x >> 4) |
                         DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(offset_y >> 2);
    rtd_outl(DC_SYS_DC_PICT_SET_OFFSET_reg, dc_pict_set_offset);

    dc_pict_set = DC_SYS_DC_PICT_SET_pict_width_scale(width_scale) |
                  DC_SYS_DC_PICT_SET_pict_init_page(init_page2);
    rtd_outl(DC2_SYS_DC_PICT_SET_reg, dc_pict_set);

    dc_pict_set_offset = DC_SYS_DC_PICT_SET_OFFSET_pict_set_num(index) |
                         DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_x(offset_x >> 4) |
                         DC_SYS_DC_PICT_SET_OFFSET_pict_set_offset_y(offset_y >> 2);
    rtd_outl(DC2_SYS_DC_PICT_SET_OFFSET_reg, dc_pict_set_offset);
}


static uint32_t rtk_md_check(
    uint32_t addr,
    uint32_t len,
    uint32_t val,
    uint32_t bytemode)
{
    uint32_t size = len;
    uint32_t cnt = 0;

    if(bytemode == MD_2B) {
        size /= 2;

    } else if(bytemode == MD_4B) {
        size /= 4;
    }

    for(cnt = 0; cnt < size; cnt++) {
        if(bytemode == MD_1B) {
            if(*((uint8_t*)addr + cnt) != (uint8_t)(val & 0xff)) {
                printk("[MD]%s error. address = %08x, shift = %d, addr value = 0x%2x, it should be 0x%2x!\n", __func__, addr, cnt, *((uint8_t*)addr + cnt), (uint8_t)(val & 0xff));
                return -1;
            }
        } else if(bytemode == MD_2B) {
            if(*((uint16_t*)addr + cnt) != (uint16_t)(val & 0xffff)) {
                printk("[MD]%s error. address = %08x, shift = %d, addr value = 0x%4x, it should be 0x%4x!\n", __func__, addr, cnt, *((uint16_t*)addr + cnt), (uint16_t)(val & 0xffff));
                return -1;
            }
        } else if(bytemode == MD_4B) {
            if(*((uint32_t*)addr + cnt) != (uint32_t)(val & 0xffffffff)) {
                printk("[MD]%s error. address = %08x, shift = %d, addr value = 0x%8x, it should be 0x%8x!\n", __func__, addr, cnt, *((uint32_t*)addr + cnt), (uint32_t)(val & 0xffffffff));
                return -1;
            }
        } else {
            printk("[MD]%s parameter error!\n", __func__);
            return -1;
        }
    }
    return 0;
}

static uint32_t rtk_md_compare(
    uint32_t addr1,
    uint32_t addr2,
    uint32_t len,
    uint32_t bytemode)
{
    uint32_t size = len;
    uint32_t cnt = 0;

    if(bytemode == MD_2B) {
        size /= 2;

    } else if(bytemode == MD_4B) {
        size /= 4;
    }

    for(cnt = 0; cnt < size; cnt++) {
        if(bytemode == MD_1B) {
            if(*((uint8_t*)addr1 + cnt) != *((uint8_t*)addr2 + cnt)) {
                printk("[MD]%s error. shift = %d, addr1(%08x)=0x%2x, addr2(%08x)=0x%2x 1B mode\n",
                       __func__, cnt, addr1, *((uint8_t*)addr1 + cnt), addr2, *((uint8_t*)addr2 + cnt));
                return -1;
            }
        } else if(bytemode == MD_2B) {
            if(*((uint16_t*)addr1 + cnt) != *((uint16_t*)addr2 + cnt)) {
                printk("[MD]%s error. shift = %d, addr1(%08x)=0x%4x, addr2(%08x)=0x%4x 2B mode\n",
                       __func__, cnt, addr1, *((uint16_t*)addr1 + cnt), addr2, *((uint16_t*)addr2 + cnt));
                //return -1;
            }
        } else if(bytemode == MD_4B) {
            if(*((uint32_t*)addr1 + cnt) != *((uint32_t*)addr2 + cnt)) {
                printk("[MD]%s error. shift = %d, addr1(%08x)=0x%8x, addr2(%08x)=0x%8x 4B mode\n",
                       __func__, cnt, addr1, *((uint32_t*)addr1 + cnt), addr2, *((uint32_t*)addr2 + cnt));
                //return -1;
            }
        } else {
            printk("[MD]%s parameter error!\n", __func__);
            return -1;
        }
    }
    return 0;
}

static void rtk_md_gen_data(
    uint32_t addr,
    uint32_t len,
    uint32_t val,
    uint32_t bytemode)
{

    uint32_t size = len;
    uint32_t cnt = 0;
    if(bytemode == MD_2B) {
        size /= 2;
    } else if(bytemode == MD_4B) {
        size /= 4;
    }

    for(cnt = 0; cnt < size; cnt++) {
        if(bytemode == MD_1B) {
            *((uint8_t*)addr + cnt) = (uint8_t)(val & 0xff);
        } else if(bytemode == MD_2B) {
            *((uint16_t*)addr + cnt) = (uint16_t)(val & 0xffff);
        } else if(bytemode == MD_4B) {
            *((uint32_t*)addr + cnt) = (uint32_t)(val & 0xffffffff);
        } else {
            printk("[MD]%s parameter error!\n", __func__);
        }
    }
    rtk_md_check(addr, len, val, bytemode);
}

static void rtk_md_testcases_pitch(
    uint32_t addrSrc,
    uint32_t addrDst,
    uint32_t VaddrSrc,
    uint32_t VaddrDst,
    uint32_t len)
{
    uint32_t pts_s = 0;
    uint32_t pts_e = 0;
    uint32_t result = -1;


    /*CASE - pitch 1B */
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 1024, 0x77, MD_1B);

    pts_s = rtd_inl(0xb801b690);

    md_memcpy_pitch(addrDst, 256, addrSrc, 256, 3, 16, MD_1B);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, 16, 0x77, MD_1B);
    result += rtk_md_check((uint32_t)VaddrDst + 16, 256 - 16, 0x00, MD_1B);
    result += rtk_md_check((uint32_t)VaddrDst + 256, 16, 0x77, MD_1B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 + 16, 256 - 16, 0x00, MD_1B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 * 2, 16, 0x77, MD_1B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 * 2 + 16, 256 - 16, 0x00, MD_1B);

    if(result == 0) {
        printk("[MD] COPY %d bytes with 1B pitch mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    } else {
        printk("[MD] COPY %d bytes with 1B pitch mode fail! result = %d\n", len, result);
        return;
    }

    /*CASE - pitch 2B */
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 1024, 0x7117, MD_2B);

    pts_s = rtd_inl(0xb801b690);

    md_memcpy_pitch(addrDst, 256, addrSrc, 256, 3, 16, MD_2B);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, 16, 0x1771, MD_2B);
    result += rtk_md_check((uint32_t)VaddrDst + 16, 256 - 16, 0x00, MD_2B);
    result += rtk_md_check((uint32_t)VaddrDst + 256, 16, 0x1771, MD_2B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 + 16, 256 - 16, 0x00, MD_2B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 * 2, 16, 0x1771, MD_2B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 * 2 + 16, 256 - 16, 0x00, MD_2B);

    if(result == 0) {
        printk("[MD] COPY %d bytes with 2B pitch mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    } else {
        printk("[MD] COPY %d bytes with 2B pitch mode fail! result = %d\n", len, result);
        return;
    }

    /*CASE - pitch 4B */
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 1024, 0x12345678, MD_4B);

    pts_s = rtd_inl(0xb801b690);

    md_memcpy_pitch(addrDst, 256, addrSrc, 256, 3, 16, MD_4B);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, 16, 0x78563412, MD_4B);
    result += rtk_md_check((uint32_t)VaddrDst + 16, 256 - 16, 0x00, MD_4B);
    result += rtk_md_check((uint32_t)VaddrDst + 256, 16, 0x78563412, MD_4B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 + 16, 256 - 16, 0x00, MD_4B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 * 2, 16, 0x78563412, MD_4B);
    result += rtk_md_check((uint32_t)VaddrDst + 256 * 2 + 16, 256 - 16, 0x00, MD_4B);

    if(result == 0) {
        printk("[MD] COPY %d bytes with 4B pitch mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    } else {
        printk("[MD] COPY %d bytes with 4B pitch mode fail! result = %d\n", len, result);
        return;
    }

    return;
}


static void rtk_md_testcases_seq2seq(
    uint32_t addrSrc,
    uint32_t addrDst,
    uint32_t VaddrSrc,
    uint32_t VaddrDst,
    uint32_t len)
{
    uint32_t pts_s = 0;
    uint32_t pts_e = 0;
    uint32_t result = -1;


    /*CASE - FILL 1B 0x1c*/
    pts_s = rtd_inl(0xb801b690);
    md_memcpy_seq(addrDst, 0x83, len, MD_CONST, MD_1B, MD_SS, 0);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, len, 0x83, MD_1B);

    if(result == -1) {
        printk("[MD] fill %d bytes with 1B mode fail!\n", len);
        return;
    } else {
        printk("[MD] fill %d bytes with 1B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }


    /*CASE - COPY 1B*/
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, len, 0x45, MD_1B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_seq(addrDst, addrSrc, len, MD_VECTOR, MD_1B, MD_SS, 0);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, len, 0x45, MD_1B);

    if(result == -1) {
        printk("[MD] COPY %d bytes with 1B mode fail!\n", len);
        return;
    } else {
        printk("[MD] COPY %d bytes with 1B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }


    /*CASE - COPY 2B*/
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, len, 0xf123, MD_2B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_seq(addrDst, addrSrc, len, MD_VECTOR, MD_2B, MD_SS, 0);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, len, 0x23f1, MD_2B);

    if(result == -1) {
        printk("[MD] COPY %d bytes with 2B mode fail!\n", len);
        return;
    } else {
        printk("[MD] COPY %d bytes with 2B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }


    /*CASE - COPY 4B*/
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, len, 0xff9abcde, MD_4B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_seq(addrDst, addrSrc, len, MD_VECTOR, MD_4B, MD_SS, 0);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrDst, len, 0xdebc9aff, MD_4B);

    if(result == -1) {
        printk("[MD] COPY %d bytes with 4B mode fail!\n", len);
        return;
    } else {
        printk("[MD] COPY %d bytes with 4B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }
#if 1
    /*CASE - COPY 1B forward*/
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 1024, 0x77, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 1024, 1024, 0x11, MD_1B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_seq(addrSrc, addrSrc + 512, 1024, MD_VECTOR, MD_1B, MD_SS, 0);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrSrc, 512, 0x77, MD_1B);
    result += rtk_md_check((uint32_t)VaddrSrc + 512, 512, 0x11, MD_1B);

    if(result != 0) {
        printk("[MD] COPY %d bytes with 1B forward mode fail!\n", len);
        return;
    } else {
        printk("[MD] COPY %d bytes with 1B forward mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }
#endif

    /*CASE - COPY 1B backward*/
    md_memcpy_seq(addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq(addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 1024, 0x77, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 1024, 1024, 0x11, MD_1B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_seq(addrSrc, addrSrc + 512, 1024, MD_VECTOR, MD_1B, MD_SS, 1);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)VaddrSrc, 1024, 0x11, MD_1B);

    if(result == -1) {
        printk("[MD] COPY %d bytes with 1B backward mode fail!\n", len);
        return;
    } else {
        printk("[MD] COPY %d bytes with 1B backward mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }
    return;
}

static void rtk_md_testcases_seq2blk(
    uint32_t addrSrc,
    uint32_t addrDst,
    uint32_t VaddrSrc,
    uint32_t VaddrDst,
    uint32_t len)
{
    uint32_t pts_s = 0;
    uint32_t pts_e = 0;
    uint32_t result = -1;
#if 0
    /*CASE - copy 1B 0x1c*/
    rtk_md_gen_data((uint32_t)addrSrc, 64, 0x11, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 1, 64, 0x22, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 2, 64, 0x33, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 3, 64, 0x44, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 4, 64, 0x55, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 5, 64, 0x66, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 6, 64, 0x77, MD_1B);
    rtk_md_gen_data((uint32_t)addrSrc + 64 * 7, 64, 0x88, MD_1B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_blk(16, 32, 0, 0, 54, addrSrc, len, MD_1B, MD_SB);
    pts_e = rtd_inl(0xb801b690);
    result = rtk_md_check((uint32_t)0x22808000, 256, 0x11, MD_1B);
    result = rtk_md_check((uint32_t)0x22808000 + 256, 256, 0x22, MD_1B);
    result = rtk_md_check((uint32_t)0x22808000 + 512, 256, 0x33, MD_1B);
    result = rtk_md_check((uint32_t)0x22808000 + 768, 256, 0x44, MD_1B);
    result = rtk_md_check((uint32_t)0x22808000 + 1024, 256, 0x0, MD_1B);

    if(result == -1) {
        printk("[MD] fill %d bytes block with 1B mode fail!\n", len);
        return;
    } else {
        printk("[MD] fill %d bytes block with 1B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }
#endif
    /*CASE - copy 1B 0x1c*/
    md_memcpy_seq((uint32_t)addrSrc, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq((uint32_t)addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc      , 64, 0x11, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 1 , 64, 0x22, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 2 , 64, 0x33, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 3 , 64, 0x44, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 4 , 64, 0x55, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 5 , 64, 0x66, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 6 , 64, 0x77, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 7 , 64, 0x88, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 8 , 64, 0x99, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 9 , 64, 0xaa, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 10, 64, 0xbb, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 11, 64, 0xcc, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 12, 64, 0xdd, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 13, 64, 0xee, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 14, 64, 0xff, MD_1B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 15, 64, 0x56, MD_1B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_blk(8, 128, 0, 0, 54, addrSrc, 1024, MD_1B, MD_SB);
    pts_e = rtd_inl(0xb801b690);
    md_memcpy_blk(8, 128, 0, 0, 54, addrDst, 1024, MD_1B, MD_BS);

    result = rtk_md_compare(VaddrSrc, VaddrDst, 1024, MD_1B);
    if(result == -1) {
        printk("[MD] seq to block to seq  %d bytes block with 1B mode fail!\n", len);
        return;
    } else {
        printk("[MD] seq to block to seq  %d bytes block with 1B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }

#if 0
    /*it will fail at block to seq case , need to */

    /*CASE - copy 2B 0x1c*/
    md_memcpy_seq((uint32_t)addrSrc, 0x00, 1024, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq((uint32_t)addrDst, 0x00, 1024, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 64, 0x1234, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 1, 64, 0x5678, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 2, 64, 0x9abc, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 3, 64, 0xdef0, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 4, 64, 0x1234, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 5, 64, 0x5678, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 6, 64, 0x9abc, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 7, 64, 0xdef0, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 8, 64, 0x1234, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 9, 64, 0x5678, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 10, 64, 0x9abc, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 11, 64, 0xdef0, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 12, 64, 0x1234, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 13, 64, 0x5678, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 14, 64, 0x9abc, MD_2B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 15, 64, 0xdef0, MD_2B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_blk(16, 64, 0, 0, 54, addrSrc, 1024, MD_2B, MD_SB);
    pts_e = rtd_inl(0xb801b690);
    md_memcpy_blk(16, 64, 0, 0, 54, addrDst, 1024, MD_2B, MD_BS);

    result = rtk_md_compare(VaddrSrc, VaddrDst, 1024, MD_2B);
    if(result == -1) {
        printk("[MD] seq to block to seq  %d bytes block with 2B mode fail!\n", len);
        return;
    } else {
        printk("[MD] seq to block to seq  %d bytes block with 2B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }

    /*CASE - copy 4B 0x1c*/
    md_memcpy_seq((uint32_t)addrSrc, 0x00, 1024, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq((uint32_t)addrDst, 0x00, 1024, MD_CONST, MD_1B, MD_SS, 0);
    rtk_md_gen_data((uint32_t)VaddrSrc, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 1, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 2, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 3, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 4, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 5, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 6, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 7, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 8, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 9, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 10, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 11, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 12, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 13, 64, 0x9abcdef0, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 14, 64, 0x12345678, MD_4B);
    rtk_md_gen_data((uint32_t)VaddrSrc + 64 * 15, 64, 0x9abcdef0, MD_4B);

    pts_s = rtd_inl(0xb801b690);
    md_memcpy_blk(8, 128, 0, 0, 54, addrSrc, 1024, MD_4B, MD_SB);
    pts_e = rtd_inl(0xb801b690);
    md_memcpy_blk(8, 128, 0, 0, 54, addrDst, 1024, MD_4B, MD_BS);

    result = rtk_md_compare(VaddrSrc, VaddrDst, 1024, MD_4B);
    if(result == -1) {
        printk("[MD] seq to block to seq  %d bytes block with 4B mode fail!\n", len);
        return;
    } else {
        printk("[MD] seq to block to seq  %d bytes block with 4B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }

    /*need block to seq pitch tesetcase */
#endif

    return;

}

static void rtk_md_testcase_fill(
    uint32_t addrSrc,
    uint32_t addrDst,
    uint32_t VaddrSrc,
    uint32_t VaddrDst,
    int32_t len)
{
    uint32_t pts_s = 0;
    uint32_t pts_e = 0;
    uint32_t result = -1;

    md_memcpy_seq((uint32_t)addrSrc, 0x47, len, MD_CONST, MD_1B, MD_SS, 0);
    md_memcpy_seq((uint32_t)addrDst, 0x00, len, MD_CONST, MD_1B, MD_SS, 0);
    /*CASE - copy 1B 0x1c*/

    pts_s = rtd_inl(0xb801b690);
    md_fill(addrDst, len, (uint32_t)MD_1B, (uint32_t)MD_SS, (uint32_t)"0x48");
    pts_e = rtd_inl(0xb801b690);
    //md_fill(addrdst, len, MD_2B, MD_SS, addrDst);

    result = rtk_md_compare(VaddrSrc, VaddrDst, len, MD_1B);

    if(result == -1) {
        printk("[MD] seq to block to seq  %d bytes block with 1B mode fail!\n", len);
        return;
    } else {
        printk("[MD] seq to block to seq  %d bytes block with 1B mode success. elapsed %d us\n", len, (pts_e - pts_s) * 1000000 / 90090);
    }
}
/*CRC */
uint32_t md_get_crc(
    uint32_t        addrsrc,
    uint32_t        len)
{
    int32_t timeout = 0;

    if(len == 0x40000000)
        len = 0;
    else if (len > 0x40000000)
        return 0;

    rtd_outl(0xb800b14c, MD_1B); //seq2seq
    rtd_outl(0xb800b150, addrsrc);
    rtd_outl(0xb800b154, addrsrc);
    rtd_outl(0xb800b158, len);
    rtd_outl(0xb800b16c, 0x2);

    rtd_outl(0xb800b148, 0x1);
    rtd_outl(0xb800b144, 0x1);
    while(rtd_inl(0xb800b144) & 0x1) {
        udelay(1000);
        timeout++;
        if(timeout > 100) {
            printk("[%s]timeout,size=%d", __func__, timeout);
            rtd_outl(0xb800b144, 0);
            return -1;
        }
    }

    return rtd_inl(0xb800b17c);
}

void rtk_md_unit_test(void)
{
    void *srcdata = NULL;
    void *dstdata = NULL;
    uint32_t SPhysicalAddress = 0;
    uint32_t DPhysicalAddress = 0;
    uint32_t mdcrc = 0;

    srcdata = dma_alloc_coherent(md_drv_dev->md_device, 0x1000, &SPhysicalAddress, GFP_ATOMIC);//(unsigned long)rtd_inl(MD_SMQBASE_reg)+0x2000;
    if(srcdata == 0) {
        printk("[MD]alloc src fail.\n");
        return;
    }

    dstdata = dma_alloc_coherent(md_drv_dev->md_device, 0x1000, &DPhysicalAddress, GFP_ATOMIC);//(unsigned long)rtd_inl(MD_SMQBASE_reg)+0x4000;
    if(dstdata == 0) {
        printk("[MD]alloc dst fail.\n");
        //free_noncache(srcdata);
        return;
    }

    printk("[MD]test src addr = %08x, dst addr = %08x.\n", (uint32_t)srcdata, (uint32_t)dstdata);
    /*enable timer 90k */
    rtd_outl(0xb801b688, 0x1);
    /*CASE - Seq to Seq test*/
    /*Set DCU Index*/
    md_DCU_Set(54, 0x22808000, 1024, 0, 0 );
    rtk_md_testcases_seq2seq(SPhysicalAddress, DPhysicalAddress, (uint32_t)srcdata, (uint32_t)dstdata, 0x1000);

    /*CASE - Seq to blk test, blk to seq test*/
    rtk_md_testcases_seq2blk(SPhysicalAddress, DPhysicalAddress, (uint32_t)srcdata, (uint32_t)dstdata, 1024);

    /*CASE - pitch test*/
    rtk_md_testcases_pitch(SPhysicalAddress, DPhysicalAddress, (uint32_t)srcdata, (uint32_t)dstdata, 0x1000);
#if 0
    /*CASE - fill test*/
    rtk_md_testcase_fill(SPhysicalAddress, DPhysicalAddress, (uint32_t)srcdata, (uint32_t)dstdata, 0x1000);
    /*CASE - blk to blk test*/
    //rtk_md_testcases_blk2blk();
#endif
    //free_noncache(srcdata);
    //free_noncache(dstdata);
    mdcrc = md_get_crc((uint32_t)srcdata, 0x60);

    printk("[MD]src addr = %08x, crc = %08x.\n", (uint32_t)srcdata, (uint32_t)mdcrc);
    return;
}


#endif


