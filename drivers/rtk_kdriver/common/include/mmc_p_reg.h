/**************************************************************
// Spec Version                  : 0.9
// Parser Version                : DVR_Parser_6.11(120105)
// CModelGen Version             : 5.1 2012.01.05
// Naming Rule                   :  Register_Name
// Naming Rule                   : Module_Register_Name_reg
// Parse Option                  : Only Parse _op1
// Parse Address Region          : All Address Region
// Decode bit number             : 12 bits
// Firmware Header Generate Date : 2013/12/5 16:43:43
***************************************************************/


#ifndef _MMC_P_REG_H_
#define _MMC_P_REG_H_

#define EMMC_SCRIPT_BUF_SIZE            4096
#define EMMC_MAX_SCRIPT_BLK             15   /* this value is IP limit, can't increase */
#define EMMC_MAX_SCRIPT_LINE            (EMMC_SCRIPT_BUF_SIZE/16)

/*
 * Rbus Register mapping (0x1801_0800~0x1801_0890)
 */

/* EMMC_WRAPPER register (0x1801_0800~0x1801_08FF) */
#define EM_PLUS_BASE                (0xb8010800)

/* Non-security CPU registers: 0x1801_0800 ~ 0x1801_080C (all CPU can access) */
#define EM_SCPU_SEL                 (EM_PLUS_BASE+0x00UL)     //0x18010800
#define EM_INT_STATUS               (EM_PLUS_BASE+0x04UL)     //0x18010804
#define EM_INT_MASK                 (EM_PLUS_BASE+0x08UL)     //0x18010808
#define EM_INT_DUMMY0               (EM_PLUS_BASE+0x0CUL)     //0x1801080C

/* Security CPU (KCPU) registers: 0x1801_0810 ~ 0x1802_082C (only KCPU can access) */
#define EM_KCPU_SEL                 (EM_PLUS_BASE+0x10UL)     //0x18010810
#define EM_START_PROTECT_ADDR       (EM_PLUS_BASE+0x14UL)     //0x18010814
#define EM_END_PROTECT_ADDR         (EM_PLUS_BASE+0x18UL)     //0x18010818
#define EM_INT_STATUS_KCPU          (EM_PLUS_BASE+0x1CUL)     //0x1801081C
#define EM_INT_MASK_KCPU            (EM_PLUS_BASE+0x20UL)     //0x18010820
#define EM_DUMMY0_KCPU              (EM_PLUS_BASE+0x24UL)     //0x18010824
#define EM_DUMMY1_KCPU              (EM_PLUS_BASE+0x28UL)     //0x18010828
#define EM_DUMMY2_KCPU              (EM_PLUS_BASE+0x2CUL)     //0x1801082C

/*
 * Only KCPU can access when kcpu_status = 1 (1801_0830~1801_08FF)
 * All CPUs can access when kcpu_status = 0
*/
#define EM_WARP_CTRL                (EM_PLUS_BASE+0x30UL)     //0x18010830
#define EM_WARP_STATUS0             (EM_PLUS_BASE+0x34UL)     //0x18010834
#define EM_WARP_STATUS1             (EM_PLUS_BASE+0x38UL)     //0x18010838
#define EM_WARP_STATUS2             (EM_PLUS_BASE+0x3CUL)     //0x1801083C

/* MBIST */
#define EM_IP_BIST                  (EM_PLUS_BASE+0x40UL)     //0x18010840
#define EM_WARP_BIST                (EM_PLUS_BASE+0x44UL)     //0x18010844
#define EM_CLK_PHASE_SEL            (EM_PLUS_BASE+0x48UL)     //0x18010848

/* DS tune */
#define EM_DS_TUNE_CTRL             (EM_PLUS_BASE+0x50UL)     //0x18010850
#define EM_DS_TUNE_CAL_DQ0_1        (EM_PLUS_BASE+0x54UL)     //0x18010854
#define EM_DS_TUNE_CAL_DQ2_3        (EM_PLUS_BASE+0x58UL)     //0x18010858
#define EM_DS_TUNE_CAL_DQ4_5        (EM_PLUS_BASE+0x5CUL)     //0x1801085C
#define EM_DS_TUNE_CAL_DQ6_7        (EM_PLUS_BASE+0x60UL)     //0x18010860
#define EM_DS_TUNE_CAL_DQ8          (EM_PLUS_BASE+0x64UL)     //0x18010864
#define EM_DS_TUNE_PH_SEL_0_1       (EM_PLUS_BASE+0x68UL)     //0x18010868
#define EM_DS_TUNE_PH_SEL_2_3       (EM_PLUS_BASE+0x6CUL)     //0x1801086C
#define EM_DS_TUNE_PH_SEL_4_5       (EM_PLUS_BASE+0x70UL)     //0x18010870
#define EM_DS_TUNE_PH_SEL_6_7       (EM_PLUS_BASE+0x74UL)     //0x18010874
#define EM_DS_TUNE_PH_SEL_8         (EM_PLUS_BASE+0x78UL)     //0x18010878
#define EM_DS_TUNE_RCV_1ST          (EM_PLUS_BASE+0x7CUL)     //0x1801087C

