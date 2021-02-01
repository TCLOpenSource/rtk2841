#include "ir_input.h"
#include "irrc_common.h"

// this is for android o
#if defined(CONFIG_RTK_KDRV_IR_SUPPORT_ANDROID_O)
int ir_is_upload_more_key = 1;
#else
int ir_is_upload_more_key = 0;
#endif
#if defined(CONFIG_RTK_KDRV_TV030_IR)
#define EV_KEY_TCL               0x19
#define FACTORY_KEY_TIMEOUT     100
eirda_report_mode ir_report_mode = IRDA_REPORT_MODE_TCL;
static int custom_code_tcl             = 0;
static int factory_prekeycode          = 0;
static int factory_precustomer_code    = 0;
static unsigned long factory_key_curtime = 0;
static unsigned long factory_key_pretime = 0;
#else
eirda_report_mode ir_report_mode = IRDA_REPORT_MODE_NORMAL;
#endif

static struct timer_list keyup_timer;
static unsigned long keyup_jiffies = 0;
unsigned int ir_to_mouse = 0;
unsigned int ir_poll_interval = 130;
extern int ir_mute_flag;
extern unsigned int repeat_event;
extern unsigned int rawkey_event;
unsigned int ir_poll_enable = 1;
extern eirda_report_mode ir_report_mode;
sirda_report_mode ir_report_mode_list[IRDA_REPORT_MODE_MAX] = {
        {IRDA_REPORT_MODE_NORMAL,       "normal"},
        {IRDA_REPORT_MODE_TCL,          "tcl"},
};

static struct venus_ir_data *data = NULL;
static bool bUseUserTable = false;

IR_Keycode_List intercept_keycode_list;

int ir_add_keycode_to_list(IR_Keycode_List *p_keycode_list, u32 keycode, u32 flags)
{
    int ret = 0;
    u32 i = 0;
    if(!p_keycode_list || keycode == 0)
        return ret;
    write_lock(&p_keycode_list->lock);
    if(p_keycode_list->keycode_num < MAX_KEYCODE_ARRY_NUM) {
        for(i = 0; i < p_keycode_list->keycode_num; i++) {
            if(p_keycode_list->keycode_array[i][0] == keycode)
                break;
        }
        if(i == p_keycode_list->keycode_num) {
            p_keycode_list->keycode_array[p_keycode_list->keycode_num][0] = keycode;
            p_keycode_list->keycode_array[p_keycode_list->keycode_num][1] = flags;
            p_keycode_list->keycode_num++;
            ret = 1;  
        }
    }
    if(p_keycode_list->keycode_num > 0)
        p_keycode_list->keycode_array_not_empty = 1;
    write_unlock(&p_keycode_list->lock);
    return ret;
}

int ir_remove_keycode_from_list(IR_Keycode_List *p_keycode_list, u32 keycode)
{
    u32 i = 0;
    if(!p_keycode_list || keycode == 0)
        return 1;
    write_lock(&p_keycode_list->lock);
    for(i = 0; i < p_keycode_list->keycode_num; i++) {
        if(p_keycode_list->keycode_array[i][0] == keycode)
            break;
    }
    if(i < p_keycode_list->keycode_num) {
        for(; i < p_keycode_list->keycode_num - 1; i++) {
            p_keycode_list->keycode_array[i][0] = 
                        p_keycode_list->keycode_array[i + 1][0];
            p_keycode_list->keycode_array[i][1] = 
                        p_keycode_list->keycode_array[i + 1][1];            
        }
        p_keycode_list->keycode_num--;
    }
    if(p_keycode_list->keycode_num == 0)
        p_keycode_list->keycode_array_not_empty = 0;
    write_unlock(&p_keycode_list->lock);
    return 1;
}

int ir_query_keycode_from_list(IR_Keycode_List *p_keycode_list, u32 keycode, u32 *flags) 
{
    int ret = 0;
    u32 i = 0;
    if(!p_keycode_list || keycode == 0)
        return ret;
    read_lock(&p_keycode_list->lock);
    if(p_keycode_list->keycode_num > 0) {
        for(i = 0; i < p_keycode_list->keycode_num; i++) {
            if(p_keycode_list->keycode_array[i][0] == keycode) {
                if(flags)
                    *flags = p_keycode_list->keycode_array[i][1];
                ret = 1;
                break;
            }
        }
    }
    read_unlock(&p_keycode_list->lock);    
    return ret;
}

void ir_send_intercept_key_event(struct input_dev *input_dev, u32 keycode)
{
    char event[64] = {0};
    char *envp[2] = {NULL, NULL};
    
    if(input_dev == NULL)
        return;
        
    snprintf(event, sizeof(event), "intercept_keycode=%x", keycode);
    envp[0]= event;
    envp[1] = NULL;
    kobject_uevent_env(&input_dev->dev.kobj, KOBJ_CHANGE, envp);
}

static void ir_intercept_keycode_work(struct work_struct *work)
{
    ir_send_intercept_key_event(data->input_dev, data->keycode);
}

extern void ir_decode_key_on_off(bool on) ;

static void venus_ir_key_disable_timer_func(unsigned long _data)
{
    ir_decode_key_on_off(ON);
}


struct user_key_data {
    struct venus_key_table key_table;
    unsigned int max_size;
};
static void _venus_ir_get_user_data(uint32_t, struct user_key_data **, u32 *);
static void _venus_ir_clean_user_keys(struct user_key_data *);
static int _venus_ir_setkeycode(struct input_dev *, unsigned int, unsigned int);
static int _venus_ir_getkeycode(struct input_dev *, unsigned int, unsigned int *);
const char* ir_core_get_cur_remote_control_name(void);

#ifdef CONFIG_RTK_KDRV_TV030_IR //TCL
#define FactoryCustomerCodeMax      10
static unsigned int factory_customer_code_map[FactoryCustomerCodeMax] =
{
    5, 6, 7, 8, 9, 11, 12, 13, 14, 15
};
int is_factory_customer_code(unsigned int customer_code)
{
    int i = 0;
    for(i = 0 ; i < FactoryCustomerCodeMax; i ++){
        if(factory_customer_code_map[i] == customer_code)
            break;
    }
    if(i >= FactoryCustomerCodeMax){
        return 0;
    }else{
        return 1;
    }
}
unsigned long _IR_Input_GetSystemTime(void)
{
    return((unsigned long)((jiffies)*(1000/HZ)));
}
static struct venus_key tcl_tv_keys[] = {

    //{0x00, KEY_CARD_READER},  // CMD_CARD_READER
    { 0x0c, KEY_AV1},  // AV1
    { 0x0d, KEY_AV2},  // AV2
    { 0x01, KEY_ZOOMOUT},    // CMD_FAVCH
    //{0x04, KEY_FREEZE},   // CMD_FREEZE
    //{0x05, KEY_ROI},  // CMD_ROI
    //{0x08, KEY_TOOLS},    // CMD_TOOLS
    { 0x0b, KEY_ENTER},  // CMD_ENTER 
    { 0x10, KEY_NETFLIX},  // CMD_ENTER 
    { 0x12, KEY_GLOBO_PLAY},   // CMD_MENU
    { 0x13, KEY_MENU},   // CMD_MENU
    // #ifndef VENDOR_EDIT
    // zihua.bu@tcl.com, 2020/8/10
    // zihua.bu@tcl.com, 2020/10/20
    // zihua.bu@tcl.com, 2020/11/27, add STAN key
    { 0x3e, KEY_PRIMEVIDEO}, //PrimeVideo
    { 0x14, KEY_IQIYI},  //IQIYI
    { 0x77, KEY_ZEE}, //ZEE
    { 0x73, KEY_STAN}, //STAN
    // #endif /* VENDOR_EDIT */
    //{0x16, KEY_AUDIO},
    //{0x17, KEY_VIDEO},
    { 0x17, KEY_GREEN},  // CMD_OPTION_GREEN
    { 0x19, KEY_GLOBAL_PLAY},//GLOBAL_PLAY
    //{0x1a, KEY_WIDE}, // CMD_WIDE
    { 0x1b, KEY_YELLOW}, // CMD_OPTION_YELLOW
    { 0x1c, KEY_QUICK_MENU},//QUICK_MENU
	{ 0x1d, KEY_YOUTUBE},
    { 0x20, KEY_LANG },
    { 0x21, KEY_LAST_CHANNEL},
    { 0x27, KEY_BLUE},   // CMD_OPTION_BLUE   
    { 0x30, KEY_SET},//set
	{ 0x32, KEY_NUMBER},
    { 0x45, KEY_NETFLIX_FORWARD},  // CMD_POP
	{ 0x46, KEY_TV_ON}, 
	{ 0x47, KEY_TV_OFF}, 
	{ 0x48, KEY_HDMI_1}, 
	{ 0x49, KEY_HDMI2}, 
	{ 0x4a, KEY_HDMI3}, 
	{ 0x4b, KEY_HDMI4}, 
	{ 0x4c, KEY_CMP}, 
	{ 0x4d, KEY_VGA}, 
	{ 0xF1, KEY_APP_CAREVISION}, //APP_CAREVISION
	{ 0x55, KEY_TCL_TUNER},  

    { 0x5c, KEY_TV_INPUT}, //CMD_SOURCE
    //{0x5d, KEY_CHANNEL_DEC},  // CMD_CHANNEL_DEC
	{ 0x60, KEY_ALL_APP}, 
	{ 0x61, KEY_ZOOMIN}, 
   { 0x62, KEY_MENU},//menu
   { 0x66, KEY_MTS },//mts
   { 0x67, KEY_3D_MODE}, //3D_MODE
   { 0x6c, KEY_RC_DOT}, //3D_MODE
    { 0x6f, KEY_ZOOM },       // (C)ASPECT RATIO
    // #ifndef VENDOR_EDIT
    // zihua.bu@tcl.com, 2020/9/15, add FPT
    { 0x78, KEY_FPTPLAYER},
    // #endif /* VENDOR_EDIT */
    { 0x7f, KEY_SUBTITLE},//tcl

    { 0x9e, KEY_LIST},
    { 0xa0, KEY_RF_LINK_S },
    { 0xa3, KEY_RC_RF_UNCONNECT },
    { 0xa5, KEY_AUDIO },      // (C)SOUND_MODE
    { 0xa6, KEY_UP},
    { 0xa7, KEY_DOWN},
    { 0xa8, KEY_RIGHT},
    { 0xa9, KEY_LEFT},
    { 0xaa, KEY_RF_LINK_F},
   { 0xab, KEY_RF_LINK_STOP},
   { 0xac, KEY_NETFLIX_NEXT},
    { 0xc0, KEY_MUTE},//tcl
    { 0xc3, KEY_REPLY},    // CMD_DISPLAY tcl
    { 0xc5, KEY_TV},//tv
    { 0xc6, KEY_9},
    { 0xc7, KEY_8},
    { 0xc8, KEY_7},
    { 0xc9, KEY_6},
    { 0xca, KEY_5},
    { 0xcb, KEY_4},
    { 0xcc, KEY_3},
    { 0xcd, KEY_2},
    { 0xce, KEY_1},
    { 0xcf, KEY_0},
    { 0xd0, KEY_VOLUMEUP},   // CMD_VOL_UP
    //{0xd1, KEY_DELETE},
    { 0xd1, KEY_VOLUMEDOWN},     // CMD_VOL_DOWN
    { 0xd2, KEY_CHANNELUP},
    { 0xd3, KEY_CHANNELDOWN},
    { 0xd5, KEY_POWER},
    { 0xd8, KEY_BACK},
    { 0xe0, KEY_NETFLIX_STOP},
    { 0xe1, KEY_TEXT },
    { 0xe2, KEY_NETFLIX_FB},    
    { 0xe3, KEY_NETFLIX_FF},
    { 0xe5, KEY_EPG},    // CMD_EPG
	{ 0xe6, KEY_PAUSECD},    
	{ 0xe8, KEY_MEDIA_RECORD},    
    { 0xea, KEY_MEDIA_PLAY},
    { 0xed, KEY_PICTURE },     // (C)PICTURE_MODE
    { 0xf1, KEY_APP_CAREVISION},  // AV1
    { 0xf3, KEY_FN_F1 },      // APP_CAREVISION
    { 0xf7, KEY_HOME},   // CMD_GUIDE tcl
    { 0xf8, KEY_SLEEP},
    { 0xf9, KEY_EXIT},
    { 0xfd, KEY_USB_MEDIA},      // (C)USB
    { 0xff, KEY_RED},    // CMD_OPTION_RED

};
static struct  venus_key_table tcl_tv_key_table = {
    .keys = tcl_tv_keys,
    .size = ARRAY_SIZE(tcl_tv_keys),
};

static struct  venus_key tcl_tv_factory_keys[] = {
    {0x17,0x17},
    {0x16,0x16},
    {0x01,0x01},
    {0x02,0x02},
    {0x07,0x07},
    {0x08,0x08},
    {0x09,0x09},
    {0x0a,0x0a},
    {0x0b,0x0b},
    {0x05,0x05},
    {0x06,0x06},
    {0x0c,0x0c},
    {0x2d,0x2d},
    {0x3f,0x3f},
    {0x14,0x14},
    {0x15,0x15},
    {0x1d,0x1d},
    {0x18,0x18},
    {0x19,0x19},
    {0x3d,0x3d},
    {0x3e,0x3e},
    {0x14,0x14},
    {0x0d,0x0d},
    {0x12,0x12},
    {0x13,0x13},
    {0x1a,0x1a},
    {0x1b,0x1b},
    {0x16,0x16},
    {0x17,0x17},
    {0x47,0x47},
    {0x48,0x48},
    {0x29,0x29},
    {0x60,0x60},
    {0x61,0x61},
    {0x20,0x20},
    {0x2e,0x2e},
    {0x7f,0x7f},
    {0x28,0x28},
    {0x32,0x32},
    {0x33,0x33},
    {0x50,0x50},
    {0x51,0x51},
    {0x2f,0x2f},
    {0x4d,0x4d},
    {0x4f,0x4f},
};
static struct venus_key_table tcl_tv_factory_key_table = {
    .keys = tcl_tv_factory_keys,
    .size = ARRAY_SIZE(tcl_tv_factory_keys),
};
static struct  venus_key tcl_dvd_keys[] = {
    {0x639c7881, KEY_POWER},
    {0x7f807881, KEY_VOLUMEUP},
    {0x77887881, KEY_VOLUMEDOWN},
    {0x35ca7881, KEY_MUTE},
    {0xe7187881, KEY_POWER},
    {0xed127881, KEY_VOLUMEUP},
    {0xec137881, KEY_VOLUMEDOWN},
    {0xe6197881, KEY_MUTE},
    {0x7f808877, KEY_POWER},
    {0x6e918877, KEY_VOLUMEUP},
    {0x6d928877, KEY_VOLUMEDOWN},
    {0x7e818877, KEY_MUTE},
    {0xe817ac53, KEY_POWER},
    {0xed12ac53, KEY_VOLUMEUP},
    {0xea15ac53, KEY_VOLUMEDOWN},
    {0xe41bac53, KEY_MUTE},
    {0xe817af50, KEY_POWER},
    {0xed12af50, KEY_VOLUMEUP},
    {0xea15af50, KEY_VOLUMEDOWN},
    {0xf40baf50, KEY_MUTE},
    {0xef101645, KEY_POWER},
    {0xdf201645, KEY_VOLUMEUP},
    {0xde211645, KEY_VOLUMEDOWN},
    {0xe01f1645, KEY_MUTE},
    {0xf7080240, KEY_POWER},
    {0xfd020240, KEY_VOLUMEUP},
    {0xfc030240, KEY_VOLUMEDOWN},
    {0xf6090240, KEY_MUTE},
    {0xed12c738, KEY_POWER},
    {0xf10ec738, KEY_VOLUMEUP},
    {0xf00fc738, KEY_VOLUMEDOWN},
    {0xe718c738, KEY_MUTE},
    {0xf50ae31c, KEY_POWER},
    {0xa35ce31c, KEY_VOLUMEUP},
    {0xa25de31c, KEY_VOLUMEDOWN},
    {0xf40be31c, KEY_MUTE},
    {0xf708e718, KEY_POWER},
    {0xfd02e718, KEY_VOLUMEUP},
    {0xfc03e718, KEY_VOLUMEDOWN},
    {0xf609e718, KEY_MUTE},
    {0xeb140e0e, KEY_POWER},
    {0xed120e0e, KEY_VOLUMEUP},
    {0xec130e0e, KEY_VOLUMEDOWN},
    {0xea150e0e, KEY_MUTE},
    {0x28d7f708, KEY_POWER},
    {0x7c83f708, KEY_VOLUMEUP},
    {0x7986f708, KEY_VOLUMEDOWN},
    {0x20dff708, KEY_MUTE},
    {0xf00f0808, KEY_POWER},
    {0xf30c0808, KEY_VOLUMEUP},
    {0xf20d0808, KEY_VOLUMEDOWN},
    {0xf10e0808, KEY_MUTE},
    {0xfd020707, KEY_POWER},
    {0xf8070707, KEY_VOLUMEUP},
    {0xf40b0707, KEY_VOLUMEDOWN},
    {0xf00f0707, KEY_MUTE},
    {0xf00f0606, KEY_POWER},
    {0xf30c0606, KEY_VOLUMEUP},
    {0xf20d0606, KEY_VOLUMEDOWN},
    {0xf10e0606, KEY_MUTE},
    {0xfd020505, KEY_POWER},
    {0xf8070505, KEY_VOLUMEUP},
    {0xf40b0505, KEY_VOLUMEDOWN},
    {0xf00f0505, KEY_MUTE},
    {0xf708fb04, KEY_POWER},
    {0xfd02fb04, KEY_VOLUMEUP},
    {0xfc03fb04, KEY_VOLUMEDOWN},
    {0xf609fb04, KEY_MUTE},
    {0xf00f1004, KEY_POWER},
    {0xf30c1004, KEY_VOLUMEUP},
    {0xf20d1004, KEY_VOLUMEDOWN},
    {0xf10e1004, KEY_MUTE},
    {0xee11fc03, KEY_POWER},
    {0xac53fc03, KEY_VOLUMEUP},
    {0xa857fc03, KEY_VOLUMEDOWN},
    {0xb748fc03, KEY_VOLUMEUP},
    {0xb24dfc03, KEY_VOLUMEDOWN},
    {0xec13fc03, KEY_MUTE},
};
static struct venus_key_table tcl_tv_dvd_key_table = {
    .keys = tcl_dvd_keys,
    .size = ARRAY_SIZE(tcl_dvd_keys),
};
#endif

