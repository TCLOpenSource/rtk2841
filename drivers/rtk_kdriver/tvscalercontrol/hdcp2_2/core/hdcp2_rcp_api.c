/***************************************************************************************************
  File        : rcp_api.cpp
  Description : Low Level API for RCP
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20090605    | Create Phase
***************************************************************************************************/

#include <tvscalercontrol/hdcp2_2/hdcp2_hal.h>
#include <tvscalercontrol/hdcp2_2/hdcp2_rcp_api.h>
#include <mach/system.h>


void RCP_HDCP2_GenKd(int KmCw, unsigned char *Rtx, unsigned char *Rrx, unsigned char *Rn, int KdCW, int modeHDCP22)
{
    RCP_HDCP2_GenDKey(KmCw, Rtx, Rrx, Rn, 0, KdCW, modeHDCP22);
    RCP_HDCP2_GenDKey(KmCw, Rtx, Rrx, Rn, 1, KdCW + 2, modeHDCP22);
}



void RCP_HDCP2_GenDKey(int KmCw, unsigned char *Rtx, unsigned char *Rrx,
                       unsigned char *Rn, unsigned char ctr, int DKeyCW,
                       int modeHDCP22)
{
    unsigned char tmp[16];
    unsigned char ctr_rrx_out[8];
    unsigned char km_tmp[16];
    unsigned char dkey_tmp[16];
    memset(ctr_rrx_out, 0x0, 8);
    pr_debug("compute ctr = %d,dkeycw= %d\n", ctr, DKeyCW);

    /* Generate Km^Rn in DKeyCW   */
    memset(tmp, 0, 16);
    memcpy(&tmp[8], Rn, 8);
    RTK_RCP_SET_CW_HDCP2(DKeyCW , tmp, 16);
    /*RCP_CW_XOR(KmCw, DKeyCW, DKeyCW);     */
#if 1
    RTK_RCP_GET_CW_HDCP2(KmCw , km_tmp, 16);
    RTK_RCP_GET_CW_HDCP2(DKeyCW , dkey_tmp, 16);
    xor_array(km_tmp, dkey_tmp, dkey_tmp, 16);
    RTK_RCP_SET_CW_HDCP2(DKeyCW , dkey_tmp, 16);

#endif
    memset(tmp, 0, 16);
    memcpy(tmp, Rtx, 8);
    if (modeHDCP22 == 0)
        tmp[15] = ctr;

    else {
        unsigned char ctr_array[8];
        memset(ctr_array, 0, 8);
        ctr_array[7] = ctr;
        xor_array(Rrx, ctr_array, ctr_rrx_out, 8);
        memcpy(tmp + 8, ctr_rrx_out, 8);
    }
    /* Generate Kd */
    RTK_RCP_AES_ECB_Encryption((unsigned char *)(DKeyCW + 1), tmp, (unsigned char *)(DKeyCW + 1), 16);
}

void RCP_HDCP2_DataDecrypt(int KsXorLs128CW,  int DatadecryptoCW, unsigned char *key, unsigned char *pcounter)
{
    RTK_RCP_SET_CW_HDCP2(DatadecryptoCW , key, 16);
    RTK_RCP_AES_ECB_Encryption((unsigned char *)(DatadecryptoCW + 1), pcounter, (unsigned char *)(DatadecryptoCW + 1), 16);
}

void RCP_HDCP2_EkhKm(int KhCw, int KmCw, unsigned char *Rtx,
                     unsigned char *pEkhKm)
{
    memset(pEkhKm, 0, 16);
    memcpy(pEkhKm, Rtx, 8);

    RTK_RCP_AES_ECB_Encryption((unsigned char *)(KhCw + 1), pEkhKm, pEkhKm, 16);

    RTK_RCP_AES_ECB_Encryption((unsigned char *)(KhCw + 1), pEkhKm, pEkhKm, 16);

    RTK_RCP_AES_CBC_Decryption((unsigned char *)(KhCw + 1), (unsigned char *)(KmCw + 1), pEkhKm, pEkhKm, 16);
}

void RCP_HDCP2_GenKs(int dKey2CW, unsigned char *EdKeyKs,
                     unsigned char *rRx, int KsCW)
{
    unsigned char tmp[16];
    unsigned char dkey2_tmp[16];
    unsigned char ks_tmp[16];
    memcpy(tmp, EdKeyKs, 16);
    xor_array(&tmp[8], rRx, &tmp[8], 8);
    RTK_RCP_SET_CW_HDCP2(KsCW , tmp, 16);
#if 1
    RTK_RCP_GET_CW_HDCP2(dKey2CW , dkey2_tmp, 16);
    RTK_RCP_GET_CW_HDCP2(KsCW , ks_tmp, 16);
    xor_array(dkey2_tmp, ks_tmp, ks_tmp, 16);
    RTK_RCP_SET_CW_HDCP2(KsCW , ks_tmp, 16);

#endif
}

void RCP_HDCP2_GenKsXorLc128(int Lc128Cw, int KsCW, int KsXorLc128CW)
{
    RTK_RCP_CW_XOR(Lc128Cw + 1, KsCW + 1, KsXorLc128CW + 1);
}

