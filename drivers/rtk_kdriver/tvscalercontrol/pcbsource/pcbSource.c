#include <tvscalercontrol/scaler/source.h>
#include <tvscalercontrol/pcbsource/pcbSource.h>
#include <rtk_kdriver/pcbMgr.h>



#define AV1				1
#define AV2				2
#define AV3				3

#define SV1				1
#define SV2				2


#define SCART1			1
#define SCART2			2

#define VGA1				1
#define VGA2				2

#define YPP1				1
#define YPP2				2



#define AV_VIDEO_IN		0
#define AV_GROUND_IN		1


#define SV_Y_VIDEO_IN			0
#define SV_Y_GROUND_IN		1
#define SV_C_VIDEO_IN			2
#define SV_C_GROUND_IN		3
#define SV_TYPE				4

#define SCART_Y_VIDEO_IN		0
#define SCART_R_VIDEO_IN		1
#define SCART_G_VIDEO_IN		2
#define SCART_B_VIDEO_IN		3
#define SCART_GROUND_IN		4




int GetAVPath(unsigned char a_ucPort, unsigned char *a_pucVideoIn, unsigned char *a_pucGroundIn);
int GetScartPath(unsigned char a_ucPort, unsigned char *a_pucYIn, unsigned char *a_pucRIn, unsigned char *a_pucGIn, unsigned char *a_pucBIn, unsigned char *a_pucGroundIn);
int GetSVPath(unsigned char a_ucPort, unsigned char *a_pucYIn, unsigned char *a_pucYGround, unsigned char *a_pucCIn, unsigned char *a_pucCGround, unsigned char *a_pucType);
int GetVGAPath(unsigned char a_ucPort, unsigned char *a_pucData, unsigned char *a_pucSOY, unsigned char *a_pucSWAP);

int GetYPPPath(unsigned char a_ucPort, unsigned char *a_pucData, unsigned char *a_pucSOY, unsigned char *a_pucSWAP);

void InitPinDefineFromBookCode(void);

/*#define LGE_PCB */

/*================================== Variables ==============================*/
VGA_ADC_DATA_PATH 			tVGAPath = {ADC_DATA_INPUT0, ADC_SOY_MUX_VIN1P, ADC_SWAP_RGB}; /* VGA */
ADC_INITIAL_OPTIONS 		VGA_DataInput_Mux = {&tVGAPath};

YPBPR_ADC_DATA_PATH 		tYPbPrPath1 = {ADC_DATA_INPUT1, ADC_SOY_MUX_VIN4P, ADC_SWAP_RGB};
ADC_INITIAL_OPTIONS 		YPP1_DataInput_Mux = {&tYPbPrPath1};

#if 0
#ifdef YPBPR2_SOURCE_USING_VGA_PATH
YPBPR_ADC_DATA_PATH 		tYPbPrPath2 = {ADC_DATA_INPUT0, ADC_SOY_MUX_VIN1P, ADC_SWAP_RGB};
ADC_INITIAL_OPTIONS 		YPP2_DataInput_Mux = {&tYPbPrPath2};
#else
YPBPR_ADC_DATA_PATH 		tYPbPrPath2 = {ADC_DATA_INPUT2, ADC_SOY_MUX_VIN8PP, ADC_SWAP_BRG};
ADC_INITIAL_OPTIONS 		YPP2_DataInput_Mux = {&tYPbPrPath2};
#endif
#endif

/* AV/SV */
#define AV1_AUTOSWITCH_DB 							10



AV_VDC_PATH 				tAv1Path = {VIDEO_INPUT13, VIDEO_GNDA0};
AV_VDC_PATH 				tAv2Path = {VIDEO_INPUT10, VIDEO_GNDA0};
AV_VDC_PATH 				tAv3Path = {VIDEO_INPUT4, VIDEO_Y0N};
AV_VDC_PATH 				tAv4Path = {VIDEO_INPUT13, VIDEO_GNDA0};

