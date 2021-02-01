/************************************************************************
 *
 *  flash_nand_profile.h
 *
 *  NAND flash profile structure
 * 
 *
 ************************************************************************/

#ifndef __FLASH_NAND_PROFILE_H__
#define __FLASH_NAND_PROFILE_H__

/************************************************************************
 *  Include files
 ************************************************************************/

/************************************************************************
 *  Definitions
*************************************************************************/
#define NAND_PROFILE_IDENTIFIER	"REALTEK."

#define ECC_6BIT		0x0
#define ECC_12BIT		0x1
#define ECC_24BIT		0x2

/************************************************************************
 *  Structures
*************************************************************************/
typedef struct{
	unsigned char	identifier[8];		/* byte   0 ~ 7  */
	unsigned int	revision;		/* byte   8 ~ 11 */
	unsigned char	extend_parameter;	/* byte  12 */
	unsigned char	reserved_1[3];		/* byte  13 ~ 15 */
	unsigned int	extend_block_number;	/* byte  16 ~ 19 */
	unsigned int	extend_page_number;	/* byte  20 ~ 23 */
	unsigned short	extend_page_length;	/* byte  24 ~ 25 */
	unsigned short 	number_of_page;		/* byte  26 ~ 27 */
	unsigned char	reserved_2[4];		/* byte  28 ~ 31 */

	unsigned char	manufacturer_id[12];	/* byte  32 ~ 43 */
	unsigned char   flash_name[16];		/* byte  44 ~ 59 */
	unsigned char	reserved_3[4];		/* byte  60 ~ 63 */

	unsigned int	number_of_bbt;		/* byte  64 ~ 67 */
	unsigned int	bbt_start_block;	/* byte  68 ~ 71 */
	unsigned int	bbt_end_block;		/* byte  72 ~ 75 */
	unsigned int	number_of_rsv_block;	/* byte  76 ~ 79 */
	unsigned int	rsv_start_block;	/* byte  80 ~ 83 */
	unsigned int	rsv_end_block;		/* byte  84 ~ 87 */
	unsigned int	data_per_page;		/* byte  88 ~ 91 */
	unsigned int	oob_per_page;		/* byte  92 ~ 95 */
	unsigned int	page_per_block;		/* byte  96 ~ 99 */
	unsigned int	block_per_die;		/* byte 100 ~ 103 */
	unsigned char	reserved_4[4];		/* byte 104 ~ 107 */
	unsigned short	ecc_bit;		/* byte 108 ~ 109 */
	unsigned int	param_t1;		/* byte 110 ~ 113 */
	unsigned int	param_t2;		/* byte 114 ~ 117 */
	unsigned int	param_t3;		/* byte 118 ~ 121 */
	unsigned int	param_t4;		/* byte 122 ~ 125 */
	unsigned char	address_mode;		/* byte 126 */
	unsigned char	reserved_5;		/* byte 127 */
	unsigned char   checksum[32];		/* byte 128 ~ 159 */
	unsigned char	reserved_6[96];		/* byte 160 ~ 225 */
} __attribute__((packed)) t_nand_profile;

#endif //#ifndef __FLASH_NAND_PROFILE_H__	
