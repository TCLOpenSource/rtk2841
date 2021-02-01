/***************************************************************************************************
  File        : demod_rtk.cpp
  Description : REALTEK_I DVB-S2 demod
  Author      : Kevin Wang
****************************************************************************************************
    Update List :
----------------------------------------------------------------------------------------------------
    20120207    | create phase
***************************************************************************************************/
#include <linux/kernel.h>
#include <linux/slab.h>
#include <asm/cacheflush.h>
#include <linux/pageremap.h>
#include "comm.h"
#include "foundation.h"
#include "demod_rtk_dvbs2.h"
#include "dvbs2_demod_rtk.h"
#include "demod_rtk_dvbs2_priv.h"
#include "dvbs2x_tvcore_registers.h"
#include "dvbs2_tvcore_registers.h"
#include "dvbs_tvcore_registers.h"
#include "dvbs2x_registers.h"
#include "dvbs2_registers.h"
#include "dvbs_registers.h"
#include "spec_an_registers.h"
#include <mach/io.h>
#include "rbus/demod_sd_reg.h"

//#define SPEC_AN_DEBUG
//#define PRINT_SPECTRUM
#define PER_COLOR_ENABLE
//#define ENABLE_LDR_LOADER
//#define SUPPORT_WINTOOL
//#define EN_AUTOTEST

#define EN_DVBS
#define EN_DVBS2
#ifdef CONFIG_CUSTOMER_TV006
#define EN_DVBS2X
#endif

#define COMMON_BASE_ADDRESS     0xc27ff100
#define VR_BASE_ADDRESS         0xc27ff200

#define CONSTELL_EQ_ADDRESS     0xc27ff300
#define CONSTELL_HD_ADDRESS     0xc27ff400

#define DEBUG_MODE_EN_ADDRESS   0xc27ff500
#define DEBUG_MODE_SEL_ADDRESS  0xc27ff504
#define HANDSHAKE_ADDRESS       0xc27ff508
#define PRI_VR_INDEX_ADDRESS    0xc27ff50c
#define SEC_VR_INDEX_ADDRESS    0xc27ff510
#define VR_VALUE_ADDRESS        0xc27ff514

#define BLINDSCAN_DBG_FREQ      0xc27ff61c
#define BLINDSCAN_DBG_TH1_CP1   0xc27ff620
#define BLINDSCAN_DBG_TH1_CP2   0xc27ff624
#define BLINDSCAN_DBG_TH2_CP1   0xc27ff628
#define BLINDSCAN_DBG_TH2_CP2   0xc27ff62c
#define BLINDSCAN_DBG_TH3_CP1   0xc27ff630
#define BLINDSCAN_DBG_TH3_CP2   0xc27ff634

#define BLINDSCAN_DBG_ANAZ_RST  0xc27ff638
#define BLINDSCAN_DBG_SIG_FOUND 0xc27ff63c
#define BLINDSCAN_DBG_CFO       0xc27ff640
#define BLINDSCAN_DBG_CSR       0xc27ff644
#define BLINDSCAN_DBG_TUN_STEP  0xc27ff648

#define IMG_DEMOD_DVBS_EQ_CONST_ADDRESS 0x36050e08
#define IMG_DEMOD_DVBS_HD_CONST_ADDRESS 0x36058e08

#define DVBS2_MOD_QPSK          0
#define DVBS2_MOD_8PSK          1
#define DVBS2_MOD_8PSKL         2
#define DVBS2_MOD_16PSK         3
#define DVBS2_MOD_32PSK         4

#define DVBS2_CR_1_2            0
#define DVBS2_CR_2_3            1
#define DVBS2_CR_3_4            2
#define DVBS2_CR_5_6            3
#define DVBS2_CR_3_5            5
#define DVBS2_CR_4_5            6
#define DVBS2_CR_8_9            7
#define DVBS2_CR_9_10           8

#define DVBS_CR_1_2             0
#define DVBS_CR_2_3             1
#define DVBS_CR_3_4             2
#define DVBS_CR_5_6             3
#define DVBS_CR_7_8             4

#define BAD_PAK_THRESHOLD       0

typedef struct _s_DvbS2SignalQualityBound
{
    unsigned int HighBound;
    unsigned int MidBound;
    unsigned int LowBound;    
}s_DvbS2SignalQualityBound;

typedef struct _s_DvbS2SignalQualityMapping
{
    unsigned int Modulation;
    unsigned int CodeRate;
    s_DvbS2SignalQualityBound sBound;
}s_DvbS2SignalQualityMapping;

static const s_DvbS2SignalQualityMapping _gsDvbs2SigQualityMappingTable[] =
{
    {DVBS2_MOD_QPSK,  DVBS2_CR_1_2,    {80, 20, 12}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_3_5,    {92, 32, 25}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_2_3,    {101, 41, 32}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_3_4,    {110, 50, 42}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_4_5,    {117, 57, 49}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_5_6,    {122, 62, 54}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_8_9,    {132, 72, 64}},
    {DVBS2_MOD_QPSK,  DVBS2_CR_9_10,   {134, 74, 66}},
    {DVBS2_MOD_8PSK,  DVBS2_CR_3_5,    {125, 65, 60}},
    {DVBS2_MOD_8PSK,  DVBS2_CR_2_3,    {136, 76, 68}},
    {DVBS2_MOD_8PSK,  DVBS2_CR_3_4,    {149, 89, 82}},
    {DVBS2_MOD_8PSK,  DVBS2_CR_5_6,    {164, 104, 96}},
    {DVBS2_MOD_8PSK,  DVBS2_CR_8_9,    {177, 117, 110}},
    {DVBS2_MOD_8PSK,  DVBS2_CR_9_10,   {180, 120, 113}}
};
#define DVBS2_SIG_QUALITY_TABLE_SIZE sizeof(_gsDvbs2SigQualityMappingTable)/sizeof(s_DvbS2SignalQualityMapping)


typedef struct _s_DvbSSignalQualityBound
{
    unsigned int HighBound;
    unsigned int MidBound;
    unsigned int LowBound;    
}s_DvbSSignalQualityBound;

typedef struct _s_DvbSSignalQualityMapping
{
    unsigned int CodeRate;
    s_DvbSSignalQualityBound sBound;
}s_DvbSSignalQualityMapping;

static const s_DvbSSignalQualityMapping _gsDvbSSigQualityMappingTable[] =
{
    {DVBS_CR_1_2,    {88, 38, 25}},
    {DVBS_CR_2_3,    {106, 56, 42}},
    {DVBS_CR_3_4,    {117, 67, 51}},
    {DVBS_CR_5_6,    {127, 77, 60}},
    {DVBS_CR_7_8,    {134, 84, 67}}
};
#define DVBS_SIG_QUALITY_TABLE_SIZE sizeof(_gsDvbSSigQualityMappingTable)/sizeof(s_DvbSSignalQualityMapping)

static const s_sDvbSLockTimeOut _sDvbSLockTimeOutTable[] = 
{
    //SR    TimeOut 
    {20000, 3500,      22, 24, 79,  22, 24, 3500,    22, 24, 79,  22, 24, 3500},
    {15000, 3500,      22, 24, 79,  22, 24, 3500,    22, 24, 79,  22, 24, 3500},
    {10000, 3500,      22, 24, 86,  22, 24, 3500,    22, 24, 86,  22, 24, 3500},
    {5000,  3500,      22, 24, 101, 22, 24, 3500,    22, 24, 101, 22, 24, 3500},
    {1100,  3500,      22, 24, 187, 22, 24, 3500,    22, 24, 187, 22, 24, 3500},
    {600,   6200,      22, 24, 288, 22, 24, 6200,    22, 24, 288, 22, 24, 6200},
    {400,   8000,      22, 24, 389, 22, 24, 8000,    22, 24, 389, 22, 24, 8000},
    {0,     15000,     22, 24, 713, 22, 24, 15000,   22, 24, 713, 22, 24, 15000}
};
#define DVBS_ACQ_TIMEOUT_TABLE_SIZE sizeof(_sDvbSLockTimeOutTable)/sizeof(s_sDvbSLockTimeOut)

static const s_sDvbS2LockTimeOut _sDvbS2LockTimeOutTable[] = 
{
    //SR    TimeOut    scan mode and play mode use the same setting for avoiding CN degrade
    {15000, 3500,      14, 16, 107,  8, 9, 3500,     14, 16, 107,  8, 9, 3500},
    {7500,  3500,      14, 16, 213,  8, 9, 3500,     14, 16, 213,  8, 9, 3500},
    {1100,  3500,      14, 16, 1598, 8, 9, 3500,     14, 16, 1598, 8, 9, 3500},
    {600,   6200,      14, 16, 1598, 8, 9, 6200,     14, 16, 1598, 8, 9, 6200},
    {400,   8000,      14, 16, 1598, 8, 9, 8000,     14, 16, 1598, 8, 9, 8000},
    {0,     15000,     14, 16, 1598, 8, 9, 15000,    14, 16, 1598, 8, 9, 15000}
};
#define DVBS2_ACQ_TIMEOUT_TABLE_SIZE sizeof(_sDvbS2LockTimeOutTable)/sizeof(s_sDvbS2LockTimeOut)

static const s_sDvbS2XLockTimeOut _sDvbS2XLockTimeOutTable[] = 
{
    {15000, 4000},
    {7500, 4500},
    {1100, 5000},
    {600, 8900},
    {400, 9700},
    {0, 16700}
};
#define DVBS2X_ACQ_TIMEOUT_TABLE_SIZE sizeof(_sDvbS2XLockTimeOutTable)/sizeof(s_sDvbS2XLockTimeOut)

#define DVBS2_BS_TP_ENHANCEMENT_SAT_NUM_TABLE_SIZE  18
#define DVBS2_BS_TP_ENHANCEMENT_MAX_SAT_TABLE_SIZE  30
static const unsigned short _sBsTpEnhancement[DVBS2_BS_TP_ENHANCEMENT_SAT_NUM_TABLE_SIZE][DVBS2_BS_TP_ENHANCEMENT_MAX_SAT_TABLE_SIZE][2] = 
{
    //(Sat 0)Eutelsat W3A 7W/Hotbird 13.0E 22K OFF H
    {
        { 977, 29999},
        {1025, 27499},
        {1065, 27499},
        {1103, 29899},
        {1142, 27499},
        {1180, 29999},
        {1221, 29699},
        {1263, 29899},
        {1304, 27499},
        {1387, 27499},
        {1429, 27498},
        {1469, 29899},
        {1508, 27499},
        {1546, 27499},
        {1584, 27499},
        {1623, 27499},
        {1660, 27499},
        {1699, 27499},
        {1738, 27499},
        {1776, 29699},
        {1816, 29899},
        {1854, 27499},
        {1893, 27499},
        {1931, 27499},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 1)Eutelsat W3A 7W/Hotbird 13.0E 22K OFF V
    {
        { 969, 27499},
        {1008, 27499},
        {1046, 27499},
        {1084, 27499},
        {1123, 27499},
        {1161, 27499},
        {1199, 27499},
        {1242, 27499},
        {1284, 27499},
        {1325, 27499},
        {1367, 27499},
        {1408, 27499},
        {1450, 27499},
        {1490, 27499},
        {1528, 27499},
        {1567, 27499},
        {1605, 29899},
        {1644, 27499},
        {1682, 29899},
        {1720, 27499},
        {1759, 27499},
        {1791, 21999},
        {1835, 27499},
        {1873, 27499},
        {1912, 27499},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 2)Eutelsat W3A 7W/Hotbird 13.0E 22K ON V
    {
        {1128, 27499},
        {1166, 29899},
        {1204, 27499},
        {1243, 29899},
        {1281, 27499},
        {1320, 29899},
        {1358, 27499},
        {1396, 29899},
        {1435, 29899},
        {1473, 29899},
        {1511, 27499},
        {1550, 27499},
        {1588, 27499},
        {1626, 27499},
        {1665, 27499},
        {1703, 27499},
        {1741, 29899},
        {1780, 27499},
        {1818, 29899},
        {1866, 29899},
        {1920, 27499},
        {1958, 27499},
        {1997, 27499},
        {2035, 29899},
        {2074, 29899},
        {2114, 29899},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 3)Eutelsat W3A 7W/Hotbird 13.0E 22K ON H
    {
        {1147, 27499},
        {1185, 29899},
        {1224, 27499},
        {1262, 29899},
        {1300, 29899},
        {1339, 27499},
        {1377, 29899},
        {1415, 27499},
        {1454, 29899},
        {1493, 29899},
        {1531, 27499},
        {1569, 27499},
        {1607, 29899},
        {1646, 29899},
        {1684, 27499},
        {1722, 27499},
        {1761, 29899},
        {1799, 29699},
        {1837, 29899},
        {1876, 29899},
        {1939, 29999},
        {1978, 27499},
        {2016, 29899},
        {2054, 27499},
        {2093, 27499},
        {2131, 29899},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 4)Turksat 42.0E 22K OFF H
    {
        {1231,  1666},
        {1271,  2220},
        {1295,  4799},
        {1303,  7999},
        {1312,  4819},
        {1346, 29999},
        {1430, 29999},
        {1758, 29999},
        {1807, 29999},
        {1823,  1799},
        {1899, 13599},
        {1925, 24444},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 5)Turksat 42.0E 22K OFF V
    {
        {1202,  1808},
        {1214, 14169},
        {1230, 12499},
        {1262, 29999},
        {1304, 29999},
        {1345, 29999},
        {1426, 34284},
        {1737,  6799},
        {1807, 29999},
        {1843, 24999},
        {1871,  3032},
        {1900, 13599},
        {1925, 24444},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 6)Turksat 42.0E 22K ON V/H
    {
        {1174, 27499},
        {1223,  7999},
        {1232,  6249},
        {1254, 29999},
        {1282,  4799},
        {1315, 29999},
        {1357, 27499},
        {1381,  2961},
        {1398, 11665},
        {1408,  4443},
        {1434, 27499},
        {1472, 27499},
        {1628,  8399},
        {1636,  3999},
        {1664, 27499},
        {1710, 14999},
        {1744, 29999},
        {1779, 27499},
        {1822, 27499},
        {1857, 29999},
        {1914, 11665},
        {1930, 14999},
        {1958, 27499},
        {2004, 27499},
        {2009, 28029},
        {2040, 29999},
        {2084, 29999},
        {2128, 27499},
        {2128, 29999},
        {   0,     0},
    },
    
    //(Sat 7)Hispasat 30.0W 22K OFF H
    {
        { 980, 27499},
        {1020, 29999},
        {1060, 29999},
        {1180, 29999},
        {1512, 29999},
        {1552, 29999},
        {1592, 29999},
        {1632, 29999},
        {1746,  7884},
        {1753,  1667},
        {1838,  3399},
        {1903, 19679},
        {1928, 19683},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 8)Hispasat 30.0W 22K OFF V
    {
        {1140, 27499},
        {1167,  7499},
        {1172,  1667},
        {1512, 29999},
        {1552, 29999},
        {1592, 29999},
        {1632, 29999},
        {1672,  4999},
        {1741,  7522},
        {1760,  9999},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 9)Hispasat 30.0W 22K ON V
    {
        {1131, 29999},
        {1171, 29999},
        {1211, 29999},
        {1251, 29999},
        {1291, 29999},
        {1331, 29999},
        {1492, 27499},
        {1530, 27499},
        {1569, 27499},
        {1607, 27499},
        {1645, 27499},
        {1684, 27499},
        {1760, 27499},
        {1799, 27499},
        {1837, 27499},
        {1876, 27499},
        {1919,  1481},
        {1949, 29599},
        {2031, 29999},
        {2071, 29999},
        {2107, 11999},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 10)Hispasat 30.0W 22K ON H
    {
        {1131, 29999},
        {1171, 29999},
        {1211, 29999},
        {1251, 29999},
        {1331, 29999},
        {1452, 27499},
        {1492, 27499},
        {1530, 27499},
        {1569, 27499},
        {1607, 27499},
        {1645, 27499},
        {1684, 27499},
        {1760, 27499},
        {1799, 27499},
        {1837, 27499},
        {1876, 27499},
        {1928,  7999},
        {2086,  4499},
        {2107, 11999},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 11)Astra 19.2E 22K OFF H
    {
        { 964, 21999},
        { 993, 21999},
        {1023, 21999},
        {1052, 21999},
        {1082, 21999},
        {1111, 23499},
        {1141, 21999},
        {1170, 21999},
        {1214, 21999},
        {1273, 23499},
        {1302, 21999},
        {1332, 21999},
        {1361, 21999},
        {1420, 21999},
        {1493, 21999},
        {1523, 21999},
        {1552, 21999},
        {1612, 21999},
        {1641, 21999},
        {1671, 21999},
        {1714, 21999},
        {1744, 21999},
        {1803, 21999},
        {1832, 21999},
        {1862, 21999},
        {1921, 21999},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 12)Astra 19.2E 22K OFF V
    {
        { 979, 21999},
        {1008, 21999},
        {1038, 21999},
        {1067, 21999},
        {1097, 21999},
        {1126, 21999},
        {1156, 21999},
        {1185, 21999},
        {1229, 21999},
        {1288, 21999},
        {1317, 21999},
        {1347, 21999},
        {1376, 21999},
        {1406, 21999},
        {1435, 21999},
        {1479, 21999},
        {1508, 21999},
        {1538, 21999},
        {1567, 21999},
        {1597, 21999},
        {1626, 21999},
        {1685, 21999},
        {1758, 21999},
        {1788, 21999},
        {1847, 21999},
        {1876, 21999},
        {1906, 21999},
        {1935, 21999},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 13)Astra 19.2E 22K ON V
    {
        {1138, 27499},
        {1216, 29699},
        {1255, 29699},
        {1294, 29699},
        {1333, 29699},
        {1372, 27499},
        {1411, 29699},
        {1450, 27499},
        {1489, 29699},
        {1528, 29699},
        {1567, 29699},
        {1606, 29699},
        {1645, 29699},
        {1684, 29699},
        {1723, 29699},
        {1762, 27499},
        {1801, 29699},
        {1840, 29699},
        {1879, 27499},
        {1951, 21999},
        {2128, 21999},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 14)Astra 19.2E 22K ON H
    {
        {1119, 27499},
        {1158, 27499},
        {1197, 27499},
        {1236, 27499},
        {1275, 27499},
        {1314, 27499},
        {1353, 27499},
        {1392, 27499},
        {1431, 27499},
        {1470, 27499},
        {1509, 27499},
        {1548, 27499},
        {1587, 27499},
        {1626, 27499},
        {1665, 27499},
        {1704, 27499},
        {1743, 29999},
        {1782, 27499},
        {1821, 27499},
        {1860, 27499},
        {1915, 21999},
        {1944, 21999},
        {1974, 21999},
        {2003, 21999},
        {2033, 21999},
        {2062, 21999},
        {2092, 21999},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //(Sat 15)Atlbird 22K OFF V
    {
        {1221, 29949},
        {1304, 29949},
        {1346, 29949},
        {1387, 29949},
        {1721, 29949},
        {1762, 29949},
        {1804, 29949},
        {1845, 29949},
        {1928, 29949},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
        {   0,     0},
    },
    
    //Asiasat 105.5E 22k off V
    {
        {969,  30001},
        {1010, 27502},
        {1050, 29719},
        {1090, 26666},
        {1130, 28095},
        {1169, 28099},
        {1210, 28099},
        {1237, 7260},
        {1244, 2815},
        {1248, 2963},
        {1260, 11840},
        {1289, 28099},
        {1330, 27502},
        {1369, 29719},
        {1395, 4418},
        {1399, 2333},
        {1411, 2333},
        {1417, 7250},
        {1460, 11395},
        {1486, 2815},
        {1498, 14099},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
    },
    
    //Asiasat 105.5E 22k off H
    {
        {974,  2814},
        {977,  2481},
        {985,  5040},
        {1004, 5316},
        {1031, 27502},
        {1055, 5800},
        {1063, 3180},
        {1068, 3185},
        {1074, 6500},
        {1080, 2963},
        {1085, 4296},
        {1111, 26501},
        {1151, 29719},
        {1190, 27502},
        {1230, 29719},
        {1271, 27502},
        {1311, 29719},
        {1351, 28095},
        {1390, 26000},
        {1416, 6500},
        {1425, 8166},
        {1435, 8167},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
        {0, 0},
    },
};


extern unsigned int DvbS2_Keep_22k_on_off;
/*----------------------------------------------------------------------
 * Func : REALTEK_I_DVBS2
 *
 * Desc : constructor
 *
 * Parm : device_addr : device address
 *        output_mode : RTK_DEMOD_OUT_IF_SERIAL / RTK_DEMOD_OUT_IF_PARALLEL
 *        output_freq : RTK_DEMOD_OUT_FREQ_6M / RTK_DEMOD_OUT_FREQ_10M
 *        pComm       : hadle of COMM
 *
 * Retn : handle of demod
 *----------------------------------------------------------------------*/
void REALTEK_I_DVBS2_Constructors(DEMOD* pDemodKernel, unsigned char addr, unsigned char output_mode, unsigned char output_freq, COMM*    pComm)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;

    pDemodKernel->private_data = dvr_malloc(sizeof(REALTEK_I_DVBS2));
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);

    Demod_Constructors(pDemodKernel);

    pDemodKernel->m_id                 = DTV_DEMOD_REALTEK_I_DVBS2;
    pDemodKernel->m_addr               = addr;
    pDemodKernel->m_pTuner             = NULL;
    pDemodKernel->m_pComm              = pComm;
    pDemodKernel->m_ScanRange          = SCAN_RANGE_3_6;
    pDemodKernel->m_Capability         = TV_SYS_TYPE_DVBS2;
    pDemodKernel->m_update_interval_ms = 1000;
    pDemodKernel->m_if.freq            = 0;
    pDemodKernel->m_if.inversion       = 0;
    pDemodKernel->m_if.agc_pola        = 0;
    pDemodKernel->m_clock              = CRYSTAL_FREQ_27000000HZ;
    pRealtekIDVBS2->m_output_freq       = output_freq;

    pRealtekIDVBS2->m_private            = (void*) AllocRealtekIDvbs2Driver(pDemodKernel->m_pComm, pDemodKernel->m_addr, pDemodKernel->m_clock);

    pDemodKernel->m_ts.mode            = (output_mode == RTK_DEMOD_OUT_IF_PARALLEL) ? PARALLEL_MODE : SERIAL_MODE;
    pDemodKernel->m_ts.data_order      = MSB_D7;
    pDemodKernel->m_ts.datapin         = MSB_FIRST;
    pDemodKernel->m_ts.err_pol         = ACTIVE_HIGH;
    pDemodKernel->m_ts.sync_pol        = ACTIVE_HIGH;
    pDemodKernel->m_ts.val_pol         = ACTIVE_HIGH;
    pDemodKernel->m_ts.clk_pol         = FALLING_EDGE;
    pDemodKernel->m_ts.internal_demod_input = 1;
    pDemodKernel->m_ts.tsOutEn = 1;
    pRealtekIDVBS2->m_TunerOptRegCnt = 0;
    pRealtekIDVBS2->m_auto_tune_en = 0;
    pRealtekIDVBS2->m_pTunerOptReg = NULL;
    pRealtekIDVBS2->BlindscanInitDone = 0;

    pRealtekIDVBS2->m_dvbs2_AgcScale = 128;
    pRealtekIDVBS2->m_dvbs2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
    pRealtekIDVBS2->m_dvbs_AgcScale = 128;
    pRealtekIDVBS2->m_dvbs_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;

    pDemodKernel->m_pComm->SetTargetName(pDemodKernel->m_pComm, pDemodKernel->m_addr, "REALTEK_I_DVBS2");

    pDemodKernel->Init = REALTEK_I_DVBS2_Init;
    pDemodKernel->Reset = Demod_Reset;
    pDemodKernel->AcquireSignal = REALTEK_I_DVBS2_AcquireSignal;
    pDemodKernel->ScanSignal = REALTEK_I_DVBS2_ScanSignal;
    pDemodKernel->SetIF = REALTEK_I_DVBS2_SetIF;
    pDemodKernel->SetTSMode = REALTEK_I_DVBS2_SetTSMode;
    pDemodKernel->SetTVSysEx = REALTEK_I_DVBS2_SetTVSysEx;
    pDemodKernel->SetMode = REALTEK_I_DVBS2_SetMode;
    pDemodKernel->SetTVSys = REALTEK_I_DVBS2_SetTVSys;
    pDemodKernel->GetLockStatus = REALTEK_I_DVBS2_GetLockStatus;
    pDemodKernel->GetSegmentNum = Demod_GetSegmentNum;
    pDemodKernel->GetSignalInfo = REALTEK_I_DVBS2_GetSignalInfo;
    pDemodKernel->GetSignalQuality = REALTEK_I_DVBS2_GetSignalQuality;
    pDemodKernel->ChangeT2PLP = Demod_ChangeT2PLP;
    pDemodKernel->GetT2PLPInfo = Demod_GetT2PLPInfo;
    pDemodKernel->GetT2L1PreInfo = Demod_GetT2L1PreInfo;
    pDemodKernel->GetT2L1PostInfo = Demod_GetT2L1PostInfo;
    pDemodKernel->GetDemodStatus = Demod_GetDemodStatus;
    pDemodKernel->GetCarrierOffset = REALTEK_I_DVBS2_GetCarrierOffset;
    pDemodKernel->GetChannelInfo = REALTEK_I_DVBS2_GetChannelInfo;
    pDemodKernel->ForwardI2C = REALTEK_I_DVBS2_ForwardI2C;
    pDemodKernel->AutoTune = REALTEK_I_DVBS2_AutoTune;
    pDemodKernel->KernelAutoTune = REALTEK_I_DVBS2_KernelAutoTune;
    pDemodKernel->GetCapability = Demod_GetCapability;
    pDemodKernel->Suspend = Demod_Suspend;
    pDemodKernel->Resume = Demod_Resume;
    pDemodKernel->SetTvMode = REALTEK_I_DVBS2_SetTvMode;
    pDemodKernel->InspectSignal = REALTEK_I_DVBS2_InspectSignal;    // Add monitor function that used to monitor demod status
    pDemodKernel->AttachTuner = Demod_AttachTuner;
    pDemodKernel->GetTSParam = Demod_GetTSParam;
    
    pDemodKernel->BlindScan_Init = REALTEK_I_DVBS2_BlindScan_Init;
    pDemodKernel->BlindScan_GetTunerFreq = REALTEK_I_DVBS2_BlindScan_GetTunerFreq;
    pDemodKernel->BlindScan_NextFreq = REALTEK_I_DVBS2_BlindScan_NextFreq;
    pDemodKernel->BlindScan_GetStatus = REALTEK_I_DVBS2_BlindScan_GetStatus;
    pDemodKernel->BlindScan_End = REALTEK_I_DVBS2_BlindScan_End;
    pDemodKernel->BlindScan_GetFoundTP = REALTEK_I_DVBS2_BlindScan_GetFoundTP;
    pDemodKernel->BlindScan_AcquireSignal = REALTEK_I_DVBS2_BlindScan_AcquireSignal;
    
    pDemodKernel->SetDiseqcContinue22kOnOff = REALTEK_I_DVBS2_SetDiseqcContinue22kOnOff;
    pDemodKernel->SetDiseqcCmd = REALTEK_I_DVBS2_SetDiseqcCmd;
    pDemodKernel->SetDiseqcToneBurst = REALTEK_I_DVBS2_SetDiseqcToneBurst;
    pDemodKernel->SetDiseqcUnModToneBurst = REALTEK_I_DVBS2_SetDiseqcUnModToneBurst;
    pDemodKernel->SetDiseqcModToneBurst = REALTEK_I_DVBS2_SetDiseqcModToneBurst;

    //pDemodKernel->Lock = Demod_Lock;
    //pDemodKernel->Unlock = Demod_Unlock;
    pDemodKernel->Lock = REALTEK_I_DVBS2_Lock;
    pDemodKernel->Unlock = REALTEK_I_DVBS2_Unlock;

    //pDemodKernel->Activate = REALTEK_I_DVBS2_Activate;
    pDemodKernel->Destory = REALTEK_I_DVBS2_Destructors;

