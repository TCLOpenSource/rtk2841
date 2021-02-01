#ifndef    _VENUSFB_H_
#define    _VENUSFB_H_

#define IOA_DC_SYS_MISC ((volatile unsigned int *)0xb8008004)
#define SB2_GRAPHIC_OFFSET 0xe0000000

typedef enum _tagDisplayMode
{
	DISPLAY_1080,
	DISPLAY_720,
	DISPLAY_576,
	DISPLAY_480
} DISPLAY_MODE;

typedef enum _PIXELFORMAT
{
	Format_8,           //332
	Format_16,          //565
	Format_32,          //A888
	Format_32_888A,     //888A
	Format_2_IDX,
	Format_4_IDX,
	Format_8_IDX,
	Format_1555,
	Format_4444_ARGB,
	Format_4444_YUVA,
	Format_8888_YUVA,
	Format_5551,
	Format_4444_RGBA,
	NO_OF_PIXEL_FORMAT
} PIXEL_FORMAT;

/*
 * These are the bitfields for each
 * display depth that we support.
 */
struct venusfb_rgb {
	struct fb_bitfield	red;
	struct fb_bitfield	green;
	struct fb_bitfield	blue;
	struct fb_bitfield	transp;
};

typedef struct venusfb_mach_info {
	int			pixclock;
	short			xres;
	short			yres;
	int			xoffset;
	int			yoffset;
	short			osdxres;		// x resolution of OSD
	short			osdyres;		// y resolution of OSD
	char			bpp;			// in bits
	int			pitch;			// in bytes
	void 			*videomemory;		// virtual address (in-kernel)
	void			*phyAddr;		// physical address
	int			videomemorysize;	// in bytes
	int			videomemorysizeorder; 	// in 2^n (4KBytes unit)
	int			storageMode;            // 0 :  block mode, 1 : sequential mode
#ifdef CONFIG_RTK_KDRV_RPC
	u_int			winID;
	void			*mixer2;
#endif
	struct venusfb_rgb	rgb_info;
} VENUSFB_MACH_INFO;

struct venusfb_info {
	struct fb_info		fb;
	struct device		*dev;

	/*
	 * These are the addresses we mapped
	 * the framebuffer memory region to.
	 */

	char			*map_vir_addr;
	void			*map_phy_addr;
	u_int			map_size;

	VENUSFB_MACH_INFO	video_info;
	u_int			pseudo_palette[256];

	atomic_t 		ref_count;
	atomic_t		passive_mode;
};

#define SB2_GREG_START_0                                                             0x1801A500
#define SB2_GREG_START_1                                                             0x1801A504
#define SB2_GREG_START_2                                                             0x1801A508
#define SB2_GREG_START_3                                                             0x1801A50C
#define SB2_GREG_START_0_reg_addr                                                    "0xB801A500"
#define SB2_GREG_START_1_reg_addr                                                    "0xB801A504"
#define SB2_GREG_START_2_reg_addr                                                    "0xB801A508"
#define SB2_GREG_START_3_reg_addr                                                    "0xB801A50C"
#define SB2_GREG_START_0_reg                                                         0xB801A500
#define SB2_GREG_START_1_reg                                                         0xB801A504
#define SB2_GREG_START_2_reg                                                         0xB801A508
#define SB2_GREG_START_3_reg                                                         0xB801A50C
#define SB2_GREG_START_0_inst_adr                                                    "0x0040"
#define SB2_GREG_START_1_inst_adr                                                    "0x0041"
#define SB2_GREG_START_2_inst_adr                                                    "0x0042"
#define SB2_GREG_START_3_inst_adr                                                    "0x0043"
#define SB2_GREG_START_0_inst                                                        0x0040
#define SB2_GREG_START_1_inst                                                        0x0041
#define SB2_GREG_START_2_inst                                                        0x0042
#define SB2_GREG_START_3_inst                                                        0x0043
#define SB2_GREG_START_addr_shift                                                    (0)
#define SB2_GREG_START_addr_mask                                                     (0x0FFFFFFF)
#define SB2_GREG_START_addr(data)                                                    (0x0FFFFFFF&((data)<<0))
#define SB2_GREG_START_addr_src(data)                                                ((0x0FFFFFFF&(data))>>0)

