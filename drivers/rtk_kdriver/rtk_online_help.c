#include <linux/init.h> 
#include <mach/rtk_log.h>       //rtd_printk
#include <linux/module.h>       //EXPORT_SYMBOL
#include <linux/slab.h>           // kmalloc()
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/sysfs.h>
#include <linux/kernel.h>  
#include <linux/device.h>  
#include <linux/uaccess.h>
#include <linux/slab.h>     /* kmalloc()*/


#define DBG_HELP_TAG "ONLINE_HELP"
//#define BIT(x)               (1 <<x)
#define DBG_BUF_SIZE 128
//main operation

#define HELP_MAIN_DCMT                  "dcmt"
#define HELP_MAIN_SB2                     "sb2"
#define HELP_MAIN_ARM_WRAPPER  "arm_wrapper"
#define HELP_MAIN_USBDUMP            "usbdump"
#define HELP_MAIN_LOGBUF               "logbuf"
#define HELP_MAIN_RTD_TOOL          "rtd_tool"
#define HELP_MAIN_ALL                     "all"
#define HELP_MAIN_HELP                    "help"
//sub operation
#define HELP_SUB_RTD_TOOL             "rtd_tool"
#define HELP_SUB_SHELL_CMD           "shell_cmd"
#define HELP_SUB_BOOT_CMD            "boot_cmd"
#define HELP_SUB_OFFLINE_TOOL       "offline_tool"
//#define HELP_SUB_OFFLINE_WIN       "offline_win"
//#define HELP_SUB_OFFLINE_LINUX    "offline_linux"
#define HELP_SUB_TRIAD                    "triad"
#define HELP_SUB_DCMT                     "dcmt"
#define HELP_SUB_SB2                        "sb2"
#define HELP_SUB_ARM_WRAPPER      "arm_wrapper"
#define HELP_SUB_LOGBUF                  "logbuf"

typedef enum{
        DCMT = 0,
        SB2,
        ARM_WRAPPER,
        USBDUMP,
        LOGBUF,
        RTD_TOOL,
        ALL,
        HELP,
        OPT_MAX_NUM
}MAIN_OPT;

typedef enum{
        DCMT_RTD_TOOL = 0,
        DCMT_SHELL_CMD,
        DCMT_OPT_MAX_NUM
}DCMT_SUB_OPT;

typedef enum{
        SB2_RTD_TOOL = 0,
        SB2_SHELL_CMD,
        SB2_OPT_MAX_NUM
}SB2_SUB_OPT;

typedef enum{
        ARM_WRAPPER_RTD_TOOL = 0,
        ARM_WRAPPER_SHELL_CMD,
        ARM_WRAPPER_OPT_MAX_NUM
}ARM_WRAPPER_SUB_OPT;

typedef enum{
        USBDUMP_KERNEL = 0,
        USBDUMP_AP,
        USBDUMP_OPT_MAX_NUM
}USBDUMP_SUB_OPT;

typedef enum{
        LOGBUF_RTD_TOOL = 0,
        LOGBUF_BOOT_CMD,
        LOGBUF_SHELL_CMD,
        LOGBUF_OFFLINE_TOOL,
        //LOGBUF_OFFLINE_WIN,
        //LOGBUF_OFFLINE_LINUX,
        LOGBUF_OPT_MAX_NUM
}LOGBUF_SUB_OPT;

typedef enum{
        RTD_TOOL_TRIAD = 0,
        RTD_TOOL_DCMT,
        RTD_TOOL_SB2,
        RTD_TOOL_ARM_WRAPPER,
        RTD_TOOL_LOGBUF,
        RTD_TOOL_OPT_MAX_NUM
}RTD_TOOL_SUB_OPT;

char * p_main_opt  = NULL;
char * p_dcmt_sub_opt = NULL;
char * p_sb2_sub_opt = NULL;
char * p_arm_wrapper_sub_opt = NULL;
char * p_usbdump_sub_opt = NULL;
char * p_logbuf_sub_opt = NULL;
char * p_rtd_tool_sub_opt = NULL;

/*
main_opt:dcmt           sub_opt:rtd_tool, shell_cmd
main_opt:sb2             sub_opt:rtd_tool, shell_cmd
main_opt:arm_wraper  sub_opt:rtd_tool, shell_cmd
main_opt:usbdump     sub_opt:N/A
main_opt:logbuf         sub_opt:rtd_tool, boot_cmd, shell_cmd, offline_tool
main_opt:rtd_tool       sub_opt:triad, dcmt, sb2, arm_wrapper, logbuf
main_opt:all               sub_opt:N/A show all main_opts
main_opt:help            sub_opt:N/A show on-line help usage                     
*/
#define CHAR_SPACE  32
static char* __find_next_str(char* str, char c)
{
        char* end = str + strlen(str);

        while(str < end)
        {
                if ((*str)!=CHAR_SPACE) // is alphabet or number
                        return str;
                str++;
        }

        return NULL;
}

static int split_str(char* str, int argc, char** argv, char c)
{
        int ret = 0;
        char * sep;
        
        while((ret<argc) && (str = __find_next_str(str, c))){
                if(str==NULL){
                        break;
                }
                argv[ret++] = str;
                sep = strchr(str, c); // devided by
                
                if (sep == NULL)
                        break;

                *sep = '\0'; // changed to null terminated
                str = sep + 1;
        }
        return ret;
}

int dbg_help_kmalloc(char **p, int size)
{
        if(size <=0){
                return -1;
        }
        
        if(*p == NULL){
                *p = kmalloc(size*sizeof(char), GFP_KERNEL);

                if(*p == NULL){
                        rtd_printk( KERN_ERR, DBG_HELP_TAG, "kmalloc error\n");
                        return -1;
                }                
        }
        memset(*p, 0, size*sizeof(char));
        return 0;
}

///***************************set*******************************/////
int dbg_help_set_dcmt(char **argv, int num)
{
        int i;

        if(num == 1){   //no sub operation
                return 0;
        }
        
        if(dbg_help_kmalloc(&p_dcmt_sub_opt, DCMT_OPT_MAX_NUM)){
                return -1;
        }
        
        for(i=1; i<num; i++){
                if(strncasecmp(argv[i],HELP_SUB_RTD_TOOL, sizeof(HELP_SUB_RTD_TOOL)-1) == 0){
                        *(p_dcmt_sub_opt+DCMT_RTD_TOOL) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_SHELL_CMD, sizeof(HELP_SUB_SHELL_CMD)-1) == 0){
                        *(p_dcmt_sub_opt+DCMT_SHELL_CMD) = 1;
                }else{
                        rtd_printk( KERN_ERR, DBG_HELP_TAG, "[warning] Unknow operation '%s'\n", argv[i]);
                }
        }

        return 0;
}

