#ifndef RTK_SEMAPHORE_H
#define RTK_SEMAPHORE_H

#include <rbus/sb2_reg.h>
#include <asm/memory.h>
#include <mach/rtk_log.h>

#define SEMAPHORE_PHY   0x00001200
//#define SEMAPHORE_BASE  ((SEMAPHORE_PHY) - PHYS_OFFSET + PAGE_OFFSET)

enum LOCK_SEM {
        SEMA_HW_SEM_8        = SB2_HD_SEM_reg,       //0xB801a000,  0
        SEMA_HW_SEM_0        = SB2_HD_SEM_NEW_0_reg, //0xB801a620,  1
        SEMA_HW_SEM_1        = SB2_HD_SEM_NEW_1_reg, //0xB801a624,  2
        SEMA_HW_SEM_2        = SB2_HD_SEM_NEW_2_reg, //0xB801a628,  3
        SEMA_HW_SEM_3        = SB2_HD_SEM_NEW_3_reg, //0xB801a62C,  4
        SEMA_HW_SEM_4        = SB2_HD_SEM_NEW_4_reg, //0xB801a630,  5
        SEMA_HW_SEM_5        = SB2_HD_SEM_NEW_5_reg, //0xB801a634,  6
        SEMA_HW_SEM_6        = SB2_HD_SEM_NEW_6_reg, //0xB801a638,  7
        SEMA_HW_SEM_7        = SB2_HD_SEM_NEW_7_reg, //0xB801a63C,  8
	SEMA_HW_SEM_TOP      = 9,
};

typedef struct LOCK_RECORD {
        unsigned long sw_sem_lr;
        int sw_sem_uuid;
} SEM_RECORD;


typedef volatile struct HW_SEMAPHORE {
        unsigned long hw_sem_addr;
} HW_SEMA;


extern HW_SEMA hw_sema[SEMA_HW_SEM_TOP];
extern SEM_RECORD volatile *sem_record;

#define _SW2HWSEM_  (8)
#define _SW2HWaddr_ hw_sema[_SW2HWSEM_].hw_sem_addr

/*
 *  *  USER RULE :
 *  *  [28:31] SEM number 0:HW_SEM 0:HW_SEM_0 ...
 *  *  [24:27] CPU number  S:0 A1:1 A2:2 V1:3 V2:4 V2:5 EMCU:6
 *  *  [20:23] predefine module num 0 - 2, other 3 - F are for extention
 *  *  [4:19] Externtion for idientifing module in detail
 *  *  [0:3] can not use, only for ser status
 *  *  Example:
 *  *  SEMA_HW_SEM_SCPU_0      = MAKE_SEMA_UUID(SWSEM_0, SCPU,  NUM0, 0)
 *  */

// define for UUID
typedef enum {
        SEM_SCPU = 0,
        SEM_ACPU1,
        SEM_ACPU2,
        SEM_VCPU1,
        SEM_VCPU2,
        SEM_KCPU,
        SEM_EMCU,
} CPU_TYPE;

typedef enum {
        NUM0 = 0,
        NUM1,
        NUM2,
} CPU_NUM;

typedef enum {
        SWSEM_8 = 0,
        SWSEM_0,
        SWSEM_1,
        SWSEM_2,
        SWSEM_3,
        SWSEM_4,
        SWSEM_5,
        SWSEM_6,
        SWSEM_7
}SEMA_TYPE;

// To find UUID
#define MAKE_SEMA_UUID(swsema, cpu, num, externtion)	( swsema << 28 | cpu << 24 | num << 20 | externtion <<4 )

enum LOCK_UUID {
	SEMA_EMPTY		= 0x00000000,  //only use for initial

