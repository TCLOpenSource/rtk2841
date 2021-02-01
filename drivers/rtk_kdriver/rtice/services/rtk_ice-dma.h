#ifndef __RTK_ICE_DMA_H__
#define __RTK_ICE_DMA_H__
#include "../core/rtk_ice.h"
#include "rtk_ice_mc_measure.h"
/****enum about ip*****/
typedef enum
{
    DMA_STATUS_TVSB2=0x0,
    DMA_STATUS_TVSB1=1,
    DMA_STATUS_SB1,
    DMA_STATUS_SB2,
    DMA_STATUS_SB3,
    DMA_STATUS_VE,
    DMA_STATUS_VE2,
    DMA_STATUS_TVSB3,
    DMA_STATUS_GPU,
    DMA_STATUS_TVSB5,
    DMA_STATUS_SE2,
    DMA_STATUS_TVSB4,
    DMA_STATUS_MEMC,
    DMA_STATUS_MAX_IP,
}ENUM_DMA_STATUS_IP_CODE;

/****enum about sub ip*****/
typedef enum{
    TVSB2_SUB_IP_DI_W=0,
    TVSB2_SUB_IP_DI_R,
    TVSB2_SUB_IP_M_cap_W,
    TVSB2_SUB_IP_M_disp_R,
    TVSB2_SUB_IP_S_cap_W,
    TVSB2_SUB_IP_S_disp_R,
    TVSB2_SUB_IP_VO1_Y_R,
    TVSB2_SUB_IP_VO1_C_R,
    TVSB2_SUB_IP_VO2_Y_R,
    TVSB2_SUB_IP_VO2_C_R,
    TVSB2_SUB_IP_I3DDMA_W,
    TVSB2_SUB_IP_DE_XC_W,
    TVSB2_SUB_IP_DE_XC_R,
    TVSB2_SUB_IP_SNR_R,
    TVSB2_MAX_SUB_IP,
}ENUM_TVSB2_SUB_IPS_CODE;

typedef enum{
    TVSB1_SUB_IP_VD=0,
    TVSB1_SUB_IP_Audio1,
    TVSB1_SUB_IP_Audio2,
    TVSB1_SUB_IP_VBI,
    TVSB1_SUB_IP_TVE_VD,
    TVSB1_SUB_IP_TVE_VBI,
    TVSB1_MAX_SUB_IP,
}ENUM_TVSB1_SUB_IPS_CODE;

typedef enum{
    SB1_SUB_IP_NF=0,
    SB1_SUB_IP_EMMC,
    SB1_MAX_SUB_IP,
}ENUM_SB1_SUB_IPS_CODE;
typedef enum{
    SB2_MAX_SUB_IP=0,
}ENUM_SB2_SUB_IPS_CODE;
typedef enum{
    SB3_SUB_IP_MD=0,
    SB3_SUB_IP_AEE,
    SB3_SUB_IP_AEE2,
    SB3_SUB_IP_ADE,
    SB3_SUB_IP_ADE2,
    SB3_SUB_IP_VDE,
    SB3_SUB_IP_VDE2,
    SB3_SUB_IP_ME,
    SB3_SUB_IP_VE,
    SB3_SUB_IP_VE2,
    SB3_MAX_SUB_IP,
}ENUM_SB3_SUB_IPS_CODE;

typedef enum{
    VE_SUB_IP_VE=0,
    VE_MAX_SUB_IP,
}ENUM_VE_SUB_IPS_CODE;

typedef enum{
    VE2_SUB_IP_VE2=0,
    VE2_MAX_SUB_IP,
}ENUM_VE2_SUB_IPS_CODE;

typedef enum{
    TVSB3_SUB_IP_OSD_COMP=0,
    TVSB3_SUB_IP_OSD_OFF_1_5,
    TVSB3_MAX_SUB_IP,
}ENUM_TVSB3_SUB_IPS_CODE;

typedef enum{
    GPU_SUB_IP_GPU=0,
    GPU_MAX_SUB_IP,
}ENUM_GPU_SUB_IPS_CODE;

typedef enum{
    TVSB5_SUB_IP_OSD_PST=0,
    TVSB5_MAX_SUB_IP,
}ENUM_TVSB5_SUB_IPS_CODE;

