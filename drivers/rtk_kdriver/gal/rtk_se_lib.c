/******************************************************************************
*
*   Copyright(c) 2017 Realtek Semiconductor Corp. All rights reserved.
*
*   @author baker.cheng@realtek.com
*
******************************************************************************/
//#include <mach/platform.h>
//#include <linux/sched.h>/*common*/
#include <linux/kernel.h>
#include <linux/string.h>
#include <rtk_kadp_se.h>
#include <rtk_se_lib.h>
#include <rtk_se_cmd.h>
#include <rtk_se_stch.h>
#include <gal/rtk_se_export.h>
#include <gal/rtk_se_reg.h>
#include <linux/slab.h> /*kmalloc*/


#define ARGBENDIAN 0
#define CONSTENDIAN 0x1d

UINT32 get_SetColorFormat(SE_COLOR_FORMAT_EX_T* pExtraParam);

#if SE_SE20 || SE_OLD
UINT32 SE_Get_mem(void) {
	return se_get_mem();
}
#endif


#if SE_SE20
static bool se_dummy_stch(SECMD_EXT_STCH_BLIT* se_ext_stch)
{
	UINT32 tmpmem = se_get_mem();

	if(tmpmem == 0)
		return false;
	se_ext_stch->DReg1.Reserved = 0;
	se_ext_stch->DReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DReg1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	se_ext_stch->DReg1_1.RegisterValue = 0x00754057;

	se_ext_stch->DReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DReg2.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SWAP_FBDC;
	se_ext_stch->DReg2_1.RegisterValue = 0;

	se_ext_stch->DReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DReg3.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SE20_DUMMY;
	se_ext_stch->DReg3_1.RegisterValue = 0xffff0000;


	se_ext_stch->DReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DReg4.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_STRETCH;
	se_ext_stch->DReg4_1.RegisterValue = 0x4;

	se_ext_stch->DReg5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DReg5.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DReg5.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_VDHS;
	se_ext_stch->DReg5_1.RegisterValue = 0x35e5;

	se_ext_stch->DReg6.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DReg6.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DReg6.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_HDHS;
	se_ext_stch->DReg6_1.RegisterValue = 0x35e5;

	se_ext_stch->DAddr0.Reserved = 0;
	se_ext_stch->DAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DAddr0.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DAddr0.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_BASE_ADDR1;
	se_ext_stch->DAddr0_1.RegisterValue = tmpmem;

	se_ext_stch->DPitch0.Reserved = 0;
	se_ext_stch->DPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DPitch0.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DPitch0.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_PITCH1;
	se_ext_stch->DPitch0_1.RegisterValue = 0x26;

	se_ext_stch->DAddr1.Reserved = 0;
	se_ext_stch->DAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DAddr1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DAddr1.RegisterAddress = (SEINFO_WRITEREG)(SEINFO_REG_BASE_ADDR1 + 0x4);
	se_ext_stch->DAddr1_1.RegisterValue = tmpmem;

	se_ext_stch->DPitch1.Reserved = 0;
	se_ext_stch->DPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch->DPitch1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch->DPitch1.RegisterAddress = (SEINFO_WRITEREG)(SEINFO_REG_PITCH1 + 0x4);
	se_ext_stch->DPitch1_1.RegisterValue = 0x26;

	se_ext_stch->DWord1.opcode = SEINFO_OPCODE_EXT_FMT;
	se_ext_stch->DWord1.rslt_fmt = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
	se_ext_stch->DWord3.rslt_addr_index = 0x1;

	se_ext_stch->DWord4.src1_inpt_w = 0x20;
	se_ext_stch->DWord4.src1_inpt_h = 0x20;
	se_ext_stch->DWord4.src1_fmt = SEINFO_EXT_COLOR_FORMAT_ARGB8888;
	se_ext_stch->DWord5.src1_fcv_stch = 1;
	se_ext_stch->DWord9.lay_num_ext = 2;
	se_ext_stch->DWord12.stch1_out_w = 0x26;
	se_ext_stch->DWord12.stch1_out_h = 0x26;
	se_ext_stch->DWord12.stch1_src = 0x1;
	se_ext_stch->DWord12.stch1_h_en = 0x1;
	se_ext_stch->DWord12.stch1_v_en = 0x1;
	se_ext_stch->DWord13.src2_inpt_w = SEINFO_OPCODE_NOP;
	se_ext_stch->DWord14.src2_out_x = SEINFO_OPCODE_NOP;
	se_ext_stch->DWord15.stch2_out_w = SEINFO_OPCODE_NOP;
	se_ext_stch->DWord16.Reserved = SEINFO_OPCODE_NOP;

	return true;
}
#endif






bool SE_WriteRegister(
	SEINFO_REGMODE		bRegisterModeSelect,
	SEINFO_WRITEREG		wRegisterAddress,
	UINT32			dwRegisterValue)
{
	SECMD_WRITE_REGISTER SeCmdWriteRegister;
	memset((void *)&SeCmdWriteRegister, 0, sizeof(SECMD_WRITE_REGISTER));
	SeCmdWriteRegister.Word1.Reserved = 0;
	SeCmdWriteRegister.Word1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdWriteRegister.Word1.Clut = bRegisterModeSelect;
	if(bRegisterModeSelect)
		SeCmdWriteRegister.Word1.RegisterAddress = wRegisterAddress & 0xff;
	else
		SeCmdWriteRegister.Word1.RegisterAddress = wRegisterAddress;
	SeCmdWriteRegister.Word2.RegisterValue = dwRegisterValue;
	SeCmdWriteRegister.Word3.Reserved = SEINFO_OPCODE_NOP;
	SeCmdWriteRegister.Word4.Reserved = SEINFO_OPCODE_NOP;
	SeCmdWriteRegister.Word5.Reserved = SEINFO_OPCODE_NOP;
	SeCmdWriteRegister.Word6.Reserved = SEINFO_OPCODE_NOP;
	SeCmdWriteRegister.Word7.Reserved = SEINFO_OPCODE_NOP;
	SeCmdWriteRegister.Word8.Reserved = SEINFO_OPCODE_NOP;
	WriteCmd(se_devices, (UINT8 *) &SeCmdWriteRegister, sizeof(SECMD_WRITE_REGISTER));
	return true;
}

bool SE_WriteRegister2(
	SEINFO_WRITEREG	wRegisterAddress1,
	UINT32		dwRegisterValue1,
	SEINFO_WRITEREG	wRegisterAddress2,
	UINT32		dwRegisterValue2,
	SEINFO_WRITEREG	wRegisterAddress3,
	UINT32		dwRegisterValue3,
	SEINFO_WRITEREG	wRegisterAddress4,
	UINT32		dwRegisterValue4)
{
	SECMD_WRITE_REGISTER2 SeCmdWriteRegister;
	memset((void *)&SeCmdWriteRegister, 0, sizeof(SECMD_WRITE_REGISTER));
	SeCmdWriteRegister.Word1.Reserved = 0;
	SeCmdWriteRegister.Word1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdWriteRegister.Word1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdWriteRegister.Word1.RegisterAddress = wRegisterAddress1;
	SeCmdWriteRegister.Word2.RegisterValue = dwRegisterValue1;

	SeCmdWriteRegister.Word3.Reserved = 0;
	SeCmdWriteRegister.Word3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdWriteRegister.Word3.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdWriteRegister.Word3.RegisterAddress = wRegisterAddress2;
	SeCmdWriteRegister.Word4.RegisterValue = dwRegisterValue2;

	SeCmdWriteRegister.Word5.Reserved = 0;
	SeCmdWriteRegister.Word5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdWriteRegister.Word5.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdWriteRegister.Word5.RegisterAddress = wRegisterAddress3;
	SeCmdWriteRegister.Word6.RegisterValue = dwRegisterValue3;

	SeCmdWriteRegister.Word7.Reserved = 0;
	SeCmdWriteRegister.Word7.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdWriteRegister.Word7.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdWriteRegister.Word7.RegisterAddress = wRegisterAddress4;
	SeCmdWriteRegister.Word8.RegisterValue = dwRegisterValue4;

	WriteCmd(se_devices, (UINT8 *) &SeCmdWriteRegister, sizeof(SECMD_WRITE_REGISTER));
	return true;
}


