#ifndef __XHCI_PLAT_RTD289X_CONFIG_H__
#define __XHCI_PLAT_RTD289X_CONFIG_H__

#define U3_PHY_SETTING_REVISION     20160636

typedef struct {
    unsigned char  page;
    unsigned char  reg;
    unsigned short val;
}U3_PHY_REGISTER;

// USB3.0 Phy initial table

static U3_PHY_REGISTER xhci_u3_phy_config[] =
{
    { 0x0, 0x00, 0x4008 },     // ANA00
    { 0x0, 0x01, 0xa846 },     // ANA01
    { 0x0, 0x02, 0x6042 },     // ANA02
    { 0x0, 0x03, 0x27F1 },     // ANA03
    { 0x0, 0x04, 0xF2F5 },     // ANA04
    { 0x0, 0x05, 0xEAD7 },     // ANA05
    { 0x0, 0x06, 0x0006 },     // ANA06
    { 0x0, 0x07, 0x3210 },     // ANA07
    { 0x0, 0x08, 0x3590 },     // ANA08
    { 0x0, 0x09, 0x325C },     // ANA09
    { 0x0, 0x0A, 0x9642 },     // ANA0A /* (Auto mode) */
    { 0x0, 0x0B, 0xE909 },     // ANA0B
    { 0x0, 0x0C, 0xC000 },     // ANA0C
    { 0x0, 0x0D, 0xF510 },     // ANA0D  /* 0625 updated/// [5:2]=0100=91.7ohm. */
    { 0x0, 0x0E, 0x2010 },     // ANA0E
    { 0x0, 0x0F, 0x0e94 },     // ANA0F
    { 0x0, 0x10, 0x000C },     // DMR
    { 0x0, 0x11, 0x4C00 },     // BACR
    { 0x0, 0x12, 0xFC00 },     // IER
    { 0x0, 0x13, 0x0C81 },     // BCSR
    { 0x0, 0x14, 0xDE01 },     // BPR
    { 0x0, 0x15, 0x0000 },     // BPNR2
    { 0x0, 0x16, 0x0000 },     // BFNR
    { 0x0, 0x17, 0x0000 },     // BRNR2
    { 0x0, 0x18, 0x0000 },     // BENR
    { 0x0, 0x19, 0x1004 },     // REG_REV0  : bits[15:9] REG_FILTER_OUT
                               // modify   dr.save eq 9-->5
    { 0x0, 0x1A, 0x1260 },     // REG_REV1
    { 0x0, 0x1B, 0xFF0C },     // REG_REV2
	{ 0x0, 0x1C, 0xCB1C },     // REG_REV3
    { 0x0, 0x1D, 0xA03F },     // REG_FLD_0
    { 0x0, 0x1E, 0xC200 },     // REG_FLD_1
    { 0x0, 0x1F, 0x4803 },     // ANA1F
	{ 0x1, 0x00, 0xD47A },     // page1 0x00 --> xxxx20xx
    //{ 0x1, 0x00, 0xd47b },     // PAGE1_REG00 bit[3:0] : REG_TXDRV_DAC_DAT : Normal operation Amplitude control
                               // modify for team group a-->b
	{ 0x1, 0x01, 0x88AA },   //
    //{ 0x1, 0x01, 0xa8aa },     // PAGE1_REG01 bit[15:12] : Normal operation Amplitude control
                               // PAGE1_REG01 bit[11: 8] : Beacon LFPS Amplitude Control deamphasis--> 8-->a (dr.save)
                               // PAGE1_REG01 bit[ 7: 4] : Normal operation Amplitude control
                               // PAGE1_REG01 bit[ 3: 0] : Beacon LFPS Amplitude Control deamphasis

    { 0x1, 0x02, 0x0053 },     //
    { 0x1, 0x03, 0xDB64 },     // 0625 updated///0x23[15:12]=1101= 89.5ohm
    { 0x1, 0x04, 0x0800 },     // 0719 modify bit 15=1,U1/U2/U3 can enter.
    { 0x1, 0x05, 0x8000 },     //
    { 0x1, 0x06, 0x046A },     //
    { 0x1, 0x07, 0x01D6 },     //

    //{ 0x1, 0x08, 0xF902 },   // PAGE1_REG08 bit[15:11] REG_EQ_UPPER_LIMIT,
                               // PAGE1_REG08 bit[10:6] REG_EQOUT_OFFSET,
                               // PAGE1_REG08 bit[4:0] REG_TIMER_EQ
    { 0x1, 0x08, 0xf802 },     //

    { 0x1, 0x09, 0x3080 },     //
    { 0x1, 0x0A, 0x3083 },     //
    { 0x1, 0x0B, 0x2038 },     //
    { 0x1, 0x0C, 0xFFFF },     //
    { 0x1, 0x0D, 0xFFFF },     //
    { 0x1, 0x0E, 0x0000 },     //
    { 0x1, 0x0F, 0x0040 },     //
    { 0x1, 0x10, 0x0000 },
    { 0x1, 0x11, 0x77bf },     //cc pin 定義開始//cc1_mode = 1,1 for 3A //
    { 0x1, 0x12, 0x6e2f },     //0804 modify cc1 Rp 4.7K  [9:5]=10001
    { 0x1, 0x13, 0x7777 },
    { 0x1, 0x14, 0x0002 },     //disable cc1_Rp_4.7k and disable cc1_detect and select rx1, but disable EN_Switch. // 0804 modify cc1 threshold voltage bit [2:0]=010
    { 0x1, 0x15, 0x77bf },     //cc2_mode = 1,1  for 3A
    { 0x1, 0x16, 0x6e2f },     //0804 modify cc2 Rp 4.7K  [9:5]=10001
    { 0x1, 0x17, 0x7777 },
    { 0x1, 0x18, 0x0002 },     //disable cc2_Rp_4.7k and enable cc2_detect and select tx1.  // 0804 modify cc2 threshold voltage bit [2:0]=010
};

