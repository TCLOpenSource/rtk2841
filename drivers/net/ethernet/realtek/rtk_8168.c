/*
 * rtk_8168.c: RealTek 8168 ethernet driver.
 *
 * Copyright (c) 2002 ShuChen <shuchen@realtek.com.tw>
 * Copyright (c) 2003 - 2007 Francois Romieu <romieu@fr.zoreil.com>
 * Copyright (c) a lot of people too. Please respect their work.
 *
 * See MAINTAINERS file for support contact information.
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/netdevice.h>
#include <linux/etherdevice.h>
#include <linux/delay.h>
#include <linux/ethtool.h>
#include <linux/mii.h>
#include <linux/if_vlan.h>
#include <linux/crc32.h>
#include <linux/in.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/dma-mapping.h>
#include <linux/pm_runtime.h>
#include <linux/prefetch.h>
#include <linux/platform_device.h>
#include <mach/platform.h>
#ifdef CONFIG_ARCH_RTK299O
#include <rbus/crt_reg.h>
#else
#include <rtk_kdriver/rtk_crt.h>
//#include <rbus/sys_reg_reg.h>
//#include <rbus/stb_reg.h>
//#include <rbus/plletn_reg.h>
#endif

#include <mach/rtk_log.h>

#include <asm/io.h>
#include <asm/irq.h>
#include <mach/io.h>

#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/jiffies.h>

#define TAG_NAME		"ETH"

#ifdef CONFIG_ARM64
extern u32 gic_irq_find_mapping(u32 hwirq);
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)            gic_irq_find_mapping(hwirq)
#else
#define IRQ_GET_KERNEL_IRQ_NUM(hwirq)            (hwirq)
#endif

#ifdef CONFIG_ARCH_RTK289X
#define ENABLE_EEEP		1
#define ENABLE_ALDPS		1
#endif
#define ENABLE_WOL		1
//#define ENABLE_WOW		1

#define NWAY_ENABLE 1

#define RTL8168_VERSION "2.3LK-NAPI"
#define MODULENAME "r8168"
#define PFX MODULENAME ": "

#define eth_debug(fmt, args...)\
	rtd_printk(KERN_DEBUG, TAG_NAME, fmt , ## args)
#define eth_info(fmt, args...)\
	rtd_printk(KERN_INFO, TAG_NAME, fmt , ## args)
#define eth_notice(fmt, args...)\
	rtd_printk(KERN_NOTICE, TAG_NAME, fmt , ## args)
#define eth_warning(fmt, args...)\
	rtd_printk(KERN_WARNING, TAG_NAME, fmt , ## args)
#define eth_err(fmt, args...)\
	rtd_printk(KERN_ERR, TAG_NAME, fmt , ## args)

#define R8168_MSG_DEFAULT \
	(NETIF_MSG_DRV | NETIF_MSG_PROBE | NETIF_MSG_IFUP | NETIF_MSG_IFDOWN)

#define TX_SLOTS_AVAIL(tp) \
	(tp->dirty_tx + NUM_TX_DESC - tp->cur_tx)

/* A skbuff with nr_frags needs nr_frags+1 entries in the tx queue */
#define TX_FRAGS_READY_FOR(tp,nr_frags) \
	(TX_SLOTS_AVAIL(tp) >= (nr_frags + 1))

/* Maximum number of multicast addresses to filter (vs. Rx-all-multicast).
   The RTL chips use a 64 element hash table based on the Ethernet CRC. */
static const int multicast_filter_limit = 32;

#define MAX_READ_REQUEST_SHIFT	12
#define TX_DMA_BURST	4	/* Maximum PCI burst, '7' is unlimited */
#define InterFrameGap	0x03	/* 3 means InterFrameGap = the shortest one */

#define R8168_REGS_SIZE		256
#define R8168_NAPI_WEIGHT	64
#define NUM_TX_DESC	64	/* Number of Tx descriptor registers */
#define NUM_RX_DESC	256U	/* Number of Rx descriptor registers */
#define R8168_TX_RING_BYTES	(NUM_TX_DESC * sizeof(struct TxDesc))
#define R8168_RX_RING_BYTES	(NUM_RX_DESC * sizeof(struct RxDesc))

#define RTL8168_TX_TIMEOUT	(6*HZ)
#if NWAY_ENABLE
#define RTL8168_PHY_TIMEOUT	(1*HZ)
#else
#define RTL8168_PHY_TIMEOUT	(3*HZ)
#endif
#define RTL8168_LINK_TIMEOUT	(8*HZ)

#define BASE_ADDR	    0xb8016000

/* write/read MMIO register */
#define RTL_W8(reg, val8)	rtd_outb(ioaddr + (reg), (val8))
#define RTL_W16(reg, val16)	rtd_outw(ioaddr + (reg), (val16))
#define RTL_W32(reg, val32)	rtd_outl(ioaddr + (reg), (val32))
#define RTL_R8(reg)		rtd_inb(ioaddr + (reg))
#define RTL_R16(reg)		rtd_inw(ioaddr + (reg))
#define RTL_R32(reg)		rtd_inl(ioaddr + (reg))

enum rtl_tx_desc_version {
	RTL_TD_0	= 0,
	RTL_TD_1	= 1,
};

#define JUMBO_1K	ETH_DATA_LEN
#define JUMBO_4K	(4*1024 - ETH_HLEN - 2)
#define JUMBO_6K	(6*1024 - ETH_HLEN - 2)
#define JUMBO_7K	(7*1024 - ETH_HLEN - 2)
#define JUMBO_9K	(9*1024 - ETH_HLEN - 2)

enum cfg_version {
	RTL_CFG_0 = 0x00,
	RTL_CFG_1,
};

static int rx_buf_sz = 16383;
static int use_dac;
static struct {
	u32 msg_enable;
} debug = { -1 };

enum rtl_registers {
	MAC0		= 0,	/* Ethernet hardware address. */
	MAC4		= 4,
	MAR0		= 8,	/* Multicast filter. */
	CounterAddrLow		= 0x10,
	CounterAddrHigh		= 0x14,
	CustomLED	= 0x18,
	TxDescStartAddrLow	= 0x20,
	TxDescStartAddrHigh	= 0x24,
	TxHDescStartAddrLow	= 0x28,
	TxHDescStartAddrHigh	= 0x2c,
	FLASH		= 0x30,
	ERSR		= 0x36,
	ChipCmd		= 0x37,
	TxPoll		= 0x38,
	IntrMask	= 0x3c,
	IntrStatus	= 0x3e,

	TxConfig	= 0x40,
#define	TXCFG_AUTO_FIFO			(1 << 7)	/* 8111e-vl */
#define	TXCFG_EMPTY			(1 << 11)	/* 8111e-vl */

	RxConfig	= 0x44,
#define	RX128_INT_EN			(1 << 15)	/* 8111c and later */
#define	RX_MULTI_EN			(1 << 14)	/* 8111c only */
#define	RXCFG_FIFO_SHIFT		13
	/* No threshold before first PCI xfer */
#define	RX_FIFO_THRESH			(7 << RXCFG_FIFO_SHIFT)
#define	RX_EARLY_OFF			(1 << 11)
#define	RXCFG_DMA_SHIFT			8
	/* Unlimited maximum PCI burst. */
#define	RX_DMA_BURST			(3 << RXCFG_DMA_SHIFT)

	RxMissed	= 0x4c,
	Cfg9346		= 0x50,
	Config0		= 0x51,
	Config1		= 0x52,
	Config2		= 0x53,
#define PME_SIGNAL			(1 << 5)	/* 8168c and later */

	Config3		= 0x54,
	Config4		= 0x55,
	Config5		= 0x56,
	MultiIntr	= 0x5c,
	PHYAR		= 0x60,
	PHYstatus	= 0x6c,
	RxMaxSize	= 0xda,
	CPlusCmd	= 0xe0,
	IntrMitigate	= 0xe2,
	RxDescAddrLow	= 0xe4,
	RxDescAddrHigh	= 0xe8,
	EarlyTxThres	= 0xec,	/* 8168. Unit of 32 bytes. */

#define NoEarlyTx	0x3f	/* Max value : no early transmit. */

	MaxTxPacketSize	= 0xec,	/* 8101/8168. Unit of 128 bytes. */

#define TxPacketMax	(8064 >> 7) /* 63 = 0x3f means no early transmit */
#define EarlySize	0x27

	FuncEvent	= 0xf0,
	FuncEventMask	= 0xf4,
	FuncPresetState	= 0xf8,
	FuncForceEvent	= 0xfc,
};

enum rtl8110_registers {
	TBICSR			= 0x64,
	TBI_ANAR		= 0x68,
	TBI_LPAR		= 0x6a,
};

enum rtl8168_8101_registers {
	CSIDR			= 0x64,
	CSIAR			= 0x68,
#define	CSIAR_FLAG			0x80000000
#define	CSIAR_WRITE_CMD			0x80000000
#define	CSIAR_BYTE_ENABLE		0x0f
#define	CSIAR_BYTE_ENABLE_SHIFT		12
#define	CSIAR_ADDR_MASK			0x0fff
#define CSIAR_FUNC_CARD			0x00000000
#define CSIAR_FUNC_SDIO			0x00010000
#define CSIAR_FUNC_NIC			0x00020000
	PMCH			= 0x6f,
	EPHYAR			= 0x80,
#define	EPHYAR_FLAG			0x80000000
#define	EPHYAR_WRITE_CMD		0x80000000
#define	EPHYAR_REG_MASK			0x1f
#define	EPHYAR_REG_SHIFT		16
#define	EPHYAR_DATA_MASK		0xffff
	DLLPR			= 0xd0,
#define	PFM_EN				(1 << 6)
	DBG_REG			= 0xd1,
#define	FIX_NAK_1			(1 << 4)
#define	FIX_NAK_2			(1 << 3)
	TWSI			= 0xd2,
	MCU			= 0xd3,
#define	NOW_IS_OOB			(1 << 7)
#define	TX_EMPTY			(1 << 5)
#define	RX_EMPTY			(1 << 4)
#define	RXTX_EMPTY			(TX_EMPTY | RX_EMPTY)
#define	EN_NDP				(1 << 3)
#define	EN_OOB_RESET			(1 << 2)
#define	LINK_LIST_RDY			(1 << 1)
#define DIS_MCU_CLROOB			BIT(0)
	EFUSEAR			= 0xdc,
#define	EFUSEAR_FLAG			0x80000000
#define	EFUSEAR_WRITE_CMD		0x80000000
#define	EFUSEAR_READ_CMD		0x00000000
#define	EFUSEAR_REG_MASK		0x03ff
#define	EFUSEAR_REG_SHIFT		8
#define	EFUSEAR_DATA_MASK		0xff
};

enum rtl8168_registers {
	LED_FREQ		= 0x1a,
	EEE_LED			= 0x1b,
	ERIDR			= 0x70,
	ERIAR			= 0x74,
#define ERIAR_FLAG			0x80000000
#define ERIAR_WRITE_CMD			0x80000000
#define ERIAR_READ_CMD			0x00000000
#define ERIAR_ADDR_BYTE_ALIGN		4
#define ERIAR_TYPE_SHIFT		16
#define ERIAR_EXGMAC			(0x00 << ERIAR_TYPE_SHIFT)
#define ERIAR_MSIX			(0x01 << ERIAR_TYPE_SHIFT)
#define ERIAR_ASF			(0x02 << ERIAR_TYPE_SHIFT)
#define ERIAR_MASK_SHIFT		12
#define ERIAR_MASK_0001			(0x1 << ERIAR_MASK_SHIFT)
#define ERIAR_MASK_0011			(0x3 << ERIAR_MASK_SHIFT)
#define ERIAR_MASK_0101			(0x5 << ERIAR_MASK_SHIFT)
#define ERIAR_MASK_1111			(0xf << ERIAR_MASK_SHIFT)
	EPHY_RXER_NUM		= 0x7c,
	OCPDR			= 0xb0,	/* OCP GPHY access */
#define OCPDR_WRITE_CMD			0x80000000
#define OCPDR_READ_CMD			0x00000000
#define OCPDR_REG_MASK			0x7f
#define OCPDR_GPHY_REG_SHIFT		16
#define OCPDR_DATA_MASK			0xffff
	OCPAR			= 0xb4,
#define OCPAR_FLAG			0x80000000
#define OCPAR_GPHY_WRITE_CMD		0x8000f060
#define OCPAR_GPHY_READ_CMD		0x0000f060
	GPHY_OCP		= 0xb8,
	RDSAR1			= 0xd0,	/* 8168c only. Undocumented on 8168dp */
	MISC			= 0xf0,	/* 8168e only. */
#define TXPLA_RST			(1 << 29)
#define DISABLE_LAN_EN			(1 << 23) /* Enable GPIO pin */
#define PWM_EN				(1 << 22)
#define RXDV_GATED_EN			(1 << 19)
#define EARLY_TALLY_EN			(1 << 16)
};

enum rtl_register_content {
	/* InterruptStatusBits */
	SYSErr		= 0x8000,
	PCSTimeout	= 0x4000,
	SWInt		= 0x0100,
	TxDescUnavail	= 0x0080,
	RxFIFOOver	= 0x0040,
	LinkChg		= 0x0020,
	RxOverflow	= 0x0010,
	TxErr		= 0x0008,
	TxOK		= 0x0004,
	RxErr		= 0x0002,
	RxOK		= 0x0001,

	/* RxStatusDesc */
	RxBOVF	= (1 << 24),
	RxFOVF	= (1 << 23),
	RxRWT	= (1 << 22),
	RxRES	= (1 << 21),
	RxRUNT	= (1 << 20),
	RxCRC	= (1 << 19),

	/* ChipCmdBits */
	StopReq		= 0x80,
	CmdReset	= 0x10,
	CmdRxEnb	= 0x08,
	CmdTxEnb	= 0x04,
	RxBufEmpty	= 0x01,

	/* TXPoll register p.5 */
	HPQ		= 0x80,		/* Poll cmd on the high prio queue */
	NPQ		= 0x40,		/* Poll cmd on the low prio queue */
	FSWInt		= 0x01,		/* Forced software interrupt */

	/* Cfg9346Bits */
	Cfg9346_Lock	= 0x00,
	Cfg9346_Unlock	= 0xc0,

	/* rx_mode_bits */
	AcceptErr	= 0x20,
	AcceptRunt	= 0x10,
	AcceptBroadcast	= 0x08,
	AcceptMulticast	= 0x04,
	AcceptMyPhys	= 0x02,
	AcceptAllPhys	= 0x01,
#define RX_CONFIG_ACCEPT_MASK		0x3f

	/* TxConfigBits */
	TxInterFrameGapShift = 24,
	TxDMAShift = 8,	/* DMA burst value (0-7) is shift this many bits */

	/* Config1 register p.24 */
	LEDS1		= (1 << 7),
	LEDS0		= (1 << 6),
	Speed_down	= (1 << 4),
	MEMMAP		= (1 << 3),
	IOMAP		= (1 << 2),
	VPD		= (1 << 1),
	PMEnable	= (1 << 0),	/* Power Management Enable */

	/* Config2 register p. 25 */
	ClkReqEn	= (1 << 7),	/* Clock Request Enable */
	MSIEnable	= (1 << 5),	/* 8169 only. Reserved in the 8168. */
	PCI_Clock_66MHz = 0x01,
	PCI_Clock_33MHz = 0x00,

	/* Config3 register p.25 */
	MagicPacket	= (1 << 5),	/* Wake up when receives a Magic Packet */
	LinkUp		= (1 << 4),	/* Wake up when the cable connection is re-established */
	Jumbo_En0	= (1 << 2),	/* 8168 only. Reserved in the 8168b */
	Beacon_en	= (1 << 0),	/* 8168 only. Reserved in the 8168b */

	/* Config4 register */
	Jumbo_En1	= (1 << 1),	/* 8168 only. Reserved in the 8168b */

	/* Config5 register p.27 */
	BWF		= (1 << 6),	/* Accept Broadcast wakeup frame */
	MWF		= (1 << 5),	/* Accept Multicast wakeup frame */
	UWF		= (1 << 4),	/* Accept Unicast wakeup frame */
	Spi_en		= (1 << 3),
	LanWake		= (1 << 1),	/* LanWake enable/disable */
	PMEStatus	= (1 << 0),	/* PME status can be reset by PCI RST# */
	ASPM_en		= (1 << 0),	/* ASPM enable */

	/* TBICSR p.28 */
	TBIReset	= 0x80000000,
	TBILoopback	= 0x40000000,
	TBINwEnable	= 0x20000000,
	TBINwRestart	= 0x10000000,
	TBILinkOk	= 0x02000000,
	TBINwComplete	= 0x01000000,

	/* CPlusCmd p.31 */
	EnableBist	= (1 << 15),	/* 8168 8101 */
	Mac_dbgo_oe	= (1 << 14),	/* 8168 8101 */
	Normal_mode	= (1 << 13),	/* unused */
	Force_half_dup	= (1 << 12),	/* 8168 8101 */
	Force_rxflow_en	= (1 << 11),	/* 8168 8101 */
	Force_txflow_en	= (1 << 10),	/* 8168 8101 */
	Cxpl_dbg_sel	= (1 << 9),	/* 8168 8101 */
	ASF		= (1 << 8),	/* 8168 8101 */
	PktCntrDisable	= (1 << 7),	/* 8168 8101 */
	Mac_dbgo_sel	= 0x001c,	/* 8168 */
	RxVlan		= (1 << 6),
	RxChkSum	= (1 << 5),
	PCIDAC		= (1 << 4),
	PCIMulRW	= (1 << 3),
	INTT_0		= 0x0000,	/* 8168 */
	INTT_1		= 0x0001,	/* 8168 */
	INTT_2		= 0x0002,	/* 8168 */
	INTT_3		= 0x0003,	/* 8168 */

	/* rtl8168_PHYstatus */
	PWR_SAVE	= 0x80,
	TxFlowCtrl	= 0x40,
	RxFlowCtrl	= 0x20,
	_1000bpsF	= 0x10,
	_100bps		= 0x08,
	_10bps		= 0x04,
	LinkStatus	= 0x02,
	FullDup		= 0x01,

	/* _TBICSRBit */
	TBILinkOK	= 0x02000000,

	/* DumpCounterCommand */
	CounterDump	= 0x8,
};

enum rtl_desc_bit {
	/* First doubleword. */
	DescOwn		= (1 << 31), /* Descriptor is owned by NIC */
	RingEnd		= (1 << 30), /* End of descriptor ring */
	FirstFrag	= (1 << 29), /* First segment of a packet */
	LastFrag	= (1 << 28), /* Final segment of a packet */
};

/* Generic case. */
enum rtl_tx_desc_bit {
	/* First doubleword. */
	TD_LSO		= (1 << 27),		/* Large Send Offload */
#define TD_MSS_MAX			0x07ffu	/* MSS value */

	/* Second doubleword. */
	TxVlanTag	= (1 << 17),		/* Add VLAN tag */
};

/* 8102e, 8168c and beyond. */
enum rtl_tx_desc_bit_1 {
	/* Second doubleword. */
#define TD1_MSS_SHIFT			18	/* MSS position (11 bits) */
	TD1_IP_CS	= (1 << 29),		/* Calculate IP checksum */
	TD1_TCP_CS	= (1 << 30),		/* Calculate TCP/IP checksum */
	TD1_UDP_CS	= (1 << 31),		/* Calculate UDP/IP checksum */
};

static const struct rtl_tx_desc_info {
	struct {
		u32 udp;
		u32 tcp;
	} checksum;
	u16 mss_shift;
	u16 opts_offset;
} tx_desc_info = {
	.checksum = {
		.udp	= TD1_IP_CS | TD1_UDP_CS,
		.tcp	= TD1_IP_CS | TD1_TCP_CS
	},
	.mss_shift	= TD1_MSS_SHIFT,
	.opts_offset	= 1
};

enum rtl_rx_desc_bit {
	/* Rx private */
	PID1		= (1 << 18), /* Protocol ID bit 1/2 */
	PID0		= (1 << 17), /* Protocol ID bit 2/2 */

#define RxProtoUDP	(PID1)
#define RxProtoTCP	(PID0)
#define RxProtoIP	(PID1 | PID0)
#define RxProtoMask	RxProtoIP

	IPFail		= (1 << 16), /* IP checksum failed */
	UDPFail		= (1 << 15), /* UDP/IP checksum failed */
	TCPFail		= (1 << 14), /* TCP/IP checksum failed */
	RxVlanTag	= (1 << 16), /* VLAN tag available */
};

#define RsvdMask	0x3fffc000

struct TxDesc {
	__le32 opts1;
	__le32 opts2;
	__le64 addr;
};

struct RxDesc {
	__le32 opts1;
	__le32 opts2;
	__le64 addr;
};

struct ring_info {
	struct sk_buff	*skb;
	u32		len;
	u8		__pad[sizeof(void *) - sizeof(u32)];
};

enum features {
	RTL_FEATURE_WOL		= (1 << 0),
	RTL_FEATURE_MSI		= (1 << 1),
	RTL_FEATURE_GMII	= (1 << 2),
};

struct rtl8168_counters {
	__le64	tx_packets;
	__le64	rx_packets;
	__le64	tx_errors;
	__le32	rx_errors;
	__le16	rx_missed;
	__le16	align_errors;
	__le32	tx_one_collision;
	__le32	tx_multi_collision;
	__le64	rx_unicast;
	__le64	rx_broadcast;
	__le32	rx_multicast;
	__le16	tx_aborted;
	__le16	tx_underun;
};

enum rtl_flag {
	RTL_FLAG_TASK_ENABLED,
	RTL_FLAG_TASK_SLOW_PENDING,
	RTL_FLAG_TASK_RESET_PENDING,
	RTL_FLAG_TASK_PHY_PENDING,
	RTL_FLAG_MAX
};

struct rtl8168_stats {
	u64			packets;
	u64			bytes;
	struct u64_stats_sync	syncp;
};

enum rtl8168_link_status {
	RTL8168_LINK_UP = 0,
	RTL8168_LINK_DOWN,
	RTL8168_LINK_UNKNOWN,
	RTL8168_LINK_MAX
};

enum rtl8168_link_recovery_enable {
	RTL8168_LINK_RECOVERY_DISABLE = 0,
	RTL8168_LINK_RECOVERY_ENABLE
};

enum rtl8168_wol_enable {
	RTL8168_WOL_DISABLE = 0,
	RTL8168_WOL_ENABLE
};

enum rtl8168_snr_enable {
	RTL8168_SNR_DISABLE = 0,
	RTL8168_SNR_ENABLE
};

enum rtl8168_adc_enable {
	RTL8168_ADC_DISABLE = 0,
	RTL8168_ADC_ENABLE
};

typedef struct {
	u32 link_status;
	u32 link_speed;
	u32 rd_dbg;
	u32 clk_fail;
	u32 mcu1;
	u32 mcu2;
	u32 lock_main;
} rtl_phy_status;

struct rtl8168_private {
	unsigned int base_addr;
	struct net_device *dev;
	struct napi_struct napi;
	u32 msg_enable;
	u32 cur_rx; /* Index into the Rx descriptor buffer of next Rx pkt. */
	u32 cur_tx; /* Index into the Tx descriptor buffer of next Rx pkt. */
	u32 dirty_tx;
	u32 link_recovery_enable;
	u32 link_recovery_count;
	u32 link_start_time;
	u32 link_up_time;
	u32 ap_wol_enable;
	struct rtl8168_stats rx_stats;
	struct rtl8168_stats tx_stats;
	struct TxDesc *TxDescArray;	/* 256-aligned Tx descriptor ring */
	struct RxDesc *RxDescArray;	/* 256-aligned Rx descriptor ring */
	dma_addr_t TxPhyAddr;
	dma_addr_t RxPhyAddr;
	void *Rx_databuff[NUM_RX_DESC];	/* Rx data buffers */
	struct ring_info tx_skb[NUM_TX_DESC];	/* Tx data buffers */
	struct timer_list timer;
	struct timer_list link_check_timer;
	u16 cp_cmd;

