
#ifndef __AUDIO_INBAND_API_H__
#define __AUDIO_INBAND_API_H__

#include "AudioRPCBaseDS_data.h"

/** Audio Inband APIs */
/**
      This spec defines a set of API to send command via cmd fifo.
        Inband command is passed through inband cmd fifo.
        System software should take the responsibility to convert and write cmds to the cmd fifo, and
        keep the cmd fifo from overflow.
*/

/** Audio inband cmd type. I use prefix "AUDIO_DEC_" to label the cmd used in Audio decoder.
    Prefix AUDIO_MIXER is used to lable the Mixer commands.
*/

//  downmix could be placed on in-band queue
//  set media type or private information to in-band queue
typedef enum
{
    /* Audio Decoder In-band Command */
    AUDIO_DEC_INBAND_CMD_TYPE_PTS = 0,
    AUDIO_DEC_INBAND_CMD_TYPE_NEW_SEG = 1,      /* let begin_AGC_gain = 1 */
    AUDIO_DEC_INBAMD_CMD_TYPE_NEW_FORMAT = 2,
    AUDIO_DEC_INBAND_CMD_TYPE_EOS = 3,          /* Can not be passed, sent back to system */
    AUDIO_DEC_INBAND_CMD_TYPE_CONTEXT = 4,      /* write debug information, need a RPC_ToSystem command *//* Can not be passed, sent back to system */
    AUDIO_DEC_INBAND_CMD_TYPE_DECODE = 5,       /* Information for each decoder is inclueded */
    AUDIO_DEC_INABND_CMD_TYPE_PTS_SKIP = 6,
    AUDIO_DEC_INBAND_CMD_TYPE_PRIVATE_INFO = 7,
    AUDIO_DEC_INBAND_CMD_TYPE_VORBIS_PACKETINFO = 8,    /* Information about vorbis packets */

    AUDIO_DEC_INBAND_CMD_TYPE_BS_DISCONTINUITY = 9,
    AUDIO_DEC_INBAND_CMD_TYPE_RESYNC = 10,
    AUDIO_DEC_INBAND_CMD_TYPE_CGMS_INFO = 11,
    AUDIO_DEC_INBAND_CMD_TYPE_RALSD_INFO = 12,
    AUDIO_DEC_INBAND_CMD_TYPE_WMAPRO_DRC = 13,
    AUDIO_DEC_INBAND_CMD_TYPE_WMAPRO_DWNMIX_MTRX = 14,

    AUDIO_DEC_INBAND_CMD_TYPE_EMPHASIS = 15,        // for lpcm emphasis info
    AUDIO_DEC_INBAND_CMD_TYPE_SHARED_MEM = 16, /* physical address for decoder agent update infomation to system */
    AUDIO_DEC_INBAND_CMD_TYPE_APE_SKIP_BIT = 17,
  AUDIO_DEC_INBAND_CMD_TYPE_AD_DESCRIPTOR = 18,

  AUDIO_INBAND_CMD_MS12_IIDK_USE_CASE = 19,
  AUDIO_INBAND_CMD_MS12_IIDK_INIT_PARAMS = 20,
  AUDIO_INBAND_CMD_MS12_IIDK_RUNTIME_PARAMS = 21,

  AUDIO_DEC_INBAND_CMD_TYPE_DDP_METADATA = 22,
  AUDIO_DEC_INBAND_CMD_TYPE_AAC_METADATA = 23,
  AUDIO_DEC_INBAND_CMD_TYPE_DAP_PARAMS = 24,

    AUDIO_INBAND_CMD_DAP_DISPLAY_INFO = 25,

  AUDIO_INBAND_CMD_DAP_DUMP_METADATA_INFO = 26,
  AUDIO_INBAND_CMD_MS12_MIXER_CMD = 27,

  AUDIO_DEC_INBAND_CMD_TYPE_DDP_INTLOUD_METADATA = 28,
  AUDIO_DEC_INBAND_CMD_TYPE_DDP_EVOLUTION_METADATA = 29,
  AUDIO_DEC_INBAND_CMD_TYPE_DDP_MIXING_METADATA = 30,

  AUDIO_DEC_INBAND_CMD_TYPE_AC4_METADATA = 31,
  AUDIO_DEC_INBAND_CMD_TYPE_DDPENC_METADATA = 32,

  /* Audio AO Mixer In-band Command */
  AUDIO_AO_MIXER_INBAND_CMD_TYPE_SET_MIXER_RPTS = 64,
  AUDIO_AO_MIXER_INBAND_CMD_TYPE_SET_BLEND,

  /* Audio DV Mixer In-band Command */
    AUDIO_DV_MIXER_INBAND_CMD_TYPE_SET_BLEND,

  AUDIO_SYS_PROCESS_CMD_INIT_RING_HEADER = 80,
  AUDIO_SYS_PROCESS_CMD_PAYLOAD_HEADER = 81,
  AUDIO_SYS_PROCESS_CMD_COMMAND_INFO = 82,
  AUDIO_SYS_PROCESS_CMD_COMMAND_EOS = 83,
  // MS12 IIDK CERT
  AUDIO_SYS_PROCESS_CMD_COMMAND_AC4_TIMESTAMP_PARA = 84,
  AUDIO_SYS_PROCESS_CMD_COMMAND_NUM = 85, // keep this at last item for count number

} AUDIO_INBAND_CMD_TYPE ;

typedef struct
{
    AUDIO_INBAND_CMD_TYPE   type ;
    long                    size ;
} AUDIO_INBAND_CMD_PKT_HEADER;

/* Audio Decoder Inband APIs */
/**
==========================================================================================
    Note (Please read):

    At decoder filter init time, 2 ringbuffers are inited with type of STREAM and COMMAND
    Since parsing mode is necessaey for audio firmware, the decoder will peek the bit stream buffer instead of
    reading it out.

    The inband commands are issued in the command segment, each segment looks this way
    ([] means optional):
        ----------
        NEW_SEG
        ----------
        DECODE
        FORMAT
        ----------
        [PTS]
        [CONTEXT]
        ----------
        [EOS]
        ----------
    System can issue one or more command segments. Decoder will finish decoding one segment
    before decoding the new one. Decoding may be stopped in 2 ways:
    1. decode is finished (PTSDuration is finished)
    2. EOS or another NEW_SEG is reached.
    Otherwise, decoder will wait for more bistream and bistream commands (PTS, SEQ_END, CONTEXT).

    System must issue all bistream commands before updating ring buffer write pointer to avoid
    racing condition.


    ==========================================================================================
**/

/**
    \brief
        This function will send a new segment tag in cmd fifo.
        Audio decoder will check cmd fifo and handle this new seg tag
        when decodeing to the location on address wPtr. The Audio
        decoder will expect a pts followed by the new seg tag immediately.
        Then, the following decode command will be executed in pts offset
        to the pts of new segement.

    \param wPtr
        A coresponding address to the bit stream buffer.
*/


typedef enum
{
    AUDIO_BIG_ENDIAN        = 0,       // CD,DVD type
    AUDIO_LITTLE_ENDIAN     = 1,
    AUDIO_LPCM_DHMV_TYPE    = 2,       // typo, stay here for backware compatilbe, HDMV type
    AUDIO_LPCM_HDMV_TYPE    = 2,       // HDMV type
} AUDIO_ENDIANTYPE;


typedef enum
{
    AUDIO_CGMS_COPY_FREE,
    AUDIO_CGMS_COPY_NEVER,
    AUDIO_CGMS_COPY_ONCE,
    AUDIO_CGMS_INVALID,
} AUDIO_CGMS_TYPE;

typedef enum
{
    AUDIO_DEC_WATERLEVEL,   // set struct AUDIO_DEC_WATERLEVEL_INFO in shared memory
} AUDIO_DEC_SHARED_TYPE;

typedef struct
{
    int undeflow; // 1:underflow
}   AUDIO_DEC_WATERLEVEL_INFO ;

