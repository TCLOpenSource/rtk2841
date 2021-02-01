#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/miscdevice.h>
#include <linux/dma-mapping.h>
#include <rtk_kdriver/rtk_mcp.h>
#include "mcp/rtk_mcp_cipher.h"
#include "mcp/rtk_mcp_buff.h"
#include "mcp/rtk_mcp_aux.h"
#include "mcp/rtk_mcp_dbg.h"

#define MCP_CIPHER_FILE_NAME       "mcp_cipher"
static struct cdev mcp_cdev;
static dev_t devno;
static struct device* mcp_cipher = NULL;

/* IOCTL Command Definitions */
#define MCP_CIPHER_IOCTL_CMD(x)         (0x12839000 + x)
#define MCP_CIPHER_IOCTL_INIT           	MCP_CIPHER_IOCTL_CMD(0)
#define MCP_CIPHER_IOCTL_UPDATE         	MCP_CIPHER_IOCTL_CMD(1)
#define MCP_CIPHER_IOCTL_FINAL          	MCP_CIPHER_IOCTL_CMD(2)
#define MCP_CIPHER_IOCTL_PEEK_IV        	MCP_CIPHER_IOCTL_CMD(3)
#define MCP_CIPHER_IOCTL_ALLOC_BUF        	MCP_CIPHER_IOCTL_CMD(4)
#define MCP_CIPHER_IOCTL_FREE_BUF        	MCP_CIPHER_IOCTL_CMD(5)

typedef struct{
    unsigned char   type;
    unsigned char   enc;
    unsigned char   key_len;
    unsigned char*  key;
    unsigned char   iv_len;
    unsigned char*  iv;
}MCP_CIPHER_PARAM;


typedef struct{
    unsigned char*  in;
    unsigned long   len;
    unsigned char*  out;
}MCP_CIPHER_DATA;


#define MCP_CIPHER_DES_ECB                  0x00
#define MCP_CIPHER_DES_CBC                  0x01
#define MCP_CIPHER_TDES_ECB                 0x10
#define MCP_CIPHER_TDES_CBC             	0x11
#define MCP_CIPHER_AES_128_ECB          	0x20
#define MCP_CIPHER_AES_128_CBC          	0x21
#define MCP_CIPHER_AES_128_CTR          	0x22
#ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA
#define MCP_CIPHER_CAM_128_ECB              0x50
#define MCP_CIPHER_CAM_128_CBC              0x51
#define MCP_CIPHER_CAM_128_CTR              0x52
#endif

/* mutex define */
static DEFINE_MUTEX(cp_buf_mutex);
#define _cp_buf_lock()          mutex_lock(&cp_buf_mutex)
#define _cp_buf_unlock()        mutex_unlock(&cp_buf_mutex)

#define MCP_PLI_BUFF_SIZE    1024*64
unsigned char* g_pli_buff = NULL; // for the buff not allocate by pli

