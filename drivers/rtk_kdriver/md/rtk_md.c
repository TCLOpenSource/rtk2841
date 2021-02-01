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
#include <linux/device.h>
#include <mach/io.h>
#include <mach/irqs.h>
#include <rbus/md_reg.h>
#include <rbus/pll27x_reg_reg.h>
#include <rbus/pll_reg_reg.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/md/rtk_md_debug.h>
#include <rtk_kdriver/md/rtk_md.h>
#include <rtk_kdriver/md/rtk_md_test.h>

#ifdef MD_MD_SMQ_CNTL
#include <rtk_kdriver/md/rtk_md_reg.h>
#endif

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)           gic_irq_find_mapping(hwirq)
#define DSB                                     dsb(sy)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)           (hwirq)
#define DSB                                     dsb()
#endif
#define SMQ_STATUS                      BIT(0)
#define KMQ_STATUS                      BIT(1)
#define SMQ_SELF_CHECK          BIT(2)
#define STOP                            0
#define START                   1
#define RESET                   1
#define FINISH                  0

/*

DUMMY1
           +----------+----------+----------+----------+
bit 4 ~ 0  |  No Use  |  No Use  |  No Use  |SMQ Status|
           +----------+----------+----------+----------+

DUMMY2
           +----------+----------+----------+----------+
bit 4 ~ 0  |  No Use  |SELF_CHECK|KMQ Status|  No Use  |
           +----------+----------+----------+----------+
*/

#define GET_DUMMY1_REG(bit)      (rtd_inl(MD_DUMMY1_reg) & bit)
#define SET_DUMMY1_REG(bit, val) val==0?rtd_clearbits(MD_DUMMY1_reg, bit):rtd_setbits(MD_DUMMY1_reg, bit)
#define GET_DUMMY2_REG(bit)      (rtd_inl(MD_DUMMY2_reg) & bit)
#if defined(CONFIG_REALTEK_SECURE) && !defined(CONFIG_RTK_KDRV_OPENBSD)
#define GET_KMQ_STATUS()                (GET_DUMMY2_REG(KMQ_STATUS) >> 1)
#else
#define GET_KMQ_STATUS()                STOP
#endif
#define GET_SMQ_SELF_CHECK()    (GET_DUMMY2_REG(SMQ_SELF_CHECK) >> 2)
#define SET_DUMMY2_REG(bit, val) val==0?rtd_clearbits(MD_DUMMY2_reg, bit):rtd_setbits(MD_DUMMY2_reg, bit)

struct md_dev *md_drv_dev;
extern bool md_dbg_onoff;

#define MD_RECOVERY_VCPU
//#define MD_RECOVERY_KCPU
#undef MD_RECOVERY_KCPU

#if defined(MD_RECOVERY_VCPU)
static unsigned int md_v_ctl = 0;
static unsigned int md_v_ine = 0;
static unsigned int md_v_base = 0;
static unsigned int md_v_limit = 0;
static unsigned int md_v_rp = 0;
static unsigned int md_v_wp = 0;
static unsigned int md_v_icnt = 0;


static void md_init_v_reg(void)
{

    if(md_v_base)
        rtd_outl(MD_VMQBASE_reg, md_v_base);
    if(md_v_limit)
        rtd_outl(MD_VMQLIMIT_reg, md_v_limit);
    if(md_v_rp)
        rtd_outl(MD_VMQRDPTR_reg, md_v_rp);
    if(md_v_wp)
        rtd_outl(MD_VMQWRPTR_reg, md_v_wp);

    if(md_v_icnt)
        rtd_outl(MD_VMQ_INSTCNT_reg, md_v_icnt);


    if(md_v_ine) {
        rtd_outl(MD_VMQ_INT_STATUS_reg, 0x1);
        rtd_outl(MD_VMQ_INT_ENABLE_reg, md_v_ine | 0x1);
    }

    if(md_v_base && md_v_limit && md_v_rp && md_v_wp)
        rtd_outl(MD_VMQ_CNTL_reg, md_v_ctl | 0x3);


}

static void md_store_v_reg(void)
{
    if(rtd_inl(SYS_REG_SYS_CLKEN1_reg)&SYS_REG_SYS_CLKEN1_clken_md_mask) {
        md_v_ctl = rtd_inl(MD_VMQ_CNTL_reg);
        md_v_ine = rtd_inl(MD_VMQ_INT_ENABLE_reg);
        md_v_base = rtd_inl(MD_VMQBASE_reg);
        md_v_limit = rtd_inl(MD_VMQLIMIT_reg);
        md_v_rp = rtd_inl(MD_VMQRDPTR_reg);
        md_v_wp = rtd_inl(MD_VMQWRPTR_reg);
        md_v_icnt = rtd_inl(MD_VMQ_INSTCNT_reg);
    }
}

#endif

#if defined(MD_RECOVERY_KCPU)
static unsigned int md_k_ctl = 0;
static unsigned int md_k_ins = 0;
static unsigned int md_k_ine = 0;
static unsigned int md_k_base = 0;
static unsigned int md_k_limit = 0;
static unsigned int md_k_rp = 0;
static unsigned int md_k_wp = 0;

