/*
 *  Mars soundcard
 *  Copyright (c) by Jaroslav Kysela <perex@suse.cz>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/slab.h>
#include <linux/time.h>
#include <linux/wait.h>
#include <linux/moduleparam.h>
#include <sound/core.h>
#include <sound/control.h>
#include <sound/pcm.h>
#include <sound/rawmidi.h>
#include <sound/initval.h>
#include <linux/mutex.h>
#include <linux/ioctl.h> /* needed for the _IOW etc stuff used later */
#include <linux/syscalls.h> /* needed for the _IOW etc stuff used later */
#include <linux/mpage.h>
#include <linux/dcache.h>
#include <linux/pageremap.h>
#include <linux/timer.h>
#include <linux/workqueue.h>
#include <linux/dma-mapping.h>
#include <sound/asound.h>
#include <sound/rtk_snd.h>
#include <asm/cacheflush.h>
#include <linux/pageremap.h>
#include <linux/string.h>
#include <linux/delay.h>
#if defined(CONFIG_REALTEK_RPC)
#include <mach/RPCDriver.h>
#endif
#include <linux/platform_device.h>

#if defined(CONFIG_RTK_KDRV_RPC)
#include <rtk_kdriver/RPCDriver.h>
#endif

MODULE_AUTHOR("EJ Hsu <ejhsu@realtek.com.tw>");
MODULE_DESCRIPTION("Mars soundcard");
MODULE_LICENSE("GPL");
MODULE_SUPPORTED_DEVICE("{{ALSA,Mars soundcard}}");

int snd_open_count;		/* playback open count */
int snd_open_ai_count;	/* capture open count */
int have_global_ai;		/* check whether FW use global AI or not */
int get_cap;
int alsa_agent;

/* #define USE_DECODER */
#define MAX_PCM_DEVICES 8
#define MAX_PCM_SUBSTREAMS 8
#define MAX_MIDI_DEVICES 2
/* for capture feature */
#define MAX_AI_DEVICES 2
#define ENDIAN_CHANGE(x)	((((x)&0xff000000)>>24)|\
				(((x)&0x00ff0000)>>8)|\
				(((x)&0x0000ff00)<<8)|\
				(((x)&0x000000ff)<<24))
#define LPCM_2CH_16BITS (4)

/* defaults */
#define MIN_BUFFER_SIZE (0x8000)
#define MAX_BUFFER_SIZE (256*1024)
/* period size in bytes */
#define MIN_PERIOD_SIZE (64)
#define MAX_PERIOD_SIZE (0x40000)

#define USE_FORMATS SNDRV_PCM_FMTBIT_S16_LE

#ifdef CONFIG_CUSTOMER_TV006
#define USE_RATE (SNDRV_PCM_RATE_44100|SNDRV_PCM_RATE_48000)
#define USE_RATE_MIN 44100
#else
#define USE_RATE (SNDRV_PCM_RATE_16000|SNDRV_PCM_RATE_32000| \
	SNDRV_PCM_RATE_44100|SNDRV_PCM_RATE_48000)
#define USE_RATE_MIN 16000
#endif

#define USE_RATE_MAX 48000

#ifndef USE_CHANNELS_MIN
#define USE_CHANNELS_MIN 1
#endif
#ifndef USE_CHANNELS_MAX
#define USE_CHANNELS_MAX 2
#endif
#ifndef USE_PERIODS_MIN
#define USE_PERIODS_MIN 4
#endif
#ifndef USE_PERIODS_MAX
#define USE_PERIODS_MAX 1024
#endif
#ifndef add_playback_constraints
#define add_playback_constraints(x) 0
#endif
#ifndef add_capture_constraints
#define add_capture_constraints(x) 0
#endif

#ifdef CONFIG_CUSTOMER_TV006
#define USE_FIXED_AO_PINID
#endif

#ifdef CONFIG_ARM64
#define ALIGN4 (0xFFFFFFFFFFFFFFFCLL)
#else
#define ALIGN4 (0xFFFFFFFC)
#endif
/* #define ALSA_DEBUG_LOG */

#if defined(CONFIG_CUSTOMER_TV001) ||  defined(CONFIG_CUSTOMER_TV010) ||  defined(CONFIG_CUSTOMER_TV030)
#ifndef RPC_ACPU_NOT_READY
#define RPC_ACPU_NOT_READY -3
#endif
#endif

/* EJ: device configuration */
static int index[SNDRV_CARDS] = SNDRV_DEFAULT_IDX;	/* Index 0-MAX */
static char *id[SNDRV_CARDS] = SNDRV_DEFAULT_STR;	/* ID for this card */
#ifndef CONFIG_CUSTOMER_TV006
static int enable[SNDRV_CARDS] = {1, 1, [2 ... (SNDRV_CARDS - 1)] = 0};
#else
static int enable[SNDRV_CARDS] = {1, [1 ... (SNDRV_CARDS - 1)] = 0};
#endif
static int pcm_devs[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = MAX_PCM_DEVICES};
static int pcm_substreams[SNDRV_CARDS] = {[0 ... (SNDRV_CARDS - 1)] = MAX_PCM_SUBSTREAMS};
static int min_period_size = MIN_PERIOD_SIZE;

#ifdef USE_FIXED_AO_PINID
static int used_ao_pin[MAX_PCM_DEVICES];
static int flush_error[MAX_PCM_DEVICES];
static int pause_error[MAX_PCM_DEVICES];
static int close_error[MAX_PCM_DEVICES];
static int release_error[MAX_PCM_DEVICES];
#endif

module_param_array(index, int, NULL, 0444);
MODULE_PARM_DESC(index, "Index value for mars soundcard.");
module_param_array(id, charp, NULL, 0444);
MODULE_PARM_DESC(id, "ID string for mars soundcard.");
module_param_array(enable, int, NULL, 0444);
MODULE_PARM_DESC(enable, "Enable this mars soundcard.");
module_param_array(pcm_devs, int, NULL, 0444);
MODULE_PARM_DESC(pcm_devs, "PCM devices # (0-7) for mars driver.");
module_param_array(pcm_substreams, int, NULL, 0444);
MODULE_PARM_DESC(pcm_substreams, "PCM substreams # (1-16) for mars driver.");
/* module_param_array(midi_devs, int, NULL, 0444); */
/* MODULE_PARM_DESC(midi_devs, "MIDI devices # (0-2) for mars driver."); */
module_param(min_period_size, int, 0444);

enum MIXER_ADDR {
	MIXER_ADDR_0,
	MIXER_ADDR_1,
	MIXER_ADDR_2,
	MIXER_ADDR_3,
	MIXER_ADDR_4,
	MIXER_ADDR_5,
	MIXER_ADDR_6,
	MIXER_ADDR_7,
	MIXER_ADDR_MAX
};

struct snd_card_mars {
	struct snd_card *card;
	spinlock_t mixer_lock;
	struct work_struct work_volume;
	struct mutex rpc_lock;
	int ao_pin_id[MIXER_ADDR_MAX];
	int ao_flash_volume[MIXER_ADDR_MAX];
	int ao_flash_change[MIXER_ADDR_MAX];
};

enum AUDIO_PATH {
	AUDIO_PATH_NONE = 0,
	AUDIO_PATH_DECODER_AO,
	AUDIO_PATH_AO,
	AUDIO_PATH_AO_BYPASS
};

enum RTK_SND_FLUSH_STATE {
	RTK_SND_FLUSH_STATE_NONE = 0,
	RTK_SND_FLUSH_STATE_WAIT,
	RTK_SND_FLUSH_STATE_FINISH
};

struct rtk_snd_pcm {
	struct snd_card_mars *card;
	spinlock_t lock;
	spinlock_t *pcm_lock;
	struct timer_list timer;
	int running;

	enum RTK_SND_FLUSH_STATE flush_state;
	unsigned int pcm_buffer_head;
	unsigned int pcm_size;		/* buffer sizze */
	unsigned int pcm_count;		/* period length */
	unsigned int pcm_bps;		/* bytes per second */
	unsigned int pcm_jiffie;	/* bytes per one jiffie */
	int pcm_irq_pos;			/* IRQ position */
	unsigned int pcm_buf_pos;	/* position in buffer */
	unsigned int remain_sample;

	snd_pcm_access_t access;	/* access mode */
	snd_pcm_format_t format;	/* SNDRV_PCM_FORMAT_* */
	unsigned int rate;		/* rate in Hz */
	unsigned int channels;		/* channels */
	snd_pcm_uframes_t period_size;	/* period size */
	unsigned int periods;		/* periods */
	snd_pcm_uframes_t buffer_size;	/* buffer size */
	unsigned int sample_bits;

	snd_pcm_uframes_t buffer_byte_size;	/* buffer size */

	unsigned int period_jiffies;
	unsigned int wp;
	unsigned int rp_real;
	unsigned int out_sample_width;
	int output_frame_bytes;
	int input_frame_bytes;
	int output_sample_bytes;
	int input_sample_bytes;

	struct RBUF_HEADER_ARM ring_bak[8];
	/* ALSA buffer control */
	snd_pcm_uframes_t appl_ptr;
	/* buffer control */
	int freerun;
	unsigned int ring_init;
	unsigned int extend_to_32be_ratio;
	/* realtek hw control */
	int ao_agent;
	int ao_pin_id;
	int dec_agent;
	int dec_pin_id;
	int agent_id;
	int pin_id;
	int volume;
	int volume_change;
	enum AUDIO_PATH audiopath;
	struct page *page;
	struct RBUF_HEADER *ring; /* realtek hw ring buffer control */
	struct RBUF_HEADER *inband; /* realtek hw ring buffer control */

	struct RBUF_HEADER hw_ring[8];
	struct RBUF_HEADER hw_inband_ring[8];
	unsigned int hw_inband_data[256];

	struct RBUF_HEADER *ao_in_ring;
	struct RBUF_HEADER ao_in_ring_instance[8];

	unsigned int *ao_in_ring_p[8];
	struct snd_pcm_substream *substream;

	dma_addr_t phy_addr; /* for UNCAC_BASE */

	long total_data_wb;	/* total data write in byte */
	long pre_time_ms; /* last time that updata wp in millisecond */
	long current_time_ms; /* current time in millisecond */
	unsigned long pre_wr_ptr;

	long pre_no_datatime_ms; /* last time that no data time in millisecond */
	long current_no_datatime_time_ms; /* current no data time in millisecond */

	long max_level; /* max data in ring buffer */
	long min_level; /* min data in ring buffer */

	int hwptr_error_times; /* error handle for ptr */
};

/* pcm capture stucture */
struct rtk_snd_cap_pcm {
	struct snd_card_mars *card;
	spinlock_t *pcm_lock;
	struct timer_list timer;
	int running;

	enum RTK_SND_FLUSH_STATE flush_state;
	unsigned int pcm_buffer_head;
	unsigned int pcm_size;		/* buffer sizze */
	unsigned int pcm_count;		/* period length */
	unsigned int pcm_bps;		/* bytes per second */
	unsigned int pcm_jiffie;	/* bytes per one jiffie */
	int pcm_irq_pos;			/* IRQ position */
	unsigned int pcm_buf_pos;	/* position in buffer */
	unsigned int remain_sample;

	snd_pcm_access_t access;	/* access mode */
	snd_pcm_format_t format;	/* SNDRV_PCM_FORMAT_* */
	unsigned int rate;		/* rate in Hz */
	unsigned int channels;		/* channels */
	snd_pcm_uframes_t period_size;	/* period size */
	unsigned int periods;		/* periods */
	snd_pcm_uframes_t buffer_size;	/* buffer size */
	unsigned int sample_bits;

	snd_pcm_uframes_t buffer_byte_size;	/* buffer size */

	unsigned int period_jiffies;
	unsigned int out_sample_width;
	int output_frame_bytes;
	int input_frame_bytes;
	int output_sample_bytes;
	int input_sample_bytes;

	struct RBUF_HEADER_ARM ring_bak[8];
	/* ALSA buffer control */
	snd_pcm_uframes_t appl_ptr;

	/* for AIO_CONFIG */
	enum AIO_PATH_SRC path_src;
	enum ENUM_AUDIO_BBADC_SRC bbadc_mux_in;
	enum ENUM_AUDIO_I2SI_SRC i2si_mux_in;
	enum ENUM_AUDIO_SPDIFI_SRC spdifi_mux_in;

	unsigned int ring_init;
	unsigned int extend_to_32be_ratio;
	/* realtek hw control */
	int ao_cap_agent;
	int ao_cap_pin;
	int ai_cap_agent;
	int ai_cap_pin;
	int volume;
	int volume_change;
	/* Android AI format */
	enum AUDIO_FORMAT_OF_AI_SEND_TO_ALSA ai_format;
	struct page *page;
	struct RBUF_HEADER *ring; /* realtek hw ring buffer control */
	struct RBUF_HEADER *inband; /* realtek hw ring buffer control */


	struct RBUF_HEADER hw_ring[8];
	struct RBUF_HEADER hw_inband_ring[8];
	unsigned int hw_inband_data[256];

	struct RBUF_HEADER *hw_ai_ring;
	struct RBUF_HEADER hw_ai_ring_instance[8];

	unsigned int *hw_ai_ring_data[8];
	struct snd_pcm_substream *substream;

	void *ring_p;	/* for capture address */
	dma_addr_t ring_phy_addr;	/* for capture address */

	dma_addr_t phy_addr; /* add for UNCAC_BASE */

	/* last time that updata wp in millisecond */
	long last_time_ms;
	/* current time in millisecond */
	long current_time_ms;

};

static struct platform_device *devices[SNDRV_CARDS];

static int rtk_snd_flush(struct snd_pcm_substream *substream);
static int rtk_snd_pause(struct snd_pcm_substream *substream);
static int rtk_snd_close(struct snd_pcm_substream *substream);
static int rtk_snd_playback_close(struct snd_pcm_substream *substream);
static int rtk_snd_create_decoder_agent(struct snd_pcm_substream *substream);
static int rtk_snd_init_connect_decoder_ao(struct snd_pcm_substream *substream);
static void rtk_snd_init_decoder_ring(struct snd_pcm_substream *substream);
static int rtk_snd_init_decoder_info(struct snd_pcm_substream *substream);
static int rtk_snd_set_ao_flashpin_volume(struct snd_pcm_substream *substream);
static void rtk_snd_resume(struct snd_pcm_substream *substream);
static int rtk_snd_init_ao_ring(struct snd_pcm_substream *substream);
static int rtk_snd_ao_info(struct snd_pcm_substream *substream);
static int rtk_snd_init(struct snd_card *card);
static int rtk_snd_open(struct snd_pcm_substream *substream);
static void rtk_snd_playback_volume_work(struct work_struct *work);
static void rtk_snd_pcm_freerun_timer_function(unsigned long data);
static void rtk_snd_pcm_capture_timer_function(unsigned long data);
static int rtk_snd_check_audio_fw_capability(struct snd_card *card);
static void rtk_snd_fmt_convert_to_S16LE(struct snd_pcm_substream *substream,
	snd_pcm_uframes_t wp_next, snd_pcm_uframes_t wp, unsigned int adv_min);

/* not used now
void getpts(void)
{
	int64_t ret;
	unsigned int ptrlo, ptrhi;

	ptrlo = (unsigned int) rtd_inl(0xB801B690);
	ptrhi = (unsigned int) rtd_inl(0xB801B694);

	ret = ptrlo;
	ret = ret|(((int64_t)ptrhi) << 32);

	pr_debug("ALSA PTS: %08x\n", ret);
}
*/

static void update_hw_delay(struct snd_pcm_substream *substream)
{
	unsigned int delay_90k;
	struct snd_pcm_runtime *runtime = substream->runtime;

	delay_90k = (unsigned int) rtd_inl(0xB800607C);

	runtime->delay = ((delay_90k / 90) * runtime->rate) / 1000;

	/*
	if (runtime->rate != 0) {
		pr_info("ALSA hw delay: %08x(%d samples, %d ms)\n", delay_90k, runtime->delay, runtime->delay*1000/runtime->rate);
	}
	*/
}

static int audio_send_rpc_command(int opt,
	unsigned long command, unsigned long param1,
	unsigned long param2, unsigned long param2_LE,
	unsigned long *retvalue)
{
	int ret, count;
	struct RPCRES *audio_ret;
	ret = 0;
	count = 0;

#if defined(CONFIG_CUSTOMER_TV001) ||  defined(CONFIG_CUSTOMER_TV010) ||  defined(CONFIG_CUSTOMER_TV030)
	do {
		ret = send_rpc_command(opt, command, param1, param2, retvalue);

		if (ret == RPC_FAIL) {
			pr_err("[ALSA] RPC to ACPU fail!!\n");
			return -1;
		}

		if (ret == RPC_OK)
			break;

		// RPC_ACPU_NOT_READY
		msleep(100);
		count++;
	} while (count <= 100);

	if (ret == RPC_ACPU_NOT_READY) {
		pr_err("[ALSA] wait ACPU ready timeout!!!\n");
		return -1;
	}
#else
	if (send_rpc_command(opt, command, param1, param2, retvalue))
		ret = -1;
#endif

	audio_ret = (struct RPCRES *)param2_LE;

	if (command == ENUM_KERNEL_RPC_CHECK_READY ||
	command == ENUM_KERNEL_RPC_PRIVATEINFO ||
	command == ENUM_KERNEL_RPC_GET_MUTE_N_VOLUME) {
		if (*retvalue != S_OK) {
			pr_err("[ALSA] RPC S_OK fail\n");
			pr_err("[ALSA] retvalue %lx\n", *retvalue);
			ret = -1;
		}
	} else {
		if (*retvalue != S_OK || ntohl(audio_ret->result) != S_OK) {
			pr_err("[ALSA] RPC S_OK fail\n");
			pr_err("[ALSA] retvalue %lx, result %x, command %lx\n",
				*retvalue, ntohl(audio_ret->result), command);
			ret = -1;
		}
	}

	return ret;
}

#if 1
static int rtk_snd_create_decoder_agent(struct snd_pcm_substream *substream)
{
	struct AUDIO_RPC_INSTANCE *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	int result;
	dma_addr_t dat;
	void *p;

	struct snd_pcm_runtime *runtime;
	struct rtk_snd_pcm *dpcm;

	if (substream == NULL)
		return -1;

	runtime = substream->runtime;
	dpcm = runtime->private_data;

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_INSTANCE *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_INSTANCE) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_INSTANCE) + 8) &
			0xFFFFFFFC));

	/* create decoder */
	info->type = htonl(AUDIO_DECODER);
	info->instance_id = htonl(-1);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_CREATE_AGENT,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dpcm->dec_agent = dpcm->agent_id = ntohl(res->data);
	dpcm->dec_pin_id = dpcm->pin_id = BASE_BS_IN;
	result = dpcm->agent_id;
	pr_debug("[ALSA] Create decode instance %d\n", dpcm->agent_id);

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return result;
}