static struct venus_key rtk_mk5_tv_keys[] = {
    {0x12, KEY_POWER},
    {0x11, KEY_EJECTCD},    // CMD_EJECT
    {0x10, KEY_1},
    {0x5B, KEY_2},
    {0x59, KEY_3},
    {0x1B, KEY_TV}, // CMD_SOURCE
    {0x18, KEY_4},
    {0x5A, KEY_5},
    {0x58, KEY_6},
    {0x1A, KEY_EPG},
    {0x14, KEY_7},
    {0x56, KEY_8},
    {0x54, KEY_9},
    {0x19, KEY_RECORD}, // CMD_FORCE_RECORD
    {0x57, KEY_SEARCH}, //widget
    {0x55, KEY_0},
    {0x17, KEY_ZOOM},
    //{0x15, KEY_FORCE_TIMESHIFT},  //CMD_FORCE_TIMESHIFT
    {0x4F, KEY_MENU},   // CMD_GUIDE
    {0x4D, KEY_UP},
    {0x16, KEY_BACK},   // CMD_RETURN
    {0x0C, KEY_LEFT},
    {0x4C, KEY_INSERT},
    {0x0E, KEY_RIGHT},
    {0x08, KEY_MENU},
    {0x48, KEY_DOWN},
    //{0x09, KEY_DISPLAY},  // CMD_DISPLAY
    {0x4B, KEY_REWIND}, // CMD_FRWD
    {0x49, KEY_PLAY},
    {0x0B, KEY_STOP},
    {0x0A, KEY_FASTFORWARD},    // CMD_FFWD
    {0x47, KEY_PREVIOUS},   // CMD_PREV
    {0x45, KEY_VOLUMEDOWN},     // CMD_VOL_DOWN
    {0x07, KEY_VOLUMEUP},   // CMD_VOL_UP
    {0x06, KEY_NEXT},
    {0x04, KEY_MUTE},
    //{0x46, KEY_PSCAN},    // CMD_PSCAN
    {0x44, KEY_SETUP},
    {0x05, KEY_SEARCH},
    {0x00, KEY_RED},    // CMD_OPTION_RED
    {0x42, KEY_GREEN},  // CMD_OPTION_GREEN
    {0x40, KEY_YELLOW}, // CMD_OPTION_YELLOW
    {0x01, KEY_BLUE},   // CMD_OPTION_BLUE
    {0x43, KEY_AUDIO},
    {0x41, KEY_SUBTITLE},   // CMD_STITLE
    //{0x03, KEY_REPEAT},   // CMD_REPEAT
    {0x02, KEY_SLOW},   // CMD_SFWD
#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
    /*Only take the position*/
    {0x0, KEY_ALC_HELLO_MIDOLI},
    {0x0, KEY_ALC_HELLO_MENU},
    {0x0, KEY_ALC_HELLO_VOLUME_LOUDER},
    {0x0, KEY_ALC_HELLO_VOLUME_DOWN},
    {0x0, KEY_ALC_CONFIRM},
    {0x0, KEY_ALC_START_PLAY},
    {0x0, KEY_ALC_PAUSE},
    {0x0, KEY_ALC_STOP},
    {0x0, KEY_ALC_GO_PREVIOUS},
    {0x0, KEY_ALC_GO_NEXT},
    {0x0, KEY_ALC_GO_RIGHT},
    {0x0, KEY_ALC_GO_LEFT},
#endif
};

static struct  venus_key_table rtk_mk5_tv_key_table = {
    .keys = rtk_mk5_tv_keys,
    .size = ARRAY_SIZE(rtk_mk5_tv_keys),
};

#if defined(CONFIG_RTK_KDRV_YK_54LU)
static struct venus_key yk_54lu_keys[] = {
    {0x17e8, KEY_IMAGE_MODE},   // CMD_PICTURE_MODE
    {0x0af5, KEY_INPUT_NUMBER},
    {0x0cf3, KEY_POWER},
    {0x18e7, KEY_SOUND_MODE},   // CMD_SOUND_MODE
    {0x4fb0, KEY_DISPLAY_MODE}, // CMD_DISPLAY_RATIO
    //{0x0bf4, KEY_INTRO},  // CMD_INTRO
    {0x1ce3, KEY_VII},  // CMD_VII
    //{0x1ae5, KEY_FREEZE}, // CMD_FREEZE
    {0x16e9, KEY_SCREEN_DISPLAY},   // CMD_DISPLAY
    {0x11ee, KEY_MENU}, // CMD_MENU
    //{0x4db2, KEY_HOME},   //CMD_HOME
    {0x0ff0, KEY_TV_INPUT}, //CMD_SOURCE
    {0x5ba4, KEY_BACK}, // CMD_RETURN
    {0x51ae, KEY_SHORTCUT}, //CMD_SHORTCUT
    {0x12ed, KEY_CHANNELUP},    // CMD_CHANNEL_INC
    {0x13ec, KEY_CHANNELDOWN},  // CMD_CHANNEL_DEC
    {0x0df2, KEY_MUTE},
    {0x14eb, KEY_VOLUMEUP},
    {0x15ea, KEY_VOLUMEDOWN},
    {0x4ab5, KEY_MEDIA_STOP},
    {0x43bc, KEY_DOWN},
    {0x44bb, KEY_LEFT},
    {0x45ba, KEY_RIGHT},
    {0x46b9, KEY_ENTER},//KEY_SELECT},
    {0x01fe, KEY_1},
    {0x02fd, KEY_2},
    {0x03fc, KEY_3},
    {0x04fb, KEY_4},
    {0x05fa, KEY_5},
    {0x06f9, KEY_6},
    {0x07f8, KEY_7},
    {0x08f7, KEY_8},
    {0x09f6, KEY_9},
    {0x00ff, KEY_0},
    {0x42bd, KEY_UP},
    {0x49b6, KEY_MEDIA_PLAY_PAUSE},
    {0x40bf, KEY_MEDIA_REWIND}, // CMD_FRWD
    {0x41be, KEY_MEDIA_FAST_FORWARD},   //CMD_FFWD
    {0x47b8, KEY_MEDIA_PREVIOUS},   // CMD_PREV
    {0x48b7, KEY_MEDIA_NEXT},
    //{0x57a8, KEY_SKIP},   // CMD_CMSKIP
    //{0x59a6, KEY_INSTANT_REPLAY}, //CMD_INSTANT_REPLAY
    //{0x58a7, KEY_MEDIA_FUNCTION}, // CMD_SFWD
    //{0x5aa5, KEY_ZOOM},
    {0x53ac, KEY_COOCAA},   // CMD_GUIDE
    {0x7986, KEY_SHARE},
    {0x0bf4, KEY_ALTERNATE},
    {0x609F, KEY_EPG}, // KEY_ENTER_EPG
    {0x629d, KEY_RED},
    {0x639c, KEY_GREEN},
    {0x649b, KEY_YELLOW},
    {0x659a, KEY_BLUE},
    {0x7887, KEY_HOME},
    {0x1de2, KEY_3D_DEL},
    {0x19e6, KEY_3D_MODE},
    {0x6996, KEY_TIME_SPOT},
    {0x9669, KEY_USER_SWITCH},
    {0x56a9, KEY_MEDIA_SONG_SYSTEM},
    {0x5da2, KEY_MEDIA_RELATIONSHIP},
    {0x55aa, KEY_MEDIA_BOOKING},
    {0x5ca3, KEY_FAVORITES},
    {0x57a8, KEY_MEDIA_AUDIO_CONTROL},
    {0x58a7, KEY_MEDIA_FUNCTION},
    {0x54ab, KEY_MEDIA_ORIGINAL_SOUNDTRACK},
    {0x4bb4, KEY_MEDIA_RECORD},
    {0x5aa5, KEY_MEDIA_SELECTED_SONGS},
    {0x5ea1, KEY_MEDIA_PRIORITY},
    {0x5fa0, KEY_MEDIA_DELETE},
    {0x59a6, KEY_MEDIA_SCORE_DISPLAY},
    {0x3fc0, KEY_FACTORY_FACTORY_MODE},
    {0x3ec1, KEY_FACTORY_RESET},
    {0x3dc2, KEY_FACTORY_SOURCE_ADD},
    {0x3cc3, KEY_FACTORY_SOURCE_REDUCE},
    {0x3ac5, KEY_FACTORY_BUS_OFF},
    {0x39c6, KEY_FACTORY_AGING_MODE},
    {0x38c7, KEY_FACTORY_AUTO_ADC},
    {0x36c9, KEY_FACTORY_RF_AGC},
    {0x22dd, KEY_FACTORY_BARCODE},
    {0x21de, KEY_FACTORY_SEARCH_UP},
    {0x20df, KEY_FACTORY_SEARCH_DOWN},
    {0x28d7, KEY_FACTORY_WHITE_BALANCE},
    {0x0001, KEY_NEW_SHUTTLE_LEFT},
    {0x0002, KEY_NEW_SHUTTLE_RIGHT},
    {0x4db2, KEY_LOCAL_MEDIA},
    {0x9c63, KEY_RESEARCH},
    {0x758a, KEY_SETTING},
    {0xc13e, KEY_SHUTTLE_LEFT_SPEED_1},
    {0xc23d, KEY_SHUTTLE_LEFT_SPEED_2},
    {0xc33c, KEY_SHUTTLE_LEFT_SPEED_3},
    {0xc43b, KEY_SHUTTLE_LEFT_SPEED_4},
    {0xc53a, KEY_SHUTTLE_LEFT_SPEED_5},
    {0xf10e, KEY_SHUTTLE_RIGHT_SPEED_1},
    {0xf20d, KEY_SHUTTLE_RIGHT_SPEED_2},
    {0xf30c, KEY_SHUTTLE_RIGHT_SPEED_3},
    {0xf40b, KEY_SHUTTLE_RIGHT_SPEED_4},
    {0xf50a, KEY_SHUTTLE_RIGHT_SPEED_5},
    {0x9a65, KEY_VOICE_END},
    {0x6699, KEY_POWER_LONG},
    {0x50af, KEY_HOME_LONG},
    {0x1be4, KEY_BACK_LONG},
    {0x1fe0, KEY_NOTIFICATION},
    {0x6a95, KEY_CENTER_LONG},
    {0x6b94, KEY_SEEK_SIGNAL},
    {0x7689, KEY_MYSTEP},
    {0x3bc4, KEY_FACTORY_OUTSET},
    {0x37c8, KEY_FACTORY_AV1},
    {0x35ca, KEY_FACTORY_AV2},
    {0x34cb, KEY_FACTORY_AV3},
    {0x33cc, KEY_FACTORY_S1},
    {0x32cd, KEY_FACTORY_YUV1},
    {0x31ce, KEY_FACTORY_YUV2},
    {0x30cf, KEY_FACTORY_VGA},
    {0x2fd0, KEY_FACTORY_HDMI1},
    {0x2ed1, KEY_FACTORY_HDMI2},
    {0x2dd2, KEY_FACTORY_HDMI3},
    {0x2cd3, KEY_FACTORY_KALA_OK},
    {0x2bd4, KEY_FACTORY_UPLAYER},
    {0x2ad5, KEY_FACTORY_LAN},
    {0x29d6, KEY_FACTORY_DREAM_PANEL},
    {0x28d7, KEY_FACTORY_WHITE_BALANCE},
    {0x24db, KEY_FACTORY_ALONE_LISTEN},
    {0x23dc, KEY_FACTORY_CA_CARD},
    {0x9b64, KEY_VOICE},
};

static struct  venus_key_table yk_54lu_key_table = {
    .keys = yk_54lu_keys,
    .size = ARRAY_SIZE(yk_54lu_keys),
};
#endif
#if defined(CONFIG_RTK_KDRV_YK_76J)
static struct venus_key yk_76j_keys[] = {
    {0x17e8, KEY_PICTURE_MODE}, // CMD_PICTURE_MODE
    {0x0af5, KEY_INPUT_NUMBER},
    {0x0cf3, KEY_POWER},
    {0x18e7, KEY_SOUND_MODE},   // CMD_SOUND_MODE
    {0x4fb0, KEY_DISPLAY_MODE}, // CMD_DISPLAY_RATIO
    {0x16e9, KEY_INFO}, // CMD_INTRO
    {0x1ce3, KEY_VII},  // CMD_VII
    //{0x1ae5, KEY_FREEZE}, // CMD_FREEZE
    //{0x16e9, KEY_SCREEN_DISPLAY}, // CMD_DISPLAY


    //{0xb748, KEY_MENU},   // CMD_QUICK

    {0x11ee, KEY_MENU}, // CMD_MENU
    {0x0ff0, KEY_SOURCE},
    //{0x4db2, KEY_HOME},   //CMD_HOME
    //{0x0ff0, KEY_TV_INPUT},   //CMD_SOURCE
    {0x0bf4, KEY_BACK}, // CMD_RETURN
    {0x51ae, KEY_SHORTCUT}, //CMD_SHORTCUT
    {0x12ed, KEY_CHANNELUP},    // CMD_CHANNEL_INC
    {0x13ec, KEY_CHANNELDOWN},  // CMD_CHANNEL_DEC
    {0x0df2, KEY_MUTE},
    {0x14eb, KEY_VOLUMEUP},
    {0x15ea, KEY_VOLUMEDOWN},
    {0x4ab5, KEY_MEDIA_STOP},
    {0x43bc, KEY_DOWN},
    {0x44bb, KEY_LEFT},
    {0x45ba, KEY_RIGHT},
    {0x46b9, KEY_ENTER},//KEY_SELECT},
    {0x01fe, KEY_1},
    {0x02fd, KEY_2},
    {0x03fc, KEY_3},
    {0x04fb, KEY_4},
    {0x05fa, KEY_5},
    {0x06f9, KEY_6},
    {0x07f8, KEY_7},
    {0x08f7, KEY_8},
    {0x09f6, KEY_9},
    {0x00ff, KEY_0},
    {0x42bd, KEY_UP},
    {0xb54a, KEY_EXIT},
    {0xac53, KEY_AUDIO},
    {0x0ef1, KEY_SLEEP},
    {0xb24d, KEY_SUBTITLE},
    {0x49b6, KEY_MEDIA_PLAY_PAUSE},
    {0x40bf, KEY_MEDIA_REWIND}, // CMD_FRWD
    {0x41be, KEY_MEDIA_FAST_FORWARD},   //CMD_FFWD
    {0x47b8, KEY_MEDIA_PREVIOUS},   // CMD_PREV
    {0x48b7, KEY_MEDIA_NEXT},
    //{0x57a8, KEY_SKIP},   // CMD_CMSKIP
    //{0x59a6, KEY_INSTANT_REPLAY}, //CMD_INSTANT_REPLAY
    //{0x58a7, KEY_MEDIA_FUNCTION}, // CMD_SFWD
    //{0x5aa5, KEY_ZOOM},
    {0x53ac, KEY_COOCAA},   // CMD_GUIDE
    //{0x7986, KEY_SHARE},
    //{0x0bf4, KEY_ALTERNATE},
    {0xb44b, KEY_EPG}, // KEY_ENTER_EPG
    {0xad52, KEY_FAVORITES},
    {0xab54, KEY_CAPTION},
    {0xb14e, KEY_RECORD},
    {0xa857, KEY_FREEZE},

    {0xa05f, KEY_RED},
    {0xa15e, KEY_GREEN},
    {0xa25d, KEY_YELLOW},
    {0xa35c, KEY_BLUE},
    {0x7887, KEY_HOME},
    {0x1de2, KEY_3D_DEL},
    {0x19e6, KEY_3D_MODE},
    {0x6996, KEY_TIME_SPOT},
    {0x9669, KEY_USER_SWITCH},
    {0x56a9, KEY_MEDIA_SONG_SYSTEM},
    {0x5da2, KEY_MEDIA_RELATIONSHIP},
    {0x55aa, KEY_MEDIA_BOOKING},
    {0x5ca3, KEY_FAVORITES},
    {0x57a8, KEY_MEDIA_AUDIO_CONTROL},
    {0x58a7, KEY_MEDIA_FUNCTION},
    {0x54ab, KEY_MEDIA_ORIGINAL_SOUNDTRACK},
    //{0x4bb4, KEY_MEDIA_RECORD},
    {0x5aa5, KEY_MEDIA_SELECTED_SONGS},
    {0x5ea1, KEY_MEDIA_PRIORITY},
    {0x5fa0, KEY_MEDIA_DELETE},
    {0x59a6, KEY_MEDIA_SCORE_DISPLAY},
    {0x3fc0, KEY_FACTORY_FACTORY_MODE},
    {0x3ec1, KEY_FACTORY_RESET},
    {0x3dc2, KEY_FACTORY_SOURCE_ADD},
    {0x3cc3, KEY_FACTORY_SOURCE_REDUCE},
    {0x3ac5, KEY_FACTORY_BUS_OFF},
    {0x39c6, KEY_FACTORY_AGING_MODE},
    {0x38c7, KEY_FACTORY_AUTO_ADC},
    {0x36c9, KEY_FACTORY_RF_AGC},
    {0x22dd, KEY_FACTORY_BARCODE},
    {0x21de, KEY_FACTORY_SEARCH_UP},
    {0x20df, KEY_FACTORY_SEARCH_DOWN},
    {0x28d7, KEY_FACTORY_WHITE_BALANCE},
    {0x0001, KEY_NEW_SHUTTLE_LEFT},
    {0x0002, KEY_NEW_SHUTTLE_RIGHT},
    {0x4db2, KEY_LOCAL_MEDIA},
    {0x9c63, KEY_RESEARCH},
    {0x758a, KEY_SETTING},
    {0xc13e, KEY_SHUTTLE_LEFT_SPEED_1},
    {0xc23d, KEY_SHUTTLE_LEFT_SPEED_2},
    {0xc33c, KEY_SHUTTLE_LEFT_SPEED_3},
    {0xc43b, KEY_SHUTTLE_LEFT_SPEED_4},
    {0xc53a, KEY_SHUTTLE_LEFT_SPEED_5},
    {0xf10e, KEY_SHUTTLE_RIGHT_SPEED_1},
    {0xf20d, KEY_SHUTTLE_RIGHT_SPEED_2},
    {0xf30c, KEY_SHUTTLE_RIGHT_SPEED_3},
    {0xf40b, KEY_SHUTTLE_RIGHT_SPEED_4},
    {0xf50a, KEY_SHUTTLE_RIGHT_SPEED_5},
    {0x9a65, KEY_VOICE_END},
    {0x6699, KEY_POWER_LONG},
    {0x50af, KEY_HOME_LONG},
    {0x1be4, KEY_BACK_LONG},
    {0x1fe0, KEY_NOTIFICATION},
    {0x6a95, KEY_CENTER_LONG},
    {0x6b94, KEY_SEEK_SIGNAL},
    {0x7689, KEY_MYSTEP},
    {0x3bc4, KEY_FACTORY_OUTSET},
    {0x37c8, KEY_FACTORY_AV1},
    {0x35ca, KEY_FACTORY_AV2},
    {0x34cb, KEY_FACTORY_AV3},
    {0x33cc, KEY_FACTORY_S1},
    {0x32cd, KEY_FACTORY_YUV1},
    {0x31ce, KEY_FACTORY_YUV2},
    {0x30cf, KEY_FACTORY_VGA},
    {0x2fd0, KEY_FACTORY_HDMI1},
    {0x2ed1, KEY_FACTORY_HDMI2},
    {0x2dd2, KEY_FACTORY_HDMI3},
    {0x2cd3, KEY_FACTORY_KALA_OK},
    {0x2bd4, KEY_FACTORY_UPLAYER},
    {0x2ad5, KEY_FACTORY_LAN},
    {0x29d6, KEY_FACTORY_DREAM_PANEL},
    {0x28d7, KEY_FACTORY_WHITE_BALANCE},
    {0x24db, KEY_FACTORY_ALONE_LISTEN},
    {0x23dc, KEY_FACTORY_CA_CARD},
    {0x9b64, KEY_VOICE},
};

