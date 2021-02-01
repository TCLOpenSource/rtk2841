#ifndef __MCP_H__
#define __MCP_H__

#define MCP_DEV_FILE_NAME                       "mcp/core"
#define MCP_DESC_ENTRY_COUNT                    512
#define MCP_INTERRUPT_ENABLE

#define RTD294x_REG_BASE                        (0xB8000000)

/* =============================================================================== */
/*  REGISTER MAP                                                                                                                                   */
/* =============================================================================== */
#define RTD294x_MCP_CTRL                        (RTD294x_REG_BASE + 0x15100)
#define MCP_GO                                          (0x01 << 1)
#define MCP_IDEL                                        (0x01 << 2)
#define MCP_SWAP                                        (0x01 << 3)
#define MCP_CLEAR                                       (0x01 << 4)
/* 0 : run-robin for all
*  1 : run-robin for TP0/1 and put priotity as TP > MD > NF > MCP
*/
#define MCP_ARB_MODE(x)                                 ((x & 0x01)<<6)

#define RTD294x_MCP_STATUS                      (RTD294x_REG_BASE + 0x15104)
#define MCP_WRITE_DATA                                  (0x01 << 0)
#define MCP_RING_EMPTY                                  (0x01 << 1)
#define MCP_ERROR                                       (0x01 << 2)
#define MCP_COMPARE                                     (0x01 << 3)
#define MCP_ACP_ERR                                     (0x01 << 6)
#define MCP_K_RING_EMPTY                                (0x01 << 7)
#define MCP_K_COMPARE                                   (0x01 << 8)
#define MCP_K_ERROR                                     (0x01 << 9)

#define RTD294x_MCP_EN                          (RTD294x_REG_BASE + 0x15108)
#define RTD294x_MCP_CTRL1                       (RTD294x_REG_BASE + 0x15198)
#define MCP_ROUND_NO(x)                                 ((x & 0xFF))
#define MCP_CSA_ENTROPY(x)                              ((x & 0x3) << 8)
#define ORIGIONAL_MODE                                      (0x0)
#define CSA_MODE_1                                          (0x1)
#define CSA_MODE_2                                          (0x2)
#define MCP_AES_PAD_OFF(x)                              ((x & 0x1) << 10)

#define RTD294x_MCP_BASE                        (RTD294x_REG_BASE + 0x1510C)
#define RTD294x_MCP_LIMIT                       (RTD294x_REG_BASE + 0x15110)
#define RTD294x_MCP_RDPTR                       (RTD294x_REG_BASE + 0x15114)
#define RTD294x_MCP_WRPTR                       (RTD294x_REG_BASE + 0x15118)
#define RTD294x_MCP_DES_COUNT                   (RTD294x_REG_BASE + 0x15134)
#define RTD294x_MCP_DES_COMPARE                 (RTD294x_REG_BASE + 0x15138)
/* DES/TDES/MULTI2 Initial Vector */
#define RTD294x_MCP_DES_INI_KEY0                (RTD294x_REG_BASE + 0x1511C)
#define RTD294x_MCP_DES_INI_KEY1                (RTD294x_REG_BASE + 0x15120)
/* AES Initial Vector */
#define RTD294x_MCP_AES_INI_KEY0                (RTD294x_REG_BASE + 0x15124)
#define RTD294x_MCP_AES_INI_KEY1                (RTD294x_REG_BASE + 0x15128)
#define RTD294x_MCP_AES_INI_KEY2                (RTD294x_REG_BASE + 0x1512C)
#define RTD294x_MCP_AES_INI_KEY3                (RTD294x_REG_BASE + 0x15130)
/* Multi2 System Key */
#define RTD294x_MCP_MULTI2_SYS_KEY0             (RTD294x_REG_BASE + 0x15178)
#define RTD294x_MCP_MULTI2_SYS_KEY1             (RTD294x_REG_BASE + 0x1517C)
#define RTD294x_MCP_MULTI2_SYS_KEY2             (RTD294x_REG_BASE + 0x15180)
#define RTD294x_MCP_MULTI2_SYS_KEY3             (RTD294x_REG_BASE + 0x15184)
#define RTD294x_MCP_MULTI2_SYS_KEY4             (RTD294x_REG_BASE + 0x15188)
#define RTD294x_MCP_MULTI2_SYS_KEY5             (RTD294x_REG_BASE + 0x1518C)
#define RTD294x_MCP_MULTI2_SYS_KEY6             (RTD294x_REG_BASE + 0x15190)
#define RTD294x_MCP_MULTI2_SYS_KEY7             (RTD294x_REG_BASE + 0x15194)
#define RTD294x_CP_OTP_LOAD                     (RTD294x_REG_BASE + 0x1519C)
#define OTP_LOAD                                    (0x01 << 0)

