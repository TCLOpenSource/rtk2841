#ifndef __DVBS2_DEMOD_REALTEK_I_H
#define __DVBS2_DEMOD_REALTEK_I_H

#include "dvbs2_demod_base.h"

#ifdef __cplusplus
extern "C" {
#endif

// DVBS2 Virtual Register Address/Mask
//#define DVBS2_REG_BAUD_RATE                                     0x8000
    #define DVBS2_BITFLD_BAUD_RATE                      0xFFFFFFFF
//#define DVBS2_REG_MODULATION                                    0x8001
    #define DVBS2_BITFLD_MODULATION                     0x00000001
//#define DVBS2_REG_CODE_RATE                                     0x8002
    #define DVBS2_BITFLD_CODE_RATE                      0x0000000F
//#define DVBS2_REG_PILOTS_PRESENT                                0x8003
    #define DVBS2_BITFLD_PILOTS_PRESENT                 0x00000001
//#define DVBS2_REG_RRC_ROLLOFF_FACTOR                            0x8004
    #define DVBS2_BITFLD_RRC_ROLLOFF_FACTOR             0x00000003
//#define DVBS2_REG_ACTIVE_BAUD_RATE                              0x8005
    #define DVBS2_BITFLD_ACTIVE_BAUD_RATE               0xFFFFFFFF
//#define DVBS2_REG_ACTIVE_MODULATION                             0x8006
    #define DVBS2_BITFLD_ACTIVE_MODULATION              0x00000001
//#define DVBS2_REG_ACTIVE_CODE_RATE                              0x8007
    #define DVBS2_BITFLD_ACTIVE_CODE_RATE               0x0000000F
//#define DVBS2_REG_ACTIVE_PILOTS_PRESENT                         0x8008
    #define DVBS2_BITFLD_ACTIVE_PILOTS_PRESENT          0x00000001
//#define DVBS2_REG_ACTIVE_ROLLOFF_FACTOR                         0x8009
    #define DVBS2_BITFLD_ACTIVE_ROLLOFF_FACTOR          0x00000003
//#define DVBS2_REG_FER_AT_LDPC_OUTPUT                            0x800A
    #define DVBS2_BITFLD_FER_AT_LDPC_OUTPUT             0xFFFFFFFF
//#define DVBS2_REG_BER_AT_BCH_INPUT                              0x800B
    #define DVBS2_BITFLD_BER_AT_BCH_INPUT               0xFFFFFFFF
//#define DVBS2_REG_FER_AT_BCH_OUTPUT                             0x800C
    #define DVBS2_BITFLD_FER_AT_BCH_OUTPUT              0xFFFFFFFF
//#define DVBS2_REG_PER_AT_OUTPUT                                 0x800D
    #define DVBS2_BITFLD_PER_AT_OUTPUT                  0xFFFFFFFF
//#define DVBS2_REG_NUM_SECONDS_BER_AVERAGING                     0x800E
    #define DVBS2_BITFLD_NUM_SECONDS_BER_AVERAGING      0x0000001F
//#define DVBS2_REG_TS_PACKET_COUNT                               0x800F
    #define DVBS2_BITFLD_TS_PACKET_COUNT                0xFFFFFFFF
//#define DVBS2_REG_BAD_PACKET_COUNT                              0x8010
    #define DVBS2_BITFLD_BAD_PACKET_COUNT               0xFFFFFFFF
//#define DVBS2_REG_BIT_RATE                                      0x8011
    #define DVBS2_BITFLD_BIT_RATE                       0xFFFFFFFF
//#define DVBS2_REG_SNR_ESTIMATE                                  0x8012
    #define DVBS2_BITFLD_SNR_ESTIMATE                   0xFFFFFFFF
//#define DVBS2_CARRIER_FREQ_SEARCH_RANGE                         0x8013
    #define DVBS2_BITFLD_CARRIER_FREQ_SEARCH_RANGE      0xFFFFFFFF
//#define DVBS2_SYMBOL_RATE_SEARCH_RANGE                          0x8014
    #define DVBS2_BITFLD_SYMBOL_RATE_SEARCH_RANGE       0xFFFFFFFF
//#define DVBS2_REG_ACQUISITION_STATE                             0x8015
    #define DVBS2_BITFLD_ACQUISITION_STATE              0x0000001F
//#define DVBS2_REG_NUM_ACQUISITIONS                              0x8016
    #define DVBS2_BITFLD_NUM_ACQUISITIONS               0xFFFFFFFF
//#define DVBS2_REG_ACQUISITION_FAILURE_CODE                      0x8017
    #define DVBS2_BITFLD_ACQUISITION_FAILURE_CODE       0x0000001F
//#define DVBS2_REG_ERROR_CODE                                    0x8018
    #define DVBS2_BITFLD_TUNING_TIMEOUT_ERROR            0x00000080
    #define DVBS2_BITFLD_UNSUPPORTED_MODCOD_ERROR        0x00000040
    #define DVBS2_BITFLD_BBFRAME_PROC_UNDERRUN_ERROR     0x00000020
    #define DVBS2_BITFLD_TIMER_CONFIG_ERROR              0x00000010
    #define DVBS2_BITFLD_LOOP_PROC_UNDERRUN_ERROR        0x00000008
    #define DVBS2_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR 0x00000004
    #define DVBS2_BITFLD_SCP_TBUS_OFLOW_ERROR            0x00000002
    #define DVBS2_BITFLD_BAUD_RATE_RANGE_ERROR           0x00000001
//#define DVBS2_REG_I_AMP                                         0x8019
    #define DVBS2_BITFLD_I_AMP                          0x00000FFF
//#define DVBS2_REG_Q_AMP                                         0x801A
    #define DVBS2_BITFLD_Q_AMP                          0x00000FFF
//#define DVBS2_REG_ANALOG_GAIN                                   0x801B
    #define DVBS2_BITFLD_ANALOG_GAIN                    0x0000FFFF
//#define DVBS2_REG_DIGITAL_GAIN                                  0x801C
    #define DVBS2_BITFLD_DIGITAL_GAIN_I                 0xFFFF0000
    #define DVBS2_BITFLD_DIGITAL_GAIN_Q                 0x0000FFFF
//#define DVBS2_REG_ACQUISITION_TIME                              0x801D
    #define DVBS2_BITFLD_ACQUISITION_TIME               0xFFFFFFFF
//#define DVBS2_REG_CARRIER_FREQ_OFFSET                           0x801E
    #define DVBS2_BITFLD_CARRIER_FREQ_OFFSET            0xFFFFFFFF
//#define DVBS2_REG_CTRL                                          0x801F
    #define DVBS2_BITFLD_RESET_METRICS_ON_REACQUISITION 0x00000002
    #define DVBS2_BITFLD_DFE_COEFFS_CONTROL_MODE        0x00000001
//#define DVBS2_REG_MANUAL_DFE_COEFFS00                           0x8020
    #define DVBS2_BITFLD_DFE_COEFF_REAL_0               0xFFFF0000
    #define DVBS2_BITFLD_DFE_COEFF_IMAG_0               0x0000FFFF
//#define DVBS2_REG_SPECTRUM_INVERSION                            0x8030
    #define DVBS2_BITFLD_SPECTRUM_INVERSION             0x00000001
//#define DVBS2_REG_ACTIVE_SPECTRUM_INVERSION                     0x8031
    #define DVBS2_BITFLD_ACTIVE_SPECTRUM_INVERSION      0x00000001
//#define DVBS2_REG_TONE_DETECT_CTRL                              0x8032
    #define DVBS2_BITFLD_TONE_DETECT_ENABLE             0x00010000
    #define DVBS2_BITFLD_TONE_DETECT_ENABLE_PSD         0x00008000
    #define DVBS2_BITFLD_TONE_DETECT_PERIOD             0x00007F00
    #define DVBS2_BITFLD_TONE_DETECT_THRESHOLD          0x000000FF
//#define DVBS2_REG_TONE_DETECT_VALUE                             0x8033
    #define DVBS2_BITFLD_TONE_DETECT_CTRL_CHANGE        0xFF000000
    #define DVBS2_BITFLD_TONE_DETECT_PEAK_IDX           0x00FF8000
    #define DVBS2_BITFLD_TONE_DETECT_PEAK_RATIO         0x00007FFF
//#define DVBS2_REG_PHASE_TRACK_STATE                             0x8034
    #define DVBS2_BITFLD_DFE_PHASE_TRACKING_MODE          0xF0000000
    #define DVBS2_BITFLD_DFE_PHASE_TRACKING_GAIN_CTRL     0x0F000000
    #define DVBS2_BITFLD_DFE_PHASE_TRACKER_MS_PHASE_ERROR 0x00FFFFFF
//#define DVBS2_REG_PHASE_TRACK_CTRL                              0x8035
    #define DVBS2_BITFLD_DFE_PHASE_TRACKER_GAIN           0x80000000
    #define DVBS2_BITFLD_DFE_PHASE_CORE_CLIP_LVL          0x40000000
    #define DVBS2_BITFLD_DFE_PHASE_CORE_LVL               0x0FFF0000
    #define DVBS2_BITFLD_DFE_PHASE_CLIP_LVL               0x0000FFF0
    #define DVBS2_BITFLD_DFE_PHASE_TRACKER_GAIN_NEG_SHIFT 0x0000000F
//#define DVBS2_REG_TUNED_FREQ_OFFSET                             0x8036
    #define DVBS2_BITFLD_TUNED_FREQ_OFFSET              0xFFFFFFFF
//#define DVBS2_REG_TUNE_REQUEST                                  0x8037
    #define DVBS2_BITFLD_TUNE_REQUEST                   0xFFFFFFFF
//#define DVBS2_REG_BW_REQUEST                                    0x8038
    #define DVBS2_BITFLD_BW_REQUEST                     0xFFFFFFFF
//#define DVBS2_REG_DEBUG_PTR                                     0x8039
    #define DVBS2_BITFLD_DEBUG_PTR                      0xFFFFFFFF
//#define DVBS2_REG_META_LOG_PTR                                  0x803A
    #define DVBS2_BITFLD_META_LOG_PTR                   0xFFFFFFFF
//#define DVBS2_REG_MCP_LOG_PTR                                   0x803B
    #define DVBS2_BITFLD_MCP_LOG_PTR                    0xFFFFFFFF
//#define DVBS2_REG_TRACE_BUFF_PTR                                0x803C
    #define DVBS2_BITFLD_TRACE_BUFF_PTR                 0xFFFFFFFF
//#define DVBS2_REG_LDPC_JOB_COUNT                                0x803D
    #define DVBS2_BITFLD_LDPC_JOB_COUNT                 0xFFFFFFFF
//#define DVBS2_REG_LDPC_JOB_ERRORS                               0x803E
    #define DVBS2_BITFLD_LDPC_JOB_ERRORS                0xFFFFFFFF

    
// DVBS2X Virtual Register Address/Mask
//#define DVBS2X_REG_BAUD_RATE                                     0x8000
    #define DVBS2X_BITFLD_BAUD_RATE                      0xFFFFFFFF
//#define DVBS2X_REG_MODULATION                                    0x8001
    #define DVBS2X_BITFLD_MODULATION                     0x00000001
//#define DVBS2X_REG_CODE_RATE                                     0x8002
    #define DVBS2X_BITFLD_CODE_RATE                      0x0000000F
//#define DVBS2X_REG_PILOTS_PRESENT                                0x8003
    #define DVBS2X_BITFLD_PILOTS_PRESENT                 0x00000001
//#define DVBS2X_REG_RRC_ROLLOFF_FACTOR                            0x8004
    #define DVBS2X_BITFLD_RRC_ROLLOFF_FACTOR             0x00000003
//#define DVBS2X_REG_ACTIVE_BAUD_RATE                              0x8005
    #define DVBS2X_BITFLD_ACTIVE_BAUD_RATE               0xFFFFFFFF
//#define DVBS2X_REG_ACTIVE_MODULATION                             0x8006
    #define DVBS2X_BITFLD_ACTIVE_MODULATION              0x00000001
//#define DVBS2X_REG_ACTIVE_CODE_RATE                              0x8007
    #define DVBS2X_BITFLD_ACTIVE_CODE_RATE               0x0000000F
//#define DVBS2X_REG_ACTIVE_PILOTS_PRESENT                         0x8008
    #define DVBS2X_BITFLD_ACTIVE_PILOTS_PRESENT          0x00000001
//#define DVBS2X_REG_ACTIVE_ROLLOFF_FACTOR                         0x8009
    #define DVBS2X_BITFLD_ACTIVE_ROLLOFF_FACTOR          0x00000003
//#define DVBS2X_REG_FER_AT_LDPC_OUTPUT                            0x800A
    #define DVBS2X_BITFLD_FER_AT_LDPC_OUTPUT             0xFFFFFFFF
//#define DVBS2X_REG_BER_AT_BCH_INPUT                              0x800B
    #define DVBS2X_BITFLD_BER_AT_BCH_INPUT               0xFFFFFFFF
//#define DVBS2X_REG_FER_AT_BCH_OUTPUT                             0x800C
    #define DVBS2X_BITFLD_FER_AT_BCH_OUTPUT              0xFFFFFFFF
//#define DVBS2X_REG_PER_AT_OUTPUT                                 0x800D
    #define DVBS2X_BITFLD_PER_AT_OUTPUT                  0xFFFFFFFF
//#define DVBS2X_REG_NUM_SECONDS_BER_AVERAGING                     0x800E
    #define DVBS2X_BITFLD_NUM_SECONDS_BER_AVERAGING      0x0000001F
//#define DVBS2X_REG_TS_PACKET_COUNT                               0x800F
    #define DVBS2X_BITFLD_TS_PACKET_COUNT                0xFFFFFFFF
//#define DVBS2X_REG_BAD_PACKET_COUNT                              0x8010
    #define DVBS2X_BITFLD_BAD_PACKET_COUNT               0xFFFFFFFF
//#define DVBS2X_REG_BIT_RATE                                      0x8011
    #define DVBS2X_BITFLD_BIT_RATE                       0xFFFFFFFF
//#define DVBS2X_REG_SNR_ESTIMATE                                  0x8012
    #define DVBS2X_BITFLD_SNR_ESTIMATE                   0xFFFFFFFF
//#define DVBS2X_CARRIER_FREQ_SEARCH_RANGE                         0x8013
    #define DVBS2X_BITFLD_CARRIER_FREQ_SEARCH_RANGE      0xFFFFFFFF
//#define DVBS2X_SYMBOL_RATE_SEARCH_RANGE                          0x8014
    #define DVBS2X_BITFLD_SYMBOL_RATE_SEARCH_RANGE       0xFFFFFFFF
//#define DVBS2X_REG_ACQUISITION_STATE                             0x8015
    #define DVBS2X_BITFLD_ACQUISITION_STATE              0x0000001F
//#define DVBS2X_REG_NUM_ACQUISITIONS                              0x8016
    #define DVBS2X_BITFLD_NUM_ACQUISITIONS               0xFFFFFFFF
//#define DVBS2X_REG_ACQUISITION_FAILURE_CODE                      0x8017
    #define DVBS2X_BITFLD_ACQUISITION_FAILURE_CODE       0x0000001F
//#define DVBS2X_REG_ERROR_CODE                                    0x8018
    #define DVBS2X_BITFLD_TUNING_TIMEOUT_ERROR            0x00000080
    #define DVBS2X_BITFLD_UNSUPPORTED_MODCOD_ERROR        0x00000040
    #define DVBS2X_BITFLD_BBFRAME_PROC_UNDERRUN_ERROR     0x00000020
    #define DVBS2X_BITFLD_TIMER_CONFIG_ERROR              0x00000010
    #define DVBS2X_BITFLD_LOOP_PROC_UNDERRUN_ERROR        0x00000008
    #define DVBS2X_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR 0x00000004
    #define DVBS2X_BITFLD_SCP_TBUS_OFLOW_ERROR            0x00000002
    #define DVBS2X_BITFLD_BAUD_RATE_RANGE_ERROR           0x00000001
//#define DVBS2X_REG_I_AMP                                         0x8019
    #define DVBS2X_BITFLD_I_AMP                          0x00000FFF
//#define DVBS2X_REG_Q_AMP                                         0x801A
    #define DVBS2X_BITFLD_Q_AMP                          0x00000FFF
//#define DVBS2X_REG_ANALOG_GAIN                                   0x801B
    #define DVBS2X_BITFLD_ANALOG_GAIN                    0x0000FFFF
//#define DVBS2X_REG_DIGITAL_GAIN                                  0x801C
    #define DVBS2X_BITFLD_DIGITAL_GAIN_I                 0xFFFF0000
    #define DVBS2X_BITFLD_DIGITAL_GAIN_Q                 0x0000FFFF
//#define DVBS2X_REG_ACQUISITION_TIME                              0x801D
    #define DVBS2X_BITFLD_ACQUISITION_TIME               0xFFFFFFFF
//#define DVBS2X_REG_CARRIER_FREQ_OFFSET                           0x801E
    #define DVBS2X_BITFLD_CARRIER_FREQ_OFFSET            0xFFFFFFFF
//#define DVBS2X_REG_CTRL                                          0x801F
    #define DVBS2X_BITFLD_RESET_METRICS_ON_REACQUISITION 0x00000002
    #define DVBS2X_BITFLD_DFE_COEFFS_CONTROL_MODE        0x00000001
//#define DVBS2X_REG_MANUAL_DFE_COEFFS00                           0x8020
    #define DVBS2X_BITFLD_DFE_COEFF_REAL_0               0xFFFF0000
    #define DVBS2X_BITFLD_DFE_COEFF_IMAG_0               0x0000FFFF
//#define DVBS2X_REG_SPECTRUM_INVERSION                            0x8030
    #define DVBS2X_BITFLD_SPECTRUM_INVERSION             0x00000001
//#define DVBS2X_REG_ACTIVE_SPECTRUM_INVERSION                     0x8031
    #define DVBS2X_BITFLD_ACTIVE_SPECTRUM_INVERSION      0x00000001
//#define DVBS2X_REG_TONE_DETECT_CTRL                              0x8032
    #define DVBS2X_BITFLD_TONE_DETECT_ENABLE             0x00010000
    #define DVBS2X_BITFLD_TONE_DETECT_ENABLE_PSD         0x00008000
    #define DVBS2X_BITFLD_TONE_DETECT_PERIOD             0x00007F00
    #define DVBS2X_BITFLD_TONE_DETECT_THRESHOLD          0x000000FF
//#define DVBS2X_REG_TONE_DETECT_VALUE                             0x8033
    #define DVBS2X_BITFLD_TONE_DETECT_CTRL_CHANGE        0xFF000000
    #define DVBS2X_BITFLD_TONE_DETECT_PEAK_IDX           0x00FF8000
    #define DVBS2X_BITFLD_TONE_DETECT_PEAK_RATIO         0x00007FFF
//#define DVBS2X_REG_PHASE_TRACK_STATE                             0x8034
    #define DVBS2X_BITFLD_DFE_PHASE_TRACKING_MODE          0xF0000000
    #define DVBS2X_BITFLD_DFE_PHASE_TRACKING_GAIN_CTRL     0x0F000000
    #define DVBS2X_BITFLD_DFE_PHASE_TRACKER_MS_PHASE_ERROR 0x00FFFFFF
//#define DVBS2X_REG_PHASE_TRACK_CTRL                              0x8035
    #define DVBS2X_BITFLD_DFE_PHASE_TRACKER_GAIN           0x80000000
    #define DVBS2X_BITFLD_DFE_PHASE_CORE_CLIP_LVL          0x40000000
    #define DVBS2X_BITFLD_DFE_PHASE_CORE_LVL               0x0FFF0000
    #define DVBS2X_BITFLD_DFE_PHASE_CLIP_LVL               0x0000FFF0
    #define DVBS2X_BITFLD_DFE_PHASE_TRACKER_GAIN_NEG_SHIFT 0x0000000F
//#define DVBS2X_REG_TUNED_FREQ_OFFSET                             0x8036
    #define DVBS2X_BITFLD_TUNED_FREQ_OFFSET              0xFFFFFFFF
//#define DVBS2X_REG_TUNE_REQUEST                                  0x8037
    #define DVBS2X_BITFLD_TUNE_REQUEST                   0xFFFFFFFF
//#define DVBS2X_REG_BW_REQUEST                                    0x8038
    #define DVBS2X_BITFLD_BW_REQUEST                     0xFFFFFFFF
//#define DVBS2X_REG_DEBUG_PTR                                     0x8039
    #define DVBS2X_BITFLD_DEBUG_PTR                      0xFFFFFFFF
//#define DVBS2X_REG_META_LOG_PTR                                  0x803A
    #define DVBS2X_BITFLD_META_LOG_PTR                   0xFFFFFFFF
//#define DVBS2X_REG_MCP_LOG_PTR                                   0x803B
    #define DVBS2X_BITFLD_MCP_LOG_PTR                    0xFFFFFFFF
//#define DVBS2X_REG_TRACE_BUFF_PTR                                0x803C
    #define DVBS2X_BITFLD_TRACE_BUFF_PTR                 0xFFFFFFFF
//#define DVBS2X_REG_LDPC_JOB_COUNT                                0x803D
    #define DVBS2X_BITFLD_LDPC_JOB_COUNT                 0xFFFFFFFF
//#define DVBS2X_REG_LDPC_JOB_ERRORS                               0x803E
    #define DVBS2X_BITFLD_LDPC_JOB_ERRORS                0xFFFFFFFF
    

// DVBS Virtual Register Address/Mask
//#define DVBS_REG_BAUD_RATE                                      0x8000
    #define DVBS_BITFLD_BAUD_RATE                       0xFFFFFFFF
//#define DVBS_REG_CODE_RATE                                      0x8001
    #define DVBS_BITFLD_CODE_RATE                       0x00000007
//#define DVBS_REG_ACTIVE_BAUD_RATE                               0x8002
    #define DVBS_BITFLD_ACTIVE_BAUD_RATE                0xFFFFFFFF
//#define DVBS_REG_ACTIVE_CODE_RATE                               0x8003
    #define DVBS_BITFLD_ACTIVE_CODE_RATE                0x00000007
//#define DVBS_REG_BER_AT_VITERBI_INPUT                           0x8004
    #define DVBS_BITFLD_BER_AT_VITERBI_INPUT            0xFFFFFFFF
//#define DVBS_REG_BER_AT_RS_INPUT                                0x8005
    #define DVBS_BITFLD_BER_AT_RS_INPUT                 0xFFFFFFFF
//#define DVBS_REG_PER_AT_OUTPUT                                  0x8006
    #define DVBS_BITFLD_PER_AT_OUTPUT                   0xFFFFFFFF
//#define DVBS_REG_NUM_SECONDS_BER_AVERAGING                      0x8007
    #define DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING       0x0000001F
//#define DVBS_REG_TS_PACKET_COUNT                                0x8008
    #define DVBS_BITFLD_TS_PACKET_COUNT                 0xFFFFFFFF
//#define DVBS_REG_BAD_PACKET_COUNT                               0x8009
    #define DVBS_BITFLD_BAD_PACKET_COUNT                0xFFFFFFFF
//#define DVBS_REG_BIT_RATE                                       0x800A
    #define DVBS_BITFLD_BIT_RATE                        0xFFFFFFFF
//#define DVBS_REG_SNR_ESTIMATE                                   0x800B
    #define DVBS_BITFLD_SNR_ESTIMATE                    0xFFFFFFFF
//#define DVBS_CARRIER_FREQ_SEARCH_RANGE                          0x800C
    #define DVBS_BITFLD_CARRIER_FREQ_SEARCH_RANGE       0xFFFFFFFF
//#define DVBS_SYMBOL_RATE_SEARCH_RANGE                           0x800D
    #define DVBS_BITFLD_SYMBOL_RATE_SEARCH_RANGE        0xFFFFFFFF
//#define DVBS_REG_ACQUISITION_STATE                              0x800E
    #define DVBS_BITFLD_ACQUISITION_STATE               0x0000001F
//#define DVBS_REG_NUM_ACQUISITIONS                               0x800F
    #define DVBS_BITFLD_NUM_ACQUISITIONS                0xFFFFFFFF
//#define DVBS_REG_ACQUISITION_FAILURE_CODE                       0x8010
    #define DVBS_BITFLD_ACQUISITION_FAILURE_CODE        0x0000000F
//#define DVBS_REG_ERROR_CODE                                     0x8011
    #define DVBS_BITFLD_TUNING_TIMEOUT                  0x00000080
    #define DVBS_BITFLD_TIMER_CONFIG_ERROR              0x00000010
    #define DVBS_BITFLDLOOP_PROC_UNDERRUN_ERROR         0x00000008
    #define DVBS_BITFLD_SCP_IP_SYNCHRONISER_OFLOW_ERROR 0x00000004
    #define SCP_TBUS_OFLOW_ERROR                        0x00000002
    #define BAUD_RATE_RANGE_ERROR                       0x00000001
//#define DVBS_REG_I_AMP                                          0x8012
    #define DVBS_BITFLD_I_AMP                           0x00000FFF
//#define DVBS_REG_Q_AMP                                          0x8013
    #define DVBS_BITFLD_Q_AMP                           0x00000FFF
//#define DVBS_REG_ANALOG_GAIN                                    0x8014
    #define DVBS_BITFLD_ANALOG_GAIN                     0x0000FFFF
//#define DVBS_REG_DIGITAL_GAIN                                   0x8015
    #define DVBS_BITFLD_DIGITAL_GAIN_I                  0xFFFF0000
    #define DVBS_BITFLD_DIGITAL_GAIN_Q                  0x0000FFFF
//#define DVBS_REG_ACQUISITION_TIME                               0x8016
    #define DVBS_BITFLD_ACQUISITION_TIME                0xFFFFFFFF
//#define DVBS_REG_CARRIER_FREQ_OFFSET                            0x8017
    #define DVBS_BITFLD_CARRIER_FREQ_OFFSET             0xFFFFFFFF
//#define DVBS_REG_CTRL                                           0x8018
    #define DVBS_BITFLD_RESET_METRICS_ON_REACQUISITION  0x00000002
    #define DVBS_BITFLD_DFE_COEFFS_CONTROL_MODE         0x00000001
//#define DVBS_REG_MANUAL_DFE_COEFFS00                            0x8019
    #define DVBS_BITFLD_DFE_COEFF_REAL_n                0xFFFF0000
    #define DVBS_BITFLD_DFE_COEFF_IMAG_n                0x0000FFFF
//#define DVBS_REG_SPECTRUM_INVERSION                             0x8029
    #define DVBS_BITFLD_SPECTRUM_INVERSION              0x00000003
//#define DVBS_REG_ACTIVE_SPECTRUM_INVERSION                      0x802A
    #define DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION       0x00000003
//#define DVBS_REG_TONE_DETECT_CTRL                               0x802B
    #define DVBS_BITFLD_TONE_DETECT_ENABLE              0x00010000
    #define DVBS_BITFLD_TONE_DETECT_ENABLE_PSD          0x00008000
    #define DVBS_BITFLD_TONE_DETECT_PERIOD              0x00007F00
    #define DVBS_BITFLD_TONE_DETECT_THRESHOLD           0x000000FF
//#define DVBS_REG_TONE_DETECT_VALUE                              0x802C
    #define DVBS_BITFLD_TONE_DETECT_CTRL_CHANGE         0xFF000000
    #define DVBS_BITFLD_TONE_DETECT_PEAK_IDX            0x00FF8000
    #define DVBS_BITFLD_TONE_DETECT_PEAK_RATIO          0x00007FFF
//#define DVBS_REG_PHASE_TRACK_STATE                              0x802D
    #define DVBS_BITFLD_DFE_PHASE_TRACKING_MODE                     0xF0000000
    #define DVBS_BITFLD_DFE_PHASE_TRACKER_GAIN_CONTROL              0x0F000000
    #define DVBS_BITFLD_DFE_PHASE_TRACKER_MEAN_SQUARED_PHASE_ERROR  0x00FFFFFF
//#define DVBS_REG_PHASE_TRACK_CTRL                               0x802E
    #define DVBS_BITFLD_PHASE_TRACK_GAIN_ENABLE         0x80000000
    #define DVBS_BITFLD_PHASE_TRACK_CLIP_LEVEL_ENABLE   0x40000000
    #define DVBS_BITFLD_PHASE_TRACK_CORE_LEVEL          0x0FFF0000
    #define DVBS_BITFLD_PHASE_TRACK_CLIP_LEVEL          0x0000FFF0
    #define DVBS_BITFLD_PHASE_TRACK_GAIN_NEG_SHIFT      0x0000000F
//#define DVBS_REG_TUNED_FREQ_OFFSET                              0x802F
    #define DVBS_BITFLD_TUNED_FREQ_OFFSET               0xFFFFFFFF
//#define DVBS_REG_TUNE_REQUEST                                   0x8030
    #define DVBS_BITFLD_TUNE_REQUEST                    0xFFFFFFFF
//#define DVBS_REG_BW_REQUEST                                     0x8031
    #define DVBS_BITFLD_BW_REQUEST                      0xFFFFFFFF
//#define DVBS_REG_DEBUG_PTR                                      0x8032
    #define DVBS_BITFLD_DEBUG_PTR                       0xFFFFFFFF
//#define DVBS_REG_META_LOG_PTR                                   0x8033
    #define DVBS_BITFLD_META_LOG_PTR                    0xFFFFFFFF
//#define DVBS_REG_MCP_LOG_PTR                                    0x8034
    #define DVBS_BITFLD_MCP_LOG_PTR                     0xFFFFFFFF
//#define DVBS_REG_TRACE_BUFF_PTR                                 0x8035
    #define DVBS_BITFLD_TRACE_BUFF_PTR                  0xFFFFFFFF


//Spectrum Analyzer
//#define SA_SCAN_RANGE                                           0x8000
    #define SA_BITFLD_SCAN_RANGE                        0xFFFFFFFF
//#define SA_SCAN_RESOLUTION                                      0x8001
    #define SA_BITFLD_SCAN_RESOLUTION                   0xFFFFFFFF
//#define SA_TUNING_STEP                                          0x8002
    #define SA_BITFLD_TUNING_STEP_AUTO                  0x80000000
    #define SA_BITFLD_TUNING_STEP                       0x7FFFFFFF
//#define SA_MEASUREMENT_CONTROL                                  0x8003
    #define SA_BITFLD_ENABLE_DC_COMP                    0x00000200
    #define SA_BITFLD_WINDOW                            0x000001C0
    #define SA_BITFLD_SIGNAL_TYPE                       0x00000038
    #define SA_BITFLD_MAX_PEAK_WIDTH                    0x00000007
//#define SA_AVERAGING_PERIOD                                     0x8004
    #define SA_BITFLD_AVERAGING_PERIOD_M                0x0000FF00
    #define SA_BITFLD_AVERAGING_PERIOD_N                0x000000FF
//#define SA_IF_GAIN_OVERRIDE                                     0x8005
    #define SA_BITFLD_OVERRIDE_IF_GAIN                  0x00010000
    #define SA_BITFLD_IF_GAIN                           0x0000FFFF
//#define SA_TUNER_3DB_POINT                                      0x8006
    #define SA_BITFLD_TUNER_3DB_POINT                   0xFFFFFFFF
//#define SA_TUNER_6DB_POINT                                      0x8007
    #define SA_BITFLD_TUNER_6DB_POINT                   0xFFFFFFFF
//#define SA_TUNER_9DB_POINT                                      0x8008
    #define SA_BITFLD_TUNER_9DB_POINT                   0xFFFFFFFF
//#define SA_TUNER_12DB_POINT                                     0x8009
    #define SA_BITFLD_TUNER_12DB_POINT                  0xFFFFFFFF
//#define SA_REG_OUT_SPECTRUM_PTR                                 0x800A
    #define SA_BITFLD_OUT_SPECTRUM_MEM_TYPE             0xC0000000
    #define SA_BITFLD_OUT_SPECTRUM_PTR                  0x3FFFFFFF
//#define SA_OUT_SPECTRUM_LEN                                     0x800B
    #define SA_BITFLD_OUT_SPECTRUM_LEN                  0xFFFFFFFF
//#define SA_MAX_RSSI_REG                                         0x800C
    #define SA_BITFLD_MAX_RSSI                          0xFFFF0000
    #define SA_BITFLD_MAX_RSSI_INDEX                    0x0000FFFF
//#define SA_REF_IF_GAIN_REG                                      0x800D
    #define SA_BITFLD_REF_IF_GAIN_REG                   0xFFFFFFFF
//#define SA_MAX_POWER_REG_00                                     0x800E
//#define SA_MAX_POWER_REG_01                                     0x800F
//#define SA_MAX_POWER_REG_02                                     0x8010
//#define SA_MAX_POWER_REG_03                                     0x8011
//#define SA_MAX_POWER_REG_04                                     0x8012
//#define SA_MAX_POWER_REG_05                                     0x8013
//#define SA_MAX_POWER_REG_06                                     0x8014
//#define SA_MAX_POWER_REG_07                                     0x8015
    #define SA_BITFLD_SA_MAX_POWER                      0x00FF0000
    #define SA_BITFLD_MAX_POWER_INDEX                   0x0000FFFF
//#define SA_FAILURE_CODE                                         0x8016
    #define SA_BITFLD_SCAN_SIZE_EXCEEDS_AVAILABLE_MEMORY 0x00000001
//#define SA_COMPLETION_PERCENT                                   0x8017
    #define SA_BITFLD_COMPLETION_PERCENT                0x000000FF

// Builder
void
BuildRealtekIDvbs2Module(
	DVBS2_DEMOD_MODULE **ppDemod,
	DVBS2_DEMOD_MODULE *pDvbS2DemodModuleMemory,
	BASE_INTERFACE_MODULE *pBaseInterfaceModuleMemory,
	I2C_BRIDGE_MODULE *pI2cBridgeModuleMemory,
	unsigned char DeviceAddr,
	unsigned long CrystalFreqHz
);

// DVBS2 Virtual Register
int
realtek_i_dvbs2_SetBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int BaudRate
);

