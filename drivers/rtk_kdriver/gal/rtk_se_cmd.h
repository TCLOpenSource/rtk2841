/******************************************************************************
*	Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
*
*	@author baker.cheng@realtek.com
*
******************************************************************************/
#ifndef _SE_CMD_H_
#define _SE_CMD_H_
typedef struct _SECMD_WRITE_REGISTER
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word1;
	struct
	{
		UINT32	RegisterValue;
	} Word2;

	struct
	{
		UINT32	Reserved;
	} Word3;

	struct
	{
		UINT32	Reserved;
	} Word4;
	struct
	{
		UINT32	Reserved;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
	struct
	{
		UINT32	Reserved;
	} Word7;
	struct
	{
		UINT32	Reserved;
	} Word8;
} SECMD_WRITE_REGISTER;

typedef struct _SECMD_WRITE_REGISTER2
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word1;
	struct
	{
		UINT32	RegisterValue;
	} Word2;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word3;
	struct
	{
		UINT32	RegisterValue;
	} Word4;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word5;
	struct
	{
		UINT32	RegisterValue;
	} Word6;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word7;
	struct
	{
		UINT32	RegisterValue;
	} Word8;
} SECMD_WRITE_REGISTER2;

typedef struct _SECMD_WRITE_CLUT
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word1;
	struct
	{
		UINT32	RegisterValue;
	} Word2;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} Word3;

	struct
	{
		UINT32	RegisterValue;
	} Word4;
} SECMD_WRITE_CLUT;

