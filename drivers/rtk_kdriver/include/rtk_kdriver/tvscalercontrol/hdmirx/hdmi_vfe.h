#ifndef _VFE_HDMI_VFE_H_
#define _VFE_HDMI_VFE_H_



/**************************************************************************************/
//
//     Whatever life holds in store for me, I will never forget these words:
//     "With great power comes great responsibility." This is my gift, my curse.
//     Who am I? I'm Spider-man.
//
//      - Spider-Man, Spider-Man (2002)
//
/**************************************************************************************/







#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************


	HDMI driver include header files


********************************************************************************************/
#include <linux/types.h>
#include <tvscalercontrol/scaler/scalerstruct.h>
#include <tvscalercontrol/scalerdrv/mode.h>



/********************************************************************************************


	HDMI driver constant definitions


********************************************************************************************/
#define VFE_HDMI_PACKET_DATA_LENGTH 28
#define VFE_HDMI_INFOFRAME_PACKET_LEN 28
#define VFE_HDMI_VENDOR_SPECIFIC_REGID_LEN 3
#define VFE_HDMI_VENDOR_SPECIFIC_PAYLOAD_LEN \
    (VFE_HDMI_INFOFRAME_PACKET_LEN - VFE_HDMI_VENDOR_SPECIFIC_REGID_LEN)

#define VFE_HDMI_SPD_IF_VENDOR_LEN          8
#define VFE_HDMI_SPD_IF_DESC_LEN            16

typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
/********************************************************************************************


	HDMI emulator definitions


********************************************************************************************/
/**
 * vfe_hdmi_vsi_video_format_e
 *
 * vsi info : video format
*/
/*  have to refer timing info, doesn't refer 3D tag or header info */
typedef enum
{
	VFE_HDMI_VSI_VIDEO_FORMAT_NO_ADDITIONAL_FORMAT, //2D
	VFE_HDMI_VSI_VIDEO_FORMAT_EXTENDED_RESOLUTION_FORMAT,
	VFE_HDMI_VSI_VIDEO_FORMAT_3D_FORMAT,
} vfe_hdmi_vsi_video_format_e;

/**
 * vfe_hdmi_3d_format_type_e
 *
 * 3D Video Full Timing Information.
*/
/*  have to refer timing info, doesn't refer 3D tag or header info */
typedef enum
{
	VFE_HDMI_3D_FORMAT_2D,					/**< for No 3D (OFF)..... INPUT_TYPE_2DTO3D */

	//interim format - half
	VFE_HDMI_3D_FORMAT_TOP_BOTTOM,			/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_TOPNBOTTOM*/
	VFE_HDMI_3D_FORMAT_SIDEBYSIDE_HALF,	/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_SIDEBYSIDE*/
	VFE_HDMI_3D_FORMAT_CHECKER_BOARD,		/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_CHECKERBOARD*/
	VFE_HDMI_3D_FORMAT_FRAME_SEQ,			/**< for T/B, S/S, Checker, Frame Seq...INPUT_TYPE_FRAMESEQ*/
	VFE_HDMI_3D_FORMAT_COLUMN_INTERLEAVE,	/**< for H.264*/
	VFE_HDMI_3D_FORMAT_LINE_INTERLEAVE_HALF,	/**< for H.264*/

	//Full format
	VFE_HDMI_3D_FORMAT_FRAME_PACKING,			/**< Full format*/
	VFE_HDMI_3D_FORMAT_FIELD_ALTERNATIVE,		/**< Full format*/
	VFE_HDMI_3D_FORMAT_LINE_ALTERNATIVE,		/**< Full format (row interleave)*/
	VFE_HDMI_3D_FORMAT_SIDEBYSIDE_FULL,		/**< Full format*/
	VFE_HDMI_3D_FORMAT_DUALSTREAM,		/**< Full format*/

	//
	VFE_HDMI_3D_FORMAT_2DTO3D,					/**< for2D TO  3D..... INPUT_TYPE_2DTO3D */
	VFE_HDMI_3D_FORMAT_MAX,
} vfe_hdmi_3d_format_type_e;

/**`
 * vfe_hdmi_vsi_3d_structure_e
 *
 * 3D struct format, see HDMI Spec. v1.4a
*/
typedef enum
{
	VFE_HDMI_VSI_3D_STRUCTURE_FRAME_PACKING,		//*0
	VFE_HDMI_VSI_3D_STRUCTURE_FIELD_ALTERNATIVE,	//*1
	VFE_HDMI_VSI_3D_STRUCTURE_LINE_ALTERNATIVE,		//*2
	VFE_HDMI_VSI_3D_STRUCTURE_SIDEBYSIDE_FULL,		//*3
	VFE_HDMI_VSI_3D_STRUCTURE_L_DEPTH,				//*4
	VFE_HDMI_VSI_3D_STRUCTURE_L_DEPTH_GRAPHICS,		//*5
	VFE_HDMI_VSI_3D_STRUCTURE_TOP_BOTTOM,			//*6
	/*reserved 7*/
	VFE_HDMI_VSI_3D_STRUCTURE_SIDEBYSIDE_HALF	=	0x08,
	VFE_HDMI_VSI_3D_STRUCTURE_TOP_BOTTOM_DIRECTV =	0x09,
} vfe_hdmi_vsi_3d_structure_e;


/**
 * vfe_hdmi_3d_lr_type_e
 *
 * 3D L/R selection
*/
typedef enum
{
	VFE_HDMI_3D_LR,
	VFE_HDMI_3D_RL,
}vfe_hdmi_3d_lr_type_e;

