/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _dvbt2_H_
#define _dvbt2_H_

/* DVBT2 Major and Minor version numbers */
#define DVBT2_VERSION_MAJOR 0x02
#define DVBT2_VERSION_MINOR 0x00

/* Configuration */
#define DVBT2_REG_SELECT_T2_PROFILE_CMD 0x8000

/* Configuration */
#define DVBT2_REG_SELECT_DETECT_TIME_MS_CMD 0x8001

/* Configuration */
#define DVBT2_REG_SIGNAL_INDICATOR 0x8002

/* Configuration */
#define DVBT2_REG_TS_LOCK_TIME_MS 0x8003

/* Configuration */
#define DVBT2_REG_SPECTRUM_INVERTED 0x8004

/* Configuration */
#define DVBT2_REG_DVBT_SEARCH_MODE 0x8005

/* Configuration */
#define DVBT2_REG_P1SEARCH_TIMEOUT_MS 0x8006

/* Configuration */
#define DVBT2_REG_MIN_P1_COUNT 0x8007

/* Configuration */
#define DVBT2_REG_DVBTSEARCH_TIMEOUT_MS 0x8008

/* Configuration */
#define DVBT2_REG_DVBTSEARCH_REFRESH_PERIOD_MS 0x8009

/* Configuration */
#define DVBT2_REG_DVBT_DECISION_THRESHOLD_1 0x800A

/* Configuration */
#define DVBT2_REG_DVBT_DECISION_THRESHOLD_2 0x800B

/* Configuration */
#define DVBT2_REG_DVBT_SEARCH_RESULTS 0x800C

/* Configuration */
#define DVBT2_REG_SELECT_DATA_PLP_ID_CMD 0x800D

/* Configuration */
#define DVBT2_REG_ACTIVE_DATA_PLP_ID 0x800E

/* Configuration */
#define DVBT2_REG_NUM_DATA_PLP 0x800F

/* Configuration */
#define DVBT2_REG_DATA_PLP_LIST 0x8010

/* Configuration */
#define DVBT2_REG_L1PRE_TYPE 0x8011

/* Configuration */
#define DVBT2_REG_BWT_EXT 0x8012

/* Configuration */
#define DVBT2_REG_S1 0x8013

/* Configuration */
#define DVBT2_REG_S2 0x8014

/* Configuration */
#define DVBT2_REG_L1_REPETITION_FLAG 0x8015

/* Configuration */
#define DVBT2_REG_GUARD_INTERVAL 0x8016

/* Configuration */
#define DVBT2_REG_PAPR 0x8017

/* Configuration */
#define DVBT2_REG_L1_MOD 0x8018

/* Configuration */
#define DVBT2_REG_L1_COD 0x8019

/* Configuration */
#define DVBT2_REG_L1_FEC_TYPE 0x801A

/* Configuration */
#define DVBT2_REG_L1POST_SIZE 0x801B

/* Configuration */
#define DVBT2_REG_L1POSTINFO_SIZE 0x801C

/* Configuration */
#define DVBT2_REG_PILOT_PATTERN 0x801D

/* Configuration */
#define DVBT2_REG_CELL_ID 0x801E

/* Configuration */
#define DVBT2_REG_NETWORK_ID 0x801F

/* Configuration */
#define DVBT2_REG_T2_SYSTEM_ID 0x8020

/* Configuration */
#define DVBT2_REG_NUM_T2_FRAMES 0x8021

/* Configuration */
#define DVBT2_REG_NUM_DATA_SYMBOLS 0x8022

/* Configuration */
#define DVBT2_REG_L1POST_EXTENSION 0x8023

/* Configuration */
#define DVBT2_REG_NUM_RF 0x8024

/* Configuration */
#define DVBT2_REG_T2_VERSION 0x8025

/* Configuration */
#define DVBT2_REG_SUB_SLICES_PER_FRAME 0x8026

/* Configuration */
#define DVBT2_REG_NUM_PLP 0x8027

/* Configuration */
#define DVBT2_REG_FEF_LENGTH 0x8028

/* Configuration */
#define DVBT2_REG_FEF_INTERVAL 0x8029

/* Configuration */
#define DVBT2_REG_DATA_PLP_PAYLOAD_TYPE 0x802A

/* Configuration */
#define DVBT2_REG_DATA_PLP_TYPE 0x802B

