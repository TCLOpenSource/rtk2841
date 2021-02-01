/************************************************************************
 *
 *  otp_reg.h
 *
 *  Public header file for Nike OTP module
 *
 ************************************************************************/
#ifndef OTP_REG_H
#define OTP_REG_H

#define MAX_OTP_OFST            (0x200)
#define OTP_DDR_MAP_BASE        (0xB8038000)
#define OTP_REG_BASE            (0xB8038200)
#define OTP_CTRL_PROG           (0xB8038200)
#define OTP_PROG_STATUS1        (0xB8038204)
#define OTP_PROG_STATUS2        (0xB8038208)
#define OTP_PROG_STATUS3        (0xB803820C)
#define OTP_CTRL                (0xB8038218)
#define OTP_CTRL_CRC_EN         (0xB8038220)
#define OTP_CRC                 (0xB8038224)
#define OTP_AUTO_RD_REGION      (0xB8038228)
#define OTP_DOUBLE_BIT_READ     (0xB803823C)

#define OTP_CTRL_PROG_DOUBLE_BIT_PROG   (1 << 17)
#define OTP_CTRL_PROG_AUTO_REPAIRED_EN  (1 << 16)
#define OTP_CTRL_PROG_EN_PROG_EFUSE     (0xDEAD)

#define OTP_PROG_STATUS_DONE        (1 << 3)
#define OTP_PROG_STATUS_LOCK        (1 << 2)
#define OTP_PROG_STATUS_FAIL        (1 << 1)
#define OTP_PROG_STATUS_SUCCESS     (1 << 0)

#define OTP_CTRL_WRITE_EN0          (1 << 1)
#define OTP_CTRL_AUTO_RD_REQ        (1 << 0)

#define OTP_CRC_EN(x)               ((x) << 0)

#define OTP_AUTO_RD_REGION_START_ADDR(x)    ((x) & 0x1FF)
#define OTP_AUTO_RD_REGION_END_ADDR(x)      (((x) & 0x1FF) << 16)

#define OTP_DOUBLE_BIT_READ_WRITE_ENABLE1           (1 << 3)
#define OTP_DOUBLE_BIT_READ_COMPARE_METHOD(x)       ((x) << 2)
#define OTP_DOUBLE_BIT_READ_WRITE_ENABLE0           (1 << 1)
#define OTP_AUTO_DOUBLE_BIT_READ                    (1 << 0)

#define OTP_CRC_CRC_INI             (0xFFFF <<16)
#define GET_OTP_CRC_CRC_OUT(x)      ((x) & 0xFFFF)

#define OTP_DOUBLE_BIT_REG_BASE_OFST     (0xA4)

#endif /* #ifndef OTP_REG_H */