bool SE_BitBltEx(
	SE_PROCINFO_T*		pSeDestinationProcInfo,
	SE_PROCINFO_T*		pSeSourceProcInfo,
	SEINFO_OUTPUT_ALPHAMODE	byOutputAlphaModeSelect,
	UINT8			byOutputAlphaValue,
	SEINFO_SETUPMODE	bSetupModeSelect,
	SEINFO_CORNER		byStartingCorner,
	SEINFO_ROPCODE		byRopCode,
	void*			pExtraParam,
	UINT32			vo_sync)
{
	SE_BLEND_EX_T* pBlitEx = (SE_BLEND_EX_T*)pExtraParam;
	SECMD_BITBLT SeCmdBitblt;
/*CONFIG_SE_COPY_WITH_FMTCONV*/

	if(!vo_sync  && pBlitEx->srcAlphaModeSelect == SEINFO_BITBLT_ALPHA_DISABLE &&
		pBlitEx->destAlphaModeSelect == SEINFO_BITBLT_ALPHA_DISABLE &&
		byRopCode == SEINFO_ROPCODE_COPY &&
		bSetupModeSelect == SEINFO_BITBLT_SETUP_MANUAL) {

		if(pBlitEx->stcolorfmt.byColorFormat == SEINFO_COLOR_FORMAT_ARGB8888) {
			return SE_FormatConversion(
				pSeDestinationProcInfo,
				pSeSourceProcInfo,
				SEINFO_CONVERSION_ARGB_ARGB,
				SEINFO_DEST_FORMAT_ARGB8888,
				SEINFO_SRC_FORMAT_ARGB8888,
				pBlitEx->colorKeySelect,
				byOutputAlphaModeSelect,
				byOutputAlphaValue,
				pExtraParam);
		}
	}



	memset((void *)&SeCmdBitblt, 0, sizeof(SeCmdBitblt));
//-------------------------------------------------------------
	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	SeCmdBitblt.WordReg1.Reserved = 0;
	SeCmdBitblt.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdBitblt.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdBitblt.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	SeCmdBitblt.WordReg1_1.RegisterValue = get_SetColorFormat(&pBlitEx->stcolorfmt);

	SeCmdBitblt.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdBitblt.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdBitblt.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	SeCmdBitblt.WordReg2_1.RegisterValue = pBlitEx->constColorValue;

	if(pBlitEx->bEnableDfbReplaceSrcAlphaWithConstAlpha){
		//SE_SetDFBColorAlpha(cmdQue, pBlitEx->constAlphaValueForBlendColorAlpha);
		SeCmdBitblt.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DFB_COLORALPHA;
		SeCmdBitblt.WordReg3_1.RegisterValue = pBlitEx->constAlphaValueForBlendColorAlpha;
	}else{
		SeCmdBitblt.WordReg3.Reserved = 0;
		SeCmdBitblt.WordReg3.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pBlitEx->bEnableDfbModulateSrcAlphaWithConstAlpha) {
		//SE_SetSourceAlpha1(cmdQue, pBlitEx->constAplhaValue);
		SeCmdBitblt.WordReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg4.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
		SeCmdBitblt.WordReg4_1.RegisterValue = pBlitEx->constAplhaValue;
	}else{
		SeCmdBitblt.WordReg4.Reserved = 0;
		SeCmdBitblt.WordReg4.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg4_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	SeCmdBitblt.WordAddr0.Reserved = 0;
	SeCmdBitblt.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdBitblt.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdBitblt.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	if(bSetupModeSelect == SEINFO_BITBLT_SETUP_CONST){
		SeCmdBitblt.WordAddr0_1.RegisterValue = pSeDestinationProcInfo->uAddr;
	}else{
		SeCmdBitblt.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;
	}

	SeCmdBitblt.WordPitch0.Reserved = 0;
	SeCmdBitblt.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdBitblt.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdBitblt.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdBitblt.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	SeCmdBitblt.WordAddr1.Reserved = 0;
	SeCmdBitblt.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdBitblt.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdBitblt.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdBitblt.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	SeCmdBitblt.WordPitch1.Reserved = 0;
	SeCmdBitblt.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdBitblt.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdBitblt.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdBitblt.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;

	SeCmdBitblt.Word1.InputSelect = (UINT32) bSetupModeSelect;
	SeCmdBitblt.Word1.Height = pSeDestinationProcInfo->wDataHeight;
	SeCmdBitblt.Word1.Width = pSeDestinationProcInfo->wDataWidth;
	SeCmdBitblt.Word1.OpCode = SEINFO_OPCODE_BITBLT;

	SeCmdBitblt.Word2.DestAddressIndex = (UINT32) pSeDestinationProcInfo->byBaseAddressIndex;
	SeCmdBitblt.Word2.SelectOutputAlpha = byOutputAlphaModeSelect;
	SeCmdBitblt.Word2.OutputX = pSeDestinationProcInfo->wDataX;
	SeCmdBitblt.Word2.OutputY = pSeDestinationProcInfo->wDataY;

	SeCmdBitblt.Word3.InputX = pSeSourceProcInfo->wDataX;
	SeCmdBitblt.Word3.InputY = pSeSourceProcInfo->wDataY;

	if(pBlitEx->srcAlphaModeSelect != SEINFO_BITBLT_ALPHA_DISABLE &&
		pBlitEx->destAlphaModeSelect != SEINFO_BITBLT_ALPHA_DISABLE) {
		SeCmdBitblt.Word3.RopMode = SEINFO_ALPHA_BLENDING;
		SeCmdBitblt.Word3.SelectSrcAlpha = pBlitEx->srcAlphaModeSelect;
		SeCmdBitblt.Word1.SelectDestAlpha = pBlitEx->destAlphaModeSelect;
		SeCmdBitblt.Word3.ColorKey = pBlitEx->colorKeySelect;
	} else {
		SeCmdBitblt.Word3.RopMode = SEINFO_ROP_MODE;
		SeCmdBitblt.Word2.RopCode = byRopCode;
	}

	if(byOutputAlphaModeSelect == SEINFO_OUTPUT_ALPHA_CONST) {
		//SE_SetConstAlpha(byCommandQueue, byOutputAlphaValue);
		SeCmdBitblt.WordReg5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg5.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg5.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_RESULT_ALPHA;
		SeCmdBitblt.WordReg5_1.RegisterValue = byOutputAlphaValue;
	}else{
		SeCmdBitblt.WordReg5.Reserved = 0;
		SeCmdBitblt.WordReg5.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg5_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pBlitEx->bEnableDfbColorize) {
		//SE_SetSourceColor1(cmdQue, pBlitEx->constColorValue);
		SeCmdBitblt.WordReg6.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg6.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg6.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
		SeCmdBitblt.WordReg6_1.RegisterValue = pBlitEx->constColorValue;
	}else{
		SeCmdBitblt.WordReg6.Reserved = 0;
		SeCmdBitblt.WordReg6.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg6_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pBlitEx->srcAlphaModeSelect ==SEINFO_BITBLT_ALPHA_CONST){
		SeCmdBitblt.WordReg7.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg7.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg7.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
		SeCmdBitblt.WordReg7_1.RegisterValue = pBlitEx->srcAplhaValue;
	}else{
		SeCmdBitblt.WordReg7.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg7_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pBlitEx->destAlphaModeSelect ==SEINFO_BITBLT_ALPHA_CONST){
		SeCmdBitblt.WordReg8.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg8.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg8.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_ALPHA;
		SeCmdBitblt.WordReg8_1.RegisterValue = pBlitEx->destAplhaValue;
	}else{
		SeCmdBitblt.WordReg8.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg8_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pBlitEx->colorKeySelect == SEINFO_COLORKEY_SOURCE ||
		pBlitEx->colorKeySelect == SEINFO_COLORKEY_BOTH){
		SeCmdBitblt.WordReg9.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg9.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg9.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_KEY;
		SeCmdBitblt.WordReg9_1.RegisterValue =pBlitEx->constSrcColorKeyValue;
	}else{
		SeCmdBitblt.WordReg9.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg9_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pBlitEx->colorKeySelect == SEINFO_COLORKEY_DESTINATION
		|| pBlitEx->colorKeySelect ==SEINFO_COLORKEY_BOTH){
		SeCmdBitblt.WordReg10.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdBitblt.WordReg10.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdBitblt.WordReg10.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_COLOR_KEY;
		SeCmdBitblt.WordReg10_1.RegisterValue = pBlitEx->constDstColorKeyValue;
	}else{
		SeCmdBitblt.WordReg10.OpCode = SEINFO_OPCODE_NOP;
		SeCmdBitblt.WordReg10_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if (bSetupModeSelect == SEINFO_BITBLT_SETUP_MANUAL) {
		SeCmdBitblt.Word2.StartingCorner = byStartingCorner;
		SeCmdBitblt.Word3.SrcAddressIndex = (UINT32) pSeSourceProcInfo->byBaseAddressIndex;
	}
	SeCmdBitblt.Word4.alpha_stream_mode = pBlitEx->bEnableAlphaStreamMode;

	if(pBlitEx->srcClrTranform != SEINFO_SRC_CLR_TRANSFORM_DISABLE) {
		SeCmdBitblt.Word4.directFB = 0;
		SeCmdBitblt.Word4.src_clr_transform = pBlitEx->srcClrTranform;
		SeCmdBitblt.Word4.src_clr_transparency = pBlitEx->bEnableSrcClrTransparency;
		SeCmdBitblt.Word1.OpCode = SEINFO_OPCODE_BIBLIT_EX;
		SeCmdBitblt.Word2.sync_vo = pBlitEx->bSyncVO;
		if (pBlitEx->srcClrTranform == SEINFO_SRC_CLR_TRANSFORM_ENABLE_FOR_ALPHA_ONLY ||
			pBlitEx->srcClrTranform == SEINFO_SRC_CLR_TRANSFORM_ENABLE_FOR_ALL) {
			return false;
		}
	}else if(pBlitEx->bEnableDirectFB) {

		SeCmdBitblt.Word1.OpCode = SEINFO_OPCODE_BIBLIT_EX;
		SeCmdBitblt.Word2.sync_vo = pBlitEx->bSyncVO;
		if (pBlitEx->bEnableDirectFB && pBlitEx->dfbOperation != SEINFO_DFB_OP_DISABLED)
			SeCmdBitblt.Word2.RopCode = pBlitEx->dfbOperation;

		SeCmdBitblt.Word4.directFB = pBlitEx->bEnableDirectFB;
		SeCmdBitblt.Word4.fb_dst_premultiply = pBlitEx->bEnableDfbDstPremultiply;
		SeCmdBitblt.Word4.fb_src_premulcolor = pBlitEx->bEnableDfbSrcPremulcolor;
		SeCmdBitblt.Word4.fb_src_premultiply = pBlitEx->bEnableDfbSrcPremultiply;
		SeCmdBitblt.Word4.fb_xor = pBlitEx->bEnableDfbXor;
		SeCmdBitblt.Word4.fb_colorize = pBlitEx->bEnableDfbColorize;
		SeCmdBitblt.Word4.fb_blend_coloralpha = pBlitEx->bEnableDfbReplaceSrcAlphaWithConstAlpha;
		SeCmdBitblt.Word4.fb_blend_alphachannel = pBlitEx->bEnableDfbModulateSrcAlphaWithConstAlpha;
		SeCmdBitblt.Word4.fb_demultiply = pBlitEx->bEnableDfbDemultiply;
		SeCmdBitblt.Word4.fb_sel_srcclr_blend = pBlitEx->selSrcClrBlend;
		SeCmdBitblt.Word4.fb_sel_destclr_blend = pBlitEx->selDestClrBlend;


	}else{
		SeCmdBitblt.Word4.Reserved = SEINFO_OPCODE_NOP;
	}

	SeCmdBitblt.Word5.Reserved = SEINFO_OPCODE_NOP;
	SeCmdBitblt.Word6.Reserved = SEINFO_OPCODE_NOP;
	SeCmdBitblt.Word7.Reserved = SEINFO_OPCODE_NOP;
	SeCmdBitblt.Word8.Reserved = SEINFO_OPCODE_NOP;

	WriteCmd(se_devices, (UINT8 *)&SeCmdBitblt, sizeof(SECMD_BITBLT));
	return true;
}


bool SE_Stretch_ext(
	SE_PROCINFO_T		*pSeDestinationProcInfo,
	SE_PROCINFO_T		*pSeSourceProcInfo,
	SEINFO_SACLING_TYPE	byVerticalScalingType,
	UINT32			dwVerticalScalingRatio,
	SEINFO_STRETCH_VTAP	byVerticalTapNumber,
	SEINFO_SACLING_TYPE	byHorizontalScalingType,
	UINT32			dwHorizontalScalingRatio,
	SEINFO_STRETCH_HTAP	byHorizontalTapNumber,
	SEINFO_STRETCH		byScalingAlgorithmSelect,
	SEINFO_ALPHAPROC_EN	bAlphaEnable,
	UINT8			iVerticalScalingOffset,
	void*			pExtraParam)
{
	SE_EXT_FMT_CONV_T* pEx = (SE_EXT_FMT_CONV_T*)pExtraParam;
	SECMD_EXT_STCH_BLIT se_ext_stch;

	UINT32 dwDataCounter = 0;
	UINT32 dwScalingSetting = 0;
	bool bHEnabled = (byHorizontalScalingType != SEINFO_SCALING_DISABLE ? true : false);
	bool bVEnabled = (byVerticalScalingType != SEINFO_SCALING_DISABLE ? true : false);
	UINT32 replaceParam=0;

	unsigned short tmp_coef_4t16p[32];
	unsigned short tmp_coef_8t16p[64];


	memset(&se_ext_stch, 0x00, sizeof(SECMD_EXT_STCH_BLIT));


	if((UINT32) pSeSourceProcInfo->uAddr == 0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch == 0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr == 0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch == 0x0)
		return false;

	if(pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeSourceProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeSourceProcInfo->uPitch_c1 == 0x0)
			return false;
	}

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeDestinationProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeDestinationProcInfo->uPitch_c1 == 0x0)
			return false;
	}
	se_ext_stch.WordReg1.Reserved = 0;
	se_ext_stch.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	se_ext_stch.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->st_blend_layer0.stcolorfmt);

	se_ext_stch.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	se_ext_stch.WordReg2_1.RegisterValue = pEx->st_blend_layer0.constColorValue;

#if 0
	se_ext_stch.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_stch.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SWAP_FBDC;
#else
	se_ext_stch.WordReg3.OpCode = SEINFO_OPCODE_NOP;
	se_ext_stch.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
#endif


	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_stch.WordReg3_1.RegisterValue = 0xff;
	}else if(pEx->result_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_stch.WordReg3_1.RegisterValue = 0xf0;
	}else if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_stch.WordReg3_1.RegisterValue = 0x0f;
	}else{
		se_ext_stch.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}


	//SE_WriteRegister(byCommandQueue, SEINFO_REGMODE_REGISTER, SE20INFO_REG_STRETCH, dwScalingSetting);
	dwScalingSetting = (replaceParam |
		((UINT32) bAlphaEnable << 5) |
		((UINT32) byHorizontalTapNumber << 3) |
		((UINT32) byVerticalTapNumber << 2));
	se_ext_stch.WordReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordReg4.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_stch.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SE20INFO_REG_STRETCH;
#else
	se_ext_stch.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_STRETCH;
#endif
	se_ext_stch.WordReg4_1.RegisterValue = dwScalingSetting;

	se_ext_stch.WordAddr0.Reserved = 0;
	se_ext_stch.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;

#if SE_SE20_EXT
	se_ext_stch.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_stch.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_stch.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	se_ext_stch.WordPitch0.Reserved = 0;
	se_ext_stch.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;

#if SE_SE20_EXT
	se_ext_stch.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_stch.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_stch.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	se_ext_stch.WordAddr1.Reserved = 0;
	se_ext_stch.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_stch.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_stch.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_stch.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	se_ext_stch.WordPitch1.Reserved = 0;
	se_ext_stch.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_stch.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;

