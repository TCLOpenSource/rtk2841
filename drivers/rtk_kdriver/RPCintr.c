/*
 * $Id: RPCintr.c,v 1.10 2004/8/4 09:25 Jacky Exp $
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
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/freezer.h>
#include <rtk_kdriver/RPCDriver.h>

#include <asm/io.h>
//#include <asm/system.h>     /* cli(), *_flags */
#include <asm/uaccess.h>    /* copy_to_user() copy_from_user() */

RPC_INTR_Dev *rpc_intr_devices;
#ifdef CONFIG_REALTEK_RPC_KCPU
RPC_INTR_Dev *rpc_intr_kcpu_devices;
#endif
int rpc_intr_is_paused = 0;

int timeout = HZ/40; // jiffies

#ifdef CONFIG_REALTEK_RPC_MULTIPROCESS

RPC_DEV_EXTRA rpc_intr_extra[RPC_NR_DEVS/RPC_NR_PAIR];
#ifdef CONFIG_REALTEK_RPC_KCPU
RPC_DEV_EXTRA rpc_intr_kcpu_extra[RPC_NR_KCPU_DEVS/RPC_NR_PAIR];
#endif
int rpc_pr_pid_debug = 0;
void _show_buffer(RPC_DEV_EXTRA *extra)
{
    RPC_COMMON_Dev *dev = extra->dev;
    u32 *data;
    u32 i;


    EMERG_DEBUG("show_buffer(0x%8x, 0x%8x) InOut(0x%8x, 0x%8x)\n",
        (u32)dev->ringStart,(u32)dev->ringEnd, (u32)dev->ringIn, (u32)dev->ringOut);

    data = (u32 *)dev->ringStart;

    for ( i = 0 ; i < RPC_RING_SIZE ; i+=16)
    {
        EMERG_DEBUG("%p: %08x %08x %08x %08x\n", data, ntohl(data[0]), ntohl(data[1]), ntohl(data[2]), ntohl(data[3]));
        data += 4;
    }
    EMERG_DEBUG("=============================================\n");

}
void _show_dispatch_stuck(RPC_DEV_EXTRA *extra, int line)
{

    extra->not_handle_count++;
    if (extra->not_handle_count > 5 && extra->not_handle_count < 10 ) {
        EMERG_DEBUG("dispatch nothandle %d\n", line);
        _show_buffer(extra);
    }
}


static ssize_t _rpc_intr_write(int minor, const char *buf, size_t count)

{
	int temp;
	ssize_t ret = 0;
	char *ptmp;
	RPC_INTR_Dev *dev;

	dev = &rpc_intr_devices[minor/RPC_NR_PAIR];

	if (down_interruptible(&dev->ptrSync->writeSem))
	        return -ERESTARTSYS;

	temp = dev->ringEnd - dev->ringIn;
	if (temp >= count) {
	        if(my_copy_user((int *)dev->ringIn, (int *)buf, count)){
	                ret = -EFAULT;
	                goto out;
	        }
	        ret += count;
	        ptmp = dev->ringIn + ((count+3) & 0xfffffffc);

            dsb(sy);

	        if (ptmp == dev->ringEnd)
	                dev->ringIn = dev->ringStart;
	        else
	                dev->ringIn = ptmp;

	        PDEBUG("RPC Write is in 1st kind...\n");
	} else {
	        if(my_copy_user((int *)dev->ringIn, (int *)buf, temp)){
	                ret = -EFAULT;
	                goto out;
	        }
	        count -= temp;

	        if(my_copy_user((int *)dev->ringStart, (int *)(buf+temp), count)){
	                ret = -EFAULT;
	                goto out;
	        }
	        ret += (temp + count);

            dsb(sy);

	        dev->ringIn = dev->ringStart+((count+3) & 0xfffffffc);

	        PDEBUG("RPC Write is in 2nd kind...\n");
	}

	temp = minor;	/* use the "f_pos" of file object to store the device number */
	if (temp == (RPC_INTR_DEV_SA_ID0*RPC_NR_PAIR+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SA | RPC_INT_WRITE_1));
	else if (temp == (RPC_INTR_DEV_SV1_ID2*RPC_NR_PAIR+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV | RPC_INT_WRITE_1));
	else if (temp == (RPC_INTR_DEV_SV2_ID4*RPC_NR_PAIR+1))
#ifndef CONFIG_REALTEK_RPC_VCPU2
		BUG();
#else
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV2 | RPC_INT_WRITE_1));
#endif
#ifdef CONFIG_REALTEK_RPC_KCPU
	else if (temp == (RPC_INTR_DEV_SK_ID0*RPC_NR_PAIR+RPC_NR_DEVS+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SK | RPC_INT_WRITE_1));
#endif
	else
		pr_err("error device number...\n");

out:
        pr_err("RPC intr ringIn pointer is : 0x%8x, minor = %d\n", (int)dev->ringIn,minor);
        up(&dev->ptrSync->writeSem);
        return ret;
}