        SEMA_HW_SEM_8_SCPU_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_SCPU,  NUM0, 0), //0x00000000,  //BOOTAVCPU HW_SEM
        SEMA_HW_SEM_8_SCPU_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_SCPU,  NUM1, 0), //0x00100000,
        SEMA_HW_SEM_8_SCPU_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_SCPU,  NUM2, 0), //0x00200000,
        SEMA_HW_SEM_8_A1_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_ACPU1, NUM0, 0), //0x01000000,
        SEMA_HW_SEM_8_A1_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_ACPU1, NUM1, 0), //0x01100000,
        SEMA_HW_SEM_8_A1_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_ACPU1, NUM2, 0), //0x01200000,
        SEMA_HW_SEM_8_A2_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_ACPU2, NUM0, 0), //0x02000000,
        SEMA_HW_SEM_8_A2_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_ACPU2, NUM1, 0), //0x02100000,
        SEMA_HW_SEM_8_A2_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_ACPU2, NUM2, 0), //0x02200000,
	SEMA_HW_SEM_8_V1_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_VCPU1, NUM0, 0), //0x03000000,
	SEMA_HW_SEM_8_V1_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_VCPU1, NUM1, 0), //0x03100000,
	SEMA_HW_SEM_8_V1_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_VCPU1, NUM2, 0), //0x03200000,
	SEMA_HW_SEM_8_V2_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_VCPU2, NUM0, 0), //0x04000000,
	SEMA_HW_SEM_8_V2_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_VCPU2, NUM1, 0), //0x04100000,
	SEMA_HW_SEM_8_V2_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_VCPU2, NUM2, 0), //0x04200000,
	SEMA_HW_SEM_8_KCPU_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_KCPU,  NUM0, 0), //0x05000000,
	SEMA_HW_SEM_8_KCPU_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_KCPU,  NUM1, 0), //0x05100000,
	SEMA_HW_SEM_8_KCPU_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_KCPU,  NUM2, 0), //0x05200000,
	SEMA_HW_SEM_8_EMCU_0	= MAKE_SEMA_UUID(SWSEM_8, SEM_EMCU,  NUM0, 0), //0x06000000,
	SEMA_HW_SEM_8_EMCU_1	= MAKE_SEMA_UUID(SWSEM_8, SEM_EMCU,  NUM1, 0), //0x06100000,
	SEMA_HW_SEM_8_EMCU_2	= MAKE_SEMA_UUID(SWSEM_8, SEM_EMCU,  NUM2, 0), //0x06200000,

	SEMA_HW_SEM_0_SCPU_0	= MAKE_SEMA_UUID(SWSEM_0, SEM_SCPU,  NUM0, 0), //0x10000000,  //HW_SEM_0
	SEMA_HW_SEM_0_SCPU_1	= MAKE_SEMA_UUID(SWSEM_0, SEM_SCPU,  NUM1, 0), //0x10100000,
        SEMA_HW_SEM_0_SCPU_2	= MAKE_SEMA_UUID(SWSEM_0, SEM_SCPU,  NUM2, 0), //0x10200000,
        SEMA_HW_SEM_0_A1_0	= MAKE_SEMA_UUID(SWSEM_0, SEM_ACPU1, NUM0, 0), //0x11000000,
        SEMA_HW_SEM_0_A1_1	= 0x11100000,
        SEMA_HW_SEM_0_A1_2	= 0x11200000,
        SEMA_HW_SEM_0_A2_0     	= 0x12000000,
        SEMA_HW_SEM_0_A2_1     	= 0x12100000,
        SEMA_HW_SEM_0_A2_2     	= 0x12200000,
        SEMA_HW_SEM_0_V1_0     	= 0x13000000,
        SEMA_HW_SEM_0_V1_1     	= 0x13100000,
        SEMA_HW_SEM_0_V1_2     	= 0x13200000,
        SEMA_HW_SEM_0_V2_0     	= 0x14000000,
        SEMA_HW_SEM_0_V2_1     	= 0x14100000,
        SEMA_HW_SEM_0_V2_2     	= 0x14200000,
	SEMA_HW_SEM_0_KCPU_0   	= 0x15000000,
	SEMA_HW_SEM_0_KCPU_1   	= 0x15100000,
	SEMA_HW_SEM_0_KCPU_2   	= 0x15200000,
	SEMA_HW_SEM_0_EMCU_0   	= 0x16000000,
        SEMA_HW_SEM_0_EMCU_1   	= 0x16100000,
        SEMA_HW_SEM_0_EMCU_2   	= 0x16200000,

	SEMA_HW_SEM_1_SCPU_0   	= 0x20000000,  //HW_SEM_1
        SEMA_HW_SEM_1_SCPU_1   	= 0x20100000,
        SEMA_HW_SEM_1_SCPU_2   	= 0x20200000,
        SEMA_HW_SEM_1_A1_0     	= 0x21000000,
        SEMA_HW_SEM_1_A1_1     	= 0x21100000,
        SEMA_HW_SEM_1_A1_2     	= 0x21200000,
        SEMA_HW_SEM_1_A2_0     	= 0x22000000,
        SEMA_HW_SEM_1_A2_1     	= 0x22100000,
        SEMA_HW_SEM_1_A2_2     	= 0x22200000,
        SEMA_HW_SEM_1_V1_0     	= 0x23000000,
        SEMA_HW_SEM_1_V1_1     	= 0x23100000,
        SEMA_HW_SEM_1_V1_2     	= 0x23200000,
        SEMA_HW_SEM_1_V2_0     	= 0x24000000,
        SEMA_HW_SEM_1_V2_1     	= 0x24100000,
        SEMA_HW_SEM_1_V2_2     	= 0x24200000,
        SEMA_HW_SEM_1_KCPU_0   	= 0x25000000,
        SEMA_HW_SEM_1_KCPU_1   	= 0x25100000,
        SEMA_HW_SEM_1_KCPU_2   	= 0x25200000,
	SEMA_HW_SEM_1_EMCU_0   	= 0x26000000,
        SEMA_HW_SEM_1_EMCU_1   	= 0x26100000,
        SEMA_HW_SEM_1_EMCU_2   	= 0x26200000,

	SEMA_HW_SEM_2_SCPU_0   	= 0x30000000,  //HW_SEM_2
        SEMA_HW_SEM_2_SCPU_1   	= 0x30100000,
        SEMA_HW_SEM_2_SCPU_2   	= 0x30200000,
        SEMA_HW_SEM_2_A1_0     	= 0x31000000,
        SEMA_HW_SEM_2_A1_1     	= 0x31100000,
        SEMA_HW_SEM_2_A1_2     	= 0x31200000,
        SEMA_HW_SEM_2_A2_0     	= 0x32000000,
        SEMA_HW_SEM_2_A2_1     	= 0x32100000,
        SEMA_HW_SEM_2_A2_2     	= 0x32200000,
        SEMA_HW_SEM_2_V1_0     	= 0x33000000,
        SEMA_HW_SEM_2_V1_1     	= 0x33100000,
        SEMA_HW_SEM_2_V1_2     	= 0x33200000,
        SEMA_HW_SEM_2_V2_0     	= 0x34000000,
        SEMA_HW_SEM_2_V2_1     	= 0x34100000,
        SEMA_HW_SEM_2_V2_2     	= 0x34200000,
        SEMA_HW_SEM_2_KCPU_0   	= 0x35000000,
        SEMA_HW_SEM_2_KCPU_1   	= 0x35100000,
        SEMA_HW_SEM_2_KCPU_2   	= 0x35200000,
	SEMA_HW_SEM_2_EMCU_0   	= 0x36000000,
        SEMA_HW_SEM_2_EMCU_1   	= 0x36100000,
        SEMA_HW_SEM_2_EMCU_2   	= 0x36200000,

	SEMA_HW_SEM_3_SCPU_0   = 0x40000000,  //HW_SEM_3
        SEMA_HW_SEM_3_SCPU_1   = 0x40100000,
        SEMA_HW_SEM_3_SCPU_2   = 0x40200000,
        SEMA_HW_SEM_3_A1_0     = 0x41000000,
        SEMA_HW_SEM_3_A1_1     = 0x41100000,
        SEMA_HW_SEM_3_A1_2     = 0x41200000,
        SEMA_HW_SEM_3_A2_0     = 0x42000000,
        SEMA_HW_SEM_3_A2_1     = 0x42100000,
        SEMA_HW_SEM_3_A2_2     = 0x42200000,
        SEMA_HW_SEM_3_V1_0     = 0x43000000,
        SEMA_HW_SEM_3_V1_1     = 0x43100000,
        SEMA_HW_SEM_3_V1_2     = 0x43200000,
        SEMA_HW_SEM_3_V2_0     = 0x44000000,
        SEMA_HW_SEM_3_V2_1     = 0x44100000,
        SEMA_HW_SEM_3_V2_2     = 0x44200000,
        SEMA_HW_SEM_3_KCPU_0   = 0x45000000,
        SEMA_HW_SEM_3_KCPU_1   = 0x45100000,
        SEMA_HW_SEM_3_KCPU_2   = 0x45200000,
	SEMA_HW_SEM_3_EMCU_0   = 0x46000000,
        SEMA_HW_SEM_3_EMCU_1   = 0x46100000,
        SEMA_HW_SEM_3_EMCU_2   = 0x46200000,

	SEMA_HW_SEM_4_SCPU_0   = 0x50000000,  //HW_SEM_4
        SEMA_HW_SEM_4_SCPU_1   = 0x50100000,
        SEMA_HW_SEM_4_SCPU_2   = 0x50200000,
        SEMA_HW_SEM_4_A1_0     = 0x51000000,
        SEMA_HW_SEM_4_A1_1     = 0x51100000,
        SEMA_HW_SEM_4_A1_2     = 0x51200000,
        SEMA_HW_SEM_4_A2_0     = 0x52000000,
        SEMA_HW_SEM_4_A2_1     = 0x52100000,
        SEMA_HW_SEM_4_A2_2     = 0x52200000,
        SEMA_HW_SEM_4_V1_0     = 0x53000000,
        SEMA_HW_SEM_4_V1_1     = 0x53100000,
        SEMA_HW_SEM_4_V1_2     = 0x53200000,
        SEMA_HW_SEM_4_V2_0     = 0x54000000,
        SEMA_HW_SEM_4_V2_1     = 0x54100000,
        SEMA_HW_SEM_4_V2_2     = 0x54200000,
        SEMA_HW_SEM_4_KCPU_0   = 0x55000000,
        SEMA_HW_SEM_4_KCPU_1   = 0x55100000,
        SEMA_HW_SEM_4_KCPU_2   = 0x55200000,
	SEMA_HW_SEM_4_EMCU_0   = 0x56000000,
        SEMA_HW_SEM_4_EMCU_1   = 0x56100000,
        SEMA_HW_SEM_4_EMCU_2   = 0x56200000,

	SEMA_HW_SEM_5_SCPU_0   = 0x60000000,  //HW_SEM_5
        SEMA_HW_SEM_5_SCPU_1   = 0x60100000,
        SEMA_HW_SEM_5_SCPU_2   = 0x60200000,
        SEMA_HW_SEM_5_A1_0     = 0x61000000,
        SEMA_HW_SEM_5_A1_1     = 0x61100000,
        SEMA_HW_SEM_5_A1_2     = 0x61200000,
        SEMA_HW_SEM_5_A2_0     = 0x62000000,
        SEMA_HW_SEM_5_A2_1     = 0x62100000,
        SEMA_HW_SEM_5_A2_2     = 0x62200000,
        SEMA_HW_SEM_5_V1_0     = 0x63000000,
        SEMA_HW_SEM_5_V1_1     = 0x63100000,
        SEMA_HW_SEM_5_V1_2     = 0x63200000,
        SEMA_HW_SEM_5_V2_0     = 0x64000000,
        SEMA_HW_SEM_5_V2_1     = 0x64100000,
        SEMA_HW_SEM_5_V2_2     = 0x64200000,
        SEMA_HW_SEM_5_KCPU_0   = 0x65000000,
        SEMA_HW_SEM_5_KCPU_1   = 0x65100000,
        SEMA_HW_SEM_5_KCPU_2   = 0x65200000,
	SEMA_HW_SEM_5_EMCU_0   = 0x66000000,
        SEMA_HW_SEM_5_EMCU_1   = 0x66100000,
        SEMA_HW_SEM_5_EMCU_2   = 0x66200000,

	SEMA_HW_SEM_6_SCPU_0   = 0x70000000,  //HW_SEM_6
        SEMA_HW_SEM_6_SCPU_1   = 0x70100000,
        SEMA_HW_SEM_6_SCPU_2   = 0x70200000,
        SEMA_HW_SEM_6_A1_0     = 0x71000000,
        SEMA_HW_SEM_6_A1_1     = 0x71100000,
        SEMA_HW_SEM_6_A1_2     = 0x71200000,
        SEMA_HW_SEM_6_A2_0     = 0x72000000,
        SEMA_HW_SEM_6_A2_1     = 0x72100000,
        SEMA_HW_SEM_6_A2_2     = 0x72200000,
        SEMA_HW_SEM_6_V1_0     = 0x73000000,
        SEMA_HW_SEM_6_V1_1     = 0x73100000,
        SEMA_HW_SEM_6_V1_2     = 0x73200000,
        SEMA_HW_SEM_6_V2_0     = 0x74000000,
        SEMA_HW_SEM_6_V2_1     = 0x74100000,
        SEMA_HW_SEM_6_V2_2     = 0x74200000,
        SEMA_HW_SEM_6_KCPU_0   = 0x75000000,
        SEMA_HW_SEM_6_KCPU_1   = 0x75100000,
        SEMA_HW_SEM_6_KCPU_2   = 0x75200000,
	SEMA_HW_SEM_6_EMCU_0   = 0x76000000,
        SEMA_HW_SEM_6_EMCU_1   = 0x76100000,
        SEMA_HW_SEM_6_EMCU_2   = 0x76200000,

	SEMA_HW_SEM_7_SCPU_0   = 0x80000000,  //HW_SEM_7
        SEMA_HW_SEM_7_SCPU_1   = 0x80100000,
        SEMA_HW_SEM_7_SCPU_2   = 0x80200000,
        SEMA_HW_SEM_7_A1_0     = 0x81000000,
        SEMA_HW_SEM_7_A1_1     = 0x81100000,
        SEMA_HW_SEM_7_A1_2     = 0x81200000,
        SEMA_HW_SEM_7_A2_0     = 0x82000000,
        SEMA_HW_SEM_7_A2_1     = 0x82100000,
        SEMA_HW_SEM_7_A2_2     = 0x82200000,
        SEMA_HW_SEM_7_V1_0     = 0x83000000,
        SEMA_HW_SEM_7_V1_1     = 0x83100000,
        SEMA_HW_SEM_7_V1_2     = 0x83200000,
        SEMA_HW_SEM_7_V2_0     = 0x84000000,
        SEMA_HW_SEM_7_V2_1     = 0x84100000,
        SEMA_HW_SEM_7_V2_2     = 0x84200000,
        SEMA_HW_SEM_7_KCPU_0   = 0x85000000,
        SEMA_HW_SEM_7_KCPU_1   = 0x85100000,
        SEMA_HW_SEM_7_KCPU_2   = 0x85200000,
	SEMA_HW_SEM_7_EMCU_0   = 0x86000000,
        SEMA_HW_SEM_7_EMCU_1   = 0x86100000,
        SEMA_HW_SEM_7_EMCU_2   = 0x86200000,
	SEMA_HW_SEM_CHECK      = 0x86800000,
};