typedef struct _SECMD_FETCH_CLUT
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	FetchEntry: 2;
		UINT32	Force_load_clut: 1;
		UINT32	Reserved: 25;
	} Word1;
	struct
	{
		UINT32	StartingAddress: 31;
		UINT32	Reserved: 1;
	} Word2;
	struct
	{
		UINT32	Reserved;
	} Word3;
	struct
	{
		UINT32	Reserved;
	} Word4;
	struct
	{
		UINT32	Reserved;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
	struct
	{
		UINT32	Reserved;
	} Word7;
	struct
	{
		UINT32	Reserved;
	} Word8;
} SECMD_FETCH_CLUT;
typedef struct _SECMD_LOCK_CLUT
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	Lock_clut: 1;
		UINT32	Reserved: 27;
	} Word1;
	struct
	{
		UINT32	Reserved;
	} Word2;
	struct
	{
		UINT32	Reserved;
	} Word3;
	struct
	{
		UINT32	Reserved;
	} Word4;
	struct
	{
		UINT32	Reserved;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
	struct
	{
		UINT32	Reserved;
	} Word7;
	struct
	{
		UINT32	Reserved;
	} Word8;
} SECMD_LOCK_CLUT;
typedef struct _SECMD_FORMAT_CONVERSION
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg5;
	struct
	{
		UINT32	RegisterValue;
	} WordReg5_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg6;
	struct
	{
		UINT32	RegisterValue;
	} WordReg6_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	Width: 12;
		UINT32	Height: 12;
		UINT32	SelectOutputAlpha: 1;
		UINT32	ColorKey: 1;
		UINT32	ConversionMode: 2;
	} Word1;
	struct
	{
		UINT32	Reserved: 1;
		UINT32	YUV422SeqEnable: 1;
		UINT32	ARGB8888MatrixEnable: 1;
		UINT32	directFB: 1;
		UINT32	FormatConversionBitblit: 1;
		UINT32	InputX: 12;
		UINT32	InputY: 12;
		UINT32	SourceFormat: 3;
	} Word2;
	struct
	{
		UINT32	Reserved: 5;
		UINT32	OutputX: 12;
		UINT32	OutputY: 12;
		UINT32	DestinationFormat: 3;
	} Word3;
	struct
	{
		UINT32	Reserved: 9;
		UINT32	ROPCode1: 2;
		UINT32	ChromaAddressIndex: 7;
		UINT32	DestAddressIndex: 7;
		UINT32	SrcAddressIndex: 7;
	} Word4;
	struct
	{
		UINT32	fb_sel_destclr_blend: 4;
		UINT32	fb_sel_srcclr_blend: 4;
		UINT32	fb_demultiply: 1;
		UINT32	fb_blend_alphachannel: 1;
		UINT32	fb_blend_coloralpha: 1;
		UINT32	fb_colorize: 1;
		UINT32	fb_xor: 1;
		UINT32	fb_src_premultiply: 1;
		UINT32	fb_src_premulcolor: 1;
		UINT32	fb_dst_premultiply: 1;
		UINT32	src_clr_transparency: 1;
		UINT32	src_clr_transform: 2;
		UINT32	rop_mode: 1;
		UINT32	bitblit_color_key: 2;
		UINT32	sel_src_alpha: 3;
		UINT32	rop_code: 2;
		UINT32	sel_output_alpha: 1;
		UINT32	sync_vo: 1;
		UINT32	sel_dest_alpha: 3;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
	struct
	{
		UINT32	Reserved;
	} Word7;
	struct
	{
		UINT32	Reserved;
	} Word8;
} SECMD_FORMAT_CONVERSION;
typedef struct _SECMD_BITBLT
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg5;
	struct
	{
		UINT32	RegisterValue;
	} WordReg5_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg6;
	struct
	{
		UINT32	RegisterValue;
	} WordReg6_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg7;
	struct
	{
		UINT32	RegisterValue;
	} WordReg7_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg8;
	struct
	{
		UINT32	RegisterValue;
	} WordReg8_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg9;
	struct
	{
		UINT32	RegisterValue;
	} WordReg9_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg10;
	struct
	{
		UINT32	RegisterValue;
	} WordReg10_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	Width: 12;
		UINT32	Height: 12;
		UINT32	InputSelect: 1;
		UINT32	SelectDestAlpha: 3;
	} Word1;
	struct
	{
		UINT32	OutputX: 12;
		UINT32	OutputY: 12;
		UINT32	StartingCorner: 2;
		UINT32	RopCode: 2;
		UINT32	SelectOutputAlpha: 1;
		UINT32	sync_vo: 1;
		UINT32	DestAddressIndex: 2;
	} Word2;
	struct
	{
		UINT32	InputX: 12;
		UINT32	InputY: 12;
		UINT32	RopMode: 1;
		UINT32	ColorKey: 2;
		UINT32	SelectSrcAlpha: 3;
		UINT32	SrcAddressIndex: 2;
	} Word3;
	struct
	{
		UINT32	Reserved: 9;
		UINT32	alpha_stream_mode: 1;
		UINT32	ROPCode1: 2;
		UINT32	fb_sel_destclr_blend: 4;
		UINT32	fb_sel_srcclr_blend: 4;
		UINT32	fb_demultiply: 1;
		UINT32	fb_blend_alphachannel: 1;
		UINT32	fb_blend_coloralpha: 1;
		UINT32	fb_colorize: 1;
		UINT32	fb_xor: 1;
		UINT32	fb_src_premultiply: 1;
		UINT32	fb_src_premulcolor: 1;
		UINT32	fb_dst_premultiply: 1;
		UINT32	directFB: 1;
		UINT32	src_clr_transparency: 1;
		UINT32	src_clr_transform: 2;
	} Word4;
	struct
	{
		UINT32	Reserved;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
	struct
	{
		UINT32	Reserved;
	} Word7;
	struct
	{
		UINT32	Reserved;
	} Word8;
} SECMD_BITBLT;
typedef struct _SECMD_STRETCH
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg5;
	struct
	{
		UINT32	RegisterValue;
	} WordReg5_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg6;
	struct
	{
		UINT32	RegisterValue;
	} WordReg6_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg7;
	struct
	{
		UINT32	RegisterValue;
	} WordReg7_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg8;
	struct
	{
		UINT32	RegisterValue;
	} WordReg8_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg9;
	struct
	{
		UINT32	RegisterValue;
	} WordReg9_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg10;
	struct
	{
		UINT32	RegisterValue;
	} WordReg10_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	OutputX: 12;
		UINT32	OutputY: 12;
		UINT32	ColorKey: 1;
		UINT32	HScalingEnable: 1;
		UINT32	VScalingEnable: 1;
		UINT32	SrcInterleaving: 1;
	} Word1;
	struct
	{
		UINT32	OutputWidth: 12;
		UINT32	OutputHeight: 12;
		UINT32	StretchBitblit: 1;
		UINT32	directFB: 1;
		UINT32	Reserved: 4;
		UINT32	ScalingAlgorithm: 2;
	} Word2;
	struct
	{
		UINT32	InputX: 12;
		UINT32	InputY: 12;
		UINT32	DestInterleaving: 1;
		UINT32	SrcAddressIndex: 7;
	} Word3;
	struct
	{
		UINT32	InputWidth: 13;
		UINT32	InputHeight: 12;
		UINT32	DestAddressIndex: 7;
	} Word4;
	struct
	{
		UINT32	fb_sel_destclr_blend: 4;
		UINT32	fb_sel_srcclr_blend: 4;
		UINT32	fb_demultiply: 1;
		UINT32	fb_blend_alphachannel: 1;
		UINT32	fb_blend_coloralpha: 1;
		UINT32	fb_colorize: 1;
		UINT32	fb_xor: 1;
		UINT32	fb_src_premultiply: 1;
		UINT32	fb_src_premulcolor: 1;
		UINT32	fb_dst_premultiply: 1;
		UINT32	src_clr_transparency: 1;
		UINT32	src_clr_transform: 2;
		UINT32	rop_mode: 1;
		UINT32	bitblit_color_key: 2;
		UINT32	sel_src_alpha: 3;
		UINT32	rop_code: 2;
		UINT32	sel_output_alpha: 1;
		UINT32	sync_vo: 1;
		UINT32	sel_dest_alpha: 3;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
	struct
	{
		UINT32	Reserved;
	} Word7;
	struct
	{
		UINT32	Reserved;
	} Word8;
} SECMD_STRETCH;
typedef struct _SECMD_MIRROR
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	OutputX: 12;
		UINT32	OutputY: 12;
		UINT32	MirrorDirection: 2;
		UINT32	DestAddressIndex: 2;
	} Word1;
	struct
	{
		UINT32	Width: 12;
		UINT32	Height: 12;
		UINT32	Reserved: 8;
	} Word2;
	struct
	{
		UINT32	Reserved1: 4;
		UINT32	InputX: 12;
		UINT32	InputY: 12;
		UINT32	Reserved2: 2;
		UINT32	SrcAddressIndex: 2;
	} Word3;
	struct
	{
		UINT32	Reserved;
	} Word4;
	struct
	{
		UINT32	Reserved;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
} SECMD_MIRROR;
typedef struct _SECMD_ROTATE
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	Reserved1: 25;
				UINT32	BlockModeOutput: 1;
		UINT32	RotateMode: 2;
	} Word1;
	struct
	{
		UINT32	InputX: 12;
		UINT32	InputY: 12;
		UINT32	Reserved: 1;
		UINT32	SrcAddressIndex: 7;
	} Word2;
	struct
	{
		UINT32	OutputX: 12;
		UINT32	OutputY: 12;
		UINT32	Reserved: 1;
		UINT32	DestAddressIndex: 7;
	} Word3;
	struct
	{
		UINT32	InputWidth: 12;
		UINT32	Reserved1: 4;
		UINT32	InputHeight: 12;
		UINT32	Reserved2: 4;
	} Word4;
	struct
	{
		UINT32	Reserved;
	} Word5;
	struct
	{
		UINT32	Reserved;
	} Word6;
} SECMD_ROTATE;
typedef struct _SECMD_NOP
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	Reserved: 28;
	} Word1;
} SECMD_NOP;
typedef struct _SECMD_EXT_FMT_CONV_BLIT
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg5;
	struct
	{
		UINT32	RegisterValue;
	} WordReg5_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg6;
	struct
	{
		UINT32	RegisterValue;
	} WordReg6_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg7;
	struct
	{
		UINT32	RegisterValue;
	} WordReg7_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg8;
	struct
	{
		UINT32	RegisterValue;
	} WordReg8_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg9;
	struct
	{
		UINT32	RegisterValue;
	} WordReg9_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg10;
	struct
	{
		UINT32	RegisterValue;
	} WordReg10_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr2;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch2;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr3;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch3;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch3_1;
	struct
	{
		UINT32	opcode: 4;
		UINT32	rslt_fmt: 5;
		UINT32	lay_ctl: 1;
		UINT32	lay_num: 1;
		UINT32	reserved0: 1;
		UINT32	rslt_swp_chr: 2;
		UINT32	src_swp_chr: 2;
		UINT32	itu_en: 1;
		UINT32	reserved1: 1;
		UINT32	rslt_matx_en: 1;
		UINT32	out_alpha: 1;
		UINT32	rslt_argb_order: 5;
		UINT32	reserved2: 1;
		UINT32	src2_argb_order: 5;
		UINT32	reserved3: 1;
	} Word1;
	struct
	{
		UINT32	rslt_out_x: 13;
		UINT32	rslt_out_y: 13;
		UINT32	reserved0: 2;
		UINT32  rslt_rotate: 2;
		UINT32  rslt_mirror: 2;
	} Word2;
	struct
	{
		UINT32	rslt_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	rslt_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	rslt_addr_index: 7;
		UINT32	rslt_blk_mode_interleave: 1;
		UINT32	reserved2: 8;
	} Word3;
	struct
	{
		UINT32	src1_inpt_w: 13;
		UINT32	src1_inpt_h: 13;
		UINT32	src1_fmt: 5;
		UINT32	src1_mat_en: 1;
	} Word4;
	struct
	{
		UINT32	src1_inpt_x: 13;
		UINT32	src1_inpt_y: 13;
		UINT32	src1_argb_order: 5;
		UINT32	src1_fcv_stch: 1;
	} Word5;
	struct
	{
		UINT32	src1_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src1_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src1_addr_index: 7;
		UINT32	src1_blk_mode_interleave: 1;
		UINT32	src1_inpt_sel: 1;
		UINT32	src1_lg_en: 1;
		UINT32	reserved2: 6;
	} Word6;
	struct
	{
		UINT32	src2_inpt_x: 13;
		UINT32	src2_inpt_y: 13;
		UINT32	src2_fmt: 5;
		UINT32	src2_mat_en: 1;
	} Word7;
	struct
	{
		UINT32	src2_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src2_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src2_addr_index: 7;
		UINT32	src2_blk_mode_interleave: 1;
		UINT32	src2_inpt_sel: 1;
		UINT32	src2_swp_chr: 2;
		UINT32	src2_clip_10b: 1;
		UINT32	reserved2: 4;
	} Word8;
	struct
	{
		UINT32	sel_s2_alpha: 3;
		UINT32	reserved0: 1;
		UINT32	sel_s1_alpha: 3;
		UINT32	reserved1: 1;
		UINT32	lay_num_ext: 3;
		UINT32	reserved2: 21;
	} Word9;
	struct
	{
		UINT32	rop_code_1: 4;
		UINT32	fb_sel_destclr_blend_1: 4;
		UINT32	fb_sel_srcclr_blend_1: 4;
		UINT32	fb_demultiply_1: 1;
		UINT32	fb_blend_alphachannel_1: 1;
		UINT32	fb_blend_coloralpha_1: 1;
		UINT32	fb_colorize_1: 1;
		UINT32	fb_xor_1: 1;
		UINT32	fb_src_premultiply_1: 1;
		UINT32	fb_src_premulcolor_1: 1;
		UINT32	fb_dst_premultiply_1: 1;
		UINT32	src_clr_transparency_1: 1;
		UINT32	src_clr_transform_1: 2;
		UINT32	reserved0: 2;
		UINT32	color_key_1: 2;
		UINT32	blend_sel_1: 4;
		UINT32	reserved1: 1;
	} Word10;
	struct
	{
		UINT32	gl_sel_destclr_1: 6;
		UINT32	reserved0: 2;
		UINT32	gl_sel_srctclr_1: 6;
		UINT32	reserved1: 2;
		UINT32	gl_sel_destalpha_1: 6;
		UINT32	reserved2: 2;
		UINT32	gl_sel_srctalpha_1: 6;
		UINT32	reserved3: 2;
	} Word11;
	struct
	{
		UINT32	Reserved: 32;
	} Word12;
	struct
	{
		UINT32	Reserved: 32;
	} Word13;
	struct
	{
		UINT32	Reserved: 32;
	} Word14;
	struct
	{
		UINT32	Reserved: 32;
	} Word15;
	struct
	{
		UINT32	Reserved: 32;
	} Word16;
} SECMD_EXT_FMT_CONV_BLIT;