#define RTD294x_CP_REG_KEY0                     (RTD294x_REG_BASE + 0x15034)
#define RTD294x_CP_REG_KEY1                     (RTD294x_REG_BASE + 0x15038)
#define RTD294x_CP_REG_KEY2                     (RTD294x_REG_BASE + 0x1503C)
#define RTD294x_CP_REG_KEY3                     (RTD294x_REG_BASE + 0x15040)
#define RTD294x_CP_REG_KEY4                     (RTD294x_REG_BASE + 0x15210)
#define RTD294x_CP_REG_KEY5                     (RTD294x_REG_BASE + 0x15214)
#define RTD294x_CP_REG_KEY6                     (RTD294x_REG_BASE + 0x15218)
#define RTD294x_CP_REG_KEY7                     (RTD294x_REG_BASE + 0x1521C)
#define RTD294x_CP_REG_DATA_IN0                 (RTD294x_REG_BASE + 0x15044)
#define RTD294x_CP_REG_DATA_IN1                 (RTD294x_REG_BASE + 0x15048)
#define RTD294x_CP_REG_DATA_IN2                 (RTD294x_REG_BASE + 0x1504C)
#define RTD294x_CP_REG_DATA_IN3                 (RTD294x_REG_BASE + 0x15050)
#define RTD294x_CP_REG_DATA_OUT0                (RTD294x_REG_BASE + 0x15054)
#define RTD294x_CP_REG_DATA_OUT1                (RTD294x_REG_BASE + 0x15058)
#define RTD294x_CP_REG_DATA_OUT2                (RTD294x_REG_BASE + 0x1505C)
#define RTD294x_CP_REG_DATA_OUT3                (RTD294x_REG_BASE + 0x15060)
#define RTD294x_CP_REG_DATA_OUT4                (RTD294x_REG_BASE + 0x15064)
#define RTD294x_CP_REG_DATA_OUT5                (RTD294x_REG_BASE + 0x15068)
#define RTD294x_CP_REG_DATA_OUT6                (RTD294x_REG_BASE + 0x1506C)
#define RTD294x_CP_REG_DATA_OUT7                (RTD294x_REG_BASE + 0x15070)

#define RTD294x_CP_REG_IV0                      (RTD294x_REG_BASE + 0x150D0)
#define RTD294x_CP_REG_IV1                      (RTD294x_REG_BASE + 0x150D4)
#define RTD294x_CP_REG_IV2                      (RTD294x_REG_BASE + 0x150D8)
#define RTD294x_CP_REG_IV3                      (RTD294x_REG_BASE + 0x150DC)
#define RTD294x_CP_REG_IV4                      (RTD294x_REG_BASE + 0x150E0)
#define RTD294x_CP_REG_IV5                      (RTD294x_REG_BASE + 0x150E4)
#define RTD294x_CP_REG_IV6                      (RTD294x_REG_BASE + 0x150E8)
#define RTD294x_CP_REG_IV7                      (RTD294x_REG_BASE + 0x150EC)

#define RTD294x_CP_REG_SET                      (RTD294x_REG_BASE + 0x15074)
#define RTD294x_CP_REG_SET1                     (RTD294x_REG_BASE + 0x15078)
#define RTD294x_CP_REG_SET2                     (RTD294x_REG_BASE + 0x1507C)

#define RTD294x_CP_SCTCH                        (RTD294x_REG_BASE + 0x15080)
/* REG0 default 0 */
#define MCP_SCTCH_REG0_DUMMY0                       (0x01 << 0)
#define MCP_SCTCH_REG0_DUMMY1                       (0x01 << 1)

/* =============================================================================== */
/*  Descriptor Definition                                                                                                                  */
/* =============================================================================== */
#if 0 // define in include/mach/mcp.h
#define MCP_BCM(x)                                  ((x & 0x03) << 6)
#define MCP_BCM_ECB                                     (0x00) //AES, DES/TDES
#define MCP_BCM_CBC                                     (0x01) //AES, DES/TDES
#define MCP_BCM_CTR                                     (0x02) //AES
#define MCP_BCM_RCBC_CS                                 (0x03) //AES for Irdeto only
#define MCP_ENC(x)                                  ((x & 0x01) << 5)
#define MCP_MODE(x)                                 (x & 0x1F)

