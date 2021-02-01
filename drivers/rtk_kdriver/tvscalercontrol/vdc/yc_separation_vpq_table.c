
#include <rbus/vdtop_reg.h>
#include <rbus/vdpq_reg.h>
#include <scalercommon/scalerCommon.h>
#include <tvscalercontrol/vdc/yc_separation_vpq_table.h>
#include <tvscalercontrol/vdc/video.h>

#if 0
// REMAPPING TABLE
#endif

unsigned char VPQ_PRJ_TABLE_SEL[PRJ_NUM_MAX][PRJ_TBL_ITEM_MAX] =
{
	/*
	[0: YC Delay]		[1: Digital filter]	[2: Y EQ filter]	[3:1D Table]
	[4: 2D Table]		[5: 3D Table]		[6: 3D DMA Table]	[7: 2D POSTP Alpha]
	[8: 3D POSTP Alpha]
	*/
	/*			0	1	2	3	4	5	6	7	8	*/
	/* 0 */	{	2,	0,	0,	0,	0,	0,	0,	0,	0	}, // TV001
	/* 1 */	{	0,	0,	0,	0,	0,	0,	0,	0,	0	}, // TV002
	/* 2 */	{	1,	1,	1,	1,	1,	1,	1,	1,	1	}, // TV006
	/* 3 */	{	0,	0,	0,	0,	0,	0,	0,	0,	0	}, // NonUsed
	/* 4 */	{	0,	0,	0,	0,	0,	0,	0,	0,	0	}  // NonUsed
};

unsigned char VPQ_1D_TABLE_REMAPPING[INPUT_SRC_MAX][FORMAT_MAX] =
{
	/* SRC_CVBS */
	{
		TABLE1,  // 0 : NTSC
		TABLE5,  // 1 : PAL_M
		TABLE8,  // 2 : NTSC_50
		TABLE6,  // 3 : PAL_N
		TABLE7,  // 4 : NTSC443
		TABLE3,  // 5 : PAL_60
		TABLE2,  // 6 : PAL
		TABLE9,  // 7 : SECAM
	},
	/* _SRC_TV internal demod : IFD path */
	{
		TABLE1,  // 0 : NTSC
		TABLE5,  // 1 : PAL_M
		TABLE8,  // 2 : NTSC_50
		TABLE6,  // 3 : PAL_N
		TABLE7,  // 4 : NTSC443
		TABLE3,  // 5 : PAL_60
		TABLE2,  // 6 : PAL
		TABLE9,  // 7 : SECAM
	},
	/* _SRC_TV external demod : VD path */
	{
		TABLE1,  // 0 : NTSC
		TABLE5,  // 1 : PAL_M
		TABLE8,  // 2 : NTSC_50
		TABLE6,  // 3 : PAL_N
		TABLE7,  // 4 : NTSC443
		TABLE3,  // 5 : PAL_60
		TABLE2,  // 6 : PAL
		TABLE9,  // 7 : SECAM
	}
};

unsigned char VPQ_2D_TABLE_REMAPPING[INPUT_SRC_MAX][FORMAT_MAX] =
{
	/* SRC_CVBS */
	{
		TABLE1,  // 0 : NTSC
		TABLE6,  // 1 : PAL_M
		TABLE7,  // 2 : NTSC_50
		TABLE8,  // 3 : PAL_N
		TABLE5,  // 4 : NTSC443
		TABLE9,  // 5 : PAL_60
		TABLE2,  // 6 : PAL  // jj
		TABLE5,  // 7 : SECAM
	},
	/* _SRC_TV internal demod : IFD path */
	{
		TABLE10,  // 0 : NTSC
	    TABLE11,  // 1 : PAL_M
	    TABLE12,  // 2 : NTSC_50
	    TABLE13,  // 3 : PAL_N
	    TABLE14,  // 4 : NTSC443
	    TABLE15,  // 5 : PAL_60
	    TABLE16,  // 6 : PAL  // jj
	    TABLE14,  // 7 : SECAM
	},
	/* _SRC_TV external demod : VD path */
	{
		TABLE10,  // 0 : NTSC
	    TABLE11,  // 1 : PAL_M
	    TABLE12,  // 2 : NTSC_50
	    TABLE13,  // 3 : PAL_N
	    TABLE14,  // 4 : NTSC443
	    TABLE15,  // 5 : PAL_60
	    TABLE16,  // 6 : PAL  // jj
	    TABLE14,  // 7 : SECAM
	}
};

unsigned char VPQ_3D_TABLE_REMAPPING[INPUT_SRC_MAX][FORMAT_MAX] =
{
	/* SRC_CVBS */
	{
		TABLE1,  // 0 : NTSC
		TABLE3,  // 1 : PAL_M
		TABLE8,  // 2 : NTSC_50
		TABLE7,  // 3 : PAL_N
		TABLE2,  // 4 : NTSC443
		TABLE6,  // 5 : PAL_60
		TABLE4,  // 6 : PAL
		TABLE5,  // 7 : SECAM
	},
	/* _SRC_TV internal demod : IFD path */
	{
		TABLE9,  // 0 : NTSC
	    TABLE10, // 1 : PAL_M
	    TABLE13, // 2 : NTSC_50
	    TABLE16, // 3 : PAL_N
	    TABLE12, // 4 : NTSC443
	    TABLE14, // 5 : PAL_60
	    TABLE11, // 6 : PAL
	    TABLE15, // 7 : SECAM
	},
	/* _SRC_TV external demod : VD path */
	{
		TABLE9,  // 0 : NTSC
	    TABLE10, // 1 : PAL_M
	    TABLE13, // 2 : NTSC_50
	    TABLE16, // 3 : PAL_N
	    TABLE12, // 4 : NTSC443
	    TABLE14, // 5 : PAL_60
	    TABLE11, // 6 : PAL
	    TABLE15, // 7 : SECAM
	}
};

unsigned char VPQ_CTI_TABLE_REMAPPING[VPQ_DCTI_MAX][INPUT_SRC_MAX][FORMAT_MAX] =
{
	/* === For 1D ======================================*/
	{
		/* SRC_CVBS */
		{
			TABLE1,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE1,	// PAL_N
			TABLE1,	// NTSC443
			TABLE2,	// PAL_60
			TABLE2,	// PAL
			TABLE1	// SECAM
		},
		/* _SRC_TV internal demod : IFD path */
		{
			TABLE5,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE1,	// NTSC443
			TABLE2,	// PAL_60
			TABLE2,	// PAL
			TABLE4	// SECAM
		},
		/* _SRC_TV external demod : VD path */
		{
			TABLE5,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE1,	// NTSC443
			TABLE2,	// PAL_60
			TABLE2,	// PAL
			TABLE4	// SECAM
		}
	},
	/* === For 2D ======================================*/
	{
		/* SRC_CVBS */
		{
			TABLE1,	// NTSC  Table2->Table1 JZ
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE1,	// PAL_N
			TABLE2,	// NTSC443
			TABLE2,	// PAL_60
			TABLE2,	// PAL
			TABLE1	// SECAM
		},
		/* _SRC_TV internal demod : IFD path */
		{
			TABLE5,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE2,	// NTSC443
			TABLE2,	// PAL_60
			TABLE3,	// PAL
			TABLE4	// SECAM
		},
		/* _SRC_TV external demod : VD path */
		{
			TABLE5,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE2,	// NTSC443
			TABLE2,	// PAL_60
			TABLE3,	// PAL
			TABLE4	// SECAM
		}
	},
	/* === For 2D ======================================*/
	{
		/* SRC_CVBS */
		{
			TABLE1,	// NTSC  Table2->Table1 JZ
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE2,	// NTSC443
			TABLE2,	// PAL_60
			TABLE1,	// PAL, Table2-> Table1, Disable by willy 20151130
			TABLE1	// SECAM
		},
		/* _SRC_TV internal demod : IFD path */
		{
			TABLE5,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE2,	// NTSC443
			TABLE2,	// PAL_60
			TABLE2,	// PAL
			TABLE4	// SECAM
		},
		/* _SRC_TV external demod : VD path */
		{
			TABLE5,	// NTSC
			TABLE2,	// PAL_M
			TABLE1,	// NTSC_50
			TABLE2,	// PAL_N
			TABLE2,	// NTSC443
			TABLE2,	// PAL_60
			TABLE2,	// PAL
			TABLE4	// SECAM
		}
	}
};
#if 0
// VDTOP TABLE
#endif

unsigned char VTOP_1D_HSYNC_START_TBL[INPUT_SRC_MAX][FORMAT_MAX][2] =
{
	/* AV */
{
	/*	Mode,	HsyncSta */
	{	HwMode,	0x82	}, // NTSC
	{	HwMode,	0x82	}, // PALM
	{	HwMode,	0x82	}, // NTSC50
	{	HwMode,	0x8c	}, // PALN
	{	HwMode,	0x7a	}, // NTSC443
	{	HwMode,	0x7c	}, // PAL60
	{	HwMode,	0x86	}, // PALI
	{	HwMode,	0x8a	}, // SECAM
	},
	/* TV */
	{
		/*	Mode,	HsyncSta */
		{	HwMode,	0x82	}, // NTSC
		{	HwMode,	0x82	}, // PALM
		{	HwMode,	0x82	}, // NTSC50
		{	HwMode,	0x8c	}, // PALN
		{	HwMode,	0x7a	}, // NTSC443
		{	HwMode,	0x7c	}, // PAL60
		{	HwMode,	0x86	}, // PALI
		{	HwMode,	0x8a	}, // SECAM
	},
	/* ExTV */
	{
		/*	Mode,	HsyncSta */
		{	HwMode,	0x82	}, // NTSC
		{	HwMode,	0x82	}, // PALM
		{	HwMode,	0x82	}, // NTSC50
		{	HwMode,	0x8c	}, // PALN
		{	HwMode,	0x7a	}, // NTSC443
		{	HwMode,	0x7c	}, // PAL60
		{	HwMode,	0x86	}, // PALI
		{	HwMode,	0x8a	}, // SECAM
	}
};

unsigned char VTOP_2D_HSYNC_START_TBL[INPUT_SRC_MAX][FORMAT_MAX][2] =
{
	/* AV */
	{
		/*	Mode,	HsyncSta */
		{	HwMode,	0x82	}, // NTSC
		{	HwMode,	0x82	}, // PALM
		{	HwMode,	0x82	}, // NTSC50
		{	HwMode,	0x8c	}, // PALN
		{	HwMode,	0x7a	}, // NTSC443
		{	HwMode,	0x7c	}, // PAL60
		{	HwMode,	0x86	}, // PALI
		{	HwMode,	0x8a	}, // SECAM
	},
	/* TV */
{
	/*	Mode,	HsyncSta */
	{	HwMode,	0x82	}, // NTSC
	{	HwMode,	0x82	}, // PALM
	{	HwMode,	0x82	}, // NTSC50
	{	HwMode,	0x8c	}, // PALN
	{	HwMode,	0x7a	}, // NTSC443
	{	HwMode,	0x7c	}, // PAL60
	{	HwMode,	0x86	}, // PALI
	{	HwMode,	0x8a	}, // SECAM
	},
	/* ExTV */
	{
		/*	Mode,	HsyncSta */
		{	HwMode,	0x82	}, // NTSC
		{	HwMode,	0x82	}, // PALM
		{	HwMode,	0x82	}, // NTSC50
		{	HwMode,	0x8c	}, // PALN
		{	HwMode,	0x7a	}, // NTSC443
		{	HwMode,	0x7c	}, // PAL60
		{	HwMode,	0x86	}, // PALI
		{	HwMode,	0x8a	}, // SECAM
	}
};