/* CP mode */
#define EM_CPMASK_0                 (EM_PLUS_BASE+0x80UL)     //0x18010880
#define EM_CPMASK_1                 (EM_PLUS_BASE+0x84UL)     //0x18010884
#define EM_CPMASK_2                 (EM_PLUS_BASE+0x88UL)     //0x18010888

/* Delay_cal */
#define EM_HALF_CYCLE_CAL_EN        (EM_PLUS_BASE+0x8CUL)     //0x1801088C
#define EM_HALF_CYCLE_CAL_RESULT    (EM_PLUS_BASE+0x90UL)     //0x18010890

/*
 * DWC_Mobile_Storage register address mapping:
 *          0x1801_0900~0x1801_0BFF
 */
#define DWC_IP_BASE                 (0xb8010900)

#define EM_DWC_CTRL                 (DWC_IP_BASE+0x000UL)     //0x18010900
#define EM_DWC_PWREN                (DWC_IP_BASE+0x004UL)     //0x18010904
#define EM_DWC_CLKDIV               (DWC_IP_BASE+0x008UL)     //0x18010908
#define EM_DWC_CLKSRC               (DWC_IP_BASE+0x00CUL)     //0x1801090C
#define EM_DWC_CLKENA               (DWC_IP_BASE+0x010UL)     //0x18010910
#define EM_DWC_TMOUT                (DWC_IP_BASE+0x014UL)     //0x18010914
#define EM_DWC_CTYPE                (DWC_IP_BASE+0x018UL)     //0x18010918
#define EM_DWC_BLKSIZ               (DWC_IP_BASE+0x01CUL)     //0x1801091C
#define EM_DWC_BYTCNT               (DWC_IP_BASE+0x020UL)     //0x18010920
#define EM_DWC_INTMASK              (DWC_IP_BASE+0x024UL)     //0x18010924
#define EM_DWC_CMDARG               (DWC_IP_BASE+0x028UL)     //0x18010928
#define EM_DWC_CMD                  (DWC_IP_BASE+0x02CUL)     //0x1801092C
#define EM_DWC_RESP0                (DWC_IP_BASE+0x030UL)     //0x18010930
#define EM_DWC_RESP1                (DWC_IP_BASE+0x034UL)     //0x18010934
#define EM_DWC_RESP2                (DWC_IP_BASE+0x038UL)     //0x18010938
#define EM_DWC_RESP3                (DWC_IP_BASE+0x03CUL)     //0x1801093C
#define EM_DWC_MINTSTS              (DWC_IP_BASE+0x040UL)     //0x18010940
#define EM_DWC_RINTSTS              (DWC_IP_BASE+0x044UL)     //0x18010944
#define EM_DWC_STATUS               (DWC_IP_BASE+0x048UL)     //0x18010948
#define EM_DWC_FIFOTH               (DWC_IP_BASE+0x04CUL)     //0x1801094C
#define EM_DWC_CDETECT              (DWC_IP_BASE+0x050UL)     //0x18010950
#define EM_DWC_WRTPRT               (DWC_IP_BASE+0x054UL)     //0x18010954
#define EM_DWC_GPIO                 (DWC_IP_BASE+0x058UL)     //0x18010958
#define EM_DWC_TCBCNT               (DWC_IP_BASE+0x05CUL)     //0x1801095C
#define EM_DWC_TBBCNT               (DWC_IP_BASE+0x060UL)     //0x18010960
#define EM_DWC_DEBNCE               (DWC_IP_BASE+0x064UL)     //0x18010964
#define EM_DWC_USRID                (DWC_IP_BASE+0x068UL)     //0x18010968
#define EM_DWC_VERID                (DWC_IP_BASE+0x06CUL)     //0x1801096C
#define EM_DWC_HCON                 (DWC_IP_BASE+0x070UL)     //0x18010970
#define EM_DWC_UHS_REG              (DWC_IP_BASE+0x074UL)     //0x18010974
#define EM_DWC_RST_n                (DWC_IP_BASE+0x078UL)     //0x18010978
#define EM_DWC_BMOD                 (DWC_IP_BASE+0x080UL)     //0x18010980
#define EM_DWC_PLDMND               (DWC_IP_BASE+0x084UL)     //0x18010984
#define EM_DWC_DBADDR               (DWC_IP_BASE+0x088UL)     //0x18010988
#define EM_DWC_DBADDRL64            (DWC_IP_BASE+0x088UL)     //0x18010988
#define EM_DWC_DBADDRU64            (DWC_IP_BASE+0x08CUL)     //0x1801098C
#define EM_DWC_IDSTS                (DWC_IP_BASE+0x08CUL)     //0x1801098C
#define EM_DWC_IDSTS64              (DWC_IP_BASE+0x090UL)     //0x18010990
#define EM_DWC_IDINTEN              (DWC_IP_BASE+0x090UL)     //0x18010990
#define EM_DWC_IDINTEN64            (DWC_IP_BASE+0x094UL)     //0x18010994
#define EM_DWC_DSCADDR              (DWC_IP_BASE+0x094UL)     //0x18010994
#define EM_DWC_DSCADDRL64           (DWC_IP_BASE+0x098UL)     //0x18010998
#define EM_DWC_DSCADDRU64           (DWC_IP_BASE+0x09CUL)     //0x1801099C
#define EM_DWC_BUFADDR              (DWC_IP_BASE+0x098UL)     //0x18010998
#define EM_DWC_BUFADDRL64           (DWC_IP_BASE+0x0A0UL)     //0x180109A0
#define EM_DWC_BUFADDRU64           (DWC_IP_BASE+0x0A4UL)     //0x180109A4
#define EM_DWC_CardThrCtl           (DWC_IP_BASE+0x100UL)     //0x18010a00
#define EM_DWC_Back_END_POWER       (DWC_IP_BASE+0x104UL)     //0x18010a04
#define EM_DWC_UHS_REG_EXT          (DWC_IP_BASE+0x108UL)     //0x18010a08
#define EM_DWC_EMMC_DDR_REG         (DWC_IP_BASE+0x10CUL)     //0x18010a0C
#define EM_DWC_ENABLE_SHIFT         (DWC_IP_BASE+0x110UL)     //0x18010a10
#define EM_DWC_DATA_BASE            (DWC_IP_BASE+0x200UL)     //0x18010b00

