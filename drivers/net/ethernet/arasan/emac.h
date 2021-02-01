#ifndef __ARASAN_EMAC_H
#define __ARASAN_EMAC_H

#include <linux/if_ether.h>
#include <linux/mii.h>
#include <linux/netdevice.h>
#include <linux/phy.h>
#include <linux/skbuff.h>
#include <linux/spinlock.h>
#include <linux/timer.h>
#include <linux/types.h>

/*
 * EMAC DMA register set
 */
#define DMA_CONF		0x0000
#define DMA_CTRL		0x0004
#define DMA_STAT_INTR		0x0008
#define DMA_INTR_ENABLE		0x000c
#define DMA_TX_AUTO_POLL_CNTR	0x0010
#define DMA_TX_POLL_DEMAND	0x0014
#define DMA_RX_POLL_DEMAND	0x0018
#define DMA_TX_BASE_ADDR	0x001c
#define DMA_RX_BASE_ADDR	0x0020
#define DMA_MISSED_FRAME_CNTR	0x0024
#define DMA_STOP_FLUSH_CNTR	0x0028
#define DMA_RX_INTR_MITIGATION_CTRL	0x002c
#define DMA_CURR_TX_DESC	0x0030
#define DMA_CURR_TX_BUFF	0x0034
#define DMA_CURR_RX_DESC	0x0038
#define DMA_CURR_RX_BUFF	0x003c

/*
 * EMAC MAC register set
 */
#define MAC_GLOBAL_CTRL		0x0100
#define MAC_TX_CTRL		0x0104
#define MAC_RX_CTRL		0x0108
#define MAC_MAX_FRAME_SIZE	0x010c
#define MAC_TX_JABBER_SIZE	0x0110
#define MAC_RX_JABBER_SIZE	0x0114
#define MAC_ADDR_CTRL		0x0118
/* RESERVED			0x011c */
#define MAC_ADDR1_HI		0x0120
#define MAC_ADDR1_ME		0x0124
#define MAC_ADDR1_LO		0x0128
#define MAC_ADDR2_HI		0x012c
#define MAC_ADDR2_ME		0x0130
#define MAC_ADDR2_LO		0x0134
#define MAC_ADDR3_HI		0x0138
#define MAC_ADDR3_ME		0x013c
#define MAC_ADDR3_LO		0x0140
#define MAC_ADDR4_HI		0x0144
#define MAC_ADDR4_ME		0x0148
#define MAC_ADDR4_LO		0x014c
#define MAC_MULTICAST_HASH1	0x0150
#define MAC_MULTICAST_HASH2	0x0154
#define MAC_MULTICAST_HASH3	0x0158
#define MAC_MULTICAST_HASH4	0x015c
#define MAC_FC_CTRL		0x0160
#define MAC_FC_PAUSE_FRAME_GEN	0x0164
#define MAC_FC_SA_HI		0x0168
#define MAC_FC_SA_ME		0x016c
#define MAC_FC_SA_LO		0x0170
#define MAC_FC_DA_HI		0x0174
#define MAC_FC_DA_ME		0x0178
#define MAC_FC_DA_LO		0x017c
#define MAC_FC_PAUSE_TIME	0x0180
/* RESERVED			0x0184 */
/* RESERVED			0x0188 */
/* RESERVED			0x018c */
/* RESERVED			0x0190 */
/* RESERVED			0x0194 */
/* RESERVED			0x0198 */
/* RESERVED			0x019c */
#define MAC_MDIO_CTRL		0x01a0
#define MAC_MDIO_DATA		0x01a4
#define MAC_RX_STATS_CTRL	0x01a8
#define MAC_RX_STATS_DATA_HI	0x01ac
#define MAC_RX_STATS_DATA_LO	0x01b0
#define MAC_TX_STATS_CTRL	0x01b4
#define MAC_TX_STATS_DATA_HI	0x01b8
#define MAC_TX_STATS_DATA_LO	0x01bc
#define MAC_TX_FIFO_ALMOST_FULL	0x01c0
#define MAC_TX_START_THRESHOLD	0x01c4
#define MAC_RX_START_THRESHOLD	0x01c8
/* RESERVED			0x01cc */
/* RESERVED			0x01d0 */
/* RESERVED			0x01d4 */
/* RESERVED			0x01d8 */
/* RESERVED			0x01dc */
#define MAC_STAT_INTR		0x01e0
#define MAC_INTR_ENABLE		0x01e4

