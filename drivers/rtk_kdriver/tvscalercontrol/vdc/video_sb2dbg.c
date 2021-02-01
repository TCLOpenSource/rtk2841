#include "video_sb2dbg.h"

#include <linux/types.h>			/**< kernel types */
#include <linux/kernel.h>			/**< kerne header */
#include <linux/stringify.h>			/**< __stringify() macro */
#include <linux/bitops.h>			/**< bits operation */
#include <asm/glue.h>				/**< ____glue() macro */
#include <mach/rtk_log.h>
#include <rbus/tv_sb1_ana_reg.h>
#include <rbus/vd_ifd_input_reg.h>
#include <rbus/vd_ifd_input_108_reg.h>
#include <rbus/sys_reg_reg.h>
#include <rbus/pll27x_reg_reg.h>

#include <rtk_sb2_callback.h>			/**< sb2 timeout callback */
#include <tvscalercontrol/io/ioregdrv.h>

#define MODIFY_DATE
#define RBUS_TAG_NONE		""
#define RBUS_TAG_VFE		"VFE"
#define RBUS_TAG_VDC		"VDC"
#define RBUS_TAG_VIP		"VIP"

#define RBUS_LOWER_BOUND_NONE	0x00000000
#define RBUS_UPPER_BOUND_NONE	0x00000000
#define RBUS_LOWER_BOUND_VFE	0x18018000
#define RBUS_UPPER_BOUND_VFE	0x180180E0
#define RBUS_LOWER_BOUND_VDC	0x18019000
#define RBUS_UPPER_BOUND_VDC	0x180197FC
#define RBUS_LOWER_BOUND_VIP	0x18019800
#define RBUS_UPPER_BOUND_VIP	0x18019FFC

#define TABLE_SIZE(tbl) (sizeof(tbl)/sizeof(tbl[0]))

enum RBUS_AT {
	RBUS_AT_NONE = 0,
	RBUS_AT_VFE,
	RBUS_AT_VDC,
	RBUS_AT_VIP,
};

#define RBUS_RANGE(name) \
	RBUS_RANGE_I(____glue(RBUS_AT_, name), \
		____glue(RBUS_LOWER_BOUND_, name), \
		____glue(RBUS_UPPER_BOUND_, name))
#define RBUS_RANGE_I(at, low, up) { at, low, up }

#define RBUS_CRT_BANK() \
	SYS_REG_SYS_SRST1_reg, \
	SYS_REG_SYS_SRST2_reg, \
	SYS_REG_SYS_CLKEN1_reg, \
	SYS_REG_SYS_CLKEN2_reg, \
	SYS_REG_SYS_CLKSEL_reg, \
	PLL27X_REG_SYS_PLL_27X3_reg

#define RBUS_ANALOG_BANK() \
	TV_SB1_ANA_IFADC_CTRL1_reg, \
	TV_SB1_ANA_IFADC_CTRL2_reg, \
	TV_SB1_ANA_IQADC_CTRL3_reg

#define show_reg_value(tag, addr) \
(unsigned long)({ \
	unsigned int _0 = (unsigned int)(addr); \
	unsigned long _r = IoReg_Read32(_0); \
	rtd_printk(KERN_EMERG, tag, "\t%08x: %08lx, bitmap: %*pbl\r\n", _0, \
		_r, sizeof(_r)*BITS_PER_BYTE, &_r); \
	(unsigned long)_r; \
})

#define show_reg_bank(tag, tbl) \
(void)({ \
	int _i = 0; \
	rtd_printk(KERN_EMERG, tag, __stringify(tbl)"\r\n"); \
	rtd_printk(KERN_EMERG, tag, "------------[ cut here ]------------\r\n"); \
	for (_i = 0; _i < TABLE_SIZE(tbl); ++_i) \
		show_reg_value(tag, tbl[_i]); \
	(void)0; \
	rtd_printk(KERN_EMERG, tag, "------------[ end dump ]------------\r\n"); \
})

struct rbus_range {
	enum RBUS_AT at;
	unsigned long lower_bound;
	unsigned long upper_bound;
};

