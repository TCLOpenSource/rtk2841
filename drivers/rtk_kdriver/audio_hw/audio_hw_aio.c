#include <linux/kconfig.h>
#include <linux/compiler.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/stat.h>			/* permission */
#include <linux/fs.h>			/* fs */
#include <linux/errno.h>		/* error codes */
#include <linux/types.h>		/* size_t */
#include <linux/fcntl.h>		/* O_ACCMODE */
#include <asm/uaccess.h>		/* copy_*_user */
#include <linux/semaphore.h>		/* semaphore */
#include <linux/kthread.h>		/* kernel thread */
#include <linux/freezer.h>		/* set freezable */
#include <linux/wait.h>			/* wait event */
#include <linux/jiffies.h>		/* jiffies */
#include <linux/delay.h>		/* msleep/mdelay */
#include <linux/string.h>		/* memcpy */

/*
 * rbus registers
 */
#include <rbus/audio_reg.h>

#include "audio_hw_port.h"
#include "audio_hw_atv.h"
#include "audio_hw_aio.h"
#include "audio_hw_app.h"

#define __ALOG_SUBTAG "aio"

static uint32_t	m_ampmute[AIO_AMPMUTE_UNKNOWN] = {0};

static MUTE_AMP Audio_MuteAmpFunc = NULL;
static MUTE_SPDIF_OUT Audio_MuteSpdifOutFunc = NULL;
static MUTE_AV_OUT Audio_MuteAVOutFunc = NULL;
static AIO_PATH_CFG curr_path_cfg[2] = {
	{
		AIO_PATH_ID_PB,
		{ AIO_PATH_SRC_UNKNOWN, AIO_PATH_SRC_UNKNOWN, AIO_PATH_SRC_UNKNOWN, AIO_PATH_SRC_UNKNOWN},
	},
	{
		AIO_PATH_ID_TS,
		{ AIO_PATH_SRC_UNKNOWN, AIO_PATH_SRC_UNKNOWN, AIO_PATH_SRC_UNKNOWN, AIO_PATH_SRC_UNKNOWN},
	}
};
#if 0//ndef TV001_BOARD
static uint32_t aio_peak_mag_tab[AIO_PEAK_MAG_TAB_SIZE] = {
	0x00007FFF,                 //   0.00 (dB)
	(uint32_t)(0.944060876286 * 0x00008000), (uint32_t)(0.891250938134 * 0x00008000), (uint32_t)(0.841395141645 * 0x00008000), (uint32_t)(0.794328234724 * 0x00008000),	// - 2.00 (dB)
	(uint32_t)(0.749894209332 * 0x00008000), (uint32_t)(0.707945784384 * 0x00008000), (uint32_t)(0.668343917569 * 0x00008000), (uint32_t)(0.630957344480 * 0x00008000),	// - 4.00 (dB)
	(uint32_t)(0.595662143529 * 0x00008000), (uint32_t)(0.562341325190 * 0x00008000), (uint32_t)(0.530884444231 * 0x00008000), (uint32_t)(0.501187233627 * 0x00008000),	// - 6.00 (dB)
	(uint32_t)(0.473151258961 * 0x00008000), (uint32_t)(0.446683592151 * 0x00008000), (uint32_t)(0.421696503429 * 0x00008000), (uint32_t)(0.398107170553 * 0x00008000),	// - 8.00 (dB)
	(uint32_t)(0.375837404288 * 0x00008000), (uint32_t)(0.354813389234 * 0x00008000), (uint32_t)(0.334965439158 * 0x00008000), (uint32_t)(0.316227766017 * 0x00008000),	// - 10.00 (dB)
	(uint32_t)(0.298538261892 * 0x00008000), (uint32_t)(0.281838293126 * 0x00008000), (uint32_t)(0.266072505980 * 0x00008000), (uint32_t)(0.251188643151 * 0x00008000),	// - 12.00 (dB)
	(uint32_t)(0.237137370566 * 0x00008000), (uint32_t)(0.223872113857 * 0x00008000), (uint32_t)(0.211348903984 * 0x00008000), (uint32_t)(0.199526231497 * 0x00008000),	// - 14.00 (dB)
	(uint32_t)(0.188364908949 * 0x00008000), (uint32_t)(0.177827941004 * 0x00008000), (uint32_t)(0.167880401812 * 0x00008000), (uint32_t)(0.158489319246 * 0x00008000),	// - 16.00 (dB)
	(uint32_t)(0.149623565609 * 0x00008000), (uint32_t)(0.141253754462 * 0x00008000), (uint32_t)(0.133352143216 * 0x00008000), (uint32_t)(0.125892541179 * 0x00008000),	// - 18.00 (dB)
	(uint32_t)(0.118850222744 * 0x00008000), (uint32_t)(0.112201845430 * 0x00008000), (uint32_t)(0.105925372518 * 0x00008000), (uint32_t)(0.100000000000 * 0x00008000),	// - 20.00 (dB)
	(uint32_t)(0.094406087629 * 0x00008000), (uint32_t)(0.089125093813 * 0x00008000), (uint32_t)(0.084139514165 * 0x00008000), (uint32_t)(0.079432823472 * 0x00008000),	// - 22.00 (dB)
	(uint32_t)(0.074989420933 * 0x00008000), (uint32_t)(0.070794578438 * 0x00008000), (uint32_t)(0.066834391757 * 0x00008000), (uint32_t)(0.063095734448 * 0x00008000),	// - 24.00 (dB)
	(uint32_t)(0.059566214353 * 0x00008000), (uint32_t)(0.056234132519 * 0x00008000), (uint32_t)(0.053088444423 * 0x00008000), (uint32_t)(0.050118723363 * 0x00008000),	// - 26.00 (dB)
	(uint32_t)(0.047315125896 * 0x00008000), (uint32_t)(0.044668359215 * 0x00008000), (uint32_t)(0.042169650343 * 0x00008000), (uint32_t)(0.039810717055 * 0x00008000),	// - 28.00 (dB)
	(uint32_t)(0.037583740429 * 0x00008000), (uint32_t)(0.035481338923 * 0x00008000), (uint32_t)(0.033496543916 * 0x00008000), (uint32_t)(0.031622776602 * 0x00008000),	// - 30.00 (dB)
	(uint32_t)(0.029853826189 * 0x00008000), (uint32_t)(0.028183829313 * 0x00008000), (uint32_t)(0.026607250598 * 0x00008000), (uint32_t)(0.025118864315 * 0x00008000),	// - 32.00 (dB)
	(uint32_t)(0.023713737057 * 0x00008000), (uint32_t)(0.022387211386 * 0x00008000), (uint32_t)(0.021134890398 * 0x00008000), (uint32_t)(0.019952623150 * 0x00008000),	// - 34.00 (dB)
	(uint32_t)(0.018836490895 * 0x00008000), (uint32_t)(0.017782794100 * 0x00008000), (uint32_t)(0.016788040181 * 0x00008000), (uint32_t)(0.015848931925 * 0x00008000),	// - 36.00 (dB)
	(uint32_t)(0.014962356561 * 0x00008000), (uint32_t)(0.014125375446 * 0x00008000), (uint32_t)(0.013335214322 * 0x00008000), (uint32_t)(0.012589254118 * 0x00008000),	// - 38.00 (dB)
	(uint32_t)(0.011885022274 * 0x00008000), (uint32_t)(0.011220184543 * 0x00008000), (uint32_t)(0.010592537252 * 0x00008000), (uint32_t)(0.010000000000 * 0x00008000),	// - 40.00 (dB)
	(uint32_t)(0.009440608763 * 0x00008000), (uint32_t)(0.008912509381 * 0x00008000), (uint32_t)(0.008413951416 * 0x00008000), (uint32_t)(0.007943282347 * 0x00008000),	// - 42.00 (dB)
	(uint32_t)(0.007498942093 * 0x00008000), (uint32_t)(0.007079457844 * 0x00008000), (uint32_t)(0.006683439176 * 0x00008000), (uint32_t)(0.006309573445 * 0x00008000),	// - 44.00 (dB)
	(uint32_t)(0.005956621435 * 0x00008000), (uint32_t)(0.005623413252 * 0x00008000), (uint32_t)(0.005308844442 * 0x00008000), (uint32_t)(0.005011872336 * 0x00008000),	// - 46.00 (dB)
	(uint32_t)(0.004731512590 * 0x00008000), (uint32_t)(0.004466835922 * 0x00008000), (uint32_t)(0.004216965034 * 0x00008000), (uint32_t)(0.003981071706 * 0x00008000),	// - 48.00 (dB)
	(uint32_t)(0.003758374043 * 0x00008000), (uint32_t)(0.003548133892 * 0x00008000), (uint32_t)(0.003349654392 * 0x00008000), (uint32_t)(0.003162277660 * 0x00008000),	// - 50.00 (dB)
	(uint32_t)(0.002985382619 * 0x00008000), (uint32_t)(0.002818382931 * 0x00008000), (uint32_t)(0.002660725060 * 0x00008000), (uint32_t)(0.002511886432 * 0x00008000),	// - 52.00 (dB)
	(uint32_t)(0.002371373706 * 0x00008000), (uint32_t)(0.002238721139 * 0x00008000), (uint32_t)(0.002113489040 * 0x00008000), (uint32_t)(0.001995262315 * 0x00008000),	// - 54.00 (dB)
	(uint32_t)(0.001883649089 * 0x00008000), (uint32_t)(0.001778279410 * 0x00008000), (uint32_t)(0.001678804018 * 0x00008000), (uint32_t)(0.001584893192 * 0x00008000),	// - 56.00 (dB)
	(uint32_t)(0.001496235656 * 0x00008000), (uint32_t)(0.001412537545 * 0x00008000), (uint32_t)(0.001333521432 * 0x00008000), (uint32_t)(0.001258925412 * 0x00008000),	// - 58.00 (dB)
	(uint32_t)(0.001188502227 * 0x00008000), (uint32_t)(0.001122018454 * 0x00008000), (uint32_t)(0.001059253725 * 0x00008000), (uint32_t)(0.001000000000 * 0x00008000),	// - 60.00 (dB)
};
#endif
/**
 * * !!!!!!!!!!!! DO NOT REMOVE static declaration !!!!!!!!!!!!!
 * !!!!! this function scope is LIMITED within this file !!!!!
 *
 * Select Headphone output source.
 *
 * @param <src>	{ AIO_HP_MUTE_ALL | AIO_HP_ADCFE | AIO_HP_PB_DAC / AIO_HP_TS_DAC}
 * @return	{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
static int32_t Audio_AioSetOptSrc_Headphone(AIO_HP_SRC mix_src);

/* 
 * aio thread
 */