#define SB2_GREG_END_0                                                               0x1801A510
#define SB2_GREG_END_1                                                               0x1801A514
#define SB2_GREG_END_2                                                               0x1801A518
#define SB2_GREG_END_3                                                               0x1801A51C
#define SB2_GREG_END_0_reg_addr                                                      "0xB801A510"
#define SB2_GREG_END_1_reg_addr                                                      "0xB801A514"
#define SB2_GREG_END_2_reg_addr                                                      "0xB801A518"
#define SB2_GREG_END_3_reg_addr                                                      "0xB801A51C"
#define SB2_GREG_END_0_reg                                                           0xB801A510
#define SB2_GREG_END_1_reg                                                           0xB801A514
#define SB2_GREG_END_2_reg                                                           0xB801A518
#define SB2_GREG_END_3_reg                                                           0xB801A51C
#define SB2_GREG_END_0_inst_adr                                                      "0x0044"
#define SB2_GREG_END_1_inst_adr                                                      "0x0045"
#define SB2_GREG_END_2_inst_adr                                                      "0x0046"
#define SB2_GREG_END_3_inst_adr                                                      "0x0047"
#define SB2_GREG_END_0_inst                                                          0x0044
#define SB2_GREG_END_1_inst                                                          0x0045
#define SB2_GREG_END_2_inst                                                          0x0046
#define SB2_GREG_END_3_inst                                                          0x0047
#define SB2_GREG_END_addr_shift                                                      (0)
#define SB2_GREG_END_addr_mask                                                       (0x0FFFFFFF)
#define SB2_GREG_END_addr(data)                                                      (0x0FFFFFFF&((data)<<0))
#define SB2_GREG_END_addr_src(data)                                                  ((0x0FFFFFFF&(data))>>0)

#define SB2_GREG_NO_SWAP                                                             0x1801A520
#define SB2_GREG_NO_SWAP_reg_addr                                                    "0xB801A520"
#define SB2_GREG_NO_SWAP_reg                                                         0xB801A520
#define SB2_GREG_NO_SWAP_inst_adr                                                    "0x0048"
#define SB2_GREG_NO_SWAP_inst                                                        0x0048
#define SB2_GREG_NO_SWAP_disable_shift                                               (0)
#define SB2_GREG_NO_SWAP_disable_mask                                                (0x00000001)
#define SB2_GREG_NO_SWAP_disable(data)                                               (0x00000001&((data)<<0))
#define SB2_GREG_NO_SWAP_disable_src(data)                                           ((0x00000001&(data))>>0)

/*
 * Minimum X and Y resolutions
 */

#define VENUS_FB_IOC_MAGIC		'f'
#define VENUS_FB_IOC_GET_MACHINE_INFO	_IOR(VENUS_FB_IOC_MAGIC, 1, struct venusfb_mach_info)
#define VENUS_FB_IOC_SET_OSD_STANDARD	_IO(VENUS_FB_IOC_MAGIC, 2)
#define VENUS_FB_IOC_GET_OSD_STATE	_IO(VENUS_FB_IOC_MAGIC, 3)
#define VENUS_FB_IOC_SET_OSD_STATE	_IO(VENUS_FB_IOC_MAGIC, 4)
#define VENUS_FB_IOC_MAXNR		8

#define VO_STANDARD_NTSC		0
#define VO_STANDARD_PAL			1
#define VO_STANDARD_HDTV_720		2
#define VO_STANDARD_HDTV_1080		3

#define MIN_XRES	256
#define MIN_YRES	64

#include "rtk_kdriver/gal/rtk_gdma_export.h"
#include "rtk_kdriver/gal/rtk_gdma_export_user.h"

#ifdef CONFIG_RTK_KDRV_RPC

#define S_OK		0x10000000
#define S_FAIL		0x10000000

#define RPCCMD_CONFIG_VIDEO_STANDARD	0
#define RPCCMD_CONFIG_HDMI		1
#define RPCCMD_SET_MIXER2_BUFFER	2
#define RPCCMD_CONFIG_GRAPHIC_CANVAS	3
#define RPCCMD_CREATE_GRAPHIC_WIN	4
#define RPCCMD_HIDE_GRAPHIC_WIN		5
#define RPCCMD_MODIFY_GRAPHIC_WIN	6
#define RPCCMD_DELETE_GRAPHIC_WIN	7
#define RPCCMD_DRAW_GRAPHIC_WIN		8
#define RPCCMD_DISPLAY_GRAPHIC		9
#define RPCCMD_CONFIG_OSD_PALETTE	10
#define RPCCMD_SET_OSD_WIN_PALETTE	11
#define RPCCMD_SET_BKGRND		12
#define RPCCMD_GET_MIXER_STATUS		13