/*------------------------------------------------------------------
 * Func : mcp_cipher_do_init
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_do_init(
    MCP_CIPHER_CTX*     	ctx,
    MCP_CIPHER_PARAM*     	param
    )
{
    MCP_CIPHER* cipher = NULL;
    unsigned char buff[MAX_CIPHER_KEY_SIZE + MAX_CIPHER_IV_SIZE];
    unsigned char *key, *iv;
    switch (param->type)
    {
    	case MCP_CIPHER_AES_128_ECB:
			cipher = MCP_aes_128_ecb();
			break;
    	case MCP_CIPHER_AES_128_CBC:
			cipher = MCP_aes_128_cbc();
			break;
    	case MCP_CIPHER_AES_128_CTR:
			cipher = MCP_aes_128_ctr();
			break;
#ifdef CONFIG_RTK_KDRV_MCP_CAMELLIA
        case MCP_CIPHER_CAM_128_ECB:
            cipher = MCP_cam_128_ecb();
            break;
        case MCP_CIPHER_CAM_128_CBC:
            cipher = MCP_cam_128_cbc();
            break;
        case MCP_CIPHER_CAM_128_CTR:
            cipher = MCP_cam_128_ctr();
            break;
#endif
    	case MCP_CIPHER_DES_ECB:
			cipher = MCP_des_ecb();
			break;
    	case MCP_CIPHER_DES_CBC:
			cipher = MCP_des_cbc();
			break;
    	case MCP_CIPHER_TDES_ECB:
			cipher = MCP_tdes_ecb();
			break;
    	case MCP_CIPHER_TDES_CBC:
			cipher = MCP_tdes_cbc();
			break;
    	default:
        	mcp_err("[MCP][CIPHER]do cipher init failed, unknow cipher\n");
        	return -EFAULT;
    }

    memset(buff, 0, sizeof(buff));

    if ((unsigned long)param->key > MCP_MAX_CW_ENTRY && param->key_len)
    {
        if (param->key_len > MAX_CIPHER_KEY_SIZE)
            param->key_len = MAX_CIPHER_KEY_SIZE;

#ifdef CONFIG_COMPAT
        if (copy_from_user((void *) buff, compat_ptr(param->key), param->key_len))
#else
        if (copy_from_user((void *) buff, (unsigned char*)param->key, param->key_len))
#endif
        {
            mcp_err("[MCP][CIPHER] do cipher init failed, copy key from user space failed\n");
            return -EFAULT;
        }
        key = buff;
    }
    else if(!param->key)
    {
        key = NULL;
    }
	else
	{
#ifdef CONFIG_COMPAT
		key = compat_ptr(param->key);
#else
		key = (unsigned char*)param->key;
#endif
//		printk("[MCP] key = %d, len = %d\n",(unsigned long)param->key, param->key_len);
	}

    if (param->iv && param->iv_len)
    {
        if (param->iv_len > MAX_CIPHER_IV_SIZE)
            param->iv_len = MAX_CIPHER_IV_SIZE;

#ifdef CONFIG_COMPAT
        if (copy_from_user((void *) &buff[MAX_CIPHER_KEY_SIZE], compat_ptr(param->iv), param->iv_len))
#else
        if (copy_from_user((void *) &buff[MAX_CIPHER_KEY_SIZE], (unsigned char*)param->iv, param->iv_len))
#endif
        {
            mcp_err("[MCP][CIPHER] do cipher init failed, copy iv from user space failed\n");
            return -EFAULT;
        }

        iv = &buff[MAX_CIPHER_KEY_SIZE];
    }
    else
    {
        iv = NULL;
    }

    return MCP_CipherInit(ctx, cipher, key, iv, param->enc);
}



/*------------------------------------------------------------------
 * Func : mcp_cipher_do_update
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_do_update(
    MCP_CIPHER_CTX*    		ctx,
    unsigned int          	in,
    unsigned long           len,
    unsigned int          	out
    )
{
    int outlen;
    int flg_use_g_pli_buff = 0; // flag to record whether use global pli buff
    unsigned char* buff = NULL;

    if (mcp_is_pli_address(in) && mcp_is_pli_address(out)) {
        return MCP_CipherUpdate(ctx, (unsigned char*)pli_to_kernel(in), len, (unsigned char*)pli_to_kernel(out));
    }

    if ( g_pli_buff == NULL || len > MCP_PLI_BUFF_SIZE ) // if pli buff allocate fail in module init
    {
        if ((buff = mcp_malloc(len))==NULL)
        {
                goto err_alloc_kernel_buffer_failed;
        }
    }
    else
    {
        buff =  g_pli_buff;
        flg_use_g_pli_buff = 1;
    }

    if ( flg_use_g_pli_buff )
    {
        // lock when use g_pli_buff
        _cp_buf_lock();
    }
	
    if (mcp_is_pli_address(in))               // input buffer is allocated by pli
    {
        if ((outlen = MCP_CipherUpdate(ctx, (unsigned char*)pli_to_kernel(in), len, buff))<0)
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, update failed\n");
            goto err_update_cipher_failed;
        }

#ifdef CONFIG_COMPAT
        if (copy_to_user(compat_ptr(out), buff, outlen))
#else
        if (copy_to_user((void __user *) out, buff, outlen))
#endif
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, copy data to user buffer failed\n");
            goto err_copy_to_user_failed;
        }
    }
    else if (mcp_is_pli_address(out))         // output buffer is allocated by pli
    {
#ifdef CONFIG_COMPAT
        if (copy_from_user((void *) buff, compat_ptr(in), len))
#else
        if (copy_from_user((void *) buff, (void __user *)in, len))
#endif
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, copy data from user space failed\n");
            goto err_copy_from_user_failed;
        }

        if ((outlen = MCP_CipherUpdate(ctx, buff, len, (unsigned char*)pli_to_kernel(out)))<0)
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, update failed\n");
            goto err_update_cipher_failed;
        }
    }
    else                                // none of them are allocated by pli
    {
#ifdef CONFIG_COMPAT
        if (copy_from_user((void *) buff, compat_ptr(in), len))
#else
        if (copy_from_user((void *) buff, (void __user *)in, len))
#endif
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, copy data from user space failed\n");
            outlen = -EFAULT;
            goto err_copy_from_user_failed;
        }

        if ((outlen = MCP_CipherUpdate(ctx, buff, len, buff))<0)
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, update failed\n");
            goto err_update_cipher_failed;
        }

#ifdef CONFIG_COMPAT
        if (copy_to_user(compat_ptr(out), buff, outlen))
#else
        if (copy_to_user((void __user *) out, buff, outlen))
#endif
        {
            mcp_err("[MCP][CIPHER] do cipher update failed, copy data to user buffer failed\n");
            goto err_copy_to_user_failed;
        }
    }

    if ( flg_use_g_pli_buff == 1 )
    {
        // un-lock when use g_pli_buff
        _cp_buf_unlock();
        flg_use_g_pli_buff = 0;
    } else {
        mcp_free(buff, len);
    }

    return outlen;

//----------------------------------
err_copy_from_user_failed:
err_copy_to_user_failed:
err_update_cipher_failed:
    if ( flg_use_g_pli_buff == 1 )
    {
        // un-lock when use g_pli_buff
        _cp_buf_unlock();
        flg_use_g_pli_buff = 0;
    } else {
        mcp_free(buff, len);
    }
err_alloc_kernel_buffer_failed:
    return -EFAULT;
}



/*------------------------------------------------------------------
 * Func : mcp_cipher_do_final
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_do_final(
    MCP_CIPHER_CTX*     	ctx,
    unsigned int          	out
    )
{
    int ret;
    unsigned char buff[MAX_CIPHER_BLOCK_SIZE];

    if (mcp_is_pli_address(out))
    {
        //return MCP_CipherFinal(ctx, (unsigned char*)pli_to_kernel(out));
		return MCP_CipherFinal(ctx, (unsigned char*) pli_to_kernel(out));
    }
    else
    {
        if ((ret = MCP_CipherFinal(ctx, buff))> 0)
        {
#ifdef CONFIG_COMPAT
            if (copy_to_user(compat_ptr(out), buff, ret))
#else
            if (copy_to_user((void __user *) out, buff, ret))
#endif
                return -EFAULT;
        }

        return ret;
    }
}



/*------------------------------------------------------------------
 * Func : mcp_cipher_do_peek_iv
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_do_peek_iv(
    MCP_CIPHER_CTX*    		ctx,
    unsigned int          	out
    )
{
    int ret;
    unsigned char buff[MAX_CIPHER_IV_SIZE];

    if (mcp_is_pli_address(out))
    {
        //return MCP_CipherPeekIV(ctx, (unsigned char*)pli_to_kernel(out));
		return MCP_CipherPeekIV(ctx, (unsigned char*) pli_to_kernel(out));
    }
    else
    {
        if ((ret = MCP_CipherPeekIV(ctx, buff))> 0)
        {
#ifdef CONFIG_COMPAT
            if (copy_to_user(compat_ptr(out), buff, ret))
#else
            if (copy_to_user((void __user *) out, buff, ret))
#endif
                return -EFAULT;
        }

        return ret;
    }
}

/*------------------------------------------------------------------
 * Func : mcp_cipher_do_alloc_buf
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
unsigned int mcp_cipher_do_alloc_buf(
    unsigned int          	len
    )
{
	unsigned long addr;

	addr = __get_free_pages(GFP_KERNEL | __GFP_ZERO, get_order(len));
	/* mcp_debug("[MCP] virt_addr = %08x, phy_addr = %08x, len = %d\n", addr, virt_to_phys((void*)addr), len); */
	if (!addr)
		return -ENOMEM;

	SetPageReserved(virt_to_page(addr));

	return (unsigned int)virt_to_phys((void*)addr);
}