static DECLARE_WAIT_QUEUE_HEAD(audio_aio_wait);
static struct task_struct *audio_aio_thread = NULL;
static int AioThread(void *arg);
static bool AioThreadState = false;
#if 0//ndef TV001_BOARD
static uint32_t AioPeakMagToDecibel(uint32_t mag);
#endif

unsigned int AIO_ReadRegister(unsigned int addr)
{
	return IoReg_Read32(addr);
}

void AIO_WriteRegister(unsigned int addr, unsigned int value)
{
	IoReg_Write32(addr, value);
}

int32_t Audio_AioGetPathSrc(AIO_PATH_CFG *p_path_cfg)
{
	if (p_path_cfg == NULL)
		return AIO_ERROR;

	if (p_path_cfg->id == AIO_PATH_ID_PB) {
		memcpy(p_path_cfg, &curr_path_cfg[AIO_PATH_ID_PB], sizeof(AIO_PATH_CFG));
	} else {
		memcpy(p_path_cfg, &curr_path_cfg[AIO_PATH_ID_TS], sizeof(AIO_PATH_CFG));
	}

	return AIO_OK;
}

void ao_SetI2sOutclockSrc(AIO_PATH_ID id)
{
	audio_global_ctrl_2_RBUS global_ctrl_2;

	global_ctrl_2.regValue =  AIO_ReadRegister(AUDIO_global_ctrl_2_reg);
	global_ctrl_2.sel_clk_i2s_out = id;
	AIO_WriteRegister(AUDIO_global_ctrl_2_reg,  global_ctrl_2.regValue);
}

void ao_SetSpdifOutclockSrc(AIO_PATH_ID id)
{
#ifdef RTD289X
	audio_global_ctrl_0_RBUS global_ctrl_0;
	global_ctrl_0.regValue =  AIO_ReadRegister(AUDIO_global_ctrl_0_reg);
	global_ctrl_0.sel_clk_spdif_out = id;
	AIO_WriteRegister(AUDIO_global_ctrl_0_reg,  global_ctrl_0.regValue);
#else //new IC after RTD289X
	audio_global_ctrl_2_RBUS global_ctrl_2;
	global_ctrl_2.regValue =  AIO_ReadRegister(AUDIO_global_ctrl_2_reg);
	global_ctrl_2.sel_clk_spdif_out = id;
	AIO_WriteRegister(AUDIO_global_ctrl_2_reg,  global_ctrl_2.regValue);
#endif
}

/** yychao:
 *    1. We control these registers in audio F/W now.
 *       Thus, do NOT use following APIs.
 *    2. to switch SPDIF-out pcm/raw mode,
 *       please use SetAudioSpdifOutputMode() in AudioUtil.cpp
 */
