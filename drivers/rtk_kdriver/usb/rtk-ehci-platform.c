#include <linux/kernel.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/usb.h>
#include <asm/io.h>
#include <rtk_kdriver/rtk_crt.h>
#include <rtk_kdriver/rtk_gpio.h>
#include <rbus/usb_top_reg.h>
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
#include <rbus/usb_ex_top_reg.h>
#endif

#include <linux/usb/hcd.h>
#include <linux/usb/ehci_def.h>
#include "ehci_reg.h"
#include "../../usb/host/ehci.h"
#include "rtk-ehci-platform-config.h"

#define USB_PHY_DELAY                         100
#define USB_HUB_CHECK_TIME                    500

#define ehci_plat_dbg(fmt, args...)           pr_debug("[ehci] dbg, " fmt, ## args)
#define ehci_plat_info(fmt, args...)          pr_info("[ehci] info, " fmt, ## args)
#define ehci_plat_warn(fmt, args...)          pr_warn("[ehci] warn, " fmt, ## args)

static bool hub_polling_check_running = false, poll_check_suspend = true;
static struct timer_list hub_polling_check_timer;
static DEFINE_MUTEX(mutex);
struct rtk_ehci_platform_driver *g_rtk_ehci_platform_driver;
static unsigned int debug_ctrl_flag = 0;

#define NO_HUB_POLLING_CHECK  (0x1)

/* Function delcaration */
static void hub_polling_check(unsigned int arg);

static unsigned long usb2_phy_vstatus_regs[] = {
	USB_TOP_VSTATUS_reg,
	USB_TOP_VSTATUS_2port_reg,
};

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
static unsigned long usb2_ex_phy_vstatus_regs[] = {
	USB_EX_TOP_VSTATUS_reg,
};
#endif

static int is_invalid_port_num(int port1, int total) {
	if (port1 < 1 || port1 > total)
		return -EINVAL;
	return 0;
}
/* We only pass E0~F7 phy_reg, although E0~F7 is just for writing.
 * For reading purpose, the _get_usb2_phy will do the mapping task.
 * E0 ~ F7 --> C0 ~ D7
 * */
static int is_invalid_phy_reg(int phy_reg) {
	if (phy_reg < 0xE0 || phy_reg > 0xF7)
		return -EINVAL;
	return 0;
}
/*-----------------------------------------------------------------
 * U2 Phy Setting API
 * The USB2 Phy registers can be accessed by UTMI interface.
 *-----------------------------------------------------------------*/
/*-----------------------------------------------
 * Func : _get_usb2_phy
 *
 * Desc : read usb2 phy register with UTMI
 *
 * Parm : port1     : port index (start from 1)
 *        phy_reg   : phy register address
 *
 * Retn : others : phy register value
 *        -1 : failed
 *-----------------------------------------------*/
static int _get_usb2_phy(int port1, int phy_reg) {
	int phy_value;
	unsigned long addr;

	if (is_invalid_port_num(port1, U2_PHY_CONFIG_COUNT)) {
		ehci_plat_warn("get_usb2_phy failed, invalid port - %d\n", port1);
		return -1;
	}
	if (is_invalid_phy_reg(phy_reg)) {
		ehci_plat_warn("get_usb2_phy failed, invalid phy_reg 0x%x\n", phy_reg);
		return -1;
	}

	addr = HMAC_HOST_EHCI_INSNREG05_reg;

	rtd_outl(addr, 0x00020000 | (phy_reg & 0x0f) << 8 | (port1 << 13));
	udelay(USB_PHY_DELAY);

	rtd_outl(addr, 0x00020000 | (phy_reg & 0xd0) << 4 | (port1 << 13));
	udelay(USB_PHY_DELAY);

	phy_value = rtd_inl(addr) & 0xff;

	return (phy_value & 0xff);
}

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
static int _get_usb2_ex_phy(int port1, int phy_reg) {
	int phy_value;
	unsigned long addr;

	if (is_invalid_port_num(port1, U2_EX_PHY_CONFIG_COUNT)) {
		ehci_plat_warn("get_usb2_phy failed, invalid port - %d\n", port1);
		return -1;
	}
	if (is_invalid_phy_reg(phy_reg)) {
		ehci_plat_warn("get_usb2_phy failed, invalid phy_reg 0x%x\n", phy_reg);
		return -1;
	}

	addr = HMAC_HOST_EHCI_EX_INSNREG05_reg;

	rtd_outl(addr, 0x00020000 | (phy_reg & 0x0f) << 8 | (port1 << 13));
	udelay(USB_PHY_DELAY);

	rtd_outl(addr, 0x00020000 | (phy_reg & 0xd0) << 4 | (port1 << 13));
	udelay(USB_PHY_DELAY);

	phy_value = rtd_inl(addr) & 0xff;

	return (phy_value & 0xff);
}
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */

/*-----------------------------------------------
 * Func : _set_usb2_phy
 *
 * Desc : set usb2 phy register with UTMI
 *
 * Parm : port1     : port index (start from 1)
 *        phy_reg   : phy register address
 *        phy_value : phy register value
 *
 * Retn : 0 : successed,
 *       -1 : failed
 *-----------------------------------------------*/
static int _set_usb2_phy(int port1, int phy_reg, int phy_value) {
	int value;
	unsigned long addr;

	if (is_invalid_port_num(port1, U2_PHY_CONFIG_COUNT)) {
		ehci_plat_warn("set_usb2_phy failed, invalid port - %d\n", port1);
		return -1;
	}

	if (is_invalid_phy_reg(phy_reg)) {
		ehci_plat_warn("get_usb2_phy failed, invalid phy_reg 0x%x\n", phy_reg);
		return -1;
	}

	addr = HMAC_HOST_EHCI_INSNREG05_reg;

	do {
        // write value
		rtd_outl(usb2_phy_vstatus_regs[port1 - 1], phy_value);
		udelay(USB_PHY_DELAY);

		rtd_outl(addr, 0x00020000 | (phy_reg & 0x0f) << 8 | (port1 << 13));
		udelay(USB_PHY_DELAY);

		rtd_outl(addr, 0x00020000 | (phy_reg & 0xf0) << 4 | (port1 << 13));
		udelay(USB_PHY_DELAY);

		value = _get_usb2_phy(port1, phy_reg);

		if ((phy_value & 0xff) != value)
			ehci_plat_warn("%s, port %d phy_reg 0x%.2x set 0x%x get 0x%x <--- not matched \n",
						__func__, port1, phy_reg, phy_value & 0xff, value);
		else
			ehci_plat_dbg("%s, port %d phy_reg 0x%.2x set 0x%x get 0x%x\n",
						__func__, port1, phy_reg, phy_value & 0xff, value);

	} while(0); /* just write once */

	return value;
}

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
static int _set_usb2_ex_phy(int port1, int phy_reg, int phy_value) {
	int value;
	unsigned long addr;

	if (is_invalid_port_num(port1, U2_EX_PHY_CONFIG_COUNT)) {
		ehci_plat_warn("set_usb2_phy failed, invalid port - %d\n", port1);
		return -1;
	}

	if (is_invalid_phy_reg(phy_reg)) {
		ehci_plat_warn("get_usb2_phy failed, invalid phy_reg 0x%x\n", phy_reg);
		return -1;
	}

	addr = HMAC_HOST_EHCI_EX_INSNREG05_reg;

	do {
        // write value
		rtd_outl(usb2_ex_phy_vstatus_regs[port1 - 1], phy_value);
		udelay(USB_PHY_DELAY);

		rtd_outl(addr, 0x00020000 | (phy_reg & 0x0f) << 8 | (port1 << 13));
		udelay(USB_PHY_DELAY);

		rtd_outl(addr, 0x00020000 | (phy_reg & 0xf0) << 4 | (port1 << 13));
		udelay(USB_PHY_DELAY);

		value = _get_usb2_ex_phy(port1, phy_reg);

		if ((phy_value & 0xff) != value)
			ehci_plat_warn("%s, port %d phy_reg 0x%.2x set 0x%x get 0x%x <--- not matched \n",
					__func__, port1, phy_reg, phy_value & 0xff, value);
		else
			ehci_plat_dbg("%s, port %d phy_reg 0x%.2x set 0x%x get 0x%x\n",
					__func__, port1, phy_reg, phy_value & 0xff, value);


	} while(0); /* just write once */

	return value;
}
#endif

/*-----------------------------------------------
 * Func : _usb2_load_phy_setting
 *
 * Desc : load usb2 phy setting
 *
 * Parm : port1 : port index (start from 1)
 *        p_reg : register list
 *        n_reg : register value
 *
 * Retn : N/A
 *-----------------------------------------------*/
void _usb2_load_phy_setting(
    U2_PHY_REGISTER*    p_reg,
    unsigned int        n_reg
    )
{
    while(n_reg--)
    {
        _set_usb2_phy(p_reg->port1, p_reg->addr, p_reg->val);
        p_reg++;
    }
}
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
void _usb2_ex_load_phy_setting(
    U2_PHY_REGISTER*    p_reg,
    unsigned int        n_reg
    )
{
    while(n_reg--)
    {
        _set_usb2_ex_phy(p_reg->port1, p_reg->addr, p_reg->val);
        p_reg++;
    }
}
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */

/*-----------------------------------------------
 * Func : ehci_usb2_phy_init
 *
 * Desc : load usb2 phy setting
 *
 * Retn : N/A
 *-----------------------------------------------*/