typedef struct
{
    AUDIO_DEC_SHARED_TYPE   type;
    unsigned long           mem_size; // size of shared memory, ex. should be same as sizeof(AUDIO_DEC_WATERLEVEL_INFO)
    unsigned long           phy_addr;
}   AUDIO_DEC_SHARED_INFO ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long wPtr ;
}   AUDIO_DEC_NEW_SEG ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long   wPtr ;
    unsigned long   CGMSInfo;
}   AUDIO_DEC_CGMS_INFO ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long   SeekByteNum ;
    unsigned long   SeekBitNum ;
}   AUDIO_APEDEC_SEEK_INFO ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long   wPtr ;
    unsigned long   emphasis;
}   AUDIO_DEC_EMPHASIS_INFO ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    AUDIO_DEC_SHARED_INFO       info;
}   AUDIO_DEC_SHARED_MEM ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long wPtr ;
    long          pktSize;
}   AUDIO_DEC_RALSD_INFO ;

/*  LPCM

    privateInfo[0] = sampling rate;
    privateInfo[1] = bitWidth;
    privateInfo[2] = downMixEnable, -1 = disable, >= 1 means the target channel number.

    MPEG

    privateInfo[0] = deemphasis, 1 = emphasis enable;
    privateInfo[1] = extbsExit, 1 = exist, 0 = not exist
    privateInfo[2] = downMixEnable, -1 = disable, >= 1 means the target channel number.

    AC3

    privateInfo[0] = bitStreamMode;
                    000 = complete main (CM)
                    001 = music and effect (ME)
                    010 = visually impaired (VI)
                    011 = hearing impaired (HI)
                    100 = dialogou (D)
                    101 = commentory (C)
                    110 = emmergency (E)
                    111 = voice over (VO)

    privateInfo[1] = ACmode;
                    001 & bitStramMode = 111, VO
                    010~111 & bitStramMode = 111, Karaoke
                    000     L1+L2
                    001     1/0, C
                    010     2/0, L+R
                    011     L,C,R
                    100     L,R,S
                    101     L,C,R,S
                    110     L,R,SL,SR
                    111     L,C,R,SL,SR

    privateInfo[2] = downMixEnable, -1 = disable, >= 1 means the target channel number.

*/

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    AUDIO_DEC_TYPE              audioType;
    long                        privateInfo[8];  // note: privateinfo[6] is used for choosing decoder sync pts method
}   AUDIO_DEC_NEW_FORMAT ;


typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr ;
    unsigned long               PTSH;
    unsigned long               PTSL;
} AUDIO_DEC_PTS_INFO ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               PTSH;
    unsigned long               PTSL;

    int          start_offset;              /**< Start sample of this meta data set */
    unsigned int acmod;                     /**< DD channel mode */
    unsigned int lfeon;                     /**< LFE available */

    /**< downmix metadata */
    unsigned int b_dmx_present;
    unsigned int cmixlev;                   /**< Center mix level */
    unsigned int surmixlev;                 /**< Surround mix level */
    unsigned int b_dsurmod_present;         /**< boolean indicating the presence of Dolby surround mode */
    unsigned int dsurmod;                   /**< Dolby surround mode */
    unsigned int b_ext1_present;            /**< Extended bitstream information 1 present */
    unsigned int dmixmod;                   /**< Preferred downmix mode */
    unsigned int ltrtcmixlev;               /**< Lt/Rt center mix level */
    unsigned int ltrtsurmixlev;             /**< Lt/Rt surround mix level */
    unsigned int lorocmixlev;               /**< Lo/Ro center mix level */
    unsigned int lorosurmixlev;             /**< Lo/Ro surround mix level */

    /**< dynrng & compr metadata */
    unsigned int b_dialnorm_present[2];     /**< Program reference level (dialnorm) exists */
    int          dialnorm[2];               /**< Program reference level (dialnorm) */
    unsigned int b_dynrng_present[2][6];    /**< boolean indicating the presence of dynamic range information */
    int          dynrng[2][6];              /**< dynamic range values for each block */
    unsigned int dynrng_start_offset[2][6]; /**< start offsets of dynamic range in samples */
    unsigned int b_compr_present[2];        /**< boolean indicating the presence of heavy compression (RF mode) */
    int          compr[2];                  /**< heavy compression values valid a the complete frame */
} AUDIO_DDP_METADATA;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               PTSH;
    unsigned long               PTSL;
    int frameid ;
    int       start_offset; /**< Start sample of this meta data set */
    int extpgmscl;          /**< External program scale factor (6 bits). Valid values are 0 to 63, with 0 interpreted as mute,
                             and 1-63 interpreted as -50 dB to +12 dB of scaling in 1 dB steps  */
    int extpgmlscl;         /**< External program left scale factor  (4 bits)\n
                                 0:   -1dB\n
                                 1:   -2dB\n
                                 2:   -3dB\n
                                 3:   -4dB\n
                                 4:   -5dB\n
                                 5:   -6dB\n
                                 6:   -8dB\n
                                 7:  -10dB\n
                                 8:  -12dB\n
                                 9:  -14dB\n
                                 10: -16dB\n
                                 11: -19dB\n
                                 12: -22dB\n
                                 13: -25dB\n
                                 14: -28dB\n
                                 15: -infinity (mute) */
    int extpgmcscl;         /**< External program center scale factor  (4 bits, interpretation see extpgmlscl) */
    int extpgmrscl;         /**< External program right scale factor  (4 bits, interpretation see extpgmlscl) */
    int extpgmlsscl;        /**< External program left surround scale factor  (4 bits, interpretation see extpgmlscl) */
    int extpgmrsscl;        /**< External program right surround scale factor  (4 bits, interpretation see extpgmlscl) */
    int extpgmaux1scl;      /**< External program left auxiliary surround channel scale factor (4 bits, interpretation see extpgmlscl) */
    int extpgmaux2scl;      /**< External program rigth auxiliary surround channel scale factor (4 bits, interpretation see extpgmlscl) */
    int extpgmlfescl;       /**< External program LFE scale factor  (4 bits, interpretation see extpgmlscl) */
    int dmixscl;            /**< Downmix scale factor  (4 bits, interpretation see extpgmlscl) */
    int panmean;            /**< Pan mean direction index - 8 bits
                                 This 8-bit word defines the mean angle of rotation index relative to the center position for a panned source in a two
                                 dimensional sound field. A value of 0 indicates the panned virtual source points toward the center speaker location
                                 (defined as 0 degrees). The index indicates 1,5 degree increments in a clockwise rotation. Values 0 to 239 represent
                                 0 to 358,5 degrees, while values 240 to 255 are reserved. */
} AUDIO_DDP_MIXING_METADATA;

typedef struct
{
    int                     dialchane;      /*!< The flag which indicates whether "dialogue_channels" exists */
    int                     dialcorre;      /*!< The flag which indicates whether "dialogue_corrected" exists */
    int                     loudcorrtype;   /*!< The flag which indicates whether "loud_corr_type" exists*/
    int                     iturelloude;    /*!< The flag which indicates whether "itu_rel_loudness" exists */
    int                     ituspchloude;   /*!< The flag which indicates whether "itu_spch_loudness" exists */
    int                     st3sloude;      /*!< The flag which indicates whether "st_3s_loudness" exists */
    int                     truepke;        /*!< The flag which indicates whether "true_peak" exists*/
    int                     dmixoffset;     /*!< The flag which indicates whether "downmix_offset" exists */
}audio_ddp_intloud_md_flag;