/*
 * Rx statistics counters
 */
#define RX_FRAMES_OK	0
#define RX_FRAMES_TOTAL	1
#define RX_FRAMES_ERR	4
#define RX_OCTETS_OK	5
/* 21 more counters */

/*
 * Tx statistics counters
 */
#define TX_FRAMES_OK	0
#define TX_FRAMES_TOTAL	1
#define TX_OCTETS_OK	2
#define TX_FRAMES_ERR	3
/* 8 more counters */

#pragma pack(push, 1)

/*
 * Rx descriptor format
 */
struct emac_rxd {
	/* RDES0 */
	unsigned long   length: 14;	/* frame/packet length */
	unsigned long   status: 15;	/* application status */
	unsigned long   last:    1;	/* last descriptor */
	unsigned long   first:   1;	/* first descriptor */
	unsigned long   own:     1;	/* owned by DMA controller */
	/* RDES1 */
	unsigned long   size1:  12;	/* buffer 1 size */
	unsigned long   size2:  12;	/* buffer 2 size */
	unsigned long   _res_1:  1;	/* reserved */
	unsigned long   chain:   1;	/* 2nd address chained */
	unsigned long   end:     1;	/* end of ring */
	unsigned long   _res_2:  5;	/* reserved */
	/* RDES2 */
	dma_addr_t      addr1;		/* buffer 1 address */
	/* RDES3 */
	struct sk_buff *addr2;		/* buffer 2 address */
};

/*
 * Tx descriptor format
 */
struct emac_txd {
	/* TDES0 */
	unsigned long   status: 31;	/* Tx status */
	unsigned long   own:     1;	/* owned by DMA controller */
	/* TDES1 */
	unsigned long   size1:  12;	/* buffer 1 size */
	unsigned long   size2:  12;	/* buffer 2 size */
	unsigned long   eop:     1;	/* force EOP error */
	unsigned long   chain:   1;	/* addr2 chained */
	unsigned long   end:     1;	/* end of ring */
	unsigned long   no_pad:  1;	/* disable padding */
	unsigned long   no_fcs:  1;	/* disable FCS */
	unsigned long   first:   1;	/* first segment */
	unsigned long   last:    1;	/* last segment */
	unsigned long   intr:    1;	/* interrupt on completion */
	/* TDES2 */
	dma_addr_t      addr1;		/* buffer 1 address */
	/* TDES3 */
	struct sk_buff *addr2;		/* buffer 2 address */
};

#pragma pack(pop)

struct emac_priv {
	/* from resources */
	phys_addr_t regs_phys;
	size_t regs_size;
	phys_addr_t desc_phys;
	size_t desc_size;
	int mac_irq;

	/* from platform data */
	unsigned char mac_addr[ETH_ALEN];
	phy_interface_t phy_mode;

	spinlock_t lock;

	void __iomem *regs_virt;
	void __iomem *desc_virt;

	phys_addr_t txd_phys;
	phys_addr_t rxd_phys;

	struct emac_txd __iomem *txd_virt;
	size_t txd_size;
	struct emac_rxd __iomem *rxd_virt;
	size_t rxd_size;

	unsigned long txd_head;
	unsigned long txd_tail;
	size_t txd_used;
	unsigned long rxd_next;

	struct napi_struct napi;

	struct platform_device *pdev;

	struct mii_bus *mii_bus;

	struct phy_device *phy_dev;

	int phy_irq[PHY_MAX_ADDR];

	int link;
	int speed;
	int duplex;

	struct net_device_stats stats;
};

#endif