static int RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(struct snd_card *card,
	struct RPC_RBUF_HEADER *header)
{
	struct RPC_RBUF_HEADER *hd, *hd_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	int i;
	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);
	if (!p) {
		pr_err("[ALSA] [%d] alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	hd = p;
	hd_audio = (struct RPC_RBUF_HEADER *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct RPC_RBUF_HEADER) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct RPC_RBUF_HEADER) + 8) &
			0xFFFFFFFC));

	hd->instance_id = htonl(header->instance_id);
	hd->pin_id = htonl(header->pin_id);
	hd->rd_idx = htonl(header->rd_idx);
	hd->listsize = htonl(header->listsize);

	for (i = 0; i < 8; i++) {
		hd->rbuf_list[i] =
			htonl(0xa0000000|(((uint) header->rbuf_list[i])&0x1FFFFFFF));
	}

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_INIT_RINGBUF,
		(unsigned int) hd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %d RPC fail\n", __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

static int RPC_TOAGENT_CONNECT_SVC(struct snd_card *card,
	struct AUDIO_RPC_CONNECTION *pconnection)
{
	struct AUDIO_RPC_CONNECTION *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);
	if (!p) {
		pr_err("[ALSA] [%d]alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_CONNECTION *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_CONNECTION) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_CONNECTION) + 8) &
			0xFFFFFFFC));

	info->src_instance = htonl(pconnection->src_instance);
	info->src_pin = htonl(pconnection->src_pin);
	info->des_instance = htonl(pconnection->des_instance);
	info->des_pin = htonl(pconnection->des_pin);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_CONNECT,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		dma_free_coherent(card->dev, 4096, p, dat);
		pr_err("[ALSA] %d RPC fail\n", __LINE__);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

static int RPC_TOAGENT_PAUSE_SVC(struct snd_card *card, int *inst_id)
{
	int *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (int *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(int) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(int) + 8) &
			0xFFFFFFFC));

	*info = htonl(*inst_id);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PAUSE,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %d RPC fail\n", __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

static int RPC_TOAGENT_RUN_SVC(struct snd_card *card, int *inst_id)
{
	int *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (int *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(int) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(int) + 8) &
			0xFFFFFFFC));

	*info = htonl(*inst_id);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_RUN,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

static int RPC_TOAGENT_FLUSH_SVC(struct snd_card *card,
	struct AUDIO_RPC_SENDIO *sendio)
{
	struct AUDIO_RPC_SENDIO *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_SENDIO *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_SENDIO) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_SENDIO) + 8) &
			0xFFFFFFFC));

	pr_debug("[ALSA] %s %d %d\n", __func__, sendio->instance_id, sendio->pin_id);

	info->instance_id = htonl(sendio->instance_id);
	info->pin_id = htonl(sendio->pin_id);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_FLUSH,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

int RPC_TOAGENT_STOP_SVC(struct snd_card *card, int *instance_id)
{
	int *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (int *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(int) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(int) + 8) &
			0xFFFFFFFC));

	*info = htonl(*instance_id);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_STOP,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

int RPC_TOAGENT_DESTROY_SVC(struct snd_card *card, int *instance_id)
{
	int *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] [%s %d]alloc memory fail\n", __func__, __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (int *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(int) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(int) + 8) &
			0xFFFFFFFC));

	*info = htonl(*instance_id);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_DESTROY,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

/* not used now
static int hw_ring_avail(struct RBUF_HEADER *ring)
{
	struct RBUF_HEADER tmp;
	int avail;

	tmp.begin_addr = ntohl(ring->begin_addr) & 0x1FFFFFFF;
	tmp.wr_ptr = ntohl(ring->wr_ptr) & 0x1FFFFFFF;
	tmp.rd_ptr[0] = ntohl(ring->rd_ptr[0]) & 0x1FFFFFFF;
	tmp.size = ntohl(ring->size);

	if (tmp.rd_ptr[0] <= tmp.wr_ptr)
		avail = tmp.wr_ptr - tmp.rd_ptr[0];
	else
		avail = tmp.wr_ptr + tmp.size - tmp.rd_ptr[0];

	avail = tmp.size - avail;

	return avail;
}
*/

static int hw_ring_write(struct RBUF_HEADER *ring, void *data, int len)
{
	struct RBUF_HEADER tmp;
	unsigned int temp;
	unsigned char *ptr = data;

	pr_debug("[ALSA] %s Enter\n", __func__);

	tmp.begin_addr = ntohl(ring->begin_addr) & 0x1FFFFFFF;
	tmp.wr_ptr = ntohl(ring->wr_ptr) & 0x1FFFFFFF;
	tmp.rd_ptr[0] = ntohl(ring->rd_ptr[0]) & 0x1FFFFFFF;
	tmp.size = ntohl(ring->size);

	if (tmp.begin_addr + tmp.size <= tmp.wr_ptr + len) {
		memcpy((unsigned char *)
			(phys_to_virt(ntohl(ring->wr_ptr)&0x1FFFFFFF)),
			ptr, (tmp.begin_addr + tmp.size - tmp.wr_ptr));
		ptr += (tmp.begin_addr + tmp.size - tmp.wr_ptr);
		len -= (tmp.begin_addr + tmp.size - tmp.wr_ptr);
		if (len != 0) {
			memcpy((unsigned char *)
				(phys_to_virt(ntohl(ring->begin_addr)&0x1FFFFFFF)), ptr, len);
			tmp.wr_ptr = tmp.begin_addr + len;
		} else {
			tmp.wr_ptr = tmp.begin_addr;
		}
	} else {
		memcpy((unsigned char *)
			(phys_to_virt(ntohl(ring->wr_ptr)&0x1FFFFFFF)),
			ptr, len);
		pr_debug("[ALSA] ntohl(ring->wr_ptr) = %lx\n",
			(unsigned long)(phys_to_virt(ntohl(ring->wr_ptr)&0x1FFFFFFF)));
		tmp.wr_ptr = tmp.wr_ptr + len;
	}

	temp = 0xa0000000|tmp.wr_ptr;
	ring->wr_ptr = htonl(temp);
	pr_debug("[ALSA] %s Exit\n", __func__);
	return len;
}

int RPC_TOAGENT_INBAND_EOS_SVC(struct snd_pcm_substream *substream)
{
	struct AUDIO_DEC_EOS cmd;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	cmd.header.type = htonl(AUDIO_DEC_INBAND_CMD_TYPE_EOS);
	cmd.header.size = htonl(sizeof(struct AUDIO_DEC_EOS));
	cmd.EOSID = 0;
	cmd.w_ptr = htonl((uint) dpcm->ring_bak[0].wr_ptr);

	hw_ring_write(dpcm->inband, &cmd, sizeof(struct AUDIO_DEC_EOS));
	return 0;
}

int RPC_TOAGENT_EOS_SVC(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	struct AUDIO_RPC_SENDPIN_LONG *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_SENDPIN_LONG *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_SENDPIN_LONG) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_SENDPIN_LONG) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(dpcm->ao_agent);
	info->pin_id = htonl(dpcm->ao_pin_id);
	info->data = htonl((uint) dpcm->ring_bak[0].wr_ptr);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_EOS,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return 0;
}

static int rtk_snd_init_decoder_info(struct snd_pcm_substream *substream)
{
	struct AUDIO_DEC_NEW_FORMAT cmd;
	struct AUDIO_RPC_SENDIO sendio;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	int temp = dpcm->ao_agent|dpcm->ao_pin_id;
	RPC_TOAGENT_PAUSE_SVC(dpcm->card->card, &temp); /* AO pause */

	temp = dpcm->dec_agent;
	RPC_TOAGENT_PAUSE_SVC(dpcm->card->card, &temp); /* Decoder pause */

	sendio.instance_id = dpcm->dec_agent;
	sendio.pin_id = dpcm->dec_pin_id;
	RPC_TOAGENT_FLUSH_SVC(dpcm->card->card, &sendio);

	cmd.audiotype = htonl(AUDIO_LPCM_DECODER_TYPE);
	cmd.header.type = htonl(AUDIO_DEC_INBAMD_CMD_TYPE_NEW_FORMAT);
	cmd.header.size = htonl(sizeof(struct AUDIO_DEC_NEW_FORMAT));
	cmd.pri_info[0] = htonl(runtime->channels);
	cmd.pri_info[1] = htonl(runtime->sample_bits);
	cmd.pri_info[2] = htonl(runtime->rate);
	cmd.pri_info[3] = htonl(0);
	cmd.pri_info[4] = htonl(0);
	cmd.pri_info[5] = htonl(0);
	cmd.pri_info[6] = htonl(0);
	cmd.pri_info[7] = htonl(0);

	switch (runtime->format) {
	case SNDRV_PCM_FORMAT_S16_BE:
	case SNDRV_PCM_FORMAT_U16_BE:
	case SNDRV_PCM_FORMAT_S24_BE:
	case SNDRV_PCM_FORMAT_U24_BE:
	case SNDRV_PCM_FORMAT_S32_BE:
	case SNDRV_PCM_FORMAT_U32_BE:
	case SNDRV_PCM_FORMAT_S24_3BE:
	case SNDRV_PCM_FORMAT_U24_3BE:
	case SNDRV_PCM_FORMAT_S20_3BE:
	case SNDRV_PCM_FORMAT_U20_3BE:
	case SNDRV_PCM_FORMAT_S18_3BE:
	case SNDRV_PCM_FORMAT_U18_3BE:
	case SNDRV_PCM_FORMAT_FLOAT_BE:
	case SNDRV_PCM_FORMAT_FLOAT64_BE:
	case SNDRV_PCM_FORMAT_IEC958_SUBFRAME_BE:
		cmd.pri_info[7] = htonl(AUDIO_BIG_ENDIAN);
		break;
	case SNDRV_PCM_FORMAT_S8:
	case SNDRV_PCM_FORMAT_U8:
	case SNDRV_PCM_FORMAT_S16_LE:
	case SNDRV_PCM_FORMAT_U16_LE:
	case SNDRV_PCM_FORMAT_S24_LE:
	case SNDRV_PCM_FORMAT_U24_LE:
	case SNDRV_PCM_FORMAT_S32_LE:
	case SNDRV_PCM_FORMAT_U32_LE:
	case SNDRV_PCM_FORMAT_S24_3LE:
	case SNDRV_PCM_FORMAT_U24_3LE:
	case SNDRV_PCM_FORMAT_S20_3LE:
	case SNDRV_PCM_FORMAT_U20_3LE:
	case SNDRV_PCM_FORMAT_S18_3LE:
	case SNDRV_PCM_FORMAT_U18_3LE:
	case SNDRV_PCM_FORMAT_FLOAT_LE:
	case SNDRV_PCM_FORMAT_FLOAT64_LE:
	case SNDRV_PCM_FORMAT_IEC958_SUBFRAME_LE:
	case SNDRV_PCM_FORMAT_MU_LAW:
	case SNDRV_PCM_FORMAT_A_LAW:
	case SNDRV_PCM_FORMAT_IMA_ADPCM:
	case SNDRV_PCM_FORMAT_MPEG:
	case SNDRV_PCM_FORMAT_GSM:
	case SNDRV_PCM_FORMAT_SPECIAL:
	default:
		cmd.pri_info[7] = htonl(AUDIO_LITTLE_ENDIAN);
		break;
	}
	cmd.w_ptr = dpcm->ring[0].begin_addr;

	hw_ring_write(dpcm->inband, &cmd, sizeof(struct AUDIO_DEC_NEW_FORMAT));
	return 0;
}

static int rtk_snd_decoder_run(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	int result = 0;

	int temp = dpcm->ao_agent|dpcm->ao_pin_id;

	if (dpcm->audiopath == AUDIO_PATH_DECODER_AO)
		result = RPC_TOAGENT_RUN_SVC(dpcm->card->card, &dpcm->agent_id);

	if (result < 0)
		return result;

	result = RPC_TOAGENT_RUN_SVC(dpcm->card->card, &temp);

	return result;
}

static void rtk_snd_init_decoder_ring(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	struct RPC_RBUF_HEADER ringbuf_header;

	dpcm->pcm_buf_pos = 0;

	/* scprioren add for UNCAC_BASE */
	dpcm->ring = dpcm->hw_ring;
	dpcm->inband = dpcm->hw_inband_ring;

	/* set bitstream ring buffer */
	dpcm->buffer_byte_size =
		frames_to_bytes(runtime, runtime->buffer_size);

	dpcm->ring[0].begin_addr =	htonl(0xa0000000|(((uint) runtime->dma_addr) & 0x1FFFFFFF));
	dpcm->ring[0].buf_id = htonl(RINGBUFFER_STREAM);
	dpcm->ring[0].size = htonl((uint) dpcm->buffer_byte_size);
	dpcm->ring[0].wr_ptr = dpcm->ring[0].begin_addr;
	dpcm->ring[0].rd_ptr[0] = dpcm->ring[0].begin_addr;
	dpcm->ring[0].rd_ptr[1] = dpcm->ring[0].begin_addr;
	dpcm->ring[0].rd_ptr[2] = dpcm->ring[0].begin_addr;
	dpcm->ring[0].rd_ptr[3] = dpcm->ring[0].begin_addr;
	dpcm->ring[0].num_rd_ptr = htonl(1);

	dpcm->ring_bak[0].begin_addr = (unsigned long) runtime->dma_addr;
	dpcm->ring_bak[0].size = dpcm->buffer_byte_size;
	dpcm->ring_bak[0].wr_ptr = dpcm->ring_bak[0].begin_addr;
	dpcm->ring_bak[0].rd_ptr[0] = dpcm->ring_bak[0].begin_addr;
	dpcm->ring_bak[0].rd_ptr[1] = dpcm->ring_bak[0].begin_addr;
	dpcm->ring_bak[0].rd_ptr[2] = dpcm->ring_bak[0].begin_addr;
	dpcm->ring_bak[0].rd_ptr[3] = dpcm->ring_bak[0].begin_addr;
	pr_debug("[ALSA] ring[0].rd_ptr[0] = %x, ring_bak[0].wr_ptr = %lx\n",
		dpcm->ring[0].rd_ptr[0], dpcm->ring_bak[0].wr_ptr);
	pr_debug("[ALSA] decoder input ring buffer %lx %lx\n",
		dpcm->ring_bak[0].size,
		dpcm->ring_bak[0].begin_addr);

	ringbuf_header.instance_id = dpcm->agent_id;
	ringbuf_header.pin_id = BASE_BS_IN;
	ringbuf_header.rbuf_list[0] = (uint) (&dpcm->ring[0]);
	ringbuf_header.rd_idx = 0;
	ringbuf_header.listsize = 1;

	RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &ringbuf_header);

	/* setup inband ring buffer */
	pr_debug("[ALSA] hw_inband_data = %lx\n",
		(unsigned long) dpcm->hw_inband_data);
	dpcm->inband[0].begin_addr =
		htonl(0xa0000000|
		((unsigned int)dpcm->hw_inband_data &
		0x1FFFFFFF));
	pr_debug("[ALSA] inband[0].begin_addr = %x\n", dpcm->inband[0].begin_addr);
	dpcm->inband[0].size = htonl(sizeof(dpcm->hw_inband_data));
	dpcm->inband[0].rd_ptr[0] = dpcm->inband[0].begin_addr;
	dpcm->inband[0].wr_ptr = dpcm->inband[0].begin_addr;
	dpcm->inband[0].num_rd_ptr = htonl(1);

	ringbuf_header.instance_id = dpcm->agent_id;
	ringbuf_header.pin_id = INBAND_QUEUE;
	ringbuf_header.rbuf_list[0] = (uint) (&dpcm->inband[0]);
	ringbuf_header.rd_idx = 0;
	ringbuf_header.listsize = 1;

	RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &ringbuf_header);
	pr_debug("[ALSA] ring[0].rd_ptr[0] = %x\n", dpcm->ring[0].rd_ptr[0]);
}

static int rtk_snd_init_connect_decoder_ao(
	struct snd_pcm_substream *substream)
{
	int i;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	int ring_size;
	struct RPC_RBUF_HEADER ringbuf_header;
	struct AUDIO_RPC_CONNECTION connection;

	dpcm->ao_in_ring = (struct RBUF_HEADER *)
		((unsigned int) dpcm->ao_in_ring_instance);

	pr_debug("[ALSA] ao_in_ring = %lx\n", (unsigned long) dpcm->ao_in_ring);

	ring_size = 8 * 1024;
	pr_debug("[ALSA] internal ring size per channel : %d bytes\n", ring_size);

	for (i = 0; i < runtime->channels; i++) {
		dpcm->ao_in_ring_p[i] =
			dvr_malloc_specific(8 * 1024, GFP_DCU1);
		if (dpcm->ao_in_ring_p[i] == NULL)
			return -ENOMEM;
		pr_debug("[ALSA] ao_in_ring_p[%d] = %lx\n",
			i, (unsigned long)dpcm->ao_in_ring_p[i]);

		dpcm->ao_in_ring[i].begin_addr =
			htonl(0xa0000000|
			(((unsigned int) dpcm->ao_in_ring_p[i])&
			0x1FFFFFFF));

		dpcm->ao_in_ring[i].size = htonl((ring_size));
		dpcm->ao_in_ring[i].rd_ptr[0] = dpcm->ao_in_ring[i].begin_addr;
		dpcm->ao_in_ring[i].rd_ptr[1] = dpcm->ao_in_ring[i].begin_addr;
		dpcm->ao_in_ring[i].rd_ptr[2] = dpcm->ao_in_ring[i].begin_addr;
		dpcm->ao_in_ring[i].rd_ptr[3] = dpcm->ao_in_ring[i].begin_addr;
		dpcm->ao_in_ring[i].wr_ptr = dpcm->ao_in_ring[i].begin_addr;
		dpcm->ao_in_ring[i].num_rd_ptr = htonl(1);
	}

	ringbuf_header.instance_id = dpcm->agent_id;
	ringbuf_header.pin_id = PCM_OUT;
	ringbuf_header.rbuf_list[0] = (unsigned int) &dpcm->ao_in_ring[0];
	ringbuf_header.rbuf_list[1] = (unsigned int) &dpcm->ao_in_ring[1];
	ringbuf_header.rd_idx = -1;
	ringbuf_header.listsize = runtime->channels;

	RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &ringbuf_header);

	ringbuf_header.instance_id = dpcm->ao_agent;
	ringbuf_header.pin_id = dpcm->ao_pin_id;
	ringbuf_header.rd_idx = 0;
	ringbuf_header.rbuf_list[0] = (unsigned int) &dpcm->ao_in_ring[0];
	ringbuf_header.rbuf_list[1] = (unsigned int) &dpcm->ao_in_ring[1];
	ringbuf_header.listsize = runtime->channels;

	RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &ringbuf_header);

	connection.des_instance = dpcm->ao_agent;
	connection.src_instance = dpcm->agent_id;

	connection.src_pin = PCM_OUT;
	connection.des_pin = dpcm->ao_pin_id;
	RPC_TOAGENT_CONNECT_SVC(dpcm->card->card, &connection);

	return 0;
}
#endif

static int rtk_snd_flush(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	struct AUDIO_RPC_SENDIO sendio;
	int ret;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	sendio.instance_id = dpcm->agent_id;
	sendio.pin_id = dpcm->ao_pin_id;

	ret = RPC_TOAGENT_FLUSH_SVC(dpcm->card->card, &sendio);
	/* end of hw buffer flushing */

	dpcm->flush_state = RTK_SND_FLUSH_STATE_FINISH;

	if (ret < 0)
		return -1;

	return 0;
}