typedef struct _SECMD_EXT_FMT_CONV_ROP
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr2;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch2;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr3;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch3;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch3_1;
	struct
	{
		UINT32	opcode: 4;
		UINT32	rslt_fmt: 5;
		UINT32	lay_ctl: 1;
		UINT32	lay_num: 1;
		UINT32	reserved0: 1;
		UINT32	rslt_swp_chr: 2;
		UINT32	src_swp_chr: 2;
		UINT32	itu_en: 1;
		UINT32	reserved1: 1;
		UINT32	rslt_matx_en: 1;
		UINT32	out_alpha: 1;
		UINT32	rslt_argb_order: 5;
		UINT32	reserved2: 1;
		UINT32	src2_argb_order: 5;
		UINT32	reserved3: 1;
	} Word1;
	struct
	{
		UINT32	rslt_out_x: 13;
		UINT32	rslt_out_y: 13;
		UINT32	reserved0: 2;
		UINT32  rslt_rotate: 2;
		UINT32  rslt_mirror: 2;
	} Word2;
	struct
	{
		UINT32	rslt_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	rslt_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	rslt_addr_index: 7;
		UINT32	rslt_blk_mode_interleave: 1;
		UINT32	reserved2: 8;
	} Word3;
	struct
	{
		UINT32	src1_inpt_w: 13;
		UINT32	src1_inpt_h: 13;
		UINT32	src1_fmt: 5;
		UINT32	src1_mat_en: 1;
	} Word4;
	struct
	{
		UINT32	src1_inpt_x: 13;
		UINT32	src1_inpt_y: 13;
		UINT32	src1_argb_order: 5;
		UINT32	src1_fcv_stch: 1;
	} Word5;
	struct
	{
		UINT32	src1_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src1_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src1_addr_index: 7;
		UINT32	src1_blk_mode_interleave: 1;
		UINT32	src1_inpt_sel: 1;
		UINT32	src1_lg_en: 1;
		UINT32	reserved2: 6;
	} Word6;
	struct
	{
		UINT32	src2_inpt_x: 13;
		UINT32	src2_inpt_y: 13;
		UINT32	src2_fmt: 5;
		UINT32	src2_mat_en: 1;
	} Word7;
	struct
	{
		UINT32	src2_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src2_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src2_addr_index: 7;
		UINT32	src2_blk_mode_interleave: 1;
		UINT32	src2_inpt_sel: 1;
		UINT32	src2_swp_chr: 2;
		UINT32	src2_clip_10b: 1;
		UINT32	reserved2: 4;
	} Word8;
	struct
	{
		UINT32	sel_s2_alpha: 3;
		UINT32	reserved0: 1;
		UINT32	sel_s1_alpha: 3;
		UINT32	reserved1: 1;
		UINT32	lay_num_ext: 3;
		UINT32	reserved2: 21;
	} Word9;
	struct
	{
		UINT32	rop_code_1: 4;
		UINT32	fb_sel_destclr_blend_1: 4;
		UINT32	fb_sel_srcclr_blend_1: 4;
		UINT32	fb_demultiply_1: 1;
		UINT32	fb_blend_alphachannel_1: 1;
		UINT32	fb_blend_coloralpha_1: 1;
		UINT32	fb_colorize_1: 1;
		UINT32	fb_xor_1: 1;
		UINT32	fb_src_premultiply_1: 1;
		UINT32	fb_src_premulcolor_1: 1;
		UINT32	fb_dst_premultiply_1: 1;
		UINT32	src_clr_transparency_1: 1;
		UINT32	src_clr_transform_1: 2;
		UINT32	reserved0: 2;
		UINT32	color_key_1: 2;
		UINT32	blend_sel_1: 4;
		UINT32	reserved1: 1;
	} Word10;
	struct
	{
		UINT32	gl_sel_destclr_1: 6;
		UINT32	reserved0: 2;
		UINT32	gl_sel_srctclr_1: 6;
		UINT32	reserved1: 2;
		UINT32	gl_sel_destalpha_1: 6;
		UINT32	reserved2: 2;
		UINT32	gl_sel_srctalpha_1: 6;
		UINT32	reserved3: 2;
	} Word11;
	struct
	{
		UINT32	Reserved: 32;
	} Word12;
	struct
	{
		UINT32	Reserved: 32;
	} Word13;
	struct
	{
		UINT32	Reserved: 32;
	} Word14;
	struct
	{
		UINT32	Reserved: 32;
	} Word15;
	struct
	{
		UINT32	Reserved: 32;
	} Word16;
} SECMD_EXT_FMT_CONV_ROP;

