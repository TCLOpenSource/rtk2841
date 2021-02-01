/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _dvbs2_H_
#define _dvbs2_H_

/* DVBS2 Major and Minor version numbers */
//#define DVBS2_VERSION_MAJOR 0x01
//#define DVBS2_VERSION_MINOR 0x00

/* Baud Rate */
#define DVBS2_REG_BAUD_RATE 0x8000

/* Modulation */
#define DVBS2_REG_MODULATION 0x8001

/* Code Rate */
#define DVBS2_REG_CODE_RATE 0x8002

/* Pilots Present */
#define DVBS2_REG_PILOTS_PRESENT 0x8003

/* RRC Rolloff Factor */
#define DVBS2_REG_RRC_ROLLOFF_FACTOR 0x8004

/* Active Baud Rate */
#define DVBS2_REG_ACTIVE_BAUD_RATE 0x8005

/* Active Modulation */
#define DVBS2_REG_ACTIVE_MODULATION 0x8006

/* Active Code Rate */
#define DVBS2_REG_ACTIVE_CODE_RATE 0x8007

/* Detected Pilots Present */
#define DVBS2_REG_ACTIVE_PILOTS_PRESENT 0x8008

/* Active RRC Rolloff Factor */
#define DVBS2_REG_ACTIVE_ROLLOFF_FACTOR 0x8009

/* Measured Frame Error Rate at LDPC Output */
#define DVBS2_REG_FER_AT_LDPC_OUTPUT 0x800A

/* Measured Bit Error Rate at BCH Decoder Input */
#define DVBS2_REG_BER_AT_BCH_INPUT 0x800B

/* Measured frame Error Rate at BCH Decoder Output */
#define DVBS2_REG_FER_AT_BCH_OUTPUT 0x800C

/* Measured Packet Error Rate at System Output */
#define DVBS2_REG_PER_AT_OUTPUT 0x800D

/* Number of Seconds of Bit Error Rate Averaging */
#define DVBS2_REG_NUM_SECONDS_BER_AVERAGING 0x800E

/* Transport Stream Packet Count */
#define DVBS2_REG_TS_PACKET_COUNT 0x800F

/* Errored Transport Stream Packet Count */
#define DVBS2_REG_BAD_PACKET_COUNT 0x8010

/* Output Bit Rate */
#define DVBS2_REG_BIT_RATE 0x8011

/* Signal to Noise Ratio */
#define DVBS2_REG_SNR_ESTIMATE 0x8012

/* Carrier Frequency Search Range */
#define DVBS2_CARRIER_FREQ_SEARCH_RANGE 0x8013

/* Symbol Rate Search Range */
#define DVBS2_SYMBOL_RATE_SEARCH_RANGE 0x8014

/* Signal Acquisition State */
#define DVBS2_REG_ACQUISITION_STATE 0x8015

/* Signal Acquisition Count */
#define DVBS2_REG_NUM_ACQUISITIONS 0x8016

/* Signal Acquisition Failure Code */
#define DVBS2_REG_ACQUISITION_FAILURE_CODE 0x8017

/* I amplitude */
#define DVBS2_REG_I_AMP 0x8019

/* Q amplitude */
#define DVBS2_REG_Q_AMP 0x801A

/* Analog Gain */
#define DVBS2_REG_ANALOG_GAIN 0x801B

/* Digital Gain */
#define DVBS2_REG_DIGITAL_GAIN 0x801C

/* Acquisition Time */
#define DVBS2_REG_ACQUISITION_TIME 0x801D

/* Carrier Frequency Offset */
#define DVBS2_REG_CARRIER_FREQ_OFFSET 0x801E

/* PHY Control */
#define DVBS2_REG_CTRL 0x801F

/* Manual DFE Coefficients */
#define DVBS2_REG_MANUAL_DFE_COEFFS00 0x8020
#define DVBS2_REG_MANUAL_DFE_COEFFS01 0x8021
#define DVBS2_REG_MANUAL_DFE_COEFFS02 0x8022
#define DVBS2_REG_MANUAL_DFE_COEFFS03 0x8023
#define DVBS2_REG_MANUAL_DFE_COEFFS04 0x8024
#define DVBS2_REG_MANUAL_DFE_COEFFS05 0x8025
#define DVBS2_REG_MANUAL_DFE_COEFFS06 0x8026
#define DVBS2_REG_MANUAL_DFE_COEFFS07 0x8027
#define DVBS2_REG_MANUAL_DFE_COEFFS08 0x8028
#define DVBS2_REG_MANUAL_DFE_COEFFS09 0x8029
#define DVBS2_REG_MANUAL_DFE_COEFFS10 0x802A
#define DVBS2_REG_MANUAL_DFE_COEFFS11 0x802B
#define DVBS2_REG_MANUAL_DFE_COEFFS12 0x802C
#define DVBS2_REG_MANUAL_DFE_COEFFS13 0x802D
#define DVBS2_REG_MANUAL_DFE_COEFFS14 0x802E
#define DVBS2_REG_MANUAL_DFE_COEFFS15 0x802F