	u16 event_slow;

	struct mdio_ops {
		void (*write)(struct rtl8168_private *, int, int);
		int (*read)(struct rtl8168_private *, int);
	} mdio_ops;

	struct pll_power_ops {
		void (*down)(struct rtl8168_private *);
		void (*up)(struct rtl8168_private *);
	} pll_power_ops;

	struct jumbo_ops {
		void (*enable)(struct rtl8168_private *);
		void (*disable)(struct rtl8168_private *);
	} jumbo_ops;

	struct csi_ops {
		void (*write)(struct rtl8168_private *, int, int);
		u32 (*read)(struct rtl8168_private *, int);
	} csi_ops;

	int (*set_speed)(struct net_device *, u8 aneg, u16 sp, u8 dpx, u32 adv);
	int (*get_settings)(struct net_device *, struct ethtool_cmd *);
	void (*phy_reset_enable)(struct rtl8168_private *tp);
	void (*phy_set_aldps)(struct rtl8168_private *tp, u32 enable);
	void (*phy_enhance_performance)(struct rtl8168_private *tp, u32 enable);
	void (*hw_start)(struct net_device *);
	unsigned int (*phy_reset_pending)(struct rtl8168_private *tp);
	unsigned int (*link_ok)(u32);
	int (*do_ioctl)(struct rtl8168_private *tp, struct mii_ioctl_data *data, int cmd);

	struct {
		DECLARE_BITMAP(flags, RTL_FLAG_MAX);
		struct mutex mutex;
		struct work_struct work;
	} wk;

	unsigned features;

	struct mii_if_info mii;
	struct rtl8168_counters counters;
	u32 saved_wolopts;
	u32 opts1_mask;

	u32 ocp_base;
	u32 link_status;
	u32 autoneg;
	rtl_phy_status phy_status;
};

MODULE_AUTHOR("Realtek and the Linux r8168 crew <netdev@vger.kernel.org>");
MODULE_DESCRIPTION("RealTek RTL-8168 Gigabit Ethernet driver");
module_param(use_dac, int, 0);
MODULE_PARM_DESC(use_dac, "Enable PCI DAC. Unsafe on 32 bit PCI slot.");
module_param_named(debug, debug.msg_enable, int, 0);
MODULE_PARM_DESC(debug, "Debug verbosity level (0=none, ..., 16=all)");
MODULE_LICENSE("GPL");
MODULE_VERSION(RTL8168_VERSION);

static int eth_init = 1;
static u32 pga_val = 0;
static u32 tapbin_val = 0;
static u32 snr_debug = RTL8168_SNR_DISABLE;
static u32 adc_debug = RTL8168_ADC_DISABLE;
static struct net_device *ndev;
#ifdef ENABLE_WOL
static void rtl_speed_down(struct rtl8168_private *tp);
#endif
#ifdef ENABLE_EEEP
static void rtl8168_mac_eeep_patch(struct rtl8168_private *tp);
#endif
#ifdef CONFIG_PM
struct platform_device *network_devs;
int rtl8168_suspend(struct platform_device *dev, pm_message_t state);
int rtl8168_resume(struct platform_device *dev);
#endif

static void rtl8168_phy_int_disable(struct rtl8168_private *tp);
static void rtl8168_phy_int_enable(struct rtl8168_private *tp);

static void rtl_lock_work(struct rtl8168_private *tp)
{
	mutex_lock(&tp->wk.mutex);
}

static void rtl_unlock_work(struct rtl8168_private *tp)
{
	mutex_unlock(&tp->wk.mutex);
}

#if 0
static void rtl_tx_performance_tweak(struct pci_dev *pdev, u16 force)
{
	pcie_capability_clear_and_set_word(pdev, PCI_EXP_DEVCTL,
			PCI_EXP_DEVCTL_READRQ, force);
}
#endif

struct rtl_cond {
	bool (*check)(struct rtl8168_private *);
	const char *msg;
};

static void rtl_udelay(unsigned int d)
{
	udelay(d);
}

static bool rtl_loop_wait(struct rtl8168_private *tp, const struct rtl_cond *c,
		void (*delay)(unsigned int), unsigned int d, int n,
		bool high)
{
	int i;

	for (i = 0; i < n; i++) {
		delay(d);
		if (c->check(tp) == high)
			return true;
	}
	netif_err(tp, drv, tp->dev, "%s == %d (loop: %d, delay: %d).\n",
			c->msg, !high, n, d);
	return false;
}

static bool rtl_udelay_loop_wait_high(struct rtl8168_private *tp,
		const struct rtl_cond *c,
		unsigned int d, int n)
{
	return rtl_loop_wait(tp, c, rtl_udelay, d, n, true);
}

static bool rtl_udelay_loop_wait_low(struct rtl8168_private *tp,
		const struct rtl_cond *c,
		unsigned int d, int n)
{
	return rtl_loop_wait(tp, c, rtl_udelay, d, n, false);
}

#if 0
static bool rtl_msleep_loop_wait_high(struct rtl8168_private *tp,
		const struct rtl_cond *c,
		unsigned int d, int n)
{
	return rtl_loop_wait(tp, c, msleep, d, n, true);
}
#endif

static bool rtl_msleep_loop_wait_low(struct rtl8168_private *tp,
		const struct rtl_cond *c,
		unsigned int d, int n)
{
	return rtl_loop_wait(tp, c, msleep, d, n, false);
}

#define DECLARE_RTL_COND(name)				\
	static bool name ## _check(struct rtl8168_private *);	\
\
static const struct rtl_cond name = {			\
	.check	= name ## _check,			\
	.msg	= #name					\
};							\
\
static bool name ## _check(struct rtl8168_private *tp)

DECLARE_RTL_COND(rtl_eriar_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(ERIAR) & ERIAR_FLAG;
}

static bool rtl_ocp_reg_failure(struct rtl8168_private *tp, u32 reg)
{
	if (reg & 0xffff0001) {
		netif_err(tp, drv, tp->dev, "Invalid ocp reg %x!\n", reg);
		return true;
	}
	return false;
}

DECLARE_RTL_COND(rtl_ocp_gphy_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(GPHY_OCP) & OCPAR_FLAG;
}

#if 0
static void r8168_phy_ocp_write(struct rtl8168_private *tp, u32 reg, u32 data)
{
	u32 ioaddr = tp->base_addr;

	if (rtl_ocp_reg_failure(tp, reg))
		return;

	RTL_W32(GPHY_OCP, OCPAR_FLAG | (reg << 15) | data);

	rtl_udelay_loop_wait_low(tp, &rtl_ocp_gphy_cond, 25, 10);
}

static u16 r8168_phy_ocp_read(struct rtl8168_private *tp, u32 reg)
{
	u32 ioaddr = tp->base_addr;

	if (rtl_ocp_reg_failure(tp, reg))
		return 0;

	RTL_W32(GPHY_OCP, reg << 15);

	return rtl_udelay_loop_wait_high(tp, &rtl_ocp_gphy_cond, 25, 10) ?
		(RTL_R32(GPHY_OCP) & 0xffff) : ~0;
}
#endif

static void r8168_mac_ocp_write(struct rtl8168_private *tp, u32 reg, u32 data)
{
	u32 ioaddr = tp->base_addr;

	if (rtl_ocp_reg_failure(tp, reg))
		return;

	RTL_W32(OCPDR, OCPAR_FLAG | (reg << 15) | data);
}

static u16 r8168_mac_ocp_read(struct rtl8168_private *tp, u32 reg)
{
	u32 ioaddr = tp->base_addr;

	if (rtl_ocp_reg_failure(tp, reg))
		return 0;

	RTL_W32(OCPDR, reg << 15);

	return RTL_R32(OCPDR);
}

#if 0
#define OCP_STD_PHY_BASE	0xa400

static void r8168g_mdio_write(struct rtl8168_private *tp, int reg, int value)
{
	if (reg == 0x1f) {
		tp->ocp_base = value ? value << 4 : OCP_STD_PHY_BASE;
		return;
	}

	if (tp->ocp_base != OCP_STD_PHY_BASE)
		reg -= 0x10;

	r8168_phy_ocp_write(tp, tp->ocp_base + reg * 2, value);
}

static int r8168g_mdio_read(struct rtl8168_private *tp, int reg)
{
	if (tp->ocp_base != OCP_STD_PHY_BASE)
		reg -= 0x10;

	return r8168_phy_ocp_read(tp, tp->ocp_base + reg * 2);
}

static void mac_mcu_write(struct rtl8168_private *tp, int reg, int value)
{
	if (reg == 0x1f) {
		tp->ocp_base = value << 4;
		return;
	}

	r8168_mac_ocp_write(tp, tp->ocp_base + reg, value);
}

static int mac_mcu_read(struct rtl8168_private *tp, int reg)
{
	return r8168_mac_ocp_read(tp, tp->ocp_base + reg);
}
#endif

DECLARE_RTL_COND(rtl_phyar_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(PHYAR) & 0x80000000;
}

static void r8168_mdio_write(struct rtl8168_private *tp, int reg, int value)
{
	u32 ioaddr = tp->base_addr;

	//eth_debug("==> %s write reg:0x%x data:0x%x \n",tp->dev->name, reg, value);
	RTL_W32(PHYAR, 0x80000000 | (reg & 0x1f) << 16 | (value & 0xffff));

	rtl_udelay_loop_wait_low(tp, &rtl_phyar_cond, 25, 20);
	/*
	 * According to hardware specs a 20us delay is required after write
	 * complete indication, but before sending next command.
	 */
	udelay(20);
}

static int r8168_mdio_read(struct rtl8168_private *tp, int reg)
{
	u32 ioaddr = tp->base_addr;
	int value;

	RTL_W32(PHYAR, 0x0 | (reg & 0x1f) << 16);

	value = rtl_udelay_loop_wait_high(tp, &rtl_phyar_cond, 25, 20) ?
		RTL_R32(PHYAR) & 0xffff : ~0;
	//eth_debug("==> %s read reg:0x%x data:0x%x \n",tp->dev->name, reg, value);

	/*
	 * According to hardware specs a 20us delay is required after read
	 * complete indication, but before sending next command.
	 */
	udelay(20);

	return value;
}

static void rtl_writephy(struct rtl8168_private *tp, int location, u32 val)
{
	tp->mdio_ops.write(tp, location, val);
}

static int rtl_readphy(struct rtl8168_private *tp, int location)
{
	return tp->mdio_ops.read(tp, location);
}

static void rtl_mdio_write(struct net_device *dev, int phy_id, int location,
		int val)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl_writephy(tp, location, val);
}

static int rtl_mdio_read(struct net_device *dev, int phy_id, int location)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	return rtl_readphy(tp, location);
}

#if 0
DECLARE_RTL_COND(rtl_ephyar_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(EPHYAR) & EPHYAR_FLAG;
}

static void rtl_ephy_write(struct rtl8168_private *tp, int reg_addr, int value)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(EPHYAR, EPHYAR_WRITE_CMD | (value & EPHYAR_DATA_MASK) |
			(reg_addr & EPHYAR_REG_MASK) << EPHYAR_REG_SHIFT);

	rtl_udelay_loop_wait_low(tp, &rtl_ephyar_cond, 10, 100);

	udelay(10);
}

static u16 rtl_ephy_read(struct rtl8168_private *tp, int reg_addr)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(EPHYAR, (reg_addr & EPHYAR_REG_MASK) << EPHYAR_REG_SHIFT);

	return rtl_udelay_loop_wait_high(tp, &rtl_ephyar_cond, 10, 100) ?
		RTL_R32(EPHYAR) & EPHYAR_DATA_MASK : ~0;
}
#endif

#if defined(ENABLE_EEEP) || defined(ENABLE_WOW)
static void rtl_eri_write(struct rtl8168_private *tp, int addr, u32 mask,
		u32 val, int type)
{
	u32 ioaddr = tp->base_addr;

	BUG_ON((addr & 3) || (mask == 0));
	RTL_W32(ERIDR, val);
	RTL_W32(ERIAR, ERIAR_WRITE_CMD | type | mask | addr);

	rtl_udelay_loop_wait_low(tp, &rtl_eriar_cond, 100, 100);
}

static u32 rtl_eri_read(struct rtl8168_private *tp, int addr, int type)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(ERIAR, ERIAR_READ_CMD | type | ERIAR_MASK_1111 | addr);

	return rtl_udelay_loop_wait_high(tp, &rtl_eriar_cond, 100, 100) ?
		RTL_R32(ERIDR) : ~0;
}

static void rtl_w1w0_eri(struct rtl8168_private *tp, int addr, u32 mask, u32 p,
		u32 m, int type)
{
	u32 val;

	val = rtl_eri_read(tp, addr, type);
	rtl_eri_write(tp, addr, mask, (val & ~m) | p, type);
}
#endif

static u16 rtl_get_events(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R16(IntrStatus);
}

static void rtl_ack_events(struct rtl8168_private *tp, u16 bits)
{
	u32 ioaddr = tp->base_addr;

	RTL_W16(IntrStatus, bits);
}

static void rtl_irq_disable(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W16(IntrMask, 0);
}

static void rtl_irq_enable(struct rtl8168_private *tp, u16 bits)
{
	u32 ioaddr = tp->base_addr;

	RTL_W16(IntrMask, bits);
}

#define RTL_EVENT_NAPI_RX	(RxOK | RxErr)
#define RTL_EVENT_NAPI_TX	(TxOK | TxErr)
#define RTL_EVENT_NAPI		(RTL_EVENT_NAPI_RX | RTL_EVENT_NAPI_TX)

static void rtl_irq_enable_all(struct rtl8168_private *tp)
{
	rtl_irq_enable(tp, RTL_EVENT_NAPI | tp->event_slow);
}

static void rtl8168_irq_mask_and_ack(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	rtl_irq_disable(tp);
	rtl_ack_events(tp, RTL_EVENT_NAPI | tp->event_slow);
	RTL_R8(ChipCmd);
}

static unsigned int rtl8168_xmii_reset_pending(struct rtl8168_private *tp)
{
	return rtl_readphy(tp, MII_BMCR) & BMCR_RESET;
}

static unsigned int rtl8168_xmii_link_ok(u32 ioaddr)
{
	return RTL_R8(PHYstatus) & LinkStatus;
}

static void rtl8168_xmii_reset_enable(struct rtl8168_private *tp)
{
	unsigned int val;

	val = rtl_readphy(tp, MII_BMCR) | BMCR_RESET;
	rtl_writephy(tp, MII_BMCR, val & 0xffff);
}

/*
 * switch phy page
 */
static void rtl8168_xmii_set_page(struct rtl8168_private *tp, u16 page)
{
	int phy_register = 0x1f;
	u32 phy_write_data = 0x0000;

	phy_write_data |= page;

	rtl_writephy(tp, phy_register, phy_write_data);
}

/*
 * enable ALDPS mode automatically
 * 1. switch page 0x0a43
 * 2. set reg 24(0x18) bit[12]=1,bit[2]=1,bit[1]=1
 * 3. disconnect cable
 * 4. check reg 26(0x1a) bit[14]=1 if phy is in ALDPS mode
 */
static void rtl8168_xmii_set_aldps(struct rtl8168_private *tp, u32 enable)
{
	int phy_register = 0x00;
	u32 phy_write_data = 0x0000;
	int phy_read_data = 0x0000;

	rtl8168_xmii_set_page(tp, 0x0a43);

	phy_write_data = 0x0000;
	phy_register = 0x18;
	phy_read_data = rtl_readphy(tp, phy_register);
	if(enable) {
		phy_write_data = phy_read_data | (0x1000 | 0x0004 | 0x0002);
	} else {
		phy_write_data = 0x2198;
	}
	rtl_writephy(tp, phy_register, phy_write_data);

	rtl8168_xmii_set_page(tp, 0x0000);
}

/*
 * enhance GETN performance
 * 1. Set tapbin R
 * 2. Adjust PGA gain manually
 */
static void rtl8168_xmii_enhance_performance(struct rtl8168_private *tp, u32 enable)
{
	int phy_register = 0x00;
	u32 phy_write_data = 0x0000;
	u32 phy_read_data = 0x0000;

	/* Set tapbin R */
	if(tapbin_val) {
		/* change Page to 0x0bce */
		rtl8168_xmii_set_page(tp, 0x0bce);
		/* set reg16 bit[15:0] */
		phy_write_data = tapbin_val;
		phy_register = 0x10;
		rtl_writephy(tp, phy_register, phy_write_data);
		/* read reg16 bit[15:0] */
		phy_read_data = rtl_readphy(tp, phy_register);
		eth_info("Tapbin val = 0x%04x\n", phy_read_data);
		if (phy_read_data != phy_write_data) {
			eth_warning("==> %s:%s Set tapbin R Fail (0x%04x)\n", tp->dev->name, __func__, phy_read_data);
		}
	}

	/* Adjust PGA gain manually */
	if(pga_val) {
		phy_write_data = 0x0f10 | pga_val;
		phy_register = 0x15;
		rtl_writephy(tp, phy_register, phy_write_data);
		phy_read_data = rtl_readphy(tp, phy_register);
		eth_info("PGA gain val = %08x\n", phy_read_data);
		if (phy_read_data != phy_write_data) {
			eth_warning("==> %s:%s Set PGA gain Fail (0x%04x) \n", tp->dev->name, __func__, phy_read_data);
		}
	}

	rtl8168_xmii_set_page(tp, 0x0000);
}

static void rtl_link_chg_patch(struct rtl8168_private *tp)
{
	struct net_device *dev = tp->dev;

	if (!netif_running(dev))
		return;
}

static void rtl_read_pga_port(struct rtl8168_private *tp)
{
	u32 phy_read_pgaA = 0x0000;
	u32 phy_read_pgaB = 0x0000;
	u32 phy_read_pgaC = 0x0000;
	u32 phy_read_pgaD = 0x0000;
	u32 phy_read_data = 0x0000;

	rtl8168_xmii_set_page(tp, 0x0a8e); /* change page to 0xa8e */
	phy_read_pgaA = rtl_readphy(tp, 0x14); /* reg20, bit[5-9] PGA port A */
	phy_read_pgaA = ((phy_read_pgaA >> 4) & 0x1f) / 2;

	rtl8168_xmii_set_page(tp, 0x0a9e); /* change page to 0xa9e */
	phy_read_pgaB = rtl_readphy(tp, 0x14); /* reg20, bit[5-9] PGA port B */
	phy_read_pgaB = ((phy_read_pgaB >> 4) & 0x1f) / 2;

	rtl8168_xmii_set_page(tp, 0x0aae); /* change page to 0xaae */
	phy_read_pgaC = rtl_readphy(tp, 0x14); /* reg20, bit[5-9] PGA port C */
	phy_read_pgaC = ((phy_read_pgaC >> 4) & 0x1f) / 2;

	rtl8168_xmii_set_page(tp, 0x0abe); /* change page to 0xabe */
	phy_read_pgaD = rtl_readphy(tp, 0x14); /* reg20, bit[5-9] PGA port D */
	phy_read_pgaD = ((phy_read_pgaD >> 4) & 0x1f) / 2;
	eth_info("PGA portA = 0x%x, portB = 0x%x, portC = 0x%x, portD = 0x%x\n",
			phy_read_pgaA, phy_read_pgaB, phy_read_pgaC, phy_read_pgaD);
#if 0
	if(phy_read_pgaA == 0 && phy_read_pgaB == 0) {
		phy_read_pgaA = 7;
	}
	else if((phy_read_pgaB == 0) && (phy_read_pgaA < 0x1 || phy_read_pgaA > 0xe)) {
		phy_read_pgaA = 7;
	}
	else if((phy_read_pgaA == 0) && (phy_read_pgaB < 0x1 || phy_read_pgaB > 0xe)) {
		phy_read_pgaB = 7;
	}
	eth_debug("PGA port A = 0x%x\n", phy_read_pgaA);
	eth_debug("PGA port B = 0x%x\n", phy_read_pgaB);
#endif	

	rtl8168_xmii_set_page(tp, 0x0a88); /* change page to 0xa88 */
	phy_read_data = rtl_readphy(tp, 0x10); /* reg16 bit[0-7] */
	eth_info("Cable length = 0x%x\n", (phy_read_data & 0xff));

	rtl8168_xmii_set_page(tp, 0x0000); /* change page to 0x0 */
}

static void rtl_read_adc_val(struct rtl8168_private *tp)
{
	u32 phy_read_data = 0x0000;
	int i = 0;

	rtl8168_xmii_set_page(tp, 0x0a8e);
	for(i = 0; i < 5; i++) {
		phy_read_data = rtl_readphy(tp, 0x11);
		eth_err("ADC peak port A = 0x%x\n", phy_read_data);
	}

	rtl8168_xmii_set_page(tp, 0x0a9e);
	for(i = 0; i < 5; i++) {
		phy_read_data = rtl_readphy(tp, 0x11);
		eth_err("ADC peak port B = 0x%x\n", phy_read_data);
	}
	rtl8168_xmii_set_page(tp, 0x0000);
}

static void rtl_read_snr_val(struct rtl8168_private *tp)
{
	int phy_register = 0x00;
	u32 phy_write_data = 0x0000;
	u32 phy_read_data = 0x0000;
	int i = 0;

	/* MDI */
	rtl8168_xmii_set_page(tp, 0x0a43);
	phy_write_data = 0xa398;
	phy_register = 0x18;
	rtl_writephy(tp, phy_register, phy_write_data);

	rtl8168_xmii_set_page(tp, 0x0a8c);
	for(i = 0; i < 3; i++) {
		phy_read_data = rtl_readphy(tp, 0x10);
		eth_err("MDI SNR = 0x%4x, %s\n", phy_read_data, (phy_read_data == 0x8000)? "No value":(phy_read_data > 0x50 && phy_read_data < 0x414)? "in range":"out of range");
	}

	rtl8168_xmii_set_page(tp, 0x0a9c);
	for(i = 0; i < 3; i++) {
		phy_read_data = rtl_readphy(tp, 0x10);
		eth_err("MDI SNR = 0x%4x, %s\n", phy_read_data, (phy_read_data == 0x8000)? "No value":(phy_read_data > 0x50 && phy_read_data < 0x414)? "in range":"out of range");
	}
	rtl8168_xmii_set_page(tp, 0x0000);
}

static void rtl_get_phy_status(struct rtl8168_private *tp)
{
	rtl_phy_status *phyStatus = &tp->phy_status;

	/* phy link status */
	phyStatus->link_status = rtl_readphy(tp, 0x01);
	phyStatus->link_status = rtl_readphy(tp, 0x01);

	/* link speed, duplex */
	rtl8168_xmii_set_page(tp, 0x0a43);
	phyStatus->link_speed = rtl_readphy(tp, 0x1a);
	phyStatus->link_speed = rtl_readphy(tp, 0x1a);

	/* rd_dbg0 */
	rtl8168_xmii_set_page(tp, 0x0a60);
	phyStatus->rd_dbg = rtl_readphy(tp, 0x10);

	/* clk_fail_mac/sys */
	rtl8168_xmii_set_page(tp, 0x0c40);
	phyStatus->clk_fail = rtl_readphy(tp, 0x12);

	rtl8168_xmii_set_page(tp, 0x0b90);
	phyStatus->mcu1 = rtl_readphy(tp, 0x13);
	phyStatus->mcu2 = rtl_readphy(tp, 0x14);

	/* lock main */
	rtl8168_xmii_set_page(tp, 0x0a46);
	phyStatus->lock_main = rtl_readphy(tp, 0x15);
	rtl8168_xmii_set_page(tp, 0x0000);
}