int
realtek_i_dvbs2_GetBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BaudRate
);

int
realtek_i_dvbs2_SetModulation(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Modulation
);

int
realtek_i_dvbs2_GetModulation(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *Modulation
);

int
realtek_i_dvbs2_SetCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CodeRate
);

int
realtek_i_dvbs2_GetCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CodeRate
);

int
realtek_i_dvbs2_SetPilotPresent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int PilotPresent
);

int
realtek_i_dvbs2_GetPilotPresent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *PilotPresent
);

int
realtek_i_dvbs2_SetRolloffFactor(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int RolloffFactor
);

int
realtek_i_dvbs2_GetRolloffFactor(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *RolloffFactor
);

int
realtek_i_dvbs2_GetActiveBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
);

int
realtek_i_dvbs2_GetActiveModulation(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveModulation
);

int
realtek_i_dvbs2_GetActiveCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
);

int
realtek_i_dvbs2_GetActivePilotPresent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActivePilotPresent
);

int
realtek_i_dvbs2_GetActiveRolloffFactor(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveRolloffFactor
);

int
realtek_i_dvbs2_GetLdpcOutputFer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *LdpcOutputFer
);

int
realtek_i_dvbs2_GetBchInputBer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BchInputBer
);

int
realtek_i_dvbs2_GetBchOutputFer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BchOutputFer
);