enum VO_STANDARD {
	VO_STANDARD_NTSC_M		= 0,
	VO_STANDARD_NTSC_J		= 1,
	VO_STANDARD_NTSC_443		= 2,
	VO_STANDARD_PAL_B		= 3,
	VO_STANDARD_PAL_D		= 4,
	VO_STANDARD_PAL_G		= 5,
	VO_STANDARD_PAL_H		= 6,
	VO_STANDARD_PAL_I		= 7,
	VO_STANDARD_PAL_N		= 8,
	VO_STANDARD_PAL_NC		= 9,
	VO_STANDARD_PAL_M		= 10,
	VO_STANDARD_PAL_60		= 11,
	VO_STANDARD_SECAM		= 12,
	VO_STANDARD_HDTV_720P_60	= 13,
	VO_STANDARD_HDTV_720P_50	= 14,
	VO_STANDARD_HDTV_720P_30	= 15,
	VO_STANDARD_HDTV_720P_25	= 16,
	VO_STANDARD_HDTV_720P_24	= 17,
	VO_STANDARD_HDTV_1080I_60	= 18,
	VO_STANDARD_HDTV_1080I_50	= 19,
	VO_STANDARD_HDTV_1080P_30	= 20,
	VO_STANDARD_HDTV_1080P_25	= 21,
	VO_STANDARD_HDTV_1080P_24	= 22,
	VO_STANDARD_VGA			= 23,
	VO_STANDARD_SVGA		= 24,
	VO_STANDARD_HDTV_1080P_60	= 25,
	VO_STANDARD_HDTV_1080P_50	= 26,
	VO_STANDARD_HDTV_1080I_59	= 27,
	VO_STANDARD_HDTV_720P_59	= 28,
	VO_STANDARD_HDTV_1080P_23	= 29,
};
typedef enum VO_STANDARD VO_STANDARD;

enum VO_PEDESTAL_TYPE {
	VO_PEDESTAL_TYPE_300_700_ON	= 0,
	VO_PEDESTAL_TYPE_300_700_OFF	= 1,
	VO_PEDESTAL_TYPE_286_714_ON	= 2,
	VO_PEDESTAL_TYPE_286_714_OFF	= 3,
};
typedef enum VO_PEDESTAL_TYPE VO_PEDESTAL_TYPE;

enum VO_HDMI_MODE {
	VO_DVI_ON			= 0,
	VO_HDMI_ON			= 1,
	VO_HDMI_OFF			= 2,
};
typedef enum VO_HDMI_MODE VO_HDMI_MODE;

enum VO_HDMI_AUDIO_SAMPLE_FREQ {
	VO_HDMI_AUDIO_NULL		= 0,
	VO_HDMI_AUDIO_32K		= 1,
	VO_HDMI_AUDIO_44_1K		= 2,
	VO_HDMI_AUDIO_48K		= 3,
	VO_HDMI_AUDIO_88_2K		= 4,
	VO_HDMI_AUDIO_96K		= 5,
	VO_HDMI_AUDIO_176_4K		= 6,
	VO_HDMI_AUDIO_192K		= 7,
};
typedef enum VO_HDMI_AUDIO_SAMPLE_FREQ VO_HDMI_AUDIO_SAMPLE_FREQ;

enum VO_HDMI_COLOR_FMT {
	VO_HDMI_RGB444			= 0,
	VO_HDMI_YCbCr422		= 1,
	VO_HDMI_YCbCr444		= 2,
};
typedef enum VO_HDMI_COLOR_FMT VO_HDMI_COLOR_FMT;

struct VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD {
	enum VO_STANDARD		standard;
	u_char				enProg;
	u_char				enDIF;
	u_char				enCompRGB;
	enum VO_PEDESTAL_TYPE		pedType;
	u_int				dataInt0;
	u_int				dataInt1;
};
typedef struct VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD VIDEO_RPC_VOUT_CONFIG_VIDEO_STANDARD;

struct VIDEO_RPC_VOUT_CONFIG_HDMI {
	enum VO_HDMI_MODE		hdmiMode;
	enum VO_HDMI_AUDIO_SAMPLE_FREQ	audioSampleFreq;
	enum VO_HDMI_COLOR_FMT		colorFmt;
	u_char				audioChannelCount;
};
typedef struct VIDEO_RPC_VOUT_CONFIG_HDMI VIDEO_RPC_VOUT_CONFIG_HDMI;

struct VO_COLOR {
	u_char				c1;
	u_char				c2;
	u_char				c3;
	u_char				isRGB;
};
typedef struct VO_COLOR VO_COLOR;

struct VIDEO_RPC_VOUT_SET_BKGRND {
	struct VO_COLOR			bgColor;
	u_char				bgEnable;
};
typedef struct VIDEO_RPC_VOUT_SET_BKGRND VIDEO_RPC_VOUT_SET_BKGRND;

#define VO_OSD_WIN_POSITION		0x01
#define VO_OSD_WIN_COLORFMT		0x02
#define VO_OSD_WIN_COLORKEY		0x04
#define VO_OSD_WIN_ALPHA		0x08
#define VO_OSD_WIN_SRC_LOCATION		0x10
#define VO_OSD_WIN_STORAGE_TYPE		0x20

struct VIDEO_RPC_VOUT_SET_MIXER_ORDER
{
	u_char				pic;
	u_char				dd;
	u_char				v1;
	u_char				sub1;
	u_char				v2;
	u_char				osd1;
	u_char				osd2;
	u_char				csr;
	u_char				reserved1;
	u_char				reserved2;
	u_char				reserved3;
	u_char				reserved4;
	u_char				reserved5;
};
typedef struct VIDEO_RPC_VOUT_SET_MIXER_ORDER VIDEO_RPC_VOUT_SET_MIXER_ORDER;

#endif

#endif

