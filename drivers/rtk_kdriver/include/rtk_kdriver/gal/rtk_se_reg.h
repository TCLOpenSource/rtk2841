/******************************************************************************
*
*   Copyright(c) 2017 Realtek Semiconductor Corp. All rights reserved.
*
*   @author baker.cheng@realtek.com
*
******************************************************************************/
#ifndef _SE_REG_MAP_H_
#define _SE_REG_MAP_H_

typedef union _SEREG_CMDMEM
{
	UINT32  Value;
	struct
	{
		UINT32  Reserved0: 4;
		UINT32  base: 28;
	} Fields;
} SEREG_CMDMEM;
typedef union _SEREG_SRWORDCNT
{
	UINT32  Value;
	struct
	{
		UINT32  srwordcnt: 7;
		UINT32  Reserved: 25;
	} Fields;
} SEREG_SRWORDCNT;
typedef union _SEREG_Q_PRIORITY
{
	UINT32  Value;
	struct
	{
		UINT32  pri1: 2;
		UINT32  pri2: 2;
		UINT32  pri3: 2;
		UINT32  pri4: 2;
		UINT32  disable: 4;
		UINT32  Reserved: 20 ;
	} Fields;
} SEREG_Q_PRIORITY;
typedef union _SEREG_CLR_FMT
{
	UINT32  Value;
	struct
	{
		UINT32  Format: 4;
		UINT32  write_enable1: 1;
		UINT32  alpha_loc: 1;
		UINT32  write_enable2: 1;
		UINT32  alpha_loc_rslt: 1;
		UINT32  write_enable3: 1;
		UINT32  alpha_loc3: 1;
		UINT32  write_enable4: 1;
		UINT32  alpha_loc4: 1;
		UINT32  write_enable9: 1;
		UINT32  alpha_loc2: 1;
		UINT32  write_enable5: 1;
		UINT32  big_endian_i1: 1;
		UINT32  write_enable6: 1;
		UINT32  big_endian_i2: 1;
		UINT32  write_enable7: 1;
		UINT32  big_endian_o: 1;
		UINT32  write_enable8: 1;
		UINT32  rounding_en: 1;
		UINT32  write_enable10: 1;
		UINT32  big_endian_i3: 1;
		UINT32  write_enable11: 1;
		UINT32  big_endian_i4: 1;
		UINT32  write_enable12: 1;
		UINT32  Reserved2: 5;
	} Fields;
} SEREG_CLR_FMT;
typedef union _SEREG_COLOR_KEY
{
	UINT32  Value;
	struct
	{
		UINT32  color_key: 24;
		UINT32  Reserved: 8;
	} Fields;
} SEREG_COLOR_KEY;
typedef union _SEREG_COLOR
{
	UINT32  Value;
	struct
	{
		UINT32  src_color: 32;
	} Fields;
} SEREG_COLOR;
typedef union _SEREG_ALPHA
{
	UINT32  Value;
	struct
	{
		UINT32  src_alpha: 8;
		UINT32  Reserved: 24;
	} Fields;
} SEREG_ALPHA;
typedef union _SEREG_BADDR
{
	UINT32  Value;
	struct
	{
		UINT32  baddr: 32;
	} Fields;
} SEREG_BADDR;
typedef union _SEREG_PITCH
{
	UINT32  Value;
	struct
	{
		UINT32  pitch: 16;
		UINT32  interleave: 1;
		UINT32  Reserved: 15;
	} Fields;
} SEREG_PITCH;
typedef struct _SEREG_DMAINFO
{
	SEREG_BADDR		SeRegBaseAddress[4];
	SEREG_PITCH		SeRegPitch[4];
} SEREG_DMAINFO;
typedef union _SE20REG_BADDR
{
	SEREG_BADDR	Se20Baddr[4];
} SE20REG_BADDR;
typedef union _SE20REG_PITCH
{
	SEREG_PITCH	Se20Pitch[4];
} SE20REG_PITCH;
typedef struct _SE20REG_DMAINFO
{
	SE20REG_BADDR		Se20BaddrSet[16];
	SE20REG_PITCH		Se20PitchSet[16];
} SE20REG_DMAINFO;