/**
 * vfe_hdmi_vsi_3d_extdata_e
 *
 * 3D struct format, see HDMI Spec. v1.4a
*/
typedef enum
{

        	VFE_HDMI_VSI_3D_EXT_DATA_HOR_SUB_SAMPL_0,
	VFE_HDMI_VSI_3D_EXT_DATA_HOR_SUB_SAMPL_1,
	VFE_HDMI_VSI_3D_EXT_DATA_HOR_SUB_SAMPL_2,
	VFE_HDMI_VSI_3D_EXT_DATA_HOR_SUB_SAMPL_3,

	VFE_HDMI_VSI_3D_EXT_DATA_QUINCUNX_MATRIX_0 = 0x04,
	VFE_HDMI_VSI_3D_EXT_DATA_QUINCUNX_MATRIX_1,
	VFE_HDMI_VSI_3D_EXT_DATA_QUINCUNX_MATRIX_2,
	VFE_HDMI_VSI_3D_EXT_DATA_QUINCUNX_MATRIX_3,

} vfe_hdmi_vsi_3d_extdata_e;

/**
 * HDMI Video Format Identification Code for extended resolution 0~ff
 *
*/
typedef enum
{
	VFE_HDMI_RESERVED,
	VFE_HDMI_VSI_VIC_4K2K_30HZ,
	VFE_HDMI_VSI_VIC_4K2K_25HZ,
	VFE_HDMI_VSI_VIC_4K2K_24HZ,
	VFE_HDMI_VSI_VIC_4K2K_24HZ_SMPTE,
}vfe_hdmi_vsi_vic_e;

/**
 * vfe_hdmi_mode_e
 *
 * HDMI or DVI mode., see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_DVI,	/**< DVI signal */
    VFE_HDMI_HDMI,	/**< HDMI signal */
} vfe_hdmi_mode_e;

/**
 * vfe_hdmi_packet_status_e
 *
 * HDMI packet status, see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_PACKET_STATUS_NOT_RECEIVED = 0,	/**< HDMI packet status */
    VFE_HDMI_PACKET_STATUS_STOPPED,				/**< HDMI packet status */
    VFE_HDMI_PACKET_STATUS_UPDATED,				/**< HDMI packet status */
    VFE_HDMI_PACKET_STATUS_MAX					/**< HDMI packet status */
} vfe_hdmi_packet_status_e;

/**
 * vfe_hdmi_avi_csc_e
 *
 * HDMI AVI CSC Info., see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_AVI_CSC_RGB = 0,	/**< HDMI CSC info */
    VFE_HDMI_AVI_CSC_YCBCR422,	/**< HDMI CSC info */
    VFE_HDMI_AVI_CSC_YCBCR444,	/**< HDMI CSC info */
    VFE_HDMI_AVI_CSC_FUTURE		/**< HDMI CSC info */
} vfe_hdmi_avi_csc_e;

/**
 * vfe_hdmi_avi_active_info_e
 *
 * HDMI AVI ACTIVE Info., see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_AVI_ACTIVE_INFO_INVALID = 0,		/**< HDMI info */
    VFE_HDMI_AVI_ACTIVE_INFO_VALID			/**< HDMI info */
} vfe_hdmi_avi_active_info_e;

/**
 * vfe_hdmi_avi_bar_info_e
 *
 * HDMI AVI BAR Info., see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_AVI_BAR_INFO_INVALID,			/**< HDMI info */
    VFE_HDMI_AVI_BAR_INFO_VERTICALVALID,		/**< HDMI info */
    VFE_HDMI_AVI_BAR_INFO_HORIZVALID,			/**< HDMI info */
    VFE_HDMI_AVI_BAR_INFO_VERTHORIZVALID		/**< HDMI info */
} vfe_hdmi_avi_bar_info_e;

/**
 * vfe_hdmi_avi_scan_info_e
 *
 * HDMI AVI SCAN Info., see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_AVI_SCAN_INFO_NODATA,			/**< HDMI info */
    VFE_HDMI_AVI_SCAN_INFO_OVERSCANNED,		/**< HDMI info */
    VFE_HDMI_AVI_SCAN_INFO_UNDERSCANNED,		/**< HDMI info */
    VFE_HDMI_AVI_SCAN_INFO_FUTURE		= 3
} vfe_hdmi_avi_scan_info_e;

/**
 * vfe_hdmi_avi_colorimetry_e
 *
 * HDMI Colorimetry., see HDMI Spec. v1.3a or above
*/
typedef enum
{
    VFE_HDMI_AVI_COLORIMETRY_NODATA =  0,		/**< HDMI info */
    VFE_HDMI_AVI_COLORIMETRY_SMPTE170,		/**< HDMI info */
    VFE_HDMI_AVI_COLORIMETRY_ITU709,			/**< HDMI info */
    VFE_HDMI_AVI_COLORIMETRY_FUTURE,			/**< HDMI info */
    VFE_HDMI_AVI_COLORIMETRY_EXTENDED = VFE_HDMI_AVI_COLORIMETRY_FUTURE
} vfe_hdmi_avi_colorimetry_e;

/**
 * vfe_hdmi_avi_picture_arc_e
 *
 * HDMI AVI Picture ARC., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_PICTURE_ARC_NODATA = 0,		/**< HDMI info */
	VFE_HDMI_AVI_PICTURE_ARC_4_3,				/**< HDMI info */
	VFE_HDMI_AVI_PICTURE_ARC_16_9,			/**< HDMI info */
	VFE_HDMI_AVI_PICTURE_ARC_FUTURE			/**< HDMI info */
} vfe_hdmi_avi_picture_arc_e;

/**
 * vfe_hdmi_avi_active_format_arc_e
 *
 * HDMI AVI ACTIVE FORMAT ARC., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_ACTIVE_FORMAT_ARC_PICTURE    =  8,	/**< HDMI info */
	VFE_HDMI_AVI_ACTIVE_FORMAT_ARC_4_3CENTER  =  9,	/**< HDMI info */
	VFE_HDMI_AVI_ACTIVE_FORMAT_ARC_16_9CENTER = 10,	/**< HDMI info */
	VFE_HDMI_AVI_ACTIVE_FORMAT_ARC_14_9CENTER = 11,	/**< HDMI info */
	VFE_HDMI_AVI_ACTIVE_FORMAT_ARC_OTHER      =  0	/**< HDMI info */
} vfe_hdmi_avi_active_format_arc_e;