static struct  venus_key_table yk_76j_key_table = {
    .keys = yk_76j_keys,
    .size = ARRAY_SIZE(yk_76j_keys),
};
#endif
#if defined(CONFIG_RTK_KDRV_TV035_IR)
static struct venus_key konka_tv_keys[] = {
    {0x0b, KEY_POWER},
    {0x1c, KEY_SOURCE},
    {0x01, KEY_1},
    {0x02, KEY_2},
    {0x03, KEY_3},
    {0x04, KEY_4},
    {0x05, KEY_5},
    {0x06, KEY_6},
    {0x07, KEY_7},
    {0x08, KEY_8},
    {0x09, KEY_9},
    {0x0a, KEY_INFO},   // CMD_INFO
    {0x0, KEY_0},
    {0x0E,  KEY_DELETE },  //KEY_KK_CHANNEL_RETURN
    //New Add one
    {0x2a, KEY_KK_PROGRAM_LIST},

    {0x15, KEY_MENU},   // CMD_MENU

    //New Add three
    {0xff, KEY_KK_PROGRAM_FAVORITE},
    {0x27, KEY_PAGEUP},
    {0x24, KEY_PAGEDOWN},

    {0x2b, KEY_UP},
    {0x2c, KEY_DOWN},
    {0x2d, KEY_LEFT},
    {0x2e, KEY_RIGHT},
    {0x2f, KEY_ENTER},
    {0x38, KEY_HOME},   // CMD_GUIDE
    {0x30, KEY_BACK},   // CMD_RETURN
    {0x1a, KEY_RED},    // CMD_OPTION_RED
    {0x1f, KEY_GREEN},  // CMD_OPTION_GREEN
    {0x0c, KEY_YELLOW}, // CMD_OPTION_YELLOW
    {0x16, KEY_BLUE},   // CMD_OPTION_BLUE

    {0x14, KEY_MUTE},

    {0x12, KEY_VOLUMEDOWN},
    {0x13, KEY_VOLUMEUP},
    {0x10, KEY_CHANNELDOWN},
    {0x11, KEY_CHANNELUP},

    //New Add TEN
    {0x22, KEY_KK_EPG}, // CMD_EPG
    {0x36, KEY_KK_3D},  // KEY_3D_MODE
    {0x1d, KEY_PICTURE_MODE}, //KEY_PICTURE_MODE
    {0x1e, KEY_DISPLAY_RATIO},  // KEY_DISPLAY_RATIO
    {0x0d, KEY_SOUND_MODE},
    {0x19, KEY_FREEZE},  // FREEZE //wangzhh add for customer 20130530
    {0x32, KEY_KK_TV},   //TV
    {0x34, KEY_YPBPR1},  // YPBPR
    {0x31, KEY_HDMI1},   // CMD_HDMI
    {0x33, KEY_AV},  // AV
    {0x25, KEY_SEARCH},
    {0x50, KEY_USB}, // CMD_USB
    //wangzhh add for factory remote control 20130604
    {0x82, KEY_VOLUME_DETECT},  // CMD_USB
    {0x88, KEY_FACTORY_MENU},   // KEY_FACTORY
    {0x85, KEY_BURN_TV}, //KEY_BURN_TV
    {0x80, KEY_KK_FAC_RESET},   // KEY_FACTORY
    {0x81, KEY_BALANCE}, //KEY_BURN_TV
    {0x83, KEY_BACKLIGHT_DETECT},   // KEY_VOICE_SEARCH
    {0x84, KEY_MIC_DETECT},
    {0x8b, KEY_KK_F1},
    {0x8c, KEY_KK_F2},   //KEY_24G_TO_INFRARED
    {0x8d, KEY_KK_F3},   // KEY_INFRARED_TO_24G
    {0x8e, KEY_F4},  // KEY_HEADPHONE_INSET
    {0x98, KEY_F5},  // KEY_HEADPHONE_PULLOUT

    {0x86, KEY_KK_LANGUAGE},
    {0x8A, KEY_KK_NET},
    {0x95, KEY_KK_VGA},

    {0x62, KEY_MORE},
    {0x64, KEY_MOUSE_CENTERED},
    {0x65, KEY_MOUSE_OK_DOWN},
    {0x66, KEY_MOUSE_OK_UP},

    {0xff, KEY_VOICE_SEARCH},    // KEY_VOICE_SEARCH
    {0xff, KEY_START_HANDWRITING},
    {0xff, KEY_FINISH_HANDWRITING},
    {0xff, KEY_24G_TO_INFRARED}, //KEY_24G_TO_INFRARED
    {0xff, KEY_INFRARED_TO_24G}, // KEY_INFRARED_TO_24G
    {0xff, KEY_HEADPHONE_INSET}, // KEY_HEADPHONE_INSET
    {0xff, KEY_HEADPHONE_PULLOUT},   // KEY_HEADPHONE_PULLOUT

};

static struct  venus_key_table konka_tv_key_table = {
    .keys = konka_tv_keys,
    .size = ARRAY_SIZE(konka_tv_keys),
};
#endif

#if defined(CONFIG_RTK_KDRV_TV036_KTSG45_IR)
static struct venus_key ktsg45_tv_keys[] = {//hikeen ir
	{0x46, KEY_POWER},
	{0x4c, KEY_MUTE},	
	{0x01, KEY_1},
	{0x02, KEY_2},
	{0x03, KEY_3},	
	{0x0c, KEY_CHANNELUP},
	{0x04, KEY_4},
	{0x05, KEY_5},
	{0x06, KEY_6},
	{0x19, KEY_CHANNELDOWN},
	{0x07, KEY_7},
	{0x08, KEY_8},
	{0x09, KEY_9},
	{0x0f, KEY_VOLUMEUP},	// CMD_VOL_UP
	{0x00, KEY_0},
	{0x5a, KEY_VOLUMEDOWN},		// CMD_VOL_DOWN
	{0x4b, KEY_SOURCE},	//CMD_SOURCE
	{0x48, KEY_UP},
	{0x4d, KEY_DOWN},
	{0x4e, KEY_LEFT},
	{0x49, KEY_RIGHT},
	{0x4a, KEY_ENTER},
	{0x42, KEY_HOME},	// CMD_GUIDE
	{0x0d, KEY_BACK},	// CMD_RETURN
	{0x52, KEY_RED},	// CMD_OPTION_RED
	{0x13, KEY_GREEN},	// CMD_OPTION_GREEN
	{0x50, KEY_YELLOW},	// CMD_OPTION_YELLOW
	{0x11, KEY_BLUE},	// CMD_OPTION_BLUE
	{0x18, KEY_EPG},	// CMD_EPG
	{0x45, KEY_MENU},	// CMD_MENU
	{0x40, KEY_SLEEP},
	{0x4f, KEY_INFO},	// CMD_DISPLAY
	{0x47, KEY_VIDEO},
	{0x43, KEY_SOUND_MODE},
	{0x59, KEY_LIST},	// CHANNEL LIST
	{0x16, KEY_STOP},	// STOP
	{0x57, KEY_PLAYPAUSE},	// PLAY
	{0x15, KEY_NEXT},	// PAUSE or STEP or STILL
	{0x54, KEY_PREVIOUS},	// SKIP - or REVEAL or |<<
	{0x58, KEY_3D_MODE},
	{0x17, KEY_FASTFORWARD},	// CMD_FFWD
	{0x56, KEY_REWIND},
	{0x5b, KEY_ZOOM},
	{0x1a, KEY_SYSRQ},
	//{0x44, KEY_BACK_TO_TV},
};

static struct  venus_key_table ktsg45_tv_key_table = {
	.keys = ktsg45_tv_keys,
	.size = ARRAY_SIZE(ktsg45_tv_keys),
};
#endif

#if defined(CONFIG_RTK_KDRV_TV036_10D_IR)
static struct venus_key Hikeen_10D_tv_keys[] = 
{
	{0x1C, KEY_POWER},
	{0x08, KEY_MUTE},

	{0x54, KEY_1},	
	{0x16, KEY_2},
	{0x15, KEY_3},

    {0x14, KEY_4},
	{0x50, KEY_5},     
	{0x12, KEY_6},

	{0x11, KEY_7},
    {0x10, KEY_8},
	{0x0E, KEY_9},

    {0x4C, KEY_JUMP},	  //channel recall
	{0x0D, KEY_0},
	{0x0C, KEY_3D_MODE},    // -/--
	
	{0x1F, KEY_SUBTITLE},
	{0x1B, KEY_VIDEO},	//P.mode
	{0x03, KEY_SOUND_MODE},//S.mode

	{0x18, KEY_SOURCE},	
    {0x17, KEY_INFO},
	{0x49, KEY_MENU},
	{0x0A, KEY_BACK},//EXIT

	{0x1A, KEY_UP},		
    {0x48, KEY_DOWN},	
	{0x47, KEY_LEFT},
	{0x07, KEY_RIGHT},
	{0x06, KEY_ENTER},
	{0x5A, KEY_HOME},

	{0x4B, KEY_VOLUMEUP},
    {0x4F, KEY_VOLUMEDOWN},	
	{0x09, KEY_CHANNELUP},
	{0x05, KEY_CHANNELDOWN},

    {0x4A, KEY_SLEEP},	
	{0x4E, KEY_AUDIO},      //Nicam key
	{0x1E, KEY_TTX_SUBPAGE},     //subpage

	{0x58, KEY_FAV_ADD},	// TT hold
	{0x5C, KEY_FAV},	// FAVORITES and Mix
	{0x40, KEY_FAV_SUB},             // TT reveal
	{0x02, KEY_TTX_CANCEL},          //TTX canel

	{0x5D, KEY_RED},		
	{0x59, KEY_GREEN},	    
	{0x51, KEY_YELLOW},    
	{0x55, KEY_BLUE},	

	{0x5E, KEY_FREEZE},    //FREEZE //TT Title
	{0x5A, KEY_LOCAL_MEDIA}, 
	{0x52, KEY_TEXT},		//TTX TEXT
	{0x56, KEY_LIST},    //TT index	

	{0x5B, KEY_FASTFORWARD},	// FF
	{0x5F, KEY_REWIND},    		//FR
	{0x53, KEY_PREVIOUS},		//prev
	{0x57, KEY_NEXT},			//next

	{0x43, KEY_EPG},
	{0x41, KEY_PLAYPAUSE},
	{0x01, KEY_STOP},
	{0x19, KEY_ZOOM},  //aspect && TT SIZE

	{0x42, KEY_RADIO},       //dtv/radio
	{0x45, KEY_PVR},       //rec.task
	{0x46, KEY_REC_LIST},       //rec.file
	{0x1D, KEY_RECORD},//

};

static struct  venus_key_table Hikeen_10D_tv_key_table = {
	.keys = Hikeen_10D_tv_keys,
	.size = ARRAY_SIZE(Hikeen_10D_tv_keys),
};
#endif

#if defined(CONFIG_RTK_KDRV_HAIER_IR)
static struct venus_key haier_tv_keys[] = {
    //{0x0df2, KEY_PICTURE_MODE},   // CMD_PICTURE_MODE

    //{0x0bf4, KEY_DELETE},//

    {0x0bf4, KEY_POWER},
    {0x15ea, KEY_SOURCE},   //CMD_SOURCE

    {0xdf2, KEY_VIDEO},
    {0x12ed, KEY_AUDIO},
    {0x13ec, KEY_ZOOM},
    //{0x1fe0, KEY_},//

    {0x5ba4, KEY_EPG}, //


    //{0x12ed, KEY_SOUND_MODE}, // CMD_SOUND_MODE
    //{0x13ec, KEY_DISPLAY_RATIO},  // CMD_DISPLAY_RATIO
    //{0x0bf4, KEY_INTRO},  // CMD_INTRO

    //{0x1ce3, KEY_VII},    // CMD_VII

    //{0x1ae5, KEY_FREEZE}, // CMD_FREEZE


    //{0x20df, KEY_DISPLAY},    // CMD_DISPLAY


    //{0x51ae, KEY_SHORTCUT},   //CMD_SHORTCUT

    //{0x4ab5, KEY_STOP},



    {0x00ff, KEY_1},
    {0x01fe, KEY_2},
    {0x02fd, KEY_3},
    {0x03fc, KEY_4},
    {0x04fb, KEY_5},
    {0x05fa, KEY_6},
    {0x06f9, KEY_7},
    {0x07f8, KEY_8},
    {0x08f7, KEY_9},
    {0x20df, KEY_DISPLAY},//
    {0x09f6, KEY_0},
    {0x0af5, KEY_LAST},//INTRO


    {0x19e6, KEY_CHANNELUP},    // CMD_CHANNEL_INC
    {0x18e7, KEY_CHANNELDOWN},  // CMD_CHANNEL_DEC
    {0x0cf3, KEY_MUTE},
    {0x1be4, KEY_VOLUMEUP},
    {0x1ae5, KEY_VOLUMEDOWN},
    {0x916e, KEY_VOLUMEUP},
    {0x9966, KEY_VOLUMEDOWN},
    {0x8a75, KEY_3D_MODE},//3D



    //{0x7c83, KEY_},//
    //{0x8c73, KEY_},//
    //{0x90},//
    {0x4db2, KEY_HOME}, //CMD_HOME
    {0x639c, KEY_HOME}, //CMD_HOME
    {0xab54, KEY_HOME},     //CMD_HOME
    {0x906f, KEY_RecentApplicationsDialog},
    {0x0ff0, KEY_SCREENSHOT},
    //{0x8b,  },//
    {0x1ce3, KEY_MENU}, // CMD_MENU


    //{0x708f, KEY_},  //
    //{0x748b, KEY_},//

    {0x649b, KEY_UP},
    {0x6699, KEY_DOWN},
    {0x659a, KEY_LEFT},
    {0x6798, KEY_RIGHT},
    {0x6897, KEY_ENTER},
    {0x708f, KEY_PAGEUP},
    {0x748b, KEY_PAGEDOWN},

    //{0x0ff0, KEY_FREEZE},//
    {0x6996, KEY_BACK},

    {0x5ea1, KEY_RED},
    {0x5fa0, KEY_GREEN},
    {0x619e, KEY_YELLOW},
    {0x629d, KEY_BLUE},

    {0x6c93, KEY_PLAY},
    {0x6a95, KEY_REWIND},   // CMD_FRWD
    {0x6b94, KEY_FASTFORWARD},  //CMD_FFWD
    //{0xa3 },//



    //{0x28d7, KEY_PREVIOUS},   // CMD_PREV
    //{0x29d6, KEY_NEXT},
    //{0x57a8, KEY_SKIP},   // CMD_CMSKIP
    //{0x59a6, KEY_INSTANT_REPLAY}, //CMD_INSTANT_REPLAY
    //{0x32cd, KEY_SLOW},   // CMD_SFWD

    //{0x32cd, KEY_ZOOM},

    //{0x7986, KEY_COFFEE}, // three display share key
    //{0x0bf4, KEY_CAPSLOCK}, // KEY Alternate

    {0x1fe0, KEY_HAIER_USB}, // CMD_GUIDE
};

static struct  venus_key_table haier_key_tv_table = {
    .keys = haier_tv_keys,
    .size = ARRAY_SIZE(haier_tv_keys),
};
static struct venus_key haier_key_Fackeys[] = {
#if 1
    {0x3ec1, KEY_FACTORY_FACTORY_MODE}, // CMD_TPV
    {0x0ff0, KEY_1},
    {0x12ed, KEY_2},
    {0x4ab5, KEY_3},
    {0x30cf, KEY_4},
    {0x10ef, KEY_5},
    {0x11ee, KEY_6},
    {0x32cd, KEY_7},
    {0x35ca, KEY_8},
    {0x36c9, KEY_9},
    {0x33cc, KEY_0},

    {0x56a9, KEY_CHANNELUP},    // CMD_CHANNEL_INC
    {0x55aa, KEY_CHANNELDOWN},  // CMD_CHANNEL_DEC
    {0x37c8, KEY_MUTE},
    {0x5fa0, KEY_VOLUMEUP},
    {0x609f, KEY_VOLUMEDOWN},