static void md_init_k_reg(void)
{
    if(md_k_base)
        rtd_outl(MD_KMQBASE_reg, md_k_base);
    if(md_k_limit)
        rtd_outl(MD_KMQLIMIT_reg, md_k_limit);
    if(md_k_rp)
        rtd_outl(MD_KMQRDPTR_reg, md_k_rp);
    if(md_k_wp)
        rtd_outl(MD_KMQWRPTR_reg, md_k_wp);
    if(md_k_ine) {
        rtd_outl(MD_KMQ_INT_STATUS_reg, 0x1);
        rtd_outl(MD_KMQ_INT_ENABLE_reg, md_k_ine | 0x1);
    }

    if(md_k_base && md_k_limit && md_k_rp && md_k_wp)
        rtd_outl(MD_KMQ_CNTL_reg, md_k_ctl | 0x3);
}

static void md_store_k_reg(void)
{
    if(rtd_inl(SYS_REG_SYS_CLKEN1_reg)&SYS_REG_SYS_CLKEN1_clken_md_mask) {
        md_k_ctl = rtd_inl(MD_KMQ_CNTL_reg);
        md_k_ine = rtd_inl(MD_KMQ_INT_ENABLE_reg);
        md_k_base = rtd_inl(MD_KMQBASE_reg);
        md_k_limit = rtd_inl(MD_KMQLIMIT_reg);
        md_k_rp = rtd_inl(MD_KMQRDPTR_reg);
        md_k_wp = rtd_inl(MD_KMQWRPTR_reg);
    }
}

#endif

typedef struct {
    uint32_t data[4];
} MD_CMD;


void md_dump_cmd_ring(struct md_dev *pdev, unsigned int count)
{
    MD_CMD* p_md_cmd = (MD_CMD*) pdev->CmdBuf;
    int cmd_ring_size = MD_CMD_BUF / sizeof(MD_CMD);
    int cmd_count = pdev->cmd_cnt / sizeof(MD_CMD);
    int i;

    if (count >= cmd_ring_size)
        count = cmd_ring_size;

    i = (cmd_count > count) ? cmd_count - count : 0;

    while (i < cmd_count) {
        int idx = i % cmd_ring_size;

        PDEWAR("[MD][WARN] CMD=%d, DESC[%d](%p/%08lx)={op:%08x, daddr:%08x, saddr:%08x, len=%08x}\n",
               i,
               idx,
               &p_md_cmd[idx],                               // Virtual Address
               ((unsigned long)pdev->CmdBase) + (idx * sizeof(MD_CMD)),         // Physical Address
               p_md_cmd[idx].data[0],
               p_md_cmd[idx].data[1],
               p_md_cmd[idx].data[2],
               p_md_cmd[idx].data[3]);
        i++;
    }
}

void md_dump_cmd_ring_status(void)
{
    md_dump_cmd_ring(md_drv_dev, 30);   // dump latest 30 descriptors
}

static void rtk_md_dump_reg(void)
{

    uint32_t* rp = NULL;
    PDEERR( " ======================================== \n");
    PDEERR( "MdCtrl         = %08x\n", (unsigned int)rtd_inl(MD_SMQ_CNTL_reg));
    PDEERR( "MdInts         = %08x\n", (unsigned int)rtd_inl(MD_SMQ_INT_STATUS_reg));
    PDEERR( "MdInte         = %08x\n", (unsigned int)rtd_inl(MD_SMQ_INT_ENABLE_reg));
    PDEERR( "MdCmdBase      = %08x\n", (unsigned int)rtd_inl(MD_SMQBASE_reg));
    PDEERR( "MdCmdLimit     = %08x\n", (unsigned int)rtd_inl(MD_SMQLIMIT_reg));
    PDEERR( "MdCmdReadPtr   = %08x\n", (unsigned int)rtd_inl(MD_SMQRDPTR_reg));
    PDEERR( "MdCmdWritePtr  = %08x\n", (unsigned int)rtd_inl(MD_SMQWRPTR_reg));
    PDEERR( "MdInsRemainder = %08x\n", (unsigned int)rtd_inl(MD_SMQFIFOSTATE_reg));
    PDEERR( "MdInstCnt      = %08x\n", (unsigned int)rtd_inl(MD_SMQ_INSTCNT_reg));
    if(rtd_inl(MD_SMQRDPTR_reg)) {
        /*This is a case for GDMA resume flow.K2L/p only. each cmd from GDMA is 4 words*/
        rp =  (uint32_t*)(rtd_inl(MD_SMQRDPTR_reg) | 0xC0000000);
        PDEERR( "CMD            = (%08x, %08x, %08x, %08x)\n", *(rp - 8), *(rp - 7), *(rp - 6), *(rp - 5));
        PDEERR( "CMD            = (%08x, %08x, %08x, %08x)\n", *(rp - 4), *(rp - 3), *(rp - 2), *(rp - 1));
        PDEERR( "CMD            = (%08x, %08x, %08x, %08x)\n", *(rp), *(rp + 1), *(rp + 2), *(rp + 3));
    }
    PDEERR( " ======================================== \n");
}