static void rtl_read_phy_status(struct rtl8168_private *tp)
{
	rtl_phy_status *phyStatus = &tp->phy_status;
	u32 ioaddr = tp->base_addr;

	rtl_get_phy_status(tp);

	eth_info("MAC link status = 0x%08x, link %s\n",
			RTL_R8(PHYstatus), tp->link_ok(ioaddr) ? "up":"down");
	eth_info("phy link status = 0x%4x, link %s, %uMbps, %s-duplex\n",
			phyStatus->link_status, phyStatus->link_status & BIT(2) ? "up":"down",
			phyStatus->link_speed & BIT(5) ? 1000 : phyStatus->link_speed & BIT(4) ? 100 : 10,
			phyStatus->link_speed & BIT(3) ? "full": "half");

	eth_info("rd_dbg0 = 0x%4x, clk_fail_mac_sys = 0x%04x, mcu = 0x%04x, 0x%04x, lock_main_uc = 0x%4x, %s",
			phyStatus->rd_dbg, phyStatus->clk_fail, phyStatus->mcu1, phyStatus->mcu2,
			phyStatus->lock_main, phyStatus->lock_main & BIT(1) ? "abnormal":"normal");

	if(phyStatus->lock_main & BIT(1)) {
		rtl8168_xmii_set_page(tp, 0x0a46);
		rtl_writephy(tp, 0x15, phyStatus->lock_main & ~BIT(1));
		phyStatus->lock_main = rtl_readphy(tp, 0x15);
		rtl8168_xmii_set_page(tp, 0x0000);
		eth_info("recovery lock_main_uc = 0x%04x\n", phyStatus->lock_main);
		tp->link_recovery_count++;
	}
}

static void __rtl8168_check_link_status(struct net_device *dev,
		struct rtl8168_private *tp,
		u32 ioaddr, bool pm)
{
	u32 i = 0;
	u32 current_link_status = RTL8168_LINK_UNKNOWN;
	u32 current_link_count = 0;
	u32 phy_read_data = 0;

	//eth_debug("==> %s:status check start %d \n",tp->dev->name, rtd_inl(0xB801b690));

#if NWAY_ENABLE
	for (i = 0; i < 5; i++) {
		if (tp->link_ok(ioaddr)) {
			current_link_count++;
		} else {
			if (current_link_count != 0) {
				current_link_count--;
			}
		}
		if(current_link_count >= 3) {
			current_link_status = RTL8168_LINK_UP;
			break;
		} else {
			current_link_status = RTL8168_LINK_DOWN;
		}
		msleep(50);
	}
#else
	if(tp->autoneg == AUTONEG_ENABLE) {
		for (i = 0; i < 5; i++) {
			if (tp->link_ok(ioaddr)) {
				current_link_count++;
			} else {
				if (current_link_count != 0) {
					current_link_count--;
				}
			}
			if(current_link_count >= 3) {
				current_link_status = RTL8168_LINK_UP;
				break;
			} else {
				current_link_status = RTL8168_LINK_DOWN;
			}
			msleep(50);
		}
	} else {
		if (tp->link_ok(ioaddr)) {
			current_link_status = RTL8168_LINK_UP;
		} else {
			current_link_status = RTL8168_LINK_DOWN;
		}
	}
#endif

	if (current_link_status == tp->link_status) {
		//eth_debug("==> %s:%s not change \n",tp->dev->name,__FUNCTION__);
		return;
	}

	//eth_debug("==>  %s:%s done %d \n",tp->dev->name,__FUNCTION__, rtd_inl(0xB801b690));

	if (current_link_status == RTL8168_LINK_UP) {
		tp->link_status = RTL8168_LINK_UP;

		rtl_link_chg_patch(tp);
		/* This is to cancel a scheduled suspend if there's one. */
		if (pm)
			pm_request_resume(&tp->dev->dev);
		netif_carrier_on(dev);
		//eth_debug("==> %s:carrier on %d \n",tp->dev->name, rtd_inl(0xB801b690));

		if (net_ratelimit()) {
			tp->link_up_time = jiffies_to_msecs(jiffies) - tp->link_start_time;
			rtl8168_phy_int_disable(tp);
			rtl8168_xmii_set_page(tp, 0x0a43);
			phy_read_data = rtl_readphy(tp, 0x1a);
			phy_read_data = rtl_readphy(tp, 0x1a);
			netif_info(tp, ifup, dev, "[ETH] link up, %uMbps, %s-duplex\n",
					phy_read_data & BIT(5) ? 1000 : phy_read_data & BIT(4) ? 100 : 10,
					phy_read_data & BIT(3) ? "full": "half");
			rtl8168_xmii_set_page(tp, 0x0000);
#ifdef CONFIG_8168_EVENT
			kobject_uevent(&tp->dev->dev.kobj, KOBJ_LINKUP);
#endif
			//if(pga_val == 0) {
			/* Read Auto PGA gain */
			rtl_read_pga_port(tp);
			//}

			if(adc_debug == RTL8168_ADC_ENABLE) {
				rtl_read_adc_val(tp);
			}

			if(snr_debug == RTL8168_SNR_ENABLE) {
				rtl_read_snr_val(tp);
			}
			rtl8168_phy_int_enable(tp);
		}
	} else {
		tp->link_status = RTL8168_LINK_DOWN;
		tp->link_start_time = jiffies_to_msecs(jiffies);

		netif_carrier_off(dev);
		netif_info(tp, ifdown, dev, "[ETH] link down\n");
#ifdef CONFIG_8168_EVENT
		kobject_uevent(&tp->dev->dev.kobj, KOBJ_LINKDOWN);
#endif
		if (pm)
			pm_schedule_suspend(&tp->dev->dev, 5000);
	}
}

static void rtl8168_check_link_status(struct net_device *dev,
		struct rtl8168_private *tp,
		u32 ioaddr)
{
	__rtl8168_check_link_status(dev, tp, ioaddr, false);
}

#define WAKE_ANY (WAKE_PHY | WAKE_MAGIC | WAKE_UCAST | WAKE_BCAST | WAKE_MCAST)

#ifdef ENABLE_WOL
static u32 __rtl8168_get_wol(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;
	u8 options;
	u32 wolopts = 0;

	options = RTL_R8(Config1);
	if (!(options & PMEnable))
		return 0;

	options = RTL_R8(Config3);
	if (options & LinkUp)
		wolopts |= WAKE_PHY;
	if (options & MagicPacket)
		wolopts |= WAKE_MAGIC;

	options = RTL_R8(Config5);
	if (options & UWF)
		wolopts |= WAKE_UCAST;
	if (options & BWF)
		wolopts |= WAKE_BCAST;
	if (options & MWF)
		wolopts |= WAKE_MCAST;

	return wolopts;
}
#endif

#if 0
static void rtl8168_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl_lock_work(tp);

	wol->supported = WAKE_ANY;
	wol->wolopts = __rtl8168_get_wol(tp);

	rtl_unlock_work(tp);
}

static void __rtl8168_set_wol(struct rtl8168_private *tp, u32 wolopts)
{
	u32 ioaddr = tp->base_addr;
	unsigned int i;
	static const struct {
		u32 opt;
		u16 reg;
		u8  mask;
	} cfg[] = {
		{ WAKE_PHY,   Config3, LinkUp },
		{ WAKE_MAGIC, Config3, MagicPacket },
		{ WAKE_UCAST, Config5, UWF },
		{ WAKE_BCAST, Config5, BWF },
		{ WAKE_MCAST, Config5, MWF },
		{ WAKE_ANY,   Config5, LanWake }
	};
	u8 options;

	RTL_W8(Cfg9346, Cfg9346_Unlock);

	for (i = 0; i < ARRAY_SIZE(cfg); i++) {
		options = RTL_R8(cfg[i].reg) & ~cfg[i].mask;
		if (wolopts & cfg[i].opt)
			options |= cfg[i].mask;
		RTL_W8(cfg[i].reg, options);
	}

	options = RTL_R8(Config2) & ~PME_SIGNAL;
	if (wolopts)
		options |= PME_SIGNAL;
	RTL_W8(Config2, options);

	RTL_W8(Cfg9346, Cfg9346_Lock);
}

static int rtl8168_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl_lock_work(tp);

	if (wol->wolopts)
		tp->features |= RTL_FEATURE_WOL;
	else
		tp->features &= ~RTL_FEATURE_WOL;
	__rtl8168_set_wol(tp, wol->wolopts);

	rtl_unlock_work(tp);

	/*device_set_wakeup_enable(&tp->pci_dev->dev, wol->wolopts); */

	return 0;
}
#endif

static void rtl8168_get_drvinfo(struct net_device *dev,
		struct ethtool_drvinfo *info)
{
	strlcpy(info->driver, MODULENAME, sizeof(info->driver));
	strlcpy(info->version, RTL8168_VERSION, sizeof(info->version));
}

static int rtl8168_get_regs_len(struct net_device *dev)
{
	return R8168_REGS_SIZE;
}

static int rtl8168_set_speed_xmii(struct net_device *dev,
		u8 autoneg, u16 speed, u8 duplex, u32 adv)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	int giga_ctrl, bmcr;
	int rc = -EINVAL;

	rtl_writephy(tp, 0x1f, 0x0000);

	if (autoneg == AUTONEG_ENABLE) {
		int auto_nego;

		auto_nego = rtl_readphy(tp, MII_ADVERTISE);
		auto_nego &= ~(ADVERTISE_10HALF | ADVERTISE_10FULL |
				ADVERTISE_100HALF | ADVERTISE_100FULL);

		if (adv & ADVERTISED_10baseT_Half)
			auto_nego |= ADVERTISE_10HALF;
		if (adv & ADVERTISED_10baseT_Full)
			auto_nego |= ADVERTISE_10FULL;
		if (adv & ADVERTISED_100baseT_Half)
			auto_nego |= ADVERTISE_100HALF;
		if (adv & ADVERTISED_100baseT_Full)
			auto_nego |= ADVERTISE_100FULL;

		auto_nego |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;

		giga_ctrl = rtl_readphy(tp, MII_CTRL1000);
		giga_ctrl &= ~(ADVERTISE_1000FULL | ADVERTISE_1000HALF);

#if 1
		/* The 8100e/8101e/8102e do Fast Ethernet only. */
		if (tp->mii.supports_gmii) {
			if (adv & ADVERTISED_1000baseT_Half)
				giga_ctrl |= ADVERTISE_1000HALF;
			if (adv & ADVERTISED_1000baseT_Full)
				giga_ctrl |= ADVERTISE_1000FULL;
		} else if (adv & (ADVERTISED_1000baseT_Half |
					ADVERTISED_1000baseT_Full)) {
			netif_info(tp, link, dev,
					"PHY does not support 1000Mbps\n");
			goto out;
		}
#endif
		bmcr = BMCR_ANENABLE | BMCR_ANRESTART;

		rtl_writephy(tp, MII_ADVERTISE, auto_nego);
		rtl_writephy(tp, MII_CTRL1000, giga_ctrl);
	} else {
		giga_ctrl = 0;

		if (speed == SPEED_10)
			bmcr = 0;
		else if (speed == SPEED_100)
			bmcr = BMCR_SPEED100;
		else
			goto out;

		if (duplex == DUPLEX_FULL)
			bmcr |= BMCR_FULLDPLX;
	}

	rtl_writephy(tp, MII_BMCR, bmcr);

	rc = 0;
out:
	return rc;
}

static int rtl8168_set_speed(struct net_device *dev,
		u8 autoneg, u16 speed, u8 duplex, u32 advertising)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	int ret;

	ret = tp->set_speed(dev, autoneg, speed, duplex, advertising);
	if (ret < 0)
		goto out;

#if NWAY_ENABLE
	/*
	   if (netif_running(dev)) {
	   mod_timer(&tp->timer, jiffies + RTL8168_PHY_TIMEOUT);
	   }
	 */
#else
	if ((netif_running(dev)) && (autoneg == AUTONEG_DISABLE)) {
		//eth_debug("==> %s:%s %d \n",tp->dev->name,__FUNCTION__,rtd_inl(0xB801b690));
		mod_timer(&tp->timer, jiffies + RTL8168_PHY_TIMEOUT);
	}
#endif
out:
	return ret;
}

static int rtl8168_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	int ret;

	del_timer_sync(&tp->timer);
	del_timer_sync(&tp->link_check_timer);

	rtl_lock_work(tp);
	ret = rtl8168_set_speed(dev, cmd->autoneg, ethtool_cmd_speed(cmd),
			cmd->duplex, cmd->advertising);
	rtl_unlock_work(tp);

	return ret;
}

static netdev_features_t rtl8168_fix_features(struct net_device *dev,
		netdev_features_t features)
{
	if (dev->mtu > TD_MSS_MAX)
		features &= ~NETIF_F_ALL_TSO;

	if (dev->mtu > JUMBO_1K)
		features &= ~NETIF_F_IP_CSUM;

	return features;
}

static void __rtl8168_set_features(struct net_device *dev,
		netdev_features_t features)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	netdev_features_t changed = features ^ dev->features;
	u32 ioaddr = tp->base_addr;

	if (!(changed & (NETIF_F_RXALL | NETIF_F_RXCSUM |
					NETIF_F_HW_VLAN_CTAG_RX)))
		return;

	if (changed & (NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_RX)) {
		if (features & NETIF_F_RXCSUM)
			tp->cp_cmd |= RxChkSum;
		else
			tp->cp_cmd &= ~RxChkSum;

		if (dev->features & NETIF_F_HW_VLAN_CTAG_RX)
			tp->cp_cmd |= RxVlan;
		else
			tp->cp_cmd &= ~RxVlan;

		RTL_W16(CPlusCmd, tp->cp_cmd);
		RTL_R16(CPlusCmd);
	}
	if (changed & NETIF_F_RXALL) {
		int tmp = (RTL_R32(RxConfig) & ~(AcceptErr | AcceptRunt));
		if (features & NETIF_F_RXALL)
			tmp |= (AcceptErr | AcceptRunt);
		RTL_W32(RxConfig, tmp);
	}
}

static int rtl8168_set_features(struct net_device *dev,
		netdev_features_t features)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl_lock_work(tp);
	__rtl8168_set_features(dev, features);
	rtl_unlock_work(tp);

	return 0;
}


static inline u32 rtl8168_tx_vlan_tag(struct sk_buff *skb)
{
	return (skb_vlan_tag_present(skb)) ?
		TxVlanTag | swab16(skb_vlan_tag_get(skb)) : 0x00;
}

static void rtl8168_rx_vlan_tag(struct RxDesc *desc, struct sk_buff *skb)
{
	u32 opts2 = le32_to_cpu(desc->opts2);

	if (opts2 & RxVlanTag)
		__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), swab16(opts2 & 0xffff));
}

static int rtl8168_gset_xmii(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	return mii_ethtool_gset(&tp->mii, cmd);
}

static int rtl8168_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	int rc;

	rtl_lock_work(tp);
	rc = tp->get_settings(dev, cmd);
	rtl_unlock_work(tp);

	return rc;
}

static void rtl8168_get_regs(struct net_device *dev, struct ethtool_regs *regs,
		void *p)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	if (regs->len > R8168_REGS_SIZE)
		regs->len = R8168_REGS_SIZE;

	rtl_lock_work(tp);
	memcpy_fromio(p, (void *)tp->base_addr, regs->len);
	rtl_unlock_work(tp);
}

static u32 rtl8168_get_msglevel(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	return tp->msg_enable;
}

static void rtl8168_set_msglevel(struct net_device *dev, u32 value)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	tp->msg_enable = value;
}

static const char rtl8168_gstrings[][ETH_GSTRING_LEN] = {
	"tx_packets",
	"rx_packets",
	"tx_errors",
	"rx_errors",
	"rx_missed",
	"align_errors",
	"tx_single_collisions",
	"tx_multi_collisions",
	"unicast",
	"broadcast",
	"multicast",
	"tx_aborted",
	"tx_underrun",
};

static int rtl8168_get_sset_count(struct net_device *dev, int sset)
{
	switch (sset) {
		case ETH_SS_STATS:
			return ARRAY_SIZE(rtl8168_gstrings);
		default:
			return -EOPNOTSUPP;
	}
}

DECLARE_RTL_COND(rtl_counters_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(CounterAddrLow) & CounterDump;
}

static void rtl8168_update_counters(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	u32 ioaddr = tp->base_addr;
	struct device *d = &tp->dev->dev;
	struct rtl8168_counters *counters;
	dma_addr_t paddr;
	u32 cmd;

	/*
	 * Some chips are unable to dump tally counters when the receiver
	 * is disabled.
	 */
	if ((RTL_R8(ChipCmd) & CmdRxEnb) == 0)
		return;

	counters = dma_alloc_coherent(d, sizeof(*counters), &paddr, GFP_ATOMIC);
	if (!counters)
		return;
	/* dma_alloc_cohernet use GFP_ATOMIC, memory need to reset 0 */
	memset(counters, 0x0, sizeof(*counters));

	RTL_W32(CounterAddrHigh, (u64)paddr >> 32);
	cmd = (u64)paddr & DMA_BIT_MASK(32);
	RTL_W32(CounterAddrLow, cmd);
	RTL_W32(CounterAddrLow, cmd | CounterDump);

	if (rtl_udelay_loop_wait_low(tp, &rtl_counters_cond, 10, 1000))
		memcpy(&tp->counters, counters, sizeof(*counters));

	RTL_W32(CounterAddrLow, 0);
	RTL_W32(CounterAddrHigh, 0);

	dma_free_coherent(d, sizeof(*counters), counters, paddr);
}

static void rtl8168_get_ethtool_stats(struct net_device *dev,
		struct ethtool_stats *stats, u64 *data)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	ASSERT_RTNL();

	rtl8168_update_counters(dev);

	data[0] = le64_to_cpu(tp->counters.tx_packets);
	data[1] = le64_to_cpu(tp->counters.rx_packets);
	data[2] = le64_to_cpu(tp->counters.tx_errors);
	data[3] = le32_to_cpu(tp->counters.rx_errors);
	data[4] = le16_to_cpu(tp->counters.rx_missed);
	data[5] = le16_to_cpu(tp->counters.align_errors);
	data[6] = le32_to_cpu(tp->counters.tx_one_collision);
	data[7] = le32_to_cpu(tp->counters.tx_multi_collision);
	data[8] = le64_to_cpu(tp->counters.rx_unicast);
	data[9] = le64_to_cpu(tp->counters.rx_broadcast);
	data[10] = le32_to_cpu(tp->counters.rx_multicast);
	data[11] = le16_to_cpu(tp->counters.tx_aborted);
	data[12] = le16_to_cpu(tp->counters.tx_underun);
}

static void rtl8168_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
	switch(stringset) {
		case ETH_SS_STATS:
			memcpy(data, *rtl8168_gstrings, sizeof(rtl8168_gstrings));
			break;
	}
}

static const struct ethtool_ops rtl8168_ethtool_ops = {
	.get_drvinfo		= rtl8168_get_drvinfo,
	.get_regs_len		= rtl8168_get_regs_len,
	.get_link		= ethtool_op_get_link,
	.get_settings		= rtl8168_get_settings,
	.set_settings		= rtl8168_set_settings,
	.get_msglevel		= rtl8168_get_msglevel,
	.set_msglevel		= rtl8168_set_msglevel,
	.get_regs		= rtl8168_get_regs,
	/*	.get_wol		= rtl8168_get_wol,
		.set_wol		= rtl8168_set_wol,*/
	.get_strings		= rtl8168_get_strings,
	.get_sset_count		= rtl8168_get_sset_count,
	.get_ethtool_stats	= rtl8168_get_ethtool_stats,
	.get_ts_info		= ethtool_op_get_ts_info,
};

static int rtl8168_check_mac_version(struct rtl8168_private *tp, struct net_device *dev)
{
	u32 ioaddr = tp->base_addr;
	u32 mask = 0x7cf00000;
	u32 val = 0x50900000;    /* 8168GU */
	u32 reg;

	reg = RTL_R32(TxConfig);
	if ((reg & mask) != val)
		return 0;

	return 1;
}

#if NWAY_ENABLE
static void rtl_phy_work(struct rtl8168_private *tp)
{
	struct timer_list *timer = &tp->timer;
	u32 ioaddr = tp->base_addr;
	unsigned long timeout = RTL8168_PHY_TIMEOUT;

	rtl8168_phy_int_disable(tp);
	if (tp->phy_reset_pending(tp)) {
		/*
		 * A busy loop could burn quite a few cycles on nowadays CPU.
		 * Let's delay the execution of the timer for a few ticks.
		 */
		timeout = HZ/10;
		rtl8168_phy_int_enable(tp);
		goto out_mod_timer;
	}

	rtl8168_phy_int_enable(tp);
	if (tp->link_ok(ioaddr))
		return;

	netif_warn(tp, link, tp->dev, "PHY reset until link up\n");

	rtl8168_phy_int_disable(tp);
	tp->phy_enhance_performance(tp, 1);
#ifdef ENABLE_ALDPS
	tp->phy_set_aldps(tp, 1);
#endif
	tp->phy_reset_enable(tp);
	rtl8168_phy_int_enable(tp);

out_mod_timer:
	mod_timer(timer, jiffies + timeout);
}
#endif

static void rtl_schedule_task(struct rtl8168_private *tp, enum rtl_flag flag)
{
	if (!test_and_set_bit(flag, tp->wk.flags))
		schedule_work(&tp->wk.work);
}

static void rtl8168_phy_timer(unsigned long __opaque)
{
	struct net_device *dev = (struct net_device *)__opaque;
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl_schedule_task(tp, RTL_FLAG_TASK_PHY_PENDING);
}

static void rtl8168_link_timer(unsigned long __opaque)
{
	struct net_device *dev = (struct net_device *)__opaque;
	struct rtl8168_private *tp = netdev_priv(dev);

	if(tp->link_ok(tp->base_addr))
		return;

	rtl8168_phy_int_disable(tp);
	/* Read PGA/cable length */
	rtl_read_pga_port(tp);
	/* Read link status, speed, duplex, and other phy status */
	rtl_read_phy_status(tp);
	rtl8168_phy_int_enable(tp);
}

DECLARE_RTL_COND(rtl_phy_reset_cond)
{
	return tp->phy_reset_pending(tp);
}

static void rtl8168_phy_reset(struct net_device *dev,
		struct rtl8168_private *tp)
{
	//eth_debug("==> %s:%s %d \n",tp->dev->name,__FUNCTION__, rtd_inl(0xB801b690));

	tp->phy_reset_enable(tp);
	rtl_msleep_loop_wait_low(tp, &rtl_phy_reset_cond, 1, 100);
}

static void rtl8168_phy_set_aldps(struct rtl8168_private *tp, u32 enable)
{
	tp->phy_set_aldps(tp, enable);
}

static void rtl8168_phy_enhance_performance(struct rtl8168_private *tp, u32 enable)
{
	tp->phy_enhance_performance(tp, enable);
}

DECLARE_RTL_COND(rtl_phy_status_cond)
{
	rtl_writephy(tp, 0x1f, 0x0a42);
	if((rtl_readphy(tp, 0x10) & 0x3) == 0x3) {
		rtl_writephy(tp, 0x1f, 0x0);
		return 1;
	}

	rtl_writephy(tp, 0x1f, 0x0);
	return 0;
}

static void rtl8168_phy_int_disable(struct rtl8168_private *tp)
{
	u32 data;
	 
	data = r8168_mac_ocp_read(tp, 0x1f1e);
	data &= ~(BIT(1) | BIT(11) | BIT(12));
	r8168_mac_ocp_write(tp, 0x1f1e, data);
}