    {0x26d9, KEY_UP},
    {0x27d8, KEY_DOWN},
    {0x5da2, KEY_LEFT},
    {0x5ea1, KEY_RIGHT},
    {0x0ef1, KEY_ENTER},
    {0x708f, KEY_HAIER_USB}, // CMD_GUIDE
    {0x22dd, KEY_3D_MODE},//3D
    {0x6d92, KEY_FACTORY_TEST},
    {0x7b84, KEY_FACTORY_VGA},
    {0x00ff, KEY_FACTORY_AV1},
    {0x01fe, KEY_FACTORY_YUV1},
    {0x02fd, KEY_FACTORY_HDMI1},
    {0x758a, KEY_FACTORY_LOGOLED},
    {0x3fc0, KEY_TV},
    {0x46b9, KEY_PICTURE_MODE},
    {0x5aa5, KEY_FACTORY_RESET},
    {0x31ce, KEY_FACTORY_AUTO_ADC},
    {0x54ab, KEY_FACTORY_AGING_MODE},
    {0x57a8, KEY_FACTORY_AUTOSCANCH},
    {0x708f, KEY_FACTORY_UPLAYER},
    {0x6b94, KEY_FACTORY_PRESETCH},
#endif

};

static struct  venus_key_table haier_key_fac_table = {
    .keys = haier_key_Fackeys,
    .size = ARRAY_SIZE(haier_key_Fackeys),
};

static struct venus_key haier_key_CVTkeys[] = { //lyg,20140325,for CVT remote
    {0x01fe, KEY_POWER},                //cvt power key
    {0x11ee, KEY_MUTE},                 //cvt mute key
    {0x05fa, KEY_DISPLAY},              //cvt display key
    {0x15ea, KEY_ZOOM},                 //cvt INOUT key(do as ZOOM)
    {0x44bb, KEY_VOLUMEUP},             //cvt V+ key
    {0x45ba, KEY_VOLUMEDOWN},           //cvt V- key
    {0x48b7, KEY_CHANNELUP},            // cvt CH+ key
    {0x49b6, KEY_CHANNELDOWN},          // cvt CH- key
    {0x02fd, KEY_1},                    // cvt 1 key
    {0x12ed, KEY_2},                    // cvt 2 key
    {0x06f9, KEY_3},                    // cvt 3 key
    {0x16e9, KEY_4},                    // cvt 4 key
    {0x03fc, KEY_5},                    // cvt 5 key
    {0x13ec, KEY_6},                    // cvt 6 key
    {0x07f8, KEY_7},                    // cvt 7 key
    {0x17e8, KEY_8},                    // cvt 8 key
    {0x00ff, KEY_9},                    // cvt 9 key
    {0x10ef, KEY_0},                    // cvt 0 key
    {0x04fb, KEY_CVTFAC_10_P},          // cvt 10 plus key  --CVT function
    {0x14eb, KEY_CVTFAC_DOT},           // cvt dot key  --CVT function
    {0x56a9, KEY_UP},                   // cvt up key
    {0x50af, KEY_DOWN},                 // cvt down key
    {0x47b8, KEY_LEFT},                 // cvt left key
    {0x4bb4, KEY_RIGHT},                // cvt right key
    {0x57a8, KEY_ENTER},                // cvt enter(OK) key
    {0x54ab, KEY_CVTAUTO},              // cvt auto key --CVT function
    {0x4ab5, KEY_BACK},                 // cvt DTV_MENU key
    {0x46b9, KEY_MENU},                 // cvt ATV_MENU key
    {0x4cb3, KEY_HOME},                 //cvt DVD_SETUP key,lyg,20140402,for enter luncher
    {0x40bf, KEY_SOURCE},               // cvt SOURCE key
    {0x51ae, KEY_VIDEO},                // cvt zoom(pic mode) key
    {0x4db2, KEY_AUDIO},                // cvt EPG(sound mode) key
    {0x59a6, KEY_CVTFAC_PVR},           // cvt PVR key  --CVT function
    {0x0af5, KEY_CVTFAC_TUNE},          // cvt TUNE key  --CVT function
    {0x09f6, KEY_HAIER_USB},            // cvt MEDIA key
    {0x19e6, KEY_CVTFAC_CALIBRATION1},  // cvt FAC_CALIBRATION1 key  --CVT function
    {0x0df2, KEY_CVTFAC_CALIBRATION2},  // cvt FAC_CALIBRATION2 key  --CVT function
    {0x0ef1, KEY_CVTFAC_VERSION},       // cvt VERSION key   --CVT function
    {0x0bf4, KEY_CVTFAC_AGING_MODE},    // cvt AGING_MODE key    --CVT function
    {0x1be4, KEY_CVTFAC_PANEL1},        // cvt PANEL1 key    --CVT function
    {0x0ff0, KEY_CVTFAC_PANEL2},        // cvt PANEL2 key    --CVT function
    {0x08f7, KEY_CVTFAC_F1},            // cvt F1 key    --CVT function
    {0x18e7, KEY_CVTFAC_F2},            // cvt F2 key    --CVT function
    {0x0cf3, KEY_SOURCE},           // cvt F3 key,lyg,20140402,for change source
    {0x1de2, KEY_CVTFAC_F4},            // cvt F4 key    --CVT function
    {0x1ee1, KEY_CVTFAC_F5},            // cvt F5 key    --CVT function
    {0x1fe0, KEY_CVTFAC_F6},            // cvt F6 key    --CVT function
    {0x1ce3, KEY_CVTFAC_F7},            // cvt F7 key    --CVT function

    {0x55aa, KEY_CVTFAC_NICAM},         // cvt NICAM key     --CVT function
    {0x41be, KEY_CVTFAC_TTXCC},         // cvt TEXT/CC key   --CVT function
    {0x1ae5, KEY_CVTFAC_RESET},         // cvt RESET key     --CVT function
};

static struct  venus_key_table haier_key_cvt_table = {  //lyg,20140325,for CVT remote
    .keys = haier_key_CVTkeys,
    .size = ARRAY_SIZE(haier_key_CVTkeys),
};

static struct venus_key haier_key_MTCkeys[] = { //lyg,20140403,for MTC remote
    {0x8877, KEY_FACTORY_S1},//KEY_MTCFAC_SV1},
    {0x807f, KEY_SOURCE},//KEY_MTCFAC_SV2},
    {0x639c, KEY_MTCFAC_DTV1},              //mtc DTV1  --MTC function
    {0x629d, KEY_MTCFAC_DTV2},              //mtc DTV2  --MTC function
    {0x619e, KEY_MTCFAC_DTV3},              //mtc DTV3  --MTC function
    {0x609f, KEY_MTCFAC_REC},               //mtc REC  --MTC function
    {0x6b94, KEY_MTCFAC_ATV1},              //mtc ATV1  --MTC function
    {0x6a95, KEY_MTCFAC_ATV2},              //mtc ATV2  --MTC function
    {0x6996, KEY_MTCFAC_ATV3},              //mtc ATV3  --MTC function
    {0x6897, KEY_HAIER_USB},//KEY_MTCFAC_USB},
    {0x738c, KEY_FACTORY_AV1},//KEY_MTCFAC_AV1},
    {0x728d, KEY_FACTORY_AV1},//KEY_MTCFAC_AV2},
    {0x718e, KEY_FACTORY_VGA},//KEY_MTCFAC_PC},
    {0x708f, KEY_FACTORY_YUV1},//KEY_MTCFAC_YUV},
    {0x7b84, KEY_FACTORY_HDMI1},//KEY_MTCFAC_HDMI1},
    {0x7887, KEY_FACTORY_HDMI2},//KEY_MTCFAC_HDMI2},
    {0x7a85, KEY_UP},                   // KEY_MTCFAC_UP
    {0x8a75, KEY_DOWN},                 // KEY_MTCFAC_DOWN
    {0x837c, KEY_LEFT},                 // KEY_MTCFAC_LEFT
    {0x817e, KEY_RIGHT},                // KEY_MTCFAC_RIGHT
    {0x827d, KEY_ENTER},                // KEY_MTCFAC_ enter(OK) key
    {0x8b74, KEY_MENU},//an undefined key,redefined by lyg
    {0x8976, KEY_BACK},//an undefined key,redefined by lyg
    {0x936c, KEY_CVTFAC_VERSION},//KEY_MTCFAC_VERSION,COPY CVT FUCNTION
    {0x926b, KEY_MTCFAC_SCART1},                //mtc SCART1  --MTC function
    {0x916e, KEY_EXIT},
    {0x9768, KEY_MTCFAC_SCART2},                //mtc SCART2  --MTC function
    {0x9669, KEY_DISPLAY},//KEY_FACTORY_AV3},
    {0x956a, KEY_FACTORY_HDMI3},
    {0x8e71, KEY_MTCFAC_DVD},                   //mtc DVD  --MTC function
    {0x8d72, KEY_MTCFAC_DVB_S},                 //mtc DVB_S  --MTC function
    {0x8778, KEY_MTCFAC_DVD_USB},               //mtc DVD_USB  --MTC function
    {0x8679, KEY_MTCFAC_DVD_DISK},              //mtc DVD_DISK  --MTC function
    {0x857a, KEY_MTCFAC_DVB_S_RESET},           //mtc DVB_S_RESET  --MTC function
    {0x7f80, KEY_MTCFAC_PLAY},                  //mtc PLAY  --MTC function
    {0x7e81, KEY_MTCFAC_STOP},                  //mtc STOP  --MTC function
    {0x7d82, KEY_MTCFAC_RESET},                 //mtc RESET  --MTC function
    {0x7788, KEY_CVTAUTO},//KEY_MTCFAC_PC AUTO ADC},
    {0x7689, KEY_HOME},//an undefined key,redefined by lyg
    {0x758a, KEY_MENU},
    {0x748b, KEY_POWER},
    {0x748b, KEY_VOLUMEDOWN},//an undefined key,redefined by lyg
    {0x748b, KEY_VOLUMEUP},//an undefined key,redefined by lyg
    {0x748b, KEY_CHANNELDOWN},//an undefined key,redefined by lyg
    {0x748b, KEY_CHANNELUP},    //an undefined key,redefined by lyg
    {0x649b, KEY_HOME},//an undefined key,redefined by lyg
};

static struct  venus_key_table haier_key_mtc_table = {  //lyg,20140403,for CVT remote
    .keys = haier_key_MTCkeys,
    .size = ARRAY_SIZE(haier_key_MTCkeys),
};
#endif


#if defined(CONFIG_RTK_KDRV_TV001_IR)
static struct venus_key rtk_mk5_2_tv_keys[] = {
    {0x5f, KEY_POWER},
    {0x5b, KEY_MUTE},
    {0x53, KEY_1},
    {0x50, KEY_2},
    {0x12, KEY_3},
    //{0x40, KEY_CHANNEL_INC},  // CMD_CHANNEL_INC
    {0x40, KEY_CHANNELUP},
    {0x4f, KEY_4},
    {0x4c, KEY_5},
    {0x0e, KEY_6},
    //{0x5d, KEY_CHANNEL_DEC},  // CMD_CHANNEL_DEC
    {0x5d, KEY_CHANNELDOWN},
    {0x4b, KEY_7},
    {0x48, KEY_8},
    {0x0a, KEY_9},
    {0x03, KEY_VOLUMEUP},   // CMD_VOL_UP
    {0x47, KEY_DELETE},
    {0x44, KEY_0},
    {0x06, KEY_ENTER},  // CMD_ENTER
    {0x1f, KEY_VOLUMEDOWN},     // CMD_VOL_DOWN
    {0x57, KEY_SOURCE}, //CMD_SOURCE
    //{0x08, KEY_TOOLS},    // CMD_TOOLS
    {0x59, KEY_UP},
    {0x51, KEY_DOWN},
    {0x56, KEY_LEFT},
    {0x14, KEY_RIGHT},
    {0x55, KEY_ENTER},
    //{0x46, KEY_PIP},  // CMD_PIP
    //{0x45, KEY_POP},  // CMD_POP
    {0x42, KEY_HOME},   // CMD_GUIDE
    //{0x41, KEY_MP},   // CMD_MP
    {0x52, KEY_JUMP},   // CMD_JUMP
    {0x10, KEY_BACK},   // CMD_RETURN
    {0x4e, KEY_RED},    // CMD_OPTION_RED
    {0x4d, KEY_GREEN},  // CMD_OPTION_GREEN
    {0x0c, KEY_YELLOW}, // CMD_OPTION_YELLOW
    {0x0d, KEY_BLUE},   // CMD_OPTION_BLUE
    {0x01, KEY_FAVCH},    // CMD_FAVCH
    {0x4a, KEY_EPG},    // CMD_EPG
    {0x49, KEY_INFO},
    //{0x49, KEY_PROGINFO}, // CMD_PROGINFO
    {0x09, KEY_MENU},   // CMD_MENU
    //{0x43, KEY_},     // CMD_NODEFINED
    {0x58, KEY_SLEEP},
    {0x1b, KEY_DISPLAY},    // CMD_DISPLAY
    {0x1a, KEY_DISPLAY_RATIO}, // CMD_WIDE
    //{0x5e, KEY_},     // CMD_NODEFINED
    {0x54, KEY_CAPTION},    // CMD_CAPTION
    {0x17, KEY_VIDEO},
    {0x16, KEY_AUDIO},
    {0x5a, KEY_AUDIOMTS},     // CMD_AUDIOMTS
    {0x05, KEY_ROI},  // CMD_ROI
    {0x04, KEY_FREEZE}, // CMD_FREEZE
    {0x00, KEY_CARD_READER},    // CMD_CARD_READER
    {0x43, KEY_TEXT},   // CMD_TELETEXT
    //{0x5e, KEY_SUBTITLE},   // CMD_SUBTITLE
    {0x5e, KEY_AUDIOMODE},
    //{0x5e, KEY_SUBTITLE},   // CMD_SUBTITLE
    //{0x5e, KEY_AUDIOMODE},
    {0x46, KEY_PIP},  // CMD_PIP
    {0x45, KEY_POP},  // CMD_POP
    {0x41, KEY_MP},   // CMD_MP
    {0x08, KEY_TOOLS},    // CMD_TOOLS
};

static struct  venus_key_table rtk_mk5_2_tv_key_table = {
    .keys = rtk_mk5_2_tv_keys,
    .size = ARRAY_SIZE(rtk_mk5_2_tv_keys),
};
#endif

#if defined(CONFIG_RTK_KDRV_ANDROID_OTT)
static struct venus_key rtk_android_ott_stb_keys[] = {
    {0xe51a, KEY_POWER},
    {0xe41b, KEY_BACK},
    {0xa758, KEY_MENU},
    {0xf906, KEY_UP},
    {0xa25d, KEY_LEFT},
    {0xa35c, KEY_RIGHT},
    {0xe01f, KEY_DOWN},
    {0xe11e, KEY_ENTER},
    {0xbb44, KEY_VOLUMEUP},
    {0xe916, KEY_VOLUMEDOWN},
    {0xaa55, KEY_PLAY}, //PLAY or PAUSE
    {0xa659, KEY_HOME},
};

static struct  venus_key_table rtk_android_ott_stb_key_table = {
    .keys = rtk_android_ott_stb_keys,
    .size = ARRAY_SIZE(rtk_android_ott_stb_keys),
};
#endif


#if defined(CONFIG_RTK_KDRV_TV015_IR)
static struct venus_key tv015_ir_aoc_tv_keys[] = {
    {0x01, KEY_POWER},

    {0x41, KEY_0},
    {0x15, KEY_1},
    {0x16, KEY_2},
    {0x17, KEY_3},
    {0x19, KEY_4},
    {0x1A, KEY_5},
    {0x1B, KEY_6},
    {0x1D, KEY_7},
    {0x1E, KEY_8},
    {0x1F, KEY_9},
    {0x4B, KEY_INPUT_NUMBER},// CMD_POINT ?
    {0x44, KEY_JUMP},

    {0x40, KEY_3D_MODE},    // CMD_3D_MODE_BANNER ?
    {0x03, KEY_VIDEO},
    {0x09, KEY_AUDIO},
    {0x14, KEY_ZOOM},       // CMD_WIDE ?

    {0x18, KEY_CHANNELUP},
    {0x1C, KEY_CHANNELDOWN},
    {0x0C, KEY_VOLUMEUP},   // CMD_VOL_UP
    {0x10, KEY_VOLUMEDOWN}, // CMD_VOL_DOWN
    {0x0a, KEY_MENU},       // CMD_MENU
    {0x04, KEY_MUTE},

    {0x08, KEY_SOURCE},     // CMD_SOURCE
    {0x51, KEY_HOME},       // CMD_GUIDE(ATV=>IPTV)
    {0x46, KEY_TV},         // CMD_SOURCE_ATV1 ?
    {0x06, KEY_AV},         // CMD_SOURCE_AV1 ?

    {0x0b, KEY_UP},
    {0x0f, KEY_DOWN},
    {0x49, KEY_LEFT},
    {0x4a, KEY_RIGHT},
    {0x0d, KEY_ENTER},      // CMD_ENTER
    {0x54, KEY_BACK},       // CMD_RETURN?
    {0x55, KEY_OPTION},     // CMD_OPTION_MENU ?

    {0x60, KEY_RED},        // CMD_OPTION_RED
    {0x61, KEY_GREEN},      // CMD_OPTION_GREEN
    {0x62, KEY_YELLOW},     // CMD_OPTION_YELLOW
    {0x63, KEY_BLUE},       // CMD_OPTION_BLUE

    {0x5c, KEY_PREVIOUS},   // CMD_PREV_FILE ?
    {0x58, KEY_REWIND},     // CMD_FRWD ?
    {0x57, KEY_FASTFORWARD},// CMD_FFWD ?
    {0x5f, KEY_NEXT},       // CMD_NEXT_FILE ?
    {0x5e, KEY_PAUSE},      // CMD_PAUSE ?
    {0x5d, KEY_STOP},       // CMD_STOP ?

    {0x56, KEY_DELETE},     // CMD_REPEAT ?
    {0x02, KEY_INFO},       // CMD_SUBTITLE ?
    {0x13, KEY_SLEEP},      // CMD_NICAM ?
    {0x53, KEY_CAPTION},    // CMD_DISPLAY
    {0x52, KEY_EPG},        // CMD_liyin
    {0x12, KEY_FREEZE},     // CMD_FREEZE