typedef struct _SECMD_EXT_STCH_BLIT
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg5;
	struct
	{
		UINT32	RegisterValue;
	} WordReg5_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg6;
	struct
	{
		UINT32	RegisterValue;
	} WordReg6_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg7;
	struct
	{
		UINT32	RegisterValue;
	} WordReg7_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg8;
	struct
	{
		UINT32	RegisterValue;
	} WordReg8_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg9;
	struct
	{
		UINT32	RegisterValue;
	} WordReg9_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg10;
	struct
	{
		UINT32	RegisterValue;
	} WordReg10_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg11;
	struct
	{
		UINT32	RegisterValue;
	} WordReg11_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg12;
	struct
	{
		UINT32	RegisterValue;
	} WordReg12_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr2;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch2;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr3;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch3;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch3_1;
	struct
	{
		UINT32	opcode: 4;
		UINT32	rslt_fmt: 5;
		UINT32	lay_ctl: 1;
		UINT32	lay_num: 1;
		UINT32	reserved0: 1;
		UINT32	rslt_swp_chr: 2;
		UINT32	src_swp_chr: 2;
		UINT32	itu_en: 1;
		UINT32	reserved1: 1;
		UINT32	rslt_matx_en: 1;
		UINT32	out_alpha: 1;
		UINT32	rslt_argb_order: 5;
		UINT32	reserved2: 1;
		UINT32	src2_argb_order: 5;
		UINT32	reserved3: 1;
	} Word1;
	struct
	{
		UINT32	rslt_out_x: 13;
		UINT32	rslt_out_y: 13;
		UINT32	reserved0: 2;
		UINT32  rslt_rotate: 2;
		UINT32  rslt_mirror: 2;
	} Word2;
	struct
	{
		UINT32	rslt_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	rslt_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	rslt_addr_index: 7;
		UINT32	rslt_blk_mode_interleave: 1;
		UINT32	reserved2: 8;
	} Word3;
	struct
	{
		UINT32	src1_inpt_w: 13;
		UINT32	src1_inpt_h: 13;
		UINT32	src1_fmt: 5;
		UINT32	src1_mat_en: 1;
	} Word4;
	struct
	{
		UINT32	src1_inpt_x: 13;
		UINT32	src1_inpt_y: 13;
		UINT32	src1_argb_order: 5;
		UINT32	src1_fcv_stch: 1;
	} Word5;
	struct
	{
		UINT32	src1_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src1_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src1_addr_index: 7;
		UINT32	src1_blk_mode_interleave: 1;
		UINT32	src1_inpt_sel: 1;
		UINT32	src1_lg_en: 1;
		UINT32	reserved2: 6;
	} Word6;
	struct
	{
		UINT32	src2_inpt_x: 13;
		UINT32	src2_inpt_y: 13;
		UINT32	src2_fmt: 5;
		UINT32	src2_mat_en: 1;
	} Word7;
	struct
	{
		UINT32	src2_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src2_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src2_addr_index: 7;
		UINT32	src2_blk_mode_interleave: 1;
		UINT32	src2_inpt_sel: 1;
		UINT32	src2_swp_chr: 2;
		UINT32	src2_clip_10b: 1;
		UINT32	reserved2: 4;
	} Word8;
	struct
	{
		UINT32	sel_s2_alpha: 3;
		UINT32	reserved0: 1;
		UINT32	sel_s1_alpha: 3;
		UINT32	reserved1: 1;
		UINT32	lay_num_ext: 3;
		UINT32	reserved2: 21;
	} Word9;
	struct
	{
		UINT32	rop_code_1: 4;
		UINT32	fb_sel_destclr_blend_1: 4;
		UINT32	fb_sel_srcclr_blend_1: 4;
		UINT32	fb_demultiply_1: 1;
		UINT32	fb_blend_alphachannel_1: 1;
		UINT32	fb_blend_coloralpha_1: 1;
		UINT32	fb_colorize_1: 1;
		UINT32	fb_xor_1: 1;
		UINT32	fb_src_premultiply_1: 1;
		UINT32	fb_src_premulcolor_1: 1;
		UINT32	fb_dst_premultiply_1: 1;
		UINT32	src_clr_transparency_1: 1;
		UINT32	src_clr_transform_1: 2;
		UINT32	reserved0: 2;
		UINT32	color_key_1: 2;
		UINT32	blend_sel_1: 4;
		UINT32	reserved1: 1;
	} Word10;
	struct
	{
		UINT32	gl_sel_destclr_1: 6;
		UINT32	reserved0: 2;
		UINT32	gl_sel_srctclr_1: 6;
		UINT32	reserved1: 2;
		UINT32	gl_sel_destalpha_1: 6;
		UINT32	reserved2: 2;
		UINT32	gl_sel_srctalpha_1: 6;
		UINT32	reserved3: 2;
	} Word11;
	struct
	{
		UINT32	stch1_out_w: 13;
		UINT32	stch1_out_h: 13;
		UINT32	stch1_src: 3;
		UINT32	stch1_h_en: 1;
		UINT32	stch1_v_en: 1;
		UINT32	stch1_algo: 1;
	} Word12;
	struct
	{
		UINT32	src2_inpt_w: 13;
		UINT32	src2_inpt_h: 13;
		UINT32	Reserved: 6;
	} Word13;
	struct
	{
		UINT32	src2_out_x: 13;
		UINT32	src2_out_y: 13;
		UINT32	Reserved: 6;
	} Word14;
	struct
	{
		UINT32	stch2_out_w: 13;
		UINT32	stch2_out_h: 13;
		UINT32	stch2_src: 3;
		UINT32	stch2_h_en: 1;
		UINT32	stch2_v_en: 1;
		UINT32	stch2_algo: 1;
	} Word15;
	struct
	{
		UINT32	Reserved: 32;
	} Word16;