#if SE_SE20_EXT
	se_ext_stch.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_stch.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_stch.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;

	if((UINT32) pSeSourceProcInfo->uAddr_c1 != 0x0) {
		se_ext_stch.WordAddr2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordAddr2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_stch.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_stch.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_stch.WordAddr2_1.RegisterValue = pSeSourceProcInfo->uAddr_c1;
	}else{
		se_ext_stch.WordAddr2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordAddr2_1.RegisterValue = SEINFO_OPCODE_NOP;

	}
	if((UINT32) pSeSourceProcInfo->uPitch_c1 !=0x0) {
		se_ext_stch.WordPitch2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordPitch2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_stch.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_stch.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_stch.WordPitch2_1.RegisterValue = pSeSourceProcInfo->uPitch_c1;
	}else{
		se_ext_stch.WordPitch2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordPitch2_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uAddr_c1 !=0x0) {
		se_ext_stch.WordAddr3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordAddr3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_stch.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_stch.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_stch.WordAddr3_1.RegisterValue = pSeDestinationProcInfo->uAddr_c1;
	}else{
		se_ext_stch.WordAddr3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordAddr3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uPitch_c1 !=0x0) {
		se_ext_stch.WordPitch3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordPitch3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_stch.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_stch.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_stch.WordPitch3_1.RegisterValue = pSeDestinationProcInfo->uPitch_c1;
	}else{
		se_ext_stch.WordPitch3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordPitch3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pEx->st_blend_layer0.bEnableDfbReplaceSrcAlphaWithConstAlpha){
		se_ext_stch.WordReg5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg5.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_stch.WordReg5.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DFB_COLORALPHA;
		se_ext_stch.WordReg5_1.RegisterValue = pEx->st_blend_layer0.constAlphaValueForBlendColorAlpha;
	}else{
		se_ext_stch.WordReg5.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg5_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pEx->st_blend_layer0.bEnableDfbModulateSrcAlphaWithConstAlpha){
		se_ext_stch.WordReg6.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg6.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_stch.WordReg6.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
		se_ext_stch.WordReg6_1.RegisterValue =pEx->st_blend_layer0.constAplhaValue;
	}else{
		se_ext_stch.WordReg6.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg6_1.RegisterValue = SEINFO_OPCODE_NOP;
	}



	if(bVEnabled) {
		//dwScalingSetting =	(iVerticalScalingOffset << 18) 			|
		dwScalingSetting = (dwVerticalScalingRatio & 0x0003FFFF);
		//SE_WriteRegister(byCommandQueue, SEINFO_REGMODE_REGISTER, SEINFO_REG_VDHS, dwScalingSetting);
		se_ext_stch.WordReg7.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg7.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_stch.WordReg7.RegisterAddress = (SEINFO_WRITEREG)SE20INFO_REG_VDHS;
#else
		se_ext_stch.WordReg7.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_VDHS;
#endif
		se_ext_stch.WordReg7_1.RegisterValue = dwScalingSetting;
	}else{
		se_ext_stch.WordReg7.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg7_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(bHEnabled) {
		dwScalingSetting = (dwHorizontalScalingRatio & 0x0003FFFF);
		//SE_WriteRegister(byCommandQueue, SEINFO_REGMODE_REGISTER, SEINFO_REG_HDHS, dwScalingSetting);
		se_ext_stch.WordReg8.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg8.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_stch.WordReg8.RegisterAddress = (SEINFO_WRITEREG)SE20INFO_REG_HDHS;
#else
		se_ext_stch.WordReg8.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_HDHS;
#endif
		se_ext_stch.WordReg8_1.RegisterValue = dwScalingSetting;
	}else{
		se_ext_stch.WordReg8.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg8_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_SOURCE ||
		pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_BOTH){
		se_ext_stch.WordReg9.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg9.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_stch.WordReg9.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_KEY;
		se_ext_stch.WordReg9_1.RegisterValue =pEx->st_blend_layer0.constSrcColorKeyValue;
	}else{
		se_ext_stch.WordReg9.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg9_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_DESTINATION
		|| pEx->st_blend_layer0.colorKeySelect ==SEINFO_COLORKEY_BOTH){
		se_ext_stch.WordReg10.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg10.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_stch.WordReg10.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_COLOR_KEY;
		se_ext_stch.WordReg10_1.RegisterValue =pEx->st_blend_layer0.constDstColorKeyValue;
	}else{
		se_ext_stch.WordReg10.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg10_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pEx->st_blend_layer0.srcAlphaModeSelect ==SEINFO_BITBLT_ALPHA_CONST){
		se_ext_stch.WordReg11.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg11.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_stch.WordReg11.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
		se_ext_stch.WordReg11_1.RegisterValue = pEx->st_blend_layer0.srcAplhaValue;
	}else{
		se_ext_stch.WordReg11.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg11_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pEx->st_blend_layer0.destAlphaModeSelect ==SEINFO_BITBLT_ALPHA_CONST){
		se_ext_stch.WordReg12.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_stch.WordReg12.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_stch.WordReg12.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_ALPHA;
		se_ext_stch.WordReg12_1.RegisterValue = pEx->st_blend_layer0.destAplhaValue;
	}else{
		se_ext_stch.WordReg12.OpCode = SEINFO_OPCODE_NOP;
		se_ext_stch.WordReg12_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
#if SE_SE20_EXT
	if(byScalingAlgorithmSelect == SEINFO_STRETCH_FIR) {
		if(bVEnabled) {
			SetVideoScalingCoeffs((unsigned short*)tmp_coef_4t16p,
				dwVerticalScalingRatio,
				iVerticalScalingOffset,
				1 << (byVerticalTapNumber+1), 0);
			for(dwDataCounter = 0; dwDataCounter < SE20INFO_STRETCH_VSCALING_COEFF_MAX; dwDataCounter +=2) {
				SE_WriteRegister2(
					(SEINFO_WRITEREG) (SE20INFO_REG_VCOEF1_32 + (dwDataCounter << 4)),
					tmp_coef_4t16p[dwDataCounter],
					(SEINFO_WRITEREG) (SE20INFO_REG_VCOEF1_32 + ((dwDataCounter+1) << 4)),
					tmp_coef_4t16p[dwDataCounter+1],
					(SEINFO_WRITEREG) (SE20INFO_REG_VCOEF1_32_2 + (dwDataCounter << 4)),
					tmp_coef_4t16p[dwDataCounter+16],
					(SEINFO_WRITEREG) (SE20INFO_REG_VCOEF1_32_2 + ((dwDataCounter+1) << 4)),
					tmp_coef_4t16p[dwDataCounter+16+1]);
			}
		}

		if(bHEnabled) {
			SetVideoScalingCoeffs((unsigned short*)tmp_coef_8t16p,
				dwHorizontalScalingRatio,
				0,
				1 << (byHorizontalTapNumber+1),
				0) ;
			for(dwDataCounter = 0; dwDataCounter < SE20INFO_STRETCH_HSCALING_COEFF_MAX; dwDataCounter+=2) {
				SE_WriteRegister2(
					(SEINFO_WRITEREG) (SE20INFO_REG_HCOEF1_32 + (dwDataCounter << 4)),
					tmp_coef_8t16p[dwDataCounter],
					(SEINFO_WRITEREG) (SE20INFO_REG_HCOEF1_32 + ((dwDataCounter+1) << 4)),
					tmp_coef_8t16p[dwDataCounter+1],
					(SEINFO_WRITEREG) (SE20INFO_REG_HCOEF1_32_2 + (dwDataCounter << 4)),
					tmp_coef_8t16p[dwDataCounter+32],
					(SEINFO_WRITEREG) (SE20INFO_REG_HCOEF1_32_2 + ((dwDataCounter+1) << 4)),
					tmp_coef_8t16p[dwDataCounter+32+1]);
			}
		}
	}
#else
	if(byScalingAlgorithmSelect == SEINFO_STRETCH_FIR) {
		if(bVEnabled) {
			SetVideoScalingCoeffs((unsigned short*)tmp_coef_4t16p,
				dwVerticalScalingRatio,
				iVerticalScalingOffset,
				1 << (byVerticalTapNumber+1),
				0) ;
			for(dwDataCounter = 0; dwDataCounter < SEINFO_STRETCH_VSCALING_COEFF_MAX; dwDataCounter +=2) {
				SE_WriteRegister2(
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0 + (dwDataCounter << 2)),
					tmp_coef_4t16p[dwDataCounter],
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0 + ((dwDataCounter+1) << 2)),
					tmp_coef_4t16p[dwDataCounter+1],
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0_16 + (dwDataCounter << 2)),
					tmp_coef_4t16p[dwDataCounter+16],
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0_16 + ((dwDataCounter+1) << 2)),
					tmp_coef_4t16p[dwDataCounter+16+1]);
			}
		}

		if(bHEnabled) {
			SetVideoScalingCoeffs((unsigned short*)tmp_coef_8t16p,
				dwHorizontalScalingRatio,
				0,
				1 << (byHorizontalTapNumber+1),
				0) ;
			for(dwDataCounter = 0; dwDataCounter < SEINFO_STRETCH_HSCALING_COEFF_MAX; dwDataCounter+=2) {

			SE_WriteRegister2(
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0 + (dwDataCounter << 2)),
					tmp_coef_8t16p[dwDataCounter],
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0 + ((dwDataCounter+1) << 2)),
					tmp_coef_8t16p[dwDataCounter+1],
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0_32 + (dwDataCounter << 2)),
					tmp_coef_8t16p[dwDataCounter+32],
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0_32 + ((dwDataCounter+1) << 2)),
					tmp_coef_8t16p[dwDataCounter+32+1]);
			}
		}
	}


#endif
	se_ext_stch.Word1.opcode = SEINFO_OPCODE_EXT_FMT;
	se_ext_stch.Word1.rslt_fmt = pEx->result_format;
	//if rslt is FBC , need c1, c2 index!
	se_ext_stch.Word1.lay_ctl = 0;
	se_ext_stch.Word1.lay_num = pEx->st_blend_layer0.bEnableWithBitblit?1:0;
	//se_ext_stch.Word1.rslt_argb_order = CONSTENDIAN 0x1d; //FPGA-->BGRA
	se_ext_stch.Word1.rslt_argb_order = ARGBENDIAN;   //FPGA-->BGRA
	se_ext_stch.Word1.src2_argb_order = ARGBENDIAN;

	se_ext_stch.Word2.rslt_out_x = pSeDestinationProcInfo->wDataX;
	se_ext_stch.Word2.rslt_out_y = pSeDestinationProcInfo->wDataY;

	se_ext_stch.Word3.rslt_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_stch.Word3.rslt_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;

	se_ext_stch.Word4.src1_inpt_w = pSeDestinationProcInfo->wDataWidth;
	se_ext_stch.Word4.src1_inpt_h = pSeDestinationProcInfo->wDataHeight;
	se_ext_stch.Word4.src1_fmt = pEx->src1_format;

	se_ext_stch.Word5.src1_inpt_x = pSeDestinationProcInfo->wDataX;
	se_ext_stch.Word5.src1_inpt_y = pSeDestinationProcInfo->wDataY;
	//se_ext_stch.Word5.src1_argb_order = CONSTENDIAN 0x1d; //FPGA-->BGRA
	se_ext_stch.Word5.src1_argb_order = ARGBENDIAN ; //FPGA-->BGRA


	se_ext_stch.Word6.src1_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_stch.Word6.src1_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;


	if(pEx->st_blend_layer0.bEnableWithBitblit) {
		se_ext_stch.Word1.lay_ctl = 1;

		//se_ext_stch.Word6.src1_inpt_sel = pEx->src1_select; //must be 0
		se_ext_stch.Word7.src2_inpt_x = pSeSourceProcInfo->wDataX;
		se_ext_stch.Word7.src2_inpt_y = pSeSourceProcInfo->wDataY;
		se_ext_stch.Word7.src2_fmt = pEx->src2_format;
		//se_ext_conv.Word8.src2_inpt_sel = pEx->src2_select; //must be 0
		se_ext_stch.Word8.src2_addr_index = (UINT32)pSeSourceProcInfo->byBaseAddressIndex;
		se_ext_stch.Word8.src2_chr1_addr_index = (UINT32)pSeSourceProcInfo->byChronmaAddressIndex;
		se_ext_stch.Word5.src1_fcv_stch = 0;
		se_ext_stch.Word9.lay_num_ext = 3;
		//se_ext_stch.Word9.sel_s2_alpha = pEx->st_blend_layer0.destAlphaModeSelect;
		//se_ext_stch.Word9.sel_s1_alpha = pEx->st_blend_layer0.srcAlphaModeSelect;

		se_ext_stch.Word9.sel_s1_alpha = pEx->st_blend_layer0.destAlphaModeSelect;
		se_ext_stch.Word9.sel_s2_alpha = pEx->st_blend_layer0.srcAlphaModeSelect;

		se_ext_stch.Word10.fb_sel_destclr_blend_1 = pEx->st_blend_layer0.selDestClrBlend;
		se_ext_stch.Word10.fb_sel_srcclr_blend_1 = pEx->st_blend_layer0.selSrcClrBlend;
		se_ext_stch.Word10.fb_demultiply_1 = pEx->st_blend_layer0.bEnableDfbDemultiply;
		//set alpha
		se_ext_stch.Word10.fb_blend_alphachannel_1 = pEx->st_blend_layer0.bEnableDfbModulateSrcAlphaWithConstAlpha;
		//set fb coloralpha
		se_ext_stch.Word10.fb_blend_coloralpha_1 = pEx->st_blend_layer0.bEnableDfbReplaceSrcAlphaWithConstAlpha;
		se_ext_stch.Word10.fb_colorize_1 = pEx->st_blend_layer0.bEnableDfbColorize;
		se_ext_stch.Word10.fb_xor_1 = pEx->st_blend_layer0.bEnableDfbXor;
		se_ext_stch.Word10.fb_src_premultiply_1 = pEx->st_blend_layer0.bEnableDfbSrcPremultiply;
		se_ext_stch.Word10.fb_src_premulcolor_1 = pEx->st_blend_layer0.bEnableDfbSrcPremulcolor;
		se_ext_stch.Word10.fb_dst_premultiply_1 = pEx->st_blend_layer0.bEnableDfbDstPremultiply;
		//if(pEx->st_blend_layer0.ropMode == SEINFO_ALPHA_BLENDING)
		se_ext_stch.Word10.blend_sel_1 = 0x2;
		se_ext_stch.Word10.fb_sel_srcclr_blend_1 = pEx->st_blend_layer0.selSrcClrBlend;
		se_ext_stch.Word10.fb_sel_destclr_blend_1 = pEx->st_blend_layer0.selDestClrBlend;

		se_ext_stch.Word10.color_key_1 = pEx->st_blend_layer0.colorKeySelect;
		if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_SOURCE)
			se_ext_stch.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;
		else if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_DESTINATION)
			se_ext_stch.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;
		else if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_BOTH )
			se_ext_stch.Word10.rop_code_1 = SEINFO_ROPCODE_BLACK;

		se_ext_stch.Word12.stch1_out_w = pSeDestinationProcInfo->wDataWidth;
		se_ext_stch.Word12.stch1_out_h = pSeDestinationProcInfo->wDataHeight;

		se_ext_stch.Word12.stch1_src = 0x2;

		se_ext_stch.Word12.stch1_algo = 0;
		se_ext_stch.Word12.stch1_h_en = bHEnabled;
		se_ext_stch.Word12.stch1_v_en = bVEnabled;


		se_ext_stch.Word13.src2_inpt_w = pSeSourceProcInfo->wDataWidth;
		se_ext_stch.Word13.src2_inpt_h = pSeSourceProcInfo->wDataHeight;
		se_ext_stch.Word14.src2_out_x = pSeDestinationProcInfo->wDataX;
		se_ext_stch.Word14.src2_out_y = pSeDestinationProcInfo->wDataY;

#if 0
		se_ext_stch.Word15.stch2_out_w = pSeDestinationProcInfo->wDataWidth;
		se_ext_stch.Word15.stch2_out_h = pSeDestinationProcInfo->wDataHeight;
		se_ext_stch.Word15.stch2_src = 0x2;
		se_ext_stch.Word15.stch2_h_en = bHEnabled;
		se_ext_stch.Word15.stch2_v_en = bVEnabled;
