#include <linux/kernel.h>
#include <linux/ioport.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/init.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/dma-mapping.h>
#include <linux/miscdevice.h>
#include <linux/platform_device.h>
#include <linux/notifier.h>
#include <linux/list.h>
#include <linux/uaccess.h>
#include <linux/of.h>
#include <mach/platform.h>
#include <asm/mutex.h>
#include "rtk_mcp_dev.h"
#include "rtk_mcp_test.h"
#include "rtk_mcp_reg.h"

#define MCP_DEV_NAME "mcp_core"
#define MCP_PLATDEVICE_NAME "mcp"
static struct kobject*  mcp_kobj;
int DisplayDesc = 0;
int DisplayFIFO = 0;
unsigned long pre_base;
unsigned long pre_limit;
unsigned long pre_rp;
unsigned long pre_wp;

static int mcp_dev_open(struct inode* inode, struct file* file)
{
    return 0;
}

static int mcp_dev_release(struct inode* inode, struct file* file)
{
    return 0;
}

#ifdef CONFIG_COMPAT
long compat_mcp_dev_ioctl(struct file *filp,
                          unsigned int cmd, unsigned long arg)
{
    compat_mcp_desc_set desc_set;

    switch (cmd) {
        case MCP_IOCTL_DO_COMMAND: {
            if (copy_from_user(&desc_set, (mcp_desc_set __user *)arg, sizeof(mcp_desc_set))) {
                mcp_warning("do ioctl command failed - copy desc_set from user failed\n");
                return -EFAULT;
            }
            return mcp_do_command_user(desc_set.p_desc, desc_set.n_desc);
            break;
        }
        /*--- for testing only---*/
        case MCP_IOCTL_TEST_AES_H:
            MCP_AES_H_DataHashTest();
            break;

        default:
            mcp_warning("do ioctl command failed - unknown ioctl command(%d)\n", cmd);
            return -EFAULT;
    }

    return 0;
}
#endif

static ssize_t mcp_dev_write(struct file *file,
                             const char __user *buf, size_t size, loff_t *ofst)
{
    unsigned char buff[512];

    if (size > sizeof(buff) - 1)
        return -1;

    memset(buff, 0, sizeof(buff));
    if(copy_from_user(buff, buf, size)) {
        mcp_warning("do write command failed - copy desc_set from user failed\n");
        return -EFAULT;
    }

    if (strncmp(buff, "do_mcp_burst_test", 17) == 0) {
        int round = 100;
        sscanf(buff, "do_mcp_burst_test=%d", &round);
        do_mcp_burst_test(round);
    } else if (strncmp(buff, "do_mcp_error_test", 17) == 0) {
        int round = 1;
        sscanf(buff, "do_mcp_error_test=%d", &round);
        do_mcp_error_test(round);
    } else if (strncmp(buff, "do_mcp_function_test", 20) == 0) {
        do_mcp_function_test();
    } else if (strncmp(buff, "do_mcp_throughput_test", 22) == 0) {
        int DataSize = 1;
        sscanf(buff, "do_mcp_throughput_test=%d", &DataSize);
        do_mcp_throughput_test(DataSize);
    } else if (strncmp(buff, "set_mcp_print_desc", 18) == 0) {
        sscanf(buff, "set_mcp_print_desc=%d", &DisplayDesc);
    } else if (strncmp(buff, "set_mcp_print_fifo", 18) == 0) {
        sscanf(buff, "set_mcp_print_fifo=%d", &DisplayFIFO);
    } else if (strncmp(buff, "do_help", 7) == 0) {
        do_mcp_help();
    } else {
        mcp_warning("unknow mcp command - %256s\n", buff);
        do_mcp_help();
    }

    return size;
}


static long mcp_dev_ioctl(struct file* file, unsigned int cmd, unsigned long arg)
{
    mcp_desc_set desc_set;
    switch (cmd) {
        case MCP_IOCTL_DO_COMMAND: {
            if (copy_from_user(&desc_set, (mcp_desc_set __user *)arg, sizeof(mcp_desc_set))) {
                mcp_warning("do ioctl command failed - copy desc_set from user failed\n");
                return -EFAULT;
            }
            return mcp_do_command_user(desc_set.p_desc, desc_set.n_desc);
            break;
        }
        /*------for testing only------*/
        case MCP_IOCTL_TEST_AES_H:
            MCP_AES_H_DataHashTest();
            break;

        default:
            mcp_warning("do ioctl command failed - unknown ioctl command(%d)\n", cmd);
            return -EFAULT;
    }

    return 0;
}