/* ====== Register Bit define ====== */
/* Wapper */
//EM_SCPU_SEL               //0x18010800
#define PS_SCPU_STOP                   _BIT2
#define PS_SCPU_STATUS                 _BIT1
#define PS_SCPU_SEL                    _BIT0

//EM_INT_STATUS             //0x18010804
#define PS_DMA_RD_DONE_S               _BIT2
#define PS_DMA_WR_DONE_S               _BIT1
#define PS_STOP_BY_KCPU_FORCE_S        _BIT0

//EM_INT_MASK               //0x18010808
#define PS_DMA_RD_DONE_MASK_S          _BIT2
#define PS_DMA_WD_DONE_MASK_S          _BIT1
#define PS_STOP_BY_KCPU_FORCE_MASK_S   _BIT0

//EM_KCPU_SEL               //0x18010810
#define PS_KCPU_FORCE_EN               _BIT3
#define PS_PROTECT_ADDR_EN             _BIT2
#define PS_KCPU_STATUS                 _BIT1
#define PS_KCPU_SEL                    _BIT0

//EM_INT_STATUS_KCPU        //0x1801081C
#define PS_DMA_RD_DONE_K               _BIT2
#define PS_DMA_WR_DONE_K               _BIT1
#define PS_PROTECT_HIT_K               _BIT0

//EM_INT_MASK_KCPU          //0x18010820
#define PS_DMA_RD_DONE_MASK_K          _BIT2
#define PS_DMA_WR_DONE_MASK_K          _BIT1
#define PS_PROTECT_HIT_MASK_K          _BIT0

//EM_WARP_CTRL              //0x18010830
#define PS_CP_BLK_LEN_SHT              (16)
#define PS_CP_BLK_LEN_MASK             (0x7FFFUL<<CP_BLK_LEN_SHT)
#define PS_CP_MODE_EN                  _BIT15
#define PS_CCLK_IN_SAMPLE_EXT_SEL      _BIT13
#define PS_CCLK_IN_SAMPLE_EXT_EN       _BIT12
#define PS_ECO_OPTION0_DIS             _BIT11
#define PS_M_HBIG_ENDIAN               _BIT10
#define PS_S_HBIG_ENDIAN               _BIT9
#define PS_CCLK_OUT_SRC_SEL            _BIT8
#define PS_WARP_VERSION                _BIT7
#define PS_DEBUG_MUX_SHT               (1)
#define PS_DEBUG_MUX_MASK              (0x3FUL<<DEBUG_MUX_SHT)
#define PS_DEBUG_CTRL                  _BIT0

//EM_WARP_STATUS0           //0x18010834
#define PS_REAL_DUMMY0_SHT             (16)
#define PS_REAL_DUMMY0_MASK            (0xFFFFUL<<REAL_DUMMY0_SHT)
#define PS_RBUS_ERR                    _BIT2
#define PS_DBUS_DMA_BUSY               _BIT1
#define PS_DBUS_WRITE_FLAG             _BIT0

//EM_WARP_STATUS1           //0x18010838
#define PS_ICTRL_STATE_SHT             (16)
#define PS_ICTRL_STATE_MASK            (0x07UL<<ICTRL_STATE_SHT)
#define PS_TOP_SM_SHT                  (0)
#define PS_TOP_SM_MASK                 (0x7FFFUL<<TOP_SM_SHT)

//EM_IP_BIST                //0x18010840
//EM_WARP_BIST              //0x18010844

