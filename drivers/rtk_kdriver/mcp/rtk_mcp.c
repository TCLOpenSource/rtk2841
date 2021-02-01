#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/dma-mapping.h>
#include <linux/notifier.h>
#include <linux/list.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <mach/irqs.h>
#include <asm/mutex.h>
#include <mach/io.h>
#include <rtk_kdriver/rtk_mcp.h>
#include <rtk_kdriver/rtk_crt.h>
#include "rtk_mcp_dbg.h"
#include "rtk_mcp_reg.h"

#define USE_DVR_MALLOC
#ifdef USE_DVR_MALLOC
#include <linux/pageremap.h>       // for dvr_malloc / dvr_free
#endif

static struct device*   mcp_device;
extern int DisplayDesc;
extern int DisplayFIFO;
extern unsigned long pre_base;
extern unsigned long pre_limit;
extern unsigned long pre_rp;
extern unsigned long pre_wp;
static DEFINE_SPINLOCK(mcp_buffer_lock);
static DEFINE_MUTEX(mcp_mutex);


#ifdef MCP_INTERRUPT_ENABLE
DECLARE_WAIT_QUEUE_HEAD(mcp_wait_queue);

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)          gic_irq_find_mapping(hwirq)
#define DSB                                    dsb(sy)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)          (hwirq)
#define DSB                                    asm("DSB")
#endif

#define MCP_IRQ    IRQ_GET_KERNEL_IRQ_NUM(IRQ_MCP)              // defined in
#endif


#define _mcp_map_single(p_data, len, dir)       dma_map_single(mcp_device, (void*) p_data, (size_t) len, dir)
#define _mcp_unmap_single(p_data, len, dir)     dma_unmap_single(mcp_device, (dma_addr_t) p_data, (size_t)  len, dir)

static mcp_desc*  desc_list;
static dma_addr_t desc_list_dma_handle = 0;

#ifdef MCP_INTERRUPT_ENABLE
static irqreturn_t mcp_isr(int irq, void* dev_id)
{
    if ((GET_MCP_STATUS() & ~(MCP_COMPARE))) {
        SET_MCP_EN(0xFE);           // disable all interrupts
        wake_up(&mcp_wait_queue);
        return IRQ_HANDLED;
    }

    return IRQ_NONE;
}

#endif

/******************************Some debug functions*****************************************/
void _DumpDescriptor(mcp_desc* d)
{
    mcp_warning("\n\nXXXXXXXX desc (%p) XXXXXXXXXX\n", d);
    mcp_warning("flag=%08x\n", d->flags);
    mcp_warning("Key0=%08x\n", d->key[0]);
    mcp_warning("Key1=%08x\n", d->key[1]);
    mcp_warning("Key2=%08x\n", d->key[2]);
    mcp_warning("Key3=%08x\n", d->key[3]);
    mcp_warning("Key4=%08x\n", d->key[4]);
    mcp_warning("Key5=%08x\n", d->key[5]);
    mcp_warning("IV0=%08x\n", d->iv[0]);
    mcp_warning("IV1=%08x\n", d->iv[1]);
    mcp_warning("IV2=%08x\n", d->iv[2]);
    mcp_warning("IV3=%08x\n", d->iv[3]);
    mcp_warning("data_in=%08x\n", d->data_in);
    mcp_warning("data_out=%08x\n", d->data_out);
    mcp_warning("len=%08x\n", d->length);
    mcp_warning("XXXXXXXX desc end XXXXXXXXXX\n\n");
}


/*------------------------------------------------------------------
 * Func : _mcp_dump_desc_buffer
 * Desc : set descriptors buffer
 *------------------------------------------------------------------*/
void _mcp_dump_desc_buffer(int warning)
{
    unsigned long event;
    unsigned long base;
    unsigned long limit;
    unsigned long rp;
    unsigned long wp;

    spin_lock_irqsave(&mcp_buffer_lock, event);

    base = GET_MCP_BASE();
    rp   = GET_MCP_RDPTR();
    wp   = GET_MCP_WRPTR();
    limit = GET_MCP_LIMIT();

    spin_unlock_irqrestore(&mcp_buffer_lock, event);

    if (warning) {
        mcp_warning("BASE=%08lx, RP=%08lx, WP=%08lx, LIMIT=%08lx\n", base, rp, wp, limit);
    } else {
        mcp_info("BASE=%08lx, RP=%08lx, WP=%08lx, LIMIT=%08lx\n", base, rp, wp, limit);
    }
}


void DumpDescriptor(mcp_desc* d, int display_desc, int display_fifo)
{
    if(display_desc) {
        _DumpDescriptor(d);
    }
    if(display_fifo) {
        _mcp_dump_desc_buffer(1);
    }
}

void mcp_dump_all_desc(char * buf)
{
    int offset = -1;
    unsigned long event;

    if (desc_list == NULL)
        return;

    if (offset < 0) { // dump the latest one
        spin_lock_irqsave(&mcp_buffer_lock, event);
        offset = (GET_MCP_RDPTR() - GET_MCP_BASE()) / sizeof(mcp_desc);
        if (offset > 0)
            offset--;
        spin_unlock_irqrestore(&mcp_buffer_lock, event);
    }

    if (offset < MCP_DESC_ENTRY_COUNT) {
        sprintf(buf, "\n\nXXXXXXXX desc (%p) XXXXXXXXXX\n", &desc_list[offset]);
        sprintf(buf + strlen(buf), "flag=%08x\n", (&desc_list[offset])->flags);
        sprintf(buf + strlen(buf), "Key0=%08x\n", (&desc_list[offset])->key[0]);
        sprintf(buf + strlen(buf), "Key1=%08x\n", (&desc_list[offset])->key[1]);
        sprintf(buf + strlen(buf), "Key2=%08x\n", (&desc_list[offset])->key[2]);
        sprintf(buf + strlen(buf), "Key3=%08x\n", (&desc_list[offset])->key[3]);
        sprintf(buf + strlen(buf), "Key4=%08x\n", (&desc_list[offset])->key[4]);
        sprintf(buf + strlen(buf), "Key5=%08x\n", (&desc_list[offset])->key[5]);
        sprintf(buf + strlen(buf), "IV0=%08x\n", (&desc_list[offset])->iv[0]);
        sprintf(buf + strlen(buf), "IV1=%08x\n", (&desc_list[offset])->iv[1]);
        sprintf(buf + strlen(buf), "IV2=%08x\n", (&desc_list[offset])->iv[2]);
        sprintf(buf + strlen(buf), "IV3=%08x\n", (&desc_list[offset])->iv[3]);
        sprintf(buf + strlen(buf), "di=%08x\n", (&desc_list[offset])->data_in);
        sprintf(buf + strlen(buf), "do=%08x\n", (&desc_list[offset])->data_out);
        sprintf(buf + strlen(buf), "len=%08x\n", (&desc_list[offset])->length);
        sprintf(buf + strlen(buf), "XXXXXXXX desc end XXXXXXXXXX\n\n");
    }
}
/*------------------------------------------------------------------
 * Func : _mcp_dump_desc_buffer_context
 *
 * Desc : dump descriptors context
 *
 * Parm : offset : > 0
 *        -1 : the last
 *
 * Retn : dma_addr
 *------------------------------------------------------------------*/
void _mcp_dump_desc_buffer_context(int offset)
{
    unsigned long event;

    if (desc_list == NULL)
        return;

    if (offset < 0) { // dump the latest one
        spin_lock_irqsave(&mcp_buffer_lock, event);
        offset = (GET_MCP_RDPTR() - GET_MCP_BASE()) / sizeof(mcp_desc);
        if (offset > 0)
            offset--;
        spin_unlock_irqrestore(&mcp_buffer_lock, event);
    }

    if (offset < MCP_DESC_ENTRY_COUNT)
        _DumpDescriptor(&desc_list[offset]);
}


#define DEBUG_REG1 0xb80150F0
#define DEBUG_REG2 0xb80150F4
#define DEBUG_REG3 0xb80151a0
#define DEBUG_REG4 0xb80151a4

/*------------------------------------------------------------------
* Func : _mcp_dump_hw_internal_FSM
*
* Desc : dump MCP HW FSM register
*------------------------------------------------------------------*/
void _mcp_dump_hw_internal_FSM(void)
{
    unsigned int debug_reg1_val;
    unsigned int debug_reg2_val;
    unsigned int debug_reg3_val;
    unsigned int debug_reg4_val;

    rtd_outl(DEBUG_REG1, 0x000002d7);
    udelay(10);
    debug_reg1_val = rtd_inl(DEBUG_REG1);
    debug_reg2_val = rtd_inl(DEBUG_REG2);
    debug_reg3_val = rtd_inl(DEBUG_REG3);
    debug_reg4_val = rtd_inl(DEBUG_REG4);

    mcp_warning("0xB80150F0=%08x, 0xB80150F4=%08x, 0xB80151A0=%08x, 0xB80151A4=%08x\n",
                debug_reg1_val, debug_reg2_val,
                debug_reg3_val, debug_reg4_val);
}


/*------------------------------------------------------------------
 * Func : _mcp_load_otp
 * Desc : load otp key
 *------------------------------------------------------------------*/
static void _mcp_load_otp(void)
{
    int i = 0;

    SET_MCP_OTP_LOAD(1);
    while(GET_MCP_OTP_LOAD()) {
        if (i++ > 100) {
            mcp_warning("Load OTP Key Timeout\n");
            break;
        }
        udelay(10);
    }
}



/*------------------------------------------------------------------
 * Func : _mcp_phy_init
 * Desc : init mcp engine
 *------------------------------------------------------------------*/
static int _mcp_phy_init(void)
{
    _mcp_load_otp();

    SET_MCP_CTRL(MCP_GO);       /* dessert go bit*/
    SET_MCP_EN(0xFE);           /* disable all interrupts*/
    SET_MCP_STATUS(0xFE);       /* clear interrupts status*/
    SET_MCP_BASE (0);
    SET_MCP_LIMIT(0);
    SET_MCP_RDPTR(0);
    SET_MCP_WRPTR(0);
    SET_MCP_CTRL(MCP_ARB_MODE(1) | MCP_WRITE_DATA);     /* set arbitraction mode to mode 1*/
    SET_MCP_CTRL1(MCP_AES_PAD_OFF(1) |                  /* disable AES_H auto padding*/
                  MCP_CSA_ENTROPY(ORIGIONAL_MODE) |    /* setup csa mode*/
                  MCP_ROUND_NO(0));                     /* set round number of multi-2 to 1*/

    return 0;
}