    {0x56, KEY_CARD_READER},// CMD_CARD_READER

};

static struct  venus_key_table tv015_ir_aoc_tv_key_table = {
    .keys = tv015_ir_aoc_tv_keys,
    .size = ARRAY_SIZE(tv015_ir_aoc_tv_keys),
};

static struct venus_key tv015_ir_fac_tv_keys[] = {
//  {0x01, KEY_POWER},

    {0x33, KEY_0},
    {0x0F, KEY_1},
    {0x12, KEY_2},
    {0x4A, KEY_3},
    {0x30, KEY_4},
    {0x10, KEY_5},
    {0x11, KEY_6},
    {0x32, KEY_7},
    {0x35, KEY_8},
    {0x36, KEY_9},
    {0x22, KEY_3D_MODE},        //KEY_TPVFAC_2D3D
    {0x56, KEY_CHANNELUP},      //KEY_TPVFAC_CH_UP
    {0x55, KEY_CHANNELDOWN},    //KEY_TPVFAC_CH_DOWN
    {0x21, KEY_MENU},           //KEY_TPVFAC_MENU
    {0x37, KEY_MUTE},           //KEY_TPVFAC_MUTE
    {0x26, KEY_UP},             //KEY_TPVFAC_UP
    {0x27, KEY_DOWN},           //KEY_TPVFAC_DOWN
    {0x0E, KEY_ENTER},          //KEY_TPVFAC_OK

    //Add TPVFactoryIrDA Key already exist
    //{0x7B, KEY_FACTORY_VGA},  //
    //{0x02, KEY_FACTORY_HDMI1},

    //Add New TPVFactoryIrDA Key
    {0x6D, KEY_TPVFAC_TEST1},
    {0x92, KEY_TPVFAC_TEST2},
    {0x73, KEY_TPVFAC_CLK},
    {0x5F, KEY_TPVFAC_VOL_MAX},
    {0x60, KEY_TPVFAC_VOL_BUZZ},
    {0x5D, KEY_TPVFAC_VOL_L},
    {0x5E, KEY_TPVFAC_VOL_R},
    {0x4B, KEY_TPVFAC_CC_TT},
    {0x54, KEY_TPVFAC_B_I},
    {0x57, KEY_TPVFAC_CH_SCAN},
    {0x6B, KEY_TPVFAC_PRE_CH},
    {0x3F, KEY_TPVFAC_ADTV},
    {0x5A, KEY_TPVFAC_RST},
    {0x3E, KEY_TPVFAC_FAC},
    {0x50, KEY_TPVFAC_CSM},
    {0x62, KEY_TPVFAC_PATTERN},
    {0x03, KEY_TPVFAC_CTC},
    //{0x56, KEY_TPVFAC_CH_UP},
    //{0x55, KEY_TPVFAC_CH_DOWN},
    //{0x21, KEY_TPVFAC_MENU},
    //{0x37, KEY_TPVFAC_MUTE},
    //{0x26, KEY_TPVFAC_UP},
    //{0x27, KEY_TPVFAC_DOWN},
    //{0x0E, KEY_TPVFAC_OK},
    {0x46, KEY_TPVFAC_PIC},
    {0x53, KEY_TPVFAC_AUDIO},
    //{0x22, KEY_TPVFAC_2D3D},
    {0x23, KEY_TPVFAC_ARC},
    {0x24, KEY_TPVFAC_CI},
    {0x51, KEY_TPVFAC_VIRGIN},
    {0x00, KEY_TPVFAC_CVBS},
    {0x01, KEY_TPVFAC_YPBPR},
    {0x02, KEY_TPVFAC_HDMI},
    {0x7B, KEY_TPVFAC_VGA},
    {0x72, KEY_TPVFAC_CLONE},
    {0x34, KEY_TPVFAC_DCR},
    {0x31, KEY_TPVFAC_ADC},
    {0x0D, KEY_TPVFAC_BLK},
    {0x69, KEY_TPVFAC_WP},
    {0x25, KEY_TPVFAC_LS},
    {0x70, KEY_TPVFAC_USB},
    {0x71, KEY_TPVFAC_RJ45},
    {0x28, KEY_TPVFAC_RS232},
    //{0x33, KEY_TPVFAC_0},
    //{0x0F, KEY_TPVFAC_1},
    //{0x12, KEY_TPVFAC_2},
    //{0x4A, KEY_TPVFAC_3},
    //{0x30, KEY_TPVFAC_4},
    //{0x10, KEY_TPVFAC_5},
    //{0x11, KEY_TPVFAC_6},
    //{0x32, KEY_TPVFAC_7},
    //{0x35, KEY_TPVFAC_8},
    //{0x36, KEY_TPVFAC_9},
};

static struct  venus_key_table tv015_ir_fac_tv_key_table = {
    .keys = tv015_ir_fac_tv_keys,
    .size = ARRAY_SIZE(tv015_ir_fac_tv_keys),
};

static struct venus_key tv015_ir_rc6_tv_keys[] = {
    {0x0C, KEY_POWER},

    {0x00, KEY_0},
    {0x01, KEY_1},
    {0x02, KEY_2},
    {0x03, KEY_3},
    {0x04, KEY_4},
    {0x05, KEY_5},
    {0x06, KEY_6},
    {0x07, KEY_7},
    {0x08, KEY_8},
    {0x09, KEY_9},

    {0x4C, KEY_CHANNELUP},
    {0x20, KEY_CHANNELUP},
    {0x4D, KEY_CHANNELDOWN},
    {0x21, KEY_CHANNELDOWN},
    {0x10, KEY_VOLUMEUP},   // CMD_VOL_UP
    {0x11, KEY_VOLUMEDOWN}, // CMD_VOL_DOWN
    {0x40, KEY_MENU},       // CMD_MENU
    {0x0D, KEY_MUTE},

    {0x38, KEY_SOURCE},     // CMD_SOURCE
    {0x54, KEY_HOME},       // CMD_GUIDE
    {0x58, KEY_UP},
    {0x59, KEY_DOWN},
    {0x5A, KEY_LEFT},
    {0x5B, KEY_RIGHT},
    {0x5C, KEY_ENTER},      // CMD_ENTER
    //{0x12, KEY_ENTER},    // ?
    //{0x47, KEY_DELETE},   // ?
    //{0x70, KEY_JUMP},     // CMD_JUMP
    {0x0A, KEY_BACK},       // CMD_RETURN
    {0x6D, KEY_RED},        // CMD_OPTION_RED
    {0x6E, KEY_GREEN},      // CMD_OPTION_GREEN ?
    {0x6F, KEY_YELLOW},     // CMD_OPTION_YELLOW ?
    {0x70, KEY_BLUE},       // CMD_OPTION_BLUE
    {0xCC, KEY_EPG},        // CMD_EPG

    //{0x13, KEY_SLEEP},
    {0xF5, KEY_DISPLAY},    // CMD_DISPLAY
    {0x0F, KEY_INFO},       // ?
    {0xD2, KEY_LIST},
    {0x2C, KEY_PLAY},
    {0x31, KEY_STOP},
    {0x30, KEY_PAUSE},
    {0x2B, KEY_REWIND},     // CMD_FRWD
    {0x28, KEY_FASTFORWARD},// CMD_FFWD
    {0xBF, KEY_SETUP},
    {0xB4, KEY_SEARCH},
    //{0x03, KEY_VIDEO},
    //{0x52, KEY_AUDIO},
    //{0x56, KEY_CARD_READER},  // CMD_CARD_READER
};

static struct  venus_key_table tv015_ir_rc6_tv_key_table = {
    .keys = tv015_ir_rc6_tv_keys,
    .size = ARRAY_SIZE(tv015_ir_rc6_tv_keys),
};
#endif

#if defined(CONFIG_RTK_KDRV_TV005_IR)
static struct venus_key tv005_keys[] = {
    {0x14, KEY_SOURCE}, // VIDEO INPUT
    {0x12, KEY_POWER},  // POWER
    {0x44, KEY_TV}, // ???
    {0x59, KEY_PICTURE_MODE},   // PICTURE SIZE
    {0x0c, KEY_SUBTITLE},   // SUBTITLE
    {0x13, KEY_LANGUAGE},   // STEREO or DUAL
    {0x01, KEY_1},
    {0x02, KEY_2},
    {0x03, KEY_3},
    {0x04, KEY_4},
    {0x05, KEY_5},
    {0x06, KEY_6},
    {0x07, KEY_7},
    {0x08, KEY_8},
    {0x09, KEY_9},
    {0x47, KEY_LIST},   // CHANNEL LIST
    {0x00, KEY_0},
    {0x17, KEY_TEXT},   // TELETEXT
    {0x1a, KEY_VOLUMEUP},
    {0x1e, KEY_VOLUMEDOWN},
    {0x16, KEY_INFO},   // i+ or INDEX
    {0x10, KEY_MUTE},
    {0x45, KEY_PROGRAM},    // ???
    {0x1b, KEY_CHANNELUP},  // P ^
    {0x1f, KEY_CHANNELDOWN},    // P v
    {0x5b, KEY_MENU},
    {0x63, KEY_SHORTCUT},   // QUICK
    {0x19, KEY_UP},
    {0x1d, KEY_DOWN},
    {0x42, KEY_LEFT},
    {0x40, KEY_RIGHT},
    {0x21, KEY_ENTER},  // OK
    {0x64, KEY_BACK},   // BACK
    {0x43, KEY_EXIT},   // EXIT
    {0x48, KEY_RED},
    {0x49, KEY_GREEN},
    {0x4a, KEY_YELLOW},
    {0x4b, KEY_BLUE},
    {0x62, KEY_AUDIO},  // ???
    {0x68, KEY_STOP},   // STOP
    {0x67, KEY_PLAY},   // PLAY
    {0x22, KEY_PAUSE},  // PAUSE or STEP or STILL
    {0x54, KEY_PREVIOUS},   // SKIP - or REVEAL or |<<
    {0x53, KEY_HOLD},   // REW or HOLD
    {0x0d, KEY_ZOOM},   // FF or FULL-TOP-BOTTOM
    {0x15, KEY_NEXT},   // SKIP + or TIME or TXCL or >>|
    {0x34, KEY_HOME},
};

static struct  venus_key_table tv005_key_table = {
    .keys = tv005_keys,
    .size = ARRAY_SIZE(tv005_keys),
};
#endif

#if defined(CONFIG_RTK_KDRV_TV002_IR)
static struct sony_key tv002_keys[] = {
    {0x1, 0x15, KEY_POWER}, // POWER
    {0x1, 0x25, KEY_SOURCE},     // VIDEO INPUT
    {0x1, 0x33, KEY_RIGHT},
    {0x1, 0x34, KEY_LEFT},
    {0x1, 0x74, KEY_UP},
    {0x1, 0x75, KEY_DOWN},
    {0x1, 0x60, KEY_HOME},       // HOME MENU
    {0x1, 0x63, KEY_BACK},       // BACK
    {0x1, 0x65, KEY_ENTER},      // OK
    {0x1, 0x00, KEY_1},
    {0x1, 0x01, KEY_2},
    {0x1, 0x02, KEY_3},
    {0x1, 0x03, KEY_4},
    {0x1, 0x04, KEY_5},
    {0x1, 0x05, KEY_6},
    {0x1, 0x06, KEY_7},
    {0x1, 0x07, KEY_8},
    {0x1, 0x08, KEY_9},
    {0x1, 0x09, KEY_0},
    {0x1, 0x10, KEY_CHANNELUP},          // P ^
    {0x1, 0x11, KEY_CHANNELDOWN},        // P v
    {0x1, 0x12, KEY_VOLUMEUP},
    {0x1, 0x13, KEY_VOLUMEDOWN},
    {0x1, 0x14, KEY_MUTE},
    {0x1, 0x3A, KEY_DISPLAY},    // CMD_DISPLAY
    {0x1, 0x3B, KEY_RETUEN_CH},  // CMD_JUMP
    {0x1, 0x3E, KEY_PIC_OFF},    // PICTURE_OFF
    {0x1, 0x0E, KEY_HOME},       // CMD_GUIDE
    {0x1, 0x38, KEY_DISPLAY_RATIO},      // CMD_WIDE
    {0x1, 0x36, KEY_SLEEP},
    {0x1, 0x17, KEY_AUDIO},
    {0x1, 0x24, KEY_TV},
    {0x97, 0x18, KEY_STOP},       // CMD_STOP
    {0x97, 0x19, KEY_PAUSE},      // CMD_PAUSE
    {0x97, 0x1A, KEY_PLAY},
    {0x97, 0x1B, KEY_REWIND},     // CMD_FRWD
    {0x97, 0x1C, KEY_FASTFORWARD},// CMD_FFWD
    {0x97, 0x3C, KEY_PREVIOUS},   // CMD_PREV
    {0x97, 0x3D, KEY_NEXT},
    {0x97, 0x23, KEY_BACK},       // BACK
    {0x97, 0x5B, KEY_HOME},       // CMD_GUIDE
    {0x97, 0x36, KEY_MENU},       // OPTIONS key as DISCOVERY
    {0x97, 0x25, KEY_RED},        // CMD_OPTION_RED
    {0x97, 0x26, KEY_GREEN},      // CMD_OPTION_GREEN
    {0x97, 0x27, KEY_YELLOW},     // CMD_OPTION_YELLOW
    {0x97, 0x24, KEY_BLUE},       // CMD_OPTION_BLUE
    {0x97, 0x28, KEY_SUBTITLE},   // CMD_SUBTITLE
    {0x97, 0x1D, KEY_DOT},        // DOT
    {0x1A, 0x78, KEY_JUMP},       // SCENE key as ACTION MENU key
    {0x1A, 0x73, KEY_MENU},       // Discovery key as menu
    {0x1A, 0x58, KEY_SYNC_MENU},  // SYNC menu key
    {0x1A, 0x55, KEY_JUMP},       // photo frame key as ACTION_MENU key
    {0x1A, 0x7C, KEY_NETFLIX},    // NETFLIX key
    {0xA4, 0x3D, KEY_DISPLAY_RATIO},       // WIDE key
    {0xA4, 0x5B, KEY_EPG},        // Guilde key
    {0x17, 0x3D, KEY_NEXT},
    {0x17, 0x24, KEY_BLUE},
    {0x17, 0x27, KEY_YELLOW},
    {0xC4, 0x4B, KEY_JUMP},       // Action menu
    {0xC4, 0x46, KEY_GOOGLE_PLAY},    // Google TV key
};

static struct  sony_key_table tv002_key_table = {
    .keys = tv002_keys,
    .size = ARRAY_SIZE(tv002_keys),
};

#endif

/*
static struct user_key_data user_key = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
*/
static struct user_key_data rtk_mk5_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

//#if defined(CONFIG_RTK_KDRV_YK_54LU)
static struct user_key_data yk_54lu_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
//#endif
//#if defined(CONFIG_RTK_KDRV_YK_76J)
static struct user_key_data yk_76j_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
//#endif
#if defined(CONFIG_RTK_KDRV_HAIER_IR)
static struct user_key_data haier_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
#endif


#if defined(CONFIG_RTK_KDRV_TV035_IR)
static struct user_key_data konka_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
#endif
//#if defined(CONFIG_RTK_KDRV_TV001_IR)
static struct user_key_data rtk_mk5_2_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
//#endif

//#if defined(CONFIG_RTK_KDRV_ANDROID_OTT)
static struct user_key_data rtk_android_ott_stb_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
//#endif

#if defined(CONFIG_RTK_KDRV_TV015_IR)
static struct user_key_data tv015_ir_aoc_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data tv015_ir_fac_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data tv015_ir_rc6_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
#endif

static struct user_key_data tv005_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data libra_ms_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data jaecs_t118_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data rtk_mk3_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data yk_70lb_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data rtk_mk4_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

static struct user_key_data netg_ms_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};

#ifdef CONFIG_RTK_KDRV_TV030_IR //TCL
static struct user_key_data tcl_user_keys = {
    .key_table = {
        .keys = NULL,
        .size = 0,
    },
    .max_size = 0,
};
#endif

#if defined(CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE)
static unsigned int repeat = 1;
int venus_ir_mouse_init(void)
{
    struct input_dev *input_dev;
    int result;

    input_dev = input_allocate_device();
    if (!input_dev) {
        result = -ENOMEM;
        IR_ERR("venus IR: can't allocate mouse device.\n");
        goto exit;
    }

    data->mouse_dev = input_dev;
    data->mouse_dev->name = "venus_IR_mouse";
    data->mouse_dev->phys = "venus/input1";

    data->mouse_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL) | BIT_MASK(EV_MSC);
    data->mouse_dev->keybit[BIT_WORD(BTN_MOUSE)] = BIT_MASK(BTN_LEFT);
    data->mouse_dev->relbit[0] = BIT_MASK(REL_X) | BIT_MASK(REL_Y);
    data->mouse_dev->mscbit[0] = BIT_MASK(EV_MSC);

    result = input_register_device(data->mouse_dev);
    if (result) {
        IR_ERR("Venus IR: cannot register mouse device.\n");
        goto fail_register_mouse_dev;
    }
    IR_ERR("Venus IR: success to reigster as mouse device\n");

    return 0;

fail_register_mouse_dev:
    input_free_device(data->mouse_dev);

exit:
    return -1;
}

void venus_ir_mouse_cleanup(void)
{
    input_unregister_device(data->mouse_dev);
    input_free_device(data->mouse_dev);
}

int ir_mouse_pointer_speed = 3;
int ir_mouse_pointer_threshold = 16;
int ir_mouse_pointer_timer = 1000;
int ir_mouse_pointer_step = 4;

int start_accel_time = 0;
int click_down = 0;

