#ifndef __VBI_SLICER_H__
#define __VBI_SLICER_H__

#include <scalercommon/scalerCommon.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	VBI_DATA_NON=0,
	VBI_DATA_COLLECTING,
	VBI_DATA_COLLECTED
}VBI_DATA_STATUS;
#define VBI_TTX_NEW_DMA_ENABLE 1
unsigned int video_send_vbi_slicer_rpc(unsigned long para1, unsigned long para2);
void init_vbi_rpc(void);
void Scaler_VbiTtxSetPhyBufAddr(unsigned long addr);
void Scaler_VbiTtInit(void);
void Scaler_VbiTtDeinit(void);
void Scaler_VbiCcSetPhyBufAddr(unsigned long addr);
void Scaler_VbiCcInit(void);
void Scaler_VbiCcPlay(unsigned char from);
void Scaler_VbiCcSetBuf(unsigned int* buf_addr);
void Scaler_VbiCcDeinit(void);
void Scaler_VbiCcStop(unsigned char from);
unsigned int Scaler_VbiGet_480I_WSS(void);
unsigned short Scaler_VbiGet_576I_WSS(void);
void Scaler_VbiVPSSetPhyBufAddr(unsigned long addr);
void Scaler_vbi_vps_init(void);
void Scaler_vbi_vps_uninit(void);
void Scaler_vbi_cgms_init(CGMS_SOURCE source);
void Scaler_vbi_cgms_Uninit(CGMS_SOURCE source);
unsigned int Scaler_VbiGet_cgms(void);
void Scaler_tt_init_enable(void);
void Scaler_vps_init_enable(void);
void Scaler_cc_init_enable(void);
void Scaler_vbi_cgms_init_enable(void);
void palwss_data_send(void);
void vbi_just_576i_wss_init(void);
void vbi_just_576i_wss_uninit(void);
void wss_data_clear(void);
void wss_data_receive(void);
void cgms_data_clear(void);
void cgms_data_receive(void);
void Scaler_reset_vbi_wss(void);
unsigned char Scaler_vbi_ttx_signal(void);
void Scaler_vbi_ttx_interrupt_set(unsigned char enable);
#if 0
unsigned int Scaler_share_vbimem(VBI_TYPE_T vbi_status);
unsigned int Scaler_VbiTtxGetVirBufAddr(unsigned char bCached);
unsigned int Scaler_VbiCcGetVirBufAddr(unsigned char bCached);
unsigned int Scaler_VbiVPSGetVirBufAddr(unsigned char bCached);
unsigned char vbi_status_get_status(VBI_TYPE_T type);
void vbi_status_clear(VBI_TYPE_T type);
unsigned int vbi_status_get_size(VBI_TYPE_T type);
extern unsigned char ttx_slicer_fieldBuff     [PPR_FIELD_BUFF_PKT_NUM][TTX_SLICER_PACKET_SIZE];
extern unsigned char vps_slicer_fieldBuff     [VBI_VPS_BUF_LENGTH][VBI_VPS_FRAME_BYTES];
extern unsigned short vbi_pal_wss;
extern unsigned int vbi_ntsc_wss;
extern unsigned char cc_slicer_fieldBuff     [VBI_CC_BUF_LENGTH][VBI_CC_FRAME_BYTES];
#endif
#ifdef __cplusplus
}
#endif

#endif