/*------------------------------------------------------------------
 * Func : mcp_cipher_do_free_buf
 *
 * Desc : open function of md dev
 *
 * Parm : addr 	: physical address
 *        len  	: buffer size
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_do_free_buf(
    unsigned int          	addr,
    unsigned int          	len
    )
{
	unsigned long virt_addr = (unsigned long)phys_to_virt((unsigned long)addr);

	/* mcp_debug("[MCP] virt_addr = %08x, len = %d\n", virt_addr, len); */

	ClearPageReserved(virt_to_page(virt_addr));
	free_pages(virt_addr, get_order(len));

	return 0;
}

/***************************************************************************
     ------------------- VM Operations  --------------------
****************************************************************************/

/*------------------------------------------------------------------
 * Func : mcp_cipher_vma_open
 *
 * Desc : open function of md dev
 *
 * Parm : vma 	: virtual memory area
 *
 *------------------------------------------------------------------*/
static
void mcp_cipher_vma_open(
	struct vm_area_struct*		vma
	)
{
}



/*------------------------------------------------------------------
 * Func : mcp_cipher_vma_close
 *
 * Desc : open function of md dev
 *
 * Parm : vma 	: virtual memory area
 *
 *------------------------------------------------------------------*/
static
void mcp_cipher_vma_close(
	struct vm_area_struct*		vma
	)
{
}