#ifdef SUPPORT_WINTOOL
    pRealtekIDVBS2->m_debug_tool_en = 0;
    rtd_outl(DEBUG_MODE_EN_ADDRESS, 0);
    rtd_outl(DEBUG_MODE_SEL_ADDRESS, 0);
#endif
    pRealtekIDVBS2->m_info.dvbs.IsBlindsearch = 0;
    //rtd_outl(0xc2700100, 0x00000000);
    //rtd_outl(0xc2700104, 0x00000000);
}


/*----------------------------------------------------------------------
 * Func : ~REALTEK_I_DVBS2
 *
 * Desc : Destructor of REALTEK_I_DVBS2
 *
 * Parm : pDemod : handle of Demod
 *
 * Retn : N/A
 *----------------------------------------------------------------------*/
void REALTEK_I_DVBS2_Destructors(DEMOD* pDemodKernel)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);

    if (pRealtekIDVBS2->m_private != NULL)
        ReleaseRealtekIDvbs2Driver((REALTEK_I_DVBS2_DRIVER_DATA*)pRealtekIDVBS2->m_private);

    dvr_free(pRealtekIDVBS2);
    //pDemodKernel->Destory(pDemodKernel);
    REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_Destructors Complete\n");
}


/*----------------------------------------------------------------------
 * Func : Init
 *
 * Desc : Initial realtekI
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_Init(DEMOD* pDemodKernel)
{   
    int ret = TUNER_CTRL_OK;
    //unsigned char PGAEnable = 0;
    //IFADCGAIN PGAGain;
    unsigned int IsRpuLowReady = 0, IsRpuHighReady = 0;
    unsigned int BuildId = 0, DemodType = 0;
    unsigned int InitRetry = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);

    if (pDemodKernel->m_pComm == NULL || pRealtekIDVBS2->m_private == NULL)
        return TUNER_CTRL_FAIL;
    
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    pRealtekIDVBS2->m_auto_tune_en = 0;
    
demod_re_init:
    DtvDemodInitialization(RTK_DEMOD_MODE_DVBS, 1);
    pRealtekIDVBS2->m_dvbs2_ldr_mode = REALTEK_I_DVBS_MODE;

    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

    if(IsRpuLowReady != 1 || IsRpuHighReady != 1)
    {
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
        
        if(!InitRetry)
        {
            InitRetry = 1;
            REALTEK_I_DVBS2_INFO("RPU Auto Re-Init in Demod Init\n");
            goto demod_re_init;
        }
        else
        {
            goto init_fail;
        }
    }

    //Change To Buffer Mode
    REALTEK_I_DVBS2_INFO("Change To Buffer Mode........\n");
    ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
    if (ret!= TUNER_CTRL_OK)
    {
        REALTEK_I_DVBS2_INFO("Change To Buffer Mode Fail !!!!!\n");
        goto init_fail;
    }

    ret |= DECODE_RET(pDemod->ActivateCore(pDemod));
    
    pDemod->SetDiseqcContinue22kOnOff(DvbS2_Keep_22k_on_off);
    
    if (pDemodKernel->m_pTuner) {
        TUNER_PARAM Param;

        if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, TV_SYS_DVBS2, &Param) == TUNER_CTRL_OK) {
            switch (Param.id)  {
            case TV_TUNER_AV2018:
                REALTEK_I_DVBS2_INFO("Tuner id %d, TV_TUNER_AV2018\n", Param.id);
                pRealtekIDVBS2->m_dvbs2_AgcScale = 128;//128/128=1.0
                pRealtekIDVBS2->m_dvbs2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
                pRealtekIDVBS2->m_dvbs_AgcScale = 128;//128/128=1.0
                pRealtekIDVBS2->m_dvbs_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
                break;
            case TV_TUNER_NO_TUNER:
                REALTEK_I_DVBS2_INFO("Tuner id %d, TV_TUNER_NO_TUNER\n", Param.id);
                pRealtekIDVBS2->m_dvbs2_AgcScale = 128;//128/128=1.0
                pRealtekIDVBS2->m_dvbs2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
                pRealtekIDVBS2->m_dvbs_AgcScale = 128;//128/128=1.0
                pRealtekIDVBS2->m_dvbs_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
                break;
            default:
                REALTEK_I_DVBS2_INFO("Unkonw tuner id %d, using default setting\n", Param.id);
                pRealtekIDVBS2->m_dvbs2_AgcScale = 128;//128/128=1.0
                pRealtekIDVBS2->m_dvbs2_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
                pRealtekIDVBS2->m_dvbs_AgcScale = 128;//128/128=1.0
                pRealtekIDVBS2->m_dvbs_ext_gain_dis = RTK_DEMOD_XML_EXT_GAIN_EN;
                break;
            }

            pDemodKernel->m_if.freq      = Param.if_freq;
            pDemodKernel->m_if.inversion = Param.if_inversion;
            pDemodKernel->m_if.agc_pola  = Param.if_agc_pola;
        }
    }
    ClearDemodReset(RTK_DEMOD_MODE_DVBS);

    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_SET_IF_GAIN_CTRL, NULL_SEC_ADDR, pRealtekIDVBS2->m_dvbs_AgcScale|(RTK_DEMOD_XML_EXT_GAIN1<<16)));//SetXmlTunerGainCtrl //Tuner 1:positive 0:negative; Demod 0:positive 1:negative
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_FLAGS, NULL_SEC_ADDR, RTK_DEMOD_XML_COMPLEX_IF|(pDemodKernel->m_if.inversion<<1)|(RTK_DEMOD_XML_UNSIGNED<<2)));//SetXmlFlags
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_FREQ, NULL_SEC_ADDR, pDemodKernel->m_if.freq));//SetXmlIfFreq
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_CFG_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlTunerCfgOverride

    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_CLK_FREQUENCY, NULL_SEC_ADDR, 90000000));//SetXmlIfClk
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_LDPC_CLK_FREQUENCY, NULL_SEC_ADDR, 607000000));//SetXmlLdpcClk
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_UCC_CLK_FREQUENCY, NULL_SEC_ADDR, 303000000));//SetXmlUccClk
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_MCU_CLK_FREQUENCY, NULL_SEC_ADDR, 607000000));//SetXmlMcuClk
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlPlftCfgOverride
    
    if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
        goto init_fail;

    REALTEK_I_DVBS2_DBG("Satellite Init Complete\n");

    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod,TV_REG_DEMOD_ID, NULL_SEC_ADDR, &DemodType));//GetDemodInfo
    DemodType = ((DemodType&0xFF000000)>>24);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_BUILD_ID, NULL_SEC_ADDR, &BuildId));//GetBuildId
    REALTEK_I_DVBS2_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);

    //Set Ber Cal Period to 1 Sec
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_SECONDS_BER_AVERAGING, NULL_SEC_ADDR, (0x00000001 & DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING)));//DvbSSetNumSecBerAvg

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_OK;

init_fail:

    REALTEK_I_DVBS2_WARNING("Satellite Init Failed\n");

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : SetTVSys
 *
 * Desc : Set TV System
 *
 * Parm : sys : TV System
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetTVSys(DEMOD* pDemodKernel, TV_SYSTEM sys)
{
    int ret = TUNER_CTRL_OK;
    TV_SIG_INFO   *pSigInfo;
    pSigInfo = kmalloc(sizeof(TV_SIG_INFO), GFP_KERNEL);

    pSigInfo->mod = TV_MODULATION_DVBS2;
    pSigInfo->dvbs.mod = TV_MODULATION_DVBS2;
    pSigInfo->dvbs.symbol_rate = 27500000;
    pSigInfo->dvbs.lnb_mode = LNB_MODE_13V_WITH_22K_BURST;
    
    ret = pDemodKernel->SetTVSysEx(pDemodKernel, sys, pSigInfo);
    
    kfree(pSigInfo);
    
    return ret;
}


/*----------------------------------------------------------------------
 * Func : SetTVSys
 *
 * Desc : Set TV System
 *
 * Parm : sys : TV System
 *        pSigInfo : signal information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetTVSysEx(DEMOD* pDemodKernel, TV_SYSTEM sys, const TV_SIG_INFO*  pSigInfo)
{
    int ret = TUNER_CTRL_OK;
    TUNER_PARAM Param;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pRealtekIDVBS2->m_auto_tune_en = 0;
    
    if (!pSigInfo) {
        REALTEK_I_DVBS2_INFO("Siginfo doesn't specified, SetTVSysEx Fail\n");

        return TUNER_CTRL_FAIL;
    }
    
    if(pSigInfo->dvbs.symbol_rate == 0 || pSigInfo->dvbs.symbol_rate > 50000000)
    {
        REALTEK_I_DVBS2_INFO("Null Symbol Rate, SetTVSysEx Break\n");
        return TUNER_CTRL_OK;
    }

    pDemodKernel->Lock(pDemodKernel);

    //TUNER_PARAM Param;
    if (pDemodKernel->m_pTuner->GetParam(pDemodKernel->m_pTuner, sys, &Param) == TUNER_CTRL_OK) {
        if ((pDemodKernel->m_if.freq != Param.if_freq) || (pDemodKernel->m_if.inversion != Param.if_inversion) || (pDemodKernel->m_if.agc_pola  != Param.if_agc_pola)) {
            pDemodKernel->m_if.freq = Param.if_freq;
            pDemodKernel->m_if.inversion = Param.if_inversion;
            pDemodKernel->m_if.agc_pola = Param.if_agc_pola;
            if (pDemodKernel->SetIF(pDemodKernel, &pDemodKernel->m_if) != TUNER_CTRL_OK)  return  TUNER_CTRL_FAIL;

        }
    }

    pDemodKernel->Unlock(pDemodKernel);

    pRealtekIDVBS2->m_info.dvbs.freq_khz = pSigInfo->dvbs.freq_khz;
    REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.freq_khz = %lu\n", pRealtekIDVBS2->m_info.dvbs.freq_khz);
    pRealtekIDVBS2->m_info.dvbs.symbol_rate = pSigInfo->dvbs.symbol_rate;
    REALTEK_I_DVBS2_INFO("\033[1;32;33m" "pRealtekIDVBS2->m_info.dvbs.symbol_rate = %lu\n" "\033[m", pRealtekIDVBS2->m_info.dvbs.symbol_rate);
    pRealtekIDVBS2->m_info.dvbs.IsBlindsearch = pSigInfo->dvbs.IsBlindsearch;
    //REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.IsBlindsearch = %u\n", (unsigned int)pRealtekIDVBS2->m_info.dvbs.IsBlindsearch);
    pRealtekIDVBS2->m_info.dvbs.scan_mode = pSigInfo->dvbs.scan_mode;
    //REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.scan_mode = %u\n", (unsigned int)pRealtekIDVBS2->m_info.dvbs.scan_mode);
    
    if(pSigInfo->dvbs.lnb_mode == 1)
    {
        REALTEK_I_DVBS2_INFO("\033[1;33;31m" "LNB_MODE_13V\n" "\033[m");
    }
    else if(pSigInfo->dvbs.lnb_mode == 2)
    {
        REALTEK_I_DVBS2_INFO("\033[1;33;31m" "LNB_MODE_18V\n" "\033[m");
    }
    else if(pSigInfo->dvbs.lnb_mode == 3)
    {
        REALTEK_I_DVBS2_INFO("\033[1;33;31m" "LNB_MODE_13V_WITH_22K_BURST\n" "\033[m");
    }
    else if(pSigInfo->dvbs.lnb_mode == 4)
    {
        REALTEK_I_DVBS2_INFO("\033[1;33;31m" "LNB_MODE_18V_WITH_22K_BURST\n" "\033[m");
    }
    else
    {
        REALTEK_I_DVBS2_INFO("\033[1;33;31m" "LNB_MODE_NONE\n" "\033[m");
    }
    pRealtekIDVBS2->m_info.dvbs.lnb_mode = pSigInfo->dvbs.lnb_mode;
    
    pDemodKernel->m_tv_sys = sys;

#ifdef SUPPORT_WINTOOL
    pRealtekIDVBS2->m_debug_tool_en = 0;
#endif
    if(pRealtekIDVBS2->m_info.dvbs.IsBlindsearch != 1)
    {
        //----------------------------------------------------------------------------------------------------------
        //NORMAL MODE
        //----------------------------------------------------------------------------------------------------------
        if(pDemodKernel->m_tv_sys == TV_SYS_DVBS)
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Webos TV_SYS_DVBS\n" "\033[m");
#ifdef EN_DVBS
            //----------------------------------------------------------------------------------------------------------
            //DVBS
            //----------------------------------------------------------------------------------------------------------
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
            
            return ret;
#endif
        }
        else
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Webos TV_SYS_DVBS2\n" "\033[m");
#ifdef EN_DVBS2
            //DVBS2 Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                return ret;
            
            //----------------------------------------------------------------------------------------------------------
            //DVBS2
            //----------------------------------------------------------------------------------------------------------
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
            
            return ret;
#endif
        }
    }
    else//if(pRealtekIDVBS2->m_info.dvbs.IsBlindsearch == 1)
    {
        //----------------------------------------------------------------------------------------------------------
        //BLINDSCAN MODE
        //----------------------------------------------------------------------------------------------------------   
        if(pDemodKernel->m_tv_sys == TV_SYS_DVBS)
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Blindscan Webos TV_SYS_DVBS\n" "\033[m");
            
            //----------------------------------------------------------------------------------------------------------
            //DVBS
            //----------------------------------------------------------------------------------------------------------
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
            
            return ret;
        }
        else
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Blindscan Webos TV_SYS_DVBS2\n" "\033[m");
            
            //----------------------------------------------------------------------------------------------------------
            //DVBS2
            //----------------------------------------------------------------------------------------------------------
            
            //DVBS2 Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                return ret;
            
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
            
            return ret;
        }
    }

    return ret;
}


/*----------------------------------------------------------------------
 * Func : SetIF
 *
 * Desc : Set IF Parameter
 *
 * Parm : pParam : IF Param
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetIF(DEMOD* pDemodKernel, IF_PARAM* pParam)
{
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    REALTEK_I_DVBS2_DBG("SetIF, IF_freq=%lu, spectrumn inv=%d, agc_pola=%d\n",
                     pParam->freq, pParam->inversion, pParam->agc_pola);

    pDemodKernel->m_if = *pParam;

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


/*----------------------------------------------------------------------
 * Func : SetMode
 *
 * Desc : Set operation mode of demod
 *
 * Parm : mode : Demod opreation mode
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetMode(DEMOD* pDemodKernel, TV_OP_MODE mode)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    
    switch (mode) {
    case TV_OP_MODE_NORMAL:
    case TV_OP_MODE_SCANING:
        break;

    case TV_OP_MODE_STANDBY:
        break;

    case TV_OP_MODE_ATV_NORMAL:
    case TV_OP_MODE_TP_ONLY:
        break;
    }
    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetTSMode
 *
 * Desc : Set mode of transport stream output
 *
 * Parm : pParam : TS Param
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetTSMode(DEMOD* pDemodKernel, TS_PARAM* pParam)
{
    int ret = TUNER_CTRL_OK;
    unsigned char TsOutEn, TsSerial, ClkPhase;
    unsigned int TsConfig = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    TsOutEn = (pParam->tsOutEn==1) ? RTK_DEMOD_TS_EN : RTK_DEMOD_TS_DIS;
    TsSerial = (pParam->mode==SERIAL_MODE) ? RTK_DEMOD_TS_SERIAL : RTK_DEMOD_TS_PARALLEL;
    ClkPhase = (pParam->clk_pol==RISING_EDGE) ? RTK_DEMOD_TS_CLK_PHASE_NOR : RTK_DEMOD_TS_CLK_PHASE_INV;

    pDemodKernel->Lock(pDemodKernel);

    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TSO_CLK_RATE_MARGIN, NULL_SEC_ADDR, 0x00011170));//SetTsClkRateMargin //Set TV_REG_TSO_CLK_RATE_MARGIN to 7%
    if(TsOutEn)
        TsConfig |= REALTEK_I_TS_DIS_MASK;
    if(TsSerial)
        TsConfig |= REALTEK_I_TS_SERIAL_MASK;
    if(ClkPhase)
        TsConfig |= REALTEK_I_TS_CLK_PHASE_INV_MASK;
    if(RTK_DEMOD_TS_PACKETS_204)
        TsConfig |= REALTEK_I_TS_PACKETS_188_MASK;
    else
        TsConfig |= REALTEK_I_TS_CLOCK_GATE_MASK;

    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TSO_CONFIG, NULL_SEC_ADDR, TsConfig));//SetTsConfig

    if (ret == TUNER_CTRL_OK)
        pDemodKernel->m_ts = *pParam;

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


/*----------------------------------------------------------------------
 * Func : GetLockStatus
 *
 * Desc : Get Demod Lock Status
 *
 * Parm : pLock : Lock Status
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetLockStatus(DEMOD* pDemodKernel, unsigned char* pLock)
{
    unsigned char lock = 0;
    unsigned int DemodStatus = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*)pRealtekIDVBS2->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS2))
        return TUNER_CTRL_FAIL;

    pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
    if(!pRealtekIDVBS2->m_debug_tool_en)
    {
#endif




    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
    lock = (DemodStatus == 5) ? YES : NO;

    if (ret == TUNER_CTRL_OK)
        *pLock = DECODE_LOCK(lock);
    else
        *pLock = 0;




#ifdef SUPPORT_WINTOOL
    }
    else
    {
        lock = YES;
        *pLock = DECODE_LOCK(lock);
    }
#endif

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


/*----------------------------------------------------------------------
 * Func : GetSignalInfo
 *
 * Desc : Get Signal Information
 *
 * Parm : pInfo : Siganl Information
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetSignalInfo(DEMOD* pDemodKernel, TV_SIG_INFO* pInfo)
{
    int ret = TUNER_CTRL_OK;
    unsigned int spec_inv = 0, code_rate = 0, modulation = 0, Snr = 0;
    long CrOffset = 0;
#ifdef EN_DVBS2X
    unsigned int ActMod = 0, ActCr = 0, ActIsi = 0, NumStream = 0;
#endif

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*)pRealtekIDVBS2->m_private)->pDemod;

#ifdef EN_DVBS2X
    if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
    {
        REALTEK_I_DVBS2_INFO("=================================================================\n");
        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
        
        if(ActMod == 0)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_MODULATION (%u) QPSK\n", ActMod);
        }
        else if(ActMod == 1)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_MODULATION (%u) 8PSK\n", ActMod);
        }
        else if(ActMod == 2)//8PSK-L
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_MODULATION (%u) 8PSK\n", ActMod);
        }
        else if(ActMod == 3)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_MODULATION (%u) 16APSK\n", ActMod);
        }
        else if(ActMod == 4)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_MODULATION (%u) 32APSK\n", ActMod);
        }
        else
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_MODULATION (%u) unknown\n", ActMod);
        }
        
        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
        
        if(ActCr == 0)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 1/2\n", ActCr);
        }
        else if(ActCr == 1)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 2/3\n", ActCr);
        }
        else if(ActCr == 2)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 3/4\n", ActCr);
        }
        else if(ActCr == 3)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 5/6\n", ActCr);
        }
        else if(ActCr == 4)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) Resverd\n", ActCr);
        }
        else if(ActCr == 5)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 3/5\n", ActCr);
        }
        else if(ActCr == 6)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 4/5\n", ActCr);
        }
        else if(ActCr == 7)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 8/9\n", ActCr);
        }
        else if(ActCr == 8)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 9/10\n", ActCr);
        }
        else if(ActCr == 9)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 1/4\n", ActCr);
        }
        else if(ActCr == 10)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 1/3\n", ActCr);
        }
        else if(ActCr == 11)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 2/5\n", ActCr);
        }
        else if(ActCr == 12)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 13/45\n", ActCr);
        }
        else if(ActCr == 13)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 9/20\n", ActCr);
        }
        else if(ActCr == 14)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 11/20\n", ActCr);
        }
        else if(ActCr == 15)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 5/9(100/180)\n", ActCr);
        }
        else if(ActCr == 16)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 26/45(104/180)\n", ActCr);
        }
        else if(ActCr == 17)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 23/36\n", ActCr);
        }
        else if(ActCr == 18)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 25/36\n", ActCr);
        }
        else if(ActCr == 19)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 13/18\n", ActCr);
        }
        else if(ActCr == 20)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 1/2(90/180)\n", ActCr);
        }
        else if(ActCr == 21)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 8/15(96/180)\n", ActCr);
        }
        else if(ActCr == 22)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 26/45\n", ActCr);
        }
        else if(ActCr == 23)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) Resverd\n", ActCr);
        }
        else if(ActCr == 24)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 3/5(18/30)\n", ActCr);
        }
        else if(ActCr == 25)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 28/45\n", ActCr);
        }
        else if(ActCr == 26)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 2/3(20/30)\n", ActCr);
        }
        else if(ActCr == 27)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 77/90(154/180)\n", ActCr);
        }
        else if(ActCr == 28)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 32/45(128/180)\n", ActCr);
        }
        else if(ActCr == 29)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 11/15(132/180)\n", ActCr);
        }
        else if(ActCr == 30)
        {
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_CODE_RATE (%u) 7/9(140/180)\n", ActCr);
        }

        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_ISI, NULL_SEC_ADDR, &ActIsi);
        REALTEK_I_DVBS2_INFO("DVBS2X_REG_ACTIVE_ISI %u\n", ActIsi);
        
        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_NUM_STREAMS, NULL_SEC_ADDR, &NumStream);
        REALTEK_I_DVBS2_INFO("DVBS2X_REG_NUM_STREAMS %u\n", NumStream);

        /*
        if(NumStream > 16)
            NumStream = 16;

        for(i=0; i<NumStream; i++)
        {
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ISI_LIST, NULL_SEC_ADDR, i, &tmp);
            REALTEK_I_DVBS2_INFO("DVBS2X_REG_ISI_LIST (%u) 0x%x\n", i ,(tmp&0xff));
        }
        */
    }
#endif
    
#ifdef SUPPORT_WINTOOL
    if(!pRealtekIDVBS2->m_debug_tool_en)
    {
#endif




    if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
    {
        pInfo->dvbs.mod = TV_MODULATION_DVBS2;                   //bIsDVBS2
        pInfo->mod = TV_MODULATION_DVBS2;                        //bIsDVBS2
        
        pDemodKernel->Lock(pDemodKernel);
        
        pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &spec_inv);//bSpectrumInv
        spec_inv &= DVBS2_BITFLD_ACTIVE_SPECTRUM_INVERSION;
        pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &code_rate);//codeRate
        code_rate &= DVBS2_BITFLD_ACTIVE_CODE_RATE;
        pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &modulation);//constellation
        modulation &= DVBS2_BITFLD_ACTIVE_MODULATION;

        pDemodKernel->Unlock(pDemodKernel);

        pInfo->dvbs.spec_invert = spec_inv;
        pInfo->dvbs.symbol_rate = pRealtekIDVBS2->m_info.dvbs.symbol_rate/1000;

        switch (code_rate) 
        {
            case 0://Code Rate 1/2
                pInfo->dvbs.code_rate = DVBS2_CR_1_2;
                break;
            case 1://Code Rate 2/3
                pInfo->dvbs.code_rate = DVBS2_CR_2_3;
                break;
            case 2://Code Rate 3/4
                pInfo->dvbs.code_rate = DVBS2_CR_3_4;
                break;
            case 3://Code Rate 5/6
                pInfo->dvbs.code_rate = DVBS2_CR_5_6;
                break;
            case 5://Code Rate 3/5
                pInfo->dvbs.code_rate = DVBS2_CR_3_5;
                break;
            case 6://Code Rate 4/5
                pInfo->dvbs.code_rate = DVBS2_CR_4_5;
                break;
            case 7://Code Rate 8/9
                pInfo->dvbs.code_rate = DVBS2_CR_8_9;
                break;
            case 8://Code Rate 9/10
                pInfo->dvbs.code_rate = DVBS2_CR_9_10;
                break;
        }

        switch (modulation) 
        {
            case 0://QPSK
                pInfo->dvbs.modulation = DVBS2_QPSK;
                break;
            case 1://8PSK
                pInfo->dvbs.modulation = DVBS2_8PSK;
                break;
        }
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        pRealtekIDVBS2->m_dvbs2_snr = (Snr*100)/655;
    }
    else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
    {
        pInfo->dvbs.mod = TV_MODULATION_DVBS2;                   //bIsDVBS2
        pInfo->mod = TV_MODULATION_DVBS2;                        //bIsDVBS2
        
        pDemodKernel->Lock(pDemodKernel);
        
        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &spec_inv);//bSpectrumInv
        spec_inv &= DVBS2_BITFLD_ACTIVE_SPECTRUM_INVERSION;
        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &code_rate);//codeRate
        code_rate &= DVBS2_BITFLD_ACTIVE_CODE_RATE;
        pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &modulation);//constellation
        modulation &= DVBS2_BITFLD_ACTIVE_MODULATION;

        pDemodKernel->Unlock(pDemodKernel);

        pInfo->dvbs.spec_invert = spec_inv;
        pInfo->dvbs.symbol_rate = pRealtekIDVBS2->m_info.dvbs.symbol_rate/1000;

        pInfo->dvbs.code_rate = code_rate;
        pInfo->dvbs.modulation = modulation;
        /*
        switch (code_rate) 
        {
            case 0://Code Rate 1/2
                pInfo->dvbs.code_rate = DVBS2_CR_1_2;
                break;
            case 1://Code Rate 2/3
                pInfo->dvbs.code_rate = DVBS2_CR_2_3;
                break;
            case 2://Code Rate 3/4
                pInfo->dvbs.code_rate = DVBS2_CR_3_4;
                break;
            case 3://Code Rate 5/6
                pInfo->dvbs.code_rate = DVBS2_CR_5_6;
                break;
            case 5://Code Rate 3/5
                pInfo->dvbs.code_rate = DVBS2_CR_3_5;
                break;
            case 6://Code Rate 4/5
                pInfo->dvbs.code_rate = DVBS2_CR_4_5;
                break;
            case 7://Code Rate 8/9
                pInfo->dvbs.code_rate = DVBS2_CR_8_9;
                break;
            case 8://Code Rate 9/10
                pInfo->dvbs.code_rate = DVBS2_CR_9_10;
                break;
        }

        switch (modulation) 
        {
            case 0://QPSK
                pInfo->dvbs.modulation = DVBS2_MOD_QPSK;
                break;
            case 1://8PSK
                pInfo->dvbs.modulation = DVBS2_MOD_8PSK;
                break;
            case 2://8PSK
                pInfo->dvbs.modulation = DVBS2_MOD_8PSKL;
                break;
            case 3://8PSK
                pInfo->dvbs.modulation = DVBS2_MOD_16APSK;
                break;
            case 4://8PSK
                pInfo->dvbs.modulation = DVBS2_MOD_32APSK;
                break;
        }
        */
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        pRealtekIDVBS2->m_dvbs2_snr = (Snr*100)/655;
    }
    else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
    {
        pInfo->dvbs.mod = TV_MODULATION_DVBS;                           //bIsDVBS2
        pInfo->mod = TV_MODULATION_DVBS;                                //bIsDVBS2
        
        pDemodKernel->Lock(pDemodKernel);
        
        pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &spec_inv);
        pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &code_rate);         //codeRate

        pDemodKernel->Unlock(pDemodKernel);

        pInfo->dvbs.spec_invert = spec_inv;
        pInfo->dvbs.symbol_rate = pRealtekIDVBS2->m_info.dvbs.symbol_rate/1000;

        switch (code_rate) 
        {
            case 0://Code Rate 1/2
                pInfo->dvbs.code_rate = DVBS_CR_1_2;
                break;
            case 1://Code Rate 2/3
                pInfo->dvbs.code_rate = DVBS_CR_2_3;
                break;
            case 2://Code Rate 3/4
                pInfo->dvbs.code_rate = DVBS_CR_3_4;
                break;
            case 3://Code Rate 5/6
                pInfo->dvbs.code_rate = DVBS_CR_5_6;
                break;
            case 4://Code Rate 7/8
                pInfo->dvbs.code_rate = DVBS_CR_7_8;
                break;
        }

        pInfo->dvbs.modulation = DVBS2_QPSK;                    //constellation
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        pRealtekIDVBS2->m_dvbs2_snr = (Snr*100)/655;
    }

    REALTEK_I_DVBS2_INFO("GetSignalInfo, SPEC_INV = %u, SYMBOL_RATE = %lu, CODE_RATE = %u, MODULATION = %u, SNR = %u\n", 
        (unsigned int)pInfo->dvbs.spec_invert, pInfo->dvbs.symbol_rate, (unsigned int)pInfo->dvbs.code_rate, (unsigned int)pInfo->dvbs.modulation, (Snr*100)/655);

    REALTEK_I_DVBS2_GetCarrierOffset(pDemodKernel, &CrOffset);