SV_VDC_PATH				tSv1Path = {VIDEO_INPUT9, VIDEO_GNDA0, VIDEO_INPUT11, VIDEO_GNDA0, VIDEO_SV_SWAP};
SV_VDC_PATH 				tSv2Path = {VIDEO_INPUT5, VIDEO_GNDA1, VIDEO_INPUT4, VIDEO_GNDA1, VIDEO_SV_NORMAL};


SCART_VDC_PATH 			tScart1Path = {VIDEO_INPUT13, VIDEO_INPUT2, VIDEO_INPUT1, VIDEO_INPUT0, VIDEO_GNDA0};
AV_VDC_PATH 				tScart2Path = {VIDEO_INPUT13, VIDEO_GNDA0};



VDC_INITIAL_OPTIONS 		VDC_AV1_Options = {&tAv1Path};
VDC_INITIAL_OPTIONS 		VDC_AV2_Options = {&tAv2Path};
VDC_INITIAL_OPTIONS 		VDC_AV3_Options = {&tAv3Path};
VDC_INITIAL_OPTIONS 		VDC_AV4_Options = {&tAv4Path};
VDC_INITIAL_OPTIONS 		VDC_SV1_Options = {&tSv1Path};
VDC_INITIAL_OPTIONS 		VDC_SV2_Options = {&tSv2Path};

VDC_INITIAL_OPTIONS 		VDC_Scart1_Options = {&tScart1Path};
VDC_INITIAL_OPTIONS 		VDC_Scart2_Options = {&tScart2Path};

/* TV */
TV_VDC_PATH 				tTvPath = {TV_INPUT};
VDC_INITIAL_OPTIONS 		VDC_TUNER_Options = {&tTvPath};

StructSourceInput g_pcbSourceTable[] = {
	{ TVD_INFMT_CVBS0_TUNER, SET_SOURCE(_SRC_FROM_VDC, _SRC_TV),	_TV_INPUT1,		0,  _SRC_OBJ_TV,    (void *)&VDC_TUNER_Options,	AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_CVBS1, SET_SOURCE(_SRC_FROM_VDC, _SRC_CVBS),	_AV_INPUT1,		0,  _SRC_OBJ_AV_SV, (void *)&VDC_AV1_Options,	AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_CVBS2, SET_SOURCE(_SRC_FROM_VDC, _SRC_CVBS),	_AV_INPUT2,		0,  _SRC_OBJ_AV_SV, (void *)&VDC_AV2_Options,	AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_CVBS2, SET_SOURCE(_SRC_FROM_VDC, _SRC_CVBS),	_AV_INPUT3,		0,  _SRC_OBJ_AV_SV, (void *)&VDC_AV3_Options,	AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_CVBS2, SET_SOURCE(_SRC_FROM_VDC, _SRC_CVBS),	_AV_INPUT4,		0,  _SRC_OBJ_AV_SV, (void *)&VDC_AV4_Options,	AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_YPbPr0, SET_SOURCE(_SRC_FROM_ADC, _SRC_YPBPR),	_YPBPR_INPUT1,	0,  _SRC_OBJ_YPBPR, (void *)&YPP1_DataInput_Mux, AV1_AUTOSWITCH_DB },
#ifdef YPBPR2_SOURCE_USING_VGA_PATH
	{ TVD_INFMT_YPbPr1, SET_SOURCE(_SRC_FROM_ADC, _SRC_YPBPR),	_YPBPR_INPUT2,	0,	_SRC_OBJ_YPBPR, (void *)&YPP2_DataInput_Mux, AV1_AUTOSWITCH_DB },
#endif
	{ TVD_INFMT_VGA0, SET_SOURCE(_SRC_FROM_ADC, _SRC_VGA),	_VGA_INPUT1,	0,  _SRC_OBJ_VGA,   (void *)&VGA_DataInput_Mux, AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_HDMI0, SET_SOURCE(_SRC_FROM_TMDS, _SRC_HDMI),	_HDMI_INPUT1,	0,  _SRC_OBJ_HDMI,  (void *)NULL, 				AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_HDMI1, SET_SOURCE(_SRC_FROM_TMDS, _SRC_HDMI),	_HDMI_INPUT2,	0,  _SRC_OBJ_HDMI,  (void *)NULL, 				AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_HDMI2, SET_SOURCE(_SRC_FROM_TMDS, _SRC_HDMI),	_HDMI_INPUT3,	0,  _SRC_OBJ_HDMI,  (void *)NULL, 				AV1_AUTOSWITCH_DB },

	{ TVD_INFMT_HDMI3, SET_SOURCE(_SRC_FROM_TMDS, _SRC_HDMI),	_HDMI_INPUT4,	0,  _SRC_OBJ_HDMI,  (void *)NULL, 				AV1_AUTOSWITCH_DB },

	{ TVD_INFMT_VODMA0, SET_SOURCE(_SRC_FROM_VO, _SRC_VO),     _VO_INPUT1,		0,  _SRC_OBJ_VO,    (void *)NULL, 				AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_VODMA1, SET_SOURCE(_SRC_FROM_VO, _SRC_VO),     _VO_INPUT2,		0,  _SRC_OBJ_VO,    (void *)NULL, 				AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_OSD0, SET_SOURCE(_SRC_FROM_OSD, _SRC_OSD),     _OSD_INPUT1,		0,  _SRC_OBJ_VO,    (void *)NULL, 				AV1_AUTOSWITCH_DB },
	{ TVD_INFMT_SCART, SET_SOURCE(_SRC_FROM_VDC, _SRC_SCART),	_SCART_INPUT1,	0, _SRC_OBJ_AV_SV, (void *)&VDC_Scart1_Options,                AV1_AUTOSWITCH_DB},
	{ TVD_INFMT_SCART, SET_SOURCE(_SRC_FROM_VDC, _SRC_SCART_RGB),	_SCART_RGB_INPUT1,	0, _SRC_OBJ_AV_SV, (void *)&VDC_Scart1_Options,                AV1_AUTOSWITCH_DB},
};


