/***************************************************************************************************
  File        : rtk_rcp.cpp
  Description : Low Level API for RCP
  Author      : liangliang_song
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20170413    | Create Phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/init.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <base_types.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/notifier.h>
#include <linux/list.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <mach/irqs.h>
#include <mach/platform.h>
#include <linux/spinlock.h>
#include <mach/io.h>
#ifdef CONFIG_RTK_KDRV_CW
#include <rtk_kdriver/rtk_cw_util.h>
#endif

#include <rtk_kdriver/mcp/rtk_rcp.h>
#include "rtk_rcp_dbg.h"
#include "rtk_rcp_dev.h"
#include "rtk_rcp_reg.h"
#include "rtk_rcp_defines.h"

#define RCP_CW_MODULE_NAME "RCP"

static DEFINE_SPINLOCK(rtk_rcp_lock);
static DEFINE_SPINLOCK(rtk_rcp_cw_lock);


#define RTK_RCP_LOCK(lock, flags)               spin_lock_irqsave(&(lock), flags)
#define RTK_RCP_UNLOCK(lock, flags)      spin_unlock_irqrestore(&(lock), flags)

static void aes_ctr_cnt_add(unsigned char cnt[16])
{
    unsigned char ov = 0;
    int i = 15;
    // KWarning: checked ok by stellaliu@realtek.com
    do {
        cnt[i]++;
        ov = (cnt[i]) ? 0 : 1;
    }while(--i>=0 && ov);
}


/*----------------------------------------------------------------------
 * Func : rtk_rcp_dump_mem
 *
 * Desc : dump data in memory
 *
 * Parm : data : start address of data
 *        len  : length of data
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void rtk_rcp_dump_mem(unsigned char* data, unsigned int len)
{
    int i;
    for (i = 0; i < len; i++) {
        if ((i & 0xF) == 0)
            printk(" %04x | ", i);
        printk("%02x ", data[i]);
    }
    printk("\n");
}


static void rtk_rcp_set_reg_array(RCP_REG_TYPE reg_type, unsigned int nregs,
                                  unsigned char *data_in, unsigned int len)
{
    unsigned int i = 0;
    if(nregs > 4)
        nregs = 4;
    if(data_in == NULL || len == 0)
        return;
    switch(reg_type) {
        case RCP_REG_TYPE_KEY:
            for(i = 0; i < nregs; i++)
                SET_CP_REG_MOD_KEY(i, RCP_BS4TL(data_in + 4 * i));
            break;
        case RCP_REG_TYPE_KEY1:
            for(i = 0; i < nregs; i++)
                SET_CP_REG_MOD_KEY1(i, RCP_BS4TL(data_in + 4 * i));
            break;    
        case RCP_REG_TYPE_IV:
            for(i = 0; i < nregs; i++)
                SET_CP_REG_MOD_IV(i, RCP_BS4TL(data_in + 4 * i));
            break;
        case RCP_REG_TYPE_DATAIN:
            for(i = 0; i < nregs; i++)
                SET_CP_REG_MOD_DATAIN(i, RCP_BS4TL(data_in + 4 * i));
            break;
        case RCP_REG_TYPE_DATAOUT:
            for(i = 0; i < nregs; i++)
                SET_CP_REG_MOD_DATAOUT(i, RCP_BS4TL(data_in + 4 * i));
            break;
        default:
            break;
    }
}


static void rtk_rcp_get_reg_array(RCP_REG_TYPE reg_type, unsigned int nregs,
                           unsigned char *data_out, unsigned int len)
{
    unsigned int i = 0;
    if(data_out == NULL || len == 0)
        return;
    if(nregs > 4)
        nregs = 4;
    switch(reg_type) {
        case RCP_REG_TYPE_KEY:
            for(i = 0; i < nregs; i++)
                RCP_LTBS4(data_out + 4 * i, GET_CP_REG_MOD_KEY(i));
            break;
        case RCP_REG_TYPE_IV:
            for(i = 0; i < nregs; i++)
                RCP_LTBS4(data_out + 4 * i, GET_CP_REG_MOD_IV(i));
            break;
        case RCP_REG_TYPE_DATAIN:
            for(i = 0; i < nregs; i++)
                RCP_LTBS4(data_out + 4 * i, GET_CP_REG_MOD_DATAIN(i));
            break;
        case RCP_REG_TYPE_DATAOUT:
            for(i = 0; i < nregs; i++)
                RCP_LTBS4(data_out + 4 * i, GET_CP_REG_MOD_DATAOUT(i));
            break;
        default:
            break;
    }
}



/*======================================================================
 * Func : RTK_RCP_SET_MODE
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : NULL / data pointer
 *======================================================================*/
