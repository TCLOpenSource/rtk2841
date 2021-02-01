/**
* @file rbusAudio_IOReg.h
* RBus systemc program.
*
* @author RS_MM2_SD
* @email jason9.ccc@realtek.com
 * @date 2017/2/20
* @ingroup model_rbus
 * @version { 1.0 }
 **
 */

#ifndef _RBUS_AUDIO_REG_H_
#define _RBUS_AUDIO_REG_H_

#include "rbusTypes.h"


//  AUDIO Register Address



#define  AUDIO_GLOBAL_CTRL_0_VADDR                          	(0xb8006000)
#define  AUDIO_GLOBAL_CTRL_2_VADDR                          	(0xb8006038)
#define  AUDIO_GLOBAL_CTRL_1_VADDR                          	(0xb8006004)
#define  AUDIO_TCON0_ASRC_IP_VADDR                          	(0xb8006008)
#define  AUDIO_TCON1_ASRC_IP_VADDR                          	(0xb800600c)
#define  AUDIO_PLLCG_SPDIF_GAIN_CR0_VADDR                   	(0xb8006010)
#define  AUDIO_PLLCG_SPDIF_GAIN_CR1_VADDR                   	(0xb8006014)
#define  AUDIO_PLLCG_SPDIF_GAIN_CR2_VADDR                   	(0xb8006018)
#define  AUDIO_PLLCG_SPDIF_NUMBER_VADDR                     	(0xb800601c)
#define  AUDIO_PLLCG_SPDIF_BOUND_VADDR                      	(0xb8006020)
#define  AUDIO_GLOBAL_DUMMY_VADDR                           	(0xb8006024)
#define  AUDIO_TCON2_ASRC_IP_VADDR                          	(0xb8006028)
#define  AUDIO_PLL_64_512_DETECT_VADDR                       	(0xb8006030)
#define  AUDIO_PLL_64_512_1_DETECT_VADDR                     	(0xb8006034)
#define  AUDIO_INTERRUPT_EN_VADDR                           	(0xb8006050)
#define  AUDIO_INTERRUPT_STATUS_VADDR                       	(0xb8006054)
#define  AUDIO_AIO_TIMER_EN_VADDR                           	(0xb8006058)
#define  AUDIO_AIN_COUNTER_VADDR                            	(0xb800605c)
#define  AUDIO_AIN_COMPARE_VADDR                            	(0xb8006060)
#define  AUDIO_AOUT_COUNTER_VADDR                           	(0xb8006064)
#define  AUDIO_AOUT_COMPARE_VADDR                           	(0xb8006068)
#define  AUDIO_SW_DBG_REG_0_VADDR                           	(0xb8006070)
#define  AUDIO_SW_DBG_REG_1_VADDR                           	(0xb8006074)
#define  AUDIO_SW_DBG_REG_2_VADDR                           	(0xb8006078)
#define  AUDIO_SW_DBG_REG_3_VADDR                           	(0xb800607c)
#define  AUDIO_INT_EN_STATES_VADDR                          	(0xb8006080)
#define  AUDIO_I2S_IN_PRIMARY_VADDR                         	(0xb8006100)
#define  AUDIO_SPDIF_IN_VADDR                               	(0xb8006130)
#define  AUDIO_SPDIF_IN_CS_VADDR                            	(0xb8006134)
#define  AUDIO_SPDIF_IN_CS_2_VADDR                          	(0xb8006138)
#define  AUDIO_SPDIF_IN_CS_3_VADDR                          	(0xb800613c)
#define  AUDIO_SPDIF_IN_CS_4_VADDR                          	(0xb8006e00)
#define  AUDIO_SPDIF_IN_CS_5_VADDR                          	(0xb8006e04)
#define  AUDIO_SPDIF_IN_CS_6_VADDR                          	(0xb8006e08)
#define  AUDIO_SPDIF_IN_CS_7_VADDR                          	(0xb8006e0c)
#define  AUDIO_SPDIF_IN_CS_8_VADDR                          	(0xb8006e10)
#define  AUDIO_SPDIF_IN_CS_9_VADDR                          	(0xb8006e14)
#define  AUDIO_SPDIF_IN_CS_10_VADDR                         	(0xb8006e18)
#define  AUDIO_SPDIF_IN_CS_11_VADDR                         	(0xb8006e1c)
#define  AUDIO_SPDIF_IN_CS_12_VADDR                         	(0xb8006e20)
#define  AUDIO_SPDIF_IN_CS_13_VADDR                         	(0xb8006e24)
#define  AUDIO_SPDIF_PATTERN_SEARCH1_VADDR                  	(0xb8006ed0)
#define  AUDIO_SPDIF_PATTERN_SET1_VADDR                     	(0xb8006ed4)
#define  AUDIO_SPDIF_PATTERN_SEARCH2_VADDR                  	(0xb8006ed8)
#define  AUDIO_SPDIF_PATTERN_SET2_VADDR                     	(0xb8006edc)
#define  AUDIO_SPDIF_PAPB_SEARCH_VADDR                      	(0xb8006ee0)
#define  AUDIO_SPDIF_PAPB_VAL_VADDR                         	(0xb8006ee4)
#define  AUDIO_SPDIF_PAPB_VAL2_VADDR                        	(0xb8006ee8)
#define  AUDIO_SPDIF_PAPB_VAL3_VADDR                        	(0xb8006eec)
#define  AUDIO_SPDIF_PATTERN1_VAL_VADDR                     	(0xb8006ef0)
#define  AUDIO_SPDIF_PATTERN2_VAL_VADDR                     	(0xb8006ef4)
#define  AUDIO_I2S_OUT_VADDR                                	(0xb8006150)
#define  AUDIO_I2S_OUT_SEL_VADDR                            	(0xb8006154)
#define  AUDIO_I2S_OUT_SEL_2_VADDR                          	(0xb8006158)
#define  AUDIO_SPDIF_OUT_VADDR                              	(0xb8006170)
#define  AUDIO_SPDIF_OUT_CS_VADDR                           	(0xb8006174)
#define  AUDIO_SPDIF_OUT_CS_2_VADDR                         	(0xb8006178)
#define  AUDIO_SPDIF_OUT_2_VADDR                            	(0xb800617c)
#define  AUDIO_SPDIF_OUT_CS_3_VADDR                         	(0xb8006e30)
#define  AUDIO_SPDIF_OUT_CS_4_VADDR                         	(0xb8006e34)
#define  AUDIO_SPDIF_OUT_CS_5_VADDR                         	(0xb8006e38)
#define  AUDIO_SPDIF_OUT_CS_6_VADDR                         	(0xb8006e3c)
#define  AUDIO_SPDIF_OUT_CS_7_VADDR                         	(0xb8006e40)
#define  AUDIO_SPDIF_OUT_CS_8_VADDR                         	(0xb8006e44)
#define  AUDIO_SPDIF_OUT_CS_9_VADDR                         	(0xb8006e48)
#define  AUDIO_SPDIF_OUT_CS_10_VADDR                        	(0xb8006e4c)
#define  AUDIO_SPDIF_OUT_CS_11_VADDR                        	(0xb8006e50)
#define  AUDIO_SPDIF_OUT_CS_12_VADDR                        	(0xb8006e54)
#define  AUDIO_SPDIF_OUT_CS_13_VADDR                        	(0xb8006e58)
#define  AUDIO_SPDIF_OUT_CS_14_VADDR                        	(0xb8006e5c)
#define  AUDIO_SPDIF_OUT_1_VADDR                            	(0xb8006e60)
#define  AUDIO_SPDIF_OUT_1_CS_VADDR                         	(0xb8006e64)
#define  AUDIO_SPDIF_OUT_1_CS_2_VADDR                       	(0xb8006e68)
#define  AUDIO_SPDIF_OUT_1_2_VADDR                          	(0xb8006e6c)
#define  AUDIO_SPDIF_OUT_1_CS_3_VADDR                       	(0xb8006e70)
#define  AUDIO_SPDIF_OUT_1_CS_4_VADDR                       	(0xb8006e74)
#define  AUDIO_SPDIF_OUT_1_CS_5_VADDR                       	(0xb8006e78)
#define  AUDIO_SPDIF_OUT_1_CS_6_VADDR                       	(0xb8006e7c)
#define  AUDIO_SPDIF_OUT_1_CS_7_VADDR                       	(0xb8006e80)
#define  AUDIO_SPDIF_OUT_1_CS_8_VADDR                       	(0xb8006e84)
#define  AUDIO_SPDIF_OUT_1_CS_9_VADDR                       	(0xb8006e88)
#define  AUDIO_SPDIF_OUT_1_CS_10_VADDR                      	(0xb8006e8c)
#define  AUDIO_SPDIF_OUT_1_CS_11_VADDR                      	(0xb8006e90)
#define  AUDIO_SPDIF_OUT_1_CS_12_VADDR                      	(0xb8006e94)
#define  AUDIO_SPDIF_OUT_1_CS_13_VADDR                      	(0xb8006e98)
#define  AUDIO_SPDIF_OUT_1_CS_14_VADDR                      	(0xb8006e9c)
#define  AUDIO_SIF_AGC_EVAL_CNT_VADDR                       	(0xb8006180)
#define  AUDIO_SIF_AGC_OPTIMAL_VADDR                        	(0xb8006184)
#define  AUDIO_SIF_AGC_THRESHOLD_VADDR                      	(0xb8006188)
#define  AUDIO_SIF_AGC_STATUS_VADDR                         	(0xb800618c)
#define  AUDIO_SIF_AGC2_CTRL_VADDR                          	(0xb8006190)
#define  AUDIO_SIF_AGC2_STATUS_VADDR                        	(0xb8006194)
#define  AUDIO_SIF_AGC3_CTRL_VADDR                          	(0xb8006198)
#define  AUDIO_SIF_AGC3_CTRL_2_VADDR                        	(0xb800619c)
#define  AUDIO_PEAK_CONTORL_VADDR                           	(0xb80061a0)
#define  AUDIO_PEAK_CONTORL_L_0_VADDR                       	(0xb80061b0)
#define  AUDIO_PEAK_CONTROL_L_1_VADDR                       	(0xb80061b4)
#define  AUDIO_PEAK_STATUS_L_VADDR                          	(0xb80061b8)
#define  AUDIO_PEAK_STATUS_L_2_VADDR                        	(0xb80061bc)
#define  AUDIO_PEAK_CONTORL_R_0_VADDR                       	(0xb80061c0)
#define  AUDIO_PEAK_CONTORL_R_1_VADDR                       	(0xb80061c4)
#define  AUDIO_PEAK_STATUS_R_VADDR                          	(0xb80061c8)
#define  AUDIO_PEAK_STATUS_R_2_VADDR                        	(0xb80061cc)
#define  AUDIO_MSD_CRTL_WORD_VADDR                          	(0xb8006200)
#define  AUDIO_MSD_RESULT_VADDR                             	(0xb8006204)
#define  AUDIO_MSD_STATUS_VADDR                             	(0xb8006208)
#define  AUDIO_MAIN_TONE_THRESHOLD_VADDR                    	(0xb800620c)
#define  AUDIO_MAIN_TONE_THRESHOLD_HD_VADDR                 	(0xb8006210)
#define  AUDIO_BW_THRESHOLD_VADDR                           	(0xb8006214)
#define  AUDIO_MAIN_SUB_RATIO_VADDR                         	(0xb8006218)
#define  AUDIO_MSD_MAG_4_5_VADDR                            	(0xb800621c)
#define  AUDIO_MSD_MAG_4_28_VADDR                           	(0xb8006220)
#define  AUDIO_MSD_MAG_4_72_VADDR                           	(0xb8006224)
#define  AUDIO_MSD_MAG_5_5_VADDR                            	(0xb8006228)
#define  AUDIO_MSD_MAG_5_25_VADDR                           	(0xb800622c)
#define  AUDIO_MSD_MAG_5_74_VADDR                           	(0xb8006230)
#define  AUDIO_MSD_CARRIER_5_85_VADDR                       	(0xb8006234)
#define  AUDIO_MSD_CARRIER_5_95_VADDR                       	(0xb8006238)
#define  AUDIO_MSD_MAG_6_VADDR                              	(0xb800623c)
#define  AUDIO_MSD_MAG_6_25_VADDR                           	(0xb8006240)
#define  AUDIO_MSD_CARRIER_6_5_VADDR                        	(0xb8006244)
#define  AUDIO_MSD_MAG_6_552_VADDR                          	(0xb8006248)
#define  AUDIO_MSD_CARRIER_6_74_VADDR                       	(0xb800624c)
#define  AUDIO_MSD_FLAGS_VADDR                              	(0xb8006250)
#define  AUDIO_MSD_PROGRAMMABLE_FREQ_VADDR                  	(0xb8006254)
#define  AUDIO_THRESHOLD_MSD_CARRIER_FW_VADDR               	(0xb8006258)
#define  AUDIO_MSD_PROGRAMMABLE_FREQ_1_VADDR                	(0xb800625c)
#define  AUDIO_THRESHOLD_MSD_CARRIER_FW_1_VADDR             	(0xb8006260)
#define  AUDIO_MSD_PROGRAMMABLE_FREQ_2_VADDR                	(0xb8006264)
#define  AUDIO_THRESHOLD_MSD_CARRIER_FW_2_VADDR             	(0xb8006268)
#define  AUDIO_MSD_PROGRAMMABLE_FREQ_3_VADDR                	(0xb800626c)
#define  AUDIO_THRESHOLD_MSD_CARRIER_FW_3_VADDR             	(0xb8006270)
#define  AUDIO_MSD_PROGRAMMABLE_FREQ_4_VADDR                	(0xb8006274)
#define  AUDIO_THRESHOLD_MSD_CARRIER_FW_4_VADDR             	(0xb8006278)
#define  AUDIO_MSD_SECOND_REG_STD_VADDR                     	(0xb800627c)
#define  AUDIO_SECOND_MAIN_TONE_THRESHOLD_VADDR             	(0xb8006280)
#define  AUDIO_MSD_BIST_VADDR                               	(0xb8006284)
#define  AUDIO_MSD_MAIN_MAG_ORI1_VADDR                      	(0xb8006288)
#define  AUDIO_MSD_MAIN_MAG_ORI2_VADDR                      	(0xb800628c)
#define  AUDIO_MSD_GAIN_CTRL_VADDR                          	(0xb8006290)
#define  AUDIO_MSD_UPDATE_COUNT_VADDR                       	(0xb8006294)
#define  AUDIO_MODE_DETECT_VADDR                            	(0xb8006300)
#define  AUDIO_MD_CTRL_VADDR                                	(0xb8006310)
#define  AUDIO_MD_STATUS_1_VADDR                            	(0xb8006314)
#define  AUDIO_MD_STATUS_2_VADDR                            	(0xb8006318)
#define  AUDIO_MD_STATUS_3_VADDR                            	(0xb800631c)
#define  AUDIO_MD_GAIN_WINDOW_VADDR                         	(0xb8006320)
#define  AUDIO_MD_LIMIT_THRE_VADDR                          	(0xb8006324)
#define  AUDIO_CARRIER_FREQ_DEVIATION_CTRL_VADDR            	(0xb8006350)
#define  AUDIO_CARRIER_PHASE_DELTA_VADDR                    	(0xb8006354)
#define  AUDIO_A2_EIAJ_DC_FILTER_VADDR                      	(0xb8006358)
#define  AUDIO_TVDEMOD_DIGITAL_VOLUME_CONTROL_VADDR         	(0xb800635c)
#define  AUDIO_TVDEMOD_DIGITAL_VOLUME_CONTROL_2_VADDR       	(0xb8006e28)
#define  AUDIO_EQ_TVD_BP1_1_VADDR                           	(0xb8006ea0)
#define  AUDIO_EQ_TVD_BP1_2_VADDR                           	(0xb8006ea4)
#define  AUDIO_EQ_TVD_BP2_1_VADDR                           	(0xb8006ea8)
#define  AUDIO_EQ_TVD_BP2_2_VADDR                           	(0xb8006eac)
#define  AUDIO_EQ_TVD_BP_CONTROL_VADDR                      	(0xb8006eb0)
#define  AUDIO_EQ_TVD_BP_STATUS_VADDR                       	(0xb8006eb4)
#define  AUDIO_EQ_TVD_LP_VADDR                              	(0xb8006eb8)
#define  AUDIO_AM_VADDR                                     	(0xb8006360)
#define  AUDIO_BIST_AM_VADDR                                	(0xb8006364)
#define  AUDIO_SAP_BPF_STAGE1_1_VADDR                       	(0xb80063d0)
#define  AUDIO_SAP_BPF_STAGE1_2_VADDR                       	(0xb80063d4)
#define  AUDIO_SAP_BPF_STAGE1_3_VADDR                       	(0xb80063d8)
#define  AUDIO_SAP_BPF_STAGE2_1_VADDR                       	(0xb80063e0)
#define  AUDIO_SAP_BPF_STAGE2_2_VADDR                       	(0xb80063e4)
#define  AUDIO_SAP_BPF_STAGE2_3_VADDR                       	(0xb80063e8)
#define  AUDIO_SAP_BPF_STAGE3_1_VADDR                       	(0xb80063f0)
#define  AUDIO_SAP_BPF_STAGE3_2_VADDR                       	(0xb80063f4)
#define  AUDIO_SAP_BPF_STAGE3_3_VADDR                       	(0xb80063f8)
#define  AUDIO_BTSC_PILOT_THRES_VADDR                       	(0xb8006400)
#define  AUDIO_BTSC_PILOT_STATUS_VADDR                      	(0xb8006404)
#define  AUDIO_BTSC_SAP_THRESH_VADDR                        	(0xb8006408)
#define  AUDIO_BTSC_SAP_NOISE_TH_VADDR                      	(0xb800640c)
#define  AUDIO_BTSC_SAP_NOISE_VADDR                         	(0xb8006410)
#define  AUDIO_BTSC_SAP_STATUS_VADDR                        	(0xb8006414)
#define  AUDIO_BTSC_SAP_DEBOUNCE_VADDR                      	(0xb8006418)
#define  AUDIO_BTSC_SIF_FM_MAGNITUDE_VADDR                  	(0xb800641c)
#define  AUDIO_BTSC_TEST_MUX_SEL_VADDR                      	(0xb8006420)
#define  AUDIO_BTSC_DUMMY_VADDR                             	(0xb8006424)
#define  AUDIO_BTSC_PILOT_PHASE_DELTA_VADDR                 	(0xb8006428)
#define  AUDIO_PHASE_ERROR_PI_GAIN_VADDR                    	(0xb800642c)
#define  AUDIO_PHASE_ERR_THRESHOLD_VADDR                    	(0xb8006430)
#define  AUDIO_PHASE_ERR_THRESHOLD2_VADDR                   	(0xb8006434)
#define  AUDIO_FREQ_CORRECTION_VADDR                        	(0xb8006438)
#define  AUDIO_PHASE_ERROR_VADDR                            	(0xb800643c)
#define  AUDIO_A2_EIAJ_DEMOD_VADDR                          	(0xb8006450)
#define  AUDIO_A2_EIAJ_MAG_NOISE_SUB_VADDR                  	(0xb8006454)
#define  AUDIO_A2_EIAJ_MAG_NOISE_VADDR                      	(0xb8006458)
#define  AUDIO_MBIST_A2_EIAJ_DEMOD_RM_0_VADDR               	(0xb800645c)
#define  AUDIO_MBIST_A2_EIAJ_DEMOD_RM_1_VADDR               	(0xb8006460)
#define  AUDIO_MBIST_A2_EIAJ_DEMOD_RME_VADDR                	(0xb8006464)
#define  AUDIO_NICAM_DEMOD_VADDR                            	(0xb8006500)
#define  AUDIO_NICAM_DAGC_CTRL_VADDR                        	(0xb8006504)
#define  AUDIO_NICAM_DAGC_THRESHOLD_VADDR                   	(0xb8006508)
#define  AUDIO_NICAM_DAGC_MAG_VADDR                         	(0xb800650c)
#define  AUDIO_NICAM_DECODE_CTRL_VADDR                      	(0xb8006510)
#define  AUDIO_NICAM_DECODE_STATUS_VADDR                    	(0xb8006514)
#define  AUDIO_NICAM_AUTO_SWITCH_VADDR                      	(0xb8006518)
#define  AUDIO_NICAM_DEMOD_AUTO_RECOVERY_VADDR              	(0xb800651c)
#define  AUDIO_NICAM_BIT_ERROR_RATE_VADDR                   	(0xb8006520)
#define  AUDIO_NICAM_BER_WINDOW_VADDR                       	(0xb8006524)
#define  AUDIO_NICAM_SRC_MBIST_VADDR                        	(0xb8006528)
#define  AUDIO_DOWN_SAMPLE_CONTROL_FOR_PLAYBACK_VADDR       	(0xb8006550)
#define  AUDIO_DOWN_SAMPLE_FIFO_SOURCE_SEL_VADDR            	(0xb8006554)
#define  AUDIO_DOWN_SAMPLE_MBIST_RECODING_VADDR             	(0xb8006558)
#define  AUDIO_DOWN_SAMPLE_FIFO_PRE_SCALE_VADDR             	(0xb800655c)
#define  AUDIO_DOWN_SAMPLE_MBIST_RM_VADDR                   	(0xb8006560)
#define  AUDIO_DOWN_SAMPLE_MBIST_RME_VADDR                  	(0xb8006568)
#define  AUDIO_DOWN_SAMPLE_CONTROL_FOR_TS_VADDR             	(0xb80065a0)
#define  AUDIO_TS_DS_FIFO_MBIST_RM_VADDR                    	(0xb80065a4)
#define  AUDIO_TS_DS_FIFO_MBIST_RME_VADDR                   	(0xb80065a8)
#define  AUDIO_ADMA_CSR_VADDR                               	(0xb8006600)
#define  AUDIO_ADMA_WCONF_VADDR                             	(0xb8006604)
#define  AUDIO_ADMA_WSADR0_VADDR                            	(0xb8006608)
#define  AUDIO_ADMA_WSADR1_VADDR                            	(0xb800660c)
#define  AUDIO_ADMA_RCONF_VADDR                             	(0xb8006628)
#define  AUDIO_ADMA_WRCONF_VADDR                            	(0xb800662c)
#define  AUDIO_ADMA_RSADR0_VADDR                            	(0xb8006630)
#define  AUDIO_ADMA_RSADR1_VADDR                            	(0xb8006634)
#define  AUDIO_ADMA_RSADR2_VADDR                            	(0xb8006638)
#define  AUDIO_ADMA_RSADR3_VADDR                            	(0xb800663c)
#define  AUDIO_ADMA_RSADR4_VADDR                            	(0xb8006640)
#define  AUDIO_ADMA_RSADR5_VADDR                            	(0xb8006644)
#define  AUDIO_ADMA_CHCONF_VADDR                            	(0xb8006650)
#define  AUDIO_AUDIO_DMA_BIST_CONTROL_INDICATE_VADDR        	(0xb8006654)
#define  AUDIO_ARC_ADMA_CSR_VADDR                           	(0xb8006680)
#define  AUDIO_ARC_ADMA_RCONF_VADDR                         	(0xb8006684)
#define  AUDIO_ARC_ADMA_WRCONF_VADDR                        	(0xb8006688)
#define  AUDIO_ARC_ADMA_RSADR0_VADDR                        	(0xb800668c)
#define  AUDIO_ARC_ADMA_RSADR1_VADDR                        	(0xb8006690)
#define  AUDIO_ARC_ADMA_CHCONF_VADDR                        	(0xb8006694)
#define  AUDIO_ARC_DMA_BIST_CONTROL_INDICATE_VADDR          	(0xb8006698)
#define  AUDIO_TSADMA_CSR_VADDR                             	(0xb80066a0)
#define  AUDIO_TS_ADMA_WCONF_VADDR                          	(0xb80066a4)
#define  AUDIO_TS_ADMA_WSADR0_VADDR                         	(0xb80066a8)
#define  AUDIO_TS_ADMA_WSADR1_VADDR                         	(0xb80066ac)
#define  AUDIO_TS_ADMA_RCONF_VADDR                          	(0xb80066b0)
#define  AUDIO_TS_ADMA_WRCONF_VADDR                         	(0xb80066b4)
#define  AUDIO_TS_ADMA_RSADR0_VADDR                         	(0xb80066b8)
#define  AUDIO_TS_ADMA_RSADR1_VADDR                         	(0xb80066bc)
#define  AUDIO_TS_ADMA_RSADR2_VADDR                         	(0xb80066c0)
#define  AUDIO_TS_ADMA_CHCONF_VADDR                         	(0xb80066c4)
#define  AUDIO_TS_DMA_BIST_CONTROL_INDICATE_VADDR           	(0xb80066c8)
#define  AUDIO_TEST_DMA_CONTROL_REGISTER_VADDR              	(0xb80066e0)
#define  AUDIO_TEST_DMA_START_ADDRESS_VADDR                 	(0xb80066e4)
#define  AUDIO_TEST_DMA_STOP_ADDRESS_VADDR                  	(0xb80066e8)
#define  AUDIO_TEST_MODE_SELECT_VADDR                       	(0xb80066ec)
#define  AUDIO_TEST_CUR_ADDRESS_VADDR                       	(0xb80066f0)
#define  AUDIO_HW_PROCESS_CONTROL_VADDR                     	(0xb8006700)
#define  AUDIO_AUTO_VOLUME_CONTROL_0_VADDR                  	(0xb8006704)
#define  AUDIO_AVC_VOLUME_CONTROL_1_VADDR                   	(0xb8006708)
#define  AUDIO_AVC_VOLUME_CONTROL_2_VADDR                   	(0xb800670c)
#define  AUDIO_AVC_VOLUME_CONTROL_3_VADDR                   	(0xb8006820)
#define  AUDIO_AVC_GAIN_STEP_CONTROL_0_VADDR                	(0xb8006854)
#define  AUDIO_AVC_GAIN_STEP_CONTROL_1_VADDR                	(0xb8006858)
#define  AUDIO_SPATIAL_EFFECT_CONTROL_0_VADDR               	(0xb8006710)
#define  AUDIO_SPATIAL_EFFECT_CONTROL_1_VADDR               	(0xb8006714)
#define  AUDIO_EQ_HP_VADDR                                  	(0xb8006718)
#define  AUDIO_EQ_LP_VADDR                                  	(0xb800671c)
#define  AUDIO_EQ_BP1_1_VADDR                               	(0xb8006720)
#define  AUDIO_EQ_BP1_2_VADDR                               	(0xb8006724)
#define  AUDIO_EQ_BP2_1_VADDR                               	(0xb8006728)
#define  AUDIO_EQ_BP2_2_VADDR                               	(0xb800672c)
#define  AUDIO_EQ_BP3_1_VADDR                               	(0xb8006730)
#define  AUDIO_EQ_BP3_2_VADDR                               	(0xb8006734)
#define  AUDIO_EQ_BP4_1_VADDR                               	(0xb8006738)
#define  AUDIO_EQ_BP4_2_VADDR                               	(0xb800673c)
#define  AUDIO_EQ_BP5_1_VADDR                               	(0xb8006740)
#define  AUDIO_EQ_BP5_2_VADDR                               	(0xb8006744)
#define  AUDIO_EQ_BP6_1_VADDR                               	(0xb8006748)
#define  AUDIO_EQ_BP6_2_VADDR                               	(0xb800674c)
#define  AUDIO_EQ_BP7_1_VADDR                               	(0xb8006750)
#define  AUDIO_EQ_BP7_2_VADDR                               	(0xb8006754)
#define  AUDIO_EQ_CONTROL_REGISTER_VADDR                    	(0xb8006768)
#define  AUDIO_EQ_STATUS_REGISTER_VADDR                     	(0xb800676c)
#define  AUDIO_LR_LOUD_LP_VADDR                             	(0xb8006770)
#define  AUDIO_LR_LOUD_BP1_1_VADDR                          	(0xb8006774)
#define  AUDIO_LR_LOUD_BP1_2_VADDR                          	(0xb8006778)
#define  AUDIO_LR_LOUD_BP2_1_VADDR                          	(0xb800677c)
#define  AUDIO_LR_LOUD_BP2_2_VADDR                          	(0xb8006780)
#define  AUDIO_LOUDNESS_CONTROL_REGISTER_VADDR              	(0xb80067ac)
#define  AUDIO_LOUDNESS_STATUS_REGISTER_VADDR               	(0xb80067b0)
#define  AUDIO_DIGITAL_VOLUME_CONTROL_0_VADDR               	(0xb80067b4)
#define  AUDIO_DIGITAL_VOLUME_CONTROL_1_VADDR               	(0xb80067b8)
#define  AUDIO_LR_DIGITAL_VOLUME_CONTROL_VADDR              	(0xb80067bc)
#define  AUDIO_LSRS_DIGITAL_VOLUME_CONTROL_VADDR            	(0xb80067c0)
#define  AUDIO_CSW_DIGITAL_VOLUME_CONTROL_VADDR             	(0xb80067c4)
#define  AUDIO_DOUBLE_BUFFER_ACK_VADDR                      	(0xb80067c8)
#define  AUDIO_AVC2_CONTROL_1_CH01_VADDR                    	(0xb80067cc)
#define  AUDIO_AVC2_CONTROL_2_CH01_VADDR                    	(0xb80067d0)
#define  AUDIO_AVC2_CONTROL_3_CH01_VADDR                    	(0xb80067d4)
#define  AUDIO_AVC2_CONTROL_4_CH01_VADDR                    	(0xb80067d8)
#define  AUDIO_AVC2_CONTROL_5_CH01_VADDR                    	(0xb8006824)
#define  AUDIO_AVC2_CONTROL_6_CH01_VADDR                    	(0xb8006828)
#define  AUDIO_AVC2_CONTROL_7_CH01_VADDR                    	(0xb800682c)
#define  AUDIO_AVC2_GAIN_STEP_CONTROL_0_VADDR               	(0xb800684c)
#define  AUDIO_AVC2_GAIN_STEP_CONTROL_1_VADDR               	(0xb8006850)
#define  AUDIO_HW_OUT_TRANS_VADDR                           	(0xb800680c)
#define  AUDIO_SYSTEM_INT_EN_VADDR                          	(0xb8006810)
#define  AUDIO_AVC_LP_OUT_CONTROL_VADDR                     	(0xb8006814)
#define  AUDIO_DUMMY_6718_VADDR                             	(0xb8006818)
#define  AUDIO_DUMMY_671C_VADDR                             	(0xb800681c)
#define  AUDIO_HW_IN_PRE_SCALE_VADDR                        	(0xb8006830)
#define  AUDIO_HW_DISTORTION_CONTROL_0_VADDR                	(0xb8006834)
#define  AUDIO_HW_DISTORTION_CONTROL_1_VADDR                	(0xb8006838)
#define  AUDIO_AVC2_DISTORTION_CONTROL_VADDR                	(0xb800683c)
#define  AUDIO_AVC2_DISTORTION_STATUS_L_VADDR               	(0xb8006840)
#define  AUDIO_AVC2_DISTORTION_STATUS_R_VADDR               	(0xb8006844)
#define  AUDIO_HW_DISTORTION_CONTROL_GAIN_STEP_VADDR        	(0xb8006848)
#define  AUDIO_DRC_CONTROL_1_CH01_VADDR                     	(0xb8006884)
#define  AUDIO_DRC_CONTROL_2_CH01_VADDR                     	(0xb8006888)
#define  AUDIO_DRC_CONTROL_3_CH01_VADDR                     	(0xb800688c)
#define  AUDIO_DRC_CONTROL_4_CH01_VADDR                     	(0xb8006890)
#define  AUDIO_DRC_CONTROL_5_CH01_VADDR                     	(0xb8006894)
#define  AUDIO_DRC_CONTROL_6_CH01_VADDR                     	(0xb8006898)
#define  AUDIO_DRC_CONTROL_7_CH01_VADDR                     	(0xb800689c)
#define  AUDIO_DRC_GAIN_STEP_CONTROL_0_VADDR                	(0xb80068a0)
#define  AUDIO_DRC_GAIN_STEP_CONTROL_1_VADDR                	(0xb80068a4)
#define  AUDIO_DRC_LPF_CONTROL_1_CH01_VADDR                 	(0xb80068a8)
#define  AUDIO_DRC_LPF_CONTROL_2_CH01_VADDR                 	(0xb80068ac)
#define  AUDIO_DRC_LPF_CONTROL_3_CH01_VADDR                 	(0xb80068b0)
#define  AUDIO_DRC_LPF_CONTROL_4_CH01_VADDR                 	(0xb80068b4)
#define  AUDIO_DRC_LPF_CONTROL_5_CH01_VADDR                 	(0xb80068b8)
#define  AUDIO_DRC_LPF_CONTROL_6_CH01_VADDR                 	(0xb80068bc)
#define  AUDIO_DRC_LPF_CONTROL_7_CH01_VADDR                 	(0xb80068c0)
#define  AUDIO_DRC_LPF_GAIN_STEP_CONTROL_0_VADDR            	(0xb80068c4)
#define  AUDIO_DRC_LPF_GAIN_STEP_CONTROL_1_VADDR            	(0xb80068c8)
#define  AUDIO_DRC_MBIST_RM_VADDR                           	(0xb80068cc)
#define  AUDIO_DRC_MBIST_RME_VADDR                          	(0xb80068d0)
#define  AUDIO_LRRR_DIGITAL_VOLUME_CONTROL_0_VADDR          	(0xb8006900)
#define  AUDIO_LRRR_DIGITAL_VOLUME_CONTROL_1_VADDR          	(0xb8006904)
#define  AUDIO_LRRR_DIGITAL_VOLUME_CONTROL_2_VADDR          	(0xb8006908)
#define  AUDIO_TS_DS_MBIST_RECODING_VADDR                   	(0xb800690c)
#define  AUDIO_DVOL_CONTROL_VADDR                           	(0xb8006910)
#define  AUDIO_TEST_PATTERN_GEN_VADDR                       	(0xb8006a00)
#define  AUDIO_CRC_HEADER_VADDR                             	(0xb8006a04)
#define  AUDIO_CRC_CONTORL_VADDR                            	(0xb8006a08)
#define  AUDIO_CRC_STATUS_VADDR                             	(0xb8006a0c)
#define  AUDIO_SINE_AUTO_CHK_VADDR                          	(0xb8006a10)
#define  AUDIO_SINE_WAVE_VALUE_VADDR                        	(0xb8006a14)
#define  AUDIO_PATTERN_GEN_DUMMY_VADDR                      	(0xb8006a18)
#define  AUDIO_RBUS_ACK_CTRL_VADDR                          	(0xb8006a50)
#define  AUDIO_ACK_FAIL_INFO_VADDR                          	(0xb8006a54)
#define  AUDIO_AUDIO_BIST_MODE_VADDR                        	(0xb8006c00)
#define  AUDIO_AUDIO_BIST_DONE_VADDR                        	(0xb8006c04)
#define  AUDIO_AUDIO_BIST_FAIL_GROUP_VADDR                  	(0xb8006c08)
#define  AUDIO_AUDIO_BIST_A2_EIAJ_FAIL_VADDR                	(0xb8006c0c)
#define  AUDIO_AUDIO_DRF_MODE_VADDR                         	(0xb8006c10)
#define  AUDIO_AUDIO_DRF_RESUME_VADDR                       	(0xb8006c14)
#define  AUDIO_AUDIO_DRF_DONE_VADDR                         	(0xb8006c18)
#define  AUDIO_AUDIO_DRF_PAUSE_VADDR                        	(0xb8006c1c)
#define  AUDIO_AUDIO_DRF_FAIL_GROUP_VADDR                   	(0xb8006c20)
#define  AUDIO_AUDIO_DRF_A2_EIAJ_FAIL_VADDR                 	(0xb8006c24)
#define  AUDIO_AUDIO_DRF_HW_DRC_FAIL_VADDR                  	(0xb8006c28)
#define  AUDIO_AUDIO_BIST_HW_DRC_FAIL_VADDR                 	(0xb8006c2c)
#define  AUDIO_AD0_ASRC_IP_VADDR                            	(0xb8006b00)
#define  AUDIO_DA0_ASRC_IP_VADDR                            	(0xb8006b08)
#define  AUDIO_DA1_ASRC_IP_VADDR                            	(0xb8006b0c)
#define  AUDIO_DAC0_1_SRC_SEL_VADDR                         	(0xb8006b10)
#define  AUDIO_ADC_DIGITAL_VOLUME_CONTROL_0_VADDR           	(0xb8006b14)
#define  AUDIO_ADC_DIGITAL_VOLUME_CONTROL_1_VADDR           	(0xb8006b18)
#define  AUDIO_ADC_LR_DIGITAL_VOLUME_CONTROL_VADDR          	(0xb8006b1c)
#define  AUDIO_ADC_LSRS_DIGITAL_VOLUME_CONTROL_VADDR        	(0xb8006b20)
#define  AUDIO_ADC_DOUBLE_BUFFER_ACK_VADDR                  	(0xb8006b24)
#define  AUDIO_ADC_DOUBLE_BUFFER_ACK_1_VADDR                	(0xb8006b28)
#define  AUDIO_ANALOG_FRONTEND1_MUTE_VADDR                  	(0xb8006b30)
#define  AUDIO_ANALOG_AIO_HPOUT_LINEOUT_L_VADDR             	(0xb8006b38)
#define  AUDIO_ANALOG_AIO_HPOUT_LINEOUT_R_VADDR             	(0xb8006b3c)
#define  AUDIO_ADC_VOLUME_GAIN_CONTROL_VADDR                	(0xb8006b40)
#define  AUDIO_ANALOG_POWER_VADDR                           	(0xb8006b44)
#define  AUDIO_ANALOG_PGA_VADDR                             	(0xb8006b48)
#define  AUDIO_ANALOG_CI01_VADDR                            	(0xb8006b4c)
#define  AUDIO_ANALOG_CI02_VADDR                            	(0xb8006b50)
#define  AUDIO_ANALOG_DEPOP1_VADDR                          	(0xb8006b58)
#define  AUDIO_ANALOG_DEPOP2_VADDR                          	(0xb8006b5c)
#define  AUDIO_ANALOG_POST_GAIN_VADDR                       	(0xb8006b60)
#define  AUDIO_ANALOG_OUT_COPY_SWAP_VADDR                   	(0xb8006b64)
#define  AUDIO_ANALOG_GPIO_VADDR                            	(0xb8006b6c)
#define  AUDIO_DRF_BIST_VADDR                               	(0xb8006b74)
#define  AUDIO_ANALOG_DUMMY2_VADDR                          	(0xb8006b78)