StructSourceInput auto_source_av_sv_info[] = {

	{ TVD_INFMT_CVBS1, SET_SOURCE(_SRC_FROM_VDC, _SRC_SV), _SV_INPUT1, 0, _SRC_OBJ_AV_SV, (void *)&VDC_SV1_Options, AV1_AUTOSWITCH_DB},

};


/*================================== Functions ==============================*/

void PcbSource_Init(void)
{
	pr_debug("PcbSource_Init\n");
	InitPinDefineFromBookCode();

	Scaler_InputSrcInit((StructSourceInput *)g_pcbSourceTable);
	Scaler_AutoAVInputSrcInit((StructSourceInput *)auto_source_av_sv_info);
}

StructSourceInput *PcbSource_GetTable(void)
{
	return g_pcbSourceTable;
}


int PcbSource_GetTableSize(void)
{
	return sizeof(g_pcbSourceTable)/sizeof(StructSourceInput);
}


void InitPinDefineFromBookCode(void)
{
	unsigned char ucAVVideoIn = 0, ucAVGroundIn = 0;
	unsigned char ucScartYIn = 0, ucScartRIn = 0, ucScartGIn = 0, ucScartBIn = 0, ucScartGroundIn = 0;
	unsigned char ucSVYIn = 0, ucSVYGround = 0, ucSVCIn = 0, ucSVCGround = 0, ucSVType = 0;

	unsigned char ucADCData = 0, ucADCSOY = 0, ucADCSWAP = 0;



	/* AV1 path */
	if (0 == GetAVPath(AV1, &ucAVVideoIn, &ucAVGroundIn)) {

		tAv1Path.VideoIn = ucAVVideoIn;
		tAv1Path.GroundIn = ucAVGroundIn;
	}

	pr_debug("tAv1Path.VideoIn=%d, tAv1Path.GroundIn=%d\n", tAv1Path.VideoIn, tAv1Path.GroundIn);

	/* AV2 path */
	if (0 == GetAVPath(AV2, &ucAVVideoIn, &ucAVGroundIn)) {

		tAv2Path.VideoIn = ucAVVideoIn;
		tAv2Path.GroundIn = ucAVGroundIn;
	}

	pr_debug("tAv2Path.VideoIn=%d, tAv2Path.GroundIn=%d\n", tAv2Path.VideoIn, tAv2Path.GroundIn);

	/* AV3 path */
	/*
	if (0 == GetAVPath(AV3, &ucAVVideoIn, &ucAVGroundIn)) {

		tAv3Path.VideoIn = ucAVVideoIn;
		tAv3Path.GroundIn = ucAVGroundIn;
	}
	*/

	pr_debug("tAv3Path.VideoIn=%d, tAv3Path.GroundIn=%d\n", tAv3Path.VideoIn, tAv3Path.GroundIn);

	/* Scart1 */
	if (0 == GetScartPath(SCART1, &ucScartYIn, &ucScartRIn, &ucScartGIn, &ucScartBIn, &ucScartGroundIn)) {
		tScart1Path.Y_VideoIn = ucScartYIn;
		tScart1Path.R_VideoIn = ucScartRIn;
		tScart1Path.G_VideoIn = ucScartGIn;
		tScart1Path.B_VideoIn = ucScartBIn;
		tScart1Path.GroundIn = ucScartGroundIn;
	}

	pr_debug("tScart1Path.Y_VideoIn=%d, tScart1Path.R_VideoIn=%d, tScart1Path.G_VideoIn=%d, tScart1Path.B_VideoIn=%d, tScart1Path.GroundIn=%d\n", tScart1Path.Y_VideoIn, tScart1Path.R_VideoIn, tScart1Path.G_VideoIn, tScart1Path.B_VideoIn, tScart1Path.GroundIn);


	/* SV1 */
	if (0 == GetSVPath(SV1, &ucSVYIn, &ucSVYGround, &ucSVCIn, &ucSVCGround, &ucSVType)) {
		tSv1Path.Y_VideoIn = ucSVYIn;
		tSv1Path.Y_GroundIn = ucSVYGround;
		tSv1Path.C_VideoIn = ucSVCIn;
		tSv1Path.C_GroundIn = ucSVCGround;
		tSv1Path.SV_Type = ucSVType;
	}

	pr_debug("tSv1Path.Y_VideoIn=%d, tSv1Path.Y_GroundIn=%d, tSv1Path.C_VideoIn=%d, tSv1Path.C_GroundIn=%d, tSv1Path.SV_Type=%d\n", tSv1Path.Y_VideoIn, tSv1Path.Y_GroundIn, tSv1Path.C_VideoIn, tSv1Path.C_GroundIn, tSv1Path.SV_Type);

	/* SV2 */
	if (0 == GetSVPath(SV2, &ucSVYIn, &ucSVYGround, &ucSVCIn, &ucSVCGround, &ucSVType)) {
		tSv1Path.Y_VideoIn = ucSVYIn;
		tSv1Path.Y_GroundIn = ucSVYGround;
		tSv1Path.C_VideoIn = ucSVCIn;
		tSv1Path.C_GroundIn = ucSVCGround;
		tSv1Path.SV_Type = ucSVType;
	}

	pr_debug("tSv2Path.Y_VideoIn=%d, tSv2Path.Y_GroundIn=%d, tSv2Path.C_VideoIn=%d, tSv2Path.C_GroundIn=%d, tSv2Path.SV_Type=%d\n", tSv2Path.Y_VideoIn, tSv2Path.Y_GroundIn, tSv2Path.C_VideoIn, tSv2Path.C_GroundIn, tSv2Path.SV_Type);


	/* VGA */
	if (0 == GetVGAPath(VGA1, &ucADCData, &ucADCSOY, &ucADCSWAP)) {
		tVGAPath.DATA_INPUT = ucADCData;
		tVGAPath.SOY_INPUT = ucADCSOY;
		tVGAPath.SWAP_PATH = ucADCSWAP;
	}

	pr_debug("tVGAPath.DATA_INPUT=%d, tVGAPath.SOY_INPUT=%d, tVGAPath.SWAP_PATH=%d\n", tVGAPath.DATA_INPUT, tVGAPath.SOY_INPUT, tVGAPath.SWAP_PATH);

	/* YPP1 */
	if (0 == GetYPPPath(YPP1, &ucADCData, &ucADCSOY, &ucADCSWAP)) {
		tYPbPrPath1.DATA_INPUT = ucADCData;
		tYPbPrPath1.SOY_INPUT = ucADCSOY;
		tYPbPrPath1.SWAP_PATH = ucADCSWAP;
	}

	pr_debug("tYPbPrPath1.DATA_INPUT=%d, tYPbPrPath1.SOY_INPUT=%d, tYPbPrPath1.SWAP_PATH=%d\n", tYPbPrPath1.DATA_INPUT, tYPbPrPath1.SOY_INPUT, tYPbPrPath1.SWAP_PATH);

#if 0
	/* YPP2 */
	if (0 == GetYPPPath(YPP2, &ucADCData, &ucADCSOY, &ucADCSWAP)) {
		tYPbPrPath2.DATA_INPUT = ucADCData;
		tYPbPrPath2.SOY_INPUT = ucADCSOY;
		tYPbPrPath2.SWAP_PATH = ucADCSWAP;
	}

	pr_debug("tYPbPrPath2.DATA_INPUT=%d, tYPbPrPath2.SOY_INPUT=%d, tYPbPrPath2.SWAP_PATH=%d\n", tYPbPrPath2.DATA_INPUT, tYPbPrPath2.SOY_INPUT, tYPbPrPath2.SWAP_PATH);
#endif
}