#endif
		se_ext_stch.Word16.Reserved = SEINFO_OPCODE_NOP;

	} else {

		if(pEx->src1_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
			if((UINT32) pSeSourceProcInfo->uAddr_c1 == 0x0)
				return false;
			if((UINT32) pSeSourceProcInfo->uPitch_c1 == 0x0)
				return false;
		}

		se_ext_stch.Word4.src1_inpt_w = pSeSourceProcInfo->wDataWidth;
		se_ext_stch.Word4.src1_inpt_h = pSeSourceProcInfo->wDataHeight;
		se_ext_stch.Word4.src1_fmt = pEx->src2_format;

		se_ext_stch.Word5.src1_inpt_x = pSeSourceProcInfo->wDataX;
		se_ext_stch.Word5.src1_inpt_y = pSeSourceProcInfo->wDataY;
		se_ext_stch.Word5.src1_argb_order = ARGBENDIAN ; //FPGA-->BGRA

		se_ext_stch.Word6.src1_addr_index = (UINT32)pSeSourceProcInfo->byBaseAddressIndex;
		se_ext_stch.Word6.src1_chr1_addr_index = (UINT32)pSeSourceProcInfo->byChronmaAddressIndex;

		se_ext_stch.Word5.src1_fcv_stch = 1;

		se_ext_stch.Word9.lay_num_ext = 2;
		se_ext_stch.Word10.blend_sel_1 = 0x0;
		se_ext_stch.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;
		se_ext_stch.Word12.stch1_out_w = pSeDestinationProcInfo->wDataWidth;
		se_ext_stch.Word12.stch1_out_h = pSeDestinationProcInfo->wDataHeight;
		se_ext_stch.Word12.stch1_src = 0x1;
		se_ext_stch.Word12.stch1_algo = 0;
		se_ext_stch.Word12.stch1_h_en = bHEnabled;
		se_ext_stch.Word12.stch1_v_en = bVEnabled;
		se_ext_stch.Word13.src2_inpt_w = SEINFO_OPCODE_NOP;
		se_ext_stch.Word14.src2_out_x = SEINFO_OPCODE_NOP;
		se_ext_stch.Word15.stch2_out_w = SEINFO_OPCODE_NOP;
		se_ext_stch.Word16.Reserved = SEINFO_OPCODE_NOP;
	}

#if SE_SE20
	if(se_dummy_stch(&se_ext_stch) == false)
		return false;

#endif


	WriteCmd(se_devices, (UINT8 *)&se_ext_stch, sizeof(SECMD_EXT_STCH_BLIT));
	return true;
}

bool SE_Stretch(
	SE_PROCINFO_T*		pSeDestinationProcInfo,
	SE_PROCINFO_T*		pSeSourceProcInfo,
	SEINFO_SACLING_TYPE	byVerticalScalingType,
	UINT32			dwVerticalScalingRatio,
	SEINFO_STRETCH_VTAP	byVerticalTapNumber,
	SEINFO_SACLING_TYPE	byHorizontalScalingType,
	UINT32			dwHorizontalScalingRatio,
	SEINFO_STRETCH_HTAP	byHorizontalTapNumber,
	SEINFO_STRETCH  	byScalingAlgorithmSelect,
	SEINFO_ALPHAPROC_EN	bAlphaEnable,
	UINT8			iVerticalScalingOffset,
	void*			pExtraParam)
{
	SE_BLEND_EX_T* pStretchEx = (SE_BLEND_EX_T*)pExtraParam;
	SECMD_STRETCH SeCmdStretch;
	UINT32 dwDataCounter = 0;
	UINT32 dwScalingSetting = 0;
	bool bHEnabled = (byHorizontalScalingType != SEINFO_SCALING_DISABLE ? true : false);
	bool bVEnabled = (byVerticalScalingType != SEINFO_SCALING_DISABLE ? true : false);
	UINT32 replaceParam=0;
	SE_BLEND_EX_T* pBlitEx = (SE_BLEND_EX_T*)pExtraParam;

	unsigned short tmp_coef_4t16p[32];
	unsigned short tmp_coef_8t16p[64];

	memset(&SeCmdStretch, 0x00, sizeof(SECMD_STRETCH));

	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	SeCmdStretch.WordReg1.Reserved = 0;
	SeCmdStretch.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	SeCmdStretch.WordReg1_1.RegisterValue = get_SetColorFormat(&pStretchEx->stcolorfmt);

	SeCmdStretch.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	SeCmdStretch.WordReg2_1.RegisterValue = pStretchEx->constColorValue;


	SeCmdStretch.WordReg3.Reserved = 0;
	SeCmdStretch.WordReg3.OpCode = SEINFO_OPCODE_NOP;
	SeCmdStretch.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
	SeCmdStretch.WordReg4.Reserved = 0;
	SeCmdStretch.WordReg4.OpCode = SEINFO_OPCODE_NOP;
	SeCmdStretch.WordReg4_1.RegisterValue = SEINFO_OPCODE_NOP;

	SeCmdStretch.WordAddr0.Reserved = 0;
	SeCmdStretch.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdStretch.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	SeCmdStretch.WordPitch0.Reserved = 0;
	SeCmdStretch.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdStretch.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	SeCmdStretch.WordAddr1.Reserved = 0;
	SeCmdStretch.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdStretch.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	SeCmdStretch.WordPitch1.Reserved = 0;
	SeCmdStretch.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdStretch.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;



	if(bVEnabled) {
		//dwScalingSetting =	(iVerticalScalingOffset << 18) 			|
		dwScalingSetting = (dwVerticalScalingRatio & 0x0003FFFF);
		SeCmdStretch.WordReg5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdStretch.WordReg5.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdStretch.WordReg5.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_VDHS;
		SeCmdStretch.WordReg5_1.RegisterValue = dwScalingSetting;
	}else{
		SeCmdStretch.WordReg5.OpCode = SEINFO_OPCODE_NOP;
		SeCmdStretch.WordReg5_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(bHEnabled) {
		dwScalingSetting = (dwHorizontalScalingRatio & 0x0003FFFF);
		SeCmdStretch.WordReg6.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdStretch.WordReg6.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdStretch.WordReg6.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_HDHS;
		SeCmdStretch.WordReg6_1.RegisterValue = dwScalingSetting;
	}else{
		SeCmdStretch.WordReg6.OpCode = SEINFO_OPCODE_NOP;
		SeCmdStretch.WordReg6_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	SeCmdStretch.WordReg7.Reserved = 0;
	SeCmdStretch.WordReg7.OpCode = SEINFO_OPCODE_NOP;
	SeCmdStretch.WordReg7_1.RegisterValue = SEINFO_OPCODE_NOP;

	if(pStretchEx->colorKeySelect == SEINFO_COLORKEY_SOURCE ||
		pStretchEx->colorKeySelect == SEINFO_COLORKEY_BOTH){
		SeCmdStretch.WordReg9.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdStretch.WordReg9.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdStretch.WordReg9.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_KEY;
		SeCmdStretch.WordReg9_1.RegisterValue =pStretchEx->constSrcColorKeyValue;
	}else{
		SeCmdStretch.WordReg9.OpCode = SEINFO_OPCODE_NOP;
		SeCmdStretch.WordReg9_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pStretchEx->colorKeySelect == SEINFO_COLORKEY_DESTINATION
		|| pStretchEx->colorKeySelect ==SEINFO_COLORKEY_BOTH){
		SeCmdStretch.WordReg10.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdStretch.WordReg10.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdStretch.WordReg10.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_COLOR_KEY;
		SeCmdStretch.WordReg10_1.RegisterValue = pStretchEx->constDstColorKeyValue;
	}else{
		SeCmdStretch.WordReg10.OpCode = SEINFO_OPCODE_NOP;
		SeCmdStretch.WordReg10_1.RegisterValue = SEINFO_OPCODE_NOP;
	}


	//SE_WriteRegister(byCommandQueue, SEINFO_REGMODE_REGISTER, SEINFO_REG_STRETCH, dwScalingSetting);

	replaceParam = (UINT32)pBlitEx->replaceAlpha << 7 | (UINT32)pBlitEx->replaceAlpha << 6;
	dwScalingSetting = (replaceParam |
		((UINT32) bAlphaEnable << 5) |
		((UINT32) byHorizontalTapNumber << 3) |
		((UINT32) byVerticalTapNumber << 2));
	SeCmdStretch.WordReg8.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdStretch.WordReg8.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdStretch.WordReg8.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_STRETCH;
	SeCmdStretch.WordReg8_1.RegisterValue = dwScalingSetting;

	if(byScalingAlgorithmSelect == SEINFO_STRETCH_FIR) {
		if(bVEnabled) {
			SetVideoScalingCoeffs((unsigned short*)tmp_coef_4t16p,
				dwVerticalScalingRatio,
				iVerticalScalingOffset,
				1 << (byVerticalTapNumber+1),
				0) ;
			for(dwDataCounter = 0; dwDataCounter < SEINFO_STRETCH_VSCALING_COEFF_MAX; dwDataCounter +=2) {
				SE_WriteRegister2(
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0 + (dwDataCounter << 2)),
					tmp_coef_4t16p[dwDataCounter],
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0 + ((dwDataCounter+1) << 2)),
					tmp_coef_4t16p[dwDataCounter+1],
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0_16 + (dwDataCounter << 2)),
					tmp_coef_4t16p[dwDataCounter+16],
					(SEINFO_WRITEREG) (SEINFO_REG_VCOEF0_16 + ((dwDataCounter+1) << 2)),
					tmp_coef_4t16p[dwDataCounter+16+1]);
			}
		}

		if(bHEnabled) {
			SetVideoScalingCoeffs((unsigned short*)tmp_coef_8t16p,
				dwHorizontalScalingRatio,
				0,
				1 << (byHorizontalTapNumber+1),
				0) ;
			for(dwDataCounter = 0; dwDataCounter < SEINFO_STRETCH_HSCALING_COEFF_MAX; dwDataCounter+=2) {

			SE_WriteRegister2(
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0 + (dwDataCounter << 2)),
					tmp_coef_8t16p[dwDataCounter],
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0 + ((dwDataCounter+1) << 2)),
					tmp_coef_8t16p[dwDataCounter+1],
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0_32 + (dwDataCounter << 2)),
					tmp_coef_8t16p[dwDataCounter+32],
					(SEINFO_WRITEREG) (SEINFO_REG_HCOEF0_32 + ((dwDataCounter+1) << 2)),
					tmp_coef_8t16p[dwDataCounter+32+1]);
			}
		}
	}

	SeCmdStretch.Word1.SrcInterleaving = pSeSourceProcInfo->bInterleavingModeEnable;
	SeCmdStretch.Word1.VScalingEnable = bVEnabled;
	SeCmdStretch.Word1.HScalingEnable = bHEnabled;
	SeCmdStretch.Word1.ColorKey = (pStretchEx->colorKeySelect == SEINFO_COLORKEY_SOURCE) ? SEINFO_COLORKEY_SOURCE : SEINFO_COLORKEY_NONE;
	SeCmdStretch.Word1.OutputY = pSeDestinationProcInfo->wDataY;
	SeCmdStretch.Word1.OutputX = pSeDestinationProcInfo->wDataX;
	SeCmdStretch.Word1.OpCode = SEINFO_OPCODE_STRETCH;

	SeCmdStretch.Word2.ScalingAlgorithm = byScalingAlgorithmSelect;
	SeCmdStretch.Word2.Reserved = 0;
	SeCmdStretch.Word2.StretchBitblit = 0;
	SeCmdStretch.Word2.directFB = 0;
	SeCmdStretch.Word2.OutputHeight = pSeDestinationProcInfo->wDataHeight;
	SeCmdStretch.Word2.OutputWidth = pSeDestinationProcInfo->wDataWidth;

	SeCmdStretch.Word3.SrcAddressIndex = pSeSourceProcInfo->byBaseAddressIndex;
	SeCmdStretch.Word3.DestInterleaving = pSeDestinationProcInfo->bInterleavingModeEnable;;
	SeCmdStretch.Word3.InputY = pSeSourceProcInfo->wDataY;
	SeCmdStretch.Word3.InputX = pSeSourceProcInfo->wDataX;

	SeCmdStretch.Word4.DestAddressIndex = pSeDestinationProcInfo->byBaseAddressIndex;
	SeCmdStretch.Word4.InputHeight = pSeSourceProcInfo->wDataHeight;
	SeCmdStretch.Word4.InputWidth = pSeSourceProcInfo->wDataWidth;

