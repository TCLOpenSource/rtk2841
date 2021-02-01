/**** THIS FILE IS AUTO GENRATED BY THE xml2reg TOOL ****/

#ifndef _dvbs_H_
#define _dvbs_H_

/* DVBS Major and Minor version numbers */
//#define DVBS_VERSION_MAJOR 0x01
//#define DVBS_VERSION_MINOR 0x00

/* Baud Rate */
#define DVBS_REG_BAUD_RATE 0x8000

/* Code Rate */
#define DVBS_REG_CODE_RATE 0x8001

/* Active Baud Rate */
#define DVBS_REG_ACTIVE_BAUD_RATE 0x8002

/* Active Code Rate */
#define DVBS_REG_ACTIVE_CODE_RATE 0x8003

/* Measured Bit Error Rate at Viterbi Input */
#define DVBS_REG_BER_AT_VITERBI_INPUT 0x8004

/* Measured Bit Error Rate at Reed-Solomon Decoder Input */
#define DVBS_REG_BER_AT_RS_INPUT 0x8005

/* Measured Packet Error Rate at System Output */
#define DVBS_REG_PER_AT_OUTPUT 0x8006

/* Number of Seconds of Bit Error Rate Averaging */
#define DVBS_REG_NUM_SECONDS_BER_AVERAGING 0x8007

/* Transport Stream Packet Count */
#define DVBS_REG_TS_PACKET_COUNT 0x8008

/* Errored Transport Stream Packet Count */
#define DVBS_REG_BAD_PACKET_COUNT 0x8009

/* Output Bit Rate */
#define DVBS_REG_BIT_RATE 0x800A

/* Signal to Noise Ratio */
#define DVBS_REG_SNR_ESTIMATE 0x800B

/* Carrier Frequency Search Range */
#define DVBS_CARRIER_FREQ_SEARCH_RANGE 0x800C

/* Symbol Rate Search Range */
#define DVBS_SYMBOL_RATE_SEARCH_RANGE 0x800D

/* Signal Acquisition State */
#define DVBS_REG_ACQUISITION_STATE 0x800E

/* Signal Acquisition Count */
#define DVBS_REG_NUM_ACQUISITIONS 0x800F

/* Signal Acquisition Failure Code */
#define DVBS_REG_ACQUISITION_FAILURE_CODE 0x8010

/* I amplitude */
#define DVBS_REG_I_AMP 0x8012

/* Q amplitude */
#define DVBS_REG_Q_AMP 0x8013

/* Analog Gain */
#define DVBS_REG_ANALOG_GAIN 0x8014

/* Digital Gain */
#define DVBS_REG_DIGITAL_GAIN 0x8015

/* Acquisition Time */
#define DVBS_REG_ACQUISITION_TIME 0x8016

/* Carrier Frequency Offset */
#define DVBS_REG_CARRIER_FREQ_OFFSET 0x8017

/* PHY Control */
#define DVBS_REG_CTRL 0x8018

/* Manual DFE Coefficients */
#define DVBS_REG_MANUAL_DFE_COEFFS00 0x8019
#define DVBS_REG_MANUAL_DFE_COEFFS01 0x801A
#define DVBS_REG_MANUAL_DFE_COEFFS02 0x801B
#define DVBS_REG_MANUAL_DFE_COEFFS03 0x801C
#define DVBS_REG_MANUAL_DFE_COEFFS04 0x801D
#define DVBS_REG_MANUAL_DFE_COEFFS05 0x801E
#define DVBS_REG_MANUAL_DFE_COEFFS06 0x801F
#define DVBS_REG_MANUAL_DFE_COEFFS07 0x8020
#define DVBS_REG_MANUAL_DFE_COEFFS08 0x8021
#define DVBS_REG_MANUAL_DFE_COEFFS09 0x8022
#define DVBS_REG_MANUAL_DFE_COEFFS10 0x8023
#define DVBS_REG_MANUAL_DFE_COEFFS11 0x8024
#define DVBS_REG_MANUAL_DFE_COEFFS12 0x8025
#define DVBS_REG_MANUAL_DFE_COEFFS13 0x8026
#define DVBS_REG_MANUAL_DFE_COEFFS14 0x8027
#define DVBS_REG_MANUAL_DFE_COEFFS15 0x8028

/* Spectrum Inversion */
#define DVBS_REG_SPECTRUM_INVERSION 0x8029