static struct file_operations mcp_dev_ops = {
    .owner          = THIS_MODULE,
    .unlocked_ioctl = mcp_dev_ioctl,
#ifdef CONFIG_COMPAT
    .compat_ioctl   = compat_mcp_dev_ioctl,
#endif
    .open           = mcp_dev_open,
    .write          = mcp_dev_write,
    .release        = mcp_dev_release,
};


static struct miscdevice rtk_mcp_miscdev = {
    MISC_DYNAMIC_MINOR,
    MCP_DEV_NAME,
    &mcp_dev_ops,
};

#define MAX_LEN         128
static unsigned char OutData[MAX_LEN];

static int ascii_to_hex(char ch)
{
    int hex_val = -1;

    if ((ch >= '0') && (ch <= '9'))
        hex_val = ch - '0';
    else if ((ch >= 'a') && (ch <= 'f'))
        hex_val = ch - 'a' + 10;
    else if ((ch >= 'A') && (ch <= 'F'))
        hex_val = ch - 'A' + 10;

    return hex_val;
}

static int get_hex_value(char *ch, char *val)
{
    int i = 0, x = 0;
    unsigned char tmp[MAX_LEN];

    while((*(ch + i) != 0x20) && (*(ch + i) != 0x0a) && (i <= 2 * MAX_LEN))
        i++;
    strncpy(tmp, ch, i);
    for(x = 0; x < i / 2; x++) {
        val[x] = (unsigned char)(ascii_to_hex(tmp[x * 2]) << 4 | ascii_to_hex(tmp[x * 2 + 1]));
    }
    return i;
}

static int get_char_value(char *ch, char *val)
{
    int i = 0;
    while((*(ch + i) != 0x20) && (*(ch + i) != 0x0a) && (i <= 2 * MAX_LEN))
        i++;

    strncpy(val, ch, i);
    *(val + i) = '\0';

    return i;
}

static void parser_str(char* buf, unsigned char* data, unsigned char* mode, unsigned int *ende, unsigned char* key, unsigned char* iv)
{
    char *pbuf = buf;
    while(pbuf != NULL) {
        if(strncmp(pbuf, "data=", 5) == 0) {
            pbuf += 5;
            pbuf += get_hex_value(pbuf, data);
        } else if(strncmp(pbuf, "mode=", 5) == 0) {
            pbuf += 5;
            pbuf += get_char_value(pbuf, mode);
        } else if(strncmp(pbuf, "key=", 4) == 0) {
            pbuf += 4;
            pbuf += get_hex_value(pbuf, key);
        } else if(strncmp(pbuf, "iv=", 3) == 0) {
            pbuf += 3;
            pbuf += get_hex_value(pbuf, iv);
        } else if(strncmp(pbuf, "enc=", 4) == 0) {
            pbuf += 4;
            pbuf += get_char_value(pbuf, ende);
            *ende -= '0';
        } else if(*pbuf == 0x0a) {
            break;
        } else {
            pbuf++;
        }
    }
    //mcp_dump_mem(data, 16);
    //mcp_dump_mem(key, 16);
}

static ssize_t mcp_rtssl_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    int i = 0;
    if(OutData != NULL) {
        for (i = 0; i < 16; i++)
            sprintf(buf + strlen(buf), "%02x ", OutData[i]);
        sprintf(buf + strlen(buf), "\n");
        return strlen(buf);
    }
    return sprintf(buf, "Please do the calculate first\n");
}