void md_dump_last_cmd(void)
{
    if(md_dbg_onoff) {
        md_dump_cmd_ring(md_drv_dev, 1); // dump the latest  descriptor
    }
}
void md_dump_last_hw_status(void)
{
    if(md_dbg_onoff) {
        rtk_md_dump_reg();
    }
}
static void md_init_reg(struct md_dev *pdev)
{
    if (down_interruptible(&md_drv_dev->sem))
        return;
    /* Clock & reset */
    if(!(rtd_inl(SYS_REG_SYS_CLKEN1_reg)&SYS_REG_SYS_CLKEN1_clken_md_mask)) {
        CRT_CLK_OnOff(MD, CLK_ON, NULL);
        udelay(10);
    }
    rtd_outl(MD_SMQ_CNTL_reg, MdEndianSwap | MdWriteData);
    rtd_outl(MD_SMQBASE_reg, (uint32_t) pdev->CmdBase);
    rtd_outl(MD_SMQLIMIT_reg, (uint32_t) pdev->CmdLimit);
    rtd_outl(MD_SMQRDPTR_reg, (uint32_t) pdev->CmdBase);
    rtd_outl(MD_SMQWRPTR_reg, (uint32_t) pdev->CmdBase);
    rtd_outl(MD_SMQ_INSTCNT_reg, 0);

    SET_DUMMY1_REG(SMQ_STATUS, START);

    pdev->CmdWptr = 0;
    pdev->wrptr = 0;
    pdev->u64InstCnt = 0;
    pdev->u64IssuedInstCnt = 0;

#if defined(MD_RECOVERY_VCPU)
    md_init_v_reg();
#endif

#if defined(MD_RECOVERY_KCPU)
    md_init_k_reg();
#endif

    rtd_outl(MD_MULTI_REQ_reg, 0x00000020);  //Multi-req default value = 0x00000020

    up(&md_drv_dev->sem);

}

static void md_reset(void)
{
    rtk_md_dump_reg();
#if defined(MD_RECOVERY_VCPU)
    md_store_v_reg();
#endif

#if defined(MD_RECOVERY_KCPU)
    md_store_k_reg();
#endif
    md_init_reg(md_drv_dev);
}


/* This function services keyboard interrupts. It reads the relevant
 *  * information from the keyboard and then scheduales the bottom half
 *   * to run when the kernel considers it safe.
 *    */
irqreturn_t md_irq_handler(
    int             irq,
    void            *dev_id)
{
    struct md_dev *pdev = (struct md_dev *)dev_id;

    /*PDEBUG("md interrupt handler\n"); */
    if((rtd_inl(MD_SMQ_INT_ENABLE_reg) & MdIntCommandEmpty) && (rtd_inl(MD_SMQ_INT_STATUS_reg) & MdIntCommandEmpty)) {
        /*Disable empty interrupt */
        rtd_outl(MD_SMQ_INT_ENABLE_reg, MdIntCommandEmpty | MdIntSCPUInt);
        /*Clear interrupt status */
        rtd_outl(MD_SMQ_INT_STATUS_reg, MdIntCommandEmpty);
        /*PDEBUG("md com empty interrupt(%08x %08x)\n", rtd_inl(MD_SMQ_INT_ENABLE_reg), rtd_inl(MD_SMQ_INT_STATUS_reg)); */
        pdev->CmdDone = 1;
        /*up(&sem_waitforcmopletion); */
        return IRQ_HANDLED;
    }
    return IRQ_NONE;
}

static void md_update_inst_count(struct md_dev *pdev)
{
    uint16_t u16CmdExecuted;
    uint16_t u16InsCntLow;

    u16CmdExecuted = rtd_inl(MD_SMQ_INSTCNT_reg) & MD_SMQ_INSTCNT_smq_inst_cnt_mask;
    u16InsCntLow = pdev->u64InstCnt & 0xFFFFLL;
    if(u16InsCntLow > u16CmdExecuted) {
        pdev->u64InstCnt = (pdev->u64InstCnt & ~0xFFFFLL) + 0x10000LL + u16CmdExecuted;
    } else {
        pdev->u64InstCnt = (pdev->u64InstCnt & ~0xFFFFLL) + u16CmdExecuted;
    }
}


