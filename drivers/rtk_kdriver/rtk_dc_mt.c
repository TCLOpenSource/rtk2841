#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/proc_fs.h>
#include <linux/interrupt.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/platform_device.h>
#include <rbus/dc_sys_reg.h>
#include <linux/suspend.h>
#include <linux/nmi.h>
#include <asm-generic/irq_regs.h>
#include <mach/rtk_platform.h>
#include <mach/io.h>
#include "rtk_dc_mt.h"
#include "rtk_dc_mt_config.h"
#include <linux/pageremap.h>
#include <mach/rtk_platform.h>
#include <linux/console.h>
#include "rtd_logger.h"
#include <rbus/sb2_reg.h>

MODULE_AUTHOR("Kevin Wang, Realtek Semiconductor");
MODULE_LICENSE("Dual BSD/GPL");

//extern func
extern void dump_stacks (void);
extern int strncasecmp(const char *s1, const char *s2, size_t n);
#if defined(CONFIG_RTK_KDRV_MD) || defined(CONFIG_RTK_KDRV_MD_NEW)
extern void md_dump_cmd_ring_status(void);
#endif

//internal func
int get_dcmt_trap_info(dcmt_trap_info *info);
int dc_to_dbus_addr(unsigned int dc_addr, unsigned int * pdbus_addr, DCID id);
int dbus_to_dc_addr(unsigned int dbus_addr, unsigned int * pdc_addr, DCID id, START_END start_end);
int dump_memtrash_log(DCID dc_id, unsigned int entry, MT_SYS_ID sys_id); //DC1/2 MT/MTEX DS_SYS1/2/3
int dcmt_set_monitor(unsigned int entry, DC_MT_DESC * pDesc);
static int emmc_workaround_process(DC_MT_DESC * pDesc);
int dcmt_set_monitor_auto(DC_MT_DESC * pDesc);
void dcmt_set_all_cpu_intr_routing(void);
void dcmt_unset_avk_intr_routing(void);

#define CONFIG_DCU2 0

#define DC_MT_DEV_FILE_NAME      "dc_mt"
#define ATTR_PERMISSION_RO      (S_IRUSR | S_IRGRP| S_IROTH)
#define ATTR_PERMISSION_RW      (S_IRUSR | S_IRGRP| S_IROTH | S_IWUSR | S_IWGRP)

static const char* bs_str[4]    = { "na", "seq", "block", "seq&block"}; //show only
static const char* mode_str[4] = { "na", "mode1", "mode2", "mode3" }; //show & setting
static const char* prot_str[4] = { "na", "r", "w", "rw"};

#define MAX_DUMP_STR_SIZE (128)
static char panic_dump_log[MAX_DUMP_STR_SIZE];
int dcmt_log_setting = DCMT_LOG_CMD|DCMT_LOG_ERR|DCMT_LOG_INIT|DCMT_LOG_ISR;//default enable logs

#define ACPU_AUTOSYNC_RANGE_START_reg           DC_SYS_DC_MT_SADDR_0_reg
#define ACPU_AUTOSYNC_RANGE_END_reg             DC_SYS_DC_MT_EADDR_0_reg
#define VCPU_AUTOSYNC_RANGE_START_reg           DC_SYS_DC_MT_SADDR_1_reg
#define VCPU_AUTOSYNC_RANGE_END_reg             DC_SYS_DC_MT_EADDR_1_reg
#define KCPU_AUTOSYNC_RANGE_START_reg           DC_SYS_DC_MTEX_SADDR_1_reg
#define KCPU_AUTOSYNC_RANGE_END_reg             DC_SYS_DC_MTEX_EADDR_1_reg
#define SECURE_AUTOSYNC_RANGE_START_reg         DC_SYS_DC_MT_SADDR_3_reg
#define SECURE_AUTOSYNC_RANGE_END_reg           DC_SYS_DC_MT_EADDR_3_reg
unsigned int avk_range[DCMT_RANGE_SYNC_NUM];//avk auto sync range for hw-monitor

const MODULE_INFO module_info[] = {

    {MODULE_TVSB2_DIW,     "TVSB2_DIW"},
    {MODULE_TVSB2_DIR,     "TVSB2_DIR"},
    {MODULE_TVSB2_M_CAP,     "TVSB2_M_CAP"},
    {MODULE_TVSB2_M_DISP,     "TVSB2_M_DISP"},
    {MODULE_TVSB2_S_CAP,     "TVSB2_S_CAP"},
    {MODULE_TVSB2_S_DISP,     "TVSB2_S_DISP"},
    {MODULE_TVSB2_VO1_Y,     "TVSB2_VO1_Y"},
    {MODULE_TVSB2_VO1_C,     "TVSB2_VO1_C"},
    {MODULE_TVSB2_VO2_Y,     "TVSB2_VO2_Y"},
    {MODULE_TVSB2_VO2_C,     "TVSB2_VO2_C"},
    {MODULE_TVSB2_I3DDMA,     "TVSB2_I3DDMA"},
    {MODULE_TVSB2_DE_XC_W,     "TVSB2_DE_XC_W"},
    {MODULE_TVSB2_DE_XC_R,     "TVSB2_DE_XC_R"},
    {MODULE_TVSB2_SNR_R,     "TVSB2_SNR_R"},

    {MODULE_TVSB2,     "TVSB2"},

    // ================================================================================

    {MODULE_TVSB1_VD,     "TVSB1_VD"},
    {MODULE_TVSB1_AUDIO1,     "TVSB1_AUDIO1"},
    {MODULE_TVSB1_AUDIO2,     "TVSB1_AUDIO2"},
    {MODULE_TVSB1_VBI,     "TVSB1_VBI"},
    {MODULE_TVSB1_TVE_VD,     "TVSB1_TVE_VD"},
    {MODULE_TVSB1_TVE_VBI,     "TVSB1_TVE_VBI"},

    {MODULE_TVSB1,     "TVSB1"},

    // ================================================================================

    {MODULE_SB1_CP_KC,        "SB1_CP"},
    {MODULE_SB1_USB_EX,        "SB1_USB_EX"},
    {MODULE_SB1_USB,       "SB1_USB"},
    {MODULE_SB1_TP2,     "SB1_TP2"},
    {MODULE_SB1_ETN,       "SB1_ETN"},
    {MODULE_SB1_TP_KC,        "SB1_TP_KC"},
    {MODULE_SB1_EMMC_KC,      "SB1_EMMC_KC"},
    {MODULE_SB1_CP_NKC,      "SB1_CP_NKC"},
    {MODULE_SB1_TP2_NKC,      "SB1_TP2_NKC"},
    {MODULE_SB1_TP_NKC,      "SB1_TP_NKC"},
    {MODULE_SB1_EMMC_NKC,      "SB1_EMMC_NKC"},

    {MODULE_SB1,      "SB1"},

    // ================================================================================

    {MODULE_SB2_KCPU,  "SB2_KCPU"},

    {MODULE_SB2_ACPU,  "SB2_ACPU"},

    {MODULE_SB2_VCPU,  "SB2_VCPU"},

    {MODULE_SB2_UART,  "SB2_UART"},
    {MODULE_SB2_HOST_IF, "SB2_HOST_IF"},

    {MODULE_SB2, "SB2"},

    // ================================================================================

    {MODULE_SB3_AEE,       "SB3_AEE"},
    {MODULE_SB3_ADE,       "SB3_ADE"},
    {MODULE_SB3_ME,        "SB3_ME"},
    {MODULE_SB3_MD_KC,        "SB3_MD_KCPU"},//SB3_MD_KC
    {MODULE_SB3_VE,    "SB3_VE"},
    {MODULE_SB3_VDE,       "SB3_VDE"},
    {MODULE_SB3_UART2 ,    "SB3_UART2"},

    {MODULE_SB3_MD_NKC,       "SB3_MD_SCPU"},//SB3_MD_NKC
    {MODULE_SB3_MD_VC,      "SB3_MD_VCPU"},//SB3_MD_VC

    {MODULE_SB3,      "SB3"},

    // ================================================================================

    {MODULE_VE,        "VE_BRIDGE"},
    {MODULE_VE_0,        "VE_BRIDGE"},
    {MODULE_VE_1,        "VE_BRIDGE"},
    {MODULE_VE_2,        "VE_BRIDGE"},
    {MODULE_VE_3,        "VE_BRIDGE"},
    {MODULE_VE_4,        "VE_BRIDGE"},
    {MODULE_VE_5,        "VE_BRIDGE"},
    {MODULE_VE_6,        "VE_BRIDGE"},
    {MODULE_VE_7,        "VE_BRIDGE"},
    {MODULE_VE_8,        "VE_BRIDGE"},
    {MODULE_VE_9,        "VE_BRIDGE"},
    {MODULE_VE_10,        "VE_BRIDGE"},
    {MODULE_VE_11,        "VE_BRIDGE"},
    {MODULE_VE_12,        "VE_BRIDGE"},
    {MODULE_VE_13,        "VE_BRIDGE"},
    {MODULE_VE_14,        "VE_BRIDGE"},

    // ================================================================================

    {MODULE_TVSB3_PST,     "TVSB3_PST"},
    {MODULE_TVSB3,     "TVSB3"},

    // ================================================================================
    {MODULE_GPU,           "GPU_BRIDGE"},

    {MODULE_GPU_0,           "GPU_BRIDGE"},
    {MODULE_GPU_1,           "GPU_BRIDGE"},
    {MODULE_GPU_2,           "GPU_BRIDGE"},
    {MODULE_GPU_3,           "GPU_BRIDGE"},
    {MODULE_GPU_4,           "GPU_BRIDGE"},
    {MODULE_GPU_5,           "GPU_BRIDGE"},
    {MODULE_GPU_6,           "GPU_BRIDGE"},
    {MODULE_GPU_7,           "GPU_BRIDGE"},
    {MODULE_GPU_8,           "GPU_BRIDGE"},
    {MODULE_GPU_9,           "GPU_BRIDGE"},
    {MODULE_GPU_10,           "GPU_BRIDGE"},
    {MODULE_GPU_11,           "GPU_BRIDGE"},
    {MODULE_GPU_12,           "GPU_BRIDGE"},
    {MODULE_GPU_13,           "GPU_BRIDGE"},
    {MODULE_GPU_14,           "GPU_BRIDGE"},

    // ================================================================================

    {MODULE_TVSB5_DEMOD,         "TVSB5_DEMOD"},
    {MODULE_TVSB5_DBGDMA,         "TVSB5_DBGDMA"},
    {MODULE_TVSB5,         "TVSB5"},

    // ================================================================================

    {MODULE_SE2_Q0,           "SE2_Q0"},
    {MODULE_SE2_Q1,           "SE2_Q1"},
    {MODULE_SE2,           "SE2"},

    // ================================================================================

    {MODULE_TVSB4_ODW,       "TVSB4_ODW"},
    {MODULE_TVSB4_ODR,       "TVSB4_ODR"},
    {MODULE_TVSB4_DC2H,       "TVSB4_DC2H"},
    {MODULE_TVSB4_SUBT,       "TVSB4_SUBT"},
    {MODULE_TVSB4_OSD1,       "TVSB4_OSD1"},
    {MODULE_TVSB4_OSD2,       "TVSB4_OSD2"},
    {MODULE_TVSB4_OSD3,       "TVSB4_OSD3"},
    {MODULE_TVSB4_DMATO3DLUTR, "TVSB4_DMATO3DLUTR"},
    {MODULE_TVSB4_OSD_FBDC, "TVSB4_OSD_FBDC"},

    {MODULE_TVSB4,       "TVSB4"},

    // ================================================================================

    {MODULE_ANY,  "ANY"},

    // ================================================================================

};

unsigned char key_table_audio[] = {MODULE_TVSB1_AUDIO1,MODULE_TVSB1_AUDIO2};
unsigned char key_table_se[] = {MODULE_SE2_Q0,MODULE_SE2_Q1};
unsigned char key_table_ve[] = {MODULE_VE, MODULE_SB3_VE};
unsigned char key_table_dispi[] = {MODULE_TVSB2_DIW,MODULE_TVSB2_DIR,MODULE_TVSB2_VO1_Y,MODULE_TVSB2_VO1_C,
                                                MODULE_TVSB2_VO2_Y,MODULE_TVSB2_VO2_C,MODULE_TVSB2_I3DDMA,MODULE_TVSB2_DE_XC_W,
                                                MODULE_TVSB2_DE_XC_R,MODULE_TVSB2_SNR_R};
unsigned char key_table_dispm[] = {MODULE_TVSB2_M_CAP,MODULE_TVSB2_M_DISP,MODULE_TVSB2_S_CAP,MODULE_TVSB2_S_DISP};
unsigned char key_table_dispd[] = {MODULE_TVSB4_ODW,MODULE_TVSB4_ODR,MODULE_TVSB4_DC2H};
unsigned char key_table_gpu[] = {MODULE_GPU};
unsigned char key_table_osd[] = {MODULE_TVSB4_OSD1,MODULE_TVSB4_OSD2,MODULE_TVSB4_OSD3,MODULE_TVSB4_OSD_FBDC};
unsigned char key_table_tve[] = {MODULE_TVSB1_TVE_VD,MODULE_TVSB1_TVE_VBI};
unsigned char key_table_aee[] = {MODULE_SB3_AEE};
unsigned char key_table_ade[] = {MODULE_SB3_ADE};
unsigned char key_table_vd[] = {MODULE_TVSB1_VD};
unsigned char key_table_vde[] = {MODULE_SB3_VDE};
unsigned char key_table_cp[] = {MODULE_SB1_CP_KC,MODULE_SB1_CP_NKC};
unsigned char key_table_usb[] = {MODULE_SB1_USB,MODULE_SB1_USB_EX};
unsigned char key_table_tp[] = {MODULE_SB1_TP_NKC,MODULE_SB1_TP_KC,MODULE_SB1_TP2_NKC,MODULE_SB1_TP2};
unsigned char key_table_uart[] = {MODULE_SB2_UART,MODULE_SB3_UART2};
unsigned char key_table_md[] = {MODULE_SB3_MD_KC,MODULE_SB3_MD_NKC,MODULE_SB3_MD_VC};
unsigned char key_table_etn[] = {MODULE_SB1_ETN};
unsigned char key_table_cpus[] = {MODULE_SB2_KCPU,MODULE_SB2_ACPU,MODULE_SB2_VCPU};
unsigned char key_table_emmc[] = {MODULE_SB1_EMMC_KC,MODULE_SB1_EMMC_NKC};
unsigned char key_table_demod[] = {MODULE_TVSB5_DEMOD};
unsigned char key_table_vbi[] = {MODULE_TVSB1_VBI};
unsigned char key_table_pst[] = {MODULE_TVSB3_PST};
unsigned char key_table_hostif[] = {MODULE_SB2_HOST_IF};
unsigned char key_table_me[] = {MODULE_SB3_ME};
unsigned char key_table_subtitle[] = {MODULE_TVSB4_SUBT};

const MODULE_SEARCH_TABLE key_table[] =
{
        {"AUDIO", key_table_audio, sizeof(key_table_audio)},
        {"SE", key_table_se, sizeof(key_table_se)},
        {"VE", key_table_ve, sizeof(key_table_ve)},
        {"DISP_I", key_table_dispi, sizeof(key_table_dispi)},
        {"DISP_M", key_table_dispm, sizeof(key_table_dispm)},
        {"DISP_D", key_table_dispd, sizeof(key_table_dispd)},
        {"GPU", key_table_gpu, sizeof(key_table_gpu)},
        {"OSD", key_table_osd, sizeof(key_table_osd)},
        {"TVE", key_table_tve, sizeof(key_table_tve)},
        {"AEE", key_table_aee, sizeof(key_table_aee)},
        {"ADE", key_table_ade, sizeof(key_table_ade)},
        {"VD", key_table_vd, sizeof(key_table_vd)},
        {"VDE", key_table_vde, sizeof(key_table_vde)},
        {"CP", key_table_cp, sizeof(key_table_cp)},
        {"USB", key_table_usb, sizeof(key_table_usb)},
        {"TP", key_table_tp, sizeof(key_table_tp)},
        {"UART", key_table_uart, sizeof(key_table_uart)},
        {"MD", key_table_md, sizeof(key_table_md)},
        {"ETN", key_table_etn, sizeof(key_table_etn)},
        {"CPUS", key_table_cpus, sizeof(key_table_cpus)},
        {"EMMC", key_table_emmc, sizeof(key_table_emmc)},
        {"DEMOD", key_table_demod, sizeof(key_table_demod)},
        {"VBI", key_table_vbi, sizeof(key_table_vbi)},
        {"PST", key_table_pst, sizeof(key_table_pst)},
        {"HOST_IF", key_table_hostif, sizeof(key_table_hostif)},
        {"ME", key_table_me, sizeof(key_table_me)},
        {"SUBTITLE", key_table_subtitle, sizeof(key_table_subtitle)},
};

unsigned char trap_table_ve[] = {MODULE_VE, MODULE_SB3_VE};
unsigned char trap_table_aee[] = {MODULE_SB3_AEE};
unsigned char trap_table_ade[] = {MODULE_SB3_ADE};
unsigned char trap_table_vde[] = {MODULE_SB3_VDE};
unsigned char trap_table_kcpucp[] = {MODULE_SB1_CP_KC};
unsigned char trap_table_scpucp[] = {MODULE_SB1_CP_NKC};
unsigned char trap_table_kcputp[] = {MODULE_SB1_TP_KC,MODULE_SB1_TP2,};
unsigned char trap_table_scputp[] = {MODULE_SB1_TP_NKC,MODULE_SB1_TP2_NKC};
unsigned char trap_table_kcpumd[] = {MODULE_SB3_MD_KC};
unsigned char trap_table_scpumd[] = {MODULE_SB3_MD_NKC};
unsigned char trap_table_vcpumd[] = {MODULE_SB3_MD_VC};
unsigned char trap_table_kcpu[] = {MODULE_SB2_KCPU};
unsigned char trap_table_acpu[] = {MODULE_SB2_ACPU};
unsigned char trap_table_vcpu[] = {MODULE_SB2_VCPU};
unsigned char trap_table_kcpuemmc[] = {MODULE_SB1_EMMC_KC};
unsigned char trap_table_scpuemmc[] = {MODULE_SB1_EMMC_NKC};

const MODULE_SEARCH_TABLE trap_table[] =
{
        {"VE", trap_table_ve, sizeof(trap_table_ve)},
        {"AEE", trap_table_aee, sizeof(trap_table_aee)},
        {"ADE", trap_table_ade, sizeof(trap_table_ade)},
        {"VDE", trap_table_vde, sizeof(trap_table_vde)},
        {"KCPU_CP", trap_table_kcpucp, sizeof(trap_table_kcpucp)},
        {"SCPU_CP", trap_table_scpucp, sizeof(trap_table_scpucp)},
        {"KCPU_TP", trap_table_kcputp, sizeof(trap_table_kcputp)},
        {"SCPU_TP", trap_table_scputp, sizeof(trap_table_scputp)},
        {"KCPU_MD", trap_table_kcpumd, sizeof(trap_table_kcpumd)},
        {"SCPU_MD", trap_table_scpumd, sizeof(trap_table_scpumd)},
        {"VCPU_MD", trap_table_vcpumd, sizeof(trap_table_vcpumd)},
        {"KCPU", trap_table_kcpu, sizeof(trap_table_kcpu)},
        {"ACPU", trap_table_acpu, sizeof(trap_table_acpu)},
        {"VCPU", trap_table_vcpu, sizeof(trap_table_vcpu)},
        {"KCPU_EMMC", trap_table_kcpuemmc, sizeof(trap_table_kcpuemmc)},
        {"SCPU_EMMC", trap_table_scpuemmc, sizeof(trap_table_scpuemmc)},
};

int dcmt_driver_disable = 0;//disable the whole dcmt driver
static int kernel_trap_warning = DCMT_INTR_MODE_PANIC;  // change default to 1
static int all_intr_routing_enable = 1;  // change default to 1

//static unsigned long dc_mt_trash_cnt[DC_MT_ENTRY_COUNT][8];
static dcmt_addr_desc dc_regs[DC_NUM][DC_MT_ENTRY_COUNT];
static DC_MT_DESC g_desc_store_dc[DC_MT_ENTRY_COUNT];

unsigned int ib_seq_bound[SEQ_NUM][BOUND_NUM];
unsigned int region_mode[BOUND_NUM + 1] = {0};
unsigned int region_slice[BOUND_NUM] = {0};
unsigned int IB_SEQ_REGION_SET;
struct atomic_notifier_head dcmt_notifier_list;
EXPORT_SYMBOL(dcmt_notifier_list); //export symbol for other module
struct atomic_notifier_head dcmt_notifier_list_cat;      //show registered callback func
EXPORT_SYMBOL(dcmt_notifier_list_cat); //export symbol for other module
static dcmt_trap_info trap_info;
static int last_set_entry = 4;//DC_MT_ENTRY_COUNT-1;
static int init_skip_mem[DC_MT_ENTRY_COUNT] = {0};

//code : low_level, driver_framework, developer, user, init

//---------------------------------low level logic---------------------------------
int __find_char_pos(char * str,char aim)
{
        char * end = str+strlen(str);
        int cnt = 0;

        while(str < end)
        {
                if((*str) == aim)
                {
                        return cnt;
                }
                str++;
                cnt++;
        }

        return -1;
}

char* __find_next_str(char* str)
{
        char* end = str + strlen(str);

        while(str < end)
        {
                if (isalnum(*str)) // is alphabet or number
                        return str;
                str++;
        }

        return NULL;
}

int get_arguments(char* str, int argc, char** argv)
{
        int ret = 0;
        char* sep;

        while ((str = __find_next_str(str)) && ret < argc)
        {
                argv[ret++] = str;
                //DC_MT_INFO("arg[%d]='%s'\n", ret, str);
                sep = strchr(str, ','); // devided by

                if (sep == NULL)
                        break;

                *sep = '\0'; // changed to null terminated
                //DC_MT_INFO("**** arg[%d]='%s'\n", ret, str);
                str = sep + 1;

        }

        return ret;
}

int get_space_arguments(char* str, int argc, char** argv)
{
        int ret = 0;
        char* sep;

        while ((str = __find_next_str(str)) && ret < argc)
        {
                argv[ret++] = str;
                //DC_MT_INFO("arg[%d]='%s'\n", ret, str);
                sep = strchr(str, ' '); // devided by

                if (sep == NULL)
                        break;

                *sep = '\0'; // changed to null terminated
                //DC_MT_INFO("**** arg[%d]='%s'\n", ret, str);
                str = sep + 1;

        }

        return ret;
}

void __replace_chr(char* str, char a, char b)
{
        char* end = str + strlen(str);
        while(str < end)
        {
                if (*str == a)
                        *str = b;
                str++;
        }
}

int isStrFullMatch(char * stra,char * strb,int case_care)
{
        if((stra == NULL)||(strb == NULL))
        {
                return -1;
        }

        if(strlen(stra) != strlen(strb))
        {
                return -1;
        }

        if(case_care)
        {
                return strcmp(stra,strb);
        }
        else
        {
                return strcasecmp(stra,strb);
        }
}

//check dcmt entry work or not
static int is_dcmt_entry_work(unsigned int entry)
{
        DCID id;
        unsigned int mode_val;
        for(id = DCID_1;id < DC_NUM;++id)
        {
                mode_val = rtd_inl(dc_regs[id][entry].mode_addr);
                mode_val &= 0x3;
                if(mode_val)
                {
                        return 1;//this entry is working
                }
        }
        return 0;
}

//disable scpu intr
static void disable_dcmt_scpu_intr(unsigned int entry)
{
        // Disable Memory Trash Interruprs
        DCID id;
        unsigned int val;
        for(id = DCID_1; id < DC_NUM; ++id)
        {
                val = dc_regs[id][entry].int_mask;
                rtd_outl(dc_regs[id][entry].int_en_addr, val);
                rtd_outl(dc_regs[id][entry].int_en_sys2_addr, val);
                rtd_outl(dc_regs[id][entry].int_en_sys3_addr, val);
        }
}
static __maybe_unused void disable_dcmt_scpu_intr_all(void)
{
        unsigned int i;
        for(i = 0; i < DC_MT_ENTRY_COUNT; ++i)
        {
                disable_dcmt_scpu_intr(i);
        }
}