int GetAVPath(unsigned char a_ucPort, unsigned char *a_pucVideoIn, unsigned char *a_pucGroundIn)
{
	unsigned long long ullValue = 0xff;
	int lRet;

	lRet = -1;

	pr_debug("GetAVPath, a_ucPort=%d\n", a_ucPort);

	switch (a_ucPort) {
	case AV1:
		if (0 == pcb_mgr_get_enum_info_byname("AV1_PATH", &ullValue)) {

			*a_pucVideoIn = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("AV1_PATH_GROUND", &ullValue)) {

				*a_pucGroundIn = (unsigned char)ullValue;
				lRet = 0;
			}
		}

		break;


	case AV2:
		if (0 == pcb_mgr_get_enum_info_byname("AV2_PATH", &ullValue)) {

			*a_pucVideoIn = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("AV2_PATH_GROUND", &ullValue)) {

				*a_pucGroundIn = (unsigned char)ullValue;
				lRet = 0;
			}
		}

		break;

	case AV3:
		if (0 == pcb_mgr_get_enum_info_byname("AV3_PATH", &ullValue)) {

			*a_pucVideoIn = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("AV3_PATH_GROUND", &ullValue)) {

				*a_pucGroundIn = (unsigned char)ullValue;
				lRet = 0;
			}
		}

		break;

	}


	pr_debug("AV path lRet=%d, VideoIn=%d, GroundIn=%d\n", lRet, *a_pucVideoIn, *a_pucGroundIn);

	return lRet;

}