static int WriteCmd(struct md_dev *pdev, uint8_t *pbyCommandBuffer,
                    uint32_t lCommandLength, int32_t go)
{
    uint32_t        dwDataCounter = 0;
    uint8_t         *pbyWritePointer = NULL;
    uint8_t         *pWptr = NULL;
    uint8_t         *pWptrPhy = NULL;
    uint8_t         *pWptrLimit = NULL;
    uint32_t        u32_err_cnt = 0;

    pWptrLimit      = (uint8_t *)pdev->CmdLimit;
    pbyWritePointer = (uint8_t *)rtd_inl(MD_SMQWRPTR_reg);
    pWptr           = (uint8_t *)pdev->CmdBuf + pdev->wrptr;
    pWptrPhy        = (uint8_t *)pdev->CmdBase + pdev->wrptr;

    if(lCommandLength == 0) {
        if(go) {
            rtd_outl(MD_SMQ_INT_STATUS_reg, MdIntCommandEmpty | MdWriteData);   /*clear com_empty interrupt status */
            rtd_outl(MD_SMQ_CNTL_reg, MdGo | MdEndianSwap | MdWriteData);
        }
        md_update_inst_count(pdev);
        PDEERR( "[%s][MD] get 0 cmd from caller.\n", __func__);
        goto WRITEFAIL;
    }

    if ((pdev->wrptr + lCommandLength) >= pdev->size) {
        while(1) {
            uint32_t rp = (uint32_t)rtd_inl(MD_SMQRDPTR_reg);
            if((uint32_t)pbyWritePointer == rp) {
                break;
            }
            udelay(1);
            u32_err_cnt++;
            /*add 200ms timeout*/
            if(u32_err_cnt > 200000) {
                PDEERR( "[%s][MD] checking available cmd queue time out, w=%08x, r=%08x, pwptr=%08x, cmdl=%d, psize=%08x\n",
                        __func__, (uint32_t)pbyWritePointer, (uint32_t)rp, (uint32_t)pdev->wrptr, lCommandLength, (uint32_t)pdev->size);
                goto WRITEFAIL;
            }
        }
    }
    u32_err_cnt = 0;
    while(1) {
        uint8_t *pbyReadPointer = (uint8_t *)rtd_inl(MD_SMQRDPTR_reg);
        if(pbyReadPointer <= pbyWritePointer) {
            pbyReadPointer += pdev->size;
        }

        if((pbyWritePointer + lCommandLength) < pbyReadPointer) {
            break;
        }
        udelay(1);
        u32_err_cnt++;
        /*add 200ms timeout*/
        if(u32_err_cnt > 200000) {
            PDEERR( "[%s][MD] getting available cmd queue time out, w=%08x, r=%08x, cmdl=%d\n",
                    __func__, (uint32_t)pbyWritePointer, (uint32_t)pbyReadPointer, lCommandLength);

            goto WRITEFAIL;
        }
    }

    DSB;
    for(dwDataCounter = 0; dwDataCounter < lCommandLength; dwDataCounter += sizeof(uint32_t)) {
        *((uint32_t *)(pWptr)) = (*(uint32_t *)(pbyCommandBuffer + dwDataCounter));

        pWptr += sizeof(uint32_t);
        pWptrPhy += sizeof(uint32_t);
        if((uint32_t)pWptrPhy >= (uint32_t)pWptrLimit) {
            pWptr = pWptr - pdev->size;
            pWptrPhy = pWptrPhy - pdev->size;
        }
    }
    pdev->u64IssuedInstCnt += lCommandLength / MD_ONE_CMD_LEN;

    DSB;

    pdev->wrptr += lCommandLength;
    pdev->cmd_cnt += lCommandLength;
    if (pdev->wrptr >= pdev->size)
        pdev->wrptr -= pdev->size;

    if(go) {
        /*toggle.... */
        rtd_outl(MD_SMQWRPTR_reg, (uint32_t)pWptrPhy);
        rtd_outl(MD_SMQ_CNTL_reg, MdGo | MdEndianSwap | MdWriteData);

        md_update_inst_count(pdev);
    } else {
        pdev->CmdWptr = (void *)pWptrPhy;
    }

    return MD_SUCCESS;
WRITEFAIL:
    return MD_ERR_WRITE_FAIL;
}

static int32_t WriteCmd_wrapper(struct md_dev *dev,
                                uint8_t *pbyCommandBuffer, uint32_t lCommandLength)
{
    int32_t wret = -1;
    int32_t timeoutcnt = 0;
    int32_t errcnt = 3;
    int32_t icnt = 3;
    uint32_t ori_rptr = 0;
    /*ToDo : add INT status conidtion.
     *      if err,then print cmd*/
    do {

        ori_rptr = rtd_inl(MD_SMQRDPTR_reg);
        md_dump_last_cmd();   // just for debug
        /*must be enable go bit!*/
        wret = WriteCmd(dev, pbyCommandBuffer, lCommandLength, 1);
        md_dump_last_hw_status();   // just for debug
        if(wret == MD_ERR_NO_SEM) {
            msleep(1);
            /*need this? or break*/
            timeoutcnt++;
        } else if(wret == MD_ERR_WRITE_FAIL) {
            msleep(1);
            timeoutcnt += 3;
        } else {
            /*if md is busy, should we need more delay?*/
            for(icnt = 0; icnt < errcnt; icnt++) {
                udelay(50);
                if(ori_rptr == rtd_inl(MD_SMQRDPTR_reg)) {
                    timeoutcnt += 10;
                } else {
                    goto WSUCCESS;
                }
            }
        }

        if(timeoutcnt >= 10) {
            PDEERR("%s timeout\n", __FUNCTION__);
            //md_reset();
            errcnt--;
            timeoutcnt = 0;
        }
    } while(wret != 0 || errcnt < 0);
WSUCCESS:
    return wret;
}