#if 0
/**
 * Setup I2S_OUT source.
 *
 * @param <p_cfg_i2s>	{ pointer of I2S_OUT control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgOptSrc_I2S(AIO_I2SO_CFG *p_cfg_i2s){
	audio_i2s_out_RBUS	I2SO_CTRL_REG;
	I2SO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_i2s_out_reg);

	if(p_cfg_i2s->update_src_only == FALSE) {
		I2SO_CTRL_REG.mclk_sel = p_cfg_i2s->mclk_sel;
	}
	I2SO_CTRL_REG.output_sel = p_cfg_i2s->src_sel;
	AIO_WriteRegister(AUDIO_i2s_out_reg, I2SO_CTRL_REG.regValue);

	if(p_cfg_i2s ->source_sel == AIO_PATH_ID_PB){
		if(p_cfg_i2s->isFixVolume)
		Audio_AioSetPcmSrc_I2S(AIO_I2S_PCM_PB_BF_AVC1);
		else
		Audio_AioSetPcmSrc_I2S(AIO_I2S_PCM_PB_BF_AVC2);

		ao_SetI2sOutclockSrc(AIO_PATH_ID_PB);
	} else {
		Audio_AioSetPcmSrc_I2S(AIO_I2S_PCM_TS_AF_DVC);
		ao_SetI2sOutclockSrc(AIO_PATH_ID_TS);
	}

	return AIO_OK;
}

/**
 * Setup SPDIF_OUT source.
 *
 * @param <p_cfg_spdif>	{ pointer of SPDIF_OUT control block }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgOptSrc_SPDIF(AIO_SPDIFO_CFG *p_cfg_spdif){
	audio_spdif_out_RBUS	spdif_out;

	spdif_out.regValue = AIO_ReadRegister(AUDIO_spdif_out_reg);
	spdif_out.output_sel = p_cfg_spdif->src_sel;
	AIO_WriteRegister(AUDIO_spdif_out_reg, spdif_out.regValue);

	if(p_cfg_spdif ->source_sel == AIO_PATH_ID_PB){
		if(p_cfg_spdif->isFixVolume)
		Audio_AioSetPcmSrc_SPDIF(AIO_SPDIF_PCM_PB_BF_AVC1); // fix-vol
		else
		Audio_AioSetPcmSrc_SPDIF(AIO_SPDIF_PCM_PB_BF_AVC2); // non-fix-vol

		ao_SetSpdifOutclockSrc(AIO_PATH_ID_PB);
	} else {
		if(p_cfg_spdif->isFixVolume)
		Audio_AioSetPcmSrc_SPDIF(AIO_SPDIF_PCM_TS_AF_DVC); // fix-vol
		else
		Audio_AioSetPcmSrc_SPDIF(AIO_SPDIF_PCM_TS_NONPCM); // non-pcm

		ao_SetSpdifOutclockSrc(AIO_PATH_ID_TS);
	}
	return AIO_OK;
}

/**
 * Select SPDIF pcm source.
 *
 * @param <src>	{ AIO_SPDIF_PCM_PB_BF_AVC1 |
		  AIO_SPDIF_PCM_PB_BF_AVC2 |
		  AIO_SPDIF_PCM_PB_AF_AVC2 |
		  AIO_SPDIF_PCM_TS_AF_DVC  |
		  AIO_SPDIF_PCM_PB_NONPCM  |
		  AIO_SPDIF_PCM_TS_NONPCM  }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetPcmSrc_SPDIF(AIO_SPDIF_PCM_SRC sel){
	audio_spdif_out_RBUS	spdif_out_REG;
	spdif_out_REG.regValue = AIO_ReadRegister(AUDIO_spdif_out_reg);
	spdif_out_REG.pcm_source_sel = sel;
	AIO_WriteRegister(AUDIO_spdif_out_reg, spdif_out_REG.regValue);
	return AIO_OK;
}

/**
 * Select I2S pcm source.
 *
 * @param <src>	{ AIO_I2S_PCM_PB_BF_AVC1 |
		  AIO_I2S_PCM_PB_BF_AVC2 |
		  AIO_I2S_PCM_PB_AF_AVC2 |
		  AIO_I2S_PCM_TS_AF_DVC  }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetPcmSrc_I2S(AIO_I2S_PCM_SRC sel){
	audio_i2s_out_RBUS	I2SO_CTRL_REG;
	I2SO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_i2s_out_reg);
	I2SO_CTRL_REG.pcm_source_sel = sel;
	AIO_WriteRegister(AUDIO_i2s_out_reg, I2SO_CTRL_REG.regValue);

	return AIO_OK;
}

/**
 * Select DAC0 pcm source.
 *
 * @param <src>	{ AIO_DAC0_PCM_PB_BF_AVC1 |
		  AIO_DAC0_PCM_PB_BF_AVC2 |
		  AIO_DAC0_PCM_PB_AF_AVC2 |
		  AIO_DAC0_PCM_TS_AF_DVC }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetPcmSrc_DAC0(AIO_DAC0_PCM_SRC sel){
	audio_dac0_1_src_sel_RBUS     dac0_1_src_sel_REG;
	dac0_1_src_sel_REG.regValue =  AIO_ReadRegister(AUDIO_dac0_1_src_sel_reg);
	dac0_1_src_sel_REG.dac0_pcm_source_sel = sel;
	AIO_WriteRegister(AUDIO_dac0_1_src_sel_reg, dac0_1_src_sel_REG.regValue);

	return AIO_OK;
}

/**
 * Select DAC1 pcm source.
 *
 * @param <src>	{ AIO_DAC1_PCM_PB_BF_AVC1 |
		  AIO_DAC1_PCM_PB_BF_AVC2 |
		  AIO_DAC1_PCM_PB_AF_AVC2 |
		  AIO_DAC1_PCM_TS_BF_DVC  |
		  AIO_DAC1_PCM_TS_AF_DVC  }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetPcmSrc_DAC1(AIO_DAC1_PCM_SRC sel){
	audio_dac0_1_src_sel_RBUS     dac0_1_src_sel_REG;
	dac0_1_src_sel_REG.regValue =  AIO_ReadRegister(AUDIO_dac0_1_src_sel_reg);
	dac0_1_src_sel_REG.dac1_pcm_source_sel = sel;
	AIO_WriteRegister(AUDIO_dac0_1_src_sel_reg, dac0_1_src_sel_REG.regValue);

	return AIO_OK;
}
#endif

/**
 * Get DAC0 pcm source.
 *
 * @param <p_dac0_sel>	{ AIO_DAC0_PCM_PB_BF_AVC1,
 *                        AIO_DAC0_PCM_PB_BF_AVC2,
 *                        AIO_DAC0_PCM_PB_AF_AVC1,
 *                        AIO_DAC0_PCM_PB_AF_AVC2,
 *                        AIO_DAC0_PCM_PB_CH23_AF_AVC2,
 *                        AIO_DAC0_PCM_PB_CH45_AF_AVC2,
 *                        AIO_DAC0_PCM_PB_CH67_AF_AVC2,
 *                        AIO_DAC0_PCM_TS_BF_DVC,
 *                        AIO_DAC0_PCM_TS_AF_DVC,
 *                        AIO_DAC0_CH01_OF_AO_HDMI_8CH_PCM,
 *                        AIO_DAC0_CH23_OF_AO_HDMI_8CH_PCM,
 *                        AIO_DAC0_CH45_OF_AO_HDMI_8CH_PCM,
 *                        AIO_DAC0_CH67_OF_AO_HDMI_8CH_PCM }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetPcmSrc_DAC0(AIO_DAC0_PCM_SRC *p_dac0_sel)
{
	int ret;
	audio_dac0_1_src_sel_RBUS dac0_1_src_sel_REG;

	dac0_1_src_sel_REG.regValue = AIO_ReadRegister(AUDIO_dac0_1_src_sel_reg);
	ret = dac0_1_src_sel_REG.dac0_pcm_source_sel;
	*p_dac0_sel = (AIO_DAC0_PCM_SRC)ret;

	return AIO_OK;
}

/**
 * Get DAC1 pcm source.
 *
 * @param <p_dac1_sel>	{ AIO_DAC0_PCM_PB_BF_AVC1,
			  AIO_DAC0_PCM_PB_BF_AVC2,
			  AIO_DAC0_PCM_PB_AF_AVC1,
			  AIO_DAC0_PCM_PB_AF_AVC2,
			  AIO_DAC0_PCM_PB_CH23_AF_AVC2,
			  AIO_DAC0_PCM_PB_CH45_AF_AVC2,
			  AIO_DAC0_PCM_PB_CH67_AF_AVC2,
			  AIO_DAC0_PCM_TS_BF_DVC,
			  AIO_DAC0_PCM_TS_AF_DVC,
			  AIO_DAC0_CH01_OF_AO_HDMI_8CH_PCM,
			  AIO_DAC0_CH23_OF_AO_HDMI_8CH_PCM,
			  AIO_DAC0_CH45_OF_AO_HDMI_8CH_PCM,
			  AIO_DAC0_CH67_OF_AO_HDMI_8CH_PCM }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetPcmSrc_DAC1(AIO_DAC1_PCM_SRC *p_dac1_sel)
{
	int ret;
	audio_dac0_1_src_sel_RBUS dac0_1_src_sel_REG;

	dac0_1_src_sel_REG.regValue = AIO_ReadRegister(AUDIO_dac0_1_src_sel_reg);
	ret = dac0_1_src_sel_REG.dac1_pcm_source_sel;
	*p_dac1_sel = (AIO_DAC1_PCM_SRC)ret;

	return AIO_OK;
}

/**
 * Select I2S_OUT source.
 *
 * @param <src>	{ AIO_I2SO_FIFO / AIO_I2SO_IN_SLAVE / AIO_I2SO_IN_MASTER / AIO_I2SO_IN_HDMI / AIO_I2SO_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_I2S(AIO_I2SO_SRC src)
{
	audio_i2s_out_RBUS I2SO_CTRL_REG;

	I2SO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_i2s_out_reg);

	I2SO_CTRL_REG.output_sel = src;

	AIO_WriteRegister(AUDIO_i2s_out_reg, I2SO_CTRL_REG.regValue);

	return AIO_OK;
}

/**
 * Get I2S_OUT source info.
 *
 * @param <p_i2s_src>	{ AIO_I2SO_FIFO / AIO_I2SO_IN_SLAVE / AIO_I2SO_IN_MASTER / AIO_I2SO_IN_HDMI / AIO_I2SO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetOptSrc_I2S(AIO_I2SO_SRC *p_i2s_src)
{
	audio_i2s_out_RBUS I2SO_CTRL_REG;

	I2SO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_i2s_out_reg);

	*p_i2s_src = (AIO_I2SO_SRC)I2SO_CTRL_REG.output_sel;

	return AIO_OK;
}

/**
 * Select SPDIF_OUT source.
 *
 * @param <src>	{ AIO_SPDIFO_FIFO / AIO_SPDIFO_IN / AIO_SPDIFO_HDMI / AIO_SPDIFO_DISABLE }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_SPDIF(AIO_SPDIFO_SRC src)
{
	audio_spdif_out_RBUS SPDIFO_CTRL_REG;

	SPDIFO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_spdif_out_reg);
	SPDIFO_CTRL_REG.output_sel = src;
	AIO_WriteRegister(AUDIO_spdif_out_reg, SPDIFO_CTRL_REG.regValue);

	return AIO_OK;
}

/**
 * Get SPDIF_OUT source info.
 *
 * @param <p_spdif_src>	{ AIO_SPDIFO_FIFO / AIO_SPDIFO_IN / AIO_SPDIFO_HDMI / AIO_SPDIFO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioGetOptSrc_SPDIF(AIO_SPDIFO_SRC *p_spdif_src)
{
	audio_spdif_out_RBUS SPDIFO_CTRL_REG;

	SPDIFO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_spdif_out_reg);

	*p_spdif_src = (AIO_SPDIFO_SRC)SPDIFO_CTRL_REG.output_sel;

	return AIO_OK;
}

/**
 * * !!!!!!!!!!!! DO NOT REMOVE static declaration !!!!!!!!!!!!!
 * !!!!! this function scope is LIMITED within this file !!!!!
 *
 * Select Headphone output source.
 * @param <src>	{ AIO_HP_MUTE_ALL, AIO_HP_PB_DAC0, AIO_HP_PB_DAC1, AIO_HP_ADCFE1, AIO_HP_ADCFE2
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
static int32_t Audio_AioSetOptSrc_Headphone(AIO_HP_SRC mix_src)
{
	/* !!!!!!!!!!!! DO NOT REMOVE static declaration !!!!!!!!!!!!! */
	/* !!!!! this function scope is LIMITED within this file !!!!! */

	audio_analog_aio_hpout_lineout_l_RBUS AIO_L_SEL_REG;
	audio_analog_aio_hpout_lineout_r_RBUS AIO_R_SEL_REG;

	AIO_L_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_aio_Hpout_Lineout_L_reg);
	AIO_R_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_aio_Hpout_Lineout_R_reg);

	AIO_L_SEL_REG.reg_bb_hpo_mutel = (~mix_src)&AIO_HP_MUTE_ALL;
	AIO_R_SEL_REG.reg_bb_hpo_muter = (~mix_src)&AIO_HP_MUTE_ALL;

	if ((mix_src&AIO_HP_MUTE_ALL) == AIO_HP_MUTE_ALL) {
		AIO_L_SEL_REG.reg_bb_hpo_mutel |= AIO_HP_MUTE_ALL;
		AIO_R_SEL_REG.reg_bb_hpo_muter |= AIO_HP_MUTE_ALL;
	}

	AIO_WriteRegister(AUDIO_analog_aio_Hpout_Lineout_L_reg, AIO_L_SEL_REG.regValue);
	AIO_WriteRegister(AUDIO_analog_aio_Hpout_Lineout_R_reg, AIO_R_SEL_REG.regValue);

	return AIO_OK;
}