int GetScartPath(unsigned char a_ucPort, unsigned char *a_pucYIn, unsigned char *a_pucRIn, unsigned char *a_pucGIn, unsigned char *a_pucBIn, unsigned char *a_pucGroundIn)
{
	unsigned long long ullValue = 0xff;
	int lRet;

	lRet = -1;

	pr_debug("GetScartPath, a_ucPort=%d\n", a_ucPort);

	switch (a_ucPort) {
	case SCART1:
		if (0 == pcb_mgr_get_enum_info_byname("SCART1_PATH_Y", &ullValue)) {

			*a_pucYIn = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("SCART1_PATH_R", &ullValue)) {

				*a_pucRIn = (unsigned char)ullValue;

				if (0 == pcb_mgr_get_enum_info_byname("SCART1_PATH_G", &ullValue)) {

					*a_pucGIn = (unsigned char)ullValue;

					if (0 == pcb_mgr_get_enum_info_byname("SCART1_PATH_B", &ullValue)) {

						*a_pucBIn = (unsigned char)ullValue;

						if (0 == pcb_mgr_get_enum_info_byname("SCART1_PATH_GROUND", &ullValue)) {

							*a_pucGroundIn = (unsigned char)ullValue;

							lRet = 0;
						} /* SCART1_Ground */
					} /* SCART1_B_IN */
				} /* SCART1_G_IN */
			} /* SCART1_R_IN */
		} /* SCART1_Y_IN */

		break;

	}


	pr_debug("Scart path lRet=%d, YIn=%d, RIn=%d, GIn=%d, BIn=%d, GroundIn=%d\n", lRet, *a_pucYIn, *a_pucRIn, *a_pucGIn, *a_pucBIn, *a_pucGroundIn);

	return lRet;

}

