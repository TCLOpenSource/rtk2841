#include <linux/module.h>

#include <linux/kernel.h>

#include <linux/crc32.h>
#include <linux/etherdevice.h>
#include <linux/ethtool.h>
#include <linux/if_ether.h>
#include <linux/if_vlan.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/mii.h>
#include <linux/netdevice.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_mdio.h>
#include <linux/of_net.h>
#include <linux/of_address.h>
#include <linux/phy.h>
#include <linux/platform_device.h>
#include <linux/skbuff.h>
#include <linux/spinlock.h>
#include <linux/timer.h>

#include <asm/dma-mapping.h>
#include <asm/io.h>
#include <asm-generic/sizes.h>

#include "emac.h"

#define FRAME_LEN	VLAN_ETH_FRAME_LEN

#define TX_RING_SIZE	64
#define RX_RING_SIZE	192

#define TX_DESC_BYTE	(sizeof(struct emac_txd) * TX_RING_SIZE)
#define RX_DESC_BYTE	(sizeof(struct emac_rxd) * RX_RING_SIZE)

/*
 * PHY support
 */

static void emac_phy_notifier(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	struct phy_device *phy_dev = priv->phy_dev;
	unsigned long ctrl = 0;
	unsigned long flags;

	BUG_ON(!phy_dev);

	spin_lock_irqsave(&priv->lock, flags);

	if (!phy_dev->link) {
		netdev_info(dev, "physical link lost\n");

		netif_carrier_off(dev);
		netif_stop_queue(dev);
	} else {
		if (phy_dev->speed == SPEED_100)
			ctrl |= 0x01;
		if (phy_dev->duplex == DUPLEX_FULL)
			ctrl |= 0x04;

		writel_relaxed(ctrl, priv->regs_virt + MAC_GLOBAL_CTRL);

		if (!priv->link) {
			netdev_info(dev, "physical link established\n");

			netif_carrier_on(dev);
			netif_wake_queue(dev);
		}

		if (phy_dev->speed != priv->speed ||
		    phy_dev->duplex != priv->duplex) {
			netdev_info(dev, "link mode: %dMbps/%cDX\n",
			            phy_dev->speed == SPEED_100 ? 100 : 10,
			            phy_dev->duplex == DUPLEX_FULL ? 'F' : 'H');
		}
	}

	priv->link = phy_dev->link;
	priv->speed = phy_dev->speed;
	priv->duplex = phy_dev->duplex;

	spin_unlock_irqrestore(&priv->lock, flags);
}

/*
 * MDIO bus support
 */

static int emac_mii_bus_read(struct mii_bus *mii, int phy, int reg)
{
	struct net_device *dev = (struct net_device *)mii->priv;
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	unsigned long val;
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	/* trigger MDIO reading */
	writel_relaxed((phy & 0x1f) | ((reg & 0x1f) << 5) | 0x8400,
	               priv->regs_virt + MAC_MDIO_CTRL);
	/* busy-wait for completion */
	while (readl_relaxed(priv->regs_virt + MAC_MDIO_CTRL) & 0x8000);
	/* return read value */
	val = readl_relaxed(priv->regs_virt + MAC_MDIO_DATA);

	spin_unlock_irqrestore(&priv->lock, flags);

	return (int)(val & 0xffff);
}