static int _md_memcpy(struct md_dev   *pdev, uint32_t        addrdst,
                      uint32_t addrsrc, int32_t len, uint32_t flags)
{
    uint32_t len_tmp = MD_SEQ_LEN_LIMIT;
    uint32_t dwcmdword[4] = {0};
    int32_t wret = 0;
    if(len <= 0)
        return wret;
    dwcmdword[0] = (MD_SS | MD_1B | ((flags & BIT(0))  ? MD_CONST : 0) |  ((flags & BIT(1))  ? MD_MOVE_DIR : 0));
    do {
        len_tmp = (len > MD_SEQ_LEN_LIMIT) ? MD_SEQ_LEN_LIMIT : len;

        dwcmdword[1] = addrdst;
        dwcmdword[2] = addrsrc;
        dwcmdword[3] = (len_tmp & MD_SEQ_LEN_LIMIT_MASK);

        wret = WriteCmd_wrapper(pdev, (uint8_t *)dwcmdword, sizeof(dwcmdword));
        len -= len_tmp;
        addrdst += len_tmp;
        addrsrc += len_tmp;
    } while(len);
    return wret;
}

int md_memcpy_multi_desc(uint8_t *srcBuf, uint32_t *dstBuf, struct md_dev *pdev, int length, int desc_num)
{
    int flags = 0, i = 0;
    unsigned long stime = 0;
    uint32_t pts_s = 0, pts_e = 0;
    uint32_t len_tmp = MD_SEQ_LEN_LIMIT;
    uint32_t dwcmdword[desc_num][4];
    int32_t wret = 0;
    uint32_t dst_phys_addr;
    uint32_t src_phys_addr = dma_map_single(md_drv_dev->md_device, (void *)srcBuf, length, DMA_BIDIRECTIONAL);

    md_drv_dev->CmdDone = 0;

    if(length <= 0)
        return wret;

    len_tmp = (length > MD_SEQ_LEN_LIMIT) ? MD_SEQ_LEN_LIMIT : length;

    for(i = 0; i < desc_num; i++) {
        dst_phys_addr = dma_map_single(md_drv_dev->md_device, (void *)(dstBuf[i]), length, DMA_BIDIRECTIONAL);
        dwcmdword[i][0] = (MD_SS | MD_1B | ((flags & BIT(0))  ? MD_CONST : 0) |  ((flags & BIT(1))  ? MD_MOVE_DIR : 0));
        dwcmdword[i][1] = dst_phys_addr;
        dwcmdword[i][2] = src_phys_addr;
        dwcmdword[i][3] = (len_tmp & MD_SEQ_LEN_LIMIT_MASK);
        //printk("daddress src=%p, dst=%p, dwd=%p\n", src_phys_addr, dst_phys_addr, dwcmdword[i][1]);
    }

    if (down_interruptible(&md_drv_dev->sem))
        return -1;
    stime = jiffies;
    pts_s = rtd_inl(0xb801b690);
    wret = WriteCmd_wrapper(pdev, (uint8_t *)dwcmdword[0], sizeof(dwcmdword));
    up(&md_drv_dev->sem);
    if(wret != MD_SUCCESS) {
        printk("[MD]%s fail(%d).\n", __func__, wret);
    }

    smd_checkComplete();
    pts_e = rtd_inl(0xb801b690);
    printk("[MD] md_memcpy_test speed test len = %d, time = %d, %d us, %d ms\n", length, desc_num, (pts_e - pts_s) * (1000000 / 90090), jiffies_to_msecs(jiffies - stime));

    /* unmap dma */
    dma_unmap_single(md_drv_dev->md_device, src_phys_addr, length, DMA_BIDIRECTIONAL);
    for(i = 0; i < desc_num; i++) {
        dma_unmap_single(md_drv_dev->md_device, dwcmdword[i][1], length, DMA_BIDIRECTIONAL);
    }
    /* compare result */
    for(i = 0; i < desc_num; i++) {
        if(memcmp((void*)srcBuf, (void*)(dstBuf[i]), length) == 0) {
            //printk("[MD][i=%d] memcpy ok\n", i);
        } else {
            printk(KERN_ALERT "[MD][i=%d] memcpy fail\n", i);
            printk(KERN_ALERT "%x,%x,%x,%x\n", srcBuf[0], srcBuf[1], srcBuf[2], srcBuf[3]);
            printk(KERN_ALERT "%x,%x,%x,%x\n", ((uint8_t*)(dstBuf[i]))[0], ((uint8_t*)(dstBuf[i]))[1], ((uint8_t*)(dstBuf[i]))[2], ((uint8_t*)(dstBuf[i]))[3]);
        }
    }
    return wret;
}

void rtk_md_enable_mult_reg(int on_off)
{
    if(on_off == 1)
        rtd_outl(MD_MULTI_REQ_reg, 0x00000021);  //Multi-req default value = 0x00000021
    else
        rtd_outl(MD_MULTI_REQ_reg, 0x00000020);
}

static int _md_wait_hw_stopped(struct md_dev *pdev, uint64_t timeout)
{
    /*clear cmd empty interrupt */
    rtd_outl(MD_SMQ_INT_STATUS_reg, MdIntCommandEmpty | MdWriteData);
    PDEBUG("\nioctl wait for complete, %08x\n", rtd_inl(MD_SMQ_CNTL_reg));
    if(rtd_inl(MD_SMQ_CNTL_reg) & MdGo) {
        rtd_outl(MD_SMQ_INT_STATUS_reg, MdIntCommandEmpty | MdWriteData);
        PDEBUG("\nwait for complete before down\n");
        wait_event_interruptible_timeout(pdev->wait_queue,
                                         (pdev->CmdDone == 1), timeout);
        PDEBUG("\nwait for complete after down\n");
        if(pdev->CmdDone == 1) {
            return 0;
        }
        return -1;
    }
    return 0;
}