static unsigned char* RTK_RCP_SET_MODE(
    int                     Mode,
    unsigned char*          pData,
    unsigned long           DataLen,
    unsigned int            BlockSize,
    unsigned char*          pKey
)
{
    int i = 0;
    switch(Mode) {
        case KEY_MODE:
            if (pData == NULL) {
                SET_CP_REG_MOD_SET1(GET_CP_REG_MOD_SET1() | REG_SET1_KEY_MODE_OTP);
            } else if ((unsigned long)pData <= MAX_CW_ENTRY) {
                SET_CP_REG_MOD_SET1(GET_CP_REG_MOD_SET1() | REG_SET1_KEY_MODE_CW);
                SET_CP_REG_MOD_SET2(GET_CP_REG_MOD_SET2() | REG_SET2_KEY_ENTRY(((unsigned long)pData) - 1));// each cw takes 8 entry
            } else {
                unsigned char tmp_key[16] = {0};
                if (DataLen == 16) {
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY, 4, pData, 16);
                } else if (DataLen == 7) {   // DES Key
                    tmp_key[0] = 0;
                    memcpy(tmp_key + 1, pData, 7);
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY, 2, tmp_key, 8);

                } else if (DataLen == 21) { // TDES Key
                    tmp_key[0] = 0;
                    tmp_key[8] = 0;
                    memcpy(tmp_key + 1, pData, 7);      // store K1, K2, K3 should be stored in Data2,3
                    memcpy(tmp_key + 9, pData + 7, 7);
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY, 4, tmp_key, 16);
                } else if (DataLen == 24) { 
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY, 4, pData, 16);
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY1, 2, pData + 16, 8);
                } else if (DataLen == 32) { 
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY, 4, pData, 16);
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_KEY1, 4, pData + 16, 16);
                }else {
                    return NULL;
                }
            }
            break;

        case IV_MODE:
            if(pData != NULL) {
                if ((unsigned long)pData <= MAX_CW_ENTRY) {
                    SET_CP_REG_MOD_SET1(GET_CP_REG_MOD_SET1() | REG_SET1_KEY_MODE_CW);
                    SET_CP_REG_MOD_SET2(GET_CP_REG_MOD_SET2() | REG_SET2_IV_ENTRY(((unsigned long)pData) - 1));// each cw takes 8 entry
                } else {
                    SET_CP_REG_MOD_SET1(GET_CP_REG_MOD_SET1() | REG_SET1_IV_MODE_REG);
                    if (DataLen == 16) {    // 128 bits IV
                        rtk_rcp_set_reg_array(RCP_REG_TYPE_IV, 4, pData, 16);

                    } else if (DataLen == 8) { // 64 bits IV
                        rtk_rcp_set_reg_array(RCP_REG_TYPE_IV, 2, pData, 8);
                    }
                }
            }
            break;

        case INPUT_MODE:
            if ((unsigned long)pData <= MAX_CW_ENTRY) {
                if (((unsigned long)pData) + (DataLen >> 3) > MAX_CW_ENTRY) {
                    RCP_WARNING("Input from CW, but out of range\n");
                    return NULL;
                }
                SET_CP_REG_MOD_SET1(GET_CP_REG_MOD_SET1() | REG_SET1_INPUT_MODE_CW);
            }
            break;

        case OUTPUT_MODE:

            if ((unsigned long)pData <= MAX_CW_ENTRY) {
                if (((unsigned long)pData) + (DataLen >> 3) > MAX_CW_ENTRY) {
                    RCP_WARNING("Output to CW, but out of range\n");
                    return NULL;
                }
                SET_CP_REG_MOD_SET1(GET_CP_REG_MOD_SET1() | REG_SET1_OUTPUT_MODE_CW);
            }
            break;

        case INPUT_ENTRY:

            if ((unsigned long)pData <= MAX_CW_ENTRY) {
                unsigned char tmp_data[16] = {0};
                SET_CP_REG_MOD_SET2((GET_CP_REG_MOD_SET2() & 0xff00ffff) | REG_SET2_INPUT_ENTRY(((unsigned long)pData) - 1));
                rtk_rcp_set_reg_array(RCP_REG_TYPE_DATAIN, 4, tmp_data, 16);
                pData += BlockSize / 8;       // jump 2 cw entry...
            }  else {
                if (BlockSize == 8) {
                    unsigned char tmp_data[16] = {0};
                    memcpy(tmp_data, pData, 8);
                    if(pKey != NULL) {       // TDES
                        // for TDES only. TDES use Data2,Data3 to store K3
                        tmp_data[8] = 0;
                        memcpy(tmp_data + 9, pKey + 14, 7);
                    }
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_DATAIN, 4, tmp_data, 16);
                } else {
                    rtk_rcp_set_reg_array(RCP_REG_TYPE_DATAIN, 4, pData, 16);
                }

                pData += BlockSize;
            }
            break;

        case OUTPUT_ENTRY:

            if ((unsigned long)pData <= MAX_CW_ENTRY) {
                unsigned char tmp[16] = {0};
                SET_CP_REG_MOD_SET2((GET_CP_REG_MOD_SET2() & 0xffffff) | REG_SET2_OUTPUT_ENTRY((unsigned long)pData - 1));
                rtk_rcp_get_reg_array(RCP_REG_TYPE_DATAOUT, 4, tmp, 16);
                pData += BlockSize / 8;
            } else {
                if (BlockSize == 16) {
                    rtk_rcp_get_reg_array(RCP_REG_TYPE_DATAOUT, 4, pData, 16);
                } else if (BlockSize == 8) {
                    rtk_rcp_get_reg_array(RCP_REG_TYPE_DATAOUT, 2, pData, 8);
                } else {
                    return NULL;
                }
                pData += BlockSize;
            }
            break;
        default:
            break;
    }

    return pData;
}


static int RTK_RCP_CRYPTION_INIT(unsigned int rcp_crypt_set, unsigned char *key, unsigned int key_len, 
                             unsigned char *iv, unsigned int iv_len, unsigned char* pDataIn,
                             unsigned char* pDataOut, unsigned long DataLen)
{
    SET_CP_REG_MOD_SET(rcp_crypt_set);
    SET_CP_REG_MOD_SET1(0);
    SET_CP_REG_MOD_SET2(0);
    RTK_RCP_SET_MODE(KEY_MODE, key, key_len, 0, NULL);
    if(iv != NULL)
        RTK_RCP_SET_MODE(IV_MODE, iv, iv_len, 0, NULL);
    RTK_RCP_SET_MODE(INPUT_MODE, pDataIn, DataLen, 0, NULL);
    RTK_RCP_SET_MODE(OUTPUT_MODE, pDataOut, DataLen, 0, NULL);
    return 0;
}