//check module include
static int is_module_include(unsigned char module_a,unsigned char module_b)
{
        //check if module_b is include module_a
        //.check module_any
        if(module_b == MODULE_ANY)
        {
                return 1;//module any include module
        }

        if(module_a == module_b)
        {
                return 1;
        }

        //.check sys_id
        if(SUB_MODULE_ID(module_b) == SUB_MODULE_ID(MODULE_ANY))//if is a bridge module,check bridge_id only
        {
                if(BRIDGE_ID(module_a) == BRIDGE_ID(module_b))
                {
                        return 1;
                }
        }

        //.check whole module_id

        return 0;
}

//enable scpu intr
static void enable_dcmt_scpu_intr(unsigned int entry)
{
        // Ensable Memory Trash Interruprs
        DCID id;
        unsigned int val;
        for(id = DCID_1; id < DC_NUM; ++id)
        {
                val = dc_regs[id][entry].int_mask | DC_INT_EN_WRITE_DATA;
                rtd_outl(dc_regs[id][entry].int_en_addr, val);
                rtd_outl(dc_regs[id][entry].int_en_sys2_addr, val);
                rtd_outl(dc_regs[id][entry].int_en_sys3_addr, val);
        }
}

static void enable_dcmt_scpu_intr_all(void)
{
        unsigned int i;
        for(i = 0; i < DC_MT_ENTRY_COUNT; ++i)
        {
                enable_dcmt_scpu_intr(i);
        }
}

//change avsk cpu routings
static void change_dcmt_intr_routing(unsigned int bit_val)
{
        if(bit_val & (1 << DCMT_INTR_ROUT_SCPU))
        {
                rtd_outl(INT_CTRL_SCPU_reg, DC_INIT_SCPU_ROUTING_EN | BIT(0));
        }
        else
        {
                rtd_outl(INT_CTRL_SCPU_reg, DC_INIT_SCPU_ROUTING_EN);
        }

        if(bit_val & (1 << DCMT_INTR_ROUT_ACPU1))
        {
                rtd_outl(INT_CTRL_ACPU_reg, DC_INIT_ACPU_ROUTING_EN | BIT(0));
        }
        else
        {
                rtd_outl(INT_CTRL_ACPU_reg, DC_INIT_ACPU_ROUTING_EN);
        }
#ifdef DCMT_AV2
        if(bit_val & (1 << DCMT_INTR_ROUT_ACPU2))
        {
                rtd_outl(INT_CTRL_ACPU_reg, DC_INIT_ACPU2_ROUTING_EN | BIT(0));
        }
        else
        {
                rtd_outl(INT_CTRL_ACPU_reg, DC_INIT_ACPU2_ROUTING_EN);
        }
#endif
        if(bit_val & (1 << DCMT_INTR_ROUT_VCPU1))
        {
                rtd_outl(INT_CTRL_VCPU_reg, DC_INIT_VCPU_ROUTING_EN | BIT(0));
        }
        else
        {
                rtd_outl(INT_CTRL_VCPU_reg, DC_INIT_VCPU_ROUTING_EN);
        }
#ifdef DCMT_AV2
        if(bit_val & (1 << DCMT_INTR_ROUT_VCPU2))
        {
                rtd_outl(INT_CTRL_VCPU_reg, DC_INIT_VCPU2_ROUTING_EN|BIT(0));
        }
        else
        {
                rtd_outl(INT_CTRL_VCPU_reg, DC_INIT_VCPU2_ROUTING_EN);
        }
#endif
        if(bit_val & (1 << DCMT_INTR_ROUT_KCPU))
        {
                //rtd_outl(INT_CTRL_KCPU_reg, DC_INIT_KCPU_ROUTING_EN | BIT(0));
        }
        else
        {
                //rtd_outl(INT_CTRL_KCPU_reg, DC_INIT_KCPU_ROUTING_EN);
        }
}

//clear_dcmt_intr
static void clear_dcmt_trash_status(DCID id, unsigned int entry) //DC1/2 MT/MTEX DS_SYS1/2/3
{
        /*dcmt status reg can latch only one time trash,
           so we have different to cope with multi-trash one time,
           we clear all intr for the entry to aviod process multi-trash intr.
        */
        unsigned int tmp_hi0 = rtd_inl(dc_regs[id][entry].hi0_addr);
        tmp_hi0 &= ~0xffffff;
        rtd_outl(dc_regs[id][entry].hi0_addr, tmp_hi0);
        rtd_outl(dc_regs[id][entry].lo_addr, 0);
        rtd_outl(dc_regs[id][entry].sa_addr, 0);
        rtd_outl(dc_regs[id][entry].hi0_sys2_addr, 0);
        rtd_outl(dc_regs[id][entry].lo_sys2_addr, 0);
        rtd_outl(dc_regs[id][entry].sa_sys2_addr, 0);
        rtd_outl(dc_regs[id][entry].hi0_sys3_addr, 0);
        rtd_outl(dc_regs[id][entry].lo_sys3_addr, 0);
        rtd_outl(dc_regs[id][entry].sa_sys3_addr, 0);
        rtd_outl(dc_regs[id][entry].int_status_addr, dc_regs[id][entry].int_mask);
        rtd_outl(dc_regs[id][entry].int_status_sys2_addr, dc_regs[id][entry].int_mask);
        rtd_outl(dc_regs[id][entry].int_status_sys3_addr, dc_regs[id][entry].int_mask);
}
//_ddr_cpy
static int __prot_id(char* prot_mode)
{
        int i;

        for (i = 0; i < 4; i++)
        {
                //DC_MT_INFO("prot_mode='%s', prot_str[%d]='%s'\n", prot_mode, i, prot_str[i]);
                if (strncasecmp(prot_mode, prot_str[i], strlen(prot_mode)) == 0)
                        return i;
        }

        return -1;
}

static char* __module_str(unsigned char id)
{
        int i;

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "search id : 0x%X \n", id);
        for (i = 0; i < sizeof(module_info) / sizeof(MODULE_INFO); i++)
        {
                if (id == module_info[i].id)
                        return (char *)module_info[i].name;
        }

        return NULL;
}

static int __module_id(char* module_name)
{
        int i;
        size_t cmp_len = 0;

        for (i = 0; i < sizeof(module_info) / sizeof(MODULE_INFO); i++)
        {
                cmp_len = max(strlen(module_info[i].name), strlen(module_name));
                if (strncasecmp(module_name, module_info[i].name, cmp_len) == 0)
                        return module_info[i].id;
        }

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "module info size:%d, get i:%d\n", sizeof(module_info) / sizeof(MODULE_INFO), i);

        return -1;
}

static int is_dcmt_intr(DCID *pDcid, unsigned int *pEntry, MT_SYS_ID *pSysid)
{
        DCID id;
        unsigned int entry;
        unsigned int reg_val;
        unsigned int mask_val;

        DCMT_LOG(DCMT_LOG_ISR, KERN_DEBUG, "start to check %s!\n", __FUNCTION__);

        //check if dcmt isr
        for(id = DCID_1; id < DC_NUM; ++id)
        {
                for(entry = 0; entry < DC_MT_ENTRY_COUNT; ++entry)
                {
                        mask_val = dc_regs[id][entry].int_mask;

                        reg_val = rtd_inl(dc_regs[id][entry].int_status_addr);
                        if(reg_val & mask_val)
                        {
                                *pDcid = id;
                                *pEntry = entry;
                                *pSysid = MT_SYS1;
                                //DC_MT_WARNING("DCMT DCU%d,mem%d,sys%d intr detected!\n", (*pDcid) + 1, *pEntry, (*pSysid) + 1);
                                return 1;
                        }

                        reg_val = rtd_inl(dc_regs[id][entry].int_status_sys2_addr);
                        if(reg_val & mask_val)
                        {
                                *pDcid = id;
                                *pEntry = entry;
                                *pSysid = MT_SYS2;
                                //DC_MT_WARNING("DCMT DCU%d,mem%d,sys%d intr detected!\n", (*pDcid) + 1, *pEntry, (*pSysid) + 1);
                                return 1;
                        }

                        reg_val = rtd_inl(dc_regs[id][entry].int_status_sys3_addr);
                        if(reg_val & mask_val)
                        {
                                *pDcid = id;
                                *pEntry = entry;
                                *pSysid = MT_SYS3;
                                //DC_MT_WARNING("DCMT DCU%d,mem%d,sys%d intr detected!\n", (*pDcid) + 1, *pEntry, (*pSysid) + 1);
                                return 1;
                        }
                }
        }

        return 0;
}

unsigned int get_addcmd_seqlen(unsigned long addcmd_h, unsigned long addcmd_l)
{
        unsigned long long cmd = addcmd_h & 0x3FFF;
        cmd <<= 32;
        cmd |= addcmd_l;

        return (unsigned int)(((cmd >> 31) & 0xFF) << 3);
}

void __dump_addcmd(unsigned long addcmd_h, unsigned long addcmd_l)
{
        unsigned long long cmd = addcmd_h & 0x3FFF;
        cmd <<= 32;
        cmd |= addcmd_l;

        if (cmd & 0x01)   //0:1bit block mode
        {
                DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "ADDCMD=%012llx, type=block %s, saddr=%08lx, len=%ld\n",
                          cmd,
                          (cmd & 0x2) ? "write" : "read",             //1:1bit
                          (unsigned long)((cmd >> 2) & 0x1FFFFFFF) << 3, //2-30:29bit
                          (unsigned long)((cmd >> 31) & 0xFF) << 3);   //31-38:8bit
        }
        else
        {
                DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "ADDCMD=%012llx, type=sequence %s, saddr=%08lx, len=%ld\n",
                          cmd,
                          (cmd & 0x2) ? "write" : "read",             //1:1bit
                          (unsigned long)((cmd >> 2) & 0x1FFFFFFF) << 3, //2-30:29bit
                          (unsigned long)((cmd >> 31) & 0xFF) << 3);   //31-38:8bit
        }
}

static int _get_dcmt_entry_desc_str(
        DCID                    id,
        unsigned char           entry,
        char*                   buff,
        unsigned long           size,
        unsigned char           user_flag
)
{
        unsigned char bs    = (rtd_inl(dc_regs[id][entry].type_addr) >> 30) & 0x3;
        unsigned int saddr = rtd_inl(dc_regs[id][entry].saddr_addr);
        unsigned int eaddr = rtd_inl(dc_regs[id][entry].eaddr_addr);
        unsigned int phy_saddr = 0;//dc_to_dbus_addr(saddr, &phy_saddr, id);
        unsigned int phy_eaddr = 0;//dc_to_dbus_addr(eaddr, &phy_eaddr, id);
        unsigned char mode  = rtd_inl(dc_regs[id][entry].mode_addr) & 0x3;
        unsigned long table0 = rtd_inl(dc_regs[id][entry].table0_addr);
        unsigned long table1 = 0;
        unsigned long addcmd_hi0 = rtd_inl(dc_regs[id][entry].hi0_addr);
        unsigned long addcmd_hi1 = 0;
        int k   = 30;
        int len = 0;
        int ret = 0;
        int j   = 0;

        if(entry >= DC_MTEX_ENTRY_START)
        {
                table1 = rtd_inl(dc_regs[id][entry].table1_addr);
                addcmd_hi1 = rtd_inl(dc_regs[id][entry].hi1_addr);
        }
        if(dc_to_dbus_addr(saddr, &phy_saddr, id))
        {
                goto end_proc;
        }
        if(dc_to_dbus_addr(eaddr, &phy_eaddr, id))
        {
                goto end_proc;
        }

        len = snprintf(buff, size, "DCU%d mem%d,", id + 1, entry);
        if (len < 0)
                goto end_proc;

        ret  += len;
        buff += len;
        size -= len;

        // show mem type
        if (bs == 0)
                goto end_proc;

        if(user_flag)
        {
                len = snprintf(buff, size, "%08x-%08x,%s,",
                               phy_saddr,       // phy addr of start address
                               phy_eaddr,       // phy addr of end address
                               mode_str[mode]); // constrain
        }
        else
        {
                len = snprintf(buff, size, "%-9s,%08x-%08x(phy %08x-%08x),%s,",
                               bs_str[bs],      // memory mode
                               saddr,           // dc addr of start address
                               eaddr,           // dc addr of end address
                               phy_saddr,       // phy addr of start address
                               phy_eaddr,       // phy addr of end address
                               mode_str[mode]); // constrain
        }

        if (len < 0)
                goto end_proc;

        ret  += len;
        buff += len;
        size -= len;
        // show entry

        for (j = 24; j >= 0; j -= 8)
        {
                unsigned char type = (addcmd_hi0 >> k) & 0x3;
                unsigned char entry = (table0 >> j) & 0xFF;
                const char* module_name = NULL;

                DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "entry: 0x%X \n", entry);

                if (type == 0)   // un-used entry
                {
                        len = 0;
                }
                else
                {
                        module_name = __module_str(entry);
                        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "module name: %s\n", module_name);
                        if (module_name)
                        {
                                len = snprintf(buff, size, "%s(%s),",
                                               module_name, prot_str[type]);
                        }
                        else
                        {
                                len = snprintf(buff, size, "MODULE_%x(%s),",
                                               entry >> 2, prot_str[type]);
                        }
                }

                if (len < 0)
                        goto end_proc;

                ret  += len;
                buff += len;
                size -= len;
                k    -= 2;
        }

        if(entry >= DC_MTEX_ENTRY_START)
        {
                k = 30;
                for (j = 24; j >= 0; j -= 8)
                {
                        unsigned char type = (addcmd_hi1 >> k) & 0x3;
                        unsigned char entry = (table1 >> j) & 0xFF;
                        const char* module_name = NULL;

                        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "entry: 0x%X \n", entry);

                        if (type == 0)   // un-used entry
                        {
                                len = 0;
                        }
                        else
                        {
                                module_name = __module_str(entry);
                                DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "module name: %s\n", module_name);
                                if (module_name)
                                {
                                        len = snprintf(buff, size, "%s(%s),",
                                                       module_name, prot_str[type]);
                                }
                                else
                                {
                                        len = snprintf(buff, size, "MODULE_%x(%s),",
                                                       entry >> 2, prot_str[type]);
                                }
                        }

                        if (len < 0)
                                goto end_proc;

                        ret  += len;
                        buff += len;
                        size -= len;
                        k    -= 2;
                }
        }

end_proc:

        len = snprintf(buff, size, "\n");

        if (len < 0)
                goto end_proc;

        ret  += len;
        buff += len;
        size -= len;

        return ret;
}
#ifdef DCMT_DCU2

int dbus_to_dc_group_offset(DCID * layout, int len, int slice_size, int offs, DCID id, unsigned int *pOffs)
{
        int i;
        int isFind = -1;
        unsigned int slice_num = 0;
        unsigned int slice_offset = 0;
        unsigned int dc_offset_in_group = 0;
        unsigned int group_size = slice_size * len;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] param - len:%d, slice_size:0x%08x, offs:0x%08x, id:%d, pOffs:0x%08x\n",
                        __FUNCTION__,len,slice_size,offs,id,(unsigned int)pOffs);
        *pOffs = 0;
        //.step check param
        if(group_size <= offs)
        {
                return -1;
        }

        //.step get slice num & offset
        slice_num = offs / slice_size;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get slice_num:0x%08x\n",__FUNCTION__,slice_num);
        slice_offset = offs % slice_size;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get slice_offset:0x%08x\n",__FUNCTION__,slice_offset);

        //.step check former slice
        dc_offset_in_group = 0;
        for(i = 0; i < slice_num; ++i)
        {
                if(layout[i] == id)
                {
                        dc_offset_in_group += slice_size;
                        isFind = 1;
                        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] slice[%d] update dc_offset_in_group:0x%08x\n",__FUNCTION__,i,dc_offset_in_group);
                }
        }

        //.step check last slice
        if(layout[i] == id)
        {
                dc_offset_in_group += slice_offset;
                isFind = 0;
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] slice[%d] update dc_offset_in_group:0x%08x\n",__FUNCTION__,i,dc_offset_in_group);
        }

        //.step get addr
        *pOffs = dc_offset_in_group;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get *pOffs:0x%08x\n",__FUNCTION__,*pOffs);

        return isFind;
}

/*
name    : dbus_to_dc_only_offset
desc    :
        convert dbus offset to dc offset in a region with DCx only mode
input   :
        dbus_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdc_offs- pointer to dc offset after convertion
return  :
        0       - dbus offset is right in DCx region (DCx match param 'id')
        -1      - dbus offset is not in DCx region
*/

int dbus_to_dc_only_offset(unsigned int dbus_offs, unsigned int * pdc_offs, DCID id, int region_id)
{
        if((id == DCID_1) && (region_mode[region_id] == DC1_MODE))
        {
                *pdc_offs = dbus_offs;
        }
        else if((id == DCID_2) && (region_mode[region_id] == DC2_MODE))
        {
                *pdc_offs = dbus_offs;
        }
        else
        {
                *pdc_offs = 0;
                return -1;
        }

        return 0;
}

/*
name    : dbus_to_dc_11_offset
desc    :
        convert dbus offset to dc offset in a region with 1:1 mode
input   :
        dbus_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdc_offs- pointer to dc offset after convertion
return  :
        0       - last slice is right in DCx region (DCx match param 'id')
        -1      - last slice is not in DCx region
*/

int dbus_to_dc_11_offset(unsigned int dbus_offs, unsigned int * pdc_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dbus offset
        unsigned int group_slice = 2;//slice num in each group
        unsigned int group_size = 0;//size for each group
        unsigned int dc_offs_by_group_num = 0;//dc offset for all group num
        unsigned int dc_offs_in_group = 0;//dc offset in now group
        unsigned int dbus_offs_in_group = 0;//dbus offset in now group
        DCID layout[2] = {DCID_1, DCID_2};
        int match_last_slice = 0;

        *pdc_offs = 0;

        //.step get slice size & group size
        slice_size = region_slice[region_id];
        group_size = slice_size * group_slice;

        //.step get group num and dbus_offs_in_group
        group_num = dbus_offs / group_size;
        dbus_offs_in_group = dbus_offs % group_size;

        //.step get dc offset among group num
        dc_offs_by_group_num = group_size * group_num / 2;

        //.step get dc offset in now group
        match_last_slice = dbus_to_dc_group_offset(layout,2,slice_size,dbus_offs_in_group,id,&dc_offs_in_group);

        //.step cacu total dc offset
        *pdc_offs = dc_offs_by_group_num + dc_offs_in_group;

        return match_last_slice;
}

/*
name    : dbus_to_dc_11sramble_offset
desc    :
        convert dbus offset to dc offset in a region with 1:1scramble mode
input   :
        dbus_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdc_offs- pointer to dc offset after convertion
return  :
        0       - last slice is right in DCx region (DCx match param 'id')
        -1      - last slice is not in DCx region
*/
int dbus_to_dc_11sramble_offset(unsigned int dbus_offs, unsigned int * pdc_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dbus offset
        unsigned int group_size = 0;//size for each group
        unsigned int dc_offs_by_group_num = 0;//dc offset for all group num
        //unsigned int dc_offs_in_group = 0;//dc offset in now group
        unsigned int dbus_offs_in_group = 0;//dbus offset in now group
        unsigned int dbus_offs_in_subgroup = 0;//dbus offset in subgroup
        unsigned int subgroup_size = 0;
        //unsigned int subgroup_num_in_group = 0;
        //unsigned int dbus_offs_in_subgroup = 0;
        unsigned int dc_offs_by_subgroup_num = 0;
        unsigned int dc_offs_in_subgroup = 0;
        DCID layout_a[2] = {DCID_1,DCID_2};//start from dc1 layout
        DCID layout_b[2] = {DCID_2,DCID_1};//start from dc2 layout
        DCID * pLayout = layout_a;
        int match_last_slice = 0;

        //.step get slice size & group size
        slice_size = region_slice[region_id];
        group_size = 16*1024;//each 16k is a group
        subgroup_size = 2*slice_size;

        //.step get group num and dbus_offs_in_group
        group_num = dbus_offs / group_size;
        dbus_offs_in_group = dbus_offs % group_size;

        //.step get dc offset among group num
        dc_offs_by_group_num = group_size * group_num / 2;

        //.step get group/sub-group layout
        pLayout = (group_num % 2 == 0)?(layout_a):(layout_b);

        //.step get dc offset in now group
        dc_offs_by_subgroup_num = dbus_offs_in_group / subgroup_size * slice_size;
        dbus_offs_in_subgroup = dbus_offs_in_group % subgroup_size;
        match_last_slice = dbus_to_dc_group_offset(pLayout,2,slice_size,dbus_offs_in_subgroup,id,&dc_offs_in_subgroup);

        //.step cacu total dc offset
        *pdc_offs = dc_offs_by_group_num + dc_offs_by_subgroup_num + dc_offs_in_subgroup;

        return match_last_slice;
}

/*
name    : dbus_to_dc_12_offset
desc    :
        convert dbus offset to dc offset in a region with 1:2 mode
input   :
        dbus_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdc_offs- pointer to dc offset after convertion
return  :
        0       - last slice is right in DCx region (DCx match param 'id')
        -1      - last slice is not in DCx region
*/
int dbus_to_dc_12_offset(unsigned int dbus_offs, unsigned int * pdc_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dbus offset
        unsigned int group_slice = 32;//slice num in each group
        unsigned int group_size = 0;//size for each group
        unsigned int dc_offs_by_group_num = 0;//dc offset for all group num
        unsigned int dc_offs_in_group = 0;//dc offset in now group
        unsigned int dbus_offs_in_group = 0;//dbus offset in now group
        DCID layout[32] =
        {
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2
        };
        int match_last_slice = 0;

        //.step get slice size & group size
        slice_size = region_slice[region_id];
        group_size = slice_size * group_slice;

        //.step get group num and dbus_offs_in_group
        group_num = dbus_offs / group_size;
        dbus_offs_in_group = dbus_offs % group_size;

        //.step get dc offset among group num
        dc_offs_by_group_num = group_size * group_num / 2;

        //.step get dc offset in now group
        match_last_slice = dbus_to_dc_group_offset(layout,32,slice_size,dbus_offs_in_group,id,&dc_offs_in_group);

        //.step cacu total dc offset
        *pdc_offs = dc_offs_by_group_num + dc_offs_in_group;

        return match_last_slice;
}

/*
name    : dbus_to_dc_21_offset
desc    :
        convert dbus offset to dc offset in a region with 2:1 mode
input   :
        dbus_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdc_offs- pointer to dc offset after convertion
return  :
        0       - last slice is right in DCx region (DCx match param 'id')
        -1      - last slice is not in DCx region
*/

int dbus_to_dc_21_offset(unsigned int dbus_offs, unsigned int * pdc_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dbus offset
        unsigned int group_slice = 32;//slice num in each group
        unsigned int group_size = 0;//size for each group
        unsigned int dc_offs_by_group_num = 0;//dc offset for all group num
        unsigned int dc_offs_in_group = 0;//dc offset in now group
        unsigned int dbus_offs_in_group = 0;//dbus offset in now group
        DCID layout[32] =
        {
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_2
        };
        int match_last_slice = 0;

        //.step get slice size & group size
        slice_size = region_slice[region_id];
        group_size = slice_size * group_slice;

        //.step get group num and dbus_offs_in_group
        group_num = dbus_offs / group_size;
        dbus_offs_in_group = dbus_offs % group_size;

        //.step get dc offset among group num
        dc_offs_by_group_num = group_size * group_num / 2;

        //.step get dc offset in now group
        match_last_slice = dbus_to_dc_group_offset(layout,32,slice_size,dbus_offs_in_group,id,&dc_offs_in_group);

        //.step cacu total dc offset
        *pdc_offs = dc_offs_by_group_num + dc_offs_in_group;

        return match_last_slice;
}


