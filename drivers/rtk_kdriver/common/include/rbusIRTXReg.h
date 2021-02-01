/**
* @file rbusIRTXReg.h
* RBus systemc program.
*
* @author Yu-Cheng Huang
* @email timhuang@realtek.com.tw
* @date 2012/7/2
* @version 802
* @ingroup model_rbus
*
*/

#ifndef _RBUS_IRTX_REG_H_
#define _RBUS_IRTX_REG_H_

#include "rbus/rbusTypes.h"




// IRTX Register Address

#define IRTX_IRTX_CTRL0_VADDR                      (0xb801bd00)
#define IRTX_IRTX_CTRL1_VADDR                      (0xb801bd04)
#define IRTX_H_SYNC_TARGET1_VADDR                  (0xb801bd08)
#define IRTX_H_SYNC_TARGET2_VADDR                  (0xb801bd0c)
#define IRTX_SAMPLING_CTRL_VADDR                   (0xb801bd10)
#define IRTX_START_ADDRESS1_VADDR                  (0xb801bd14)
#define IRTX_START_ADDRESS2_VADDR                  (0xb801bd18)
#define IRTX_TRANSITION_MAX1_VADDR                 (0xb801bd1c)
#define IRTX_TRANSITION_MAX2_VADDR                 (0xb801bd20)
#define IRTX_CARRIER_PWM_CTRL_VADDR                (0xb801bd24)
#define IRTX_TX_SET_VADDR                          (0xb801bd28)
#define IRTX_STATUS_VADDR                          (0xb801bd2c)
#define IRTX_FIFO_ST_VADDR                         (0xb801bd30)
#define IRTX_IRTX_FIFO_VADDR                       (0xb801bd34)
#define IRTX_CRC_CTRL_VADDR                        (0xb801bd38)
#define IRTX_CRC_INITIAL_VADDR                     (0xb801bd3c)
#define IRTX_IRTX_BIST_VADDR                       (0xb801bd40)
#define IRTX_CRC_RESULT_VADDR                      (0xb801bd44)
#define IRTX_IRTX_BIST_MODE_VADDR                  (0xb801bd48)
#define IRTX_IRTX_BIST_DONE_VADDR                  (0xb801bd4c)
#define IRTX_IRTX_BIST_FAIL_VADDR                  (0xb801bd50)
#define IRTX_IRTX_DRF_MODE_VADDR                   (0xb801bd54)
#define IRTX_IRTX_DRF_RESUME_VADDR                 (0xb801bd58)
#define IRTX_IRTX_DRF_DONE_VADDR                   (0xb801bd5c)
#define IRTX_IRTX_DRF_PAUSE_VADDR                  (0xb801bd60)
#define IRTX_IRTX_DRF_FAIL_VADDR                   (0xb801bd64)
#define IRTX_IRTX_3D_GLASSES_TX_VADDR              (0xb801bd68)




#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN


//======IRTX register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  res1:21;
        RBus_UInt32  frame_mode:1;
        RBus_UInt32  h_sync_mode_sel:1;
        RBus_UInt32  function_sel:1;
        RBus_UInt32  default_val:1;
        RBus_UInt32  l_r_change:1;
        RBus_UInt32  modulation:1;
        RBus_UInt32  endian:1;
        RBus_UInt32  fifoout_inv:1;
        RBus_UInt32  irtxout_inv:1;
        RBus_UInt32  irtx_en:1;
    };
}irtx_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  immediate_start:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  modulation_len:1;
    };
}irtx_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  counter_target1:12;
    };
}h_sync_target1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  counter_target2:12;
    };
}h_sync_target2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  df:16;
    };
}sampling_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_1:32;
    };
}start_address1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_2:32;
    };
}start_address2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length1:32;
    };
}transition_max1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length2:32;
    };
}transition_max2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pwm_clksrc_div:4;
        RBus_UInt32  pwm_clk_duty:8;
        RBus_UInt32  pwm_clk_div:8;
    };
}carrier_pwm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  emp_en:1;
        RBus_UInt32  l_r_set:1;
    };
}tx_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  l_r_status:1;
        RBus_UInt32  emp_flag:1;
    };
}status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_rst:1;
        RBus_UInt32  res1:17;
        RBus_UInt32  wrp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rdp:6;
    };
}fifo_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}irtx_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_en:1;
        RBus_UInt32  res1:31;
    };
}crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_initial:32;
    };
}crc_initial_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  res2:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  res7:6;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  bist_rstn:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  res10:1;
    };
}irtx_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_mode:1;
    };
}irtx_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_done:1;
    };
}irtx_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  bist_fail:1;
    };
}irtx_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_mode:1;
    };
}irtx_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_resume:1;
    };
}irtx_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_done:1;
    };
}irtx_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_pause:1;
    };
}irtx_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  drf_fail:1;
    };
}irtx_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  irtx_3d_glassesmode_en:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  rotation_num:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  rlg_num:3;
    };
}irtx_3d_glasses_tx_RBUS;