static void rtl8168_phy_int_enable(struct rtl8168_private *tp)
{
	u32 data;
	 
	data = r8168_mac_ocp_read(tp, 0x1f1e);
	data |= (BIT(1) | BIT(11) | BIT(12));
	r8168_mac_ocp_write(tp, 0x1f1e, data);
}

static void rtl8168_init_phy(struct net_device *dev, struct rtl8168_private *tp)
{
	/*rtl_hw_phy_config(dev); */

	/* Exit oob */
	u32 ioaddr = tp->base_addr;
	RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);

#if NWAY_ENABLE
	rtl8168_phy_enhance_performance(tp, 1);
#ifdef ENABLE_ALDPS
	rtl8168_phy_set_aldps(tp, 1);
#endif
	rtl8168_phy_reset(dev, tp);

	//eth_debug("\033[7;41m %s:%s N-way %d \033[m \n",tp->dev->name,__FUNCTION__, rtd_inl(0xB801b690));

	rtl8168_set_speed(dev, AUTONEG_ENABLE, SPEED_1000, DUPLEX_FULL,
			ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
			ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
			(tp->mii.supports_gmii ?
			 ADVERTISED_1000baseT_Half |
			 ADVERTISED_1000baseT_Full : 0));
#else
#ifdef ENABLE_ALDPS
	rtl8168_phy_set_aldps(tp, 1);
#endif
	rtl8168_phy_enhance_performance(tp, 1);

	//eth_debug("\033[7;41m ==> %s:%s force 100 %d \033[m \n",tp->dev->name,__FUNCTION__, rtd_inl(0xB801b690));

	rtl8168_set_speed(dev, AUTONEG_DISABLE, SPEED_100, DUPLEX_FULL, ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
			ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full);
#endif

	/*
	   if (rtl_tbi_enabled(tp))
	   netif_info(tp, link, dev, "TBI auto-negotiating\n");
	 */
}

static void rtl_rar_set(struct rtl8168_private *tp, u8 *addr)
{
	u32 ioaddr = tp->base_addr;

	rtl_lock_work(tp);

	RTL_W8(Cfg9346, Cfg9346_Unlock);

	RTL_W32(MAC4, addr[4] | addr[5] << 8);
	RTL_R32(MAC4);

	RTL_W32(MAC0, addr[0] | addr[1] << 8 | addr[2] << 16 | addr[3] << 24);
	RTL_R32(MAC0);

	RTL_W8(Cfg9346, Cfg9346_Lock);

	rtl_unlock_work(tp);
}

static int rtl_set_mac_address(struct net_device *dev, void *p)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	struct sockaddr *addr = p;

	if (!is_valid_ether_addr(addr->sa_data))
		return -EADDRNOTAVAIL;

	memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);

	rtl_rar_set(tp, dev->dev_addr);

	return 0;
}

static int rtl8168_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	struct mii_ioctl_data *data = if_mii(ifr);

	return netif_running(dev) ? tp->do_ioctl(tp, data, cmd) : -ENODEV;
}

static int rtl_xmii_ioctl(struct rtl8168_private *tp,
		struct mii_ioctl_data *data, int cmd)
{
	switch (cmd) {
		case SIOCGMIIPHY:
			data->phy_id = 32; /* Internal PHY */
			return 0;

		case SIOCGMIIREG:
			data->val_out = rtl_readphy(tp, data->reg_num & 0x1f);
			return 0;

		case SIOCSMIIREG:
			rtl_writephy(tp, data->reg_num & 0x1f, data->val_in);
			return 0;
	}
	return -EOPNOTSUPP;
}

#if 0
static void rtl_disable_msi(struct pci_dev *pdev, struct rtl8168_private *tp)
{
	if (tp->features & RTL_FEATURE_MSI) {
		tp->features &= ~RTL_FEATURE_MSI;
	}
}
#endif

static void rtl_init_mdio_ops(struct rtl8168_private *tp)
{
	struct mdio_ops *ops = &tp->mdio_ops;

	ops->write	= r8168_mdio_write;
	ops->read	= r8168_mdio_read;
}

#ifdef ENABLE_WOL
static void rtl_speed_down(struct rtl8168_private *tp)
{
	u32 adv;
	int lpa;

	rtl_writephy(tp, 0x1f, 0x0000);
	lpa = rtl_readphy(tp, MII_LPA);

	if (lpa & (LPA_10HALF | LPA_10FULL))
		adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full;
	else if (lpa & (LPA_100HALF | LPA_100FULL))
		adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
			ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full;
	else
		adv = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
			ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
			(tp->mii.supports_gmii ?
			 ADVERTISED_1000baseT_Half |
			 ADVERTISED_1000baseT_Full : 0);

	//rtl8168_set_speed(tp->dev, AUTONEG_ENABLE, SPEED_1000, DUPLEX_FULL, adv);
	rtl8168_set_speed(tp->dev, AUTONEG_DISABLE, SPEED_10, DUPLEX_FULL, adv);
}
#endif

#ifdef ENABLE_EEEP
/*
 * Mac EEEPlus patch from CN
 */
static void rtl8168_mac_eeep_patch_disable(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(OCPDR,0xFE140000);
	RTL_W32(OCPDR,0xFE150000);
	RTL_W32(OCPDR,0xFE160000);
	RTL_W32(OCPDR,0xFE170000);
	RTL_W32(OCPDR,0xFE180000);
	RTL_W32(OCPDR,0xFE190000);
	RTL_W32(OCPDR,0xFE1A0000);
	RTL_W32(OCPDR,0xFE1B0000);
	mdelay(3);
	RTL_W32(OCPDR,0xFE130000);
}

static void rtl8168_mac_eeep_enable(struct rtl8168_private *tp)
{
	/* EEEPlus switch (ERI channel 0x1D0 bit[1]=1) */
	rtl_w1w0_eri(tp, 0x1d0, ERIAR_MASK_0001, 0x02, 0x00, ERIAR_EXGMAC);
	//eth_err("ERI value = %08x\n", RTL_R32(ERIDR));

	/* EEE on */
	rtl_writephy(tp, 0x1f, 0x0a40);
	rtl_writephy(tp, 0x09, 0x0000);

	rtl_writephy(tp, 0x1f, 0x0a43);
	rtl_writephy(tp, 0x19, 0x0073);
	rtl_writephy(tp, 0x1f, 0x0a5d);
	rtl_writephy(tp, 0x10, 0x0006);

	rtl_writephy(tp, 0x1f, 0x0a44);
	rtl_writephy(tp, 0x11, 0x0cbc);
	rtl_writephy(tp, 0x1f, 0x0a43);
	rtl_writephy(tp, 0x10, 0x2199);
}

static void rtl8168_mac_eeep_patch(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(OCPDR,0xFC00E008);
	RTL_W32(OCPDR,0xFC01E012);
	RTL_W32(OCPDR,0xFC02E044);
	RTL_W32(OCPDR,0xFC03E046);
	RTL_W32(OCPDR,0xFC04E048);
	RTL_W32(OCPDR,0xFC05E04A);
	RTL_W32(OCPDR,0xFC06E04C);
	RTL_W32(OCPDR,0xFC07E04E);
	RTL_W32(OCPDR,0xFC0844E3);
	RTL_W32(OCPDR,0xFC09C708);
	RTL_W32(OCPDR,0xFC0A75E0);
	RTL_W32(OCPDR,0xFC0B485D);
	RTL_W32(OCPDR,0xFC0C9DE0);
	RTL_W32(OCPDR,0xFC0DC705);
	RTL_W32(OCPDR,0xFC0EC502);
	RTL_W32(OCPDR,0xFC0FBD00);
	RTL_W32(OCPDR,0xFC1001A4);
	RTL_W32(OCPDR,0xFC11E85A);
	RTL_W32(OCPDR,0xFC12E000);
	RTL_W32(OCPDR,0xFC13C72D);
	RTL_W32(OCPDR,0xFC1476E0);
	RTL_W32(OCPDR,0xFC1549ED);
	RTL_W32(OCPDR,0xFC16F026);
	RTL_W32(OCPDR,0xFC17C02A);
	RTL_W32(OCPDR,0xFC187400);
	RTL_W32(OCPDR,0xFC19C526);
	RTL_W32(OCPDR,0xFC1AC228);
	RTL_W32(OCPDR,0xFC1B9AA0);
	RTL_W32(OCPDR,0xFC1C73A2);
	RTL_W32(OCPDR,0xFC1D49BE);
	RTL_W32(OCPDR,0xFC1EF11E);
	RTL_W32(OCPDR,0xFC1FC324);
	RTL_W32(OCPDR,0xFC209BA2);
	RTL_W32(OCPDR,0xFC2173A2);
	RTL_W32(OCPDR,0xFC2249BE);
	RTL_W32(OCPDR,0xFC23F0FE);
	RTL_W32(OCPDR,0xFC2473A2);
	RTL_W32(OCPDR,0xFC2549BE);
	RTL_W32(OCPDR,0xFC26F1FE);
	RTL_W32(OCPDR,0xFC271A02);
	RTL_W32(OCPDR,0xFC2849C9);
	RTL_W32(OCPDR,0xFC29F003);
	RTL_W32(OCPDR,0xFC2A4821);
	RTL_W32(OCPDR,0xFC2BE002);
	RTL_W32(OCPDR,0xFC2C48A1);
	RTL_W32(OCPDR,0xFC2D73A2);
	RTL_W32(OCPDR,0xFC2E49BE);
	RTL_W32(OCPDR,0xFC2FF10D);
	RTL_W32(OCPDR,0xFC30C313);
	RTL_W32(OCPDR,0xFC319AA0);
	RTL_W32(OCPDR,0xFC32C312);
	RTL_W32(OCPDR,0xFC339BA2);
	RTL_W32(OCPDR,0xFC3473A2);
	RTL_W32(OCPDR,0xFC3549BE);
	RTL_W32(OCPDR,0xFC36F0FE);
	RTL_W32(OCPDR,0xFC3773A2);
	RTL_W32(OCPDR,0xFC3849BE);
	RTL_W32(OCPDR,0xFC39F1FE);
	RTL_W32(OCPDR,0xFC3A48ED);
	RTL_W32(OCPDR,0xFC3B9EE0);
	RTL_W32(OCPDR,0xFC3CC602);
	RTL_W32(OCPDR,0xFC3DBE00);
	RTL_W32(OCPDR,0xFC3E04E6);
	RTL_W32(OCPDR,0xFC3FDE00);
	RTL_W32(OCPDR,0xFC40E85A);
	RTL_W32(OCPDR,0xFC41E086);
	RTL_W32(OCPDR,0xFC420A44);
	RTL_W32(OCPDR,0xFC43801F);
	RTL_W32(OCPDR,0xFC448015);
	RTL_W32(OCPDR,0xFC450015);
	RTL_W32(OCPDR,0xFC46C602);
	RTL_W32(OCPDR,0xFC47BE00);
	RTL_W32(OCPDR,0xFC480000);
	RTL_W32(OCPDR,0xFC49C602);
	RTL_W32(OCPDR,0xFC4ABE00);
	RTL_W32(OCPDR,0xFC4B0000);
	RTL_W32(OCPDR,0xFC4CC602);
	RTL_W32(OCPDR,0xFC4DBE00);
	RTL_W32(OCPDR,0xFC4E0000);
	RTL_W32(OCPDR,0xFC4FC602);
	RTL_W32(OCPDR,0xFC50BE00);
	RTL_W32(OCPDR,0xFC510000);
	RTL_W32(OCPDR,0xFC52C602);
	RTL_W32(OCPDR,0xFC53BE00);
	RTL_W32(OCPDR,0xFC540000);
	RTL_W32(OCPDR,0xFC55C602);
	RTL_W32(OCPDR,0xFC56BE00);
	RTL_W32(OCPDR,0xFC570000);

	RTL_W32(OCPDR,0xFE138000);
	RTL_W32(OCPDR,0xFE1401A3);
	RTL_W32(OCPDR,0xFE1504E5);
}
#endif

#ifdef ENABLE_WOL
static void rtl_wol_suspend_quirk(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(RxConfig, RTL_R32(RxConfig) |
			AcceptBroadcast | AcceptMulticast | AcceptMyPhys);
}

static bool rtl_wol_pll_power_down(struct rtl8168_private *tp)
{
	if (!(__rtl8168_get_wol(tp) & WAKE_ANY))
		return false;

#ifndef ENABLE_EEEP
	rtl8168_phy_int_disable(tp);
	/* fix 10M */
	rtl_speed_down(tp);
	rtl8168_phy_int_enable(tp);
#endif
	rtl_wol_suspend_quirk(tp);

	return true;
}
//#endif

static void rtl_wol_set(struct rtl8168_private *tp, u32 enable)
{
	u32 ioaddr = tp->base_addr;
	//u32 wol_mode = 1;

	eth_info("%s\n", __func__);
	if (enable == RTL8168_WOL_ENABLE)
	{
#ifdef ENABLE_ALDPS
		rtl8168_phy_int_disable(tp);
		/* Diable Aldps mode */
		rtl8168_phy_set_aldps(tp, 0);
		rtl8168_xmii_set_page(tp, 0x0a43);
		//eth_info("ALDPS = 0x%04x\n", rtl_readphy(tp, 0x18));
		rtl8168_xmii_set_page(tp, 0x0000);
		rtl8168_phy_int_enable(tp);
#endif

		/* Enable WOL IP setting for PHY */
		//rtl_writephy(tp, 0x1f, 0x0bc4);
		//rtl_writephy(tp, 0x15, 0x0203);

		/* <1> Enable WOL IP setting for MAC */
		RTL_W8(Cfg9346, Cfg9346_Unlock);
		RTL_W8(MCU, RTL_R8(MCU) | NOW_IS_OOB | DIS_MCU_CLROOB); /* enable now_is_oob */
		RTL_W8(Config5, RTL_R8(Config5) | LanWake);
		RTL_W8(Config3, RTL_R8(Config3) | MagicPacket);
		RTL_W8(Cfg9346, Cfg9346_Lock);

		if (rtl_wol_pll_power_down(tp))
		{
#ifdef ENABLE_EEEP
			rtl8168_phy_int_disable(tp);
			/* <2> Enable EEEP */
			rtl8168_mac_eeep_enable(tp);
			/* <3> Force 10M */
			rtl_speed_down(tp);
			rtl8168_phy_int_enable(tp);
			/* <4> EEEP patch code */
			rtl8168_mac_eeep_patch_disable(tp);
			rtl8168_mac_eeep_patch(tp);
#endif
#ifdef ENABLE_ALDPS
			rtl8168_phy_int_disable(tp);
			/* <5> Enable Aldps mode */
			rtl8168_phy_set_aldps(tp, 1);
			rtl8168_phy_int_enable(tp);
#endif
			/* <6> WOL_PLLETN setting, can't read/write ethernet register */
			//CRT_CLK_OnOff(ETH, CLK_OFF, &wol_mode);
			//rtd_setbits(STB_ST_CTRL0_reg, BIT(STB_ST_CTRL0_getn_rstn_mask_shift));
			//rtd_outl(PLLETN_GETN_CLKEN_reg, BIT(PLLETN_GETN_CLKEN_clken_getn_sys_shift)); 
			//rtd_outl(PLLETN_GETN_RST_reg, BIT(PLLETN_GETN_RST_rstn_getn_sys_shift));
			//rtd_outl(STB_ST_CLKEN0_reg, BIT(STB_ST_CLKEN0_clken_getn_rbus_shift));
#if 0
			if(tp->ap_wol_enable) {
				/* Check WOL status */
				mdelay(10000);
				RTL_W32(OCPDR, 0x70030000);
				eth_info("[ETH] check wol status = %04x\n", RTL_R32(OCPDR));
			}	
#endif
			return;
		}
		else
			eth_err("wol setting failed\n");
	} else {
		return;
	}
}
#endif

#ifdef ENABLE_WOW
// ToDo: WOW
static void rtl_realwow_set(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	// isram patch
	RTL_W32(OCPDR,0xFC00E008);
	RTL_W32(OCPDR,0xFC01E02C);
	RTL_W32(OCPDR,0xFC02E032);
	RTL_W32(OCPDR,0xFC03E06A);
	RTL_W32(OCPDR,0xFC04E0A1);
	RTL_W32(OCPDR,0xFC05E0A3);
	RTL_W32(OCPDR,0xFC06E0A5);
	RTL_W32(OCPDR,0xFC07E0A7);
	RTL_W32(OCPDR,0xFC08C208);
	RTL_W32(OCPDR,0xFC097340);
	RTL_W32(OCPDR,0xFC0A49B7);
	RTL_W32(OCPDR,0xFC0BF009);
	RTL_W32(OCPDR,0xFC0C1D02);
	RTL_W32(OCPDR,0xFC0D8D40);
	RTL_W32(OCPDR,0xFC0EC203);
	RTL_W32(OCPDR,0xFC0FBA00);
	RTL_W32(OCPDR,0xFC10C0BC);
	RTL_W32(OCPDR,0xFC11100C);
	RTL_W32(OCPDR,0xFC12D2E4);
	RTL_W32(OCPDR,0xFC13C0C4);
	RTL_W32(OCPDR,0xFC14C5FE);
	RTL_W32(OCPDR,0xFC1574A0);
	RTL_W32(OCPDR,0xFC1649C0);
	RTL_W32(OCPDR,0xFC17F010);
	RTL_W32(OCPDR,0xFC1874A2);
	RTL_W32(OCPDR,0xFC1976A4);
	RTL_W32(OCPDR,0xFC1A4034);
	RTL_W32(OCPDR,0xFC1BF804);
	RTL_W32(OCPDR,0xFC1C0601);
	RTL_W32(OCPDR,0xFC1D9EA4);
	RTL_W32(OCPDR,0xFC1EE009);
	RTL_W32(OCPDR,0xFC1F1D02);
	RTL_W32(OCPDR,0xFC208D40);
	RTL_W32(OCPDR,0xFC21C5F2);
	RTL_W32(OCPDR,0xFC2264A1);
	RTL_W32(OCPDR,0xFC234845);
	RTL_W32(OCPDR,0xFC248CA1);
	RTL_W32(OCPDR,0xFC25C606);
	RTL_W32(OCPDR,0xFC26BE00);
	RTL_W32(OCPDR,0xFC271C20);
	RTL_W32(OCPDR,0xFC288C41);
	RTL_W32(OCPDR,0xFC29C603);
	RTL_W32(OCPDR,0xFC2ABE00);
	RTL_W32(OCPDR,0xFC2B104E);
	RTL_W32(OCPDR,0xFC2C0C80);
	RTL_W32(OCPDR,0xFC2DC605);
	RTL_W32(OCPDR,0xFC2E1D22);
	RTL_W32(OCPDR,0xFC2F8DC0);
	RTL_W32(OCPDR,0xFC30C603);
	RTL_W32(OCPDR,0xFC31BE00);
	RTL_W32(OCPDR,0xFC32C0BC);
	RTL_W32(OCPDR,0xFC330D28);
	RTL_W32(OCPDR,0xFC347236);
	RTL_W32(OCPDR,0xFC350208);
	RTL_W32(OCPDR,0xFC36C323);
	RTL_W32(OCPDR,0xFC37C724);
	RTL_W32(OCPDR,0xFC3864E0);
	RTL_W32(OCPDR,0xFC397522);
	RTL_W32(OCPDR,0xFC3A26D5);
	RTL_W32(OCPDR,0xFC3B050C);
	RTL_W32(OCPDR,0xFC3C31EC);
	RTL_W32(OCPDR,0xFC3D7620);
	RTL_W32(OCPDR,0xFC3E48EF);
	RTL_W32(OCPDR,0xFC3F403E);
	RTL_W32(OCPDR,0xFC40F80A);
	RTL_W32(OCPDR,0xFC41E81D);
	RTL_W32(OCPDR,0xFC421401);
	RTL_W32(OCPDR,0xFC43F107);
	RTL_W32(OCPDR,0xFC441C10);
	RTL_W32(OCPDR,0xFC45C518);
	RTL_W32(OCPDR,0xFC468CA1);
	RTL_W32(OCPDR,0xFC47C602);
	RTL_W32(OCPDR,0xFC48BE00);
	RTL_W32(OCPDR,0xFC490A6A);
	RTL_W32(OCPDR,0xFC4AC310);
	RTL_W32(OCPDR,0xFC4BC710);
	RTL_W32(OCPDR,0xFC4C64E1);
	RTL_W32(OCPDR,0xFC4D31EC);
	RTL_W32(OCPDR,0xFC4E403E);
	RTL_W32(OCPDR,0xFC4FF807);
	RTL_W32(OCPDR,0xFC50E80E);
	RTL_W32(OCPDR,0xFC511401);
	RTL_W32(OCPDR,0xFC52F104);
	RTL_W32(OCPDR,0xFC53C509);
	RTL_W32(OCPDR,0xFC541E00);
	RTL_W32(OCPDR,0xFC559EA4);
	RTL_W32(OCPDR,0xFC56C602);
	RTL_W32(OCPDR,0xFC57BE00);
	RTL_W32(OCPDR,0xFC580D6E);
	RTL_W32(OCPDR,0xFC596808);
	RTL_W32(OCPDR,0xFC5A6848);
	RTL_W32(OCPDR,0xFC5B6800);
	RTL_W32(OCPDR,0xFC5CD2E4);
	RTL_W32(OCPDR,0xFC5DC0C4);
	RTL_W32(OCPDR,0xFC5EB405);
	RTL_W32(OCPDR,0xFC5FB407);
	RTL_W32(OCPDR,0xFC600C01);
	RTL_W32(OCPDR,0xFC61A154);
	RTL_W32(OCPDR,0xFC62A1DC);
	RTL_W32(OCPDR,0xFC63402F);
	RTL_W32(OCPDR,0xFC64F105);
	RTL_W32(OCPDR,0xFC651400);
	RTL_W32(OCPDR,0xFC66F1FA);
	RTL_W32(OCPDR,0xFC671C01);
	RTL_W32(OCPDR,0xFC68E002);
	RTL_W32(OCPDR,0xFC691C00);
	RTL_W32(OCPDR,0xFC6AB007);
	RTL_W32(OCPDR,0xFC6BB005);
	RTL_W32(OCPDR,0xFC6CFF80);
	RTL_W32(OCPDR,0xFC6DC532);
	RTL_W32(OCPDR,0xFC6E74A0);
	RTL_W32(OCPDR,0xFC6F49C0);
	RTL_W32(OCPDR,0xFC70F01E);
	RTL_W32(OCPDR,0xFC71C52F);
	RTL_W32(OCPDR,0xFC7273A0);
	RTL_W32(OCPDR,0xFC731300);
	RTL_W32(OCPDR,0xFC74F104);
	RTL_W32(OCPDR,0xFC7573A2);
	RTL_W32(OCPDR,0xFC761300);
	RTL_W32(OCPDR,0xFC77F014);
	RTL_W32(OCPDR,0xFC78C52A);
	RTL_W32(OCPDR,0xFC7974A0);
	RTL_W32(OCPDR,0xFC7A49C0);
	RTL_W32(OCPDR,0xFC7BF11B);
	RTL_W32(OCPDR,0xFC7CC525);
	RTL_W32(OCPDR,0xFC7D76A0);
	RTL_W32(OCPDR,0xFC7E74A2);
	RTL_W32(OCPDR,0xFC7F0601);
	RTL_W32(OCPDR,0xFC803720);
	RTL_W32(OCPDR,0xFC819EA0);
	RTL_W32(OCPDR,0xFC829CA2);
	RTL_W32(OCPDR,0xFC83C51D);
	RTL_W32(OCPDR,0xFC8473A2);
	RTL_W32(OCPDR,0xFC854023);
	RTL_W32(OCPDR,0xFC86F810);
	RTL_W32(OCPDR,0xFC87F304);
	RTL_W32(OCPDR,0xFC8873A0);
	RTL_W32(OCPDR,0xFC894033);
	RTL_W32(OCPDR,0xFC8AF80C);
	RTL_W32(OCPDR,0xFC8BC514);
	RTL_W32(OCPDR,0xFC8C1C02);
	RTL_W32(OCPDR,0xFC8D8CA1);
	RTL_W32(OCPDR,0xFC8EC515);
	RTL_W32(OCPDR,0xFC8F76A8);
	RTL_W32(OCPDR,0xFC904862);
	RTL_W32(OCPDR,0xFC9148E0);
	RTL_W32(OCPDR,0xFC929EA8);
	RTL_W32(OCPDR,0xFC93C602);
	RTL_W32(OCPDR,0xFC94BE00);
	RTL_W32(OCPDR,0xFC9500E0);
	RTL_W32(OCPDR,0xFC961C01);
	RTL_W32(OCPDR,0xFC97C50B);
	RTL_W32(OCPDR,0xFC988CA1);
	RTL_W32(OCPDR,0xFC99C60B);
	RTL_W32(OCPDR,0xFC9A1F20);
	RTL_W32(OCPDR,0xFC9B9FC0);
	RTL_W32(OCPDR,0xFC9C48F5);
	RTL_W32(OCPDR,0xFC9D9FC0);
	RTL_W32(OCPDR,0xFC9EE7F0);
	RTL_W32(OCPDR,0xFC9FC0BC);
	RTL_W32(OCPDR,0xFCA0D2C8);
	RTL_W32(OCPDR,0xFCA1D2CC);
	RTL_W32(OCPDR,0xFCA2C0C4);
	RTL_W32(OCPDR,0xFCA3E420);
	RTL_W32(OCPDR,0xFCA4C0F0);
	RTL_W32(OCPDR,0xFCA5C602);
	RTL_W32(OCPDR,0xFCA6BE00);
	RTL_W32(OCPDR,0xFCA70000);
	RTL_W32(OCPDR,0xFCA8C602);
	RTL_W32(OCPDR,0xFCA9BE00);
	RTL_W32(OCPDR,0xFCAA0000);
	RTL_W32(OCPDR,0xFCABC602);
	RTL_W32(OCPDR,0xFCACBE00);
	RTL_W32(OCPDR,0xFCAD0000);
	RTL_W32(OCPDR,0xFCAEC602);
	RTL_W32(OCPDR,0xFCAFBE00);
	RTL_W32(OCPDR,0xFCB00000);

	// bp base address
	RTL_W32(OCPDR,0xFC268000);
	// bp 0~3
	RTL_W32(OCPDR,0xFC280FD3);
	RTL_W32(OCPDR,0xFC2A0D23);
	RTL_W32(OCPDR,0xFC2C0F95);
	RTL_W32(OCPDR,0xFC2E009B);
}