static int rtk_snd_pause(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime;
	struct rtk_snd_pcm *dpcm;
	int temp, ret;

	runtime = substream->runtime;
	dpcm = runtime->private_data;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	temp = dpcm->ao_agent|dpcm->ao_pin_id;
	ret = RPC_TOAGENT_PAUSE_SVC(dpcm->card->card, &temp);

	if (ret < 0)
		return -1;

	return 0;
}

static char *snd_access_mode[SNDRV_PCM_ACCESS_LAST+1] = {
	"SND_PCM_ACCESS_MMAP_INTERLEAVED",
	/** mmap access with simple non interleaved channels */
	"SND_PCM_ACCESS_MMAP_NONINTERLEAVED",
	/** mmap access with complex placement */
	"SND_PCM_ACCESS_MMAP_COMPLEX",
	/** snd_pcm_readi/snd_pcm_writei access */
	"SND_PCM_ACCESS_RW_INTERLEAVED",
	/** snd_pcm_readn/snd_pcm_writen access */
	"SND_PCM_ACCESS_RW_NONINTERLEAVED",
};

static int rtk_snd_init_ao_ring(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	struct rtk_snd_pcm *dpcm_audio = (struct rtk_snd_pcm *) (dpcm->phy_addr|0xa0000000);

	struct RPC_RBUF_HEADER *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long retval;

	int i, ret = 0;
	dma_addr_t dat;
	void *p;
	unsigned long count, phy_addr_ring;

	pr_debug("[ALSA] %s\n", __func__);

	dpcm->pcm_buf_pos = 0;
	dpcm->ring = (struct RBUF_HEADER *)((unsigned long) dpcm->hw_ring);
	dpcm->ao_in_ring = dpcm->ring;
	dpcm->buffer_byte_size =
		runtime->buffer_size * frames_to_bytes(runtime, 1);

	pr_debug("[ALSA] buffer_byte_size %ld\n", dpcm->buffer_byte_size);

	for (i = 0; i < 1; i++) {
		dpcm->ring[i].begin_addr = htonl(0xa0000000|(((unsigned int) runtime->dma_addr) & 0x1FFFFFFF));
		dpcm->ring_bak[i].begin_addr = (unsigned long) runtime->dma_addr;

		dpcm->ring[i].buf_id = htonl(RINGBUFFER_STREAM);
		dpcm->ring[i].size = htonl(dpcm->buffer_byte_size);
		dpcm->ring[i].wr_ptr = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[0] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[1] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[2] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[3] = dpcm->ring[i].begin_addr;

		dpcm->ring_bak[i].size = dpcm->buffer_byte_size;
		dpcm->ring_bak[i].wr_ptr = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[0] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[1] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[2] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[3] = dpcm->ring_bak[i].begin_addr;
	}

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
	pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_KERNEL | __GFP_DMA);
	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct RPC_RBUF_HEADER *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct RPC_RBUF_HEADER) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct RPC_RBUF_HEADER) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(dpcm->ao_agent);
	info->pin_id = htonl(dpcm->ao_pin_id);
	info->rd_idx = htonl(0);
	info->listsize = htonl(1);

	for (i = 0; i < 1; i++) {
		count = (unsigned long)&dpcm->ring[i] - (unsigned long)dpcm;
		phy_addr_ring = (unsigned long)dpcm_audio + count;

		info->rbuf_list[i] =
			htonl(0xa0000000|
			((((unsigned long)phy_addr_ring))&0x1FFFFFFF));
	}

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_INIT_RINGBUF,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &retval)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		ret = -1;
		goto exit;
	}

	pr_debug("[ALSA] RING INITIALIZED\n");
	pr_debug("[ALSA] channel = %d\n", runtime->channels);
	pr_debug("[ALSA] frames_to_bytes = %d\n", frames_to_bytes(runtime, 1));
	pr_debug("[ALSA] samples_to_bytes = %d\n", samples_to_bytes(runtime, 1));
	pr_debug("[ALSA] buffer size = %d\n", (int) runtime->buffer_size);
	pr_debug("[ALSA] ACCESS MODE=%s", snd_access_mode[runtime->access]);
	for (i = 0; i < runtime->channels; i++) {
		pr_debug("[ALSA] buf_header[%d].magic = %x\n",
			i, ntohl(dpcm->ring[i].magic));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].begin_addr = %x\n",
			i, ntohl(dpcm->ring[i].begin_addr));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].size = %x\n",
			i, ntohl(dpcm->ring[i].size));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].rd_ptr[0] = %x\n",
			i, ntohl(dpcm->ring[i].rd_ptr[0]));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].rd_ptr[1] = %x\n",
			i, ntohl(dpcm->ring[i].rd_ptr[1]));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].wr_ptr = %x\n",
			i, ntohl(dpcm->ring[i].wr_ptr));
	}

exit:
	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return ret;
}

static int rtk_snd_init_ai_ring(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	struct RPC_RBUF_HEADER *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long retval;

	int ret = 0;
	dma_addr_t dat;
	void *p;
	int i;

	/* allocate ring buffer */
	dpcm->ring = (struct RBUF_HEADER *)((unsigned long) dpcm->hw_ring);
	/* frames per buffer * sample_bytes */
	dpcm->buffer_byte_size = runtime->buffer_size * dpcm->input_sample_bytes;

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	dpcm->ring_p = dma_alloc_coherent(dpcm->card->card->dev,runtime->channels * dpcm->buffer_byte_size,&dpcm->ring_phy_addr, GFP_ATOMIC);

	for (i = 0; i < runtime->channels; i++) {
		dpcm->hw_ai_ring_data[i] =
			dpcm->ring_p + i * dpcm->buffer_byte_size;

		if (dpcm->hw_ai_ring_data[i] == NULL)
			return -ENOMEM;

		/* uncache address for Audio FW */
		dpcm->ring[i].begin_addr =
			htonl(0xa0000000|
			(((unsigned int) dpcm->hw_ai_ring_data[i]) & 0x1FFFFFFF));
		dpcm->ring_bak[i].begin_addr =
			((unsigned long) dpcm->hw_ai_ring_data[i]);

		dpcm->ring[i].buf_id = htonl(RINGBUFFER_STREAM);
		dpcm->ring[i].size = htonl((uint) dpcm->buffer_byte_size);
		dpcm->ring[i].num_rd_ptr = htonl(1);
		dpcm->ring[i].wr_ptr = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[0] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[1] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[2] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[3] = dpcm->ring[i].begin_addr;

		dpcm->ring_bak[i].size = dpcm->buffer_byte_size;
		dpcm->ring_bak[i].num_rd_ptr = 1;
		dpcm->ring_bak[i].wr_ptr = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[0] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[1] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[2] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[3] = dpcm->ring_bak[i].begin_addr;
	}

	/* send init ring rpc */

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct RPC_RBUF_HEADER *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct RPC_RBUF_HEADER) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct RPC_RBUF_HEADER) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(dpcm->ai_cap_agent);
	info->pin_id = htonl(dpcm->ai_cap_pin);
	info->rd_idx = htonl(-1);
	info->listsize = htonl(runtime->channels);

	for (i = 0; i < runtime->channels; i++) {
		/* uncache address for Audio FW */
		info->rbuf_list[i] =
			htonl(0xa0000000|(((unsigned int) &dpcm->ring[i])&0x1FFFFFFF));
	}

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_INIT_RINGBUF,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &retval)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		ret = -1;
		goto exit;
	}

	pr_debug("[ALSA] ALSA RING INITIALIZED\n");
	pr_debug("[ALSA] channel = %d\n", runtime->channels);
	pr_debug("[ALSA] frames_to_bytes = %d\n", frames_to_bytes(runtime, 1));
	pr_debug("[ALSA] samples_to_bytes = %d\n", samples_to_bytes(runtime, 1));
	pr_debug("[ALSA] buffer size = %d\n", (int) runtime->buffer_size);
	pr_debug("[ALSA] ACCESS MODE=%s", snd_access_mode[runtime->access]);
	for (i = 0; i < runtime->channels; i++) {
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].begin_addr = %x\n",
			i, ntohl(dpcm->ring[i].begin_addr));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].size = %x\n",
			i, ntohl(dpcm->ring[i].size));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].rd_ptr[0] = %x\n",
			i, ntohl(dpcm->ring[i].rd_ptr[0]));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].wr_ptr = %x\n",
			i, ntohl(dpcm->ring[i].wr_ptr));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].rd_ptr[0] = %lx\n",
			i, dpcm->ring_bak[i].rd_ptr[0]);
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].wr_ptr = %lx\n",
			i, dpcm->ring_bak[i].wr_ptr);
	}

exit:
	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return ret;
}

/* init AO capture ring */
static int rtk_snd_init_ao_capture_ring(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	struct RPC_RBUF_HEADER *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long retval;

	int ret = 0;
	dma_addr_t dat;
	void *p;
	int i;

	/* allocate ring buffer */
	dpcm->ring = (struct RBUF_HEADER *)((unsigned long) dpcm->hw_ring);
	dpcm->buffer_byte_size =
		runtime->buffer_size * dpcm->input_sample_bytes;

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	dpcm->ring_p = dma_alloc_coherent(dpcm->card->card->dev,runtime->channels * dpcm->buffer_byte_size,&dpcm->ring_phy_addr, GFP_ATOMIC);

	for (i = 0; i < runtime->channels; i++) {
		dpcm->hw_ai_ring_data[i] =
			dpcm->ring_p + i * dpcm->buffer_byte_size;

		if (dpcm->hw_ai_ring_data[i] == NULL)
			return -ENOMEM;

		/* uncache address for Audio FW */
		dpcm->ring[i].begin_addr =
			htonl(0xa0000000 |
			(((unsigned int) dpcm->hw_ai_ring_data[i]) & 0x1FFFFFFF));
		dpcm->ring_bak[i].begin_addr =
			((unsigned long) dpcm->hw_ai_ring_data[i]);

		dpcm->ring[i].buf_id = htonl(RINGBUFFER_STREAM);
		dpcm->ring[i].size = htonl((uint) dpcm->buffer_byte_size);
		dpcm->ring[i].num_rd_ptr = htonl(1);
		dpcm->ring[i].wr_ptr = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[0] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[1] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[2] = dpcm->ring[i].begin_addr;
		dpcm->ring[i].rd_ptr[3] = dpcm->ring[i].begin_addr;

		dpcm->ring_bak[i].size = dpcm->buffer_byte_size;
		dpcm->ring_bak[i].num_rd_ptr = 1;
		dpcm->ring_bak[i].wr_ptr = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[0] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[1] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[2] = dpcm->ring_bak[i].begin_addr;
		dpcm->ring_bak[i].rd_ptr[3] = dpcm->ring_bak[i].begin_addr;
	}

	/* send init ring rpc */

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		ret = -ENOMEM;
		goto exit;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct RPC_RBUF_HEADER *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct RPC_RBUF_HEADER) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct RPC_RBUF_HEADER) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(dpcm->ao_cap_agent);
	info->pin_id = htonl(dpcm->ao_cap_pin);
	info->rd_idx = htonl(-1);
	info->listsize = htonl(runtime->channels);

	for (i = 0; i < runtime->channels; i++) {
		/* uncache address for Audio FW */
		info->rbuf_list[i] =
			htonl(0xa0000000|(((unsigned int) &dpcm->ring[i])&0x1FFFFFFF));
	}

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_INIT_RINGBUF,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &retval)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		ret = -1;
		goto exit;
	}

#ifdef ALSA_DEBUG_LOG
	pr_debug("[ALSA] ALSA RING INITIALIZED\n");
	pr_debug("[ALSA] channel = %d\n", runtime->channels);
	pr_debug("[ALSA] frames_to_bytes = %d\n", frames_to_bytes(runtime, 1));
	pr_debug("[ALSA] samples_to_bytes = %d\n", samples_to_bytes(runtime, 1));
	pr_debug("[ALSA] buffer size = %d\n", (int) runtime->buffer_size);
	pr_debug("[ALSA] ACCESS MODE=%s", snd_access_mode[runtime->access]);
	for (i = 0; i < runtime->channels; i++) {
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].begin_addr = %x\n",
			i, ntohl(dpcm->ring[i].begin_addr));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].size = %x\n",
			i, ntohl(dpcm->ring[i].size));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].rd_ptr[0] = %x\n",
			i, ntohl(dpcm->ring[i].rd_ptr[0]));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].wr_ptr = %x\n",
			i, ntohl(dpcm->ring[i].wr_ptr));
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].rd_ptr[0] = %x\n",
			i, dpcm->ring_bak[i].rd_ptr[0]);
		pr_debug("[ALSA] snd_rtk_buffer_header[%d].wr_ptr = %x\n",
			i, dpcm->ring_bak[i].wr_ptr);
	}
#endif

exit:
	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return ret;
}

static void rtk_snd_resume(struct snd_pcm_substream *substream)
{
	unsigned int temp;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	pr_debug("[ALSA] %s\n", __func__);

	if (dpcm->audiopath == AUDIO_PATH_DECODER_AO) {
		rtk_snd_decoder_run(substream);
	} else {
		pr_debug("[ALSA] Flash Pin =%d\n", dpcm->ao_pin_id);
		temp = (dpcm->ao_agent | dpcm->ao_pin_id);
		RPC_TOAGENT_RUN_SVC(dpcm->card->card, &temp);
	}
}

static int rtk_snd_set_volume(struct snd_card_mars *mars)
{
	dma_addr_t dat;
	void *p;
	unsigned long ret;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id, pin_id, i;

	pr_debug("[ALSA] %s\n", __func__);

    mars->card->dev->dma_mask = &mars->card->dev->coherent_dma_mask;
    if(dma_set_mask(mars->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(mars->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(mars->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *)((uint) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM)+8) & 0xFFFFFFFC));

	for (i = 0; i < MIXER_ADDR_MAX; i++) {
		if ((mars->ao_pin_id[i] != 0) && (alsa_agent != -1) &&
			(mars->ao_flash_change[i] != 0)) {

			memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
			instance_id = alsa_agent;
			cmd->instance_id = htonl(instance_id);
			cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_CONTROL_FLASH_VOLUME);
			pin_id = mars->ao_pin_id[i];
			cmd->pri_info[0] = htonl(pin_id);
			cmd->pri_info[1] = htonl(mars->ao_flash_volume[i]);

			pr_debug("[ALSA] volume = %d, pin_id = %d\n",
				mars->ao_flash_volume[i], pin_id);

			if (audio_send_rpc_command(RPC_AUDIO,
				ENUM_KERNEL_RPC_PRIVATEINFO,
				(unsigned int) cmd_audio,
				(unsigned int) res_audio,
				(unsigned long) res, &ret)) {
				pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
				dma_free_coherent(mars->card->dev, 4096, p, dat);
				return -1;
			}

			mars->ao_flash_change[i] = 0;
		} else {
			pr_debug("[ALSA] no running AO flash pin_id, don't set volume\n");
		}
	}

	dma_free_coherent(mars->card->dev, 4096, p, dat);
	return 0;
}

static void rtk_snd_playback_volume_work(struct work_struct *work)
{
	struct snd_card_mars *mars = container_of(work,
		struct snd_card_mars, work_volume);
	rtk_snd_set_volume(mars);
}

static int rtk_snd_set_ao_flashpin_volume(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd , *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id, pin_id;

	pr_debug("[ALSA] %s\n", __func__);

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *)((uint) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = alsa_agent;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_CONTROL_FLASH_VOLUME);
	pin_id = dpcm->ao_pin_id;
	cmd->pri_info[0] = htonl(pin_id);
	cmd->pri_info[1] = htonl(dpcm->volume);

	pr_debug("[ALSA] dpcm->volume= %d\n", dpcm->volume);
	dpcm->volume_change = 0;

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int) cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return pin_id;
}

#ifdef USE_FIXED_AO_PINID
static int rtk_snd_get_used_pin_id(struct snd_card *card)
{
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id, pin_map;

	pr_debug("[ALSA] %s\n", __func__);

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *)((uint) dat | 0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat | 0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = alsa_agent;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_QUERY_FLASH_PIN);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int)cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	pin_map = ntohl(cmd->pri_info[0]);

	dma_free_coherent(card->dev, 4096, p, dat);

	return pin_map;
}

static int rtk_snd_set_flashpin_id(struct snd_card *card, int pin)
{
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id;

	pr_debug("[ALSA] %s\n", __func__);

	card->dev->dma_mask = &card->dev->coherent_dma_mask;
	if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
	}
	arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);
	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *) ((uint) dat | 0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat | 0xa0000000) + sizeof(struct RPC_PRI_PARAM)+8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = alsa_agent;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_SET_FLASH_PIN);
	cmd->pri_info[0] = htonl(pin);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int) cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}
#else
static int rtk_snd_query_flashpin_id(struct snd_card *card)
{
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id, pin_id;

	pr_debug("[ALSA] %s\n", __func__);

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);
	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *) ((uint) dat | 0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
			((((uint)(dat | 0xa0000000) + sizeof(struct RPC_PRI_PARAM)+8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = alsa_agent;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_GET_FLASH_PIN);
	cmd->pri_info[0] = 0xFF;
	cmd->pri_info[1] = 0xFF;
	cmd->pri_info[2] = 0xFF;
	cmd->pri_info[3] = 0xFF;
	cmd->pri_info[4] = 0xFF;
	cmd->pri_info[5] = 0xFF;

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int)cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	pin_id = ntohl(cmd->pri_info[0]);

	dma_free_coherent(card->dev, 4096, p, dat);

	if (pin_id < FLASH_AUDIO_PIN_1 || pin_id > FLASH_AUDIO_PIN_8)
		return -1;

	return pin_id;
}
#endif

static int rtk_snd_release_flashpin_id(struct snd_card *card, int pin_id)
{
	unsigned long ret;
	struct RPC_PRI_PARAM *cmd , *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id;
	dma_addr_t dat;
	void *p;

	if (pin_id < FLASH_AUDIO_PIN_1 || pin_id > FLASH_AUDIO_PIN_8)
			return -1;

	pr_debug("[ALSA] %s\n", __func__);

	card->dev->dma_mask = &card->dev->coherent_dma_mask;
	if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
	}
	arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);
	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *) ((uint) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = alsa_agent;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_RELEASE_FLASH_PIN);
	cmd->pri_info[0] = htonl(pin_id);
	cmd->pri_info[1] = 0xFF;
	cmd->pri_info[2] = 0xFF;
	cmd->pri_info[3] = 0xFF;
	cmd->pri_info[4] = 0xFF;
	cmd->pri_info[5] = 0xFF;

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int) cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