static int RTK_RCP_DO_CRYPTION(unsigned int rcp_crypt_set, unsigned char *Key, unsigned int BlockSize, 
                                        unsigned char* pDataIn, unsigned char* pDataOut, unsigned long DataLen)
{
    unsigned long  out_len = 0;
    while(DataLen >= BlockSize) {
        if ((unsigned long)pDataOut <= MAX_CW_ENTRY) {
            SET_CP_REG_MOD_SET2((GET_CP_REG_MOD_SET2() & 0xffffff) |
                                REG_SET2_OUTPUT_ENTRY((unsigned long)pDataOut - 1));
            pDataOut += BlockSize / 8;
            if(!(pDataIn = RTK_RCP_SET_MODE(INPUT_ENTRY, pDataIn, DataLen, BlockSize, Key)))
                goto error_occur;
        } else {
            if(!(pDataIn = RTK_RCP_SET_MODE(INPUT_ENTRY, pDataIn, DataLen, BlockSize, Key)))
                goto error_occur;

            rtk_rcp_get_reg_array(RCP_REG_TYPE_DATAOUT, BlockSize/sizeof(unsigned int), pDataOut, BlockSize);
            pDataOut += BlockSize;
        }

        DataLen -= BlockSize;
        out_len += BlockSize;
        if(rcp_crypt_set & REG_SET_FIRST_128)
            SET_CP_REG_MOD_SET(GET_CP_REG_MOD_SET() & (~REG_SET_FIRST_128));
    }
    return out_len;
error_occur:
    return 0;
}

