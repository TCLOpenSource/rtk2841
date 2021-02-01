#include <linux/kernel.h>
#include <linux/printk.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/mutex.h>
#include <rtk_kdriver/rtk_otp_util.h>
#include "rtk_otp_reg.h"

#define WRITE_REG32(addr, val)      rtd_outl((addr), val)
#define READ_REG32(addr)            rtd_inl((addr))
#define OTP_BIT_MASK(i)             (0xFFFFFFFF >> (32-(i)))

static DEFINE_MUTEX(otp_r_mutex);
static DEFINE_MUTEX(otp_w_mutex);

/*-----------------------------------------------------------------------------
 * Func : _otp_get_bits
 *
 * Desc : get specified bits
 *
 * Parm :
 *
 * Retn :
 *-----------------------------------------------------------------------------*/
int _otp_get_bits(unsigned int *pval, unsigned char msb, unsigned char lsb)
{
    if (msb < lsb || lsb > 31 || msb > 31)
        return -1;
    *pval >>= lsb;
    *pval &= OTP_BIT_MASK(msb - lsb + 1);
    return 0;
}

/*-----------------------------------------------------------------------------
* Func : _otp_is_readable
*
* Desc : Test if the OTP Reg you want to read is readable
*
* Parm : ofst : byte offsets, it should be 4 bytes alignments
*
* Retn : 0: can read;1 can't read.
*-----------------------------------------------------------------------------*/
int _otp_is_readable(unsigned int ofst)
{
#ifndef ENABLE_SECURE_CPU
    if(ofst < 0x28)
        return -1;
    else if((ofst >= 0xA4) && (ofst < 0xCC))
        return -1;
    else if((ofst >= 0x1A4) && (ofst < 0x1F4))
        return -1;
#endif
    return 0;
}

static int _otp_read(unsigned int ofst, unsigned int* pval)
{
    if (_otp_is_readable(ofst) == -1) {
        *pval = 0xdeaddead;
    } else {
        mutex_lock(&otp_r_mutex);
        WRITE_REG32(OTP_DOUBLE_BIT_READ, OTP_DOUBLE_BIT_READ_WRITE_ENABLE0 | OTP_AUTO_DOUBLE_BIT_READ);
        *pval = READ_REG32(OTP_DDR_MAP_BASE + ofst);
        mutex_unlock(&otp_r_mutex);
    }
    return 0;
}

/*-----------------------------------------------------------------------------
* Func : otp_read
*
* Desc : read OTP word
*
* Parm : ofst : byte offsets, it should be 4 bytes alignments
*
* Retn : OTP words
*-----------------------------------------------------------------------------*/
int otp_read(unsigned int ofst, unsigned int *pval)
{
    if (ofst & 0x3) {
        OTP_WARNING("read otp failed, ofst 0x%08lx is not 4 bytes alignments\n", ofst);
        return -1;
    }
    return _otp_read(ofst, pval);
}


/*-----------------------------------------------------------------------------
 * Func : otp_read_region
 *
 * Desc : read OTP region
 *
 * Parm : ofst : byte offsets, it should be 4 bytes alignments
 *
 * Retn : OTP words
 *-----------------------------------------------------------------------------*/
int otp_read_region(unsigned int ofst, unsigned int *data, int len)
{
    int i = 0;
    if (ofst & 0x3) {
        OTP_WARNING("read otp region failed, ofst 0x%08lx is not 4 bytes alignments\n", ofst);
        return -1;
    }
    if (data == NULL || len < 0)
        return -1;
    for (i = 0; i < len; i++) {
        if (otp_read(ofst, (unsigned int *)data) != 0) {
            return -1;
        }
        ofst += sizeof(unsigned int);
        data++;
    }
    return 0;
}

/*-----------------------------------------------------------------------------
 * Func : otp_read_region_byte
 *
 * Desc : read OTP region
 *
 * Parm : ofst : byte offsets, it should be 4 bytes alignments
 *
 * Retn : OTP words
 *-----------------------------------------------------------------------------*/