#ifndef LITTLE_ENDIAN //apply BIG_ENDIAN

//======AUDIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  inv_ad_128fs:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  div_pre_512fs_ts:2;
        RBus_UInt32  frontend_clkgate_enable:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  div_dma_r_512fs:2;
        RBus_UInt32  div_tsdma_r_512fs:2;
        RBus_UInt32  play_r_adc_512fs_sel:2;
        RBus_UInt32  play_r_adc_512fs_sel_ts:2;
        RBus_UInt32  sel_64fs_ts:3;
        RBus_UInt32  sel_64fs:3;
        RBus_UInt32  div_arcdma_r_512fs:2;
        RBus_UInt32  play_r_adc_512fs_sel_arc:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  sel_clk_adc_fsi:1;
        RBus_UInt32  sel_clk_dac0_fsi:1;
        RBus_UInt32  sel_clk_dac1_fsi:1;
        RBus_UInt32  res5:2;
    };
}audio_global_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_clk_i2s_out:3;
        RBus_UInt32  res1:13;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_pcr_clk_0_sel:2;
        RBus_UInt32  res3:3;
        RBus_UInt32  tv_demod_en:1;
        RBus_UInt32  i2s_out_en:1;
        RBus_UInt32  i2s_in_en:1;
        RBus_UInt32  spdif_out_en:1;
        RBus_UInt32  spdif_in_en:1;
        RBus_UInt32  sel_clk_spdif_out:2;
        RBus_UInt32  sel_clk_spdif_out_1:2;
    };
}audio_global_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_sram_on:1;
        RBus_UInt32  dac_sram_on:1;
        RBus_UInt32  am_sram_on:1;
        RBus_UInt32  a2_eiaj_sram_on:1;
        RBus_UInt32  inv_da_128fs:1;
        RBus_UInt32  inv_da_128fs_ts:1;
        RBus_UInt32  src_da_128fs:1;
        RBus_UInt32  src_da_128fs_ts:1;
        RBus_UInt32  hdv_mode_sel:1;
        RBus_UInt32  sif_adc_clk_sel:2;
        RBus_UInt32  sif_adc_clk_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  sel_play_r_ck_source_arc:2;
        RBus_UInt32  spdif_nicam:1;
        RBus_UInt32  adc_512fs_sel_ts:2;
        RBus_UInt32  sel_ts_ck_source:2;
        RBus_UInt32  back_end_ts_sample_rate:2;
        RBus_UInt32  sel_play_r_ck_source_ts:2;
        RBus_UInt32  adc_512fs_sel:2;
        RBus_UInt32  sel_play_ck_source:2;
        RBus_UInt32  back_end_play_sample_rate:2;
        RBus_UInt32  sel_play_r_ck_source:2;
    };
}audio_global_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  asrcin0_fsi_rate_manual:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_tcon0_rst_n:1;
        RBus_UInt32  asrcin0_ftk_loop_filter_mode:1;
        RBus_UInt32  asrcin0_ftk_loop_gain_sel:1;
        RBus_UInt32  asrcin0_div_fsi:2;
        RBus_UInt32  asrcin0_ftk_sdm_ini:22;
    };
}audio_tcon0_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  asrcin1_fsi_rate_manual:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_tcon1_rst_n:1;
        RBus_UInt32  asrcin1_ftk_loop_filter_mode:1;
        RBus_UInt32  asrcin1_ftk_loop_gain_sel:1;
        RBus_UInt32  asrcin1_div_fsi:2;
        RBus_UInt32  asrcin1_ftk_sdm_ini:22;
    };
}audio_tcon1_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  contword_inv:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  div_2fs:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  reg_para_e:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  ps_testmode:1;
        RBus_UInt32  pll_spdif_dtrack_en:1;
        RBus_UInt32  reg_smooth_en:1;
        RBus_UInt32  pll_spdif_auto_mode:1;
        RBus_UInt32  mod_acc_rst:1;
        RBus_UInt32  reg_para_d:5;
        RBus_UInt32  reg_para_b:7;
        RBus_UInt32  reg_para_a:6;
    };
}audio_pllcg_spdif_gain_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  p_gain_set:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  p_gain_set2:10;
    };
}audio_pllcg_spdif_gain_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  i_gain_set:10;
    };
}audio_pllcg_spdif_gain_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:25;
        RBus_UInt32  reach_time_num:3;
        RBus_UInt32  max_correct_range:4;
    };
}audio_pllcg_spdif_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  high_bound1:8;
        RBus_UInt32  low_bound1:8;
        RBus_UInt32  high_bound2:8;
        RBus_UInt32  low_bound2:8;
    };
}audio_pllcg_spdif_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006024_31_19:13;
        RBus_UInt32  res1:2;
        RBus_UInt32  inv_ck512fs_pll_spdif:1;
        RBus_UInt32  res2:4;
        RBus_UInt32  phase_contword:5;
        RBus_UInt32  wdog_switch_en_1:1;
        RBus_UInt32  freq_sel_1:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  wdog_switch_en:1;
        RBus_UInt32  freq_sel:2;
    };
}audio_global_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  asrcin2_fsi_rate_manual:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_tcon2_rst_n:1;
        RBus_UInt32  asrcin2_ftk_loop_filter_mode:1;
        RBus_UInt32  asrcin2_ftk_loop_gain_sel:1;
        RBus_UInt32  asrcin2_div_fsi:2;
        RBus_UInt32  asrcin2_ftk_sdm_ini:22;
    };
}audio_tcon2_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cnt_debug:8;
        RBus_UInt32  pll_64_512fs_unstable:1;
        RBus_UInt32  pll_64_512_detect_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  deta:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  average_value:7;
    };
}audio_pll_64_512_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  cnt_debug_1:8;
        RBus_UInt32  pll_64_512fs_1_unstable:1;
        RBus_UInt32  pll_64_512_1_detect_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  deta_1:7;
        RBus_UInt32  res3:1;
        RBus_UInt32  average_value_1:7;
    };
}audio_pll_64_512_1_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_nicam_true_detect_en:1;
        RBus_UInt32  int_fifo0_ts_full_en:1;
        RBus_UInt32  int_fifo0_ts_empty_en:1;
        RBus_UInt32  int_pll64512_wd_en:1;
        RBus_UInt32  int_msd_decision_done_en:1;
        RBus_UInt32  int_msd_fw_scan_done_en:1;
        RBus_UInt32  int_rbus_timeout_en:1;
        RBus_UInt32  int_btsc_mode_chg_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  int_fifo0_full_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  int_fifo0_empty_en:1;
        RBus_UInt32  int_nicam_level_status_en:1;
        RBus_UInt32  int_ain_timer_en:1;
        RBus_UInt32  int_aout_timer_en:1;
        RBus_UInt32  int_spi_in_datatype_change_en:1;
        RBus_UInt32  int_spi_in_lock_change_en:1;
        RBus_UInt32  int_nicam_hierr_change_en:1;
        RBus_UInt32  int_i2s_pri_sample_rate_chg_en:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  int_spi_sample_rate_chg_en:1;
        RBus_UInt32  int_i2s_pri_word_length_change_en:1;
        RBus_UInt32  int_pll64512_wd_en_1:1;
        RBus_UInt32  int_sif_nopt_en:1;
        RBus_UInt32  int_msd_change_en:1;
        RBus_UInt32  int_msd_timeout_en:1;
        RBus_UInt32  int_mode_det_status_change_en:1;
        RBus_UInt32  int_sif_ovf_en:1;
    };
}audio_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_nicam_true_detect:1;
        RBus_UInt32  int_fifo0_ts_full:1;
        RBus_UInt32  int_fifo0_ts_empty:1;
        RBus_UInt32  int_pll64512_wd:1;
        RBus_UInt32  int_msd_decision_done:1;
        RBus_UInt32  int_msd_fw_scan_done:1;
        RBus_UInt32  int_rbus_timeout:1;
        RBus_UInt32  int_btsc_mode_chg:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  int_fifo0_full:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  int_fifo0_empty:1;
        RBus_UInt32  int_nicam_level_status:1;
        RBus_UInt32  int_ain_timer:1;
        RBus_UInt32  int_aout_timer:1;
        RBus_UInt32  int_spi_in_datatype_change:1;
        RBus_UInt32  int_spi_in_lock_change:1;
        RBus_UInt32  int_nicam_hierr_change:1;
        RBus_UInt32  int_i2s_pri_sample_rate_chg:1;
        RBus_UInt32  int_mic_short_status:1;
        RBus_UInt32  int_spi_sample_rate_chg:1;
        RBus_UInt32  int_i2s_pri_word_length_change:1;
        RBus_UInt32  int_pll64512_wd_1:1;
        RBus_UInt32  int_sif_nopt:1;
        RBus_UInt32  int_msd_change:1;
        RBus_UInt32  int_msd_timeout:1;
        RBus_UInt32  int_mode_det_status_change:1;
        RBus_UInt32  int_sif_ovf:1;
    };
}audio_interrupt_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  timer_clr_mode_sel:1;
        RBus_UInt32  timer_div:3;
        RBus_UInt32  ain_timer_src:2;
        RBus_UInt32  aout_timer_src:2;
        RBus_UInt32  ain_timer_en:1;
        RBus_UInt32  aout_timer_en:1;
    };
}audio_aio_timer_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ain_timer:32;
    };
}audio_ain_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ain_compare:32;
    };
}audio_ain_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aout_timer:32;
    };
}audio_aout_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aout_compare:32;
    };
}audio_aout_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_0:32;
    };
}audio_sw_dbg_reg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_1:32;
    };
}audio_sw_dbg_reg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_2:32;
    };
}audio_sw_dbg_reg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_3:32;
    };
}audio_sw_dbg_reg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  int_64_512_unstable_1_en:1;
        RBus_UInt32  int_64_512_unstable_en:1;
        RBus_UInt32  res2:14;
        RBus_UInt32  int_64_512fs_unstable_1:1;
        RBus_UInt32  int_64_512fs_unstable:1;
    };
}audio_int_en_states_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  source_sel:2;
        RBus_UInt32  left_right:2;
        RBus_UInt32  mode_sel:1;
        RBus_UInt32  debounce_en:1;
        RBus_UInt32  sclk_inv:1;
        RBus_UInt32  dummy18006100_24_16:9;
        RBus_UInt32  res1:4;
        RBus_UInt32  sampling_rate:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  pcm_width:7;
    };
}audio_i2s_in_primary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  source_sel:2;
        RBus_UInt32  req_after_lock:1;
        RBus_UInt32  debounce_en:1;
        RBus_UInt32  source_sel_spdif_out:1;
        RBus_UInt32  res1:11;
        RBus_UInt32  dummy18006130_15_5:11;
        RBus_UInt32  spdif_in_2fs_sel:1;
        RBus_UInt32  sampling_rate:4;
    };
}audio_spdif_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_locked:1;
        RBus_UInt32  invalid_bit:1;
        RBus_UInt32  clock_accuracy_r:2;
        RBus_UInt32  sampling_freq_r:4;
        RBus_UInt32  channel_number_r:4;
        RBus_UInt32  source_number_r:4;
        RBus_UInt32  category_code_r:8;
        RBus_UInt32  mode_r:2;
        RBus_UInt32  pre_emphasis_r:3;
        RBus_UInt32  copyright_r:1;
        RBus_UInt32  data_type_r:1;
        RBus_UInt32  professional_r:1;
    };
}audio_spdif_in_cs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_rb3_31_30:2;
        RBus_UInt32  cs_lb3_31_30:2;
        RBus_UInt32  pre_emphasis_l:3;
        RBus_UInt32  copyright_l:1;
        RBus_UInt32  data_type_l:1;
        RBus_UInt32  professional_l:1;
        RBus_UInt32  cgms_a_l:2;
        RBus_UInt32  cgms_a_r:2;
        RBus_UInt32  original_sampling_freq_r:4;
        RBus_UInt32  word_length_r:4;
    };
}audio_spdif_in_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  original_sampling_freq_l:4;
        RBus_UInt32  word_length_l:4;
        RBus_UInt32  clock_accuracy_l:2;
        RBus_UInt32  sampling_freq_l:4;
        RBus_UInt32  channel_number_l:4;
        RBus_UInt32  source_number_l:4;
        RBus_UInt32  category_code_l:8;
        RBus_UInt32  mode_l:2;
    };
}audio_spdif_in_cs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_byte_7_5_r:22;
    };
}audio_spdif_in_cs_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_r:32;
    };
}audio_spdif_in_cs_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_r:32;
    };
}audio_spdif_in_cs_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_r:32;
    };
}audio_spdif_in_cs_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_r:32;
    };
}audio_spdif_in_cs_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_byte_7_5_l:22;
    };
}audio_spdif_in_cs_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_l:32;
    };
}audio_spdif_in_cs_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_l:32;
    };
}audio_spdif_in_cs_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_l:32;
    };
}audio_spdif_in_cs_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_l:32;
    };
}audio_spdif_in_cs_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern_search_enable1:1;
        RBus_UInt32  pattern_search_catch1:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pattern_search_length1:15;
    };
}audio_spdif_pattern_search1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  specific_pattern1:32;
    };
}audio_spdif_pattern_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern_search_enable2:1;
        RBus_UInt32  pattern_search_catch2:1;
        RBus_UInt32  res1:15;
        RBus_UInt32  pattern_search_length2:15;
    };
}audio_spdif_pattern_search2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  specific_pattern2:32;
    };
}audio_spdif_pattern_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  papb_search_enable:1;
        RBus_UInt32  papb_search_catch:1;
        RBus_UInt32  res1:9;
        RBus_UInt32  papb_04_flag:1;
        RBus_UInt32  hbr_i2s_ch_no:3;
        RBus_UInt32  det_path_sel:1;
        RBus_UInt32  res2:16;
    };
}audio_spdif_papb_search_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pd_val:16;
        RBus_UInt32  pc_val:16;
    };
}audio_spdif_papb_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pb_val:16;
        RBus_UInt32  pa_val:16;
    };
}audio_spdif_papb_val2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_val_buf:32;
    };
}audio_spdif_papb_val3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pd_val_pat1:16;
        RBus_UInt32  pc_val_pat1:16;
    };
}audio_spdif_pattern1_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pd_val_pat2:16;
        RBus_UInt32  pc_val_pat2:16;
    };
}audio_spdif_pattern2_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_swap_sel:1;
        RBus_UInt32  output_sel:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  mclk_sel:2;
        RBus_UInt32  res2:6;
        RBus_UInt32  wclk_inv:1;
        RBus_UInt32  sclk_inv:1;
        RBus_UInt32  dummy18006150_15_0:16;
    };
}audio_i2s_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcm_source_sel_ch01:4;
        RBus_UInt32  pcm_source_sel_ch23:4;
        RBus_UInt32  res1:8;
        RBus_UInt32  swap_sel_ch01:2;
        RBus_UInt32  res2:14;
    };
}audio_i2s_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hw_limit_en_ch01:1;
        RBus_UInt32  hw_limit_ch01:7;
    };
}audio_i2s_out_sel_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_sel:2;
        RBus_UInt32  wait_en:1;
        RBus_UInt32  validity_ctrl:1;
        RBus_UInt32  spdif_out_null_burst:1;
        RBus_UInt32  pcm_source_sel:4;
        RBus_UInt32  res1:5;
        RBus_UInt32  swap_sel:2;
        RBus_UInt32  dummy18006170_15_0:16;
    };
}audio_spdif_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_lb3_31_30:2;
        RBus_UInt32  clock_accuracy:2;
        RBus_UInt32  sampling_freq:4;
        RBus_UInt32  channel_number:4;
        RBus_UInt32  source_number:4;
        RBus_UInt32  category_code:8;
        RBus_UInt32  mode:2;
        RBus_UInt32  pre_emphasis:3;
        RBus_UInt32  copyright:1;
        RBus_UInt32  data_type:1;
        RBus_UInt32  professional:1;
    };
}audio_spdif_out_cs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cgms_a:2;
        RBus_UInt32  original_sampling_freq:4;
        RBus_UInt32  word_length:4;
    };
}audio_spdif_out_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hw_limit_en:1;
        RBus_UInt32  hw_limit:7;
    };
}audio_spdif_out_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_rb3_31_30:2;
        RBus_UInt32  clock_accuracy_r:2;
        RBus_UInt32  sampling_freq_r:4;
        RBus_UInt32  channel_number_r:4;
        RBus_UInt32  source_number_r:4;
        RBus_UInt32  category_code_r:8;
        RBus_UInt32  mode_r:2;
        RBus_UInt32  pre_emphasis_r:3;
        RBus_UInt32  copyright_r:1;
        RBus_UInt32  data_type_r:1;
        RBus_UInt32  professional_r:1;
    };
}audio_spdif_out_cs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cgms_a_r:2;
        RBus_UInt32  original_sampling_freq_r:4;
        RBus_UInt32  word_length_r:4;
    };
}audio_spdif_out_cs_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_byte_7_5_l:22;
    };
}audio_spdif_out_cs_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_l:32;
    };
}audio_spdif_out_cs_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_l:32;
    };
}audio_spdif_out_cs_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_l:32;
    };
}audio_spdif_out_cs_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_l:32;
    };
}audio_spdif_out_cs_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_byte_7_5_r:22;
    };
}audio_spdif_out_cs_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_r:32;
    };
}audio_spdif_out_cs_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_r:32;
    };
}audio_spdif_out_cs_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_r:32;
    };
}audio_spdif_out_cs_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_r:32;
    };
}audio_spdif_out_cs_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  output_sel:2;
        RBus_UInt32  wait_en:1;
        RBus_UInt32  validity_ctrl:1;
        RBus_UInt32  spdif_out_null_burst:1;
        RBus_UInt32  pcm_source_sel:4;
        RBus_UInt32  res1:5;
        RBus_UInt32  swap_sel:2;
        RBus_UInt32  dummy18006e60_15_0:16;
    };
}audio_spdif_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_lb3_31_30:2;
        RBus_UInt32  clock_accuracy:2;
        RBus_UInt32  sampling_freq:4;
        RBus_UInt32  channel_number:4;
        RBus_UInt32  source_number:4;
        RBus_UInt32  category_code:8;
        RBus_UInt32  mode:2;
        RBus_UInt32  pre_emphasis:3;
        RBus_UInt32  copyright:1;
        RBus_UInt32  data_type:1;
        RBus_UInt32  professional:1;
    };
}audio_spdif_out_1_cs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cgms_a:2;
        RBus_UInt32  original_sampling_freq:4;
        RBus_UInt32  word_length:4;
    };
}audio_spdif_out_1_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  hw_limit_en:1;
        RBus_UInt32  hw_limit:7;
    };
}audio_spdif_out_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_rb3_31_30:2;
        RBus_UInt32  clock_accuracy_r:2;
        RBus_UInt32  sampling_freq_r:4;
        RBus_UInt32  channel_number_r:4;
        RBus_UInt32  source_number_r:4;
        RBus_UInt32  category_code_r:8;
        RBus_UInt32  mode_r:2;
        RBus_UInt32  pre_emphasis_r:3;
        RBus_UInt32  copyright_r:1;
        RBus_UInt32  data_type_r:1;
        RBus_UInt32  professional_r:1;
    };
}audio_spdif_out_1_cs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  cgms_a_r:2;
        RBus_UInt32  original_sampling_freq_r:4;
        RBus_UInt32  word_length_r:4;
    };
}audio_spdif_out_1_cs_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_byte_7_5_l:22;
    };
}audio_spdif_out_1_cs_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_l:32;
    };
}audio_spdif_out_1_cs_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_l:32;
    };
}audio_spdif_out_1_cs_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_l:32;
    };
}audio_spdif_out_1_cs_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_l:32;
    };
}audio_spdif_out_1_cs_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  cs_byte_7_5_r:22;
    };
}audio_spdif_out_1_cs_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_r:32;
    };
}audio_spdif_out_1_cs_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_r:32;
    };
}audio_spdif_out_1_cs_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_r:32;
    };
}audio_spdif_out_1_cs_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_r:32;
    };
}audio_spdif_out_1_cs_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  dummy18006180_19_17:3;
        RBus_UInt32  hw_agc_en:1;
        RBus_UInt32  ob_time:16;
    };
}audio_sif_agc_eval_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  non_opt_cnt_th:3;
        RBus_UInt32  non_opt_cnt_under:8;
        RBus_UInt32  non_opt_cnt_ovf:8;
    };
}audio_sif_agc_optimal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ovf_th:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  opt_th:10;
    };
}audio_sif_agc_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  ovf:1;
        RBus_UInt32  opt:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  abs_peak:10;
    };
}audio_sif_agc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  agc2_debounce_cnt:3;
        RBus_UInt32  agc2_stepsize:2;
        RBus_UInt32  agc2_gain_a:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  agc2_gain_b:6;
        RBus_UInt32  agc2_obtime:16;
    };
}audio_sif_agc2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc2_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  agc2_overflow:1;
        RBus_UInt32  agc2_underflow:1;
        RBus_UInt32  res2:18;
        RBus_UInt32  agc2_sif_mag:10;
    };
}audio_sif_agc2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  aagc_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  audio_gain_manual:9;
        RBus_UInt32  res3:2;
        RBus_UInt32  output_bpf_input_div2:2;
        RBus_UInt32  audio_bp_sel:8;
        RBus_UInt32  res4:2;
        RBus_UInt32  audio_upsample_lp_sel:2;
    };
}audio_sif_agc3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  soft_reset:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  audiodn_fifo_clr:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  audiodn_fifo_full:1;
        RBus_UInt32  audiodn_fifo_empty:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  audiodbg_fifo_clr:1;
        RBus_UInt32  audiodbg_fifo_full:1;
        RBus_UInt32  audiodbg_fifo_empty:1;
        RBus_UInt32  debug_mode2:2;
        RBus_UInt32  res5:12;
    };
}audio_sif_agc3_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  pdetect_enable:1;
        RBus_UInt32  detect_source_sel:4;
    };
}audio_peak_contorl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_th_l:16;
        RBus_UInt32  ovf_th_l:16;
    };
}audio_peak_contorl_l_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180061b4_31_19:13;
        RBus_UInt32  nonopt_cnt_tr_l:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  vpp_eval_cnt_l:14;
    };
}audio_peak_control_l_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  optimize_l_irq_en:1;
        RBus_UInt32  overflow_l_irq_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  optimize_l:1;
        RBus_UInt32  overflow_l:1;
        RBus_UInt32  pk_adj_l:6;
        RBus_UInt32  magnitude_l:16;
    };
}audio_peak_status_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  toggle_cnt:8;
        RBus_UInt32  pcm_l_monitor:24;
    };
}audio_peak_status_l_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_th_r:16;
        RBus_UInt32  ovf_th_r:16;
    };
}audio_peak_contorl_r_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180061c4_31_19:13;
        RBus_UInt32  nonopt_cnt_tr_r:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  vpp_eval_cnt_r:14;
    };
}audio_peak_contorl_r_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  optimize_r_irq_en:1;
        RBus_UInt32  overflow_r_irq_en:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  optimize_r:1;
        RBus_UInt32  overflow_r:1;
        RBus_UInt32  pk_adj_r:6;
        RBus_UInt32  magnitude_r:16;
    };
}audio_peak_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  pcm_r_monitor:24;
    };
}audio_peak_status_r_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  msd_en:1;
        RBus_UInt32  update_en:1;
        RBus_UInt32  carrier_shift_scan_en:1;
        RBus_UInt32  carrier_phase_delta:3;
        RBus_UInt32  msd_reset_n:1;
        RBus_UInt32  msd_debounce_cnt:3;
        RBus_UInt32  reg_scan_cnt:8;
        RBus_UInt32  res2:1;
        RBus_UInt32  mn_priority:2;
        RBus_UInt32  dkl_priority:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  calc_time_sel:1;
        RBus_UInt32  sound_select:2;
        RBus_UInt32  res4:1;
        RBus_UInt32  fw_scan_freq:3;
    };
}audio_msd_crtl_word_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  deviation_unnormal:2;
        RBus_UInt32  case_subtomain:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  flag_unnormal:1;
        RBus_UInt32  flag_subtomain:1;
        RBus_UInt32  h_dv_th_sel:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  hw_detected_std:5;
        RBus_UInt32  res4:3;
        RBus_UInt32  reg_std:5;
    };
}audio_msd_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  bw_cnt_max:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  bw_cnt_min:5;
        RBus_UInt32  res3:4;
        RBus_UInt32  shift_value:4;
        RBus_UInt32  res4:1;
        RBus_UInt32  main_cari_idx:3;
        RBus_UInt32  deviation:4;
    };
}audio_msd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_thresh:16;
        RBus_UInt32  main_thresh_low:16;
    };
}audio_main_tone_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_thresh_hd:16;
        RBus_UInt32  main_thresh_hd_low:16;
    };
}audio_main_tone_threshold_hd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_dev_thresh_hd:16;
        RBus_UInt32  bw_dev_thresh:16;
    };
}audio_bw_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_dev_thresh_low:16;
        RBus_UInt32  main_sub_ratio:16;
    };
}audio_main_sub_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_4_5:16;
    };
}audio_msd_mag_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_4_28:16;
    };
}audio_msd_mag_4_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_4_72:16;
    };
}audio_msd_mag_4_72_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_5_5:16;
    };
}audio_msd_mag_5_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_5_25:16;
    };
}audio_msd_mag_5_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_5_74:16;
    };
}audio_msd_mag_5_74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_5_85:16;
    };
}audio_msd_carrier_5_85_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_5_95:16;
    };
}audio_msd_carrier_5_95_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_6:16;
    };
}audio_msd_mag_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_6_25:16;
    };
}audio_msd_mag_6_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_6_5:16;
    };
}audio_msd_carrier_6_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_6_552:16;
    };
}audio_msd_mag_6_552_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  reg_mag_6_74:16;
    };
}audio_msd_carrier_6_74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  flag_fw_4:1;
        RBus_UInt32  flag_fw_3:1;
        RBus_UInt32  flag_fw_2:1;
        RBus_UInt32  flag_fw_1:1;
        RBus_UInt32  flag_fw:1;
        RBus_UInt32  flag_4_5:1;
        RBus_UInt32  flag_5_5:1;
        RBus_UInt32  flag_6:1;
        RBus_UInt32  flag_6_5:1;
        RBus_UInt32  flag_4_72:1;
        RBus_UInt32  flag_5_74:1;
        RBus_UInt32  flag_5_85:1;
        RBus_UInt32  flag_6_25:1;
        RBus_UInt32  flag_6_552:1;
        RBus_UInt32  flag_6_74:1;
    };
}audio_msd_flags_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fw_phase_delta:14;
        RBus_UInt32  reg_mag_fw:16;
    };
}audio_msd_programmable_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh:16;
        RBus_UInt32  fw_thresh_low:16;
    };
}audio_threshold_msd_carrier_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fw_phase_delta_1:14;
        RBus_UInt32  reg_mag_fw_1:16;
    };
}audio_msd_programmable_freq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_1:16;
        RBus_UInt32  fw_thresh_1_low:16;
    };
}audio_threshold_msd_carrier_fw_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fw_phase_delta_2:14;
        RBus_UInt32  reg_mag_fw_2:16;
    };
}audio_msd_programmable_freq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_2:16;
        RBus_UInt32  fw_thresh_2_low:16;
    };
}audio_threshold_msd_carrier_fw_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fw_phase_delta_3:14;
        RBus_UInt32  reg_mag_fw_3:16;
    };
}audio_msd_programmable_freq_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_3:16;
        RBus_UInt32  fw_thresh_3_low:16;
    };
}audio_threshold_msd_carrier_fw_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  fw_phase_delta_4:14;
        RBus_UInt32  reg_mag_fw_4:16;
    };
}audio_msd_programmable_freq_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_4:16;
        RBus_UInt32  fw_thresh_4_low:16;
    };
}audio_threshold_msd_carrier_fw_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  reg_cari_sft_detect_en:1;
        RBus_UInt32  reg_bw_detect_en:1;
        RBus_UInt32  mono_std_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  second_reg_std:5;
    };
}audio_msd_second_reg_std_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sec_thresh:16;
        RBus_UInt32  sec_thresh_low:16;
    };
}audio_second_main_tone_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rm_0:4;
    };
}audio_msd_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_45_fix:16;
        RBus_UInt32  reg_mag_55_fix:16;
    };
}audio_msd_main_mag_ori1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_60_fix:16;
        RBus_UInt32  reg_mag_65_fix:16;
    };
}audio_msd_main_mag_ori2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  msd_gain_en:1;
        RBus_UInt32  msd_gain_result:4;
    };
}audio_msd_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_update_count:16;
        RBus_UInt32  msd_update_count:16;
    };
}audio_msd_update_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_update_count:16;
        RBus_UInt32  res1:13;
        RBus_UInt32  hw_mode_en:1;
        RBus_UInt32  mode_result:2;
    };
}audio_mode_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  bpf_sel:1;
        RBus_UInt32  high_threshold:2;
        RBus_UInt32  low_threshold:2;
        RBus_UInt32  auto_pre_gain_ctrl_en:1;
        RBus_UInt32  auto_gain_ctrl_en:1;
        RBus_UInt32  max_threshold:24;
    };
}audio_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_result_pre:4;
        RBus_UInt32  gain_result:4;
        RBus_UInt32  max_other:24;
    };
}audio_md_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  lpf_coef_sel:2;
        RBus_UInt32  lpf_coef_sel_lock:2;
        RBus_UInt32  mode_result:2;
        RBus_UInt32  max_dual:24;
    };
}audio_md_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800631c_31_27:5;
        RBus_UInt32  debounce_time:3;
        RBus_UInt32  max_stereo:24;
    };
}audio_md_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_win:16;
        RBus_UInt32  pre_gain_win:16;
    };
}audio_md_gain_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  md_limit_thre:24;
    };
}audio_md_limit_thre_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sif_data_source:1;
        RBus_UInt32  nicam_play_ana_sel:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  tone_det_en:1;
        RBus_UInt32  force_a2_dk_sel:2;
        RBus_UInt32  freq_manual_en:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  phase_3rd_delta:14;
    };
}audio_carrier_freq_deviation_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  main_phase_delta:14;
        RBus_UInt32  res2:2;
        RBus_UInt32  sub_phase_delta:14;
    };
}audio_carrier_phase_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fm_magnitude:16;
        RBus_UInt32  dummy18006358_15_0:16;
    };
}audio_a2_eiaj_dc_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  dvol_apply_tvd:1;
        RBus_UInt32  dvol_enable_tvd:1;
        RBus_UInt32  mode_sel_tvd:1;
        RBus_UInt32  force_mute_tvd:1;
        RBus_UInt32  switch_status_tvd:2;
        RBus_UInt32  zcto_status_tvd:1;
        RBus_UInt32  zcth_tvd:5;
        RBus_UInt32  dvcm_tvd:2;
        RBus_UInt32  zcto_mute_tvd:3;
        RBus_UInt32  ramp_step_mute_tvd:2;
        RBus_UInt32  delay_ctrl_tvd:10;
    };
}audio_tvdemod_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  vol_a_tvd:5;
        RBus_UInt32  delay_ctrl_unmute_tvd:10;
        RBus_UInt32  vol_b_tvd:6;
        RBus_UInt32  delay_ctrl_mute_tvd:10;
    };
}audio_tvdemod_digital_volume_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_bp1_a1:16;
        RBus_UInt32  eq_tvd_bp1_a2:16;
    };
}audio_eq_tvd_bp1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_tvd_bp1_h0:16;
    };
}audio_eq_tvd_bp1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_bp2_a1:16;
        RBus_UInt32  eq_tvd_bp2_a2:16;
    };
}audio_eq_tvd_bp2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_tvd_bp2_h0:16;
    };
}audio_eq_tvd_bp2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  eq_tvd_ovf:1;
        RBus_UInt32  eq_tvd_deq_enable:1;
        RBus_UInt32  eq_tvd_lp_enable:1;
        RBus_UInt32  eq_tvd_band2_enable:1;
        RBus_UInt32  eq_tvd_band1_enable:1;
    };
}audio_eq_tvd_bp_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  eq_tvd_lp_of:1;
        RBus_UInt32  eq_tvd_band2_of:1;
        RBus_UInt32  eq_tvd_band1_of:1;
    };
}audio_eq_tvd_bp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_lp_a1:16;
        RBus_UInt32  eq_tvd_lp_h0:16;
    };
}audio_eq_tvd_lp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  dummy18006360_7_4:4;
        RBus_UInt32  am_bpf_bw:1;
        RBus_UInt32  am_path_sel:1;
        RBus_UInt32  hw_am_prescale:2;
    };
}audio_am_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rm_0:4;
    };
}audio_bist_am_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage1_b0:16;
        RBus_UInt32  sap_bpf_stage1_b1:16;
    };
}audio_sap_bpf_stage1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sap_bpf_stage1_b2:16;
    };
}audio_sap_bpf_stage1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage1_a1:16;
        RBus_UInt32  sap_bpf_stage1_a2:16;
    };
}audio_sap_bpf_stage1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage2_b0:16;
        RBus_UInt32  sap_bpf_stage2_b1:16;
    };
}audio_sap_bpf_stage2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sap_bpf_stage2_b2:16;
    };
}audio_sap_bpf_stage2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage2_a1:16;
        RBus_UInt32  sap_bpf_stage2_a2:16;
    };
}audio_sap_bpf_stage2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage3_b0:16;
        RBus_UInt32  sap_bpf_stage3_b1:16;
    };
}audio_sap_bpf_stage3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  sap_bpf_stage3_b2:16;
    };
}audio_sap_bpf_stage3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage3_a1:16;
        RBus_UInt32  sap_bpf_stage3_a2:16;
    };
}audio_sap_bpf_stage3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lock_reference:1;
        RBus_UInt32  fm_radio_en:1;
        RBus_UInt32  fm_radio_deem_sel:1;
        RBus_UInt32  fm_radio_deem_bypass:1;
        RBus_UInt32  bypass_com_hpf:1;
        RBus_UInt32  bypass_com_bpf:1;
        RBus_UInt32  pilot_hithresh:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pilot_lothresh:10;
    };
}audio_btsc_pilot_thres_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:13;
        RBus_UInt32  pilot_lock_reset:1;
        RBus_UInt32  out_hpf_en:1;
        RBus_UInt32  w1pilotpresent:1;
        RBus_UInt32  w1pilotlocked:1;
        RBus_UInt32  pilot_level_pass:1;
        RBus_UInt32  pilot_hi_pass:1;
        RBus_UInt32  pilot_lo_refuse:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  w10pilotmagnitude:10;
    };
}audio_btsc_pilot_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sap_hithresh:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  sap_lothresh:10;
    };
}audio_btsc_sap_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  sap_noise_hi_thresh:10;
        RBus_UInt32  res2:6;
        RBus_UInt32  sap_noise_lo_thresh:10;
    };
}audio_btsc_sap_noise_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  w10sapnoise:10;
    };
}audio_btsc_sap_noise_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  w1sapqualitygood:1;
        RBus_UInt32  sap_hi_pass:1;
        RBus_UInt32  sap_lo_refuse:1;
        RBus_UInt32  sap_noise_flag:1;
        RBus_UInt32  sap_compen_en:1;
        RBus_UInt32  w10sapmagnitude:10;
    };
}audio_btsc_sap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:27;
        RBus_UInt32  sap_debounce_en:1;
        RBus_UInt32  sap_debounce:4;
    };
}audio_btsc_sap_debounce_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  fm_mag_overflow:1;
        RBus_UInt32  fm_mag_optimize:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  w10fmmagnitude:10;
    };
}audio_btsc_sif_fm_magnitude_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  testoutputselect:4;
    };
}audio_btsc_test_mux_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  dummy_6424:16;
    };
}audio_btsc_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pilot_phase_delta:32;
    };
}audio_btsc_pilot_phase_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  unlock_p_gain:4;
        RBus_UInt32  unlock_i_gain:4;
        RBus_UInt32  locked_p_gain:4;
        RBus_UInt32  locked_i_gain:4;
    };
}audio_phase_error_pi_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_hpf_en:1;
        RBus_UInt32  mono_lpf_sel:1;
        RBus_UInt32  stereo_lpf_sel:1;
        RBus_UInt32  res1:5;
        RBus_UInt32  phase_err_threshold:24;
    };
}audio_phase_err_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  phase_err_high_threshold:24;
    };
}audio_phase_err_threshold2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  freq_correction:22;
    };
}audio_freq_correction_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  average_movement:24;
    };
}audio_phase_error_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  a2_bw_sel:2;
        RBus_UInt32  de_emphasis_time:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  hdv_compen_en:1;
        RBus_UInt32  down_6db:1;
        RBus_UInt32  res2:10;
        RBus_UInt32  a2_sub_bw_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  fm1_deviation_gain:3;
        RBus_UInt32  res4:1;
        RBus_UInt32  fm2_deviation_gain:3;
        RBus_UInt32  res5:4;
    };
}audio_a2_eiaj_demod_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  magnitude_sub:10;
        RBus_UInt32  noise_sub:10;
    };
}audio_a2_eiaj_mag_noise_sub_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  magnitude:10;
        RBus_UInt32  noise:10;
    };
}audio_a2_eiaj_mag_noise_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_7:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}audio_mbist_a2_eiaj_demod_rm_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rm_8:4;
    };
}audio_mbist_a2_eiaj_demod_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
    };
}audio_mbist_a2_eiaj_demod_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  psf_sel:1;
        RBus_UInt32  tr_lpf_kp:3;
        RBus_UInt32  psf_bg_sel:1;
        RBus_UInt32  cr_lpf_kp:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  cr_lpf_ki:2;
        RBus_UInt32  tr_timing_step:20;
    };
}audio_nicam_demod_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  debounce_cnt:3;
        RBus_UInt32  res1:2;
        RBus_UInt32  window_size:10;
        RBus_UInt32  res2:10;
        RBus_UInt32  gain_adjust:6;
    };
}audio_nicam_dagc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  high:16;
        RBus_UInt32  low:16;
    };
}audio_nicam_dagc_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  magnitude:16;
    };
}audio_nicam_dagc_mag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  src_out_en:1;
        RBus_UInt32  data_channel_sel:1;
        RBus_UInt32  pcm_l_out_sel:1;
        RBus_UInt32  pcm_r_out_sel:1;
        RBus_UInt32  cib_1:1;
        RBus_UInt32  cib_0:1;
        RBus_UInt32  cib_mask:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  status_debounce_cnt:4;
        RBus_UInt32  bypass_interpol:1;
        RBus_UInt32  sat_en:1;
        RBus_UInt32  de_em_by_pass:1;
        RBus_UInt32  dummy_0:1;
        RBus_UInt32  level_sel:2;
        RBus_UInt32  dummy18006510_13_2:12;
        RBus_UInt32  nicam_to_mute_clk_sel:1;
        RBus_UInt32  nicam_to_mono_clk_sel:1;
    };
}audio_nicam_decode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  c0:1;
        RBus_UInt32  c1c2c3:3;
        RBus_UInt32  c4:1;
        RBus_UInt32  additional_data:11;
        RBus_UInt32  res1:2;
        RBus_UInt32  bit_cnt_sync:1;
        RBus_UInt32  true_detect:1;
        RBus_UInt32  bit_error_rate:12;
    };
}audio_nicam_decode_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  c4_hi_ber:2;
        RBus_UInt32  analog_flag:1;
        RBus_UInt32  hi_ber_debounce:3;
        RBus_UInt32  high_threshold:12;
        RBus_UInt32  low_threshold:12;
    };
}audio_nicam_auto_switch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  enable:1;
        RBus_UInt32  dur_rand_en:1;
        RBus_UInt32  duration:2;
        RBus_UInt32  res1:5;
        RBus_UInt32  ted_error_threshold:3;
        RBus_UInt32  res2:2;
        RBus_UInt32  ted_error:18;
    };
}audio_nicam_demod_auto_recovery_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  bit_error_rate_l:12;
        RBus_UInt32  bit_error_rate_r:12;
    };
}audio_nicam_bit_error_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  window_en:1;
        RBus_UInt32  l_start:6;
        RBus_UInt32  l_end:6;
        RBus_UInt32  r_start:6;
        RBus_UInt32  r_end:6;
    };
}audio_nicam_ber_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}audio_nicam_src_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  fifo_ch1_source:2;
        RBus_UInt32  fifo_ch0_source:2;
        RBus_UInt32  res2:12;
        RBus_UInt32  output_hold_zero:1;
        RBus_UInt32  backend_play_en:1;
        RBus_UInt32  downsample_en:1;
        RBus_UInt32  down_rate:1;
    };
}audio_down_sample_control_for_playback_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  fifo_ch01_sel:4;
    };
}audio_down_sample_fifo_source_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006558_31_14:18;
        RBus_UInt32  res1:14;
    };
}audio_down_sample_mbist_recoding_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}audio_down_sample_fifo_pre_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}audio_down_sample_mbist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
    };
}audio_down_sample_mbist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  fifo_ch0_source:2;
        RBus_UInt32  fifo_ch1_source:2;
        RBus_UInt32  fifo_ch01_sel:4;
        RBus_UInt32  res2:8;
        RBus_UInt32  output_hold_zero:1;
        RBus_UInt32  backend_play_en:1;
        RBus_UInt32  downsample_en:1;
        RBus_UInt32  down_rate:1;
    };
}audio_down_sample_control_for_ts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180065a4_31_16:16;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_0:4;
    };
}audio_ts_ds_fifo_mbist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_0:1;
    };
}audio_ts_ds_fifo_mbist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_wr_src_sel:2;
        RBus_UInt32  dma_output_src_sel:2;
        RBus_UInt32  dma_w_format:1;
        RBus_UInt32  dma_r_format:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_src_pre_fifo_en:1;
        RBus_UInt32  output_hold_en:1;
        RBus_UInt32  pcm_random:1;
        RBus_UInt32  hbr_wr_channel_no:2;
        RBus_UInt32  wr_channel_no:3;
        RBus_UInt32  aidmatype:1;
        RBus_UInt32  rd_channel_no:3;
        RBus_UInt32  aodmatype:1;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  int_rd_en:1;
        RBus_UInt32  int_wr_en:1;
        RBus_UInt32  dma_int_en:1;
        RBus_UInt32  dma_soft_rd_rst:1;
        RBus_UInt32  dma_soft_wr_rst:1;
        RBus_UInt32  dma_read_enable:1;
        RBus_UInt32  dma_write_enable:1;
        RBus_UInt32  overflow_dma_status:1;
        RBus_UInt32  unflow_dma_status:1;
        RBus_UInt32  wr_intr_dma_status:1;
        RBus_UInt32  rd_intr_dma_status:1;
    };
}audio_adma_csr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  write_len:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  wr_intr_point:15;
    };
}audio_adma_wconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_start_addr0:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_wsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_start_addr1:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_wsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  read_len:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  read_intr_point:15;
    };
}audio_adma_rconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  load_wr:1;
        RBus_UInt32  avail_length:15;
        RBus_UInt32  load_rd:1;
        RBus_UInt32  read_length:15;
    };
}audio_adma_wrconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_start_addr0:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_rsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_start_addr1:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_rsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_start_addr2:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_rsadr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_start_addr3:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_rsadr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_start_addr4:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_rsadr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_start_addr5:26;
        RBus_UInt32  res1:6;
    };
}audio_adma_rsadr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  wr_buffer_length:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  rd_buffer_length:15;
    };
}audio_adma_chconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ls_on:1;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rm_0:4;
    };
}audio_audio_dma_bist_control_indicate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  arc_dma_output_src_sel:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  arc_dma_r_format:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  arc_output_hold_en:1;
        RBus_UInt32  res4:7;
        RBus_UInt32  arc_rd_channel_no:3;
        RBus_UInt32  arc_aodmatype:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  arc_int_rd_en:1;
        RBus_UInt32  res6:1;
        RBus_UInt32  arc_dma_int_en:1;
        RBus_UInt32  arc_dma_soft_rd_rst:1;
        RBus_UInt32  res7:1;
        RBus_UInt32  arc_dma_read_enable:1;
        RBus_UInt32  res8:2;
        RBus_UInt32  arc_unflow_dma_status:1;
        RBus_UInt32  res9:1;
        RBus_UInt32  arc_rd_intr_dma_status:1;
    };
}audio_arc_adma_csr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  arc_read_len:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  arc_read_intr_point:15;
    };
}audio_arc_adma_rconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  arc_load_rd:1;
        RBus_UInt32  arc_read_length:15;
    };
}audio_arc_adma_wrconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arc_rd_start_addr0:26;
        RBus_UInt32  res1:6;
    };
}audio_arc_adma_rsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arc_rd_start_addr1:26;
        RBus_UInt32  res1:6;
    };
}audio_arc_adma_rsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:17;
        RBus_UInt32  arc_rd_buffer_length:15;
    };
}audio_arc_adma_chconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  arc_ls_on:1;
        RBus_UInt32  rme_0_arc:1;
        RBus_UInt32  rm_0_arc:4;
    };
}audio_arc_dma_bist_control_indicate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_dma_wr_src_sel:2;
        RBus_UInt32  ts_dma_output_src_sel:2;
        RBus_UInt32  ts_dma_w_format:1;
        RBus_UInt32  ts_dma_r_format:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_dma_src_pre_fifo_en:1;
        RBus_UInt32  ts_output_hold_en:1;
        RBus_UInt32  ts_pcm_random:1;
        RBus_UInt32  ts_hbr_wr_channel_no:2;
        RBus_UInt32  ts_wr_channel_no:3;
        RBus_UInt32  ts_aidmatype:1;
        RBus_UInt32  ts_rd_channel_no:3;
        RBus_UInt32  ts_aodmatype:1;
        RBus_UInt32  ts_dma_mode:1;
        RBus_UInt32  ts_int_rd_en:1;
        RBus_UInt32  ts_int_wr_en:1;
        RBus_UInt32  ts_dma_int_en:1;
        RBus_UInt32  ts_dma_soft_rd_rst:1;
        RBus_UInt32  ts_dma_soft_wr_rst:1;
        RBus_UInt32  ts_dma_read_enable:1;
        RBus_UInt32  ts_dma_write_enable:1;
        RBus_UInt32  ts_overflow_dma_status:1;
        RBus_UInt32  ts_unflow_dma_status:1;
        RBus_UInt32  ts_wr_intr_dma_status:1;
        RBus_UInt32  ts_rd_intr_dma_status:1;
    };
}audio_tsadma_csr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_write_len:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  ts_wr_intr_point:15;
    };
}audio_ts_adma_wconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_wr_start_addr0:26;
        RBus_UInt32  res1:6;
    };
}audio_ts_adma_wsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_wr_start_addr1:26;
        RBus_UInt32  res1:6;
    };
}audio_ts_adma_wsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_read_len:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  ts_read_intr_point:15;
    };
}audio_ts_adma_rconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_load_wr:1;
        RBus_UInt32  ts_avail_length:15;
        RBus_UInt32  ts_load_rd:1;
        RBus_UInt32  ts_read_length:15;
    };
}audio_ts_adma_wrconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_rd_start_addr0:26;
        RBus_UInt32  res1:6;
    };
}audio_ts_adma_rsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_rd_start_addr1:26;
        RBus_UInt32  res1:6;
    };
}audio_ts_adma_rsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_rd_start_addr2:26;
        RBus_UInt32  res1:6;
    };
}audio_ts_adma_rsadr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_wr_buffer_length:15;
        RBus_UInt32  res2:1;
        RBus_UInt32  ts_rd_buffer_length:15;
    };
}audio_ts_adma_chconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  ts_ls_on:1;
        RBus_UInt32  rme_0_ts:1;
        RBus_UInt32  rm_0_ts:4;
    };
}audio_ts_dma_bist_control_indicate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  test_dma_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  test_dma_rw_mode:1;
        RBus_UInt32  test_dma_in_sel:3;
        RBus_UInt32  test_dma_ring:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  test_dma_over_read:1;
        RBus_UInt32  test_dma_over_write:1;
    };
}audio_test_dma_control_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_dma_start_addr:26;
        RBus_UInt32  res1:6;
    };
}audio_test_dma_start_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_dma_stop_addr:26;
        RBus_UInt32  res1:6;
    };
}audio_test_dma_stop_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy180066ec_31_2:30;
        RBus_UInt32  eco_ifd_inv:1;
        RBus_UInt32  dma_sel:1;
    };
}audio_test_mode_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_dma_cur_addr:26;
        RBus_UInt32  res1:6;
    };
}audio_test_cur_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  drc_enable:1;
        RBus_UInt32  drc_lpf_enable:1;
        RBus_UInt32  distortion_enable:1;
        RBus_UInt32  avc2_enable:1;
        RBus_UInt32  basic_premium_sel:1;
        RBus_UInt32  dvol_enable:1;
        RBus_UInt32  loud_enable:1;
        RBus_UInt32  deq_enable:1;
        RBus_UInt32  spatial_ctrlenable:1;
        RBus_UInt32  auto_volenable:1;
    };
}audio_hw_process_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_vol_detect:2;
        RBus_UInt32  avc_noise_gain:2;
        RBus_UInt32  avc_noise_thre:8;
        RBus_UInt32  avc_level_max:8;
        RBus_UInt32  avc_level_min:8;
        RBus_UInt32  avc_down_db:2;
        RBus_UInt32  avc_up_db:2;
    };
}audio_auto_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  avc_cnt_thre:10;
        RBus_UInt32  avc_zc_win:10;
        RBus_UInt32  avc_mon_win:10;
    };
}audio_avc_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_vol_amplif_enable:1;
        RBus_UInt32  avc1_coef:3;
        RBus_UInt32  avc_small_level_max:8;
        RBus_UInt32  avc_small_level_min:8;
        RBus_UInt32  avc_small_down_db:2;
        RBus_UInt32  avc_small_up_db:2;
        RBus_UInt32  avc_small_cnt_thre:8;
    };
}audio_avc_volume_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_lower_step_mag_thre:8;
        RBus_UInt32  avc_amplif_step_mag_thre:8;
        RBus_UInt32  avc_small_level:16;
    };
}audio_avc_volume_control_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_lower_step_cnt_low_thre:8;
        RBus_UInt32  avc_lower_step_cnt_hi_thre:8;
        RBus_UInt32  avc_amplif_step_cnt_low_thre:8;
        RBus_UInt32  avc_amplif_step_cnt_hi_thre:8;
    };
}audio_avc_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  avc_down_db_fine:2;
        RBus_UInt32  avc_up_db_fine:2;
        RBus_UInt32  avc_small_down_db_fine:2;
        RBus_UInt32  avc_small_up_db_fine:2;
    };
}audio_avc_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  spatial_zc_win:12;
        RBus_UInt32  spatial_zc_apply:1;
        RBus_UInt32  apf_en:1;
        RBus_UInt32  psb_en:1;
        RBus_UInt32  seb_en:1;
        RBus_UInt32  spatial_in_l_sel:1;
        RBus_UInt32  spatial_in_r_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  f_coef:9;
    };
}audio_spatial_effect_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  depth1:9;
        RBus_UInt32  res2:7;
        RBus_UInt32  depth2:9;
    };
}audio_spatial_effect_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:15;
        RBus_UInt32  eq_hp_slope:1;
        RBus_UInt32  eq_hp_a1:16;
    };
}audio_eq_hp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_lp_a1:16;
        RBus_UInt32  eq_lp_h0:16;
    };
}audio_eq_lp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp1_a1:16;
        RBus_UInt32  eq_bp1_a2:16;
    };
}audio_eq_bp1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp1_h0:16;
    };
}audio_eq_bp1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp2_a1:16;
        RBus_UInt32  eq_bp2_a2:16;
    };
}audio_eq_bp2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp2_h0:16;
    };
}audio_eq_bp2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp3_a1:16;
        RBus_UInt32  eq_bp3_a2:16;
    };
}audio_eq_bp3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp3_h0:16;
    };
}audio_eq_bp3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp4_a1:16;
        RBus_UInt32  eq_bp4_a2:16;
    };
}audio_eq_bp4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp4_h0:16;
    };
}audio_eq_bp4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp5_a1:16;
        RBus_UInt32  eq_bp5_a2:16;
    };
}audio_eq_bp5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp5_h0:16;
    };
}audio_eq_bp5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp6_a1:16;
        RBus_UInt32  eq_bp6_a2:16;
    };
}audio_eq_bp6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp6_h0:16;
    };
}audio_eq_bp6_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp7_a1:16;
        RBus_UInt32  eq_bp7_a2:16;
    };
}audio_eq_bp7_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  eq_bp7_h0:16;
    };
}audio_eq_bp7_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  eq_band7_enable:1;
        RBus_UInt32  eq_band6_enable:1;
        RBus_UInt32  eq_band5_enable:1;
        RBus_UInt32  eq_band4_enable:1;
        RBus_UInt32  eq_band3_enable:1;
        RBus_UInt32  eq_band2_enable:1;
        RBus_UInt32  eq_band1_enable:1;
        RBus_UInt32  eq_lp_enable:1;
        RBus_UInt32  eq_hp_enable:1;
    };
}audio_eq_control_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:23;
        RBus_UInt32  eq_band7_of:1;
        RBus_UInt32  eq_band6_of:1;
        RBus_UInt32  eq_band5_of:1;
        RBus_UInt32  eq_band4_of:1;
        RBus_UInt32  eq_band3_of:1;
        RBus_UInt32  eq_band2_of:1;
        RBus_UInt32  eq_band1_of:1;
        RBus_UInt32  eq_lp_of:1;
        RBus_UInt32  eq_hp_of:1;
    };
}audio_eq_status_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_lp0_a1:16;
        RBus_UInt32  lr_loud_lp0_h0:16;
    };
}audio_lr_loud_lp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_bp1_a1:16;
        RBus_UInt32  lr_loud_bp1_a2:16;
    };
}audio_lr_loud_bp1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lr_loud_bp1_h0:16;
    };
}audio_lr_loud_bp1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_bp2_a1:16;
        RBus_UInt32  lr_loud_bp2_a2:16;
    };
}audio_lr_loud_bp2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  lr_loud_bp2_h0:16;
    };
}audio_lr_loud_bp2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ld_lpf_en_lr:1;
        RBus_UInt32  ld_bpf1_en_lr:1;
        RBus_UInt32  ld_bpf2_en_lr:1;
    };
}audio_loudness_control_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  ld_lpf_of_lr:1;
        RBus_UInt32  ld_bpf1_of_lr:1;
        RBus_UInt32  ld_bpf2_of_lr:1;
    };
}audio_loudness_status_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  reg_in_thre:5;
        RBus_UInt32  reg_zero_in_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  zcth:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  dvcm:2;
    };
}audio_digital_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvol_apply:1;
        RBus_UInt32  zcto:3;
        RBus_UInt32  ramp_step:2;
        RBus_UInt32  delay_ctrl:10;
        RBus_UInt32  mute_apply:1;
        RBus_UInt32  zcto_mute:3;
        RBus_UInt32  ramp_step_mute:2;
        RBus_UInt32  delay_ctrl_mute:10;
    };
}audio_digital_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mute_l:1;
        RBus_UInt32  rep_l_status:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hpf_l_enable:1;
        RBus_UInt32  vol_l_ready:1;
        RBus_UInt32  vol_l_a:5;
        RBus_UInt32  vol_l_b:6;
        RBus_UInt32  mute_r:1;
        RBus_UInt32  rep_r_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hpf_r_enable:1;
        RBus_UInt32  vol_r_ready:1;
        RBus_UInt32  vol_r_a:5;
        RBus_UInt32  vol_r_b:6;
    };
}audio_lr_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mute_ls:1;
        RBus_UInt32  rep_ls_status:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hpf_ls_enable:1;
        RBus_UInt32  vol_ls_ready:1;
        RBus_UInt32  vol_ls_a:5;
        RBus_UInt32  vol_ls_b:6;
        RBus_UInt32  mute_rs:1;
        RBus_UInt32  rep_rs_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hpf_rs_enable:1;
        RBus_UInt32  vol_rs_ready:1;
        RBus_UInt32  vol_rs_a:5;
        RBus_UInt32  vol_rs_b:6;
    };
}audio_lsrs_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mute_c:1;
        RBus_UInt32  rep_c_status:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hpf_c_enable:1;
        RBus_UInt32  vol_c_ready:1;
        RBus_UInt32  vol_c_a:5;
        RBus_UInt32  vol_c_b:6;
        RBus_UInt32  mute_sw:1;
        RBus_UInt32  rep_sw_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hpf_sw_enable:1;
        RBus_UInt32  vol_sw_ready:1;
        RBus_UInt32  vol_sw_a:5;
        RBus_UInt32  vol_sw_b:6;
    };
}audio_csw_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  zcto_status:1;
        RBus_UInt32  double_buffer_ack:1;
    };
}audio_double_buffer_ack_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  avc2_vol_amplif_enable:1;
        RBus_UInt32  avc2_lpf_coef:3;
        RBus_UInt32  avc2_vol_detect:2;
        RBus_UInt32  fast_recov_ctrl:1;
        RBus_UInt32  slow_up_db:2;
        RBus_UInt32  fast_up_db:2;
        RBus_UInt32  down_db:2;
        RBus_UInt32  avc2_noise_gain:2;
        RBus_UInt32  avc2_noise_thre:16;
    };
}audio_avc2_control_1_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  avc2_cnt_thre:10;
        RBus_UInt32  avc2_zc_win:10;
        RBus_UInt32  avc2_mon_win:10;
    };
}audio_avc2_control_2_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_noise_thre_hi:16;
        RBus_UInt32  recov_win_max:8;
        RBus_UInt32  recov_win_min:8;
    };
}audio_avc2_control_3_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_level_max:16;
        RBus_UInt32  avc2_level_min:16;
    };
}audio_avc2_control_4_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  slow_up_db_fine:2;
        RBus_UInt32  fast_up_db_fine:2;
        RBus_UInt32  down_db_fine:2;
        RBus_UInt32  avc2_small_up_db_fine:2;
        RBus_UInt32  avc2_small_down_db_fine:2;
        RBus_UInt32  avc2_small_up_db:2;
        RBus_UInt32  avc2_small_down_db:2;
        RBus_UInt32  avc2_small_cnt_thre:8;
    };
}audio_avc2_control_5_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_small_level_max:16;
        RBus_UInt32  avc2_small_level_min:16;
    };
}audio_avc2_control_6_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  avc2_small_level:31;
    };
}audio_avc2_control_7_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_lower_step_mag_thre:16;
        RBus_UInt32  avc2_lower_step_cnt_low_thre:8;
        RBus_UInt32  avc2_lower_step_cnt_hi_thre:8;
    };
}audio_avc2_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_amplif_step_mag_thre:16;
        RBus_UInt32  avc2_amplif_step_cnt_low_thre:8;
        RBus_UInt32  avc2_amplif_step_cnt_hi_thre:8;
    };
}audio_avc2_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  hw_mixing_sel:2;
        RBus_UInt32  res2:4;
    };
}audio_hw_out_trans_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  eq_ovf_en:1;
        RBus_UInt32  loudness_ovf_en:1;
        RBus_UInt32  dvol_int_en:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  dvol_done:1;
        RBus_UInt32  eq_ovf:1;
        RBus_UInt32  loudness_ovf:1;
    };
}audio_system_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  avc_lp_out:24;
    };
}audio_avc_lp_out_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006818_31_0:32;
    };
}audio_dummy_6718_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800681c_31_0:32;
    };
}audio_dummy_671c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  ch01_scale_a:4;
        RBus_UInt32  res2:1;
        RBus_UInt32  ch01_scale_b:3;
    };
}audio_hw_in_pre_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dist_vol_detect:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  dist_down_db_fine:2;
        RBus_UInt32  dist_down_db:2;
        RBus_UInt32  res2:1;
        RBus_UInt32  dist_coef:3;
        RBus_UInt32  dist_high_thre:8;
        RBus_UInt32  dist_low_thre:8;
        RBus_UInt32  dist_up_db_fine:2;
        RBus_UInt32  dist_up_db:2;
    };
}audio_hw_distortion_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  dist_cnt_thre:10;
        RBus_UInt32  dist_zc_win:10;
        RBus_UInt32  dist_mon_win:10;
    };
}audio_hw_distortion_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_count_reset:1;
        RBus_UInt32  avc2_detect_samples:15;
        RBus_UInt32  avc2_hi_threshold:16;
    };
}audio_avc2_distortion_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  avc2_count_l:15;
        RBus_UInt32  avc2_max_energy_l:16;
    };
}audio_avc2_distortion_status_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  avc2_count_r:15;
        RBus_UInt32  avc2_max_energy_r:16;
    };
}audio_avc2_distortion_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  step_mag_thre:8;
        RBus_UInt32  step_cnt_high_thre:8;
        RBus_UInt32  step_cnt_low_thre:8;
    };
}audio_hw_distortion_control_gain_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drc_vol_amplif_enable:1;
        RBus_UInt32  drc_lpf_coef:3;
        RBus_UInt32  drc_vol_detect:2;
        RBus_UInt32  drc_fast_recov_ctrl:1;
        RBus_UInt32  drc_slow_up_db:2;
        RBus_UInt32  drc_fast_up_db:2;
        RBus_UInt32  drc_down_db:2;
        RBus_UInt32  drc_noise_gain:2;
        RBus_UInt32  drc_noise_thre:16;
    };
}audio_drc_control_1_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  drc_cnt_thre:10;
        RBus_UInt32  drc_zc_win:10;
        RBus_UInt32  drc_mon_win:10;
    };
}audio_drc_control_2_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_noise_thre_hi:16;
        RBus_UInt32  drc_recov_win_max:8;
        RBus_UInt32  drc_recov_win_min:8;
    };
}audio_drc_control_3_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_level_max:16;
        RBus_UInt32  drc_level_min:16;
    };
}audio_drc_control_4_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  drc_slow_up_db_fine:2;
        RBus_UInt32  drc_fast_up_db_fine:2;
        RBus_UInt32  drc_down_db_fine:2;
        RBus_UInt32  drc_small_up_db_fine:2;
        RBus_UInt32  drc_small_down_db_fine:2;
        RBus_UInt32  drc_small_up_db:2;
        RBus_UInt32  drc_small_down_db:2;
        RBus_UInt32  drc_small_cnt_thre:8;
    };
}audio_drc_control_5_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_small_level_max:16;
        RBus_UInt32  drc_small_level_min:16;
    };
}audio_drc_control_6_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drc_small_level:31;
    };
}audio_drc_control_7_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lower_step_mag_thre:16;
        RBus_UInt32  drc_lower_step_cnt_low_thre:8;
        RBus_UInt32  drc_lower_step_cnt_hi_thre:8;
    };
}audio_drc_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_amplif_step_mag_thre:16;
        RBus_UInt32  drc_amplif_step_cnt_low_thre:8;
        RBus_UInt32  drc_amplif_step_cnt_hi_thre:8;
    };
}audio_drc_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drc_lpf_vol_amplif_enable:1;
        RBus_UInt32  drc_lpf_lpf_coef:3;
        RBus_UInt32  drc_lpf_vol_detect:2;
        RBus_UInt32  drc_lpf_fast_recov_ctrl:1;
        RBus_UInt32  drc_lpf_slow_up_db:2;
        RBus_UInt32  drc_lpf_fast_up_db:2;
        RBus_UInt32  drc_lpf_down_db:2;
        RBus_UInt32  drc_lpf_noise_gain:2;
        RBus_UInt32  drc_lpf_noise_thre:16;
    };
}audio_drc_lpf_control_1_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  drc_lpf_cnt_thre:10;
        RBus_UInt32  drc_lpf_zc_win:10;
        RBus_UInt32  drc_lpf_mon_win:10;
    };
}audio_drc_lpf_control_2_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_noise_thre_hi:16;
        RBus_UInt32  drc_lpf_recov_win_max:8;
        RBus_UInt32  drc_lpf_recov_win_min:8;
    };
}audio_drc_lpf_control_3_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_level_max:16;
        RBus_UInt32  drc_lpf_level_min:16;
    };
}audio_drc_lpf_control_4_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:10;
        RBus_UInt32  drc_lpf_slow_up_db_fine:2;
        RBus_UInt32  drc_lpf_fast_up_db_fine:2;
        RBus_UInt32  drc_lpf_down_db_fine:2;
        RBus_UInt32  drc_lpf_small_up_db_fine:2;
        RBus_UInt32  drc_lpf_small_down_db_fine:2;
        RBus_UInt32  drc_lpf_small_up_db:2;
        RBus_UInt32  drc_lpf_small_down_db:2;
        RBus_UInt32  drc_lpf_small_cnt_thre:8;
    };
}audio_drc_lpf_control_5_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_small_level_max:16;
        RBus_UInt32  drc_lpf_small_level_min:16;
    };
}audio_drc_lpf_control_6_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  drc_lpf_small_level:31;
    };
}audio_drc_lpf_control_7_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_lower_step_mag_thre:16;
        RBus_UInt32  drc_lpf_lower_step_cnt_low_thre:8;
        RBus_UInt32  drc_lpf_lower_step_cnt_hi_thre:8;
    };
}audio_drc_lpf_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_amplif_step_mag_thre:16;
        RBus_UInt32  drc_lpf_amplif_step_cnt_low_thre:8;
        RBus_UInt32  drc_lpf_amplif_step_cnt_hi_thre:8;
    };
}audio_drc_lpf_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  drc_rm_3:4;
        RBus_UInt32  drc_rm_2:4;
        RBus_UInt32  drc_rm_1:4;
        RBus_UInt32  drc_rm_0:4;
    };
}audio_drc_mbist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  drc_rme_3:1;
        RBus_UInt32  drc_rme_2:1;
        RBus_UInt32  drc_rme_1:1;
        RBus_UInt32  drc_rme_0:1;
    };
}audio_drc_mbist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lrrr_dvol_apply:1;
        RBus_UInt32  lrrr_zcto:3;
        RBus_UInt32  lrrr_ramp_step:2;
        RBus_UInt32  lrrr_delay_ctrl:10;
        RBus_UInt32  lrrr_mute_apply:1;
        RBus_UInt32  lrrr_zcto_mute:3;
        RBus_UInt32  lrrr_ramp_step_mute:2;
        RBus_UInt32  lrrr_delay_ctrl_mute:10;
    };
}audio_lrrr_digital_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:21;
        RBus_UInt32  lrrr_dvol_enable:1;
        RBus_UInt32  lrrr_zcto_status:1;
        RBus_UInt32  lrrr_zcth:5;
        RBus_UInt32  res2:2;
        RBus_UInt32  lrrr_dvcm:2;
    };
}audio_lrrr_digital_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mute_lr:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  hpf_lr_enable:1;
        RBus_UInt32  vol_lr_ready:1;
        RBus_UInt32  vol_lr_a:5;
        RBus_UInt32  vol_lr_b:6;
        RBus_UInt32  mute_rr:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  hpf_rr_enable:1;
        RBus_UInt32  vol_rr_ready:1;
        RBus_UInt32  vol_rr_a:5;
        RBus_UInt32  vol_rr_b:6;
    };
}audio_lrrr_digital_volume_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800690c_31_0:32;
    };
}audio_ts_ds_mbist_recoding_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:29;
        RBus_UInt32  down_sample_rate:2;
        RBus_UInt32  vol_source_sel:1;
    };
}audio_dvol_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  sif_adc_in_test_en:1;
        RBus_UInt32  sif_adc_in_test_sel:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  debug_mode_sel:9;
    };
}audio_test_pattern_gen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:8;
        RBus_UInt32  audio_crc_header:24;
    };
}audio_crc_header_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  audio_crc_en:1;
        RBus_UInt32  audio_crc_ch_sel:3;
        RBus_UInt32  audio_crc_frame_length:16;
    };
}audio_crc_contorl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  audio_crc_done:1;
        RBus_UInt32  audio_crc:24;
    };
}audio_crc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sine_auto_chk_en:1;
        RBus_UInt32  sine_channel_select:3;
        RBus_UInt32  res1:3;
        RBus_UInt32  auto_chk_result:1;
        RBus_UInt32  half_sine_num:2;
        RBus_UInt32  amplitude_low_threshold:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  zc_sample_cnt_threshold:6;
        RBus_UInt32  zc_sample_cnt_golden:12;
    };
}audio_sine_auto_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  sine_amplitude:8;
        RBus_UInt32  zc_sample_cnt:12;
    };
}audio_sine_wave_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006a18_31_1:31;
        RBus_UInt32  pcr_clk_1_sel_eco:1;
    };
}audio_pattern_gen_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:18;
        RBus_UInt32  rbus_timeout_thr:10;
        RBus_UInt32  dummy18006a50_3_1:3;
        RBus_UInt32  to_ack_en:1;
    };
}audio_rbus_ack_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  ack_fail_rw:1;
        RBus_UInt32  ack_fail_addr:12;
    };
}audio_ack_fail_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_bist_mode_nicam_src:1;
        RBus_UInt32  audio_bist_mode_hw_drc:1;
        RBus_UInt32  audio_bist_mode_dma_arc:1;
        RBus_UInt32  audio_bist_mode_ts_ds:1;
        RBus_UInt32  audio_bist_mode_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_bist_mode_adc_0:1;
        RBus_UInt32  audio_bist_mode_dac:1;
        RBus_UInt32  audio_bist_mode_dma_ts:1;
        RBus_UInt32  audio_bist_mode_dma:1;
        RBus_UInt32  audio_bist_mode_a2_eiaj:1;
        RBus_UInt32  audio_bist_mode_am:1;
        RBus_UInt32  audio_bist_mode_msd:1;
    };
}audio_audio_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_bist_done_nicam_src:1;
        RBus_UInt32  audio_bist_done_hw_drc:1;
        RBus_UInt32  audio_bist_done_dma_arc:1;
        RBus_UInt32  audio_bist_done_ts_ds:1;
        RBus_UInt32  audio_bist_done_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_bist_done_adc_0:1;
        RBus_UInt32  audio_bist_done_dac:1;
        RBus_UInt32  audio_bist_done_dma_ts:1;
        RBus_UInt32  audio_bist_done_dma:1;
        RBus_UInt32  audio_bist_done_a2_eiaj:1;
        RBus_UInt32  audio_bist_done_am:1;
        RBus_UInt32  audio_bist_done_msd:1;
    };
}audio_audio_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_bist_fail_group_nicam_src:1;
        RBus_UInt32  audio_bist_fail_group_hw_drc:1;
        RBus_UInt32  audio_bist_fail_group_dma_arc:1;
        RBus_UInt32  audio_bist_fail_group_ts_ds:1;
        RBus_UInt32  audio_bist_fail_group_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_bist_fail_group_adc_0:1;
        RBus_UInt32  audio_bist_fail_group_dac:1;
        RBus_UInt32  audio_bist_fail_group_dma_ts:1;
        RBus_UInt32  audio_bist_fail_group_dma:1;
        RBus_UInt32  audio_bist_fail_group_a2_eiaj:1;
        RBus_UInt32  audio_bist_fail_group_am:1;
        RBus_UInt32  audio_bist_fail_group_msd:1;
    };
}audio_audio_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_bist_dac_fail_1:1;
        RBus_UInt32  audio_bist_dac_fail_0:1;
        RBus_UInt32  audio_bist_down_ts_fail_3:1;
        RBus_UInt32  audio_bist_down_ts_fail_2:1;
        RBus_UInt32  audio_bist_down_ts_fail_1:1;
        RBus_UInt32  audio_bist_down_ts_fail_0:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  audio_bist_down_fail_3:1;
        RBus_UInt32  audio_bist_down_fail_2:1;
        RBus_UInt32  audio_bist_down_fail_1:1;
        RBus_UInt32  audio_bist_down_fail_0:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_8:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_7:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_6:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_5:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_4:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_3:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_2:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_1:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_0:1;
    };
}audio_audio_bist_a2_eiaj_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_drf_mode_nicam_src:1;
        RBus_UInt32  audio_drf_mode_hw_drc:1;
        RBus_UInt32  audio_drf_mode_dma_arc:1;
        RBus_UInt32  audio_drf_mode_ts_ds:1;
        RBus_UInt32  audio_drf_mode_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_drf_mode_adc_0:1;
        RBus_UInt32  audio_drf_mode_dac:1;
        RBus_UInt32  audio_drf_mode_dma_ts:1;
        RBus_UInt32  audio_drf_mode_dma:1;
        RBus_UInt32  audio_drf_mode_a2_eiaj:1;
        RBus_UInt32  audio_drf_mode_am:1;
        RBus_UInt32  audio_drf_mode_msd:1;
    };
}audio_audio_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_drf_resume_nicam_src:1;
        RBus_UInt32  audio_drf_resume_hw_drc:1;
        RBus_UInt32  audio_drf_resume_dma_arc:1;
        RBus_UInt32  audio_drf_resume_ts_ds:1;
        RBus_UInt32  audio_drf_resume_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_drf_resume_adc_0:1;
        RBus_UInt32  audio_drf_resume_dac:1;
        RBus_UInt32  audio_drf_resume_dma_ts:1;
        RBus_UInt32  audio_drf_resume_dma:1;
        RBus_UInt32  audio_drf_resume_a2_eiaj:1;
        RBus_UInt32  audio_drf_resume_am:1;
        RBus_UInt32  audio_drf_resume_msd:1;
    };
}audio_audio_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_drf_done_nicam_src:1;
        RBus_UInt32  audio_drf_done_hw_drc:1;
        RBus_UInt32  audio_drf_done_dma_arc:1;
        RBus_UInt32  audio_drf_done_ts_ds:1;
        RBus_UInt32  audio_drf_done_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_drf_done_adc_0:1;
        RBus_UInt32  audio_drf_done_dac:1;
        RBus_UInt32  audio_drf_done_dma_ts:1;
        RBus_UInt32  audio_drf_done_dma:1;
        RBus_UInt32  audio_drf_done_a2_eiaj:1;
        RBus_UInt32  audio_drf_done_am:1;
        RBus_UInt32  audio_drf_done_msd:1;
    };
}audio_audio_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_drf_pause_nicam_src:1;
        RBus_UInt32  audio_drf_pause_hw_drc:1;
        RBus_UInt32  audio_drf_pause_dma_arc:1;
        RBus_UInt32  audio_drf_pause_ts_ds:1;
        RBus_UInt32  audio_drf_pause_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_drf_pause_adc_0:1;
        RBus_UInt32  audio_drf_pause_dac:1;
        RBus_UInt32  audio_drf_pause_dma_ts:1;
        RBus_UInt32  audio_drf_pause_dma:1;
        RBus_UInt32  audio_drf_pause_a2_eiaj:1;
        RBus_UInt32  audio_drf_pause_am:1;
        RBus_UInt32  audio_drf_pause_msd:1;
    };
}audio_audio_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:19;
        RBus_UInt32  audio_drf_fail_group_nicam_src:1;
        RBus_UInt32  audio_drf_fail_group_hw_drc:1;
        RBus_UInt32  audio_drf_fail_group_dma_arc:1;
        RBus_UInt32  audio_drf_fail_group_ts_ds:1;
        RBus_UInt32  audio_drf_fail_group_ds:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  audio_drf_fail_group_adc_0:1;
        RBus_UInt32  audio_drf_fail_group_dac:1;
        RBus_UInt32  audio_drf_fail_group_dma_ts:1;
        RBus_UInt32  audio_drf_fail_group_dma:1;
        RBus_UInt32  audio_drf_fail_group_a2_eiaj:1;
        RBus_UInt32  audio_drf_fail_group_am:1;
        RBus_UInt32  audio_drf_fail_group_msd:1;
    };
}audio_audio_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_drf_dac_fail_1:1;
        RBus_UInt32  audio_drf_dac_fail_0:1;
        RBus_UInt32  audio_drf_down_ts_fail_3:1;
        RBus_UInt32  audio_drf_down_ts_fail_2:1;
        RBus_UInt32  audio_drf_down_ts_fail_1:1;
        RBus_UInt32  audio_drf_down_ts_fail_0:1;
        RBus_UInt32  res2:12;
        RBus_UInt32  audio_drf_down_fail_3:1;
        RBus_UInt32  audio_drf_down_fail_2:1;
        RBus_UInt32  audio_drf_down_fail_1:1;
        RBus_UInt32  audio_drf_down_fail_0:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_8:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_7:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_6:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_5:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_4:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_3:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_2:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_1:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_0:1;
    };
}audio_audio_drf_a2_eiaj_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  audio_drf_nicam_src_fail_1:1;
        RBus_UInt32  audio_drf_nicam_src_fail_0:1;
        RBus_UInt32  audio_drf_hw_drc_fail_3:1;
        RBus_UInt32  audio_drf_hw_drc_fail_2:1;
        RBus_UInt32  audio_drf_hw_drc_fail_1:1;
        RBus_UInt32  audio_drf_hw_drc_fail_0:1;
    };
}audio_audio_drf_hw_drc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:26;
        RBus_UInt32  audio_bist_nicam_src_1:1;
        RBus_UInt32  audio_bist_nicam_src_0:1;
        RBus_UInt32  audio_bist_hw_drc_3:1;
        RBus_UInt32  audio_bist_hw_drc_2:1;
        RBus_UInt32  audio_bist_hw_drc_1:1;
        RBus_UInt32  audio_bist_hw_drc_0:1;
    };
}audio_audio_bist_hw_drc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  daad_lp_en_0:1;
        RBus_UInt32  src_op_sel_0:1;
        RBus_UInt32  src_ad0_lpf1st_fc_sel:2;
        RBus_UInt32  ad0_hpf_en:1;
        RBus_UInt32  ad0_comp_gain:3;
        RBus_UInt32  ad0_zdet_tout:2;
        RBus_UInt32  ad0_zdet_func:2;
        RBus_UInt32  adc0_src_lpf_disable:1;
        RBus_UInt32  ad0_lp_sel:1;
        RBus_UInt32  ad0_mute_l:1;
        RBus_UInt32  ad0_mute_r:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ad0_gain_l:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ad0_gain_r:7;
    };
}audio_ad0_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adda_lp_en_0:1;
        RBus_UInt32  src_en_0:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  da0_hpf_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  da0_dither_sel:2;
        RBus_UInt32  da0_zdet_tout:2;
        RBus_UInt32  da0_zdet_func:2;
        RBus_UInt32  da0_fifo_empty:1;
        RBus_UInt32  da0_fifo_full:1;
        RBus_UInt32  da0_fifo_empty_pending:1;
        RBus_UInt32  da0_fifo_full_pending:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  da0_gain_l:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  da0_gain_r:7;
    };
}audio_da0_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adda_lp_en_1:1;
        RBus_UInt32  src_en_1:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  da1_hpf_en:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  da1_dither_sel:2;
        RBus_UInt32  da1_zdet_tout:2;
        RBus_UInt32  da1_zdet_func:2;
        RBus_UInt32  da1_fifo_empty:1;
        RBus_UInt32  da1_fifo_full:1;
        RBus_UInt32  da1_fifo_empty_pending:1;
        RBus_UInt32  da1_fifo_full_pending:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  da1_gain_l:7;
        RBus_UInt32  res4:1;
        RBus_UInt32  da1_gain_r:7;
    };
}audio_da1_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dac1_hw_l_inverter_en:1;
        RBus_UInt32  dac1_hw_r_inverter_en:1;
        RBus_UInt32  dac1_hw_out_limiter_en:1;
        RBus_UInt32  dac1_hw_out_limiter:7;
        RBus_UInt32  dac1_pcm_source_sel:4;
        RBus_UInt32  dac0_swap_sel:2;
        RBus_UInt32  dac1_swap_sel:2;
        RBus_UInt32  dac0_hw_l_inverter_en:1;
        RBus_UInt32  dac0_hw_r_inverter_en:1;
        RBus_UInt32  dac0_hw_out_limiter_en:1;
        RBus_UInt32  dac0_hw_out_limiter:7;
        RBus_UInt32  dac0_pcm_source_sel:4;
    };
}audio_dac0_1_src_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_dvol_enable:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  reg_in_thre:5;
        RBus_UInt32  reg_zero_in_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  zcth:5;
        RBus_UInt32  res3:2;
        RBus_UInt32  dvcm:2;
    };
}audio_adc_digital_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvol_apply:1;
        RBus_UInt32  zcto:3;
        RBus_UInt32  ramp_step:2;
        RBus_UInt32  delay_ctrl:10;
        RBus_UInt32  mute_apply:1;
        RBus_UInt32  zcto_mute:3;
        RBus_UInt32  ramp_step_mute:2;
        RBus_UInt32  delay_ctrl_mute:10;
    };
}audio_adc_digital_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mute_l:1;
        RBus_UInt32  rep_l_status:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hpf_l_enable:1;
        RBus_UInt32  vol_l_ready:1;
        RBus_UInt32  vol_l_a:5;
        RBus_UInt32  vol_l_b:6;
        RBus_UInt32  mute_r:1;
        RBus_UInt32  rep_r_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hpf_r_enable:1;
        RBus_UInt32  vol_r_ready:1;
        RBus_UInt32  vol_r_a:5;
        RBus_UInt32  vol_r_b:6;
    };
}audio_adc_lr_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mute_ls:1;
        RBus_UInt32  rep_ls_status:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  hpf_ls_enable:1;
        RBus_UInt32  vol_ls_ready:1;
        RBus_UInt32  vol_ls_a:5;
        RBus_UInt32  vol_ls_b:6;
        RBus_UInt32  mute_rs:1;
        RBus_UInt32  rep_rs_status:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  hpf_rs_enable:1;
        RBus_UInt32  vol_rs_ready:1;
        RBus_UInt32  vol_rs_a:5;
        RBus_UInt32  vol_rs_b:6;
    };
}audio_adc_lsrs_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:30;
        RBus_UInt32  zcto_status:1;
        RBus_UInt32  double_buffer_ack:1;
    };
}audio_adc_double_buffer_ack_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  adc_dvol_enable_1:1;
        RBus_UInt32  dvol_apply_1:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  zcto_status_1:1;
        RBus_UInt32  double_buffer_ack_1:1;
    };
}audio_adc_double_buffer_ack_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_bb_adcfe_muter:7;
        RBus_UInt32  res2:11;
        RBus_UInt32  reg_bb_adcfe_mutel:7;
    };
}audio_analog_frontend1_mute_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_hpo_bias_sel:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  reg_bb_hpo_mutel:7;
        RBus_UInt32  res2:12;
        RBus_UInt32  reg_bb_aio1_mutel:6;
    };
}audio_analog_aio_hpout_lineout_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:7;
        RBus_UInt32  reg_bb_hpo_muter:7;
        RBus_UInt32  res2:12;
        RBus_UInt32  reg_bb_aio1_muter:6;
    };
}audio_analog_aio_hpout_lineout_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:28;
        RBus_UInt32  reg_bb_adcfe_gsell:2;
        RBus_UInt32  reg_bb_adcfe_gselr:2;
    };
}audio_adc_volume_gain_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  reg_bb_adcfe_pow:1;
        RBus_UInt32  reg_bb_adc_pow:1;
        RBus_UInt32  reg_bb_dac_pow:2;
        RBus_UInt32  reg_bb_mbias_pow:1;
        RBus_UInt32  reg_bb_vref_pow:1;
        RBus_UInt32  reg_bb_df2se_pow:2;
        RBus_UInt32  reg_bb_hpo_pow:1;
        RBus_UInt32  reg_bb_aio1_pow:1;
        RBus_UInt32  res2:2;
    };
}audio_analog_power_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  reg_bb_hpo_hpmode:1;
        RBus_UInt32  reg_bb_adcfe_input_20k:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  option_gain:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  fix_gain:3;
        RBus_UInt32  res4:5;
        RBus_UInt32  afe_pga_vol:4;
    };
}audio_analog_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_isel_adc_vcm:2;
        RBus_UInt32  reg_bb_isel_vref:2;
        RBus_UInt32  reg_bb_isel_aio1:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_bb_isel_hpo:2;
        RBus_UInt32  reg_bb_isel_df2se:2;
        RBus_UInt32  reg_bb_isel_depop:2;
        RBus_UInt32  reg_bb_isel_dac_vref:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  reg_bb_isel_dac:2;
        RBus_UInt32  res3:4;
        RBus_UInt32  reg_bb_isel_adc_ref:2;
        RBus_UInt32  reg_bb_isel_adcfe:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_bb_isel_adc_aa:2;
    };
}audio_analog_ci01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:22;
        RBus_UInt32  reg_bb_adc_ossel:2;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_bb_adc_ckxen:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_bb_vref_vrefsel:2;
    };
}audio_analog_ci02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:20;
        RBus_UInt32  reg_bb_isel_adc_core:2;
        RBus_UInt32  reg_bb_hpo_endp:1;
        RBus_UInt32  reg_bb_aio_endp:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_bb_dpramp_enramp:1;
        RBus_UInt32  bb_ck_depop_en:1;
        RBus_UInt32  sel_bb_ck_depop:3;
    };
}audio_analog_depop1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:24;
        RBus_UInt32  reg_bb_dpramp_rampsel:1;
        RBus_UInt32  reg_bb_dpramp_pow:1;
        RBus_UInt32  reg_bb_dpramp_csel:2;
        RBus_UInt32  reg_bb_hpo_normal:1;
        RBus_UInt32  reg_bb_aio1_normal:1;
        RBus_UInt32  res2:2;
    };
}audio_analog_depop2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  reg_bb_hpo_engl:1;
        RBus_UInt32  reg_bb_hpo_engr:1;
        RBus_UInt32  res2:20;
        RBus_UInt32  reg_bb_hpo_gsell:2;
        RBus_UInt32  reg_bb_hpo_gselr:2;
    };
}audio_analog_post_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}audio_analog_out_copy_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}audio_analog_gpio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:3;
        RBus_UInt32  rme_1_dac:1;
        RBus_UInt32  rm_1_dac:4;
        RBus_UInt32  res2:3;
        RBus_UInt32  rme_0_dac:1;
        RBus_UInt32  rm_0_dac:4;
        RBus_UInt32  res3:8;
        RBus_UInt32  res4:3;
        RBus_UInt32  rme_0_adc:1;
        RBus_UInt32  rm_0_adc:4;
    };
}audio_drf_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006b78_31_0:32;
    };
}audio_analog_dummy2_RBUS;

