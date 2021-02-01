#ifndef __RTK_MD_H__
#define __RTK_MD_H__
#include <linux/semaphore.h>

#define MD_ONE_CMD_LEN                         16
#define MD_WRITE_MAX_SIZE                    16384
#define MD_CMD_BUF                                   (4096*sizeof(uint32_t))
#define MD_SEQ_LEN_LIMIT                (0x40000000 - 16)
#define MD_SEQ_LEN_LIMIT_MASK           (0x3fffffff)

#define MdClearWriteData                (0)
#define MD_CONST                        BIT(6)
#define MD_MOVE_DIR                     BIT(7)

/*Word 1 bit[3:0] : opcode */
#define MD_1B                           (0x05)
#define MD_2B                           (0x07)
#define MD_4B                           (0x0D)

/*Word 1 bit[5:4] : move mode */
#define MD_SS                           (0x00) /*seq -> seq */
#define MD_SB                           (0x10) /*seq -> blk */
#define MD_BS                           (0x20) /*blk -> seq */
#define MD_SS_PITCH                     (0x30) /*seq -> seq (pitch) */

#define MD_2B_SS                        (MD_SS|MD_2B)
#define MD_2B_SS_PITCH                  (MD_SS_PITCH|MD_2B)

#define MD_4B_SS                        (MD_SS|MD_4B)
#define MD_4B_SS_PITCH                  (MD_SS_PITCH|MD_4B)

#define MD_SRC_PITCH(x)         ((x & 0x1FFF)<<19)
#define MD_MAX_SRC_PITCH        (0x2000)
#define MD_DST_PITCH(x)         ((x & 0x1FFF)<<6)
#define MD_MAX_DST_PITCH        (0x2000)
#define MD_HEIGHT_BLK(x)        ((x & 0x7FF)<<21)
#define MD_MAX_HEIGHT_BLOCK     (0x800)
#define MD_WIDTH_BLK(x)         ((x & 0x3FFF)<<7)
#define MD_MAX_WIDTH_BLOCK      (0x4000)

/*MD error define*/
#define MD_SUCCESS              (0)
#define MD_ERR_WRITE_FAIL       (-1)
#define MD_ERR_NO_SEM           (-2)
typedef enum {
    MdWriteData     = BIT(0),
    MdGo            = BIT(1),
    MdEndianSwap    = BIT(2),
    MdIdle          = BIT(3)
} MD_CTRL_REG;


/*interrupt status and control bits */
typedef enum {
    MdIntCmdOpcodeError     = BIT(1),
    MdIntCmdLengthError     = BIT(2),
    MdIntCommandEmpty       = BIT(3),
    MdIntFlashCmdDone       = BIT(4),
    MdInt2B4BModeError      = BIT(5),
    MdIntTxThreshold        = BIT(6),
    MdIntRxThreshold        = BIT(7),
    MdIntRxTimeOut          = BIT(8),
    MdIntTxRxLengthError    = BIT(9),
    MdIntSCPUInt            = BIT(10)
} MD_INT_STATUS_REG, MD_INT_CTRL_REG;


struct md_dev {
    volatile void *CmdBuf;
    volatile void *CmdBase;
    volatile void *CmdLimit;
    volatile void *CmdWptr;
    int wrptr;
    int cmd_cnt;
    volatile int size;
    volatile uint64_t u64InstCnt;
    volatile uint64_t u64IssuedInstCnt;
    volatile int queue;
    struct semaphore sem;
    wait_queue_head_t  wait_queue __attribute__((__aligned__(4)));
    volatile int CmdDone;
    struct device *md_device;
};


/*************Internel API for itself to call**********/
extern __init int rtk_md_init(struct device *md_device);
extern __exit void rtk_md_uninit(void);
extern int md_memcpy(uint32_t dst_phys_addr,
                     uint32_t src_phys_addr, uint32_t length, int32_t op, uint32_t is_wait);
extern int md_do_cmds(uint8_t *pbyCommandBuffer, uint32_t lCommandLength);
extern int md_wait_hw_stopped(uint64_t timeout);
extern int md_get_inst_count(uint64_t *p_u64InstCnt);
extern int md_get_issued_inst_count(uint64_t *p_u64IssuedInstCnt);
extern int md_fill(uint32_t addrdst, int32_t len, uint32_t bytemode,
                   uint32_t movemode, uint32_t val);
extern int md_memcpy_multi_desc(uint8_t *srcBuf, uint32_t *dstBuf, struct md_dev *pdev, int length, int desc_num);
void rtk_md_enable_mult_reg(int on_off);


#ifdef CONFIG_PM
extern int md_poweroff(void);
extern int md_suspend_noirq(void);
extern int md_resume_noirq(void);
extern int md_resume_early(void);
extern int md_restore(void);
extern int md_freeze_noirq(void);
#endif

/*************The MD Global APIs for other modules in kernel to call**********/
extern bool smd_waitComplete(uint64_t handle,
                             uint64_t timeout, uint64_t *hw_cnt);
extern bool smd_checkFinish(uint64_t handle);
extern void smd_checkComplete(void);
extern uint64_t smd_memcpy(uint32_t addr_dst,
                           uint32_t addr_src, int32_t len);
extern int smd_fill(uint32_t addrdst, int32_t len, uint32_t val);
#endif