/* Detected Spectrum Inversion */
#define DVBS_REG_ACTIVE_SPECTRUM_INVERSION 0x802A

/* Tone detection control */
#define DVBS_REG_TONE_DETECT_CTRL 0x802B

/* Tone detection values */
#define DVBS_REG_TONE_DETECT_VALUE 0x802C

/* Tuned Frequency Offset */
#define DVBS_REG_TUNED_FREQ_OFFSET 0x802D

/* Set tuner frequency request */
#define DVBS_REG_TUNE_REQUEST 0x802E

/* Set tuner bandwidth request */
#define DVBS_REG_BW_REQUEST 0x802F

/* Meta logging pointer */
#define DVBS_REG_DEBUG_PTR 0x8030

/* Meta logging pointer */
#define DVBS_REG_META_LOG_PTR 0x8031

/* MCP logging pointer */
#define DVBS_REG_MCP_LOG_PTR 0x8032

/* DCP logging pointer */
#define DVBS_REG_TRACE_BUFF_PTR 0x8033

/* Set this indicator to tell the PHY software that blind scan is in use. */
#define DVBS_REG_BLIND_SCAN_IN_USE 0x8034

/* Viterbi iterative mode elimination coefficients for pass 2. */
#define DVBS_REG_ELIM_COEFF_VITERBI_ITER_MODE_PASS2 0x8035

/* Viterbi iterative mode elimination coefficients for pass 3. */
#define DVBS_REG_ELIM_COEFF_VITERBI_ITER_MODE_PASS3 0x8036

/* Estimated cut-off point at the left side of the spectrum. */
#define DVBS_REG_COARSE_SPECTRUM_CUTOFF_LEFT 0x8037

/* Estimated cut-off point at the right side of the spectrum */
#define DVBS_REG_COARSE_SPECTRUM_CUTOFF_RIGHT 0x8038

/* Estimated coarse carrier frequency offset based on the spectrum. */
#define DVBS_REG_COARSE_CFO 0x8039

/* Estimated coarse baud rate based on the spectrum. */
#define DVBS_REG_COARSE_BAUD_RATE 0x803A

/* DFE Phase tracker state */
#define DVBS_REG_PHASE_TRACK_STATE 0x803B

/* DFE Phase tracker override control. Override the default core and clip levels. */
#define DVBS_REG_PHASE_TRACK_CTRL_QPSK 0x803C

/* DFE Phase tracker override control. Override the default gain when the mode is not FIXED */
#define DVBS_REG_PHASE_TRACK_GAIN_CTRL_QPSK 0x803D

/* Phase error threshold for data. If the phase error exceeds the specified threshold then the phase error is set to zero. */
#define DVBS_REG_PHASE_ERROR_THRESH_QPSK 0x803E

/* Sample Frequency Offset */
#define DVBS_REG_SAMPLE_FREQ_OFFSET_PPM 0x803F

/* Interferer notch status */
#define DVBS_REG_INTERFERER_NOTCH_STATUS 0x8040

/* Interferer notch frequency offset in Hz */
#define DVBS_REG_INTERFERER_NOTCH_FREQ_OFFSET 0x8041

/* Interferer detection sample peak in dB */
#define DVBS_REG_INTERFERER_DETECT_PEAK_DB 0x8042

/* Interferer detection samples mean in dB */
#define DVBS_REG_INTERFERER_DETECT_MEAN_DB 0x8043

/* CFO pull-in range for low symbol rates */
#define DVBS_REG_CFO_PULL_IN_RANGE_LOW_SYM_RATES 0x8044

/* CFO pull-in range for medium symbol rates */
#define DVBS_REG_CFO_PULL_IN_RANGE_MEDIUM_SYM_RATES 0x8045

/* CFO pull-in range for high symbol rates */
#define DVBS_REG_CFO_PULL_IN_RANGE_HIGH_SYM_RATES 0x8046

/* Tolerance for symbol rate error when not in blind scan mode */
#define DVBS_REG_SYM_RATE_TOLERANCE_PPM 0x8047

/* Total number of registers for dvbs. Note that this has been manually edited until the tool gets sorted to generate register sets with a gap. */
#define DVBS_REG_TOTALREG ((72) + TV_REG_NUM_COMMON_REG)


#endif /* _dvbs_H_ */

