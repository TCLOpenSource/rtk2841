/**
* @file rbusVDPQReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_VDPQ_REG_H_
#define _RBUS_VDPQ_REG_H_

#include "rbusTypes.h"


//  VDPQ Register Address



#define  VDPQ_FRAME_BUF_CHK3D_CTRL0_VADDR                   	(0xb8019800)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL1_VADDR                   	(0xb8019804)
#define  VDPQ_FRAME_BUF_CHK3D_CTRL2_VADDR                   	(0xb8019808)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_CTRL_VADDR                	(0xb801980c)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM1_BYTE_VADDR           	(0xb8019810)
#define  VDPQ_FRAME_BUF_CHK3D_CEN_NUM2_BYTE_VADDR           	(0xb8019814)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_CTRL_VADDR           	(0xb8019818)
#define  VDPQ_FRAME_BUF_CHK3D_HEN_NUM1_BYTE_VADDR           	(0xb801981c)
#define  VDPQ_DMA_VACTIVE_ST1_VADDR                         	(0xb8019830)
#define  VDPQ_DMA_VACTIVE_END1_VADDR                        	(0xb8019834)
#define  VDPQ_DMA_VACTIVE_ST2_VADDR                         	(0xb8019838)
#define  VDPQ_DMA_VACTIVE_END2_VADDR                        	(0xb801983c)
#define  VDPQ_DMA_CTRL1_VADDR                               	(0xb8019840)
#define  VDPQ_DMA_CTRL2_VADDR                               	(0xb8019844)
#define  VDPQ_DMA_CTRL3_VADDR                               	(0xb8019848)
#define  VDPQ_DMA_CTRL4_VADDR                               	(0xb801984c)
#define  VDPQ_DMA_CTRL5_VADDR                               	(0xb8019850)
#define  VDPQ_DMA_CTRL6_VADDR                               	(0xb8019854)
#define  VDPQ_DEBUG_DMA_IF_CTRL_VADDR                       	(0xb8019858)
#define  VDPQ_VD_SRAM_ON_OFF_VADDR                          	(0xb801985c)
#define  VDPQ_MEM0_ADDR_INI_VADDR                           	(0xb8019870)
#define  VDPQ_MEM1_ADDR_INI_VADDR                           	(0xb8019874)
#define  VDPQ_MEM2_ADDR_INI_VADDR                           	(0xb8019878)
#define  VDPQ_MEM3_ADDR_INI_VADDR                           	(0xb801987c)
#define  VDPQ_MEM0_ADDR_END_VADDR                           	(0xb8019880)
#define  VDPQ_MEM1_ADDR_END_VADDR                           	(0xb8019884)
#define  VDPQ_MEM2_ADDR_END_VADDR                           	(0xb8019888)
#define  VDPQ_MEM3_ADDR_END_VADDR                           	(0xb801988c)
#define  VDPQ_DMA_DEBUG_ADDR_VADDR                          	(0xb8019890)
#define  VDPQ_DMA_DEBUG_VBI_END_ADDR_VADDR                  	(0xb8019894)
#define  VDPQ_VIDEO_DMA_DEBUG_CTRL_VADDR                    	(0xb8019898)
#define  VDPQ_VBIDMA_TEST_CTRL_VADDR                        	(0xb801989c)
#define  VDPQ_DMA_CNT_CALIBRATION1_VADDR                    	(0xb80198a0)
#define  VDPQ_DMA_CNT_CALIBRATION2_VADDR                    	(0xb80198a4)
#define  VDPQ_DMA_CNT_CALIBRATION3_VADDR                    	(0xb80198a8)
#define  VDPQ_FRAME_BUFFER_F1_STATUS_VADDR                  	(0xb80198d0)
#define  VDPQ_FRAME_BUFFER_F2_STATUS_VADDR                  	(0xb80198d4)
#define  VDPQ_DUMMY_1_VADDR                                 	(0xb80198d8)
#define  VDPQ_DUMMY_2_VADDR                                 	(0xb80198dc)
#define  VDPQ_YC_SEP_CONTROL_VADDR                          	(0xb8019900)
#define  VDPQ_BPF_BW_SEL_Y_VADDR                            	(0xb8019904)
#define  VDPQ_BPF_BW_SEL_C_VADDR                            	(0xb8019908)
#define  VDPQ_ADAP_BPF_C_TH1_VADDR                          	(0xb801990c)
#define  VDPQ_ADAP_BPF_C_TH2_VADDR                          	(0xb8019910)
#define  VDPQ_COMB_FILTER_CONFIG_VADDR                      	(0xb8019914)
#define  VDPQ_COMB_FILTER_THRESHOLD1_VADDR                  	(0xb8019918)
#define  VDPQ_ADAP_BPF_Y_TH3_VADDR                          	(0xb8019928)
#define  VDPQ_YC_BW_CTRL_VADDR                              	(0xb801992c)
#define  VDPQ_DEBUG_2D_MODE_VADDR                           	(0xb8019930)
#define  VDPQ_BW_DETECTION_VADDR                            	(0xb8019934)
#define  VDPQ_BW_EDGE_THR_VADDR                             	(0xb8019938)
#define  VDPQ_BLEND_1D_THR_VADDR                            	(0xb801993c)
#define  VDPQ_BLEND_1D_BPF_SEL_VADDR                        	(0xb8019940)
#define  VDPQ_ALPHA_2D_MOD_ENABLE_VADDR                     	(0xb8019944)
#define  VDPQ_H2V_CORING_THR_VADDR                          	(0xb8019948)
#define  VDPQ_H2V_Y_NOISE_THR_VADDR                         	(0xb801994c)
#define  VDPQ_H2V_CVBS_NOISE_THR_VADDR                      	(0xb8019950)
#define  VDPQ_H2V_NOISE_MAX_HDY_VADDR                       	(0xb8019954)
#define  VDPQ_H2V_NOISE_Y_ADD_DC_VADDR                      	(0xb8019958)
#define  VDPQ_H2V_BLEND_RATIO_VADDR                         	(0xb801995c)
#define  VDPQ_ADAP_BPF_Y_TH2_VADDR                          	(0xb8019960)
#define  VDPQ_CDIFF_ADAP_BPF_TH1_VADDR                      	(0xb8019964)
#define  VDPQ_CDIFF_ADAP_BPF_TH2_VADDR                      	(0xb8019968)
#define  VDPQ_BPF_VEDGE_CTRL1_VADDR                         	(0xb8019970)
#define  VDPQ_BPF_VEDGE_CTRL2_VADDR                         	(0xb8019974)
#define  VDPQ_BYPASS_BPF_CTRL1_VADDR                        	(0xb8019978)
#define  VDPQ_BYPASS_BPF_CTRL2_VADDR                        	(0xb801997c)
#define  VDPQ_GRIDGIRL_CTRL_VADDR                           	(0xb8019988)
#define  VDPQ_GRIDGIRL_TH1_VADDR                            	(0xb801998c)
#define  VDPQ_GRIDGIRL_TH2_VADDR                            	(0xb8019990)
#define  VDPQ_GRIDGIRL_TH3_VADDR                            	(0xb8019994)
#define  VDPQ_GRIDGIRL_TH4_VADDR                            	(0xb8019998)
#define  VDPQ_DIAMC_CVBS_AMP_TH_VADDR                       	(0xb801999c)
#define  VDPQ_DIAMC_CTRL_VADDR                              	(0xb80199a0)
#define  VDPQ_VMC_CTRL_VADDR                                	(0xb80199a4)
#define  VDPQ_VMC_SPATIAL_CORR_CTRL_VADDR                   	(0xb80199a8)
#define  VDPQ_YC2D_POSTLP_CTRL_VADDR                        	(0xb80199d0)
#define  VDPQ_YC2D_POSTLP_FLAT_1_VADDR                      	(0xb80199d4)
#define  VDPQ_YC2D_POSTLP_FLAT_2_VADDR                      	(0xb80199d8)
#define  VDPQ_YC2D_POSTLP_FLAT_3_VADDR                      	(0xb80199dc)
#define  VDPQ_YC2D_POSTLP_FLAT_4_VADDR                      	(0xb80199e0)
#define  VDPQ_YC2D_POSTLP_GRAD_1_VADDR                      	(0xb80199e4)
#define  VDPQ_YC2D_POSTLP_GRAD_2_VADDR                      	(0xb80199e8)
#define  VDPQ_YC2D_POSTLP_GRAD_3_VADDR                      	(0xb80199ec)
#define  VDPQ_YC2D_POSTLP_DIA_1_VADDR                       	(0xb80199f0)
#define  VDPQ_YC2D_POSTLP_DIA_2_VADDR                       	(0xb80199f4)
#define  VDPQ_YC2D_POSTLP_DIA_3_VADDR                       	(0xb80199f8)
#define  VDPQ_YC2D_POSTLP_DIA_4_VADDR                       	(0xb80199fc)
#define  VDPQ_YC_SEP_MODE_CTRL_VADDR                        	(0xb8019b28)
#define  VDPQ_DUMMY_3_VADDR                                 	(0xb8019b2c)
#define  VDPQ_YC_3DSEP_CHROMA_BPF_SEL_VADDR                 	(0xb8019b30)
#define  VDPQ_YC_3D_F4_SLP_MONO_VADDR                       	(0xb8019cfc)
#define  VDPQ_YC_3D_F4_STAT_1_VADDR                         	(0xb8019d00)
#define  VDPQ_YC_3D_F4_STAT_2_VADDR                         	(0xb8019d04)
#define  VDPQ_YC_3D_F4_STAT_3_VADDR                         	(0xb8019d08)
#define  VDPQ_YC_3D_F4_SLP_1_VADDR                          	(0xb8019d0c)
#define  VDPQ_YC_3D_F4_SLP_2_VADDR                          	(0xb8019d10)
#define  VDPQ_YC_3D_F4_SLP_3_VADDR                          	(0xb8019d14)
#define  VDPQ_YC_3D_F4_NTSC_ABA_1_VADDR                     	(0xb8019d18)
#define  VDPQ_YC_3D_F4_NTSC_ABA_2_VADDR                     	(0xb8019d1c)
#define  VDPQ_DUMMY_4_VADDR                                 	(0xb8019d20)
#define  VDPQ_YC_3D_F4_CTRL_VADDR                           	(0xb8019d24)
#define  VDPQ_YC_3D_F4_SPA_CNT_CVBS_AMP_VADDR               	(0xb8019d28)
#define  VDPQ_YC_3D_F4_HV_EDGE_1_VADDR                      	(0xb8019d2c)
#define  VDPQ_YC_3D_F4_HV_EDGE_2_VADDR                      	(0xb8019d30)
#define  VDPQ_YC_3D_F4_HIFREQ_DET_VADDR                     	(0xb8019d34)
#define  VDPQ_YC_3D_F4_DC_COMPARE_VADDR                     	(0xb8019d38)
#define  VDPQ_YC_3D_F4_PAL_ERR_COM_1_VADDR                  	(0xb8019d3c)
#define  VDPQ_YC_3D_F4_PAL_ERR_COM_2_VADDR                  	(0xb8019d40)
#define  VDPQ_YC_3D_F4_PAL_ERR_COM_3_VADDR                  	(0xb8019d44)
#define  VDPQ_YC_3D_F4_STILL_VECTOR_1_VADDR                 	(0xb8019d48)
#define  VDPQ_YC_3D_F4_STILL_VECTOR_2_VADDR                 	(0xb8019d4c)
#define  VDPQ_YC_3D_F4_STILL_GRAY_HIFREQ_1_VADDR            	(0xb8019d50)
#define  VDPQ_YC_3D_F4_STILL_GRAY_HIFREQ_2_VADDR            	(0xb8019d54)
#define  VDPQ_YC_3D_F4_PAIR_TH_MULTIPLE_1_VADDR             	(0xb8019d58)
#define  VDPQ_YC_3D_F4_PAIR_TH_MULTIPLE_2_VADDR             	(0xb8019d5c)
#define  VDPQ_YC_3D_F4_PAIR_TH_MULTIPLE_3_VADDR             	(0xb8019d60)
#define  VDPQ_YC_3D_F4_PAIR_TH_BASE_1_VADDR                 	(0xb8019d64)
#define  VDPQ_YC_3D_F4_PAIR_TH_BASE_2_VADDR                 	(0xb8019d68)
#define  VDPQ_YC_3D_F4_PAIR_TH_BASE_3_VADDR                 	(0xb8019d6c)
#define  VDPQ_YC_3D_F4_PAIR_CTRL_1_VADDR                    	(0xb8019d70)
#define  VDPQ_YC_3D_F4_PAIR_CTRL_2_VADDR                    	(0xb8019d74)
#define  VDPQ_YC_3D_F4_PAIR_CTRL_3_VADDR                    	(0xb8019d78)
#define  VDPQ_YC_3D_F4_PAIR_CTRL_4_VADDR                    	(0xb8019d7c)
#define  VDPQ_YC_3D_F4_PAIR_CTRL_5_VADDR                    	(0xb8019d80)
#define  VDPQ_YC_3D_F4_PAIR_CTRL_6_VADDR                    	(0xb8019d84)
#define  VDPQ_YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_1_VADDR 	(0xb8019d88)
#define  VDPQ_YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_2_VADDR 	(0xb8019d8c)
#define  VDPQ_YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_3_VADDR 	(0xb8019d90)
#define  VDPQ_YC_3D_F4_GLOBAL_DIFF_TH_HIFREQ_OFFSET_4_VADDR 	(0xb8019d94)
#define  VDPQ_YC_3D_F4_MGHF_CTRL_1_VADDR                    	(0xb8019d98)
#define  VDPQ_YC_3D_F4_MGHF_CTRL_2_VADDR                    	(0xb8019d9c)
#define  VDPQ_YC_3D_F4_GLOBAL_DIFF_TH_COM_VADDR             	(0xb8019da0)
#define  VDPQ_YC_POST2DBPF_DBWLINE_1_VADDR                  	(0xb8019da4)
#define  VDPQ_YC_POST2DBPF_DBWLINE_2_VADDR                  	(0xb8019da8)
#define  VDPQ_YC_POST2DBPF_DBWLINE_3_VADDR                  	(0xb8019dac)
#define  VDPQ_YC_POST2DBPF_CTRL_VADDR                       	(0xb8019db0)
#define  VDPQ_YC_POST2DBPF_THBASE_VADDR                     	(0xb8019db4)
#define  VDPQ_YC_POST2DBPF_ADAPTH_1_VADDR                   	(0xb8019db8)
#define  VDPQ_YC_POST2DBPF_ADAPTH_2_VADDR                   	(0xb8019dbc)
#define  VDPQ_YC_POST2DBPF_ADAPTH_3_VADDR                   	(0xb8019dc0)
#define  VDPQ_YC_POST2DBPF_ADAPTH_4_VADDR                   	(0xb8019dc4)
#define  VDPQ_YC_POST2DBPF_ADAPTH_5_VADDR                   	(0xb8019dc8)
#define  VDPQ_YC_POST2DBPF_ADAPTH_6_VADDR                   	(0xb8019dcc)
#define  VDPQ_YC_POST2DBPF_ADAPTH_7_VADDR                   	(0xb8019dd0)
#define  VDPQ_YC_POST2DBPF_ADAPTH_8_VADDR                   	(0xb8019dd4)
#define  VDPQ_YC_POST2DBPF_ADAPTH_9_VADDR                   	(0xb8019dd8)
#define  VDPQ_YC_POST2DBPF_ADAPTH_10_VADDR                  	(0xb8019ddc)
#define  VDPQ_YC_POST2DBPF_ADAPTH_11_VADDR                  	(0xb8019de0)
#define  VDPQ_YC_POST2DBPF_ADAPTH_12_VADDR                  	(0xb8019de4)
#define  VDPQ_YC_POST2DBPF_ADAPTH_13_VADDR                  	(0xb8019de8)
#define  VDPQ_YC_POST2DBPF_XC_VADDR                         	(0xb8019dec)
#define  VDPQ_SECAM_YADAP_MODE_VADDR                        	(0xb8019df0)
#define  VDPQ_SECAM_YADAP_CTRL1_VADDR                       	(0xb8019df4)
#define  VDPQ_SECAM_YADAP_CTRL2_VADDR                       	(0xb8019df8)
#define  VDPQ_XNR_CTRL_VADDR                                	(0xb8019e04)
#define  VDPQ_XNR_THR_VADDR                                 	(0xb8019e08)
#define  VDPQ_XNR_IDX_THR_VADDR                             	(0xb8019e0c)
#define  VDPQ_XNR_RATIO_CTRL_VADDR                          	(0xb8019e10)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL1_VADDR             	(0xb8019e14)
#define  VDPQ_POSTP_MF_COMPENSATION_CTRL2_VADDR             	(0xb8019e18)
#define  VDPQ_YC2D_POSTPK2_CTRL1_VADDR                      	(0xb8019e1c)
#define  VDPQ_YC2D_POSTPK2_ADAP1_VADDR                      	(0xb8019e20)
#define  VDPQ_YC2D_POSTPK2_DNOISE1_VADDR                    	(0xb8019e24)
#define  VDPQ_YC2D_POSTPK2_FILTER_0_VADDR                   	(0xb8019e28)
#define  VDPQ_YC2D_POSTPK2_GAIN_VADDR                       	(0xb8019e2c)
#define  VDPQ_YC2D_POSTPK2_BOUND_VADDR                      	(0xb8019e30)
#define  VDPQ_POSTP_DLTI_CTRL1_VADDR                        	(0xb8019e34)
#define  VDPQ_POSTP_DLTI_CTRL2_VADDR                        	(0xb8019e38)
#define  VDPQ_POSTP_DLTI_CTRL3_VADDR                        	(0xb8019e3c)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_VADDR             	(0xb8019e40)
#define  VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_VADDR             	(0xb8019e44)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_VADDR           	(0xb8019e48)
#define  VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_VADDR           	(0xb8019e4c)
#define  VDPQ_POSTP_DLTI_PK_SELECT_VADDR                    	(0xb8019e50)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_VADDR            	(0xb8019e54)
#define  VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_VADDR            	(0xb8019e58)
#define  VDPQ_POSTP_NTSC443_LPF_VADDR                       	(0xb8019e60)
#define  VDPQ_SPNR_DEBUGMODE_VADDR                          	(0xb8019e64)
#define  VDPQ_SPNR_CP_CTRL_VADDR                            	(0xb8019e68)
#define  VDPQ_SPNR_SPATIAL_TH_VADDR                         	(0xb8019e6c)
#define  VDPQ_SPNR_SPATIAL_WEIGHT_VADDR                     	(0xb8019e70)
#define  VDPQ_DUMMY_STATUS_VADDR                            	(0xb8019e74)
#define  VDPQ_SPNR_LOCAL_VAR2_VADDR                         	(0xb8019e78)
#define  VDPQ_NOTCH_CTRL_1_VADDR                            	(0xb8019e7c)
#define  VDPQ_NOTCH_CTRL_2_VADDR                            	(0xb8019e80)
#define  VDPQ_NOTCH_CTRL_3_VADDR                            	(0xb8019e84)
#define  VDPQ_NOTCH_CTRL_4_VADDR                            	(0xb8019e88)
#define  VDPQ_DE_XC_CTRL_VADDR                              	(0xb8019f00)
#define  VDPQ_CNR_CTRL_VADDR                                	(0xb8019f04)
#define  VDPQ_CADAP_ENABLE_CTRL_VADDR                       	(0xb8019f0c)
#define  VDPQ_CADAP_ENABLE_CTRL2_VADDR                      	(0xb8019f10)
#define  VDPQ_CADAP_GAIN_CTRL_VADDR                         	(0xb8019f14)
#define  VDPQ_CADAP_ZC_TH_VADDR                             	(0xb8019f18)
#define  VDPQ_CADAP_ZC_TH2_VADDR                            	(0xb8019f1c)
#define  VDPQ_CADAP_VER_UNIFORMITY_TH_VADDR                 	(0xb8019f20)
#define  VDPQ_CADAP_SYNC_UNIFORMITY_TH_VADDR                	(0xb8019f24)
#define  VDPQ_CADAP_LUT_LEVEL_TH_VADDR                      	(0xb8019f28)
#define  VDPQ_CADAP_LUT_GAIN_TH_VADDR                       	(0xb8019f2c)
#define  VDPQ_DCTI_FILTER_COEF_B1_VADDR                     	(0xb8019f30)
#define  VDPQ_DCTI_FILTER_COEF_B2_VADDR                     	(0xb8019f34)
#define  VDPQ_DCTI_FILTER_COEF_B3_VADDR                     	(0xb8019f38)
#define  VDPQ_DCTI_FILTER_COEF_A2_VADDR                     	(0xb8019f3c)
#define  VDPQ_DCTI_FILTER_COEF_A3_VADDR                     	(0xb8019f40)
#define  VDPQ_DCTI_FILTER_EN_VADDR                          	(0xb8019f44)
#define  VDPQ_YC_3D_F4_SMD_EN_VADDR                         	(0xb8019f48)
#define  VDPQ_YC_3D_F4_SMD_TH1_VADDR                        	(0xb8019f4c)
#define  VDPQ_YC_3D_F4_SMD_TH2_VADDR                        	(0xb8019f50)
#define  VDPQ_YC_3D_F4_PAIR_SMD_TH1_VADDR                   	(0xb8019f54)
#define  VDPQ_YC_3D_F4_PAIR_SMD_TH2_VADDR                   	(0xb8019f58)
#define  VDPQ_NS_R1_VADDR                                   	(0xb8019f5c)
#define  VDPQ_NS_R2_VADDR                                   	(0xb8019f60)
#define  VDPQ_NS_R3_VADDR                                   	(0xb8019f64)
#define  VDPQ_NS_RW1_VADDR                                  	(0xb8019f68)
#define  VDPQ_NS_RW2_VADDR                                  	(0xb8019f6c)
#define  VDPQ_POSTP_SECAM_FIX_CTRL_VADDR                    	(0xb8019f70)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT0_VADDR               	(0xb8019f74)
#define  VDPQ_POSTP_SECAM_FIX_Y_DETECT1_VADDR               	(0xb8019f78)
#define  VDPQ_DUMMY_5_VADDR                                 	(0xb8019ff0)
#define  VDPQ_DUMMY_6_VADDR                                 	(0xb8019ff4)
#define  VDPQ_DUMMY_7_VADDR                                 	(0xb8019ff8)
#define  VDPQ_DUMMY_8_VADDR                                 	(0xb8019ffc)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======VDPQ register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  f_num_chk_3d_sel:2;
        RBus_UInt32  f_hennum_range:6;
    };
}vdpq_frame_buf_chk3d_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  f_num_chk_3d_en:1;
        RBus_UInt32  f_num_3d_fail_det:1;
        RBus_UInt32  f_cennum_range:6;
    };
}vdpq_frame_buf_chk3d_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  f_num_open3d_cnt:4;
        RBus_UInt32  f_num_close3d_cnt:4;
    };
}vdpq_frame_buf_chk3d_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  f_cennum_valid_en:1;
        RBus_UInt32  f_cennum_valid1_en:1;
        RBus_UInt32  f_cennum_valid2_en:1;
    };
}vdpq_frame_buf_chk3d_cen_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  f_cennum_valid1_num:20;
    };
}vdpq_frame_buf_chk3d_cen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  f_cennum_valid2_num:20;
    };
}vdpq_frame_buf_chk3d_cen_num2_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  f_hennum_valid_en:1;
        RBus_UInt32  f_hennum_valid1_en:1;
    };
}vdpq_frame_buf_chk3d_hen_num1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  f_hennum_valid1_num:20;
    };
}vdpq_frame_buf_chk3d_hen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_st1:10;
    };
}vdpq_dma_vactive_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end1:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_end1:10;
    };
}vdpq_dma_vactive_end1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_st2:10;
    };
}vdpq_dma_vactive_st2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end2:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  vactive_end2:10;
    };
}vdpq_dma_vactive_end2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dma_ctrl_ififo_thr:6;
    };
}vdpq_dma_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dma_ctrl_ofifo_thr:6;
    };
}vdpq_dma_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dma_ctrl_ceiladr:6;
    };
}vdpq_dma_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_3d_on_off:1;
        RBus_UInt32  ntsc443_tune:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_vcnt_diff:10;
        RBus_UInt32  dma_vcnt_sft_chk_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dma_vcnt_sft_thr:5;
        RBus_UInt32  dma_3d_on_vcnt:5;
        RBus_UInt32  dma_ctrl_bstlen:3;
    };
}vdpq_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ofifo_err_flag:1;
        RBus_UInt32  ififo_err_flag_1:1;
        RBus_UInt32  ififo_err_flag_2:1;
        RBus_UInt32  ififo_err_flag_3:1;
        RBus_UInt32  ififo_err_flag_4:1;
        RBus_UInt32  mem_off:1;
        RBus_UInt32  mem_test_mode:1;
        RBus_UInt32  mem_test_mode_ok:1;
    };
}vdpq_dma_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  dma_field_inv:1;
        RBus_UInt32  dma_adc_in_en:1;
        RBus_UInt32  dma_adc_in_sel:1;
    };
}vdpq_dma_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dma_debugif_stline_en:1;
        RBus_UInt32  dma_debugif_stline:10;
    };
}vdpq_debug_dma_if_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  vlpf_sram_bypass:1;
        RBus_UInt32  vd_sram_on_off:1;
    };
}vdpq_vd_sram_on_off_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr0:29;
    };
}vdpq_mem0_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr1:29;
    };
}vdpq_mem1_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr2:29;
    };
}vdpq_mem2_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr3:29;
    };
}vdpq_mem3_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr0_end:29;
    };
}vdpq_mem0_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr1_end:29;
    };
}vdpq_mem1_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr2_end:29;
    };
}vdpq_mem2_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  frame_addr3_end:29;
    };
}vdpq_mem3_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_debug_adr:29;
    };
}vdpq_dma_debug_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dma_debug_vbiend_adr:29;
    };
}vdpq_dma_debug_vbi_end_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dma_debug_vd_sel:4;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  dma_debugmode_sel:2;
        RBus_UInt32  dma_debugmode_en:1;
    };
}vdpq_video_dma_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dma_debug_one_rw_rlt:1;
        RBus_UInt32  dma_debug_rw_en:2;
        RBus_UInt32  res2:4;
    };
}vdpq_vbidma_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  calib_delay_hsync_en:1;
        RBus_UInt32  chase_line_pos_en:2;
        RBus_UInt32  calib_delay_frame_sel:1;
        RBus_UInt32  calib_delay_sel:1;
        RBus_UInt32  calib_delay_en:1;
        RBus_UInt32  dma_pix_sht_fix_en:1;
        RBus_UInt32  chase_per_frame_en:1;
        RBus_UInt32  chase_pix_num:4;
        RBus_UInt32  pix_sht_st_th:20;
    };
}vdpq_dma_cnt_calibration1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fscnum_dif_abs_sel:2;
        RBus_UInt32  pix_sht_limit_en:1;
        RBus_UInt32  pix_sht_limit_th:8;
        RBus_UInt32  pix_sht_end_th:20;
    };
}vdpq_dma_cnt_calibration2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fscdif_num_abs:6;
        RBus_UInt32  res2:4;
        RBus_UInt32  fscdif_sum_abs:20;
    };
}vdpq_dma_cnt_calibration3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  f1_cennum:16;
    };
}vdpq_frame_buffer_f1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  f2_cennum:16;
    };
}vdpq_frame_buffer_f2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:32;
    };
}vdpq_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:32;
    };
}vdpq_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yc3d_tb_en:1;
        RBus_UInt32  res1:22;
        RBus_UInt32  ycsep_rdsel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  yc_linebf_sel:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  adaptive_mode:3;
    };
}vdpq_yc_sep_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  wide_bpf_sel_y:4;
        RBus_UInt32  mid_bpf_sel_y:4;
        RBus_UInt32  narrow_bpf_sel_y:4;
    };
}vdpq_bpf_bw_sel_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  wide_bpf_sel_c:4;
        RBus_UInt32  mid_bpf_sel_c:4;
        RBus_UInt32  narrow_bpf_sel_c:4;
    };
}vdpq_bpf_bw_sel_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_lk_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  v2v_lk_y_en:1;
        RBus_UInt32  v2v_lk_c_en:1;
        RBus_UInt32  h2v_mid_sel_y:1;
        RBus_UInt32  h2v_mid_sel_c:1;
        RBus_UInt32  h2v_near_sel_y:1;
        RBus_UInt32  h2v_near_sel_c:1;
    };
}vdpq_adap_bpf_c_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_vflag_remag_thr:4;
        RBus_UInt32  h2v_vflag_mag_thr:4;
    };
}vdpq_adap_bpf_c_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  pal_perr:1;
        RBus_UInt32  pal_perr_auto_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  palsw_level:2;
    };
}vdpq_comb_filter_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  noise_ntsc_c:8;
    };
}vdpq_comb_filter_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  malpha_c_divider2_sel:1;
        RBus_UInt32  malpha_y_divider2_sel:1;
        RBus_UInt32  malpha_y_en:1;
        RBus_UInt32  malpha_y:1;
        RBus_UInt32  malpha_c_en:1;
        RBus_UInt32  malpha_c:1;
        RBus_UInt32  yalpha_en:1;
        RBus_UInt32  yalpha:1;
    };
}vdpq_adap_bpf_y_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  chroma_vlpf_round_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  pal_demod_sel:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  chroma_vlpf_en:1;
        RBus_UInt32  chroma_bw_lo:3;
    };
}vdpq_yc_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  debug_mode_2d_en:1;
        RBus_UInt32  debug_mode_2d:4;
    };
}vdpq_debug_2d_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bw_gain_sel:2;
        RBus_UInt32  bw_detect_thr:6;
    };
}vdpq_bw_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  bw_edge_thr:8;
    };
}vdpq_bw_edge_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  same_phase_diff_1d_gauge_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  blend_1d_thr:5;
        RBus_UInt32  bpf_1d_sel_y:2;
    };
}vdpq_blend_1d_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  narrow_1d_bpf_sel_c:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  wide_1d_bpf_sel_c:3;
    };
}vdpq_blend_1d_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_halpha_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  halpha:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  lut_large_th:5;
        RBus_UInt32  lut_fuzzy_th:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  lut_sel_y:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  lut_sel_c:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  h2v_coring_thr:3;
    };
}vdpq_alpha_2d_mod_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  h2v_lut_hprefer_ratio:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  h2v_lut_hv_large_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  h2v_cvbs_coring_thr:3;
        RBus_UInt32  h2v_bw_color_gain:4;
    };
}vdpq_h2v_coring_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_y_noise_thr:8;
    };
}vdpq_h2v_y_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_cvbs_noise_thr:8;
    };
}vdpq_h2v_cvbs_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  h2v_noise_max_hdy:8;
    };
}vdpq_h2v_noise_max_hdy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  v2v_lut_sel_y:1;
        RBus_UInt32  v2v_noise_y_add_dc:8;
    };
}vdpq_h2v_noise_y_add_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  h2v_blendratio:3;
    };
}vdpq_h2v_blend_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xc_sel_gain:2;
        RBus_UInt32  res2:6;
    };
}vdpq_adap_bpf_y_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cdiff_bpf_mm_small_th:6;
        RBus_UInt32  cdiff_bpf_mm_diff_th:8;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_bpf_hor_range:1;
        RBus_UInt32  cdiff_bpf_ver_range:1;
        RBus_UInt32  res3:4;
    };
}vdpq_cdiff_adap_bpf_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  cdiff_bpf_vspd_small_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_bpf_low_sat_th:6;
        RBus_UInt32  cdiff_bpf_large_offset:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  cdiff_bpf_large_amp_wei:3;
        RBus_UInt32  cdiff_bpf_small_offset:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  cdiff_bpf_small_amp_wei:3;
    };
}vdpq_cdiff_adap_bpf_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hvdiff_comp_offset:8;
        RBus_UInt32  hvdiff_comp_multiple:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_tolerance:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vedge_en:1;
    };
}vdpq_bpf_vedge_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  c_follow_y_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hdiff_lowbound:7;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_upbound:5;
    };
}vdpq_bpf_vedge_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_diff_ratio:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  lr_diff_lower_th:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  lr_diff_th:7;
        RBus_UInt32  complex_level_th:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  complex_level_mode_sel:1;
        RBus_UInt32  bypassbpf_adap_en:1;
    };
}vdpq_bypass_bpf_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  newvedge_lr_diff_th:7;
        RBus_UInt32  newvedge_vdiff_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  newvedge_vdiff_th:7;
        RBus_UInt32  lr_ratio_th:4;
    };
}vdpq_bypass_bpf_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode_gridgirl:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  grid_cvbs_diff_th:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  gridgirl_corr_en:1;
        RBus_UInt32  grid_reset_sel:1;
        RBus_UInt32  grid_use_preflag_en:1;
        RBus_UInt32  gridgirl_en:1;
    };
}vdpq_gridgirl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_chroma_th2:8;
        RBus_UInt32  grid_chroma_th1:8;
        RBus_UInt32  grid_hordiff_th2:8;
        RBus_UInt32  grid_hordiff_th1:8;
    };
}vdpq_gridgirl_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_linecnt_th2:8;
        RBus_UInt32  grid_linecnt_th1:8;
        RBus_UInt32  grid_linesum_th2:8;
        RBus_UInt32  grid_linesum_th1:8;
    };
}vdpq_gridgirl_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_sum_right_bound:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  grid_sum_left_bound:11;
    };
}vdpq_gridgirl_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_right_bound:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  grid_left_bound:11;
    };
}vdpq_gridgirl_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  vmc_widehspd_small_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diamc_cvbsamp_still_th:6;
    };
}vdpq_diamc_cvbs_amp_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diamc_dc_still_th_offset:6;
        RBus_UInt32  diamc_dc_still_th_weight:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  diamc_y_v_line_id_cnt_th:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  diamc_fid_th_weight:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  diamc_amp_low_bnd:7;
        RBus_UInt32  res5:1;
        RBus_UInt32  diamc_all_line_match_en:1;
        RBus_UInt32  diamc_perfect_fid_en:1;
        RBus_UInt32  diamc_en:1;
    };
}vdpq_diamc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  ver_cvbsamp_still_th:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  vmc_cfollowy_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_dc_still_th:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  amp_low_bnd:6;
        RBus_UInt32  res5:1;
        RBus_UInt32  slant_det_en:1;
        RBus_UInt32  perfect_fid_en:1;
        RBus_UInt32  vmc_en:1;
    };
}vdpq_vmc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  offset_2:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  offset_1:2;
        RBus_UInt32  cnt_th_2:4;
        RBus_UInt32  cnt_th_1:4;
    };
}vdpq_vmc_spatial_corr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  postlpf_dia_en:1;
        RBus_UInt32  postlpf_grad_en:1;
        RBus_UInt32  postlpf_force_en:1;
        RBus_UInt32  postlpf_en:1;
    };
}vdpq_yc2d_postlp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  low_amp_th_3:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  low_amp_th_2:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  low_amp_th_1:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  low_amp_th_0:5;
    };
}vdpq_yc2d_postlp_flat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_th_2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hdiff_th_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hdiff_th_0:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  low_amp_th_4:5;
    };
}vdpq_yc2d_postlp_flat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hdiff_th_4:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdiff_th_3:5;
    };
}vdpq_yc2d_postlp_flat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  vdiff_th_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_3:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_2:5;
    };
}vdpq_yc2d_postlp_flat_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  larger_cnt_th_1:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  smaller_cnt_th_0:2;
        RBus_UInt32  larger_cnt_th_0:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  grad_flat_th_ratio:5;
        RBus_UInt32  grad_flat_th_offset:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  grad_flat_th_upbnd:5;
    };
}vdpq_yc2d_postlp_grad_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  vdiff_th_1_grad:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0_grad:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  low_amp_th_grad_offset:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  smaller_cnt_th_1:2;
    };
}vdpq_yc2d_postlp_grad_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  vdiff_th_3_grad:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_2_grad:5;
    };
}vdpq_yc2d_postlp_grad_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  spd_large_ratio:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  spd_large_th:6;
        RBus_UInt32  low_amp_th_dia_offset:8;
        RBus_UInt32  res3:2;
        RBus_UInt32  smaller_cnt_th_dia:2;
        RBus_UInt32  larger_cnt_th_dia:4;
    };
}vdpq_yc2d_postlp_dia_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  dia_grad_flat_th_ratio:5;
        RBus_UInt32  dia_grad_flat_th_offset:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dia_grad_flat_th_upbnd:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  spd_diff_th:7;
    };
}vdpq_yc2d_postlp_dia_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_3_dia:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_2_dia:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_1_dia:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  vdiff_th_0_dia:5;
    };
}vdpq_yc2d_postlp_dia_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  dia_cedge_th:6;
    };
}vdpq_yc2d_postlp_dia_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  demodphase_fix_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  demodphase_fix:2;
        RBus_UInt32  res2:19;
        RBus_UInt32  pal_mod_inv:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  yc_sep_mode:2;
    };
}vdpq_yc_sep_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:32;
    };
}vdpq_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  yc3d_cchroma_bpf_sel:1;
        RBus_UInt32  yc3d_ychroma_bpf_sel:1;
        RBus_UInt32  res2:6;
    };
}vdpq_yc_3dsep_chroma_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  monotone_flat_cnt_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  monotone_flat_th:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  monotone_edge_th:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  slp_monotone_en:1;
    };
}vdpq_yc_3d_f4_slp_mono_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slp_cnt:16;
        RBus_UInt32  hor_c_change_cnt:16;
    };
}vdpq_yc_3d_f4_stat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  stat_tempspd_small_th:7;
        RBus_UInt32  tempspd_small_cnt:16;
    };
}vdpq_yc_3d_f4_stat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  stat_hifreqdiff_not_small_th:8;
        RBus_UInt32  hifreqdiff_not_small_cnt:16;
    };
}vdpq_yc_3d_f4_stat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sc_hfd_diff_large_ratio:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  sc_hfd_diff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  sc_hfd_diff_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  slp_offset:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  slp_en:1;
    };
}vdpq_yc_3d_f4_slp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cvbs_match_cnt_th_hvspd:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  large_hvspd_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  dc_still_th:7;
        RBus_UInt32  match_cnt_th:4;
    };
}vdpq_yc_3d_f4_slp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  cvbsamp_ratio:3;
        RBus_UInt32  cvbsamp_th:4;
        RBus_UInt32  cvbsamp_diff_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  cvbsamp_diff_th:7;
        RBus_UInt32  cvbs_match_cnt_th:4;
    };
}vdpq_yc_3d_f4_slp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  aba_dc_change_th:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  aba_aa_diff_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  aba_hifreqdiff_th:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  ntsc_aba_en:1;
    };
}vdpq_yc_3d_f4_ntsc_aba_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  aba_cvbsamp_multiple:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  aba_cvbsamp_aa_th:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  aba_cvbsamp_ab_th:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  aba_dc_multiple:5;
    };
}vdpq_yc_3d_f4_ntsc_aba_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:32;
    };
}vdpq_dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  f4_global_diff_dbg_sftbit:2;
        RBus_UInt32  f4_dbg_highfreq_diff_th:8;
        RBus_UInt32  f4_dbg_cvbs_amp_th:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  f4_debug_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  f4_debug_mode_sel:5;
    };
}vdpq_yc_3d_f4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cvbs_amp_change_th:7;
        RBus_UInt32  res2:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_5:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_4:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_3:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_2:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_1:4;
    };
}vdpq_yc_3d_f4_spa_cnt_cvbs_amp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  hv_cvbs_diff_large_multiple_th:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hv_diff_large_multiple_th:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  hv_diff_large_offset_th:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  hv_local_diff_comp_ratio:3;
        RBus_UInt32  hv_diff_tolerance:4;
    };
}vdpq_yc_3d_f4_hv_edge_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  h_diff_normalize_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  hv_edge_c_diff_small_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hv_edge_c_diff_small_en:1;
    };
}vdpq_yc_3d_f4_hv_edge_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  hifreq_postp_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  f4_fill_hole_neightbor_diff_th:6;
        RBus_UInt32  f4_hor_chifreq_range:1;
        RBus_UInt32  f4_ver_chifreq_range:1;
        RBus_UInt32  f4_hor_hifreq_range:1;
        RBus_UInt32  f4_ver_hifreq_usepalmode:1;
    };
}vdpq_yc_3d_f4_hifreq_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  dc_level_change_th_multiple:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  dc_level_change_th_base:6;
    };
}vdpq_yc_3d_f4_dc_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  similary_th_base:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  similary_th_multiple:5;
        RBus_UInt32  palerr_accu_tolerance:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  palerr_hifreq_diff_large_th:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  pal_error_detect_en:1;
    };
}vdpq_yc_3d_f4_pal_err_com_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_of_spd_small_th_base:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_of_spd_small_th_multiple:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  massive_palmode_error_multiple_th:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  massive_palmode_error_large_th:7;
    };
}vdpq_yc_3d_f4_pal_err_com_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4f0_still_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  palerr_massive_tolerance:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  f4f0_still_th_weight:6;
        RBus_UInt32  f4f0_still_th_offset:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  f4f0_still_th_upbnd:5;
    };
}vdpq_yc_3d_f4_pal_err_com_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_avg_dynamic_en:1;
        RBus_UInt32  sv_longtime_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  sv_vector_fid_match_cnt_th:5;
        RBus_UInt32  sv_vector_fid_offset:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_vector_large_cnt_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  sv_vector_large_th:5;
    };
}vdpq_yc_3d_f4_still_vector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  sv_self_diff_small_th:7;
    };
}vdpq_yc_3d_f4_still_vector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  sghf_inter_diff_th:7;
        RBus_UInt32  sghf_global_diff_small_th:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  sghf_longtime_en:1;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sghf_avg_dynamic_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  sghf_vector_fid_match_cnt_th:5;
        RBus_UInt32  sghf_vector_fid_offset:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  sghf_vector_large_cnt_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  sghf_vector_large_th:5;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_140:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_160:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_180:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  diff_th_multiple_200:5;
    };
}vdpq_yc_3d_f4_pair_th_multiple_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_60:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_80:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_100:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  diff_th_multiple_120:5;
    };
}vdpq_yc_3d_f4_pair_th_multiple_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_10:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_20:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  diff_th_multiple_40:5;
    };
}vdpq_yc_3d_f4_pair_th_multiple_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_140:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_160:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_180:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  diff_th_base_200:6;
    };
}vdpq_yc_3d_f4_pair_th_base_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_60:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_80:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_100:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  diff_th_base_120:6;
    };
}vdpq_yc_3d_f4_pair_th_base_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_20:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  diff_th_base_40:6;
    };
}vdpq_yc_3d_f4_pair_th_base_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hv_offset:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  still_vector_offset_multiple:3;
        RBus_UInt32  res3:2;
        RBus_UInt32  still_vector_offset_base:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  pal_error_offset:6;
        RBus_UInt32  res5:1;
        RBus_UInt32  hor_c_diff_dpo_hedge_rshift_bit:3;
    };
}vdpq_yc_3d_f4_pair_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  still_vector_cvbs_amp_change_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_vector_hifreq_diff_th:6;
    };
}vdpq_yc_3d_f4_pair_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  later_diff_upper_bound:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pair_diff_sel_th:7;
        RBus_UInt32  res3:3;
        RBus_UInt32  highfreq_diff_low_border:5;
        RBus_UInt32  flat_offset:4;
    };
}vdpq_yc_3d_f4_pair_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  diff_th_upper_bound:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_lower_bound:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_2d_comp_3d_offset:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  hvdiff_border:6;
    };
}vdpq_yc_3d_f4_pair_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  still_gray_hifreq_th:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_gray_hifreq_low_border:6;
        RBus_UInt32  res3:3;
        RBus_UInt32  still_gray_hifreq_enable:1;
    };
}vdpq_yc_3d_f4_pair_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  global_diff_tolerance:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  global_diff_offset_dc_fierce_change:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  dc_level_fierce_change_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  hdy_small_th:6;
    };
}vdpq_yc_3d_f4_pair_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_120:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_140:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_160:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  global_diff_th_hifreq_offset_180:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_60:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_70:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_80:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  global_diff_th_hifreq_offset_100:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_40:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  global_diff_th_hifreq_offset_50:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  global_diff_th_hifreq_offset_5:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_0:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_10:6;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  moving_vline_ver_dc_level_fierce_change_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  moving_vline_flat_ver_cvbs_th:5;
        RBus_UInt32  mghf_flag:1;
        RBus_UInt32  mghf_enable:1;
        RBus_UInt32  moving_vline_en:1;
        RBus_UInt32  dc_level_hor_dc_check_en:1;
    };
}vdpq_yc_3d_f4_mghf_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  large_hifreq_diff_ratio:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  hor_c_change_ratio:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  hifreq_diff_large_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  cvbs_still_th:5;
        RBus_UInt32  res5:3;
        RBus_UInt32  hor_c_change_th:5;
    };
}vdpq_yc_3d_f4_mghf_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  diff_th_multiple_5:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_5:6;
    };
}vdpq_yc_3d_f4_global_diff_th_com_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  diadiff_vspd_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diadiff_small_upbnd:6;
        RBus_UInt32  diadiff_small_weight:4;
        RBus_UInt32  res3:2;
        RBus_UInt32  diadiff_small_base:6;
        RBus_UInt32  res4:3;
        RBus_UInt32  dbwline_en:1;
    };
}vdpq_yc_post2dbpf_dbwline_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dbwline_d45_hspd_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  dbwline_hspd_small_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  dbwline_hor_cdiff_th:7;
        RBus_UInt32  res4:2;
        RBus_UInt32  low_sat_th:6;
    };
}vdpq_yc_post2dbpf_dbwline_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  dbwline_d45_diadiff_small_th:7;
    };
}vdpq_yc_post2dbpf_dbwline_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  gremove_c_small_th:5;
        RBus_UInt32  gremove_bpfedc_small_th:4;
        RBus_UInt32  weight_2d_c:2;
        RBus_UInt32  weight_bld_c:2;
        RBus_UInt32  weight_3d_c:2;
        RBus_UInt32  weight_2d_y:2;
        RBus_UInt32  weight_bld_y:2;
        RBus_UInt32  weight_3d_y:2;
        RBus_UInt32  mghf_narrowbpf_en:1;
        RBus_UInt32  greenish_detected_en:1;
        RBus_UInt32  post2dbpf_c_en:1;
        RBus_UInt32  post2dbpf_y_en:1;
    };
}vdpq_yc_post2dbpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  hor_cdiff_th_base:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ver_cdiff_th_base:7;
    };
}vdpq_yc_post2dbpf_thbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  bpfed_c_diff_small_th:7;
        RBus_UInt32  res2:3;
        RBus_UInt32  dual_ch_bpfedc_small_th:5;
        RBus_UInt32  dual_ch_bpfedcdiff_large_ratio:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  dual_ch_bpfedcdiff_large_th:5;
    };
}vdpq_yc_post2dbpf_adapth_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  bpfed_c_diff_large_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  bpfed_c_diff_large_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bpfed_c_diff_small_hor_offset:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  bpfed_c_diff_small_ver_offset:7;
    };
}vdpq_yc_post2dbpf_adapth_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  neighbor_vdiff_small_hor_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  neighbor_hdiff_small_ver_offset:6;
        RBus_UInt32  res3:3;
        RBus_UInt32  vspd_small_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdy_spd_small_th:5;
    };
}vdpq_yc_post2dbpf_adapth_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hvedge_diff_large_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  vspd_large_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  hdy_spd_large_th:7;
        RBus_UInt32  res4:3;
        RBus_UInt32  hdiff_tolerance:5;
    };
}vdpq_yc_post2dbpf_adapth_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  vedge_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  hedge_ver_offset:7;
    };
}vdpq_yc_post2dbpf_adapth_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  dia_spd_large_ver_offset:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  dia_spd_large_th_small_hordiff_th:6;
        RBus_UInt32  dia_spd_large_th_small_hordiff_offset:8;
        RBus_UInt32  dia_spd_large_th_base:8;
    };
}vdpq_yc_post2dbpf_adapth_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  dual_ch_c_small_th:5;
        RBus_UInt32  dual_ch_cdiff_large_ratio:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dual_ch_cdiff_large_th:5;
    };
}vdpq_yc_post2dbpf_adapth_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hdiff_much_larger_ratio:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  hdiff_much_larger_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hdiff_vdiff_diff_larger_th:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  hdiff_large_th:7;
    };
}vdpq_yc_post2dbpf_adapth_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_color_tran_ver_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ver_color_tran_ver_cdiff_small_th:7;
        RBus_UInt32  res3:2;
        RBus_UInt32  ver_color_tran_hdiff_large_th:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  hdiff_much_larger_hor_offset:7;
    };
}vdpq_yc_post2dbpf_adapth_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  colorbar_detect_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  colorbar_detect_ver_offset:7;
        RBus_UInt32  res3:2;
        RBus_UInt32  colorbar_hdiff_large_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  colorbar_vdiff_small_th:6;
    };
}vdpq_yc_post2dbpf_adapth_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_avoid_th_c:4;
        RBus_UInt32  ver_avoid_th_y:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  smooth_detect_ver_offset:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  smooth_hdiff_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  smooth_vdiff_small_th:6;
    };
}vdpq_yc_post2dbpf_adapth_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vedge_avoid_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vcdiff_large_diff_th:6;
        RBus_UInt32  vcdiff_large_ratio:4;
        RBus_UInt32  v2sides_diff_large_ratio:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  v2sides_diff_large_th:7;
        RBus_UInt32  res3:3;
        RBus_UInt32  v2sides_gray_diff_small_th:5;
    };
}vdpq_yc_post2dbpf_adapth_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  upbnd:8;
        RBus_UInt32  hedge_ratio_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  hedge_bypass_en:1;
        RBus_UInt32  ignore_th_c:4;
        RBus_UInt32  ignore_th_y:4;
    };
}vdpq_yc_post2dbpf_adapth_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xc_hvedge_avoid_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  xc_cdiff_upbnd:6;
        RBus_UInt32  xc_hvedge_ratio_th_2:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  xc_hvedge_th_2:5;
        RBus_UInt32  xc_hvedge_ratio_th_1:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  xc_hvedge_th_1:5;
    };
}vdpq_yc_post2dbpf_xc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  yadap_hpf_sel:2;
        RBus_UInt32  yadap_peak_mode:2;
    };
}vdpq_secam_yadap_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  yadap_peak_gain:4;
        RBus_UInt32  yadap_peak_th:4;
    };
}vdpq_secam_yadap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  yadap_peak_gain_2d:4;
        RBus_UInt32  yadap_uniform_gain:4;
    };
}vdpq_secam_yadap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpq_alphadelay_indep_en:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  postpq_alphadelay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  postpq_malphadelay:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  xnr_lpf_sel:2;
        RBus_UInt32  xnr_vlpf_sel:2;
        RBus_UInt32  xnr_blend_dbm:1;
        RBus_UInt32  xnr_blend_en:1;
        RBus_UInt32  xnr_det_bypass_en:1;
        RBus_UInt32  xnr_en:1;
    };
}vdpq_xnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xnr_cdiff_thr:4;
        RBus_UInt32  xnr_csum_thr:4;
    };
}vdpq_xnr_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xnr_idxgain:4;
        RBus_UInt32  xnr_ver_idxgain:4;
    };
}vdpq_xnr_idx_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  xnr_ver_ratio:4;
        RBus_UInt32  xnr_ver_ratio_w:4;
    };
}vdpq_xnr_ratio_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_cedge_sum_th:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_cedge_single_th:6;
        RBus_UInt32  ver_cedge_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  mf_en:1;
        RBus_UInt32  ma0_cnt_th:5;
        RBus_UInt32  point_type_coring_lv:4;
        RBus_UInt32  vline_len_3_sel:1;
        RBus_UInt32  vline_con_en:1;
        RBus_UInt32  cdiff_small_con_en:1;
        RBus_UInt32  ma0_con_en:1;
    };
}vdpq_postp_mf_compensation_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  cdiff_small_sum_th:7;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_small_single_th:6;
        RBus_UInt32  cdiff_small_len:4;
    };
}vdpq_postp_mf_compensation_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  postpk_prelpf_mode:1;
        RBus_UInt32  postpk_prelpf_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  postpk_alphablend_en:1;
        RBus_UInt32  postpk_dnoise_en:1;
        RBus_UInt32  postpk_adap_mode:2;
        RBus_UInt32  postpk_adappk_en:1;
        RBus_UInt32  postpk_en:1;
    };
}vdpq_yc2d_postpk2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  postpk_c_stepbit:3;
        RBus_UInt32  postpk_c_lwbnd:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  postpk_y_stepbit:3;
        RBus_UInt32  postpk_y_lwbnd:8;
    };
}vdpq_yc2d_postpk2_adap1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  postpk_lv_upbnd:8;
        RBus_UInt32  res2:5;
        RBus_UInt32  postpk_lv_sft:3;
        RBus_UInt32  postpk_lv_th:8;
    };
}vdpq_yc2d_postpk2_dnoise1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  postpk_c0:9;
        RBus_UInt32  res2:3;
        RBus_UInt32  postpk_c1:9;
        RBus_UInt32  postpk_c2:8;
    };
}vdpq_yc2d_postpk2_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  postpk_gain_pos:8;
        RBus_UInt32  postpk_gain_neg:8;
    };
}vdpq_yc2d_postpk2_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  postpk_hv_pos:10;
        RBus_UInt32  postpk_hv_neg:10;
        RBus_UInt32  postpk_lv:8;
    };
}vdpq_yc2d_postpk2_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_ffd2_ratio:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlti_ffd2_en:1;
        RBus_UInt32  dlti_ffd1_ratio:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti_ffd1_th:5;
        RBus_UInt32  res3:1;
        RBus_UInt32  dlti_maxlen:3;
        RBus_UInt32  dlti_pnth:7;
        RBus_UInt32  dlti_en:1;
    };
}vdpq_postp_dlti_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_d1_cp_shift:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  dlti_dcp_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti_tn_blend_mode:1;
        RBus_UInt32  dlti_tn_blend_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dlti_ovc_en:1;
        RBus_UInt32  dlti_can_shift:4;
        RBus_UInt32  dlti_ffd2_range2l:4;
        RBus_UInt32  dlti_ffd2_range2r:4;
    };
}vdpq_postp_dlti_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_cchange_srcwei_offset_2:4;
        RBus_UInt32  dlti_cchange_srcwei_offset_1:4;
        RBus_UInt32  dlti_uv_diff_th_2:8;
        RBus_UInt32  dlti_uv_diff_th_1:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  dlti_cchange_len:3;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti_cchange_corr_en:1;
    };
}vdpq_postp_dlti_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tngain7:4;
        RBus_UInt32  dlti_tngain6:4;
        RBus_UInt32  dlti_tngain5:4;
        RBus_UInt32  dlti_tngain4:4;
        RBus_UInt32  dlti_tngain3:4;
        RBus_UInt32  dlti_tngain2:4;
        RBus_UInt32  dlti_tngain1:4;
        RBus_UInt32  dlti_tngain0:4;
    };
}vdpq_postp_dlti_tngain_gain_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dlti_tngain14:4;
        RBus_UInt32  dlti_tngain13:4;
        RBus_UInt32  dlti_tngain12:4;
        RBus_UInt32  dlti_tngain11:4;
        RBus_UInt32  dlti_tngain10:4;
        RBus_UInt32  dlti_tngain9:4;
        RBus_UInt32  dlti_tngain8:4;
    };
}vdpq_postp_dlti_tngain_gain_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tnoffset7:4;
        RBus_UInt32  dlti_tnoffset6:4;
        RBus_UInt32  dlti_tnoffset5:4;
        RBus_UInt32  dlti_tnoffset4:4;
        RBus_UInt32  dlti_tnoffset3:4;
        RBus_UInt32  dlti_tnoffset2:4;
        RBus_UInt32  dlti_tnoffset1:4;
        RBus_UInt32  dlti_tnoffset0:4;
    };
}vdpq_postp_dlti_tngain_offset_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dlti_tnoffset14:4;
        RBus_UInt32  dlti_tnoffset13:4;
        RBus_UInt32  dlti_tnoffset12:4;
        RBus_UInt32  dlti_tnoffset11:4;
        RBus_UInt32  dlti_tnoffset10:4;
        RBus_UInt32  dlti_tnoffset9:4;
        RBus_UInt32  dlti_tnoffset8:4;
    };
}vdpq_postp_dlti_tngain_offset_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pd_sel_dlti_cnt_th2:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pd_sel_dlti_cnt_th1:3;
        RBus_UInt32  pd_sel_dlti_diff_th:8;
        RBus_UInt32  res3:1;
        RBus_UInt32  pd_sel:3;
    };
}vdpq_postp_dlti_pk_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pk_alpha_2d_weight:2;
        RBus_UInt32  pk_alpha_bld_weight:2;
        RBus_UInt32  pk_alpha_3d_weight:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti_alpha_2d_weight:2;
        RBus_UInt32  dlti_alpha_bld_weight:2;
        RBus_UInt32  dlti_alpha_3d_weight:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  xnr_alpha_2d_weight:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  xnr_alpha_bld_weight:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  xnr_alpha_3d_weight:3;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  alphablend_round_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  snr_alpha_2d_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  snr_alpha_bld_weight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  snr_alpha_3d_weight:3;
        RBus_UInt32  notch_force_upbnd:8;
        RBus_UInt32  notch_force_3dweight:4;
        RBus_UInt32  res4:2;
        RBus_UInt32  mfnotch_alpha_2d_weight:2;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ntsc443_lpf:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  ntsc443_lpf_ext:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ntsc443_lpf_th_y:3;
    };
}vdpq_postp_ntsc443_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  cp_sweightydebug:2;
    };
}vdpq_spnr_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_sresultweight:3;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  res2:14;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  cp_spatialenabley:1;
    };
}vdpq_spnr_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  cp_spatialthlyx2:8;
        RBus_UInt32  cp_spatialthly:8;
    };
}vdpq_spnr_spatial_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  cp_weight1y:4;
        RBus_UInt32  cp_weight2y:4;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  res3:7;
    };
}vdpq_spnr_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_status:32;
    };
}vdpq_dummy_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_sw_edge_thl:16;
        RBus_UInt32  res1:14;
        RBus_UInt32  cp_edge_weight:2;
    };
}vdpq_spnr_local_var2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  notch_upbnd_offset:6;
        RBus_UInt32  res2:3;
        RBus_UInt32  notch_upbnd_weight:5;
        RBus_UInt32  notch_upbnd_upbnd:8;
        RBus_UInt32  res3:3;
        RBus_UInt32  notch_en:1;
    };
}vdpq_notch_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  large_notchy_amp_th:6;
        RBus_UInt32  high_sat_weight_undo:4;
        RBus_UInt32  high_sat_weight_do:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  high_sat_lowbnd:6;
        RBus_UInt32  res3:3;
        RBus_UInt32  notch_lowbnd:5;
    };
}vdpq_notch_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  very_nonmonotone_weight_undo:4;
        RBus_UInt32  very_nonmonotone_weight_do:4;
        RBus_UInt32  very_diff_large_weight_undo:4;
        RBus_UInt32  very_diff_large_weight_do:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  very_diff_large_th:6;
        RBus_UInt32  large_notchy_amp_weight_undo:4;
        RBus_UInt32  large_notchy_amp_weight_do:4;
    };
}vdpq_notch_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  force_notch_weight:4;
        RBus_UInt32  vline_weight_undo:4;
        RBus_UInt32  large_cdiff_weight_undo:4;
        RBus_UInt32  large_cdiff_weight_do:4;
        RBus_UInt32  large_cdiff_th:8;
    };
}vdpq_notch_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpq_alphablend_dbm:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  xc_blend_en:1;
        RBus_UInt32  de_xc_en:1;
        RBus_UInt32  de_xc_thr:4;
    };
}vdpq_de_xc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cnr_lpf_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cnr_en:1;
    };
}vdpq_cnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  cadap_spatial_lpf_out:1;
        RBus_UInt32  cadap_clpf_en:1;
        RBus_UInt32  cadap_ylpf_en:1;
        RBus_UInt32  cadap_uvsync_en:1;
        RBus_UInt32  cadap_yuvsync_en:1;
        RBus_UInt32  cadap_cti_en:1;
    };
}vdpq_cadap_enable_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  cadap_uni_gain_ctrl_en:1;
        RBus_UInt32  cadap_uv_sync_uni_en:1;
        RBus_UInt32  cadap_y_sync_uni_en:1;
    };
}vdpq_cadap_enable_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_gain:4;
        RBus_UInt32  cadap_level:4;
    };
}vdpq_cadap_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_zc_mag_th_y:4;
        RBus_UInt32  cadap_zc_mag_th_y_c:4;
    };
}vdpq_cadap_zc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_zc_mag_th_c:4;
        RBus_UInt32  cadap_dir_det_gain:4;
    };
}vdpq_cadap_zc_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_ver_uni_th:4;
        RBus_UInt32  cadap_dir_uni_th:4;
    };
}vdpq_cadap_ver_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_y_sync_uni_th:4;
        RBus_UInt32  cadap_uv_sync_uni_th:4;
    };
}vdpq_cadap_sync_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_lut_level_tha:4;
        RBus_UInt32  cadap_lut_level_thb:4;
    };
}vdpq_cadap_lut_level_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  cadap_lut_gain_tha:4;
        RBus_UInt32  cadap_lut_gain_thb:4;
    };
}vdpq_cadap_lut_gain_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_b1:11;
    };
}vdpq_dcti_filter_coef_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_b2:11;
    };
}vdpq_dcti_filter_coef_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_b3:11;
    };
}vdpq_dcti_filter_coef_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_a2:11;
    };
}vdpq_dcti_filter_coef_a2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  dcti_filter_coef_a3:11;
    };
}vdpq_dcti_filter_coef_a3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:31;
        RBus_UInt32  dcti_filter_en:1;
    };
}vdpq_dcti_filter_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  smd_10_move_enable:1;
        RBus_UInt32  smd_08_move_enable:1;
        RBus_UInt32  smd_06_move_enable:1;
        RBus_UInt32  smd_04_move_enable:1;
        RBus_UInt32  smd_02_move_enable:1;
        RBus_UInt32  smd_00_move_enable:1;
        RBus_UInt32  smd_en:1;
    };
}vdpq_yc_3d_f4_smd_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  smd_spatial_temporal_traily_diff:8;
        RBus_UInt32  smd_vertical_sad_tolerance:8;
        RBus_UInt32  smd_horizontal_sad_tolerance:8;
    };
}vdpq_yc_3d_f4_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_min_sad_vetical:8;
        RBus_UInt32  smd_min_sad_horizontal:8;
    };
}vdpq_yc_3d_f4_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_2d_small_global_diff_offset:16;
        RBus_UInt32  smd_highfreq_diff_2_th:8;
        RBus_UInt32  smd_highfreq_diff_th:8;
    };
}vdpq_yc_3d_f4_pair_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_2d_not_small_global_diff_offset:16;
    };
}vdpq_yc_3d_f4_pair_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_vm:32;
    };
}vdpq_ns_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  countv:16;
        RBus_UInt32  maxv:16;
    };
}vdpq_ns_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sumv:32;
    };
}vdpq_ns_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  nfactor:8;
        RBus_UInt32  vmm:16;
    };
}vdpq_ns_rw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  density:8;
        RBus_UInt32  meannxv:16;
    };
}vdpq_ns_rw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_uv_flag_en:1;
        RBus_UInt32  secam_fix_color_reduce_en:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  secam_fix_line_grey_ratio:4;
        RBus_UInt32  secam_fix_grey_thd:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  secam_fix_debug_mode:3;
        RBus_UInt32  secam_fix_post_cvlpf_en:1;
        RBus_UInt32  secam_fix_pre_yvlpf_en:1;
        RBus_UInt32  secam_fix_color_reduce_ctrl:2;
    };
}vdpq_postp_secam_fix_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_y_flag_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  secam_fix_y_diff_thd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_fix_y_action_continue_d_time:6;
        RBus_UInt32  secam_fix_y_flag_ext_l:8;
        RBus_UInt32  secam_fix_y_flag_ext_r:8;
    };
}vdpq_postp_secam_fix_y_detect0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_fix_y_target_d3:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_fix_y_target_d2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  secam_fix_y_target_d1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  secam_fix_y_target_d0:6;
    };
}vdpq_postp_secam_fix_y_detect1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:32;
    };
}vdpq_dummy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_6:32;
    };
}vdpq_dummy_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_7:32;
    };
}vdpq_dummy_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_8:32;
    };
}vdpq_dummy_8_RBUS;

#else //apply LITTLE_ENDIAN

//======VDPQ register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_hennum_range:6;
        RBus_UInt32  f_num_chk_3d_sel:2;
        RBus_UInt32  res1:24;
    };
}vdpq_frame_buf_chk3d_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_range:6;
        RBus_UInt32  f_num_3d_fail_det:1;
        RBus_UInt32  f_num_chk_3d_en:1;
        RBus_UInt32  res1:24;
    };
}vdpq_frame_buf_chk3d_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_num_close3d_cnt:4;
        RBus_UInt32  f_num_open3d_cnt:4;
        RBus_UInt32  res1:24;
    };
}vdpq_frame_buf_chk3d_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_valid2_en:1;
        RBus_UInt32  f_cennum_valid1_en:1;
        RBus_UInt32  f_cennum_valid_en:1;
        RBus_UInt32  res1:29;
    };
}vdpq_frame_buf_chk3d_cen_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_valid1_num:20;
        RBus_UInt32  res1:12;
    };
}vdpq_frame_buf_chk3d_cen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_cennum_valid2_num:20;
        RBus_UInt32  res1:12;
    };
}vdpq_frame_buf_chk3d_cen_num2_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_hennum_valid1_en:1;
        RBus_UInt32  f_hennum_valid_en:1;
        RBus_UInt32  res1:30;
    };
}vdpq_frame_buf_chk3d_hen_num1_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_hennum_valid1_num:20;
        RBus_UInt32  res1:12;
    };
}vdpq_frame_buf_chk3d_hen_num1_byte_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_st1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st1:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_st1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_end1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end1:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_end1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_st2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_st2:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_st2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vactive_end2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  vactive_grid_end2:10;
        RBus_UInt32  res2:6;
    };
}vdpq_dma_vactive_end2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_ififo_thr:6;
        RBus_UInt32  res1:26;
    };
}vdpq_dma_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_ofifo_thr:6;
        RBus_UInt32  res1:26;
    };
}vdpq_dma_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_ceiladr:6;
        RBus_UInt32  res1:26;
    };
}vdpq_dma_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_ctrl_bstlen:3;
        RBus_UInt32  dma_3d_on_vcnt:5;
        RBus_UInt32  dma_vcnt_sft_thr:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  dma_vcnt_sft_chk_en:1;
        RBus_UInt32  dma_vcnt_diff:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  ntsc443_tune:3;
        RBus_UInt32  dma_3d_on_off:1;
    };
}vdpq_dma_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mem_test_mode_ok:1;
        RBus_UInt32  mem_test_mode:1;
        RBus_UInt32  mem_off:1;
        RBus_UInt32  ififo_err_flag_4:1;
        RBus_UInt32  ififo_err_flag_3:1;
        RBus_UInt32  ififo_err_flag_2:1;
        RBus_UInt32  ififo_err_flag_1:1;
        RBus_UInt32  ofifo_err_flag:1;
        RBus_UInt32  res1:24;
    };
}vdpq_dma_ctrl5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_adc_in_sel:1;
        RBus_UInt32  dma_adc_in_en:1;
        RBus_UInt32  dma_field_inv:1;
        RBus_UInt32  res1:29;
    };
}vdpq_dma_ctrl6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debugif_stline:10;
        RBus_UInt32  dma_debugif_stline_en:1;
        RBus_UInt32  res1:21;
    };
}vdpq_debug_dma_if_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vd_sram_on_off:1;
        RBus_UInt32  vlpf_sram_bypass:1;
        RBus_UInt32  res1:30;
    };
}vdpq_vd_sram_on_off_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr0:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem0_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr1:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem1_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr2:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem2_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr3:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem3_addr_ini_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr0_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem0_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr1_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem1_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr2_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem2_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  frame_addr3_end:29;
        RBus_UInt32  res1:3;
    };
}vdpq_mem3_addr_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debug_adr:29;
        RBus_UInt32  res1:3;
    };
}vdpq_dma_debug_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debug_vbiend_adr:29;
        RBus_UInt32  res1:3;
    };
}vdpq_dma_debug_vbi_end_addr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_debugmode_en:1;
        RBus_UInt32  dma_debugmode_sel:2;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  dma_debug_vd_sel:4;
        RBus_UInt32  res1:24;
    };
}vdpq_video_dma_debug_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  dma_debug_rw_en:2;
        RBus_UInt32  dma_debug_one_rw_rlt:1;
        RBus_UInt32  res2:25;
    };
}vdpq_vbidma_test_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_sht_st_th:20;
        RBus_UInt32  chase_pix_num:4;
        RBus_UInt32  chase_per_frame_en:1;
        RBus_UInt32  dma_pix_sht_fix_en:1;
        RBus_UInt32  calib_delay_en:1;
        RBus_UInt32  calib_delay_sel:1;
        RBus_UInt32  calib_delay_frame_sel:1;
        RBus_UInt32  chase_line_pos_en:2;
        RBus_UInt32  calib_delay_hsync_en:1;
    };
}vdpq_dma_cnt_calibration1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pix_sht_end_th:20;
        RBus_UInt32  pix_sht_limit_th:8;
        RBus_UInt32  pix_sht_limit_en:1;
        RBus_UInt32  fscnum_dif_abs_sel:2;
        RBus_UInt32  res1:1;
    };
}vdpq_dma_cnt_calibration2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fscdif_sum_abs:20;
        RBus_UInt32  res1:4;
        RBus_UInt32  fscdif_num_abs:6;
        RBus_UInt32  res2:2;
    };
}vdpq_dma_cnt_calibration3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f1_cennum:16;
        RBus_UInt32  res1:16;
    };
}vdpq_frame_buffer_f1_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f2_cennum:16;
        RBus_UInt32  res1:16;
    };
}vdpq_frame_buffer_f2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_1:32;
    };
}vdpq_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_2:32;
    };
}vdpq_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adaptive_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  yc_linebf_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  ycsep_rdsel:1;
        RBus_UInt32  res3:22;
        RBus_UInt32  yc3d_tb_en:1;
    };
}vdpq_yc_sep_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  narrow_bpf_sel_y:4;
        RBus_UInt32  mid_bpf_sel_y:4;
        RBus_UInt32  wide_bpf_sel_y:4;
        RBus_UInt32  res1:20;
    };
}vdpq_bpf_bw_sel_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  narrow_bpf_sel_c:4;
        RBus_UInt32  mid_bpf_sel_c:4;
        RBus_UInt32  wide_bpf_sel_c:4;
        RBus_UInt32  res1:20;
    };
}vdpq_bpf_bw_sel_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_near_sel_c:1;
        RBus_UInt32  h2v_near_sel_y:1;
        RBus_UInt32  h2v_mid_sel_c:1;
        RBus_UInt32  h2v_mid_sel_y:1;
        RBus_UInt32  v2v_lk_c_en:1;
        RBus_UInt32  v2v_lk_y_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  h2v_lk_en:1;
        RBus_UInt32  res2:24;
    };
}vdpq_adap_bpf_c_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_vflag_mag_thr:4;
        RBus_UInt32  h2v_vflag_remag_thr:4;
        RBus_UInt32  res1:24;
    };
}vdpq_adap_bpf_c_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  palsw_level:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  pal_perr_auto_en:1;
        RBus_UInt32  pal_perr:1;
        RBus_UInt32  res2:25;
    };
}vdpq_comb_filter_config_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise_ntsc_c:8;
        RBus_UInt32  res1:24;
    };
}vdpq_comb_filter_threshold1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yalpha:1;
        RBus_UInt32  yalpha_en:1;
        RBus_UInt32  malpha_c:1;
        RBus_UInt32  malpha_c_en:1;
        RBus_UInt32  malpha_y:1;
        RBus_UInt32  malpha_y_en:1;
        RBus_UInt32  malpha_y_divider2_sel:1;
        RBus_UInt32  malpha_c_divider2_sel:1;
        RBus_UInt32  res1:24;
    };
}vdpq_adap_bpf_y_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chroma_bw_lo:3;
        RBus_UInt32  chroma_vlpf_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  pal_demod_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  chroma_vlpf_round_en:1;
        RBus_UInt32  res3:23;
    };
}vdpq_yc_bw_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode_2d:4;
        RBus_UInt32  debug_mode_2d_en:1;
        RBus_UInt32  res1:27;
    };
}vdpq_debug_2d_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_detect_thr:6;
        RBus_UInt32  bw_gain_sel:2;
        RBus_UInt32  res1:24;
    };
}vdpq_bw_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_edge_thr:8;
        RBus_UInt32  res1:24;
    };
}vdpq_bw_edge_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bpf_1d_sel_y:2;
        RBus_UInt32  blend_1d_thr:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  same_phase_diff_1d_gauge_en:1;
        RBus_UInt32  res2:23;
    };
}vdpq_blend_1d_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wide_1d_bpf_sel_c:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  narrow_1d_bpf_sel_c:3;
        RBus_UInt32  res2:25;
    };
}vdpq_blend_1d_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_coring_thr:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lut_sel_c:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  lut_sel_y:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  lut_fuzzy_th:4;
        RBus_UInt32  lut_large_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  halpha:4;
        RBus_UInt32  res5:3;
        RBus_UInt32  force_halpha_en:1;
    };
}vdpq_alpha_2d_mod_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_bw_color_gain:4;
        RBus_UInt32  h2v_cvbs_coring_thr:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  h2v_lut_hv_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  h2v_lut_hprefer_ratio:4;
        RBus_UInt32  res3:12;
    };
}vdpq_h2v_coring_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_y_noise_thr:8;
        RBus_UInt32  res1:24;
    };
}vdpq_h2v_y_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_cvbs_noise_thr:8;
        RBus_UInt32  res1:24;
    };
}vdpq_h2v_cvbs_noise_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_noise_max_hdy:8;
        RBus_UInt32  res1:24;
    };
}vdpq_h2v_noise_max_hdy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v2v_noise_y_add_dc:8;
        RBus_UInt32  v2v_lut_sel_y:1;
        RBus_UInt32  res1:23;
    };
}vdpq_h2v_noise_y_add_dc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h2v_blendratio:3;
        RBus_UInt32  res1:29;
    };
}vdpq_h2v_blend_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  xc_sel_gain:2;
        RBus_UInt32  res2:24;
    };
}vdpq_adap_bpf_y_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cdiff_bpf_ver_range:1;
        RBus_UInt32  cdiff_bpf_hor_range:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  cdiff_bpf_mm_diff_th:8;
        RBus_UInt32  cdiff_bpf_mm_small_th:6;
        RBus_UInt32  res3:10;
    };
}vdpq_cdiff_adap_bpf_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdiff_bpf_small_amp_wei:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cdiff_bpf_small_offset:4;
        RBus_UInt32  cdiff_bpf_large_amp_wei:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cdiff_bpf_large_offset:4;
        RBus_UInt32  cdiff_bpf_low_sat_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  cdiff_bpf_vspd_small_th:6;
        RBus_UInt32  res4:2;
    };
}vdpq_cdiff_adap_bpf_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vedge_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_tolerance:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hvdiff_comp_multiple:4;
        RBus_UInt32  hvdiff_comp_offset:8;
        RBus_UInt32  res3:8;
    };
}vdpq_bpf_vedge_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_upbound:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_lowbound:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  c_follow_y_en:1;
        RBus_UInt32  res3:15;
    };
}vdpq_bpf_vedge_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bypassbpf_adap_en:1;
        RBus_UInt32  complex_level_mode_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  complex_level_th:8;
        RBus_UInt32  lr_diff_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  lr_diff_lower_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  lr_diff_ratio:4;
    };
}vdpq_bypass_bpf_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_ratio_th:4;
        RBus_UInt32  newvedge_vdiff_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  newvedge_vdiff_ratio:4;
        RBus_UInt32  newvedge_lr_diff_th:7;
        RBus_UInt32  res2:9;
    };
}vdpq_bypass_bpf_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gridgirl_en:1;
        RBus_UInt32  grid_use_preflag_en:1;
        RBus_UInt32  grid_reset_sel:1;
        RBus_UInt32  gridgirl_corr_en:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  grid_cvbs_diff_th:8;
        RBus_UInt32  res2:15;
        RBus_UInt32  debug_mode_gridgirl:1;
    };
}vdpq_gridgirl_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_hordiff_th1:8;
        RBus_UInt32  grid_hordiff_th2:8;
        RBus_UInt32  grid_chroma_th1:8;
        RBus_UInt32  grid_chroma_th2:8;
    };
}vdpq_gridgirl_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_linesum_th1:8;
        RBus_UInt32  grid_linesum_th2:8;
        RBus_UInt32  grid_linecnt_th1:8;
        RBus_UInt32  grid_linecnt_th2:8;
    };
}vdpq_gridgirl_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_sum_left_bound:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_sum_right_bound:11;
        RBus_UInt32  res2:5;
    };
}vdpq_gridgirl_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grid_left_bound:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  grid_right_bound:11;
        RBus_UInt32  res2:5;
    };
}vdpq_gridgirl_th4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diamc_cvbsamp_still_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  vmc_widehspd_small_th:6;
        RBus_UInt32  res2:18;
    };
}vdpq_diamc_cvbs_amp_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diamc_en:1;
        RBus_UInt32  diamc_perfect_fid_en:1;
        RBus_UInt32  diamc_all_line_match_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  diamc_amp_low_bnd:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  diamc_fid_th_weight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  diamc_y_v_line_id_cnt_th:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  diamc_dc_still_th_weight:4;
        RBus_UInt32  diamc_dc_still_th_offset:6;
        RBus_UInt32  res5:2;
    };
}vdpq_diamc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmc_en:1;
        RBus_UInt32  perfect_fid_en:1;
        RBus_UInt32  slant_det_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  amp_low_bnd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_dc_still_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  vmc_cfollowy_en:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  ver_cvbsamp_still_th:6;
        RBus_UInt32  res5:2;
    };
}vdpq_vmc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnt_th_1:4;
        RBus_UInt32  cnt_th_2:4;
        RBus_UInt32  offset_1:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  offset_2:3;
        RBus_UInt32  res2:17;
    };
}vdpq_vmc_spatial_corr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postlpf_en:1;
        RBus_UInt32  postlpf_force_en:1;
        RBus_UInt32  postlpf_grad_en:1;
        RBus_UInt32  postlpf_dia_en:1;
        RBus_UInt32  res1:28;
    };
}vdpq_yc2d_postlp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_amp_th_0:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  low_amp_th_1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  low_amp_th_2:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  low_amp_th_3:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_flat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_amp_th_4:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_th_0:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hdiff_th_1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hdiff_th_2:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_flat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_th_3:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdiff_th_4:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_1:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_flat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_th_2:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_3:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_4:5;
        RBus_UInt32  res3:11;
    };
}vdpq_yc2d_postlp_flat_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  grad_flat_th_upbnd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  grad_flat_th_offset:4;
        RBus_UInt32  grad_flat_th_ratio:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  larger_cnt_th_0:4;
        RBus_UInt32  smaller_cnt_th_0:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  larger_cnt_th_1:4;
    };
}vdpq_yc2d_postlp_grad_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smaller_cnt_th_1:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  low_amp_th_grad_offset:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_0_grad:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_1_grad:5;
        RBus_UInt32  res4:7;
    };
}vdpq_yc2d_postlp_grad_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_th_2_grad:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_3_grad:5;
        RBus_UInt32  res2:19;
    };
}vdpq_yc2d_postlp_grad_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  larger_cnt_th_dia:4;
        RBus_UInt32  smaller_cnt_th_dia:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  low_amp_th_dia_offset:8;
        RBus_UInt32  spd_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  spd_large_ratio:4;
        RBus_UInt32  res3:4;
    };
}vdpq_yc2d_postlp_dia_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  spd_diff_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  dia_grad_flat_th_upbnd:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dia_grad_flat_th_offset:4;
        RBus_UInt32  dia_grad_flat_th_ratio:5;
        RBus_UInt32  res3:7;
    };
}vdpq_yc2d_postlp_dia_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vdiff_th_0_dia:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vdiff_th_1_dia:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  vdiff_th_2_dia:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  vdiff_th_3_dia:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc2d_postlp_dia_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dia_cedge_th:6;
        RBus_UInt32  res1:26;
    };
}vdpq_yc2d_postlp_dia_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yc_sep_mode:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  pal_mod_inv:1;
        RBus_UInt32  res2:19;
        RBus_UInt32  demodphase_fix:2;
        RBus_UInt32  res3:5;
        RBus_UInt32  demodphase_fix_en:1;
    };
}vdpq_yc_sep_mode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_3:32;
    };
}vdpq_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  yc3d_ychroma_bpf_sel:1;
        RBus_UInt32  yc3d_cchroma_bpf_sel:1;
        RBus_UInt32  res2:24;
    };
}vdpq_yc_3dsep_chroma_bpf_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slp_monotone_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  monotone_edge_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  monotone_flat_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  monotone_flat_cnt_th:4;
        RBus_UInt32  res4:8;
    };
}vdpq_yc_3d_f4_slp_mono_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c_change_cnt:16;
        RBus_UInt32  slp_cnt:16;
    };
}vdpq_yc_3d_f4_stat_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tempspd_small_cnt:16;
        RBus_UInt32  stat_tempspd_small_th:7;
        RBus_UInt32  res1:9;
    };
}vdpq_yc_3d_f4_stat_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hifreqdiff_not_small_cnt:16;
        RBus_UInt32  stat_hifreqdiff_not_small_th:8;
        RBus_UInt32  res1:8;
    };
}vdpq_yc_3d_f4_stat_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  slp_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  slp_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  sc_hfd_diff_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  sc_hfd_diff_large_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  sc_hfd_diff_large_ratio:4;
    };
}vdpq_yc_3d_f4_slp_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  match_cnt_th:4;
        RBus_UInt32  dc_still_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  large_hvspd_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cvbs_match_cnt_th_hvspd:4;
        RBus_UInt32  res3:8;
    };
}vdpq_yc_3d_f4_slp_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cvbs_match_cnt_th:4;
        RBus_UInt32  cvbsamp_diff_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  cvbsamp_diff_ratio:4;
        RBus_UInt32  cvbsamp_th:4;
        RBus_UInt32  cvbsamp_ratio:3;
        RBus_UInt32  res2:9;
    };
}vdpq_yc_3d_f4_slp_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ntsc_aba_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  aba_hifreqdiff_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  aba_aa_diff_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  aba_dc_change_th:6;
        RBus_UInt32  res4:6;
    };
}vdpq_yc_3d_f4_ntsc_aba_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aba_dc_multiple:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  aba_cvbsamp_ab_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  aba_cvbsamp_aa_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  aba_cvbsamp_multiple:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_ntsc_aba_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_4:32;
    };
}vdpq_dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_debug_mode_sel:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  f4_debug_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  f4_dbg_cvbs_amp_th:8;
        RBus_UInt32  f4_dbg_highfreq_diff_th:8;
        RBus_UInt32  f4_global_diff_dbg_sftbit:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  f4_en:1;
    };
}vdpq_yc_3d_f4_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_3d_spatial_cnt_th_1:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_2:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_3:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_4:4;
        RBus_UInt32  f4_3d_spatial_cnt_th_5:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  cvbs_amp_change_th:7;
        RBus_UInt32  res2:1;
    };
}vdpq_yc_3d_f4_spa_cnt_cvbs_amp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hv_diff_tolerance:4;
        RBus_UInt32  hv_local_diff_comp_ratio:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  hv_diff_large_offset_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hv_diff_large_multiple_th:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  hv_cvbs_diff_large_multiple_th:3;
        RBus_UInt32  res4:9;
    };
}vdpq_yc_3d_f4_hv_edge_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hv_edge_c_diff_small_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hv_edge_c_diff_small_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_diff_normalize_en:1;
        RBus_UInt32  res3:19;
    };
}vdpq_yc_3d_f4_hv_edge_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4_ver_hifreq_usepalmode:1;
        RBus_UInt32  f4_hor_hifreq_range:1;
        RBus_UInt32  f4_ver_chifreq_range:1;
        RBus_UInt32  f4_hor_chifreq_range:1;
        RBus_UInt32  f4_fill_hole_neightbor_diff_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  hifreq_postp_mode:1;
        RBus_UInt32  res2:19;
    };
}vdpq_yc_3d_f4_hifreq_det_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_level_change_th_base:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dc_level_change_th_multiple:4;
        RBus_UInt32  res2:20;
    };
}vdpq_yc_3d_f4_dc_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pal_error_detect_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  palerr_hifreq_diff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  palerr_accu_tolerance:4;
        RBus_UInt32  similary_th_multiple:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  similary_th_base:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pal_err_com_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  massive_palmode_error_large_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  massive_palmode_error_multiple_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_of_spd_small_th_multiple:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_of_spd_small_th_base:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pal_err_com_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f4f0_still_th_upbnd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  f4f0_still_th_offset:4;
        RBus_UInt32  f4f0_still_th_weight:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  palerr_massive_tolerance:4;
        RBus_UInt32  res3:7;
        RBus_UInt32  f4f0_still_en:1;
    };
}vdpq_yc_3d_f4_pal_err_com_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_vector_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  sv_vector_large_cnt_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  sv_vector_fid_offset:4;
        RBus_UInt32  sv_vector_fid_match_cnt_th:5;
        RBus_UInt32  res3:5;
        RBus_UInt32  sv_longtime_en:1;
        RBus_UInt32  sv_avg_dynamic_en:1;
    };
}vdpq_yc_3d_f4_still_vector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sv_self_diff_small_th:7;
        RBus_UInt32  res1:25;
    };
}vdpq_yc_3d_f4_still_vector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sghf_longtime_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  sghf_global_diff_small_th:8;
        RBus_UInt32  sghf_inter_diff_th:7;
        RBus_UInt32  res2:13;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sghf_vector_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  sghf_vector_large_cnt_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  sghf_vector_fid_offset:4;
        RBus_UInt32  sghf_vector_fid_match_cnt_th:5;
        RBus_UInt32  res3:6;
        RBus_UInt32  sghf_avg_dynamic_en:1;
    };
}vdpq_yc_3d_f4_still_gray_hifreq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_multiple_200:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_180:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_160:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_140:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pair_th_multiple_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_multiple_120:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_100:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_80:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_60:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pair_th_multiple_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_multiple_40:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  diff_th_multiple_20:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_multiple_10:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_multiple_0:5;
        RBus_UInt32  res4:3;
    };
}vdpq_yc_3d_f4_pair_th_multiple_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_200:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_180:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_160:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_140:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pair_th_base_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_120:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_100:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_80:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_60:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pair_th_base_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_40:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_base_20:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diff_th_base_10:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diff_th_base_0:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_pair_th_base_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c_diff_dpo_hedge_rshift_bit:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pal_error_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_vector_offset_base:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  still_vector_offset_multiple:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  hv_offset:6;
        RBus_UInt32  res5:2;
    };
}vdpq_yc_3d_f4_pair_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  still_vector_hifreq_diff_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  still_vector_cvbs_amp_change_offset:6;
        RBus_UInt32  res2:18;
    };
}vdpq_yc_3d_f4_pair_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flat_offset:4;
        RBus_UInt32  highfreq_diff_low_border:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  pair_diff_sel_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  later_diff_upper_bound:7;
        RBus_UInt32  res3:5;
    };
}vdpq_yc_3d_f4_pair_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hvdiff_border:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_2d_comp_3d_offset:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  diff_th_lower_bound:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  diff_th_upper_bound:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_3d_f4_pair_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  still_gray_hifreq_enable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  still_gray_hifreq_low_border:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  still_gray_hifreq_th:7;
        RBus_UInt32  res3:13;
    };
}vdpq_yc_3d_f4_pair_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdy_small_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dc_level_fierce_change_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_offset_dc_fierce_change:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  global_diff_tolerance:4;
        RBus_UInt32  res4:4;
    };
}vdpq_yc_3d_f4_pair_ctrl_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_180:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_160:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_140:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_120:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_100:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_80:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_70:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_60:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_50:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_40:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_30:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  global_diff_th_hifreq_offset_20:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  global_diff_th_hifreq_offset_10:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  global_diff_th_hifreq_offset_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  global_diff_th_hifreq_offset_5:6;
        RBus_UInt32  res3:10;
    };
}vdpq_yc_3d_f4_global_diff_th_hifreq_offset_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dc_level_hor_dc_check_en:1;
        RBus_UInt32  moving_vline_en:1;
        RBus_UInt32  mghf_enable:1;
        RBus_UInt32  mghf_flag:1;
        RBus_UInt32  moving_vline_flat_ver_cvbs_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  moving_vline_ver_dc_level_fierce_change_th:5;
        RBus_UInt32  res2:15;
    };
}vdpq_yc_3d_f4_mghf_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hor_c_change_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  cvbs_still_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hifreq_diff_large_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hor_c_change_ratio:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  large_hifreq_diff_ratio:3;
        RBus_UInt32  res5:1;
    };
}vdpq_yc_3d_f4_mghf_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diff_th_base_5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  diff_th_multiple_5:5;
        RBus_UInt32  res2:19;
    };
}vdpq_yc_3d_f4_global_diff_th_com_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbwline_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  diadiff_small_base:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  diadiff_small_weight:4;
        RBus_UInt32  diadiff_small_upbnd:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  diadiff_vspd_large_th:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_post2dbpf_dbwline_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_sat_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dbwline_hor_cdiff_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  dbwline_hspd_small_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  dbwline_d45_hspd_large_th:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_post2dbpf_dbwline_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dbwline_d45_diadiff_small_th:7;
        RBus_UInt32  res1:25;
    };
}vdpq_yc_post2dbpf_dbwline_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  post2dbpf_y_en:1;
        RBus_UInt32  post2dbpf_c_en:1;
        RBus_UInt32  greenish_detected_en:1;
        RBus_UInt32  mghf_narrowbpf_en:1;
        RBus_UInt32  weight_3d_y:2;
        RBus_UInt32  weight_bld_y:2;
        RBus_UInt32  weight_2d_y:2;
        RBus_UInt32  weight_3d_c:2;
        RBus_UInt32  weight_bld_c:2;
        RBus_UInt32  weight_2d_c:2;
        RBus_UInt32  gremove_bpfedc_small_th:4;
        RBus_UInt32  gremove_c_small_th:5;
        RBus_UInt32  res1:7;
    };
}vdpq_yc_post2dbpf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ver_cdiff_th_base:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  hor_cdiff_th_base:7;
        RBus_UInt32  res2:17;
    };
}vdpq_yc_post2dbpf_thbase_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dual_ch_bpfedcdiff_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  dual_ch_bpfedcdiff_large_ratio:4;
        RBus_UInt32  dual_ch_bpfedc_small_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  bpfed_c_diff_small_th:7;
        RBus_UInt32  res3:5;
    };
}vdpq_yc_post2dbpf_adapth_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bpfed_c_diff_small_ver_offset:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  bpfed_c_diff_small_hor_offset:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  bpfed_c_diff_large_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  bpfed_c_diff_large_hor_offset:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_post2dbpf_adapth_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdy_spd_small_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  vspd_small_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  neighbor_hdiff_small_ver_offset:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  neighbor_vdiff_small_hor_offset:6;
        RBus_UInt32  res4:2;
    };
}vdpq_yc_post2dbpf_adapth_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_tolerance:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hdy_spd_large_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  vspd_large_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  hvedge_diff_large_ratio:4;
        RBus_UInt32  res4:4;
    };
}vdpq_yc_post2dbpf_adapth_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hedge_ver_offset:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  vedge_hor_offset:7;
        RBus_UInt32  res2:17;
    };
}vdpq_yc_post2dbpf_adapth_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dia_spd_large_th_base:8;
        RBus_UInt32  dia_spd_large_th_small_hordiff_offset:8;
        RBus_UInt32  dia_spd_large_th_small_hordiff_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  dia_spd_large_ver_offset:7;
        RBus_UInt32  res2:1;
    };
}vdpq_yc_post2dbpf_adapth_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dual_ch_cdiff_large_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  dual_ch_cdiff_large_ratio:4;
        RBus_UInt32  dual_ch_c_small_th:5;
        RBus_UInt32  res2:15;
    };
}vdpq_yc_post2dbpf_adapth_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_large_th:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  hdiff_vdiff_diff_larger_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hdiff_much_larger_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hdiff_much_larger_ratio:4;
        RBus_UInt32  res4:4;
    };
}vdpq_yc_post2dbpf_adapth_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hdiff_much_larger_hor_offset:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_color_tran_hdiff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_color_tran_ver_cdiff_small_th:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_color_tran_ver_offset:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_post2dbpf_adapth_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  colorbar_vdiff_small_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  colorbar_hdiff_large_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  colorbar_detect_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  colorbar_detect_hor_offset:7;
        RBus_UInt32  res4:1;
    };
}vdpq_yc_post2dbpf_adapth_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smooth_vdiff_small_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  smooth_hdiff_small_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  smooth_detect_ver_offset:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  ver_avoid_th_y:4;
        RBus_UInt32  ver_avoid_th_c:4;
    };
}vdpq_yc_post2dbpf_adapth_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  v2sides_gray_diff_small_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  v2sides_diff_large_th:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  v2sides_diff_large_ratio:4;
        RBus_UInt32  vcdiff_large_ratio:4;
        RBus_UInt32  vcdiff_large_diff_th:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  vedge_avoid_en:1;
    };
}vdpq_yc_post2dbpf_adapth_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ignore_th_y:4;
        RBus_UInt32  ignore_th_c:4;
        RBus_UInt32  hedge_bypass_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hedge_ratio_th:4;
        RBus_UInt32  upbnd:8;
        RBus_UInt32  res2:8;
    };
}vdpq_yc_post2dbpf_adapth_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xc_hvedge_th_1:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  xc_hvedge_ratio_th_1:4;
        RBus_UInt32  xc_hvedge_th_2:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  xc_hvedge_ratio_th_2:4;
        RBus_UInt32  xc_cdiff_upbnd:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  xc_hvedge_avoid_en:1;
    };
}vdpq_yc_post2dbpf_xc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yadap_peak_mode:2;
        RBus_UInt32  yadap_hpf_sel:2;
        RBus_UInt32  res1:28;
    };
}vdpq_secam_yadap_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yadap_peak_th:4;
        RBus_UInt32  yadap_peak_gain:4;
        RBus_UInt32  res1:24;
    };
}vdpq_secam_yadap_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  yadap_uniform_gain:4;
        RBus_UInt32  yadap_peak_gain_2d:4;
        RBus_UInt32  res1:24;
    };
}vdpq_secam_yadap_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_en:1;
        RBus_UInt32  xnr_det_bypass_en:1;
        RBus_UInt32  xnr_blend_en:1;
        RBus_UInt32  xnr_blend_dbm:1;
        RBus_UInt32  xnr_vlpf_sel:2;
        RBus_UInt32  xnr_lpf_sel:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  postpq_malphadelay:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  postpq_alphadelay:6;
        RBus_UInt32  res3:5;
        RBus_UInt32  postpq_alphadelay_indep_en:1;
    };
}vdpq_xnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_csum_thr:4;
        RBus_UInt32  xnr_cdiff_thr:4;
        RBus_UInt32  res1:24;
    };
}vdpq_xnr_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_ver_idxgain:4;
        RBus_UInt32  xnr_idxgain:4;
        RBus_UInt32  res1:24;
    };
}vdpq_xnr_idx_thr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_ver_ratio_w:4;
        RBus_UInt32  xnr_ver_ratio:4;
        RBus_UInt32  res1:24;
    };
}vdpq_xnr_ratio_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma0_con_en:1;
        RBus_UInt32  cdiff_small_con_en:1;
        RBus_UInt32  vline_con_en:1;
        RBus_UInt32  vline_len_3_sel:1;
        RBus_UInt32  point_type_coring_lv:4;
        RBus_UInt32  ma0_cnt_th:5;
        RBus_UInt32  mf_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ver_cedge_en:1;
        RBus_UInt32  ver_cedge_single_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  ver_cedge_sum_th:7;
        RBus_UInt32  res3:1;
    };
}vdpq_postp_mf_compensation_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cdiff_small_len:4;
        RBus_UInt32  cdiff_small_single_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cdiff_small_sum_th:7;
        RBus_UInt32  res2:13;
    };
}vdpq_postp_mf_compensation_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_en:1;
        RBus_UInt32  postpk_adappk_en:1;
        RBus_UInt32  postpk_adap_mode:2;
        RBus_UInt32  postpk_dnoise_en:1;
        RBus_UInt32  postpk_alphablend_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  postpk_prelpf_en:1;
        RBus_UInt32  postpk_prelpf_mode:1;
        RBus_UInt32  res2:22;
    };
}vdpq_yc2d_postpk2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_y_lwbnd:8;
        RBus_UInt32  postpk_y_stepbit:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  postpk_c_lwbnd:8;
        RBus_UInt32  postpk_c_stepbit:3;
        RBus_UInt32  res2:5;
    };
}vdpq_yc2d_postpk2_adap1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_lv_th:8;
        RBus_UInt32  postpk_lv_sft:3;
        RBus_UInt32  res1:5;
        RBus_UInt32  postpk_lv_upbnd:8;
        RBus_UInt32  res2:8;
    };
}vdpq_yc2d_postpk2_dnoise1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_c2:8;
        RBus_UInt32  postpk_c1:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  postpk_c0:9;
        RBus_UInt32  res2:3;
    };
}vdpq_yc2d_postpk2_filter_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_gain_neg:8;
        RBus_UInt32  postpk_gain_pos:8;
        RBus_UInt32  res1:16;
    };
}vdpq_yc2d_postpk2_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  postpk_lv:8;
        RBus_UInt32  postpk_hv_neg:10;
        RBus_UInt32  postpk_hv_pos:10;
        RBus_UInt32  res1:4;
    };
}vdpq_yc2d_postpk2_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_en:1;
        RBus_UInt32  dlti_pnth:7;
        RBus_UInt32  dlti_maxlen:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dlti_ffd1_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  dlti_ffd1_ratio:4;
        RBus_UInt32  dlti_ffd2_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  dlti_ffd2_ratio:4;
    };
}vdpq_postp_dlti_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_ffd2_range2r:4;
        RBus_UInt32  dlti_ffd2_range2l:4;
        RBus_UInt32  dlti_can_shift:4;
        RBus_UInt32  dlti_ovc_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlti_tn_blend_en:1;
        RBus_UInt32  dlti_tn_blend_mode:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  dlti_dcp_th:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  dlti_d1_cp_shift:4;
    };
}vdpq_postp_dlti_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_cchange_corr_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  dlti_cchange_len:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  dlti_uv_diff_th_1:8;
        RBus_UInt32  dlti_uv_diff_th_2:8;
        RBus_UInt32  dlti_cchange_srcwei_offset_1:4;
        RBus_UInt32  dlti_cchange_srcwei_offset_2:4;
    };
}vdpq_postp_dlti_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tngain0:4;
        RBus_UInt32  dlti_tngain1:4;
        RBus_UInt32  dlti_tngain2:4;
        RBus_UInt32  dlti_tngain3:4;
        RBus_UInt32  dlti_tngain4:4;
        RBus_UInt32  dlti_tngain5:4;
        RBus_UInt32  dlti_tngain6:4;
        RBus_UInt32  dlti_tngain7:4;
    };
}vdpq_postp_dlti_tngain_gain_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tngain8:4;
        RBus_UInt32  dlti_tngain9:4;
        RBus_UInt32  dlti_tngain10:4;
        RBus_UInt32  dlti_tngain11:4;
        RBus_UInt32  dlti_tngain12:4;
        RBus_UInt32  dlti_tngain13:4;
        RBus_UInt32  dlti_tngain14:4;
        RBus_UInt32  res1:4;
    };
}vdpq_postp_dlti_tngain_gain_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tnoffset0:4;
        RBus_UInt32  dlti_tnoffset1:4;
        RBus_UInt32  dlti_tnoffset2:4;
        RBus_UInt32  dlti_tnoffset3:4;
        RBus_UInt32  dlti_tnoffset4:4;
        RBus_UInt32  dlti_tnoffset5:4;
        RBus_UInt32  dlti_tnoffset6:4;
        RBus_UInt32  dlti_tnoffset7:4;
    };
}vdpq_postp_dlti_tngain_offset_tab1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dlti_tnoffset8:4;
        RBus_UInt32  dlti_tnoffset9:4;
        RBus_UInt32  dlti_tnoffset10:4;
        RBus_UInt32  dlti_tnoffset11:4;
        RBus_UInt32  dlti_tnoffset12:4;
        RBus_UInt32  dlti_tnoffset13:4;
        RBus_UInt32  dlti_tnoffset14:4;
        RBus_UInt32  res1:4;
    };
}vdpq_postp_dlti_tngain_offset_tab2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pd_sel:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  pd_sel_dlti_diff_th:8;
        RBus_UInt32  pd_sel_dlti_cnt_th1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  pd_sel_dlti_cnt_th2:3;
        RBus_UInt32  res3:13;
    };
}vdpq_postp_dlti_pk_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xnr_alpha_3d_weight:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  xnr_alpha_bld_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  xnr_alpha_2d_weight:3;
        RBus_UInt32  res3:5;
        RBus_UInt32  dlti_alpha_3d_weight:2;
        RBus_UInt32  dlti_alpha_bld_weight:2;
        RBus_UInt32  dlti_alpha_2d_weight:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  pk_alpha_3d_weight:2;
        RBus_UInt32  pk_alpha_bld_weight:2;
        RBus_UInt32  pk_alpha_2d_weight:2;
        RBus_UInt32  res5:2;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mfnotch_alpha_2d_weight:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  notch_force_3dweight:4;
        RBus_UInt32  notch_force_upbnd:8;
        RBus_UInt32  snr_alpha_3d_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  snr_alpha_bld_weight:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  snr_alpha_2d_weight:3;
        RBus_UInt32  res4:4;
        RBus_UInt32  alphablend_round_en:1;
    };
}vdpq_postp_3d2dalpha_blend_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ntsc443_lpf_th_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ntsc443_lpf_ext:2;
        RBus_UInt32  res2:25;
        RBus_UInt32  ntsc443_lpf:1;
    };
}vdpq_postp_ntsc443_lpf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_sweightydebug:2;
        RBus_UInt32  res1:30;
    };
}vdpq_spnr_debugmode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialenabley:1;
        RBus_UInt32  cp_spatialenablec:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  cp_zoranweight4y:2;
        RBus_UInt32  cp_zoranweight3y:2;
        RBus_UInt32  cp_zoranweight2y:2;
        RBus_UInt32  cp_zoranfiltersizey:2;
        RBus_UInt32  cp_sresultweight:3;
        RBus_UInt32  res2:5;
    };
}vdpq_spnr_cp_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_spatialthly:8;
        RBus_UInt32  cp_spatialthlyx2:8;
        RBus_UInt32  cp_spatialthlyx4:8;
        RBus_UInt32  res1:8;
    };
}vdpq_spnr_spatial_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  cp_ringgain:1;
        RBus_UInt32  cp_ringrange:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_fixedweight2y:1;
        RBus_UInt32  cp_fixedweight1y:1;
        RBus_UInt32  cp_weight2y:4;
        RBus_UInt32  cp_weight1y:4;
        RBus_UInt32  cp_ringweighty:4;
        RBus_UInt32  res3:4;
    };
}vdpq_spnr_spatial_weight_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_status:32;
    };
}vdpq_dummy_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_edge_weight:2;
        RBus_UInt32  res1:14;
        RBus_UInt32  cp_sw_edge_thl:16;
    };
}vdpq_spnr_local_var2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  notch_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  notch_upbnd_upbnd:8;
        RBus_UInt32  notch_upbnd_weight:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  notch_upbnd_offset:6;
        RBus_UInt32  res3:6;
    };
}vdpq_notch_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  notch_lowbnd:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  high_sat_lowbnd:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  high_sat_weight_do:4;
        RBus_UInt32  high_sat_weight_undo:4;
        RBus_UInt32  large_notchy_amp_th:6;
        RBus_UInt32  res3:2;
    };
}vdpq_notch_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  large_notchy_amp_weight_do:4;
        RBus_UInt32  large_notchy_amp_weight_undo:4;
        RBus_UInt32  very_diff_large_th:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  very_diff_large_weight_do:4;
        RBus_UInt32  very_diff_large_weight_undo:4;
        RBus_UInt32  very_nonmonotone_weight_do:4;
        RBus_UInt32  very_nonmonotone_weight_undo:4;
    };
}vdpq_notch_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  large_cdiff_th:8;
        RBus_UInt32  large_cdiff_weight_do:4;
        RBus_UInt32  large_cdiff_weight_undo:4;
        RBus_UInt32  vline_weight_undo:4;
        RBus_UInt32  force_notch_weight:4;
        RBus_UInt32  res1:8;
    };
}vdpq_notch_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  de_xc_thr:4;
        RBus_UInt32  de_xc_en:1;
        RBus_UInt32  xc_blend_en:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  postpq_alphablend_dbm:1;
    };
}vdpq_de_xc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cnr_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cnr_lpf_sel:2;
        RBus_UInt32  res2:28;
    };
}vdpq_cnr_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_cti_en:1;
        RBus_UInt32  cadap_yuvsync_en:1;
        RBus_UInt32  cadap_uvsync_en:1;
        RBus_UInt32  cadap_ylpf_en:1;
        RBus_UInt32  cadap_clpf_en:1;
        RBus_UInt32  cadap_spatial_lpf_out:1;
        RBus_UInt32  res1:26;
    };
}vdpq_cadap_enable_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_y_sync_uni_en:1;
        RBus_UInt32  cadap_uv_sync_uni_en:1;
        RBus_UInt32  cadap_uni_gain_ctrl_en:1;
        RBus_UInt32  res1:29;
    };
}vdpq_cadap_enable_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_level:4;
        RBus_UInt32  cadap_gain:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_zc_mag_th_y_c:4;
        RBus_UInt32  cadap_zc_mag_th_y:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_zc_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_dir_det_gain:4;
        RBus_UInt32  cadap_zc_mag_th_c:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_zc_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_dir_uni_th:4;
        RBus_UInt32  cadap_ver_uni_th:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_ver_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_uv_sync_uni_th:4;
        RBus_UInt32  cadap_y_sync_uni_th:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_sync_uniformity_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_lut_level_thb:4;
        RBus_UInt32  cadap_lut_level_tha:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_lut_level_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cadap_lut_gain_thb:4;
        RBus_UInt32  cadap_lut_gain_tha:4;
        RBus_UInt32  res1:24;
    };
}vdpq_cadap_lut_gain_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_b1:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_b1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_b2:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_b2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_b3:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_b3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_a2:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_a2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_coef_a3:11;
        RBus_UInt32  res1:21;
    };
}vdpq_dcti_filter_coef_a3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dcti_filter_en:1;
        RBus_UInt32  res1:31;
    };
}vdpq_dcti_filter_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_en:1;
        RBus_UInt32  smd_00_move_enable:1;
        RBus_UInt32  smd_02_move_enable:1;
        RBus_UInt32  smd_04_move_enable:1;
        RBus_UInt32  smd_06_move_enable:1;
        RBus_UInt32  smd_08_move_enable:1;
        RBus_UInt32  smd_10_move_enable:1;
        RBus_UInt32  res1:25;
    };
}vdpq_yc_3d_f4_smd_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_horizontal_sad_tolerance:8;
        RBus_UInt32  smd_vertical_sad_tolerance:8;
        RBus_UInt32  smd_spatial_temporal_traily_diff:8;
        RBus_UInt32  res1:8;
    };
}vdpq_yc_3d_f4_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_min_sad_horizontal:8;
        RBus_UInt32  smd_min_sad_vetical:8;
        RBus_UInt32  res1:16;
    };
}vdpq_yc_3d_f4_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_highfreq_diff_th:8;
        RBus_UInt32  smd_highfreq_diff_2_th:8;
        RBus_UInt32  smd_2d_small_global_diff_offset:16;
    };
}vdpq_yc_3d_f4_pair_smd_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_2d_not_small_global_diff_offset:16;
        RBus_UInt32  res1:16;
    };
}vdpq_yc_3d_f4_pair_smd_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sum_vm:32;
    };
}vdpq_ns_r1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  maxv:16;
        RBus_UInt32  countv:16;
    };
}vdpq_ns_r2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sumv:32;
    };
}vdpq_ns_r3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vmm:16;
        RBus_UInt32  nfactor:8;
        RBus_UInt32  res1:8;
    };
}vdpq_ns_rw1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  meannxv:16;
        RBus_UInt32  density:8;
        RBus_UInt32  res1:8;
    };
}vdpq_ns_rw2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_color_reduce_ctrl:2;
        RBus_UInt32  secam_fix_pre_yvlpf_en:1;
        RBus_UInt32  secam_fix_post_cvlpf_en:1;
        RBus_UInt32  secam_fix_debug_mode:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  secam_fix_grey_thd:8;
        RBus_UInt32  secam_fix_line_grey_ratio:4;
        RBus_UInt32  res2:10;
        RBus_UInt32  secam_fix_color_reduce_en:1;
        RBus_UInt32  secam_fix_uv_flag_en:1;
    };
}vdpq_postp_secam_fix_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_y_flag_ext_r:8;
        RBus_UInt32  secam_fix_y_flag_ext_l:8;
        RBus_UInt32  secam_fix_y_action_continue_d_time:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_fix_y_diff_thd:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  secam_fix_y_flag_en:1;
    };
}vdpq_postp_secam_fix_y_detect0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  secam_fix_y_target_d0:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  secam_fix_y_target_d1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  secam_fix_y_target_d2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  secam_fix_y_target_d3:6;
        RBus_UInt32  res4:2;
    };
}vdpq_postp_secam_fix_y_detect1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_5:32;
    };
}vdpq_dummy_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_6:32;
    };
}vdpq_dummy_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_7:32;
    };
}vdpq_dummy_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_8_motion_status:4;
	 RBus_UInt32  dummy_8_log_enable:1;
	 RBus_UInt32  dummy_8_print_time:8;
	 RBus_UInt32  dummy_8_set_scan_enable:1;
	 RBus_UInt32  dummy_8_auto_disable:1;
	 RBus_UInt32  dummy_8_res:17;
    };
}vdpq_dummy_8_RBUS;




#endif


#endif