void ehci_usb2_phy_init(void)
{
    ehci_plat_dbg("---- %s start ----\n", __func__);

    _usb2_load_phy_setting(u2_phy_config.p_reg_table, u2_phy_config.n_reg);
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    _usb2_ex_load_phy_setting(u2_ex_phy_config.p_reg_table, u2_ex_phy_config.n_reg);
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */
    ehci_plat_dbg("---- %s complete ----\n", __func__);
}


/*-----------------------------------------------
 * Func : usb2_phy_restore
 *
 * Desc : resrote part of the phys setting phy setting
 *
 * Parm : port1 : port index (start from 1)
 *        p_reg : register list
 *        n_reg : register value
 *
 * Retn : N/A
 *-----------------------------------------------*/
void usb2_phy_restore(int portnum)
{
	return;
}
EXPORT_SYMBOL_GPL(usb2_phy_restore);


int set_usb2_phy_reg (
	unsigned char       port1,
	unsigned char       page,
	unsigned char       addr,
	unsigned char       val)
{
	if (is_invalid_port_num(port1, U2_PHY_CONFIG_COUNT)) {
		pr_warn("set_u2_phy_reg failed, invalid port number - %d\n", port1);
		return -1;
	}

	if (page > 3) {
		pr_warn("set_u2_phy_reg failed, invalid page - %d\n", page);
		return -1;
	}

	_set_usb2_phy(port1, 0xF4, (page<<5) | 0x9b);  // bit [6:5] : page select = page
	_set_usb2_phy(port1, addr, val);
	_set_usb2_phy(port1, 0xF4, 0x9b);  // bit [6:5] : page select = 0
	return 0;
}

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
int set_usb2_ex_phy_reg (
	unsigned char       phy,
	unsigned char       page,
	unsigned char       addr,
	unsigned char       val)
{
	if (is_invalid_port_num(phy, U2_EX_PHY_CONFIG_COUNT)) {
		pr_warn("set_u2_phy_reg failed, invalid phy id - %d\n", phy);
		return -1;
	}

	if (page > 3)
	{
		pr_warn("set_u2_phy_reg failed, invalid page - %d\n", page);
		return -1;
	}

	_set_usb2_ex_phy(phy, 0xF4, (page<<5) | 0x9b);  // bit [6:5] : page select = page
	_set_usb2_ex_phy(phy, addr, val);
	_set_usb2_ex_phy(phy, 0xF4, 0x9b);  // bit [6:5] : page select = 0
	return 0;
}
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */

int get_usb2_phy_reg (
	unsigned char       phy,
	unsigned char       page,
	unsigned char       addr
	)
{
	int ret;

	if (is_invalid_port_num(phy, U2_PHY_CONFIG_COUNT)) {
		pr_warn("set_u2_phy_reg failed, invalid phy id - %d\n", phy);
		return -1;
	}

	if (page > 3)
	{
		pr_warn("set_u2_phy_reg failed, invalid page - %d\n", page);
		return -1;
	}

	_set_usb2_phy(phy, 0xF4, (page<<5) | 0x9b);  // bit [6:5] : page select = page
	ret = _get_usb2_phy(phy, addr);
	_set_usb2_phy(phy, 0xF4, 0x9b);  // bit [6:5] : page select = 0

	return ret;
}

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
int get_usb2_ex_phy_reg (
	unsigned char       phy,
	unsigned char       page,
	unsigned char       addr
	)
{
	int ret;

	if (is_invalid_port_num(phy, U2_EX_PHY_CONFIG_COUNT)) {
		pr_warn("set_u2_phy_reg failed, invalid phy id - %d\n", phy);
		return -1;
	}

	if (page > 3)
	{
		pr_warn("set_u2_phy_reg failed, invalid page - %d\n", page);
		return -1;
	}

	_set_usb2_ex_phy(phy, 0xF4, (page<<5) | 0x9b);  // bit [6:5] : page select = page
	ret = _get_usb2_ex_phy(phy, addr);
	_set_usb2_ex_phy(phy, 0xF4, 0x9b);  // bit [6:5] : page select = 0

	return ret;
}
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */

/*-----------------------------------------------
 * Func : ehci_usb2_set_phy_from_otp
 *
 * Desc : set usb2 phy val from OTP
 *
 * Retn : N/A
 *-----------------------------------------------*/