static void rtl_wow_set(struct rtl8168_private *tp, u32 enable)
{
	u32 ioaddr = tp->base_addr;
	u32 data_read_u32 = 0;
	u32 data_write_u32 = 0;
	int reg_addr_int = 0;
	u32 reg_addr_u32 = 0;
	u32 reg_mask_u32 = 0;
	u32 u32i = 0;
	u8 MACID[6] = {0x00, 0x11, 0x22, 0x33, 0x17, 0x34};
	u8 OOB_IPv4[4] = {172, 22, 56, 23};
	u8 NS0_MACID[6] = {0x00, 0x11, 0x22, 0x33, 0x17, 0x34};
	u16 UDP_PORT[2] = {1734, 3417};
	u16 ACKMISS_TIME = 0xFFFF;
	u8 ack_len = 0xFF;
	u8 wake_len = 0xFF;
	u8 tx1_len = 0xFF;
	u8 tx2_len = 0xFF;
	u16 txpkt_timer = 0x0080; //tx packet timer (in units of 8ms) ~1024ms


	if (enable == 1)
	{
		tp->ocp_base = OCP_STD_PHY_BASE;

		/* (1) Set Now_is_OOB = 0 (IO offset 0xd3 bit 7 set to 0b) */
		RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);

		/* (2) Flow control related (only for OOB) */
		/* I. ERI 0xC8 => 0x03	credit full */
		reg_addr_int = 0x0C8;
		reg_mask_u32 = ERIAR_MASK_0001;
		data_write_u32 = 0x00000003;
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		/* II. ERI 0xCA => 0x180	point full */
		reg_addr_int = 0x0CA;
		reg_mask_u32 = ERIAR_MASK_0011;
		data_write_u32 = 0x00000180;
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		/* III. ERI 0xCC => 0x4A	credit near full */
		reg_addr_int = 0x0CC;
		reg_mask_u32 = ERIAR_MASK_0001;
		data_write_u32 = 0x0000004A;
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		/* IV. ERI 0xD0 => 0x5A	credit near empty */
		reg_addr_int = 0x0D0;
		reg_mask_u32 = ERIAR_MASK_0001;
		data_write_u32 = 0x0000005A;
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);

		/* (3)Turn off RCR (IO offset 0x44 set to 0) */
		RTL_W32(RxConfig, 0x00000000);

		/* (4) Set rxdv_gated_en (IO 0xF2 bit3 = 1) */
		RTL_W32(MISC, RTL_R32(MISC) | RXDV_GATED_EN);

		/* (5) check FIFO empty (IO 0xD2 bit[12:13]) */
		while(1)
		{
			if (RTL_R8(MCU) & TX_EMPTY)
			{
				if (RTL_R8(MCU) & RX_EMPTY)
					break;
			}
			eth_debug("check Tx/RX FIFO empty fail\n");
			msleep(1);
		}

		/* (6) disable Tx/Rx enable = 0 (IO 0x36 bit[10:11]=0b) */
		RTL_W32(ChipCmd, RTL_R32(ChipCmd) & ~(CmdTxEnb | CmdRxEnb));

		/* (7) check link_list ready =1 (IO 0xD2 bit9=1) */
		while(1) {
			if (RTL_R16(MCU) & LINK_LIST_RDY)
				break;
			eth_debug("check link_list ready fail != 1\n");
			msleep(1);
		}

		/* (8) set re_ini_ll =1 (MACOCP : 0xE8DE bit15=1) */
		reg_addr_u32 = 0x0000E8DE;
		data_read_u32 = r8168_mac_ocp_read(tp, reg_addr_u32);
		data_write_u32 = data_read_u32 | 0x00001000;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);

		/* (9) check link_list ready =1 (IO 0xD2 bit9=1) */
		while(1) {
			if (RTL_R16(MCU) & LINK_LIST_RDY)
				break;
			eth_debug("check link_list ready fail != 1\n");
			msleep(1);
		}

		/* (10) Setting RMS (IO offset 0xdb-0xda set to 0x05F3) */
		RTL_W32(RxMaxSize, 0x05F3);

		/* (11) OOB parameter setting */
		/* b. MACID_VLAN(MAC needs the offload information from upper layer) */
		/*	1. VLAN ID: ERI offset 0xf1-0Xf0 set 0xFFFF */
		reg_addr_int = 0x0F0;
		reg_mask_u32 = ERIAR_MASK_0011;
		data_write_u32 = 0x0000FFFF;
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		//			/*	2. MACID : ERI offset 0xf7-0xf2 */
		for(u32i = 0; u32i < 6; u32i++)
		{
			reg_addr_int = 0x0F2 + u32i;
			reg_mask_u32 = ERIAR_MASK_0001;
			data_write_u32 = MACID[u32i];
			rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		}
		/*
		   reg_addr_int = 0x0F2;
		   reg_mask_u32 = ERIAR_MASK_1111;
		   data_write_u32 = 0xFFFFFFFF;
		   rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		   reg_addr_int = 0x0F6;
		   reg_mask_u32 = ERIAR_MASK_0011;
		   data_write_u32 = 0x0000FFFF;
		   rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		 */
		/* d. OOB_IPv4 (IPv4 Address needs the offload information from upper layer) */
		//			/*	1. OOB_IPv4 : ERI offset 0x1f3-0x1f0 */
		for(u32i = 0; u32i < 4; u32i++)
		{
			reg_addr_int = 0x1F0 + u32i;
			reg_mask_u32 = ERIAR_MASK_0001;
			data_write_u32 = OOB_IPv4[u32i];
			rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		}
		/*
		   reg_addr_int = 0x1F0;
		   reg_mask_u32 = ERIAR_MASK_1111;
		   data_write_u32 = 0xFFFFFFFF;
		   rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		 */
		/* e. NS_MACID */
		//			/*	1. NS0_MACID : ERI offset 0x25d-0x258 */
		for(u32i = 0; u32i < 6; u32i++)
		{
			reg_addr_int = 0x0F2 + u32i;
			reg_mask_u32 = ERIAR_MASK_0001;
			data_write_u32 = NS0_MACID[u32i];
			rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		}
		/*
		   reg_addr_int = 0x258;
		   reg_mask_u32 = ERIAR_MASK_1111;
		   data_write_u32 = 0xFFFFFFFF;
		   rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		   reg_addr_int = 0x25C;
		   reg_mask_u32 = ERIAR_MASK_0011;
		   data_write_u32 = 0x0000FFFF;
		   rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		 */

		/* (12) Enable VLAN De-tagging (IO offset 0xE0 bit6 set to 1) */
		RTL_W32(CPlusCmd, RTL_R32(CPlusCmd) | RxVlan);

		/* (13-B) Realwow2 setting */
		/* 13B-1. clear previous wakeup type: OCP 0xC0C4 = 0x00FF */
		reg_addr_u32 = 0x0000C0C4;
		data_write_u32 = 0x000000FF;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-2. clear previous ack miss counter: OCP 0xD2E8 = 0x0000 */
		reg_addr_u32 = 0x0000D2E8;
		data_write_u32 = 0x00000000;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		//			/* 13B-3. UDP port: OCP 0xCDB2 = SERVER1_PORT */
		reg_addr_u32 = 0x0000CDB2;
		data_write_u32 = UDP_PORT[0];
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		//			/* 13B-4. UDP port: OCP 0xCDB4 = SERVER2_PORT */
		reg_addr_u32 = 0x0000CDB4;
		data_write_u32 = UDP_PORT[1];
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-5. port enable: OCP 0xC0BE bit11=1, bit6=1, bit5=1 */
		reg_addr_u32 = 0x0000C0BE;
		data_read_u32 = r8168_mac_ocp_read(tp, reg_addr_u32);
		data_write_u32 = data_read_u32 | 0x00000860;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-6. port enable: OCP 0xC0C0 bit6=1, bit5=1 */
		reg_addr_u32 = 0x0000C0C0;
		data_read_u32 = r8168_mac_ocp_read(tp, reg_addr_u32);
		data_write_u32 = data_read_u32 | 0x00000060;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-7. rsvd_proxy_udp enable: OCP 0xC0B6 bit10=1 */
		reg_addr_u32 = 0x0000C0B6;
		data_read_u32 = r8168_mac_ocp_read(tp, reg_addr_u32);
		data_write_u32 = data_read_u32 | 0x00000400;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		//			/* 13B-8. ack miss timer: OCP 0xD2E6 = ACKMISS_TIME */
		reg_addr_u32 = 0x0000D2E6;
		data_write_u32 = ACKMISS_TIME;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-9. Disable ftr_mcu_en(ERI 0xDC[0] = 0) */
		reg_addr_int = 0x0F0;
		reg_mask_u32 = ERIAR_MASK_0001;
		data_read_u32 = rtl_eri_read(tp, 0x0DC, ERIAR_EXGMAC);
		data_write_u32 = data_read_u32 & (~0x00000001);
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		/* 13B-10. Enable ftr_mcu_en(ERI 0xDC[0] = 1) */
		reg_addr_int = 0x0F0;
		reg_mask_u32 = ERIAR_MASK_0001;
		data_read_u32 = rtl_eri_read(tp, 0x0DC, ERIAR_EXGMAC);
		data_write_u32 = data_read_u32 | 0x00000001;
		rtl_eri_write(tp, reg_addr_int, reg_mask_u32, data_write_u32, ERIAR_EXGMAC);
		//			/* 13B-11. rx length: OCP 0x6800 = ACKLEN[7:0]_WAKELEN[7:0] */
		reg_addr_u32 = 0x00006800;
		data_write_u32 = ack_len << 8 | wake_len;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		//			/* 13B-12. tx length: OCP 0x6802 = TX2LEN[7:0]_TX1LEN[7:0] */
		reg_addr_u32 = 0x00006802;
		data_write_u32 = tx2_len << 8 | tx1_len;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		//			/* 13B-13. wake packet UDP payload (64 bytes): OCP 0x6808-6847 */
		for (u32i = 0; u32i < 32; u32i++)
		{
			reg_addr_u32 = 0x00006808 + (u32i*2);
			data_write_u32 = 0x0000FFFF;
			r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		}
		//			/* 13B-14. ack packet UDP payload (48 bytes): OCP 0x6848-6877 */
		for (u32i = 0; u32i < 24; u32i++)
		{
			reg_addr_u32 = 0x00006848 + (u32i*2);
			data_write_u32 = 0x0000FFFF;
			r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		}
		//			/* 13B-15. tx1 whole packet excluding crc (100 bytes) : OCP 0x6880-68E3 */
		for (u32i = 0; u32i < 50; u32i++)
		{
			reg_addr_u32 = 0x00006880 + (u32i*2);
			data_write_u32 = 0x0000FFFF;
			r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		}
		//			/* 13B-16. tx2 whole packet excluding crc (100 bytes) : OCP 0x68E4-6947 */
		for (u32i = 0; u32i < 50; u32i++)
		{
			reg_addr_u32 = 0x000068E4 + (u32i*2);
			data_write_u32 = 0x0000FFFF;
			r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		}
		/* 13B-17. ack miss wakeup enable/disable : OCP 0xD2E4 bit 0 */
		reg_addr_u32 = 0x0000D2E4;
		data_read_u32 = r8168_mac_ocp_read(tp, reg_addr_u32);
		data_write_u32 = data_read_u32 | 0x00000001;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-18. RealWOWv2	enable/disable : OCP 0xC0BC = 0x0100 */
		reg_addr_u32 = 0x0000C0BC;
		data_write_u32 = 0x00000100;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		//			/* 13B-19. tx packet timer (in units of 8ms): OCP 0xE42A = TX_TIMER */
		reg_addr_u32 = 0x0000E42A;
		data_write_u32 = txpkt_timer;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);
		/* 13B-20. tx packet timer enable: OCP 0xE428 = 0x0019 */
		reg_addr_u32 = 0x0000E428;
		data_write_u32 = 0x00000019;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);

		/* (14) Enable now_is_oob (IO offset 0xd3 bit 7 set to 1b) */
		RTL_W8(MCU, RTL_R8(MCU) | NOW_IS_OOB | DIS_MCU_CLROOB);

		/* (15) set MACOCP 0xE8DE bit14 mcu_borw_en to 1b for modifying ShareFIFO's points */
		reg_addr_u32 = 0x0000E8DE;
		data_read_u32 = r8168_mac_ocp_read(tp, reg_addr_u32);
		data_write_u32 = data_read_u32 | 0x00004000;
		r8168_mac_ocp_write(tp, reg_addr_u32, data_write_u32);

		/* (16) Patch code to share FIFO if need (Yang Chang-Shiuan's patch code and BPs) */
		rtl_realwow_set(tp);

		/*  (17) Set rxdv_gated_en = 0 (IO 0xF2 bit3=0) */
		RTL_W8(MISC, RTL_R8(MISC) & ~RXDV_GATED_EN);

		/*  (18) Turn on RCR (IO offset 0x44 set to 0x0e) */
		RTL_W8(RxConfig, AcceptBroadcast | AcceptMulticast | AcceptMyPhys);


		/* enable WOL IP setting for PHY */
		//rtl_writephy(tp, 0x1f, 0x0bc4);
		//rtl_writephy(tp, 0x15, 0x0203);
		/* enable WOL IP setting for MAC */
		//RTL_W8(Cfg9346, Cfg9346_Unlock);
		/* enable now_is_oob */
		//RTL_W8(MCU, RTL_R8(MCU) | NOW_IS_OOB | DIS_MCU_CLROOB);
		//RTL_W8(Config5, RTL_R8(Config5) | LanWake);
		//RTL_W8(Config3, RTL_R8(Config3) | MagicPacket);
		//RTL_W8(Cfg9346, Cfg9346_Lock);
		//if (rtl_wol_pll_power_down(tp))
		//	return;
		//else
		//	eth_err("wol setting failed\n");
	} else {
	}

}
#endif

static void r8168_phy_power_up(struct rtl8168_private *tp)
{
	rtl_writephy(tp, 0x1f, 0x0000);
	rtl_writephy(tp, MII_BMCR, BMCR_ANENABLE);
}

static void r8168_phy_power_down(struct rtl8168_private *tp)
{
	rtl_writephy(tp, 0x1f, 0x0000);
	rtl_writephy(tp, MII_BMCR, BMCR_PDOWN);
}

static void r8168_pll_power_down(struct rtl8168_private *tp)
{
	/* Check wol enable/disable */
	if ( (rtd_inl(0xb8060500) & BIT(24)) != 0 ) { /* read WOW/WOL flag in the share memory */
		eth_info("%s, Reading WOW/WOL flag from 0xb8060500 = %08x\n", __func__, rtd_inl(0xb8060500));
#ifdef ENABLE_WOL
		rtl_wol_set(tp, RTL8168_WOL_ENABLE);
#endif
#ifdef ENABLE_WOW
		rtl_wow_set(tp, RTL8168_WOL_ENABLE);
#endif
	}
	else {
		r8168_phy_power_down(tp);
	}
}

static void r8168_pll_power_up(struct rtl8168_private *tp)
{
	r8168_phy_power_up(tp);
}

static void rtl_generic_op(struct rtl8168_private *tp,
		void (*op)(struct rtl8168_private *))
{
	if (op)
		op(tp);
}

static void rtl_pll_power_down(struct rtl8168_private *tp)
{
	rtl_generic_op(tp, tp->pll_power_ops.down);
}

static void rtl_pll_power_up(struct rtl8168_private *tp)
{
	rtl_generic_op(tp, tp->pll_power_ops.up);
}

static void rtl_init_pll_power_ops(struct rtl8168_private *tp)
{
	struct pll_power_ops *ops = &tp->pll_power_ops;

	ops->down	= r8168_pll_power_down;
	ops->up		= r8168_pll_power_up;
}

static void rtl_init_rxcfg(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(RxConfig, RX128_INT_EN | RX_DMA_BURST | RX_EARLY_OFF);
}

static void rtl8168_init_ring_indexes(struct rtl8168_private *tp)
{
	tp->dirty_tx = tp->cur_tx = tp->cur_rx = 0;
}

DECLARE_RTL_COND(rtl_chipcmd_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R8(ChipCmd) & CmdReset;
}

static void rtl_hw_reset(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W8(ChipCmd, CmdReset);

	rtl_udelay_loop_wait_low(tp, &rtl_chipcmd_cond, 100, 100);
}

static void rtl_rx_close(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(RxConfig, RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK);
}

DECLARE_RTL_COND(rtl_npq_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R8(TxPoll) & NPQ;
}

DECLARE_RTL_COND(rtl_txcfg_empty_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(TxConfig) & TXCFG_EMPTY;
}

static void rtl8168_hw_reset(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	/* Disable interrupts */
	rtl8168_irq_mask_and_ack(tp);

	rtl_rx_close(tp);

	RTL_W8(ChipCmd, RTL_R8(ChipCmd) | StopReq);
	eth_debug("%s, ChipCmd = %08x\n", __func__, RTL_R8(ChipCmd));
	rtl_udelay_loop_wait_high(tp, &rtl_txcfg_empty_cond, 100, 666);

	rtl_hw_reset(tp);
}

static void rtl_set_rx_tx_config_registers(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;

	/* Set DMA burst size and Interframe Gap Time */
	RTL_W32(TxConfig, (TX_DMA_BURST << TxDMAShift) |
			(InterFrameGap << TxInterFrameGapShift));
}

static void rtl_hw_start(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	tp->hw_start(dev);

	rtl_irq_enable_all(tp);
}

static void rtl_set_rx_tx_desc_registers(struct rtl8168_private *tp,
		u32 ioaddr)
{
	/*
	 * Magic spell: some iop3xx ARM board needs the TxDescAddrHigh
	 * register to be written before TxDescAddrLow to work.
	 * Switching from MMIO to I/O access fixes the issue as well.
	 */
	RTL_W32(TxDescStartAddrHigh, ((u64) tp->TxPhyAddr) >> 32);
	RTL_W32(TxDescStartAddrLow, ((u64) tp->TxPhyAddr) & DMA_BIT_MASK(32));
	RTL_W32(RxDescAddrHigh, ((u64) tp->RxPhyAddr) >> 32);
	RTL_W32(RxDescAddrLow, ((u64) tp->RxPhyAddr) & DMA_BIT_MASK(32));
}

static void rtl_set_rx_max_size(u32 ioaddr, unsigned int rx_buf_sz)
{
	/* Low hurts. Let's disable the filtering. */
	RTL_W16(RxMaxSize, rx_buf_sz + 1);
}

static void rtl_set_rx_mode(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	u32 ioaddr = tp->base_addr;
	u32 mc_filter[2];	/* Multicast hash filter */
	int rx_mode;
	u32 tmp = 0;
	u32 data = 0;

	if (dev->flags & IFF_PROMISC) {
		/* Unconditionally log net taps. */
		netif_notice(tp, link, dev, "Promiscuous mode enabled\n");
		rx_mode =
			AcceptBroadcast | AcceptMulticast | AcceptMyPhys |
			AcceptAllPhys;
		mc_filter[1] = mc_filter[0] = 0xffffffff;
	} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
			(dev->flags & IFF_ALLMULTI)) {
		/* Too many to filter perfectly -- accept all multicasts. */
		rx_mode = AcceptBroadcast | AcceptMulticast | AcceptMyPhys;
		mc_filter[1] = mc_filter[0] = 0xffffffff;
	} else {
		struct netdev_hw_addr *ha;

		rx_mode = AcceptBroadcast | AcceptMyPhys;
		mc_filter[1] = mc_filter[0] = 0;
		netdev_for_each_mc_addr(ha, dev) {
			int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
			mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
			rx_mode |= AcceptMulticast;
		}
	}

	if (dev->features & NETIF_F_RXALL)
		rx_mode |= (AcceptErr | AcceptRunt);

	tmp = (RTL_R32(RxConfig) & ~RX_CONFIG_ACCEPT_MASK) | rx_mode;

	data = mc_filter[0];
	mc_filter[0] = swab32(mc_filter[1]);
	mc_filter[1] = swab32(data);

	RTL_W32(MAR0 + 4, mc_filter[1]);
	RTL_W32(MAR0 + 0, mc_filter[0]);

	RTL_W32(RxConfig, tmp);
}

#if 0
static void rtl_csi_write(struct rtl8168_private *tp, int addr, int value)
{
	if (tp->csi_ops.write)
		tp->csi_ops.write(tp, addr, value);
}

static u32 rtl_csi_read(struct rtl8168_private *tp, int addr)
{
	return tp->csi_ops.read ? tp->csi_ops.read(tp, addr) : ~0;
}

static void rtl_csi_access_enable(struct rtl8168_private *tp, u32 bits)
{
	u32 csi;

	csi = rtl_csi_read(tp, 0x070c) & 0x00ffffff;
	rtl_csi_write(tp, 0x070c, csi | bits);
}

static void rtl_csi_access_enable_1(struct rtl8168_private *tp)
{
	rtl_csi_access_enable(tp, 0x17000000);
}


DECLARE_RTL_COND(rtl_csiar_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R32(CSIAR) & CSIAR_FLAG;
}