int
realtek_i_dvbs2_GetSysOutputPer(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SysOutputPer
);

int
realtek_i_dvbs2_SetBerAveSecNum(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int BerAveSecNum
);

int
realtek_i_dvbs2_GetBerAveSecNum(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BerAveSecNum
);

int
realtek_i_dvbs2_GetTsPktCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TsPktCnt
);

int
realtek_i_dvbs2_GetBadPktCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *BadPktCnt
);

int
realtek_i_dvbs2_GetOutputBitRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutputBitRat
);

int
realtek_i_dvbs2_GetSnr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *Snr
);

int
realtek_i_dvbs2_SetCarrierFreqSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int CarrierFreqSearchRange
);

int
realtek_i_dvbs2_GetCarrierFreqSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqSearchRange
);

int
realtek_i_dvbs2_SetSymbolRateSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SymbolRateSearchRange
);

int
realtek_i_dvbs2_GetSymbolRateSearchRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SymbolRateSearchRange
);

int
realtek_i_dvbs2_GetAcquisitionState(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionState
);

int
realtek_i_dvbs2_SetSignalAcquisitionCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SignalAcquisitionCnt
);

int
realtek_i_dvbs2_GetSignalAcquisitionCnt(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SignalAcquisitionCnt
);

int
realtek_i_dvbs2_GetAcquisitionFailCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionFailCode
);

