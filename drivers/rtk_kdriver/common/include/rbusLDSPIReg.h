/**
* @file rbusLDSPIReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/7/29
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_LDSPI_REG_H_
#define _RBUS_LDSPI_REG_H_

#include "rbusTypes.h"



//  LDSPI Register Address



#define  LDSPI_LD_CTRL_VADDR                                	(0xb802c900)
#define  LDSPI_DB_CTRL_VADDR                                	(0xb802c95c)
#define  LDSPI_OUT_DATA_CTRL_VADDR                          	(0xb802c904)
#define  LDSPI_TIMING_CTRL_VADDR                            	(0xb802c908)
#define  LDSPI_SEND_DELAY_VADDR                             	(0xb802c90c)
#define  LDSPI_DATA_UNIT_DELAY_VADDR                        	(0xb802c910)
#define  LDSPI_V_SYNC_DUTY_VADDR                            	(0xb802c914)
#define  LDSPI_DATA_H_TIME_VADDR                            	(0xb802c918)
#define  LDSPI_LD_SPI_V_SYNC_DELAY_VADDR                    	(0xb802c964)
#define  LDSPI_LD_SPI_H_TOTAL_VADDR                         	(0xb802c968)
#define  LDSPI_LD_SPI_DUMMY_VADDR                           	(0xb802c96c)
#define  LDSPI_OUTINDEX_ADDR_CTRL_VADDR                     	(0xb802c91c)
#define  LDSPI_OUTINDEX_RWPORT_VADDR                        	(0xb802c920)
#define  LDSPI_DATA_ADDR_CTRL_VADDR                         	(0xb802c924)
#define  LDSPI_DATA_RWPORT_VADDR                            	(0xb802c928)
#define  LDSPI_AS_WR_CTRL_VADDR                             	(0xb802c92c)
#define  LDSPI_WCLR_CTRL_VADDR                              	(0xb802c960)
#define  LDSPI_RX_DATA_CTRL_VADDR                           	(0xb802c930)
#define  LDSPI_RX_DATAW0_VADDR                              	(0xb802c934)
#define  LDSPI_RX_DATAW1_VADDR                              	(0xb802c938)
#define  LDSPI_RX_DATAW2_VADDR                              	(0xb802c93c)
#define  LDSPI_RX_DATAW3_VADDR                              	(0xb802c940)
#define  LDSPI_RX_DATAW4_VADDR                              	(0xb802c944)
#define  LDSPI_RX_DATAW5_VADDR                              	(0xb802c948)
#define  LDSPI_RX_DATAW6_VADDR                              	(0xb802c94c)
#define  LDSPI_RX_DATAW7_VADDR                              	(0xb802c950)
#define  LDSPI_BIST_CTRL0_VADDR                             	(0xb802c954)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======LDSPI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_mode:2;
        RBus_UInt32  tx_add_1t:1;
        RBus_UInt32  always_sending_mode:1;
        RBus_UInt32  as_led_reset:1;
        RBus_UInt32  rx_clk_sample_mode:1;
        RBus_UInt32  rx_clk_shift:10;
        RBus_UInt32  rx_sdi_inv:1;
        RBus_UInt32  tx_sdo_inv:1;
        RBus_UInt32  tx_vsync_inv:1;
        RBus_UInt32  tx_hsync_inv:1;
        RBus_UInt32  tx_cs_inv:1;
        RBus_UInt32  tx_clk_inv:1;
        RBus_UInt32  out_data_align:1;
        RBus_UInt32  in_data_align:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  send_follow_vsync:1;
        RBus_UInt32  send_trigger:1;
        RBus_UInt32  start_enable:1;
    };
}ldspi_ld_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  double_buf_set:1;
        RBus_UInt32  double_buf_read_level:1;
        RBus_UInt32  res1:29;
    };
}ldspi_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_endian:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  output_units:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  output_data_format:2;
    };
}ldspi_out_data_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sck_h:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  sck_l:8;
    };
}ldspi_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_send_delay:24;
        RBus_UInt32  cs_hold_time:8;
    };
}ldspi_send_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  each_unit_delay:24;
        RBus_UInt32  res1:8;
    };
}ldspi_data_unit_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_d:8;
        RBus_UInt32  hsync_d:8;
        RBus_UInt32  res1:16;
    };
}ldspi_v_sync_duty_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  data_hold_time:9;
        RBus_UInt32  res2:16;
    };
}ldspi_data_h_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vsync_delay:24;
        RBus_UInt32  res1:8;
    };
}ldspi_ld_spi_v_sync_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_dh_total:13;
        RBus_UInt32  res1:19;
    };
}ldspi_ld_spi_h_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c96c_31_0:32;
    };
}ldspi_ld_spi_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  outindex_rw_pointer_set:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  outindex_rw_pointer:7;
    };
}ldspi_outindex_addr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  outindex_rw_data_port:10;
    };
}ldspi_outindex_rwport_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  data_rw_pointer_set:7;
        RBus_UInt32  res2:9;
        RBus_UInt32  data_rw_pointer:7;
    };
}ldspi_data_addr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  data_rw_data_port:16;
    };
}ldspi_data_rwport_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  data_16_bit_swap:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  rw_bit_sent_sel:1;
        RBus_UInt32  rw_cmd_sel:1;
        RBus_UInt32  rwcmd:1;
        RBus_UInt32  w_package_repeater:4;
    };
}ldspi_as_wr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_done:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rx_time_out_pending:1;
        RBus_UInt32  res2:17;
        RBus_UInt32  cmd_error_status:1;
        RBus_UInt32  res3:11;
    };
}ldspi_wclr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  time_out_period:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  rx_units:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  rx0_timeout_int_en:1;
        RBus_UInt32  rx_data_format:1;
    };
}ldspi_rx_data_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte0:8;
        RBus_UInt32  input_data_byte1:8;
        RBus_UInt32  input_data_byte2:8;
        RBus_UInt32  input_data_byte3:8;
    };
}ldspi_rx_dataw0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte4:8;
        RBus_UInt32  input_data_byte5:8;
        RBus_UInt32  input_data_byte6:8;
        RBus_UInt32  input_data_byte7:8;
    };
}ldspi_rx_dataw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte8:8;
        RBus_UInt32  input_data_byte9:8;
        RBus_UInt32  input_data_byte10:8;
        RBus_UInt32  input_data_byte11:8;
    };
}ldspi_rx_dataw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte12:8;
        RBus_UInt32  input_data_byte13:8;
        RBus_UInt32  input_data_byte14:8;
        RBus_UInt32  input_data_byte15:8;
    };
}ldspi_rx_dataw3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte16:8;
        RBus_UInt32  input_data_byte17:8;
        RBus_UInt32  input_data_byte18:8;
        RBus_UInt32  input_data_byte19:8;
    };
}ldspi_rx_dataw4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte20:8;
        RBus_UInt32  input_data_byte21:8;
        RBus_UInt32  input_data_byte22:8;
        RBus_UInt32  input_data_byte23:8;
    };
}ldspi_rx_dataw5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte24:8;
        RBus_UInt32  input_data_byte25:8;
        RBus_UInt32  input_data_byte26:8;
        RBus_UInt32  input_data_byte27:8;
    };
}ldspi_rx_dataw6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte28:8;
        RBus_UInt32  input_data_byte29:8;
        RBus_UInt32  input_data_byte30:8;
        RBus_UInt32  input_data_byte31:8;
    };
}ldspi_rx_dataw7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ld_spi_rme_1:1;
        RBus_UInt32  ld_spi_rm_1:4;
        RBus_UInt32  ld_spi_ls_1:1;
        RBus_UInt32  ld_spi_rme_0:1;
        RBus_UInt32  ld_spi_rm_0:4;
        RBus_UInt32  ld_spi_ls_0:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  ld_spi_drf_bist_fail_1:1;
        RBus_UInt32  ld_spi_drf_bist_fail_0:1;
        RBus_UInt32  ld_spi_bist_fail_1:1;
        RBus_UInt32  ld_spi_bist_fail_0:1;
    };
}ldspi_bist_ctrl0_RBUS;

#else //apply LITTLE_ENDIAN

//======LDSPI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_enable:1;
        RBus_UInt32  send_trigger:1;
        RBus_UInt32  send_follow_vsync:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  in_data_align:1;
        RBus_UInt32  out_data_align:1;
        RBus_UInt32  tx_clk_inv:1;
        RBus_UInt32  tx_cs_inv:1;
        RBus_UInt32  tx_hsync_inv:1;
        RBus_UInt32  tx_vsync_inv:1;
        RBus_UInt32  tx_sdo_inv:1;
        RBus_UInt32  rx_sdi_inv:1;
        RBus_UInt32  rx_clk_shift:10;
        RBus_UInt32  rx_clk_sample_mode:1;
        RBus_UInt32  as_led_reset:1;
        RBus_UInt32  always_sending_mode:1;
        RBus_UInt32  tx_add_1t:1;
        RBus_UInt32  ld_mode:2;
    };
}ldspi_ld_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  double_buf_read_level:1;
        RBus_UInt32  double_buf_set:1;
        RBus_UInt32  double_buf_en:1;
    };
}ldspi_db_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_data_format:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  output_units:10;
        RBus_UInt32  res2:17;
        RBus_UInt32  data_endian:1;
    };
}ldspi_out_data_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sck_l:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  sck_h:8;
        RBus_UInt32  res2:8;
    };
}ldspi_timing_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_hold_time:8;
        RBus_UInt32  data_send_delay:24;
    };
}ldspi_send_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  each_unit_delay:24;
    };
}ldspi_data_unit_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  hsync_d:8;
        RBus_UInt32  vsync_d:8;
    };
}ldspi_v_sync_duty_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  data_hold_time:9;
        RBus_UInt32  res2:7;
    };
}ldspi_data_h_time_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vsync_delay:24;
    };
}ldspi_ld_spi_v_sync_delay_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ld_spi_dh_total:13;
    };
}ldspi_ld_spi_h_total_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c96c_31_0:32;
    };
}ldspi_ld_spi_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  outindex_rw_pointer:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  outindex_rw_pointer_set:7;
        RBus_UInt32  res2:9;
    };
}ldspi_outindex_addr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  outindex_rw_data_port:10;
        RBus_UInt32  res1:22;
    };
}ldspi_outindex_rwport_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_rw_pointer:7;
        RBus_UInt32  res1:9;
        RBus_UInt32  data_rw_pointer_set:7;
        RBus_UInt32  res2:9;
    };
}ldspi_data_addr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_rw_data_port:16;
        RBus_UInt32  res1:16;
    };
}ldspi_data_rwport_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w_package_repeater:4;
        RBus_UInt32  rwcmd:1;
        RBus_UInt32  rw_cmd_sel:1;
        RBus_UInt32  rw_bit_sent_sel:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  data_16_bit_swap:1;
        RBus_UInt32  res2:15;
    };
}ldspi_as_wr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cmd_error_status:1;
        RBus_UInt32  res2:17;
        RBus_UInt32  rx_time_out_pending:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  rx_done:1;
    };
}ldspi_wclr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx_data_format:1;
        RBus_UInt32  rx0_timeout_int_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  rx_units:5;
        RBus_UInt32  res2:7;
        RBus_UInt32  time_out_period:8;
        RBus_UInt32  res3:8;
    };
}ldspi_rx_data_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte3:8;
        RBus_UInt32  input_data_byte2:8;
        RBus_UInt32  input_data_byte1:8;
        RBus_UInt32  input_data_byte0:8;
    };
}ldspi_rx_dataw0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte7:8;
        RBus_UInt32  input_data_byte6:8;
        RBus_UInt32  input_data_byte5:8;
        RBus_UInt32  input_data_byte4:8;
    };
}ldspi_rx_dataw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte11:8;
        RBus_UInt32  input_data_byte10:8;
        RBus_UInt32  input_data_byte9:8;
        RBus_UInt32  input_data_byte8:8;
    };
}ldspi_rx_dataw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte15:8;
        RBus_UInt32  input_data_byte14:8;
        RBus_UInt32  input_data_byte13:8;
        RBus_UInt32  input_data_byte12:8;
    };
}ldspi_rx_dataw3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte19:8;
        RBus_UInt32  input_data_byte18:8;
        RBus_UInt32  input_data_byte17:8;
        RBus_UInt32  input_data_byte16:8;
    };
}ldspi_rx_dataw4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte23:8;
        RBus_UInt32  input_data_byte22:8;
        RBus_UInt32  input_data_byte21:8;
        RBus_UInt32  input_data_byte20:8;
    };
}ldspi_rx_dataw5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte27:8;
        RBus_UInt32  input_data_byte26:8;
        RBus_UInt32  input_data_byte25:8;
        RBus_UInt32  input_data_byte24:8;
    };
}ldspi_rx_dataw6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  input_data_byte31:8;
        RBus_UInt32  input_data_byte30:8;
        RBus_UInt32  input_data_byte29:8;
        RBus_UInt32  input_data_byte28:8;
    };
}ldspi_rx_dataw7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spi_bist_fail_0:1;
        RBus_UInt32  ld_spi_bist_fail_1:1;
        RBus_UInt32  ld_spi_drf_bist_fail_0:1;
        RBus_UInt32  ld_spi_drf_bist_fail_1:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  ld_spi_ls_0:1;
        RBus_UInt32  ld_spi_rm_0:4;
        RBus_UInt32  ld_spi_rme_0:1;
        RBus_UInt32  ld_spi_ls_1:1;
        RBus_UInt32  ld_spi_rm_1:4;
        RBus_UInt32  ld_spi_rme_1:1;
        RBus_UInt32  res2:6;
    };
}ldspi_bist_ctrl0_RBUS;




#endif 


#endif 