#ifdef CONFIG_RTK_KDRV_TV005_IR
void venus_ir_mouse_report_event(uint32_t value)
{
    int i, x, y, click, abs_x, abs_y;

    if ((value & 0x0000ffff) == 0x0040) {
        x = 0x7f & (value >> 17);
        y = 0x7f & (value >> 25);
        click = 0x01 & (value >> 16);
        abs_x = x;
        abs_y = y;
        if(x >= 64) {
            abs_x = 0x7f & ~(x - 1);
            x = -abs_x;
        }

        if(y >= 64) {
            abs_y = 0x7f & ~(y - 1);
            y = -abs_y;
        }

        IR_ALERT("(x, y) = (%d, %d), click = %d\n", x, y, click);
        if (ir_mouse_pointer_threshold * ir_mouse_pointer_threshold < abs_x * abs_x + abs_y * abs_y) {
            if (start_accel_time == 0) {
                start_accel_time = jiffies + msecs_to_jiffies(ir_mouse_pointer_timer);
            }

        } else {
            start_accel_time = 0;
        }

        if (start_accel_time != 0 && jiffies >= start_accel_time) {
            x *= ir_mouse_pointer_speed;
            y *= ir_mouse_pointer_speed;
        }


        x /= ir_mouse_pointer_step;
        y /= ir_mouse_pointer_step;
        for (i = 0; i < ir_mouse_pointer_step; i++) {
            input_event(data->mouse_dev, EV_REL, REL_X, x);
            input_event(data->mouse_dev, EV_REL, REL_Y, y);
            input_sync(data->mouse_dev);
            msleep(1);
        }

        if (click == 1 && click_down == 0) {
            input_event(data->mouse_dev, EV_MSC, MSC_SCAN, 0x90001);
            input_event(data->mouse_dev, EV_KEY, BTN_LEFT, 1);
            input_sync(data->mouse_dev);
            click_down = 1;
        }
    }
}

void venus_ir_mouse_report_end(uint32_t value)
{
    start_accel_time = 0;
    if (click_down == 1) {
        input_event(data->mouse_dev, EV_MSC, MSC_SCAN, 0x90001);
        input_event(data->mouse_dev, EV_KEY, BTN_LEFT, 0);
        input_sync(data->mouse_dev);
        click_down = 0;
    }
}

#else
void venus_ir_to_mouse_event(uint32_t x, uint32_t y)
{
    input_event(data->mouse_dev, EV_REL, REL_X, x * repeat);
    input_event(data->mouse_dev, EV_REL, REL_Y, y * repeat);
    input_sync(data->mouse_dev);
}

void venus_ir_to_mouse_click_event(uint32_t down)
{
    input_event(data->mouse_dev, EV_MSC, MSC_SCAN, 0x90001);
    input_event(data->mouse_dev, EV_KEY, BTN_LEFT, down);
    input_sync(data->mouse_dev);
}

void venus_ir_mouse_report_event(uint32_t value)
{
    s32 x = 0;
    s32 y = 0;

    switch(value) {
        case KEY_LEFT:
            IR_DBG("#####[LEFT] repeat: %d\n", repeat);
            x = -ir_mouse_pointer_speed;
            venus_ir_to_mouse_event(x, y);
            break;
        case KEY_RIGHT:
            IR_DBG("#####[RIGHT] repeat: %d\n", repeat);
            x = ir_mouse_pointer_speed;
            venus_ir_to_mouse_event(x, y);
            break;
        case KEY_UP:
            IR_DBG("#####[UP] repeat: %d\n", repeat);
            y = -ir_mouse_pointer_speed;
            venus_ir_to_mouse_event(x, y);
            break;
        case KEY_DOWN:
            IR_DBG("#####[DOWN] repeat: %d\n", repeat);
            y = ir_mouse_pointer_speed;
            venus_ir_to_mouse_event(x, y);
            break;
        case KEY_ENTER:
        case KEY_SELECT:
            IR_DBG("#####[Enter]#####\n");
            venus_ir_to_mouse_click_event(1);
            break;
   }
}

void venus_ir_mouse_report_end(uint32_t value)
{
    if(value == KEY_ENTER || value == KEY_SELECT) {
        IR_DBG("#####[Enter] release event #####\n");
        venus_ir_to_mouse_click_event(0);
    }
}
#endif
#endif

// this is for android o
void venus_ir_init_report_more_key(void)
{
    if(NULL != data)
    {
        set_bit(KEY_VOLUME_UP_ANDROID_O,     data->input_dev->keybit);
        set_bit(KEY_VOLUME_DOWN_ANDROID_O,   data->input_dev->keybit);
        set_bit(KEY_MUTE_ANDROID_O,          data->input_dev->keybit);
    }
    else
        IR_WARNING("fail to init report mode of android o\n");
}

int venus_ir_input_set_input_dev_name(const char *name)
{
#ifdef CONFIG_RTK_KDRV_DYNAMIC_INPUT_DEV_NAME
    if(data == NULL || data->input_dev == NULL ||name == NULL)
        return -1;
    data->input_dev->name = name;
#endif    
    return 0;
}


int venus_ir_input_init(void)
{
    struct input_dev *input_dev;
    int i, result;

    rwlock_init(&intercept_keycode_list.lock);
    INIT_WORK(&intercept_keycode_list.work, ir_intercept_keycode_work);
    setup_timer(&intercept_keycode_list.timer, venus_ir_key_disable_timer_func, 0);

    data = kzalloc(sizeof(*data), GFP_KERNEL);
    if (!data) {
        result = -ENOMEM;
        goto exit;
    }

    input_dev = input_allocate_device();
    if (!input_dev) {
        result = -ENOMEM;
        IR_ERR("venus IR: can't allocate input device.\n");
        goto fail_alloc_input_dev;
    }

    data->input_dev = input_dev;

    data->input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL) | BIT_MASK(EV_MSC) | BIT_MASK(EV_KEY_TCL);
#ifdef CONFIG_RTK_KDRV_DYNAMIC_INPUT_DEV_NAME
    data->input_dev->name = ir_core_get_cur_remote_control_name();
#else
    data->input_dev->name = "mtkinp";