static inline void rpc_unhandle_packet(RPC_PROCESS *proc, char *out, int minor)
{
       RPC_DEV_EXTRA *extra = proc->extra;
       RPC_STRUCT rpc;
       REPLY_RPC_STRUCT reply_rpc;
       out = get_ring_data(extra->name, extra->dev, out, (char *)&rpc, sizeof(RPC_STRUCT));
       if (out) {
               convert_rpc_struct(extra->name, &rpc);
               pr_err("%s-rpc(%p),program:%lu version:%lu procedure:%lu taskID:%lu sysPID:%lx size:%lu context:%lx %s\n",
                       extra->name, out, rpc.programID, rpc.versionID, rpc.procedureID, rpc.taskID, rpc.sysPID, rpc.parameterSize,
                       rpc.mycontext, in_atomic() ? "atomic" : "");

	       if ((rpc.programID == AUDIO_AGENT) || (rpc.programID == VIDEO_AGENT)){
		   	if(rpc.taskID){	//for blocking mode RPC request
				reply_rpc.rpc.programID = htonl(REPLYID);
				reply_rpc.rpc.versionID = htonl(REPLYID);
				reply_rpc.rpc.procedureID = 0;
				reply_rpc.rpc.mycontext = htonl(rpc.mycontext);
				reply_rpc.rpc.taskID = 0;
	               	reply_rpc.rpc.sysPID = 0;
			  	reply_rpc.rpc.parameterSize = htonl(2*sizeof(unsigned long));

				reply_rpc.req_taskID = htonl(rpc.taskID);
	               	reply_rpc.replay_result = htonl(0x20010001);
	               	_rpc_intr_write(minor, (char *)&reply_rpc, sizeof(REPLY_RPC_STRUCT));
				pr_err("%s send reply to rpc-%d \n", extra->name, minor);
		   	}
	       }
	}

}

//This function may be called by tasklet and rpc_intr_read(), rpc_poll_read()