void ehci_usb2_set_phy_from_otp(void)
{
#define SQUELCH_LEVEL_shift   (4)
#define SQUELCH_LEVEL_mask    (0xF0)
    int i, shift;
    unsigned int val, mask;
    unsigned int efuse1 = rtd_inl(0xb8038090), efuse2 = rtd_inl(0xb8038134); // These two addresses are given by HW SD

    ehci_plat_dbg("---- %s start ----\n", __func__);
    ehci_plat_info("efuse1 = 0x%x, efuse2 = 0x%x \n", efuse1, efuse2);

    if ((efuse1 & 0x1) | (efuse2 & 0x1)) {
        /* USB TOP, port1:bit[19:16] and port2;bit[23:20] */
        for (i = 0; i < U2_PHY_CONFIG_COUNT; i++) {
            shift = (i * 4) + 16;
            mask = 0xF << shift;
            val = (((efuse1 & mask) | (efuse2 & mask)) >> shift) & 0xF;
            set_usb2_phy_reg(i + 1, 0x0, 0xe7, ((get_usb2_phy_reg(i + 1, 0x0, 0xe7) & ~SQUELCH_LEVEL_mask) | (val << SQUELCH_LEVEL_shift)));
            ehci_plat_info("set sequlch level from otp. port(%d), val=0x%x(7:4) \n", i + 1, get_usb2_phy_reg(i + 1, 0x0, 0xe7));
        }

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
        /* USB EX TOP, port1:bit[27:24] */
        for (i = 0; i < U2_EX_PHY_CONFIG_COUNT; i++) {
            shift = (i * 4) + 24;
            mask = 0xF << shift;
            val = (((efuse1 & mask) | (efuse2 & mask)) >> shift) & 0xF;
            set_usb2_ex_phy_reg(i + 1, 0x0, 0xe7, ((get_usb2_ex_phy_reg(i + 1, 0x0, 0xe7) & ~SQUELCH_LEVEL_mask) | (val << SQUELCH_LEVEL_shift)));
            ehci_plat_info("set sequlch level from otp. ex_port(%d), val=0x%x(7:4) \n", i + 1, get_usb2_ex_phy_reg(i + 1, 0x0, 0xe7));
        }
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */
    }
    ehci_plat_dbg("---- %s complete ----\n", __func__);
#undef SQUELCH_LEVEL_shift
#undef SQUELCH_LEVEL_mask
}

void ehci_usb2_set_disconnect_level_from_otp(void)
{
#define DISCONNECT_LEVEL_shift   (4)
#define DISCONNECT_LEVEL_mask    (0xF0)
    int i, shift;
    unsigned int val, mask;
    unsigned int efuse1 = rtd_inl(0xb8038148), efuse2 = rtd_inl(0xb80381a0); // These two addresses are given by HW SD

    ehci_plat_dbg("---- %s start ----\n", __func__);
    ehci_plat_info("efuse1 = 0x%x, efuse2 = 0x%x \n", efuse1, efuse2);

    if ((efuse1 & 0x1) | (efuse2 & 0x1)) {
        /* USB TOP, port0:bit[19:16] and port1;bit[23:20] */
        for (i = 0; i < U2_PHY_CONFIG_COUNT; i++) {
            shift = (i * 4) + 16;
            mask = 0xF << shift;
            val = (((efuse1 & mask) | (efuse2 & mask)) >> shift) & 0xF;
            set_usb2_phy_reg(i + 1, 0x0, 0xe4, ((get_usb2_phy_reg(i + 1, 0x0, 0xe4) & ~DISCONNECT_LEVEL_mask) | (val << DISCONNECT_LEVEL_shift)));
            ehci_plat_info("set disconnect level from otp. port(%d), val=0x%x(7:4) \n", i + 1, get_usb2_phy_reg(i + 1, 0x0, 0xe4));
        }

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
        /* USB EX TOP, port1:bit[27:24] */
        for (i = 0; i < U2_EX_PHY_CONFIG_COUNT; i++) {
            shift = (i * 4) + 24;
            mask = 0xF << shift;
            val = (((efuse1 & mask) | (efuse2 & mask)) >> shift) & 0xF;
            set_usb2_ex_phy_reg(i + 1, 0x0, 0xe4, ((get_usb2_ex_phy_reg(i + 1, 0x0, 0xe4) & ~DISCONNECT_LEVEL_mask) | (val << DISCONNECT_LEVEL_shift)));
            ehci_plat_info("set disconnect level from otp. ex_port(%d), val=0x%x(7:4) \n", i + 1, get_usb2_ex_phy_reg(i + 1, 0x0, 0xe4));
        }
#endif /* CONFIG_USB_RTK_USB2_HCD_EX */
    }
    ehci_plat_dbg("---- %s complete ----\n", __func__);
#undef DISCONNECT_LEVEL_shift
#undef DISCONNECT_LEVEL_mask
}

static inline void snps_reset_release(void)
{
    /* SNPS reset. write 1 to reset */
    rtd_outl(0xb8013848, 0x00001e00);
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(0xb8012848, 0x00001a00);
#endif

   /* SNPS release. clear 0 to release */
    rtd_outl(0xb8013848, 0x00001800);
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(0xb8012848, 0x00001800);
#endif
}

/* for internal LDO Trun on */
static inline void internal_ldo_on(void)
{
    rtd_outl(0xb8013848, 0x0002d800); // Usb phy Port 1/ Port 0 LDO_EN / Pll keep alive enable
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(0xb8012848, 0x00025800); // Usb phy Port 2 LDO_EN / Pll keep alive enable
#endif
    /////USB 2.0 Phy Release//////
    rtd_outl(0xb800010c, 0x00000071); // phy reset. release bit of legacy USB2 PHY port2/1/0
}