//EM_CLK_PHASE_SEL          //0x18010848
#define PS_CCLK_OUT_SEL_SHT            (12)
#define PS_CCLK_OUT_SEL_MASK           (0x3FUL<<CCLK_OUT_SEL_SHT)
#define PS_CCLK_IN_SAMPLE_SEL_SHT      (6)
#define PS_CCLK_IN_SAMPLE_SEL_MASK     (0x3FUL<<CCLK_IN_SAMPLE_SEL_SHT)
#define PS_CCLK_IN_DRV_SEL_SHT         (0)
#define PS_CCLK_IN_DRV_SEL_MASK        (0x3FUL<<CCLK_IN_DRV_SEL_SHT)

//EM_DS_TUNE_CTRL           //0x18010850
#define PS_RD_DBG_MOD_SHT              (28)
#define PS_RD_DBG_MOD_MASK             (0xFUL<<RD_DBG_MOD_SHT)
#define PS_RTK_HS400                   _BIT23
#define PS_RTK_HS200_POS               _BIT22
#define PS_RTK_HS200                   _BIT21
#define PS_BYPASS_DS_TUNE              _BIT20
#define PS_BYPASS_DS_PH_SEL_SHT        (15)
#define PS_BYPASS_DS_PH_SEL_MASK       (0x1FUL<<BYPASS_DS_PH_SEL_SHT)
#define PS_RW_CNT_RESET                _BIT14
#define PS_WR_ADR_P_0_TRAN_SEL         _BIT13
#define PS_RW_CNT_REF_ALIGN_EN         _BIT12
#define PS_FW_SET_PLUSE                _BIT9
#define PS_DQSF_DLYN_SHT               (7)
#define PS_DQSF_DLYN_MASK              (0x03UL<<DQSF_DLYN_SHT)
#define PS_POS_TRIG_SEL_SHT            (5)
#define PS_POS_TRIG_SEL_MASK           (0x03UL<<POS_TRIG_SEL_SHT)
#define PS_PRE_TRIG_SEL_SHT            (3)
#define PS_PRE_TRIG_SEL_MASK           (0x03UL<<PRE_TRIG_SEL_SHT)
#define PS_SYNC_CAL_DLYN               _BIT2
#define PS_AUTO_CAL                    _BIT1
#define PS_DQS_DEL_OFFST_EN            _BIT0

//EM_DS_TUNE_CAL_DQ0_1      //0x18010854
#define PS_CAL_DQ1_NEG_DLYN_SHT        (24)
#define PS_CAL_DQ1_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ1_NEG_DLYN_SHT)
#define PS_CAL_DQ1_POS_DLYN_SHT        (16)
#define PS_CAL_DQ1_POS_DLYN_MASK       (0x3FUL<<CAL_DQ1_POS_DLYN_SHT)
#define PS_CAL_DQ0_NEG_DLYN_SHT        (8)
#define PS_CAL_DQ0_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ0_NEG_DLYN_SHT)
#define PS_CAL_DQ0_POS_DLYN_SHT        (0)
#define PS_CAL_DQ0_POS_DLYN_MASK       (0x3FUL<<CAL_DQ0_POS_DLYN_SHT)



//EM_DS_TUNE_CAL_DQ2_3      //0x18010858
#define PS_CAL_DQ3_NEG_DLYN_SHT        (24)
#define PS_CAL_DQ3_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ3_NEG_DLYN_SHT)
#define PS_CAL_DQ3_POS_DLYN_SHT        (16)
#define PS_CAL_DQ3_POS_DLYN_MASK       (0x3FUL<<CAL_DQ3_POS_DLYN_SHT)
#define PS_CAL_DQ2_NEG_DLYN_SHT        (8)
#define PS_CAL_DQ2_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ2_NEG_DLYN_SHT)
#define PS_CAL_DQ2_POS_DLYN_SHT        (0)
#define PS_CAL_DQ2_POS_DLYN_MASK       (0x3FUL<<CAL_DQ2_POS_DLYN_SHT)


//EM_DS_TUNE_CAL_DQ4_5      //0x1801085C
#define PS_CAL_DQ5_NEG_DLYN_SHT        (24)
#define PS_CAL_DQ5_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ5_NEG_DLYN_SHT)
#define PS_CAL_DQ5_POS_DLYN_SHT        (16)
#define PS_CAL_DQ5_POS_DLYN_MASK       (0x3FUL<<CAL_DQ5_POS_DLYN_SHT)
#define PS_CAL_DQ4_NEG_DLYN_SHT        (8)
#define PS_CAL_DQ4_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ4_NEG_DLYN_SHT)
#define PS_CAL_DQ4_POS_DLYN_SHT        (0)
#define PS_CAL_DQ4_POS_DLYN_MASK       (0x3FUL<<CAL_DQ4_POS_DLYN_SHT)


//EM_DS_TUNE_CAL_DQ6_7      //0x18010860
#define PS_CAL_DQ7_NEG_DLYN_SHT        (24)
#define PS_CAL_DQ7_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ7_NEG_DLYN_SHT)
#define PS_CAL_DQ7_POS_DLYN_SHT        (16)
#define PS_CAL_DQ7_POS_DLYN_MASK       (0x3FUL<<CAL_DQ7_POS_DLYN_SHT)
#define PS_CAL_DQ6_NEG_DLYN_SHT        (8)
#define PS_CAL_DQ6_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ6_NEG_DLYN_SHT)
#define PS_CAL_DQ6_POS_DLYN_SHT        (0)
#define PS_CAL_DQ6_POS_DLYN_MASK       (0x3FUL<<CAL_DQ6_POS_DLYN_SHT)