int print_count = 0;
void rpc_dispatch(unsigned long data)
{
        RPC_DEV_EXTRA *extra = (RPC_DEV_EXTRA *)data;
        RPC_COMMON_Dev *dev = extra->dev;
        RPC_PROCESS *proc = NULL;
        char *out;
        RPC_STRUCT rpc;
        int found = 0;
        unsigned long taskID = 0;
        int state = 0;


        PDEBUG("==*==*==*==*== %s Out:%p next:%p In:%p size:%d %s==*==*==*==*==\n", extra->name, dev->ringOut, extra->nextRpc, dev->ringIn, get_ring_data_size(dev->ringStart, dev->ringEnd, dev->ringIn, dev->ringOut), in_atomic() ? "atomic" : "");

        if(ring_empty(dev)){
                if(!rpc_done(extra)){
                        update_nextRpc(extra, dev->ringOut);
                        PDEBUG("%s:%d No data, update nextRpc:%p\n", extra->name, __LINE__, extra->nextRpc);
                }
                return;
        }

        if(!rpc_done(extra)){
                PDEBUG("%s:%d prev RPC hasn't finished. Out:%p next:%p In:%p\n", extra->name, __LINE__, dev->ringOut, extra->nextRpc, dev->ringIn);
                return;
        }

        //peek_rpc_struct(extra->name, dev);
        out = dev->ringOut;
        out = get_ring_data(extra->name, dev, out, (char *)&rpc, sizeof(RPC_STRUCT));
        if(out == NULL) {
            _show_dispatch_stuck(extra,__LINE__);
            return;
        }

        convert_rpc_struct(extra->name, &rpc);
#ifdef CONFIG_REALTEK_RPC_DEBUG
        //show_rpc_struct(extra->name, &rpc);
        if(is_pr_type_match( extra->name))
        {
        PDEBUGD("%s: program:%lu version:%lu procedure:%lu taskID:%lu sysPID:%lx size:%lu context:%lx %s\n",
		extra->name, rpc.programID, rpc.versionID, rpc.procedureID, rpc.taskID, rpc.sysPID, rpc.parameterSize,
		rpc.mycontext, in_atomic() ? "atomic" : "");
        }
#endif
        //BUG_ON(rpc.programID != R_PROGRAM && rpc.programID != REPLYID && rpc.programID != AUDIO_AGENT && rpc.programID != VIDEO_AGENT);


        extra->footprint = 0;
        if(rpc.programID == R_PROGRAM){
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
                proc = pick_supported_proc(extra, rpc.programID,0,0,0);
#else
                proc = pick_one_proc(extra);
#endif
        /*}else if(rpc.programID == AUDIO_AGENT || rpc.programID == VIDEO_AGENT){
                proc = NULL;
                if(likely(rpc.sysPID != 0xFFFFFFFF))
                        proc = lookup_by_taskID(extra, rpc.sysPID);
                if(unlikely(proc == NULL)){
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
                        proc = pick_supported_proc(extra, rpc.programID);
#else
                        proc = pick_one_proc(extra);
#endif
                }*/
        }else if(rpc.programID == REPLYID && rpc.versionID == REPLYID && rpc.parameterSize >= sizeof(unsigned long)){

                if(get_ring_data(extra->name, dev, out, (char *)&taskID, sizeof(unsigned long)) == NULL)
                        return;

                taskID = ntohl(taskID);
#ifdef CONFIG_REALTEK_RPC_DEBUG
		   if(is_pr_type_match( extra->name))
                {
		       PDEBUGD("%s:%d taskID:%lu\n", extra->name, __LINE__, taskID);
		   }
#endif
                proc = lookup_by_taskID(extra, taskID, &state, 0);
#ifdef CONFIG_DEBUG_USER_RPC
		release_block_rpc(extra, taskID);
#endif
        }else{
                    int print_message = 0;
                    if(rpc.programID == AUDIO_AGENT) print_message = 1;

	                proc = NULL;

	                if(likely(rpc.sysPID != 0xFFFFFFFF))
	                        proc = lookup_by_taskID(extra, rpc.sysPID, &state, print_message);

	                if(unlikely(proc == NULL)){
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
	                        proc = pick_supported_proc(extra, rpc.programID,rpc.sysPID, state, print_message);
#else
	                        proc = pick_one_proc(extra);
#endif
	                }
					if(rpc.programID == AUDIO_AGENT) {
                        if (proc && (int)proc->pid != (int)rpc.sysPID )
                            EMERG_DEBUG("found pid = %d, sysPID = %d, taskID = 0x%lx, programID = %d, procedureID = %d, footprint=%x\n",(proc) ? proc->pid:-1,(int)rpc.sysPID,rpc.taskID, (int)rpc.programID,(int)rpc.procedureID,extra->footprint);
                    }

        }

        if (proc) {
                found = 1;
                extra->not_handle_count  = 0;
        } else {
#ifdef CONFIG_REALTEK_RPC_DEBUG
		if(is_pr_type_match( extra->name))
        	{
			PDEBUGD("%s:%d can't find process for handling %s programID:%lu \n", extra->name, __LINE__, extra->name, rpc.programID);
			if(rpc.programID == REPLYID)
				PDEBUGD("%s:%d, taskID:%lu \n", extra->name, __LINE__, taskID);
		}
#endif
        }

        out += rpc.parameterSize;
        if (out >= dev->ringEnd)
                out = dev->ringStart + (out - dev->ringEnd);

        if (found) {
                update_nextRpc(extra, out);
                update_currProc(extra, proc);
                wake_up_interruptible(&proc->waitQueue);
#ifdef CONFIG_REALTEK_RPC_DEBUG
		if(is_pr_type_match( extra->name))
        	{
			PDEBUGD("%s:%d Wakeup process:%d and update nextRpc:%p for programID:%lu\n", extra->name, __LINE__, proc->pid, extra->nextRpc, rpc.programID);
		}
#endif
        } else {
            if((rpc.programID == REPLYID)&&( rpc.versionID == REPLYID)){
                if(!is_taskID_alive(taskID)){
                    update_nextRpc(extra, out);
                    dev->ringOut = extra->nextRpc;
                    EMERG_DEBUG("%s:%d drop an ack taskID:%lu that send to a died AP, update nextRpc:%p for programID:%lu\n", extra->name, __LINE__, taskID, extra->nextRpc, rpc.programID);
                }
            }
            else {
                EMERG_DEBUG("%s:footprint(%x)\n", extra->name, extra->footprint);
                _show_dispatch_stuck(extra,__LINE__);
            }

            update_currProc(extra, NULL);
        }
}

int rpc_intr_init(void)
{
	static int is_init = 0;
	int result = 0, i;

	// Create corresponding structures for each device.
	rpc_intr_devices = (RPC_INTR_Dev *)phys_to_virt(RPC_INTR_RECORD_ADDR);

	for (i = 0; i < RPC_INTR_DEV_TOTAL; i++) {
		PDEBUG("rpc_intr_device %d addr: %x \n", i, (unsigned)&rpc_intr_devices[i]);
		rpc_intr_devices[i].ringBuf = (char *)(phys_to_virt(RPC_INTR_DEV_ADDR + i*RPC_RING_SIZE*2));

		// Initialize pointers...
		rpc_intr_devices[i].ringStart = rpc_intr_devices[i].ringBuf;
		rpc_intr_devices[i].ringEnd = rpc_intr_devices[i].ringBuf+RPC_RING_SIZE;
		rpc_intr_devices[i].ringIn = rpc_intr_devices[i].ringBuf;
		rpc_intr_devices[i].ringOut = rpc_intr_devices[i].ringBuf;

		PDEBUG("The %dth RPC_INTR_Dev:\n", i);
		PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_intr_devices[i].ringStart);
		PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_intr_devices[i].ringEnd);
		PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_intr_devices[i].ringIn);
		PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_intr_devices[i].ringOut);
		PDEBUG("\n");

		rpc_intr_extra[i].nextRpc = rpc_intr_devices[i].ringOut;
		rpc_intr_extra[i].currProc = NULL;

		if (!is_init) {
			rpc_intr_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

			// Initialize wait queue...
			init_waitqueue_head(&(rpc_intr_devices[i].ptrSync->waitQueue));

			// Initialize sempahores...
			sema_init(&rpc_intr_devices[i].ptrSync->readSem, 1);
			sema_init(&rpc_intr_devices[i].ptrSync->writeSem, 1);

			rpc_intr_extra[i].dev = (void *)&rpc_intr_devices[i];
			INIT_LIST_HEAD(&rpc_intr_extra[i].tasks);
#ifdef CONFIG_DEBUG_USER_RPC
			INIT_LIST_HEAD(&rpc_intr_extra[i].blockrpc_list);
#endif
			tasklet_init(&rpc_intr_extra[i].tasklet, rpc_dispatch, (unsigned long)&rpc_intr_extra[i]);
			spin_lock_init(&rpc_intr_extra[i].lock);
			switch(i){
				case 0: rpc_intr_extra[i].name = "AudioIntrWrite"; break;
				case 1: rpc_intr_extra[i].name = "AudioIntrRead"; break;
				case 2: rpc_intr_extra[i].name = "Video1IntrWrite"; break;
				case 3: rpc_intr_extra[i].name = "Video1IntrRead"; break;
				case 4: rpc_intr_extra[i].name = "Video2IntrWrite"; break;
				case 5: rpc_intr_extra[i].name = "Video2IntrRead"; break;
			}
		}
	}