#if SE_SE20
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DReg1;
	struct
	{
		UINT32	RegisterValue;
	} DReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DReg2;
	struct
	{
		UINT32	RegisterValue;
	} DReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DReg3;
	struct
	{
		UINT32	RegisterValue;
	} DReg3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DReg4;
	struct
	{
		UINT32	RegisterValue;
	} DReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DReg5;
	struct
	{
		UINT32	RegisterValue;
	} DReg5_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DReg6;
	struct
	{
		UINT32	RegisterValue;
	} DReg6_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DAddr0;
	struct
	{
		UINT32	RegisterValue;
	} DAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DPitch0;
	struct
	{
		UINT32	RegisterValue;
	} DPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DAddr1;
	struct
	{
		UINT32	RegisterValue;
	} DAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} DPitch1;
	struct
	{
		UINT32	RegisterValue;
	} DPitch1_1;
	struct
	{
		UINT32	opcode: 4;
		UINT32	rslt_fmt: 5;
		UINT32	lay_ctl: 1;
		UINT32	lay_num: 1;
		UINT32	sync_vo: 1;
		UINT32	rslt_swp_chr: 2;
		UINT32	src_swp_chr: 2;
		UINT32	itu_en: 1;
		UINT32	clip_10b: 1;
		UINT32	rslt_matx_en: 1;
		UINT32	out_alpha: 1;
		UINT32	rslt_argb_order: 5;
		UINT32	reserved0: 1;
		UINT32	src2_argb_order: 5;
		UINT32	two_dc_mode: 1;
	} DWord1;
	struct
	{
		UINT32	rslt_out_x: 13;
		UINT32	rslt_out_y: 13;
		UINT32	reserved0: 6;
	} DWord2;
	struct
	{
		UINT32	rslt_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	rslt_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	rslt_addr_index: 7;
		UINT32	rslt_blk_mode_interleave: 1;
		UINT32	reserved2: 8;
	} DWord3;
	struct
	{
		UINT32	src1_inpt_w: 13;
		UINT32	src1_inpt_h: 13;
		UINT32	src1_fmt: 5;
		UINT32	src1_mat_en: 1;
	} DWord4;
	struct
	{
		UINT32	src1_inpt_x: 13;
		UINT32	src1_inpt_y: 13;
		UINT32	src1_argb_order: 5;
		UINT32	src1_fcv_stch: 1;
	} DWord5;
	struct
	{
		UINT32	src1_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src1_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src1_addr_index: 7;
		UINT32	src1_blk_mode_interleave: 1;
		UINT32	src1_inpt_sel: 1;
		UINT32	reserved2: 7;
	} DWord6;
	struct
	{
		UINT32	src2_inpt_x: 13;
		UINT32	src2_inpt_y: 13;
		UINT32	src2_fmt: 5;
		UINT32	src2_mat_en: 1;
	} DWord7;
	struct
	{
		UINT32	src2_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src2_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src2_addr_index: 7;
		UINT32	src2_blk_mode_interleave: 1;
		UINT32	src2_inpt_sel: 1;
		UINT32	src2_swp_chr: 2;
		UINT32	src2_clip_10b: 1;
		UINT32	reserved2: 4;
	} DWord8;
	struct
	{
		UINT32	sel_s2_alpha: 3;
		UINT32	reserved0: 1;
		UINT32	sel_s1_alpha: 3;
		UINT32	reserved1: 1;
		UINT32	lay_num_ext: 3;
		UINT32	reserved2: 21;
	} DWord9;
	struct
	{
		UINT32	rop_code_1: 4;
		UINT32	fb_sel_destclr_blend_1: 4;
		UINT32	fb_sel_srcclr_blend_1: 4;
		UINT32	fb_demultiply_1: 1;
		UINT32	fb_blend_alphachannel_1: 1;
		UINT32	fb_blend_coloralpha_1: 1;
		UINT32	fb_colorize_1: 1;
		UINT32	fb_xor_1: 1;
		UINT32	fb_src_premultiply_1: 1;
		UINT32	fb_src_premulcolor_1: 1;
		UINT32	fb_dst_premultiply_1: 1;
		UINT32	src_clr_transparency_1: 1;
		UINT32	src_clr_transform_1: 2;
		UINT32	reserved0: 2;
		UINT32	color_key_1: 2;
		UINT32	blend_sel_1: 4;
		UINT32	reserved1: 1;
	} DWord10;
	struct
	{
		UINT32	gl_sel_destclr_1: 6;
		UINT32	reserved0: 2;
		UINT32	gl_sel_srctclr_1: 6;
		UINT32	reserved1: 2;
		UINT32	gl_sel_destalpha_1: 6;
		UINT32	reserved2: 2;
		UINT32	gl_sel_srctalpha_1: 6;
		UINT32	reserved3: 2;
	} DWord11;
	struct
	{
		UINT32	stch1_out_w: 13;
		UINT32	stch1_out_h: 13;
		UINT32	stch1_src: 3;
		UINT32	stch1_h_en: 1;
		UINT32	stch1_v_en: 1;
		UINT32	stch1_algo: 1;
	} DWord12;
	struct
	{
		UINT32	src2_inpt_w: 13;
		UINT32	src2_inpt_h: 13;
		UINT32	Reserved: 6;
	} DWord13;
	struct
	{
		UINT32	src2_out_x: 13;
		UINT32	src2_out_y: 13;
		UINT32	Reserved: 6;
	} DWord14;
	struct
	{
		UINT32	stch2_out_w: 13;
		UINT32	stch2_out_h: 13;
		UINT32	stch2_src: 3;
		UINT32	stch2_h_en: 1;
		UINT32	stch2_v_en: 1;
		UINT32	stch2_algo: 1;
	} DWord15;
	struct
	{
		UINT32	Reserved: 32;
	} DWord16;