typedef struct
{

    int  dialogue_channels;  /* not present = -2, invalid = -1, none = 0, Left = 1, Right = 2, Left and Right = 3, Center = 4, Left and Center = 5, Right and Center = 6,
                                Left Right and Center = 7. */
    int  loud_reg_type;      /* Increased. Invalid = -1, not_indicated = 0, ATSC, EBU, FREETV, RESERVED_5~13, MANUAL, CONSUMER_LEVEL */
    int  dialogue_corrected; /* Increased. Not present = -2, invalid = -1, FALSE, TRUE. */
    int  loud_corr_type;     /* Increased. Not present = -2, invalid = -1, streaming, program. */
    int  itu_rel_loudness;   /*!< The range of itu_rel_loudness is [-116, 11].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  itu_spch_loudness;  /*!< The range of itu_spch_loudness is [-116, 11].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  st_3s_loudness;     /*!< The range of st_3s_loudness is [-232, 23].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  true_peak;          /*!< The range of true_peak is [-116, 11].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  downmix_offset;     /*!< The range of downmix_offset is [-15, 15].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
} audio_ddp_intloud_unpacked_md_t;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER         header;
    unsigned long                       wPtr;
    unsigned long                       PTSH;
    unsigned long                       PTSL;

    int                                 start_offset;       /**< Start sample of this meta data set */
    int                                 mdat_present;       /*!< Indicate if the intelligent loudness metadata is present.*/
    int                                 update_mdat_flag;   /*!< Indicate if the intelligent loudness metadata updates in current frame.
                                                               - 1 = The metadata is updated when there is a valid intelligent loudness metadata or downmix is enabled
                                                               - 0 = The metadata is not updated */
    int                                 mdat_substreamid;   /*!< Indicate which substream the intelligent loudness metadata is extracted from. */
    audio_ddp_intloud_md_flag           intloud_mdat_flags; /*!< The exist flags of intelligent loudness data */
    audio_ddp_intloud_unpacked_md_t     intloud_unpacked_md;/*!< The unpacked intelligent loudness metadata */
    int                                 timestamp;          /*!< Indicate the start sample in audio frame, that the payload applies to  */
    int                                 pcm_trusted_is_leveld;
    int                                 pcm_trusted_is_dialogue_enhanced;

    /*!< Intelligent loudness metadata (opaque field if present, all bytes are output for analysis outside of the decoder) */
} AUDIO_DDP_INTLOUD_METADATA;

#define AUDIO_DDP_UDC_EVO_MAX_SERIAL_LEN 1536 // default 3066
typedef struct
{
    int                    size;        /*!< Size of the serialized Evolution data in bytes */
    unsigned char          data[AUDIO_DDP_UDC_EVO_MAX_SERIAL_LEN];  /*!< Serialized Evolution data */
} audio_ddp_udc_serialized_evolution_t;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER          header;
    unsigned long                        wPtr;
    unsigned long                        PTSH;
    unsigned long                        PTSL;

    int                                  start_offset;              /**< Start sample of this meta data set */
    int                                  frameid;                   /**< current frame **/
    audio_ddp_udc_serialized_evolution_t evo_serialized_frame;
    int                                  evo_data_validity; /* Increased. valid = 0, no data, error */
    int                                  b_atmos_present;           /* Indicate atmos present, 0: not present, 1: present */
    int                                  joc_is_active;             /* Indicate JOC. 0: not active, 1:active */
} AUDIO_DDP_EVO_METADATA;


typedef struct
{
    int is_leveled;
    int is_dialogue_enhanced;
} AUDIO_MS12_PCM_TRUST_INDICATION;


typedef struct
{
    int  dialchane;      /*!< The flag which indicates whether "dialogue_channels" exists */
    int  dialcorre;      /*!< The flag which indicates whether "dialogue_corrected" exists */
    int  loudcorrtype;   /*!< The flag which indicates whether "loud_corr_type" exists*/
    int  iturelloude;    /*!< The flag which indicates whether "itu_rel_loudness" exists */
    int  ituspchloude;   /*!< The flag which indicates whether "itu_spch_loudness" exists */
    int  st3sloude;      /*!< The flag which indicates whether "st_3s_loudness" exists */
    int  truepke;        /*!< The flag which indicates whether "true_peak" exists*/
    int  dmixoffset;     /*!< The flag which indicates whether "downmix_offset" exists */
}ddp_ild_md_flag;

typedef struct
{
    int  dialogue_channels;  /* not present = -2, invalid = -1, none = 0, Left = 1, Right = 2, Left and Right = 3, Center = 4, Left and Center = 5, Right and Center = 6,
                                Left Right and Center = 7. */
    int  loud_reg_type;      /* Increased. Invalid = -1, not_indicated = 0, ATSC, EBU, FREETV, RESERVED_5~13, MANUAL, CONSUMER_LEVEL */
    int  dialogue_corrected; /* Increased. Not present = -2, invalid = -1, FALSE, TRUE. */
    int  loud_corr_type;     /* Increased. Not present = -2, invalid = -1, streaming, program. */
    int  itu_rel_loudness;   /*!< The range of itu_rel_loudness is [-116, 11].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  itu_spch_loudness;  /*!< The range of itu_spch_loudness is [-116, 11].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  st_3s_loudness;     /*!< The range of st_3s_loudness is [-232, 23].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  true_peak;          /*!< The range of true_peak is [-116, 11].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
    int  downmix_offset;     /*!< The range of downmix_offset is [-15, 15].
                                "-1024" indicates invalid value. "-512" indicates this variable is not present. */
} ddp_ild_unpacked_md_t;

typedef struct
{
    unsigned long         PTSH;
    unsigned long         PTSL;

    int                   start_offset;       /**< Start sample of this meta data set */
    int                   mdat_present;       /*!< Indicate if the intelligent loudness metadata is present.*/
    int                   update_mdat_flag;   /*!< Indicate if the intelligent loudness metadata updates in current frame.
                                                               - 1 = The metadata is updated when there is a valid intelligent loudness metadata or downmix is enabled
                                                               - 0 = The metadata is not updated */
    int                   mdat_substreamid;   /*!< Indicate which substream the intelligent loudness metadata is extracted from. */
    ddp_ild_md_flag       flags; /*!< The exist flags of intelligent loudness data */
    ddp_ild_unpacked_md_t unpacked;/*!< The unpacked intelligent loudness metadata */
    int                   timestamp;          /*!< Indicate the start sample in audio frame, that the payload applies to  */
    int                   pcm_trusted_is_leveld;
    int                   pcm_trusted_is_dialogue_enhanced;

    /*!< Intelligent loudness metadata (opaque field if present, all bytes are output for analysis outside of the decoder) */
} DDP_ILD_METADATA_INFO;

typedef struct
{
    unsigned long  PTSH;
    unsigned long  PTSL;

    int            start_offset;         /**< Start sample of this meta data set */
    int            ser_frame_size;
    unsigned char* ser_frame_data;
    int            evo_data_validity;    /* Refer to DDPI_UDC_EVO_STATUS, 0:valid, 1:no DATA, 2: Error*/
    int            b_atmos_present;
    int            joc_is_active;
    unsigned char data[AUDIO_DDP_UDC_EVO_MAX_SERIAL_LEN]; // only use in ARM version
} DDP_EVO_METADATA_INFO;

typedef struct
{
    int max_num_channels; /**< Determines the maximum number of channels in the signal processing chain */
    int enc_chmod_locking_mode; /**< Determines whether the encoded channel mode is driven by the input or locked. */
    int pcm_mixing;
    int PP_mixer_delayed;
} DDPENC_IIDK_INIT_PARAMS;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    AUDIO_INBAND_CMD_TYPE commandType;
    //int size;// means vaild data[x] number
    //unsigned int data[12];
    unsigned long               wPtr;
    unsigned long               PTSH;
    unsigned long               PTSL;
    int          start_offset;              /**< Start sample of this meta data set */
    unsigned int frameId;
    int sampling_frequency;
    int acmod;
    int lfeon;
    int a_chan_cfg[2];
    int b_ad_mixing;
    unsigned int delay[2];
    int compressor_profile ;
    int pes_mix_md[5];
    AUDIO_MS12_PCM_TRUST_INDICATION pcm_trust_indication;
    int phase90_shifted;
} AUDIO_AC4_METADATA;

typedef struct
{
    unsigned long  PTSH;
    unsigned long  PTSL;

    int            start_offset;              /**< Start sample of this meta data set */
    int            phase90_shifted;
    int            pcm_trust_is_leveled;
    int            pcm_trust_is_dialogue_enhanced;
}AC4_METADATA_INFO;


typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               PTSH;
    unsigned long               PTSL;

    int          start_offset;              /**< Start sample of this meta data set */
    unsigned int acmod;                     /**< DD channel mode */
    unsigned int lfeon;                     /**< LFE available */

    /**< dynrng & compr metadata */
    unsigned int b_dialnorm_present;                /**< Program reference level (dialnorm) exists */
    int          dialnorm;                          /**< Program reference level (dialnorm) */
    unsigned int b_prl_present[2];                  /**< Program reference level (dialnorm) exists */
    int          prl[2][8];                         /**< Program reference level (dialnorm) */
    unsigned int b_dynrng_present[2];               /**< boolean indicating the presence of dynamic range information */
    int          dynrng[2][8];                      /**< dynamic range values for each block */
    unsigned int dynrng_start_offset[2][8];         /**< start offsets of dynamic range in samples */
    unsigned int b_compr_present;                   /**< boolean indicating the presence of heavy compression (RF mode) */
    int          compr;                             /**< heavy compression values valid a the complete frame */
    unsigned int b_drc_presentation_mode_present;   /**< boolean indicating the presence of the DRC presentation mode extension:*/
    unsigned int drc_presentation_mode;             /**< ETSI TS 101 154 Annex C5 */

    /* DMX MPEG */
    unsigned int b_mpeg_dmx_present;                /**< boolean indicating the presence of DMX coefficent in MPEG style */
    unsigned int mpeg_dmx_coef;                     /**< index; 2 valid bits */
    /* DVB dolbySurroundMode */
    unsigned int b_dolby_surround_present;          /**< boolean indicating the presence of dolby surround mode indication */
    unsigned int dolby_surround_mode;               /**< 2 valid bits: see ETSI TS 101154 Annex C5  */
    /* DMX DVB */
    unsigned int b_dvb_dmx_center_present;          /**< boolean indicating the presence of center DMX coefficent in DVB style */
    unsigned int dvb_dmx_coef_center;               /**< index; 3 valid bits: see ETSI TS 101 154 Annex C5 */
    unsigned int b_dvb_dmx_surround_present;        /**< boolean indicating the presence of surround DMX coefficent in DVB style */
    unsigned int dvb_dmx_coef_surround;             /**< index; 3 valid bits: see ETSI TS 101 154 Annex C5 */

} AUDIO_AAC_METADATA;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;

    char dap_ena;

    /* dap_cpdp_init_info */
    unsigned int blocks;
    unsigned int license_size;
    unsigned char license_data[20];
    unsigned long manufacturer_id;
    int mi_process_disable;
    int virtual_bass_process_enable;
    int mode;
    unsigned int process_bit;


    unsigned int dap_out_mode;
    char display;
    char undisplay;
    int special_testcase;

    /*dap in-configuration info */
    //char in_configuration[60];
    long volume_leveler_weight;
    long intelligent_equalizer_weight;
    long dialog_enhancer_speech_confidence;
    long surround_compressor_music_confidence;
    int cmixlev_q14;
    int surmixlev_q14;
    //char *dump_metadata;
    //char *dump_display;

    int audio_optimizer_enable;

    /* audio-optimizer-bands */
    unsigned int opt_nb_bands;
    unsigned int opt_band_freq[20];
    int opt_gains[8][20];

    int bass_enhancer_enable;
    int bass_enhancer_boost;
    int bass_enhancer_cutoff_frequency;
    int bass_enhancer_width;

    unsigned int calibration_boost;

    unsigned int dialog_enhancer_amount;
    unsigned int dialog_enhancer_enable;
    unsigned int dialog_enhancer_ducking;

    int graphic_equalizer_enable;

    /* graphic_equalizer_bands */
    unsigned int graphic_eq_nb_bands;
    unsigned int graphic_eq_freq[20];
    int graphic_eq_gains[20];


    unsigned int surround_decoder_enable;

    unsigned int surround_boost;

    unsigned int regulator_timbre_preservation;
    unsigned int regulator_speaker_dist_enable;
    unsigned int regulator_tuning;
    /* regulator_tuning */
    unsigned int regulator_tuning_center[20];
    int regulator_tuning_low_threshold[20];
    int regulator_tuning_high_threshold[20];
    int regulator_tuning_isolates[20];
    unsigned int regulator_tuning_bands;

    unsigned int regulator_relaxation_amount;
    unsigned int regulator_enable;
    unsigned int regulator_overdrive;

    unsigned int output_mode;

    unsigned int ieq_amount;
    unsigned int ieq_enable;

    unsigned int ieq_bands;
    /* --ieq-bands */
    unsigned int ieq_bands_size;
    unsigned int ieq_bands_freqs[20];
    int ieq_bands_targets[20];


    unsigned int mi_dialog_enhancer_steering_enable;
    unsigned int mi_dv_leveler_steering_enable;
    unsigned int mi_ieq_steering_enable;
    unsigned int mi_surround_compressor_steering_enable;

    int pregain;
    int postgain;
    int system_gain;

    unsigned int volmax_boost;
    unsigned int volume_modeler_calibration;
    unsigned int volume_modeler_enable;
    int volume_leveler_in_target;
    int volume_leveler_out_target;
    unsigned int volume_leveler_enable;
    unsigned int volume_leveler_amount;

    int virtual_bass_mode;
    unsigned int virtual_bass_overall_gain;
    unsigned int virtual_bass_slope_gain;
    unsigned int virtual_bass_src_freqs;
    unsigned int virtual_bass_mix_freqs;
    //unsigned int virtual_bass_subgains;
    /* --virtual-bass-src-freqs */
    unsigned int virtual_bass_low_src_freq;
    unsigned int virtual_bass_high_src_freq;
    /* --virtual-bass-mix-freqs */
    unsigned int virtual_bass_subgains_size;
    int virtual_bass_subgains[3];
    /* --virtual-bass-mix-freqs */
    unsigned int virtual_bass_mix_low_freq;
    unsigned int virtual_bass_mix_high_freq;

    int virtualizer_headphone_reverb_gain;
    int virtualizer_speaker_start_freq;
    int virtualizer_speaker_angle;

    /* status of param changed  */
    unsigned int blocks_changed;

    unsigned int in_configuration_changed;
    // dap_init_info_changed;
    unsigned int manufacturer_id_changed;
    unsigned int license_size_changed;
    unsigned int license_data_changed;
    unsigned int mi_process_disable_changed;
    unsigned int virtual_bass_process_enable_changed;
    unsigned int mode_changed;

    unsigned int dap_out_mode_changed;
    unsigned int pregain_changed;
    unsigned int postgain_changed;
    unsigned int system_gain_changed;
    unsigned int calibration_boost_changed;
    unsigned int surround_decoder_enable_changed;
    unsigned int dialog_enhancer_enable_changed;
    unsigned int dialog_enhancer_amount_changed;
    unsigned int dialog_enhancer_ducking_changed;
    unsigned int volmax_boost_changed;
    unsigned int surround_boost_changed;
    unsigned int volume_leveler_enable_changed;
    unsigned int volume_leveler_amount_changed;
    unsigned int volume_leveler_in_target_changed;
    unsigned int volume_leveler_out_target_changed;
    unsigned int volume_modeler_enable_changed;
    unsigned int volume_modeler_calibration_changed;
    unsigned int ieq_enable_changed;
    unsigned int ieq_amount_changed;
    unsigned int ieq_bands_changed;
    unsigned int mi_ieq_steering_enable_changed;
    unsigned int mi_dv_leveler_steering_enable_changed;
    unsigned int mi_dialog_enhancer_steering_enable_changed;
    unsigned int mi_surround_compressor_steering_enable_changed;
    unsigned int regulator_timbre_preservation_changed;
    unsigned int regulator_overdrive_changed;
    unsigned int regulator_relaxation_amount_changed;
    unsigned int regulator_enable_changed;
    unsigned int regulator_speaker_dist_enable_changed;
    unsigned int regulator_tuning_changed;
    unsigned int virtualizer_headphone_reverb_gain_changed;
    unsigned int virtualizer_speaker_angle_changed;
    unsigned int virtualizer_speaker_start_freq_changed;
    unsigned int graphic_eq_enable_changed;
    unsigned int graphic_eq_bands_changed;
    unsigned int bass_enhancer_enable_changed;
    unsigned int bass_enhancer_boost_changed;
    unsigned int bass_enhancer_cutoff_frequency_changed;
    unsigned int bass_enhancer_width_changed;
    unsigned int audio_optimizer_enable_changed;
    unsigned int audio_optimizer_bands_changed;
    unsigned int virtual_bass_mode_changed;
    unsigned int virtual_bass_src_freqs_changed;
    unsigned int virtual_bass_overall_gain_changed;
    unsigned int virtual_bass_slope_gain_changed;
    unsigned int virtual_bass_subgains_changed;
    unsigned int virtual_bass_mix_freqs_changed;

} DAP_SELFTEST_PARAM;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;

    unsigned int num_bands;
    int band_centers[20];
    int band_gains[20];
    int band_excitation[20];
} DAP_DISPLAY_INFO;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;

    int  file;                                 /**< file=2: output file -> "metadata.txt"; else: output file -> "mi_info.txt" */
    long volume_leveler_weight;                /**< weighting for volume leveler in range [0,1], Q31 */
    long intelligent_equalizer_weight;         /**< weighting for intelligent_equalizer in range [0,1],Q31 */
    long dialog_enhancer_speech_confidence;    /**< speech confidence value for dialog_enhancer in range[0,1],Q31 */
    long surround_compressor_music_confidence; /**< music confidence value for surround_compressor in range[0,1],Q31 */
} DAP_DUMP_METADATA_INFO;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    long                        EOSID;  /* ID associated with command */
} AUDIO_DEC_EOS;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               PTSH;
    unsigned long               PTSL;
    unsigned long               AD_fade_byte;
    unsigned long               AD_pan_byte;
    long                        gain_byte_center;
    long                        gain_byte_front;
    long                        gain_byte_surround;
} AUDIO_DEC_AD_DESCRIPTOR;