#ifdef CONFIG_REALTEK_RPC_KCPU
	// Create corresponding structures for each device.
	rpc_intr_kcpu_devices = (RPC_INTR_Dev *)phys_to_virt(RPC_INTR_KCPU_RECORD_ADDR);

	for (i = 0; i < RPC_INTR_DEV_KCPU_TOTAL; i++) {
		PDEBUG("rpc_intr_kcpu_device %d addr: %x \n", i, (unsigned)&rpc_intr_kcpu_devices[i]);

		rpc_intr_kcpu_devices[i].ringBuf = (char *)(phys_to_virt(RPC_INTR_KCPU_DEV_ADDR + i*RPC_KCPU_RING_SIZE*2));

		// Initialize pointers...
		rpc_intr_kcpu_devices[i].ringStart = rpc_intr_kcpu_devices[i].ringBuf;
		rpc_intr_kcpu_devices[i].ringEnd = rpc_intr_kcpu_devices[i].ringBuf+RPC_KCPU_RING_SIZE;
		rpc_intr_kcpu_devices[i].ringIn = rpc_intr_kcpu_devices[i].ringBuf;
		rpc_intr_kcpu_devices[i].ringOut = rpc_intr_kcpu_devices[i].ringBuf;

		PDEBUG("The %dth RPC_INTR_Dev:\n", i);
		PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_intr_kcpu_devices[i].ringStart);
		PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_intr_kcpu_devices[i].ringEnd);
		PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_intr_kcpu_devices[i].ringIn);
		PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_intr_kcpu_devices[i].ringOut);
		PDEBUG("\n");

		rpc_intr_kcpu_extra[i].nextRpc = rpc_intr_kcpu_devices[i].ringOut;
		rpc_intr_kcpu_extra[i].currProc = NULL;

		if (!is_init) {
			rpc_intr_kcpu_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

			// Initialize wait queue...
			init_waitqueue_head(&(rpc_intr_kcpu_devices[i].ptrSync->waitQueue));

			// Initialize sempahores...
			sema_init(&rpc_intr_kcpu_devices[i].ptrSync->readSem, 1);
			sema_init(&rpc_intr_kcpu_devices[i].ptrSync->writeSem, 1);

			rpc_intr_kcpu_extra[i].dev = (void *)&rpc_intr_kcpu_devices[i];
			INIT_LIST_HEAD(&rpc_intr_kcpu_extra[i].tasks);
#ifdef CONFIG_DEBUG_USER_RPC
			INIT_LIST_HEAD(&rpc_intr_kcpu_extra[i].blockrpc_list);
#endif
			tasklet_init(&rpc_intr_kcpu_extra[i].tasklet, rpc_dispatch, (unsigned long)&rpc_intr_kcpu_extra[i]);
			spin_lock_init(&rpc_intr_kcpu_extra[i].lock);
			switch(i){
				case 0: rpc_intr_kcpu_extra[i].name = "KCPUIntrWrite"; break;
				case 1: rpc_intr_kcpu_extra[i].name = "KCPUIntrRead"; break;
			}
		}
	}
#endif

	is_init = 1;
	rpc_intr_is_paused = 0;

//fail:
	return result;
}

int rpc_intr_pause(void)
{
	rpc_intr_is_paused = 1;

	return 0;
}

void rpc_intr_cleanup(void)
{
	int i;

	// Clean corresponding structures for each device.
	if (rpc_intr_devices) {
		// Clean ring buffers.
		for (i = 0; i < RPC_INTR_DEV_TOTAL; i++) {
//			if (rpc_intr_devices[i].ringBuf)
//				kfree(rpc_intr_devices[i].ringBuf);
			kfree(rpc_intr_devices[i].ptrSync);
		}

//		kfree(rpc_intr_devices);
	}

	return;
}