static void r8168_csi_write(struct rtl8168_private *tp, int addr, int value)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(CSIDR, value);
	RTL_W32(CSIAR, CSIAR_WRITE_CMD | (addr & CSIAR_ADDR_MASK) |
			CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);

	rtl_udelay_loop_wait_low(tp, &rtl_csiar_cond, 10, 100);
}

static u32 r8168_csi_read(struct rtl8168_private *tp, int addr)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(CSIAR, (addr & CSIAR_ADDR_MASK) |
			CSIAR_BYTE_ENABLE << CSIAR_BYTE_ENABLE_SHIFT);

	return rtl_udelay_loop_wait_high(tp, &rtl_csiar_cond, 10, 100) ?
		RTL_R32(CSIDR) : ~0;
}

static void rtl_init_csi_ops(struct rtl8168_private *tp)
{
	struct csi_ops *ops = &tp->csi_ops;

	ops->write	= r8168_csi_write;
	ops->read	= r8168_csi_read;
}

struct ephy_info {
	unsigned int offset;
	u16 mask;
	u16 bits;
};

static void rtl_ephy_init(struct rtl8168_private *tp, const struct ephy_info *e,
		int len)
{
	u16 w;

	while (len-- > 0) {
		w = (rtl_ephy_read(tp, e->offset) & ~e->mask) | e->bits;
		rtl_ephy_write(tp, e->offset, w);
		e++;
	}
}
#endif

#define R8168_CPCMD_QUIRK_MASK (\
		EnableBist | \
		Mac_dbgo_oe | \
		Force_half_dup | \
		Force_rxflow_en | \
		Force_txflow_en | \
		Cxpl_dbg_sel | \
		ASF | \
		PktCntrDisable | \
		Mac_dbgo_sel)

#if 0
static void rtl_hw_start_8168g_1(struct rtl8169_private *tp)
{
	u32 ioaddr = tp->base_addr;

	RTL_W32(TxConfig, RTL_R32(TxConfig) | TXCFG_AUTO_FIFO);

	rtl_eri_write(tp, 0xc8, ERIAR_MASK_0101, 0x080002, ERIAR_EXGMAC);
	rtl_eri_write(tp, 0xcc, ERIAR_MASK_0001, 0x38, ERIAR_EXGMAC);
	rtl_eri_write(tp, 0xd0, ERIAR_MASK_0001, 0x48, ERIAR_EXGMAC);
	rtl_eri_write(tp, 0xe8, ERIAR_MASK_1111, 0x00100006, ERIAR_EXGMAC);

	/*rtl_csi_access_enable_1(tp); */

	/*rtl_tx_performance_tweak(pdev, 0x5 << MAX_READ_REQUEST_SHIFT); */

	rtl_w1w0_eri(tp, 0xdc, ERIAR_MASK_0001, 0x00, 0x01, ERIAR_EXGMAC);
	rtl_w1w0_eri(tp, 0xdc, ERIAR_MASK_0001, 0x01, 0x00, ERIAR_EXGMAC);
	rtl_eri_write(tp, 0x2f8, ERIAR_MASK_0011, 0x1d8f, ERIAR_EXGMAC);

	RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);
	RTL_W32(MISC, RTL_R32(MISC) & ~RXDV_GATED_EN);
	RTL_W8(MaxTxPacketSize, EarlySize);

	rtl_eri_write(tp, 0xc0, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);
	rtl_eri_write(tp, 0xb8, ERIAR_MASK_0011, 0x0000, ERIAR_EXGMAC);

	/* Adjust EEE LED frequency */
	RTL_W8(EEE_LED, RTL_R8(EEE_LED) & ~0x07);

	rtl_w1w0_eri(tp, 0x2fc, ERIAR_MASK_0001, 0x01, 0x06, ERIAR_EXGMAC);
	rtl_w1w0_eri(tp, 0x1b0, ERIAR_MASK_0011, 0x0000, 0x1000, ERIAR_EXGMAC);
}

static void rtl_hw_start_8168g_2(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;
	static const struct ephy_info e_info_8168g_2[] = {
		{ 0x00, 0x0000,	0x0008 },
		{ 0x0c, 0x3df0,	0x0200 },
		{ 0x19, 0xffff,	0xfc00 },
		{ 0x1e, 0xffff,	0x20eb }
	};

	rtl_hw_start_8168g_1(tp); /*? share tx/rx fifo enable?  */

	/* disable aspm and clock request before access ephy */
	RTL_W8(Config2, RTL_R8(Config2) & ~ClkReqEn); /*? */
	RTL_W8(Config5, RTL_R8(Config5) & ~ASPM_en); /*? */
	/*rtl_ephy_init(tp, e_info_8168g_2, ARRAY_SIZE(e_info_8168g_2)); */
}
#endif
static void rtl_hw_start_8168(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	u32 ioaddr = tp->base_addr;
	u32 wol_mode = 0;

	RTL_W8(Cfg9346, Cfg9346_Unlock);

	RTL_W8(MaxTxPacketSize, TxPacketMax);

	rtl_set_rx_max_size(ioaddr, rx_buf_sz);

	tp->cp_cmd |= RTL_R16(CPlusCmd) | PktCntrDisable | INTT_1;

	RTL_W16(CPlusCmd, tp->cp_cmd); /*? no need */

	RTL_W16(IntrMitigate, 0x5151); /*? no need */

	rtl_set_rx_tx_desc_registers(tp, ioaddr);

	rtl_set_rx_tx_config_registers(tp);

	RTL_R8(IntrMask);

	/*	rtl_hw_start_8168g_2(tp); //? no need */
	RTL_W32(MISC, RTL_R32(MISC) & ~RXDV_GATED_EN);

	RTL_W8(Cfg9346, Cfg9346_Lock);

	RTL_W8(ChipCmd, CmdTxEnb | CmdRxEnb);

	rtl_set_rx_mode(dev);

	RTL_W16(MultiIntr, RTL_R16(MultiIntr) & 0xF000); /*? no need */

	/* Enable SCPU interrupt and disable KCPU interrupt */
#if defined(CONFIG_ARCH_RTK299O) || defined(CONFIG_ARCH_RTK293x) || defined(CONFIG_ARCH_RTK289X) || defined(CONFIG_ARCH_RTK284X)
	CRT_CLK_OnOff(ETH, CLK_ON, &wol_mode);
#else
	rtd_clearbits(CRT_INT_CTRL_KCPU_reg, BIT(17));
	rtd_setbits(CRT_INT_CTRL_SCPU_reg, BIT(17));
#endif
}

static int rtl8168_change_mtu(struct net_device *dev, int new_mtu)
{
	if (new_mtu < ETH_ZLEN ||
			new_mtu > JUMBO_9K)
		return -EINVAL;

	dev->mtu = new_mtu;
	netdev_update_features(dev);

	return 0;
}

static inline void rtl8168_make_unusable_by_asic(struct RxDesc *desc)
{
	desc->addr = cpu_to_le64(0x0badbadbadbadbadull);
	desc->opts1 &= ~cpu_to_le32(DescOwn | RsvdMask);
}

static void rtl8168_free_rx_databuff(struct rtl8168_private *tp,
		void **data_buff, struct RxDesc *desc)
{
	dma_unmap_single(&tp->dev->dev, le64_to_cpu(desc->addr), rx_buf_sz,
			DMA_FROM_DEVICE);

	kfree(*data_buff);
	*data_buff = NULL;
	rtl8168_make_unusable_by_asic(desc);
}

static inline void rtl8168_mark_to_asic(struct RxDesc *desc, u32 rx_buf_sz)
{
	u32 eor = le32_to_cpu(desc->opts1) & RingEnd;

	desc->opts1 = cpu_to_le32(DescOwn | eor | rx_buf_sz);
}

static inline void rtl8168_map_to_asic(struct RxDesc *desc, dma_addr_t mapping,
		u32 rx_buf_sz)
{
	desc->addr = cpu_to_le64(mapping);
	wmb();
	rtl8168_mark_to_asic(desc, rx_buf_sz);
}

static inline void *rtl8168_align(void *data)
{
	return (void *)ALIGN((long)data, 16);
}

static struct sk_buff *rtl8168_alloc_rx_data(struct rtl8168_private *tp,
		struct RxDesc *desc)
{
	void *data;
	dma_addr_t mapping;
	struct device *d = &tp->dev->dev;
	struct net_device *dev = tp->dev;
	int node = dev->dev.parent ? dev_to_node(dev->dev.parent) : -1;

	data = kmalloc_node(rx_buf_sz, GFP_KERNEL, node);
	if (!data)
		return NULL;

	if (rtl8168_align(data) != data) {
		kfree(data);
		data = kmalloc_node(rx_buf_sz + 15, GFP_KERNEL, node);
		if (!data)
			return NULL;
	}

	mapping = dma_map_single(d, rtl8168_align(data), rx_buf_sz,
			DMA_FROM_DEVICE);
	if (unlikely(dma_mapping_error(d, mapping))) {
		if (net_ratelimit())
			netif_err(tp, drv, tp->dev, "Failed to map RX DMA!\n");
		goto err_out;
	}

	rtl8168_map_to_asic(desc, mapping, rx_buf_sz);
	return data;

err_out:
	kfree(data);
	return NULL;
}

static void rtl8168_rx_clear(struct rtl8168_private *tp)
{
	unsigned int i;

	for (i = 0; i < NUM_RX_DESC; i++) {
		if (tp->Rx_databuff[i]) {
			rtl8168_free_rx_databuff(tp, tp->Rx_databuff + i,
					tp->RxDescArray + i);
		}
	}
}

static inline void rtl8168_mark_as_last_descriptor(struct RxDesc *desc)
{
	desc->opts1 |= cpu_to_le32(RingEnd);
}

static int rtl8168_rx_fill(struct rtl8168_private *tp)
{
	unsigned int i;

	for (i = 0; i < NUM_RX_DESC; i++) {
		void *data;

		if (tp->Rx_databuff[i])
			continue;

		data = rtl8168_alloc_rx_data(tp, tp->RxDescArray + i);
		if (!data) {
			rtl8168_make_unusable_by_asic(tp->RxDescArray + i);
			goto err_out;
		}
		tp->Rx_databuff[i] = data;
	}

	rtl8168_mark_as_last_descriptor(tp->RxDescArray + NUM_RX_DESC - 1);
	return 0;

err_out:
	rtl8168_rx_clear(tp);
	return -ENOMEM;
}

static int rtl8168_init_ring(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl8168_init_ring_indexes(tp);

	memset(tp->tx_skb, 0x0, NUM_TX_DESC * sizeof(struct ring_info));
	memset(tp->Rx_databuff, 0x0, NUM_RX_DESC * sizeof(void *));

	return rtl8168_rx_fill(tp);
}

static void rtl8168_unmap_tx_skb(struct net_device *dev, struct ring_info *tx_skb,
		struct TxDesc *desc)
{
	unsigned int len = tx_skb->len;

	dma_unmap_single(&dev->dev, le64_to_cpu(desc->addr), len, DMA_TO_DEVICE);

	desc->opts1 = 0x00;
	desc->opts2 = 0x00;
	desc->addr = 0x00;
	tx_skb->len = 0;
}

static void rtl8168_tx_clear_range(struct rtl8168_private *tp, u32 start,
		unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++) {
		unsigned int entry = (start + i) % NUM_TX_DESC;
		struct ring_info *tx_skb = tp->tx_skb + entry;
		unsigned int len = tx_skb->len;

		if (len) {
			struct sk_buff *skb = tx_skb->skb;

			rtl8168_unmap_tx_skb(tp->dev, tx_skb,
					tp->TxDescArray + entry);
			if (skb) {
				tp->dev->stats.tx_dropped++;
				dev_kfree_skb(skb);
				tx_skb->skb = NULL;
			}
		}
	}
}

static void rtl8168_tx_clear(struct rtl8168_private *tp)
{
	rtl8168_tx_clear_range(tp, tp->dirty_tx, NUM_TX_DESC);
	tp->cur_tx = tp->dirty_tx = 0;
}

static void rtl_reset_work(struct rtl8168_private *tp)
{
	struct net_device *dev = tp->dev;
	int i;

	napi_disable(&tp->napi);
	netif_stop_queue(dev);
	//synchronize_sched();
	synchronize_irq(dev->irq);

	rtl8168_hw_reset(tp);

	for (i = 0; i < NUM_RX_DESC; i++)
		rtl8168_mark_to_asic(tp->RxDescArray + i, rx_buf_sz);

	rtl8168_tx_clear(tp);
	rtl8168_init_ring_indexes(tp);

	napi_enable(&tp->napi);
	rtl_hw_start(dev);
	netif_wake_queue(dev);
	rtl8168_check_link_status(dev, tp, tp->base_addr);
}

static void rtl8168_tx_timeout(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
}

static int rtl8168_xmit_frags(struct rtl8168_private *tp, struct sk_buff *skb,
		u32 *opts)
{
	struct skb_shared_info *info = skb_shinfo(skb);
	unsigned int cur_frag, entry;
	struct TxDesc * uninitialized_var(txd);
	struct device *d = &tp->dev->dev;

	entry = tp->cur_tx;
	for (cur_frag = 0; cur_frag < info->nr_frags; cur_frag++) {
		const skb_frag_t *frag = info->frags + cur_frag;
		dma_addr_t mapping;
		u32 status, len;
		void *addr;

		entry = (entry + 1) % NUM_TX_DESC;

		txd = tp->TxDescArray + entry;
		len = skb_frag_size(frag);
		addr = skb_frag_address(frag);
		mapping = dma_map_single(d, addr, len, DMA_TO_DEVICE);
		if (unlikely(dma_mapping_error(d, mapping))) {
			if (net_ratelimit())
				netif_err(tp, drv, tp->dev,
						"Failed to map TX fragments DMA!\n");
			goto err_out;
		}

		/* Anti gcc 2.95.3 bugware (sic) */
		status = opts[0] | len |
			(RingEnd * !((entry + 1) % NUM_TX_DESC));

		txd->opts1 = cpu_to_le32(status);
		txd->opts2 = cpu_to_le32(opts[1]);
		txd->addr = cpu_to_le64(mapping);

		tp->tx_skb[entry].len = len;
	}

	if (cur_frag) {
		tp->tx_skb[entry].skb = skb;
		txd->opts1 |= cpu_to_le32(LastFrag);
	}

	return cur_frag;

err_out:
	rtl8168_tx_clear_range(tp, tp->cur_tx + 1, cur_frag);
	return -EIO;
}

static bool rtl_skb_pad(struct sk_buff *skb)
{
	if (skb_padto(skb, ETH_ZLEN))
		return false;
	skb_put(skb, ETH_ZLEN - skb->len);
	return true;
}

static bool rtl_test_hw_pad_bug(struct rtl8168_private *tp, struct sk_buff *skb)
{
	return skb->len < ETH_ZLEN && false;
}

static inline bool rtl8168_tso_csum(struct rtl8168_private *tp,
		struct sk_buff *skb, u32 *opts)
{
	const struct rtl_tx_desc_info *info = &tx_desc_info;
	u32 mss = skb_shinfo(skb)->gso_size;
	int offset = info->opts_offset;

	if (mss) {
		opts[0] |= TD_LSO;
		opts[offset] |= min(mss, TD_MSS_MAX) << info->mss_shift;
	} else if (skb->ip_summed == CHECKSUM_PARTIAL) {
		const struct iphdr *ip = ip_hdr(skb);

		if (unlikely(rtl_test_hw_pad_bug(tp, skb)))
			return skb_checksum_help(skb) == 0 && rtl_skb_pad(skb);

		if (ip->protocol == IPPROTO_TCP)
			opts[offset] |= info->checksum.tcp;
		else if (ip->protocol == IPPROTO_UDP)
			opts[offset] |= info->checksum.udp;
		else
			WARN_ON_ONCE(1);
	} else {
		if (unlikely(rtl_test_hw_pad_bug(tp, skb)))
			return rtl_skb_pad(skb);
	}
	return true;
}

static netdev_tx_t rtl8168_start_xmit(struct sk_buff *skb,
		struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	unsigned int entry = tp->cur_tx % NUM_TX_DESC;
	struct TxDesc *txd = tp->TxDescArray + entry;
	u32 ioaddr = tp->base_addr;
	struct device *d = &tp->dev->dev;
	dma_addr_t mapping;
	u32 status, len;
	u32 opts[2];
	int frags;

	if (unlikely(!TX_FRAGS_READY_FOR(tp, skb_shinfo(skb)->nr_frags))) {
		netif_err(tp, drv, dev, "BUG! Tx Ring full when queue awake!\n");
		goto err_stop_0;
	}

	if (unlikely(le32_to_cpu(txd->opts1) & DescOwn)) {
		eth_err("DescOwn bit is set, Des = 0x%08x, entry = %d\n", le32_to_cpu(txd->opts1), entry);
		goto err_stop_0;
	}

	opts[1] = cpu_to_le32(rtl8168_tx_vlan_tag(skb));
	opts[0] = DescOwn;

	if (!rtl8168_tso_csum(tp, skb, opts)) /*? sw checksum */
		goto err_update_stats;

	len = skb_headlen(skb);
	mapping = dma_map_single(d, skb->data, len, DMA_TO_DEVICE);
	if (unlikely(dma_mapping_error(d, mapping))) {
		if (net_ratelimit())
			netif_err(tp, drv, dev, "Failed to map TX DMA!\n");
		goto err_dma_0;
	}

	tp->tx_skb[entry].len = len;
	txd->addr = cpu_to_le64(mapping);

	frags = rtl8168_xmit_frags(tp, skb, opts);
	if (frags < 0)
		goto err_dma_1;
	else if (frags)
		opts[0] |= FirstFrag;
	else {
		opts[0] |= FirstFrag | LastFrag;
		tp->tx_skb[entry].skb = skb;
	}

	txd->opts2 = cpu_to_le32(opts[1]);

	skb_tx_timestamp(skb);

	wmb();

	/* Anti gcc 2.95.3 bugware (sic) */
	status = opts[0] | len | (RingEnd * !((entry + 1) % NUM_TX_DESC));
	txd->opts1 = cpu_to_le32(status);

	tp->cur_tx += frags + 1;

	wmb();

	RTL_W8(TxPoll, NPQ);

	if (!TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS)) {
		/* Avoid wrongly optimistic queue wake-up: rtl_tx thread must
		 * not miss a ring update when it notices a stopped queue.
		 */
		smp_wmb();
		netif_stop_queue(dev);
		/* Sync with rtl_tx:
		 * - publish queue status and cur_tx ring index (write barrier)
		 * - refresh dirty_tx ring index (read barrier).
		 * May the current thread have a pessimistic view of the ring
		 * status and forget to wake up queue, a racing rtl_tx thread
		 * can't.
		 */
		smp_mb();
		if (TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS))
			netif_wake_queue(dev);
	}

	return NETDEV_TX_OK;

err_dma_1:
	rtl8168_unmap_tx_skb(dev, tp->tx_skb + entry, txd);
err_dma_0:
	dev_kfree_skb(skb);
err_update_stats:
	dev->stats.tx_dropped++;
	return NETDEV_TX_OK;

err_stop_0:
	netif_stop_queue(dev);
	dev->stats.tx_dropped++;
	return NETDEV_TX_BUSY;
}

#if 0
static void rtl8168_pcierr_interrupt(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	struct pci_dev *pdev = tp->pci_dev;
	u16 pci_status, pci_cmd;

	pci_read_config_word(pdev, PCI_COMMAND, &pci_cmd);
	pci_read_config_word(pdev, PCI_STATUS, &pci_status);

	netif_err(tp, intr, dev, "PCI error (cmd = 0x%04x, status = 0x%04x)\n",
			pci_cmd, pci_status);

	/*
	 * The recovery sequence below admits a very elaborated explanation:
	 * - it seems to work;
	 * - I did not see what else could be done;
	 * - it makes iop3xx happy.
	 *
	 * Feel free to adjust to your needs.
	 */
	if (pdev->broken_parity_status)
		pci_cmd &= ~PCI_COMMAND_PARITY;
	else
		pci_cmd |= PCI_COMMAND_SERR | PCI_COMMAND_PARITY;

	pci_write_config_word(pdev, PCI_COMMAND, pci_cmd);

	pci_write_config_word(pdev, PCI_STATUS,
			pci_status & (PCI_STATUS_DETECTED_PARITY |
				PCI_STATUS_SIG_SYSTEM_ERROR | PCI_STATUS_REC_MASTER_ABORT |
				PCI_STATUS_REC_TARGET_ABORT | PCI_STATUS_SIG_TARGET_ABORT));

	/* The infamous DAC f*ckup only happens at boot time */
	if ((tp->cp_cmd & PCIDAC) && !tp->cur_rx) {
		u32 ioaddr = tp->base_addr;

		netif_info(tp, intr, dev, "disabling PCI DAC\n");
		tp->cp_cmd &= ~PCIDAC;
		RTL_W16(CPlusCmd, tp->cp_cmd);
		dev->features &= ~NETIF_F_HIGHDMA;
	}

	rtl8168_hw_reset(tp);

	/*rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING); */
}
#endif

static void rtl_tx(struct net_device *dev, struct rtl8168_private *tp)
{
	unsigned int dirty_tx, tx_left;

	dirty_tx = tp->dirty_tx;
	smp_rmb();
	tx_left = tp->cur_tx - dirty_tx;

	while (tx_left > 0) {
		unsigned int entry = dirty_tx % NUM_TX_DESC;
		struct ring_info *tx_skb = tp->tx_skb + entry;
		u32 status;

		rmb();
		status = le32_to_cpu(tp->TxDescArray[entry].opts1);
		if (status & DescOwn)
			break;

		rtl8168_unmap_tx_skb(dev, tx_skb,
				tp->TxDescArray + entry);
		if (status & LastFrag) {
			u64_stats_update_begin(&tp->tx_stats.syncp);
			tp->tx_stats.packets++;
			tp->tx_stats.bytes += tx_skb->skb->len;
			u64_stats_update_end(&tp->tx_stats.syncp);
			dev_kfree_skb(tx_skb->skb);
			tx_skb->skb = NULL;
		}
		dirty_tx++;
		tx_left--;
	}

	if (tp->dirty_tx != dirty_tx) {
		tp->dirty_tx = dirty_tx;
		/* Sync with rtl8168_start_xmit:
		 * - publish dirty_tx ring index (write barrier)
		 * - refresh cur_tx ring index and queue status (read barrier)
		 * May the current thread miss the stopped queue condition,
		 * a racing xmit thread can only have a right view of the
		 * ring status.
		 */
		smp_mb();
		if (netif_queue_stopped(dev) &&
				TX_FRAGS_READY_FOR(tp, MAX_SKB_FRAGS)) {
			netif_wake_queue(dev);
		}
		/*
		 * 8168 hack: TxPoll requests are lost when the Tx packets are
		 * too close. Let's kick an extra TxPoll request when a burst
		 * of start_xmit activity is detected (if it is not detected,
		 * it is slow enough). -- FR
		 */
		if (tp->cur_tx != dirty_tx) {
			u32 ioaddr = tp->base_addr;

			RTL_W8(TxPoll, NPQ);
		}
	}
}

static inline int rtl8168_fragmented_frame(u32 status)
{
	return (status & (FirstFrag | LastFrag)) != (FirstFrag | LastFrag);
}

static inline void rtl8168_rx_csum(struct sk_buff *skb, u32 opts1)
{
	u32 status = opts1 & RxProtoMask;

	if (((status == RxProtoTCP) && !(opts1 & TCPFail)) ||
			((status == RxProtoUDP) && !(opts1 & UDPFail)))
		skb->ip_summed = CHECKSUM_UNNECESSARY;
	else
		skb_checksum_none_assert(skb);
}