/*======================================================================
 * Func : RTK_RCP_DES_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_DES_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[7],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_DES_ECB_ENC : RCP_DES_ECB_DEC,
            Key, 7, NULL, 0, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_DES_ECB_ENC : RCP_DES_ECB_DEC, NULL, 8,
            pDataIn, pDataOut, DataLen);      
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RTK_RCP_DES_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_DES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[7],
    unsigned char           IV[8],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_DES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_DES_CBC_ENC : RCP_DES_CBC_DEC,
            Key, 7, IV, 8, pDataIn, pDataOut, DataLen);          
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_DES_CBC_ENC : RCP_DES_CBC_DEC, NULL, 8,
                                        pDataIn, pDataOut, DataLen); 
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RTK_RCP_TDES_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_TDES_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[21],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long out_len = 0;
    unsigned char tmp_key[21];
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);

    if (EnDe == 0) {
        memcpy(tmp_key + 14, Key, 7);
        memcpy(tmp_key + 7, Key + 7, 7);
        memcpy(tmp_key, Key + 14, 7);
        Key = tmp_key;
    }
    
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_TDES_ECB_ENC : RCP_TDES_ECB_DEC,
            Key, 21, NULL, 0, pDataIn, pDataOut, DataLen);

    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_TDES_ECB_ENC : RCP_TDES_ECB_DEC, Key, 8,
                                        pDataIn, pDataOut, DataLen); 
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RTK_RCP_TDES_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_TDES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[21],
    unsigned char           IV[8],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long out_len = 0;
    unsigned char tmp_key[21];

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_DES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);

    if (EnDe == 0) {
        memcpy(tmp_key + 14, Key, 7);
        memcpy(tmp_key + 7, Key + 7, 7);
        memcpy(tmp_key, Key + 14, 7);
        Key = tmp_key;
    }

    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_TDES_CBC_ENC : RCP_TDES_CBC_DEC,
            Key, 21, IV, 8, pDataIn, pDataOut, DataLen);

    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_TDES_CBC_ENC : RCP_TDES_CBC_DEC, Key, 8,
                                        pDataIn, pDataOut, DataLen); 
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}



/*======================================================================
 * Func : RTK_RCP_AES_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_128_ECB_ENC : RCP_AES_128_ECB_DEC,
            Key, 16, NULL, 0, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_128_ECB_ENC : RCP_AES_128_ECB_DEC, NULL, 16,
                                        pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RTK_RCP_AES_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_AES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_128_CBC_ENC : RCP_AES_128_CBC_DEC,
            Key, 16, IV, 16, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_128_CBC_ENC : RCP_AES_128_CBC_DEC, NULL, 16,
                                            pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RTK_RCP_AES_CTR_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
 static int _RTK_RCP_AES_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen,
    unsigned char           word_align  /*It seems stranged, from old api*/
)
{
    unsigned long flags;
    unsigned long  out_len = 0;    
    unsigned char  ecnt[16];
    unsigned long* pDI   = (unsigned long*) pDataIn;
    unsigned long* pDO   = (unsigned long*) pDataOut;    
    unsigned long* pEcnt = (unsigned long*) ecnt;    


    if (pDataIn == NULL || pDataOut == NULL || (unsigned long)IV <= MAX_CW_ENTRY) {
        RCP_WARNING("Run RTK_RCP_AES_CTR_Cipher failed, IV should not comes form OTP or CW\n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT(RCP_AES_128_ECB_ENC, Key, 16, NULL, 0, IV, ecnt, 16);
    
    while(DataLen >= 16) {
        RTK_RCP_SET_MODE(INPUT_ENTRY, IV, 16, 16, Key);
        aes_ctr_cnt_add(IV);
        rtk_rcp_get_reg_array(RCP_REG_TYPE_DATAOUT, 16/sizeof(unsigned int), ecnt, 16);
        if (word_align)
        {
            pDO[0] = pEcnt[0] ^ pDI[0];
            pDO[1] = pEcnt[1] ^ pDI[1];
            pDO[2] = pEcnt[2] ^ pDI[2];
            pDO[3] = pEcnt[3] ^ pDI[3];                      
            pDI+=4;
            pDO+=4;
        }
        else
        {
            xor_array(pDataIn, ecnt, pDataOut, 16);    
            pDataIn += 16;
            pDataOut+= 16;     
        }    
        DataLen -= 16;
        out_len += 16; 
        SET_CP_REG_MOD_SET(GET_CP_REG_MOD_SET() & (~REG_SET_FIRST_128));
    }
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}



int RTK_RCP_AES_CTR_Cipher_ex(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen,
    unsigned char           word_align  /*It seems stranged, from old api*/
)
{
    return _RTK_RCP_AES_CTR_Cipher(EnDe, Key, IV, pDataIn, pDataOut, DataLen, word_align);
}

int RTK_RCP_AES_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned char   word_align = (((unsigned long)pDataIn & 0x3) || ((unsigned long)pDataOut & 0x3)) ? 0 : 1; 
    return _RTK_RCP_AES_CTR_Cipher(EnDe, Key, IV, pDataIn, pDataOut, DataLen, word_align);
}


/*======================================================================
 * Func : RTK_RCP_WIDEVINE_AES_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_WIDEVINE_AES_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV_In[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    int ret = DataLen;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    if (DataLen < 16) {
        memcpy(pDataIn, pDataOut, DataLen);
    } else if ((DataLen & 0xF) == 0) {
        ret = RTK_RCP_AES_CBC_Cipher(EnDe, Key, IV_In, pDataIn, pDataOut, DataLen);
    } else {
        int SbLen  = 16 + (DataLen & 0xF);
        unsigned char tmp[32];
        unsigned char tmp2[32];
        unsigned char Cn2[16];
        unsigned char IV[16];

        memcpy(IV, IV_In, 16);      // back up IV
        DataLen -= SbLen;

        if (EnDe) {
            // Encrypt P0 ~ Pn-2
            if (DataLen) {
                RTK_RCP_AES_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen);
                pDataIn  += DataLen;
                pDataOut += DataLen;
                memcpy(IV, pDataOut - 16, 16);   // Update IV (e.g. Cn2)
            }

            /*-------------------------------------------
             * Encryption (Pn-1 ~ Pn)
             *-------------------------------------------
             * Ek(Pn-1 ^ Cn-2) = AEC_CEB_ENC(Pn-1, Cn-2)=[Cn || C']
             * Ek([Pn||0] ^ [Cn||C']) = Cn-1
             * Out = [Cn-1 || Cn]
            //-------------------------------------------*/
            memset(tmp, 0, 32);
            memcpy(tmp, pDataIn, SbLen);

            //mcp_dump_data_with_text(tmp, 32, "Pn1 | Pn | 0");
            //mcp_dump_data_with_text(IV, 16, "Cn2");

            RTK_RCP_AES_CBC_Encryption(Key, IV, tmp, tmp2, 32);   // tmp = [Cn || C'] || Cn-1

            //mcp_dump_data_with_text(tmp2, 32, "[Cn || C'] || Cn-1");
            memcpy(pDataOut, tmp2 + 16, 16);             // output Cn-1
            memcpy(pDataOut + 16, tmp2, SbLen & 0xF);    // output Cn
        } else {
            unsigned char tmpIn[32];

            // Decrypt C0 - Cn-2
            if (DataLen) {
                memcpy(Cn2, pDataIn + DataLen - 16, 16);   // Store Cn2 first.

                RTK_RCP_AES_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen);
                pDataIn  += DataLen;
                pDataOut += DataLen;
            } else
                memcpy(Cn2, IV, 16);

            if (pDataIn == pDataOut) {
                memcpy(tmpIn, pDataIn, 32);
                pDataIn = tmpIn;
            }

            /*-------------------------------------------
             * Decryption Cn-1 ~ Cn
             *-------------------------------------------
             * Dk(Cn-1) ^ [Cn||0] = AES_CBC_DEC(Cn-1, [Cn||0]) = [Pn || C']
             * Dk([Cn||C']) ^ Cn-2 = AES_CBC_DEC([Cn|C'], Cn-2) = Pn-1
             * Out = Pn-1 || Pn
             *-------------------------------------------*/

            SbLen &= 0xF;       // size of the last block

            // IV = [Cn||0]
            memset(IV, 0, 16);
            memcpy(IV, pDataIn + 16, SbLen);

            RTK_RCP_AES_CBC_Decryption(Key, IV, pDataIn, tmp, 16);    // tmp = [Pn || C']

            memcpy(pDataOut + 16, tmp, SbLen);            // output Pn

            //tmp = [Cn || C']
            memcpy(tmp, pDataIn + 16, SbLen);

            RTK_RCP_AES_CBC_Decryption(Key, Cn2, tmp, pDataOut, 16);       // output Pn-1

        }
    }

    return ret;
}