unsigned char VTOP_3D_HSYNC_START_TBL[INPUT_SRC_MAX][FORMAT_MAX][2] =
{
	/* AV */
{
	/*	Mode,	HsyncSta */
	{	FwMode,	0x86	}, // NTSC
	{	FwMode,	0x89	}, // PALM
	{	FwMode,	0x86	}, // NTSC50
	{	FwMode,	0x8c	}, // PALN
	{	FwMode,	0x86	}, // NTSC443
	{	HwMode,	0x7c	}, // PAL60
	{	FwMode,	0x89	}, // PALI
	{	FwMode,	0x8a	}, // SECAM
	},
	/* TV */
	{
		/*	Mode,	HsyncSta */
		{	FwMode,	0x88	}, // NTSC
		{	FwMode,	0x89	}, // PALM
		{	FwMode,	0x88	}, // NTSC50
		{	FwMode,	0x8f	}, // PALN
		{	FwMode,	0x88	}, // NTSC443
		{	HwMode,	0x7c	}, // PAL60
		{	FwMode,	0x8a	}, // PALI
		{	FwMode,	0x8a	}, // SECAM
	},
	/* ExTV */
	{
		/*	Mode,	HsyncSta */
		{	FwMode,	0x88	}, // NTSC
		{	FwMode,	0x89	}, // PALM
		{	FwMode,	0x88	}, // NTSC50
		{	FwMode,	0x8f	}, // PALN
		{	FwMode,	0x88	}, // NTSC443
		{	HwMode,	0x7c	}, // PAL60
		{	FwMode,	0x8a	}, // PALI
		{	FwMode,	0x8a	}, // SECAM
	}
};

#if 0
// PQ TABLE
#endif

/*=========POST-PROC. Alpha_Weight Table========= */
unsigned char VPQ_2D_POSTP_ALPHAWEI_SET[PRJ_NUM_MAX][INPUT_SRC_MAX][FORMAT_MAX][19] =
{
	// 2D , BLD, 3D (alpha blending weight)
    // [0], [1], [2]  : xNR, max: 4
    // [3], [4], [5]  : Median Filter // removed by spec. yrchen 2014.07
    // [6], [7], [8]  : DLTI, max: 2
    // [9], [10],[11] : PK, max: 2
    // [12],[13],[14] : SPNR, max: 4 //added by spec. yrchen
    // [15] : round all post-process
    // [16] : notch_force_upbnd,
    // [17] : notch_force_3Dweight, [18] mfnotch_alpha_2d_weight
	/* TABLE 0 */
	{
	    /* AV */
	    {
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
	    },
	    /* ATV */
	    {
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
	    },
	    /* ExTV */
	    {
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
	    }
	},
	/* TABLE 1 */
	{
	    /* AV */
	    {
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
	    },
	    /* ATV */
	    {
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
	    },
	    /* ExTV */
	    {
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/0,0,0,/*MF*/1,1,0,/*DLTI*/2,1,1,/*PK*/2,1,1,/*SPNR*/2,1,1,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
	    }
	},
};

unsigned char VPQ_3D_POSTP_ALPHAWEI_SET[PRJ_NUM_MAX][INPUT_SRC_MAX][FORMAT_MAX][19] =
{
	// 2D , BLD, 3D (alpha blending weight)
	// [0], [1], [2]  : xNR, max: 4
	// [3], [4], [5]  : Median Filter // removed by spec. yrchen 2014.07
	// [6], [7], [8]  : DLTI, max: 2
	// [9], [10],[11] : PK, max: 2
	// [12],[13],[14] : SPNR, max: 4 //added by spec. yrchen
	// [15] : round all post-process
	// [16] : notch_force_upbnd,
	// [17] : notch_force_3Dweight, [18] mfnotch_alpha_2d_weight
	/* TABLE 0 */
	{

	  	/* AV */
		{
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
		},
		/* TV */
		{
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/3,2,2,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
		},
		/* ExTV */
		{
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/3,2,2,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
		}
	},
	/* TABLE 1 */
	{

	  	/* AV */
		{
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/2,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
		},
		/* TV */
		{
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/3,2,2,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
		},
		/* ExTV */
		{
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALM*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC50*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PALN*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*NTSC443*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/0,0,0,/*15*/1,/**/80,/*Notch*/0,2}, /*PAL60*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/3,2,2,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*PALI*/
	        {/*xNR*/2,0,0,/*MF*/0,0,0,/*DLTI*/0,0,0,/*PK*/0,0,2,/*SPNR*/3,3,3,/*15*/1,/**/80,/*Notch*/0,2}, /*SECAM*/
		}
	},
};

unsigned int VPQ_Y_EQ_FILTER[PRJ_NUM_MAX][2][41] =
{
	/* TABLE 0 */
	{
		// 0: Bypass
		{
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,	0x3ff
		},
		// 1: NTSC, Sample Frequency = 14.32MHz, PassBand = 3.5MHz, StopBand = 5MHz
		{
			0x001, 0x001, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x7ff, 0x000,
			0x001, 0x7ff, 0x7ff, 0x003,	0x000, 0x7fc, 0x003, 0x003,
			0x7f9, 0x000, 0x00a, 0x7f8,	0x7f7, 0x012, 0x7ff, 0x7e7,
			0x013, 0x016, 0x7d3, 0x001,	0x049, 0x7c1, 0x7a2, 0x135,	0x265
		}
	},
	/* TABLE 1 */
	{
		// 0: Bypass
		{
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,	0x3ff
		},
		// 1: NTSC, Sample Frequency = 14.32MHz, PassBand = 3.5MHz, StopBand = 5MHz
		{
			0x001, 0x001, 0x000, 0x000,	0x000, 0x000, 0x000, 0x000,
			0x000, 0x000, 0x000, 0x000,	0x000, 0x000, 0x7ff, 0x000,
			0x001, 0x7ff, 0x7ff, 0x003,	0x000, 0x7fc, 0x003, 0x003,
			0x7f9, 0x000, 0x00a, 0x7f8,	0x7f7, 0x012, 0x7ff, 0x7e7,
			0x013, 0x016, 0x7d3, 0x001,	0x049, 0x7c1, 0x7a2, 0x135,	0x265
		}
	},
};

unsigned char VPQ_YCBCR_DELAY_TABLE[PRJ_NUM_MAX][YCSEP_STATUS_MAX][INPUT_SRC_MAX][FORMAT_MAX][YCDLEAY_MAX] =
{
	/* TABLE 0 */
	{
		/* === For 1D ======================================*/
		{
			{	/* _SRC_CVBS */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV internal demod : IFD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x05,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV external demod : VD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x25,	0x23,	0x23,	0x05,	0x0,	0x0,	0x0	},	/* SECAM */
			},
		},
		/* === For 2D and 3D =================================*/
		{
			{	/* _SRC_CVBS */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x02,	0x02,	0x02,	0x00,	0x03,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x01,	0x02,	0x02,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x01,	0x02,	0x02,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x11,	0x13,	0x13,	0x12,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x01,	0x02,	0x02,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV internal demod : IFD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x05,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x02,	0x01,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x01,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x01,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x04,	0x01,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV external demod : VD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x02,	0x01,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x25,	0x23,	0x24,	0x05,	0x0,	0x0,	0x0	},	/* SECAM */
			},
		},
	},
	/* TABLE 1 */
	{
		/* === For 1D ======================================*/
		{
			{	/* _SRC_CVBS */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV internal demod : IFD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x05,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV external demod : VD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x25,	0x23,	0x23,	0x05,	0x0,	0x0,	0x0	},	/* SECAM */
			},
		},
		/* === For 2D and 3D =================================*/
		{
			{	/* _SRC_CVBS */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x02,	0x02,	0x02,	0x00,	0x03,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x02,	0x02,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x02,	0x02,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x11,	0x13,	0x13,	0x12,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x01,	0x02,	0x02,	0x00,	0x02,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV internal demod : IFD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x05,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x02,	0x01,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x01,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x01,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x04,	0x01,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV external demod : VD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x02,	0x01,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x25,	0x23,	0x24,	0x05,	0x0,	0x0,	0x0	},	/* SECAM */
			},
		},
	},
	/* New Table 2 */
	{
		/* === For 1D ======================================*/
		{
			{	/* _SRC_CVBS */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x0d,	0x0,	0x0,	0x0	},	/* NTSC */ // ok
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x0d,	0x0,	0x0,	0x0	},	/* PALM */ // ok
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x02,	0x0,	0x0,	0x0	},	/* NTSC50 */ // ok
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* PALN */ // ok
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */ // ok
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x02,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */ // ok
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x02,	0x02,	0x0,	0x0,	0x0	},	/* PALI */ // ok
				{	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV internal demod : IFD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x05,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV external demod : VD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x00,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x25,	0x23,	0x23,	0x05,	0x0,	0x0,	0x0	},	/* SECAM */
			},
		},
		/* === For 2D and 3D =================================*/
		{
			{	/* _SRC_CVBS */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x02,	0x02,	0x02,	0x0c,	0x0f,	0x10,	0x00,	0x0,	0x0,	0x0	},	/* NTSC */ // ok (160, 360)
				{	0x02,	0x02,	0x01,	0x0b,	0x0e,	0x0f,	0x00,	0x0,	0x0,	0x0	},	/* PALM */ // ok
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* NTSC50 */ // ok
				{	0x02,	0x02,	0x00,	0x00,	0x02,	0x04,	0x00,	0x0,	0x0,	0x0	},	/* PALN */ // ok
				{	0x00,	0x00,	0x00,	0x26,	0x29,	0x2a,	0x12,	0x0,	0x0,	0x0	},	/* NTSC443 */ // ok
				{	0x00,	0x00,	0x00,	0x25,	0x28,	0x28,	0x00,	0x0,	0x0,	0x0	},	/* PAL60 */ // ok
				{	0x01,	0x02,	0x02,	0x19,	0x1b,	0x1b,	0x00,	0x0,	0x0,	0x0	},	/* PALI */ // ok
				{	0x00,	0x00,	0x00,	0x2d,	0x2e,	0x2f,	0x00,	0x0,	0x0,	0x0	},	/* SECAM */ // need h sync help (160 330)
			},
			{	/* _SRC_TV internal demod : IFD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x05,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x02,	0x01,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x01,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x02,	0x01,	0x01,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x01,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* SECAM */
			},
			{	/* _SRC_TV external demod : VD path */
				/*	Y,		Cb,		Cr,		NewY,	NewCb,	NewCr,	NewCKY,	4fscY,	4fscCb,	4fscCr	*/
				{	0x00,	0x00,	0x00,	0x02,	0x04,	0x03,	0x02,	0x0,	0x0,	0x0	},	/* NTSC */
				{	0x00,	0x02,	0x01,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALM */
				{	0x00,	0x00,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* NTSC50 */
				{	0x00,	0x01,	0x00,	0x00,	0x00,	0x00,	0x01,	0x0,	0x0,	0x0	},	/* PALN */
				{	0x00,	0x00,	0x00,	0x00,	0x04,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* NTSC443 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x02,	0x01,	0x0,	0x0,	0x0	},	/* PAL60 */
				{	0x00,	0x00,	0x00,	0x00,	0x03,	0x03,	0x01,	0x0,	0x0,	0x0	},	/* PALI */
				{	0x00,	0x00,	0x00,	0x25,	0x23,	0x24,	0x05,	0x0,	0x0,	0x0	},	/* SECAM */
			},
		},
	}
};