#ifdef SUPPORT_WINTOOL
    }
#endif

    return ret;
}


/*----------------------------------------------------------------------
 * Func : GetSignalQuality
 *
 * Desc : Get Signal Information
 *
 * Parm : id : Type of Quality Information
 *        pQuality : Siganl Quality
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetSignalQuality(DEMOD* pDemodKernel, ENUM_TV_QUAL id,    TV_SIG_QUAL* pQuality)
{
    unsigned int Snr = 0, Fer = 0, Per = 0, Ubc = 0, PakN = 0, BadPakN = 0, Agc = 0;
    int ret = TUNER_CTRL_OK;
    static unsigned int preBecPakN = 0, preBecBadPakN = 0, prePecPakN = 0, prePecBadPakN = 0;
    static unsigned int preReportBadPakN = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS2))
        return TUNER_CTRL_FAIL;

    pDemodKernel->Lock(pDemodKernel);

#ifdef SUPPORT_WINTOOL
    if(!pRealtekIDVBS2->m_debug_tool_en)
    {
#endif




    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_UPDATE_COUNTERS));//DemodCtrlUpdateCounters

    switch (id) {
    case TV_QUAL_SNR:
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        }
        pQuality->snr = (Snr*100)/655;
        pRealtekIDVBS2->m_dvbs2_snr = pQuality->snr;
        //REALTEK_I_DVBS2_INFO("Snr %lu(%u)\n", pQuality->snr, Snr);
        break;
    case TV_QUAL_BER:
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_FER_AT_BCH_OUTPUT, NULL_SEC_ADDR, &Fer));
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_FER_AT_BCH_OUTPUT, NULL_SEC_ADDR, &Fer));
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BER_AT_RS_INPUT, NULL_SEC_ADDR, &Fer));//RS input BER
        }
        pQuality->ber = (Fer*10000)/4294967296;
        break;
    case TV_QUAL_PER:
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per));
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per));
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per));
        }
        pQuality->per = (Per*10000)/4294967296;
        break;
    case TV_QUAL_UCBLOCKS:
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &Ubc));//GetBadPktCnt
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &Ubc));//GetBadPktCnt
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &Ubc));
        }
        
        if(Ubc >= pRealtekIDVBS2->m_PreUbc)
            pQuality->ucblocks = Ubc - pRealtekIDVBS2->m_PreUbc;
        else
            pQuality->ucblocks = Ubc + ((2^32) - pRealtekIDVBS2->m_PreUbc);
        
        pRealtekIDVBS2->m_PreUbc = Ubc;
        break;
    case TV_QUAL_SIGNAL_STRENGTH:
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            pQuality->strength = REALTEK_I_DVBS2_CalDvbS2Ssi(pDemodKernel);
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            pQuality->strength = REALTEK_I_DVBS2_CalDvbS2XSsi(pDemodKernel);
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            pQuality->strength = REALTEK_I_DVBS2_CalDvbSSsi(pDemodKernel);
        }
        break;
    case TV_QUAL_SIGNAL_QUALITY:
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            pQuality->quality = REALTEK_I_DVBS2_CalDvbS2Sqi(pDemodKernel);
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            pQuality->quality = REALTEK_I_DVBS2_CalDvbS2XSqi(pDemodKernel);
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            pQuality->quality = REALTEK_I_DVBS2_CalDvbSSqi(pDemodKernel);
        }
        break;
    case TV_QUAL_AGC:
        //ret = DECODE_RET(pDemod->GetIfAgcGain(pDemod, &IfAgcGain));
        //pQuality->agc = IfAgcGain >> 20;
        Agc = rtd_inl(DEMOD_SD_SIGMA_DELTA_INPUT_reg)&0x7ff;
        Agc =  Agc*100/0x7ff;
        pQuality->agc = Agc;
        break;
    case TV_QUAL_BEC:
#ifdef EN_AUTOTEST
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN));
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN));
        }
        REALTEK_I_DVBS2_DBG("TV_QUAL_PEC\n");
        REALTEK_I_DVBS2_DBG("GetTsPktCnt %u\n", PakN);
        REALTEK_I_DVBS2_DBG("GetBadPktCnt %u\n", BadPakN);
        REALTEK_I_DVBS2_DBG("prePecPakN %u\n", prePecPakN);
        REALTEK_I_DVBS2_DBG("prePecBadPakN %u\n", prePecBadPakN);
        if (PakN > prePecPakN) {
            pQuality->layer_ber.ber_num = BadPakN-prePecBadPakN;
            pQuality->layer_ber.ber_den = PakN-prePecPakN;
            REALTEK_I_DVBS2_DBG("Cal\n");
        } else  {
            pQuality->layer_ber.ber_num = 0;
            pQuality->layer_ber.ber_den = 0;
            REALTEK_I_DVBS2_DBG("Skip\n");
        }

        if( (preReportBadPakN > BAD_PAK_THRESHOLD) && ((PakN-prePecPakN) == 0)){
            pQuality->layer_ber.ber_num = preReportBadPakN;
            preReportBadPakN = preReportBadPakN;
        }
        else{
            preReportBadPakN = BadPakN-prePecBadPakN;
        }

        prePecPakN = PakN;
        prePecBadPakN = BadPakN;
        
        #ifndef PER_COLOR_ENABLE
        REALTEK_I_DVBS2_DBG("pQuality->layer_ber.ber_den %d\n", pQuality->layer_ber.ber_den);
        REALTEK_I_DVBS2_DBG("pQuality->layer_ber.ber_num %d\n", pQuality->layer_ber.ber_num);
        #else
        if(pQuality->layer_ber.ber_num > 0)
        {
            REALTEK_I_DVBS2_INFO("!!!!!!!!!!!!!!!!!!!!\n");
            REALTEK_I_DVBS2_INFO("!!!!!!!!!!!!!!!!!!!!\n");
            REALTEK_I_DVBS2_INFO("Packet Err %lu\n", pQuality->layer_ber.ber_num);
        }
        else
        {
            REALTEK_I_DVBS2_INFO("Packet Err %lu\n", pQuality->layer_ber.ber_num);
        }
        #endif
#else
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN));
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN));
        }
        REALTEK_I_DVBS2_DBG("TV_QUAL_BEC\n");
        REALTEK_I_DVBS2_DBG("GetTsPktCnt %u\n", PakN);
        REALTEK_I_DVBS2_DBG("GetBadPktCnt %u\n", BadPakN);
        REALTEK_I_DVBS2_DBG("preBecPakN %u\n", preBecPakN);
        REALTEK_I_DVBS2_DBG("preBecBadPakN %u\n", preBecBadPakN);
        if (PakN > preBecPakN) {
            pQuality->layer_ber.ber_num = (BadPakN-preBecBadPakN) * 36;
            pQuality->layer_ber.ber_den = (PakN-preBecPakN) * 204 * 8;
            REALTEK_I_DVBS2_DBG("Cal\n");
        }  else  {
            pQuality->layer_ber.ber_num = 0;
            pQuality->layer_ber.ber_den = 0;
            REALTEK_I_DVBS2_DBG("Skip\n");
        }
        preBecPakN = PakN;
        preBecBadPakN = BadPakN;
        REALTEK_I_DVBS2_DBG("pQuality->layer_ber.ber_num %lu\n", pQuality->layer_ber.ber_num);
        REALTEK_I_DVBS2_DBG("pQuality->layer_ber.ber_den %lu\n", pQuality->layer_ber.ber_den);
#endif
        break;
    case TV_QUAL_PEC:
#ifdef EN_AUTOTEST
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN));
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN));
        }
        pQuality->layer_per.per_num = BadPakN;
        pQuality->layer_per.per_den = PakN;
#else
        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN);//GetTsPktCnt
            PakN &= DVBS2_BITFLD_TS_PACKET_COUNT;
            ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN);//GetBadPktCnt
            BadPakN &= DVBS2_BITFLD_BAD_PACKET_COUNT;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &PakN));
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BAD_PACKET_COUNT, NULL_SEC_ADDR, &BadPakN));
        }
        REALTEK_I_DVBS2_DBG("TV_QUAL_PEC\n");
        REALTEK_I_DVBS2_DBG("GetTsPktCnt %u\n", PakN);
        REALTEK_I_DVBS2_DBG("GetBadPktCnt %u\n", BadPakN);
        REALTEK_I_DVBS2_DBG("prePecPakN %u\n", prePecPakN);
        REALTEK_I_DVBS2_DBG("prePecBadPakN %u\n", prePecBadPakN);
        if (PakN > prePecPakN) {
            pQuality->layer_per.per_num = BadPakN-prePecBadPakN;
            pQuality->layer_per.per_den = PakN-prePecPakN;
            REALTEK_I_DVBS2_DBG("Cal\n");
        } else  {
            pQuality->layer_per.per_num = 0;
            pQuality->layer_per.per_den = 0;
            REALTEK_I_DVBS2_DBG("Skip\n");
        }

        if( (preReportBadPakN > BAD_PAK_THRESHOLD) && ((PakN-prePecPakN) == 0)){
            pQuality->layer_per.per_num = preReportBadPakN;
            preReportBadPakN = preReportBadPakN;
        }
        else{
            preReportBadPakN = BadPakN-prePecBadPakN;
        }

        prePecPakN = PakN;
        prePecBadPakN = BadPakN;
        
        #ifndef PER_COLOR_ENABLE
        REALTEK_I_DVBS2_DBG("pQuality->layer_per.per_den %lu\n", pQuality->layer_per.per_den);
        REALTEK_I_DVBS2_DBG("pQuality->layer_per.per_num %lu\n", pQuality->layer_per.per_num);
        #else
        if(pQuality->layer_per.per_num > 0)
        {
            REALTEK_I_DVBS2_INFO("!!!!!!!!!!!!!!!!!!!!\n");
            REALTEK_I_DVBS2_INFO("!!!!!!!!!!!!!!!!!!!!\n");
            REALTEK_I_DVBS2_INFO("Packet Err %lu\n", pQuality->layer_per.per_num);
        }
        else
        {
            REALTEK_I_DVBS2_INFO("Packet Err %lu\n", pQuality->layer_per.per_num);
        }
        #endif
#endif
        break;
    case TV_QUAL_DEMODFWVERSION:
        pQuality->DemodFwVersion = 0x000001;
        break;
    default:
        break;
    }




#ifdef SUPPORT_WINTOOL
    }
#endif

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


/*----------------------------------------------------------------------
 * Func : GetCarrierOffset
 *
 * Desc : Get the carrier offset.
 *
 * Parm : pOffset : carrier frequency offset output (unit : Hz)
 *
 *          Note: the offset value is only valid as demod is on lock stage.
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetCarrierOffset(DEMOD* pDemodKernel, long* pOffset)
{
    int ret = TUNER_CTRL_OK;
    unsigned int Cfo = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS2))
        return TUNER_CTRL_FAIL;

    pDemodKernel->Lock(pDemodKernel);
    
#ifdef SUPPORT_WINTOOL
    if(!pRealtekIDVBS2->m_debug_tool_en)
    {
#endif




    if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
    {
        ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &Cfo);//GetCarrierFreqOffset
        Cfo &= DVBS2_BITFLD_CARRIER_FREQ_OFFSET;
    }
    else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
    {
        ret |= pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &Cfo);//GetCarrierFreqOffset
        Cfo &= DVBS2X_BITFLD_CARRIER_FREQ_OFFSET;
    }
    else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
    {
        ret |= pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &Cfo);
    }
    *pOffset = Cfo;

    REALTEK_I_DVBS2_INFO("GetCarrierOffset %ld\n", *pOffset);


#ifdef SUPPORT_WINTOOL
    }
#endif

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}
/*----------------------------------------------------------------------
 * Func : GetDebugLogBuf
 *
 * Desc : Get the debug log Buf.
 *
 * Parm : 
 *
 *          
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetDebugLogBuf(DEMOD* pDemodKernel, unsigned int* LogBufAddr, unsigned int* LogBufSize)
{
    int ret = TUNER_CTRL_OK;
    unsigned int ReadValue = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    if (pDemod) {
        ret|=pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_PTR, NULL_SEC_ADDR, &ReadValue);
        * LogBufAddr = ReadValue;
        ret|=pDemod->GetVirtualRegister(pDemod, TV_REG_ENSIGMA_SDK_BUFF_SIZE, NULL_SEC_ADDR, &ReadValue);
        * LogBufSize = ReadValue;
        if(ret!=TUNER_CTRL_OK)
        {
            * LogBufAddr = 0;
            * LogBufSize = 0;
        }
    }
    else
    {
        * LogBufAddr = 0;
        * LogBufSize = 0;
    }

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


#ifdef INVERSE_SPECTRUM
void REALTEK_I_DVBS2_ReverseArray(unsigned short *pintArray, unsigned int intArraySize)
{
    unsigned short intBuf = 0;
    int i = 0;

    for(i=(intArraySize-1);i>(intArraySize-1)/2;i--)
    {
        if(i!=(intArraySize-1-i))
        {
            intBuf=*(pintArray+i);
            *(pintArray+i)=*(pintArray+(intArraySize-1-i));
            *(pintArray+(intArraySize-1-i))=intBuf;
        }
        else
        {
            break;
        }
    }
}
#endif


/*----------------------------------------------------------------------
 * Func : SpecAnGetSpectrum
 *
 * Desc : Get spectrum data.
 *
 * Parm : Mode : Select mode for getting spectrum
 *        SpectrumArray : Spectrum data result
 *        SpectrumLength : Spectrum data length
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SpecAnGetSpectrum(DEMOD* pDemodKernel, unsigned int *SpectrumArray, unsigned int *SpectrumLength)
{
    int ret = TUNER_CTRL_OK;
    static unsigned int DemodVirAddrStart = 0;
    static unsigned int DemodVirAddrtEnd = 0;
    unsigned long stime = 0, etime = 0;
    unsigned char lock = 0, Tuned = 0;
    unsigned int DemodStatus, BwRequest = 0, FreqRequest = 0;
    unsigned int SpecMemType = 0, SpecMemPtr = 0, x = 0;
    unsigned int RegVal = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_SPEC_AN_BS_MODE)
        REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_SPEC_AN_BS_MODE);

    pDemodKernel->Lock(pDemodKernel);

    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect

    stime = tv_osal_time();
    lock = NO;
    while ((tv_osal_time() - stime) <= 2000) {
        tv_osal_msleep(5);

        if(Tuned == 0)
        {
            Tuned = 1;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ACTIVE_TUNER_BW, NULL_SEC_ADDR, &BwRequest));//GetActiveTunerBandwidth
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ACTIVE_TUNER_FREQ, NULL_SEC_ADDR, &FreqRequest));//GetActiveTunerFreq

            if(BwRequest!=0 && FreqRequest!=0xFFFFFFFF)
            {
                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, BwRequest));//SetTunerBandwidth
                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, FreqRequest));//SetTunerFreq
            }
        }

        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

        if(DemodStatus == 3)
        {
            etime = tv_osal_time();
            lock = YES;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod,SA_REG_OUT_SPECTRUM_PTR, NULL_SEC_ADDR, &RegVal));//DvbS2GetSpecAnOutSpectrumPtr
            SpecMemType = (RegVal & SA_BITFLD_OUT_SPECTRUM_MEM_TYPE) >> 30;
            SpecMemPtr = (RegVal & SA_BITFLD_OUT_SPECTRUM_PTR);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, SA_OUT_SPECTRUM_LEN, NULL_SEC_ADDR, SpectrumLength));//DvbS2GetSpecAnOutSpectrumLen
            *SpectrumLength &= SA_BITFLD_OUT_SPECTRUM_LEN;
            break;
        }
        etime = tv_osal_time();
    }
    
    pDemodKernel->Unlock(pDemodKernel);
    
    DemodVirAddrStart = (unsigned int) phys_to_virt(DEMOD_MEM_START_PHYS);
    DemodVirAddrtEnd = (unsigned int) phys_to_virt(DEMOD_MEM_END_PHYS);

    memcpy(pRealtekIDVBS2->BlindscanSpectrum_dvbs2, (void *)(DemodVirAddrStart+((SpecMemPtr-0x840000)<<2)+0x100000), (*SpectrumLength*2));

    dmac_flush_range((void *)DemodVirAddrStart, (void *)DemodVirAddrtEnd);
    outer_flush_range(DEMOD_MEM_START_PHYS, DEMOD_MEM_END_PHYS);

    #ifdef INVERSE_SPECTRUM
    REALTEK_I_DVBS2_ReverseArray(pRealtekIDVBS2->BlindscanSpectrum_dvbs2, *SpectrumLength);
    #endif
    
    //smooth spectrum
    #ifdef PRINT_SPECTRUM
    REALTEK_I_DVBS2_INFO("====================================\n");
    #endif

    for(x=0;x<*SpectrumLength;x++)
    {
        if((x>=7) && (x<*SpectrumLength-7))
        {
            pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x] = (pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-7]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-6]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-5]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-4]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-3]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-2]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x-1]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x]+
                pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+1]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+2]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+3]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+4]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+5]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+6]+pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x+7])/15;
        }

        //SpectrumArray[x] = ((unsigned int)pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x])*(pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x]-50000)>>10;
        SpectrumArray[x] = (unsigned int)pRealtekIDVBS2->BlindscanSpectrum_dvbs2[x];
        
        #ifdef PRINT_SPECTRUM
        printk("[ %u ]\n", SpectrumArray[x]);
        if(x%100==0)
            tv_osal_msleep(800);
        #endif
    }
    #ifdef PRINT_SPECTRUM
    REALTEK_I_DVBS2_INFO("====================================\n");
    #endif

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SpecAnGetCp1Cp2
 *
 * Desc : Get cross points in the spectrum.
 *
 * Parm : SpectrumArray : Input spectrum data
 *        CutTh : Set threshold for finding cross points
 *        CutSp : Set start point for finding cross points
 *        CutEp : Set end point for finding cross points
 *        ReturnCp1 : Cross point 1 result
 *        ReturnCp2 : Cross point 2 result
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SpecAnGetCp1Cp2(
    DEMOD* pDemodKernel,
    unsigned int *SpectrumArray,
    unsigned int SkipDc,
    unsigned int CutSp,
    unsigned int CutEp,
    short *AllCutCandidateNum,
    short *AllCutCandidateCp1,
    short *AllCutCandidateCp2,
    unsigned int CutTh_1st,
    unsigned int CutTh_2nd,
    unsigned int CutTh_3rd,
    unsigned int CutTh_4th,
    unsigned int CutTh_5th,
    unsigned int CutTh_6th)
{
    short SpecIdx = 0, u8i = 0, u8j = 0;
    unsigned int freq_process = 0, pre_freq_process = 0;
    short Cp1_1st = -1, Cp2_1st = -1, Cp1Done_1st = 0, Cp2Done_1st = 0;
    short Cp1_2nd = -1, Cp2_2nd = -1, Cp1Done_2nd = 0, Cp2Done_2nd = 0;
    short Cp1_3rd = -1, Cp2_3rd = -1, Cp1Done_3rd = 0, Cp2Done_3rd = 0;
    short Cp1_4th = -1, Cp2_4th = -1, Cp1Done_4th = 0, Cp2Done_4th = 0;
    short Cp1_5th = -1, Cp2_5th = -1, Cp1Done_5th = 0, Cp2Done_5th = 0;
    //short Cp1_6th = -1, Cp2_6th = -1, Cp1Done_6th = 0, Cp2Done_6th = 0;

    short CutCandidateNum_1st = 0, CutCandidateCp1_1st[32] = {0}, CutCandidateCp2_1st[32] = {0};
    short CutCandidateNum_2nd = 0, CutCandidateCp1_2nd[32] = {0}, CutCandidateCp2_2nd[32] = {0};
    short CutCandidateNum_3rd = 0, CutCandidateCp1_3rd[32] = {0}, CutCandidateCp2_3rd[32] = {0};
    short CutCandidateNum_4th = 0, CutCandidateCp1_4th[32] = {0}, CutCandidateCp2_4th[32] = {0};
    short CutCandidateNum_5th = 0, CutCandidateCp1_5th[32] = {0}, CutCandidateCp2_5th[32] = {0};
    //short CutCandidateNum_6th = 0, CutCandidateCp1_6th[32] = {0}, CutCandidateCp2_6th[32] = {0};
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    for(SpecIdx=CutSp; SpecIdx<=CutEp; SpecIdx++)
    {
        //------------------------------------------------------------------------------------------
        //    1st Threshold
        //------------------------------------------------------------------------------------------
        //CP1
        if(SpectrumArray[SpecIdx-1]<CutTh_1st && SpectrumArray[SpecIdx]>=CutTh_1st && Cp1Done_1st == 0)
        {
            Cp1Done_1st = 1;
            Cp1_1st = SpecIdx;
          
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp1_1st = %d\n", Cp1_1st);
            #endif
        }

        //CP2
        if(SpectrumArray[SpecIdx-1]>CutTh_1st && SpectrumArray[SpecIdx]<=CutTh_1st && Cp1Done_1st == 1 && Cp2Done_1st == 0)
        {
            Cp2Done_1st = 1;
            Cp2_1st = SpecIdx;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp2_1st = %d\n", Cp2_1st);
            #endif
        }
        
        if(Cp1Done_1st == 1 && Cp2Done_1st == 1)
        {
            CutCandidateCp1_1st[CutCandidateNum_1st] = Cp1_1st;
            CutCandidateCp2_1st[CutCandidateNum_1st] = Cp2_1st;
            CutCandidateNum_1st++;
            Cp1Done_1st = 0;
            Cp2Done_1st = 0;
        }
        else if(SpecIdx == CutEp && Cp1Done_1st == 1 && Cp2Done_1st == 0)
        {
            CutCandidateCp1_1st[CutCandidateNum_1st] = Cp1_1st;
            CutCandidateCp2_1st[CutCandidateNum_1st] = -1;
            CutCandidateNum_1st++;
        }
        else if(SpecIdx == CutEp && Cp1Done_1st == 0 && Cp2Done_1st == 0)
        {
            CutCandidateCp1_1st[CutCandidateNum_1st] = -1;
            CutCandidateCp2_1st[CutCandidateNum_1st] = -1;
            CutCandidateNum_1st++;
        }
        
        
        //------------------------------------------------------------------------------------------
        //    2nd Threshold
        //------------------------------------------------------------------------------------------
        //CP1
        if(SpectrumArray[SpecIdx-1]<CutTh_2nd && SpectrumArray[SpecIdx]>=CutTh_2nd && Cp1Done_2nd == 0)
        {
            Cp1Done_2nd = 1;
            Cp1_2nd = SpecIdx;
          
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp1_2nd = %d\n", Cp1_2nd);
            #endif
        }

        //CP2
        if(SpectrumArray[SpecIdx-1]>CutTh_2nd && SpectrumArray[SpecIdx]<=CutTh_2nd && Cp1Done_2nd == 1 && Cp2Done_2nd == 0)
        {
            Cp2Done_2nd = 1;
            Cp2_2nd = SpecIdx;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp2_2nd = %d\n", Cp2_2nd);
            #endif
        }
        
        if(Cp1Done_2nd == 1 && Cp2Done_2nd == 1)
        {
            CutCandidateCp1_2nd[CutCandidateNum_2nd] = Cp1_2nd;
            CutCandidateCp2_2nd[CutCandidateNum_2nd] = Cp2_2nd;
            CutCandidateNum_2nd++;
            Cp1Done_2nd = 0;
            Cp2Done_2nd = 0;
        }
        else if(SpecIdx == CutEp && Cp1Done_2nd == 1 && Cp2Done_2nd == 0)
        {
            CutCandidateCp1_2nd[CutCandidateNum_2nd] = Cp1_2nd;
            CutCandidateCp2_2nd[CutCandidateNum_2nd] = -1;
            CutCandidateNum_2nd++;
        }
        else if(SpecIdx == CutEp && Cp1Done_2nd == 0 && Cp2Done_2nd == 0)
        {
            CutCandidateCp1_2nd[CutCandidateNum_2nd] = -1;
            CutCandidateCp2_2nd[CutCandidateNum_2nd] = -1;
            CutCandidateNum_2nd++;
        }

        
        //------------------------------------------------------------------------------------------
        //    3rd Threshold
        //------------------------------------------------------------------------------------------
        //CP1
        if(SpectrumArray[SpecIdx-1]<CutTh_3rd && SpectrumArray[SpecIdx]>=CutTh_3rd && Cp1Done_3rd == 0)
        {
            Cp1Done_3rd = 1;
            Cp1_3rd = SpecIdx;
          
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp1_3rd = %d\n", Cp1_3rd);
            #endif
        }

        //CP2
        if(SpectrumArray[SpecIdx-1]>CutTh_3rd && SpectrumArray[SpecIdx]<=CutTh_3rd && Cp1Done_3rd == 1 && Cp2Done_3rd == 0)
        {
            Cp2Done_3rd = 1;
            Cp2_3rd = SpecIdx;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp2_3rd = %d\n", Cp2_3rd);
            #endif
        }
        
        if(Cp1Done_3rd == 1 && Cp2Done_3rd == 1)
        {
            CutCandidateCp1_3rd[CutCandidateNum_3rd] = Cp1_3rd;
            CutCandidateCp2_3rd[CutCandidateNum_3rd] = Cp2_3rd;
            CutCandidateNum_3rd++;
            Cp1Done_3rd = 0;
            Cp2Done_3rd = 0;
        }
        else if(SpecIdx == CutEp && Cp1Done_3rd == 1 && Cp2Done_3rd == 0)
        {
            CutCandidateCp1_3rd[CutCandidateNum_3rd] = Cp1_3rd;
            CutCandidateCp2_3rd[CutCandidateNum_3rd] = -1;
            CutCandidateNum_3rd++;
        }
        else if(SpecIdx == CutEp && Cp1Done_3rd == 0 && Cp2Done_3rd == 0)
        {
            CutCandidateCp1_3rd[CutCandidateNum_3rd] = -1;
            CutCandidateCp2_3rd[CutCandidateNum_3rd] = -1;
            CutCandidateNum_3rd++;
        }
        
        
        //------------------------------------------------------------------------------------------
        //    4th Threshold
        //------------------------------------------------------------------------------------------
        //CP1
        if(SpectrumArray[SpecIdx-1]<CutTh_4th && SpectrumArray[SpecIdx]>=CutTh_4th && Cp1Done_4th == 0)
        {
            Cp1Done_4th = 1;
            Cp1_4th = SpecIdx;
          
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp1_4th = %d\n", Cp1_4th);
            #endif
        }

        //CP2
        if(SpectrumArray[SpecIdx-1]>CutTh_4th && SpectrumArray[SpecIdx]<=CutTh_4th && Cp1Done_4th == 1 && Cp2Done_4th == 0)
        {
            Cp2Done_4th = 1;
            Cp2_4th = SpecIdx;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp2_4th = %d\n", Cp2_4th);
            #endif
        }
        
        if(Cp1Done_4th == 1 && Cp2Done_4th == 1)
        {
            CutCandidateCp1_4th[CutCandidateNum_4th] = Cp1_4th;
            CutCandidateCp2_4th[CutCandidateNum_4th] = Cp2_4th;
            CutCandidateNum_4th++;
            Cp1Done_4th = 0;
            Cp2Done_4th = 0;
        }
        else if(SpecIdx == CutEp && Cp1Done_4th == 1 && Cp2Done_4th == 0)
        {
            CutCandidateCp1_4th[CutCandidateNum_4th] = Cp1_4th;
            CutCandidateCp2_4th[CutCandidateNum_4th] = -1;
            CutCandidateNum_4th++;
        }
        else if(SpecIdx == CutEp && Cp1Done_4th == 0 && Cp2Done_4th == 0)
        {
            CutCandidateCp1_4th[CutCandidateNum_4th] = -1;
            CutCandidateCp2_4th[CutCandidateNum_4th] = -1;
            CutCandidateNum_4th++;
        }
        
        /*
        //------------------------------------------------------------------------------------------
        //    5th Threshold
        //------------------------------------------------------------------------------------------
        //CP1
        if(SpectrumArray[SpecIdx-1]<CutTh_5th && SpectrumArray[SpecIdx]>=CutTh_5th && Cp1Done_5th == 0)
        {
            Cp1Done_5th = 1;
            Cp1_5th = SpecIdx;
          
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp1_5th = %d\n", Cp1_5th);
            #endif
        }

        //CP2
        if(SpectrumArray[SpecIdx-1]>CutTh_5th && SpectrumArray[SpecIdx]<=CutTh_5th && Cp1Done_5th == 1 && Cp2Done_5th == 0)
        {
            Cp2Done_5th = 1;
            Cp2_5th = SpecIdx;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Cp2_5th = %d\n", Cp2_5th);
            #endif
        }
        
        if(Cp1Done_5th == 1 && Cp2Done_5th == 1)
        {
            CutCandidateCp1_5th[CutCandidateNum_5th] = Cp1_5th;
            CutCandidateCp2_5th[CutCandidateNum_5th] = Cp2_5th;
            CutCandidateNum_5th++;
            Cp1Done_5th = 0;
            Cp2Done_5th = 0;
        }
        else if(SpecIdx == CutEp && Cp1Done_5th == 1 && Cp2Done_5th == 0)
        {
            CutCandidateCp1_5th[CutCandidateNum_5th] = Cp1_5th;
            CutCandidateCp2_5th[CutCandidateNum_5th] = -1;
            CutCandidateNum_5th++;
        }
        else if(SpecIdx == CutEp && Cp1Done_5th == 0 && Cp2Done_5th == 0)
        {
            CutCandidateCp1_5th[CutCandidateNum_5th] = -1;
            CutCandidateCp2_5th[CutCandidateNum_5th] = -1;
            CutCandidateNum_5th++;
        }
        */
    }
    
    *AllCutCandidateNum = CutCandidateNum_1st + CutCandidateNum_2nd + CutCandidateNum_3rd + CutCandidateNum_4th + CutCandidateNum_5th;
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("CutCandidateNum_1st %u CutCandidateNum_2nd %u CutCandidateNum_3rd %u CutCandidateNum_4th %u CutCandidateNum_5th %u\n", CutCandidateNum_1st, CutCandidateNum_2nd, CutCandidateNum_3rd, CutCandidateNum_4th, CutCandidateNum_5th);
    #endif
    
    u8i = 0;
    
    for(freq_process = 10; freq_process < pRealtekIDVBS2->m_blindscan_spectrum_len+10; freq_process += 10)
    {
        //1st Threshold
        for(u8j = 0; u8j < CutCandidateNum_1st; u8j++)
        {
            if(((CutCandidateCp1_1st[u8j]+CutCandidateCp2_1st[u8j])/2) < freq_process && ((CutCandidateCp1_1st[u8j]+CutCandidateCp2_1st[u8j])/2) >= pre_freq_process)
            {
                AllCutCandidateCp1[u8i] = CutCandidateCp1_1st[u8j];
                AllCutCandidateCp2[u8i] = CutCandidateCp2_1st[u8j];
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("TH1 Add %d CP1 %d\tCP2 %d\n", (CutCandidateCp1_1st[u8j]+CutCandidateCp2_1st[u8j])/2, CutCandidateCp1_1st[u8j], CutCandidateCp2_1st[u8j]);
                #endif
                u8i++;
            }
        }
        
        //2nd Threshold
        for(u8j = 0; u8j < CutCandidateNum_2nd; u8j++)
        {
            if(((CutCandidateCp1_2nd[u8j]+CutCandidateCp2_2nd[u8j])/2) < freq_process && ((CutCandidateCp1_2nd[u8j]+CutCandidateCp2_2nd[u8j])/2) >= pre_freq_process)
            {
                AllCutCandidateCp1[u8i] = CutCandidateCp1_2nd[u8j];
                AllCutCandidateCp2[u8i] = CutCandidateCp2_2nd[u8j];
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("TH2 Add %d CP1 %d\tCP2 %d\n", (CutCandidateCp1_2nd[u8j]+CutCandidateCp2_2nd[u8j])/2, CutCandidateCp1_2nd[u8j], CutCandidateCp2_2nd[u8j]);
                #endif
                u8i++;
            }
        }
        
        //3rd Threshold
        for(u8j = 0; u8j < CutCandidateNum_3rd; u8j++)
        {
            if(((CutCandidateCp1_3rd[u8j]+CutCandidateCp2_3rd[u8j])/2) < freq_process && ((CutCandidateCp1_3rd[u8j]+CutCandidateCp2_3rd[u8j])/2) >= pre_freq_process)
            {
                AllCutCandidateCp1[u8i] = CutCandidateCp1_3rd[u8j];
                AllCutCandidateCp2[u8i] = CutCandidateCp2_3rd[u8j];
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("TH3 Add %d CP1 %d\tCP2 %d\n", (CutCandidateCp1_3rd[u8j]+CutCandidateCp2_3rd[u8j])/2, CutCandidateCp1_3rd[u8j], CutCandidateCp2_3rd[u8j]);
                #endif
                u8i++;
            }
        }
        
        //4th Threshold
        for(u8j = 0; u8j < CutCandidateNum_4th; u8j++)
        {
            if(((CutCandidateCp1_4th[u8j]+CutCandidateCp2_4th[u8j])/2) < freq_process && ((CutCandidateCp1_4th[u8j]+CutCandidateCp2_4th[u8j])/2) >= pre_freq_process)
            {
                AllCutCandidateCp1[u8i] = CutCandidateCp1_4th[u8j];
                AllCutCandidateCp2[u8i] = CutCandidateCp2_4th[u8j];
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("TH4 Add %d CP1 %d\tCP2 %d\n", (CutCandidateCp1_4th[u8j]+CutCandidateCp2_4th[u8j])/2, CutCandidateCp1_4th[u8j], CutCandidateCp2_4th[u8j]);
                #endif
                u8i++;
            }
        }
        
        //5th Threshold
        for(u8j = 0; u8j < CutCandidateNum_5th; u8j++)
        {
            if(((CutCandidateCp1_5th[u8j]+CutCandidateCp2_5th[u8j])/2) < freq_process && ((CutCandidateCp1_5th[u8j]+CutCandidateCp2_5th[u8j])/2) >= pre_freq_process)
            {
                AllCutCandidateCp1[u8i] = CutCandidateCp1_5th[u8j];
                AllCutCandidateCp2[u8i] = CutCandidateCp2_5th[u8j];
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("TH5 Add %d CP1 %d\tCP2 %d\n", (CutCandidateCp1_5th[u8j]+CutCandidateCp2_5th[u8j])/2, CutCandidateCp1_5th[u8j], CutCandidateCp2_5th[u8j]);
                #endif
                u8i++;
            }
        }
        pre_freq_process = freq_process;
    }

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SpecAnCalCfoCsr
 *
 * Desc : Calculate signal carrier frequency offset and course symbol rate.
 *
 * Parm : Mode : Calculation mode
 *        Cp1 : Input cross point 1
 *        Cp2 : Input cross point 2
 *        SigCfo : Carrier frequency offset calculation result
 *        SigCsr : Course symbol rate calculation result
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SpecAnCalCfoCsr(DEMOD* pDemodKernel, short Cp1, short Cp2, int *SigCfo, unsigned int *SigCsr)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    if(Cp1 != -1 && Cp2 != -1)
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("Full Signal Found\n");
        #endif

        *SigCfo = (((Cp1+Cp2)/2)-(pRealtekIDVBS2->m_blindscan_spectrum_len/2))*BS_FFT_RESOLUTION;
        *SigCsr = (Cp2-Cp1)*BS_FFT_RESOLUTION;
        
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("*SigCsr = %d\n", *SigCsr);
        #endif

        /*
        if(*SigCsr >= 3000000) //>3M
        {
            // *SigCsr = *SigCsr*11/10;
            *SigCsr = *SigCsr*10/10;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Csr >= 3M; Csr*1.0\n");
            REALTEK_I_DVBS2_INFO("*SigCsr * 1 = %d\n", *SigCsr);
            #endif
        }
        else
        {
            *SigCsr = *SigCsr;
            
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("Csr < 3M; Csr*1\n");
            REALTEK_I_DVBS2_INFO("*SigCsr * 1 = %d\n", *SigCsr);
            #endif
        }
        */
    }
    else
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("Not Full Signal\n");
        #endif
        *SigCfo = 0;
        *SigCsr = 0;
    }
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("Cal Cfo=%d; Csr=%u\n", *SigCfo, *SigCsr);
    #endif

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SpecAnSearchMaxMin
 *
 * Desc : Get max and min level in the spectrum.
 *
 * Parm : SpectrumArray : Input spectrum data
 *        Sp : Start search point
 *        Ep : End search point
 *        MaxPower : Max level of input spectrum between Sp and Ep
 *        MinPower : Min level of input spectrum between Sp and Ep
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SpecAnSearchMaxMin(
    DEMOD* pDemodKernel,
    unsigned int *SpectrumArray,
    unsigned int Sp,
    unsigned int Ep,
    unsigned int *MaxPower,
    unsigned int *MaxPowerPos,
    unsigned int *MinPower,
    unsigned int *MinPowerPos
)
{
    unsigned int SpecIdx = 0;

    *MaxPower = SpectrumArray[Sp];
    *MinPower = SpectrumArray[Sp];

    for(SpecIdx=Sp; SpecIdx<Ep; SpecIdx++)
    {
        if(SpectrumArray[SpecIdx]>*MaxPower)
        {
            *MaxPower = SpectrumArray[SpecIdx];
            *MaxPowerPos = SpecIdx;
        }
        if(SpectrumArray[SpecIdx]<*MinPower)
        {
            *MinPower = SpectrumArray[SpecIdx];
            *MinPowerPos = SpecIdx;
        }
    }
    return TUNER_CTRL_OK;
}