/*------------------------------------------------------------------
 * Func : _mcp_set_desc_buffer
 *
 * Desc : set descriptors buffer
 *
 * Parm : base  : base address of descriptor buffer
 *        limit : limit address of descriptor buffer
 *        rp    : read pointer of descriptor buffer
 *        wp    : write pointer of descriptor buffer
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int _mcp_set_desc_buffer(
    unsigned long           base,
    unsigned long           limit,
    unsigned long           rp,
    unsigned long           wp
)
{
    unsigned long event;
    spin_lock_irqsave(&mcp_buffer_lock, event);

    if (base & 0x7)
        mcp_warning("Set MCP Descriptor Buffer with non 8 byte alignment base address - %08lx\n", base);

    if (limit & 0x7)
        mcp_warning("Set MCP Descriptor Buffer with non 8 byte alignment limit address - %08lx\n", limit);

    if (rp & 0x7)
        mcp_warning("Set MCP Descriptor Buffer with non 8 byte alignment rp - %08lx\n", rp);

    if (wp & 0x7)
        mcp_warning("Set MCP Descriptor Buffer with non 8 byte alignment rp - %08lx\n", wp);

    if (((limit - base) % 56))
        mcp_warning("Set MCP Descriptor Buffer size (%lu) is not multiple of 56\n", limit - base);

    if(base != 0 && limit != 0 && rp != 0 && wp != 0) {
        pre_base = base;
        pre_limit = limit;
        pre_rp = rp;
        pre_wp = wp;
    }


    SET_MCP_BASE (base);
    SET_MCP_LIMIT(limit);
    SET_MCP_RDPTR(rp);
    SET_MCP_WRPTR(wp);

    spin_unlock_irqrestore(&mcp_buffer_lock, event);

    return 0;
}

/*------------------------------------------------------------------
* Func : _mcp_sw_reset
* Desc : recover mcp from a error condition
*------------------------------------------------------------------*/
void _mcp_sw_reset(void)
{
    unsigned char key[16];


    mcp_warning("mcp fsm reset\n");
    SET_MCP_EN(0xE);               // disable all interrupts
    SET_MCP_CTRL(MCP_GO);          // clear go bit
    udelay(10);
    SET_MCP_CTRL(MCP_CLEAR | 1);   // set up clear flag
    SET_MCP_STATUS(0xFE);          // clear status
    udelay(10);
    SET_MCP_CTRL(MCP_CLEAR);       // set up clear flag

    // add a fake command to restart the Command
    MCP_AES_DESC_INIT(desc_list, 0, MCP_BCM_ECB, key, key);
    desc_list[0].data_in  = desc_list_dma_handle + sizeof(mcp_desc) * 10;
    desc_list[0].data_out = desc_list[0].data_in;
    desc_list[0].length   = 16;

    mcp_warning("_mcp_sw_reset ... do a dummy command...\n");

    _mcp_set_desc_buffer(desc_list_dma_handle,                          // Base
                         desc_list_dma_handle + sizeof(mcp_desc) * 2, // Limit
                         desc_list_dma_handle,                          // RP
                         desc_list_dma_handle + sizeof(mcp_desc));                   // WP

    SET_MCP_CTRL(MCP_GO | 0x1);          // do go
    msleep(10);
    SET_MCP_CTRL(MCP_GO);
}


#ifdef MCP_INTERRUPT_ENABLE


/*------------------------------------------------------------------
 * Func : _mcp_start_xfer
 *
 * Desc : Start Xfer
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *------------------------------------------------------------------*/
int _mcp_start_xfer(void)
{
    int ret = -1;
    unsigned long ctrl;
    unsigned long status;
    unsigned long stime = 0;
    int complete = 0;
    int try_count = HZ >> 1;
    int wait_count = 0;

    if ((GET_MCP_CTRL() & MCP_CLEAR))
        SET_MCP_CTRL(MCP_CLEAR);   // deassert clear flag

    SET_MCP_STATUS(~0x1);    // clear all status
    SET_MCP_EN(MCP_ERROR | MCP_RING_EMPTY | MCP_WRITE_DATA);     // enable ring empty interr
    SET_MCP_CTRL(MCP_GO | MCP_WRITE_DATA);
    stime = jiffies;

    while(complete == 0 && try_count-- > 0) {
        ret = wait_event_timeout(mcp_wait_queue, (GET_MCP_CTRL() & MCP_GO) == 0, 10);

        ctrl = GET_MCP_CTRL();
        status = GET_MCP_STATUS();

        if ((status & MCP_ERROR)) {
            _mcp_dump_desc_buffer(1);
            _mcp_dump_hw_internal_FSM();

            _mcp_dump_desc_buffer_context(-1);  // dump last RP

            // Reset FSM
            _mcp_sw_reset();

            mcp_warning("do command error, after reset (Ctrl=%08lx->%08x, Status=%08lx->%08x) (Spend time %d ms)\n",
                        ctrl, GET_MCP_CTRL(), status, GET_MCP_STATUS(),  jiffies_to_msecs(jiffies - stime));

            complete = 1;
            ret = -1;
        } else if (!(ctrl & MCP_GO) || (status & MCP_RING_EMPTY)) {
            // normal complete
            complete = 1;
            ret = 0;
        } else if ((ctrl & MCP_GO) && (GET_MCP_RDPTR() == GET_MCP_WRPTR())) {
            // sometimes the empty event will be clear
            if (wait_count++ < 10)  // wait (around 100ms)
                continue;

            mcp_warning("wait command complete timeout, but Ring Empty, (%d), (Ctrl=%08lx, Status=%08lx) (Spend time %d ms)\n",
                        ret, ctrl, status,  jiffies_to_msecs(jiffies - stime));
            _mcp_dump_hw_internal_FSM();
            complete = 1;
            ret = 0;
        }

    }

    if (!complete) {
        mcp_warning("wait command complete timeout, ret fsm (%d), (Ctrl=%08lx, Status=%08lx) (Spend time %d ms) kcpu\n",
                    ret, ctrl, status,  jiffies_to_msecs(jiffies - stime));
        _mcp_dump_desc_buffer(1);
        _mcp_dump_hw_internal_FSM();
        // Reset FSM
        _mcp_sw_reset();
        ret = -1;
    }

    SET_MCP_CTRL(MCP_GO);               // clear go bit

    SET_MCP_STATUS(0xFE);               // clear ring empty

    SET_MCP_EN(0xFE);                   // disable all interrupts

    return ret;
}


#else


/*------------------------------------------------------------------
 * Func : _mcp_start_xfer
 *
 * Desc : Start Xfer
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *------------------------------------------------------------------*/
int _mcp_start_xfer(void)
{
    int ret = -1;
    unsigned long wiat_timeout = jiffies +  msecs_to_jiffies(10);

    SET_MCP_CTRL(MCP_CLEAR | MCP_WRITE_DATA);    // issue clear

    while (GET_MCP_CTRL() & MCP_CLEAR && time_before(jiffies, wiat_timeout));

    if (GET_MCP_CTRL() & MCP_CLEAR) {
        mcp_debug("wait clear bit deassert timeout,  force unset clear bit, (CTRL=%08x, STATUS=%08x)\n",
                  GET_MCP_CTRL(), GET_MCP_STATUS());
        SET_MCP_CTRL(MCP_CLEAR);    // issue clear
        mcp_debug("CTRL=%08x, STATUS=%08x)\n", GET_MCP_CTRL(), GET_MCP_STATUS());
    }

    SET_MCP_EN(0xFE);

    SET_MCP_STATUS(0xFE);    // clear status

    SET_MCP_CTRL(MCP_GO | MCP_WRITE_DATA);

    wiat_timeout = jiffies +  HZ;

    while (time_before(jiffies, wiat_timeout)) {
        unsigned long ctrl = GET_MCP_CTRL();
        unsigned long status = GET_MCP_STATUS();

        mcp_debug("STATUS=%08lx, CTRL=%08lx\n", status, ctrl);

        if (!(ctrl & MCP_GO) || (ctrl & MCP_IDEL)) {
            mcp_debug("MCP Check Ctrl Ready=%08lx\n", ctrl);
            break;
        }

        if (status & (MCP_RING_EMPTY | MCP_ERROR | MCP_COMPARE | MCP_ACP_ERR)) {
            mcp_debug("MCP Check Status Ready=%08x\n", status);
            break;
        }

        msleep(1);
    }

    if (time_after(jiffies, wiat_timeout)) {
        mcp_warning("wait MCP timeout\n");
    }

    ret = ((GET_MCP_STATUS() & ~(MCP_RING_EMPTY | MCP_COMPARE))) ? -1 : 0;

    if (ret < 0)
        mcp_warning("do mcp command failed, (MCP_Status %08x)\n", GET_MCP_STATUS());

    SET_MCP_CTRL(MCP_GO);               // clear go bit

    SET_MCP_STATUS(0xFE);               // clear ring empty

    return ret;
}

#endif


/*------------------------------------------------------------------
 * Func : mcp_fixup_descriptor_jupiter
 *
 * Desc : fixup descriptor
 *
 * Parm : p_desc : descriptor to fixup
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int mcp_fixup_descriptor_jupiter(
    mcp_desc*                           p_desc
)
{
    return 0;
}



/*------------------------------------------------------------------
 * Func : mcp_fixup_descriptors
 *
 * Desc : Do Command
 *
 * Parm : p_desc : number of Descriptor to be Execute
 *        n_desc  : number of Descriptor to be Execute
 *
 * Retn : 0
 *------------------------------------------------------------------*/
int mcp_fixup_descriptors(
    mcp_desc*                   p_desc,
    int                         n_desc
)
{
    while(n_desc-- > 0)
        mcp_fixup_descriptor_jupiter(p_desc++);

    return 0;
}


static inline int mcp_copy_descriptor(void *dst, void* src, int len, int is_user_pointer)
{
    if(is_user_pointer) {
        if (copy_from_user(dst, (void __user *)src, len)) {
            mcp_warning("do ioctl command failed - copy desc from user failed\n");
            return -1;
        }
    } else {
        memcpy(dst, src, len);
    }
    return 0;
}