/*! System process related
 */
enum PAYLOAD_TYPE {
    AUDIO_PCM,
    AUDIO_BS,
    AUDIO_NONE,
};

enum COMMAND_TYPE {
    SYS_INIT,
    SYS_FLUSH,
    SYS_SELECT_SUBSTREAM,
    SYS_FLUSH_FINISH,
    SYS_EOS,
};

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    long listSize;
    long pRingBufferHeaderList[8];
} SYS_PROCESS_INIT_RING_HEADER;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    long payload_type;
    long payload_size;
    long pcm_channels;
    long pcm_samplrate;
    long n_bytes_consumed;// update rp or wp
} SYS_PROCESS_PAYLOAD_HEADER;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    long cmd_Type;
    long cmd_Data;
} SYS_PROCESS_COMMAND_INFO;

/* System process related end */

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    int mixer_samples;
    int mixer_debug;
    int mixing_mode;
    int user_pref;
    int b_enable_limiter;
    int b_dmx;
    int frame_size;
    int ramp_pause_mode;
    int chanmod_primary;
    int chanmod_secondary;
    int chanmod_system;
    int chanmod_out;
    int pcm_primary_lfe;
    int pcm_secondary_lfe;
    int pcm_system_lfe;
    int mmd_type;
    int fade_change_ena;
    int fade_change_ena_secondary;
    int fade_change_ena_system;
    int primary_target_attenuation;
    int primary_duration_in_ms;
    int primary_type;
    int primary_sampleRate;
    int secondary_target_attenuation;
    int secondary_duration_in_ms;
    int secondary_type;
    int secondary_sampleRate;
    int system_target_attenuation;
    int system_duration_in_ms;
    int system_type;
    int system_sampleRate;
    unsigned int primary_present;
    unsigned int secondary_present;
    unsigned int system_present;
    int primary_sample_left;
    int secondary_sample_left;
    int system_sample_left;
    AUDIO_DEC_AD_DESCRIPTOR pes_mmd;
    AUDIO_DDP_MIXING_METADATA ddp_mmd;
} AUDIO_MS12_MIXER_CMD;

/**
    \brief Send a general purpose context which is associated a wPtr. It might be "here!", "run to here!" or something like that.
    \param: wPtr
*/
typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    long                        context;
} AUDIO_DEC_CONTEXT;

enum DEC_MODE {
    AUDIO_DECODE,
    AUDIO_PARSING       // purpose: (1) check bit stream is valid or not. (2) for SPDIF pass through.
};

/**
    \brief Decode and/or parse a bitstream by the instruction of parameter AUDIO_DEC_DECODE.
    \param AUDIO_DEC_DECODE.
    See more detailed comments in AUDIO_DEC_DECODE
*/

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               peakReference;
    unsigned long               peakTarget;
    unsigned long               avgReference;
    unsigned long               avgTarget;
}   AUDIO_DEC_WMAPRO_DRC ;


typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               nameLen;
    unsigned long               dataLen;
}   AUDIO_DEC_WMAPRO_DWNMIX_MTRX ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;
    unsigned long               RelativePTSH;
    unsigned long               RelativePTSL;
    unsigned long               PTSDurationH;
    unsigned long               PTSDurationL;
    enum                        DEC_MODE    decodeMode;

}   AUDIO_DEC_DECODE ;


/**
 *  \brief Tell decoder to look at the system PTS (SPTS not RPTS) in shared reference clock.
 *  if (SPTS of current picture + deltaPTS < current SPTS in ref clock) skip decoding this picture.
 *  This is used to catch the display quickly. deltaPTS is the estimated latency between decoder and
 *  AOUT with a margin. In other words, it is the DTS.
 *  \param:
 */

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr ;
    unsigned long               OffsetPTSH;
    unsigned long               OffsetPTSL;
}   AUDIO_DEC_PTS_SKIP;



typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long               wPtr ;
}   AUDIO_DEC_BS_DISCONTINUITY ;


typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header ;
    unsigned long wPtr ;
}   AUDIO_DEC_RESYNC ;

//  We should discuss about the message ringbuffer, we could use it to prepare audio header information.

/**
 * \defgroup   Sub-picture Decoder in-band command definitions.
 * \@{
 */

/** Audio Mixer Inband APIs */
/**
      This spec defines a set of API to send command via cmd fifo.
        Inband command is passed through inband cmd fifo. Each command
        is contained in AUDIO_INBAND_CMD_PKT. Once the system software
        push a AUDIO_INBAND_CMD_PKT in the cmd fifo, it should then update
        the write pointer. System software should take the responsibility
        to keep the cmd fifo from overflow.
    ==========================================================================================
    Note (Please read):

    Audio Mixer is filter with 2 input pins and one output pin. Its inputs are connected to 2 decoders
    and its output is connected to a VOUT or a Audio Encoder.

    Audio mixer operation is very simple, it does not have run, stop, or pause. It only have 2 APIs:
    SET_MIXER_RPTS and BLEND.

    SET_MIXER_RPTS sets mixer relative PTS. All the future BLEND command refer to this RPTS.

    BLEND is the only command that causes actions: blend 1 or 2 stream(s) and/or background
    and send the output Audio to output pin. Mixer RPTS is counted with mixer output.

    The output of Blending will be AGC controlled.

    BlendMode selects A only, B only and AB blend.
    For A only mode, only stream A buffer is sent out.
    For B only mode, only stream B  buffer is sent out.
    For AB only mode, both stream A and stream B buffers are sent out and AGC conttrolled.

    Implementation notes for AB mode:

    ==========================================================================================
*/

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               PTSH;
    unsigned long               PTSL;
} AUDIO_AO_MIXER_RPTS ;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               PTSH;
    unsigned long               PTSL;
} AUDIO_DV_MIXER_RPTS ;

//  Since it will be fade out to 0 and fade in to 255, so the alpha is not assigned.
//  If SetFocus is considered, only 1 input pin is selected.

typedef struct
{
    long    bitWidth;
    long    samplingRate;
}   AUDIO_MIXER_PCM_FORMAT;

/*  Since DV mixer is always an off-line application, we do not need to set relative PTS first.

    For example, we have 4 audio sources to be mixed.

    1.  AVI or MPEG demuxed audio PCM sample, demuxer will stamp the PTS according to GPTS.
    2.  Another AVI or MPEG demuxed audio PCM sample, demuxer will stamp the PTS according to GPTS.
    3.  Microphone in from AI, the PTS stamp is given by AI according to GPTS.
    4.  A WAVE file which is decoded by the LPCM decoder, demuxer will stamp the PTS according to GPTS.

    However, the time stamps are meaningless, because user will replace them here and there again and again.
    After some trials, user will decide the location of the three sources. Microphone is a real-time source
    which be inputed at the run time.

    Since it is very lousy to re-stamp all the PTS for the 3 non-real-time resources, the muxer should only
    put the correct data in the ring buffer with a correct wptr. Since the whole process may be more than 1
    hour, garbage should not be put into ring buffer at all.

    Therefore, PTS is useless for begin / stop marking.
*/

typedef struct