int REALTEK_I_DVBS2_BlindscanCheckSignalLock(DEMOD* pDemodKernel, unsigned int CCfo, unsigned int Csr, unsigned char *SigLock, unsigned int *FSr, int *FCfo)
{
    unsigned int ActSr = 0, ActCfo = 0, DemodStatus = 0;
    unsigned int AcqTime = 0, Cfo = 0, AcqState = 0, MaxAcqState = 0;
    unsigned char lock = 0;
    unsigned long check_stime = 0, stime = 0, etime = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    if(Csr < MIN_CSR || Csr > MAX_CSR)
    {
        REALTEK_I_DVBS2_INFO("BlindScan Check SR over Range\n");
        return TUNER_CTRL_OK;
    }
    
    if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS_MODE)
    {
        REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
    }

    pDemodKernel->Lock(pDemodKernel);

    ActCfo = CCfo;
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 1));
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, Csr));
    REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_symbolrate = %u\n", Csr);
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
    //Set Bandwidth and Frequency to Acknowledge Demod to Lock
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, Csr));//SetTunerBandwidth
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

    pRealtekIDVBS2->m_AcqTimeOut = 600;

    check_stime = tv_osal_time();
    stime = tv_osal_time();
    lock = NO;
    MaxAcqState = 0;
    while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
        tv_osal_msleep(5);
    
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
        if(MaxAcqState < AcqState && AcqState <= 30)
            MaxAcqState = AcqState;

        if(DemodStatus == 5 || MaxAcqState >= 10)
        {
            etime = tv_osal_time();
            lock = YES;
            REALTEK_I_DVBS2_INFO("BlindScan Check Signal Stable!!!\n");
            break;
        }
        else if(tv_osal_time() - stime >= 200 && MaxAcqState <= 6)
        {
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("BlindScan Check No Signal!!!\n");
            goto Blindscan_Check_Stable_End;
        }
        else
        {
            etime = tv_osal_time();
        }
    }
    ret |= pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &Cfo);//Use DVBS LDR to check signal. Only can get DVBS CFO
    REALTEK_I_DVBS2_INFO("DVBS_REG_CARRIER_FREQ_OFFSET=%d\n", Cfo);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_CFO, NULL_SEC_ADDR, &ActCfo);//DVBS2 use CCFO to adjust Frequency
    REALTEK_I_DVBS2_INFO("DVBS_REG_COARSE_CFO=%d\n", ActCfo);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSr));
    REALTEK_I_DVBS2_INFO("DvbSGetActiveBaudRate=%d\n", ActSr);
    REALTEK_I_DVBS2_INFO("DVBS MaxAcqState=%d\n", MaxAcqState);
    REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-check_stime, AcqTime);

    *SigLock = lock;
    *FSr = ActSr;

    if(ActSr > 46000000)
    {
        *SigLock = NO;
        goto Blindscan_Check_Stable_End;
    }

    if(lock == YES)
        goto Blindscan_Check_Stable_End;
    
    if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
    {
        REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
    }

    ActCfo = CCfo;
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 1));
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR, Csr));
    REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_symbolrate = %u\n", Csr);
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
    //Set Bandwidth and Frequency to Acknowledge Demod to Lock
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, Csr));//SetTunerBandwidth
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

    pRealtekIDVBS2->m_AcqTimeOut = 750;

    check_stime = tv_osal_time();
    stime = tv_osal_time();
    lock = NO;
    MaxAcqState = 0;
    while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
        tv_osal_msleep(5);
    
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
        if(MaxAcqState < AcqState && AcqState <= 30)
            MaxAcqState = AcqState;

        if(DemodStatus == 5 || MaxAcqState >= 10)
        {
            etime = tv_osal_time();
            lock = YES;
            REALTEK_I_DVBS2_INFO("BlindScan Check Signal Stable!!!\n");
            break;
        }
        else if(tv_osal_time() - stime >= 200 && MaxAcqState <= 6)
        {
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("BlindScan Check No Signal!!!\n");
            goto Blindscan_Check_Stable_End;
        }
        else
        {
            etime = tv_osal_time();
        }
    }
    ret |= pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &Cfo);//Use DVBS2 LDR to check signal. Only can get DVBS2 CFO
    REALTEK_I_DVBS2_INFO("DVBS2_REG_CARRIER_FREQ_OFFSET=%d\n", Cfo);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_CFO, NULL_SEC_ADDR, &ActCfo);//DVBS2 use CCFO to adjust Frequency
    REALTEK_I_DVBS2_INFO("DVBS2_REG_COARSE_CFO=%d\n", ActCfo);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSr));
    REALTEK_I_DVBS2_INFO("DvbS2GetActiveBaudRate=%d\n", ActSr);
    REALTEK_I_DVBS2_INFO("DVBS2 MaxAcqState=%d\n", MaxAcqState);
    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-check_stime, AcqTime);

    *SigLock = lock;
    *FSr = ActSr;
    
    if(ActSr > 46000000)
        *SigLock = NO;

Blindscan_Check_Stable_End:
    if(ActSr > 8000000)//SR>8M use CCFO to compensate, others no compensation
    {
        *FCfo = ActCfo;
    }
    
    REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_BlindscanCheckSignalLock %u %u %d\n", *SigLock, *FSr, *FCfo);

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : BlindscanAnalyzeSpectrum
 *
 * Desc : Analyze spectrum.
 *
 * Parm : SignalFound : Is there a signal in the spectrum
 *        SigCfo : Signal carrier offest in the spectrum (unit : Hz)
 *        SigCsr : Signal course symbol rate in the spectrum (unit : Hz)
 *        NextStep : Next tuner move step (unit : Hz)
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindscanAnalyzeSpectrum(DEMOD* pDemodKernel, unsigned char *SignalFound, int *SigCfo, unsigned int *SigCsr, unsigned int *NextStep)
{
    unsigned int MaxPower = 0, MinPower = 0, MaxPowerPos = 0, MinPowerPos = 0, Sp = 0, Ep = 0;
    unsigned int CutTh_1st = 0, CutTh_2nd = 0, CutTh_3rd = 0, CutTh_4th = 0, CutTh_5th = 0, CutTh_6th = 0;
    unsigned char IsCutNoTp = 1, IsCutAllPartial = 1, IsCutPartial = 0;
    unsigned int u8i = 0, MaxCp1 = 0, MaxCp2 = 0, PartialMinCp1 = 1000, PartialCp1Idx = 1000, NextStepCpIdx = 0, SecLast_CP1 = 0, SecLast_CP2 = 0;
    short AllCutCandidateNum = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    *SignalFound = 0;
    Sp = 16;//90;
    Ep = pRealtekIDVBS2->m_blindscan_spectrum_len-16;//-90;
    
    //Get M, m
    REALTEK_I_DVBS2_SpecAnSearchMaxMin(pDemodKernel, pRealtekIDVBS2->BlindscanSpectrum_dvbs2_convert, Sp, Ep, &MaxPower, &MaxPowerPos, &MinPower, &MinPowerPos);

    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("MaxPower = %u(%u)\n", MaxPower, MaxPowerPos);
    REALTEK_I_DVBS2_INFO("MinPower = %u(%u)\n", MinPower, MinPowerPos);
    #endif
    REALTEK_I_DVBS2_INFO("MaxPower-MinPower = %d\n", MaxPower-MinPower);
    
    if(MaxPower-MinPower <= BS_FULL_NO_SIGNAL_TH)
    {
        IsCutNoTp = 1;
        REALTEK_I_DVBS2_INFO("\033[1;32;31m" "BS No Signal in Spectrum(<%u)\n" "\033[m", BS_FULL_NO_SIGNAL_TH);
        goto decide_next_step;
    }
    
    CutTh_1st = ((MaxPower - MinPower)*39/60) + MinPower;
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("CutTh_1st = %u\n", CutTh_1st);
    #endif
    
    CutTh_2nd = ((MaxPower - MinPower)*34/60) + MinPower;//36/60
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("CutTh_2nd = %u\n", CutTh_2nd);
    #endif
    
    CutTh_3rd = ((MaxPower - MinPower)*27/60) + MinPower;//30/60
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("CutTh_3rd = %u\n", CutTh_3rd);
    #endif
    
    CutTh_4th = ((MaxPower - MinPower)*23/60) + MinPower;//24/60
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("CutTh_4th = %u\n", CutTh_4th);
    #endif
    
    CutTh_5th = ((MaxPower - MinPower)*12/60) + MinPower;
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("CutTh_5th = %u\n", CutTh_5th);
    #endif

    //Cp1 Cp2
    memset(pRealtekIDVBS2->BlindscanAllCutCandidateCp1, 0, sizeof(pRealtekIDVBS2->BlindscanAllCutCandidateCp1)/sizeof(short));
    memset(pRealtekIDVBS2->BlindscanAllCutCandidateCp2, 0, sizeof(pRealtekIDVBS2->BlindscanAllCutCandidateCp2)/sizeof(short));
    REALTEK_I_DVBS2_SpecAnGetCp1Cp2(pDemodKernel, pRealtekIDVBS2->BlindscanSpectrum_dvbs2_convert, 0, Sp, Ep, &AllCutCandidateNum, pRealtekIDVBS2->BlindscanAllCutCandidateCp1, pRealtekIDVBS2->BlindscanAllCutCandidateCp2,
    CutTh_1st, CutTh_2nd, CutTh_3rd, CutTh_4th, CutTh_5th, CutTh_6th);
    
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("AllCutCandidateNum = %d\n", AllCutCandidateNum);
    #endif
    
    for(u8i=0; u8i<AllCutCandidateNum; u8i++)
    {
        if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] != -1 && pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] != -1)
        {
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("CP1 = %u CP2 = %u\n", pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i], pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i]);
            #endif
            IsCutNoTp = 0;
            REALTEK_I_DVBS2_SpecAnCalCfoCsr(pDemodKernel, pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i], pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i], SigCfo, SigCsr);
            
            if(*SigCsr > MIN_CSR && *SigCsr < MAX_CSR)
            {
                pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanTpCnt] = pRealtekIDVBS2->m_blindscan_current_freq + *SigCfo;
                pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanTpCnt] = *SigCsr;
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("(%d) pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanTpCnt] = %d\n", pRealtekIDVBS2->BlindscanTpCnt, pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanTpCnt]);
                REALTEK_I_DVBS2_INFO("(%d) pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanTpCnt] = %d\n", pRealtekIDVBS2->BlindscanTpCnt, pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanTpCnt]);
                REALTEK_I_DVBS2_INFO("-----------------------------------------------------------------\n");
                #endif
                pRealtekIDVBS2->BlindscanTpCnt++;
            }
            else
            {
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("CSR Over Range\n");
                REALTEK_I_DVBS2_INFO("-----------------------------------------------------------------\n");
                #endif
            }

            if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] > MaxCp1 && ((pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] - pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i]) > 18))
            {
                MaxCp1 = pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i];
                //REALTEK_I_DVBS2_INFO("MaxCp1 = %u\n", MaxCp1);
            }
            //726 = BS_FFT_RESOLUTION - EP -2M
            if(pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] > MaxCp2 && pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] < 726 && ((pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] - pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i]) > 18))
            {
                MaxCp2 = pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i];
                //REALTEK_I_DVBS2_INFO("MaxCp2 = %u\n", MaxCp2);
            }
        }
        
        IsCutPartial = 0;
        if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] != -1 && pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] == -1)
        {
            IsCutNoTp = 0;
            IsCutPartial = 1;
            if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] < PartialMinCp1)
            {
                PartialMinCp1 = pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i];
                //REALTEK_I_DVBS2_INFO("PartialMinCp1 = %u\n", PartialMinCp1);
            }
            
            /*if(PartialCp1Idx > pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] && pRealtekIDVBS2->m_blindscan_spectrum_len-pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] < (50*12))//keep the min partial CP1(not over 50M)
            {
                PartialCp1Idx = pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i];
            }*/
        }
        IsCutAllPartial &= IsCutPartial;
        
        /*
        if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i] != -1 && pRealtekIDVBS2->BlindscanAllCutCandidateCp2[AllCutCandidateNum-1-u8i] != -1)
        {
            IsCutNoTp = 0;
            REALTEK_I_DVBS2_SpecAnCalCfoCsr(pDemodKernel, pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i], pRealtekIDVBS2->BlindscanAllCutCandidateCp2[AllCutCandidateNum-1-u8i], SigCfo, SigCsr);
            
            if(*SigCsr > MIN_CSR && *SigCsr < MAX_CSR)
            {
                pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanTpCnt] = pRealtekIDVBS2->m_blindscan_current_freq + *SigCfo;
                pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanTpCnt] = *SigCsr;
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("-----------------------------------------------------------------\n");
                REALTEK_I_DVBS2_INFO("(%d) pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanTpCnt] = %d\n", pRealtekIDVBS2->BlindscanTpCnt, pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanTpCnt]);
                REALTEK_I_DVBS2_INFO("(%d) pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanTpCnt] = %d\n", pRealtekIDVBS2->BlindscanTpCnt, pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanTpCnt]);
                #endif
                pRealtekIDVBS2->BlindscanTpCnt++;
            }
            else
            {
                REALTEK_I_DVBS2_INFO("-----------------------------------------------------------------\n");
                REALTEK_I_DVBS2_INFO("CSR Over Range\n");
            }
            
            if(pRealtekIDVBS2->BlindscanAllCutCandidateCp2[AllCutCandidateNum-1-u8i] > MaxCp2)
            {
                MaxCp2 = pRealtekIDVBS2->BlindscanAllCutCandidateCp2[AllCutCandidateNum-1-u8i];
            }
        }
        
        IsCutPartial = 0;
        if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i] != -1 && pRealtekIDVBS2->BlindscanAllCutCandidateCp2[AllCutCandidateNum-1-u8i] == -1)
        {
            IsCutNoTp = 0;
            IsCutPartial = 1;
            if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i] < PartialMinCp1)
            {
                PartialMinCp1 = pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i];
            }
            
            if(PartialCp1Idx > pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i] && pRealtekIDVBS2->m_blindscan_spectrum_len-pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i] < (50*12))//keep the min partial CP1(not over 50M)
            {
                PartialCp1Idx = pRealtekIDVBS2->BlindscanAllCutCandidateCp1[AllCutCandidateNum-1-u8i];
            }
        }
        IsCutAllPartial &= IsCutPartial;
        */
    }

    if(MaxCp2 == 0)//No full signal CP2
    {
        if(PartialMinCp1 == 1000)//No partial case
            IsCutNoTp = 1;
        else
            PartialCp1Idx = PartialMinCp1;
    }
    else
    {
        for(u8i=0; u8i<AllCutCandidateNum; u8i++)
        {
            if(pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i] != -1 && pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] != -1)
            {
                if((pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] < MaxCp1) && (pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i] > SecLast_CP2) 
                    && ((pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i]-pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i]) > 40)) //SecLast must > 3.4M
                {
                    SecLast_CP1 = pRealtekIDVBS2->BlindscanAllCutCandidateCp1[u8i];
                    SecLast_CP2 = pRealtekIDVBS2->BlindscanAllCutCandidateCp2[u8i];
                    #ifdef SPEC_AN_DEBUG
                    REALTEK_I_DVBS2_INFO("SecLast_CP1 = %u  SecLast_CP2 = %u\n", SecLast_CP1, SecLast_CP2);
                    #endif
                }
            }
        }
    }

    if(PartialCp1Idx != 1000)
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("Final is Partial Signal\n");
        #endif
        NextStepCpIdx = PartialCp1Idx-(12*2);
    }
    else
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("Final is Full Siganl\n");
        #endif
        if (SecLast_CP2 == 0)
            NextStepCpIdx = MaxCp2;
        else
            NextStepCpIdx = SecLast_CP2;
    }
    
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("NextStepCpIdx = %u\n", NextStepCpIdx);
    REALTEK_I_DVBS2_INFO("IsCutNoTp = %u\n", IsCutNoTp);
    REALTEK_I_DVBS2_INFO("IsCutAllPartial = %u\n", IsCutAllPartial);
    REALTEK_I_DVBS2_INFO("MaxCp1 = %u\n", MaxCp1);
    REALTEK_I_DVBS2_INFO("MaxCp2 = %u\n", MaxCp2);
    REALTEK_I_DVBS2_INFO("PartialMinCp1 = %u\n", PartialMinCp1);
    REALTEK_I_DVBS2_INFO("PartialCp1Idx = %u\n", PartialCp1Idx);
    REALTEK_I_DVBS2_INFO("SecLast_CP1 = %u\n", SecLast_CP1);
    REALTEK_I_DVBS2_INFO("SecLast_CP2 = %u\n", SecLast_CP2);
    #endif
    
