#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/module.h>
#include <linux/device.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_dgst.h"
#include "mcp/rtk_mcp_buff.h"
#include "mcp/rtk_rsa.h"
#include "mcp/rtk_mcp_dbg.h"

#define MCP_DEV_FILE_NAME      	"mcp_rsa"

static struct cdev mcp_cdev;
static dev_t devno;
static struct device* mcp_rsa = NULL;

/* IOCTL Command Definitions */
#define MCP_RSA_IOCTL_CMD(x)         (0x10 + x)
#define MCP_RSA_IOCTL_VERIFY          MCP_RSA_IOCTL_CMD(0)



/***************************************************************************
    ------------------- Dgest Device File Operations  --------------------
****************************************************************************/

typedef struct {
    BI* signature;
    BI* pub_exp;
    BI* mod;
    BI* dgst;
}RSA_VERIFY;


#define DEF_RSA_MOD        "FFFFFFFFFFFFFFFF"
#define DEF_RSA_MOD_FMT    HEX


int rsa_dev_do_rsa_verify(
	RSA_VERIFY* 			rsa
	)
{
    BI* signature = NULL;
    BI* pub_exp = NULL;
    BI* mod  = NULL;
    BI* dgst = init_BI();
    int ret  = -EFAULT;

    if (!rsa)
    {
        mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, invalid argument\n");
        goto end_proc;
    }

    if (rsa->dgst==NULL)
    {
        mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, dgst should not be zero\n");
        ret = -EFAULT;
        goto end_proc;
    }

    if (rsa->signature)
    {
        signature = init_BI();

        if (copy_from_user(signature, (RSA_VERIFY __user *) rsa->signature, sizeof(BI)))
        {
            mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, copy signature failed\n");
            goto end_proc;
        }
    }
    else
    {
        mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, signature should not be null\n");
        goto end_proc;
    }

    if (rsa->pub_exp)
    {
        pub_exp = init_BI();

        if (copy_from_user(pub_exp, (BI __user *) rsa->pub_exp, sizeof(BI)))
        {
            mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, copy signature failed\n");
            goto end_proc;
        }
    }
    else
    {
        pub_exp = move_p(65537);            // default public exp
    }

    if (rsa->mod)
    {
        mod = init_BI();

        if (copy_from_user(mod, (BI __user *) rsa->mod, sizeof(BI)))
        {
            mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, copy signature failed\n");
            goto end_proc;
        }
    }
    else
    {
        mod = InPutFromStr(DEF_RSA_MOD, DEF_RSA_MOD_FMT);
    }

    ret = rsa_verify(signature, pub_exp, mod, dgst);

    if (copy_to_user((BI __user *) rsa->dgst, dgst, sizeof(BI)))
    {
        mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, copy dgst to user failed\n");
        ret = -EFAULT;
    }

end_proc:

    if (signature)  	free_BI(signature);
    if (pub_exp)    	free_BI(pub_exp);
    if (mod)        	free_BI(mod);
    if (dgst)      	free_BI(dgst);

    return ret;
}



/***************************************************************************
     ------------------- Device File Operations  --------------------
****************************************************************************/

/*------------------------------------------------------------------
 * Func : rsa_dev_open
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int rsa_dev_open(
	struct inode*		inode,
	struct file*		file
	)
{
    return 0;
}



/*------------------------------------------------------------------
 * Func : rsa_dev_release
 *
 * Desc : release function of mcp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int rsa_dev_release(
    struct inode* 	inode,
    struct file*		file
    )
{
	return 0;
}



/*------------------------------------------------------------------
 * Func : rsa_dev_ioctl
 *
 * Desc : ioctl function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long rsa_dev_ioctl(
    struct file*    	file,
    unsigned int 		cmd,
    unsigned long 		arg
    )
{
    RSA_VERIFY    rsa_v;

	switch (cmd)
    {
    	case MCP_RSA_IOCTL_VERIFY:
        {
        	if (copy_from_user((void *) &rsa_v, (void __user *)arg, sizeof(RSA_VERIFY)))
        	{
            	        mcp_warning("[MCP][RSA] WARNING, do rsa verify failed, copy data from user failed\n");
				return -EFAULT;
        	}

        	return rsa_dev_do_rsa_verify(&rsa_v);
    	}
		default:
	    	        mcp_warning("[MCP][RSA] WARNING, unknown command\n");
			return -EFAULT;
	}
}



static struct file_operations mcp_ops =
{
	.owner				= THIS_MODULE,
	.unlocked_ioctl	= rsa_dev_ioctl,
	.open				= rsa_dev_open,
	.release			= rsa_dev_release,
};




/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/

static int __init rsa_dev_init(void)
{
    cdev_init(&mcp_cdev, &mcp_ops);

    if (alloc_chrdev_region(&devno, 0, 1, MCP_DEV_FILE_NAME)!=0)
    {
        cdev_del(&mcp_cdev);
        return -EFAULT;
    }

    if (cdev_add(&mcp_cdev, devno, 1)<0)
        return -EFAULT;

    mcp_rsa = device_create(
                 mcp_dev_class,      // class
                 NULL,               // parent
		         devno,              // dev number
		         NULL,               // driver data
		         MCP_DEV_FILE_NAME);      // device name

    return 0;
}


static void __exit rsa_dev_exit(void)
{
    cdev_del(&mcp_cdev);
    device_destroy(mcp_dev_class, mcp_rsa->devt);       // remove device
    unregister_chrdev_region(devno, 1);
}



module_init(rsa_dev_init);
module_exit(rsa_dev_exit);
