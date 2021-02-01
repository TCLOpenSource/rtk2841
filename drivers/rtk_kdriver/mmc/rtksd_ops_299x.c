/*
 * Realtek MMC/SD/SDIO driver
 *
 * Authors:
 * Copyright (C) 2008-2009 Realtek Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/mbus.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/scatterlist.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/mmc/host.h>
#include <asm/unaligned.h>

#include <linux/sched.h>
#include <linux/wait.h>
#include <linux/slab.h>
#include <linux/semaphore.h>
#include <linux/mmc/card.h>
#include <linux/mmc/mmc.h>
#include <linux/mmc/sd.h>
#include <linux/workqueue.h>
#include <linux/completion.h>
#include <rbus/mmc_reg.h>
#include "rtksdio_299x.h"
#include "rtksd_ops.h"

#define MIS_GP0DATO_reg         0xB801B11C
#define MIS_GP0DIR_reg          0xB801B100

extern unsigned int test_start_flag;

#ifdef GPIO_DEBUG
void trans_db_gpio(void)
{
	u32 reginfo;
	/*
	 * 1. 0xB800_0804[31:28] = F    --> pin share as gpio
	 * 2. 0x1801_BC00[4] = 1  --> output mode
	 * 3. 0x1801_BC18[4]   is output data
	 */
	cr_writel(cr_readl(MIS_GP0DIR_reg) | 0x10, MIS_GP0DIR_reg);

	reginfo = cr_readl(MIS_GP0DATO_reg);
	if (reginfo & 0x10) {
		cr_writel(reginfo & ~0x10, MIS_GP0DATO_reg);
	} else {
		cr_writel(reginfo | 0x10, MIS_GP0DATO_reg);
	}

}

void trans_rst_gpio(void)
{
	u32 reginfo;
	cr_writel(cr_readl(MIS_GP0DIR_reg) | 0x00100000, MIS_GP0DIR_reg);
	reginfo = cr_readl(MIS_GP0DATO_reg);

	if (reginfo & 0x00100000) {
		cr_writel(reginfo & ~0x00100000, MIS_GP0DATO_reg);
	} else {
		cr_writel(reginfo | 0x00100000, MIS_GP0DATO_reg);
	}

}
#else
#define trans_db_gpio()
#define trans_rst_gpio()
#endif

char *rtkcr_parse_token(const char *parsed_string, const char *token)
{
	const char *ptr = parsed_string;
	const char *start, *end, *value_start, *value_end;
	char *ret_str;

	while (1) {
		value_start = value_end = 0;
		for (; *ptr == ' ' || *ptr == '\t'; ptr++) ;
		if (*ptr == '\0')
			break;
		start = ptr;
		for (;
		     *ptr != ' ' && *ptr != '\t' && *ptr != '=' && *ptr != '\0';
		     ptr++) ;
		end = ptr;
		if (*ptr == '=') {
			ptr++;
			if (*ptr == '"') {
				ptr++;
				value_start = ptr;
				for (; *ptr != '"' && *ptr != '\0'; ptr++) ;
				if (*ptr != '"'
				    || (*(ptr + 1) != '\0' && *(ptr + 1) != ' '
					&& *(ptr + 1) != '\t')) {
					pr_warning
					    ("system_parameters error! Check your parameters     .");
					break;
				}
			} else {
				value_start = ptr;
				for (;
				     *ptr != ' ' && *ptr != '\t' && *ptr != '\0'
				     && *ptr != '"'; ptr++) ;
				if (*ptr == '"') {
					pr_warning
					    ("system_parameters error! Check your parameters.");
					break;
				}
			}
			value_end = ptr;
		}

		if (!strncmp(token, start, end - start)) {
			if (value_start) {
				ret_str =
				    kmalloc(value_end - value_start + 1,
					    GFP_KERNEL);
				/* KWarning: checked ok by alexkh@realtek.com */
				if (ret_str) {
					strncpy(ret_str, value_start,
						value_end - value_start);
					ret_str[value_end - value_start] = '\0';
				}
				return ret_str;
			} else {
				ret_str = kmalloc(1, GFP_KERNEL);
				/* KWarning: checked ok by alexkh@realtek.com */
				if (ret_str)
					strcpy(ret_str, "");
				return ret_str;
			}
		}
	}

	return (char *)NULL;
}