/**
 * Config Headphone output
 *
 * @param <hp_cfg>	{}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioCfgOptSrc_Headphone(AIO_HEADPHONE_CFG hp_cfg)
{
	AIO_DAC0_PCM_SRC dac0_sel;
	AIO_DAC1_PCM_SRC dac1_sel;
	int32_t dac0_is_fix_vol;
	int32_t dac1_is_fix_vol;

	Audio_AioGetPcmSrc_DAC0(&dac0_sel);
	Audio_AioGetPcmSrc_DAC1(&dac1_sel);


	if ((dac0_sel == AIO_DAC0_PCM_PB_BF_AVC1)
	    || (dac0_sel == AIO_DAC0_PCM_TS_BF_DVC)
	    || (dac0_sel == AIO_DAC0_PCM_TS_AF_DVC)) {
		dac0_is_fix_vol = TRUE;
	} else {
		dac0_is_fix_vol = FALSE;
	}

	if ((dac1_sel == AIO_DAC1_PCM_PB_BF_AVC1)
	    || (dac1_sel == AIO_DAC1_PCM_TS_BF_DVC)
	    || (dac1_sel == AIO_DAC1_PCM_TS_AF_DVC)) {
		dac1_is_fix_vol = TRUE;
	} else {
		dac1_is_fix_vol = FALSE;
	}

	if (dac0_is_fix_vol == dac1_is_fix_vol) {
		alog("[AIO][HP] Warning! FAIL to config headphone!\n");
		alog("[AIO][HP] pcm-source(%d): DAC0(%d), DAC1(%d)!\n\n", dac0_is_fix_vol, dac0_sel, dac1_sel);
		return AIO_ERROR;
	}

	if (hp_cfg.isFixVol == TRUE) {
		if (dac0_is_fix_vol == TRUE) {
			// DAC0 is fix-vol path
			Audio_AioSetOptSrc_Headphone(AIO_HP_PB_DAC0);
			alog("[AIO][HP] fix-vol path (from DAC0)!\n");
		} else {
			// DAC1 is fix-vol path
			Audio_AioSetOptSrc_Headphone(AIO_HP_PB_DAC1);
			alog("[AIO][HP] fix-vol path (from DAC1)!\n");
		}
	} else {
		if (dac0_is_fix_vol == FALSE) {
			// DAC0 is vol path
			Audio_AioSetOptSrc_Headphone(AIO_HP_PB_DAC0);
			alog("[AIO][HP] vol path (from DAC0)!\n");
		} else {
			// DAC1 is vol path
			Audio_AioSetOptSrc_Headphone(AIO_HP_PB_DAC1);
			alog("[AIO][HP] vol path (from DAC1)!\n");
		}
	}

	return AIO_OK;
}

/**
 * Auther: Wu Yi-Chiao
 * Date: 2013/6/6
 * Select AIO(Lineout) output source.
 *
 * @param <src>	{ AIO_AIO_MUTE_ALL | AIO_AIO_ADCFE | AIO_AIO_PB_DAC / AIO_AIO_TS_DAC}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_AIO(AIO_AIO2_SRC mix_src)
{
	alog("[System][AIO] USE AioSetOptSrc_AIO ERROR, This is set at Audio FW AO init\n");
#if 0
	// Wu Yi-Chiao 2013/6/6
	// Fix: Add AIO source selection API function
	audio_analog_aio_hpout_lineout_l_RBUS analog_aio_hpout_lineout_l_REG;
	audio_analog_aio_hpout_lineout_r_RBUS analog_aio_hpout_lineout_r_REG;

	analog_aio_hpout_lineout_l_REG.regValue = AIO_ReadRegister(AUDIO_analog_aio_Hpout_Lineout_L_reg);
	analog_aio_hpout_lineout_r_REG.regValue = AIO_ReadRegister(AUDIO_analog_aio_Hpout_Lineout_R_reg);

	// not all mute
	if(mix_src & AIO_AIO_PB_DAC) {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel&= ~AIO_AIO_PB_DAC;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter&= ~AIO_AIO_PB_DAC;
	} else {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel |= AIO_AIO_PB_DAC;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter |= AIO_AIO_PB_DAC;
	}

	if(mix_src & AIO_AIO_ADCFE) {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel&= ~AIO_AIO_ADCFE;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter&= ~AIO_AIO_ADCFE;
	} else {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel |= AIO_AIO_ADCFE;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter |= AIO_AIO_ADCFE;
	}

	if(mix_src & AIO_AIO_TS_DAC) {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel&= ~AIO_AIO_TS_DAC;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter&= ~AIO_AIO_TS_DAC;
	} else {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel |= AIO_AIO_TS_DAC;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter |= AIO_AIO_TS_DAC;
	}

	if((mix_src & AIO_AIO_MUTE_ALL) == AIO_AIO_MUTE_ALL) {
		analog_aio_hpout_lineout_l_REG.reg_bb_aio_mutel |= AIO_AIO_MUTE_ALL;
		analog_aio_hpout_lineout_r_REG.reg_bb_aio_muter |= AIO_AIO_MUTE_ALL;
	}

	AIO_WriteRegister(AUDIO_analog_aio_Hpout_Lineout_L_reg, analog_aio_hpout_lineout_l_REG.regValue);
	AIO_WriteRegister(AUDIO_analog_aio_Hpout_Lineout_R_reg, analog_aio_hpout_lineout_r_REG.regValue);
#endif
	return AIO_OK;
}

/**
 * Auther: Wu Yi-Chiao
 * Date: 2013/6/6
 * Select  Lineout (AIO) output source.
 *
 * @param <src>	{ AIO_AIO_MUTE_ALL | AIO_CLLO_ADCFE | AIO_CLLO_PB_DAC / AIO_CLLO_TS_DAC}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_Lineout(AIO_LO_SRC mix_src)
{
	alog("[System][AIO] USE AioSetOptSrc_Lineout ERROR, This is set at Audio FW AO init\n");
#if 0
	// Wu Yi-Chiao 2013/6/6
	// Fix: Add  Lineout (AIO) source selection API function

	Audio_AioSetOptSrc_AIO((AIO_AIO2_SRC) mix_src);
#endif
	return AIO_OK;
}

#if 0 // [MAC] obsolete
/**
 * Select PB_DAC_Mixer output.
 * HWP-Post-FIFO always output to Mixer and user can add AMIX_1 to Mixer output.
 *
 * @param <src>	{ AIO_DACMIX_AMIX_1 }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptSrc_DACMixer(uint32_t mix_src){
	audio_analog_aio_master_hpout_lineout_RBUS HP_LINEOUT_MIX_REG;

	HP_LINEOUT_MIX_REG.regValue = AIO_ReadRegister(AUDIO_ANALOG_AIO_MASTER_HPOUT_LINEOUT_VADDR);

	if(mix_src & AIO_DACMIX_AMIX_1) {
		HP_LINEOUT_MIX_REG.reg_bb_m_master_l &= ~AIO_DACMIX_AMIX_1;
		HP_LINEOUT_MIX_REG.reg_bb_m_master_r &= ~AIO_DACMIX_AMIX_1;
	} else {
		HP_LINEOUT_MIX_REG.reg_bb_m_master_l |= AIO_DACMIX_AMIX_1;
		HP_LINEOUT_MIX_REG.reg_bb_m_master_r |= AIO_DACMIX_AMIX_1;
	}

	AIO_WriteRegister(AUDIO_ANALOG_AIO_MASTER_HPOUT_LINEOUT_VADDR, HP_LINEOUT_MIX_REG.regValue);

	return AIO_OK;
}
#endif

/**
 * Select Headphone output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_R_TO_L |AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_LR_SWAP | AIO_OPT_CHANNEL_L_TO_R}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */

int32_t Audio_AioSetOptChannel_Headphone(AIO_OPT_CHANNEL sel)
{
#ifdef RTD289X
	// Clayton 2013/5/22
	// Add HPout COPY/SWAP function
	audio_analog_out_copy_swap_RBUS AIO_SEL_REG;

	AIO_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_out_copy_swap_reg);

	AIO_SEL_REG.reg_bb_hpo_encopy = sel;

	AIO_WriteRegister(AUDIO_analog_out_copy_swap_reg, AIO_SEL_REG.regValue);
#endif
	return AIO_OK;
}

/**
 * Select AIO(Lineout) output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_R_TO_L |AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_LR_SWAP | AIO_OPT_CHANNEL_L_TO_R}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptChannel_AIO1(AIO_OPT_CHANNEL sel)
{
#ifdef RTD289X
	// Clayton 2013/12/30
	// Add AIO1 COPY/SWAP function
	audio_analog_out_copy_swap_RBUS AIO_SEL_REG;

	AIO_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_out_copy_swap_reg);

	AIO_SEL_REG.reg_bb_aio1_encopy = sel;

	AIO_WriteRegister(AUDIO_analog_out_copy_swap_reg, AIO_SEL_REG.regValue);
#endif
	return AIO_OK;
}

/**
 * Select AIO(Lineout) output channel configuration.
 *
 * @param <sel>	{ AIO_OPT_CHANNEL_R_TO_L |AIO_OPT_CHANNEL_STEREO | AIO_OPT_CHANNEL_LR_SWAP | AIO_OPT_CHANNEL_L_TO_R}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetOptChannel_AIO2(AIO_OPT_CHANNEL sel)
{
#ifdef RTD289X
	// Clayton 2013/12/30
	// Add AIO2 COPY/SWAP function
	audio_analog_out_copy_swap_RBUS AIO_SEL_REG;

	AIO_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_out_copy_swap_reg);

	AIO_SEL_REG.reg_bb_aio2_encopy = sel;

	AIO_WriteRegister(AUDIO_analog_out_copy_swap_reg, AIO_SEL_REG.regValue);
#endif
	return AIO_OK;
}

/**
 * Select DAC0 configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_DAC0(DIO_OPT_CHANNEL sel)
{
	audio_dac0_1_src_sel_RBUS dac0_1_src_sel;

	dac0_1_src_sel.regValue = AIO_ReadRegister(AUDIO_dac0_1_src_sel_reg);

	dac0_1_src_sel.dac0_swap_sel = sel;

	AIO_WriteRegister(AUDIO_dac0_1_src_sel_reg, dac0_1_src_sel.regValue);

	return AIO_OK;
}

/**
 * Select DAC1 configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_DAC1(DIO_OPT_CHANNEL sel)
{
	audio_dac0_1_src_sel_RBUS dac0_1_src_sel;

	dac0_1_src_sel.regValue = AIO_ReadRegister(AUDIO_dac0_1_src_sel_reg);

	dac0_1_src_sel.dac1_swap_sel = sel;

	AIO_WriteRegister(AUDIO_dac0_1_src_sel_reg, dac0_1_src_sel.regValue);

	return AIO_OK;
}

/**
 * Select I2S out configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @param <ch_sel>	{DIO_I2S_CH_01, DIO_I2S_CH_23, DIO_I2S_CH_45, DIO_I2S_CH_67}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_I2S(DIO_OPT_CHANNEL sel, uint16_t ch_sel)
{
	audio_i2s_out_sel_RBUS i2s_out_sel;

	i2s_out_sel.regValue = AIO_ReadRegister(AUDIO_i2s_out_sel_reg);

	if (ch_sel&DIO_I2S_CH_01) {
		i2s_out_sel.swap_sel_ch01 = sel;
	}
#ifdef SUPPORT_8_CHANNEL_I2S_OUT
	if (ch_sel&DIO_I2S_CH_23) {
		i2s_out_sel.swap_sel_ch23 = sel;
	}

	if (ch_sel&DIO_I2S_CH_45) {
		i2s_out_sel.swap_sel_ch45 = sel;
	}

	if (ch_sel&DIO_I2S_CH_67) {
		i2s_out_sel.swap_sel_ch67 = sel;
	}
#endif
	AIO_WriteRegister(AUDIO_i2s_out_sel_reg, i2s_out_sel.regValue);

	return AIO_OK;
}

/**
 * Select SPDIF out configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_SPDIF(DIO_OPT_CHANNEL sel)
{

	audio_spdif_out_RBUS spdif_out;

	spdif_out.regValue = AIO_ReadRegister(AUDIO_spdif_out_reg);

	spdif_out.swap_sel = sel;

	AIO_WriteRegister(AUDIO_spdif_out_reg, spdif_out.regValue);

	return AIO_OK;
}

/**
 * Select DAC0/DAC1/I2S out/SPDIF out configuration.
 *
 * @param <sel>	{ DIO_OPT_CHANNEL_STEREO |DIO_OPT_CHANNEL_L_TO_R | DIO_OPT_CHANNEL_R_TO_L | DIO_OPT_CHANNEL_LR_SWAP}
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_DIOSetOptChannel_ALL(DIO_OPT_CHANNEL sel)
{
	uint16_t i2s_channel_sel = DIO_I2S_CH_01|DIO_I2S_CH_23|DIO_I2S_CH_45|DIO_I2S_CH_67;

	Audio_DIOSetOptChannel_DAC0(sel);
	Audio_DIOSetOptChannel_DAC1(sel);
	Audio_DIOSetOptChannel_I2S(sel, i2s_channel_sel);
	Audio_DIOSetOptChannel_SPDIF(sel);

	return AIO_OK;
}

/**
 * Mute/Unmute SPDIF output.
 *
 * @param <para>	{ AIO_ENABLE / AIO_DISABLE }
 * @return			{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioMute_SPDIF(bool para)
{
	audio_spdif_out_RBUS SPDIFO_CTRL_REG;

	SPDIFO_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_spdif_out_reg);
	SPDIFO_CTRL_REG.spdif_out_null_burst = para;
	AIO_WriteRegister(AUDIO_spdif_out_reg, SPDIFO_CTRL_REG.regValue);

	return AIO_OK;
}

/**
 * Enable/Disable Atlantic Audio Analog Modules 
 *  
 * Refer to typedef "AIO_ANA_POWER" in audio_hw_aio.h 
 * Default PW ON: bit3~14 all enable, module_idx = 0xFFFFFFFF
 * Default PW Down: bit3~14 all disable, module_idx = 0x0 
 *  
 * @param <para>		{ AIO_ENABLE / AIO_DISABLE }
 * @param <module_idx>	{ AIO_POW_XXX, refer to audio_aio.h }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetAnalogPower(bool para, uint32_t module_idx)
{
	audio_analog_power_RBUS ANALOG_POW_REG;

	ANALOG_POW_REG.regValue = AIO_ReadRegister(AUDIO_analog_power_reg);
	if (para == AIO_ENABLE)
		ANALOG_POW_REG.regValue |= module_idx;
	else
		ANALOG_POW_REG.regValue &= ~module_idx;

	AIO_WriteRegister(AUDIO_analog_power_reg, ANALOG_POW_REG.regValue);

	return AIO_OK;
}

#if 0 // [MAC] obsolete
/**
 * Enable/Disable Atlantic Audio HP-Amp output
 *
 * @param <para>		{ AIO_ENABLE / AIO_DISABLE }
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetHeadphoneAmp(bool para){
	audio_analog_aio_master_hpout_lineout_RBUS HP_LINEOUT_MIX_REG;

	HP_LINEOUT_MIX_REG.regValue = AIO_ReadRegister(AUDIO_ANALOG_AIO_MASTER_HPOUT_LINEOUT_VADDR);
	HP_LINEOUT_MIX_REG.reg_bb_en_amp = para;
	AIO_WriteRegister(AUDIO_ANALOG_AIO_MASTER_HPOUT_LINEOUT_VADDR, HP_LINEOUT_MIX_REG.regValue);

	return AIO_OK;
}
#endif

/**
 * Configure Atlantic Audio Interface before using them.
 * This function maybe recall afer resuming from power-saving mode.
 * If the sequence of resuming from power-saving is the same with system-power-on,
 * this function can be replaced by audio_AioInit()
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioConfig(void)
{
	return AIO_OK;
}

int32_t Audio_AioSemInit(void)
{
	return 0;
}

void Audio_AioSemDeInit(void)
{
	return;
}

int32_t Audio_HW_AQ_Init(ATV_CFG *p_atv_cfg)
{
	Audio_AioInit(p_atv_cfg);
	Audio_AppInit();
	return AIO_OK;
}

int32_t Audio_HW_AQ_DeInit(void)
{
	Audio_AioDeInit();
	Audio_AppDeInit();
	return AIO_OK;
}

/**
 * Init. Atlantic Audio Interface
 *
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioInit(ATV_CFG *p_atv_cfg)
{
#ifdef ENABLE_TVSERVER_STR_SWITCH
	// linmc_20160205, prevent creating another thread after resuming from STR.
	if (AioThreadState == true)
		return AIO_OK;
#endif

	//	audio_global_ctrl_RBUS		GLOBAL_CTRL_REG;
	//	audio_sys_clken2_RBUS			SYS_CLKEN2_REG;
	//Frank 20140718 Mac3 no this register
	//audio_post_peak_contorl_RBUS	POST_PEAK_CTRL_REG;
	//audio_ad_asrc_ip_RBUS	AD_ASRC_IP_REG;
	//	audio_down_sample_fifo_source_sel_RBUS	FIFO_SEL_REG;
	//	audio_pll512_fs1_RBUS			PLL_512FS1_REG;
	//	audio_pllaud_ps_RBUS			PLL_AUDPS_REG;
	//audio_peak_contorl_RBUS		PEAK_CTRL_REG;
	//audio_analog_capless_lineout_control_RBUS	ANALOG_CAPLESS_LINEOUT_CONTROL_REG;
	int32_t i;
	//	uint32_t					flag = 0;
	//	ASE_GNL_CONFIG			ase_gnl_cfg;

	/*
	 * sram ,clk and power should be turn-on before power-on-music stage,
	 * but they may be turn-off after into power-save mode.
	 */
	/* ROS
		SYS_CLKEN2_REG.regValue = AIO_ReadRegister(SYSTEM_SYS_CLKEN2_VADDR);
		alog("[CLKEN2] = 0x%08x\n",SYS_CLKEN2_REG.regValue);
		SYS_CLKEN2_REG.clken_audio = AIO_ENABLE;
		SYS_CLKEN2_REG.clken_audio_daad_128fs = AIO_ENABLE;
		SYS_CLKEN2_REG.clken_audio_daad_256fs = AIO_ENABLE;
		SYS_CLKEN2_REG.clken_audio_pre512fs = AIO_ENABLE;
		AIO_WriteRegister(SYSTEM_SYS_CLKEN2_VADDR, SYS_CLKEN2_REG.regValue);
		alog("[CLKEN2] = 0x%08x\n",SYS_CLKEN2_REG.regValue);
	*/
	/*
		SYS_CLKEN3_REG.regValue = AIO_ReadRegister(SYSTEM_SYS_CLKEN3_VADDR);
		SYS_CLKEN3_REG.clken_audio2_512fs = AIO_ENABLE;
		SYS_CLKEN3_REG.clken_audio2_daad_128fs = AIO_ENABLE;
		SYS_CLKEN3_REG.clken_audio2_daad_256fs = AIO_ENABLE;
		AIO_WriteRegister(SYSTEM_SYS_CLKEN3_VADDR, SYS_CLKEN3_REG.regValue);
	*/
	/* ROS
		PLL_512FS1_REG.regValue = AIO_ReadRegister(SYSTEM_PLL512_FS1_VADDR);
		alog("[PLL512_1] = 0x%08x\n",PLL_512FS1_REG.regValue);
		PLL_512FS1_REG.pll512fs_rstb = 1;	// [0,1] = [reset,normal]
		PLL_512FS1_REG.pll512fs_pwdn = 0;	// [0,1] = [pow_on,pow_off]
		PLL_512FS1_REG.pll512fs_oeb  = 0;	// [0,1] = [output_enable,output_disable]
		AIO_WriteRegister(SYSTEM_PLL512_FS1_VADDR, PLL_512FS1_REG.regValue);
		alog("[PLL512_1] = 0x%08x\n",PLL_512FS1_REG.regValue);
	*/
	/* ROS
		PLL_AUDPS_REG.regValue = AIO_ReadRegister(SYSTEM_PLLAUD_PS_VADDR);
		alog("[PLLAUDPS] = 0x%08x\n",PLL_AUDPS_REG.regValue);
		PLL_AUDPS_REG.pllaud_rstb = 1;	// [0,1] = [reset,normal]
		PLL_AUDPS_REG.pllaud_oeb1 = 0;	// [0,1] = [output_enable,output_disable]
		PLL_AUDPS_REG.pllaud_oeb2 =	0;	// [0,1] = [output_enable,output_disable]
		PLL_AUDPS_REG.pllaud_pwdn = 0;	// [0,1] = [pow_on,pow_off]
		PLL_AUDPS_REG.psaud_en   = AIO_ENABLE;
		PLL_AUDPS_REG.psaud_psen = AIO_ENABLE;
		AIO_WriteRegister(SYSTEM_PLLAUD_PS_VADDR, PLL_AUDPS_REG.regValue);
		alog("[PLLAUDPS] = 0x%08x\n",PLL_AUDPS_REG.regValue);
	*/
	/* ROS enable
		GLOBAL_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_GLOBAL_CTRL_VADDR);
		alog("[GLOBAL] = 0x%08x\n",GLOBAL_CTRL_REG.regValue);
		GLOBAL_CTRL_REG.adc_sram_on = AIO_ENABLE;
		GLOBAL_CTRL_REG.dac_sram_on = AIO_ENABLE;
		GLOBAL_CTRL_REG.am_sram_on  = AIO_ENABLE;
		GLOBAL_CTRL_REG.a2_eiaj_sram_on = AIO_ENABLE;
		GLOBAL_CTRL_REG.sif_adc_clk_en = AIO_ENABLE;
		AIO_WriteRegister(AUDIO_GLOBAL_CTRL_VADDR, GLOBAL_CTRL_REG.regValue);
		alog("[GLOBAL] = 0x%08x\n",GLOBAL_CTRL_REG.regValue);
	*/

	// peak detection
	//PEAK_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_peak_contorl_reg);
	//PEAK_CTRL_REG.pdetect_enable = TRUE;
	//AIO_WriteRegister(AUDIO_peak_contorl_reg, PEAK_CTRL_REG.regValue);
	//Frank 20140718 Mac3 no this register
	//POST_PEAK_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_POST_PEAK_CONTORL_VADDR);
	//POST_PEAK_CTRL_REG.post_detect_enable = TRUE;
	//AIO_WriteRegister(AUDIO_POST_PEAK_CONTORL_VADDR,POST_PEAK_CTRL_REG.regValue);

	// Disable ADC LPF bypass mode, let ADC LPF enable due to better performance
	/*
		// [Clayton] 2014/5/28
		// Optimize ADC performance(1) By pass LPF in ASRC (2) Add -1dB compensated gain to avoid truncation
		// [start]
		AD_ASRC_IP_REG.regValue = AIO_ReadRegister(AUDIO_AD_ASRC_IP_VADDR);
		AD_ASRC_IP_REG.ad_comp_gain = AIO_AD_COMP_GAIN_MINUS_1DB;
		AD_ASRC_IP_REG.adc_src_lpf_disable = 1; // By pass LPF in ASRC
		AIO_WriteRegister(AUDIO_AD_ASRC_IP_VADDR,AD_ASRC_IP_REG.regValue);
		// [end]
	*/
	//Audio_AioSetHeadphoneAmp(AIO_ENABLE); // [MAC] obsolete
	/* yychao- : unmute reg6910 in depop flow to avoid pop sound if unmute here
		Audio_AioSetOptSrc_Headphone(AIO_HP_PB_DAC);
		Audio_AioMute_Lineout(AIO_DISABLE);
		Audio_AioMute_Headphone(AIO_DISABLE);
	*/

	// TODO: replaced by API
	//	FIFO_SEL_REG.fifo_ch1_source = 0; // ch1,ch2,(ch1+ch2)/2,(ch1-ch2)/2
	//FIFO_SEL_REG.fifo_ch2_source = 1; // ch1,ch2,(ch1+ch2)/2,(ch1-ch2)/2

	//	FIFO_SEL_REG.regValue = AIO_ReadRegister(AUDIO_down_sample_fifo_source_sel_reg);
	//	FIFO_SEL_REG.fifo_ch12_scale = 5; // 0dB
	//	FIFO_SEL_REG.fifo_ch34_scale = 5; // 0dB
	//	FIFO_SEL_REG.fifo_ch56_scale = 5; // 0dB
	//	FIFO_SEL_REG.fifo_ch78_scale = 5; // 0dB
	//	AIO_WriteRegister(AUDIO_down_sample_fifo_source_sel_reg,FIFO_SEL_REG.regValue);

	alog("init aio driver -- start ----\n");
	alog("g_user_config = %d\n", g_user_config);
	//	m_hdmi_state     = 0;

	for (i = 0; i < AIO_AMPMUTE_UNKNOWN; i++) {
		m_ampmute[i] = 0; // init: set m_ampmute unmute and set m_ampmute_backup as APP_CH_ID_ALL
	}

	//ioctl(audio_fd, AIO_CMD_INIT_DRIVER, flag);

	alog("init aio driver -- end ------\n");

	if(g_user_config == AUDIO_USER_CONFIG_TV002)
	{
		//Audio_AmwInit(NULL);
	Audio_AppInit();
	Audio_AtvInit(p_atv_cfg);
	}

	// initialization for sound event general config.
	//ase_gnl_cfg.delay_ms		= 0;
	//ase_gnl_cfg.flow_pct_main	= 100;
	//Audio_SoundEventInit(&ase_gnl_cfg);

	/*
	 * because HDMI source will hold CPU too long,we force thread priority to highest.
	 */

	/*	audio_aio_thread_param.sched_priority = sched_get_priority_max(SCHED_RR);
	    pthread_attr_setinheritsched(&audio_aio_thread_attr, PTHREAD_EXPLICIT_SCHED);
	#ifndef DISABLE_SCHED_RR
	    pthread_attr_setschedpolicy(&audio_aio_thread_attr, SCHED_RR);
	#endif
	    pthread_attr_setschedparam(&audio_aio_thread_attr, &audio_aio_thread_param);
	*/

	if (IS_ERR_OR_NULL(audio_aio_thread)) {
		AioThreadState = false;
		audio_aio_thread = kthread_run(AioThread, NULL, "AioThread%d", 0);
		if (IS_ERR(audio_aio_thread))
			alog_err("audio_aio_thread creation failed\n");
		else
			alog_info("audio_aio_thread creation ok\n");
		}

	// testing
	//Audio_AioSetIptNoiseReduction(AIO_ENABLE, NULL); // parisfu-

	// for contorl/patch ain_element
	//Audio_ElmCreate(AUDIO_ELM_TYPE_AIN, 0, (void**)&m_ain_handle);

	return AIO_OK;
}