/* Spectrum Inversion */
#define DVBS2_REG_SPECTRUM_INVERSION 0x8030

/* Detected Spectrum Inversion */
#define DVBS2_REG_ACTIVE_SPECTRUM_INVERSION 0x8031

/* Tone detection control */
#define DVBS2_REG_TONE_DETECT_CTRL 0x8032

/* Tone detection values */
#define DVBS2_REG_TONE_DETECT_VALUE 0x8033

/* Tuned Frequency Offset */
#define DVBS2_REG_TUNED_FREQ_OFFSET 0x8034

/* Set tuner frequency request */
#define DVBS2_REG_TUNE_REQUEST 0x8035

/* Set tuner bandwidth request */
#define DVBS2_REG_BW_REQUEST 0x8036

/* Meta logging pointer */
#define DVBS2_REG_DEBUG_PTR 0x8037

/* Meta logging pointer */
#define DVBS2_REG_META_LOG_PTR 0x8038

/* MCP logging pointer */
#define DVBS2_REG_MCP_LOG_PTR 0x8039

/* DCP logging pointer */
#define DVBS2_REG_TRACE_BUFF_PTR 0x803A

/* LDPC job counter */
#define DVBS2_REG_LDPC_JOB_COUNT 0x803B

/* LDPC job errors */
#define DVBS2_REG_LDPC_JOB_ERRORS 0x803C

/* Set this indicator to tell the PHY software that blind scan is in use. */
#define DVBS2_REG_BLIND_SCAN_IN_USE 0x803D

/* Estimated cut-off point at the left side of the spectrum. */
#define DVBS2_REG_COARSE_SPECTRUM_CUTOFF_LEFT 0x803E

/* Estimated cut-off point at the right side of the spectrum */
#define DVBS2_REG_COARSE_SPECTRUM_CUTOFF_RIGHT 0x803F

/* Estimated coarse carrier frequency offset based on the spectrum. */
#define DVBS2_REG_COARSE_CFO 0x8040

/* Estimated coarse baud rate based on the spectrum. */
#define DVBS2_REG_COARSE_BAUD_RATE 0x8041

/* DFE Phase tracker state */
#define DVBS2_REG_PHASE_TRACK_STATE 0x8042

/* DFE Phase tracker override control. Override the default core and clip levels */
#define DVBS2_REG_PHASE_TRACK_CTRL_QPSK 0x8043

/* DFE Phase tracker override control. Override the default core and clip levels. */
#define DVBS2_REG_PHASE_TRACK_CTRL_8PSK 0x8044

/* DFE Phase tracker override control. Override the default gain when the mode is not FIXED */
#define DVBS2_REG_PHASE_TRACK_GAIN_CTRL_QPSK 0x8045

/* DFE Phase tracker override control. Override the default gain when the mode is not FIXED */
#define DVBS2_REG_PHASE_TRACK_GAIN_CTRL_8PSK 0x8046

/* Phase error threshold for data, headers and pilot bursts. If the phase error exceeds the specified threshold then the phase error is set to zero. */
#define DVBS2_REG_PHASE_ERROR_THRESH_QPSK 0x8047

/* Phase error threshold for data, headers and pilot bursts. If the phase error exceeds the specified threshold then the phase error is set to zero. */
#define DVBS2_REG_PHASE_ERROR_THRESH_8PSK 0x8048

/* Detected S2 frame length type. */
#define DVBS2_DETECTED_FRAME_LENGTH 0x8049

/* Sample Frequency Offset */
#define DVBS2_REG_SAMPLE_FREQ_OFFSET_PPM 0x804A

/* Interferer notch status */
#define DVBS2_REG_INTERFERER_NOTCH_STATUS 0x804B

/* Interferer notch frequency offset in Hz */
#define DVBS2_REG_INTERFERER_NOTCH_FREQ_OFFSET 0x804C

/* Interferer detection sample peak in dB */
#define DVBS2_REG_INTERFERER_DETECT_PEAK_DB 0x804D

/* Interferer detection samples mean in dB */
#define DVBS2_REG_INTERFERER_DETECT_MEAN_DB 0x804E

/* CFO pull-in range for low symbol rates */
#define DVBS2_REG_CFO_PULL_IN_RANGE_LOW_SYM_RATES 0x804F

/* CFO pull-in range for medium symbol rates */
#define DVBS2_REG_CFO_PULL_IN_RANGE_MEDIUM_SYM_RATES 0x8050

/* CFO pull-in range for high symbol rates */
#define DVBS2_REG_CFO_PULL_IN_RANGE_HIGH_SYM_RATES 0x8051

/* Tolerance for symbol rate error when not in blind scan mode */
#define DVBS2_REG_SYM_RATE_TOLERANCE_PPM 0x8052

/* Total number of registers for dvbs2. Note that this has been manually edited until the tool gets sorted to generate register sets with a gap. */
#define DVBS2_REG_TOTALREG ((83) + TV_REG_NUM_COMMON_REG)


#endif /* _dvbs2_H_ */