int dbg_help_set_sb2(char **argv, int num)
{
        int i;

        if(num == 1){
                return 0;
        }

        if(dbg_help_kmalloc(&p_sb2_sub_opt, SB2_OPT_MAX_NUM)){
                return -1;
        }
        
        for(i=1; i<num; i++){
                if(strncasecmp(argv[i],HELP_SUB_RTD_TOOL, sizeof(HELP_SUB_RTD_TOOL)-1) == 0){
                        *(p_sb2_sub_opt+SB2_RTD_TOOL) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_SHELL_CMD, sizeof(HELP_SUB_SHELL_CMD)-1) == 0){
                        *(p_sb2_sub_opt+SB2_SHELL_CMD) = 1;
                }else{
                        rtd_printk( KERN_ERR, DBG_HELP_TAG, "[warning] Unknow operation '%s'\n", argv[i]);
                }
        }
        return 0;
}

int dbg_help_set_arm_wrapper(char **argv, int num)
{
        int i;

        if(num == 1){
                return 0;
        }

        if(dbg_help_kmalloc(&p_arm_wrapper_sub_opt, ARM_WRAPPER_OPT_MAX_NUM)){
                return -1;
        }

        for(i=1; i<num; i++){
                if(strncasecmp(argv[i],HELP_SUB_RTD_TOOL, sizeof(HELP_SUB_RTD_TOOL)-1) == 0){
                        *(p_arm_wrapper_sub_opt+SB2_RTD_TOOL) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_SHELL_CMD, sizeof(HELP_SUB_SHELL_CMD)-1) == 0){
                        *(p_arm_wrapper_sub_opt+SB2_SHELL_CMD) = 1;
                }else{
                        rtd_printk( KERN_ERR, DBG_HELP_TAG, "[warning] Unknow operation '%s'\n", argv[i]);
                }
        }
        return 0;
}

int dbg_help_set_usbdump(char **argv, int num)
{
        // no sub operation

        return 0;
}

int dbg_help_set_logbuf(char **argv, int num)
{
        int i;

        if(num == 1){
                return 0;
        }
        
        if(dbg_help_kmalloc(&p_logbuf_sub_opt, LOGBUF_OPT_MAX_NUM)){
                return -1;
        }
        
        for(i=1; i<num; i++){
                if(strncasecmp(argv[i],HELP_SUB_RTD_TOOL, sizeof(HELP_SUB_RTD_TOOL)-1) == 0){
                        *(p_logbuf_sub_opt+LOGBUF_RTD_TOOL) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_BOOT_CMD, sizeof(HELP_SUB_BOOT_CMD)-1) == 0){
                        *(p_logbuf_sub_opt+LOGBUF_BOOT_CMD) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_SHELL_CMD, sizeof(HELP_SUB_SHELL_CMD)-1) == 0){
                        *(p_logbuf_sub_opt+LOGBUF_SHELL_CMD) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_OFFLINE_TOOL, sizeof(HELP_SUB_OFFLINE_TOOL)-1) == 0){
                        *(p_logbuf_sub_opt+LOGBUF_OFFLINE_TOOL) = 1;

#if 0                        
                }else if(strncasecmp(argv[i],HELP_SUB_OFFLINE_WIN, sizeof(HELP_SUB_OFFLINE_WIN)-1) == 0){
                        *(p_logbuf_sub_opt+LOGBUF_OFFLINE_WIN) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_OFFLINE_LINUX, sizeof(HELP_SUB_OFFLINE_LINUX)-1) == 0){
                        *(p_logbuf_sub_opt+LOGBUF_OFFLINE_LINUX) = 1;
#endif
                }else{
                        rtd_printk( KERN_ERR, DBG_HELP_TAG, "[warning] Unknow operation '%s'\n", argv[i]);
                }
        }

        return 0;
}

int dbg_help_set_rtd_tool(char **argv, int num)
{
        int i;

        if(num == 1){
                return 0;
        }
        
        if(dbg_help_kmalloc(&p_rtd_tool_sub_opt, RTD_TOOL_OPT_MAX_NUM)){
                return -1;
        }
                
        for(i=1; i<num; i++){
                if(strncasecmp(argv[i],HELP_SUB_TRIAD, sizeof(HELP_SUB_TRIAD)-1) == 0){
                        *(p_rtd_tool_sub_opt+RTD_TOOL_TRIAD) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_DCMT, sizeof(HELP_SUB_DCMT)-1) == 0){
                        *(p_rtd_tool_sub_opt+RTD_TOOL_DCMT) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_SB2, sizeof(HELP_SUB_SB2)-1) == 0){
                        *(p_rtd_tool_sub_opt+RTD_TOOL_SB2) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_ARM_WRAPPER, sizeof(HELP_SUB_ARM_WRAPPER)-1) == 0){
                        *(p_rtd_tool_sub_opt+RTD_TOOL_ARM_WRAPPER) = 1;
                }else if(strncasecmp(argv[i],HELP_SUB_LOGBUF, sizeof(HELP_SUB_LOGBUF)-1) == 0){
                        *(p_rtd_tool_sub_opt+RTD_TOOL_LOGBUF) = 1;
                }else{
                        rtd_printk( KERN_ERR, DBG_HELP_TAG, "[warning] Unknow operation '%s'\n", argv[i]);
                }
        }
        return 0;
}

