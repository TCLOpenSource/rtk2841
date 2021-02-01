#include <linux/delay.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <asm/traps.h>
#include <mach/io.h>
#include <rtk_kdriver/rtk_semaphore.h>
#include <mach/platform.h>
#include <asm/cacheflush.h>

extern unsigned int debugMode; // declare in mach-rtdxxxx/init.c

SEM_RECORD volatile *sem_record;// = (SEM_RECORD *) SEMAPHORE_BASE;

HW_SEMA hw_sema[SEMA_HW_SEM_TOP] =
{
	/* hw_sema_addr */
        { SEMA_HW_SEM_8 },
        { SEMA_HW_SEM_0 },
        { SEMA_HW_SEM_1 },
        { SEMA_HW_SEM_2 },
        { SEMA_HW_SEM_3 },
        { SEMA_HW_SEM_4 },
        { SEMA_HW_SEM_5 },
        { SEMA_HW_SEM_6 },
        { SEMA_HW_SEM_7 },
};

static void try_to_panic ( enum LOCK_UUID uuid, int value )
{
#ifdef CONFIG_CUSTOMER_TV006
        if ( debugMode == DEBUG_LEVEL || debugMode == EVENT_LEVEL)
        {
                panic("UUID[%x] try to lock, but owner is [%x]\n", uuid, value);
        }
#else
	while(1)
	{
		if (signal_pending(current))
                {
                        RTK_SEM_ERR(" Recive Signal to STOP\n ");
                        return;
                }
	}
#endif
}

static void invalidate_status_flag( void )
{
        dmac_inv_range((void *)sem_record,(void *) ((unsigned long)(sem_record+9)-1));
        outer_inv_range(SEMAPHORE_PHY, SEMAPHORE_PHY+(sizeof(SEM_RECORD)*SEMA_HW_SEM_TOP));
}
static void flush_status_flag( void )
{
        dmac_flush_range((void *)sem_record,(void *) ((unsigned long)(sem_record+9)-1));
        outer_flush_range(SEMAPHORE_PHY, SEMAPHORE_PHY+(sizeof(SEM_RECORD)*SEMA_HW_SEM_TOP));
}

void dump_sem_data( void )
{
	int i, j;
	RTK_SEM_ERR( " Dump all semaphore info \n\n" );
	for (i=0; i<SEMA_HW_SEM_TOP; i++) {
		j = rtd_inl(hw_sema[i].hw_sem_addr);
		if ( j & 1 == 1 )
			rtd_outl( hw_sema[i].hw_sem_addr, j & ~1 );
                RTK_SEM_ERR( " HW sema [0x%x], Owner [0x%x] \n", (unsigned int) hw_sema[i].hw_sem_addr,
			j);
                RTK_SEM_ERR( " SW sema [0x%x], Owner [0x%x], return address (0x%x) \n",
			(unsigned int) &sem_record[i],
                        (unsigned int) sem_record[i].sw_sem_uuid,
                        (unsigned int) sem_record[i].sw_sem_lr);
#ifdef __linux__
                RTK_SEM_ERR( " Owner's return address = [ %pS ] \n", (void *) sem_record[i].sw_sem_lr );
#endif
	}
}


void rtd_semaphore_init()
{
	sem_record = (SEM_RECORD *) phys_to_virt(SEMAPHORE_PHY);
}

/* 	Notice: HW Lock API is semantically diff from hw_semaphore_try_lock.
 *  * * return 1: get lock
 *  * * return 0: not get lock.
 *  * *
 */

/**
 *  * rtd_hwsem_trylock - try to acquire the mutex, without waiting
 */

unsigned int _rtd_hwsem_trylock( enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid )
{
        unsigned int value;

        if ( (((value = rtd_inl( hw_sem_addr ))) & 1) == 1 )
        {
                rtd_outl(hw_sem_addr, uuid | 1);
                return 1;
        }
        return value;
}