int
realtek_i_dvbs2_SetDemodErrorCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DemodErrorCode
);

int
realtek_i_dvbs2_GetDemodErrorCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DemodErrorCode
);

int
realtek_i_dvbs2_GetAmplitudeI(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AmplitudeI
);

int
realtek_i_dvbs2_GetAmplitudeQ(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AmplitudeQ
);

int
realtek_i_dvbs2_GetAnalogGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AnalogGain
);

int
realtek_i_dvbs2_GetDigitalGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DigitalGainI,
	unsigned int *DigitalGainQ
);

int
realtek_i_dvbs2_GetAcquisitionTime(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

int
realtek_i_dvbs2_GetCarrierFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
);

int
realtek_i_dvbs2_SetPhyCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ReAcqResetMetricsEn,
	unsigned int CoeffsCtrlMode
);

int
realtek_i_dvbs2_GetPhyCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ReAcqResetMetricsEn,
	unsigned int *CoeffsCtrlMode
);

int
realtek_i_dvbs2_SetManualDfeCoeff0(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ManualCoeffReal0,
	unsigned int ManualCoeffImg0
);

int
realtek_i_dvbs2_GetManualDfeCoeff0(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ManualCoeffReal0,
	unsigned int *ManualCoeffImg0
);

int
realtek_i_dvbs2_SetSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
);

