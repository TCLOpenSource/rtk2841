/**
* @file rbusBLUReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2014-7-31
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_BLU_REG_H_
#define _RBUS_BLU_REG_H_

#include "rbusTypes.h"



//  BLU Register Address



#define  BLU_LD_GLOBAL_CTRL0_VADDR                          	(0xb802c200)
#define  BLU_LD_GLOBAL_CTRL1_VADDR                          	(0xb802c204)
#define  BLU_LD_GLOBAL_CTRL2_VADDR                          	(0xb802c208)
#define  BLU_LD_GLOBAL_CTRL3_VADDR                          	(0xb802c20c)
#define  BLU_LD_GLOBAL_CTRL4_VADDR                          	(0xb802c210)
#define  BLU_LD_GLOBAL_CTRL5_VADDR                          	(0xb802c214)
#define  BLU_LD_GLOBAL_MAX_CTRL_VADDR                       	(0xb802c218)
#define  BLU_LD_GLOBAL_HIST1_VADDR                          	(0xb802c21c)
#define  BLU_LD_GLOBAL_HIST2_VADDR                          	(0xb802c220)
#define  BLU_LD_GLOBAL_HIST3_VADDR                          	(0xb802c224)
#define  BLU_LD_GLOBAL_HIST4_VADDR                          	(0xb802c228)
#define  BLU_LD_GLOBAL_HIST5_VADDR                          	(0xb802c22c)
#define  BLU_LD_GLOBAL_HIST6_VADDR                          	(0xb802c230)
#define  BLU_LD_GLOBAL_HIST7_VADDR                          	(0xb802c234)
#define  BLU_LD_GLOBAL_HIST8_VADDR                          	(0xb802c238)
#define  BLU_LD_DECISION_CTRL1_VADDR                        	(0xb802c23c)
#define  BLU_LD_DECISION_CTRL2_VADDR                        	(0xb802c240)
#define  BLU_LD_DECISION_CTRL3_VADDR                        	(0xb802c244)
#define  BLU_LD_DECISION_CTRL4_VADDR                        	(0xb802c248)
#define  BLU_LD_DECISION_CTRL5_VADDR                        	(0xb802c24c)
#define  BLU_LD_SPATIAL_CTRL1_VADDR                         	(0xb802c250)
#define  BLU_LD_SPATIAL_CTRL2_VADDR                         	(0xb802c254)
#define  BLU_LD_SPATIAL_CTRL3_VADDR                         	(0xb802c258)
#define  BLU_LD_TEMPORAL_CTRL1_VADDR                        	(0xb802c25c)
#define  BLU_LD_TEMPORAL_CTRL2_VADDR                        	(0xb802c260)
#define  BLU_LD_TEMPORAL_CTRL3_VADDR                        	(0xb802c264)
#define  BLU_LD_BACKLIGHT_CTRL1_VADDR                       	(0xb802c268)
#define  BLU_LD_DATACOMP_CTRL1_VADDR                        	(0xb802c26c)
#define  BLU_LD_DATACOMP_CTRL2_VADDR                        	(0xb802c270)
#define  BLU_LD_INTER_HCTRL1_VADDR                          	(0xb802c274)
#define  BLU_LD_INTER_HCTRL2_VADDR                          	(0xb802c278)
#define  BLU_LD_INTER_VCTRL1_VADDR                          	(0xb802c27c)
#define  BLU_LD_INTER_VCTRL2_VADDR                          	(0xb802c280)
#define  BLU_LD_VTAB_AP_VADDR                               	(0xb802c284)
#define  BLU_LD_VTAB_DP_VADDR                               	(0xb802c288)
#define  BLU_LD_HTAB_AP_VADDR                               	(0xb802c28c)
#define  BLU_LD_HTAB_DP_VADDR                               	(0xb802c290)
#define  BLU_LD_SRAM_CTRL_VADDR                             	(0xb802c294)
#define  BLU_LD_BLIGHT_AP_VADDR                             	(0xb802c298)
#define  BLU_LD_BLIGHT_DP_VADDR                             	(0xb802c29c)
#define  BLU_LD_INTER_HTABSEL1_VADDR                        	(0xb802c2a0)
#define  BLU_LD_INTER_HTABSEL2_VADDR                        	(0xb802c2a4)
#define  BLU_LD_INTER_HTABSEL3_VADDR                        	(0xb802c2a8)
#define  BLU_LD_INTER_HTABSEL4_VADDR                        	(0xb802c2ac)
#define  BLU_LD_INTER_HTABSEL5_VADDR                        	(0xb802c2b0)
#define  BLU_LD_INTER_HTABSEL6_VADDR                        	(0xb802c2b4)
#define  BLU_LD_INTER_HTABSEL7_VADDR                        	(0xb802c2b8)
#define  BLU_LD_INTER_HTABSEL8_VADDR                        	(0xb802c2bc)
#define  BLU_LD_INTER_VTABSEL1_VADDR                        	(0xb802c2c0)
#define  BLU_LD_INTER_VTABSEL2_VADDR                        	(0xb802c2c4)
#define  BLU_LD_INTER_VTABSEL3_VADDR                        	(0xb802c2c8)
#define  BLU_LD_INTER_VTABSEL4_VADDR                        	(0xb802c2cc)
#define  BLU_LD_INTER_VTABSEL5_VADDR                        	(0xb802c2d0)
#define  BLU_LD_INTER_VTABSEL6_VADDR                        	(0xb802c2d4)
#define  BLU_LD_INTER_VTABSEL7_VADDR                        	(0xb802c2d8)
#define  BLU_LD_INTER_VTABSEL8_VADDR                        	(0xb802c2dc)
#define  BLU_LD_DEMO_WINDOW_CTRL0_VADDR                     	(0xb802c2e0)
#define  BLU_LD_DEMO_WINDOW_CTRL1_VADDR                     	(0xb802c2e4)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======BLU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_comp_en:1;
        RBus_UInt32  dummy1802c200_30_0:31;
    };
}blu_ld_global_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_db_en:1;
        RBus_UInt32  dummy1802c204_30:1;
        RBus_UInt32  ld_db_apply:1;
        RBus_UInt32  dummy1802c204_28:1;
        RBus_UInt32  ld_db_read_level:1;
        RBus_UInt32  dummy1802c204_26_0:27;
    };
}blu_ld_global_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c208_31:1;
        RBus_UInt32  ld_3d_mode:2;
        RBus_UInt32  ld_blk_hnum:5;
        RBus_UInt32  dummy1802c208_23_21:3;
        RBus_UInt32  ld_blk_vnum:5;
        RBus_UInt32  dummy1802c208_15_8:8;
        RBus_UInt32  ld_subblk_mode:1;
        RBus_UInt32  ld_gdim_mode:1;
        RBus_UInt32  ld_blk_type:2;
        RBus_UInt32  ld_hist_mode:2;
        RBus_UInt32  ld_tenable:1;
        RBus_UInt32  ld_valid:1;
    };
}blu_ld_global_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c20c_31_29:3;
        RBus_UInt32  ld_blk_hsize:13;
        RBus_UInt32  dummy1802c20c_15_12:4;
        RBus_UInt32  ld_blk_vsize:12;
    };
}blu_ld_global_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_drf_rme_5:1;
        RBus_UInt32  ld_drf_rme_4:1;
        RBus_UInt32  ld_drf_rme_3:1;
        RBus_UInt32  ld_drf_rme_2:1;
        RBus_UInt32  ld_drf_rme_1:1;
        RBus_UInt32  ld_drf_rme_0:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_drf_ls_5:1;
        RBus_UInt32  ld_drf_ls_4:1;
        RBus_UInt32  ld_drf_ls_3:1;
        RBus_UInt32  ld_drf_ls_2:1;
        RBus_UInt32  ld_drf_ls_1:1;
        RBus_UInt32  ld_drf_ls_0:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ld_drf_bist_fail_5:1;
        RBus_UInt32  ld_drf_bist_fail_4:1;
        RBus_UInt32  ld_drf_bist_fail_3:1;
        RBus_UInt32  ld_drf_bist_fail_2:1;
        RBus_UInt32  ld_drf_bist_fail_1:1;
        RBus_UInt32  ld_drf_bist_fail_0:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_bist_fail_5:1;
        RBus_UInt32  ld_bist_fail_4:1;
        RBus_UInt32  ld_bist_fail_3:1;
        RBus_UInt32  ld_bist_fail_2:1;
        RBus_UInt32  ld_bist_fail_1:1;
        RBus_UInt32  ld_bist_fail_0:1;
    };
}blu_ld_global_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_drf_rm_5:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  ld_drf_rm_4:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  ld_drf_rm_3:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  ld_drf_rm_2:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  ld_drf_rm_1:4;
        RBus_UInt32  res6:1;
        RBus_UInt32  ld_drf_rm_0:4;
    };
}blu_ld_global_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  ld_global_max:12;
    };
}blu_ld_global_max_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist0:16;
        RBus_UInt32  ld_global_hist1:16;
    };
}blu_ld_global_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist2:16;
        RBus_UInt32  ld_global_hist3:16;
    };
}blu_ld_global_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist4:16;
        RBus_UInt32  ld_global_hist5:16;
    };
}blu_ld_global_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist6:16;
        RBus_UInt32  ld_global_hist7:16;
    };
}blu_ld_global_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist8:16;
        RBus_UInt32  ld_global_hist9:16;
    };
}blu_ld_global_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist10:16;
        RBus_UInt32  ld_global_hist11:16;
    };
}blu_ld_global_hist6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist12:16;
        RBus_UInt32  ld_global_hist13:16;
    };
}blu_ld_global_hist7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist14:16;
        RBus_UInt32  ld_global_hist15:16;
    };
}blu_ld_global_hist8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_maxgain:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_avegain:5;
        RBus_UInt32  res3:12;
        RBus_UInt32  ld_histshiftbit:4;
    };
}blu_ld_decision_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist0gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist1gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist2gain:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_hist3gain:6;
    };
}blu_ld_decision_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist4gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist5gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist6gain:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_hist7gain:6;
    };
}blu_ld_decision_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  ld_decaccess_addr:9;
        RBus_UInt32  res2:15;
        RBus_UInt32  ld_decaccess_en:1;
    };
}blu_ld_decision_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_decaccess_data:30;
    };
}blu_ld_decision_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialcoef0:4;
        RBus_UInt32  ld_spatialcoef1:4;
        RBus_UInt32  ld_spatialcoef2:4;
        RBus_UInt32  ld_spatialcoef3:4;
        RBus_UInt32  ld_spatialcoef4:4;
        RBus_UInt32  ld_spatialcoef5:4;
        RBus_UInt32  ld_spatialcoef6:4;
        RBus_UInt32  ld_spatialcoef7:4;
    };
}blu_ld_spatial_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialcoef8:4;
        RBus_UInt32  ld_spatialcoef9:4;
        RBus_UInt32  ld_spatialcoef10:4;
        RBus_UInt32  dummy1802c254_19_2:18;
        RBus_UInt32  ld_spatialremapbusy:1;
        RBus_UInt32  ld_spatialremapen:1;
    };
}blu_ld_spatial_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_spatialremapadr:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_spatialremaptab1:10;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_spatialremaptab0:10;
    };
}blu_ld_spatial_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_pos0thd:8;
        RBus_UInt32  ld_tmp_pos1thd:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_posmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_posmaxgain:5;
    };
}blu_ld_temporal_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_neg0thd:8;
        RBus_UInt32  ld_tmp_neg1thd:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_negmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_negmaxgain:5;
    };
}blu_ld_temporal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ld_tmp_maxdiff:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_scenechangegain1:5;
        RBus_UInt32  res3:8;
    };
}blu_ld_temporal_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blu_wr_num:7;
        RBus_UInt32  ld_blu_spitotal:9;
        RBus_UInt32  res1:6;
        RBus_UInt32  ld_blu_spien:1;
        RBus_UInt32  ld_blu_nodim:1;
        RBus_UInt32  ld_blu_usergain:8;
    };
}blu_ld_backlight_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_comp_satrange:8;
        RBus_UInt32  ld_comp_softmax:8;
        RBus_UInt32  ld_comp_minlimit:8;
        RBus_UInt32  ld_softcomp_gain:4;
        RBus_UInt32  ld_comp_maxmode:2;
        RBus_UInt32  ld_debugmode:2;
    };
}blu_ld_datacomp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c270_31_20:12;
        RBus_UInt32  ld_comp_inv_shift:3;
        RBus_UInt32  ld_comp_inv_mode:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  ld_srcgainsel:3;
    };
}blu_ld_datacomp_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tab_hsize:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_hfactor:20;
    };
}blu_ld_inter_hctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hinitphase3_right:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_hboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_hinitphase1:1;
        RBus_UInt32  ld_hinitphase2:8;
        RBus_UInt32  ld_hinitphase3_left:8;
    };
}blu_ld_inter_hctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tab_vsize:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_vfactor:20;
    };
}blu_ld_inter_vctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vinitphase3_right:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_vboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_vinitphase1:1;
        RBus_UInt32  ld_vinitphase2:8;
        RBus_UInt32  ld_vinitphase3_left:8;
    };
}blu_ld_inter_vctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c284_31_9:23;
        RBus_UInt32  ld_vtab_adr:9;
    };
}blu_ld_vtab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c288_31_26:6;
        RBus_UInt32  ld_vtab_dat_msb:10;
        RBus_UInt32  dummy1802c288_15_10:6;
        RBus_UInt32  ld_vtab_dat_lsb:10;
    };
}blu_ld_vtab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c28c_31_9:23;
        RBus_UInt32  ld_htab_adr:9;
    };
}blu_ld_htab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c290_31_26:6;
        RBus_UInt32  ld_htab_dat_msb:10;
        RBus_UInt32  dummy1802c290_15_10:6;
        RBus_UInt32  ld_htab_dat_lsb:10;
    };
}blu_ld_htab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c294_31_3:29;
        RBus_UInt32  ld_blight_update_en:1;
        RBus_UInt32  ld_blight_sw_mode:1;
        RBus_UInt32  ld_table_sw_mode:1;
    };
}blu_ld_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c298_31_5:27;
        RBus_UInt32  ld_blight_adr:5;
    };
}blu_ld_blight_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c29c_31_26:6;
        RBus_UInt32  ld_blight_dat_msb:10;
        RBus_UInt32  dummy1802c29c_15_10:6;
        RBus_UInt32  ld_blight_dat_lsb:10;
    };
}blu_ld_blight_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_3:6;
    };
}blu_ld_inter_htabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_7:6;
    };
}blu_ld_inter_htabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_11:6;
    };
}blu_ld_inter_htabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_15:6;
    };
}blu_ld_inter_htabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_19:6;
    };
}blu_ld_inter_htabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_23:6;
    };
}blu_ld_inter_htabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_27:6;
    };
}blu_ld_inter_htabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_htabsel_31:6;
    };
}blu_ld_inter_htabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_3:6;
    };
}blu_ld_inter_vtabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_7:6;
    };
}blu_ld_inter_vtabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_10:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_11:6;
    };
}blu_ld_inter_vtabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_12:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_14:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_15:6;
    };
}blu_ld_inter_vtabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_16:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_18:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_19:6;
    };
}blu_ld_inter_vtabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_22:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_23:6;
    };
}blu_ld_inter_vtabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_24:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_26:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_27:6;
    };
}blu_ld_inter_vtabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_28:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_30:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  ld_vtabsel_31:6;
    };
}blu_ld_inter_vtabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_demo_en:1;
        RBus_UInt32  ld_demo_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_demo_top:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ld_demo_bottom:12;
    };
}blu_ld_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_demo_left:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_demo_right:13;
    };
}blu_ld_demo_window_ctrl1_RBUS;

#else //apply LITTLE_ENDIAN

//======BLU register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c200_30_0:31;
        RBus_UInt32  ld_comp_en:1;
    };
}blu_ld_global_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802c204_26_0:27;
        RBus_UInt32  ld_db_read_level:1;
        RBus_UInt32  dummy1802c204_28_28:1;
        RBus_UInt32  ld_db_apply:1;
        RBus_UInt32  dummy1802c204_30_30:1;
        RBus_UInt32  ld_db_en:1;
    };
}blu_ld_global_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_valid:1;
        RBus_UInt32  ld_tenable:1;
        RBus_UInt32  ld_hist_mode:2;
        RBus_UInt32  ld_blk_type:2;
        RBus_UInt32  ld_gdim_mode:1;
        RBus_UInt32  ld_subblk_mode:1;
        RBus_UInt32  dummy1802c208_15:8;
        RBus_UInt32  ld_blk_vnum:5;
        RBus_UInt32  dummy1802c208_23:3;
        RBus_UInt32  ld_blk_hnum:5;
        RBus_UInt32  ld_3d_mode:2;
        RBus_UInt32  dummy1802c208_31:1;
    };
}blu_ld_global_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blk_vsize:12;
        RBus_UInt32  dummy1802c20c_15_12:4;
        RBus_UInt32  ld_blk_hsize:13;
        RBus_UInt32  dummy1802c20c_31_29:3;
    };
}blu_ld_global_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_bist_fail_0:1;
        RBus_UInt32  ld_bist_fail_1:1;
        RBus_UInt32  ld_bist_fail_2:1;
        RBus_UInt32  ld_bist_fail_3:1;
        RBus_UInt32  ld_bist_fail_4:1;
        RBus_UInt32  ld_bist_fail_5:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_drf_bist_fail_0:1;
        RBus_UInt32  ld_drf_bist_fail_1:1;
        RBus_UInt32  ld_drf_bist_fail_2:1;
        RBus_UInt32  ld_drf_bist_fail_3:1;
        RBus_UInt32  ld_drf_bist_fail_4:1;
        RBus_UInt32  ld_drf_bist_fail_5:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  ld_drf_ls_0:1;
        RBus_UInt32  ld_drf_ls_1:1;
        RBus_UInt32  ld_drf_ls_2:1;
        RBus_UInt32  ld_drf_ls_3:1;
        RBus_UInt32  ld_drf_ls_4:1;
        RBus_UInt32  ld_drf_ls_5:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_drf_rme_0:1;
        RBus_UInt32  ld_drf_rme_1:1;
        RBus_UInt32  ld_drf_rme_2:1;
        RBus_UInt32  ld_drf_rme_3:1;
        RBus_UInt32  ld_drf_rme_4:1;
        RBus_UInt32  ld_drf_rme_5:1;
    };
}blu_ld_global_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_drf_rm_0:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  ld_drf_rm_1:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  ld_drf_rm_2:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  ld_drf_rm_3:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  ld_drf_rm_4:4;
        RBus_UInt32  res5:1;
        RBus_UInt32  ld_drf_rm_5:4;
        RBus_UInt32  res6:3;
    };
}blu_ld_global_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_max:12;
        RBus_UInt32  res1:20;
    };
}blu_ld_global_max_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist1:16;
        RBus_UInt32  ld_global_hist0:16;
    };
}blu_ld_global_hist1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist3:16;
        RBus_UInt32  ld_global_hist2:16;
    };
}blu_ld_global_hist2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist5:16;
        RBus_UInt32  ld_global_hist4:16;
    };
}blu_ld_global_hist3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist7:16;
        RBus_UInt32  ld_global_hist6:16;
    };
}blu_ld_global_hist4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist9:16;
        RBus_UInt32  ld_global_hist8:16;
    };
}blu_ld_global_hist5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist11:16;
        RBus_UInt32  ld_global_hist10:16;
    };
}blu_ld_global_hist6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist13:16;
        RBus_UInt32  ld_global_hist12:16;
    };
}blu_ld_global_hist7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_global_hist15:16;
        RBus_UInt32  ld_global_hist14:16;
    };
}blu_ld_global_hist8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_histshiftbit:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  ld_avegain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_maxgain:6;
        RBus_UInt32  res3:2;
    };
}blu_ld_decision_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hist3gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist2gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist1gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist0gain:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_decision_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hist7gain:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_hist6gain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_hist5gain:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_hist4gain:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_decision_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_decaccess_en:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  ld_decaccess_addr:9;
        RBus_UInt32  res2:7;
    };
}blu_ld_decision_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_decaccess_data:30;
        RBus_UInt32  res1:2;
    };
}blu_ld_decision_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialcoef7:4;
        RBus_UInt32  ld_spatialcoef6:4;
        RBus_UInt32  ld_spatialcoef5:4;
        RBus_UInt32  ld_spatialcoef4:4;
        RBus_UInt32  ld_spatialcoef3:4;
        RBus_UInt32  ld_spatialcoef2:4;
        RBus_UInt32  ld_spatialcoef1:4;
        RBus_UInt32  ld_spatialcoef0:4;
    };
}blu_ld_spatial_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialremapen:1;
        RBus_UInt32  ld_spatialremapbusy:1;
        RBus_UInt32  dummy1802c254_19:18;
        RBus_UInt32  ld_spatialcoef10:4;
        RBus_UInt32  ld_spatialcoef9:4;
        RBus_UInt32  ld_spatialcoef8:4;
    };
}blu_ld_spatial_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_spatialremaptab0:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_spatialremaptab1:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_spatialremapadr:5;
        RBus_UInt32  res3:3;
    };
}blu_ld_spatial_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_posmaxgain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_posmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_pos1thd:8;
        RBus_UInt32  ld_tmp_pos0thd:8;
    };
}blu_ld_temporal_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_tmp_negmaxgain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_tmp_negmingain:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_neg1thd:8;
        RBus_UInt32  ld_tmp_neg0thd:8;
    };
}blu_ld_temporal_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ld_tmp_scenechangegain1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_tmp_maxdiff:8;
        RBus_UInt32  res3:8;
    };
}blu_ld_temporal_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blu_usergain:8;
        RBus_UInt32  ld_blu_nodim:1;
        RBus_UInt32  ld_blu_spien:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  ld_blu_spitotal:9;
        RBus_UInt32  ld_blu_wr_num:7;
    };
}blu_ld_backlight_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_debugmode:2;
        RBus_UInt32  ld_comp_maxmode:2;
        RBus_UInt32  ld_softcomp_gain:4;
        RBus_UInt32  ld_comp_minlimit:8;
        RBus_UInt32  ld_comp_softmax:8;
        RBus_UInt32  ld_comp_satrange:8;
    };
}blu_ld_datacomp_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_srcgainsel:3;
        RBus_UInt32  res1:13;
        RBus_UInt32  ld_comp_inv_mode:1;
        RBus_UInt32  ld_comp_inv_shift:3;
        RBus_UInt32  dummy1802c270_31_20:12;
    };
}blu_ld_datacomp_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hfactor:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_tab_hsize:8;
    };
}blu_ld_inter_hctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_hinitphase3_left:8;
        RBus_UInt32  ld_hinitphase2:8;
        RBus_UInt32  ld_hinitphase1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_hboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_hinitphase3_right:8;
    };
}blu_ld_inter_hctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vfactor:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_tab_vsize:8;
    };
}blu_ld_inter_vctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vinitphase3_left:8;
        RBus_UInt32  ld_vinitphase2:8;
        RBus_UInt32  ld_vinitphase1:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_vboundary:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ld_vinitphase3_right:8;
    };
}blu_ld_inter_vctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtab_adr:9;
        RBus_UInt32  dummy1802c284_31_9:23;
    };
}blu_ld_vtab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtab_dat_lsb:10;
        RBus_UInt32  dummy1802c288_15_10:6;
        RBus_UInt32  ld_vtab_dat_msb:10;
        RBus_UInt32  dummy1802c288_31_26:6;
    };
}blu_ld_vtab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htab_adr:9;
        RBus_UInt32  dummy1802c28c_31_9:23;
    };
}blu_ld_htab_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htab_dat_lsb:10;
        RBus_UInt32  dummy1802c290_15_10:6;
        RBus_UInt32  ld_htab_dat_msb:10;
        RBus_UInt32  dummy1802c290_31_26:6;
    };
}blu_ld_htab_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_table_sw_mode:1;
        RBus_UInt32  ld_blight_sw_mode:1;
        RBus_UInt32  ld_blight_update_en:1;
        RBus_UInt32  dummy1802c294_31:29;
    };
}blu_ld_sram_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blight_adr:5;
        RBus_UInt32  dummy1802c298_31_5:27;
    };
}blu_ld_blight_ap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_blight_dat_lsb:10;
        RBus_UInt32  dummy1802c29c_15_10:6;
        RBus_UInt32  ld_blight_dat_msb:10;
        RBus_UInt32  dummy1802c29c_31_26:6;
    };
}blu_ld_blight_dp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_0:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_4:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_11:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_8:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_15:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_12:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_19:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_16:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_23:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_20:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_27:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_24:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_htabsel_31:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_htabsel_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_htabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_htabsel_28:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_htabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_0:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_7:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_5:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_4:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_11:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_10:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_9:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_8:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_15:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_14:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_13:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_12:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_19:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_18:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_17:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_16:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_23:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_22:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_21:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_20:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_27:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_26:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_25:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_24:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_vtabsel_31:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  ld_vtabsel_30:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_vtabsel_29:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  ld_vtabsel_28:6;
        RBus_UInt32  res4:2;
    };
}blu_ld_inter_vtabsel8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_demo_bottom:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ld_demo_top:12;
        RBus_UInt32  res2:2;
        RBus_UInt32  ld_demo_mode:1;
        RBus_UInt32  ld_demo_en:1;
    };
}blu_ld_demo_window_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_demo_right:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ld_demo_left:13;
        RBus_UInt32  res2:3;
    };
}blu_ld_demo_window_ctrl1_RBUS;




#endif 


#endif 