static int emac_mii_bus_write(struct mii_bus *mii, int phy, int reg, u16 val)
{
	struct net_device *dev = (struct net_device *)mii->priv;
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	/* store value written */
	writel_relaxed(val & 0xffff, priv->regs_virt + MAC_MDIO_DATA);
	/* trigger MDIO writing */
	writel_relaxed((phy & 0x1f) | ((reg & 0x1f) << 5) | 0x8000,
	               priv->regs_virt + MAC_MDIO_CTRL);
	/* busy-wait for completion */
	while (readl_relaxed(priv->regs_virt + MAC_MDIO_CTRL) & 0x8000);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

static int emac_mii_bus_reset(struct mii_bus *mii)
{
	return 0;
}

static int emac_mdio_probe(struct mii_bus *mii)
{
	struct net_device *dev = (struct net_device *)mii->priv;
	struct emac_priv *priv = netdev_priv(dev);
	int err;

	priv->phy_dev = phy_find_first(mii);
	if (!priv->phy_dev) {
		netdev_err(dev, "failed to find a PHY chip\n");
		return -ENODEV;
	}

	BUG_ON(priv->phy_dev->attached_dev);

	err = phy_connect_direct(dev, priv->phy_dev, emac_phy_notifier,
	                         priv->phy_mode);
	if (err < 0) {
		netdev_err(dev, "failed to phy_connect_direct\n");
		return err;
	}

	priv->phy_dev->supported &= SUPPORTED_10baseT_Half |
	                            SUPPORTED_10baseT_Full |
	                            SUPPORTED_100baseT_Half |
	                            SUPPORTED_100baseT_Full |
	                            SUPPORTED_Autoneg |
	                            SUPPORTED_MII |
	                            SUPPORTED_TP;

	priv->phy_dev->advertising = priv->phy_dev->supported;

	priv->link = 0;
	priv->speed = SPEED_UNKNOWN;
	priv->duplex = DUPLEX_UNKNOWN;

	netdev_info(dev, "PHY attached: %s @ address %d using irq %d\n",
	            priv->phy_dev->drv->name, priv->phy_dev->addr,
	            priv->phy_dev->irq);

	return 0;
}

static void emac_mdio_remove(struct mii_bus *mii)
{
	struct net_device *dev = (struct net_device *)mii->priv;
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);

	phy_disconnect(priv->phy_dev);
	priv->phy_dev = NULL;
}

/*
 * MAC support
 */

static unsigned long emac_get_rx_stats(struct net_device *dev, int counter)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);

	/* trigger counter reading */
	writel_relaxed(counter | 0x8000, priv->regs_virt + MAC_RX_STATS_CTRL);
	/* busy-wait for completion */
	while (readl_relaxed(priv->regs_virt + MAC_RX_STATS_CTRL) & 0x8000);
	/* return read value */

	return readl_relaxed(priv->regs_virt + MAC_RX_STATS_DATA_HI) << 16 |
	       readl_relaxed(priv->regs_virt + MAC_RX_STATS_DATA_LO);
}

static unsigned long emac_get_tx_stats(struct net_device *dev, int counter)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);

	/* trigger counter reading */
	writel_relaxed(counter | 0x8000, priv->regs_virt + MAC_TX_STATS_CTRL);
	/* busy-wait for completion */
	while (readl_relaxed(priv->regs_virt + MAC_TX_STATS_CTRL) & 0x8000);
	/* return read value */

	return readl_relaxed(priv->regs_virt + MAC_TX_STATS_DATA_HI) << 16 |
	       readl_relaxed(priv->regs_virt + MAC_TX_STATS_DATA_LO);
}

static void emac_set_rx_promisc(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	writel_relaxed(0x0100, priv->regs_virt + MAC_ADDR_CTRL);
}

static void emac_set_rx_allmulti(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	writel_relaxed(~0x00, priv->regs_virt + MAC_MULTICAST_HASH1);
	writel_relaxed(~0x00, priv->regs_virt + MAC_MULTICAST_HASH2);
	writel_relaxed(~0x00, priv->regs_virt + MAC_MULTICAST_HASH3);
	writel_relaxed(~0x00, priv->regs_virt + MAC_MULTICAST_HASH4);
}

static void emac_set_rx_mc_list(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	struct netdev_hw_addr *ha;
	unsigned long hash[4] = { 0, };
	u32 crc;

	netdev_for_each_mc_addr(ha, dev)
	{
		crc = ether_crc(ETH_ALEN, ha->addr);
		crc = (crc >> 26) & 0x3f;
		hash[crc >> 4] |= 1 << (crc & 0x0f);
	}

	writel_relaxed(hash[0], priv->regs_virt + MAC_MULTICAST_HASH1);
	writel_relaxed(hash[1], priv->regs_virt + MAC_MULTICAST_HASH2);
	writel_relaxed(hash[2], priv->regs_virt + MAC_MULTICAST_HASH3);
	writel_relaxed(hash[3], priv->regs_virt + MAC_MULTICAST_HASH4);
}