EXPORT_SYMBOL_GPL(rtkcr_parse_token);

void rtkcr_chk_param(u32 *pparam, u32 len, u8 *ptr)
{
	u32 value, i;

	*pparam = 0;
	for (i = 0; i < len; i++) {
		value = ptr[i] - '0';
		/* KWarning: checked ok by alexkh@realtek.com */
		if ((value >= 0) && (value <= 9)) {
			*pparam += value << (4 * (len - 1 - i));
			continue;
		}

		value = ptr[i] - 'a';
		/* KWarning: checked ok by alexkh@realtek.com */
		if ((value >= 0) && (value <= 5)) {
			value += 10;
			*pparam += value << (4 * (len - 1 - i));
			continue;
		}

		value = ptr[i] - 'A';
		/* KWarning: checked ok by alexkh@realtek.com */
		if ((value >= 0) && (value <= 5)) {
			value += 10;
			*pparam += value << (4 * (len - 1 - i));
			continue;
		}
	}
}

EXPORT_SYMBOL_GPL(rtkcr_chk_param);

void rtkcr_set_mis_gpio(u32 gpio_num, u8 ctl)
{
	u32 reginfo;
	u32 reg_tmp = 0;
	u32 bit_tmp = 0;

	reginfo = 0;

	if (gpio_num > MAX_MIS_GPIO_CNT) {
		if(gpio_num != 0xff)
			WARN_ON(1);
		return;
	} else {
		if (mis_gpio_mux_tbl[gpio_num][0] == MIS_GPIO_UNKNOW) {
			WARN_ON(1);
			return;
		}
		reg_tmp = ((gpio_num & 0xffffffe0) >> 5) << 2;
		bit_tmp = (gpio_num & 0x1fUL);

		mmcinfo("reg_tmp=0x%x; bit_tmp=%d\n", reg_tmp, bit_tmp);
	}

	/* Set data */
	if (ctl & DIR_OUT) {
		mmcinfo("MIS_GPDATO_BASE = 0x%x\n", MIS_GPDATO_BASE);
		if (ctl & GPIO_H) {
			mmcinfo("\n");
			reginfo =
			    cr_readl(MIS_GPDATO_BASE +
				     reg_tmp) | (0x01UL << bit_tmp);
		} else {
			mmcinfo("\n");

			reginfo =
			    cr_readl(MIS_GPDATO_BASE +
				     reg_tmp) & ~(0x01UL << bit_tmp);

		}
		mmcinfo("\n");
		cr_writel(reginfo, MIS_GPDATO_BASE + reg_tmp);

		mmcinfo("0x%x = 0x%08x\n",
			MIS_GPDATO_BASE + reg_tmp,
			cr_readl(MIS_GPDATO_BASE + reg_tmp));
	}

	/* Set dir */
	if ((ctl & DIR_SKIP) == 0) {
		mmcinfo("\n");
		if (ctl & DIR_OUT)
			reginfo =
			    cr_readl(MIS_GPDIR_BASE +
				     reg_tmp) | (0x01UL << bit_tmp);
		else
			reginfo =
			    cr_readl(MIS_GPDIR_BASE +
				     reg_tmp) & ~(0x01UL << bit_tmp);

		cr_writel(reginfo, MIS_GPDIR_BASE + reg_tmp);
		mmcinfo("0x%x = 0x%08x\n",
			MIS_GPDIR_BASE + reg_tmp,
			cr_readl(MIS_GPDIR_BASE + reg_tmp));
	}

	mmcinfo("\n");
	/* Set pin share */
	if ((ctl & MUX_SKIP) == 0) {
		mmcinfo("\n");
		reginfo = cr_readl(M_MUX(gpio_num))
		    | (0x1fUL << M_SHT(gpio_num));
		cr_writel(reginfo, M_MUX(gpio_num));
		mmcinfo("0x%x = 0x%08x\n",
			M_MUX(gpio_num), cr_readl(M_MUX(gpio_num)));
	}
}

