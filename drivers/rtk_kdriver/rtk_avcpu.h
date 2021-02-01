#ifndef _LINUX_RTK_AVCPU_H
#define _LINUX_RTK_AVCPU_H

#include <generated/autoconf.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define AUDIO_CPU               1
#define VIDEO_CPU_1             2
#define VIDEO_CPU_2             3

#define AUDIO_ENTRY_ADDR        (PAGE_OFFSET+0xe0)
#define VIDEO_ENTRY_ADDR_1      (PAGE_OFFSET+0xe4)
#define VIDEO_ENTRY_ADDR_2      (PAGE_OFFSET+0xdc)

#define AVCPU_MAJOR             241

#define AVCPU_SUSPEND           100
#define AVCPU_RESUME            101
#define AVCPU_RESET_PREPARE     102
#define AVCPU_RESET_DONE        103

#define ACPU_STATUS_FLAG_ADDRESS	0x000000c8
#ifdef CONFIG_RTK_KDRV_SUPPORT_ACPU2
  #define ACPU2_STATUS_FLAG_ADDRESS       0x000001fc
#endif
#define VCPU_STATUS_FLAG_ADDRESS	0x00000814
#ifdef CONFIG_RTK_KDRV_SUPPORT_VCPU2
  #define VCPU2_STATUS_FLAG_ADDRESS	0x00000818
#endif
#define AVCPU_STATUS_FLAG_STD_ADDR	0x0000081C

#if defined(CONFIG_RTK_KDRV_SUPPORT_ACPU2) && defined(CONFIG_RTK_KDRV_SUPPORT_VCPU2)
	#define AVCPU_FLAG 0xf
#else
	#define AVCPU_FLAG 0x3
#endif

#ifdef CONFIG_PM
//#define SUPPORT_AV_NO_RELOAD use stravnoreload to control
#endif

int register_avcpu_notifier(struct notifier_block *nb);
int unregister_avcpu_notifier(struct notifier_block *nb);

typedef enum {
	FW_TYPE_RESERVED = 0,
	FW_TYPE_BOOTCODE,
	FW_TYPE_KERNEL,
	FW_TYPE_AUDIO,
	FW_TYPE_VIDEO,
	FW_TYPE_VIDEO_2,
	FW_TYPE_ECPU,
	FW_TYPE_JFFS2,
	FW_TYPE_SQUASH,
	FW_TYPE_EXT3,
	FW_TYPE_ODD,
	FW_TYPE_YAFFS2,
	FW_TYPE_AUDIO_FILE,
	FW_TYPE_VIDEO_FILE,
	FW_TYPE_IMAGE_FILE,
} fw_type_code_t;

typedef struct {
	char			*audio_image;
	unsigned int		audio_start;
	char			*video_image_1;
	unsigned int		video_start_1;
	char			*video_image_2;
	unsigned int		video_start_2;
} resetav_struct;

typedef struct {
	u8			signature[8];
	u32			checksum;
	u8			version;	//0x00
	u8			reserved[15];
	u32			length;
} __attribute__((packed)) fw_desc_table_t;

typedef struct {
	u8			signature[8];
	u32			checksum;
	u8			version;	//0x01
	u8			reserved[7];
	u32			paddings;
	u32			part_list_len;
	u32			fw_list_len;
} __attribute__((packed)) fw_desc_table_v1_t;

typedef struct {
	u8			type;
	u8			reserved:7,
				ro:1;
	u32			length;
	u8			fw_count;
	u8			reserved_1[9];
	u8			mount_point[32];
} __attribute__((packed)) part_desc_entry_v1_t;

typedef struct {
	u8			type;
	u8			reserved:6,
				lzma:1,
				ro:1;
	u32			version;
	u32			target_addr;
	u32			offset;
	u32			length;
	u32			paddings;
	u32			checksum;
	u8			reserved_1[6];
} __attribute__((packed)) fw_desc_entry_v1_t;

typedef struct {
	fw_desc_entry_v1_t	v1;
	u32			act_size;
	u8			hash[32];
	u8			part_num;
	u8			reserved[27];
} __attribute__((packed)) fw_desc_entry_v11_t;

typedef struct {
	fw_desc_entry_v1_t v1;
	u32			act_size;
	u8			part_num;
	u8			RSA_sign[256];
	u8			reserved[27];
} __attribute__((packed)) fw_desc_entry_v21_t;

/*
 * Ioctl definitions
 */

/* Use 'c' as magic number */
#define AVCPU_IOC_MAGIC  'c'

/*
 * S means "Set"                : through a ptr,
 * T means "Tell"               : directly with the argument value
 * G means "Get"                : reply by setting through a pointer
 * Q means "Query"              : response is on the return value
 * X means "eXchange"           : G and S atomically
 * H means "sHift"              : T and Q atomically
 */
#define AVCPU_IOCTRESET		_IOW(AVCPU_IOC_MAGIC, 1, resetav_struct)

#endif