static void emac_set_rx_uc_addr(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);

	writel_relaxed((unsigned long)*(unsigned short *)&dev->dev_addr[0],
	               priv->regs_virt + MAC_ADDR1_HI);
	writel_relaxed((unsigned long)*(unsigned short *)&dev->dev_addr[2],
	               priv->regs_virt + MAC_ADDR1_ME);
	writel_relaxed((unsigned long)*(unsigned short *)&dev->dev_addr[4],
	               priv->regs_virt + MAC_ADDR1_LO);

	writel_relaxed(0x01, priv->regs_virt + MAC_ADDR_CTRL);
}

static void emac_set_rx_uc_list(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	struct netdev_hw_addr *ha;
	int i = 1;

	netdev_for_each_uc_addr(ha, dev)
	{
		writel_relaxed((unsigned long)*(unsigned short *)&ha->addr[0],
		               priv->regs_virt + MAC_ADDR1_HI + i * 0x0c);
		writel_relaxed((unsigned long)*(unsigned short *)&ha->addr[2],
		               priv->regs_virt + MAC_ADDR1_ME + i * 0x0c);
		writel_relaxed((unsigned long)*(unsigned short *)&ha->addr[4],
		               priv->regs_virt + MAC_ADDR1_LO + i * 0x0c);
		++i;
	}

	writel_relaxed((1 << i) - 1, priv->regs_virt + MAC_ADDR_CTRL);
}