unsigned char VPQ_FRONT_DIGITAL_FILTER[PRJ_NUM_MAX][YCSEP_STATUS_MAX][FORMAT_MAX][INPUT_SRC_MAX][5] =
{
	/* TABLE 0 */
	{
		/* === For 1D ======================================*/
		{
			{
				/* NTSC */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00}
			},
			{
				/* PALM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* NTSC50 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00}
			},
			{
				/* PALN */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* NTSC443 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00},
			},
			{
				/* PAL60 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* PALI */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* SECAM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00}
			}
		},
		/* === For 2D and 3D =================================*/
		{
			{
				/* NTSC */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x02,		0x00,		0x00,		0x05,		0x00},
				/*TV  */ {	0x02,		0x00,		0x03,		0x06,		0x00},
				/*ExTV*/ {	0x02,		0x00,		0x03,		0x06,		0x00}
			},
			{
				/* PALM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x06,		0x01}
			},
			{
				/* NTSC50 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x00,		0x00}
			},
			{
				/* PALN */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x06,		0x01}
			},
			{
				/* NTSC443 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x00,		0x00},
			},
			{
				/* PAL60 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x03,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x03,		0x00,		0x00,		0x06,		0x01},
				/*ExTV*/ {	0x03,		0x00,		0x00,		0x06,		0x01}
			},
			{
				/* PALI */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x00,		0x00,		0x04,		0x04,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x04,		0x04,		0x01}
			},
			{
				/* SECAM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x00,		0x00}
			}
		}
	},
	/* TABLE 1 */
	{
		/* === For 1D ======================================*/
		{
			{
				/* NTSC */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00}
			},
			{
				/* PALM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* NTSC50 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00}
			},
			{
				/* PALN */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* NTSC443 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00},
			},
			{
				/* PAL60 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* PALI */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x01}
			},
			{
				/* SECAM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x06,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x06,		0x00,		0x00}
			}
		},
		/* === For 2D and 3D =================================*/
		{
			{
				/* NTSC */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x02,		0x00,		0x00,		0x06,		0x00},
				/*TV  */ {	0x02,		0x00,		0x03,		0x06,		0x00},
				/*ExTV*/ {	0x02,		0x00,		0x03,		0x06,		0x00}
			},
			{
				/* PALM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x06,		0x01}
			},
			{
				/* NTSC50 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x00,		0x00}
			},
			{
				/* PALN */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x06,		0x01}
			},
			{
				/* NTSC443 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x00,		0x00},
			},
			{
				/* PAL60 */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x03,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x03,		0x00,		0x00,		0x06,		0x01},
				/*ExTV*/ {	0x03,		0x00,		0x00,		0x06,		0x01}
			},
			{
				/* PALI */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x06,		0x01},
				/*TV  */ {	0x00,		0x00,		0x04,		0x04,		0x01},
				/*ExTV*/ {	0x00,		0x00,		0x04,		0x04,		0x01}
			},
			{
				/* SECAM */
				/*			108M_over,	108M,		27M_over,	27M,		Cresample*/
				/*AV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*TV  */ {	0x00,		0x00,		0x00,		0x00,		0x00},
				/*ExTV*/ {	0x00,		0x00,		0x00,		0x00,		0x00}
			}
		}
	},
};

unsigned char VPQ_POSTP_CTI_SET1[18] =
//PAL M ,PALN NTSC50,NTSC443,PAL60   disable the function
{
	0,	//[0] : 9f0c[0]
	0,	//[1] : 9f0c[1]
	1,	//[2] : 9f0c[2]
	1,	//[3] : 9f0c[5]
	0x03,	//[4] : 9f14[3:0]
	0x06,	//[5] : 9f14[7:4]
	0x06,	//[6] : 9f18[3:0]
	0x07,	//[7] : 9f18[7:4]
	0x05,	//[8] : 9f1c[3:0]
	0x06,	//[9] : 9f1c[7:6]
	0x0f,	//[10] : 9f20[3:0]
	0x0f,	//[11] : 9f20[7:6]
	0x00,	//[12] : 9f24[3:0]
	0x05,	//[13] : 9f24[7:6]
	0x09,	//[14] : 9f28[3:0]
	0x03,	//[15] : 9f28[7:6]
	0x09,	//[16] : 9f2c[3:0]
	0x08,	//[17] : 9f2c[7:6]
};

unsigned char  VPQ_POSTP_CTI_SET2[18] =
//ntsc pal i  , av setting
{
	0,	//[0] : 9f0c[0]
	1,	//[1] : 9f0c[1]
	1,	//[2] : 9f0c[2]
	1,	//[3] : 9f0c[5]
	0x06,	//[4] : 9f14[3:0]	//rock_rau 20120827 0023745: [Video] Please change CTI coring level
	0x02,	//[5] : 9f14[7:4]
	0x06,	//[6] : 9f18[3:0]
	0x07,	//[7] : 9f18[7:4]
	0x05,	//[8] : 9f1c[3:0]
	0x06,	//[9] : 9f1c[7:6]
	0x0f,	//[10] : 9f20[3:0]
	0x0f,	//[11] : 9f20[7:6]
	0x00,	//[12] : 9f24[3:0]
	0x00,	//[13] : 9f24[7:6]
	0x07,	//[14] : 9f28[3:0]
	0x02,	//[15] : 9f28[7:6]
	0x03,	//[16] : 9f2c[3:0]
	0x03,	//[17] : 9f2c[7:6]
};

unsigned char VPQ_POSTP_CTI_SET3[18] =
//ntsc pal i  , tv setting
{
	1,	//[0] : 9f0c[0]
	1,	//[1] : 9f0c[1]
	1,	//[2] : 9f0c[2]
	1,	//[3] : 9f0c[5]
	0x03,	//[4] : 9f14[3:0]
	0x02,	//[5] : 9f14[7:4]
	0x06,	//[6] : 9f18[3:0]
	0x07,	//[7] : 9f18[7:4]
	0x05,	//[8] : 9f1c[3:0]
	0x06,	//[9] : 9f1c[7:6]
	0x0f,	//[10] : 9f20[3:0]
	0x0f,	//[11] : 9f20[7:6]
	0x00,	//[12] : 9f24[3:0]
	0x00,	//[13] : 9f24[7:6]
	0x09,	//[14] : 9f28[3:0]
	0x03,	//[15] : 9f28[7:6]
	0x07,	//[16] : 9f2c[3:0]
	0x02,	//[17] : 9f2c[7:6]
};

unsigned char  VPQ_POSTP_CTI_SET4[18] =
//secam
{
	1,	//[0] : 9f0c[0]
	1,	//[1] : 9f0c[1]
	1,	//[2] : 9f0c[2]
	1,	//[3] : 9f0c[5]
	0x03,	//[4] : 9f14[3:0]	//rock_rau 20120906 mantis: //rock_rau 20120827 mantis:0023745
	0x0b,	//[5] : 9f14[7:4]
	0x06,	//[6] : 9f18[3:0]
	0x07,	//[7] : 9f18[7:4]
	0x05,	//[8] : 9f1c[3:0]
	0x06,	//[9] : 9f1c[7:6]
	0x0f,	//[10] : 9f20[3:0]
	0x0f,	//[11] : 9f20[7:6]
	0x04,	//[12] : 9f24[3:0]
	0x00,	//[13] : 9f24[7:6]
	0x07,	//[14] : 9f28[3:0]
	0x02,	//[15] : 9f28[7:6]
	0x03,	//[16] : 9f2c[3:0]
	0x03,	//[17] : 9f2c[7:6]
};

unsigned char  VPQ_POSTP_CTI_SET5[18] =
//LG TV ntsc setting
{
	1,	//[0] : 9f0c[0]
    1,	//[1] : 9f0c[1]
    1,	//[2] : 9f0c[2]
    1,	//[3] : 9f0c[5]
    0x03,	//[4] : 9f14[3:0]
    0x04,	//[5] : 9f14[7:4]
    0x02,	//[6] : 9f18[3:0]
    0x03,	//[7] : 9f18[7:4]
    0x0A,	//[8] : 9f1c[3:0]
    0x0F,	//[9] : 9f1c[7:6]
    0x07,	//[10] : 9f20[3:0]
    0x07,	//[11] : 9f20[7:6]
    0x00,	//[12] : 9f24[3:0]
    0x0F,	//[13] : 9f24[7:6]
    0x0B,	//[14] : 9f28[3:0]
    0x0D,	//[15] : 9f28[7:6]
    0x04,	//[16] : 9f2c[3:0]
    0x02,	//[17] : 9f2c[7:6]
};

/*======================================================================*/
/*============================== 1D Table ==============================*/
/*======================================================================*/
unsigned int VPQ_1D_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [NTSC]
{
	/* TABLE 0 */
	{
		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,				//20121015	rock_rau	mantis: 0026026	//0x644, //20120816 rock_rau
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_C_TH1_reg,			0x0000000c,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000014,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,
		VDPQ_YC_BW_CTRL_reg,				0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209 (1D ->3D vertical shift problem, Jimmy 20151001)

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,				//20121015	rock_rau	mantis: 0026026	//0x644, //20120816 rock_rau
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_C_TH1_reg,			0x0000000c,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000014,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,
		VDPQ_YC_BW_CTRL_reg,				0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209 (1D ->3D vertical shift problem, Jimmy 20151001)

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
		_TBL_END
	},
};

