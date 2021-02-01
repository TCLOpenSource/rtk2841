/**
* @file Mac5-DesignSpec-ME
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_ME_REG_H_
#define _RBUS_ME_REG_H_

#include "rbus_types.h"



//  ME Register Address
#define  ME_ME_CTRL                                                              0x18009000
#define  ME_ME_CTRL_reg_addr                                                     "0xB8009000"
#define  ME_ME_CTRL_reg                                                          0xB8009000
#define  ME_ME_CTRL_inst_addr                                                    "0x0000"
#define  set_ME_ME_CTRL_reg(data)                                                (*((volatile unsigned int*)ME_ME_CTRL_reg)=data)
#define  get_ME_ME_CTRL_reg                                                      (*((volatile unsigned int*)ME_ME_CTRL_reg))
#define  ME_ME_CTRL_err_shift                                                    (20)
#define  ME_ME_CTRL_mbl1_shift                                                   (9)
#define  ME_ME_CTRL_mbl0_shift                                                   (8)
#define  ME_ME_CTRL_ints_shift                                                   (7)
#define  ME_ME_CTRL_inte_shift                                                   (6)
#define  ME_ME_CTRL_disable_mp_shift                                             (5)
#define  ME_ME_CTRL_tw_shift                                                     (4)
#define  ME_ME_CTRL_tms_shift                                                    (3)
#define  ME_ME_CTRL_tbs_shift                                                    (2)
#define  ME_ME_CTRL_go_shift                                                     (1)
#define  ME_ME_CTRL_write_data_shift                                             (0)
#define  ME_ME_CTRL_err_mask                                                     (0x00100000)
#define  ME_ME_CTRL_mbl1_mask                                                    (0x00000200)
#define  ME_ME_CTRL_mbl0_mask                                                    (0x00000100)
#define  ME_ME_CTRL_ints_mask                                                    (0x00000080)
#define  ME_ME_CTRL_inte_mask                                                    (0x00000040)
#define  ME_ME_CTRL_disable_mp_mask                                              (0x00000020)
#define  ME_ME_CTRL_tw_mask                                                      (0x00000010)
#define  ME_ME_CTRL_tms_mask                                                     (0x00000008)
#define  ME_ME_CTRL_tbs_mask                                                     (0x00000004)
#define  ME_ME_CTRL_go_mask                                                      (0x00000002)
#define  ME_ME_CTRL_write_data_mask                                              (0x00000001)
#define  ME_ME_CTRL_err(data)                                                    (0x00100000&((data)<<20))
#define  ME_ME_CTRL_mbl1(data)                                                   (0x00000200&((data)<<9))
#define  ME_ME_CTRL_mbl0(data)                                                   (0x00000100&((data)<<8))
#define  ME_ME_CTRL_ints(data)                                                   (0x00000080&((data)<<7))
#define  ME_ME_CTRL_inte(data)                                                   (0x00000040&((data)<<6))
#define  ME_ME_CTRL_disable_mp(data)                                             (0x00000020&((data)<<5))
#define  ME_ME_CTRL_tw(data)                                                     (0x00000010&((data)<<4))
#define  ME_ME_CTRL_tms(data)                                                    (0x00000008&((data)<<3))
#define  ME_ME_CTRL_tbs(data)                                                    (0x00000004&((data)<<2))
#define  ME_ME_CTRL_go(data)                                                     (0x00000002&((data)<<1))
#define  ME_ME_CTRL_write_data(data)                                             (0x00000001&(data))
#define  ME_ME_CTRL_get_err(data)                                                ((0x00100000&(data))>>20)
#define  ME_ME_CTRL_get_mbl1(data)                                               ((0x00000200&(data))>>9)
#define  ME_ME_CTRL_get_mbl0(data)                                               ((0x00000100&(data))>>8)
#define  ME_ME_CTRL_get_ints(data)                                               ((0x00000080&(data))>>7)
#define  ME_ME_CTRL_get_inte(data)                                               ((0x00000040&(data))>>6)
#define  ME_ME_CTRL_get_disable_mp(data)                                         ((0x00000020&(data))>>5)
#define  ME_ME_CTRL_get_tw(data)                                                 ((0x00000010&(data))>>4)
#define  ME_ME_CTRL_get_tms(data)                                                ((0x00000008&(data))>>3)
#define  ME_ME_CTRL_get_tbs(data)                                                ((0x00000004&(data))>>2)
#define  ME_ME_CTRL_get_go(data)                                                 ((0x00000002&(data))>>1)
#define  ME_ME_CTRL_get_write_data(data)                                         (0x00000001&(data))

#define  ME_ME_CMDADDR                                                           0x18009010
#define  ME_ME_CMDADDR_reg_addr                                                  "0xB8009010"
#define  ME_ME_CMDADDR_reg                                                       0xB8009010
#define  ME_ME_CMDADDR_inst_addr                                                 "0x0001"
#define  set_ME_ME_CMDADDR_reg(data)                                             (*((volatile unsigned int*)ME_ME_CMDADDR_reg)=data)
#define  get_ME_ME_CMDADDR_reg                                                   (*((volatile unsigned int*)ME_ME_CMDADDR_reg))
#define  ME_ME_CMDADDR_addr_shift                                                (0)
#define  ME_ME_CMDADDR_addr_mask                                                 (0xFFFFFFFF)
#define  ME_ME_CMDADDR_addr(data)                                                (0xFFFFFFFF&(data))
#define  ME_ME_CMDADDR_get_addr(data)                                            (0xFFFFFFFF&(data))

#define  ME_ME_RLTADDR                                                           0x18009014
#define  ME_ME_RLTADDR_reg_addr                                                  "0xB8009014"
#define  ME_ME_RLTADDR_reg                                                       0xB8009014
#define  ME_ME_RLTADDR_inst_addr                                                 "0x0002"
#define  set_ME_ME_RLTADDR_reg(data)                                             (*((volatile unsigned int*)ME_ME_RLTADDR_reg)=data)
#define  get_ME_ME_RLTADDR_reg                                                   (*((volatile unsigned int*)ME_ME_RLTADDR_reg))
#define  ME_ME_RLTADDR_addr_shift                                                (0)
#define  ME_ME_RLTADDR_addr_mask                                                 (0xFFFFFFFF)
#define  ME_ME_RLTADDR_addr(data)                                                (0xFFFFFFFF&(data))
#define  ME_ME_RLTADDR_get_addr(data)                                            (0xFFFFFFFF&(data))

#define  ME_ME_TSETA                                                             0x18009018
#define  ME_ME_TSETA_reg_addr                                                    "0xB8009018"
#define  ME_ME_TSETA_reg                                                         0xB8009018
#define  ME_ME_TSETA_inst_addr                                                   "0x0003"
#define  set_ME_ME_TSETA_reg(data)                                               (*((volatile unsigned int*)ME_ME_TSETA_reg)=data)
#define  get_ME_ME_TSETA_reg                                                     (*((volatile unsigned int*)ME_ME_TSETA_reg))
#define  ME_ME_TSETA_fld_shift                                                   (16)
#define  ME_ME_TSETA_ti_shift                                                    (8)
#define  ME_ME_TSETA_bi_shift                                                    (0)
#define  ME_ME_TSETA_fld_mask                                                    (0x00010000)
#define  ME_ME_TSETA_ti_mask                                                     (0x00007F00)
#define  ME_ME_TSETA_bi_mask                                                     (0x0000007F)
#define  ME_ME_TSETA_fld(data)                                                   (0x00010000&((data)<<16))
#define  ME_ME_TSETA_ti(data)                                                    (0x00007F00&((data)<<8))
#define  ME_ME_TSETA_bi(data)                                                    (0x0000007F&(data))
#define  ME_ME_TSETA_get_fld(data)                                               ((0x00010000&(data))>>16)
#define  ME_ME_TSETA_get_ti(data)                                                ((0x00007F00&(data))>>8)
#define  ME_ME_TSETA_get_bi(data)                                                (0x0000007F&(data))

#define  ME_ME_TSETB                                                             0x18009020
#define  ME_ME_TSETB_reg_addr                                                    "0xB8009020"
#define  ME_ME_TSETB_reg                                                         0xB8009020
#define  ME_ME_TSETB_inst_addr                                                   "0x0004"
#define  set_ME_ME_TSETB_reg(data)                                               (*((volatile unsigned int*)ME_ME_TSETB_reg)=data)
#define  get_ME_ME_TSETB_reg                                                     (*((volatile unsigned int*)ME_ME_TSETB_reg))
#define  ME_ME_TSETB_y_shift                                                     (16)
#define  ME_ME_TSETB_xinc_shift                                                  (12)
#define  ME_ME_TSETB_x_shift                                                     (0)
#define  ME_ME_TSETB_y_mask                                                      (0x07FF0000)
#define  ME_ME_TSETB_xinc_mask                                                   (0x0000F000)
#define  ME_ME_TSETB_x_mask                                                      (0x000007FF)
#define  ME_ME_TSETB_y(data)                                                     (0x07FF0000&((data)<<16))
#define  ME_ME_TSETB_xinc(data)                                                  (0x0000F000&((data)<<12))
#define  ME_ME_TSETB_x(data)                                                     (0x000007FF&(data))
#define  ME_ME_TSETB_get_y(data)                                                 ((0x07FF0000&(data))>>16)
#define  ME_ME_TSETB_get_xinc(data)                                              ((0x0000F000&(data))>>12)
#define  ME_ME_TSETB_get_x(data)                                                 (0x000007FF&(data))

#define  ME_ME_RSETA                                                             0x18009028
#define  ME_ME_RSETA_reg_addr                                                    "0xB8009028"
#define  ME_ME_RSETA_reg                                                         0xB8009028
#define  ME_ME_RSETA_inst_addr                                                   "0x0005"
#define  set_ME_ME_RSETA_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETA_reg)=data)
#define  get_ME_ME_RSETA_reg                                                     (*((volatile unsigned int*)ME_ME_RSETA_reg))
#define  ME_ME_RSETA_fld_shift                                                   (16)
#define  ME_ME_RSETA_ti_shift                                                    (8)
#define  ME_ME_RSETA_bi_shift                                                    (0)
#define  ME_ME_RSETA_fld_mask                                                    (0x00010000)
#define  ME_ME_RSETA_ti_mask                                                     (0x00007F00)
#define  ME_ME_RSETA_bi_mask                                                     (0x0000007F)
#define  ME_ME_RSETA_fld(data)                                                   (0x00010000&((data)<<16))
#define  ME_ME_RSETA_ti(data)                                                    (0x00007F00&((data)<<8))
#define  ME_ME_RSETA_bi(data)                                                    (0x0000007F&(data))
#define  ME_ME_RSETA_get_fld(data)                                               ((0x00010000&(data))>>16)
#define  ME_ME_RSETA_get_ti(data)                                                ((0x00007F00&(data))>>8)
#define  ME_ME_RSETA_get_bi(data)                                                (0x0000007F&(data))

#define  ME_ME_RSETB                                                             0x18009030
#define  ME_ME_RSETB_reg_addr                                                    "0xB8009030"
#define  ME_ME_RSETB_reg                                                         0xB8009030
#define  ME_ME_RSETB_inst_addr                                                   "0x0006"
#define  set_ME_ME_RSETB_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETB_reg)=data)
#define  get_ME_ME_RSETB_reg                                                     (*((volatile unsigned int*)ME_ME_RSETB_reg))
#define  ME_ME_RSETB_mvys_shift                                                  (30)
#define  ME_ME_RSETB_mvxs_shift                                                  (22)
#define  ME_ME_RSETB_mvx_shift                                                   (8)
#define  ME_ME_RSETB_mvy_shift                                                   (0)
#define  ME_ME_RSETB_mvys_mask                                                   (0xC0000000)
#define  ME_ME_RSETB_mvxs_mask                                                   (0x00C00000)
#define  ME_ME_RSETB_mvx_mask                                                    (0x0000FF00)
#define  ME_ME_RSETB_mvy_mask                                                    (0x000000FF)
#define  ME_ME_RSETB_mvys(data)                                                  (0xC0000000&((data)<<30))
#define  ME_ME_RSETB_mvxs(data)                                                  (0x00C00000&((data)<<22))
#define  ME_ME_RSETB_mvx(data)                                                   (0x0000FF00&((data)<<8))
#define  ME_ME_RSETB_mvy(data)                                                   (0x000000FF&(data))
#define  ME_ME_RSETB_get_mvys(data)                                              ((0xC0000000&(data))>>30)
#define  ME_ME_RSETB_get_mvxs(data)                                              ((0x00C00000&(data))>>22)
#define  ME_ME_RSETB_get_mvx(data)                                               ((0x0000FF00&(data))>>8)
#define  ME_ME_RSETB_get_mvy(data)                                               (0x000000FF&(data))

#define  ME_ME_RSETC                                                             0x18009038
#define  ME_ME_RSETC_reg_addr                                                    "0xB8009038"
#define  ME_ME_RSETC_reg                                                         0xB8009038
#define  ME_ME_RSETC_inst_addr                                                   "0x0007"
#define  set_ME_ME_RSETC_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETC_reg)=data)
#define  get_ME_ME_RSETC_reg                                                     (*((volatile unsigned int*)ME_ME_RSETC_reg))
#define  ME_ME_RSETC_y_shift                                                     (16)
#define  ME_ME_RSETC_xinc_shift                                                  (12)
#define  ME_ME_RSETC_x_shift                                                     (0)
#define  ME_ME_RSETC_y_mask                                                      (0x07FF0000)
#define  ME_ME_RSETC_xinc_mask                                                   (0x0000F000)
#define  ME_ME_RSETC_x_mask                                                      (0x000007FF)
#define  ME_ME_RSETC_y(data)                                                     (0x07FF0000&((data)<<16))
#define  ME_ME_RSETC_xinc(data)                                                  (0x0000F000&((data)<<12))
#define  ME_ME_RSETC_x(data)                                                     (0x000007FF&(data))
#define  ME_ME_RSETC_get_y(data)                                                 ((0x07FF0000&(data))>>16)
#define  ME_ME_RSETC_get_xinc(data)                                              ((0x0000F000&(data))>>12)
#define  ME_ME_RSETC_get_x(data)                                                 (0x000007FF&(data))

#define  ME_ME_RSETD                                                             0x18009040
#define  ME_ME_RSETD_reg_addr                                                    "0xB8009040"
#define  ME_ME_RSETD_reg                                                         0xB8009040
#define  ME_ME_RSETD_inst_addr                                                   "0x0008"
#define  set_ME_ME_RSETD_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETD_reg)=data)
#define  get_ME_ME_RSETD_reg                                                     (*((volatile unsigned int*)ME_ME_RSETD_reg))
#define  ME_ME_RSETD_rh_shift                                                    (16)
#define  ME_ME_RSETD_rw_shift                                                    (0)
#define  ME_ME_RSETD_rh_mask                                                     (0x07FF0000)
#define  ME_ME_RSETD_rw_mask                                                     (0x000007FF)
#define  ME_ME_RSETD_rh(data)                                                    (0x07FF0000&((data)<<16))
#define  ME_ME_RSETD_rw(data)                                                    (0x000007FF&(data))
#define  ME_ME_RSETD_get_rh(data)                                                ((0x07FF0000&(data))>>16)
#define  ME_ME_RSETD_get_rw(data)                                                (0x000007FF&(data))

#define  ME_ME_RSETE                                                             0x18009048
#define  ME_ME_RSETE_reg_addr                                                    "0xB8009048"
#define  ME_ME_RSETE_reg                                                         0xB8009048
#define  ME_ME_RSETE_inst_addr                                                   "0x0009"
#define  set_ME_ME_RSETE_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETE_reg)=data)
#define  get_ME_ME_RSETE_reg                                                     (*((volatile unsigned int*)ME_ME_RSETE_reg))
#define  ME_ME_RSETE_tsy_shift                                                   (16)
#define  ME_ME_RSETE_tsx_shift                                                   (0)
#define  ME_ME_RSETE_tsy_mask                                                    (0x07FF0000)
#define  ME_ME_RSETE_tsx_mask                                                    (0x000007FF)
#define  ME_ME_RSETE_tsy(data)                                                   (0x07FF0000&((data)<<16))
#define  ME_ME_RSETE_tsx(data)                                                   (0x000007FF&(data))
#define  ME_ME_RSETE_get_tsy(data)                                               ((0x07FF0000&(data))>>16)
#define  ME_ME_RSETE_get_tsx(data)                                               (0x000007FF&(data))

#define  ME_ME_RSETF                                                             0x18009050
#define  ME_ME_RSETF_reg_addr                                                    "0xB8009050"
#define  ME_ME_RSETF_reg                                                         0xB8009050
#define  ME_ME_RSETF_inst_addr                                                   "0x000A"
#define  set_ME_ME_RSETF_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETF_reg)=data)
#define  get_ME_ME_RSETF_reg                                                     (*((volatile unsigned int*)ME_ME_RSETF_reg))
#define  ME_ME_RSETF_tey_shift                                                   (16)
#define  ME_ME_RSETF_tex_shift                                                   (0)
#define  ME_ME_RSETF_tey_mask                                                    (0x07FF0000)
#define  ME_ME_RSETF_tex_mask                                                    (0x000007FF)
#define  ME_ME_RSETF_tey(data)                                                   (0x07FF0000&((data)<<16))
#define  ME_ME_RSETF_tex(data)                                                   (0x000007FF&(data))
#define  ME_ME_RSETF_get_tey(data)                                               ((0x07FF0000&(data))>>16)
#define  ME_ME_RSETF_get_tex(data)                                               (0x000007FF&(data))

#define  ME_ME_RSETG                                                             0x18009058
#define  ME_ME_RSETG_reg_addr                                                    "0xB8009058"
#define  ME_ME_RSETG_reg                                                         0xB8009058
#define  ME_ME_RSETG_inst_addr                                                   "0x000B"
#define  set_ME_ME_RSETG_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETG_reg)=data)
#define  get_ME_ME_RSETG_reg                                                     (*((volatile unsigned int*)ME_ME_RSETG_reg))
#define  ME_ME_RSETG_bsy_shift                                                   (16)
#define  ME_ME_RSETG_bsx_shift                                                   (0)
#define  ME_ME_RSETG_bsy_mask                                                    (0x07FF0000)
#define  ME_ME_RSETG_bsx_mask                                                    (0x000007FF)
#define  ME_ME_RSETG_bsy(data)                                                   (0x07FF0000&((data)<<16))
#define  ME_ME_RSETG_bsx(data)                                                   (0x000007FF&(data))
#define  ME_ME_RSETG_get_bsy(data)                                               ((0x07FF0000&(data))>>16)
#define  ME_ME_RSETG_get_bsx(data)                                               (0x000007FF&(data))

#define  ME_ME_RSETH                                                             0x18009060
#define  ME_ME_RSETH_reg_addr                                                    "0xB8009060"
#define  ME_ME_RSETH_reg                                                         0xB8009060
#define  ME_ME_RSETH_inst_addr                                                   "0x000C"
#define  set_ME_ME_RSETH_reg(data)                                               (*((volatile unsigned int*)ME_ME_RSETH_reg)=data)
#define  get_ME_ME_RSETH_reg                                                     (*((volatile unsigned int*)ME_ME_RSETH_reg))
#define  ME_ME_RSETH_bey_shift                                                   (16)
#define  ME_ME_RSETH_bex_shift                                                   (0)
#define  ME_ME_RSETH_bey_mask                                                    (0x07FF0000)
#define  ME_ME_RSETH_bex_mask                                                    (0x000007FF)
#define  ME_ME_RSETH_bey(data)                                                   (0x07FF0000&((data)<<16))
#define  ME_ME_RSETH_bex(data)                                                   (0x000007FF&(data))
#define  ME_ME_RSETH_get_bey(data)                                               ((0x07FF0000&(data))>>16)
#define  ME_ME_RSETH_get_bex(data)                                               (0x000007FF&(data))

#define  ME_ME_MSETA_0                                                           0x18009068
#define  ME_ME_MSETA_0_reg_addr                                                  "0xB8009068"
#define  ME_ME_MSETA_0_reg                                                       0xB8009068
#define  ME_ME_MSETA_0_inst_addr                                                 "0x000D"
#define  set_ME_ME_MSETA_0_reg(data)                                             (*((volatile unsigned int*)ME_ME_MSETA_0_reg)=data)
#define  get_ME_ME_MSETA_0_reg                                                   (*((volatile unsigned int*)ME_ME_MSETA_0_reg))
#define  ME_ME_MSETA_0_stage_shift                                               (31)
#define  ME_ME_MSETA_0_half_shift                                                (29)
#define  ME_ME_MSETA_0_mvce_shift                                                (28)
#define  ME_ME_MSETA_0_hdrlt_shift                                               (27)
#define  ME_ME_MSETA_0_mvcfp_shift                                               (24)
#define  ME_ME_MSETA_0_mvcf_shift                                                (16)
#define  ME_ME_MSETA_0_zmvp_shift                                                (15)
#define  ME_ME_MSETA_0_hdsad_shift                                               (14)
#define  ME_ME_MSETA_0_can_shift                                                 (12)
#define  ME_ME_MSETA_0_bk8x8_shift                                               (11)
#define  ME_ME_MSETA_0_bscale_shift                                              (8)
#define  ME_ME_MSETA_0_zmvb_shift                                                (0)
#define  ME_ME_MSETA_0_stage_mask                                                (0x80000000)
#define  ME_ME_MSETA_0_half_mask                                                 (0x60000000)
#define  ME_ME_MSETA_0_mvce_mask                                                 (0x10000000)
#define  ME_ME_MSETA_0_hdrlt_mask                                                (0x08000000)
#define  ME_ME_MSETA_0_mvcfp_mask                                                (0x07000000)
#define  ME_ME_MSETA_0_mvcf_mask                                                 (0x00FF0000)
#define  ME_ME_MSETA_0_zmvp_mask                                                 (0x00008000)
#define  ME_ME_MSETA_0_hdsad_mask                                                (0x00004000)
#define  ME_ME_MSETA_0_can_mask                                                  (0x00003000)
#define  ME_ME_MSETA_0_bk8x8_mask                                                (0x00000800)
#define  ME_ME_MSETA_0_bscale_mask                                               (0x00000700)
#define  ME_ME_MSETA_0_zmvb_mask                                                 (0x000000FF)
#define  ME_ME_MSETA_0_stage(data)                                               (0x80000000&((data)<<31))
#define  ME_ME_MSETA_0_half(data)                                                (0x60000000&((data)<<29))
#define  ME_ME_MSETA_0_mvce(data)                                                (0x10000000&((data)<<28))
#define  ME_ME_MSETA_0_hdrlt(data)                                               (0x08000000&((data)<<27))
#define  ME_ME_MSETA_0_mvcfp(data)                                               (0x07000000&((data)<<24))
#define  ME_ME_MSETA_0_mvcf(data)                                                (0x00FF0000&((data)<<16))
#define  ME_ME_MSETA_0_zmvp(data)                                                (0x00008000&((data)<<15))
#define  ME_ME_MSETA_0_hdsad(data)                                               (0x00004000&((data)<<14))
#define  ME_ME_MSETA_0_can(data)                                                 (0x00003000&((data)<<12))
#define  ME_ME_MSETA_0_bk8x8(data)                                               (0x00000800&((data)<<11))
#define  ME_ME_MSETA_0_bscale(data)                                              (0x00000700&((data)<<8))
#define  ME_ME_MSETA_0_zmvb(data)                                                (0x000000FF&(data))
#define  ME_ME_MSETA_0_get_stage(data)                                           ((0x80000000&(data))>>31)
#define  ME_ME_MSETA_0_get_half(data)                                            ((0x60000000&(data))>>29)
#define  ME_ME_MSETA_0_get_mvce(data)                                            ((0x10000000&(data))>>28)
#define  ME_ME_MSETA_0_get_hdrlt(data)                                           ((0x08000000&(data))>>27)
#define  ME_ME_MSETA_0_get_mvcfp(data)                                           ((0x07000000&(data))>>24)
#define  ME_ME_MSETA_0_get_mvcf(data)                                            ((0x00FF0000&(data))>>16)
#define  ME_ME_MSETA_0_get_zmvp(data)                                            ((0x00008000&(data))>>15)
#define  ME_ME_MSETA_0_get_hdsad(data)                                           ((0x00004000&(data))>>14)
#define  ME_ME_MSETA_0_get_can(data)                                             ((0x00003000&(data))>>12)
#define  ME_ME_MSETA_0_get_bk8x8(data)                                           ((0x00000800&(data))>>11)
#define  ME_ME_MSETA_0_get_bscale(data)                                          ((0x00000700&(data))>>8)
#define  ME_ME_MSETA_0_get_zmvb(data)                                            (0x000000FF&(data))

#define  ME_ME_MSETA_1                                                           0x1800906C
#define  ME_ME_MSETA_1_reg_addr                                                  "0xB800906C"
#define  ME_ME_MSETA_1_reg                                                       0xB800906C
#define  ME_ME_MSETA_1_inst_addr                                                 "0x000E"
#define  set_ME_ME_MSETA_1_reg(data)                                             (*((volatile unsigned int*)ME_ME_MSETA_1_reg)=data)
#define  get_ME_ME_MSETA_1_reg                                                   (*((volatile unsigned int*)ME_ME_MSETA_1_reg))
#define  ME_ME_MSETA_1_stage_shift                                               (31)
#define  ME_ME_MSETA_1_half_shift                                                (29)
#define  ME_ME_MSETA_1_mvce_shift                                                (28)
#define  ME_ME_MSETA_1_hdrlt_shift                                               (27)
#define  ME_ME_MSETA_1_mvcfp_shift                                               (24)
#define  ME_ME_MSETA_1_mvcf_shift                                                (16)
#define  ME_ME_MSETA_1_zmvp_shift                                                (15)
#define  ME_ME_MSETA_1_hdsad_shift                                               (14)
#define  ME_ME_MSETA_1_can_shift                                                 (12)
#define  ME_ME_MSETA_1_bk8x8_shift                                               (11)
#define  ME_ME_MSETA_1_bscale_shift                                              (8)
#define  ME_ME_MSETA_1_zmvb_shift                                                (0)
#define  ME_ME_MSETA_1_stage_mask                                                (0x80000000)
#define  ME_ME_MSETA_1_half_mask                                                 (0x60000000)
#define  ME_ME_MSETA_1_mvce_mask                                                 (0x10000000)
#define  ME_ME_MSETA_1_hdrlt_mask                                                (0x08000000)
#define  ME_ME_MSETA_1_mvcfp_mask                                                (0x07000000)
#define  ME_ME_MSETA_1_mvcf_mask                                                 (0x00FF0000)
#define  ME_ME_MSETA_1_zmvp_mask                                                 (0x00008000)
#define  ME_ME_MSETA_1_hdsad_mask                                                (0x00004000)
#define  ME_ME_MSETA_1_can_mask                                                  (0x00003000)
#define  ME_ME_MSETA_1_bk8x8_mask                                                (0x00000800)
#define  ME_ME_MSETA_1_bscale_mask                                               (0x00000700)
#define  ME_ME_MSETA_1_zmvb_mask                                                 (0x000000FF)
#define  ME_ME_MSETA_1_stage(data)                                               (0x80000000&((data)<<31))
#define  ME_ME_MSETA_1_half(data)                                                (0x60000000&((data)<<29))
#define  ME_ME_MSETA_1_mvce(data)                                                (0x10000000&((data)<<28))
#define  ME_ME_MSETA_1_hdrlt(data)                                               (0x08000000&((data)<<27))
#define  ME_ME_MSETA_1_mvcfp(data)                                               (0x07000000&((data)<<24))
#define  ME_ME_MSETA_1_mvcf(data)                                                (0x00FF0000&((data)<<16))
#define  ME_ME_MSETA_1_zmvp(data)                                                (0x00008000&((data)<<15))
#define  ME_ME_MSETA_1_hdsad(data)                                               (0x00004000&((data)<<14))
#define  ME_ME_MSETA_1_can(data)                                                 (0x00003000&((data)<<12))
#define  ME_ME_MSETA_1_bk8x8(data)                                               (0x00000800&((data)<<11))
#define  ME_ME_MSETA_1_bscale(data)                                              (0x00000700&((data)<<8))
#define  ME_ME_MSETA_1_zmvb(data)                                                (0x000000FF&(data))
#define  ME_ME_MSETA_1_get_stage(data)                                           ((0x80000000&(data))>>31)
#define  ME_ME_MSETA_1_get_half(data)                                            ((0x60000000&(data))>>29)
#define  ME_ME_MSETA_1_get_mvce(data)                                            ((0x10000000&(data))>>28)
#define  ME_ME_MSETA_1_get_hdrlt(data)                                           ((0x08000000&(data))>>27)
#define  ME_ME_MSETA_1_get_mvcfp(data)                                           ((0x07000000&(data))>>24)
#define  ME_ME_MSETA_1_get_mvcf(data)                                            ((0x00FF0000&(data))>>16)
#define  ME_ME_MSETA_1_get_zmvp(data)                                            ((0x00008000&(data))>>15)
#define  ME_ME_MSETA_1_get_hdsad(data)                                           ((0x00004000&(data))>>14)
#define  ME_ME_MSETA_1_get_can(data)                                             ((0x00003000&(data))>>12)
#define  ME_ME_MSETA_1_get_bk8x8(data)                                           ((0x00000800&(data))>>11)
#define  ME_ME_MSETA_1_get_bscale(data)                                          ((0x00000700&(data))>>8)
#define  ME_ME_MSETA_1_get_zmvb(data)                                            (0x000000FF&(data))

#define  ME_ME_MSETB_0                                                           0x18009078
#define  ME_ME_MSETB_0_reg_addr                                                  "0xB8009078"
#define  ME_ME_MSETB_0_reg                                                       0xB8009078
#define  ME_ME_MSETB_0_inst_addr                                                 "0x000F"
#define  set_ME_ME_MSETB_0_reg(data)                                             (*((volatile unsigned int*)ME_ME_MSETB_0_reg)=data)
#define  get_ME_ME_MSETB_0_reg                                                   (*((volatile unsigned int*)ME_ME_MSETB_0_reg))
#define  ME_ME_MSETB_0_mvcb_shift                                                (24)
#define  ME_ME_MSETB_0_mvct_shift                                                (16)
#define  ME_ME_MSETB_0_ryadj_shift                                               (14)
#define  ME_ME_MSETB_0_ry_shift                                                  (8)
#define  ME_ME_MSETB_0_rxadj_shift                                               (6)
#define  ME_ME_MSETB_0_rx_shift                                                  (0)
#define  ME_ME_MSETB_0_mvcb_mask                                                 (0xFF000000)
#define  ME_ME_MSETB_0_mvct_mask                                                 (0x00FF0000)
#define  ME_ME_MSETB_0_ryadj_mask                                                (0x00004000)
#define  ME_ME_MSETB_0_ry_mask                                                   (0x00003F00)
#define  ME_ME_MSETB_0_rxadj_mask                                                (0x00000040)
#define  ME_ME_MSETB_0_rx_mask                                                   (0x0000003F)
#define  ME_ME_MSETB_0_mvcb(data)                                                (0xFF000000&((data)<<24))
#define  ME_ME_MSETB_0_mvct(data)                                                (0x00FF0000&((data)<<16))
#define  ME_ME_MSETB_0_ryadj(data)                                               (0x00004000&((data)<<14))
#define  ME_ME_MSETB_0_ry(data)                                                  (0x00003F00&((data)<<8))
#define  ME_ME_MSETB_0_rxadj(data)                                               (0x00000040&((data)<<6))
#define  ME_ME_MSETB_0_rx(data)                                                  (0x0000003F&(data))
#define  ME_ME_MSETB_0_get_mvcb(data)                                            ((0xFF000000&(data))>>24)
#define  ME_ME_MSETB_0_get_mvct(data)                                            ((0x00FF0000&(data))>>16)
#define  ME_ME_MSETB_0_get_ryadj(data)                                           ((0x00004000&(data))>>14)
#define  ME_ME_MSETB_0_get_ry(data)                                              ((0x00003F00&(data))>>8)
#define  ME_ME_MSETB_0_get_rxadj(data)                                           ((0x00000040&(data))>>6)
#define  ME_ME_MSETB_0_get_rx(data)                                              (0x0000003F&(data))

#define  ME_ME_MSETB_1                                                           0x1800907C
#define  ME_ME_MSETB_1_reg_addr                                                  "0xB800907C"
#define  ME_ME_MSETB_1_reg                                                       0xB800907C
#define  ME_ME_MSETB_1_inst_addr                                                 "0x0010"
#define  set_ME_ME_MSETB_1_reg(data)                                             (*((volatile unsigned int*)ME_ME_MSETB_1_reg)=data)
#define  get_ME_ME_MSETB_1_reg                                                   (*((volatile unsigned int*)ME_ME_MSETB_1_reg))
#define  ME_ME_MSETB_1_mvcb_shift                                                (24)
#define  ME_ME_MSETB_1_mvct_shift                                                (16)
#define  ME_ME_MSETB_1_ryadj_shift                                               (14)
#define  ME_ME_MSETB_1_ry_shift                                                  (8)
#define  ME_ME_MSETB_1_rxadj_shift                                               (6)
#define  ME_ME_MSETB_1_rx_shift                                                  (0)
#define  ME_ME_MSETB_1_mvcb_mask                                                 (0xFF000000)
#define  ME_ME_MSETB_1_mvct_mask                                                 (0x00FF0000)
#define  ME_ME_MSETB_1_ryadj_mask                                                (0x00004000)
#define  ME_ME_MSETB_1_ry_mask                                                   (0x00003F00)
#define  ME_ME_MSETB_1_rxadj_mask                                                (0x00000040)
#define  ME_ME_MSETB_1_rx_mask                                                   (0x0000003F)
#define  ME_ME_MSETB_1_mvcb(data)                                                (0xFF000000&((data)<<24))
#define  ME_ME_MSETB_1_mvct(data)                                                (0x00FF0000&((data)<<16))
#define  ME_ME_MSETB_1_ryadj(data)                                               (0x00004000&((data)<<14))
#define  ME_ME_MSETB_1_ry(data)                                                  (0x00003F00&((data)<<8))
#define  ME_ME_MSETB_1_rxadj(data)                                               (0x00000040&((data)<<6))
#define  ME_ME_MSETB_1_rx(data)                                                  (0x0000003F&(data))
#define  ME_ME_MSETB_1_get_mvcb(data)                                            ((0xFF000000&(data))>>24)
#define  ME_ME_MSETB_1_get_mvct(data)                                            ((0x00FF0000&(data))>>16)
#define  ME_ME_MSETB_1_get_ryadj(data)                                           ((0x00004000&(data))>>14)
#define  ME_ME_MSETB_1_get_ry(data)                                              ((0x00003F00&(data))>>8)
#define  ME_ME_MSETB_1_get_rxadj(data)                                           ((0x00000040&(data))>>6)
#define  ME_ME_MSETB_1_get_rx(data)                                              (0x0000003F&(data))

#define  ME_ME_DBG                                                               0x18009088
#define  ME_ME_DBG_reg_addr                                                      "0xB8009088"
#define  ME_ME_DBG_reg                                                           0xB8009088
#define  ME_ME_DBG_inst_addr                                                     "0x0011"
#define  set_ME_ME_DBG_reg(data)                                                 (*((volatile unsigned int*)ME_ME_DBG_reg)=data)
#define  get_ME_ME_DBG_reg                                                       (*((volatile unsigned int*)ME_ME_DBG_reg))
#define  ME_ME_DBG_write_enable3_shift                                           (9)
#define  ME_ME_DBG_sel1_shift                                                    (6)
#define  ME_ME_DBG_write_enable2_shift                                           (5)
#define  ME_ME_DBG_sel0_shift                                                    (2)
#define  ME_ME_DBG_write_enable1_shift                                           (1)
#define  ME_ME_DBG_enable_shift                                                  (0)
#define  ME_ME_DBG_write_enable3_mask                                            (0x00000200)
#define  ME_ME_DBG_sel1_mask                                                     (0x000001C0)
#define  ME_ME_DBG_write_enable2_mask                                            (0x00000020)
#define  ME_ME_DBG_sel0_mask                                                     (0x0000001C)
#define  ME_ME_DBG_write_enable1_mask                                            (0x00000002)
#define  ME_ME_DBG_enable_mask                                                   (0x00000001)
#define  ME_ME_DBG_write_enable3(data)                                           (0x00000200&((data)<<9))
#define  ME_ME_DBG_sel1(data)                                                    (0x000001C0&((data)<<6))
#define  ME_ME_DBG_write_enable2(data)                                           (0x00000020&((data)<<5))
#define  ME_ME_DBG_sel0(data)                                                    (0x0000001C&((data)<<2))
#define  ME_ME_DBG_write_enable1(data)                                           (0x00000002&((data)<<1))
#define  ME_ME_DBG_enable(data)                                                  (0x00000001&(data))
#define  ME_ME_DBG_get_write_enable3(data)                                       ((0x00000200&(data))>>9)
#define  ME_ME_DBG_get_sel1(data)                                                ((0x000001C0&(data))>>6)
#define  ME_ME_DBG_get_write_enable2(data)                                       ((0x00000020&(data))>>5)
#define  ME_ME_DBG_get_sel0(data)                                                ((0x0000001C&(data))>>2)
#define  ME_ME_DBG_get_write_enable1(data)                                       ((0x00000002&(data))>>1)
#define  ME_ME_DBG_get_enable(data)                                              (0x00000001&(data))

#define  ME_ME_INT                                                               0x1800908C
#define  ME_ME_INT_reg_addr                                                      "0xB800908C"
#define  ME_ME_INT_reg                                                           0xB800908C
#define  ME_ME_INT_inst_addr                                                     "0x0012"
#define  set_ME_ME_INT_reg(data)                                                 (*((volatile unsigned int*)ME_ME_INT_reg)=data)
#define  get_ME_ME_INT_reg                                                       (*((volatile unsigned int*)ME_ME_INT_reg))
#define  ME_ME_INT_me_int_vcpu_en_shift                                          (1)
#define  ME_ME_INT_me_int_vcpu2_en_shift                                         (0)
#define  ME_ME_INT_me_int_vcpu_en_mask                                           (0x00000002)
#define  ME_ME_INT_me_int_vcpu2_en_mask                                          (0x00000001)
#define  ME_ME_INT_me_int_vcpu_en(data)                                          (0x00000002&((data)<<1))
#define  ME_ME_INT_me_int_vcpu2_en(data)                                         (0x00000001&(data))
#define  ME_ME_INT_get_me_int_vcpu_en(data)                                      ((0x00000002&(data))>>1)
#define  ME_ME_INT_get_me_int_vcpu2_en(data)                                     (0x00000001&(data))

#define  ME_ME_SRAM                                                              0x18009090
#define  ME_ME_SRAM_reg_addr                                                     "0xB8009090"
#define  ME_ME_SRAM_reg                                                          0xB8009090
#define  ME_ME_SRAM_inst_addr                                                    "0x0013"
#define  set_ME_ME_SRAM_reg(data)                                                (*((volatile unsigned int*)ME_ME_SRAM_reg)=data)
#define  get_ME_ME_SRAM_reg                                                      (*((volatile unsigned int*)ME_ME_SRAM_reg))
#define  ME_ME_SRAM_ls_shift                                                     (5)
#define  ME_ME_SRAM_rme_shift                                                    (4)
#define  ME_ME_SRAM_rm_3_shift                                                   (3)
#define  ME_ME_SRAM_rm_2_shift                                                   (2)
#define  ME_ME_SRAM_rm_1_shift                                                   (1)
#define  ME_ME_SRAM_rm_0_shift                                                   (0)
#define  ME_ME_SRAM_ls_mask                                                      (0x00000060)
#define  ME_ME_SRAM_rme_mask                                                     (0x00000010)
#define  ME_ME_SRAM_rm_3_mask                                                    (0x00000008)
#define  ME_ME_SRAM_rm_2_mask                                                    (0x00000004)
#define  ME_ME_SRAM_rm_1_mask                                                    (0x00000002)
#define  ME_ME_SRAM_rm_0_mask                                                    (0x00000001)
#define  ME_ME_SRAM_ls(data)                                                     (0x00000060&((data)<<5))
#define  ME_ME_SRAM_rme(data)                                                    (0x00000010&((data)<<4))
#define  ME_ME_SRAM_rm_3(data)                                                   (0x00000008&((data)<<3))
#define  ME_ME_SRAM_rm_2(data)                                                   (0x00000004&((data)<<2))
#define  ME_ME_SRAM_rm_1(data)                                                   (0x00000002&((data)<<1))
#define  ME_ME_SRAM_rm_0(data)                                                   (0x00000001&(data))
#define  ME_ME_SRAM_get_ls(data)                                                 ((0x00000060&(data))>>5)
#define  ME_ME_SRAM_get_rme(data)                                                ((0x00000010&(data))>>4)
#define  ME_ME_SRAM_get_rm_3(data)                                               ((0x00000008&(data))>>3)
#define  ME_ME_SRAM_get_rm_2(data)                                               ((0x00000004&(data))>>2)
#define  ME_ME_SRAM_get_rm_1(data)                                               ((0x00000002&(data))>>1)
#define  ME_ME_SRAM_get_rm_0(data)                                               (0x00000001&(data))

#define  ME_ME_BIST_CTRL1                                                        0x18009094
#define  ME_ME_BIST_CTRL1_reg_addr                                               "0xB8009094"
#define  ME_ME_BIST_CTRL1_reg                                                    0xB8009094
#define  ME_ME_BIST_CTRL1_inst_addr                                              "0x0014"
#define  set_ME_ME_BIST_CTRL1_reg(data)                                          (*((volatile unsigned int*)ME_ME_BIST_CTRL1_reg)=data)
#define  get_ME_ME_BIST_CTRL1_reg                                                (*((volatile unsigned int*)ME_ME_BIST_CTRL1_reg))
#define  ME_ME_BIST_CTRL1_me0_drf_bist_en_shift                                  (3)
#define  ME_ME_BIST_CTRL1_me1_drf_bist_en_shift                                  (2)
#define  ME_ME_BIST_CTRL1_me0_bist_en_shift                                      (1)
#define  ME_ME_BIST_CTRL1_me1_bist_en_shift                                      (0)
#define  ME_ME_BIST_CTRL1_me0_drf_bist_en_mask                                   (0x00000008)
#define  ME_ME_BIST_CTRL1_me1_drf_bist_en_mask                                   (0x00000004)
#define  ME_ME_BIST_CTRL1_me0_bist_en_mask                                       (0x00000002)
#define  ME_ME_BIST_CTRL1_me1_bist_en_mask                                       (0x00000001)
#define  ME_ME_BIST_CTRL1_me0_drf_bist_en(data)                                  (0x00000008&((data)<<3))
#define  ME_ME_BIST_CTRL1_me1_drf_bist_en(data)                                  (0x00000004&((data)<<2))
#define  ME_ME_BIST_CTRL1_me0_bist_en(data)                                      (0x00000002&((data)<<1))
#define  ME_ME_BIST_CTRL1_me1_bist_en(data)                                      (0x00000001&(data))
#define  ME_ME_BIST_CTRL1_get_me0_drf_bist_en(data)                              ((0x00000008&(data))>>3)
#define  ME_ME_BIST_CTRL1_get_me1_drf_bist_en(data)                              ((0x00000004&(data))>>2)
#define  ME_ME_BIST_CTRL1_get_me0_bist_en(data)                                  ((0x00000002&(data))>>1)
#define  ME_ME_BIST_CTRL1_get_me1_bist_en(data)                                  (0x00000001&(data))

#define  ME_ME_BIST_CTRL2                                                        0x18009098
#define  ME_ME_BIST_CTRL2_reg_addr                                               "0xB8009098"
#define  ME_ME_BIST_CTRL2_reg                                                    0xB8009098
#define  ME_ME_BIST_CTRL2_inst_addr                                              "0x0015"
#define  set_ME_ME_BIST_CTRL2_reg(data)                                          (*((volatile unsigned int*)ME_ME_BIST_CTRL2_reg)=data)
#define  get_ME_ME_BIST_CTRL2_reg                                                (*((volatile unsigned int*)ME_ME_BIST_CTRL2_reg))
#define  ME_ME_BIST_CTRL2_me0_drf_test_resume_shift                              (1)
#define  ME_ME_BIST_CTRL2_me1_drf_test_resume_shift                              (0)
#define  ME_ME_BIST_CTRL2_me0_drf_test_resume_mask                               (0x00000002)
#define  ME_ME_BIST_CTRL2_me1_drf_test_resume_mask                               (0x00000001)
#define  ME_ME_BIST_CTRL2_me0_drf_test_resume(data)                              (0x00000002&((data)<<1))
#define  ME_ME_BIST_CTRL2_me1_drf_test_resume(data)                              (0x00000001&(data))
#define  ME_ME_BIST_CTRL2_get_me0_drf_test_resume(data)                          ((0x00000002&(data))>>1)
#define  ME_ME_BIST_CTRL2_get_me1_drf_test_resume(data)                          (0x00000001&(data))

#define  ME_ME_BIST_RSLT1                                                        0x1800909C
#define  ME_ME_BIST_RSLT1_reg_addr                                               "0xB800909C"
#define  ME_ME_BIST_RSLT1_reg                                                    0xB800909C
#define  ME_ME_BIST_RSLT1_inst_addr                                              "0x0016"
#define  set_ME_ME_BIST_RSLT1_reg(data)                                          (*((volatile unsigned int*)ME_ME_BIST_RSLT1_reg)=data)
#define  get_ME_ME_BIST_RSLT1_reg                                                (*((volatile unsigned int*)ME_ME_BIST_RSLT1_reg))
#define  ME_ME_BIST_RSLT1_drf_start_pause1_shift                                 (5)
#define  ME_ME_BIST_RSLT1_drf_start_pause0_shift                                 (4)
#define  ME_ME_BIST_RSLT1_drf_done1_shift                                        (3)
#define  ME_ME_BIST_RSLT1_drf_done0_shift                                        (2)
#define  ME_ME_BIST_RSLT1_bist_done1_shift                                       (1)
#define  ME_ME_BIST_RSLT1_bist_done0_shift                                       (0)
#define  ME_ME_BIST_RSLT1_drf_start_pause1_mask                                  (0x00000020)
#define  ME_ME_BIST_RSLT1_drf_start_pause0_mask                                  (0x00000010)
#define  ME_ME_BIST_RSLT1_drf_done1_mask                                         (0x00000008)
#define  ME_ME_BIST_RSLT1_drf_done0_mask                                         (0x00000004)
#define  ME_ME_BIST_RSLT1_bist_done1_mask                                        (0x00000002)
#define  ME_ME_BIST_RSLT1_bist_done0_mask                                        (0x00000001)
#define  ME_ME_BIST_RSLT1_drf_start_pause1(data)                                 (0x00000020&((data)<<5))
#define  ME_ME_BIST_RSLT1_drf_start_pause0(data)                                 (0x00000010&((data)<<4))
#define  ME_ME_BIST_RSLT1_drf_done1(data)                                        (0x00000008&((data)<<3))
#define  ME_ME_BIST_RSLT1_drf_done0(data)                                        (0x00000004&((data)<<2))
#define  ME_ME_BIST_RSLT1_bist_done1(data)                                       (0x00000002&((data)<<1))
#define  ME_ME_BIST_RSLT1_bist_done0(data)                                       (0x00000001&(data))
#define  ME_ME_BIST_RSLT1_get_drf_start_pause1(data)                             ((0x00000020&(data))>>5)
#define  ME_ME_BIST_RSLT1_get_drf_start_pause0(data)                             ((0x00000010&(data))>>4)
#define  ME_ME_BIST_RSLT1_get_drf_done1(data)                                    ((0x00000008&(data))>>3)
#define  ME_ME_BIST_RSLT1_get_drf_done0(data)                                    ((0x00000004&(data))>>2)
#define  ME_ME_BIST_RSLT1_get_bist_done1(data)                                   ((0x00000002&(data))>>1)
#define  ME_ME_BIST_RSLT1_get_bist_done0(data)                                   (0x00000001&(data))

#define  ME_ME_BIST_RSLT2                                                        0x180090A0
#define  ME_ME_BIST_RSLT2_reg_addr                                               "0xB80090A0"
#define  ME_ME_BIST_RSLT2_reg                                                    0xB80090A0
#define  ME_ME_BIST_RSLT2_inst_addr                                              "0x0017"
#define  set_ME_ME_BIST_RSLT2_reg(data)                                          (*((volatile unsigned int*)ME_ME_BIST_RSLT2_reg)=data)
#define  get_ME_ME_BIST_RSLT2_reg                                                (*((volatile unsigned int*)ME_ME_BIST_RSLT2_reg))
#define  ME_ME_BIST_RSLT2_me_drf_fail_group_1_shift                              (3)
#define  ME_ME_BIST_RSLT2_me_drf_fail_group_0_shift                              (2)
#define  ME_ME_BIST_RSLT2_me_bist_fail_group_1_shift                             (1)
#define  ME_ME_BIST_RSLT2_me_bist_fail_group_0_shift                             (0)
#define  ME_ME_BIST_RSLT2_me_drf_fail_group_1_mask                               (0x00000008)
#define  ME_ME_BIST_RSLT2_me_drf_fail_group_0_mask                               (0x00000004)
#define  ME_ME_BIST_RSLT2_me_bist_fail_group_1_mask                              (0x00000002)
#define  ME_ME_BIST_RSLT2_me_bist_fail_group_0_mask                              (0x00000001)
#define  ME_ME_BIST_RSLT2_me_drf_fail_group_1(data)                              (0x00000008&((data)<<3))
#define  ME_ME_BIST_RSLT2_me_drf_fail_group_0(data)                              (0x00000004&((data)<<2))
#define  ME_ME_BIST_RSLT2_me_bist_fail_group_1(data)                             (0x00000002&((data)<<1))
#define  ME_ME_BIST_RSLT2_me_bist_fail_group_0(data)                             (0x00000001&(data))
#define  ME_ME_BIST_RSLT2_get_me_drf_fail_group_1(data)                          ((0x00000008&(data))>>3)
#define  ME_ME_BIST_RSLT2_get_me_drf_fail_group_0(data)                          ((0x00000004&(data))>>2)
#define  ME_ME_BIST_RSLT2_get_me_bist_fail_group_1(data)                         ((0x00000002&(data))>>1)
#define  ME_ME_BIST_RSLT2_get_me_bist_fail_group_0(data)                         (0x00000001&(data))

#define  ME_ME_BIST0_ST                                                          0x180090A4
#define  ME_ME_BIST0_ST_reg_addr                                                 "0xB80090A4"
#define  ME_ME_BIST0_ST_reg                                                      0xB80090A4
#define  ME_ME_BIST0_ST_inst_addr                                                "0x0018"
#define  set_ME_ME_BIST0_ST_reg(data)                                            (*((volatile unsigned int*)ME_ME_BIST0_ST_reg)=data)
#define  get_ME_ME_BIST0_ST_reg                                                  (*((volatile unsigned int*)ME_ME_BIST0_ST_reg))
#define  ME_ME_BIST0_ST_bist_fail9_shift                                         (9)
#define  ME_ME_BIST0_ST_bist_fail8_shift                                         (8)
#define  ME_ME_BIST0_ST_bist_fail7_shift                                         (7)
#define  ME_ME_BIST0_ST_bist_fail6_shift                                         (6)
#define  ME_ME_BIST0_ST_bist_fail5_shift                                         (5)
#define  ME_ME_BIST0_ST_bist_fail4_shift                                         (4)
#define  ME_ME_BIST0_ST_bist_fail3_shift                                         (3)
#define  ME_ME_BIST0_ST_bist_fail2_shift                                         (2)
#define  ME_ME_BIST0_ST_bist_fail1_shift                                         (1)
#define  ME_ME_BIST0_ST_bist_fail0_shift                                         (0)
#define  ME_ME_BIST0_ST_bist_fail9_mask                                          (0x00000200)
#define  ME_ME_BIST0_ST_bist_fail8_mask                                          (0x00000100)
#define  ME_ME_BIST0_ST_bist_fail7_mask                                          (0x00000080)
#define  ME_ME_BIST0_ST_bist_fail6_mask                                          (0x00000040)
#define  ME_ME_BIST0_ST_bist_fail5_mask                                          (0x00000020)
#define  ME_ME_BIST0_ST_bist_fail4_mask                                          (0x00000010)
#define  ME_ME_BIST0_ST_bist_fail3_mask                                          (0x00000008)
#define  ME_ME_BIST0_ST_bist_fail2_mask                                          (0x00000004)
#define  ME_ME_BIST0_ST_bist_fail1_mask                                          (0x00000002)
#define  ME_ME_BIST0_ST_bist_fail0_mask                                          (0x00000001)
#define  ME_ME_BIST0_ST_bist_fail9(data)                                         (0x00000200&((data)<<9))
#define  ME_ME_BIST0_ST_bist_fail8(data)                                         (0x00000100&((data)<<8))
#define  ME_ME_BIST0_ST_bist_fail7(data)                                         (0x00000080&((data)<<7))
#define  ME_ME_BIST0_ST_bist_fail6(data)                                         (0x00000040&((data)<<6))
#define  ME_ME_BIST0_ST_bist_fail5(data)                                         (0x00000020&((data)<<5))
#define  ME_ME_BIST0_ST_bist_fail4(data)                                         (0x00000010&((data)<<4))
#define  ME_ME_BIST0_ST_bist_fail3(data)                                         (0x00000008&((data)<<3))
#define  ME_ME_BIST0_ST_bist_fail2(data)                                         (0x00000004&((data)<<2))
#define  ME_ME_BIST0_ST_bist_fail1(data)                                         (0x00000002&((data)<<1))
#define  ME_ME_BIST0_ST_bist_fail0(data)                                         (0x00000001&(data))
#define  ME_ME_BIST0_ST_get_bist_fail9(data)                                     ((0x00000200&(data))>>9)
#define  ME_ME_BIST0_ST_get_bist_fail8(data)                                     ((0x00000100&(data))>>8)
#define  ME_ME_BIST0_ST_get_bist_fail7(data)                                     ((0x00000080&(data))>>7)
#define  ME_ME_BIST0_ST_get_bist_fail6(data)                                     ((0x00000040&(data))>>6)
#define  ME_ME_BIST0_ST_get_bist_fail5(data)                                     ((0x00000020&(data))>>5)
#define  ME_ME_BIST0_ST_get_bist_fail4(data)                                     ((0x00000010&(data))>>4)
#define  ME_ME_BIST0_ST_get_bist_fail3(data)                                     ((0x00000008&(data))>>3)
#define  ME_ME_BIST0_ST_get_bist_fail2(data)                                     ((0x00000004&(data))>>2)
#define  ME_ME_BIST0_ST_get_bist_fail1(data)                                     ((0x00000002&(data))>>1)
#define  ME_ME_BIST0_ST_get_bist_fail0(data)                                     (0x00000001&(data))

#define  ME_ME_DRF0_ST                                                           0x180090A8
#define  ME_ME_DRF0_ST_reg_addr                                                  "0xB80090A8"
#define  ME_ME_DRF0_ST_reg                                                       0xB80090A8
#define  ME_ME_DRF0_ST_inst_addr                                                 "0x0019"
#define  set_ME_ME_DRF0_ST_reg(data)                                             (*((volatile unsigned int*)ME_ME_DRF0_ST_reg)=data)
#define  get_ME_ME_DRF0_ST_reg                                                   (*((volatile unsigned int*)ME_ME_DRF0_ST_reg))
#define  ME_ME_DRF0_ST_drf_fail9_shift                                           (9)
#define  ME_ME_DRF0_ST_drf_fail8_shift                                           (8)
#define  ME_ME_DRF0_ST_drf_fail7_shift                                           (7)
#define  ME_ME_DRF0_ST_drf_fail6_shift                                           (6)
#define  ME_ME_DRF0_ST_drf_fail5_shift                                           (5)
#define  ME_ME_DRF0_ST_drf_fail4_shift                                           (4)
#define  ME_ME_DRF0_ST_drf_fail3_shift                                           (3)
#define  ME_ME_DRF0_ST_drf_fail2_shift                                           (2)
#define  ME_ME_DRF0_ST_drf_fail1_shift                                           (1)
#define  ME_ME_DRF0_ST_drf_fail0_shift                                           (0)
#define  ME_ME_DRF0_ST_drf_fail9_mask                                            (0x00000200)
#define  ME_ME_DRF0_ST_drf_fail8_mask                                            (0x00000100)
#define  ME_ME_DRF0_ST_drf_fail7_mask                                            (0x00000080)
#define  ME_ME_DRF0_ST_drf_fail6_mask                                            (0x00000040)
#define  ME_ME_DRF0_ST_drf_fail5_mask                                            (0x00000020)
#define  ME_ME_DRF0_ST_drf_fail4_mask                                            (0x00000010)
#define  ME_ME_DRF0_ST_drf_fail3_mask                                            (0x00000008)
#define  ME_ME_DRF0_ST_drf_fail2_mask                                            (0x00000004)
#define  ME_ME_DRF0_ST_drf_fail1_mask                                            (0x00000002)
#define  ME_ME_DRF0_ST_drf_fail0_mask                                            (0x00000001)
#define  ME_ME_DRF0_ST_drf_fail9(data)                                           (0x00000200&((data)<<9))
#define  ME_ME_DRF0_ST_drf_fail8(data)                                           (0x00000100&((data)<<8))
#define  ME_ME_DRF0_ST_drf_fail7(data)                                           (0x00000080&((data)<<7))
#define  ME_ME_DRF0_ST_drf_fail6(data)                                           (0x00000040&((data)<<6))
#define  ME_ME_DRF0_ST_drf_fail5(data)                                           (0x00000020&((data)<<5))
#define  ME_ME_DRF0_ST_drf_fail4(data)                                           (0x00000010&((data)<<4))
#define  ME_ME_DRF0_ST_drf_fail3(data)                                           (0x00000008&((data)<<3))
#define  ME_ME_DRF0_ST_drf_fail2(data)                                           (0x00000004&((data)<<2))
#define  ME_ME_DRF0_ST_drf_fail1(data)                                           (0x00000002&((data)<<1))
#define  ME_ME_DRF0_ST_drf_fail0(data)                                           (0x00000001&(data))
#define  ME_ME_DRF0_ST_get_drf_fail9(data)                                       ((0x00000200&(data))>>9)
#define  ME_ME_DRF0_ST_get_drf_fail8(data)                                       ((0x00000100&(data))>>8)
#define  ME_ME_DRF0_ST_get_drf_fail7(data)                                       ((0x00000080&(data))>>7)
#define  ME_ME_DRF0_ST_get_drf_fail6(data)                                       ((0x00000040&(data))>>6)
#define  ME_ME_DRF0_ST_get_drf_fail5(data)                                       ((0x00000020&(data))>>5)
#define  ME_ME_DRF0_ST_get_drf_fail4(data)                                       ((0x00000010&(data))>>4)
#define  ME_ME_DRF0_ST_get_drf_fail3(data)                                       ((0x00000008&(data))>>3)
#define  ME_ME_DRF0_ST_get_drf_fail2(data)                                       ((0x00000004&(data))>>2)
#define  ME_ME_DRF0_ST_get_drf_fail1(data)                                       ((0x00000002&(data))>>1)
#define  ME_ME_DRF0_ST_get_drf_fail0(data)                                       (0x00000001&(data))

#define  ME_ME_BIST1_ST                                                          0x180090AC
#define  ME_ME_BIST1_ST_reg_addr                                                 "0xB80090AC"
#define  ME_ME_BIST1_ST_reg                                                      0xB80090AC
#define  ME_ME_BIST1_ST_inst_addr                                                "0x001A"
#define  set_ME_ME_BIST1_ST_reg(data)                                            (*((volatile unsigned int*)ME_ME_BIST1_ST_reg)=data)
#define  get_ME_ME_BIST1_ST_reg                                                  (*((volatile unsigned int*)ME_ME_BIST1_ST_reg))
#define  ME_ME_BIST1_ST_bist_fail2_shift                                         (2)
#define  ME_ME_BIST1_ST_bist_fail1_shift                                         (1)
#define  ME_ME_BIST1_ST_bist_fail0_shift                                         (0)
#define  ME_ME_BIST1_ST_bist_fail2_mask                                          (0x00000004)
#define  ME_ME_BIST1_ST_bist_fail1_mask                                          (0x00000002)
#define  ME_ME_BIST1_ST_bist_fail0_mask                                          (0x00000001)
#define  ME_ME_BIST1_ST_bist_fail2(data)                                         (0x00000004&((data)<<2))
#define  ME_ME_BIST1_ST_bist_fail1(data)                                         (0x00000002&((data)<<1))
#define  ME_ME_BIST1_ST_bist_fail0(data)                                         (0x00000001&(data))
#define  ME_ME_BIST1_ST_get_bist_fail2(data)                                     ((0x00000004&(data))>>2)
#define  ME_ME_BIST1_ST_get_bist_fail1(data)                                     ((0x00000002&(data))>>1)
#define  ME_ME_BIST1_ST_get_bist_fail0(data)                                     (0x00000001&(data))

#define  ME_ME_DRF1_ST                                                           0x180090B0
#define  ME_ME_DRF1_ST_reg_addr                                                  "0xB80090B0"
#define  ME_ME_DRF1_ST_reg                                                       0xB80090B0
#define  ME_ME_DRF1_ST_inst_addr                                                 "0x001B"
#define  set_ME_ME_DRF1_ST_reg(data)                                             (*((volatile unsigned int*)ME_ME_DRF1_ST_reg)=data)
#define  get_ME_ME_DRF1_ST_reg                                                   (*((volatile unsigned int*)ME_ME_DRF1_ST_reg))
#define  ME_ME_DRF1_ST_drf_fail2_shift                                           (2)
#define  ME_ME_DRF1_ST_drf_fail1_shift                                           (1)
#define  ME_ME_DRF1_ST_drf_fail0_shift                                           (0)
#define  ME_ME_DRF1_ST_drf_fail2_mask                                            (0x00000004)
#define  ME_ME_DRF1_ST_drf_fail1_mask                                            (0x00000002)
#define  ME_ME_DRF1_ST_drf_fail0_mask                                            (0x00000001)
#define  ME_ME_DRF1_ST_drf_fail2(data)                                           (0x00000004&((data)<<2))
#define  ME_ME_DRF1_ST_drf_fail1(data)                                           (0x00000002&((data)<<1))
#define  ME_ME_DRF1_ST_drf_fail0(data)                                           (0x00000001&(data))
#define  ME_ME_DRF1_ST_get_drf_fail2(data)                                       ((0x00000004&(data))>>2)
#define  ME_ME_DRF1_ST_get_drf_fail1(data)                                       ((0x00000002&(data))>>1)
#define  ME_ME_DRF1_ST_get_drf_fail0(data)                                       (0x00000001&(data))

#define  ME_ME_ASYNC                                                             0x180090B4
#define  ME_ME_ASYNC_reg_addr                                                    "0xB80090B4"
#define  ME_ME_ASYNC_reg                                                         0xB80090B4
#define  ME_ME_ASYNC_inst_addr                                                   "0x001C"
#define  set_ME_ME_ASYNC_reg(data)                                               (*((volatile unsigned int*)ME_ME_ASYNC_reg)=data)
#define  get_ME_ME_ASYNC_reg                                                     (*((volatile unsigned int*)ME_ME_ASYNC_reg))
#define  ME_ME_ASYNC_async_wait_cycle_shift                                      (0)
#define  ME_ME_ASYNC_async_wait_cycle_mask                                       (0x0000001F)
#define  ME_ME_ASYNC_async_wait_cycle(data)                                      (0x0000001F&(data))
#define  ME_ME_ASYNC_get_async_wait_cycle(data)                                  (0x0000001F&(data))

#define  ME_ME_CLK_CTRL                                                          0x180090B8
#define  ME_ME_CLK_CTRL_reg_addr                                                 "0xB80090B8"
#define  ME_ME_CLK_CTRL_reg                                                      0xB80090B8
#define  ME_ME_CLK_CTRL_inst_addr                                                "0x001D"
#define  set_ME_ME_CLK_CTRL_reg(data)                                            (*((volatile unsigned int*)ME_ME_CLK_CTRL_reg)=data)
#define  get_ME_ME_CLK_CTRL_reg                                                  (*((volatile unsigned int*)ME_ME_CLK_CTRL_reg))
#define  ME_ME_CLK_CTRL_clk_gate_en_shift                                        (0)
#define  ME_ME_CLK_CTRL_clk_gate_en_mask                                         (0x0000000F)
#define  ME_ME_CLK_CTRL_clk_gate_en(data)                                        (0x0000000F&(data))
#define  ME_ME_CLK_CTRL_get_clk_gate_en(data)                                    (0x0000000F&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======ME register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  err:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  mbl1:1;
        RBus_UInt32  mbl0:1;
        RBus_UInt32  ints:1;
        RBus_UInt32  inte:1;
        RBus_UInt32  disable_mp:1;
        RBus_UInt32  tw:1;
        RBus_UInt32  tms:1;
        RBus_UInt32  tbs:1;
        RBus_UInt32  go:1;
        RBus_UInt32  write_data:1;
    };
}me_me_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}me_me_cmdaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}me_me_rltaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  fld:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ti:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bi:7;
    };
}me_me_tseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  y:11;
        RBus_UInt32  xinc:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  x:11;
    };
}me_me_tsetb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  fld:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  ti:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bi:7;
    };
}me_me_rseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvys:2;
        RBus_UInt32  res1:6;
        RBus_UInt32  mvxs:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  mvx:8;
        RBus_UInt32  mvy:8;
    };
}me_me_rsetb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  y:11;
        RBus_UInt32  xinc:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  x:11;
    };
}me_me_rsetc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  rh:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  rw:11;
    };
}me_me_rsetd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tsy:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  tsx:11;
    };
}me_me_rsete_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tey:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  tex:11;
    };
}me_me_rsetf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  bsy:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  bsx:11;
    };
}me_me_rsetg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  bey:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  bex:11;
    };
}me_me_rseth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stage:1;
        RBus_UInt32  half:2;
        RBus_UInt32  mvce:1;
        RBus_UInt32  hdrlt:1;
        RBus_UInt32  mvcfp:3;
        RBus_UInt32  mvcf:8;
        RBus_UInt32  zmvp:1;
        RBus_UInt32  hdsad:1;
        RBus_UInt32  can:2;
        RBus_UInt32  bk8x8:1;
        RBus_UInt32  bscale:3;
        RBus_UInt32  zmvb:8;
    };
}me_me_mseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvcb:8;
        RBus_UInt32  mvct:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  ryadj:1;
        RBus_UInt32  ry:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  rxadj:1;
        RBus_UInt32  rx:6;
    };
}me_me_msetb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  sel1:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sel0:3;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  enable:1;
    };
}me_me_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  me_int_vcpu_en:1;
        RBus_UInt32  me_int_vcpu2_en:1;
    };
}me_me_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  ls:2;
        RBus_UInt32  rme:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_0:1;
    };
}me_me_sram_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  me0_drf_bist_en:1;
        RBus_UInt32  me1_drf_bist_en:1;
        RBus_UInt32  me0_bist_en:1;
        RBus_UInt32  me1_bist_en:1;
    };
}me_me_bist_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  me0_drf_test_resume:1;
        RBus_UInt32  me1_drf_test_resume:1;
    };
}me_me_bist_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  drf_start_pause1:1;
        RBus_UInt32  drf_start_pause0:1;
        RBus_UInt32  drf_done1:1;
        RBus_UInt32  drf_done0:1;
        RBus_UInt32  bist_done1:1;
        RBus_UInt32  bist_done0:1;
    };
}me_me_bist_rslt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  me_drf_fail_group_1:1;
        RBus_UInt32  me_drf_fail_group_0:1;
        RBus_UInt32  me_bist_fail_group_1:1;
        RBus_UInt32  me_bist_fail_group_0:1;
    };
}me_me_bist_rslt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  bist_fail9:1;
        RBus_UInt32  bist_fail8:1;
        RBus_UInt32  bist_fail7:1;
        RBus_UInt32  bist_fail6:1;
        RBus_UInt32  bist_fail5:1;
        RBus_UInt32  bist_fail4:1;
        RBus_UInt32  bist_fail3:1;
        RBus_UInt32  bist_fail2:1;
        RBus_UInt32  bist_fail1:1;
        RBus_UInt32  bist_fail0:1;
    };
}me_me_bist0_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  drf_fail9:1;
        RBus_UInt32  drf_fail8:1;
        RBus_UInt32  drf_fail7:1;
        RBus_UInt32  drf_fail6:1;
        RBus_UInt32  drf_fail5:1;
        RBus_UInt32  drf_fail4:1;
        RBus_UInt32  drf_fail3:1;
        RBus_UInt32  drf_fail2:1;
        RBus_UInt32  drf_fail1:1;
        RBus_UInt32  drf_fail0:1;
    };
}me_me_drf0_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  bist_fail2:1;
        RBus_UInt32  bist_fail1:1;
        RBus_UInt32  bist_fail0:1;
    };
}me_me_bist1_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  drf_fail2:1;
        RBus_UInt32  drf_fail1:1;
        RBus_UInt32  drf_fail0:1;
    };
}me_me_drf1_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  async_wait_cycle:5;
    };
}me_me_async_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  clk_gate_en:4;
    };
}me_me_clk_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======ME register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  write_data:1;
        RBus_UInt32  go:1;
        RBus_UInt32  tbs:1;
        RBus_UInt32  tms:1;
        RBus_UInt32  tw:1;
        RBus_UInt32  disable_mp:1;
        RBus_UInt32  inte:1;
        RBus_UInt32  ints:1;
        RBus_UInt32  mbl0:1;
        RBus_UInt32  mbl1:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  err:1;
        RBus_UInt32  res2:11;
    };
}me_me_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}me_me_cmdaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  addr:32;
    };
}me_me_rltaddr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bi:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ti:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  fld:1;
        RBus_UInt32  res3:15;
    };
}me_me_tseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  xinc:4;
        RBus_UInt32  y:11;
        RBus_UInt32  res2:5;
    };
}me_me_tsetb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bi:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ti:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  fld:1;
        RBus_UInt32  res3:15;
    };
}me_me_rseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mvy:8;
        RBus_UInt32  mvx:8;
        RBus_UInt32  res1:6;
        RBus_UInt32  mvxs:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  mvys:2;
    };
}me_me_rsetb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  x:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  xinc:4;
        RBus_UInt32  y:11;
        RBus_UInt32  res2:5;
    };
}me_me_rsetc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rw:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  rh:11;
        RBus_UInt32  res2:5;
    };
}me_me_rsetd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tsx:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  tsy:11;
        RBus_UInt32  res2:5;
    };
}me_me_rsete_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tex:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  tey:11;
        RBus_UInt32  res2:5;
    };
}me_me_rsetf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bsx:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  bsy:11;
        RBus_UInt32  res2:5;
    };
}me_me_rsetg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bex:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  bey:11;
        RBus_UInt32  res2:5;
    };
}me_me_rseth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zmvb:8;
        RBus_UInt32  bscale:3;
        RBus_UInt32  bk8x8:1;
        RBus_UInt32  can:2;
        RBus_UInt32  hdsad:1;
        RBus_UInt32  zmvp:1;
        RBus_UInt32  mvcf:8;
        RBus_UInt32  mvcfp:3;
        RBus_UInt32  hdrlt:1;
        RBus_UInt32  mvce:1;
        RBus_UInt32  half:2;
        RBus_UInt32  stage:1;
    };
}me_me_mseta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rx:6;
        RBus_UInt32  rxadj:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ry:6;
        RBus_UInt32  ryadj:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  mvct:8;
        RBus_UInt32  mvcb:8;
    };
}me_me_msetb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  write_enable1:1;
        RBus_UInt32  sel0:3;
        RBus_UInt32  write_enable2:1;
        RBus_UInt32  sel1:3;
        RBus_UInt32  write_enable3:1;
        RBus_UInt32  res1:22;
    };
}me_me_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  me_int_vcpu2_en:1;
        RBus_UInt32  me_int_vcpu_en:1;
        RBus_UInt32  res1:30;
    };
}me_me_int_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:1;
        RBus_UInt32  rm_1:1;
        RBus_UInt32  rm_2:1;
        RBus_UInt32  rm_3:1;
        RBus_UInt32  rme:1;
        RBus_UInt32  ls:2;
        RBus_UInt32  res1:25;
    };
}me_me_sram_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  me1_bist_en:1;
        RBus_UInt32  me0_bist_en:1;
        RBus_UInt32  me1_drf_bist_en:1;
        RBus_UInt32  me0_drf_bist_en:1;
        RBus_UInt32  res1:28;
    };
}me_me_bist_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  me1_drf_test_resume:1;
        RBus_UInt32  me0_drf_test_resume:1;
        RBus_UInt32  res1:30;
    };
}me_me_bist_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done0:1;
        RBus_UInt32  bist_done1:1;
        RBus_UInt32  drf_done0:1;
        RBus_UInt32  drf_done1:1;
        RBus_UInt32  drf_start_pause0:1;
        RBus_UInt32  drf_start_pause1:1;
        RBus_UInt32  res1:26;
    };
}me_me_bist_rslt1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  me_bist_fail_group_0:1;
        RBus_UInt32  me_bist_fail_group_1:1;
        RBus_UInt32  me_drf_fail_group_0:1;
        RBus_UInt32  me_drf_fail_group_1:1;
        RBus_UInt32  res1:28;
    };
}me_me_bist_rslt2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail0:1;
        RBus_UInt32  bist_fail1:1;
        RBus_UInt32  bist_fail2:1;
        RBus_UInt32  bist_fail3:1;
        RBus_UInt32  bist_fail4:1;
        RBus_UInt32  bist_fail5:1;
        RBus_UInt32  bist_fail6:1;
        RBus_UInt32  bist_fail7:1;
        RBus_UInt32  bist_fail8:1;
        RBus_UInt32  bist_fail9:1;
        RBus_UInt32  res1:22;
    };
}me_me_bist0_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail0:1;
        RBus_UInt32  drf_fail1:1;
        RBus_UInt32  drf_fail2:1;
        RBus_UInt32  drf_fail3:1;
        RBus_UInt32  drf_fail4:1;
        RBus_UInt32  drf_fail5:1;
        RBus_UInt32  drf_fail6:1;
        RBus_UInt32  drf_fail7:1;
        RBus_UInt32  drf_fail8:1;
        RBus_UInt32  drf_fail9:1;
        RBus_UInt32  res1:22;
    };
}me_me_drf0_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail0:1;
        RBus_UInt32  bist_fail1:1;
        RBus_UInt32  bist_fail2:1;
        RBus_UInt32  res1:29;
    };
}me_me_bist1_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail0:1;
        RBus_UInt32  drf_fail1:1;
        RBus_UInt32  drf_fail2:1;
        RBus_UInt32  res1:29;
    };
}me_me_drf1_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  async_wait_cycle:5;
        RBus_UInt32  res1:27;
    };
}me_me_async_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  clk_gate_en:4;
        RBus_UInt32  res1:28;
    };
}me_me_clk_ctrl_RBUS;




#endif 


#endif 
