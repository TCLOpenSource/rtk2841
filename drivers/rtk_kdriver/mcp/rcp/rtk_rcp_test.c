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
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/dma-mapping.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/notifier.h>
#include <linux/list.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <mach/irqs.h>
#include <mach/platform.h>
#include <asm/mutex.h>
#include <mach/io.h>
#include <rtk_kdriver/mcp/rtk_rcp.h>
#include "rtk_rcp_dbg.h"
#include "rtk_rcp_dev.h"
#include "rtk_rcp_reg.h"
#include "rtk_rcp_defines.h"


/***************************************************************************
            ------------------- Auto Test ----------------
****************************************************************************/

static int RTK_RCP_PrintCheckReuslt(unsigned int enc, unsigned char* pRefData, unsigned char* pOutData,
                                    unsigned int OutDataLen, const char *msg, const char *fun)
{

    if(enc == 1) {
        rtk_rcp_dump_data_with_text(pRefData, OutDataLen, "Expect  : ");
        rtk_rcp_dump_data_with_text(pOutData, OutDataLen, "Encrypt : ");
    } else {
        rtk_rcp_dump_data_with_text(pOutData, OutDataLen, "Decrypt : ");
    }

    if (strncmp(pRefData, pOutData, OutDataLen) != 0 ) { /* output not equual to except output */
        printk("\033[0;32;31m" "%s %s %s Fail!\n""\033[m", msg, fun, enc ? "Enc" : "Dec");
        return 1;
    } else {
        printk("\033[0;32;34m" "%s %s %s Sucess!\n""\033[m" , msg, fun, enc ? "Enc" : "Dec");
    }

    return 0;
}



