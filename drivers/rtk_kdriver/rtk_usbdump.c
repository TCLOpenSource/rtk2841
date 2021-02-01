/******************************************************************************
 *
 *   Realtek kernel driver
 *
 *   Copyright(c) 2014 Realtek Semiconductor Corp. All rights reserved.
 *
 *   @author liangliang_song mail:liangliang_song@apowertec.com
 *
 *****************************************************************************/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/net.h>
#include <linux/in.h>
#include <linux/types.h>
#include <linux/kthread.h>
#include <linux/skbuff.h>
#include <linux/string.h>
#include <linux/sysctl.h>
#include <linux/netfilter.h>
#include <linux/netfilter_ipv4.h>
#include <linux/workqueue.h>
#include <linux/stddef.h>
#include <net/net_namespace.h>
#include <net/sock.h>
#include <net/request_sock.h>
#include <linux/syscalls.h>
#include <mach/rtk_log.h>
#include <linux/fs.h>

#undef TAG_NAME
#define TAG_NAME "USBDUMP"
#ifdef USBDUMP_DBG_EN
#define USBDUMP_DBG(fmt, args...)            rtd_printk(KERN_DEBUG, TAG_NAME,"[DBG] " fmt, ## args)
#else
#define USBDUMP_DBG(fmt, args...)
#endif

#define USBDUMP_PRINT(fmt, args...)     rtd_printk(KERN_INFO , TAG_NAME,  fmt, ## args)
#define USBDUMP_INFO(fmt, args...)              rtd_printk(KERN_INFO , TAG_NAME,  "[Info] " fmt, ## args)
#define USBDUMP_WARNING(fmt, args...)   rtd_printk( KERN_WARNING , TAG_NAME, "[Warn] " fmt, ## args)
#define USBDUMP_ERR(fmt, args...)               rtd_printk( KERN_ERR , TAG_NAME, "[Err] " fmt, ## args)

#define NETLINK_RECV_BUF_LEN  1024
static struct task_struct *g_usbdump_task = NULL;
unsigned int cp_total = 0;
unsigned int cp_success = 0;
static char usb_path[256];

typedef struct usb_uevent_capture_info {
        char add_event[256];
        char devname[32];
        char subsystem[32];
        char action[32];
        char mount_path[128];
} STRUCT_UINFO;

enum INFO_CHECK {
        UEVENT_ADD_CHECK = 0,
        UEVENT_ACTION_CHECK,
        UEVENT_SUBSYSTEM_CHECK,
        UEVENT_DEVNAME_CHECK,
};

#define USB_CHECK_ACTION_KEY  "ACTION=%32s"
#define USB_CHECK_ACTION_VAL  "add"
#define USB_CHECK_SUBSYSTEM_KEY  "SUBSYSTEM=%32s"
#define USB_CHECK_SUBSYSTEM_VAL  "block"
#define USB_CHECK_DEVNAME_KEY  "DEVNAME=%5s"
#define USB_CHECK_DEVNAME_VAL  "sd"

#define USB_CHECK_AIM ((1<<UEVENT_ACTION_CHECK)|(1<<UEVENT_SUBSYSTEM_CHECK)|(1<<UEVENT_DEVNAME_CHECK))

static unsigned char usb_check_process;
static unsigned char path_check_flag;


static int check_usbinfo_reset(STRUCT_UINFO * info, char * str)
{
        if(sscanf(str, "add@%256s", info->add_event) > 0) {
                info->devname[0] = '\0';
                info->subsystem[0] = '\0';
                info->action[0] = '\0';
                info->mount_path[0] = '\0';
                usb_check_process = 0;
                path_check_flag = 0;
                return 0;
        }
        return -1;
}

static int check_usbinfo_devname(STRUCT_UINFO * info, char * str)
{
        unsigned char tmp[8] = {0};
        if(sscanf(str, USB_CHECK_DEVNAME_KEY, info->devname) > 0) {
                if(sscanf(info->devname, "sd%2s", tmp) > 0) {
                        usb_check_process |= 1 << UEVENT_DEVNAME_CHECK;
                        return 0;
                }
        }

        return -1;
}