#if SE_SE20 || SE_OLD

	if (pStretchEx->bEnableWithBitblit && pStretchEx->bEnableDirectFB) {
		SeCmdStretch.Word2.StretchBitblit = pStretchEx->bEnableWithBitblit;

		if(pStretchEx->srcAlphaModeSelect != SEINFO_BITBLT_ALPHA_DISABLE &&
			pStretchEx->destAlphaModeSelect != SEINFO_BITBLT_ALPHA_DISABLE /*&&
			pStretchEx->bEnableDirectFB*/) {

			SeCmdStretch.Word5.rop_mode = SEINFO_ALPHA_BLENDING;
			SeCmdStretch.Word5.sel_src_alpha = pStretchEx->srcAlphaModeSelect;
			SeCmdStretch.Word5.sel_dest_alpha = pStretchEx->destAlphaModeSelect;
			SeCmdStretch.Word5.bitblit_color_key = pStretchEx->colorKeySelect;
			SeCmdStretch.Word5.sel_output_alpha = pStretchEx->outputAlphaModeSelect == SEINFO_OUTPUT_ALPHA_CONST ? 1 : 0;

			//SE_SetSourceAlpha1(cmdQue, pEx->srcAplhaValue);
			SeCmdStretch.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdStretch.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
			SeCmdStretch.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
			SeCmdStretch.WordReg3_1.RegisterValue = pStretchEx->srcAplhaValue;

			//SE_SetDestAlpha(cmdQue, pEx->destAplhaValue);
			SeCmdStretch.WordReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdStretch.WordReg4.Clut = SEINFO_REGMODE_REGISTER;
			SeCmdStretch.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_ALPHA;
			SeCmdStretch.WordReg4_1.RegisterValue = pStretchEx->destAplhaValue;

			if (pStretchEx->dfbOperation != SEINFO_DFB_OP_DISABLED)
				SeCmdStretch.Word5.rop_code = pStretchEx->dfbOperation;

		} else {
			SeCmdStretch.Word5.rop_mode = SEINFO_ROP_MODE;
			SeCmdStretch.Word5.rop_code = pStretchEx->ropCode;
		}

		SeCmdStretch.Word5.sync_vo = pStretchEx->bSyncVO;
		SeCmdStretch.Word5.src_clr_transform = pStretchEx->srcClrTranform;
		SeCmdStretch.Word5.src_clr_transparency = pStretchEx->bEnableSrcClrTransparency;
		SeCmdStretch.Word2.directFB = pStretchEx->bEnableDirectFB;
		SeCmdStretch.Word5.fb_dst_premultiply = pStretchEx->bEnableDfbDstPremultiply;
		SeCmdStretch.Word5.fb_src_premulcolor = pStretchEx->bEnableDfbSrcPremulcolor;
		SeCmdStretch.Word5.fb_src_premultiply = pStretchEx->bEnableDfbSrcPremultiply;

		SeCmdStretch.Word5.fb_xor = pStretchEx->bEnableDfbXor;
		SeCmdStretch.Word5.fb_colorize = pStretchEx->bEnableDfbColorize;
		SeCmdStretch.Word5.fb_blend_coloralpha = pStretchEx->bEnableDfbReplaceSrcAlphaWithConstAlpha;
		SeCmdStretch.Word5.fb_blend_alphachannel = pStretchEx->bEnableDfbModulateSrcAlphaWithConstAlpha;

		SeCmdStretch.Word5.fb_demultiply = pStretchEx->bEnableDfbDemultiply;
		SeCmdStretch.Word5.fb_sel_srcclr_blend = pStretchEx->selSrcClrBlend;
		SeCmdStretch.Word5.fb_sel_destclr_blend = pStretchEx->selDestClrBlend;
		SeCmdStretch.Word5.sel_output_alpha = pStretchEx->outputAlphaModeSelect == SEINFO_OUTPUT_ALPHA_CONST ? 1 : 0;

		if(pStretchEx->bEnableDfbReplaceSrcAlphaWithConstAlpha) {
			//SE_SetDFBColorAlpha(cmdQue, pStretchEx->constAlphaValueForBlendColorAlpha);
			SeCmdStretch.WordReg7.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdStretch.WordReg7.Clut = SEINFO_REGMODE_REGISTER;
			SeCmdStretch.WordReg7.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DFB_COLORALPHA;
			SeCmdStretch.WordReg7_1.RegisterValue = pStretchEx->constAlphaValueForBlendColorAlpha;
		}

		if(pStretchEx->bEnableDfbModulateSrcAlphaWithConstAlpha)
			//SE_SetSourceAlpha1(cmdQue, pStretchEx->constAplhaValue);
			SeCmdStretch.WordReg3_1.RegisterValue = pStretchEx->constAplhaValue;

		if (pStretchEx->srcClrTranform == SEINFO_SRC_CLR_TRANSFORM_ENABLE_FOR_ALPHA_ONLY ||
			pStretchEx->srcClrTranform == SEINFO_SRC_CLR_TRANSFORM_ENABLE_FOR_ALL) {
			return false;
		}
	}else{
		SeCmdStretch.Word5.fb_sel_destclr_blend = SEINFO_OPCODE_NOP;
	}
#else
	SeCmdStretch.Word5.fb_sel_destclr_blend = SEINFO_OPCODE_NOP;
#endif

	SeCmdStretch.Word6.Reserved = SEINFO_OPCODE_NOP;
	SeCmdStretch.Word7.Reserved = SEINFO_OPCODE_NOP;
	SeCmdStretch.Word8.Reserved = SEINFO_OPCODE_NOP;
	WriteCmd(se_devices, (UINT8 *)&SeCmdStretch, sizeof(SECMD_STRETCH));
	return true;
}



bool SE_FormatConversion(
	SE_PROCINFO_T*		pSeDestinationProcInfo,
	SE_PROCINFO_T*		pSeSourceProcInfo,
	SEINFO_CONVERSION	byConversionModeSelect,
	SEINFO_DEST_FORMAT	byDestinationFormatSelect,
	SEINFO_SRC_FORMAT	bySourceFormatSelect,
	SEINFO_COLORKEY		byColorKeySelect,
	SEINFO_OUTPUT_ALPHAMODE	byOutputAlphaModeSelect,
	UINT8			byOutputAlphaValue,
	void*			pExtraParam)
{
	SECMD_FORMAT_CONVERSION	SeCmdFormatConversion;
	SE_BLEND_EX_T* pEx = (SE_BLEND_EX_T*)pExtraParam;

	memset((void *)&SeCmdFormatConversion, 0, sizeof(SECMD_FORMAT_CONVERSION));



	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

#if 1
	SeCmdFormatConversion.WordReg1.Reserved = 0;
	SeCmdFormatConversion.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdFormatConversion.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdFormatConversion.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	SeCmdFormatConversion.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->stcolorfmt);
#else

	SeCmdFormatConversion.WordReg1.Reserved = 0;
	SeCmdFormatConversion.WordReg1.OpCode = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.WordReg1_1.RegisterValue = SEINFO_OPCODE_NOP;
#endif
	SeCmdFormatConversion.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdFormatConversion.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdFormatConversion.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	SeCmdFormatConversion.WordReg2_1.RegisterValue = pEx->constColorValue;

	SeCmdFormatConversion.WordReg3.Reserved = 0;
	SeCmdFormatConversion.WordReg3.OpCode = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.WordReg4.Reserved = 0;
	SeCmdFormatConversion.WordReg4.OpCode = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.WordReg4_1.RegisterValue = SEINFO_OPCODE_NOP;

	if(byOutputAlphaModeSelect == SEINFO_OUTPUT_ALPHA_CONST) {
		//SE_WriteRegister(byCommandQueue, SEINFO_REGMODE_REGISTER, SEINFO_REG_RESULT_ALPHA, byOutputAlphaValue);
		SeCmdFormatConversion.WordReg5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		SeCmdFormatConversion.WordReg5.Clut = SEINFO_REGMODE_REGISTER;
		SeCmdFormatConversion.WordReg5.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_RESULT_ALPHA;
		SeCmdFormatConversion.WordReg5_1.RegisterValue = byOutputAlphaValue;
	}else{
		SeCmdFormatConversion.WordReg5.Reserved = 0;
		SeCmdFormatConversion.WordReg5.OpCode = SEINFO_OPCODE_NOP;
		SeCmdFormatConversion.WordReg5_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	SeCmdFormatConversion.WordReg6.Reserved = 0;
	SeCmdFormatConversion.WordReg6.OpCode = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.WordReg6_1.RegisterValue = SEINFO_OPCODE_NOP;


	SeCmdFormatConversion.WordAddr0.Reserved = 0;
	SeCmdFormatConversion.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdFormatConversion.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdFormatConversion.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdFormatConversion.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	SeCmdFormatConversion.WordPitch0.Reserved = 0;
	SeCmdFormatConversion.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdFormatConversion.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdFormatConversion.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdFormatConversion.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	SeCmdFormatConversion.WordAddr1.Reserved = 0;
	SeCmdFormatConversion.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdFormatConversion.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdFormatConversion.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdFormatConversion.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	SeCmdFormatConversion.WordPitch1.Reserved = 0;
	SeCmdFormatConversion.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdFormatConversion.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdFormatConversion.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdFormatConversion.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;


//-------------------------------------------------------------
	SeCmdFormatConversion.Word1.ConversionMode = byConversionModeSelect;
	SeCmdFormatConversion.Word1.ColorKey = byColorKeySelect;
	SeCmdFormatConversion.Word1.SelectOutputAlpha = byOutputAlphaModeSelect;
	SeCmdFormatConversion.Word1.Width = pSeDestinationProcInfo->wDataWidth;
	SeCmdFormatConversion.Word1.Height = pSeDestinationProcInfo->wDataHeight;
	SeCmdFormatConversion.Word1.OpCode = SEINFO_OPCODE_FORMAT_CONVERSION;

	SeCmdFormatConversion.Word2.SourceFormat = bySourceFormatSelect;
	SeCmdFormatConversion.Word2.InputX = pSeSourceProcInfo->wDataX;
	SeCmdFormatConversion.Word2.InputY = pSeSourceProcInfo->wDataY;
	SeCmdFormatConversion.Word2.FormatConversionBitblit = 0;
	SeCmdFormatConversion.Word2.directFB = 0;
/*CONFIG_SE_COPY_WITH_FMTCONV*/

	if(byDestinationFormatSelect == SEINFO_DEST_FORMAT_ARGB8888 && bySourceFormatSelect == SEINFO_SRC_FORMAT_ARGB8888)
		SeCmdFormatConversion.Word2.ARGB8888MatrixEnable=1;

	SeCmdFormatConversion.Word3.DestinationFormat = byDestinationFormatSelect;
	SeCmdFormatConversion.Word3.OutputX = pSeDestinationProcInfo->wDataX;
	SeCmdFormatConversion.Word3.OutputY = pSeDestinationProcInfo->wDataY;

	SeCmdFormatConversion.Word4.SrcAddressIndex = pSeSourceProcInfo->byBaseAddressIndex;
	SeCmdFormatConversion.Word4.DestAddressIndex = pSeDestinationProcInfo->byBaseAddressIndex;
	if(byConversionModeSelect == SEINFO_CONVERSION_ARGB_YUV)
		SeCmdFormatConversion.Word4.ChromaAddressIndex = pSeDestinationProcInfo->byChronmaAddressIndex;
	else
		SeCmdFormatConversion.Word4.ChromaAddressIndex = pSeSourceProcInfo->byChronmaAddressIndex;

	if (pEx->bEnableWithBitblit) {
		SeCmdFormatConversion.Word5.sync_vo = pEx->bSyncVO;
		SeCmdFormatConversion.Word2.FormatConversionBitblit = pEx->bEnableWithBitblit;
		SeCmdFormatConversion.Word2.directFB = pEx->bEnableDirectFB;


		if(!pEx->bEnableDirectFB) {
			if(pEx->ropMode == SEINFO_ROP_MODE) {
				SeCmdFormatConversion.Word5.rop_mode = SEINFO_ROP_MODE;
				SeCmdFormatConversion.Word5.rop_code = pEx->ropCode;
			}else {
				SeCmdFormatConversion.Word5.sel_src_alpha = pEx->srcAlphaModeSelect;
				SeCmdFormatConversion.Word5.sel_dest_alpha = pEx->destAlphaModeSelect;

				//SE_SetSourceAlpha1(cmdQue, pEx->srcAplhaValue);
				SeCmdFormatConversion.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
				SeCmdFormatConversion.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
				SeCmdFormatConversion.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
				SeCmdFormatConversion.WordReg3_1.RegisterValue = pEx->srcAplhaValue;

				//SE_SetDestAlpha(cmdQue, pEx->destAplhaValue);
				SeCmdFormatConversion.WordReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
				SeCmdFormatConversion.WordReg4.Clut = SEINFO_REGMODE_REGISTER;
				SeCmdFormatConversion.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_ALPHA;
				SeCmdFormatConversion.WordReg4_1.RegisterValue = pEx->destAplhaValue;

				SeCmdFormatConversion.Word5.bitblit_color_key = pEx->colorKeySelect;
			}
		}else{

			SeCmdFormatConversion.Word5.rop_mode = SEINFO_ALPHA_BLENDING;
			SeCmdFormatConversion.Word5.sel_src_alpha = pEx->srcAlphaModeSelect;
			SeCmdFormatConversion.Word5.sel_dest_alpha = pEx->destAlphaModeSelect;
			SeCmdFormatConversion.Word5.bitblit_color_key = pEx->colorKeySelect;
			if (pEx->dfbOperation != SEINFO_DFB_OP_DISABLED)
				SeCmdFormatConversion.Word5.rop_code = pEx->dfbOperation;

			//SE_SetSourceAlpha1(cmdQue, pEx->srcAplhaValue);
			SeCmdFormatConversion.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdFormatConversion.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
			SeCmdFormatConversion.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
			SeCmdFormatConversion.WordReg3_1.RegisterValue = pEx->srcAplhaValue;

			//SE_SetDestAlpha(cmdQue, pEx->destAplhaValue);
			SeCmdFormatConversion.WordReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdFormatConversion.WordReg4.Clut = SEINFO_REGMODE_REGISTER;
			SeCmdFormatConversion.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_ALPHA;
			SeCmdFormatConversion.WordReg4_1.RegisterValue = pEx->destAplhaValue;

			SeCmdFormatConversion.Word5.src_clr_transform = pEx->srcClrTranform;
			SeCmdFormatConversion.Word5.src_clr_transparency = pEx->bEnableSrcClrTransparency;
			SeCmdFormatConversion.Word5.fb_dst_premultiply = pEx->bEnableDfbDstPremultiply;
			SeCmdFormatConversion.Word5.fb_src_premulcolor = pEx->bEnableDfbSrcPremulcolor;
			SeCmdFormatConversion.Word5.fb_src_premultiply = pEx->bEnableDfbSrcPremultiply;
			SeCmdFormatConversion.Word5.fb_xor = pEx->bEnableDfbXor;
			SeCmdFormatConversion.Word5.fb_colorize = pEx->bEnableDfbColorize;
			SeCmdFormatConversion.Word5.fb_blend_coloralpha = pEx->bEnableDfbReplaceSrcAlphaWithConstAlpha;
			SeCmdFormatConversion.Word5.fb_blend_alphachannel = pEx->bEnableDfbModulateSrcAlphaWithConstAlpha;
			SeCmdFormatConversion.Word5.fb_demultiply = pEx->bEnableDfbDemultiply;
			SeCmdFormatConversion.Word5.fb_sel_srcclr_blend = pEx->selSrcClrBlend;
			SeCmdFormatConversion.Word5.fb_sel_destclr_blend = pEx->selDestClrBlend;

			if (pEx->bEnableDfbSrcPremulcolor ||
				pEx->bEnableDfbReplaceSrcAlphaWithConstAlpha ||
				pEx->bEnableDfbModulateSrcAlphaWithConstAlpha) {
				//SE_SetSourceAlpha1(cmdQue, pEx->constAplhaValue);
				SeCmdFormatConversion.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
				SeCmdFormatConversion.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
				SeCmdFormatConversion.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
				SeCmdFormatConversion.WordReg3_1.RegisterValue = pEx->constAplhaValue;
			}

			if (pEx->srcClrTranform == SEINFO_SRC_CLR_TRANSFORM_ENABLE_FOR_ALPHA_ONLY ||
				pEx->srcClrTranform == SEINFO_SRC_CLR_TRANSFORM_ENABLE_FOR_ALL) {
				return false;
			}
		}
	}else{
		SeCmdFormatConversion.Word5.fb_sel_destclr_blend = SEINFO_OPCODE_NOP;

	}

	SeCmdFormatConversion.Word6.Reserved = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.Word7.Reserved = SEINFO_OPCODE_NOP;
	SeCmdFormatConversion.Word8.Reserved = SEINFO_OPCODE_NOP;

	WriteCmd(se_devices, (UINT8 *)&SeCmdFormatConversion, sizeof(SECMD_FORMAT_CONVERSION));
	return true;
}