/*------------------------------------------------------------------
 * Func : do_mcp_command
 *
 * Desc : Do Command
 *
 * Parm : p_desc : number of Descriptor to be Execute
 *        n_desc  : number of Descriptor to be Execute
 *        is_user_pointer: p_desc is user point or not
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static int do_mcp_command(mcp_desc* p_desc, int n_desc, int is_user_pointer)
{
    int ret = 0;
    if (n_desc <= 0)
        return 0;

    while(n_desc) {
        int desc_cnt = (n_desc > MCP_DESC_ENTRY_COUNT) ? MCP_DESC_ENTRY_COUNT : n_desc;
        int len      = desc_cnt * sizeof(mcp_desc);

        mutex_lock(&mcp_mutex);

        DSB;
        if(mcp_copy_descriptor(desc_list, p_desc, len, is_user_pointer) != 0) {
            mutex_unlock(&mcp_mutex);
            return -1;
        }
        DSB;
        p_desc += desc_cnt;
        n_desc -= desc_cnt;

        mcp_fixup_descriptors(desc_list, desc_cnt);      // fixup descriptors

        _mcp_set_desc_buffer(desc_list_dma_handle,                          // Base
                             desc_list_dma_handle + len + sizeof(mcp_desc), // Limit
                             desc_list_dma_handle,                          // RP
                             desc_list_dma_handle + len);                   // WP

        wmb();

        DumpDescriptor(desc_list, DisplayDesc, DisplayFIFO);

        ret = _mcp_start_xfer();

        DumpDescriptor(desc_list, 0, DisplayFIFO);

        _mcp_set_desc_buffer(0, 0, 0, 0);

        mutex_unlock(&mcp_mutex);
    }

    return ret;
}


/*------------------------------------------------------------------
 * Func : mcp_do_command
 *
 * Desc : Do Command
 *
 * Parm : p_desc : number of Descriptor to be Execute
 *        n_desc  : number of Descriptor to be Execute
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int mcp_do_command(mcp_desc* p_desc, int n_desc)
{
    return do_mcp_command(p_desc, n_desc, 0);
}



/*------------------------------------------------------------------
 * Func : mcp_do_command
 *
 * Desc : Do Command
 *
 * Parm : p_desc : number of Descriptor to be Execute
 *        n_desc  : number of Descriptor to be Execute
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
int mcp_do_command_user(mcp_desc __user * p_desc, int n_desc)
{
    return do_mcp_command(p_desc, n_desc, 1);
}
/***************************************************************************
               ------------------- APIS ----------------
****************************************************************************/


/********************************************************************************
 AES Hash
 ********************************************************************************/


/*------------------------------------------------------------------
 * Func : MCP_AES_H_HASH_INIT
 *
 * Desc : Init AES Hashing Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_AES_H_HASH_INIT(
    mcp_desc*                       p_desc
)
{
    memset(p_desc, 0, sizeof(mcp_desc));

    p_desc->flags = MCP_MODE(MCP_ALGO_AES_H)
                    | MCP_BCM(MCP_BCM_ECB)
                    | MCP_ENC(1);

    p_desc->iv[0]   = 0x2DC2DF39;
    p_desc->iv[1]   = 0x420321D0;
    p_desc->iv[2]   = 0xCEF1FE23;
    p_desc->iv[3]   = 0x74029D95;
    return 0;
}



/*------------------------------------------------------------------
 * Func : MCP_AES_H_IV_UPDATE
 *
 * Desc : Update Initial Vector of AES Hashing Descriptor
 *
 * Parm : p_desc      : Descriptor to be Load
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_AES_H_IV_UPDATE(
    mcp_desc*                       p_desc,
    unsigned char                   hash[16]
)
{
    p_desc->iv[0]   = (hash[ 0] << 24) + (hash[ 1] << 16) + (hash[ 2] << 8) + hash[ 3];
    p_desc->iv[1]   = (hash[ 4] << 24) + (hash[ 5] << 16) + (hash[ 6] << 8) + hash[ 7];
    p_desc->iv[2]   = (hash[ 8] << 24) + (hash[ 9] << 16) + (hash[10] << 8) + hash[11];
    p_desc->iv[3]   = (hash[12] << 24) + (hash[13] << 16) + (hash[14] << 8) + hash[15];
    return 0;
}




/*------------------------------------------------------------------
 * Func : MCP_AES_H_PADDING
 *
 * Desc : padding tail to the end of the last data block.
 *
 * Parm : p_buff        : data buffer
 *        buff_len      : length of buffer
 *        data_len      : total length of data in byte(from 1st block to
 *                        the last block)
 *
 * Retn : > 0 : number of bytes padded
 *------------------------------------------------------------------*/
int MCP_AES_H_PADDING(
    unsigned char*              p_buff,
    unsigned long               buff_len,
    unsigned long               data_len
)
{
    unsigned long long bit_len = ((unsigned long long) data_len) << 3;
    int pad_sz = 16 - (data_len & 0xF);

    if (pad_sz <= 8)
        pad_sz += 16;

    if (buff_len < pad_sz) {
        mcp_warning("padding AES_H data failed, no enough space left for data padding. pad_sz = %d, remain_sz = %ld\n", pad_sz, buff_len);
        return 0;
    }

    memset(p_buff, 0, pad_sz);

    *p_buff |= 0x80;

    // pad bit length in big endian format
    p_buff += pad_sz - 8;
    *p_buff++ = (bit_len >> 56) & 0xFF;
    *p_buff++ = (bit_len >> 48) & 0xFF;
    *p_buff++ = (bit_len >> 40) & 0xFF;
    *p_buff++ = (bit_len >> 32) & 0xFF;
    *p_buff++ = (bit_len >> 24) & 0xFF;
    *p_buff++ = (bit_len >> 16) & 0xFF;
    *p_buff++ = (bit_len >>  8) & 0xFF;
    *p_buff++ = (bit_len)       & 0xFF;

    return pad_sz;
}




/*------------------------------------------------------------------
 * Func : MCP_AES_H_Hashing
 *
 * Desc : Do AES H Hashing
 *
 * Parm : pDesc      : Descriptor to be Load
 *        DataIn     : Data to be hashing (in Physical Address)
 *        Len        : number of data to be hashing
 *        DataOut    : Physical address that used to store hash value
 *
 * Retn : S_OK  /  S_FALSE
 *------------------------------------------------------------------*/
int MCP_AES_H_Hashing(
    mcp_desc*                   p_desc,
    unsigned char*              p_in,
    unsigned long               len,
    unsigned char*              p_out
)
{
    int ret = 0;

    dma_addr_t addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);

    dma_addr_t addr2 = _mcp_map_single(p_out, 16, DMA_FROM_DEVICE);

    p_desc->data_in  = addr1;

    p_desc->data_out = addr2;

    p_desc->length   = len;

    ret = mcp_do_command(p_desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, 16, DMA_FROM_DEVICE);

    return ret;
}



/*------------------------------------------------------------------
 * Func : MCP_AES_H_DataHash
 *
 * Desc : Compute hash value of Data via 128 bits AES_H_Hasing
 *
 * Parm : pData         : Start address of data
 *        DataLen       : Length of data
 *        Hash[16]      : 128 bits hash value of the file
 *        BlockSize     : Block Size that used to compute Hashing Value
 *        first_block   : 1 : this block is first block
 *                        0 : this block is not first block
 *
 *           if this block is first block, the iv of the descriptor
 *           will be reset to default. if this block is not first block
 *           then uses the hash vaule as the default iv.
 *
 * Retn : S_OK  /  S_FALSE
 *------------------------------------------------------------------*/
int MCP_AES_H_DataHash(
    unsigned char*              p_data,
    unsigned long               data_len,
    unsigned char               hash[16],
    unsigned long               block_size,
    unsigned char               first_block
)
{
    mcp_desc desc;
    int      ret = 0;

    MCP_AES_H_HASH_INIT(&desc);

    if (!first_block)
        MCP_AES_H_IV_UPDATE(&desc, hash);  // Update Hash Value

    while(data_len && !ret) {
        if (data_len > block_size) {
            ret       = MCP_AES_H_Hashing(&desc, p_data, block_size, hash);
            data_len -= block_size;
            p_data   += block_size;
        } else {
            ret       = MCP_AES_H_Hashing(&desc, p_data, data_len, hash);
            p_data   += data_len;
            data_len = 0;
        }

        MCP_AES_H_IV_UPDATE(&desc, hash);  // Update Hash Value
    }

    return ret;
}



/********************************************************************************
 DES
 ********************************************************************************/



/*======================================================================
 * Func : MCP_DES_DESC_INIT
 *
 * Desc : Init DES Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *        EnDe       : Encryption/Descryption
 *              0 for Decryption / 1 for Encryption
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_DES_DESC_INIT(
    mcp_desc*                   pDesc,
    unsigned char               EnDe,
    unsigned char               Mode,
    unsigned char               Key[7],
    unsigned char               IV[8]
)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    pDesc->flags = MCP_MODE(MCP_ALGO_DES) | MCP_BCM(Mode) | MCP_ENC(EnDe);

    if (Key == NULL) {
        pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_OTP);
    } else if((unsigned long)Key <= MCP_MAX_CW_ENTRY) {
        pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
        pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
        pDesc->key[1]  = 0;
        pDesc->key[2]  = 0;
        pDesc->key[3]  = 0;
    } else {
        pDesc->key[0]  = (Key[0] << 16) + (Key[1] << 8) + Key[2];
        pDesc->key[1]  = (Key[3] << 24) + (Key[4] << 16) + (Key[5] << 8) +  Key[6];
    }

    if (IV) {
        pDesc->iv[0]   = (IV[0] << 24) + (IV[1] << 16) + (IV[2] << 8) + IV[3];
        pDesc->iv[1]   = (IV[4] << 24) + (IV[5] << 16) + (IV[6] << 8) + IV[7];
    }

    return 0;
}






/*======================================================================
 * Func : MCP_DES_Decryption
 *
 * Desc : Do DES Decryption
 *
 * Parm : pDesc      : Descriptor to be Load
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_DES_Decryption(
    unsigned char       Mode,
    unsigned char               Key[7],
    unsigned char               IV[8],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_DES_DESC_INIT(&desc, 0, Mode, Key, IV);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0x7;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}




/*======================================================================
 * Func : MCP_DES_Encryption
 *
 * Desc : Do DES Encryption
 *
 * Parm : pDesc      : Descriptor to be Load
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *        DataIn     : Data In
 *        DataOut    : Data Out
 *        Len        : Data Length
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_DES_Encryption(
    unsigned char               Mode,
    unsigned char               Key[7],
    unsigned char               IV[8],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_DES_DESC_INIT(&desc, 1, Mode, Key, IV);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0x7;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}



/********************************************************************************
 TDES
 ********************************************************************************/


