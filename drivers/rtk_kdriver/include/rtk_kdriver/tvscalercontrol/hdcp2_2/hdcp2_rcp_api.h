#ifndef __HDCP2_RCP_API_H__
#define __HDCP2_RCP_API_H__

#include <rtk_kdriver/mcp/rtk_rcp.h>

#define RTK_RCP_SET_CW_HDCP2(id, pCW, len)  RTK_RCP_SET_CW((id+1), pCW, len)
#define RTK_RCP_GET_CW_HDCP2(id, pCW, len)  RTK_RCP_GET_CW((id+1), pCW, len)

/*//////////////////////// Functions for HDCP2 /////////////////////////////*/
void RCP_HDCP2_EkhKm(int KhCw, int KmCw, unsigned char *Rtx,
                     unsigned char *pEkhKm);
void RCP_HDCP2_GenDKey(int KmCw, unsigned char *Rtx,
                       unsigned char *Rrx, unsigned char *Rn,
                       unsigned char ctr, int DKeyCW, int modeHDCP22);
void RCP_HDCP2_GenKd(int KmCw, unsigned char *Rtx, unsigned char *Rrx,
                     unsigned char *Rn, int KdCW, int modeHDCP22);
void RCP_HDCP2_GenKs(int dKey2CW, unsigned char *EdKeyKs,
                     unsigned char *Rrx, int KsCW);
void RCP_HDCP2_GenKsXorLc128(int Lc128CW, int KsCW, int KsXorLc128CW);
void RCP_HDCP2_DataDecrypt(int KsXorLs128CW,  int DatadecryptoCW, unsigned char *key, unsigned char *pcounter);

#endif