unsigned int VPQ_1D_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [PALI]
{
	/* TABLE 0 */
	{
		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,				//20121015	rock_rau	mantis: 0026026	//0x649, //20120816 rock_rau
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
		VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209 (1D ->3D vertical shift problem, Jimmy 20151001)

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,				//20121015	rock_rau	mantis: 0026026	//0x649, //20120816 rock_rau
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
		VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209 (1D ->3D vertical shift problem, Jimmy 20151001)

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
};

unsigned int VPQ_1D_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [PAL60]
{
	/* TABLE 0 */
	{
		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000443, //0x43, //20120530 nick187 (since Pacific')
		VDPQ_BPF_BW_SEL_C_reg,				0x00000660, //0x60, //20120530 nick187 (since Pacific')
		VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000443, //0x43, //20120530 nick187 (since Pacific')
		VDPQ_BPF_BW_SEL_C_reg,				0x00000660, //0x60, //20120530 nick187 (since Pacific')
		VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
};

unsigned int VPQ_1D_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// low color burst, currently not used
{
	/* TABLE 0 */
	{
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,				//20121015	rock_rau	mantis: 0026026	//0x649, //20120816 rock_rau
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
		VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,				//20121015	rock_rau	mantis: 0026026	//0x649, //20120816 rock_rau
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
		VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
		_TBL_END
	},
};

// new added table, willy 20150703
unsigned int VPQ_1D_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [PALM]
{
	/* TABLE 0 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
	    VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1*/
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
	    VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_1D_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [PALN]
{
	/* TABLE 0 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
	    VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,

		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000003,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
	    VDPQ_YC_BW_CTRL_reg,				0x00000049, //if chroma_vlpf_round_en, 0x149 // yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,

		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
};

unsigned int VPQ_1D_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [NTSC443]
{
	/* TABLE 0 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000014,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,
	    VDPQ_YC_BW_CTRL_reg,				0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000014,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,
	    VDPQ_YC_BW_CTRL_reg,				0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
};
unsigned int VPQ_1D_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [NTSC50]
{
	/* TABLE 0 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000014,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,
	    VDPQ_YC_BW_CTRL_reg,				0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000003,
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x0000000c,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000014,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,
	    VDPQ_YC_BW_CTRL_reg,				0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
	    VDPQ_BW_DETECTION_reg,				0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
};
unsigned int VPQ_1D_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [SECAM]
{
	/* TABLE 0 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,				0x00000003,
	    VDPQ_YC_SEP_MODE_CTRL_reg,				0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,					0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,					0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,				0x0000000c,
	    VDPQ_ADAP_BPF_C_TH2_reg,				0x00000014,
	    VDPQ_ADAP_BPF_Y_TH2_reg,				0x00000003,
	    VDPQ_YC_BW_CTRL_reg,					0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
	    VDPQ_BW_DETECTION_reg,					0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,				0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,				0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,				0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		// 20160115 jimmy for LG AV SECAM
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg,	0x84005002,
		VDPQ_SPNR_CP_Ctrl_reg,					0x07000001,
		VDPQ_SPNR_Spatial_Th_reg,				0x00140a05,
		VDPQ_SPNR_Spatial_Weight_reg,			0x0f000000,
		VDPQ_DE_XC_CTRL_reg,					0x00000003,
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x00000063,
		VDPQ_CADAP_ZC_TH_reg,					0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000089,

	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- Global control ---
	    VDPQ_YC_SEP_CONTROL_reg,				0x00000003,
	    VDPQ_YC_SEP_MODE_CTRL_reg,				0x00000000,

		// --- YC 1D ---
	    VDPQ_BPF_BW_SEL_Y_reg,					0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,					0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_C_TH1_reg,				0x0000000c,
	    VDPQ_ADAP_BPF_C_TH2_reg,				0x00000014,
	    VDPQ_ADAP_BPF_Y_TH2_reg,				0x00000003,
	    VDPQ_YC_BW_CTRL_reg,					0x00000001, //chroma_vlpf_round is disabled in NTSC //yrchen
	    VDPQ_BW_DETECTION_reg,					0x00000060,
	    VDPQ_H2V_Y_NOISE_THR_reg,				0x00000003,
	    VDPQ_H2V_NOISE_MAX_HDY_reg,				0x0000000f,
		VDPQ_YC_Post2DBPF_Ctrl_reg,				0x00000000, // Fix 1D can't enable post2D, V position is different, jennifer 20151209

		//--- Post Process
		// 20160115 jimmy for LG AV SECAM
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg,	0x84005002,
		VDPQ_SPNR_CP_Ctrl_reg,					0x07000001,
		VDPQ_SPNR_Spatial_Th_reg,				0x00140a05,
		VDPQ_SPNR_Spatial_Weight_reg,			0x0f000000,
		VDPQ_DE_XC_CTRL_reg,					0x00000003,
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x00000063,
		VDPQ_CADAP_ZC_TH_reg,					0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000089,

	    _TBL_END
	},
};

/*======================================================================*/
/*============================== 2D Table ==============================*/
/*======================================================================*/
unsigned int VPQ_2D_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] new 2d table Mode 0 : [NTSC]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, // 0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, // 20120606 nick187 for pacific'-noDDR
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002, // 4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, // jimmy
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		//--- Post process ---
		VDPQ_YC_BW_CTRL_reg,				0x00000001, // chroma_vlpf_round is disabled in NTSC
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, // 0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, // 20120606 nick187 for pacific'-noDDR
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002, // 4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, // jimmy
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		//--- Post process ---
		VDPQ_YC_BW_CTRL_reg,				0x00000001, // chroma_vlpf_round is disabled in NTSC
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		_TBL_END
	},
};

unsigned int VPQ_2D_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] new 2d table Mode 2 : [PAL]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, // 20120606 nick187 for pacific'-noDDR
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,	// 4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0, // 0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b, // for panasonic TV_Pal disk 20121217 ,CSFC
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, // lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	// 20121015	rock_rau	mantis: 0026026
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, // 20120606 nick187 for pacific'-noDDR
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,	// 4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0, // 0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b, // for panasonic TV_Pal disk 20121217 ,CSFC
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, // lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
};


unsigned int VPQ_2D_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] old 2d table , Mode 0 : [NTSC]
{
	/* TABLE 0 */
	{
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000020,

		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000000,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000077,
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x0000005a,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f030, // jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		_TBL_END
	},
	/* TABLE 1*/
	{
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000020,

		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000000,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000077,
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x0000005a,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f030, // jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		_TBL_END
	},
};

unsigned int VPQ_2D_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] old 2d table ,  Mode 2 : [PAL]
{
	/* TABLE 0 */
	{
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000000,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000077,
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04053222, //20120206 nick187
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_Dummy_1_reg, 					0x00000001, // reg_ycsep_round_sel = 1 to solve diagonal-line-noise (since Sirius)
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000000,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000077,
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04053222, //20120206 nick187
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_Dummy_1_reg, 					0x00000001, // reg_ycsep_round_sel = 1 to solve diagonal-line-noise (since Sirius)
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		_TBL_END
	},
};

unsigned int VPQ_2D_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] [NTSC443]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,   // new 2D setting(from atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,   // new 2D setting(from atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] [PALM]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,


		//--- Post process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,


		//--- Post process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] [NTSC50]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x644, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] [PALN]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000774,              //20121015  rock_rau    mantis: 0026026 //0x649, //20120816 rock_rau
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [CVBS] [PAL60]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000443, //0x43, //20120530 nick187 (since Pacific')
		VDPQ_BPF_BW_SEL_C_reg,				0x00000660, //0x60, //20120530 nick187 (since Pacific')

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000443, //0x43, //20120530 nick187 (since Pacific')
		VDPQ_BPF_BW_SEL_C_reg,				0x00000660, //0x60, //20120530 nick187 (since Pacific')

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET10[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	//20121015	rock_rau	mantis: 0026026	//0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000043,
		VDPQ_CADAP_ZC_TH_reg,				0x00000032,
		VDPQ_CADAP_ZC_TH2_reg,				0x000000fa,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x00000077,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x000000f0,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x000000db,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000024,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	//20121015	rock_rau	mantis: 0026026	//0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000043,
		VDPQ_CADAP_ZC_TH_reg,				0x00000032,
		VDPQ_CADAP_ZC_TH2_reg,				0x000000fa,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x00000077,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x000000f0,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x000000db,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000024,
		_TBL_END
	},
};

unsigned int VPQ_2D_SET11[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PAL_M]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET12[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC_50]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET13[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PAL_N]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

	    _TBL_END
	},
};

unsigned int VPQ_2D_SET14[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC443]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,   // new 2D setting(from atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,   // new 2D setting(from atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000744,  //20121015  rock_rau    mantis: 0026026 //0x888, //20120816 rock_rau
	    VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000003,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET15[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PAL_60]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000660, //0x60, //20120530 nick187 (since Pacific')

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
	    VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
	    VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
	    VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
	    VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
	    VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
	    VDPQ_BW_DETECTION_reg,				0x00000010,
	    VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
	    VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
	    VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
	    VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
	    VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
	    VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
	    VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
	    VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
	    VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
	    VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
	    VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
	    VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
	    VDPQ_BPF_BW_SEL_C_reg,				0x00000660, //0x60, //20120530 nick187 (since Pacific')

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
	    _TBL_END
	},
};

unsigned int VPQ_2D_SET16[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PAL]
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	//20121015	rock_rau	mantis: 0026026	//0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,	 //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000023,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000027,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	//20121015	rock_rau	mantis: 0026026	//0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,	 //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000744,	//20121015	rock_rau	mantis: 0026026	//0x888, //20120816 rock_rau
		VDPQ_ADAP_BPF_Y_TH2_reg,			0x00000013,

		//--- Post Process
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000023,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000027,
		_TBL_END
	},
};


/*======================================================================*/
/*============================== 3D Table ==============================*/
/*======================================================================*/
unsigned int VPQ_3DDMA_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [NTSC][NO SIGNAL]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		//VDPQ_DMA_CTRL4_reg,			0x0000817D, //sync from tv010 rtkand
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		//VDPQ_DMA_CTRL4_reg,			0x0000817D, //sync from tv010 rtkand
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [NTSC443]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL_M]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		_TBL_END
	}
};

unsigned int VPQ_3DDMA_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL_I]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014C,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026D,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014C,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026D,
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [SECAM]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL60]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int  VPQ_3DDMA_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PALN]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014B,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026E,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014B,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026E,
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [NTSC50]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int  VPQ_3DDMA_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC][NO SIGNAL]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET10[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PALM]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x0000000F, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000104, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x00000114,
		VDPQ_DMA_VACTIVE_END2_reg,		0x00000208,
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET11[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PALI]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014B,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026E,
		_TBL_END
	},
	/* TABLE 1 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014B,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026E,
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET12[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC443]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};


unsigned int VPQ_3DDMA_SET13[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC50]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET14[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PAL60]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET15[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [SECAM]
{
	/* TABLE 0 */
	{
		_TBL_END
	},
	/* TABLE 1 */
	{
		_TBL_END
	},
};

unsigned int VPQ_3DDMA_SET16[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PALN]
{
	/* TABLE 0 */
	{
		VDPQ_DMA_VACTIVE_ST1_reg,		0x00000013, // grid_st = st + d'16
		VDPQ_DMA_VACTIVE_END1_reg,		0x00000134, // grid_end = end - d'16
		VDPQ_DMA_VACTIVE_ST2_reg,		0x0000014B,
		VDPQ_DMA_VACTIVE_END2_reg,		0x0000026E,
		_TBL_END
	},
	/* TABLE 1 */
};