static inline void wrapper_unmask_usb_interrupt(void) {
    rtd_setbits(0xb8013848, BIT(13));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_setbits(0xb8012848, BIT(13));
#endif
}

/*-----------------------------------------------
 * Func : ehci_usb_mac_init
 *
 * Desc : init usb mac
 *
 * Parm : N/A
 *
 * Retn : N/A
 *-----------------------------------------------*/
void ehci_usb_mac_init(void)
{
    /* UTMI reset. wclr_out: Write 1 clear */
    rtd_outl(USB_TOP_RESET_UTMI_reg, 0x00000001);   //Mac0 p0 UTMI reset
    rtd_outl(USB_TOP_RESET_UTMI_2port_reg, 0x00000001); //Mac0 p1 UTMI reset
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(USB_EX_TOP_RESET_UTMI_reg, 0x00000001); //Mac1 p0 UTMI reset
#endif /* USB_RTK_HCD_EX */

    /* EHCI Run */
    rtd_outl(0xb8013010, 0x00080B01);  // bit[0] EHCI Mac 0 RUN / set USBCMD
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(0xb8012010, 0x00080B01);  // bit[0] EHCI Mac EX RUN / set USBCMD
#endif

    /* Set Configflag register */
    rtd_outl(0xb8013050, 0x00000001);  //release owner / Mac 0//Host software sets this bit as the last action in its process of configuring the Host Controller
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(0xb8012050, 0x00000001);  //release owner / Mac-EX//Host software sets this bit as the last action in its process of configuring the Host Controller
#endif

    /* Prevent Memory Trash.
     * Sram read_bc option:
     * 0: default;  ehci is 33, ohci 9;
     * 1: less one; ehci is 32, ohci 8; */
    rtd_setbits(USB_TOP_USB_CTR0_reg, BIT(18));
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_setbits(USB_EX_TOP_USB_CTR0_reg, BIT(18));
#endif

    /* Set EHCI port power for Mac */
    rtd_outl(0xb8013054, 0x00001000);  // Set EHCI port 1 power for Mac 0
    rtd_outl(0xb8013058, 0x00001000);  // Set EHCI port 2 power for Mac 0
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    rtd_outl(0xb8012054, 0x00001000);  // set EHCI port power for Mac-EX
#endif

    udelay(USB_PHY_DELAY);
}

static bool is_usb_on(void) {
    bool is_mac_clk_on = false, is_mac_release = false, is_phy_release = false;
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    bool is_mac_ex_clk_on = false, is_mac_ex_release = false, is_phy_ex_release = false;
#endif

    // clock: USB MAC
    if (rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_usb2_mask)
        is_mac_clk_on = true;
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    if (rtd_inl(SYS_REG_SYS_CLKEN2_reg) & SYS_REG_SYS_CLKEN2_clken_usb2_ex_mask)
        is_mac_ex_clk_on = true;
#endif

    // reset: USB MAC
    if (rtd_inl(SYS_REG_SYS_SRST2_reg) & SYS_REG_SYS_SRST2_rstn_usb2_mask)
        is_mac_release = true;
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    if (rtd_inl(SYS_REG_SYS_SRST2_reg) & SYS_REG_SYS_SRST2_rstn_usb2_ex_mask)
        is_mac_ex_release = true;
#endif

    // reset: USB PHY
    if (rtd_inl(SYS_REG_SYS_SRST3_reg) & (SYS_REG_SYS_SRST3_rstn_usb2_phy_p0_mask | SYS_REG_SYS_SRST3_rstn_usb2_phy_p1_mask))
        is_phy_release = true;
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    if (rtd_inl(SYS_REG_SYS_SRST3_reg) & SYS_REG_SYS_SRST3_rstn_usb2_phy_p2_mask)
        is_phy_ex_release = true;
#endif

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    return (is_mac_clk_on && is_mac_release && is_phy_release && is_mac_ex_clk_on && is_mac_ex_release && is_phy_ex_release);
#else
    return (is_mac_clk_on && is_mac_release && is_phy_release);
#endif
}