/**
 *  * rtd_hwsem_lock - acquire the mutex
 *  * @lock: the hwsem to be acquired
 */

void _rtd_hwsem_lock(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid)
{
	int timeout = 1000000; // 5us * 1000000 = 5s ; every 1s print warning message
        unsigned int value;

        while ( (((value = _rtd_hwsem_trylock(hw_sem_addr, uuid) ))) != 1 ){
                if (--timeout == 0) {
			RTK_SEM_ERR( "\n\n\n\n"
				"[HW Semaphore] LOCK timeout: Sem 0x%x owned by 0x%x, but try lock by 0x%x\n"
				"\n\n\n\n",
				(unsigned int) hw_sem_addr,
				value,
				uuid);
			try_to_panic(  uuid, value );
			return;
		}

		if ( (timeout & 0x0001FFFF) == 0)
		{
			RTK_SEM_WARNING( " [HW Semaphore] LOCK WARNING: Sem 0x%x owned by 0x%x, wait by 0x%x \n",
				(unsigned int) hw_sem_addr, value, uuid);
		}
		udelay(5);

        }
}

void _rtd_hwsem_unlock(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid)
{
        int value;

        if ( (value = rtd_inl( hw_sem_addr )) !=  ( uuid | 0x0 ) )
        {
		if ( value == 1 )
		{
			RTK_SEM_WARNING( "\n\n\n\n"
				"[HW Semaphore] unlock warning : sem 0x%x is unlocked\n"
				"\n\n\n\n",
				(unsigned int) hw_sem_addr);
		}
		else
		{
			RTK_SEM_ERR( "\n\n\n\n"
				"[HW Semaphore] unlock FAIL : sem 0x%x owned by 0x%x, but unlock by 0x%x\n"
				"\n\n\n\n",
				(unsigned int) hw_sem_addr, (unsigned int) value,
				uuid);
			try_to_panic( uuid, value );
		}
        }
        rtd_outl(hw_sem_addr, 0x0);
}

void _rtd_hwsem_unlock_nocheck(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid)
{
        int value;

        if ( ((value = rtd_inl( hw_sem_addr )) & 0x1 ) != 0x0 )
        {
                RTK_SEM_WARNING( "\n\n\n\n"
			"[HW Semaphore] warning : %s sem 0x%x is unlocked \n"
			"\n\n\n\n",
                        __FUNCTION__, (unsigned int) hw_sem_addr);
        }
        rtd_outl(hw_sem_addr, 0x0);
}


/**
 * 	Error -EBUSY hw semaphore error  -EAGAIN sw semaphore error
 *      return 1: get lock
 *       **/
inline int _rtd_swsem_trylock(int checkid, enum LOCK_UUID uuid, unsigned long ip)
{
	int swsem, ret;

	if ( _rtd_hwsem_trylock( _SW2HWaddr_, uuid ) != 1 )
		return -EBUSY;

	invalidate_status_flag( );

	swsem = sem_record[checkid].sw_sem_uuid;
	if (swsem != 0) {
		ret = -EAGAIN;
		goto badTL;
	}

	sem_record[checkid].sw_sem_uuid = uuid;
	sem_record[checkid].sw_sem_lr 	= ip;

	flush_status_flag( );

	ret = 1;
badTL:
	_rtd_hwsem_unlock( _SW2HWaddr_, uuid );

	return ret;
}