unsigned int VPQ_3D_SET1[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [NTSC][NO SIGNAL] sync 2D table finish
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius
		VDTOP_LDPAUSE_CTRL_reg,				0x00000044,   //rock sync 2648  20120814

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_H2V_CORING_THR_reg,			0x00020251, // for LG menu dot crawl while moving selection 2.Tone Reproduction -> 3. Image Noise
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0140c30a, // sync with video fw reset value
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b, // sync with video fw reset value
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0, // sync with video fw reset value
		VDPQ_yc2d_postlp_flat_2_reg,		0x140f0e0a, // #107 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_3_reg,		0x00031a17, // #107 2D post lpf to reduce 2D dot crawl
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0a19a3a0, // #107 to distinguish the LG Logo and scrolling text to apply different y bpf
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000064,	//4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f,	// willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000550,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000550,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000108,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011a0c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f101400,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x08191407,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f505a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa006,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_YC_Post2DBPF_ThBase_reg,		0x0000000f,

		// --- YC 3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x00000000,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x000a1108, // global_diff_tolerance=1
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144, // F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000201, // DC_level_change_th_multiple=2, DC_level_change_th_base=1
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x000415A0, // sghf_global_diff_small_th=80,sghf_inter_diff_th=25 for VB_DancingWomen
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00A50A08,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x0000040a,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x090a0c0c,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x08080808,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x03050607, // diff_th_multiple_0=0, diff_th_multiple_10=0, for VB_EnglishWord_pan
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x17191919, // diff_th_base_200=30 // diff_th_base_160=30 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x15161616, // diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x0a0f1112, // diff_th_base_0=15
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x19214002, // hv_offset=25 for Videobook TOSHIBA#1 CH#2, hv_offset=5 for TG-45 under TV
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x3c10051e, // diff_th_lower_bound=16 // 2D_comp_3D_offset=5 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x0005b081, // still_gray_hifreq_th=91(not big enough), still_gray_hifreq_low_border=8
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000814, // hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0a0f1114, // default setting
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x000a000a, // default setting
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00019147, // moving_vline_ver_DC_level_fierce_change_th=25, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_SMD_EN_reg,							0x0000030d, // enable SMD and enable 02, 04 mv, 20150818 willy
		VDPQ_YC_3D_F4_SMD_TH1_reg,							0x1e050a0a, // adjust default SMD vertical threshold, 20151008
		VDPQ_YC_3D_F4_SMD_TH2_reg,							0x00003228, // adjust default SMD vertical threshold, 20151008
		VDPQ_YC_3D_F4_Pair_SMD_TH1_reg,						0x01000523,
		VDPQ_YC_3D_F4_Still_Vector_2_reg,					0x0000000f, // sync with video fw reset value
		VDPQ_DIRECTIONAL_3D_reg,							0x00000001, // enable directional 3D
		VDPQ_ALPHA_TEMPORAL_SMOOTH_reg,						0x800ff862, // enable temporal smooth for avoid 2D/3D alpha jumping
		VDPQ_NS_GATE_reg,									0x0000df1a, // noise status measure start/end position
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x40c5060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			    0x0000003f,	// VD DCTI to enhance color bar transition, move here?
		VDPQ_CADAP_ENABLE_CTRL2_reg,		    0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			    0x00000013,
		VDPQ_CADAP_ZC_TH_reg,				    0x000000c6,
		VDPQ_CADAP_ZC_TH2_reg,				    0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	    0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	    0x00000051,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		    0x000000ff,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			    0x00000050,

		VDPQ_YC_BW_CTRL_reg,				    0x00000100,
		VDPQ_DE_XC_CTRL_reg,				    0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,		    0x0000001b,
		VDPQ_yc2d_postpk2_adap1_reg,		    0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,		    0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,		    0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,			    0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,		    0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,			    0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,			    0x51911158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg, 0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg, 0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					0x01408780,
		VDPQ_XNR_CTRL_reg,						0x000000c1,
		VDPQ_XNR_THR_reg,						0x0000005c,
		VDPQ_XNR_IDX_THR_reg,					0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	0x0000e086,

		VDPQ_DCTI_FILTER_EN_reg,			0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,		0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,		0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,		0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,		0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,		0x000000c2,

		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius
		VDTOP_LDPAUSE_CTRL_reg,				0x00000044,   //rock sync 2648  20120814

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_H2V_CORING_THR_reg,			0x00020251, // for LG menu dot crawl while moving selection 2.Tone Reproduction -> 3. Image Noise
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0140c30a, // sync with video fw reset value
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b, // sync with video fw reset value
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // sync with video fw reset value
		VDPQ_yc2d_postlp_flat_2_reg,		0x140f0e0a, // #107 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_3_reg,		0x00031a17, // #107 2D post lpf to reduce 2D dot crawl
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x3c19a3a0, // #107 to distinguish the LG Logo and scrolling text to apply different y bpf
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,	//4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f,	// willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000550,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000550,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000108,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011a0c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f101400,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x08191407,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f505a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa006,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_YC_Post2DBPF_ThBase_reg,		0x0000000f,

		// --- YC 3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x000a1108, // global_diff_tolerance=1
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144, // F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000201, // DC_level_change_th_multiple=2, DC_level_change_th_base=1
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x000415A0, // sghf_global_diff_small_th=80,sghf_inter_diff_th=25 for VB_DancingWomen
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00A50A08,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05, // diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x00000606, // diff_th_multiple_0=0, diff_th_multiple_10=0, for VB_EnglishWord_pan
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x141E1414, // diff_th_base_200=30 // diff_th_base_160=30 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414, // diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x0F0F0F0F, // diff_th_base_0=15
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x19214002, // hv_offset=25 for Videobook TOSHIBA#1 CH#2, hv_offset=5 for TG-45 under TV
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x3c10051e, // diff_th_lower_bound=16 // 2D_comp_3D_offset=5 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x0005b081, // still_gray_hifreq_th=91(not big enough), still_gray_hifreq_low_border=8
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000814, // hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x00000000, // default setting
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000000, // default setting
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00019057, // moving_vline_ver_DC_level_fierce_change_th=25, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_SMD_EN_reg,							0x0000030d, // enable SMD and enable 02, 04 mv, 20150818 willy
		VDPQ_YC_3D_F4_SMD_TH1_reg,							0x1e1e0a0a, // adjust default SMD vertical threshold, 20151008
		VDPQ_YC_3D_F4_SMD_TH2_reg,							0x00003232, // adjust default SMD vertical threshold, 20151008
		VDPQ_YC_3D_F4_Still_Vector_2_reg,					0x0000000f, // sync with video fw reset value
		VDPQ_DIRECTIONAL_3D_reg,							0x00000001, // enable directional 3D
		VDPQ_ALPHA_TEMPORAL_SMOOTH_reg,						0x800ff894, // enable temporal smooth for avoid 2D/3D alpha jumping
		VDPQ_NS_GATE_reg,									0x0000df1a, // noise status measure start/end position
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x40c5060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			    0x0000003f,	// VD DCTI to enhance color bar transition, move here?
		VDPQ_CADAP_ENABLE_CTRL2_reg,		    0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			    0x00000013,
		VDPQ_CADAP_ZC_TH_reg,				    0x000000c6,
		VDPQ_CADAP_ZC_TH2_reg,				    0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	    0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	    0x00000051,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		    0x000000ff,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			    0x00000050,

		VDPQ_YC_BW_CTRL_reg,				    0x00000100,
		VDPQ_DE_XC_CTRL_reg,				    0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,		    0x0000001b,
		VDPQ_yc2d_postpk2_adap1_reg,		    0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,		    0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,		    0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,			    0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,		    0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,			    0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,			    0x51911158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg, 0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg, 0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					0x01408780,
		VDPQ_XNR_CTRL_reg,						0x000000c1,
		VDPQ_XNR_THR_reg,						0x0000005c,
		VDPQ_XNR_IDX_THR_reg,					0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	0x0000e086,

		VDPQ_DCTI_FILTER_EN_reg,			0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,		0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,		0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,		0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,		0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,		0x000000c2,

		_TBL_END
	},
};

unsigned int VPQ_3D_SET2[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [NTSC443] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000000,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015	rock_rau	mantis: 0026026 //0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b8,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000010,	  // new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,	   //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011a0c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20000,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f030,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,					0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,				0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,					0x00000026,
		VDPQ_CADAP_ZC_TH_reg,						0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,						0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,			0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,			0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,				0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,					0x00000033,

		VDPQ_YC_BW_CTRL_reg,						0x00000009,
		VDPQ_DE_XC_CTRL_reg,						0x00000023,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000000,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015	rock_rau	mantis: 0026026 //0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b8,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000010,	  // new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,	   //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011a0c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20000,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f030,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,					0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,				0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,					0x00000026,
		VDPQ_CADAP_ZC_TH_reg,						0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,						0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,			0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,			0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,				0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,					0x00000033,

		VDPQ_YC_BW_CTRL_reg,						0x00000009,
		VDPQ_DE_XC_CTRL_reg,						0x00000023,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET3[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL_M] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,		//rock sync 2648	20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x0000055a,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00000000,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x191010F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x07010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x8020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg, 				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000320F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=50
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x14000000,// hifreq_offset_120=20
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000D14,// hifreq_offset_100=20,hifreq_offset_80=13
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x00000026,
		VDPQ_CADAP_ZC_TH_reg,					0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000033,

		VDPQ_YC_BW_CTRL_reg,					0x00000000,
		VDPQ_DE_XC_CTRL_reg,					0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,			0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,			0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,			0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,			0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,				0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,			0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,				0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,				0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,	0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,	0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					0x01408780,
		VDPQ_XNR_CTRL_reg,						0x000000c0,
		VDPQ_XNR_THR_reg,						0x00000059,
		VDPQ_XNR_IDX_THR_reg,					0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,			0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,				0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,			0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,			0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,			0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,		//rock sync 2648	20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x0000055a,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x191010F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x07010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x8020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg, 				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000320F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=50
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x14000000,// hifreq_offset_120=20
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000D14,// hifreq_offset_100=20,hifreq_offset_80=13
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x00000026,
		VDPQ_CADAP_ZC_TH_reg,					0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000033,

		VDPQ_YC_BW_CTRL_reg,					0x00000000,
		VDPQ_DE_XC_CTRL_reg,					0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,			0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,			0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,			0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,			0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,				0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,			0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,				0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,				0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,	0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,	0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					0x01408780,
		VDPQ_XNR_CTRL_reg,						0x000000c0,
		VDPQ_XNR_THR_reg,						0x00000059,
		VDPQ_XNR_IDX_THR_reg,					0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,			0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,				0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,			0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,			0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,			0x000000c2,
		_TBL_END
	},
};


