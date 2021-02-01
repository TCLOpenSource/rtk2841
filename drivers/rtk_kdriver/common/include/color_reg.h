/**
* @file Mac5-DesignSpec-D-Domain_DCTI_DLTI
* RBus systemc program.
*
* @author RS_MM2_SD
* @email mm_mm2_rd_sw_kernel@realtek.com
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_REG_H_
#define _RBUS_COLOR_REG_H_

#include "rbus_types.h"



//  COLOR Register Address
#define  COLOR_D_VC_Global_CTRL                                                  0x1802A000
#define  COLOR_D_VC_Global_CTRL_reg_addr                                         "0xB802A000"
#define  COLOR_D_VC_Global_CTRL_reg                                              0xB802A000
#define  COLOR_D_VC_Global_CTRL_inst_addr                                        "0x0000"
#define  set_COLOR_D_VC_Global_CTRL_reg(data)                                    (*((volatile unsigned int*)COLOR_D_VC_Global_CTRL_reg)=data)
#define  get_COLOR_D_VC_Global_CTRL_reg                                          (*((volatile unsigned int*)COLOR_D_VC_Global_CTRL_reg))
#define  COLOR_D_VC_Global_CTRL_dummy_30_27_shift                                (27)
#define  COLOR_D_VC_Global_CTRL_write_enable_11_shift                            (26)
#define  COLOR_D_VC_Global_CTRL_m_vc_en_shift                                    (25)
#define  COLOR_D_VC_Global_CTRL_write_enable_12_shift                            (22)
#define  COLOR_D_VC_Global_CTRL_m_lc_comp_en_shift                               (21)
#define  COLOR_D_VC_Global_CTRL_write_enable_9_shift                             (20)
#define  COLOR_D_VC_Global_CTRL_icm_dcc_swap_shift                               (19)
#define  COLOR_D_VC_Global_CTRL_write_enable_6_shift                             (11)
#define  COLOR_D_VC_Global_CTRL_reg_bypass_pq_shift                              (10)
#define  COLOR_D_VC_Global_CTRL_write_enable_5_shift                             (9)
#define  COLOR_D_VC_Global_CTRL_m_edgesmooth_en_shift                            (8)
#define  COLOR_D_VC_Global_CTRL_write_enable_4_shift                             (7)
#define  COLOR_D_VC_Global_CTRL_m_sharp_en_shift                                 (6)
#define  COLOR_D_VC_Global_CTRL_write_enable_3_shift                             (5)
#define  COLOR_D_VC_Global_CTRL_m_icm_en_shift                                   (4)
#define  COLOR_D_VC_Global_CTRL_write_enable_2_shift                             (3)
#define  COLOR_D_VC_Global_CTRL_m_dcti_en_shift                                  (2)
#define  COLOR_D_VC_Global_CTRL_write_enable_1_shift                             (1)
#define  COLOR_D_VC_Global_CTRL_dcc_en_shift                                     (0)
#define  COLOR_D_VC_Global_CTRL_dummy_30_27_mask                                 (0x78000000)
#define  COLOR_D_VC_Global_CTRL_write_enable_11_mask                             (0x04000000)
#define  COLOR_D_VC_Global_CTRL_m_vc_en_mask                                     (0x02000000)
#define  COLOR_D_VC_Global_CTRL_write_enable_12_mask                             (0x00400000)
#define  COLOR_D_VC_Global_CTRL_m_lc_comp_en_mask                                (0x00200000)
#define  COLOR_D_VC_Global_CTRL_write_enable_9_mask                              (0x00100000)
#define  COLOR_D_VC_Global_CTRL_icm_dcc_swap_mask                                (0x00080000)
#define  COLOR_D_VC_Global_CTRL_write_enable_6_mask                              (0x00000800)
#define  COLOR_D_VC_Global_CTRL_reg_bypass_pq_mask                               (0x00000400)
#define  COLOR_D_VC_Global_CTRL_write_enable_5_mask                              (0x00000200)
#define  COLOR_D_VC_Global_CTRL_m_edgesmooth_en_mask                             (0x00000100)
#define  COLOR_D_VC_Global_CTRL_write_enable_4_mask                              (0x00000080)
#define  COLOR_D_VC_Global_CTRL_m_sharp_en_mask                                  (0x00000040)
#define  COLOR_D_VC_Global_CTRL_write_enable_3_mask                              (0x00000020)
#define  COLOR_D_VC_Global_CTRL_m_icm_en_mask                                    (0x00000010)
#define  COLOR_D_VC_Global_CTRL_write_enable_2_mask                              (0x00000008)
#define  COLOR_D_VC_Global_CTRL_m_dcti_en_mask                                   (0x00000004)
#define  COLOR_D_VC_Global_CTRL_write_enable_1_mask                              (0x00000002)
#define  COLOR_D_VC_Global_CTRL_dcc_en_mask                                      (0x00000001)
#define  COLOR_D_VC_Global_CTRL_dummy_30_27(data)                                (0x78000000&((data)<<27))
#define  COLOR_D_VC_Global_CTRL_write_enable_11(data)                            (0x04000000&((data)<<26))
#define  COLOR_D_VC_Global_CTRL_m_vc_en(data)                                    (0x02000000&((data)<<25))
#define  COLOR_D_VC_Global_CTRL_write_enable_12(data)                            (0x00400000&((data)<<22))
#define  COLOR_D_VC_Global_CTRL_m_lc_comp_en(data)                               (0x00200000&((data)<<21))
#define  COLOR_D_VC_Global_CTRL_write_enable_9(data)                             (0x00100000&((data)<<20))
#define  COLOR_D_VC_Global_CTRL_icm_dcc_swap(data)                               (0x00080000&((data)<<19))
#define  COLOR_D_VC_Global_CTRL_write_enable_6(data)                             (0x00000800&((data)<<11))
#define  COLOR_D_VC_Global_CTRL_reg_bypass_pq(data)                              (0x00000400&((data)<<10))
#define  COLOR_D_VC_Global_CTRL_write_enable_5(data)                             (0x00000200&((data)<<9))
#define  COLOR_D_VC_Global_CTRL_m_edgesmooth_en(data)                            (0x00000100&((data)<<8))
#define  COLOR_D_VC_Global_CTRL_write_enable_4(data)                             (0x00000080&((data)<<7))
#define  COLOR_D_VC_Global_CTRL_m_sharp_en(data)                                 (0x00000040&((data)<<6))
#define  COLOR_D_VC_Global_CTRL_write_enable_3(data)                             (0x00000020&((data)<<5))
#define  COLOR_D_VC_Global_CTRL_m_icm_en(data)                                   (0x00000010&((data)<<4))
#define  COLOR_D_VC_Global_CTRL_write_enable_2(data)                             (0x00000008&((data)<<3))
#define  COLOR_D_VC_Global_CTRL_m_dcti_en(data)                                  (0x00000004&((data)<<2))
#define  COLOR_D_VC_Global_CTRL_write_enable_1(data)                             (0x00000002&((data)<<1))
#define  COLOR_D_VC_Global_CTRL_dcc_en(data)                                     (0x00000001&(data))
#define  COLOR_D_VC_Global_CTRL_get_dummy_30_27(data)                            ((0x78000000&(data))>>27)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_11(data)                        ((0x04000000&(data))>>26)
#define  COLOR_D_VC_Global_CTRL_get_m_vc_en(data)                                ((0x02000000&(data))>>25)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_12(data)                        ((0x00400000&(data))>>22)
#define  COLOR_D_VC_Global_CTRL_get_m_lc_comp_en(data)                           ((0x00200000&(data))>>21)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_9(data)                         ((0x00100000&(data))>>20)
#define  COLOR_D_VC_Global_CTRL_get_icm_dcc_swap(data)                           ((0x00080000&(data))>>19)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_6(data)                         ((0x00000800&(data))>>11)
#define  COLOR_D_VC_Global_CTRL_get_reg_bypass_pq(data)                          ((0x00000400&(data))>>10)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_5(data)                         ((0x00000200&(data))>>9)
#define  COLOR_D_VC_Global_CTRL_get_m_edgesmooth_en(data)                        ((0x00000100&(data))>>8)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_4(data)                         ((0x00000080&(data))>>7)
#define  COLOR_D_VC_Global_CTRL_get_m_sharp_en(data)                             ((0x00000040&(data))>>6)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_3(data)                         ((0x00000020&(data))>>5)
#define  COLOR_D_VC_Global_CTRL_get_m_icm_en(data)                               ((0x00000010&(data))>>4)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_2(data)                         ((0x00000008&(data))>>3)
#define  COLOR_D_VC_Global_CTRL_get_m_dcti_en(data)                              ((0x00000004&(data))>>2)
#define  COLOR_D_VC_Global_CTRL_get_write_enable_1(data)                         ((0x00000002&(data))>>1)
#define  COLOR_D_VC_Global_CTRL_get_dcc_en(data)                                 (0x00000001&(data))

#define  COLOR_D_VC_Global_CTRL_DB                                               0x1802A004
#define  COLOR_D_VC_Global_CTRL_DB_reg_addr                                      "0xB802A004"
#define  COLOR_D_VC_Global_CTRL_DB_reg                                           0xB802A004
#define  COLOR_D_VC_Global_CTRL_DB_inst_addr                                     "0x0001"
#define  set_COLOR_D_VC_Global_CTRL_DB_reg(data)                                 (*((volatile unsigned int*)COLOR_D_VC_Global_CTRL_DB_reg)=data)
#define  get_COLOR_D_VC_Global_CTRL_DB_reg                                       (*((volatile unsigned int*)COLOR_D_VC_Global_CTRL_DB_reg))
#define  COLOR_D_VC_Global_CTRL_DB_db_read_shift                                 (2)
#define  COLOR_D_VC_Global_CTRL_DB_db_en_shift                                   (1)
#define  COLOR_D_VC_Global_CTRL_DB_db_load_shift                                 (0)
#define  COLOR_D_VC_Global_CTRL_DB_db_read_mask                                  (0x00000004)
#define  COLOR_D_VC_Global_CTRL_DB_db_en_mask                                    (0x00000002)
#define  COLOR_D_VC_Global_CTRL_DB_db_load_mask                                  (0x00000001)
#define  COLOR_D_VC_Global_CTRL_DB_db_read(data)                                 (0x00000004&((data)<<2))
#define  COLOR_D_VC_Global_CTRL_DB_db_en(data)                                   (0x00000002&((data)<<1))
#define  COLOR_D_VC_Global_CTRL_DB_db_load(data)                                 (0x00000001&(data))
#define  COLOR_D_VC_Global_CTRL_DB_get_db_read(data)                             ((0x00000004&(data))>>2)
#define  COLOR_D_VC_Global_CTRL_DB_get_db_en(data)                               ((0x00000002&(data))>>1)
#define  COLOR_D_VC_Global_CTRL_DB_get_db_load(data)                             (0x00000001&(data))

#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dummy1802a000_30_27:4;
        RBus_UInt32  write_enable_11:1;
        RBus_UInt32  m_vc_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  write_enable_12:1;
        RBus_UInt32  m_lc_comp_en:1;
        RBus_UInt32  write_enable_9:1;
        RBus_UInt32  icm_dcc_swap:1;
        RBus_UInt32  res3:7;
        RBus_UInt32  write_enable_6:1;
        RBus_UInt32  reg_bypass_pq:1;
        RBus_UInt32  write_enable_5:1;
        RBus_UInt32  m_edgesmooth_en:1;
        RBus_UInt32  write_enable_4:1;
        RBus_UInt32  m_sharp_en:1;
        RBus_UInt32  write_enable_3:1;
        RBus_UInt32  m_icm_en:1;
        RBus_UInt32  write_enable_2:1;
        RBus_UInt32  m_dcti_en:1;
        RBus_UInt32  write_enable_1:1;
        RBus_UInt32  dcc_en:1;
    };
}color_d_vc_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
    };
}color_d_vc_global_ctrl_db_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcc_en:1;
        RBus_UInt32  write_enable_1:1;
        RBus_UInt32  m_dcti_en:1;
        RBus_UInt32  write_enable_2:1;
        RBus_UInt32  m_icm_en:1;
        RBus_UInt32  write_enable_3:1;
        RBus_UInt32  m_sharp_en:1;
        RBus_UInt32  write_enable_4:1;
        RBus_UInt32  m_edgesmooth_en:1;
        RBus_UInt32  write_enable_5:1;
        RBus_UInt32  reg_bypass_pq:1;
        RBus_UInt32  write_enable_6:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  icm_dcc_swap:1;
        RBus_UInt32  write_enable_9:1;
        RBus_UInt32  m_lc_comp_en:1;
        RBus_UInt32  write_enable_12:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  m_vc_en:1;
        RBus_UInt32  write_enable_11:1;
        RBus_UInt32  dummy1802a000_30_27:4;
        RBus_UInt32  res3:1;
    };
}color_d_vc_global_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:29;
    };
}color_d_vc_global_ctrl_db_RBUS;




#endif 


#endif 
