#ifndef __I2C_RTK_H__
#define __I2C_RTK_H__

#ifdef CONFIG_RTK_KDRIVER_SUPPORT
#include <rtk_kdriver/rtk_gpio.h>
#else
#include <mach/rtk_gpio.h>
#endif

#include <mach/rtk_log.h>

#ifdef CONFIG_I2C_DEBUG_BUS
#define i2c_debug(fmt, args...)		rtd_printk(KERN_DEBUG, "I2C" ,"[Debug]" fmt, ## args)
#else
#define i2c_debug(fmt, args...)
#endif

#define I2C_INFO(fmt, args...)		rtd_printk(KERN_INFO   ,  "I2C" , "[Info]" fmt, ## args)
#define I2C_WARNING(fmt, args...)	rtd_printk(KERN_WARNING,  "I2C" , "[Warn]" fmt, ## args)


#define rtk_MASTER_7BIT_ADDR    0x24
#define MAX_I2C_ADAPTER         8

#define IsReadMsg(x)        (x.flags & I2C_M_RD)
#define IsGPIORW(x)         (x.flags & I2C_GPIO_RW)
#define IsSameTarget(x,y)   ((x.addr == y.addr) && !((x.flags ^ y.flags) & (~I2C_M_RD)))

LIST_HEAD(rtk_i2c_list);
extern char *parse_token(const char *parsed_string, const char *token);


typedef struct
{
    struct i2c_adapter adap;
    i2c_rtk_algo algo;
    struct list_head list;
    rtk_i2c * p_phy;
    int port;
    int spd;

#ifdef CONFIG_PM
    struct platform_device *p_dev;

#endif
} rtk_i2c_adapter;

typedef struct
{
    unsigned char mode;

#define I2C_MODE    0
#define G2C_MODE    1
    union
    {
        struct
        {
            unsigned char phy_id;
            char port_id;
        } i2c;
        struct
        {
            RTK_GPIO_ID scl;
            RTK_GPIO_ID sda;
        } g2c;
    };
} rtk_i2c_adapter_config;

#define SET_I2C_CFG(phy_id, port_id)          ((0x80000000) |((phy_id)<<8) | (port_id))
#define SET_G2C_CFG(sda, scl)                 ((0xC0000000) | ((sda)<<8) | (scl))
#define IS_I2C_CFG(cfg)                       ((cfg & 0xFFFF0000)==0x80000000)
#define IS_G2C_CFG(cfg)                       ((cfg & 0xFFFF0000)==0xC0000000)
#define IS_VALID_CFG(cfg)                     (IS_G2C_MODE(cfg)||IS_I2C_MODE(cfg))
#define GET_I2C_PHY(cfg)                      ((cfg>>8) & 0xFF)
#define GET_I2C_PORT(cfg)                     (cfg & 0xFF)
#define GET_G2C_SDA(cfg)                      ((cfg>>8) & 0xFF)
#define GET_G2C_SCL(cfg)                      (cfg & 0xFF)

#endif