unsigned int VPQ_3D_SET4[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL_I] sync 2D table finish
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044, //rock sync 2648  20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0a195151, // 2D bpf selection thershold, LG#40 Flag
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000002, // LG#107 horizontal scrolling text stick issue, also #2 the complex region becomes better
		VDPQ_H2V_CORING_THR_reg,			0x00020231, // LG#107 for vertical scrolling text clearity
		VDPQ_yc2d_postlp_flat_1_reg,		0x08070504, // 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_2_reg,		0x0805040a, // 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_3_reg,		0x02000c0a, // 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_4_reg,		0x00060403, // 2D post lpf to reduce 2D dot crawl
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000007, // LG#46, right arm dot crawl at colorful background, 20151110, willy
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053102, // LG#46, change LUT for background dot crawl, 20151110, willy
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000550,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000400,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000108,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000001,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// ---YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x19108181, // LG#147~150, parerr_accu_tolerance for colorful characters cannot get into 3D, 20151110, willy
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x07010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x8020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x14050f1e, // avoid 2D 3D jump, global diff threshold upper/lower bound, all tend to 2D, 20151111, willy
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000320F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=50
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x020a1108, // avoid 2D 3D jump, global diff tolerance, 20151111, willy
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x14000000,// hifreq_offset_120=20
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000D14,// hifreq_offset_100=20,hifreq_offset_80=13
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_SMD_EN_reg,							0x00000000, // disable SMD to avoid mistake when switching from NTSC to PAL, 20151111 willy
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0f2140a2, // pal_error_offset = 5 for LG#123, 20151114, willy
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_ALPHA_TEMPORAL_SMOOTH_reg,						0x800ff894, // enable temporal smooth for avoid 2D/3D alpha jumping
		VDPQ_NS_GATE_reg,									0x0000df1a, // noise status measure start/end position
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x41250e12,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x0000001f,
		VDPQ_CADAP_ZC_TH_reg,					0x000000d6,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x00000015,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000051,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x000000af,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000060,

		VDPQ_YC_BW_CTRL_reg,					0x00000149,
		VDPQ_DE_XC_CTRL_reg,					0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,			0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,			0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,			0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,			0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,				0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,			0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,				0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,				0x51911158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg, 0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg, 0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					0x01408780,
		VDPQ_XNR_CTRL_reg,						0x000000c1,
		VDPQ_XNR_THR_reg,						0x0000005c,
		VDPQ_XNR_IDX_THR_reg,					0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	0x0000e086,
		VDPQ_YC_Post2DBPF_ThBase_reg,			0x00000a0a,

		VDPQ_DCTI_FILTER_EN_reg,				0x00000001,
		VDPQ_DCTI_FILTER_COEF_B1_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,			0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,			0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,			0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044, //rock sync 2648  20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0a195151, // 2D bpf selection thershold, LG#40 Flag
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000002, // LG#107 horizontal scrolling text stick issue, also #2 the complex region becomes better
		VDPQ_H2V_CORING_THR_reg,			0x00020231, // LG#107 for vertical scrolling text clearity
		VDPQ_yc2d_postlp_flat_1_reg,		0x08070504, // 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_2_reg,		0x0805040a, // 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_3_reg,		0x02000c0a, // 2D post lpf to reduce 2D dot crawl
		VDPQ_yc2d_postlp_flat_4_reg,		0x00060403, // 2D post lpf to reduce 2D dot crawl
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000007, // LG#46, right arm dot crawl at colorful background, 20151110, willy
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053102, // LG#46, change LUT for background dot crawl, 20151110, willy
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000550,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000400,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000108,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000001,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// ---YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x19108181, // LG#147~150, parerr_accu_tolerance for colorful characters cannot get into 3D, 20151110, willy
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x07010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x8020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x14050f1e, // avoid 2D 3D jump, global diff threshold upper/lower bound, all tend to 2D, 20151111, willy
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000320F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=50
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x020a1108, // avoid 2D 3D jump, global diff tolerance, 20151111, willy
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x14000000,// hifreq_offset_120=20
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000D14,// hifreq_offset_100=20,hifreq_offset_80=13
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_SMD_EN_reg,							0x00000000, // disable SMD to avoid mistake when switching from NTSC to PAL, 20151111 willy
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0f2140a2, // pal_error_offset = 5 for LG#123, 20151114, willy
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_ALPHA_TEMPORAL_SMOOTH_reg,						0x800ff894, // enable temporal smooth for avoid 2D/3D alpha jumping
		VDPQ_NS_GATE_reg,									0x0000df1a, // noise status measure start/end position
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x41250e12,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x0000001f,
		VDPQ_CADAP_ZC_TH_reg,					0x000000d6,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x00000015,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000051,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x000000af,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000060,

		VDPQ_YC_BW_CTRL_reg,					0x00000149,
		VDPQ_DE_XC_CTRL_reg,					0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,			0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,			0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,			0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,			0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,				0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,			0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,				0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,				0x51911158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg, 0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg, 0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					0x01408780,
		VDPQ_XNR_CTRL_reg,						0x000000c1,
		VDPQ_XNR_THR_reg,						0x0000005c,
		VDPQ_XNR_IDX_THR_reg,					0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	0x0000e086,
		VDPQ_YC_Post2DBPF_ThBase_reg,			0x00000a0a,

		VDPQ_DCTI_FILTER_EN_reg,				0x00000001,
		VDPQ_DCTI_FILTER_COEF_B1_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,			0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,			0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,			0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,			0x000000c2,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET5[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [SECAM] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,					0x00000044,		//rock sync 2648	20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x0000055a,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x0000190c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20003,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x0000000a,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Still_Vector_1_reg,	0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,		0x0050f140,

		// --- Post Process ---
		VDPQ_POSTP_SECAM_FIX_CTRL_reg,				0xc005100c,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg,			0x8f010f05,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg,			0x00000405,

		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg,	0x84005002,
		VDPQ_SPNR_CP_Ctrl_reg,					0x06000001,
		VDPQ_SPNR_Spatial_Th_reg,				0x00140a05,
		VDPQ_SPNR_Spatial_Weight_reg,			0x0f000000,
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x00000063,
		VDPQ_CADAP_ZC_TH_reg,					0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000089,

		VDPQ_YC_BW_CTRL_reg,						0x00000000,
		VDPQ_DE_XC_CTRL_reg,						0x00000003,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,					0x00000044,		//rock sync 2648	20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x0000055a,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x0000190c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20003,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x0000000a,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Still_Vector_1_reg,	0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,		0x0050f140,

		// --- Post Process ---
		VDPQ_POSTP_SECAM_FIX_CTRL_reg,				0xc005100c,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg,			0x8f010f05,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg,			0x00000405,

		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_2_reg,	0x84005002,
		VDPQ_SPNR_CP_Ctrl_reg,					0x06000001,
		VDPQ_SPNR_Spatial_Th_reg,				0x00140a05,
		VDPQ_SPNR_Spatial_Weight_reg,			0x0f000000,
		VDPQ_CADAP_ENABLE_CTRL_reg,				0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,			0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,				0x00000063,
		VDPQ_CADAP_ZC_TH_reg,					0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,					0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,		0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,		0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,			0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,				0x00000089,

		VDPQ_YC_BW_CTRL_reg,						0x00000000,
		VDPQ_DE_XC_CTRL_reg,						0x00000003,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET6[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL60] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_VIDEO_CONTROL0_reg,		0x0000000e,
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,		//rock sync 2648	20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000, // 2D adap

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000555,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20003,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Still_Vector_1_reg,	0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,		0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

		VDPQ_YC_BW_CTRL_reg,					   0x00000109,
		VDPQ_DE_XC_CTRL_reg,					   0x00000023,
		VDPQ_yc2d_postpk2_ctrl1_reg,			   0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,			   0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,			   0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,			   0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,				   0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,			   0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,				   0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,				   0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,	   0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,	   0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	   0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			   0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					   0x01408780,
		VDPQ_XNR_CTRL_reg,						   0x000000c0,
		VDPQ_XNR_THR_reg,						   0x00000059,
		VDPQ_XNR_IDX_THR_reg,					   0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				   0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	   0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	   0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,			   0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,				   0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,			   0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,			   0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,			   0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,			   0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,			   0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_VIDEO_CONTROL0_reg,		0x0000000e,
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,		//rock sync 2648	20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000, // 2D adap

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000555,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20003,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Still_Vector_1_reg,	0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,		0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

		VDPQ_YC_BW_CTRL_reg,					   0x00000109,
		VDPQ_DE_XC_CTRL_reg,					   0x00000023,
		VDPQ_yc2d_postpk2_ctrl1_reg,			   0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,			   0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,			   0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,			   0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,				   0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,			   0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,				   0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,				   0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,	   0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,	   0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,	   0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,			   0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,					   0x01408780,
		VDPQ_XNR_CTRL_reg,						   0x000000c0,
		VDPQ_XNR_THR_reg,						   0x00000059,
		VDPQ_XNR_IDX_THR_reg,					   0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,				   0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,	   0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,	   0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,			   0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,				   0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,			   0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,			   0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,			   0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,			   0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,			   0x000000c2,
		_TBL_END
	},
};

unsigned int  VPQ_3D_SET7[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [PAL_N] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,				0x00000001,
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,		0x0000008a,

		// --- YC 1D/2D ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x0000055a,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2028b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x191010F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x07010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x8020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000320F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=50
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x14000000,// hifreq_offset_120=20
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000D14,// hifreq_offset_100=20,hifreq_offset_80=13
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		VDPQ_YC_BW_CTRL_reg,						0x00000008,
		VDPQ_DE_XC_CTRL_reg,						0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,				0x00000001,
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,		0x0000008a,

		// --- YC 1D/2D ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BPF_BW_SEL_Y_reg,				0x0000055a,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x00000008,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2028b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x191010F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x07010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x8020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000320F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=50
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x14000000,// hifreq_offset_120=20
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000D14,// hifreq_offset_100=20,hifreq_offset_80=13
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		VDPQ_YC_BW_CTRL_reg,						0x00000008,
		VDPQ_DE_XC_CTRL_reg,						0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14301,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x22000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET8[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [AV] [NTSC50] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,			0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,					0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,			0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,					0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		_TBL_END
	},
};