int md_wait_hw_stopped(uint64_t timeout)
{
    int retval = 0;
    if (down_interruptible(&md_drv_dev->sem))
        return -ERESTARTSYS;
    retval = _md_wait_hw_stopped(md_drv_dev, timeout);
    up(&md_drv_dev->sem);
    return retval;
}

int md_get_inst_count(uint64_t *p_u64InstCnt)
{
    if(!p_u64InstCnt)
        return -1;
    if (down_interruptible(&md_drv_dev->sem))
        return -ERESTARTSYS;
    md_update_inst_count(md_drv_dev);
    *p_u64InstCnt = md_drv_dev->u64InstCnt;
    up(&md_drv_dev->sem);
    return MD_SUCCESS;
}

int md_get_issued_inst_count(uint64_t *p_u64IssuedInstCnt)
{
    if(!p_u64IssuedInstCnt)
        return -1;
    *p_u64IssuedInstCnt = md_drv_dev->u64IssuedInstCnt;
    return MD_SUCCESS;
}

int md_memcpy(uint32_t dst_phys_addr, uint32_t src_phys_addr,
              uint32_t length, int32_t op, uint32_t is_wait)
{

    PDEBUG("%s,%d, dst_phys_addr=0x%08x, src_phys_addr=0x%08x, length=%d\n", __func__, __LINE__, dst_phys_addr, src_phys_addr, length);
    if(length == 0) {
        PDEWAR("md_copy_pages with zero length = %d, ignore it\n", length);
        return 0;
    }
    if (down_interruptible(&md_drv_dev->sem))
        return -ERESTARTSYS;
    md_drv_dev->CmdDone = 0;
    _md_memcpy(md_drv_dev, dst_phys_addr, src_phys_addr, length, op);
    if(is_wait) {
        /*Enable empty interrupt */
        rtd_outl(MD_SMQ_INT_ENABLE_reg, MdIntCommandEmpty | MdIntSCPUInt | MdWriteData);
        wait_event_interruptible_timeout(md_drv_dev->wait_queue, (md_drv_dev->CmdDone == 1), (2 * HZ));
        if(md_drv_dev->CmdDone == 0) {
            PDEBUG("MD : no empty interrupt.\n");
            up(&md_drv_dev->sem);
            return -1;
        }
    }
    up(&md_drv_dev->sem);
    return 0;
}

int md_do_cmds(uint8_t *pbyCommandBuffer, uint32_t lCommandLength)
{
    int retval = 0;
    if(pbyCommandBuffer == NULL || lCommandLength == 0)
        return -1;
    if (down_interruptible(&md_drv_dev->sem)) {
        return -ERESTARTSYS;
    }
    md_drv_dev->CmdDone = 0;
    retval = WriteCmd_wrapper(md_drv_dev, pbyCommandBuffer, lCommandLength);
    up(&md_drv_dev->sem);
    return retval;
}


static void rtk_md_self_checking(void)
{
    /*self-checking*/
    int retry_cnt = 0;
    for(retry_cnt = 0; retry_cnt <= 2; retry_cnt++) {
        smd_memcpy((unsigned long)rtd_inl(MD_SMQBASE_reg) + 0x1000,
                   (unsigned long)(rtd_inl(MD_SMQBASE_reg) + 0x2000), 0x40);
        smd_checkComplete();
        if(rtd_inl(MD_SMQ_INSTCNT_reg) >= 1) {
            PDEIFO("[MD]%s success.instcnt=%d\n", __func__, rtd_inl(MD_SMQ_INSTCNT_reg));
            break;
        }
    }

    SET_DUMMY2_REG(SMQ_SELF_CHECK, FINISH);
    PDEIFO( "%s kcpu md status(%s), scpu md status(%s)\n", __FUNCTION__, GET_KMQ_STATUS() == STOP ? "stop" : "run", GET_DUMMY1_REG(SMQ_STATUS) == STOP ? "stop" : "run");

}