//EM_DS_TUNE_CAL_DQ8        //0x18010864
#define PS_CAL_DQ8_NEG_DLYN_SHT        (8)
#define PS_CAL_DQ8_NEG_DLYN_MASK       (0x3FUL<<CAL_DQ8_NEG_DLYN_SHT)
#define PS_CAL_DQ8_POS_DLYN_SHT        (0)
#define PS_CAL_DQ8_POS_DLYN_MASK       (0x3FUL<<CAL_DQ8_POS_DLYN_SHT)


//EM_DS_TUNE_PH_SEL_0_1     //0x18010868
#define PS_PH_SEL_DQ_NEG_1_SHT         (24)
#define PS_PH_SEL_DQ_NEG_1_MASK        (0x3FUL<<PH_SEL_DQ_NEG_1_SHT)
#define PS_PH_SEL_DQ_POS_1_SHT         (16)
#define PS_PH_SEL_DQ_POS_1_MASK        (0x3FUL<<PH_SEL_DQ_POS_1_SHT)
#define PS_PH_SEL_DQ_NEG_0_SHT         (8)
#define PS_PH_SEL_DQ_NEG_0_MASK        (0x3FUL<<PH_SEL_DQ_NEG_0_SHT)
#define PS_PH_SEL_DQ_POS_0_SHT         (0)
#define PS_PH_SEL_DQ_POS_0_MASK        (0x3FUL<<PH_SEL_DQ_POS_0_SHT)


//EM_DS_TUNE_PH_SEL_2_3     //0x1801086C
#define PS_PH_SEL_DQ_NEG_3_SHT         (24)
#define PS_PH_SEL_DQ_NEG_3_MASK        (0x3FUL<<PH_SEL_DQ_NEG_3_SHT)
#define PS_PH_SEL_DQ_POS_3_SHT         (16)
#define PS_PH_SEL_DQ_POS_3_MASK        (0x3FUL<<PH_SEL_DQ_POS_3_SHT)
#define PS_PH_SEL_DQ_NEG_2_SHT         (8)
#define PS_PH_SEL_DQ_NEG_2_MASK        (0x3FUL<<PH_SEL_DQ_NEG_2_SHT)
#define PS_PH_SEL_DQ_POS_2_SHT         (0)
#define PS_PH_SEL_DQ_POS_2_MASK        (0x3FUL<<PH_SEL_DQ_POS_2_SHT)


//EM_DS_TUNE_PH_SEL_4_5     //0x18010870
#define PS_PH_SEL_DQ_NEG_5_SHT         (24)
#define PS_PH_SEL_DQ_NEG_5_MASK        (0x3FUL<<PH_SEL_DQ_NEG_5_SHT)
#define PS_PH_SEL_DQ_POS_5_SHT         (16)
#define PS_PH_SEL_DQ_POS_5_MASK        (0x3FUL<<PH_SEL_DQ_POS_5_SHT)
#define PS_PH_SEL_DQ_NEG_4_SHT         (8)
#define PS_PH_SEL_DQ_NEG_4_MASK        (0x3FUL<<PH_SEL_DQ_NEG_4_SHT)
#define PS_PH_SEL_DQ_POS_4_SHT         (0)
#define PS_PH_SEL_DQ_POS_4_MASK        (0x3FUL<<PH_SEL_DQ_POS_4_SHT)


//EM_DS_TUNE_PH_SEL_6_7     //0x18011074
#define PS_PH_SEL_DQ_NEG_7_SHT         (24)
#define PS_PH_SEL_DQ_NEG_7_MASK        (0x3FUL<<PH_SEL_DQ_NEG_7_SHT)
#define PS_PH_SEL_DQ_POS_7_SHT         (16)
#define PS_PH_SEL_DQ_POS_7_MASK        (0x3FUL<<PH_SEL_DQ_POS_7_SHT)
#define PS_PH_SEL_DQ_NEG_6_SHT         (8)
#define PS_PH_SEL_DQ_NEG_6_MASK        (0x3FUL<<PH_SEL_DQ_NEG_6_SHT)
#define PS_PH_SEL_DQ_POS_6_SHT         (0)
#define PS_PH_SEL_DQ_POS_6_MASK        (0x3FUL<<PH_SEL_DQ_POS_6_SHT)

//EM_DS_TUNE_PH_SEL_8       //0x18011078
#define PS_RCV_1ST_DQ_PH_SEL_8_SHT     (16)
#define PS_RCV_1ST_DQ_PH_SEL_8_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_8_SHT)
#define PS_PH_SEL_DQ_NEG_8_SHT         (8)
#define PS_PH_SEL_DQ_NEG_8_MASK        (0x3FUL<<PH_SEL_DQ_NEG_8_SHT)
#define PS_PH_SEL_DQ_POS_8_SHT         (0)
#define PS_PH_SEL_DQ_POS_8_MASK        (0x3FUL<<PH_SEL_DQ_POS_8_SHT)