#endif
} SECMD_EXT_STCH_BLIT;

typedef struct _SECMD_EXT_FMT_CONV
{
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg1;
	struct
	{
		UINT32	RegisterValue;
	} WordReg1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg2;
	struct
	{
		UINT32	RegisterValue;
	} WordReg2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg3;
	struct
	{
		UINT32	RegisterValue;
	} WordReg3_1;

	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordReg4;
	struct
	{
		UINT32	RegisterValue;
	} WordReg4_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr0;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch0;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch0_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr1;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch1;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch1_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr2;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch2;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch2_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordAddr3;
	struct
	{
		UINT32	RegisterValue;
	} WordAddr3_1;
	struct
	{
		UINT32	OpCode: 4;
		UINT32	RegisterAddress: 12;
		UINT32	Clut: 1;
		UINT32	Reserved: 15;
	} WordPitch3;
	struct
	{
		UINT32	RegisterValue;
	} WordPitch3_1;
	struct
	{
		UINT32	opcode: 4;
		UINT32	rslt_fmt: 5;
		UINT32	lay_ctl: 1;
		UINT32	lay_num: 1;
		UINT32	reserved0: 1;
		UINT32	rslt_swp_chr: 2;
		UINT32	src_swp_chr: 2;
		UINT32	itu_en: 1;
		UINT32	reserved1: 1;
		UINT32	rslt_matx_en: 1;
		UINT32	out_alpha: 1;
		UINT32	rslt_argb_order: 5;
		UINT32	reserved2: 1;
		UINT32	src2_argb_order: 5;
		UINT32	reserved3: 1;
	} Word1;
	struct
	{
		UINT32	rslt_out_x: 13;
		UINT32	rslt_out_y: 13;
		UINT32	reserved0: 2;
		UINT32  rslt_rotate: 2;
		UINT32  rslt_mirror: 2;
	} Word2;
	struct
	{
		UINT32	rslt_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	rslt_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	rslt_addr_index: 7;
		UINT32	rslt_blk_mode_interleave: 1;
		UINT32	reserved2: 8;
	} Word3;
	struct
	{
		UINT32	src1_inpt_w: 13;
		UINT32	src1_inpt_h: 13;
		UINT32	src1_fmt: 5;
		UINT32	src1_mat_en: 1;
	} Word4;
	struct
	{
		UINT32	src1_inpt_x: 13;
		UINT32	src1_inpt_y: 13;
		UINT32	src1_argb_order: 5;
		UINT32	src1_fcv_stch: 1;
	} Word5;
	struct
	{
		UINT32	src1_chr2_addr_index: 7;
		UINT32	reserved0: 1;
		UINT32	src1_chr1_addr_index: 7;
		UINT32	reserved1: 1;
		UINT32	src1_addr_index: 7;
		UINT32	src1_blk_mode_interleave: 1;
		UINT32	src1_inpt_sel: 1;
		UINT32	src1_lg_en: 1;
		UINT32	reserved2: 6;
	} Word6;
	struct
	{
		UINT32	Reserved: 32;
	} Word7;
	struct
	{
		UINT32	Reserved: 32;
	} Word8;
} SECMD_EXT_FMT_CONV;


#endif