bool SE_WriteClut(
	UINT32* pale,
	UINT32  size,
	UINT32  startpale)
{
	int step = 0;
	int slot1 = 0;
	//SECMD_WRITE_CLUT* SeCmdCLUT;

	SECMD_WRITE_CLUT SeCmdCLUT[64];
	if(size == 0)
		return true;

	if(startpale + size > 256) {
		printk(KERN_ERR"%s pale out of size start=%d, size=%d\n",
			__func__, startpale, size);
		return false;
	}

	//SeCmdCLUT = kmalloc(sizeof(SECMD_WRITE_CLUT)*128, GFP_KERNEL);

	//if (SeCmdCLUT == NULL) {
	//	printk(KERN_ERR"%s kmalloc fail\n", __func__);
	//	return false;
	//}

	memset((void *)&SeCmdCLUT, 0, sizeof(SECMD_WRITE_CLUT)*64);

	for(step=0;step < 64; step++) {
		slot1 = (step*2);
		if(slot1 > size) {
			SeCmdCLUT[step].Word1.OpCode = SEINFO_OPCODE_NOP;
			SeCmdCLUT[step].Word2.RegisterValue = SEINFO_OPCODE_NOP;
		}else{
			SeCmdCLUT[step].Word1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdCLUT[step].Word1.Clut = SEINFO_REGMODE_CLUT;
			SeCmdCLUT[step].Word1.RegisterAddress = (slot1+startpale) & 0xff;
			SeCmdCLUT[step].Word2.RegisterValue = (unsigned int)*(pale+slot1);
		}
		slot1 +=1;
		if(slot1 > size) {
			SeCmdCLUT[step].Word3.OpCode = SEINFO_OPCODE_NOP;
			SeCmdCLUT[step].Word4.RegisterValue = SEINFO_OPCODE_NOP;
		}else{
			SeCmdCLUT[step].Word3.Reserved = 0;
			SeCmdCLUT[step].Word3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
			SeCmdCLUT[step].Word3.Clut = SEINFO_REGMODE_CLUT;
			SeCmdCLUT[step].Word3.RegisterAddress = (slot1+startpale) & 0xff;
			SeCmdCLUT[step].Word4.RegisterValue = (unsigned int)*(pale+slot1);
		}
	}

	WriteCmd(se_devices, (UINT8 *)SeCmdCLUT, sizeof(SECMD_WRITE_CLUT)*(64));
	//kfree(SeCmdCLUT);
	return true;
}

bool SE_WaitCmdDone(
	UINT32 uTimeoutCnt,
	UINT32 uMode
)
{

#if 0
	/*if sleep, we will be swaped out....
	  if delay, busy waiting,
	  provide ioctl for user space process,
	  let's them blocked by themselves*/
	UINT32 u32ExitCounter = 0;
	while(1) {
		if(se_checkfinish(false, 0)) break;
		udelay(100);
		if(u32ExitCounter >uTimeoutCnt) {
			se_checkfinish(true, 0);
			break;
		}
		u32ExitCounter++;
	}
#endif
	return true;
}


UINT32 get_SetColorFormat(
	SE_COLOR_FORMAT_EX_T* pExtraParam)
{
	SEREG_CLR_FMT SeRegColorFormat;

	memset((void *)&SeRegColorFormat, 0, sizeof(SEREG_CLR_FMT));

	if (pExtraParam) {
		SE_COLOR_FORMAT_EX_T* pClrFormatEx = (SE_COLOR_FORMAT_EX_T*) pExtraParam;
		SeRegColorFormat.Value = 0;
		SeRegColorFormat.Fields.Format = pClrFormatEx->byColorFormat;
		SeRegColorFormat.Fields.write_enable1 = true;

		if(pClrFormatEx->byArgbAlphaLocation != SEINFO_ARGB_ALPHA_NONE) {
			SeRegColorFormat.Fields.alpha_loc = pClrFormatEx->byArgbAlphaLocation;
			SeRegColorFormat.Fields.write_enable2 = true;
		}

		if(pClrFormatEx->byOutputArgbAlphaLocation != SEINFO_ARGB_ALPHA_NONE)
		{
			SeRegColorFormat.Fields.alpha_loc2 = pClrFormatEx->byOutputArgbAlphaLocation;
			SeRegColorFormat.Fields.write_enable5 = true;
		}

		SeRegColorFormat.Fields.big_endian_i1  = pClrFormatEx->bInputSrcColorFormatBigEndian;
		SeRegColorFormat.Fields.write_enable6  = true;
		SeRegColorFormat.Fields.big_endian_i2  = pClrFormatEx->bInputDestColorFormatBigEndian;
		SeRegColorFormat.Fields.write_enable7  = true;
		SeRegColorFormat.Fields.big_endian_o   = pClrFormatEx->bOutputColorFormatBigEndian;
		SeRegColorFormat.Fields.write_enable8  = true;
		SeRegColorFormat.Fields.rounding_en    = pClrFormatEx->bEnableRoundingOption;
		SeRegColorFormat.Fields.write_enable10 = true;
	}else{
		SeRegColorFormat.Fields.Format = SEINFO_COLOR_FORMAT_ARGB8888;
		SeRegColorFormat.Fields.write_enable1 = true;
		SeRegColorFormat.Value =  0x00754057;
	}

	return (UINT32)SeRegColorFormat.Value;
}

bool SE_EXT_FormatConversion_ROP(
	SE_PROCINFO_T		*pSeDestinationProcInfo,
	SE_PROCINFO_T		*pSeSourceProcInfo,
	void*			pExtraParam
)
{

	SE_EXT_FMT_CONV_T* pEx = (SE_EXT_FMT_CONV_T*)pExtraParam;
	SECMD_EXT_FMT_CONV_ROP se_ext_rop;
	memset((void *)&se_ext_rop, 0, sizeof(SECMD_EXT_FMT_CONV_ROP));

	if(pExtraParam == NULL) {
		printk(KERN_ERR"[%s] get null pointer!!\n",__func__);
		return false;
	}


	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	if(pEx->src1_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeSourceProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeSourceProcInfo->uPitch_c1 == 0x0)
			return false;
	}

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeDestinationProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeDestinationProcInfo->uPitch_c1 == 0x0)
			return false;
	}
	se_ext_rop.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_rop.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	se_ext_rop.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->st_blend_layer0.stcolorfmt);
#if 0
	se_ext_rop.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_rop.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SWAP_FBDC;
#else
	se_ext_rop.WordReg2.OpCode = SEINFO_OPCODE_NOP;
	se_ext_rop.WordReg2_1.RegisterValue = SEINFO_OPCODE_NOP;

#endif

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_rop.WordReg2_1.RegisterValue = 0xff;
	}else if(pEx->result_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_rop.WordReg2_1.RegisterValue = 0xf0;
	}else if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_rop.WordReg2_1.RegisterValue = 0x0f;
	}else{
		se_ext_rop.WordReg2_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	se_ext_rop.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_rop.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	se_ext_rop.WordReg3_1.RegisterValue = pEx->st_blend_layer0.constColorValue;

	se_ext_rop.WordReg4.OpCode = SEINFO_OPCODE_NOP;
	se_ext_rop.WordReg4_1.RegisterValue = SEINFO_OPCODE_NOP;

	se_ext_rop.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_rop.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_rop.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_rop.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	se_ext_rop.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;

#if SE_SE20_EXT
	se_ext_rop.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_rop.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_rop.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	se_ext_rop.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_rop.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_rop.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_rop.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	se_ext_rop.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_rop.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_rop.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_rop.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_rop.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;

	if((UINT32) pSeSourceProcInfo->uAddr_c1 != 0x0) {
		se_ext_rop.WordAddr2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_rop.WordAddr2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_rop.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_rop.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif

		se_ext_rop.WordAddr2_1.RegisterValue = pSeSourceProcInfo->uAddr_c1;
	}else{
		se_ext_rop.WordAddr2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_rop.WordAddr2_1.RegisterValue = SEINFO_OPCODE_NOP;

	}
	if((UINT32) pSeSourceProcInfo->uPitch_c1 !=0x0) {
		se_ext_rop.WordPitch2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_rop.WordPitch2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_rop.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_rop.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_rop.WordPitch2_1.RegisterValue = pSeSourceProcInfo->uPitch_c1;
	}else{
		se_ext_rop.WordPitch2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_rop.WordPitch2_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uAddr_c1 !=0x0) {
		se_ext_rop.WordAddr3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_rop.WordAddr3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_rop.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_rop.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_rop.WordAddr3_1.RegisterValue = pSeDestinationProcInfo->uAddr_c1;
	}else{
		se_ext_rop.WordAddr3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_rop.WordAddr3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uPitch_c1 !=0x0) {
		se_ext_rop.WordPitch3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_rop.WordPitch3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_rop.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_rop.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_rop.WordPitch3_1.RegisterValue = pSeDestinationProcInfo->uPitch_c1;
	}else{
		se_ext_rop.WordPitch3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_rop.WordPitch3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

//-------------------------------------------------------------
	se_ext_rop.Word1.opcode = SEINFO_OPCODE_EXT_FMT;
	se_ext_rop.Word1.rslt_fmt = pEx->result_format;
	se_ext_rop.Word1.lay_ctl = 1;
	se_ext_rop.Word1.lay_num = 1;

	se_ext_rop.Word1.rslt_argb_order = ARGBENDIAN;
	se_ext_rop.Word1.src2_argb_order = ARGBENDIAN;
	se_ext_rop.Word2.rslt_out_x = pSeDestinationProcInfo->wDataX;
	se_ext_rop.Word2.rslt_out_y = pSeDestinationProcInfo->wDataY;

	se_ext_rop.Word3.rslt_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_rop.Word3.rslt_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;

	se_ext_rop.Word4.src1_inpt_w = pSeDestinationProcInfo->wDataWidth;
	se_ext_rop.Word4.src1_inpt_h = pSeDestinationProcInfo->wDataHeight;
	se_ext_rop.Word4.src1_fmt = pEx->result_format;

	se_ext_rop.Word5.src1_inpt_x = pSeDestinationProcInfo->wDataX;
	se_ext_rop.Word5.src1_inpt_y = pSeDestinationProcInfo->wDataY;

	se_ext_rop.Word5.src1_argb_order = ARGBENDIAN;
	if(pEx->src2_select == SEINFO_BITBLT_EXT_SELECT_CONST) {
		se_ext_rop.Word5.src1_argb_order = CONSTENDIAN; //FPGA-->BGRA
		se_ext_rop.Word1.src2_argb_order = CONSTENDIAN;
	}
	se_ext_rop.Word6.src1_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_rop.Word6.src1_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;
	se_ext_rop.Word6.src1_inpt_sel = pEx->src1_select;

	se_ext_rop.Word7.src2_inpt_x = pSeSourceProcInfo->wDataX;
	se_ext_rop.Word7.src2_inpt_y = pSeSourceProcInfo->wDataY;
	se_ext_rop.Word7.src2_fmt = pEx->src2_format;

	se_ext_rop.Word8.src2_inpt_sel = pEx->src1_select;
	se_ext_rop.Word8.src2_addr_index = (UINT32)pSeSourceProcInfo->byBaseAddressIndex;
	se_ext_rop.Word8.src2_chr1_addr_index = (UINT32)pSeSourceProcInfo->byChronmaAddressIndex;

	se_ext_rop.Word9.lay_num_ext = 1;
	se_ext_rop.Word10.blend_sel_1 = 0x0;
	se_ext_rop.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;

	se_ext_rop.Word12.Reserved = SEINFO_OPCODE_NOP;
	se_ext_rop.Word13.Reserved = SEINFO_OPCODE_NOP;
	se_ext_rop.Word14.Reserved = SEINFO_OPCODE_NOP;
	se_ext_rop.Word15.Reserved = SEINFO_OPCODE_NOP;
	se_ext_rop.Word16.Reserved = SEINFO_OPCODE_NOP;

	WriteCmd(se_devices, (UINT8 *)&se_ext_rop, sizeof(SECMD_EXT_FMT_CONV_ROP));
	return true;
}

bool atomic_SE_EXT_FormatConversion(
	SE_PROCINFO_T		*pSeDestinationProcInfo,
	SE_PROCINFO_T		*pSeSourceProcInfo,
	void*			pExtraParam
)
{
	SE_EXT_FMT_CONV_T* pEx = (SE_EXT_FMT_CONV_T*)pExtraParam;
	SECMD_EXT_FMT_CONV se_ext_conv;
	memset((void *)&se_ext_conv, 0, sizeof(SECMD_EXT_FMT_CONV));

//-------------------------------------------------------------
	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	if(pEx->src1_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeSourceProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeSourceProcInfo->uPitch_c1 == 0x0)
			return false;
	}

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeDestinationProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeDestinationProcInfo->uPitch_c1 == 0x0)
			return false;
	}
