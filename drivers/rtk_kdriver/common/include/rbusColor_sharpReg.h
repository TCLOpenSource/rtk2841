/**
* @file rbusColor_sharpReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/2/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_COLOR_SHARP_REG_H_
#define _RBUS_COLOR_SHARP_REG_H_

#include "rbusTypes.h"



//  COLOR_SHARP Register Address



#define  COLOR_SHARP_DM_NR_SHP_CTRL_VADDR                   	(0xb802b500)
#define  COLOR_SHARP_DM_MKIII_SHP_CTRL_VADDR                	(0xb802b504)
#define  COLOR_SHARP_DM_SEGPK_CTRL1_VADDR                   	(0xb802b508)
#define  COLOR_SHARP_DM_SEGPK_CTRL2_VADDR                   	(0xb802b50c)
#define  COLOR_SHARP_DM_SEGPK_CTRL3_VADDR                   	(0xb802b510)
#define  COLOR_SHARP_DM_SEGPK_RING_VADDR                    	(0xb802b514)
#define  COLOR_SHARP_DM_SEGPK_LPF_VADDR                     	(0xb802b518)
#define  COLOR_SHARP_DM_SEGPK_DBG_VADDR                     	(0xb802b51c)
#define  COLOR_SHARP_DM_2D_SHP_Y_REMAP_VADDR                	(0xb802b520)
#define  COLOR_SHARP_DM_PEAKING_GAIN_VADDR                  	(0xb802b524)
#define  COLOR_SHARP_DM_PEAKING_BOUND_1_VADDR               	(0xb802b528)
#define  COLOR_SHARP_DM_PEAKING_BOUND_0_VADDR               	(0xb802b52c)
#define  COLOR_SHARP_DM_2D_SHP_TEX_0_VADDR                  	(0xb802b530)
#define  COLOR_SHARP_DM_2D_SHP_TEX_1_VADDR                  	(0xb802b534)
#define  COLOR_SHARP_DM_2D_SHP_TEX_1_1_VADDR                	(0xb802b538)
#define  COLOR_SHARP_DM_2D_SHP_TEX_2_VADDR                  	(0xb802b558)
#define  COLOR_SHARP_DM_2D_SHP_TEX_3_VADDR                  	(0xb802b55c)
#define  COLOR_SHARP_DM_2D_SHP_TEX_4_VADDR                  	(0xb802b57c)
#define  COLOR_SHARP_DM_2D_SHP_TEX_5_VADDR                  	(0xb802b580)
#define  COLOR_SHARP_DM_2D_SHP_TEX_6_VADDR                  	(0xb802b5a0)
#define  COLOR_SHARP_DM_2D_SHP_TEX_7_VADDR                  	(0xb802b5c0)
#define  COLOR_SHARP_DM_2D_SHP_TEX_SHIFT_VADDR              	(0xb802b5e0)
#define  COLOR_SHARP_DM_PEAKING_EMF_TEXTURE_VADDR           	(0xb802b5e4)
#define  COLOR_SHARP_DM_EMFMK2_CTRL_TEXTURE_VADDR           	(0xb802b5e8)
#define  COLOR_SHARP_DM_EMF_EXT_0_TEXTURE_VADDR             	(0xb802b5ec)
#define  COLOR_SHARP_DM_EMF_EXT_1_TEXTURE_VADDR             	(0xb802b5f0)
#define  COLOR_SHARP_DM_PEAKING_EMF_OFFSET_VADDR            	(0xb802b5f4)
#define  COLOR_SHARP_DM_SKIPIR_CTRL1_VADDR                  	(0xb802b5f8)
#define  COLOR_SHARP_DM_SKIPIR_CTRL2_VADDR                  	(0xb802b5fc)
#define  COLOR_SHARP_DM_SKIPIR_CTRL3_VADDR                  	(0xb802b600)
#define  COLOR_SHARP_DM_DNOISE_CTRL1_VADDR                  	(0xb802b604)
#define  COLOR_SHARP_DM_DNOISE_CTRL2_VADDR                  	(0xb802b608)
#define  COLOR_SHARP_DM_AUTO_SHP_DATA_VADDR                 	(0xb802b60c)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_00_VADDR         	(0xb802b610)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_01_VADDR         	(0xb802b614)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_02_VADDR         	(0xb802b618)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_03_VADDR         	(0xb802b61c)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_04_VADDR         	(0xb802b620)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_05_VADDR         	(0xb802b624)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_06_VADDR         	(0xb802b628)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_07_VADDR         	(0xb802b62c)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_08_VADDR         	(0xb802b630)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_09_VADDR         	(0xb802b634)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_10_VADDR         	(0xb802b638)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_11_VADDR         	(0xb802b63c)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_12_VADDR         	(0xb802b640)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_13_VADDR         	(0xb802b644)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_14_VADDR         	(0xb802b648)
#define  COLOR_SHARP_DM_AUTO_SHP_FIR_COUNT_15_VADDR         	(0xb802b64c)
#define  COLOR_SHARP_DM_SEGPK_EDGPK3_VADDR                  	(0xb802b650)
#define  COLOR_SHARP_DM_SEGPK_EDGPK4_VADDR                  	(0xb802b654)
#define  COLOR_SHARP_DM_SEGPK_EDGPK2_VADDR                  	(0xb802b658)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_0_VADDR                 	(0xb802b65c)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_1_VADDR                 	(0xb802b660)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_1_1_VADDR               	(0xb802b664)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_2_VADDR                 	(0xb802b684)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_3_VADDR                 	(0xb802b688)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_4_VADDR                 	(0xb802b6a8)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_5_VADDR                 	(0xb802b6ac)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_6_VADDR                 	(0xb802b6cc)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_7_VADDR                 	(0xb802b6ec)
#define  COLOR_SHARP_DM_2D_SHP_EDGE_SHIFT_VADDR             	(0xb802b70c)
#define  COLOR_SHARP_DM_PEAKING_EMF_VADDR                   	(0xb802b710)
#define  COLOR_SHARP_DM_EMFMK2_CTRL_VADDR                   	(0xb802b714)
#define  COLOR_SHARP_DM_EMF_EXT_0_VADDR                     	(0xb802b718)
#define  COLOR_SHARP_DM_EMF_EXT_1_VADDR                     	(0xb802b71c)
#define  COLOR_SHARP_DM_SEGPK_EDGE_CORING_0_VADDR           	(0xb802b720)
#define  COLOR_SHARP_DM_SEGPK_EDGE_CORING_1_VADDR           	(0xb802b724)
#define  COLOR_SHARP_DM_SEGPK_EDGPK_SOURCESLOPE_VADDR       	(0xb802b728)
#define  COLOR_SHARP_DM_SEGPK_VPK1_VADDR                    	(0xb802b72c)
#define  COLOR_SHARP_DM_SEGPK_VPK2_VADDR                    	(0xb802b730)
#define  COLOR_SHARP_DM_SEGPK_VPK3_VADDR                    	(0xb802b734)
#define  COLOR_SHARP_DM_SEGPK_VPK4_VADDR                    	(0xb802b738)
#define  COLOR_SHARP_DM_SEGPK_VWSUM_VADDR                   	(0xb802b73c)
#define  COLOR_SHARP_DM_CDS_CM0_U_BOUND_0_VADDR             	(0xb802b740)
#define  COLOR_SHARP_DM_CDS_CM0_V_BOUND_0_VADDR             	(0xb802b744)
#define  COLOR_SHARP_DM_CDS_CM0_U_BOUND_1_VADDR             	(0xb802b748)
#define  COLOR_SHARP_DM_CDS_CM0_V_BOUND_1_VADDR             	(0xb802b74c)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM0_TEX_VADDR      	(0xb802b750)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM0_TEX_VADDR     	(0xb802b754)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM0_EDGE_VADDR     	(0xb802b758)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM0_EDGE_VADDR    	(0xb802b75c)
#define  COLOR_SHARP_DM_CDS_CM1_U_BOUND_0_VADDR             	(0xb802b760)
#define  COLOR_SHARP_DM_CDS_CM1_V_BOUND_0_VADDR             	(0xb802b764)
#define  COLOR_SHARP_DM_CDS_CM1_U_BOUND_1_VADDR             	(0xb802b768)
#define  COLOR_SHARP_DM_CDS_CM1_V_BOUND_1_VADDR             	(0xb802b76c)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM1_TEX_VADDR      	(0xb802b770)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM1_TEX_VADDR     	(0xb802b774)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM1_EDGE_VADDR     	(0xb802b778)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM1_EDGE_VADDR    	(0xb802b77c)
#define  COLOR_SHARP_DM_CDS_CM2_U_BOUND_0_VADDR             	(0xb802b780)
#define  COLOR_SHARP_DM_CDS_CM2_V_BOUND_0_VADDR             	(0xb802b784)
#define  COLOR_SHARP_DM_CDS_CM2_U_BOUND_1_VADDR             	(0xb802b788)
#define  COLOR_SHARP_DM_CDS_CM2_V_BOUND_1_VADDR             	(0xb802b78c)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM2_TEX_VADDR      	(0xb802b790)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM2_TEX_VADDR     	(0xb802b794)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM2_EDGE_VADDR     	(0xb802b798)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM2_EDGE_VADDR    	(0xb802b79c)
#define  COLOR_SHARP_DM_CDS_CM3_U_BOUND_0_VADDR             	(0xb802b7a0)
#define  COLOR_SHARP_DM_CDS_CM3_V_BOUND_0_VADDR             	(0xb802b7a4)
#define  COLOR_SHARP_DM_CDS_CM3_U_BOUND_1_VADDR             	(0xb802b7a8)
#define  COLOR_SHARP_DM_CDS_CM3_V_BOUND_1_VADDR             	(0xb802b7ac)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM3_TEX_VADDR      	(0xb802b7b0)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM3_TEX_VADDR     	(0xb802b7b4)
#define  COLOR_SHARP_DM_CDS_PEAKING_GAIN_CM3_EDGE_VADDR     	(0xb802b7b8)
#define  COLOR_SHARP_DM_CDS_PEAKING_BOUND_CM3_EDGE_VADDR    	(0xb802b7bc)
#define  COLOR_SHARP_DM_SOURS_LPF_0_VADDR                   	(0xb802b7c0)
#define  COLOR_SHARP_DM_SOURS_LPF_1_VADDR                   	(0xb802b7c4)
#define  COLOR_SHARP_DM_MAXMIN_SHP_GAIN_0_VADDR             	(0xb802b7c8)
#define  COLOR_SHARP_DM_MAXMIN_SHP_GAIN_1_VADDR             	(0xb802b7cc)
#define  COLOR_SHARP_DM_MAXMIN_SHP_GAIN_2_VADDR             	(0xb802b7d0)
#define  COLOR_SHARP_DM_MAXMIN_SHP_GAIN_3_VADDR             	(0xb802b7d4)
#define  COLOR_SHARP_DM_MAXMIN_SHP_STEP_0_VADDR             	(0xb802b7d8)
#define  COLOR_SHARP_DM_MAXMIN_SHP_STEP_1_VADDR             	(0xb802b7dc)
#define  COLOR_SHARP_DM_MAXMIN_SHP_STEP_2_VADDR             	(0xb802b7e0)
#define  COLOR_SHARP_DM_MAXMIN_SHP_STEP_3_VADDR             	(0xb802b7e4)
#define  COLOR_SHARP_DM_CDS_CM0_Y_VADDR                     	(0xb802b7e8)
#define  COLOR_SHARP_DM_CDS_CM0_U_VADDR                     	(0xb802b7ec)
#define  COLOR_SHARP_DM_CDS_CM0_V_VADDR                     	(0xb802b7f0)
#define  COLOR_SHARP_DM_CDS_CM1_Y_VADDR                     	(0xb802b7f4)
#define  COLOR_SHARP_DM_CDS_CM1_U_VADDR                     	(0xb802b7f8)
#define  COLOR_SHARP_DM_CDS_CM1_V_VADDR                     	(0xb802b7fc)
#define  COLOR_SHARP_DM_CDS_CM2_Y_VADDR                     	(0xb802b800)
#define  COLOR_SHARP_DM_CDS_CM2_U_VADDR                     	(0xb802b804)
#define  COLOR_SHARP_DM_CDS_CM2_V_VADDR                     	(0xb802b808)
#define  COLOR_SHARP_DM_CDS_CM3_Y_VADDR                     	(0xb802b80c)
#define  COLOR_SHARP_DM_CDS_CM3_U_VADDR                     	(0xb802b810)
#define  COLOR_SHARP_DM_CDS_CM3_V_VADDR                     	(0xb802b814)
#define  COLOR_SHARP_DM_VPK_HPK_ADD_VADDR                   	(0xb802b818)
#define  COLOR_SHARP_DM_VC_AFTER_FILTER_0_VADDR             	(0xb802b81c)
#define  COLOR_SHARP_DM_VC_AFTER_FILTER_1_VADDR             	(0xb802b820)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_0_VADDR 	(0xb802b824)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_1_VADDR 	(0xb802b828)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_2_VADDR 	(0xb802b82c)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_3_VADDR 	(0xb802b830)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_4_VADDR 	(0xb802b834)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_5_VADDR 	(0xb802b838)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_6_VADDR 	(0xb802b83c)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_GAIN_7_VADDR 	(0xb802b840)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_STEP_0_VADDR 	(0xb802b844)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_STEP_1_VADDR 	(0xb802b848)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_STEP_2_VADDR 	(0xb802b84c)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_STEP_3_VADDR 	(0xb802b850)
#define  COLOR_SHARP_DM_VERTICAL_POS_GAIN_CURVE_STEP_4_VADDR 	(0xb802b854)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_0_VADDR 	(0xb802b858)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_1_VADDR 	(0xb802b85c)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_2_VADDR 	(0xb802b860)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_3_VADDR 	(0xb802b864)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_4_VADDR 	(0xb802b868)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_5_VADDR 	(0xb802b86c)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_6_VADDR 	(0xb802b870)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_GAIN_7_VADDR 	(0xb802b874)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_STEP_0_VADDR 	(0xb802b878)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_STEP_1_VADDR 	(0xb802b87c)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_STEP_2_VADDR 	(0xb802b880)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_STEP_3_VADDR 	(0xb802b884)
#define  COLOR_SHARP_DM_VERTICAL_NEG_GAIN_CURVE_STEP_4_VADDR 	(0xb802b888)
#define  COLOR_SHARP_DM_GAIN_CURVE_DEBUG_VADDR              	(0xb802b88c)
#define  COLOR_SHARP_DM_SR_CONTINUAL_DETAIL_GAIN_VADDR      	(0xb802b890)
#define  COLOR_SHARP_DM_SR_CONTINUAL_DETAIL_SEL_VADDR       	(0xb802b894)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_H_COEF_0_VADDR          	(0xb802b898)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_H_COEF_1_VADDR          	(0xb802b89c)
#define  COLOR_SHARP_DM_SR_13TAP_HPF_H_COEF_0_VADDR         	(0xb802b8a0)
#define  COLOR_SHARP_DM_SR_13TAP_HPF_H_COEF_1_VADDR         	(0xb802b8a4)
#define  COLOR_SHARP_DM_SR_21TAP_HPF_H_COEF_0_VADDR         	(0xb802b8a8)
#define  COLOR_SHARP_DM_SR_21TAP_HPF_H_COEF_1_VADDR         	(0xb802b8ac)
#define  COLOR_SHARP_DM_SR_21TAP_HPF_H_COEF_2_VADDR         	(0xb802b8b0)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_0_0_VADDR        	(0xb802b8b4)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_0_1_VADDR        	(0xb802b8b8)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_1_0_VADDR        	(0xb802b8bc)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_1_1_VADDR        	(0xb802b8c0)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_2_0_VADDR        	(0xb802b8c4)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_2_1_VADDR        	(0xb802b8c8)
#define  COLOR_SHARP_DM_SR_11TAP_HPF_H_COEF_0_VADDR         	(0xb802b8cc)
#define  COLOR_SHARP_DM_SR_11TAP_HPF_H_COEF_1_VADDR         	(0xb802b8d0)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_3_0_VADDR        	(0xb802b8d4)
#define  COLOR_SHARP_DM_SR_9TAP_HPF_V_COEF_3_1_VADDR        	(0xb802b8d8)
#define  COLOR_SHARP_DM_EDGE_SM_CTRL1_VADDR                 	(0xb802b8dc)
#define  COLOR_SHARP_DM_EDGE_SM_CTRL2_VADDR                 	(0xb802b8e0)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_0_VADDR    	(0xb802ba00)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_1_VADDR    	(0xb802ba04)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_2_VADDR    	(0xb802ba08)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_3_VADDR    	(0xb802ba0c)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_4_VADDR    	(0xb802ba10)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_5_VADDR    	(0xb802ba14)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_6_VADDR    	(0xb802ba18)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_GAIN_7_VADDR    	(0xb802ba1c)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_STEP_0_VADDR    	(0xb802ba20)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_STEP_1_VADDR    	(0xb802ba24)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_STEP_2_VADDR    	(0xb802ba28)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_STEP_3_VADDR    	(0xb802ba2c)
#define  COLOR_SHARP_DM_EDGE_POS_GAIN_CURVE_STEP_4_VADDR    	(0xb802ba30)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_0_VADDR    	(0xb802ba40)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_1_VADDR    	(0xb802ba44)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_2_VADDR    	(0xb802ba48)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_3_VADDR    	(0xb802ba4c)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_4_VADDR    	(0xb802ba50)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_5_VADDR    	(0xb802ba54)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_6_VADDR    	(0xb802ba58)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_GAIN_7_VADDR    	(0xb802ba5c)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_STEP_0_VADDR    	(0xb802ba60)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_STEP_1_VADDR    	(0xb802ba64)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_STEP_2_VADDR    	(0xb802ba68)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_STEP_3_VADDR    	(0xb802ba6c)
#define  COLOR_SHARP_DM_EDGE_NEG_GAIN_CURVE_STEP_4_VADDR    	(0xb802ba70)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_0_VADDR     	(0xb802ba80)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_1_VADDR     	(0xb802ba84)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_2_VADDR     	(0xb802ba88)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_3_VADDR     	(0xb802ba8c)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_4_VADDR     	(0xb802ba90)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_5_VADDR     	(0xb802ba94)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_6_VADDR     	(0xb802ba98)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_GAIN_7_VADDR     	(0xb802ba9c)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_STEP_0_VADDR     	(0xb802baa0)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_STEP_1_VADDR     	(0xb802baa4)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_STEP_2_VADDR     	(0xb802baa8)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_STEP_3_VADDR     	(0xb802baac)
#define  COLOR_SHARP_DM_TEX_POS_GAIN_CURVE_STEP_4_VADDR     	(0xb802bab0)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_0_VADDR     	(0xb802bac0)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_1_VADDR     	(0xb802bac4)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_2_VADDR     	(0xb802bac8)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_3_VADDR     	(0xb802bacc)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_4_VADDR     	(0xb802bad0)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_5_VADDR     	(0xb802bad4)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_6_VADDR     	(0xb802bad8)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_GAIN_7_VADDR     	(0xb802badc)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_STEP_0_VADDR     	(0xb802bae0)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_STEP_1_VADDR     	(0xb802bae4)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_STEP_2_VADDR     	(0xb802bae8)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_STEP_3_VADDR     	(0xb802baec)
#define  COLOR_SHARP_DM_TEX_NEG_GAIN_CURVE_STEP_4_VADDR     	(0xb802baf0)
#define  COLOR_SHARP_DM_SEGPK_VPK5_VADDR                    	(0xb802baf4)
#define  COLOR_SHARP_DM_SEGPK_VPK6_VADDR                    	(0xb802baf8)
#define  COLOR_SHARP_DM_SEGPK_EDGPK_VSOURCESLOPE_VADDR      	(0xb802bafc)
#define  COLOR_SHARP_DM_MAXMIN_LPF_WEIT_0_VADDR             	(0xb802b900)
#define  COLOR_SHARP_DM_MAXMIN_LPF_WEIT_1_VADDR             	(0xb802b904)
#define  COLOR_SHARP_DM_MAXMIN_LPF_WEIT_2_VADDR             	(0xb802b908)
#define  COLOR_SHARP_DM_MAXMIN_LPF_WEIT_3_VADDR             	(0xb802b90c)
#define  COLOR_SHARP_DM_MAXMIN_LPF_STEP_0_VADDR             	(0xb802b910)
#define  COLOR_SHARP_DM_MAXMIN_LPF_STEP_1_VADDR             	(0xb802b914)
#define  COLOR_SHARP_DM_MAXMIN_LPF_STEP_2_VADDR             	(0xb802b918)
#define  COLOR_SHARP_DM_MAXMIN_LPF_STEP_3_VADDR             	(0xb802b91c)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_GAIN_0_VADDR       	(0xb802b920)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_GAIN_1_VADDR       	(0xb802b924)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_GAIN_2_VADDR       	(0xb802b928)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_GAIN_3_VADDR       	(0xb802b92c)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_STEP_0_VADDR       	(0xb802b930)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_STEP_1_VADDR       	(0xb802b934)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_STEP_2_VADDR       	(0xb802b938)
#define  COLOR_SHARP_DM_MAXMIN_GAIN_BY_Y_STEP_3_VADDR       	(0xb802b93c)
#define  COLOR_SHARP_DS_NR_SHP_CTRL_VADDR                   	(0xb802b970)
#define  COLOR_SHARP_DS_PEAKING_FILTER_0_VADDR              	(0xb802b974)
#define  COLOR_SHARP_DS_PEAKING_FILTER_1_VADDR              	(0xb802b978)
#define  COLOR_SHARP_DS_PEAKING_GAIN_VADDR                  	(0xb802b97c)
#define  COLOR_SHARP_DS_PEAKING_BOUND_VADDR                 	(0xb802b980)
#define  COLOR_SHARP_DS_PEAKING_EMF_VADDR                   	(0xb802b984)
#define  COLOR_SHARP_DS_CHROMA_LOWPASS_VADDR                	(0xb802b988)
#define  COLOR_SHARP_DS_PEAKING_EMF_OFFSET_VADDR            	(0xb802b98c)
#define  COLOR_SHARP_SHP_CRC_CTRL_VADDR                     	(0xb802b940)
#define  COLOR_SHARP_SHP_CRC_RESULT_VADDR                   	(0xb802b944)
#define  COLOR_SHARP_PEAK2D_BIST_VADDR                      	(0xb802b948)
#define  COLOR_SHARP_PEAK2D_BISR_VADDR                      	(0xb802b94c)
#define  COLOR_SHARP_SHP_DLTI_CTRL_1_VADDR                  	(0xb802b950)
#define  COLOR_SHARP_SHP_DLTI_CTRL_2_VADDR                  	(0xb802b954)
#define  COLOR_SHARP_SHP_DLTI_CTRL_3_VADDR                  	(0xb802b958)
#define  COLOR_SHARP_SHP_DLTI_GAIN_OFFSET_1_VADDR           	(0xb802b95c)
#define  COLOR_SHARP_SHP_DLTI_GAIN_OFFSET_2_VADDR           	(0xb802b960)
#define  COLOR_SHARP_SHP_DLTI_GAIN_OFFSET_3_VADDR           	(0xb802b964)
#define  COLOR_SHARP_SHP_DLTI_GAIN_OFFSET_4_VADDR           	(0xb802b968)
#define  COLOR_SHARP_SHP_DLTI_GAIN_OFFSET_5_VADDR           	(0xb802b96c)
#define  COLOR_SHARP_SHP_DCTI_CTRL_1_VADDR                  	(0xb802b9c0)
#define  COLOR_SHARP_SHP_DCTI_CTRL_2_VADDR                  	(0xb802b9c4)
#define  COLOR_SHARP_SHP_DCTI_CTRL_3_VADDR                  	(0xb802b9c8)
#define  COLOR_SHARP_SHP_DCTI_CTRL_4_VADDR                  	(0xb802b9cc)
#define  COLOR_SHARP_SHP_DCTI_CTRL_5_VADDR                  	(0xb802b9d0)
#define  COLOR_SHARP_SHP_DCTI_CTRL_6_VADDR                  	(0xb802b9d4)
#define  COLOR_SHARP_SHP_DCTI_CTRL_7_VADDR                  	(0xb802b9d8)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======COLOR_SHARP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_load:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  tex_emf_enable:1;
        RBus_UInt32  edg_emf_enable:1;
        RBus_UInt32  peaking_enable:1;
    };
}color_sharp_dm_nr_shp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  mkiii_tex_filter_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  mkiii_edge_filter_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  mmsum_2d_src_sel:1;
        RBus_UInt32  mmsum_edge_array_mode:1;
        RBus_UInt32  mmsum_tex_array_mode:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg_gain_debug_step:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  seg_gain_debug_mode:2;
        RBus_UInt32  res6:3;
        RBus_UInt32  gain_by_y_en:1;
        RBus_UInt32  lpf_weigh_en:1;
        RBus_UInt32  max_min_gain_en:1;
        RBus_UInt32  sharp_mkiii_debug_en:1;
    };
}color_sharp_dm_mkiii_shp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  edg_tex_blending_lpf_filter_en:1;
        RBus_UInt32  edg_tex_blending_lpf_filter:2;
        RBus_UInt32  enhance_mode:2;
        RBus_UInt32  edgextrange_v:1;
        RBus_UInt32  edgextrange:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  sobel_stepbit:3;
        RBus_UInt32  sobel_upbnd:8;
        RBus_UInt32  sobelmode:1;
        RBus_UInt32  edgmode:2;
        RBus_UInt32  texpk_en:1;
        RBus_UInt32  edgpk_en:1;
        RBus_UInt32  edgext_en:1;
        RBus_UInt32  segpk_mode:2;
    };
}color_sharp_dm_segpk_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  sobelrange_h:2;
        RBus_UInt32  sobelrange_v:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pkdlti_comsign:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  zigsftbit_reg:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  zdiff_stepbit:3;
        RBus_UInt32  zdiff_upbnd:8;
    };
}color_sharp_dm_segpk_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  acts_offset:8;
        RBus_UInt32  small_th1:7;
        RBus_UInt32  tex_en:1;
        RBus_UInt32  actsftbit_reg:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  tex_stepbit:3;
        RBus_UInt32  tex_upbnd:8;
    };
}color_sharp_dm_segpk_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  ringtune:4;
        RBus_UInt32  res2:5;
        RBus_UInt32  ringgain_reg:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  ringrange_reg:2;
        RBus_UInt32  res4:3;
        RBus_UInt32  dering_en:1;
    };
}color_sharp_dm_segpk_ring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  lpf_filter:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  lpf_mode:3;
    };
}color_sharp_dm_segpk_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  debugmode:4;
    };
}color_sharp_dm_segpk_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  lineary_umode:2;
        RBus_UInt32  lineary_lmode:2;
        RBus_UInt32  lineary_ub:8;
        RBus_UInt32  lineary_lb:8;
    };
}color_sharp_dm_2d_shp_y_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_pos2:2;
        RBus_UInt32  gain_neg2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  tex_d2_shift_bit:2;
        RBus_UInt32  res2:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_peaking_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lv2:8;
    };
}color_sharp_dm_peaking_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  coef_c0_0:9;
        RBus_UInt32  coef_c1_0:8;
        RBus_UInt32  coef_c2_0:8;
    };
}color_sharp_dm_2d_shp_tex_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3_0:8;
        RBus_UInt32  coef_c4_0:8;
        RBus_UInt32  coef_c5_0:8;
        RBus_UInt32  coef_c6_0:8;
    };
}color_sharp_dm_2d_shp_tex_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c7_0:8;
        RBus_UInt32  coef_c8_0:8;
        RBus_UInt32  coef_c9_0:8;
        RBus_UInt32  coef_c10_0:8;
    };
}color_sharp_dm_2d_shp_tex_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_1:8;
        RBus_UInt32  coef_c1_1:8;
        RBus_UInt32  coef_c2_1:8;
        RBus_UInt32  coef_c3_1:8;
    };
}color_sharp_dm_2d_shp_tex_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c4_1:8;
        RBus_UInt32  coef_c5_1:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_2d_shp_tex_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_2:8;
        RBus_UInt32  coef_c1_2:8;
        RBus_UInt32  coef_c2_2:8;
        RBus_UInt32  coef_c3_2:8;
    };
}color_sharp_dm_2d_shp_tex_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c4_2:8;
        RBus_UInt32  coef_c5_2:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_2d_shp_tex_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_3:8;
        RBus_UInt32  res1:24;
    };
}color_sharp_dm_2d_shp_tex_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_4:8;
        RBus_UInt32  res1:24;
    };
}color_sharp_dm_2d_shp_tex_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tex_lpf_shift:4;
        RBus_UInt32  res1:28;
    };
}color_sharp_dm_2d_shp_tex_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  seg0_offset:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg2_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg1_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_gain_sel:3;
        RBus_UInt32  emf_range_force_v_5tap:1;
        RBus_UInt32  emf_range_force_h_11tap:1;
        RBus_UInt32  emf_range:2;
        RBus_UInt32  emf_shift:3;
        RBus_UInt32  res5:1;
    };
}color_sharp_dm_peaking_emf_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  declinebit:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  blendstepbit:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  lowbnd:10;
        RBus_UInt32  blend_wt:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  aov_range:1;
        RBus_UInt32  emf_mk2_debug:1;
        RBus_UInt32  emf_mode_sel:1;
    };
}color_sharp_dm_emfmk2_ctrl_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  seg1_offset:11;
        RBus_UInt32  emf_fixextent_pos:8;
        RBus_UInt32  emf_fixextent_neg:8;
    };
}color_sharp_dm_emf_ext_0_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg1_x:10;
        RBus_UInt32  seg0_x:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  seg2_offset:11;
    };
}color_sharp_dm_emf_ext_1_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wtsum_level:3;
        RBus_UInt32  wtsum_enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  wtsum_tap:1;
        RBus_UInt32  res2:24;
    };
}color_sharp_dm_peaking_emf_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  oceansft:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  isletsft:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  isletlvsft:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  isletgainsft:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  revlvsft:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  revgainsft:3;
        RBus_UInt32  res7:2;
        RBus_UInt32  islet_mode_sel:1;
        RBus_UInt32  revlv_en:1;
        RBus_UInt32  revgain_en:1;
        RBus_UInt32  isletlv_en:1;
        RBus_UInt32  isletgain_en:1;
        RBus_UInt32  skipir_en:1;
    };
}color_sharp_dm_skipir_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  isletmode1_th:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_sharp_d2sft:3;
        RBus_UInt32  sharp_graymode:1;
        RBus_UInt32  debug_sharp:1;
        RBus_UInt32  debug_revlv:1;
        RBus_UInt32  debug_isletlv:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  islet_enlargeaov:3;
        RBus_UInt32  isletrange:4;
    };
}color_sharp_dm_skipir_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  isletlv_upbnd:8;
        RBus_UInt32  isletgain_upbnd:8;
        RBus_UInt32  revlv_upbnd:8;
        RBus_UInt32  revgain_upbnd:8;
    };
}color_sharp_dm_skipir_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802b604_31_11:21;
        RBus_UInt32  dnoise_gainsft:3;
        RBus_UInt32  dummy1802b604_7:1;
        RBus_UInt32  dnoise_lvsft:3;
        RBus_UInt32  dnoise_aovrange:1;
        RBus_UInt32  dnoise_mode:1;
        RBus_UInt32  dnoise_gain_en:1;
        RBus_UInt32  dnoise_lv_en:1;
    };
}color_sharp_dm_dnoise_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dnoise_gain_upbnd:8;
        RBus_UInt32  dnoise_lv_upbnd:8;
        RBus_UInt32  dnoise_noise_gain_th:8;
        RBus_UInt32  dnoise_noise_lv_th:8;
    };
}color_sharp_dm_dnoise_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  enable:1;
        RBus_UInt32  shift_bit:4;
        RBus_UInt32  bin0_offset:8;
        RBus_UInt32  y_lb:8;
        RBus_UInt32  y_ub:8;
    };
}color_sharp_dm_auto_shp_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut0:22;
    };
}color_sharp_dm_auto_shp_fir_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut1:22;
    };
}color_sharp_dm_auto_shp_fir_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut2:22;
    };
}color_sharp_dm_auto_shp_fir_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut3:22;
    };
}color_sharp_dm_auto_shp_fir_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut4:22;
    };
}color_sharp_dm_auto_shp_fir_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut5:22;
    };
}color_sharp_dm_auto_shp_fir_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut6:22;
    };
}color_sharp_dm_auto_shp_fir_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut7:22;
    };
}color_sharp_dm_auto_shp_fir_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut8:22;
    };
}color_sharp_dm_auto_shp_fir_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut9:22;
    };
}color_sharp_dm_auto_shp_fir_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut10:22;
    };
}color_sharp_dm_auto_shp_fir_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut11:22;
    };
}color_sharp_dm_auto_shp_fir_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut12:22;
    };
}color_sharp_dm_auto_shp_fir_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut13:22;
    };
}color_sharp_dm_auto_shp_fir_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut14:22;
    };
}color_sharp_dm_auto_shp_fir_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  lut15:22;
    };
}color_sharp_dm_auto_shp_fir_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_pos2:2;
        RBus_UInt32  gain_neg2:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  edg_d2_shift_bit:2;
        RBus_UInt32  res2:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_segpk_edgpk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_segpk_edgpk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  lv2:8;
    };
}color_sharp_dm_segpk_edgpk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  coef_c0_0:9;
        RBus_UInt32  coef_c1_0:8;
        RBus_UInt32  coef_c2_0:8;
    };
}color_sharp_dm_2d_shp_edge_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3_0:8;
        RBus_UInt32  coef_c4_0:8;
        RBus_UInt32  coef_c5_0:8;
        RBus_UInt32  coef_c6_0:8;
    };
}color_sharp_dm_2d_shp_edge_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c7_0:8;
        RBus_UInt32  coef_c8_0:8;
        RBus_UInt32  coef_c9_0:8;
        RBus_UInt32  coef_c10_0:8;
    };
}color_sharp_dm_2d_shp_edge_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_1:8;
        RBus_UInt32  coef_c1_1:8;
        RBus_UInt32  coef_c2_1:8;
        RBus_UInt32  coef_c3_1:8;
    };
}color_sharp_dm_2d_shp_edge_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c4_1:8;
        RBus_UInt32  coef_c5_1:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_2d_shp_edge_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_2:8;
        RBus_UInt32  coef_c1_2:8;
        RBus_UInt32  coef_c2_2:8;
        RBus_UInt32  coef_c3_2:8;
    };
}color_sharp_dm_2d_shp_edge_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c4_2:8;
        RBus_UInt32  coef_c5_2:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_2d_shp_edge_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_3:8;
        RBus_UInt32  res1:24;
    };
}color_sharp_dm_2d_shp_edge_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0_4:8;
        RBus_UInt32  res1:24;
    };
}color_sharp_dm_2d_shp_edge_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edg_lpf_shift:4;
        RBus_UInt32  res1:28;
    };
}color_sharp_dm_2d_shp_edge_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  seg0_offset:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg2_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg1_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_gain_sel:3;
        RBus_UInt32  emf_range_force_v_5tap:1;
        RBus_UInt32  emf_range_force_h_11tap:1;
        RBus_UInt32  emf_range:2;
        RBus_UInt32  emf_shift:3;
        RBus_UInt32  res5:1;
    };
}color_sharp_dm_peaking_emf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  declinebit:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  blendstepbit:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  lowbnd:10;
        RBus_UInt32  blend_wt:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  aov_range:1;
        RBus_UInt32  emf_mk2_debug:1;
        RBus_UInt32  emf_mode_sel:1;
    };
}color_sharp_dm_emfmk2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  seg1_offset:11;
        RBus_UInt32  emf_fixextent_pos:8;
        RBus_UInt32  emf_fixextent_neg:8;
    };
}color_sharp_dm_emf_ext_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg1_x:10;
        RBus_UInt32  seg0_x:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  seg2_offset:11;
    };
}color_sharp_dm_emf_ext_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  bigedge_ratio:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smalledge_ratio:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  deltaedge_ratio:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  smalledge_ulevel:5;
    };
}color_sharp_dm_segpk_edge_coring_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_coring_en:1;
        RBus_UInt32  edge_gain_en:1;
        RBus_UInt32  edge_coring_debug:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  deltaedge_ulevel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  edge_coring_clip:5;
        RBus_UInt32  edge_delta_ext_range:3;
        RBus_UInt32  edge_gain_bound:5;
        RBus_UInt32  edge_ser_range:4;
    };
}color_sharp_dm_segpk_edge_coring_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  slope_gain_en:1;
        RBus_UInt32  dir:1;
        RBus_UInt32  fh:1;
        RBus_UInt32  gain_boundpos:4;
        RBus_UInt32  gain_boundneg:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  gain_extendpos:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  gain_extendneg:7;
    };
}color_sharp_dm_segpk_edgpk_sourceslope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_c2:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  vpk_c1:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  vpk_c0:9;
    };
}color_sharp_dm_segpk_vpk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vpk_lv:8;
        RBus_UInt32  vpk_gain_neg:8;
        RBus_UInt32  vpk_gain_pos:8;
    };
}color_sharp_dm_segpk_vpk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  lv2:8;
        RBus_UInt32  gain_pos2:2;
        RBus_UInt32  gain_neg2:2;
        RBus_UInt32  vpk_hv_pos:8;
        RBus_UInt32  vpk_hv_neg:8;
    };
}color_sharp_dm_segpk_vpk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_c3:8;
        RBus_UInt32  vpk_c4:8;
        RBus_UInt32  vext_reg:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  vpk_edg_en:1;
        RBus_UInt32  v_dering_en:1;
        RBus_UInt32  v_tex_en:1;
        RBus_UInt32  vemf_en:1;
        RBus_UInt32  vpk_en:1;
    };
}color_sharp_dm_segpk_vpk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  v_wtsum_tap:1;
        RBus_UInt32  v_wtsum_level:3;
        RBus_UInt32  v_wtsum_enable:1;
    };
}color_sharp_dm_segpk_vwsum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cds_cm0_enable:1;
        RBus_UInt32  cds_enable:1;
        RBus_UInt32  cds_debug:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  u_ub_0:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  u_lb_0:11;
    };
}color_sharp_dm_cds_cm0_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm0_mode:2;
        RBus_UInt32  cm0_conti_area:5;
        RBus_UInt32  cm0_conti_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_0:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_lb_0:11;
    };
}color_sharp_dm_cds_cm0_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  uv_rad_0:9;
        RBus_UInt32  cv_0:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  cu_0:10;
    };
}color_sharp_dm_cds_cm0_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt_0:24;
    };
}color_sharp_dm_cds_cm0_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm0_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm0_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm0_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm0_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cds_cm1_enable:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  u_ub_1:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  u_lb_1:11;
    };
}color_sharp_dm_cds_cm1_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm1_mode:2;
        RBus_UInt32  cm1_conti_area:5;
        RBus_UInt32  cm1_conti_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_lb_1:11;
    };
}color_sharp_dm_cds_cm1_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  uv_rad_1:9;
        RBus_UInt32  cv_1:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  cu_1:10;
    };
}color_sharp_dm_cds_cm1_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt_1:24;
    };
}color_sharp_dm_cds_cm1_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm1_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm1_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm1_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm1_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cds_cm2_enable:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  u_ub_2:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  u_lb_2:11;
    };
}color_sharp_dm_cds_cm2_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm2_mode:2;
        RBus_UInt32  cm2_conti_area:5;
        RBus_UInt32  cm2_conti_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_2:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_lb_2:11;
    };
}color_sharp_dm_cds_cm2_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  uv_rad_2:9;
        RBus_UInt32  cv_2:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  cu_2:10;
    };
}color_sharp_dm_cds_cm2_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt_2:24;
    };
}color_sharp_dm_cds_cm2_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm2_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm2_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm2_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm2_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cds_cm3_enable:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  u_ub_3:11;
        RBus_UInt32  res3:1;
        RBus_UInt32  u_lb_3:11;
    };
}color_sharp_dm_cds_cm3_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cm3_mode:2;
        RBus_UInt32  cm3_conti_area:5;
        RBus_UInt32  cm3_conti_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_3:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  v_lb_3:11;
    };
}color_sharp_dm_cds_cm3_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  uv_rad_3:9;
        RBus_UInt32  cv_3:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  cu_3:10;
    };
}color_sharp_dm_cds_cm3_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cnt_3:24;
    };
}color_sharp_dm_cds_cm3_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm3_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm3_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_dm_cds_peaking_gain_cm3_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_dm_cds_peaking_bound_cm3_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  coef_c0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  coef_c1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  coef_c2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  coef_c3:6;
    };
}color_sharp_dm_sours_lpf_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  coef_c4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  coef_c5:6;
    };
}color_sharp_dm_sours_lpf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s0:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s1:11;
    };
}color_sharp_dm_maxmin_shp_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s3:11;
    };
}color_sharp_dm_maxmin_shp_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s5:11;
    };
}color_sharp_dm_maxmin_shp_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_maxmin_shp_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  s1:11;
    };
}color_sharp_dm_maxmin_shp_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s3:11;
    };
}color_sharp_dm_maxmin_shp_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s5:11;
    };
}color_sharp_dm_maxmin_shp_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_maxmin_shp_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_0:32;
    };
}color_sharp_dm_cds_cm0_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_0:32;
    };
}color_sharp_dm_cds_cm0_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_0:32;
    };
}color_sharp_dm_cds_cm0_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_1:32;
    };
}color_sharp_dm_cds_cm1_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_1:32;
    };
}color_sharp_dm_cds_cm1_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_1:32;
    };
}color_sharp_dm_cds_cm1_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_2:32;
    };
}color_sharp_dm_cds_cm2_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_2:32;
    };
}color_sharp_dm_cds_cm2_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_2:32;
    };
}color_sharp_dm_cds_cm2_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_3:32;
    };
}color_sharp_dm_cds_cm3_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_3:32;
    };
}color_sharp_dm_cds_cm3_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_3:32;
    };
}color_sharp_dm_cds_cm3_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802b818_31_4:28;
        RBus_UInt32  res1:2;
        RBus_UInt32  hpf_vpf_maxmin_en:1;
        RBus_UInt32  src_sel:1;
    };
}color_sharp_dm_vpk_hpk_add_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c0:8;
        RBus_UInt32  coef_c1:8;
        RBus_UInt32  coef_c2:8;
        RBus_UInt32  coef_c3:8;
    };
}color_sharp_dm_vc_after_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c4:8;
        RBus_UInt32  hpf_gain:8;
        RBus_UInt32  res1:14;
        RBus_UInt32  mode:1;
        RBus_UInt32  enable:1;
    };
}color_sharp_dm_vc_after_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s1:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s5:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s7:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s11:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s13:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s1:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s4:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s6:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s7:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s10:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s12:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s13:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:10;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s1:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s5:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s7:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s11:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s13:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s1:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s4:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s6:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s7:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s10:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s12:10;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s13:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:9;
        RBus_UInt32  enable:1;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hpf_out_debug_en:1;
        RBus_UInt32  hpf_out_debug_sel:3;
        RBus_UInt32  res2:4;
        RBus_UInt32  debug_step:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  enable:1;
    };
}color_sharp_dm_gain_curve_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  period:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  gain:9;
        RBus_UInt32  res3:3;
        RBus_UInt32  offset:9;
    };
}color_sharp_dm_sr_continual_detail_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  ring_gen_gain:8;
        RBus_UInt32  ring_gen:2;
        RBus_UInt32  hv_max:2;
        RBus_UInt32  tex_filter_sel:2;
        RBus_UInt32  edg_filter_sel:2;
    };
}color_sharp_dm_sr_continual_detail_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_9tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
    };
}color_sharp_dm_sr_9tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
    };
}color_sharp_dm_sr_13tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
        RBus_UInt32  c5:8;
        RBus_UInt32  c6:8;
    };
}color_sharp_dm_sr_13tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
    };
}color_sharp_dm_sr_21tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
        RBus_UInt32  c5:8;
        RBus_UInt32  c6:8;
    };
}color_sharp_dm_sr_21tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c7:8;
        RBus_UInt32  c8:8;
        RBus_UInt32  c9:8;
        RBus_UInt32  c10:8;
    };
}color_sharp_dm_sr_21tap_hpf_h_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:23;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:23;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:23;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:15;
        RBus_UInt32  c1:8;
    };
}color_sharp_dm_sr_11tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
        RBus_UInt32  c5:8;
    };
}color_sharp_dm_sr_11tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:23;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c4:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  dirsm_rangh:1;
        RBus_UInt32  dirsm_rangv:1;
        RBus_UInt32  meandiff_rangeh:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  meandiff_rangev:2;
        RBus_UInt32  meandiff_shiftbit:3;
        RBus_UInt32  meandiff_step:3;
        RBus_UInt32  meandiff_lowbd:8;
    };
}color_sharp_dm_edge_sm_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  edge_method_sel:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  edgeindex_step:3;
        RBus_UInt32  edgeindex_lowbd:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  dism_debug_mode:3;
    };
}color_sharp_dm_edge_sm_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s1:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s5:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s7:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s11:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s13:10;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s1:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_edge_pos_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s4:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s6:10;
    };
}color_sharp_dm_edge_pos_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s7:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_edge_pos_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s10:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s12:10;
    };
}color_sharp_dm_edge_pos_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s13:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:10;
    };
}color_sharp_dm_edge_pos_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s1:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s5:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s7:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s11:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s13:10;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s1:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_edge_neg_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s4:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s6:10;
    };
}color_sharp_dm_edge_neg_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s7:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_edge_neg_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s10:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s12:10;
    };
}color_sharp_dm_edge_neg_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s13:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:9;
        RBus_UInt32  enable:1;
    };
}color_sharp_dm_edge_neg_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s1:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s5:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s7:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s11:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s13:10;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s1:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_tex_pos_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s4:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s6:10;
    };
}color_sharp_dm_tex_pos_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s7:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_tex_pos_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s10:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s12:10;
    };
}color_sharp_dm_tex_pos_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s13:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:10;
    };
}color_sharp_dm_tex_pos_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s1:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s5:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s7:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s11:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  s13:10;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s1:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s3:10;
    };
}color_sharp_dm_tex_neg_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s4:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s6:10;
    };
}color_sharp_dm_tex_neg_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s7:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s9:10;
    };
}color_sharp_dm_tex_neg_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s10:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s12:10;
    };
}color_sharp_dm_tex_neg_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  s13:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:9;
        RBus_UInt32  enable:1;
    };
}color_sharp_dm_tex_neg_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  vpk_edg_lv:8;
        RBus_UInt32  vpk_edg_gain_neg:8;
        RBus_UInt32  vpk_edg_gain_pos:8;
    };
}color_sharp_dm_segpk_vpk5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edg_lv2:8;
        RBus_UInt32  vpk_edg_gain_pos2:2;
        RBus_UInt32  vpk_edg_gain_neg2:2;
        RBus_UInt32  vpk_edg_hv_pos:10;
        RBus_UInt32  vpk_edg_hv_neg:10;
    };
}color_sharp_dm_segpk_vpk6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  v_slope_gain_en:1;
        RBus_UInt32  dir_v:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  gain_boundpos_v:4;
        RBus_UInt32  gain_boundneg_v:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  gain_extendpos_v:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  gain_extendneg_v:7;
    };
}color_sharp_dm_segpk_edgpk_vsourceslope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s0:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s1:11;
    };
}color_sharp_dm_maxmin_lpf_weit_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s3:11;
    };
}color_sharp_dm_maxmin_lpf_weit_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s5:11;
    };
}color_sharp_dm_maxmin_lpf_weit_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_maxmin_lpf_weit_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  s1:11;
    };
}color_sharp_dm_maxmin_lpf_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s3:11;
    };
}color_sharp_dm_maxmin_lpf_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s5:11;
    };
}color_sharp_dm_maxmin_lpf_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_maxmin_lpf_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s0:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s1:11;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s3:11;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s5:11;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  s1:11;
    };
}color_sharp_dm_maxmin_gain_by_y_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s3:11;
    };
}color_sharp_dm_maxmin_gain_by_y_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  s5:11;
    };
}color_sharp_dm_maxmin_gain_by_y_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:16;
    };
}color_sharp_dm_maxmin_gain_by_y_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  clp_enable:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  emf_enable:1;
        RBus_UInt32  peaking_enable:1;
    };
}color_sharp_ds_nr_shp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sh_b0:2;
        RBus_UInt32  sh_b1:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  c0:9;
        RBus_UInt32  res3:3;
        RBus_UInt32  c1:9;
    };
}color_sharp_ds_peaking_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  c3:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c4:7;
        RBus_UInt32  res3:2;
        RBus_UInt32  c5:6;
    };
}color_sharp_ds_peaking_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_neg:8;
    };
}color_sharp_ds_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  lv:8;
    };
}color_sharp_ds_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  seg0_offset:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg2_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg1_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_gain_sel:3;
        RBus_UInt32  res5:4;
        RBus_UInt32  emf_shift:3;
        RBus_UInt32  res6:1;
    };
}color_sharp_ds_peaking_emf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  blur_fac:5;
    };
}color_sharp_ds_chroma_lowpass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  seg2_offset:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg1_offset:11;
    };
}color_sharp_ds_peaking_emf_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  crc_channel:1;
        RBus_UInt32  crc_conti:1;
        RBus_UInt32  crc_start:1;
    };
}color_sharp_shp_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shp_crc_result:32;
    };
}color_sharp_shp_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  ls:1;
        RBus_UInt32  dvse:1;
        RBus_UInt32  dvs:4;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  bist_fail_0:1;
    };
}color_sharp_peak2d_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ls:1;
        RBus_UInt32  dvse:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  dvs:4;
        RBus_UInt32  bisr_fail_0:1;
        RBus_UInt32  bisr_fail_1:1;
        RBus_UInt32  bisr_fail_2:1;
        RBus_UInt32  bisr_fail_3:1;
        RBus_UInt32  bisr_fail_4:1;
        RBus_UInt32  bisr_fail_5:1;
        RBus_UInt32  bisr_fail_6:1;
        RBus_UInt32  bisr_fail_7:1;
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_2:1;
        RBus_UInt32  drf_fail_3:1;
        RBus_UInt32  drf_fail_4:1;
        RBus_UInt32  drf_fail_5:1;
        RBus_UInt32  drf_fail_6:1;
        RBus_UInt32  drf_fail_7:1;
        RBus_UInt32  bisr_repaired:1;
    };
}color_sharp_peak2d_bisr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_sel:1;
        RBus_UInt32  can_shift:2;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  pnth:10;
        RBus_UInt32  dcp_th:8;
        RBus_UInt32  rn_extend_en:1;
        RBus_UInt32  d1_cp_shift:2;
        RBus_UInt32  ffd2_en:1;
        RBus_UInt32  tn_blend_mode:1;
        RBus_UInt32  tn_blend_en:1;
        RBus_UInt32  ovc_en:1;
        RBus_UInt32  dlti_en:1;
    };
}color_sharp_shp_dlti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_debug:3;
        RBus_UInt32  res1:12;
        RBus_UInt32  ffd1_ratio:7;
        RBus_UInt32  ffd1_th:10;
    };
}color_sharp_shp_dlti_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  ffd2_ratio:7;
        RBus_UInt32  ffd2_range2r:10;
        RBus_UInt32  ffd2_range2l:10;
    };
}color_sharp_shp_dlti_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tngain2:5;
        RBus_UInt32  tnoff2:4;
        RBus_UInt32  tngain1:5;
        RBus_UInt32  tnoff1:4;
        RBus_UInt32  tngain0:5;
        RBus_UInt32  tnoff0:4;
    };
}color_sharp_shp_dlti_gain_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tngain5:5;
        RBus_UInt32  tnoff5:4;
        RBus_UInt32  tngain4:5;
        RBus_UInt32  tnoff4:4;
        RBus_UInt32  tngain3:5;
        RBus_UInt32  tnoff3:4;
    };
}color_sharp_shp_dlti_gain_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tngain8:5;
        RBus_UInt32  tnoff8:4;
        RBus_UInt32  tngain7:5;
        RBus_UInt32  tnoff7:4;
        RBus_UInt32  tngain6:5;
        RBus_UInt32  tnoff6:4;
    };
}color_sharp_shp_dlti_gain_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tngain11:5;
        RBus_UInt32  tnoff11:4;
        RBus_UInt32  tngain10:5;
        RBus_UInt32  tnoff10:4;
        RBus_UInt32  tngain9:5;
        RBus_UInt32  tnoff9:4;
    };
}color_sharp_shp_dlti_gain_offset_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  tngain14:5;
        RBus_UInt32  tnoff14:4;
        RBus_UInt32  tngain13:5;
        RBus_UInt32  tnoff13:4;
        RBus_UInt32  tngain12:5;
        RBus_UInt32  tnoff12:4;
    };
}color_sharp_shp_dlti_gain_offset_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  data_sel:1;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  psmth:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  lpmode:3;
        RBus_UInt32  engdiv:2;
        RBus_UInt32  offdiv:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  uvgain:7;
        RBus_UInt32  dcti_mode:1;
        RBus_UInt32  uvalign_en:1;
        RBus_UInt32  cur_sel:1;
        RBus_UInt32  res3:1;
    };
}color_sharp_shp_dcti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  uvsync_en:1;
        RBus_UInt32  tran_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  rate_steep:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  th_steep:6;
        RBus_UInt32  th_coring:5;
        RBus_UInt32  steep_mode:3;
        RBus_UInt32  hp_mode:3;
        RBus_UInt32  vlp_mode:3;
        RBus_UInt32  median_mode:1;
        RBus_UInt32  blending_mode:1;
    };
}color_sharp_shp_dcti_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  maxminlen:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  rate_tran:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  th_tran:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  region_mode:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  rate_smooth:3;
        RBus_UInt32  res6:2;
        RBus_UInt32  th_smooth:6;
    };
}color_sharp_shp_dcti_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rate_align_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  rate_align:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  th_align:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  align_mingain:6;
        RBus_UInt32  res5:2;
        RBus_UInt32  th_gtran:6;
    };
}color_sharp_shp_dcti_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  th_uvmindiff:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  rate_stair2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  rate_stair1:3;
        RBus_UInt32  res4:2;
        RBus_UInt32  th_stair:6;
        RBus_UInt32  res5:3;
        RBus_UInt32  th_align_weight:5;
    };
}color_sharp_shp_dcti_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:19;
        RBus_UInt32  rate_engsync:3;
        RBus_UInt32  rate_uvmindiff:3;
        RBus_UInt32  th_engsync:6;
    };
}color_sharp_shp_dcti_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  debug_shiftbit:3;
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  res2:6;
        RBus_UInt32  res3:6;
    };
}color_sharp_shp_dcti_ctrl_7_RBUS;

#else //apply LITTLE_ENDIAN

//======COLOR_SHARP register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  edg_emf_enable:1;
        RBus_UInt32  tex_emf_enable:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  db_load:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res2:19;
    };
}color_sharp_dm_nr_shp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sharp_mkiii_debug_en:1;
        RBus_UInt32  max_min_gain_en:1;
        RBus_UInt32  lpf_weigh_en:1;
        RBus_UInt32  gain_by_y_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  seg_gain_debug_mode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg_gain_debug_step:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  mmsum_tex_array_mode:1;
        RBus_UInt32  mmsum_edge_array_mode:1;
        RBus_UInt32  mmsum_2d_src_sel:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  mkiii_edge_filter_sel:2;
        RBus_UInt32  res5:2;
        RBus_UInt32  mkiii_tex_filter_sel:2;
        RBus_UInt32  res6:6;
    };
}color_sharp_dm_mkiii_shp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  segpk_mode:2;
        RBus_UInt32  edgext_en:1;
        RBus_UInt32  edgpk_en:1;
        RBus_UInt32  texpk_en:1;
        RBus_UInt32  edgmode:2;
        RBus_UInt32  sobelmode:1;
        RBus_UInt32  sobel_upbnd:8;
        RBus_UInt32  sobel_stepbit:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  edgextrange:3;
        RBus_UInt32  edgextrange_v:1;
        RBus_UInt32  enhance_mode:2;
        RBus_UInt32  edg_tex_blending_lpf_filter:2;
        RBus_UInt32  edg_tex_blending_lpf_filter_en:1;
        RBus_UInt32  res2:3;
    };
}color_sharp_dm_segpk_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zdiff_upbnd:8;
        RBus_UInt32  zdiff_stepbit:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  zigsftbit_reg:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  pkdlti_comsign:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  sobelrange_v:1;
        RBus_UInt32  sobelrange_h:2;
        RBus_UInt32  res4:9;
    };
}color_sharp_dm_segpk_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tex_upbnd:8;
        RBus_UInt32  tex_stepbit:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  actsftbit_reg:2;
        RBus_UInt32  tex_en:1;
        RBus_UInt32  small_th1:7;
        RBus_UInt32  acts_offset:8;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_segpk_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dering_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  ringrange_reg:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  ringgain_reg:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  ringtune:4;
        RBus_UInt32  res4:12;
    };
}color_sharp_dm_segpk_ring_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lpf_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lpf_filter:3;
        RBus_UInt32  res2:25;
    };
}color_sharp_dm_segpk_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debugmode:4;
        RBus_UInt32  res1:28;
    };
}color_sharp_dm_segpk_dbg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lineary_lb:8;
        RBus_UInt32  lineary_ub:8;
        RBus_UInt32  lineary_lmode:2;
        RBus_UInt32  lineary_umode:2;
        RBus_UInt32  res1:12;
    };
}color_sharp_dm_2d_shp_y_remap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  tex_d2_shift_bit:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  gain_neg2:2;
        RBus_UInt32  gain_pos2:2;
    };
}color_sharp_dm_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_peaking_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv2:8;
        RBus_UInt32  res1:24;
    };
}color_sharp_dm_peaking_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c2_0:8;
        RBus_UInt32  coef_c1_0:8;
        RBus_UInt32  coef_c0_0:9;
        RBus_UInt32  res1:7;
    };
}color_sharp_dm_2d_shp_tex_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c6_0:8;
        RBus_UInt32  coef_c5_0:8;
        RBus_UInt32  coef_c4_0:8;
        RBus_UInt32  coef_c3_0:8;
    };
}color_sharp_dm_2d_shp_tex_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c10_0:8;
        RBus_UInt32  coef_c9_0:8;
        RBus_UInt32  coef_c8_0:8;
        RBus_UInt32  coef_c7_0:8;
    };
}color_sharp_dm_2d_shp_tex_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3_1:8;
        RBus_UInt32  coef_c2_1:8;
        RBus_UInt32  coef_c1_1:8;
        RBus_UInt32  coef_c0_1:8;
    };
}color_sharp_dm_2d_shp_tex_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  coef_c5_1:8;
        RBus_UInt32  coef_c4_1:8;
    };
}color_sharp_dm_2d_shp_tex_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3_2:8;
        RBus_UInt32  coef_c2_2:8;
        RBus_UInt32  coef_c1_2:8;
        RBus_UInt32  coef_c0_2:8;
    };
}color_sharp_dm_2d_shp_tex_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  coef_c5_2:8;
        RBus_UInt32  coef_c4_2:8;
    };
}color_sharp_dm_2d_shp_tex_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coef_c0_3:8;
    };
}color_sharp_dm_2d_shp_tex_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coef_c0_4:8;
    };
}color_sharp_dm_2d_shp_tex_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  tex_lpf_shift:4;
    };
}color_sharp_dm_2d_shp_tex_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  emf_shift:3;
        RBus_UInt32  emf_range:2;
        RBus_UInt32  emf_range_force_h_11tap:1;
        RBus_UInt32  emf_range_force_v_5tap:1;
        RBus_UInt32  seg0_gain_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg1_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg2_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_offset:11;
        RBus_UInt32  res5:1;
    };
}color_sharp_dm_peaking_emf_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emf_mode_sel:1;
        RBus_UInt32  emf_mk2_debug:1;
        RBus_UInt32  aov_range:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  blend_wt:4;
        RBus_UInt32  lowbnd:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  blendstepbit:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  declinebit:2;
        RBus_UInt32  res4:6;
    };
}color_sharp_dm_emfmk2_ctrl_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emf_fixextent_neg:8;
        RBus_UInt32  emf_fixextent_pos:8;
        RBus_UInt32  seg1_offset:11;
        RBus_UInt32  res1:5;
    };
}color_sharp_dm_emf_ext_0_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg2_offset:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  seg0_x:10;
        RBus_UInt32  seg1_x:10;
    };
}color_sharp_dm_emf_ext_1_texture_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  wtsum_tap:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  wtsum_enable:1;
        RBus_UInt32  wtsum_level:3;
    };
}color_sharp_dm_peaking_emf_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  skipir_en:1;
        RBus_UInt32  isletgain_en:1;
        RBus_UInt32  isletlv_en:1;
        RBus_UInt32  revgain_en:1;
        RBus_UInt32  revlv_en:1;
        RBus_UInt32  islet_mode_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  revgainsft:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  revlvsft:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  isletgainsft:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  isletlvsft:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  isletsft:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  oceansft:3;
        RBus_UInt32  res7:1;
    };
}color_sharp_dm_skipir_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  isletrange:4;
        RBus_UInt32  islet_enlargeaov:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  debug_isletlv:1;
        RBus_UInt32  debug_revlv:1;
        RBus_UInt32  debug_sharp:1;
        RBus_UInt32  sharp_graymode:1;
        RBus_UInt32  debug_sharp_d2sft:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  isletmode1_th:8;
        RBus_UInt32  res3:8;
    };
}color_sharp_dm_skipir_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  revgain_upbnd:8;
        RBus_UInt32  revlv_upbnd:8;
        RBus_UInt32  isletgain_upbnd:8;
        RBus_UInt32  isletlv_upbnd:8;
    };
}color_sharp_dm_skipir_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dnoise_lv_en:1;
        RBus_UInt32  dnoise_gain_en:1;
        RBus_UInt32  dnoise_mode:1;
        RBus_UInt32  dnoise_aovrange:1;
        RBus_UInt32  dnoise_lvsft:3;
        RBus_UInt32  dummy1802b604_7:1;
        RBus_UInt32  dnoise_gainsft:3;
        RBus_UInt32  dummy1802b604_31:21;
    };
}color_sharp_dm_dnoise_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dnoise_noise_lv_th:8;
        RBus_UInt32  dnoise_noise_gain_th:8;
        RBus_UInt32  dnoise_lv_upbnd:8;
        RBus_UInt32  dnoise_gain_upbnd:8;
    };
}color_sharp_dm_dnoise_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  y_ub:8;
        RBus_UInt32  y_lb:8;
        RBus_UInt32  bin0_offset:8;
        RBus_UInt32  shift_bit:4;
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:3;
    };
}color_sharp_dm_auto_shp_data_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut0:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut1:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut2:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut3:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut4:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut5:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut6:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut7:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut8:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut9:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut10:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut11:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut12:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut13:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut14:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lut15:22;
        RBus_UInt32  res1:10;
    };
}color_sharp_dm_auto_shp_fir_count_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  edg_d2_shift_bit:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  gain_neg2:2;
        RBus_UInt32  gain_pos2:2;
    };
}color_sharp_dm_segpk_edgpk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_segpk_edgpk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv2:8;
        RBus_UInt32  res1:24;
    };
}color_sharp_dm_segpk_edgpk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c2_0:8;
        RBus_UInt32  coef_c1_0:8;
        RBus_UInt32  coef_c0_0:9;
        RBus_UInt32  res1:7;
    };
}color_sharp_dm_2d_shp_edge_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c6_0:8;
        RBus_UInt32  coef_c5_0:8;
        RBus_UInt32  coef_c4_0:8;
        RBus_UInt32  coef_c3_0:8;
    };
}color_sharp_dm_2d_shp_edge_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c10_0:8;
        RBus_UInt32  coef_c9_0:8;
        RBus_UInt32  coef_c8_0:8;
        RBus_UInt32  coef_c7_0:8;
    };
}color_sharp_dm_2d_shp_edge_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3_1:8;
        RBus_UInt32  coef_c2_1:8;
        RBus_UInt32  coef_c1_1:8;
        RBus_UInt32  coef_c0_1:8;
    };
}color_sharp_dm_2d_shp_edge_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  coef_c5_1:8;
        RBus_UInt32  coef_c4_1:8;
    };
}color_sharp_dm_2d_shp_edge_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3_2:8;
        RBus_UInt32  coef_c2_2:8;
        RBus_UInt32  coef_c1_2:8;
        RBus_UInt32  coef_c0_2:8;
    };
}color_sharp_dm_2d_shp_edge_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  coef_c5_2:8;
        RBus_UInt32  coef_c4_2:8;
    };
}color_sharp_dm_2d_shp_edge_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coef_c0_3:8;
    };
}color_sharp_dm_2d_shp_edge_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  coef_c0_4:8;
    };
}color_sharp_dm_2d_shp_edge_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  edg_lpf_shift:4;
    };
}color_sharp_dm_2d_shp_edge_shift_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  emf_shift:3;
        RBus_UInt32  emf_range:2;
        RBus_UInt32  emf_range_force_h_11tap:1;
        RBus_UInt32  emf_range_force_v_5tap:1;
        RBus_UInt32  seg0_gain_sel:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  seg1_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg2_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg0_offset:11;
        RBus_UInt32  res5:1;
    };
}color_sharp_dm_peaking_emf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emf_mode_sel:1;
        RBus_UInt32  emf_mk2_debug:1;
        RBus_UInt32  aov_range:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  blend_wt:4;
        RBus_UInt32  lowbnd:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  blendstepbit:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  declinebit:2;
        RBus_UInt32  res4:6;
    };
}color_sharp_dm_emfmk2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  emf_fixextent_neg:8;
        RBus_UInt32  emf_fixextent_pos:8;
        RBus_UInt32  seg1_offset:11;
        RBus_UInt32  res1:5;
    };
}color_sharp_dm_emf_ext_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg2_offset:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  seg0_x:10;
        RBus_UInt32  seg1_x:10;
    };
}color_sharp_dm_emf_ext_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smalledge_ulevel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  deltaedge_ratio:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smalledge_ratio:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  bigedge_ratio:5;
        RBus_UInt32  res4:3;
    };
}color_sharp_dm_segpk_edge_coring_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edge_ser_range:4;
        RBus_UInt32  edge_gain_bound:5;
        RBus_UInt32  edge_delta_ext_range:3;
        RBus_UInt32  edge_coring_clip:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  deltaedge_ulevel:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  edge_coring_debug:2;
        RBus_UInt32  edge_gain_en:1;
        RBus_UInt32  edge_coring_en:1;
    };
}color_sharp_dm_segpk_edge_coring_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_extendneg:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gain_extendpos:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gain_boundneg:4;
        RBus_UInt32  gain_boundpos:4;
        RBus_UInt32  fh:1;
        RBus_UInt32  dir:1;
        RBus_UInt32  slope_gain_en:1;
        RBus_UInt32  res3:5;
    };
}color_sharp_dm_segpk_edgpk_sourceslope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_c0:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  vpk_c1:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  vpk_c2:8;
    };
}color_sharp_dm_segpk_vpk1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_gain_pos:8;
        RBus_UInt32  vpk_gain_neg:8;
        RBus_UInt32  vpk_lv:8;
        RBus_UInt32  res1:8;
    };
}color_sharp_dm_segpk_vpk2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_hv_neg:8;
        RBus_UInt32  vpk_hv_pos:8;
        RBus_UInt32  gain_neg2:2;
        RBus_UInt32  gain_pos2:2;
        RBus_UInt32  lv2:8;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_segpk_vpk3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_en:1;
        RBus_UInt32  vemf_en:1;
        RBus_UInt32  v_tex_en:1;
        RBus_UInt32  v_dering_en:1;
        RBus_UInt32  vpk_edg_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  vext_reg:8;
        RBus_UInt32  vpk_c4:8;
        RBus_UInt32  vpk_c3:8;
    };
}color_sharp_dm_segpk_vpk4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_wtsum_enable:1;
        RBus_UInt32  v_wtsum_level:3;
        RBus_UInt32  v_wtsum_tap:1;
        RBus_UInt32  res1:27;
    };
}color_sharp_dm_segpk_vwsum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_lb_0:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  u_ub_0:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  cds_debug:3;
        RBus_UInt32  cds_enable:1;
        RBus_UInt32  cds_cm0_enable:1;
        RBus_UInt32  res3:3;
    };
}color_sharp_dm_cds_cm0_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_lb_0:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_0:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  cm0_conti_enable:1;
        RBus_UInt32  cm0_conti_area:5;
        RBus_UInt32  cm0_mode:2;
    };
}color_sharp_dm_cds_cm0_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cu_0:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  cv_0:10;
        RBus_UInt32  uv_rad_0:9;
        RBus_UInt32  res2:1;
    };
}color_sharp_dm_cds_cm0_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_0:24;
        RBus_UInt32  res1:8;
    };
}color_sharp_dm_cds_cm0_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm0_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm0_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm0_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm0_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_lb_1:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  u_ub_1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  cds_cm1_enable:1;
        RBus_UInt32  res3:3;
    };
}color_sharp_dm_cds_cm1_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_lb_1:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_1:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  cm1_conti_enable:1;
        RBus_UInt32  cm1_conti_area:5;
        RBus_UInt32  cm1_mode:2;
    };
}color_sharp_dm_cds_cm1_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cu_1:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  cv_1:10;
        RBus_UInt32  uv_rad_1:9;
        RBus_UInt32  res2:1;
    };
}color_sharp_dm_cds_cm1_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_1:24;
        RBus_UInt32  res1:8;
    };
}color_sharp_dm_cds_cm1_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm1_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm1_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm1_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm1_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_lb_2:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  u_ub_2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  cds_cm2_enable:1;
        RBus_UInt32  res3:3;
    };
}color_sharp_dm_cds_cm2_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_lb_2:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_2:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  cm2_conti_enable:1;
        RBus_UInt32  cm2_conti_area:5;
        RBus_UInt32  cm2_mode:2;
    };
}color_sharp_dm_cds_cm2_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cu_2:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  cv_2:10;
        RBus_UInt32  uv_rad_2:9;
        RBus_UInt32  res2:1;
    };
}color_sharp_dm_cds_cm2_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_2:24;
        RBus_UInt32  res1:8;
    };
}color_sharp_dm_cds_cm2_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm2_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm2_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm2_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm2_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  u_lb_3:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  u_ub_3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  cds_cm3_enable:1;
        RBus_UInt32  res3:3;
    };
}color_sharp_dm_cds_cm3_u_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v_lb_3:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  v_ub_3:11;
        RBus_UInt32  res2:1;
        RBus_UInt32  cm3_conti_enable:1;
        RBus_UInt32  cm3_conti_area:5;
        RBus_UInt32  cm3_mode:2;
    };
}color_sharp_dm_cds_cm3_v_bound_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cu_3:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  cv_3:10;
        RBus_UInt32  uv_rad_3:9;
        RBus_UInt32  res2:1;
    };
}color_sharp_dm_cds_cm3_u_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_3:24;
        RBus_UInt32  res1:8;
    };
}color_sharp_dm_cds_cm3_v_bound_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm3_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm3_tex_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_cds_peaking_gain_cm3_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_dm_cds_peaking_bound_cm3_edge_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  coef_c2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  coef_c1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  coef_c0:6;
        RBus_UInt32  res4:2;
    };
}color_sharp_dm_sours_lpf_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  coef_c4:6;
        RBus_UInt32  res2:18;
    };
}color_sharp_dm_sours_lpf_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s0:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:11;
        RBus_UInt32  res1:21;
    };
}color_sharp_dm_maxmin_shp_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_shp_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_0:32;
    };
}color_sharp_dm_cds_cm0_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_0:32;
    };
}color_sharp_dm_cds_cm0_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_0:32;
    };
}color_sharp_dm_cds_cm0_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_1:32;
    };
}color_sharp_dm_cds_cm1_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_1:32;
    };
}color_sharp_dm_cds_cm1_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_1:32;
    };
}color_sharp_dm_cds_cm1_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_2:32;
    };
}color_sharp_dm_cds_cm2_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_2:32;
    };
}color_sharp_dm_cds_cm2_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_2:32;
    };
}color_sharp_dm_cds_cm2_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_3:32;
    };
}color_sharp_dm_cds_cm3_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_3:32;
    };
}color_sharp_dm_cds_cm3_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_3:32;
    };
}color_sharp_dm_cds_cm3_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_sel:1;
        RBus_UInt32  hpf_vpf_maxmin_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  dummy1802b818_31:28;
    };
}color_sharp_dm_vpk_hpk_add_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  coef_c3:8;
        RBus_UInt32  coef_c2:8;
        RBus_UInt32  coef_c1:8;
        RBus_UInt32  coef_c0:8;
    };
}color_sharp_dm_vc_after_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  mode:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  hpf_gain:8;
        RBus_UInt32  coef_c4:8;
    };
}color_sharp_dm_vc_after_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s13:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_pos_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s6:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s4:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s12:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s10:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  s13:10;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_vertical_pos_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s13:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_vertical_neg_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s6:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s4:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s12:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s10:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  s14:10;
        RBus_UInt32  s13:10;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_vertical_neg_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  debug_step:4;
        RBus_UInt32  res3:4;
        RBus_UInt32  hpf_out_debug_sel:3;
        RBus_UInt32  hpf_out_debug_en:1;
        RBus_UInt32  res4:12;
    };
}color_sharp_dm_gain_curve_debug_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  offset:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  gain:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  period:4;
        RBus_UInt32  res3:4;
    };
}color_sharp_dm_sr_continual_detail_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  edg_filter_sel:2;
        RBus_UInt32  tex_filter_sel:2;
        RBus_UInt32  hv_max:2;
        RBus_UInt32  ring_gen:2;
        RBus_UInt32  ring_gen_gain:8;
        RBus_UInt32  res1:16;
    };
}color_sharp_dm_sr_continual_detail_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:9;
        RBus_UInt32  res1:23;
    };
}color_sharp_dm_sr_9tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
    };
}color_sharp_dm_sr_9tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_13tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c6:8;
        RBus_UInt32  c5:8;
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
    };
}color_sharp_dm_sr_13tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_21tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c6:8;
        RBus_UInt32  c5:8;
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
    };
}color_sharp_dm_sr_21tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c10:8;
        RBus_UInt32  c9:8;
        RBus_UInt32  c8:8;
        RBus_UInt32  c7:8;
    };
}color_sharp_dm_sr_21tap_hpf_h_coef_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_0_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_0_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:8;
        RBus_UInt32  res1:15;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_11tap_hpf_h_coef_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c5:8;
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c2:8;
    };
}color_sharp_dm_sr_11tap_hpf_h_coef_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  c0:9;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_3_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c4:8;
        RBus_UInt32  c3:8;
        RBus_UInt32  c2:8;
        RBus_UInt32  c1:8;
    };
}color_sharp_dm_sr_9tap_hpf_v_coef_3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  meandiff_lowbd:8;
        RBus_UInt32  meandiff_step:3;
        RBus_UInt32  meandiff_shiftbit:3;
        RBus_UInt32  meandiff_rangev:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  meandiff_rangeh:2;
        RBus_UInt32  dirsm_rangv:1;
        RBus_UInt32  dirsm_rangh:1;
        RBus_UInt32  res2:10;
    };
}color_sharp_dm_edge_sm_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dism_debug_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  edgeindex_lowbd:8;
        RBus_UInt32  edgeindex_step:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  edge_method_sel:1;
        RBus_UInt32  res3:11;
    };
}color_sharp_dm_edge_sm_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s13:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_pos_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_pos_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s6:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s4:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_pos_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_pos_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s12:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s10:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_pos_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  s13:10;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_edge_pos_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s13:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_edge_neg_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_neg_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s6:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s4:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_neg_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_neg_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s12:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s10:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_edge_neg_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  s14:10;
        RBus_UInt32  s13:10;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_edge_neg_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s13:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_pos_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_pos_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s6:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s4:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_pos_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_pos_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s12:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s10:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_pos_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  s14:10;
        RBus_UInt32  s13:10;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_tex_pos_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s0:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s2:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s4:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s6:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s8:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s11:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s10:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s13:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  s12:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s14:10;
        RBus_UInt32  res2:6;
    };
}color_sharp_dm_tex_neg_gain_curve_gain_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:10;
        RBus_UInt32  s2:10;
        RBus_UInt32  s1:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_neg_gain_curve_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s6:10;
        RBus_UInt32  s5:10;
        RBus_UInt32  s4:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_neg_gain_curve_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s9:10;
        RBus_UInt32  s8:10;
        RBus_UInt32  s7:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_neg_gain_curve_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s12:10;
        RBus_UInt32  s11:10;
        RBus_UInt32  s10:10;
        RBus_UInt32  res1:2;
    };
}color_sharp_dm_tex_neg_gain_curve_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  s14:10;
        RBus_UInt32  s13:10;
        RBus_UInt32  res2:2;
    };
}color_sharp_dm_tex_neg_gain_curve_step_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_edg_gain_pos:8;
        RBus_UInt32  vpk_edg_gain_neg:8;
        RBus_UInt32  vpk_edg_lv:8;
        RBus_UInt32  res1:8;
    };
}color_sharp_dm_segpk_vpk5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpk_edg_hv_neg:10;
        RBus_UInt32  vpk_edg_hv_pos:10;
        RBus_UInt32  vpk_edg_gain_neg2:2;
        RBus_UInt32  vpk_edg_gain_pos2:2;
        RBus_UInt32  edg_lv2:8;
    };
}color_sharp_dm_segpk_vpk6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_extendneg_v:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  gain_extendpos_v:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  gain_boundneg_v:4;
        RBus_UInt32  gain_boundpos_v:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  dir_v:1;
        RBus_UInt32  v_slope_gain_en:1;
        RBus_UInt32  res4:5;
    };
}color_sharp_dm_segpk_edgpk_vsourceslope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s0:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_weit_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_weit_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_weit_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_weit_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:11;
        RBus_UInt32  res1:21;
    };
}color_sharp_dm_maxmin_lpf_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_lpf_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s0:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_gain_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s1:11;
        RBus_UInt32  res1:21;
    };
}color_sharp_dm_maxmin_gain_by_y_step_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s2:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_step_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  s5:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  s4:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_step_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  s6:11;
        RBus_UInt32  res2:5;
    };
}color_sharp_dm_maxmin_gain_by_y_step_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  peaking_enable:1;
        RBus_UInt32  emf_enable:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  clp_enable:1;
        RBus_UInt32  res2:22;
    };
}color_sharp_ds_nr_shp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c1:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  c0:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  sh_b1:2;
        RBus_UInt32  sh_b0:2;
        RBus_UInt32  res3:4;
    };
}color_sharp_ds_peaking_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  c4:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c3:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  c2:8;
    };
}color_sharp_ds_peaking_filter_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_neg:8;
        RBus_UInt32  gain_pos:8;
        RBus_UInt32  gain_blr:8;
        RBus_UInt32  res1:8;
    };
}color_sharp_ds_peaking_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lv:8;
        RBus_UInt32  hv_neg:10;
        RBus_UInt32  hv_pos:10;
        RBus_UInt32  res1:4;
    };
}color_sharp_ds_peaking_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  emf_shift:3;
        RBus_UInt32  res2:4;
        RBus_UInt32  seg0_gain_sel:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  seg1_gain_sel:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  seg2_gain_sel:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  seg0_offset:11;
        RBus_UInt32  res6:1;
    };
}color_sharp_ds_peaking_emf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blur_fac:5;
        RBus_UInt32  res1:27;
    };
}color_sharp_ds_chroma_lowpass_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  seg1_offset:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  seg2_offset:11;
        RBus_UInt32  res2:9;
    };
}color_sharp_ds_peaking_emf_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  crc_start:1;
        RBus_UInt32  crc_conti:1;
        RBus_UInt32  crc_channel:1;
        RBus_UInt32  res1:29;
    };
}color_sharp_shp_crc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  shp_crc_result:32;
    };
}color_sharp_shp_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bist_fail_0:1;
        RBus_UInt32  bist_fail_1:1;
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  dvs:4;
        RBus_UInt32  dvse:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res1:22;
    };
}color_sharp_peak2d_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bisr_repaired:1;
        RBus_UInt32  drf_fail_7:1;
        RBus_UInt32  drf_fail_6:1;
        RBus_UInt32  drf_fail_5:1;
        RBus_UInt32  drf_fail_4:1;
        RBus_UInt32  drf_fail_3:1;
        RBus_UInt32  drf_fail_2:1;
        RBus_UInt32  drf_fail_1:1;
        RBus_UInt32  drf_fail_0:1;
        RBus_UInt32  bisr_fail_7:1;
        RBus_UInt32  bisr_fail_6:1;
        RBus_UInt32  bisr_fail_5:1;
        RBus_UInt32  bisr_fail_4:1;
        RBus_UInt32  bisr_fail_3:1;
        RBus_UInt32  bisr_fail_2:1;
        RBus_UInt32  bisr_fail_1:1;
        RBus_UInt32  bisr_fail_0:1;
        RBus_UInt32  dvs:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  dvse:1;
        RBus_UInt32  ls:1;
        RBus_UInt32  res2:5;
    };
}color_sharp_peak2d_bisr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_en:1;
        RBus_UInt32  ovc_en:1;
        RBus_UInt32  tn_blend_en:1;
        RBus_UInt32  tn_blend_mode:1;
        RBus_UInt32  ffd2_en:1;
        RBus_UInt32  d1_cp_shift:2;
        RBus_UInt32  rn_extend_en:1;
        RBus_UInt32  dcp_th:8;
        RBus_UInt32  pnth:10;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  can_shift:2;
        RBus_UInt32  data_sel:1;
    };
}color_sharp_shp_dlti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ffd1_th:10;
        RBus_UInt32  ffd1_ratio:7;
        RBus_UInt32  res1:12;
        RBus_UInt32  dlti_debug:3;
    };
}color_sharp_shp_dlti_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ffd2_range2l:10;
        RBus_UInt32  ffd2_range2r:10;
        RBus_UInt32  ffd2_ratio:7;
        RBus_UInt32  res1:5;
    };
}color_sharp_shp_dlti_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnoff0:4;
        RBus_UInt32  tngain0:5;
        RBus_UInt32  tnoff1:4;
        RBus_UInt32  tngain1:5;
        RBus_UInt32  tnoff2:4;
        RBus_UInt32  tngain2:5;
        RBus_UInt32  res1:5;
    };
}color_sharp_shp_dlti_gain_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnoff3:4;
        RBus_UInt32  tngain3:5;
        RBus_UInt32  tnoff4:4;
        RBus_UInt32  tngain4:5;
        RBus_UInt32  tnoff5:4;
        RBus_UInt32  tngain5:5;
        RBus_UInt32  res1:5;
    };
}color_sharp_shp_dlti_gain_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnoff6:4;
        RBus_UInt32  tngain6:5;
        RBus_UInt32  tnoff7:4;
        RBus_UInt32  tngain7:5;
        RBus_UInt32  tnoff8:4;
        RBus_UInt32  tngain8:5;
        RBus_UInt32  res1:5;
    };
}color_sharp_shp_dlti_gain_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnoff9:4;
        RBus_UInt32  tngain9:5;
        RBus_UInt32  tnoff10:4;
        RBus_UInt32  tngain10:5;
        RBus_UInt32  tnoff11:4;
        RBus_UInt32  tngain11:5;
        RBus_UInt32  res1:5;
    };
}color_sharp_shp_dlti_gain_offset_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnoff12:4;
        RBus_UInt32  tngain12:5;
        RBus_UInt32  tnoff13:4;
        RBus_UInt32  tngain13:5;
        RBus_UInt32  tnoff14:4;
        RBus_UInt32  tngain14:5;
        RBus_UInt32  res1:5;
    };
}color_sharp_shp_dlti_gain_offset_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cur_sel:1;
        RBus_UInt32  uvalign_en:1;
        RBus_UInt32  dcti_mode:1;
        RBus_UInt32  uvgain:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  offdiv:2;
        RBus_UInt32  engdiv:2;
        RBus_UInt32  lpmode:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  psmth:8;
        RBus_UInt32  maxlen:3;
        RBus_UInt32  data_sel:1;
    };
}color_sharp_shp_dcti_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  blending_mode:1;
        RBus_UInt32  median_mode:1;
        RBus_UInt32  vlp_mode:3;
        RBus_UInt32  hp_mode:3;
        RBus_UInt32  steep_mode:3;
        RBus_UInt32  th_coring:5;
        RBus_UInt32  th_steep:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  rate_steep:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  tran_mode:3;
        RBus_UInt32  uvsync_en:1;
    };
}color_sharp_shp_dcti_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_smooth:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  rate_smooth:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  region_mode:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  th_tran:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  rate_tran:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  maxminlen:3;
        RBus_UInt32  res6:1;
    };
}color_sharp_shp_dcti_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_gtran:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  align_mingain:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  th_align:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  rate_align:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  rate_align_weight:3;
        RBus_UInt32  res5:1;
    };
}color_sharp_shp_dcti_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_align_weight:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  th_stair:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rate_stair1:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  rate_stair2:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  th_uvmindiff:7;
        RBus_UInt32  res5:1;
    };
}color_sharp_shp_dcti_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  th_engsync:6;
        RBus_UInt32  rate_uvmindiff:3;
        RBus_UInt32  rate_engsync:3;
        RBus_UInt32  res1:19;
        RBus_UInt32  res2:1;
    };
}color_sharp_shp_dcti_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  res2:6;
        RBus_UInt32  debug_mode:3;
        RBus_UInt32  debug_shiftbit:3;
        RBus_UInt32  res3:14;
    };
}color_sharp_shp_dcti_ctrl_7_RBUS;




#endif 


#endif 