decide_next_step:
    if(IsCutNoTp == 1)
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("NextStep Case 1\n");
        #endif
        //*NextStep = (pRealtekIDVBS2->m_blindscan_spectrum_len*BS_FFT_RESOLUTION)-TUNER_STEP_TOLERANCE-WIN_MARGIN;
        *NextStep = FIX_TUNER_STEP;
    }
    else if(IsCutAllPartial == 1)
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("NextStep Case 2\n");
        #endif
        //*NextStep = (PartialCp1Idx*BS_FFT_RESOLUTION)-TUNER_STEP_TOLERANCE-WIN_MARGIN;
        *NextStep = FIX_TUNER_STEP;
    }
    else
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("NextStep Case 3\n");
        #endif
        //*NextStep = (NextStepCpIdx*BS_FFT_RESOLUTION)-TUNER_STEP_TOLERANCE-WIN_MARGIN;
        *NextStep = FIX_TUNER_STEP;
    }
    
    if(*NextStep < 2000000 || *NextStep > 100000000)
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("Force NextStep to 2M (%u)\n", *NextStep);
        #endif
        *NextStep = 2000000;
    }
    
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("Next Step = %u\n", *NextStep);
    #endif

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_Init
 *
 * Desc : Initiate blindscan.
 *
 * Parm : StartFreqMhz : start frequency for blindscan (unit : Hz)
 *        EndFreqMhz : end frequency for blindscan (unit : Hz)
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_Init(DEMOD* pDemodKernel, unsigned int StartFreqMhz, unsigned int EndFreqMhz)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    REALTEK_I_DVBS2_INFO("\033[1;32;33m" "============= BlindScan_Init =============\n" "\033[m");
    
    pRealtekIDVBS2->m_blindscan_start_freq = StartFreqMhz*1000000;
    pRealtekIDVBS2->m_blindscan_end_freq = EndFreqMhz*1000000;
    REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_start_freq = %u\n", pRealtekIDVBS2->m_blindscan_start_freq);
    REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_end_freq = %u\n", pRealtekIDVBS2->m_blindscan_end_freq);
    
    pRealtekIDVBS2->m_blindscan_first_step = 1;
    pRealtekIDVBS2->BlindscanTpCnt = 0;
    pRealtekIDVBS2->BlindscanAcqTpCnt = 0;
    pRealtekIDVBS2->Blindscan1stPhaseDone = 0;
    pRealtekIDVBS2->m_auto_tune_en = 0;
    
    memset(pRealtekIDVBS2->BlindscanTpFreq, 0, sizeof(pRealtekIDVBS2->BlindscanTpFreq)/sizeof(unsigned int));
    memset(pRealtekIDVBS2->BlindscanTpCpDis, 0, sizeof(pRealtekIDVBS2->BlindscanTpCpDis)/sizeof(unsigned int));
    memset(pRealtekIDVBS2->BlindscanTpCheck, 0, sizeof(pRealtekIDVBS2->BlindscanTpCheck)/sizeof(unsigned int));

    memset(pRealtekIDVBS2->m_blindscan_tp_ref_frequency, 0, sizeof(pRealtekIDVBS2->m_blindscan_tp_ref_frequency)/sizeof(unsigned int));
    memset(pRealtekIDVBS2->m_blindscan_tp_ref_symbolrate, 0, sizeof(pRealtekIDVBS2->m_blindscan_tp_ref_symbolrate)/sizeof(unsigned int));
    memset(pRealtekIDVBS2->m_blindscan_tp_lock_frequency, 0, sizeof(pRealtekIDVBS2->m_blindscan_tp_lock_frequency)/sizeof(unsigned int));
    memset(pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate, 0, sizeof(pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate)/sizeof(unsigned int));
    
    pRealtekIDVBS2->BlindscanFoundTpIdx = 0;
    pRealtekIDVBS2->BlindscanStime = tv_osal_time();
    pRealtekIDVBS2->BlindscanInitDone = 1;
    pRealtekIDVBS2->m_blindscan_sat_index = 0xFFFF;
    pRealtekIDVBS2->m_blindscan_tp_ref_num = 0;
    pRealtekIDVBS2->m_blindscan_tp_ref_idx = 0;
    pRealtekIDVBS2->m_blindscan_tp_lock_idx = 0;

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_GetTunerFreq
 *
 * Desc : Get tuner frequency and tuner bandwidth for current blindscan step.
 *
 * Parm : TunerCenterFreqMhz : tuner frequency (unit : Hz)
 *        TunerCutOffFreqKhz : tuner bandwidth (unit : Hz)
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_GetTunerFreq(DEMOD* pDemodKernel, unsigned int *TunerCenterFreqMhz, unsigned int *TunerCutOffFreqKhz)
{
    unsigned char IsNotDuplicateSig = 1;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("==========================================================================\n");
    #endif
    REALTEK_I_DVBS2_INFO("BlindScan_GetTunerFreq\n");
    
    if(!pRealtekIDVBS2->Blindscan1stPhaseDone)
    {
        *TunerCutOffFreqKhz = 70000000;//Tuner Bw=70M in Blindscan

        if(pRealtekIDVBS2->m_blindscan_first_step == 1)
        {
            *TunerCenterFreqMhz = pRealtekIDVBS2->m_blindscan_start_freq;//First tuner step is Blindscan start frequency(Scan window is 70MHz)
            pRealtekIDVBS2->m_blindscan_current_freq = *TunerCenterFreqMhz;
            pRealtekIDVBS2->m_blindscan_first_step = 0;
        }
        else
        {
            *TunerCenterFreqMhz = pRealtekIDVBS2->m_blindscan_next_freq;//Next tuner step is last Blindscan scan calcelation result step
            pRealtekIDVBS2->m_blindscan_current_freq = *TunerCenterFreqMhz;
        }
        
        *TunerCenterFreqMhz /= 1000000; //MHz
        *TunerCutOffFreqKhz /= 1000; //KHz
    }
    else
    {
next_tp:
        IsNotDuplicateSig = REALTEK_I_DVBS2_BlindscanRemoveDuplicateTp(pDemodKernel, 0);
        if(IsNotDuplicateSig)
        {
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("[Coarse] - Not Duplicate Signal, (%u)/(%u)\n", pRealtekIDVBS2->BlindscanAcqTpCnt, pRealtekIDVBS2->BlindscanTpCnt);
            #endif
            if(
                (pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt] < MIN_CSR || pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt] > MAX_CSR) &&
                (pRealtekIDVBS2->BlindscanAcqTpCnt < pRealtekIDVBS2->BlindscanTpCnt)
            )
            {
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("[Coarse] - !!!! SR Over Range !!!!\n");
                #endif
                pRealtekIDVBS2->BlindscanAcqTpCnt++;
                goto next_tp;
            }
            *TunerCenterFreqMhz = pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanAcqTpCnt]/1000000; //MHz
            *TunerCutOffFreqKhz = pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt]/1000; //KHz
        }
        else
        {
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("[Coarse] - !!!! Duplicate Signal !!!!, (%u)/(%u)\n", pRealtekIDVBS2->BlindscanAcqTpCnt, pRealtekIDVBS2->BlindscanTpCnt);
            REALTEK_I_DVBS2_INFO("[Coarse] - Next TP\n");
            #endif
            pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanAcqTpCnt] = 10;
            pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt] = 10;
            pRealtekIDVBS2->BlindscanAcqTpCnt++;
            
            if(pRealtekIDVBS2->BlindscanAcqTpCnt < pRealtekIDVBS2->BlindscanTpCnt)
            {
                goto next_tp;
            }
        }
        
    }
    pRealtekIDVBS2->m_info.dvbs.freq_khz = *TunerCenterFreqMhz*1000;
    REALTEK_I_DVBS2_INFO("\033[1;32;35m" "*TunerCenterFreqMhz = %u, *TunerCutOffFreqKhz = %u\n" "\033[m", *TunerCenterFreqMhz, *TunerCutOffFreqKhz);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_NextFreq
 *
 * Desc : Check is blindscan done.
 *
 * Parm : bBlindScanEnd : Is blindscan done?
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_NextFreq(DEMOD* pDemodKernel, unsigned int *bBlindScanEnd)
{
    unsigned char SigLock = 0, CheckCnt = 0;
    unsigned int FSr = 0, AcqSr = 0, SrShift = 0, CheckSr = 0;
    int FCfo = 0;
    unsigned long stime = 0, etime = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    REALTEK_I_DVBS2_INFO("BlindScan_GetNextFreq\n");

    if(!pRealtekIDVBS2->Blindscan1stPhaseDone)
    {
        REALTEK_I_DVBS2_SpecAnGetSpectrum(pDemodKernel, pRealtekIDVBS2->BlindscanSpectrum_dvbs2_convert, &pRealtekIDVBS2->m_blindscan_spectrum_len);
        REALTEK_I_DVBS2_BlindscanAnalyzeSpectrum(pDemodKernel, &pRealtekIDVBS2->m_blindscan_signal_found, &pRealtekIDVBS2->m_blindscan_signal_cfo, &pRealtekIDVBS2->m_blindscan_signal_csr, &pRealtekIDVBS2->m_blindscan_tuner_step);

        #ifdef SUPPORT_WINTOOL
        if(rtd_inl(DEBUG_MODE_EN_ADDRESS) == 0x00022243 && rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFC)
        {
            rtd_outl(BLINDSCAN_DBG_SIG_FOUND, pRealtekIDVBS2->m_blindscan_signal_found);
            rtd_outl(BLINDSCAN_DBG_CFO, pRealtekIDVBS2->m_blindscan_signal_cfo);
            rtd_outl(BLINDSCAN_DBG_CSR, pRealtekIDVBS2->m_blindscan_signal_csr);
            rtd_outl(BLINDSCAN_DBG_TUN_STEP, pRealtekIDVBS2->m_blindscan_tuner_step);
        }
        #endif

        if(pRealtekIDVBS2->m_blindscan_signal_found)
        {
            pRealtekIDVBS2->m_blindscan_signal_frequency = pRealtekIDVBS2->m_blindscan_current_freq + pRealtekIDVBS2->m_blindscan_signal_cfo;
            pRealtekIDVBS2->m_blindscan_signal_symbolrate = pRealtekIDVBS2->m_blindscan_signal_csr;
            REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_frequency = %u\n", pRealtekIDVBS2->m_blindscan_signal_frequency);
            REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_symbolrate = %u\n", pRealtekIDVBS2->m_blindscan_signal_symbolrate);
        }

        pRealtekIDVBS2->m_blindscan_next_freq = pRealtekIDVBS2->m_blindscan_current_freq + pRealtekIDVBS2->m_blindscan_tuner_step;

        *bBlindScanEnd = 0;
        if(pRealtekIDVBS2->m_blindscan_next_freq > (pRealtekIDVBS2->m_blindscan_end_freq+10000000))
        {
            pRealtekIDVBS2->Blindscan1stPhaseDone = 1;
        }
    }
    else
    {
        #ifdef SPEC_AN_DEBUG
        REALTEK_I_DVBS2_INFO("(%u)/(%u)\n", pRealtekIDVBS2->BlindscanAcqTpCnt, pRealtekIDVBS2->BlindscanTpCnt);
        #endif
        if(pRealtekIDVBS2->BlindscanAcqTpCnt >= pRealtekIDVBS2->BlindscanTpCnt && pRealtekIDVBS2->m_blindscan_sat_index == 0xFFFF)
        {
            pRealtekIDVBS2->BlindscanTpCnt++;
            stime = tv_osal_time();
            REALTEK_I_DVBS2_Blindscan_TPListEnhancement(pDemodKernel);
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_Blindscan_TPListEnhancement %lu ms\n", etime-stime);
            
            stime = tv_osal_time();
            REALTEK_I_DVBS2_Blindscan_AddTPList(pDemodKernel);
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_Blindscan_AddTPList %lu ms\n", etime-stime);
            
            if(pRealtekIDVBS2->m_blindscan_sat_index == 0xFFFF)
            {
                REALTEK_I_DVBS2_INFO("[bBlindScanEnd]\n");
                *bBlindScanEnd = 1;
                return TUNER_CTRL_OK;
            }
        }
        
        if(pRealtekIDVBS2->m_blindscan_sat_index != 0xFFFF)
        {
            if(pRealtekIDVBS2->m_blindscan_tp_ref_idx >= pRealtekIDVBS2->m_blindscan_tp_ref_num)
            {
                REALTEK_I_DVBS2_INFO("[TP Reference Done]\n");
                *bBlindScanEnd = 1;
                return TUNER_CTRL_OK;
            }
            REALTEK_I_DVBS2_INFO("[TP Reference GO!!!!] ===============================================================\n");
            
            pRealtekIDVBS2->m_blindscan_signal_found = 1;
            pRealtekIDVBS2->m_blindscan_signal_frequency = pRealtekIDVBS2->m_blindscan_tp_ref_frequency[pRealtekIDVBS2->m_blindscan_tp_ref_idx]*1000000;
            pRealtekIDVBS2->m_blindscan_signal_symbolrate = pRealtekIDVBS2->m_blindscan_tp_ref_symbolrate[pRealtekIDVBS2->m_blindscan_tp_ref_idx]*1000;
            REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_frequency = %u\n", pRealtekIDVBS2->m_blindscan_signal_frequency);
            REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_symbolrate = %u\n", pRealtekIDVBS2->m_blindscan_signal_symbolrate);
            pRealtekIDVBS2->m_blindscan_tp_ref_idx++;
            
            return TUNER_CTRL_OK;
        }

        SrShift = 0;
re_check_lock:
        pRealtekIDVBS2->m_blindscan_signal_found = 0;
        AcqSr = pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt];
        CheckSr = AcqSr + SrShift;
        REALTEK_I_DVBS2_BlindscanCheckSignalLock(pDemodKernel, 0, CheckSr, &SigLock, &FSr, &FCfo);
        REALTEK_I_DVBS2_INFO("*SigCsr=%u, SigLock=%u, &Fsr=%u, &CCfo=%d\n", pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt], SigLock, FSr, FCfo);
        
        if(!SigLock)
        {
            if(CheckCnt == 0)
            {
                REALTEK_I_DVBS2_INFO("[REALTEK_I_DVBS2_BlindscanCheckSignalLock Retry 1]\n");
                SrShift = (AcqSr * 4)/10;//modify SR to 1.4x
                
                CheckCnt = 1;
                goto re_check_lock;
            }
            /*
            else if(CheckCnt == 1)
            {
                REALTEK_I_DVBS2_INFO("[REALTEK_I_DVBS2_BlindscanCheckSignalLock Retry 2]\n");
                SrShift = (AcqSr * 5)/10;//modify SR to 1.5x
                
                CheckCnt = 2;
                goto re_check_lock;
            }
            else if(CheckCnt == 2)
            {
                REALTEK_I_DVBS2_INFO("[REALTEK_I_DVBS2_BlindscanCheckSignalLock Retry 3]\n");
                if(AcqSr < 5000000)
                    SrShift = -300000;
                else if(AcqSr < 10000000)
                    SrShift = -1500000;
                else if(AcqSr < 20000000)
                    SrShift = -2000000;
                else if(AcqSr < 30000000)
                    SrShift = -3000000;
                else if(AcqSr < 40000000)
                    SrShift = -4000000;
                else
                    SrShift = -4000000;
                
                CheckCnt = 3;
                goto re_check_lock;
            }
            */
            pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanAcqTpCnt] = 1;
            pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt] = 1;
        }
        else if(SigLock)
        {
            pRealtekIDVBS2->m_blindscan_signal_found = 1;
            pRealtekIDVBS2->m_blindscan_signal_frequency = pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanAcqTpCnt] + FCfo;
            pRealtekIDVBS2->BlindscanTpFreq[pRealtekIDVBS2->BlindscanAcqTpCnt] = pRealtekIDVBS2->m_blindscan_signal_frequency;
            pRealtekIDVBS2->m_blindscan_signal_symbolrate = FSr;
            pRealtekIDVBS2->BlindscanTpCpDis[pRealtekIDVBS2->BlindscanAcqTpCnt] = pRealtekIDVBS2->m_blindscan_signal_symbolrate;
            REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_frequency = %u\n", pRealtekIDVBS2->m_blindscan_signal_frequency);
            REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_blindscan_signal_symbolrate = %u\n", pRealtekIDVBS2->m_blindscan_signal_symbolrate);
        }
        pRealtekIDVBS2->BlindscanAcqTpCnt++;
    }
 
    return TUNER_CTRL_OK;
}

int REALTEK_I_DVBS2_Blindscan_AddTPList(DEMOD* pDemodKernel)
{
    unsigned short u16i = 0, u16j = 0;
    unsigned char u8found = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    REALTEK_I_DVBS2_INFO("=========================================\n");
    REALTEK_I_DVBS2_INFO("Blindscan Acquire Lock List\n");
    REALTEK_I_DVBS2_INFO("=========================================\n");
    
    for(u16i=0; u16i<pRealtekIDVBS2->m_blindscan_tp_lock_idx; u16i++)
    {
        REALTEK_I_DVBS2_INFO("(%02u)\tBS Acquire Lock\t%04u\t%u\n", u16i+1, pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i], pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate[u16i]);
    }
    REALTEK_I_DVBS2_INFO("=========================================\n");

    while(1)
    {
        u8found = 0;
        for(u16i=0; u16i<pRealtekIDVBS2->m_blindscan_tp_lock_idx; u16i++)
        {
            if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] == 0 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] == 0)
                goto FoundTp;
            
            //REALTEK_I_DVBS2_INFO("\033[1;32;35m" "AddTPList Table %u\t%u to BS %u\t%u\n" "\033[m", _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0], _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1], pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i], pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate[u16i]);
            //tv_osal_msleep(30);
            if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] <= pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate[u16i]+100 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] >= pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate[u16i]-100)//SR
            {
                if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] > 0 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] < 8000)//SR
                {
                    if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] <= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]+2 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] >= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]-2)//Freq
                    {
                        u8found++;
                        goto FoundTp;
                    }
                }
                else if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] >= 8000 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] < 14000)//SR
                {
                    if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] <= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]+3 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] >= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]-3)//Freq
                    {
                        u8found++;
                        goto FoundTp;
                    }
                }
                else if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] >= 14000 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] < 21000)//SR
                {
                    if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] <= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]+6 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] >= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]-6)//Freq
                    {
                        u8found++;
                        goto FoundTp;
                    }
                }
                else if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] >= 21000)//SR
                {
                    if(_sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] <= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]+8 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] >= pRealtekIDVBS2->m_blindscan_tp_lock_frequency[u16i]-8)//Freq
                    {
                        u8found++;
                        goto FoundTp;
                    }
                }
            }
        }
FoundTp:
        if(u8found == 0 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] != 0 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1] != 0 &&
            _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] <= 2200 && _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0] >= 900)
        {
            pRealtekIDVBS2->m_blindscan_tp_ref_frequency[pRealtekIDVBS2->m_blindscan_tp_ref_num] = _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][0];
            pRealtekIDVBS2->m_blindscan_tp_ref_symbolrate[pRealtekIDVBS2->m_blindscan_tp_ref_num] = _sBsTpEnhancement[pRealtekIDVBS2->m_blindscan_sat_index][u16j][1];
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "****Add Freq = %u SR = %u\n" "\033[m", pRealtekIDVBS2->m_blindscan_tp_ref_frequency[pRealtekIDVBS2->m_blindscan_tp_ref_num], pRealtekIDVBS2->m_blindscan_tp_ref_symbolrate[pRealtekIDVBS2->m_blindscan_tp_ref_num]);
            pRealtekIDVBS2->m_blindscan_tp_ref_num++;
        }
        else
        {
            //REALTEK_I_DVBS2_INFO("\033[1;32;32m" "Compare Next\n" "\033[m");
        }
        u16j++;
        
        if(u16j >= DVBS2_BS_TP_ENHANCEMENT_MAX_SAT_TABLE_SIZE)
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;31m" "Compare Done\n" "\033[m");
            break;
        }
    }

    return TUNER_CTRL_OK;
}


int REALTEK_I_DVBS2_Blindscan_TPListEnhancement(DEMOD* pDemodKernel)
{
    unsigned short u16i = 0, u16j = 0, u16k = 0, u16max_index = 0, u16same_num = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    if(pRealtekIDVBS2->BlindscanFoundTpIdx <= 3)
    {
        pRealtekIDVBS2->m_blindscan_sat_index = 0xFFFF;
        goto GetSatIdxDone;
    }
    else if(pRealtekIDVBS2->BlindscanFoundTpIdx <= 6)
        u16max_index = pRealtekIDVBS2->BlindscanFoundTpIdx-2;
    else if(pRealtekIDVBS2->BlindscanFoundTpIdx <= 10)
        u16max_index = 6;
    else if(pRealtekIDVBS2->BlindscanFoundTpIdx <= 15)
        u16max_index = 9;
    else//if(pRealtekIDVBS2->BlindscanFoundTpIdx > 15)
        u16max_index = 13;
    
    for(u16k=0; u16k<DVBS2_BS_TP_ENHANCEMENT_SAT_NUM_TABLE_SIZE; u16k++)
    {
        u16same_num = 0;
        for(u16i=0; u16i<pRealtekIDVBS2->BlindscanFoundTpIdx; u16i++)
        {
            for(u16j=0; u16j<DVBS2_BS_TP_ENHANCEMENT_MAX_SAT_TABLE_SIZE; u16j++)
            {
                //REALTEK_I_DVBS2_INFO("\033[1;32;35m" "TPListEnhancement BS %u\t%u to Table %u\t%u\n" "\033[m", pRealtekIDVBS2->BlindscanFoundTpList[u16i*2], pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1], _sBsTpEnhancement[u16k][u16j][0], _sBsTpEnhancement[u16k][u16j][1]);
                //REALTEK_I_DVBS2_INFO("TPListEnhancement BS %u\t%u to Table %u\t%u\n", pRealtekIDVBS2->BlindscanFoundTpList[u16i*2], pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1], _sBsTpEnhancement[u16k][u16j][0], _sBsTpEnhancement[u16k][u16j][1]);
                //tv_osal_msleep(30);
                if(
                    (_sBsTpEnhancement[u16k][u16j][0] != 0 && _sBsTpEnhancement[u16k][u16j][1] != 0) &&
                    (pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] <= _sBsTpEnhancement[u16k][u16j][1]+100 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] >= _sBsTpEnhancement[u16k][u16j][1]-100)//SR
                )
                {
                    if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] > 0 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] < 8000)//SR
                    {
                        if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] <= _sBsTpEnhancement[u16k][u16j][0]+2 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] >= _sBsTpEnhancement[u16k][u16j][0]-2)//Freq
                        {
                            u16same_num++;
                        }
                    }
                    else if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] >= 8000 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] < 14000)//SR
                    {
                        if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] <= _sBsTpEnhancement[u16k][u16j][0]+3 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] >= _sBsTpEnhancement[u16k][u16j][0]-3)//Freq
                        {
                            u16same_num++;
                        }
                    }
                    else if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] >= 14000 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] < 21000)//SR
                    {
                        if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] <= _sBsTpEnhancement[u16k][u16j][0]+5 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] >= _sBsTpEnhancement[u16k][u16j][0]-5)//Freq
                        {
                            u16same_num++;
                        }
                    }
                    else if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2+1] >= 21000)//SR
                    {
                        if(pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] <= _sBsTpEnhancement[u16k][u16j][0]+6 && pRealtekIDVBS2->BlindscanFoundTpList[u16i*2] >= _sBsTpEnhancement[u16k][u16j][0]-6)//Freq
                        {
                            u16same_num++;
                        }
                    }
                }
            }
            if(u16same_num >= u16max_index)
            {
                pRealtekIDVBS2->m_blindscan_sat_index = u16k;
                goto GetSatIdxDone;
            }
        }
    }
    
    
GetSatIdxDone:
    REALTEK_I_DVBS2_INFO("\033[1;32;33m" "pRealtekIDVBS2->m_blindscan_sat_index = %u\n" "\033[m", pRealtekIDVBS2->m_blindscan_sat_index);
    
        
    return TUNER_CTRL_OK;
}


