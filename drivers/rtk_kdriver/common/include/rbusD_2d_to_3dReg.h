/**
* @file rbusD_2d_to_3dReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014/3/6
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_D_2D_TO_3D_REG_H_
#define _RBUS_D_2D_TO_3D_REG_H_

#include "rbusTypes.h"



//  D_2D_TO_3D Register Address
#define D_2D_TO_3D_D_2D3D_DB_CONTROL_ADDR          (0x18029600)
#define D_2D_TO_3D_D_2D3D_CONTROL_ADDR             (0x18029604)
#define D_2D_TO_3D_D_2D3D_OBJECT1_OPERATION_ADDR   (0x18029608)
#define D_2D_TO_3D_D_2D3D_OBJECT2_OPERATION_ADDR   (0x1802960c)
#define D_2D_TO_3D_D_2D3D_OBJECT3_OPERATION_ADDR   (0x18029610)
#define D_2D_TO_3D_D_2D3D_TILT_OPERATION_ADDR      (0x18029614)
#define D_2D_TO_3D_D_2D3D_B_BORDER_ADDR            (0x18029620)
#define D_2D_TO_3D_D_2D3D_TILT_DEPTH_ADDR          (0x18029630)
#define D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_ADDR      (0x18029634)
#define D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_ADDR      (0x18029638)
#define D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_ADDR      (0x1802963c)
#define D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_ADDR      (0x18029640)
#define D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_ADDR      (0x18029644)
#define D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_ADDR      (0x18029648)
#define D_2D_TO_3D_D_2D3D_DEPTH_FIL_ADDR           (0x18029660)
#define D_2D_TO_3D_D_2D3D_SHIFTER_ADDR             (0x18029664)
#define D_2D_TO_3D_D_2D3D_BOUNDARY_SCALING_ADDR    (0x18029668)
#define D_2D_TO_3D_D_2D3D_HOLE_FILL_ADDR           (0x18029670)
#define D_2D_TO_3D_D_2D3D_DUMMY0_ADDR              (0x18029674)
#define D_2D_TO_3D_D_2D3D_DUMMY1_ADDR              (0x18029678)
#define D_2D_TO_3D_D_2D3D_BIST_ADDR                (0x18029680)
#define D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_ADDR        (0x18029690)
#define D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_ADDR        (0x18029694)

#define  D_2D_TO_3D_D_2D3D_DB_CONTROL_VADDR 		(0xb8029600)
#define  D_2D_TO_3D_D_2D3D_CONTROL_VADDR 		(0xb8029604)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_OPERATION_VADDR 		(0xb8029608)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_OPERATION_VADDR 		(0xb802960c)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_OPERATION_VADDR 		(0xb8029610)
#define  D_2D_TO_3D_D_2D3D_TILT_OPERATION_VADDR 		(0xb8029614)
#define  D_2D_TO_3D_D_2D3D_B_BORDER_VADDR 		(0xb8029620)
#define  D_2D_TO_3D_D_2D3D_TILT_DEPTH_VADDR 		(0xb8029630)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH1_VADDR 		(0xb8029634)
#define  D_2D_TO_3D_D_2D3D_OBJECT1_DEPTH2_VADDR 		(0xb8029638)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH1_VADDR 		(0xb802963c)
#define  D_2D_TO_3D_D_2D3D_OBJECT2_DEPTH2_VADDR 		(0xb8029640)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH1_VADDR 		(0xb8029644)
#define  D_2D_TO_3D_D_2D3D_OBJECT3_DEPTH2_VADDR 		(0xb8029648)
#define  D_2D_TO_3D_D_2D3D_DEPTH_FIL_VADDR 		(0xb8029660)
#define  D_2D_TO_3D_D_2D3D_SHIFTER_VADDR 		(0xb8029664)
#define  D_2D_TO_3D_D_2D3D_BOUNDARY_SCALING_VADDR 		(0xb8029668)
#define  D_2D_TO_3D_D_2D3D_HOLE_FILL_VADDR 		(0xb8029670)
#define  D_2D_TO_3D_D_2D3D_DUMMY0_VADDR 		(0xb8029674)
#define  D_2D_TO_3D_D_2D3D_DUMMY1_VADDR 		(0xb8029678)
#define  D_2D_TO_3D_D_2D3D_BIST_VADDR 		(0xb8029680)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_Y_VADDR 		(0xb8029690)
#define  D_2D_TO_3D_D_2D3D_OUTPUT_FIL_C_VADDR 		(0xb8029694)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======D_2D_TO_3D register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  res1:29;
    };
}d_2d3d_db_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  render_method:1;
        RBus_UInt32  input_sbs_render_mode:1;
        RBus_UInt32  obj_y_src_sel:1;
        RBus_UInt32  output_format:1;
        RBus_UInt32  d_2d3d_depth_frac_en:1;
        RBus_UInt32  depth_debug_mode:1;
        RBus_UInt32  l_frame_shift_en:1;
        RBus_UInt32  r_frame_shift_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  tilt_depth_en:1;
        RBus_UInt32  object3_depth_en:1;
        RBus_UInt32  object2_depth_en:1;
        RBus_UInt32  object1_depth_en:1;
        RBus_UInt32  res2:1;
    };
}d_2d3d_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object1_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object1_offset:9;
        RBus_UInt32  object1_gain:8;
    };
}d_2d3d_object1_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object2_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object2_offset:9;
        RBus_UInt32  object2_gain:8;
    };
}d_2d3d_object2_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  object3_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  object3_offset:9;
        RBus_UInt32  object3_gain:8;
    };
}d_2d3d_object3_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  tilt_thd:8;
        RBus_UInt32  tilt_offset:8;
        RBus_UInt32  tilt_gain:8;
    };
}d_2d3d_tilt_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  border_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  border_den_start:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  border_den_end:12;
    };
}d_2d3d_b_border_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  tilt_depth_step:12;
        RBus_UInt32  res2:8;
        RBus_UInt32  initial_depth:8;
    };
}d_2d3d_tilt_depth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object1_depth_weight1:3;
        RBus_UInt32  object1_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object1_depth_dir:1;
    };
}d_2d3d_object1_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object1_depth_weight3:3;
        RBus_UInt32  object1_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object1_depth_weight2:3;
        RBus_UInt32  object1_depth_ref2:8;
    };
}d_2d3d_object1_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object2_depth_weight1:3;
        RBus_UInt32  object2_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object2_depth_dir:1;
    };
}d_2d3d_object2_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object2_depth_weight3:3;
        RBus_UInt32  object2_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object2_depth_weight2:3;
        RBus_UInt32  object2_depth_ref2:8;
    };
}d_2d3d_object2_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object3_depth_weight1:3;
        RBus_UInt32  object3_depth_ref1:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  object3_depth_dir:1;
    };
}d_2d3d_object3_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  object3_depth_weight3:3;
        RBus_UInt32  object3_depth_ref3:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  object3_depth_weight2:3;
        RBus_UInt32  object3_depth_ref2:8;
    };
}d_2d3d_object3_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  d_2d3d_depth_lpf_c0:4;
        RBus_UInt32  d_2d3d_depth_lpf_c1:4;
        RBus_UInt32  d_2d3d_depth_lpf_c2:4;
        RBus_UInt32  res2:11;
        RBus_UInt32  d_2d3d_depth_lpf_en:1;
    };
}d_2d3d_depth_fil_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  shifter_thd:6;
        RBus_UInt32  shifter_offset:8;
        RBus_UInt32  shifter_gain:8;
    };
}d_2d3d_shifter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dbs_seg_num:2;
        RBus_UInt32  dbs_en:1;
    };
}d_2d3d_boundary_scaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  hf_new_en:1;
        RBus_UInt32  hole_fil_sel:3;
    };
}d_2d3d_hole_fill_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029674_31_0:32;
    };
}d_2d3d_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029678_31_0:32;
    };
}d_2d3d_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  render_2p_drf_bist_fail_1:1;
        RBus_UInt32  render_2p_drf_bist_fail_0:1;
        RBus_UInt32  render_2p_bist_fail_1:1;
        RBus_UInt32  render_2p_bist_fail_0:1;
        RBus_UInt32  render_2p_rmea_1:1;
        RBus_UInt32  render_2p_rmeb_1:1;
        RBus_UInt32  render_2p_rmea_0:1;
        RBus_UInt32  render_2p_rmeb_0:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  render_2p_ls_1:1;
        RBus_UInt32  render_2p_ls_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  render_2p_rma_1:4;
        RBus_UInt32  render_2p_rmb_1:4;
        RBus_UInt32  render_2p_rma_0:4;
        RBus_UInt32  render_2p_rmb_0:4;
    };
}d_2d3d_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c0:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c2:4;
        RBus_UInt32  res2:15;
        RBus_UInt32  d_2d3d_output_lpf_y_en:1;
    };
}d_2d3d_output_fil_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c0:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c2:4;
        RBus_UInt32  res2:15;
        RBus_UInt32  d_2d3d_output_lpf_c_en:1;
    };
}d_2d3d_output_fil_c_RBUS;

#else //apply LITTLE_ENDIAN

//======D_2D_TO_3D register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_read_level:1;
        RBus_UInt32  db_en:1;
    };
}d_2d3d_db_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res2:1;
        RBus_UInt32  object1_depth_en:1;
        RBus_UInt32  object2_depth_en:1;
        RBus_UInt32  object3_depth_en:1;
        RBus_UInt32  tilt_depth_en:1;
        RBus_UInt32  l_flag_inv:1;
        RBus_UInt32  r_frame_shift_en:1;
        RBus_UInt32  l_frame_shift_en:1;
        RBus_UInt32  depth_debug_mode:1;
        RBus_UInt32  d_2d3d_depth_frac_en:1;
        RBus_UInt32  output_format:1;
        RBus_UInt32  obj_y_src_sel:1;
        RBus_UInt32  input_sbs_render_mode:1;
        RBus_UInt32  render_method:1;
        RBus_UInt32  res1:18;
    };
}d_2d3d_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object1_gain:8;
        RBus_UInt32  object1_offset:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  object1_thd:8;
        RBus_UInt32  res1:4;
    };
}d_2d3d_object1_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object2_gain:8;
        RBus_UInt32  object2_offset:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  object2_thd:8;
        RBus_UInt32  res1:4;
    };
}d_2d3d_object2_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object3_gain:8;
        RBus_UInt32  object3_offset:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  object3_thd:8;
        RBus_UInt32  res1:4;
    };
}d_2d3d_object3_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tilt_gain:8;
        RBus_UInt32  tilt_offset:8;
        RBus_UInt32  tilt_thd:8;
        RBus_UInt32  res1:8;
    };
}d_2d3d_tilt_operation_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  border_den_end:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  border_den_start:12;
        RBus_UInt32  res1:3;
        RBus_UInt32  border_en:1;
    };
}d_2d3d_b_border_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  initial_depth:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  tilt_depth_step:12;
        RBus_UInt32  res1:4;
    };
}d_2d3d_tilt_depth_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object1_depth_dir:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  object1_depth_ref1:8;
        RBus_UInt32  object1_depth_weight1:3;
        RBus_UInt32  res1:5;
    };
}d_2d3d_object1_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object1_depth_ref2:8;
        RBus_UInt32  object1_depth_weight2:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  object1_depth_ref3:8;
        RBus_UInt32  object1_depth_weight3:3;
        RBus_UInt32  res1:5;
    };
}d_2d3d_object1_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object2_depth_dir:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  object2_depth_ref1:8;
        RBus_UInt32  object2_depth_weight1:3;
        RBus_UInt32  res1:5;
    };
}d_2d3d_object2_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object2_depth_ref2:8;
        RBus_UInt32  object2_depth_weight2:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  object2_depth_ref3:8;
        RBus_UInt32  object2_depth_weight3:3;
        RBus_UInt32  res1:5;
    };
}d_2d3d_object2_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object3_depth_dir:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  object3_depth_ref1:8;
        RBus_UInt32  object3_depth_weight1:3;
        RBus_UInt32  res1:5;
    };
}d_2d3d_object3_depth1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  object3_depth_ref2:8;
        RBus_UInt32  object3_depth_weight2:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  object3_depth_ref3:8;
        RBus_UInt32  object3_depth_weight3:3;
        RBus_UInt32  res1:5;
    };
}d_2d3d_object3_depth2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_2d3d_depth_lpf_en:1;
        RBus_UInt32  res2:11;
        RBus_UInt32  d_2d3d_depth_lpf_c2:4;
        RBus_UInt32  d_2d3d_depth_lpf_c1:4;
        RBus_UInt32  d_2d3d_depth_lpf_c0:4;
        RBus_UInt32  res1:8;
    };
}d_2d3d_depth_fil_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shifter_gain:8;
        RBus_UInt32  shifter_offset:8;
        RBus_UInt32  shifter_thd:6;
        RBus_UInt32  res1:10;
    };
}d_2d3d_shifter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbs_en:1;
        RBus_UInt32  dbs_seg_num:2;
        RBus_UInt32  res1:29;
    };
}d_2d3d_boundary_scaling_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hole_fil_sel:3;
        RBus_UInt32  hf_new_en:1;
        RBus_UInt32  res1:28;
    };
}d_2d3d_hole_fill_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029674_31_0:32;
    };
}d_2d3d_dummy0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18029678_31_0:32;
    };
}d_2d3d_dummy1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  render_2p_rmb_0:4;
        RBus_UInt32  render_2p_rma_0:4;
        RBus_UInt32  render_2p_rmb_1:4;
        RBus_UInt32  render_2p_rma_1:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  render_2p_ls_0:1;
        RBus_UInt32  render_2p_ls_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  render_2p_rmeb_0:1;
        RBus_UInt32  render_2p_rmea_0:1;
        RBus_UInt32  render_2p_rmeb_1:1;
        RBus_UInt32  render_2p_rmea_1:1;
        RBus_UInt32  render_2p_bist_fail_0:1;
        RBus_UInt32  render_2p_bist_fail_1:1;
        RBus_UInt32  render_2p_drf_bist_fail_0:1;
        RBus_UInt32  render_2p_drf_bist_fail_1:1;
    };
}d_2d3d_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_2d3d_output_lpf_y_en:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  d_2d3d_output_y_lpf_c2:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_y_lpf_c0:4;
        RBus_UInt32  res1:4;
    };
}d_2d3d_output_fil_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  d_2d3d_output_lpf_c_en:1;
        RBus_UInt32  res2:15;
        RBus_UInt32  d_2d3d_output_c_lpf_c2:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c1:4;
        RBus_UInt32  d_2d3d_output_c_lpf_c0:4;
        RBus_UInt32  res1:4;
    };
}d_2d3d_output_fil_c_RBUS;




#endif


#endif
