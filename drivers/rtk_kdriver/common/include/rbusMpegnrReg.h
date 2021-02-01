/**
* @file rbusMPEGNRReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_MPEGNR_REG_H_
#define _RBUS_MPEGNR_REG_H_

#include "rbusTypes.h"



//  MPEGNR Register Address



#define  MPEGNR_ICH1_BLEND_NR_HOR_STEP_VADDR                	(0xb8023820)
#define  MPEGNR_ICH1_MPEGNR1_VADDR                          	(0xb8023824)
#define  MPEGNR_ICH1_MPEGNR_UB_DELTA1_VADDR                 	(0xb8023828)
#define  MPEGNR_ICH1_MPEGNR_UB_DELTA2_VADDR                 	(0xb802382c)
#define  MPEGNR_ICH1_MPEGNR_UB_CEN_TH_VADDR                 	(0xb8023830)
#define  MPEGNR_ICH1_MPEGNR2_VADDR                          	(0xb8023834)
#define  MPEGNR_ICH1_HIST_BLKING_HOR_RANGE_VADDR            	(0xb8023840)
#define  MPEGNR_ICH1_HIST_BLKING_VER_RANGE_VADDR            	(0xb8023844)
#define  MPEGNR_ICH1_MPEGSTART_VADDR                        	(0xb8023848)
#define  MPEGNR_ICH1_CNTHOR0_VADDR                          	(0xb802384c)
#define  MPEGNR_ICH1_CNTHOR2_VADDR                          	(0xb8023850)
#define  MPEGNR_ICH1_CNTHOR4_VADDR                          	(0xb8023854)
#define  MPEGNR_ICH1_CNTHOR6_VADDR                          	(0xb8023858)
#define  MPEGNR_ICH1_DET_HIST_HOR_STEP_VADDR                	(0xb802385c)
#define  MPEGNR_ICH1_DET_HIST_HOR_THD_VADDR                 	(0xb8023860)
#define  MPEGNR_FSYNC_GENERAL_CTRL1_VADDR                   	(0xb80238a0)
#define  MPEGNR_FSYNC_GENERAL_CTRL2_VADDR                   	(0xb80238a4)
#define  MPEGNR_FSYNC_GENERAL_CTRL3_VADDR                   	(0xb80238a8)
#define  MPEGNR_FSYNC_GENERAL_CTRL4_VADDR                   	(0xb80238ac)
#define  MPEGNR_ICH1_ACCESSDATA_CTRL_PK_VADDR               	(0xb80238b0)
#define  MPEGNR_ICH1_ACCESSDATA_POSCTRL_PK_VADDR            	(0xb80238b4)
#define  MPEGNR_ICH1_READDATA_DATA_Y1_PK_VADDR              	(0xb80238b8)
#define  MPEGNR_ICH1_READDATA_DATA_Y2_PK_VADDR              	(0xb80238bc)
#define  MPEGNR_ICH1_READDATA_DATA_C1_PK_VADDR              	(0xb80238c0)
#define  MPEGNR_ICH1_READDATA_DATA_C2_PK_VADDR              	(0xb80238c4)
#define  MPEGNR_ICH1_READDATA_DATA_C3_PK_VADDR              	(0xb80238c8)
#define  MPEGNR_ICH1_READDATA_DATA_C4_PK_VADDR              	(0xb80238cc)
#define  MPEGNR_ICH1_WRITEDATA_DATA_PK_VADDR                	(0xb80238d0)
#define  MPEGNR_ICH1_GENERAL_DB_CTRL_VADDR                  	(0xb80238fc)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======MPEGNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_blend_range:2;
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_mpghor_blend_xini:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpghor_blend_xstep:15;
    };
}mpegnr_ich1_blend_nr_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_dec_sel:1;
        RBus_UInt32  cp_mpgub_difcmp_en:1;
        RBus_UInt32  cp_mpgub_difcen_en:1;
        RBus_UInt32  dummy18023824_28_26:3;
        RBus_UInt32  cp_mpgupperbound_x:10;
        RBus_UInt32  cp_mpgupperbound_offset:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_mpgupperbound_gain:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpgnr_filter_sel:3;
    };
}mpegnr_ich1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpgub_delta2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgub_delta1:10;
    };
}mpegnr_ich1_mpegnr_ub_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cp_mpgub_delta3:10;
    };
}mpegnr_ich1_mpegnr_ub_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpghor_diff_th_high:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpghor_diff_th_low:10;
    };
}mpegnr_ich1_mpegnr_ub_cen_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgdcgain:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_mpgdcqp:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgfiltersel1:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mpgidxmode_x:1;
        RBus_UInt32  cp_mpgidx_x:3;
        RBus_UInt32  cp_mpegresultweight_x:3;
        RBus_UInt32  cp_mpegenable_x:1;
    };
}mpegnr_ich1_mpegnr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histhorend:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histhorstart:14;
    };
}mpegnr_ich1_hist_blking_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histverend:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_histverstart:14;
    };
}mpegnr_ich1_hist_blking_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  cp_histhoren:1;
    };
}mpegnr_ich1_mpegstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor1:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor0:14;
    };
}mpegnr_ich1_cnthor0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor3:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor2:14;
    };
}mpegnr_ich1_cnthor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor5:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor4:14;
    };
}mpegnr_ich1_cnthor4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor7:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_cnthor6:14;
    };
}mpegnr_ich1_cnthor6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cp_histhor_det_xini:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_histhor_det_xstep:15;
    };
}mpegnr_ich1_det_hist_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_histhor_diff_th_high:8;
        RBus_UInt32  res2:8;
        RBus_UInt32  cp_histhor_diff_th_low:8;
    };
}mpegnr_ich1_det_hist_hor_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  fsync_general_standard_num:17;
        RBus_UInt32  res2:6;
        RBus_UInt32  fsync_general_en:1;
        RBus_UInt32  fsync_general_line_num:5;
    };
}mpegnr_fsync_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_debug_en:1;
        RBus_UInt32  res1:18;
        RBus_UInt32  fsync_general_delta_ratio:13;
    };
}mpegnr_fsync_general_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measure_result_tmp:17;
        RBus_UInt32  delta_trunc:15;
    };
}mpegnr_fsync_general_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measult_result:32;
    };
}mpegnr_fsync_general_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  write_en:1;
        RBus_UInt32  read_en:1;
    };
}mpegnr_ich1_accessdata_ctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  starty:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  startx:14;
    };
}mpegnr_ich1_accessdata_posctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y00:10;
    };
}mpegnr_ich1_readdata_data_y1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  y10:10;
    };
}mpegnr_ich1_readdata_data_y2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u00:10;
    };
}mpegnr_ich1_readdata_data_c1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u01:10;
    };
}mpegnr_ich1_readdata_data_c2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u10:10;
    };
}mpegnr_ich1_readdata_data_c3_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  u11:10;
    };
}mpegnr_ich1_readdata_data_c4_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  v:4;
        RBus_UInt32  u:4;
        RBus_UInt32  y:4;
    };
}mpegnr_ich1_writedata_data_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  general_db_apply:1;
        RBus_UInt32  general_db_rd_sel:1;
        RBus_UInt32  general_db_en:1;
    };
}mpegnr_ich1_general_db_ctrl_RBUS;

#else //apply LITTLE_ENDIAN

//======MPEGNR register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_blend_xstep:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpghor_blend_xini:3;
        RBus_UInt32  res2:11;
        RBus_UInt32  cp_mpghor_blend_range:2;
    };
}mpegnr_ich1_blend_nr_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgnr_filter_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgupperbound_gain:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_mpgupperbound_offset:8;
        RBus_UInt32  cp_mpgupperbound_x:10;
        RBus_UInt32  dummy18023824_28_26:3;
        RBus_UInt32  cp_mpgub_difcen_en:1;
        RBus_UInt32  cp_mpgub_difcmp_en:1;
        RBus_UInt32  cp_mpgub_dec_sel:1;
    };
}mpegnr_ich1_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_delta1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpgub_delta2:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_mpegnr_ub_delta1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpgub_delta3:10;
        RBus_UInt32  res1:22;
    };
}mpegnr_ich1_mpegnr_ub_delta2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpghor_diff_th_low:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  cp_mpghor_diff_th_high:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_mpegnr_ub_cen_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpegenable_x:1;
        RBus_UInt32  cp_mpegresultweight_x:3;
        RBus_UInt32  cp_mpgidx_x:3;
        RBus_UInt32  cp_mpgidxmode_x:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgfiltersel1:1;
        RBus_UInt32  res2:6;
        RBus_UInt32  cp_mpgdcqp:8;
        RBus_UInt32  res3:4;
        RBus_UInt32  cp_mpgdcgain:4;
    };
}mpegnr_ich1_mpegnr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhorstart:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histhorend:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_hist_blking_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histverstart:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_histverend:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_hist_blking_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhoren:1;
        RBus_UInt32  res1:31;
    };
}mpegnr_ich1_mpegstart_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor0:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor1:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_cnthor0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor2:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor3:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_cnthor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor4:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor5:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_cnthor4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cnthor6:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_cnthor7:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_cnthor6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhor_det_xstep:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_histhor_det_xini:3;
        RBus_UInt32  res2:13;
    };
}mpegnr_ich1_det_hist_hor_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histhor_diff_th_low:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_histhor_diff_th_high:8;
        RBus_UInt32  res2:8;
    };
}mpegnr_ich1_det_hist_hor_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_general_line_num:5;
        RBus_UInt32  fsync_general_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  fsync_general_standard_num:17;
        RBus_UInt32  res2:3;
    };
}mpegnr_fsync_general_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fsync_general_delta_ratio:13;
        RBus_UInt32  res1:18;
        RBus_UInt32  fsync_debug_en:1;
    };
}mpegnr_fsync_general_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delta_trunc:15;
        RBus_UInt32  measure_result_tmp:17;
    };
}mpegnr_fsync_general_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  measult_result:32;
    };
}mpegnr_fsync_general_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_en:1;
        RBus_UInt32  write_en:1;
        RBus_UInt32  res1:30;
    };
}mpegnr_ich1_accessdata_ctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  startx:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  starty:14;
        RBus_UInt32  res2:2;
    };
}mpegnr_ich1_accessdata_posctrl_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y01:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_y1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  y11:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_y2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u00:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v00:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c1_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u01:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v01:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c2_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u10:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v10:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c3_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  v11:10;
        RBus_UInt32  res2:6;
    };
}mpegnr_ich1_readdata_data_c4_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y:4;
        RBus_UInt32  u:4;
        RBus_UInt32  v:4;
        RBus_UInt32  res1:20;
    };
}mpegnr_ich1_writedata_data_pk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  general_db_en:1;
        RBus_UInt32  general_db_rd_sel:1;
        RBus_UInt32  general_db_apply:1;
        RBus_UInt32  res1:29;
    };
}mpegnr_ich1_general_db_ctrl_RBUS;




#endif 


#endif 