//EM_DS_TUNE_RCV_1ST        //0x1801107C
#define PS_RCV_1ST_DQ_PH_SEL_7_SHT     (28)
#define PS_RCV_1ST_DQ_PH_SEL_7_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_7_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_6_SHT     (24)
#define PS_RCV_1ST_DQ_PH_SEL_6_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_6_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_5_SHT     (20)
#define PS_RCV_1ST_DQ_PH_SEL_5_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_5_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_4_SHT     (16)
#define PS_RCV_1ST_DQ_PH_SEL_4_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_4_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_3_SHT     (12)
#define PS_RCV_1ST_DQ_PH_SEL_3_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_3_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_2_SHT     (8)
#define PS_RCV_1ST_DQ_PH_SEL_2_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_2_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_1_SHT     (4)
#define PS_RCV_1ST_DQ_PH_SEL_1_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_1_SHT)
#define PS_RCV_1ST_DQ_PH_SEL_0_SHT     (0)
#define PS_RCV_1ST_DQ_PH_SEL_0_MASK    (0xfUL<<RCV_1ST_DQ_PH_SEL_0_SHT)

//EM_CPMASK_0               //0x18011080
#define PS_CPMASK_SEL                  _BIT0

//EM_HALF_CYCLE_CAL_EN      //0x1801108C
#define PS_FW_MODE                     _BIT18
#define PS_HALH_CYCLE_CAL_SEL          _BIT17
#define PS_HALH_CYCLE_REF_THR_SHT      (9)
#define PS_HALH_CYCLE_REF_THR_MASK     (0x7FUL<<HALH_CYCLE_REF_THR_SHT)
#define PS_HALH_CYCLE_RES_THR_SHT      (3)
#define PS_HALH_CYCLE_RES_THR_MASK     (0x1FUL<<HALH_CYCLE_RES_THR_SHT)
#define PS_HALH_CYCLE_RES_MOD_SHT      (1)
#define PS_HALH_CYCLE_RES_MOD_MASK     (0x03UL<<HALH_CYCLE_RES_MOD_SHT)
#define PS_HALH_CYCLE_CAL_EN           _BIT0

//EM_HALF_CYCLE_CAL_RESULT  //0x18011090
#define PS_HALH_CYCLE_CAL_RESULT_SHT       (0)
#define PS_HALH_CYCLE_CAL_RESULT_MASK      (0x1FUL<<HALH_CYCLE_CAL_RESULT_SHT)

/* ====== DWC_Mobile_Storage ====== */

//EM_DWC_CTRL               //0x18011100
/* Control register defines  */
#define SDMMC_CTRL_USE_IDMAC		_BIT25
#define SDMMC_CTRL_OD_PULLUP_EN     _BIT24
#define SDMMC_CTRL_CARD_VOLT_B_SHT  (20)
#define SDMMC_CTRL_CARD_VOLT_B_MASK (0xfUL<<SDMMC_CTRL_CARD_VOLT_B_SHT)
#define SDMMC_CTRL_CARD_VOLT_A_SHT  (16)
#define SDMMC_CTRL_CARD_VOLT_A_MASK (0xfUL<<SDMMC_CTRL_CARD_VOLT_A_SHT)
#define SDMMC_CTRL_CEATA_INT_EN		_BIT11
#define SDMMC_CTRL_SEND_AS_CCSD		_BIT10
#define SDMMC_CTRL_SEND_CCSD		_BIT9
#define SDMMC_CTRL_ABRT_READ_DATA	_BIT8
#define SDMMC_CTRL_SEND_IRQ_RESP	_BIT7
#define SDMMC_CTRL_READ_WAIT		_BIT6
#define SDMMC_CTRL_DMA_ENABLE		_BIT5
#define SDMMC_CTRL_INT_ENABLE		_BIT4
#define SDMMC_CTRL_DMA_RESET		_BIT2
#define SDMMC_CTRL_FIFO_RESET		_BIT1
#define SDMMC_CTRL_RESET		    _BIT0


//EM_DWC_CLKDIV             //0x18011108
#define SDMMC_CLKDIV0_SHT           (0)
#define SDMMC_CLKDIV0_MASK          (0xffUL<<SDMMC_CLKDIV0_SHT )
#define SDMMC_CLKDIV0(val)          (((val) & SDMMC_CLKDIV0_MASK)>>SDMMC_CLKDIV0_SHT)
#define CLKDIV_NON                  0
#define CLKDIV_2                    1

//EM_DWC_CLKSRC             //0x1801110C
//EM_DWC_CLKENA             //0x18011110
/* Clock Enable register defines */
#define SDMMC_CLKEN_LOW_PWR_SHT     (16)
#define SDMMC_CLKEN_LOW_PWR_MASK    (0xFFFFUL<<SDMMC_CLKEN_LOW_PWR_SHT)
#define SDMMC_CLKEN_ENABLE_SHT 		(0)
#define SDMMC_CLKEN_ENABLE_MASK		(0xFFFFUL<<SDMMC_CLKEN_ENABLE_SHT)