#ifdef CONFIG_PM
int md_suspend_noirq(void)
{
    int retrycnt = 0;
    PDEIFO("[MD]%s\n", __func__);

    while(!(rtd_inl(MD_SMQ_CNTL_reg) & MD_SMQ_CNTL_smq_idle_mask)
#if defined(MD_RECOVERY_KCPU)
          || !(rtd_inl(MD_KMQ_CNTL_reg) & MD_KMQ_CNTL_kmq_idle_mask)
#endif
#ifndef CONFIG_OPTEE
          || ( GET_KMQ_STATUS() != STOP )
#endif
         ) {

        if(retrycnt >= 6000) {
            PDEERR("[MD]wait finish timeout.\n");
            break;
        }

        if ( retrycnt == 0 ) {
            if (!(rtd_inl(MD_SMQ_CNTL_reg) & MD_SMQ_CNTL_smq_idle_mask))
                PDEIFO("scpu md is not idle... will retry again.\n");
#ifndef CONFIG_OPTEE
            if (GET_KMQ_STATUS() != STOP) {
                PDEIFO("kcpu md is not ok... will retry again.\n");
            }
#endif
            if(retrycnt >= 6000) {
                PDEERR("[MD]wait finish timeout.\n");
                break;
            }
        }
        retrycnt++;
        udelay(100);
    }

    SET_DUMMY1_REG(SMQ_STATUS, STOP);
    SET_DUMMY2_REG(SMQ_SELF_CHECK, RESET);
#ifndef CONFIG_OPTEE
    PDEIFO( "suspend stop kcpu md(%s) and scpu md(%s)\n", GET_KMQ_STATUS() == STOP ? "stop" : "run", GET_DUMMY1_REG(SMQ_STATUS) == STOP ? "stop" : "run");
#endif

#if defined(MD_RECOVERY_VCPU)
    md_store_v_reg();
#endif

#if defined(MD_RECOVERY_KCPU)
    md_store_k_reg();
#endif
#ifndef CONFIG_OPTEE
    /*ensure KMQ_STATUS is  stop  */
    while( GET_KMQ_STATUS() != STOP ) {
        msleep(1);
    }
#endif
    /* clock disable */
    CRT_CLK_OnOff(MD, CLK_OFF, NULL);
    return 0;
}

int md_resume_noirq(void)
{
    PDEIFO("[MD]%s\n", __func__);
    md_init_reg(md_drv_dev);
    return 0;
}

int md_resume_early(void)
{
    PDEIFO("[MD]%s\n", __func__);
    rtk_md_self_checking();
    return 0;
}

int md_restore(void)
{
    PDEIFO("[MD]%s\n", __func__);
    md_init_reg(md_drv_dev);
    rtk_md_self_checking();
    return 0;
}

int md_freeze_noirq(void)
{
    PDEIFO("[MD]%s\n", __func__);
    SET_DUMMY2_REG(SMQ_SELF_CHECK, FINISH);
    return 0;
}

int md_poweroff(void)
{
    int retrycnt = 0;

    PDEIFO("[MD]%s\n", __func__);
    /* Check idle bit */
    while(!(rtd_inl(MD_SMQ_CNTL_reg) & MD_SMQ_CNTL_smq_idle_mask)
#if defined(MD_RECOVERY_KCPU)
          || !(rtd_inl(MD_KMQ_CNTL_reg) & MD_KMQ_CNTL_kmq_idle_mask)
//#else
#ifndef CONFIG_OPTEE
//          || GET_KMQ_STATUS()
#endif
#endif
         ) {
        udelay(1);
        retrycnt++;
        if(retrycnt >= 10000) {
            PDEERR("[MD]wait finish timeout.\n");
            break;
        }
    }

    SET_DUMMY1_REG(SMQ_STATUS, STOP);
    SET_DUMMY2_REG(SMQ_SELF_CHECK, RESET);

#if defined(MD_RECOVERY_VCPU)
    md_store_v_reg();
#endif

#if defined(MD_RECOVERY_KCPU)
    md_store_k_reg();
#endif

    /* clock disable */
    CRT_CLK_OnOff(MD, CLK_OFF, NULL);

    PDEIFO("[MD]%s success.\n", __func__);
    return 0;
}

#endif

__init int rtk_md_init(struct device *md_device)
{
    int ret = 0;
    uint32_t dwPhysicalAddress = 0;

    md_drv_dev = kzalloc(sizeof(struct md_dev), GFP_KERNEL);
    if (!md_drv_dev) {
        ret = -ENOMEM;
        goto FAIL_ALLOCATE_MD_DEV;
    }
    sema_init(&md_drv_dev->sem, 1);
    init_waitqueue_head(&md_drv_dev->wait_queue);
    md_drv_dev->size = MD_CMD_BUF;

    md_drv_dev->CmdBuf = dma_alloc_coherent(md_device, md_drv_dev->size, &
                                            dwPhysicalAddress, GFP_ATOMIC);
    if(!md_drv_dev->CmdBuf) {
        ret = -ENOMEM;
        goto FAIL_ALLOCATE_CMD_BUFFER;
    }
    PDEIFO("Command Buffer Address = %x, Physical Address = %x, Size = %08x\n",
           (uint32_t) md_drv_dev->CmdBuf, (uint32_t)
           dwPhysicalAddress, md_drv_dev->size);
    md_drv_dev->wrptr = 0;
    md_drv_dev->CmdBase = (void *) dwPhysicalAddress;
    md_drv_dev->CmdLimit = (void *) (dwPhysicalAddress + md_drv_dev->size);
    md_drv_dev->md_device = md_device;

    ret = request_irq(IRQ_GET_KERNEL_IRQ_NUM(IRQ_MD), md_irq_handler,
                      IRQF_SHARED, "md", (void *)md_drv_dev);
    if(ret < 0) {
        PDEERR("[MD] Request irq %d failed\n", IRQ_GET_KERNEL_IRQ_NUM(
                   IRQ_MD));
        goto FAIL_REQUEST_IRQ;
    }

#if defined(MD_RECOVERY_VCPU)
    md_store_v_reg();
#endif
#if defined(MD_RECOVERY_KCPU)
    md_store_k_reg();
#endif
    md_init_reg(md_drv_dev);

    rtk_md_self_checking();

    return 0;
FAIL_REQUEST_IRQ:
    dma_free_coherent(md_drv_dev->md_device, md_drv_dev->size,
                      (void*)md_drv_dev->CmdBuf, (dma_addr_t)md_drv_dev->CmdBase);
FAIL_ALLOCATE_CMD_BUFFER:
    kfree(md_drv_dev);
    md_drv_dev = NULL;
FAIL_ALLOCATE_MD_DEV:
    return ret;
}