struct rbus_info {
	struct rbus_range range;
	sb2_timeout_info info;
};

static const unsigned long vfe_monitor_bank[] = {
	RBUS_CRT_BANK(),
	RBUS_ANALOG_BANK(),
};

static const unsigned long vdc_monitor_bank[] = {
	RBUS_CRT_BANK(),
};

static const unsigned long vip_monitor_bank[] = {
	RBUS_CRT_BANK(),
};

static void show_vdc_rbus_timeout_info(void);

SB2_DEBUG_INFO_DECLARE(sb2_vdc_callback, show_vdc_rbus_timeout_info);

static inline struct rbus_range to_rbus_range(const unsigned int addr)
{
	struct rbus_range r = RBUS_RANGE(NONE);
	static const struct rbus_range tbl[] = {
		RBUS_RANGE(VFE),
		RBUS_RANGE(VDC),
		RBUS_RANGE(VIP),
	};
	const int n = TABLE_SIZE(tbl);
	int i;

	for (i = 0; i < n; ++i) {
		if (addr >= tbl[i].lower_bound && addr <= tbl[i].upper_bound) {
			r = tbl[i];
			break;
		}
	}

	return r;
}

static inline struct rbus_info get_rbus_info(void)
{
	struct rbus_info r;
	sb2_timeout_info info;

	get_sb2_timeout_info(&info);

	r.info = info;
	r.range = to_rbus_range(info.timeout_reg);

	return r;
}

static inline enum RBUS_AT show_rbus_info(void)
{
	struct rbus_info r = get_rbus_info();

	switch (r.range.at) {
	case RBUS_AT_VFE:
		rtd_printk(KERN_EMERG, RBUS_TAG_VFE,
			   "rbus timeout @0x%08lx, isTimeout %x\r\n",
			   r.info.timeout_reg, r.info.isTimeout);
		break;
	case RBUS_AT_VDC:
		rtd_printk(KERN_EMERG, RBUS_TAG_VDC,
			   "rbus timeout @0x%08lx, isTimeout %x\r\n",
			   r.info.timeout_reg, r.info.isTimeout);
	break;
	case RBUS_AT_VIP:
		rtd_printk(KERN_EMERG, RBUS_TAG_VIP,
			   "rbus timeout @0x%08lx, isTimeout %x\r\n",
			   r.info.timeout_reg, r.info.isTimeout);
		break;
	default:
		break;
	}

	return r.range.at;
}

/**
 * video decoder sb2 timeout callback function
 * 
 * @param void 
 */
void show_vdc_rbus_timeout_info(void)
{
	enum RBUS_AT at;

	if (isSb2Timeout("Video Decorder")) {
		at = show_rbus_info();
		switch (at) {
		case RBUS_AT_VFE:
			show_reg_bank(RBUS_TAG_VFE, vfe_monitor_bank);
			break;

		case RBUS_AT_VDC:
			show_reg_bank(RBUS_TAG_VDC, vdc_monitor_bank);
			break;

		case RBUS_AT_VIP:
			show_reg_bank(RBUS_TAG_VDC, vip_monitor_bank);
			break;

		default:
			break;
		}
	}
}

/**
 * register video decoder sb2 timeout callback funciton
 * 
 * @param void 
 */
void module_video_register_sb2_timeout_callback(void)
{
	SB2_DEBUG_INFO_REGISTER(sb2_vdc_callback, show_vdc_rbus_timeout_info);
	rtd_printk(KERN_EMERG, RBUS_TAG_VDC,
		   "register vdc sb2 timeout callback\r\n");
}

/**
 * unregister video decoder sb2 timeout callback funciton
 * 
 * @param void 
 */
void module_video_unregister_sb2_timeout_callback(void)
{
	SB2_DEBUG_INFO_UNREGISTER(sb2_vdc_callback, show_vdc_rbus_timeout_info);
	rtd_printk(KERN_EMERG, RBUS_TAG_VDC,
		   "unregister vdc sb2 timeout callback\r\n");
}