//EM_DWC_TMOUT              //0x18011114
/* time-out register defines */
#define SDMMC_TMOUT_DATA_SHT        (8)
#define SDMMC_TMOUT_DATA_MASK		(0xFFFFFFUL<<SDMMC_TMOUT_DATA_SHT)
#define SDMMC_TMOUT_RESP_SHT        (0)
#define SDMMC_TMOUT_RESP_MASK		(0xFFUL<<SDMMC_TMOUT_RESP_SHT)

//EM_DWC_CTYPE              //0x18011118
/* card-type register defines */
#define SDMMC_CTYPE_8BIT_SHT		(16)
#define SDMMC_CTYPE_8BIT_MASK		(0xFFFFUL<<SDMMC_CTYPE_8BIT_SHT)
#define SDMMC_CTYPE_4BIT_SHT		(0)
#define SDMMC_CTYPE_4BIT_MASK		(0xFFFFUL<<SDMMC_CTYPE_4BIT_SHT)


//EM_DWC_BLKSIZ             //0x1801111C
//EM_DWC_BYTCNT             //0x18011120
//EM_DWC_INTMASK            //0x18011124
/* Interrupt status & mask register defines */
#define SDMMC_INT_SDIO(n)		(_BIT16+(n))
#define SDMMC_INT_EBE			_BIT15
#define SDMMC_INT_ACD			_BIT14
#define SDMMC_INT_SBE			_BIT13
#define SDMMC_INT_HLE			_BIT12
#define SDMMC_INT_FRUN			_BIT11
#define SDMMC_INT_HTO			_BIT10
#define SDMMC_INT_DTO			_BIT9
#define SDMMC_INT_RTO			_BIT8
#define SDMMC_INT_DCRC			_BIT7
#define SDMMC_INT_RCRC			_BIT6
#define SDMMC_INT_RXDR			_BIT5
#define SDMMC_INT_TXDR			_BIT4
#define SDMMC_INT_DATA_OVER		_BIT3
#define SDMMC_INT_CMD_DONE		_BIT2
#define SDMMC_INT_RESP_ERR		_BIT1
#define SDMMC_INT_CD			_BIT0
#define SDMMC_INT_ERROR			(0xbfc2)

//EM_DWC_CMDARG             //0x18011128
//EM_DWC_CMD                //0x1801112C
/* Command register defines */
#define SDMMC_CMD_START			_BIT31
#define SDMMC_CMD_USE_HREG		_BIT29
#define SDMMC_CMD_CCS_EXP		_BIT23
#define SDMMC_CMD_CEATA_RD		_BIT22
#define SDMMC_CMD_UPD_CLK		_BIT21
#define SDMMC_CMD_CARD_NUM_SHT  (16)
#define SDMMC_CMD_CARD_NUM_MASK (0x1FUL<<SDMMC_CMD_CARD_NUM_SHT)
#define SDMMC_CMD_CARD_NUM(val) (((n) & SDMMC_CMD_INDX_MASK)>>SDMMC_CMD_CARD_NUM_SHT)
#define SDMMC_CMD_INIT			_BIT15
#define SDMMC_CMD_STOP			_BIT14
#define SDMMC_CMD_PRV_DAT_WAIT  _BIT13
#define SDMMC_CMD_SEND_STOP		_BIT12
#define SDMMC_CMD_STRM_MODE		_BIT11
#define SDMMC_CMD_DAT_WR		_BIT10
#define SDMMC_CMD_DAT_EXP		_BIT9
#define SDMMC_CMD_RESP_CRC		_BIT8
#define SDMMC_CMD_RESP_LONG		_BIT7
#define SDMMC_CMD_RESP_EXP		_BIT6
#define SDMMC_CMD_INDX_SHT		(0)
#define SDMMC_CMD_INDX_MASK		(0x3FUL<<SDMMC_CMD_INDX_SHT)
#define SDMMC_CMD_INDX(n)		(((n) & SDMMC_CMD_INDX_MASK)>>SDMMC_CMD_INDX_SHT)

//EM_DWC_RESP0              //0x18011130
//EM_DWC_RESP1              //0x18011134
//EM_DWC_RESP2              //0x18011138
//EM_DWC_RESP3              //0x1801113C
//EM_DWC_MINTSTS            //0x18011140 To reference bits define at REG0x24
//EM_DWC_RINTSTS            //0x18011144
//EM_DWC_STATUS             //0x18011148
/* Status register defines */
#define SDMMC_DAT0_BUSY         _BIT9   //1: card busy; 0: card not busy;
#define SDMMC_GET_FCNT_SHT      (17)
#define SDMMC_GET_FCNT_MASK     (0x1FFFUL<<SDMMC_GET_FCNT_SHT)
#define SDMMC_GET_FCNT(x)		(((x)& SDMMC_GET_FCNT_MASK)>> SDMMC_GET_FCNT_SHT)