/*
echo "data=112233445566778899aabbccddeeff00 key=ffffffffffffffffffffffffffffffff enc=1 mode=aes_128_ecb"> /sys/mcp/rtssl
45 d7 4d ac b3 52 f9 3f d3 09 bf 8b 91 59 df 58
echo "data=45d74dacb352f93fd309bf8b9159df58 key=ffffffffffffffffffffffffffffffff enc=0 mode=aes_128_ecb"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
echo "data=112233445566778899aabbccddeeff00 key=ffffffffffffffffffffffffffffffff iv=22222222222222222222222222222222 enc=1 mode=aes_128_cbc"> /sys/mcp/rtssl
9a 6c 86 ce c3 31 dd b0 14 2c fb 37 06 25 bf fe
echo "data=9a6c86cec331ddb0142cfb370625bffe key=ffffffffffffffffffffffffffffffff iv=22222222222222222222222222222222 enc=0 mode=aes_128_cbc"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
echo "data=112233445566778899aabbccddeeff00 key=ffffffffffffffffffffffffffffffff iv=22222222222222222222222222222222 enc=1 mode=aes_128_ctr"> /sys/mcp/rtssl
d7 9d e0 8a be a9 a2 c8 f7 f1 85 c7 72 57 2e b5
echo "data=d79de08abea9a2c8f7f185c772572eb5 key=ffffffffffffffffffffffffffffffff iv=22222222222222222222222222222222 enc=0 mode=aes_128_ctr"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
echo "data=112233445566778899aabbccddeeff00 key=11223344556677 enc=1 mode=des_ecb"> /sys/mcp/rtssl
5c5d76e8eba35a429e6d263b5c9adf4e
echo "data=5c5d76e8eba35a429e6d263b5c9adf4e key=11223344556677 enc=0 mode=des_ecb"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
echo "data=112233445566778899aabbccddeeff00 key=ffffffffffffff iv=22222222222222222222222222222222 enc=1 mode=des_cbc"> /sys/mcp/rtssl
03 d3 76 73 a2 79 50 d1 76 7a 78 3c 47 5b 6a 0a
echo "data=03d37673a27950d1767a783c475b6a0a key=ffffffffffffff iv=22222222222222222222222222222222 enc=0 mode=des_cbc"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
echo "data=112233445566778899aabbccddeeff00 key=112233445566771122334455667711223344556677 enc=1 mode=tdes_ecb"> /sys/mcp/rtssl
5c 5d 76 e8 eb a3 5a 42 9e 6d 26 3b 5c 9a df 4e
echo "data=5c5d76e8eba35a429e6d263b5c9adf4e key=112233445566771122334455667711223344556677 enc=0 mode=tdes_ecb"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
echo "data=112233445566778899aabbccddeeff00 key=112233445566771122334455667711223344556677 iv=22222222222222222222222222222222 enc=1 mode=tdes_cbc"> /sys/mcp/rtssl
16 c8 d8 60 06 ee 87 fa 30 cb 88 a3 c1 82 55 7b
echo "data=16c8d86006ee87fa30cb88a3c182557b key=112233445566771122334455667711223344556677 iv=22222222222222222222222222222222 enc=0 mode=tdes_cbc"> /sys/mcp/rtssl
11 22 33 44 55 66 77 88 99 aa bb cc dd ee ff 00
*/
static ssize_t mcp_rtssl_store(struct kobject *kobj, struct kobj_attribute *attr,
                               const char *buf, size_t count)
{
    unsigned int   ende = 0;
    unsigned char  data[MAX_LEN] = {0};
    unsigned char  mode[24] = {0};
    unsigned char  key[32] = {0};
    unsigned char  iv[16] = {0};
    unsigned char  out_data[MAX_LEN] = {0};

    parser_str((char *)buf, data, mode, &ende, key, iv);
    //printk(KERN_EMERG "Date=%x, Key=%x, Mode=%s, ENC=%d", data[0], key[0], mode, ende);

    if(strncmp(mode, "des_ecb", 7) == 0) {
        if(ende == 1) {
            MCP_DES_ECB_Encryption(key, data, out_data, 16);
        } else {
            MCP_DES_ECB_Decryption(key, data, out_data, 16);
        }
    } else if(strncmp(mode, "des_cbc", 7) == 0) {
        if(ende == 1) {
            MCP_DES_CBC_Encryption(key, iv, data, out_data, 16);
        } else {
            MCP_DES_CBC_Decryption(key, iv, data, out_data, 16);
        }
    } else if(strncmp(mode, "tdes_ecb", 8) == 0) {
        if(ende == 1) {
            MCP_TDES_ECB_Encryption(key, data, out_data, 16);
        } else {
            MCP_TDES_ECB_Decryption(key, data, out_data, 16);
        }
    } else if(strncmp(mode, "tdes_cbc", 8) == 0) {
        if(ende == 1) {
            MCP_TDES_CBC_Encryption(key, iv, data, out_data, 16);
        } else {
            MCP_TDES_CBC_Decryption(key, iv, data, out_data, 16);
        }
    } else if(strncmp(mode, "aes_128_ecb", 11) == 0) {
        if(ende == 1) {
            MCP_AES_ECB_Encryption(key, data, out_data, 16);
        } else {
            MCP_AES_ECB_Decryption(key, data, out_data, 16);
        }
    } else if(strncmp(mode, "aes_128_cbc", 11) == 0) {
        if(ende == 1) {
            MCP_AES_CBC_Encryption(key, iv, data, out_data, 16);
        } else {
            MCP_AES_CBC_Decryption(key, iv, data, out_data, 16);
        }
    } else if(strncmp(mode, "aes_128_ctr", 11) == 0) {
        if(ende == 1) {
            MCP_AES_CTR_Encryption(key, iv, data, out_data, 16);
        } else {
            MCP_AES_CTR_Decryption(key, iv, data, out_data, 16);
        }
    }

    memcpy(OutData, out_data, 16);
    mcp_dump_data_with_text(OutData, 16, "Encrypt : ");
    return count;
}