int REALTEK_I_DVBS2_BlindscanRemoveDuplicateTp(DEMOD* pDemodKernel, unsigned char mode)
{
    unsigned short u8i = 0, StartCompareIdx = 0, LastIndex = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    if(mode == 0)
        LastIndex = pRealtekIDVBS2->BlindscanAcqTpCnt;
    else
        LastIndex = pRealtekIDVBS2->BlindscanAcqTpCnt - 1;
    
    #ifdef SPEC_AN_DEBUG
    REALTEK_I_DVBS2_INFO("=================================================================\n");
    REALTEK_I_DVBS2_INFO("Current TP %u, %u\n", pRealtekIDVBS2->BlindscanTpFreq[LastIndex], pRealtekIDVBS2->BlindscanTpCpDis[LastIndex]);
    REALTEK_I_DVBS2_INFO("=================================================================\n");
    #endif
    
    if(LastIndex > 50)
        StartCompareIdx = LastIndex-50;
    
    for(u8i=StartCompareIdx; u8i<=LastIndex-1; u8i++)
    {
        #ifdef SPEC_AN_DEBUG
        //REALTEK_I_DVBS2_INFO("Compare TP (%u) %u, %u\n", u8i, pRealtekIDVBS2->BlindscanTpFreq[u8i], pRealtekIDVBS2->BlindscanTpCpDis[u8i]);
        #endif

        if(mode == 0)//Remove coarse duplicate TPs
        {
            if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] > 0 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 5000000)
            {
                if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+1300000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-1300000 &&
                   pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] <= pRealtekIDVBS2->BlindscanTpCpDis[u8i]+1000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= pRealtekIDVBS2->BlindscanTpCpDis[u8i]-1000000)
                {
                    #ifdef SPEC_AN_DEBUG
                    REALTEK_I_DVBS2_INFO("coarse duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] > 0 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 5000000)\n");
                    #endif
                    return 0;
                }
            }
            else if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 5000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 12000000)
            {
                if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+1700000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-1700000 &&
                   pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] <= pRealtekIDVBS2->BlindscanTpCpDis[u8i]+2400000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= pRealtekIDVBS2->BlindscanTpCpDis[u8i]-2400000)
                {
                    #ifdef SPEC_AN_DEBUG
                    REALTEK_I_DVBS2_INFO("coarse duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 5000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 12000000)\n");
                    #endif
                    return 0;
                }
            }
            else if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 12000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 22000000)
            {
                if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+2000000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-2000000 &&
                   pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] <= pRealtekIDVBS2->BlindscanTpCpDis[u8i]+3600000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= pRealtekIDVBS2->BlindscanTpCpDis[u8i]-3600000)
                {
                    #ifdef SPEC_AN_DEBUG
                    REALTEK_I_DVBS2_INFO("coarse duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 12000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 22000000)\n");
                    #endif
                    return 0;
                }
            }
            else if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 22000000)
            {
                if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+3200000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-3200000 &&
                   pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] <= pRealtekIDVBS2->BlindscanTpCpDis[u8i]+6500000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= pRealtekIDVBS2->BlindscanTpCpDis[u8i]-6500000)
                {
                    #ifdef SPEC_AN_DEBUG
                    REALTEK_I_DVBS2_INFO("coarse duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 22000000)\n");
                    #endif
                    return 0;
                }
            }
        }
        else//mode == 1//Remove fine duplicate TPs
        {
            if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] <= pRealtekIDVBS2->BlindscanTpCpDis[u8i]+200 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= pRealtekIDVBS2->BlindscanTpCpDis[u8i]-200)
            {
                if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] > 0 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 5000000)
                {
                    if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+2100000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-2100000)
                    {
                        #ifdef SPEC_AN_DEBUG
                        REALTEK_I_DVBS2_INFO("fine duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] > 0 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 5000000)\n");
                        #endif
                        return 0;
                    }
                }
                else if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 5000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 12000000)
                {
                    if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+2500000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-2500000)
                    {
                        #ifdef SPEC_AN_DEBUG
                        REALTEK_I_DVBS2_INFO("fine duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 5000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 12000000)\n");
                        #endif
                        return 0;
                    }
                }
                else if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 12000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 22000000)
                {
                    if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+5000000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-5000000)
                    {
                        #ifdef SPEC_AN_DEBUG
                        REALTEK_I_DVBS2_INFO("fine duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 12000000 && pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] < 22000000)\n");
                        #endif
                        return 0;
                    }
                }
                else if(pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 22000000)
                {
                    if(pRealtekIDVBS2->BlindscanTpFreq[LastIndex] <= pRealtekIDVBS2->BlindscanTpFreq[u8i]+9000000 && pRealtekIDVBS2->BlindscanTpFreq[LastIndex] >= pRealtekIDVBS2->BlindscanTpFreq[u8i]-9000000)
                    {
                        #ifdef SPEC_AN_DEBUG
                        REALTEK_I_DVBS2_INFO("fine duplicate @ (pRealtekIDVBS2->BlindscanTpCpDis[LastIndex] >= 22000000)\n");
                        #endif
                        return 0;
                    }
                }
            }
        }
    }
    
    return 1;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_GetStatus
 *
 * Desc : Get blindscan status.
 *
 * Parm : Status : blindscan status
 *        bBlindScanLock : Does blindscan search a signal?
  *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_GetStatus(DEMOD* pDemodKernel, unsigned char *Status, unsigned int *bBlindScanLock)
{
    unsigned char IsNotDuplicateSig = 1;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    REALTEK_I_DVBS2_INFO("BlindScan_GetStatus\n");

    *Status = 0;
    *bBlindScanLock = 0;
    if(pRealtekIDVBS2->m_blindscan_signal_found)
    {
        if(pRealtekIDVBS2->m_blindscan_sat_index == 0xFFFF)
            IsNotDuplicateSig = REALTEK_I_DVBS2_BlindscanRemoveDuplicateTp(pDemodKernel, 1);
        else
            IsNotDuplicateSig = 1;
        
        if(IsNotDuplicateSig)
        {
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("[Fine] - Not Duplicate Signal\n");
            #endif
            if(pRealtekIDVBS2->m_blindscan_signal_frequency < (pRealtekIDVBS2->m_blindscan_start_freq - 5000000))
            {
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("Skip!!! Scanned TP Frequency < Start Frequency - 5M\n");
                #endif
            }
            else if(pRealtekIDVBS2->m_blindscan_signal_frequency > (pRealtekIDVBS2->m_blindscan_end_freq + 5000000))
            {
                #ifdef SPEC_AN_DEBUG
                REALTEK_I_DVBS2_INFO("Skip!!! Scanned TP Frequency > End Frequency + 5M\n");
                #endif
            }
            else
            {
                *bBlindScanLock = 1;
            }
        }
        else
        {
            #ifdef SPEC_AN_DEBUG
            REALTEK_I_DVBS2_INFO("[Fine] - !!!! Duplicate Signal !!!!\n");
            #endif
        }
    }

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_GetFoundTP
 *
 * Desc : Get blindscan search result.
 *
 * Parm : FreqMhz : frequency of found TP (unit : MHz)
 *        SymbolRateKhz : symbol rate of found TP (unit : MHz)
  *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_GetFoundTP(DEMOD* pDemodKernel, unsigned int *FreqMhz, unsigned int *SymbolRateKhz)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    *FreqMhz = pRealtekIDVBS2->m_blindscan_signal_frequency/1000000; //MHz
    *SymbolRateKhz = pRealtekIDVBS2->m_blindscan_signal_symbolrate/1000; //KHz

    REALTEK_I_DVBS2_INFO("\033[1;32;33m" "BlindScan_GetFoundTP %u %u\n" "\033[m", *FreqMhz, *SymbolRateKhz);
    
    pRealtekIDVBS2->BlindscanFoundTpList[pRealtekIDVBS2->BlindscanFoundTpIdx*2] = *FreqMhz;
    pRealtekIDVBS2->BlindscanFoundTpList[pRealtekIDVBS2->BlindscanFoundTpIdx*2+1] = *SymbolRateKhz;
    pRealtekIDVBS2->BlindscanFoundTpIdx++;

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_End
 *
 * Desc : End blindscan.
 *
 * Parm : N/A
  *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_End(DEMOD* pDemodKernel)
{
    unsigned int i = 0;
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    REALTEK_I_DVBS2_INFO("\033[1;32;33m" "============= BlindScan_End =============\n" "\033[m");
    
    if(pRealtekIDVBS2->BlindscanInitDone)
    {
        REALTEK_I_DVBS2_INFO("=========================================\n");
        pRealtekIDVBS2->BlindscanEtime = tv_osal_time();
        REALTEK_I_DVBS2_INFO("BlindScan Time(sec) %u\n", (pRealtekIDVBS2->BlindscanEtime-pRealtekIDVBS2->BlindscanStime)/1000);
        REALTEK_I_DVBS2_INFO("=========================================\n");
        
        for(i=0; i<pRealtekIDVBS2->BlindscanFoundTpIdx; i++)
        {
            REALTEK_I_DVBS2_INFO("(%02u)\tGetFoundTP\t%04u\t%u\n", i+1, pRealtekIDVBS2->BlindscanFoundTpList[i*2], pRealtekIDVBS2->BlindscanFoundTpList[i*2+1]);
        }
        REALTEK_I_DVBS2_INFO("=========================================\n");
    }
    else
    {
        REALTEK_I_DVBS2_INFO("Blindscan Not Init\n");
    }

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : REALTEK_I_DVBS2_GetDiffSrParams
 *
 * Desc : GetDiffSrParams
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetDiffSrParams(DEMOD* pDemodKernel, unsigned int ldr_mode, unsigned long symbolrate, unsigned int scan_mode, unsigned int *AcqTimeOut)
{
    int ret = TUNER_CTRL_OK;
    unsigned int u8i = 0;
    unsigned int threshold = 0;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);
    
    *AcqTimeOut = 3500;
    if(ldr_mode == REALTEK_I_DVBS_MODE)
    {
        for(u8i = 0; u8i < DVBS_ACQ_TIMEOUT_TABLE_SIZE; u8i++)
        {
            if((symbolrate/1000) >= _sDvbSLockTimeOutTable[u8i].SymbolRateKhz)
            {
                *AcqTimeOut = _sDvbSLockTimeOutTable[u8i].TimeOutMs;
                REALTEK_I_DVBS2_INFO("DVBS Acq TimeOut = %u\n", *AcqTimeOut);
                if(scan_mode == 1)
                {
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].SCAN_ERR_THRESH_FOR_DEMOD_ENTRY));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].SCAN_DEMOD_ENTRY_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].SCAN_DEMOD_LOCK_TIMEOUT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].SCAN_ERR_THRESH_FOR_DEMOD_EXIT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].SCAN_DEMOD_EXIT_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].SCAN_LOST_LOCK_TIMEOUT));
                }
                else//scan_mode == 0
                {
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].ZAP_ERR_THRESH_FOR_DEMOD_ENTRY));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].ZAP_DEMOD_ENTRY_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].ZAP_DEMOD_LOCK_TIMEOUT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].ZAP_ERR_THRESH_FOR_DEMOD_EXIT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].ZAP_DEMOD_EXIT_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbSLockTimeOutTable[u8i].ZAP_LOST_LOCK_TIMEOUT));
                }
                break;
            }
        } 
    }
    else if(ldr_mode == REALTEK_I_DVBS2_MODE)
    {
        for(u8i = 0; u8i < DVBS2_ACQ_TIMEOUT_TABLE_SIZE; u8i++)
        {
            if((symbolrate/1000) >= _sDvbS2LockTimeOutTable[u8i].SymbolRateKhz)
            {
                *AcqTimeOut = _sDvbS2LockTimeOutTable[u8i].TimeOutMs;
                REALTEK_I_DVBS2_INFO("DVBS2 Acq TimeOut = %d\n", *AcqTimeOut);
                if(scan_mode == 1)
                {
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].SCAN_ERR_THRESH_FOR_DEMOD_ENTRY));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].SCAN_DEMOD_ENTRY_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].SCAN_DEMOD_LOCK_TIMEOUT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].SCAN_ERR_THRESH_FOR_DEMOD_EXIT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].SCAN_DEMOD_EXIT_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].SCAN_LOST_LOCK_TIMEOUT));
                }
                else
                {
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].ZAP_ERR_THRESH_FOR_DEMOD_ENTRY));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].ZAP_DEMOD_ENTRY_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].ZAP_DEMOD_LOCK_TIMEOUT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].ZAP_ERR_THRESH_FOR_DEMOD_EXIT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].ZAP_DEMOD_EXIT_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2LockTimeOutTable[u8i].ZAP_LOST_LOCK_TIMEOUT));
                }
                break;
            }
        }
    }
    else if(ldr_mode == REALTEK_I_DVBS2X_MODE)
    {
        for(u8i = 0; u8i < DVBS2X_ACQ_TIMEOUT_TABLE_SIZE; u8i++)
        {
            if((symbolrate/1000) >= _sDvbS2XLockTimeOutTable[u8i].SymbolRateKhz)
            {
                *AcqTimeOut = _sDvbS2XLockTimeOutTable[u8i].TimeOutMs;
                REALTEK_I_DVBS2_INFO("DVBS2X Acq TimeOut = %d\n", *AcqTimeOut);
                /*
                if(scan_mode == 1)
                {
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].SCAN_ERR_THRESH_FOR_DEMOD_ENTRY));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].SCAN_DEMOD_ENTRY_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].SCAN_DEMOD_LOCK_TIMEOUT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].SCAN_ERR_THRESH_FOR_DEMOD_EXIT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].SCAN_DEMOD_EXIT_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].SCAN_LOST_LOCK_TIMEOUT));
                }
                else
                {
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].ZAP_ERR_THRESH_FOR_DEMOD_ENTRY));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].ZAP_DEMOD_ENTRY_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].ZAP_DEMOD_LOCK_TIMEOUT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].ZAP_ERR_THRESH_FOR_DEMOD_EXIT));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].ZAP_DEMOD_EXIT_MEASURE_LEN));
                    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, _sDvbS2XLockTimeOutTable[u8i].ZAP_LOST_LOCK_TIMEOUT));
                }
                */
                break;
            }
        }
    }

    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, &threshold));
    REALTEK_I_DVBS2_INFO("TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY = %d\n", threshold);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, &threshold));
    REALTEK_I_DVBS2_INFO("TV_REG_DEMOD_ENTRY_MEASURE_LEN = %d\n", threshold);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, &threshold));
    REALTEK_I_DVBS2_INFO("TV_REG_DEMOD_LOCK_TIMEOUT = %d\n", threshold);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, &threshold));
    REALTEK_I_DVBS2_INFO("TV_REG_ERR_THRESH_FOR_DEMOD_EXIT = %d\n", threshold);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, &threshold));
    REALTEK_I_DVBS2_INFO("TV_REG_DEMOD_EXIT_MEASURE_LEN = %d\n", threshold);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, &threshold));
    REALTEK_I_DVBS2_INFO("TV_REG_LOST_LOCK_TIMEOUT = %d\n", threshold);

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


/*----------------------------------------------------------------------
 * Func : BlindScan_AcquireSignal
 *
 * Desc : Acquire Signal in Blindscan
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_BlindScan_AcquireSignal(DEMOD* pDemodKernel, unsigned int *SymbolRateKhz, int *Fcfo, unsigned char *bTpLock)
{
    unsigned long stime = 0, etime = 0;
    unsigned char lock = 0, ext_lock_time1 = 0, ext_lock_time2 = 0;
    unsigned int DemodStatus = 0, AcqTime = 0, ActSymbolRate = 0;
    unsigned int CutLeft = 0, CutRight = 0, Ccfo = 0, Csr = 0, MaxAcqState = 0, AcqState = 0, AcqFailState = 0;
    unsigned int ModCodResult = 0, IsModCodDet = 0;
    unsigned int AcqNum = 0, ActMod = 0, ActCr = 0, ActPilot = 0, ActFcfo = 0, Threshold = 0, Snr = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pRealtekIDVBS2->m_info.dvbs.symbol_rate = *SymbolRateKhz*1000;

    if(pRealtekIDVBS2->m_info.dvbs.symbol_rate == 0 || pRealtekIDVBS2->m_info.dvbs.symbol_rate > 50000000)
    {
        REALTEK_I_DVBS2_WARNING("pRealtekIDVBS2->m_info.dvbs.symbol_rate=%lu, REALTEK_I_DVBS2_BlindScan_AcquireSignal Break\n", pRealtekIDVBS2->m_info.dvbs.symbol_rate);
        return TUNER_CTRL_NO_SIGNAL;
    }

    pRealtekIDVBS2->m_auto_tune_en = 0;
    AcqTime = 0;

    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "REALTEK_I_DVBS2_BlindScan_AcquireSignal V7.0\n" "\033[m");
    REALTEK_I_DVBS2_INFO("\033[1;32;33m" "pRealtekIDVBS2->m_info.dvbs.symbol_rate=%lu\n" "\033[m", pRealtekIDVBS2->m_info.dvbs.symbol_rate);

    //----------------------------------------------------------------------------------------------------------
    //DVBS2
    //----------------------------------------------------------------------------------------------------------
    //DVBS2 Only Support Baudrate > 0.9M
    if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
        goto auto_scan_mode_done;
    
    if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
    {
        REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
    }
    REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
    //Set Bandwidth and Frequency to Acknowledge Demod to Lock
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

    stime = tv_osal_time();
    lock = NO;
    MaxAcqState = 0;
    IsModCodDet = 0;
    ext_lock_time1 = 0;
    ext_lock_time2 = 0;

    while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
        tv_osal_msleep(5);

        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
        AcqState &= DVBS2_BITFLD_ACQUISITION_STATE;
        if(MaxAcqState < AcqState)
            MaxAcqState = AcqState;
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum));
        /*
        -1: Invalid S2 frame length type.
        0: QPSK frame length type.
        1: QPSK with pilots frame length type.
        2: 8-PSK frame length type.
        3: 8-PSK with pilots frame length type.
        4: Initial value.
        */
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_DETECTED_FRAME_LENGTH, NULL_SEC_ADDR, &ModCodResult));
        REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
        if(ModCodResult >= 0 && ModCodResult <= 3)
            IsModCodDet = 1;
        
        if(MaxAcqState >= 14 && AcqNum >= 6 && ext_lock_time1 == 0)
        {
            REALTEK_I_DVBS2_INFO("DVBS2 EXT Lock Time 1\n");
            ext_lock_time1 = 1;
            pRealtekIDVBS2->m_AcqTimeOut += 4500;
        }
        
        if(MaxAcqState >= 14 && AcqNum >= 10 && ext_lock_time2 == 0 && tv_osal_time() - stime >= 7000)
        {
            REALTEK_I_DVBS2_INFO("DVBS2 EXT Lock Time 2\n");
            ext_lock_time2 = 1;
            pRealtekIDVBS2->m_AcqTimeOut += 5500;
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, 16));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, 9));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_DEMOD_ENTRY_MEASURE_LEN = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_DEMOD_LOCK_TIMEOUT = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_ERR_THRESH_FOR_DEMOD_EXIT = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_DEMOD_EXIT_MEASURE_LEN = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_LOST_LOCK_TIMEOUT = %d\n", Threshold);
        }
        
        if(DemodStatus == 5)
        {
            etime = tv_osal_time();
            lock = YES;
            pRealtekIDVBS2->m_PreUbc = 0;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
            REALTEK_I_DVBS2_INFO("DvbS2GetActiveBaudRate=%d\n", ActSymbolRate);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
            AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo));//GetCarrierFreqOffset
            ActFcfo &= DVBS2_BITFLD_CARRIER_FREQ_OFFSET;
            REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2 Signal Lock!!!\n" "\033[m");
            break;
        }
        else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
        {
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
            REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            goto auto_scan_mode_done;//break;
        }
        else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
        {
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
            break;
        }
        etime = tv_osal_time();
    }
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_FAILURE_CODE, NULL_SEC_ADDR, &AcqFailState);
    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u, AcqFailState = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum, AcqFailState);
    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
    REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
    REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
    pDemod->GetVirtualRegister(pDemod, DVBS2_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr);
    REALTEK_I_DVBS2_INFO("Snr=%u\n", (Snr*100)/655);
    
    if(lock == YES)
        goto auto_scan_mode_done;

    //----------------------------------------------------------------------------------------------------------
    //DVBS
    //----------------------------------------------------------------------------------------------------------
    if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS_MODE)
    {
        REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
    }
    REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
    //Set Bandwidth and Frequency to Acknowledge Demod to Lock
    ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

    stime = tv_osal_time();
    lock = NO;
    MaxAcqState = 0;
    ext_lock_time1 = 0;
    ext_lock_time2 = 0;

    while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
        tv_osal_msleep(5);

        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
        if(MaxAcqState < AcqState)
            MaxAcqState = AcqState;
        
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum));
        
        if(MaxAcqState >= 14 && AcqNum >= 6 && ext_lock_time1 == 0)
        {
            REALTEK_I_DVBS2_INFO("DVBS EXT Lock Time 1\n");
            ext_lock_time1 = 1;
            pRealtekIDVBS2->m_AcqTimeOut += 4500;
        }
        
        if(MaxAcqState >= 14 && AcqNum >= 10 && ext_lock_time2 == 0 && tv_osal_time() - stime >= 7000)
        {
            REALTEK_I_DVBS2_INFO("DVBS EXT Lock Time 2\n");
            ext_lock_time2 = 1;
            pRealtekIDVBS2->m_AcqTimeOut += 5500;
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, 24));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, 22));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_ERR_THRESH_FOR_DEMOD_ENTRY = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_ENTRY_MEASURE_LEN, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_DEMOD_ENTRY_MEASURE_LEN = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_LOCK_TIMEOUT, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_DEMOD_LOCK_TIMEOUT = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_ERR_THRESH_FOR_DEMOD_EXIT, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_ERR_THRESH_FOR_DEMOD_EXIT = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_DEMOD_EXIT_MEASURE_LEN, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_DEMOD_EXIT_MEASURE_LEN = %d\n", Threshold);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_LOST_LOCK_TIMEOUT, NULL_SEC_ADDR, &Threshold));
            REALTEK_I_DVBS2_INFO("NEW TV_REG_LOST_LOCK_TIMEOUT = %d\n", Threshold);
        }
        
        if(DemodStatus == 5)
        {
            etime = tv_osal_time();
            lock = YES;
            pRealtekIDVBS2->m_PreUbc = 0;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
            REALTEK_I_DVBS2_INFO("DvbSGetActiveBaudRate=%d\n", ActSymbolRate);
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//DvbSGetAcquisitionTime
            AcqTime &= DVBS_BITFLD_ACQUISITION_TIME;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo));//GetCarrierFreqOffset
            REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS Signal Lock!!!\n" "\033[m");
            break;
        }
        else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
        {
            etime = tv_osal_time();
            REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
            REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            goto auto_scan_mode_done;
        }
        etime = tv_osal_time();
    }
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_FAILURE_CODE, NULL_SEC_ADDR, &AcqFailState);
    REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u, AcqFailState = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum, AcqFailState);
    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
    REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d\n", CutLeft, CutRight, Ccfo, Csr);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
    REALTEK_I_DVBS2_INFO("ActMod=0, ActCr=%d\n", ActCr);
    pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr);
    REALTEK_I_DVBS2_INFO("Snr=%u\n", (Snr*100)/655);
    
    if(lock == YES)
        goto auto_scan_mode_done;
    
auto_scan_mode_done:
    *bTpLock = lock;
    *SymbolRateKhz = ActSymbolRate/1000;
    *Fcfo = ActFcfo;
    //pRealtekIDVBS2->m_auto_tune_en = 1;
    pRealtekIDVBS2->m_auto_tune_reset = 1;
    
    if(lock == YES)
    {
        pRealtekIDVBS2->m_blindscan_tp_lock_frequency[pRealtekIDVBS2->m_blindscan_tp_lock_idx] = pRealtekIDVBS2->BlindscanFoundTpList[(pRealtekIDVBS2->BlindscanFoundTpIdx-1)*2];
        pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate[pRealtekIDVBS2->m_blindscan_tp_lock_idx] = pRealtekIDVBS2->BlindscanFoundTpList[(pRealtekIDVBS2->BlindscanFoundTpIdx-1)*2+1];
        REALTEK_I_DVBS2_INFO("\033[1;32;33m" "m_blindscan_tp_lock %u %u\n" "\033[m", pRealtekIDVBS2->m_blindscan_tp_lock_frequency[pRealtekIDVBS2->m_blindscan_tp_lock_idx], pRealtekIDVBS2->m_blindscan_tp_lock_symbolrate[pRealtekIDVBS2->m_blindscan_tp_lock_idx]);
        pRealtekIDVBS2->m_blindscan_tp_lock_idx++;
    }

    return ret;
}


/*----------------------------------------------------------------------
 * Func : AcquireSignal
 *
 * Desc : Reset Demodulator and Acquire Signal.
 *        This function should be called when channel changed.
 *
 * Parm : WaitSignalLock : wait until signal lock
 *          0 : don't wait,
 *          others: wait for signal lock
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_AcquireSignal(DEMOD* pDemodKernel, unsigned char WaitSignalLock)
{
    return REALTEK_I_DVBS2_AcquireSignalEx(pDemodKernel, WaitSignalLock, 0, NULL);
}


/*----------------------------------------------------------------------
 * Func : AcquireSignal
 *
 * Desc : Reset Demodulator and Acquire Signal.
 *        This function should be called when channel changed.
 *
 * Parm : WaitSignalLock : wait until signal lock
 *          0 : don't wait,
 *          others: wait for signal lock
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_AcquireSignalEx(DEMOD* pDemodKernel, unsigned char WaitSignalLock, unsigned char DiseqcCmdCnt, const unsigned char *pDiseqcCmd)
{
    unsigned long stime = 0, etime = 0;
    unsigned char lock = 0;
    unsigned int DemodStatus = 0, AcqTime = 0, ActSymbolRate = 0;
    unsigned int CutLeft = 0, CutRight = 0, Ccfo = 0, Csr = 0, MaxAcqState = 0, AcqState = 0;
    unsigned int ModCodResult = 0, IsModCodDet = 0;
    unsigned int AcqNum = 0, ActMod = 0, ActCr = 0, ActPilot = 0, ActFcfo = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    if(pRealtekIDVBS2->m_info.dvbs.symbol_rate == 0 || pRealtekIDVBS2->m_info.dvbs.symbol_rate > 50000000)
    {
        REALTEK_I_DVBS2_WARNING("Null Symbol Rate, AcquireSignalEx Break\n");
        return TUNER_CTRL_NO_SIGNAL;
    }

    pRealtekIDVBS2->m_auto_tune_en = 0;

#ifdef SUPPORT_WINTOOL
    pRealtekIDVBS2->m_debug_tool_en = 0;
#endif

    AcqTime = 0;

    if(pRealtekIDVBS2->m_info.dvbs.IsBlindsearch != 1)
    {
        
        
        //----------------------------------------------------------------------------------------------------------
        //NORMAL MODE
        //----------------------------------------------------------------------------------------------------------
        if(pDemodKernel->m_tv_sys == TV_SYS_DVBS)
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Webos TV_SYS_DVBS\n" "\033[m");
#ifdef EN_DVBS
            //----------------------------------------------------------------------------------------------------------
            //DVBS
            //----------------------------------------------------------------------------------------------------------
            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;

                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod,DVBS_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbSGetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//DvbSGetAcquisitionTime
                    AcqTime &= DVBS_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d\n", CutLeft, CutRight, Ccfo, Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=0, ActCr=%d\n", ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
#endif

#ifdef EN_DVBS2
            //----------------------------------------------------------------------------------------------------------
            //DVBS2
            //----------------------------------------------------------------------------------------------------------
            //DVBS2 Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                goto auto_scan_mode_done;
            
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;
            IsModCodDet = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
                AcqState &= DVBS2_BITFLD_ACQUISITION_STATE;
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;
                
                /*
                -1: Invalid S2 frame length type.
                0: QPSK frame length type.
                1: QPSK with pilots frame length type.
                2: 8-PSK frame length type.
                3: 8-PSK with pilots frame length type.
                4: Initial value.
                */
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_DETECTED_FRAME_LENGTH, NULL_SEC_ADDR, &ModCodResult));
                REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
                if(ModCodResult >= 0 && ModCodResult <= 3)
                    IsModCodDet = 1;
                
                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbS2GetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
                    AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2 Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    #ifdef EN_DVBS2X
                    break;
                    #else
                    goto auto_scan_mode_done;
                    #endif
                }
                else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
                    break;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
#endif

#ifdef EN_DVBS2X
            //----------------------------------------------------------------------------------------------------------
            //DVBS2X
            //----------------------------------------------------------------------------------------------------------
            //DVBS2X Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                goto auto_scan_mode_done;

            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2X_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2X_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2X_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;
            IsModCodDet = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
                AcqState &= DVBS2X_BITFLD_ACQUISITION_STATE;
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;
                
                /*
                0: Unknown signal.
                1: DVB-S2(X) signal.
                2: Possibly DVB-S signal.
                */
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_SIGNAL_INDICATOR, NULL_SEC_ADDR, &ModCodResult));
                REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
                if(ModCodResult == 1)
                    IsModCodDet = 1;
                
                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbS2XGetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
                    AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2X Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;//break;
                }
                else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
                    break;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS2X signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
#endif
        }
        else
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Webos TV_SYS_DVBS2\n" "\033[m");
#ifdef EN_DVBS2
            //----------------------------------------------------------------------------------------------------------
            //DVBS2
            //----------------------------------------------------------------------------------------------------------

            //DVBS2 Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                goto direct_acq_dvbs;
            
            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;
            IsModCodDet = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
                AcqState &= DVBS2_BITFLD_ACQUISITION_STATE;
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;
                
                /*
                -1: Invalid S2 frame length type.
                0: QPSK frame length type.
                1: QPSK with pilots frame length type.
                2: 8-PSK frame length type.
                3: 8-PSK with pilots frame length type.
                4: Initial value.
                */
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_DETECTED_FRAME_LENGTH, NULL_SEC_ADDR, &ModCodResult));
                REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
                if(ModCodResult >= 0 && ModCodResult <= 3)
                    IsModCodDet = 1;
                
                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbS2GetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
                    AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2 Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    #ifdef EN_DVBS2X
                    break;
                    #else
                    goto auto_scan_mode_done;
                    #endif
                }
                else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
                    break;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
#endif

#ifdef EN_DVBS2X
            //----------------------------------------------------------------------------------------------------------
            //DVBS2X
            //----------------------------------------------------------------------------------------------------------
            //DVBS2X Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                goto direct_acq_dvbs;

            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2X_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2X_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2X_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;
            IsModCodDet = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
                AcqState &= DVBS2X_BITFLD_ACQUISITION_STATE;
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;
                
                /*
                0: Unknown signal.
                1: DVB-S2(X) signal.
                2: Possibly DVB-S signal.
                */
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_SIGNAL_INDICATOR, NULL_SEC_ADDR, &ModCodResult));
                REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
                if(ModCodResult == 1)
                    IsModCodDet = 1;
                
                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbS2XGetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
                    AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2X Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;//break;
                }
                else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
                    break;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS2X signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
#endif

direct_acq_dvbs:
#ifdef EN_DVBS
            //----------------------------------------------------------------------------------------------------------
            //DVBS
            //----------------------------------------------------------------------------------------------------------
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;

                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbSGetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//DvbSGetAcquisitionTime
                    AcqTime &= DVBS_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d\n", CutLeft, CutRight, Ccfo, Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=0, ActCr=%d\n", ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
#endif
        }
    
    
    }
    else//if(pRealtekIDVBS2->m_info.dvbs.IsBlindsearch == 1)
    {
        
        //----------------------------------------------------------------------------------------------------------
        //BLINDSCAN MODE
        //----------------------------------------------------------------------------------------------------------   
        if(pDemodKernel->m_tv_sys == TV_SYS_DVBS)
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Blindscan Webos TV_SYS_DVBS\n" "\033[m");
            
            //----------------------------------------------------------------------------------------------------------
            //DVBS
            //----------------------------------------------------------------------------------------------------------
            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;

                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod,DVBS_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbSGetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//DvbSGetAcquisitionTime
                    AcqTime &= DVBS_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d\n", CutLeft, CutRight, Ccfo, Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=0, ActCr=%d\n", ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
            
            //----------------------------------------------------------------------------------------------------------
            //DVBS2
            //----------------------------------------------------------------------------------------------------------
            //DVBS2 Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                goto auto_scan_mode_done;
            
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;
            IsModCodDet = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
                AcqState &= DVBS2_BITFLD_ACQUISITION_STATE;
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;
                
                /*
                -1: Invalid S2 frame length type.
                0: QPSK frame length type.
                1: QPSK with pilots frame length type.
                2: 8-PSK frame length type.
                3: 8-PSK with pilots frame length type.
                4: Initial value.
                */
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_DETECTED_FRAME_LENGTH, NULL_SEC_ADDR, &ModCodResult));
                REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
                if(ModCodResult >= 0 && ModCodResult <= 3)
                    IsModCodDet = 1;

                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbS2GetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
                    AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2 Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;
                }
                else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
                    break;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
        }
        else
        {
            REALTEK_I_DVBS2_INFO("\033[1;32;33m" "Blindscan Webos TV_SYS_DVBS2\n" "\033[m");
            
            //----------------------------------------------------------------------------------------------------------
            //DVBS2
            //----------------------------------------------------------------------------------------------------------
            //DVBS2 Only Support Baudrate > 0.9M
            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate < 900000)
                goto direct_bs_dvbs;
            
            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;
            IsModCodDet = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));//GetAcquisitionState
                AcqState &= DVBS2_BITFLD_ACQUISITION_STATE;
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;
                
                /*
                -1: Invalid S2 frame length type.
                0: QPSK frame length type.
                1: QPSK with pilots frame length type.
                2: 8-PSK frame length type.
                3: 8-PSK with pilots frame length type.
                4: Initial value.
                */
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_DETECTED_FRAME_LENGTH, NULL_SEC_ADDR, &ModCodResult));
                REALTEK_I_DVBS2_DBG("ModCodResult (%d)\n", ModCodResult);
                if(ModCodResult >= 0 && ModCodResult <= 3)
                    IsModCodDet = 1;

                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbS2GetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//GetAcquisitionTime
                    AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS2 Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;
                }
                else if(tv_osal_time() - stime >= 600 && IsModCodDet == 0)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("NO MODCOD DET\n");
                    break;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS2 signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &ActPilot);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d, ActPilot=%d\n", CutLeft, CutRight, Ccfo, Csr, ActPilot);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
            pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
            