/*======================================================================
 * Func : RTK_RCP_AES_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_192_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_192_ECB_ENC : RCP_AES_192_ECB_DEC,
            Key, 24, NULL, 0, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_192_ECB_ENC : RCP_AES_192_ECB_DEC, NULL, 16,
                                        pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;

}


/*======================================================================
 * Func : RTK_RCP_AES_192_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_192_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_AES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_192_CBC_ENC : RCP_AES_192_CBC_DEC,
            Key, 24, IV, 16, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_192_CBC_ENC : RCP_AES_192_CBC_DEC, NULL, 16,
                                            pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RTK_RCP_AES_CTR_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_192_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || (unsigned long)IV <= MAX_CW_ENTRY) {
        RCP_WARNING("Run RTK_RCP_AES_CTR_Cipher failed, IV should not comes form OTP or CW\n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_192_CTR_ENC : RCP_AES_192_CTR_DEC,
            Key, 24, IV, 16, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_192_CTR_ENC : RCP_AES_192_CTR_DEC, NULL, 16,
                                                pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RTK_RCP_AES_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_256_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_256_ECB_ENC : RCP_AES_256_ECB_DEC,
            Key, 32, NULL, 0, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_256_ECB_ENC : RCP_AES_256_ECB_DEC, NULL, 16,
                                        pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;

}


/*======================================================================
 * Func : RTK_RCP_AES_192_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_256_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_AES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_256_CBC_ENC : RCP_AES_256_CBC_DEC,
            Key, 32, IV, 16, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_256_CBC_ENC : RCP_AES_256_CBC_DEC, NULL, 16,
                                            pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RTK_RCP_AES_CTR_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_AES_256_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || (unsigned long)IV <= MAX_CW_ENTRY) {
        RCP_WARNING("Run RTK_RCP_AES_CTR_Cipher failed, IV should not comes form OTP or CW\n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_AES_256_CTR_ENC : RCP_AES_256_CTR_DEC,
            Key, 32, IV, 16, pDataIn, pDataOut, DataLen);
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_AES_256_CTR_ENC : RCP_AES_256_CTR_DEC, NULL, 16,
                                                pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}



/*======================================================================
 * Func : RCP_CAM_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_128_ECB_ENC : RCP_CAM_128_ECB_DEC,
            Key, 16, NULL, 0, pDataIn, pDataOut, DataLen);  
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_128_ECB_ENC : RCP_CAM_128_ECB_DEC, NULL, 16,
                                                pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RCP_CAM_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_AES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_128_CBC_ENC : RCP_CAM_128_CBC_DEC,
            Key, 16, IV, 16, pDataIn, pDataOut, DataLen);  
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_128_CBC_ENC : RCP_CAM_128_CBC_DEC, NULL, 16,
                                                    pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RTK_RCP_WIDEVINE_CAM_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_WIDEVINE_CAM_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV_In[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    int ret = DataLen;

    if (DataLen < 16) {
        memcpy(pDataIn, pDataOut, DataLen);
    } else if ((DataLen & 0xF) == 0) {
        ret = RTK_RCP_CAM_CBC_Cipher(EnDe, Key, IV_In, pDataIn, pDataOut, DataLen);
    } else {
        int SbLen  = 16 + (DataLen & 0xF);
        unsigned char tmp[32];
        unsigned char tmp2[32];
        unsigned char Cn2[16];
        unsigned char IV[16];

        memcpy(IV, IV_In, 16);      // back up IV
        DataLen -= SbLen;

        if (EnDe) {
            // Encrypt P0 ~ Pn-2
            if (DataLen) {
                RTK_RCP_CAM_CBC_Encryption(Key, IV, pDataIn, pDataOut, DataLen);
                pDataIn  += DataLen;
                pDataOut += DataLen;
                memcpy(IV, pDataOut - 16, 16);   // Update IV (e.g. Cn2)
            }

            /*-------------------------------------------
             * Encryption (Pn-1 ~ Pn)
             *-------------------------------------------
             * Ek(Pn-1 ^ Cn-2) = AEC_CEB_ENC(Pn-1, Cn-2)=[Cn || C']
             * Ek([Pn||0] ^ [Cn||C']) = Cn-1
             * Out = [Cn-1 || Cn]
            //-------------------------------------------*/
            memset(tmp, 0, 32);
            memcpy(tmp, pDataIn, SbLen);

            //mcp_dump_data_with_text(tmp, 32, "Pn1 | Pn | 0");
            //mcp_dump_data_with_text(IV, 16, "Cn2");

            RTK_RCP_CAM_CBC_Encryption(Key, IV, tmp, tmp2, 32);   // tmp = [Cn || C'] || Cn-1

            //mcp_dump_data_with_text(tmp2, 32, "[Cn || C'] || Cn-1");
            memcpy(pDataOut, tmp2 + 16, 16);             // output Cn-1
            memcpy(pDataOut + 16, tmp2, SbLen & 0xF);    // output Cn
        } else {
            unsigned char tmpIn[32];

            // Decrypt C0 - Cn-2
            if (DataLen) {
                memcpy(Cn2, pDataIn + DataLen - 16, 16);   // Store Cn2 first.

                RTK_RCP_CAM_CBC_Decryption(Key, IV, pDataIn, pDataOut, DataLen);
                pDataIn  += DataLen;
                pDataOut += DataLen;
            } else
                memcpy(Cn2, IV, 16);

            if (pDataIn == pDataOut) {
                memcpy(tmpIn, pDataIn, 32);
                pDataIn = tmpIn;
            }

            /*-------------------------------------------
             * Decryption Cn-1 ~ Cn
             *-------------------------------------------
             * Dk(Cn-1) ^ [Cn||0] = CAM_CBC_DEC(Cn-1, [Cn||0]) = [Pn || C']
             * Dk([Cn||C']) ^ Cn-2 = CAM_CBC_DEC([Cn|C'], Cn-2) = Pn-1
             * Out = Pn-1 || Pn
             *-------------------------------------------*/

            SbLen &= 0xF;       // size of the last block

            // IV = [Cn||0]
            memset(IV, 0, 16);
            memcpy(IV, pDataIn + 16, SbLen);

            RTK_RCP_CAM_CBC_Decryption(Key, IV, pDataIn, tmp, 16);    // tmp = [Pn || C']

            memcpy(pDataOut + 16, tmp, SbLen);            // output Pn

            //tmp = [Cn || C']
            memcpy(tmp, pDataIn + 16, SbLen);

            RTK_RCP_CAM_CBC_Decryption(Key, Cn2, tmp, pDataOut, 16);       // output Pn-1

        }
    }

    return ret;
}