/*======================================================================
 * Func : MCP_TDES_DESC_INIT
 *
 * Desc : Init TDES Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *        EnDe       : Encryption/Descryption
 *              0 for Decryption / 1 for Encryption
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_TDES_DESC_INIT(
    mcp_desc*           pDesc,
    unsigned char       EnDe,
    unsigned char       Mode,
    unsigned char       Key[21],
    unsigned char       IV[8]
)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    pDesc->flags = MCP_MODE(MCP_ALGO_3DES) | MCP_BCM(Mode) | MCP_ENC(EnDe);

    if (Key == NULL) {
        pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_OTP);
    } else if((unsigned long)Key <= MCP_MAX_CW_ENTRY) {
        pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
        pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
        pDesc->key[1]  = 0;
        pDesc->key[2]  = 0;
        pDesc->key[3]  = 0;
        pDesc->key[4]  = 0;
        pDesc->key[5]  = 0;
    } else {
        if (EnDe) {
            // Key A
            pDesc->key[0]  = (Key[ 0] << 16) + (Key[ 1] << 8)  + Key[2];
            pDesc->key[1]  = (Key[ 3] << 24) + (Key[ 4] << 16) + (Key[ 5] << 8) +  Key[ 6];

            // Key B
            pDesc->key[2]  = (Key[ 7] << 16) + (Key[ 8] << 8)  + Key[9];
            pDesc->key[3]  = (Key[10] << 24) + (Key[11] << 16) + (Key[12] << 8) +  Key[13];

            // Key C
            pDesc->key[4]  = (Key[14] << 16) + (Key[15] << 8)  + Key[16];
            pDesc->key[5]  = (Key[17] << 24) + (Key[18] << 16) + (Key[19] << 8)  +  Key[20];
        } else {
            // Key C
            pDesc->key[4]  = (Key[ 0] << 16) + (Key[ 1] << 8)  + Key[2];
            pDesc->key[5]  = (Key[ 3] << 24) + (Key[ 4] << 16) + (Key[ 5] << 8) +  Key[ 6];

            // Key B
            pDesc->key[2]  = (Key[ 7] << 16) + (Key[ 8] << 8)  + Key[9];
            pDesc->key[3]  = (Key[10] << 24) + (Key[11] << 16) + (Key[12] << 8) +  Key[13];

            // Key A
            pDesc->key[0]  = (Key[14] << 16) + (Key[15] << 8)  + Key[16];
            pDesc->key[1]  = (Key[17] << 24) + (Key[18] << 16) + (Key[19] << 8)  +  Key[20];
        }
    }

    if (IV) {
        pDesc->iv[0]   = (IV[0] << 24) + (IV[1] << 16) + (IV[2] << 8) + IV[3];
        pDesc->iv[1]   = (IV[4] << 24) + (IV[5] << 16) + (IV[6] << 8) + IV[7];
    }

    return 0;
}




/*======================================================================
 * Func : MCP_TDES_Decryption
 *
 * Desc : Do TDES Decryption
 *
 * Parm : pDesc      : Descriptor to be Load
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_TDES_Decryption(
    unsigned char               Mode,
    unsigned char               Key[21],
    unsigned char               IV[8],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_TDES_DESC_INIT(&desc, 0, Mode, Key, IV);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0x7;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}




/*======================================================================
 * Func : MCP_TDES_Encryption
 *
 * Desc : Do TDES Encryption
 *
 * Parm : pDesc      : Descriptor to be Load
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *        DataIn     : Data In
 *        DataOut    : Data Out
 *        Len        : Data Length
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_TDES_Encryption(
    unsigned char               Mode,
    unsigned char               Key[21],
    unsigned char               IV[8],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_TDES_DESC_INIT(&desc, 1, Mode, Key, IV);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0x7;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}



/********************************************************************************
 AES
 ********************************************************************************/
static void inline LongToByte4(
    unsigned long                       l,
    unsigned char                       b[4]
)
{
    b[0] = (l >> 24) & 0xFF;
    b[1] = (l >> 16) & 0xFF;
    b[2] = (l >> 8)  & 0xFF;
    b[3] =  l        & 0xFF;
}
/*======================================================================
 * Func : MCP_AES_PeekIV
 *
 * Desc : Do AES PeekIV
 *
 * Parm : iv         : Initial Vector
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_PeekIV(
    unsigned char           IV[16]
)
{
    LongToByte4(GET_MCP_AES_INI_KEY0(), (unsigned char*) &IV[0]);
    LongToByte4(GET_MCP_AES_INI_KEY1(), (unsigned char*) &IV[4]);
    LongToByte4(GET_MCP_AES_INI_KEY2(), (unsigned char*) &IV[8]);
    LongToByte4(GET_MCP_AES_INI_KEY3(), (unsigned char*) &IV[12]);
    return 0;
}


/*======================================================================
 * Func : MCP_AES_DESC_INIT
 *
 * Desc : Init AES Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *        EnDe       : Encryption/Descryption
 *              0 for Decryption / 1 for Encryption
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_AES_DESC_INIT(
    mcp_desc*                   pDesc,
    unsigned char               EnDe,
    unsigned char               Mode,
    unsigned char               Key[16],
    unsigned char               IV[16]
)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    switch (Mode) {

        case MCP_BCM_ECB:
        case MCP_BCM_CBC:
        case MCP_BCM_CTR:

            pDesc->flags = MCP_MODE(MCP_ALGO_AES) | MCP_BCM(Mode) | MCP_ENC(EnDe);

            if (Key == NULL) {
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_OTP);
            } else if((unsigned long)Key <= MCP_MAX_CW_ENTRY) {
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
                pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
            } else {
                pDesc->key[0]  = (Key[ 0] << 24) + (Key[ 1] << 16) + (Key[ 2] << 8) + Key[ 3];
                pDesc->key[1]  = (Key[ 4] << 24) + (Key[ 5] << 16) + (Key[ 6] << 8) + Key[ 7];
                pDesc->key[2]  = (Key[ 8] << 24) + (Key[ 9] << 16) + (Key[10] << 8) + Key[11];
                pDesc->key[3]  = (Key[12] << 24) + (Key[13] << 16) + (Key[14] << 8) + Key[15];
            }

            if (IV) {
                pDesc->iv[0]   = (IV[ 0] << 24) + (IV[ 1] << 16) + (IV[ 2] << 8) + IV[ 3];
                pDesc->iv[1]   = (IV[ 4] << 24) + (IV[ 5] << 16) + (IV[ 6] << 8) + IV[ 7];
                pDesc->iv[2]   = (IV[ 8] << 24) + (IV[ 9] << 16) + (IV[10] << 8) + IV[11];
                pDesc->iv[3]   = (IV[12] << 24) + (IV[13] << 16) + (IV[14] << 8) + IV[15];
            } else
                pDesc->flags |= MCP_IV_SEL(MCP_IV_SEL_REG);

            return 0;

        default:
            mcp_warning("Init AES descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}





/*======================================================================
 * Func : MCP_AES_Decryption
 *
 * Desc : Do AES Decryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_Decryption(
    unsigned char       Mode,
    unsigned char               Key[16],
    unsigned char               IV[16],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret = -1;
    dma_addr_t addr1;
    dma_addr_t addr2;
    unsigned int cur_pos = 0;
    unsigned char cur_iv_key[16];
    unsigned char last_iv_key[16];

    switch(Mode) {
        case MCP_BCM_CBC:

            while(cur_pos < len) {
                if((len - cur_pos ) > MAX_CP_EN_DE_SEGMENT_SIZE) { // for len of image more than 16M
                    unsigned char *plast_raw_iv = p_in + cur_pos + MAX_CP_EN_DE_SEGMENT_SIZE - 16;
                    memcpy(last_iv_key, plast_raw_iv, 16);
                    if(cur_pos == 0) {
                        MCP_AES_DESC_INIT(&desc, 0, Mode, Key, IV);
                    } else {
                        MCP_AES_DESC_INIT(&desc, 0, Mode, Key, cur_iv_key);
                    }

                    addr1 = _mcp_map_single(p_in + cur_pos, MAX_CP_EN_DE_SEGMENT_SIZE, DMA_TO_DEVICE);
                    addr2 = _mcp_map_single(p_out + cur_pos, MAX_CP_EN_DE_SEGMENT_SIZE, DMA_FROM_DEVICE);

                    desc.data_in  = addr1;
                    desc.data_out = addr2;
                    desc.length   = MAX_CP_EN_DE_SEGMENT_SIZE & ~0xF;

                    ret = mcp_do_command(&desc, 1);

                    _mcp_unmap_single(addr1, MAX_CP_EN_DE_SEGMENT_SIZE, DMA_TO_DEVICE);
                    _mcp_unmap_single(addr2, MAX_CP_EN_DE_SEGMENT_SIZE, DMA_FROM_DEVICE);

                    if (ret != 0)
                        break;
                    cur_pos += MAX_CP_EN_DE_SEGMENT_SIZE;
                    memcpy(cur_iv_key, last_iv_key, 16);
                } else {
                    if(cur_pos == 0) {
                        MCP_AES_DESC_INIT(&desc, 0, Mode, Key, IV);
                    } else {
                        MCP_AES_DESC_INIT(&desc, 0, Mode, Key, cur_iv_key);
                    }

                    addr1 = _mcp_map_single(p_in + cur_pos, len - cur_pos, DMA_TO_DEVICE);
                    addr2 = _mcp_map_single(p_out + cur_pos, len - cur_pos, DMA_FROM_DEVICE);

                    desc.data_in  = addr1;
                    desc.data_out = addr2;
                    desc.length   = (len - cur_pos) & ~0xF;

                    ret = mcp_do_command(&desc, 1);

                    _mcp_unmap_single(addr1, len - cur_pos, DMA_TO_DEVICE);
                    _mcp_unmap_single(addr2, len - cur_pos, DMA_FROM_DEVICE);

                    if (ret != 0)
                        break;
                    cur_pos = len;
                }
            }
            return ret;

        case MCP_BCM_ECB:
        case MCP_BCM_CTR:


            MCP_AES_DESC_INIT(&desc, 0, Mode, Key, IV);

            addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
            addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

            desc.data_in  = addr1;
            desc.data_out = addr2;
            desc.length   = len & ~0xF;

            ret = mcp_do_command(&desc, 1);

            _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
            _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

            return ret;

        default:

            mcp_warning("Init AES descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}




/*======================================================================
 * Func : MCP_AES_Encryption
 *
 * Desc : Do AES Encryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_Encryption(
    unsigned char               mode,
    unsigned char               key[16],
    unsigned char               iv[16],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_AES_DESC_INIT(&desc, 1, mode, key, iv);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}

/********************************************************************************
 AES-192
 ********************************************************************************/


