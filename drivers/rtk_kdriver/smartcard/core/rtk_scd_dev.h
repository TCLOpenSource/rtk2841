#ifndef __RTK_SCD_DEV_H__
#define __RTK_SCD_DEV_H__

#include <linux/cdev.h>
#include "rtk_scd.h"

#define SCD_IFD_ENABLE          0x7300
#define SCD_RESET               0x7301
#define SCD_SETPARAM            0x7302
#define SCD_GETPARAM            0x7303
#define SCD_DEACTIVE            0x7306
#define SCD_ACTIVE              0x7307
#define SCD_GET_ATR             0x7309
#define SCD_READ                0x730a
#define SCD_WRITE               0x730b
#define SCD_DATA_EXCHANGE       0x730c
#define SCD_GET_CARD_STATUS     0x730d
#define SCD_POLL_CARD_STATUS_CHANGE 0x730e
#define SCD_ABORT_DATA_EXCHANGE 0x730f	/* this function will termainate all io requests*/

#define SCD_SETPARAM_EX         0x7310
#define SCD_GETPARAM_EX         0x7311
#define SCD_GETINTERFACE_VAL       0x7312

#define SCD_KER_PRINT           0x7312

#ifdef CONFIG_COMPAT

#define COMPAT_SCD_SETPARAM			0x7302
#define COMPAT_SCD_GETPARAM			0x7303
#define COMPAT_SCD_SETPARAM_EX         0x7310
#define COMPAT_SCD_GETPARAM_EX         0x7311
#define COMPAT_SCD_ACTIVE              0x7307
#define COMPAT_SCD_DEACTIVE            0x7306
#define COMPAT_SCD_RESET               0x7301
#define COMPAT_SCD_GET_CARD_STATUS     0x730d
#define COMPAT_SCD_POLL_CARD_STATUS_CHANGE 0x730e
#define COMPAT_SCD_GET_ATR             0x7309
#define COMPAT_SCD_READ                0x730a
#define COMPAT_SCD_WRITE               0x730b
#define COMPAT_SCD_DATA_EXCHANGE       0x730c
#define COMPAT_SCD_ABORT_DATA_EXCHANGE 0x730f	/* this function will termainate all io requests*/

#endif

typedef struct {
	unsigned long clk;
	unsigned long etu;
} scd_ifd_param;

typedef struct {
	unsigned char *p_data;
	unsigned int length;
} sc_msg_buff;

typedef struct {
	unsigned int flags;	/* reserved for feature*/
	unsigned char *tx_data;
	unsigned int tx_len;
	unsigned char *rx_buff;
	unsigned int rx_len;
	unsigned int timeout;	/*wait time (in ms)*/
} sc_transcation;

typedef struct {
	struct cdev cdev;
	struct device *device;
} scd_dev;

#ifdef CONFIG_COMPAT

typedef struct {
	unsigned int clk;
	unsigned int etu;
} compat_scd_ifd_param;

typedef struct {
	unsigned int p_data;
	unsigned int length;
} compat_sc_msg_buff;

typedef struct {
	unsigned int flags;	/* reserved for feature*/
	unsigned int tx_data;
	unsigned int tx_len;
	unsigned int rx_buff;
	unsigned int rx_len;
	unsigned int timeout;	/*wait time (in ms)*/
} compat_sc_transcation;

#endif

extern int create_scd_dev_node(scd_device *dev);
extern void remove_scd_dev_node(scd_device *dev);

extern int scd_dev_module_init(void);
extern void scd_dev_module_exit(void);

#endif /*__SCD_DEV_H__*/