int rpc_intr_open(struct inode *inode, struct file *filp)
{
	int minor = MINOR(inode->i_rdev);

	PDEBUG("RPC intr open with minor number: %d\n", minor);

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
			proc->dev = (RPC_COMMON_Dev *)&rpc_intr_kcpu_devices[(minor-RPC_NR_DEVS)/RPC_NR_PAIR];
			proc->extra = &rpc_intr_kcpu_extra[(minor-RPC_NR_DEVS)/RPC_NR_PAIR];
		} else {
			proc->dev = (RPC_COMMON_Dev *)&rpc_intr_devices[minor/RPC_NR_PAIR];
			proc->extra = &rpc_intr_extra[minor/RPC_NR_PAIR];
		}
#else
		proc->dev = (RPC_COMMON_Dev *)&rpc_intr_devices[minor/RPC_NR_PAIR];
		proc->extra = &rpc_intr_extra[minor/RPC_NR_PAIR];
#endif

		proc->pid = current->tgid; //current->tgid = process id, current->pid = thread id
		init_waitqueue_head(&proc->waitQueue);
		INIT_LIST_HEAD(&proc->threads);
#ifdef CONFIG_REALTEK_RPC_PROGRAM_REGISTER
		INIT_LIST_HEAD(&proc->handlers);
#endif
        tasklet_disable(&proc->extra->tasklet);
        spin_lock_bh(&proc->extra->lock);
		list_add(&proc->list, &proc->extra->tasks);
        spin_unlock_bh(&proc->extra->lock);
        tasklet_enable(&proc->extra->tasklet);

		filp->private_data = proc;
		filp->f_pos = (loff_t)minor;
        }

//	MOD_INC_USE_COUNT; /* Before we maybe sleep */

	return 0;          /* success */
}

int rpc_intr_release(struct inode *inode, struct file *filp)
{
	int minor = MINOR(inode->i_rdev);

	RPC_PROCESS *proc = filp->private_data;
	RPC_INTR_Dev *dev = (RPC_INTR_Dev *)proc->dev; /* the first listitem */
	RPC_DEV_EXTRA *extra = proc->extra;



	if(extra->currProc == proc){
		PDEBUG("%s: clear %s(%p) current process\n", __func__, proc->extra->name, dev);
		update_currProc(extra, NULL);
		if(minor == 3 || minor == 7 || minor == 11
#ifdef CONFIG_REALTEK_RPC_KCPU
			||minor == 15
#endif
		){ //intr read device (ugly code)
			if(!rpc_done(extra)){
				EMERG_DEBUG("%s: pid: %d,previous rpc hasn't finished, force clear!! ringOut %p => %p\n", extra->name,proc->pid, dev->ringOut, extra->nextRpc);
				if(minor ==3)
					rtd_outl(DUMP_AUDIO_BUFFER_DUMMY_REGISTER, 0xC0DE0002);
				//show_queued_rpc(extra, dev->ringOut);
				rpc_unhandle_packet(proc, dev->ringOut, minor-2);
				if (down_interruptible(&dev->ptrSync->readSem))
					return -ERESTARTSYS;
				dev->ringOut = extra->nextRpc;
				up(&dev->ptrSync->readSem);

			}
		}
	}

    tasklet_disable(&extra->tasklet);
    spin_lock_bh(&extra->lock);

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
	list_del(&proc->list);
	kfree(proc);
	spin_unlock_bh(&extra->lock);
	tasklet_enable(&extra->tasklet);

	PDEBUG("RPC intr close with minor number: %d\n", minor);

//	MOD_DEC_USE_COUNT;

	return 0;          /* success */
}