#define U3_PHY_SETTING_SIZE      (sizeof(xhci_u3_phy_config) / sizeof(unsigned long))


/////////////////////////////////////////////////////////////////
// U2 Phy Setting
/////////////////////////////////////////////////////////////////

typedef struct {
	unsigned char page;
	unsigned char addr;
}U2_PHY_REG;

U2_PHY_REG u2_phy_reg_table[] =
{
	{0, 0xE0},
	{0, 0xE1},
	{0, 0xE2},
	{0, 0xE3},
	{0, 0xE4},
	{0, 0xE5},
	{0, 0xE6},
	{0, 0xE7},
	{1, 0xE0},
	{1, 0xE1},
	{1, 0xE2},
	{1, 0xE3},
	{1, 0xE4},
	{1, 0xE5},
	{1, 0xE6},
	{1, 0xE7},
	{0, 0xF0},
	{0, 0xF1},
	{0, 0xF2},
	{0, 0xF3},
	{0, 0xF4},
	{0, 0xF5},
	{0, 0xF6},
	{0, 0xF7},
};



typedef struct {
    unsigned char addr;
    unsigned char val;
}U2_PHY_REGISTER;


/////////////////////////////////////////////
// for port 1
U2_PHY_REGISTER u2_phy_setting_1[] =
{
    {0xF4, 0xbb},   // zap to page1
    {0XE5, 0x00},   // E5 Page 1 = 0
    {0xE6, 0x40},   // E6 Page 1 = 40
    {0xE7, 0x00},   // E7 Page 1 = 00
    {0xF4, 0x9b},   // zap to page0   // zap to page0
    {0xE0, 0x0f},   // E0 Page 0 = 63
    {0xE1, 0x18},
    {0xE2, 0x4D},
    {0xE3, 0xcd},
    {0xE4, 0x6b},   // disconnect  stage 1 =6
    {0xE7, 0x41},
    {0xF4, 0xbb},   // zap to page1
    {0xE0, 0x23},
    //{0xE0, 0x27},
    {0xF4, 0x9b},   // zap to page0
    {0xE4, 0x7c},   // bit[7:4] disconnt level,bit[3:0]=swing
    {0xE7, 0xa1},   // bit[7:4] device disconnt level
    {0XE5, 0x11},
    {0xE6, 0x01},   // 0727 Modify 0xe6 bit7=0 for enable LPF in bandgap
    {0xF0, 0xfc},
    {0xF1, 0x88},
    {0xF2, 0x00},
    {0xF3, 0x11},
    {0xF6, 0x01},
    {0xF7, 0x0a},
    {0xF4, 0xbb},   // zap to page1
    {0xE1, 0x70},
    {0xE2, 0x00},
    {0xF4, 0x9b},   // zap to page0
};