struct vm_operations_struct mcp_cipher_remap_vm_ops = {
	.open =     mcp_cipher_vma_open,
	.close =    mcp_cipher_vma_close,
//	.nopage =   mcp_cipher_vma_nopage,
};

/***************************************************************************
     ------------------- Device File Operations  --------------------
****************************************************************************/

/*------------------------------------------------------------------
 * Func : mcp_cipher_open
 *
 * Desc : open function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_open(
	struct inode*			inode,
	struct file*			file
	)
{
    file->private_data = kmalloc(sizeof(MCP_CIPHER_CTX),GFP_KERNEL);

    if (file->private_data==NULL)
        return -EFAULT;

    MCP_CIPHER_CTX_init((MCP_CIPHER_CTX*) file->private_data);

    return 0;
}



/*------------------------------------------------------------------
 * Func : mcp_cipher_release
 *
 * Desc : release function of mcp dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_release(
    struct inode*        	inode,
    struct file*          file
    )
{
    MCP_CIPHER_CTX* ctx = (MCP_CIPHER_CTX*) file->private_data;

    if (ctx)
    {
        MCP_CIPHER_CTX_cleanup(ctx);
        kfree(ctx);
    }

	return 0;
}



/*------------------------------------------------------------------
 * Func : mcp_cipher_ioctl
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
long mcp_cipher_ioctl(
    struct file*       	file,
    unsigned int        	cmd,
    unsigned long        	arg
    )
{
    MCP_CIPHER_CTX*   ctx = (MCP_CIPHER_CTX*) file->private_data;
    MCP_CIPHER_PARAM  param;
    MCP_CIPHER_DATA   data;

    switch (cmd)
    {
    	case MCP_CIPHER_IOCTL_INIT:
        {
        	if (copy_from_user(&param, (void __user *)arg, sizeof(MCP_CIPHER_PARAM)))
        	{
            	mcp_warning("[MCP][CIPHER] WARNING, do cipher init failed, copy cipher data from user failed\n");
				return -EFAULT;
        	}

        	return mcp_cipher_do_init(ctx, &param);
    	}
    	case MCP_CIPHER_IOCTL_UPDATE:
      	{
        	if (copy_from_user(&data, (void __user *)arg, sizeof(MCP_CIPHER_DATA)))
        	{
            	mcp_warning("[MCP][CIPHER] WARNING, do cipher update failed, copy cipher data from user failed\n");
				return -EFAULT;
        	}

        	return mcp_cipher_do_update(ctx, (unsigned int) data.in, data.len, (unsigned int) data.out);
    	}
    	case MCP_CIPHER_IOCTL_FINAL:
     	{
        	return mcp_cipher_do_final(ctx, (unsigned int)arg);
    	}
    	case MCP_CIPHER_IOCTL_PEEK_IV:
       	{
        	return mcp_cipher_do_peek_iv(ctx, (unsigned int)arg);
    	}
    	case MCP_CIPHER_IOCTL_ALLOC_BUF:
       	{
        	return mcp_cipher_do_alloc_buf((unsigned int)arg);
    	}
    	case MCP_CIPHER_IOCTL_FREE_BUF:
       	{
        	if (copy_from_user(&data, (void __user *)arg, sizeof(MCP_CIPHER_DATA)))
        	{
			mcp_warning("[MCP][CIPHER] WARNING, free buffer failed, copy buffer info from user failed\n");
			return -EFAULT;
        	}
        	return mcp_cipher_do_free_buf((unsigned int) data.in, data.len);
    	}
	default:
		mcp_warning("[MCP] WARNING, unknown command\n");
		return -EFAULT;
    }
}


#ifdef CONFIG_COMPAT
/*------------------------------------------------------------------
 * Func : mcp_cipher_compat_ioctl
 *
 * Desc : compat ioctl function of md dev
 *
 * Parm : inode : inode of dev
 *        file  : context of file
 *        cmd   : control command
 *        arg   : arguments
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
long mcp_cipher_compat_ioctl(
    struct file*       	file,
    unsigned int        	cmd,
    unsigned long        	arg
    )
{
    MCP_CIPHER_CTX*   ctx = (MCP_CIPHER_CTX*) file->private_data;
    MCP_CIPHER_PARAM  param;
    MCP_CIPHER_DATA   data;

    switch (cmd)
    {
    	case MCP_CIPHER_IOCTL_INIT:
        {
        	if (copy_from_user(&param, compat_ptr(arg), sizeof(MCP_CIPHER_PARAM)))
        	{
            	mcp_warning("[MCP][CIPHER] WARNING, do cipher init failed, copy cipher data from user failed\n");
				return -EFAULT;
        	}

        	return mcp_cipher_do_init(ctx, &param);
    	}
    	case MCP_CIPHER_IOCTL_UPDATE:
      	{
        	if (copy_from_user(&data, compat_ptr(arg), sizeof(MCP_CIPHER_DATA)))
        	{
            	mcp_warning("[MCP][CIPHER] WARNING, do cipher update failed, copy cipher data from user failed\n");
				return -EFAULT;
        	}

        	return mcp_cipher_do_update(ctx, data.in, data.len, data.out);
    	}
    	case MCP_CIPHER_IOCTL_FINAL:
     	{
        	return mcp_cipher_do_final(ctx, (unsigned int)arg);
    	}
    	case MCP_CIPHER_IOCTL_PEEK_IV:
       	{
        	return mcp_cipher_do_peek_iv(ctx, (unsigned int)arg);
    	}
    	case MCP_CIPHER_IOCTL_ALLOC_BUF:
       	{
        	return mcp_cipher_do_alloc_buf((unsigned int)arg);
    	}
    	case MCP_CIPHER_IOCTL_FREE_BUF:
       	{
        	if (copy_from_user(&data, compat_ptr(arg), sizeof(MCP_CIPHER_DATA)))
        	{
			mcp_warning("[MCP][CIPHER] WARNING, free buffer failed, copy buffer info from user failed\n");
			return -EFAULT;
        	}
        	return mcp_cipher_do_free_buf(data.in, data.len);
    	}
	default:
		mcp_warning("[MCP] WARNING, unknown command\n");
		return -EFAULT;
    }
}
#endif

/*------------------------------------------------------------------
 * Func : mcp_cipher_mmap
 *
 * Desc : open function of md dev
 *
 * Parm : file  : context of file
 *        vma   : virtual memory area
 *
 * Retn : 0 : success, others fail
 *------------------------------------------------------------------*/