typedef union _SEREG_CLUT_LOCK_ST
{
	UINT32  Value;
	struct
	{
		UINT32 clut_lock_st: 3;
		UINT32 Reserved:29;
	} Fields;
} SEREG_CLUT_LOCK_ST;
typedef union _SEREG_CONVSCALING
{
	UINT32  Value;
	struct
	{
		UINT32  vup: 1;
		UINT32  hup: 1;
		UINT32  vdown: 1;
		UINT32  hdown: 1;
		UINT32  Reserved: 28;
	} Fields;
} SEREG_CONVSCALING;
typedef union _SEREG_CONVCOEF
{
	UINT32  Value;
	struct
	{
		UINT32  m0: 13;
		UINT32  m1: 13;
		UINT32  Reserved: 6;
	} Fields;
} SEREG_CONVCOEF;
typedef union _SEREG_CONVCOEF6
{
	UINT32  Value;
	struct
	{
		UINT32  a0: 10;
		UINT32  a1: 10;
		UINT32  a2: 10;
		UINT32  Reserved: 2;
	} Fields;
} SEREG_CONVCOEF6;
typedef union _SEREG_SRC_CLR
{
	UINT32  Value;
	struct
	{
		UINT32  src_clr_mul_red: 9;
		UINT32  Reserved: 7;
		UINT32  src_clr_add_red: 9;
		UINT32  Reserved1: 7;
	} Fields;
} SEREG_SRC_CLR;
typedef union _SEREG_SYNC_VO_MARGIN
{
	UINT32  Value;
	struct
	{
		UINT32  margin_VOtoSE: 12;
		UINT32  Reserved: 14;
		UINT32  vo_osd_plane: 1;
		UINT32  vbi: 1;
		UINT32  after_vo_cur: 1;
		UINT32  before_vo_cur: 1;
		UINT32  vo_plane: 1;
		UINT32  auto_dir_en: 1;
	} Fields;
} SEREG_SYNC_VO_MARGIN;
typedef union _SEREG_SYNC_VO_LOCATION
{
	UINT32  Value;
	struct
	{
		UINT32  VO_current_y: 14;
		UINT32  Reserved: 18;
	} Fields;
} SEREG_SYNC_VO_LOCATION;
typedef union _SEREG_SYNC_VO_Y
{
	UINT32  Value;
	struct
	{
		UINT32  VO_total_y: 13;
		UINT32  Reserved0: 3;
		UINT32  gdma_dir: 1;
		UINT32  Reserved: 15;
	} Fields;
} SEREG_SYNC_VO_Y;
typedef union _SEREG_STRETCH
{
	UINT32  Value;
	struct
	{
		UINT32  vodd: 1;
		UINT32  hodd: 1;
		UINT32  vtype: 1;
		UINT32  htype: 2;
		UINT32  ref_alpha: 1;
		UINT32  repl_color: 1;
		UINT32  repl_alpha: 1;
		UINT32  Reserved: 24;
	} Fields;
} SEREG_STRETCH;
typedef union _SEREG_HDHS
{
	UINT32  Value;
	struct
	{
		UINT32  H_scaling_dph_lsb: 14;
		UINT32  H_scaling_dph_msb: 4;
		UINT32  H_scaling_iniph: 7;
		UINT32  Reserved: 7;
	} Fields;
} SEREG_HDHS;
typedef union _SEREG_VDHS
{
	UINT32  Value;
	struct
	{
		UINT32  V_scaling_dph_lsb: 14;
		UINT32  V_scaling_dph_msb: 4;
		UINT32  V_scaling_iniph: 7;
		UINT32  Reserved: 7;
	} Fields;
} SEREG_VDHS;

typedef struct _SEREG_SEREG_STCH_SET
{
	SEREG_STRETCH			SeStretch[4];
	SEREG_HDHS			SeHdhs[4];
	SEREG_VDHS			SeVdhs[4];
} SEREG_STCH_SET;
typedef union _SEREG_HCOEF
{
	UINT32  Value;
	struct
	{
		UINT32  hcoef: 14;
		UINT32  Reserved: 18;
	} Fields;
} SEREG_HCOEF;
typedef union _SEREG_VCOEF
{
	UINT32  Value;
	struct
	{
		UINT32  vcoef: 14;
		UINT32  Reserved: 18;
	} Fields;
} SEREG_VCOEF;
typedef struct _SEREG_COEFINFO
{
	SEREG_HCOEF		SeRegHCoef[32];
	SEREG_HCOEF		SeRegHCoef32[32];
	SEREG_VCOEF		SeRegVCoef[16];
	SEREG_VCOEF		SeRegVCoef16[16];
} SEREG_COEFINFO;

typedef union _SE20REG_HCOEF
{
	SEREG_HCOEF	Se20HCoef[4];
} SE20REG_HCOEF;