/////////////////////////////////////////////
// for port 2
U2_PHY_REGISTER u2_phy_setting_2[] =
{
    {0xF4, 0xbb},   // zap to page1
    {0XE5, 0x0f},   /* only for port : Division-ratio control of PLL driver */
    {0xE6, 0x58},
    {0xE7, 0xe3},
    {0xF4, 0x9b},   // zap to page0
    {0xE0, 0x0f},       // Page0 E0 : only for port 2
    {0xE1, 0x18},       // Page0 E1
    {0xE2, 0x4d},       // Page0 E2
    {0xE3, 0xcd},       // Page0 E3
    {0xE4, 0x6a},       // Page0 E4  ///disconnect  stage 1 =6
    {0xE7, 0x41},       // Page0 E7
    {0xF4, 0xbb},   // zap to page1
    {0xE0, 0x23},       // Page1 E0
 //   {0xE0, 0x27},       // Page1 E2
    {0xF4, 0x9b},   // zap to page0
    {0xE4, 0x7c},       // Page0 9B  ////bit[7:4] disconnt level,bit[3:0]=swing
    {0xE7, 0xa1},     // bit[7:4] device disconnt level
    {0XE5, 0x11},
    {0xE6, 0x01},     // 0727 Modify 0xe6 bit7=0 for enable LPF in bandgap
    {0xF0, 0xfc},
    {0xF1, 0x88},
    {0xF2, 0x00},
    {0xF3, 0x11},
    {0xF6, 0x01},
    {0xF7, 0x0a},
    {0xF4, 0xbb},     // zap to page1
    {0xE1, 0x70},
    {0xE2, 0x00},
    {0xF4, 0x9b},     // zap to page0
};

/////////////////////////////////////////////
// for port 3
U2_PHY_REGISTER u2_phy_setting_3[] =
{
    {0xF4, 0xbb},     // zap to page1
    {0XE5, 0x00},
    {0xE6, 0x40},
    {0xE7, 0x00},
    {0xF4, 0x9b},     // zap to page0
    {0xE0, 0x0f},
    {0xE1, 0x18},
    {0xE2, 0x4d},
    {0xE3, 0xcd},
    {0xE4, 0x6b},    // disconnect  stage 1 =6
    {0xE7, 0x41},
    {0xF4, 0xbb},     // zap to page1
    {0xE0, 0x23},
//    {0xE0, 0x27},
    {0xF4, 0x9b},     // zap to page0
    {0xE4, 0x7c},     //bit[7:4] disconnt level,bit[3:0]=swing
    {0xE7, 0xa1},     // bit[7:4] device disconnt level
    {0XE5, 0x11},
    {0xE6, 0x01},     // 0727 Modify 0xe6 bit7=0 for enable LPF in bandgap
    {0xF0, 0xfc},
    {0xF1, 0x88},
    {0xF2, 0x00},
    {0xF3, 0x11},
    {0xF6, 0x01},
    {0xF7, 0x0a},
    {0xF4, 0xbb},     // zap to page1
    {0xE1, 0x70},
    {0xE2, 0x00},
    {0xF4, 0x9b},     // zap to page0
};