#endif
    data->input_dev->phys = "venus/input0";

    data->input_dev->setkeycode = _venus_ir_setkeycode;
    data->input_dev->getkeycode = _venus_ir_getkeycode;

    data->input_dev->keybit[BIT_WORD(BTN_MOUSE)] = BIT_MASK(BTN_LEFT) | BIT_MASK(BTN_RIGHT) | BIT_MASK(BTN_MIDDLE);
    data->input_dev->relbit[0] = BIT_MASK(REL_X) | BIT_MASK(REL_Y) | BIT_MASK(REL_WHEEL);
    data->input_dev->mscbit[0] = BIT_MASK(EV_MSC);

    // this is for android o
    venus_ir_init_report_more_key();
    for (i = 0; i < rtk_mk5_tv_key_table.size; i++) {
        set_bit(rtk_mk5_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }

#if defined(CONFIG_RTK_KDRV_YK_54LU)
    for (i = 0; i < yk_54lu_key_table.size; i++) {
        set_bit(yk_54lu_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif
#if defined(CONFIG_RTK_KDRV_YK_76J)
    for (i = 0; i < yk_76j_key_table.size; i++) {
        set_bit(yk_76j_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif
#if defined(CONFIG_RTK_KDRV_TV035_IR)
    for (i = 0; i < konka_tv_key_table.size; i++) {
        set_bit(konka_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV001_IR)
    for (i = 0; i < rtk_mk5_2_tv_key_table.size; i++) {
        set_bit(rtk_mk5_2_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#if defined(CONFIG_RTK_KDRV_ANDROID_OTT)
    for (i = 0; i < rtk_android_ott_stb_key_table.size; i++) {
        set_bit(rtk_android_ott_stb_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV015_IR)
    for (i = 0; i < tv015_ir_aoc_tv_key_table.size; i++) {
        set_bit(tv015_ir_aoc_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }

    for (i = 0; i < tv015_ir_fac_tv_key_table.size; i++) {
        set_bit(tv015_ir_fac_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }

    for (i = 0; i < tv015_ir_rc6_tv_key_table.size; i++) {
        set_bit(tv015_ir_rc6_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV005_IR)
    for (i = 0; i < tv005_key_table.size; i++) {
        set_bit(tv005_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV002_IR)
    for (i = 0; i < tv002_key_table.size; i++) {
        set_bit(tv002_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#ifdef CONFIG_RTK_KDRV_TV030_IR //TCL
    for (i = 0; i < tcl_tv_key_table.size; i++) {
        set_bit(tcl_tv_key_table.keys[i].keycode, data->input_dev->keybit);
    }
    rawkey_event = 1;
    /*for (i = 0; i < tcl_tv_factory_key_table.size; i++) {
        set_bit(tcl_tv_factory_key_table.keys[i].keycode, data->input_dev->keybit);
    }*/
    for (i = 1; i <= 0xFF; i++) {
		set_bit(i, data->input_dev->keybit);
	}
    for (i = 0; i < tcl_tv_dvd_key_table.size; i++) {
        set_bit(tcl_tv_dvd_key_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#ifdef CONFIG_RTK_KDRV_HAIER_IR //Haier
    for (i = 0; i < haier_key_tv_table.size; i++) {
        set_bit(haier_key_tv_table.keys[i].keycode, data->input_dev->keybit);
    }
    for (i = 0; i < haier_key_fac_table.size; i++) {
        set_bit(haier_key_fac_table.keys[i].keycode, data->input_dev->keybit);
    }

    for (i = 0; i < haier_key_cvt_table.size; i++) {//lyg,20140325,for CVT remote
        set_bit(haier_key_cvt_table.keys[i].keycode, data->input_dev->keybit);
    }
    for (i = 0; i < haier_key_mtc_table.size; i++) {//lyg,20140403,for MTC remote
        set_bit(haier_key_mtc_table.keys[i].keycode, data->input_dev->keybit);
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV036_10D_IR)
	for (i = 0;i < Hikeen_10D_tv_key_table.size; i++)
	{
		set_bit(Hikeen_10D_tv_key_table.keys[i].keycode,data->input_dev->keybit);
	}
#endif
    for(i = KEY_RESERVER_MIN; i <= KEY_RESERVER_MAX; i++) {
        set_bit(i, data->input_dev->keybit);
    }

    result = input_register_device(data->input_dev);
    if (result) {
        IR_ERR("Venus IR: cannot register input device.\n");
        goto fail_register_input_dev;
    }

    setup_timer(&keyup_timer, venus_ir_input_report_end, 0);

    return 0;

fail_register_input_dev:
    input_free_device(data->input_dev);
fail_alloc_input_dev:
    kfree(data);
exit:
    return -1;
}

void venus_ir_input_cleanup(void)
{

    cancel_work_sync(&intercept_keycode_list.work);
    del_timer_sync(&intercept_keycode_list.timer);

    input_unregister_device(data->input_dev);
    input_free_device(data->input_dev);
    kfree(data);

    _venus_ir_clean_user_keys(&rtk_mk5_user_keys);
//#if defined(CONFIG_RTK_KDRV_YK_54LU)
    _venus_ir_clean_user_keys(&yk_54lu_user_keys);
//#endif
//#if defined(CONFIG_RTK_KDRV_YK_76J)
    _venus_ir_clean_user_keys(&yk_76j_user_keys);
//#endif
#if defined(CONFIG_RTK_KDRV_TV035_IR)
    _venus_ir_clean_user_keys(&konka_user_keys);
#endif
//#if defined(CONFIG_RTK_KDRV_TV001_IR)
    _venus_ir_clean_user_keys(&rtk_mk5_2_user_keys);
    _venus_ir_clean_user_keys(&rtk_android_ott_stb_user_keys);
    _venus_ir_clean_user_keys(&tv005_user_keys);
//#endif
#if defined(CONFIG_RTK_KDRV_TV015_IR)
    _venus_ir_clean_user_keys(&tv015_ir_aoc_user_keys);
    _venus_ir_clean_user_keys(&tv015_ir_fac_user_keys);
    _venus_ir_clean_user_keys(&tv015_ir_rc6_user_keys);
#endif
    _venus_ir_clean_user_keys(&libra_ms_user_keys);
    _venus_ir_clean_user_keys(&jaecs_t118_user_keys);
    _venus_ir_clean_user_keys(&rtk_mk3_user_keys);
    _venus_ir_clean_user_keys(&yk_70lb_user_keys);
    _venus_ir_clean_user_keys(&rtk_mk4_user_keys);
    _venus_ir_clean_user_keys(&netg_ms_user_keys);
#ifdef CONFIG_RTK_KDRV_TV030_IR //TCL
    _venus_ir_clean_user_keys(&tcl_user_keys);
#endif


#ifdef CONFIG_RTK_KDRV_HAIER_IR //haier
    _venus_ir_clean_user_keys(&haier_user_keys);
#endif



}

void schedule_venus_ir_keyup_handler(void)
{
    keyup_jiffies = jiffies + msecs_to_jiffies(ir_poll_interval);
    mod_timer(&keyup_timer, keyup_jiffies);
}

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE
inline int venus_ir_is_simulated_key(u32 key)
{
    if (key != KEY_LEFT && key != KEY_RIGHT && key != KEY_UP && key != KEY_DOWN && key != KEY_ENTER && key != KEY_SELECT) {
        IR_DBG("The key is not simulated key\n");
        return 0;
    }

    return 1;
}
#endif

///////////////////////////////report mode////////////////////////////////////
static void venus_ir_input_report_mode_normal(u32 keycode,u32 custcode)
{
    if(!data->dataRepeat)
    {
        if(!rawkey_event)
        {
            input_report_key(data->input_dev, keycode, 1);
        }
        else
        {
            input_report_key(data->input_dev, custcode, 1);
            input_report_key(data->input_dev, keycode, 1);
            IR_DBG("%s: %04x %04x\n", __func__, custcode, keycode);
        }
        input_sync(data->input_dev);
        data->dataRepeat = 1;
    }
    else if(repeat_event)
    {
        if(!rawkey_event)
        {
            input_event(data->input_dev, EV_KEY, keycode, 2);
        }
        else
        {
            input_event(data->input_dev, EV_KEY, custcode, 2);
            input_event(data->input_dev, EV_KEY, keycode, 2);
        }
        input_sync(data->input_dev);
    }
}

// this is for android o
static void venus_ir_input_report_more_key(u32 keycode,u32 custcode,int isDown)
{
    isDown = isDown?1:0;
    // volume up
    if(KEY_VOLUMEUP == data->keycode)
    {
        IR_DBG("VOLUME_UP_ANDROID_O = 0x%08x\n", KEY_VOLUME_UP_ANDROID_O);
        input_report_key(data->input_dev, KEY_VOLUME_UP_ANDROID_O, isDown);
        input_sync(data->input_dev);
    }
    // volume down
    else if (KEY_VOLUMEDOWN == data->keycode)
    {
        IR_DBG("VOLUME_DOWN_ANDROID_O = 0x%08x\n", KEY_VOLUME_DOWN_ANDROID_O);
        input_report_key(data->input_dev, KEY_VOLUME_DOWN_ANDROID_O, isDown);
        input_sync(data->input_dev);
    }
    else if(KEY_MUTE == data->keycode)
    {
        IR_DBG("MUTE_ANDROID_O = 0x%08x\n", KEY_MUTE_ANDROID_O);
        input_report_key(data->input_dev, KEY_MUTE_ANDROID_O, isDown);
        input_sync(data->input_dev);
    }
}
static void venus_ir_input_report_mode_TCL(u32 keycode)
{
#if defined(CONFIG_RTK_KDRV_TV030_IR)
    if(is_factory_customer_code(custom_code_tcl)){
        if(factory_key_curtime == 0){
            IR_DBG("first time press factory_key_curtime == 0 \n");
            IR_DBG("Venus IR: -report factory key %u 0x%x\n", keycode,((custom_code_tcl << 16) | 1));
            factory_key_curtime = _IR_Input_GetSystemTime();
            factory_key_pretime = factory_key_curtime;
            input_event(data->input_dev, EV_KEY_TCL, keycode, ((custom_code_tcl << 16) | 1));
        }
        else
        {
            factory_key_curtime = _IR_Input_GetSystemTime();
            if((factory_key_curtime - factory_key_pretime) < FACTORY_KEY_TIMEOUT) //no timeout
            {
                if(factory_precustomer_code == custom_code_tcl && factory_prekeycode == keycode){// the same key action
                    IR_DBG(" ignore the repeat key action between 500ms\n");
                    factory_key_pretime = factory_key_curtime;
                }else{
                    IR_DBG("factory precustomer_code = 0x%x , prekeycode = 0x%x \n",factory_precustomer_code,factory_prekeycode);
                    IR_DBG("Venus IR: -report factory key %d 0x%x\n", keycode,((custom_code_tcl << 16) | 1));
                    input_event(data->input_dev, EV_KEY_TCL, keycode, ((custom_code_tcl << 16) | 1));
                    factory_key_pretime = factory_key_curtime;
                }
            }
            else
            {
                IR_DBG("Venus IR: -report factory key %d 0x%x\n", keycode,((custom_code_tcl << 16) | 1));
                input_event(data->input_dev, EV_KEY_TCL, keycode, ((custom_code_tcl << 16)) | 1);
                factory_key_pretime = factory_key_curtime;
            }
        }
        factory_precustomer_code = custom_code_tcl;
        factory_prekeycode = keycode;
        input_sync(data->input_dev);
    }else if(!data->dataRepeat){
        IR_DBG("Venus IR: -report key down %u\n", keycode);
        input_report_key(data->input_dev, keycode, 1);
        input_sync(data->input_dev);
        data->dataRepeat = 1;
    }
    
#endif
}
void venus_ir_input_report_key(uint32_t repkey)
{
    u32 keycode = 0;
    u32 custcode = 0;

    if(ir_poll_enable) {
        if (data->prev_keycode && data->prev_keycode != data->keycode && timer_pending(&keyup_timer)) {
            IR_DBG( "[%s,%d,%s]keyup_jiffies==%u,jiffies==%u,keycode_up==%08x\n",__FILE__,__LINE__,__FUNCTION__,keyup_jiffies,jiffies,data->prev_keycode);
            input_report_key(data->input_dev, data->prev_keycode, 0);
            input_sync(data->input_dev);
            data->prev_keycode = 0;
            data->dataRepeat = 0;
        }   
    }

    if(!rawkey_event) {
        keycode = data->keycode;
    } else {
        custcode = (data->scancode) & 0xffff;
        keycode = ((data->scancode) >> 16) & 0xffff;
    }

    if(ir_mute_flag) {
        if(!data->dataRepeat)
            data->dataRepeat = 1;
        return;
    }
        
    if(unlikely(intercept_keycode_list.keycode_array_not_empty)) {
        u32 flags = 0;
        if(ir_query_keycode_from_list(&intercept_keycode_list, data->keycode, &flags)) {
            if(!data->dataRepeat) {
                if(flags & KEYCODE_INTERCEPT_DISABLE_IRDA_DECODE) {
                    ir_decode_key_on_off(OFF);
                    mod_timer(&intercept_keycode_list.timer, jiffies + MAX_IR_DISABLE_KEY_TIME);
                }
                schedule_work(&intercept_keycode_list.work);
                data->dataRepeat = 1;
            }
            return;
        }
    }     
    
    if (keycode <= 0 && custcode <=0)
        return;
    
#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE
    if(ir_to_mouse && venus_ir_is_simulated_key(keycode)) {
        venus_ir_mouse_report_event(keycode);
        repeat++;
        return;
    }
#endif

    IR_DBG("ir_report_mode= %d %s\n"
            ,ir_report_mode
            ,ir_report_mode_list[ir_report_mode].name);
    // this is for android o
    if(ir_is_upload_more_key)
        venus_ir_input_report_more_key(keycode,custcode,1);
    switch(ir_report_mode)
    {
    case IRDA_REPORT_MODE_NORMAL:
        venus_ir_input_report_mode_normal(keycode,custcode);
        break;
    case IRDA_REPORT_MODE_TCL:
        venus_ir_input_report_mode_TCL(data->keycode);
        break;
    default:
        IR_ERR("there is no input report mode\n");
        break;
    }

}

void venus_ir_gen_keyupdown_event(uint32_t keycode)
{
    input_report_key(data->input_dev, keycode, 1);
    input_sync(data->input_dev);
    input_report_key(data->input_dev, keycode, 0);
    input_sync(data->input_dev);
}

#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
void venus_ir_input_report_end(unsigned long _data);
void voice_dev_input_report_key(uint32_t value)
{
    input_report_key(data->input_dev, value, 1);
    input_sync(data->input_dev);
    input_report_key(data->input_dev, value, 0);
    input_sync(data->input_dev);
}
u32 voice_dev_cmd_to_keycode(uint32_t value)
{
    u32 scancode, keycode = 0;
    int i;
    if(value >= 16)
        return 0;
    switch(value) {
        case 0x0:
            keycode = KEY_ALC_HELLO_MIDOLI;
            break;
        case 0x3:
            keycode = KEY_ALC_GO_RIGHT;
            break;
        case 0x4:
            keycode = KEY_ALC_GO_LEFT;
            break;
        case 0x7:
            keycode = KEY_ALC_STOP;
            break;
        case 0x8:
            keycode = KEY_ALC_HELLO_MENU;
            break;
        case 0x9:
            keycode = KEY_ALC_HELLO_VOLUME_LOUDER;
            break;
        case 0xa:
            keycode = KEY_ALC_HELLO_VOLUME_DOWN;
            break;
        case 0xb:
            keycode = KEY_ALC_GO_PREVIOUS;
            break;
        case 0xc:
            keycode = KEY_ALC_GO_NEXT;
            break;
        case 0xd:
            keycode = KEY_ALC_CONFIRM;
            break;
        case 0xe:
            keycode = KEY_ALC_START_PLAY;
            break;
        case 0xf:
            keycode = KEY_ALC_PAUSE;
            break;
        default:
            keycode = 0;
    }
    if(keycode != 0) {
        data->keycode = keycode;
        return data->keycode;
    }
    return 0;
}
#endif
u32 venus_ir_scancode_to_keycode(uint32_t value)
{
    u32 scancode, customer_code;
    int i;

    data->scancode = value;

    if(bUseUserTable) {
        struct user_key_data *pUserData;
        _venus_ir_get_user_data(value, &pUserData, &scancode);
        if(pUserData == NULL) {
            return 0;
        }

        if(pUserData->key_table.size > 0 && pUserData->key_table.keys) {
            IR_DBG("[report_key]search in user mappint table");
            IR_DBG("[report_key]table size=%d", pUserData->key_table.size);
            for(i = 0; i < pUserData->key_table.size; i++) {
                IR_DBG("[report_key]i=%d, scancode=%d, keycode=%d",
                       i, pUserData->key_table.keys[i].scancode, pUserData->key_table.keys[i].keycode);
                if(scancode == pUserData->key_table.keys[i].scancode)   {
                    // mapping found, report key and return
                    data->prev_keycode = data->keycode;
                    data->keycode = pUserData->key_table.keys[i].keycode;
                    IR_DBG("Venus IR:ALL report key 0x%x %d\n", scancode, data->keycode);
                    return data->keycode;
                }
            }
        }
        // no mapping found, just return
        return 0;
    }

#if defined(CONFIG_RTK_KDRV_TV030_IR )//TCL

/*********************************** TCL RCA *******************************************/
    if (((~((value & 0xfff000) >> 12)) & 0x000fff) == (value & 0x000fff)) {
        scancode = (value & 0x0000ff);
        custom_code_tcl = ((value & 0x00000f00) >> 8);
        printk("custom_code_tcl:  0x%x\n", custom_code_tcl);
        if(is_factory_customer_code(custom_code_tcl)){
            data->prev_keycode = data->keycode;
            data->keycode = scancode;
            IR_DBG("Venus IR: -report key 0x%x %d\n", scancode, data->keycode);
            return data->keycode;
        }
        printk("Venus IR: Data 0x%x\n", scancode);
        for (i = 0; i < tcl_tv_key_table.size; i++) {
            if (scancode == tcl_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = tcl_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }

/*********************************** TCL NEC *******************************************/
	custom_code_tcl = 0x00;
	
    if((value & 0x0000ffff) == 0x9966) {
	scancode = ((value & 0x00ff0000) >> 16);
	printk("Venus IR: Data 0x%x\n", scancode);
        for (i = 0; i < tcl_tv_key_table.size; i++) {
            if (scancode == tcl_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = tcl_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
	
    for (i = 0; i < tcl_tv_dvd_key_table.size; i++) {
		if (value == tcl_tv_dvd_key_table.keys[i].scancode) {
		    data->prev_keycode = data->keycode;
		    data->keycode = tcl_tv_dvd_key_table.keys[i].keycode;
		    IR_DBG("Venus IR: -report key 0x%x %d\n", scancode, data->keycode);
		    return data->keycode;
		}
   }
	
	if(is_factory_customer_code(value & 0x000000ff)){
		custom_code_tcl = (value & 0x000000ff);
		scancode = (value & 0x00ff0000) >> 16;
		data->prev_keycode = data->keycode;
		data->keycode = scancode;
		IR_DBG("Venus IR: -report key 0x%x %d\n", scancode, data->keycode);
		return data->keycode;		
	}
#endif

    if ((value & 0x0000ffff) == RTK_MK5_CUSTOMER_CODE) {
        scancode = (value & 0x00ff0000) >> 16;
        for (i = 0; i < rtk_mk5_tv_key_table.size; i++) {
            if (scancode == rtk_mk5_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = rtk_mk5_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR:  -RTK_MK5 report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }

#if defined(CONFIG_RTK_KDRV_YK_54LU)
    if ((value & 0x0000ffff) == YK_54LU_CUSTOMER_CODE) {
        scancode = (value & 0xffff0000) >> 16;
        for (i = 0; i < yk_54lu_key_table.size; i++) {
            if (scancode == yk_54lu_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = yk_54lu_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -YK_54LU report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif
#if defined(CONFIG_RTK_KDRV_YK_76J)
    if ((value & 0x0000ffff) == YK_76J_CUSTOMER_CODE) {
        scancode = (value & 0xffff0000) >> 16;
        for (i = 0; i < yk_76j_key_table.size; i++) {
            if (scancode == yk_76j_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = yk_76j_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -YK_76J report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif

//haier

#if defined(CONFIG_RTK_KDRV_HAIER_IR)
    if ((value & 0x0000ffff) == 0xe7e7) {
        scancode = (value & 0xffff0000) >> 16;


        /*
                for (i = 0; i < haier_key_tv_table.size; i++) {

                    IR_DBG("-----Haier-----Venus IR: report key 0x%x %d %d\n", haier_key_tv_table.keys[i].scancode, haier_key_tv_table.keys[i].keycode,i);

                }
        */



        for (i = 0; i < haier_key_tv_table.size; i++) {
            if (scancode == haier_key_tv_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = haier_key_tv_table.keys[i].keycode;

                IR_DBG("-----Haier-----Venus IR: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    } else if ((value & 0x0000ffff) == 0xf7df) {
        scancode = (value & 0xffff0000) >> 16;
        for (i = 0; i < haier_key_fac_table.size; i++) {
            if (scancode == haier_key_fac_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = haier_key_fac_table.keys[i].keycode;

                IR_DBG("-----Haier--Fac---Venus IR: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    } else if ((value & 0x0000ffff) == 0x6f77) { //lyg,20140325,for CVT remote
        scancode = (value & 0xffff0000) >> 16;
        for (i = 0; i < haier_key_cvt_table.size; i++) {
            if (scancode == haier_key_cvt_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = haier_key_cvt_table.keys[i].keycode;

                IR_DBG("-----Haier--CVT---Venus IR: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    } else if ((value & 0x0000ffff) == 0x20ff) { //lyg,20140325,for MTC remote
        scancode = (value & 0xffff0000) >> 16;
        for (i = 0; i < haier_key_mtc_table.size; i++) {
            if (scancode == haier_key_mtc_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = haier_key_mtc_table.keys[i].keycode;

                IR_DBG("-----Haier--MTC---Venus IR: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
    IR_DBG("IR: report key 0x%x %d, value=0x%x\n", scancode, data->keycode, value);
#endif


#if defined(CONFIG_RTK_KDRV_TV001_IR)
    if ((value & 0x0000ffff) == RTK_MK5_2_CUSTOMER_CODE) {
        scancode = (value & 0x00ff0000) >> 16;
        for (i = 0; i < rtk_mk5_2_tv_key_table.size; i++) {
            if (scancode == rtk_mk5_2_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = rtk_mk5_2_tv_key_table.keys[i].keycode;
                IR_DBG("RTK_MK5_2 Venus IR: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif


#if defined(CONFIG_RTK_KDRV_ANDROID_OTT)
    if ((value & 0x0000ffff) == RTK_ANDROID_OTT_CUSTOMER_CODE) {
        scancode = (value & 0xffff0000) >> 16;
        for (i = 0; i < rtk_android_ott_stb_key_table.size; i++) {
            if (scancode == rtk_android_ott_stb_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = rtk_android_ott_stb_key_table.keys[i].keycode;
                IR_DBG("RTK_ANDROID_OTT Venus IR: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif



#if defined(CONFIG_RTK_KDRV_TV035_IR)
    if ((value & 0x0000ff00) == KONKA_CUSTOMER_CODE && ((value & 0xffff0000) >> 16) == 0 ) {
        scancode = (value & 0x000000ff);
        IR_DBG("Venus IR: -konka: scancode is 0x%x\n", scancode);
        for (i = 0; i < konka_tv_key_table.size; i++) {
            if (scancode == konka_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = konka_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -konka: report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV036_10D_IR)
	if ((value & 0x0000ffff) == TV036_10D_CUSTOMER_CODE) {
			scancode = (value & 0x00ff0000) >> 16;
				for (i = 0; i < Hikeen_10D_tv_key_table.size; i++) {
					if (scancode == Hikeen_10D_tv_key_table.keys[i].scancode) {
					       data->prev_keycode = data->keycode;
						data->keycode = Hikeen_10D_tv_key_table.keys[i].keycode;
						printk(KERN_ALERT "HIKEEN_10D Venus IR: report key 0x%x %d\n", scancode, data->keycode);
						return data->keycode;
					}
				}
		}
#endif

#if defined(CONFIG_RTK_KDRV_TV036_KTSG45_IR)
	if ((value & 0x0000ffff) == TV036_KTSG45_COUSTOM_CODE)
	{
		scancode = (value & 0x00ff0000) >> 16;
		for (i = 0; i < ktsg45_tv_key_table.size; i++) 
		{
			if (scancode == ktsg45_tv_key_table.keys[i].scancode)
			{
				data->prev_keycode = data->keycode;
				data->keycode = ktsg45_tv_key_table.keys[i].keycode;
				IR_DBG(KERN_ALERT "Venus IR: ktsg45 report key 0x%x %d\n", scancode, data->keycode);
				return data->keycode;
			}
		}
	}
#endif

#if defined(CONFIG_RTK_KDRV_TV001_IR)
    if ((value & 0x0000ffff) == RTK_MK5_2_CUSTOMER_CODE) {
        scancode = (value & 0x00ff0000) >> 16;
        for (i = 0; i < rtk_mk5_2_tv_key_table.size; i++) {
            if (scancode == rtk_mk5_2_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;				
                data->keycode = rtk_mk5_2_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: RTK_MK5_2 report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV015_IR)
    if ((value & 0x0000ffff) == TV015_IR_AOC_CUSTOMER_CODE) {
        scancode = (value & 0x00ff0000) >> 16;
        for (i = 0; i < tv015_ir_aoc_tv_key_table.size; i++) {
            if (scancode == tv015_ir_aoc_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = tv015_ir_aoc_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: TV015_IR_AOC report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }

    if (value == TV015_IR_FAC_TEST_CODE1) {
        scancode = value;
        data->prev_keycode = data->keycode;
        data->keycode = KEY_TPVFAC_TEST1;
        IR_DBG("Venus IR: TV015_IR_FAC test key 0x%x %d\n", scancode, data->keycode);
        return data->keycode;
    } else if (value == TV015_IR_FAC_TEST_CODE2) {
        scancode = value;
        data->prev_keycode = data->keycode;
        data->keycode = KEY_TPVFAC_TEST2;
        IR_DBG("Venus IR: TV015_IR_FAC test key 0x%x %d\n", scancode, data->keycode);
        return data->keycode;
    } else if ((value & 0x0000ffff) == TV015_IR_FAC_CUSTOMER_CODE) {
        scancode = (value & 0x00ff0000) >> 16;
        for (i = 0; i < tv015_ir_fac_tv_key_table.size; i++) {
            if (scancode == tv015_ir_fac_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = tv015_ir_fac_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: TV015_IR_FAC report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }

    if ((value & 0x00000000) == TV015_IR_RC6_CUSTOMER_CODE) {
        scancode = (value & 0x000000ff);
        for (i = 0; i < tv015_ir_rc6_tv_key_table.size; i++) {
            if (scancode == tv015_ir_rc6_tv_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = tv015_ir_rc6_tv_key_table.keys[i].keycode;
                IR_DBG("Venus IR: TV015_IR_RC6 report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif

#if defined(CONFIG_RTK_KDRV_TV005_IR)
    customer_code = value & 0x0000ffff;
    if ((customer_code == TV005_CUSTOMER_CODE1) || (customer_code == TV005_CUSTOMER_CODE2) || (customer_code == TV005_CUSTOMER_CODE3)) {
        scancode = (value & 0x00ff0000) >> 16;
        for (i = 0; i < tv005_key_table.size; i++) {
            if (scancode == tv005_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = tv005_key_table.keys[i].keycode;
                IR_DBG("Venus IR: TV005 report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif
#if defined(CONFIG_RTK_KDRV_TV002_IR)
#if defined(CONFIG_RTK_KDRV_TV002_IR_RAW_MODE)
    customer_code = (value >> 7) & 0xfff;
    scancode = value & 0x0000007f;
#else
    customer_code = (value >> 27) & 0xfff;
    scancode = (value & 0x07f00000) >> 20;
#endif
    for (i = 0; i < tv002_key_table.size; i++) {
        if (customer_code == tv002_key_table.keys[i].custcode  && scancode == tv002_key_table.keys[i].datacode) {
            data->prev_keycode = data->keycode;
            data->keycode = tv002_key_table.keys[i].keycode;
            IR_DBG("Venus IR: TV002 report key 0x%x %d\n", scancode, data->keycode);
            return data->keycode;
        }
    }

    if(i == tv002_key_table.size) {
        IR_DBG("###Venus IR: Not TV002 report key 0x%x %x###\n", customer_code, scancode);
    }

#endif
#if defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE)
    if ((value & 0x00000003) == YK_54LU_SHUTTLE_CUSTOMER_CODE) {
        scancode = (value & 0x000000e0) >> 5;
        for (i = 0; i < yk_54lu_key_table.size; i++) {
            if (scancode == yk_54lu_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = yk_54lu_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -YK_54LU_SHUTTLE report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif
#if defined(CONFIG_RTK_KDRV_YK_76J_SHUTTLE)
    if ((value & 0x00000003) == YK_76J_SHUTTLE_CUSTOMER_CODE) {
        scancode = (value & 0x000000e0) >> 5;
        for (i = 0; i < yk_76j_key_table.size; i++) {
            if (scancode == yk_76j_key_table.keys[i].scancode) {
                data->prev_keycode = data->keycode;
                data->keycode = yk_76j_key_table.keys[i].keycode;
                IR_DBG("Venus IR: -YK_76J_SHUTTLE report key 0x%x %d\n", scancode, data->keycode);
                return data->keycode;
            }
        }
    }
#endif
    return 0;
}

int venus_ir_reverse_bit(u32* scancode)
{
#define CHAR_BIT_SIZE       8
    unsigned int v = *scancode;     // input bits to be reversed
    unsigned int r = v & 1; // r will be reversed bits of v; first get LSB of v
    int s = sizeof(v)*CHAR_BIT_SIZE - 1; // extra shift needed at end

    for (v >>= 1; v; v >>= 1)
    {
      r <<= 1;
      r |= v & 1;

      s--;
    }
    r <<= s; // shift when v's highest bits are zero
    *scancode = r;
    IR_DBG("reverse 0x%08x\n",r);
    return 0;
}

u32 venus_ir_keycode_to_scancode(uint32_t value)
{
	u32 scancode = 0;
	int i = 0;

	switch(ir_keymap_type) {
#if defined(CONFIG_RTK_KDRV_TV001_IR)
	case IRDA_KEYMAP_TYPE_NEC:
        for (i = 0; i < rtk_mk5_2_tv_key_table.size; i++) {
            if (value == rtk_mk5_2_tv_key_table.keys[i].keycode) {
                scancode = rtk_mk5_2_tv_key_table.keys[i].scancode;
                IR_DBG("RTK_MK5_2 keycode %d to scancode 0x%x\n", value, scancode);
                break;
            }
        }

        scancode = (~scancode & 0xff) << 24 | (scancode & 0xff) << 16 | RTK_MK5_2_CUSTOMER_CODE;
        break;
#endif
#if defined(CONFIG_RTK_KDRV_TV002_IR)
    case IRDA_KEYMAP_TYPE_TV002:
        for (i = 0; i < tv002_key_table.size; i++) {
            if (value == tv002_key_table.keys[i].keycode) {
                IR_DBG("datacode 0x%x, custcode 0x%x\n", tv002_key_table.keys[i].datacode, tv002_key_table.keys[i].custcode);
                scancode = ((tv002_key_table.keys[i].datacode & 0x7f) << 20) | ((tv002_key_table.keys[i].custcode & 0xfff) << 27);
                IR_DBG("scan code=0x%x\n", scancode);
                // because 8051 use hw mode, but driver use raw mode, reverse bits for
                // match key of two protocol
                venus_ir_reverse_bit(&scancode);
                IR_DBG("SONY keycode %d to scancode 0x%x\n", value, scancode);
                break;
            }
        }
        break;
#endif
#if defined(CONFIG_RTK_KDRV_TV030_IR)
    case IRDA_KEYMAP_TYPE_TV030:
        for (i = 0; i < tcl_tv_key_table.size; i++) {
            if (value == tcl_tv_key_table.keys[i].keycode) {
                scancode = tcl_tv_key_table.keys[i].scancode;
                IR_DBG("RCA keycode %d to scancode 0x%x\n", value, scancode);
                scancode = (((~(scancode & 0xfff) & 0xfff) << 12) | scancode);
                IR_INFO("RCA scancode=0x%x\n",scancode);
                break;
            }
        }
        break;
	case IRDA_KEYMAP_TYPE_TV030_NEC:
        for (i = 0; i < tcl_tv_key_table.size; i++) {
            if (value == tcl_tv_key_table.keys[i].keycode) {
                scancode = tcl_tv_key_table.keys[i].scancode;
                IR_DBG("RCA keycode %d to scancode 0x%x\n", value, scancode);
                scancode = (((~(scancode & 0xfff) & 0xfff) << 12) | scancode);
                IR_INFO("RCA scancode=0x%x\n",scancode);
                break;
            }
        }
        scancode = ((~scancode & 0xff) << 24) | ((scancode & 0xff) << 16) | 0x9966;
        break;
#endif
#if defined(CONFIG_RTK_KDRV_TV036_10D_IR)
    case IRDA_KEYMAP_TYPE_TV036_10D:
        for (i = 0; i < Hikeen_10D_tv_key_table.size; i++) {
            if (value == Hikeen_10D_tv_key_table.keys[i].keycode) {
                scancode = Hikeen_10D_tv_key_table.keys[i].scancode;
                scancode = (~scancode & 0xff) << 24 | (scancode & 0xff) << 16 | TV036_10D_CUSTOMER_CODE;
                IR_DBG("tv036 10d keycode %d to scancode 0x%x (0x%x)\n", value,Hikeen_10D_tv_key_table.keys[i].scancode, scancode);
                break;
            }
        }

        break;
#endif
		default:
			IR_DBG("Doesn't support keycode translate to scancode\n");
	}

	return scancode;
}

void venus_ir_keylist_to_scanlist(uint32_t *keylist, uint32_t *scanlist, uint32_t keycnt)
{
	int i = 0;

	for(i = 0; i < keycnt; i++) {
		scanlist[i] = venus_ir_keycode_to_scancode(keylist[i]);
	}
}

static void venus_ir_input_report_end_normal(u32 keycode, u32 custcode)
{
    IR_DBG("%s\n", __func__);
    if(!rawkey_event)
    {
        input_report_key(data->input_dev, keycode, 0);
        input_sync(data->input_dev);
    }
    else
    {
        input_report_key(data->input_dev, custcode, 0);
        input_report_key(data->input_dev, keycode, 0);
        input_sync(data->input_dev);
    }
}
void venus_ir_input_report_end_TCL(u32 keycode)
{
    IR_DBG("roger %s keycode=0x%x\n",__func__,keycode);
#if defined(CONFIG_RTK_KDRV_TV030_IR)
    if(is_factory_customer_code(custom_code_tcl)){
        IR_DBG("====>: report key 0x%x\n", keycode);
        input_event(data->input_dev, EV_KEY_TCL, keycode, ((custom_code_tcl << 16) | 0));
    }else{
        IR_DBG("roger %s keycode=0x%x up\n",__func__,keycode);
        input_report_key(data->input_dev, keycode, 0);
    }
    input_sync(data->input_dev);
#endif
}
void venus_ir_input_report_end(unsigned long _data)
{
    u32 keycode = 0;
    u32 custcode = 0;

    if(!rawkey_event) {
        keycode = data->keycode;
    } else {
        custcode = (data->scancode) & 0xffff;
        keycode = ((data->scancode) >> 16) & 0xffff;
    }

    if(ir_mute_flag) {
        data->dataRepeat = 0;
        data->keycode = 0;
        return;
    }
        
    if(unlikely(intercept_keycode_list.keycode_array_not_empty)) {
        u32 flags = 0;
        if(ir_query_keycode_from_list(&intercept_keycode_list, data->keycode, &flags)) {
            data->dataRepeat = 0;
            data->keycode = 0;
            return;
        }
    }        
    
    if (keycode <= 0 && custcode <= 0)
        return;

#ifdef CONFIG_RTK_KDRV_INPUT_DEVICE_MOUSE
    if(ir_to_mouse && venus_ir_is_simulated_key(keycode)) {
        venus_ir_mouse_report_end(keycode);
        repeat = 1;
        return;
    }
#endif

    // this is for android o
    if(ir_is_upload_more_key)
        venus_ir_input_report_more_key(keycode,custcode,0);

    switch(ir_report_mode)
    {
    case IRDA_REPORT_MODE_NORMAL:
        venus_ir_input_report_end_normal(keycode,custcode);
        break;
    case IRDA_REPORT_MODE_TCL:
        venus_ir_input_report_end_TCL(data->keycode);
        break;
    default:
        IR_ERR("there is no input report mode\n");
        break;
    }
    data->dataRepeat = 0;
    data->keycode = 0;
}

static void _venus_ir_get_user_data(uint32_t value, struct user_key_data **ppUsrData, u32 *pCode)
{

#ifdef CONFIG_RTK_KDRV_TV030_IR
    if (((~((value & 0xfff000) >> 12)) & 0x000fff) == (value & 0x000fff)) {
        *ppUsrData = &tcl_user_keys;
        *pCode = (value & 0x000000ff);
    } else
#endif

        if ((value & 0x0000ffff) == RTK_MK5_CUSTOMER_CODE) {
            IR_DBG("match RTK_MK5_CUSTOMER_CODE");
            *ppUsrData = &rtk_mk5_user_keys;
            *pCode = (value & 0x00ff0000) >> 16;
        } else
//#if defined(CONFIG_RTK_KDRV_YK_54LU)
            if ((value & 0x0000ffff) == YK_54LU_CUSTOMER_CODE) {
                *ppUsrData = &yk_54lu_user_keys;
                *pCode = (value & 0xffff0000) >> 16;
            } else
//#if defined(CONFIG_RTK_KDRV_YK_76J)
                if ((value & 0x0000ffff) == YK_76J_CUSTOMER_CODE) {
                    *ppUsrData = &yk_76j_user_keys;
                    *pCode = (value & 0xffff0000) >> 16;
                } else

#if defined(CONFIG_RTK_KDRV_HAIER_IR)
                    if ((value & 0x0000ffff) == 0xe7e7) {
                        *ppUsrData = &haier_user_keys;
                        *pCode = (value & 0xffff0000) >> 16;
                    } else
#endif
#if defined(CONFIG_RTK_KDRV_TV035_IR)
                        if ((value & 0x0000ff00) == KONKA_CUSTOMER_CODE) {
                            *ppUsrData = &konka_user_keys;
                            *pCode = (value & 0x000000ff);
                        } else
#endif
//#if defined(CONFIG_RTK_KDRV_TV001_IR)
                            if ((value & 0x0000ffff) == RTK_MK5_2_CUSTOMER_CODE) {
                                *ppUsrData = &rtk_mk5_2_user_keys;
                                *pCode = (value & 0x00ff0000) >> 16;
                            } else
//#endif
//#if defined(CONFIG_RTK_KDRV_ANDROID_OTT)
                                if ((value & 0x0000ffff) == RTK_ANDROID_OTT_CUSTOMER_CODE) {
                                    *ppUsrData = &rtk_android_ott_stb_user_keys;
                                    *pCode = (value & 0xffff0000) >> 16;
                                } else
//#endif
                                    if ((value & 0x0000ffff) == TV005_CUSTOMER_CODE1) {
                                        *ppUsrData = &tv005_user_keys;
                                        *pCode = (value & 0x00ff0000) >> 16;
                                    } else if ((value & 0x0000ffff) == LIBRA_MS_CUSTOMER_CODE) {
                                        *ppUsrData = &libra_ms_user_keys;
                                        *pCode = (value & 0x00ff0000) >> 16;
                                    } else if ((value & 0x0000ffff) == JAECS_T118_CUSTOMER_CODE) {
                                        *ppUsrData = &jaecs_t118_user_keys;
                                        *pCode = (value & 0x00ff0000) >> 16;
                                    } else if ((value & 0x0000ffff) == RTK_MK3_CUSTOMER_CODE) {
                                        *ppUsrData = &rtk_mk3_user_keys;
                                        *pCode = (value & 0x00ff0000) >> 16;
                                    } else if ((value & 0x0000ffff) == YK_70LB_CUSTOMER_CODE) {
                                        *ppUsrData = &yk_70lb_user_keys;
                                        *pCode = (value & 0xffff0000) >> 16;
                                    } else if ((value & 0x0000ffff) == RTK_MK4_CUSTOMER_CODE) {
                                        *ppUsrData = &rtk_mk4_user_keys;
                                        *pCode = (value & 0x00ff0000) >> 16;
                                    } else if ((value & 0x0000ffff) == NETG_MS_CUSTOMER_CODE) {
                                        *ppUsrData = &netg_ms_user_keys;
                                        *pCode = (value & 0x00007c0) >> 6;
                                    } else if ((value & 0x00000003) == YK_54LU_SHUTTLE_CUSTOMER_CODE) {
                                        *ppUsrData = &yk_54lu_user_keys;
                                        *pCode = (value & 0x000000e0) >> 5;
                                    } else if ((value & 0x00000003) == YK_76J_SHUTTLE_CUSTOMER_CODE) {
                                        *ppUsrData = &yk_76j_user_keys;
                                        *pCode = (value & 0x000000e0) >> 5;
                                    } else
#if defined(CONFIG_RTK_KDRV_TV015_IR)
                                        if ((value & 0x0000ffff) == TV015_IR_AOC_CUSTOMER_CODE) {
                                            *ppUsrData = &tv015_ir_aoc_user_keys;
                                            *pCode = (value & 0x00ff0000) >> 16;
                                        } else if (value == TV015_IR_FAC_TEST_CODE1) {
                                            *ppUsrData = NULL;
                                            *pCode = 0;
                                        } else if (value == TV015_IR_FAC_TEST_CODE2) {
                                            *ppUsrData = NULL;
                                            *pCode = 0;
                                        } else if ((value & 0x0000ffff) == TV015_IR_FAC_CUSTOMER_CODE) {
                                            *ppUsrData = &tv015_ir_fac_user_keys;
                                            *pCode = (value & 0x00ff0000) >> 16;
                                        } else if ((value & 0x00000000) == TV015_IR_RC6_CUSTOMER_CODE) {
                                            *ppUsrData = &tv015_ir_rc6_user_keys;
                                            *pCode = (value & 0x000000ff);
                                        } else
#endif
                                        {
                                            *ppUsrData = NULL;
                                            *pCode = 0;
                                        }
}

static void _venus_ir_clean_user_keys(struct user_key_data *pUserKeys)
{
    if(pUserKeys->key_table.keys && pUserKeys->max_size > 0) {
        kfree(pUserKeys->key_table.keys);
        pUserKeys->key_table.keys = NULL;
    }
    pUserKeys->key_table.size = 0;
    pUserKeys->max_size = 0;
}

static bool _venus_ir_checkkeycode(struct user_key_data *pUserKeys, unsigned int keycode)
{
    int i;
    for (i = 0; i < pUserKeys->key_table.size; i++) {
        if (pUserKeys->key_table.keys[i].keycode == keycode) {
            return true;
        }
    }
    return false;
}
static int _venus_ir_setkeycode(struct input_dev *dev, unsigned int scancode, unsigned int keycode)
{
    int i;
    int old_keycode = KEY_CNT;
    struct user_key_data *pUsrData;
    u32 ir_scancode;

    IR_DBG("venus_ir_setkeycode");

    _venus_ir_get_user_data(scancode, &pUsrData, &ir_scancode);
    if(pUsrData == NULL) {
        IR_ALERT("user keys not found for %d", scancode);
        return 0;
    }
    bUseUserTable = true;
    IR_DBG("[setkeycode]size=%d, max=%d", pUsrData->key_table.size, pUsrData->max_size);
    for(i = 0; i < pUsrData->key_table.size; i++) {
        if(ir_scancode == pUsrData->key_table.keys[i].scancode) {
            IR_DBG("[setkeycode]found keycode, scancode=%d, keycode=%d", ir_scancode, pUsrData->key_table.keys[i].keycode);
            //mapping found, set to new keycode
            old_keycode = pUsrData->key_table.keys[i].keycode;
            pUsrData->key_table.keys[i].keycode = keycode;
            break;
        }
    }

    if(old_keycode != KEY_CNT) {
        __clear_bit(old_keycode, dev->keybit);
        __set_bit(keycode, dev->keybit);

        if(
            _venus_ir_checkkeycode(&rtk_mk5_user_keys, old_keycode) ||
//#if defined(CONFIG_RTK_KDRV_YK_54LU)
            _venus_ir_checkkeycode(&yk_54lu_user_keys, old_keycode) ||
//#endif
//#if defined(CONFIG_RTK_KDRV_YK_76J)
            _venus_ir_checkkeycode(&yk_76j_user_keys, old_keycode) ||
//#endif
#if defined(CONFIG_RTK_KDRV_HAIER_IR)
            _venus_ir_checkkeycode(&haier_user_keys, old_keycode) ||
#endif


#if defined(CONFIG_RTK_KDRV_TV035_IR)
            _venus_ir_checkkeycode(&konka_user_keys, old_keycode) ||
#endif

//#if defined(CONFIG_RTK_KDRV_TV001_IR)
            _venus_ir_checkkeycode(&rtk_mk5_2_user_keys, old_keycode) ||
//#endif
            _venus_ir_checkkeycode(&rtk_android_ott_stb_user_keys, old_keycode) ||

#if defined(CONFIG_RTK_KDRV_TV015_IR)
            _venus_ir_checkkeycode(&tv015_ir_aoc_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&tv015_ir_fac_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&tv015_ir_rc6_user_keys, old_keycode) ||
#endif

#if defined(CONFIG_RTK_KDRV_TV030_IR)
            _venus_ir_checkkeycode(&tcl_user_keys, old_keycode) ||
#endif

            _venus_ir_checkkeycode(&libra_ms_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&jaecs_t118_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&rtk_mk3_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&yk_70lb_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&rtk_mk4_user_keys, old_keycode) ||
            _venus_ir_checkkeycode(&netg_ms_user_keys, old_keycode) ||
            false) {
            __set_bit(old_keycode, dev->keybit);
        }
        return 0;
    }


    IR_ALERT("[setkeycode]keycode not found");
    if(pUsrData->key_table.size == pUsrData->max_size) {
        //realloc for key table
        struct venus_key *pNew;
        IR_ALERT("[setkeycode]try to realloc memory for mappint table, new size =%d", pUsrData->max_size + 10);
        pNew = (struct venus_key *)krealloc(pUsrData->key_table.keys,
                                            (pUsrData->max_size + 10) * sizeof(struct venus_key),
                                            GFP_ATOMIC);
        if(!pNew)
            return -ENOMEM;

        pUsrData->key_table.keys = pNew;
        pUsrData->max_size += 10;

        if(pUsrData->key_table.size == 0) {
            // first time set, disable default key map, clear keybit table
            memset(data->input_dev->keybit, 0, sizeof(data->input_dev->keybit));
        }

    }

    IR_ALERT("[setkeycode]add mapping, scancode=%d, keycode=%d", ir_scancode, keycode);
    pUsrData->key_table.keys[pUsrData->key_table.size].scancode = ir_scancode;
    pUsrData->key_table.keys[pUsrData->key_table.size].keycode = keycode;
    pUsrData->key_table.size++;
    __set_bit(keycode, dev->keybit);

    return 0;
}

static int _venus_ir_getkeycode(struct input_dev *dev, unsigned int scancode, unsigned int *keycode)
{
    int i;
    struct user_key_data *pUsrData;
    u32 ir_scancode;

    IR_DBG("venus_ir_getkeycode");

    do {
        if(bUseUserTable == false)
            break;

        _venus_ir_get_user_data(scancode, &pUsrData, &ir_scancode);
        if(pUsrData == NULL)
            break;

        for(i = 0; i < pUsrData->key_table.size; i++) {
            if(ir_scancode == pUsrData->key_table.keys[i].scancode) {
                //mapping found
                *keycode = pUsrData->key_table.keys[i].keycode;
                IR_DBG("[getkeycode]scancode=%d, keycode=%d", ir_scancode, pUsrData->key_table.keys[i].keycode);
                return 0;
            }
        }
    } while(0);

    IR_DBG("[getkeycode]not found, return KEY_RESERVED for %d", ir_scancode);

    *keycode = KEY_RESERVED; //not found, set to KEY_RESERVED
    return 0;
}