static ssize_t mcp_dump_desc_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    mcp_dump_all_desc(buf);
    return strlen(buf);
}

static ssize_t mcp_dump_desc_store(struct kobject *kobj, struct kobj_attribute *attr,
                                   const char *buf, size_t count)
{
    int val = 0;
    if (sscanf(buf, "%d", &val) == 1) {
        if(val == 1)
            DisplayDesc = 1;
        else
            DisplayDesc = 0;
    }
    return count;
}

static ssize_t mcp_dump_fifo_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "Previous BASE=%08lx, RP=%08lx, WP=%08lx, LIMIT=%08lx\n", pre_base, pre_rp, pre_wp, pre_limit);
}

static ssize_t mcp_dump_fifo_store(struct kobject *kobj, struct kobj_attribute *attr,
                                   const char *buf, size_t count)
{
    int val = 0;
    if (sscanf(buf, "%d", &val) == 1) {
        if(val == 1)
            DisplayFIFO = 1;
        else
            DisplayFIFO = 0;
    }
    return count;
}

static ssize_t mcp_dump_reg_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
    return sprintf(buf, "CTRL   = %08x\nSTATUS = %08x\nEN     = %08x\nCTRL1  = %08x\nSCTCH  = %08x\nCOUNT  = %08x\nCOMPARE= %08x\n",
                   GET_MCP_CTRL(), GET_MCP_STATUS(), GET_MCP_EN(), GET_MCP_CTRL1(), GET_MCP_SCTCH());
}

static struct kobj_attribute mcp_rtssl =
    __ATTR(rtssl, 0644, mcp_rtssl_show, mcp_rtssl_store);

static struct kobj_attribute mcp_dump_desc =
    __ATTR(dump_desc, 0644, mcp_dump_desc_show, mcp_dump_desc_store);

static struct kobj_attribute mcp_dump_fifo =
    __ATTR(dump_fifo, 0644, mcp_dump_fifo_show, mcp_dump_fifo_store);

static struct kobj_attribute mcp_dump_reg =
    __ATTR(dump_reg, 0644, mcp_dump_reg_show, NULL);

static struct attribute * mcp_attrs[] = {
    &mcp_rtssl.attr,
    &mcp_dump_desc.attr,
    &mcp_dump_fifo.attr,
    &mcp_dump_reg.attr,
    NULL,
};

static struct attribute_group mcp_attr_group = {
    .attrs = mcp_attrs,
};

static int mcp_setup_cdev(void)
{
    int ret = 0;
    struct device *dev_device = NULL;
    if (misc_register(&rtk_mcp_miscdev)) {
        mcp_err("register mcp dev file failed\n");
        ret = -ENODEV;
        return ret;
    }

    mcp_kobj = kobject_create_and_add("mcp", NULL);
    if (!mcp_kobj)
        return -ENOMEM;

    if (sysfs_create_group(mcp_kobj, &mcp_attr_group) != 0)
        return -1;

    dev_device = rtk_mcp_miscdev.this_device;
    dev_device->coherent_dma_mask = DMA_BIT_MASK(32);
    dev_device->dma_mask = &dev_device->coherent_dma_mask;

#ifdef CONFIG_ARM64
    arch_setup_dma_ops(dev_device, 0, 0, NULL, false);
#endif
    if(dma_set_mask(dev_device, DMA_BIT_MASK(32))) {
        printk(KERN_ERR "[MCP] DMA not supported\n");
    }
    dma_set_coherent_mask(dev_device, DMA_BIT_MASK(32));
    return 0;
}

static void mcp_unsetup_cdev(void)
{
    kobject_put(mcp_kobj);
    misc_deregister(&rtk_mcp_miscdev);
}


#ifdef CONFIG_PM

static struct platform_device*  mcp_platform_dev = NULL;

static int mcp_probe(struct device *dev)
{
    struct platform_device  *pdev = to_platform_device(dev);
    mcp_notice("mcp device detected ...\n");
    return strncmp(pdev->name, MCP_PLATDEVICE_NAME, sizeof(MCP_PLATDEVICE_NAME));
}


static int mcp_remove(struct device *dev)
{
    return 0;
}

static void mcp_shutdown(struct device *dev)
{
}