/*
name    : dbus_to_dc_offset
desc    :
        convert dbus offset to dc offset in a region
input   :
        dbus_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdc_offs- pointer to dc offset after convertion
return  :
        0       - last slice is right in DCx region (DCx match param 'id')
        -1      - last slice is not in DCx region
*/
int dbus_to_dc_offset(unsigned int dbus_offs, unsigned int * pdc_offs, DCID id, int region_id)
{
        int ret = 0;

        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] param - dbus_offs:0x%08x , pdc_offs:0x%08x, id:%d, region_id:%d\n",__FUNCTION__,dbus_offs,(unsigned int)pdc_offs,id,region_id);
        switch(region_mode[region_id])
        {
        case DC1_MODE:
        case DC2_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use DC1/DC2 only mode \n",__FUNCTION__);
                ret = dbus_to_dc_only_offset(dbus_offs,pdc_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] DC1/DC2 only mode ret:%d, *pdc_offs:0x%08x\n",__FUNCTION__,ret,*pdc_offs);
                break;
        case IB_1_1_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_1_1_MODE mode \n",__FUNCTION__);
                ret = dbus_to_dc_11_offset(dbus_offs,pdc_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_1_1_MODE mode ret:%d, *pdc_offs:0x%08x\n",__FUNCTION__,ret,*pdc_offs);
                break;
        case IB_1_1_SCRMBLE_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_1_1_SCRMBLE_MODE mode \n",__FUNCTION__);
                ret = dbus_to_dc_11sramble_offset(dbus_offs,pdc_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_1_1_SCRMBLE_MODE mode ret:%d, *pdc_offs:0x%08x\n",__FUNCTION__,ret,*pdc_offs);
                break;
        case IB_1_2_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_1_2_MODE mode \n",__FUNCTION__);
                ret = dbus_to_dc_12_offset(dbus_offs,pdc_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_1_2_MODE mode ret:%d, *pdc_offs:0x%08x\n",__FUNCTION__,ret,*pdc_offs);
                break;
        case IB_2_1_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_2_1_MODE mode \n",__FUNCTION__);
                ret = dbus_to_dc_21_offset(dbus_offs,pdc_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_2_1_MODE mode ret:%d, *pdc_offs:0x%08x\n",__FUNCTION__,ret,*pdc_offs);
                break;
        default:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] ERROR no proper mode found!\n",__FUNCTION__);
                break;
        }
        return ret;
}
#endif  // #ifdef DCMT_DCU2
/*
name    : dbus_to_dc_addr
desc    :
        convert dbus address to dc address
input   :
        dbus_addr - dbus address, unit is byte
        id      - which DC the user want to convert
        start_end - start address or end address
output  :
        pdc_addr- pointer to dc address after convertion
return  :
        0       - last slice is right in DCx region (DCx match param 'id')
        -1      - last slice is not in DCx region
*/
int dbus_to_dc_addr(unsigned int dbus_addr, unsigned int * pdc_addr, DCID id, START_END start_end)
{
#ifdef DCMT_DCU2
        unsigned int seq_id = 0;//seq for ib_seq_bound[seq][region]
        unsigned int region_id = 0;//which region the dbus/dc addr fall in
        unsigned int dbus_region_base = 0;//dbus base addr in this region
        unsigned int dbus_region_offset = 0;//dbus addr offset between this region
        unsigned int dc_region_base = 0;//dc base addr in this region
        unsigned int dc_region_offset = 0;//dc addr offset between this region
        int i;
        int tmp;
        unsigned int end_minus = 0;

        *pdc_addr = 0;

        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] param - dbus_addr:0x%08x , pdc_addr:0x%08x, id:%d, start_end:%d\n",__FUNCTION__,dbus_addr,(unsigned int)pdc_addr,id,start_end);
        //step. get seq_id for ib_seq_bound
        if(id == DCID_1)
        {
                seq_id = SEQ_DC1;
        }
        else if(id == DCID_2)
        {
                seq_id = SEQ_DC2;
        }
        else
        {
                return -1;
        }

        //step. get region id
        for(i = 1; i < BOUND_NUM; ++i)
        {
                if(dbus_addr < ib_seq_bound[SEQ_PHY][i])
                {
                        break;
                }
        }
        region_id = i - 1;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get region_id:%d\n",__FUNCTION__,region_id);

        //step. get dbus region base addr
        dbus_region_base = ib_seq_bound[SEQ_PHY][region_id];
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dbus_region_base:0x%08x\n",__FUNCTION__,dbus_region_base);

        //step. get dc region base addr
        dc_region_base = ib_seq_bound[seq_id][region_id];
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dc_region_base:0x%08x\n",__FUNCTION__,dc_region_base);

        //step. get dbus offset between the region
        dbus_region_offset = dbus_addr - dbus_region_base;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dbus_region_offset:0x%08x\n",__FUNCTION__,dbus_region_offset);

        //step. convert dbus offset to dc offset
        tmp = dbus_to_dc_offset(dbus_region_offset,&dc_region_offset,id,region_id);
        if(tmp != 0)
        {
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] dbus_to_dc_offset return:%d\n",__FUNCTION__,tmp);
                if(start_end == DCMT_RANGE_END)
                {
                        end_minus = DCMT_ALIGN_SIZE;
                        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] change end_minus to 0x%08x\n",__FUNCTION__,end_minus);
                }
        }

        //setp. get final dc address
        *pdc_addr = dc_region_base + dc_region_offset;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] ret dc_addr:0x%08x(dc_region_base:0x%08x + dc_region_offset:0x%08x)\n",__FUNCTION__,*pdc_addr,dc_region_base,dc_region_offset);
        if(*pdc_addr >= end_minus)// minus 32B rear if addr is a end addr and the last slice if for another DCID.
        {
                *pdc_addr -= end_minus;
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] minus *pdc_addr to 0x%08x\n",__FUNCTION__,*pdc_addr);
        }
        else
        {
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] dbus address -> dc address failed!\n",__FUNCTION__);
                return -1;
        }

        if(*pdc_addr > DC_SYS_ADDR_MAX)
        {
                *pdc_addr = DC_SYS_ADDR_MAX;
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] force change *pdc_addr to 0x%08x\n",__FUNCTION__,*pdc_addr);
        }

        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "\n\n\n");
#else    // #ifdef DCMT_DCU2
        *pdc_addr = dbus_addr;
#endif   // #ifdef DCMT_DCU2
        return 0;
}


/*------------------dbus_addr -> dc_addr algorithm end---------------------*/

#ifdef DCMT_DCU2
/*-----------------dc_addr -> dbus_addr algorithm start--------------------*/

/*
name    : dc_to_dbus_group_offset
desc    : convert dc offset to dbus offset in a group
input   :
        layout  - dbus group layout, unit is slice
        len     - slice num in a dbus group
        slice_size - slice size, unit is Byte
        offs    - dc offset in group
        id      - which DC the user want to convert
output  :
        pOffs- pointer to dbus offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/
int dc_to_dbus_group_offset(DCID * layout, int len, int slice_size, int offs, DCID id, unsigned int *pOffs)
{
        int i,j;
        unsigned int slice_num = 0;
        unsigned int slice_offset = 0;
        unsigned int dbus_offset_in_group = 0;
        unsigned int group_size = slice_size * len;

        //.step check param
        if(group_size <= offs)
        {
                return -1;
        }

        //.step get dc slice num & offset
        slice_num = offs / slice_size;
        slice_offset = offs % slice_size;

        //.step check former slice
        dbus_offset_in_group = 0;
        for(i = 0, j = 0; i < len; i++)
        {

                if(layout[i] == id)
                {
                        j++;
                        if(j > slice_num)
                        {
                                break;
                        }
                }
                dbus_offset_in_group += slice_size;
        }

        //.step add offset in slice
        dbus_offset_in_group += slice_offset;

        //.step get addr
        *pOffs = dbus_offset_in_group;

        return 0;
}

/*
name    : dc_to_dbus_only_offset
desc    :
        convert dc offset to dbus offset in a region with DCx only mode
input   :
        dc_offs - dc offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdbus_offs- pointer to dbus offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/
int dc_to_dbus_only_offset(unsigned int dc_offs, unsigned int * pdbus_offs, DCID id, int region_id)
{
        if((id == DCID_1) && (region_mode[region_id] == DC1_MODE))
        {
                *pdbus_offs = dc_offs;
        }
        else if((id == DCID_2) && (region_mode[region_id] == DC2_MODE))
        {
                *pdbus_offs = dc_offs;
        }
        else
        {
                return -1;
        }

        return 0;
}

/*
name    : dc_to_dbus_11_offset
desc    :
        convert dc offset to dbus offset in a region with 1:1 mode
input   :
        dc_offs - dc offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdbus_offs- pointer to dbus offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/

int dc_to_dbus_11_offset(unsigned int dc_offs, unsigned int * pdbus_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dc offset
        unsigned int dc_offs_in_group = 0;//dc offset in a group
        unsigned int dc_group_size = 0;//the size of dc group
        unsigned int dbus_group_slice = 2;//the num of slice for a group in dbus
        unsigned int dbus_group_size = 0;//size for each group mapping to dbus
        unsigned int dbus_offs_by_group_num = 0;//dbus offset by group num
        unsigned int dbus_offs_in_group = 0;//dbus offset in a group

        //.step get slice size & dbus group size
        slice_size = region_slice[region_id];
        dbus_group_size = slice_size * dbus_group_slice;
        dc_group_size = slice_size;
        //.step get group num & dc offset in group
        group_num = dc_offs / dc_group_size;
        dc_offs_in_group = dc_offs % dc_group_size;
        //.step cacu dbus addr by group
        dbus_offs_by_group_num = dbus_group_size * group_num;
        //.step cacu dbus addr in group
        dbus_offs_in_group = (id == DCID_1)?(dc_offs_in_group):(dc_offs_in_group + slice_size);
        //.step cacu dbus offset in region
        *pdbus_offs = dbus_offs_by_group_num + dbus_offs_in_group;

        return 0;
}

/*
name    : dc_to_dbus_11sramble_offset
desc    :
        convert dc offset to dbus offset in a region with 1:1 scramble mode
input   :
        dc_offs - dc offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdbus_offs- pointer to dbus offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/

int dc_to_dbus_11sramble_offset(unsigned int dc_offs, unsigned int * pdbus_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dbus offset
        unsigned int dbus_group_size = 16*1024;//dbus group size
        unsigned int dbus_group_slice = 0;
        unsigned int dbus_offs_by_group_num = 0;//dc offset for all group num
        //unsigned int dbus_offs_in_group = 0;//dc offset in now group
        unsigned int dc_group_slice = 0;//num of slice for each group in dc range
        unsigned int dc_group_size = 0;//size for each group in dc range
        unsigned int dc_offs_in_group = 0;//dbus offset in now group
        unsigned int dbus_subgroup_slice = 2;//use 2 slice as a subgroup
        unsigned int dbus_subgroup_size = 0;
        unsigned int dc_subgroup_size = 0;
        //unsigned int subgroup_size = 0;//sub group size
        unsigned int subgroup_num = 0;
        unsigned int dc_offs_in_subgroup = 0;
        //unsigned int subgroup_num_in_group = 0;
        //unsigned int dbus_offs_in_subgroup = 0;
        unsigned int dbus_offs_by_subgroup_num = 0;
        unsigned int dbus_offs_in_subgroup = 0;
        DCID layout_a[2] = {DCID_1,DCID_2};//start from dc1 layout
        DCID layout_b[2] = {DCID_2,DCID_1};//start from dc2 layout
        DCID * pLayout = layout_a;

        //.step get dc_group_slice,group_num,dbus_group_size
        slice_size = region_slice[region_id];
        dbus_group_slice = dbus_group_size / slice_size;
        dc_group_slice = dbus_group_slice / 2;
        dc_group_size = dc_group_slice * slice_size;
        //.step get dbus_offs_by_group_num
        group_num = dc_offs / dc_group_size;
        dbus_offs_by_group_num = dbus_group_size * group_num;
        //.step get dc_offs_in_group
        dc_offs_in_group = dc_offs % dc_group_size;
        //.step get subgroup_num
        dc_subgroup_size = slice_size;
        dbus_subgroup_size = dbus_subgroup_slice * slice_size;
        subgroup_num = dc_offs_in_group / dc_subgroup_size;
        //.step get dbus_offs_by_subgroup_num
        dbus_offs_by_subgroup_num = dbus_subgroup_size * subgroup_num;
        //.step get dbug_offs_in_subgroup
        dc_offs_in_subgroup = dc_offs_in_group % dc_subgroup_size;
        pLayout = (group_num % 2 == 0)?(layout_a):(layout_b);
        if(dc_to_dbus_group_offset(pLayout,2,slice_size,dc_offs_in_subgroup,id,&dbus_offs_in_subgroup))
        {
                return -1;
        }
        //.step cacu dbus offs
        *pdbus_offs = dbus_offs_by_group_num + dbus_offs_by_subgroup_num + dbus_offs_in_subgroup;

        return 0;
}

/*
name    : dc_to_dbus_12_offset
desc    :
        convert dc offset to dbus offset in a region with 1:2 mode
input   :
        dc_offs - dc offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdbus_offs- pointer to dbus offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/

int dc_to_dbus_12_offset(unsigned int dc_offs, unsigned int * pdbus_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dc offset
        unsigned int dc_offs_in_group = 0;//dc offset in a group
        unsigned int dc_group_slice = 4;//the num of slice for a group in dbus
        unsigned int dc_group_size = 0;//the size of dc group
        unsigned int dbus_group_slice = 32;//the num of slice for a group in dbus
        unsigned int dbus_group_size = 0;//size for each group mapping to dbus
        unsigned int dbus_offs_by_group_num = 0;//dbus offset by group num
        unsigned int dbus_offs_in_group = 0;//dbus offset in a group
        DCID layout[32] =
        {
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2, DCID_2,
                DCID_1, DCID_2
        };

        //.step get slice size & group size
        slice_size = region_slice[region_id];
        dbus_group_size = slice_size * dbus_group_slice;
        dc_group_size = slice_size * dc_group_slice;
        //.step get group num & dc offset in group
        group_num = dc_offs / dc_group_size;
        dc_offs_in_group = dc_offs % dc_group_size;
        //.step cacu dbus addr by group
        dbus_offs_by_group_num = dbus_group_size * group_num;
        //.step cacu dbus addr in group
        if(dc_to_dbus_group_offset(layout,32,slice_size,dc_offs_in_group,id,&dbus_offs_in_group))
        {
                return -1;
        }
        //.step cacu dbus offset in region
        *pdbus_offs = dbus_offs_by_group_num + dbus_offs_in_group;

        return 0;
}

/*
name    : dc_to_dbus_21_offset
desc    :
        convert dc offset to dbus offset in a region with 2:1 mode
input   :
        dc_offs - dc offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdbus_offs- pointer to dbus offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/

int dc_to_dbus_21_offset(unsigned int dc_offs, unsigned int * pdbus_offs, DCID id, int region_id)
{
        unsigned int slice_size = 0;//slice size by ib setting
        unsigned int group_num = 0;//group num in dc offset
        unsigned int dc_offs_in_group = 0;//dc offset in a group
        unsigned int dc_group_slice = 4;//the num of slice for a group in dbus
        unsigned int dc_group_size = 0;//the size of dc group
        unsigned int dbus_group_slice = 32;//the num of slice for a group in dbus
        unsigned int dbus_group_size = 0;//size for each group mapping to dbus
        unsigned int dbus_offs_by_group_num = 0;//dbus offset by group num
        unsigned int dbus_offs_in_group = 0;//dbus offset in a group
        DCID layout[32] =
        {
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_1, DCID_2,
                DCID_1, DCID_2
        };

        //.step get slice size & group size
        slice_size = region_slice[region_id];
        dbus_group_size = slice_size * dbus_group_slice;
        dc_group_size = slice_size * dc_group_slice;
        //.step get group num & dc offset in group
        group_num = dc_offs / dc_group_size;
        dc_offs_in_group = dc_offs % dc_group_size;
        //.step cacu dbus addr by group
        dbus_offs_by_group_num = dbus_group_size * group_num;
        //.step cacu dbus addr in group
        if(dc_to_dbus_group_offset(layout,32,slice_size,dc_offs_in_group,id,&dbus_offs_in_group))
        {
                return -1;
        }
        //.step cacu dbus offset in region
        *pdbus_offs = dbus_offs_by_group_num + dbus_offs_in_group;

        return 0;
}

/*
name    : dc_to_dbus_offset
desc    :
        convert dc offset to dbus offset in a region
input   :
        dc_offs - dbus offset in this region, unit is byte
        id      - which DC the user want to convert
        region_id - the region of this offset
output  :
        pdbus_offs - pointer to dc offset after convertion
return  :
        0       - convertion OK
        -1      - param error
*/

int dc_to_dbus_offset(unsigned int dc_offs, unsigned int * pdbus_offs, DCID id, int region_id)
{
        int ret = 0;

        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] param - dc_offs:0x%08x , pdbus_offs:0x%08x, id:%d, region_id:%d\n",__FUNCTION__,dc_offs,(unsigned int)pdbus_offs,id,region_id);
        switch(region_mode[region_id])
        {
        case DC1_MODE:
        case DC2_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use DC1/DC2 only mode \n",__FUNCTION__);
                ret = dc_to_dbus_only_offset(dc_offs,pdbus_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] DC1/DC2 only mode ret:%d, *pdbus_offs:0x%08x\n",__FUNCTION__,ret,*pdbus_offs);
                break;
        case IB_1_1_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_1_1_MODE mode \n",__FUNCTION__);
                ret = dc_to_dbus_11_offset(dc_offs,pdbus_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_1_1_MODE mode ret:%d, *pdbus_offs:0x%08x\n",__FUNCTION__,ret,*pdbus_offs);
                break;
        case IB_1_1_SCRMBLE_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_1_1_SCRMBLE_MODE mode \n",__FUNCTION__);
                ret = dc_to_dbus_11sramble_offset(dc_offs,pdbus_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_1_1_SCRMBLE_MODE mode ret:%d, *pdbus_offs:0x%08x\n",__FUNCTION__,ret,*pdbus_offs);
                break;
        case IB_1_2_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_1_2_MODE mode \n",__FUNCTION__);
                ret = dc_to_dbus_12_offset(dc_offs,pdbus_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_1_2_MODE mode ret:%d, *pdbus_offs:0x%08x\n",__FUNCTION__,ret,*pdbus_offs);
                break;
        case IB_2_1_MODE:
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] use IB_2_1_MODE mode \n",__FUNCTION__);
                ret = dc_to_dbus_21_offset(dc_offs,pdbus_offs,id,region_id);
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] IB_2_1_MODE mode ret:%d, *pdbus_offs:0x%08x\n",__FUNCTION__,ret,*pdbus_offs);
                break;
        default:
                break;
        }
        return ret;
}
#endif
/*
name    : dc_to_dbus_addr
desc    :
        convert dc address to dbus address
input   :
        dc_addr - dbus address, unit is byte
        id      - which DC the user want to convert
output  :
        pdbus_addr- pointer to dc address after convertion
return  :
        0       - convertion OK
        -1      - param error
*/

int dc_to_dbus_addr(unsigned int dc_addr, unsigned int * pdbus_addr, DCID id)
{
#ifdef DCMT_DCU2
        unsigned int dc_region_base = 0;
        unsigned int dc_region_offset = 0;
        unsigned int dbus_region_base = 0;
        unsigned int dbus_region_offset = 0;
        unsigned int seq_id = 0;//seq for ib_seq_bound[seq][region]
        unsigned int region_id = 0;
        int i;

        *pdbus_addr = 0;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] param - dc_addr:0x%08x , pdbus_addr:0x%08x, id:%d\n",__FUNCTION__,dc_addr,(unsigned int)pdbus_addr,id);

        if(id == DCID_1)
        {
                seq_id = SEQ_DC1;
        }
        else if(id == DCID_2)
        {
                seq_id = SEQ_DC2;
        }
        else
        {
                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] param:mode error!\n", __FUNCTION__);
                return -1;
        }

        //step. get region id
        for(i = 1; i < BOUND_NUM; ++i)
        {
                if(dc_addr < ib_seq_bound[seq_id][i])
                {
                        break;
                }
        }
        region_id = i - 1;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get region_id:%d\n",__FUNCTION__,region_id);

        //step. get dc region base & offset
        dc_region_base = ib_seq_bound[seq_id][region_id];
        dc_region_offset = dc_addr - dc_region_base;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dc_region_base:0x%08x\n",__FUNCTION__,dc_region_base);
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dc_region_offset:0x%08x\n",__FUNCTION__,dc_region_offset);
        //step. convert dc offset to dbus offset in a region
        if(dc_to_dbus_offset(dc_region_offset,&dbus_region_offset,id,region_id) != 0)
        {

                DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] call dc_to_dbus_offset() return fail!\n",__FUNCTION__);
                return -1;
        }
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dbus_region_offset:0x%08x\n",__FUNCTION__,dbus_region_offset);

        //step. get region start phy addr
        dbus_region_base = ib_seq_bound[SEQ_PHY][region_id];
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get dbus_region_base:0x%08x\n",__FUNCTION__,dbus_region_base);
        *pdbus_addr = dbus_region_base + dbus_region_offset;
        DCMT_LOG(DCMT_LOG_ADDR, KERN_ERR, "[%s] get *pdbus_addr:0x%08x (dbus_region_base:0x%08x + dbus_region_offset:0x%08x)\n\n\n",__FUNCTION__,*pdbus_addr,dbus_region_base,dbus_region_offset);

#else   // #ifdef DCMT_DCU2
        *pdbus_addr = dc_addr;
#endif  //#ifdef DCMT_DCU2

        return 0;
}
/*-------------------dc_addr -> dc_addr algorithm end----------------------*/

//---------------------------------developer logic---------------------------------
/*change log setting*/
int change_dcmt_log_setting(unsigned int flag,int set_clear)
{
        if(set_clear)
        {
                dcmt_log_setting |=  flag;
        }
        else
        {
                dcmt_log_setting &= ~flag;
        }

        return dcmt_log_setting;
}

static int apply_log_change(char * str,int set_clear)
{
        if(isStrFullMatch(str,"all",0) == 0)
        {
                change_dcmt_log_setting(0xffffffff,set_clear);
        }
        else if(isStrFullMatch(str,"init",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_INIT,set_clear);
        }
        else if(isStrFullMatch(str,"set",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_SET,set_clear);
        }
        else if(isStrFullMatch(str,"isr",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_ISR,set_clear);
        }
        else if(isStrFullMatch(str,"err",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_ERR,set_clear);
        }
        else if(isStrFullMatch(str,"cmd",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_CMD,set_clear);
        }
        else if(isStrFullMatch(str,"tip",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_UTIP,set_clear);
        }
        else if(isStrFullMatch(str,"addr",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_ADDR,set_clear);
        }
        else if(isStrFullMatch(str,"dbg",0) == 0)
        {
                change_dcmt_log_setting(DCMT_LOG_DBG,set_clear);
        }
        else
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_WARNING, "unknow change log param : %s!\n", str);
                return -1;
        }

        DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "change DCMT log to : 0x%08x!\n", dcmt_log_setting);

        return 0;
}
//---------------------------------developer logic---------------------------------
/*module_search_by_moduleID*/
int module_table_search_byID(MODULE_SEARCH_TABLE *table,int table_len,int start_index,unsigned char module_id)
{
        int i,j;

        for(i = start_index;i < table_len;++i)
        {
                for(j = 0;j < table[i].table_len;++j)
                {
                        if(table[i].table[j] == module_id)
                        {
                                return i;
                        }
                }
        }

        return -1;
}


/*module_search_by_key
        input : key_words
        output : module_num, module name string(split by ',')
*/
int module_table_search(const MODULE_SEARCH_TABLE *table,int table_len,char * key)
{
        int i;
        int len;
        int tmp;

        for(i = 0;i < table_len;++i)
        {
                len = strlen(key);
                tmp = strlen(table[i].key);
                if(len < tmp)
                {
                        len = tmp;
                }
                //DC_MT_ERR("compare len : %d ([%s]:%d, [%s]:%d)\n",len,table[i].key,strlen(table[i].key),key,strlen(key));
                if(strncmp(key, table[i].key, len) == 0)
                {
                        return i;
                }
        }

        return -1;
}

void dump_key_table_desc(int id)
{
        int i;
        char * desc_buf;
        char * buf;
        int offset;
        int remain;
        int buf_size = 512;

        desc_buf = kmalloc(buf_size,GFP_KERNEL);
        if(!desc_buf)
        {
                DC_MT_ERR("no mem to malloc for dump key_table\n");
                return;
        }

        buf = desc_buf;
        remain = buf_size;

        memset(desc_buf, 0, buf_size);
        offset = snprintf(buf,remain,"group " FYELLOW_START "%-10s" FCOLOR_END " : ", key_table[id].key);
        buf += offset;
        remain -= offset;
        for(i = 0; i < key_table[id].table_len; ++i)
        {
                offset = snprintf(buf,remain," %s", __module_str(key_table[id].table[i]));
                buf += offset;
                remain -= offset;
        }

        DC_MT_ERR("%s\n",desc_buf);

        if(desc_buf)
        {
                kfree(desc_buf);
        }
}

