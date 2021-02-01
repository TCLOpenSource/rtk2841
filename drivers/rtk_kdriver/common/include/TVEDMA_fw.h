#ifndef _TVEDMA_FW_
#define _TVEDMA_FW_

#define TVEVDDMA_CTRL 0x1801f400
#define TVEVDDMA_CTRL_reg_addr "0x1801f400"
#define TVEVDDMA_CTRL_reg 0xb801f400
#define TVEVDDMA_CTRL_vddma_buf_ctrl(data) (0x00000010&((data)<<3))
#define TVEVDDMA_CTRL_vddma_buf_sel(data) (0x00000001&(data))
#define TVEVDDMA 0x1801f404
#define TVEVDDMA_reg_addr "0x1801f404"
#define TVEVDDMA_reg 0xb801f404
#define TVEVDDMA_vddma_waterlvl(data) (0x3F000000&((data)<<23))
#define TVEVDDMA_vddma_Num(data) (0x00FF0000&((data)<<15))
#define TVEVDDMA_vddma_length(data) (0x0000FF00&((data)<<7))
#define TVEVDDMA_vddma_remain(data) (0x000000FF&(data))

#define TVEVBIDMA_START 0x1801f424
#define TVEVBIDMA_START_reg_addr "0x1801f424"
#define TVEVBIDMA_START_reg 0xb801f424
#define TVEVBIDMA_START_vbidma_edge_trig(data) (0x20000000&((data)<<29))
#define TVEVBIDMA_START_vbidma_start_addr(data) (0x1FFFFFFF&(data))
#define TVEVBIDMA_CTRL 0x1801f420
#define TVEVBIDMA_CTRL_reg_addr "0x1801f420"
#define TVEVBIDMA_CTRL_reg 0xb801f420
#define TVEVBIDMA_CTRL_vbidma_endian(data) (0x00001000&((data)<<11))
#define TVEVBIDMA_CTRL_vbidma_buf_num(data) (0x00000F00&((data)<<7))
#define TVEVBIDMA_CTRL_vbidma_fetch_num(data) (0x00000010&((data)<<3))
#define TVEVBIDMA_CTRL_vbidma_total_line(data) (0x00000001&(data))
#define TVEVBIDMA_READ_WINDOW 0x1801f428
#define TVEVBIDMA_READ_WINDOW_reg_addr "0x1801f428"
#define TVEVBIDMA_READ_WINDOW_reg 0xb801f428
#define TVEVBIDMA_READ_WINDOW_vbi_read_start(data) (0x007FF000&((data)<<11))
#define TVEVBIDMA_READ_WINDOW_vbi_read_end(data) (0x000007FF&(data))

#endif