/*======================================================================
 * Func : RTK_RCP_CAM_CTR_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[16],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || (unsigned long)IV <= MAX_CW_ENTRY) {
        RCP_WARNING("Run RTK_RCP_AES_CTR_Cipher failed, IV should not comes form OTP or CW\n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_128_CTR_ENC : RCP_CAM_128_CTR_DEC,
            Key, 16, IV, 16, pDataIn, pDataOut, DataLen); 
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_128_CTR_ENC : RCP_CAM_128_CTR_DEC, NULL, 16,
                                                    pDataIn, pDataOut, DataLen);        
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RCP_CAM_192_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_192_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_192_ECB_ENC : RCP_CAM_192_ECB_DEC,
            Key, 24, NULL, 0, pDataIn, pDataOut, DataLen);  
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_192_ECB_ENC : RCP_CAM_192_ECB_DEC, NULL, 16,
                                                pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RCP_CAM_192_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_192_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_AES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_192_CBC_ENC : RCP_CAM_192_CBC_DEC,
            Key, 24, IV, 16, pDataIn, pDataOut, DataLen);  
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_192_CBC_ENC : RCP_CAM_192_CBC_DEC, NULL, 16,
                                                    pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RTK_RCP_CAM_192_CTR_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_192_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[24],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || (unsigned long)IV <= MAX_CW_ENTRY) {
        RCP_WARNING("Run RTK_RCP_AES_CTR_Cipher failed, IV should not comes form OTP or CW\n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_192_CTR_ENC : RCP_CAM_192_CTR_DEC,
            Key, 24, IV, 16, pDataIn, pDataOut, DataLen); 
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_192_CTR_ENC : RCP_CAM_192_CTR_DEC, NULL, 16,
                                                    pDataIn, pDataOut, DataLen);        
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RCP_CAM_256_ECB_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_256_ECB_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;
    if(pDataIn == NULL || pDataOut == NULL)
        return 0;

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_256_ECB_ENC : RCP_CAM_256_ECB_DEC,
            Key, 32, NULL, 0, pDataIn, pDataOut, DataLen);  
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_256_ECB_ENC : RCP_CAM_256_ECB_DEC, NULL, 16,
                                                pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}

/*======================================================================
 * Func : RCP_CAM_CBC_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_256_CBC_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || IV == NULL) {
        RCP_WARNING("Run RTK_RCP_AES_CBC_Cipher failed, IV should not be NULL \n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_256_CBC_ENC : RCP_CAM_256_CBC_DEC,
            Key, 32, IV, 16, pDataIn, pDataOut, DataLen);  
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_256_CBC_ENC : RCP_CAM_256_CBC_DEC, NULL, 16,
                                                    pDataIn, pDataOut, DataLen);
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}


/*======================================================================
 * Func : RTK_RCP_CAM_192_CTR_Cipher
 *
 * Desc :
 *
 * Parm : N/A
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_CAM_256_CTR_Cipher(
    unsigned char           EnDe,
    unsigned char           Key[32],
    unsigned char           IV[16],
    unsigned char*          pDataIn,
    unsigned char*          pDataOut,
    unsigned long           DataLen
)
{
    unsigned long flags;
    unsigned long  out_len = 0;

    if (pDataIn == NULL || pDataOut == NULL || (unsigned long)IV <= MAX_CW_ENTRY) {
        RCP_WARNING("Run RTK_RCP_AES_CTR_Cipher failed, IV should not comes form OTP or CW\n");
        return 0;
    }

    RTK_RCP_LOCK(rtk_rcp_lock, flags);
    RTK_RCP_CRYPTION_INIT((EnDe) ? RCP_CAM_256_CTR_ENC : RCP_CAM_256_CTR_DEC,
            Key, 32, IV, 16, pDataIn, pDataOut, DataLen); 
    out_len = RTK_RCP_DO_CRYPTION((EnDe) ? RCP_CAM_256_CTR_ENC : RCP_CAM_256_CTR_DEC, NULL, 16,
                                                    pDataIn, pDataOut, DataLen);        
    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return out_len;
}
/*======================================================================
 * Func : _RCP_SET_CW
 *
 * Desc : Set Control Word to CW Area
 *
 * Parm : id   : CW Entry offset
 *        pCW  : CW data
 *        len  : size of CW data
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
static int _RCP_SET_CW(unsigned int id, unsigned char* pCW, unsigned int len)
{
    unsigned long flags;
    int ret = -1;
    int cw_entries = (len - 1) / 8 + 1;
    if(len == 0 || pCW == NULL || id == 0 ||
       id > MAX_CW_ENTRY || (id + cw_entries) > (MAX_CW_ENTRY + 1))
        return ret;

    RTK_RCP_LOCK(rtk_rcp_cw_lock, flags);
#ifdef CONFIG_RTK_KDRV_CW
    ret = rtk_cw_request_multi_cws(RCP_CW_MODULE_NAME, id - 1, cw_entries);
    if(ret != 0)
        goto FAIL_REQUEST_CWS;
    ret = rtk_cw_set_cw(RCP_CW_MODULE_NAME, id - 1, pCW, len);
    if(ret != 0)
        goto FAIL_SET_CWS;
FAIL_SET_CWS:
    rtk_cw_release_cw_by_module(RCP_CW_MODULE_NAME);
FAIL_REQUEST_CWS:
#endif
    RTK_RCP_UNLOCK(rtk_rcp_cw_lock, flags);
    return ret;

}




/*======================================================================
 * Func : _RCP_GET_CW
 *
 * Desc : Get Control Word from CW Area
 *
 * Parm : id   : CW Entry offset
 *        pCW  : CW data output
 *        len  : size of CW data to read
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
static int _RCP_GET_CW(unsigned int id, unsigned char* pCW, unsigned int len)
{
    unsigned long flags;
    int ret = -1;
    int cw_entries = (len - 1) / 8 + 1;
    if(len == 0 || pCW == NULL || id == 0 ||
       id > MAX_CW_ENTRY || (id + cw_entries) > (MAX_CW_ENTRY + 1))
        return ret;

    RTK_RCP_LOCK(rtk_rcp_cw_lock, flags);
#ifdef CONFIG_RTK_KDRV_CW
    ret = rtk_cw_request_multi_cws(RCP_CW_MODULE_NAME, id - 1, cw_entries);
    if(ret != 0)
        goto FAIL_REQUEST_CWS;
    ret = rtk_cw_get_cw(RCP_CW_MODULE_NAME, id - 1, pCW, len);
    if(ret != 0)
        goto FAIL_SET_CWS;
FAIL_SET_CWS:
    rtk_cw_release_cw_by_module(RCP_CW_MODULE_NAME);
FAIL_REQUEST_CWS:
#endif
    RTK_RCP_UNLOCK(rtk_rcp_cw_lock, flags);
    return ret;
}

static void change_array_endian(unsigned char * content, unsigned int len)
{
    int loop = 0;
    int i = 0;
    if(content == NULL || len == 0)
        return;
    loop = len / 8;
    for(i = 0; i < loop; i++) {
        int j = 0;
        for(j = 0; j < 4; j++) {
            unsigned char tmp = content[i * 8 + j];
            content[i * 8 + j] = content[i * 8 + 8 - j - 1];
            content[i * 8 + 8 - j - 1] = tmp;
        }
    }   
}


/*======================================================================
 * Func : RCP_GET_CW
 *
 * Desc : Get Control Word from CW Area
 *
 * Parm : id   : CW Entry offset
 *        pCW  : CW data output
 *        len  : size of CW data to read
 *
 * Retn : S_OK /  S_FALSE
 *======================================================================*/