// We don't need parameter f_pos here...
// note: rpc_intr_read support both blocking & nonblocking modes
ssize_t rpc_intr_read(struct file *filp, char *buf, size_t count,
                loff_t *f_pos)
{
        RPC_PROCESS *proc = filp->private_data;
        RPC_INTR_Dev *dev = (RPC_INTR_Dev *)proc->dev; /* the first listitem */
        RPC_DEV_EXTRA *extra = proc->extra;
        int temp, size;
        ssize_t ret = 0;
        char *ptmp;
        int rpc_ring_size = dev->ringEnd - dev->ringStart;


        PDEBUG("%s:%d thread:%s pid:%d tgid:%d device:%s\n", __func__, __LINE__, current->comm, current->pid, current->tgid, extra->name);
        if (rpc_intr_is_paused) {
                pr_err("RPCintr: someone access rpc intr during the pause...\n");
                msleep(1000);
                return -EAGAIN;
        }

        if (need_dispatch(extra)) {
                tasklet_disable(&extra->tasklet);
                spin_lock_bh(&extra->lock);
                if (need_dispatch(extra)) {
                        rpc_dispatch((unsigned long)extra);
                }
                spin_unlock_bh(&extra->lock);
                tasklet_enable(&extra->tasklet);
        }

        PDEBUG("%s: dev:%s(%p) currProc:%p\n", __func__, extra->name, dev, extra->currProc);
        if ((extra->currProc != proc) || (ring_empty((RPC_COMMON_Dev *)dev))) {
                if (filp->f_flags & O_NONBLOCK)
                        goto done;
wait_again:
                if (wait_event_interruptible_timeout(proc->waitQueue,
			(extra->currProc == proc) && (!ring_empty((RPC_COMMON_Dev *)dev)), timeout) == 0)
                        goto done; /* timeout */

//              if (current->flags & PF_FREEZE) {
//                      refrigerator(PF_FREEZE);
//                      if (!signal_pending(current))
//                              goto wait_again;
//              }
                if (try_to_freeze()) {
                        if (!signal_pending(current))
                                goto wait_again;
                }

                if (signal_pending(current)) {
                        PDEBUG("RPC deblock because of receiving a signal...\n");
                        goto done;
                }
        }

        if (down_interruptible(&dev->ptrSync->readSem))
                return -ERESTARTSYS;

        if (dev->ringIn > dev->ringOut)
                size = dev->ringIn - dev->ringOut;
        else
                size = rpc_ring_size + dev->ringIn - dev->ringOut;

#ifdef CONFIG_REALTEK_RPC_DEBUG
	 if(is_pr_type_match( extra->name))
        {
        	PDEBUGR("%s: %s: count:%d size:%d\n", __func__, extra->name, count, size);
	 }
#endif
        //peek_rpc_struct(__func__, dev);
        if (count > size){
                //count = size;
                goto out;
        }

        temp = dev->ringEnd - dev->ringOut;
        if (temp >= count) {
                if (my_copy_to_user((int *)buf, (int *)dev->ringOut, count)) {
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
	up(&dev->ptrSync->readSem);

        /* NOTE: we do not need spin lock here because we are protected by semaphore already */
	/*has race condition, so we need spin lock here*/
        tasklet_disable(&extra->tasklet);
	spin_lock_bh(&extra->lock);	
        if (rpc_done(extra)) {
                PDEBUG("%s: Previous RPC is done, unregister myself\n", __func__);
                update_currProc(extra, NULL);
        }

        //process next rpc command if any
        if (need_dispatch(extra)) {
		rpc_dispatch((unsigned long)extra);
	}
	spin_unlock_bh(&extra->lock);
        tasklet_enable(&extra->tasklet);
#ifdef CONFIG_REALTEK_RPC_DEBUG
	if(is_pr_type_match( extra->name))
	{
		PDEBUGR("RPC intr ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
		PDEBUGR("%s:%d pid:%d reads %d bytes\n", extra->name, __LINE__, current->pid, ret);
	}
#endif
	goto done;

out:
        up(&dev->ptrSync->readSem);
done:
        PDEBUG("RPC intr ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
        PDEBUG("%s:%d pid:%d reads %d bytes\n", extra->name, __LINE__, current->pid, ret);
        return ret;
}

// We don't need parameter f_pos here...
// note: rpc_intr_write only support nonblocking mode
ssize_t rpc_intr_write(struct file *filp, const char *buf, size_t count,
                loff_t *f_pos)
{
        RPC_PROCESS *proc = filp->private_data;
        RPC_INTR_Dev *dev = (RPC_INTR_Dev *)proc->dev; /* the first listitem */
        RPC_DEV_EXTRA *extra = proc->extra;
        RPC_DEV_EXTRA *rextra = extra + 1;
        int temp, size;
        ssize_t ret = 0;
        char *ptmp;
        int rpc_ring_size = dev->ringEnd - dev->ringStart;

        if (rpc_intr_is_paused) {
                pr_err("RPCintr: someone access rpc intr during the pause...\n");
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

                EMERG_DEBUG("rpc_intr_write(%s) pid = %d, tgid = %d,current->tgid is not equal to proc->pid\n",extra->name,proc->pid, current->tgid);
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

        		//modify by Angus
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

        		//modify by Angus
        		dsb(sy);

                dev->ringIn = dev->ringStart+((count+3) & 0xfffffffc);

                PDEBUG("RPC Write is in 2nd kind...\n");
        }

        //peek_rpc_struct(extra->name, dev);
#ifdef CONFIG_DEBUG_USER_RPC
        record_block_rpc((unsigned long)extra, (RPC_COMMON_Dev *)dev);
#endif
        // notify all the processes in the wait queue
        //      wake_up_interruptible(&dev->waitQueue);
	temp = (int)*f_pos;	/* use the "f_pos" of file object to store the device number */
	if (temp == (RPC_INTR_DEV_SA_ID0*RPC_NR_PAIR+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SA | RPC_INT_WRITE_1));
	else if (temp == (RPC_INTR_DEV_SV1_ID2*RPC_NR_PAIR+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV | RPC_INT_WRITE_1));
	else if (temp == (RPC_INTR_DEV_SV2_ID4*RPC_NR_PAIR+1)){
#ifdef CONFIG_REALTEK_RPC_VCPU2
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV2 | RPC_INT_WRITE_1));		
#else
		BUG();
#endif
	}
#ifdef CONFIG_REALTEK_RPC_KCPU
	else if (temp == (RPC_INTR_DEV_SK_ID0*RPC_NR_PAIR+RPC_NR_DEVS+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SK | RPC_INT_WRITE_1));
#endif
	else
		pr_err("error device number...\n");

out:
#ifdef CONFIG_REALTEK_RPC_DEBUG
	 if(is_pr_type_match( extra->name))
        {
		PDEBUGW("RPC intr ringIn pointer is : 0x%8x\n", (int)dev->ringIn);
	 }
#endif
        up(&dev->ptrSync->writeSem);
        return ret;
}

long rpc_intr_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
        int ret = 0;

    switch(cmd) {
        case RPC_IOCTTIMEOUT:
                timeout = arg;
                break;
        case RPC_IOCQTIMEOUT:
                return timeout;
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
        default:  /* redundant, as cmd was checked against MAXNR */
                pr_err("%s:%d unsupported ioctl cmd:%x arg:%lx\n", __func__, __LINE__, cmd, arg);
                return -ENOTTY;
        }

        return ret;
}

#else

int rpc_intr_init(void)
{
	static int is_init = 0;
	int result = 0, i;

    // Create corresponding structures for each device.
    rpc_intr_devices = (RPC_INTR_Dev *)phys_to_virt(RPC_INTR_RECORD_ADDR);

    for (i = 0; i < RPC_INTR_DEV_TOTAL; i++) {
        PDEBUG("rpc_intr_device %d addr: %x \n", i, (unsigned)&rpc_intr_devices[i]);
        rpc_intr_devices[i].ringBuf = (char *)(phys_to_virt(RPC_INTR_DEV_ADDR + i*RPC_RING_SIZE*2));

        // Initialize pointers...
        rpc_intr_devices[i].ringStart = rpc_intr_devices[i].ringBuf;
        rpc_intr_devices[i].ringEnd = rpc_intr_devices[i].ringBuf+RPC_RING_SIZE;
        rpc_intr_devices[i].ringIn = rpc_intr_devices[i].ringBuf;
        rpc_intr_devices[i].ringOut = rpc_intr_devices[i].ringBuf;

        PDEBUG("The %dth RPC_INTR_Dev:\n", i);
        PDEBUG("RPC ringStart: 0x%8x\n", (int)rpc_intr_devices[i].ringStart);
        PDEBUG("RPC ringEnd:   0x%8x\n", (int)rpc_intr_devices[i].ringEnd);
        PDEBUG("RPC ringIn:    0x%8x\n", (int)rpc_intr_devices[i].ringIn);
        PDEBUG("RPC ringOut:   0x%8x\n", (int)rpc_intr_devices[i].ringOut);
        PDEBUG("\n");

        if (!is_init) {
		rpc_intr_devices[i].ptrSync = kmalloc(sizeof(RPC_SYNC_Struct), GFP_KERNEL);

	        // Initialize wait queue...
	        init_waitqueue_head(&(rpc_intr_devices[i].ptrSync->waitQueue));

	        // Initialize sempahores...
	        sema_init(&rpc_intr_devices[i].ptrSync->readSem, 1);
	        sema_init(&rpc_intr_devices[i].ptrSync->writeSem, 1);
        }
    }

    is_init = 1;
    rpc_intr_is_paused = 0;

//fail:
    return result;
}

int rpc_intr_pause(void)
{
    rpc_intr_is_paused = 1;

    return 0;
}

void rpc_intr_cleanup(void)
{
    int num = RPC_NR_DEVS/RPC_NR_PAIR, i;

    // Clean corresponding structures for each device.
    if (rpc_intr_devices) {
    	// Clean ring buffers.
    	for (i = 0; i < num; i++) {
//          if (rpc_intr_devices[i].ringBuf)
//              kfree(rpc_intr_devices[i].ringBuf);
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
        	devfs_unregister(rpc_intr_devices[i].handle);
#endif
#endif
    	}

//        kfree(rpc_intr_devices);
    }

    return;
}

int rpc_intr_open(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
	int minor = MINOR(inode->i_rdev)-1;
#endif
#endif
	int minor = MINOR(inode->i_rdev);

    PDEBUG("RPC intr open with minor number: %d\n", minor);

	if (!filp->private_data) {
#ifdef CONFIG_REALTEK_RPC_KCPU
		if (minor >= RPC_NR_DEVS)
			filp->private_data = &rpc_intr_kcpu_devices[(minor-RPC_NR_DEVS)/RPC_NR_PAIR];
		else
#endif
		filp->private_data = &rpc_intr_devices[minor/RPC_NR_PAIR];
		filp->f_pos = (loff_t)minor;
	}

//    MOD_INC_USE_COUNT; /* Before we maybe sleep */

    return 0;          /* success */
}

int rpc_intr_release(struct inode *inode, struct file *filp)
{
#ifdef CONFIG_DEVFS_FS
#ifndef KERNEL2_6
	int minor = MINOR(inode->i_rdev)-1;
#endif
#endif
	int minor = MINOR(inode->i_rdev);

    PDEBUG("RPC intr close with minor number: %d\n", minor);

//    MOD_DEC_USE_COUNT;

    return 0;          /* success */
}

// We don't need parameter f_pos here...
// note: rpc_intr_read support both blocking & nonblocking modes
ssize_t rpc_intr_read(struct file *filp, char *buf, size_t count,
                loff_t *f_pos)
{
    RPC_INTR_Dev *dev = filp->private_data; /* the first listitem */
    int temp, size;
    ssize_t ret = 0;
    char *ptmp;
    int rpc_ring_size = dev->ringEnd - dev->ringStart;

    if (rpc_intr_is_paused) {
        pr_err("RPCintr: someone access rpc intr during the pause...\n");
        msleep(1000);
        return -EAGAIN;
    }

    if (down_interruptible(&dev->ptrSync->readSem))
        return -ERESTARTSYS;

	if (dev->ringIn == dev->ringOut) {
		if (filp->f_flags & O_NONBLOCK)
			goto out;
wait_again:
		if (wait_event_interruptible_timeout(dev->ptrSync->waitQueue, dev->ringIn != dev->ringOut, timeout) == 0)
			goto out; /* timeout */

//		if (current->flags & PF_FREEZE) {
//			refrigerator(PF_FREEZE);
//			if (!signal_pending(current))
//				goto wait_again;
//		}
		if (try_to_freeze()) {
			if (!signal_pending(current))
				goto wait_again;
		}

		if (signal_pending(current)) {
			PDEBUG("RPC deblock because of receiving a signal...\n");
			goto out;
		}
	}

    if (dev->ringIn > dev->ringOut)
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
    PDEBUG("RPC intr ringOut pointer is : 0x%8x\n", (int)dev->ringOut);
    up(&dev->ptrSync->readSem);
    return ret;
}

// We don't need parameter f_pos here...
// note: rpc_intr_write only support nonblocking mode
ssize_t rpc_intr_write(struct file *filp, const char *buf, size_t count,
                loff_t *f_pos)
{
    RPC_INTR_Dev *dev = filp->private_data; /* the first listitem */
    int temp, size;
    ssize_t ret = 0;
    char *ptmp;
    int rpc_ring_size = dev->ringEnd - dev->ringStart;

    PDEBUG("[rpc_intr_write] write rpc_kern_device: caller%x, *buf:0x%x \n", (unsigned int) __read_32bit_caller_register(), *(unsigned int *)buf);
    if (rpc_intr_is_paused) {
        pr_err("RPCintr: someone access rpc intr during the pause...\n");
        msleep(1000);
        return -EAGAIN;
    }

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

		//modify by Angus
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

	// notify all the processes in the wait queue
//	wake_up_interruptible(&dev->waitQueue);
	temp = (int)*f_pos;	/* use the "f_pos" of file object to store the device number */
	if (temp == (RPC_INTR_DEV_SA_ID0*RPC_NR_PAIR+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SA | RPC_INT_WRITE_1));
	else if (temp == (RPC_INTR_DEV_SV1_ID2*RPC_NR_PAIR+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV | RPC_INT_WRITE_1));
	else if (temp == (RPC_INTR_DEV_SV2_ID4*RPC_NR_PAIR+1))
		//BUG();
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SV2 | RPC_INT_WRITE_1));
#ifdef CONFIG_REALTEK_RPC_KCPU
	else if (temp == (RPC_INTR_DEV_SK_ID0*RPC_NR_PAIR+RPC_NR_DEVS+1))
		rtd_outl(REG_SB2_CPU_INT, (RPC_INT_SK | RPC_INT_WRITE_1));