static int emac_mac_open(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	/* stop both Rx/Tx MAC */
	writel_relaxed(0x00, priv->regs_virt + MAC_RX_CTRL);
	writel_relaxed(0x00, priv->regs_virt + MAC_TX_CTRL);
	
	/* reset MAC counters */
	writel_relaxed(0x18, priv->regs_virt + MAC_GLOBAL_CTRL);

	mdelay(1);

	/* clear reset and initially setup 10Mbps/HDX */
	writel_relaxed(0x00, priv->regs_virt + MAC_GLOBAL_CTRL);

	/* ?MAGIC VALUE? -- Tx FIFO almost-full threshold */
	writel_relaxed(0x01f8, priv->regs_virt + MAC_TX_FIFO_ALMOST_FULL);

	/* setup MAC Rx/Tx start threshold */
	writel_relaxed(ETH_ZLEN, priv->regs_virt + MAC_RX_START_THRESHOLD);
	writel_relaxed(FRAME_LEN, priv->regs_virt + MAC_TX_START_THRESHOLD);

	/* start both Rx/Tx MAC in proper mode */
	writel_relaxed(0x4d, priv->regs_virt + MAC_RX_CTRL);
	writel_relaxed(0x09, priv->regs_virt + MAC_TX_CTRL);

	/* stop both Rx/Tx DMA */
	writel_relaxed(0x00, priv->regs_virt + DMA_CTRL);

	/* soft-reset DMA controller */
	writel_relaxed(0x00000001, priv->regs_virt + DMA_CONF);

	mdelay(1);

	/* clear reset and setup DMA burst mode */
	writel_relaxed(0x00020020, priv->regs_virt + DMA_CONF);

	mdelay(1);

	/* clear ring pointers to force update */
	writel_relaxed(0x00, priv->regs_virt + DMA_RX_BASE_ADDR);
	writel_relaxed(0x00, priv->regs_virt + DMA_TX_BASE_ADDR);

	/* setup DMA Rx/Tx descriptor ring pointers */
	writel_relaxed(priv->rxd_phys, priv->regs_virt + DMA_RX_BASE_ADDR);
	writel_relaxed(priv->txd_phys, priv->regs_virt + DMA_TX_BASE_ADDR);

	/* do not use auto-poll feature */
	writel_relaxed(0x00, priv->regs_virt + DMA_TX_AUTO_POLL_CNTR);

	/* clear all interrupts */
	writel_relaxed(0xff, priv->regs_virt + DMA_STAT_INTR);

	/* enable MAC interrupt(s) -- currently nothing */
	writel_relaxed(0x00, priv->regs_virt + MAC_INTR_ENABLE);
	/* enable DMA interrupt(s) -- only Rx/Tx done INTRs */
	writel_relaxed(0x11, priv->regs_virt + DMA_INTR_ENABLE);

	/* start both Rx/Tx DMA */
	writel_relaxed(0x03, priv->regs_virt + DMA_CTRL);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

static int emac_mac_stop(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	/* stop both Rx/Tx DMA */
	writel_relaxed(0x00, priv->regs_virt + DMA_CTRL);

	/* stop both Rx/Tx MAC */
	writel_relaxed(0x00, priv->regs_virt + MAC_RX_CTRL);
	writel_relaxed(0x00, priv->regs_virt + MAC_TX_CTRL);
	
	/* disable DMA interrupts */
	writel_relaxed(0x00, priv->regs_virt + DMA_INTR_ENABLE);
	/* disable MAC interrupts */
	writel_relaxed(0x00, priv->regs_virt + MAC_INTR_ENABLE);

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

/*
 * network driver support
 */

static int emac_handle_tx(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	int tx = 0;

	while (priv->txd_used) {
		if (priv->txd_virt[priv->txd_tail].own)
			break;

		dma_unmap_single(&priv->pdev->dev,
		                 priv->txd_virt[priv->txd_tail].addr1,
		                 priv->txd_virt[priv->txd_tail].size1,
		                 DMA_TO_DEVICE);

		dev_kfree_skb_any(priv->txd_virt[priv->txd_tail].addr2);

		priv->txd_tail = (priv->txd_tail + 1) % priv->txd_size;
		priv->txd_used--;

		++tx;
	}

	return tx;
}

static int emac_handle_rx(struct net_device *dev, int budget)
{
	struct emac_priv *priv = netdev_priv(dev);
	struct sk_buff *skb;
	dma_addr_t dma;
	int rx = 0;

	while (rx < budget && !priv->rxd_virt[priv->rxd_next].own) {
		dma_unmap_single(&priv->pdev->dev,
		                 priv->rxd_virt[priv->rxd_next].addr1,
		                 priv->rxd_virt[priv->rxd_next].size1,
		                 DMA_FROM_DEVICE);

		skb = priv->rxd_virt[priv->rxd_next].addr2;
		skb_put(skb, priv->rxd_virt[priv->rxd_next].length);
		skb->protocol = eth_type_trans(skb, dev);

		netif_receive_skb(skb);

		skb = dev_alloc_skb(FRAME_LEN + NET_IP_ALIGN);
		skb->dev = dev;
		skb_reserve(skb, NET_IP_ALIGN);

		dma = dma_map_single(&priv->pdev->dev, skb->data, FRAME_LEN,
		                     DMA_FROM_DEVICE);

		priv->rxd_virt[priv->rxd_next].size1 = FRAME_LEN;
		priv->rxd_virt[priv->rxd_next].size2 = 0;
		priv->rxd_virt[priv->rxd_next].addr1 = dma;
		priv->rxd_virt[priv->rxd_next].addr2 = skb;

		priv->rxd_virt[priv->rxd_next].own = 1;
		
		priv->rxd_next = (priv->rxd_next + 1) % priv->rxd_size;

		++rx;
	}

	return rx;
}

static int emac_poll(struct napi_struct *napi, int budget)
{
	struct net_device *dev = napi->dev;
	struct emac_priv *priv = netdev_priv(dev);
	int rx_done;

	rx_done = emac_handle_rx(dev, budget);
	if (rx_done < budget) {
		napi_complete(napi);
		writel_relaxed(0x11, priv->regs_virt + DMA_INTR_ENABLE);
	}

	return rx_done;
}

static irqreturn_t emac_isr(int irq, void *dev_id)
{
	struct net_device *dev = (struct net_device *)dev_id;
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	unsigned long status;
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	status = readl_relaxed(priv->regs_virt + DMA_STAT_INTR);
	writel_relaxed(status, priv->regs_virt + DMA_STAT_INTR);

	if (status & 0x01)
		emac_handle_tx(dev);
	if (status & 0x10) {
		writel_relaxed(0x01, priv->regs_virt + DMA_INTR_ENABLE);
		napi_schedule(&priv->napi);
	}

	spin_unlock_irqrestore(&priv->lock, flags);

	return IRQ_HANDLED;
}

#ifdef	CONFIG_NET_POLL_CONTROLLER

static void emac_poll_controller(struct net_device *dev)
{
	unsigned long flags;

	local_irq_save(flags);
	emac_isr(dev->irq, dev);
	local_irq_restore(flags);
}

#endif	/* CONFIG_NET_POLL_CONTROLLER */

static int emac_alloc_tx(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	int i;

	memset(priv->txd_virt, 0, sizeof(struct emac_txd) * priv->txd_size);

	for (i = 0; i < priv->txd_size; ++i) {
		/* currently nothing */
	}

	priv->txd_virt[priv->txd_size - 1].end = 1;

	priv->txd_tail = priv->txd_head;
	priv->txd_used = 0;

	return 0;
}

static int emac_free_tx(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	int i;

	for (i = 0; i < priv->txd_size; ++i) {
		if(!priv->txd_virt[i].own)
			continue;

		priv->txd_virt[i].own = 0;

		dma_unmap_single(&priv->pdev->dev, priv->txd_virt[i].addr1,
		                 priv->txd_virt[i].size1, DMA_TO_DEVICE);
		kfree_skb(priv->txd_virt[i].addr2);
	}

	return 0;
}

static int emac_alloc_rx(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	struct sk_buff *skb;
	dma_addr_t dma;
	int i;

	memset(priv->rxd_virt, 0, sizeof(struct emac_rxd) * priv->rxd_size);

	for (i = 0; i < priv->rxd_size; ++i) {
		skb = alloc_skb(FRAME_LEN + NET_IP_ALIGN, GFP_KERNEL);
		skb->dev = dev;
		skb_reserve(skb, NET_IP_ALIGN);

		dma = dma_map_single(&priv->pdev->dev, skb->data, FRAME_LEN,
		                     DMA_FROM_DEVICE);

		priv->rxd_virt[i].size1 = FRAME_LEN;
		priv->rxd_virt[i].size2 = 0;
		priv->rxd_virt[i].addr1 = dma;
		priv->rxd_virt[i].addr2 = skb;

		priv->rxd_virt[i].own = 1;
	}

	priv->rxd_virt[priv->rxd_size - 1].end = 1;

	return 0;
}

static int emac_free_rx(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	int i;

	for (i = 0; i < priv->rxd_size; ++i) {
		priv->rxd_virt[i].own = 0;

		dma_unmap_single(&priv->pdev->dev, priv->rxd_virt[i].addr1,
		                 priv->rxd_virt[i].size1, DMA_FROM_DEVICE);
		kfree_skb(priv->rxd_virt[i].addr2);
	}

	return 0;
}

static int emac_init(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	int err;

	/*
	 * remap registers
	 */

	if (!(priv->regs_virt = ioremap(dev->base_addr, SZ_1K))) {
		netdev_err(dev, "failed to ioremap\n");
		err = -ENXIO;
		goto _quit_0;
	}

	priv->desc_size = TX_DESC_BYTE + RX_DESC_BYTE;
	priv->desc_virt = dma_alloc_coherent(&priv->pdev->dev, priv->desc_size,
	                                     &priv->desc_phys, GFP_DMA32);
	if(!priv->desc_virt) {
		netdev_err(dev, "failed to dma_alloc_coherent\n");
		err = -ENOMEM;
		goto _quit_1;
	}

	priv->txd_virt = priv->desc_virt;
	priv->rxd_virt = priv->desc_virt + TX_DESC_BYTE;

	priv->txd_phys = priv->desc_phys;
	priv->rxd_phys = priv->desc_phys + TX_DESC_BYTE;

	priv->txd_size = TX_RING_SIZE;
	priv->rxd_size = RX_RING_SIZE;

	/*
	 * init driver data
	 */

	if (is_valid_ether_addr(priv->mac_addr))
		memcpy(dev->dev_addr, priv->mac_addr, ETH_ALEN);
	else
		random_ether_addr(dev->dev_addr);

	/*
	 * init internal data
	 */

	spin_lock_init(&priv->lock);

	if (!(priv->mii_bus = mdiobus_alloc())) {
		netdev_err(dev, "failed to mdiobus_alloc\n");
		err = -ENOMEM;
		goto _quit_2;
	}

	priv->mii_bus->priv = dev;
	priv->mii_bus->read = emac_mii_bus_read;
	priv->mii_bus->write = emac_mii_bus_write;
	priv->mii_bus->reset = emac_mii_bus_reset;
	priv->mii_bus->name = "emac mdc/mdio bus";
	priv->mii_bus->parent = dev->dev.parent;

	strcpy(priv->mii_bus->id, "emac-mii");
	priv->mii_bus->irq = priv->phy_irq;
	
	err = of_mdiobus_register(priv->mii_bus, priv->pdev->dev.of_node);
	if (err < 0) {
		netdev_err(dev, "failed to of_mdiobus_register\n");
		goto _quit_3;
	}

	if ((err = emac_mdio_probe(priv->mii_bus)) < 0)
		goto _quit_4;

	return 0;

_quit_4:
	mdiobus_unregister(priv->mii_bus);
_quit_3:
	mdiobus_free(priv->mii_bus);
_quit_2:
	dma_free_coherent(&priv->pdev->dev, priv->desc_size, priv->desc_virt,
	                  priv->desc_phys);
_quit_1:
	iounmap(priv->regs_virt);
_quit_0:
	return err;
}

static int emac_open(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	int err;

	memset(&priv->stats, 0, sizeof(struct net_device_stats));

	/*
	 * Tx/Rx descriptors(at least, the own bits of the first descriptors)
	 * should be cleared before calling _mac_init, because the DMA starts
	 * descriptor-lookup immediately on enabling DMA even when the auto-
	 * polling is disabled -- possible HW bug?
	 */
	memset(priv->desc_virt, 0, priv->desc_size);

	priv->txd_head = 0;
	priv->txd_tail = 0;
	priv->txd_used = 0;
	priv->rxd_next = 0;

	if ((err = emac_alloc_tx(dev)) < 0)
		goto _quit_0;
	if ((err = emac_alloc_rx(dev)) < 0)
		goto _quit_1;

	napi_enable(&priv->napi);

	if ((err = emac_mac_open(dev)) < 0)
		goto _quit_2;

	phy_start(priv->phy_dev);

	if ((err = request_irq(dev->irq, emac_isr, 0, "emac", dev)) < 0) {
		netdev_err(dev, "failed to request_irq\n");
		goto _quit_3;
	}

	netif_start_queue(dev);

	return 0;

_quit_3:
	emac_mac_stop(dev);
_quit_2:
	emac_free_rx(dev);
_quit_1:
	emac_free_tx(dev);
_quit_0:
	return err;
}

static int emac_stop(struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);

	netif_stop_queue(dev);

	free_irq(dev->irq, dev);

	phy_stop(priv->phy_dev);

	emac_mac_stop(dev);

	napi_disable(&priv->napi);

	emac_free_rx(dev);
	emac_free_tx(dev);

	return 0;
}

static netdev_tx_t emac_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	dma_addr_t dma;
	unsigned long flags;

	if (priv->txd_used == priv->txd_size)
		return NETDEV_TX_BUSY;

	spin_lock_irqsave(&priv->lock, flags);

	dma = dma_map_single(&priv->pdev->dev, skb->data, skb->len,
	                     DMA_TO_DEVICE);

	priv->txd_virt[priv->txd_head].first = 1;
	priv->txd_virt[priv->txd_head].last  = 1;
	priv->txd_virt[priv->txd_head].intr  = 1;
	priv->txd_virt[priv->txd_head].size1 = skb->len;
	priv->txd_virt[priv->txd_head].size2 = 0;
	priv->txd_virt[priv->txd_head].addr1 = dma;
	priv->txd_virt[priv->txd_head].addr2 = skb;

	wmb();

	priv->txd_virt[priv->txd_head].own = 1;

	writel_relaxed(0x01, priv->regs_virt + DMA_TX_POLL_DEMAND);

	priv->txd_head = (priv->txd_head + 1) % priv->txd_size;
	priv->txd_used++;

	spin_unlock_irqrestore(&priv->lock, flags);

	return NETDEV_TX_OK;
}

