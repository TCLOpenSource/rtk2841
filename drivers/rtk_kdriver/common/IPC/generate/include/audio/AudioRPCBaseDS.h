/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _AUDIORPCBASEDS_H_RPCGEN
#define _AUDIORPCBASEDS_H_RPCGEN

#include <rt/misc/RPCstruct.h>

#include "AudioRPCBaseDS_data.h"

#ifdef __cplusplus
extern "C" {
#endif

#define printf(str)

#include <rpc_common.h>

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_AUDIO_DEC_TYPE (XDR *, AUDIO_DEC_TYPE*);
extern  bool_t xdr_AUDIO_CHANNEL_OUT_INDEX (XDR *, AUDIO_CHANNEL_OUT_INDEX*);
extern  bool_t xdr_AUDIO_MODULE_TYPE (XDR *, AUDIO_MODULE_TYPE*);
extern  bool_t xdr_AUDIO_IO_PIN (XDR *, AUDIO_IO_PIN*);
extern  bool_t xdr_ENUM_AUDIO_BILINGUAL_TYPE (XDR *, ENUM_AUDIO_BILINGUAL_TYPE*);
extern  bool_t xdr_ENUM_AUDIO_NIGHTMODE_CFG (XDR *, ENUM_AUDIO_NIGHTMODE_CFG*);
extern  bool_t xdr_AUDIO_RPC_NIGHTMODE (XDR *, AUDIO_RPC_NIGHTMODE*);
extern  bool_t xdr_AUDIO_RPC_PP_AGC (XDR *, AUDIO_RPC_PP_AGC*);
extern  bool_t xdr_ENUM_AUDIO_AGC_TYPE (XDR *, ENUM_AUDIO_AGC_TYPE*);
extern  bool_t xdr_ENUM_AUDIO_DAC_SWITCH_CFG (XDR *, ENUM_AUDIO_DAC_SWITCH_CFG*);
extern  bool_t xdr_ENUM_AUDIO_TRUEHD_LOSSLESSMODE_CFG (XDR *, ENUM_AUDIO_TRUEHD_LOSSLESSMODE_CFG*);
extern  bool_t xdr_AUDIO_RPC_TRUEHD_LOSSLESSMODE (XDR *, AUDIO_RPC_TRUEHD_LOSSLESSMODE*);
extern  bool_t xdr_ENUM_AUDIO_DELAY_DAC_SWITCH_CFG (XDR *, ENUM_AUDIO_DELAY_DAC_SWITCH_CFG*);
extern  bool_t xdr_ENUM_AUDIO_IPT_SRC (XDR *, ENUM_AUDIO_IPT_SRC*);
extern  bool_t xdr_ENUM_AUDIO_BBADC_SRC (XDR *, ENUM_AUDIO_BBADC_SRC*);
extern  bool_t xdr_ENUM_AUDIO_SPDIFI_SRC (XDR *, ENUM_AUDIO_SPDIFI_SRC*);
extern  bool_t xdr_ENUM_AUDIO_I2SI_SRC (XDR *, ENUM_AUDIO_I2SI_SRC*);
extern  bool_t xdr_ENUM_AUDIO_I2SI_ID (XDR *, ENUM_AUDIO_I2SI_ID*);
extern  bool_t xdr_ENUM_AUDIO_I2SI_MODE (XDR *, ENUM_AUDIO_I2SI_MODE*);
extern  bool_t xdr_ENUM_AUDIO_I2SI_SYNC (XDR *, ENUM_AUDIO_I2SI_SYNC*);
extern  bool_t xdr_ENUM_AUDIO_BBADC_CLK (XDR *, ENUM_AUDIO_BBADC_CLK*);
extern  bool_t xdr_AUDIO_IPT_SRC (XDR *, AUDIO_IPT_SRC*);
extern  bool_t xdr_AUDIO_RPC_DEC_BITSTREAM_BUFFER (XDR *, AUDIO_RPC_DEC_BITSTREAM_BUFFER*);
extern  bool_t xdr_AUDIO_RPC_FORMAT_INFO (XDR *, AUDIO_RPC_FORMAT_INFO*);
extern  bool_t xdr_AUDIO_PCM_FORMAT (XDR *, AUDIO_PCM_FORMAT*);
extern  bool_t xdr_AUDIO_EXT_BS (XDR *, AUDIO_EXT_BS*);
extern  bool_t xdr_AUDIO_DEC_CFG (XDR *, AUDIO_DEC_CFG*);
extern  bool_t xdr_ENCODE_MODE (XDR *, ENCODE_MODE*);
extern  bool_t xdr_AUDIO_ENC_CFG (XDR *, AUDIO_ENC_CFG*);
extern  bool_t xdr_AUDIO_RPC_INSTANCE (XDR *, AUDIO_RPC_INSTANCE*);
extern  bool_t xdr_AUDIO_RPC_HASH (XDR *, AUDIO_RPC_HASH*);
extern  bool_t xdr_AUDIO_FRAME_BOUNDARY (XDR *, AUDIO_FRAME_BOUNDARY*);
extern  bool_t xdr_AUDIO_RPC_SEND_LONG (XDR *, AUDIO_RPC_SEND_LONG*);
extern  bool_t xdr_AUDIO_RPC_SENDPIN_LONG (XDR *, AUDIO_RPC_SENDPIN_LONG*);
extern  bool_t xdr_AUDIO_RPC_SEEK (XDR *, AUDIO_RPC_SEEK*);
extern  bool_t xdr_AUDIO_RPC_PRIVATEINFO (XDR *, AUDIO_RPC_PRIVATEINFO*);
extern  bool_t xdr_AUDIO_RPC_RINGBUFFER (XDR *, AUDIO_RPC_RINGBUFFER*);
extern  bool_t xdr_AUDIO_RPC_IOBUFFER (XDR *, AUDIO_RPC_IOBUFFER*);
extern  bool_t xdr_AUDIO_RPC_BUFFER (XDR *, AUDIO_RPC_BUFFER*);
extern  bool_t xdr_ENUM_SYSTEM_PROCESS_TYPE (XDR *, ENUM_SYSTEM_PROCESS_TYPE*);
extern  bool_t xdr_SYSTEM_PROCESS_INFO (XDR *, SYSTEM_PROCESS_INFO*);
extern  bool_t xdr_SYSTEM_PROCESS_RES (XDR *, SYSTEM_PROCESS_RES*);
extern  bool_t xdr_AUDIO_RPC_WRITEPACK (XDR *, AUDIO_RPC_WRITEPACK*);
extern  bool_t xdr_AUDIO_RPC_READPACK (XDR *, AUDIO_RPC_READPACK*);
extern  bool_t xdr_AUDIO_RPC_SENDIO (XDR *, AUDIO_RPC_SENDIO*);
extern  bool_t xdr_AUDIO_RPC_SWITCHAGENT (XDR *, AUDIO_RPC_SWITCHAGENT*);
extern  bool_t xdr_AUDIO_RPC_PCMFORMAT (XDR *, AUDIO_RPC_PCMFORMAT*);
extern  bool_t xdr_AUDIO_RPC_FRAME_BOUNDARY (XDR *, AUDIO_RPC_FRAME_BOUNDARY*);
extern  bool_t xdr_AUDIO_RPC_DECCFG (XDR *, AUDIO_RPC_DECCFG*);
extern  bool_t xdr_AUDIO_RPC_EXTBS_EXIST (XDR *, AUDIO_RPC_EXTBS_EXIST*);
extern  bool_t xdr_AUDIO_RPC_CONNECTION (XDR *, AUDIO_RPC_CONNECTION*);
extern  bool_t xdr_AUDIO_RPC_REFCLOCK (XDR *, AUDIO_RPC_REFCLOCK*);
extern  bool_t xdr_AUDIO_RPC_PTS_INFO (XDR *, AUDIO_RPC_PTS_INFO*);
extern  bool_t xdr_AUDIO_RPC_RINGBUFFER_HEADER (XDR *, AUDIO_RPC_RINGBUFFER_HEADER*);
extern  bool_t xdr_AUDIO_RPC_FOCUS (XDR *, AUDIO_RPC_FOCUS*);
extern  bool_t xdr_AUDIO_RPC_SUBCHANNEL (XDR *, AUDIO_RPC_SUBCHANNEL*);
extern  bool_t xdr_ENUM_AUDIO_CHANNEL_IDX (XDR *, ENUM_AUDIO_CHANNEL_IDX*);
extern  bool_t xdr_AUDIO_RPC_AO_FOCUS (XDR *, AUDIO_RPC_AO_FOCUS*);
extern  bool_t xdr_ENUM_AUDIO_CHANNEL_IN (XDR *, ENUM_AUDIO_CHANNEL_IN*);
extern  bool_t xdr_ENUM_AUDIO_CHANNEL_OUT (XDR *, ENUM_AUDIO_CHANNEL_OUT*);
extern  bool_t xdr_AUDIO_GENERAL_CONFIG (XDR *, AUDIO_GENERAL_CONFIG*);
extern  bool_t xdr_AUDIO_SAMPLE_INFO (XDR *, AUDIO_SAMPLE_INFO*);
extern  bool_t xdr_AUDIO_BBADC_CONFIG (XDR *, AUDIO_BBADC_CONFIG*);
extern  bool_t xdr_AUDIO_I2SI_CONFIG (XDR *, AUDIO_I2SI_CONFIG*);
extern  bool_t xdr_AUDIO_SPDIFI_CONFIG (XDR *, AUDIO_SPDIFI_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_IPT_SRC (XDR *, AUDIO_RPC_IPT_SRC*);
extern  bool_t xdr_AUDIO_RPC_SET_ATV_CLOCK (XDR *, AUDIO_RPC_SET_ATV_CLOCK*);
extern  bool_t xdr_AUDIO_RPC_INOUT_CH_SELECT (XDR *, AUDIO_RPC_INOUT_CH_SELECT*);
extern  bool_t xdr_AUDIO_RPC_SET_FS_CLOCKSRC (XDR *, AUDIO_RPC_SET_FS_CLOCKSRC*);
extern  bool_t xdr_AUDIO_RPC_SET_PATH_DATA_OUT (XDR *, AUDIO_RPC_SET_PATH_DATA_OUT*);
extern  bool_t xdr_AUDIO_RPC_AI_SET_OUT_FMT (XDR *, AUDIO_RPC_AI_SET_OUT_FMT*);
extern  bool_t xdr_AUDIO_RPC_SET_INTERLEAVE_OUT (XDR *, AUDIO_RPC_SET_INTERLEAVE_OUT*);
extern  bool_t xdr_AUDIO_RPC_SET_SIF_ADC_INIT (XDR *, AUDIO_RPC_SET_SIF_ADC_INIT*);
extern  bool_t xdr_AUDIO_SPDIF_ERROR (XDR *, AUDIO_SPDIF_ERROR*);
extern  bool_t xdr_AUDIO_ADC_CONFIG (XDR *, AUDIO_ADC_CONFIG*);
extern  bool_t xdr_AUDIO_SPDIF_CONFIG (XDR *, AUDIO_SPDIF_CONFIG*);
extern  bool_t xdr_AUDIO_IN_SOURCE (XDR *, AUDIO_IN_SOURCE*);
extern  bool_t xdr_AUDIO_IN_DATA_MEASURE (XDR *, AUDIO_IN_DATA_MEASURE*);
extern  bool_t xdr_AUDIO_IN_MUTE_INFO (XDR *, AUDIO_IN_MUTE_INFO*);
extern  bool_t xdr_AUDIO_OUT_COPY_SOURCE (XDR *, AUDIO_OUT_COPY_SOURCE*);
extern  bool_t xdr_AUDIO_OUT_SPDIF_SOURCE (XDR *, AUDIO_OUT_SPDIF_SOURCE*);
extern  bool_t xdr_AUDIO_KARAOKE_CONTROL_INFO (XDR *, AUDIO_KARAOKE_CONTROL_INFO*);
extern  bool_t xdr_LINK_BUFFER (XDR *, LINK_BUFFER*);
extern  bool_t xdr_AUDIO_SOUND_EVENT (XDR *, AUDIO_SOUND_EVENT*);
extern  bool_t xdr_AUDIO_HDMI_SET (XDR *, AUDIO_HDMI_SET*);
extern  bool_t xdr_AUDIO_HDMI_MUTE_INFO (XDR *, AUDIO_HDMI_MUTE_INFO*);
extern  bool_t xdr_AUDIO_OUT_MUTE_INFO (XDR *, AUDIO_OUT_MUTE_INFO*);
extern  bool_t xdr_AUDIO_RPC_BBADC_CONFIG (XDR *, AUDIO_RPC_BBADC_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_I2SI_CONFIG (XDR *, AUDIO_RPC_I2SI_CONFIG*);
extern  bool_t xdr_AUDIO_CONFIG_ADC (XDR *, AUDIO_CONFIG_ADC*);
extern  bool_t xdr_AUDIO_CONFIG_AFC (XDR *, AUDIO_CONFIG_AFC*);
extern  bool_t xdr_AUDIO_DROP_SAMPLE (XDR *, AUDIO_DROP_SAMPLE*);
extern  bool_t xdr_AUDIO_P_W_NOISE_CFG (XDR *, AUDIO_P_W_NOISE_CFG*);
extern  bool_t xdr_ENUM_AUDIO_SPECTRUM_BANDNUM (XDR *, ENUM_AUDIO_SPECTRUM_BANDNUM*);
extern  bool_t xdr_AUDIO_SPECTRUM_CFG (XDR *, AUDIO_SPECTRUM_CFG*);
extern  bool_t xdr_AUDIO_VOLUME_CONTROL (XDR *, AUDIO_VOLUME_CONTROL*);
extern  bool_t xdr_AUDIO_RPC_SPDIFI_CONFIG (XDR *, AUDIO_RPC_SPDIFI_CONFIG*);
extern  bool_t xdr_AUDIO_CONFIG_SPDIF (XDR *, AUDIO_CONFIG_SPDIF*);
extern  bool_t xdr_AUDIO_CONFIG_SPDIF_ERR (XDR *, AUDIO_CONFIG_SPDIF_ERR*);
extern  bool_t xdr_AUDIO_BACKDOOR_AI_INIT (XDR *, AUDIO_BACKDOOR_AI_INIT*);
extern  bool_t xdr_AUDIO_OUT_GENERAL_CONFIG (XDR *, AUDIO_OUT_GENERAL_CONFIG*);
extern  bool_t xdr_AUDIO_OUT_CS_INFO (XDR *, AUDIO_OUT_CS_INFO*);
extern  bool_t xdr_AUDIO_DAC_CONFIG (XDR *, AUDIO_DAC_CONFIG*);
extern  bool_t xdr_AUDIO_OUT_SPDIF_CONFIG (XDR *, AUDIO_OUT_SPDIF_CONFIG*);
extern  bool_t xdr_AUDIO_CONFIG_DAC_I2S (XDR *, AUDIO_CONFIG_DAC_I2S*);
extern  bool_t xdr_AUDIO_CONFIG_DAC_SPDIF (XDR *, AUDIO_CONFIG_DAC_SPDIF*);
extern  bool_t xdr_AUDIO_RPC_SPDIF_CHANNEL_STATUS (XDR *, AUDIO_RPC_SPDIF_CHANNEL_STATUS*);
extern  bool_t xdr_ENUM_DVD_AUDIO_ENCODER_OUTPUT_INFO_TYPE (XDR *, ENUM_DVD_AUDIO_ENCODER_OUTPUT_INFO_TYPE*);
extern  bool_t xdr_AUDIO_RPC_ENC_ELEM_GENERAL_INFO (XDR *, AUDIO_RPC_ENC_ELEM_GENERAL_INFO*);
extern  bool_t xdr_AUDIO_RPC_ENC_ELEM_FRAME_INFO (XDR *, AUDIO_RPC_ENC_ELEM_FRAME_INFO*);
extern  bool_t xdr_ENUM_AUDIO_AIN_INFO_TYPE (XDR *, ENUM_AUDIO_AIN_INFO_TYPE*);
extern  bool_t xdr_AUDIO_RPC_AIN_ELEM_FRAME_INFO (XDR *, AUDIO_RPC_AIN_ELEM_FRAME_INFO*);
extern  bool_t xdr_AUDIO_RPC_DEC_GENERAL_INFO (XDR *, AUDIO_RPC_DEC_GENERAL_INFO*);
extern  bool_t xdr_AUDIO_RPC_DEC_FRAME_INFO (XDR *, AUDIO_RPC_DEC_FRAME_INFO*);
extern  bool_t xdr_AUDIO_RPC_ERROR (XDR *, AUDIO_RPC_ERROR*);
extern  bool_t xdr_AUDIO_RPC_MASTERSHIP (XDR *, AUDIO_RPC_MASTERSHIP*);
extern  bool_t xdr_AUDIO_RPC_ENC_SOURCEFILE (XDR *, AUDIO_RPC_ENC_SOURCEFILE*);
extern  bool_t xdr_AUDIO_PP_FUNCTION (XDR *, AUDIO_PP_FUNCTION*);
extern  bool_t xdr_AUDIO_PP_FUNCTION_MODE (XDR *, AUDIO_PP_FUNCTION_MODE*);
extern  bool_t xdr_AUDIO_PP_CONFIG (XDR *, AUDIO_PP_CONFIG*);
extern  bool_t xdr_AUDIO_PROLOGIC2_MODE (XDR *, AUDIO_PROLOGIC2_MODE*);
extern  bool_t xdr_ENUM_PROLOGIC2_ENA (XDR *, ENUM_PROLOGIC2_ENA*);
extern  bool_t xdr_ENUM_AI_PATH (XDR *, ENUM_AI_PATH*);
extern  bool_t xdr_AUDIO_PROLOGIC2_CONFIG (XDR *, AUDIO_PROLOGIC2_CONFIG*);
extern  bool_t xdr_ENUM_SRC_MODE (XDR *, ENUM_SRC_MODE*);
extern  bool_t xdr_AUDIO_SRC_CONFIG (XDR *, AUDIO_SRC_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_MIXER_MODE (XDR *, AUDIO_RPC_MIXER_MODE*);
extern  bool_t xdr_AUDIO_MIXER_CONFIG (XDR *, AUDIO_MIXER_CONFIG*);
extern  bool_t xdr_AUDIO_PTS_MIXER (XDR *, AUDIO_PTS_MIXER*);
extern  bool_t xdr_AUDIO_PTS_MIXER (XDR *, AUDIO_PTS_MIXER*);
extern  bool_t xdr_AUDIO_RPC_PTS_MIXER_CONFIG (XDR *, AUDIO_RPC_PTS_MIXER_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_PTS_MIXER_CONFIG (XDR *, AUDIO_RPC_PTS_MIXER_CONFIG*);
extern  bool_t xdr_ENUM_EQUALIZER_GAIN (XDR *, ENUM_EQUALIZER_GAIN*);
extern  bool_t xdr_ENUM_EQUALIZER_MODE (XDR *, ENUM_EQUALIZER_MODE*);
extern  bool_t xdr_AUDIO_RPC_EQUALIZER_MODE (XDR *, AUDIO_RPC_EQUALIZER_MODE*);
extern  bool_t xdr_ENUM_EQUALIZER_ENA (XDR *, ENUM_EQUALIZER_ENA*);
extern  bool_t xdr_ENUM_GBL_VAR_EQUALIZER_ID (XDR *, ENUM_GBL_VAR_EQUALIZER_ID*);
extern  bool_t xdr_AUDIO_EQUALIZER_CONFIG (XDR *, AUDIO_EQUALIZER_CONFIG*);
extern  bool_t xdr_ENUM_BASS_MANAGEMENT_CUTOFFFREQ (XDR *, ENUM_BASS_MANAGEMENT_CUTOFFFREQ*);
extern  bool_t xdr_ENUM_BASS_MANAGEMENT_MODE (XDR *, ENUM_BASS_MANAGEMENT_MODE*);
extern  bool_t xdr_ENUM_BASS_MANAGEMENT_SUBWOOFER_ENA (XDR *, ENUM_BASS_MANAGEMENT_SUBWOOFER_ENA*);
extern  bool_t xdr_AUDIO_RPC_BASS_MANAGEMENT_MODE (XDR *, AUDIO_RPC_BASS_MANAGEMENT_MODE*);
extern  bool_t xdr_ENUM_BASS_MANAGEMENT_ENA (XDR *, ENUM_BASS_MANAGEMENT_ENA*);
extern  bool_t xdr_AUDIO_BASS_MANAGEMENT_CONFIG (XDR *, AUDIO_BASS_MANAGEMENT_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_DVS_MODE (XDR *, AUDIO_RPC_DVS_MODE*);
extern  bool_t xdr_ENUM_DVS_ENA (XDR *, ENUM_DVS_ENA*);
extern  bool_t xdr_AUDIO_DVS_CONFIG (XDR *, AUDIO_DVS_CONFIG*);
extern  bool_t xdr_ENUM_KEY_SHIFT_ENA (XDR *, ENUM_KEY_SHIFT_ENA*);
extern  bool_t xdr_ENUM_KEY_SHIFT_STONE (XDR *, ENUM_KEY_SHIFT_STONE*);
extern  bool_t xdr_AUDIO_KEY_SHIFT_CONFIG (XDR *, AUDIO_KEY_SHIFT_CONFIG*);
extern  bool_t xdr_ENUM_REVERB_ENA (XDR *, ENUM_REVERB_ENA*);
extern  bool_t xdr_ENUM_REVERB_MODE (XDR *, ENUM_REVERB_MODE*);
extern  bool_t xdr_AUDIO_REVERB_CONFIG (XDR *, AUDIO_REVERB_CONFIG*);
extern  bool_t xdr_ENUM_VOCAL_REMOVER_ENA (XDR *, ENUM_VOCAL_REMOVER_ENA*);
extern  bool_t xdr_ENUM_VOCAL_REMOVER_MODE (XDR *, ENUM_VOCAL_REMOVER_MODE*);
extern  bool_t xdr_AUDIO_VOCAL_REMOVER_CONFIG (XDR *, AUDIO_VOCAL_REMOVER_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_DEC_INIT (XDR *, AUDIO_RPC_DEC_INIT*);
extern  bool_t xdr_AUDIO_RPC_ENC_INIT (XDR *, AUDIO_RPC_ENC_INIT*);
extern  bool_t xdr_AUDIO_RPC_ENC_SET_BITRATE (XDR *, AUDIO_RPC_ENC_SET_BITRATE*);
extern  bool_t xdr_AUDIO_RPC_ENC_COMMAND (XDR *, AUDIO_RPC_ENC_COMMAND*);
extern  bool_t xdr_AUDIO_RPC_DEBUG_MEMORY (XDR *, AUDIO_RPC_DEBUG_MEMORY*);
extern  bool_t xdr_AUDIO_RPC_ENC_INFO (XDR *, AUDIO_RPC_ENC_INFO*);
extern  bool_t xdr_AUDIO_RPC_ENC_DV_MIXER (XDR *, AUDIO_RPC_ENC_DV_MIXER*);
extern  bool_t xdr_AUDIO_RPC_AO_INIT (XDR *, AUDIO_RPC_AO_INIT*);
extern  bool_t xdr_AUDIO_RPC_AO_SET_EQUALIZER (XDR *, AUDIO_RPC_AO_SET_EQUALIZER*);
extern  bool_t xdr_AUDIO_AO_RPC_CONFIG_DELAY_CONTROL (XDR *, AUDIO_AO_RPC_CONFIG_DELAY_CONTROL*);
extern  bool_t xdr_AUDIO_RPC_AO_CONFIG_KARAOKE (XDR *, AUDIO_RPC_AO_CONFIG_KARAOKE*);
extern  bool_t xdr_AUDIO_RPC_AO_MIXER (XDR *, AUDIO_RPC_AO_MIXER*);
extern  bool_t xdr_AUDIO_RPC_PP_CFG (XDR *, AUDIO_RPC_PP_CFG*);
extern  bool_t xdr_AUDIO_RPC_PP_MUTE (XDR *, AUDIO_RPC_PP_MUTE*);
extern  bool_t xdr_AUDIO_RPC_AO_DAC (XDR *, AUDIO_RPC_AO_DAC*);
extern  bool_t xdr_AUDIO_RPC_PP_PROLOGIC (XDR *, AUDIO_RPC_PP_PROLOGIC*);
extern  bool_t xdr_AUDIO_AGC_MODE (XDR *, AUDIO_AGC_MODE*);
extern  bool_t xdr_AUDIO_KARAOKE_MODE (XDR *, AUDIO_KARAOKE_MODE*);
extern  bool_t xdr_AUDIO_EASE_TYPE (XDR *, AUDIO_EASE_TYPE*);
extern  bool_t xdr_AUDIO_CONFIG_CMD_MSG (XDR *, AUDIO_CONFIG_CMD_MSG*);
extern  bool_t xdr_AUDIO_DTS_DEC_PARAM_TYPE (XDR *, AUDIO_DTS_DEC_PARAM_TYPE*);
extern  bool_t xdr_AUDIO_DBX_DEBUG_CMD (XDR *, AUDIO_DBX_DEBUG_CMD*);
extern  bool_t xdr_AUDIO_DBXTV_PARAM_TYPE (XDR *, AUDIO_DBXTV_PARAM_TYPE*);
extern  bool_t xdr_AUDIO_DBXTV_TABLE (XDR *, AUDIO_DBXTV_TABLE*);
extern  bool_t xdr_AUDIO_DBXTV_TotSonMode (XDR *, AUDIO_DBXTV_TotSonMode*);
extern  bool_t xdr_AUDIO_DBXTV_TotVolMode (XDR *, AUDIO_DBXTV_TotVolMode*);
extern  bool_t xdr_AUDIO_DBXTV_TotSurMode (XDR *, AUDIO_DBXTV_TotSurMode*);
extern  bool_t xdr_AUDIO_DBXTV_SAMPLE_RATE (XDR *, AUDIO_DBXTV_SAMPLE_RATE*);
extern  bool_t xdr_AUDIO_DBXTV_TABLE_INFO (XDR *, AUDIO_DBXTV_TABLE_INFO*);
extern  bool_t xdr_AUDIO_CONFIG_LGSE (XDR *, AUDIO_CONFIG_LGSE*);
extern  bool_t xdr_AUDIO_CONFIG_DEVICE (XDR *, AUDIO_CONFIG_DEVICE*);
extern  bool_t xdr_AUDIO_CONFIG_AIO (XDR *, AUDIO_CONFIG_AIO*);
extern  bool_t xdr_AUDIO_CUSTOMIZE_REQUEST (XDR *, AUDIO_CUSTOMIZE_REQUEST*);
extern  bool_t xdr_AUDIO_CONFIG_COMMAND (XDR *, AUDIO_CONFIG_COMMAND*);
extern  bool_t xdr_AUDISTRY_FEATURE_CMD_MSG (XDR *, AUDISTRY_FEATURE_CMD_MSG*);
extern  bool_t xdr_AUDISTRY_TWOUP_PARAMETER (XDR *, AUDISTRY_TWOUP_PARAMETER*);
extern  bool_t xdr_AUDISTRY_HEADSPACE_PARAMETER (XDR *, AUDISTRY_HEADSPACE_PARAMETER*);
extern  bool_t xdr_AUDISTRY_STEREOWRAPPER_PARAMETER (XDR *, AUDISTRY_STEREOWRAPPER_PARAMETER*);
extern  bool_t xdr_AUDISTRY_LATENIGHT_PARAMETER (XDR *, AUDISTRY_LATENIGHT_PARAMETER*);
extern  bool_t xdr_AUDISTRY_VOLUME_PARAMETER (XDR *, AUDISTRY_VOLUME_PARAMETER*);
extern  bool_t xdr_AUDISTRY_RUMBLER_PARAMETER (XDR *, AUDISTRY_RUMBLER_PARAMETER*);
extern  bool_t xdr_AUDISTRY_CONFIG_COMMAND (XDR *, AUDISTRY_CONFIG_COMMAND*);
extern  bool_t xdr_AUDIO_AO_MIC_CONFIG (XDR *, AUDIO_AO_MIC_CONFIG*);
extern  bool_t xdr_AUDIO_AO_AUX_CONFIG (XDR *, AUDIO_AO_AUX_CONFIG*);
extern  bool_t xdr_AUDIO_AO_ECHO_REVERB_CONFIG (XDR *, AUDIO_AO_ECHO_REVERB_CONFIG*);
extern  bool_t xdr_AUDIO_RPC_ECHO_MODE (XDR *, AUDIO_RPC_ECHO_MODE*);
extern  bool_t xdr_AUDIO_AO_ECHO_DELAY_MODE (XDR *, AUDIO_AO_ECHO_DELAY_MODE*);
extern  bool_t xdr_AUDIO_HDMI_CODING_TYPE (XDR *, AUDIO_HDMI_CODING_TYPE*);
extern  bool_t xdr_AUDIO_HDMI_CHANNEL_COUNT (XDR *, AUDIO_HDMI_CHANNEL_COUNT*);
extern  bool_t xdr_AUDIO_HDMI_SAMPLING_FREQ (XDR *, AUDIO_HDMI_SAMPLING_FREQ*);
extern  bool_t xdr_AUDIO_HDMI_SAMPLE_SIZE (XDR *, AUDIO_HDMI_SAMPLE_SIZE*);
extern  bool_t xdr_AUDIO_HDMI_SETTING_INFO (XDR *, AUDIO_HDMI_SETTING_INFO*);
extern  bool_t xdr_ENUM_AUDIO_HDMI_EDID_ENABLE (XDR *, ENUM_AUDIO_HDMI_EDID_ENABLE*);
extern  bool_t xdr_AUDIO_HDMI_OUT_EDID_DATA (XDR *, AUDIO_HDMI_OUT_EDID_DATA*);
extern  bool_t xdr_AUDIO_HDMI_OUT_EDID_DATA2 (XDR *, AUDIO_HDMI_OUT_EDID_DATA2*);
extern  bool_t xdr_AUDIO_HDMI_OUT_VSDB_DATA (XDR *, AUDIO_HDMI_OUT_VSDB_DATA*);
extern  bool_t xdr_HDMI_VIDEO_TYPE (XDR *, HDMI_VIDEO_TYPE*);
extern  bool_t xdr_HDMI_INFO (XDR *, HDMI_INFO*);
extern  bool_t xdr_AUDIO_MIC_DELAY_SLOT (XDR *, AUDIO_MIC_DELAY_SLOT*);
extern  bool_t xdr_AUDIO_VOLUME_LEVEL (XDR *, AUDIO_VOLUME_LEVEL*);
extern  bool_t xdr_AUDIO_DVOL_LEVEL (XDR *, AUDIO_DVOL_LEVEL*);
extern  bool_t xdr_AUDIO_LICENSE_CONTROL_MASK (XDR *, AUDIO_LICENSE_CONTROL_MASK*);
extern  bool_t xdr_AUDIO_RPC_DEC_FORMAT_INFO (XDR *, AUDIO_RPC_DEC_FORMAT_INFO*);
extern  bool_t xdr_AUDIO_RPC_AIN_FORMAT_INFO (XDR *, AUDIO_RPC_AIN_FORMAT_INFO*);
extern  bool_t xdr_AUDIO_LICENSE_STATUS_CONFIG (XDR *, AUDIO_LICENSE_STATUS_CONFIG*);
extern  bool_t xdr_AudioCodecControlBit (XDR *, AudioCodecControlBit*);
extern  bool_t xdr_AUDIO_ENUM_PRIVAETINFO_TO_SYS (XDR *, AUDIO_ENUM_PRIVAETINFO_TO_SYS*);
extern  bool_t xdr_AUDIO_RPC_PRIVATEINFO_TO_SYS (XDR *, AUDIO_RPC_PRIVATEINFO_TO_SYS*);
extern  bool_t xdr_AUDIO_ENUM_PRIVAETINFO (XDR *, AUDIO_ENUM_PRIVAETINFO*);
extern  bool_t xdr_AUDIO_ENUM_AUDIO_FIRMWARE_CAPABILITY_BIT (XDR *, AUDIO_ENUM_AUDIO_FIRMWARE_CAPABILITY_BIT*);
extern  bool_t xdr_AUDIO_RPC_PRIVATEINFO_PARAMETERS (XDR *, AUDIO_RPC_PRIVATEINFO_PARAMETERS*);
extern  bool_t xdr_AUDIO_RPC_PRIVATEINFO_RETURNVAL (XDR *, AUDIO_RPC_PRIVATEINFO_RETURNVAL*);
extern  bool_t xdr_AUDIO_ENUM_MAX_OUTPUT_SAMPLERATE (XDR *, AUDIO_ENUM_MAX_OUTPUT_SAMPLERATE*);
extern  bool_t xdr_AUDIO_PASSTHROUGH_INFO (XDR *, AUDIO_PASSTHROUGH_INFO*);
extern  bool_t xdr_AUDIO_SAMPLERATE (XDR *, AUDIO_SAMPLERATE*);
extern  bool_t xdr_USB_AUDIO_IN_CMD (XDR *, USB_AUDIO_IN_CMD*);
extern  bool_t xdr_USB_AUDIO_IN_FORMAT (XDR *, USB_AUDIO_IN_FORMAT*);
extern  bool_t xdr_USB_AUDIO_IN_INFO (XDR *, USB_AUDIO_IN_INFO*);
extern  bool_t xdr_USB_AUDIO_IN_TYPE (XDR *, USB_AUDIO_IN_TYPE*);
extern  bool_t xdr_AUDIO_AI_DEVICE_USB_INFO (XDR *, AUDIO_AI_DEVICE_USB_INFO*);
extern  bool_t xdr_AUDIO_DUMMY_DATA (XDR *, AUDIO_DUMMY_DATA*);
extern  bool_t xdr_LPCM_ENDIANESS (XDR *, LPCM_ENDIANESS*);
extern  bool_t xdr_AUDIO_RPC_TSXT (XDR *, AUDIO_RPC_TSXT*);
extern  bool_t xdr_AUDIO_RPC_TSHD_INFO (XDR *, AUDIO_RPC_TSHD_INFO*);
extern  bool_t xdr_AUDIO_RPC_TSHD (XDR *, AUDIO_RPC_TSHD*);
extern  bool_t xdr_AUDIO_RPC_LGSE_RETURNVAL (XDR *, AUDIO_RPC_LGSE_RETURNVAL*);
extern  bool_t xdr_AUDIO_RPC_LGSE_GETDATA (XDR *, AUDIO_RPC_LGSE_GETDATA*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETMODE (XDR *, AUDIO_RPC_LGSE_SETMODE*);
extern  bool_t xdr_AUDIO_RPC_LGSE00861 (XDR *, AUDIO_RPC_LGSE00861*);
extern  bool_t xdr_AUDIO_RPC_LGSE00876 (XDR *, AUDIO_RPC_LGSE00876*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETMAIN (XDR *, AUDIO_RPC_LGSE_SETMAIN*);
extern  bool_t xdr_AUDIO_RPC_LGSE00855 (XDR *, AUDIO_RPC_LGSE00855*);
extern  bool_t xdr_AUDIO_RPC_LGSE00870 (XDR *, AUDIO_RPC_LGSE00870*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN000 (XDR *, AUDIO_RPC_LGSE_SETFN000*);
extern  bool_t xdr_AUDIO_RPC_LGSE00854 (XDR *, AUDIO_RPC_LGSE00854*);
extern  bool_t xdr_AUDIO_RPC_LGSE00869 (XDR *, AUDIO_RPC_LGSE00869*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN001 (XDR *, AUDIO_RPC_LGSE_SETFN001*);
extern  bool_t xdr_AUDIO_RPC_LGSE00857 (XDR *, AUDIO_RPC_LGSE00857*);
extern  bool_t xdr_AUDIO_RPC_LGSE00872 (XDR *, AUDIO_RPC_LGSE00872*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN009 (XDR *, AUDIO_RPC_LGSE_SETFN009*);
extern  bool_t xdr_AUDIO_RPC_LGSE00859 (XDR *, AUDIO_RPC_LGSE00859*);
extern  bool_t xdr_AUDIO_RPC_LGSE00874 (XDR *, AUDIO_RPC_LGSE00874*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN010 (XDR *, AUDIO_RPC_LGSE_SETFN010*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN004 (XDR *, AUDIO_RPC_LGSE_SETFN004*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN005 (XDR *, AUDIO_RPC_LGSE_SETFN005*);
extern  bool_t xdr_AUDIO_RPC_LGSE00858 (XDR *, AUDIO_RPC_LGSE00858*);
extern  bool_t xdr_AUDIO_RPC_LGSE00873 (XDR *, AUDIO_RPC_LGSE00873*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN008 (XDR *, AUDIO_RPC_LGSE_SETFN008*);
extern  bool_t xdr_AUDIO_RPC_LGSE00853 (XDR *, AUDIO_RPC_LGSE00853*);
extern  bool_t xdr_AUDIO_RPC_LGSE00868 (XDR *, AUDIO_RPC_LGSE00868*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN014 (XDR *, AUDIO_RPC_LGSE_SETFN014*);
extern  bool_t xdr_AUDIO_RPC_LGSE00879 (XDR *, AUDIO_RPC_LGSE00879*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN017 (XDR *, AUDIO_RPC_LGSE_SETFN017*);
extern  bool_t xdr_AUDIO_RPC_LGSE00856 (XDR *, AUDIO_RPC_LGSE00856*);
extern  bool_t xdr_AUDIO_RPC_LGSE00871 (XDR *, AUDIO_RPC_LGSE00871*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN019 (XDR *, AUDIO_RPC_LGSE_SETFN019*);
extern  bool_t xdr_AUDIO_RPC_LGSE00863 (XDR *, AUDIO_RPC_LGSE00863*);
extern  bool_t xdr_AUDIO_RPC_LGSE00878 (XDR *, AUDIO_RPC_LGSE00878*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN022 (XDR *, AUDIO_RPC_LGSE_SETFN022*);
extern  bool_t xdr_AUDIO_RPC_LGSE00862 (XDR *, AUDIO_RPC_LGSE00862*);
extern  bool_t xdr_AUDIO_RPC_LGSE00877 (XDR *, AUDIO_RPC_LGSE00877*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN018 (XDR *, AUDIO_RPC_LGSE_SETFN018*);
extern  bool_t xdr_AUDIO_RPC_LGSE02624 (XDR *, AUDIO_RPC_LGSE02624*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN024 (XDR *, AUDIO_RPC_LGSE_SETFN024*);
extern  bool_t xdr_AUDIO_RPC_LGSE_DATA026 (XDR *, AUDIO_RPC_LGSE_DATA026*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN026 (XDR *, AUDIO_RPC_LGSE_SETFN026*);
extern  bool_t xdr_AUDIO_RPC_LGSE_DATA027 (XDR *, AUDIO_RPC_LGSE_DATA027*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN027 (XDR *, AUDIO_RPC_LGSE_SETFN027*);
extern  bool_t xdr_AUDIO_RPC_LGSE02871 (XDR *, AUDIO_RPC_LGSE02871*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN028 (XDR *, AUDIO_RPC_LGSE_SETFN028*);
extern  bool_t xdr_AUDIO_RPC_LGSE02869 (XDR *, AUDIO_RPC_LGSE02869*);
extern  bool_t xdr_AUDIO_RPC_LGSE_SETFN029 (XDR *, AUDIO_RPC_LGSE_SETFN029*);
extern  bool_t xdr_AUDIO_RPC_TRUVOL_MODE (XDR *, AUDIO_RPC_TRUVOL_MODE*);
extern  bool_t xdr_AUDIO_FREQ_EQ_MODE (XDR *, AUDIO_FREQ_EQ_MODE*);
extern  bool_t xdr_AUDIO_RPC_FREQ_EQ (XDR *, AUDIO_RPC_FREQ_EQ*);
extern  bool_t xdr_AUDIO_RPC_TRUVOLUME (XDR *, AUDIO_RPC_TRUVOLUME*);
extern  bool_t xdr_AUDIO_SAMPLERATE_TOLERANCE (XDR *, AUDIO_SAMPLERATE_TOLERANCE*);
extern  bool_t xdr_AUDIO_BASSBACK_TV_MODE (XDR *, AUDIO_BASSBACK_TV_MODE*);
extern  bool_t xdr_AUDIO_BASSBACK_PCBU_MODE (XDR *, AUDIO_BASSBACK_PCBU_MODE*);
extern  bool_t xdr_AUDIO_RPC_PCBU_BASSBACK (XDR *, AUDIO_RPC_PCBU_BASSBACK*);
extern  bool_t xdr_AUDIO_RPC_TV_BASSBACK (XDR *, AUDIO_RPC_TV_BASSBACK*);
extern  bool_t xdr_AUDIO_RPC_TV_BASSBACK_CHANGE_BASS_GAIN (XDR *, AUDIO_RPC_TV_BASSBACK_CHANGE_BASS_GAIN*);
extern  bool_t xdr_AUDIO_AO_CHANNEL_OUT_SWAP (XDR *, AUDIO_AO_CHANNEL_OUT_SWAP*);
extern  bool_t xdr_AUDIO_RPC_AO_CHANNEL_OPT_SWAP (XDR *, AUDIO_RPC_AO_CHANNEL_OPT_SWAP*);
extern  bool_t xdr_AUDIO_CHANNEL_OUT_MODE (XDR *, AUDIO_CHANNEL_OUT_MODE*);
extern  bool_t xdr_AUDIO_RPC_CHANNEL_OUT_MODE (XDR *, AUDIO_RPC_CHANNEL_OUT_MODE*);
extern  bool_t xdr_AUDIO_RPC_GET_PTS_INFO (XDR *, AUDIO_RPC_GET_PTS_INFO*);
extern  bool_t xdr_AUDIO_SPDIFO_SOURCE (XDR *, AUDIO_SPDIFO_SOURCE*);
extern  bool_t xdr_AUDIO_RPC_SPDIFO_SOURCE (XDR *, AUDIO_RPC_SPDIFO_SOURCE*);
extern  bool_t xdr_AUDIO_RPC_PP_ASF_ON_OFF (XDR *, AUDIO_RPC_PP_ASF_ON_OFF*);
extern  bool_t xdr_AUDIO_RPC_PP_ASF_BALANCE (XDR *, AUDIO_RPC_PP_ASF_BALANCE*);
extern  bool_t xdr_AUDIO_RPC_PP_ASF_MASTER_VOLUME (XDR *, AUDIO_RPC_PP_ASF_MASTER_VOLUME*);
extern  bool_t xdr_AUDIO_SPDIF_CS (XDR *, AUDIO_SPDIF_CS*);
extern  bool_t xdr_AUDIO_RPC_RESAMPLE_INFO (XDR *, AUDIO_RPC_RESAMPLE_INFO*);
extern  bool_t xdr_AUDIO_RPC_TO_KERNEL_PARAMETER (XDR *, AUDIO_RPC_TO_KERNEL_PARAMETER*);
extern  bool_t xdr_AUDIO_RPC_DEC_SEEKING_CAP (XDR *, AUDIO_RPC_DEC_SEEKING_CAP*);
extern  bool_t xdr_AUDIO_RPC_GET_DEC_SEEK_CAP (XDR *, AUDIO_RPC_GET_DEC_SEEK_CAP*);

#else /* K&R C */
extern bool_t xdr_AUDIO_DEC_TYPE ();
extern bool_t xdr_AUDIO_CHANNEL_OUT_INDEX ();
extern bool_t xdr_AUDIO_MODULE_TYPE ();
extern bool_t xdr_AUDIO_IO_PIN ();
extern bool_t xdr_ENUM_AUDIO_BILINGUAL_TYPE ();
extern bool_t xdr_ENUM_AUDIO_NIGHTMODE_CFG ();
extern bool_t xdr_AUDIO_RPC_NIGHTMODE ();
extern bool_t xdr_AUDIO_RPC_PP_AGC ();
extern bool_t xdr_ENUM_AUDIO_AGC_TYPE ();
extern bool_t xdr_ENUM_AUDIO_DAC_SWITCH_CFG ();
extern bool_t xdr_ENUM_AUDIO_TRUEHD_LOSSLESSMODE_CFG ();
extern bool_t xdr_AUDIO_RPC_TRUEHD_LOSSLESSMODE ();
extern bool_t xdr_ENUM_AUDIO_DELAY_DAC_SWITCH_CFG ();
extern bool_t xdr_ENUM_AUDIO_IPT_SRC ();
extern bool_t xdr_ENUM_AUDIO_BBADC_SRC ();
extern bool_t xdr_ENUM_AUDIO_SPDIFI_SRC ();
extern bool_t xdr_ENUM_AUDIO_I2SI_SRC ();
extern bool_t xdr_ENUM_AUDIO_I2SI_ID ();
extern bool_t xdr_ENUM_AUDIO_I2SI_MODE ();
extern bool_t xdr_ENUM_AUDIO_I2SI_SYNC ();
extern bool_t xdr_ENUM_AUDIO_BBADC_CLK ();
extern bool_t xdr_AUDIO_IPT_SRC ();
extern bool_t xdr_AUDIO_RPC_DEC_BITSTREAM_BUFFER ();
extern bool_t xdr_AUDIO_RPC_FORMAT_INFO ();
extern bool_t xdr_AUDIO_PCM_FORMAT ();
extern bool_t xdr_AUDIO_EXT_BS ();
extern bool_t xdr_AUDIO_DEC_CFG ();
extern bool_t xdr_ENCODE_MODE ();
extern bool_t xdr_AUDIO_ENC_CFG ();
extern bool_t xdr_AUDIO_RPC_INSTANCE ();
extern bool_t xdr_AUDIO_RPC_HASH ();
extern bool_t xdr_AUDIO_FRAME_BOUNDARY ();
extern bool_t xdr_AUDIO_RPC_SEND_LONG ();
extern bool_t xdr_AUDIO_RPC_SENDPIN_LONG ();
extern bool_t xdr_AUDIO_RPC_SEEK ();
extern bool_t xdr_AUDIO_RPC_PRIVATEINFO ();
extern bool_t xdr_AUDIO_RPC_RINGBUFFER ();
extern bool_t xdr_AUDIO_RPC_IOBUFFER ();
extern bool_t xdr_AUDIO_RPC_BUFFER ();
extern bool_t xdr_ENUM_SYSTEM_PROCESS_TYPE ();
extern bool_t xdr_SYSTEM_PROCESS_INFO ();
extern bool_t xdr_SYSTEM_PROCESS_RES ();
extern bool_t xdr_AUDIO_RPC_WRITEPACK ();
extern bool_t xdr_AUDIO_RPC_READPACK ();
extern bool_t xdr_AUDIO_RPC_SENDIO ();
extern bool_t xdr_AUDIO_RPC_SWITCHAGENT ();
extern bool_t xdr_AUDIO_RPC_PCMFORMAT ();
extern bool_t xdr_AUDIO_RPC_FRAME_BOUNDARY ();
extern bool_t xdr_AUDIO_RPC_DECCFG ();
extern bool_t xdr_AUDIO_RPC_EXTBS_EXIST ();
extern bool_t xdr_AUDIO_RPC_CONNECTION ();
extern bool_t xdr_AUDIO_RPC_REFCLOCK ();
extern bool_t xdr_AUDIO_RPC_PTS_INFO ();
extern bool_t xdr_AUDIO_RPC_RINGBUFFER_HEADER ();
extern bool_t xdr_AUDIO_RPC_FOCUS ();
extern bool_t xdr_AUDIO_RPC_SUBCHANNEL ();
extern bool_t xdr_ENUM_AUDIO_CHANNEL_IDX ();
extern bool_t xdr_AUDIO_RPC_AO_FOCUS ();
extern bool_t xdr_ENUM_AUDIO_CHANNEL_IN ();
extern bool_t xdr_ENUM_AUDIO_CHANNEL_OUT ();
extern bool_t xdr_AUDIO_GENERAL_CONFIG ();
extern bool_t xdr_AUDIO_SAMPLE_INFO ();
extern bool_t xdr_AUDIO_BBADC_CONFIG ();
extern bool_t xdr_AUDIO_I2SI_CONFIG ();
extern bool_t xdr_AUDIO_SPDIFI_CONFIG ();
extern bool_t xdr_AUDIO_RPC_IPT_SRC ();
extern bool_t xdr_AUDIO_RPC_SET_ATV_CLOCK ();
extern bool_t xdr_AUDIO_RPC_INOUT_CH_SELECT ();
extern bool_t xdr_AUDIO_RPC_SET_FS_CLOCKSRC ();
extern bool_t xdr_AUDIO_RPC_SET_PATH_DATA_OUT ();
extern bool_t xdr_AUDIO_RPC_AI_SET_OUT_FMT ();
extern bool_t xdr_AUDIO_RPC_SET_INTERLEAVE_OUT ();
extern bool_t xdr_AUDIO_RPC_SET_SIF_ADC_INIT ();
extern bool_t xdr_AUDIO_SPDIF_ERROR ();
extern bool_t xdr_AUDIO_ADC_CONFIG ();
extern bool_t xdr_AUDIO_SPDIF_CONFIG ();
extern bool_t xdr_AUDIO_IN_SOURCE ();
extern bool_t xdr_AUDIO_IN_DATA_MEASURE ();
extern bool_t xdr_AUDIO_IN_MUTE_INFO ();
extern bool_t xdr_AUDIO_OUT_COPY_SOURCE ();
extern bool_t xdr_AUDIO_OUT_SPDIF_SOURCE ();
extern bool_t xdr_AUDIO_KARAOKE_CONTROL_INFO ();
extern bool_t xdr_LINK_BUFFER ();
extern bool_t xdr_AUDIO_SOUND_EVENT ();
extern bool_t xdr_AUDIO_HDMI_SET ();
extern bool_t xdr_AUDIO_HDMI_MUTE_INFO ();
extern bool_t xdr_AUDIO_OUT_MUTE_INFO ();
extern bool_t xdr_AUDIO_RPC_BBADC_CONFIG ();
extern bool_t xdr_AUDIO_RPC_I2SI_CONFIG ();
extern bool_t xdr_AUDIO_CONFIG_ADC ();
extern bool_t xdr_AUDIO_CONFIG_AFC ();
extern bool_t xdr_AUDIO_DROP_SAMPLE ();
extern bool_t xdr_AUDIO_P_W_NOISE_CFG ();
extern bool_t xdr_ENUM_AUDIO_SPECTRUM_BANDNUM ();
extern bool_t xdr_AUDIO_SPECTRUM_CFG ();
extern bool_t xdr_AUDIO_VOLUME_CONTROL ();
extern bool_t xdr_AUDIO_RPC_SPDIFI_CONFIG ();
extern bool_t xdr_AUDIO_CONFIG_SPDIF ();
extern bool_t xdr_AUDIO_CONFIG_SPDIF_ERR ();
extern bool_t xdr_AUDIO_BACKDOOR_AI_INIT ();
extern bool_t xdr_AUDIO_OUT_GENERAL_CONFIG ();
extern bool_t xdr_AUDIO_OUT_CS_INFO ();
extern bool_t xdr_AUDIO_DAC_CONFIG ();
extern bool_t xdr_AUDIO_OUT_SPDIF_CONFIG ();
extern bool_t xdr_AUDIO_CONFIG_DAC_I2S ();
extern bool_t xdr_AUDIO_CONFIG_DAC_SPDIF ();
extern bool_t xdr_AUDIO_RPC_SPDIF_CHANNEL_STATUS ();
extern bool_t xdr_ENUM_DVD_AUDIO_ENCODER_OUTPUT_INFO_TYPE ();
extern bool_t xdr_AUDIO_RPC_ENC_ELEM_GENERAL_INFO ();
extern bool_t xdr_AUDIO_RPC_ENC_ELEM_FRAME_INFO ();
extern bool_t xdr_ENUM_AUDIO_AIN_INFO_TYPE ();
extern bool_t xdr_AUDIO_RPC_AIN_ELEM_FRAME_INFO ();
extern bool_t xdr_AUDIO_RPC_DEC_GENERAL_INFO ();
extern bool_t xdr_AUDIO_RPC_DEC_FRAME_INFO ();
extern bool_t xdr_AUDIO_RPC_ERROR ();
extern bool_t xdr_AUDIO_RPC_MASTERSHIP ();
extern bool_t xdr_AUDIO_RPC_ENC_SOURCEFILE ();
extern bool_t xdr_AUDIO_PP_FUNCTION ();
extern bool_t xdr_AUDIO_PP_FUNCTION_MODE ();
extern bool_t xdr_AUDIO_PP_CONFIG ();
extern bool_t xdr_AUDIO_PROLOGIC2_MODE ();
extern bool_t xdr_ENUM_PROLOGIC2_ENA ();
extern bool_t xdr_ENUM_AI_PATH ();
extern bool_t xdr_AUDIO_PROLOGIC2_CONFIG ();
extern bool_t xdr_ENUM_SRC_MODE ();
extern bool_t xdr_AUDIO_SRC_CONFIG ();
extern bool_t xdr_AUDIO_RPC_MIXER_MODE ();
extern bool_t xdr_AUDIO_MIXER_CONFIG ();
extern bool_t xdr_AUDIO_PTS_MIXER ();
extern bool_t xdr_AUDIO_PTS_MIXER ();
extern bool_t xdr_AUDIO_RPC_PTS_MIXER_CONFIG ();
extern bool_t xdr_AUDIO_RPC_PTS_MIXER_CONFIG ();
extern bool_t xdr_ENUM_EQUALIZER_GAIN ();
extern bool_t xdr_ENUM_EQUALIZER_MODE ();
extern bool_t xdr_AUDIO_RPC_EQUALIZER_MODE ();
extern bool_t xdr_ENUM_EQUALIZER_ENA ();
extern bool_t xdr_ENUM_GBL_VAR_EQUALIZER_ID ();
extern bool_t xdr_AUDIO_EQUALIZER_CONFIG ();
extern bool_t xdr_ENUM_BASS_MANAGEMENT_CUTOFFFREQ ();
extern bool_t xdr_ENUM_BASS_MANAGEMENT_MODE ();
extern bool_t xdr_ENUM_BASS_MANAGEMENT_SUBWOOFER_ENA ();
extern bool_t xdr_AUDIO_RPC_BASS_MANAGEMENT_MODE ();
extern bool_t xdr_ENUM_BASS_MANAGEMENT_ENA ();
extern bool_t xdr_AUDIO_BASS_MANAGEMENT_CONFIG ();
extern bool_t xdr_AUDIO_RPC_DVS_MODE ();
extern bool_t xdr_ENUM_DVS_ENA ();
extern bool_t xdr_AUDIO_DVS_CONFIG ();
extern bool_t xdr_ENUM_KEY_SHIFT_ENA ();
extern bool_t xdr_ENUM_KEY_SHIFT_STONE ();
extern bool_t xdr_AUDIO_KEY_SHIFT_CONFIG ();
extern bool_t xdr_ENUM_REVERB_ENA ();
extern bool_t xdr_ENUM_REVERB_MODE ();
extern bool_t xdr_AUDIO_REVERB_CONFIG ();
extern bool_t xdr_ENUM_VOCAL_REMOVER_ENA ();
extern bool_t xdr_ENUM_VOCAL_REMOVER_MODE ();
extern bool_t xdr_AUDIO_VOCAL_REMOVER_CONFIG ();
extern bool_t xdr_AUDIO_RPC_DEC_INIT ();
extern bool_t xdr_AUDIO_RPC_ENC_INIT ();
extern bool_t xdr_AUDIO_RPC_ENC_SET_BITRATE ();
extern bool_t xdr_AUDIO_RPC_ENC_COMMAND ();
extern bool_t xdr_AUDIO_RPC_DEBUG_MEMORY ();
extern bool_t xdr_AUDIO_RPC_ENC_INFO ();
extern bool_t xdr_AUDIO_RPC_ENC_DV_MIXER ();
extern bool_t xdr_AUDIO_RPC_AO_INIT ();
extern bool_t xdr_AUDIO_RPC_AO_SET_EQUALIZER ();
extern bool_t xdr_AUDIO_AO_RPC_CONFIG_DELAY_CONTROL ();
extern bool_t xdr_AUDIO_RPC_AO_CONFIG_KARAOKE ();
extern bool_t xdr_AUDIO_RPC_AO_MIXER ();
extern bool_t xdr_AUDIO_RPC_PP_CFG ();
extern bool_t xdr_AUDIO_RPC_PP_MUTE ();
extern bool_t xdr_AUDIO_RPC_AO_DAC ();
extern bool_t xdr_AUDIO_RPC_PP_PROLOGIC ();
extern bool_t xdr_AUDIO_AGC_MODE ();
extern bool_t xdr_AUDIO_KARAOKE_MODE ();
extern bool_t xdr_AUDIO_EASE_TYPE ();
extern bool_t xdr_AUDIO_CONFIG_CMD_MSG ();
extern bool_t xdr_AUDIO_DTS_DEC_PARAM_TYPE ();
extern bool_t xdr_AUDIO_DBX_DEBUG_CMD ();
extern bool_t xdr_AUDIO_DBXTV_PARAM_TYPE ();
extern bool_t xdr_AUDIO_DBXTV_TABLE ();
extern bool_t xdr_AUDIO_DBXTV_TotSonMode ();
extern bool_t xdr_AUDIO_DBXTV_TotVolMode ();
extern bool_t xdr_AUDIO_DBXTV_TotSurMode ();
extern bool_t xdr_AUDIO_DBXTV_SAMPLE_RATE ();
extern bool_t xdr_AUDIO_DBXTV_TABLE_INFO ();
extern bool_t xdr_AUDIO_CONFIG_LGSE ();
extern bool_t xdr_AUDIO_CONFIG_DEVICE ();
extern bool_t xdr_AUDIO_CONFIG_AIO ();
extern bool_t xdr_AUDIO_CUSTOMIZE_REQUEST ();
extern bool_t xdr_AUDIO_CONFIG_COMMAND ();
extern bool_t xdr_AUDISTRY_FEATURE_CMD_MSG ();
extern bool_t xdr_AUDISTRY_TWOUP_PARAMETER ();
extern bool_t xdr_AUDISTRY_HEADSPACE_PARAMETER ();
extern bool_t xdr_AUDISTRY_STEREOWRAPPER_PARAMETER ();
extern bool_t xdr_AUDISTRY_LATENIGHT_PARAMETER ();
extern bool_t xdr_AUDISTRY_VOLUME_PARAMETER ();
extern bool_t xdr_AUDISTRY_RUMBLER_PARAMETER ();
extern bool_t xdr_AUDISTRY_CONFIG_COMMAND ();
extern bool_t xdr_AUDIO_AO_MIC_CONFIG ();
extern bool_t xdr_AUDIO_AO_AUX_CONFIG ();
extern bool_t xdr_AUDIO_AO_ECHO_REVERB_CONFIG ();
extern bool_t xdr_AUDIO_RPC_ECHO_MODE ();
extern bool_t xdr_AUDIO_AO_ECHO_DELAY_MODE ();
extern bool_t xdr_AUDIO_HDMI_CODING_TYPE ();
extern bool_t xdr_AUDIO_HDMI_CHANNEL_COUNT ();
extern bool_t xdr_AUDIO_HDMI_SAMPLING_FREQ ();
extern bool_t xdr_AUDIO_HDMI_SAMPLE_SIZE ();
extern bool_t xdr_AUDIO_HDMI_SETTING_INFO ();
extern bool_t xdr_ENUM_AUDIO_HDMI_EDID_ENABLE ();
extern bool_t xdr_AUDIO_HDMI_OUT_EDID_DATA ();
extern bool_t xdr_AUDIO_HDMI_OUT_EDID_DATA2 ();
extern bool_t xdr_AUDIO_HDMI_OUT_VSDB_DATA ();
extern bool_t xdr_HDMI_VIDEO_TYPE ();
extern bool_t xdr_HDMI_INFO ();
extern bool_t xdr_AUDIO_MIC_DELAY_SLOT ();
extern bool_t xdr_AUDIO_VOLUME_LEVEL ();
extern bool_t xdr_AUDIO_DVOL_LEVEL ();
extern bool_t xdr_AUDIO_LICENSE_CONTROL_MASK ();
extern bool_t xdr_AUDIO_RPC_DEC_FORMAT_INFO ();
extern bool_t xdr_AUDIO_RPC_AIN_FORMAT_INFO ();
extern bool_t xdr_AUDIO_LICENSE_STATUS_CONFIG ();
extern bool_t xdr_AudioCodecControlBit ();
extern bool_t xdr_AUDIO_ENUM_PRIVAETINFO_TO_SYS ();
extern bool_t xdr_AUDIO_RPC_PRIVATEINFO_TO_SYS ();
extern bool_t xdr_AUDIO_ENUM_PRIVAETINFO ();
extern bool_t xdr_AUDIO_ENUM_AUDIO_FIRMWARE_CAPABILITY_BIT ();
extern bool_t xdr_AUDIO_RPC_PRIVATEINFO_PARAMETERS ();
extern bool_t xdr_AUDIO_RPC_PRIVATEINFO_RETURNVAL ();
extern bool_t xdr_AUDIO_ENUM_MAX_OUTPUT_SAMPLERATE ();
extern bool_t xdr_AUDIO_PASSTHROUGH_INFO ();
extern bool_t xdr_AUDIO_SAMPLERATE ();
extern bool_t xdr_USB_AUDIO_IN_CMD ();
extern bool_t xdr_USB_AUDIO_IN_FORMAT ();
extern bool_t xdr_USB_AUDIO_IN_INFO ();
extern bool_t xdr_USB_AUDIO_IN_TYPE ();
extern bool_t xdr_AUDIO_AI_DEVICE_USB_INFO ();
extern bool_t xdr_AUDIO_DUMMY_DATA ();
extern bool_t xdr_LPCM_ENDIANESS ();
extern bool_t xdr_AUDIO_RPC_TSXT ();
extern bool_t xdr_AUDIO_RPC_TSHD_INFO ();
extern bool_t xdr_AUDIO_RPC_TSHD ();
extern bool_t xdr_AUDIO_RPC_LGSE_RETURNVAL ();
extern bool_t xdr_AUDIO_RPC_LGSE_GETDATA ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETMODE ();
extern bool_t xdr_AUDIO_RPC_LGSE00861 ();
extern bool_t xdr_AUDIO_RPC_LGSE00876 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETMAIN ();
extern bool_t xdr_AUDIO_RPC_LGSE00855 ();
extern bool_t xdr_AUDIO_RPC_LGSE00870 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN000 ();
extern bool_t xdr_AUDIO_RPC_LGSE00854 ();
extern bool_t xdr_AUDIO_RPC_LGSE00869 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN001 ();
extern bool_t xdr_AUDIO_RPC_LGSE00857 ();
extern bool_t xdr_AUDIO_RPC_LGSE00872 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN009 ();
extern bool_t xdr_AUDIO_RPC_LGSE00859 ();
extern bool_t xdr_AUDIO_RPC_LGSE00874 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN010 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN004 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN005 ();
extern bool_t xdr_AUDIO_RPC_LGSE00858 ();
extern bool_t xdr_AUDIO_RPC_LGSE00873 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN008 ();
extern bool_t xdr_AUDIO_RPC_LGSE00853 ();
extern bool_t xdr_AUDIO_RPC_LGSE00868 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN014 ();
extern bool_t xdr_AUDIO_RPC_LGSE00879 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN017 ();
extern bool_t xdr_AUDIO_RPC_LGSE00856 ();
extern bool_t xdr_AUDIO_RPC_LGSE00871 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN019 ();
extern bool_t xdr_AUDIO_RPC_LGSE00863 ();
extern bool_t xdr_AUDIO_RPC_LGSE00878 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN022 ();
extern bool_t xdr_AUDIO_RPC_LGSE00862 ();
extern bool_t xdr_AUDIO_RPC_LGSE00877 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN018 ();
extern bool_t xdr_AUDIO_RPC_LGSE02624 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN024 ();
extern bool_t xdr_AUDIO_RPC_LGSE_DATA026 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN026 ();
extern bool_t xdr_AUDIO_RPC_LGSE_DATA027 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN027 ();
extern bool_t xdr_AUDIO_RPC_LGSE02871 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN028 ();
extern bool_t xdr_AUDIO_RPC_LGSE02869 ();
extern bool_t xdr_AUDIO_RPC_LGSE_SETFN029 ();
extern bool_t xdr_AUDIO_RPC_TRUVOL_MODE ();
extern bool_t xdr_AUDIO_FREQ_EQ_MODE ();
extern bool_t xdr_AUDIO_RPC_FREQ_EQ ();
extern bool_t xdr_AUDIO_RPC_TRUVOLUME ();
extern bool_t xdr_AUDIO_SAMPLERATE_TOLERANCE ();
extern bool_t xdr_AUDIO_BASSBACK_TV_MODE ();
extern bool_t xdr_AUDIO_BASSBACK_PCBU_MODE ();
extern bool_t xdr_AUDIO_RPC_PCBU_BASSBACK ();
extern bool_t xdr_AUDIO_RPC_TV_BASSBACK ();
extern bool_t xdr_AUDIO_RPC_TV_BASSBACK_CHANGE_BASS_GAIN ();
extern bool_t xdr_AUDIO_AO_CHANNEL_OUT_SWAP ();
extern bool_t xdr_AUDIO_RPC_AO_CHANNEL_OPT_SWAP ();
extern bool_t xdr_AUDIO_CHANNEL_OUT_MODE ();
extern bool_t xdr_AUDIO_RPC_CHANNEL_OUT_MODE ();
extern bool_t xdr_AUDIO_RPC_GET_PTS_INFO ();
extern bool_t xdr_AUDIO_SPDIFO_SOURCE ();
extern bool_t xdr_AUDIO_RPC_SPDIFO_SOURCE ();
extern bool_t xdr_AUDIO_RPC_PP_ASF_ON_OFF ();
extern bool_t xdr_AUDIO_RPC_PP_ASF_BALANCE ();
extern bool_t xdr_AUDIO_RPC_PP_ASF_MASTER_VOLUME ();
extern bool_t xdr_AUDIO_SPDIF_CS ();
extern bool_t xdr_AUDIO_RPC_RESAMPLE_INFO ();
extern bool_t xdr_AUDIO_RPC_TO_KERNEL_PARAMETER ();
extern bool_t xdr_AUDIO_RPC_DEC_SEEKING_CAP ();
extern bool_t xdr_AUDIO_RPC_GET_DEC_SEEK_CAP ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_AUDIORPCBASEDS_H_RPCGEN */