void dump_module_key_table_single(int id)
{
        int i;

        DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "%s include these modules: \n",key_table[id].key);
        for(i = 0; i < key_table[id].table_len; ++i)
        {
                DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "\t[%02d] : %s(0x%02x)\n",i+1,__module_str(key_table[id].table[i]),key_table[id].table[i]);
        }
}

void dump_module_key_table(char * key)
{
        int i,total;

        total = sizeof(key_table)/sizeof(MODULE_SEARCH_TABLE);

        DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "------------DC_SYS MODULE KEY TABLE------------\n");
        if(key)
        {
                i = module_table_search(key_table,total,key);
                if(i >= 0)
                {
                        dump_module_key_table_single(i);
                }
        }
        else
        {
                for(i = 0;i < total;++i)
                {
                        dump_module_key_table_single(i);
                }
        }
        DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "-----------------------------------------------\n");
}

void dump_carvedout_key(void)
{
        DC_MT_ERR("You can use these key_words for carvedout mem:\n"
                "\t DEMOD\n"
                "\t VDEC_RINGBUF\n"
                "\t LOGBUF\n"
                "\t SCALER_MDOMAIN\n"
                "\t SCALER_OD\n"
                "\t TP\n"
                "\t GAL\n"
                //"\t SCALER\n"
                //"\t AV_DMEM\n"
                "\t MAP_RPC\n"
        );
}

//show_dcmt_set_cmd
void show_dcmt_set_cmd(void)
{
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "You should use dcmt setting cmd like this format!!\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\nsimple cmd : \n"
                "\t set <start>,<end>\n"
                "\t\"set  0x108000,0x700000\" > /sys/mt/cntl\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "full cmd : \n"
                "\t set <start>,<end> <ip: ... > <mode: ... > <type: ... > <mem: ... >\n"
                "\techo \"set  0x108000,0x700000 ip:SB2_ACPU,SB2_ACPU2(rw),SB2_VCPU,SB2_VCPU2(r) mode:1 type:sb mem:0\" > /sys/mt/cntl \n");
}

void dump_dcmt_desc(const char * msg,DC_MT_DESC * pDesc)
{
        int i;
        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "%s\n",msg);
        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "mode : 0x%x\n",pDesc->mode);
        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "start : 0x%08x\n",(unsigned int)pDesc->start);
        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "end : 0x%08x\n",(unsigned int)pDesc->end);
        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "type : 0x%x (0:na 1:s 2:b 3:sb)\n",pDesc->type);
        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "module_max : 0x%x\n",pDesc->module_max);

        for(i = 0;i < 8;++i)
        {
                if(pDesc->ip_entry[i].prot)
                {
                        //DC_MT_ERR("module[%d] : %02x(%s, %s)\n",i,pDesc->ip_entry[i].module,__module_str(pDesc->ip_entry[i].module),prot_str[pDesc->ip_entry[i].prot]);
                        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "module[%d] : %02x,%d\n",i,pDesc->ip_entry[i].module,pDesc->ip_entry[i].prot);
                }
        }
}

int get_dcmt_modues(char * buff)
{
        int i,j,cnt = 0,ret = 0;
        unsigned char id;
        char * name;
        int offset = 0,check_id;

        for(i = 0;i < 16;++i)
        {
                id = MODULE_ID(i,0xf);
                name = __module_str(id);
                if(name == NULL)
                {
                        continue;
                }

                offset = sprintf(buff, "Bridge-%x : " FRED_START "%s" FCOLOR_END, i, name);
                buff += offset;
                ret += offset;

                offset = sprintf(buff,  "%s",FYELLOW_START);
                buff += offset;
                ret += offset;

                cnt = 0;
                for(j = 0;j < 15;++j)
                {
                        id = MODULE_ID(i,j);
                        name = __module_str(id);

                        if(name == NULL)
                        {
                                continue;
                        }

                        check_id = __module_id(name);
                        if((check_id < 0) || (check_id != id))
                        {
                                continue;
                        }

                        //DC_MT_ERR("add %s(%x-%x) @ offset:%d\n",name,i,j,offset);

                        if(cnt%4 == 0)          // 4 module name each line
                        {
                                offset = sprintf(buff, "\n    ");
                                buff += offset;
                                ret += offset;
                        }


                        offset = sprintf(buff, "%-25s", name);
                        buff += offset;
                        ret += offset;

                        cnt++;
                }

                offset = sprintf(buff,  "%s\n", FCOLOR_END);
                        buff += offset;
                        ret += offset;
                //DC_MT_ERR("%s",desc_buf);
        }

        return ret;
}

int get_module_keys(char * buff)
{
        int i,cnt = 0,ret = 0;
        char * name;
        //char * desc_buf;
        int offset=0;
        int total;

        total = sizeof(key_table)/sizeof(MODULE_SEARCH_TABLE);

        offset = sprintf(buff, "Module Groups : \n    ");
        buff += offset;
        ret +=offset;

        offset = sprintf(buff,  "%s",FYELLOW_START);
        buff += offset;
        ret += offset;

        for(i = 0;i < total;++i)
        {
                name = key_table[i].key;

                if(name == NULL)
                {
                        continue;
                }

                //DC_MT_ERR("add %s(%x-%x) @ offset:%d\n",name,i,j,offset);
                offset = sprintf(buff, "%-25s", name);
                buff += offset;
                ret +=offset;

                cnt++;
                if(cnt%4 == 0)
                {
                        offset = sprintf(buff, "\n    ");
                        buff += offset;
                        ret +=offset;
                }

                //DC_MT_ERR("%s",desc_buf);
        }

        offset = sprintf(buff,  "%s", FCOLOR_END);
        buff += offset;
        ret += offset;

        return ret;
}


void dump_dcmt_common_regs(void)
{
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "DC1 MISC", rtd_inl(DC_SYS_DC_MT_MISC_reg), DC_SYS_DC_MT_MISC_reg);
#ifdef DCMT_DCU2
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "DC2 MISC", rtd_inl(DC2_SYS_DC_MT_MISC_reg), DC2_SYS_DC_MT_MISC_reg);
#endif
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SCPU INTR", rtd_inl(INT_CTRL_SCPU_reg), INT_CTRL_SCPU_reg);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ACPU INTR", rtd_inl(INT_CTRL_ACPU_reg), INT_CTRL_ACPU_reg);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "VCPU INTR", rtd_inl(INT_CTRL_VCPU_reg), INT_CTRL_VCPU_reg);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "KCPU INTR", rtd_inl(INT_CTRL_KCPU_reg), INT_CTRL_KCPU_reg);
#ifdef DCMT_DCU2
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_PHY_BOUND1",rtd_inl(0xb803f000),0xb803f000);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_PHY_BOUND2",rtd_inl(0xb803f004),0xb803f004);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_PHY_BOUND3",rtd_inl(0xb803f008),0xb803f008);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_DC1_BOUND1",rtd_inl(0xb803f00C),0xb803f00C);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_DC1_BOUND2",rtd_inl(0xb803f010),0xb803f010);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_DC1_BOUND3",rtd_inl(0xb803f014),0xb803f014);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_DC2_BOUND1",rtd_inl(0xb803f018),0xb803f018);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_DC2_BOUND2",rtd_inl(0xb803f01C),0xb803f01C);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SEQ_DC2_BOUND3",rtd_inl(0xb803f020),0xb803f020);
#endif
}

void dump_dcmt_regs(dcmt_addr_desc * pDesc)
{
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "dump control regs:\n");
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "MODE", rtd_inl(pDesc->mode_addr), pDesc->mode_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "TYPE", rtd_inl(pDesc->type_addr), pDesc->type_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "SADDR", rtd_inl(pDesc->saddr_addr), pDesc->saddr_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "EADDR", rtd_inl(pDesc->eaddr_addr), pDesc->eaddr_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "TABLE0", rtd_inl(pDesc->table0_addr), pDesc->table0_addr);
        if(pDesc->table1_addr)
        {
                DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "TABLE1", rtd_inl(pDesc->table1_addr), pDesc->table1_addr);
        }
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_HI0", rtd_inl(pDesc->hi0_addr), pDesc->hi0_addr);
        if(pDesc->hi1_addr)
        {
                DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_HI1", rtd_inl(pDesc->hi1_addr), pDesc->hi1_addr);
        }

        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR EN", rtd_inl(pDesc->int_en_addr), pDesc->int_en_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR SYS2 EN", rtd_inl(pDesc->int_en_sys2_addr), pDesc->int_en_sys2_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR SYS3 EN", rtd_inl(pDesc->int_en_sys3_addr), pDesc->int_en_sys3_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR ROUTING", rtd_inl(pDesc->intr_routing_addr), pDesc->intr_routing_addr);

        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "dump status regs:\n");
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_HI0", rtd_inl(pDesc->hi0_addr), pDesc->hi0_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_LO", rtd_inl(pDesc->lo_addr), pDesc->lo_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_SA", rtd_inl(pDesc->sa_addr), pDesc->sa_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_HI0_SYS2", rtd_inl(pDesc->hi0_sys2_addr), pDesc->hi0_sys2_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_LO_SYS2", rtd_inl(pDesc->lo_sys2_addr), pDesc->lo_sys2_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_SA_SYS2", rtd_inl(pDesc->sa_sys2_addr), pDesc->sa_sys2_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_HI0_SYS3", rtd_inl(pDesc->hi0_sys3_addr), pDesc->hi0_sys3_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_LO_SYS3", rtd_inl(pDesc->lo_sys3_addr), pDesc->lo_sys3_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "ADDCMD_SA_SYS3", rtd_inl(pDesc->sa_sys3_addr), pDesc->sa_sys3_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR PEND", rtd_inl(pDesc->int_status_addr), pDesc->int_status_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR SYS2 PEND", rtd_inl(pDesc->int_status_sys2_addr), pDesc->int_status_sys2_addr);
        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "%-16s : %08x @ %08x\n", "INTR SYS3 PEND", rtd_inl(pDesc->int_status_sys3_addr), pDesc->int_status_sys3_addr);
}

void dump_dcmt_regs_all(void)
{
        DCID id;
        unsigned int entry;

        dump_dcmt_common_regs();
        for(id = DCID_1; id < DC_NUM; ++id)
        {
                for(entry = 0; entry < DC_MT_ENTRY_COUNT; ++entry)
                {
                        DCMT_LOG(DCMT_LOG_CMD|DCMT_LOG_ISR, KERN_ERR, "***dump reg DCU%d, entry%d***\n", id + 1, entry);
                        dump_dcmt_regs(&dc_regs[id][entry]);
                }
        }
}

int dump_memtrash_log(DCID dc_id, unsigned int entry, MT_SYS_ID sys_id) //DC1/2 MT/MTEX DS_SYS1/2/3
{
        unsigned int dcmt_mode;
        unsigned int intr_status = 0;
        int i;
        char msg[512];
        unsigned int trap_addr;
        unsigned int phy_addr;
        unsigned char module_id;
        int log_cnt = 0;
        unsigned int addcmd_hi = 0;
        unsigned int addcmd_lo = 0;
        unsigned int addcmd_sa = 0;

        if(sys_id >= MT_MAX)
        {
                return -1;
        }

        //.step get intr mode
        if(sys_id == MT_SYS1)
        {
                intr_status = rtd_inl(dc_regs[dc_id][entry].int_status_addr);
                addcmd_hi = rtd_inl(dc_regs[dc_id][entry].hi0_addr);
                addcmd_lo = rtd_inl(dc_regs[dc_id][entry].lo_addr);
                addcmd_sa = rtd_inl(dc_regs[dc_id][entry].sa_addr);
        }
        else if(sys_id == MT_SYS2)
        {
                intr_status = rtd_inl(dc_regs[dc_id][entry].int_status_sys2_addr);
                addcmd_hi = rtd_inl(dc_regs[dc_id][entry].hi0_sys2_addr);
                addcmd_lo = rtd_inl(dc_regs[dc_id][entry].lo_sys2_addr);
                addcmd_sa = rtd_inl(dc_regs[dc_id][entry].sa_sys2_addr);
        }
        else if(sys_id == MT_SYS3)
        {
                intr_status = rtd_inl(dc_regs[dc_id][entry].int_status_sys3_addr);
                addcmd_hi = rtd_inl(dc_regs[dc_id][entry].hi0_sys3_addr);
                addcmd_lo = rtd_inl(dc_regs[dc_id][entry].lo_sys3_addr);
                addcmd_sa = rtd_inl(dc_regs[dc_id][entry].sa_sys3_addr);
        }

        dcmt_mode = (intr_status >> dc_regs[dc_id][entry].int_offset) & 0x7;
        for(i = 0; i < 3; ++i)
        {
                if(dcmt_mode & (1 << i))
                {
                        dcmt_mode = i + 1;
                }
        }

        //.step get basic info and copy to global vari
        trap_addr = addcmd_sa;
        dc_to_dbus_addr(trap_addr, &phy_addr, dc_id);
        module_id = (addcmd_hi >> 14) & 0xFF;

        trap_info.isTraped = 1;
        trap_info.module_id = module_id;
        trap_info.trash_addr = phy_addr;
        trap_info.rw_type = (addcmd_lo & 0x2) ? 1 : 0 ;

        //.step return directly if silence mode
        if(kernel_trap_warning ==  DCMT_INTR_MODE_SILIENCE)
        {
                return 0;
        }

        //.step dump simple log
        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, FRED_START "\n\n\n\n\n\n"
                  "[Memory trash][KEY] DC%d-SYS%d @ mem%d ,module:%s trash phy_addr:0x%08x,access_type:%s,access_len:%d"
                  "\n\n\n\n\n\n" FCOLOR_END,
                  dc_id + 1,
                  sys_id + 1,
                  entry,
                  __module_str(module_id),
                  phy_addr,
                  (addcmd_lo & 0x2) ? "write" : "read",
                  get_addcmd_seqlen(addcmd_hi, addcmd_lo));

        snprintf(panic_dump_log,sizeof(panic_dump_log),"\e[1;31m[DCMT] DC%d-SYS%d@mem%d,%s %s phy_addr:0x%08x,len:%d\e[0m",
                        dc_id + 1,sys_id + 1,entry,__module_str(module_id),(addcmd_lo & 0x2) ? "write" : "read",phy_addr,
                        get_addcmd_seqlen(addcmd_hi, addcmd_lo));
        //.step dump detail log
        if(kernel_trap_warning != DCMT_INTR_MODE_SIMPLE)
        {
                console_flush_on_panic();
                DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "[Memory trash] System got interrupt from DC trash...\n");
                DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "[Memory trash]dump_stacks loop 1/2(may diff with dump_stacks 2/2)\n");
                dump_stacks();
                DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "[Memory trash]dump_stacks loop 2/2(may diff with dump_stacks 1/2)\n");
                dump_stacks();
                for(log_cnt = 0; log_cnt < 3; ++log_cnt) //dump 3 times to avoid a/v log flush
                {
                        console_flush_on_panic();
                        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "[Memory trash]dump log loop %d/%d\n", log_cnt + 1, 3);
                        dump_dcmt_common_regs();
                        dump_dcmt_regs(&dc_regs[dc_id][entry]);
                        _get_dcmt_entry_desc_str(dc_id, entry, msg, sizeof(msg), 0);
                        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "%s\n", msg);

                        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, FRED_START "\n\n\n\n\n\n"
                                  "[Memory trash][KEY] DC%d-SYS%d @ mem%d ,module:%s trash phy_addr:0x%08x,access_type:%s,access_len:%d"
                                  "\n\n\n\n\n\n" FCOLOR_END,
                                  dc_id + 1,
                                  sys_id + 1,
                                  entry,
                                  __module_str(module_id),
                                  phy_addr,
                                  (addcmd_lo & 0x2) ? "write" : "read",
                                  get_addcmd_seqlen(addcmd_hi, addcmd_lo));

                        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "[Memory trash] DC%d-SYS%d trap @ mem%d, module=%s(%d,%d), mode:%d,dc addr:0x%08x(phy 0x%08x), addcmd=%04x-%08x\n",
                                  dc_id + 1,
                                  sys_id + 1,
                                  entry,
                                  __module_str(module_id),
                                  BRIDGE_ID(module_id),
                                  SUB_MODULE_ID(module_id),
                                  dcmt_mode,
                                  trap_addr,
                                  phy_addr,
                                  addcmd_hi & 0x3FFF,
                                  addcmd_lo);
                        __dump_addcmd(addcmd_hi, addcmd_lo);
                        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, "\n\n\n\n\n");
                }

                console_flush_on_panic();
                atomic_notifier_call_chain(&dcmt_notifier_list, 0, NULL);
                if(kernel_trap_warning != DCMT_INTR_MODE_SIMPLE)
                {
                        DCMT_LOG(DCMT_LOG_ISR, KERN_ERR, FRED_START "\n\n\n\n\n\n"
                                  "[Memory trash][KEY] DC%d-SYS%d @ mem%d ,module:%s trash phy_addr:0x%08x,access_type:%s,access_len:%d"
                                  "\n\n\n\n\n\n" FCOLOR_END,
                                  dc_id + 1,
                                  sys_id + 1,
                                  entry,
                                  __module_str(module_id),
                                  phy_addr,
                                  (addcmd_lo & 0x2) ? "write" : "read",
                                  get_addcmd_seqlen(addcmd_hi, addcmd_lo));
                }
                console_flush_on_panic();
        }

        return 0;
}

static int dump_dcmt_last_set(void)
{
        DCID id;
        int ret = 0;
        //int len = 0;
        char buffer[512];
        int i;

        for(id = DCID_1; id < DC_NUM; ++id)
        {
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\nDCU%d setting : \n", id+1);
                for (i = 0; i < DC_MT_ENTRY_COUNT; i++){
                        memset(buffer, 0 , sizeof(buffer));
                        ret = _get_dcmt_entry_desc_str(id, i, buffer, sizeof(buffer), 1);

                        if (ret < 0)
                                return -EINVAL;

                        if(__find_char_pos(buffer,'\n') >= 0) //process default rw prot
                        {
                                __replace_chr(buffer, '\n', '\0');
                        }

                        if(i==last_set_entry){
                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\e[1;33m%s\e[0m\n", buffer);
                        }else{
                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "%s\n", buffer);
                        }
                }
        }
        return 0;
}

int dump_dcmt_last_set_only(void)
{
        DCID id;
        int ret = 0;
        //int len = 0;
        char buffer[512];
        int i;

        for(id = DCID_1; id < DC_NUM; ++id)
        {
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "DCU%d setting : \n", id+1);
                for (i = 0; i < DC_MT_ENTRY_COUNT; i++){
                        memset(buffer, 0 , sizeof(buffer));
                        ret = _get_dcmt_entry_desc_str(id, i, buffer, sizeof(buffer), 1);

                        if (ret < 0)
                                return -EINVAL;

                        if(__find_char_pos(buffer,'\n') >= 0) //process default rw prot
                        {
                                __replace_chr(buffer, '\n', '\0');
                        }

                        if(i==last_set_entry){
                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\e[1;33m%s\e[0m\n", buffer);
                        }
                }
        }
        return 0;
}

//dcmt_show_help
void dump_dcmt_help_info(void)
{
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "====================DCMT HELP INFO====================\n");
        //.set mem
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]Set DCMT\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t simple cmd : \n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t set <start>,<end>\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t echo \"set  0x108000,0x700000\" > /sys/mt/cntl\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t full cmd : \n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t set <start>,<end> [ip: ... ] [mode: ... ] [type: ... ] [mem: ... ]\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t echo \"set  0x108000,0x700000 ip:SB2_ACPU,SB2_ACPU2(rw),SB2_VCPU,SB2_VCPU2(r) mode:1 type:sb mem:0\" > /sys/mt/cntl \n");
        //.unset mem
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]unset DCMT\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t cmd:\"unset mem<region_number>\"\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t Example: unset monitor set 2\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t echo \"unset mem2\">/sys/mt/cntl\n");
        //.cat cntl
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]Get DCMT setting\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t cat /sys/mt/cntl\n");
        //.cat modules
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]Get DCMT Module names\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t cat /sys/mt/modules\n");
        //.trap warning
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]enable/disable kernel trap warning when mt interrupt occurs\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t   Command: \"set warn=<0/1/2/3>\"\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t     0 : silence, don't display any message\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t     1 : simple, only dump key message (won't stop kernel..)\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t     2 : print, dump module, command & trap statistic informtaion only (won't stop kernel..)\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t     3 : panic, dump module and command information and stop the kernel immediately\n");
        //.avk routing toggle
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]toggle avk interrupt routing\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t   echo routen > /sys/mt/cntl\n");
        //.mdtest
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "[*]use md to test dcmt\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t   Command: \"mdtest <dst> <src> <len>\" > /sys/mt/cntl\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t   Example: copy 1M data from 0x300000 to 0x200000\n");
        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\t     echo \"mdtest 200000 300000 100000\">/sys/mt/cntl\n");
}

//force get entry
static int force_get_dcmt_entry(int num, int entry_num, int * pMark)
{
        int i,end,cnt;
        int blank_cnt = 0;
        int next_force_entry = 0;
        if(entry_num > 4)
        {
                end = DC_MTEX_ENTRY_START;
                cnt = DC_MT_ENTRY_COUNT - DC_MTEX_ENTRY_START;
        }
        else
        {
                end = 0;
                cnt = DC_MT_ENTRY_COUNT;
        }

        //take dcmt entry from ip_entry[start] to ip_entry[ends]
        next_force_entry = (last_set_entry-1)%DC_MT_ENTRY_COUNT;
        if(next_force_entry < end)
        {
                next_force_entry = DC_MT_ENTRY_COUNT-1;
        }

        i = next_force_entry;
        while(cnt > 0)//loop cnt times
        {
                if(i < end)//get invalid entry num
                {
                        i = DC_MT_ENTRY_COUNT-1;
                }

                if(pMark[i] == 0)//check entry
                {
                        pMark[i] = 1;
                        blank_cnt++;
                }

                if(blank_cnt >= num)
                {
                        break;
                }
                --cnt;
                --i;
        }

        return blank_cnt;
}

//find blank entry
static int find_blank_dcmt_entry(int num, int entry_num, int * pMark)
{
        int i,start;
        int blank_cnt = 0;
        if((num > DC_MT_ENTRY_COUNT)||(entry_num > 8))
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] error param num:%d(should < %d) entry_num:%d(should < %d)!\n",
                        __FUNCTION__,num,DC_MT_ENTRY_COUNT,entry_num,8);
                return -1;
        }

        if(entry_num > 4)
        {
                start = DC_MTEX_ENTRY_START;
        }
        else
        {
                start = 0;
        }

        for(i = DC_MT_ENTRY_COUNT-1;i >= start;--i)
        {
                if(is_dcmt_entry_work(i))
                {
                        pMark[i] = 0;//clear blank mark
                }
                else
                {
                        blank_cnt++;
                        pMark[i] = 1;
                }
        }

        return blank_cnt;

}


//init regs
void init_dc1_mt_regs(unsigned int entry, dcmt_addr_desc * pDesc)
{
        pDesc->int_offset = entry * 3 + 1;
        pDesc->int_mask = 0x7 << (pDesc->int_offset); //mode3|mode2|mode1

        pDesc->misc_addr = DC_SYS_DC_MT_MISC_reg;
        pDesc->type_addr = DC_SYS_DC_MT_TYPE_0_reg + entry * 4;
        pDesc->saddr_addr = DC_SYS_DC_MT_SADDR_0_reg + entry * 4;
        pDesc->eaddr_addr = DC_SYS_DC_MT_EADDR_0_reg + entry * 4;
        pDesc->mode_addr = DC_SYS_DC_MT_MODE_0_reg + entry * 4;
        pDesc->table0_addr = DC_SYS_DC_MT_TABLE_0_reg + entry * 4;
        pDesc->table1_addr = 0;
        pDesc->hi0_addr = DC_SYS_DC_MT_ADDCMD_HI_0_reg + entry * 4;
        pDesc->hi1_addr = 0;
        pDesc->int_en_addr = DC_SYS_DC_int_enable_reg;
        pDesc->int_en_sys2_addr = DC_SYS_DC_int_enable_SYS2_reg;
        pDesc->int_en_sys3_addr = DC_SYS_DC_int_enable_SYS3_reg;
        pDesc->sys2_mux_addr = DC_SYS_dc_sys2_mux_reg;
        pDesc->sys3_mux_addr = DC_SYS_dc_sys3_mux_reg;
        pDesc->intr_routing_addr = INT_CTRL_SCPU_reg;

        pDesc->int_status_addr = DC_SYS_DC_int_status_reg;
        pDesc->int_status_sys2_addr = DC_SYS_DC_int_status_SYS2_reg;
        pDesc->int_status_sys3_addr = DC_SYS_DC_int_status_SYS3_reg;
        pDesc->lo_addr = DC_SYS_DC_MT_ADDCMD_LO_0_reg + entry * 4;
        pDesc->sa_addr = DC_SYS_DC_MT_ADDCMD_SA_0_reg + entry * 4;
        pDesc->hi0_sys2_addr = DC_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg + entry * 4;
        pDesc->lo_sys2_addr = DC_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg + entry * 4;
        pDesc->sa_sys2_addr = DC_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg + entry * 4;
        pDesc->hi0_sys3_addr = DC_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg + entry * 4;
        pDesc->lo_sys3_addr = DC_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg + entry * 4;
        pDesc->sa_sys3_addr = DC_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg + entry * 4;
}