static void emac_set_rx_mode(struct net_device *dev)
{
	/* primary unicast address */
	emac_set_rx_uc_addr(dev);
	
	if (dev->flags & IFF_PROMISC || netdev_uc_count(dev) > 3)
		emac_set_rx_promisc(dev);
	else {
		/* secondary unicast addresses */
		emac_set_rx_uc_list(dev);

		if (dev->flags & IFF_ALLMULTI)
			emac_set_rx_allmulti(dev);
		else
			emac_set_rx_mc_list(dev);
	}
}

static int emac_do_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	return phy_mii_ioctl(priv->phy_dev, ifr, cmd);
}

static void emac_tx_timeout(struct net_device *dev)
{
}

static struct net_device_stats *emac_get_stats(struct net_device *dev)
{
	struct emac_priv *priv = netdev_priv(dev);
	unsigned long flags;

	spin_lock_irqsave(&priv->lock, flags);

	priv->stats.rx_packets = emac_get_rx_stats(dev, RX_FRAMES_OK);
	priv->stats.tx_packets = emac_get_tx_stats(dev, TX_FRAMES_OK);
	priv->stats.rx_bytes   = emac_get_rx_stats(dev, RX_OCTETS_OK);
	priv->stats.tx_bytes   = emac_get_tx_stats(dev, TX_OCTETS_OK);
	priv->stats.tx_errors  = emac_get_tx_stats(dev, TX_FRAMES_ERR);
	priv->stats.rx_errors  = emac_get_rx_stats(dev, RX_FRAMES_ERR);
	priv->stats.tx_dropped = emac_get_tx_stats(dev, TX_FRAMES_TOTAL) -
	                         priv->stats.tx_packets - priv->stats.tx_errors;
	priv->stats.rx_dropped = emac_get_rx_stats(dev, RX_FRAMES_TOTAL) -
	                         priv->stats.rx_packets - priv->stats.rx_errors;