extern void rtd_semaphore_init( void );
extern void dump_sem_data( void );
extern unsigned int  _rtd_hwsem_trylock(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid);
extern void _rtd_hwsem_lock(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid);
extern void _rtd_hwsem_unlock(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid);
extern void _rtd_hwsem_unlock_nocheck(enum LOCK_SEM hw_sem_addr, enum LOCK_UUID uuid);

extern int  _rtd_swsem_trylock(int checkid, enum LOCK_UUID uuid, unsigned long ip);
extern void _rtd_swsem_lock(int checkid, enum LOCK_UUID uuid, unsigned long ip);
extern void _rtd_swsem_unlock(int checkid, enum LOCK_UUID uuid, unsigned long ip);

#define rtd_hwsem_getid(uuid)                   \
( {                                             \
        int __id;                               \
        if ( (unsigned int)uuid >= 0x90000000 )               \
                panic("Semaphore UUID Fail");   \
        __id = ((unsigned int)uuid>>(28));      \
        __id; 					\
} )

#define rtd_hwsem_trylock(uuid)				\
	( {							\
		int __ret;					\
		enum LOCK_UUID m = uuid;			\
		__ret =_rtd_hwsem_trylock( hw_sema[rtd_hwsem_getid(m)].hw_sem_addr, (unsigned long)__builtin_return_address(0)); \
		if ( __ret != 1 )				\
			__ret = 0;				\
		__ret;						\
	} )