/////////////////////////////////////////////
// for port 4
U2_PHY_REGISTER u2_phy_setting_4[] =
{
    {0xF4, 0xbb},     // zap to page1
    {0XE5, 0x00},
    {0xE6, 0x40},
    {0xE7, 0x00},
    {0xF4, 0x9b},     // zap to page0
    {0xE0, 0x0f},
    {0xE1, 0x18},
    {0xE2, 0x4d},
    {0xE3, 0xcd},
    {0xE4, 0x69},    // disconnect  stage 1 =6
    {0xE7, 0x41},
    {0xF4, 0xbb},     // zap to page1
    {0xE0, 0x23},
//    {0xE0, 0x27},
    {0xF4, 0x9b},     // zap to page0
    {0xE4, 0x7c},     //bit[7:4] disconnt level,bit[3:0]=swing
    {0xE7, 0xa1},     // bit[7:4] device disconnt level
    {0XE5, 0x11},
    {0xE6, 0x01},     // 0727 Modify 0xe6 bit7=0 for enable LPF in bandgap
    {0xF0, 0xfc},
    {0xF1, 0x88},
    {0xF2, 0x00},
    {0xF3, 0x11},
    {0xF6, 0x01},
    {0xF7, 0x0a},
    {0xF4, 0xbb},     // zap to page1
    {0xE1, 0x70},
    {0xE2, 0x00},
    {0xF4, 0x9b},     // zap to page0
};


typedef struct {
    U2_PHY_REGISTER* p_reg_table;
    unsigned int     n_reg;
}U2_PHY_CONFIG;


U2_PHY_CONFIG u2_phy_config[] =
{
    {
        u2_phy_setting_1,
        sizeof(u2_phy_setting_1) / sizeof(U2_PHY_REGISTER),
    },
    {
        u2_phy_setting_2,
        sizeof(u2_phy_setting_2) / sizeof(U2_PHY_REGISTER),
    },
    {
        u2_phy_setting_3,
        sizeof(u2_phy_setting_3) / sizeof(U2_PHY_REGISTER),
    },
    {
        u2_phy_setting_4,
        sizeof(u2_phy_setting_4) / sizeof(U2_PHY_REGISTER),
    },
};

#define U2_PHY_CONFIG_COUNT         (sizeof(u2_phy_config)/sizeof(U2_PHY_CONFIG))

////////////////////////////////////////////////////////////////////
// XHCI Config file
////////////////////////////////////////////////////////////////////

typedef enum {
	XHCI_U2_PORT1 = 0,
	XHCI_U2_PORT2,
	XHCI_U2_PORT3,
	XHCI_U2_PORT4,
	XHCI_U3_PORT,
	XHCI_MAX_PORT,
}XHCI_PORT_ID;

typedef struct 
{		
	u32 enable:1; 		// 0 : disabled, 1 : enabled
	u32 polarity:1; 	// 0: negative active, 1 : postive active
	RTK_GPIO_ID gid;
}XHCI_PORT_GPIO;

typedef struct 
{			
	XHCI_PORT_GPIO   vbus;	// for VBus control
	XHCI_PORT_GPIO   ocd;	// for OCD control
}XHCI_PORT_GPIO_CONFIG;

typedef struct 
{	
	u32 u3_port_disabled:1;
	u32 type_c_en:1;
	u32 company_u2_port:4;
	u32 reserved:26;	
	XHCI_PORT_GPIO_CONFIG port_config[XHCI_MAX_PORT];
}XHCI_RTD289X_CONFIG;

#define XHCI_SET_PORT_GPIO(gpio, en, pol, type, gpio_id)		do {  \
																	gpio.enable = en; \
																	gpio.polarity = pol; \
																	gpio.gid = rtk_gpio_id(type, gpio_id);	\
																} while(0)
#define XHCI_SET_PORT_VBUS_CFG(pcfg, en, pol, type, gpio_id)	XHCI_SET_PORT_GPIO(pcfg.vbus, en, pol, type, gpio_id)
#define XHCI_SET_PORT_OCD_CFG(pcfg, en, pol, type, gpio_id)		XHCI_SET_PORT_GPIO(pcfg.ocd,  en, pol, type, gpio_id)

static unsigned long u2_portsc_regs[] =
{
	0xb8050420,
	0xb8050430,
	0xb8050440,
	0xb8050450,
};

#endif // __XHCI_PLAT_RTD289X_CONFIG_H__