	spin_unlock_irqrestore(&priv->lock, flags);

	return &priv->stats;
}

static struct net_device_ops const emac_ndo = {
	.ndo_init		= emac_init,
	.ndo_open		= emac_open,
	.ndo_stop		= emac_stop,
	.ndo_start_xmit		= emac_start_xmit,
	.ndo_set_rx_mode	= emac_set_rx_mode,
	.ndo_set_mac_address	= eth_mac_addr,
	.ndo_validate_addr	= eth_validate_addr,
	.ndo_do_ioctl		= emac_do_ioctl,
	.ndo_tx_timeout		= emac_tx_timeout,
	.ndo_get_stats		= emac_get_stats,
#ifdef	CONFIG_NET_POLL_CONTROLLER
	.ndo_poll_controller	= emac_poll_controller,
#endif	/* CONFIG_NET_POLL_CONTROLLER */
};

static int emac_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	return phy_ethtool_gset(priv->phy_dev, cmd);
}

static int emac_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
	struct emac_priv *priv = (struct emac_priv *)netdev_priv(dev);
	return phy_ethtool_sset(priv->phy_dev, cmd);
}

static void emac_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct emac_priv *priv = netdev_priv(dev);
	if (priv->phy_dev->drv->get_wol)
		priv->phy_dev->drv->get_wol(priv->phy_dev, wol);
}