static
int mcp_cipher_mmap(
	struct file*			file,
	struct vm_area_struct*		vma
	)
{
	if (remap_pfn_range(vma, vma->vm_start, vma->vm_pgoff,
                             vma->vm_end - vma->vm_start,
                             vma->vm_page_prot))
		return -EAGAIN;

	vma->vm_ops = &mcp_cipher_remap_vm_ops;
	mcp_cipher_vma_open(vma);
	return 0;
}


static struct file_operations mcp_ops =
{
	.owner				= THIS_MODULE,
	.unlocked_ioctl			= mcp_cipher_ioctl,
#ifdef CONFIG_COMPAT
	.compat_ioctl			= mcp_cipher_compat_ioctl,
#endif
	.open				= mcp_cipher_open,
	.release			= mcp_cipher_release,
	.mmap				= mcp_cipher_mmap,
};

static struct miscdevice rtk_mcp_cipher_miscdev = {
        MISC_DYNAMIC_MINOR,
        MCP_CIPHER_FILE_NAME,
        &mcp_ops,
};


/***************************************************************************
     ------------------- module init / exit stubs ----------------
****************************************************************************/

static int __init mcp_cipher_init(void)
{
        if (misc_register(&rtk_mcp_cipher_miscdev))
                return -ENODEV;

        /* allocate buff for the data not alloc by pli */
        // eva TODO tune the len of this buff
        if ((g_pli_buff = mcp_malloc(MCP_PLI_BUFF_SIZE)) == NULL) {
                mcp_err("[MCP] allocate pli buff for non-pli data fail\n");
        } else {
                mcp_debug("[MCP] allocate pli buff for non-pli data %d BYTE \n", MCP_PLI_BUFF_SIZE);
        }
        return 0;
}


static void __exit mcp_cipher_exit(void)
{
        misc_deregister(&rtk_mcp_cipher_miscdev);
        if ( g_pli_buff != NULL ) {
                mcp_free(g_pli_buff, MCP_PLI_BUFF_SIZE);
        }
}


module_init(mcp_cipher_init);
module_exit(mcp_cipher_exit);