int
realtek_i_dvbs2_GetSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *SpectrumInversion
);

int
realtek_i_dvbs2_GetActiveSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
);

/*int
realtek_i_dvbs2_SetSystemClockInfo(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int LdpcClockFreq,
	unsigned int MetaClockFreq
);
*/

int
realtek_i_dvbs2_SetToneDetectionCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ToneDetEn,
	unsigned int ToneDetPsdEn,
	unsigned int ToneDetPeriod,
	unsigned int ToneDetTh
);

int
realtek_i_dvbs2_GetToneDetectionValue(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ToneDetChange,
	unsigned int *ToneDetPeakIdx,
	unsigned int *ToneDetPeakRatio
);

int
realtek_i_dvbs2_SetDfePhaseTrackerState(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DfePhaseTrackMode,
	unsigned int DfePhaseTrackGain,
	unsigned int DfePhaseTrackErr
);

int
realtek_i_dvbs2_GetDfePhaseTrackerState(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackMode,
	unsigned int *DfePhaseTrackGain,
	unsigned int *DfePhaseTrackErr
);

int
realtek_i_dvbs2_GetDfePhaseTrackerOverrideCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *DfePhaseTrackGain,
	unsigned int *DfePhaseTrackCoreClipLvl,
	unsigned int *CoreLvl,
	unsigned int *ClipLvl,
	unsigned int *DfePhaseTrackGainNegShift
);