unsigned int  VPQ_3D_SET9[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC][NO SIGNAL] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,	//rock sync 2648	20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000030,	//0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	//20121015	rock_rau	mantis: 0026026	//0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x0000010b,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011a0c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f101400,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x08191407,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f505a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa006,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x050A1108,// global_diff_tolerance=5 to stable noise, 20160329 jimmy
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000201,// DC_level_change_th_multiple=2, DC_level_change_th_base=1
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x000415A0,// sghf_inter_diff_th=70, sghf_global_diff_small_th=80 // 00019500:sghf_inter_diff_th=25 for VB_DancingWomen
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x00000606,// diff_th_multiple_0=0, diff_th_multiple_10=0,  for VB_EnglishWord_pan
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x141E1414,// diff_th_base_200=30 // diff_th_base_160=30 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x0F0F0F0F,// diff_th_base_0=15
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x19214002,// hv_offset=25 for Videobook TOSHIBA#1 CH#2, hv_offset=5 for TG-45 under TV
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x2610051E,// diff_th_lower_bound=16 // 2D_comp_3D_offset=5 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x0005B081,// still_gray_hifreq_th=91(not big enough), still_gray_hifreq_low_border=8
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014,// hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x1C1E0000,// hifreq_offset_30=30, hifreq_offset_20=28
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000006,// hifreq_offset_10=6
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00019057,// moving_vline_ver_DC_level_fierce_change_th=25, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_SPNR_Spatial_Weight_reg,		0x05930000, // adjust the SPNR setting for ATV ring, 20160121 willy
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000032,
		VDPQ_CADAP_ZC_TH2_reg,				0x000000fa,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x00000077,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x000000f0,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x000000db,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000046,

		VDPQ_YC_BW_CTRL_reg,						0x00000000,
		VDPQ_DE_XC_CTRL_reg,						0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14315,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x02000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c1,
		VDPQ_XNR_THR_reg,							0x0000005c,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x0000e086,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x00002828,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000001,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000000ec,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x00000627,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000000ec,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x00000101,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x0000005f,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,	//rock sync 2648	20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000030,	//0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0,	//20121015	rock_rau	mantis: 0026026	//0x0019A2A0,		//20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,	// new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x0027814f, // willy, adjust the threshold for LG #107 character dot crawl
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x0000010b,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011a0c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f101400,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x08191407,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f505a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa006,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x050A1108,// global_diff_tolerance=5 to stable noise, 20160329 jimmy
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000201,// DC_level_change_th_multiple=2, DC_level_change_th_base=1
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x000415A0,// sghf_inter_diff_th=70, sghf_global_diff_small_th=80 // 00019500:sghf_inter_diff_th=25 for VB_DancingWomen
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x00000606,// diff_th_multiple_0=0, diff_th_multiple_10=0,  for VB_EnglishWord_pan
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x141E1414,// diff_th_base_200=30 // diff_th_base_160=30 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x0F0F0F0F,// diff_th_base_0=15
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x19214002,// hv_offset=25 for Videobook TOSHIBA#1 CH#2, hv_offset=5 for TG-45 under TV
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x2610051E,// diff_th_lower_bound=16 // 2D_comp_3D_offset=5 for Videobook TOSHIBA#1 CH#2
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x0005B081,// still_gray_hifreq_th=91(not big enough), still_gray_hifreq_low_border=8
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014,// hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x1C1E0000,// hifreq_offset_30=30, hifreq_offset_20=28
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000006,// hifreq_offset_10=6
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00019057,// moving_vline_ver_DC_level_fierce_change_th=25, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_SPNR_Spatial_Weight_reg,		0x05930000, // adjust the SPNR setting for ATV ring, 20160121 willy
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000032,
		VDPQ_CADAP_ZC_TH2_reg,				0x000000fa,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x00000077,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x000000f0,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x000000db,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000046,

		VDPQ_YC_BW_CTRL_reg,						0x00000000,
		VDPQ_DE_XC_CTRL_reg,						0x00000033,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14315,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x02000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c1,
		VDPQ_XNR_THR_reg,							0x0000005c,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x0000e086,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x00002828,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000001,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000000ec,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x00000627,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000000ec,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x00000101,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x0000005f,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET10[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PALM] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,   //rock sync 2648  20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,

		// --- YC 1D/2D ---
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2000b,
		VDPQ_YC_BW_CTRL_reg,				0x00000008, // default enable chroma vlpf to avoid color trembling at color bar
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e1, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_C_reg,				0x00000555, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,

		// --- YC3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,//0xca,//0x8a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x321E40F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x0E010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x0020a20a,// F4F0_still_en=0, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000460F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=70
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014,// hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044,   //rock sync 2648  20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,

		// --- YC 1D/2D ---
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2000b,
		VDPQ_YC_BW_CTRL_reg,				0x00000008, // default enable chroma vlpf to avoid color trembling at color bar
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e1, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_C_reg,				0x00000555, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,

		// --- YC3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a,//0xca,//0x8a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x321E40F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x0E010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x0020a20a,// F4F0_still_en=0, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000460F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=70
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014,// hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x00000005,// global_diff_th_hifreq_offset_10=5
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

		_TBL_END
	},
};

unsigned int VPQ_3D_SET11[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PALI] sync 2D table finish
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044, // rock sync 2648    20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053102,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000002,
		VDPQ_H2V_CORING_THR_reg,			0x00020231,
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019a2a3, // reduce the narrow BPF region to avoid too much dot crawl
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000444,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x0000010b,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x321E40F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x0E010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x0020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000460F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=70
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014,// hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x0000000f,// global_diff_th_hifreq_offset_10=15
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_SMD_EN_reg,							0x0000000d, // enable SMD to keep the slow motion clear in ATV, 20160121 willy
		VDPQ_YC_3D_F4_SMD_TH1_reg,							0x0008050a,
		VDPQ_YC_3D_F4_SMD_TH2_reg,							0x00000a32,
		VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg,					0x140db853, // adjust the spatial alpha blending threshold to make slow motion go into 3D, 20160124, willy
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a, // 0xca,//0x8a,
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_SPNR_CP_Ctrl_reg,				0x055b0001, // adjust the SPNR setting for ATV ring, 20160121 willy
		VDPQ_SPNR_Spatial_Weight_reg,		0x03930100, // adjust the SPNR setting for ATV ring, 20160121 willy

		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000003,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000053,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000059,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000057,

		VDPQ_YC_BW_CTRL_reg,						0x00000149,
		VDPQ_DE_XC_CTRL_reg,						0x00000038,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14315,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51911158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x023a0200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c1,
		VDPQ_XNR_THR_reg,							0x0000005c,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x0000e086,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044, // rock sync 2648    20120814
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,

		// --- YC 1D/2D ---
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08		Rock_rau	20121009	mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,	// new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,	rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053102,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000002,
		VDPQ_H2V_CORING_THR_reg,			0x00020231,
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019a2a3, // reduce the narrow BPF region to avoid too much dot crawl
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000444,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x0000010b,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325051,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010f1c,
		VDPQ_VMC_CTRL_reg,					0x19114145,
		VDPQ_DIAMC_CTRL_reg,				0x052230a7,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a2a28b,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100a00,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x0a191404,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f4b5a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0xa3661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa00a,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,						0x010A1108,// global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,						0x000000f1,//hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x321E40F1,// palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x0E010505,// diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x0020a20a,// F4F0_still_en=1, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144,//F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414,// DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500,// sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05,//diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606,// diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E,// diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414,// diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F,// diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002,// hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E,// diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000460F1,// still_gray_hifreq_low_border=35, still_gray_hifreq_th=70
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014,// hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00,// global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x0000000f,// global_diff_th_hifreq_offset_10=15
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057,// moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1
		VDPQ_YC_3D_F4_SMD_EN_reg,							0x0000000d, // enable SMD to keep the slow motion clear in ATV, 20160121 willy
		VDPQ_YC_3D_F4_SMD_TH1_reg,							0x0008050a,
		VDPQ_YC_3D_F4_SMD_TH2_reg,							0x00000a32,
		VDPQ_YC_3D_F4_Spa_Cnt_CVBS_Amp_reg,					0x140db853, // adjust the spatial alpha blending threshold to make slow motion go into 3D, 20160124, willy
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a, // 0xca,//0x8a,
		VDPQ_YC_3D_F4_Still_Vector_1_reg,					0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,						0x0050f140,

		// --- Post Process ---
		VDPQ_SPNR_CP_Ctrl_reg,				0x055b0001, // adjust the SPNR setting for ATV ring, 20160121 willy
		VDPQ_SPNR_Spatial_Weight_reg,		0x03930100, // adjust the SPNR setting for ATV ring, 20160121 willy

		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003f,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000003,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000053,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000059,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000057,

		VDPQ_YC_BW_CTRL_reg,						0x00000149,
		VDPQ_DE_XC_CTRL_reg,						0x00000038,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14315,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51911158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg,		0x33333333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg,		0x03333333,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x023a0200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c1,
		VDPQ_XNR_THR_reg,							0x0000005c,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x0000e086,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET12[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC443] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,   // new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000030, //0x20 ->0x30 JZ Sirius

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000000,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x000000b0,
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000000,   // new 2D setting(from atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x04000112, //20120606 nick187 for pacific'-noDDR //0x04000222,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000002,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000004,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x00000002,
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00011A0C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0xf3f7f031, //jimmy
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x002782ff,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00001419,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,

		_TBL_END
	},
};


unsigned int VPQ_3D_SET13[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [NTSC50] finsih sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,			0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,					0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, // 20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035, // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, // 20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003, // 4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0, // 0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b, // for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, // lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,			0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,					0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,		0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000000,

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, // 20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035, // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, // 20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003, // 4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0, // 0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b, // for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, // lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003c,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000063,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000050,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000039,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000089,

		_TBL_END
	},
};

unsigned int VPQ_3D_SET14[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [PAL60] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV
		VDTOP_VIDEO_CONTROL0_reg,			0x0000000e,
		VDTOP_LDPAUSE_CTRL_reg,				0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000, // 2D adap

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,		0x00000010, // ives for TV
		VDTOP_VIDEO_CONTROL0_reg,			0x0000000e,
		VDTOP_LDPAUSE_CTRL_reg,				0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,			0x00000002,
		VDPQ_YC_SEP_MODE_CTRL_reg,			0x00000000, // 2D adap

		// --- YC 1D/2D ---
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0, //lydia
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change

		// --- YC3D F4 ---
		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
};

unsigned int VPQ_3D_SET15[PRJ_NUM_MAX][VPQ_SETTING_MAX]=
// [TV] [SECAM] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,                           0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,                          0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,                        0x00000000,

		// --- YC 1D/2D ---
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x0000000b,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x0000190c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20003,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x0000000a,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Still_Vector_1_reg,			0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,				0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,					0x0000003d,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,				0x00000005,
		VDPQ_CADAP_GAIN_CTRL_reg,					0x00000053,
		VDPQ_CADAP_ZC_TH_reg,						0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,						0x00000075,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,			0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,			0x00000004,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,				0x00000047,
		VDPQ_CADAP_LUT_GAIN_TH_reg,					0x00000044,

		VDPQ_POSTP_SECAM_FIX_CTRL_reg,				0xc004140c,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg,			0xa6030a02,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg,			0x00000105,

		VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg,		0x00123333,
		VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg,		0x00000000,

		VDPQ_YC_BW_CTRL_reg,						0x00000001,
		VDPQ_DE_XC_CTRL_reg,						0x00000003,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14315,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg, 	0x00123333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg, 	0x00000000,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x02000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END

	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_LDPAUSE_CTRL_reg,                           0x00000044,       //rock sync 2648    20120814

		// --- Global control ---
		VDPQ_YC_SEP_CONTROL_reg,                          0x00000003,
		VDPQ_YC_SEP_MODE_CTRL_reg,                        0x00000000,

		// --- YC 1D/2D ---
		VDPQ_BW_DETECTION_reg,				0x00000060,
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555,
		VDPQ_BPF_BW_SEL_C_reg,				0x00000551,
		VDPQ_CDIFF_ADAP_BPF_TH1_reg,		0x00081e00,
		VDPQ_BLEND_1D_THR_reg,				0x0000000b,
		VDPQ_yc2d_postlp_ctrl_reg,			0x00000000,
		VDPQ_BPF_VEDGE_CTRL1_reg,			0x00325050,
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x0000190c,
		VDPQ_VMC_CTRL_reg,					0x19114144,
		VDPQ_DIAMC_CTRL_reg,				0x052230a6,
		VDPQ_YC_Post2DBPF_Ctrl_reg,			0x00a20003,
		VDPQ_YC_Post2DBPF_AdapTh_1_reg,		0x0080c30a,
		VDPQ_YC_Post2DBPF_AdapTh_2_reg,		0x0f100000,
		VDPQ_YC_Post2DBPF_AdapTh_4_reg,		0x00191400,
		VDPQ_YC_Post2DBPF_AdapTh_6_reg,		0x1e0f005a,
		VDPQ_YC_Post2DBPF_AdapTh_12_reg,	0x23661e0f,
		VDPQ_YC_Post2DBPF_AdapTh_13_reg,	0x00ffa000,
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e0,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x0000000a,

		// --- YC3D F4 ---
		VDPQ_YC_3D_F4_Still_Vector_1_reg,			0x0125060a,
		VDPQ_YC_3D_F4_NTSC_ABA_1_reg,				0x0050f140,

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,					0x0000003d,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,				0x00000005,
		VDPQ_CADAP_GAIN_CTRL_reg,					0x00000053,
		VDPQ_CADAP_ZC_TH_reg,						0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,						0x00000075,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,			0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,			0x00000004,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,				0x00000047,
		VDPQ_CADAP_LUT_GAIN_TH_reg,					0x00000044,

		VDPQ_POSTP_SECAM_FIX_CTRL_reg,				0xc004140c,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT0_reg,			0xa6030a02,
		VDPQ_POSTP_SECAM_FIX_Y_DETECT1_reg,			0x00000105,

		VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB1_reg,		0x00123333,
		VDPQ_POSTP_DLTI_TNGAIN_GAIN_TAB2_reg,		0x00000000,

		VDPQ_YC_BW_CTRL_reg,						0x00000001,
		VDPQ_DE_XC_CTRL_reg,						0x00000003,
		VDPQ_yc2d_postpk2_ctrl1_reg,				0x0000001a,
		VDPQ_yc2d_postpk2_adap1_reg,				0x001e011e,
		VDPQ_yc2d_postpk2_dnoise1_reg,				0x00ff050a,
		VDPQ_yc2d_postpk2_filter_0_reg,				0x03c1ecf6,
		VDPQ_yc2d_postpk2_gain_reg,					0x00002020,
		VDPQ_yc2d_postpk2_bound_reg,				0x00401002,
		VDPQ_POSTP_DLTI_CTRL1_reg,					0xb1c14315,
		VDPQ_POSTP_DLTI_CTRL2_reg,					0x51910158,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB1_reg, 	0x00123333,
		VDPQ_POSTP_DLTI_TNGAIN_OFFSET_TAB2_reg, 	0x00000000,
		VDPQ_POSTP_3D2DALPHA_BLEND_CTRL_1_reg,		0x02000200,
		VDPQ_POSTP_DLTI_PK_SELECT_reg,				0x00013053,
		VDPQ_NOTCH_CTRL_1_reg,						0x01408780,
		VDPQ_XNR_CTRL_reg,							0x000000c0,
		VDPQ_XNR_THR_reg,							0x00000059,
		VDPQ_XNR_IDX_THR_reg,						0x00000033,
		VDPQ_XNR_RATIO_CTRL_reg,					0x00000022,
		VDPQ_POSTP_MF_COMPENSATION_CTRL1_reg,		0x00003b3f,
		VDPQ_POSTP_MF_COMPENSATION_CTRL2_reg,		0x00019146,
		VDPQ_YC_Post2DBPF_ThBase_reg,				0x0000000f,

		VDPQ_DCTI_FILTER_EN_reg,					0x00000000,
		VDPQ_DCTI_FILTER_COEF_B1_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B2_reg,				0x000006ae,
		VDPQ_DCTI_FILTER_COEF_B3_reg,				0x000001a8,
		VDPQ_DCTI_FILTER_COEF_A2_reg,				0x000006c4,
		VDPQ_DCTI_FILTER_COEF_A3_reg,				0x000000c2,
		_TBL_END

	},
};