inline void _rtd_swsem_lock(int checkid, enum LOCK_UUID uuid, unsigned long ip)
{
        int swsem;
	unsigned int cht;
	int timeout = 1000000; // 5us * 1000000 = 5s ; every 1s print warning message

	while ( ( swsem = _rtd_swsem_trylock(checkid, uuid, ip) ) != 1 )
	{
		if (signal_pending(current))
		{
			RTK_SEM_ERR(" Recive Signal to STOP\n ");
			return;
		}

		if (--timeout == 0) {

				RTK_SEM_ERR( "\n\n\n\n"
				"[SW Semaphore] LOCK TIMEOUT CAUSE:[%s]",
				(swsem & 0x1) ? "SW" : "HW");

			if ( swsem == -EAGAIN )
			{
				RTK_SEM_ERR( " SW sem %x owned by [0x%x] return address [0x%x], but try lock by %x \n",
					(unsigned int) &sem_record[checkid],
					(unsigned int) sem_record[checkid].sw_sem_uuid,
					(unsigned int) sem_record[checkid].sw_sem_lr,
					uuid);
#ifdef __linux__
				RTK_SEM_ERR( " Owner's return address[%pS] \n\n",
					(void *) sem_record[checkid].sw_sem_lr );
#endif
				//dump_sem_data();
			}
			else if ( swsem == -EBUSY )
			{
				cht = rtd_inl(hw_sema[_SW2HWSEM_].hw_sem_addr);
				if ( (cht & 1) == 1 )
					rtd_outl( hw_sema[_SW2HWSEM_].hw_sem_addr, cht & ~1 );
				RTK_SEM_ERR( " HW Sem %x owned by 0x%x, but try lock by 0x%x\n",
					(unsigned int) hw_sema[_SW2HWSEM_].hw_sem_addr,
					cht,
					uuid);
                        }
			RTK_SEM_ERR( "\n\n");
			try_to_panic(  uuid, swsem );
		}

		if ( (timeout & 0x0001FFFF) == 0 )
		{
			RTK_SEM_WARNING(" [SW semaphore] LOCK WARNING : wait for %s sema\n",
				(swsem & 0x1) ? "SW" : "HW"
				);
			if ( swsem == -EAGAIN )
			{
				RTK_SEM_WARNING( " sem 0x%x owned by 0x%x, RA [0x%x], but wait by 0x%x RA [0x%x]",
					(unsigned int) &sem_record[checkid],
					(unsigned int) sem_record[checkid].sw_sem_uuid,
					(unsigned int) sem_record[checkid].sw_sem_lr,
					uuid,
					(unsigned int) ip );
#ifdef __linux__
				RTK_SEM_WARNING( " User's RA[%pS], Owner's RA[%pS]\n",
					(void *) ip,
					(void *) sem_record[checkid].sw_sem_lr );
#endif
			}
			else if ( swsem == -EBUSY )
			{
				RTK_SEM_WARNING( " sem 0x%x wait by 0x%x\n",
					(unsigned int) hw_sema[_SW2HWSEM_].hw_sem_addr,
					uuid);
			}
		}
		udelay(5);
	}

}

void _rtd_swsem_unlock( int checkid, enum LOCK_UUID uuid, unsigned long ip )
{
	int value;

	_rtd_hwsem_lock( _SW2HWaddr_, uuid );

	invalidate_status_flag( );

        if ( (value = sem_record[checkid].sw_sem_uuid) != uuid )
        {

		RTK_SEM_ERR( "\n\n\n\n"
			"[SW Semaphore] sem 0x%x owned by 0x%x RA [0x%x], but Unlock by 0x%x"
                        "\n\n\n\n",
                        (unsigned int) &sem_record[checkid],
			(unsigned int) value,
			(unsigned int) (unsigned int) sem_record[checkid].sw_sem_lr,
			uuid
			);
#ifdef __linux__
		RTK_SEM_ERR( " Owner's return address[%pS] \n",
			(void *) sem_record[checkid].sw_sem_lr );
#endif
                RTK_SEM_ERR( "\n\n");

		//dump_sem_data();
		_rtd_hwsem_unlock( _SW2HWaddr_, uuid );
		try_to_panic( uuid, value );
		return;
        }

	sem_record[checkid].sw_sem_uuid = 0x00000000;
	sem_record[checkid].sw_sem_lr 	= 0x00000000;

	flush_status_flag( );

	_rtd_hwsem_unlock( _SW2HWaddr_, uuid );
}