static int check_usbinfo_subsystem(STRUCT_UINFO * info, char * str)
{

        if(sscanf(str, USB_CHECK_SUBSYSTEM_KEY, info->subsystem) > 0) {
                if(!strcmp(USB_CHECK_SUBSYSTEM_VAL, info->subsystem)) {
                        usb_check_process |= 1 << UEVENT_SUBSYSTEM_CHECK;
                        return 0;
                }
        }
        return -1;
}

static int check_usbinfo_action(STRUCT_UINFO * info, char * str)
{
        if(sscanf(str, USB_CHECK_ACTION_KEY, info->action) > 0) {
                if(!strcmp(USB_CHECK_ACTION_VAL, info->action)) {
                        usb_check_process |= 1 << UEVENT_ACTION_CHECK;
                        return 0;
                }
        }
        return -1;
}

static void check_usbinfo(STRUCT_UINFO * info, char * str)
{
        check_usbinfo_reset(info, str);
        check_usbinfo_devname(info, str);
        check_usbinfo_subsystem(info, str);
        check_usbinfo_action(info, str);
}

static inline loff_t file_pos_read(struct file *file)
{
        return file->f_pos;
}

static inline void file_pos_write(struct file *file, loff_t pos)
{
        file->f_pos = pos;
}

static int create_rtdlog_bin(void)
{
        struct file * file = NULL;
        char buff[] = "dump";
        int ret_write = 0;
        mm_segment_t old_fs;
        file = filp_open("sys/realtek_boards/rtdlog", O_RDWR, 0);
        if(IS_ERR(file)) {
                USBDUMP_PRINT("open sys/realtek_boards/rtdlog FAIL! ret=%d\n", IS_ERR(file));
                return -1;
        }
        old_fs = get_fs();
        set_fs(KERNEL_DS);

        loff_t pos = file_pos_read(file);
        ret_write = vfs_write(file, buff, sizeof(buff), &(pos));
        if(ret_write <= 0)
                USBDUMP_PRINT("write dump to  rtdlog FAIL ,ret =%d\n", ret_write);
        set_fs(old_fs);
        filp_close(file, NULL);
        return 0;
}

static int  copy_rtdlog_bin(char * logbuf_bin_path)
{
        int cmd_ret = 0;
        char path_cp[] = "/bin/cp";
        char * argv_cp[] = {path_cp,  "-f", "tmp/var/log/logbuf.bin", NULL, NULL};
        char * cmdEnvp[] = {NULL};

        argv_cp[3] = kmalloc(256, GFP_KERNEL);
        if(argv_cp[3] == NULL) {
                USBDUMP_ERR(KERN_WARNING "malloc argv_cp[3]\n");
                return -1;
        }
        strcpy(argv_cp[3], logbuf_bin_path);
        cp_total = cp_total + 1;
        cmd_ret = call_usermodehelper(path_cp, argv_cp, cmdEnvp, UMH_WAIT_PROC);
        if(cmd_ret != 0)  {
                USBDUMP_PRINT("COPY %s FAIL, ret=%d\n", argv_cp[2], cmd_ret);
        } else {
                //USBDUMP_WARNING("mkdir %s OK, ret=%d\n", argv_cp[2], cmd_ret);
                cp_success = cp_success + 1;
        }
        kfree(argv_cp[3]);
        return 0;
}

static void finish_print(void)
{
        //USBDUMP_PRINT("--------USBDUMP RESULT:\n");
        USBDUMP_PRINT("--------COPY:( %d /%d )-----------\n", cp_success, cp_total);
        USBDUMP_PRINT("--------USBDUMP FINISH!!!-----------\n");
}
static void start_print(void)
{
        USBDUMP_PRINT("--------USBDUMP START!!!----------------\n\n");
}

static int parse_line(char *tmp, char *aim, char *aim_block, char *aim_fuse, char *path)
{
        char *find = NULL;
        int i = 0;
        find = strstr(tmp, aim);
        if(!find) {
                find = strstr(tmp, aim_block);
        }
        if(!find){
                 find = strstr(tmp, aim_fuse);
        }
        if(find) {
                find = strchr(tmp, ' ');
                if(NULL != find) {
                        find++;
                        for(i = 0; *find != ' '; i++) {
                                if(('\0' == *find) ||('\n' == *find))
                                        break;
                                *(path + i) = *find;
                                find++;
                        }
                        //USBDUMP_PRINT("mount path=%s\n", path);
                        return 0;
                }
        }
        return -1;
}