unsigned int VPQ_3D_SET16[PRJ_NUM_MAX][VPQ_SETTING_MAX] =
// [TV] [PALN] finish sync 2D table
{
	/* TABLE 0 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044, // rock sync 2648  20120814

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,

		// --- YC 1D/2D ---
		VDPQ_YC_BW_CTRL_reg,				0x00000008, // default enable chroma vlpf to avoid color trembling at color bar
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e1, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_C_reg,				0x00000555, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,

		// --- YC3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a, // 0xca,//0x8a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,                      0x010A1108, // global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,                        0x000000f1, // hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x321E40F1, // palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x0E010505, // diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x0020a20a, // F4F0_still_en=0, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144, // F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414, // DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500, // sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05, // diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606, // diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E, // diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414, // diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F, // diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002, // hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E, // diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000460F1, // still_gray_hifreq_low_border=35, still_gray_hifreq_th=70
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014, // hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00, // global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x0000000f, // global_diff_th_hifreq_offset_10=15
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057, // moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
	/* TABLE 1 */
	{
		// --- From VD Top ---
		VDTOP_CHROMA_DELAY_CTRL_reg,	0x00000010, // ives for TV
		VDTOP_LDPAUSE_CTRL_reg,			0x00000044, // rock sync 2648  20120814

		// --- Global control ---
		VDPQ_YC_SEP_MODE_CTRL_reg,		0x00000001,
		VDPQ_YC_SEP_CONTROL_reg,		0x00000002,

		// --- YC 1D/2D ---
		VDPQ_YC_BW_CTRL_reg,				0x00000008, // default enable chroma vlpf to avoid color trembling at color bar
		VDPQ_BYPASS_BPF_CTRL1_reg,			0x519321e1, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_C_reg,				0x00000555, // for ATV PALN color bar transition issue
		VDPQ_BPF_BW_SEL_Y_reg,				0x00000555, // set narrow bpf for channel change
		VDPQ_CDIFF_ADAP_BPF_TH2_reg,		0x0019A2A0, //20121015  rock_rau    mantis: 0026026 //0x0019A2A0,       //20120905 rock_rau mantis : 0022590
		VDPQ_ADAP_BPF_C_TH1_reg,			0x00000030, // for monoscope //0x08       Rock_rau    20121009    mantis:0025733
		VDPQ_ADAP_BPF_C_TH2_reg,			0x00000035,   // new 2D setting(since atlantic)
		VDPQ_BW_DETECTION_reg,				0x00000010,
		VDPQ_ALPHA_2D_MOD_ENABLE_reg,		0x84053002, //20120606 nick187 for pacific'-noDDR //0x84053332,
		VDPQ_H2V_Y_NOISE_THR_reg,			0x00000003,    //4
		VDPQ_H2V_NOISE_MAX_HDY_reg,			0x0000002f,
		VDPQ_H2V_NOISE_Y_ADD_DC_reg,		0x00000005,
		VDPQ_H2V_BLEND_RATIO_reg,			0x00000007,
		VDPQ_COMB_FILTER_THRESHOLD1_reg,	0x000000f0,//0x02,    rock_rau 20120822 mantis 0022590
		VDPQ_H2V_CVBS_NOISE_THR_reg,		0x0000000b,//for panasonic TV_Pal disk 20121217 ,CSFC //,0xf
		VDPQ_BPF_VEDGE_CTRL2_reg,			0x00010F1C,
		VDPQ_BYPASS_BPF_CTRL2_reg,			0x00283194,
		VDPQ_DIAMC_CVBS_AMP_TH_reg,			0x00000a19,

		// --- YC3D F4 ---
		VDPQ_YC_3DSEP_CHROMA_BPF_SEL_reg,					0x0000008a, // 0xca,//0x8a,
		VDPQ_YC_3D_F4_Ctrl_reg,								0xA3264000,
		VDPQ_YC_3D_F4_Pair_Ctrl_6_reg,                      0x010A1108, // global_diff_tolerance=1
		VDPQ_YC_3D_F4_HV_Edge_2_reg,                        0x000000f1, // hv_edge_c_diff_small_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_1_reg,					0x321E40F1, // palerr_accu_tolerance(TV=4, AV=1), palerr_hifreq_diff_large_th=15, pal_error_detect_en=1
		VDPQ_YC_3D_F4_PAL_Err_Com_2_reg,					0x0E010505, // diff_of_spd_small_th_base=7, diff_of_spd_small_th_multiple=1, massive_palmode_error_multiple_th=5, massive_palmode_error_large_th=5
		VDPQ_YC_3D_F4_PAL_Err_Com_3_reg,					0x0020a20a, // F4F0_still_en=0, palerr_massive_tolerance=2
		VDPQ_YC_3D_F4_Hifreq_Det_reg,						0x00000144, // F4_ver_Chifreq_range=1:5-point
		VDPQ_YC_3D_F4_DC_Compare_reg,						0x00000414, // DC_level_change_th_multiple=6, DC_level_change_th_base=20 for TG-45 Tropical Beach @ Y+sync level=43. BUT DC_level_change_th_multiple=4 for many scene change
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_1_reg,				0x0002D500, // sghf_inter_diff_th=45, sghf_global_diff_small_th=80
		VDPQ_YC_3D_F4_Still_Gray_HiFreq_2_reg,				0x00F50C0A,
		VDPQ_YC_3D_F4_Global_Diff_Th_Com_reg,				0x00000F05, // diff_th_multiple_5=15, diff_th_base_5=5
		VDPQ_YC_3D_F4_Pair_Th_Multiple_1_reg,				0x08090B0B,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_2_reg,				0x06070707,
		VDPQ_YC_3D_F4_Pair_Th_Multiple_3_reg,				0x06060606, // diff_th_multiple_0=6, diff_th_multiple_10=6
		VDPQ_YC_3D_F4_Pair_Th_Base_1_reg,					0x1414141E, // diff_th_base_200=30
		VDPQ_YC_3D_F4_Pair_Th_Base_2_reg,					0x0F141414, // diff_th_base_80=20, diff_th_base_100=20
		VDPQ_YC_3D_F4_Pair_Th_Base_3_reg,					0x050F0F0F, // diff_th_base_0=5(defalut)
		VDPQ_YC_3D_F4_Pair_Ctrl_1_reg,						0x0F214002, // hv_offset=15
		VDPQ_YC_3D_F4_Pair_Ctrl_4_reg,						0x26090F1E, // diff_th_lower_bound=9
		VDPQ_YC_3D_F4_Pair_Ctrl_5_reg,						0x000460F1, // still_gray_hifreq_low_border=35, still_gray_hifreq_th=70
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_1_reg,	0x00000000,
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_2_reg,	0x00000014, // hifreq_offset_100=20 for TG-45 monoscope's noise between the number 7&8  @ Y+sync level=43
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_3_reg,	0x0F0F0C00, // global_diff_th_hifreq_offset_20=15,global_diff_th_hifreq_offset_30=15,global_diff_th_hifreq_offset_40=12
		VDPQ_YC_3D_F4_Global_Diff_Th_Hifreq_Offset_4_reg,	0x0000000f, // global_diff_th_hifreq_offset_10=15
		VDPQ_YC_3D_F4_MGHF_Ctrl_1_reg,						0x00014057, // moving_vline_ver_DC_level_fierce_change_th=20, MGHF_enable=1, moving_vline_en=1, DC_level_hor_DC_check_en=1

		// --- Post Process ---
		VDPQ_CADAP_ENABLE_CTRL_reg,			0x0000003e,	// VD DCTI
		VDPQ_CADAP_ENABLE_CTRL2_reg,		0x00000007,
		VDPQ_CADAP_GAIN_CTRL_reg,			0x00000026,
		VDPQ_CADAP_ZC_TH_reg,				0x00000076,
		VDPQ_CADAP_ZC_TH2_reg,				0x00000065,
		VDPQ_CADAP_VER_UNIFORMITY_TH_reg,	0x000000ff,
		VDPQ_CADAP_SYNC_UNIFORMITY_TH_reg,	0x00000000,
		VDPQ_CADAP_LUT_LEVEL_TH_reg,		0x00000027,
		VDPQ_CADAP_LUT_GAIN_TH_reg,			0x00000033,
		_TBL_END
	},
};