/**
 * vfe_hdmi_avi_scaling_e
 *
 * HDMI AVI Scaling info., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_SCALING_NOSCALING = 0,		/**< HDMI info */
	VFE_HDMI_AVI_SCALING_HSCALING,			/**< HDMI info */
	VFE_HDMI_AVI_SCALING_VSCALING,			/**< HDMI info */
	VFE_HDMI_AVI_SCALING_HVSCALING			/**< HDMI info */
} vfe_hdmi_avi_scaling_e;

/**
 * vfe_hdmi_avi_it_content_e
 *
 * HDMI AVI IT Content., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_IT_CONTENT_NODATA    =  0,	/**< HDMI info */
	VFE_HDMI_AVI_IT_CONTENT_ITCONTENT  =  1	/**< HDMI info */
} vfe_hdmi_avi_it_content_e;

/**
 * vfe_hdmi_avi_ext_colorimetry_e
 *
 * HDMI Extended Colorimetry., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_EXT_COLORIMETRY_XVYCC601 = 0,	/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_XVYCC709 ,		/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_sYCC601,		/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_AdobeYCC601,	/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_AdobeRGB,		/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_ITURBT2020YCCBCCRC,		/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_ITURBT2020RGBorYCBCR,		/**< HDMI info */
	VFE_HDMI_AVI_EXT_COLORIMETRY_RESERVED		/**< HDMI info */
} vfe_hdmi_avi_ext_colorimetry_e;

/**
 * vfe_hdmi_avi_rgb_quantization_range_e
 *
 * HDMI AVI RGB Quantization range., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_RGB_QUANTIZATION_RANGE_DEFAULT    =  0,		/**< HDMI info */
	VFE_HDMI_AVI_RGB_QUANTIZATION_RANGE_LIMITEDRANGE  =  1,	/**< HDMI info */
	VFE_HDMI_AVI_RGB_QUANTIZATION_RANGE_FULLRANGE = 2,		/**< HDMI info */
	VFE_HDMI_AVI_RGB_QUANTIZATION_RANGE_RESERVED = 3			/**< HDMI info */
} vfe_hdmi_avi_rgb_quantization_range_e;

/**
 * vfe_hdmi_avi_ycc_quantization_range_e
 *
 * HDMI AVI YCC Quantization range., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_YCC_QUANTIZATION_RANGE_LIMITEDRANGE  =  0,	/**< HDMI info */
	VFE_HDMI_AVI_YCC_QUANTIZATION_RANGE_FULLRANGE = 1,		/**< HDMI info */
	VFE_HDMI_AVI_YCC_QUANTIZATION_RANGE_RESERVED = 2			/**< HDMI info */
} vfe_hdmi_avi_ycc_quantization_range_e;

/**
 * vfe_hdmi_avi_content_type_e
 *
 * HDMI AVI Content Type., see HDMI Spec. v1.3a or above
*/
typedef enum
{
	VFE_HDMI_AVI_CONTENT_TYPE_GRAPHICS = 0,
	VFE_HDMI_AVI_CONTENT_TYPE_PHOTO,
	VFE_HDMI_AVI_CONTENT_TYPE_CINEMA,
	VFE_HDMI_AVI_CONTENT_TYPE_GAME,
	VFE_HDMI_AVI_CONTENT_TYPE_MAX
} vfe_hdmi_avi_content_type_e;

/**
 * vfe_hdmi_access_edid_path_e
 *
 * select access edid path
*/
typedef enum
{
	VFE_HDMI_ACCESS_EDID_FROM_INTERNAL,
	VFE_HDMI_ACCESS_EDID_FROM_EXTERNAL,
} vfe_hdmi_access_edid_path_e;

/**
 * vfe_hdmi_mhl_msc_type_e
 *
 * mhl msc type selection
*/
typedef enum
{
	VFE_HDMI_MHL_MSC_MSG_MSGE = 0x02,
	VFE_HDMI_MHL_MSC_MSG_RCP  = 0x10,
	VFE_HDMI_MHL_MSC_MSG_RCPK = 0x11,
	VFE_HDMI_MHL_MSC_MSG_RCPE = 0x12,
	VFE_HDMI_MHL_MSC_MSG_RAP  = 0x20,
	VFE_HDMI_MHL_MSC_MSG_RAPK = 0x21,
	VFE_HDMI_MHL_MSC_MSG_UCP  = 0x30,
	VFE_HDMI_MHL_MSC_MSG_UCPK = 0x31,
	VFE_HDMI_MHL_MSC_MSG_UCPE = 0x32,
} vfe_hdmi_mhl_msc_type_e;


enum vfe_hdmi_color_space_e
{
	VFE_HDMI_COLOR_RGB 	= 0X00,
	VFE_HDMI_COLOR_YUV422,
	VFE_HDMI_COLOR_YUV444,
	VFE_HDMI_COLOR_YUV411,
	VFE_HDMI_COLOR_UNKNOW
};

enum vfe_hdmi_color_depth_e
{
	VFE_HDMI_COLOR_DEPTH_8B =0,
	VFE_HDMI_COLOR_DEPTH_10B,
	VFE_HDMI_COLOR_DEPTH_12B,
	VFE_HDMI_COLOR_DEPTH_16B,
};