void dbg_help_clear_flags(void)
{
        if(p_main_opt != NULL){
                kfree(p_main_opt);
                p_main_opt = NULL;
        }

        //sub opt
        if(p_dcmt_sub_opt != NULL){
                kfree(p_dcmt_sub_opt);
                p_dcmt_sub_opt = NULL;
        }
        
        if(p_sb2_sub_opt != NULL){
                kfree(p_sb2_sub_opt);
                p_sb2_sub_opt = NULL;
        }
        
        if(p_arm_wrapper_sub_opt != NULL){
                kfree(p_arm_wrapper_sub_opt);
                p_arm_wrapper_sub_opt = NULL;
        }

        if(p_usbdump_sub_opt != NULL){
                kfree(p_usbdump_sub_opt);
                p_usbdump_sub_opt = NULL;
        }

        if(p_logbuf_sub_opt != NULL){
                kfree(p_logbuf_sub_opt);
                p_logbuf_sub_opt = NULL;
        }

        if(p_rtd_tool_sub_opt != NULL){
                kfree(p_rtd_tool_sub_opt);
                p_rtd_tool_sub_opt = NULL;
        }

}

#if 0
int dbg_help_printf(char __user * buf, loff_t *ofst, char * str)
{
        int ret;
        
        ret = copy_to_user(buf+(*ofst), str, strlen(str));
        if(!ret){
                *ofst += (strlen(str)-ret);
                //return strlen(str)-ret;
                return strlen(str);
        }
        *ofst += strlen(str);

        return strlen(str);
}

#else
int dbg_help_printf(char __user * buf, loff_t *ofst, const char * fmt, ...)
{
        va_list args;
        int i;
        char *tmp_buf = NULL;
        int ret;

        tmp_buf = kmalloc(PAGE_SIZE, GFP_KERNEL);

        if(tmp_buf == NULL){
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "kmalloc fail\n");
                return 0;
        }
        memset(tmp_buf, 0, PAGE_SIZE);

        va_start(args, fmt);
        i = vsnprintf(tmp_buf, INT_MAX, fmt, args);
        va_end(args);

        ret = copy_to_user(buf+(*ofst), tmp_buf, i);
        if(!ret){
                *ofst += (i-ret);
                goto RET;
        }
        *ofst += i;
        
RET:
        kfree(tmp_buf);
        return i;
}
#endif