static int rtk_snd_ao_info(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id;

	int temp = dpcm->ao_agent | dpcm->ao_pin_id;
	RPC_TOAGENT_PAUSE_SVC(dpcm->card->card, &temp); /* AO pause */

	pr_debug("[ALSA] %s\n", __func__);

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *) ((uint) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = dpcm->ao_agent | dpcm->ao_pin_id;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_CONFIG_CMD_BS_INFO);
	cmd->pri_info[0] = htonl(runtime->channels); /* channel number */

	pr_debug("[ALSA] format %d\n", runtime->format);
	pr_debug("[ALSA] channels %d\n", runtime->channels);

	if ((dpcm->audiopath == AUDIO_PATH_AO_BYPASS) ||
		(dpcm->audiopath == AUDIO_PATH_AO)) {
		/*
		0	32 bit big endian
		1	24 bit big endian
		2	16 bit big endian
		3	24 bit little endian
		4	16 bit little endian
		5	8 bit
		*/
		switch (runtime->format) {
		case SNDRV_PCM_FORMAT_S32_BE:
			cmd->pri_info[1] = htonl(0);
			break;
		case SNDRV_PCM_FORMAT_S24_BE:
			cmd->pri_info[1] = htonl(1);
			break;
		case SNDRV_PCM_FORMAT_S24_LE:
			cmd->pri_info[1] = htonl(3);
			break;
		case SNDRV_PCM_FORMAT_S16_BE:
		case SNDRV_PCM_FORMAT_S16_LE:
			cmd->pri_info[1] = htonl(0x84);
			break;
		case SNDRV_PCM_FORMAT_S8:
			cmd->pri_info[1] = htonl(5);
			break;
		default:
			cmd->pri_info[1] = htonl(0);
			break;
		}
	} else {
		cmd->pri_info[1] = htonl(0);
	}

	pr_debug("[ALSA] pri_info[1] %d\n", htonl(cmd->pri_info[1]));
	pr_debug("[ALSA] rate %d\n", runtime->rate);

	cmd->pri_info[2] = htonl(runtime->rate);
	cmd->pri_info[4] = htonl(dpcm->ao_pin_id);

	/* channel mapping,
	ALSA driver only supports case 1 and case 2 now */
	switch (runtime->channels) {
	case 1:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(0);
		cmd->pri_info[7] = htonl(0);
		cmd->pri_info[8] = htonl(0);
		cmd->pri_info[9] = htonl(0);
		cmd->pri_info[10] = htonl(0);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	case 2:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(0);
		cmd->pri_info[8] = htonl(0);
		cmd->pri_info[9] = htonl(0);
		cmd->pri_info[10] = htonl(0);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	case 3:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(AUDIO_LFE_INDEX);
		cmd->pri_info[8] = htonl(0);
		cmd->pri_info[9] = htonl(0);
		cmd->pri_info[10] = htonl(0);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	case 4:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(AUDIO_LEFT_SURROUND_REAR_INDEX);
		cmd->pri_info[8] = htonl(AUDIO_RIGHT_SURROUND_REAR_INDEX);
		cmd->pri_info[9] = htonl(0);
		cmd->pri_info[10] = htonl(0);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	case 5:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(AUDIO_LEFT_SURROUND_REAR_INDEX);
		cmd->pri_info[8] = htonl(AUDIO_RIGHT_SURROUND_REAR_INDEX);
		cmd->pri_info[9] = htonl(AUDIO_CENTER_FRONT_INDEX);
		cmd->pri_info[10] = htonl(0);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	case 6:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(AUDIO_LEFT_SURROUND_REAR_INDEX);
		cmd->pri_info[8] = htonl(AUDIO_RIGHT_SURROUND_REAR_INDEX);
		cmd->pri_info[9] = htonl(AUDIO_CENTER_FRONT_INDEX);
		cmd->pri_info[10] = htonl(AUDIO_LFE_INDEX);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	case 7:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(AUDIO_LEFT_SURROUND_REAR_INDEX);
		cmd->pri_info[8] = htonl(AUDIO_RIGHT_SURROUND_REAR_INDEX);
		cmd->pri_info[9] = htonl(AUDIO_CENTER_FRONT_INDEX);
		cmd->pri_info[10] = htonl(AUDIO_LFE_INDEX);
		cmd->pri_info[11] = htonl(AUDIO_CENTER_SURROUND_REAR_INDEX);
		cmd->pri_info[12] = htonl(0);
		break;
	case 8:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(AUDIO_LEFT_SURROUND_REAR_INDEX);
		cmd->pri_info[8] = htonl(AUDIO_RIGHT_SURROUND_REAR_INDEX);
		cmd->pri_info[9] = htonl(AUDIO_CENTER_FRONT_INDEX);
		cmd->pri_info[10] = htonl(AUDIO_LFE_INDEX);
		cmd->pri_info[11] = htonl(AUDIO_LEFT_OUTSIDE_FRONT_INDEX);
		cmd->pri_info[12] = htonl(AUDIO_RIGHT_OUTSIDE_FRONT_INDEX);
		break;
	default:
		cmd->pri_info[5] = htonl(AUDIO_LEFT_FRONT_INDEX);
		cmd->pri_info[6] = htonl(AUDIO_RIGHT_FRONT_INDEX);
		cmd->pri_info[7] = htonl(0);
		cmd->pri_info[8] = htonl(0);
		cmd->pri_info[9] = htonl(0);
		cmd->pri_info[10] = htonl(0);
		cmd->pri_info[11] = htonl(0);
		cmd->pri_info[12] = htonl(0);
		break;
	}

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int) cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return 0;
}

int RPC_TOAGENT_CHECK_AO_READY(struct snd_card *card)
{
	unsigned int *info, *info_audio;
	struct RPCRES *res, *res_audio;

	unsigned long ret;
	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (unsigned int *)((unsigned int) dat | 0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct RPCRES) + 8) &
			0xFFFFFFFC));

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_CHECK_READY,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	if (info == 0) {
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(card->dev, 4096, p, dat);
	return 0;
}

static int rtk_snd_check_ao_ready(struct snd_card *card)
{
	DEFINE_WAIT(wait);
	wait_queue_head_t q;	/* for blocking read */
	long remain_time;
	pr_debug("[ALSA] %s %d enter\n", __func__, __LINE__);

	/* Initialize wait queue... */
	init_waitqueue_head(&q);
	do {
		if (RPC_TOAGENT_CHECK_AO_READY(card) != 0) {
			pr_debug("[ALSA] wait AO READY\n");
		} else {
			pr_debug("[ALSA] AO ready .....\n");
			return 0;
		}

		prepare_to_wait(&q, &wait, TASK_INTERRUPTIBLE);
		remain_time = schedule_timeout(HZ);
		finish_wait(&q, &wait);
	} while (remain_time == 0);

	return 1;
}

static int rtk_snd_create_ao_agent(struct snd_card *card)
{
	struct AUDIO_RPC_INSTANCE *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

    card->dev->dma_mask = &card->dev->coherent_dma_mask;
    if(dma_set_mask(card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_INSTANCE *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_INSTANCE) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_INSTANCE) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(0);
	info->type = htonl(AUDIO_OUT);
	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_CREATE_AGENT,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(card->dev, 4096, p, dat);
		return -1;
	}

	alsa_agent = ntohl(res->data);

	dma_free_coherent(card->dev, 4096, p, dat);
	pr_debug("[ALSA] AO agent ID = %d\n", alsa_agent);
	return 0;
}

/* create AI agent to get Instance ID for capture */
static int rtk_snd_create_ai_agent(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	struct AUDIO_RPC_INSTANCE *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;
	dma_addr_t dat;
	void *p;

	if (snd_open_ai_count >= MAX_AI_DEVICES) {
		pr_err("[ALSA] too more capture open %d\n", __LINE__);
		return -1;
	}

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);
	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_INSTANCE *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_INSTANCE) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_INSTANCE) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(-1);
	info->type = htonl(AUDIO_IN);

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_CREATE_AGENT,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dpcm->ai_cap_agent = ntohl(res->data);
	dpcm->ao_cap_agent =  -1;

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	pr_debug("[ALSA] AI agent ID = %d\n", dpcm->ai_cap_agent);
	snd_open_ai_count++;
	return 0;
}

/* create AO agent to get Instance ID for capture */
static int rtk_snd_create_ao_capture_agent(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	struct AUDIO_RPC_INSTANCE *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;
	dma_addr_t dat;
	void *p;

	if (snd_open_ai_count >= MAX_AI_DEVICES) {
		pr_err("[ALSA] capture busy %d\n", __LINE__);
		return -1;
	}

	if (rtk_snd_check_ao_ready(dpcm->card->card)) {
		pr_err("[ALSA] ao not ready\n");
		return -1;
	}

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	info = p;
	info_audio = (struct AUDIO_RPC_INSTANCE *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(struct AUDIO_RPC_INSTANCE) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct AUDIO_RPC_INSTANCE) + 8) &
			0xFFFFFFFC));

	info->instance_id = htonl(0);
	info->type = htonl(AUDIO_OUT);

	pr_debug("[ALSA] [%s %d]\n", __func__, __LINE__);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_CREATE_AGENT,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dpcm->ao_cap_agent = ntohl(res->data);
	dpcm->ai_cap_agent = -1;

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	pr_debug("[ALSA] AO capture agent ID = %d\n", dpcm->ao_cap_agent);
	snd_open_ai_count++;
	return 0;
}

static int rtk_snd_init(struct snd_card *card)
{
	static int init = 1;
	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	if (init == 0)
		return 0;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	if (rtk_snd_check_ao_ready(card))
		return -1;

	rtk_snd_create_ao_agent(card);
	init = 0;
	return 0;
}

static int rtk_snd_open(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	int pin, ret;
#ifdef USE_FIXED_AO_PINID
	int pinmap[8], i, error_handle, dev_num;

	error_handle = 0;
	dev_num = substream->pcm->device;
#endif

	pin = 0;
	ret = 0;

	dpcm->ao_pin_id = 0;

	if (snd_open_count >= MAX_PCM_SUBSTREAMS) {
		pr_err("[ALSA] too more open %d\n", MAX_PCM_SUBSTREAMS);
		ret = -1;
		goto exit;
	}

#ifdef USE_FIXED_AO_PINID
	pin = rtk_snd_get_used_pin_id(dpcm->card->card);
	pr_debug("[ALSA] FW used pinmap %x\n", pin);

	for(i = 0; i < 8; i++) {
		pinmap[i] = pin % 2;
		pin = pin / 2;
	}

	if(used_ao_pin[dev_num] == 0 && pinmap[dev_num] == 1) {
		dpcm->ao_pin_id = FLASH_AUDIO_PIN_1 + dev_num;
		used_ao_pin[dev_num] = 1;
		if (rtk_snd_set_flashpin_id(dpcm->card->card, dpcm->ao_pin_id)) {
			pr_err("[ALSA] set flashpin fail\n");
			ret = -1;
			goto exit;
		}
		pr_debug("[ALSA] use fixed pin %d\n", dev_num);
	} else {
		pr_err("[ALSA] device %d already opened\n", dev_num);
		error_handle = 1;
	}

	if (error_handle == 1) {
		if (used_ao_pin[dev_num] == 0) {
			pr_err("[ALSA] error handle for pin release\n");
			dpcm->ao_pin_id = FLASH_AUDIO_PIN_1 + dev_num;
			used_ao_pin[dev_num] = 1;

			/* error handle for preclose */
			if (flush_error[dev_num] > 0) {
				rtk_snd_flush(substream);
				flush_error[dev_num] = 0;
			}
			if (pause_error[dev_num] > 0) {
				rtk_snd_pause(substream);
				pause_error[dev_num] = 0;
			}
			if (close_error[dev_num] > 0) {
				rtk_snd_close(substream);
				close_error[dev_num] = 0;
			}
			if (release_error[dev_num] > 0) {
				rtk_snd_release_flashpin_id(dpcm->card->card, dpcm->ao_pin_id);
				release_error[dev_num] = 0;
			}

			if (rtk_snd_set_flashpin_id(dpcm->card->card, dpcm->ao_pin_id)) {
				pr_err("[ALSA] set flashpin fail\n");
				ret = -1;
				goto exit;
			}
			pr_debug("[ALSA] use fixed pin\n");
		} else {
			pr_err("[ALSA] need check status\n");

			for (i = 0; i < 8; i++) {
				pr_err("[ALSA] pinmap[%d] = %d, used_ao_pin[%d] = %d\n",
					i, pinmap[i], i, used_ao_pin[i]);
			}

			ret = -1;
			goto exit;
		}
	}

#else
	dpcm->ao_pin_id = rtk_snd_query_flashpin_id(dpcm->card->card);
	pr_debug("[ALSA] use query pin\n");
	if (dpcm->ao_pin_id < 0) {
		pr_err("[ALSA] can't get flash pin");
		ret = -1;
		goto exit;
	}
#endif

	dpcm->ring_init = 0;
	dpcm->volume_change = 0;
	snd_open_count++;

	pr_debug("[ALSA] Audio AgentID = %d pin_id = %d\n",
		dpcm->ao_agent, dpcm->ao_pin_id);

exit:
	return ret;
}

static int rtk_snd_close(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime;
	struct rtk_snd_pcm *dpcm;
	struct RPC_RBUF_HEADER buf;
	int ret = 0;
	int result = 0;
	int i;
	int temp;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);
	runtime = substream->runtime;
	dpcm = runtime->private_data;

	/* re-initialize ring buffer with null ring */
	buf.instance_id = dpcm->ao_agent;
	buf.pin_id = dpcm->ao_pin_id;
	buf.rd_idx = 0;
	buf.listsize = 0;

	for (i = 0; i < 8; i++)
		buf.rbuf_list[i] = 0;

	/*stop AO agent*/
	temp = dpcm->ao_agent | dpcm->ao_pin_id;
	result = RPC_TOAGENT_STOP_SVC(dpcm->card->card, &temp);

	/* stop decoder */
	if (dpcm->audiopath == AUDIO_PATH_DECODER_AO)
		RPC_TOAGENT_STOP_SVC(dpcm->card->card, &dpcm->agent_id);

	/* initial ring buffer NULL */
	ret = RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &buf);

	/* destroy decoder instance if exist */
	if (dpcm->audiopath == AUDIO_PATH_DECODER_AO)
		ret = RPC_TOAGENT_DESTROY_SVC(dpcm->card->card, &dpcm->agent_id);

	return ret;
}

static int snd_realtek_ai_hw_close(struct snd_pcm_substream *substream)
{
	unsigned int instance_id;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	struct RPC_RBUF_HEADER buf;
	int ret = 0;
	int i;

	instance_id = ((dpcm->ai_cap_agent&0xFFFFFFF0)|(dpcm->ai_cap_pin&0xF));

	/* stop AI */
	RPC_TOAGENT_STOP_SVC(dpcm->card->card, &instance_id);
	pr_debug("[ALSA] AI stop success\n");

	/* re-initialize ring buffer with null ring */
	buf.instance_id = dpcm->ai_cap_agent;
	buf.pin_id = dpcm->ai_cap_pin;
	buf.rd_idx = 0;
	buf.listsize = 0;

	for (i = 0; i < 8; i++)
		buf.rbuf_list[i] = 0;

	/* initial ring buffer NULL */
	ret = RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &buf);
	pr_debug("[ALSA] AI init ring success\n");

	return 0;
}

static int snd_realtek_ao_capture_hw_close(struct snd_pcm_substream *substream)
{
	unsigned int instance_id;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	struct RPC_RBUF_HEADER buf;
	int ret = 0;
	int i;

	instance_id = ((dpcm->ao_cap_agent&0xFFFFFFF0)|(dpcm->ao_cap_pin&0xF));

	/* re-initialize ring buffer with null ring */
	buf.instance_id = dpcm->ao_cap_agent;
	buf.pin_id = dpcm->ao_cap_pin;
	buf.rd_idx = 0;
	buf.listsize = 0;

	for (i = 0; i < 8; i++)
		buf.rbuf_list[i] = 0;

	/* initial ring buffer NULL */
	ret = RPC_TOAGENT_INITRINGBUFFER_HEADER_SVC(dpcm->card->card, &buf);
	pr_debug("[ALSA] AO capture init ring success\n");

	return 0;
}

static void rtk_snd_pcm_timer_start(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	struct timeval t;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

#ifdef ALSA_DEBUG_LOG
	pr_debug("[ALSA] period_size = %d\n", runtime->period_size);
	pr_debug("[ALSA] period_jiffies = %d, rate = %d\n",
		dpcm->period_jiffies, runtime->rate);
#endif

	dpcm->period_jiffies = 1;

	do_gettimeofday(&t);
	dpcm->pre_time_ms = t.tv_sec*1000 + t.tv_usec/1000;
	dpcm->pre_no_datatime_ms = 0;
	dpcm->pre_wr_ptr = (ntohl(dpcm->ring[0].begin_addr) & 0x1FFFFFFF);
	dpcm->max_level = 0;
	dpcm->min_level = dpcm->buffer_byte_size;
	dpcm->total_data_wb = 0;

	spin_lock(dpcm->pcm_lock);
	mod_timer(&dpcm->timer, jiffies + 1);
	dpcm->running = 1;
	spin_unlock(dpcm->pcm_lock);
}

static void rtk_snd_pcm_timer_stop(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	spin_lock(dpcm->pcm_lock);
	dpcm->running = 0;
	del_timer(&dpcm->timer);
	pr_debug("[ALSA] del timer stop\n");
	spin_unlock(dpcm->pcm_lock);
}

static void rtk_snd_pcm_capture_timer_start(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	struct timeval t;

	dpcm->pcm_buf_pos = 0;
	dpcm->period_jiffies = 1;

	do_gettimeofday(&t);
	dpcm->last_time_ms = t.tv_sec*1000 + t.tv_usec/1000;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	spin_lock(dpcm->pcm_lock);
	mod_timer(&dpcm->timer, jiffies + 1);
	dpcm->running = 1;
	spin_unlock(dpcm->pcm_lock);
}

static void rtk_snd_pcm_capture_timer_stop(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

	spin_lock(dpcm->pcm_lock);
	dpcm->running = 0;
	del_timer(&dpcm->timer);
	spin_unlock(dpcm->pcm_lock);
}

static int rtk_snd_playback_trigger(
	struct snd_pcm_substream *substream, int cmd)
{
	if (cmd == SNDRV_PCM_TRIGGER_START)
		rtk_snd_pcm_timer_start(substream);
	else if (cmd == SNDRV_PCM_TRIGGER_STOP)
		rtk_snd_pcm_timer_stop(substream);
	else
		return -EINVAL;

	return 0;
}

static int rtk_snd_capture_trigger(
	struct snd_pcm_substream *substream, int cmd)
{
	if (cmd == SNDRV_PCM_TRIGGER_START)
		rtk_snd_pcm_capture_timer_start(substream);
	else if (cmd == SNDRV_PCM_TRIGGER_STOP)
		rtk_snd_pcm_capture_timer_stop(substream);
	else
		return -EINVAL;

	return 0;
}