int
realtek_i_dvbs2_SetTunedFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
);

int
realtek_i_dvbs2_GetTunedFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqOffset
);

int
realtek_i_dvbs2_SetTunerFreqRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqReq
);

int
realtek_i_dvbs2_GetTunerFreqRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqReq
);

int
realtek_i_dvbs2_SetTunerBandwidthRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqReq
);

int
realtek_i_dvbs2_GetTunerBandwidthRequest(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TunedFreqReq
);

int
realtek_i_dvbs2_GetIfAgcGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *IfAgcGain
);

int
realtek_i_dvbs2_DvbSSetCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int DemodCodeRate
);

int
realtek_i_dvbs2_DvbSSetSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int SpectrumInversion
);

int
realtek_i_dvbs2_DvbSGetActiveBaudRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveBaudRate
);

int
realtek_i_dvbs2_DvbSGetActiveCodeRate(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveCodeRate
);

int
realtek_i_dvbs2_DvbSGetActiveSpectrumInversion(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ActiveSpectrumInversion
);

int
realtek_i_dvbs2_DvbSGetCarrierFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CarrierFreqOffset
);

int
realtek_i_dvbs2_DvbSSetNumSecBerAvg(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int NumSecBerAvg
);

int
realtek_i_dvbs2_DvbSSetTunedFreqOffset(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TunedFreqOffset
);