#if 1
	se_ext_conv.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_conv.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	se_ext_conv.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->st_blend_layer0.stcolorfmt);
#else
	se_ext_conv.WordReg1.Reserved = 0;
	se_ext_conv.WordReg1.OpCode = SEINFO_OPCODE_NOP;
	se_ext_conv.WordReg1_1.RegisterValue = SEINFO_OPCODE_NOP;

#endif
	se_ext_conv.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_conv.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	se_ext_conv.WordReg2_1.RegisterValue = pEx->st_blend_layer0.constColorValue;
#if 0
	se_ext_conv.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_conv.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SWAP_FBDC;
#else
	se_ext_conv.WordReg3.OpCode = SEINFO_OPCODE_NOP;
	se_ext_conv.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
#endif

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_conv.WordReg3_1.RegisterValue = 0xff;
	}else if(pEx->result_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_conv.WordReg3_1.RegisterValue = 0xf0;
	}else if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_conv.WordReg3_1.RegisterValue = 0x0f;
	}else{
		se_ext_conv.WordReg3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	se_ext_conv.WordReg4.OpCode = SEINFO_OPCODE_NOP;
	se_ext_conv.WordReg4_1.RegisterValue = SEINFO_OPCODE_NOP;


	se_ext_conv.WordAddr0.Reserved = 0;
	se_ext_conv.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	se_ext_conv.WordPitch0.Reserved = 0;
	se_ext_conv.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	se_ext_conv.WordAddr1.Reserved = 0;
	se_ext_conv.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	se_ext_conv.WordPitch1.Reserved = 0;
	se_ext_conv.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;


	if((UINT32) pSeSourceProcInfo->uAddr_c1 != 0x0) {
		se_ext_conv.WordAddr2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordAddr2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordAddr2_1.RegisterValue = pSeSourceProcInfo->uAddr_c1;
	}else{
		se_ext_conv.WordAddr2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordAddr2_1.RegisterValue = SEINFO_OPCODE_NOP;

	}
	if((UINT32) pSeSourceProcInfo->uPitch_c1 !=0x0) {
		se_ext_conv.WordPitch2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordPitch2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordPitch2_1.RegisterValue = pSeSourceProcInfo->uPitch_c1;
	}else{
		se_ext_conv.WordPitch2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordPitch2_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uAddr_c1 !=0x0) {
		se_ext_conv.WordAddr3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordAddr3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordAddr3_1.RegisterValue = pSeDestinationProcInfo->uAddr_c1;
	}else{
		se_ext_conv.WordAddr3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordAddr3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uPitch_c1 !=0x0) {
		se_ext_conv.WordPitch3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordPitch3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordPitch3_1.RegisterValue = pSeDestinationProcInfo->uPitch_c1;
	}else{
		se_ext_conv.WordPitch3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordPitch3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

//-------------------------------------------------------------

	se_ext_conv.Word1.opcode = SEINFO_OPCODE_EXT_FMT;
	se_ext_conv.Word1.rslt_fmt = pEx->result_format;
	se_ext_conv.Word1.lay_ctl = 0;
	se_ext_conv.Word1.lay_num = 0;
	se_ext_conv.Word1.rslt_argb_order = ARGBENDIAN;

	se_ext_conv.Word2.rslt_rotate = pEx->st_blend_layer0.rot;
	se_ext_conv.Word2.rslt_mirror = pEx->st_blend_layer0.mir;

	se_ext_conv.Word2.rslt_out_x = pSeDestinationProcInfo->wDataX;
	se_ext_conv.Word2.rslt_out_y = pSeDestinationProcInfo->wDataY;

	se_ext_conv.Word3.rslt_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_conv.Word3.rslt_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;

	se_ext_conv.Word4.src1_inpt_w = pSeSourceProcInfo->wDataWidth;
	se_ext_conv.Word4.src1_inpt_h = pSeSourceProcInfo->wDataHeight;
	se_ext_conv.Word4.src1_fmt = pEx->src1_format;

	se_ext_conv.Word5.src1_inpt_x = pSeSourceProcInfo->wDataX;
	se_ext_conv.Word5.src1_inpt_y = pSeSourceProcInfo->wDataY;

	se_ext_conv.Word5.src1_argb_order = ARGBENDIAN;
	if(pEx->src1_select == SEINFO_BITBLT_EXT_SELECT_CONST) {
		se_ext_conv.Word5.src1_argb_order = CONSTENDIAN;//FPGA
		se_ext_conv.Word1.src2_argb_order = CONSTENDIAN;
	}

	se_ext_conv.Word6.src1_addr_index = (UINT32)pSeSourceProcInfo->byBaseAddressIndex;
	se_ext_conv.Word6.src1_chr1_addr_index = (UINT32)pSeSourceProcInfo->byChronmaAddressIndex;
	se_ext_conv.Word6.src1_inpt_sel = pEx->src1_select;

	se_ext_conv.Word7.Reserved = SEINFO_OPCODE_NOP;
	se_ext_conv.Word8.Reserved = SEINFO_OPCODE_NOP;

	WriteCmd(se_devices, (UINT8 *)&se_ext_conv, sizeof(SECMD_EXT_FMT_CONV));


	return true;
}

bool SE_EXT_FormatConversion(
	SE_PROCINFO_T		*pSeDestinationProcInfo,
	SE_PROCINFO_T		*pSeSourceProcInfo,
	void*			pExtraParam
)
{
	SE_EXT_FMT_CONV_T* pEx = (SE_EXT_FMT_CONV_T*)pExtraParam;
	SECMD_EXT_FMT_CONV_BLIT se_ext_conv;
	memset((void *)&se_ext_conv, 0, sizeof(SECMD_EXT_FMT_CONV_BLIT));

	if(pExtraParam == NULL) {
		printk(KERN_ERR"[%s] get null pointer!!\n",__func__);
		return false;
	}



	if((pEx->st_blend_layer0.bEnableWithBitblit == false && pEx->src1_select == SEINFO_BITBLT_EXT_SELECT_CONST) ||
		pEx->st_blend_layer0.bEnableWithBitblit == false) {
		return atomic_SE_EXT_FormatConversion(pSeDestinationProcInfo, pSeSourceProcInfo, pExtraParam);
	}

	if(pEx->st_blend_layer0.ropMode == SEINFO_ROP_MODE) {
		return SE_EXT_FormatConversion_ROP(pSeDestinationProcInfo, pSeSourceProcInfo, pExtraParam);
	}
//-------------------------------------------------------------
	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	if(pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeSourceProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeSourceProcInfo->uPitch_c1 == 0x0)
			return false;
	}

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		if((UINT32) pSeDestinationProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeDestinationProcInfo->uPitch_c1 == 0x0)
			return false;
	}

	if(pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_NV12_420) {
		if((UINT32) pSeSourceProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeSourceProcInfo->uPitch_c1 == 0x0)
			return false;
	}

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_NV12_420) {
		if((UINT32) pSeDestinationProcInfo->uAddr_c1 == 0x0)
			return false;
		if((UINT32) pSeDestinationProcInfo->uPitch_c1 == 0x0)
			return false;
	}


	se_ext_conv.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_conv.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	se_ext_conv.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->st_blend_layer0.stcolorfmt);
#if 0
	se_ext_conv.WordReg2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordReg2.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_conv.WordReg2.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SWAP_FBDC;
#else
	se_ext_conv.WordReg2.OpCode = SEINFO_OPCODE_NOP;
	se_ext_conv.WordReg2_1.RegisterValue = SEINFO_OPCODE_NOP;
#endif

	if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_conv.WordReg2_1.RegisterValue = 0xff;
	}else if(pEx->result_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_conv.WordReg2_1.RegisterValue = 0xf0;
	}else if(pEx->result_format == SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8
		&& pEx->src2_format != SEINFO_EXT_COLOR_FORMAT_FBDC_U8U8U8U8) {
		se_ext_conv.WordReg2_1.RegisterValue = 0x0f;
	}else{
		se_ext_conv.WordReg2_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	//if (pEx->st_blend_layer0.bEnableDfbColorize){
	se_ext_conv.WordReg3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordReg3.Clut = SEINFO_REGMODE_REGISTER;
	se_ext_conv.WordReg3.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_COLOR;
	se_ext_conv.WordReg3_1.RegisterValue = pEx->st_blend_layer0.constColorValue;

	if(pEx->st_blend_layer0.bEnableDfbReplaceSrcAlphaWithConstAlpha){
		se_ext_conv.WordReg4.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg4.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg4.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DFB_COLORALPHA;
		se_ext_conv.WordReg4_1.RegisterValue = pEx->st_blend_layer0.constAlphaValueForBlendColorAlpha;
	}else{
		se_ext_conv.WordReg4.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg4_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pEx->st_blend_layer0.bEnableDfbModulateSrcAlphaWithConstAlpha){
		se_ext_conv.WordReg5.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg5.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg5.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
		se_ext_conv.WordReg5_1.RegisterValue =pEx->st_blend_layer0.constAplhaValue;
	}else{
		se_ext_conv.WordReg5.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg5_1.RegisterValue = SEINFO_OPCODE_NOP;
	}


	if(pEx->st_blend_layer0.outputAlphaModeSelect == SEINFO_OUTPUT_ALPHA_CONST){
		se_ext_conv.WordReg6.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg6.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg6.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_RESULT_ALPHA;
		se_ext_conv.WordReg6_1.RegisterValue = pEx->st_blend_layer0.destAplhaValue;
	}else{
		se_ext_conv.WordReg6.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg6_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_SOURCE ||
		pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_BOTH){
		se_ext_conv.WordReg7.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg7.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg7.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_KEY;
		se_ext_conv.WordReg7_1.RegisterValue =pEx->st_blend_layer0.constSrcColorKeyValue;
	}else{
		se_ext_conv.WordReg7.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg7_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

	if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_DESTINATION
		|| pEx->st_blend_layer0.colorKeySelect ==SEINFO_COLORKEY_BOTH){
		se_ext_conv.WordReg8.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg8.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg8.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_COLOR_KEY;
		se_ext_conv.WordReg8_1.RegisterValue =pEx->st_blend_layer0.constDstColorKeyValue;
	}else{
		se_ext_conv.WordReg8.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg8_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pEx->st_blend_layer0.srcAlphaModeSelect ==SEINFO_BITBLT_ALPHA_CONST){
		se_ext_conv.WordReg9.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg9.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg9.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_SRC_ALPHA;
		se_ext_conv.WordReg9_1.RegisterValue = pEx->st_blend_layer0.srcAplhaValue;
	}else{
		se_ext_conv.WordReg9.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg9_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if(pEx->st_blend_layer0.destAlphaModeSelect ==SEINFO_BITBLT_ALPHA_CONST){
		se_ext_conv.WordReg10.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordReg10.Clut = SEINFO_REGMODE_REGISTER;
		se_ext_conv.WordReg10.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_DEST_ALPHA;
		se_ext_conv.WordReg10_1.RegisterValue = pEx->st_blend_layer0.destAplhaValue;
	}else{
		se_ext_conv.WordReg10.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordReg10_1.RegisterValue = SEINFO_OPCODE_NOP;
	}


	se_ext_conv.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	se_ext_conv.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;

#if SE_SE20_EXT
	se_ext_conv.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	se_ext_conv.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	se_ext_conv.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_ext_conv.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
	se_ext_conv.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byBaseAddressIndex << 4));
#else
	se_ext_conv.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
#endif
	se_ext_conv.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;

	if((UINT32) pSeSourceProcInfo->uAddr_c1 != 0x0) {
		se_ext_conv.WordAddr2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordAddr2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordAddr2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordAddr2_1.RegisterValue = pSeSourceProcInfo->uAddr_c1;
	}else{
		se_ext_conv.WordAddr2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordAddr2_1.RegisterValue = SEINFO_OPCODE_NOP;

	}
	if((UINT32) pSeSourceProcInfo->uPitch_c1 !=0x0) {
		se_ext_conv.WordPitch2.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordPitch2.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeSourceProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordPitch2.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordPitch2_1.RegisterValue = pSeSourceProcInfo->uPitch_c1;
	}else{
		se_ext_conv.WordPitch2.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordPitch2_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uAddr_c1 !=0x0) {
		se_ext_conv.WordAddr3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordAddr3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_BASE_ADDR0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordAddr3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordAddr3_1.RegisterValue = pSeDestinationProcInfo->uAddr_c1;
	}else{
		se_ext_conv.WordAddr3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordAddr3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}
	if((UINT32) pSeDestinationProcInfo->uPitch_c1 !=0x0) {
		se_ext_conv.WordPitch3.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
		se_ext_conv.WordPitch3.Clut = SEINFO_REGMODE_REGISTER;
#if SE_SE20_EXT
		se_ext_conv.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SE20INFO_REG_PITCH0 + (pSeDestinationProcInfo->byChronmaAddressIndex << 4));