/* Configuration */
#define DVBT2_REG_DATA_PLP_GROUP_ID 0x802C

/* Configuration */
#define DVBT2_REG_DATA_PLP_COD 0x802D

/* Configuration */
#define DVBT2_REG_DATA_PLP_MOD 0x802E

/* Configuration */
#define DVBT2_REG_DATA_PLP_ROTATION 0x802F

/* Configuration */
#define DVBT2_REG_DATA_PLP_FEC_TYPE 0x8030

/* Configuration */
#define DVBT2_REG_DATA_PLP_NUM_BLOCKS_MAX 0x8031

/* Configuration */
#define DVBT2_REG_DATA_PLP_FRAME_INTERVAL 0x8032

/* Configuration */
#define DVBT2_REG_DATA_PLP_TIME_IL_TYPE 0x8033

/* Configuration */
#define DVBT2_REG_DATA_PLP_TIME_IL_LENGTH 0x8034

/* Configuration */
#define DVBT2_REG_DATA_PLP_MODE 0x8035

/* Configuration */
#define DVBT2_REG_COMMON_PLP_ID 0x8036

/* Configuration */
#define DVBT2_REG_COMMON_PLP_PAYLOAD_TYPE 0x8037

/* Configuration */
#define DVBT2_REG_COMMON_PLP_TYPE 0x8038

/* Configuration */
#define DVBT2_REG_COMMON_PLP_GROUP_ID 0x8039

/* Configuration */
#define DVBT2_REG_COMMON_PLP_COD 0x803A

/* Configuration */
#define DVBT2_REG_COMMON_PLP_MOD 0x803B

/* Configuration */
#define DVBT2_REG_COMMON_PLP_ROTATION 0x803C

/* Configuration */
#define DVBT2_REG_COMMON_PLP_FEC_TYPE 0x803D

/* Configuration */
#define DVBT2_REG_COMMON_PLP_NUM_BLOCKS_MAX 0x803E

/* Configuration */
#define DVBT2_REG_COMMON_PLP_FRAME_INTERVAL 0x803F

/* Configuration */
#define DVBT2_REG_COMMON_PLP_TIME_IL_TYPE 0x8040

/* Configuration */
#define DVBT2_REG_COMMON_PLP_TIME_IL_LENGTH 0x8041

/* Configuration */
#define DVBT2_REG_COMMON_PLP_MODE 0x8042

/* Configuration */
#define DVBT2_REG_DATA_PLP_START 0x8043

/* Configuration */
#define DVBT2_REG_DATA_PLP_NUM_BLOCKS 0x8044

/* Configuration */
#define DVBT2_REG_COMMON_PLP_START 0x8045

/* Configuration */
#define DVBT2_REG_COMMON_PLP_NUM_BLOCKS 0x8046

/* Configuration */
#define DVBT2_REG_SFOPPM_Q16_15 0x8047

/* Engineering */
#define DVBT2_REG_TS_BAD_PACKETS 0x8048

/* Engineering */
#define DVBT2_REG_DATA_ERROR_COUNTERS_CMD 0x8049

/* Engineering */
#define DVBT2_REG_DATA_DECODED_FRAMES 0x804A

/* Engineering */
#define DVBT2_REG_DATA_LDPC_STUCK_FRAMES 0x804B

/* Engineering */
#define DVBT2_REG_DATA_LDPC_UNSTABLE_FRAMES 0x804C

/* Engineering */
#define DVBT2_REG_DATA_LDPC_FRAMES_WITH_PARITY_FAILURE 0x804D

/* Engineering */
#define DVBT2_REG_DATA_LDPC_PARITY_CHECK_FAILURES 0x804E

/* Engineering */
#define DVBT2_REG_DATA_BCH_UNCORRECTABLE_CWS 0x804F

/* Engineering */
#define DVBT2_REG_DATA_BCH_CORRECTED_BYTES 0x8050

/* Engineering */
#define DVBT2_REG_DATA_BCH_CORRECTED_BITS 0x8051

/* Engineering */
#define DVBT2_REG_COMMON_ERROR_COUNTERS_CMD 0x8052

/* Engineering */
#define DVBT2_REG_COMMON_DECODED_FRAMES 0x8053

/* Engineering */
#define DVBT2_REG_COMMON_LDPC_STUCK_FRAMES 0x8054