//EM_DWC_FIFOTH             //0x1801114C
#define SDMMC_MSIZE_SHT         (28)
#define SDMMC_MSIZE_MASK        (0x07UL<<SDMMC_MSIZE_SHT)
#define SDMMC_MSIZE(x)		    (((x)& SDMMC_MSIZE_MASK)>> SDMMC_MSIZE_SHT)
#define SDMMC_MSIZE_ROW(x)		((x)& SDMMC_MSIZE_MASK)
#define SDMMC_RX_WMARK_SHT      (16)
#define SDMMC_RX_WMARK_MASK     (0x7FFUL<<SDMMC_RX_WMARK_SHT)
#define SDMMC_RX_WMARK(x)	    (((x)& SDMMC_RX_WMARK_MASK)>> SDMMC_RX_WMARK_SHT)
#define SDMMC_RX_WMARK_ROW(x)   ((x)& SDMMC_RX_WMARK_MASK)
#define SDMMC_TX_WMARK_SHT      (0)
#define SDMMC_TX_WMARK_MASK     (0xFFFUL<<SDMMC_TX_WMARK_SHT)
#define SDMMC_TX_WMARK(x)	    (((x)& SDMMC_TX_WMARK_MASK)>> SDMMC_TX_WMARK_SHT)
#define SSDMMC_TX_WMARK_ROW(x)  ((x)& SDMMC_TX_WMARK_MASK)


//EM_DWC_CDETECT            //0x18011150
//EM_DWC_WRTPRT             //0x18011154
//EM_DWC_GPIO               //0x18011158
//EM_DWC_TCBCNT             //0x1801115C
//EM_DWC_TBBCNT             //0x18011160
//EM_DWC_DEBNCE             //0x18011164
//EM_DWC_USRID              //0x18011168
//EM_DWC_VERID              //0x1801116C
//EM_DWC_HCON               //0x18011170
//EM_DWC_UHS_REG            //0x18011174
//EM_DWC_RST_n              //0x18011178
//EM_DWC_BMOD               //0x18011180
#define SDMMC_DE            (_BIT7)
#define SDMMC_FB            (_BIT1)
#define SDMMC_SWR           (_BIT0)

//EM_DWC_PLDMND             //0x18011184
//EM_DWC_DBADDR             //0x18011188
//EM_DWC_DBADDRL64          //0x18011188
//EM_DWC_DBADDRU64          //0x1801118C
//EM_DWC_IDSTS              //0x1801118C
//EM_DWC_IDSTS64            //0x18011190
//EM_DWC_IDINTEN            //0x18011190
//EM_DWC_IDINTEN64          //0x18011194
/* Internal DMAC interrupt defines */
#define SDMMC_IDMAC_INT_AI		_BIT9
#define SDMMC_IDMAC_INT_NI		_BIT8
#define SDMMC_IDMAC_INT_CES		_BIT5
#define SDMMC_IDMAC_INT_DU		_BIT4
#define SDMMC_IDMAC_INT_FBE		_BIT2
#define SDMMC_IDMAC_INT_RI		_BIT1
#define SDMMC_IDMAC_INT_TI		_BIT0

//EM_DWC_DSCADDR            //0x18011194
//EM_DWC_DSCADDRL64         //0x18011198
//EM_DWC_DSCADDRU64         //0x1801119C
//EM_DWC_BUFADDR            //0x18011198
//EM_DWC_BUFADDRL64         //0x180111A0
//EM_DWC_BUFADDRU64         //0x180111A4
//EM_DWC_CardThrCtl         //0x18011200
//EM_DWC_Back_END_POWER     //0x18011204
//EM_DWC_UHS_REG_EXT        //0x18011208
//EM_DWC_EMMC_DDR_REG       //0x1801120C
//EM_DWC_ENABLE_SHIFT       //0x18011210
//EM_DWC_DATA_BASE          //0x18011300

/* Internal DMAC bus mode bits */
#define SDMMC_IDMAC_ENABLE		_BIT7
#define SDMMC_IDMAC_FB			_BIT1
#define SDMMC_IDMAC_SWRESET		_BIT0
/* Version ID register define */
#define SDMMC_GET_VERID(x)		((x) & 0xFFFF)

struct idmac_desc {
	unsigned int		des0;	/* Control Descriptor */
#define IDMAC_DES0_DIC	_BIT1
#define IDMAC_DES0_LD	_BIT2
#define IDMAC_DES0_FD	_BIT3
#define IDMAC_DES0_CH	_BIT4
#define IDMAC_DES0_ER	_BIT5
#define IDMAC_DES0_CES	_BIT30
#define IDMAC_DES0_OWN	_BIT31

	unsigned int		des1;	/* Buffer sizes */
#define IDMAC_SET_BUFFER1_SIZE(d, s) \
	((d)->des1 = ((d)->des1 & 0x03ffe000) | ((s) & 0x1fff))

	unsigned int		des2;	/* buffer 1 physical address */

	unsigned int		des3;	/* buffer 2 physical address */
};


#endif  //#define _MMC_P_REG_H_