direct_bs_dvbs:
            //----------------------------------------------------------------------------------------------------------
            //DVBS
            //----------------------------------------------------------------------------------------------------------
            if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS_MODE)
            {
                REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
            }
            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
            //Set Bandwidth and Frequency to Acknowledge Demod to Lock
            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

            stime = tv_osal_time();
            lock = NO;
            MaxAcqState = 0;

            while ((tv_osal_time() - stime) <= pRealtekIDVBS2->m_AcqTimeOut) {
                tv_osal_msleep(5);

                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                
                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_STATE, NULL_SEC_ADDR, &AcqState));
                if(MaxAcqState < AcqState)
                    MaxAcqState = AcqState;

                if(DemodStatus == 5)
                {
                    etime = tv_osal_time();
                    lock = YES;
                    pRealtekIDVBS2->m_PreUbc = 0;
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_BAUD_RATE, NULL_SEC_ADDR, &ActSymbolRate));
                    REALTEK_I_DVBS2_INFO("DvbSGetActiveBaudRate=%d\n", ActSymbolRate);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));//DvbSGetAcquisitionTime
                    AcqTime &= DVBS_BITFLD_ACQUISITION_TIME;
                    REALTEK_I_DVBS2_INFO("\033[1;32;31m" "DVBS Signal Lock!!!\n" "\033[m");
                    break;
                }
                else if(tv_osal_time() - stime >= 400 && MaxAcqState <= 6)
                {
                    etime = tv_osal_time();
                    REALTEK_I_DVBS2_INFO("CARRIER UNLOCK DET\n");
                    REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u\n", (unsigned int)lock, etime-stime, AcqTime);
                    REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
                    goto auto_scan_mode_done;
                }
                etime = tv_osal_time();
            }
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_NUM_ACQUISITIONS, NULL_SEC_ADDR, &AcqNum);
            REALTEK_I_DVBS2_INFO("DVBS signal lock = %u, driver time = %lu, HW time = %u, AcqNum = %u\n", (unsigned int)lock, etime-stime, AcqTime, AcqNum);
            REALTEK_I_DVBS2_INFO("MaxAcqState (%d)\n", MaxAcqState);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_LEFT, NULL_SEC_ADDR, &CutLeft);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_SPECTRUM_CUTOFF_RIGHT, NULL_SEC_ADDR, &CutRight);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_CFO, NULL_SEC_ADDR, &Ccfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_COARSE_BAUD_RATE, NULL_SEC_ADDR, &Csr);
            REALTEK_I_DVBS2_INFO("CutLeft=%d, CutRight=%d, Ccfo=%d, Csr=%d\n", CutLeft, CutRight, Ccfo, Csr);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_CARRIER_FREQ_OFFSET, NULL_SEC_ADDR, &ActFcfo);
            REALTEK_I_DVBS2_INFO("ActFcfo=%d\n", ActFcfo);
            pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
            REALTEK_I_DVBS2_INFO("ActMod=0, ActCr=%d\n", ActCr);
            
            if(lock == YES)
                goto auto_scan_mode_done;
        }


    }
    
auto_scan_mode_done:
    pRealtekIDVBS2->m_auto_tune_en = 1;
    pRealtekIDVBS2->m_auto_tune_reset = 1;

    return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;
}


/*----------------------------------------------------------------------
 * Func : ScanSignal
 *
 * Desc : Ask demodulator to Search signal within specified range
 *        This function should be called every time the channel changed.
 *
 * Parm : pOffset : Offset Output
 *        range   : Scan Range
 *          SCAN_RANGE_NONE : center only
 *          SCAN_RANGE_1_6  : (-)1/6 MHz
 *          SCAN_RANGE_2_6  : (-)2/6 MHz
 *          SCAN_RANGE_3_6  : (-)3/6 MHz
 *
 * Retn : TUNER_CTRL_OK        : signal found and locked
 *        TUNER_CTRL_FAIL      : error occured during scan channel
 *        TUNER_CTRL_NO_SIGNAL : no signal found in specified range
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_ScanSignal(DEMOD* pDemodKernel, long* pOffset, SCAN_RANGE range)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : ForwardI2C
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_ForwardI2C(DEMOD* pDemodKernel, unsigned char on_off)
{
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);

    pDemodKernel->Unlock(pDemodKernel);

    return ret;
}


/*----------------------------------------------------------------------
 * Func : AutoTune
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_AutoTune(DEMOD* pDemodKernel)
{
#ifndef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE
    unsigned int DemodStatus = 0, u8i = 0;
    static unsigned long stime = 0;
    int ret = TUNER_CTRL_OK;
    static unsigned long UnlockStime = 0;
    static unsigned char UnlockHappened = 0;
    unsigned int ISI_ID = 0;
#ifdef EN_DVBS2X
    unsigned int ActMod = 0, ActCr = 0;
#endif
    
#ifdef SUPPORT_WINTOOL
    unsigned int dbg_pri_addr = 0, dbg_sec_addr = 0, dbg_val = 0, ConstData = 0;
    unsigned int blindscan_debug_freq = 0, TunerCenterFreqMhz = 0, TunerCutOffFreqKhz = 0, bBlindScanEnd = 0;
#endif

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
#ifdef ENABLE_LDR_LOADER
    if((rtd_inl(0xb8000200) & 0x00000060) == 0x00000060)
    {
        while(1)
        {
            REALTEK_I_DVBS2_INFO("EJTAG ENABLED\n");
            tv_osal_msleep(100);
        }
    }
#endif

    //if(rtd_inl(0xc2700100) == 0x00000001)
    //{
    //    ISI_ID = rtd_inl(0xc2700104);
    //    pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_SELECT_ISI_CMD, NULL_SEC_ADDR, ISI_ID);
    //    rtd_outl(0xc2700100, 0x00000002);
    //    pRealtekIDVBS2->m_auto_tune_en = 0;
    //}
    //else
    //{
//#ifdef SUPPORT_WINTOOL
        if(pRealtekIDVBS2->m_auto_tune_en)
        {
            //if(rtd_inl(DEBUG_MODE_EN_ADDRESS) == 0x00022243)
            //{
            //    REALTEK_I_DVBS2_INFO("WINTOOL ENABLED\n");
            //    if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFF)//Dump All Virtual Register
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_UPDATE_COUNTERS));//DemodCtrlUpdateCounters
            //            for(dbg_pri_addr = 0; dbg_pri_addr <= 4; dbg_pri_addr++)
            //            {
            //                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, dbg_pri_addr, NULL_SEC_ADDR, &dbg_val));
            //                rtd_outl(COMMON_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
            //            }
            //
            //            for(dbg_pri_addr = 0; dbg_pri_addr <= (DVBS2_REG_TOTALREG-TV_REG_NUM_COMMON_REG); dbg_pri_addr++)
            //            {
            //                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, (0x8000+dbg_pri_addr), NULL_SEC_ADDR, &dbg_val));
            //                rtd_outl(VR_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
            //            }
            //
            //            //EQ/HD Constellation
            //            for(u8i = 0; u8i < 6; u8i++)
            //            {
            //                pDemod->GetHwRegValue(IMG_DEMOD_DVBS_EQ_CONST_ADDRESS+u8i*4, &ConstData);
            //                rtd_outl(CONSTELL_EQ_ADDRESS+u8i*4, ConstData);
            //
            //                pDemod->GetHwRegValue(IMG_DEMOD_DVBS_HD_CONST_ADDRESS+u8i*4, &ConstData);
            //                rtd_outl(CONSTELL_HD_ADDRESS+u8i*4, ConstData);
            //            }
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //    else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFE)//GetVirtualRegister
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
            //            dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
            //            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, &dbg_val));
            //            rtd_outl(VR_VALUE_ADDRESS, dbg_val);//get vr value
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //    else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFD)//SetVirtualRegister
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
            //            dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
            //            dbg_val = rtd_inl(VR_VALUE_ADDRESS);//get vr value
            //            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, dbg_val));
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //    else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFC)
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            blindscan_debug_freq = rtd_inl(BLINDSCAN_DBG_FREQ) - 30;//blindscan will scan init freq+30MHz
            //            REALTEK_I_DVBS2_BlindScan_Init(pDemodKernel, blindscan_debug_freq, 2150);
            //
            //            REALTEK_I_DVBS2_BlindScan_GetTunerFreq(pDemodKernel, &TunerCenterFreqMhz, &TunerCutOffFreqKhz);
            //
            //            REALTEK_I_DVBS2_BlindScan_NextFreq(pDemodKernel, &bBlindScanEnd);
            //            
            //            pRealtekIDVBS2->m_auto_tune_en = 1;
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //}
            //else
            //{
                pRealtekIDVBS2->m_debug_tool_en = 0;
                //if(pRealtekIDVBS2->m_auto_tune_en)
                //{
                    pRealtekIDVBS2->m_AcqTimeOut = 3500;
                    for(u8i = 0; u8i < DVBS2_ACQ_TIMEOUT_TABLE_SIZE; u8i++)
                    {
                        if((pRealtekIDVBS2->m_info.dvbs.symbol_rate/1000) >= _sDvbSLockTimeOutTable[u8i].SymbolRateKhz)
                        {
                            pRealtekIDVBS2->m_AcqTimeOut = _sDvbSLockTimeOutTable[u8i].TimeOutMs;
                            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate == 0)
                            {
                                pRealtekIDVBS2->m_AcqTimeOut = 0;
                            }
                            break;
                        }
                    }

                    pDemodKernel->Lock(pDemodKernel);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                    pDemodKernel->Unlock(pDemodKernel);

                    if(DemodStatus != 5 && (UnlockHappened == 0  || pRealtekIDVBS2->m_auto_tune_reset == 1))
                    {
                        UnlockStime = tv_osal_time();
                        pRealtekIDVBS2->m_auto_tune_reset = 0;
                        UnlockHappened = 1;
                    }
                    else if(DemodStatus == 5)
                    {
                        UnlockStime = tv_osal_time();
                        UnlockHappened = 0;
                        
                        #ifdef EN_DVBS2X
                        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
                        {
                            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
                            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
                            if( 
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_1_2)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_3_5)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_2_3)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_3_4)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_4_5)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_5_6)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_8_9)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_9_10) ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_3_5)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_2_3)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_3_4)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_5_6)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_8_9)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_9_10)
                            )
                            {
                                REALTEK_I_DVBS2_INFO("Force TV_SYS_DVBS2\n");
                                REALTEK_I_DVBS2_INFO("ActMod=%d, ActCr=%d\n", ActMod, ActCr);
                                if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
                                {
                                    REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
                                }
                                
                                REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                                REALTEK_I_DVBS2_INFO("symbol_rate=%lu\n", pRealtekIDVBS2->m_info.dvbs.symbol_rate);
                                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
                                //Set Bandwidth and Frequency to Acknowledge Demod to Lock
                                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
                                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
                                
                                stime = tv_osal_time();
                            }
                        }
                        #endif
                    }

                    if((DemodStatus != 5) && (tv_osal_time() - UnlockStime >= 4000) && (tv_osal_time() - stime >= (pRealtekIDVBS2->m_AcqTimeOut+2000)))
                    {
                        REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_AutoTune\n");

                        #ifdef EN_DVBS2X
                        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2X_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2X_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        #else
                        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        #endif
                        REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.freq_khz=%lu\n", pRealtekIDVBS2->m_info.dvbs.freq_khz);
                        REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.symbol_rate=%lu\n", pRealtekIDVBS2->m_info.dvbs.symbol_rate);
                        
                        pDemodKernel->Lock(pDemodKernel);

                        ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect

                        //Set Bandwidth and Frequency to Acknowledge Demod to Lock
                        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
                        ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

                        stime = tv_osal_time();

                        pDemodKernel->Unlock(pDemodKernel);
                    }
                //pRealtekIDVBS2->m_auto_tune_en = 1;
                //}
            //}
        }
//#endif
    //}
#endif
    
    return TUNER_CTRL_OK;
}

/*----------------------------------------------------------------------
 * Func : KernelAutoTune
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_KernelAutoTune(DEMOD* pDemodKernel)
{
#ifdef CONFIG_RTK_KDRV_DEMOD_SCAN_THREAD_ENABLE
    unsigned int DemodStatus = 0, u8i = 0;
    static unsigned long stime = 0;
    int ret = TUNER_CTRL_OK;
    static unsigned long UnlockStime = 0;
    static unsigned char UnlockHappened = 0;
    unsigned int ISI_ID = 0;
#ifdef EN_DVBS2X
    unsigned int ActMod = 0, ActCr = 0;
#endif
    
#ifdef SUPPORT_WINTOOL
    unsigned int dbg_pri_addr = 0, dbg_sec_addr = 0, dbg_val = 0, ConstData = 0;
    unsigned int blindscan_debug_freq = 0, TunerCenterFreqMhz = 0, TunerCutOffFreqKhz = 0, bBlindScanEnd = 0;
#endif

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
#ifdef ENABLE_LDR_LOADER
    if((rtd_inl(0xb8000200) & 0x00000060) == 0x00000060)
    {
        while(1)
        {
            REALTEK_I_DVBS2_INFO("EJTAG ENABLED\n");
            tv_osal_msleep(100);
        }
    }
#endif

    //if(rtd_inl(0xc2700100) == 0x00000001)
    //{
    //    ISI_ID = rtd_inl(0xc2700104);
    //    pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_SELECT_ISI_CMD, NULL_SEC_ADDR, ISI_ID);
    //    rtd_outl(0xc2700100, 0x00000002);
    //    pRealtekIDVBS2->m_auto_tune_en = 0;
    //}
    //else
    //{
//#ifdef SUPPORT_WINTOOL
        if(pRealtekIDVBS2->m_auto_tune_en)
        {
            //if(rtd_inl(DEBUG_MODE_EN_ADDRESS) == 0x00022243)
            //{
            //    REALTEK_I_DVBS2_INFO("WINTOOL ENABLED\n");
            //    if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFF)//Dump All Virtual Register
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_UPDATE_COUNTERS));//DemodCtrlUpdateCounters
            //            for(dbg_pri_addr = 0; dbg_pri_addr <= 4; dbg_pri_addr++)
            //            {
            //                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, dbg_pri_addr, NULL_SEC_ADDR, &dbg_val));
            //                rtd_outl(COMMON_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
            //            }
            //
            //            for(dbg_pri_addr = 0; dbg_pri_addr <= (DVBS2_REG_TOTALREG-TV_REG_NUM_COMMON_REG); dbg_pri_addr++)
            //            {
            //                ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, (0x8000+dbg_pri_addr), NULL_SEC_ADDR, &dbg_val));
            //                rtd_outl(VR_BASE_ADDRESS+dbg_pri_addr*4, dbg_val);
            //            }
            //
            //            //EQ/HD Constellation
            //            for(u8i = 0; u8i < 6; u8i++)
            //            {
            //                pDemod->GetHwRegValue(IMG_DEMOD_DVBS_EQ_CONST_ADDRESS+u8i*4, &ConstData);
            //                rtd_outl(CONSTELL_EQ_ADDRESS+u8i*4, ConstData);
            //
            //                pDemod->GetHwRegValue(IMG_DEMOD_DVBS_HD_CONST_ADDRESS+u8i*4, &ConstData);
            //                rtd_outl(CONSTELL_HD_ADDRESS+u8i*4, ConstData);
            //            }
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //    else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFE)//GetVirtualRegister
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
            //            dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
            //            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, &dbg_val));
            //            rtd_outl(VR_VALUE_ADDRESS, dbg_val);//get vr value
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //    else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFD)//SetVirtualRegister
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            dbg_pri_addr = rtd_inl(PRI_VR_INDEX_ADDRESS);//get vr index
            //            dbg_sec_addr = rtd_inl(SEC_VR_INDEX_ADDRESS);//get vr index
            //            dbg_val = rtd_inl(VR_VALUE_ADDRESS);//get vr value
            //            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, dbg_pri_addr, dbg_sec_addr, dbg_val));
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //    else if(rtd_inl(DEBUG_MODE_SEL_ADDRESS) == 0xFFFFFFFC)
            //    {
            //        pRealtekIDVBS2->m_debug_tool_en = 1;
            //        if(rtd_inl(HANDSHAKE_ADDRESS) == 0x00000001)//tool done
            //        {
            //            blindscan_debug_freq = rtd_inl(BLINDSCAN_DBG_FREQ) - 30;//blindscan will scan init freq+30MHz
            //            REALTEK_I_DVBS2_BlindScan_Init(pDemodKernel, blindscan_debug_freq, 2150);
            //
            //            REALTEK_I_DVBS2_BlindScan_GetTunerFreq(pDemodKernel, &TunerCenterFreqMhz, &TunerCutOffFreqKhz);
            //
            //            REALTEK_I_DVBS2_BlindScan_NextFreq(pDemodKernel, &bBlindScanEnd);
            //            
            //            pRealtekIDVBS2->m_auto_tune_en = 1;
            //
            //            rtd_outl(HANDSHAKE_ADDRESS, 0x00000002);//driver done
            //        }
            //    }
            //}
            //else
            //{
                pRealtekIDVBS2->m_debug_tool_en = 0;
                //if(pRealtekIDVBS2->m_auto_tune_en)
                //{
                    pRealtekIDVBS2->m_AcqTimeOut = 3500;
                    for(u8i = 0; u8i < DVBS2_ACQ_TIMEOUT_TABLE_SIZE; u8i++)
                    {
                        if((pRealtekIDVBS2->m_info.dvbs.symbol_rate/1000) >= _sDvbSLockTimeOutTable[u8i].SymbolRateKhz)
                        {
                            pRealtekIDVBS2->m_AcqTimeOut = _sDvbSLockTimeOutTable[u8i].TimeOutMs;
                            if(pRealtekIDVBS2->m_info.dvbs.symbol_rate == 0)
                            {
                                pRealtekIDVBS2->m_AcqTimeOut = 0;
                            }
                            break;
                        }
                    }

                    pDemodKernel->Lock(pDemodKernel);
                    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
                    pDemodKernel->Unlock(pDemodKernel);

                    if(DemodStatus != 5 && (UnlockHappened == 0  || pRealtekIDVBS2->m_auto_tune_reset == 1))
                    {
                        UnlockStime = tv_osal_time();
                        pRealtekIDVBS2->m_auto_tune_reset = 0;
                        UnlockHappened = 1;
                    }
                    else if(DemodStatus == 5)
                    {
                        UnlockStime = tv_osal_time();
                        UnlockHappened = 0;
                        
                        #ifdef EN_DVBS2X
                        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
                        {
                            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &ActMod);
                            pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &ActCr);
                            if( 
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_1_2)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_3_5)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_2_3)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_3_4)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_4_5)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_5_6)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_8_9)  ||
                                (ActMod == DVBS2_MOD_QPSK && ActCr == RTK_DEMOD_DVBS2_CR_9_10) ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_3_5)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_2_3)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_3_4)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_5_6)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_8_9)  ||
                                (ActMod == DVBS2_MOD_8PSK && ActCr == RTK_DEMOD_DVBS2_CR_9_10)
                            )
                            {
                                REALTEK_I_DVBS2_INFO("Kernel AT Force TV_SYS_DVBS2\n");
                                REALTEK_I_DVBS2_INFO("Kernel AT ActMod=%d, ActCr=%d\n", ActMod, ActCr);
                                if(pRealtekIDVBS2->m_dvbs2_ldr_mode != REALTEK_I_DVBS2_MODE)
                                {
                                    REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
                                }
                                
                                REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR,pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                                REALTEK_I_DVBS2_INFO("symbol_rate=%lu\n", pRealtekIDVBS2->m_info.dvbs.symbol_rate);
                                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect
                                //Set Bandwidth and Frequency to Acknowledge Demod to Lock
                                ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
                                ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together
                                
                                stime = tv_osal_time();
                            }
                        }
                        #endif
                    }

                    if((DemodStatus != 5) && (tv_osal_time() - UnlockStime >= 4000) && (tv_osal_time() - stime >= (pRealtekIDVBS2->m_AcqTimeOut+2000)))
                    {
                        REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_KernelAutoTune\n");

                        #ifdef EN_DVBS2X
                        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2X_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2X_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        #else
                        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
                        {
                            REALTEK_I_DVBS2_ChangeStandard(pDemodKernel, REALTEK_I_DVBS2_MODE);
                            REALTEK_I_DVBS2_GetDiffSrParams(pDemodKernel, REALTEK_I_DVBS2_MODE, pRealtekIDVBS2->m_info.dvbs.symbol_rate, pRealtekIDVBS2->m_info.dvbs.scan_mode, &pRealtekIDVBS2->m_AcqTimeOut);
                            ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod,TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_STOP));//DemodCtrlStop
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BLIND_SCAN_IN_USE, NULL_SEC_ADDR, 0));
                            ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_BAUD_RATE, NULL_SEC_ADDR, pRealtekIDVBS2->m_info.dvbs.symbol_rate));
                        }
                        #endif
                        REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.freq_khz=%lu\n", pRealtekIDVBS2->m_info.dvbs.freq_khz);
                        REALTEK_I_DVBS2_INFO("pRealtekIDVBS2->m_info.dvbs.symbol_rate=%lu\n", pRealtekIDVBS2->m_info.dvbs.symbol_rate);
                        
                        pDemodKernel->Lock(pDemodKernel);

                        ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_DETECT));//DemodCtrlDetect

                        //Set Bandwidth and Frequency to Acknowledge Demod to Lock
                        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, (unsigned int)pRealtekIDVBS2->m_info.dvbs.symbol_rate));//SetTunerBandwidth
                        ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1500000000));//SetTunerFreq //Set Frequency and Bandwidth together

                        stime = tv_osal_time();

                        pDemodKernel->Unlock(pDemodKernel);
                    }
                //pRealtekIDVBS2->m_auto_tune_en = 1;
                //}
            //}
        }
//#endif
    //}
#endif
    
    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : InspectSignal
 *
 * Desc : Inspect Signal Info (for Debug Purpose)
 *
 * Parm : pBuff : message buffer
 *        BufferSize : size of message buffer
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_InspectSignal(DEMOD* pDemodKernel)
{
    unsigned int DemodStatus = 0, SigLock = 0, Fer = 0, Per = 0, Snr = 0, TsPktCnt = 0, AcqTime = 0;
    float SnrResult = 0, FerResult = 0, PerResult = 0;
    int ret = TUNER_CTRL_OK;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    if (!DtvIsDemodClockEnable(RTK_DEMOD_MODE_DVBS2))
        return 0;

    pDemodKernel->Lock(pDemodKernel);

    ret |= DECODE_RET(pDemod->SetCmdVirtualRegister(pDemod, TV_REG_CONTROL, NULL_SEC_ADDR, TV_CMD_UPDATE_COUNTERS));//DemodCtrlUpdateCounters

    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
    if((ret == TUNER_CTRL_OK)&&(DemodStatus == 5))
        SigLock = YES;
    else
        SigLock = NO;

    if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
    {
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        Snr &= DVBS2_BITFLD_SNR_ESTIMATE;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_FER_AT_BCH_OUTPUT, NULL_SEC_ADDR, &Fer));
        Fer &= DVBS2_BITFLD_FER_AT_BCH_OUTPUT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per));
        Per &= DVBS2_BITFLD_PER_AT_OUTPUT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &TsPktCnt));
        TsPktCnt &= DVBS2_BITFLD_TS_PACKET_COUNT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));
        AcqTime &= DVBS2_BITFLD_ACQUISITION_TIME;
    }
    else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
    {
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        Snr &= DVBS2X_BITFLD_SNR_ESTIMATE;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_FER_AT_BCH_OUTPUT, NULL_SEC_ADDR, &Fer));
        Fer &= DVBS2X_BITFLD_FER_AT_BCH_OUTPUT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per));
        Per &= DVBS2X_BITFLD_PER_AT_OUTPUT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &TsPktCnt));
        TsPktCnt &= DVBS2X_BITFLD_TS_PACKET_COUNT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));
        AcqTime &= DVBS2X_BITFLD_ACQUISITION_TIME;
    }
    else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
    {
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        Snr &= DVBS_BITFLD_SNR_ESTIMATE;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_BER_AT_RS_INPUT, NULL_SEC_ADDR, &Fer));
        Fer &= DVBS_BITFLD_BER_AT_RS_INPUT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_PER_AT_OUTPUT, NULL_SEC_ADDR, &Per));
        Per &= DVBS_BITFLD_PER_AT_OUTPUT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_TS_PACKET_COUNT, NULL_SEC_ADDR, &TsPktCnt));
        TsPktCnt &= DVBS_BITFLD_TS_PACKET_COUNT;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACQUISITION_TIME, NULL_SEC_ADDR, &AcqTime));
        AcqTime &= DVBS_BITFLD_ACQUISITION_TIME;
    }

    SnrResult = (Snr*100)/655;
    FerResult = (Fer*10000)/4294967296;
    PerResult = (Per*10000)/4294967296;

    pDemodKernel->Unlock(pDemodKernel);

    #if 0
    ret = snprintf(pBuff, BufferSize, "[REALTEK_I_DVBS2] lock=%u, snr=%f, error_rate(BchFer/PktER)=%f/%f, ts_pkt_cnt=%u, demod_lock_time=%u\n",
                SigLock, (double)SnrResult,
                (double)FerResult, (double)PerResult, TsPktCnt, AcqTime);
    #endif

    return ret;
}


/*----------------------------------------------------------------------
 * Func : Activate
 *
 * Desc : Activate REALTEK_I_ QAM Demod
 *
 * Parm : N/A
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_Activate(DEMOD* pDemodKernel, unsigned char force_rst)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Init(pDemodKernel);

    return TUNER_CTRL_OK;

//--------------------------
/*
activate_demod_fail:
    pDemodKernel->Unlock(pDemodKernel);
    return TUNER_CTRL_FAIL;
*/
}


/*----------------------------------------------------------------------
 * Func : SetTvMode
 *
 * Desc : Set Mode of REALTEK_I_ALL
 *
 * Parm : mode :    RTK_DEMOD_MODE_DVBS2 : DVBS2 mode
 *                  RTK_DEMOD_MODE_DVBC  : DVBC mode
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetTvMode(DEMOD* pDemodKernel, TV_SYSTEM_TYPE mode)
{
    int ret = TUNER_CTRL_FAIL;
    
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);

    pDemodKernel->Lock(pDemodKernel);

    REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2::SetTvMode(%d)\n", mode);

    switch (mode) {

    case TV_SYS_TYPE_DVBS2:

        REALTEK_I_DVBS2_INFO("Set to DVBS2\n");
        ret = pDemodKernel->Init(pDemodKernel);
        //ret |= pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts);

        if (ret != TUNER_CTRL_OK) {
            REALTEK_I_DVBS2_WARNING("Set REALTEK_I_DVBS2 to DVBS2 mode failed\n");
            goto set_demod_mode_failed;
        }

        break;

    default:
        goto set_demod_mode_failed;
    }

    ret = TUNER_CTRL_OK;
    REALTEK_I_DVBS2_INFO("Set REALTEK_I_DVBS2 to appointed DTV mode successed\n");


//end_proc:

    pDemodKernel->Unlock(pDemodKernel);
    return ret;

//--------------
set_demod_mode_failed:
    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
}


void REALTEK_I_DVBS2_Lock(DEMOD* pDemodKernel)
{
    //mutex_lock(&pDemodKernel->m_lock);
}


void REALTEK_I_DVBS2_Unlock(DEMOD* pDemodKernel)
{
    //mutex_unlock(&pDemodKernel->m_lock);
}


/*-----------------------------------------------------------------
 *     BASE_INTERFACE for REALTEK_I_DVBS2 API
 *----------------------------------------------------------------*/


void ReleaseRealtekIDvbs2Driver(REALTEK_I_DVBS2_DRIVER_DATA *pDriver)
{
    kfree(pDriver);
}