EXPORT_SYMBOL_GPL(rtkcr_set_mis_gpio);

void rtkcr_set_iso_gpio(u32 gpio_num, u8 ctl)
{
	u32 reginfo = 0;
	u32 reg_tmp = 0;
	u32 bit_tmp = 0;

	if (gpio_num > MAX_ISO_GPIO_CNT) {
		WARN_ON(1);
		return;
	} else {
		if (iso_gpio_mux_tbl[gpio_num][0] == ISO_GPIO_UNKNOW) {
			WARN_ON(1);
			return;
		}
		reg_tmp = ((gpio_num & 0xffffffe0) >> 5) << 2;
		bit_tmp = (gpio_num & 0x1fUL);
	}

	/* Set data */
	if (ctl & DIR_OUT) {

		if (ctl & GPIO_H)
			reginfo =
			    cr_readl(ISO_GPDATO_BASE +
				     reg_tmp) | (0x01UL << bit_tmp);
		else
			reginfo =
			    cr_readl(ISO_GPDATO_BASE +
				     reg_tmp) & ~(0x01UL << bit_tmp);

		cr_writel(reginfo, ISO_GPDATO_BASE + reg_tmp);

	}

	/* Set dir */
	if ((ctl & DIR_SKIP) == 0) {
		if (ctl & DIR_OUT)
			reginfo =
			    cr_readl(ISO_GPDIR_BASE +
				     reg_tmp) | (0x01UL << bit_tmp);
		else
			reginfo =
			    cr_readl(ISO_GPDIR_BASE +
				     reg_tmp) & ~(0x01UL << bit_tmp);
		cr_writel(reginfo, ISO_GPDIR_BASE + reg_tmp);
	}

	/* Set pin share */
	if ((ctl & MUX_SKIP) == 0) {
		reginfo = cr_readl(I_MUX(gpio_num))
		    | (0x1fUL << I_SHT(gpio_num));
		cr_writel(reginfo, I_MUX(gpio_num));

	}
}

EXPORT_SYMBOL_GPL(rtkcr_set_iso_gpio);

#define BOOT_TYPE_DUMMY_REG 0xb8060120
#define BTYPE_MAGIC_NUM     0x298
#define BTYPE_MAGIC_SHT     20
#define BTYPE_MAGIC_MASK    (0xFFFUL<<BTYPE_MAGIC_SHT)
#define BTYPE_FLASH_SHT     4
#define BTYPE_FLASH_MASK    (0x3UL<<BTYPE_FLASH_SHT)
#define BTYPE_TYPE_SHT      0
#define BTYPE_TYPE_MASK     (0x7UL)

#define NAND_TPYE       (0UL)
#define SPI_TPYE        (1UL)
#define SPI_NAND_TPYE   (2UL)
#define EMMC_TPYE       (3UL)
u8 get_emmc_type_select(const char *drv_name)
{
#if 1
	return EMMC_TPYE;
#else
	u8 res = 0xff;
	u32 reginfo;

	reginfo = cr_readl(BOOT_TYPE_DUMMY_REG);

	if ((reginfo & BTYPE_MAGIC_MASK) ==
	    (BTYPE_MAGIC_NUM << BTYPE_MAGIC_SHT)) {

		if ((reginfo & BTYPE_FLASH_MASK) ==
		    (EMMC_TPYE << BTYPE_FLASH_SHT)) {
			res = (u8) (reginfo & BTYPE_TYPE_MASK);
		}
	}

	return res;
#endif
}

EXPORT_SYMBOL_GPL(get_emmc_type_select);

/* end of file */
