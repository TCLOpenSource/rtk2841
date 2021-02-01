#ifndef __MHL_CDF_H
#define __MHL_CDF_H


#ifndef MHL3_ENABLE
//#error "Need to define MHL3_ENABLE"
#define MHL3_ENABLE 0
#endif
#if MHL3_ENABLE
#define CDF_CR_MHL_VER_MAJOR     	 3
#define CDF_CR_MHL_VER_MINOR     	 2
#else
#define CDF_CR_MHL_VER_MAJOR     	 2
#define CDF_CR_MHL_VER_MINOR     	 2
#endif
#define CDF_CR_DEV_TYPE          		 1
#define CDF_CR_POW              		 1
#define CDF_CR_POW_PLIM           		 1
#define CDF_CR_ADOPTER_ID_H      	0x02
#define CDF_CR_ADOPTER_ID_L      	0xFD
#define CDF_CR_SUPP_RGB444         	1
#define CDF_CR_SUPP_YCBCR444       	1
#define CDF_CR_SUPP_YCBCR422     	1
#define CDF_CR_SUPP_PPIXEL         	1 /*MHL3 spec. define no pp mode*/
#define CDF_CR_SUPP_ISLANDS        	1
#define CDF_CR_SUPP_VGA            		1
#if MHL3_ENABLE
#define CDF_CR_SUPP_16BPP		1
#define CDF_CR_HBR				1
#else
#define CDF_CR_SUPP_16BPP		0
#define CDF_CR_HBR				0
#endif
#define CDF_CR_AUD_2CH             		1
#define CDF_CR_AUD_8CH             		0
#define CDF_CR_VT_GRAPHICS         	0
#define CDF_CR_VT_PHOTO            	0
#define CDF_CR_VT_CINEMA           	0
#define CDF_CR_VT_GAME             		0
#define CDF_CR_LD_DISPLAY          	1
#define CDF_CR_LD_VIDEO            		0
#define CDF_CR_LD_AUDIO            		0
#define CDF_CR_LD_MEDIA            		0
#define CDF_CR_LD_TUNER            		0
#define CDF_CR_LD_RECORD           	0
#define CDF_CR_LD_SPEAKER          	1
#define CDF_CR_LD_GUI              		0
#define CDF_CR_BANDWIDTH           	15
#define CDF_CR_RCP_SUPPORT         	1
#define CDF_CR_RAP_SUPPORT         	1
#define CDF_CR_SP_SUPPORT          	1
#define CDF_CR_RBP_SUPPORT		0
#define CDF_CR_DEVICE_ID_H         	0
#define CDF_CR_DEVICE_ID_L         	0
#define CDF_CR_SCRATCHPAD_SIZE     16
#define CDF_CR_INT_SIZE            		3
#define CDF_CR_STAT_SIZE           		3
#define CDF_CR_UCP_RECV_SUPPORT    0
#define CDF_CR_UCP_SEND_SUPPORT    0

#define CDF_ECBUS_S_75		1
#define CDF_ECBUS_S_8BIT	1
#define CDF_ECBUS_S_12BIT	0
#define CDF_ECBUS_D_150	0
#define CDF_ECBUS_D_8BIT	0

#define CDF_TMDS_150		1
#define CDF_TMDS_300		1
#define CDF_TMDS_600		1

#define CDF_DEV_HOST		0
#define CDF_DEV_DEVICE		0
#define CDF_DEV_CHARGER	0
#define CDF_HID_HOST		0
#define CDF_HID_DEVICE		0

#define CDF_LD_PHONE		0

#define CDF_ACRFS_DIV_8	0
#define CDF_ACRFS_DIV_16	0
#define CDF_ACRFS_DIV_32	0

#endif