static void init_aim_path(char * aim, char * aim_block,char * aim_fuse, STRUCT_UINFO * info, int buff_size)
{
        strcat(aim, "/dev/");
        strcat(aim, info->devname);
        strcat(aim, " ");

        strcat(aim_block, "/dev/block/");
        strcat(aim_block, info->devname);
        strcat(aim_block, " ");

        strcat(aim_fuse, "/storage/");
        strcat(aim_fuse, info->devname);

}
void handle_err(int error_num, char *filename)
{
       /*  if(error_num == -2)
                USBDUMP_PRINT("file %s not exist!\n",filename);
        else*/
        USBDUMP_PRINT("read %s fail ,ret=%d\n",filename, error_num);

}

static size_t fread(struct file *file, char *addr, unsigned long count, loff_t *offset)
{
        ssize_t result;
        if (count ==0){
                USBDUMP_PRINT("fread argument error count =0\n ");   
                return -1;
        }
        if(IS_ERR(file)) {
                USBDUMP_PRINT("file error retnum=%d\n", IS_ERR(file));
                return -1;
        }
        if(NULL == addr){
                USBDUMP_PRINT("fread addr = NULL\n");
                return -1;
        }
 
        result = vfs_read(file, addr, count, offset);
           
        return result;
}


static char getc(struct file *file, char *filename, loff_t *offset)
{
        int result;
        char ret_char = 0;
                
        result = fread(file,&ret_char, 1, offset);
        if(0 == result)
                ret_char = -1;
        else if(result<0){               
                handle_err(result, filename);
                ret_char = -2;
        }               

        return ret_char;
}

static char *fget_line(struct file *file, char *filename, char *s, int n, loff_t *offset)
{
        int c;
        char *cs=s;
        while(1){
                --n;
                c = getc(file, filename, offset);
                if((n <=0) ||(c <=0) ||(c == '\n') )
                        break;
                *cs++=  c; 
        }
        *cs = '\0';
        
        return ( (c<0) ||(c == 0 && cs == s) )?NULL :s ;
}
static void init_cfg_path(char *tmp_path, char *path, char *rtdlog_path, char *dest)
{
        cp_total = 0;
        cp_success = 0;

        strcat(tmp_path, path);
        strcpy(dest, tmp_path);
        strcat(tmp_path, "/usbdump/");
        strcpy(rtdlog_path, tmp_path);        
        strcat(tmp_path, "usbdump.cfg");
}

static void cfg_read(char * tmp, char * dest)
{
        char * seach = NULL;
        char path_cp[] = "/bin/cp";
        char * argv_cp[] = {path_cp,  "-rf", NULL, dest, NULL};
        char * cmdEnvp[] = {NULL};
        int cmd_ret = -1, IS_fie = 0;

        seach = strchr(tmp, ':');
        cp_total = cp_total + 1;
        if(seach) {
                argv_cp[2] = seach + 1;
                if(tmp[strlen(tmp) - 1] == '/') {
                        IS_fie  = 1;
                } else {
                        IS_fie = 0;
                }
                cmd_ret = call_usermodehelper(path_cp, argv_cp, cmdEnvp, UMH_WAIT_PROC);
                if(cmd_ret < 0)  {
                        USBDUMP_PRINT("COPY %s To %s FAIL!!!!, ret=%d\n", argv_cp[2] , argv_cp[3], cmd_ret);
                } else if(cmd_ret > 0) {
                        if(IS_fie == 1) {
                                USBDUMP_PRINT("COPY %s To %s  FAIL???, ret=%d\n", argv_cp[2] , argv_cp[3], cmd_ret);
                                cp_success = cp_success + 1;
                        } else {
                                USBDUMP_PRINT("COPY %s To %s FAIL!!!!, ret=%d\n", argv_cp[2] , argv_cp[3], cmd_ret);
                        }
                } else {
                        //USBDUMP_WARNING("COPY %s to %s OK, ret=%d\n", argv_cp[2] ,argv_cp[3], cmd_ret);
                        cp_success = cp_success + 1;
                }
        }
}