int GetSVPath(unsigned char a_ucPort, unsigned char *a_pucYIn, unsigned char *a_pucYGround, unsigned char *a_pucCIn, unsigned char *a_pucCGround, unsigned char *a_pucType)
{
	unsigned long long ullValue = 0xff;
	int lRet;

	lRet = -1;

	pr_debug("GetSVPath, a_ucPort=%d\n", a_ucPort);

	switch (a_ucPort) {
	case SV1:
		if (0 == pcb_mgr_get_enum_info_byname("SV1_Y_IN", &ullValue)) {

			*a_pucYIn = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("SV1_Y_GROUND", &ullValue)) {

				*a_pucYGround = (unsigned char)ullValue;

				if (0 == pcb_mgr_get_enum_info_byname("SV1_C_IN", &ullValue)) {

					*a_pucCIn = (unsigned char)ullValue;

					if (0 == pcb_mgr_get_enum_info_byname("SV1_C_GROUND", &ullValue)) {

						*a_pucCGround = (unsigned char)ullValue;

						if (0 == pcb_mgr_get_enum_info_byname("SV1_TYPE", &ullValue)) {

							*a_pucType = (unsigned char)ullValue;

							lRet = 0;
						} /* SV1_TYPE */
					} /* SV1_C_GROUND */
				} /* SCART1_G_IN */
			} /* SV1_C_IN */
		} /* SV1_Y_GROUND */

		break;

	case SV2:
		if (0 == pcb_mgr_get_enum_info_byname("SV2_Y_IN", &ullValue)) {

			*a_pucYIn = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("SV2_Y_GROUND", &ullValue)) {

				*a_pucYGround = (unsigned char)ullValue;

				if (0 == pcb_mgr_get_enum_info_byname("SV2_C_IN", &ullValue)) {

					*a_pucCIn = (unsigned char)ullValue;

					if (0 == pcb_mgr_get_enum_info_byname("SV2_C_GROUND", &ullValue)) {

						*a_pucCGround = (unsigned char)ullValue;

						if (0 == pcb_mgr_get_enum_info_byname("SV2_TYPE", &ullValue)) {

							*a_pucType = (unsigned char)ullValue;

							lRet = 0;
						} /* SV1_TYPE*/
					} /* SV1_C_GROUND */
				} /* SCART1_G_IN */
			} /*SV1_C_IN */
		} /* SV1_Y_GROUND */

		break;


	}


	pr_debug("SV path lRet=%d, YIn=%d, YGround=%d, CIn=%d, CGround=%d, Type=%d\n", lRet, *a_pucYIn, *a_pucYGround, *a_pucCIn, *a_pucCGround, *a_pucType);

	return lRet;

}