typedef enum{
    SE2_MAX_SUB_IP=0,
}ENUM_SE2_SUB_IPS_CODE;

typedef enum{
    TVSB4_SUB_IP_OD_W=0,
    TVSB4_SUB_IP_OD_R,
    TVSB4_SUB_IP_DC2H ,
    TVSB4_SUB_IP_SUBTITLE,
    TVSB4_SUB_IP_OSD1_5,
    TVSB4_SUB_IP_OSD_FBDC1,
#if 0    
    TVSB4_SUB_IP_Demura,
#endif
    TVSB4_MAX_SUB_IP,
}ENUM_TVSB4_SUB_IPS_CODE;
#if 0
typedef enum{
    MEMC_SUB_IP_ME0=0,
    MEMC_SUB_IP_ME1,
    MEMC_SUB_IP_ME2,
    MEMC_SUB_IP_ME3,
    MEMC_SUB_IP_ME4,
    MEMC_SUB_IP_ME5,
    MEMC_SUB_IP_ME6,
    MEMC_SUB_IP_ME7,
    MEMC_SUB_IP_ME8,
    MEMC_SUB_IP_ME9,
    MEMC_SUB_IP_ME10,
    MEMC_SUB_IP_ME11,
    MEMC_SUB_IP_ME12,
    MEMC_SUB_IP_ME13,
    MEMC_SUB_IP_ME14,
    MEMC_SUB_IP_ME15,
    MEMC_SUB_IP_MC0,
    MEMC_SUB_IP_MC1,
    MEMC_SUB_IP_MC4,
    MEMC_SUB_IP_MC5,
    MEMC_SUB_IP_MC6,
    MEMC_SUB_IP_MC7,
    MEMC_MAX_SUB_IP,
}ENUM_MEMC_SUB_IPS_CODE;
#endif
/****enum about data type*****/
typedef enum{
    DMA_STATUS_UNDERFLOW=0,
    DMA_STATUS_UNDERFLOW_1,
    DMA_STATUS_UNDERFLOW_2,
    DMA_STATUS_OVERFLOW_0,
    DMA_STATUS_OVERFLOW_1,   
    DMA_STATUS_OVERFLOW_2,
    DMA_STATUS_OVER_UNDER_FLOW,
    DMS_STATUS_MAX_DATA_CODE,
}ENUM_DMA_STATUS_DATA_CODE;
/****define struct*****/

/****define struct*****/
typedef struct CFIFODataInfo{
    unsigned int _id;
    unsigned int _value;
    struct CFIFODataInfo * next;
    bool _isChoosen;
    unsigned int (*UpdateFunction)(void);
};

typedef struct{
    unsigned int _id;//ip id
    unsigned int _subCount;//data count
    struct CFIFODataInfo * _pDataHead;//list about data
    bool _isChoosen;
}CFIFOSubIpStatus;

typedef struct{
    unsigned int _id;//ip id
    unsigned int _subCount;//sub ips count
    CFIFOSubIpStatus ** _subIps;//vector about data
    bool _isChoosen;
}CFIFOIpStatus;

typedef struct{
    unsigned int _subCount;//sub ips count
    CFIFOIpStatus ** _ips;//vector about ip
}CFIFODMAStatus;

/*Get DMA Status*/
#define RTICE_IOMEM_CMD_GET_DMA_STATUS\
	RTICE_OP_CODE(RTICE_CMD_GROUP_ID_DMA_STATUS, 0)

/* Error Code*/
#define RTICE_DMA_STATUS_INVALID_CMD_LEN			    RTICE_FUNC_ERR_1(0)
#define RTICE_DMA_STATUS_INVALID_IP_ID			    RTICE_FUNC_ERR_1(1)
#define RTICE_DMA_STATUS_INVALID_SUB_IP_ID			RTICE_FUNC_ERR_1(2)
#define RTICE_DMA_STATUS_INVALID_DATA_ID			    RTICE_FUNC_ERR_1(3)
#define RTICE_DMA_STATUS_INIT_IP_ORDER_ERROR		RTICE_FUNC_ERR_1(4)
#define RTICE_DMA_STATUS_OUT_LENGTH_OVERFLOW		RTICE_FUNC_ERR_1(5)

#endif