#else //apply LITTLE_ENDIAN

//======AUDIO register structure define==========

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  sel_clk_dac1_fsi:1;
        RBus_UInt32  sel_clk_dac0_fsi:1;
        RBus_UInt32  sel_clk_adc_fsi:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  play_r_adc_512fs_sel_arc:2;
        RBus_UInt32  div_arcdma_r_512fs:2;
        RBus_UInt32  sel_64fs:3;
        RBus_UInt32  sel_64fs_ts:3;
        RBus_UInt32  play_r_adc_512fs_sel_ts:2;
        RBus_UInt32  play_r_adc_512fs_sel:2;
        RBus_UInt32  div_tsdma_r_512fs:2;
        RBus_UInt32  div_dma_r_512fs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  frontend_clkgate_enable:1;
        RBus_UInt32  div_pre_512fs_ts:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  inv_ad_128fs:1;
        RBus_UInt32  res5:1;
    };
}audio_global_ctrl_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_clk_spdif_out_1:2;
        RBus_UInt32  sel_clk_spdif_out:2;
        RBus_UInt32  spdif_in_en:1;
        RBus_UInt32  spdif_out_en:1;
        RBus_UInt32  i2s_in_en:1;
        RBus_UInt32  i2s_out_en:1;
        RBus_UInt32  tv_demod_en:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_pcr_clk_0_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  res3:13;
        RBus_UInt32  sel_clk_i2s_out:3;
    };
}audio_global_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_play_r_ck_source:2;
        RBus_UInt32  back_end_play_sample_rate:2;
        RBus_UInt32  sel_play_ck_source:2;
        RBus_UInt32  adc_512fs_sel:2;
        RBus_UInt32  sel_play_r_ck_source_ts:2;
        RBus_UInt32  back_end_ts_sample_rate:2;
        RBus_UInt32  sel_ts_ck_source:2;
        RBus_UInt32  adc_512fs_sel_ts:2;
        RBus_UInt32  spdif_nicam:1;
        RBus_UInt32  sel_play_r_ck_source_arc:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  sif_adc_clk_en:1;
        RBus_UInt32  sif_adc_clk_sel:2;
        RBus_UInt32  hdv_mode_sel:1;
        RBus_UInt32  src_da_128fs_ts:1;
        RBus_UInt32  src_da_128fs:1;
        RBus_UInt32  inv_da_128fs_ts:1;
        RBus_UInt32  inv_da_128fs:1;
        RBus_UInt32  a2_eiaj_sram_on:1;
        RBus_UInt32  am_sram_on:1;
        RBus_UInt32  dac_sram_on:1;
        RBus_UInt32  adc_sram_on:1;
    };
}audio_global_ctrl_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  asrcin0_ftk_sdm_ini:22;
        RBus_UInt32  asrcin0_div_fsi:2;
        RBus_UInt32  asrcin0_ftk_loop_gain_sel:1;
        RBus_UInt32  asrcin0_ftk_loop_filter_mode:1;
        RBus_UInt32  reg_tcon0_rst_n:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  asrcin0_fsi_rate_manual:4;
    };
}audio_tcon0_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  asrcin1_ftk_sdm_ini:22;
        RBus_UInt32  asrcin1_div_fsi:2;
        RBus_UInt32  asrcin1_ftk_loop_gain_sel:1;
        RBus_UInt32  asrcin1_ftk_loop_filter_mode:1;
        RBus_UInt32  reg_tcon1_rst_n:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  asrcin1_fsi_rate_manual:4;
    };
}audio_tcon1_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_para_a:6;
        RBus_UInt32  reg_para_b:7;
        RBus_UInt32  reg_para_d:5;
        RBus_UInt32  mod_acc_rst:1;
        RBus_UInt32  pll_spdif_auto_mode:1;
        RBus_UInt32  reg_smooth_en:1;
        RBus_UInt32  pll_spdif_dtrack_en:1;
        RBus_UInt32  ps_testmode:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  reg_para_e:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  div_2fs:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  contword_inv:1;
    };
}audio_pllcg_spdif_gain_cr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  p_gain_set2:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  p_gain_set:10;
        RBus_UInt32  res2:6;
    };
}audio_pllcg_spdif_gain_cr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  i_gain_set:10;
        RBus_UInt32  res1:22;
    };
}audio_pllcg_spdif_gain_cr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_correct_range:4;
        RBus_UInt32  reach_time_num:3;
        RBus_UInt32  res1:25;
    };
}audio_pllcg_spdif_number_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_bound2:8;
        RBus_UInt32  high_bound2:8;
        RBus_UInt32  low_bound1:8;
        RBus_UInt32  high_bound1:8;
    };
}audio_pllcg_spdif_bound_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  freq_sel:2;
        RBus_UInt32  wdog_switch_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  freq_sel_1:2;
        RBus_UInt32  wdog_switch_en_1:1;
        RBus_UInt32  phase_contword:5;
        RBus_UInt32  res2:4;
        RBus_UInt32  inv_ck512fs_pll_spdif:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  dummy18006024_31_19:13;
    };
}audio_global_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  asrcin2_ftk_sdm_ini:22;
        RBus_UInt32  asrcin2_div_fsi:2;
        RBus_UInt32  asrcin2_ftk_loop_gain_sel:1;
        RBus_UInt32  asrcin2_ftk_loop_filter_mode:1;
        RBus_UInt32  reg_tcon2_rst_n:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  asrcin2_fsi_rate_manual:4;
    };
}audio_tcon2_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  average_value:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  deta:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_64_512_detect_en:1;
        RBus_UInt32  pll_64_512fs_unstable:1;
        RBus_UInt32  cnt_debug:8;
        RBus_UInt32  res3:6;
    };
}audio_pll_64_512_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  average_value_1:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  deta_1:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  pll_64_512_1_detect_en:1;
        RBus_UInt32  pll_64_512fs_1_unstable:1;
        RBus_UInt32  cnt_debug_1:8;
        RBus_UInt32  res3:6;
    };
}audio_pll_64_512_1_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_sif_ovf_en:1;
        RBus_UInt32  int_mode_det_status_change_en:1;
        RBus_UInt32  int_msd_timeout_en:1;
        RBus_UInt32  int_msd_change_en:1;
        RBus_UInt32  int_sif_nopt_en:1;
        RBus_UInt32  int_pll64512_wd_en_1:1;
        RBus_UInt32  int_i2s_pri_word_length_change_en:1;
        RBus_UInt32  int_spi_sample_rate_chg_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  int_i2s_pri_sample_rate_chg_en:1;
        RBus_UInt32  int_nicam_hierr_change_en:1;
        RBus_UInt32  int_spi_in_lock_change_en:1;
        RBus_UInt32  int_spi_in_datatype_change_en:1;
        RBus_UInt32  int_aout_timer_en:1;
        RBus_UInt32  int_ain_timer_en:1;
        RBus_UInt32  int_nicam_level_status_en:1;
        RBus_UInt32  int_fifo0_empty_en:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  int_fifo0_full_en:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  int_btsc_mode_chg_en:1;
        RBus_UInt32  int_rbus_timeout_en:1;
        RBus_UInt32  int_msd_fw_scan_done_en:1;
        RBus_UInt32  int_msd_decision_done_en:1;
        RBus_UInt32  int_pll64512_wd_en:1;
        RBus_UInt32  int_fifo0_ts_empty_en:1;
        RBus_UInt32  int_fifo0_ts_full_en:1;
        RBus_UInt32  int_nicam_true_detect_en:1;
    };
}audio_interrupt_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_sif_ovf:1;
        RBus_UInt32  int_mode_det_status_change:1;
        RBus_UInt32  int_msd_timeout:1;
        RBus_UInt32  int_msd_change:1;
        RBus_UInt32  int_sif_nopt:1;
        RBus_UInt32  int_pll64512_wd_1:1;
        RBus_UInt32  int_i2s_pri_word_length_change:1;
        RBus_UInt32  int_spi_sample_rate_chg:1;
        RBus_UInt32  int_mic_short_status:1;
        RBus_UInt32  int_i2s_pri_sample_rate_chg:1;
        RBus_UInt32  int_nicam_hierr_change:1;
        RBus_UInt32  int_spi_in_lock_change:1;
        RBus_UInt32  int_spi_in_datatype_change:1;
        RBus_UInt32  int_aout_timer:1;
        RBus_UInt32  int_ain_timer:1;
        RBus_UInt32  int_nicam_level_status:1;
        RBus_UInt32  int_fifo0_empty:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  int_fifo0_full:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  int_btsc_mode_chg:1;
        RBus_UInt32  int_rbus_timeout:1;
        RBus_UInt32  int_msd_fw_scan_done:1;
        RBus_UInt32  int_msd_decision_done:1;
        RBus_UInt32  int_pll64512_wd:1;
        RBus_UInt32  int_fifo0_ts_empty:1;
        RBus_UInt32  int_fifo0_ts_full:1;
        RBus_UInt32  int_nicam_true_detect:1;
    };
}audio_interrupt_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aout_timer_en:1;
        RBus_UInt32  ain_timer_en:1;
        RBus_UInt32  aout_timer_src:2;
        RBus_UInt32  ain_timer_src:2;
        RBus_UInt32  timer_div:3;
        RBus_UInt32  timer_clr_mode_sel:1;
        RBus_UInt32  res1:22;
    };
}audio_aio_timer_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ain_timer:32;
    };
}audio_ain_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ain_compare:32;
    };
}audio_ain_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aout_timer:32;
    };
}audio_aout_counter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  aout_compare:32;
    };
}audio_aout_compare_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_0:32;
    };
}audio_sw_dbg_reg_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_1:32;
    };
}audio_sw_dbg_reg_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_2:32;
    };
}audio_sw_dbg_reg_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sw_dbg_reg_3:32;
    };
}audio_sw_dbg_reg_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  int_64_512fs_unstable:1;
        RBus_UInt32  int_64_512fs_unstable_1:1;
        RBus_UInt32  res1:14;
        RBus_UInt32  int_64_512_unstable_en:1;
        RBus_UInt32  int_64_512_unstable_1_en:1;
        RBus_UInt32  res2:14;
    };
}audio_int_en_states_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcm_width:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  sampling_rate:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  dummy18006100_24_16:9;
        RBus_UInt32  sclk_inv:1;
        RBus_UInt32  debounce_en:1;
        RBus_UInt32  mode_sel:1;
        RBus_UInt32  left_right:2;
        RBus_UInt32  source_sel:2;
    };
}audio_i2s_in_primary_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sampling_rate:4;
        RBus_UInt32  spdif_in_2fs_sel:1;
        RBus_UInt32  dummy18006130_15_5:11;
        RBus_UInt32  res1:11;
        RBus_UInt32  source_sel_spdif_out:1;
        RBus_UInt32  debounce_en:1;
        RBus_UInt32  req_after_lock:1;
        RBus_UInt32  source_sel:2;
    };
}audio_spdif_in_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  professional_r:1;
        RBus_UInt32  data_type_r:1;
        RBus_UInt32  copyright_r:1;
        RBus_UInt32  pre_emphasis_r:3;
        RBus_UInt32  mode_r:2;
        RBus_UInt32  category_code_r:8;
        RBus_UInt32  source_number_r:4;
        RBus_UInt32  channel_number_r:4;
        RBus_UInt32  sampling_freq_r:4;
        RBus_UInt32  clock_accuracy_r:2;
        RBus_UInt32  invalid_bit:1;
        RBus_UInt32  hw_locked:1;
    };
}audio_spdif_in_cs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  word_length_r:4;
        RBus_UInt32  original_sampling_freq_r:4;
        RBus_UInt32  cgms_a_r:2;
        RBus_UInt32  cgms_a_l:2;
        RBus_UInt32  professional_l:1;
        RBus_UInt32  data_type_l:1;
        RBus_UInt32  copyright_l:1;
        RBus_UInt32  pre_emphasis_l:3;
        RBus_UInt32  cs_lb3_31_30:2;
        RBus_UInt32  cs_rb3_31_30:2;
        RBus_UInt32  res1:10;
    };
}audio_spdif_in_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_l:2;
        RBus_UInt32  category_code_l:8;
        RBus_UInt32  source_number_l:4;
        RBus_UInt32  channel_number_l:4;
        RBus_UInt32  sampling_freq_l:4;
        RBus_UInt32  clock_accuracy_l:2;
        RBus_UInt32  word_length_l:4;
        RBus_UInt32  original_sampling_freq_l:4;
    };
}audio_spdif_in_cs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_7_5_r:22;
        RBus_UInt32  res1:10;
    };
}audio_spdif_in_cs_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_r:32;
    };
}audio_spdif_in_cs_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_r:32;
    };
}audio_spdif_in_cs_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_r:32;
    };
}audio_spdif_in_cs_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_r:32;
    };
}audio_spdif_in_cs_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_7_5_l:22;
        RBus_UInt32  res1:10;
    };
}audio_spdif_in_cs_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_l:32;
    };
}audio_spdif_in_cs_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_l:32;
    };
}audio_spdif_in_cs_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_l:32;
    };
}audio_spdif_in_cs_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_l:32;
    };
}audio_spdif_in_cs_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern_search_length1:15;
        RBus_UInt32  res1:15;
        RBus_UInt32  pattern_search_catch1:1;
        RBus_UInt32  pattern_search_enable1:1;
    };
}audio_spdif_pattern_search1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  specific_pattern1:32;
    };
}audio_spdif_pattern_set1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pattern_search_length2:15;
        RBus_UInt32  res1:15;
        RBus_UInt32  pattern_search_catch2:1;
        RBus_UInt32  pattern_search_enable2:1;
    };
}audio_spdif_pattern_search2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  specific_pattern2:32;
    };
}audio_spdif_pattern_set2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:16;
        RBus_UInt32  det_path_sel:1;
        RBus_UInt32  hbr_i2s_ch_no:3;
        RBus_UInt32  papb_04_flag:1;
        RBus_UInt32  res2:9;
        RBus_UInt32  papb_search_catch:1;
        RBus_UInt32  papb_search_enable:1;
    };
}audio_spdif_papb_search_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_val:16;
        RBus_UInt32  pd_val:16;
    };
}audio_spdif_papb_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pa_val:16;
        RBus_UInt32  pb_val:16;
    };
}audio_spdif_papb_val2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_val_buf:32;
    };
}audio_spdif_papb_val3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_val_pat1:16;
        RBus_UInt32  pd_val_pat1:16;
    };
}audio_spdif_pattern1_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pc_val_pat2:16;
        RBus_UInt32  pd_val_pat2:16;
    };
}audio_spdif_pattern2_val_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006150_15_0:16;
        RBus_UInt32  sclk_inv:1;
        RBus_UInt32  wclk_inv:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  mclk_sel:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  output_sel:3;
        RBus_UInt32  output_swap_sel:1;
    };
}audio_i2s_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  swap_sel_ch01:2;
        RBus_UInt32  res2:8;
        RBus_UInt32  pcm_source_sel_ch23:4;
        RBus_UInt32  pcm_source_sel_ch01:4;
    };
}audio_i2s_out_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_limit_ch01:7;
        RBus_UInt32  hw_limit_en_ch01:1;
        RBus_UInt32  res1:24;
    };
}audio_i2s_out_sel_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006170_15_0:16;
        RBus_UInt32  swap_sel:2;
        RBus_UInt32  res1:5;
        RBus_UInt32  pcm_source_sel:4;
        RBus_UInt32  spdif_out_null_burst:1;
        RBus_UInt32  validity_ctrl:1;
        RBus_UInt32  wait_en:1;
        RBus_UInt32  output_sel:2;
    };
}audio_spdif_out_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  professional:1;
        RBus_UInt32  data_type:1;
        RBus_UInt32  copyright:1;
        RBus_UInt32  pre_emphasis:3;
        RBus_UInt32  mode:2;
        RBus_UInt32  category_code:8;
        RBus_UInt32  source_number:4;
        RBus_UInt32  channel_number:4;
        RBus_UInt32  sampling_freq:4;
        RBus_UInt32  clock_accuracy:2;
        RBus_UInt32  cs_lb3_31_30:2;
    };
}audio_spdif_out_cs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  word_length:4;
        RBus_UInt32  original_sampling_freq:4;
        RBus_UInt32  cgms_a:2;
        RBus_UInt32  res1:22;
    };
}audio_spdif_out_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_limit:7;
        RBus_UInt32  hw_limit_en:1;
        RBus_UInt32  res1:24;
    };
}audio_spdif_out_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  professional_r:1;
        RBus_UInt32  data_type_r:1;
        RBus_UInt32  copyright_r:1;
        RBus_UInt32  pre_emphasis_r:3;
        RBus_UInt32  mode_r:2;
        RBus_UInt32  category_code_r:8;
        RBus_UInt32  source_number_r:4;
        RBus_UInt32  channel_number_r:4;
        RBus_UInt32  sampling_freq_r:4;
        RBus_UInt32  clock_accuracy_r:2;
        RBus_UInt32  cs_rb3_31_30:2;
    };
}audio_spdif_out_cs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  word_length_r:4;
        RBus_UInt32  original_sampling_freq_r:4;
        RBus_UInt32  cgms_a_r:2;
        RBus_UInt32  res1:22;
    };
}audio_spdif_out_cs_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_7_5_l:22;
        RBus_UInt32  res1:10;
    };
}audio_spdif_out_cs_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_l:32;
    };
}audio_spdif_out_cs_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_l:32;
    };
}audio_spdif_out_cs_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_l:32;
    };
}audio_spdif_out_cs_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_l:32;
    };
}audio_spdif_out_cs_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_7_5_r:22;
        RBus_UInt32  res1:10;
    };
}audio_spdif_out_cs_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_r:32;
    };
}audio_spdif_out_cs_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_r:32;
    };
}audio_spdif_out_cs_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_r:32;
    };
}audio_spdif_out_cs_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_r:32;
    };
}audio_spdif_out_cs_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006e60_15_0:16;
        RBus_UInt32  swap_sel:2;
        RBus_UInt32  res1:5;
        RBus_UInt32  pcm_source_sel:4;
        RBus_UInt32  spdif_out_null_burst:1;
        RBus_UInt32  validity_ctrl:1;
        RBus_UInt32  wait_en:1;
        RBus_UInt32  output_sel:2;
    };
}audio_spdif_out_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  professional:1;
        RBus_UInt32  data_type:1;
        RBus_UInt32  copyright:1;
        RBus_UInt32  pre_emphasis:3;
        RBus_UInt32  mode:2;
        RBus_UInt32  category_code:8;
        RBus_UInt32  source_number:4;
        RBus_UInt32  channel_number:4;
        RBus_UInt32  sampling_freq:4;
        RBus_UInt32  clock_accuracy:2;
        RBus_UInt32  cs_lb3_31_30:2;
    };
}audio_spdif_out_1_cs_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  word_length:4;
        RBus_UInt32  original_sampling_freq:4;
        RBus_UInt32  cgms_a:2;
        RBus_UInt32  res1:22;
    };
}audio_spdif_out_1_cs_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_limit:7;
        RBus_UInt32  hw_limit_en:1;
        RBus_UInt32  res1:24;
    };
}audio_spdif_out_1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  professional_r:1;
        RBus_UInt32  data_type_r:1;
        RBus_UInt32  copyright_r:1;
        RBus_UInt32  pre_emphasis_r:3;
        RBus_UInt32  mode_r:2;
        RBus_UInt32  category_code_r:8;
        RBus_UInt32  source_number_r:4;
        RBus_UInt32  channel_number_r:4;
        RBus_UInt32  sampling_freq_r:4;
        RBus_UInt32  clock_accuracy_r:2;
        RBus_UInt32  cs_rb3_31_30:2;
    };
}audio_spdif_out_1_cs_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  word_length_r:4;
        RBus_UInt32  original_sampling_freq_r:4;
        RBus_UInt32  cgms_a_r:2;
        RBus_UInt32  res1:22;
    };
}audio_spdif_out_1_cs_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_7_5_l:22;
        RBus_UInt32  res1:10;
    };
}audio_spdif_out_1_cs_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_l:32;
    };
}audio_spdif_out_1_cs_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_l:32;
    };
}audio_spdif_out_1_cs_7_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_l:32;
    };
}audio_spdif_out_1_cs_8_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_l:32;
    };
}audio_spdif_out_1_cs_9_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_7_5_r:22;
        RBus_UInt32  res1:10;
    };
}audio_spdif_out_1_cs_10_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_11_8_r:32;
    };
}audio_spdif_out_1_cs_11_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_15_12_r:32;
    };
}audio_spdif_out_1_cs_12_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_19_16_r:32;
    };
}audio_spdif_out_1_cs_13_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  cs_byte_23_20_r:32;
    };
}audio_spdif_out_1_cs_14_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ob_time:16;
        RBus_UInt32  hw_agc_en:1;
        RBus_UInt32  dummy18006180_19_17:3;
        RBus_UInt32  res1:12;
    };
}audio_sif_agc_eval_cnt_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  non_opt_cnt_ovf:8;
        RBus_UInt32  non_opt_cnt_under:8;
        RBus_UInt32  non_opt_cnt_th:3;
        RBus_UInt32  res1:13;
    };
}audio_sif_agc_optimal_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  opt_th:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  ovf_th:10;
        RBus_UInt32  res2:6;
    };
}audio_sif_agc_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  abs_peak:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  opt:1;
        RBus_UInt32  ovf:1;
        RBus_UInt32  res2:18;
    };
}audio_sif_agc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc2_obtime:16;
        RBus_UInt32  agc2_gain_b:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  agc2_gain_a:2;
        RBus_UInt32  agc2_stepsize:2;
        RBus_UInt32  agc2_debounce_cnt:3;
        RBus_UInt32  res2:1;
    };
}audio_sif_agc2_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  agc2_sif_mag:10;
        RBus_UInt32  res1:18;
        RBus_UInt32  agc2_underflow:1;
        RBus_UInt32  agc2_overflow:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  agc2_en:1;
    };
}audio_sif_agc2_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_upsample_lp_sel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  audio_bp_sel:8;
        RBus_UInt32  output_bpf_input_div2:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  audio_gain_manual:9;
        RBus_UInt32  res3:3;
        RBus_UInt32  aagc_en:1;
        RBus_UInt32  res4:3;
    };
}audio_sif_agc3_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:12;
        RBus_UInt32  debug_mode2:2;
        RBus_UInt32  audiodbg_fifo_empty:1;
        RBus_UInt32  audiodbg_fifo_full:1;
        RBus_UInt32  audiodbg_fifo_clr:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  audiodn_fifo_empty:1;
        RBus_UInt32  audiodn_fifo_full:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  audiodn_fifo_clr:1;
        RBus_UInt32  res4:3;
        RBus_UInt32  soft_reset:1;
        RBus_UInt32  res5:3;
    };
}audio_sif_agc3_ctrl_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  detect_source_sel:4;
        RBus_UInt32  pdetect_enable:1;
        RBus_UInt32  res1:27;
    };
}audio_peak_contorl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ovf_th_l:16;
        RBus_UInt32  opt_th_l:16;
    };
}audio_peak_contorl_l_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpp_eval_cnt_l:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  nonopt_cnt_tr_l:3;
        RBus_UInt32  dummy180061b4_31_19:13;
    };
}audio_peak_control_l_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  magnitude_l:16;
        RBus_UInt32  pk_adj_l:6;
        RBus_UInt32  overflow_l:1;
        RBus_UInt32  optimize_l:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  overflow_l_irq_en:1;
        RBus_UInt32  optimize_l_irq_en:1;
    };
}audio_peak_status_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcm_l_monitor:24;
        RBus_UInt32  toggle_cnt:8;
    };
}audio_peak_status_l_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ovf_th_r:16;
        RBus_UInt32  opt_th_r:16;
    };
}audio_peak_contorl_r_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vpp_eval_cnt_r:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  nonopt_cnt_tr_r:3;
        RBus_UInt32  dummy180061c4_31_19:13;
    };
}audio_peak_contorl_r_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  magnitude_r:16;
        RBus_UInt32  pk_adj_r:6;
        RBus_UInt32  overflow_r:1;
        RBus_UInt32  optimize_r:1;
        RBus_UInt32  res1:6;
        RBus_UInt32  overflow_r_irq_en:1;
        RBus_UInt32  optimize_r_irq_en:1;
    };
}audio_peak_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcm_r_monitor:24;
        RBus_UInt32  res1:8;
    };
}audio_peak_status_r_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_scan_freq:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  sound_select:2;
        RBus_UInt32  calc_time_sel:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  dkl_priority:1;
        RBus_UInt32  mn_priority:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  reg_scan_cnt:8;
        RBus_UInt32  msd_debounce_cnt:3;
        RBus_UInt32  msd_reset_n:1;
        RBus_UInt32  carrier_phase_delta:3;
        RBus_UInt32  carrier_shift_scan_en:1;
        RBus_UInt32  update_en:1;
        RBus_UInt32  msd_en:1;
        RBus_UInt32  res4:2;
    };
}audio_msd_crtl_word_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_std:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  hw_detected_std:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  h_dv_th_sel:1;
        RBus_UInt32  flag_subtomain:1;
        RBus_UInt32  flag_unnormal:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  case_subtomain:4;
        RBus_UInt32  deviation_unnormal:2;
        RBus_UInt32  res4:6;
    };
}audio_msd_result_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  deviation:4;
        RBus_UInt32  main_cari_idx:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  shift_value:4;
        RBus_UInt32  res2:4;
        RBus_UInt32  bw_cnt_min:5;
        RBus_UInt32  res3:3;
        RBus_UInt32  bw_cnt_max:5;
        RBus_UInt32  res4:3;
    };
}audio_msd_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_thresh_low:16;
        RBus_UInt32  main_thresh:16;
    };
}audio_main_tone_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_thresh_hd_low:16;
        RBus_UInt32  main_thresh_hd:16;
    };
}audio_main_tone_threshold_hd_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bw_dev_thresh:16;
        RBus_UInt32  bw_dev_thresh_hd:16;
    };
}audio_bw_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  main_sub_ratio:16;
        RBus_UInt32  bw_dev_thresh_low:16;
    };
}audio_main_sub_ratio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_4_5:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_4_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_4_28:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_4_28_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_4_72:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_4_72_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_5_5:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_5_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_5_25:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_5_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_5_74:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_5_74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_5_85:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_carrier_5_85_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_5_95:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_carrier_5_95_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_6:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_6_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_6_25:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_6_25_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_6_5:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_carrier_6_5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_6_552:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_mag_6_552_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_6_74:16;
        RBus_UInt32  res1:16;
    };
}audio_msd_carrier_6_74_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  flag_6_74:1;
        RBus_UInt32  flag_6_552:1;
        RBus_UInt32  flag_6_25:1;
        RBus_UInt32  flag_5_85:1;
        RBus_UInt32  flag_5_74:1;
        RBus_UInt32  flag_4_72:1;
        RBus_UInt32  flag_6_5:1;
        RBus_UInt32  flag_6:1;
        RBus_UInt32  flag_5_5:1;
        RBus_UInt32  flag_4_5:1;
        RBus_UInt32  flag_fw:1;
        RBus_UInt32  flag_fw_1:1;
        RBus_UInt32  flag_fw_2:1;
        RBus_UInt32  flag_fw_3:1;
        RBus_UInt32  flag_fw_4:1;
        RBus_UInt32  res1:17;
    };
}audio_msd_flags_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_fw:16;
        RBus_UInt32  fw_phase_delta:14;
        RBus_UInt32  res1:2;
    };
}audio_msd_programmable_freq_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_low:16;
        RBus_UInt32  fw_thresh:16;
    };
}audio_threshold_msd_carrier_fw_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_fw_1:16;
        RBus_UInt32  fw_phase_delta_1:14;
        RBus_UInt32  res1:2;
    };
}audio_msd_programmable_freq_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_1_low:16;
        RBus_UInt32  fw_thresh_1:16;
    };
}audio_threshold_msd_carrier_fw_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_fw_2:16;
        RBus_UInt32  fw_phase_delta_2:14;
        RBus_UInt32  res1:2;
    };
}audio_msd_programmable_freq_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_2_low:16;
        RBus_UInt32  fw_thresh_2:16;
    };
}audio_threshold_msd_carrier_fw_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_fw_3:16;
        RBus_UInt32  fw_phase_delta_3:14;
        RBus_UInt32  res1:2;
    };
}audio_msd_programmable_freq_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_3_low:16;
        RBus_UInt32  fw_thresh_3:16;
    };
}audio_threshold_msd_carrier_fw_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_fw_4:16;
        RBus_UInt32  fw_phase_delta_4:14;
        RBus_UInt32  res1:2;
    };
}audio_msd_programmable_freq_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fw_thresh_4_low:16;
        RBus_UInt32  fw_thresh_4:16;
    };
}audio_threshold_msd_carrier_fw_4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  second_reg_std:5;
        RBus_UInt32  res1:3;
        RBus_UInt32  mono_std_sel:1;
        RBus_UInt32  reg_bw_detect_en:1;
        RBus_UInt32  reg_cari_sft_detect_en:1;
        RBus_UInt32  res2:21;
    };
}audio_msd_second_reg_std_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sec_thresh_low:16;
        RBus_UInt32  sec_thresh:16;
    };
}audio_second_main_tone_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  res1:27;
    };
}audio_msd_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_55_fix:16;
        RBus_UInt32  reg_mag_45_fix:16;
    };
}audio_msd_main_mag_ori1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_mag_65_fix:16;
        RBus_UInt32  reg_mag_60_fix:16;
    };
}audio_msd_main_mag_ori2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msd_gain_result:4;
        RBus_UInt32  msd_gain_en:1;
        RBus_UInt32  res1:27;
    };
}audio_msd_gain_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  msd_update_count:16;
        RBus_UInt32  fw_update_count:16;
    };
}audio_msd_update_count_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  mode_result:2;
        RBus_UInt32  hw_mode_en:1;
        RBus_UInt32  res1:13;
        RBus_UInt32  md_update_count:16;
    };
}audio_mode_detect_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_threshold:24;
        RBus_UInt32  auto_gain_ctrl_en:1;
        RBus_UInt32  auto_pre_gain_ctrl_en:1;
        RBus_UInt32  low_threshold:2;
        RBus_UInt32  high_threshold:2;
        RBus_UInt32  bpf_sel:1;
        RBus_UInt32  enable:1;
    };
}audio_md_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_other:24;
        RBus_UInt32  gain_result:4;
        RBus_UInt32  gain_result_pre:4;
    };
}audio_md_status_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_dual:24;
        RBus_UInt32  mode_result:2;
        RBus_UInt32  lpf_coef_sel_lock:2;
        RBus_UInt32  lpf_coef_sel:2;
        RBus_UInt32  res1:2;
    };
}audio_md_status_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  max_stereo:24;
        RBus_UInt32  debounce_time:3;
        RBus_UInt32  dummy1800631c_31_27:5;
    };
}audio_md_status_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pre_gain_win:16;
        RBus_UInt32  gain_win:16;
    };
}audio_md_gain_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  md_limit_thre:24;
        RBus_UInt32  res1:8;
    };
}audio_md_limit_thre_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_3rd_delta:14;
        RBus_UInt32  res1:10;
        RBus_UInt32  freq_manual_en:1;
        RBus_UInt32  force_a2_dk_sel:2;
        RBus_UInt32  tone_det_en:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  nicam_play_ana_sel:1;
        RBus_UInt32  sif_data_source:1;
    };
}audio_carrier_freq_deviation_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sub_phase_delta:14;
        RBus_UInt32  res1:2;
        RBus_UInt32  main_phase_delta:14;
        RBus_UInt32  res2:2;
    };
}audio_carrier_phase_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006358_15_0:16;
        RBus_UInt32  fm_magnitude:16;
    };
}audio_a2_eiaj_dc_filter_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_ctrl_tvd:10;
        RBus_UInt32  ramp_step_mute_tvd:2;
        RBus_UInt32  zcto_mute_tvd:3;
        RBus_UInt32  dvcm_tvd:2;
        RBus_UInt32  zcth_tvd:5;
        RBus_UInt32  zcto_status_tvd:1;
        RBus_UInt32  switch_status_tvd:2;
        RBus_UInt32  force_mute_tvd:1;
        RBus_UInt32  mode_sel_tvd:1;
        RBus_UInt32  dvol_enable_tvd:1;
        RBus_UInt32  dvol_apply_tvd:1;
        RBus_UInt32  res1:3;
    };
}audio_tvdemod_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_ctrl_mute_tvd:10;
        RBus_UInt32  vol_b_tvd:6;
        RBus_UInt32  delay_ctrl_unmute_tvd:10;
        RBus_UInt32  vol_a_tvd:5;
        RBus_UInt32  res1:1;
    };
}audio_tvdemod_digital_volume_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_bp1_a2:16;
        RBus_UInt32  eq_tvd_bp1_a1:16;
    };
}audio_eq_tvd_bp1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_bp1_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_tvd_bp1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_bp2_a2:16;
        RBus_UInt32  eq_tvd_bp2_a1:16;
    };
}audio_eq_tvd_bp2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_bp2_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_tvd_bp2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_band1_enable:1;
        RBus_UInt32  eq_tvd_band2_enable:1;
        RBus_UInt32  eq_tvd_lp_enable:1;
        RBus_UInt32  eq_tvd_deq_enable:1;
        RBus_UInt32  eq_tvd_ovf:1;
        RBus_UInt32  res1:27;
    };
}audio_eq_tvd_bp_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_band1_of:1;
        RBus_UInt32  eq_tvd_band2_of:1;
        RBus_UInt32  eq_tvd_lp_of:1;
        RBus_UInt32  res1:29;
    };
}audio_eq_tvd_bp_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_tvd_lp_h0:16;
        RBus_UInt32  eq_tvd_lp_a1:16;
    };
}audio_eq_tvd_lp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  hw_am_prescale:2;
        RBus_UInt32  am_path_sel:1;
        RBus_UInt32  am_bpf_bw:1;
        RBus_UInt32  dummy18006360_7_4:4;
        RBus_UInt32  res1:24;
    };
}audio_am_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  res1:27;
    };
}audio_bist_am_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage1_b1:16;
        RBus_UInt32  sap_bpf_stage1_b0:16;
    };
}audio_sap_bpf_stage1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage1_b2:16;
        RBus_UInt32  res1:16;
    };
}audio_sap_bpf_stage1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage1_a2:16;
        RBus_UInt32  sap_bpf_stage1_a1:16;
    };
}audio_sap_bpf_stage1_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage2_b1:16;
        RBus_UInt32  sap_bpf_stage2_b0:16;
    };
}audio_sap_bpf_stage2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage2_b2:16;
        RBus_UInt32  res1:16;
    };
}audio_sap_bpf_stage2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage2_a2:16;
        RBus_UInt32  sap_bpf_stage2_a1:16;
    };
}audio_sap_bpf_stage2_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage3_b1:16;
        RBus_UInt32  sap_bpf_stage3_b0:16;
    };
}audio_sap_bpf_stage3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage3_b2:16;
        RBus_UInt32  res1:16;
    };
}audio_sap_bpf_stage3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_bpf_stage3_a2:16;
        RBus_UInt32  sap_bpf_stage3_a1:16;
    };
}audio_sap_bpf_stage3_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pilot_lothresh:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  pilot_hithresh:10;
        RBus_UInt32  bypass_com_bpf:1;
        RBus_UInt32  bypass_com_hpf:1;
        RBus_UInt32  fm_radio_deem_bypass:1;
        RBus_UInt32  fm_radio_deem_sel:1;
        RBus_UInt32  fm_radio_en:1;
        RBus_UInt32  lock_reference:1;
    };
}audio_btsc_pilot_thres_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w10pilotmagnitude:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  pilot_lo_refuse:1;
        RBus_UInt32  pilot_hi_pass:1;
        RBus_UInt32  pilot_level_pass:1;
        RBus_UInt32  w1pilotlocked:1;
        RBus_UInt32  w1pilotpresent:1;
        RBus_UInt32  out_hpf_en:1;
        RBus_UInt32  pilot_lock_reset:1;
        RBus_UInt32  res2:13;
    };
}audio_btsc_pilot_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_lothresh:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  sap_hithresh:10;
        RBus_UInt32  res2:6;
    };
}audio_btsc_sap_thresh_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_noise_lo_thresh:10;
        RBus_UInt32  res1:6;
        RBus_UInt32  sap_noise_hi_thresh:10;
        RBus_UInt32  res2:6;
    };
}audio_btsc_sap_noise_th_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w10sapnoise:10;
        RBus_UInt32  res1:22;
    };
}audio_btsc_sap_noise_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w10sapmagnitude:10;
        RBus_UInt32  sap_compen_en:1;
        RBus_UInt32  sap_noise_flag:1;
        RBus_UInt32  sap_lo_refuse:1;
        RBus_UInt32  sap_hi_pass:1;
        RBus_UInt32  w1sapqualitygood:1;
        RBus_UInt32  res1:17;
    };
}audio_btsc_sap_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sap_debounce:4;
        RBus_UInt32  sap_debounce_en:1;
        RBus_UInt32  res1:27;
    };
}audio_btsc_sap_debounce_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  w10fmmagnitude:10;
        RBus_UInt32  res1:2;
        RBus_UInt32  fm_mag_optimize:1;
        RBus_UInt32  fm_mag_overflow:1;
        RBus_UInt32  res2:18;
    };
}audio_btsc_sif_fm_magnitude_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  testoutputselect:4;
        RBus_UInt32  res1:28;
    };
}audio_btsc_test_mux_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy_6424:16;
        RBus_UInt32  res1:16;
    };
}audio_btsc_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pilot_phase_delta:32;
    };
}audio_btsc_pilot_phase_delta_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  locked_i_gain:4;
        RBus_UInt32  locked_p_gain:4;
        RBus_UInt32  unlock_i_gain:4;
        RBus_UInt32  unlock_p_gain:4;
        RBus_UInt32  res1:16;
    };
}audio_phase_error_pi_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_err_threshold:24;
        RBus_UInt32  res1:5;
        RBus_UInt32  stereo_lpf_sel:1;
        RBus_UInt32  mono_lpf_sel:1;
        RBus_UInt32  sap_hpf_en:1;
    };
}audio_phase_err_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  phase_err_high_threshold:24;
        RBus_UInt32  res1:8;
    };
}audio_phase_err_threshold2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  freq_correction:22;
        RBus_UInt32  res1:10;
    };
}audio_freq_correction_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  average_movement:24;
        RBus_UInt32  res1:8;
    };
}audio_phase_error_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  fm2_deviation_gain:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  fm1_deviation_gain:3;
        RBus_UInt32  res3:1;
        RBus_UInt32  a2_sub_bw_sel:2;
        RBus_UInt32  res4:10;
        RBus_UInt32  down_6db:1;
        RBus_UInt32  hdv_compen_en:1;
        RBus_UInt32  res5:2;
        RBus_UInt32  de_emphasis_time:2;
        RBus_UInt32  a2_bw_sel:2;
    };
}audio_a2_eiaj_demod_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise_sub:10;
        RBus_UInt32  magnitude_sub:10;
        RBus_UInt32  res1:12;
    };
}audio_a2_eiaj_mag_noise_sub_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  noise:10;
        RBus_UInt32  magnitude:10;
        RBus_UInt32  res1:12;
    };
}audio_a2_eiaj_mag_noise_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  rm_4:4;
        RBus_UInt32  rm_5:4;
        RBus_UInt32  rm_6:4;
        RBus_UInt32  rm_7:4;
    };
}audio_mbist_a2_eiaj_demod_rm_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_8:4;
        RBus_UInt32  res1:28;
    };
}audio_mbist_a2_eiaj_demod_rm_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  rme_4:1;
        RBus_UInt32  rme_5:1;
        RBus_UInt32  rme_6:1;
        RBus_UInt32  rme_7:1;
        RBus_UInt32  rme_8:1;
        RBus_UInt32  res1:23;
    };
}audio_mbist_a2_eiaj_demod_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  tr_timing_step:20;
        RBus_UInt32  cr_lpf_ki:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  cr_lpf_kp:3;
        RBus_UInt32  psf_bg_sel:1;
        RBus_UInt32  tr_lpf_kp:3;
        RBus_UInt32  psf_sel:1;
    };
}audio_nicam_demod_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  gain_adjust:6;
        RBus_UInt32  res1:10;
        RBus_UInt32  window_size:10;
        RBus_UInt32  res2:2;
        RBus_UInt32  debounce_cnt:3;
        RBus_UInt32  enable:1;
    };
}audio_nicam_dagc_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low:16;
        RBus_UInt32  high:16;
    };
}audio_nicam_dagc_threshold_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  magnitude:16;
        RBus_UInt32  res1:16;
    };
}audio_nicam_dagc_mag_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  nicam_to_mono_clk_sel:1;
        RBus_UInt32  nicam_to_mute_clk_sel:1;
        RBus_UInt32  dummy18006510_13:12;
        RBus_UInt32  level_sel:2;
        RBus_UInt32  dummy_0:1;
        RBus_UInt32  de_em_by_pass:1;
        RBus_UInt32  sat_en:1;
        RBus_UInt32  bypass_interpol:1;
        RBus_UInt32  status_debounce_cnt:4;
        RBus_UInt32  res1:1;
        RBus_UInt32  cib_mask:1;
        RBus_UInt32  cib_0:1;
        RBus_UInt32  cib_1:1;
        RBus_UInt32  pcm_r_out_sel:1;
        RBus_UInt32  pcm_l_out_sel:1;
        RBus_UInt32  data_channel_sel:1;
        RBus_UInt32  src_out_en:1;
    };
}audio_nicam_decode_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_error_rate:12;
        RBus_UInt32  true_detect:1;
        RBus_UInt32  bit_cnt_sync:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  additional_data:11;
        RBus_UInt32  c4:1;
        RBus_UInt32  c1c2c3:3;
        RBus_UInt32  c0:1;
    };
}audio_nicam_decode_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  low_threshold:12;
        RBus_UInt32  high_threshold:12;
        RBus_UInt32  hi_ber_debounce:3;
        RBus_UInt32  analog_flag:1;
        RBus_UInt32  c4_hi_ber:2;
        RBus_UInt32  res1:1;
        RBus_UInt32  enable:1;
    };
}audio_nicam_auto_switch_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ted_error:18;
        RBus_UInt32  res1:2;
        RBus_UInt32  ted_error_threshold:3;
        RBus_UInt32  res2:5;
        RBus_UInt32  duration:2;
        RBus_UInt32  dur_rand_en:1;
        RBus_UInt32  enable:1;
    };
}audio_nicam_demod_auto_recovery_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  bit_error_rate_r:12;
        RBus_UInt32  bit_error_rate_l:12;
        RBus_UInt32  res1:8;
    };
}audio_nicam_bit_error_rate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  r_end:6;
        RBus_UInt32  r_start:6;
        RBus_UInt32  l_end:6;
        RBus_UInt32  l_start:6;
        RBus_UInt32  window_en:1;
        RBus_UInt32  res1:7;
    };
}audio_nicam_ber_window_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  res1:22;
    };
}audio_nicam_src_mbist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  down_rate:1;
        RBus_UInt32  downsample_en:1;
        RBus_UInt32  backend_play_en:1;
        RBus_UInt32  output_hold_zero:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  fifo_ch0_source:2;
        RBus_UInt32  fifo_ch1_source:2;
        RBus_UInt32  res2:12;
    };
}audio_down_sample_control_for_playback_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  fifo_ch01_sel:4;
        RBus_UInt32  res1:28;
    };
}audio_down_sample_fifo_source_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:14;
        RBus_UInt32  dummy18006558_31_14:18;
    };
}audio_down_sample_mbist_recoding_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}audio_down_sample_fifo_pre_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  res1:16;
    };
}audio_down_sample_mbist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  res1:28;
    };
}audio_down_sample_mbist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  down_rate:1;
        RBus_UInt32  downsample_en:1;
        RBus_UInt32  backend_play_en:1;
        RBus_UInt32  output_hold_zero:1;
        RBus_UInt32  res1:8;
        RBus_UInt32  fifo_ch01_sel:4;
        RBus_UInt32  fifo_ch1_source:2;
        RBus_UInt32  fifo_ch0_source:2;
        RBus_UInt32  res2:12;
    };
}audio_down_sample_control_for_ts_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rm_1:4;
        RBus_UInt32  rm_2:4;
        RBus_UInt32  rm_3:4;
        RBus_UInt32  dummy180065a4_31_16:16;
    };
}audio_ts_ds_fifo_mbist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rme_0:1;
        RBus_UInt32  rme_1:1;
        RBus_UInt32  rme_2:1;
        RBus_UInt32  rme_3:1;
        RBus_UInt32  res1:28;
    };
}audio_ts_ds_fifo_mbist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_intr_dma_status:1;
        RBus_UInt32  wr_intr_dma_status:1;
        RBus_UInt32  unflow_dma_status:1;
        RBus_UInt32  overflow_dma_status:1;
        RBus_UInt32  dma_write_enable:1;
        RBus_UInt32  dma_read_enable:1;
        RBus_UInt32  dma_soft_wr_rst:1;
        RBus_UInt32  dma_soft_rd_rst:1;
        RBus_UInt32  dma_int_en:1;
        RBus_UInt32  int_wr_en:1;
        RBus_UInt32  int_rd_en:1;
        RBus_UInt32  dma_mode:1;
        RBus_UInt32  aodmatype:1;
        RBus_UInt32  rd_channel_no:3;
        RBus_UInt32  aidmatype:1;
        RBus_UInt32  wr_channel_no:3;
        RBus_UInt32  hbr_wr_channel_no:2;
        RBus_UInt32  pcm_random:1;
        RBus_UInt32  output_hold_en:1;
        RBus_UInt32  dma_src_pre_fifo_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  dma_r_format:1;
        RBus_UInt32  dma_w_format:1;
        RBus_UInt32  dma_output_src_sel:2;
        RBus_UInt32  dma_wr_src_sel:2;
    };
}audio_adma_csr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  wr_intr_point:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  write_len:15;
        RBus_UInt32  res2:1;
    };
}audio_adma_wconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  wr_start_addr0:26;
    };
}audio_adma_wsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  wr_start_addr1:26;
    };
}audio_adma_wsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_intr_point:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  read_len:15;
        RBus_UInt32  res2:1;
    };
}audio_adma_rconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  read_length:15;
        RBus_UInt32  load_rd:1;
        RBus_UInt32  avail_length:15;
        RBus_UInt32  load_wr:1;
    };
}audio_adma_wrconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rd_start_addr0:26;
    };
}audio_adma_rsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rd_start_addr1:26;
    };
}audio_adma_rsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rd_start_addr2:26;
    };
}audio_adma_rsadr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rd_start_addr3:26;
    };
}audio_adma_rsadr3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rd_start_addr4:26;
    };
}audio_adma_rsadr4_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  rd_start_addr5:26;
    };
}audio_adma_rsadr5_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rd_buffer_length:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  wr_buffer_length:15;
        RBus_UInt32  res2:1;
    };
}audio_adma_chconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0:4;
        RBus_UInt32  rme_0:1;
        RBus_UInt32  ls_on:1;
        RBus_UInt32  res1:26;
    };
}audio_audio_dma_bist_control_indicate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arc_rd_intr_dma_status:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  arc_unflow_dma_status:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  arc_dma_read_enable:1;
        RBus_UInt32  res3:1;
        RBus_UInt32  arc_dma_soft_rd_rst:1;
        RBus_UInt32  arc_dma_int_en:1;
        RBus_UInt32  res4:1;
        RBus_UInt32  arc_int_rd_en:1;
        RBus_UInt32  res5:1;
        RBus_UInt32  arc_aodmatype:1;
        RBus_UInt32  arc_rd_channel_no:3;
        RBus_UInt32  res6:7;
        RBus_UInt32  arc_output_hold_en:1;
        RBus_UInt32  res7:2;
        RBus_UInt32  arc_dma_r_format:1;
        RBus_UInt32  res8:1;
        RBus_UInt32  arc_dma_output_src_sel:2;
        RBus_UInt32  res9:2;
    };
}audio_arc_adma_csr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arc_read_intr_point:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  arc_read_len:15;
        RBus_UInt32  res2:1;
    };
}audio_arc_adma_rconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arc_read_length:15;
        RBus_UInt32  arc_load_rd:1;
        RBus_UInt32  res1:16;
    };
}audio_arc_adma_wrconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  arc_rd_start_addr0:26;
    };
}audio_arc_adma_rsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  arc_rd_start_addr1:26;
    };
}audio_arc_adma_rsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  arc_rd_buffer_length:15;
        RBus_UInt32  res1:17;
    };
}audio_arc_adma_chconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0_arc:4;
        RBus_UInt32  rme_0_arc:1;
        RBus_UInt32  arc_ls_on:1;
        RBus_UInt32  res1:26;
    };
}audio_arc_dma_bist_control_indicate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_rd_intr_dma_status:1;
        RBus_UInt32  ts_wr_intr_dma_status:1;
        RBus_UInt32  ts_unflow_dma_status:1;
        RBus_UInt32  ts_overflow_dma_status:1;
        RBus_UInt32  ts_dma_write_enable:1;
        RBus_UInt32  ts_dma_read_enable:1;
        RBus_UInt32  ts_dma_soft_wr_rst:1;
        RBus_UInt32  ts_dma_soft_rd_rst:1;
        RBus_UInt32  ts_dma_int_en:1;
        RBus_UInt32  ts_int_wr_en:1;
        RBus_UInt32  ts_int_rd_en:1;
        RBus_UInt32  ts_dma_mode:1;
        RBus_UInt32  ts_aodmatype:1;
        RBus_UInt32  ts_rd_channel_no:3;
        RBus_UInt32  ts_aidmatype:1;
        RBus_UInt32  ts_wr_channel_no:3;
        RBus_UInt32  ts_hbr_wr_channel_no:2;
        RBus_UInt32  ts_pcm_random:1;
        RBus_UInt32  ts_output_hold_en:1;
        RBus_UInt32  ts_dma_src_pre_fifo_en:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_dma_r_format:1;
        RBus_UInt32  ts_dma_w_format:1;
        RBus_UInt32  ts_dma_output_src_sel:2;
        RBus_UInt32  ts_dma_wr_src_sel:2;
    };
}audio_tsadma_csr_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_wr_intr_point:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_write_len:15;
        RBus_UInt32  res2:1;
    };
}audio_ts_adma_wconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ts_wr_start_addr0:26;
    };
}audio_ts_adma_wsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ts_wr_start_addr1:26;
    };
}audio_ts_adma_wsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_read_intr_point:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_read_len:15;
        RBus_UInt32  res2:1;
    };
}audio_ts_adma_rconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_read_length:15;
        RBus_UInt32  ts_load_rd:1;
        RBus_UInt32  ts_avail_length:15;
        RBus_UInt32  ts_load_wr:1;
    };
}audio_ts_adma_wrconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ts_rd_start_addr0:26;
    };
}audio_ts_adma_rsadr0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ts_rd_start_addr1:26;
    };
}audio_ts_adma_rsadr1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  ts_rd_start_addr2:26;
    };
}audio_ts_adma_rsadr2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ts_rd_buffer_length:15;
        RBus_UInt32  res1:1;
        RBus_UInt32  ts_wr_buffer_length:15;
        RBus_UInt32  res2:1;
    };
}audio_ts_adma_chconf_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0_ts:4;
        RBus_UInt32  rme_0_ts:1;
        RBus_UInt32  ts_ls_on:1;
        RBus_UInt32  res1:26;
    };
}audio_ts_dma_bist_control_indicate_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  test_dma_over_write:1;
        RBus_UInt32  test_dma_over_read:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  test_dma_ring:1;
        RBus_UInt32  test_dma_in_sel:3;
        RBus_UInt32  test_dma_rw_mode:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  test_dma_en:1;
        RBus_UInt32  res3:19;
    };
}audio_test_dma_control_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  test_dma_start_addr:26;
    };
}audio_test_dma_start_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  test_dma_stop_addr:26;
    };
}audio_test_dma_stop_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dma_sel:1;
        RBus_UInt32  eco_ifd_inv:1;
        RBus_UInt32  dummy180066ec_31:30;
    };
}audio_test_mode_select_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:6;
        RBus_UInt32  test_dma_cur_addr:26;
    };
}audio_test_cur_address_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  auto_volenable:1;
        RBus_UInt32  spatial_ctrlenable:1;
        RBus_UInt32  deq_enable:1;
        RBus_UInt32  loud_enable:1;
        RBus_UInt32  dvol_enable:1;
        RBus_UInt32  basic_premium_sel:1;
        RBus_UInt32  avc2_enable:1;
        RBus_UInt32  distortion_enable:1;
        RBus_UInt32  drc_lpf_enable:1;
        RBus_UInt32  drc_enable:1;
        RBus_UInt32  res1:22;
    };
}audio_hw_process_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_up_db:2;
        RBus_UInt32  avc_down_db:2;
        RBus_UInt32  avc_level_min:8;
        RBus_UInt32  avc_level_max:8;
        RBus_UInt32  avc_noise_thre:8;
        RBus_UInt32  avc_noise_gain:2;
        RBus_UInt32  avc_vol_detect:2;
    };
}audio_auto_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_mon_win:10;
        RBus_UInt32  avc_zc_win:10;
        RBus_UInt32  avc_cnt_thre:10;
        RBus_UInt32  res1:2;
    };
}audio_avc_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_small_cnt_thre:8;
        RBus_UInt32  avc_small_up_db:2;
        RBus_UInt32  avc_small_down_db:2;
        RBus_UInt32  avc_small_level_min:8;
        RBus_UInt32  avc_small_level_max:8;
        RBus_UInt32  avc1_coef:3;
        RBus_UInt32  avc_vol_amplif_enable:1;
    };
}audio_avc_volume_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_small_level:16;
        RBus_UInt32  avc_amplif_step_mag_thre:8;
        RBus_UInt32  avc_lower_step_mag_thre:8;
    };
}audio_avc_volume_control_3_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_amplif_step_cnt_hi_thre:8;
        RBus_UInt32  avc_amplif_step_cnt_low_thre:8;
        RBus_UInt32  avc_lower_step_cnt_hi_thre:8;
        RBus_UInt32  avc_lower_step_cnt_low_thre:8;
    };
}audio_avc_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_small_up_db_fine:2;
        RBus_UInt32  avc_small_down_db_fine:2;
        RBus_UInt32  avc_up_db_fine:2;
        RBus_UInt32  avc_down_db_fine:2;
        RBus_UInt32  res1:24;
    };
}audio_avc_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  f_coef:9;
        RBus_UInt32  res1:1;
        RBus_UInt32  spatial_in_r_sel:1;
        RBus_UInt32  spatial_in_l_sel:1;
        RBus_UInt32  seb_en:1;
        RBus_UInt32  psb_en:1;
        RBus_UInt32  apf_en:1;
        RBus_UInt32  spatial_zc_apply:1;
        RBus_UInt32  spatial_zc_win:12;
        RBus_UInt32  res2:4;
    };
}audio_spatial_effect_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  depth2:9;
        RBus_UInt32  res1:7;
        RBus_UInt32  depth1:9;
        RBus_UInt32  res2:7;
    };
}audio_spatial_effect_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_hp_a1:16;
        RBus_UInt32  eq_hp_slope:1;
        RBus_UInt32  res1:15;
    };
}audio_eq_hp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_lp_h0:16;
        RBus_UInt32  eq_lp_a1:16;
    };
}audio_eq_lp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp1_a2:16;
        RBus_UInt32  eq_bp1_a1:16;
    };
}audio_eq_bp1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp1_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp2_a2:16;
        RBus_UInt32  eq_bp2_a1:16;
    };
}audio_eq_bp2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp2_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp3_a2:16;
        RBus_UInt32  eq_bp3_a1:16;
    };
}audio_eq_bp3_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp3_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp3_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp4_a2:16;
        RBus_UInt32  eq_bp4_a1:16;
    };
}audio_eq_bp4_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp4_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp4_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp5_a2:16;
        RBus_UInt32  eq_bp5_a1:16;
    };
}audio_eq_bp5_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp5_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp5_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp6_a2:16;
        RBus_UInt32  eq_bp6_a1:16;
    };
}audio_eq_bp6_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp6_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp6_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp7_a2:16;
        RBus_UInt32  eq_bp7_a1:16;
    };
}audio_eq_bp7_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_bp7_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_eq_bp7_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_hp_enable:1;
        RBus_UInt32  eq_lp_enable:1;
        RBus_UInt32  eq_band1_enable:1;
        RBus_UInt32  eq_band2_enable:1;
        RBus_UInt32  eq_band3_enable:1;
        RBus_UInt32  eq_band4_enable:1;
        RBus_UInt32  eq_band5_enable:1;
        RBus_UInt32  eq_band6_enable:1;
        RBus_UInt32  eq_band7_enable:1;
        RBus_UInt32  res1:23;
    };
}audio_eq_control_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  eq_hp_of:1;
        RBus_UInt32  eq_lp_of:1;
        RBus_UInt32  eq_band1_of:1;
        RBus_UInt32  eq_band2_of:1;
        RBus_UInt32  eq_band3_of:1;
        RBus_UInt32  eq_band4_of:1;
        RBus_UInt32  eq_band5_of:1;
        RBus_UInt32  eq_band6_of:1;
        RBus_UInt32  eq_band7_of:1;
        RBus_UInt32  res1:23;
    };
}audio_eq_status_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_lp0_h0:16;
        RBus_UInt32  lr_loud_lp0_a1:16;
    };
}audio_lr_loud_lp_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_bp1_a2:16;
        RBus_UInt32  lr_loud_bp1_a1:16;
    };
}audio_lr_loud_bp1_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_bp1_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_lr_loud_bp1_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_bp2_a2:16;
        RBus_UInt32  lr_loud_bp2_a1:16;
    };
}audio_lr_loud_bp2_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lr_loud_bp2_h0:16;
        RBus_UInt32  res1:16;
    };
}audio_lr_loud_bp2_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_bpf2_en_lr:1;
        RBus_UInt32  ld_bpf1_en_lr:1;
        RBus_UInt32  ld_lpf_en_lr:1;
        RBus_UInt32  res1:29;
    };
}audio_loudness_control_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ld_bpf2_of_lr:1;
        RBus_UInt32  ld_bpf1_of_lr:1;
        RBus_UInt32  ld_lpf_of_lr:1;
        RBus_UInt32  res1:29;
    };
}audio_loudness_status_register_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvcm:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  zcth:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_zero_in_en:1;
        RBus_UInt32  reg_in_thre:5;
        RBus_UInt32  res3:14;
    };
}audio_digital_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_ctrl_mute:10;
        RBus_UInt32  ramp_step_mute:2;
        RBus_UInt32  zcto_mute:3;
        RBus_UInt32  mute_apply:1;
        RBus_UInt32  delay_ctrl:10;
        RBus_UInt32  ramp_step:2;
        RBus_UInt32  zcto:3;
        RBus_UInt32  dvol_apply:1;
    };
}audio_digital_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_r_b:6;
        RBus_UInt32  vol_r_a:5;
        RBus_UInt32  vol_r_ready:1;
        RBus_UInt32  hpf_r_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rep_r_status:1;
        RBus_UInt32  mute_r:1;
        RBus_UInt32  vol_l_b:6;
        RBus_UInt32  vol_l_a:5;
        RBus_UInt32  vol_l_ready:1;
        RBus_UInt32  hpf_l_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rep_l_status:1;
        RBus_UInt32  mute_l:1;
    };
}audio_lr_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_rs_b:6;
        RBus_UInt32  vol_rs_a:5;
        RBus_UInt32  vol_rs_ready:1;
        RBus_UInt32  hpf_rs_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rep_rs_status:1;
        RBus_UInt32  mute_rs:1;
        RBus_UInt32  vol_ls_b:6;
        RBus_UInt32  vol_ls_a:5;
        RBus_UInt32  vol_ls_ready:1;
        RBus_UInt32  hpf_ls_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rep_ls_status:1;
        RBus_UInt32  mute_ls:1;
    };
}audio_lsrs_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_sw_b:6;
        RBus_UInt32  vol_sw_a:5;
        RBus_UInt32  vol_sw_ready:1;
        RBus_UInt32  hpf_sw_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rep_sw_status:1;
        RBus_UInt32  mute_sw:1;
        RBus_UInt32  vol_c_b:6;
        RBus_UInt32  vol_c_a:5;
        RBus_UInt32  vol_c_ready:1;
        RBus_UInt32  hpf_c_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rep_c_status:1;
        RBus_UInt32  mute_c:1;
    };
}audio_csw_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  double_buffer_ack:1;
        RBus_UInt32  zcto_status:1;
        RBus_UInt32  res1:30;
    };
}audio_double_buffer_ack_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_noise_thre:16;
        RBus_UInt32  avc2_noise_gain:2;
        RBus_UInt32  down_db:2;
        RBus_UInt32  fast_up_db:2;
        RBus_UInt32  slow_up_db:2;
        RBus_UInt32  fast_recov_ctrl:1;
        RBus_UInt32  avc2_vol_detect:2;
        RBus_UInt32  avc2_lpf_coef:3;
        RBus_UInt32  avc2_vol_amplif_enable:1;
        RBus_UInt32  res1:1;
    };
}audio_avc2_control_1_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_mon_win:10;
        RBus_UInt32  avc2_zc_win:10;
        RBus_UInt32  avc2_cnt_thre:10;
        RBus_UInt32  res1:2;
    };
}audio_avc2_control_2_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  recov_win_min:8;
        RBus_UInt32  recov_win_max:8;
        RBus_UInt32  avc2_noise_thre_hi:16;
    };
}audio_avc2_control_3_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_level_min:16;
        RBus_UInt32  avc2_level_max:16;
    };
}audio_avc2_control_4_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_small_cnt_thre:8;
        RBus_UInt32  avc2_small_down_db:2;
        RBus_UInt32  avc2_small_up_db:2;
        RBus_UInt32  avc2_small_down_db_fine:2;
        RBus_UInt32  avc2_small_up_db_fine:2;
        RBus_UInt32  down_db_fine:2;
        RBus_UInt32  fast_up_db_fine:2;
        RBus_UInt32  slow_up_db_fine:2;
        RBus_UInt32  res1:10;
    };
}audio_avc2_control_5_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_small_level_min:16;
        RBus_UInt32  avc2_small_level_max:16;
    };
}audio_avc2_control_6_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_small_level:31;
        RBus_UInt32  res1:1;
    };
}audio_avc2_control_7_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_lower_step_cnt_hi_thre:8;
        RBus_UInt32  avc2_lower_step_cnt_low_thre:8;
        RBus_UInt32  avc2_lower_step_mag_thre:16;
    };
}audio_avc2_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_amplif_step_cnt_hi_thre:8;
        RBus_UInt32  avc2_amplif_step_cnt_low_thre:8;
        RBus_UInt32  avc2_amplif_step_mag_thre:16;
    };
}audio_avc2_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:4;
        RBus_UInt32  hw_mixing_sel:2;
        RBus_UInt32  res2:26;
    };
}audio_hw_out_trans_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  loudness_ovf:1;
        RBus_UInt32  eq_ovf:1;
        RBus_UInt32  dvol_done:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  dvol_int_en:1;
        RBus_UInt32  loudness_ovf_en:1;
        RBus_UInt32  eq_ovf_en:1;
        RBus_UInt32  res2:14;
    };
}audio_system_int_en_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc_lp_out:24;
        RBus_UInt32  res1:8;
    };
}audio_avc_lp_out_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006818_31_0:32;
    };
}audio_dummy_6718_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800681c_31_0:32;
    };
}audio_dummy_671c_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ch01_scale_b:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  ch01_scale_a:4;
        RBus_UInt32  res2:24;
    };
}audio_hw_in_pre_scale_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dist_up_db:2;
        RBus_UInt32  dist_up_db_fine:2;
        RBus_UInt32  dist_low_thre:8;
        RBus_UInt32  dist_high_thre:8;
        RBus_UInt32  dist_coef:3;
        RBus_UInt32  res1:1;
        RBus_UInt32  dist_down_db:2;
        RBus_UInt32  dist_down_db_fine:2;
        RBus_UInt32  res2:2;
        RBus_UInt32  dist_vol_detect:2;
    };
}audio_hw_distortion_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dist_mon_win:10;
        RBus_UInt32  dist_zc_win:10;
        RBus_UInt32  dist_cnt_thre:10;
        RBus_UInt32  res1:2;
    };
}audio_hw_distortion_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_hi_threshold:16;
        RBus_UInt32  avc2_detect_samples:15;
        RBus_UInt32  avc2_count_reset:1;
    };
}audio_avc2_distortion_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_max_energy_l:16;
        RBus_UInt32  avc2_count_l:15;
        RBus_UInt32  res1:1;
    };
}audio_avc2_distortion_status_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  avc2_max_energy_r:16;
        RBus_UInt32  avc2_count_r:15;
        RBus_UInt32  res1:1;
    };
}audio_avc2_distortion_status_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  step_cnt_low_thre:8;
        RBus_UInt32  step_cnt_high_thre:8;
        RBus_UInt32  step_mag_thre:8;
        RBus_UInt32  res1:8;
    };
}audio_hw_distortion_control_gain_step_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_noise_thre:16;
        RBus_UInt32  drc_noise_gain:2;
        RBus_UInt32  drc_down_db:2;
        RBus_UInt32  drc_fast_up_db:2;
        RBus_UInt32  drc_slow_up_db:2;
        RBus_UInt32  drc_fast_recov_ctrl:1;
        RBus_UInt32  drc_vol_detect:2;
        RBus_UInt32  drc_lpf_coef:3;
        RBus_UInt32  drc_vol_amplif_enable:1;
        RBus_UInt32  res1:1;
    };
}audio_drc_control_1_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_mon_win:10;
        RBus_UInt32  drc_zc_win:10;
        RBus_UInt32  drc_cnt_thre:10;
        RBus_UInt32  res1:2;
    };
}audio_drc_control_2_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_recov_win_min:8;
        RBus_UInt32  drc_recov_win_max:8;
        RBus_UInt32  drc_noise_thre_hi:16;
    };
}audio_drc_control_3_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_level_min:16;
        RBus_UInt32  drc_level_max:16;
    };
}audio_drc_control_4_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_small_cnt_thre:8;
        RBus_UInt32  drc_small_down_db:2;
        RBus_UInt32  drc_small_up_db:2;
        RBus_UInt32  drc_small_down_db_fine:2;
        RBus_UInt32  drc_small_up_db_fine:2;
        RBus_UInt32  drc_down_db_fine:2;
        RBus_UInt32  drc_fast_up_db_fine:2;
        RBus_UInt32  drc_slow_up_db_fine:2;
        RBus_UInt32  res1:10;
    };
}audio_drc_control_5_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_small_level_min:16;
        RBus_UInt32  drc_small_level_max:16;
    };
}audio_drc_control_6_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_small_level:31;
        RBus_UInt32  res1:1;
    };
}audio_drc_control_7_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lower_step_cnt_hi_thre:8;
        RBus_UInt32  drc_lower_step_cnt_low_thre:8;
        RBus_UInt32  drc_lower_step_mag_thre:16;
    };
}audio_drc_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_amplif_step_cnt_hi_thre:8;
        RBus_UInt32  drc_amplif_step_cnt_low_thre:8;
        RBus_UInt32  drc_amplif_step_mag_thre:16;
    };
}audio_drc_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_noise_thre:16;
        RBus_UInt32  drc_lpf_noise_gain:2;
        RBus_UInt32  drc_lpf_down_db:2;
        RBus_UInt32  drc_lpf_fast_up_db:2;
        RBus_UInt32  drc_lpf_slow_up_db:2;
        RBus_UInt32  drc_lpf_fast_recov_ctrl:1;
        RBus_UInt32  drc_lpf_vol_detect:2;
        RBus_UInt32  drc_lpf_lpf_coef:3;
        RBus_UInt32  drc_lpf_vol_amplif_enable:1;
        RBus_UInt32  res1:1;
    };
}audio_drc_lpf_control_1_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_mon_win:10;
        RBus_UInt32  drc_lpf_zc_win:10;
        RBus_UInt32  drc_lpf_cnt_thre:10;
        RBus_UInt32  res1:2;
    };
}audio_drc_lpf_control_2_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_recov_win_min:8;
        RBus_UInt32  drc_lpf_recov_win_max:8;
        RBus_UInt32  drc_lpf_noise_thre_hi:16;
    };
}audio_drc_lpf_control_3_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_level_min:16;
        RBus_UInt32  drc_lpf_level_max:16;
    };
}audio_drc_lpf_control_4_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_small_cnt_thre:8;
        RBus_UInt32  drc_lpf_small_down_db:2;
        RBus_UInt32  drc_lpf_small_up_db:2;
        RBus_UInt32  drc_lpf_small_down_db_fine:2;
        RBus_UInt32  drc_lpf_small_up_db_fine:2;
        RBus_UInt32  drc_lpf_down_db_fine:2;
        RBus_UInt32  drc_lpf_fast_up_db_fine:2;
        RBus_UInt32  drc_lpf_slow_up_db_fine:2;
        RBus_UInt32  res1:10;
    };
}audio_drc_lpf_control_5_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_small_level_min:16;
        RBus_UInt32  drc_lpf_small_level_max:16;
    };
}audio_drc_lpf_control_6_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_small_level:31;
        RBus_UInt32  res1:1;
    };
}audio_drc_lpf_control_7_ch01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_lower_step_cnt_hi_thre:8;
        RBus_UInt32  drc_lpf_lower_step_cnt_low_thre:8;
        RBus_UInt32  drc_lpf_lower_step_mag_thre:16;
    };
}audio_drc_lpf_gain_step_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_lpf_amplif_step_cnt_hi_thre:8;
        RBus_UInt32  drc_lpf_amplif_step_cnt_low_thre:8;
        RBus_UInt32  drc_lpf_amplif_step_mag_thre:16;
    };
}audio_drc_lpf_gain_step_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_rm_0:4;
        RBus_UInt32  drc_rm_1:4;
        RBus_UInt32  drc_rm_2:4;
        RBus_UInt32  drc_rm_3:4;
        RBus_UInt32  res1:16;
    };
}audio_drc_mbist_rm_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  drc_rme_0:1;
        RBus_UInt32  drc_rme_1:1;
        RBus_UInt32  drc_rme_2:1;
        RBus_UInt32  drc_rme_3:1;
        RBus_UInt32  res1:28;
    };
}audio_drc_mbist_rme_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lrrr_delay_ctrl_mute:10;
        RBus_UInt32  lrrr_ramp_step_mute:2;
        RBus_UInt32  lrrr_zcto_mute:3;
        RBus_UInt32  lrrr_mute_apply:1;
        RBus_UInt32  lrrr_delay_ctrl:10;
        RBus_UInt32  lrrr_ramp_step:2;
        RBus_UInt32  lrrr_zcto:3;
        RBus_UInt32  lrrr_dvol_apply:1;
    };
}audio_lrrr_digital_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  lrrr_dvcm:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  lrrr_zcth:5;
        RBus_UInt32  lrrr_zcto_status:1;
        RBus_UInt32  lrrr_dvol_enable:1;
        RBus_UInt32  res2:21;
    };
}audio_lrrr_digital_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_rr_b:6;
        RBus_UInt32  vol_rr_a:5;
        RBus_UInt32  vol_rr_ready:1;
        RBus_UInt32  hpf_rr_enable:1;
        RBus_UInt32  res1:2;
        RBus_UInt32  mute_rr:1;
        RBus_UInt32  vol_lr_b:6;
        RBus_UInt32  vol_lr_a:5;
        RBus_UInt32  vol_lr_ready:1;
        RBus_UInt32  hpf_lr_enable:1;
        RBus_UInt32  res2:2;
        RBus_UInt32  mute_lr:1;
    };
}audio_lrrr_digital_volume_control_2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy1800690c_31_0:32;
    };
}audio_ts_ds_mbist_recoding_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_source_sel:1;
        RBus_UInt32  down_sample_rate:2;
        RBus_UInt32  res1:29;
    };
}audio_dvol_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  debug_mode_sel:9;
        RBus_UInt32  res1:3;
        RBus_UInt32  sif_adc_in_test_sel:1;
        RBus_UInt32  sif_adc_in_test_en:1;
        RBus_UInt32  res2:18;
    };
}audio_test_pattern_gen_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_crc_header:24;
        RBus_UInt32  res1:8;
    };
}audio_crc_header_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_crc_frame_length:16;
        RBus_UInt32  audio_crc_ch_sel:3;
        RBus_UInt32  audio_crc_en:1;
        RBus_UInt32  res1:12;
    };
}audio_crc_contorl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_crc:24;
        RBus_UInt32  audio_crc_done:1;
        RBus_UInt32  res1:7;
    };
}audio_crc_status_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zc_sample_cnt_golden:12;
        RBus_UInt32  zc_sample_cnt_threshold:6;
        RBus_UInt32  res1:2;
        RBus_UInt32  amplitude_low_threshold:2;
        RBus_UInt32  half_sine_num:2;
        RBus_UInt32  auto_chk_result:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  sine_channel_select:3;
        RBus_UInt32  sine_auto_chk_en:1;
    };
}audio_sine_auto_chk_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  zc_sample_cnt:12;
        RBus_UInt32  sine_amplitude:8;
        RBus_UInt32  res1:12;
    };
}audio_sine_wave_value_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  pcr_clk_1_sel_eco:1;
        RBus_UInt32  dummy18006a18_31:31;
    };
}audio_pattern_gen_dummy_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  to_ack_en:1;
        RBus_UInt32  dummy18006a50_3:3;
        RBus_UInt32  rbus_timeout_thr:10;
        RBus_UInt32  res1:18;
    };
}audio_rbus_ack_ctrl_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ack_fail_addr:12;
        RBus_UInt32  ack_fail_rw:1;
        RBus_UInt32  res1:19;
    };
}audio_ack_fail_info_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_mode_msd:1;
        RBus_UInt32  audio_bist_mode_am:1;
        RBus_UInt32  audio_bist_mode_a2_eiaj:1;
        RBus_UInt32  audio_bist_mode_dma:1;
        RBus_UInt32  audio_bist_mode_dma_ts:1;
        RBus_UInt32  audio_bist_mode_dac:1;
        RBus_UInt32  audio_bist_mode_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_bist_mode_ds:1;
        RBus_UInt32  audio_bist_mode_ts_ds:1;
        RBus_UInt32  audio_bist_mode_dma_arc:1;
        RBus_UInt32  audio_bist_mode_hw_drc:1;
        RBus_UInt32  audio_bist_mode_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_bist_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_done_msd:1;
        RBus_UInt32  audio_bist_done_am:1;
        RBus_UInt32  audio_bist_done_a2_eiaj:1;
        RBus_UInt32  audio_bist_done_dma:1;
        RBus_UInt32  audio_bist_done_dma_ts:1;
        RBus_UInt32  audio_bist_done_dac:1;
        RBus_UInt32  audio_bist_done_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_bist_done_ds:1;
        RBus_UInt32  audio_bist_done_ts_ds:1;
        RBus_UInt32  audio_bist_done_dma_arc:1;
        RBus_UInt32  audio_bist_done_hw_drc:1;
        RBus_UInt32  audio_bist_done_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_bist_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_fail_group_msd:1;
        RBus_UInt32  audio_bist_fail_group_am:1;
        RBus_UInt32  audio_bist_fail_group_a2_eiaj:1;
        RBus_UInt32  audio_bist_fail_group_dma:1;
        RBus_UInt32  audio_bist_fail_group_dma_ts:1;
        RBus_UInt32  audio_bist_fail_group_dac:1;
        RBus_UInt32  audio_bist_fail_group_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_bist_fail_group_ds:1;
        RBus_UInt32  audio_bist_fail_group_ts_ds:1;
        RBus_UInt32  audio_bist_fail_group_dma_arc:1;
        RBus_UInt32  audio_bist_fail_group_hw_drc:1;
        RBus_UInt32  audio_bist_fail_group_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_bist_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_a2_eiaj_fail_0:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_1:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_2:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_3:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_4:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_5:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_6:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_7:1;
        RBus_UInt32  audio_bist_a2_eiaj_fail_8:1;
        RBus_UInt32  audio_bist_down_fail_0:1;
        RBus_UInt32  audio_bist_down_fail_1:1;
        RBus_UInt32  audio_bist_down_fail_2:1;
        RBus_UInt32  audio_bist_down_fail_3:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  audio_bist_down_ts_fail_0:1;
        RBus_UInt32  audio_bist_down_ts_fail_1:1;
        RBus_UInt32  audio_bist_down_ts_fail_2:1;
        RBus_UInt32  audio_bist_down_ts_fail_3:1;
        RBus_UInt32  audio_bist_dac_fail_0:1;
        RBus_UInt32  audio_bist_dac_fail_1:1;
        RBus_UInt32  res2:1;
    };
}audio_audio_bist_a2_eiaj_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_mode_msd:1;
        RBus_UInt32  audio_drf_mode_am:1;
        RBus_UInt32  audio_drf_mode_a2_eiaj:1;
        RBus_UInt32  audio_drf_mode_dma:1;
        RBus_UInt32  audio_drf_mode_dma_ts:1;
        RBus_UInt32  audio_drf_mode_dac:1;
        RBus_UInt32  audio_drf_mode_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_drf_mode_ds:1;
        RBus_UInt32  audio_drf_mode_ts_ds:1;
        RBus_UInt32  audio_drf_mode_dma_arc:1;
        RBus_UInt32  audio_drf_mode_hw_drc:1;
        RBus_UInt32  audio_drf_mode_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_drf_mode_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_resume_msd:1;
        RBus_UInt32  audio_drf_resume_am:1;
        RBus_UInt32  audio_drf_resume_a2_eiaj:1;
        RBus_UInt32  audio_drf_resume_dma:1;
        RBus_UInt32  audio_drf_resume_dma_ts:1;
        RBus_UInt32  audio_drf_resume_dac:1;
        RBus_UInt32  audio_drf_resume_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_drf_resume_ds:1;
        RBus_UInt32  audio_drf_resume_ts_ds:1;
        RBus_UInt32  audio_drf_resume_dma_arc:1;
        RBus_UInt32  audio_drf_resume_hw_drc:1;
        RBus_UInt32  audio_drf_resume_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_drf_resume_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_done_msd:1;
        RBus_UInt32  audio_drf_done_am:1;
        RBus_UInt32  audio_drf_done_a2_eiaj:1;
        RBus_UInt32  audio_drf_done_dma:1;
        RBus_UInt32  audio_drf_done_dma_ts:1;
        RBus_UInt32  audio_drf_done_dac:1;
        RBus_UInt32  audio_drf_done_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_drf_done_ds:1;
        RBus_UInt32  audio_drf_done_ts_ds:1;
        RBus_UInt32  audio_drf_done_dma_arc:1;
        RBus_UInt32  audio_drf_done_hw_drc:1;
        RBus_UInt32  audio_drf_done_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_drf_done_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_pause_msd:1;
        RBus_UInt32  audio_drf_pause_am:1;
        RBus_UInt32  audio_drf_pause_a2_eiaj:1;
        RBus_UInt32  audio_drf_pause_dma:1;
        RBus_UInt32  audio_drf_pause_dma_ts:1;
        RBus_UInt32  audio_drf_pause_dac:1;
        RBus_UInt32  audio_drf_pause_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_drf_pause_ds:1;
        RBus_UInt32  audio_drf_pause_ts_ds:1;
        RBus_UInt32  audio_drf_pause_dma_arc:1;
        RBus_UInt32  audio_drf_pause_hw_drc:1;
        RBus_UInt32  audio_drf_pause_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_drf_pause_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_fail_group_msd:1;
        RBus_UInt32  audio_drf_fail_group_am:1;
        RBus_UInt32  audio_drf_fail_group_a2_eiaj:1;
        RBus_UInt32  audio_drf_fail_group_dma:1;
        RBus_UInt32  audio_drf_fail_group_dma_ts:1;
        RBus_UInt32  audio_drf_fail_group_dac:1;
        RBus_UInt32  audio_drf_fail_group_adc_0:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  audio_drf_fail_group_ds:1;
        RBus_UInt32  audio_drf_fail_group_ts_ds:1;
        RBus_UInt32  audio_drf_fail_group_dma_arc:1;
        RBus_UInt32  audio_drf_fail_group_hw_drc:1;
        RBus_UInt32  audio_drf_fail_group_nicam_src:1;
        RBus_UInt32  res2:19;
    };
}audio_audio_drf_fail_group_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_a2_eiaj_fail_0:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_1:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_2:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_3:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_4:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_5:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_6:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_7:1;
        RBus_UInt32  audio_drf_a2_eiaj_fail_8:1;
        RBus_UInt32  audio_drf_down_fail_0:1;
        RBus_UInt32  audio_drf_down_fail_1:1;
        RBus_UInt32  audio_drf_down_fail_2:1;
        RBus_UInt32  audio_drf_down_fail_3:1;
        RBus_UInt32  res1:12;
        RBus_UInt32  audio_drf_down_ts_fail_0:1;
        RBus_UInt32  audio_drf_down_ts_fail_1:1;
        RBus_UInt32  audio_drf_down_ts_fail_2:1;
        RBus_UInt32  audio_drf_down_ts_fail_3:1;
        RBus_UInt32  audio_drf_dac_fail_0:1;
        RBus_UInt32  audio_drf_dac_fail_1:1;
        RBus_UInt32  res2:1;
    };
}audio_audio_drf_a2_eiaj_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_drf_hw_drc_fail_0:1;
        RBus_UInt32  audio_drf_hw_drc_fail_1:1;
        RBus_UInt32  audio_drf_hw_drc_fail_2:1;
        RBus_UInt32  audio_drf_hw_drc_fail_3:1;
        RBus_UInt32  audio_drf_nicam_src_fail_0:1;
        RBus_UInt32  audio_drf_nicam_src_fail_1:1;
        RBus_UInt32  res1:26;
    };
}audio_audio_drf_hw_drc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  audio_bist_hw_drc_0:1;
        RBus_UInt32  audio_bist_hw_drc_1:1;
        RBus_UInt32  audio_bist_hw_drc_2:1;
        RBus_UInt32  audio_bist_hw_drc_3:1;
        RBus_UInt32  audio_bist_nicam_src_0:1;
        RBus_UInt32  audio_bist_nicam_src_1:1;
        RBus_UInt32  res1:26;
    };
}audio_audio_bist_hw_drc_fail_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  ad0_gain_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  ad0_gain_l:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  ad0_mute_r:1;
        RBus_UInt32  ad0_mute_l:1;
        RBus_UInt32  ad0_lp_sel:1;
        RBus_UInt32  adc0_src_lpf_disable:1;
        RBus_UInt32  ad0_zdet_func:2;
        RBus_UInt32  ad0_zdet_tout:2;
        RBus_UInt32  ad0_comp_gain:3;
        RBus_UInt32  ad0_hpf_en:1;
        RBus_UInt32  src_ad0_lpf1st_fc_sel:2;
        RBus_UInt32  src_op_sel_0:1;
        RBus_UInt32  daad_lp_en_0:1;
    };
}audio_ad0_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  da0_gain_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  da0_gain_l:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  da0_fifo_full_pending:1;
        RBus_UInt32  da0_fifo_empty_pending:1;
        RBus_UInt32  da0_fifo_full:1;
        RBus_UInt32  da0_fifo_empty:1;
        RBus_UInt32  da0_zdet_func:2;
        RBus_UInt32  da0_zdet_tout:2;
        RBus_UInt32  da0_dither_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  da0_hpf_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  src_en_0:1;
        RBus_UInt32  adda_lp_en_0:1;
    };
}audio_da0_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  da1_gain_r:7;
        RBus_UInt32  res1:1;
        RBus_UInt32  da1_gain_l:7;
        RBus_UInt32  res2:1;
        RBus_UInt32  da1_fifo_full_pending:1;
        RBus_UInt32  da1_fifo_empty_pending:1;
        RBus_UInt32  da1_fifo_full:1;
        RBus_UInt32  da1_fifo_empty:1;
        RBus_UInt32  da1_zdet_func:2;
        RBus_UInt32  da1_zdet_tout:2;
        RBus_UInt32  da1_dither_sel:2;
        RBus_UInt32  res3:1;
        RBus_UInt32  da1_hpf_en:1;
        RBus_UInt32  res4:2;
        RBus_UInt32  src_en_1:1;
        RBus_UInt32  adda_lp_en_1:1;
    };
}audio_da1_asrc_ip_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dac0_pcm_source_sel:4;
        RBus_UInt32  dac0_hw_out_limiter:7;
        RBus_UInt32  dac0_hw_out_limiter_en:1;
        RBus_UInt32  dac0_hw_r_inverter_en:1;
        RBus_UInt32  dac0_hw_l_inverter_en:1;
        RBus_UInt32  dac1_swap_sel:2;
        RBus_UInt32  dac0_swap_sel:2;
        RBus_UInt32  dac1_pcm_source_sel:4;
        RBus_UInt32  dac1_hw_out_limiter:7;
        RBus_UInt32  dac1_hw_out_limiter_en:1;
        RBus_UInt32  dac1_hw_r_inverter_en:1;
        RBus_UInt32  dac1_hw_l_inverter_en:1;
    };
}audio_dac0_1_src_sel_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dvcm:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  zcth:5;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_zero_in_en:1;
        RBus_UInt32  reg_in_thre:5;
        RBus_UInt32  res3:13;
        RBus_UInt32  adc_dvol_enable:1;
    };
}audio_adc_digital_volume_control_0_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  delay_ctrl_mute:10;
        RBus_UInt32  ramp_step_mute:2;
        RBus_UInt32  zcto_mute:3;
        RBus_UInt32  mute_apply:1;
        RBus_UInt32  delay_ctrl:10;
        RBus_UInt32  ramp_step:2;
        RBus_UInt32  zcto:3;
        RBus_UInt32  dvol_apply:1;
    };
}audio_adc_digital_volume_control_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_r_b:6;
        RBus_UInt32  vol_r_a:5;
        RBus_UInt32  vol_r_ready:1;
        RBus_UInt32  hpf_r_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rep_r_status:1;
        RBus_UInt32  mute_r:1;
        RBus_UInt32  vol_l_b:6;
        RBus_UInt32  vol_l_a:5;
        RBus_UInt32  vol_l_ready:1;
        RBus_UInt32  hpf_l_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rep_l_status:1;
        RBus_UInt32  mute_l:1;
    };
}audio_adc_lr_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  vol_rs_b:6;
        RBus_UInt32  vol_rs_a:5;
        RBus_UInt32  vol_rs_ready:1;
        RBus_UInt32  hpf_rs_enable:1;
        RBus_UInt32  res1:1;
        RBus_UInt32  rep_rs_status:1;
        RBus_UInt32  mute_rs:1;
        RBus_UInt32  vol_ls_b:6;
        RBus_UInt32  vol_ls_a:5;
        RBus_UInt32  vol_ls_ready:1;
        RBus_UInt32  hpf_ls_enable:1;
        RBus_UInt32  res2:1;
        RBus_UInt32  rep_ls_status:1;
        RBus_UInt32  mute_ls:1;
    };
}audio_adc_lsrs_digital_volume_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  double_buffer_ack:1;
        RBus_UInt32  zcto_status:1;
        RBus_UInt32  res1:30;
    };
}audio_adc_double_buffer_ack_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  double_buffer_ack_1:1;
        RBus_UInt32  zcto_status_1:1;
        RBus_UInt32  res1:28;
        RBus_UInt32  dvol_apply_1:1;
        RBus_UInt32  adc_dvol_enable_1:1;
    };
}audio_adc_double_buffer_ack_1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_adcfe_mutel:7;
        RBus_UInt32  res1:11;
        RBus_UInt32  reg_bb_adcfe_muter:7;
        RBus_UInt32  res2:7;
    };
}audio_analog_frontend1_mute_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_aio1_mutel:6;
        RBus_UInt32  res1:12;
        RBus_UInt32  reg_bb_hpo_mutel:7;
        RBus_UInt32  res2:6;
        RBus_UInt32  reg_bb_hpo_bias_sel:1;
    };
}audio_analog_aio_hpout_lineout_l_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_aio1_muter:6;
        RBus_UInt32  res1:12;
        RBus_UInt32  reg_bb_hpo_muter:7;
        RBus_UInt32  res2:7;
    };
}audio_analog_aio_hpout_lineout_r_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_adcfe_gselr:2;
        RBus_UInt32  reg_bb_adcfe_gsell:2;
        RBus_UInt32  res1:28;
    };
}audio_adc_volume_gain_control_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_bb_aio1_pow:1;
        RBus_UInt32  reg_bb_hpo_pow:1;
        RBus_UInt32  reg_bb_df2se_pow:2;
        RBus_UInt32  reg_bb_vref_pow:1;
        RBus_UInt32  reg_bb_mbias_pow:1;
        RBus_UInt32  reg_bb_dac_pow:2;
        RBus_UInt32  reg_bb_adc_pow:1;
        RBus_UInt32  reg_bb_adcfe_pow:1;
        RBus_UInt32  res2:20;
    };
}audio_analog_power_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  afe_pga_vol:4;
        RBus_UInt32  res1:5;
        RBus_UInt32  fix_gain:3;
        RBus_UInt32  res2:1;
        RBus_UInt32  option_gain:1;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_bb_adcfe_input_20k:1;
        RBus_UInt32  reg_bb_hpo_hpmode:1;
        RBus_UInt32  res4:14;
    };
}audio_analog_pga_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_isel_adc_aa:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_bb_isel_adcfe:2;
        RBus_UInt32  reg_bb_isel_adc_ref:2;
        RBus_UInt32  res2:4;
        RBus_UInt32  reg_bb_isel_dac:2;
        RBus_UInt32  res3:2;
        RBus_UInt32  reg_bb_isel_dac_vref:2;
        RBus_UInt32  reg_bb_isel_depop:2;
        RBus_UInt32  reg_bb_isel_df2se:2;
        RBus_UInt32  reg_bb_isel_hpo:2;
        RBus_UInt32  res4:2;
        RBus_UInt32  reg_bb_isel_aio1:2;
        RBus_UInt32  reg_bb_isel_vref:2;
        RBus_UInt32  reg_bb_isel_adc_vcm:2;
    };
}audio_analog_ci01_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_vref_vrefsel:2;
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_bb_adc_ckxen:1;
        RBus_UInt32  res2:3;
        RBus_UInt32  reg_bb_adc_ossel:2;
        RBus_UInt32  res3:22;
    };
}audio_analog_ci02_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  sel_bb_ck_depop:3;
        RBus_UInt32  bb_ck_depop_en:1;
        RBus_UInt32  reg_bb_dpramp_enramp:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  reg_bb_aio_endp:1;
        RBus_UInt32  reg_bb_hpo_endp:1;
        RBus_UInt32  reg_bb_isel_adc_core:2;
        RBus_UInt32  res2:20;
    };
}audio_analog_depop1_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:2;
        RBus_UInt32  reg_bb_aio1_normal:1;
        RBus_UInt32  reg_bb_hpo_normal:1;
        RBus_UInt32  reg_bb_dpramp_csel:2;
        RBus_UInt32  reg_bb_dpramp_pow:1;
        RBus_UInt32  reg_bb_dpramp_rampsel:1;
        RBus_UInt32  res2:24;
    };
}audio_analog_depop2_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  reg_bb_hpo_gselr:2;
        RBus_UInt32  reg_bb_hpo_gsell:2;
        RBus_UInt32  res1:20;
        RBus_UInt32  reg_bb_hpo_engr:1;
        RBus_UInt32  reg_bb_hpo_engl:1;
        RBus_UInt32  res2:6;
    };
}audio_analog_post_gain_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}audio_analog_out_copy_swap_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  res1:32;
    };
}audio_analog_gpio_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  rm_0_adc:4;
        RBus_UInt32  rme_0_adc:1;
        RBus_UInt32  res1:3;
        RBus_UInt32  res2:8;
        RBus_UInt32  rm_0_dac:4;
        RBus_UInt32  rme_0_dac:1;
        RBus_UInt32  res3:3;
        RBus_UInt32  rm_1_dac:4;
        RBus_UInt32  rme_1_dac:1;
        RBus_UInt32  res4:3;
    };
}audio_drf_bist_RBUS;

typedef union
{
    RBus_UInt32 regValue;
    struct{
        RBus_UInt32  dummy18006b78_31_0:32;
    };
}audio_analog_dummy2_RBUS;




#endif 


#endif 