int otp_read_region_byte(unsigned int ofst,
                         unsigned char *data, int len)
{
    unsigned char *tmp = data;
    if (tmp == NULL || len < 0) {
        OTP_WARNING("otp program region failed, params are input error\n");
        return -1;
    }
    /*if ofst is not align by 4 bytes,should seperate read the ualigned parts*/
    if ((ofst & 0x3) && len > 0) {
        unsigned int val = 0;
        unsigned char start_byte = (ofst & 0x3);
        unsigned char read_len = ((len >= sizeof(unsigned int) - start_byte)) ? (sizeof(unsigned int) - start_byte) : len;
        otp_read(ofst - start_byte, &val);
        ofst += read_len;
        len -= read_len;
        val = val >> (start_byte * 8);
        while (read_len > 0) {
            *tmp = val & 0xFF;
            val >>= 8;
            tmp++;
            read_len--;
        }
        if (len <= 0)
            return 0;

    }

    if (len / sizeof(int) > 0) {
        int read_len = len / sizeof(int);
        unsigned int val = 0;
        while (read_len > 0) {
            unsigned char times = 4;
            otp_read(ofst, &val);
            while (times > 0) {
                *tmp = val & 0xFF;
                tmp++;
                val >>= 8;
                times--;
            }
            ofst += sizeof(unsigned int);
            read_len--;
        }
        len = len - (len / sizeof(int)) * sizeof(int);
    }
    if (len > 0) {
        unsigned int val = 0;
        otp_read(ofst, &val);
        while (len > 0) {
            *tmp = val & 0xFF;
            val >>= 8;
            tmp++;
            ofst += 1;
            len--;
        }
    }
    return 0;
}

/*-----------------------------------------------------------------------------
 * Func : otp_read_bits
 *
 * Desc : read OTP bits
 *
 * Parm : ofst : byte offsets, it should be 4 bytes alignments
 *
 * Retn : OTP words
 *-----------------------------------------------------------------------------*/
int otp_read_bits(unsigned int ofst, unsigned char msb,
                  unsigned char lsb, unsigned int *pval)
{
    int ret = otp_read(ofst, pval);

    if (ret == 0 && *pval != 0xdeaddead)    /* do not mask bits if it is non readable*/
        ret = _otp_get_bits(pval, msb, lsb);
    return ret;
}

/*-----------------------------------------------------------------------------
 * Func : otp_crc_auto_region
 *
 * Desc : opt crc auto region
 *
 * Parm : pval:pval:the address of the crc value
 *
 * Retn : OTP words
 *-----------------------------------------------------------------------------*/

int otp_crc_auto_region(unsigned int *pval)
{
    return otp_crc_partial_region(0x0, MAX_OTP_OFST, pval);
}


/*-----------------------------------------------------------------------------
 * Func : otp_crc_partial_region
 *
 * Desc : otp_crc_partial_region
 *
 * Parm : start_ofst:the offset of start reg you want to verify.
 *      end_ofst:the offset of end reg you want to verify.
 *      pval:the address of the crc value
 * Retn : OTP words
 *-----------------------------------------------------------------------------*/
int otp_crc_partial_region(unsigned int start_ofst, unsigned int len, unsigned int *pval)
{
    int ret = -1;
    int times = 200;
    if (start_ofst >= MAX_OTP_OFST || (start_ofst + len) > MAX_OTP_OFST || pval == NULL) {
        OTP_WARNING("params are input error\n");
        return ret;
    }
    mutex_lock(&otp_w_mutex);
    WRITE_REG32(OTP_CRC, OTP_CRC_CRC_INI);
    OTP_DBG("[%s,%d,%s]0x%08x = 0x%08x\n", __FILE__, __LINE__, __FUNCTION__, OTP_CRC, READ_REG32(OTP_CRC));

    WRITE_REG32(OTP_AUTO_RD_REGION, OTP_AUTO_RD_REGION_START_ADDR(start_ofst)
                | OTP_AUTO_RD_REGION_END_ADDR(start_ofst + len - 1));
    OTP_DBG("[%s,%d,%s]0x%08x = 0x%08x\n", __FILE__, __LINE__, __FUNCTION__, OTP_AUTO_RD_REGION, READ_REG32(OTP_AUTO_RD_REGION));

    WRITE_REG32(OTP_CTRL_CRC_EN, OTP_CRC_EN(1));
    OTP_DBG("[%s,%d,%s]0x%08x = 0x%08x\n", __FILE__, __LINE__, __FUNCTION__, OTP_CTRL_CRC_EN, READ_REG32(OTP_CTRL_CRC_EN));

    WRITE_REG32(OTP_CTRL, (OTP_CTRL_AUTO_RD_REQ | OTP_CTRL_WRITE_EN0));
    OTP_DBG("[%s,%d,%s]0x%08x = 0x%08x\n", __FILE__, __LINE__, __FUNCTION__, OTP_CTRL, READ_REG32(OTP_CTRL));

    while (times --) {
        unsigned int value = READ_REG32(OTP_CTRL);
        if (!(value & OTP_CTRL_AUTO_RD_REQ)) {
            ret = 0;
            break;
        }
        udelay(1000);
    }
    if (ret == 0)
        *pval = GET_OTP_CRC_CRC_OUT(READ_REG32(OTP_CRC));
    WRITE_REG32(OTP_CTRL_CRC_EN, OTP_CRC_EN(0));
    mutex_unlock(&otp_w_mutex);
    return ret;
}