void init_dc1_mtex_regs(unsigned int entry, dcmt_addr_desc * pDesc)
{
        pDesc->int_offset = entry * 3 + 1;
        pDesc->int_mask = 0x7 << (pDesc->int_offset); //mode3|mode2|mode1

        pDesc->misc_addr = DC_SYS_DC_MT_MISC_reg;
        pDesc->type_addr = DC_SYS_DC_MTEX_TYPE_0_reg + entry * 4;
        pDesc->saddr_addr = DC_SYS_DC_MTEX_SADDR_0_reg + entry * 4;
        pDesc->eaddr_addr = DC_SYS_DC_MTEX_EADDR_0_reg + entry * 4;
        pDesc->mode_addr = DC_SYS_DC_MTEX_MODE_0_reg + entry * 4;
        pDesc->table0_addr = DC_SYS_DC_MTEX_TABLE0_0_reg + entry * 4;
        pDesc->table1_addr = DC_SYS_DC_MTEX_TABLE1_0_reg + entry * 4;
        pDesc->hi0_addr = DC_SYS_DC_MTEX_ADDCMD_HI0_0_reg + entry * 4;
        pDesc->hi1_addr = DC_SYS_DC_MTEX_ADDCMD_HI1_0_reg + entry * 4;
        pDesc->int_en_addr = DC_SYS_DC_MTEX_int_enable_reg;
        pDesc->int_en_sys2_addr = DC_SYS_DC_MTEX_int_enable_SYS2_reg;
        pDesc->int_en_sys3_addr = DC_SYS_DC_MTEX_int_enable_SYS3_reg;
        pDesc->sys2_mux_addr = DC_SYS_dc_sys2_mux_reg;
        pDesc->sys3_mux_addr = DC_SYS_dc_sys3_mux_reg;
        pDesc->intr_routing_addr = INT_CTRL_SCPU_reg;

        pDesc->int_status_addr = DC_SYS_DC_MTEX_int_status_reg;
        pDesc->int_status_sys2_addr = DC_SYS_DC_MTEX_int_status_SYS2_reg;
        pDesc->int_status_sys3_addr = DC_SYS_DC_MTEX_int_status_SYS3_reg;
        pDesc->lo_addr = DC_SYS_DC_MTEX_ADDCMD_LO_0_reg + entry * 4;
        pDesc->sa_addr = DC_SYS_DC_MTEX_ADDCMD_SA_0_reg + entry * 4;
        pDesc->hi0_sys2_addr = DC_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg + entry * 4;
        pDesc->lo_sys2_addr = DC_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg + entry * 4;
        pDesc->sa_sys2_addr = DC_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg + entry * 4;
        pDesc->hi0_sys3_addr = DC_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg + entry * 4;
        pDesc->lo_sys3_addr = DC_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg + entry * 4;
        pDesc->sa_sys3_addr = DC_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg + entry * 4;
}

#ifdef DCMT_DCU2
void init_dc2_mt_regs(unsigned int entry, dcmt_addr_desc * pDesc)
{
        pDesc->int_offset = entry * 3 + 1;
        pDesc->int_mask = 0x7 << (pDesc->int_offset); //mode3|mode2|mode1

        pDesc->misc_addr = DC2_SYS_DC_MT_MISC_reg;
        pDesc->type_addr = DC2_SYS_DC_MT_TYPE_0_reg + entry * 4;
        pDesc->saddr_addr = DC2_SYS_DC_MT_SADDR_0_reg + entry * 4;
        pDesc->eaddr_addr = DC2_SYS_DC_MT_EADDR_0_reg + entry * 4;
        pDesc->mode_addr = DC2_SYS_DC_MT_MODE_0_reg + entry * 4;
        pDesc->table0_addr = DC2_SYS_DC_MT_TABLE_0_reg + entry * 4;
        pDesc->table1_addr = 0;
        pDesc->hi0_addr = DC2_SYS_DC_MT_ADDCMD_HI_0_reg + entry * 4;
        pDesc->hi1_addr = 0;
        pDesc->int_en_addr = DC2_SYS_DC_int_enable_reg;
        pDesc->int_en_sys2_addr = DC2_SYS_DC_int_enable_SYS2_reg;
        pDesc->int_en_sys3_addr = DC2_SYS_DC_int_enable_SYS3_reg;
        pDesc->sys2_mux_addr = DC2_SYS_dc_sys2_mux_reg;
        pDesc->sys3_mux_addr = DC2_SYS_dc_sys3_mux_reg;
        pDesc->intr_routing_addr = INT_CTRL_SCPU_reg;

        pDesc->int_status_addr = DC2_SYS_DC_int_status_reg;
        pDesc->int_status_sys2_addr = DC2_SYS_DC_int_status_SYS2_reg;
        pDesc->int_status_sys3_addr = DC2_SYS_DC_int_status_SYS3_reg;
        pDesc->lo_addr = DC2_SYS_DC_MT_ADDCMD_LO_0_reg + entry * 4;
        pDesc->sa_addr = DC2_SYS_DC_MT_ADDCMD_SA_0_reg + entry * 4;
        pDesc->hi0_sys2_addr = DC2_SYS_DC_MT_ADDCMD_HI_SYS2_0_reg + entry * 4;
        pDesc->lo_sys2_addr = DC2_SYS_DC_MT_ADDCMD_LO_SYS2_0_reg + entry * 4;
        pDesc->sa_sys2_addr = DC2_SYS_DC_MT_ADDCMD_SA_SYS2_0_reg + entry * 4;
        pDesc->hi0_sys3_addr = DC2_SYS_DC_MT_ADDCMD_HI_SYS3_0_reg + entry * 4;
        pDesc->lo_sys3_addr = DC2_SYS_DC_MT_ADDCMD_LO_SYS3_0_reg + entry * 4;
        pDesc->sa_sys3_addr = DC2_SYS_DC_MT_ADDCMD_SA_SYS3_0_reg + entry * 4;
}

void init_dc2_mtex_regs(unsigned int entry, dcmt_addr_desc * pDesc)
{
        pDesc->int_offset = entry * 3 + 1;
        pDesc->int_mask = 0x7 << (pDesc->int_offset); //mode3|mode2|mode1

        pDesc->misc_addr = DC2_SYS_DC_MT_MISC_reg;
        pDesc->type_addr = DC2_SYS_DC_MTEX_TYPE_0_reg + entry * 4;
        pDesc->saddr_addr = DC2_SYS_DC_MTEX_SADDR_0_reg + entry * 4;
        pDesc->eaddr_addr = DC2_SYS_DC_MTEX_EADDR_0_reg + entry * 4;
        pDesc->mode_addr = DC2_SYS_DC_MTEX_MODE_0_reg + entry * 4;
        pDesc->table0_addr = DC2_SYS_DC_MTEX_TABLE0_0_reg + entry * 4;
        pDesc->table1_addr = DC2_SYS_DC_MTEX_TABLE1_0_reg + entry * 4;
        pDesc->hi0_addr = DC2_SYS_DC_MTEX_ADDCMD_HI0_0_reg + entry * 4;
        pDesc->hi1_addr = DC2_SYS_DC_MTEX_ADDCMD_HI1_0_reg + entry * 4;
        pDesc->int_en_addr = DC2_SYS_DC_MTEX_int_enable_reg;
        pDesc->int_en_sys2_addr = DC2_SYS_DC_MTEX_int_enable_SYS2_reg;
        pDesc->int_en_sys3_addr = DC2_SYS_DC_MTEX_int_enable_SYS3_reg;
        pDesc->sys2_mux_addr = DC2_SYS_dc_sys2_mux_reg;
        pDesc->sys3_mux_addr = DC2_SYS_dc_sys3_mux_reg;
        pDesc->intr_routing_addr = INT_CTRL_SCPU_reg;

        pDesc->int_status_addr = DC2_SYS_DC_MTEX_int_status_reg;
        pDesc->int_status_sys2_addr = DC2_SYS_DC_MTEX_int_status_SYS2_reg;
        pDesc->int_status_sys3_addr = DC2_SYS_DC_MTEX_int_status_SYS3_reg;
        pDesc->lo_addr = DC2_SYS_DC_MTEX_ADDCMD_LO_0_reg + entry * 4;
        pDesc->sa_addr = DC2_SYS_DC_MTEX_ADDCMD_SA_0_reg + entry * 4;
        pDesc->hi0_sys2_addr = DC2_SYS_DC_MTEX_ADDCMD_HI0_SYS2_0_reg + entry * 4;
        pDesc->lo_sys2_addr = DC2_SYS_DC_MTEX_ADDCMD_LO_SYS2_0_reg + entry * 4;
        pDesc->sa_sys2_addr = DC2_SYS_DC_MTEX_ADDCMD_SA_SYS2_0_reg + entry * 4;
        pDesc->hi0_sys3_addr = DC2_SYS_DC_MTEX_ADDCMD_HI0_SYS3_0_reg + entry * 4;
        pDesc->lo_sys3_addr = DC2_SYS_DC_MTEX_ADDCMD_LO_SYS3_0_reg + entry * 4;
        pDesc->sa_sys3_addr = DC2_SYS_DC_MTEX_ADDCMD_SA_SYS3_0_reg + entry * 4;
}
#endif
void init_dcregs_vari(void)
{
        unsigned int entry;
        for(entry = 0; entry < DC_MTEX_ENTRY_START; ++entry)
        {
                init_dc1_mt_regs(entry, &dc_regs[DCID_1][entry]);
        }

        for(entry = DC_MTEX_ENTRY_START; entry < DC_MT_ENTRY_COUNT; ++entry)
        {
                init_dc1_mtex_regs(entry - DC_MTEX_ENTRY_START, &dc_regs[DCID_1][entry]);
        }
}
#ifdef DCMT_DCU2
int checkIBRegion(unsigned int saddr, unsigned int eaddr)
{
        unsigned int sregion = 0;
        unsigned int eregion = 0;
        int i;
        //get start region
        for(i = 0; i < BOUND_NUM; ++i)
        {
                if(saddr < ib_seq_bound[SEQ_PHY][i])
                {
                        break;
                }
        }
        sregion = i - 1;
        //get end region
        for(i = 0; i < BOUND_NUM; ++i)
        {
                if(eaddr < ib_seq_bound[SEQ_PHY][i])
                {
                        break;
                }
        }
        eregion = i - 1;
        //check if over region
        //DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "start region 0x%08X, end region 0x%08X\n", sregion, eregion);
        if(sregion == eregion)
        {
                return 0;
        }
        else
        {
                return 1;
        }
}

int getIBMode(unsigned int addr)
{
        unsigned int region_id = 0;
        int i;
        //step. get region id
        for(i = 1; i < BOUND_NUM; ++i)
        {
                if(addr < ib_seq_bound[SEQ_PHY][i])
                {
                        break;
                }
        }
        region_id = i - 1;

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "addr : 0x%08X region_0, mode = 0x%03X \n", addr, region_mode[region_id]);

        return region_mode[region_id];
}
#endif

//updateIBMode
void updateIBMode(void)
{
#ifdef DCMT_DCU2
        ib_seq_bound[SEQ_PHY][BOUND_0] = 0;
        ib_seq_bound[SEQ_PHY][BOUND_1] = rtd_inl(0xb803f000);
        ib_seq_bound[SEQ_PHY][BOUND_2] = rtd_inl(0xb803f004);
        ib_seq_bound[SEQ_PHY][BOUND_3] = rtd_inl(0xb803f008);

        ib_seq_bound[SEQ_DC1][BOUND_0] = 0;
        ib_seq_bound[SEQ_DC1][BOUND_1] = rtd_inl(0xb803f00C);
        ib_seq_bound[SEQ_DC1][BOUND_2] = rtd_inl(0xb803f010);
        ib_seq_bound[SEQ_DC1][BOUND_3] = rtd_inl(0xb803f014);

        ib_seq_bound[SEQ_DC2][BOUND_0] = 0;
        ib_seq_bound[SEQ_DC2][BOUND_1] = rtd_inl(0xb803f018);
        ib_seq_bound[SEQ_DC2][BOUND_2] = rtd_inl(0xb803f01C);
        ib_seq_bound[SEQ_DC2][BOUND_3] = rtd_inl(0xb803f020);

        IB_SEQ_REGION_SET = rtd_inl(0xb803f028);

        region_mode[0] = (IB_SEQ_REGION_SET >> 28) & 0x3;
        region_slice[0] = (1 << ((IB_SEQ_REGION_SET >> 24) & 0x7)) * DCMT_IB_SLICE_BASIC;
        region_mode[1] = (IB_SEQ_REGION_SET >> 20) & 0x3;
        region_slice[1] = (1 << ((IB_SEQ_REGION_SET >> 16) & 0x7)) * DCMT_IB_SLICE_BASIC;
        region_mode[2] = (IB_SEQ_REGION_SET >> 12) & 0x3;
        region_slice[2] = (1 << ((IB_SEQ_REGION_SET >> 8) & 0x7)) * DCMT_IB_SLICE_BASIC;
        region_mode[3] = (IB_SEQ_REGION_SET >> 4) & 0x3;
        region_slice[3] = (1 << ((IB_SEQ_REGION_SET >> 0) & 0x7)) * DCMT_IB_SLICE_BASIC;

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "IB_SEQ_REGION_SET = 0x%08X \n", IB_SEQ_REGION_SET);

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_0_mode = 0x%03X \n", region_mode[0]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_1_mode = 0x%03X \n", region_mode[1]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_2_mode = 0x%03X \n", region_mode[2]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_3_mode = 0x%03X \n", region_mode[3]);

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_0_addr = 0x%08x \n", ib_seq_bound[SEQ_PHY][BOUND_0]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_1_addr = 0x%08X \n", ib_seq_bound[SEQ_PHY][BOUND_1]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_2_addr = 0x%08X \n", ib_seq_bound[SEQ_PHY][BOUND_2]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "region_3_addr = 0x%08X \n", ib_seq_bound[SEQ_PHY][BOUND_3]);

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc1_region_0_addr = 0x%08x \n", ib_seq_bound[SEQ_DC1][BOUND_0]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc1_region_1_addr = 0x%08X \n", ib_seq_bound[SEQ_DC1][BOUND_1]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc1_region_2_addr = 0x%08X \n", ib_seq_bound[SEQ_DC1][BOUND_2]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc1_region_3_addr = 0x%08X \n", ib_seq_bound[SEQ_DC1][BOUND_3]);

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc2_region_0_addr = 0x%08x \n", ib_seq_bound[SEQ_DC2][BOUND_0]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc2_region_1_addr = 0x%08X \n", ib_seq_bound[SEQ_DC2][BOUND_1]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc2_region_2_addr = 0x%08X \n", ib_seq_bound[SEQ_DC2][BOUND_2]);
        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc2_region_3_addr = 0x%08X \n", ib_seq_bound[SEQ_DC2][BOUND_3]);
#endif  // #ifdef DCMT_DCU2
}


//verify dcmt setting descriptor
static unsigned int verify_dcmt_desc(DC_MT_DESC * pDesc)
{
        int i;
        //verify type
        if(pDesc->type == MEMORY_TYPE_NONE)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[err] DCMT descriptor err, memtype is invalid!\n");
                return 1;
        }
        //verify start_end
        if(pDesc->start > pDesc->end)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[err] DCMT descriptor err, start address > end address!\n");
                return 2;
        }
        //verify mode
        if((pDesc->mode & 0x3) == 0)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[err] DCMT descriptor err, mode is invalid!\n");
                return 3;
        }
        //verify module_rw
        for(i = 0;i < pDesc->module_max;++i)
        {
                if(pDesc->ip_entry[i].prot >= PROT_MODE_NUM)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[err] DCMT descriptor err, rw type is invalid!\n");
                        return 4;
                }
        }
        //verify module num
        for(i = pDesc->module_max;i < 8;++i)
        {
                if(pDesc->ip_entry[i].prot != 0)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[err] DCMT descriptor err, module is more than expected!(max:%d,now:%d)\n",i,pDesc->module_max);
                        return 5;
                }
        }

        return 0;
}

//_dcmt_clear_monitor
static void _dcmt_clear_monitor(unsigned int entry, int update)
{
        unsigned int id;
        //disable scpu intr
        //disable_dcmt_scpu_intr(entry);
        if(entry >= DC_MT_ENTRY_COUNT)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "%s error param entry:%d !\n",__FUNCTION__,entry);
                return;
        }

        for(id = DCID_1; id < DC_NUM; ++id)
        {
                rtd_outl(dc_regs[id][entry].mode_addr, DC_MT_MODE_WE5);
                rtd_outl(dc_regs[id][entry].type_addr, 0);
                //rtd_outl(dc_regs[id][entry].saddr_addr, 0);//mark this line to avoid clear atuo range sync info
                //rtd_outl(dc_regs[id][entry].eaddr_addr, 0);//mark this line to avoid clear atuo range sync info
                rtd_outl(dc_regs[id][entry].table0_addr, 0);
                if(dc_regs[id][entry].table1_addr)
                {
                        rtd_outl(dc_regs[id][entry].table1_addr, 0);
                }
                rtd_outl(dc_regs[id][entry].hi0_addr, 0);
                if(dc_regs[id][entry].hi1_addr)
                {
                        rtd_outl(dc_regs[id][entry].hi1_addr, 0);
                }
                rtd_outl(dc_regs[id][entry].lo_addr, 0);
                rtd_outl(dc_regs[id][entry].sa_addr, 0);

                if(update)
                {
                        memset(&g_desc_store_dc[entry], 0, sizeof(DC_MT_DESC));
                }
        }
}

//_dcmt_set_monitor
static int _dcmt_set_monitor(unsigned int entry, DC_MT_DESC * pDesc, int update)
{
        unsigned int err_case = 0;
        unsigned int dc_addr_start = 0;
        unsigned int dc_addr_end = 0;
        DCID id;

        //.dump desc
        //dump_dcmt_desc("dump setting desc:",pDesc);
        if(entry >= DC_MT_ENTRY_COUNT)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] error param entry:%d !\n",__FUNCTION__,entry);
                return -1;
        }

        //.step set pDesc->module_max for mt&mtex
        if(entry < DC_MTEX_ENTRY_START)
        {
                pDesc->module_max = 4;
        }
        else
        {
                pDesc->module_max = 8;
        }
        //.step emmc work around process
        //emmc_workaround_process(pDesc);
        //.step verify pDesc

        err_case = verify_dcmt_desc(pDesc);
        //.step check start & end addr
        if(err_case)
        {
                err_case = 1;
                goto err;
        }
		//.step check ib region cross
        /*
        if(checkIBRegion(pDesc->start, pDesc->end))
        {
                err_case = 2;
                goto err;
        }
        */

        _dcmt_clear_monitor(entry,0);//clear old setting at first
        //DC_MT_WARNING("set dcmt mem%d : 0x%08x - 0x%08x\n!",entry,pDesc->start,pDesc->end);
        last_set_entry = entry;

        for(id = DCID_1; id < DC_NUM; ++id)
        {
                //.step convert start & end addr
                if(dbus_to_dc_addr(pDesc->start,&dc_addr_start,id,DCMT_RANGE_START) != 0)
                {
                        //DC_MT_ERR("set DCU%d start addr failed!\n", id + 1);
                        continue;
                }

                if(dbus_to_dc_addr(pDesc->end,&dc_addr_end,id,DCMT_RANGE_END) != 0)
                {
                        //DC_MT_ERR("set DCU%d start addr failed!\n", id + 1);
                        continue;
                }

                if(dc_addr_end >= 0x80000000)
                {
                        dc_addr_end = 0x80000000 - DCMT_ALIGN_SIZE;
                        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "force DC%d end addr to 0x%08x!\n", id, dc_addr_end);
                }

                if((dc_addr_start > dc_addr_end)||(dc_addr_start >= 0x80000000)||(dc_addr_end >= 0x80000000)) //when region offset is 0,dc2 end < start
                {
                        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "DC%d start/end reg value error, start:0x%08x, end:0x%08x", id, dc_addr_start, dc_addr_end);
                        continue;
                }

                //.step disable dcmt and clear status
                rtd_outl(dc_regs[id][entry].mode_addr, DC_MT_MODE_WE5);
                clear_dcmt_trash_status(id, entry);
                //.step set dcmt regs
                rtd_outl(dc_regs[id][entry].type_addr, ((pDesc->type & 0x3) << 30)); //sb type
                rtd_outl(dc_regs[id][entry].saddr_addr, dc_addr_start); //start
                rtd_outl(dc_regs[id][entry].eaddr_addr, dc_addr_end); //end
                rtd_outl(dc_regs[id][entry].table0_addr,
                         DC_MT_TABLE_MODULE0(pDesc->ip_entry[0].module) |
                         DC_MT_TABLE_MODULE1(pDesc->ip_entry[1].module) |
                         DC_MT_TABLE_MODULE2(pDesc->ip_entry[2].module) |
                         DC_MT_TABLE_MODULE3(pDesc->ip_entry[3].module));//module_id 0-3
                rtd_outl(dc_regs[id][entry].hi0_addr,
                         DC_MT_ACCESS_TYPE0(pDesc->ip_entry[0].prot) |
                         DC_MT_ACCESS_TYPE1(pDesc->ip_entry[1].prot) |
                         DC_MT_ACCESS_TYPE2(pDesc->ip_entry[2].prot) |
                         DC_MT_ACCESS_TYPE3(pDesc->ip_entry[3].prot));//rw type 0-3
                if(entry >= DC_MTEX_ENTRY_START)
                {
                        rtd_outl(dc_regs[id][entry].table1_addr,
                                 DC_MT_TABLE_MODULE0(pDesc->ip_entry[4].module) |
                                 DC_MT_TABLE_MODULE1(pDesc->ip_entry[5].module) |
                                 DC_MT_TABLE_MODULE2(pDesc->ip_entry[6].module) |
                                 DC_MT_TABLE_MODULE3(pDesc->ip_entry[7].module));//module_id 4-7
                        rtd_outl(dc_regs[id][entry].hi1_addr,
                                 DC_MT_ACCESS_TYPE0(pDesc->ip_entry[4].prot) |
                                 DC_MT_ACCESS_TYPE1(pDesc->ip_entry[5].prot) |
                                 DC_MT_ACCESS_TYPE2(pDesc->ip_entry[6].prot) |
                                 DC_MT_ACCESS_TYPE3(pDesc->ip_entry[7].prot));//rw type 4-7
                }
                rtd_outl(dc_regs[id][entry].mode_addr, DC_MT_MODE_WE5 | pDesc->mode); //enable dcmt monitor
        }

        //.step update str desc
        if(update)
        {
                memcpy(&g_desc_store_dc[entry], pDesc, sizeof(DC_MT_DESC));
        }

        return 0;

err:
        //DC_MT_ERR("[%s] entry:%d failed!\n",__FUNCTION__,entry);
        //dump_dcmt_desc("desc", pDesc);

        return -EINVAL;
}

//init_notifier_info
void clear_notifier_info(void)
{
        memset(&trap_info, 0, sizeof(trap_info));
}

//init
static void init_dcmt_store_status(void)
{
        int entry;
        for(entry = 0; entry < DC_MT_ENTRY_COUNT; entry++)
        {
                memset(&g_desc_store_dc[entry],0,sizeof(DC_MT_DESC));
        }
}