enum vfe_hdmi_color_imetry_e
{
	VFE_HDMI_COLORIMETRY_NOSPECIFIED = 0,
	VFE_HDMI_COLORIMETRY_601,
	VFE_HDMI_COLORIMETRY_709,
	VFE_HDMI_COLORIMETRY_XYYCC601,
	VFE_HDMI_COLORIMETRY_XYYCC709,
	VFE_HDMI_COLORIMETRY_SYCC601,
	VFE_HDMI_COLORIMETRY_ADOBE_YCC601,
	VFE_HDMI_COLORIMETRY_ADOBE_RGB,
};

enum vfe_hdmi_audio_coding_type_e
{
	VFE_HDMI_AUDIO_HDMI_DVI         = 0,
	VFE_HDMI_AUDIO_HDMI_NO_AUDIO    = 1,
	VFE_HDMI_AUDIO_HDMI_PCM         = 2,
	VFE_HDMI_AUDIO_HDMI_AC3         = 3,
	VFE_HDMI_AUDIO_HDMI_DTS         = 4,
	VFE_HDMI_AUDIO_HDMI_AAC         = 5,
	VFE_HDMI_AUDIO_HDMI_DEFAULT     = 6,
	VFE_HDMI_AUDIO_HDMI_MPEG        = 10,
	VFE_HDMI_AUDIO_HDMI_DTS_HD_MA   = 11,
	VFE_HDMI_AUDIO_HDMI_DTS_EXPRESS = 12,
	VFE_HDMI_AUDIO_HDMI_DTS_CD      = 13,
};

/**
 * vfe_hdcp_mode_e
 *
 * HDCP 1.4 / HDCP 2.2
*/
typedef enum
{
    VFE_HDCP_1P4,
    VFE_HDCP_2P2,
    VFE_HDCP_MAX,
} vfe_hdcp_mode_e;
/********************************************************************************************


	HDMI sturcture definitions


********************************************************************************************/
/**
 * vfe_hdmi_infoframe_header_t
 *
 * HDMI info-frame header, see HDMI Spec. v1.3a or above
*/
typedef struct
{
	unsigned char type;            /**< packet type */
	unsigned char version;         /**< packet version */
	unsigned char length;          /**< packet length */
} vfe_hdmi_infoframe_header_t;


/**
 * vfe_hdmi_avi_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, avi infoframe
 *
 * HDMI AVI RGB INFO., see HDMI Spec. v1.3a or above
*/
typedef struct
{
	unsigned char port;

	vfe_hdmi_infoframe_header_t header;

	vfe_hdmi_mode_e mode;				/**< HDMI info */

	vfe_hdmi_avi_csc_e pixel_encoding;			/**< HDMI info */

	vfe_hdmi_avi_active_info_e active_info;		/**< HDMI info */	/* A0 */

	vfe_hdmi_avi_bar_info_e  bar_info;			/**< HDMI info */   /* B1B0 */

	vfe_hdmi_avi_scan_info_e  scan_info;			/**< HDMI info */   /* S1S0 */

	vfe_hdmi_avi_colorimetry_e colorimetry;		/**< HDMI info */	/* C1C0 */

	vfe_hdmi_avi_picture_arc_e picture_aspect_ratio;	/**< HDMI info */	/* M1M0 */

	vfe_hdmi_avi_active_format_arc_e active_format_aspect_ratio;/**< HDMI info */	/* R3R0 */

	vfe_hdmi_avi_scaling_e scaling;						/**< HDMI info */	/* SC1SC0 */

	unsigned char video_id_code;								/**< HDMI info */	/* VICn */

	unsigned char pixel_repeat;								/**< HDMI info */

	vfe_hdmi_avi_it_content_e it_content;			/**< HDMI info */	/*ITC */

	vfe_hdmi_avi_ext_colorimetry_e extended_colorimetry;	/**< HDMI info */	/* EC2EC1EC0 */

	vfe_hdmi_avi_rgb_quantization_range_e rgb_quantization_range;	/**< HDMI info */	/* Q1Q0 */

	vfe_hdmi_avi_ycc_quantization_range_e ycc_quantization_range;	/**< HDMI info */	/* YQ1YQ0 */

	vfe_hdmi_avi_content_type_e content_type;			/**< HDMI info */	/* Contents Type */

	/* bar info */
	unsigned short TopBarEndLineNumber;				/**< HDMI info */
	unsigned short BottomBarStartLineNumber;		/**< HDMI info */
	unsigned short LeftBarEndPixelNumber;			/**< HDMI info */
	unsigned short RightBarEndPixelNumber;			/**< HDMI info */

	vfe_hdmi_packet_status_e packetStatus;	/**< HDMI info */
} vfe_hdmi_avi_t;


/**
 * vfe_hdmi_spd_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, sdp infoframe
 *
 * HDMI SPD Info.
 * see HDMI Spec. v1.3a or above
*/
typedef struct
{
	unsigned char port;
	vfe_hdmi_infoframe_header_t header;
    unsigned char  vendor_name[VFE_HDMI_SPD_IF_VENDOR_LEN];
    unsigned char  product_desc[VFE_HDMI_SPD_IF_DESC_LEN];
    unsigned char  src_dev_info;
    vfe_hdmi_packet_status_e packetStatus;
} vfe_hdmi_spd_t;

/**
 * vfe_hdmi_vsi_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, vsi infoframe
 *
 * HDMI VSI Info., see HDMI Spec. v1.3a or above
*/
typedef struct
{
	unsigned char port;
	vfe_hdmi_infoframe_header_t header;
    unsigned char   ieee_reg_id[VFE_HDMI_VENDOR_SPECIFIC_REGID_LEN];
    unsigned char   payload[VFE_HDMI_VENDOR_SPECIFIC_PAYLOAD_LEN];
    vfe_hdmi_packet_status_e packetStatus;				/**< HDMI VSI info */

//willychou add
	vfe_hdmi_vsi_video_format_e vidoe_fmt;
	vfe_hdmi_vsi_3d_structure_e struct_3d;
              vfe_hdmi_vsi_3d_extdata_e extdata_3d;
              vfe_hdmi_vsi_vic_e vic;
} vfe_hdmi_vsi_t;