#define rtd_hwsem_lock(uuid)				\
	do {							\
		enum LOCK_UUID m = uuid;                 \
		_rtd_hwsem_lock( hw_sema[rtd_hwsem_getid(m)].hw_sem_addr, (unsigned long)__builtin_return_address(0) );	\
	} while(0)

#define rtd_hwsem_unlock(uuid)				\
	do {							\
		enum LOCK_UUID m = uuid;                 \
		_rtd_hwsem_unlock_nocheck( hw_sema[rtd_hwsem_getid(m)].hw_sem_addr, (unsigned long)__builtin_return_address(0) );\
	} while(0)

#define rtd_swsem_trylock(uuid)					\
	( {							\
		int __ret;					\
		enum LOCK_UUID m = uuid;			\
		__ret = _rtd_swsem_trylock(rtd_hwsem_getid(m),m,(unsigned long)__builtin_return_address(0));	\
		__ret;						\
	} )

#define rtd_swsem_lock(uuid)                            	\
        do {       						\
		enum LOCK_UUID m = uuid; 			\
                _rtd_swsem_lock(rtd_hwsem_getid(m), m, (unsigned long)__builtin_return_address(0));    	\
        } while(0)

#define rtd_swsem_unlock(uuid)                            	\
        do {                                                    \
		enum LOCK_UUID m = uuid;                        \
                _rtd_swsem_unlock(rtd_hwsem_getid(m), m, (unsigned long)__builtin_return_address(0));           \
        } while(0)

#define SEMA_TAG "SEMAPHORE"
#define RTK_SEM_INFO(fmt, args...)    rtd_printk(KERN_INFO, SEMA_TAG, fmt, ## args)
#define RTK_SEM_WARNING(fmt, args...) rtd_printk(KERN_WARNING, SEMA_TAG, fmt, ## args)
#define RTK_SEM_ERR(fmt, args...)     rtd_printk(KERN_ERR, SEMA_TAG, fmt, ## args)

#endif //RTK_SEMAPHORE_H