static int rtk_snd_pcm_prepare(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	unsigned int bps;
	struct timeval t;
	long ctms;
	long ptms;
	int dev;

	pr_debug("[ALSA] [%s]\n", __func__);

	if (dpcm->ring_init == 1) {
		if (dpcm->periods != runtime->periods) {
			pr_err("[ALSA] periods different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->period_size != runtime->period_size) {
			pr_err("[ALSA] period_size different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->buffer_size != runtime->buffer_size) {
			pr_err("[ALSA] buffer_size different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->access != runtime->access) {
			pr_err("[ALSA] access different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->format != runtime->format) {
			pr_err("[ALSA] format different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->channels != runtime->channels) {
			pr_err("[ALSA] channels different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->ring_bak[0].begin_addr !=
			(unsigned long) runtime->dma_addr) {
			pr_err("[ALSA] dma_addr different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->ring_init == 0) {
			rtk_snd_flush(substream);
			rtk_snd_pause(substream);
			rtk_snd_close(substream);
		}
	}

	bps = runtime->rate * runtime->channels;
	bps *= snd_pcm_format_width(runtime->format);
	bps /= 8;
	if (bps <= 0)
		return -EINVAL;

	dpcm->pcm_bps = bps;
	dpcm->pcm_jiffie = runtime->rate / HZ;
	dpcm->pcm_size = snd_pcm_lib_buffer_bytes(substream);
	dpcm->pcm_count = snd_pcm_lib_period_bytes(substream);
	dpcm->pcm_buf_pos = 0;
	dpcm->pcm_irq_pos = 0;
	dpcm->appl_ptr = 0;
	dpcm->flush_state = RTK_SND_FLUSH_STATE_NONE;
	dpcm->periods = runtime->periods;
	dpcm->buffer_size = runtime->buffer_size;
	dpcm->access = runtime->access;
	dpcm->channels = runtime->channels;
	dpcm->format = runtime->format;
	dpcm->period_size = runtime->period_size;
	dpcm->sample_bits = runtime->sample_bits;
	dpcm->rate = runtime->rate;
	dpcm->remain_sample = 0;
	dpcm->running = 0;

	dpcm->period_jiffies =
		runtime->period_size * 100 / runtime->rate * 1 / 20;
	if (dpcm->period_jiffies == 0)
		dpcm->period_jiffies = 1;

	dpcm->hwptr_error_times = 0;

#ifdef ALSA_DEBUG_LOG
		pr_debug("[ALSA] dpcm->period_jiffies = %d\n", dpcm->period_jiffies);
#endif
		switch (runtime->access) {
		case SNDRV_PCM_ACCESS_MMAP_INTERLEAVED:
			pr_debug("[ALSA] MMAP_INTERLEAVED\n");
#ifdef USE_DECODER
			/*old flow ALSA -> Decoder -> AO */
			dpcm->audiopath = AUDIO_PATH_DECODER_AO;
#else
			/* new flow ALSA -> AO */
			dpcm->audiopath = AUDIO_PATH_AO;
#endif
			break;
		case SNDRV_PCM_ACCESS_MMAP_NONINTERLEAVED:
			pr_debug("[ALSA] MMAP_NONINTERLEAVED\n");
			dpcm->audiopath = AUDIO_PATH_AO_BYPASS;
			break;
		case SNDRV_PCM_ACCESS_RW_INTERLEAVED:
			pr_debug("[ALSA] RW_INTERLEAVED\n");
#ifdef USE_DECODER
			/*old flow ALSA -> Decoder -> AO */
			dpcm->audiopath = AUDIO_PATH_DECODER_AO;
#else
			/* new flow ALSA -> AO */
			dpcm->audiopath = AUDIO_PATH_AO;
#endif
			break;
		case SNDRV_PCM_ACCESS_RW_NONINTERLEAVED:
			pr_debug("[ALSA] RW_NONINTERLEAVED\n");
			dpcm->audiopath = AUDIO_PATH_AO_BYPASS;
			break;
		default:
			pr_debug("[ALSA][%d] unsupport mode\n", __LINE__);
			return -1;
			break;
	}

	if (dpcm->audiopath == AUDIO_PATH_AO) {
		switch (runtime->format) {
#ifdef USE_DECODER
		case SNDRV_PCM_FORMAT_S32_BE:
		case SNDRV_PCM_FORMAT_S24_BE:
		case SNDRV_PCM_FORMAT_S24_LE:
		case SNDRV_PCM_FORMAT_S8:
#endif
		case SNDRV_PCM_FORMAT_S16_BE:
		case SNDRV_PCM_FORMAT_S16_LE:
			break;
		default:
			pr_debug("[ALSA] unsupport format\n");
			return -1;
			break;
		}
	}

	if (dpcm->ring_init == 1) {
		pr_debug("[ALSA] reprepare!!\n");
		spin_lock(dpcm->pcm_lock);
		dpcm->pcm_buf_pos = dpcm->appl_ptr;
		runtime->status->hw_ptr = runtime->control->appl_ptr;
		dpcm->ring_bak[0].wr_ptr = dpcm->ring_bak[0].begin_addr +
			(dpcm->appl_ptr % runtime->buffer_size) * dpcm->output_frame_bytes;
		dpcm->ring[0].wr_ptr = htonl(0xa0000000|
			(dpcm->ring_bak[0].wr_ptr & 0x1FFFFFFF));
		spin_unlock(dpcm->pcm_lock);
		rtk_snd_pause(substream);
		rtk_snd_flush(substream);
		rtk_snd_resume(substream);

		dpcm->running = 0;

		do_gettimeofday(&t);
		ptms = t.tv_sec*1000 + t.tv_usec/1000;

		/* wait ADSP finish flush */
		while (1) {
			if ((dpcm->ring_bak[0].wr_ptr & 0x1FFFFFFF) ==
				((ntohl(dpcm->ring[0].rd_ptr[0]) & 0x1FFFFFFF))) {
				pr_debug("[ALSA] wp %lx, rp %x\n",
					dpcm->ring_bak[0].wr_ptr, ntohl(dpcm->ring[0].rd_ptr[0]));
				break;
			}

			do_gettimeofday(&t);
			ctms = t.tv_sec*1000 + t.tv_usec/1000;
			if ((ctms - ptms) >= 100) {
				/* wait timeout prevent deadlock */
				pr_err("[ALSA] wait ADSP flush timeout!!!\n");
				break;
			}
		}
		return 0;
	}

	dpcm->ring_init = 1;
	dev = substream->pcm->device;

	pr_debug("[ALSA] freerun = %d\n", dpcm->freerun);
	pr_debug("[ALSA] start_threshold = %lx\n", runtime->start_threshold);
	pr_debug("[ALSA] stop_threshold = %lx\n", runtime->stop_threshold);
	pr_debug("[ALSA] avail_min = %lx\n", runtime->control->avail_min);
	pr_debug("[ALSA] buffer_size = %lx\n", runtime->buffer_size);
	pr_debug("[ALSA] period_size = %lx\n", runtime->period_size);
	pr_debug("[ALSA] sample rate = %d\n", runtime->rate);

	if (dpcm->audiopath == AUDIO_PATH_DECODER_AO) {
		dpcm->output_frame_bytes = frames_to_bytes(runtime, 1);
		dpcm->input_frame_bytes = frames_to_bytes(runtime, 1);
		dpcm->output_sample_bytes = samples_to_bytes(runtime, 1);
		dpcm->input_sample_bytes = samples_to_bytes(runtime, 1);

		rtk_snd_create_decoder_agent(substream);

		pr_debug("[ALSA] dec_agent = %d, dec_pin_id = %d\n",
			dpcm->dec_agent, dpcm->dec_pin_id);

		rtk_snd_init_decoder_ring(substream);
		if (rtk_snd_init_connect_decoder_ao(substream)) {
			pr_debug("[ALSA] %s %d\n", __func__, __LINE__);
			return -ENOMEM;
		}

		/*
		*	AO Pause
		*	Decoder Pause
		*	Decoder Flush
		*	Write Inband data
		*/
		rtk_snd_init_decoder_info(substream);
		rtk_snd_set_ao_flashpin_volume(substream);
		rtk_snd_resume(substream);

		/*
		substream->ops->silence = NULL;
		substream->ops->copy = snd_card_std_copy;
		*/

	} else if (dpcm->audiopath == AUDIO_PATH_AO_BYPASS) {

		pr_debug("[ALSA] AO BYPASS\n");
		dpcm->agent_id = dpcm->ao_agent;
		dpcm->pin_id = dpcm->ao_pin_id;
		dpcm->extend_to_32be_ratio = 0;
		dpcm->output_frame_bytes = samples_to_bytes(runtime, 1);
		dpcm->input_frame_bytes = samples_to_bytes(runtime, 1);
		dpcm->output_sample_bytes = samples_to_bytes(runtime, 1);
		dpcm->input_sample_bytes = samples_to_bytes(runtime, 1);

		/*
		substream->ops->copy = NULL;
		substream->ops->silence = NULL;
		*/

		if (rtk_snd_init_ao_ring(substream))
			return -ENOMEM;

		if (rtk_snd_ao_info(substream)) {
			pr_err("[ALSA] %s %d\n", __func__, __LINE__);
			return -ENOMEM;
		}
		rtk_snd_resume(substream);
	} else if (dpcm->audiopath == AUDIO_PATH_AO) {
		pr_debug("[ALSA] AO interleaved\n");
		dpcm->agent_id = dpcm->ao_agent;
		dpcm->pin_id = dpcm->ao_pin_id;
		dpcm->card->ao_pin_id[dev] = dpcm->ao_pin_id;
		dpcm->volume = dpcm->card->ao_flash_volume[dev];

		dpcm->output_frame_bytes = frames_to_bytes(runtime, 1);
		dpcm->input_frame_bytes = frames_to_bytes(runtime, 1);
		dpcm->output_sample_bytes = samples_to_bytes(runtime, 1);
		dpcm->input_sample_bytes = samples_to_bytes(runtime, 1);

		/*
		substream->ops->copy = NULL;
		substream->ops->silence = NULL;
		*/

		if (rtk_snd_init_ao_ring(substream)) {
			pr_err("[ALSA] %d Fail!!\n", __LINE__);
			return -ENOMEM;
		}

		if (rtk_snd_ao_info(substream)) {
			pr_err("[ALSA] %d Fail!!\n", __LINE__);
			return -ENOMEM;
		}

		rtk_snd_set_ao_flashpin_volume(substream);
		rtk_snd_resume(substream);
	}

	return 0;
}

static int rtk_snd_playback_prepare(struct snd_pcm_substream *substream)
{
	return rtk_snd_pcm_prepare(substream);
}

#ifndef CONFIG_CUSTOMER_TV006
static void get_mux_in(char *mux_in, struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	switch (dpcm->path_src) {
	case AIO_PATH_SRC_BBADC:
		if (!strcmp(mux_in, "MUTE_ALL"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_MUTE_ALL;
		else if (!strcmp(mux_in, "MIC1"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_MIC1;
		else if (!strcmp(mux_in, "MIC2"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_MIC2;
		else if (!strcmp(mux_in, "AIN1"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_AIN1;
		else if (!strcmp(mux_in, "AIN2"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_AIN2;
		else if (!strcmp(mux_in, "AIN3"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_AIN3;
		else if (!strcmp(mux_in, "AIO1"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_AIO1;
		else if (!strcmp(mux_in, "AIO2"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_AIO2;
		else if (!strcmp(mux_in, "DMIC"))
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_DMIC;
		else
			dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_UNKNOWN;
		break;
	case AIO_PATH_SRC_SPDIF:
		if (!strcmp(mux_in, "IN"))
			dpcm->spdifi_mux_in = AUDIO_SPDIFI_SRC_IN;
		else if (!strcmp(mux_in, "HDMI"))
			dpcm->spdifi_mux_in = AUDIO_SPDIFI_SRC_HDMI;
		else if (!strcmp(mux_in, "LOOPBACK"))
			dpcm->spdifi_mux_in = AUDIO_SPDIFI_SRC_LOOPBACK;
		else
			dpcm->spdifi_mux_in = AUDIO_SPDIFI_SRC_DISABLE;
		break;
	case AIO_PATH_SRC_I2S_PRI_CH12:
	case AIO_PATH_SRC_I2S_PRI_CH34:
	case AIO_PATH_SRC_I2S_PRI_CH56:
	case AIO_PATH_SRC_I2S_PRI_CH78:
	case AIO_PATH_SRC_I2S_SEC_CH12:
		if (!strcmp(mux_in, "IN"))
			dpcm->i2si_mux_in = AUDIO_I2SI_SRC_IN;
		else if (!strcmp(mux_in, "HDMI"))
			dpcm->i2si_mux_in = AUDIO_I2SI_SRC_HDMI;
		else if (!strcmp(mux_in, "LOOPBACK"))
			dpcm->i2si_mux_in = AUDIO_I2SI_SRC_LOOPBACK;
		else
			dpcm->i2si_mux_in = AUDIO_I2SI_SRC_DISABLE;
		break;
	default:
		pr_debug("[ALSA] unknown mux_in\n");
		break;
	}
}
#endif

static void get_aio_config_src(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

#ifndef CONFIG_CUSTOMER_TV006
	char *token, *path_src;

	pr_debug("[ALSA] path_src : %s\n", runtime->path_src);

    if(substream->pcm->device == 0){
	    strcpy(runtime->path_src, "I2S_PRI_CH12,IN");
    }
	else if(substream->pcm->device == 1){
	    strcpy(runtime->path_src, "I2S_PRI_CH12,LOOPBACK");
    }
    path_src = (char *)runtime->path_src;

	token = strsep(&path_src, ",");
	pr_debug("[ALSA] token[0] : %s\n", token);

	if (!strcmp(token, "BBADC"))
		dpcm->path_src = AIO_PATH_SRC_BBADC;
	else if (!strcmp(token, "ATV"))
		dpcm->path_src = AIO_PATH_SRC_ATV;
	else if (!strcmp(token, "SPDIFI"))
		dpcm->path_src = AIO_PATH_SRC_SPDIF;
	else if (!strcmp(token, "I2S_PRI_CH12"))
		dpcm->path_src = AIO_PATH_SRC_I2S_PRI_CH12;
	else if (!strcmp(token, "I2S_PRI_CH34"))
		dpcm->path_src = AIO_PATH_SRC_I2S_PRI_CH34;
	else if (!strcmp(token, "I2S_PRI_CH56"))
		dpcm->path_src = AIO_PATH_SRC_I2S_PRI_CH56;
	else if (!strcmp(token, "I2S_PRI_CH78"))
		dpcm->path_src = AIO_PATH_SRC_I2S_PRI_CH78;
	else if (!strcmp(token, "I2S_SEC_CH12"))
		dpcm->path_src = AIO_PATH_SRC_I2S_SEC_CH12;
	else
		dpcm->path_src = AIO_PATH_SRC_UNKNOWN;

	token = strsep(&path_src, ",");
	pr_debug("[ALSA] token[1] : %s\n", token);
	get_mux_in(token, substream);

#else
	dpcm->path_src = AIO_PATH_SRC_BBADC;
	dpcm->bbadc_mux_in = AUDIO_BBADC_SRC_DMIC;
#endif
}

static int rtk_snd_ai_switch_focus(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;
	int instance_id;

	get_aio_config_src(substream);

	pr_debug("[ALSA] path_src: %x\n", dpcm->path_src);

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] [%d] alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *) ((uint) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((uint) dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));

	instance_id = ((dpcm->ai_cap_agent&0xFFFFFFF0)|(dpcm->ai_cap_pin&0xF));
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_AI_SWITCH_FOCUS);
	cmd->pri_info[0] = htonl(dpcm->path_src);
	cmd->pri_info[1] = htonl(AIO_PATH_SRC_UNKNOWN);
	cmd->pri_info[2] = htonl(AIO_PATH_SRC_UNKNOWN);
	cmd->pri_info[3] = htonl(AIO_PATH_SRC_UNKNOWN);

	switch (dpcm->path_src) {
	case AIO_PATH_SRC_BBADC:
		pr_debug("[ALSA] bbadc_mux_in: %x\n", dpcm->bbadc_mux_in);
		cmd->pri_info[4] = htonl(dpcm->bbadc_mux_in);
	break;
	case AIO_PATH_SRC_SPDIF:
		pr_debug("[ALSA] spdifi_mux_in: %x\n", dpcm->spdifi_mux_in);
		cmd->pri_info[4] = htonl(dpcm->spdifi_mux_in);
		break;
	case AIO_PATH_SRC_I2S_PRI_CH12:
	case AIO_PATH_SRC_I2S_PRI_CH34:
	case AIO_PATH_SRC_I2S_PRI_CH56:
	case AIO_PATH_SRC_I2S_PRI_CH78:
	case AIO_PATH_SRC_I2S_SEC_CH12:
		pr_debug("[ALSA] i2si_mux_in: %x\n", dpcm->i2si_mux_in);
		cmd->pri_info[4] = htonl(dpcm->i2si_mux_in);
		break;
	case AIO_PATH_SRC_ATV:
		cmd->pri_info[4] = htonl(AIO_PATH_SRC_UNKNOWN);
		break;
	default:
		pr_debug("[ALSA] unknown mux_in\n");
		cmd->pri_info[4] = htonl(AIO_PATH_SRC_UNKNOWN);
		break;
	}

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int) cmd_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		pr_err("[ALSA] %d RPC fail\n", __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
	return 0;
}

static int snd_realtek_ai_hw_resume(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	unsigned int temp;

	temp = ((dpcm->ai_cap_agent&0xFFFFFFF0)|(dpcm->ai_cap_pin&0xF));

	if (RPC_TOAGENT_RUN_SVC(dpcm->card->card, &temp) < 0)
		return -1;

	return 0;
}

static int rtk_snd_check_audio_fw_capability(struct snd_card *card)
{
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res, *res_audio;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);


	card->card_dev.dma_mask = &card->card_dev.coherent_dma_mask;
	if(dma_set_mask(&card->card_dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
	}
	arch_setup_dma_ops(&card->card_dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(&card->card_dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA]%d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}
	else
	{
		pr_debug("[ALSA]%d OK to alloc memory\n", __LINE__);
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *) ((unsigned int) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		(((((unsigned int) dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) &
			0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	/********************************************
	*   pri_info[0]: Magic Number               *
	*   pri_info[1]: for AI                     *
	*   [2] ~ [15]	  : TBD			    *
	********************************************/
	/********************************************
	*	pri_info[1]:                        *
	*		bit 0 -> check global AI    *
	********************************************/
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_FIRMWARE_CAPABILITY);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int)cmd_audio,
		(unsigned int)res_audio,
		(unsigned long)res, &ret)) {
		pr_err("[ALSA] %d RPC fail\n", __LINE__);
		dma_free_coherent(&card->card_dev, 4096, p, dat);
		return -1;
	}

	pr_debug("[ALSA] pri_info[0] 0x%x, pri_info[1] 0x%x\n",
		ntohl(res->pri_info[0]),
		ntohl(res->pri_info[1]));

	if (ntohl(res->pri_info[0]) == 0x23792379) {
		have_global_ai = ntohl(res->pri_info[1]) & 0x00000001;
		pr_debug("[ALSA] support capability RPC!!\n");
	} else {
		have_global_ai = 0;
		pr_debug("[ALSA] doesn't support capability RPC\n");
	}

	dma_free_coherent(&card->card_dev, 4096, p, dat);
	return 0;
}

/* AO capture get available AO out pin */
static int rpc_toagent_get_ao_outpin(struct snd_pcm_substream *substream)
{
	unsigned long ret;
	dma_addr_t dat;
	void *p;
	struct RPC_PRI_PARAM *cmd, *cmd_audio;
	struct RPC_PRI_RET *res , *res_audio;
	int instance_id, pin_id;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	pr_debug("[ALSA] %s %d\n", __func__, __LINE__);

    dpcm->card->card->dev->dma_mask = &dpcm->card->card->dev->coherent_dma_mask;
    if(dma_set_mask(dpcm->card->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(dpcm->card->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(dpcm->card->card->dev, 4096, &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] [%d]alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, 4096);

	cmd = p;
	res = (struct RPC_PRI_RET *)
		((((unsigned long)p + sizeof(struct RPC_PRI_PARAM) + 8) & ALIGN4));

	cmd_audio = (struct RPC_PRI_PARAM *)((uint) dat|0xa0000000);
	res_audio = (struct RPC_PRI_RET *)
		((((uint)(dat|0xa0000000) + sizeof(struct RPC_PRI_PARAM) + 8) & 0xFFFFFFFC));

	memset(cmd, 0, sizeof(struct RPC_PRI_PARAM));
	instance_id = dpcm->ao_cap_agent;
	cmd->instance_id = htonl(instance_id);
	cmd->type = htonl(ENUM_PRIVATEINFO_AUDIO_GET_AVAILABLE_AO_OUTPUT_PIN);
	cmd->pri_info[0] = 0xFF;
	cmd->pri_info[1] = 0xFF;
	cmd->pri_info[2] = 0xFF;
	cmd->pri_info[3] = 0xFF;
	cmd->pri_info[4] = 0xFF;
	cmd->pri_info[5] = 0xFF;

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_PRIVATEINFO,
		(unsigned int)cmd_audio,
		(unsigned int)res_audio,
		(unsigned long)res, &ret)) {
		pr_err("[ALSA] %d RPC fail\n", __LINE__);
		dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);
		return -1;
	}

	pin_id = ntohl(res->pri_info[0]);
	dpcm->ao_cap_pin = pin_id;
	dma_free_coherent(dpcm->card->card->dev, 4096, p, dat);

	return 0;
}

static int rtk_snd_capture_prepare_BE(
	struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	if (dpcm->ai_format == AUDIO_ALSA_FORMAT_24BITS_BE_PCM) {
	dpcm->input_frame_bytes = 4 * runtime->channels;
	dpcm->input_sample_bytes = 4;
	} else if (dpcm->ai_format == AUDIO_ALSA_FORMAT_16BITS_BE_PCM) {
		dpcm->input_frame_bytes = 2 * runtime->channels;
		dpcm->input_sample_bytes = 2 * runtime->channels;
	}

	/* Mars 1 for AI capture, Mars 2 for AO capture */
	if (!strcmp(dpcm->card->card->longname, "Mars 1")) {
#ifdef USE_ASLA_OUTPIN
		dpcm->ai_cap_pin = ASLA_OUTPIN;
#else
		dpcm->ai_cap_pin = TS_OUTPIN;
#endif
		pr_debug("[ALSA] prepare open AI capture\n");
		/* send rpc init ai ring */
		if (rtk_snd_init_ai_ring(substream)) {
			pr_err("[ALSA] %d fail\n", __LINE__);
			goto prepare_fail;
		}
		/* send rpc switch focus to AI capture */
		if (rtk_snd_ai_switch_focus(substream)) {
			pr_err("[ALSA] %d fail\n", __LINE__);
			goto prepare_fail;
		}
		/* send rpc run AI */
		if (snd_realtek_ai_hw_resume(substream) < 0) {
			pr_err("[ALSA] %d fail\n", __LINE__);
			goto prepare_fail;
		}

		return 0;
	} else {
		pr_debug("[ALSA] prepare open AO capture\n");
		/* get available ao outpin */
		rpc_toagent_get_ao_outpin(substream);

		/* send rpc init ao capture ring */
		if (rtk_snd_init_ao_capture_ring(substream)) {
			pr_err("[ALSA] %d fail\n", __LINE__);
			goto prepare_fail;
		}

		return 0;
	}

prepare_fail:
	return -ENOMEM;
}

static int rtk_snd_capture_prepare(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	unsigned int bps;

	if (dpcm->ring_init == 1) {
		if (dpcm->periods != runtime->periods) {
			pr_err("[ALSA] periods different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->period_size != runtime->period_size) {
			pr_err("[ALSA] period_size different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->buffer_size != runtime->buffer_size) {
			pr_err("[ALSA] buffer_size different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->access != runtime->access) {
			pr_err("[ALSA] access different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->format != runtime->format) {
			pr_err("[ALSA] format different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->channels != runtime->channels) {
			pr_err("[ALSA] channels different\n");
			dpcm->ring_init = 0;
		}
		if (dpcm->ring_init == 0) {
			/* Mars 1 for AI capture, Mars 2 for AO capture */
			if (!strcmp(dpcm->card->card->longname, "Mars 1"))
				snd_realtek_ai_hw_close(substream);
			else
				snd_realtek_ao_capture_hw_close(substream);
		}
	}

	/* set ALSA capture parameters */
	bps = runtime->rate * runtime->channels;
	bps *= snd_pcm_format_width(runtime->format);
	bps /= 8;
	if (bps <= 0)
		return -EINVAL;

	dpcm->pcm_bps = bps;
	dpcm->pcm_jiffie = runtime->rate / HZ;
	dpcm->pcm_size = snd_pcm_lib_buffer_bytes(substream);
	dpcm->pcm_count = snd_pcm_lib_period_bytes(substream);
	dpcm->pcm_irq_pos = 0;
	dpcm->appl_ptr = 0;
	dpcm->flush_state = RTK_SND_FLUSH_STATE_NONE;
	dpcm->periods = runtime->periods;
	dpcm->buffer_size = runtime->buffer_size;
	dpcm->access = runtime->access;
	dpcm->channels = runtime->channels;
	dpcm->format = runtime->format;
	dpcm->period_size = runtime->period_size;
	dpcm->sample_bits = runtime->sample_bits;
	dpcm->rate = runtime->rate;
	dpcm->remain_sample = 0;

	dpcm->period_jiffies =
		runtime->period_size * 100 / runtime->rate * 1 / 20;
	if (dpcm->period_jiffies == 0)
		dpcm->period_jiffies = 1;

	pr_debug("[ALSA] period_jiffies = %d\n", dpcm->period_jiffies);

	/* check format */
	switch (runtime->access) {
	case SNDRV_PCM_ACCESS_MMAP_INTERLEAVED:
	case SNDRV_PCM_ACCESS_RW_INTERLEAVED:
		switch (runtime->format) {
		case SNDRV_PCM_FORMAT_S16_LE:
			dpcm->ai_format = AUDIO_ALSA_FORMAT_16BITS_LE_LPCM;
			break;
		case SNDRV_PCM_FORMAT_S24_LE:
			pr_debug("[ALSA] write .wav header err\n");
			dpcm->ai_format = AUDIO_ALSA_FORMAT_24BITS_LE_LPCM;
			break;
		default:
			pr_debug("[ALSA] unsupport format %d\n", __LINE__);
			return -1;
		}
		break;
	case SNDRV_PCM_ACCESS_MMAP_NONINTERLEAVED:
	case SNDRV_PCM_ACCESS_RW_NONINTERLEAVED:
	default:
		pr_debug("[ALSA] unsupport access %d\n", __LINE__);
		return -1;
	}

#ifdef USE_ASLA_OUTPIN
	/* 24bit BE non-interleave from ASLA_OUTPIN */
	dpcm->ai_format = AUDIO_ALSA_FORMAT_24BITS_BE_PCM;
#else
	/* 16bit BE interleave from TS_OUTPIN */
	dpcm->ai_format = AUDIO_ALSA_FORMAT_16BITS_BE_PCM;
#endif

	if (dpcm->ring_init == 1)
		return 0;

	dpcm->ring_init = 1;
	dpcm->running = 0;

	pr_debug("[ALSA] start_threshold = %lx\n", runtime->start_threshold);
	pr_debug("[ALSA] stop_threshold = %lx\n", runtime->stop_threshold);
	pr_debug("[ALSA] avail_min = %lx\n", runtime->control->avail_min);
	pr_debug("[ALSA] buffer_size = %lx\n", runtime->buffer_size);
	pr_debug("[ALSA] period_size = %lx\n", runtime->period_size);
	pr_debug("[ALSA] sample rate = %d\n", runtime->rate);

	/*
	substream->ops->silence = NULL;
	substream->ops->copy = NULL;
	*/

	/* prepare according to format */
	switch (dpcm->ai_format) {
	case AUDIO_ALSA_FORMAT_24BITS_BE_PCM:
	case AUDIO_ALSA_FORMAT_16BITS_BE_PCM:
		if (rtk_snd_capture_prepare_BE(substream)) {
			pr_err("[ALSA] %d fail\n", __LINE__);
			return -ENOMEM;
		}
		break;
	case AUDIO_ALSA_FORMAT_24BITS_LE_LPCM:
	case AUDIO_ALSA_FORMAT_16BITS_LE_LPCM:
		pr_debug("[ALSA] %d not support\n", __LINE__);
		break;
	default:
		pr_debug("[ALSA] %d unknown format\n", __LINE__);
		break;
	}

	return 0;
}

static void rtk_snd_fmt_convert_to_S16LE(struct snd_pcm_substream *substream,
	snd_pcm_uframes_t wp_next, snd_pcm_uframes_t wp, unsigned int adv_min)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	int i, loop;
	char *p = NULL, temp;

	p = (char *) dpcm->ring_bak[0].wr_ptr;

	switch (runtime->format) {
	case SNDRV_PCM_FORMAT_S16_BE:
		if (wp_next > wp || wp_next == 0) {
			for (i = 0; i < adv_min * runtime->channels; i++) {
				temp = *p;
				*p = *(p+1);
				p++;
				*p = temp;
				p++;
			}
		} else {
			loop = runtime->buffer_size - wp;
			for (i = 0; i < loop * runtime->channels; i++) {
				temp = *p;
				*p = *(p+1);
				p++;
				*p = temp;
				p++;
			}
			p = (char *) dpcm->ring_bak[0].begin_addr;
			for (i = 0; i < wp_next * runtime->channels; i++) {
				temp = *p;
				*p = *(p+1);
				p++;
				*p = temp;
				p++;
			}
		}
	break;
	case SNDRV_PCM_FORMAT_S16_LE:
	break;
	default:
		pr_err("[ALSA] not support format convert\n");
	break;
	}
}

static void rtk_snd_pcm_freerun_timer_function(unsigned long data)
{
#ifdef ALSA_DEBUG_LOG
	pr_debug("[ALSA] [%s %d]Enter\n", __func__, __LINE__);
#endif

	struct rtk_snd_pcm *dpcm = (struct rtk_snd_pcm *)data;
	struct snd_pcm_substream *substream = dpcm->substream;
	struct snd_pcm_runtime *runtime = substream->runtime;
	unsigned int rp;
	unsigned int rp_base, adv_min, rp_real, avail;
	snd_pcm_uframes_t wp, wp_next;

	/* for ALSA data throughput */
	struct timeval t;
	long per_write_count;
	long valid;
	long time_diff, nodata_time_diff;
	int hwptr_diff;  /* for error handle */

	spin_lock(dpcm->pcm_lock);

	rp_base = dpcm->ring_bak[0].begin_addr & 0x1FFFFFFF;
	rp_real = ntohl(dpcm->ring[0].rd_ptr[0]) & 0x1FFFFFFF;
#ifdef ALSA_DEBUG_LOG
	pr_debug("[ALSA] rp_real = %lx, rp_base = %lx\n", rp_real, rp_base);
#endif
	if ((dpcm->audiopath == AUDIO_PATH_DECODER_AO) ||
	(dpcm->audiopath == AUDIO_PATH_AO)) {
		rp = (rp_real - rp_base) / dpcm->output_frame_bytes;
#ifdef ALSA_DEBUG_LOG
		pr_debug("[ALSA] rp = %ld\n", rp);
#endif
		if (runtime->buffer_size !=
			(dpcm->ring_bak[0].size / dpcm->output_frame_bytes)) {
			pr_err("[ALSA] buffer_size error\n");
		}
	} else {
		rp = (rp_real - rp_base) / dpcm->output_sample_bytes;
		if (runtime->buffer_size !=
			(dpcm->ring_bak[0].size / dpcm->output_sample_bytes)) {
			pr_err("[ALSA] buffer_size error\n");
		}
	}

	if (rp < (dpcm->pcm_buf_pos % runtime->buffer_size)) {
		adv_min = rp + runtime->buffer_size -
				(dpcm->pcm_buf_pos%runtime->buffer_size);
	} else {
		adv_min = rp - (dpcm->pcm_buf_pos%runtime->buffer_size);
	}

	if (dpcm->pcm_buf_pos > runtime->control->appl_ptr)
		avail = runtime->control->appl_ptr +
			runtime->boundary -
			dpcm->pcm_buf_pos;
	else
		avail = runtime->control->appl_ptr - dpcm->pcm_buf_pos;

#ifdef ALSA_DEBUG_LOG
	pr_debug("[ALSA] avail = %d, adv_min = %d\n", avail, adv_min);
#endif

	/* prevent underflow condition occur */
	if (runtime->status->state != SNDRV_PCM_STATE_DRAINING ||
		dpcm->freerun) {
		if (avail == adv_min && adv_min >= 16)
			adv_min = avail - 16;
	}

	dpcm->pcm_buf_pos += adv_min;
	dpcm->pcm_buf_pos %= runtime->boundary;
	if (dpcm->remain_sample < adv_min)
		dpcm->remain_sample = 0;
	else
		dpcm->remain_sample = dpcm->remain_sample - adv_min;

	/* calculate the avail size */
	if (dpcm->freerun == 0) {
		if (dpcm->appl_ptr == runtime->control->appl_ptr)
			goto check_status;

		wp = dpcm->appl_ptr % runtime->buffer_size;

		if (dpcm->pcm_buf_pos > runtime->control->appl_ptr) {
			avail = runtime->control->appl_ptr +
				runtime->boundary -
				dpcm->pcm_buf_pos;
		} else {
			avail = runtime->control->appl_ptr -
			dpcm->pcm_buf_pos;
		}

#ifdef ALSA_DEBUG_LOG
		pr_debug("[ALSA] avail = %d\n", avail);
#endif

		/* buffer full */
		if (avail == runtime->buffer_size) {
			if (runtime->control->appl_ptr < 16) {
				dpcm->appl_ptr =
					runtime->control->appl_ptr +
					runtime->boundary - 16;
			} else {
				dpcm->appl_ptr =
					runtime->control->appl_ptr - 16;
			}
		} else {
			dpcm->appl_ptr = runtime->control->appl_ptr;
		}

		dpcm->appl_ptr %= runtime->boundary;
		wp_next = dpcm->appl_ptr % runtime->buffer_size;

		if (wp_next != wp) {
			if (wp_next > wp) {
				dpcm->remain_sample += (wp_next - wp);
				adv_min = (wp_next - wp);
			} else {
				dpcm->remain_sample +=
					(wp_next + runtime->buffer_size - wp);
				adv_min =
					(wp_next + runtime->buffer_size - wp);
			}
		} else {
			adv_min = 0;
			goto check_status;
		}

		rtk_snd_fmt_convert_to_S16LE(substream, wp_next, wp, adv_min);

		if ((dpcm->audiopath == AUDIO_PATH_DECODER_AO) ||
			(dpcm->audiopath == AUDIO_PATH_AO)) {
			if (wp_next > wp || wp_next == 0) {
				dma_addr_t phy_addr =
					dma_map_single(dpcm->card->card->dev,
					(phys_to_virt(dpcm->ring_bak[0].wr_ptr&
					0x1FFFFFFF)),
					adv_min * dpcm->output_frame_bytes,
					DMA_TO_DEVICE);
				dma_unmap_single(dpcm->card->card->dev, phy_addr,
				(int) (phys_to_virt(dpcm->ring_bak[0].wr_ptr&
				0x1FFFFFFF)),
				DMA_TO_DEVICE);
			} else {
				dma_addr_t phy_addr =
					dma_map_single(dpcm->card->card->dev,
					(phys_to_virt(dpcm->ring_bak[0].wr_ptr&
					0x1FFFFFFF)),
					(runtime->buffer_size - wp) *
					dpcm->output_frame_bytes,
					DMA_TO_DEVICE);
				dma_unmap_single(dpcm->card->card->dev, phy_addr,
				(int) (phys_to_virt(dpcm->ring_bak[0].wr_ptr&
				0x1FFFFFFF)),
				DMA_TO_DEVICE);

				if (wp_next) {
					dma_addr_t phy_addr1 =
						dma_map_single(dpcm->card->card->dev,
						(phys_to_virt(
						dpcm->ring_bak[0].begin_addr&
						0x1FFFFFFF)),
						(wp_next) *
						dpcm->output_frame_bytes,
						DMA_TO_DEVICE);
					dma_unmap_single(dpcm->card->card->dev, phy_addr1,
					(int) (phys_to_virt(
					dpcm->ring_bak[0].begin_addr&
					0x1FFFFFFF)),
					DMA_TO_DEVICE);
				}
			}
			dpcm->ring_bak[0].wr_ptr =
				dpcm->ring_bak[0].begin_addr +
				(dpcm->appl_ptr % runtime->buffer_size) *
				dpcm->output_frame_bytes;
			dpcm->ring[0].wr_ptr =
				htonl(0xa0000000|
				(dpcm->ring_bak[0].wr_ptr&
				0x1FFFFFFF));
		} else {
			/* not support AUDIO_PATH_AO_BYPASS */
		}
	} else {
		/* not support freerun */
	}

check_status:
	/* throughput compute */
	per_write_count = (long)((ntohl(dpcm->ring[0].wr_ptr) & 0x1FFFFFFF) -
						dpcm->pre_wr_ptr);

	if (per_write_count < 0)
		per_write_count += (long)dpcm->buffer_byte_size;

	dpcm->total_data_wb = dpcm->total_data_wb + per_write_count;

	valid = (long)(ntohl(dpcm->ring[0].wr_ptr) & 0x1FFFFFFF) -
			((ntohl(dpcm->ring[0].rd_ptr[0]) & 0x1FFFFFFF));
	if (valid < 0)
		valid += dpcm->buffer_byte_size;

	if (dpcm->max_level < valid)
		dpcm->max_level = valid;

	if (dpcm->min_level > valid)
		dpcm->min_level = valid;

	dpcm->pre_wr_ptr = ntohl(dpcm->ring[0].wr_ptr) & 0x1FFFFFFF;

#ifndef CONFIG_CUSTOMER_TV006
	update_hw_delay(substream);
#endif

	do_gettimeofday(&t);
	dpcm->current_time_ms = t.tv_sec*1000 + t.tv_usec/1000;

	time_diff = dpcm->current_time_ms - dpcm->pre_time_ms;

	if (valid == 0) {
		if (dpcm->pre_no_datatime_ms == 0) {
			dpcm->pre_no_datatime_ms = t.tv_sec*1000 + t.tv_usec/1000;
		}
	} else {
		if (dpcm->pre_no_datatime_ms != 0) {
			dpcm->current_no_datatime_time_ms = t.tv_sec*1000 + t.tv_usec/1000;
			nodata_time_diff = dpcm->current_no_datatime_time_ms - dpcm->pre_no_datatime_ms;

			if (nodata_time_diff > 30) {
				pr_debug("[ALSA] shared buffer no data over than %ld ms\n", nodata_time_diff);
			}

			if (nodata_time_diff > 50) {
				pr_debug("[ALSA] appl_ptr = %ld, appl_ptr = %ld\n",
					dpcm->appl_ptr,
					runtime->control->appl_ptr);
				pr_debug("[ALSA] pcm_buf_pos %d, hw_ptr %ld\n",
					dpcm->pcm_buf_pos,
					runtime->status->hw_ptr);
			}
			dpcm->pre_no_datatime_ms = 0;
		}
	}

	if (time_diff >= 3000) {
		if (dpcm->max_level != 0) {
			pr_debug("[ALSA] total_data_wb %ld, %ld~%ld bytes, time %ldms\n",
				dpcm->total_data_wb,
				dpcm->min_level,
				dpcm->max_level,
				time_diff);
		}

		pr_debug("[ALSA] wr_ptr = %x, rd_ptr = %x\n",
			ntohl(dpcm->ring[0].wr_ptr),
			ntohl(dpcm->ring[0].rd_ptr[0]));
		pr_debug("[ALSA] pcm_buf_pos %d, hw_ptr %ld, dma_addr %x\n",
			dpcm->pcm_buf_pos,
			runtime->status->hw_ptr,
			(unsigned int) runtime->dma_addr);
		pr_debug("[ALSA] appl_ptr = %ld, appl_ptr = %ld\n",
			dpcm->appl_ptr,	runtime->control->appl_ptr);

		if (runtime->rate != 0) {
			pr_info("[ALSA] hw delay: %d ms\n", runtime->delay * 1000 / runtime->rate);
		}

		do_gettimeofday(&t);
		dpcm->pre_time_ms = t.tv_sec*1000 + t.tv_usec/1000;
		dpcm->max_level = 0;
		dpcm->min_level = dpcm->buffer_byte_size;
		dpcm->total_data_wb = 0;
	}
	/* End throughput compute */

	hwptr_diff = dpcm->pcm_buf_pos - runtime->status->hw_ptr;
	if(hwptr_diff < 0) {
		hwptr_diff += runtime->boundary;
	}

	if(hwptr_diff >= runtime->buffer_size) {
		pr_debug("[ALSA] reset hwptr from %d to hw_ptr %ld\n",
			dpcm->pcm_buf_pos, runtime->status->hw_ptr);

		dpcm->hwptr_error_times++;

		if(dpcm->hwptr_error_times >= 10) {
			runtime->status->hw_ptr = dpcm->pcm_buf_pos;
			dpcm->hwptr_error_times = 0;
		}
	}

	if (dpcm->running == 0) {
#ifdef CONFIG_SMP
		mod_timer(&dpcm->timer, dpcm->period_jiffies + jiffies);
#else
		mod_timer(&dpcm->timer, jiffies + 1);
#endif
		spin_unlock(dpcm->pcm_lock);
		return;
	}

	if (runtime->status->state != SNDRV_PCM_STATE_DRAINING ||
		dpcm->freerun) {
		dpcm->pcm_irq_pos = dpcm->pcm_buf_pos - runtime->status->hw_ptr;
		if (dpcm->pcm_irq_pos < 0) {
			dpcm->pcm_irq_pos =
				dpcm->pcm_irq_pos + runtime->boundary;
		}

		if (dpcm->pcm_irq_pos >= runtime->period_size) {
			spin_unlock(dpcm->pcm_lock);
			snd_pcm_period_elapsed(substream);
			spin_lock(dpcm->pcm_lock);
		}
	} else {
		switch (dpcm->flush_state) {
		case RTK_SND_FLUSH_STATE_NONE:
			pr_debug("[ALSA] draining data start\n");
			dpcm->flush_state = RTK_SND_FLUSH_STATE_FINISH;
		case RTK_SND_FLUSH_STATE_WAIT:
			break;
		case RTK_SND_FLUSH_STATE_FINISH:
			if (dpcm->appl_ptr >= dpcm->pcm_buf_pos) {
				if ((dpcm->appl_ptr - dpcm->pcm_buf_pos) <= 256)
					dpcm->pcm_buf_pos = dpcm->appl_ptr;
			} else {
				if ((dpcm->appl_ptr - dpcm->pcm_buf_pos +
					runtime->boundary) <= 256)
					dpcm->pcm_buf_pos = dpcm->appl_ptr;
			}
			if (dpcm->pcm_buf_pos == dpcm->appl_ptr) {
				pr_debug("[ALSA] draining data done\n");
				spin_unlock(dpcm->pcm_lock);
				snd_pcm_period_elapsed(substream);
				spin_lock(dpcm->pcm_lock);
			}
			break;
		}
	}

	if (dpcm->running) {
		mod_timer(&dpcm->timer, dpcm->period_jiffies + jiffies);
	}
	spin_unlock(dpcm->pcm_lock);
}

#ifdef USE_ASLA_OUTPIN
/* tranfer 24 bit BE to 16 bit LE */
#define COPY_FUNC(n_frame, p, ring_rp) \
{\
	int i, temp;\
	for (i = 0; i < n_frame; ++i) {\
		temp = (int)(*ring_rp[0]);\
		temp = ENDIAN_CHANGE(temp);\
		*p = (short)(temp >> 9);\
		p++;\
		temp = (int)(*ring_rp[1]);\
		temp = ENDIAN_CHANGE(temp);\
		*p = (short)(temp >> 9);\
		p++;\
		ring_rp[0]++;\
		ring_rp[1]++;\
	} \
}
#else
/* tranfer 24 bit BE to 16 bit LE */
void COPY_FUNC_24to16(int n_frame, short* p, long *ring_rp[2])
{
	int i, temp;

	for (i = 0; i < n_frame; ++i) {
		temp = (int)(*ring_rp[0]);
		temp = ENDIAN_CHANGE(temp);
		*p = (short)(temp >> 9);
		p++;
		temp = (int)(*ring_rp[1]);
		temp = ENDIAN_CHANGE(temp);
		*p = (short)(temp >> 9);
		p++;
		ring_rp[0]++;
		ring_rp[1]++;
	}
}


/* tranfer 16 bit BE to 16 bit LE */
void COPY_FUNC_16BETo16LE(int n_frame, short* p, long *ring_rp[2])
{
	int i, temp;

	for (i = 0; i < n_frame; ++i) {
		temp = (int)(*ring_rp[0]);
		temp = ENDIAN_CHANGE(temp);
		*p = (short)(temp&0x0000ffff);
		p++;
		*p = (short)((temp&0xffff0000)>>16);
		p++;
		ring_rp[0]++;
	}
}

#endif

/* write zero to dma_area */
#define COPY_ZERO_FUNC(n_frame, p)\
{\
	int i;\
	for (i = 0; i < n_frame; ++i) {\
		*p = (short)(0);\
		p++;\
		*p = (short)(0);\
		p++;\
	} \
}

/*
copy ring buf to dma buf
substream: struct of the pcm stream
nPeriodCound: number of periods that write to runtime->dma_area
write_zero:
	if write_zero = 1,
		ALSA would write zero to dma_area.
	if write_zero = 0,
		ALSA would write n periods to dma_area from AI or AO.
*/


static void rtk_snd_capture_copy(struct snd_pcm_substream *substream,
	long n_period, int write_zero)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	snd_pcm_uframes_t n_frame = n_period * runtime->period_size;
	snd_pcm_uframes_t dma_wp = dpcm->pcm_buf_pos % runtime->buffer_size;
	snd_pcm_uframes_t wrap_size = runtime->buffer_size - dma_wp;
	long *ring_rp[2];
	long ring_limit[2];
	int i, loop0, loop1;
	short *p = NULL;

    void (*COPY_API)(int n_frame, short* p, long *ring_rp[2]);

    COPY_API = COPY_FUNC_16BETo16LE;

    if(dpcm -> ao_cap_agent != -1){
        COPY_API = COPY_FUNC_24to16;
    }

	if (write_zero == 0) {
		for (i = 0; i < 2; ++i) {
			ring_rp[i] = (long *)dpcm->ring_bak[i].rd_ptr[0];
			ring_limit[i] =
				(long)(dpcm->ring_bak[i].begin_addr +
				dpcm->ring_bak[i].size);
		}
	}


	if (n_frame > wrap_size) {
		p = (short *)(runtime->dma_area + LPCM_2CH_16BITS * dma_wp);
		if (write_zero == 0) {
			if ((long)(ring_rp[0] + wrap_size) > ring_limit[0]) {
				loop0 = (ring_limit[0] - (long)ring_rp[0]) >> 2;
				loop1 = wrap_size - loop0;
				COPY_API(loop0, p, ring_rp);
				ring_rp[0] =
					(long *)dpcm->ring_bak[0].begin_addr;
				ring_rp[1] =
					(long *)dpcm->ring_bak[1].begin_addr;
				COPY_API(loop1, p, ring_rp);
			} else {
				COPY_API(wrap_size, p, ring_rp);
			}
		} else {
			COPY_ZERO_FUNC(n_frame, p);
		}

		p = (short *)(runtime->dma_area);
		n_frame -= wrap_size;
		if (write_zero == 0) {
			if ((long)(ring_rp[0] + n_frame) > ring_limit[0]) {
				loop0 = (ring_limit[0] - (long)ring_rp[0]) >> 2;
				loop1 = n_frame - loop0;
				COPY_API(loop0, p, ring_rp);
				ring_rp[0] =
					(long *)dpcm->ring_bak[0].begin_addr;
				ring_rp[1] =
					(long *)dpcm->ring_bak[1].begin_addr;
				COPY_API(loop1, p, ring_rp);
			} else {
				COPY_API(n_frame, p, ring_rp);
			}
		} else {
			COPY_ZERO_FUNC(n_frame, p);
		}
	} else {
		p = (short *)(runtime->dma_area + LPCM_2CH_16BITS * dma_wp);
		if (write_zero == 0) {
			if ((long)(ring_rp[0] + n_frame) > ring_limit[0]) {
				loop0 = (ring_limit[0] - (long)ring_rp[0]) >> 2;
				loop1 = n_frame - loop0;
				COPY_API(loop0, p, ring_rp);
				ring_rp[0] =
					(long *)dpcm->ring_bak[0].begin_addr;
				ring_rp[1] =
					(long *)dpcm->ring_bak[1].begin_addr;
				COPY_API(loop1, p, ring_rp);
			} else {
				COPY_API(n_frame, p, ring_rp);
			}
		} else {
			COPY_ZERO_FUNC(n_frame, p);
		}
	}
}

static long ring_valid_data(long ring_base, long ring_limit,
	long ring_rp, long ring_wp)
{
	if (ring_wp >= ring_rp)
		return ring_wp-ring_rp;
	else
		return (ring_limit-ring_base)-(ring_rp-ring_wp);
}

static long rtk_snd_get_ring_data(struct RBUF_HEADER *p_ring_be,
	struct RBUF_HEADER_ARM *p_ring_le)
{
	long base, limit, rp, wp, data_size;
	base = p_ring_le->begin_addr;
	limit = p_ring_le->begin_addr + p_ring_le->size;
	wp = (long)(ntohl(p_ring_be->wr_ptr) & 0x1FFFFFFF);
	rp = (long)(ntohl(p_ring_be->rd_ptr[0]) & 0x1FFFFFFF);
	data_size = ring_valid_data(base, limit, rp, wp);
	return data_size;
}

/* 24BE AI 2ch input */
static void rtk_snd_pcm_capture_timer_function(unsigned long data)
{
	struct rtk_snd_cap_pcm *dpcm = (struct rtk_snd_cap_pcm *)data;
	struct snd_pcm_substream *substream = dpcm->substream;
	struct snd_pcm_runtime *runtime = substream->runtime;

	snd_pcm_uframes_t n_data_frame;
	long n_data_size;
	unsigned int n_period = 0;
	int i;
	struct timeval t;

	spin_lock(dpcm->pcm_lock);
	/* get AI outring data size */
	n_data_size = rtk_snd_get_ring_data(dpcm->ring, dpcm->ring_bak);
	n_data_frame = n_data_size / dpcm->input_sample_bytes;

	if (n_data_frame >= runtime->period_size) {
		n_period = n_data_frame / runtime->period_size;
		if (n_period == runtime->periods)
			n_period--;

		/* copy data from ai ring to dma */
		rtk_snd_capture_copy(substream, n_period, 0);

		/* update rp */
		dpcm->pcm_buf_pos += n_period * runtime->period_size;

		pr_debug("[ALSA] pcm_buf_pos= %x\n", dpcm->pcm_buf_pos);

		for (i = 0; i < runtime->channels; i++) {
			dpcm->ring_bak[i].rd_ptr[0] =
				dpcm->ring_bak[i].begin_addr +
				(dpcm->pcm_buf_pos % runtime->buffer_size) *
				dpcm->input_sample_bytes;
			dpcm->ring[i].rd_ptr[0] =
				htonl(0xa0000000|
				((uint) dpcm->ring_bak[i].rd_ptr[0]&0x1FFFFFFF));
		}
		/* update ALSA runtime->hw_ptr */
		spin_unlock(dpcm->pcm_lock);
		snd_pcm_period_elapsed(substream);
		spin_lock(dpcm->pcm_lock);

		do_gettimeofday(&t);
		dpcm->last_time_ms = t.tv_sec*1000 + t.tv_usec/1000;
	} else {
		do_gettimeofday(&t);
		dpcm->current_time_ms = t.tv_sec*1000 + t.tv_usec/1000;

		if ((dpcm->current_time_ms - dpcm->last_time_ms) >= 5000) {
			pr_debug("[ALSA] no data in %ld millisecond\n",
				dpcm->current_time_ms - dpcm->last_time_ms);
			dpcm->last_time_ms = dpcm->current_time_ms;

			/* write zero data to dma_area
			when FW doesn't have data in 5 seconds */
			rtk_snd_capture_copy(substream, 1, 1);

			/* update rp */
			dpcm->pcm_buf_pos += runtime->period_size;
			pr_debug("[ALSA] pcm_buf_pos = %x\n", dpcm->pcm_buf_pos);

			/* update ALSA runtime->status->hw_ptr */
			spin_unlock(dpcm->pcm_lock);
			snd_pcm_period_elapsed(substream);
			spin_lock(dpcm->pcm_lock);
		}
	}

	if (dpcm->running) {
		mod_timer(&dpcm->timer, dpcm->period_jiffies + jiffies);
	}
	spin_unlock(dpcm->pcm_lock);
}

static snd_pcm_uframes_t rtk_snd_playback_pointer(
	struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	snd_pcm_uframes_t pos;
	unsigned long flags;
	spin_lock_irqsave(dpcm->pcm_lock, flags);
	pos = (snd_pcm_uframes_t) dpcm->pcm_buf_pos % runtime->buffer_size;
	spin_unlock_irqrestore(dpcm->pcm_lock, flags);
	return pos;
}

static snd_pcm_uframes_t rtk_snd_capture_pointer(
	struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;
	snd_pcm_uframes_t pos;
	unsigned long flags;
	spin_lock_irqsave(dpcm->pcm_lock, flags);
	pos = (snd_pcm_uframes_t) dpcm->pcm_buf_pos % runtime->buffer_size;
	spin_unlock_irqrestore(dpcm->pcm_lock, flags);
	return pos;
}

static struct snd_pcm_hardware rtk_snd_playback = {
	.info =	SNDRV_PCM_INFO_MMAP |
			SNDRV_PCM_INFO_INTERLEAVED |
			SNDRV_PCM_INFO_NONINTERLEAVED |
			SNDRV_PCM_INFO_MMAP_VALID,
	.formats = (SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S16_BE),
	.rates = USE_RATE,
	.rate_min = USE_RATE_MIN,
	.rate_max =	USE_RATE_MAX,
	.channels_min =	1,
	.channels_max =	2,
	.buffer_bytes_max =	MAX_BUFFER_SIZE,
	.period_bytes_min =	MIN_PERIOD_SIZE,
	.period_bytes_max =	MAX_PERIOD_SIZE,
	.periods_min = USE_PERIODS_MIN,
	.periods_max = USE_PERIODS_MAX,
	.fifo_size = 32,
};

static struct snd_pcm_hardware rtk_snd_capture = {
	.info =	SNDRV_PCM_INFO_MMAP |
			SNDRV_PCM_INFO_INTERLEAVED |
			SNDRV_PCM_INFO_NONINTERLEAVED |
			SNDRV_PCM_INFO_MMAP_VALID,
	.formats = USE_FORMATS,
	.rates = SNDRV_PCM_RATE_48000,
	.rate_min =	48000,
	.rate_max =	48000,
	.channels_min =	USE_CHANNELS_MAX, // only 2 channel
	.channels_max =	USE_CHANNELS_MAX,
	.buffer_bytes_max =	MAX_BUFFER_SIZE,
	.period_bytes_min =	MIN_PERIOD_SIZE,
	.period_bytes_max =	MAX_PERIOD_SIZE,
	.periods_min = USE_PERIODS_MIN,
	.periods_max = USE_PERIODS_MAX,
	.fifo_size = 32,
};

static void rtk_snd_runtime_free(struct snd_pcm_runtime *runtime)
{
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	pr_debug("[ALSA] %s\n", __func__);

	if (dpcm == NULL) {
		return;
	}

	dma_free_coherent(dpcm->card->card->dev, sizeof(*dpcm), dpcm, dpcm->phy_addr);
	runtime->private_data = NULL;
}

static void snd_card_capture_runtime_free(struct snd_pcm_runtime *runtime)
{
	struct snd_card *card;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	pr_debug("[ALSA] [%s]\n", __func__);

	if (dpcm == NULL) {
		return;
	}

	card = dpcm->card->card;

	if (dpcm->pcm_lock != NULL) {
		kfree(dpcm->pcm_lock);
	}

	if (dpcm->ring_p)
		dma_free_coherent(card->dev, runtime->channels * dpcm->buffer_byte_size,
			dpcm->ring_p, dpcm->ring_phy_addr);

	dma_free_coherent(card->dev, sizeof(*dpcm), dpcm, dpcm->phy_addr);
	runtime->private_data = NULL;
}

static int rtk_snd_playback_hw_params(
	struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *hw_params)
{
	int err = 0;
	pr_debug("[ALSA] [%s]\n", __func__);

	if (rtk_snd_open(substream) < 0)
		return -ENOMEM;

	err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
	return err;
}

static int rtk_snd_capture_hw_params(
	struct snd_pcm_substream *substream,
	struct snd_pcm_hw_params *hw_params)
{
	int err = 0;
	pr_debug("[ALSA] [%s] size %x\n", __func__, params_buffer_bytes(hw_params));
	err = snd_pcm_lib_malloc_pages(substream, params_buffer_bytes(hw_params));
	return err;
}

static int rtk_snd_playback_hw_free(struct snd_pcm_substream *substream)
{
	int ret;
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;

	pr_debug("[ALSA] [%s]\n", __func__);

	ret = 0;

	if (dpcm == NULL || dpcm->ring_init == 0) {
		if (dpcm && dpcm->ao_pin_id != 0) {
			ret = rtk_snd_release_flashpin_id(dpcm->card->card, dpcm->ao_pin_id);
#ifdef USE_FIXED_AO_PINID
			if (ret < 0) {
				release_error[substream->pcm->device] = dpcm->ao_pin_id;
			}

			dpcm->ao_pin_id = 0;
			used_ao_pin[substream->pcm->device] = 0;
			pr_debug("[ALSA] reset used_ao_pin[%d] %d\n",
				substream->pcm->device, used_ao_pin[substream->pcm->device]);
#endif
		}
		goto exit;
	}
	ret = rtk_snd_flush(substream);

#ifdef USE_FIXED_AO_PINID
	if (ret < 0)
		flush_error[substream->pcm->device] = 1;
#endif

	ret = rtk_snd_pause(substream);

#ifdef USE_FIXED_AO_PINID
	if (ret < 0)
		pause_error[substream->pcm->device] = 1;
#endif

	ret = rtk_snd_close(substream);

#ifdef USE_FIXED_AO_PINID
	if (ret < 0)
		close_error[substream->pcm->device] = 1;
#endif

	ret = rtk_snd_release_flashpin_id(dpcm->card->card, dpcm->ao_pin_id);
	dpcm->card->ao_pin_id[substream->pcm->device] = 0;
#ifdef USE_FIXED_AO_PINID
	if (ret < 0)
		release_error[substream->pcm->device] = dpcm->ao_pin_id;

	dpcm->ao_pin_id = 0;
	used_ao_pin[substream->pcm->device] = 0;
#endif

exit:
	return snd_pcm_lib_free_pages(substream);
}

static int rtk_snd_capture_hw_free(struct snd_pcm_substream *substream)
{
	pr_debug("[ALSA] [%s]\n", __func__);
	return snd_pcm_lib_free_pages(substream);
}

static int rtk_snd_playback_open(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct snd_card_mars *mars;
	struct rtk_snd_pcm *dpcm;
	dma_addr_t dat;
	void *p;

	pr_debug("[ALSA] [%s]\n", __func__);

	mars = (struct snd_card_mars *)(substream->pcm->card->private_data);

    mars->card->dev->dma_mask = &mars->card->dev->coherent_dma_mask;
    if(dma_set_mask(mars->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
    }
    arch_setup_dma_ops(mars->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(mars->card->dev, sizeof(*dpcm), &dat, GFP_ATOMIC);

	if (!p) {
		pr_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, sizeof(struct rtk_snd_pcm));

	dpcm = p;
	dpcm->phy_addr = dat;
	pr_debug("[ALSA] dpcm address = %lx\n", (unsigned long) dpcm);

	if (rtk_snd_init(mars->card)) {
		dma_free_coherent(mars->card->dev, sizeof(*dpcm), dpcm, dpcm->phy_addr);
		return -ENOMEDIUM;
	}

	dpcm->ao_agent = alsa_agent;
	dpcm->pcm_lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL);

	if (dpcm->pcm_lock == NULL) {
		pr_err("[ALSA] malloc mem fail\n");
		dma_free_coherent(mars->card->dev, sizeof(*dpcm), dpcm, dpcm->phy_addr);
		return -ENOMEM;
	}

	spin_lock_init(dpcm->pcm_lock);

	runtime->private_data = dpcm;
	runtime->private_free = rtk_snd_runtime_free;

	memcpy(&runtime->hw,&rtk_snd_playback, sizeof(struct snd_pcm_hardware));
	runtime->hw.period_bytes_min = min_period_size;
	dpcm->substream = substream;
	dpcm->card = mars;

	setup_timer(&dpcm->timer, rtk_snd_pcm_freerun_timer_function, (unsigned long) dpcm);

	dpcm->ring_init = 0;

	snd_pcm_hw_constraint_minmax(runtime,SNDRV_PCM_HW_PARAM_BUFFER_TIME, 20000, 1000000);

	pr_debug("[ALSA] open playback device %d\n", substream->pcm->device);
	return 0;
}

static int rtk_snd_capture_open(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm;
	struct snd_card_mars *mars;
	int err;
	void *p;
	dma_addr_t dat;

	mars = (struct snd_card_mars *)	(substream->pcm->card->private_data);

	/* allocate memory for card instance */

	mars->card->dev->dma_mask = &mars->card->dev->coherent_dma_mask;
	if(dma_set_mask(mars->card->dev, DMA_BIT_MASK(32))) {
		pr_err("[ALSA] %d:DMA not supported\n",__LINE__);
	}
	arch_setup_dma_ops(mars->card->dev, 0, 0, NULL, false);

	p = dma_alloc_coherent(mars->card->dev, sizeof(*dpcm), &dat, GFP_ATOMIC);

	if (!p)	{
		pr_err("[ALSA] %d allocate memory fail\n", __LINE__);
		return -ENOMEM;
	}

	/* set parameter to 0, for snapshot */
	memset(p, 0, sizeof(struct rtk_snd_cap_pcm));

	dpcm = p;
	dpcm->phy_addr = dat;

	dpcm->pcm_lock = kmalloc(sizeof(spinlock_t), GFP_KERNEL);

	if (dpcm->pcm_lock == NULL) {
		pr_err("[ALSA] malloc mem fail\n");
		dma_free_coherent(mars->card->dev, sizeof(*dpcm), dpcm, dpcm->phy_addr);
		return -ENOMEM;
	}

	pr_debug("[ALSA] %d\n", __LINE__);
	spin_lock_init(dpcm->pcm_lock);

	/* set pcm capture hardware consraint */
	memcpy(&runtime->hw, &rtk_snd_capture, sizeof(struct snd_pcm_hardware));

	dpcm->substream = substream;
	runtime->private_data = dpcm;
	runtime->private_free = snd_card_capture_runtime_free;

	dpcm->card = mars;

	/* Mars 1 for AI capture, Mars 2 for AO capture */
	if (!strcmp(dpcm->card->card->longname, "Mars 1")) {
		if (rtk_snd_create_ai_agent(substream) < 0) {
			err = -ENOMEM;
			goto fail;
		}
	} else {
		if (rtk_snd_create_ao_capture_agent(substream) < 0) {
			err = -ENOMEM;
			goto fail;
		}
	}

	/* init capture timer */
	setup_timer(&dpcm->timer, rtk_snd_pcm_capture_timer_function, (unsigned long) dpcm);

	dpcm->ring_init = 0;

	pr_debug("[ALSA] open a realtek pcm capture success\n");
	return 0;

fail:
	pr_err("[ALSA] open a realtek pcm capture fail\n");
	if (dpcm) {
		if (dpcm->pcm_lock != NULL) {
			kfree(dpcm->pcm_lock);
		}

		dma_free_coherent(mars->card->dev, sizeof(*dpcm), dpcm, dpcm->phy_addr);
	}
	return err;
}

static int rtk_snd_playback_close(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_pcm *dpcm = runtime->private_data;
	int i;
	pr_debug("[ALSA] [%s]\n", __func__);

	spin_lock(dpcm->pcm_lock);
	pr_debug("[ALSA] del timer close\n");
	del_timer(&dpcm->timer);
	spin_unlock(dpcm->pcm_lock);

	if (dpcm->pcm_lock != NULL) {
		kfree(dpcm->pcm_lock);
	}

	for (i = 0; i < runtime->channels; i++) {
		if (dpcm->ao_in_ring_p[i]) {
			if (dpcm->audiopath == AUDIO_PATH_DECODER_AO) {
				dvr_free(dpcm->ao_in_ring_p[i]);
			} else {
				pr_err("[ALSA] dpcm->ao_in_ring_p[%d] %x\n", i, (unsigned int)dpcm->ao_in_ring_p[i]);
			}
		}
	}

	snd_open_count--;
	return 0;
}

static int rtk_snd_capture_close(struct snd_pcm_substream *substream)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	struct rtk_snd_cap_pcm *dpcm = runtime->private_data;

	pr_debug("[ALSA] close a realtek pcm capture channel\n");
	/* Mars 1 for AI capture, Mars 2 for AO capture */
	if (!strcmp(dpcm->card->card->longname, "Mars 1")) {
		pr_debug("[ALSA] close AI capture channel\n");
		snd_realtek_ai_hw_close(substream);
	} else {
		pr_debug("[ALSA] close AO capture channel\n");
		snd_realtek_ao_capture_hw_close(substream);
	}

	spin_lock(dpcm->pcm_lock);
	del_timer(&dpcm->timer);
	spin_unlock(dpcm->pcm_lock);
	snd_open_ai_count--;
	return 0;
}

static int rtk_snd_playback_ioctl(struct snd_pcm_substream *substream,
	unsigned int cmd, void *arg)
{
	switch (cmd) {
	default:
		return snd_pcm_lib_ioctl(substream, cmd, arg);
		break;

	}

	return 0;
}

static int rtk_snd_capture_ioctl(struct snd_pcm_substream *substream,
	unsigned int cmd, void *arg)
{
	switch (cmd) {
	default:
		return snd_pcm_lib_ioctl(substream, cmd, arg);
		break;
	}

	return 0;
}

static struct snd_pcm_ops rtk_snd_playback_ops = {
	.open =	rtk_snd_playback_open,
	.close = rtk_snd_playback_close,
	.ioctl = rtk_snd_playback_ioctl,
	.hw_params = rtk_snd_playback_hw_params,
	.hw_free = rtk_snd_playback_hw_free,
	.prepare = rtk_snd_playback_prepare,
	.trigger = rtk_snd_playback_trigger,
	.pointer = rtk_snd_playback_pointer,
};

static struct snd_pcm_ops rtk_snd_capture_ops = {
	.open =	rtk_snd_capture_open,
	.close = rtk_snd_capture_close,
	.ioctl = rtk_snd_capture_ioctl,
	.hw_params = rtk_snd_capture_hw_params,
	.hw_free = rtk_snd_capture_hw_free,
	.prepare = rtk_snd_capture_prepare,
	.trigger = rtk_snd_capture_trigger,
	.pointer = rtk_snd_capture_pointer,
};

static int __init rtk_snd_pcm(struct snd_card_mars *mars,
	int device, int substreams, int card)
{
	struct snd_pcm *pcm;
	int err;
	struct snd_pcm_substream *p;
	int i;

	if (have_global_ai == 1 && device < 4  && card == 0) {
		pr_debug("[ALSA] support capture deivce C%dD%d\n",
			card, device);
		err = snd_pcm_new(mars->card, "Mars PCM", device,
			substreams, MAX_AI_DEVICES, &pcm);
		if (err < 0)
			return err;
	} else if (card == 0 && device != 0) {
		pr_debug("[ALSA] not support capture device C%dD%d\n",
			card, device);
		err = snd_pcm_new(mars->card, "Mars PCM", device,
			substreams, 0, &pcm);
		if (err < 0)
			return err;
	} else if (card == 1 && device == 0) {
		pr_debug("[ALSA] support capture device C%dD%d\n",
			card, device);
		err = snd_pcm_new(mars->card, "Mars PCM", device,
			0, MAX_AI_DEVICES, &pcm);
		if (err < 0)
			return err;
	} else {
		pr_info("[ALSA] not support all device C%dD%d\n", card, device);
	}

	if (card == 0){
		snd_pcm_set_ops(pcm,
			SNDRV_PCM_STREAM_PLAYBACK, &rtk_snd_playback_ops);
	}

	if ((have_global_ai == 1 && device < 4 && card == 0) ||
		(card == 1 && device == 0)) {
		snd_pcm_set_ops(pcm,
			SNDRV_PCM_STREAM_CAPTURE, &rtk_snd_capture_ops);
	}

	/* set init flashpin volume to 0dB*/
	for (i = 0; i < MIXER_ADDR_MAX; i++)
		mars->ao_flash_volume[i] = 389;

	pcm->private_data = mars;
	pcm->info_flags = 0;
	strcpy(pcm->name, "Mars PCM");

	/* set playback device */
	if (card == 0) {
		p = pcm->streams[0].substream;
		for (i = 0; i < substreams; i++) {
			p->dma_buffer.dev.dev =	snd_dma_continuous_data(GFP_KERNEL);
			p->dma_buffer.dev.type = SNDRV_RTK_DMA_TYPE;
			p = p->next;
		}
	}

	/* set capture device */
	if ((have_global_ai == 1 && device < 4 && card == 0) ||
		(card == 1 && device == 0)) {
        p = pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream;
		for (i = 0; i < MAX_AI_DEVICES; i++) {
			p->dma_buffer.dev.dev =	snd_dma_continuous_data(GFP_KERNEL);
			p->dma_buffer.dev.type = SNDRV_RTK_DMA_TYPE;
			p = p->next;
		}
	}

	return 0;
}

#define MARS_VOLUME(xname, xindex, addr)\
{	.iface = SNDRV_CTL_ELEM_IFACE_MIXER,\
	.name = xname,\
	.index = xindex,\
	.info = snd_mars_volume_info,\
	.get = snd_mars_volume_get,\
	.put = snd_mars_volume_put,\
	.private_value = addr }

static int snd_mars_volume_info(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_info *uinfo)
{
	pr_debug("[ALSA] %s\n", __func__);
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 100;
	uinfo->value.integer.max = 509;
	return 0;
}

static int snd_mars_volume_get(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_card_mars *mars = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	int addr = kcontrol->private_value;
	pr_debug("[ALSA] %s\n", __func__);
	spin_lock_irqsave(&mars->mixer_lock, flags);
	ucontrol->value.integer.value[0] = mars->ao_flash_volume[addr];
	spin_unlock_irqrestore(&mars->mixer_lock, flags);
	return 0;
}

static int snd_mars_volume_put(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_card_mars *mars = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	int addr, volume;
	pr_debug("[ALSA] %s\n", __func__);

	addr = kcontrol->private_value;
	volume = ucontrol->value.integer.value[0];

	/* check volume gain is correct */
	if (volume < 100)
		volume = 100;
	if (volume > 509)
		volume = 509;

	pr_debug("[ALSA] volume(%d) %d\n", addr, volume);

	if ((addr >= MIXER_ADDR_0) && (addr <= MIXER_ADDR_7)) {
		spin_lock_irqsave(&mars->mixer_lock, flags);
		mars->ao_flash_change[addr] = (mars->ao_flash_volume[addr] != volume);
		mars->ao_flash_volume[addr] = volume;
		spin_unlock_irqrestore(&mars->mixer_lock, flags);
		schedule_work(&mars->work_volume);
	return mars->ao_flash_change[addr];
	}

	return 0;
}

static struct snd_kcontrol_new snd_mars_controls[] = {
	MARS_VOLUME("AMIXER0", 0, MIXER_ADDR_0),
	MARS_VOLUME("AMIXER1", 0, MIXER_ADDR_1),
	MARS_VOLUME("AMIXER2", 0, MIXER_ADDR_2),
	MARS_VOLUME("AMIXER3", 0, MIXER_ADDR_3),
	MARS_VOLUME("AMIXER4", 0, MIXER_ADDR_4),
	MARS_VOLUME("AMIXER5", 0, MIXER_ADDR_5),
	MARS_VOLUME("AMIXER6", 0, MIXER_ADDR_6),
	MARS_VOLUME("AMIXER7", 0, MIXER_ADDR_7),
};

static int __init rtk_snd_new_mixer(struct snd_card_mars *mars)
{
	struct snd_card *card = mars->card;
	unsigned int idx;
	int err;

	spin_lock_init(&mars->mixer_lock);
	INIT_WORK(&mars->work_volume, rtk_snd_playback_volume_work);

	strcpy(card->mixername, "Mars Mixer");

	for (idx = 0; idx < ARRAY_SIZE(snd_mars_controls); idx++) {
		err = snd_ctl_add(card,
			snd_ctl_new1(&snd_mars_controls[idx], mars));
		if (err < 0)
			return err;
	}
	return 0;
}

static int rtk_snd_probe(struct platform_device *devptr)
{
	struct snd_card *card;
	struct snd_card_mars *mars;
	int idx, err;
	int dev;

	dev = devptr->id;

	if (!enable[dev])
		return -ENODEV;

	err = snd_card_new(&devptr->dev, index[dev], id[dev],
			THIS_MODULE, sizeof(struct snd_card_mars), &card);
	if (err < 0)
		return err;
	mars = (struct snd_card_mars *)card->private_data;
	mars->card = card;
	mutex_init(&mars->rpc_lock);

	if (get_cap == 0) {
		err = rtk_snd_check_audio_fw_capability(card);

		if (err < 0)
			return err;

		get_cap = 1;
	}

	for (idx = 0; idx < MAX_PCM_DEVICES && idx < pcm_devs[dev]; idx++) {
		if (pcm_substreams[dev] < 1)
			pcm_substreams[dev] = 1;
		if (pcm_substreams[dev] > MAX_PCM_SUBSTREAMS)
			pcm_substreams[dev] = MAX_PCM_SUBSTREAMS;

		err = rtk_snd_pcm(mars, idx, pcm_substreams[dev], dev);

		if (err < 0)
			goto __nodev;
	}

	err = rtk_snd_new_mixer(mars);
	if (err < 0)
		goto __nodev;

	strcpy(card->driver, "Mars");
	strcpy(card->shortname, "Mars");
	sprintf(card->longname, "Mars %i", dev + 1);

	err = snd_card_register(card);
	if (err == 0) {
		platform_set_drvdata(devptr, card);
		return 0;
	}

__nodev:
	snd_card_free(platform_get_drvdata(devptr));
	return err;
}

static int rtk_snd_remove(struct platform_device *devptr)
{
	snd_card_free(platform_get_drvdata(devptr));
	platform_set_drvdata(devptr, NULL);
	return 0;
}

#ifdef CONFIG_PM_SLEEP
static int rtk_snd_pm_suspend(struct device *dev)
{
	pr_debug("[ALSA] rtk_snd_pm_suspend!!!\n");
	return 0;
}

static int rtk_snd_pm_resume(struct device *dev)
{
	pr_debug("[ALSA] rtk_snd_pm_resume!!!\n");
	return 0;
}

static SIMPLE_DEV_PM_OPS(rtk_snd_pm, rtk_snd_pm_suspend, rtk_snd_pm_resume);
#define RTK_SND_OPS	&rtk_snd_pm
#else
#define RTK_SND_OPS	NULL
#endif

#define RTK_SND_DRIVER	"rtk_snd"

static struct platform_driver rtk_snd_driver = {
	.probe		= rtk_snd_probe,
	.remove		= rtk_snd_remove,
	.driver		= {
		.name	= RTK_SND_DRIVER,
		.owner	= THIS_MODULE,
		.pm	= RTK_SND_OPS,
	},
};

static int alsa_card_mars_init(void)
{
	int dev, cards, err;
	int ret = 0;
	struct platform_device *device;

#ifdef USE_FIXED_AO_PINID
	int i;

	for (i = 0; i < MAX_PCM_DEVICES; i++) {
		used_ao_pin[i] = 0;
		flush_error[i] = 0;
		pause_error[i] = 0;
		close_error[i] = 0;
		release_error[i] = 0;
	}
#endif

	snd_open_count = 0;
	snd_open_ai_count = 0;
	alsa_agent = -1;

	err = platform_driver_register(&rtk_snd_driver);
	if (err < 0)
		return err;

	for (dev = cards = 0; dev < SNDRV_CARDS && enable[dev]; dev++) {
		device = platform_device_register_simple(RTK_SND_DRIVER,
							 dev, NULL, 0);

		if (IS_ERR(device))
			continue;
		if (!platform_get_drvdata(device)) {
			platform_device_unregister(device);
			continue;
		}
		devices[dev] = device;

		cards++;
	}

	if (!cards)
		ret = -ENODEV;

	return ret;
}

static void __exit alsa_card_mars_exit(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(devices); ++i)
		platform_device_unregister(devices[i]);
	platform_driver_unregister(&rtk_snd_driver);
}

late_initcall(alsa_card_mars_init);
module_exit(alsa_card_mars_exit);