/**
 * vfe_hdmi_all_packet_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, avi spd vsi infoframe
 *
 * HDMI AVI SPD VSI Info., see HDMI Spec. v1.3a or above
*/
typedef struct
{
    vfe_hdmi_mode_e mode;
    vfe_hdmi_avi_t stAVI;
    vfe_hdmi_spd_t stSPD;
    vfe_hdmi_vsi_t stVSI;
    vfe_hdmi_packet_status_e packetStatus;
} vfe_hdmi_all_packet_t;

typedef struct
{
        unsigned char type_code;
        unsigned char ver;
        unsigned char len;
        unsigned char  eEOTFtype;
        unsigned char  eMeta_Desc;
        unsigned short display_primaries_x0;
        unsigned short display_primaries_y0;
        unsigned short display_primaries_x1;
        unsigned short display_primaries_y1;
        unsigned short display_primaries_x2;
        unsigned short display_primaries_y2;
        unsigned short white_point_x;
        unsigned short white_point_y;
        unsigned short max_display_mastering_luminance;
        unsigned short min_display_mastering_luminance;
        unsigned short maximum_content_light_level;
        unsigned short maximum_frame_average_light_level;
		unsigned char  reserved;
}__attribute__((packed)) vfe_hdmi_drm_t;

/**
 * vfe_hdmi_rect_t
 *
 * video timing rect. info
*/
typedef struct
{
	unsigned short	x;	/**< horizontal Start Position in pixel [0,].*/
	unsigned short	y;	/**< vertical   Start Position in pixel [0,].*/
	unsigned short	w;	/**< horizontal Size(Width)    in pixel [0,].*/
	unsigned short	h;	/**< vertical   Size(Height)   in pixel [0,].*/
} vfe_hdmi_rect_t;

/**
 * vfe_hdmi_timing_info_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, timing info
 *
 * update hdmi timing info
*/
typedef struct
{
	unsigned char port;
	unsigned short h_freq;	/**< ... */
	unsigned short v_freq;	/**< ... */
	unsigned short h_total;	/**< ... */
	unsigned short v_total;	/**< ... */
	unsigned short h_porch;	/**< ... */
	unsigned short v_porch;	/**< ... */
	vfe_hdmi_rect_t	active;	/**< */
	unsigned short scan_type;	/**< 1:progressive; 0:interlace */
	unsigned char isDolbyHDR;

	vfe_hdmi_3d_format_type_e full_3d_timing;// 3D format information base on timing info
	vfe_hdmi_3d_lr_type_e	video_lr_order;
	vfe_hdmi_vsi_video_format_e vidoe_fmt;
	vfe_hdmi_vsi_3d_structure_e struct_3d;

	/**
	 * extra info that VSC needs
	 * scan_type info above equals to progressive or interlace
	*/
	int x_offset; /* diff. of w start position betweet off-line and on-line measure */
	int y_offset; /* diff. of h start position betweet off-line and on-line measure */
	unsigned short hsync; /* equal to h_total */
	unsigned short vsync; /* equal to v_total */
    unsigned char mode_id;
	unsigned char mode_table_index;
	unsigned char polarity;
	enum vfe_hdmi_color_space_e color_space;
	enum vfe_hdmi_color_depth_e color_depth;
	enum vfe_hdmi_color_imetry_e color_imetry;
       unsigned char pixel_repeat;
	unsigned short IVSyncPulseCount;
} vfe_hdmi_timing_info_t;

/**
 * vfe_hdmi_sw_5v_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, sw 5v info
 *
 * hdmi 5v info
*/
typedef struct
{
	unsigned char port;
	unsigned char sw_5v;
} vfe_hdmi_sw_5v_t;

/**
 * vfe_hdmi_connect_state_t
 * @param [IN] port, hdmi port selection
 * @param [OUT] others, connect state
 *
 * hdmi connect state
*/
typedef struct
{
	unsigned char port;
	unsigned char state; /**< 1:connect; 0:disconnect */
} vfe_hdmi_connect_state_t;

/**
 * vfe_hdmi_edid_data_t
 * @param [IN] port, hdmi port selection
 * @param [IN/OUT] *pdata, edid data when read, it is a output param;
 *                         otherwise it is a input param.
 * @param [IN] access_path, refer to vfe_hdmi_access_edid_path_e
 *
 * hdmi edid table
*/
typedef struct
{
	unsigned char port;
	unsigned char *pdata;
	vfe_hdmi_access_edid_path_e access_path;
} vfe_hdmi_edid_data_t;

/**
 * vfe_hdmi_hdcp_data_t
 * @param [IN/OUT] *pksv,  ksv data when read, it is a output param;
 *                         otherwise it is a input param.
 * @param [IN/OUT] *pdevice_key, device key when read, it is a output param;
 *                               otherwise it is a input param.
 * hdmi hdcp key table
*/
typedef struct
{
	unsigned char *pksv;
	unsigned char *pdevice_key;
} vfe_hdmi_hdcp_data_t;

/**
 * vfe_hdmi_ksv_data_t
 * @param [IN] port, hdmi port selection
 * @param [IN/OUT] *pksv, ksv data when read, it is a output param;
 *                        otherwise it is a input param.
 *
 * hdmi ksv table
*/
typedef struct
{
	unsigned char port;
	unsigned char *pksv;
} vfe_hdmi_ksv_data_t;

/**
 * vfe_hdmi_mhl_msc_write_burst_cmd_t
 * @param [IN/OUT] data_len, data array len
 * @param [IN/OUT] *pdata_bytes, write burst data
 *
 * hdmi ksv table
*/
typedef struct
{
	unsigned char data_len;
	unsigned char *pdata_bytes;
} vfe_hdmi_mhl_msc_write_burst_cmd_t;