int
realtek_i_dvbs2_DvbSGetAcquisitionTime(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AcquisitionTime
);

//Spectrum Analyzer
int
realtek_i_SpecAn_DvbS2SetSpecAnScanRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ScanRange
);

int
realtek_i_SpecAn_DvbS2GetSpecAnScanRange(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ScanRange
);

int
realtek_i_SpecAn_DvbS2SetSpecAnScanResolution(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int ScanResolution
);

int
realtek_i_SpecAn_DvbS2GetSpecAnScanResolution(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *ScanResolution
);

int
realtek_i_SpecAn_DvbS2SetSpecAnTuningStep(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int TuningStepAuto,
	unsigned int TuningStep
);

int
realtek_i_SpecAn_DvbS2GetSpecAnTuningStep(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *TuningStepAuto,
	unsigned int *TuningStep
);

int
realtek_i_SpecAn_DvbS2SetSpecAnMeasureCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int EnDcComp,
	unsigned int Window,
	unsigned int SignalType,
	unsigned int MaxPickWidth
);

int
realtek_i_SpecAn_DvbS2GetSpecAnMeasureCtrl(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *EnDcComp,
	unsigned int *Window,
	unsigned int *SignalType,
	unsigned int *MaxPickWidth
);

int
realtek_i_SpecAn_DvbS2SetSpecAnAveragePeriod(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int AveragePeriodM,
	unsigned int AveragePeriodN
);