__exit void rtk_md_uninit(void)
{
    free_irq(IRQ_GET_KERNEL_IRQ_NUM(IRQ_MD), (void *)md_drv_dev);
    dma_free_coherent(md_drv_dev->md_device, md_drv_dev->size, (void*)md_drv_dev->
                      CmdBuf, (dma_addr_t)md_drv_dev->CmdBase);
    kfree(md_drv_dev);
    md_drv_dev = NULL;
}



/**********************The MD global apis for other modules in kernel to call**************************/
uint64_t smd_memcpy(
    uint32_t        addrDst,
    uint32_t        addrSrc,
    int32_t         len)
{
    int wret = md_memcpy(addrDst, addrSrc, len, 0, 0);
    if(wret != MD_SUCCESS) {
        PDEERR( "[MD]%s fail(%d).\n", __func__, wret);
    }
    return md_drv_dev->u64IssuedInstCnt;
}
EXPORT_SYMBOL(smd_memcpy);

bool smd_waitComplete(
    uint64_t        handle,
    uint64_t        timeout,
    uint64_t        *hwCnt)
{
    if (down_interruptible(&md_drv_dev->sem))
        return false;
    /* Enable empty interrupt */
    rtd_outl(MD_SMQ_INT_ENABLE_reg,
             MdIntCommandEmpty | MdIntSCPUInt | MdWriteData);
    _md_wait_hw_stopped(md_drv_dev, timeout);
    if(md_drv_dev->CmdDone == 0) {
        PDEALT("MD : no empty interrupt.\n");
        up(&md_drv_dev->sem);
        return false;
    }
    md_update_inst_count(md_drv_dev);
    hwCnt = (uint64_t*) &md_drv_dev->u64InstCnt;
    up(&md_drv_dev->sem);
    return true;
}
EXPORT_SYMBOL(smd_waitComplete);

bool smd_checkFinish(
    uint64_t        handle)
{
    uint64_t sw_counter = (uint64_t)handle;
    if(down_timeout(&md_drv_dev->sem, HZ / 10)) {
        PDEERR( "[MD]%s down_tiemput!\n", __func__);
        return false;
    }
    md_update_inst_count(md_drv_dev);
    up(&md_drv_dev->sem);

    if(md_drv_dev->u64InstCnt >= sw_counter) {
        return true;
    }
    return false;
}
EXPORT_SYMBOL(smd_checkFinish);


void smd_checkComplete(void)
{
    uint32_t u32_err_cnt = 0;
    while(1) {
        if(smd_checkFinish(md_drv_dev->u64IssuedInstCnt))
            break;
        udelay(200);
        u32_err_cnt++;
        /*add 200ms timeout*/
        if(u32_err_cnt > 1000) {
            PDEERR("%s timeout\n", __FUNCTION__);
            md_reset();
            break;
        }
    }
}
EXPORT_SYMBOL(smd_checkComplete);

/***********************The MD APIS for Reg Mode***********************************************************/
int md_fill(uint32_t addrdst, int32_t len,
            uint32_t bytemode, uint32_t movemode, uint32_t val)
{
    uint8_t const_data = (val & 0xff);
    uint32_t len_tmp = 0;
    int32_t timeout = 0;
    if(len <= 0)
        return 0;
    if(down_interruptible(&md_drv_dev->sem))
        return -1;
    do {
        rtd_outl(MD_REG_CMD1_reg, (movemode | bytemode | MD_CONST));
        rtd_outl(MD_REG_CMD2_reg, addrdst);
        rtd_outl(MD_REG_CMD5_reg, const_data | (const_data << 8) |
                            (const_data << 16) | (const_data << 24));
        timeout = 0;
        len_tmp = (len > MD_SEQ_LEN_LIMIT) ? MD_SEQ_LEN_LIMIT : len;
        
        rtd_outl(MD_REG_CMD4_reg, len_tmp & MD_SEQ_LEN_LIMIT_MASK);

        rtd_outl(MD_REG_CTRL_reg, 0x1);
        rtd_outl(MD_REG_MODE_reg, 0x1);

        while(rtd_inl(MD_REG_MODE_reg) & 0x1) {
            msleep(1);
            timeout++;
            if(timeout > 100) {
                PDEERR("[%s]timeout,size=%d", __func__, timeout);
                rtd_outl(MD_REG_MODE_reg, 0);
                up(&md_drv_dev->sem);
                return -1;
            }
        }
        len -= len_tmp;
        addrdst += len_tmp;
    } while(len);
    rtd_outl(MD_REG_MODE_reg, 0);
    up(&md_drv_dev->sem);
    return 0;
}

int smd_fill(uint32_t addrdst, int32_t len, uint32_t val)
{
    return md_fill(addrdst, len, MD_1B, MD_SS, val);
}