/**
 * vfe_hdmi_mhl_msc_msg_t
 * @param [OUT] msc_type, msc type selection
 * @param [OUT] value, get value
 *
 * mhl msc msg info
*/
typedef struct
{
	vfe_hdmi_mhl_msc_type_e msc_type;
	unsigned char value;
} vfe_hdmi_mhl_msc_msg_t;

typedef struct
{
	unsigned char port;
	bool is_mhl;
}vfe_hdmi_mhl_mode_t;

typedef struct
{
	unsigned char port;
	bool bClockStatus;
}vfe_hdmi_clockstatus_t;
//willychou add for write edid value before HDMI init
/**
 * vfe_hdmi_edid_data_apply_t
 * @param [IN] port, hdmi port selection
 * @param [IN/OUT] *pdata, edid data when read, it is a output param;
 *                         otherwise it is a input param.
 * @param [IN] access_path, refer to vfe_hdmi_access_edid_path_e
*/
typedef struct
{
	unsigned char port;
	unsigned char *pdata;
	vfe_hdmi_access_edid_path_e access_path;
	unsigned char apply;
} vfe_hdmi_edid_data_apply_t;

/**
 * vfe_hdmi_hdcp_data_apply_t
 * @param [IN/OUT] *pksv,  ksv data when read, it is a output param;
 *                         otherwise it is a input param.
 * @param [IN/OUT] *pdevice_key, device key when read, it is a output param;
 *                               otherwise it is a input param.
 * hdmi hdcp key table
*/
typedef struct
{
	unsigned char  version;
	unsigned char *pksv;
	unsigned char apply;
} vfe_hdmi_hdcp_data_apply_t;

typedef struct
{
	unsigned char port;
	unsigned char hdmi_ver; // [bit 0] : HDMI 1.4, [Bit 1] : HDMI 2.0
}vfe_hdmi_support_ver_t;

typedef struct
{
	unsigned char port;
	unsigned char hdcp_ver;
}vfe_hdmi_hdcp_ver_t;

typedef struct
{
	unsigned char port;
	unsigned char hpd_ctl;
}vfe_hdmi_hpd_t;

typedef struct
{
	vfe_hdcp_mode_e hdcp_ver;
	unsigned char key_load;
}vfe_hdcp_table_t;
/****************************************************************************


	HDMI Driver API  For Users


****************************************************************************/
/**
 * int vfe_hdmi_drv_init(void)
 * @param none
 * @return 0 : ok; other not ok
 *
 * it initializes all the sources such as tables, task...etc
*/
int vfe_hdmi_drv_init(void);

/**
 * int vfe_hdmi_drv_uninit(void)
 * @param none
 * @return 0 : ok; other not ok
 *
 * it un-initializes all the sources such as tables, task...etc
*/
int vfe_hdmi_drv_uninit(void);

/**
 * int vfe_hdmi_drv_open(void)
 * @param none
 * @return 0 : ok; other not ok
 *
 * it opens hdmi IP to be ready to detect timing
*/
int vfe_hdmi_drv_open(void);

/**
 * int vfe_hdmi_drv_close(void)
 * @param none
 * @return 0 : ok; other not ok
 *
 * it closes hdmi IP
*/
int vfe_hdmi_drv_close(void);

/**
 * int vfe_hdmi_drv_connect(unsigned char port)
 * @param [IN] port, hdmi port
 * @return 0 : ok; other not ok
 *
 * it connects hdmi to detect timing for selected port
*/
int vfe_hdmi_drv_connect(unsigned char port);

/**
 * int vfe_hdmi_drv_disconnect(unsigned char port)
 * @param [IN] port, hdmi port
 * @return 0 : ok; other not ok
 *
 * it disconnects hdmi to open-state
*/
int vfe_hdmi_drv_disconnect(unsigned char port);


extern unsigned char vfe_hdmi_drv_detect_mode(void);


/**
 * int vfe_hdmi_drv_get_port_timing_info(vfe_hdmi_timing_info_t *timing_info)
 * @param [IN] timing_info, refer to vfe_hdmi_timing_info_t
 * @return 0 : ok; other not ok
 *
 * it gets timing info for selected port
*/
int vfe_hdmi_drv_get_port_timing_info(vfe_hdmi_timing_info_t *timing_info);

/**
 * int vfe_hdmi_drv_get_display_timing_info(vfe_hdmi_timing_info_t *timing_info)
 * @param [IN] timing_info, refer to vfe_hdmi_timing_info_t
 * @return 0 : ok; other not ok
 *
 * It updates timing info from off-line measure info except for x_offset and y_offset.
 * Use on-line measure to get w and h start position, and x_offset and y_offset are got from
 * the diff. of start position between off-line and on-line measure.
 * The function is called by VSC
*/
int vfe_hdmi_drv_get_display_timing_info(vfe_hdmi_timing_info_t *timing_info, unsigned char vsc_ch);

/**
 * void vfe_hdmi_drv_handle_on_line_measure_error(unsigned char vfe_call)
 * @param [IN] none
 * @return none
 *
 * When on-line measure happens to error, api is called to process this evnet.
*/
void vfe_hdmi_drv_handle_on_line_measure_error(unsigned char vfe_call);

/**
 * int vfe_hdmi_drv_get_port_vsi_info(vfe_hdmi_vsi_t *info_frame)
 * @param [IN] info_frame, refer to vfe_hdmi_vsi_t
 * @return 0 : ok; other not ok
 *
 * it gets vsi info-frame data for selected port
*/