static int __init _dc_mt_get_avk_range(unsigned int *addr)
{
        addr[DCMT_RANGE_SYNC_A_START] = rtd_inl(dc_regs[0][0].saddr_addr);
        addr[DCMT_RANGE_SYNC_A_END] = rtd_inl(dc_regs[0][0].eaddr_addr);
        DC_MT_WARNING("acpu range: %08x - %08x\n",addr[DCMT_RANGE_SYNC_A_START],addr[DCMT_RANGE_SYNC_A_END]);

        addr[DCMT_RANGE_SYNC_V_START] = rtd_inl(dc_regs[0][1].saddr_addr);
        addr[DCMT_RANGE_SYNC_V_END] = rtd_inl(dc_regs[0][1].eaddr_addr);
        DC_MT_WARNING("vcpu range: %08x - %08x\n",addr[DCMT_RANGE_SYNC_V_START],addr[DCMT_RANGE_SYNC_V_END]);

        addr[DCMT_RANGE_SYNC_K_START] = rtd_inl(dc_regs[0][5].saddr_addr);
        addr[DCMT_RANGE_SYNC_K_END] = rtd_inl(dc_regs[0][5].eaddr_addr);
        DC_MT_WARNING("kcpu range: %08x - %08x\n",addr[DCMT_RANGE_SYNC_K_START],addr[DCMT_RANGE_SYNC_K_END]);

        return 0;
}

//dcmt_reset
static void _dc_mt_clear_all_monitor(void)
{
        int i;
        unsigned int tmp = 0;

        init_dcmt_store_status();

        for (i = 0; i < DC_MT_ENTRY_COUNT; i++)
        {
                _dcmt_clear_monitor(i, 0);
        }

        //disable cross range check
        tmp = rtd_inl(DC_SYS_DC_MT_MISC_reg);
        rtd_outl(DC_SYS_DC_MT_MISC_reg, tmp | BIT(0));
#ifdef DCMT_DCU2
        tmp = rtd_inl(DC2_SYS_DC_MT_MISC_reg);
        rtd_outl(DC2_SYS_DC_MT_MISC_reg, tmp | BIT(0));
#endif
}

//emmc_wrap_process
static int is_include_emmc_module(DC_MT_DESC * pDesc)
{
        unsigned int i;
        for(i = 0;i < pDesc->module_max;++i)
        {
                if(is_module_include(MODULE_SB1_EMMC_NKC,pDesc->ip_entry[i].module) ||
                        is_module_include(MODULE_SB1_EMMC_KC,pDesc->ip_entry[i].module))
                {
                        return 1;
                }
        }

        return 0;
}

static __maybe_unused int emmc_workaround_process(DC_MT_DESC * pDesc)
{
        int ret = 0;
        //emmc will read more 64B in merlin2
        if(pDesc->mode == 1)//mode 1
        {
                //if include emmc module,start += 64
                if(is_include_emmc_module(pDesc))
                {
                        pDesc->start += 64;
                        //DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "emmc mode1 workaround, start change to 0x%08x\n",pDesc->start);
                        ret = 1;
                }
        }
        else if(pDesc->mode == 2)//mode2
        {
                //if not include emmc module,start += 64
                if(!is_include_emmc_module(pDesc))
                {
                        pDesc->start += 64;
                        //DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "emmc mode2 workaround, start change to 0x%08x\n",pDesc->start);
                        ret = 1;
                }
        }
        else if(pDesc->mode == 3)//mode3
        {
                //if include emmc module, end += 64
                if(is_include_emmc_module(pDesc))
                {
                        pDesc->end += 64;
                        //DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "emmc mode3 workaround, end change to 0x%08x\n",pDesc->end);
                        ret = 1;
                }
        }

        return ret;
}

static int update_desc_entries(DC_MT_DESC *pDesc, int i, unsigned char module_id, unsigned char module_prot)
{
        if(i >= 8)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "too much modules,DCMT can only monitor 4-8 modules at one time!\n");
                return -1;
        }

        pDesc->ip_entry[i].module = module_id;
        pDesc->ip_entry[i].prot = module_prot;

        return 0;
}

int parse_module_name(char * name,unsigned char *pModuleID,int max_num)
{
        int rst = -1;
        int module_num = 0;
        int i;
        //search module_list
        if(max_num <= 0)
        {
                return -1;
        }

        rst = __module_id(name);

        if(rst >= 0)
        {
                pModuleID[0] = (unsigned char)rst;
                return 1;
        }

        //search key_table
        rst = module_table_search(key_table, sizeof(key_table)/sizeof(MODULE_SEARCH_TABLE), name);
        if(rst < 0)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "unkonwn module - %s\n", name);
                return -1;
        }

        dump_module_key_table_single(rst);

        module_num = key_table[rst].table_len;
        for(i = 0;i < module_num;++i)
        {
                if(i >= max_num)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "too much module in key_table - %s\n", name);
                        return -1;
                }

                pModuleID[i] = key_table[rst].table[i];
        }

        return i;
}
EXPORT_SYMBOL(parse_module_name);

//parse cmd_module to desc
static int parse_dcmt_module_cmd(const char *cmd, DC_MT_DESC *pDesc)
{
        int i = 0,j = 0,k = 0;
        char* argv[9];
        int key_table_id;
        int module_num;
        unsigned char tmp_module_id;
        unsigned char tmp_module_prot;
        int argc = get_arguments((char*)cmd, 9, argv);

        if(argc > 8)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "module cmd param is too much!\n");
                return -1;
        }

        k = 0;
        for(i = 0; i < argc; ++i)
        {
                char* param[2];
                int user_param_num = 1;
                char* dft_param1 = "w";

                if(__find_char_pos(argv[i],'(') >= 0) //process default rw prot
                {
                        __replace_chr(argv[i], '(', ',');
                        __replace_chr(argv[i], ')', '\0');
                        user_param_num = 2;
                }

                if (get_arguments(argv[i], user_param_num, param) < user_param_num)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, parse module failed - %s\n", argv[i]);
                        return -1;
                }

                if(user_param_num == 1) //use default rw prot
                {
                        param[1] = dft_param1;
                }

                //DC_MT_ERR("i:%d param[0]=%s, param[1]=%s\n",i, param[0], param[1]);

                //update entry if less then 8
                tmp_module_prot = __prot_id(param[1]);
                if(tmp_module_prot < 0)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, unkonwn r/w prot - %s\n", param[1]);
                        return -1;
                }

                key_table_id = -1;
                if ( (__module_id(param[0])) < 0)
                {
                        key_table_id = module_table_search(key_table, sizeof(key_table)/sizeof(MODULE_SEARCH_TABLE), param[0]);
                        if(key_table_id < 0)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, unkonwn module - %s\n", param[0]);
                                return -1;
                        }

                        dump_module_key_table_single(key_table_id);

                        module_num = key_table[key_table_id].table_len;
                }
                else
                {
                        module_num = 1;
                        tmp_module_id = __module_id(param[0]);
                }

                //for loop to update module_num
                for(j = 0;j < module_num;++j)
                {
                        if(key_table_id >= 0)
                        {
                                tmp_module_id = key_table[key_table_id].table[j];
                        }

                        if(update_desc_entries(pDesc,k,tmp_module_id,tmp_module_prot) < 0)
                        {
                                return -1;
                        }
                        k++;
                }

        }

        return k;
}

//parse dcmt set cmd branch
/*
echo "set  0x108000,0x700000 ip:ANY(w) mode:1 type:sb" > /sys/mt/cntl
*/
static int parse_dcmt_easy_set_cmd(const char * buffer)
{
        DC_MT_DESC desc;
        const char* cmd = buffer;
        char* argv[14];
        char tmp[16];
        int argc = 0;
        int mem_entry = -1;
        int i;
        unsigned long start,end;
        unsigned int mode;
        int ret = -1;

        memset(&desc, 0, sizeof(desc));
        desc.mode = 2;
        desc.start = 0;
        desc.end = 0;
        desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        desc.ip_entry[0].module = MODULE_ANY;
        desc.ip_entry[0].prot = PROT_MODE_WO;

        if (strncmp(cmd, "set", strlen("set")) == 0)
        {
                cmd += strlen("set");
        }
        else
        {
                return -1;
        }

        argc = get_space_arguments((char*)cmd, 14, argv);

        for(i = 0;i < argc;++i)
        {
                if(strncmp( argv[i], "mode:", strlen("mode:") ) == 0) // check mode
                {
                        if(sscanf(argv[i],"mode:%u",&mode)<1)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] parse mode failed!\n",__FUNCTION__);
                                return -1;
                        }
                        else
                        {
                                desc.mode = (unsigned char)mode;
                        }
                }
                else if(strncmp( argv[i], "mem:", strlen("mem:") ) == 0) // check mem entry
                {
                        if(sscanf(argv[i],"mem:%d",&mem_entry)<1)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] parse mem set failed!\n",__FUNCTION__);
                                return -1;
                        }
                }
                else if(strncmp( argv[i], "type:", strlen("type:") ) == 0) //check type
                {
                        if(sscanf(argv[i],"type:%3s",tmp)<1)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] parse memtype failed!\n",__FUNCTION__);
                                return -1;
                        }
                        else
                        {
                                if(strcmp(tmp,"sb") == 0)
                                {
                                        desc.type = MEMORY_TYPE_SERIAL_BLOCK;
                                }
                                else if(strcmp(tmp,"s") == 0)
                                {
                                        desc.type = MEMORY_TYPE_SERIAL;
                                }
                                else if(strcmp(tmp,"b") == 0)
                                {
                                        desc.type = MEMORY_TYPE_BLOCK;
                                }
                                else
                                {
                                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] parse memtype:%s failed!\n",__FUNCTION__,tmp);
                                        return -1;
                                }
                        }
                }
                else if(strncmp( argv[i], "ip:", strlen("ip:") ) == 0) // check mem entry
                {
                        cmd = argv[i];
                        cmd += strlen("ip:");
                        if(parse_dcmt_module_cmd(cmd,&desc) <= 0)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "[%s] parse module failed!\n",__FUNCTION__);
                                return -1;
                        }
                }
                else if(sscanf(argv[i],"%lx,%lx",&start,&end) == 2)
                {
                        desc.start = start;
                        desc.end = end;
                }
                else
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "Unknown param %s (ignored)!\n",argv[i]);
                }
                //DC_MT_INFO("arg%d : %s\n",i+1,argv[i]);
        }

        if(mem_entry < 0)
        {
                //auto set
                if(dcmt_set_monitor_auto(&desc) >= 0)
                {
                        dump_dcmt_last_set();
                        ret = last_set_entry;
                }
        }
        else
        {
                if(_dcmt_set_monitor(mem_entry,&desc,1) >= 0)
                {
                        dump_dcmt_last_set();
                        ret = last_set_entry;
                }
        }

        return ret;
}

//parse dcmt set cmd
static int parse_mt_set_cmd(const char * buffer)
{
        int entry;
        char* cmd = NULL;
        char* tmp = NULL;

        if(buffer == NULL)
        {
                return -1;
        }

        if(strlen(buffer) < 4)
        {
                return -1;
        }

        cmd = __find_next_str((char*)buffer + 3);
        tmp = cmd;

        while(*tmp != '\0')
        {
                if((*tmp == '\r')||(*tmp=='\n'))
                {
                        *tmp = '\0';
                }
                tmp++;
        }

        if (cmd == NULL)
        {
                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt failed, unknown command - %s\n", cmd);
                return -1;
        }

        if (strncmp(cmd, "kernel_trap_warning=", 20) == 0)
        {
                if (sscanf(cmd, "kernel_trap_warning=%d", &entry) < 1)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set kernel_trap_warning failed, invalid argument - %s\n", (char*)(cmd + 20));
                        return -1;
                }

                if(entry < DCMT_INTR_MODE_INVALID)
                {
                        kernel_trap_warning = entry;
                        if(kernel_trap_warning < DCMT_INTR_MODE_PANIC)
                        {
                                all_intr_routing_enable = 0;
                                dcmt_unset_avk_intr_routing();
                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "Disabled avk intr routing!\n");
                        }
                        else
                        {
                                all_intr_routing_enable = 1;
                                dcmt_set_all_cpu_intr_routing();
                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "Enabled avk intr routing!\n");
                        }
                        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "kernel_trap_warning change to %d (0:silence 1:simple 2:print 3:panic)\n", kernel_trap_warning);
                }
                else
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "kernel_trap_warning should less than value %d!\n",DCMT_INTR_MODE_INVALID);
                }
        }
        else if (strncmp(cmd, "mem", 3) == 0)
        {
                DC_MT_DESC mt_desc;
                int i = 0;
                char* argv[14];
                int argc = get_arguments((char*)cmd, 14, argv);

                memset(&mt_desc, 0, sizeof(mt_desc));

                for (i = 0; i < argc; i++)
                {
                        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "arg[%d]='%s'\n", i, argv[i]);
                }

                if (argc < 6)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, no enough arguments\n");
                        return -1;
                }

                // memory region
                if (sscanf(argv[0], "mem%d:", &entry) < 1)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, parse memory id failed\n");
                        return -1;
                }

                // memory type
                if (strcmp(argv[1], "sb") == 0)
                {
                        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
                }
                else if (strcmp(argv[1], "s") == 0)
                {
                        mt_desc.type = MEMORY_TYPE_SERIAL;
                }
                else if (strcmp(argv[1], "b") == 0)
                {
                        mt_desc.type = MEMORY_TYPE_BLOCK;
                }
                else
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, memory type should be 's' 'b' or 'sb' \n");
                        return -1;
                }

                // saddr
                if (sscanf(argv[2], "%lx", &mt_desc.start) != 1)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, parse start address failed\n");
                        return -1;
                }

                // eaddr
                if (sscanf(argv[3], "%lx", &mt_desc.end) != 1)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, parse end address failed\n");
                        return -1;
                }

                // mt mode
                mt_desc.mode = 0;
                for (i = 1; i < 4; i++)
                {
                        if (isStrFullMatch(argv[4], (char *)mode_str[i], 0) == 0)
                                mt_desc.mode = i;
                }

                if (mt_desc.mode == 0)
                {
                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed,  mode should be 'mode1' 'mode2' or 'mode3' \n");
                        return -1;
                }

                for (i = 5; i < argc; i++)
                {
                        char* param[2];
                        int ret;
                        __replace_chr(argv[i], '(', ',');
                        __replace_chr(argv[i], ')', '\0');

                        if (get_arguments(argv[i], 2, param) < 2)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, parse module name & protect mode failed - %s\n", argv[i]);
                                return -1;
                        }

                        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "param[0]=%s, param[1]=%s\n", param[0], param[1]);

                        if ((ret = __module_id(param[0])) < 0)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, unkonwn module - %s\n", param[0]);
                                return -1;
                        }
                        if(i - 5 < DC_MT_ENTRY_COUNT)
                        {
                                mt_desc.ip_entry[i - 5].module = ret;
                        }

                        if ((ret = __prot_id(param[1])) < 0)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt parameter failed, unkonwn prot mode - %s\n", param[1]);
                                return -1;
                        }
                        if(i - 5 < DC_MT_ENTRY_COUNT)
                        {
                                mt_desc.ip_entry[i - 5].prot = ret;
                        }
                }

                if(entry < DC_MT_ENTRY_COUNT)
                {
                        _dcmt_set_monitor(entry, &mt_desc, 1);
                }
        }
        else
        {
                if(parse_dcmt_easy_set_cmd(buffer) < 0) //check if simple format cmd)
                {
                        show_dcmt_set_cmd();
                }
        }

        return 0;
}

static int callback_cmd_error(char * str)
{
        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "####CALLBACK ERROR!!!####\n");
        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "%s\n", str);
        return -1;
}

static int callback_cat_list(char* str)
{
        if(strncmp(str,"show_func", strlen("show_func"))==0){
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "------------DCMT REGISTERED MOUDLES------------\n");
                atomic_notifier_call_chain(&dcmt_notifier_list_cat, 0, NULL);
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "------------DCMT SHOW MOUDLUES END-------------\n");
                return 0;
        }else{
                return -1;
        }
}

//echo "callback TVSB2_DIW,180e0000,r" > /sys/mt/cntl
static int parse_callback_cmd(const char * buffer)
{
        int id = 0;
        int ret = 0;
        char* argv[3];
        char* cmd = __find_next_str((char*)buffer + strlen("callback"));
        int argc;

        if(cmd == NULL){        //no command
                return callback_cmd_error("Lack param");
        }

        argc = get_arguments((char*)cmd, 3, argv);

        if(callback_cat_list(argv[0]) == 0){
                return 0;
        }
        if(argc ==1){           //cmd "callback cat "
                return callback_cat_list(argv[0]);

        }else if(argc <3){      //lack cmd param
                return callback_cmd_error("Lack param");
        }

        id = __module_id(argv[0]);
        if(id < 0){
                return callback_cmd_error("set callback parameter failed, parse moudle name failed\n");
        }
        memset(&trap_info,0,sizeof(trap_info));//clear trap info

        trap_info.isTraped = 1;
        trap_info.module_id = id;
        if (sscanf(argv[1], "%lx", &trap_info.trash_addr) != 1) {
                ret = callback_cmd_error("set callback parameter failed, parse address failed\n");
                goto RET;
        }

         if (strncmp(argv[2], "r", 1) == 0){
                trap_info.rw_type = 0 ;
         }else if (strncmp(argv[2], "w", 1) == 0) {
                trap_info.rw_type = 1 ;
        } else {
                ret = callback_cmd_error("set callback parameter failed, parse r/w type failed\n");
                goto RET;
        }

        atomic_notifier_call_chain(&dcmt_notifier_list, 0, NULL);

RET:
        memset(&trap_info,0,sizeof(trap_info));//clear trap info
        return ret;
}

//dcmt_monitor_kernel_text
extern char _text[];
extern char _stext[];
extern char _etext[];
extern pgd_t swapper_pg_dir[];
static void dcmt_monitor_kernel_text(void) //use mem6
{
        DC_MT_DESC mt_desc;
        int kernel_mem_entry = DCMT_DFT_MEM_KERNEL;
#if CONFIG_ARM_KERNMEM_PERMS
        unsigned long phy_kernel_start = (unsigned long)_stext - PAGE_OFFSET;     //M6RTANOM-11:change start address swapper_pg_dir to _stext //protect start from mmu table
#else
        unsigned long phy_kernel_start = (unsigned long)swapper_pg_dir - PAGE_OFFSET;     ////protect start from mmu table ;
#endif
        unsigned long phy_kernel_end = (unsigned long)_etext - PAGE_OFFSET - DCMT_ALIGN_SIZE; //default value

        if(init_skip_mem[kernel_mem_entry])
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "[%s] skip this setting...\n",__FUNCTION__);
                return;
        }
        memset(&mt_desc, 0, sizeof(mt_desc));
        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = phy_kernel_start;
        mt_desc.end = phy_kernel_end;

        mt_desc.mode = 1; //trap if module_ID and access_type match
        mt_desc.ip_entry[0].module = MODULE_ANY; //all modules
        mt_desc.ip_entry[0].prot = PROT_MODE_WO; //access type write

        dcmt_set_monitor(kernel_mem_entry,&mt_desc);
}

static void dcmt_monitor_av_exception_region(void) //use mem7 monitor A/V exception header
{
        DC_MT_DESC mt_desc;

        memset(&mt_desc, 0, sizeof(mt_desc));
        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = 0x100;
        mt_desc.end = 0x140-1;

        mt_desc.mode = 1; //trap if module_ID and access_type match
        mt_desc.ip_entry[0].module = MODULE_ANY; //all modules
        mt_desc.ip_entry[0].prot = PROT_MODE_WO; //access type write

        dcmt_set_monitor(DCMT_DFT_MEM_AV_EXCEPTION, &mt_desc);
}

//set_monitor_redirect_code_DCU1_GPU
void set_monitor_redirect_code_DCU1_GPU(int index, unsigned int addr, unsigned int size) {
	DC_MT_DESC mt_desc;

	memset(&mt_desc, 0, sizeof(mt_desc));
	//monitor physical address address 0x0 ~ 0x60
	mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
	mt_desc.start = addr;
	mt_desc.end = addr + size - DCMT_ALIGN_SIZE;
	mt_desc.mode = 2; //2trap if no module_ID and access_type match
	mt_desc.ip_entry[0].module = MODULE_GPU;//MODULE_GPU;//MODULE_GPU|MODULE_TVSB3_SE; //GPU
	mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type write
	mt_desc.ip_entry[1].module = MODULE_SB1_EMMC_KC;//MODULE_GPU;//MODULE_GPU|MODULE_TVSB3_SE; //all module
	mt_desc.ip_entry[1].prot = PROT_MODE_RO; //access type write
	mt_desc.ip_entry[2].module = MODULE_SB1_EMMC_NKC;//MODULE_GPU;//MODULE_GPU|MODULE_TVSB3_SE; //all module
	mt_desc.ip_entry[2].prot = PROT_MODE_RO; //access type write

	DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "[GPU] func=%s line=%d addr=%x size=%x\n",__FUNCTION__,__LINE__,addr,size);
	dcmt_set_monitor(index,&mt_desc);
}
EXPORT_SYMBOL(set_monitor_redirect_code_DCU1_GPU);

//dcmt_monitor_over_range
static void dcmt_monitor_over_range(void) //use mem4(mem4 is mtex-0)
{
        DC_MT_DESC mt_desc;
        unsigned long total_ddr_size = 0x80000000;
        int over_range_entry = DCMT_DFT_MEM_OVERRANGE;

        if(init_skip_mem[over_range_entry])
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "[%s] skip this setting...\n",__FUNCTION__);
                return;
        }

        total_ddr_size = get_memory_size(GFP_DCU1) + get_memory_size(GFP_DCU2);
        //DC_MT_ERR("DCU1:%08x, DCU2:%08x, total:%08x\n", get_memory_size(GFP_DCU1), get_memory_size(GFP_DCU2),total_ddr_size);

        memset(&mt_desc, 0, sizeof(mt_desc));
        //monitor overrun range  0x80000000 ~ 0xffffffff
        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = total_ddr_size;
        mt_desc.end = 0xffffffff;

        if(total_ddr_size <= 0x40000000) //in mac5p. acpu will access 0x40000000 because HW bug.
        {
		    mt_desc.start = total_ddr_size;
            mt_desc.mode = 2; //trap if no module_ID and access_type match
            mt_desc.ip_entry[0].module = MODULE_SB2_ACPU; //ACPU1
            mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type read&write
#ifdef DCMT_AV2
                mt_desc.ip_entry[1].module = MODULE_SB2_ACPU2; //ACPU2
                mt_desc.ip_entry[1].prot = PROT_MODE_RW; //access type read&write
#endif
        }else{
            mt_desc.mode = 1; //trap if module_ID and access_type match
            mt_desc.ip_entry[0].module = MODULE_ANY; //all module
            mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type read&write
        }

dcmt_set_monitor(over_range_entry,&mt_desc);
}

static __maybe_unused void dcmt_monitor_0_1M_memory (void)
{
    DC_MT_DESC mt_desc;
    memset(&mt_desc, 0, sizeof(mt_desc));

    mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
    mt_desc.start = 0;
    mt_desc.end = 1*1024*1024-1;
    mt_desc.mode = 2;

    mt_desc.ip_entry[0].module = MODULE_SB2_ACPU;
    mt_desc.ip_entry[0].prot = PROT_MODE_RW;
#ifdef DCMT_AV2
    mt_desc.ip_entry[1].module = MODULE_SB2_ACPU2;
    mt_desc.ip_entry[1].prot = PROT_MODE_RW;
#endif
    mt_desc.ip_entry[2].module = MODULE_SB2_VCPU;
    mt_desc.ip_entry[2].prot = PROT_MODE_RW;
#ifdef DCMT_AV2
    mt_desc.ip_entry[3].module = MODULE_SB2_VCPU2;
    mt_desc.ip_entry[3].prot = PROT_MODE_RW;
#endif
    mt_desc.ip_entry[4].module = MODULE_SB2_KCPU;
    mt_desc.ip_entry[4].prot = PROT_MODE_RW;
    mt_desc.ip_entry[5].module = MODULE_ANY;
    mt_desc.ip_entry[5].prot = PROT_MODE_RO;

    dcmt_set_monitor(7,&mt_desc);
}