int GetVGAPath(unsigned char a_ucPort, unsigned char *a_pucData, unsigned char *a_pucSOY, unsigned char *a_pucSWAP)
{
	unsigned long long ullValue = 0xff;
	int lRet;

	lRet = -1;

	pr_debug("GetVGAPath, a_ucPort=%d\n", a_ucPort);

	switch (a_ucPort) {
	case VGA1:
		if (0 == pcb_mgr_get_enum_info_byname("VGA1_DATA", &ullValue)) {

			*a_pucData = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("VGA1_SOY_MUX", &ullValue)) {

				*a_pucSOY = (unsigned char)ullValue;

				if (0 == pcb_mgr_get_enum_info_byname("VGA1_SWAP_RGB", &ullValue)) {

					*a_pucSWAP = (unsigned char)ullValue;

					lRet = 0;

				} /* VGA1_SWAP_RGB */
			} /* VGA1_SOY_MUX */
		} /* VGA1_DATA */

		break;

	case VGA2:
		if (0 == pcb_mgr_get_enum_info_byname("VGA2_DATA", &ullValue)) {

			*a_pucData = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("VGA2_SOY_MUX", &ullValue)) {

				*a_pucSOY = (unsigned char)ullValue;

				if (0 == pcb_mgr_get_enum_info_byname("VGA2_SWAP_RGB", &ullValue)) {

					*a_pucSWAP = (unsigned char)ullValue;

					lRet = 0;

				} /* VGA1_SWAP_RGB */
			} /* VGA1_SOY_MUX */
		} /* VGA1_DATA */

		break;


	}


	pr_debug("VGA path lRet=%d, a_pucData=%d, a_pucSOY=%d, a_pucSWAP=%d\n", lRet, *a_pucData, *a_pucSOY, *a_pucSWAP);

	return lRet;

}


int GetYPPPath(unsigned char a_ucPort, unsigned char *a_pucData, unsigned char *a_pucSOY, unsigned char *a_pucSWAP)
{
	unsigned long long ullValue = 0xff;
	int lRet;

	lRet = -1;

	pr_debug("GetVGAPath, a_ucPort=%d\n", a_ucPort);

	switch (a_ucPort) {
	case YPP1:
	if (0 == pcb_mgr_get_enum_info_byname("YPP1_DATA", &ullValue)) {

		*a_pucData = (unsigned char)ullValue;

		if (0 == pcb_mgr_get_enum_info_byname("YPP1_SOY_MUX", &ullValue)) {

			*a_pucSOY = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("YPP1_SWAP_RGB", &ullValue)) {

				*a_pucSWAP = (unsigned char)ullValue;

				lRet = 0;

			} /* VGA1_SWAP_RGB */
		} /* VGA1_SOY_MUX */
	} /* VGA1_DATA */

	break;

	case YPP2:
	if (0 == pcb_mgr_get_enum_info_byname("YPP2_DATA", &ullValue)) {

		*a_pucData = (unsigned char)ullValue;

		if (0 == pcb_mgr_get_enum_info_byname("YPP2_SOY_MUX", &ullValue)) {

			*a_pucSOY = (unsigned char)ullValue;

			if (0 == pcb_mgr_get_enum_info_byname("YPP2_SWAP_RGB", &ullValue)) {

				*a_pucSWAP = (unsigned char)ullValue;

				lRet = 0;

			} /*/ VGA1_SWAP_RGB */
		} /* VGA1_SOY_MUX */
	} /* VGA1_DATA */

	break;


	}


	pr_debug("YPP path lRet=%d, a_pucData=%d, a_pucSOY=%d, a_pucSWAP=%d\n", lRet, *a_pucData, *a_pucSOY, *a_pucSWAP);

	return lRet;

}

