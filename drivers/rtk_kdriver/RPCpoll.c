/*
 * $Id: RPCpoll.c,v 1.10 2004/8/4 09:25 Jacky Exp $
 */
#include <generated/autoconf.h>
/*
#if defined(CONFIG_MODVERSIONS) && !defined(MODVERSIONS)
    #define MODVERSIONS
#endif

#ifdef MODVERSIONS
    #include <linux/modversions.h>
#endif

#ifndef MODULE
#define MODULE
#endif
*/
#include <linux/module.h>
#include <linux/kernel.h>   /* printk() */
#include <linux/slab.h>     /* kmalloc() */
#include <linux/fs.h>       /* everything... */
#include <linux/errno.h>    /* error codes */
#include <linux/types.h>    /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>    /* O_ACCMODE */
#include <linux/ioctl.h>    /* needed for the _IOW etc stuff used later */
#include <linux/delay.h>
#include <rtk_kdriver/RPCDriver.h>
#include <mach/io.h>
#include <rtk_kdriver/rtk_tee_proxy.h>

//#include <asm/system.h>     /* cli(), *_flags */
#include <asm/uaccess.h>    /* copy_to_user() copy_from_user() */

RPC_POLL_Dev *rpc_poll_devices;
#ifdef CONFIG_REALTEK_RPC_KCPU
RPC_POLL_Dev *rpc_poll_kcpu_devices;
#endif
int rpc_poll_is_paused = 0;
unsigned int user_rpc_queue_count= 0;

#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS

static RPC_DEV_EXTRA rpc_poll_extra[RPC_NR_DEVS/RPC_NR_PAIR];
#ifdef CONFIG_REALTEK_RPC_KCPU
static RPC_DEV_EXTRA rpc_poll_kcpu_extra[RPC_NR_KCPU_DEVS/RPC_NR_PAIR];
#endif
int rpc_stop(RPC_PROCESS *proc)
{
	unsigned long ret = 0;
	if (proc->stop)
		return ret;
	proc->stop = 1;
	if(send_rpc_command(RPC_AUDIO,RPC_ACPU_RELEASE_NOTICE, proc->pid, 0, &ret) == RPC_OK)
		PDEBUG("%s: Notify audio firmware PID(%d) success.\n", __func__, proc->pid);
	else
		PDEBUG("%s: Notify audio firmware PID(%d) failed.\n", __func__, proc->pid);

	return (int)ret;

}

int rpc_poll_init(void)
{
        static int is_init = 0;
        int result = 0, i;

    // Create corresponding structures for each device.
    rpc_poll_devices = (RPC_POLL_Dev *)phys_to_virt(RPC_POLL_RECORD_ADDR);

    for (i = 0; i < RPC_POLL_DEV_TOTAL; i++) {
        PDEBUG("rpc_poll_device %d addr: %x \n", i, (unsigned)&rpc_poll_devices[i]);
        rpc_poll_devices[i].ringBuf = (char *)(phys_to_virt(RPC_POLL_DEV_ADDR + i*RPC_RING_SIZE*2));

        // Initialize pointers...
        rpc_poll_devices[i].ringStart = rpc_poll_devices[i].ringBuf;
        rpc_poll_devices[i].ringEnd = rpc_poll_devices[i].ringBuf+RPC_RING_SIZE;
        rpc_poll_devices[i].ringIn = rpc_poll_devices[i].ringBuf;
        rpc_poll_devices[i].ringOut = rpc_poll_devices[i].ringBuf;

        PDEBUG("The %dth RPC_POLL_Dev:\n", i);
        PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_poll_devices[i].ringStart);
        PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_poll_devices[i].ringEnd);
        PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_poll_devices[i].ringIn);
        PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_poll_devices[i].ringOut);
        PDEBUG("\n");

        rpc_poll_extra[i].nextRpc = rpc_poll_devices[i].ringOut;
        rpc_poll_extra[i].currProc = NULL;
        spin_lock_init(&rpc_poll_extra[i].lock);

        if (!is_init) {
		rpc_poll_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

                // Initialize wait queue...
                //init_waitqueue_head(&(rpc_poll_devices[i].ptrSync->waitQueue));

	        // Initialize sempahores...
	        sema_init(&rpc_poll_devices[i].ptrSync->readSem, 1);
	        sema_init(&rpc_poll_devices[i].ptrSync->writeSem, 1);

                rpc_poll_extra[i].dev = (void *)&rpc_poll_devices[i];
                INIT_LIST_HEAD(&rpc_poll_extra[i].tasks);
                //tasklet_init(&rpc_poll_extra[i].tasklet, rpc_dispatch, (unsigned long)&rpc_poll_extra[i]);
                spin_lock_init(&rpc_poll_extra[i].lock);
                switch(i){
                case 0: rpc_poll_extra[i].name = "AudioPollWrite"; break;
                case 1: rpc_poll_extra[i].name = "AudioPollRead"; break;
                case 2: rpc_poll_extra[i].name = "Video1PollWrite"; break;
                case 3: rpc_poll_extra[i].name = "Video1PollRead"; break;
                case 4: rpc_poll_extra[i].name = "Video2PollWrite"; break;
                case 5: rpc_poll_extra[i].name = "Video2PollRead"; break;
                }
        }
    }