#ifdef CONFIG_REALTEK_SECURE
//dcmt_monitor_kcpu_text
static void dcmt_monitor_kcpu_text(unsigned int start, unsigned int end) //use mem5(mem5 is mtex-1)
{
        DC_MT_DESC mt_desc;
        int kcpu_mem_entry = DCMT_DFT_MEM_KCPU;
        unsigned int pagetable_size = 0x8000;

        if(init_skip_mem[kcpu_mem_entry])
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "[%s] skip this setting...\n",__FUNCTION__);
                return;
        }

        memset(&mt_desc, 0, sizeof(mt_desc));

        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = start;
        mt_desc.end = end;
        if((mt_desc.start == 0)||(mt_desc.end == 0))
        {
#ifdef CONFIG_OPTEE
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "DCMT use default range for OPTEE!\n");
                carvedout_buf_query(CARVEDOUT_K_OS,(void *)&mt_desc.start);
                mt_desc.start += pagetable_size;
                mt_desc.end = mt_desc.start + 0x3d000 - DCMT_ALIGN_SIZE;
#else   //ifndef CONFIG_OPTEE
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "DCMT use default range for KCPU!\n");
                carvedout_buf_query(CARVEDOUT_K_OS,(void *)&mt_desc.start);
                mt_desc.start += pagetable_size;
                mt_desc.end = mt_desc.start + 0x13d000 - DCMT_ALIGN_SIZE; //monitor K-Linux range
#endif  // CONFIG_OPTEE
        }

        mt_desc.end -= DCMT_ALIGN_SIZE;//avoid monitor too large range

        mt_desc.mode = 1;
        mt_desc.ip_entry[0].module = MODULE_ANY;//all module
        mt_desc.ip_entry[0].prot = PROT_MODE_WO; //access type read

        dcmt_set_monitor(kcpu_mem_entry,&mt_desc);
}
#endif  // #ifdef CONFIG_REALTEK_SECURE

//dcmt_monitor_acpu1_text
static void dcmt_monitor_acpu1_text(unsigned int start, unsigned int end) //use mem6(mem6 is mtex-2)
{
        DC_MT_DESC mt_desc;
        int acpu1_mem_entry = DCMT_DFT_MEM_ACPU;

        if(init_skip_mem[acpu1_mem_entry])
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "[%s] skip this setting...\n",__FUNCTION__);
                return;
        }
        memset(&mt_desc, 0, sizeof(mt_desc));

        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = start;
        mt_desc.end = end;
        if((mt_desc.start == 0)||(mt_desc.end == 0))
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "DCMT use default range for ACPU1!\n");
                mt_desc.start = 0x1a500500;//0x1a500510;
                mt_desc.end = 0x1a700000;
        }

        mt_desc.end -= DCMT_ALIGN_SIZE;//avoid monitor too large range

        mt_desc.mode = 1;
        mt_desc.ip_entry[0].module = MODULE_ANY;//all module
        mt_desc.ip_entry[0].prot = PROT_MODE_WO; //access type read

        dcmt_set_monitor(acpu1_mem_entry,&mt_desc);
}

//dcmt_monitor_vcpu1_text
static void dcmt_monitor_vcpu1_text(unsigned int start, unsigned int end) //use mem7(mem7 is mtex-3)
{
        DC_MT_DESC mt_desc;
        int vcpu1_mem_entry = DCMT_DFT_MEM_VCPU;

        if(init_skip_mem[vcpu1_mem_entry])
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "[%s] skip this setting...\n",__FUNCTION__);
                return;
        }
        memset(&mt_desc, 0, sizeof(mt_desc));

        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = start;
        mt_desc.end = end;
        if((mt_desc.start == 0)||(mt_desc.end == 0))
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "DCMT use default range for VCPU1!\n");
                mt_desc.start = 0x1a900400;//0x1a900410;
                mt_desc.end = 0x1ab80000;//0x1ab80000 - DCMT_ALIGN_SIZE;
        }

        mt_desc.end -= DCMT_ALIGN_SIZE; //avoid monitor too large range

        mt_desc.mode = 1;
        mt_desc.ip_entry[0].module = MODULE_ANY;//all module
        mt_desc.ip_entry[0].prot = PROT_MODE_WO; //access type read

        dcmt_set_monitor(vcpu1_mem_entry,&mt_desc);
}

//dcmt_monitor_kasan_range
#ifdef CONFIG_KASAN
#define DCMT_MONITOR_KASAN_SHADOW_RANGE()  dcmt_monitor_kasan_range()
static void dcmt_monitor_kasan_range(void) //use mem6(mem4 is mtex-2)
{
        DC_MT_DESC mt_desc;
        int kasan_mem_entry = DCMT_DFT_MEM_KASAN;

        if(init_skip_mem[kasan_mem_entry])
        {
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "[%s] skip this setting...\n",__FUNCTION__);
                return;
        }
        memset(&mt_desc, 0, sizeof(mt_desc));
        //monitor overrun range  0x80000000 ~ 0xffffffff
        mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
        mt_desc.start = KASAN_SHADOW_PHYS;
        mt_desc.end = KASAN_SHADOW_PHYS+KASAN_SHADOW_SIZE-1;
        pr_emerg("kasan dcmt range: %x %x\n",(unsigned int)mt_desc.start, (unsigned int)mt_desc.end);

        mt_desc.mode = 1; //trap if module_ID and access_type match
        mt_desc.ip_entry[0].module = MODULE_ANY; //all module
        mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type read&write

        // skip acpu check 0x40000000 for HW bug
        if ( (mt_desc.start<=0x40000000) && (mt_desc.end>=0x40000000) )
        {
            mt_desc.mode = 2; //trap if no module_ID and access_type match
            mt_desc.ip_entry[0].module = MODULE_SB2_ACPU; //ACPU1
            mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type read&write
            mt_desc.ip_entry[1].module = MODULE_ANY;//allow read(uart2rbus etc...)
            mt_desc.ip_entry[1].prot = PROT_MODE_RO; //access type read
        }

        dcmt_set_monitor(kasan_mem_entry,&mt_desc);
}
#else
#define DCMT_MONITOR_KASAN_SHADOW_RANGE() do{}while(0)
#endif

/*
monitor_over_range_test() is used to test kinds of overrange monitor case
ex:DDR size : 512M, 768M, 1G, 1.5G, 2G, 3G, 4G
*/
static void monitor_over_range_test(void) //use mem4(mem4 is mtex-0)
{
        DC_MT_DESC mt_desc;
        unsigned long ddr_size[] = {
                0x20000000,
                0x30000000,
                0x40000000,
                0x60000000,
                0x80000000,
                0xc0000000,
                0xffffffff
        };
        unsigned long total_ddr_size;
        int over_range_entry = DCMT_DFT_MEM_OVERRANGE;
        int i;

        disable_dcmt_scpu_intr_all();
        dcmt_unset_avk_intr_routing();

        for(i = 0; i < sizeof(ddr_size)/sizeof(unsigned long); ++i)
        {
                total_ddr_size = ddr_size[i];
                memset(&mt_desc, 0, sizeof(mt_desc));
                //monitor overrun range  0x80000000 ~ 0xffffffff
                mt_desc.type = MEMORY_TYPE_SERIAL_BLOCK;
                mt_desc.start = total_ddr_size;
                mt_desc.end = 0xffffffff;
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\n[%d]test DDR size 0x%08lx, user_start:0x%08lx, user_end:0x%08lx\n", i, total_ddr_size, mt_desc.start, mt_desc.end);
                if(total_ddr_size <= 0x40000000){
                        mt_desc.start = total_ddr_size;
                        mt_desc.mode = 2; //trap if no module_ID and access_type match
                        mt_desc.ip_entry[0].module = MODULE_SB2_ACPU; //ACPU1
                        mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type read&write
#ifdef DCMT_AV2
                        mt_desc.ip_entry[1].module = MODULE_SB2_ACPU2; //ACPU2
                        mt_desc.ip_entry[1].prot = PROT_MODE_RW; //access type read&write
#endif
                }else{
                        mt_desc.mode = 1; //trap if module_ID and access_type match
                        mt_desc.ip_entry[0].module = MODULE_ANY; //all module
                        mt_desc.ip_entry[0].prot = PROT_MODE_RW; //access type read&write
                }

                dcmt_set_monitor(over_range_entry,&mt_desc);
                dump_dcmt_last_set_only();
        }

        dcmt_clear_monitor(over_range_entry);

        enable_dcmt_scpu_intr_all();
        if(all_intr_routing_enable)
        {
                dcmt_set_all_cpu_intr_routing();
        }

        dcmt_monitor_over_range();
}
void set_dcmt_monitor_range(unsigned int * addr)
{
        dcmt_monitor_over_range();//mem0 for over range

#ifdef CONFIG_REALTEK_SECURE
#ifdef CONFIG_OPTEE
        dcmt_monitor_kcpu_text(addr[DCMT_RANGE_SYNC_SECURE_START], addr[DCMT_RANGE_SYNC_SECURE_END]);//mem1 for kcpu
#else
        dcmt_monitor_kcpu_text(addr[DCMT_RANGE_SYNC_K_START], addr[DCMT_RANGE_SYNC_K_END]);//mem1 for kcpu
#endif //endif CONFIG_OPTEE
#endif //endif CONFIG_REALTEK_SECURE
        //mem2 for GPU
        //mem3 for GPU

        dcmt_monitor_acpu1_text(addr[DCMT_RANGE_SYNC_A_START], addr[DCMT_RANGE_SYNC_A_END]);//mem4 for ACPU1
        dcmt_monitor_vcpu1_text(addr[DCMT_RANGE_SYNC_V_START], addr[DCMT_RANGE_SYNC_V_END]);//mem5 for VCPU1

        dcmt_monitor_kernel_text();//mem6 for kernel


#ifndef CONFIG_KASAN
        dcmt_monitor_av_exception_region();//mem7 for A/V exception region
#else
        DCMT_MONITOR_KASAN_SHADOW_RANGE();//mem7 for KASAN
#endif
        return;
}

/*
input : key_words
output : index
*/
int dcmt_monitor_carvedout_mem(char * key)
{
        carvedout_buf_t index = CARVEDOUT_NUM;
        unsigned int mem_size = 0;
        unsigned int mem_addr = 0;
        DC_MT_DESC desc;
        DC_MT_DESC * pDesc = &desc;
        int cmp_len;

        if(key == NULL)
                return CARVEDOUT_NUM;

        memset(pDesc,0,sizeof(DC_MT_DESC));

        if(strncasecmp(key,"DEMOD",strlen("DEMOD")) == 0 )
        {
                index = CARVEDOUT_DEMOD;
                cmp_len = strlen("DEMOD");
                pDesc->ip_entry[0].module = MODULE_TVSB5_DEMOD;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
        }
        else if(strncasecmp(key,"VDEC_RINGBUF",strlen("VDEC_RINGBUF")) == 0 )
        {
                index = CARVEDOUT_VDEC_RINGBUF;
                cmp_len = strlen("VDEC_RINGBUF");
                pDesc->ip_entry[0].module = MODULE_SB2_VCPU;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_SB3_VE;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
                pDesc->ip_entry[2].module = MODULE_VE;
                pDesc->ip_entry[2].prot = PROT_MODE_RW;
        }
#ifdef CONFIG_REALTEK_LOGBUF
        else if(strncasecmp(key,"LOGBUF",strlen("LOGBUF")) == 0 )
        {
                index = CARVEDOUT_LOGBUF;
                cmp_len = strlen("LOGBUF");
                pDesc->ip_entry[0].module = MODULE_SB2_ACPU;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_SB2_VCPU;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
                pDesc->ip_entry[2].module = MODULE_SB2_KCPU;
                pDesc->ip_entry[2].prot = PROT_MODE_RW;
        }
#endif
        else if(strncasecmp(key,"SCALER_MDOMAIN",strlen("SCALER_MDOMAIN")) == 0 )
        {
                index = CARVEDOUT_SCALER_MDOMAIN;
                cmp_len = strlen("SCALER_MDOMAIN");
                pDesc->ip_entry[0].module = MODULE_TVSB2_M_CAP;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_TVSB2_M_DISP;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
                pDesc->ip_entry[2].module = MODULE_TVSB2_S_CAP;
                pDesc->ip_entry[2].prot = PROT_MODE_RW;
                pDesc->ip_entry[3].module = MODULE_TVSB2_S_DISP;
                pDesc->ip_entry[3].prot = PROT_MODE_RW;
                pDesc->ip_entry[4].module = MODULE_TVSB2_DIW;
                pDesc->ip_entry[4].prot = PROT_MODE_RW;
                pDesc->ip_entry[5].module = MODULE_TVSB2_DIR;
                pDesc->ip_entry[5].prot = PROT_MODE_RW;
                pDesc->ip_entry[6].module = MODULE_TVSB2_SNR_R;
                pDesc->ip_entry[6].prot = PROT_MODE_RW;
                pDesc->ip_entry[7].module = MODULE_TVSB4_DMATO3DLUTR;
                pDesc->ip_entry[7].prot = PROT_MODE_RW;
        }
        else if(strncasecmp(key,"SCALER_OD",strlen("SCALER_OD")) == 0 )
        {
                index = CARVEDOUT_SCALER_OD;
                cmp_len = strlen("SCALER_OD");
                pDesc->ip_entry[0].module = MODULE_TVSB4_ODW;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_TVSB4_ODR;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
        }
        else if(strncasecmp(key,"TP",strlen("TP")) == 0 )
        {
                index = CARVEDOUT_TP;
                cmp_len = strlen("TP");
                //SB1_TP_NKC,SB1_TP_KC,SB1_TP2_NKC,SB1_TP2
                pDesc->ip_entry[0].module = MODULE_SB1_TP_NKC;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_SB1_TP_KC;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
                pDesc->ip_entry[2].module = MODULE_SB1_TP2_NKC;
                pDesc->ip_entry[2].prot = PROT_MODE_RW;
                pDesc->ip_entry[3].module = MODULE_SB1_TP2;
                pDesc->ip_entry[3].prot = PROT_MODE_RW;
        }
#ifdef CONFIG_CUSTOMER_TV006
        else if(strncasecmp(key,"GAL",strlen("GAL")) == 0 )
        {
                index = CARVEDOUT_GAL;
                cmp_len = strlen("GAL");
                //GPU, CPU , SE, GDMA
                pDesc->ip_entry[0].module = MODULE_GPU;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_SE2_Q0;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
                pDesc->ip_entry[2].module = MODULE_SE2_Q1;
                pDesc->ip_entry[2].prot = PROT_MODE_RW;
        }
#endif
#if 0
        else if(strncasecmp(key,"SCALER",strlen("SCALER")) == 0 )
        {
                index = CARVEDOUT_SCALER;
                cmp_len = strlen("SCALER");
        }
        else if(strncasecmp(key,"AV_DMEM",strlen("AV_DMEM")) == 0 )
        {
                index = CARVEDOUT_AV_DMEM;
                cmp_len = strlen("AV_DMEM");
        }
#endif
#if defined(CONFIG_REALTEK_RPC) ||defined(CONFIG_RTK_KDRV_RPC)
        else if(strncasecmp(key,"MAP_RPC",strlen("MAP_RPC")) == 0 )
        {
                index = CARVEDOUT_MAP_RPC;
                cmp_len = strlen("MAP_RPC");
                pDesc->ip_entry[0].module = MODULE_SB2_ACPU;
                pDesc->ip_entry[0].prot = PROT_MODE_RW;
                pDesc->ip_entry[1].module = MODULE_SB2_VCPU;
                pDesc->ip_entry[1].prot = PROT_MODE_RW;
                pDesc->ip_entry[2].module = MODULE_SB2_KCPU;
                pDesc->ip_entry[2].prot = PROT_MODE_RW;
        }
#endif
        else
        {
                index = CARVEDOUT_NUM;
                cmp_len = 0;
                DC_MT_ERR("Can't find %s area, may be not configed!\n",key);
        }

        if((index < CARVEDOUT_NUM)&&(strlen(key) == cmp_len))
        {
                mem_size = carvedout_buf_query(index,&mem_addr);
                DC_MT_WARNING("carvedout index : %d , addr : %08x, size : %08x\n",index, mem_addr, mem_size);
                pDesc->start = mem_addr;
                pDesc->end = mem_addr + mem_size - DCMT_ALIGN_SIZE;
                pDesc->type = MEMORY_TYPE_SERIAL_BLOCK;
                pDesc->mode = 2;

                if(dcmt_set_monitor_auto(pDesc) >= 0)
                {
                        dump_dcmt_last_set_only();
                }
        }
        else
        {
                index = CARVEDOUT_NUM;
        }

        if(index >= CARVEDOUT_NUM)
        {
                dump_carvedout_key();
        }

        return index;
}


static int parse_bootparam_mem_unset(char *pParam)
{
        int entry = -1;

        if(pParam == NULL)
        {
                return -1;
        }

        if(strcmp(pParam,"all") == 0)
        {
                entry = DC_MT_ENTRY_COUNT;
        }
        else if(strcmp(pParam,"over-range") == 0)
        {
                entry = DCMT_DFT_MEM_OVERRANGE;
        }
        else if(strcmp(pParam,"kcpu") == 0)
        {
                entry = DCMT_DFT_MEM_KCPU;
        }
        else if(strcmp(pParam,"acpu") == 0)
        {
                entry = DCMT_DFT_MEM_ACPU;
        }
        else if(strcmp(pParam,"vcpu") == 0)
        {
                entry = DCMT_DFT_MEM_VCPU;
        }
        else if(strcmp(pParam,"s-ker") == 0)
        {
                entry = DCMT_DFT_MEM_KERNEL;
        }
        else if(strcmp(pParam,"kasan") == 0)
        {
                entry = DCMT_DFT_MEM_KASAN;
        }
        else if(sscanf(pParam, "%d", &entry) != 1)
        {
                entry = -1;
        }

        DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "parse unset param [%s] to [%d]\n!",pParam,entry);

        return entry;
}

static int __init bootparam_mem_unset (char *str)
{
        char* argv[32];
        int argc;
        int i,j;
        int entry;

        if(str == NULL)
        {
                return -1;
        }

        DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "get param %s%s\n",DCMT_ENV_MEM_UNSET,str);

        //.step split param
        argc = get_arguments((char*)str, 32, argv);
        //.try parse param as string label
        for(i = 0; i < argc; ++i)
        {
                entry = parse_bootparam_mem_unset(argv[i]);
                DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "parse unset param %s as entry:%d\n",str,entry);
                if((entry >= 0)&&(entry < DC_MT_ENTRY_COUNT))
                {
                        init_skip_mem[entry] = 1;
                }
                else if(entry == DC_MT_ENTRY_COUNT)
                {
                        for(j = 0;j < DC_MT_ENTRY_COUNT;++j)
                        {
                                init_skip_mem[j] = 1;
                        }
                        break;//all is unset,so don't check other param
                }
        }

        return 0;
}
__setup(DCMT_ENV_MEM_UNSET, bootparam_mem_unset);

static int __init bootparam_mem_set (char *str)
{
        int entry = -1;
        char * buf = NULL;
        int argc = 0;
        char * argv[DC_MT_ENTRY_COUNT];
        int i;

        if(str == NULL)
        {
                return -1;
        }

        DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "get param %s%s\n",DCMT_ENV_MEM_SET,str);
        //.step change ",set" to " set" and split param
        while(1)
        {
                buf = strstr(str,",set");
                if(buf)
                {
                        *buf = ' ';
                }
                else
                {
                        break;
                }
        }
        //.step for loop to call parse easy cmd to set
        argc = get_space_arguments((char*)str, DC_MT_ENTRY_COUNT, argv);
        //.step for loop change '#' to ' '
        for(i = 0;i < argc;++i)
        {
                for(buf = argv[i];*buf != '\0';buf++)
                {
                        if(*buf == '#')
                        {
                                *buf = ' ';
                        }
                }
                DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "get a set param:%s\n",argv[i]);
                entry = parse_dcmt_easy_set_cmd(argv[i]);
                DCMT_LOG(DCMT_LOG_DBG, KERN_ERR, "parse_dcmt_easy_set_cmd return :%d\n",entry);
                if((entry >= 0)&&(entry < DC_MT_ENTRY_COUNT))
                {
                        init_skip_mem[entry] = 1;
                }
        }

        return 0;
}
__setup(DCMT_ENV_MEM_SET, bootparam_mem_set);

static int __init bootparam_dbg_log (char *str)
{
        int argc = 0;
        char * argv[16];
        int i;

        DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "get param %s%s\n",DCMT_ENV_DBG_LOG,str);

        if(str == NULL)
        {
                return -1;
        }

        argc = get_arguments((char*)str, 16, argv);

        for(i = 0;i < argc;++i)
        {
                apply_log_change(argv[i],1);
        }

        return 0;
}
__setup(DCMT_ENV_DBG_LOG, bootparam_dbg_log);

static int __init bootparam_keep_going (char *str)
{
        int mode = 0;

        if(str == NULL)
        {
                return -1;
        }

        DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "get param %s%s\n",DCMT_ENV_KEEP_GO,str);
        //.get mode,change mode and routing
        if(sscanf(str, "%d", &mode) != 1)
        {
                return -1;
        }

        if((mode >= DCMT_INTR_MODE_SILIENCE)&&(mode <= DCMT_INTR_MODE_PANIC))
        {
                kernel_trap_warning = mode;//change intr log mode

                if(mode < DCMT_INTR_MODE_PANIC)
                {
                        all_intr_routing_enable = 0;//disable a/v/k intr
                        dcmt_unset_avk_intr_routing();
                        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "Disabled avk intr routing!\n");
                }
                else
                {
                        all_intr_routing_enable = 1;//enable a/v/k intr
                        dcmt_set_all_cpu_intr_routing();
                        DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "Enabled avk intr routing!\n");
                }
        }

        return 0;
}
__setup(DCMT_ENV_KEEP_GO, bootparam_keep_going);

static int __init bootparam_driver_disable (char *str)
{
        if(str == NULL)
        {
                return -1;
        }

        DCMT_LOG(DCMT_LOG_INIT, KERN_ERR, "get param %s%s\n",DCMT_ENV_DRIVER_DISABLE,str);
        //.get mode,change mode and routing
        if(isStrFullMatch(str,"y",0) == 0)
        {
                dcmt_driver_disable = 1;
        }

        return 0;
}
__setup(DCMT_ENV_DRIVER_DISABLE, bootparam_driver_disable);
//---------------------------------user logic---------------------------------

//dcmt_reset_monitor
void dcmt_clear_monitor_all(void)
{
        int i;

        for (i = 0; i < DC_MT_ENTRY_COUNT; i++)
        {
                _dcmt_clear_monitor(i, 1);
        }
}

//dcmt_set_monitor
int dcmt_set_monitor(unsigned int entry, DC_MT_DESC * pDesc)
{
        return _dcmt_set_monitor(entry, pDesc, 1);
}
EXPORT_SYMBOL(dcmt_set_monitor);

//dcmt_set_monitor_auto
int dcmt_set_monitor_auto(DC_MT_DESC * pDesc)
{
        int entry_num = 0;
        int get_blank_num = 0;
        int blank_mark[DC_MT_ENTRY_COUNT];
        int i,j;
        int ret;

        //.step get entry num
        for(i = 0;i < 8;++i)
        {
                if(pDesc->ip_entry[i].prot != PROT_MODE_NONE)
                {
                        entry_num = i+1;
                }
        }
        DCMT_LOG(DCMT_LOG_SET, KERN_ERR, "[%s] get ip entry_num:%d\n",__FUNCTION__,entry_num);
        //dump_dcmt_desc("dump monitor set",pDesc);
        //.step auto found and set
		memset(blank_mark,0,sizeof(blank_mark));
        get_blank_num = find_blank_dcmt_entry(1,entry_num,blank_mark);
        //.step if not enough,hack blank_mark
        if(get_blank_num <= 0)
        {
                //force take them
                get_blank_num = force_get_dcmt_entry(1,entry_num,blank_mark);
                if(get_blank_num <= 0)//try again
                {
                        DCMT_LOG(DCMT_LOG_SET, KERN_ERR, "[%s] line%d , force_get_dcmt_entry() fail!\n",__FUNCTION__,__LINE__);
                        return -1;
                }
        }

        //.step set
        ret = 0;
        i = (last_set_entry > 0)?(last_set_entry - 1):(DC_MT_ENTRY_COUNT-1);
        j = 0;
        while(j < DC_MT_ENTRY_COUNT)
        {
                if(blank_mark[i])
                {
                        if(_dcmt_set_monitor(i, pDesc, 1))
                        {
                                return -1;
                        }
                        DCMT_LOG(DCMT_LOG_SET, KERN_ERR, "[%s] set mem%d OK!\n",__FUNCTION__,i);
                        ret = i;
                        j++;
                        break;
                }
                i = (i > 0)?(i - 1):(DC_MT_ENTRY_COUNT-1);
        }

        return ret;
}
EXPORT_SYMBOL(dcmt_set_monitor_auto);