static struct sk_buff *rtl8168_try_rx_copy(void *data,
		struct rtl8168_private *tp,
		int pkt_size,
		dma_addr_t addr)
{
	struct sk_buff *skb;
	struct device *d = &tp->dev->dev;

	data = rtl8168_align(data);
	dma_sync_single_for_cpu(d, addr, pkt_size, DMA_FROM_DEVICE);
	prefetch(data);
	skb = netdev_alloc_skb_ip_align(tp->dev, pkt_size);
	if (skb)
		memcpy(skb->data, data, pkt_size);
	dma_sync_single_for_device(d, addr, pkt_size, DMA_FROM_DEVICE);

	return skb;
}

static int rtl_rx(struct net_device *dev, struct rtl8168_private *tp, u32 budget)
{
	unsigned int cur_rx, rx_left;
	unsigned int count;

	cur_rx = tp->cur_rx;

	for (rx_left = min(budget, NUM_RX_DESC); rx_left > 0; rx_left--, cur_rx++) {
		unsigned int entry = cur_rx % NUM_RX_DESC;
		struct RxDesc *desc = tp->RxDescArray + entry;
		u32 status;

		rmb();
		status = le32_to_cpu(desc->opts1) & tp->opts1_mask;

		if (status & DescOwn)
			break;
		if (unlikely(status & RxRES)) {
			netif_info(tp, rx_err, dev, "Rx ERROR. status = %08x\n",
					status);
			dev->stats.rx_errors++;
			if (status & (RxRWT | RxRUNT))
				dev->stats.rx_length_errors++;
			if (status & RxCRC)
				dev->stats.rx_crc_errors++;
			if (status & RxFOVF) {
				rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
				dev->stats.rx_fifo_errors++;
			}
			if ((status & (RxRUNT | RxCRC)) &&
					!(status & (RxRWT | RxFOVF)) &&
					(dev->features & NETIF_F_RXALL))
				goto process_pkt;
		} else {
			struct sk_buff *skb;
			dma_addr_t addr;
			int pkt_size;

process_pkt:
			addr = le64_to_cpu(desc->addr);
			if (likely(!(dev->features & NETIF_F_RXFCS)))
				pkt_size = (status & 0x00003fff) - 4;
			else
				pkt_size = status & 0x00003fff;

			/*
			 * The driver does not support incoming fragmented
			 * frames. They are seen as a symptom of over-mtu
			 * sized frames.
			 */
			if (unlikely(rtl8168_fragmented_frame(status))) {
				dev->stats.rx_dropped++;
				dev->stats.rx_length_errors++;
				goto release_descriptor;
			}

			skb = rtl8168_try_rx_copy(tp->Rx_databuff[entry],
					tp, pkt_size, addr);
			if (!skb) {
				dev->stats.rx_dropped++;
				goto release_descriptor;
			}

			rtl8168_rx_csum(skb, status);
			skb_put(skb, pkt_size);
			skb->protocol = eth_type_trans(skb, dev);

			rtl8168_rx_vlan_tag(desc, skb);

			napi_gro_receive(&tp->napi, skb);

			u64_stats_update_begin(&tp->rx_stats.syncp);
			tp->rx_stats.packets++;
			tp->rx_stats.bytes += pkt_size;
			u64_stats_update_end(&tp->rx_stats.syncp);
		}
release_descriptor:
		desc->opts2 = 0;
		wmb();
		rtl8168_mark_to_asic(desc, rx_buf_sz);
	}

	count = cur_rx - tp->cur_rx;
	tp->cur_rx = cur_rx;

	return count;
}

static irqreturn_t rtl8168_interrupt(int irq, void *dev_instance)
{
	struct net_device *dev = dev_instance;
	struct rtl8168_private *tp = netdev_priv(dev);
	int handled = 0;
	u16 status;

	status = rtl_get_events(tp);
	if (status && status != 0xffff) {
		status &= RTL_EVENT_NAPI | tp->event_slow;
		if (status) {
			handled = 1;

			rtl_irq_disable(tp);
			napi_schedule(&tp->napi);
		}
	}
	return IRQ_RETVAL(handled);
}

/*
 * Workqueue context.
 */
static void rtl_slow_event_work(struct rtl8168_private *tp)
{
	struct net_device *dev = tp->dev;
	u16 status;

	status = rtl_get_events(tp) & tp->event_slow;
	rtl_ack_events(tp, status);

	/*if (unlikely(status & SYSErr)) */
	/*	rtl8168_pcierr_interrupt(dev); */

	if (status & LinkChg)
	{
		__rtl8168_check_link_status(dev, tp, tp->base_addr, true);
		if(tp->link_ok(tp->base_addr))
		{
			rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
		}
	}
	rtl_irq_enable_all(tp);
}

#if !NWAY_ENABLE
static void rtl_phy_work(struct rtl8168_private *tp)
{
	struct timer_list *timer = &tp->timer;
	u32 ioaddr = tp->base_addr;
	unsigned long timeout = RTL8168_PHY_TIMEOUT;
	struct net_device *dev = tp->dev;

	rtl8168_phy_int_disable(tp);
	if (tp->phy_reset_pending(tp)) {
		/*
		 * A busy loop could burn quite a few cycles on nowadays CPU.
		 * Let's delay the execution of the timer for a few ticks.
		 */
		timeout = HZ/10;
		rtl8168_phy_int_enable(tp);
		goto out_mod_timer;
	}

	rtl8168_phy_int_enable(tp);
	if (tp->link_ok(ioaddr))
		return;

	netif_warn(tp, link, tp->dev, "PHY reset until link up\n");

	rtl8168_phy_int_disable(tp);
#ifdef ENABLE_ALDPS
	tp->phy_set_aldps(tp, 1);
#endif
	tp->phy_enhance_performance(tp, 1);

	if(tp->autoneg == AUTONEG_DISABLE)
	{
		rtl8168_phy_reset(dev, tp);

		//eth_debug("==> %s:%s N-way %d \n",tp->dev->name,__FUNCTION__, rtd_inl(0xB801b690));

		rtl8168_set_speed(dev, AUTONEG_ENABLE, SPEED_100, DUPLEX_FULL,
				ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
				ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full |
				(tp->mii.supports_gmii ?
				 ADVERTISED_1000baseT_Half |
				 ADVERTISED_1000baseT_Full : 0));

		tp->autoneg = AUTONEG_ENABLE;
		rtl8168_phy_int_enable(tp);

		//rtl_pll_power_up(tp);
		return;
	}
	rtl8168_phy_int_enable(tp);

out_mod_timer:
	mod_timer(timer, jiffies + timeout);
}
#endif

static void rtl_task(struct work_struct *work)
{
	static const struct {
		int bitnr;
		void (*action)(struct rtl8168_private *);
	} rtl_work[] = {
		/* XXX - keep rtl_slow_event_work() as first element. */
		{ RTL_FLAG_TASK_SLOW_PENDING,	rtl_slow_event_work },
		{ RTL_FLAG_TASK_RESET_PENDING,	rtl_reset_work },
		{ RTL_FLAG_TASK_PHY_PENDING,	rtl_phy_work }
	};
	struct rtl8168_private *tp =
		container_of(work, struct rtl8168_private, wk.work);
	struct net_device *dev = tp->dev;
	int i;

	rtl_lock_work(tp);

	if (!netif_running(dev) ||
			!test_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags))
		goto out_unlock;

	for (i = 0; i < ARRAY_SIZE(rtl_work); i++) {
		bool pending;

		pending = test_and_clear_bit(rtl_work[i].bitnr, tp->wk.flags);
		if (pending)
			rtl_work[i].action(tp);
	}

out_unlock:
	rtl_unlock_work(tp);
}

static int rtl8168_poll(struct napi_struct *napi, int budget)
{
	struct rtl8168_private *tp = container_of(napi, struct rtl8168_private, napi);
	struct net_device *dev = tp->dev;
	u16 enable_mask = RTL_EVENT_NAPI | tp->event_slow;
	int work_done= 0;
	u16 status;

	/* Check interrupt status */
	status = rtl_get_events(tp);
	rtl_ack_events(tp, status & ~tp->event_slow);

	if (status & RTL_EVENT_NAPI_RX)
		work_done = rtl_rx(dev, tp, (u32) budget);

	if (status & RTL_EVENT_NAPI_TX)
		rtl_tx(dev, tp);

	if (status & tp->event_slow) {
		enable_mask &= ~tp->event_slow;

		rtl_schedule_task(tp, RTL_FLAG_TASK_SLOW_PENDING);
	}

	if (work_done < budget) {
		napi_complete(napi);

		rtl_irq_enable(tp, enable_mask);
	}

	return work_done;
}

static void rtl8168_rx_missed(struct net_device *dev, u32 ioaddr)
{
	/*	struct rtl8168_private *tp = netdev_priv(dev); */

	return;

	dev->stats.rx_missed_errors += (RTL_R32(RxMissed) & 0xffffff);
	RTL_W32(RxMissed, 0);
}

static void rtl8168_down(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	u32 ioaddr = tp->base_addr;

#if !NWAY_ENABLE
	del_timer_sync(&tp->timer);
#endif
	del_timer_sync(&tp->link_check_timer);

	napi_disable(&tp->napi);
	netif_stop_queue(dev);

	rtl8168_hw_reset(tp);
	/*
	 * At this point device interrupts can not be enabled in any function,
	 * as netif_running is not true (rtl8168_interrupt, rtl8168_reset_task)
	 * and napi is disabled (rtl8168_poll).
	 */
	rtl8168_rx_missed(dev, ioaddr);

	/* Give a racing hard_start_xmit a few cycles to complete. */
	synchronize_sched();

	rtl8168_tx_clear(tp);

	rtl8168_rx_clear(tp);

#if NWAY_ENABLE
	rtl_pll_power_down(tp);
#endif
}

static int rtl8168_close(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	u32 wol_mode = 0;

	eth_info("%s\n", __func__);
	del_timer_sync(&tp->link_check_timer);
	//eth_debug("==> %s:%s %d \n",tp->dev->name,__FUNCTION__,rtd_inl(0xB801b690));

	/*pm_runtime_get_sync(&pdev->dev); */

	/* Update counters before going down */
	rtl8168_update_counters(dev);

	rtl_lock_work(tp);
	clear_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);

	rtl8168_down(dev);
	rtl_unlock_work(tp);

	free_irq(dev->irq, dev);
#if defined(CONFIG_ARCH_RTK299O) || defined(CONFIG_ARCH_RTK293x) || defined(CONFIG_ARCH_RTK289X) || defined(CONFIG_ARCH_RTK284X)
	CRT_CLK_OnOff(ETH, CLK_OFF, &wol_mode);
#else
	rtd_clearbits(CRT_INT_CTRL_SCPU_reg, BIT(17));
#endif

	dma_free_coherent(&dev->dev, R8168_RX_RING_BYTES, tp->RxDescArray,
			tp->RxPhyAddr);
	dma_free_coherent(&dev->dev, R8168_TX_RING_BYTES, tp->TxDescArray,
			tp->TxPhyAddr);
	tp->TxDescArray = NULL;
	tp->RxDescArray = NULL;

	/*pm_runtime_put_sync(&pdev->dev); */

	return 0;
}

#ifdef CONFIG_NET_POLL_CONTROLLER
static void rtl8168_netpoll(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	rtl8168_interrupt(tp->pci_dev->irq, dev);
}
#endif

static int rtl_open(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	struct timer_list *timer = &tp->link_check_timer;
	u32 ioaddr = tp->base_addr;
	int retval = -ENOMEM;

	eth_info("%s\n", __func__);
	tp->link_start_time = jiffies_to_msecs(jiffies);
	//eth_debug("==> %s:%s %d \n",tp->dev->name,__FUNCTION__,rtd_inl(0xB801b690));

	/*pm_runtime_get_sync(&pdev->dev);   */

	/*
	 * Rx and Tx descriptors needs 256 bytes alignment.
	 * dma_alloc_coherent provides more.
	 */
	tp->TxDescArray = dma_alloc_coherent(&dev->dev, R8168_TX_RING_BYTES,
			&tp->TxPhyAddr, GFP_ATOMIC);
	if (!tp->TxDescArray) {
		eth_err("TX can't allocate continue memory\n");
		goto err_pm_runtime_put;
	}
	/* dma_alloc_cohernet use GFP_ATOMIC, memory need to reset 0 */
	memset(tp->TxDescArray, 0x0, R8168_TX_RING_BYTES);

	tp->RxDescArray = dma_alloc_coherent(&dev->dev, R8168_RX_RING_BYTES,
			&tp->RxPhyAddr, GFP_ATOMIC);
	if (!tp->RxDescArray) {
		eth_err("RX can't allocate continue memory\n");
		goto err_free_tx_0;
	}
	/* dma_alloc_cohernet use GFP_ATOMIC, memory need to reset 0 */
	memset(tp->RxDescArray, 0x0, R8168_RX_RING_BYTES);

	retval = rtl8168_init_ring(dev);
	if (retval < 0)
		goto err_free_rx_1;

	INIT_WORK(&tp->wk.work, rtl_task);

	smp_mb();

	retval = request_irq(dev->irq, rtl8168_interrupt, 0, dev->name, dev);
	if (retval < 0)
		goto err_release_fw_2;

	rtl_lock_work(tp);

	set_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);

	napi_enable(&tp->napi);

#ifdef ENABLE_EEEP
	rtl8168_mac_eeep_patch_disable(tp);
#endif

	rtl8168_phy_int_disable(tp);
	rtl_udelay_loop_wait_high(tp, &rtl_phy_status_cond, 100, 20);
	rtl8168_init_phy(dev, tp);
	rtl8168_phy_int_enable(tp);

	__rtl8168_set_features(dev, dev->features);

#if NWAY_ENABLE
	rtl8168_phy_int_disable(tp);
	rtl_pll_power_up(tp);
	rtl8168_phy_int_enable(tp);
#endif

	rtl_hw_start(dev);

	netif_start_queue(dev);

	rtl_unlock_work(tp);

	tp->saved_wolopts = 0;
	/*pm_runtime_put_noidle(&pdev->dev); */

	rtl8168_check_link_status(dev, tp, ioaddr);
	/* Check link status timer */
	mod_timer(timer, jiffies + RTL8168_LINK_TIMEOUT);

#if !NWAY_ENABLE
	if(tp->link_ok(tp->base_addr))
	{
		rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
	}
#endif

out:
	return retval;

err_release_fw_2:
	rtl8168_rx_clear(tp);
err_free_rx_1:
	dma_free_coherent(&dev->dev, R8168_RX_RING_BYTES, tp->RxDescArray,
			tp->RxPhyAddr);
	tp->RxDescArray = NULL;
err_free_tx_0:
	dma_free_coherent(&dev->dev, R8168_TX_RING_BYTES, tp->TxDescArray,
			tp->TxPhyAddr);
	tp->TxDescArray = NULL;
err_pm_runtime_put:
	/*	pm_runtime_put_noidle(&pdev->dev); */
	goto out;
}

	static struct rtnl_link_stats64 *
rtl8168_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
	struct rtl8168_private *tp = netdev_priv(dev);
	u32 ioaddr = tp->base_addr;
	unsigned int start;

	if (netif_running(dev))
		rtl8168_rx_missed(dev, ioaddr);

	do {
		start = u64_stats_fetch_begin_irq(&tp->rx_stats.syncp);
		stats->rx_packets = tp->rx_stats.packets;
		stats->rx_bytes	= tp->rx_stats.bytes;
	} while (u64_stats_fetch_retry_irq(&tp->rx_stats.syncp, start));


	do {
		start = u64_stats_fetch_begin_irq(&tp->tx_stats.syncp);
		stats->tx_packets = tp->tx_stats.packets;
		stats->tx_bytes	= tp->tx_stats.bytes;
	} while (u64_stats_fetch_retry_irq(&tp->tx_stats.syncp, start));

	stats->rx_dropped	= dev->stats.rx_dropped;
	stats->tx_dropped	= dev->stats.tx_dropped;
	stats->rx_length_errors = dev->stats.rx_length_errors;
	stats->rx_errors	= dev->stats.rx_errors;
	stats->rx_crc_errors	= dev->stats.rx_crc_errors;
	stats->rx_fifo_errors	= dev->stats.rx_fifo_errors;
	stats->rx_missed_errors = dev->stats.rx_missed_errors;

	return stats;
}

static struct kobject *eth_kobj;

static ssize_t rtl8168_link_recovery_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	return sprintf(buf, "link_recovery_enable = %d, link_recovery_count = %d\n", tp->link_recovery_enable, tp->link_recovery_count);
}

static ssize_t rtl8168_link_recovery_store(struct kobject *kobj, struct kobj_attribute *attr,
		const char *buf, size_t count)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	sscanf(buf, "%d", &tp->link_recovery_enable);

	return count;
}

#ifdef ENABLE_WOL
static ssize_t rtl8168_wol_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);
	u32 wol_status = rtd_inl(0xb8060450);
	//u32 ioaddr = tp->base_addr;

	/* Check WOL status */
	//RTL_W32(OCPDR, 0x70030000);

        return sprintf(buf, "wol_enable = %d, wol_interrupt = 0x%08x	\
				\n%s\n", tp->ap_wol_enable, wol_status, wol_status & BIT(9)? "Receive magic packet!!":"");
}

static ssize_t rtl8168_wol_store(struct kobject *kobj, struct kobj_attribute *attr,
		const char *buf, size_t count)
{
	struct rtl8168_private *tp = netdev_priv(ndev);
	u32 ioaddr = tp->base_addr;
	pm_message_t pmstate;
	//u32 wol_mode = 1;

	sscanf(buf, "%d", &tp->ap_wol_enable);

	if(tp->ap_wol_enable) {
		/* Set share memory to 8051 */
		rtd_setbits(0xb8060500, BIT(24));
		/* Clear ETN WOL Status */
		RTL_W32(OCPDR, 0xf0031e00);
		/* Set PLETN WOW_GMAC_CLKSEL */
		rtd_outl(0xb8016c10, 0x1);
#ifdef CONFIG_PM
		rtl8168_suspend(network_devs, pmstate);
#endif
	}
	else {
		/* Clock & reset */
		//CRT_CLK_OnOff(ETH, CLK_ON, &wol_mode);
		/* Clear wol interrupt status */
		RTL_W32(OCPDR, 0x6e410000);
		RTL_W32(RxConfig, 0x00000000);
		RTL_W32(OCPDR, 0x6e400000);
		RTL_W32(RDSAR1, 0x32000021);
		RTL_W32(OCPDR, 0x746f0000);
		RTL_W32(OCPDR, 0xee400001);
		RTL_W32(OCPDR, 0xf0031e00);
		/* Clear share memory to 8051 */
		rtd_clearbits(0xb8060500, BIT(24));
		rtd_outl(0xb8016c10, 0x0);
#ifdef CONFIG_PM
		rtl8168_resume(network_devs);
#endif
	}

	return count;
}
#endif

static ssize_t rtl8168_pga_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	return sprintf(buf, "manual_pga_val = 0x%x\n", pga_val);
}

static ssize_t rtl8168_pga_store(struct kobject *kobj, struct kobj_attribute *attr,
		const char *buf, size_t count)
{
	struct rtl8168_private *tp = netdev_priv(ndev);
	int phy_register = 0x00;
	u32 phy_write_data = 0x0000;
	u32 phy_read_data = 0x0000;

	sscanf(buf, "0x%x", &pga_val);

	if(pga_val) {
		rtl8168_xmii_set_page(tp, 0x0bce);
		phy_write_data = 0x0f10 | pga_val;
		phy_register = 0x15;
		rtl_writephy(tp, phy_register, phy_write_data);
		phy_read_data = rtl_readphy(tp, phy_register);
		eth_info("manual_pga_val = 0x%x\n", phy_read_data & 0xf);
		rtl8168_xmii_set_page(tp, 0x0000);
	}

	return count;
}

static ssize_t rtl8168_tapbin_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	return sprintf(buf, "manual_tapbin_val = 0x%04x\n", tapbin_val);
}

static ssize_t rtl8168_tapbin_store(struct kobject *kobj, struct kobj_attribute *attr,
		const char *buf, size_t count)
{
	struct rtl8168_private *tp = netdev_priv(ndev);
	int phy_register = 0x00;
	u32 phy_write_data = 0x0000;
	u32 phy_read_data = 0x0000;

	sscanf(buf, "0x%04x", &tapbin_val);

	if(tapbin_val) {
		/* change Page to 0x0bce */
		rtl8168_xmii_set_page(tp, 0x0bce);
		/* set reg16 bit[15:0] */
		phy_write_data = tapbin_val;
		phy_register = 0x10;
		rtl_writephy(tp, phy_register, phy_write_data);
		/* read reg16 bit[15:0] */
		phy_read_data = rtl_readphy(tp, phy_register);
		eth_info("Tapbin val = 0x%04x\n", phy_read_data);
		rtl8168_xmii_set_page(tp, 0x0000);
	}

	return count;
}
static ssize_t rtl8168_snr_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	rtl_read_snr_val(tp);

	return sprintf(buf, "snr_debug = %d\n", snr_debug);
}

static ssize_t rtl8168_snr_store(struct kobject *kobj, struct kobj_attribute *attr,
		const char *buf, size_t count)
{
	sscanf(buf, "%d", &snr_debug);

	return count;
}

static ssize_t rtl8168_adc_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	rtl_read_adc_val(tp);

	return sprintf(buf, "adc_debug = %d\n", adc_debug);
}

static ssize_t rtl8168_adc_store(struct kobject *kobj, struct kobj_attribute *attr,
		const char *buf, size_t count)
{
	sscanf(buf, "%d", &adc_debug);

	return count;
}

static ssize_t rtl8168_phy_status_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);
	rtl_phy_status *phyStatus = &tp->phy_status;
	u32 ioaddr = tp->base_addr;

	rtl_get_phy_status(tp);
	return sprintf(buf, "MAC link status = 0x%08x, link %s		\
			     \nPHY link status = 0x%4x, link %s 	\
			     \n%uMbps, %s-duplex 			\
			     \nrd_dbg0 = 0x%4x				\
			     \nclk_fail_mac_sys = 0x%04x		\
			     \nmcu = 0x%04x, 0x%04x			\
			     \nlock_main_uc = 0x%4x, %s\n",
			RTL_R8(PHYstatus), tp->link_ok(ioaddr) ? "up":"down",
			phyStatus->link_status, phyStatus->link_status & BIT(2) ? "up":"down",
			phyStatus->link_speed & BIT(5) ? 1000 : phyStatus->link_speed & BIT(4) ? 100 : 10,
			phyStatus->link_speed & BIT(3) ? "full": "half",
			phyStatus->rd_dbg, phyStatus->clk_fail, phyStatus->mcu1, phyStatus->mcu2,
			phyStatus->lock_main, phyStatus->lock_main & BIT(1) ? "abnormal":"normal");
}

static ssize_t rtl8168_linkup_time_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	return sprintf(buf, "Linkup time = %dms\n", tp->link_up_time);
}

static ssize_t rtl8168_mac_addr_show(struct kobject *kobj, struct kobj_attribute *attr,
		char *buf)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	return sprintf(buf, "%s: RTL8168 at 0x%08x, "
			"%02x:%02x:%02x:%02x:%02x:%02x, "
			"IRQ %d\n",
			ndev->name,
			tp->base_addr,
			ndev->dev_addr[0], ndev->dev_addr[1],
			ndev->dev_addr[2], ndev->dev_addr[3],
			ndev->dev_addr[4], ndev->dev_addr[5], ndev->irq);
}