#ifdef CONFIG_REALTEK_RPC_KCPU
    // Create corresponding structures for each device.
    rpc_poll_kcpu_devices = (RPC_POLL_Dev *)phys_to_virt(RPC_POLL_KCPU_RECORD_ADDR);

    for (i = 0; i < RPC_POLL_DEV_KCPU_TOTAL; i++) {
        PDEBUG("rpc_poll_kcpu_device %d addr: %x \n", i, (unsigned)&rpc_poll_kcpu_devices[i]);
        rpc_poll_kcpu_devices[i].ringBuf = (char *)(phys_to_virt(RPC_POLL_KCPU_DEV_ADDR + i*RPC_KCPU_RING_SIZE*2));

        // Initialize pointers...
        rpc_poll_kcpu_devices[i].ringStart = rpc_poll_kcpu_devices[i].ringBuf;
        rpc_poll_kcpu_devices[i].ringEnd = rpc_poll_kcpu_devices[i].ringBuf+RPC_KCPU_RING_SIZE;
        rpc_poll_kcpu_devices[i].ringIn = rpc_poll_kcpu_devices[i].ringBuf;
        rpc_poll_kcpu_devices[i].ringOut = rpc_poll_kcpu_devices[i].ringBuf;

        PDEBUG("The %dth RPC_POLL_Dev:\n", i);
        PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_poll_kcpu_devices[i].ringStart);
        PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_poll_kcpu_devices[i].ringEnd);
        PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_poll_kcpu_devices[i].ringIn);
        PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_poll_kcpu_devices[i].ringOut);
        PDEBUG("\n");

        rpc_poll_kcpu_extra[i].nextRpc = rpc_poll_kcpu_devices[i].ringOut;
        rpc_poll_kcpu_extra[i].currProc = NULL;

        if (!is_init) {
		rpc_poll_kcpu_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

                // Initialize wait queue...
                //init_waitqueue_head(&(rpc_poll_kcpu_devices[i].ptrSync->waitQueue));

	        // Initialize sempahores...
	        sema_init(&rpc_poll_kcpu_devices[i].ptrSync->readSem, 1);
	        sema_init(&rpc_poll_kcpu_devices[i].ptrSync->writeSem, 1);

                rpc_poll_kcpu_extra[i].dev = (void *)&rpc_poll_kcpu_devices[i];
                INIT_LIST_HEAD(&rpc_poll_kcpu_extra[i].tasks);
                //tasklet_init(&rpc_poll_kcpu_extra[i].tasklet, rpc_dispatch, (unsigned long)&rpc_poll_kcpu_extra[i]);
                spin_lock_init(&rpc_poll_kcpu_extra[i].lock);
                switch(i){
                case 0: rpc_poll_kcpu_extra[i].name = "KCPUPollWrite"; break;
                case 1: rpc_poll_kcpu_extra[i].name = "KCPUPollRead"; break;
                }
        }
    }
#endif

    is_init = 1;
    rpc_poll_is_paused = 0;

//fail:
    return result;
}

int rpc_poll_pause(void)
{
    rpc_poll_is_paused = 1;

    return 0;
}

void rpc_poll_cleanup(void)
{
        int num = RPC_NR_DEVS/RPC_NR_PAIR, i;

    // Clean corresponding structures for each device.
    if (rpc_poll_devices) {
        // Clean ring buffers.
        for (i = 0; i < num; i++) {
//          if (rpc_poll_devices[i].ringBuf)
//              kfree(rpc_poll_devices[i].ringBuf);
            kfree(rpc_poll_devices[i].ptrSync);
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
                devfs_unregister(rpc_poll_devices[i].handle);
#endif
#endif
        }

//        kfree(rpc_poll_devices);
    }

    return;
}

int rpc_poll_open(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
        int minor = MINOR(inode->i_rdev)-1;
#endif
#endif
        int minor = MINOR(inode->i_rdev);

    if (minor == 100) {
        filp->f_op = &rpc_ctrl_fops;
        return filp->f_op->open(inode, filp); /* dispatch to specific open */
    }
#ifdef CONFIG_REALTEK_RPC_DEBUG
	else if(minor == 101){
		filp->f_op = &rpc_debug_fops;
		return filp->f_op->open(inode, filp);
	}
#endif
    /*
     * If private data is not valid, we are not using devfs
     * so use the minor number to select a new f_op
     */
    if (!filp->private_data && (minor%RPC_NR_PAIR != 0)) {
        filp->f_op = rpc_fop_array[minor%RPC_NR_PAIR];
        return filp->f_op->open(inode, filp); /* dispatch to specific open */
    }

    PDEBUG("RPC poll open with minor number: %d\n", minor);

        if (!filp->private_data) {
                RPC_PROCESS *proc = kmalloc(sizeof(RPC_PROCESS), GFP_KERNEL);
                if(proc == NULL){
                        pr_err("%s: failed to allocate RPC_PROCESS\n", __func__);
                        return -ENOMEM;
                }

#ifdef CONFIG_REALTEK_RPC_KCPU
                if (minor >= RPC_NR_DEVS) {
                        if(minor > (RPC_NR_DEVS +RPC_NR_KCPU_DEVS)){
                            pr_err("%s: no such device ! \n", __func__);
                            return -ENXIO;
			            }
                        proc->dev = (RPC_COMMON_Dev *)&rpc_poll_kcpu_devices[(minor-RPC_NR_DEVS)/RPC_NR_PAIR];
                        proc->extra = &rpc_poll_kcpu_extra[(minor-RPC_NR_DEVS)/RPC_NR_PAIR];
                } else {
                        proc->dev = (RPC_COMMON_Dev *)&rpc_poll_devices[minor/RPC_NR_PAIR];
                        proc->extra = &rpc_poll_extra[minor/RPC_NR_PAIR];
                }
#else
                proc->dev = (RPC_COMMON_Dev *)&rpc_poll_devices[minor/RPC_NR_PAIR];
                proc->extra = &rpc_poll_extra[minor/RPC_NR_PAIR];
#endif

                proc->pid = current->tgid; //current->tgid = process id, current->pid = thread id
                proc->stop = 0;
                init_waitqueue_head(&proc->waitQueue);
                INIT_LIST_HEAD(&proc->threads);
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
                INIT_LIST_HEAD(&proc->handlers);
#endif

                spin_lock_bh(&proc->extra->lock);
                list_add(&proc->list, &proc->extra->tasks);
                spin_unlock_bh(&proc->extra->lock);
                PDEBUG("%s: Current process pid:%d tgid:%d => %d(%p) for %s(%p)\n", __func__, current->pid, current->tgid, proc->pid, &proc->waitQueue, proc->extra->name, proc->dev);

                filp->private_data = proc;
        }

//    MOD_INC_USE_COUNT;  /* Before we maybe sleep */

    return 0;          /* success */
}