void vfe_hdmi_drv_adapter(void);
int vfe_hdmi_drv_get_drm_info(vfe_hdmi_drm_t *info_frame);
int vfe_hdmi_drv_get_port_vsi_info(vfe_hdmi_vsi_t *info_frame);

/**
 * int vfe_hdmi_drv_get_port_spd_info(vfe_hdmi_spd_t *info_frame)
 * @param [IN] info_frame, refer to vfe_hdmi_spd_t
 * @return 0 : ok; other not ok
 *
 * it gets spd info-frame data for selected port
*/
int vfe_hdmi_drv_get_port_spd_info(vfe_hdmi_spd_t *info_frame);

/**
 * int vfe_hdmi_drv_get_port_avi_info(vfe_hdmi_avi_t *info_frame)
 * @param [IN] info_frame, refer to vfe_hdmi_avi_t
 * @return 0 : ok; other not ok
 *
 * it gets avi info-frame data for selected port
*/
int vfe_hdmi_drv_get_port_avi_info(vfe_hdmi_avi_t *info_frame);
//bool Cmp_AviInfoFrame(vfe_hdmi_avi_t *info_frameA,vfe_hdmi_avi_t *info_frameB);
//bool Cmp_TiminginfoFrame(vfe_hdmi_timing_info_t *info_frameA,vfe_hdmi_timing_info_t *info_frameB);
/**
 * int vfe_hdmi_drv_get_port_allpacket_info(vfe_hdmi_all_packet_t *info_frame)
 * @param [IN] info_frame, refer to vfe_hdmi_all_packet_t
 * @return 0 : ok; other not ok
 *
 * it gets avi vsi spd info-frame data for selected port
*/
int vfe_hdmi_drv_get_port_allpacket_info(vfe_hdmi_all_packet_t *info_frame);

/**
 * int vfe_hdmi_drv_get_connection_state(vfe_hdmi_connect_state_t *con_state)
 * @param [IN] con_state, refer to vfe_hdmi_connect_state_t
 * @return 0 : ok; other not ok
 *
 * it gets connection state for selected port
*/
int vfe_hdmi_drv_get_connection_state(vfe_hdmi_connect_state_t *con_state);

/**
 * int vfe_hdmi_drv_enable_hpd(void)
 * @param none
 * @return 0 : ok; other not ok
 *
 * it enables hdmi hpd
*/
int vfe_hdmi_drv_enable_hpd(void);

/**
 * int vfe_hdmi_drv_disable_hpd(void)
 * @param none
 * @return 0 : ok; other not ok
 *
 * it disables hdmi hpd
*/
int vfe_hdmi_drv_disable_hpd(void);

/**
 * int vfe_hdmi_drv_disable_internal_edid_access(unsigned char port)
 * @param [IN] port, hdmi port
 * @return 0 : ok; other not ok
 *
 * it disables internal edid access
*/
int vfe_hdmi_drv_disable_internal_edid_access(unsigned char port);


/**
 * int vfe_hdmi_drv_read_edid(unsigned char ch, unsigned char* p_edid, unsigned short len)
 * @param [IN] ch     : HDMI channel (0~N-1)
 *        [IN] p_edid : EDID data to be written
 *        [IN] len    : size of EDID data. the possible value of it is 256 & 512 
 * @return 0 : ok; other not ok  
 *
 * it reads edid for selected port
*/
int vfe_hdmi_drv_read_edid(unsigned char ch, unsigned char* p_edid, unsigned short len);

#define APPLY_EDID_IMMEDIATELY 0x80
/**
 * int vfe_hdmi_drv_write_edid(unsigned char ch, unsigned char* p_edid, unsigned short len, unsigned long flags)
 * @param [IN] ch     : HDMI channel (0~N-1)
 *        [IN] p_edid : EDID data to be written
 *        [IN] len    : size of EDID data. the possible value of it is 256 & 512
 *        [IN] flags  : controlling flags  
 *              APPLY_EDID_IMMEDIATELY : enable EDID immedately
 * @return 0 : ok; other not ok 
 */
int vfe_hdmi_drv_write_edid(unsigned char ch, const unsigned char* p_edid, unsigned short len, unsigned long flags);


/**
 * int vfe_hdmi_drv_read_hdcp(vfe_hdmi_hdcp_data_t *hdcp_data)
 * @param [IN] hdcp_data, refer to vfe_hdmi_hdcp_data_t
 * @return 0 : ok; other not ok
 *
 * it reads hdcp key
*/
int vfe_hdmi_drv_read_hdcp(vfe_hdmi_hdcp_data_t *hdcp_data);

/**
 * int vfe_hdmi_drv_write_hdcp(vfe_hdmi_hdcp_data_t hdcp_data)
 * @param [IN] hdcp_data, refer to vfe_hdmi_hdcp_data_t
 * @return 0 : ok; other not ok
 *
 * it writes hdcp key
*/
int vfe_hdmi_drv_write_hdcp(vfe_hdmi_hdcp_data_t hdcp_data);

/**
 * int vfe_hdmi_drv_get_src_ksv_data(vfe_hdmi_ksv_data_t *ksv_data)
 * @param [IN] ksv_data, refer to vfe_hdmi_ksv_data_t
 * @return 0 : ok; other not ok
 *
 * it gets source ksv data
*/
int vfe_hdmi_drv_get_src_ksv_data(vfe_hdmi_ksv_data_t *ksv_data);

/**
 * int vfe_hdmi_drv_get_src_ksv_data(vfe_hdmi_ksv_data_t *ksv_data)
 * @param [IN] ksv_data, refer to vfe_hdmi_ksv_data_t
 * @return true : mhl mode; 0 : hdmi mode
 *
 * it gets MHL mode
*/
int vfe_hdmi_drv_get_is_mhl_mode(void);