static struct kobj_attribute rtl8168_link_recovery =
__ATTR(link_recovery, S_IRUGO | S_IWUSR, rtl8168_link_recovery_show, rtl8168_link_recovery_store);
#ifdef ENABLE_WOL
static struct kobj_attribute rtl8168_wol =
__ATTR(wol, S_IRUGO | S_IWUSR, rtl8168_wol_show, rtl8168_wol_store);
#endif
static struct kobj_attribute rtl8168_pga =
__ATTR(pga, S_IRUGO | S_IWUSR, rtl8168_pga_show, rtl8168_pga_store);
static struct kobj_attribute rtl8168_tapbin =
__ATTR(tapbin, S_IRUGO | S_IWUSR, rtl8168_tapbin_show, rtl8168_tapbin_store);
static struct kobj_attribute rtl8168_snr =
__ATTR(snr, S_IRUGO | S_IWUSR, rtl8168_snr_show, rtl8168_snr_store);
static struct kobj_attribute rtl8168_adc =
__ATTR(adc, S_IRUGO | S_IWUSR, rtl8168_adc_show, rtl8168_adc_store);
static struct kobj_attribute rtl8168_phy_status =
__ATTR(phy_status, S_IRUGO | S_IWUSR, rtl8168_phy_status_show, NULL);
static struct kobj_attribute rtl8168_linkup_time =
__ATTR(linkup_time, S_IRUGO | S_IWUSR, rtl8168_linkup_time_show, NULL);
static struct kobj_attribute rtl8168_mac_addr =
__ATTR(mac_addr, S_IRUGO | S_IWUSR, rtl8168_mac_addr_show, NULL);

static struct attribute *attrs[] = {
	&rtl8168_link_recovery.attr,
#ifdef ENABLE_WOL
	&rtl8168_wol.attr,
#endif
	&rtl8168_pga.attr,
	&rtl8168_tapbin.attr,
	&rtl8168_snr.attr,
	&rtl8168_adc.attr,
	&rtl8168_phy_status.attr,
	&rtl8168_linkup_time.attr,
	&rtl8168_mac_addr.attr,
	NULL,   /* need to NULL terminate the list of attributes */
};

static struct attribute_group eth_attr_group = {
	.attrs = attrs,
};

#ifdef CONFIG_PM
static struct task_struct *link_tsk;
static wait_queue_head_t wait;
static struct completion comp;

static int __rtl8168_link_recovery(void *arg)
{
	struct rtl8168_private *tp = (struct rtl8168_private*)arg;
	u32 ioaddr = tp->base_addr;
	u32 phyStatus = 0;
	u32 lockMainUC = 0;
	u32 ret = 0;

	do {
		phyStatus = RTL_R8(PHYstatus);
		rtl_writephy(tp, 0x1f, 0x0a46);
		lockMainUC = rtl_readphy(tp, 0x15);
		//eth_info("[ETH][%d] Phy status = 0x%x, lock_main_uc = 0x%04x\n", __LINE__, phyStatus, lockMainUC);

		if(lockMainUC & BIT(1)) {
			eth_info("[ETH][%d] Phy status = 0x%x, lock_main_uc = 0x%04x\n", __LINE__, phyStatus, lockMainUC);
			rtl_writephy(tp, 0x15, lockMainUC & ~BIT(1));
			lockMainUC = rtl_readphy(tp, 0x15);
			rtl_writephy(tp, 0x1f, 0x0000);
			phyStatus = RTL_R8(PHYstatus);
			eth_info("[ETH][%d] Phy status = 0x%x, lock_main_uc = 0x%04x\n", __LINE__, phyStatus, lockMainUC);
			tp->link_recovery_count++;
			break;
		}
		ret = wait_event_interruptible_timeout(wait, (phyStatus & BIT(1)) == 1, 1*HZ);
		rtl_writephy(tp, 0x1f, 0x0000);

		if (signal_pending(current)) {
			eth_err("[ETH]%s:received a SIGKILL signal\n", __func__);
			break;
		}

		if(kthread_should_stop()) {
			eth_err("[ETH] thread stop\n");
			break;
		}
	} while(!(phyStatus & BIT(1)));

	eth_info("[ETH] resume thread end: %s leaved\n", __func__);
	complete_and_exit(&comp, 0);

	return 0;
}


static void rtl8168_net_suspend(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	if (!netif_running(dev)|| !test_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags))
		return;

	netif_device_detach(dev);
	netif_stop_queue(dev);

	rtl_lock_work(tp);
	napi_disable(&tp->napi);
	clear_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
	rtl_unlock_work(tp);
	rtl8168_hw_reset(tp);
	rtl_pll_power_down(tp);
}

//static int rtl8168_suspend(struct platform_device *dev, pm_message_t state) // RTK_patch: export this api
int rtl8168_suspend(struct platform_device *dev, pm_message_t state) // for WOL of the warm standby flow (suspend/resume)
{
	struct net_device *ndev = platform_get_drvdata(dev);
	struct rtl8168_private *tp = netdev_priv(ndev);

	eth_info("%s\n", __func__);

	if(link_tsk && tp->link_recovery_enable) {
		if(!completion_done(&comp)) {
			kthread_stop(link_tsk);
			wait_for_completion(&comp);
		}
		link_tsk = NULL;
	}

	rtl8168_net_suspend(ndev);

	return 0;
}

static void __rtl8168_resume(struct net_device *dev)
{
	struct rtl8168_private *tp = netdev_priv(dev);

	tp->link_start_time = jiffies_to_msecs(jiffies);

	netif_device_attach(dev);

	rtl_pll_power_up(tp);
	rtl_rar_set(tp, tp->dev->dev_addr);

	rtl_lock_work(tp);
	napi_enable(&tp->napi);
	set_bit(RTL_FLAG_TASK_ENABLED, tp->wk.flags);
	rtl_unlock_work(tp);

	rtl_udelay_loop_wait_high(tp, &rtl_phy_status_cond, 100, 20);
	rtl_schedule_task(tp, RTL_FLAG_TASK_RESET_PENDING);
}

//static int rtl8168_resume(struct platform_device *dev) // RTK_patch: export this api
int rtl8168_resume(struct platform_device *dev) // for WOL of the warm standby flow (suspend/resume)
{
	struct net_device *ndev = platform_get_drvdata(dev);
	struct rtl8168_private *tp = netdev_priv(ndev);
	int ret;

	eth_info("%s\n", __func__);

#ifdef CONFIG_CUSTOMER_TV006
	/* Customize LED */
	rtd_outl((BASE_ADDR + CustomLED), 0x000670ca);
#endif
	/* mdc clock frequency increase */
	rtd_outl((0xb80160b0), 0xef080040);

	if (netif_running(ndev))
		__rtl8168_resume(ndev);

#ifdef ENABLE_EEEP
	rtl8168_mac_eeep_patch_disable(tp);
#endif
	rtl8168_phy_int_disable(tp);
	rtl8168_init_phy(ndev, tp);
	rtl8168_phy_int_enable(tp);

	if(tp->link_recovery_enable) {
		init_completion(&comp);
		init_waitqueue_head(&wait);

		link_tsk = kthread_run(__rtl8168_link_recovery, tp, "link_recovery");
		if (IS_ERR(link_tsk)) {
			ret = PTR_ERR(link_tsk);
			link_tsk = NULL;
			goto out;
		}
		eth_info("Create link recovery thread\n");

		return 0;
out:
		eth_err("create link recovery kthread failed\n");
		return ret;
	}

	return 0;
}

#if 0
static __maybe_unused int rtl8168_runtime_suspend(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct rtl8168_private *tp = netdev_priv(ndev);

	if (!tp->TxDescArray)
		return 0;

	rtl_lock_work(tp);
	tp->saved_wolopts = __rtl8168_get_wol(tp);
	__rtl8168_set_wol(tp, WAKE_ANY);
	rtl_unlock_work(tp);

	rtl8168_net_suspend(ndev);

	return 0;
}

static __maybe_unused int rtl8168_runtime_resume(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct rtl8168_private *tp = netdev_priv(ndev);

	if (!tp->TxDescArray)
		return 0;

	rtl_lock_work(tp);
	__rtl8168_set_wol(tp, tp->saved_wolopts);
	tp->saved_wolopts = 0;
	rtl_unlock_work(tp);

	rtl8168_mac_eeep_patch_disable(tp);
	rtl8168_init_phy(ndev, tp);

	__rtl8168_resume(ndev);

	return 0;
}

static __maybe_unused int rtl8168_runtime_idle(struct device *dev)
{
	struct net_device *ndev = dev_get_drvdata(dev);
	struct rtl8168_private *tp = netdev_priv(ndev);

	return tp->TxDescArray ? -EBUSY : 0;
}
#endif

static struct platform_driver rtl8168_driver = {
	.suspend        = rtl8168_suspend,
	.resume         = rtl8168_resume,
	.driver = {
		.name		= MODULENAME,
		.owner		= THIS_MODULE,
	},
};
#endif

#if 0
static void rtl_wol_shutdown_quirk(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;
}

static void rtl_shutdown(struct pci_dev *pdev)
{
	struct net_device *dev = pci_get_drvdata(pdev);
	struct rtl8168_private *tp = netdev_priv(dev);
	/*struct device *d = &pdev->dev; */

	/*pm_runtime_get_sync(d); */

	rtl8168_net_suspend(dev);

	/* Restore original MAC address */
	rtl_rar_set(tp, dev->perm_addr);

	rtl8168_hw_reset(tp);

	if (system_state == SYSTEM_POWER_OFF) {
		if (__rtl8168_get_wol(tp) & WAKE_ANY) {
			rtl_wol_suspend_quirk(tp);
			rtl_wol_shutdown_quirk(tp);
		}
	}

	/*pm_runtime_put_noidle(d); */
}
#endif

static const struct net_device_ops rtl_netdev_ops = {
	.ndo_open		= rtl_open,
	.ndo_stop		= rtl8168_close,
	.ndo_get_stats64	= rtl8168_get_stats64,
	.ndo_start_xmit		= rtl8168_start_xmit,
	.ndo_tx_timeout		= rtl8168_tx_timeout,
	.ndo_validate_addr	= eth_validate_addr,
	.ndo_change_mtu		= rtl8168_change_mtu,
	.ndo_fix_features	= rtl8168_fix_features,
	.ndo_set_features	= rtl8168_set_features,
	.ndo_set_mac_address	= rtl_set_mac_address,
	.ndo_do_ioctl		= rtl8168_ioctl,
	.ndo_set_rx_mode	= rtl_set_rx_mode,
#ifdef CONFIG_NET_POLL_CONTROLLER
	.ndo_poll_controller	= rtl8168_netpoll,
#endif

};

#if 0
/* Cfg9346_Unlock assumed. */
static unsigned rtl_try_msi(struct rtl8168_private *tp,
		unsigned features)
{
	u32 ioaddr = tp->base_addr;
	unsigned msi = 0;
	u8 cfg2;

	cfg2 = RTL_R8(Config2) & ~MSIEnable;
	if (features & RTL_FEATURE_MSI) {
#if 0
		cfg2 |= MSIEnable;
		msi = RTL_FEATURE_MSI;
#endif
	}

	return msi;
}
#endif

DECLARE_RTL_COND(rtl_link_list_ready_cond)
{
	u32 ioaddr = tp->base_addr;

	return RTL_R8(MCU) & LINK_LIST_RDY;
}

DECLARE_RTL_COND(rtl_rxtx_empty_cond)
{
	u32 ioaddr = tp->base_addr;

	return (RTL_R8(MCU) & RXTX_EMPTY) == RXTX_EMPTY;
}

static void rtl_hw_init_8168g(struct rtl8168_private *tp)
{
	u32 ioaddr = tp->base_addr;
#if 0
	u32 data;

	tp->ocp_base = OCP_STD_PHY_BASE;
#endif
	RTL_W32(MISC, RTL_R32(MISC) | RXDV_GATED_EN);

	/* Check TX/RX fifo empty */
	if (!rtl_udelay_loop_wait_high(tp, &rtl_txcfg_empty_cond, 100, 42))
		return;

	if (!rtl_udelay_loop_wait_high(tp, &rtl_rxtx_empty_cond, 100, 42))
		return;

	/* Disable TX/RX */
	RTL_W8(ChipCmd, RTL_R8(ChipCmd) & ~(CmdTxEnb | CmdRxEnb));
	msleep(1);

#if 0
	/* Exit oob */
	RTL_W8(MCU, RTL_R8(MCU) & ~NOW_IS_OOB);

	data = r8168_mac_ocp_read(tp, 0xe8de);
	data &= ~(1 << 14);
	r8168_mac_ocp_write(tp, 0xe8de, data);

	if (!rtl_udelay_loop_wait_high(tp, &rtl_link_list_ready_cond, 100, 42))
		return;

	data = r8168_mac_ocp_read(tp, 0xe8de);
	data |= (1 << 15);
	r8168_mac_ocp_write(tp, 0xe8de, data);

	if (!rtl_udelay_loop_wait_high(tp, &rtl_link_list_ready_cond, 100, 42))
		return;
#endif
}
static void rtl_hw_initialize(struct rtl8168_private *tp)
{
	rtl_hw_init_8168g(tp);
}

static int __init rtl8168_enable(char *cpu)
{
	if(strcmp(cpu, "scpu") == 0 || strcmp(cpu, "SCPU") == 0) {
		eth_init = 1;
	}
	else {
		eth_init = 0;
	}
	return 1;
}
__setup("eth_cpu=", rtl8168_enable);

static int __init rtl8168_set_pga(char *val)
{
	char *ptr;

	pga_val = simple_strtoul(val, &ptr, 16);
	return 1;
}
__setup("pga=", rtl8168_set_pga);

static int __init rtl8168_set_tapbin(char *val)
{
	char *ptr;

	tapbin_val = simple_strtoul(val, &ptr, 16);
	return 1;
}
__setup("tapbin=", rtl8168_set_tapbin);

static int __init rtl8168_snr_debug(char *val)
{
	if(strncmp(val, "1", 1) == 0) {
		snr_debug = RTL8168_SNR_ENABLE;
	}else {
		snr_debug = RTL8168_SNR_DISABLE;
	}
	return 1;
}
__setup("snr_debug=", rtl8168_snr_debug);

static int __init rtl8168_adc_debug(char *val)
{
	if(strncmp(val, "1", 1) == 0) {
		adc_debug = RTL8168_ADC_ENABLE;
	}else {
		adc_debug = RTL8168_ADC_DISABLE;
	}
	return 1;
}
__setup("adc_debug=", rtl8168_adc_debug);

static int rtl_init_one(void)
{
	struct rtl8168_private *tp;
	struct mii_if_info *mii;
	char *env_base;
	unsigned features = 2;
	u32 ioaddr;
	/*int i; */
	int rc = 0;
	const char dev_name[] = "eth0";

	if(eth_init == 0) {
		eth_info("SCPU does not enable rtl8168 driver\n");
		return 1;
	}

	if (netif_msg_drv(&debug)) {
		eth_info("%s Gigabit Ethernet driver %s loaded\n",
				MODULENAME, RTL8168_VERSION);
	}

	ndev = alloc_etherdev(sizeof (*tp));
	if (!ndev) {
		rc = -ENOMEM;
		goto out;
	}

	ndev->netdev_ops = &rtl_netdev_ops;
	ndev->irq = IRQ_GET_KERNEL_IRQ_NUM(IRQ_ETH);
	memset(ndev->name, 0, sizeof(ndev->name));
	strncpy(ndev->name, dev_name, sizeof(ndev->name)-1);
	tp = netdev_priv(ndev);
	tp->dev = ndev;
	tp->msg_enable = netif_msg_init(debug.msg_enable, R8168_MSG_DEFAULT);
	tp->link_recovery_enable = RTL8168_LINK_RECOVERY_ENABLE;
	tp->link_recovery_count = 0;
	tp->ap_wol_enable = RTL8168_WOL_DISABLE;

	mii = &tp->mii;
	mii->dev = ndev;
	mii->mdio_read = rtl_mdio_read;
	mii->mdio_write = rtl_mdio_write;
	mii->phy_id_mask = 0x1f;
	mii->reg_num_mask = 0x1f;
	mii->supports_gmii = !!(features & RTL_FEATURE_GMII);

	tp->cp_cmd = RxChkSum;

	ndev->features |= NETIF_F_HIGHDMA;

	ioaddr = BASE_ADDR;
	tp->base_addr = ioaddr;

	/* Check chip attached to board */
	if (!(rtl8168_check_mac_version(tp, ndev))) {
		eth_err("mac version is incorrect\n");
		goto err_out_msi;
	}

	ndev->dev.coherent_dma_mask = DMA_BIT_MASK(32);
	ndev->dev.dma_mask = &ndev->dev.coherent_dma_mask;
#ifdef CONFIG_ARM64	
	arch_setup_dma_ops(&ndev->dev, 0, 0, NULL, false);
#endif
	if(dma_set_mask(&ndev->dev, DMA_BIT_MASK(32))) {
		eth_err("DMA not supported\n");
	}

	/* Initialize RX config */
	rtl_init_rxcfg(tp);

	/* Disable interrupt */
	rtl_irq_disable(tp);

	/* Check TX/RX FIFO and Disable TX/RX */
	rtl_hw_initialize(tp);

	/* Software reset */
	rtl_hw_reset(tp);

	/* Clear interrupt status */
	rtl_ack_events(tp, 0xffff);

	rtl_init_mdio_ops(tp);
	rtl_init_pll_power_ops(tp);
	/*rtl_init_csi_ops(tp); */

#if 0
	/* For WOL ?? */
	RTL_W8(Cfg9346, Cfg9346_Unlock);
	RTL_W8(Config1, RTL_R8(Config1) | PMEnable);
	RTL_W8(Config5, RTL_R8(Config5) & PMEStatus);

	/*disable magic packet WOL */
	RTL_W8(Config3, RTL_R8(Config3) & ~MagicPacket);
	if ((RTL_R8(Config3) & (LinkUp | MagicPacket)) != 0)
		tp->features |= RTL_FEATURE_WOL;
	if ((RTL_R8(Config5) & (UWF | BWF | MWF)) != 0)
		tp->features |= RTL_FEATURE_WOL;
	tp->features |= rtl_try_msi(tp, features);
	RTL_W8(Cfg9346, Cfg9346_Lock);
#endif

	tp->set_speed = rtl8168_set_speed_xmii;
	tp->get_settings = rtl8168_gset_xmii;
	tp->phy_reset_enable = rtl8168_xmii_reset_enable;
	tp->phy_set_aldps = rtl8168_xmii_set_aldps;
	tp->phy_enhance_performance = rtl8168_xmii_enhance_performance;
	tp->phy_reset_pending = rtl8168_xmii_reset_pending;
	tp->link_ok = rtl8168_xmii_link_ok;
	tp->do_ioctl = rtl_xmii_ioctl;

	mutex_init(&tp->wk.mutex);

#if 1
	/* default MAC address */
	((u16 *) (ndev->dev_addr))[0] = 0x0000;
	((u16 *) (ndev->dev_addr))[1] = 0x0000;
	((u16 *) (ndev->dev_addr))[2] = 0x0000;
	((u16 *) (ndev->dev_addr))[3] = 0x0000;

	/* read MAC address from FLASH */
	env_base = platform_info.ethaddr;

	/*eth_info("MAC address = 0x%s\n",env_base); */
	ndev->dev_addr[0] = (u8) simple_strtoul(env_base, NULL, 16);
	ndev->dev_addr[1] = (u8) simple_strtoul(env_base + 3, NULL, 16);
	ndev->dev_addr[2] = (u8) simple_strtoul(env_base + 6, NULL, 16);
	ndev->dev_addr[3] = (u8) simple_strtoul(env_base + 9, NULL, 16);
	ndev->dev_addr[4] = (u8) simple_strtoul(env_base + 12, NULL, 16);
	ndev->dev_addr[5] = (u8) simple_strtoul(env_base + 15, NULL, 16);
	ndev->dev_addr[6] = (u8) (0x00);
	ndev->dev_addr[7] = (u8) (0x00);
#else
	/* default MAC address */
	RTL_W32(MAC0, 0x33221100);
	RTL_W32(MAC4, 0x00005544);
	{
		int i;
		for (i = 0; i < ETH_ALEN; i++)
			ndev->dev_addr[i] = RTL_R8(MAC0 + i);
	}

#endif
	eth_info("%s: RTL8168 at 0x%08x, "
			"%02x:%02x:%02x:%02x:%02x:%02x, "
			"IRQ %d\n",
			ndev->name,
			tp->base_addr,
			ndev->dev_addr[0], ndev->dev_addr[1],
			ndev->dev_addr[2], ndev->dev_addr[3],
			ndev->dev_addr[4], ndev->dev_addr[5], ndev->irq);

	netdev_set_default_ethtool_ops(ndev, &rtl8168_ethtool_ops);
	ndev->watchdog_timeo = RTL8168_TX_TIMEOUT;

	netif_napi_add(ndev, &tp->napi, rtl8168_poll, R8168_NAPI_WEIGHT);

	/* don't enable SG, IP_CSUM and TSO by default - it might not work
	 * properly for all devices */
	ndev->features |= NETIF_F_RXCSUM |
		NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;

	ndev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
		NETIF_F_RXCSUM | NETIF_F_HW_VLAN_CTAG_TX |
		NETIF_F_HW_VLAN_CTAG_RX;
	ndev->vlan_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_TSO |
		NETIF_F_HIGHDMA;

	ndev->hw_features |= NETIF_F_RXALL;
	ndev->hw_features |= NETIF_F_RXFCS;

	tp->hw_start = rtl_hw_start_8168;
	tp->event_slow = SYSErr | LinkChg | RxOverflow;

	tp->opts1_mask = ~(RxBOVF | RxFOVF);

	init_timer(&tp->timer);
	tp->timer.data = (unsigned long) ndev;
	tp->timer.function = rtl8168_phy_timer; /* call rtl_task  */

	init_timer(&tp->link_check_timer);
	tp->link_check_timer.data = (unsigned long) ndev;
	tp->link_check_timer.function = rtl8168_link_timer;

	rc = register_netdev(ndev);
	if (rc < 0)
		goto err_out_msi;

	/*device_set_wakeup_enable(&pdev->dev, tp->features & RTL_FEATURE_WOL); */

	tp->link_status = RTL8168_LINK_DOWN;
#if NWAY_ENABLE
	tp->autoneg = AUTONEG_ENABLE;
#else
	tp->autoneg = AUTONEG_DISABLE;
#endif

	netif_carrier_off(ndev);

#ifdef CONFIG_PM
	network_devs = platform_device_register_simple((char *)MODULENAME, -1, NULL, 0);

	if (IS_ERR(network_devs)) {
		rc = PTR_ERR(network_devs);
		return rc;
	}

	dev_set_drvdata(&network_devs->dev, ndev);
	platform_driver_register(&rtl8168_driver);

#ifdef CONFIG_CUSTOMER_TV006
	device_enable_async_suspend(&network_devs->dev);
#endif
#endif
	eth_kobj = kobject_create_and_add("etn", NULL);
	if (!eth_kobj) {
		rc = -ENOMEM;
		goto err_kobject_create;
	}

	rc = sysfs_create_group(eth_kobj, &eth_attr_group);
	if (rc != 0) {
		goto err_sysfs_create_group;
	}

out:
	return rc;

err_sysfs_create_group:
	kobject_put(eth_kobj);
err_kobject_create:
err_out_msi:
	netif_napi_del(&tp->napi);
	free_netdev(ndev);
	/*rtl_disable_msi(pdev, tp); */
	goto out;
}

static void __exit rtl_remove_one(void)
{
	struct rtl8168_private *tp = netdev_priv(ndev);

	cancel_work_sync(&tp->wk.work);

	netif_napi_del(&tp->napi);

	unregister_netdev(ndev);

	/* restore original MAC address */
	rtl_rar_set(tp, ndev->perm_addr);

	free_netdev(ndev);

#ifdef CONFIG_PM
	platform_driver_unregister(&rtl8168_driver);
	platform_device_unregister(network_devs);
#endif
}

module_init(rtl_init_one);
module_exit(rtl_remove_one);