static void cfg_write(char *dest_w)
{
        char path_rm[] = "/bin/rm";
        char path_mkdir[] = "/bin/mkdir";
        char * argv_rm[] = {path_rm, "-rf" , NULL,  NULL};
        char * argv_mkdir[] = {path_mkdir, NULL , NULL,  NULL};
        char * cmdEnvp[] = {NULL};
        int cmd_ret = -1;

        argv_rm[2] = dest_w;
        argv_mkdir[1] = dest_w;

        cmd_ret = call_usermodehelper(path_rm, argv_rm, cmdEnvp, UMH_WAIT_PROC);
        if(cmd_ret < 0)
                USBDUMP_PRINT("rm %s FAIL, ret=%d\n", argv_rm[2], cmd_ret);

        cmd_ret = call_usermodehelper(path_mkdir, argv_mkdir, cmdEnvp, UMH_WAIT_PROC);
        if(cmd_ret < 0)
                USBDUMP_PRINT("mkdir %s FAIL, ret=%d\n", argv_mkdir[1], cmd_ret);
}


static void cfg_sh(char * tmp, char *dest_w, char *path)
{
        char * seach = NULL;
        char path_bash[] = "/bin/sh";
        char * argv_bash[] = {path_bash, NULL, path, NULL};
        char * cmdEnvp[] = {NULL};
        int cmd_ret = -1;

        seach = strchr(tmp, ':');
        if(seach) {
                strcat(dest_w, path);
                strcat(dest_w, seach + 1);
                argv_bash[1] = dest_w;
                cmd_ret = call_usermodehelper(path_bash, argv_bash, cmdEnvp, UMH_WAIT_EXEC);
                if(cmd_ret != 0)
                        USBDUMP_PRINT("EXECUTE %s FAIL, ret=%d\n", argv_bash[1] , cmd_ret);
        }
}

/*
#Token:'#':comment; 'w':write dir in $(usb_mount_dir)/; 'r':read path in file-system; 's':script path
#example 'w': w:/usbdump/logs/
#example 'r': r:/tmp/var/log/
#example 's': s:/usbdump/usbdump_shell.sh
s:/usbdump/usbdump_shell.sh
*/
static void parse_cfg_line(char * tmp, char * path, char * dest)
{
        char * seach = NULL;
        char dest_w[256] = {'\0'};

        memset(dest_w, '\0', sizeof(dest_w));
        switch(*tmp) {
                case '#':
                        //USBDUMP_PRINT("Parse '#'\n");
                        break;
                case 'r':
                        //USBDUMP_INFO("Parse 'r'\n");
                        cfg_read(tmp, dest);
                        break;
                case 'w':
                        //USBDUMP_PRINT("Parse 'w'\n");
                        seach = strchr(tmp, ':');
                        if(seach) {
                                strcat(dest_w, path);
                                strcat(dest_w, seach + 1);
                                dest_w[sizeof(dest_w) - 1] = '\0';
                                strcpy(dest, dest_w);
                                cfg_write(dest_w);
                        }
                        break;
                case 's':
                        //USBDUMP_PRINT("Parse 's'\n");
                        cfg_sh(tmp, dest_w, path);
                        break;
                default:
                        //USBDUMP_PRINT("Unknown:%s\n", tmp);
                        break;
        }
}

static int rtk_logbuf_use_USB;        //logbuf use USB path, usbdump should be disable.
int rtk_get_usb_path(char *buf)
{
        rtk_logbuf_use_USB = 1;
        if(strlen(usb_path)==0){
                return -1;
        }
        memcpy(buf,usb_path,(strlen(usb_path)+1));
        return 0;
}