/*======================================================================
 * Func : MCP_AES_192_DESC_INIT
 *
 * Desc : Init AES_192 Descriptor
 *
 * Parm : pDesc        : Descriptor to be Load
 *        EnDe         : Encryption/Descryption
 *                       0 for Decryption / 1 for Encryption
 *        Mode         : Operation Mode (ECB, CBC and CTR mode)
 *        Key          : Key Value
 *        IV           : Initial Vector
 *        key_buff_phy : physical address of DDR stored key
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_AES_192_DESC_INIT(
    mcp_desc*               pDesc,
    unsigned char           EnDe,
    unsigned char           Mode,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned long           key_buff_phy)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    switch (Mode) {
        case MCP_BCM_ECB:
        case MCP_BCM_CBC:
        case MCP_BCM_CTR:

            pDesc->flags = MCP_MODE(MCP_ALGO_AES_192) | MCP_BCM(Mode) | MCP_ENC(EnDe);

            /* for aes 192, DDR or CW only */
            if(Key == NULL || (unsigned long)Key <= MCP_MAX_CW_ENTRY) {
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
                pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            } else { /* DDR */
                pDesc->flags |= MCP_KEY_SEL(0xFF);
                pDesc->key[0]  = key_buff_phy;
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            }

            if (IV && Mode != MCP_BCM_ECB) { /* IV for AES 192, only CBC and CTR */
                pDesc->iv[0]   = (IV[ 0] << 24) + (IV[ 1] << 16) + (IV[ 2] << 8) + IV[ 3];
                pDesc->iv[1]   = (IV[ 4] << 24) + (IV[ 5] << 16) + (IV[ 6] << 8) + IV[ 7];
                pDesc->iv[2]   = (IV[ 8] << 24) + (IV[ 9] << 16) + (IV[10] << 8) + IV[11];
                pDesc->iv[3]   = (IV[12] << 24) + (IV[13] << 16) + (IV[14] << 8) + IV[15];
            } else {
                pDesc->flags |= MCP_IV_SEL(MCP_IV_SEL_REG);
            }

            return 0;

        default:
            mcp_warning("Init AES descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}

/*======================================================================
 * Func : MCP_AES_192_Decryption
 *
 * Desc : Do AES_192 Decryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_192_Decryption(
    unsigned char           Mode,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int                 ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 24, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("AES 192 Decryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 24);
    if(Key != NULL) {
        memcpy (key_buff, Key, 24);
    } else {
        mcp_warning("AES 192 Decryption failed - invalid key (null)\n");
        return ret;
    }

    MCP_AES_192_DESC_INIT(&desc, 0, Mode, Key, IV, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 24, key_buff, key_buff_phy);

    return ret;
}



/*======================================================================
 * Func : MCP_AES_192_Encryption
 *
 * Desc : Do AES_192 Encryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_192_Encryption(
    unsigned char           mode,
    unsigned char           key[24],
    unsigned char           iv[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int                 ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 24, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("AES 192 Encryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 24);
    if(key != NULL) {
        memcpy (key_buff, key, 24);
    } else {
        mcp_warning("AES 192 Encryption failed - invalid key (null)\n");
        return ret;
    }
    // mcp_dump_data_with_text(key_buff, 24, "key_buff :");
    // mcp_dump_data_with_text(key, 24, "key :");
    MCP_AES_192_DESC_INIT(&desc, 1, mode, key, iv, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 24, key_buff, key_buff_phy);

    return ret;
}


/********************************************************************************
 AES-256
 ********************************************************************************/


/*======================================================================
 * Func : MCP_AES_256_DESC_INIT
 *
 * Desc : Init AES_256 Descriptor
 *
 * Parm : pDesc        : Descriptor to be Load
 *        EnDe         : Encryption/Descryption
 *                       0 for Decryption / 1 for Encryption
 *        Mode         : Operation Mode (ECB, CBC and CTR mode)
 *        Key          : Key Value
 *        IV           : Initial Vector
 *        key_buff_phy : physical address of DDR stored key
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_AES_256_DESC_INIT(
    mcp_desc*               pDesc,
    unsigned char           EnDe,
    unsigned char           Mode,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned long           key_buff_phy)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    switch (Mode) {
        case MCP_BCM_ECB:
        case MCP_BCM_CBC:
        case MCP_BCM_CTR:

            pDesc->flags = MCP_MODE(MCP_ALGO_AES_256) | MCP_BCM(Mode) | MCP_ENC(EnDe);

            /* for aes 256, DDR or CW only */
            if(Key == NULL || (unsigned long)Key <= MCP_MAX_CW_ENTRY) {
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
                pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            } else {/* DDR */
                pDesc->flags |= MCP_KEY_SEL(0xFF);
                pDesc->key[0]  = key_buff_phy;
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            }

            if (IV && Mode != MCP_BCM_ECB) {/* IV for AES 256, only CBC and CTR */
                pDesc->iv[0]   = (IV[ 0] << 24) + (IV[ 1] << 16) + (IV[ 2] << 8) + IV[ 3];
                pDesc->iv[1]   = (IV[ 4] << 24) + (IV[ 5] << 16) + (IV[ 6] << 8) + IV[ 7];
                pDesc->iv[2]   = (IV[ 8] << 24) + (IV[ 9] << 16) + (IV[10] << 8) + IV[11];
                pDesc->iv[3]   = (IV[12] << 24) + (IV[13] << 16) + (IV[14] << 8) + IV[15];
            } else {
                pDesc->flags |= MCP_IV_SEL(MCP_IV_SEL_REG);
            }

            return 0;

        default:
            mcp_warning("Init AES descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}

/*======================================================================
 * Func : MCP_AES_256_Decryption
 *
 * Desc : Do AES_256 Decryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_256_Decryption(
    unsigned char           Mode,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int                 ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 32, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("AES 256 Decryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 32);
    if(Key != NULL) {
        memcpy (key_buff, Key, 32);
    } else {
        mcp_warning("AES 256 Decryption failed - invalid key (null)\n");
        return ret;
    }

    MCP_AES_256_DESC_INIT(&desc, 0, Mode, Key, IV, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 32, key_buff, key_buff_phy);

    return ret;
}



/*======================================================================
 * Func : MCP_AES_256_Encryption
 *
 * Desc : Do AES_256 Encryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_AES_256_Encryption(
    unsigned char           mode,
    unsigned char           key[32],
    unsigned char           iv[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int                 ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 32, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("AES 256 Encryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 32);
    if(key != NULL) {
        memcpy (key_buff, key, 32);
    } else {
        mcp_warning("AES 256 Encryption failed - invalid key (null)\n");
        return ret;
    }

    // mcp_dump_data_with_text(key_buff, 32, "key_buff :");
    // mcp_dump_data_with_text(key, 32, "key :");
    MCP_AES_256_DESC_INIT(&desc, 1, mode, key, iv, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 32, key_buff, key_buff_phy);

    return ret;
}


#ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA

/********************************************************************************
 CAMELLIA
 ********************************************************************************/


/*======================================================================
 * Func : MCP_CAM_DESC_INIT
 *
 * Desc : Init CAM Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *        EnDe       : Encryption/Descryption
 *              0 for Decryption / 1 for Encryption
 *        Mode       : Operation Mode
 *        Key        : Key Value
 *        IV         : Initial Vector
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_CAM_DESC_INIT(
    mcp_desc*                   pDesc,
    unsigned char               EnDe,
    unsigned char               Mode,
    unsigned char               Key[16],
    unsigned char               IV[16]
)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    switch (Mode) {
        case MCP_BCM_ECB:
        case MCP_BCM_CBC:
        case MCP_BCM_CTR:

            pDesc->flags = MCP_MODE(MCP_ALGO_CAM) | MCP_BCM(Mode) | MCP_ENC(EnDe);

            if (Key == NULL) {
#ifndef CONFIG_ARCH_RTK293x
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_OTP);
#else
                mcp_warning("MCP_CAMELLIA_DESC_INIT failed, Key value is NULL! \n" );
                return -1;
#endif
            } else if((unsigned long)Key <= MCP_MAX_CW_ENTRY) {
                pDesc->flags  |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
                pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
            } else {
                pDesc->key[0]  = (Key[ 0] << 24) + (Key[ 1] << 16) + (Key[ 2] << 8) + Key[ 3];
                pDesc->key[1]  = (Key[ 4] << 24) + (Key[ 5] << 16) + (Key[ 6] << 8) + Key[ 7];
                pDesc->key[2]  = (Key[ 8] << 24) + (Key[ 9] << 16) + (Key[10] << 8) + Key[11];
                pDesc->key[3]  = (Key[12] << 24) + (Key[13] << 16) + (Key[14] << 8) + Key[15];
            }

            if (IV) {
                pDesc->iv[0]   = (IV[ 0] << 24) + (IV[ 1] << 16) + (IV[ 2] << 8) + IV[ 3];
                pDesc->iv[1]   = (IV[ 4] << 24) + (IV[ 5] << 16) + (IV[ 6] << 8) + IV[ 7];
                pDesc->iv[2]   = (IV[ 8] << 24) + (IV[ 9] << 16) + (IV[10] << 8) + IV[11];
                pDesc->iv[3]   = (IV[12] << 24) + (IV[13] << 16) + (IV[14] << 8) + IV[15];
            } else {
                pDesc->flags |= MCP_IV_SEL(MCP_IV_SEL_REG);
            }

            return 0;

        default:
            mcp_warning("Init CAMELLIA descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}





/*======================================================================
 * Func : MCP_CAM_Decryption
 *
 * Desc : Do CAM Decryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_CAM_Decryption(
    unsigned char           Mode,
    unsigned char               Key[16],
    unsigned char               IV[16],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_CAM_DESC_INIT(&desc, 0, Mode, Key, IV);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}




/*======================================================================
 * Func : MCP_CAM_Encryption
 *
 * Desc : Do CAM Encryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_CAM_Encryption(
    unsigned char               mode,
    unsigned char               key[16],
    unsigned char               iv[16],
    unsigned char*              p_in,
    unsigned char*              p_out,
    unsigned long               len
)
{
    mcp_desc desc;
    int ret;
    dma_addr_t addr1;
    dma_addr_t addr2;

    MCP_CAM_DESC_INIT(&desc, 1, mode, key, iv);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;
    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);

    return ret;
}

/********************************************************************************
 Camellia-192
 ********************************************************************************/


/*======================================================================
 * Func : MCP_CAM_192_DESC_INIT
 *
 * Desc : Init CAM_192 Descriptor
 *
 * Parm : pDesc        : Descriptor to be Load
 *        EnDe         : Encryption/Descryption
 *                       0 for Decryption / 1 for Encryption
 *        Mode         : Operation Mode (ECB, CBC and CTR mode)
 *        Key          : Key Value
 *        IV           : Initial Vector
 *        key_buff_phy : physical address of DDR stored key
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_CAM_192_DESC_INIT(
    mcp_desc*               pDesc,
    unsigned char           EnDe,
    unsigned char           Mode,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned long           key_buff_phy)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    switch (Mode) {
        case MCP_BCM_ECB:
        case MCP_BCM_CBC:
        case MCP_BCM_CTR:

            pDesc->flags = MCP_MODE(MCP_ALGO_CAM_192) | MCP_BCM(Mode) | MCP_ENC(EnDe);

            /* for cam 192, DDR or CW only */
            if(Key == NULL || (unsigned long)Key <= MCP_MAX_CW_ENTRY) {
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
                pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            } else {/* DDR */
                pDesc->flags |= MCP_KEY_SEL(0xFF);
                pDesc->key[0]  = key_buff_phy;
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            }

            if (IV && Mode != MCP_BCM_ECB) {/* IV for CAM 192, only CBC and CTR */
                pDesc->iv[0]   = (IV[ 0] << 24) + (IV[ 1] << 16) + (IV[ 2] << 8) + IV[ 3];
                pDesc->iv[1]   = (IV[ 4] << 24) + (IV[ 5] << 16) + (IV[ 6] << 8) + IV[ 7];
                pDesc->iv[2]   = (IV[ 8] << 24) + (IV[ 9] << 16) + (IV[10] << 8) + IV[11];
                pDesc->iv[3]   = (IV[12] << 24) + (IV[13] << 16) + (IV[14] << 8) + IV[15];
            } else {
                pDesc->flags |= MCP_IV_SEL(MCP_IV_SEL_REG);
            }

            return 0;

        default:
            mcp_warning("Init Camellia descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}

/*======================================================================
 * Func : MCP_CAM_192_Decryption
 *
 * Desc : Do CAM_192 Decryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_CAM_192_Decryption(
    unsigned char           Mode,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 24, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("Camellia 192 Decryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 24);
    if(Key != NULL) {
        memcpy (key_buff, Key, 24);
    } else {
        mcp_warning("Camellia 192 Decryption failed - invalid key (null)\n");
        return ret;
    }

    MCP_CAM_192_DESC_INIT(&desc, 0, Mode, Key, IV, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 24, key_buff, key_buff_phy);

    return ret;
}



/*======================================================================
 * Func : MCP_CAM_192_Encryption
 *
 * Desc : Do CAM_192 Encryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_CAM_192_Encryption(
    unsigned char           mode,
    unsigned char           key[24],
    unsigned char           iv[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int                 ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 24, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("Camellia 192 Encryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 24);
    if(key != NULL) {
        memcpy (key_buff, key, 24);
    } else {
        mcp_warning("Camellia 192 Encryption failed - invalid key (null)\n");
        return ret;
    }
    // mcp_dump_data_with_text(key_buff, 24, "key_buff :");
    // mcp_dump_data_with_text(key, 24, "key :");
    MCP_CAM_192_DESC_INIT(&desc, 1, mode, key, iv, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 24, key_buff, key_buff_phy);

    return ret;
}


/********************************************************************************
 Camellia-256
 ********************************************************************************/


/*======================================================================
 * Func : MCP_CAM_256_DESC_INIT
 *
 * Desc : Init CAM_256 Descriptor
 *
 * Parm : pDesc        : Descriptor to be Load
 *        EnDe         : Encryption/Descryption
 *                       0 for Decryption / 1 for Encryption
 *        Mode         : Operation Mode (ECB, CBC and CTR mode)
 *        Key          : Key Value
 *        IV           : Initial Vector
 *        key_buff_phy : physical address of DDR stored key
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int MCP_CAM_256_DESC_INIT(
    mcp_desc*               pDesc,
    unsigned char           EnDe,
    unsigned char           Mode,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned long           key_buff_phy)
{
    memset(pDesc, 0, sizeof(mcp_desc));

    switch (Mode) {
        case MCP_BCM_ECB:
        case MCP_BCM_CBC:
        case MCP_BCM_CTR:

            pDesc->flags = MCP_MODE(MCP_ALGO_CAM_256) | MCP_BCM(Mode) | MCP_ENC(EnDe);

            /* for cam 256, DDR or CW only */
            if(Key == NULL || (unsigned long)Key <= MCP_MAX_CW_ENTRY) {
                pDesc->flags |= MCP_KEY_SEL(MCP_KEY_SEL_CW);
                pDesc->key[0]  = MCP_CW_KEY((unsigned long)(Key - 1));
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            } else {/* DDR */
                pDesc->flags |= MCP_KEY_SEL(0xFF);
                pDesc->key[0]  = key_buff_phy;
                pDesc->key[1]  = 0;
                pDesc->key[2]  = 0;
                pDesc->key[3]  = 0;
                pDesc->key[4]  = 0;
                pDesc->key[5]  = 0;
            }

            if (IV && Mode != MCP_BCM_ECB) {/* IV for CAM 256, only CBC and CTR */
                pDesc->iv[0]   = (IV[ 0] << 24) + (IV[ 1] << 16) + (IV[ 2] << 8) + IV[ 3];
                pDesc->iv[1]   = (IV[ 4] << 24) + (IV[ 5] << 16) + (IV[ 6] << 8) + IV[ 7];
                pDesc->iv[2]   = (IV[ 8] << 24) + (IV[ 9] << 16) + (IV[10] << 8) + IV[11];
                pDesc->iv[3]   = (IV[12] << 24) + (IV[13] << 16) + (IV[14] << 8) + IV[15];
            } else {
                pDesc->flags |= MCP_IV_SEL(MCP_IV_SEL_REG);
            }

            return 0;

        default:
            mcp_warning("Init Camellia descriptor failed - invalid mode (%d)\n", Mode);
            return -1;
    }
}

/*======================================================================
 * Func : MCP_CAMS_256_Decryption
 *
 * Desc : Do CAM_256 Decryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_CAM_256_Decryption(
    unsigned char           Mode,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 32, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("Camellia 256 Decryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 32);
    if(Key != NULL) {
        memcpy (key_buff, Key, 32);
    } else {
        mcp_warning("Camellia 256 Decryption failed - invalid key (null)\n");
        return ret;
    }

    MCP_CAM_256_DESC_INIT(&desc, 0, Mode, Key, IV, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 32, key_buff, key_buff_phy);

    return ret;
}



/*======================================================================
 * Func : MCP_CAM_256_Encryption
 *
 * Desc : Do CAM_256 Encryption
 *
 * Parm : mode       : Operation Mode
 *        key        : Key Value
 *        iv         : Initial Vector
 *        p_in       : Data In
 *        p_out      : Data Out
 *        len        : Data Length
 *
 * Retn : 0 for success, others failed
 *======================================================================*/
int MCP_CAM_256_Encryption(
    unsigned char           mode,
    unsigned char           key[32],
    unsigned char           iv[16],
    unsigned char*          p_in,
    unsigned char*          p_out,
    unsigned long           len
)
{
    mcp_desc            desc;
    unsigned char*      key_buff;
    int                 ret = -1;
    dma_addr_t          addr1;
    dma_addr_t          addr2;
    dma_addr_t          key_buff_phy;

    key_buff = dma_alloc_coherent(NULL, 32, &key_buff_phy, GFP_KERNEL);
    if(!key_buff) {
        mcp_warning("Camellia 256 Encryption failed - dma_alloc_coherent fail\n");
        return ret;
    }
    memset (key_buff, 0, 32);
    if(key != NULL) {
        memcpy (key_buff, key, 32);
    } else {
        mcp_warning("Camellia 256 Encryption failed - invalid key (null)\n");
        return ret;
    }

    // mcp_dump_data_with_text(key_buff, 32, "key_buff :");
    // mcp_dump_data_with_text(key, 32, "key :");
    MCP_CAM_256_DESC_INIT(&desc, 1, mode, key, iv, key_buff_phy);

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);
    addr2 = _mcp_map_single(p_out, len, DMA_FROM_DEVICE);

    desc.data_in  = addr1;
    desc.data_out = addr2;

    desc.length   = len & ~0xF;

    ret = mcp_do_command(&desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);
    _mcp_unmap_single(addr2, len, DMA_FROM_DEVICE);
    dma_free_coherent(NULL, 32, key_buff, key_buff_phy);

    return ret;
}