typedef union _SE20REG_VCOEF
{
	SEREG_VCOEF	Se20VCoef[4];
} SE20REG_VCOEF;

typedef struct _SE20REG_COEFINFO
{
	SE20REG_HCOEF		SeRegHCoef[32];
	SE20REG_VCOEF		SeRegVCoef[32];
} SE20REG_COEFINFO;

typedef struct _SEREG_COEFINFO2
{
	SEREG_HCOEF		SeRegHCoef[16];
	SEREG_HCOEF		SeRegHCoef32[16];
	SEREG_VCOEF		SeRegVCoef[16];
	SEREG_VCOEF		SeRegVCoef16[16];
} SEREG_COEFINFO2;
typedef union _SEREG_CTRL
{
	UINT32  Value;
	struct
	{
		UINT32  write_data: 1;
		UINT32  go: 1;
		UINT32  endiswap: 1;
		UINT32  Reserved: 29;
	} Fields;
} SEREG_CTRL;
typedef union _SEREG_IDLE
{
	UINT32  Value;
	struct
	{
		UINT32  idle: 1;
		UINT32  Reserved: 31;
	} Fields;
} SEREG_IDLE;
typedef union _SEREG_INTSEL
{
	UINT32  Value;
	struct
	{
		UINT32  Sel1: 3;
		UINT32  Reserved0: 1;
		UINT32  Sel2: 3;
		UINT32  Reserved1: 25;
	} Fields;
} SEREG_INTSEL;
typedef union _SEREG_INTS
{
	UINT32  Value;
	struct
	{
		UINT32  write_data: 1;
		UINT32  sync: 1;
		UINT32  com_err: 1;
		UINT32  com_empty: 1;
		UINT32  Reserved1: 12;
		UINT32  fmt_err: 1;
		UINT32  vo_sync_err: 1;
		UINT32  Reserved2: 14;
	} Fields;
} SEREG_INTS;
typedef union _SEREG_INTE
{
	UINT32  Value;
	struct
	{
		UINT32  write_data: 1;
		UINT32  sync: 1;
		UINT32  com_err: 1;
		UINT32  com_empty: 1;
		UINT32  Reserved1: 12;
		UINT32  fmt_err: 1;
		UINT32  vo_sync_err: 1;
		UINT32  Reserved: 14;
	} Fields;
} SEREG_INTE;
typedef union _SEREG_INSTCNT_L
{
	UINT32  Value;
	struct
	{
		UINT32 instcnt_l;
	} Fields;
} SEREG_INSTCNT_L;
typedef union _SEREG_INSTCNT_H
{
	UINT32  Value;
	struct
	{
		UINT32 instcnt_h;
	} Fields;
} SEREG_INSTCNT_H;
typedef union _SEREG_CLUT_RADR
{
	UINT32  Value;
	struct
	{
		UINT32  radr: 8;
		UINT32  Reserved: 24;
	} Fields;
} SEREG_CLUT_RADR;
typedef union _SEREG_CLUT_VALUE
{
	UINT32  Value;
	struct
	{
		UINT32  value;
	} Fields;
} SEREG_CLUT_VALUE;
typedef union _SEREG_DBG
{
	UINT32  Value;
	struct
	{
		UINT32  dbg_sel0: 5;
		UINT32  Reserved1: 3;
		UINT32  dbg_sel1: 5;
		UINT32  Reserved2: 3;
		UINT32  dbg_module_sel0:4;
		UINT32  dbg_module_sel1:4;
		UINT32  dbg_en: 1;
		UINT32  dbg_change: 1;
		UINT32  Reserved3: 6;
	} Fields;
} SEREG_DBG;
typedef union _SEREG_SCTCH
{
	UINT32  Value;
	struct
	{
		UINT32  Reg0: 16;
		UINT32  Reg1: 16;
	} Fields;
} SEREG_SCTCH;
typedef union _SEREG_DCU_CTRL
{
	UINT32  Value;
	struct
	{
		UINT32  dcu_access_mode: 2;
		UINT32  Reserved: 30;
	} Fields;
} SEREG_DCU_CTRL;
typedef union _SEREG_READ_MARGIN
{
	UINT32  Value;
	struct
	{
		UINT32  rme: 1;
		UINT32  rm: 4;
		UINT32  ls: 1;
		UINT32  Reserved: 26;
	} Fields;
} SEREG_READ_MARGIN;
typedef union _SEREG_BIST
{
	UINT32  Value;
	struct
	{
		UINT32  se_bist_0: 1;
		UINT32  se_bist_1: 1;
		UINT32  Reserved: 30;
	} Fields;
} SEREG_BIST;
typedef union _SEREG_SE_BIST_0_FAIL
{
	UINT32  Value;
	struct
	{
		UINT32  se_bist_0_fail_0: 1;
		UINT32  se_bist_0_fail_1: 1;
		UINT32  se_bist_0_fail_2: 1;
		UINT32  se_bist_0_fail_3: 1;
		UINT32  se_bist_0_fail_4: 1;
		UINT32  se_bist_0_fail_5: 1;
		UINT32  Reserved: 26;
	} Fields;
} SEREG_BIST_0;
typedef union _SEREG_SE_DRF_0_FAIL
{
	UINT32  Value;
	struct
	{
		UINT32  se_drf_0_fail_0: 1;
		UINT32  se_drf_0_fail_1: 1;
		UINT32  se_drf_0_fail_2: 1;
		UINT32  se_drf_0_fail_3: 1;
		UINT32  se_drf_0_fail_4: 1;
		UINT32  se_drf_0_fail_5: 1;
		UINT32  se_drf_0_fail_6: 1;
		UINT32  se_drf_0_fail_7: 1;
		UINT32  se_drf_0_fail_8: 1;
		UINT32  Reserved: 23;
	} Fields;
} SEREG_SE_DRF_0_FAIL;
typedef union _SEREG_SE_SWAP
{
	UINT32  Value;
	struct
	{
		UINT32  w_1b_en: 1;
		UINT32  w_2b_en: 1;
		UINT32  w_4b_en: 1;
		UINT32  w_8b_en: 1;
		UINT32  r_1b_en: 1;
		UINT32  r_2b_en: 1;
		UINT32  r_4b_en: 1;
		UINT32  r_8b_en: 1;
		UINT32  Reserved: 24;
	} Fields;
} SEREG_SWAP;
typedef union _SEREG_DFB_CTRL
{
	UINT32  Value;
	struct
	{
		UINT32  src_round: 1;
		UINT32  dst_round: 1;
		UINT32  Reserved: 30;
	} Fields;
} SEREG_DFB_CTRL;