/**
 * DeInit. Atlantic Audio Interface
 * call this function before into power-save/power-down mode.
 *
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioDeInit(void)
{
	int32_t res;
	audio_analog_aio_hpout_lineout_l_RBUS AIO_L_SEL_REG;
	audio_analog_aio_hpout_lineout_r_RBUS AIO_R_SEL_REG;

	Audio_AtvDeInit();
	Audio_AppDeInit();

	if (!IS_ERR(audio_aio_thread)) {
		res = kthread_stop(audio_aio_thread);
		if (res) {
			alog_info("audio_aio_thread cancellation failed %d\n", res);
			audio_aio_thread = NULL;
		} else {
			alog_info("audio_aio_thread cancellation ok\n");
		}
	}

	AIO_L_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_aio_Hpout_Lineout_L_reg);
	AIO_R_SEL_REG.regValue = AIO_ReadRegister(AUDIO_analog_aio_Hpout_Lineout_R_reg);

	AIO_L_SEL_REG.reg_bb_hpo_mutel |= AIO_HP_MUTE_ALL;
	AIO_R_SEL_REG.reg_bb_hpo_muter |= AIO_HP_MUTE_ALL;

	AIO_L_SEL_REG.reg_bb_aio1_mutel |= AIO_AIO1_MUTE_ALL;
	AIO_R_SEL_REG.reg_bb_aio1_muter |= AIO_AIO1_MUTE_ALL;
	
#if !(defined(RTD284X) || defined(RTD287X) || defined(RTD285X))
	AIO_L_SEL_REG.reg_bb_aio2_mutel |= AIO_AIO2_MUTE_ALL;	
	AIO_R_SEL_REG.reg_bb_aio2_muter |= AIO_AIO2_MUTE_ALL;
	
#endif

	AIO_WriteRegister(AUDIO_analog_aio_Hpout_Lineout_L_reg, AIO_L_SEL_REG.regValue); //audio mute
	AIO_WriteRegister(AUDIO_analog_aio_Hpout_Lineout_R_reg, AIO_R_SEL_REG.regValue);

	return AIO_OK;
}

#if 0 // [MAC] obsolete
/**
 * Set AIO2 is ouput
 *
 * @param <src>	{ AIO_BBADC_AIO1 | BBADC_AIO2 | ..., refer to audio_aio.h }
 * @return		{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_SetAIO2IsOutput(uint8_t Output){
	//	audio_analog_frontend_mute_RBUS	BBADC_MUTE_CTRL_REG;
	audio_analog_in_out_sel_RBUS		AIO_SEL_REG;
	uint32_t						ana_pow_flag;

	ana_pow_flag = 0;

	//BBADC_MUTE_CTRL_REG.regValue = 0x03FFFF;		// mute all input of BBADC
	AIO_SEL_REG.regValue = AIO_ReadRegister(AUDIO_ANALOG_IN_OUT_SEL_VADDR);

	if(Output == TRUE)
	AIO_SEL_REG.reg_bb_aio2_io = TRUE; //output
	else
	AIO_SEL_REG.reg_bb_aio2_io = FALSE; //output

	AIO_WriteRegister(AUDIO_ANALOG_IN_OUT_SEL_VADDR, AIO_SEL_REG.regValue);

	return AIO_OK;
}
#endif

/**
 * register Amp Mute callback function for audio library
 *
 * @param <para>		{ callback function name }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetMuteAmpFunc(MUTE_AMP p_func)
{
	Audio_MuteAmpFunc = p_func;
	return AIO_OK;
}

/**
 * Determine Mute/Unmute Amp
 *
 * @param <para>		{ AIO_ENABLE/AIO_DISABLE }
 * @param <ch_id>		{ AIO_CH_ID_L/AIO_CH_ID_R/AIO_CH_ID_ALL )
 * @param <mute_by_who>	{ AIO_AMPMUTE_ID )
 * @return				{ AIO_OK or AIO_ERROR_CODE }
 * @ingroup lib_audio
 */