{

    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long   PTSDurationH;           // Duration in PTS
    unsigned long   PTSDuration;            // Duration in PTS
    long    pinID[4];               // for at most 4 inputs, 1 = valid, 0 = invalid

    long    alphaA[4];              // alpha for 4 inputs to begin with
    long    alphaB[4];              // alpha for 4 inputs to stop with
    long    channelValid[4];        // LSB 8 bits stand for 0~7 channels
    long    frameSize;              // internal frame size, for DVMixer editing, default = 256.
    AUDIO_MIXER_PCM_FORMAT  inputFormat[4]; // in case of needing converting
}   AUDIO_DV_MIXER_BLEND;



/*
    If the mixer is configure to select mode, there will be 2 cases:

    If SetFocus is considered, only 1 input pin is selected.
    If SwitchAgent is considered, mixer will not find the decoder is changed at all.

    If the mixer is configure to mixer mode:

    Two sources may have different PTS system, therefore, we need relative PTS.

    */

typedef struct
{

    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long   PTSDurationH;           // Duration in PTS
    unsigned long   PTSDuration;            // Duration in PTS
    long    pinID[4];               // for at most 4 inputs, 1 = valid, 0 = invalid

    long    alphaA[4];              // alpha for 4 inputs to begin with
    long    alphaB[4];              // alpha for 4 inputs to stop with
    long    channelValid[4];        // LSB 8 bits stand for 0~7 channels
    long    frameSize;              // internal frame size, for DVMixer editing, default = 256.
    AUDIO_MIXER_PCM_FORMAT  inputFormat[4]; // in case of needing converting
}   AUDIO_AO_MIXER_BLAND;

typedef struct{
      unsigned int vorbisPacketSize;
//    unsigned char vorbisPacketState;
      unsigned int vorbisPacketState;
}     AUDIO_VORBIS_PACKET_INFO;

typedef struct{
      AUDIO_INBAND_CMD_PKT_HEADER header;
      unsigned int listSize;
}     AUDIO_VORBIS_PACKETLIST_SIZE;

typedef struct{
//    AUDIO_VORBIS_PACKETLIST_SIZE header;
      AUDIO_INBAND_CMD_PKT_HEADER header;
      AUDIO_VORBIS_PACKET_INFO  info[255];
}     AUDIO_VORBIS_PACKET_LIST_INFO;


// for use dwnstrmInBandQ to deliver info
typedef enum
{

    AUDIO_INBAND_CMD_PRIVATE_INVALID    = 0,
/*
typedef struct
{
    ENUM_AUDIO_INFO_TYPE    infoType;
    AUDIO_PCM_FORMAT        pcmFormat;
    long                    start_addr;
    int                     max_bit_rate;
} AUDIO_INFO_PCM_FORMAT;

AUDIO_PCM_FORMAT is defined in common/IPC/generate/include/system/AudioRPCBaseDS_data.h
struct AUDIO_PCM_FORMAT {
    int chnum;
    int samplebit;
    int samplerate;
    u_int dynamicRange;
    u_char emphasis;
    u_char mute;
};
*/

    AUDIO_INBAND_CMD_PRIVATE_PCM_FMT    = 1,

/*
typedef struct
{
    ENUM_AUDIO_INFO_TYPE    infoType;
    char channel_index[8];
    long start_addr;
    char dual_mono_flag;
} AUDIO_INFO_CHANNEL_INDEX;

typedef enum
{
    ENUM_AUDIO_NULL_CHANNEL_INDEX = 0,

    ENUM_AUDIO_LEFT_FRONT_INDEX = 1,            // L
    ENUM_AUDIO_RIGHT_FRONT_INDEX = 2,           // R
    ENUM_AUDIO_CENTER_FRONT_INDEX = 5,          // C
    ENUM_AUDIO_LFE_INDEX = 6,                   // LFE
    ENUM_AUDIO_LEFT_SURROUND_REAR_INDEX = 3,    // Ls or Lsr
    ENUM_AUDIO_RIGHT_SURROUND_REAR_INDEX = 4,   // Rs or Rsr
    ENUM_AUDIO_LEFT_OUTSIDE_FRONT_INDEX = 7,    // Lss
    ENUM_AUDIO_RIGHT_OUTSIDE_FRONT_INDEX = 8,   // Rss

} ENUM_AUDIO_CHANNEL_OUT_INDEX;

*/

    AUDIO_INBAND_CMD_PRIVATE_CH_IDX     = 2
} ENUM_AUDIO_INBAND_PRIVATE_INFO;


//following this packet, has private_size number of bytes is the privateinfo to deliver out
typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    ENUM_AUDIO_INBAND_PRIVATE_INFO infoType;
    unsigned int infoSize;
} AUDIO_INBAND_PRIVATE_INFO ;

/*************** For ARM MESSAGE CONTROL ***************/
enum ENUM_MESSAGE_TYPE {
    ENUM_UNKNOWN_MESSAGE = 0,
    ENUM_NODE_OPEN_MESSAGE = 1,
    ENUM_NODE_CLOSE_MESSAGE = 2,
    ENUM_AOUT_EOS_MESSAGE = 3,
    ENUM_MESSAGE_MAX = 4,
};
typedef enum ENUM_MESSAGE_TYPE ENUM_MESSAGE_TYPE;

enum ENUM_NODE_TYPE {
    ENUM_NODE_SRC = 0,
    ENUM_NODE_DUMP = 1,
    ENUM_NODE_AC3_DEC = 2,
    ENUM_NODE_AC4_DEC = 3,
    ENUM_NODE_MPEGH_DEC = 4,
    ENUM_NODE_DDP_ENC = 5,
    ENUM_NODE_AAC_DEC = 6,
    ENUM_NODE_DTS_DEC = 7,
    ENUM_NODE_MAT_DEC = 8,
    ENUM_NODE_OPUS_DEC = 9,
    ENUM_NODE_MESSAGE_MANAGER = 10,
};
typedef enum ENUM_NODE_TYPE ENUM_NODE_TYPE;

struct SYSTEM_MESSAGE_INFO {
    ENUM_MESSAGE_TYPE m_type;
    ENUM_NODE_TYPE type;
    long instanceID;
    long data[29];
};
typedef struct SYSTEM_MESSAGE_INFO SYSTEM_MESSAGE_INFO;

struct SYSTEM_MESSAGE_RES {
    long instanceID;
    long packetBufHeader[2];
    long data[29];
};
typedef struct SYSTEM_MESSAGE_RES SYSTEM_MESSAGE_RES;
/*****************************************************/

/* ============================================  For IIDK  ================================================*/

#define MS_DOWNMIX_OUT_IDX          0
#define MS_VIRTUALIZER_OUT_IDX      1
#define MS_DAP_SPEAKER_OUT_IDX      2
#define MS_DAP_HEADPHONE_OUT_IDX    3
#define MS_MAX_NUM_PCM_OUTPUTS      4

#define MS_PROGRAM_UUID_LEN_BYTES  16

#if 1//def MS12_AC4_SUPPORT
#define MS_MIN_AC4_DE_GAIN      0                 /**< Minimum value for AC4 Dialogue enhancement gain   */
#define MS_MAX_AC4_DE_GAIN      12                /**< Maximum value for AC4 Dialogue enhancement gain   */
#define MS_MIN_AC4_ASSOC_TYPE   1                 /**< Minimum associated content type preference index  */
#define MS_MAX_AC4_ASSOC_TYPE   3                 /**< Maximum associated content type preference index  */
#define MS_AC4_NUM_LANG_CHAR    3                 /**< Number of characters used for language selection. */
#define MS_AC4_LANG_MAX_STRLEN  (MS_AC4_NUM_LANG_CHAR+1)
#define AC4_MODE_SINGLE_STREAM_SINGLE_DECODE               0
#define AC4_MODE_SINGLE_STREAM_DUAL_DECODE_SINGLE_INSTANCE 1
#define AC4_MODE_SINGLE_STREAM_DUAL_DECODE_DUAL_INSTANCE   2
#define AC4_MODE_DUAL_STREAM_DUAL_DECODE                   3
#define MS_MIN_AC4_MODE         AC4_MODE_SINGLE_STREAM_SINGLE_DECODE
#define MS_MAX_AC4_MODE         AC4_MODE_DUAL_STREAM_DUAL_DECODE
#define MS_MIN_AC4_PRES_IDX     -1                       /**< Minimum value for AC4 presentation index */
#define MS_MAX_AC4_PRES_IDX      63                      /**< Maximum value for AC4 presentation index */
#define MS_MIN_AC4_PROG_ID_TYPE  0                       /**< Minimum value for AC4 program id type */
#define MS_MAX_AC4_PROG_ID_TYPE  2                       /**< Maximum value for AC4 program id type */
#define MS_MIN_AC4_SHORT_PROG_ID       0                 /**< Minimum value for AC4 short program id */
#define MS_MAX_AC4_SHORT_PROG_ID   65536                 /**< Maximum value for AC4 short program id */
#endif