static int emac_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
	struct emac_priv *priv = netdev_priv(dev);
	if (priv->phy_dev->drv->set_wol)
		return priv->phy_dev->drv->set_wol(priv->phy_dev, wol);
	return -ENOTSUPP;
}

static struct ethtool_ops const emac_eto = {
	.get_settings	= emac_get_settings,
	.set_settings	= emac_set_settings,
	.get_wol	= emac_get_wol,
	.set_wol	= emac_set_wol,
};

/*
 * platform driver support
 */

static int emac_probe(struct platform_device *pdev)
{
	struct net_device *dev;
	struct emac_priv *priv;
	struct device_node *dev_node = pdev->dev.of_node;
	struct resource *res;
	int irq;
	char const *mac_addr;
	phy_interface_t phy_mode;
	int i;
	int err;

	if (!(dev = alloc_etherdev(sizeof(struct emac_priv)))) {
		dev_err(&pdev->dev, "failed to alloc_etherdev\n");
		err = -ENOMEM;
		goto _quit_0;
	}

	SET_NETDEV_DEV(dev, &pdev->dev);
	platform_set_drvdata(pdev, dev);
	priv = (struct emac_priv *)netdev_priv(dev);
	priv->pdev = pdev;

	/*
	 * find and reserve all dedicated resources
	 */

	if(!(res = platform_get_resource(pdev, IORESOURCE_MEM, 0))) {
		dev_err(&pdev->dev, "failed to platform_get_resource\n");
		err = -ENODEV;
		goto _quit_1;
	}

	priv->regs_phys = res->start;
	priv->regs_size = resource_size(res);

	if (!request_mem_region(priv->regs_phys, priv->regs_size, res->name)) {
		dev_err(&pdev->dev, "failed to request_mem_region\n");
		err = -ENXIO;
		goto _quit_1;
	}

	if ((irq = platform_get_irq(pdev, 0)) < 0) {
		dev_err(&pdev->dev, "failed to platform_get_irq\n");
		err = -ENODEV;
		goto _quit_2;
	}

	dev->irq = irq;

	mac_addr = of_get_mac_address(dev_node);
	if (mac_addr) {
		memcpy(priv->mac_addr, mac_addr, ETH_ALEN);
	} else {
		netdev_info(dev, "no valid HW address -- generate random\n");
		eth_random_addr(priv->mac_addr);
	}

	phy_mode = of_get_phy_mode(dev_node);
	if ((int)phy_mode > 0) {
		priv->phy_mode = phy_mode;
	} else {
		priv->phy_mode = PHY_INTERFACE_MODE_MII;
	}

	for (i = 0; i < PHY_MAX_ADDR; ++i)
		priv->phy_irq[i] = PHY_POLL;

	/* early device inits */

	dev->base_addr = priv->regs_phys;
	dev->netdev_ops = &emac_ndo;
	dev->ethtool_ops = &emac_eto;

	netif_napi_add(dev, &priv->napi, emac_poll, 32);

	if ((err = register_netdev(dev)) < 0) {
		dev_err(&pdev->dev, "failed to register_netdev\n");
		goto _quit_2;
	}

	return 0;

_quit_2:
	release_mem_region(priv->regs_phys, priv->regs_size);
_quit_1:
	free_netdev(dev);
_quit_0:
	return err;
}