int32_t Audio_AioSetMute(int32_t para, uint32_t ch_id, AIO_AMPMUTE_ID mute_by_who)
{
	// TODO:
#if 0
	uint32_t i, res;

	if(mute_by_who >= AIO_AMPMUTE_UNKNOWN){
		alog("Error! Unknown AMPMUTE_ID(%d).\n", mute_by_who);
		return AIO_ERROR;
	}

	if(para == ASE_ENABLE){
		m_ampmute[mute_by_who] |= ch_id;

		res = (m_ampmute[AIO_AMPMUTE_APP] & m_ampmute[AIO_AMPMUTE_ASE])
		| m_ampmute[AIO_AMPMUTE_HEADPHONE]
		| m_ampmute[AIO_AMPMUTE_POWERSAVING];

		alog("AmpMute ");
		for(i=0;
		    i<AIO_AMPMUTE_UNKNOWN;
		    i++) {
			alog("(%d:0x%x) ",i,m_ampmute[i]);
		}
		alog("\n[AUDIO][AIO] AMP Mute CH:%x (by ID:%d, CH:0x%x)\n", res, mute_by_who, ch_id);

		if(Audio_MuteAmpFunc == NULL){
			m_ampmute_backup = res;
			alog("Warning! Audio_MuteAmpFunc is NOT registered.\n");
			return AIO_ERROR;
		} else {
			if(res != 0)
			Audio_MuteAmpFunc(AIO_ENABLE, res);
			m_ampmute_backup = res;
		}

	} else {
		m_ampmute[mute_by_who] &= ~ch_id;

		res = (m_ampmute[AIO_AMPMUTE_APP] & m_ampmute[AIO_AMPMUTE_ASE])
		| m_ampmute[AIO_AMPMUTE_HEADPHONE]
		| m_ampmute[AIO_AMPMUTE_POWERSAVING];

		alog("AmpMute ");
		for(i=0;
		    i<AIO_AMPMUTE_UNKNOWN;
		    i++) {
			alog("(%d:0x%x) ",i,m_ampmute[i]);
		}
		alog("\n[AUDIO][AIO] AMP Unmute CH:%x (by ID:%d, CH:0x%x)\n", (m_ampmute_backup - res), mute_by_who, ch_id);

		if(Audio_MuteAmpFunc == NULL){
			m_ampmute_backup = res;
			alog("Warning! Audio_MuteAmpFunc is NOT registered.\n");
			return AIO_ERROR;
		} else {
			if((m_ampmute_backup - res) != 0)
			Audio_MuteAmpFunc(AIO_DISABLE, (m_ampmute_backup - res));
			m_ampmute_backup = res;
		}
	}
#endif
	return AIO_OK;
}