#define DAP_MAX_BANDS          (20)
#define DAP_IEQ_MAX_BANDS      DAP_MAX_BANDS
#define DAP_GEQ_MAX_BANDS      DAP_MAX_BANDS
#define DAP_REG_MAX_BANDS      DAP_MAX_BANDS
#define DAP_OPT_MAX_BANDS      DAP_MAX_BANDS
#define DAP_MAX_CHANNELS       (MS_MAX_MAX_CHANNEL)

#define MS_MIN_MAX_CHANNEL      6                 /**< Minimum value for max. number of channels        */
#define MS_MAX_MAX_CHANNEL      8                 /**< Maximum value for max. number of channels        */


#define INPUT_IM            (0x1 << 7)
#define INPUT_IM2           (0x1 << 8)
#define INPUT_IA            (0x1 << 9)
#define INPUT_TYPE_1PID     (0x1 << 10)
#define INPUT_TYPE_AD       (0x1 << 11)
#define INPUT_TYPE_DUAL     (0x1 << 12)


typedef enum ms_bs_output_mode_t
{
    MS_BS_OUTPUT_MODE_NONE,
    MS_BS_OUTPUT_MODE_DD,
    MS_BS_OUTPUT_MODE_DDP,
    MS_BS_OUTPUT_MODE_SIM_DDP_DD
} ms_bs_output_mode_t;

typedef enum ms_dap_mode_t
{
    MS_DAP_NO_PROC = 0,
    MS_DAP_CONTENT_PROC = 1,
    MS_DAP_DEVICE_PROC = 2,
    MS_DAP_DEVICE_CONTENT_PROC = MS_DAP_DEVICE_PROC | MS_DAP_CONTENT_PROC,
    MS_DAP_SI_PROC = 4,
} ms_dap_mode_t;

/*! Enumeration of possible input types beeing processed by the multistream decoder */
typedef enum MS_INPUT_TYPE
{
    UNKNOWN_MINIAP,
    DOLBY_DIGITAL_PLUS,
    HE_AAC,
    AC4,
    EXTERNAL_PCM
} MS_INPUT_TYPE;

/**
 * @brief See dap_cpdp.h in the DAPv2 CIDK for a detailed description of the parameter.
 */
typedef struct dap_params_s
{
    int drc_type;
    int dmx_type;
    int speaker_lfe;
    int pregain;
    int postgain;
    int systemgain;
    int surround_decoder_enable;
    int virtualizer_enable;
    int headphone_reverb;
    int speaker_angle;
    int speaker_start;
    int surround_boost;
    int mi_ieq_enable;
    int mi_dv_enable;
    int mi_de_enable;
    int mi_surround_enable;

    int calibration_boost;

    int leveler_amount;
    int leveler_input;
    int leveler_output;
    int leveler_enable;
    int leveler_ignore_il;

    int modeler_enable;
    int modeler_calibration;

    int ieq_enable;
    int ieq_amount;
    int ieq_nb_bands;
    int a_ieq_band_center[DAP_IEQ_MAX_BANDS];
    int a_ieq_band_target[DAP_IEQ_MAX_BANDS];

    int de_enable;
    int de_amount;
    int de_ducking;

    int volmax_boost;

    int eq_enable;
    int eq_nb_bands;
    int a_geq_band_center[DAP_GEQ_MAX_BANDS];
    int a_geq_band_target[DAP_GEQ_MAX_BANDS];

    int optimizer_enable;
    int optimizer_nb_bands;
    int a_opt_band_center_freq[DAP_OPT_MAX_BANDS];
    int a_opt_band_gain[DAP_MAX_CHANNELS][DAP_OPT_MAX_BANDS];

    int bass_enable;
    int bass_boost;
    int bass_cutoff;
    int bass_width;

    int reg_nb_bands;
    int a_reg_band_center[DAP_REG_MAX_BANDS];
    int a_reg_low_thresholds[DAP_REG_MAX_BANDS];
    int a_reg_high_thresholds[DAP_REG_MAX_BANDS];
    int a_reg_isolated_bands[DAP_REG_MAX_BANDS];

    int regulator_overdrive;
    int regulator_timbre;
    int regulator_distortion;
    int regulator_mode;
    int regulator_enable;

    int vb_mode;
    int vb_low_src_freq;
    int vb_high_src_freq;
    int vb_overall_gain;
    int vb_slope_gain;
    int vb_subgain[3];
    int vb_mix_low_freq;
    int vb_mix_high_freq;
} dap_params_t;


typedef struct CHANNEL_CONFIG_S
{
  int acmod;         /*!< Audio coding mode as defined for Dolby Digital.
                               The audio coding mode can be ONEPLUSONE=0, MONO=1, STEREO=2, or 3_2=7. */
  int b_lfe_present; /*!< Flag indicating presence of the low frequency enhancement channel. */
  int dsurmod;       /*!< Indicates if the signal is dolby surround encoded (only possible for stereo signals) */
} CHANNEL_CONFIG;

/**
 * @brief Mixer fade event parameter.
 */
typedef struct mix_fade_s
{
    int target_attenuation;  /**< Target attenuation at end of ramp in dB (range: -96...0). */
    int duration_in_ms;      /**< Duration of ramp in milliseconds (range: 0...60000). */
    int type;                /**< Shape of the ramp (0: linear, 1: in cube, 2: out cube). */
} mix_fade_t;

/*! Struct defining the current use case, not all permutations are allowed */
typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;

    MS_INPUT_TYPE               input_type; /*!< Either HE-AAC, Dolby Digital Plus or external PCM */
    int                   b_low_complexity; /*!< Flag indicating if the Processing Graph is initialized in low complexity mode */
    int                       b_dual_input; /*!< Flag indicating if two input streams are present (n/a for external PCM) */
    int                        b_dual_main; /*!< Flag indicating if two main input streams are present (DDP only).
                                                 b_dual_main is a special case of b_dual_input. */
    int                    b_file_playback; /*!< Flag indicating file playback (HE-AAC with single input only) */
    int                    b_restricted_ad; /*!< Flag indicating that the associated instance is restricted to 2 channels (HE-AAC only) */
    int                         b_mainonly; /*!< Flag indicating that the UDC shall handle only the main program */
    int                    b_system_sounds; /*!< Flag indicating that system sounds are present */
    int                       b_app_sounds; /*!< Flag indicating that application sounds are present */
    int                        b_eval_mode; /*!< Flag indicating that evaluation mode is enabled */
    ms_bs_output_mode_t     bs_output_mode; /*!< Either DD, DD+ or both */
    ms_dap_mode_t            dap_init_mode; /*!< DAP configuration:
                                                  - 0: no DAP
                                                  - 1: content processing only
                                                  - 2: device processing only
                                                  - 3: both with two DAP instances
                                                  - 4: both with single instance DAP processing */
    int                    b_dap_vb_enable; /*!< DAP virtual bass configuration */
    int                           ac4_mode; /**< AC4 decoding mode:
                                                  - -1: not define MS12_AC4_SUPPORT
                                                  - 0: single stream, single decode
                                                  - 1: single stream, dual decode, single instance (mixing inside decoder)
                                                  - 2: single stream, dual decode, dual instance (mixing outside decoder)
                                                  - 3: dual stream, dual decode, dual instance (mixing outside decoder) */
} IIDK_USE_CASE_INFO;

typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;

    /* Input and output filenames */
    //const char *input_filename[MS_MAX_NUM_INPUTS];               /**< Names of the input file(s) - main, associated, sys sounds, app sounds */
    //const char *pcm_output_filename[MS_MAX_NUM_PCM_OUTPUTS];     /**< Names of the PCM output files - downmix, multichannel, dap speaker and headphone  */
    //const char *bitstream_output_filename[MS_MAX_NUM_BS_OUTPUTS];/**< Name of the DD and DD+ bitstream output file. */
    //const char *pcmr_output_filename;                            /**< Name of the PCMR output text file. */
    int         pcm_out_chans[MS_MAX_NUM_PCM_OUTPUTS];           /**< Number of channels of the PCM output files */

    int     verbose_mode;                 /**< Determines the amout of information that is written to the command line */
    int         wav_bit_depth;                /**< Output WAV file bit-depth */
    int         max_num_channels;             /**< Determines the maximum number of channels in the signal processing chain */
    int         enc_chmod_locking_mode;       /**< Determines whether the encoded channel mode is driven by the input or locked. */
    int         b_high_risc_precision;        /**< Determines whether LFRACT or SFRACT data type is used for PCM representation */

    /* PCM parameters */
    int     extpcm_compressor_profile;    /**< The compressor profile for external PCM reencoding */

    /* HE-AAC parameters */
    int heaac_allow_partial_feed;        /**< Flag enabling feeding of less input data than necessary to complete an output frame */

    /* DAP parameters */
    int dap_output_mode;                 /**< 2-Bit Bitmask to indicate which of both supported DAP outputs is active */

    int         dbg_output_mask;              /**< Used to activate different debug outputs */
} IIDK_INIT_PARAMS_INFO;

/** This struct holds all parameters that may change during runtime without re-initialization */
typedef struct
{
    AUDIO_INBAND_CMD_PKT_HEADER header;
    unsigned long               wPtr;

    int module_update_flag;
    int pts_90k;

    /* Parameters common to DD+, external PCM and HE-AAC */
    int drc_cut_fac_mc;           /**< Determines the percentage of application of DRC
                                         attenuation factors for the multichannel channel output.    */
    int drc_boost_fac_mc;         /**< Determines the percentage of application of DRC
                                         boost factors for the multichannel channel output.          */
    int drc_cut_fac_2ch;          /**< Determines the percentage of application of DRC
                                         attenuation factors for the 2 channel output.               */
    int drc_boost_fac_2ch;        /**< Determines the percentage of application of DRC
                                         boost factors for the 2 channel output.                     */
    int downmix_type;             /**< Indicates which downmix type is used (LtRt,LoRo,ARIB)       */
    int drc_mode;                 /**< Indicates whether to operate in RF or Line mode             */
    int dual_mono;                /**< Dual Mono reproduction mode, (both, left, right)            */
    int cmix_lev;                 /**< Index in center mix level table (-3dB,-4.5dB,-6dB)          */
    int smix_lev;                 /**< Index in surround mix level table (-3dB,-4.5dB,-6dB)        */
    int multichannel_enable;      /**< Indicates if the signal in the multichannel output is valid */
    int associated_audio_mixing;  /**< Enables/Disables mixing in dual decoding use cases          */
    int user_balance_adjustment;  /**< User defined balance between main and associated signal.
                                         Value range is between -32 and +32 (in dB),
                                         -32dB indicates main only (mute associated)
                                         +32dB indicates associated only (mute main)                 */
    int b_sys_app_sound_mixing;   /**< Enables/Disables mixing of systen and application sounds    */

    mix_fade_t input_mix_input1;      /**< Input mixer input1 gain/fade event.                         */
    mix_fade_t input_mix_input2;      /**< Input mixer input2 gain/fade event.                         */
    mix_fade_t syssound_mix_input1;   /**< System/application sound mixer input1 gain/fade event.      */
    mix_fade_t syssound_mix_input2;   /**< System/application sound mixer input2 gain/fade event.      */
    mix_fade_t syssound_mix_input3;   /**< System/application sound mixer input3 gain/fade event.      */

    int input_mix_input1_present;     /**< Input mixer input1 present in runtime.                      */
    int input_mix_input2_present;     /**< Input mixer input2 present in runtime.                      */
    int syssound_mix_input1_present;  /**< System/application sound mixer input1 present in runtime.   */
    int syssound_mix_input2_present;  /**< System/application sound mixer input2 present in runtime.   */
    int syssound_mix_input3_present;  /**< System/application sound mixer input3 present in runtime.   */

    /* External PCM parameters */
    int                       extpcm_num_in_samples;          /**< Number of input samples to process  */
    CHANNEL_CONFIG            extpcm_in_channel_config;       /**< Input channel configuration         */

    /* System Sounds PCM parameters */
    int                       sys_sounds_num_in_samples;      /**< Number of input samples to process  */
    CHANNEL_CONFIG            sys_sounds_channel_config;      /**< Input channel configuration         */

    /* Application Sounds PCM parameters */
    int                       app_sounds_num_in_samples;      /**< Number of input samples to process  */
    CHANNEL_CONFIG            app_sounds_channel_config;      /**< Input channel configuration         */

    /* HE-AAC parameters */
    int heaac_mixing_mode;          /**< Blocking or non-blocking mixing, i.e. does main wait for associated */
    int heaac_default_dialnorm;     /**< Default dialnorm (dB/4) that is used until a valid dialnorm is found in the bitstream */
    int heaac_transport_format;     /**< Specifies the HE-AAC transport format
                                           (can increase robustness compared to auto-detect)   */

    /* DDPlus parameters */
    int ddplus_associated_substream; /**< ID of the substream which should be mixed with the main program */
    int ddplus_outlfe;               /**< Determines if LFE will be present in the DD+ decoded signal  */
    int ddplus_outmode;              /**< Determines which acmod will be set in the DD+ decoded signal */

    dap_params_t  dap_parameter;         /**< Contains all configurable DAP parameter */
    int           b_mc_5_1_dmx;          /**< Determines if 7.1 signals shall be dowmixed to 5.1 for the multichannel PCM output */

    /* AC4 parameters */
    //char          ac4_1st_pref_lang[MS_AC4_LANG_MAX_STRLEN]; /**< String containing the preferred language selection */
    int           ac4_1st_pref_lang;
    //char          ac4_2nd_pref_lang[MS_AC4_LANG_MAX_STRLEN]; /**< String containing the preferred language selection */
    int           ac4_2nd_pref_lang;
    int           ac4_associated_type;                       /**< Indication of the preferred associated content type */
    int           b_ac4_pref_assoc_type_over_lang;           /**< Preferred filter priority (selection of associated content type over language or vice versa) */
    int           ac4_de_gain;                               /**< Indicates gain that will be applied to dialog enhancement. Range: 0 to 12 dB (in 1 dB steps) */
    int           ac4_pres_index[2];                         /**< Primary and secondary Presentation index to be decoded. Overrides presentation selection by language and assoc. type. */
    int           ac4_prog_id_type;                                           /**< Determines whether the program_identifier is present or not and whether it's the short or the long version. */
    //char          ac4_program_identifier_string[2*MS_PROGRAM_UUID_LEN_BYTES]; /**< Either the short program identifier (16 bit) or the UUID (128 bit) as a string copied from the command line */
    int           ac4_program_identifier_string;

    /* parameter update status variables */
    int    frame;                    /**< Current Frame number (necessary to apply runtime changes) */
    //DLB_TIMESTAMP  next_update;          /**< Indicates the next frame when parameters shall be updated */
    int main1_dummy;
    int main2_dummy;
} IIDK_RUNTIME_PARAMS_INFO;

typedef struct
{
    SYS_PROCESS_COMMAND_INFO cmd_info;
    DDP_ILD_METADATA_INFO ddp_ild_meta_info;
    DDP_EVO_METADATA_INFO ddp_evo_meta_info;
    AUDIO_DDP_METADATA ddp_md;
    AC4_METADATA_INFO  ac4_md;
    DDPENC_IIDK_INIT_PARAMS iidk_para;
} DDPENC_CMD_DATA_META;

typedef enum {
    DECODER_RT_UP = 0,
    MIXER_RT_UP,
    PP_RT_UP,
    PCMR_RT_UP,
    AO_MIXER_RT_UP
} IIDK_MODULE_RUNTIME_UPDATE;

/* ===========================================================================================*/

#endif

/** \@} */