/* Engineering */
#define DVBT2_REG_COMMON_LDPC_UNSTABLE_FRAMES 0x8055

/* Engineering */
#define DVBT2_REG_COMMON_LDPC_FRAMES_WITH_PARITY_FAILURE 0x8056

/* Engineering */
#define DVBT2_REG_COMMON_LDPC_PARITY_CHECK_FAILURES 0x8057

/* Engineering */
#define DVBT2_REG_COMMON_BCH_UNCORRECTABLE_CWS 0x8058

/* Engineering */
#define DVBT2_REG_COMMON_BCH_CORRECTED_BYTES 0x8059

/* Engineering */
#define DVBT2_REG_COMMON_BCH_CORRECTED_BITS 0x805A

/* Engineering */
#define DVBT2_REG_ERROR_RATES_INTEGRATION_PERIOD 0x805B

/* Engineering */
#define DVBT2_REG_DATA_ERROR_RATES_UPDATES 0x805C

/* Engineering */
#define DVBT2_REG_DATA_LDPC_OUTPUT_FER_Q32 0x805D

/* Engineering */
#define DVBT2_REG_DATA_BCH_INPUT_BER_Q32 0x805E

/* Engineering */
#define DVBT2_REG_DATA_BCH_OUTPUT_FER_Q32 0x805F

/* Engineering */
#define DVBT2_REG_DATA_SQI 0x8060

/* Engineering */
#define DVBT2_REG_COMMON_ERROR_RATES_UPDATES 0x8061

/* Engineering */
#define DVBT2_REG_COMMON_LDPC_INPUT_BER_Q32 0x8062

/* Engineering */
#define DVBT2_REG_COMMON_BCH_INPUT_BER_Q32 0x8063

/* Engineering */
#define DVBT2_REG_COMMON_BCH_OUTPUT_FER_Q32 0x8064

/* Engineering */
#define DVBT2_REG_SYM_STATUS_UPDATES 0x8065

/* Engineering */
#define DVBT2_REG_SYM_SYMBOL_COUNT 0x8066

/* Engineering */
#define DVBT2_REG_SYM_FRAME_COUNT 0x8067

/* Engineering */
#define DVBT2_REG_SYM_CSI_DB_Q16_15 0x8068

/* Engineering */
#define DVBT2_REG_SYM_NOISE_VAR_DB_Q16_15 0x8069

/* Engineering */
#define DVBT2_REG_SYM_CHANNEL_DELAY_SPREAD 0x806A

/* Engineering */
#define DVBT2_REG_SYM_CFO_HZ 0x806B

/* Engineering */
#define DVBT2_REG_SSI 0x806C

/* Engineering */
#define DVBT2_REG_DATA_HEM 0x806D

/* Engineering */
#define DVBT2_REG_DATA_ISSYI 0x806E

/* Engineering */
#define DVBT2_REG_DATA_NPD 0x806F

/* Engineering */
#define DVBT2_REG_DATA_VAR_DFL 0x8070

/* Engineering */
#define DVBT2_REG_DATA_PACKETS 0x8071

/* Engineering */
#define DVBT2_REG_DATA_BITRATE_Q3_29 0x8072

/* Engineering */
#define DVBT2_REG_COMMON_HEM 0x8073

/* Engineering */
#define DVBT2_REG_COMMON_ISSYI 0x8074

/* Engineering */
#define DVBT2_REG_COMMON_NPD 0x8075

/* Engineering */
#define DVBT2_REG_COMMON_VAR_DFL 0x8076

/* Engineering */
#define DVBT2_REG_COMMON_PACKETS 0x8077

/* Engineering */
#define DVBT2_REG_COMMON_BITRATE_Q3_29 0x8078

/* Engineering */
#define DVBT2_REG_L1_INFO 0x8079

/* Engineering */
#define DVBT2_REG_CONSTELLATION_BUFFER_HOST_STATUS_CMD 0x807A

/* Engineering */
#define DVBT2_REG_CONSTELLATION_BUFFER_ADDRESS 0x807B

/* Engineering */
#define DVBT2_REG_CONSTELLATION_SAMPLE_NUMBER 0x807C

/* Total number of registers for dvbt2 */
#define DVBT2_REG_TOTALREG ((125) + TV_REG_NUM_COMMON_REG)


#endif /* _dvbt2_H_ */