/**
 * int vfe_hdmi_drv_send_msc_msg_cmd(vfe_hdmi_mhl_msc_msg_t msc_msg)
 * @param [IN] msc_info, refer to vfe_hdmi_mhl_msc_msg_t
 * @return 0 : ok; other not ok
 *
 * it sends mhl msc msg command
*/
int vfe_hdmi_drv_send_msc_msg_cmd(vfe_hdmi_mhl_msc_msg_t msc_info);

/**
 * int vfe_hdmi_drv_send_msc_write_burst_cmd(vfe_hdmi_mhl_msc_write_burst_cmd_t msc_info)
 * @param [IN] msc_info, refer to vfe_hdmi_mhl_msc_write_burst_cmd_t
 * @return 0 : ok; other not ok
 *
 * it sends mhl msc write burst cmd
*/
int vfe_hdmi_drv_send_msc_write_burst_cmd(vfe_hdmi_mhl_msc_write_burst_cmd_t msc_info);

/**
 * int vfe_hdmi_drv_read_msc_write_burst_cmd(vfe_hdmi_mhl_msc_write_burst_cmd_t *msc_info)
 * @param [IN] msc_info, refer to vfe_hdmi_mhl_msc_write_burst_cmd_t
 * @return 0 : ok; other not ok
 *
 * it gets mhl msc write burst cmd
*/
int vfe_hdmi_drv_read_msc_write_burst_cmd(vfe_hdmi_mhl_msc_write_burst_cmd_t *msc_info);
/**
 * bool vfe_hdmi_drv_get_clock_status(unsigned char port)
 * @param [IN] port, hdmi port
 * @return 1 : clock ok; 0 : clock not ok
 *
 * it gets clock status for selected port
*/
unsigned char  vfe_hdmi_drv_get_clock_status(unsigned char port);
/**
 * bool vfe_hdmi_drv_get_mhl_mode(unsigned char port)
 * @param [IN] port, hdmi port
 * @return true : mhl mode; 0 : hdmi mode
 *
 * it gets MHL mode for selected port
*/
unsigned char vfe_hdmi_drv_get_mhl_mode(unsigned char port);

/**
 * bool vfe_hdmi_drv_chk_is_rcp_msg(void)
 * @param none
 * @return true : rcp msg; false : not rcp
 *
 * it checks if msc msg is rcp
*/
unsigned char vfe_hdmi_drv_chk_is_rcp_msg(void);

/**
 * int vfe_hdmi_drv_get_msc_msg(vfe_hdmi_mhl_msc_msg_t *msc_info)
 * @param [IN] msc_info, refer to vfe_hdmi_mhl_msc_msg_t
 * @return 0 : ok; other not ok
 *
 * it receives msc msg cmd
*/
int vfe_hdmi_drv_get_msc_msg(vfe_hdmi_mhl_msc_msg_t *msc_info);

/**
 * int vfe_hdmi_drv_get_audio_coding_type(unsigned char *coding_type)
 * @param [OUT] coding type value, refer to vfe_hdmi_audio_coding_type_e
 * @return 0 : ok; other not ok
 *
 * users can get audio coding type through this api
*/
int vfe_hdmi_drv_get_audio_coding_type(unsigned char *coding_type);

/**
 * int vfe_hdmi_drv_set_hpd_low_delay(unsigned int delay_timer)
 * @param [IN] hpd low delay timer
 * @return 0 : ok; other not ok
 *
 * users can set hpd low delay timer(ms) through this api
*/
int vfe_hdmi_drv_set_hpd_low_delay(unsigned int delay_timer);

/**
 * int vfe_hdmi_drv_get_avmute(void)
 * @param
 * @return true : avmute enable ; other not ok
 *
 * users can get av mute  through this api
*/
bool vfe_hdmi_drv_get_avmute(void);

int vfe_hdmi_drv_write_hdcp_apply(vfe_hdmi_hdcp_data_apply_t hdcp_data);
char vfe_hdmi_drv_get_arc_channel(void);
#ifdef CONFIG_PM
/**
 * void vfe_hdmi_drv_suspend(void)
 * @param none
 * @return none
 *
 * when power down, it starts to reserve current setting to table
*/
void vfe_hdmi_drv_suspend_afterDisconnectClose(void);
void vfe_hdmi_drv_suspend(void);
/**
 * void vfe_hdmi_drv_resume(void)
 * @param none
 * @return none
 *
 * when power on, it starts to resume last setting and work
*/
void vfe_hdmi_drv_resume(void);
void vfe_hdmi_drv_resume_init(void);
void vfe_hdmi_drv_resume_std(void);
void vfe_hdmi_drv_resume_crt_setting(void);
void vfe_hdmi_drv_suspend_no_connect_setting(void);

#endif


void vfe_hdmi_drv_set_connection_by_5v(UINT8 port, UINT8 state);
UINT8 vfe_hdmi_drv_get_connection_by_5v(UINT8 port);


int vfe_hdmi_drv_get_rx_port_cnt(unsigned char* port_cnt);
int vfe_hdmi_drv_get_hdmi_support_version(vfe_hdmi_support_ver_t* hdmi_version);
int vfe_hdmi_drv_get_hdcp_version(vfe_hdmi_hdcp_ver_t* hdcp_version);
int vfe_hdmi_drv_set_hdcp_support(vfe_hdcp_table_t hdcp_support);
int vfe_hdmi_drv_get_hdcp_support(vfe_hdcp_table_t* hdcp_support);
int vfe_hdmi_drv_SetHDCPReceiverId(UINT8* ReceiverId);
int vfe_hdmi_drv_GetHDCPReceiverId(UINT8* ReceiverId);
int vfe_hdmi_drv_set_hpd(vfe_hdmi_hpd_t* hpd_value);
int vfe_hdmi_drv_get_logical_port(unsigned char* logical_port);

#ifdef __cplusplus
}
#endif


#endif // _VFE_HDMI_VFE_H_