static int mcp_suspend_noirq (struct device *dev)
{
    int ret = 0;

    mcp_notice("suspend_noirq\n");
    ret = mcp_pm_off();
    if ( ret < 0 ) {
        mcp_err("mcp suspend_noirq fail\n");
    }
    mcp_notice("suspend_noirq finished\n");

    return 0;
}

static int mcp_resume_noirq(struct device *dev)
{
    int ret = 0;

    mcp_notice("resume_noirq\n");
    ret = mcp_pm_on();
    if ( ret < 0 ) {
        mcp_err("mcp resume_noirq fail\n");
    }

    mcp_notice("resume_noirq finished\n");
    return 0;
}

static int mcp_freeze_noirq(struct device *dev)
{
    int ret = 0;

    mcp_notice("freeze_noirq\n");
    ret = mcp_pm_off();
    if ( ret < 0 ) {
        mcp_err("mcp freeze_noirq fail\n");
    }

    mcp_notice("freeze_noirq finish\n");
    return 0;
}

static int mcp_thaw_noirq(struct device *dev)
{
    int ret = 0;

    mcp_notice("thaw_noirq\n");
    ret = mcp_pm_on();
    if ( ret < 0 ) {
        mcp_err("mcp thaw_noirq fail\n");
    }

    mcp_notice("thaw_noirq finish\n");
    return 0;
}

static int mcp_restore_noirq(struct device *dev)
{
    int ret = 0;

    mcp_notice("restore_noirq\n");
    ret = mcp_pm_on();
    if ( ret < 0 ) {
        mcp_err("mcp restore_noirq fail\n");
    }
    mcp_notice("restore_noirq finished\n");
    return 0;
}


static const struct dev_pm_ops mcp_pm_ops = {
    .freeze_noirq   = mcp_freeze_noirq,
    .thaw_noirq     = mcp_thaw_noirq,
    .suspend_noirq   = mcp_suspend_noirq,
    .resume_noirq    = mcp_resume_noirq,
    /*.poweroff_late   = mcp_poweroff,*/
    .restore_noirq   = mcp_restore_noirq,
};
#ifdef CONFIG_OF
static const struct of_device_id mcp_of_match[] = {
    { .compatible = "realtek,rtk-mcp" },
    { },
};
MODULE_DEVICE_TABLE(of, mcp_of_match);
#endif
static struct platform_driver mcp_platform_drv = {
    .driver = {
        .name           = MCP_PLATDEVICE_NAME,
        .bus            = &platform_bus_type,
        .probe          = mcp_probe,
        .remove         = mcp_remove,
        .shutdown       = mcp_shutdown,
#ifdef CONFIG_PM
        .pm             = &mcp_pm_ops,
#endif
#ifdef CONFIG_OF
        .of_match_table = of_match_ptr(mcp_of_match),
#endif
    }
};
static __init int mcp_platform_init(void)
{
    mcp_platform_dev = platform_device_register_simple(MCP_PLATDEVICE_NAME, 0, NULL, 0);
    if(!mcp_platform_dev) {
        goto FAIL_ADD_PLATFORM_DEVICE;
    }
    if(platform_driver_register(&mcp_platform_drv) == 0)
        return 0;
    platform_device_unregister(mcp_platform_dev);
    mcp_platform_dev = NULL;
FAIL_ADD_PLATFORM_DEVICE:
    return -1;
}

static __exit void mcp_platform_uninit(void)
{
    platform_driver_unregister(&mcp_platform_drv);
    platform_device_unregister(mcp_platform_dev);
}
#endif


static int __init mcp_module_init(void)
{
    int ret = 0;
    ret = mcp_setup_cdev();
    if(ret != 0)
        goto FAIL_CREATE_MCP_CDEV;
    ret = mcp_core_init(rtk_mcp_miscdev.this_device);
    if (ret != 0)
        goto FAIL_INIT_MCP_CORE;

#ifdef CONFIG_PM
    ret = mcp_platform_init();
    if (ret != 0)
        goto FAIL_INIT_PlATFORM_DRIVER;
#endif
    return 0;
#ifdef CONFIG_PM
FAIL_INIT_PlATFORM_DRIVER:
    mcp_core_uninit();
#endif
FAIL_INIT_MCP_CORE:
    mcp_unsetup_cdev();
FAIL_CREATE_MCP_CDEV:
    return ret;
}



static void __exit mcp_module_exit(void)
{
    mcp_core_uninit();
    mcp_unsetup_cdev();
#ifdef CONFIG_PM
    mcp_platform_uninit();
#endif

}


module_init(mcp_module_init);
module_exit(mcp_module_exit);