static int emac_remove(struct platform_device *pdev)
{
	struct net_device *dev = platform_get_drvdata(pdev);
	struct emac_priv *priv = netdev_priv(dev);

	unregister_netdev(dev);
	emac_mdio_remove(priv->mii_bus);
	mdiobus_unregister(priv->mii_bus);
	mdiobus_free(priv->mii_bus);
	dma_free_coherent(&pdev->dev, priv->desc_size, priv->desc_virt,
	                  priv->desc_phys);
	iounmap(priv->regs_virt);
	release_mem_region(priv->regs_phys, priv->regs_size);
	free_netdev(dev);

	return 0;
}

static int emac_suspend(struct platform_device *pdev, pm_message_t state)
{
	struct net_device *netdev = platform_get_drvdata(pdev);

	netif_device_detach(netdev);
	if (netif_running(netdev)) {
		pr_warn("attempt to suspend netif in running state\n");

		emac_stop(netdev);
	}

	return 0;
}

static int emac_resume(struct platform_device *pdev)
{
	struct net_device *netdev = platform_get_drvdata(pdev);

	if (netif_running(netdev)) {
		pr_warn("attempt to resume netif in running state\n");

		emac_open(netdev);
		emac_set_rx_mode(netdev);

		/* refresh link-state */
		netif_carrier_off(netdev);
	}
	netif_device_attach(netdev);

	return 0;
}

#ifdef CONFIG_OF

static struct of_device_id const emac_dt_ids[] = {
	{ .compatible = "arasan,emac" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, emac_dt_ids);

#endif	/* CONFIG_OF */

static struct platform_driver emac_driver = {
	.probe		= emac_probe,
	.remove		= emac_remove,
	.suspend	= emac_suspend,
	.resume		= emac_resume,
	.driver		= {
		.name		= "emac",
		.owner		= THIS_MODULE,
		.of_match_table	= of_match_ptr(emac_dt_ids),
	},
};

/*
 * kernel module support
 */

#ifndef CONFIG_USER_INITCALL_NET

module_platform_driver_probe(emac_driver, emac_probe);

#else	/* CONFIG_USE_INITCALL_NET */

static int emac_mod_init(void)
{
	return platform_driver_register(&emac_driver);
}
user_initcall_grp("NETWORK", emac_mod_init);

static void __exit emac_mod_exit(void)
{
	platform_driver_unregister(&emac_driver);
}
module_exit(emac_mod_exit);

#endif	/* CONFIG_USE_INITCALL_NET */

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Arasan Fast Ethernet MAC driver");
MODULE_AUTHOR("Jongsung Kim <neidhard.kim@lge.com>");
MODULE_ALIAS("platform:emac");