/*
/dev/sda1 /tmp/usb/sda/sda1 tfat rw,\
relatime,uid=0,gid=5000,umask=0002,allow_utime=0020,codepage=437,\
iocharset=utf8,shortname=winnt,min_prealloc_size=64k,max_prealloc_size=32M,\
writeback_boundary=4M,readahead=4M,fail_safe,fastmount,hidden=show,errors=continue 0 0
*/
static int cat_proc_mounts(STRUCT_UINFO * info, char * path)
{
        struct file * file = NULL;
        char * buf_file = NULL;
        char aim[256] = {'\0'};
        char aim_block[256] = {'\0'};
        char aim_fuse[256] = {'\0'};
        unsigned int buff_size = 512;
        const char *filepath = "/proc/mounts"; 
        int ret = 0;
        
        file = filp_open(filepath, O_RDONLY, 0);
        if(IS_ERR(file)) {
                USBDUMP_PRINT("open /proc/mounts FAIL! ret=%d\n", IS_ERR(file));
                return -1;
        }
                
        buf_file = kmalloc(buff_size, GFP_KERNEL);          
        if(buf_file == NULL) {
                USBDUMP_ERR(KERN_WARNING "kmalloc buf_file\n");
                ret = -1;
                goto RET; 
        }
        
        path[0] = '\0';
        memset(buf_file, '\0', buff_size);
        init_aim_path(aim, aim_block, aim_fuse, info, buff_size);
        aim[sizeof(aim) - 1] = '\0';
        aim_block[sizeof(aim_block) - 1] = '\0';
        aim_fuse[sizeof(aim_fuse) - 1] = '\0';

        loff_t pos = file_pos_read(file);
        //prase mounts file, find mount path
        while(NULL != fget_line(file, "/proc/mounts" ,buf_file, buff_size,&pos)){
                if(0 == parse_line(buf_file, aim, aim_block,aim_fuse, path)){
                        //memset(usb_path,0, 256);
                        memcpy(usb_path,path,(strlen(path)+1));
                        ret = 0;        
                        goto RET;
                }
                memset(buf_file, '\0', buff_size);
        }
        ret = -1;
        goto RET;

RET:
        kfree(buf_file);
        filp_close(file, NULL);
        return ret;
}


static int parse_cfg(char * path)
{
        struct file *file = NULL;
        char *tmp_path = NULL, *rtdlog_path = NULL;
        char buf[256] = {'\0'};
        char dest[256] = {'\0'};
        int ret;
        
        tmp_path = kmalloc(256, GFP_KERNEL);
        rtdlog_path = kmalloc(256, GFP_KERNEL);
        if((rtdlog_path == NULL) ||(tmp_path == NULL)) {
                USBDUMP_ERR(KERN_WARNING "kmalloc rtdlog_path/tmp_path\n");
                ret = -1;
                goto GO_RET;
        }

        memset(dest, '\0', sizeof(dest));
        init_cfg_path(tmp_path, path, rtdlog_path, dest);
        *(tmp_path + strlen(tmp_path)) = '\0';
        
        file = filp_open(tmp_path, O_RDONLY, 0);
        if(IS_ERR(file)){
                if(IS_ERR(file) == 1)
                        USBDUMP_PRINT("usbdump config file no exist!\n");
                else
                        USBDUMP_PRINT("open %s FAIL! ret=%d\n", tmp_path, IS_ERR(file));
                ret = -1;
                goto GO_RET;
        }
        
        start_print();
        loff_t pos = file_pos_read(file);
        //parse cfg file
        while(NULL != fget_line(file, tmp_path, buf, sizeof(buf),&pos)){
                parse_cfg_line(buf, path, dest); 
                memset(buf, '\0', sizeof(buf));
        }

        filp_close(file, NULL);
        if(0 == create_rtdlog_bin())
                copy_rtdlog_bin(rtdlog_path);
        
        finish_print();         //print result

        ret = 0;
        goto GO_RET;

GO_RET:
        kfree(tmp_path);
        kfree(rtdlog_path);
        return ret;

}