#endif

/********************************************************************************
 SHA-1 Hash
 ********************************************************************************/


/*------------------------------------------------------------------
 * Func : MCP_SHA1_HASH_INIT
 *
 * Desc : Init SHA1 Hashing Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_SHA1_HASH_INIT(
    mcp_desc*                       p_desc
)
{
    memset(p_desc, 0, sizeof(mcp_desc));

    p_desc->flags = MCP_MODE(MCP_ALGO_SHA_1) | MCP_ENC(1);

    //------------------------------------------------------------
    // set up the initial value of SHA1
    //
    //   for mars
    //      the initial value is hardware implemented,
    //      no extra initial value setting is necessary.
    //
    //   for jupiter
    //      use the key[0:4] to specified the initial value
    //-----------------------------------------------------------
    p_desc->key[0] = 0x67452301;
    p_desc->key[1] = 0xEFCDAB89;
    p_desc->key[2] = 0x98BADCFE;
    p_desc->key[3] = 0x10325476;
    p_desc->key[4] = 0xC3D2E1F0;

    return 0;
}





/*------------------------------------------------------------------
 * Func : MCP_SHA1_IV_UPDATE
 *
 * Desc : Update Initial Vector of SHA1 Hashing Descriptor
 *
 * Parm : p_desc      : Descriptor to be Load
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_SHA1_IV_UPDATE(
    mcp_desc*                       p_desc,
    unsigned char                   hash[SHA1_DIGEST_SIZE])
{
    p_desc->key[0]   = (hash[ 0] << 24) + (hash[ 1] << 16) + (hash[ 2] << 8) + hash[ 3];
    p_desc->key[1]   = (hash[ 4] << 24) + (hash[ 5] << 16) + (hash[ 6] << 8) + hash[ 7];
    p_desc->key[2]   = (hash[ 8] << 24) + (hash[ 9] << 16) + (hash[10] << 8) + hash[11];
    p_desc->key[3]   = (hash[12] << 24) + (hash[13] << 16) + (hash[14] << 8) + hash[15];
    p_desc->key[4]   = (hash[16] << 24) + (hash[17] << 16) + (hash[18] << 8) + hash[19];
    return 0;
}




/*------------------------------------------------------------------
 * Func : MCP_SHA1_PADDING
 *
 * Desc : padding tail to the end of the last data block.
 *
 * Parm : mcpb          : mcp buffer
 *        data_len      : total length of data in byte(from 1st block to
 *                        the last block)
 *
 * Retn : > 0 : number of bytes padded
 *------------------------------------------------------------------*/