static void rtk_usb_on(void) {
    mutex_lock(&mutex);
    if (!is_usb_on()) {
        CRT_CLK_OnOff(USB, CLK_ON, (void *)2);
        snps_reset_release();
        udelay(320);
        internal_ldo_on();
        udelay(320);
        ehci_usb2_phy_init();
        ehci_usb2_set_phy_from_otp();
        ehci_usb2_set_disconnect_level_from_otp();
        ehci_usb_mac_init();
        wrapper_unmask_usb_interrupt();
    }
#ifdef CONFIG_EHCI_HUB_POLLING_CHECK
    if (poll_check_suspend) {
        poll_check_suspend = false;
        setup_timer(&hub_polling_check_timer, hub_polling_check, NULL);
        mod_timer(&hub_polling_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
    }
#endif
    mutex_unlock(&mutex);
}

static void rtk_usb_off(void) {
#ifdef CONFIG_EHCI_HUB_POLLING_CHECK
    poll_check_suspend = true;
    del_timer_sync(&hub_polling_check_timer);
#endif
    /*CRT_CLK_OnOff(USB, CLK_OFF, 2);*/
}


static int get_usb_crc_error_count(int port1) {
    int crc_cnt;
    if (!USB_TOP_USB_CRC_CNT_get_rx_crc_cnt_en(rtd_inl(USB_TOP_USB_CRC_CNT_reg)))
        return -1;

    switch (port1) {
    case 1:
        crc_cnt = USB_TOP_USB_CRC_CNT_get_rx_crc_cnt_port0(rtd_inl(USB_TOP_USB_CRC_CNT_reg));
        break;
    case 2:
        crc_cnt = USB_TOP_USB_CRC_CNT_get_rx_crc_cnt_port1(rtd_inl(USB_TOP_USB_CRC_CNT_reg));
        break;
    default:
        crc_cnt = -1;
    }
    return crc_cnt;
}
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
static int get_usb_ex_crc_error_count(int port1) {
    int crc_cnt;
    if (!USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_en(rtd_inl(USB_EX_TOP_USB_CRC_CNT_reg)))
        return -1;

    switch (port1) {
    case 1:
        crc_cnt = USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_port0(rtd_inl(USB_EX_TOP_USB_CRC_CNT_reg));
        break;
    default:
        crc_cnt = -1;
    }
    return crc_cnt;
}
#endif

static ssize_t _get_crc_str(char *ptr, size_t count) {
    ssize_t n = 0, len = 0;

    n = scnprintf(ptr, count, "[USB][TOP] CRC_ERR={%d, %d} ", get_usb_crc_error_count(1), get_usb_crc_error_count(2));
    ptr +=n;
    len += n;
    count -= n;
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    n = scnprintf(ptr, count, "[USB][EX-TOP] CRC_ERR={%d} ", get_usb_ex_crc_error_count(1));
    ptr +=n;
    len += n;
    count -= n;
#endif
    return len;
}


/* Dump ehci portsc of each port */
static ssize_t _get_portsc_str(char *ptr, size_t count) {
    char *buf = ptr;
    char *crc_buf;
    ssize_t n = 0, len = 0;

    n = scnprintf(ptr, count, "[USB][TOP] U2 PORTSC={%lx, %lx} U1 PORTSC={%lx, %lx} ",
            rtd_inl(0xb8013054), rtd_inl(0xb8013058),
            rtd_inl(0xb8013454), rtd_inl(0xb8013458));
    ptr += n;
    count -= n;
    len += n;

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    n = scnprintf(ptr, count, "[EX-TOP] U2 PORTSC={%lx} U1 PORTSC={%lx} ",
            rtd_inl(0xb8012054), rtd_inl(0xb8012454));
    ptr += n;
    count -= n;
    len += n;
#endif
    n = scnprintf(ptr, count, "\n");
    ptr += n;
    count -= n;
    len += n;

    // May be called in timer ISR, can't sleep
    crc_buf = kzalloc(count, GFP_ATOMIC);
    if (crc_buf) {
        if (_get_crc_str(crc_buf, count)) {
            n = scnprintf(ptr, count, "%s \n", crc_buf);
            ptr += n;
            count -= n;
            len += n;
        }
        kfree(crc_buf);
    }

    return len;
}

//===========================================================================
// Func : show_portsc
//===========================================================================
static ssize_t show_portsc(struct device *dev, struct device_attribute *attr, char *buf) {
    return _get_portsc_str(buf, 1024);
}
static DEVICE_ATTR(portsc, S_IRUGO,
        show_portsc, NULL);


static ssize_t show_debug_control(struct device *dev, struct device_attribute *attr, char *buf) {
    int n = 0, len = 0, count = 1024;
    char *ptr = buf;

#ifdef CONFIG_EHCI_HUB_POLLING_CHECK
    n = scnprintf(ptr, count, "no_hub_polling_check=%x\n", (debug_ctrl_flag & NO_HUB_POLLING_CHECK));
    ptr += n;
    count -= n;
    len += n;
#endif

    n = scnprintf(ptr, count, "usb_crc_en=%x\n", USB_TOP_USB_CRC_CNT_get_rx_crc_cnt_en(rtd_inl(USB_TOP_USB_CRC_CNT_reg)));
    ptr += n;
    count -= n;
    len += n;

    n = scnprintf(ptr, count, "usb_crc_rst=%x\n", USB_TOP_USB_CRC_CNT_get_rx_crc_cnt_rst(rtd_inl(USB_TOP_USB_CRC_CNT_reg)));
    ptr += n;
    count -= n;
    len += n;

#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    n = scnprintf(ptr, count, "usb_ex_crc_en=%x\n", USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_en(rtd_inl(USB_EX_TOP_USB_CRC_CNT_reg)));
    ptr += n;
    count -= n;
    len += n;

    n = scnprintf(ptr, count, "usb_ex_crc_rst=%x\n", USB_EX_TOP_USB_CRC_CNT_get_rx_crc_cnt_rst(rtd_inl(USB_EX_TOP_USB_CRC_CNT_reg)));
    ptr += n;
    count -= n;
    len += n;
#endif

    return len;
}

static ssize_t set_debug_control(struct device *dev, struct device_attribute *attr, char *buf, size_t count) {
    int val;

#ifdef CONFIG_EHCI_HUB_POLLING_CHECK
    if (sscanf(buf, "no_hub_polling_check=%x", &val))
    {
        if (val) {
            if (!(debug_ctrl_flag & NO_HUB_POLLING_CHECK)) {
                debug_ctrl_flag |= NO_HUB_POLLING_CHECK;
                del_timer_sync(&hub_polling_check_timer);
            }
        }
        else {
            if (debug_ctrl_flag & NO_HUB_POLLING_CHECK) {
                debug_ctrl_flag &= ~NO_HUB_POLLING_CHECK;
                mod_timer(&hub_polling_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
            }
        }
    }
#endif

    if (sscanf(buf, "usb_crc_en=%x", &val))
    {
        if (val)
            rtd_setbits(USB_TOP_USB_CRC_CNT_reg, USB_TOP_USB_CRC_CNT_rx_crc_cnt_en_mask);
        else
            rtd_clearbits(USB_TOP_USB_CRC_CNT_reg, USB_TOP_USB_CRC_CNT_rx_crc_cnt_en_mask);

    }
    else if (sscanf(buf, "usb_crc_rst=%x", &val))
    {
        if (val) {
            rtd_setbits(USB_TOP_USB_CRC_CNT_reg, USB_TOP_USB_CRC_CNT_rx_crc_cnt_rst_mask);
            udelay(10);
            rtd_clearbits(USB_TOP_USB_CRC_CNT_reg, USB_TOP_USB_CRC_CNT_rx_crc_cnt_rst_mask);
        }
    }
#ifdef CONFIG_USB_RTK_USB2_HCD_EX
    else if (sscanf(buf, "usb_ex_crc_en=%x", &val))
    {
        if (val)
            rtd_setbits(USB_EX_TOP_USB_CRC_CNT_reg, USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_en_mask);
        else
            rtd_clearbits(USB_EX_TOP_USB_CRC_CNT_reg, USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_en_mask);
    }
    else if (sscanf(buf, "usb_ex_crc_rst=%x", &val))
    {
        if (val) {
            rtd_setbits(USB_EX_TOP_USB_CRC_CNT_reg, USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_rst_mask);
            udelay(10);
            rtd_clearbits(USB_EX_TOP_USB_CRC_CNT_reg, USB_EX_TOP_USB_CRC_CNT_rx_crc_cnt_rst_mask);
        }
    }
#endif

    return count;
}
static DEVICE_ATTR(debug_control, 0644,
        show_debug_control, set_debug_control);


static void dump_portsc_ex(unsigned char warn) {
    char *buf;
    ssize_t n = 0;

    // May be called in timer ISR, can't sleep
    buf = kzalloc(1024, GFP_ATOMIC);
    if (!buf)
        return;

    n = _get_portsc_str(buf, 1024);
    if (n) {
        if (warn)
            ehci_plat_warn("%s", buf);
        else
            ehci_plat_dbg("%s", buf);
    }
    kfree(buf);
}
#define dump_portsc()       dump_portsc_ex(0)


static int create_sysfs(void *data) {
    struct usb_hcd *hcd = (struct usb_hcd *)data;
    struct device *controller = hcd->self.controller;
    struct usb_device *hdev = hcd->self.root_hub;

    if (!controller)
        return -ENODEV;

    device_create_file(controller, &dev_attr_portsc);
    device_create_file(controller, &dev_attr_debug_control);

    return 0;
}


static struct rtk_ehci_platform_driver *setup_rtk_ehci_platform(void) {
    struct rtk_ehci_platform_driver *rtk_ehci_plat = kzalloc(sizeof(*rtk_ehci_plat), GFP_KERNEL);
    if (!rtk_ehci_plat)
        return NULL;

    rtk_ehci_plat->usb_on = rtk_usb_on;
    rtk_ehci_plat->usb_off = rtk_usb_off;
    rtk_ehci_plat->create_sysfs = create_sysfs;

    kref_init(&rtk_ehci_plat->kref);

    return rtk_ehci_plat;
}

struct rtk_ehci_platform_driver *get_rtk_ehci_platform_driver(void) {
    if (!g_rtk_ehci_platform_driver) {
        g_rtk_ehci_platform_driver = setup_rtk_ehci_platform();
        if (!g_rtk_ehci_platform_driver)
            return NULL;
    }
    mutex_lock(&mutex);
    kref_get(&g_rtk_ehci_platform_driver->kref);
    mutex_unlock(&mutex);
    return g_rtk_ehci_platform_driver;
}
EXPORT_SYMBOL(get_rtk_ehci_platform_driver);

static void release_rtk_ehci_platform(struct kref *kref) {
    if (g_rtk_ehci_platform_driver) {
        kfree(g_rtk_ehci_platform_driver);
        g_rtk_ehci_platform_driver = NULL;
    }
}

void rtk_put_ehci_platform(struct rtk_ehci_platform_driver *rtk_ehci_plat) {
    if (!rtk_ehci_plat)
        return;
    mutex_lock(&mutex);
    kref_put(&rtk_ehci_plat->kref, release_rtk_ehci_platform);
    mutex_unlock(&mutex);
}
EXPORT_SYMBOL(rtk_put_ehci_platform);


/* Port Test Modes.
 * Refs to section 4.14 in Enhanced Host Controller Interface Specification for Universal Serial Bus specification
 * */
int rtk_ehci_port_test_mode(struct usb_device *udev, int port1, int mode) {
    struct usb_hcd *hcd;
    struct ehci_hcd *ehci;
    int i, ret = 0;

    /* is root hub */
    if (!udev->parent) {
        if (udev->maxchild < port1) {
            pr_err("port1 is out of range.1~%d \n", udev->maxchild);
            return -1;
        }
        else if (mode > 5) {
            pr_err("mode is out of range. 0~5 \n");
            return -1;
        }

        usb_lock_device(udev);
        hcd = container_of(udev->bus, struct usb_hcd, self);
        ehci = hcd_to_ehci(hcd);

        /* Disable the periodic and asynchronous schedules */
        ehci_writel(ehci, (ehci->regs->command & ~(CMD_ASE | CMD_PSE)), &ehci->regs->command);

        /* Place all enabled root ports into the suspended state by setting the Suspend bit
        * in each appropriate PORTSC register to a one. */
        for (i = 0; i < udev->maxchild; i++) {
            if (ehci->regs->port_status[i] & PORT_PE) {
                pr_info("port%d(%p) is enable. set to suspend \n", i, &ehci->regs->port_status[i]);
                ehci_writel(ehci, (ehci->regs->port_status[i] | PORT_SUSPEND), &ehci->regs->port_status[i]);
            }
        }

        /* Set the Run/Stop bit in the USBCMD register to a zero and wait for the HCHalted bit in the USBSTS
        * register, to transition to a one. Note that an EHCI host controller implementation may optionally allow
        * port testing with the Run/Stop bit set to a one. However, all host controllers must support port testing
        * with Run/Stop set to a zero and HCHalted set to a one. */
        ehci_writel(ehci, (ehci->regs->command & ~(CMD_RUN)), &ehci->regs->command);
        while (!(ehci->regs->status & STS_HALT))
            pr_err("ehci is not halted yet.... \n");

        /* Set the Port Test Control field in the port under test PORTSC register to the value corresponding to the
        * desired test mode. If the selected test is Test_Force_Enable, then the Run/Stop bit in the USBCMD
        * register must then be transitioned back to one, in order to enable transmission of SOFs out of the port
        * under test. */
        ehci_writel(ehci, ((ehci->regs->port_status[port1 - 1] & ~PORT_TEST(0xf)) | PORT_TEST(mode)), &ehci->regs->port_status[port1 - 1]);
        if (PORT_TEST(mode) == PORT_TEST_FORCE) {
            pr_info("Is Test_Force_Enable. Need to set Run/Stop bit in USBCMD to 1 \n");
            ehci_writel(ehci, (ehci->regs->command | CMD_RUN), &ehci->regs->command);
        }

        ret = 0;

        usb_unlock_device(udev);
    } else {
        pr_err("Only support ports in root_hub \n");
        ret = -1;
    }
    return ret;
}
EXPORT_SYMBOL(rtk_ehci_port_test_mode);

#ifdef CONFIG_EHCI_HUB_POLLING_CHECK
static void hub_polling_check(unsigned int arg) {

    if (poll_check_suspend || hub_polling_check_running || (debug_ctrl_flag & NO_HUB_POLLING_CHECK))
        return;

    hub_polling_check_running = true;

    dump_portsc();


restart_timer:
    hub_polling_check_running = false;
    if (!poll_check_suspend && !(debug_ctrl_flag & NO_HUB_POLLING_CHECK))
        mod_timer(&hub_polling_check_timer, jiffies + msecs_to_jiffies(USB_HUB_CHECK_TIME));
}
#endif