#else //apply LITTLE_ENDIAN


//======IRTX register structure define==========
typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  irtx_en:1;
        RBus_UInt32  irtxout_inv:1;
        RBus_UInt32  fifoout_inv:1;
        RBus_UInt32  endian:1;
        RBus_UInt32  modulation:1;
        RBus_UInt32  l_r_change:1;
        RBus_UInt32  default_val:1;
        RBus_UInt32  function_sel:1;
        RBus_UInt32  h_sync_mode_sel:1;
        RBus_UInt32  frame_mode:1;
        RBus_UInt32  res1:21;
        RBus_UInt32  dma_mode:1;
    };
}irtx_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  modulation_len:1;
        RBus_UInt32  double_buf_en:1;
        RBus_UInt32  res1:29;
        RBus_UInt32  immediate_start:1;
    };
}irtx_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  counter_target1:12;
        RBus_UInt32  res1:20;
    };
}h_sync_target1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  counter_target2:12;
        RBus_UInt32  res1:20;
    };
}h_sync_target2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  df:16;
        RBus_UInt32  res1:16;
    };
}sampling_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_1:32;
    };
}start_address1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  start_addr_2:32;
    };
}start_address2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length1:32;
    };
}transition_max1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_length2:32;
    };
}transition_max2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pwm_clk_div:8;
        RBus_UInt32  pwm_clk_duty:8;
        RBus_UInt32  pwm_clksrc_div:4;
        RBus_UInt32  res1:12;
    };
}carrier_pwm_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  l_r_set:1;
        RBus_UInt32  emp_en:1;
        RBus_UInt32  res1:30;
    };
}tx_set_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emp_flag:1;
        RBus_UInt32  l_r_status:1;
        RBus_UInt32  res1:30;
    };
}status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rdp:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  wrp:6;
        RBus_UInt32  res1:17;
        RBus_UInt32  fifo_rst:1;
    };
}fifo_st_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data:32;
    };
}irtx_fifo_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  crc_en:1;
    };
}crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_initial:32;
    };
}crc_initial_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res10:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  bist_rstn:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  dvse_0:1;
        RBus_UInt32  dvs_0:4;
        RBus_UInt32  res7:6;
        RBus_UInt32  res6:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  res1:12;
    };
}irtx_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_result:32;
    };
}crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_mode:1;
        RBus_UInt32  res1:31;
    };
}irtx_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_done:1;
        RBus_UInt32  res1:31;
    };
}irtx_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail:1;
        RBus_UInt32  res1:31;
    };
}irtx_bist_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_mode:1;
        RBus_UInt32  res1:31;
    };
}irtx_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_resume:1;
        RBus_UInt32  res1:31;
    };
}irtx_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_done:1;
        RBus_UInt32  res1:31;
    };
}irtx_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_pause:1;
        RBus_UInt32  res1:31;
    };
}irtx_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drf_fail:1;
        RBus_UInt32  res1:31;
    };
}irtx_drf_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rlg_num:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  rotation_num:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  irtx_3d_glassesmode_en:1;
        RBus_UInt32  res1:15;
    };
}irtx_3d_glasses_tx_RBUS;


#endif







#endif //_RBUS_IRTX_REG_H_