int MCP_SHA1_PADDING(
    unsigned char*              p_buff,
    unsigned long               buff_len,
    unsigned long               data_len
)
{
    unsigned long long bit_len = ((unsigned long long) data_len) << 3;
    int pad_sz = 64 - (data_len & SHA1_ALIGNMENT_CHECK);

    if (pad_sz <= 8)
        pad_sz += 64;

    if (buff_len < pad_sz) {
        mcp_warning("padding SHA1 data failed, no enough space left for data padding. pad_sz = %d, remain_sz = %ld\n", pad_sz, buff_len);
        return -1;
    }

    memset(p_buff, 0, pad_sz);

    *p_buff |= 0x80;

    // pad bit length in big endian format
    p_buff   += pad_sz - 8;
    *p_buff++ = (bit_len >> 56) & 0xFF;
    *p_buff++ = (bit_len >> 48) & 0xFF;
    *p_buff++ = (bit_len >> 40) & 0xFF;
    *p_buff++ = (bit_len >> 32) & 0xFF;
    *p_buff++ = (bit_len >> 24) & 0xFF;
    *p_buff++ = (bit_len >> 16) & 0xFF;
    *p_buff++ = (bit_len >>  8) & 0xFF;
    *p_buff++ = (bit_len)       & 0xFF;

    return pad_sz;
}



/*------------------------------------------------------------------
 * Func : MCP_SHA1_Hashing
 *
 * Desc : Do SHA1 Hashing
 *
 * Parm : pDesc      : Descriptor to be Load
 *        DataIn     : Data to be hashing (in Physical Address)
 *        Len        : number of data to be hashing
 *                     (for SHA1, it should be multiple of 64)
 *        DataOut    : Physical address that used to store hash value
 *                     (for SHA1, it should be 20 bytes)
 *
 * Retn : S_OK  /  S_FALSE
 *------------------------------------------------------------------*/
int MCP_SHA1_Hashing(
    mcp_desc*                   p_desc,
    unsigned char*              p_in,
    unsigned long               len,
    unsigned char*              p_out
)
{
    dma_addr_t addr1;
    dma_addr_t addr2;
    int ret = 0;

    if (len & SHA1_ALIGNMENT_CHECK) {
        mcp_warning("input data length (%lu) of SHA_1 should be multiple of 64 bytes\n", len);
        return -1;
    }

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);

    addr2 = _mcp_map_single(p_out, SHA1_DIGEST_SIZE, DMA_FROM_DEVICE);

    p_desc->data_in  = addr1;

    p_desc->data_out = addr2;

    p_desc->length   = len;

    ret = mcp_do_command(p_desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, SHA1_DIGEST_SIZE, DMA_FROM_DEVICE);

    return ret;
}




/*------------------------------------------------------------------
 * Func : MCP_SHA1_DataHash
 *
 * Desc : Compute hash value of Data via 128 bits SHA1
 *
 * Parm : p_data        : Start address of data
 *        data_len      : Length of data
 *        hash          : 20 Bytes (160 bits) hash value of the file
 *        block_size    : Block Size that used to compute Hashing Value
 *                        for SHA1, it should be multiple of 64 bytes.
 *        block_status  : b7 : this block is the first  block
 *                        b3 : this block is the latest block
 *
 *           if this block is first block, the iv of the descriptor
 *           will be reset to default. if this block is not first block
 *           then uses the hash vaule as the default iv.
 *
 * Retn : S_OK  /  S_FALSE
 *------------------------------------------------------------------*/
int MCP_SHA1_DataHash(
    unsigned char*          p_data,
    unsigned long           data_len,
    unsigned char           hash[SHA1_DIGEST_SIZE],
    unsigned long           block_size,
    unsigned char           block_status
)
{
    mcp_desc desc;
    int ret = 0;

    MCP_SHA1_HASH_INIT(&desc);

    // to simplify the implementation, we have made some constrains over here
    // 1) the data_len must be multiple if 64 Bytes
    // 2) the block size must be multiple if 64 Bytes
    // 3) the data_len must be multiple if block size excepts the last block
    if (data_len & SHA1_ALIGNMENT_CHECK) {
        mcp_warning("compute SHA1 hash value failed - data_len (%lu) should be multiple of 64 bytes\n", data_len);
        return -1;
    }

    if (block_size & SHA1_ALIGNMENT_CHECK) {
        mcp_warning("compute SHA1 hash value failed - block size (%lu) should be multiple of 64 bytes\n", block_size);
        return -1;
    }

    if (!(block_status & LAST_BLOCK) && (data_len % block_size)) {
        mcp_warning("compute SHA1 hash value failed - data_len (%lu) should be multiple of block size (%lu) excepts the last block\n", data_len, block_size);
        return -1;
    }

    //--------------
    if (!(block_status & FIRST_BLOCK))
        MCP_SHA1_IV_UPDATE(&desc, hash);    // Setup the initial value of SHA1 Hash Value

    while(data_len && !ret) {
        if (data_len > block_size) {
            ret       = MCP_SHA1_Hashing(&desc, p_data, block_size, hash);
            data_len -= block_size;
            p_data   += block_size;
        } else {
            ret       = MCP_SHA1_Hashing(&desc, p_data, data_len, hash);
            p_data   += data_len;
            data_len = 0;
        }

        MCP_SHA1_IV_UPDATE(&desc, hash);  // Update Hash Value
    }

    return ret;
}


#ifdef CONFIG_RTK_KDRV_MCP_SHA256


/********************************************************************************
 SHA-256 Hash
 ********************************************************************************/


/*------------------------------------------------------------------
 * Func : MCP_SHA256_HASH_INIT
 *
 * Desc : Init SHA256 Hashing Descriptor
 *
 * Parm : pDesc      : Descriptor to be Load
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_SHA256_HASH_INIT(mcp_desc* p_desc)
{
    memset(p_desc, 0, sizeof(mcp_desc));

    p_desc->flags = MCP_MODE(MCP_ALGO_SHA256) | MCP_ENC(1);

    //------------------------------------------------------------
    // set up the initial value of SHA256
    //
    //    use the key[0:5] + iv[0:1] to specified the initial value
    //-----------------------------------------------------------
    p_desc->key[0] = 0x6a09e667;
    p_desc->key[1] = 0xbb67ae85;
    p_desc->key[2] = 0x3c6ef372;
    p_desc->key[3] = 0xa54ff53a;
    p_desc->key[4] = 0x510e527f;
    p_desc->key[5] = 0x9b05688c;
    p_desc->iv[0]  = 0x1f83d9ab;
    p_desc->iv[1]  = 0x5be0cd19;
    return 0;
}



/*------------------------------------------------------------------
 * Func : MCP_SHA256_IV_UPDATE
 *
 * Desc : Update Initial Vector of SHA256 Hashing Descriptor
 *
 * Parm : p_desc      : Descriptor to be Load
 *
 * Retn : 0 for success, others failed
 *------------------------------------------------------------------*/
int MCP_SHA256_IV_UPDATE(mcp_desc* p_desc, unsigned char hash[SHA256_DIGEST_SIZE])
{
    p_desc->key[0] = (hash[ 0] << 24) + (hash[ 1] << 16) + (hash[ 2] << 8) + hash[ 3];
    p_desc->key[1] = (hash[ 4] << 24) + (hash[ 5] << 16) + (hash[ 6] << 8) + hash[ 7];
    p_desc->key[2] = (hash[ 8] << 24) + (hash[ 9] << 16) + (hash[10] << 8) + hash[11];
    p_desc->key[3] = (hash[12] << 24) + (hash[13] << 16) + (hash[14] << 8) + hash[15];
    p_desc->key[4] = (hash[16] << 24) + (hash[17] << 16) + (hash[18] << 8) + hash[19];
    p_desc->key[5] = (hash[20] << 24) + (hash[21] << 16) + (hash[22] << 8) + hash[23];
    p_desc->iv[0]  = (hash[24] << 24) + (hash[25] << 16) + (hash[26] << 8) + hash[27];
    p_desc->iv[1]  = (hash[28] << 24) + (hash[29] << 16) + (hash[30] << 8) + hash[31];
    return 0;
}


/*------------------------------------------------------------------
 * Func : MCP_SHA256_PADDING
 *
 * Desc : padding tail to the end of the last data block.
 *
 * Parm : mcpb          : mcp buffer
 *        data_len      : total length of data in byte(from 1st block to
 *                        the last block)
 *
 * Retn : > 0 : number of bytes padded
 *------------------------------------------------------------------*/
int MCP_SHA256_PADDING(
    unsigned char*          p_buff,
    unsigned long           buff_len,
    unsigned long           data_len
)
{
    unsigned long long bit_len = ((unsigned long long) data_len) << 3;
    int pad_sz = 64 - (data_len & SHA256_ALIGNMENT_CHECK);

    if (pad_sz <= 8)
        pad_sz += 64;

    if (buff_len < pad_sz) {
        mcp_warning("padding SHA1 data failed, no enough space left for data padding. pad_sz = %d, remain_sz = %ld\n", pad_sz, buff_len);
        return -1;
    }

    memset(p_buff, 0, pad_sz);

    *p_buff |= 0x80;

    // pad bit length in big endian format
    p_buff   += pad_sz - 8;
    *p_buff++ = (bit_len >> 56) & 0xFF;
    *p_buff++ = (bit_len >> 48) & 0xFF;
    *p_buff++ = (bit_len >> 40) & 0xFF;
    *p_buff++ = (bit_len >> 32) & 0xFF;
    *p_buff++ = (bit_len >> 24) & 0xFF;
    *p_buff++ = (bit_len >> 16) & 0xFF;
    *p_buff++ = (bit_len >>  8) & 0xFF;
    *p_buff++ = (bit_len)       & 0xFF;

    return pad_sz;
}



/*------------------------------------------------------------------
 * Func : MCP_SHA256_Hashing
 *
 * Desc : Do SHA256 Hashing
 *
 * Parm : pDesc      : Descriptor to be Load
 *        DataIn     : Data to be hashing (in Physical Address)
 *        Len        : number of data to be hashing
 *                     (for SHA1, it should be multiple of 64)
 *        DataOut    : Physical address that used to store hash value
 *                     (for SHA1, it should be 20 bytes)
 *
 * Retn : S_OK  /  S_FALSE
 *------------------------------------------------------------------*/