int RTK_RCP_GET_CW(unsigned int id, unsigned char* pCW, unsigned int len)
{
    int ret = -1;
    int cw_entries = (len - 1) / 8 + 1;
    unsigned char *content = pCW;
    unsigned int content_len = len;
    if(pCW == NULL || len == 0 || id == 0 || id > MAX_CW_ENTRY ||
                (id + cw_entries) > (MAX_CW_ENTRY + 1))
        return ret;
    if(len & 0x7) {
        content_len = cw_entries * 8;
        content = (unsigned char *)kmalloc(content_len, GFP_ATOMIC);
        if(!content)
            return ret;
    }

    ret = _RCP_GET_CW(id, content, content_len);
    if(ret == 0) {
        change_array_endian(content, content_len);
        if(len & 0x7)
            memcpy(pCW, content, len);
    }
    if(len & 0x7)
        kfree(content);
    return ret;
}

int RTK_RCP_SET_CW(unsigned int id, unsigned char* pCW, unsigned int len)
{
    int ret = -1;
    int cw_entries = (len - 1) / 8 + 1;
    unsigned char *content = pCW;
    unsigned int content_len = len;
    if(pCW == NULL || len == 0 || id == 0 || id > MAX_CW_ENTRY ||
                (id + cw_entries) > (MAX_CW_ENTRY + 1))
        return ret;
    /*The endian of cw driver is not the same as the origin API,
    *
    * CW    4 5 6 7 0 1 2 3
    * HDCP 3 2 1 0 7 6 5 4
    */
    content_len = cw_entries * 8;
    content = (unsigned char *)kmalloc(content_len, GFP_ATOMIC);
    if(!content)
        return ret;
    memset(content, 0, content_len);
    memcpy(content, pCW, len);

    change_array_endian(content, content_len);
        
    ret = _RCP_SET_CW(id, content, content_len) ;
    
    kfree(content);
    return ret;

}