#endif
	else
		pr_err("error device number...\n");

out:
    PDEBUG("RPC intr ringIn pointer is : 0x%8x\n", (int)dev->ringIn);
    up(&dev->ptrSync->writeSem);
    return ret;
}

long rpc_intr_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	int ret = 0;

	switch(cmd) {
    	case RPC_IOCTTIMEOUT:
	        timeout = arg;
	        break;
    	case RPC_IOCQTIMEOUT:
    		return timeout;
		default:  /* redundant, as cmd was checked against MAXNR */
        	return -ENOTTY;
	}

	return ret;
}

#endif //CONFIG_REALTEK_RPC_MULTIPROCESS

int rpc_intr_run(void)
{

	int i;
	RPC_INTR_Dev * rpc_dev = (RPC_INTR_Dev *)phys_to_virt(RPC_INTR_RECORD_ADDR);
	for (i = 0; i < RPC_INTR_DEV_TOTAL; i++)
	{
		if(!(ring_empty((RPC_COMMON_Dev *)(&rpc_dev[i]))))
		{
			printk(KERN_NOTICE "rpc_intr_device(%d) not empty:%d\n", i,
				get_ring_data_size(rpc_dev[i].ringStart,rpc_dev[i].ringEnd,rpc_dev[i].ringIn, rpc_dev[i].ringOut));
			peek_rpc_struct(__func__, (RPC_COMMON_Dev *)(&rpc_dev[i]));
		}
	}
	rpc_intr_is_paused = 0;
	return 0;
}

struct file_operations rpc_intr_fops = {
//	llseek =                scull_llseek,
	//modify by angus
 	.unlocked_ioctl =       rpc_intr_ioctl,
 	.read =                 rpc_intr_read,
 	.write =                rpc_intr_write,
 	.open =                 rpc_intr_open,
 	.release =              rpc_intr_release,
};

