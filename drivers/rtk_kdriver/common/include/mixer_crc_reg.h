#ifndef _mixer_crc_reg_h_included_
#define _MIXER_CRC_REG_H_INCLUDED_

#define MIXER_CRC_SEL_reg								0xB802B030
#define MIXER_CRC_SEL_mixer_crc_sel_mask				(0x00000007)
#define MIXER_CRC_SEL_mixer_crc_sel(data)				(0x00000007&((data)<<0))

#define MIXER_CRC_CTRL_reg								0xB802B034
#define MIXER_CRC_CTRL_mixer_crc_cnt_mask				(0x00000002)
#define MIXER_CRC_CTRL_mixer_crc_cnt(data)				(0x00000002&((data)<<1))
#define MIXER_CRC_CTRL_mixer_crc_start_mask				(0x00000001)
#define MIXER_CRC_CTRL_mixer_crc_start(data)			(0x00000001&((data)<<0))

#define MIXER_CRC_RESULT_reg							0xB802B038
#define MIXER_CRC_RESULT_mixer_crc_result_mask			0xffffffff
#define MIXER_CRC_RESULT_mixer_crc_result(data)			(0xffffffff&((data)<<0))
#endif	//end of #ifndef _mixer_crc_reg_h_included_