#else
		se_ext_conv.WordPitch3.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byChronmaAddressIndex << 2));
#endif
		se_ext_conv.WordPitch3_1.RegisterValue = pSeDestinationProcInfo->uPitch_c1;
	}else{
		se_ext_conv.WordPitch3.OpCode = SEINFO_OPCODE_NOP;
		se_ext_conv.WordPitch3_1.RegisterValue = SEINFO_OPCODE_NOP;
	}

//-------------------------------------------------------------
	se_ext_conv.Word1.opcode = SEINFO_OPCODE_EXT_FMT;
	se_ext_conv.Word1.rslt_fmt = pEx->result_format;
	if(pEx->st_blend_layer0.outputAlphaModeSelect == SEINFO_OUTPUT_ALPHA_CONST) {
		se_ext_conv.Word1.out_alpha = 1;
	}

	se_ext_conv.Word1.lay_ctl = 1;
	se_ext_conv.Word1.lay_num = pEx->st_blend_layer0.bEnableWithBitblit?1:0;
	se_ext_conv.Word2.rslt_out_x = pSeDestinationProcInfo->wDataX;
	se_ext_conv.Word2.rslt_out_y = pSeDestinationProcInfo->wDataY;

	se_ext_conv.Word1.src2_argb_order = ARGBENDIAN;
	se_ext_conv.Word1.rslt_argb_order = ARGBENDIAN;


	se_ext_conv.Word3.rslt_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_conv.Word3.rslt_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;


	se_ext_conv.Word4.src1_inpt_w = pSeDestinationProcInfo->wDataWidth;
	se_ext_conv.Word4.src1_inpt_h = pSeDestinationProcInfo->wDataHeight;

	se_ext_conv.Word4.src1_fmt = pEx->src1_format;

	se_ext_conv.Word5.src1_inpt_x = pSeDestinationProcInfo->wDataX;
	se_ext_conv.Word5.src1_inpt_y = pSeDestinationProcInfo->wDataY;

	se_ext_conv.Word5.src1_argb_order = ARGBENDIAN;
	if(pEx->src2_select == SEINFO_BITBLT_EXT_SELECT_CONST) {
		//se_ext_conv.Word1.src2_argb_order = 0x1b;

		//se_ext_conv.Word1.rslt_argb_order = ARGBENDIAN;
		//se_ext_conv.Word5.src1_argb_order = CONSTENDIAN;
		se_ext_conv.Word1.src2_argb_order = CONSTENDIAN;
	}

	se_ext_conv.Word6.src1_addr_index = (UINT32)pSeDestinationProcInfo->byBaseAddressIndex;
	se_ext_conv.Word6.src1_chr1_addr_index = (UINT32)pSeDestinationProcInfo->byChronmaAddressIndex;

	//se_ext_conv.Word6.src1_addr_index = (UINT32)pSeSourceProcInfo->byBaseAddressIndex;
	//se_ext_conv.Word6.src1_chr1_addr_index = (UINT32)pSeSourceProcInfo->byChronmaAddressIndex;

	if(pEx->src2_select == SEINFO_BITBLT_EXT_SELECT_CONST) {
		se_ext_conv.Word6.src1_inpt_sel = 0;
	}else{
		se_ext_conv.Word6.src1_inpt_sel = pEx->src1_select;
	}


	se_ext_conv.Word7.src2_inpt_x = pSeSourceProcInfo->wDataX;
	se_ext_conv.Word7.src2_inpt_y = pSeSourceProcInfo->wDataY;
	se_ext_conv.Word7.src2_fmt = pEx->src2_format;

	se_ext_conv.Word8.src2_inpt_sel = pEx->src2_select;
	se_ext_conv.Word8.src2_addr_index = (UINT32)pSeSourceProcInfo->byBaseAddressIndex;
	se_ext_conv.Word8.src2_chr1_addr_index = (UINT32)pSeSourceProcInfo->byChronmaAddressIndex;

	se_ext_conv.Word9.sel_s2_alpha = pEx->st_blend_layer0.srcAlphaModeSelect;
	se_ext_conv.Word9.sel_s1_alpha = pEx->st_blend_layer0.destAlphaModeSelect;
	se_ext_conv.Word9.lay_num_ext = 1;

	se_ext_conv.Word10.fb_sel_destclr_blend_1 = pEx->st_blend_layer0.selDestClrBlend;
	se_ext_conv.Word10.fb_sel_srcclr_blend_1 = pEx->st_blend_layer0.selSrcClrBlend;
	se_ext_conv.Word10.fb_demultiply_1 = pEx->st_blend_layer0.bEnableDfbDemultiply;


	//set alpha
	se_ext_conv.Word10.fb_blend_alphachannel_1 = pEx->st_blend_layer0.bEnableDfbModulateSrcAlphaWithConstAlpha;
	//set fb coloralpha
	se_ext_conv.Word10.fb_blend_coloralpha_1 = pEx->st_blend_layer0.bEnableDfbReplaceSrcAlphaWithConstAlpha;
	se_ext_conv.Word10.fb_colorize_1 = pEx->st_blend_layer0.bEnableDfbColorize;
	se_ext_conv.Word10.fb_xor_1 = pEx->st_blend_layer0.bEnableDfbXor;
	se_ext_conv.Word10.fb_src_premultiply_1 = pEx->st_blend_layer0.bEnableDfbSrcPremultiply;
	se_ext_conv.Word10.fb_src_premulcolor_1 = pEx->st_blend_layer0.bEnableDfbSrcPremulcolor;
	se_ext_conv.Word10.fb_dst_premultiply_1 = pEx->st_blend_layer0.bEnableDfbDstPremultiply;
	if(pEx->st_blend_layer0.ropMode == SEINFO_ALPHA_BLENDING) {
		se_ext_conv.Word10.blend_sel_1 = 0x2;
	} else {
		se_ext_conv.Word10.blend_sel_1 = 0x0;
		se_ext_conv.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;
	}

	se_ext_conv.Word10.color_key_1 = pEx->st_blend_layer0.colorKeySelect;

	if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_SOURCE)
		se_ext_conv.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;
	else if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_DESTINATION)
		se_ext_conv.Word10.rop_code_1 = SEINFO_ROPCODE_COPY;
	else if(pEx->st_blend_layer0.colorKeySelect == SEINFO_COLORKEY_BOTH )
		se_ext_conv.Word10.rop_code_1 = SEINFO_ROPCODE_BLACK;


	se_ext_conv.Word10.fb_sel_srcclr_blend_1 = pEx->st_blend_layer0.selSrcClrBlend;
	se_ext_conv.Word10.fb_sel_destclr_blend_1 = pEx->st_blend_layer0.selDestClrBlend;


	se_ext_conv.Word12.Reserved = SEINFO_OPCODE_NOP;
	se_ext_conv.Word13.Reserved = SEINFO_OPCODE_NOP;
	se_ext_conv.Word14.Reserved = SEINFO_OPCODE_NOP;
	se_ext_conv.Word15.Reserved = SEINFO_OPCODE_NOP;
	se_ext_conv.Word16.Reserved = SEINFO_OPCODE_NOP;
	WriteCmd(se_devices, (UINT8 *)&se_ext_conv, sizeof(SECMD_EXT_FMT_CONV_BLIT));

	return true;
}

bool SE_Rotate(
	SE_PROCINFO_T	*pSeDestinationProcInfo,
	SE_PROCINFO_T	*pSeSourceProcInfo,
	SEINFO_ROTATE	byRotateMode,
	void*		pExtraParam
)
{
	SECMD_ROTATE se_rota;
	SE_EXT_FMT_CONV_T* pEx = (SE_EXT_FMT_CONV_T*)pExtraParam;
	memset((void *)&se_rota , 0, sizeof(SECMD_ROTATE));

	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	se_rota.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_rota.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	se_rota.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	se_rota.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->st_blend_layer0.stcolorfmt);

	//se_rota.WordReg2.Reserved = 0;
	//se_rota.WordReg2.OpCode = SEINFO_OPCODE_NOP;
	//se_rota.WordReg2_1.RegisterValue = SEINFO_OPCODE_NOP;


	se_rota.WordAddr0.Reserved = 0;
	se_rota.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_rota.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
	se_rota.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	se_rota.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	se_rota.WordPitch0.Reserved = 0;
	se_rota.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_rota.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;
	se_rota.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	se_rota.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	se_rota.WordAddr1.Reserved = 0;
	se_rota.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_rota.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
	se_rota.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	se_rota.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	se_rota.WordPitch1.Reserved = 0;
	se_rota.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	se_rota.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
	se_rota.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	se_rota.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;

	se_rota.Word1.RotateMode = byRotateMode;
	se_rota.Word1.OpCode = SEINFO_OPCODE_ROTATE;

	se_rota.Word2.SrcAddressIndex = pSeSourceProcInfo->byBaseAddressIndex;
	se_rota.Word2.InputY = pSeSourceProcInfo->wDataY;
	se_rota.Word2.InputX = pSeSourceProcInfo->wDataX;

	se_rota.Word3.DestAddressIndex = pSeDestinationProcInfo->byBaseAddressIndex;
	se_rota.Word3.OutputY = pSeDestinationProcInfo->wDataY;
	se_rota.Word3.OutputX = pSeDestinationProcInfo->wDataX;

	se_rota.Word4.InputHeight = pSeSourceProcInfo->wDataHeight;
	se_rota.Word4.InputWidth = pSeSourceProcInfo->wDataWidth;

	se_rota.Word5.Reserved = SEINFO_OPCODE_NOP;
	se_rota.Word6.Reserved = SEINFO_OPCODE_NOP;


	WriteCmd(se_devices, (UINT8 *)&se_rota, sizeof(SECMD_ROTATE));
	return true;
}

bool SE_Mirror(
	SE_PROCINFO_T*		pSeDestinationProcInfo,
	SE_PROCINFO_T*		pSeSourceProcInfo,
	SEINFO_MIRRORMODE	byMirrorDirection,
	void*				pExtraParam
)
{
	SECMD_MIRROR SeCmdMirror;
	SE_EXT_FMT_CONV_T* pEx = (SE_EXT_FMT_CONV_T*)pExtraParam;
	memset((void *)&SeCmdMirror, 0, sizeof(SECMD_MIRROR));

	if((UINT32) pSeSourceProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeSourceProcInfo->uPitch ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uAddr ==0x0)
		return false;
	if((UINT32) pSeDestinationProcInfo->uPitch ==0x0)
		return false;

	SeCmdMirror.WordReg1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdMirror.WordReg1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdMirror.WordReg1.RegisterAddress = (SEINFO_WRITEREG)SEINFO_REG_COLOR_FORMAT;
	SeCmdMirror.WordReg1_1.RegisterValue = get_SetColorFormat(&pEx->st_blend_layer0.stcolorfmt);

	SeCmdMirror.WordAddr0.Reserved = 0;
	SeCmdMirror.WordAddr0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdMirror.WordAddr0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdMirror.WordAddr0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdMirror.WordAddr0_1.RegisterValue = pSeSourceProcInfo->uAddr;

	SeCmdMirror.WordPitch0.Reserved = 0;
	SeCmdMirror.WordPitch0.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdMirror.WordPitch0.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdMirror.WordPitch0.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeSourceProcInfo->byBaseAddressIndex << 2));
	SeCmdMirror.WordPitch0_1.RegisterValue = pSeSourceProcInfo->uPitch;

	SeCmdMirror.WordAddr1.Reserved = 0;
	SeCmdMirror.WordAddr1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdMirror.WordAddr1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdMirror.WordAddr1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_BASE_ADDR1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdMirror.WordAddr1_1.RegisterValue = pSeDestinationProcInfo->uAddr;

	SeCmdMirror.WordPitch1.Reserved = 0;
	SeCmdMirror.WordPitch1.OpCode = SEINFO_OPCODE_WRITE_REGISTER;
	SeCmdMirror.WordPitch1.Clut = SEINFO_REGMODE_REGISTER;
	SeCmdMirror.WordPitch1.RegisterAddress =(SEINFO_WRITEREG) (SEINFO_REG_PITCH1 + (pSeDestinationProcInfo->byBaseAddressIndex << 2));
	SeCmdMirror.WordPitch1_1.RegisterValue = pSeDestinationProcInfo->uPitch;

	SeCmdMirror.Word1.DestAddressIndex = (UINT32) pSeDestinationProcInfo->byBaseAddressIndex;
	SeCmdMirror.Word1.MirrorDirection = byMirrorDirection;
	SeCmdMirror.Word1.OutputX = pSeDestinationProcInfo->wDataX;
	SeCmdMirror.Word1.OutputY = pSeDestinationProcInfo->wDataY;
	SeCmdMirror.Word1.OpCode = SEINFO_OPCODE_MIRROR;

	SeCmdMirror.Word2.Height = pSeDestinationProcInfo->wDataHeight;
	SeCmdMirror.Word2.Width = pSeDestinationProcInfo->wDataWidth;

	SeCmdMirror.Word3.SrcAddressIndex = (UINT32) pSeSourceProcInfo->byBaseAddressIndex;
	SeCmdMirror.Word3.InputY = pSeSourceProcInfo->wDataY;
	SeCmdMirror.Word3.InputX = pSeSourceProcInfo->wDataX;

	SeCmdMirror.Word4.Reserved = SEINFO_OPCODE_NOP;
	SeCmdMirror.Word5.Reserved = SEINFO_OPCODE_NOP;
	SeCmdMirror.Word6.Reserved = SEINFO_OPCODE_NOP;

	WriteCmd(se_devices, (UINT8 *) &SeCmdMirror, sizeof(SECMD_MIRROR));
	return true;
}