int MCP_SHA256_Hashing(
    mcp_desc*               p_desc,
    unsigned char*          p_in,
    unsigned long           len,
    unsigned char*          p_out
)
{
    dma_addr_t addr1;
    dma_addr_t addr2;
    int ret = 0;

    if (len & SHA1_ALIGNMENT_CHECK) {
        mcp_warning("input data length (%lu) of SHA_1 should be multiple of 64 bytes\n", len);
        return -1;
    }

    addr1 = _mcp_map_single(p_in, len, DMA_TO_DEVICE);

    addr2 = _mcp_map_single(p_out, SHA256_DIGEST_SIZE, DMA_FROM_DEVICE);

    p_desc->data_in  = addr1;

    p_desc->data_out = addr2;

    p_desc->length   = len;

    //_DumpDescriptor(p_desc);

    ret = mcp_do_command(p_desc, 1);

    _mcp_unmap_single(addr1, len, DMA_TO_DEVICE);

    _mcp_unmap_single(addr2, SHA256_DIGEST_SIZE, DMA_FROM_DEVICE);

    return ret;
}



/*------------------------------------------------------------------
 * Func : MCP_SHA256_DataHash
 *
 * Desc : Compute hash value of Data via 128 bits SHA1
 *
 * Parm : p_data        : Start address of data
 *        data_len      : Length of data
 *        hash          : 32 Bytes (256 bits) hash value of the file
 *        block_size    : Block Size that used to compute Hashing Value
 *                        for SHA256, it should be multiple of 64 bytes (512 bits).
 *        block_status  : b7 : this block is the first  block
 *                        b3 : this block is the latest block
 *
 *           if this block is first block, the iv of the descriptor
 *           will be reset to default. if this block is not first block
 *           then uses the hash vaule as the default iv.
 *
 * Retn : S_OK  /  S_FALSE
 *------------------------------------------------------------------*/
int MCP_SHA256_DataHash(
    unsigned char*          p_data,
    unsigned long           data_len,
    unsigned char           hash[SHA256_DIGEST_SIZE],
    unsigned long           block_size,
    unsigned char           block_status
)
{
    mcp_desc desc;
    int      ret = 0;

    MCP_SHA256_HASH_INIT(&desc);

    // to simplify the implementation, we have made some constrains over here
    // 1) the data_len must be multiple if 64 Bytes
    // 2) the block size must be multiple if 64 Bytes
    // 3) the data_len must be multiple if block size excepts the last block
    if (data_len & SHA256_ALIGNMENT_CHECK) {
        mcp_warning("compute SHA256 hash value failed - data_len (%lu) should be multiple of 64 bytes\n", data_len);
        return -1;
    }

    if (block_size & SHA256_ALIGNMENT_CHECK) {
        mcp_warning("compute SHA256 hash value failed - block size (%lu) should be multiple of 64 bytes\n", block_size);
        return -1;
    }

    if (!(block_status & LAST_BLOCK) && (data_len % block_size)) {
        mcp_warning("compute SHA256 hash value failed - data_len (%lu) should be multiple of block size (%lu) excepts the last block\n", data_len, block_size);
        return -1;
    }

    //--------------
    if (!(block_status & FIRST_BLOCK))
        MCP_SHA256_IV_UPDATE(&desc, hash);    // Setup the initial value of SHA256 Hash Value

    while(data_len && !ret) {
        if (data_len > block_size) {
            ret       = MCP_SHA256_Hashing(&desc, p_data, block_size, hash);
            data_len -= block_size;
            p_data   += block_size;
        } else {
            ret       = MCP_SHA256_Hashing(&desc, p_data, data_len, hash);
            p_data   += data_len;
            data_len = 0;
        }

        MCP_SHA256_IV_UPDATE(&desc, hash);  // Update Hash Value
    }

    return ret;
}


#endif


void do_mcp_throughput_calculate(mcp_desc* desc, dma_addr_t* data_in, dma_addr_t* data_out, unsigned long data_len, int ende, int bcm, char *str)
{
    unsigned long stime = 0;

    desc->data_in  = *data_in;
    desc->data_out = *data_out;
    desc->length   = data_len;

    stime = jiffies;
    mcp_do_command(desc, 1);

    printk("[MCP] %s %s BCM(%d) Throughput %ld Kbytes elapsed \033[0;32;34m %d ms\n\033[m", str, ende ? "EN" : "DE", bcm, data_len / 1024, jiffies_to_msecs(jiffies - stime));
}

/***************************************************************************
            ------------------- MISC ----------------
****************************************************************************/



/*------------------------------------------------------------------
 * Func : mcp_malloc
 *
 * Desc : allocate memory
 *
 * Parm : size      : size of data
 *
 * Retn : start address of data
 *------------------------------------------------------------------*/
void* mcp_malloc(unsigned long size)
{
#ifdef USE_DVR_MALLOC
    return (size >= PAGE_SIZE) ? (void*) dvr_malloc(size)
           : (void*) kmalloc(size, GFP_KERNEL);
#else
    return (size >= PAGE_SIZE) ? (void*) __get_free_pages(GFP_KERNEL, get_order(size))
           : (void*) kmalloc(size, GFP_KERNEL) ;
#endif
}




/*------------------------------------------------------------------
 * Func : mcp_free
 *
 * Desc : release memory
 *
 * Parm : addr      : Start address of data
 *        size      : size of data
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
void mcp_free(void *addr, unsigned long size)
{
    if (size >= PAGE_SIZE)
#ifdef USE_DVR_MALLOC
        dvr_free(addr);
#else
        free_pages((unsigned long)addr, get_order(size));
#endif
    else
        kfree(addr) ;
}


#ifdef CONFIG_PM

int mcp_pm_on(void)
{
    /* check mcp clock*/
    if ( ( rtd_inl(SYS_REG_SYS_SRST1_reg) & SYS_REG_SYS_SRST1_rstn_cp_mask ) &&
         ( rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_cp_mask ) )
        mcp_notice("CP HW Clock is on!"); /* do nothing */
    else
        CRT_CLK_OnOff(CP, CLK_ON, NULL);

    /* reset MCP phy */
    _mcp_phy_init();

    return 0;
}

int mcp_pm_off(void)
{

    int log_flag = 0;
    /* check mcp clock off */
    if (!(rtd_inl(SYS_REG_SYS_CLKEN1_reg) & SYS_REG_SYS_CLKEN1_clken_cp_mask)) {
        mcp_err("MCP has been turned off the clock by anothers.\n");
        return -1;
    }

    // mcp_debug("MCP (GET_MCP_CTRL() & MCP_IDEL)>>2=0x%x, !((GET_MCP_CTRL() & MCP_IDEL)>>2)=0x%x\n", (GET_MCP_CTRL() & MCP_IDEL)>>2, !((GET_MCP_CTRL() & MCP_IDEL)>>2));
    /* check scpu mcp idle and kcpu suspend finish */
    while(!((GET_MCP_CTRL() & MCP_IDEL) >> 2)
#ifdef CONFIG_REALTEK_SECURE
#if  !defined(CONFIG_RTK_KDRV_OPENBSD) && !defined(CONFIG_OPTEE)
          || !(GET_MCP_SCTCH() & MCP_SCTCH_REG0_DUMMY0)
#endif
#endif
         ) {
        if ( log_flag == 0 ) {
            mcp_notice("wait for cp engine idle ...\n");
            if (!((GET_MCP_CTRL() & MCP_IDEL) >> 2))
                mcp_notice("scpu mcp not idle ...\n");
#ifdef CONFIG_REALTEK_SECURE
#if  !defined(CONFIG_RTK_KDRV_OPENBSD) && !defined(CONFIG_OPTEE)
            if ( !(GET_MCP_SCTCH() & MCP_SCTCH_REG0_DUMMY0) )
                mcp_notice("kcpu not ok ...\n");
#endif
#endif
            log_flag++;
        }
    }

    // mcp_debug("Check Dummy0 status:0x%x in scpu pm off before clear dummy bit must be 1\n",GET_MCP_SCTCH() & MCP_SCTCH_REG0_DUMMY0);
    /* clear dummy bit */
    SET_MCP_SCTCH(GET_MCP_SCTCH() & (~MCP_SCTCH_REG0_DUMMY0));
    // mcp_debug("Check Dummy0 status:0x%x in scpu pm off after clear dummy bit must be 0\n",GET_MCP_SCTCH() & MCP_SCTCH_REG0_DUMMY0);

    CRT_CLK_OnOff(CP, CLK_OFF, NULL);

    return 0;
}
#endif

int __init mcp_core_init(struct device *dev_device)
{
    int ret = 0;
    if (_mcp_phy_init() < 0) {
        ret = -1;
        goto FAIL_INIT_PHY;
    }
#ifdef MCP_INTERRUPT_ENABLE
    if (request_irq(MCP_IRQ, mcp_isr, IRQF_SHARED, "MCP", &mcp_wait_queue) < 0) {
        mcp_warning("Request irq %d failed\n", MCP_IRQ);
        ret = -ENODEV;
        goto FAIL_REQUEST_IRQ;
    }
#endif
    desc_list = dma_alloc_coherent(dev_device, sizeof(mcp_desc) * MCP_DESC_ENTRY_COUNT,
                                   &desc_list_dma_handle, GFP_ATOMIC);
    if (!desc_list) {
        mcp_err("mcp_module_init error, cannot allocate memory.\n");
        ret = -ENOMEM;
        goto FAIL_ALLOC_DESC_LIST;
    }
    mcp_device = dev_device;
    return 0;
FAIL_ALLOC_DESC_LIST:
#ifdef MCP_INTERRUPT_ENABLE
    free_irq(MCP_IRQ, &mcp_wait_queue);
FAIL_REQUEST_IRQ:
#endif
FAIL_INIT_PHY:
    return ret;
}

void __exit mcp_core_uninit(void)
{
    SET_MCP_CTRL(MCP_GO);           /* dessert go bit*/
    SET_MCP_EN(0xFE);               /* disable all interrupts*/
    msleep(10);                     /* wait for hw stop */
    SET_MCP_BASE (0);
    SET_MCP_LIMIT(0);
    SET_MCP_RDPTR(0);
    SET_MCP_WRPTR(0);
#ifdef MCP_INTERRUPT_ENABLE
    free_irq(MCP_IRQ, &mcp_wait_queue);
#endif
    dma_free_coherent(mcp_device, sizeof(mcp_desc) * MCP_DESC_ENTRY_COUNT,
                      desc_list, desc_list_dma_handle);
}