/*===================== Local Subroutine ======================*/
#if 0//ndef TV001_BOARD
static void set_peak_src_sel(AIO_PEAK_SRC src)
{
	audio_peak_contorl_RBUS	PEAK_CTRL_REG;

	PEAK_CTRL_REG.regValue = AIO_ReadRegister(AUDIO_peak_contorl_reg);
	PEAK_CTRL_REG.detect_source_sel = src;
	alog("peak set source %x\n", PEAK_CTRL_REG.detect_source_sel);
	AIO_WriteRegister(AUDIO_peak_contorl_reg, PEAK_CTRL_REG.regValue);
}

static uint32_t AioPeakMagToDecibel(uint32_t mag)
{
	uint32_t i;

	for (i = 1; i < AIO_PEAK_MAG_TAB_SIZE; i++) {
		if (mag > aio_peak_mag_tab[i])
			return i - 1;
	}

	return AIO_PEAK_MAG_TAB_SIZE - 1;
}
#endif

//[start] eq overflow test , test eq overflow process
uint32_t isEQOverflow(void)
{
	audio_system_int_en_RBUS system_int_en_RBUS;

	system_int_en_RBUS.regValue = AIO_ReadRegister(AUDIO_System_Int_En_reg);
	return system_int_en_RBUS.eq_ovf;
}

uint32_t isLoudnessOverflow(void)
{
	audio_system_int_en_RBUS system_int_en_RBUS;

	system_int_en_RBUS.regValue = AIO_ReadRegister(AUDIO_System_Int_En_reg);
	return system_int_en_RBUS.loudness_ovf;
}

//[end]
int AioThread(void *arg)
{
	alog_info("AioThread ceate...\n");

	(void)arg;  /* suppress compile warning */

	AioThreadState = true;
	
	set_freezable();

	do {
		wait_event_freezable_timeout(audio_aio_wait,
					     kthread_should_stop(),
					     usecs_to_jiffies(AIO_PEAK_DETECT_PERIOD_US));

		if (isEQOverflow() || isLoudnessOverflow()) {
			CleanEQLoudnessOverflow();
			alog("eq & loud of \n");
		}
	} while (!kthread_should_stop());

	AioThreadState = false;

	alog_info("AioThread exiting\n");

	return 0;
}

/**
 * register Spdif Out Mute callback function for audio library
 *
 * @param <para>		{ callback function name }
 * @ingroup lib_audio
 */
void Audio_AioMuteSpdifOutFuncRegister(MUTE_SPDIF_OUT p_func)
{
	Audio_MuteSpdifOutFunc = p_func;
}

int32_t Audio_AioSetSpdifOutMute(bool para, uint32_t mute_id)
{
	if (NULL == Audio_MuteSpdifOutFunc) {
		//alog("Warning! Audio_MuteSpdifOutFunc is NOT registered.\n");
		return AIO_ERROR;
	}

	Audio_MuteSpdifOutFunc(para, mute_id);
	return AIO_OK;
}

/**
 * register AV Out Mute callback function for audio library
 *
 * @param <para>		{ callback function name }
 * @ingroup lib_audio
 */
void Audio_AioMuteAVOutFuncRegister(MUTE_AV_OUT p_func)
{
	Audio_MuteAVOutFunc = p_func;
}

int32_t Audio_AioSetAVOutMute(bool para)
{
	if (NULL == Audio_MuteAVOutFunc) {
		//alog("Warning! Audio_MuteAVOutFunc is NOT registered.\n");
		return AIO_ERROR;
	}

	Audio_MuteAVOutFunc(para);
	return AIO_OK;
}

// Clayton 2013/10/18
// Call this API to compensate the HW default gain difference of ADC
void AioADC0GainCompensate(void)
{
	audio_ad0_asrc_ip_RBUS ad0_asrc_ip;

	ad0_asrc_ip.regValue = AIO_ReadRegister(AUDIO_ad0_asrc_ip_reg);
	ad0_asrc_ip.ad0_gain_l = AIO_AD_ASRC_GAIN_HW_Compensate;
	ad0_asrc_ip.ad0_gain_r = AIO_AD_ASRC_GAIN_HW_Compensate;
	AIO_WriteRegister(AUDIO_ad0_asrc_ip_reg, ad0_asrc_ip.regValue);
}

#ifdef SUPPORT_2_SET_ADC
void AioADC1GainCompensate(void)
{
	audio_ad1_asrc_ip_RBUS ad1_asrc_ip;

	ad1_asrc_ip.regValue = AIO_ReadRegister(AUDIO_ad1_asrc_ip_reg);
	ad1_asrc_ip.ad1_gain_l = AIO_AD_ASRC_GAIN_HW_Compensate;
	ad1_asrc_ip.ad1_gain_r = AIO_AD_ASRC_GAIN_HW_Compensate;
	AIO_WriteRegister(AUDIO_ad1_asrc_ip_reg, ad1_asrc_ip.regValue);
}
#endif

void Audio_AioADCGainCompensate(void)
{
	AioADC0GainCompensate();
#ifdef SUPPORT_2_SET_ADC
	AioADC1GainCompensate();
#endif
}

AUDIO_ICVERSION Audio_GetIcVersion(void)
{
	uint32_t GET_IC_VERSION;

	GET_IC_VERSION = AIO_ReadRegister(STB_SC_VerID_reg);
	alog("GET_IC_VERSION = %x\n", GET_IC_VERSION);

	if (GET_IC_VERSION == VERSION_A_REG_CODE)
		return VERSION_A;
	else
		return VERSION_B;
}

#if 0
int32_t Audio_AioSetIptNoiseReduction(bool para, AIO_NR_CFG *p_cfg_nr){
	printf("[%s] phase out .......\n",__FUNCTION__);
	return 0;
}

void Audio_AioGetNrSetting(AIO_NR_CFG* pAIO_NR_CFG){
	printf("[%s]phase out......\n",__FUNCTION__);
}

void Audio_AioSetOptAVCFactor(uint32_t factor){
	printf("[%s]phase out.....\n",__FUNCTION__);
}
int32_t Audio_AioSetOptAVC(bool para, AIO_AVC_CFG *p_cfg_opt_avc){
	printf("[%s]phase out.....\n",__FUNCTION__);
}
#endif