//dcmt_clear_monitor
void dcmt_clear_monitor(unsigned int entry)
{
        _dcmt_clear_monitor(entry, 1);
}
EXPORT_SYMBOL(dcmt_clear_monitor);

//dcmt_set_intr_mode
//dcmt_set_intr_routing
void dcmt_set_all_cpu_intr_routing(void)
{
        unsigned int intr_flag = 0;
        intr_flag |= (1 << DCMT_INTR_ROUT_SCPU);
        intr_flag |= (1 << DCMT_INTR_ROUT_ACPU1);
#ifdef DCMT_AV2
        intr_flag |= (1 << DCMT_INTR_ROUT_ACPU2);
#endif
        intr_flag |= (1 << DCMT_INTR_ROUT_VCPU1);
#ifdef DCMT_AV2
        intr_flag |= (1 << DCMT_INTR_ROUT_VCPU2);
#endif
        intr_flag |= (1 << DCMT_INTR_ROUT_KCPU);
        change_dcmt_intr_routing(intr_flag);
}

void dcmt_unset_avk_intr_routing(void)
{
        unsigned int intr_flag = 0;
        intr_flag |= (1 << DCMT_INTR_ROUT_SCPU);
        change_dcmt_intr_routing(intr_flag);
}

void dcmt_toggle_avk_intr_routing(void)
{
        if(all_intr_routing_enable)
        {
                all_intr_routing_enable = 0;
                dcmt_unset_avk_intr_routing();
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "Disabled avk intr routing!\n");
        }
        else
        {
                all_intr_routing_enable = 1;
                dcmt_set_all_cpu_intr_routing();
                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "Enabled avk intr routing!\n");
        }
}

//dcmt_simulator_callback
int get_dcmt_trap_info(dcmt_trap_info *info)
{
        if(trap_info.isTraped)
        {
                memcpy(info, &trap_info, sizeof(trap_info));
        }
        else
        {
                memset(info, 0, sizeof(dcmt_trap_info));
        }

        return 0;
}
EXPORT_SYMBOL(get_dcmt_trap_info);

int isModuleIDBelonged(unsigned char id_src,unsigned char id_req)
{
        //DC_MT_ERR("check src:%02x req:%02x\n",id_src,id_req);
        if(id_src == id_req)
        {
                return 1;
        }
        else if( (SUB_MODULE_ID(id_req) == 0xf) && (BRIDGE_ID(id_req) == BRIDGE_ID(id_src))) //.check group id
        {
                return 1;
        }

        return 0;
}

int isDcmtTrap(char * module_name)
{
        int i,id = 0;
        const MODULE_SEARCH_TABLE * table = NULL;
        int table_len;
        int table_index;
        //.step find module
        id = __module_id(module_name);
        //.check id
        if(id < 0)
        {
                //search trap_table & key_table
                table = trap_table;
                table_len = sizeof(trap_table)/sizeof(MODULE_SEARCH_TABLE);
                table_index = module_table_search(table,table_len,module_name);
                if(table_index < 0)
                {
                        //search trap_table & key_table
                        table = key_table;
                        table_len = sizeof(key_table)/sizeof(MODULE_SEARCH_TABLE);
                        table_index = module_table_search(table,table_len,module_name);

                        if(table_index < 0)
                        {
                                DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "ERR:module [%s] is not exist!\n",module_name);
                                return 0;
                        }
                }
        }
        //.check trap
        if(!trap_info.isTraped)
        {
                return 0;
        }

        //.check single id
        if(id >= 0)
        {
                return isModuleIDBelonged(trap_info.module_id, id);
        }
        //.check tables
        for(i = 0;i < table[table_index].table_len;++i)
        {
                if(isModuleIDBelonged(trap_info.module_id, table[table_index].table[i]))
                {
                        return 1;
                }
        }

        return 0;//0 means match fail
}
EXPORT_SYMBOL(isDcmtTrap);

//---------------------------------driver frame work---------------------------------
#ifdef CONFIG_RTK_KDRV_MD

#include <linux/dma-mapping.h>
#include <rtk_kdriver/md/rtk_md.h>

extern void smd_checkComplete(void);

static void fill_random_pattern ( unsigned char* data, unsigned long size)
{
    int i;
    int val = jiffies;

    for (i = 0; i < size; i++) {
        data[i] = (i + val ) & 0xFF;
    }
    val++;
}

static uint8_t *srcBuf , *dstBuf;
static dma_addr_t src_phys_addr , dst_phys_addr;

void ddr_cpy(void)
{
    int length = 4096;

    smd_memcpy(dst_phys_addr, src_phys_addr, length);
    smd_checkComplete();
}

static void _ddr_cpy(unsigned int dst, unsigned int src, int len )
{
    DCMT_LOG(DCMT_LOG_CMD, KERN_WARNING, "_ddr_cpy dst == %#x src == %#x len == %#x \n", dst, src, len);
    smd_memcpy(dst, src, len);
    smd_checkComplete();
}

void dc_mt_test (void)
{
    DC_MT_DESC mt_desc;
    int length = 4096 * 10;
    int length2 = 4096;

    static int flag = 1;

    if (flag) {
        srcBuf = kmalloc(length, GFP_KERNEL);
        dstBuf = kmalloc(length, GFP_KERNEL);
        if (srcBuf == NULL || dstBuf == NULL) {
            DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "%s fail\n", __func__);
            return ;
        }

        srcBuf = (uint8_t *)(((unsigned long)srcBuf) & 0xFFFFF000);
        dstBuf = (uint8_t *)(((unsigned long)dstBuf) & 0xFFFFF000);

        //src_phys_addr=((unsigned int)srcBuf)&0xFFFFFFF;
        //dst_phys_addr=((unsigned int)dstBuf)&0xFFFFFFF;

        memset(dstBuf, 0, length2);
        fill_random_pattern(srcBuf, length2);
        flag = 0;
    }


    src_phys_addr = dma_map_single(NULL, (void *)srcBuf, length, DMA_FROM_DEVICE); //DMA_BIDIRECTIONAL
    dst_phys_addr = dma_map_single(NULL, (void *)dstBuf, length, DMA_FROM_DEVICE);
    DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "src_phys_addr = 0x%p\n", (void *)src_phys_addr);
    DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "dst_phys_addr = 0x%p\n", (void *)dst_phys_addr);
    DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\n\n\n\n\n");

    memset(&mt_desc, 0, sizeof(mt_desc));
    mt_desc.type = MEMORY_TYPE_SERIAL;
    mt_desc.start = dst_phys_addr;
    mt_desc.end = dst_phys_addr + length2;
    mt_desc.mode = 1;
    mt_desc.ip_entry[0].module = MODULE_SB3_MD_NKC;//MODULE_ANY;
    mt_desc.ip_entry[0].prot = PROT_MODE_WO;

    dcmt_set_monitor(3, &mt_desc);

    ddr_cpy();

    if(srcBuf != NULL){
        kfree(srcBuf);
        srcBuf = NULL;
    }
    if(dstBuf != NULL){
        kfree(dstBuf);
        dstBuf = NULL;
    }
}
#else

void dc_mt_test (void)
{
    DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "do dc_mt_test test filed empty!. please turn on CONFIG_RTK_KDRV_MD\n");
}

void ddr_cpy(void)
{
    DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "do ddr_cpy filed empty!. please turn on CONFIG_RTK_KDRV_MD\n");
}

static void _ddr_cpy(unsigned int dst, unsigned int src, int len )
{
    DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "do _ddr_cpy test filed empty!. please turn on CONFIG_RTK_KDRV_MD\n");
}
#endif

//dcmt_resume_restore
void dc_mt_resume(void)
{
        unsigned int  entry = 0;
        unsigned int tmp = 0;
        if(dcmt_driver_disable)
        {
                return;
        }

        if(all_intr_routing_enable)
        {
                dcmt_set_all_cpu_intr_routing();
        }
        else
        {
                dcmt_unset_avk_intr_routing();
        }

        enable_dcmt_scpu_intr_all();

        //disable cross range check
        tmp = rtd_inl(DC_SYS_DC_MT_MISC_reg);
        rtd_outl(DC_SYS_DC_MT_MISC_reg, tmp | BIT(0));
#ifdef DCMT_DCU2
        tmp = rtd_inl(DC2_SYS_DC_MT_MISC_reg);
        rtd_outl(DC2_SYS_DC_MT_MISC_reg, tmp | BIT(0));
#endif
        for(entry = 0; entry < DC_MT_ENTRY_COUNT; entry++)
        {
                _dcmt_clear_monitor(entry, 0);
                if(g_desc_store_dc[entry].mode != 0)
                {
                        dcmt_set_monitor(entry, &g_desc_store_dc[entry]);
                }
        }
}

//dcmt_isr
static irqreturn_t dc_mt_isr(int this_irq, void* dev_id)
{
        irqreturn_t ret = IRQ_NONE;
        DCID id;
        unsigned int entry;
        MT_SYS_ID sys_id;
        unsigned char old_loglevel;

        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "get into %s!\n", __FUNCTION__);
        //check dcmt intr pengding
        if(!is_dcmt_intr(&id, &entry, &sys_id))
        {
                return ret;
        }

        ret = IRQ_HANDLED; //now it's definitely a dcmt interrupt

        old_loglevel = console_loglevel;
        if(old_loglevel <= 3)
        {
                console_loglevel = 5;
        }
        //dump logs
        dump_memtrash_log(id, entry, sys_id);
        //panic
        if(kernel_trap_warning == DCMT_INTR_MODE_PANIC)
        {
                //local_irq_disable();
                rtd_save_keylog(KERN_DEBUG,DCMT_TAG,"%s\n",panic_dump_log);
                panic(panic_dump_log);
        }
        console_loglevel = old_loglevel;

        //clear intr
        clear_dcmt_trash_status(id, entry);

        memset(&trap_info, 0, sizeof(trap_info)); //clear trap info
        return ret;
}

static int dc_mt_proc_write(int data, const char *buffer)
{
        int entry;
        char key_words[64];

        switch((int)data)
        {
                case PROC_PARAM_CNTL:

                        DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "dc_mt_proc_write_cntl: %s\n", buffer);

                        if (strncmp(buffer, "reset", 5) == 0)
                        {
                                DCMT_LOG(DCMT_LOG_DBG, KERN_DEBUG, "reset dcmt to the init monitor setting\n");
                                set_dcmt_monitor_range(avk_range);
                        }
                        else if (strncmp(buffer, "set", 3) == 0)
                        {
                                if(parse_mt_set_cmd(buffer))
                                {
                                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "set mt failed - %s\n", buffer);
                                        goto end_proc;
                                }
                        }
                        else if (strncmp(buffer, "unset", 5) == 0)
                        {
                                if (sscanf(buffer, "unset mem%d", &entry) >= 1)
                                {
                                        dcmt_clear_monitor(entry);
                                }
                                else
                                {
                                        dcmt_clear_monitor_all();
                                }
                        }
                        else if (strncmp(buffer, "test", 4) == 0)
                        {
                                dc_mt_test();
                        }
#if 0
                        else if (strncmp(buffer, "ddrcpy", 6) == 0)
                        {
                                ddr_cpy();
                        }
#endif
                        else if (strncmp(buffer, "mdtest", strlen("mdtest")) == 0)
                        {
                                unsigned int src = 0, dst = 0, len = 0;

                                if (sscanf(buffer, "mdtest %x %x %x", &dst, &src, &len) < 3)
                                {
                                        DCMT_LOG(DCMT_LOG_ERR, KERN_ERR, "mdtest mt parameter failed, no dst or src or len specified\n");
                                        break;
                                }

                                if(len > 0)
                                {
                                        // KWarning: checked ok by muye_wang
                                        _ddr_cpy(dst, src, len );
                                }
                        }
                        else if (strncmp(buffer, "help", strlen("help")) == 0)
                        {
                                dump_dcmt_help_info();
                        }
                        else if (strncmp(buffer, "routen", strlen("routen")) == 0)
                        {
                                dcmt_toggle_avk_intr_routing();
                        }
                        else if (strncmp(buffer, "callback", strlen("callback")) == 0)
                        {
                                parse_callback_cmd(buffer);
                        }
                        else if (strncmp(buffer, "dumpreg", strlen("dumpreg")) == 0)
                        {
                                unsigned int dump_id = 0, dump_entry = 0;
                                if (sscanf(buffer, "dumpreg %x-%x", &dump_id, &dump_entry) < 1)
                                {
                                        dump_dcmt_regs_all();
                                }
                                else
                                {
                                        if((dump_id < DC_NUM)&&(dump_entry < DC_MT_ENTRY_COUNT))
                                        {
                                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "\ndump DCU%d entry%d regs\n",dump_id+1,dump_entry);
                                                dump_dcmt_regs(&dc_regs[dump_id][dump_entry]);
                                        }
                                        else
                                        {
                                                DCMT_LOG(DCMT_LOG_CMD, KERN_ERR, "dumpreg %x-%x param error!\n dump common reg only!\n",dump_id,dump_entry);
                                                dump_dcmt_common_regs();
                                        }
                                }
                        }
                        else if(strncmp(buffer, "search", strlen("search")) == 0)
                        {
                                char key_words[64];
                                memset(key_words,0,sizeof(key_words));

                                if (sscanf(buffer, "search %64s", key_words) < 1)
                                {
                                        dump_module_key_table(NULL);
                                }
                                else
                                {
                                        dump_module_key_table(key_words);
                                }
                        }
                        else if (strncmp(buffer, "carvedout", strlen("carvedout")) == 0)
                        {
                                memset(key_words,0,sizeof(key_words));
                                if (sscanf(buffer, "carvedout %64s", key_words) >= 1)
                                {
                                        dcmt_monitor_carvedout_mem(key_words);
                                }
                                else
                                {
                                        dump_carvedout_key();
                                }
                        }
                        else if(strncmp(buffer, "show_set", strlen("show_set")) == 0)
                        {
                                dump_dcmt_last_set();
                        }
                        else if(strncmp(buffer, "log_set", strlen("log_set")) == 0)
                        {
                                memset(key_words,0,sizeof(key_words));
                                if (sscanf(buffer, "log_set %64s", key_words) >= 1)
                                {
                                        apply_log_change(key_words,1);
                                }
                        }
                        else if(strncmp(buffer, "log_unset ", strlen("log_unset ")) == 0)
                        {
                                memset(key_words,0,sizeof(key_words));
                                if (sscanf(buffer, "log_unset %64s", key_words) >= 1)
                                {
                                        apply_log_change(key_words,0);
                                }
                        }
                        else if(strncmp(buffer, "over_range_test", strlen("over_range_test")) == 0)
                        {
                                monitor_over_range_test();
                        }
                        else
                        {
                                dump_dcmt_help_info();
                        }

                default:
                        break;
        }


end_proc:

        return 0;
}

static int dc_mt_proc_read(int data, char *buffer)
{
        int ret = 0;
        int len = 0;
        int i;
        int count = 4096;
        DCID id;

        char * ib_mode_str[6] =
        {
                "DC1",
                "DC2",
                "DC1:DC2 1:1",
                "DC1:DC2 1:1 Scramble",
                "DC1:DC2 1:2",
                "DC1:DC2 2:1"
        };

        switch((int) data)
        {
                case PROC_PARAM_CNTL:
                        ret = sprintf(buffer, "kernel_trap_warning=%d (0:silence 1:simple 2:print 3:panic)\n", kernel_trap_warning);
                        buffer += ret;
                        len    += ret;

                        ret = sprintf(buffer, "all_intr_routing_enable=%d (0:disable avk 1:enable avk)\n", all_intr_routing_enable);
                        buffer += ret;
                        len    += ret;
                        ret = sprintf(buffer, "dcmt_log_setting=0x%08x\n", dcmt_log_setting);
                        buffer += ret;
                        len    += ret;

                        for(id = DCID_1; id < DC_NUM; ++id)
                        {
                                ret = sprintf(buffer, "\nDCU%d setting : \n", id+1);
                                buffer += ret;
                                len    += ret;
                                for (i = 0; i < DC_MT_ENTRY_COUNT; i++)
                                {
                                        ret = _get_dcmt_entry_desc_str(id, i, buffer, count, 1);

                                        if (ret < 0)
                                                return -EINVAL;

                                        len    += ret;
                                        buffer += ret;
                                }
                        }
                        break;

                case PROC_PARAM_STAT:
                        ret = sprintf(buffer, "kernel_trap_warning=%d (0:silence 1:simple 2:print 3:panic)\n", kernel_trap_warning);
                        buffer += ret;
                        len    += ret;

                        ret = sprintf(buffer, "all_intr_routing_enable=%d (0:disable avk 1:enable avk)\n", all_intr_routing_enable);
                        buffer += ret;
                        len    += ret;

                        ret = sprintf(buffer, "dcmt_log_setting=0x%08x\n", dcmt_log_setting);
                        buffer += ret;
                        len    += ret;
                        ret = sprintf(buffer, "IB INFO:\n");
                        buffer += ret;
                        len    += ret;
                        ret = sprintf(buffer, "IB_SEQ_REGION_SET = 0x%08X \n", IB_SEQ_REGION_SET);
                        buffer += ret;
                        len    += ret;
                        for(i = 0; i < BOUND_3; ++i)
                        {
                                ret = sprintf(buffer, "phy_region_%d: [0x%08x - 0x%08x] slice:%d mode:%s\n", i, ib_seq_bound[SEQ_PHY][i], ib_seq_bound[SEQ_PHY][i + 1], region_slice[i], ib_mode_str[region_mode[i]]);
                                buffer += ret;
                                len    += ret;
                        }
                        ret = sprintf(buffer, "phy_region_%d: [0x%08x - 0x%08x] slice:%d mode:%s\n", BOUND_NUM - 1, ib_seq_bound[SEQ_PHY][BOUND_NUM - 1], 0xFFFFFFFF, region_slice[BOUND_NUM-1], ib_mode_str[region_mode[BOUND_NUM - 1]]);
                        buffer += ret;
                        len    += ret;
                        for(i = 0; i < BOUND_3; ++i)
                        {
                                ret = sprintf(buffer, "dc1_region_%d: [0x%08x - 0x%08x] mode:%s\n", i, ib_seq_bound[SEQ_DC1][i], ib_seq_bound[SEQ_DC1][i + 1], ib_mode_str[region_mode[i]]);
                                buffer += ret;
                                len    += ret;
                        }
                        ret = sprintf(buffer, "dc1_region_%d: [0x%08x - 0x%08x] mode:%s\n", BOUND_NUM - 1, ib_seq_bound[SEQ_DC1][BOUND_NUM - 1], 0xFFFFFFFF, ib_mode_str[region_mode[BOUND_NUM - 1]]);
                        buffer += ret;
                        len    += ret;
                        for(i = 0; i < BOUND_3; ++i)
                        {
                                ret = sprintf(buffer, "dc2_region_%d: [0x%08x - 0x%08x] mode:%s\n", i, ib_seq_bound[SEQ_DC2][i], ib_seq_bound[SEQ_DC2][i + 1], ib_mode_str[region_mode[i]]);
                                buffer += ret;
                                len    += ret;
                        }
                        ret = sprintf(buffer, "dc2_region_%d: [0x%08x - 0x%08x] mode:%s\n", BOUND_NUM - 1, ib_seq_bound[SEQ_DC2][BOUND_NUM - 1], 0xFFFFFFFF, ib_mode_str[region_mode[BOUND_NUM - 1]]);
                        buffer += ret;
                        len    += ret;
                        for(id = DCID_1; id < DC_NUM; ++id)
                        {
                                ret = sprintf(buffer, "\nDCU%d setting : \n", id+1);
                                buffer += ret;
                                len    += ret;
                                for (i = 0; i < DC_MT_ENTRY_COUNT; i++)
                                {
                                        ret = _get_dcmt_entry_desc_str(id, i, buffer, count, 0);

                                        if (ret < 0)
                                                return -EINVAL;

                                        len    += ret;
                                        buffer += ret;
                                }
                        }
                        break;

                case PROC_PARAM_MODULES:
                        ret = get_dcmt_modues(buffer);
                        buffer += ret;
                        len += ret;

                        ret = get_module_keys(buffer);
                        buffer += ret;
                        len += ret;

                case PROC_PARAM_LOG:
                default:
                        break;
        }

        return len;
}

static ssize_t dc_mt_show(struct kobject *kobj, struct kobj_attribute *attr,
                          char *buf)
{
        if (strcmp(attr->attr.name, "modules") == 0)
        {
                dc_mt_proc_read(PROC_PARAM_MODULES, buf);
        }

        if (strcmp(attr->attr.name, "cntl") == 0)
        {
                dc_mt_proc_read(PROC_PARAM_CNTL, buf);
        }

        if (strcmp(attr->attr.name, "stat") == 0)
        {
                dc_mt_proc_read(PROC_PARAM_STAT, buf);
        }

        return sprintf(buf, "%s\n", buf);
}

static ssize_t dc_mt_store(struct kobject *kobj, struct kobj_attribute *attr,
                           const char *buf, size_t count)
{
        if (strcmp(attr->attr.name, "cntl") == 0)
        {
                dc_mt_proc_write(PROC_PARAM_CNTL, buf);
        }

        return count;
}

//---------------------------------module init & exit---------------------------------
static struct kobj_attribute dc_mt_modules_attribute =
        __ATTR(modules, ATTR_PERMISSION_RO, dc_mt_show, NULL);
static struct kobj_attribute dc_mt_cntl_attribute =
        __ATTR(cntl, ATTR_PERMISSION_RW, dc_mt_show, dc_mt_store);
static struct kobj_attribute dc_mt_stat_attribute =
        __ATTR(stat, ATTR_PERMISSION_RO, dc_mt_show, NULL);


static struct attribute *attrs[] =
{
        &dc_mt_modules_attribute.attr,
        &dc_mt_cntl_attribute.attr,
        &dc_mt_stat_attribute.attr,
        NULL,   /* need to NULL terminate the list of attributes */
};

static struct attribute_group attr_group =
{
        .attrs = attrs,
};
static struct kobject *dc_mt_kobj;

static int __init dc_mt_module_init(void)
{
        int retval;

        if (request_irq(DCU_IRQ, dc_mt_isr, IRQF_SHARED, "DC_SYS", (void*) DC_MT_DEV_FILE_NAME) < 0)
        {
                DC_MT_ERR("init dc_mt failed : request irq %d failed\n", DCU_IRQ);
                return -EFAULT;
        }

        init_dcregs_vari();

        memset(avk_range,0,sizeof(avk_range));
        _dc_mt_get_avk_range(avk_range); //get avk monitor range before clear reg
        _dc_mt_clear_all_monitor();

        DC_MT_DBG("dc_mt_dev_init successfully\n");

        dc_mt_kobj = kobject_create_and_add("mt", NULL);
        if (!dc_mt_kobj)
                return -ENOMEM;

        retval = sysfs_create_group(dc_mt_kobj, &attr_group);
        if (retval)
                kobject_put(dc_mt_kobj);

        clear_notifier_info();

        if(all_intr_routing_enable)
        {
                dcmt_set_all_cpu_intr_routing();
        }
        else
        {
                dcmt_unset_avk_intr_routing();
        }

        enable_dcmt_scpu_intr_all();
        set_dcmt_monitor_range(avk_range);
        //dump_dcmt_regs_all();

        return retval;
}

/*------------------------------------------------------------------
 * Func : dc_mt_module_exit
 *
 * Desc : mcp module init function
 *
 * Parm : N/A
 *
 * Retn : N/A
 *------------------------------------------------------------------*/
static void __exit dc_mt_module_exit(void)
{
        _dc_mt_clear_all_monitor();// reset
        free_irq(DCU_IRQ, DC_MT_DEV_FILE_NAME);
}

#ifdef CONFIG_ARM64
static int dc_mt_probe(struct platform_device *pdev)
{
        dc_mt_module_init();
        return 0;
}

static const struct of_device_id dcmt_of_match[] =
{
        {
                .compatible = "realtek,dcmt",
        },
        {},
};

static struct platform_driver dcmt_driver =
{
        .probe          = dc_mt_probe,
        .driver = {
                .name = "dcmt",
                .of_match_table = dcmt_of_match,
        },
};
MODULE_DEVICE_TABLE(of, dcmt_of_match);
module_platform_driver(dcmt_driver);
#else
module_init(dc_mt_module_init);
module_exit(dc_mt_module_exit);
#endif