static int RTK_RCP_CW_LOGIC_OP(RCP_CW_LOGIC_MODE_TYPE cw_logic_mode, int CwIn1, int CwIn2, int CwOut)
{
    unsigned long flags;
    unsigned char tmp_data[16];
    if(CwIn1 <= 0 || CwIn1 > MAX_CW_ENTRY || CwIn2 <= 0 ||
       CwIn2 > MAX_CW_ENTRY || CwOut <= 0 || CwOut > MAX_CW_ENTRY)
        return 0;
    RTK_RCP_LOCK(rtk_rcp_lock, flags);

    switch(cw_logic_mode) {
        case CW_LOGIC_MODE_AND:
            SET_CP_REG_MOD_SET(RCP_CW_LOGIC_OPSEL_AND);
            break;
        case CW_LOGIC_MODE_OR:
            SET_CP_REG_MOD_SET(RCP_CW_LOGIC_OPSEL_OR);
            break;
        case CW_LOGIC_MODE_XOR:
            SET_CP_REG_MOD_SET(RCP_CW_LOGIC_OPSEL_XOR);
            break;
        default:
            RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
            return 0;
    }
    SET_CP_REG_MOD_SET1(REG_SET1_KEY_MODE_CW | REG_SET1_IV_MODE_CW | REG_SET1_OUTPUT_MODE_CW);
    SET_CP_REG_MOD_SET2(REG_SET2_KEY_ENTRY(CwIn1 - 1) | REG_SET2_IV_ENTRY(CwIn2 - 1) | REG_SET2_OUTPUT_ENTRY(CwOut - 1));
    SET_CP_REG_MOD_DATAIN(3, 0);// triger computation
    rtk_rcp_get_reg_array(RCP_REG_TYPE_DATAOUT, 1, tmp_data, 1);                // wait complete

    RTK_RCP_UNLOCK(rtk_rcp_lock, flags);
    return 1;
}

int RTK_RCP_CW_XOR(int CwIn1, int CwIn2, int CwOut)
{
    return RTK_RCP_CW_LOGIC_OP(CW_LOGIC_MODE_XOR, CwIn1, CwIn2, CwOut);
}


int rtk_rcp_do_command(RCP_DESC * p_desc)
{
    int ret = -1;
    if(p_desc == NULL)
        return ret;
    switch(RCP_MODE(p_desc->flags)) {
        case RCP_ALGO_AES: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_AES_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_AES_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_AES_CTR_Cipher_ex(1, p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len, p_desc->addr_align);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_AES_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_AES_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_AES_CTR_Cipher_ex(0, p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len, p_desc->addr_align);
                        break;
                }
            }
            break;
        }

        case RCP_ALGO_DES: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_DES_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_DES_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_DES_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_DES_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }
        case RCP_ALGO_TDES: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_TDES_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                          p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_TDES_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                          p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_TDES_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                          p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_TDES_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                          p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }

        case RCP_ALGO_AES_192: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_AES_192_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_AES_192_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_AES_192_CTR_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_AES_192_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_AES_192_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_AES_192_CTR_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }

        case RCP_ALGO_AES_256: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_AES_256_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_AES_256_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_AES_256_CTR_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_AES_256_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_AES_256_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_AES_256_CTR_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }
        
        case RCP_ALGO_CAM: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_CAM_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_CAM_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_CAM_CTR_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_CAM_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_CAM_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_CAM_CTR_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }

        case RCP_ALGO_CAM_192: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_CAM_192_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_CAM_192_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_CAM_192_CTR_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_CAM_192_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_CAM_192_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_CAM_192_CTR_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }

        case RCP_ALGO_CAM_256: {
            if(RCP_ENDE(p_desc->flags) == RCP_ENC) {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_CAM_256_ECB_Encryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_CAM_256_CBC_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_CAM_256_CTR_Encryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            } else {
                switch(RCP_BCM(p_desc->flags)) {
                    case RCP_BCM_ECB:
                        ret = RTK_RCP_CAM_256_ECB_Decryption(p_desc->key, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CBC:
                        ret = RTK_RCP_CAM_256_CBC_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                    case RCP_BCM_CTR:
                        ret = RTK_RCP_CAM_256_CTR_Decryption(p_desc->key, p_desc->iv, p_desc->data_in,
                                                         p_desc->data_out, p_desc->len);
                        break;
                }
            }
            break;
        }

        case RCP_ALGO_CW_LOGIC: {
            switch(RCP_CW_LOGIC(p_desc->flags)) {
                case RCP_CW_LOGIC_XOR:
                    ret = RTK_RCP_CW_XOR(p_desc->key, p_desc->iv, p_desc->data_out);
                    break;
                default:
                    ret = 0;
                    break;
            }
            break;
        }
        case RCP_ALGO_CW_OPSEL: {
            switch(RCP_CW_OPSEL(p_desc->flags)) {
                case GET_CW:
                    ret = _RCP_GET_CW(p_desc->data_in, p_desc->data_out, p_desc->len);
                    ret = (ret == 0) ? p_desc->len : 0;
                    break;
                case SET_CW:
                    ret = _RCP_SET_CW(p_desc->data_out, p_desc->data_in, p_desc->len);
                    ret = (ret == 0) ? p_desc->len : 0;
                    break;
            }
            break;
        }

    }
    if(ret != 0) {
        p_desc->out_len = ret;
        ret = 0;
    } else {
        ret = -1;
    }
    return ret;
}

static int __init rtk_rcp_core_init(void)
{
    return 0;
}

static void rtk_rcp_core_exit(void)
{

}


static int __init rtk_rcp_module_init(void)
{
    int ret;
    ret = rtk_rcp_core_init();
    if(ret != 0) {
        goto FAIL_RCP_CORE_INIT;
    }
    ret = rtk_rcp_dev_init();
    if(ret != 0) {
        goto FAIL_RCP_DEV_INIT;
    }
    RCP_INFO("rcp driver init sucess\n");
    return 0;
FAIL_RCP_DEV_INIT:
    rtk_rcp_core_exit();
FAIL_RCP_CORE_INIT:
    return ret;
}


static void __exit rtk_rcp_module_exit(void)
{
    RCP_INFO("rcp driver exit\n");
    rtk_rcp_dev_exit();
}

module_init(rtk_rcp_module_init);
module_exit(rtk_rcp_module_exit);


