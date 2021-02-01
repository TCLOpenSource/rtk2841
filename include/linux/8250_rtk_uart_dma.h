#ifndef _8250_RTK_UART_DMA_H_
#define _8250_RTK_UART_DMA_H_
#ifdef CONFIG_REALTEK_UART_DMA
#include <linux/types.h>

#define UART1_DMA_BIT_MASK 32

/*Uart1 DMA regs define*/
#define UR1_DMA_CTRL									(0x18039200)
#define UR1_DMA_CTRL_reg								(0xB8039200)
#define UR1_DMAIFEN(x)								(x << 6)
#define UR1_TXEMPTHR(x)								(x & 0x2F)
#define UR1_DMAM(x)									(x << 3)

#define UR1_DMA_STS									(0x18039204)
#define UR1_DMA_STS_reg								(0xB8039204)
#define UR1_TX_WRD_COUNT(x)							(x & 0x1F)

#define UR1_DMA_INT									(0x18039208)
#define UR1_DMA_INT_reg								(0xB8039208)
#define UR1_UR_TX_THD								(1 << 1)
#define UR1_WRITE_DATA(x)								(x << 0)

#define UR1_DMA_INT_EN								(0x1803920C)
#define UR1_DMA_INT_EN_reg							(0xB803920C)
#define UR1_UR_TX_THD_EN(x)							(x << 0)

#define UR1_DMA_TXBASE								(0x18039210)
#define UR1_DMA_TXBASE_reg							(0xB8039210)
#define UR1_TX_BASE(x)								(x & 0x7FFFFFF8)


#define UR1_DMA_TXLIMIT								(0x18039214)
#define UR1_DMA_TXLIMIT_reg							(0xB8039214)
#define UR1_TX_LIMIT(x)								(x & 0x7FFFFFF8)

#define UR1_DMA_TXWRPTR								(0x18039218)
#define UR1_DMA_TXWRPTR_reg							(0xB8039218)
#define UR1_TX_WRPTR(x)								(x & 0x7FFFFFFF)

#define UR1_DMA_TXRDPTR								(0x1803921C)
#define UR1_DMA_TXRDPTR_reg							(0xB803921C)
#define UR1_TX_TXRDPTR(x)								(x & 0x7FFFFFFF)

#define UR1_DMA_TXTHD								(0x18039220)
#define UR1_DMA_TXTHD_reg								(0xB8039220)
#define UR1_TX_THD(x)									(x)

#define UR1_DMA_GATING_EN_CTRL						(0x18039224)
#define UR1_DMA_GATING_EN_CTRL_reg					(0xB8039224)
#define UR1_GATING_EN(x)								(x << 0)


/*DMA reg ofst define*/
#define UART_DMA_CTRL						(0)
#define UART_DMA_STS							(1)
#define UART_DMA_INT							(2)
#define UART_DMA_INT_EN						(3)
#define UART_DMA_TXBASE						(4)
#define UART_DMA_TXLIMIT						(5)
#define UART_DMA_TXWRPTR						(6)
#define UART_DMA_TXRDPTR						(7)
#define UART_DMA_TXTHD						(8)
#define UART_DMA_GATING_EN_CTRL				(9)


#define UART_GET_PHYS(virtual)                           virt_to_phys(virtual)
#define UART_DMA_BUF_ALIGN			8

struct uart_8250_rtk_dma {
	void *tx_dma_ring_buf_head;
	void *tx_dma_ring_buf_align;
	dma_addr_t tx_dma_addr;
	int tx_dma_ring_buf_size;
};

struct uart_8250_rtk_dma_config {
	unsigned char *dma_membase;
	int dma_membase_ofst;
	unsigned int dma_ring_buf_len;
	unsigned int dma_tx_thd;
	unsigned int dma_tx_empty_thd;
};


#endif
#endif