/*------------------------------------------------------------------
* Func : RTK_RCP_DES_ECB_Test
*
* Desc : DES ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_DES_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xa3, 0x2a, 0xd8, 0xac, 0xd2, 0x0c, 0x38, 0xfc, 0x28, 0x51, 0x07, 0x7e, 0x16, 0xf6, 0x38, 0x75};
    unsigned char  Key[7];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP DES ECB ===============================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_DES_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[1.1.1]", __FUNCTION__);

    RTK_RCP_DES_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[1.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_DES_CBC_Test
*
* Desc : DES CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_DES_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x03, 0xd3, 0x76, 0x73, 0xa2, 0x79, 0x50, 0xd1, 0x76, 0x7a, 0x78, 0x3c, 0x47, 0x5b, 0x6a, 0x0a};
    unsigned char  Key[7];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP DES CBC ===============================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_DES_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[1.2.1]", __FUNCTION__);

    RTK_RCP_DES_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[1.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : rcp_TDES_ECB_Test
*
* Desc : TDES ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_TDES_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xa3, 0x2a, 0xd8, 0xac, 0xd2, 0x0c, 0x38, 0xfc, 0x28, 0x51, 0x07, 0x7e, 0x16, 0xf6, 0x38, 0x75};
    unsigned char  Key[21];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================= TDES ECB ==============================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_TDES_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[2.1.1]", __FUNCTION__);

    RTK_RCP_TDES_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[2.1.2] ", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : rcp_TDES_CBC_Test
*
* Desc : TDES CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_TDES_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x03, 0xd3, 0x76, 0x73, 0xa2, 0x79, 0x50, 0xd1, 0x76, 0x7a, 0x78, 0x3c, 0x47, 0x5b, 0x6a, 0x0a};
    unsigned char  Key[21];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================= TDES CBC ==============================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_TDES_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[2.2.1] ", __FUNCTION__);

    RTK_RCP_TDES_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[2.2.2]", __FUNCTION__);

    return ret;
}


/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_ECB_Test
*
* Desc : AES-128 ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_128_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x45, 0xd7, 0x4d, 0xac, 0xb3, 0x52, 0xf9, 0x3f, 0xd3, 0x09, 0xbf, 0x8b, 0x91, 0x59, 0xdf, 0x58};
    unsigned char  Key[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("==========================RCP AES-128 ECB ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[3.1.1]", __FUNCTION__);

    RTK_RCP_AES_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[3.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_CBC_Test
*
* Desc : AES-128 CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_128_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x9a, 0x6c, 0x86, 0xce, 0xc3, 0x31, 0xdd, 0xb0, 0x14, 0x2c, 0xfb, 0x37, 0x06, 0x25, 0xbf, 0xfe};
    unsigned char  Key[16];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================== RCP AES-128 CBC ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[3.2.1]", __FUNCTION__);

    RTK_RCP_AES_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[3.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_CTR_Test
*
* Desc : AES-128 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_128_CTR_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xd7, 0x9d, 0xe0, 0x8a, 0xbe, 0xa9, 0xa2, 0xc8, 0xf7, 0xf1, 0x85, 0xc7, 0x72, 0x57, 0x2e, 0xb5};
    unsigned char  Key[16];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP AES-128 CTR ===========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_CTR_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[3.3.1]", __FUNCTION__);

    memset(IV , 0x22, BlockSize);
    RTK_RCP_AES_CTR_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[3.3.2]", __FUNCTION__);

    return ret;
}


/*------------------------------------------------------------------
* Func : RTK_RCP_AES_192_ECB_Test
*
* Desc : AES-192 ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_192_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x3D, 0xA3, 0x68, 0x1F, 0x1E, 0xFE, 0x06, 0xB1, 0xCF, 0x3A, 0x89, 0x66, 0x04, 0x7B, 0x2F, 0x63};
    unsigned char  Key[24] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44};
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("==========================RCP AES-192 ECB ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_192_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[4.1.1]", __FUNCTION__);

    RTK_RCP_AES_192_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[4.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_CBC_Test
*
* Desc : AES-128 CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_192_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x08, 0x1C, 0x30, 0xEA, 0xA6, 0xED, 0x9E, 0x93, 0x02, 0x59, 0xDB, 0x27, 0xF0, 0x60, 0xC5, 0x31};
    unsigned char  Key[24] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66,
                              0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44
                             };
    unsigned char  IV[16] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0xaa, 0xbb, 0xcc, 0xdd};
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================== RCP AES-192 CBC ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_192_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[4.2.1]", __FUNCTION__);

    RTK_RCP_AES_192_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[4.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_CTR_Test
*
* Desc : AES-128 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_192_CTR_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x9f, 0xe3, 0xc0, 0xbc, 0xa6, 0x65, 0x19, 0x89, 0xbd, 0x96, 0x2e, 0xb5, 0xf8, 0x46, 0xac, 0x31};
    unsigned char  Key[24] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66,
                              0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44
                             };
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP AES-192 CTR ===========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_192_CTR_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[4.3.1]", __FUNCTION__);

    RTK_RCP_AES_192_CTR_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, Data, DecData, BlockSize, "[4.3.2]", __FUNCTION__);

    return ret;
}


/*------------------------------------------------------------------
* Func : RTK_RCP_AES_192_ECB_Test
*
* Desc : AES-192 ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_256_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x76, 0xFB, 0xD8, 0x07, 0x6B, 0x21, 0x20, 0x82, 0xD5, 0x8D, 0xE6, 0x97, 0x3A, 0x17, 0x1C, 0x5D};
    unsigned char  Key[32] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66,
                              0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22
                             };
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("==========================RCP AES_256 ECB ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_256_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[5.1.1]", __FUNCTION__);

    RTK_RCP_AES_256_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[5.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_CBC_Test
*
* Desc : AES-128 CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_256_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xA5, 0xBD, 0x95, 0xA8, 0xD4, 0x59, 0xEC, 0xCE, 0x55, 0xD0, 0xE3, 0xBC, 0xF7, 0x98, 0xC2, 0xC0};
    unsigned char  Key[32] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66,
                              0x77, 0x88, 0x99, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00, 0x11, 0x22
                             };
    unsigned char  IV[16] = {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0xaa, 0xbb, 0xcc, 0xdd};
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================== RCP AES_256 CBC ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_256_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[5.2.1]", __FUNCTION__);

    RTK_RCP_AES_256_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[5.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_AES_128_CTR_Test
*
* Desc : AES-128 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_AES_256_CTR_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xf5, 0x89, 0xa3, 0xe5, 0x91, 0x82, 0x02, 0x08, 0xa0, 0xea, 0xb1, 0x81, 0x66, 0x7e, 0x20, 0x04};
    unsigned char  Key[32];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP AES_256 CTR ===========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_AES_256_CTR_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[5.3.1]", __FUNCTION__);

    RTK_RCP_AES_256_CTR_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, Data, DecData, BlockSize, "[5.3.2]", __FUNCTION__);

    return ret;
}


/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_128_ECB_Test
*
* Desc : CAM-128 ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_128_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x4C, 0xE6, 0x0E, 0x91, 0x3F, 0x30, 0xAD, 0x46, 0x57, 0x58, 0x2B, 0x5F, 0x9D, 0x46, 0x77, 0x1D};
    unsigned char  Key[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("==========================RCP CAM-128 ECB ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[6.1.1]", __FUNCTION__);

    RTK_RCP_CAM_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[6.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_128_CBC_Test
*
* Desc : CAM-128 CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_128_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xE9, 0x1F, 0xF6, 0x46, 0x88, 0x64, 0x1F, 0x57, 0xF4, 0xEB, 0x2A, 0xCC, 0x7B, 0x7B, 0x6E, 0x59};
    unsigned char  Key[16];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================== RCP CAM-128 CBC ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[6.2.1]", __FUNCTION__);

    RTK_RCP_CAM_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[6.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_128_CTR_Test
*
* Desc : CAM-128 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_128_CTR_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xC8, 0xE4, 0xA6, 0x1B, 0x84, 0x8D, 0x8E, 0x32, 0xC0, 0x91, 0x34, 0x83, 0x6C, 0x91, 0x34, 0x31};
    unsigned char  Key[16];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP CAM-128 CTR ===========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_CTR_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[6.3.1]", __FUNCTION__);

    RTK_RCP_CAM_CTR_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, Data, DecData, BlockSize, "[6.3.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_192_ECB_Test
*
* Desc : CAM-192 ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_192_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x06, 0x97, 0x54, 0xB5, 0x17, 0xA8, 0xF4, 0xF1, 0x8F, 0x00, 0x76, 0x62, 0x7E, 0xFC, 0x6B, 0x59};
    unsigned char  Key[24];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("==========================RCP CAM-192 ECB ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_192_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[7.1.1]", __FUNCTION__);

    RTK_RCP_CAM_192_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[7.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_192_CBC_Test
*
* Desc : CAM-192 CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_192_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xBE, 0x14, 0x78, 0x8D, 0x88, 0x38, 0x9D, 0x7C, 0xE7, 0x71, 0xC9, 0x4B, 0xCF, 0x9F, 0x1C, 0x0A};
    unsigned char  Key[24];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================== RCP CAM-192 CBC ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_192_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[7.2.1]", __FUNCTION__);

    RTK_RCP_CAM_192_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[7.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_192_CTR_Test
*
* Desc : CAM-192 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_192_CTR_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x8C, 0x87, 0x80, 0xC8, 0x41, 0xC2, 0x45, 0x69, 0x36, 0xCE, 0x83, 0x88, 0xEA, 0xF5, 0x70, 0xAE};
    unsigned char  Key[24];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP CAM-192 CTR ===========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_192_CTR_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[7.3.1]", __FUNCTION__);

    RTK_RCP_CAM_192_CTR_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, Data, DecData, BlockSize, "[7.3.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_256_ECB_Test
*
* Desc : CAM-256 ECB Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_256_ECB_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x63, 0xF2, 0x81, 0x94, 0x51, 0x46, 0x71, 0x9F, 0x8F, 0x70, 0xDA, 0x4F, 0xC1, 0x80, 0x6C, 0x26};
    unsigned char  Key[32];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("==========================RCP CAM-256 ECB ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_256_ECB_Encryption(Key, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[8.1.1]", __FUNCTION__);

    RTK_RCP_CAM_256_ECB_Decryption(Key, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[8.1.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_256_CBC_Test
*
* Desc : CAM-256 CBC Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_256_CBC_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0x9C, 0x0B, 0xA0, 0x2E, 0x32, 0xB1, 0xCC, 0xB7, 0x39, 0xA3, 0x67, 0xB6, 0x8C, 0x18, 0x2F, 0xFB};
    unsigned char  Key[32];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("========================== RCP CAM-256 CBC ==========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_256_CBC_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[8.2.1]", __FUNCTION__);

    RTK_RCP_CAM_256_CBC_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(0, Data, DecData, BlockSize, "[8.2.2]", __FUNCTION__);

    return ret;
}

/*------------------------------------------------------------------
* Func : RTK_RCP_CAM_256_CTR_Test
*
* Desc : CAM-256 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CAM_256_CTR_Test(void)
{
    unsigned int   BlockSize = 16;
    unsigned char  Data[16] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x00};
    unsigned char  RefD[16] = {0xE9, 0x56, 0x6A, 0xB9, 0x23, 0xC4, 0xD9, 0x98, 0x6B, 0x90, 0x17, 0x80, 0x19, 0xB2, 0x38, 0x0B};
    unsigned char  Key[32];
    unsigned char  IV[16];
    unsigned char  EncData[16];
    unsigned char  DecData[16];
    int ret = 0;

    printk("=========================RCP CAM-256 CTR ===========================\n");
    rtk_rcp_dump_data_with_text(Data, BlockSize, "Input   : ");
    memset(Key, 0xff, sizeof(Key));
    memset(IV , 0x22, BlockSize);
    memset(EncData, 0x00, BlockSize);
    memset(DecData, 0x00, BlockSize);

    RTK_RCP_CAM_256_CTR_Encryption(Key, IV, Data, EncData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, RefD, EncData, BlockSize, "[8.3.1]", __FUNCTION__);

    RTK_RCP_CAM_256_CTR_Decryption(Key, IV, EncData, DecData, BlockSize);
    ret += RTK_RCP_PrintCheckReuslt(1, Data, DecData, BlockSize, "[8.3.2]", __FUNCTION__);

    return ret;
}



/*------------------------------------------------------------------
* Func : RTK_RCP_CW_XOR_Test
*
* Desc : AES-128 CTR Encrypt Decrypt Test
*
* Parm : Void
*
* Retn : Fail Count
*------------------------------------------------------------------*/
int RTK_RCP_CW_XOR_Test(void)
{
    unsigned char  CW1[8] = {0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF};
    unsigned char  CW2[8] = {0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00};
    unsigned char  CWout[8];
    unsigned char  RefD[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    int ret = 0;

    printk("=========================RCP CW XOR===========================\n");

    RTK_RCP_SET_CW(120, CW1, 8);
    RTK_RCP_GET_CW(120, CWout, 8);
    rtk_rcp_dump_data_with_text(CWout, 8, "CW1   : ");

    RTK_RCP_SET_CW(121, CW2, 8);
    RTK_RCP_GET_CW(121, CWout, 8);
    rtk_rcp_dump_data_with_text(CWout, 8, "CW2   : ");
    RTK_RCP_CW_XOR(120, 121, 122);
    RTK_RCP_GET_CW(122, CWout, 8);

    ret += RTK_RCP_PrintCheckReuslt(1, RefD, CWout, 8, "[9.1.1]", __FUNCTION__);

    return ret;
}


void do_rcp_function_test(void)
{
    int ErrorCount = 0;
    ErrorCount += RTK_RCP_DES_ECB_Test();
    ErrorCount += RTK_RCP_DES_CBC_Test();
    ErrorCount += RTK_RCP_TDES_ECB_Test();
    ErrorCount += RTK_RCP_TDES_CBC_Test();
    ErrorCount += RTK_RCP_AES_128_ECB_Test();
    ErrorCount += RTK_RCP_AES_128_CBC_Test();
    ErrorCount += RTK_RCP_AES_128_CTR_Test();
    ErrorCount += RTK_RCP_AES_192_ECB_Test();
    ErrorCount += RTK_RCP_AES_192_CBC_Test();
    ErrorCount += RTK_RCP_AES_192_CTR_Test();
    ErrorCount += RTK_RCP_AES_256_ECB_Test();
    ErrorCount += RTK_RCP_AES_256_CBC_Test();
    ErrorCount += RTK_RCP_AES_256_CTR_Test();

    ErrorCount += RTK_RCP_CAM_128_ECB_Test();
    ErrorCount += RTK_RCP_CAM_128_CBC_Test();
    ErrorCount += RTK_RCP_CAM_128_CTR_Test();
    ErrorCount += RTK_RCP_CAM_192_ECB_Test();
    ErrorCount += RTK_RCP_CAM_192_CBC_Test();
    ErrorCount += RTK_RCP_CAM_192_CTR_Test();
    ErrorCount += RTK_RCP_CAM_256_ECB_Test();
    ErrorCount += RTK_RCP_CAM_256_CBC_Test();
    ErrorCount += RTK_RCP_CAM_256_CTR_Test();

    ErrorCount += RTK_RCP_CW_XOR_Test();

    if(ErrorCount == 0) {
        printk("\nTest All Success\nTest All Success\n");
    } else {
        printk("\nTest Fail Count %d\nTest Fail Count %d\n", ErrorCount, ErrorCount);
    }
}


int do_rcp_help(void)
{
    RCP_WARNING("----------------- rcp test command set --------------\n");
    RCP_WARNING(" do_help : print help message \n");
    RCP_WARNING(" do_rcp_burst_test : do burst test (to issue command burst) \n");
    RCP_WARNING(" do_rcp_error_test : do error test (to test mcp error handling and recovery procedure) \n");
    RCP_WARNING(" do_rcp_function_test : do function test (to test mcp function test) \n");
    RCP_WARNING(" do_rcp_throughput_test : do throughput test (to test mcp throughput) \n");
    RCP_WARNING(" do_dump_desc : do dump_desc  (to dump the content of desc) \n");
    RCP_WARNING(" do_dump_fifo : do dump_fifo  (to dump the content of fifo) \n");
    return 0;
}







