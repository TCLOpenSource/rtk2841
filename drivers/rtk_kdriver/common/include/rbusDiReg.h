/**
* @file rbusDiReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2015/6/12
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_DI_REG_H_
#define _RBUS_DI_REG_H_

#include "rbusTypes.h"



//  DI Register Address



#define  DI_IM_DI_CONTROL_VADDR                             	(0xb8024000)
#define  DI_COLOR_RECOVERY_OPTION_VADDR                     	(0xb8024004)
#define  DI_IM_DI_DEBUG_MODE_VADDR                          	(0xb8024008)
#define  DI_IM_DI_ACTIVE_WINDOW_CONTROL_VADDR               	(0xb802400c)
#define  DI_IM_DI_WEAVE_WINDOW_CONTROL_VADDR                	(0xb8024010)
#define  DI_IM_DI_WEAVE_WINDOW_0_START_VADDR                	(0xb8024014)
#define  DI_IM_DI_WEAVE_WINDOW_0_END_VADDR                  	(0xb8024018)
#define  DI_IM_DI_WEAVE_WINDOW_1_START_VADDR                	(0xb802401c)
#define  DI_IM_DI_WEAVE_WINDOW_1_END_VADDR                  	(0xb8024020)
#define  DI_IM_DI_WEAVE_WINDOW_2_START_VADDR                	(0xb8024024)
#define  DI_IM_DI_WEAVE_WINDOW_2_END_VADDR                  	(0xb8024028)
#define  DI_IM_DI_WEAVE_WINDOW_3_START_VADDR                	(0xb802402c)
#define  DI_IM_DI_WEAVE_WINDOW_3_END_VADDR                  	(0xb8024030)
#define  DI_IM_DI_WEAVE_WINDOW_4_START_VADDR                	(0xb8024034)
#define  DI_IM_DI_WEAVE_WINDOW_4_END_VADDR                  	(0xb8024038)
#define  DI_IM_DI_WEAVE_WINDOW_5_START_VADDR                	(0xb802403c)
#define  DI_IM_DI_WEAVE_WINDOW_5_END_VADDR                  	(0xb8024040)
#define  DI_IM_DI_CLASSIFY_THCLASSIFY_THRESHOLD_VADDR       	(0xb8024044)
#define  DI_IM_DI_BLEND_AND_WEIGHTING_METHOD_VADDR          	(0xb8024048)
#define  DI_IM_DI_MPEG_SEQUENCE_APP_VADDR                   	(0xb802404c)
#define  DI_IM_DI_CLASSIFY2_THCLASSIFY_THRESHOLD_VADDR      	(0xb8024050)
#define  DI_IM_DI_NEW_CLASS_VADDR                           	(0xb8024054)
#define  DI_IM_DI_DMA_VADDR                                 	(0xb8024058)
#define  DI_IM_DI_XC_AUTO_BALANCE_TH_VADDR                  	(0xb8024068)
#define  DI_IM_DI_XC_AUTO_BALANCE_TH2_VADDR                 	(0xb802406c)
#define  DI_IM_DI_XC_AUTO_BALANCE_TH3_VADDR                 	(0xb8024070)
#define  DI_IM_DI_INTRA_SOBEL_MOTION_TH_VADDR               	(0xb8024074)
#define  DI_IM_DI_INTRA_LINE_CONT_TH_VADDR                  	(0xb8024078)
#define  DI_IM_DI_INTRA_TH_VADDR                            	(0xb802407c)
#define  DI_IM_DI_MA_FRAME_MOTION_TH_A_VADDR                	(0xb8024080)
#define  DI_IM_DI_MA_FRAME_MOTION_TH_B_VADDR                	(0xb8024084)
#define  DI_IM_DI_MA_FRAME_MOTION_TH_C_VADDR                	(0xb8024088)
#define  DI_IM_DI_MA_FIELD_TEETH_TH_A_VADDR                 	(0xb802408c)
#define  DI_IM_DI_MA_OTHERS_TH_VADDR                        	(0xb8024090)
#define  DI_IM_DI_MA_SAWTOOTH_TH_VADDR                      	(0xb8024094)
#define  DI_IM_DI_MA_VERTEXT_TH_B_VADDR                     	(0xb802409c)
#define  DI_IM_DI_FILM_SAWTOOTH_FILMFRAME_TH_VADDR          	(0xb80240a0)
#define  DI_IM_DI_FILM_STATIC_SUM_TH_VADDR                  	(0xb80240a4)
#define  DI_IM_DI_FILM_FIELD_JUDGE_TH_VADDR                 	(0xb80240a8)
#define  DI_IM_DI_FILM_STATIC_SUM_SUB_TH_VADDR              	(0xb80240ac)
#define  DI_IM_DI_FILM_FIELD_JUDGE_SUB_TH_VADDR             	(0xb80240b0)
#define  DI_IM_DI_FILM_MOTION_SUM_TH_VADDR                  	(0xb80240b4)
#define  DI_IM_DI_SI_FILM_BOUND_VADDR                       	(0xb80240b8)
#define  DI_RESERVED_1_VADDR                                	(0xb80240bc)
#define  DI_IM_DI_SI_FILM_HB_COUT_VADDR                     	(0xb80240c0)
#define  DI_IM_DI_SI_FILM_FINAL_RESULT_VADDR                	(0xb80240c4)
#define  DI_IM_DI_SI_FILM_PATTERN_A_VADDR                   	(0xb80240c8)
#define  DI_IM_DI_SI_FILM_PATTERN_B_VADDR                   	(0xb80240cc)
#define  DI_IM_DI_SI_FILM_32_RESULT_1_A_VADDR               	(0xb80240d0)
#define  DI_IM_DI_SI_FILM_32_RESULT_1_B_VADDR               	(0xb80240d4)
#define  DI_IM_DI_SI_FILM_32_RESULT_2_A_VADDR               	(0xb80240d8)
#define  DI_IM_DI_SI_FILM_32_RESULT_2_B_VADDR               	(0xb80240dc)
#define  DI_IM_DI_SI_FILM_22_RESULT_A_VADDR                 	(0xb80240e0)
#define  DI_IM_DI_SI_FILM_22_RESULT_B_VADDR                 	(0xb80240e4)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_VADDR                 	(0xb80240e8)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_H_T_VADDR             	(0xb80240ec)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_H_M_VADDR             	(0xb80240f0)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_H_B_VADDR             	(0xb80240f4)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_V_L_VADDR             	(0xb80240f8)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_V_M_VADDR             	(0xb80240fc)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_V_R_VADDR             	(0xb8024100)
#define  DI_IM_DI_SI_FILM_MOTION_NEXT_C_VADDR               	(0xb8024104)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_VADDR                  	(0xb8024108)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_H_T_VADDR              	(0xb802410c)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_H_M_VADDR              	(0xb8024110)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_H_B_VADDR              	(0xb8024114)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_V_L_VADDR              	(0xb8024118)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_V_M_VADDR              	(0xb802411c)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_V_R_VADDR              	(0xb8024120)
#define  DI_IM_DI_SI_FILM_MOTION_PRE_C_VADDR                	(0xb8024124)
#define  DI_IM_DI_SI_FILM_MOTION_VADDR                      	(0xb8024128)
#define  DI_IM_DI_SI_FILM_MOTION_H_T_VADDR                  	(0xb802412c)
#define  DI_IM_DI_SI_FILM_MOTION_H_M_VADDR                  	(0xb8024130)
#define  DI_IM_DI_SI_FILM_MOTION_H_B_VADDR                  	(0xb8024134)
#define  DI_IM_DI_SI_FILM_MOTION_V_L_VADDR                  	(0xb8024138)
#define  DI_IM_DI_SI_FILM_MOTION_V_M_VADDR                  	(0xb802413c)
#define  DI_IM_DI_SI_FILM_MOTION_V_R_VADDR                  	(0xb8024140)
#define  DI_IM_DI_SI_FILM_MOTION_C_VADDR                    	(0xb8024144)
#define  DI_IM_DI_SI_FILM_MOTION_H_11_VADDR                 	(0xb8024148)
#define  DI_IM_DI_SI_FILM_MOTION_H_10_VADDR                 	(0xb802414c)
#define  DI_IM_DI_SI_FILM_MOTION_H_09_VADDR                 	(0xb8024150)
#define  DI_IM_DI_SI_FILM_MOTION_H_08_VADDR                 	(0xb8024154)
#define  DI_IM_DI_SI_FILM_MOTION_H_07_VADDR                 	(0xb8024158)
#define  DI_IM_DI_SI_FILM_MOTION_H_06_VADDR                 	(0xb802415c)
#define  DI_IM_DI_SI_FILM_MOTION_H_05_VADDR                 	(0xb8024160)
#define  DI_IM_DI_SI_FILM_MOTION_H_04_VADDR                 	(0xb8024164)
#define  DI_IM_DI_SI_FILM_MOTION_H_03_VADDR                 	(0xb8024168)
#define  DI_IM_DI_SI_FILM_MOTION_H_02_VADDR                 	(0xb802416c)
#define  DI_IM_DI_SI_FILM_MOTION_H_01_VADDR                 	(0xb8024170)
#define  DI_IM_DI_SI_FILM_MOTION_H_00_VADDR                 	(0xb8024174)
#define  DI_IM_DI_SI_MA_TOTAL_FM_SUM_VADDR                  	(0xb8024178)
#define  DI_IM_DI_SI_MA_LARGE_FM_PIXEL_VADDR                	(0xb802417c)
#define  DI_IM_DI_SI_MA_LARGE_FM_SUM_VADDR                  	(0xb8024180)
#define  DI_IM_DI_SI_MA_MESS_H_PIXEL_VADDR                  	(0xb8024184)
#define  DI_IM_DI_SI_IMAGE_BALANCE_VADDR                    	(0xb8024188)
#define  DI_IM_DI_SI_SUB_IN_AUTO_BALANCE_VADDR              	(0xb802418c)
#define  DI_IM_DI_CRC_RESULT_VADDR                          	(0xb8024190)
#define  DI_IM_DI_SI_STILL_INFO_FOR_NE_VADDR                	(0xb8024194)
#define  DI_IM_DI_SI_FILM22_DETECTOR_PATTERN_VADDR          	(0xb8024198)
#define  DI_IM_DI_TNR_TH_VADDR                              	(0xb802419c)
#define  DI_IM_DI_RTNR_CONTROL_VADDR                        	(0xb80241a0)
#define  DI_IM_DI_RTNR_K_FORCE_MODIFY_VADDR                 	(0xb80241a4)
#define  DI_TR2TO1_VADDR                                    	(0xb80241a8)
#define  DI_IM_DI_RTNR_K_FORCE_MODIFY_TH_VADDR              	(0xb80241ac)
#define  DI_IM_DI_RTNR_MAD_Y_TH_VADDR                       	(0xb80241b0)
#define  DI_IM_DI_RTNR_MAD_C_TH_VADDR                       	(0xb80241b4)
#define  DI_IM_DI_RTNR_MAD_Y_COUNTER_VADDR                  	(0xb80241b8)
#define  DI_IM_DI_RTNR_MAD_U_COUNTER_VADDR                  	(0xb80241bc)
#define  DI_IM_DI_RTNR_MAD_V_COUNTER_VADDR                  	(0xb80241c0)
#define  DI_IM_DI_RTNR_EDIFF_CONTROL_VADDR                  	(0xb80241c4)
#define  DI_IM_DI_RTNR_SAD_OFFSET_VADDR                     	(0xb80241c8)
#define  DI_IM_DI_RTNR_EDIFF_TH_VADDR                       	(0xb80241cc)
#define  DI_IM_DI_RTNR_EDIFF_SOBEL_TH_VADDR                 	(0xb80241d0)
#define  DI_IM_DI_RTNR_LEVEL_BOUND_VADDR                    	(0xb80241d4)
#define  DI_IM_DI_RTNR_ET_COUNT_Y_VADDR                     	(0xb80241d8)
#define  DI_IM_DI_RTNR_ET_SUM_Y_VADDR                       	(0xb80241dc)
#define  DI_IM_DI_RTNR_ET_SUM_U_VADDR                       	(0xb80241e0)
#define  DI_IM_DI_RTNR_ET_SUM_V_VADDR                       	(0xb80241e4)
#define  DI_IM_DI_TNR_XC_CONTROL_VADDR                      	(0xb80241e8)
#define  DI_IM_DI_HFD_CONTROL_VADDR                         	(0xb80241ec)
#define  DI_IM_DI_HFD_LINE_MOTION_COUNT_VADDR               	(0xb80241f0)
#define  DI_IM_DI_HFD_STATISTIC_VADDR                       	(0xb80241f4)
#define  DI_IM_DI_HFD_MA_ERROR_RECOVERY_VADDR               	(0xb80241f8)
#define  DI_IM_DI_NEW_INTRA_LOW_ANGLE_VADDR                 	(0xb80241fc)
#define  DI_IM_DI_INTRA_NEW_GRADIENT_CORRECT_VADDR          	(0xb8024200)
#define  DI_IM_DI_INTRA_POST_PROCESS_VADDR                  	(0xb8024204)
#define  DI_IM_DI_BTR_CONTROL_VADDR                         	(0xb8024208)
#define  DI_IM_DI_BTR_SOLA_METHOD0_MIN_MAX_VADDR            	(0xb802420c)
#define  DI_IM_DI_BTR_LONGWEAVE_STATISTIC_VADDR             	(0xb8024210)
#define  DI_IM_DI_BER_LOWPASS_STATISTIC_VADDR               	(0xb8024214)
#define  DI_IM_DI_BER_SPATIAL_CONTROL_VADDR                 	(0xb8024218)
#define  DI_IM_DI_BER_SPATIAL_DIFFY_VADDR                   	(0xb802421c)
#define  DI_IM_DI_BER_TEMPORAL_CONTROL_VADDR                	(0xb8024220)
#define  DI_IM_DI_INTRA_L_CROSS_PAT_DET_TH1_VADDR           	(0xb8024224)
#define  DI_IM_DI_INTRA_L_CROSS_PAT_DET_TH2_VADDR           	(0xb8024228)
#define  DI_IM_DI_INTRA_L_CROSS_PAT_DET_CTL_VADDR           	(0xb802422c)
#define  DI_NOISEEST_HOR_RANGE_VADDR                        	(0xb8024230)
#define  DI_NOISEEST_VER_RANGE_VADDR                        	(0xb8024234)
#define  DI_IM_DI_DUMMY_3_VADDR                             	(0xb8024238)
#define  DI_IM_DI_DUMMY_4_VADDR                             	(0xb802423c)
#define  DI_MPEG_HIST_BLKING_VADDR                          	(0xb8024240)
#define  DI_CNTVER0_VADDR                                   	(0xb8024244)
#define  DI_CNTVER2_VADDR                                   	(0xb8024248)
#define  DI_CNTVER4_VADDR                                   	(0xb802424c)
#define  DI_CNTVER6_VADDR                                   	(0xb8024250)
#define  DI_MPEGNR1_VADDR                                   	(0xb8024254)
#define  DI_IM_DI_PIB_CONTROL_VADDR                         	(0xb8024260)
#define  DI_IM_DI_PIB_ALL_CEN_TH_VADDR                      	(0xb8024264)
#define  DI_IM_DI_PIB_H_V_TH_VADDR                          	(0xb8024268)
#define  DI_IM_DI_PIB_H00_H11_TH_VADDR                      	(0xb802426c)
#define  DI_IM_DI_FILM_MASK_DETECTION_VADDR                 	(0xb8024270)
#define  DI_IM_DI_FILM_EDGE_TYPE_CHECK_VADDR                	(0xb8024274)
#define  DI_IM_DI_HMC_3A_VADDR                              	(0xb8024280)
#define  DI_IM_DI_HMC_STATISTIC_TH_VADDR                    	(0xb8024284)
#define  DI_IM_DI_HMC_STATISTIC1_VADDR                      	(0xb8024288)
#define  DI_IM_DI_HMC_STATISTIC2_VADDR                      	(0xb802428c)
#define  DI_IM_DI_HMC_STATISTIC3_VADDR                      	(0xb8024290)
#define  DI_IM_DI_LSB_RTNR_VADDR                            	(0xb8024294)
#define  DI_IM_DI_FRAMESOBEL_STATISTIC_CTRL_VADDR           	(0xb8024298)
#define  DI_IM_DI_FRAMESOBEL_STATISTIC_VADDR                	(0xb802429c)
#define  DI_TNRXC_MKII_CTRL_VADDR                           	(0xb80242a0)
#define  DI_IM_DI_RTNR_K_DARK_VADDR                         	(0xb80242a4)
#define  DI_IM_DI_RTNR_REFINED_CTRL_VADDR                   	(0xb80242a8)
#define  DI_IM_DI_RTNR_REFINED_CTRL2_VADDR                  	(0xb80242ac)
#define  DI_IM_DI_RTNR_EDIFF_ENABLE_C_VADDR                 	(0xb80242c4)
#define  DI_IM_DI_RTNR_EDIFF_ENABLE_VADDR                   	(0xb80242c8)
#define  DI_IM_DI_RTNR_HMCNR_VADDR                          	(0xb80242cc)
#define  DI_IM_DI_RTNR_NEW_CONTROL_VADDR                    	(0xb80242d0)
#define  DI_IM_DI_RTNR_NEW_SOBEL_TH_VADDR                   	(0xb80242d4)
#define  DI_IM_DI_RTNR_NEW_SAD_EDGE_TH_1_VADDR              	(0xb80242d8)
#define  DI_IM_DI_RTNR_NEW_SAD_EDGE_TH_2_VADDR              	(0xb80242dc)
#define  DI_IM_DI_RTNR_NEW_SAD_NONEDGE_TH_1_VADDR           	(0xb80242e0)
#define  DI_IM_DI_RTNR_NEW_SAD_NONEDGE_TH_2_VADDR           	(0xb80242e4)
#define  DI_IM_DI_RTNR_NEW_SAD_COUNT_TH_VADDR               	(0xb80242e8)
#define  DI_IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_1_VADDR          	(0xb80242ec)
#define  DI_IM_DI_RTNR_NEW_EDGETYPEDIFF_TH_2_VADDR          	(0xb80242f0)
#define  DI_IM_DI_RTNR_NEW_SNR_CONTROL_VADDR                	(0xb80242f4)
#define  DI_IM_DI_RTNR_NEW_SNR_TH_1_VADDR                   	(0xb80242f8)
#define  DI_IM_DI_RTNR_NEW_SNR_TH2_VADDR                    	(0xb80242fc)
#define  DI_IM_DI_RTNR_NEW_K_00_VADDR                       	(0xb8024300)
#define  DI_IM_DI_RTNR_NEW_K_10_VADDR                       	(0xb8024304)
#define  DI_IM_DI_RTNR_NEW_K_20_VADDR                       	(0xb8024308)
#define  DI_IM_DI_RTNR_NEW_K_30_VADDR                       	(0xb802430c)
#define  DI_IM_DI_RTNR_NEW_K_40_VADDR                       	(0xb8024310)
#define  DI_IM_DI_RTNR_NEW_K_50_VADDR                       	(0xb8024314)
#define  DI_IM_DI_RTNR_NEW_K_60_VADDR                       	(0xb8024318)
#define  DI_IM_DI_RTNR_NEW_K_70_VADDR                       	(0xb802431c)
#define  DI_IM_DI_RTNR_NEW_MASK1_CTRL1_VADDR                	(0xb8024320)
#define  DI_IM_DI_RTNR_NEW_MASK1_CTRL2_VADDR                	(0xb8024324)
#define  DI_IM_DI_RTNR_NEW_MASK2_CTRL1_VADDR                	(0xb8024328)
#define  DI_IM_DI_RTNR_NEW_MASK2_CTRL2_VADDR                	(0xb802432c)
#define  DI_IM_DI_INTRA_HFD_VADDR                           	(0xb8024330)
#define  DI_IM_DI_BLENDING_CORRECTOR_1_VADDR                	(0xb8024344)
#define  DI_IM_DI_BLENDING_CORRECTOR_2_VADDR                	(0xb8024348)
#define  DI_IM_DI_BLENDING_CORRECTOR_3_VADDR                	(0xb802434c)
#define  DI_IM_DI_BLENDING_CORRECTOR_4_VADDR                	(0xb8024350)
#define  DI_IM_DI_PAN_DETECTION_CONTROL_1_VADDR             	(0xb8024354)
#define  DI_IM_DI_PAN_DETECTION_CONTROL_2_VADDR             	(0xb8024358)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_1_VADDR           	(0xb802435c)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_2_VADDR           	(0xb8024360)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_3_VADDR           	(0xb8024364)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_4_VADDR           	(0xb8024368)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_5_VADDR           	(0xb802436c)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_6_VADDR           	(0xb8024370)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_7_VADDR           	(0xb8024374)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_8_VADDR           	(0xb8024378)
#define  DI_IM_DI_PAN_DETECTION_CONTROL_3_VADDR             	(0xb802437c)
#define  DI_IM_DI_FILM_NEW_FUNCTION_MAIN_VADDR              	(0xb8024380)
#define  DI_IM_DI_FILM_TOPBOTLINE1_VADDR                    	(0xb8024384)
#define  DI_IM_DI_FILM_TOPBOTLINE2_VADDR                    	(0xb8024388)
#define  DI_IM_DI_FILM_TOPBOTLINE3_VADDR                    	(0xb802438c)
#define  DI_IM_DI_FILM_PREV_FIELDMOTION_VADDR               	(0xb8024390)
#define  DI_IM_DI_FILM_MARK_INFORMATION_VADDR               	(0xb8024394)
#define  DI_IM_DI_FILM_MARK_PREV1_VADDR                     	(0xb8024398)
#define  DI_IM_DI_FILM_MARK_PREV2_VADDR                     	(0xb802439c)
#define  DI_IM_DI_FILM_MARK_PREV3_VADDR                     	(0xb80243a0)
#define  DI_IM_DI_FILM_MARK_NEXT1_VADDR                     	(0xb80243a4)
#define  DI_IM_DI_FILM_MARK_NEXT2_VADDR                     	(0xb80243a8)
#define  DI_IM_DI_FILM_MARK_NEXT3_VADDR                     	(0xb80243ac)
#define  DI_DI_SMD_CONTROL_CANDIDATELIST_VADDR              	(0xb80243b0)
#define  DI_DI_SMD_CHOOSECANDIDATE_VADDR                    	(0xb80243b4)
#define  DI_DI_SMD_REFINEMV1_VADDR                          	(0xb80243b8)
#define  DI_DI_SMD_REFINEMV2_VADDR                          	(0xb80243bc)
#define  DI_DI_SMD_REFINEMV3_VADDR                          	(0xb80243c0)
#define  DI_DI_SMD_PANNING1_VADDR                           	(0xb80243c4)
#define  DI_DI_SMD_FINAL_ADJUSTMENT1_VADDR                  	(0xb80243c8)
#define  DI_DI_SMD_FINAL_ADJUSTMENT2_VADDR                  	(0xb80243cc)
#define  DI_DI_SMD_COMPENSATE_VADDR                         	(0xb80243d0)
#define  DI_IM_DI_RTNR_SC_VADDR                             	(0xb80243d4)
#define  DI_IM_DI_RTNR_Y_16_TH0_TH3_VADDR                   	(0xb80243d8)
#define  DI_IM_DI_RTNR_Y_16_TH4_TH7_VADDR                   	(0xb80243dc)
#define  DI_IM_DI_RTNR_Y_16_TH8_TH11_VADDR                  	(0xb80243e0)
#define  DI_IM_DI_RTNR_Y_16_TH12_TH14_VADDR                 	(0xb80243e4)
#define  DI_IM_DI_RTNR_C_TH0_TH3_VADDR                      	(0xb80243e8)
#define  DI_IM_DI_RTNR_C_TH4_TH6_VADDR                      	(0xb80243ec)
#define  DI_IM_DI_RTNR_Y_16_K0_K7_VADDR                     	(0xb80243f0)
#define  DI_IM_DI_RTNR_Y_16_K8_K15_VADDR                    	(0xb80243f4)
#define  DI_IM_DI_RTNR_C_K_VADDR                            	(0xb80243f8)
#define  DI_DI_DATMEMORYSTARTADD1_VADDR                     	(0xb8024400)
#define  DI_DI_DATMEMORYSTARTADD2_VADDR                     	(0xb8024404)
#define  DI_DI_DATMEMORYSTARTADD3_VADDR                     	(0xb8024408)
#define  DI_DI_DATMEMORYSTARTADD4_VADDR                     	(0xb802440c)
#define  DI_DI_INFMEMORYSTARTADD1_VADDR                     	(0xb8024410)
#define  DI_DI_INFMEMORYSTARTADD2_VADDR                     	(0xb8024414)
#define  DI_DDR_RDATDMA_WTLENNUM_VADDR                      	(0xb8024418)
#define  DI_DDR_WDATDMA_WTLENNUM_VADDR                      	(0xb802441c)
#define  DI_DDR_DATDMA_RM_VADDR                             	(0xb8024420)
#define  DI_DDR_RINFDMA_WTLENNUM_VADDR                      	(0xb8024424)
#define  DI_DDR_WINFDMA_WTLENNUM_VADDR                      	(0xb8024428)
#define  DI_DDR_INFDMA_RM_VADDR                             	(0xb802442c)
#define  DI_DDR_DMASTATUS_VADDR                             	(0xb8024430)
#define  DI_DDR_WDE_VADDR                                   	(0xb8024434)
#define  DI_DI1_WRRD_BOUNDARYADDR1_VADDR                    	(0xb8024438)
#define  DI_DI1_WRRD_BOUNDARYADDR2_VADDR                    	(0xb802443c)
#define  DI_DI1_WRRD_BOUNDARYADD_STATUS_VADDR               	(0xb8024440)
#define  DI_DI_DATMEMORYSTARTADD1_3D_VADDR                  	(0xb8024444)
#define  DI_DI_DATMEMORYSTARTADD2_3D_VADDR                  	(0xb8024448)
#define  DI_DI_DATMEMORYSTARTADD3_3D_VADDR                  	(0xb802444c)
#define  DI_DI_DATMEMORYSTARTADD4_3D_VADDR                  	(0xb8024450)
#define  DI_DI_INFMEMORYSTARTADD1_3D_VADDR                  	(0xb8024454)
#define  DI_DI_INFMEMORYSTARTADD2_3D_VADDR                  	(0xb8024458)
#define  DI_DI_LINE_BASE_DMA_ADDR_L_VADDR                   	(0xb802445c)
#define  DI_DI_LINE_BASE_DMA_ADDR_R_VADDR                   	(0xb8024460)
#define  DI_DI_DMA_MULTI_REQ_NUM_VADDR                      	(0xb8024464)
#define  DI_DISPI_BIST_FAIL_SEPARATE_1_VADDR                	(0xb8024470)
#define  DI_DISPI_BIST_FAIL_SEPARATE_2_VADDR                	(0xb8024474)
#define  DI_DISPI_DRF_FAIL_SEPARATE_1_VADDR                 	(0xb8024478)
#define  DI_DISPI_DRF_FAIL_SEPARATE_2_VADDR                 	(0xb802447c)
#define  DI_DISPI_BIST_RME_VADDR                            	(0xb8024480)
#define  DI_DISPI_BIST_RM_1_VADDR                           	(0xb8024484)
#define  DI_DISPI_BIST_RM_2_VADDR                           	(0xb8024488)
#define  DI_DISPI_BIST_LS_VADDR                             	(0xb802448c)
#define  DI_DB_REG_CTL_VADDR                                	(0xb8024490)
#define  DI_SM_TOG_TG_0_VADDR                               	(0xb8024498)
#define  DI_SM_TOG_TG_1_VADDR                               	(0xb802449c)
#define  DI_CCDINR_DBG_MUX_VADDR                            	(0xb8024494)
#define  DI_DI_SMD_DUMMY_VADDR                              	(0xb8024540)
#define  DI_DI_SMD_SADHISBINA_VADDR                         	(0xb8024544)
#define  DI_DI_SMD_SADHISBINB_VADDR                         	(0xb8024548)
#define  DI_DI_SMD_SADHISBINC_VADDR                         	(0xb802454c)
#define  DI_DI_SMD_SADHISBIND_VADDR                         	(0xb8024550)
#define  DI_DI_SMD_SADHISBINE_VADDR                         	(0xb8024554)
#define  DI_DI_SMD_SADHISBINF_VADDR                         	(0xb8024558)
#define  DI_DI_SMD_SADHISBING_VADDR                         	(0xb802455c)
#define  DI_DI_SMD_SADHISBINH_VADDR                         	(0xb8024560)
#define  DI_DI_SMD_GMVCOEFF1_VADDR                          	(0xb8024564)
#define  DI_DI_SMD_GMVCOEFF2_VADDR                          	(0xb8024568)
#define  DI_DI_SMD_GMVCOEFF3_VADDR                          	(0xb802456c)
#define  DI_DI_SMD_PAN1_VADDR                               	(0xb8024570)
#define  DI_DI_SMD_PAN2_VADDR                               	(0xb8024574)
#define  DI_DI_SMD_PAN3_VADDR                               	(0xb8024578)
#define  DI_DI_SMD_ADDITIONALCOEFF1_VADDR                   	(0xb802457c)
#define  DI_DI_SMD_ADDITIONALCOEFF2_VADDR                   	(0xb8024580)
#define  DI_DI_SMD_ADDITIONALCOEFF3_VADDR                   	(0xb8024584)
#define  DI_DI_SMD_V4HIGHFREQ_VADDR                         	(0xb802458c)
#define  DI_IM_DI_ZOOMMOTION_DETECTOR_VADDR                 	(0xb8024590)
#define  DI_IM_DI_ZOOMMOTION_DET_02_VADDR                   	(0xb8024594)
#define  DI_IM_DI_ZOOMMOTION_DET_03_VADDR                   	(0xb8024598)
#define  DI_IM_DI_ZOOMMOTION_DET_04_VADDR                   	(0xb802459c)
#define  DI_IM_DI_ZOOMMOTION_DET_05_VADDR                   	(0xb80245a0)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_01_VADDR              	(0xb80245a4)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_02_VADDR              	(0xb80245a8)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_03_VADDR              	(0xb80245ac)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_04_VADDR              	(0xb80245b0)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_05_VADDR              	(0xb80245b4)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_06_VADDR              	(0xb80245b8)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_07_VADDR              	(0xb80245bc)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_08_VADDR              	(0xb80245c0)
#define  DI_IM_DI_ZOOMMOTION_DET_INFO_09_VADDR              	(0xb80245c4)
#define  DI_IM_DI_ZOOMMOTION_DET_FM_TH_A_VADDR              	(0xb80245c8)
#define  DI_IM_DI_ZOOMMOTION_DET_FM_TH_B_VADDR              	(0xb80245cc)
#define  DI_IM_DI_ZOOMMOTION_DET_FM_TH_C_VADDR              	(0xb80245d0)
#define  DI_IM_DI_SLOWMOTION_DETECTOR_1_VADDR               	(0xb80245d4)
#define  DI_IM_DI_SLOWMOTION_DETECTOR_2_VADDR               	(0xb80245d8)
#define  DI_IM_DI_SLOWMOTION_DET_FM_TH_A_VADDR              	(0xb80245dc)
#define  DI_IM_DI_SLOWMOTION_DET_FM_TH_B_VADDR              	(0xb80245e0)
#define  DI_IM_DI_SLOWMOTION_DET_FM_TH_C_VADDR              	(0xb80245e4)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_9_VADDR           	(0xb80245e8)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_10_VADDR          	(0xb80245ec)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_11_VADDR          	(0xb80245f0)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_12_VADDR          	(0xb80245f4)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_13_VADDR          	(0xb80245f8)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_14_VADDR          	(0xb80245fc)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_15_VADDR          	(0xb8024600)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_16_VADDR          	(0xb8024604)
#define  DI_IM_DI_PAN_DETECTION_STATISTIC_17_VADDR          	(0xb8024608)
#define  DI_DI_GST_CTRL_VADDR                               	(0xb802460c)
#define  DI_DI_GST_ENTER_ORIGSADCHECK_VADDR                 	(0xb8024610)
#define  DI_DI_GST_OUTOFRANGECHECK_VADDR                    	(0xb8024614)
#define  DI_DI_GST_FREQNONMATCHCHECK_VADDR                  	(0xb8024618)
#define  DI_DI_SMD_CANDIDATELIMITSAD_VADDR                  	(0xb802461c)
#define  DI_DI_GST_FMVHISA_VADDR                            	(0xb8024620)
#define  DI_DI_GST_FMVHISB_VADDR                            	(0xb8024624)
#define  DI_DI_GST_FMVHISC_VADDR                            	(0xb8024628)
#define  DI_DI_GST_FMVHISD_VADDR                            	(0xb802462c)
#define  DI_DI_GST_FMVHISE_VADDR                            	(0xb8024630)
#define  DI_DI_GST_FMVHISF_VADDR                            	(0xb8024634)
#define  DI_DI_GST_FMVHISG_VADDR                            	(0xb8024638)
#define  DI_DI_GST_FMVHISH_VADDR                            	(0xb802463c)
#define  DI_DI_GST_FMVHISI_VADDR                            	(0xb8024640)
#define  DI_DI_GST_FMVHISJ_VADDR                            	(0xb8024644)
#define  DI_DI_GST_FMVHISK_VADDR                            	(0xb8024648)
#define  DI_IM_DI_HMC_ADJUSTABLE_VADDR                      	(0xb802464c)
#define  DI_IM_DI_HMC_ADJUSTABLE2_VADDR                     	(0xb8024650)
#define  DI_IM_DI_HMC_ADJUSTABLE3_VADDR                     	(0xb8024654)
#define  DI_IM_DI_HMC_ADJUSTABLE4_VADDR                     	(0xb8024658)
#define  DI_IM_DI_SC_ADJUSTMENT_VADDR                       	(0xb802465c)
#define  DI_IM_DI_HMC_PAN_CONTROL_VADDR                     	(0xb8024660)
#define  DI_IM_DI_HMC_PAN_ADD_BIAS_VADDR                    	(0xb8024664)
#define  DI_IM_DI_HMC_PAN_CONTROL_PAR_1_VADDR               	(0xb8024668)
#define  DI_IM_DI_HMC_PAN_CONTROL_PAR_2_VADDR               	(0xb802466c)
#define  DI_IM_DI_HMC_PAN_VERTICAL_INTRA_1_VADDR            	(0xb8024670)
#define  DI_IM_DI_HMC_PAN_VERTICAL_INTRA_2_VADDR            	(0xb8024674)
#define  DI_IM_DI_HMC_PAN_VERTICAL_INTRA_3_VADDR            	(0xb8024678)
#define  DI_IM_DI_HMC_PAN_DUMMY_1_VADDR                     	(0xb802467c)
#define  DI_IM_DI_HMC_PAN_DUMMY_2_VADDR                     	(0xb8024680)
#define  DI_IM_DI_HMC_PAN_DUMMY_3_VADDR                     	(0xb8024684)
#define  DI_RTNR_MA_SNR_CONTROL_VADDR                       	(0xb8024688)
#define  DI_RTNR_MA_SNR_MOTION_TH_LOW_VADDR                 	(0xb802468c)
#define  DI_RTNR_MA_SNR_MOTION_TH_HIGH_VADDR                	(0xb8024690)
#define  DI_RTNR_MA_SNR_MOTION_EDGE_TH_VADDR                	(0xb8024694)
#define  DI_RTNR_MA_SNR_MOTION_TH_SLOPE_VADDR               	(0xb8024698)
#define  DI_RTNR_MA_SNR_STRENGTH_CONTROL_VADDR              	(0xb802469c)
#define  DI_DI_RTNR_NM_CONTROL_VADDR                        	(0xb8024700)
#define  DI_DI_RTNR_NM_VARMEAN_CONTROL_VADDR                	(0xb8024704)
#define  DI_DI_RTNR_NM_VAR_THD_VADDR                        	(0xb8024708)
#define  DI_DI_RTNR_NM_MARGIN0_VADDR                        	(0xb802470c)
#define  DI_DI_RTNR_NM_MARGIN1_VADDR                        	(0xb8024710)
#define  DI_DI_RTNR_NM_NOISELEVEL_TH0_VADDR                 	(0xb8024714)
#define  DI_DI_RTNR_NM_NOISELEVEL_TH1_VADDR                 	(0xb8024718)
#define  DI_DI_RTNR_NM_NOISELEVEL_TH2_VADDR                 	(0xb802471c)
#define  DI_DI_RTNR_NM_NOISELEVEL_TH3_VADDR                 	(0xb8024720)
#define  DI_DI_RTNR_NM_INFOR1_VADDR                         	(0xb8024724)
#define  DI_DI_RTNR_NM_INFOR2_VADDR                         	(0xb8024728)
#define  DI_DI_RTNR_NM_HIST1_0_VADDR                        	(0xb8024730)
#define  DI_DI_RTNR_NM_HIST1_1_VADDR                        	(0xb8024734)
#define  DI_DI_RTNR_NM_HIST1_2_VADDR                        	(0xb8024738)
#define  DI_DI_RTNR_NM_HIST1_3_VADDR                        	(0xb802473c)
#define  DI_DI_RTNR_NM_HIST1_4_VADDR                        	(0xb8024740)
#define  DI_DI_RTNR_NM_HIST1_5_VADDR                        	(0xb8024744)
#define  DI_DI_RTNR_NM_HIST1_6_VADDR                        	(0xb8024748)
#define  DI_DI_RTNR_NM_HIST1_7_VADDR                        	(0xb802474c)
#define  DI_DI_RTNR_NM_HIST1_8_VADDR                        	(0xb8024750)
#define  DI_DI_RTNR_NM_HIST1_9_VADDR                        	(0xb8024754)
#define  DI_DI_RTNR_NM_HIST1_10_VADDR                       	(0xb8024758)
#define  DI_DI_RTNR_NM_HIST1_11_VADDR                       	(0xb802475c)
#define  DI_DI_RTNR_NM_HIST1_12_VADDR                       	(0xb8024760)
#define  DI_DI_RTNR_NM_HIST1_13_VADDR                       	(0xb8024764)
#define  DI_DI_RTNR_NM_HIST1_14_VADDR                       	(0xb8024768)
#define  DI_DI_RTNR_NM_HIST1_15_VADDR                       	(0xb802476c)
#define  DI_DI_RTNR_NM_HIST2_0_VADDR                        	(0xb8024770)
#define  DI_DI_RTNR_NM_HIST2_1_VADDR                        	(0xb8024774)
#define  DI_DI_RTNR_NM_HIST2_2_VADDR                        	(0xb8024778)
#define  DI_DI_RTNR_NM_HIST2_3_VADDR                        	(0xb802477c)
#define  DI_DI_RTNR_NM_HIST2_4_VADDR                        	(0xb8024780)
#define  DI_DI_RTNR_NM_HIST2_5_VADDR                        	(0xb8024784)
#define  DI_DI_RTNR_NM_HIST2_6_VADDR                        	(0xb8024788)
#define  DI_DI_RTNR_NM_HIST2_7_VADDR                        	(0xb802478c)
#define  DI_DI_RTNR_NM_HIST2_8_VADDR                        	(0xb8024790)
#define  DI_DI_RTNR_NM_HIST2_9_VADDR                        	(0xb8024794)
#define  DI_DI_RTNR_NM_HIST2_10_VADDR                       	(0xb8024798)
#define  DI_DI_RTNR_NM_HIST2_11_VADDR                       	(0xb802479c)
#define  DI_DI_RTNR_NM_HIST2_12_VADDR                       	(0xb80247a0)
#define  DI_DI_RTNR_NM_HIST2_13_VADDR                       	(0xb80247a4)
#define  DI_DI_RTNR_NM_HIST2_14_VADDR                       	(0xb80247a8)
#define  DI_DI_RTNR_NM_HIST2_15_VADDR                       	(0xb80247ac)
#define  DI_DI_RTNR_NM_HIST2VAR_0_VADDR                     	(0xb80247b0)
#define  DI_DI_RTNR_NM_HIST2VAR_1_VADDR                     	(0xb80247b4)
#define  DI_DI_RTNR_NM_HIST2VAR_2_VADDR                     	(0xb80247b8)
#define  DI_DI_RTNR_NM_HIST2VAR_3_VADDR                     	(0xb80247bc)
#define  DI_DI_RTNR_NM_HIST2VAR_4_VADDR                     	(0xb80247c0)
#define  DI_DI_RTNR_NM_HIST2VAR_5_VADDR                     	(0xb80247c4)
#define  DI_DI_RTNR_NM_HIST2VAR_6_VADDR                     	(0xb80247c8)
#define  DI_DI_RTNR_NM_HIST2VAR_7_VADDR                     	(0xb80247cc)
#define  DI_DI_RTNR_NM_HIST2VAR_8_VADDR                     	(0xb80247d0)
#define  DI_DI_RTNR_NM_HIST2VAR_9_VADDR                     	(0xb80247d4)
#define  DI_DI_RTNR_NM_HIST2VAR_10_VADDR                    	(0xb80247d8)
#define  DI_DI_RTNR_NM_HIST2VAR_11_VADDR                    	(0xb80247dc)
#define  DI_DI_RTNR_NM_HIST2VAR_12_VADDR                    	(0xb80247e0)
#define  DI_DI_RTNR_NM_HIST2VAR_13_VADDR                    	(0xb80247e4)
#define  DI_DI_RTNR_NM_HIST2VAR_14_VADDR                    	(0xb80247e8)
#define  DI_DI_RTNR_NM_HIST2VAR_15_VADDR                    	(0xb80247ec)
#define  DI_RTNR_OUTPUT_CLAMP_VADDR                         	(0xb8024800)
#define  DI_DI_SMD_WATERFLAG_CTR1_VADDR                     	(0xb8024804)
#define  DI_DI_SMD_WATERFLAG_CTR2_VADDR                     	(0xb8024808)
#define  DI_DI_SMD_WATERFLAG_CTR3_VADDR                     	(0xb802480c)
#define  DI_DI_SMD_HARDWAREPAN_MODIFY1_VADDR                	(0xb8024810)
#define  DI_DI_SMD_SAMPLING_GMVC_VADDR                      	(0xb8024814)
#define  DI_DI_SMD_SAMPLING_GMVB_VADDR                      	(0xb8024818)
#define  DI_DI_GST_COMPENSATE_VADDR                         	(0xb802481c)
#define  DI_DI_GST_MAXFMV_PART1_VADDR                       	(0xb8024820)
#define  DI_DI_GST_MAXFMV_PART2_VADDR                       	(0xb8024824)
#define  DI_DI_GST_MAXFMV_PART3_VADDR                       	(0xb8024828)
#define  DI_DI_GST_MAXFMV_PART4_VADDR                       	(0xb802482c)
#define  DI_DI_GST_FMV_PAN_COEFF1_VADDR                     	(0xb8024830)
#define  DI_DI_GST_FMV_PAN_COEFF2_VADDR                     	(0xb8024834)
#define  DI_DI_MA_WEAVEMODE_CHECK_VADDR                     	(0xb8024840)
#define  DI_IM_DI_RTNR_HMCNR_STATISTIC_1_VADDR              	(0xb8024844)
#define  DI_IM_DI_RTNR_HMCNR_STATISTIC_2_VADDR              	(0xb8024848)
#define  DI_IM_DI_RTNR_HMCNR_STATISTIC_3_VADDR              	(0xb802484c)
#define  DI_IM_DI_RTNR_HMCNR_STATISTIC_4_VADDR              	(0xb8024850)
#define  DI_IM_DI_RTNR_HMCNR_STATISTIC_5_VADDR              	(0xb8024854)
#define  DI_IM_DI_RTNR_HMCNR_STATISTIC_6_VADDR              	(0xb8024858)
#define  DI_IM_DI_RTNR_MAD_Y_TH2_C_TH2_VADDR                	(0xb802485c)
#define  DI_IM_DI_RTNR_MAD_Y_COUNTER_2_VADDR                	(0xb8024860)
#define  DI_IM_DI_RTNR_MAD_Y_COUNTER_3_VADDR                	(0xb8024864)
#define  DI_IM_DI_RTNR_MAD_U_COUNTER_2_VADDR                	(0xb8024868)
#define  DI_IM_DI_RTNR_MAD_U_COUNTER_3_VADDR                	(0xb802486c)
#define  DI_IM_DI_RTNR_MAD_V_COUNTER_2_VADDR                	(0xb8024870)
#define  DI_IM_DI_RTNR_MAD_V_COUNTER_3_VADDR                	(0xb8024874)
#define  DI_MEMC_P_FILM_CTRL0_VADDR                         	(0xb8024878)
#define  DI_MEMC_P_FILM_FR_NUM_CHK_VADDR                    	(0xb802487c)
#define  DI_MEMC_P_FILM_CTRL1_VADDR                         	(0xb8024880)
#define  DI_MEMC_P_FILM_CTRL2_VADDR                         	(0xb8024884)
#define  DI_MEMC_P_FILM_READ_VADDR                          	(0xb8024888)
#define  DI_MEMC_P_FILM_READ1_VADDR                         	(0xb802488c)
#define  DI_MEMC_P_FILM_READ2_VADDR                         	(0xb8024890)
#define  DI_MEMC_P_FILM_READ3_VADDR                         	(0xb8024894)
#define  DI_MEMC_P_FILM_READ4_VADDR                         	(0xb8024898)
#define  DI_MEMC_P_FILM_CTRL3_VADDR                         	(0xb802489c)
#define  DI_MEMC_P_FILM_CTRL4_VADDR                         	(0xb80248a0)
#define  DI_IM_DI_RTNR_FADING_DETECTOR_VADDR                	(0xb80248b0)
#define  DI_IM_DI_RTNR_FADING_INFO_1_VADDR                  	(0xb80248b4)
#define  DI_IM_DI_RTNR_FADING_INFO_2_VADDR                  	(0xb80248b8)
#define  DI_IM_DI_RTNR_FADING_INFO_3_VADDR                  	(0xb80248bc)
#define  DI_IM_DI_RTNR_FADING_INFO_4_VADDR                  	(0xb80248c0)
#define  DI_IM_DI_RTNR_FADING_INFO_5_VADDR                  	(0xb80248c4)
#define  DI_IM_DI_RTNR_FADING_INFO_6_VADDR                  	(0xb80248c8)
#define  DI_IM_DI_MA_FADING_APPLY_BIAS_VADDR                	(0xb80248cc)
#define  DI_IM_DI_MA_NOISE_APPLY_BIAS_VADDR                 	(0xb80248d0)
#define  DI_IM_DI_MA_VHF_CTRL_VADDR                         	(0xb80248d4)
#define  DI_IM_DI_MA_VHF_CTRL2_VADDR                        	(0xb80248d8)
#define  DI_IM_DI_MA_VHF_CTRL3_VADDR                        	(0xb80248dc)
#define  DI_IM_DI_NINTRA_CONTROL_VADDR                      	(0xb80248e0)
#define  DI_IM_DI_NINTRA_LOWPASS_SOURCE_VADDR               	(0xb80248e4)
#define  DI_IM_DI_NINTRA_SEARCH_DIR_LIMIT_VADDR             	(0xb80248e8)
#define  DI_IM_DI_NINTRA_INTERSECTION_TH_VADDR              	(0xb80248ec)
#define  DI_IM_DI_NINTRA_1ST_2ND_YDIFF_TH_VADDR             	(0xb80248f0)
#define  DI_IM_DI_NINTRA_HIGH_FREQ_LIMIT_VADDR              	(0xb80248f4)
#define  DI_IM_DI_HMC_ME_REFINE_CTRL_1_VADDR                	(0xb8024900)
#define  DI_IM_DI_HMC_ME_REFINE_CTRL_2_VADDR                	(0xb8024904)
#define  DI_IM_DI_HMC_ME_REFINE_CTRL_3_VADDR                	(0xb8024908)
#define  DI_IM_DI_HMC_ME_REFINE_CTRL_4_VADDR                	(0xb802490c)
#define  DI_IM_DI_HMC_ME_REFINE_CTRL_5_VADDR                	(0xb8024910)
#define  DI_IM_NEW_MCNR_CONTROL_VADDR                       	(0xb8024914)
#define  DI_IM_NEW_MCNR_PAN_CONDITION_VADDR                 	(0xb8024918)
#define  DI_IM_NEW_MCNR_WEIGHTING_CONDITION_VADDR           	(0xb802491c)
#define  DI_IM_NEW_MCNR_CLAMPING_VALUE_VADDR                	(0xb8024920)
#define  DI_IM_DI_HME_LINE_STATISTIC_1_VADDR                	(0xb8024924)
#define  DI_IM_DI_HME_LINE_STATISTIC_2_VADDR                	(0xb8024928)
#define  DI_IM_DI_HME_LINE_STATISTIC_3_VADDR                	(0xb802492c)
#define  DI_IM_DI_HME_LINE_STATISTIC_4_VADDR                	(0xb8024930)
#define  DI_IM_DI_HME_LINE_STATISTIC_5_VADDR                	(0xb8024934)
#define  DI_IM_DI_HME_LINE_STATISTIC_6_VADDR                	(0xb8024938)
#define  DI_IM_DI_HME_LINE_STATISTIC_7_VADDR                	(0xb802493c)
#define  DI_IM_DI_HME_LINE_STATISTIC_8_VADDR                	(0xb8024940)
#define  DI_IM_DI_HME_LINE_STATISTIC_9_VADDR                	(0xb8024944)
#define  DI_DI_DDR_CHECKSUM_CTRL_VADDR                      	(0xb802494c)
#define  DI_DI_DDR_CHECKSUM_FLAG_0_VADDR                    	(0xb8024950)
#define  DI_DI_DDR_CHECKSUM_FLAG_1_VADDR                    	(0xb8024954)
#define  DI_DI_DDR_CHECKSUM_FLAG_2_VADDR                    	(0xb8024958)
#define  DI_DI_DDR_CHECKSUM_FLAG_3_VADDR                    	(0xb802495c)
#define  DI_DI_DDR_CHECKSUM_MASK_0_VADDR                    	(0xb8024960)
#define  DI_DI_DDR_CHECKSUM_MASK_1_VADDR                    	(0xb8024964)
#define  DI_DI_DDR_CHECKSUM_MASK_2_VADDR                    	(0xb8024968)
#define  DI_DI_DDR_CHECKSUM_MASK_3_VADDR                    	(0xb802496c)
#define  DI_IM_NEW_MCNR_CONTROL2_VADDR                      	(0xb8024970)
#define  DI_DI_SMD_WATERFLOW_TEETH_CTR_VADDR                	(0xb8024974)
#define  DI_DI_SMD_WATERFLOW_TEETH_COUNT_VADDR              	(0xb8024978)
#define  DI_DI_SMD_MA_MC_WEIGHT_CTR_VADDR                   	(0xb802497c)
#define  DI_DI_SMD_DIAG_EDGE_PROTECT_CTR_VADDR              	(0xb8024980)
#define  DI_DI_SMD_SLOW_MOTION_HANDLE1_VADDR                	(0xb8024984)
#define  DI_DI_SMD_SLOW_MOTION_HANDLE2_VADDR                	(0xb8024988)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_7_VADDR               	(0xb802498c)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_8_VADDR               	(0xb8024990)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_9_VADDR               	(0xb8024994)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_10_VADDR              	(0xb8024998)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_11_VADDR              	(0xb802499c)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_12_VADDR              	(0xb8024a00)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_13_VADDR              	(0xb8024a04)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_14_VADDR              	(0xb8024a08)
#define  DI_IM_DI_RTNR_MCNR_STATISTIC_15_VADDR              	(0xb8024a0c)
#define  DI_IM_NEW_MCNR_CONTROL3_VADDR                      	(0xb8024a10)
#define  DI_IM_NEW_MCNR_MV_MAD_OFFSET_VADDR                 	(0xb8024a14)
#define  DI_IM_DI_RTNR_K128_MODE_VADDR                      	(0xb8024a18)
#define  DI_IM_DI_RTNR_NEW_SAD_TH_3_VADDR                   	(0xb8024a1c)
#define  DI_IM_DI_RTNR_NEW_SAD_COUNT_TH_2_VADDR             	(0xb8024a20)
#define  DI_IM_DI_RTNR_NEW_STA_MOTION_TH_0_VADDR            	(0xb8024a24)
#define  DI_IM_DI_RTNR_NEW_STA_MOTION_TH_1_VADDR            	(0xb8024a28)
#define  DI_IM_DI_RTNR_NEW_STA_MOTION_TH_3_VADDR            	(0xb8024a2c)
#define  DI_IM_DI_RTNR_NEW_SAD_EDGE_SLOPE_0_4_VADDR         	(0xb8024a30)
#define  DI_IM_DI_RTNR_NEW_SAD_EDGE_SLOPE_4_8_VADDR         	(0xb8024a34)
#define  DI_IM_DI_RTNR_NEW_SAD_NONEDGE_SLOPE_0_4_VADDR      	(0xb8024a38)
#define  DI_IM_DI_RTNR_NEW_SAD_NONEDGE_SLOPE_4_8_VADDR      	(0xb8024a3c)
#define  DI_IM_DI_RTNR_NEW_STA_MOTION_SLOPE_0_4_VADDR       	(0xb8024a40)
#define  DI_IM_DI_RTNR_NEW_STA_MOTION_SLOPE_4_8_VADDR       	(0xb8024a44)
#define  DI_IM_DI_RTNR_NEW_K_80_VADDR                       	(0xb8024a48)
#define  DI_IM_DI_RTNR_NEW_K_REMAIN_0_VADDR                 	(0xb8024a4c)
#define  DI_IM_DI_RTNR_NEW_K_REMAIN_1_VADDR                 	(0xb8024a50)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======DI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sawtooth_choose:2;
        RBus_UInt32  film22_filter_andor:1;
        RBus_UInt32  ip_enable:1;
        RBus_UInt32  di444to422lowpass:1;
        RBus_UInt32  cp_tresultweight:3;
        RBus_UInt32  cp_temporalenable:1;
        RBus_UInt32  intra_lowangleenable:1;
        RBus_UInt32  intra_stage1enable:1;
        RBus_UInt32  intra_stage2enable:1;
        RBus_UInt32  intra_mfilterenable:1;
        RBus_UInt32  intra_interpolationrange:4;
        RBus_UInt32  film_enable:5;
        RBus_UInt32  dummy18024000_9:1;
        RBus_UInt32  ma_horicomen:1;
        RBus_UInt32  ma_stilllogoena:1;
        RBus_UInt32  ma_smoothintra90:1;
        RBus_UInt32  ma_messintra90:1;
        RBus_UInt32  ma_3aenable:1;
        RBus_UInt32  ma_controlmode:2;
        RBus_UInt32  ma_onedirectionweaveen:1;
        RBus_UInt32  ma_preferintra:1;
    };
}di_im_di_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fun_y_en:1;
        RBus_UInt32  y10bitsin:1;
        RBus_UInt32  c10bitsin:1;
        RBus_UInt32  game_mode_3a:1;
        RBus_UInt32  res1:10;
        RBus_UInt32  cr_fh_switch:1;
        RBus_UInt32  cr_autoimg_enable:1;
        RBus_UInt32  di_half_frame_en:1;
        RBus_UInt32  di_r_drop_odd_line:1;
        RBus_UInt32  di_l_drop_odd_line:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  dma_force_4buf:1;
        RBus_UInt32  framemotion_pxs_sel:1;
        RBus_UInt32  di_clock_gating_disable:1;
        RBus_UInt32  di_wrapper_en:1;
        RBus_UInt32  cp_bist_clkmux_en:1;
    };
}di_color_recovery_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  field_confuse:1;
        RBus_UInt32  di_3d_l_flag:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  readstart:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  unfreeze_polarity:1;
        RBus_UInt32  auto_frz_num:3;
        RBus_UInt32  auto_freeze:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  film_debugmode:1;
        RBus_UInt32  ma_debugmode:3;
        RBus_UInt32  ma_modeselect:1;
        RBus_UInt32  cp_tnrdebugmode:1;
    };
}di_im_di_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  singlefieldintra:1;
        RBus_UInt32  hsize:11;
        RBus_UInt32  vsize:10;
        RBus_UInt32  hblksize:10;
    };
}di_im_di_active_window_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fixedwindowmode:2;
        RBus_UInt32  ccdinr_memshare_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  boundary_inter_mode:1;
        RBus_UInt32  hsize_msb:2;
        RBus_UInt32  vsize_msb:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  hblksize_msb:1;
        RBus_UInt32  freeze:1;
        RBus_UInt32  force2d:1;
        RBus_UInt32  res3:11;
        RBus_UInt32  delpixelen:1;
        RBus_UInt32  dellineen:1;
        RBus_UInt32  fixedwindow5:1;
        RBus_UInt32  fixedwindow4:1;
        RBus_UInt32  fixedwindow3:1;
        RBus_UInt32  fixedwindow2:1;
        RBus_UInt32  fixedwindow1:1;
        RBus_UInt32  fixedwindow0:1;
    };
}di_im_di_weave_window_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_12_0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xstart_12_0:13;
    };
}di_im_di_weave_window_0_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_12_0:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xend_12_0:13;
    };
}di_im_di_weave_window_0_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_25_13:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xstart_25_13:13;
    };
}di_im_di_weave_window_1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_25_13:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xend_25_13:13;
    };
}di_im_di_weave_window_1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_38_26:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xstart_38_26:13;
    };
}di_im_di_weave_window_2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_38_26:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xend_38_26:13;
    };
}di_im_di_weave_window_2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_51_39:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xstart_51_39:13;
    };
}di_im_di_weave_window_3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_51_39:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xend_51_39:13;
    };
}di_im_di_weave_window_3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_64_52:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xstart_64_52:13;
    };
}di_im_di_weave_window_4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_64_52:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xend_64_52:13;
    };
}di_im_di_weave_window_4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_77_65:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xstart_77_65:13;
    };
}di_im_di_weave_window_5_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_77_65:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  xend_77_65:13;
    };
}di_im_di_weave_window_5_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pseudo_memc_film22_sequence:2;
        RBus_UInt32  pseudo_memc_film22_weight0:2;
        RBus_UInt32  pseudo_memc_film22_weight1:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  ma_class_h_th1_cmp:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ma_class_h_th1:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  ma_class_h_th2:5;
    };
}di_im_di_classify_thclassify_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pseudo_memc_en:1;
        RBus_UInt32  dummy18024048_30:1;
        RBus_UInt32  pseudo_memc_film32_sequence:4;
        RBus_UInt32  pseudo_memc_film32_weight0:2;
        RBus_UInt32  pseudo_memc_film32_weight1:2;
        RBus_UInt32  pseudo_memc_film32_weight2:2;
        RBus_UInt32  pseudo_memc_film32_weight3:2;
        RBus_UInt32  ma_blend_fmcomb3:2;
        RBus_UInt32  ma_blend_fmcomb2:2;
        RBus_UInt32  ma_blend_fmcomb1_hor:2;
        RBus_UInt32  ma_blend_fmcomb1:2;
        RBus_UInt32  ma_blend_fmcomb0:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  ma_blend10_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ma_blend01_weight:3;
    };
}di_im_di_blend_and_weighting_method_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802404c_31:1;
        RBus_UInt32  ma_sobelthm:10;
        RBus_UInt32  ma_sobelths:10;
        RBus_UInt32  force_2d_timing_en:1;
        RBus_UInt32  force_2d_timing_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  vodma_film_en:1;
        RBus_UInt32  dummy1802404c_6_3:4;
        RBus_UInt32  force_di_nxt:1;
        RBus_UInt32  force_dma_intra:1;
        RBus_UInt32  force_dma_2d:1;
    };
}di_im_di_mpeg_sequence_app_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_vedge_nolp_en:3;
        RBus_UInt32  ma_class_s_th2:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ma_class_rlv_th1_cmp:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ma_class_rlv_th1:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ma_class_rlv_th2:5;
    };
}di_im_di_classify2_thclassify_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_new_class_en:1;
        RBus_UInt32  res1:25;
        RBus_UInt32  ma_vedge_add_rlv:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  ma_vedge_nonlpfm_en:1;
        RBus_UInt32  ma_vedge_force90_en:1;
        RBus_UInt32  ma_vedge_force_intra_en:1;
    };
}di_im_di_new_class_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_420_en:2;
        RBus_UInt32  rdma_random_en:1;
        RBus_UInt32  dma_422to444_boundary_duplicate:1;
        RBus_UInt32  dma_422to444_cr_dly_cb:1;
        RBus_UInt32  dma_422to444_duplicate:1;
        RBus_UInt32  dma_444to422_cr_dly_cb:1;
        RBus_UInt32  dma_444to422_drop:1;
        RBus_UInt32  dma_444to422_lowpass_boundary_duplicate:1;
        RBus_UInt32  linesize_even:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  linesize_odd:11;
    };
}di_im_di_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_var4thl:8;
        RBus_UInt32  cr_var3thl:8;
        RBus_UInt32  cr_var2thl:8;
        RBus_UInt32  cr_var1thl:8;
    };
}di_im_di_xc_auto_balance_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bcclowpassyenablecontrol:1;
        RBus_UInt32  autoimg_lpf_enable:1;
        RBus_UInt32  autoimg_debug_enable:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  cr_transitionthl:8;
        RBus_UInt32  cr_meanthl:8;
    };
}di_im_di_xc_auto_balance_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cr_thl_mainbalance:8;
        RBus_UInt32  cr_thl_subbalance:16;
    };
}di_im_di_xc_auto_balance_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  stilllinecntns_window_mode:1;
        RBus_UInt32  stilllinecntns_cond_th:2;
        RBus_UInt32  stilllinecntns_window_th:5;
        RBus_UInt32  stilllinecntns_window:3;
        RBus_UInt32  stilllinecntns_apply_hmc_window:1;
        RBus_UInt32  stillline_cntns_en:1;
        RBus_UInt32  intra_motionthly:8;
        RBus_UInt32  intra_motionthlc:8;
    };
}di_im_di_intra_sobel_motion_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_con1peakthly:8;
        RBus_UInt32  intra_con1peakthlc:8;
        RBus_UInt32  intra_con2interpolationthly:8;
        RBus_UInt32  intra_con3peakthly:8;
    };
}di_im_di_intra_line_cont_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  intra_mfilter_angle_range:2;
        RBus_UInt32  intra_mfilter_angle_enable:1;
        RBus_UInt32  intra_ma_mess_enable:1;
        RBus_UInt32  intra_con2interpolationthly_mess:8;
        RBus_UInt32  intra_mfilterthl:8;
        RBus_UInt32  intra_areaedgepixeldiffthly:8;
    };
}di_im_di_intra_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_framemtha:8;
        RBus_UInt32  ma_framehtha:8;
        RBus_UInt32  ma_framerlvtha:8;
        RBus_UInt32  ma_framestha:8;
    };
}di_im_di_ma_frame_motion_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_framemthb:8;
        RBus_UInt32  ma_framehthb:8;
        RBus_UInt32  ma_framerlvthb:8;
        RBus_UInt32  ma_framesthb:8;
    };
}di_im_di_ma_frame_motion_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_framemthc:8;
        RBus_UInt32  ma_framehthc:8;
        RBus_UInt32  ma_framerlvthc:8;
        RBus_UInt32  ma_framesthc:8;
    };
}di_im_di_ma_frame_motion_th_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_fieldteethstha:8;
        RBus_UInt32  ma_fieldteethmtha:8;
        RBus_UInt32  ma_fieldteethhtha:8;
        RBus_UInt32  ma_fieldteethrlvtha:8;
    };
}di_im_di_ma_field_teeth_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_horicomth:8;
        RBus_UInt32  ma_stilllogovdth:8;
        RBus_UInt32  ma_ydiffth:8;
        RBus_UInt32  ma_fieldteeththb:8;
    };
}di_im_di_ma_others_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_sawtoothmth:8;
        RBus_UInt32  ma_sawtoothhth:8;
        RBus_UInt32  ma_sawtoothrlvth:8;
        RBus_UInt32  ma_sawtoothsth:8;
    };
}di_im_di_ma_sawtooth_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_ma_vertext_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_leavequick_en:1;
        RBus_UInt32  film_verscrollingtext_en:1;
        RBus_UInt32  film_thumbnail_en:1;
        RBus_UInt32  film_pair1_en:1;
        RBus_UInt32  film_pair2_en:1;
        RBus_UInt32  film_pair_en_auto:1;
        RBus_UInt32  film_violate_strict_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  film22_sawtooththl:8;
        RBus_UInt32  film_sawtooththl:8;
        RBus_UInt32  film_frmotionthl:8;
    };
}di_im_di_film_sawtooth_filmframe_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_fieldmotionsumthl:8;
        RBus_UInt32  film22_fistaticsthl:8;
        RBus_UInt32  film_frstaticsthl:8;
        RBus_UInt32  film_fistaticsthl:8;
    };
}di_im_di_film_static_sum_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_pairratio_all1:4;
        RBus_UInt32  film_pairratio_all2:4;
        RBus_UInt32  film_fiminsthl:8;
        RBus_UInt32  film_fimaxsthl:16;
    };
}di_im_di_film_field_judge_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_subfieldmotionsumthl:8;
        RBus_UInt32  film22_subfistaticsthl:8;
        RBus_UInt32  film_subfrstaticsthl:8;
        RBus_UInt32  film_subfistaticsthl:8;
    };
}di_im_di_film_static_sum_sub_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_pairratio_sub1:4;
        RBus_UInt32  film_pairratio_sub2:4;
        RBus_UInt32  film_subfiminsthl:8;
        RBus_UInt32  film_subfimaxsthl:16;
    };
}di_im_di_film_field_judge_sub_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film22_debounce_fieldnum:4;
        RBus_UInt32  film32_debounce_fieldnum:4;
        RBus_UInt32  dummy180240b4_23_16:7;
        RBus_UInt32  nm_main_enable:1;
        RBus_UInt32  film22_subfieldmotionsumthl:8;
        RBus_UInt32  film22_fieldmotionsumthl:8;
    };
}di_im_di_film_motion_sum_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  film_bot_margin:4;
        RBus_UInt32  film_top_margin:4;
    };
}di_im_di_si_film_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_reserved_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_hifreq_thl:16;
        RBus_UInt32  film_hifreq_cnt_thl:4;
        RBus_UInt32  film_3d_mode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  film_motionstatus_choose:1;
        RBus_UInt32  film_hbcounter:8;
    };
}di_im_di_si_film_hb_cout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180240c4_31_9:23;
        RBus_UInt32  film_hifreq_flag:1;
        RBus_UInt32  film_detected:1;
        RBus_UInt32  film_subdetected:1;
        RBus_UInt32  film_confuse:1;
        RBus_UInt32  film_sequence:5;
    };
}di_im_di_si_film_final_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_framestatic:8;
        RBus_UInt32  film_framepair:16;
        RBus_UInt32  film_prefistatic1:8;
    };
}di_im_di_si_film_pattern_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_nxtfistatic1:8;
        RBus_UInt32  film_prefistatic2:8;
        RBus_UInt32  film_nxtfistatic2:8;
        RBus_UInt32  film_nxtfimotion:8;
    };
}di_im_di_si_film_pattern_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_detected321:8;
        RBus_UInt32  film_match321:8;
        RBus_UInt32  film_violate321:8;
        RBus_UInt32  film_sequence321_39_32:8;
    };
}di_im_di_si_film_32_result_1_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence321_31_0:32;
    };
}di_im_di_si_film_32_result_1_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_detected322:8;
        RBus_UInt32  film_match322:8;
        RBus_UInt32  film_violate322:8;
        RBus_UInt32  film_sequence322_39_32:8;
    };
}di_im_di_si_film_32_result_2_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence322_31_0:32;
    };
}di_im_di_si_film_32_result_2_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_detected22:8;
        RBus_UInt32  film_match22:8;
        RBus_UInt32  film_violate22:8;
        RBus_UInt32  film_sequence22_39_32:8;
    };
}di_im_di_si_film_22_result_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence22_31_0:32;
    };
}di_im_di_si_film_22_result_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_719_700:20;
    };
}di_im_di_si_film_motion_next_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_699_680:20;
    };
}di_im_di_si_film_motion_next_h_t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_679_660:20;
    };
}di_im_di_si_film_motion_next_h_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_659_640:20;
    };
}di_im_di_si_film_motion_next_h_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_639_620:20;
    };
}di_im_di_si_film_motion_next_v_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_619_600:20;
    };
}di_im_di_si_film_motion_next_v_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_599_580:20;
    };
}di_im_di_si_film_motion_next_v_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_579_560:20;
    };
}di_im_di_si_film_motion_next_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_559_540:20;
    };
}di_im_di_si_film_motion_pre_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_539_520:20;
    };
}di_im_di_si_film_motion_pre_h_t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_519_500:20;
    };
}di_im_di_si_film_motion_pre_h_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_499_480:20;
    };
}di_im_di_si_film_motion_pre_h_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_479_460:20;
    };
}di_im_di_si_film_motion_pre_v_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_459_440:20;
    };
}di_im_di_si_film_motion_pre_v_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_439_420:20;
    };
}di_im_di_si_film_motion_pre_v_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_419_400:20;
    };
}di_im_di_si_film_motion_pre_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_399_380:20;
    };
}di_im_di_si_film_motion_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_379_360:20;
    };
}di_im_di_si_film_motion_h_t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_359_340:20;
    };
}di_im_di_si_film_motion_h_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_339_320:20;
    };
}di_im_di_si_film_motion_h_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_319_300:20;
    };
}di_im_di_si_film_motion_v_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_299_280:20;
    };
}di_im_di_si_film_motion_v_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_279_260:20;
    };
}di_im_di_si_film_motion_v_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_259_240:20;
    };
}di_im_di_si_film_motion_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_239_220:20;
    };
}di_im_di_si_film_motion_h_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_219_200:20;
    };
}di_im_di_si_film_motion_h_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_199_180:20;
    };
}di_im_di_si_film_motion_h_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_179_160:20;
    };
}di_im_di_si_film_motion_h_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_159_140:20;
    };
}di_im_di_si_film_motion_h_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_139_120:20;
    };
}di_im_di_si_film_motion_h_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_119_100:20;
    };
}di_im_di_si_film_motion_h_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_99_80:20;
    };
}di_im_di_si_film_motion_h_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_79_60:20;
    };
}di_im_di_si_film_motion_h_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_59_40:20;
    };
}di_im_di_si_film_motion_h_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_39_20:20;
    };
}di_im_di_si_film_motion_h_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  film_motionstatus_19_0:20;
    };
}di_im_di_si_film_motion_h_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  total_frame_motion_sum:24;
    };
}di_im_di_si_ma_total_fm_sum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  large_frame_motion_pixel:24;
    };
}di_im_di_si_ma_large_fm_pixel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  large_frame_motion_sum:24;
    };
}di_im_di_si_ma_large_fm_sum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  mess_horizontal_pixel:24;
    };
}di_im_di_si_ma_mess_h_pixel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cr_subbal_status:3;
        RBus_UInt32  cr_enable_mainbalance:1;
        RBus_UInt32  cr_mean3_status:8;
        RBus_UInt32  cr_mean2_status:8;
        RBus_UInt32  cr_mean1_status:8;
    };
}di_im_di_si_image_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  fbuf_crc_compare_en:1;
        RBus_UInt32  fbuf_crc_continous_mode:1;
        RBus_UInt32  fbuf_crc_compare_done:1;
        RBus_UInt32  fbuf_crc_r1_compare_fail:1;
        RBus_UInt32  fbuf_crc_r2_compare_fail:1;
        RBus_UInt32  fbuf_crc_r3_compare_fail:1;
        RBus_UInt32  fbuf_crc_r4_compare_fail:1;
        RBus_UInt32  fbuf_crc_r1_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r2_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r3_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r4_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_info_r1_compare_fail:1;
        RBus_UInt32  fbuf_crc_info_r2_compare_fail:1;
        RBus_UInt32  di_crc_ctrl_conti:1;
        RBus_UInt32  di_crc_ctrl_start:1;
        RBus_UInt32  cr_amount_subbalance:16;
    };
}di_im_di_si_sub_in_auto_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_crc_result:32;
    };
}di_im_di_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  newintrainterpolate_vertical_thd:10;
        RBus_UInt32  newintrainterpolate_sumdiff_thd:10;
        RBus_UInt32  newintrainterpolate_pixdiff_thd:8;
        RBus_UInt32  newintrainterpolate_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_partialstill:1;
        RBus_UInt32  cp_partialstillnew:1;
    };
}di_im_di_si_still_info_for_ne_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  film22_nxtfistatic1:8;
        RBus_UInt32  film22_nxtfimotion:8;
    };
}di_im_di_si_film22_detector_pattern_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cp_temporalthly:8;
        RBus_UInt32  cp_temporalthlc:8;
    };
}di_im_di_tnr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_rtnr_interlace_force2d_en:1;
        RBus_UInt32  cp_rtnr_rgb444_enable:1;
        RBus_UInt32  cp_progressive_line_dma:1;
        RBus_UInt32  cp_rtnr_rgb444_8bit_mode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_rtnr_rounding_correction2_errorthd_c:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_rtnr_rounding_correction2_errorthd_y:6;
        RBus_UInt32  cp_rtnr_mad_window_mode:1;
        RBus_UInt32  cp_rtnr_rounding_correction2_mode:2;
        RBus_UInt32  cp_rtnr_rounding_correction2_en:1;
        RBus_UInt32  cp_rtnr_updatelockflg:1;
        RBus_UInt32  cp_rtnr_updatelocken:1;
        RBus_UInt32  cp_rtnr_mad_window:2;
        RBus_UInt32  cp_rtnr_rounding_correction:1;
        RBus_UInt32  cp_rtnr_progressive:1;
        RBus_UInt32  cp_rtnr_c_enable:1;
        RBus_UInt32  cp_rtnr_y_enable:1;
    };
}di_im_di_rtnr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180241a4_31_27:5;
        RBus_UInt32  cp_rtnr_k_force_modify_index:3;
        RBus_UInt32  cp_rtnr_k_force_modify_mode:1;
        RBus_UInt32  cp_rtnr_ne_follow_k_modify:1;
        RBus_UInt32  cp_rtnr_k_force_modify_en_c:1;
        RBus_UInt32  cp_rtnr_k_force_modify_en_y:1;
        RBus_UInt32  cp_rtnr_k_force_modify_offset:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_24:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_00:1;
    };
}di_im_di_rtnr_k_force_modify_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_24:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_00:1;
        RBus_UInt32  res2:5;
        RBus_UInt32  tr2to1_dist:11;
    };
}di_tr2to1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_24:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_00:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_24:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_00:1;
    };
}di_im_di_rtnr_k_force_modify_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_temporal_mad_y_th1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_temporal_mad_y_th2:11;
    };
}di_im_di_rtnr_mad_y_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_temporal_mad_c_th1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_temporal_mad_c_th2:11;
    };
}di_im_di_rtnr_mad_c_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_countery:21;
    };
}di_im_di_rtnr_mad_y_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_counteru:21;
    };
}di_im_di_rtnr_mad_u_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_counterv:21;
    };
}di_im_di_rtnr_mad_v_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_24:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_00:1;
        RBus_UInt32  dummy180241c4_15_13:3;
        RBus_UInt32  cp_temporal_num_match_l:4;
        RBus_UInt32  cp_temporal_l_qlfy_th:4;
        RBus_UInt32  cp_temporal_c_k_decision:3;
        RBus_UInt32  cp_temporal_edge_crct_en:1;
        RBus_UInt32  res2:1;
    };
}di_im_di_rtnr_ediff_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_temporal_sad_offset_y:8;
        RBus_UInt32  cp_temporal_sad_offset_u:8;
        RBus_UInt32  cp_temporal_sad_offset_v:8;
    };
}di_im_di_rtnr_sad_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_e_th1_y:8;
        RBus_UInt32  cp_temporal_e_th2_y:8;
        RBus_UInt32  cp_temporal_e_th1_c:8;
        RBus_UInt32  cp_temporal_e_th2_c:8;
    };
}di_im_di_rtnr_ediff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180241d0_31_22:10;
        RBus_UInt32  cp_temporal_sbl_thm_y:10;
        RBus_UInt32  dummy180241d0_11_10:2;
        RBus_UInt32  cp_temporal_sbl_ths_y:10;
    };
}di_im_di_rtnr_ediff_sobel_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  cp_temporal_nl_up_bnd_y:8;
        RBus_UInt32  cp_temporal_nl_low_bnd_y:8;
    };
}di_im_di_rtnr_level_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_temporal_same_et_cnt_y:24;
    };
}di_im_di_rtnr_et_count_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_sad_sum_y:32;
    };
}di_im_di_rtnr_et_sum_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_sad_sum_u:32;
    };
}di_im_di_rtnr_et_sum_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_sad_sum_v:32;
    };
}di_im_di_rtnr_et_sum_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set_sobeledgetypeen:1;
        RBus_UInt32  set_stillmotion_tha:4;
        RBus_UInt32  set_stillmotion_thb:4;
        RBus_UInt32  set_stillmotion_thc:4;
        RBus_UInt32  set_classifysmooth:3;
        RBus_UInt32  set_frame_offset_verystill:4;
        RBus_UInt32  set_frame_offset_still:3;
        RBus_UInt32  set_frame_offset_motion:3;
        RBus_UInt32  set_frame_offset_verymotion:4;
        RBus_UInt32  cp_temporal_xc_switch:1;
        RBus_UInt32  cp_temporal_xc_en:1;
    };
}di_im_di_tnr_xc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  set_sobeledgetype_sel:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  stilllogo_hf_check_ctrl:1;
        RBus_UInt32  hfd_highfrequencydetectoren:1;
        RBus_UInt32  hfd_highlowhighdiff_thl:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  hfd_highlowhighdiff_count_thl:4;
        RBus_UInt32  res3:3;
        RBus_UInt32  hfd_manyteethareastilllogoen:1;
        RBus_UInt32  hfd_3x3blockteethcount_thl:4;
    };
}di_im_di_hfd_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hfd_checklinemotioncounten:1;
        RBus_UInt32  hfd_framekcombineoflinemotion:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  hfd_linemotioncount_thl2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  hfd_linemotioncount_thl:11;
    };
}di_im_di_hfd_line_motion_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hfd_statistic:24;
    };
}di_im_di_hfd_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  hmc_window_en:1;
        RBus_UInt32  hmc_window_top:10;
        RBus_UInt32  hmc_window_bot:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  stilllogolrcorrectionen:1;
        RBus_UInt32  stilllogoweavelineen:1;
    };
}di_im_di_hfd_ma_error_recovery_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  newintralowangle_continuous_pt:7;
        RBus_UInt32  newintralowangle_precur_diff_thd:10;
        RBus_UInt32  newintralowangle_vercur_diff_thd:10;
        RBus_UInt32  newintralowangle_left_dir:2;
        RBus_UInt32  newintralowangle_right_dir:2;
        RBus_UInt32  newintralowangle_enable:1;
    };
}di_im_di_new_intra_low_angle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intranewgracorr_transpt_thd:8;
        RBus_UInt32  intranewgracorr_gradmatchmin_thd:8;
        RBus_UInt32  intranewgracorr_gradmatchdiff_thd:8;
        RBus_UInt32  intranewgracorr_mintransrange:4;
        RBus_UInt32  intranewgracorr_minmatchdifftransrange:4;
    };
}di_im_di_intra_new_gradient_correct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intranewgracorr_enable:1;
        RBus_UInt32  intranewgracorr_doublecheck_enable:1;
        RBus_UInt32  intra_lowangle_lpf_enable:1;
        RBus_UInt32  intra_averagefilter_enable:1;
        RBus_UInt32  intra_range_correct_interpolation_enable:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  intranewgracorr_transptcenter_thd:8;
        RBus_UInt32  intra_areacorner_intrarange_correct_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  intra_lowangle_lpf_diffthd:10;
    };
}di_im_di_intra_post_process_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  btr_hmc_blendchoose:1;
        RBus_UInt32  btr_blendtemporaldebugmode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  btr_solb_cur1_count:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  btr_solb_cur0_count:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  btr_solb_temporallength:3;
        RBus_UInt32  btr_info_save_mode:2;
        RBus_UInt32  btr_blendtemporalrecovery_dma_en:1;
        RBus_UInt32  btr_sola_method0_blendtype:1;
        RBus_UInt32  btr_sola_method0_successtime:3;
        RBus_UInt32  btr_sola_method:1;
        RBus_UInt32  btr_sola_temporallength:2;
        RBus_UInt32  btr_solutiontype:1;
        RBus_UInt32  btr_blendtemporalrecoveryen:1;
    };
}di_im_di_btr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  btr_sola_method0_cur1_pre4_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre4_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre3_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre3_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre2_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre2_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre1_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre1_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre4_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre4_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre3_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre3_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre2_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre2_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre1_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre1_min:2;
    };
}di_im_di_btr_sola_method0_min_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_areacorner_intrarange_correct_peak_thd:8;
        RBus_UInt32  btr_longweavesum:24;
    };
}di_im_di_btr_longweave_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ber_lowpasssum:24;
    };
}di_im_di_ber_lowpass_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  ber_closeclevel_max:8;
        RBus_UInt32  res2:4;
        RBus_UInt32  ber_closeclevel_min:8;
        RBus_UInt32  ber_blendspatial_lpf_blendingtype:1;
        RBus_UInt32  ber_blendspatial_lpf_stilllogo:1;
        RBus_UInt32  ber_blendspatialclassify:1;
        RBus_UInt32  ber_blendspatialrecoveryen:1;
    };
}di_im_di_ber_spatial_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ber_diffylevel_max:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  ber_diffylevel_min:10;
    };
}di_im_di_ber_spatial_diffy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_totalcontinuesum:24;
        RBus_UInt32  ber_spatialcontinuelength:4;
        RBus_UInt32  ber_blendtemporaltype:1;
        RBus_UInt32  ber_blendtemporalblock:2;
        RBus_UInt32  ber_blendtemporalrevoeryen:1;
    };
}di_im_di_ber_temporal_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lpattern_flat_rldiff_th:8;
        RBus_UInt32  intra_lpattern_flat_cendiff_th:8;
        RBus_UInt32  intra_lpattern_flat_wholediff_th:8;
        RBus_UInt32  intra_lpattern_rough_diff_th:8;
    };
}di_im_di_intra_l_cross_pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lpattern_rough_flat_diff_th:8;
        RBus_UInt32  intra_lpattern_vdiff_th:8;
        RBus_UInt32  intra_lpattern_vdev_lowbound_th:8;
        RBus_UInt32  intra_lpattern_vdev_highbound_th:8;
    };
}di_im_di_intra_l_cross_pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lpattern_cen_pixdiff_th:8;
        RBus_UInt32  res1:19;
        RBus_UInt32  intra_lpattern_dir_pk_enable:1;
        RBus_UInt32  intra_lpattern_rough_ratio:3;
        RBus_UInt32  intra_lpattern_enable:1;
    };
}di_im_di_intra_l_cross_pat_det_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_noiseesthorend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_noiseesthorstart:12;
    };
}di_noiseest_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_noiseestverend:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_noiseestverstart:12;
    };
}di_noiseest_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802423c_31_0:32;
    };
}di_im_di_dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histthl1:8;
        RBus_UInt32  cp_histthl2:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  subsamplingmode:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_histhoroffset:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_histveroffset:3;
        RBus_UInt32  res4:3;
        RBus_UInt32  cp_histveren:1;
    };
}di_mpeg_hist_blking_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver1:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_cntver0:12;
    };
}di_cntver0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_cntver2:12;
    };
}di_cntver2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver5:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_cntver4:12;
    };
}di_cntver4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver7:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_cntver6:12;
    };
}di_cntver6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpglowerbound:8;
        RBus_UInt32  cp_mpgupperbound:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_mpglpmode:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpgidx_y:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_mpegresultweight_y:3;
        RBus_UInt32  cp_mpgidxmode_y:2;
        RBus_UInt32  cp_mpegenable_y_c:1;
        RBus_UInt32  cp_mpegenable_y_y:1;
    };
}di_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  pib_film_all:1;
        RBus_UInt32  pib_film_h_t:1;
        RBus_UInt32  pib_film_h_m:1;
        RBus_UInt32  pib_film_h_b:1;
        RBus_UInt32  pib_film_v_l:1;
        RBus_UInt32  pib_film_v_m:1;
        RBus_UInt32  pib_film_v_r:1;
        RBus_UInt32  pib_film_c:1;
        RBus_UInt32  pib_film_h_11:1;
        RBus_UInt32  pib_film_h_10:1;
        RBus_UInt32  pib_film_h_09:1;
        RBus_UInt32  pib_film_h_08:1;
        RBus_UInt32  pib_film_h_07:1;
        RBus_UInt32  pib_film_h_06:1;
        RBus_UInt32  pib_film_h_05:1;
        RBus_UInt32  pib_film_h_04:1;
        RBus_UInt32  pib_film_h_03:1;
        RBus_UInt32  pib_film_h_02:1;
        RBus_UInt32  pib_film_h_01:1;
        RBus_UInt32  pib_film_h_00:1;
    };
}di_im_di_pib_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pib_film_all_th:16;
        RBus_UInt32  pib_film_cen_all:16;
    };
}di_im_di_pib_all_cen_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pib_film_h_th:16;
        RBus_UInt32  pib_film_v_th:16;
    };
}di_im_di_pib_h_v_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pib_film_h00_h11_th:16;
    };
}di_im_di_pib_h00_h11_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  film_mask_frmdif_thd:8;
        RBus_UInt32  film_mask_fiedif_thd:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  film_mask_pass_thd:4;
        RBus_UInt32  film_mask_en:1;
    };
}di_im_di_film_mask_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  film_edgetype_sobelthm:10;
        RBus_UInt32  film_edgetype_sobelths:10;
        RBus_UInt32  res2:3;
        RBus_UInt32  film_edgetype_n_pass:1;
        RBus_UInt32  film_edgetype_l_pass:1;
        RBus_UInt32  film_edgetype_h_pass:1;
        RBus_UInt32  film_edgetype_r_pass:1;
        RBus_UInt32  film_edgetype_v_pass:1;
    };
}di_im_di_film_edge_type_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  hmc_startline:10;
    };
}di_im_di_hmc_3a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_hmc_statistic_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_hmc_botline:12;
        RBus_UInt32  ma_hmc_topline:12;
        RBus_UInt32  ma_hmc_lineratio:8;
    };
}di_im_di_hmc_statistic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ma_hmc_botline2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ma_hmc_topline2:12;
    };
}di_im_di_hmc_statistic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  ma_hmc_botline3:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  ma_hmc_topline3:12;
    };
}di_im_di_hmc_statistic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  lsb_rtnr_th:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  lsb_rtnr_curweight:3;
        RBus_UInt32  lsb_rtnr_rounding:1;
        RBus_UInt32  lsb_rtnr_bitnum:1;
        RBus_UInt32  lsb_rtnr_channel:1;
        RBus_UInt32  lsb_rtnr_en:1;
    };
}di_im_di_lsb_rtnr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  res2:7;
        RBus_UInt32  chromaerror_framemotionc_th:8;
        RBus_UInt32  tnrxc_pixel_counter:16;
    };
}di_im_di_framesobel_statistic_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  chromaerror_en:1;
        RBus_UInt32  chromaerror_all:1;
        RBus_UInt32  hmc_vector_follow_pan_en:1;
        RBus_UInt32  chromaerror_th:5;
        RBus_UInt32  hmc_dynamic_threshold_max_clip:8;
        RBus_UInt32  hmc_dynamic_threshold_bias:6;
        RBus_UInt32  hmc_dynamic_threshold_en:1;
        RBus_UInt32  res1:9;
    };
}di_im_di_framesobel_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnrxc_mkii_thc2:8;
        RBus_UInt32  tnrxc_mkii_thc1:8;
        RBus_UInt32  tnrxc_mkii_thy:8;
        RBus_UInt32  dummy180242a0_7_2:6;
        RBus_UInt32  tnrxc_dbguvmode:1;
        RBus_UInt32  tnrxc_mkii_en:1;
    };
}di_tnrxc_mkii_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_y_kout_dark_2:4;
        RBus_UInt32  cp_temporal_y_kin_dark_2:4;
        RBus_UInt32  cp_temporal_y_dark_th:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_temporal_y_kout_dark:4;
        RBus_UInt32  cp_temporal_y_kin_dark:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  cp_temporal_y_dark_k_en:1;
    };
}di_im_di_rtnr_k_dark_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180242a8_31_29:3;
        RBus_UInt32  rtnr_refined_c_en:1;
        RBus_UInt32  rtnr_th_localedgediff:12;
        RBus_UInt32  rtnr_stilledge_debug:1;
        RBus_UInt32  rtnr_stilledge_bonusbias:3;
        RBus_UInt32  rtnr_localedge_debug:1;
        RBus_UInt32  rtnr_act_bias:3;
        RBus_UInt32  dummy180242a8_7:1;
        RBus_UInt32  rtnr_crct_bias:3;
        RBus_UInt32  rtnr_crct_debug:1;
        RBus_UInt32  rtnr_stilledge_en:1;
        RBus_UInt32  rtnr_localedge_en:1;
        RBus_UInt32  rtnr_new_formula_en:1;
    };
}di_im_di_rtnr_refined_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180242ac_31_17:15;
        RBus_UInt32  rtnr_stilledge_th_edgdiff:9;
        RBus_UInt32  rtnr_stilledge_th_edg:8;
    };
}di_im_di_rtnr_refined_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  cp_temporal_ediff_c_en6:1;
        RBus_UInt32  cp_temporal_ediff_c_en5:1;
        RBus_UInt32  cp_temporal_ediff_c_en4:1;
        RBus_UInt32  cp_temporal_ediff_c_en3:1;
        RBus_UInt32  cp_temporal_ediff_c_en2:1;
        RBus_UInt32  cp_temporal_ediff_c_en1:1;
        RBus_UInt32  cp_temporal_ediff_c_en0:1;
    };
}di_im_di_rtnr_ediff_enable_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  cp_temporal_y_k_decision:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_temporal_ediff_en14:1;
        RBus_UInt32  cp_temporal_ediff_en13:1;
        RBus_UInt32  cp_temporal_ediff_en12:1;
        RBus_UInt32  cp_temporal_ediff_en11:1;
        RBus_UInt32  cp_temporal_ediff_en10:1;
        RBus_UInt32  cp_temporal_ediff_en9:1;
        RBus_UInt32  cp_temporal_ediff_en8:1;
        RBus_UInt32  cp_temporal_ediff_en7:1;
        RBus_UInt32  cp_temporal_ediff_en6:1;
        RBus_UInt32  cp_temporal_ediff_en5:1;
        RBus_UInt32  cp_temporal_ediff_en4:1;
        RBus_UInt32  cp_temporal_ediff_en3:1;
        RBus_UInt32  cp_temporal_ediff_en2:1;
        RBus_UInt32  cp_temporal_ediff_en1:1;
        RBus_UInt32  cp_temporal_ediff_en0:1;
    };
}di_im_di_rtnr_ediff_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_temporal_hmcnr_mad_window:2;
        RBus_UInt32  cp_temporal_hmcnr_weight:3;
        RBus_UInt32  cp_temporal_hmcnr_ref_topline_th:11;
        RBus_UInt32  cp_temporal_hmcnr_y_en:1;
        RBus_UInt32  cp_temporal_hmcnr_debug_progressive:1;
        RBus_UInt32  cp_temporal_hmcnr_ref_topline_en:1;
        RBus_UInt32  cp_temporal_hmcnr_uv_with_y:1;
        RBus_UInt32  cp_temporal_hmcnr_follow_pan_en:1;
        RBus_UInt32  res2:3;
    };
}di_im_di_rtnr_hmcnr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  rtnr_debugmode:4;
        RBus_UInt32  prtnr_4k2k:1;
        RBus_UInt32  rtnr_moredetail_cotinue_en:1;
        RBus_UInt32  rtnr_k_temporal_compare_snr:1;
        RBus_UInt32  rtnr_k_temporal_compare_en:1;
        RBus_UInt32  res2:8;
        RBus_UInt32  rtnr_sad_mix_cal_weight:4;
        RBus_UInt32  rtnr_new_method_k_extend_en:1;
        RBus_UInt32  rtnr_sad_method:2;
        RBus_UInt32  rtnr_new_method_en:1;
    };
}di_im_di_rtnr_new_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  rtnr_edgetypediff_count_th0:6;
        RBus_UInt32  rtnr_sobel_method:2;
        RBus_UInt32  rtnr_sbl_thm_y:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  rtnr_sbl_ths_y:10;
    };
}di_im_di_rtnr_new_sobel_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th4:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th3:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th2:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th1:8;
    };
}di_im_di_rtnr_new_sad_edge_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th8:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th7:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th6:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th5:8;
    };
}di_im_di_rtnr_new_sad_edge_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th4:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th3:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th2:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th1:8;
    };
}di_im_di_rtnr_new_sad_nonedge_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th8:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th7:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th6:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th5:8;
    };
}di_im_di_rtnr_new_sad_nonedge_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  rtnr_statistic_motion_count_th6:5;
        RBus_UInt32  rtnr_statistic_motion_count_th5:5;
        RBus_UInt32  rtnr_statistic_motion_count_th4:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  rtnr_statistic_motion_count_th3:5;
        RBus_UInt32  rtnr_statistic_motion_count_th2:5;
        RBus_UInt32  rtnr_statistic_motion_count_th1:5;
    };
}di_im_di_rtnr_new_sad_count_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  rtnr_edgetypediff_count_th4:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rtnr_edgetypediff_count_th3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  rtnr_edgetypediff_count_th2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  rtnr_edgetypediff_count_th1:6;
    };
}di_im_di_rtnr_new_edgetypediff_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  rtnr_edgetypediff_count_th8:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rtnr_edgetypediff_count_th7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  rtnr_edgetypediff_count_th6:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  rtnr_edgetypediff_count_th5:6;
    };
}di_im_di_rtnr_new_edgetypediff_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_rtnr_new_snr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_rtnr_new_snr_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_rtnr_new_snr_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_07:4;
        RBus_UInt32  rtnr_k_06:4;
        RBus_UInt32  rtnr_k_05:4;
        RBus_UInt32  rtnr_k_04:4;
        RBus_UInt32  rtnr_k_03:4;
        RBus_UInt32  rtnr_k_02:4;
        RBus_UInt32  rtnr_k_01:4;
        RBus_UInt32  rtnr_k_00:4;
    };
}di_im_di_rtnr_new_k_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_17:4;
        RBus_UInt32  rtnr_k_16:4;
        RBus_UInt32  rtnr_k_15:4;
        RBus_UInt32  rtnr_k_14:4;
        RBus_UInt32  rtnr_k_13:4;
        RBus_UInt32  rtnr_k_12:4;
        RBus_UInt32  rtnr_k_11:4;
        RBus_UInt32  rtnr_k_10:4;
    };
}di_im_di_rtnr_new_k_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_27:4;
        RBus_UInt32  rtnr_k_26:4;
        RBus_UInt32  rtnr_k_25:4;
        RBus_UInt32  rtnr_k_24:4;
        RBus_UInt32  rtnr_k_23:4;
        RBus_UInt32  rtnr_k_22:4;
        RBus_UInt32  rtnr_k_21:4;
        RBus_UInt32  rtnr_k_20:4;
    };
}di_im_di_rtnr_new_k_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_37:4;
        RBus_UInt32  rtnr_k_36:4;
        RBus_UInt32  rtnr_k_35:4;
        RBus_UInt32  rtnr_k_34:4;
        RBus_UInt32  rtnr_k_33:4;
        RBus_UInt32  rtnr_k_32:4;
        RBus_UInt32  rtnr_k_31:4;
        RBus_UInt32  rtnr_k_30:4;
    };
}di_im_di_rtnr_new_k_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_47:4;
        RBus_UInt32  rtnr_k_46:4;
        RBus_UInt32  rtnr_k_45:4;
        RBus_UInt32  rtnr_k_44:4;
        RBus_UInt32  rtnr_k_43:4;
        RBus_UInt32  rtnr_k_42:4;
        RBus_UInt32  rtnr_k_41:4;
        RBus_UInt32  rtnr_k_40:4;
    };
}di_im_di_rtnr_new_k_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_57:4;
        RBus_UInt32  rtnr_k_56:4;
        RBus_UInt32  rtnr_k_55:4;
        RBus_UInt32  rtnr_k_54:4;
        RBus_UInt32  rtnr_k_53:4;
        RBus_UInt32  rtnr_k_52:4;
        RBus_UInt32  rtnr_k_51:4;
        RBus_UInt32  rtnr_k_50:4;
    };
}di_im_di_rtnr_new_k_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_67:4;
        RBus_UInt32  rtnr_k_66:4;
        RBus_UInt32  rtnr_k_65:4;
        RBus_UInt32  rtnr_k_64:4;
        RBus_UInt32  rtnr_k_63:4;
        RBus_UInt32  rtnr_k_62:4;
        RBus_UInt32  rtnr_k_61:4;
        RBus_UInt32  rtnr_k_60:4;
    };
}di_im_di_rtnr_new_k_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_77:4;
        RBus_UInt32  rtnr_k_76:4;
        RBus_UInt32  rtnr_k_75:4;
        RBus_UInt32  rtnr_k_74:4;
        RBus_UInt32  rtnr_k_73:4;
        RBus_UInt32  rtnr_k_72:4;
        RBus_UInt32  rtnr_k_71:4;
        RBus_UInt32  rtnr_k_70:4;
    };
}di_im_di_rtnr_new_k_70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vc_nr_mask1_yref:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vc_nr_mask1_uref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vc_nr_mask1_vref:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  rtnr_mask1_ygain:2;
        RBus_UInt32  rtnr_mask1_ugain:2;
        RBus_UInt32  rtnr_mask1_vgain:2;
    };
}di_im_di_rtnr_new_mask1_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rtnr_mask1_maplimit:4;
        RBus_UInt32  rtnr_mask1_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  rtnr_mask1_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  rtnr_mask1_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  rtnr_mask1_en:1;
    };
}di_im_di_rtnr_new_mask1_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_vc_nr_mask2_yref:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_vc_nr_mask2_uref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vc_nr_mask2_vref:6;
        RBus_UInt32  res3:4;
        RBus_UInt32  rtnr_mask2_ygain:2;
        RBus_UInt32  rtnr_mask2_ugain:2;
        RBus_UInt32  rtnr_mask2_vgain:2;
    };
}di_im_di_rtnr_new_mask2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  rtnr_mask2_maplimit:4;
        RBus_UInt32  rtnr_mask2_mapthre:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  rtnr_mask2_mapstep:3;
        RBus_UInt32  res3:3;
        RBus_UInt32  rtnr_mask2_dir:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  rtnr_mask2_en:1;
    };
}di_im_di_rtnr_new_mask2_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  intra_highfreq_en:1;
        RBus_UInt32  intra_highfreq_diff_th:8;
        RBus_UInt32  intra_highfreq_dir2:4;
        RBus_UInt32  intra_highfreq_dir1:4;
        RBus_UInt32  intra_highfreq_change_th2:6;
        RBus_UInt32  intra_highfreq_change_th1:6;
    };
}di_im_di_intra_hfd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_debug_mode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  bc_type2_block_access_mode:1;
        RBus_UInt32  bc_type2_block_access_y:5;
        RBus_UInt32  bc_type2_block_access_x:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  bc_type2_block_update_once:1;
        RBus_UInt32  bc_type2_block_update_type:1;
        RBus_UInt32  bc_type2_en:1;
        RBus_UInt32  bc_type1_mid_teeth_max:8;
        RBus_UInt32  bc_type1_mid_teeth_min:4;
        RBus_UInt32  res3:1;
        RBus_UInt32  bc_type1_blendmode:2;
        RBus_UInt32  bc_type1_en:1;
    };
}di_im_di_blending_corrector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_block_height:8;
        RBus_UInt32  bc_type2_block_width:8;
        RBus_UInt32  bc_type2_edgecase_m:1;
        RBus_UInt32  bc_type2_edgecase_s:1;
        RBus_UInt32  bc_type2_edgecase_rlv:1;
        RBus_UInt32  bc_type2_edgecase_h:1;
        RBus_UInt32  bc_type2_block_access_data:12;
    };
}di_im_di_blending_corrector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_frame_motion_offset:6;
        RBus_UInt32  bc_type2_block_motion_th_2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  bc_type2_block_motion_th_1:10;
    };
}di_im_di_blending_corrector_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_slight_teeth_min:3;
        RBus_UInt32  bc_type3_en:1;
        RBus_UInt32  bc_type3_hfsum:12;
        RBus_UInt32  bc_type2_slight_teeth_max:4;
        RBus_UInt32  bc_type2_slight_teeth_en:1;
        RBus_UInt32  bc_type2_prefer_intra:1;
        RBus_UInt32  bc_type2_block_motion_th_3:10;
    };
}di_im_di_blending_corrector_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_mc_odd_mv_pass_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  pan_mc_sobel_diff_min_th:6;
        RBus_UInt32  res2:19;
        RBus_UInt32  pan_mc_path_sel:1;
        RBus_UInt32  pan_me_edgediff_min_th:3;
        RBus_UInt32  pan_en:1;
    };
}di_im_di_pan_detection_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  pan_mc_teeth_check_th:4;
        RBus_UInt32  pan_mc_teeth_check_en:1;
        RBus_UInt32  pan_mc_edge_n:1;
        RBus_UInt32  pan_mc_edge_h:1;
        RBus_UInt32  pan_mc_edge_v:1;
        RBus_UInt32  pan_mc_edge_l:1;
        RBus_UInt32  pan_mc_edge_r:1;
        RBus_UInt32  res2:6;
    };
}di_im_di_pan_detection_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r7_pixelsum:16;
        RBus_UInt32  hmc_r6_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r5_pixelsum:16;
        RBus_UInt32  hmc_r4_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r3_pixelsum:16;
        RBus_UInt32  hmc_r2_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r1_pixelsum:16;
        RBus_UInt32  hmc_c0_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l1_pixelsum:16;
        RBus_UInt32  hmc_l2_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l3_pixelsum:16;
        RBus_UInt32  hmc_l4_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l5_pixelsum:16;
        RBus_UInt32  hmc_l6_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l7_pixelsum:16;
        RBus_UInt32  res1:4;
        RBus_UInt32  pan_me_border_top_width:12;
    };
}di_im_di_pan_detection_statistic_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  pan_me_border_bot_width:12;
        RBus_UInt32  pan_me_border_left_width:8;
        RBus_UInt32  pan_me_border_right_width:8;
    };
}di_im_di_pan_detection_control_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  fw_film_doublebuffer_en:1;
        RBus_UInt32  film_bad_edit_en:1;
        RBus_UInt32  fw_film_filmsequence:5;
        RBus_UInt32  fw_film_32detected1:1;
        RBus_UInt32  fw_film_32detected2:1;
        RBus_UInt32  fw_film_22detected:1;
        RBus_UInt32  fw_film_filmweavemode:2;
        RBus_UInt32  fw_film_mixedfilmconfuse:1;
        RBus_UInt32  fw_film_mixedfilmdetected:1;
        RBus_UInt32  fw_film_filmdetected:1;
        RBus_UInt32  film_mixedfilm_margin:2;
        RBus_UInt32  fw_film_reg_sel:1;
        RBus_UInt32  badeditor_ratio:2;
        RBus_UInt32  film_pair3_ratio:2;
        RBus_UInt32  force_badeditor_en:1;
        RBus_UInt32  film_pair3_en:1;
        RBus_UInt32  fw_film_en:1;
    };
}di_im_di_film_new_function_main_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fw_botline1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  fw_topline1:11;
    };
}di_im_di_film_topbotline1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fw_botline2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  fw_topline2:11;
    };
}di_im_di_film_topbotline2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  fw_botline3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  fw_topline3:11;
    };
}di_im_di_film_topbotline3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  film_badeditor_flag:1;
        RBus_UInt32  film22_prevfilmmotion:8;
        RBus_UInt32  film_prevfilmmotion:8;
    };
}di_im_di_film_prev_fieldmotion_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  film_nextbotdetected3:1;
        RBus_UInt32  film_nexttopdetected3:1;
        RBus_UInt32  film_nextbotdetected2:1;
        RBus_UInt32  film_nexttopdetected2:1;
        RBus_UInt32  film_nextbotdetected1:1;
        RBus_UInt32  film_nexttopdetected1:1;
        RBus_UInt32  film_prevbotdetected3:1;
        RBus_UInt32  film_prevtopdetected3:1;
        RBus_UInt32  film_prevbotdetected2:1;
        RBus_UInt32  film_prevtopdetected2:1;
        RBus_UInt32  film_prevbotdetected1:1;
        RBus_UInt32  film_prevtopdetected1:1;
    };
}di_im_di_film_mark_information_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  film_prevbotmark1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  film_prevtopmark1:11;
    };
}di_im_di_film_mark_prev1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  film_prevbotmark2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  film_prevtopmark2:11;
    };
}di_im_di_film_mark_prev2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  film_prevbotmark3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  film_prevtopmark3:11;
    };
}di_im_di_film_mark_prev3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  film_nextbotmark1:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  film_nexttopmark1:11;
    };
}di_im_di_film_mark_next1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  film_nextbotmark2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  film_nexttopmark2:11;
    };
}di_im_di_film_mark_next2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  film_nextbotmark3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  film_nexttopmark3:11;
    };
}di_im_di_film_mark_next3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_en:1;
        RBus_UInt32  smd_debug_hentryofmv_en:1;
        RBus_UInt32  smd_debug_ventryofmv_en:1;
        RBus_UInt32  smd_debug_sawtooth_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_spatialmv_counter_th:2;
        RBus_UInt32  smd_debug_preinrateeth_en:1;
        RBus_UInt32  smd_debug_resurrect_en:1;
        RBus_UInt32  smd_debug_mvschanged_en:1;
        RBus_UInt32  smd_debug_spatialfreqnomatch_en:1;
        RBus_UInt32  smd_debug_outofrange_en:1;
        RBus_UInt32  smd_localmv_counter_th:3;
        RBus_UInt32  smd_lowbound_sad_forjudgemv:8;
        RBus_UInt32  smd_upperbound_sad_forjudgemv:8;
    };
}di_di_smd_control_candidatelist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_spatialmv_sad_th:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_spatial_divergence_th:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_localmv_concentrate_ratio_th:3;
        RBus_UInt32  smd_localmv_sad_th:8;
        RBus_UInt32  smd_reliablerange_sad_th:8;
    };
}di_di_smd_choosecandidate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_steeth_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_preintra_teeth_offset:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_preintra_effect:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_preintra_teeth_gain:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  smd_curr_teeth_gain:3;
        RBus_UInt32  smd_teeth_new_mode:2;
        RBus_UInt32  smd_curr_teeth_offset:6;
    };
}di_di_smd_refinemv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_mvs_vchanged_en:1;
        RBus_UInt32  smd_mvs_hchanged_en:1;
        RBus_UInt32  smd_resurrect_en:1;
        RBus_UInt32  smd_resurrect_union_num:5;
        RBus_UInt32  smd_resurrect_smallwindow_num:4;
        RBus_UInt32  smd_resurrect_localcurr_num:4;
        RBus_UInt32  smd_resurrect_minsad_th:8;
        RBus_UInt32  smd_global_en_ratio:8;
    };
}di_di_smd_refinemv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_sfreq_diff_gain:4;
        RBus_UInt32  smd_sfreq_diff_th:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  smd_sfreq_drop_th:10;
    };
}di_di_smd_refinemv3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_di_smd_panning1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_drop_singleweaveline_en:1;
        RBus_UInt32  smd_drop_singleintraline_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_leftweave_gap_range:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_leftweave_gap_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_rightweave_gap_range:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  smd_rightweave_gap_th:5;
    };
}di_di_smd_final_adjustment1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_line_continous_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_leftintra_gap_range:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_leftintra_gap_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_rightintra_gap_range:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  smd_rightintra_gap_th:5;
    };
}di_di_smd_final_adjustment2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_compensate_teeth_th:8;
        RBus_UInt32  smd_compensate_avg:8;
    };
}di_di_smd_compensate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rtnr_new_method_sc_th:8;
        RBus_UInt32  res2:6;
        RBus_UInt32  rtnr_new_method_sc_mode:1;
        RBus_UInt32  rtnr_new_method_sc_en:1;
    };
}di_im_di_rtnr_sc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly3:8;
        RBus_UInt32  cp_temporalthly2:8;
        RBus_UInt32  cp_temporalthly1:8;
        RBus_UInt32  cp_temporalthly0:8;
    };
}di_im_di_rtnr_y_16_th0_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly7:8;
        RBus_UInt32  cp_temporalthly6:8;
        RBus_UInt32  cp_temporalthly5:8;
        RBus_UInt32  cp_temporalthly4:8;
    };
}di_im_di_rtnr_y_16_th4_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly11:8;
        RBus_UInt32  cp_temporalthly10:8;
        RBus_UInt32  cp_temporalthly9:8;
        RBus_UInt32  cp_temporalthly8:8;
    };
}di_im_di_rtnr_y_16_th8_th11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_temporalthly14:8;
        RBus_UInt32  cp_temporalthly13:8;
        RBus_UInt32  cp_temporalthly12:8;
    };
}di_im_di_rtnr_y_16_th12_th14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthlc3:8;
        RBus_UInt32  cp_temporalthlc2:8;
        RBus_UInt32  cp_temporalthlc1:8;
        RBus_UInt32  cp_temporalthlc0:8;
    };
}di_im_di_rtnr_c_th0_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  cp_temporalthlc6:8;
        RBus_UInt32  cp_temporalthlc5:8;
        RBus_UInt32  cp_temporalthlc4:8;
    };
}di_im_di_rtnr_c_th4_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_y_k7:4;
        RBus_UInt32  cp_temporal_y_k6:4;
        RBus_UInt32  cp_temporal_y_k5:4;
        RBus_UInt32  cp_temporal_y_k4:4;
        RBus_UInt32  cp_temporal_y_k3:4;
        RBus_UInt32  cp_temporal_y_k2:4;
        RBus_UInt32  cp_temporal_y_k1:4;
        RBus_UInt32  cp_temporal_y_k0:4;
    };
}di_im_di_rtnr_y_16_k0_k7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_y_k15:4;
        RBus_UInt32  cp_temporal_y_k14:4;
        RBus_UInt32  cp_temporal_y_k13:4;
        RBus_UInt32  cp_temporal_y_k12:4;
        RBus_UInt32  cp_temporal_y_k11:4;
        RBus_UInt32  cp_temporal_y_k10:4;
        RBus_UInt32  cp_temporal_y_k9:4;
        RBus_UInt32  cp_temporal_y_k8:4;
    };
}di_im_di_rtnr_y_16_k8_k15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_temporal_c_k7:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_temporal_c_k6:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_temporal_c_k5:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cp_temporal_c_k4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cp_temporal_c_k3:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cp_temporal_c_k2:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cp_temporal_c_k1:3;
        RBus_UInt32  res8:1;
        RBus_UInt32  cp_temporal_c_k0:3;
    };
}di_im_di_rtnr_c_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_115_87:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_86_58:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_57_29:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_28_0:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_mstart_57_29:29;
        RBus_UInt32  res1:3;
    };
}di_di_infmemorystartadd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_mstart_28_0:29;
        RBus_UInt32  res1:3;
    };
}di_di_infmemorystartadd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_water_r:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  dat_len_r:7;
        RBus_UInt32  dat_num_r:16;
    };
}di_ddr_rdatdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_water_w:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  dat_len_w:7;
        RBus_UInt32  dat_num_w:16;
    };
}di_ddr_wdatdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rdma_remain_en:1;
        RBus_UInt32  dat_remain_w:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  dat_remain_r:7;
    };
}di_ddr_datdma_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_water_r:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  inf_len_r:7;
        RBus_UInt32  inf_num_r:16;
    };
}di_ddr_rinfdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_water_w:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  inf_len_w:7;
        RBus_UInt32  inf_num_w:16;
    };
}di_ddr_winfdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  inf_remain_w:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  inf_remain_r:7;
    };
}di_ddr_infdma_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_fifoerr_ie:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  ccdinr_flag_clr:8;
        RBus_UInt32  ccdinr_ovfl:8;
        RBus_UInt32  ccdinr_unfl:8;
    };
}di_ddr_dmastatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_fifoerr_wde:1;
        RBus_UInt32  ccdinr_vs_reset_en:1;
        RBus_UInt32  ccdinr_fifoerr_wde_sub:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  ccdinr_wd_to_main:1;
        RBus_UInt32  ccdinr_wd_to_sub:1;
    };
}di_ddr_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di1_wrrd_downlimit_adr:29;
        RBus_UInt32  res1:3;
    };
}di_di1_wrrd_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di1_wrrd_uplimit_adr:29;
        RBus_UInt32  res1:3;
    };
}di_di1_wrrd_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  di1_wrrd_downup_limit_ov_clearstatus:1;
        RBus_UInt32  di1_wr_downlimit_ov:2;
        RBus_UInt32  di1_wr_uplimit_ov:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  di1_rd_downlimit_ov:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  di1_rd_uplimit_ov:6;
    };
}di_di1_wrrd_boundaryadd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_3d_115_87:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd1_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_3d_86_58:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd2_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_3d_57_29:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd3_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_mstart_3d_28_0:29;
        RBus_UInt32  res1:3;
    };
}di_di_datmemorystartadd4_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_mstart_3d_57_29:29;
        RBus_UInt32  res1:3;
    };
}di_di_infmemorystartadd1_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_mstart_3d_28_0:29;
        RBus_UInt32  res1:3;
    };
}di_di_infmemorystartadd2_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_line_dma_buffer_cnt:2;
        RBus_UInt32  ccdinr_write_addr_l:29;
    };
}di_di_line_base_dma_addr_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  ccdinr_write_addr_r:29;
    };
}di_di_line_base_dma_addr_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_info_first:1;
        RBus_UInt32  res1:24;
        RBus_UInt32  rdma_req_num:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  wdma_req_num:2;
    };
}di_di_dma_multi_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_li1_bist_fail:8;
        RBus_UInt32  di_li2_bist_fail:8;
        RBus_UInt32  di_li3_bist_fail:8;
        RBus_UInt32  di_hmc_bist_fail:5;
        RBus_UInt32  di_tr2to1_bist_fail:3;
    };
}di_dispi_bist_fail_separate_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_dma_wdat_bist_fail:8;
        RBus_UInt32  di_dma_rdat_bist_fail:8;
        RBus_UInt32  di_memc_film_bist_fail:2;
        RBus_UInt32  di_li4_bist_fail:8;
        RBus_UInt32  di_li5_bist_fail:5;
        RBus_UInt32  res1:1;
    };
}di_dispi_bist_fail_separate_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_li1_drf_fail:8;
        RBus_UInt32  di_li2_drf_fail:8;
        RBus_UInt32  di_li3_drf_fail:8;
        RBus_UInt32  di_hmc_drf_fail:5;
        RBus_UInt32  di_tr2to1_drf_fail:3;
    };
}di_dispi_drf_fail_separate_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_dma_wdat_drf_fail:8;
        RBus_UInt32  di_dma_rdat_drf_fail:8;
        RBus_UInt32  di_memc_film_drf_fail:2;
        RBus_UInt32  di_li4_drf_fail:8;
        RBus_UInt32  di_li5_drf_fail:5;
        RBus_UInt32  res1:1;
    };
}di_dispi_drf_fail_separate_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  di_li1_rme:1;
        RBus_UInt32  di_li2_rme:1;
        RBus_UInt32  di_li3_rme:1;
        RBus_UInt32  di_li4_rme:1;
        RBus_UInt32  di_li5_rme:1;
        RBus_UInt32  di_hmc_rme:1;
        RBus_UInt32  di_tr2to1_rme:1;
        RBus_UInt32  di_memc_film_rme:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  di_dma_wdat_rme:1;
        RBus_UInt32  di_dma_rdat_rme:1;
    };
}di_dispi_bist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  di_li1_rm:4;
        RBus_UInt32  di_li2_rm:4;
        RBus_UInt32  di_li3_rm:4;
        RBus_UInt32  di_hmc_rm:4;
        RBus_UInt32  di_tr2to1_rm:4;
        RBus_UInt32  di_memc_film_rm:4;
        RBus_UInt32  res2:4;
    };
}di_dispi_bist_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  di_li5_rm:4;
        RBus_UInt32  di_li4_rm:4;
        RBus_UInt32  di_dma_wdat_rm:4;
        RBus_UInt32  di_dma_rdat_rm:4;
    };
}di_dispi_bist_rm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_dispi_bist_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sm_tog_apply_disable:1;
        RBus_UInt32  sm_tog_3d_mode:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  db_read:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_apply:1;
    };
}di_db_reg_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  sm_tog_v_start:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  sm_tog_h_start:12;
    };
}di_sm_tog_tg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  sm_tog_v_total:13;
        RBus_UInt32  res2:3;
        RBus_UInt32  sm_tog_h_total:13;
    };
}di_sm_tog_tg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ccdinr_debug_mode:3;
    };
}di_ccdinr_dbg_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18024540_31_2:30;
        RBus_UInt32  smd_partialweave:2;
    };
}di_di_smd_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin0:16;
        RBus_UInt32  smd_sad_his_bin1:16;
    };
}di_di_smd_sadhisbina_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin2:16;
        RBus_UInt32  smd_sad_his_bin3:16;
    };
}di_di_smd_sadhisbinb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin4:16;
        RBus_UInt32  smd_sad_his_bin5:16;
    };
}di_di_smd_sadhisbinc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin6:16;
        RBus_UInt32  smd_sad_his_bin7:16;
    };
}di_di_smd_sadhisbind_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin8:16;
        RBus_UInt32  smd_sad_his_bin9:16;
    };
}di_di_smd_sadhisbine_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin10:16;
        RBus_UInt32  smd_sad_his_bin11:16;
    };
}di_di_smd_sadhisbinf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin12:16;
        RBus_UInt32  smd_sad_his_bin13:16;
    };
}di_di_smd_sadhisbing_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin14:16;
        RBus_UInt32  smd_sad_his_bin15:16;
    };
}di_di_smd_sadhisbinh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmv_ctr:16;
        RBus_UInt32  smd_gmv1_max_ctr:16;
    };
}di_di_smd_gmvcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmv2_max_ctr:16;
        RBus_UInt32  smd_gmv3_max_ctr:16;
    };
}di_di_smd_gmvcoeff2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmv_old_method:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_gmv1_x:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_gmv1_y:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_gmv2_x:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  smd_gmv2_y:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  smd_gmv3_x:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  smd_firmwaremv_x:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  smd_firmwaremv_y:3;
    };
}di_di_smd_gmvcoeff3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_apply_result_mode:2;
        RBus_UInt32  smd_firmware_pan:1;
        RBus_UInt32  smd_searchmv_apply:1;
        RBus_UInt32  smd_hardware_pan_en:1;
        RBus_UInt32  smd_vpan_en:1;
        RBus_UInt32  smd_searchmv_apply_sad_th:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_pg_no_pixel_ctr_en:1;
        RBus_UInt32  smd_firmware_pan_sad_th:6;
        RBus_UInt32  smd_vpan_work_th:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_vpan_jump_out:3;
        RBus_UInt32  smd_vpan_upper_bound:4;
    };
}di_di_smd_pan1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_enter_pan_ctr_th:6;
        RBus_UInt32  smd_vpan_gmv1_pixel:6;
        RBus_UInt32  smd_vpan_total_pixel:6;
        RBus_UInt32  smd_gmv3_th:14;
    };
}di_di_smd_pan2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_addctr_gmv1_pixelth1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_addctr_gmv1_pixelth2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  smd_search_apply_th:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  smd_rebuild_pan_ctr:6;
    };
}di_di_smd_pan3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_full_search_mode:1;
        RBus_UInt32  smd_intra_en:1;
        RBus_UInt32  smd_colony_drop_en:1;
        RBus_UInt32  smd_colony_expanse_en:1;
        RBus_UInt32  smd_colony_expanse_type:1;
        RBus_UInt32  smd_result_en:1;
        RBus_UInt32  smd_curr_teeth_offset_c:6;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_curr_teeth_gain_c:3;
        RBus_UInt32  smd_expanse_range:3;
        RBus_UInt32  smd_left_weave_blend:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_right_weave_blend:5;
    };
}di_di_smd_additionalcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_image_boundary_height:4;
        RBus_UInt32  smd_image_boundary_width:4;
        RBus_UInt32  smd_search_gmv_offset:5;
        RBus_UInt32  smd_search_gmv_gain:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_left_us_blend:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_right_us_blend:5;
    };
}di_di_smd_additionalcoeff2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sm_flag_control:1;
        RBus_UInt32  smd_zm_flag_control:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_left_us_range:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_left_us_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_right_us_range:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  smd_right_us_th:5;
    };
}di_di_smd_additionalcoeff3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_patterngenmode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_v4highfreqeffect:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_v4highfreqth2:7;
        RBus_UInt32  res3:4;
        RBus_UInt32  smd_v4highfreqth1:12;
    };
}di_di_smd_v4highfreq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_continue_th:4;
        RBus_UInt32  smd_zoommotion_continue_count:4;
        RBus_UInt32  smd_zoommotion_flag:2;
        RBus_UInt32  smd_zoommotion_vector_ratio:6;
        RBus_UInt32  smd_zoommotion_block_ratio_offset:4;
        RBus_UInt32  smd_zoommotion_block_9_en:1;
        RBus_UInt32  smd_zoommotion_block_8_en:1;
        RBus_UInt32  smd_zoommotion_block_7_en:1;
        RBus_UInt32  smd_zoommotion_block_6_en:1;
        RBus_UInt32  smd_zoommotion_block_5_en:1;
        RBus_UInt32  smd_zoommotion_block_4_en:1;
        RBus_UInt32  smd_zoommotion_block_3_en:1;
        RBus_UInt32  smd_zoommotion_block_2_en:1;
        RBus_UInt32  smd_zoommotion_block_1_en:1;
        RBus_UInt32  smd_zoommotion_type_sel:2;
        RBus_UInt32  smd_zoommotion_en:1;
    };
}di_im_di_zoommotion_detector_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_zoommotion_x_2:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  smd_zoommotion_x_1:12;
    };
}di_im_di_zoommotion_det_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  smd_zoommotion_y_2:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  smd_zoommotion_y_1:11;
    };
}di_im_di_zoommotion_det_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_debugmode_en:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  smd_zoommotion_block_9_type:4;
        RBus_UInt32  smd_zoommotion_estimation_min_sad:8;
    };
}di_im_di_zoommotion_det_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_8_type:4;
        RBus_UInt32  smd_zoommotion_block_7_type:4;
        RBus_UInt32  smd_zoommotion_block_6_type:4;
        RBus_UInt32  smd_zoommotion_block_5_type:4;
        RBus_UInt32  smd_zoommotion_block_4_type:4;
        RBus_UInt32  smd_zoommotion_block_3_type:4;
        RBus_UInt32  smd_zoommotion_block_2_type:4;
        RBus_UInt32  smd_zoommotion_block_1_type:4;
    };
}di_im_di_zoommotion_det_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_1_max:16;
        RBus_UInt32  smd_zoommotion_block_1_total:16;
    };
}di_im_di_zoommotion_det_info_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_2_max:16;
        RBus_UInt32  smd_zoommotion_block_2_total:16;
    };
}di_im_di_zoommotion_det_info_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_3_max:16;
        RBus_UInt32  smd_zoommotion_block_3_total:16;
    };
}di_im_di_zoommotion_det_info_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_4_max:16;
        RBus_UInt32  smd_zoommotion_block_4_total:16;
    };
}di_im_di_zoommotion_det_info_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_5_max:16;
        RBus_UInt32  smd_zoommotion_block_5_total:16;
    };
}di_im_di_zoommotion_det_info_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_6_max:16;
        RBus_UInt32  smd_zoommotion_block_6_total:16;
    };
}di_im_di_zoommotion_det_info_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_7_max:16;
        RBus_UInt32  smd_zoommotion_block_7_total:16;
    };
}di_im_di_zoommotion_det_info_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_8_max:16;
        RBus_UInt32  smd_zoommotion_block_8_total:16;
    };
}di_im_di_zoommotion_det_info_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_9_max:16;
        RBus_UInt32  smd_zoommotion_block_9_total:16;
    };
}di_im_di_zoommotion_det_info_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_ma_framemtha:8;
        RBus_UInt32  smd_zoommotion_ma_framehtha:8;
        RBus_UInt32  smd_zoommotion_ma_framerlvtha:8;
        RBus_UInt32  smd_zoommotion_ma_framestha:8;
    };
}di_im_di_zoommotion_det_fm_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_ma_framemthb:8;
        RBus_UInt32  smd_zoommotion_ma_framehthb:8;
        RBus_UInt32  smd_zoommotion_ma_framerlvthb:8;
        RBus_UInt32  smd_zoommotion_ma_framesthb:8;
    };
}di_im_di_zoommotion_det_fm_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_ma_framemthc:8;
        RBus_UInt32  smd_zoommotion_ma_framehthc:8;
        RBus_UInt32  smd_zoommotion_ma_framerlvthc:8;
        RBus_UInt32  smd_zoommotion_ma_framesthc:8;
    };
}di_im_di_zoommotion_det_fm_th_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_continue_th:4;
        RBus_UInt32  smd_slowmotion_continue_count:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_slowmotion_flag:1;
        RBus_UInt32  smd_slowmotion_vector_ratio:6;
        RBus_UInt32  smd_slowmotion_min_sad_class_high:4;
        RBus_UInt32  smd_slowmotion_min_sad_class_low:4;
        RBus_UInt32  res2:7;
        RBus_UInt32  smd_slowmotion_en:1;
    };
}di_im_di_slowmotion_detector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_vcompenen_count:16;
        RBus_UInt32  smd_slowmotion_count:16;
    };
}di_im_di_slowmotion_detector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_ma_framemtha:8;
        RBus_UInt32  smd_slowmotion_ma_framehtha:8;
        RBus_UInt32  smd_slowmotion_ma_framerlvtha:8;
        RBus_UInt32  smd_slowmotion_ma_framestha:8;
    };
}di_im_di_slowmotion_det_fm_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_ma_framemthb:8;
        RBus_UInt32  smd_slowmotion_ma_framehthb:8;
        RBus_UInt32  smd_slowmotion_ma_framerlvthb:8;
        RBus_UInt32  smd_slowmotion_ma_framesthb:8;
    };
}di_im_di_slowmotion_det_fm_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_ma_framemthc:8;
        RBus_UInt32  smd_slowmotion_ma_framehthc:8;
        RBus_UInt32  smd_slowmotion_ma_framerlvthc:8;
        RBus_UInt32  smd_slowmotion_ma_framesthc:8;
    };
}di_im_di_slowmotion_det_fm_th_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r16_pixelsum:16;
        RBus_UInt32  hmc_r15_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r14_pixelsum:16;
        RBus_UInt32  hmc_r13_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r12_pixelsum:16;
        RBus_UInt32  hmc_r11_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r10_pixelsum:16;
        RBus_UInt32  hmc_r9_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r8_pixelsum:16;
        RBus_UInt32  hmc_l8_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l9_pixelsum:16;
        RBus_UInt32  hmc_l10_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l11_pixelsum:16;
        RBus_UInt32  hmc_l12_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l13_pixelsum:16;
        RBus_UInt32  hmc_l14_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l15_pixelsum:16;
        RBus_UInt32  hmc_l16_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_en:1;
        RBus_UInt32  gst_debug_fmv2weave:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  gst_pregmv_needstable:1;
        RBus_UInt32  gst_replace_sad:1;
        RBus_UInt32  gst_search_zmv_offset:6;
        RBus_UInt32  gst_fmv2weave_p:4;
        RBus_UInt32  gst_fmv2weave_n:4;
    };
}di_di_gst_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  gst_enter_origsad_lowth:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  gst_enter_origsad_offset:9;
    };
}di_di_gst_enter_origsadcheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_outofrange_check:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  gst_outofrange_origsad:8;
        RBus_UInt32  gst_outofrange_fracsadlowth:8;
        RBus_UInt32  gst_outofrange_fracsad_offset:8;
    };
}di_di_gst_outofrangecheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_freqnonmatch_check:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  gst_freqnonmatch_origsad:8;
        RBus_UInt32  gst_freqnonmatch_fracsad_lowth:8;
        RBus_UInt32  gst_freqnonmatch_fracsad_offset:8;
    };
}di_di_gst_freqnonmatchcheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_gmv_sad_th:7;
        RBus_UInt32  smd_gmv_sad_max:8;
        RBus_UInt32  smd_localmv_sad_max:8;
        RBus_UInt32  smd_spatialmv_sad_max:8;
    };
}di_di_smd_candidatelimitsad_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his00:16;
        RBus_UInt32  gst_fmv_his01:16;
    };
}di_di_gst_fmvhisa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his02:16;
        RBus_UInt32  gst_fmv_his03:16;
    };
}di_di_gst_fmvhisb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his04:16;
        RBus_UInt32  gst_fmv_his05:16;
    };
}di_di_gst_fmvhisc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his06:16;
        RBus_UInt32  gst_fmv_his07:16;
    };
}di_di_gst_fmvhisd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his08:16;
        RBus_UInt32  gst_fmv_his09:16;
    };
}di_di_gst_fmvhise_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  gst_fmv_his10:16;
    };
}di_di_gst_fmvhisf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his11:16;
        RBus_UInt32  gst_fmv_his12:16;
    };
}di_di_gst_fmvhisg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his13:16;
        RBus_UInt32  gst_fmv_his14:16;
    };
}di_di_gst_fmvhish_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his15:16;
        RBus_UInt32  gst_fmv_his16:16;
    };
}di_di_gst_fmvhisi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his17:16;
        RBus_UInt32  gst_fmv_his18:16;
    };
}di_di_gst_fmvhisj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his19:16;
        RBus_UInt32  gst_fmv_his20:16;
    };
}di_di_gst_fmvhisk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_mv_refine_mor_en:1;
        RBus_UInt32  hmc_dynamic_threshold_min_clip:3;
        RBus_UInt32  hmc_mv_refine_y_th:8;
        RBus_UInt32  mc_dynamic_threshold_clip_en:1;
        RBus_UInt32  hmc_mv_refine_en:1;
        RBus_UInt32  hmc_odd_mv_no_compesation:1;
        RBus_UInt32  hmc_even_mv_no_vectorteeth:1;
        RBus_UInt32  hme_max_absolute_count:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  hme_sobel_search_min:4;
    };
}di_im_di_hmc_adjustable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_x_continued_counter:4;
        RBus_UInt32  hmc_mv_refine_mor_noise_th:4;
        RBus_UInt32  res1:2;
        RBus_UInt32  hmc_mv_refine_mor_zero_th1_hh:6;
        RBus_UInt32  hmc_follow_ma_result_en:1;
        RBus_UInt32  hmc_mv_refine_cur_motion_en:1;
        RBus_UInt32  hmc_mv_refine_mor_same_th1_hh:6;
        RBus_UInt32  hmc_mv_refine_cur_motion_th:8;
    };
}di_im_di_hmc_adjustable2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  hmc_mv_refine_mor_zero_th2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hmc_mv_refine_mor_same_th2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hmc_mv_refine_mor_zero_th1:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  hmc_mv_refine_mor_same_th1:6;
    };
}di_im_di_hmc_adjustable3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_mv_refine_sobel_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hmc_mv_refine_sobel_non_edge_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  hmc_mv_refine_sobel_diff_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hmc_mv_refine_mor_hh_h_th:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  hmc_mv_refine_mor_hh_v_th:5;
    };
}di_im_di_hmc_adjustable4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scene_change_cond1_en:1;
        RBus_UInt32  scene_change_cond2_en:1;
        RBus_UInt32  scene_change_cond1_result:1;
        RBus_UInt32  scene_change_cond2_result:1;
        RBus_UInt32  scene_change_debug_en:1;
        RBus_UInt32  scene_change_cond1_th:11;
        RBus_UInt32  scene_change_cond2_th:16;
    };
}di_im_di_sc_adjustment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18024660_31_24:8;
        RBus_UInt32  hmc_half_mv_blending_en:1;
        RBus_UInt32  hmc_vertical_intra_en:1;
        RBus_UInt32  hmc_mv_refine_sub_px_mv_en:1;
        RBus_UInt32  hme_prefer_even_mv_en:1;
        RBus_UInt32  hme_avoid_rltype_vertical_pan_en:1;
        RBus_UInt32  hme_consider_mv_invalid_en:1;
        RBus_UInt32  hme_check_zero_mv_en:1;
        RBus_UInt32  pan_mc_compensation_vertical_intra_en:1;
        RBus_UInt32  pan_mc_adaptive_compensation_en:1;
        RBus_UInt32  pan_me_sub_pixel_mv_det_en:1;
        RBus_UInt32  pan_mc_rls_en:1;
        RBus_UInt32  pan_me_invalid_check_en:1;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_en:1;
        RBus_UInt32  pan_mc_force_compensation_en:1;
        RBus_UInt32  pan_me_select_mv_hist:1;
        RBus_UInt32  hmc_debug_en:1;
        RBus_UInt32  pan_mc_debug_en:1;
        RBus_UInt32  pan_me_fw_control_motion_vector:6;
        RBus_UInt32  pan_me_fw_control_motion_vector_det:1;
    };
}di_im_di_hmc_pan_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_3:4;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_2:4;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_1:4;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_th2:6;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_th1:6;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_th0:6;
    };
}di_im_di_hmc_pan_add_bias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  pan_mc_rls_sobel_diff_min_th:5;
        RBus_UInt32  pan_me_invalid_check_maxmin_diff_thd:5;
        RBus_UInt32  pan_me_invalid_check_cnt_thd:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  hme_sum_max_ratio:7;
    };
}di_im_di_hmc_pan_control_par_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_sub_pixel_diff_thd:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  hme_prefer_even_mv_ratio:5;
        RBus_UInt32  hme_avoid_rltype_vertical_pan_nedge_thd:4;
        RBus_UInt32  hme_avoid_rltype_vertical_pan_rledge_thd:5;
        RBus_UInt32  pan_mc_adaptive_compensation_teeth_thd:8;
    };
}di_im_di_hmc_pan_control_par_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_vertical_intra_edge_yuv_diff:8;
        RBus_UInt32  hmc_vertical_intra_top_bot_diff_v:8;
        RBus_UInt32  hmc_vertical_intra_top_bot_diff_u:8;
        RBus_UInt32  hmc_vertical_intra_top_bot_diff_y:8;
    };
}di_im_di_hmc_pan_vertical_intra_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hmc_vertical_intra_top_cur_diff_v:8;
        RBus_UInt32  hmc_vertical_intra_top_cur_diff_u:8;
        RBus_UInt32  hmc_vertical_intra_top_cur_diff_y:8;
    };
}di_im_di_hmc_pan_vertical_intra_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hmc_vertical_intra_cur_bot_diff_v:8;
        RBus_UInt32  hmc_vertical_intra_cur_bot_diff_u:8;
        RBus_UInt32  hmc_vertical_intra_cur_bot_diff_y:8;
    };
}di_im_di_hmc_pan_vertical_intra_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  restIdxThd:16;
        RBus_UInt32  restIdx:6;
        RBus_UInt32  diffMinThd:10;
    };
}di_im_di_hmc_pan_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  panConti:8;
        RBus_UInt32  panConti_str:8;
        RBus_UInt32  diffMaxMin:16;
    };
}di_im_di_hmc_pan_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy:16;
        RBus_UInt32  panDeb:8;
        RBus_UInt32  panDeb_str:8;
    };
}di_im_di_hmc_pan_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor5:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor4:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor3:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor2:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor1:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  rtnr_ma_snr_debug_mode_selection:2;
        RBus_UInt32  rtnr_ma_snr_debug_mode_en:1;
        RBus_UInt32  rtnr_ma_snr_mask:1;
        RBus_UInt32  rtnr_ma_snr_en:1;
    };
}di_rtnr_ma_snr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_motion_th4_low:8;
        RBus_UInt32  rtnr_ma_snr_motion_th3_low:8;
        RBus_UInt32  rtnr_ma_snr_motion_th2_low:8;
        RBus_UInt32  rtnr_ma_snr_motion_th1_low:8;
    };
}di_rtnr_ma_snr_motion_th_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_motion_th4_high:8;
        RBus_UInt32  rtnr_ma_snr_motion_th3_high:8;
        RBus_UInt32  rtnr_ma_snr_motion_th2_high:8;
        RBus_UInt32  rtnr_ma_snr_motion_th1_high:8;
    };
}di_rtnr_ma_snr_motion_th_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rtnr_ma_snr_edge_th_high:8;
        RBus_UInt32  rtnr_ma_snr_edge_th_low:8;
    };
}di_rtnr_ma_snr_motion_edge_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_motion_slope4:8;
        RBus_UInt32  rtnr_ma_snr_motion_slope3:8;
        RBus_UInt32  rtnr_ma_snr_motion_slope2:8;
        RBus_UInt32  rtnr_ma_snr_motion_slope1:8;
    };
}di_rtnr_ma_snr_motion_th_slope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  rtnr_ma_snr_strength:4;
        RBus_UInt32  rtnr_ma_snr_output_clamp:8;
        RBus_UInt32  rtnr_ma_snr_edge_curve_slope:8;
        RBus_UInt32  rtnr_ma_snr_edge_curve_lo_th:8;
    };
}di_rtnr_ma_snr_strength_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_fw_ydiff:8;
        RBus_UInt32  nm_fw_yref:8;
        RBus_UInt32  res1:3;
        RBus_UInt32  nm_samplingbit:5;
        RBus_UInt32  res2:1;
        RBus_UInt32  nm_debug_conti:1;
        RBus_UInt32  nm_varsel:2;
        RBus_UInt32  nm_ref_y_en:1;
        RBus_UInt32  nm_debug_en:1;
        RBus_UInt32  nm_pixmove_en:1;
        RBus_UInt32  nm_start:1;
    };
}di_di_rtnr_nm_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  nm_meandiff_thd:5;
        RBus_UInt32  nm_vardiff_thd:16;
    };
}di_di_rtnr_nm_varmean_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_varhigh_thd:16;
        RBus_UInt32  nm_varlow_thd:16;
    };
}di_di_rtnr_nm_var_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nm_bottommargin:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  nm_topmargin:12;
    };
}di_di_rtnr_nm_margin0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  nm_rightmargin:12;
        RBus_UInt32  res2:4;
        RBus_UInt32  nm_leftmargin:12;
    };
}di_di_rtnr_nm_margin1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd3:8;
        RBus_UInt32  noiselevel_thd2:8;
        RBus_UInt32  noiselevel_thd1:8;
        RBus_UInt32  noiselevel_thd0:8;
    };
}di_di_rtnr_nm_noiselevel_th0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd7:8;
        RBus_UInt32  noiselevel_thd6:8;
        RBus_UInt32  noiselevel_thd5:8;
        RBus_UInt32  noiselevel_thd4:8;
    };
}di_di_rtnr_nm_noiselevel_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd11:8;
        RBus_UInt32  noiselevel_thd10:8;
        RBus_UInt32  noiselevel_thd9:8;
        RBus_UInt32  noiselevel_thd8:8;
    };
}di_di_rtnr_nm_noiselevel_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  noiselevel_thd14:8;
        RBus_UInt32  noiselevel_thd13:8;
        RBus_UInt32  noiselevel_thd12:8;
    };
}di_di_rtnr_nm_noiselevel_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  nm_sumvarnum:21;
        RBus_UInt32  nm_noiselevel:4;
    };
}di_di_rtnr_nm_infor1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  nm_sumvar:24;
    };
}di_di_rtnr_nm_infor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_0:20;
    };
}di_di_rtnr_nm_hist1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_1:20;
    };
}di_di_rtnr_nm_hist1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_2:20;
    };
}di_di_rtnr_nm_hist1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_3:20;
    };
}di_di_rtnr_nm_hist1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_4:20;
    };
}di_di_rtnr_nm_hist1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_5:20;
    };
}di_di_rtnr_nm_hist1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_6:20;
    };
}di_di_rtnr_nm_hist1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_7:20;
    };
}di_di_rtnr_nm_hist1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_8:20;
    };
}di_di_rtnr_nm_hist1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_9:20;
    };
}di_di_rtnr_nm_hist1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_10:20;
    };
}di_di_rtnr_nm_hist1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_11:20;
    };
}di_di_rtnr_nm_hist1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_12:20;
    };
}di_di_rtnr_nm_hist1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_13:20;
    };
}di_di_rtnr_nm_hist1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_14:20;
    };
}di_di_rtnr_nm_hist1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist1_15:20;
    };
}di_di_rtnr_nm_hist1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_0:20;
    };
}di_di_rtnr_nm_hist2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_1:20;
    };
}di_di_rtnr_nm_hist2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_2:20;
    };
}di_di_rtnr_nm_hist2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_3:20;
    };
}di_di_rtnr_nm_hist2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_4:20;
    };
}di_di_rtnr_nm_hist2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_5:20;
    };
}di_di_rtnr_nm_hist2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_6:20;
    };
}di_di_rtnr_nm_hist2_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_7:20;
    };
}di_di_rtnr_nm_hist2_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_8:20;
    };
}di_di_rtnr_nm_hist2_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_9:20;
    };
}di_di_rtnr_nm_hist2_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_10:20;
    };
}di_di_rtnr_nm_hist2_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_11:20;
    };
}di_di_rtnr_nm_hist2_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_12:20;
    };
}di_di_rtnr_nm_hist2_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_13:20;
    };
}di_di_rtnr_nm_hist2_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_14:20;
    };
}di_di_rtnr_nm_hist2_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  hist2_15:20;
    };
}di_di_rtnr_nm_hist2_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_0:24;
    };
}di_di_rtnr_nm_hist2var_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_1:24;
    };
}di_di_rtnr_nm_hist2var_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_2:24;
    };
}di_di_rtnr_nm_hist2var_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_3:24;
    };
}di_di_rtnr_nm_hist2var_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_4:24;
    };
}di_di_rtnr_nm_hist2var_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_5:24;
    };
}di_di_rtnr_nm_hist2var_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_6:24;
    };
}di_di_rtnr_nm_hist2var_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_7:24;
    };
}di_di_rtnr_nm_hist2var_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_8:24;
    };
}di_di_rtnr_nm_hist2var_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_9:24;
    };
}di_di_rtnr_nm_hist2var_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_10:24;
    };
}di_di_rtnr_nm_hist2var_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_11:24;
    };
}di_di_rtnr_nm_hist2var_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_12:24;
    };
}di_di_rtnr_nm_hist2var_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_13:24;
    };
}di_di_rtnr_nm_hist2var_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_14:24;
    };
}di_di_rtnr_nm_hist2var_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  hist2var_15:24;
    };
}di_di_rtnr_nm_hist2var_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  rtnr_output_clamp_en:1;
        RBus_UInt32  rtnr_output_clamp_chroma:8;
        RBus_UInt32  rtnr_output_clamp_luma:8;
    };
}di_rtnr_output_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_water_en:1;
        RBus_UInt32  smd_debugwaterflag:1;
        RBus_UInt32  smd_water_pan_disable:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_water_result:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  smd_water_gain:2;
        RBus_UInt32  smd_water_offset:8;
        RBus_UInt32  res3:4;
        RBus_UInt32  smd_water_modeth:4;
    };
}di_di_smd_waterflag_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_water_uv_offset:8;
        RBus_UInt32  smd_water_intradiff_th:8;
        RBus_UInt32  smd_water_minteethy:8;
        RBus_UInt32  smd_water_teeth:8;
    };
}di_di_smd_waterflag_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_elseintra_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_stillsad_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_stillsad_max:5;
        RBus_UInt32  smd_water_avgy_offset:8;
        RBus_UInt32  smd_water_avgy_lowbound:8;
    };
}di_di_smd_waterflag_ctr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_hardwarepan_firststep:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_streammv_gmv_diff:5;
        RBus_UInt32  smd_gmvb_sadmin_th:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_firmwarepan_sadmax:9;
        RBus_UInt32  smd_searchmvapply_ctr:8;
    };
}di_di_smd_hardwarepan_modify1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_gmvc_x:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_gmvc_y:3;
        RBus_UInt32  smd_close2gmv_mvselect:2;
        RBus_UInt32  smd_pg_diffsad_th:6;
        RBus_UInt32  smd_pg_messlevel_th:8;
        RBus_UInt32  smd_pg_minsad_th:8;
    };
}di_di_smd_sampling_gmvc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_close2gmv_minctr:8;
        RBus_UInt32  smd_close2gmv_edgectr:8;
        RBus_UInt32  smd_pg_close2gmv:1;
        RBus_UInt32  smd_vmin_sad_ctr:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_hmin_sad_ctr:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_gmvb_x:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_gmvb_y:3;
    };
}di_di_smd_sampling_gmvb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_subpixel_compensate_en:1;
        RBus_UInt32  gst_debug_subpixel_pan:1;
        RBus_UInt32  gst_subpixel_hardwarepan_en:1;
        RBus_UInt32  gst_subpixel_rlv2intra_en:1;
        RBus_UInt32  gst_integerpan_highpriority:1;
        RBus_UInt32  gst_pg_highpriority:1;
        RBus_UInt32  gst_compensate_fmv0_en:1;
        RBus_UInt32  gst_compensate_fmv1_en:1;
        RBus_UInt32  gst_compensate_fmv2_en:1;
        RBus_UInt32  gst_compensate_fmv3_en:1;
        RBus_UInt32  gst_compensate_fmv4_en:1;
        RBus_UInt32  gst_compensate_fmv5_en:1;
        RBus_UInt32  gst_compensate_fmv6_en:1;
        RBus_UInt32  gst_compensate_fmv7_en:1;
        RBus_UInt32  gst_compensate_fmv8_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  gst_compensate_blending_en:1;
        RBus_UInt32  gst_blend_weight:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  gst_subpixel_firmwarepan:1;
        RBus_UInt32  gst_subpixel_firmwarepan_fmv2:4;
        RBus_UInt32  gst_subpixel_firmwarepan_fmv1:4;
    };
}di_di_gst_compensate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  gst_maxfmv_0:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  gst_maxfmv_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  gst_maxfmv_2:6;
        RBus_UInt32  res4:2;
        RBus_UInt32  gst_maxfmv_3:6;
    };
}di_di_gst_maxfmv_part1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  gst_maxfmv_4:6;
        RBus_UInt32  gst_maxfmv_ctr4:16;
    };
}di_di_gst_maxfmv_part2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_maxfmv_ctr0:16;
        RBus_UInt32  gst_maxfmv_ctr1:16;
    };
}di_di_gst_maxfmv_part3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_maxfmv_ctr2:16;
        RBus_UInt32  gst_maxfmv_ctr3:16;
    };
}di_di_gst_maxfmv_part4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_subpixel_pan_ratio:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  gst_subpixel_firmwarepan_sadmin:6;
        RBus_UInt32  res2:7;
        RBus_UInt32  gst_subpixel_firmwarepan_sadmax:9;
    };
}di_di_gst_fmv_pan_coeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  gst_fmvhist_sad_diff:6;
        RBus_UInt32  gst_maxfmv_diff_th:8;
        RBus_UInt32  gst_quantizeddiff_offset:8;
        RBus_UInt32  res2:3;
        RBus_UInt32  gst_quantizeddiff_gain:5;
    };
}di_di_gst_fmv_pan_coeff2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_weavemode_check_en:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  ma_weavemode_check_gain:4;
        RBus_UInt32  ma_weavemode_check_th:8;
    };
}di_di_ma_weavemode_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_r5_sum:16;
        RBus_UInt32  hmcnr_r4_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_r3_sum:16;
        RBus_UInt32  hmcnr_r2_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_r1_sum:16;
        RBus_UInt32  hmcnr_c0_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_l1_sum:16;
        RBus_UInt32  hmcnr_l2_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_l3_sum:16;
        RBus_UInt32  hmcnr_l4_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_l5_sum:16;
        RBus_UInt32  dummy18024858_15_0:16;
    };
}di_im_di_rtnr_hmcnr_statistic_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_temporal_mad_y_th3:11;
        RBus_UInt32  res2:5;
        RBus_UInt32  cp_temporal_mad_c_th3:11;
    };
}di_im_di_rtnr_mad_y_th2_c_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_countery2:21;
    };
}di_im_di_rtnr_mad_y_counter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_countery3:21;
    };
}di_im_di_rtnr_mad_y_counter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_counteru2:21;
    };
}di_im_di_rtnr_mad_u_counter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_counteru3:21;
    };
}di_im_di_rtnr_mad_u_counter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_counterv2:21;
    };
}di_im_di_rtnr_mad_v_counter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:11;
        RBus_UInt32  cp_temporal_mad_counterv3:21;
    };
}di_im_di_rtnr_mad_v_counter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_v_down_scale_factor:3;
        RBus_UInt32  res2:7;
        RBus_UInt32  memc_prgfilm_fw_film_idx:5;
        RBus_UInt32  memc_prgfilm_motion_th:8;
        RBus_UInt32  memc_prgfilm_motion_cnt_avg_auto:1;
        RBus_UInt32  memc_prgfilm_32_auto:1;
        RBus_UInt32  memc_prgfilm_22_auto:1;
        RBus_UInt32  memc_prgfilm_32_en:1;
        RBus_UInt32  memc_prgfilm_22_en:1;
    };
}di_memc_p_film_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  memc_prgfilm_32_detect_num:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  memc_prgfilm_22_detect_num:5;
    };
}di_memc_p_film_fr_num_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_easy_stay_mode_32:1;
        RBus_UInt32  memc_easy_stay_mode_22:1;
        RBus_UInt32  memc_prgfilm_fw_32_detected:1;
        RBus_UInt32  memc_prgfilm_fw_22_detected:1;
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_prgfilm_fw_motion_cnt_avg:24;
    };
}di_memc_p_film_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  memc_avg_thl_gain_01:5;
        RBus_UInt32  memc_abs_motion_thl:24;
    };
}di_memc_p_film_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  memc_prgfilm_32_detected:1;
        RBus_UInt32  memc_prgfilm_22_detected:1;
        RBus_UInt32  memc_prgfilm_film_idx:5;
        RBus_UInt32  memc_prgfilm_motion_cnt:24;
    };
}di_memc_p_film_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_p_factor:8;
        RBus_UInt32  memc_n32_duration_f:12;
        RBus_UInt32  memc_film32_duration_f:12;
    };
}di_memc_p_film_read1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_frm_cnt:10;
        RBus_UInt32  memc_pre_film32_prob:12;
        RBus_UInt32  memc_film32_freq:10;
    };
}di_memc_p_film_read2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  memc_avg_thl_gain:5;
        RBus_UInt32  memc_n22_duration_f:12;
        RBus_UInt32  memc_film22_duration_f:12;
    };
}di_memc_p_film_read3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  memc_pre_film22_prob:12;
        RBus_UInt32  memc_film22_freq:10;
    };
}di_memc_p_film_read4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_debounce_32_in_thl:10;
        RBus_UInt32  memc_debounce_32_out_thl:10;
        RBus_UInt32  memc_pass_factor:4;
        RBus_UInt32  memc_region_size_x:4;
    };
}di_memc_p_film_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  memc_fw_force_32:1;
        RBus_UInt32  memc_fw_force_22:1;
        RBus_UInt32  memc_debounce_22_in_thl:10;
        RBus_UInt32  memc_debounce_22_out_thl:10;
    };
}di_memc_p_film_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fdc_value_pre:8;
        RBus_UInt32  fdc_value:8;
        RBus_UInt32  fdc_grey_uv_range_en:1;
        RBus_UInt32  fdc_grey_uv_range:7;
    };
}di_im_di_rtnr_fading_detector_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_sum_inc:32;
    };
}di_im_di_rtnr_fading_info_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fdc_pixels_inc:24;
    };
}di_im_di_rtnr_fading_info_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_sum_dec:32;
    };
}di_im_di_rtnr_fading_info_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fdc_pixels_dec:24;
    };
}di_im_di_rtnr_fading_info_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fdc_pixels_ignore_end:24;
    };
}di_im_di_rtnr_fading_info_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  fdc_pixels_ignore_same:24;
    };
}di_im_di_rtnr_fading_info_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fm_dc_debug_en:1;
        RBus_UInt32  fm_dc_adaptive_bias_fw_ctrl:1;
        RBus_UInt32  fm_dc_adaptive_bias:6;
        RBus_UInt32  fm_dc_adaptive_pn_small_th:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  fm_dc_adaptive_same_count_th:4;
        RBus_UInt32  fm_dc_adaptive_en:1;
        RBus_UInt32  fm_dc_adaptive_same_th:7;
    };
}di_im_di_ma_fading_apply_bias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fm_noise_adaptive_en:1;
        RBus_UInt32  fm_nosie_offset_ctrl:1;
        RBus_UInt32  fm_noise_adaptive_bias:6;
        RBus_UInt32  fm_noise_offset:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  fm_adaptive_bias_max_limit:8;
    };
}di_im_di_ma_noise_apply_bias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vhf_energy_th0:8;
        RBus_UInt32  vhf_fm_offset_th4:4;
        RBus_UInt32  vhf_fm_offset_th3:4;
        RBus_UInt32  vhf_fm_offset_th2:4;
        RBus_UInt32  vhf_fm_offset_th1:4;
        RBus_UInt32  vhf_en:1;
        RBus_UInt32  vhf_check_mode:2;
        RBus_UInt32  vhf_teeth_depth_th:5;
    };
}di_im_di_ma_vhf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vhf_energy_th4:8;
        RBus_UInt32  vhf_energy_th3:8;
        RBus_UInt32  vhf_energy_th2:8;
        RBus_UInt32  vhf_energy_th1:8;
    };
}di_im_di_ma_vhf_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vhf_energy_slop4:8;
        RBus_UInt32  vhf_energy_slop3:8;
        RBus_UInt32  vhf_energy_slop2:8;
        RBus_UInt32  vhf_energy_slop1:8;
    };
}di_im_di_ma_vhf_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  nintra_ud_boundary_repeat_en:1;
        RBus_UInt32  nintra_n_check2_control_disable:1;
        RBus_UInt32  nintra_check2_y_diff_th:8;
        RBus_UInt32  nintra_lowpass_dir_count_th:4;
        RBus_UInt32  nintra_output_lowpass_en:1;
        RBus_UInt32  nintra_dyn_dir_lowpass_en:1;
        RBus_UInt32  nintra_preline_dir_check2_en:1;
        RBus_UInt32  nintra_preline_dir_check1_en:1;
        RBus_UInt32  nintra_lowpass_dir_check_en:1;
        RBus_UInt32  nintra_pre_dir_check_en:1;
        RBus_UInt32  nintra_min_second_dir_check2_en:1;
        RBus_UInt32  nintra_min_second_dir_check_en:1;
        RBus_UInt32  nintra_dynamic_cross_th_en:1;
        RBus_UInt32  nintra_intersection_check_en:1;
        RBus_UInt32  nintra_high_freq_detect_en:1;
        RBus_UInt32  nintra_search_min_limit_en:1;
        RBus_UInt32  nintra_vbound_detect_en:1;
        RBus_UInt32  nintra_ydiff_mode:1;
        RBus_UInt32  nintra_new_mode_en:1;
        RBus_UInt32  nintra_src_lpf_clamp_en:1;
    };
}di_im_di_nintra_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_lp_src_yclamp_th:8;
        RBus_UInt32  nintra_lp_src_edge_slope:8;
        RBus_UInt32  nintra_lp_src_edge_th2:8;
        RBus_UInt32  nintra_lp_src_edge_th1:8;
    };
}di_im_di_nintra_lowpass_source_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  nintra_dir_search_region_max:4;
        RBus_UInt32  nintra_hdiff_th2:8;
        RBus_UInt32  nintra_hdiff_th1:8;
    };
}di_im_di_nintra_search_dir_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  nintra_crossslope_diff_th:8;
        RBus_UInt32  nintra_crossdiff_th:8;
        RBus_UInt32  nintra_slopediff_th:8;
    };
}di_im_di_nintra_intersection_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_minsecond_diff_th3:8;
        RBus_UInt32  nintra_minsecond_diff_th2:8;
        RBus_UInt32  nintra_vertical_diff_th:8;
        RBus_UInt32  nintra_minsecond_diff_th:8;
    };
}di_im_di_nintra_1st_2nd_ydiff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  nintra_trans_count_th2:8;
        RBus_UInt32  nintra_trans_count_th1:8;
        RBus_UInt32  nintra_hfq_hdiff_th:8;
    };
}di_im_di_nintra_high_freq_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_rf_c2_lineminindex_mv_bin_cnt_th:8;
        RBus_UInt32  hme_rf_c2_mv_lineminindex_range_th:4;
        RBus_UInt32  hme_rf_c2_2mv_bin_ratio_th:4;
        RBus_UInt32  hme_rf_c1_2max_diff_th:8;
        RBus_UInt32  hme_rf_c1_2mv_range_th:4;
        RBus_UInt32  hme_rf_c3_en:1;
        RBus_UInt32  hme_rf_c2_en:1;
        RBus_UInt32  hme_rf_c1_en:1;
        RBus_UInt32  hme_refine_en:1;
    };
}di_im_di_hmc_me_refine_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_teeth_total:8;
        RBus_UInt32  hmc_teeth_of_line_th:8;
        RBus_UInt32  hme_rf_c3_sobeldiffinvalidcount_th:8;
        RBus_UInt32  res1:2;
        RBus_UInt32  hmc_fw_ctrl_bypass:1;
        RBus_UInt32  hme_rf_c3_max_sdinvalidcount_ratio_th:5;
    };
}di_im_di_hmc_me_refine_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_modify_dir_total:16;
        RBus_UInt32  hme_pass_total:16;
    };
}di_im_di_hmc_me_refine_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_pass_counter:16;
        RBus_UInt32  res1:8;
        RBus_UInt32  hme_rf_temporal_correction_en:1;
        RBus_UInt32  hme_rf_temporal_correction_th:7;
    };
}di_im_di_hmc_me_refine_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_fail_counter:16;
        RBus_UInt32  hmc_mv_refine_fail_counter:16;
    };
}di_im_di_hmc_me_refine_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_mcnr_mad_select:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  n_mcnr_old_search_range_en:1;
        RBus_UInt32  n_mcnr_mv_diff_max_en:1;
        RBus_UInt32  n_mcnr_smp_en:1;
        RBus_UInt32  n_mcnr_debug_mode_select:2;
        RBus_UInt32  hori_boundary_th:4;
        RBus_UInt32  n_mcnr_offset:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  n_mcnr_debug_mode_en:1;
        RBus_UInt32  n_rtnr_c_k_select:1;
        RBus_UInt32  n_mcnr_y_k_select_mc:1;
        RBus_UInt32  n_rtnr_y_k_select:1;
        RBus_UInt32  n_mcnr_weight_clamp_en:1;
        RBus_UInt32  n_mcnr_weight_avg_en:1;
        RBus_UInt32  n_c_zero_mv_k_en:1;
        RBus_UInt32  n_mv_avg_en:1;
        RBus_UInt32  n_mv_avg_mode_select:1;
        RBus_UInt32  n_mv_diff_distance_select:1;
        RBus_UInt32  n_zero_mv_gain8_en:1;
        RBus_UInt32  n_y_zero_mv_k_en:1;
        RBus_UInt32  n_h_pan_zeromv_penalty_en:1;
        RBus_UInt32  n_h_pan_flag:1;
        RBus_UInt32  n_mcnr_new_en:1;
    };
}di_im_new_mcnr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  h_pan_mv_value:5;
        RBus_UInt32  h_pan_mv_penalty:8;
    };
}di_im_new_mcnr_pan_condition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  sad_min_slope:4;
        RBus_UInt32  mv_diff_slope:4;
        RBus_UInt32  sad_min_th:8;
        RBus_UInt32  mv_diff_th:8;
    };
}di_im_new_mcnr_weighting_condition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  mcnr_weight_clamp_loth:5;
        RBus_UInt32  mcnr_weight_clamp_upth:5;
        RBus_UInt32  avg_mv_clamp_value:4;
    };
}di_im_new_mcnr_clamping_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l16_linesum:8;
        RBus_UInt32  hmc_l15_linesum:8;
        RBus_UInt32  hmc_l14_linesum:8;
        RBus_UInt32  hmc_l13_linesum:8;
    };
}di_im_di_hme_line_statistic_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l12_linesum:8;
        RBus_UInt32  hmc_l11_linesum:8;
        RBus_UInt32  hmc_l10_linesum:8;
        RBus_UInt32  hmc_l9_linesum:8;
    };
}di_im_di_hme_line_statistic_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l8_linesum:8;
        RBus_UInt32  hmc_l7_linesum:8;
        RBus_UInt32  hmc_l6_linesum:8;
        RBus_UInt32  hmc_l5_linesum:8;
    };
}di_im_di_hme_line_statistic_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l4_linesum:8;
        RBus_UInt32  hmc_l3_linesum:8;
        RBus_UInt32  hmc_l2_linesum:8;
        RBus_UInt32  hmc_l1_linesum:8;
    };
}di_im_di_hme_line_statistic_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_c0_linesum:8;
        RBus_UInt32  hmc_r1_linesum:8;
        RBus_UInt32  hmc_r2_linesum:8;
        RBus_UInt32  hmc_r3_linesum:8;
    };
}di_im_di_hme_line_statistic_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r4_linesum:8;
        RBus_UInt32  hmc_r5_linesum:8;
        RBus_UInt32  hmc_r6_linesum:8;
        RBus_UInt32  hmc_r7_linesum:8;
    };
}di_im_di_hme_line_statistic_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r8_linesum:8;
        RBus_UInt32  hmc_r9_linesum:8;
        RBus_UInt32  hmc_r10_linesum:8;
        RBus_UInt32  hmc_r11_linesum:8;
    };
}di_im_di_hme_line_statistic_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r12_linesum:8;
        RBus_UInt32  hmc_r13_linesum:8;
        RBus_UInt32  hmc_r14_linesum:8;
        RBus_UInt32  hmc_r15_linesum:8;
    };
}di_im_di_hme_line_statistic_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r16_linesum:8;
        RBus_UInt32  res1:12;
        RBus_UInt32  hmc_linesum_step_mv_diff_th:4;
        RBus_UInt32  hmc_linesum_step_tolerance:4;
        RBus_UInt32  hmc_linesum_step:4;
    };
}di_im_di_hme_line_statistic_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_comp_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  di_ddr_error_count:24;
    };
}di_di_ddr_checksum_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_127_96:32;
    };
}di_di_ddr_checksum_flag_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_95_64:32;
    };
}di_di_ddr_checksum_flag_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_63_32:32;
    };
}di_di_ddr_checksum_flag_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_31_0:32;
    };
}di_di_ddr_checksum_flag_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_127_96:32;
    };
}di_di_ddr_checksum_mask_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_95_64:32;
    };
}di_di_ddr_checksum_mask_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_63_32:32;
    };
}di_di_ddr_checksum_mask_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_31_0:32;
    };
}di_di_ddr_checksum_mask_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_mcnr_mad_min_uv_th:8;
        RBus_UInt32  n_mcnr_mad_min_th:8;
        RBus_UInt32  n_mcnr_mv_penalty:4;
        RBus_UInt32  n_mcnr_y_boundary_th:4;
        RBus_UInt32  n_mcnr_v_pre_loadok_clr:1;
        RBus_UInt32  n_mcnr_v_pre_loadok:1;
        RBus_UInt32  n_mcnr_v_search_range:2;
        RBus_UInt32  cp_temporal_hmcnr_search_range:4;
    };
}di_im_new_mcnr_control2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_sawtooth_count_th_wf:8;
        RBus_UInt32  smd_min_total_th_wf:4;
        RBus_UInt32  smd_compensate_teeth_th_wf:4;
        RBus_UInt32  smd_totalteethoffset_wf:4;
        RBus_UInt32  smd_currteethgain_wf:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_debugsawtooth_waterflow_en:1;
        RBus_UInt32  smd_waterflow_protect_en:1;
    };
}di_di_smd_waterflow_teeth_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_sawtooth_count_wf:16;
    };
}di_di_smd_waterflow_teeth_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  smd_spatial_mv_diff_gain:4;
        RBus_UInt32  smd_spatial_mv_diff_coring:4;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_odd_mvy_ma_out_select:1;
        RBus_UInt32  smd_smd_weight_out_debug_en:1;
        RBus_UInt32  smd_spatial_mv_diff_weight_en:1;
        RBus_UInt32  smd_smd_blend_clamp_en:1;
        RBus_UInt32  smd_smd_blend_lpf_en:1;
        RBus_UInt32  smd_outofrange_lpf_en:1;
    };
}di_di_smd_ma_mc_weight_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  smd_diag_count_th:3;
        RBus_UInt32  smd_intra_weight_method_vpan:1;
        RBus_UInt32  smd_intra_weight_method:1;
        RBus_UInt32  smd_mcdi2madi_debug_en:1;
        RBus_UInt32  smd_mcdi2madi_v_pan_new_en:1;
        RBus_UInt32  smd_mcdi2madi_en:1;
    };
}di_di_smd_diag_edge_protect_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_resurrectsmallwindownum2:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  smd_weight_lpf_select:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  gst_min_sad_nolimit_en:1;
        RBus_UInt32  gst_gst_static_disable:1;
        RBus_UInt32  gst_min_sad_compare_diable:1;
        RBus_UInt32  smd_linecontinous_new_condition:1;
        RBus_UInt32  smd_weave_dynamic:2;
        RBus_UInt32  smd_spatialfreqnomatch_off:1;
        RBus_UInt32  smd_acc_smd_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_sawtooth_condition_select:1;
        RBus_UInt32  smd_outofrange_content_new:1;
        RBus_UInt32  res4:1;
    };
}di_di_smd_slow_motion_handle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  gst_mv_limit:2;
        RBus_UInt32  smd_resurrectminsadth2:8;
        RBus_UInt32  smd_reliablerangesadth2:8;
    };
}di_di_smd_slow_motion_handle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_r10_sum:16;
        RBus_UInt32  mcnr_r9_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_r8_sum:16;
        RBus_UInt32  mcnr_r7_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_r6_sum:16;
        RBus_UInt32  mcnr_l6_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_l7_sum:16;
        RBus_UInt32  mcnr_l8_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_l9_sum:16;
        RBus_UInt32  mcnr_l10_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_u3_sum:16;
        RBus_UInt32  mcnr_u2_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_u1_sum:16;
        RBus_UInt32  mcnr_v0_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_d1_sum:16;
        RBus_UInt32  mcnr_d2_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_d3_sum:16;
        RBus_UInt32  mcnr_static_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  n_mcnr_mv_mad_mv_gap:2;
        RBus_UInt32  n_mcnr_mv_mad_blending_vertical_en:1;
        RBus_UInt32  n_mcnr_v_pan_mv:3;
        RBus_UInt32  n_mcnr_messlevel_th:8;
        RBus_UInt32  n_mcnr_mv_mad_mv_lo_th:4;
        RBus_UInt32  n_mcnr_mv_mad_blending_en:1;
        RBus_UInt32  n_mcnr_kfactor_lpf_large_select:1;
        RBus_UInt32  n_mcnr_kfactor_lpf_method:1;
        RBus_UInt32  n_mcnr_k_factor_lpf_en:1;
    };
}di_im_new_mcnr_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  n_mcnr_mad_uv_offset:8;
        RBus_UInt32  n_mcnr_mad_offset:8;
    };
}di_im_new_mcnr_mv_mad_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  cp_temporal_k128_mode:1;
        RBus_UInt32  cp_temporal_shiftbit_usermode:1;
        RBus_UInt32  cp_temporal_shiftbit:2;
    };
}di_im_di_rtnr_k128_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th0:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th0:8;
    };
}di_im_di_rtnr_new_sad_th_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  rtnr_statistic_motion_count_th0:5;
        RBus_UInt32  rtnr_statistic_motion_count_th8:5;
        RBus_UInt32  rtnr_statistic_motion_count_th7:5;
    };
}di_im_di_rtnr_new_sad_count_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_sad_th4:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th3:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th2:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th1:8;
    };
}di_im_di_rtnr_new_sta_motion_th_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_sad_th8:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th7:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th6:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th5:8;
    };
}di_im_di_rtnr_new_sta_motion_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_sad_th12:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th11:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th10:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th9:8;
    };
}di_im_di_rtnr_new_sta_motion_th_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th3_4_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th2_3_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th1_2_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th0_1_slope:8;
    };
}di_im_di_rtnr_new_sad_edge_slope_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th7_8_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th6_7_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th5_6_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th4_5_slope:8;
    };
}di_im_di_rtnr_new_sad_edge_slope_4_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th3_4_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th2_3_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th1_2_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th0_1_slope:8;
    };
}di_im_di_rtnr_new_sad_nonedge_slope_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th7_8_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th6_7_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th5_6_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th4_5_slope:8;
    };
}di_im_di_rtnr_new_sad_nonedge_slope_4_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_count_th3_4_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th2_3_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th1_2_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th0_1_slope:8;
    };
}di_im_di_rtnr_new_sta_motion_slope_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_count_th7_8_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th6_7_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th5_6_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th4_5_slope:8;
    };
}di_im_di_rtnr_new_sta_motion_slope_4_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_87:4;
        RBus_UInt32  rtnr_k_86:4;
        RBus_UInt32  rtnr_k_85:4;
        RBus_UInt32  rtnr_k_84:4;
        RBus_UInt32  rtnr_k_83:4;
        RBus_UInt32  rtnr_k_82:4;
        RBus_UInt32  rtnr_k_81:4;
        RBus_UInt32  rtnr_k_80:4;
    };
}di_im_di_rtnr_new_k_80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_78:4;
        RBus_UInt32  rtnr_k_68:4;
        RBus_UInt32  rtnr_k_58:4;
        RBus_UInt32  rtnr_k_48:4;
        RBus_UInt32  rtnr_k_38:4;
        RBus_UInt32  rtnr_k_28:4;
        RBus_UInt32  rtnr_k_18:4;
        RBus_UInt32  rtnr_k_08:4;
    };
}di_im_di_rtnr_new_k_remain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rtnr_k_88:4;
    };
}di_im_di_rtnr_new_k_remain_1_RBUS;

#else //apply LITTLE_ENDIAN

//======DI register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_preferintra:1;
        RBus_UInt32  ma_onedirectionweaveen:1;
        RBus_UInt32  ma_controlmode:2;
        RBus_UInt32  ma_3aenable:1;
        RBus_UInt32  ma_messintra90:1;
        RBus_UInt32  ma_smoothintra90:1;
        RBus_UInt32  ma_stilllogoena:1;
        RBus_UInt32  ma_horicomen:1;
        RBus_UInt32  dummy18024000_9:1;
        RBus_UInt32  film_enable:5;
        RBus_UInt32  intra_interpolationrange:4;
        RBus_UInt32  intra_mfilterenable:1;
        RBus_UInt32  intra_stage2enable:1;
        RBus_UInt32  intra_stage1enable:1;
        RBus_UInt32  intra_lowangleenable:1;
        RBus_UInt32  cp_temporalenable:1;
        RBus_UInt32  cp_tresultweight:3;
        RBus_UInt32  di444to422lowpass:1;
        RBus_UInt32  ip_enable:1;
        RBus_UInt32  film22_filter_andor:1;
        RBus_UInt32  film_sawtooth_choose:2;
    };
}di_im_di_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_bist_clkmux_en:1;
        RBus_UInt32  di_wrapper_en:1;
        RBus_UInt32  di_clock_gating_disable:1;
        RBus_UInt32  framemotion_pxs_sel:1;
        RBus_UInt32  dma_force_4buf:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  di_l_drop_odd_line:1;
        RBus_UInt32  di_r_drop_odd_line:1;
        RBus_UInt32  di_half_frame_en:1;
        RBus_UInt32  cr_autoimg_enable:1;
        RBus_UInt32  cr_fh_switch:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  game_mode_3a:1;
        RBus_UInt32  c10bitsin:1;
        RBus_UInt32  y10bitsin:1;
        RBus_UInt32  fun_y_en:1;
    };
}di_color_recovery_option_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_tnrdebugmode:1;
        RBus_UInt32  ma_modeselect:1;
        RBus_UInt32  ma_debugmode:3;
        RBus_UInt32  film_debugmode:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  auto_freeze:1;
        RBus_UInt32  auto_frz_num:3;
        RBus_UInt32  unfreeze_polarity:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  readstart:13;
        RBus_UInt32  res3:1;
        RBus_UInt32  di_3d_l_flag:1;
        RBus_UInt32  field_confuse:1;
    };
}di_im_di_debug_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hblksize:10;
        RBus_UInt32  vsize:10;
        RBus_UInt32  hsize:11;
        RBus_UInt32  singlefieldintra:1;
    };
}di_im_di_active_window_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fixedwindow0:1;
        RBus_UInt32  fixedwindow1:1;
        RBus_UInt32  fixedwindow2:1;
        RBus_UInt32  fixedwindow3:1;
        RBus_UInt32  fixedwindow4:1;
        RBus_UInt32  fixedwindow5:1;
        RBus_UInt32  dellineen:1;
        RBus_UInt32  delpixelen:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  force2d:1;
        RBus_UInt32  freeze:1;
        RBus_UInt32  hblksize_msb:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  vsize_msb:2;
        RBus_UInt32  hsize_msb:2;
        RBus_UInt32  boundary_inter_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  ccdinr_memshare_en:1;
        RBus_UInt32  fixedwindowmode:2;
    };
}di_im_di_weave_window_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xstart_12_0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_12_0:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_0_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xend_12_0:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_12_0:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_0_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xstart_25_13:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_25_13:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_1_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xend_25_13:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_25_13:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_1_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xstart_38_26:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_38_26:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_2_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xend_38_26:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_38_26:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_2_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xstart_51_39:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_51_39:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_3_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xend_51_39:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_51_39:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_3_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xstart_64_52:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_64_52:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_4_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xend_64_52:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_64_52:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_4_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xstart_77_65:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  ystart_77_65:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_5_start_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  xend_77_65:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  yend_77_65:13;
        RBus_UInt32  res2:3;
    };
}di_im_di_weave_window_5_end_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_class_h_th2:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ma_class_h_th1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ma_class_h_th1_cmp:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  pseudo_memc_film22_weight1:2;
        RBus_UInt32  pseudo_memc_film22_weight0:2;
        RBus_UInt32  pseudo_memc_film22_sequence:2;
        RBus_UInt32  res4:2;
    };
}di_im_di_classify_thclassify_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_blend01_weight:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ma_blend10_weight:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  ma_blend_fmcomb0:2;
        RBus_UInt32  ma_blend_fmcomb1:2;
        RBus_UInt32  ma_blend_fmcomb1_hor:2;
        RBus_UInt32  ma_blend_fmcomb2:2;
        RBus_UInt32  ma_blend_fmcomb3:2;
        RBus_UInt32  pseudo_memc_film32_weight3:2;
        RBus_UInt32  pseudo_memc_film32_weight2:2;
        RBus_UInt32  pseudo_memc_film32_weight1:2;
        RBus_UInt32  pseudo_memc_film32_weight0:2;
        RBus_UInt32  pseudo_memc_film32_sequence:4;
        RBus_UInt32  dummy18024048_30_30:1;
        RBus_UInt32  pseudo_memc_en:1;
    };
}di_im_di_blend_and_weighting_method_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  force_dma_2d:1;
        RBus_UInt32  force_dma_intra:1;
        RBus_UInt32  force_di_nxt:1;
        RBus_UInt32  dummy1802404c_6:4;
        RBus_UInt32  vodma_film_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  force_2d_timing_mode:1;
        RBus_UInt32  force_2d_timing_en:1;
        RBus_UInt32  ma_sobelths:10;
        RBus_UInt32  ma_sobelthm:10;
        RBus_UInt32  dummy1802404c_31:1;
    };
}di_im_di_mpeg_sequence_app_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_class_rlv_th2:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  ma_class_rlv_th1:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  ma_class_rlv_th1_cmp:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  ma_class_s_th2:5;
        RBus_UInt32  ma_vedge_nolp_en:3;
    };
}di_im_di_classify2_thclassify_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_vedge_force_intra_en:1;
        RBus_UInt32  ma_vedge_force90_en:1;
        RBus_UInt32  ma_vedge_nonlpfm_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ma_vedge_add_rlv:2;
        RBus_UInt32  res2:25;
        RBus_UInt32  ma_new_class_en:1;
    };
}di_im_di_new_class_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  linesize_odd:11;
        RBus_UInt32  res1:1;
        RBus_UInt32  linesize_even:11;
        RBus_UInt32  dma_444to422_lowpass_boundary_duplicate:1;
        RBus_UInt32  dma_444to422_drop:1;
        RBus_UInt32  dma_444to422_cr_dly_cb:1;
        RBus_UInt32  dma_422to444_duplicate:1;
        RBus_UInt32  dma_422to444_cr_dly_cb:1;
        RBus_UInt32  dma_422to444_boundary_duplicate:1;
        RBus_UInt32  rdma_random_en:1;
        RBus_UInt32  dma_420_en:2;
    };
}di_im_di_dma_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_var1thl:8;
        RBus_UInt32  cr_var2thl:8;
        RBus_UInt32  cr_var3thl:8;
        RBus_UInt32  cr_var4thl:8;
    };
}di_im_di_xc_auto_balance_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_meanthl:8;
        RBus_UInt32  cr_transitionthl:8;
        RBus_UInt32  res1:13;
        RBus_UInt32  autoimg_debug_enable:1;
        RBus_UInt32  autoimg_lpf_enable:1;
        RBus_UInt32  bcclowpassyenablecontrol:1;
    };
}di_im_di_xc_auto_balance_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_thl_subbalance:16;
        RBus_UInt32  cr_thl_mainbalance:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_xc_auto_balance_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_motionthlc:8;
        RBus_UInt32  intra_motionthly:8;
        RBus_UInt32  stillline_cntns_en:1;
        RBus_UInt32  stilllinecntns_apply_hmc_window:1;
        RBus_UInt32  stilllinecntns_window:3;
        RBus_UInt32  stilllinecntns_window_th:5;
        RBus_UInt32  stilllinecntns_cond_th:2;
        RBus_UInt32  stilllinecntns_window_mode:1;
        RBus_UInt32  res1:3;
    };
}di_im_di_intra_sobel_motion_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_con3peakthly:8;
        RBus_UInt32  intra_con2interpolationthly:8;
        RBus_UInt32  intra_con1peakthlc:8;
        RBus_UInt32  intra_con1peakthly:8;
    };
}di_im_di_intra_line_cont_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_areaedgepixeldiffthly:8;
        RBus_UInt32  intra_mfilterthl:8;
        RBus_UInt32  intra_con2interpolationthly_mess:8;
        RBus_UInt32  intra_ma_mess_enable:1;
        RBus_UInt32  intra_mfilter_angle_enable:1;
        RBus_UInt32  intra_mfilter_angle_range:2;
        RBus_UInt32  res1:4;
    };
}di_im_di_intra_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_framestha:8;
        RBus_UInt32  ma_framerlvtha:8;
        RBus_UInt32  ma_framehtha:8;
        RBus_UInt32  ma_framemtha:8;
    };
}di_im_di_ma_frame_motion_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_framesthb:8;
        RBus_UInt32  ma_framerlvthb:8;
        RBus_UInt32  ma_framehthb:8;
        RBus_UInt32  ma_framemthb:8;
    };
}di_im_di_ma_frame_motion_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_framesthc:8;
        RBus_UInt32  ma_framerlvthc:8;
        RBus_UInt32  ma_framehthc:8;
        RBus_UInt32  ma_framemthc:8;
    };
}di_im_di_ma_frame_motion_th_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_fieldteethrlvtha:8;
        RBus_UInt32  ma_fieldteethhtha:8;
        RBus_UInt32  ma_fieldteethmtha:8;
        RBus_UInt32  ma_fieldteethstha:8;
    };
}di_im_di_ma_field_teeth_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_fieldteeththb:8;
        RBus_UInt32  ma_ydiffth:8;
        RBus_UInt32  ma_stilllogovdth:8;
        RBus_UInt32  ma_horicomth:8;
    };
}di_im_di_ma_others_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_sawtoothsth:8;
        RBus_UInt32  ma_sawtoothrlvth:8;
        RBus_UInt32  ma_sawtoothhth:8;
        RBus_UInt32  ma_sawtoothmth:8;
    };
}di_im_di_ma_sawtooth_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_ma_vertext_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_frmotionthl:8;
        RBus_UInt32  film_sawtooththl:8;
        RBus_UInt32  film22_sawtooththl:8;
        RBus_UInt32  res1:1;
        RBus_UInt32  film_violate_strict_en:1;
        RBus_UInt32  film_pair_en_auto:1;
        RBus_UInt32  film_pair2_en:1;
        RBus_UInt32  film_pair1_en:1;
        RBus_UInt32  film_thumbnail_en:1;
        RBus_UInt32  film_verscrollingtext_en:1;
        RBus_UInt32  film_leavequick_en:1;
    };
}di_im_di_film_sawtooth_filmframe_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_fistaticsthl:8;
        RBus_UInt32  film_frstaticsthl:8;
        RBus_UInt32  film22_fistaticsthl:8;
        RBus_UInt32  film_fieldmotionsumthl:8;
    };
}di_im_di_film_static_sum_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_fimaxsthl:16;
        RBus_UInt32  film_fiminsthl:8;
        RBus_UInt32  film_pairratio_all2:4;
        RBus_UInt32  film_pairratio_all1:4;
    };
}di_im_di_film_field_judge_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_subfistaticsthl:8;
        RBus_UInt32  film_subfrstaticsthl:8;
        RBus_UInt32  film22_subfistaticsthl:8;
        RBus_UInt32  film_subfieldmotionsumthl:8;
    };
}di_im_di_film_static_sum_sub_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_subfimaxsthl:16;
        RBus_UInt32  film_subfiminsthl:8;
        RBus_UInt32  film_pairratio_sub2:4;
        RBus_UInt32  film_pairratio_sub1:4;
    };
}di_im_di_film_field_judge_sub_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film22_fieldmotionsumthl:8;
        RBus_UInt32  film22_subfieldmotionsumthl:8;
		RBus_UInt32  nm_main_enable:1;
        RBus_UInt32  dummy180240b4_23_16:7;
        RBus_UInt32  film32_debounce_fieldnum:4;
        RBus_UInt32  film22_debounce_fieldnum:4;
    };
}di_im_di_film_motion_sum_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_top_margin:4;
        RBus_UInt32  film_bot_margin:4;
        RBus_UInt32  res1:24;
    };
}di_im_di_si_film_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_reserved_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_hbcounter:8;
        RBus_UInt32  film_motionstatus_choose:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  film_3d_mode:2;
        RBus_UInt32  film_hifreq_cnt_thl:4;
        RBus_UInt32  film_hifreq_thl:16;
    };
}di_im_di_si_film_hb_cout_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence:5;
        RBus_UInt32  film_confuse:1;
        RBus_UInt32  film_subdetected:1;
        RBus_UInt32  film_detected:1;
        RBus_UInt32  film_hifreq_flag:1;
        RBus_UInt32  dummy180240c4_31_9:23;
    };
}di_im_di_si_film_final_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_prefistatic1:8;
        RBus_UInt32  film_framepair:16;
        RBus_UInt32  film_framestatic:8;
    };
}di_im_di_si_film_pattern_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_nxtfimotion:8;
        RBus_UInt32  film_nxtfistatic2:8;
        RBus_UInt32  film_prefistatic2:8;
        RBus_UInt32  film_nxtfistatic1:8;
    };
}di_im_di_si_film_pattern_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence321_39_32:8;
        RBus_UInt32  film_violate321:8;
        RBus_UInt32  film_match321:8;
        RBus_UInt32  film_detected321:8;
    };
}di_im_di_si_film_32_result_1_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence321_31_0:32;
    };
}di_im_di_si_film_32_result_1_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence322_39_32:8;
        RBus_UInt32  film_violate322:8;
        RBus_UInt32  film_match322:8;
        RBus_UInt32  film_detected322:8;
    };
}di_im_di_si_film_32_result_2_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence322_31_0:32;
    };
}di_im_di_si_film_32_result_2_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence22_39_32:8;
        RBus_UInt32  film_violate22:8;
        RBus_UInt32  film_match22:8;
        RBus_UInt32  film_detected22:8;
    };
}di_im_di_si_film_22_result_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_sequence22_31_0:32;
    };
}di_im_di_si_film_22_result_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_719_700:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_699_680:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_h_t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_679_660:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_h_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_659_640:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_h_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_639_620:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_v_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_619_600:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_v_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_599_580:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_v_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_579_560:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_next_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_559_540:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_539_520:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_h_t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_519_500:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_h_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_499_480:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_h_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_479_460:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_v_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_459_440:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_v_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_439_420:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_v_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_419_400:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_pre_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_399_380:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_379_360:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_t_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_359_340:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_339_320:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_319_300:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_v_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_299_280:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_v_m_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_279_260:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_v_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_259_240:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_239_220:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_219_200:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_199_180:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_179_160:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_159_140:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_139_120:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_119_100:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_99_80:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_79_60:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_59_40:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_39_20:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_motionstatus_19_0:20;
        RBus_UInt32  res1:12;
    };
}di_im_di_si_film_motion_h_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  total_frame_motion_sum:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_si_ma_total_fm_sum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  large_frame_motion_pixel:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_si_ma_large_fm_pixel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  large_frame_motion_sum:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_si_ma_large_fm_sum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mess_horizontal_pixel:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_si_ma_mess_h_pixel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_mean1_status:8;
        RBus_UInt32  cr_mean2_status:8;
        RBus_UInt32  cr_mean3_status:8;
        RBus_UInt32  cr_enable_mainbalance:1;
        RBus_UInt32  cr_subbal_status:3;
        RBus_UInt32  res1:4;
    };
}di_im_di_si_image_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cr_amount_subbalance:16;
        RBus_UInt32  di_crc_ctrl_start:1;
        RBus_UInt32  di_crc_ctrl_conti:1;
        RBus_UInt32  fbuf_crc_info_r2_compare_fail:1;
        RBus_UInt32  fbuf_crc_info_r1_compare_fail:1;
        RBus_UInt32  fbuf_crc_r4_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r3_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r2_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r1_compare_fail_3d:1;
        RBus_UInt32  fbuf_crc_r4_compare_fail:1;
        RBus_UInt32  fbuf_crc_r3_compare_fail:1;
        RBus_UInt32  fbuf_crc_r2_compare_fail:1;
        RBus_UInt32  fbuf_crc_r1_compare_fail:1;
        RBus_UInt32  fbuf_crc_compare_done:1;
        RBus_UInt32  fbuf_crc_continous_mode:1;
        RBus_UInt32  fbuf_crc_compare_en:1;
        RBus_UInt32  res1:1;
    };
}di_im_di_si_sub_in_auto_balance_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_crc_result:32;
    };
}di_im_di_crc_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_partialstillnew:1;
        RBus_UInt32  cp_partialstill:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  newintrainterpolate_enable:1;
        RBus_UInt32  newintrainterpolate_pixdiff_thd:8;
        RBus_UInt32  newintrainterpolate_sumdiff_thd:10;
        RBus_UInt32  newintrainterpolate_vertical_thd:10;
    };
}di_im_di_si_still_info_for_ne_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film22_nxtfimotion:8;
        RBus_UInt32  film22_nxtfistatic1:8;
        RBus_UInt32  res1:16;
    };
}di_im_di_si_film22_detector_pattern_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthlc:8;
        RBus_UInt32  cp_temporalthly:8;
        RBus_UInt32  res1:16;
    };
}di_im_di_tnr_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_rtnr_y_enable:1;
        RBus_UInt32  cp_rtnr_c_enable:1;
        RBus_UInt32  cp_rtnr_progressive:1;
        RBus_UInt32  cp_rtnr_rounding_correction:1;
        RBus_UInt32  cp_rtnr_mad_window:2;
        RBus_UInt32  cp_rtnr_updatelocken:1;
        RBus_UInt32  cp_rtnr_updatelockflg:1;
        RBus_UInt32  cp_rtnr_rounding_correction2_en:1;
        RBus_UInt32  cp_rtnr_rounding_correction2_mode:2;
        RBus_UInt32  cp_rtnr_mad_window_mode:1;
        RBus_UInt32  cp_rtnr_rounding_correction2_errorthd_y:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  cp_rtnr_rounding_correction2_errorthd_c:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  cp_rtnr_rgb444_8bit_mode:1;
        RBus_UInt32  cp_progressive_line_dma:1;
        RBus_UInt32  cp_rtnr_rgb444_enable:1;
        RBus_UInt32  cp_rtnr_interlace_force2d_en:1;
    };
}di_im_di_rtnr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_rtnr_k_force_modify_0_00:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_0_24:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_rtnr_k_force_modify_offset:4;
        RBus_UInt32  cp_rtnr_k_force_modify_en_y:1;
        RBus_UInt32  cp_rtnr_k_force_modify_en_c:1;
        RBus_UInt32  cp_rtnr_ne_follow_k_modify:1;
        RBus_UInt32  cp_rtnr_k_force_modify_mode:1;
        RBus_UInt32  cp_rtnr_k_force_modify_index:3;
        RBus_UInt32  dummy180241a4_31:5;
    };
}di_im_di_rtnr_k_force_modify_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tr2to1_dist:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_rtnr_k_force_modify_1_00:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_1_24:1;
        RBus_UInt32  res2:1;
    };
}di_tr2to1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_rtnr_k_force_modify_2_00:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_2_24:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_00:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_3_24:1;
        RBus_UInt32  res2:1;
    };
}di_im_di_rtnr_k_force_modify_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_y_th2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_temporal_mad_y_th1:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_rtnr_mad_y_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_c_th2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_temporal_mad_c_th1:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_rtnr_mad_c_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_countery:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_y_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_counteru:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_u_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_counterv:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_v_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_temporal_edge_crct_en:1;
        RBus_UInt32  cp_temporal_c_k_decision:3;
        RBus_UInt32  cp_temporal_l_qlfy_th:4;
        RBus_UInt32  cp_temporal_num_match_l:4;
        RBus_UInt32  dummy180241c4_15:3;
        RBus_UInt32  cp_rtnr_k_force_modify_4_00:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_01:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_02:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_03:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_04:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_10:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_11:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_12:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_13:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_14:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_20:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_21:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_22:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_23:1;
        RBus_UInt32  cp_rtnr_k_force_modify_4_24:1;
        RBus_UInt32  res2:1;
    };
}di_im_di_rtnr_ediff_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_sad_offset_v:8;
        RBus_UInt32  cp_temporal_sad_offset_u:8;
        RBus_UInt32  cp_temporal_sad_offset_y:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_sad_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_e_th2_c:8;
        RBus_UInt32  cp_temporal_e_th1_c:8;
        RBus_UInt32  cp_temporal_e_th2_y:8;
        RBus_UInt32  cp_temporal_e_th1_y:8;
    };
}di_im_di_rtnr_ediff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_sbl_ths_y:10;
        RBus_UInt32  dummy180241d0_11_10:2;
        RBus_UInt32  cp_temporal_sbl_thm_y:10;
        RBus_UInt32  dummy180241d0_31_22:10;
    };
}di_im_di_rtnr_ediff_sobel_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_nl_low_bnd_y:8;
        RBus_UInt32  cp_temporal_nl_up_bnd_y:8;
        RBus_UInt32  res1:16;
    };
}di_im_di_rtnr_level_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_cnt_y:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_et_count_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_sad_sum_y:32;
    };
}di_im_di_rtnr_et_sum_y_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_sad_sum_u:32;
    };
}di_im_di_rtnr_et_sum_u_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_same_et_sad_sum_v:32;
    };
}di_im_di_rtnr_et_sum_v_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_xc_en:1;
        RBus_UInt32  cp_temporal_xc_switch:1;
        RBus_UInt32  set_frame_offset_verymotion:4;
        RBus_UInt32  set_frame_offset_motion:3;
        RBus_UInt32  set_frame_offset_still:3;
        RBus_UInt32  set_frame_offset_verystill:4;
        RBus_UInt32  set_classifysmooth:3;
        RBus_UInt32  set_stillmotion_thc:4;
        RBus_UInt32  set_stillmotion_thb:4;
        RBus_UInt32  set_stillmotion_tha:4;
        RBus_UInt32  set_sobeledgetypeen:1;
    };
}di_im_di_tnr_xc_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hfd_3x3blockteethcount_thl:4;
        RBus_UInt32  hfd_manyteethareastilllogoen:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  hfd_highlowhighdiff_count_thl:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  hfd_highlowhighdiff_thl:8;
        RBus_UInt32  hfd_highfrequencydetectoren:1;
        RBus_UInt32  stilllogo_hf_check_ctrl:1;
        RBus_UInt32  res3:4;
        RBus_UInt32  set_sobeledgetype_sel:2;
    };
}di_im_di_hfd_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hfd_linemotioncount_thl:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  hfd_linemotioncount_thl2:11;
        RBus_UInt32  res2:2;
        RBus_UInt32  hfd_framekcombineoflinemotion:2;
        RBus_UInt32  hfd_checklinemotioncounten:1;
    };
}di_im_di_hfd_line_motion_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hfd_statistic:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_hfd_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  stilllogoweavelineen:1;
        RBus_UInt32  stilllogolrcorrectionen:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  hmc_window_bot:10;
        RBus_UInt32  hmc_window_top:10;
        RBus_UInt32  hmc_window_en:1;
        RBus_UInt32  res2:3;
    };
}di_im_di_hfd_ma_error_recovery_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  newintralowangle_enable:1;
        RBus_UInt32  newintralowangle_right_dir:2;
        RBus_UInt32  newintralowangle_left_dir:2;
        RBus_UInt32  newintralowangle_vercur_diff_thd:10;
        RBus_UInt32  newintralowangle_precur_diff_thd:10;
        RBus_UInt32  newintralowangle_continuous_pt:7;
    };
}di_im_di_new_intra_low_angle_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intranewgracorr_minmatchdifftransrange:4;
        RBus_UInt32  intranewgracorr_mintransrange:4;
        RBus_UInt32  intranewgracorr_gradmatchdiff_thd:8;
        RBus_UInt32  intranewgracorr_gradmatchmin_thd:8;
        RBus_UInt32  intranewgracorr_transpt_thd:8;
    };
}di_im_di_intra_new_gradient_correct_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lowangle_lpf_diffthd:10;
        RBus_UInt32  res1:1;
        RBus_UInt32  intra_areacorner_intrarange_correct_enable:1;
        RBus_UInt32  intranewgracorr_transptcenter_thd:8;
        RBus_UInt32  res2:7;
        RBus_UInt32  intra_range_correct_interpolation_enable:1;
        RBus_UInt32  intra_averagefilter_enable:1;
        RBus_UInt32  intra_lowangle_lpf_enable:1;
        RBus_UInt32  intranewgracorr_doublecheck_enable:1;
        RBus_UInt32  intranewgracorr_enable:1;
    };
}di_im_di_intra_post_process_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  btr_blendtemporalrecoveryen:1;
        RBus_UInt32  btr_solutiontype:1;
        RBus_UInt32  btr_sola_temporallength:2;
        RBus_UInt32  btr_sola_method:1;
        RBus_UInt32  btr_sola_method0_successtime:3;
        RBus_UInt32  btr_sola_method0_blendtype:1;
        RBus_UInt32  btr_blendtemporalrecovery_dma_en:1;
        RBus_UInt32  btr_info_save_mode:2;
        RBus_UInt32  btr_solb_temporallength:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  btr_solb_cur0_count:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  btr_solb_cur1_count:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  btr_blendtemporaldebugmode:2;
        RBus_UInt32  btr_hmc_blendchoose:1;
        RBus_UInt32  res4:5;
    };
}di_im_di_btr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  btr_sola_method0_cur0_pre1_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre1_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre2_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre2_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre3_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre3_max:2;
        RBus_UInt32  btr_sola_method0_cur0_pre4_min:2;
        RBus_UInt32  btr_sola_method0_cur0_pre4_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre1_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre1_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre2_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre2_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre3_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre3_max:2;
        RBus_UInt32  btr_sola_method0_cur1_pre4_min:2;
        RBus_UInt32  btr_sola_method0_cur1_pre4_max:2;
    };
}di_im_di_btr_sola_method0_min_max_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  btr_longweavesum:24;
        RBus_UInt32  intra_areacorner_intrarange_correct_peak_thd:8;
    };
}di_im_di_btr_longweave_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_lowpasssum:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_ber_lowpass_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_blendspatialrecoveryen:1;
        RBus_UInt32  ber_blendspatialclassify:1;
        RBus_UInt32  ber_blendspatial_lpf_stilllogo:1;
        RBus_UInt32  ber_blendspatial_lpf_blendingtype:1;
        RBus_UInt32  ber_closeclevel_min:8;
        RBus_UInt32  res1:4;
        RBus_UInt32  ber_closeclevel_max:8;
        RBus_UInt32  res2:8;
    };
}di_im_di_ber_spatial_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_diffylevel_min:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ber_diffylevel_max:10;
        RBus_UInt32  res2:6;
    };
}di_im_di_ber_spatial_diffy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ber_blendtemporalrevoeryen:1;
        RBus_UInt32  ber_blendtemporalblock:2;
        RBus_UInt32  ber_blendtemporaltype:1;
        RBus_UInt32  ber_spatialcontinuelength:4;
        RBus_UInt32  ber_totalcontinuesum:24;
    };
}di_im_di_ber_temporal_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lpattern_rough_diff_th:8;
        RBus_UInt32  intra_lpattern_flat_wholediff_th:8;
        RBus_UInt32  intra_lpattern_flat_cendiff_th:8;
        RBus_UInt32  intra_lpattern_flat_rldiff_th:8;
    };
}di_im_di_intra_l_cross_pat_det_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lpattern_vdev_highbound_th:8;
        RBus_UInt32  intra_lpattern_vdev_lowbound_th:8;
        RBus_UInt32  intra_lpattern_vdiff_th:8;
        RBus_UInt32  intra_lpattern_rough_flat_diff_th:8;
    };
}di_im_di_intra_l_cross_pat_det_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_lpattern_enable:1;
        RBus_UInt32  intra_lpattern_rough_ratio:3;
        RBus_UInt32  intra_lpattern_dir_pk_enable:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  intra_lpattern_cen_pixdiff_th:8;
    };
}di_im_di_intra_l_cross_pat_det_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_noiseesthorstart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_noiseesthorend:12;
        RBus_UInt32  res2:4;
    };
}di_noiseest_hor_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_noiseestverstart:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_noiseestverend:12;
        RBus_UInt32  res2:4;
    };
}di_noiseest_ver_range_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1802423c_31_0:32;
    };
}di_im_di_dummy_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_histveren:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_histveroffset:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_histhoroffset:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  subsamplingmode:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  cp_histthl2:8;
        RBus_UInt32  cp_histthl1:8;
    };
}di_mpeg_hist_blking_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cntver0:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver1:12;
        RBus_UInt32  res2:4;
    };
}di_cntver0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cntver2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver3:12;
        RBus_UInt32  res2:4;
    };
}di_cntver2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cntver4:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver5:12;
        RBus_UInt32  res2:4;
    };
}di_cntver4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_cntver6:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  cp_cntver7:12;
        RBus_UInt32  res2:4;
    };
}di_cntver6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_mpegenable_y_y:1;
        RBus_UInt32  cp_mpegenable_y_c:1;
        RBus_UInt32  cp_mpgidxmode_y:2;
        RBus_UInt32  cp_mpegresultweight_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_mpgidx_y:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_mpglpmode:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  cp_mpgupperbound:8;
        RBus_UInt32  cp_mpglowerbound:8;
    };
}di_mpegnr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pib_film_h_00:1;
        RBus_UInt32  pib_film_h_01:1;
        RBus_UInt32  pib_film_h_02:1;
        RBus_UInt32  pib_film_h_03:1;
        RBus_UInt32  pib_film_h_04:1;
        RBus_UInt32  pib_film_h_05:1;
        RBus_UInt32  pib_film_h_06:1;
        RBus_UInt32  pib_film_h_07:1;
        RBus_UInt32  pib_film_h_08:1;
        RBus_UInt32  pib_film_h_09:1;
        RBus_UInt32  pib_film_h_10:1;
        RBus_UInt32  pib_film_h_11:1;
        RBus_UInt32  pib_film_c:1;
        RBus_UInt32  pib_film_v_r:1;
        RBus_UInt32  pib_film_v_m:1;
        RBus_UInt32  pib_film_v_l:1;
        RBus_UInt32  pib_film_h_b:1;
        RBus_UInt32  pib_film_h_m:1;
        RBus_UInt32  pib_film_h_t:1;
        RBus_UInt32  pib_film_all:1;
        RBus_UInt32  res1:12;
    };
}di_im_di_pib_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pib_film_cen_all:16;
        RBus_UInt32  pib_film_all_th:16;
    };
}di_im_di_pib_all_cen_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pib_film_v_th:16;
        RBus_UInt32  pib_film_h_th:16;
    };
}di_im_di_pib_h_v_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pib_film_h00_h11_th:16;
        RBus_UInt32  res1:16;
    };
}di_im_di_pib_h00_h11_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_mask_en:1;
        RBus_UInt32  film_mask_pass_thd:4;
        RBus_UInt32  res1:3;
        RBus_UInt32  film_mask_fiedif_thd:8;
        RBus_UInt32  film_mask_frmdif_thd:8;
        RBus_UInt32  res2:8;
    };
}di_im_di_film_mask_detection_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_edgetype_v_pass:1;
        RBus_UInt32  film_edgetype_r_pass:1;
        RBus_UInt32  film_edgetype_h_pass:1;
        RBus_UInt32  film_edgetype_l_pass:1;
        RBus_UInt32  film_edgetype_n_pass:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  film_edgetype_sobelths:10;
        RBus_UInt32  film_edgetype_sobelthm:10;
        RBus_UInt32  res2:4;
    };
}di_im_di_film_edge_type_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_startline:10;
        RBus_UInt32  res1:22;
    };
}di_im_di_hmc_3a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_hmc_statistic_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_hmc_lineratio:8;
        RBus_UInt32  ma_hmc_topline:12;
        RBus_UInt32  ma_hmc_botline:12;
    };
}di_im_di_hmc_statistic1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_hmc_topline2:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ma_hmc_botline2:12;
        RBus_UInt32  res2:4;
    };
}di_im_di_hmc_statistic2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_hmc_topline3:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  ma_hmc_botline3:12;
        RBus_UInt32  res2:4;
    };
}di_im_di_hmc_statistic3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lsb_rtnr_en:1;
        RBus_UInt32  lsb_rtnr_channel:1;
        RBus_UInt32  lsb_rtnr_bitnum:1;
        RBus_UInt32  lsb_rtnr_rounding:1;
        RBus_UInt32  lsb_rtnr_curweight:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  lsb_rtnr_th:6;
        RBus_UInt32  res2:18;
    };
}di_im_di_lsb_rtnr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnrxc_pixel_counter:16;
        RBus_UInt32  chromaerror_framemotionc_th:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  res2:1;
    };
}di_im_di_framesobel_statistic_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:9;
        RBus_UInt32  hmc_dynamic_threshold_en:1;
        RBus_UInt32  hmc_dynamic_threshold_bias:6;
        RBus_UInt32  hmc_dynamic_threshold_max_clip:8;
        RBus_UInt32  chromaerror_th:5;
        RBus_UInt32  hmc_vector_follow_pan_en:1;
        RBus_UInt32  chromaerror_all:1;
        RBus_UInt32  chromaerror_en:1;
    };
}di_im_di_framesobel_statistic_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tnrxc_mkii_en:1;
        RBus_UInt32  tnrxc_dbguvmode:1;
        RBus_UInt32  dummy180242a0_7:6;
        RBus_UInt32  tnrxc_mkii_thy:8;
        RBus_UInt32  tnrxc_mkii_thc1:8;
        RBus_UInt32  tnrxc_mkii_thc2:8;
    };
}di_tnrxc_mkii_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_y_dark_k_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_temporal_y_kin_dark:4;
        RBus_UInt32  cp_temporal_y_kout_dark:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  cp_temporal_y_dark_th:8;
        RBus_UInt32  cp_temporal_y_kin_dark_2:4;
        RBus_UInt32  cp_temporal_y_kout_dark_2:4;
    };
}di_im_di_rtnr_k_dark_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_new_formula_en:1;
        RBus_UInt32  rtnr_localedge_en:1;
        RBus_UInt32  rtnr_stilledge_en:1;
        RBus_UInt32  rtnr_crct_debug:1;
        RBus_UInt32  rtnr_crct_bias:3;
        RBus_UInt32  dummy180242a8_7:1;
        RBus_UInt32  rtnr_act_bias:3;
        RBus_UInt32  rtnr_localedge_debug:1;
        RBus_UInt32  rtnr_stilledge_bonusbias:3;
        RBus_UInt32  rtnr_stilledge_debug:1;
        RBus_UInt32  rtnr_th_localedgediff:12;
        RBus_UInt32  rtnr_refined_c_en:1;
        RBus_UInt32  dummy180242a8_31:3;
    };
}di_im_di_rtnr_refined_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_stilledge_th_edg:8;
        RBus_UInt32  rtnr_stilledge_th_edgdiff:9;
        RBus_UInt32  dummy180242ac_31_17:15;
    };
}di_im_di_rtnr_refined_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_ediff_c_en0:1;
        RBus_UInt32  cp_temporal_ediff_c_en1:1;
        RBus_UInt32  cp_temporal_ediff_c_en2:1;
        RBus_UInt32  cp_temporal_ediff_c_en3:1;
        RBus_UInt32  cp_temporal_ediff_c_en4:1;
        RBus_UInt32  cp_temporal_ediff_c_en5:1;
        RBus_UInt32  cp_temporal_ediff_c_en6:1;
        RBus_UInt32  res1:25;
    };
}di_im_di_rtnr_ediff_enable_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_ediff_en0:1;
        RBus_UInt32  cp_temporal_ediff_en1:1;
        RBus_UInt32  cp_temporal_ediff_en2:1;
        RBus_UInt32  cp_temporal_ediff_en3:1;
        RBus_UInt32  cp_temporal_ediff_en4:1;
        RBus_UInt32  cp_temporal_ediff_en5:1;
        RBus_UInt32  cp_temporal_ediff_en6:1;
        RBus_UInt32  cp_temporal_ediff_en7:1;
        RBus_UInt32  cp_temporal_ediff_en8:1;
        RBus_UInt32  cp_temporal_ediff_en9:1;
        RBus_UInt32  cp_temporal_ediff_en10:1;
        RBus_UInt32  cp_temporal_ediff_en11:1;
        RBus_UInt32  cp_temporal_ediff_en12:1;
        RBus_UInt32  cp_temporal_ediff_en13:1;
        RBus_UInt32  cp_temporal_ediff_en14:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_temporal_y_k_decision:1;
        RBus_UInt32  res2:15;
    };
}di_im_di_rtnr_ediff_enable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  cp_temporal_hmcnr_follow_pan_en:1;
        RBus_UInt32  cp_temporal_hmcnr_uv_with_y:1;
        RBus_UInt32  cp_temporal_hmcnr_ref_topline_en:1;
        RBus_UInt32  cp_temporal_hmcnr_debug_progressive:1;
        RBus_UInt32  cp_temporal_hmcnr_y_en:1;
        RBus_UInt32  cp_temporal_hmcnr_ref_topline_th:11;
        RBus_UInt32  cp_temporal_hmcnr_weight:3;
        RBus_UInt32  cp_temporal_hmcnr_mad_window:2;
        RBus_UInt32  res2:8;
    };
}di_im_di_rtnr_hmcnr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_new_method_en:1;
        RBus_UInt32  rtnr_sad_method:2;
        RBus_UInt32  rtnr_new_method_k_extend_en:1;
        RBus_UInt32  rtnr_sad_mix_cal_weight:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  rtnr_k_temporal_compare_en:1;
        RBus_UInt32  rtnr_k_temporal_compare_snr:1;
        RBus_UInt32  rtnr_moredetail_cotinue_en:1;
        RBus_UInt32  prtnr_4k2k:1;
        RBus_UInt32  rtnr_debugmode:4;
        RBus_UInt32  res2:8;
    };
}di_im_di_rtnr_new_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_sbl_ths_y:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  rtnr_sbl_thm_y:10;
        RBus_UInt32  rtnr_sobel_method:2;
        RBus_UInt32  rtnr_edgetypediff_count_th0:6;
        RBus_UInt32  res2:2;
    };
}di_im_di_rtnr_new_sobel_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th1:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th2:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th3:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th4:8;
    };
}di_im_di_rtnr_new_sad_edge_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th5:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th6:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th7:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th8:8;
    };
}di_im_di_rtnr_new_sad_edge_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th1:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th2:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th3:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th4:8;
    };
}di_im_di_rtnr_new_sad_nonedge_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th5:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th6:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th7:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th8:8;
    };
}di_im_di_rtnr_new_sad_nonedge_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_count_th1:5;
        RBus_UInt32  rtnr_statistic_motion_count_th2:5;
        RBus_UInt32  rtnr_statistic_motion_count_th3:5;
        RBus_UInt32  res1:1;
        RBus_UInt32  rtnr_statistic_motion_count_th4:5;
        RBus_UInt32  rtnr_statistic_motion_count_th5:5;
        RBus_UInt32  rtnr_statistic_motion_count_th6:5;
        RBus_UInt32  res2:1;
    };
}di_im_di_rtnr_new_sad_count_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_edgetypediff_count_th1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  rtnr_edgetypediff_count_th2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rtnr_edgetypediff_count_th3:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  rtnr_edgetypediff_count_th4:6;
        RBus_UInt32  res4:2;
    };
}di_im_di_rtnr_new_edgetypediff_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_edgetypediff_count_th5:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  rtnr_edgetypediff_count_th6:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  rtnr_edgetypediff_count_th7:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  rtnr_edgetypediff_count_th8:6;
        RBus_UInt32  res4:2;
    };
}di_im_di_rtnr_new_edgetypediff_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_rtnr_new_snr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_rtnr_new_snr_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_im_di_rtnr_new_snr_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_00:4;
        RBus_UInt32  rtnr_k_01:4;
        RBus_UInt32  rtnr_k_02:4;
        RBus_UInt32  rtnr_k_03:4;
        RBus_UInt32  rtnr_k_04:4;
        RBus_UInt32  rtnr_k_05:4;
        RBus_UInt32  rtnr_k_06:4;
        RBus_UInt32  rtnr_k_07:4;
    };
}di_im_di_rtnr_new_k_00_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_10:4;
        RBus_UInt32  rtnr_k_11:4;
        RBus_UInt32  rtnr_k_12:4;
        RBus_UInt32  rtnr_k_13:4;
        RBus_UInt32  rtnr_k_14:4;
        RBus_UInt32  rtnr_k_15:4;
        RBus_UInt32  rtnr_k_16:4;
        RBus_UInt32  rtnr_k_17:4;
    };
}di_im_di_rtnr_new_k_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_20:4;
        RBus_UInt32  rtnr_k_21:4;
        RBus_UInt32  rtnr_k_22:4;
        RBus_UInt32  rtnr_k_23:4;
        RBus_UInt32  rtnr_k_24:4;
        RBus_UInt32  rtnr_k_25:4;
        RBus_UInt32  rtnr_k_26:4;
        RBus_UInt32  rtnr_k_27:4;
    };
}di_im_di_rtnr_new_k_20_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_30:4;
        RBus_UInt32  rtnr_k_31:4;
        RBus_UInt32  rtnr_k_32:4;
        RBus_UInt32  rtnr_k_33:4;
        RBus_UInt32  rtnr_k_34:4;
        RBus_UInt32  rtnr_k_35:4;
        RBus_UInt32  rtnr_k_36:4;
        RBus_UInt32  rtnr_k_37:4;
    };
}di_im_di_rtnr_new_k_30_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_40:4;
        RBus_UInt32  rtnr_k_41:4;
        RBus_UInt32  rtnr_k_42:4;
        RBus_UInt32  rtnr_k_43:4;
        RBus_UInt32  rtnr_k_44:4;
        RBus_UInt32  rtnr_k_45:4;
        RBus_UInt32  rtnr_k_46:4;
        RBus_UInt32  rtnr_k_47:4;
    };
}di_im_di_rtnr_new_k_40_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_50:4;
        RBus_UInt32  rtnr_k_51:4;
        RBus_UInt32  rtnr_k_52:4;
        RBus_UInt32  rtnr_k_53:4;
        RBus_UInt32  rtnr_k_54:4;
        RBus_UInt32  rtnr_k_55:4;
        RBus_UInt32  rtnr_k_56:4;
        RBus_UInt32  rtnr_k_57:4;
    };
}di_im_di_rtnr_new_k_50_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_60:4;
        RBus_UInt32  rtnr_k_61:4;
        RBus_UInt32  rtnr_k_62:4;
        RBus_UInt32  rtnr_k_63:4;
        RBus_UInt32  rtnr_k_64:4;
        RBus_UInt32  rtnr_k_65:4;
        RBus_UInt32  rtnr_k_66:4;
        RBus_UInt32  rtnr_k_67:4;
    };
}di_im_di_rtnr_new_k_60_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_70:4;
        RBus_UInt32  rtnr_k_71:4;
        RBus_UInt32  rtnr_k_72:4;
        RBus_UInt32  rtnr_k_73:4;
        RBus_UInt32  rtnr_k_74:4;
        RBus_UInt32  rtnr_k_75:4;
        RBus_UInt32  rtnr_k_76:4;
        RBus_UInt32  rtnr_k_77:4;
    };
}di_im_di_rtnr_new_k_70_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_mask1_vgain:2;
        RBus_UInt32  rtnr_mask1_ugain:2;
        RBus_UInt32  rtnr_mask1_ygain:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_vc_nr_mask1_vref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vc_nr_mask1_uref:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_vc_nr_mask1_yref:6;
    };
}di_im_di_rtnr_new_mask1_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_mask1_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rtnr_mask1_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rtnr_mask1_mapstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  rtnr_mask1_mapthre:4;
        RBus_UInt32  rtnr_mask1_maplimit:4;
        RBus_UInt32  res4:12;
    };
}di_im_di_rtnr_new_mask1_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_mask2_vgain:2;
        RBus_UInt32  rtnr_mask2_ugain:2;
        RBus_UInt32  rtnr_mask2_ygain:2;
        RBus_UInt32  res1:4;
        RBus_UInt32  reg_vc_nr_mask2_vref:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_vc_nr_mask2_uref:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_vc_nr_mask2_yref:6;
    };
}di_im_di_rtnr_new_mask2_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_mask2_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  rtnr_mask2_dir:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  rtnr_mask2_mapstep:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  rtnr_mask2_mapthre:4;
        RBus_UInt32  rtnr_mask2_maplimit:4;
        RBus_UInt32  res4:12;
    };
}di_im_di_rtnr_new_mask2_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  intra_highfreq_change_th1:6;
        RBus_UInt32  intra_highfreq_change_th2:6;
        RBus_UInt32  intra_highfreq_dir1:4;
        RBus_UInt32  intra_highfreq_dir2:4;
        RBus_UInt32  intra_highfreq_diff_th:8;
        RBus_UInt32  intra_highfreq_en:1;
        RBus_UInt32  res1:3;
    };
}di_im_di_intra_hfd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type1_en:1;
        RBus_UInt32  bc_type1_blendmode:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  bc_type1_mid_teeth_min:4;
        RBus_UInt32  bc_type1_mid_teeth_max:8;
        RBus_UInt32  bc_type2_en:1;
        RBus_UInt32  bc_type2_block_update_type:1;
        RBus_UInt32  bc_type2_block_update_once:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  bc_type2_block_access_x:4;
        RBus_UInt32  bc_type2_block_access_y:5;
        RBus_UInt32  bc_type2_block_access_mode:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  bc_type2_debug_mode:1;
    };
}di_im_di_blending_corrector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_block_access_data:12;
        RBus_UInt32  bc_type2_edgecase_h:1;
        RBus_UInt32  bc_type2_edgecase_rlv:1;
        RBus_UInt32  bc_type2_edgecase_s:1;
        RBus_UInt32  bc_type2_edgecase_m:1;
        RBus_UInt32  bc_type2_block_width:8;
        RBus_UInt32  bc_type2_block_height:8;
    };
}di_im_di_blending_corrector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_block_motion_th_1:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  bc_type2_block_motion_th_2:10;
        RBus_UInt32  bc_type2_frame_motion_offset:6;
    };
}di_im_di_blending_corrector_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bc_type2_block_motion_th_3:10;
        RBus_UInt32  bc_type2_prefer_intra:1;
        RBus_UInt32  bc_type2_slight_teeth_en:1;
        RBus_UInt32  bc_type2_slight_teeth_max:4;
        RBus_UInt32  bc_type3_hfsum:12;
        RBus_UInt32  bc_type3_en:1;
        RBus_UInt32  bc_type2_slight_teeth_min:3;
    };
}di_im_di_blending_corrector_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_en:1;
        RBus_UInt32  pan_me_edgediff_min_th:3;
        RBus_UInt32  pan_mc_path_sel:1;
        RBus_UInt32  res1:19;
        RBus_UInt32  pan_mc_sobel_diff_min_th:6;
        RBus_UInt32  res2:1;
        RBus_UInt32  pan_mc_odd_mv_pass_en:1;
    };
}di_im_di_pan_detection_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  pan_mc_edge_r:1;
        RBus_UInt32  pan_mc_edge_l:1;
        RBus_UInt32  pan_mc_edge_v:1;
        RBus_UInt32  pan_mc_edge_h:1;
        RBus_UInt32  pan_mc_edge_n:1;
        RBus_UInt32  pan_mc_teeth_check_en:1;
        RBus_UInt32  pan_mc_teeth_check_th:4;
        RBus_UInt32  res2:16;
    };
}di_im_di_pan_detection_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r6_pixelsum:16;
        RBus_UInt32  hmc_r7_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r4_pixelsum:16;
        RBus_UInt32  hmc_r5_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r2_pixelsum:16;
        RBus_UInt32  hmc_r3_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_c0_pixelsum:16;
        RBus_UInt32  hmc_r1_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l2_pixelsum:16;
        RBus_UInt32  hmc_l1_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l4_pixelsum:16;
        RBus_UInt32  hmc_l3_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l6_pixelsum:16;
        RBus_UInt32  hmc_l5_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_me_border_top_width:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  hmc_l7_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_me_border_right_width:8;
        RBus_UInt32  pan_me_border_left_width:8;
        RBus_UInt32  pan_me_border_bot_width:12;
        RBus_UInt32  res1:4;
    };
}di_im_di_pan_detection_control_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_film_en:1;
        RBus_UInt32  film_pair3_en:1;
        RBus_UInt32  force_badeditor_en:1;
        RBus_UInt32  film_pair3_ratio:2;
        RBus_UInt32  badeditor_ratio:2;
        RBus_UInt32  fw_film_reg_sel:1;
        RBus_UInt32  film_mixedfilm_margin:2;
        RBus_UInt32  fw_film_filmdetected:1;
        RBus_UInt32  fw_film_mixedfilmdetected:1;
        RBus_UInt32  fw_film_mixedfilmconfuse:1;
        RBus_UInt32  fw_film_filmweavemode:2;
        RBus_UInt32  fw_film_22detected:1;
        RBus_UInt32  fw_film_32detected2:1;
        RBus_UInt32  fw_film_32detected1:1;
        RBus_UInt32  fw_film_filmsequence:5;
        RBus_UInt32  film_bad_edit_en:1;
        RBus_UInt32  fw_film_doublebuffer_en:1;
        RBus_UInt32  res1:7;
    };
}di_im_di_film_new_function_main_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_topline1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  fw_botline1:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_topbotline1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_topline2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  fw_botline2:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_topbotline2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_topline3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  fw_botline3:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_topbotline3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_prevfilmmotion:8;
        RBus_UInt32  film22_prevfilmmotion:8;
        RBus_UInt32  film_badeditor_flag:1;
        RBus_UInt32  res1:15;
    };
}di_im_di_film_prev_fieldmotion_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_prevtopdetected1:1;
        RBus_UInt32  film_prevbotdetected1:1;
        RBus_UInt32  film_prevtopdetected2:1;
        RBus_UInt32  film_prevbotdetected2:1;
        RBus_UInt32  film_prevtopdetected3:1;
        RBus_UInt32  film_prevbotdetected3:1;
        RBus_UInt32  film_nexttopdetected1:1;
        RBus_UInt32  film_nextbotdetected1:1;
        RBus_UInt32  film_nexttopdetected2:1;
        RBus_UInt32  film_nextbotdetected2:1;
        RBus_UInt32  film_nexttopdetected3:1;
        RBus_UInt32  film_nextbotdetected3:1;
        RBus_UInt32  res1:20;
    };
}di_im_di_film_mark_information_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_prevtopmark1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  film_prevbotmark1:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_mark_prev1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_prevtopmark2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  film_prevbotmark2:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_mark_prev2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_prevtopmark3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  film_prevbotmark3:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_mark_prev3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_nexttopmark1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  film_nextbotmark1:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_mark_next1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_nexttopmark2:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  film_nextbotmark2:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_mark_next2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  film_nexttopmark3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  film_nextbotmark3:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_film_mark_next3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_upperbound_sad_forjudgemv:8;
        RBus_UInt32  smd_lowbound_sad_forjudgemv:8;
        RBus_UInt32  smd_localmv_counter_th:3;
        RBus_UInt32  smd_debug_outofrange_en:1;
        RBus_UInt32  smd_debug_spatialfreqnomatch_en:1;
        RBus_UInt32  smd_debug_mvschanged_en:1;
        RBus_UInt32  smd_debug_resurrect_en:1;
        RBus_UInt32  smd_debug_preinrateeth_en:1;
        RBus_UInt32  smd_spatialmv_counter_th:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_debug_sawtooth_en:1;
        RBus_UInt32  smd_debug_ventryofmv_en:1;
        RBus_UInt32  smd_debug_hentryofmv_en:1;
        RBus_UInt32  smd_en:1;
    };
}di_di_smd_control_candidatelist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_reliablerange_sad_th:8;
        RBus_UInt32  smd_localmv_sad_th:8;
        RBus_UInt32  smd_localmv_concentrate_ratio_th:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_spatial_divergence_th:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_spatialmv_sad_th:8;
    };
}di_di_smd_choosecandidate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_curr_teeth_offset:6;
        RBus_UInt32  smd_teeth_new_mode:2;
        RBus_UInt32  smd_curr_teeth_gain:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_preintra_teeth_gain:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_preintra_effect:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  smd_preintra_teeth_offset:6;
        RBus_UInt32  res4:1;
        RBus_UInt32  smd_steeth_en:1;
    };
}di_di_smd_refinemv1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_global_en_ratio:8;
        RBus_UInt32  smd_resurrect_minsad_th:8;
        RBus_UInt32  smd_resurrect_localcurr_num:4;
        RBus_UInt32  smd_resurrect_smallwindow_num:4;
        RBus_UInt32  smd_resurrect_union_num:5;
        RBus_UInt32  smd_resurrect_en:1;
        RBus_UInt32  smd_mvs_hchanged_en:1;
        RBus_UInt32  smd_mvs_vchanged_en:1;
    };
}di_di_smd_refinemv2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sfreq_drop_th:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  smd_sfreq_diff_th:8;
        RBus_UInt32  smd_sfreq_diff_gain:4;
        RBus_UInt32  res2:4;
    };
}di_di_smd_refinemv3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_di_smd_panning1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_rightweave_gap_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_rightweave_gap_range:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_leftweave_gap_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_leftweave_gap_range:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  smd_drop_singleintraline_en:1;
        RBus_UInt32  smd_drop_singleweaveline_en:1;
    };
}di_di_smd_final_adjustment1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_rightintra_gap_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_rightintra_gap_range:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_leftintra_gap_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_leftintra_gap_range:5;
        RBus_UInt32  res4:2;
        RBus_UInt32  smd_line_continous_en:1;
    };
}di_di_smd_final_adjustment2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_compensate_avg:8;
        RBus_UInt32  smd_compensate_teeth_th:8;
        RBus_UInt32  res1:16;
    };
}di_di_smd_compensate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_new_method_sc_en:1;
        RBus_UInt32  rtnr_new_method_sc_mode:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  rtnr_new_method_sc_th:8;
        RBus_UInt32  res2:16;
    };
}di_im_di_rtnr_sc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly0:8;
        RBus_UInt32  cp_temporalthly1:8;
        RBus_UInt32  cp_temporalthly2:8;
        RBus_UInt32  cp_temporalthly3:8;
    };
}di_im_di_rtnr_y_16_th0_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly4:8;
        RBus_UInt32  cp_temporalthly5:8;
        RBus_UInt32  cp_temporalthly6:8;
        RBus_UInt32  cp_temporalthly7:8;
    };
}di_im_di_rtnr_y_16_th4_th7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly8:8;
        RBus_UInt32  cp_temporalthly9:8;
        RBus_UInt32  cp_temporalthly10:8;
        RBus_UInt32  cp_temporalthly11:8;
    };
}di_im_di_rtnr_y_16_th8_th11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthly12:8;
        RBus_UInt32  cp_temporalthly13:8;
        RBus_UInt32  cp_temporalthly14:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_y_16_th12_th14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthlc0:8;
        RBus_UInt32  cp_temporalthlc1:8;
        RBus_UInt32  cp_temporalthlc2:8;
        RBus_UInt32  cp_temporalthlc3:8;
    };
}di_im_di_rtnr_c_th0_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporalthlc4:8;
        RBus_UInt32  cp_temporalthlc5:8;
        RBus_UInt32  cp_temporalthlc6:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_c_th4_th6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_y_k0:4;
        RBus_UInt32  cp_temporal_y_k1:4;
        RBus_UInt32  cp_temporal_y_k2:4;
        RBus_UInt32  cp_temporal_y_k3:4;
        RBus_UInt32  cp_temporal_y_k4:4;
        RBus_UInt32  cp_temporal_y_k5:4;
        RBus_UInt32  cp_temporal_y_k6:4;
        RBus_UInt32  cp_temporal_y_k7:4;
    };
}di_im_di_rtnr_y_16_k0_k7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_y_k8:4;
        RBus_UInt32  cp_temporal_y_k9:4;
        RBus_UInt32  cp_temporal_y_k10:4;
        RBus_UInt32  cp_temporal_y_k11:4;
        RBus_UInt32  cp_temporal_y_k12:4;
        RBus_UInt32  cp_temporal_y_k13:4;
        RBus_UInt32  cp_temporal_y_k14:4;
        RBus_UInt32  cp_temporal_y_k15:4;
    };
}di_im_di_rtnr_y_16_k8_k15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_c_k0:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  cp_temporal_c_k1:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  cp_temporal_c_k2:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  cp_temporal_c_k3:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  cp_temporal_c_k4:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  cp_temporal_c_k5:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  cp_temporal_c_k6:3;
        RBus_UInt32  res7:1;
        RBus_UInt32  cp_temporal_c_k7:3;
        RBus_UInt32  res8:1;
    };
}di_im_di_rtnr_c_k_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_115_87:29;
    };
}di_di_datmemorystartadd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_86_58:29;
    };
}di_di_datmemorystartadd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_57_29:29;
    };
}di_di_datmemorystartadd3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_28_0:29;
    };
}di_di_datmemorystartadd4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  inf_mstart_57_29:29;
    };
}di_di_infmemorystartadd1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  inf_mstart_28_0:29;
    };
}di_di_infmemorystartadd2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_num_r:16;
        RBus_UInt32  dat_len_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  dat_water_r:8;
    };
}di_ddr_rdatdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_num_w:16;
        RBus_UInt32  dat_len_w:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  dat_water_w:8;
    };
}di_ddr_wdatdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dat_remain_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  dat_remain_w:7;
        RBus_UInt32  rdma_remain_en:1;
        RBus_UInt32  res2:16;
    };
}di_ddr_datdma_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_num_r:16;
        RBus_UInt32  inf_len_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  inf_water_r:8;
    };
}di_ddr_rinfdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_num_w:16;
        RBus_UInt32  inf_len_w:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  inf_water_w:8;
    };
}di_ddr_winfdma_wtlennum_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  inf_remain_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  inf_remain_w:7;
        RBus_UInt32  res2:17;
    };
}di_ddr_infdma_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_unfl:8;
        RBus_UInt32  ccdinr_ovfl:8;
        RBus_UInt32  ccdinr_flag_clr:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  ccdinr_fifoerr_ie:1;
    };
}di_ddr_dmastatus_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_wd_to_sub:1;
        RBus_UInt32  ccdinr_wd_to_main:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  ccdinr_fifoerr_wde_sub:1;
        RBus_UInt32  ccdinr_vs_reset_en:1;
        RBus_UInt32  ccdinr_fifoerr_wde:1;
    };
}di_ddr_wde_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  di1_wrrd_downlimit_adr:29;
    };
}di_di1_wrrd_boundaryaddr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  di1_wrrd_uplimit_adr:29;
    };
}di_di1_wrrd_boundaryaddr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di1_rd_uplimit_ov:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  di1_rd_downlimit_ov:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  di1_wr_uplimit_ov:2;
        RBus_UInt32  di1_wr_downlimit_ov:2;
        RBus_UInt32  di1_wrrd_downup_limit_ov_clearstatus:1;
        RBus_UInt32  res3:11;
    };
}di_di1_wrrd_boundaryadd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_3d_115_87:29;
    };
}di_di_datmemorystartadd1_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_3d_86_58:29;
    };
}di_di_datmemorystartadd2_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_3d_57_29:29;
    };
}di_di_datmemorystartadd3_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dat_mstart_3d_28_0:29;
    };
}di_di_datmemorystartadd4_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  inf_mstart_3d_57_29:29;
    };
}di_di_infmemorystartadd1_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  inf_mstart_3d_28_0:29;
    };
}di_di_infmemorystartadd2_3d_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_write_addr_l:29;
        RBus_UInt32  cp_line_dma_buffer_cnt:2;
        RBus_UInt32  res1:1;
    };
}di_di_line_base_dma_addr_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_write_addr_r:29;
        RBus_UInt32  res1:3;
    };
}di_di_line_base_dma_addr_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wdma_req_num:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  rdma_req_num:3;
        RBus_UInt32  res2:24;
        RBus_UInt32  dma_info_first:1;
    };
}di_di_dma_multi_req_num_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_tr2to1_bist_fail:3;
        RBus_UInt32  di_hmc_bist_fail:5;
        RBus_UInt32  di_li3_bist_fail:8;
        RBus_UInt32  di_li2_bist_fail:8;
        RBus_UInt32  di_li1_bist_fail:8;
    };
}di_dispi_bist_fail_separate_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  di_li5_bist_fail:5;
        RBus_UInt32  di_li4_bist_fail:8;
        RBus_UInt32  di_memc_film_bist_fail:2;
        RBus_UInt32  di_dma_rdat_bist_fail:8;
        RBus_UInt32  di_dma_wdat_bist_fail:8;
    };
}di_dispi_bist_fail_separate_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_tr2to1_drf_fail:3;
        RBus_UInt32  di_hmc_drf_fail:5;
        RBus_UInt32  di_li3_drf_fail:8;
        RBus_UInt32  di_li2_drf_fail:8;
        RBus_UInt32  di_li1_drf_fail:8;
    };
}di_dispi_drf_fail_separate_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  di_li5_drf_fail:5;
        RBus_UInt32  di_li4_drf_fail:8;
        RBus_UInt32  di_memc_film_drf_fail:2;
        RBus_UInt32  di_dma_rdat_drf_fail:8;
        RBus_UInt32  di_dma_wdat_drf_fail:8;
    };
}di_dispi_drf_fail_separate_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_dma_rdat_rme:1;
        RBus_UInt32  di_dma_wdat_rme:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  di_memc_film_rme:1;
        RBus_UInt32  di_tr2to1_rme:1;
        RBus_UInt32  di_hmc_rme:1;
        RBus_UInt32  di_li5_rme:1;
        RBus_UInt32  di_li4_rme:1;
        RBus_UInt32  di_li3_rme:1;
        RBus_UInt32  di_li2_rme:1;
        RBus_UInt32  di_li1_rme:1;
        RBus_UInt32  res2:21;
    };
}di_dispi_bist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  di_memc_film_rm:4;
        RBus_UInt32  di_tr2to1_rm:4;
        RBus_UInt32  di_hmc_rm:4;
        RBus_UInt32  di_li3_rm:4;
        RBus_UInt32  di_li2_rm:4;
        RBus_UInt32  di_li1_rm:4;
        RBus_UInt32  res2:4;
    };
}di_dispi_bist_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_dma_rdat_rm:4;
        RBus_UInt32  di_dma_wdat_rm:4;
        RBus_UInt32  di_li4_rm:4;
        RBus_UInt32  di_li5_rm:4;
        RBus_UInt32  res1:16;
    };
}di_dispi_bist_rm_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}di_dispi_bist_ls_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  db_apply:1;
        RBus_UInt32  db_en:1;
        RBus_UInt32  db_read:1;
        RBus_UInt32  res1:27;
        RBus_UInt32  sm_tog_3d_mode:1;
        RBus_UInt32  sm_tog_apply_disable:1;
    };
}di_db_reg_ctl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sm_tog_h_start:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  sm_tog_v_start:12;
        RBus_UInt32  res2:4;
    };
}di_sm_tog_tg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sm_tog_h_total:13;
        RBus_UInt32  res1:3;
        RBus_UInt32  sm_tog_v_total:13;
        RBus_UInt32  res2:3;
    };
}di_sm_tog_tg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ccdinr_debug_mode:3;
        RBus_UInt32  res1:29;
    };
}di_ccdinr_dbg_mux_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_partialweave:2;
        RBus_UInt32  dummy18024540_31_2:30;
    };
}di_di_smd_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin1:16;
        RBus_UInt32  smd_sad_his_bin0:16;
    };
}di_di_smd_sadhisbina_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin3:16;
        RBus_UInt32  smd_sad_his_bin2:16;
    };
}di_di_smd_sadhisbinb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin5:16;
        RBus_UInt32  smd_sad_his_bin4:16;
    };
}di_di_smd_sadhisbinc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin7:16;
        RBus_UInt32  smd_sad_his_bin6:16;
    };
}di_di_smd_sadhisbind_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin9:16;
        RBus_UInt32  smd_sad_his_bin8:16;
    };
}di_di_smd_sadhisbine_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin11:16;
        RBus_UInt32  smd_sad_his_bin10:16;
    };
}di_di_smd_sadhisbinf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin13:16;
        RBus_UInt32  smd_sad_his_bin12:16;
    };
}di_di_smd_sadhisbing_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sad_his_bin15:16;
        RBus_UInt32  smd_sad_his_bin14:16;
    };
}di_di_smd_sadhisbinh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmv1_max_ctr:16;
        RBus_UInt32  smd_gmv_ctr:16;
    };
}di_di_smd_gmvcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmv3_max_ctr:16;
        RBus_UInt32  smd_gmv2_max_ctr:16;
    };
}di_di_smd_gmvcoeff2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_firmwaremv_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_firmwaremv_x:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_gmv3_x:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_gmv2_y:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  smd_gmv2_x:3;
        RBus_UInt32  res5:1;
        RBus_UInt32  smd_gmv1_y:3;
        RBus_UInt32  res6:1;
        RBus_UInt32  smd_gmv1_x:3;
        RBus_UInt32  res7:4;
        RBus_UInt32  smd_gmv_old_method:1;
    };
}di_di_smd_gmvcoeff3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_vpan_upper_bound:4;
        RBus_UInt32  smd_vpan_jump_out:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_vpan_work_th:4;
        RBus_UInt32  smd_firmware_pan_sad_th:6;
        RBus_UInt32  smd_pg_no_pixel_ctr_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_searchmv_apply_sad_th:6;
        RBus_UInt32  smd_vpan_en:1;
        RBus_UInt32  smd_hardware_pan_en:1;
        RBus_UInt32  smd_searchmv_apply:1;
        RBus_UInt32  smd_firmware_pan:1;
        RBus_UInt32  smd_apply_result_mode:2;
    };
}di_di_smd_pan1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmv3_th:14;
        RBus_UInt32  smd_vpan_total_pixel:6;
        RBus_UInt32  smd_vpan_gmv1_pixel:6;
        RBus_UInt32  smd_enter_pan_ctr_th:6;
    };
}di_di_smd_pan2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_rebuild_pan_ctr:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_search_apply_th:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_addctr_gmv1_pixelth2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  smd_addctr_gmv1_pixelth1:6;
        RBus_UInt32  res4:2;
    };
}di_di_smd_pan3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_right_weave_blend:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_left_weave_blend:5;
        RBus_UInt32  smd_expanse_range:3;
        RBus_UInt32  smd_curr_teeth_gain_c:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_curr_teeth_offset_c:6;
        RBus_UInt32  smd_result_en:1;
        RBus_UInt32  smd_colony_expanse_type:1;
        RBus_UInt32  smd_colony_expanse_en:1;
        RBus_UInt32  smd_colony_drop_en:1;
        RBus_UInt32  smd_intra_en:1;
        RBus_UInt32  smd_full_search_mode:1;
    };
}di_di_smd_additionalcoeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_right_us_blend:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_left_us_blend:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_search_gmv_gain:3;
        RBus_UInt32  smd_search_gmv_offset:5;
        RBus_UInt32  smd_image_boundary_width:4;
        RBus_UInt32  smd_image_boundary_height:4;
    };
}di_di_smd_additionalcoeff2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_right_us_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_right_us_range:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  smd_left_us_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_left_us_range:5;
        RBus_UInt32  res4:1;
        RBus_UInt32  smd_zm_flag_control:1;
        RBus_UInt32  smd_sm_flag_control:1;
    };
}di_di_smd_additionalcoeff3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_v4highfreqth1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_v4highfreqth2:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_v4highfreqeffect:6;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_patterngenmode:1;
    };
}di_di_smd_v4highfreq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_en:1;
        RBus_UInt32  smd_zoommotion_type_sel:2;
        RBus_UInt32  smd_zoommotion_block_1_en:1;
        RBus_UInt32  smd_zoommotion_block_2_en:1;
        RBus_UInt32  smd_zoommotion_block_3_en:1;
        RBus_UInt32  smd_zoommotion_block_4_en:1;
        RBus_UInt32  smd_zoommotion_block_5_en:1;
        RBus_UInt32  smd_zoommotion_block_6_en:1;
        RBus_UInt32  smd_zoommotion_block_7_en:1;
        RBus_UInt32  smd_zoommotion_block_8_en:1;
        RBus_UInt32  smd_zoommotion_block_9_en:1;
        RBus_UInt32  smd_zoommotion_block_ratio_offset:4;
        RBus_UInt32  smd_zoommotion_vector_ratio:6;
        RBus_UInt32  smd_zoommotion_flag:2;
        RBus_UInt32  smd_zoommotion_continue_count:4;
        RBus_UInt32  smd_zoommotion_continue_th:4;
    };
}di_im_di_zoommotion_detector_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_x_1:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_zoommotion_x_2:12;
        RBus_UInt32  res2:4;
    };
}di_im_di_zoommotion_det_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_y_1:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  smd_zoommotion_y_2:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_zoommotion_det_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_estimation_min_sad:8;
        RBus_UInt32  smd_zoommotion_block_9_type:4;
        RBus_UInt32  res1:19;
        RBus_UInt32  smd_zoommotion_debugmode_en:1;
    };
}di_im_di_zoommotion_det_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_1_type:4;
        RBus_UInt32  smd_zoommotion_block_2_type:4;
        RBus_UInt32  smd_zoommotion_block_3_type:4;
        RBus_UInt32  smd_zoommotion_block_4_type:4;
        RBus_UInt32  smd_zoommotion_block_5_type:4;
        RBus_UInt32  smd_zoommotion_block_6_type:4;
        RBus_UInt32  smd_zoommotion_block_7_type:4;
        RBus_UInt32  smd_zoommotion_block_8_type:4;
    };
}di_im_di_zoommotion_det_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_1_total:16;
        RBus_UInt32  smd_zoommotion_block_1_max:16;
    };
}di_im_di_zoommotion_det_info_01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_2_total:16;
        RBus_UInt32  smd_zoommotion_block_2_max:16;
    };
}di_im_di_zoommotion_det_info_02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_3_total:16;
        RBus_UInt32  smd_zoommotion_block_3_max:16;
    };
}di_im_di_zoommotion_det_info_03_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_4_total:16;
        RBus_UInt32  smd_zoommotion_block_4_max:16;
    };
}di_im_di_zoommotion_det_info_04_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_5_total:16;
        RBus_UInt32  smd_zoommotion_block_5_max:16;
    };
}di_im_di_zoommotion_det_info_05_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_6_total:16;
        RBus_UInt32  smd_zoommotion_block_6_max:16;
    };
}di_im_di_zoommotion_det_info_06_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_7_total:16;
        RBus_UInt32  smd_zoommotion_block_7_max:16;
    };
}di_im_di_zoommotion_det_info_07_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_8_total:16;
        RBus_UInt32  smd_zoommotion_block_8_max:16;
    };
}di_im_di_zoommotion_det_info_08_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_block_9_total:16;
        RBus_UInt32  smd_zoommotion_block_9_max:16;
    };
}di_im_di_zoommotion_det_info_09_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_ma_framestha:8;
        RBus_UInt32  smd_zoommotion_ma_framerlvtha:8;
        RBus_UInt32  smd_zoommotion_ma_framehtha:8;
        RBus_UInt32  smd_zoommotion_ma_framemtha:8;
    };
}di_im_di_zoommotion_det_fm_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_ma_framesthb:8;
        RBus_UInt32  smd_zoommotion_ma_framerlvthb:8;
        RBus_UInt32  smd_zoommotion_ma_framehthb:8;
        RBus_UInt32  smd_zoommotion_ma_framemthb:8;
    };
}di_im_di_zoommotion_det_fm_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_zoommotion_ma_framesthc:8;
        RBus_UInt32  smd_zoommotion_ma_framerlvthc:8;
        RBus_UInt32  smd_zoommotion_ma_framehthc:8;
        RBus_UInt32  smd_zoommotion_ma_framemthc:8;
    };
}di_im_di_zoommotion_det_fm_th_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_en:1;
        RBus_UInt32  res1:7;
        RBus_UInt32  smd_slowmotion_min_sad_class_low:4;
        RBus_UInt32  smd_slowmotion_min_sad_class_high:4;
        RBus_UInt32  smd_slowmotion_vector_ratio:6;
        RBus_UInt32  smd_slowmotion_flag:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_slowmotion_continue_count:4;
        RBus_UInt32  smd_slowmotion_continue_th:4;
    };
}di_im_di_slowmotion_detector_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_count:16;
        RBus_UInt32  smd_vcompenen_count:16;
    };
}di_im_di_slowmotion_detector_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_ma_framestha:8;
        RBus_UInt32  smd_slowmotion_ma_framerlvtha:8;
        RBus_UInt32  smd_slowmotion_ma_framehtha:8;
        RBus_UInt32  smd_slowmotion_ma_framemtha:8;
    };
}di_im_di_slowmotion_det_fm_th_a_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_ma_framesthb:8;
        RBus_UInt32  smd_slowmotion_ma_framerlvthb:8;
        RBus_UInt32  smd_slowmotion_ma_framehthb:8;
        RBus_UInt32  smd_slowmotion_ma_framemthb:8;
    };
}di_im_di_slowmotion_det_fm_th_b_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_slowmotion_ma_framesthc:8;
        RBus_UInt32  smd_slowmotion_ma_framerlvthc:8;
        RBus_UInt32  smd_slowmotion_ma_framehthc:8;
        RBus_UInt32  smd_slowmotion_ma_framemthc:8;
    };
}di_im_di_slowmotion_det_fm_th_c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r15_pixelsum:16;
        RBus_UInt32  hmc_r16_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r13_pixelsum:16;
        RBus_UInt32  hmc_r14_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r11_pixelsum:16;
        RBus_UInt32  hmc_r12_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r9_pixelsum:16;
        RBus_UInt32  hmc_r10_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l8_pixelsum:16;
        RBus_UInt32  hmc_r8_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l10_pixelsum:16;
        RBus_UInt32  hmc_l9_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l12_pixelsum:16;
        RBus_UInt32  hmc_l11_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l14_pixelsum:16;
        RBus_UInt32  hmc_l13_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_16_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l16_pixelsum:16;
        RBus_UInt32  hmc_l15_pixelsum:16;
    };
}di_im_di_pan_detection_statistic_17_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv2weave_n:4;
        RBus_UInt32  gst_fmv2weave_p:4;
        RBus_UInt32  gst_search_zmv_offset:6;
        RBus_UInt32  gst_replace_sad:1;
        RBus_UInt32  gst_pregmv_needstable:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  gst_debug_fmv2weave:1;
        RBus_UInt32  gst_en:1;
    };
}di_di_gst_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_enter_origsad_offset:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  gst_enter_origsad_lowth:8;
        RBus_UInt32  res2:8;
    };
}di_di_gst_enter_origsadcheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_outofrange_fracsad_offset:8;
        RBus_UInt32  gst_outofrange_fracsadlowth:8;
        RBus_UInt32  gst_outofrange_origsad:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  gst_outofrange_check:1;
    };
}di_di_gst_outofrangecheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_freqnonmatch_fracsad_offset:8;
        RBus_UInt32  gst_freqnonmatch_fracsad_lowth:8;
        RBus_UInt32  gst_freqnonmatch_origsad:8;
        RBus_UInt32  res1:7;
        RBus_UInt32  gst_freqnonmatch_check:1;
    };
}di_di_gst_freqnonmatchcheck_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_spatialmv_sad_max:8;
        RBus_UInt32  smd_localmv_sad_max:8;
        RBus_UInt32  smd_gmv_sad_max:8;
        RBus_UInt32  smd_gmv_sad_th:7;
        RBus_UInt32  res1:1;
    };
}di_di_smd_candidatelimitsad_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his01:16;
        RBus_UInt32  gst_fmv_his00:16;
    };
}di_di_gst_fmvhisa_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his03:16;
        RBus_UInt32  gst_fmv_his02:16;
    };
}di_di_gst_fmvhisb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his05:16;
        RBus_UInt32  gst_fmv_his04:16;
    };
}di_di_gst_fmvhisc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his07:16;
        RBus_UInt32  gst_fmv_his06:16;
    };
}di_di_gst_fmvhisd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his09:16;
        RBus_UInt32  gst_fmv_his08:16;
    };
}di_di_gst_fmvhise_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his10:16;
        RBus_UInt32  res1:16;
    };
}di_di_gst_fmvhisf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his12:16;
        RBus_UInt32  gst_fmv_his11:16;
    };
}di_di_gst_fmvhisg_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his14:16;
        RBus_UInt32  gst_fmv_his13:16;
    };
}di_di_gst_fmvhish_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his16:16;
        RBus_UInt32  gst_fmv_his15:16;
    };
}di_di_gst_fmvhisi_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his18:16;
        RBus_UInt32  gst_fmv_his17:16;
    };
}di_di_gst_fmvhisj_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_fmv_his20:16;
        RBus_UInt32  gst_fmv_his19:16;
    };
}di_di_gst_fmvhisk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_sobel_search_min:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  hme_max_absolute_count:8;
        RBus_UInt32  hmc_even_mv_no_vectorteeth:1;
        RBus_UInt32  hmc_odd_mv_no_compesation:1;
        RBus_UInt32  hmc_mv_refine_en:1;
        RBus_UInt32  mc_dynamic_threshold_clip_en:1;
        RBus_UInt32  hmc_mv_refine_y_th:8;
        RBus_UInt32  hmc_dynamic_threshold_min_clip:3;
        RBus_UInt32  hmc_mv_refine_mor_en:1;
    };
}di_im_di_hmc_adjustable_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_mv_refine_cur_motion_th:8;
        RBus_UInt32  hmc_mv_refine_mor_same_th1_hh:6;
        RBus_UInt32  hmc_mv_refine_cur_motion_en:1;
        RBus_UInt32  hmc_follow_ma_result_en:1;
        RBus_UInt32  hmc_mv_refine_mor_zero_th1_hh:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  hmc_mv_refine_mor_noise_th:4;
        RBus_UInt32  hme_x_continued_counter:4;
    };
}di_im_di_hmc_adjustable2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_mv_refine_mor_same_th1:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  hmc_mv_refine_mor_zero_th1:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  hmc_mv_refine_mor_same_th2:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  hmc_mv_refine_mor_zero_th2:6;
        RBus_UInt32  res4:2;
    };
}di_im_di_hmc_adjustable3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_mv_refine_mor_hh_v_th:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hmc_mv_refine_mor_hh_h_th:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  hmc_mv_refine_sobel_diff_th:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  hmc_mv_refine_sobel_non_edge_th:4;
        RBus_UInt32  res4:3;
        RBus_UInt32  hmc_mv_refine_sobel_en:1;
    };
}di_im_di_hmc_adjustable4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  scene_change_cond2_th:16;
        RBus_UInt32  scene_change_cond1_th:11;
        RBus_UInt32  scene_change_debug_en:1;
        RBus_UInt32  scene_change_cond2_result:1;
        RBus_UInt32  scene_change_cond1_result:1;
        RBus_UInt32  scene_change_cond2_en:1;
        RBus_UInt32  scene_change_cond1_en:1;
    };
}di_im_di_sc_adjustment_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_me_fw_control_motion_vector_det:1;
        RBus_UInt32  pan_me_fw_control_motion_vector:6;
        RBus_UInt32  pan_mc_debug_en:1;
        RBus_UInt32  hmc_debug_en:1;
        RBus_UInt32  pan_me_select_mv_hist:1;
        RBus_UInt32  pan_mc_force_compensation_en:1;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_en:1;
        RBus_UInt32  pan_me_invalid_check_en:1;
        RBus_UInt32  pan_mc_rls_en:1;
        RBus_UInt32  pan_me_sub_pixel_mv_det_en:1;
        RBus_UInt32  pan_mc_adaptive_compensation_en:1;
        RBus_UInt32  pan_mc_compensation_vertical_intra_en:1;
        RBus_UInt32  hme_check_zero_mv_en:1;
        RBus_UInt32  hme_consider_mv_invalid_en:1;
        RBus_UInt32  hme_avoid_rltype_vertical_pan_en:1;
        RBus_UInt32  hme_prefer_even_mv_en:1;
        RBus_UInt32  hmc_mv_refine_sub_px_mv_en:1;
        RBus_UInt32  hmc_vertical_intra_en:1;
        RBus_UInt32  hmc_half_mv_blending_en:1;
        RBus_UInt32  dummy18024660_31:8;
    };
}di_im_di_hmc_pan_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_th0:6;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_th1:6;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_th2:6;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_1:4;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_2:4;
        RBus_UInt32  pan_me_sobel_diff_ref_y_add_bias_3:4;
        RBus_UInt32  res1:2;
    };
}di_im_di_hmc_pan_add_bias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_sum_max_ratio:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  pan_me_invalid_check_cnt_thd:5;
        RBus_UInt32  pan_me_invalid_check_maxmin_diff_thd:5;
        RBus_UInt32  pan_mc_rls_sobel_diff_min_th:5;
        RBus_UInt32  res2:9;
    };
}di_im_di_hmc_pan_control_par_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pan_mc_adaptive_compensation_teeth_thd:8;
        RBus_UInt32  hme_avoid_rltype_vertical_pan_rledge_thd:5;
        RBus_UInt32  hme_avoid_rltype_vertical_pan_nedge_thd:4;
        RBus_UInt32  hme_prefer_even_mv_ratio:5;
        RBus_UInt32  res1:2;
        RBus_UInt32  hmc_sub_pixel_diff_thd:8;
    };
}di_im_di_hmc_pan_control_par_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_vertical_intra_top_bot_diff_y:8;
        RBus_UInt32  hmc_vertical_intra_top_bot_diff_u:8;
        RBus_UInt32  hmc_vertical_intra_top_bot_diff_v:8;
        RBus_UInt32  hmc_vertical_intra_edge_yuv_diff:8;
    };
}di_im_di_hmc_pan_vertical_intra_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_vertical_intra_top_cur_diff_y:8;
        RBus_UInt32  hmc_vertical_intra_top_cur_diff_u:8;
        RBus_UInt32  hmc_vertical_intra_top_cur_diff_v:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_hmc_pan_vertical_intra_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_vertical_intra_cur_bot_diff_y:8;
        RBus_UInt32  hmc_vertical_intra_cur_bot_diff_u:8;
        RBus_UInt32  hmc_vertical_intra_cur_bot_diff_v:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_hmc_pan_vertical_intra_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
         RBus_UInt32  diffMinThd:10;
         RBus_UInt32  restIdx:6;
         RBus_UInt32  restIdxThd:16;
    };
}di_im_di_hmc_pan_dummy_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  diffMaxMin:16;
        RBus_UInt32  panConti_str:8;
        RBus_UInt32  panConti:8;
   };
}di_im_di_hmc_pan_dummy_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  panDeb_str:8;
        RBus_UInt32  panDeb:8;
        RBus_UInt32  dummy:16;
    };
}di_im_di_hmc_pan_dummy_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_en:1;
        RBus_UInt32  rtnr_ma_snr_mask:1;
        RBus_UInt32  rtnr_ma_snr_debug_mode_en:1;
        RBus_UInt32  rtnr_ma_snr_debug_mode_selection:2;
        RBus_UInt32  res1:3;
        RBus_UInt32  rtnr_ma_snr_blending_factor1:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor2:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor3:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor4:4;
        RBus_UInt32  rtnr_ma_snr_blending_factor5:4;
        RBus_UInt32  res2:4;
    };
}di_rtnr_ma_snr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_motion_th1_low:8;
        RBus_UInt32  rtnr_ma_snr_motion_th2_low:8;
        RBus_UInt32  rtnr_ma_snr_motion_th3_low:8;
        RBus_UInt32  rtnr_ma_snr_motion_th4_low:8;
    };
}di_rtnr_ma_snr_motion_th_low_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_motion_th1_high:8;
        RBus_UInt32  rtnr_ma_snr_motion_th2_high:8;
        RBus_UInt32  rtnr_ma_snr_motion_th3_high:8;
        RBus_UInt32  rtnr_ma_snr_motion_th4_high:8;
    };
}di_rtnr_ma_snr_motion_th_high_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_edge_th_low:8;
        RBus_UInt32  rtnr_ma_snr_edge_th_high:8;
        RBus_UInt32  res1:16;
    };
}di_rtnr_ma_snr_motion_edge_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_motion_slope1:8;
        RBus_UInt32  rtnr_ma_snr_motion_slope2:8;
        RBus_UInt32  rtnr_ma_snr_motion_slope3:8;
        RBus_UInt32  rtnr_ma_snr_motion_slope4:8;
    };
}di_rtnr_ma_snr_motion_th_slope_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_ma_snr_edge_curve_lo_th:8;
        RBus_UInt32  rtnr_ma_snr_edge_curve_slope:8;
        RBus_UInt32  rtnr_ma_snr_output_clamp:8;
        RBus_UInt32  rtnr_ma_snr_strength:4;
        RBus_UInt32  res1:4;
    };
}di_rtnr_ma_snr_strength_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_start:1;
        RBus_UInt32  nm_pixmove_en:1;
        RBus_UInt32  nm_debug_en:1;
        RBus_UInt32  nm_ref_y_en:1;
        RBus_UInt32  nm_varsel:2;
        RBus_UInt32  nm_debug_conti:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  nm_samplingbit:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  nm_fw_yref:8;
        RBus_UInt32  nm_fw_ydiff:8;
    };
}di_di_rtnr_nm_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_vardiff_thd:16;
        RBus_UInt32  nm_meandiff_thd:5;
        RBus_UInt32  res1:11;
    };
}di_di_rtnr_nm_varmean_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_varlow_thd:16;
        RBus_UInt32  nm_varhigh_thd:16;
    };
}di_di_rtnr_nm_var_thd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_topmargin:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nm_bottommargin:12;
        RBus_UInt32  res2:4;
    };
}di_di_rtnr_nm_margin0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_leftmargin:12;
        RBus_UInt32  res1:4;
        RBus_UInt32  nm_rightmargin:12;
        RBus_UInt32  res2:4;
    };
}di_di_rtnr_nm_margin1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd0:8;
        RBus_UInt32  noiselevel_thd1:8;
        RBus_UInt32  noiselevel_thd2:8;
        RBus_UInt32  noiselevel_thd3:8;
    };
}di_di_rtnr_nm_noiselevel_th0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd4:8;
        RBus_UInt32  noiselevel_thd5:8;
        RBus_UInt32  noiselevel_thd6:8;
        RBus_UInt32  noiselevel_thd7:8;
    };
}di_di_rtnr_nm_noiselevel_th1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd8:8;
        RBus_UInt32  noiselevel_thd9:8;
        RBus_UInt32  noiselevel_thd10:8;
        RBus_UInt32  noiselevel_thd11:8;
    };
}di_di_rtnr_nm_noiselevel_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noiselevel_thd12:8;
        RBus_UInt32  noiselevel_thd13:8;
        RBus_UInt32  noiselevel_thd14:8;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_noiselevel_th3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_noiselevel:4;
        RBus_UInt32  nm_sumvarnum:21;
        RBus_UInt32  res1:7;
    };
}di_di_rtnr_nm_infor1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nm_sumvar:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_infor2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_0:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_1:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_2:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_3:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_4:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_5:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_6:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_7:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_8:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_9:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_10:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_11:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_12:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_13:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_14:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist1_15:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist1_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_0:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_1:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_2:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_3:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_4:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_5:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_6:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_7:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_8:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_9:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_10:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_11:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_12:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_13:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_14:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2_15:20;
        RBus_UInt32  res1:12;
    };
}di_di_rtnr_nm_hist2_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_0:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_1:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_2:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_3:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_4:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_5:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_6:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_7:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_8:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_9:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_10:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_11:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_12:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_13:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_14:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hist2var_15:24;
        RBus_UInt32  res1:8;
    };
}di_di_rtnr_nm_hist2var_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_output_clamp_luma:8;
        RBus_UInt32  rtnr_output_clamp_chroma:8;
        RBus_UInt32  rtnr_output_clamp_en:1;
        RBus_UInt32  res1:15;
    };
}di_rtnr_output_clamp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_water_modeth:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  smd_water_offset:8;
        RBus_UInt32  smd_water_gain:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  smd_water_result:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_water_pan_disable:1;
        RBus_UInt32  smd_debugwaterflag:1;
        RBus_UInt32  smd_water_en:1;
    };
}di_di_smd_waterflag_ctr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_water_teeth:8;
        RBus_UInt32  smd_water_minteethy:8;
        RBus_UInt32  smd_water_intradiff_th:8;
        RBus_UInt32  smd_water_uv_offset:8;
    };
}di_di_smd_waterflag_ctr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_water_avgy_lowbound:8;
        RBus_UInt32  smd_water_avgy_offset:8;
        RBus_UInt32  smd_stillsad_max:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_stillsad_th:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_elseintra_en:1;
    };
}di_di_smd_waterflag_ctr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_searchmvapply_ctr:8;
        RBus_UInt32  smd_firmwarepan_sadmax:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  smd_gmvb_sadmin_th:4;
        RBus_UInt32  smd_streammv_gmv_diff:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  smd_hardwarepan_firststep:1;
    };
}di_di_smd_hardwarepan_modify1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_pg_minsad_th:8;
        RBus_UInt32  smd_pg_messlevel_th:8;
        RBus_UInt32  smd_pg_diffsad_th:6;
        RBus_UInt32  smd_close2gmv_mvselect:2;
        RBus_UInt32  smd_gmvc_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_gmvc_x:3;
        RBus_UInt32  res2:1;
    };
}di_di_smd_sampling_gmvc_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_gmvb_y:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_gmvb_x:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_hmin_sad_ctr:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  smd_vmin_sad_ctr:3;
        RBus_UInt32  smd_pg_close2gmv:1;
        RBus_UInt32  smd_close2gmv_edgectr:8;
        RBus_UInt32  smd_close2gmv_minctr:8;
    };
}di_di_smd_sampling_gmvb_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_subpixel_firmwarepan_fmv1:4;
        RBus_UInt32  gst_subpixel_firmwarepan_fmv2:4;
        RBus_UInt32  gst_subpixel_firmwarepan:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  gst_blend_weight:2;
        RBus_UInt32  gst_compensate_blending_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  gst_compensate_fmv8_en:1;
        RBus_UInt32  gst_compensate_fmv7_en:1;
        RBus_UInt32  gst_compensate_fmv6_en:1;
        RBus_UInt32  gst_compensate_fmv5_en:1;
        RBus_UInt32  gst_compensate_fmv4_en:1;
        RBus_UInt32  gst_compensate_fmv3_en:1;
        RBus_UInt32  gst_compensate_fmv2_en:1;
        RBus_UInt32  gst_compensate_fmv1_en:1;
        RBus_UInt32  gst_compensate_fmv0_en:1;
        RBus_UInt32  gst_pg_highpriority:1;
        RBus_UInt32  gst_integerpan_highpriority:1;
        RBus_UInt32  gst_subpixel_rlv2intra_en:1;
        RBus_UInt32  gst_subpixel_hardwarepan_en:1;
        RBus_UInt32  gst_debug_subpixel_pan:1;
        RBus_UInt32  gst_subpixel_compensate_en:1;
    };
}di_di_gst_compensate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_maxfmv_3:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  gst_maxfmv_2:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  gst_maxfmv_1:6;
        RBus_UInt32  res3:2;
        RBus_UInt32  gst_maxfmv_0:6;
        RBus_UInt32  res4:2;
    };
}di_di_gst_maxfmv_part1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_maxfmv_ctr4:16;
        RBus_UInt32  gst_maxfmv_4:6;
        RBus_UInt32  res1:10;
    };
}di_di_gst_maxfmv_part2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_maxfmv_ctr1:16;
        RBus_UInt32  gst_maxfmv_ctr0:16;
    };
}di_di_gst_maxfmv_part3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_maxfmv_ctr3:16;
        RBus_UInt32  gst_maxfmv_ctr2:16;
    };
}di_di_gst_maxfmv_part4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_subpixel_firmwarepan_sadmax:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  gst_subpixel_firmwarepan_sadmin:6;
        RBus_UInt32  res2:2;
        RBus_UInt32  gst_subpixel_pan_ratio:8;
    };
}di_di_gst_fmv_pan_coeff1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gst_quantizeddiff_gain:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  gst_quantizeddiff_offset:8;
        RBus_UInt32  gst_maxfmv_diff_th:8;
        RBus_UInt32  gst_fmvhist_sad_diff:6;
        RBus_UInt32  res2:2;
    };
}di_di_gst_fmv_pan_coeff2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ma_weavemode_check_th:8;
        RBus_UInt32  ma_weavemode_check_gain:4;
        RBus_UInt32  res1:19;
        RBus_UInt32  ma_weavemode_check_en:1;
    };
}di_di_ma_weavemode_check_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_r4_sum:16;
        RBus_UInt32  hmcnr_r5_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_r2_sum:16;
        RBus_UInt32  hmcnr_r3_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_c0_sum:16;
        RBus_UInt32  hmcnr_r1_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_l2_sum:16;
        RBus_UInt32  hmcnr_l1_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmcnr_l4_sum:16;
        RBus_UInt32  hmcnr_l3_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18024858_15_0:16;
        RBus_UInt32  hmcnr_l5_sum:16;
    };
}di_im_di_rtnr_hmcnr_statistic_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_c_th3:11;
        RBus_UInt32  res1:5;
        RBus_UInt32  cp_temporal_mad_y_th3:11;
        RBus_UInt32  res2:5;
    };
}di_im_di_rtnr_mad_y_th2_c_th2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_countery2:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_y_counter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_countery3:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_y_counter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_counteru2:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_u_counter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_counteru3:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_u_counter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_counterv2:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_v_counter_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_mad_counterv3:21;
        RBus_UInt32  res1:11;
    };
}di_im_di_rtnr_mad_v_counter_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_prgfilm_22_en:1;
        RBus_UInt32  memc_prgfilm_32_en:1;
        RBus_UInt32  memc_prgfilm_22_auto:1;
        RBus_UInt32  memc_prgfilm_32_auto:1;
        RBus_UInt32  memc_prgfilm_motion_cnt_avg_auto:1;
        RBus_UInt32  memc_prgfilm_motion_th:8;
        RBus_UInt32  memc_prgfilm_fw_film_idx:5;
        RBus_UInt32  res1:7;
        RBus_UInt32  memc_v_down_scale_factor:3;
        RBus_UInt32  res2:4;
    };
}di_memc_p_film_ctrl0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_prgfilm_22_detect_num:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  memc_prgfilm_32_detect_num:5;
        RBus_UInt32  res2:19;
    };
}di_memc_p_film_fr_num_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_prgfilm_fw_motion_cnt_avg:24;
        RBus_UInt32  res1:4;
        RBus_UInt32  memc_prgfilm_fw_22_detected:1;
        RBus_UInt32  memc_prgfilm_fw_32_detected:1;
        RBus_UInt32  memc_easy_stay_mode_22:1;
        RBus_UInt32  memc_easy_stay_mode_32:1;
    };
}di_memc_p_film_ctrl1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_abs_motion_thl:24;
        RBus_UInt32  memc_avg_thl_gain_01:5;
        RBus_UInt32  res1:3;
    };
}di_memc_p_film_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_prgfilm_motion_cnt:24;
        RBus_UInt32  memc_prgfilm_film_idx:5;
        RBus_UInt32  memc_prgfilm_22_detected:1;
        RBus_UInt32  memc_prgfilm_32_detected:1;
        RBus_UInt32  res1:1;
    };
}di_memc_p_film_read_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_film32_duration_f:12;
        RBus_UInt32  memc_n32_duration_f:12;
        RBus_UInt32  memc_p_factor:8;
    };
}di_memc_p_film_read1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_film32_freq:10;
        RBus_UInt32  memc_pre_film32_prob:12;
        RBus_UInt32  memc_frm_cnt:10;
    };
}di_memc_p_film_read2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_film22_duration_f:12;
        RBus_UInt32  memc_n22_duration_f:12;
        RBus_UInt32  memc_avg_thl_gain:5;
        RBus_UInt32  res1:3;
    };
}di_memc_p_film_read3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_film22_freq:10;
        RBus_UInt32  memc_pre_film22_prob:12;
        RBus_UInt32  res1:10;
    };
}di_memc_p_film_read4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_region_size_x:4;
        RBus_UInt32  memc_pass_factor:4;
        RBus_UInt32  memc_debounce_32_out_thl:10;
        RBus_UInt32  memc_debounce_32_in_thl:10;
        RBus_UInt32  res1:4;
    };
}di_memc_p_film_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  memc_debounce_22_out_thl:10;
        RBus_UInt32  memc_debounce_22_in_thl:10;
        RBus_UInt32  memc_fw_force_22:1;
        RBus_UInt32  memc_fw_force_32:1;
        RBus_UInt32  res1:10;
    };
}di_memc_p_film_ctrl4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_grey_uv_range:7;
        RBus_UInt32  fdc_grey_uv_range_en:1;
        RBus_UInt32  fdc_value:8;
        RBus_UInt32  fdc_value_pre:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_fading_detector_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_sum_inc:32;
    };
}di_im_di_rtnr_fading_info_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_pixels_inc:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_fading_info_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_sum_dec:32;
    };
}di_im_di_rtnr_fading_info_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_pixels_dec:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_fading_info_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_pixels_ignore_end:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_fading_info_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fdc_pixels_ignore_same:24;
        RBus_UInt32  res1:8;
    };
}di_im_di_rtnr_fading_info_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fm_dc_adaptive_same_th:7;
        RBus_UInt32  fm_dc_adaptive_en:1;
        RBus_UInt32  fm_dc_adaptive_same_count_th:4;
        RBus_UInt32  res1:4;
        RBus_UInt32  fm_dc_adaptive_pn_small_th:8;
        RBus_UInt32  fm_dc_adaptive_bias:6;
        RBus_UInt32  fm_dc_adaptive_bias_fw_ctrl:1;
        RBus_UInt32  fm_dc_debug_en:1;
    };
}di_im_di_ma_fading_apply_bias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fm_adaptive_bias_max_limit:8;
        RBus_UInt32  res1:8;
        RBus_UInt32  fm_noise_offset:8;
        RBus_UInt32  fm_noise_adaptive_bias:6;
        RBus_UInt32  fm_nosie_offset_ctrl:1;
        RBus_UInt32  fm_noise_adaptive_en:1;
    };
}di_im_di_ma_noise_apply_bias_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vhf_teeth_depth_th:5;
        RBus_UInt32  vhf_check_mode:2;
        RBus_UInt32  vhf_en:1;
        RBus_UInt32  vhf_fm_offset_th1:4;
        RBus_UInt32  vhf_fm_offset_th2:4;
        RBus_UInt32  vhf_fm_offset_th3:4;
        RBus_UInt32  vhf_fm_offset_th4:4;
        RBus_UInt32  vhf_energy_th0:8;
    };
}di_im_di_ma_vhf_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vhf_energy_th1:8;
        RBus_UInt32  vhf_energy_th2:8;
        RBus_UInt32  vhf_energy_th3:8;
        RBus_UInt32  vhf_energy_th4:8;
    };
}di_im_di_ma_vhf_ctrl2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vhf_energy_slop1:8;
        RBus_UInt32  vhf_energy_slop2:8;
        RBus_UInt32  vhf_energy_slop3:8;
        RBus_UInt32  vhf_energy_slop4:8;
    };
}di_im_di_ma_vhf_ctrl3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_src_lpf_clamp_en:1;
        RBus_UInt32  nintra_new_mode_en:1;
        RBus_UInt32  nintra_ydiff_mode:1;
        RBus_UInt32  nintra_vbound_detect_en:1;
        RBus_UInt32  nintra_search_min_limit_en:1;
        RBus_UInt32  nintra_high_freq_detect_en:1;
        RBus_UInt32  nintra_intersection_check_en:1;
        RBus_UInt32  nintra_dynamic_cross_th_en:1;
        RBus_UInt32  nintra_min_second_dir_check_en:1;
        RBus_UInt32  nintra_min_second_dir_check2_en:1;
        RBus_UInt32  nintra_pre_dir_check_en:1;
        RBus_UInt32  nintra_lowpass_dir_check_en:1;
        RBus_UInt32  nintra_preline_dir_check1_en:1;
        RBus_UInt32  nintra_preline_dir_check2_en:1;
        RBus_UInt32  nintra_dyn_dir_lowpass_en:1;
        RBus_UInt32  nintra_output_lowpass_en:1;
        RBus_UInt32  nintra_lowpass_dir_count_th:4;
        RBus_UInt32  nintra_check2_y_diff_th:8;
        RBus_UInt32  nintra_n_check2_control_disable:1;
        RBus_UInt32  nintra_ud_boundary_repeat_en:1;
        RBus_UInt32  res1:2;
    };
}di_im_di_nintra_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_lp_src_edge_th1:8;
        RBus_UInt32  nintra_lp_src_edge_th2:8;
        RBus_UInt32  nintra_lp_src_edge_slope:8;
        RBus_UInt32  nintra_lp_src_yclamp_th:8;
    };
}di_im_di_nintra_lowpass_source_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_hdiff_th1:8;
        RBus_UInt32  nintra_hdiff_th2:8;
        RBus_UInt32  nintra_dir_search_region_max:4;
        RBus_UInt32  res1:12;
    };
}di_im_di_nintra_search_dir_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_slopediff_th:8;
        RBus_UInt32  nintra_crossdiff_th:8;
        RBus_UInt32  nintra_crossslope_diff_th:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_nintra_intersection_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_minsecond_diff_th:8;
        RBus_UInt32  nintra_vertical_diff_th:8;
        RBus_UInt32  nintra_minsecond_diff_th2:8;
        RBus_UInt32  nintra_minsecond_diff_th3:8;
    };
}di_im_di_nintra_1st_2nd_ydiff_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nintra_hfq_hdiff_th:8;
        RBus_UInt32  nintra_trans_count_th1:8;
        RBus_UInt32  nintra_trans_count_th2:8;
        RBus_UInt32  res1:8;
    };
}di_im_di_nintra_high_freq_limit_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_refine_en:1;
        RBus_UInt32  hme_rf_c1_en:1;
        RBus_UInt32  hme_rf_c2_en:1;
        RBus_UInt32  hme_rf_c3_en:1;
        RBus_UInt32  hme_rf_c1_2mv_range_th:4;
        RBus_UInt32  hme_rf_c1_2max_diff_th:8;
        RBus_UInt32  hme_rf_c2_2mv_bin_ratio_th:4;
        RBus_UInt32  hme_rf_c2_mv_lineminindex_range_th:4;
        RBus_UInt32  hme_rf_c2_lineminindex_mv_bin_cnt_th:8;
    };
}di_im_di_hmc_me_refine_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_rf_c3_max_sdinvalidcount_ratio_th:5;
        RBus_UInt32  hmc_fw_ctrl_bypass:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hme_rf_c3_sobeldiffinvalidcount_th:8;
        RBus_UInt32  hmc_teeth_of_line_th:8;
        RBus_UInt32  hmc_teeth_total:8;
    };
}di_im_di_hmc_me_refine_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_pass_total:16;
        RBus_UInt32  hme_modify_dir_total:16;
    };
}di_im_di_hmc_me_refine_ctrl_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hme_rf_temporal_correction_th:7;
        RBus_UInt32  hme_rf_temporal_correction_en:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  hmc_pass_counter:16;
    };
}di_im_di_hmc_me_refine_ctrl_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_mv_refine_fail_counter:16;
        RBus_UInt32  hmc_fail_counter:16;
    };
}di_im_di_hmc_me_refine_ctrl_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_mcnr_new_en:1;
        RBus_UInt32  n_h_pan_flag:1;
        RBus_UInt32  n_h_pan_zeromv_penalty_en:1;
        RBus_UInt32  n_y_zero_mv_k_en:1;
        RBus_UInt32  n_zero_mv_gain8_en:1;
        RBus_UInt32  n_mv_diff_distance_select:1;
        RBus_UInt32  n_mv_avg_mode_select:1;
        RBus_UInt32  n_mv_avg_en:1;
        RBus_UInt32  n_c_zero_mv_k_en:1;
        RBus_UInt32  n_mcnr_weight_avg_en:1;
        RBus_UInt32  n_mcnr_weight_clamp_en:1;
        RBus_UInt32  n_rtnr_y_k_select:1;
        RBus_UInt32  n_mcnr_y_k_select_mc:1;
        RBus_UInt32  n_rtnr_c_k_select:1;
        RBus_UInt32  n_mcnr_debug_mode_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  n_mcnr_offset:4;
        RBus_UInt32  hori_boundary_th:4;
        RBus_UInt32  n_mcnr_debug_mode_select:2;
        RBus_UInt32  n_mcnr_smp_en:1;
        RBus_UInt32  n_mcnr_mv_diff_max_en:1;
        RBus_UInt32  n_mcnr_old_search_range_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  n_mcnr_mad_select:2;
    };
}di_im_new_mcnr_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  h_pan_mv_penalty:8;
        RBus_UInt32  h_pan_mv_value:5;
        RBus_UInt32  res1:19;
    };
}di_im_new_mcnr_pan_condition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mv_diff_th:8;
        RBus_UInt32  sad_min_th:8;
        RBus_UInt32  mv_diff_slope:4;
        RBus_UInt32  sad_min_slope:4;
        RBus_UInt32  res1:8;
    };
}di_im_new_mcnr_weighting_condition_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avg_mv_clamp_value:4;
        RBus_UInt32  mcnr_weight_clamp_upth:5;
        RBus_UInt32  mcnr_weight_clamp_loth:5;
        RBus_UInt32  res1:18;
    };
}di_im_new_mcnr_clamping_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l13_linesum:8;
        RBus_UInt32  hmc_l14_linesum:8;
        RBus_UInt32  hmc_l15_linesum:8;
        RBus_UInt32  hmc_l16_linesum:8;
    };
}di_im_di_hme_line_statistic_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l9_linesum:8;
        RBus_UInt32  hmc_l10_linesum:8;
        RBus_UInt32  hmc_l11_linesum:8;
        RBus_UInt32  hmc_l12_linesum:8;
    };
}di_im_di_hme_line_statistic_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l5_linesum:8;
        RBus_UInt32  hmc_l6_linesum:8;
        RBus_UInt32  hmc_l7_linesum:8;
        RBus_UInt32  hmc_l8_linesum:8;
    };
}di_im_di_hme_line_statistic_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_l1_linesum:8;
        RBus_UInt32  hmc_l2_linesum:8;
        RBus_UInt32  hmc_l3_linesum:8;
        RBus_UInt32  hmc_l4_linesum:8;
    };
}di_im_di_hme_line_statistic_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r3_linesum:8;
        RBus_UInt32  hmc_r2_linesum:8;
        RBus_UInt32  hmc_r1_linesum:8;
        RBus_UInt32  hmc_c0_linesum:8;
    };
}di_im_di_hme_line_statistic_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r7_linesum:8;
        RBus_UInt32  hmc_r6_linesum:8;
        RBus_UInt32  hmc_r5_linesum:8;
        RBus_UInt32  hmc_r4_linesum:8;
    };
}di_im_di_hme_line_statistic_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r11_linesum:8;
        RBus_UInt32  hmc_r10_linesum:8;
        RBus_UInt32  hmc_r9_linesum:8;
        RBus_UInt32  hmc_r8_linesum:8;
    };
}di_im_di_hme_line_statistic_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_r15_linesum:8;
        RBus_UInt32  hmc_r14_linesum:8;
        RBus_UInt32  hmc_r13_linesum:8;
        RBus_UInt32  hmc_r12_linesum:8;
    };
}di_im_di_hme_line_statistic_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hmc_linesum_step:4;
        RBus_UInt32  hmc_linesum_step_tolerance:4;
        RBus_UInt32  hmc_linesum_step_mv_diff_th:4;
        RBus_UInt32  res1:12;
        RBus_UInt32  hmc_r16_linesum:8;
    };
}di_im_di_hme_line_statistic_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_count:24;
        RBus_UInt32  res1:7;
        RBus_UInt32  di_ddr_comp_en:1;
    };
}di_di_ddr_checksum_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_127_96:32;
    };
}di_di_ddr_checksum_flag_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_95_64:32;
    };
}di_di_ddr_checksum_flag_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_63_32:32;
    };
}di_di_ddr_checksum_flag_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_flag_31_0:32;
    };
}di_di_ddr_checksum_flag_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_127_96:32;
    };
}di_di_ddr_checksum_mask_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_95_64:32;
    };
}di_di_ddr_checksum_mask_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_63_32:32;
    };
}di_di_ddr_checksum_mask_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  di_ddr_error_mask_31_0:32;
    };
}di_di_ddr_checksum_mask_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_hmcnr_search_range:4;
        RBus_UInt32  n_mcnr_v_search_range:2;
        RBus_UInt32  n_mcnr_v_pre_loadok:1;
        RBus_UInt32  n_mcnr_v_pre_loadok_clr:1;
        RBus_UInt32  n_mcnr_y_boundary_th:4;
        RBus_UInt32  n_mcnr_mv_penalty:4;
        RBus_UInt32  n_mcnr_mad_min_th:8;
        RBus_UInt32  n_mcnr_mad_min_uv_th:8;
    };
}di_im_new_mcnr_control2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_waterflow_protect_en:1;
        RBus_UInt32  smd_debugsawtooth_waterflow_en:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_currteethgain_wf:4;
        RBus_UInt32  smd_totalteethoffset_wf:4;
        RBus_UInt32  smd_compensate_teeth_th_wf:4;
        RBus_UInt32  smd_min_total_th_wf:4;
        RBus_UInt32  smd_sawtooth_count_th_wf:8;
        RBus_UInt32  res2:4;
    };
}di_di_smd_waterflow_teeth_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_sawtooth_count_wf:16;
        RBus_UInt32  res1:16;
    };
}di_di_smd_waterflow_teeth_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_outofrange_lpf_en:1;
        RBus_UInt32  smd_smd_blend_lpf_en:1;
        RBus_UInt32  smd_smd_blend_clamp_en:1;
        RBus_UInt32  smd_spatial_mv_diff_weight_en:1;
        RBus_UInt32  smd_smd_weight_out_debug_en:1;
        RBus_UInt32  smd_odd_mvy_ma_out_select:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  smd_spatial_mv_diff_coring:4;
        RBus_UInt32  smd_spatial_mv_diff_gain:4;
        RBus_UInt32  res2:16;
    };
}di_di_smd_ma_mc_weight_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_mcdi2madi_en:1;
        RBus_UInt32  smd_mcdi2madi_v_pan_new_en:1;
        RBus_UInt32  smd_mcdi2madi_debug_en:1;
        RBus_UInt32  smd_intra_weight_method:1;
        RBus_UInt32  smd_intra_weight_method_vpan:1;
        RBus_UInt32  smd_diag_count_th:3;
        RBus_UInt32  res1:24;
    };
}di_di_smd_diag_edge_protect_ctr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  smd_outofrange_content_new:1;
        RBus_UInt32  smd_sawtooth_condition_select:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  smd_acc_smd_en:1;
        RBus_UInt32  smd_spatialfreqnomatch_off:1;
        RBus_UInt32  smd_weave_dynamic:2;
        RBus_UInt32  smd_linecontinous_new_condition:1;
        RBus_UInt32  gst_min_sad_compare_diable:1;
        RBus_UInt32  gst_gst_static_disable:1;
        RBus_UInt32  gst_min_sad_nolimit_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  smd_weight_lpf_select:1;
        RBus_UInt32  res4:12;
        RBus_UInt32  smd_resurrectsmallwindownum2:4;
    };
}di_di_smd_slow_motion_handle1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  smd_reliablerangesadth2:8;
        RBus_UInt32  smd_resurrectminsadth2:8;
        RBus_UInt32  gst_mv_limit:2;
        RBus_UInt32  res1:14;
    };
}di_di_smd_slow_motion_handle2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_r9_sum:16;
        RBus_UInt32  mcnr_r10_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_r7_sum:16;
        RBus_UInt32  mcnr_r8_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_l6_sum:16;
        RBus_UInt32  mcnr_r6_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_l8_sum:16;
        RBus_UInt32  mcnr_l7_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_l10_sum:16;
        RBus_UInt32  mcnr_l9_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_u2_sum:16;
        RBus_UInt32  mcnr_u3_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_v0_sum:16;
        RBus_UInt32  mcnr_u1_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_d2_sum:16;
        RBus_UInt32  mcnr_d1_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mcnr_static_sum:16;
        RBus_UInt32  mcnr_d3_sum:16;
    };
}di_im_di_rtnr_mcnr_statistic_15_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_mcnr_k_factor_lpf_en:1;
        RBus_UInt32  n_mcnr_kfactor_lpf_method:1;
        RBus_UInt32  n_mcnr_kfactor_lpf_large_select:1;
        RBus_UInt32  n_mcnr_mv_mad_blending_en:1;
        RBus_UInt32  n_mcnr_mv_mad_mv_lo_th:4;
        RBus_UInt32  n_mcnr_messlevel_th:8;
        RBus_UInt32  n_mcnr_v_pan_mv:3;
        RBus_UInt32  n_mcnr_mv_mad_blending_vertical_en:1;
        RBus_UInt32  n_mcnr_mv_mad_mv_gap:2;
        RBus_UInt32  res1:10;
    };
}di_im_new_mcnr_control3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  n_mcnr_mad_offset:8;
        RBus_UInt32  n_mcnr_mad_uv_offset:8;
        RBus_UInt32  res1:16;
    };
}di_im_new_mcnr_mv_mad_offset_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cp_temporal_shiftbit:2;
        RBus_UInt32  cp_temporal_shiftbit_usermode:1;
        RBus_UInt32  cp_temporal_k128_mode:1;
        RBus_UInt32  res1:28;
    };
}di_im_di_rtnr_k128_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th0:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th0:8;
        RBus_UInt32  res1:16;
    };
}di_im_di_rtnr_new_sad_th_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_count_th7:5;
        RBus_UInt32  rtnr_statistic_motion_count_th8:5;
        RBus_UInt32  rtnr_statistic_motion_count_th0:5;
        RBus_UInt32  res1:17;
    };
}di_im_di_rtnr_new_sad_count_th_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_sad_th1:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th2:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th3:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th4:8;
    };
}di_im_di_rtnr_new_sta_motion_th_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_sad_th5:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th6:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th7:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th8:8;
    };
}di_im_di_rtnr_new_sta_motion_th_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_sad_th9:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th10:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th11:8;
        RBus_UInt32  rtnr_statistic_motion_sad_th12:8;
    };
}di_im_di_rtnr_new_sta_motion_th_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th0_1_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th1_2_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th2_3_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th3_4_slope:8;
    };
}di_im_di_rtnr_new_sad_edge_slope_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th4_5_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th5_6_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th6_7_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_edge_th7_8_slope:8;
    };
}di_im_di_rtnr_new_sad_edge_slope_4_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th0_1_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th1_2_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th2_3_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th3_4_slope:8;
    };
}di_im_di_rtnr_new_sad_nonedge_slope_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th4_5_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th5_6_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th6_7_slope:8;
        RBus_UInt32  rtnr_calculate_motion_sad_nonedge_th7_8_slope:8;
    };
}di_im_di_rtnr_new_sad_nonedge_slope_4_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_count_th0_1_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th1_2_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th2_3_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th3_4_slope:8;
    };
}di_im_di_rtnr_new_sta_motion_slope_0_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_statistic_motion_count_th4_5_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th5_6_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th6_7_slope:8;
        RBus_UInt32  rtnr_statistic_motion_count_th7_8_slope:8;
    };
}di_im_di_rtnr_new_sta_motion_slope_4_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_80:4;
        RBus_UInt32  rtnr_k_81:4;
        RBus_UInt32  rtnr_k_82:4;
        RBus_UInt32  rtnr_k_83:4;
        RBus_UInt32  rtnr_k_84:4;
        RBus_UInt32  rtnr_k_85:4;
        RBus_UInt32  rtnr_k_86:4;
        RBus_UInt32  rtnr_k_87:4;
    };
}di_im_di_rtnr_new_k_80_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_08:4;
        RBus_UInt32  rtnr_k_18:4;
        RBus_UInt32  rtnr_k_28:4;
        RBus_UInt32  rtnr_k_38:4;
        RBus_UInt32  rtnr_k_48:4;
        RBus_UInt32  rtnr_k_58:4;
        RBus_UInt32  rtnr_k_68:4;
        RBus_UInt32  rtnr_k_78:4;
    };
}di_im_di_rtnr_new_k_remain_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rtnr_k_88:4;
        RBus_UInt32  res1:28;
    };
}di_im_di_rtnr_new_k_remain_1_RBUS;




#endif 


#endif 