int dbg_help_usage(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mON-LINE HELP USAGE:\e[0m\n\n");
        len += dbg_help_printf(buf, ofst, "%4s Step1: echo \"main_opt sub_opt1 sub_opt2 ...\" > /dev/dbg_help\n"," ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:dcmt        sub_opt:rtd_tool, shell_cmd\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:sb2         sub_opt:rtd_tool, shell_cmd\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:arm_wraper  sub_opt:rtd_tool, shell_cmd\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:usbdump     sub_opt:N/A\n", " ");
        //len += dbg_help_printf(buf, ofst, "%10s main_opt:logbuf      sub_opt:rtd_tool, boot_cmd, shell_cmd, offline_win, offline_linux\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:logbuf      sub_opt:rtd_tool, boot_cmd, shell_cmd, offline_tool\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:rtd_tool    sub_opt:triad, dcmt, sb2, arm_wrapper, logbuf\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:all         sub_opt:N/A show all main_opts\n", " ");
        len += dbg_help_printf(buf, ofst, "%10s main_opt:help        sub_opt:N/A show on-line help usage\n", " ");
        
        len += dbg_help_printf(buf, ofst, "%4s Step2: cat /dev/dbg_help\n"," ");

        return len;
}

int dbg_help_show_dcmt_rtd_tool(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nRTD_TOOL:\n");
        len += dbg_help_printf(buf, ofst, "%4s rtd hw_monitor  -easy set. hw monitor triad func enter commad, set by tips\n"," ");
        len += dbg_help_printf(buf, ofst, "%4s rtd dcmt        -dcmt rtd debug enter command\n", " ");
        return len;
}
int dbg_help_show_dcmt_shell_cmd(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nSHELL CMD:\n");
        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mset DCMT\e[0m        -simple cmd: set <start>,<end>\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set 0x108000,0x700000\" > /sys/mt/cntl\e[0m                   (all IP can not write [0x108000,0x700000] region)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set 0x108000,0x700000 ip:ANY(rw)\" > /sys/mt/cntl\e[0m        (all IP can not read/write [0x108000,0x700000] region)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set 0x108000,0x700000 ip:MEMC(r)\" > /sys/mt/cntl\e[0m        (MEMC can not read [0x108000,0x700000] region)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set 0x108000,0x700000 ip:MEMC(r) mode:2\" > /sys/mt/cntl\e[0m (only MEMC can read [0x108000,0x700000] region)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set 0x108000,0x700000 ip:MEMC(r) mem:1\" > /sys/mt/cntl\e[0m  (use mt entry1 set MEMC)\n", " ");
        
        len += dbg_help_printf(buf, ofst, "%20s -full cmd: set <start>,<end> [ip: ... ] [mode: ... ] [type: ... ] [mem: ... ]\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set  0x108000,0x700000 ip:SB2_ACPU,SB2_ACPU2(rw),SB2_VCPU2(r) mode:1 type:sb mem:0\" > /sys/mt/cntl\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s \e[1;34munset DCMT\e[0m      -cmd: unset mem<region_number>\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"unset mem2\">/sys/mt/cntl\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s current setting -cmd: cat /sys/mt/cntl\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s show module     -cmd: cat /sys/mt/modules\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s trap warning    -enable/disable kernel trap warning when mt interrupt occurs\n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd:\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s echo \"set kernel_trap_warning=0\"> /sys/mt/cntl (silence, don't display any message)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s echo \"set kernel_trap_warning=1\"> /sys/mt/cntl (simple, only dump key message ,won't stop kernel)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s echo \"set kernel_trap_warning=2\"> /sys/mt/cntl (print, dump module, command & trap informtaion, won't stop kernel)\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s echo \"set kernel_trap_warning=3\"> /sys/mt/cntl (panic, dump module, command information, stop the kernel immediately)\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s routen          -toggle avk interrupt routing\n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd: echo routen > /sys/mt/cntl\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s dcmt test       -test DCMT monitor is work\n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd1: echo \"mdtest <dst> <src> <len>\" > /sys/mt/cntl\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s step1: echo \"set 0x1f0000,0x200000\" > /sys/mt/cntl\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s step2: echo \"mdtest 200000 300000 100000\">/sys/mt/cntl     (copy 1M data from 0x300000 to 0x200000)\n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd2: echo test>/sys/mt/cntl\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s callback        -test func is registered or not \n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd: echo \"callback module_name,addr,r/w\"> /sys/mt/cntl\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s module_name:all module name in rtk_dc_mt.c module_info[] array. addr: trash address. r/w: read/write\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: echo \"callback TVSB2_DIW,1e0e0000,r\"> /sys/mt/cntl\n", " ");

        
        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mdumpreg\e[0m         -dump dcmt relate register\n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd: echo dumpreg DCU_id-mem_id> /sys/mt/cntl\n", " ");  
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho dumpreg > /sys/mt/cntl\e[0m\n", " ");    
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho dumpreg 0-1 > /sys/mt/cntl\e[0m\n", " ");    

        len += dbg_help_printf(buf, ofst, "%4s search          -show dcmt module key table\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: echo search > /sys/mt/cntl\n", " ");    
        len += dbg_help_printf(buf, ofst, "%24s exp: echo search AUDIO> /sys/mt/cntl\n", " ");    //

        len += dbg_help_printf(buf, ofst, "%4s carvedout       -monitor assigned carvedout mem\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: echo carvedout  > /sys/mt/cntl\n", " "); 
        len += dbg_help_printf(buf, ofst, "%24s exp: echo \"carvedout logbuf\"  > /sys/mt/cntl\n", " "); 
        
        return len;
}
int dbg_help_show_dcmt(char __user * buf, loff_t *ofst)
{
        int len=0;
        int sub_opt_set = 0;  //0: dump all

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mDCMT:\e[0m\n");
        
        if(p_dcmt_sub_opt == NULL){
                //dump all dcmt sub
                len += dbg_help_show_dcmt_rtd_tool(buf, ofst);
                len += dbg_help_show_dcmt_shell_cmd(buf, ofst);
                goto RET;
        }

        if(*(p_dcmt_sub_opt+DCMT_RTD_TOOL)){
                sub_opt_set = 1;
                len += dbg_help_show_dcmt_rtd_tool(buf, ofst);

        }
        
        if(*(p_dcmt_sub_opt+DCMT_SHELL_CMD)){
                sub_opt_set =1;
                len += dbg_help_show_dcmt_shell_cmd(buf, ofst);

        }

        if(sub_opt_set == 0){
                len += dbg_help_show_dcmt_rtd_tool(buf, ofst);
                len += dbg_help_show_dcmt_shell_cmd(buf, ofst);
        }
RET:                
        return len;
        
}


int dbg_help_show_sb2_rtd_tool(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nRTD_TOOL:\n");
        len += dbg_help_printf(buf, ofst, "%4s rtd hw_monitor  -easy set. hw monitor triad func enter commad, set by tips\n"," ");
        len += dbg_help_printf(buf, ofst, "%4s rtd sb2         -sb2 rtd debug enter command\n"," ");

        return len;
}

int dbg_help_show_sb2_shell_cmd(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nSHELL CMD:\n");
        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mset SB2\e[0m         -cmd: set{1-16} monitor {cpu_type1,cpu_type2,...} start_addr-end_addr rw/r/w\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s selectable cpu type:{acpu/vcpu/scpu/vcpu2/kcpu/acpu2};\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set7 monitor scpu,acpu 18062200-180622a0 rw\">/sys/realtek_boards/sb2_dbg\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s \e[1;34munset SB2\e[0m       -cmd: set{1-16} clear\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: \e[1;34mecho \"set7 clear\">/sys/realtek_boards/sb2_dbg\e[0m\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s show setting    -cmd: cat /sys/realtek_boards/sb2_dbg\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s hack            -force enable/disalbe all cpus interrupt: set{1-8} hack_on/hack_off\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: echo \"set1 hack_on\">/sys/realtek_boards/sb2_dbg\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: echo \"set1 hack_off\">/sys/realtek_boards/sb2_dbg\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s callback        -test func is registered or not \n", " ");
        len += dbg_help_printf(buf, ofst, "%20s -cmd: echo \"callback module_name,addr,r/w\"> /sys/realtek_boards/sb2_dbg\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s module_name:all module name in rtk_sb2.c module_sb2_info[] array. addr: trash address. r/w: read/write\n", " ");
        len += dbg_help_printf(buf, ofst, "%24s exp: echo \"callback ST PERI,18061900\" > /sys/realtek_boards/sb2_dbg\n", " ");

        return len;
}

int dbg_help_show_sb2(char __user * buf, loff_t *ofst)
{
        int len=0;
        int sub_opt_set = 0;  //0: dump all

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mSB2\e[0m\n");
        
        if(p_sb2_sub_opt == NULL){
                goto show_all_sub;
        }

        if(*(p_sb2_sub_opt+SB2_RTD_TOOL)){
                sub_opt_set = 1;
                len += dbg_help_show_sb2_rtd_tool(buf, ofst);

        }
        
        if(*(p_sb2_sub_opt+SB2_SHELL_CMD)){
                sub_opt_set =1;
                len += dbg_help_show_sb2_shell_cmd(buf, ofst);

        }

        if(sub_opt_set == 0){
show_all_sub:                
                len += dbg_help_show_sb2_rtd_tool(buf, ofst);
                len += dbg_help_show_sb2_shell_cmd(buf, ofst);
        }
               
        return len;
        
}


int dbg_help_show_arm_wrapper_rtd_tool(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nRTD_TOOL:\n");
        len += dbg_help_printf(buf, ofst, "%4s rtd hw_monitor  -easy set. hw monitor triad func enter commad, set by tips\n"," ");
        len += dbg_help_printf(buf, ofst, "%4s rtd arm_wraper  -arm wrapper rtd debug enter command\n", " ");

        return len;
}

int dbg_help_show_arm_wrapper_shell_cmd(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nSHELL CMD:\n");
        len += dbg_help_printf(buf, ofst, "%4s set          -cmd: set{1-4} start_addr-end_addr r/w\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s exp: \e[1;34mecho \"set2 0x00cd2d00-0x00cd2d40 rw\" > /sys/realtek_boards/arm_wrapper\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s unset        -cmd: set{1-4} clear\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s exp: \e[1;34mecho \"set2 clear\" > /sys/realtek_boards/arm_wrapper\e[0m\n", " ");

        return len;
}
int dbg_help_show_arm_wrapper(char __user * buf, loff_t *ofst)
{
        int len=0;
        int sub_opt_set = 0;  //0: dump all

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mARM_WRAPPER\e[0m\n");
        
        if(p_arm_wrapper_sub_opt == NULL){
                goto show_all_sub;
        }

        if(*(p_arm_wrapper_sub_opt+SB2_RTD_TOOL)){
                sub_opt_set = 1;
                len += dbg_help_show_arm_wrapper_rtd_tool(buf, ofst);

        }
        
        if(*(p_arm_wrapper_sub_opt+SB2_SHELL_CMD)){
                sub_opt_set =1;
                len += dbg_help_show_arm_wrapper_shell_cmd(buf, ofst);

        }

        if(sub_opt_set == 0){
show_all_sub:                
                len += dbg_help_show_arm_wrapper_rtd_tool(buf, ofst);
                len += dbg_help_show_arm_wrapper_shell_cmd(buf, ofst);
        }
               
        return len;
        
}


int dbg_help_show_usbdump_kernel(char __user * buf, loff_t *ofst)
{
        int len = 0;
        
        len += dbg_help_printf(buf, ofst, "\nusbdump SOP:\n");
        len += dbg_help_printf(buf, ofst, "%4s 1. download usbdump.tar from link: http://172.21.15.130/rt_wiki/index.php/File:Usbdump.tar\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 2. untar usbdump.tar to u disk root dirctory\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 3. insert U disk, wait 3-5 mins\n", " ");

        return len;
}

int dbg_help_show_usbdump_ap(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nusb log dump SOP:\n");
        len += dbg_help_printf(buf, ofst, "%4s 1. create rtklog_usb directory in usb root\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 2. insert U disk\n", " ");
        
        return len;        
}

int dbg_help_show_usbdump(char __user * buf, loff_t *ofst)
{
        int len=0;

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mUSBDUMP\e[0m\n");
        len += dbg_help_show_usbdump_kernel(buf, ofst);
        len += dbg_help_show_usbdump_ap(buf, ofst);
        
        return len;
}
int dbg_help_show_logbuf_rtd_tool(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nRTD_TOOL:\n");
        len += dbg_help_printf(buf, ofst, "%4s cmd: rtd logbuf cpu_type on/off loglevel\n", " ");
        len += dbg_help_printf(buf, ofst, "%9s -selectable cpu_type:acpu1,acpu2,vcpu1,vcpu2,acpu(acpu1,acpu2),vcpu(vcpu1,vcpu2),avcpu(all)\n", " ");
        len += dbg_help_printf(buf, ofst, "%9s -leglevel: level under loglevel, display log.(just for on, not necessary) \n", " ");
        len += dbg_help_printf(buf, ofst, "%13s exp: rtd logbuf vcpu on\n", " ");
         
        return len;
}
int dbg_help_show_logbuf_boot_cmd(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nBOOT_CMD:\n");
        len += dbg_help_printf(buf, ofst, "%4s logbuf logswi value                -hex value. must 8bit and except 0x, default value is 8000ff60.\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf bufsize value               -set logbuf ring buffer size, selectable value 512K, 1M, 2M, 4M, default value is 512K.\n", " ");
        len += dbg_help_printf(buf, ofst, "%40s exp:logbuf bufsize 2M\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf logdir value                -set logfile path, value path must contain '/' except for 'USB', default value is/tmp/var/log/\n", " ");
        len += dbg_help_printf(buf, ofst, "%40s exp:logbuf logdir /tmp/var/\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf logfile value               -hex value. must 8bit and except 0x, default value is 9000aaaa.\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf logfile on/off              -enable rtd_logfile.log or not, selectable value on/off.\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf logfile all filesize value  -set rtd_logfile.log file size, selectable value *k , *M ,0 (infinite filesize).\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf logfile all av_inside value -rtd_logfile.log contain av log or not, selectable value on/off.\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf cpu_type value              -show console log or not, selectable value: on/off\n", " ");
        len += dbg_help_printf(buf, ofst, "%40s exp:\e[1;34mlogbuf acpu on\e[0m (show acpu1&acpu2 console log)\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s logbuf cpu_type wrap value         -set log is wrap or not, selectable value: on/off.\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf cpu_type header value       -set log header is long or short,  selectable value: short/long.\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s logbuf cpu_type filesize value     -set logfile filesize, selectable value: *k,*K,*m,*M ,0 (infinite filesize).\n", " ");
        len += dbg_help_printf(buf, ofst, "%40s -cpu_type:selectable value apcu1,acpu2,acpu,vcpu1,vcpu2,vcpu avcpu\n", " ");

        return len;
}

int dbg_help_show_logbuf_shell_cmd(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nSHELL_CMD:\n");
        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mset logfilter\e[0m    -modify the log filter setting\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: set buf_1,buf_2,... core:-- mod:-- lv:--\n", " ");
        len += dbg_help_printf(buf, ofst, "%22s selectale buf: all,acpu1,acpu2,vcpu1,vcpu2,kcpu1,s-ker,s-hal\n", " ");
        len += dbg_help_printf(buf, ofst, "%22s core: core mask by bit. mod:module mask by bit\n", " ");
        len += dbg_help_printf(buf, ofst, "%22s lv:log level(including the setting level will output to log-file)\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: \e[1;34mecho \"set acpu1,kcpu1 core:0 mod:0 lv:5\" > /sys/realtek_boards/rtdlog\e[0m\n", " ");
        
        len += dbg_help_printf(buf, ofst, "%4s \e[1;34munset logfilter\e[0m  -prevent the log which come from specified logbuf to input in log-file\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: unset buf_1,buf_2,...\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: \e[1;34mecho \"unset acpu1,kcpu1\" > /sys/realtek_boards/rtdlog\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mdump\e[0m             -dump log-data to rtd_logbuf.bin\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s -exp: \e[1;34mecho dump > /dev/rtd-logger\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mmsgon\e[0m            -kernel print other fw log\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: msgon buf_1,buf_2,...\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: \e[1;34mecho msgon acpu1,vcpu1 > /sys/realtek_boards/rtdlog\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s \e[1;34mmsgoff\e[0m           -kernel not print other fw log\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: msgoff buf_1,buf_2,..\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: \e[1;34mecho msgoff acpu1,vcpu1 > /sys/realtek_boards/rtdlog\e[0m\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s debug info       -show debug info\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: dbg buf_1,buf_2,...\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: echo \"dbg acpu1,kcpu1\" > /sys/realtek_boards/rtdlog\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: echo \"dbg all\" > /sys/realtek_boards/rtdlog\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s block            -block/unblock RtdLogReader Thread\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s -exp: echo block > /sys/realtek_boards/rtdlog\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s logcat           -cat log in rtd logbuf\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: cat /dev/rtd-logger\n", " ");


        len += dbg_help_printf(buf, ofst, "%4s set catfilter    -set the log-cat filter setting\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: cat buf_1,buf_2,...\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: echo \"cat acpu1,kcpu1\" > /sys/realtek_boards/rtdlog\n", " ");
        
        len += dbg_help_printf(buf, ofst, "%4s unset catfilter  -unset the log-cat filter setting\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: uncat buf_1,buf_2,...\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: echo \"uncat acpu1,kcpu1\" > /sys/realtek_boards/rtdlog\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s file             -toggle log-file write enable/disable\n", " ");
        len += dbg_help_printf(buf, ofst, "%21s -cmd: echo file > /sys/realtek_boards/rtdlog\n", " ");

        len += dbg_help_printf(buf, ofst, "%4s unmask level     -loglevel <= this level,ignore buf_mask ,put into file/display\n", " ");
        len += dbg_help_printf(buf, ofst, "%25s exp: echo unmask 3 > /sys/realtek_boards/rtdlog\n", " ");

        return len;
}

int dbg_help_show_logbuf_offline_win(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nOffline tool(win) SOP:\n");
        len += dbg_help_printf(buf, ofst, "%4s 1. open windows cmd\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 2. cd in parse.exe directory\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 3. cmd: parse.exe input.bin output.log \n", " ");
        return len;        
}

int dbg_help_show_logbuf_offline_linux(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "\nOffline tool(linux) SOP:\n");
        len += dbg_help_printf(buf, ofst, "%4s 1. download parse tool. link: http://172.21.15.130/rt_wiki/images/2/20/Parse_logbuf_v05.tar\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 2. dump logbuf data, copy to parse tool directory\n", " ");
        len += dbg_help_printf(buf, ofst, "%4s 3. cmd: ./parse input_data_file output_log_file\n", " ");

        return len;        
}

int dbg_help_show_logbuf(char __user * buf, loff_t *ofst)
{
        int len=0;
        int sub_opt_set = 0;  //0: dump all

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mLOGBUF\e[0m\n");
        
        if(p_logbuf_sub_opt == NULL){
                goto show_all_sub;
        }

        if(*(p_logbuf_sub_opt+LOGBUF_RTD_TOOL)){
                sub_opt_set = 1;
                len += dbg_help_show_logbuf_rtd_tool(buf, ofst);

        }
        
        if(*(p_logbuf_sub_opt+LOGBUF_BOOT_CMD)){
                sub_opt_set =1;
                len += dbg_help_show_logbuf_boot_cmd(buf, ofst);

        }

        if(*(p_logbuf_sub_opt+LOGBUF_SHELL_CMD)){
                sub_opt_set =1;
                len += dbg_help_show_logbuf_shell_cmd(buf, ofst);

        }

        if(*(p_logbuf_sub_opt+LOGBUF_OFFLINE_TOOL)){
                sub_opt_set =1;
                len += dbg_help_show_logbuf_offline_win(buf, ofst);
                len += dbg_help_show_logbuf_offline_linux(buf, ofst);

        }
        
        if(sub_opt_set == 0){
show_all_sub:                
                len += dbg_help_show_logbuf_rtd_tool(buf, ofst);
                len += dbg_help_show_logbuf_boot_cmd(buf, ofst);
                len += dbg_help_show_logbuf_shell_cmd(buf, ofst);
                len += dbg_help_show_logbuf_offline_win(buf, ofst);
                len += dbg_help_show_logbuf_offline_linux(buf, ofst);
        }
               
        return len;
        
}

int dbg_help_show_rtd_tool_triad(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "triad       -integrate DCMT,SB2,ARM_WRAPPER set\n");
        len += dbg_help_printf(buf, ofst, "%11s -cmd: rtd hw_monitor\n", " ");

        return len;
}
int dbg_help_show_rtd_tool_dcmt(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "dcmt        -interactive cmd for setting DCMT\n");
        len += dbg_help_printf(buf, ofst, "%11s -cmd: rtd dcmt\n", " ");
        
        return len;
}
int dbg_help_show_rtd_tool_sb2(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "sb2         -interactive cmd for setting SB2\n");
        len += dbg_help_printf(buf, ofst, "%11s -cmd: rtd sb2\n", " ");

        return len;
}

int dbg_help_show_rtd_tool_arm_wrapper(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "arm_wrapper -interactive cmd for setting DCMT\n");
        len += dbg_help_printf(buf, ofst, "%11s -cmd: rtd arm_wraper\n", " ");    

        return len;
}

int dbg_help_show_rtd_tool_logbuf(char __user * buf, loff_t *ofst)
{
        int len = 0;

        len += dbg_help_printf(buf, ofst, "logbuf      -control a/v cpu console log on/off\n");
        len += dbg_help_printf(buf, ofst, "%11s -cmd: rtd logbuf cpu_type on/off loglevel\n", " ");
        len += dbg_help_printf(buf, ofst, "%12s selectable cpu_type:acpu1,acpu2,vcpu1,vcpu2,acpu(acpu1,acpu2),vcpu(vcpu1,vcpu2),avcpu(all)\n", " ");
        len += dbg_help_printf(buf, ofst, "%12s leglevel: display log under loglevel.(just for on, not necessary)\n", " ");   
        len += dbg_help_printf(buf, ofst, "%15s exp: rtd logbuf vcpu on\n", " ");
        len += dbg_help_printf(buf, ofst, "%15s exp: rtd logbuf vcpu off\n", " ");
        return len;
}


int dbg_help_show_rtd_tool(char __user * buf, loff_t *ofst)
{
        int len=0;
        int sub_opt_set = 0;  //0: dump all

        len += dbg_help_printf(buf, ofst, "\n\e[1;33mRTD TOOL:\e[0m\n");
        
        if(p_rtd_tool_sub_opt == NULL){
                goto show_all_sub;
        }

        if(*(p_rtd_tool_sub_opt+RTD_TOOL_TRIAD)){
                sub_opt_set = 1;
                len += dbg_help_show_rtd_tool_triad(buf, ofst);

        }
        
        if(*(p_rtd_tool_sub_opt+RTD_TOOL_DCMT)){
                sub_opt_set =1;
                len += dbg_help_show_rtd_tool_dcmt(buf, ofst);

        }

        if(*(p_rtd_tool_sub_opt+RTD_TOOL_SB2)){
                sub_opt_set =1;
                len += dbg_help_show_rtd_tool_sb2(buf, ofst);

        }

        if(*(p_rtd_tool_sub_opt+RTD_TOOL_ARM_WRAPPER)){
                sub_opt_set =1;
                len += dbg_help_show_rtd_tool_arm_wrapper(buf, ofst);

        }

        if(*(p_rtd_tool_sub_opt+RTD_TOOL_LOGBUF)){
                sub_opt_set =1;
                len += dbg_help_show_rtd_tool_logbuf(buf, ofst);

        }

        if(sub_opt_set == 0){
show_all_sub:                
                len += dbg_help_show_rtd_tool_triad(buf, ofst);
                len += dbg_help_show_rtd_tool_dcmt(buf, ofst);
                len += dbg_help_show_rtd_tool_sb2(buf, ofst);
                len += dbg_help_show_rtd_tool_arm_wrapper(buf, ofst);
                len += dbg_help_show_rtd_tool_logbuf(buf, ofst);
        }
               
        return len;
}

int dbg_help_show_all(char __user * buf, loff_t *ofst)
{
        int ret_len = 0;

        ret_len += dbg_help_usage(buf, ofst);
        ret_len += dbg_help_show_dcmt(buf, ofst);
        ret_len += dbg_help_show_sb2(buf, ofst);
        ret_len += dbg_help_show_arm_wrapper(buf, ofst);
        ret_len += dbg_help_show_usbdump(buf, ofst);
        ret_len += dbg_help_show_logbuf(buf, ofst);
        ret_len += dbg_help_show_rtd_tool(buf, ofst);

        return ret_len;
}

int dbg_help_get_info (char __user * buf, loff_t *ofst, MAIN_OPT opt)
{
        int len=0;        

        switch(opt){
                case DCMT:
                        len += dbg_help_show_dcmt(buf, ofst);
                        break;
                        
                case SB2:
                        len += dbg_help_show_sb2(buf, ofst);
                        break;

                case ARM_WRAPPER:
                        len += dbg_help_show_arm_wrapper(buf, ofst);
                        break;

                case USBDUMP:
                        len += dbg_help_show_usbdump(buf, ofst);
                        break;
                        
                case LOGBUF:
                        len += dbg_help_show_logbuf(buf, ofst);
                        break;
                        
                case RTD_TOOL:
                        len += dbg_help_show_rtd_tool(buf, ofst);
                        break;
                        
                 case ALL:
                        len += dbg_help_show_all(buf, ofst);
                        break;
                        
                case HELP:
                        len += dbg_help_usage(buf, ofst);
                        break;
                        
                default:
                        break;
                        
        }
        return len;   
}

int dbg_help_get (char __user * buf, loff_t *ofst)
{
        int ret_len = 0;
        MAIN_OPT opt_main;

        if(p_main_opt == NULL){
                goto show_all_operation;
        }

        for(opt_main=0; opt_main<OPT_MAX_NUM; opt_main++){
                if(*(p_main_opt+opt_main)){
                        //rtd_printk( KERN_ERR, DBG_HELP_TAG, "p_main_opt[%d]=%d\n", opt_main, *(p_main_opt+opt_main));
                        return dbg_help_get_info(buf, ofst, opt_main);
                }
        }


show_all_operation:
        ret_len += dbg_help_show_all(buf, ofst);
        
        return ret_len;
}

void dbg_help_set (const char *buffer)
{
        char * argv[10];
        int arg_num = split_str((char*)buffer, 10, argv, CHAR_SPACE);

        if(arg_num <=0){
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "have not arg, num=%d\n", arg_num);
                return;
        }

        dbg_help_clear_flags();
        if(dbg_help_kmalloc(&p_main_opt, OPT_MAX_NUM)){
                return;
        }

        //dcmt
        if(strncasecmp(argv[0],HELP_MAIN_DCMT, sizeof(HELP_MAIN_DCMT)-1) == 0){
                *(p_main_opt+DCMT) = 1;
                dbg_help_set_dcmt(argv, arg_num);

        //sb2               
        }else if(strncasecmp(argv[0],HELP_MAIN_SB2, sizeof(HELP_MAIN_SB2)-1) == 0){
                *(p_main_opt+SB2) = 1;
                dbg_help_set_sb2(argv, arg_num);

        //arm_wrapper                
        }else if(strncasecmp(argv[0],HELP_MAIN_ARM_WRAPPER, sizeof(HELP_MAIN_ARM_WRAPPER)-1) == 0){
                //rtd_printk( KERN_ERR, DBG_HELP_TAG, "main arm_wrapper opt=%s\n", argv[0]);
                *(p_main_opt+ARM_WRAPPER) = 1;
                dbg_help_set_arm_wrapper(argv, arg_num);

        //usbdump
        }else if(strncasecmp(argv[0],HELP_MAIN_USBDUMP, sizeof(HELP_MAIN_USBDUMP)-1) == 0){
                //rtd_printk( KERN_ERR, DBG_HELP_TAG, "main usbdump opt=%s\n", argv[0]);
                *(p_main_opt+USBDUMP) = 1;
                dbg_help_set_usbdump(argv, arg_num);

        //logbuf
        }else if(strncasecmp(argv[0],HELP_MAIN_LOGBUF, sizeof(HELP_MAIN_LOGBUF)-1) == 0){
                //rtd_printk( KERN_ERR, DBG_HELP_TAG, "main logbuf opt=%s\n", argv[0]);
                *(p_main_opt+LOGBUF) = 1;
                dbg_help_set_logbuf(argv, arg_num);

        //rtd_tool
        }else if(strncasecmp(argv[0],HELP_MAIN_RTD_TOOL, sizeof(HELP_MAIN_RTD_TOOL)-1) == 0){
                //rtd_printk( KERN_ERR, DBG_HELP_TAG, "main rtd_tool opt=%s\n", argv[0]);
                *(p_main_opt+RTD_TOOL) = 1;
                dbg_help_set_rtd_tool(argv, arg_num);

        }else if(strncasecmp(argv[0],HELP_MAIN_ALL, sizeof(HELP_MAIN_ALL)-1) == 0){
                //rtd_printk( KERN_ERR, DBG_HELP_TAG, "main rtd_tool opt=%s\n", argv[0]);
                *(p_main_opt+ALL) = 1;
                dbg_help_set_rtd_tool(argv, arg_num);

        }else if(strncasecmp(argv[0],HELP_MAIN_HELP, sizeof(HELP_MAIN_HELP)-1) == 0){
                //rtd_printk( KERN_ERR, DBG_HELP_TAG, "main rtd_tool opt=%s\n", argv[0]);
                *(p_main_opt+HELP) = 1;
                dbg_help_set_rtd_tool(argv, arg_num);        

        }else{
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "unknown main opt=%s\n", argv[0]);     
                return;
        }

        return;
}


/////************************module init***********************************///
long dbg_help_ioctl(struct file             *filp,
        unsigned int            cmd,
        unsigned long           arg)
{
        rtd_printk( KERN_WARNING, DBG_HELP_TAG, "ioctl device node\n");
        return 0;
}

int dbg_help_open(struct inode* inode, struct file* filp)
{
        rtd_printk( KERN_WARNING, DBG_HELP_TAG, "open device node\n");
        return 0;
}

int dbg_help_release(struct inode* inode, struct file* filp)
{
        rtd_printk( KERN_WARNING, DBG_HELP_TAG, "release device node\n");
        return 0;
}

ssize_t dbg_help_read(struct file *file, char __user *buff, size_t size, loff_t *ofst)
{
        int len;

        len = dbg_help_get(buff, ofst);

        if(*ofst > len){
                return 0;
        }else{
                return len;
        }
     
}

ssize_t dbg_help_write(struct file *file,const char __user *buff, size_t size, loff_t *ofst)
{
        char str[DBG_BUF_SIZE];

        if(size >= DBG_BUF_SIZE){
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "input len beyond bufsize\n");
                goto ret;
        }

        memset(str, 0, sizeof(str));
        if(copy_from_user(str, buff, size) !=0){
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "copy from user error\n");
                goto ret;
        }

        dbg_help_set(str);
ret:
        return size;
}


////**************************create device node****************************////
struct file_operations dbg_help_fops = {
        .owner = THIS_MODULE,
        .unlocked_ioctl = dbg_help_ioctl,
        .open           = dbg_help_open,
        .release        = dbg_help_release,
        .read           = dbg_help_read,
        .write          = dbg_help_write,
};

#define DBG_HELP_DEV_MAJOR 280
#define DBG_HELP_DEV_MINOR 0

#define DBG_HLEP_DEV_NAME "dbg_help"

int dbg_help_major = DBG_HELP_DEV_MAJOR;
int dbg_help_minor = DBG_HELP_DEV_MINOR;


struct dbg_help_dev {
        struct semaphore sem;     /* mutual exclusion semaphore     */
        struct cdev cdev;   /* Char device structure          */
};

static struct class *dbg_help_class;
static struct dbg_help_dev *dbg_help_drv_dev;   

static int __init dbg_help_module(void)
{
        int result;
        dev_t dev = 0;
        
        /*
         * Get a range of minor numbers to work with, asking for a dynamic
         * major unless directed otherwise at load time.
         */

        rtd_printk( KERN_WARNING, DBG_HELP_TAG, " ***************** dbg_help  init module ********************* \n");

        if (dbg_help_major) {
                dev = MKDEV(dbg_help_major, dbg_help_minor);
                result = register_chrdev_region(dev, 1, DBG_HLEP_DEV_NAME);
        } else {
                result = alloc_chrdev_region(&dev, dbg_help_minor, 1, DBG_HLEP_DEV_NAME);
                dbg_help_major = MAJOR(dev);
        }

        if (result < 0) {
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "dbg_help: can't get major %d\n", dbg_help_major);
                return result;
        }

        rtd_printk( KERN_WARNING, DBG_HELP_TAG, "dbg_help: get result:%d,get dev:0x%08x,major:%d\n", result, dev, dbg_help_major);

        dbg_help_class = class_create(THIS_MODULE, DBG_HLEP_DEV_NAME);
        
        if (IS_ERR(dbg_help_class))
                return PTR_ERR(dbg_help_class);
        
        device_create(dbg_help_class, NULL, dev, NULL, DBG_HLEP_DEV_NAME);

        /*
         * allocate the devices
         */
        dbg_help_drv_dev = kmalloc(sizeof(struct dbg_help_dev), GFP_KERNEL);
        if (!dbg_help_drv_dev) {
                device_destroy(dbg_help_class, dev);
                result = -ENOMEM;
                goto fail;  /* Make this more graceful */
        }
        memset(dbg_help_drv_dev, 0, sizeof(struct dbg_help_dev));

        //initialize device structure
        sema_init(&dbg_help_drv_dev->sem, 1);
        cdev_init(&dbg_help_drv_dev->cdev, &dbg_help_fops);
        dbg_help_drv_dev->cdev.owner = THIS_MODULE;
        dbg_help_drv_dev->cdev.ops = &dbg_help_fops;
        result = cdev_add(&dbg_help_drv_dev->cdev, dev, 1);
        /* Fail gracefully if need be */
        if (result) {
                device_destroy(dbg_help_class, dev);
                kfree(dbg_help_drv_dev);
                rtd_printk( KERN_ERR, DBG_HELP_TAG, "Error %d adding cdev rtdlog", result);
                goto fail;
        }

        return 0; /* succeed */

fail:
        return result;
        
}

static void __exit dbg_help_cleanup_module(void)
{
        int i = 0;
        dev_t dev = MKDEV(dbg_help_major, dbg_help_minor);

        rtd_printk( KERN_WARNING, DBG_HELP_TAG, "hw monitor clean module\n");

        /* Get rid of our char dev entries */
        if (dbg_help_drv_dev) {
                device_destroy(dbg_help_class, dev);
                cdev_del(&dbg_help_drv_dev[i].cdev);
                kfree(dbg_help_drv_dev);
        }

        unregister_chrdev_region(dev, 1);
}

module_init(dbg_help_module);
module_exit(dbg_help_cleanup_module);