int rpc_poll_release(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
        int minor = MINOR(inode->i_rdev)-1;
#endif
#endif
        int minor = MINOR(inode->i_rdev);

#ifdef CONFIG_REALTEK_RPC_PROGRAM_RELEASE_NOTICE
			unsigned long ret;
#endif

        RPC_PROCESS *proc = filp->private_data;
        RPC_POLL_Dev *dev = (RPC_POLL_Dev *)proc->dev; /* the first listitem */
        RPC_DEV_EXTRA *extra = proc->extra;

        if(extra->currProc == proc){
                PDEBUG("%s: clear %s(%p) current process\n", __func__, proc->extra->name, dev);
                update_currProc(extra, NULL);
                if(minor == 2 || minor == 6 || minor == 10
#ifdef CONFIG_REALTEK_RPC_KCPU
			||minor == 14
#endif
		   ){ //poll read device (ugly code)
                        if(!rpc_done(extra)){
                                pr_err("%s: previous rpc hasn't finished, force clear!! ringOut %p => %p\n", __func__,
					dev->ringOut, extra->nextRpc);
                                if (down_interruptible(&dev->ptrSync->readSem))
                                        return -ERESTARTSYS;
                                dev->ringOut = extra->nextRpc;
                                up(&dev->ptrSync->readSem);
                        }
                }
        }

#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
		{
	        //unregister myself from handler list
	        RPC_HANDLER *handler, *hdltmp;
	        list_for_each_entry_safe(handler, hdltmp, &proc->handlers, list){
	                list_del(&handler->list);
	                kfree(handler);
	        }
        }
#endif
        {
        	//unregister myself from thread list
        	RPC_THREAD *threads, *thdtmp;
        		list_for_each_entry_safe(threads, thdtmp, &proc->threads, list){
        			list_del(&threads->list);
        			kfree(threads);
        	}
        }
        //remove myself from task list
        spin_lock_bh(&extra->lock);
        list_del(&proc->list);
        spin_unlock_bh(&extra->lock);

#ifdef CONFIG_REALTEK_RPC_PROGRAM_RELEASE_NOTICE
			// Send a RPC to firmware to notify process close
			if(minor == RPC_POLL_DEV_SA_ID0)
			{
				if(send_rpc_command(RPC_VIDEO,RPC_VCPU_ID_0x126_Resource_Recovery_Pause, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware PID(%d) failed.\n", __func__, proc->pid);
#ifdef CONFIG_REALTEK_RPC_VCPU2
				if(send_rpc_command(RPC_VIDEO2,RPC_VCPU_ID_0x126_Resource_Recovery_Pause, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware 2 PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware 2 PID(%d) failed.\n", __func__, proc->pid);
#endif
				if(send_rpc_command(RPC_VIDEO,RPC_VCPU_ID_0x125_Resource_Recovery_Flush, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware PID(%d) failed.\n", __func__, proc->pid);
#ifdef CONFIG_REALTEK_RPC_VCPU2
				if(send_rpc_command(RPC_VIDEO2,RPC_VCPU_ID_0x125_Resource_Recovery_Flush, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware 2 PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware 2 PID(%d) failed.\n", __func__, proc->pid);
#endif
				if(send_rpc_command(RPC_VIDEO,RPC_VCPU_ID_0x123_Resource_Recovery_Stop, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware PID(%d) failed.\n", __func__, proc->pid);
#ifdef CONFIG_REALTEK_RPC_VCPU2
				if(send_rpc_command(RPC_VIDEO2,RPC_VCPU_ID_0x123_Resource_Recovery_Stop, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware 2 PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware 2 PID(%d) failed.\n", __func__, proc->pid);
#endif
				if(send_rpc_command(RPC_VIDEO,RPC_VCPU_ID_0x124_Resource_Recovery_Destory, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware PID(%d) failed.\n", __func__, proc->pid);
#ifdef CONFIG_REALTEK_RPC_VCPU2
				if(send_rpc_command(RPC_VIDEO2,RPC_VCPU_ID_0x124_Resource_Recovery_Destory, proc->pid, 0, &ret) == RPC_OK)
					PDEBUG("%s: Notify video firmware 2 PID(%d) success.\n", __func__, proc->pid);
				else
					PDEBUG("%s: Notify video firmware 2 PID(%d) failed.\n", __func__, proc->pid);
#endif
				// if(send_rpc_command(RPC_AUDIO,RPC_ACPU_RELEASE_NOTICE, proc->pid, 0, &ret) == RPC_OK)
				//	PDEBUG("%s: Notify audio firmware PID(%d) success.\n", __func__, proc->pid);
				//else
				//	PDEBUG("%s: Notify audio firmware PID(%d) failed.\n", __func__, proc->pid);

				ret = rpc_stop(proc);

				#ifdef CONFIG_RTK_KDRV_TEEPROXY
				rtk_teeproxy_free_user_mem(proc->pid);
				#endif
			}
#endif

        kfree(proc);

    PDEBUG("RPC poll close with minor number: %d\n", minor);

//    MOD_DEC_USE_COUNT;

    return 0;          /* success */
}

// We don't need parameter f_pos here...
ssize_t rpc_poll_read(struct file *filp, char *buf, size_t count,
                loff_t *f_pos)
{
        RPC_PROCESS *proc = filp->private_data;
        RPC_POLL_Dev *dev = (RPC_POLL_Dev *)proc->dev; /* the first listitem */
        RPC_DEV_EXTRA *extra = proc->extra;
        int temp, size;
        ssize_t ret = 0;
        char *ptmp;
        int rpc_ring_size = dev->ringEnd - dev->ringStart;

        PDEBUG("%s:%d thread:%s pid:%d tgid:%d device:%s\n", __func__, __LINE__, current->comm, current->pid, current->tgid, extra->name);
        if (rpc_poll_is_paused) {
                pr_err("RPCpoll: someone access rpc poll during the pause...\n");
                msleep(1000);
                return -EAGAIN;
        }

        if (down_interruptible(&dev->ptrSync->readSem))
                return -ERESTARTSYS;

        if (need_dispatch(extra)) {
                rpc_dispatch((unsigned long)extra);
        }

        PDEBUG("%s: dev:%s(%p) currProc:%p\n", __func__, extra->name, dev, extra->currProc);
        if ((extra->currProc != proc) || (ring_empty((RPC_COMMON_Dev *)dev))) {
                if (unlikely(!(filp->f_flags & O_NONBLOCK))){
                        //printk("%s:%d:%s Warning: pid:%d use blocking mode with poll buffer!\n", __func__, __LINE__, extra->name, current->pid);
                }
                goto out; //return anyway
        }

        if (dev->ringIn > dev->ringOut)
                size = dev->ringIn - dev->ringOut;
        else
                size = rpc_ring_size + dev->ringIn - dev->ringOut;

#ifdef CONFIG_REALTEK_RPC_DEBUG
	 if(is_pr_type_match( extra->name))
        	PDEBUGR("%s: %s: count:%d size:%d\n", __func__, extra->name, count, size);
#endif
        //peek_rpc_struct(__func__, dev);
        if (count > size)
			goto out;
                //count = size;

        temp = dev->ringEnd - dev->ringOut;
        if (temp >= count) {
                if(my_copy_to_user((int *)buf, (int *)dev->ringOut, count)){
                        ret = -EFAULT;
                        goto out;
                }
                ret += count;
                ptmp = dev->ringOut + ((count+3) & 0xfffffffc);
                if (ptmp == dev->ringEnd)
                        dev->ringOut = dev->ringStart;
                else
                        dev->ringOut = ptmp;

                PDEBUG("RPC Read is in 1st kind...\n");
        } else {
                if(my_copy_to_user((int *)buf, (int *)dev->ringOut, temp)){
                        ret = -EFAULT;
                        goto out;
                }
                count -= temp;

               if(my_copy_to_user((int *)(buf+temp), (int *)dev->ringStart, count)){
                        ret = -EFAULT;
                        goto out;
                }
                ret += (temp + count);
                dev->ringOut = dev->ringStart+((count+3) & 0xfffffffc);

                PDEBUG("RPC Read is in 2nd kind...\n");
        }

        if (rpc_done(extra)) {
                PDEBUG("%s: Previous RPC is done, unregister myself\n", __func__);
                update_currProc(extra, NULL);
        }

        //process next rpc command if any
        if (need_dispatch(extra)) {
                rpc_dispatch((unsigned long)extra);
	}
#ifdef CONFIG_REALTEK_RPC_DEBUG
	if(is_pr_type_match( extra->name))
       {
       	PDEBUGR("RPC poll ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
       	PDEBUGR("%s:%d pid:%d reads %d bytes\n", extra->name, __LINE__, current->pid, ret);
	}
#endif
out:
        up(&dev->ptrSync->readSem);
        PDEBUG("RPC poll ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
        PDEBUG("%s:%d pid:%d reads %d bytes\n", extra->name, __LINE__, current->pid, ret);
        return ret;
}

// We don't need parameter f_pos here...
ssize_t rpc_poll_write(struct file *filp, const char *buf, size_t count,
                loff_t *f_pos)
{
        RPC_PROCESS *proc = filp->private_data;
        RPC_POLL_Dev *dev = (RPC_POLL_Dev *)proc->dev; /* the first listitem */
        RPC_DEV_EXTRA *extra = proc->extra;
        RPC_DEV_EXTRA *rextra = extra + 1;
        int temp, size;
        ssize_t ret = 0;
        char *ptmp;
        int rpc_ring_size = dev->ringEnd - dev->ringStart;

        if (rpc_poll_is_paused) {
                pr_err("RPCpoll: someone access rpc poll during the pause...\n");
                msleep(1000);
                return -EAGAIN;
        }

        if (down_interruptible(&dev->ptrSync->writeSem))
                return -ERESTARTSYS;

#if 1
        /* Threads that share the same file descriptor should have the same tgid
         * However, with uClibc pthread library, pthread_create() creates threads with pid == tgid
         * So the tgid is not readl tgid, we have to maintain the thread list that we can lookup later
         */
        if(current->tgid != proc->pid){
                RPC_PROCESS *rproc;
                list_for_each_entry(rproc, &rextra->tasks, list){
                        //find the entry in read device task list with the same pid
                        if(rproc->pid == proc->pid){
                                update_thread_list(rproc);
                                break;
                        }
                }
        }
#endif

        if (ring_empty((RPC_COMMON_Dev *)dev))
                size = 0;   // the ring is empty
        else if (dev->ringIn > dev->ringOut)
                size = dev->ringIn - dev->ringOut;
        else
                size = rpc_ring_size + dev->ringIn - dev->ringOut;

#ifdef CONFIG_REALTEK_RPC_DEBUG
        if(is_pr_type_match( extra->name))
        {
		PDEBUGW("%s: count:%d space:%d\n", extra->name, count, rpc_ring_size - size - 1);
        	PDEBUGW("%s: pid:%d tgid:%d\n", extra->name, current->pid, current->tgid);
        }
#endif

        if (count > (rpc_ring_size - size - 1))
                goto out;

        temp = dev->ringEnd - dev->ringIn;
        if (temp >= count) {
               if(my_copy_from_user((int *)dev->ringIn, (int *)buf, count)){
                        ret = -EFAULT;
                        goto out;
                }
                ret += count;
                ptmp = dev->ringIn + ((count+3) & 0xfffffffc);

        		//moidfy by Angus
                dsb(sy);

                if (ptmp == dev->ringEnd)
                        dev->ringIn = dev->ringStart;
                else
                        dev->ringIn = ptmp;

                PDEBUG("RPC Write is in 1st kind...\n");
        } else {
                if(my_copy_from_user((int *)dev->ringIn, (int *)buf, temp)){
                        ret = -EFAULT;
                        goto out;
                }
                count -= temp;

                if(my_copy_from_user((int *)dev->ringStart, (int *)(buf+temp), count)){
                        ret = -EFAULT;
                        goto out;
                }
                ret += (temp + count);

        		//moidfy by Angus
        		dsb(sy);

                dev->ringIn = dev->ringStart+((count+3) & 0xfffffffc);

                PDEBUG("RPC Write is in 2nd kind...\n");
        }

        //peek_rpc_struct(extra->name, dev);
#ifdef CONFIG_REALTEK_RPC_DEBUG
        if(is_pr_type_match( extra->name))
        {
		PDEBUGW("RPC poll ringIn pointer is : 0x%8x\n", (int)dev->ringIn);
        }
#endif
out:
        PDEBUG("RPC poll ringIn pointer is : 0x%8x\n", (int)dev->ringIn);
        up(&dev->ptrSync->writeSem);
        return ret;
}

long rpc_poll_ioctl(/*struct inode *inode, */struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
        int ret = 0;

        switch(cmd) {
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
        case RPC_IOCTHANDLER:
        {
                int found;
                RPC_PROCESS *proc = filp->private_data;
                RPC_HANDLER *handler;

                PDEBUG("%s:%d %d: Register handler for programID:%lu\n", __func__, __LINE__, proc->pid, arg);
                found = 0;
                list_for_each_entry(handler, &proc->handlers, list){
                        if(handler->programID == arg){
                                found = 1;
                                break;
                        }
                }

                if(found) break;

                //not found, add to handler list
                handler = kmalloc(sizeof(RPC_HANDLER), GFP_KERNEL);
                if(handler == NULL){
                        pr_err("%s: failed to allocate RPC_HANDLER\n", __func__);
                        return -ENOMEM;
                }
                handler->programID = arg;
                list_add(&handler->list, &proc->handlers);
                PDEBUG("%s:%d %s: Add handler pid:%d for programID:%lu\n", __func__, __LINE__, proc->extra->name, proc->pid, arg);
                break;
        }
#endif
		case RPC_IOSTOP:
			ret = rpc_stop((RPC_PROCESS *)filp->private_data);
			break;

        default:
                pr_err("%s:%d unsupported ioctl cmd:%x arg:%lx\n", __func__, __LINE__, cmd, arg);
                return -ENOTTY;
        }
        return ret;
}

#else

int rpc_poll_init(void)
{
	static int is_init = 0;
	int result = 0, i;

    // Create corresponding structures for each device.
    rpc_poll_devices = (RPC_POLL_Dev *)phys_to_virt(RPC_POLL_RECORD_ADDR);

    for (i = 0; i < RPC_POLL_DEV_TOTAL; i++) {
        PDEBUG("rpc_poll_device %d addr: %x \n", i, (unsigned)&rpc_poll_devices[i]);
        rpc_poll_devices[i].ringBuf = (char *)(phys_to_virt(RPC_POLL_DEV_ADDR + i*RPC_RING_SIZE*2));

        // Initialize pointers...
        rpc_poll_devices[i].ringStart = rpc_poll_devices[i].ringBuf;
        rpc_poll_devices[i].ringEnd = rpc_poll_devices[i].ringBuf+RPC_RING_SIZE;
        rpc_poll_devices[i].ringIn = rpc_poll_devices[i].ringBuf;
        rpc_poll_devices[i].ringOut = rpc_poll_devices[i].ringBuf;

        PDEBUG("The %dth RPC_POLL_Dev:\n", i);
        PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_poll_devices[i].ringStart);
        PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_poll_devices[i].ringEnd);
        PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_poll_devices[i].ringIn);
        PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_poll_devices[i].ringOut);
        PDEBUG("\n");

		if (!is_init) {
			rpc_poll_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

		        // Initialize sempahores...
		        sema_init(&rpc_poll_devices[i].ptrSync->readSem, 1);
		        sema_init(&rpc_poll_devices[i].ptrSync->writeSem, 1);
		}
    }

    is_init = 1;
    rpc_poll_is_paused = 0;

//fail:
    return result;
}

int rpc_poll_pause(void)
{
    rpc_poll_is_paused = 1;

    return 0;
}

void rpc_poll_cleanup(void)
{
	int num = RPC_NR_DEVS/RPC_NR_PAIR, i;

    // Clean corresponding structures for each device.
    if (rpc_poll_devices) {
    	// Clean ring buffers.
    	for (i = 0; i < num; i++) {
//     	    if (rpc_poll_devices[i].ringBuf)
//            	kfree(rpc_poll_devices[i].ringBuf);
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
        	devfs_unregister(rpc_poll_devices[i].handle);
#endif
#endif
    	}

//        kfree(rpc_poll_devices);
    }

    return;
}

int rpc_poll_open(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
	int minor = MINOR(inode->i_rdev)-1;
#endif
#endif
	int minor = MINOR(inode->i_rdev);

    if (minor == 100) {
        filp->f_op = &rpc_ctrl_fops;
        return filp->f_op->open(inode, filp); /* dispatch to specific open */
    }
    /*
     * If private data is not valid, we are not using devfs
     * so use the minor number to select a new f_op
     */
    if (!filp->private_data && (minor%RPC_NR_PAIR != 0)) {
        filp->f_op = rpc_fop_array[minor%RPC_NR_PAIR];
        return filp->f_op->open(inode, filp); /* dispatch to specific open */
    }

    PDEBUG("RPC poll open with minor number: %d\n", minor);

	if (!filp->private_data) {
#ifdef CONFIG_REALTEK_RPC_KCPU
		if (minor >= RPC_NR_DEVS)
			filp->private_data = &rpc_poll_kcpu_devices[(minor-RPC_NR_DEVS)/RPC_NR_PAIR];
		else
#endif
		filp->private_data = &rpc_poll_devices[minor/RPC_NR_PAIR];
	}

//    MOD_INC_USE_COUNT;  /* Before we maybe sleep */

    return 0;          /* success */
}

int rpc_poll_release(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
	int minor = MINOR(inode->i_rdev)-1;
#endif
#endif
	int minor = MINOR(inode->i_rdev);

    PDEBUG("RPC poll close with minor number: %d\n", minor);

//    MOD_DEC_USE_COUNT;

    return 0;          /* success */
}

// We don't need parameter f_pos here...
ssize_t rpc_poll_read(struct file *filp, char *buf, size_t count,
                loff_t *f_pos)
{
    RPC_POLL_Dev *dev = filp->private_data; /* the first listitem */
    int temp, size;
    ssize_t ret = 0;
    char *ptmp;
    int rpc_ring_size = dev->ringEnd - dev->ringStart;

    if (rpc_poll_is_paused) {
        pr_err("RPCpoll: someone access rpc poll during the pause...\n");
        msleep(1000);
        return -EAGAIN;
    }

    if (down_interruptible(&dev->ptrSync->readSem))
        return -ERESTARTSYS;

    if (dev->ringIn == dev->ringOut)
        goto out;   // the ring is empty...
    else if (dev->ringIn > dev->ringOut)
        size = dev->ringIn - dev->ringOut;
    else
        size = rpc_ring_size + dev->ringIn - dev->ringOut;

	if (count > size)
		count = size;

	temp = dev->ringEnd - dev->ringOut;
	if (temp >= count) {
		if (my_copy_user((int *)buf, (int *)dev->ringOut, count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += count;
		ptmp = dev->ringOut + ((count+3) & 0xfffffffc);
		if (ptmp == dev->ringEnd)
			dev->ringOut = dev->ringStart;
		else
			dev->ringOut = ptmp;

    	PDEBUG("RPC Read is in 1st kind...\n");
	} else {
		if (my_copy_user((int *)buf, (int *)dev->ringOut, temp)) {
        	ret = -EFAULT;
			goto out;
		}
		count -= temp;

		if (my_copy_user((int *)(buf+temp), (int *)dev->ringStart, count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += (temp + count);
		dev->ringOut = dev->ringStart+((count+3) & 0xfffffffc);

    	PDEBUG("RPC Read is in 2nd kind...\n");
	}
out:
    PDEBUG("RPC poll ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
    up(&dev->ptrSync->readSem);
    return ret;
}

// We don't need parameter f_pos here...
ssize_t rpc_poll_write(struct file *filp, const char *buf, size_t count,
                loff_t *f_pos)
{
    RPC_POLL_Dev *dev = filp->private_data; /* the first listitem */
    int temp, size;
    ssize_t ret = 0;
    char *ptmp;
    int rpc_ring_size = dev->ringEnd - dev->ringStart;

    if (rpc_poll_is_paused) {
        pr_err("RPCpoll: someone access rpc poll during the pause...\n");
        msleep(1000);
        return -EAGAIN;
    }

    PDEBUG("[rpc_poll_write] write rpc_kern_device: caller%x, *buf:0x%x \n", (unsigned int) __read_32bit_caller_register(), *(unsigned int *)buf);
    if (down_interruptible(&dev->ptrSync->writeSem))
        return -ERESTARTSYS;

    if (dev->ringIn == dev->ringOut)
        size = 0;   // the ring is empty
    else if (dev->ringIn > dev->ringOut)
        size = dev->ringIn - dev->ringOut;
    else
        size = rpc_ring_size + dev->ringIn - dev->ringOut;

	if (count > (rpc_ring_size - size - 1))
		goto out;

	temp = dev->ringEnd - dev->ringIn;
	if (temp >= count) {
		if (my_copy_user((int *)dev->ringIn, (int *)buf, count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += count;
		ptmp = dev->ringIn + ((count+3) & 0xfffffffc);

		//moidfy by Angus
		asm("DSB");

		if (ptmp == dev->ringEnd)
			dev->ringIn = dev->ringStart;
		else
			dev->ringIn = ptmp;

    	PDEBUG("RPC Write is in 1st kind...\n");
	} else {
		if (my_copy_user((int *)dev->ringIn, (int *)buf, temp)) {
        	ret = -EFAULT;
			goto out;
		}
		count -= temp;

		if (my_copy_user((int *)dev->ringStart, (int *)(buf+temp), count)) {
        	ret = -EFAULT;
			goto out;
		}
		ret += (temp + count);

		//modify by Angus
		asm("DSB");

		dev->ringIn = dev->ringStart+((count+3) & 0xfffffffc);

    	PDEBUG("RPC Write is in 2nd kind...\n");
	}

out:
    PDEBUG("RPC poll ringIn pointer is : 0x%8x\n", (int)dev->ringIn);
    up(&dev->ptrSync->writeSem);
    return ret;
}

long rpc_poll_ioctl(/*struct inode *inode, */struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
	int ret = 0;

	return ret;
}

#endif //CONFIG_REALTEK_RPC_MULTIPROCESS


int rpc_poll_run(void)
{
	int i;
	RPC_POLL_Dev * rpc_dev = (RPC_POLL_Dev *)phys_to_virt(RPC_POLL_RECORD_ADDR);
	for (i = 0; i < RPC_POLL_DEV_TOTAL; i++)
	{
		if(!(ring_empty((RPC_COMMON_Dev *)(&rpc_dev[i]))))
		{
			printk(KERN_NOTICE "rpc_poll_device(%d) not empty:%d\n",
				i,get_ring_data_size(rpc_dev[i].ringStart,rpc_dev[i].ringEnd,rpc_dev[i].ringIn, rpc_dev[i].ringOut));
			peek_rpc_struct(__func__, (RPC_COMMON_Dev *)(&rpc_dev[i]));
		}
	}
	rpc_poll_is_paused = 0;
	return 0;
}

long rpc_ctrl_ioctl(/*struct inode *inode, */struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
	int ret = 0;

	if (cmd == RPC_IOCTRESET) {
		pr_err("[RPC]start reset...\n");
		rpc_poll_init();
		rpc_intr_init();
		rpc_kern_init();

		// clear the inter-processor interrupts

		#ifdef CONFIG_REALTEK_RPC_KCPU // for platform support KCPU case
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_KV);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_KV2);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_KA);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_KS);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_VK);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_V2K);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_AK);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_SK);
		#endif

		rtd_outl(REG_SB2_CPU_INT, RPC_INT_VA);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_V2A);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_VS);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_V2S);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_AV);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_AV2);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_AS);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_SV);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_SV2);
		rtd_outl(REG_SB2_CPU_INT, RPC_INT_SA);




		*((int *)phys_to_virt(0x000000d0)) = 0xffffffff;
		*((int *)phys_to_virt(0x000000d4)) = 0xffffffff;
		*((int *)phys_to_virt(0x000000d8)) = 0xffffffff;
		flush_sync_flag();

		pr_err("[RPC]done...\n");
	} else {
		pr_err("[RPC]: error ioctl command...\n");
	}

	return ret;
}

int rpc_ctrl_open(struct inode *inode, struct file *filp)
{
	pr_err("[RPC]open for RPC ioctl...\n");

	return 0;          /* success */
}

#ifdef CONFIG_REALTEK_RPC_DEBUG
int rpc_pr_dispatch=0;  /*debug rpc dispatch to the right process*/
int rpc_pr_dispatch_more =0; /*print more information about dispatch*/
int rpc_pr_read =0; /*print read pointer*/
int rpc_pr_write =0; /*wether print write pointer*/
int rpc_pr_type =0; /*print ACPU or VCPU or KCPU information, or both print*/
char rpc_pr_typename[8]; /*record the print type name*/

#ifdef CONFIG_DEBUG_USER_RPC
static void show_block_user_rpc(int index)
{
    DEBUG_RECORD_RPC *rrpc;
    RPC_DEV_EXTRA           *extra;

#ifdef CONFIG_REALTEK_RPC_KCPU
    if (index >= RPC_INTR_DEV_TOTAL) {
        extra = &rpc_intr_kcpu_extra[(index-RPC_INTR_DEV_TOTAL)];
    } else {
        extra = &rpc_intr_extra[index];
    }
#else
    extra = &rpc_intr_extra[index];
#endif

    printk("\n show block rpc:\n");
    list_for_each_entry(rrpc, &extra->blockrpc_list, list){
        printk("%s: program:%lu version:%lu procedure:%lu taskID:%lu sysPID:%lx size:%lu context:%lx, count:%d\n",
        extra->name, rrpc->rpc.programID, rrpc->rpc.versionID, rrpc->rpc.procedureID, rrpc->rpc.taskID,
        rrpc->rpc.sysPID, rrpc->rpc.parameterSize, rrpc->rpc.mycontext, rrpc->tcount);
    }
}
#endif

void show_rpc_buffer(RPC_POLL_Dev *pdev)
{
	RPC_COMMON_Dev *dev = pdev;
	u32 j;

    	printk("\n ringStart: 0x%8x, ringEnd:0x%8x, ringIn: 0x%8x, ringOut: 0x%8x \n", (u32)dev->ringStart,
		(u32)dev->ringEnd, (u32)dev->ringIn, (u32)dev->ringOut);
	printk("ringbuffer info:\n");
	for(j=0;j<RPC_RING_SIZE ;j++)
	{
		if (j%16 == 0) {
			printk("\n%08x :", (u32)(dev->ringStart +j));
		}
		else if(j%4 == 0)
			printk(" ");
		printk("%02x",(unsigned char)*(dev->ringStart +j));
		}
	printk("\n");
    	printk("=============================================\n");

}

static void show_buffer(int index)
{
	int  i, j, type, tmpindex;
	RPC_DEV_EXTRA *extra;
	RPC_POLL_Dev *dev;

	if(index < RPC_POLL_DEV_TOTAL){
		tmpindex = index ;
		for(type = 0; type < 3; type++){
			if(type == 0){ /*dump polling buffer*/
				extra = rpc_poll_extra;
				dev = rpc_poll_devices;
			}
			else if(type ==1){/*dump intr buffer*/
				extra = rpc_intr_extra;
				dev = (RPC_POLL_Dev *)rpc_intr_devices;
			}
			else if(type ==2){ /*dump kern buffer*/
				extra = NULL;
				dev = (RPC_POLL_Dev *)rpc_kern_devices;
			}
			for (i = tmpindex; i < min(RPC_POLL_DEV_TOTAL,(tmpindex+2)); i++){
				if(extra == NULL)
					printk("\n kernel rpc buffer status:\n");
				else
					printk("\n%s buffer status:\n", extra[i].name);
				show_rpc_buffer(dev+i);
			}
		}
	}
#ifdef CONFIG_REALTEK_RPC_KCPU
	else{
		tmpindex = index - RPC_POLL_DEV_TOTAL;
		for(type = 0; type < 3; type++){
			if(type == 0){
				extra = rpc_poll_kcpu_extra;
				dev = rpc_poll_kcpu_devices;
			}
			else if(type ==1){
				extra = rpc_intr_kcpu_extra;
				dev = (RPC_POLL_Dev *)rpc_intr_kcpu_devices;
			}
			else if(type ==2){
				extra = NULL;
				dev = (RPC_POLL_Dev *)rpc_kern_kcpu_devices;
			}
			for (i = tmpindex; i < (tmpindex+2); i++){
				if(extra == NULL)
					printk("\n kernel rpc buffer status:\n");
				else
					printk("\n%s buffer status:\n", extra[i].name);
				show_rpc_buffer(dev+i);
			}
		}
	}
#endif
}
////////////////////////////////////////
/*
* echo dumpa/dumpv1/dumpv2/dumpk >/dev/rpcdebug   dump buffer status
* echo prtyx > /dev/rpcdebug       : setting pr type;
* echo prrp1 > /dev/rpcdebug        : print read pointer
* echo prwp1 > /dev/rpcdebug       :print write pointer
*/
////////////////////////////////////////

ssize_t rpc_debug_write(struct file *filp,
	const char *buf, size_t count, loff_t *f_pos)
{
	long ret = count, rpc_ret;
	char cmd_buf[100] = {0};

	pr_debug("%s(): count=%d, buf=0x%08lx\n", __func__, count, (long)buf);

	if (count >= 100)
		return -EFAULT;

	if (copy_from_user(cmd_buf, buf, count)){
		ret = -EFAULT;
	}

	if ((cmd_buf[0] == 'd') && (cmd_buf[1] == 'u') && (cmd_buf[2] == 'm') && (cmd_buf[3] == 'p')) {
		if(cmd_buf[4] == 'a'){
			show_buffer(0);
		}
		else if((cmd_buf[4] == 'v') &&(cmd_buf[5] == '1')){
			show_buffer(2);
		}
 #ifdef CONFIG_REALTEK_RPC_VCPU2
		else if((cmd_buf[4] == 'v') &&(cmd_buf[5] == '2')){
			show_buffer(4);
		}
 #endif
		else if(cmd_buf[4] == 'k'){
			show_buffer(6);
		}		
	}
#ifdef CONFIG_DEBUG_USER_RPC
	else if ((cmd_buf[0] == 's') && (cmd_buf[1] == 'h') && (cmd_buf[2] == 'q') && (cmd_buf[3] == 'e')) {
		if(cmd_buf[4] == 'a'){
			show_block_user_rpc(1);
		}
		else if((cmd_buf[4] == 'v') &&(cmd_buf[5] == '1')){
			show_block_user_rpc(3);
		}
#ifdef CONFIG_REALTEK_RPC_VCPU2
		else if((cmd_buf[4] == 'v') &&(cmd_buf[5] == '2')){
			show_block_user_rpc(5);
		}
#endif
		else if((cmd_buf[4] == 'k') ){
			show_block_user_rpc(7);
		}		
	}
#endif
	else if((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') && (cmd_buf[2] == 't') && (cmd_buf[3] == 'y')){/*set log level*/
		if(cmd_buf[4] == '0'){
			rpc_pr_type =0;
			rpc_pr_typename[0] = '\0';
		}
		else if(cmd_buf[4] == '1'){ /*print log related to audio*/
			rpc_pr_type =1;
            strncpy(rpc_pr_typename, "Audio", 8);
		}
		else if(cmd_buf[4] == '2'){/*print log related to video1*/
			rpc_pr_type =2;
            strncpy(rpc_pr_typename, "Video1", 8);
		}
#ifdef CONFIG_REALTEK_RPC_VCPU2
		else if(cmd_buf[4] == '3'){/*print log related to video2*/
			rpc_pr_type =3;
            strncpy(rpc_pr_typename, "Video2", 8);
		}
#endif
		else if(cmd_buf[4] == '4'){/*print log related to kcpu*/
			rpc_pr_type =4;
            strncpy(rpc_pr_typename, "KCPU", 8);
		}
		else if(cmd_buf[4] == '5'){/*print all the log*/
			rpc_pr_type =5;
			rpc_pr_typename[0] = '\0';
		}		
	}
	else if((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') && (cmd_buf[2] == 'd') && (cmd_buf[3] == 'p')){
		if(cmd_buf[4] == '0'){
			rpc_pr_dispatch = 0;
		}
		else if(cmd_buf[4] == '1'){
			rpc_pr_dispatch =1;
		}
		
	}
	else if((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') && (cmd_buf[2] == 'd') && (cmd_buf[3] == 'p')&& (cmd_buf[4] == 'm')){
		if(cmd_buf[5] == '0'){
			rpc_pr_dispatch_more =0;
		}
		else if(cmd_buf[5] == '1'){
			rpc_pr_dispatch_more =1;
		}
	}
	else if((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') && (cmd_buf[2] == 'r') && (cmd_buf[3] == 'p')){
		if(cmd_buf[4] == '0'){
			rpc_pr_read =0;
		}
		else if(cmd_buf[4] == '1'){
			rpc_pr_read =1;
		}
	}
	else if((cmd_buf[0] == 'p') && (cmd_buf[1] == 'r') && (cmd_buf[2] == 'w') && (cmd_buf[3] == 'p')){
		if(cmd_buf[4] == '0'){
			rpc_pr_write =0;
		}
		else if(cmd_buf[4] == '1'){
			rpc_pr_write =1;
		}
		
	}
	else if((cmd_buf[0] == 'k') && (cmd_buf[1] == 'c') && (cmd_buf[2] == 'p') && (cmd_buf[3] == 'u')&&
		(cmd_buf[4] == '@') && (cmd_buf[5] == 'r') && (cmd_buf[6] == 'p') && (cmd_buf[7] == 'c')){
		if(send_rpc_command(RPC_KCPU,RPC_SCPU_DEBUG_COMMAND, 0, 0, &rpc_ret) == RPC_OK)
			printk("send debug kernel rpc to kcpu success(%d).\n", rpc_ret);
		else
			printk("send debug kernel rpc to kcpu failed(%d).\n", rpc_ret);
	}
	
	return ret;
}

long rpc_debug_ioctl(/*struct inode *inode, */struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
	//int ret = 0;

	if (cmd == RPC_IOCTRESET) {

	}
	return 0;
}

int rpc_debug_open(struct inode *inode, struct file *filp)
{
	pr_err("[RPC]open for RPC debug...\n");

	return 0;          /* success */
}
#endif

struct file_operations rpc_poll_fops = {
//    llseek:     scull_llseek,
    .unlocked_ioctl=	rpc_poll_ioctl,
    .read=				rpc_poll_read,
    .write=				rpc_poll_write,
    .open=				rpc_poll_open,
    .release=			rpc_poll_release,
};

struct file_operations rpc_ctrl_fops = {
    .unlocked_ioctl=	rpc_ctrl_ioctl,
    .open=				rpc_ctrl_open,
};

#ifdef CONFIG_REALTEK_RPC_DEBUG
struct file_operations rpc_debug_fops = {
    .unlocked_ioctl=	rpc_debug_ioctl,
    .open=				rpc_debug_open,
    .write =  rpc_debug_write,

};
#endif