int
realtek_i_SpecAn_DvbS2GetSpecAnAveragePeriod(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *AveragePeriodM,
	unsigned int *AveragePeriodN
);

int
realtek_i_SpecAn_DvbS2SetSpecAnIfGainOverride(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int OverrideIfGain,
	unsigned int IfGain
);

int
realtek_i_SpecAn_DvbS2GetSpecAnIfGainOverride(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OverrideIfGain,
	unsigned int *IfGain
);

int
realtek_i_SpecAn_DvbS2SetSpecAnTuner3dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbS2SetSpecAnTuner6dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbS2SetSpecAnTuner9dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbS2SetSpecAnTuner12dBPoint(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int FreqSpacing
);

int
realtek_i_SpecAn_DvbS2GetSpecAnOutSpectrumPtr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecMemType,
	unsigned int *SpecMemPtr
);

int
realtek_i_SpecAn_DvbS2GetSpecAnOutSpectrumLen(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutSpecLen
);

int
realtek_i_SpecAn_DvbS2GetSpecAnMaxRssi(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *MaxRssi,
	unsigned int *MaxRssiIdx
);

int
realtek_i_SpecAn_DvbS2GetSpecAnRefIfGain(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *RefIfGain
);

int
realtek_i_SpecAn_DvbS2GetSpecAnMaxPwr(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int Number,
	unsigned int *MaxPwrDb,
	unsigned int *MaxPwrindex
);

int
realtek_i_SpecAn_DvbS2GetSpecAnFailureCode(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *OutOfMem
);

int
realtek_i_SpecAn_DvbS2GetSpecAnCompletionPercent(
	DVBS2_DEMOD_MODULE *pDemod,
	unsigned int *CompPercent
);

#ifdef __cplusplus
}
#endif
#endif