#if SE_SE20_EXT
typedef struct _SEREG_INFO
{
	SEREG_CMDMEM			SeCmdBase[4];
	SEREG_CMDMEM			SeCmdLimit[4];
	SEREG_CMDMEM			SeCmdReadPtr[4];
	SEREG_CMDMEM			SeCmdWritePtr[4];
	SEREG_SRWORDCNT			SeSramWordCount[4];
	SEREG_Q_PRIORITY		SeQueuePriority;
	UINT32				ReservedQueuePriority[3];
	SEREG_CLR_FMT			SeColorFormat[4];
	SEREG_COLOR_KEY			SeColorKey[4];
	SEREG_COLOR_KEY			SeDestColorKey[4];/*80*/
	UINT32				ReservedDestColorKey[16];/*90~CC*/
	SEREG_COLOR			SeSrcColor[4];/*D0*/
	SEREG_ALPHA			SeSrcAlpha[4];
	SEREG_ALPHA			SeDestAlpha[4];
	SEREG_ALPHA			SeResultAlpha[4];/*100*/
	SEREG_COLOR			SeResultColor[4];/*110*/
	UINT32				ReservedResultAlpha[24];/*120~17C*/
	SEREG_DMAINFO			SeDmaInfo1[2];/*180~1B0*/
	SEREG_CLUT_LOCK_ST		SeClutLockSt[4];/*1C0, dummy*3*/
	SEREG_CONVSCALING		SeConvScaling[4]; /*1d0*/
	SEREG_CONVCOEF			SeConvCoef1[4];
	SEREG_CONVCOEF			SeConvCoef2[4];
	SEREG_CONVCOEF			SeConvCoef3[4];
	SEREG_CONVCOEF			SeConvCoef4[4];
	SEREG_CONVCOEF			SeConvCoef5[4];
	SEREG_CONVCOEF6			SeConvCoef6[4];
	SEREG_COLOR_KEY			SeFcvBitblitColorKey[4]; /*24*/
	SEREG_SRC_CLR			SeSrcClrRed[4];
	SEREG_SRC_CLR			SeSrcClrGreen[4];
	SEREG_SRC_CLR			SeSrcClrBlue[4];
	SEREG_SRC_CLR			SeSrcClrAlpha[4];/*28*/
	UINT32				ReservedSrcClrAlpha[12];/*29~2bc*/
	SEREG_ALPHA			SeFBColorAlpha1[4];/*2C*/
	UINT32				ReservedFBColorAlpha1[8];/*2D~2E*/
	SEREG_STCH_SET			SeStchSet[2];/*2F~34*/
/*
	SEREG_STRETCH			SeStretch[4];
	SEREG_HDHS			SeHdhs[4];
	SEREG_VDHS			SeVdhs[4];
	SEREG_STRETCH			Se20Stretch[4];
	SEREG_HDHS			Se20Hdhs[4];
	SEREG_VDHS			Se20Vdhs[4];
*/
	UINT32				ReservedStchSet[12];/*35~37*/
	/*[38, 40, 48, 4C], [50, 58, 60, 64]*/
	SEREG_COEFINFO			SeCoefInfo[2];
	/*SE20 [68, 88]*/
	SE20REG_COEFINFO		Se20CoefInfo[1];
	SEREG_COLOR_KEY			SeScBitblitColorKey[4]; /*a8*/
	UINT32				SeLinearG[20];/*a9~ad*/
	UINT32				ReservedLinearG[40];/*ae~b7*/
	SE20REG_DMAINFO			Se20DmaInfo;/*b8~D7*/
	SEREG_SWAP			SeSWAP[4];/*D8*/
	SEREG_DFB_CTRL			SeDfbCtrl[4];/*D9*/
	UINT32				ReservedDfbCtrl[24];/*DADF*/
	UINT32				SeCacheReq[4];/*e0*/
	UINT32				SeCacheMiss[4];
	UINT32				Se20Dummy[4];
	UINT32				Se20DbgIdle;
	UINT32				Se20Dbgwdma;
	UINT32				Se20DbgIntf;
	UINT32				ReservedDbgIntf;
	UINT32				Se20DbgPerf;/*e4*/
	UINT32				Se20Option;
	UINT32				Se20IdleMask;
	UINT32				ReservedIdleMask[13];
	SEREG_CTRL			SeCtrl[4]; /*e8*/
	SEREG_IDLE			SeIdle[4];
	SEREG_INTSEL			SeIntSel;
	UINT32				ReservedIntSel[3];
	SEREG_INTS			SeInts[4];
	SEREG_INTE			SeInte[4];
	SEREG_INSTCNT_L			SeInstCntL[4];
	SEREG_INSTCNT_H			SeInstCntH[4];
	SEREG_CLUT_RADR			SeClutReadAddress;/*ef*/
	SEREG_CLUT_VALUE		SeClutValue;
	SEREG_DBG			SeDebug;
	SEREG_SCTCH			SeSctch;
	UINT32				SeSFT;/*f0*/
} SEREG_INFO;
#else
/*SE_OLD*/
typedef struct _SEREG_INFO
{
	SEREG_CMDMEM			SeCmdBase[4];
	SEREG_CMDMEM			SeCmdLimit[4];
	SEREG_CMDMEM			SeCmdReadPtr[4];
	SEREG_CMDMEM			SeCmdWritePtr[4];
	SEREG_SRWORDCNT			SeSramWordCount[4];
	SEREG_Q_PRIORITY		SeQueuePriority;
	UINT32				Reserved0[3];
	SEREG_CLR_FMT			SeColorFormat[4];
	SEREG_COLOR_KEY			SeColorKey[4];
	SEREG_COLOR_KEY			SeDestColorKey[4];
	SEREG_COLOR			SeSrcColor[4];
	SEREG_ALPHA			SeSrcAlpha[4];/*a0*/
	SEREG_ALPHA			SeDestAlpha[4];
	SEREG_ALPHA			SeResultAlpha[4];
	SEREG_DMAINFO			SeDmaInfo1[2];/*d0e0 f0100*/
	UINT32				Reserved1[4];/*110*/
	SEREG_ALPHA			SeSrcAlpha4[4];/*120*/
	SEREG_ALPHA			SeDestAlpha3[4];/*130*/
	SEREG_COLOR			SeColorKey2[4];/*140*/
	SEREG_COLOR			SeDestColorKey2[4];/*150*/
	SEREG_COLOR			SeColorKey3[4];/*160*/
	SEREG_COLOR			SeDestColorKey3[4];/*170*/
	SEREG_COLOR			SeResultColor[4];/*180*/
	SEREG_COLOR			SeSrcColor3[4];/*190*/
	SEREG_ALPHA			SeSrcAlpha3[4];/*1a0*/
	SEREG_ALPHA			SeDestAlpha2[4];/*1b0*/
	SEREG_COLOR			SeSrcColor4[4];/*1c0*/
	SEREG_CLUT_LOCK_ST		SeClutLockSt[4];/*1d0, dummy*3*/
	SEREG_CONVSCALING		SeConvScaling[4]; /*1e0*/
	SEREG_CONVCOEF			SeConvCoef1[4];
	SEREG_CONVCOEF			SeConvCoef2[4];
	SEREG_CONVCOEF			SeConvCoef3[4];
	SEREG_CONVCOEF			SeConvCoef4[4];
	SEREG_CONVCOEF			SeConvCoef5[4];/*dummy, m1*/
	SEREG_CONVCOEF6			SeConvCoef6[4];
	SEREG_COLOR_KEY			SeFcvBitblitColorKey[4]; /*25*/
	SEREG_SRC_CLR			SeSrcClrRed[4];
	SEREG_SRC_CLR			SeSrcClrGreen[4];
	SEREG_SRC_CLR			SeSrcClrBlue[4];
	SEREG_SRC_CLR			SeSrcClrAlpha[4];
	SEREG_SYNC_VO_MARGIN		SeSyncVoMargin[4]; /*2A*/
	SEREG_SYNC_VO_LOCATION		SeSyncVoLocation[4];
	SEREG_STRETCH			SeStretch[4];
	SEREG_HDHS			SeHdhs[4];
	SEREG_VDHS			SeVdhs[4];
	UINT32				Reserved2[4];
	SEREG_COEFINFO			SeCoefInfo[2];
	/*[30, 38, 40, 44], [48, 50, 58, 5c]*/
	SEREG_COEFINFO2			SeCoefInfo2[3];
	/*[60, 64, 68, 6c], [70, 74, 78, 7c] dummy[80, 84, 88, 8c]*/
	SEREG_COLOR_KEY			SeScBitblitColorKey[4]; /*90*/
	UINT32				Reserved3[20];/*91,92,93,94,95*/
	SEREG_CTRL			SeCtrl[4]; /*96*/
	SEREG_IDLE			SeIdle[4];
	SEREG_INTSEL			SeIntSel;
	UINT32				Reserved4[3];
	SEREG_INTS			SeInts[4];
	SEREG_INTE			SeInte[4];
	SEREG_INSTCNT_L			SeInstCntL[4];
	SEREG_INSTCNT_H			SeInstCntH[4];
	SEREG_CLUT_RADR			SeClutReadAddress;/*9d*/
	SEREG_CLUT_VALUE		SeClutValue;
	SEREG_DBG			SeDebug;
	SEREG_SCTCH			SeSctch;
	UINT32				Reserved5[8];/*9e,9f*/
#if SE_SE20
	SEREG_READ_MARGIN		SeReadMargin;/*a0*/
	SEREG_BIST			SeBistMode;
	SEREG_BIST			SeBistDone;
	SEREG_BIST			SeBistFailGroup;
	SEREG_BIST_0			SeBist0Fail;/*a1*/
	SEREG_BIST			SeBist1Fail;
	SEREG_BIST			SeDrfMode;
	SEREG_BIST			SeDrfResume;
	SEREG_BIST			SeDrfDone;/*a2*/
	SEREG_BIST			SeDrfPause;
	SEREG_BIST			SeDrfFailGroup;
	SEREG_SE_DRF_0_FAIL		SeDrf0Fail;
	SEREG_BIST			SeDrf1Fail[4];/*a3, dummy*3*/
	UINT32				Reserved6[68];/*a4~a68, */
	SEREG_ALPHA			SeFBColorAlpha1[4];/*b5*/
	SEREG_SYNC_VO_Y			SeSyncVoY[4];/*b6*/
	SEREG_ALPHA			SeFBColorAlpha2[4];
	SEREG_ALPHA			SeFBColorAlpha3[4];
	UINT32				Reserved7[36];/*b9~c1*/
	UINT32				SeLinearG[20];/*c2~c6*/
	UINT32				Reserved8[36];/*c7~cf*/
	SEREG_DMAINFO			SeDmaInfo2[6];/*d0~db*/
	SEREG_SWAP			SeSWAP[4];/*dc*/
	SEREG_DFB_CTRL			SeDfbCtrl[4];/*dd*/
	UINT32				Reserved9[8];/*dedf*/
	UINT32				SeCacheReq[4];/*e0*/
	UINT32				SeCacheMiss[4];
	UINT32				SeDummy[4];
	UINT32				SeDbg[4];
#endif
} SEREG_INFO;

#endif
#endif