#define MCP_ALGO_DES                                (0x00)
#define MCP_ALGO_3DES                               (0x01)
#define MCP_ALGO_MD5                                (0x03)
#define MCP_ALGO_SHA_1                              (0x04)
#define MCP_ALGO_AES                                (0x05)
#define MCP_ALGO_AES_G                              (0x06)
#define MCP_ALGO_AES_H                              (0x07)
#define MCP_ALGO_CMAC                               (0x08)
#define MCP_ALGO_CSA                                (0x09)
#define MCP_ALGO_MULTI2                             (0x0A)
#define MCP_ALGO_SHA256                             (0x0B)
#endif

#define MCP_ALGO_LOAD_MICRO_CODE                    (0x0E)
#define MCP_ALGO_MICRO_CODE                         (0x0F)

#define MCP_KEY_SEL(x)                              ((x & 0x03) << 12)
#define MCP_KEY_SEL_CW                                  (0x02)
#define MCP_KEY_SEL_OTP                                 (0x01)
#define MCP_KEY_SEL_DESC                                (0x00)

#define MCP_IV_SEL(x)                               ((x & 0x01) << 11)
#define MCP_IV_SEL_REG                                  (0x01)
#define MCP_IV_SEL_DESC                                 (0x00)

#define MCP_CW_KEY(x)                               (((x) & 0x7F)<<8)

/* =============================================================================== */
/*  MACROS                                                                                                                                                 */
/* =============================================================================== */
#define MCP_CTRL                                    RTD294x_MCP_CTRL
#define MCP_STATUS                                  RTD294x_MCP_STATUS
#define MCP_EN                                      RTD294x_MCP_EN
#define MCP_BASE                                    RTD294x_MCP_BASE
#define MCP_LIMIT                                   RTD294x_MCP_LIMIT
#define MCP_RDPTR                                   RTD294x_MCP_RDPTR
#define MCP_WRPTR                                   RTD294x_MCP_WRPTR
#define MCP_CTRL1                                   RTD294x_MCP_CTRL1
#define MCP_OTP_LOAD                                RTD294x_CP_OTP_LOAD
#define MCP_AES_INI_KEY0                            RTD294x_MCP_AES_INI_KEY0
#define MCP_AES_INI_KEY1                            RTD294x_MCP_AES_INI_KEY1
#define MCP_AES_INI_KEY2                            RTD294x_MCP_AES_INI_KEY2
#define MCP_AES_INI_KEY3                            RTD294x_MCP_AES_INI_KEY3
#define MCP_SCTCH                                   RTD294x_CP_SCTCH

#define SET_MCP_CTRL(x)                             rtd_outl(MCP_CTRL, x)
#define SET_MCP_STATUS(x)                           rtd_outl(MCP_STATUS, x)
#define SET_MCP_EN(x)                               rtd_outl(MCP_EN, x)
#define SET_MCP_BASE(x)                             rtd_outl(MCP_BASE, x)
#define SET_MCP_LIMIT(x)                            rtd_outl(MCP_LIMIT, x)
#define SET_MCP_RDPTR(x)                            rtd_outl(MCP_RDPTR, x)
#define SET_MCP_WRPTR(x)                            rtd_outl(MCP_WRPTR, x)
#define SET_MCP_CTRL1(x)                            rtd_outl(MCP_CTRL1, x)
#define SET_MCP_OTP_LOAD(x)                         rtd_outl(MCP_OTP_LOAD, x)
#define SET_MCP_SCTCH(x)                            rtd_outl(MCP_SCTCH, x)

#define GET_MCP_CTRL()                              rtd_inl(MCP_CTRL)
#define GET_MCP_STATUS()                            rtd_inl(MCP_STATUS)
#define GET_MCP_EN()                                rtd_inl(MCP_EN)
#define GET_MCP_BASE()                              rtd_inl(MCP_BASE)
#define GET_MCP_LIMIT()                             rtd_inl(MCP_LIMIT)
#define GET_MCP_RDPTR()                             rtd_inl(MCP_RDPTR)
#define GET_MCP_WRPTR()                             rtd_inl(MCP_WRPTR)
#define GET_MCP_CTRL1()                             rtd_inl(MCP_CTRL1)
#define GET_MCP_OTP_LOAD()                          rtd_inl(MCP_OTP_LOAD)
#define GET_MCP_SCTCH()                             rtd_inl(MCP_SCTCH)
#define GET_MCP_AES_INI_KEY0()                      rtd_inl(MCP_AES_INI_KEY0)
#define GET_MCP_AES_INI_KEY1()                      rtd_inl(MCP_AES_INI_KEY1)
#define GET_MCP_AES_INI_KEY2()                      rtd_inl(MCP_AES_INI_KEY2)
#define GET_MCP_AES_INI_KEY3()                      rtd_inl(MCP_AES_INI_KEY3)

#endif  // __MCP_REG_H__