static int test_usbdump(STRUCT_UINFO * info, char * path)
{
        unsigned int i;
        for(i=0;i<10000;i++)
        {
                 if(cat_proc_mounts(info, path) == 0) {
                        //start_print();
                        parse_cfg(path);
                        //finish_print(); //print result
                  }
                 else
                        break;
                 msleep(500);
        }
        return 0;

}
static void sleep_sec(int sec)
{
	int i=0;

	for(i=0; i<sec; i++){
		msleep(1000);
	}

}
static int usbdump_threadfn(void *data)
{
        int ret = -1;
        char *recv_buf = NULL;
        struct socket *sock;
        struct sockaddr_nl nls;
        struct kvec vec;
        struct msghdr msg;
        STRUCT_UINFO usb_info;
        char path[256]  = {'\0'};
        int retry_cnt = 0;

        if (sock_create_kern(&init_net, PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT, &sock) < 0) {
                USBDUMP_ERR("%s create socket failed\n", __FUNCTION__);
                goto CREAT_SOCK_FAIL;
        }

        memset(&nls, 0, sizeof(struct sockaddr_nl));
        nls.nl_family = AF_NETLINK;
        nls.nl_pid = sys_getpid();
        nls.nl_groups = NETLINK_KOBJECT_UEVENT;

        ret = sock->ops->bind(sock, (struct sockaddr *)&nls, sizeof(struct sockaddr_nl));
        if(ret < 0) {
                USBDUMP_ERR("%s bind failed\n", __FUNCTION__);
                goto BIND_SOCK_FAIL;
        }

        recv_buf = kmalloc(NETLINK_RECV_BUF_LEN, GFP_KERNEL);
        if(recv_buf == NULL) {
                USBDUMP_ERR(KERN_WARNING "malloc recv buff\n");
                goto MALLOC_BUFFER_FAIL;
        }
        
        /*
        usb uevent :
        add@/devices/platform/usb/xhci-hcd/usb1/1-2/1-2:1.0/\
        host0/target0:0:0/0:0:0:0/block/sda/sda1ACTION=add\
        DEVPATH=/devices/platform/usb/xhci-hcd/usb1/1-2/1-2:1.0/\
        host0/target0:0:0/0:0:0:0/block/sda/sda1\
        SUBSYSTEM=blockMAJOR=8MINOR=1DEVNAME=sda1
        */
        while (!kthread_should_stop()) {
                /*receive message from client*/
                memset(&vec, 0, sizeof(vec));
                memset(&msg, 0, sizeof(msg));
                memset(recv_buf, 0, NETLINK_RECV_BUF_LEN);
                vec.iov_base = recv_buf;
                vec.iov_len = NETLINK_RECV_BUF_LEN;
                check_usbinfo_reset(&usb_info, "add@null_clear_info");
                ret = kernel_recvmsg(sock, &msg, &vec, 1, NETLINK_RECV_BUF_LEN, 0);
                if(ret > 0) {
                        int i = 0;
                        while (i < ret) {
                                check_usbinfo(&usb_info, recv_buf + i);
                                if((usb_check_process == USB_CHECK_AIM) && (path_check_flag == 0)) {
                                        path_check_flag = 1;
                                        USBDUMP_PRINT("GET USB_UEVENT\n");
                                        for(retry_cnt = 0; retry_cnt < 3; ++retry_cnt) {
                                                //test_usbdump(&usb_info, path);        //for test
                                                if(cat_proc_mounts(&usb_info, path) == 0) {
                                                        if(rtk_logbuf_use_USB){
                                                                sleep_sec(20);
                                                                rtk_logbuf_use_USB = 0; //for next usb plug
                                                        }
                                                        //start_print();
                                                        parse_cfg(path);
                                                        //finish_print(); //print result
                                                        break;
                                                }
                                                sleep_sec(5);           //wait usb mount

                                        }

                                }
                                i += strlen(recv_buf + i) + 1;
                        }
                }
        }
        kfree(recv_buf);
        recv_buf = NULL;

MALLOC_BUFFER_FAIL:
BIND_SOCK_FAIL:
        sock_release(sock);
CREAT_SOCK_FAIL:
        return 0;
}

static int __init usbdump_init(void)
{
        g_usbdump_task = kthread_run(usbdump_threadfn, NULL, "kusbdump");
        if(!g_usbdump_task) {
                USBDUMP_ERR("create kusbdump thread failed\n");
                return -1;
        }
        USBDUMP_PRINT("create kusbdump thread sucess\n");
        return 0;
}

static void __exit usbdump_exit(void)
{
        if(g_usbdump_task) {
                kthread_stop(g_usbdump_task);
                g_usbdump_task = NULL;
        }
}

module_init(usbdump_init);
module_exit(usbdump_exit);
MODULE_LICENSE("GPL");
