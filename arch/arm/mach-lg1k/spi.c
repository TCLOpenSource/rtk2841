#include <linux/kernel.h>

#include <linux/amba/bus.h>
#include <linux/amba/pl022.h>
#include <linux/sizes.h>
#include <linux/spi/spi.h>

struct pl022_ssp_controller spi0_data = {
	.bus_id		= 0,
	.num_chipselect	= 1,
};

struct pl022_ssp_controller spi1_data = {
	.bus_id		= 1,
	.num_chipselect	= 1,
};

#ifdef CONFIG_SPI_SPIDEV
static void select_dummy_chip(unsigned int chipselect)
{
        /* add your code here for chip select */
}

static struct pl022_config_chip dummy_chip_info = {
        .com_mode = POLLING_TRANSFER,
        .iface = SSP_INTERFACE_MOTOROLA_SPI,
        .hierarchy = SSP_MASTER,
        .slave_tx_disable = 0,
        .rx_lev_trig = SSP_RX_1_OR_MORE_ELEM,
        .tx_lev_trig = SSP_TX_1_OR_MORE_EMPTY_LOC,
        .ctrl_len = SSP_BITS_12,
        .wait_state = SSP_MWIRE_WAIT_ZERO,
        .duplex = SSP_MICROWIRE_CHANNEL_FULL_DUPLEX,
        .clkdelay = SSP_FEEDBACK_CLK_DELAY_NONE,
        .cs_control = select_dummy_chip,
};

static struct spi_board_info lg115x_spi_board_info[] __initdata = {
	{
		.modalias       = "spidev",
		.bus_num        = 0,
		.chip_select    = 0,
		.max_speed_hz   = 2000000,
		.controller_data = &dummy_chip_info,
		.mode           = SPI_MODE_0,
	},
	{
		.modalias       = "spidev",
		.bus_num        = 1,
		.chip_select    = 0,
		.max_speed_hz   = 2000000,
		.controller_data = &dummy_chip_info,
		.mode           = SPI_MODE_0,
	},
};
#endif

void __init lg115x_init_spi(void)
{
#ifdef CONFIG_SPI_SPIDEV
        spi_register_board_info(lg115x_spi_board_info, ARRAY_SIZE(lg115x_spi_board_info));
#endif
}
