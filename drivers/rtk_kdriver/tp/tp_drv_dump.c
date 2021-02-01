/*  version 0.1 */

/* #define TP_DUMP_DATA_TO_FILE */

#ifdef TP_DUMP_DATA_TO_FILE

#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/delay.h>

#include <tp/tp_drv_global.h>
#include <tp/tp_dbg.h>


#define FILE_PATH "/mnt/usbmounts/sda/tpdata.ts"
#define REC_TIME (30*1000)
#define WRITE_INTERVAL (10)
#define WRITE_TIMES (REC_TIME/WRITE_INTERVAL)

static struct file* file_open(const char* path, int flags, int rights)
{
        struct file* filp = NULL;
        mm_segment_t oldfs;
        int err = 0;

        oldfs = get_fs();
        set_fs(get_ds());
        filp = filp_open(path, flags, rights);
        set_fs(oldfs);
        if(IS_ERR(filp)) {
                err = PTR_ERR(filp);
                return NULL;
        }
        return filp;
}

static void file_close(struct file* file)
{
        filp_close(file, NULL);
}

static int file_read(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size)
{
        mm_segment_t oldfs;
        int ret;

        oldfs = get_fs();
        set_fs(get_ds());

        ret = vfs_read(file, data, size, &offset);

        set_fs(oldfs);
        return ret;
}

static int file_write(struct file* file, unsigned long long offset, unsigned char* data, unsigned int size)
{
        mm_segment_t oldfs;
        int ret;

        oldfs = get_fs();
        set_fs(get_ds());

        ret = vfs_write(file, data, size, &offset);

        set_fs(oldfs);
        return ret;
}

static int file_sync(struct file* file)
{
        vfs_fsync(file, 0);
        return 0;
}


static int tp_dump_data_to_file(void* arg)
{
        struct file* filp = file_open(FILE_PATH, O_RDWR, 0);
        unsigned int cnt;
        unsigned int SharedRPPhy, SharedWPPhy;
        unsigned int RP, WP, Base, Limit, RPPhy, WPPhy, BasePhy, LimitPhy;
        unsigned int ReadSize;
        unsigned char* pBuf;
        unsigned int offset = 0;

        BasePhy = pTp_drv->tp[0].mass_buffer.BasePhy;
        LimitPhy = pTp_drv->tp[0].mass_buffer.LimitPhy;
        Base = phys_to_virt(BasePhy);
        Limit = phys_to_virt(LimitPhy);


        TP_INFO("BasePhy=%p LimitPhy=%p Base=%p Limit=%p\n", (void *)BasePhy, (void *)LimitPhy, (void *)Base, (void *)Limit);

        SharedRPPhy = BasePhy;
        SharedWPPhy = BasePhy;

        RHAL_DumpTPRingBuffer(0, 1, (unsigned char*)&SharedRPPhy, (unsigned char*)&SharedWPPhy);

        msleep(WRITE_INTERVAL * 2);

        for (cnt = 0; cnt < WRITE_TIMES; cnt++) {
                RPPhy = SharedRPPhy;
                WPPhy = SharedWPPhy;

                RP = phys_to_virt(RPPhy);
                WP = phys_to_virt(WPPhy);

                if (RP >= WP) {
                        ReadSize = Limit - RP;

                        /*  make sure that more than 376 bytes left */
                        if ((WP - Base) < 376)
                                ReadSize = (ReadSize > 376) ? ReadSize - 376 : 0;
                } else {
                        ReadSize = WP - RP;

                        /*  make sure that more than 376 bytes left */
                        ReadSize = (ReadSize > 376) ? ReadSize - 376 : 0;
                }
                TP_INFO("RPPhy=%p WPPhy=%p RP=%p WP=%p ReadSize=%u\n", (void *)RPPhy, (void *)WPPhy, (void *)RP, (void *)WP, ReadSize);

                if (ReadSize > 0) {
                        pBuf = (unsigned char*)RP;

                        /*     file_write(filp, offset, pBuf, ReadSize); */
                        offset += ReadSize;

                        SharedRPPhy = BasePhy + (SharedRPPhy - BasePhy + ReadSize) % (LimitPhy - BasePhy);
                }

                msleep(WRITE_INTERVAL);
        }

        RHAL_DumpTPRingBuffer(0, 0, (unsigned char*)&SharedRPPhy, (unsigned char*)&SharedWPPhy);

        file_close(filp);

        return 0;
}

void DumpData(void)
{
        kthread_run(tp_dump_data_to_file, NULL, "tp_dump_data_to_file");
        TP_INFO("Call DumpData\n");
}

#endif