REALTEK_I_DVBS2_DRIVER_DATA* AllocRealtekIDvbs2Driver(
    COMM*               pComm,
    unsigned char       Addr,
    unsigned long       CrystalFreq
)
{
    REALTEK_I_DVBS2_DRIVER_DATA* pDriver = (REALTEK_I_DVBS2_DRIVER_DATA*) kmalloc(
                                            sizeof(REALTEK_I_DVBS2_DRIVER_DATA) +
                                            sizeof(DVBS2_DEMOD_MODULE)   +
                                            sizeof(I2C_BRIDGE_MODULE)   +
                                            sizeof(BASE_INTERFACE_MODULE), GFP_KERNEL);

    if (pDriver) {
        BASE_INTERFACE_MODULE* pBIF;
        DVBS2_DEMOD_MODULE* pDemod;
        memset(pDriver, 0, sizeof(REALTEK_I_DVBS2_DRIVER_DATA));

        pDriver->pDemod                = (DVBS2_DEMOD_MODULE*)(((unsigned char*)pDriver) + sizeof(REALTEK_I_DVBS2_DRIVER_DATA));
        pDriver->pBaseInterface        = (BASE_INTERFACE_MODULE*)(((unsigned char*)pDriver->pDemod) + sizeof(DVBS2_DEMOD_MODULE));
        pDriver->pI2CBridge            = (I2C_BRIDGE_MODULE*)(((unsigned char*)pDriver->pBaseInterface) + sizeof(BASE_INTERFACE_MODULE));
        pDriver->DeviceAddr            = Addr;
        pDriver->CrystalFreqHz         = CrystalFreq;

        // Init Base IF
        pBIF = pDriver->pBaseInterface;

        pBIF->I2cReadingByteNumMax      = RTK_DEMOD_BIF_TX_FIFO_DEPTH;
        pBIF->I2cWritingByteNumMax      = RTK_DEMOD_BIF_RX_FIFO_DEPTH;
        pBIF->I2cRead                   = __realtek_i2c_read;
        pBIF->I2cWrite                  = __realtek_i2c_write;
        pBIF->WaitMs                    = __realtek_wait_ms;
        pBIF->SetUserDefinedDataPointer = base_interface_SetUserDefinedDataPointer;
        pBIF->GetUserDefinedDataPointer = base_interface_GetUserDefinedDataPointer;
        pBIF->SetUserDefinedDataPointer(pBIF, (void*)pComm);

        // Init Demod Driver
        BuildRealtekIDvbs2Module(&pDemod,
                               pDriver->pDemod,
                               pDriver->pBaseInterface,
                               pDriver->pI2CBridge,
                               Addr,
                               CrystalFreq);            // Spectrum mode is inverse.
    }

    return pDriver;
}


/*----------------------------------------------------------------------
 * Func : GetChannelInfo
 *
 * Desc : GetChannelInfo
 *        This function should be called after acquisition lock.
 *
 * Parm : 
 *
 *
 * Retn : TUNER_CTRL_OK / TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_GetChannelInfo(DEMOD* pDemodKernel, unsigned char* Standard, unsigned char* Modulation, unsigned char* CodeRate, unsigned char* PilotOnOff, unsigned char* Inverse)
{
    unsigned char lock = 0;
    unsigned int DemodStatus = 0, GetValue = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);
    
    lock = NO;

    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

    if(DemodStatus == 5)
    {
        lock = YES;

        if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2_MODE)
        {
            *Standard = 1;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2_BITFLD_ACTIVE_MODULATION;
            *Modulation = (unsigned char)GetValue;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2_BITFLD_ACTIVE_CODE_RATE;
            *CodeRate = (unsigned char)GetValue;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2_BITFLD_ACTIVE_PILOTS_PRESENT; 
            *PilotOnOff = (unsigned char)GetValue;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2_BITFLD_ACTIVE_SPECTRUM_INVERSION;
            *Inverse = (unsigned char)GetValue;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS2X_MODE)
        {
            *Standard = 1;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2X_BITFLD_ACTIVE_MODULATION;
            *Modulation = (unsigned char)GetValue;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2X_BITFLD_ACTIVE_CODE_RATE;
            *CodeRate = (unsigned char)GetValue;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_PILOTS_PRESENT, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2X_BITFLD_ACTIVE_PILOTS_PRESENT; 
            *PilotOnOff = (unsigned char)GetValue;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS2X_BITFLD_ACTIVE_SPECTRUM_INVERSION;
            *Inverse = (unsigned char)GetValue;
        }
        else if(pRealtekIDVBS2->m_dvbs2_ldr_mode == REALTEK_I_DVBS_MODE)
        {
            *Standard = 0;
            *Modulation = 0;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS_BITFLD_ACTIVE_CODE_RATE;
            *CodeRate = (unsigned char)GetValue;
            *PilotOnOff = 0;
            ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_SPECTRUM_INVERSION, NULL_SEC_ADDR, &GetValue));
            GetValue &= DVBS_BITFLD_ACTIVE_SPECTRUM_INVERSION;
            *Inverse = (unsigned char)GetValue;
        }
    }
    else
    {
        *Standard = 0;
        *Modulation = 0;
        *CodeRate = 0;
        *PilotOnOff = 0;
        *Inverse = 0;
    }

    REALTEK_I_DVBS2_INFO("GetActiveStandard = %x\n", *Standard);
    REALTEK_I_DVBS2_INFO("GetActiveModulation = %x\n", *Modulation);
    REALTEK_I_DVBS2_INFO("GetActiveCodeRate = %x\n", *CodeRate);
    REALTEK_I_DVBS2_INFO("GetActivePilotPresent = %x\n", *PilotOnOff);
    REALTEK_I_DVBS2_INFO("GetActiveSpectrumInversion = %x\n", *Inverse);

    pDemodKernel->Unlock(pDemodKernel);

    return (lock) ? TUNER_CTRL_OK : TUNER_CTRL_NO_SIGNAL;
}


/*----------------------------------------------------------------------
 * Func : ChangeStandard
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_ChangeStandard(DEMOD* pDemodKernel, unsigned int Mode)
{
    int ret = TUNER_CTRL_OK;
    unsigned int IsRpuLowReady = 0, IsRpuHighReady = 0;
    unsigned int BuildId = 0, DemodType = 0;
    unsigned int InitRetry = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);

    if (pDemodKernel->m_pComm == NULL || pRealtekIDVBS2->m_private == NULL)
        return TUNER_CTRL_FAIL;
    
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    //pRealtekIDVBS2->m_auto_tune_en = 0;
    
demod_re_init:
    if(Mode == REALTEK_I_DVBS_MODE)
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_DVBS, 1);
        pRealtekIDVBS2->m_dvbs2_ldr_mode = REALTEK_I_DVBS_MODE;
    }
    else if(Mode == REALTEK_I_DVBS2_MODE)
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_DVBS2, 1);
        pRealtekIDVBS2->m_dvbs2_ldr_mode = REALTEK_I_DVBS2_MODE;
    }
    else if(Mode == REALTEK_I_DVBS2X_MODE)
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_DVBS2X, 1);
        pRealtekIDVBS2->m_dvbs2_ldr_mode = REALTEK_I_DVBS2X_MODE;
    }
    else if(Mode == REALTEK_I_SPEC_AN_BS_MODE)
    {
        DtvDemodInitialization(RTK_DEMOD_MODE_SPEC_AN, 1);
        pRealtekIDVBS2->m_dvbs2_ldr_mode = REALTEK_I_SPEC_AN_BS_MODE;
    }
    
    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuLowReady));//Check for Low level Header
    ret |= DECODE_RET(pDemod->CheckRpuReady(pDemod, &IsRpuHighReady));//Check for High level Msg

    if(IsRpuLowReady != 1 || IsRpuHighReady != 1)
    {
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("Waiting for Demod Init Done; Demod Has No Reply !!!!\n");
        REALTEK_I_DVBS2_INFO("RpuLowReady = %d, RpuHighReady = %d\n", IsRpuLowReady, IsRpuHighReady);
        
        if(!InitRetry)
        {
            InitRetry = 1;
            REALTEK_I_DVBS2_INFO("RPU Auto Re-Init in Demod Init\n");
            goto demod_re_init;
        }
        else
        {
            goto init_fail;
        }
    }

    //Change To Buffer Mode
    REALTEK_I_DVBS2_INFO("Change To Buffer Mode........\n");
    ret |= DECODE_RET(pDemod->SwitchToBuffer(pDemod));
    if (ret!= TUNER_CTRL_OK)
    {
        REALTEK_I_DVBS2_INFO("Change To Buffer Mode Fail !!!!!\n");
        goto init_fail;
    }

    ret |= DECODE_RET(pDemod->ActivateCore(pDemod));

    pDemod->SetDiseqcContinue22kOnOff(DvbS2_Keep_22k_on_off);

    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod,TV_REG_DEMOD_ID, NULL_SEC_ADDR, &DemodType));//GetDemodInfo
    DemodType = ((DemodType&0xFF000000)>>24);
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_BUILD_ID, NULL_SEC_ADDR, &BuildId));//GetBuildId
    REALTEK_I_DVBS2_INFO("DemodType = %x, BuildId = %x\n", DemodType, BuildId);

    if(Mode == REALTEK_I_DVBS_MODE)
    {
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_SET_IF_GAIN_CTRL, NULL_SEC_ADDR, pRealtekIDVBS2->m_dvbs_AgcScale|(RTK_DEMOD_XML_EXT_GAIN1<<16)));//SetXmlTunerGainCtrl //Tuner 1:positive 0:negative; Demod 0:positive 1:negative
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_FLAGS, NULL_SEC_ADDR, RTK_DEMOD_XML_COMPLEX_IF|(pDemodKernel->m_if.inversion<<1)|(RTK_DEMOD_XML_UNSIGNED<<2)));//SetXmlFlags
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_FREQ, NULL_SEC_ADDR, pDemodKernel->m_if.freq));//SetXmlIfFreq
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_CFG_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlTunerCfgOverride

        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_CLK_FREQUENCY, NULL_SEC_ADDR, 90000000));//SetXmlIfClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_LDPC_CLK_FREQUENCY, NULL_SEC_ADDR, 607000000));//SetXmlLdpcClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_UCC_CLK_FREQUENCY, NULL_SEC_ADDR, 303000000));//SetXmlUccClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_MCU_CLK_FREQUENCY, NULL_SEC_ADDR, 607000000));//SetXmlMcuClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlPlftCfgOverride
        
        if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
            goto init_fail;

        REALTEK_I_DVBS2_DBG("REALTEK_I_DVBS Init Complete\n");
        
        //Set Ber Cal Period to 1 Sec
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS_REG_NUM_SECONDS_BER_AVERAGING, NULL_SEC_ADDR, (0x00000001 & DVBS_BITFLD_NUM_SECONDS_BER_AVERAGING)));//DvbSSetNumSecBerAvg
    }
    else if(Mode == REALTEK_I_DVBS2_MODE)
    {
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_SET_IF_GAIN_CTRL, NULL_SEC_ADDR, pRealtekIDVBS2->m_dvbs2_AgcScale|(RTK_DEMOD_XML_EXT_GAIN1<<16)));//SetXmlTunerGainCtrl ////Tuner 1:positive 0:negative; Demod 0:positive 1:negative
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_FLAGS, NULL_SEC_ADDR, RTK_DEMOD_XML_COMPLEX_IF|(pDemodKernel->m_if.inversion<<1)|(RTK_DEMOD_XML_UNSIGNED<<2)));//SetXmlFlags
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_FREQ, NULL_SEC_ADDR, pDemodKernel->m_if.freq));//SetXmlIfFreq
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_CFG_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlTunerCfgOverride

        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_CLK_FREQUENCY, NULL_SEC_ADDR, 90000000));//SetXmlIfClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_LDPC_CLK_FREQUENCY, NULL_SEC_ADDR, 607000000));//SetXmlLdpcClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_UCC_CLK_FREQUENCY, NULL_SEC_ADDR, 303000000));//SetXmlUccClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_MCU_CLK_FREQUENCY, NULL_SEC_ADDR, 607000000));//SetXmlMcuClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlPlftCfgOverride
        
        if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
            goto init_fail;

        REALTEK_I_DVBS2_DBG("REALTEK_I_DVBS2 Init Complete\n");
        
        //Set Ber Cal Period to 1 Sec
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2_REG_NUM_SECONDS_BER_AVERAGING, NULL_SEC_ADDR, (0x00000001 & DVBS2_BITFLD_NUM_SECONDS_BER_AVERAGING)));//SetBerAveSecNum
    }
    else if(Mode == REALTEK_I_DVBS2X_MODE)
    {
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_SET_IF_GAIN_CTRL, NULL_SEC_ADDR, pRealtekIDVBS2->m_dvbs2_AgcScale|(RTK_DEMOD_XML_EXT_GAIN1<<16)));//SetXmlTunerGainCtrl //Tuner 1:positive 0:negative; Demod 0:positive 1:negative
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_FLAGS, NULL_SEC_ADDR, RTK_DEMOD_XML_COMPLEX_IF|(pDemodKernel->m_if.inversion<<1)|(RTK_DEMOD_XML_UNSIGNED<<2)));//SetXmlFlags
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_FREQ, NULL_SEC_ADDR, pDemodKernel->m_if.freq));//SetXmlIfFreq
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_CFG_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlTunerCfgOverride

        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_IF_CLK_FREQUENCY, NULL_SEC_ADDR, 90000000));//SetXmlIfClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_LDPC_CLK_FREQUENCY, NULL_SEC_ADDR, 675000000));//SetXmlLdpcClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_UCC_CLK_FREQUENCY, NULL_SEC_ADDR, 337000000));//SetXmlUccClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_MCU_CLK_FREQUENCY, NULL_SEC_ADDR, 675000000));//SetXmlMcuClk
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_PFM_OVERRIDE, NULL_SEC_ADDR, 0x00000001));//SetXmlPlftCfgOverride
        
        if (pDemodKernel->SetTSMode(pDemodKernel, &pDemodKernel->m_ts) != TUNER_CTRL_OK)
            goto init_fail;

        REALTEK_I_DVBS2_DBG("REALTEK_I_DVBS2X Init Complete\n");
        
        //Set Ber Cal Period to 1 Sec
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, DVBS2X_REG_NUM_SECONDS_BER_AVERAGING, NULL_SEC_ADDR, (0x00000001 & DVBS2X_BITFLD_NUM_SECONDS_BER_AVERAGING)));//SetBerAveSecNum
    }
    else if(Mode == REALTEK_I_SPEC_AN_BS_MODE)
    {
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_BW, NULL_SEC_ADDR, 140000000));//SetTunerBandwidth
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_FREQ, NULL_SEC_ADDR, 1000000000));//SetTunerFreq
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod,SA_SCAN_RANGE, NULL_SEC_ADDR, (0 & SA_BITFLD_SCAN_RANGE)));//DvbS2SetSpecAnScanRange
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, SA_SCAN_RESOLUTION, NULL_SEC_ADDR, (BS_FFT_RESOLUTION & SA_BITFLD_SCAN_RESOLUTION)));//DvbS2SetSpecAnScanResolution
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_GRID_BASE, NULL_SEC_ADDR, 0));//SetTunerGridBase
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, TV_REG_TUNER_GRID_INCR, NULL_SEC_ADDR, 1000000));//SetTunerGridIncr

        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod,SA_AVERAGING_PERIOD, NULL_SEC_ADDR, (((8 << 8)& SA_BITFLD_AVERAGING_PERIOD_M ) | (8 & SA_BITFLD_AVERAGING_PERIOD_N))));//DvbS2SetSpecAnAveragePeriod
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod, SA_TUNING_STEP, NULL_SEC_ADDR, (((0 << 30) & SA_BITFLD_TUNING_STEP_AUTO) | (70000000 & SA_BITFLD_TUNING_STEP))));//DvbS2SetSpecAnTuningStep
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod,SA_MEASUREMENT_CONTROL, NULL_SEC_ADDR, (((0 << 9)&SA_BITFLD_ENABLE_DC_COMP) | ((1 << 6)&SA_BITFLD_WINDOW) | ((0 << 3)&SA_BITFLD_SIGNAL_TYPE) | (0&SA_BITFLD_MAX_PEAK_WIDTH))));//DvbS2SetSpecAnMeasureCtrl
        ret |= DECODE_RET(pDemod->SetVirtualRegister(pDemod,SA_IF_GAIN_OVERRIDE, NULL_SEC_ADDR, (((1 << 16)&SA_BITFLD_OVERRIDE_IF_GAIN) | (36000&SA_BITFLD_IF_GAIN))));//DvbS2SetSpecAnIfGainOverride
    }
    
    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_OK;

init_fail:

    REALTEK_I_DVBS2_WARNING("REALTEK_I_DVBS2 Init Failed\n");

    pDemodKernel->Unlock(pDemodKernel);

    return TUNER_CTRL_FAIL;
}


/*----------------------------------------------------------------------
 * Func : CalDvbS2Ssi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_CalDvbS2Ssi(DEMOD* pDemodKernel)
{
    unsigned int DemodStatus = 0, IfAgcGain = 0, Ssi = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    ret = DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
    ret = DECODE_RET(pDemod->GetHwRegValue(0x02041090, &IfAgcGain));//GetIfAgcGain
    IfAgcGain = IfAgcGain >> 20;
    
    pDemodKernel->Unlock(pDemodKernel);

    if(DemodStatus == 5)
    {
        Ssi = (((0xFFF - IfAgcGain)*40)/0xFFF)+ 60;

        if(Ssi > 100)
            Ssi = 100;
        else if(Ssi < 50)
            Ssi = 50;
    }
    else
    {
        Ssi = 0;
    }

    return Ssi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbS2Sqi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_CalDvbS2Sqi(DEMOD* pDemodKernel)
{
    int ret = TUNER_CTRL_OK;
    unsigned int CalHighBound = 0, CalMidBound = 0, CalLowBound = 0, Modulation = 0, CodeRate = 0, DemodStatus = 0, Sqi = 0, Snr = 0;
    unsigned char u8i = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);
    
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

    if(DemodStatus == 5)
    {
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &Modulation));
        Modulation &= DVBS2_BITFLD_ACTIVE_MODULATION;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &CodeRate));
        CodeRate &= DVBS2_BITFLD_ACTIVE_CODE_RATE;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        pRealtekIDVBS2->m_dvbs2_snr = Snr/6553;
        
        for(u8i = 0; u8i < DVBS2_SIG_QUALITY_TABLE_SIZE; u8i++)
        {
            if(_gsDvbs2SigQualityMappingTable[u8i].Modulation == Modulation &&
               _gsDvbs2SigQualityMappingTable[u8i].CodeRate == CodeRate)
            {
                CalHighBound = _gsDvbs2SigQualityMappingTable[u8i].sBound.HighBound;
                CalMidBound = _gsDvbs2SigQualityMappingTable[u8i].sBound.MidBound;
                CalLowBound = _gsDvbs2SigQualityMappingTable[u8i].sBound.LowBound;
                break;
            }
        }

        if(pRealtekIDVBS2->m_dvbs2_snr >= CalHighBound)
        {
            Sqi = 100;
        }
        else if(pRealtekIDVBS2->m_dvbs2_snr >= CalMidBound)
        {
            Sqi = ((((pRealtekIDVBS2->m_dvbs2_snr - CalMidBound)*100) / (CalHighBound - CalMidBound))*90)/100 + 10;
        }
        else if(pRealtekIDVBS2->m_dvbs2_snr >= CalLowBound)
        {
            Sqi = ((((pRealtekIDVBS2->m_dvbs2_snr - CalLowBound)*100) / (CalMidBound - CalLowBound))*10)/100;
        }
        else
        {
            Sqi = 0;
        }
    }
    else
    {
        Sqi = 0;
    }
    
    pDemodKernel->Unlock(pDemodKernel);

    return Sqi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbS2XSsi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_CalDvbS2XSsi(DEMOD* pDemodKernel)
{
    unsigned int DemodStatus = 0, IfAgcGain = 0, Ssi = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    ret = DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
    ret = DECODE_RET(pDemod->GetHwRegValue(0x02041090, &IfAgcGain));//GetIfAgcGain
    IfAgcGain = IfAgcGain >> 20;
    
    pDemodKernel->Unlock(pDemodKernel);

    if(DemodStatus == 5)
    {
        Ssi = (((0xFFF - IfAgcGain)*40)/0xFFF)+ 60;

        if(Ssi > 100)
            Ssi = 100;
        else if(Ssi < 50)
            Ssi = 50;
    }
    else
    {
        Ssi = 0;
    }

    return Ssi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbS2XSqi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_CalDvbS2XSqi(DEMOD* pDemodKernel)
{
    int ret = TUNER_CTRL_OK;
    unsigned int CalHighBound = 0, CalMidBound = 0, CalLowBound = 0, Modulation = 0, CodeRate = 0, DemodStatus = 0, Sqi = 0, Snr = 0;
    unsigned char u8i = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);
    
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

    if(DemodStatus == 5)
    {
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_MODULATION, NULL_SEC_ADDR, &Modulation));
        Modulation &= DVBS2_BITFLD_ACTIVE_MODULATION;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &CodeRate));
        CodeRate &= DVBS2_BITFLD_ACTIVE_CODE_RATE;
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS2X_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        pRealtekIDVBS2->m_dvbs2_snr = Snr/6553;
        
        for(u8i = 0; u8i < DVBS2_SIG_QUALITY_TABLE_SIZE; u8i++)
        {
            if(_gsDvbs2SigQualityMappingTable[u8i].Modulation == Modulation &&
               _gsDvbs2SigQualityMappingTable[u8i].CodeRate == CodeRate)
            {
                CalHighBound = _gsDvbs2SigQualityMappingTable[u8i].sBound.HighBound;
                CalMidBound = _gsDvbs2SigQualityMappingTable[u8i].sBound.MidBound;
                CalLowBound = _gsDvbs2SigQualityMappingTable[u8i].sBound.LowBound;
                break;
            }
        }

        if(pRealtekIDVBS2->m_dvbs2_snr >= CalHighBound)
        {
            Sqi = 100;
        }
        else if(pRealtekIDVBS2->m_dvbs2_snr >= CalMidBound)
        {
            Sqi = ((((pRealtekIDVBS2->m_dvbs2_snr - CalMidBound)*100) / (CalHighBound - CalMidBound))*90)/100 + 10;
        }
        else if(pRealtekIDVBS2->m_dvbs2_snr >= CalLowBound)
        {
            Sqi = ((((pRealtekIDVBS2->m_dvbs2_snr - CalLowBound)*100) / (CalMidBound - CalLowBound))*10)/100;
        }
        else
        {
            Sqi = 0;
        }
    }
    else
    {
        Sqi = 0;
    }
    
    pDemodKernel->Unlock(pDemodKernel);

    return Sqi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbSSsi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_CalDvbSSsi(DEMOD* pDemodKernel)
{
    unsigned int DemodStatus = 0, IfAgcGain = 0, Ssi = 0;
    int ret = TUNER_CTRL_OK;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    pDemodKernel->Lock(pDemodKernel);

    ret = DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus
    ret = DECODE_RET(pDemod->GetHwRegValue(0x02041090, &IfAgcGain));//GetIfAgcGain
    IfAgcGain = IfAgcGain >> 20;
    
    pDemodKernel->Unlock(pDemodKernel);

    if(DemodStatus == 5)
    {
        Ssi = (((0xFFF - IfAgcGain)*40)/0xFFF)+ 60;

        if(Ssi > 100)
            Ssi = 100;
        else if(Ssi < 50)
            Ssi = 50;
    }
    else
    {
        Ssi = 0;
    }

    return Ssi;
}


/*----------------------------------------------------------------------
 * Func : CalDvbSSqi
 *
 * Desc :
 *
 * Parm :
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_CalDvbSSqi(DEMOD* pDemodKernel)
{
    int ret = TUNER_CTRL_OK;
    unsigned int CalHighBound = 0, CalMidBound = 0, CalLowBound = 0, CodeRate = 0, DemodStatus = 0, Sqi = 0, Snr = 0;
    unsigned char u8i = 0;

    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    pDemodKernel->Lock(pDemodKernel);
    
    ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, TV_REG_STATE, NULL_SEC_ADDR, &DemodStatus));//GetDemodStatus

    if(DemodStatus == 5)
    {
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_ACTIVE_CODE_RATE, NULL_SEC_ADDR, &CodeRate));
        ret |= DECODE_RET(pDemod->GetVirtualRegister(pDemod, DVBS_REG_SNR_ESTIMATE, NULL_SEC_ADDR, &Snr));
        pRealtekIDVBS2->m_dvbs2_snr = Snr/6553;

        for(u8i = 0; u8i < DVBS_SIG_QUALITY_TABLE_SIZE; u8i++)
        {
            if(_gsDvbSSigQualityMappingTable[u8i].CodeRate == CodeRate)
            {
                CalHighBound = _gsDvbSSigQualityMappingTable[u8i].sBound.HighBound;
                CalMidBound = _gsDvbSSigQualityMappingTable[u8i].sBound.MidBound;
                CalLowBound = _gsDvbSSigQualityMappingTable[u8i].sBound.LowBound;
                break;
            }
        }

        if(pRealtekIDVBS2->m_dvbs2_snr >= CalHighBound)
        {
            Sqi = 100;
        }
        else if(pRealtekIDVBS2->m_dvbs2_snr >= CalMidBound)
        {
            //SNR shift 0.6dB to Calculate
            Sqi = (((((pRealtekIDVBS2->m_dvbs2_snr + 6) - CalMidBound)*100) / (CalHighBound - CalMidBound))*90)/100 + 10;
        }
        else if(pRealtekIDVBS2->m_dvbs2_snr >= CalLowBound)
        {
            Sqi = ((((pRealtekIDVBS2->m_dvbs2_snr - CalLowBound)*100) / (CalMidBound - CalLowBound))*10)/100;
        }
        else
        {
            Sqi = 0;
        }
    }
    else
    {
        Sqi = 0;
    }
    
    pDemodKernel->Unlock(pDemodKernel);

    return Sqi;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcContinue22kOnOff
 *
 * Desc : Set Diseqc 22K always ON/OFF
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetDiseqcContinue22kOnOff(DEMOD* pDemodKernel, unsigned int OnOff)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
    
    REALTEK_I_DVBS2_INFO("REALTEK_I_DVBS2_SetDiseqcContinue22kOnOff %d\n", OnOff);

    //Direct link to diseqc driver, not here
    pDemod->SetDiseqcContinue22kOnOff(OnOff);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcCmd
 *
 * Desc : Set Diseqc command
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetDiseqcCmd(DEMOD* pDemodKernel, unsigned int Length, unsigned char *Data)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
        
    //Direct link to diseqc driver, not here
    pDemod->SetDiseqcCmd(Length, Data);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcToneBurst
 *
 * Desc : Set Un-Modulated Tone Burst(SA)
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetDiseqcToneBurst(DEMOD* pDemodKernel, DISEQC_TONE_MODE mode)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;

    //Direct link to diseqc driver, not here
    pDemod->SetDiseqcToneBurst(mode);

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcUnModToneBurst
 *
 * Desc : Set Un-Modulated Tone Burst(SA)
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetDiseqcUnModToneBurst(DEMOD* pDemodKernel)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
        
    //Direct link to diseqc driver, not here
    pDemod->SetDiseqcUnModToneBurst();

    return TUNER_CTRL_OK;
}


/*----------------------------------------------------------------------
 * Func : SetDiseqcModToneBurst
 *
 * Desc : Set Modulated Tone Burst(SB)
 *
 * Parm : 
 *
 * Retn : TUNER_CTRL_OK/TUNER_CTRL_FAIL
 *----------------------------------------------------------------------*/
int REALTEK_I_DVBS2_SetDiseqcModToneBurst(DEMOD* pDemodKernel)
{
    REALTEK_I_DVBS2* pRealtekIDVBS2;
    DVBS2_DEMOD_MODULE* pDemod;
    pRealtekIDVBS2 = (REALTEK_I_DVBS2*)(pDemodKernel->private_data);
    pDemod = ((REALTEK_I_DVBS2_DRIVER_DATA*) pRealtekIDVBS2->m_private)->pDemod;
        
    //Direct link to diseqc driver, not here
    pDemod->SetDiseqcModToneBurst();

    return TUNER_CTRL_OK;
}

